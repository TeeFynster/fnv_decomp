
// src/gamebryo2.2/corelibs/nimain/nisingleshadermateriallibrary.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nisingleshadermateriallibrary.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiMaterialLibrary.h"
#include "../../../../include/NiShaderFactory.h"
#include "../../../../include/NiSingleShaderMaterialLibrary.h"

extern NiMaterial* __cdecl FindOrCreateShaderEntry(NiMaterial*, int);

// @fnv 0x00a8fd60
NiMaterial* NiSingleShaderMaterialLibrary::vf02(const NiFixedString* kName)
{
    char* p = kName->m_kHandle;
    return FindOrCreateShaderEntry((NiMaterial*)p, 1);
}

extern NiMaterial* DAT_011f5e40;

// @fnv 0x00a8fcc0
// src: XBOX_PDB 0x00a8fcc0
void __cdecl NiSingleShaderMaterialLibrary__SDMShutdown()
{
    NiMaterial* material = DAT_011f5e40;
    if (material)
        ((void(__thiscall*)(NiMaterial*, int))(*reinterpret_cast<void***>(material))[0])(material, 1);
    DAT_011f5e40 = 0;
}

// Local declarations pending include/NiShaderLibraryDesc.h: 0x00a9ffd0 reads count at 0x44; 0x00a9ffe0 indexes the array at 0x3C.
class NiShaderLibraryDesc
{
public:
    unsigned int NiShaderLibraryDesc_GetShaderCount();
    void* NiShaderLibraryDesc_GetShaderDesc(int);
};
struct RefCountedNamedObject
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual NiShaderLibraryDesc* w5();
};
// Walks the shader factory's library list, summing the material count reported by each library's descriptor, and returns the total.
// @fnv 0x00a8fc70
unsigned int NiSingleShaderMaterialLibrary::vf04()
{
    RefCountedNamedObject* pkLib;
    NiShaderFactory* pkFactory;
    unsigned int uiTotalMaterials;
    uiTotalMaterials = 0;
    pkFactory = NiShaderFactory::GetInstance();
    if (!pkFactory)
        return uiTotalMaterials;
    pkLib = pkFactory->v14();
    while (pkLib)
    {
        NiShaderLibraryDesc* pkDesc = pkLib->w5();
        if (pkDesc)
            uiTotalMaterials += pkDesc->NiShaderLibraryDesc_GetShaderCount();
        pkLib = pkFactory->v15();
    }
    return uiTotalMaterials;
}

// Registers the class name string as the library name, then zeroes _c and _d.
// @fnv 0x00a8fce0
NiSingleShaderMaterialLibrary::NiSingleShaderMaterialLibrary()
    : NiMaterialLibrary(NiFixedString("NiSingleShaderMaterialLibrary")), _c(0), _d(0)
{
}

extern int DAT_0109f7b4;
void __cdecl _delete(void*, unsigned int);
// Sets the vfptr to DAT_0109f7b4, clears _c and _d, calls the NiMaterialLibrary destructor, and deletes this with size 0x14 when flag bit 0 is set.
// @fnv 0x00a8fd30
void* NiSingleShaderMaterialLibrary::Destroy(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_0109f7b4;
    _c = 0;
    _d = 0;
    NiMaterialLibrary::~NiMaterialLibrary();
    if (auiFlags & 1)
        _delete(this, 0x14);
    return this;
}

// @fnv 0x00a8fac0
void* NiSingleShaderMaterialLibrary::vf05()
{
    NiShaderFactory* pkFactory = NiShaderFactory::GetInstance();
    RefCountedNamedObject* library = pkFactory->v14();
    _c = (int)library;
    _d = 0;
    if (library)
    {
        NiShaderLibraryDesc* desc = library->w5();
        while (!desc->NiShaderLibraryDesc_GetShaderCount())
        {
            _c = (int)pkFactory->v15();
            _d = 0;
            desc = ((RefCountedNamedObject*)_c)->w5();
        }
        if (desc)
        {
            if (desc->NiShaderLibraryDesc_GetShaderCount())
                return desc->NiShaderLibraryDesc_GetShaderDesc(_d);
        }
    }
    return 0;
}

// Stand-in for NameProvider (not declared in this unit)
struct NameProvider
{
    virtual void w0();
    virtual void w1();
    virtual const char* GetName();
};

// @fnv 0x00a8fbf0
const char* NiSingleShaderMaterialLibrary::GetShaderNameByIndex(unsigned int uiShaderIndex)
{
    unsigned int uiBaseIndex;
    RefCountedNamedObject* pkLib;
    NiShaderFactory* pkFactory;
    NiShaderLibraryDesc* pkDesc;
    NameProvider* pkShaderDesc;

    uiBaseIndex = 0;
    pkFactory = NiShaderFactory::GetInstance();
    pkLib = pkFactory->v14();
    if (pkLib)
    {
        do
        {
            pkDesc = pkLib->w5();
            if (pkDesc)
            {
                if (pkDesc->NiShaderLibraryDesc_GetShaderCount() + uiBaseIndex > uiShaderIndex)
                {
                    pkShaderDesc =
                        (NameProvider*)pkDesc->NiShaderLibraryDesc_GetShaderDesc(uiShaderIndex - uiBaseIndex);
                    return pkShaderDesc->GetName();
                }
                uiBaseIndex += pkDesc->NiShaderLibraryDesc_GetShaderCount();
            }
            pkLib = pkFactory->v15();
        } while (pkLib);
    }
    return 0;
}

// @fnv 0x00a8fb50
void* NiSingleShaderMaterialLibrary::vf06()
{
    NiShaderFactory* factory = NiShaderFactory::GetInstance();
    RefCountedNamedObject* lib = factory->v14();
    if (lib != (RefCountedNamedObject*)_c)
    {
        do
        {
            lib = factory->v15();
        } while (lib != (RefCountedNamedObject*)_c);
    }
    _d++;
    if (lib == 0)
    {
        goto L_008b;
    }
    NiShaderLibraryDesc* desc;
L_0035:
    desc = lib->w5();
    if (desc != 0)
    {
        if (desc->NiShaderLibraryDesc_GetShaderCount() > _d)
        {
            goto L_0067;
        }
    }
    lib = factory->v15();
    _c = (int)lib;
    _d = 0;
    if (lib != 0)
    {
        goto L_0035;
    }
L_0067:
    if (_c == 0)
    {
        goto L_008b;
    }
    if (desc == 0)
    {
        goto L_008b;
    }
    {
        unsigned int idx = _d;
        if (desc->NiShaderLibraryDesc_GetShaderCount() > idx)
        {
            return desc->NiShaderLibraryDesc_GetShaderDesc(idx);
        }
    }
L_008b:
    return 0;
}
