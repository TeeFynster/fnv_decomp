// gamebryo2.2/corelibs/nimain/nisingleshadermaterial.cpp: NiDepthStencilBuffer, NiSingleShaderMaterial (8 functions)

#include "../../../../include/NiDepthStencilBuffer.h"
#include "../../../../include/NiPixelFormat.h"
#include "../../../../include/NiShaderFactory.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiShader.h"
#include "../../../../include/NiSingleShaderMaterial.h"
#include <new>

inline NiDepthStencilBuffer::NiDepthStencilBuffer() throw()
{}

// Creates a NiDepthStencilBuffer when its format is depth/stencil, sets width/height, and returns it or 0 if CreateRendererData fails.
// @fnv 0x00a9fe90
NiDepthStencilBuffer* NiDepthStencilBuffer::Create(unsigned int width, unsigned int height, NiRenderer*,
                                                   const NiPixelFormat& format, unsigned int samples)
{
    if (format.m_eFormat != NiPixelFormat::FORMAT_DEPTH_STENCIL)
        return 0;
    NiDepthStencilBuffer* buffer = new NiDepthStencilBuffer;
    buffer->m_uiImageWidth = width;
    buffer->m_uiImageHeight = height;
    if (!buffer->CreateRendererData(format, samples))
    {
        delete buffer;
        return 0;
    }
    return buffer;
}

extern "C" void* g_011f6048;

// @fnv 0x00aa06e0
// src: GUESS 0x00aa06e0 (confidence: low)
void* NiSingleShaderMaterial::GetGlobalObjectAddress_00aa06e0()
{
    return &g_011f6048;
}

// Returns true if pkShader is non-null and its filename string equals the string stored at this+0x0C; otherwise false.
// @fnv 0x00aa0770
bool __thiscall NiSingleShaderMaterial::MatchesShaderFilename(NiShader* pkShader, const NiGeometry* pkGeometry,
                                                          const NiSkinInstance* pkSkinInstance,
                                                          const NiPropertyState* pkPropertyState,
                                                          const NiDynamicEffectState* pkDynamicEffectState,
                                                          unsigned int uiMaterialExtraData)
{
    if (pkShader && pkShader->GetFilename().m_kHandle == m_kShaderFilename.m_kHandle)
        return true;
    return false;
}

// If not manual, decrements the shader's reference count, calls its release when it hits zero, and clears m_sp.
// @fnv 0x00aa0830
void NiSingleShaderMaterial::ReleaseShader()
{
    if (!m_bManual)
    {
        NiShader* pShader = m_sp;
        if (pShader)
        {
            if (InterlockedDecrement(reinterpret_cast<long volatile*>(&pShader->m_uiRefCount)) == 0)
                pShader->DeleteThis();
            m_sp = 0;
        }
    }
}

extern int DAT_010a21dc;

// NiMaterial's named initialization entry is not yet declared in its shared header.
void InitializeMaterial();

// @fnv 0x00aa06f0
// src: EXE 0x00aa06f0
NiSingleShaderMaterial* NiSingleShaderMaterial::NiSingleShaderMaterial_00aa06f0(void* arg1, char const* apcString, bool abCreateShader)
{
    typedef void (__thiscall* InitializeMaterialEntry)(NiMaterial*, void*);
    reinterpret_cast<InitializeMaterialEntry>(InitializeMaterial)(this, arg1);

    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_010a21dc);

    if (!apcString)
    {
        m_kShaderFilename.m_kHandle = NiGlobalStringTable::ms_pcEmptyString;
    }
    else
    {
        m_kShaderFilename.m_kHandle = NiGlobalStringTable::AddString(apcString);
    }

    m_sp = 0;
    m_bManual = false;

    if (abCreateShader)
    {
        NiShaderFactory* factory = NiShaderFactory::GetInstance();
        NiShader* shader = reinterpret_cast<NiShader*>(factory->Create(apcString, -1, 0));
        if (shader)
        {
            long volatile* refs = reinterpret_cast<long volatile*>(&shader->m_uiRefCount);
            InterlockedIncrement(refs);
            if (!InterlockedDecrement(refs))
            {
                shader->DeleteThis();
            }
        }
    }

    return this;
}

// The shared NiShader header does not yet declare this implementation-ID query.
int __fastcall NiShader_GetImplementation(NiShader* shader);

// Returns a compatible cached shader, or creates and initializes one through the shader factory.
// @fnv 0x00aa07a0
// src: XBOX_PDB 0x00aa07a0
NiShader* NiSingleShaderMaterial::GetCurrentShader(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int key)
{
    NiShaderFactory* pManager = NiShaderFactory::GetInstance();
    if (m_sp)
    {
        if (NiShader_GetImplementation(m_sp) == key)
            return m_sp;
        if (key == -1)
        {
            if (pManager)
            {
                NiShader* pCached = m_sp;
                // The shared factory's slot 0x24 lacks the shader-validation signature.
                typedef bool (__thiscall* ValidateShader)(NiShaderFactory*, NiShader*);
                if (reinterpret_cast<ValidateShader>((*reinterpret_cast<void***>(pManager))[9])(pManager, pCached))
                    return m_sp;
            }
        }
    }
    NiShader* pResult = 0;
    if (pManager)
    {
        const char* h = m_kShaderFilename.m_kHandle;
        pResult = reinterpret_cast<NiShader*>(pManager->Create(h, key, 1));
    }
    if (pResult && (pResult->IsFormInitialized() || pResult->Initialize()))
        return pResult;
    return 0;
}

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

// Releases the shader reference and string buffer, runs base cleanup, and optionally frees the 0x18-byte object.
// @fnv 0x00aa0870
NiSingleShaderMaterial* NiSingleShaderMaterial::Destroy(unsigned char acFlags)
{
    long(__stdcall * pfnRelease)(long volatile*) = InterlockedDecrement;
    *(int volatile*)this = (int)&DAT_010a21dc;
    NiShader* sp = *(NiShader* volatile*)&m_sp;
    if (sp != 0)
    {
        if (pfnRelease(reinterpret_cast<long volatile*>(&sp->m_uiRefCount)) == 0)
        {
            sp->DeleteThis();
        }
    }
    if (m_kShaderFilename.m_kHandle != NiGlobalStringTable::ms_pcEmptyString)
    {
        pfnRelease((long volatile*)((char*)m_kShaderFilename.m_kHandle - 8));
    }
    BaseCleanup();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x18);
    }
    return this;
}

void* __cdecl Object_DispatchCommandFour(unsigned int uiSize) throw();

inline NiFixedString::operator const char*() const
{
    return m_kHandle;
}

// The factory starts the temporary lifetime before assigning its string.
// Defer construction in aligned storage while using the shared string bodies.
template <class T> class DeferredConstruction
{
public:
    DeferredConstruction() throw() {}
    ~DeferredConstruction() throw() { reinterpret_cast<T*>(m_storage)->~T(); }
    T& Construct(const char* pcName) throw() { return *::new (m_storage) T(pcName); }
private:
    union
    {
        char m_storage[sizeof(T)];
        void* m_alignment;
    };
};

NiSingleShaderMaterial* __cdecl Object_FindGlobalHashValue(const char* const& pcName) throw();

// The approved header lacks the non-throwing material constructor.
extern "C" __declspec(nothrow) void ConstructSingleShaderMaterial();
inline NiSingleShaderMaterial* InitializeSingleShaderMaterial(NiSingleShaderMaterial* material,
    NiFixedString& name, const char* filename, bool flag) throw()
{
    typedef NiSingleShaderMaterial* (__thiscall* Constructor)(NiSingleShaderMaterial*, NiFixedString*, const char*, bool);
    return reinterpret_cast<Constructor>(ConstructSingleShaderMaterial)(material, &name, filename, flag);
}

// Finds the named material or creates a single-shader material with the requested filename and flag.
// @fnv 0x00aa08d0
NiSingleShaderMaterial* __cdecl FindOrCreateShaderEntry(const char* pcName, bool bFlag)
{
    NiSingleShaderMaterial* pkFound = Object_FindGlobalHashValue(NiFixedString(pcName));
    if (pkFound)
        return pkFound;
    NiSingleShaderMaterial* material = reinterpret_cast<NiSingleShaderMaterial*>(Object_DispatchCommandFour(sizeof(NiSingleShaderMaterial)));
    return material ? InitializeSingleShaderMaterial(material,
        DeferredConstruction<NiFixedString>().Construct(pcName), pcName, bFlag) : 0;
}
