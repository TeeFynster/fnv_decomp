// bsmenu/tileimage.cpp: TileImage, FileFinder, BGSTextureSet, NiNode and more (7 functions)

#include "tileimage_private.h"

// @fnv 0x00a20580
Tile* TileImage::SetTraitValue(int trait, float value, const char* text)
{
    if ((trait == 0xfa1 || trait == 0xfa2) && !(uiFlags & 1))
        SetImageFlags(1);
    else if ((trait == 0xfb1 || trait == 0xfb0) && !(uiFlags & 16))
        SetImageFlags(16);
    else if (trait == 0xfcc && GetValue(0xff9))
        SetImageFlags(16);
    return 0;
}

// @fnv 0x0078cdf0
void TileImage::UpdateTileImage()
{
    ((ExtraDataList*)&g_011ded3c)->GetStartingAngle(0)->FUN_004bc320();
}

// @fnv 0x00a1f6e0
void TileImage::Init(Tile* parent, const char* name, Tile* root)
{
    int unused[2];
    Tile::Init(parent, name, root);
    Set(0xff5, 255.0f, true);
    Set(0xfb2, 255.0f, true);
    Set(0xfb3, 255.0f, true);
    Set(0xfb4, 255.0f, true);
    Set(0xfa9, 255.0f, true);
    Set(0xfad, 1.0f, true);
    Set(0xfa3, 1.0f, true);
    SetTileType(3);
    fScale = 1.0f;
    spTexture = (NiTexture*)0;
    m_bTextureLoaded = false;
}

// Allocates a BSShaderTextureSet and copies each non-empty texture path from textures into it, prefixed with Data\Textures\.
// @fnv 0x00592d20
BSShaderTextureSet* BGSTextureSet::BuildShaderTextureSet()
{
    BSShaderTextureSet* result = new BSShaderTextureSet;
    for (int i = 0; i < 6; ++i)
    {
        const char* path = textures.GetTexturePath(i);
        if (path && *path)
        {
            char szFullPath[260];
            TaskQueueInterface::CopyStringToBuffer(szFullPath, 260, "Data\\Textures\\");
            strcat_s(szFullPath, 260, path);
            result->SetTexturePath(i, szFullPath);
        }
    }
    return result;
}

struct Interface
{
    static float __cdecl GetInterfaceFloat();
};
struct NiGlobalStringTable
{
    static char* __cdecl AddString(const char*);
    static void DecRef(long* p)
    {
        InterlockedDecrement(p);
    }
};
struct FileFinder;
extern FileFinder* g_fileFinder;
struct FileFinder
{
    int GetFileLocation(char*, char*, unsigned int, unsigned int);
    static FileFinder* GetSingleton()
    {
        return g_fileFinder;
    }
};
extern char* EmptyFS;
int _strcpy_s(char*, unsigned int, const char*);
int _strcat_s(char*, unsigned int, const char*);
namespace L {
struct Setting
{
    void* vtbl;
    char* m_pString;
    char* GetString()
    {
        char* r;
        if (this)
            r = m_pString;
        else
            r = 0;
        return r;
    }
};
struct NiFixedString
{
    char* m_kHandle;
    NiFixedString(const char* s)
    {
        if (s == 0)
            m_kHandle = EmptyFS;
        else
            m_kHandle = NiGlobalStringTable::AddString(s);
    }
    ~NiFixedString()
    {
        if (m_kHandle == EmptyFS)
            return;
        NiGlobalStringTable::DecRef((long*)(m_kHandle - 8));
    }
};
struct NiTexture
{
    virtual void S0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct NiTexturePtr
{
    NiTexture* m_pObject;
    NiTexturePtr(NiTexture* p = 0)
    {
        m_pObject = p;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiTexturePtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    bool operator==(const NiTexture* p) const
    {
        return m_pObject == p;
    }
};
}
bool fnv_NiStreamGetTexture(char*, L::NiTexturePtr*);

// Builds a Data\Textures\ path from apFilename, looks up the texture, and falls back to a default setting string if not found.
// @fnv 0x00a1f7d0
void ResolveTexturePath(const char* apFilename, float* afScale, float afZoom, char* axOut)
{
    if (!apFilename || !*apFilename || *apFilename == ' ')
        return;
    float aspect = Interface::GetInterfaceFloat();
    *afScale = 1.0f;
    _strcpy_s(axOut, 260, "Data\\Textures\\");
    _strcat_s(axOut, 260, apFilename);
    L::NiTexturePtr sptex;
    L::NiFixedString path(axOut);
    fnv_NiStreamGetTexture(path.m_kHandle, &sptex);
    if (sptex == 0)
    {
        if (!FileFinder::GetSingleton()->GetFileLocation(axOut, axOut, 6, 0xffffffff))
        {
            if (*afScale != 1.0)
            {
                _strcpy_s(axOut, 260, "Data\\Textures\\");
                _strcat_s(axOut, 260, apFilename);
                if (FileFinder::GetSingleton()->GetFileLocation(axOut, 0, 6, 0xffffffff))
                    *afScale = 1.0f;
                else
                    _strcpy_s(axOut, 260, ((L::Setting*)&g_011d33f0)->GetString());
            }
            else
            {
                _strcpy_s(axOut, 260, ((L::Setting*)&g_011d33f0)->GetString());
            }
        }
    }
}

namespace fnv_00a1fa20 {
struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];
struct BooleanFlagObject
{
    void* __vecDelDtor(unsigned int);
    bool m_bFlag;
};
typedef char _sizecheck_AutoPauseFileCaching[sizeof(BooleanFlagObject) == 1 ? 1 : -1];
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];

extern char* EmptyFS;
extern __declspec(thread) int OM06_tlsMemContext;
struct NiGlobalStringTable
{
    static char* __cdecl AddString(const char*);
    static long* GetRealBufferStart(char* const& h)
    {
        return ((long*)h) - 2;
    }
    static long NiAtomicSubtract(long& v)
    {
        return InterlockedDecrement(&v);
    }
    static void DecRefCount(char*& h)
    {
        if (h == EmptyFS)
            return;
        NiAtomicSubtract(GetRealBufferStart(h)[0]);
    }
};
struct OMFixedString : public NiFixedString
{
    OMFixedString(const char* pc)
    {
        if (pc == 0)
            m_kHandle = EmptyFS;
        else
            m_kHandle = NiGlobalStringTable::AddString(pc);
    }
    ~OMFixedString()
    {
        NiGlobalStringTable::DecRefCount(m_kHandle);
    }
    OMFixedString& operator=(const char* pc)
    {
        if (m_kHandle != pc)
        {
            char* kHandle = m_kHandle;
            m_kHandle = NiGlobalStringTable::AddString(pc);
            NiGlobalStringTable::DecRefCount(kHandle);
        }
        return *this;
    }
};
class OMTex
{
  public:
    virtual void V0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class NiSourceTexture
{
  public:
    static NiSourceTexture* __cdecl Create(const NiFixedString&, NiTexture::TextureFormatPreferences&, bool, bool);
};
class BSFileEntry;
struct TextureFileEntrySetter
{
    static void __cdecl SetTexture(NiTexture*, const BSFileEntry*);
};
struct Interface
{
    static void __cdecl PrintDebugMessage(const char*, ...);
};
struct GO
{
    OMTex* m_pObject;
    void operator=(void* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = (OMTex*)pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
    }
};
struct Helper62d0
{
    OMTex* m_pObject;
    void* operator=(const void* ptr)
    {
        if (m_pObject != ((const Helper62d0*)ptr)->m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ((const Helper62d0*)ptr)->m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return this;
    }
};
class FileFinder;
extern FileFinder* g_fileFinder;
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FL_NONE
    };
    FILE_LOCATION GetFileLocation(char*, char*, unsigned int, unsigned int);
    static FileFinder* GetSingleton()
    {
        return g_fileFinder;
    }
};
extern NiTexture::TextureFormatPreferences DAT_011a9598;
void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
void __cdecl ResolveTexturePath(const char*, float&, float, char*);
char* __cdecl FUN_00ec7750(const char*, const char*);
class OMTexPtr
{
  public:
    OMTex* m_pObject;
    ~OMTexPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator OMTex*() const
    {
        return m_pObject;
    }
};
void __cdecl fnv_NiStreamGetTexture(const char*, OMTexPtr&);
struct OMMemContext
{
    int m_eMemoryContext;
    static int GetCurrent()
    {
        return OM06_tlsMemContext;
    }
    static void SetCurrent(int i)
    {
        OM06_tlsMemContext = i;
    }
    OMMemContext(int iNew)
    {
        m_eMemoryContext = GetCurrent();
        SetCurrent(iNew);
    }
    ~OMMemContext()
    {
        SetCurrent(m_eMemoryContext);
    }
};
// @fnv 0x00a1fa20
void __cdecl LoadTextureForFile(const char* apFilename, float& afScale, OMTexPtr& aspTexture, float afZoom,
                                OMTexPtr apDataImage)
{
    if (!apDataImage)
    {
        char acTexturePath[1024];
        acTexturePath[0] = 0;
        _fnv_zlib_memset(acTexturePath + 1, 0, 0x3ff);
        ResolveTexturePath(apFilename, afScale, afZoom, acTexturePath);
        if (acTexturePath[0])
        {
            OMFixedString path(acTexturePath);
            fnv_NiStreamGetTexture(path.m_kHandle, aspTexture);
            if (!aspTexture && FileFinder::GetSingleton()->GetFileLocation(acTexturePath, 0, 0, 0xffffffff))
            {
                path = acTexturePath;
                OMMemContext tempMemContext(0xd);
                ((GO*)&aspTexture)->operator=(NiSourceTexture::Create(path, DAT_011a9598, true, false));
                if (aspTexture)
                {
                    if (!FUN_00ec7750(acTexturePath, "oading\\load_"))
                        TextureFileEntrySetter::SetTexture((NiTexture*)(OMTex*)aspTexture, 0);
                }
                else
                {
                    Interface::PrintDebugMessage("*** ERROR: Could not create ptexture '%s'!", acTexturePath);
                }
            }
        }
    }
    else
    {
        ((Helper62d0*)&aspTexture)->operator=(&apDataImage);
    }
    return;
}
}  // namespace fnv_00a1fa20

namespace ImageNodeBuild {
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    inline NiPointer(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    inline void Release()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    inline bool operator!() const
    {
        return m_pObject == 0;
    }
    NiPointer<T>& operator=(T*);
    NiPointer<T>& operator=(const NiPointer<T>&);
    inline operator T*() const
    {
        return m_pObject;
    }
    inline T* operator->() const
    {
        return m_pObject;
    }
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);

struct NiObject
{
    virtual void OnObject();
    virtual void DeleteThis();
    long referenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            DeleteThis();
    }
};

struct GeometryData
{
    void FUN_00a67050(int);
};
struct NiNode;
struct PropertyList
{
    void* head;
    void* tail;
    unsigned int count;
    void FUN_00439fd0(const NiPointer<NiNode>&);
};
struct NiNode : NiObject
{
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual int GetPropertyType();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void AttachChildInAvailableSlot(NiNode*, bool);
    void AssignFixedString(const L::NiFixedString&);
    void SetExtraDataName(void*);
    void FUN_00a5a040();
    void FUN_00439410(NiNode*);
    GeometryData* GetGeometryData()
    {
        return geometryData;
    }
    void SetExtraBuffer(void* buffer)
    {
        m_pExtraBuffer = buffer;
    }
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    PropertyList properties;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    GeometryData* geometryData;
    unsigned int unk0bc;
    void* m_pExtraBuffer;
};
inline void NiNode::FUN_00439410(NiNode* property)
{
    if (property->GetPropertyType() < 7)
    {
        NiPointer<NiNode> heldProperty(property);
        properties.FUN_00439fd0(heldProperty);
    }
}
class TileShaderProperty : public NiObject
{
};
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            m_pObject->DecRefCount();
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    return *this;
}
struct TraitArray
{
    void* vtable;
    void* buffer;
    unsigned int size;
    unsigned int reserved;
};
struct StringValue
{
    char* pString;
    unsigned short length;
    unsigned short maxLength;
};
struct GameAllocator
{
    void* FUN_00aa3e40(unsigned int);
};
extern GameAllocator g_GameAllocator;
struct NiPoint3
{
    static __forceinline void* operator new[](size_t n)
    {
        return g_GameAllocator.FUN_00aa3e40((unsigned)n);
    }
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float vx, float vy, float vz) : x(vx), y(vy), z(vz)
    {}
};
struct NiUV
{
    static __forceinline void* operator new[](size_t n)
    {
        return g_GameAllocator.FUN_00aa3e40((unsigned)n);
    }
    float u, v_r;
    NiUV()
    {}
    NiUV(float x, float y) : u(x), v_r(y)
    {}
};
extern void* __cdecl FUN_00aa1070(unsigned int);
extern void* __cdecl FUN_00aa13e0(unsigned int);
extern void* __cdecl FUN_00b55560(unsigned int);
extern void* __cdecl FUN_00706d30();
extern void* __cdecl FUN_00706df0();
extern void* __cdecl AttachFaceGenAnimationData(void*);
extern void __stdcall FUN_00706e00(unsigned int);
extern void __cdecl FUN_00707930(int);
extern unsigned int __cdecl FUN_00ec62c0();
extern void __cdecl FUN_00a5b690_(const char*);
struct FUN_00c5cf30
{
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0xd4);
    }
    FUN_00c5cf30(int, NiPoint3*, NiPoint3*, int, NiUV*, int, int, int, unsigned short*, int, int, unsigned int);
};
struct FUN_00a74410
{
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0xc4);
    }
    FUN_00a74410(int, NiPoint3*, NiPoint3*, int, NiUV*, int, int, int, unsigned short*);
};
static __forceinline unsigned int GeometryTime()
{
    FUN_00706df0();
    FUN_00706e00(FUN_00ec62c0());
    return FUN_00ec62c0();
}
struct FUN_00bb7c30
{
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0xb0);
    }
    FUN_00bb7c30(int);
};
struct FUN_00a5ecb0
{
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0xac);
    }
    FUN_00a5ecb0(int);
};
extern char DAT_010954cc[];
struct FUN_00a7b2e0 : NiObject
{
    char* name;
    FUN_00a7b2e0();
    ~FUN_00a7b2e0();
    void AssignFixedString(const L::NiFixedString&);
};
struct FUN_00a1f610 : FUN_00a7b2e0
{
    void* tile;
    NiNode* node;
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0x14);
    }
    FUN_00a1f610(void* owner, NiNode* model) : tile(owner), node(model)
    {
        AssignFixedString(L::NiFixedString(DAT_010954cc));
    }
};
extern void* __cdecl FUN_00a5b690(const char*);
extern char kGeometryName[];
static __forceinline void GD(NiNode* n)
{
    n->GetGeometryData()->FUN_00a67050(0);
}
static __forceinline NiNode* AsN(NiNode* p)
{
    return p;
}

struct TileImageShim
{
    void* vtable;
    NiTPointerList<Tile*> m_kChildTileList;
    BSSimpleArray<Tile::Value*, 8> m_kValues;
    BSStringT<char> StringProvider;
    Tile* pParent;
    NiPointer<NiNode> m_pRenderedNodeEntry;
    unsigned int uiFlags;
    bool m_bFlagAfterUiFlags;
    bool m_bSpeechChallengeFailure;
    float fScale;
    NiPointer<NiTexture> spTexture;
    NiPointer<TileShaderProperty> m_spShaderProperty;
    bool m_bTextureLoaded;
    NiNode* GetNiNode();
    bool IsTraitNonZero(unsigned int);
    float FUN_00a011b0(unsigned int, int);
    void FUN_00a037e0(unsigned int, float);
    void SetChangeFlag(unsigned int);
    NiNode* FUN_00a1fd50();
};
// Builds a quad geometry object, attaches it beneath a node returned by FUN_00a089c0() or a fallback, and returns the containing node.
// @fnv 0x00a1fd50
NiNode* TileImageShim::FUN_00a1fd50()
{
    NiNode* cnt_lgft;
    cnt_lgft = GetNiNode();
    NiPointer<NiNode> ptr_k;

    NiPoint3* vertices_nriq;
    vertices_nriq = new NiPoint3[4];
    void* s_xx;
    s_xx = 0;
    NiUV* extraBuffer_tjnslw;
    extraBuffer_tjnslw = new NiUV[4];
    unsigned short* indices_tyg;
    indices_tyg = static_cast<unsigned short*>(FUN_00aa1070(6 * sizeof(unsigned short)));
    NiPoint3* previous_zphzqj;
    previous_zphzqj = 0;

    vertices_nriq[0] = NiPoint3(0.0f, 0.0f, 0.0f);
    vertices_nriq[1] = NiPoint3(0.0f, 0.0f, -1.0f);
    vertices_nriq[2] = NiPoint3(1.0f, 0.0f, 0.0f);
    vertices_nriq[3] = NiPoint3(1.0f, 0.0f, -1.0f);
    indices_tyg[0] = 0;
    indices_tyg[1] = 1;
    indices_tyg[2] = 2;
    indices_tyg[3] = 2;
    indices_tyg[4] = 1;
    indices_tyg[5] = 3;

    extraBuffer_tjnslw[0] = NiUV(0.0f, 0.0f);
    extraBuffer_tjnslw[1] = NiUV(0.0f, 1.0f);
    extraBuffer_tjnslw[2] = NiUV(1.0f, 0.0f);
    extraBuffer_tjnslw[3] = NiUV(1.0f, 1.0f);

    if (IsTraitNonZero(0xfae))
    {
        ptr_k =
            (NiNode*)new FUN_00c5cf30(4, vertices_nriq, previous_zphzqj, 0, extraBuffer_tjnslw, 1, 0, 2, indices_tyg, 0,
                                      0, (FUN_00706df0(), FUN_00706e00(FUN_00ec62c0()), FUN_00ec62c0()));
        m_bTextureLoaded = true;
    }
    else
    {
        ptr_k =
            (NiNode*)new FUN_00a74410(4, vertices_nriq, previous_zphzqj, 0, extraBuffer_tjnslw, 1, 0, 2, indices_tyg);
        m_bTextureLoaded = false;
    }

    ptr_k->AssignFixedString(L::NiFixedString(kGeometryName));
    GD(ptr_k);

    m_spShaderProperty = (TileShaderProperty*)(new FUN_00bb7c30(0));
    ptr_k->FUN_00439410((NiNode*)(TileShaderProperty*)m_spShaderProperty);

    void* v_r;
    void* kIter_bw;
    kIter_bw = FUN_00b55560(0x20);
    v_r = kIter_bw;
    ptr_k->SetExtraBuffer(v_r);

    m_pRenderedNodeEntry = (NiNode*)(new FUN_00a5ecb0(0));
    m_pRenderedNodeEntry->AttachChildInAvailableSlot(ptr_k, true);
    if (0 == cnt_lgft)
        cnt_lgft = (NiNode*)FUN_00706d30();
    cnt_lgft->AttachChildInAvailableSlot(m_pRenderedNodeEntry, true);

    m_pRenderedNodeEntry->AssignFixedString(L::NiFixedString(StringProvider.pString));
    AttachFaceGenAnimationData(ptr_k);
    m_pRenderedNodeEntry->FUN_00a5a040();
    FUN_00707930(1);

    m_pRenderedNodeEntry->SetExtraDataName(new FUN_00a1f610(this, (NiNode*)m_pRenderedNodeEntry));

    FUN_00a037e0(0xfad, FUN_00a011b0(0xfad, 0));
    if (IsTraitNonZero(0xfae))
        SetChangeFlag(0x100);
    SetChangeFlag(0x3d);
    return (NiNode*)m_pRenderedNodeEntry;
}

}
