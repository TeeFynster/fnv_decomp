// NiNode.h and NiTexturingProperty.h currently declare incompatible NiTArray
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiSourceCubeMap.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/NiSourceTexture.h"
#include "../../../../include/NiStream.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}

inline void NiSourceTexture::IncRefCount()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}

inline void NiSourceTexture::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}

inline unsigned int NiStream::version()
{
    return *(unsigned int*)((char*)this + 0xd8);
}

inline NiBinaryStream* CubeMapBinaryStream(NiStream& stream)
{
    return *(NiBinaryStream**)((char*)&stream + 0x24c);
}

inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
                                               unsigned int* sizes, unsigned int count)
{
    unsigned int result = (*(ReadFunction*)((char*)this + 8))(this, buffer, bytes, sizes, count);
    *(unsigned int*)((char*)this + 4) += result;
    return result;
}

// NiRenderer.h does not yet declare the cube-map renderer-data virtual (slot 81).
inline bool CreateCubeRendererData(NiRenderer* renderer, void* cube)
{
    typedef bool (__thiscall* CreateCubeFn)(NiRenderer*, void*);
    return ((CreateCubeFn*)*(void**)renderer)[81](renderer, cube);
}


// src/gamebryo2.2/corelibs/nimain/nisourcecubemap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nisourcecubemap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
    char __stdcall AttachToListener(NiStream* kStream);
}

// @fnv 0x00a60850
// src: XBOX_PDB 0x00a60850
bool __stdcall NiSourceCubeMap_RegisterStreamables(NiStream& kStream)
{
    return AttachToListener(&kStream);
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4454;

// @fnv 0x00a60cb0
// src: COMMUNITY 0x00a60cb0
GlobalObjectO2_00a7b610* __cdecl NiSourceCubeMap_GetRTTI()
{
    return &g_011f4454;
}

// @fnv 0x00a60f30
NiSourceCubeMap* __cdecl CreateNiSourceCubeMap()
{
    void* p = BSFadeNode::operator new(0x4c);
    if (p)
    {
        NiSourceCubeMap* n = static_cast<NiSourceCubeMap*>(p);
        n->NiSourceTexture::NiSourceTexture();
        *(unsigned int*)(n) = 0x0109babc;
        n->m_uiFace = 0;
        return n;
    }
    return 0;
}

// Calls FUN_00a5fae0 on pkObject, then compares four fields of this and pkObject and returns true only if all match.
// @fnv 0x00a60880
// src: GAMEBRYO_LIB 0x00a60880
bool __thiscall NiSourceCubeMap::IsEqual_00a60880(NiObject* pkObject)
{
    if (NiSourceTexture_IsEqual(pkObject))
    {
        NiSourceCubeMap* pkTexture = reinterpret_cast<NiSourceCubeMap*>(pkObject);
        if (m_kFormatPrefs.m_ePreferredPixelLayout == pkTexture->m_kFormatPrefs.m_ePreferredPixelLayout &&
            m_kFormatPrefs.m_eMipFlag == pkTexture->m_kFormatPrefs.m_eMipFlag &&
            m_kFormatPrefs.m_eAlphaFormat == pkTexture->m_kFormatPrefs.m_eAlphaFormat &&
            m_bStatic == pkTexture->m_bStatic)
            return true;
    }
    return false;
}

struct DelObj
{
    virtual ~DelObj();
};

// @fnv 0x00a60800
bool __thiscall NiSourceCubeMap::CreateCubeOrRelease()
{
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    if (pkRenderer)
    {
        if (!CreateCubeRendererData(pkRenderer, this))
        {
            DelObj* p1 = (DelObj*)m_pFile;
            if (p1)
            {
                delete p1;
                m_pFile = 0;
            }
            return false;
        }
    }
    DelObj* p2 = (DelObj*)m_pFile;
    if (p2)
    {
        delete p2;
        m_pFile = 0;
    }
    return true;
}

char* __cdecl _FUN_00a7d330(char*);

// @fnv 0x00a61480
void NiSourceCubeMap::AppendGlobalString(StrArr* pkStrings)
{
    GetFileStrings(pkStrings);
    char* psz = _FUN_00a7d330(*(char**)&g_011f4454);
    unsigned int uiSize = *(unsigned short*)((char*)pkStrings + 0xa);
    unsigned int uiCap = *(unsigned short*)((char*)pkStrings + 8);
    if (uiSize >= uiCap)
    {
        unsigned int uiGrow = *(unsigned short*)((char*)pkStrings + 0xe);
        pkStrings->SetSize(uiSize + uiGrow);
    }
    pkStrings->SetAt(uiSize, psz);
}

// The legacy texture LinkObject stub is not declared by NiTexture.h. This
// call-only interface keeps its thiscall signature without copying a game class.
struct LegacyTextureStream
{
    void LinkObject(NiStream&);
};

extern "C" void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x00a60ba0
// src: XBOX_PDB 0x00a60ba0
void NiSourceCubeMap::LinkObject_00a60ba0(NiStream& kStream)
{
    if (kStream.version() < 0x0A030006)
    {
        reinterpret_cast<LegacyTextureStream*>(this)->LinkObject(kStream);
        NiObject* apkFaces[6];
        memset(apkFaces, 0, sizeof(apkFaces));
        if (kStream.GetLinkID() == 6)
        {
            for (unsigned int i = 0; i < 6; i++)
            {
                NiObject* pkObj = kStream.GetLoadedObject();
                if (apkFaces[i] != pkObj)
                {
                    if (apkFaces[i])
                        apkFaces[i]->DecRefCount();
                    apkFaces[i] = pkObj;
                    if (pkObj)
                        pkObj->IncRefCount();
                }
            }
        }
        if (m_spSrcPixelData.m_pObject == 0)
            SetFaces(apkFaces[0], apkFaces[1], apkFaces[2], apkFaces[3], apkFaces[4], apkFaces[5]);
        NiObject** ppkFace = apkFaces + 6;
        for (int j = 5; j >= 0; j--)
        {
            --ppkFace;
            if (*ppkFace)
                (*ppkFace)->DecRefCount();
        }
    }
    else
    {
        LinkObjectOld(kStream);
    }
}

extern "C"
{
    void* __cdecl Object_DispatchCommandFour(unsigned int size);
    void __cdecl NiStandardizeFilePath(char** pp);
    void __cdecl NiImageConverter_ConvertFilenameToPlatformSpecific_(char** pp, unsigned int* p);
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}

extern "C" char* DAT_0109b220;
extern "C" unsigned char DAT_011a9594;

// @fnv 0x00a60f60
NiSourceCubeMap* __cdecl CreateSpawnedCubeShell(char** ppName, NiRenderer* pOwner, unsigned int* pVals)
{
    void* mem = Object_DispatchCommandFour(0x4c);
    NiSourceCubeMap* pShell = mem != 0 ? ::new (mem) NiSourceCubeMap() : 0;
    pShell->m_kFormatPrefs.m_ePreferredPixelLayout = (NiTexture::TextureFormatPreferences::PixelLayout)pVals[0];
    pShell->m_kFormatPrefs.m_eAlphaFormat = (NiTexture::TextureFormatPreferences::AlphaFormat)pVals[1];
    pShell->m_kFormatPrefs.m_eMipFlag = (NiTexture::TextureFormatPreferences::MipFlag)pVals[2];
    char* s = *ppName;
    char** ppStoredName = &pShell->m_kFilename.m_kHandle;
    if (*ppStoredName != s)
    {
        if (s != DAT_0109b220)
        {
            InterlockedIncrement((long volatile*)(s - 8));
        }
        if (*ppStoredName != DAT_0109b220)
        {
            InterlockedDecrement((long volatile*)(*ppStoredName - 8));
        }
        *ppStoredName = s;
    }
    NiStandardizeFilePath(ppStoredName);
    NiImageConverter_ConvertFilenameToPlatformSpecific_(ppStoredName, (unsigned int*)&pShell->m_kPlatformFilename.m_kHandle);
    if (pShell->m_uiFace != 0)
    {
        pShell->m_uiFace = 0;
    }
    if (DAT_011a9594 != 0)
    {
        pShell->LoadPixelDataFromFile();
        if (pOwner != 0 && !CreateCubeRendererData(pOwner, pShell))
        {
            delete pShell;
            return 0;
        }
    }
    return pShell;
}

// @fnv 0x00a61040
// src: XBOX_PDB 0x00a61040
NiSourceCubeMap* __cdecl NiSourceCubeMap_Create(char** ppName, int aValue, NiRenderer* pRenderer, int* pVec)
{
    NiSourceCubeMap* p = new NiSourceCubeMap();
    p->m_kFormatPrefs.m_ePreferredPixelLayout = (NiTexture::TextureFormatPreferences::PixelLayout)pVec[0];
    p->m_kFormatPrefs.m_eAlphaFormat = (NiTexture::TextureFormatPreferences::AlphaFormat)pVec[1];
    p->m_kFormatPrefs.m_eMipFlag = (NiTexture::TextureFormatPreferences::MipFlag)pVec[2];

    char* name = *ppName;
    char** ppNameSlot = &p->m_kFilename.m_kHandle;
    if (*ppNameSlot != name)
    {
        if (name != DAT_0109b220)
        {
            InterlockedIncrement((long volatile*)(name - 8));
        }
        char* old = *ppNameSlot;
        if (old != DAT_0109b220)
        {
            InterlockedDecrement((long volatile*)(old - 8));
        }
        *ppNameSlot = name;
    }

    NiStandardizeFilePath(ppNameSlot);
    NiImageConverter_ConvertFilenameToPlatformSpecific_(ppNameSlot, (unsigned int*)&p->m_kPlatformFilename.m_kHandle);

    if (p->m_uiFace != 0)
    {
        p->m_uiFace = 0;
    }

    p->m_pFile = (NiFile*)aValue;
    p->LoadPixelDataFromFile();

    if (pRenderer != 0 && !CreateCubeRendererData(pRenderer, p))
    {
        delete p;
        return 0;
    }
    return p;
}

struct TextureFormatPreferences
{
    int ePixelLayout;
    int eAlphaFmt;
    int eMipMapped;
};

struct LoadBuffer
{
    int unk00;
    void Init();
    void Shutdown();
    int unk04;
    char m_acPath[260];
    char m_acAltPath[260];
};

// @fnv 0x00a61120
NiSourceCubeMap* __cdecl CreateCubeMap(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, NiRenderer* pkRenderer,
                                 int iUnused, const TextureFormatPreferences* pkPrefs)
{
    NiSourceCubeMap* pkMap = new NiSourceCubeMap;
    *(TextureFormatPreferences*)&pkMap->m_kFormatPrefs = *pkPrefs;

    LoadBuffer kBuf;
    kBuf.Init();
    pkMap->Load(a1, a2, a3, a4, a5, a6, &kBuf);

    if (pkMap->m_uiFace)
        pkMap->m_uiFace = 0;

    if (pkRenderer && (!pkMap->m_spSrcPixelData.m_pObject || !CreateCubeRendererData(pkRenderer, pkMap)))
    {
        delete pkMap;
        kBuf.Shutdown();
        return 0;
    }

    kBuf.Shutdown();
    return pkMap;
}

void NiFree(void* p);

template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream* pkStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return pkStream->BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}

template <class T> inline unsigned int ReadBinaryValue(NiStream& kStream, T& value)
{
    return NiBinaryStreamLoad(CubeMapBinaryStream(kStream), &value, 1);
}

inline void LoadBool(NiStream& kStream, bool& bValue)
{
    char cValue = bValue;
    ReadBinaryValue(kStream, cValue);
    bValue = (cValue != 0);
}

inline void LoadChar(NiStream& kStream, char& cValue)
{
    ReadBinaryValue(kStream, cValue);
}

inline void LoadEnum(NiStream& kStream, int& eValue)
{
    int iValue;
    ReadBinaryValue(kStream, iValue);
    eValue = iValue;
}

// @fnv 0x00a612a0
// src: XBOX_PDB 0x00a612a0
void NiSourceCubeMap::LoadBinary_00a612a0(NiStream& kStream)
{
    if (kStream.version() < 0x0A030006)
    {
        NiTexture::LoadBinary(kStream);
        NiSourceTexture::IncRefCount();

        char cCreateFaces = 0;
        LoadChar(kStream, cCreateFaces);

        char* apcFaceNames[6] = {};
        unsigned int i;
        for (i = 0; i < 6; i++)
            kStream.ReadCString(apcFaceNames[i]);

        kStream.ReadUnsignedInteger(6);
        for (i = 0; i < 6; i++)
            kStream.ResetStreamState();

        if (cCreateFaces)
            CreateFaces(apcFaceNames[0], apcFaceNames[1], apcFaceNames[2], apcFaceNames[3], apcFaceNames[4],
                        apcFaceNames[5], *(int*)((char*)&kStream + 0x1e8));

        for (i = 0; i < 6; i++)
            NiFree(apcFaceNames[i]);

        LoadEnum(kStream, (int&)m_kFormatPrefs.m_ePreferredPixelLayout);
        LoadEnum(kStream, (int&)m_kFormatPrefs.m_eMipFlag);
        LoadEnum(kStream, (int&)m_kFormatPrefs.m_eAlphaFormat);
        bool oldStatic = m_bStatic;
        LoadBool(kStream, oldStatic);
        m_bStatic = oldStatic;
        NiSourceTexture::DecRefCount();
    }
    else
    {
        NiSourceTexture::LoadBinary(kStream);
    }
}

void __cdecl NiSourceTexture_SaveBinary();

// @fnv 0x00a60870
// src: XBOX_PDB 0x00a60870
void __cdecl NiSourceCubeMap_SaveBinary()
{
    NiSourceTexture_SaveBinary();
}

struct NiGPUProgram;

struct ProgramFactory_a60
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual NiGPUProgram* CreateProgram(char* pcName, int iFlags, void* pvDefines);
};
ProgramFactory_a60* __cdecl FUN_00a76640();

struct ShaderPass_a60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    char* m_pcProgramName;
    int unk38;
    NiPointer<NiGPUProgram> m_spShaderProgram;
    int unk40;
    void* m_pvDefines;
    void EnsureProgramCreated();
};
// @fnv 0x00a608c0
void ShaderPass_a60::EnsureProgramCreated()
{
    if (m_spShaderProgram.m_pObject == 0 && m_pcProgramName != DAT_0109b220)
    {
        ProgramFactory_a60* pkFactory = FUN_00a76640();
        char* pcName = m_pcProgramName;
        m_spShaderProgram = pkFactory->CreateProgram(pcName, 0, m_pvDefines);
        m_pvDefines = 0;
    }
}

extern "C" unsigned int __cdecl strlen(const char* s);
extern "C" void* __cdecl memset(void* d, int v, unsigned int n);

struct S00a60cc0_Mgr
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual NiRefObject* Create(char* buf, int a, int b);
};

struct CubeMapLoader
{
    virtual void v00();
    virtual void v01();
    virtual bool v02(char* buf, int size);
    void SetPath(void* p);
};

void* __cdecl _NiMalloc_00aa1070(unsigned int size);
int __cdecl FUN_00ec65a6(char* dst, unsigned int n, const char* src);
void __cdecl NiPath_Standardize(char* p);
void* __cdecl GetPathWithExtension(char* p);
bool __cdecl NiFile_Access(const char* p, int a);

static __forceinline void S00a60cc0_ReleaseAll(NiRefObject** res)
{
    NiRefObject** pp = res + 6;
    int n = 5;
    do
    {
        NiRefObject* p = *--pp;
        if (p)
        {
            if (InterlockedDecrement((long volatile*)&p->m_uiRefCount) == 0)
                p->DeleteThis();
        }
    } while (--n >= 0);
}

// Loads six resources by name via a loader and manager, storing the created refs and calling FUN_00a60940 on success.
// @fnv 0x00a60cc0
void NiSourceCubeMap::LoadResources(char* apName0, char* apName1, char* apName2, char* apName3, char* apName4,
                                     char* apName5, CubeMapLoader* apLoader)
{
    NiRefObject* res[6];
    memset(res, 0, sizeof(res));
    char* names[6] = {apName0, apName1, apName2, apName3, apName4, apName5};
    S00a60cc0_Mgr* mgr = (S00a60cc0_Mgr*)FUN_00a76640();
    char buf[260];
    for (unsigned int idx = 0; idx < 6; idx++)
    {
        char* src = names[idx];
        unsigned int len = strlen(src) + 1;
        char* copy = (char*)_NiMalloc_00aa1070(len);
        FUN_00ec65a6(copy, len, src);
        NiPath_Standardize(copy);
        void* tmp = GetPathWithExtension(copy);
        apLoader->SetPath(tmp);
        apLoader->v01();
        if (apLoader->v02(buf, 260))
        {
        retry:
            if (!NiFile_Access(buf, 0))
            {
                if (apLoader->v02(buf, 260))
                    goto retry;
                goto tail;
            }
            NiRefObject* pNew = mgr->Create(buf, 0, 0);
            NiRefObject* old = res[idx];
            if (old != pNew)
            {
                if (old && InterlockedDecrement((long volatile*)&old->m_uiRefCount) == 0)
                    old->DeleteThis();
                res[idx] = pNew;
                if (pNew)
                    InterlockedIncrement((long volatile*)&pNew->m_uiRefCount);
            }
            NiFree(tmp);
            NiFree(copy);
        }
    tail:
        if (!res[idx])
        {
            S00a60cc0_ReleaseAll(res);
            return;
        }
    }
    LoadFromPixelData(res[0], res[1], res[2], res[3], res[4], res[5]);
    S00a60cc0_ReleaseAll(res);
}

extern "C" void* DAT_0109babc;
extern "C" void __cdecl FUN_00aa1460(void*, unsigned int);
extern "C" void _ReadWriteBarrier();

// Releases pixels, calls FUN_00a5fca0, and calls FUN_00aa1460 with this and sizeof(NiSourceCubeMap) when flags & 1.
// @fnv 0x00a61250
void* NiSourceCubeMap::FUN_00a61250(unsigned int flags)
{
    *(void**)this = &DAT_0109babc;
    _ReadWriteBarrier();
    NiRefObject* old = (NiRefObject*)m_spSrcPixelData.m_pObject;
    if (old)
    {
        if (!InterlockedDecrement((long volatile*)&old->m_uiRefCount))
            old->DeleteThis();
        m_spSrcPixelData.m_pObject = 0;
    }
    NiSourceTexture::~NiSourceTexture();
    if (flags & 1)
        FUN_00aa1460(this, sizeof(NiSourceCubeMap));
    return this;
}

void __cdecl FUN_00ec44d0(void*, const void*, unsigned int) throw();
struct PixelFormat
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
};
struct Pixels
{
    virtual void slot0();
    virtual void Destroy() throw();
    volatile long refs;
    PixelFormat format;
    unsigned char* data;
    unsigned int* widths;
    unsigned int* heights;
    unsigned int* offsets;
    unsigned int levels;
    unsigned int unk64, unk68, unk6c, unk70;
    static void* __cdecl operator new(unsigned int size) throw();
    __declspec(nothrow) unsigned int Width() const
    {
        return *widths;
    }
    __declspec(nothrow) unsigned int Height() const
    {
        return *heights;
    }
    __declspec(nothrow) unsigned int Size(unsigned int level) const
    {
        return offsets[level + 1] - offsets[level];
    }
    __declspec(nothrow) unsigned char* Data(unsigned int level, unsigned int face = 0) const
    {
        return data + offsets[level] + offsets[levels] * face;
    }
    unsigned char* SourceData(unsigned int level) const
    {
        return &data[offsets[level]];
    }
    Pixels(unsigned int, unsigned int, const PixelFormat&, unsigned int, unsigned int) throw();
};
struct PixelPtr
{
    Pixels* ptr;
    __declspec(nothrow) __forceinline void operator=(Pixels* value)
    {
        if (ptr != value)
        {
            Pixels* old = ptr;
            if (old && !InterlockedDecrement(&old->refs))
                old->Destroy();
            ptr = value;
            if (ptr)
                InterlockedIncrement(&ptr->refs);
        }
    }
};

// Allocates a Pixels object with six faces, copies each level from the six inputs, then releases their references.
// @fnv 0x00a60940
// src: COMMUNITY 0x00a60940
void NiSourceCubeMap::LoadFromPixelData(Pixels* a, Pixels* b, Pixels* c, Pixels* d, Pixels* e, Pixels* f)
{
    void* storage = Object_DispatchCommandFour(sizeof(Pixels));
    Pixels* created;
    if (storage)
    {
        unsigned int levels = a->levels;
        unsigned int height = *a->heights;
        unsigned int width = *a->widths;
        created = ::new (storage) Pixels(width, height, a->format, levels, 6);
    }
    else
        created = 0;
    *(PixelPtr*)&m_spSrcPixelData = created;
    PixelPtr facePtrs[6];
    memset(facePtrs, 0, sizeof(facePtrs));
    facePtrs[0] = a;
    facePtrs[1] = b;
    facePtrs[2] = c;
    facePtrs[3] = d;
    facePtrs[4] = e;
    facePtrs[5] = f;
    for (unsigned int face = 0; face < 6; ++face)
    {
        for (unsigned int level = 0; level < facePtrs[face].ptr->levels; ++level)
        {
            Pixels* dst = (Pixels*)m_spSrcPixelData.m_pObject;
            unsigned int size = facePtrs[face].ptr->Size(level);
            unsigned char* source = facePtrs[face].ptr->SourceData(level);
            FUN_00ec44d0(dst->Data(level, face), source, size);
        }
    }
    PixelPtr* cursor = facePtrs + 6;
    for (int cleanup = 5; cleanup >= 0; --cleanup)
    {
        Pixels* old = (--cursor)->ptr;
        if (old && !InterlockedDecrement(&old->refs))
            old->Destroy();
    }
}
