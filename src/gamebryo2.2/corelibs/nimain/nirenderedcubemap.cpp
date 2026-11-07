#include "../../../../include/NiRenderedCubeMap.h"
#include <string.h>

// src/gamebryo2.2/corelibs/nimain/nirenderedcubemap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nirenderedcubemap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// These accessors and the deleting destructor have no declarations in the shared class.
// @fnv 0x00ee8220
// src: XBOX_PDB 0x00ee8220
void* __fastcall NiRenderedCubeMap_GetWidth(NiRenderedCubeMap* cubeMap)
{
    void* p = cubeMap->m_ppCubeMapFaces[0];
    return *(void**)((char*)p + 8);
}

// @fnv 0x00ee8230
// src: XBOX_PDB 0x00ee8230
int __fastcall NiRenderedCubeMap_GetHeight(NiRenderedCubeMap* cubeMap)
{
    void* p = cubeMap->m_ppCubeMapFaces[0];
    return *(int*)((char*)p + 0xc);
}

extern "C" void* DAT_012708e4;

// @fnv 0x00ee82a0
// src: COMMUNITY 0x00ee82a0
void* __cdecl NiRenderedCubeMap_GetRTTI()
{
    return &DAT_012708e4;
}

void __cdecl operator delete(void* p, size_t size);

// @fnv 0x00ee8440
void* __fastcall FUN_00ee8440(NiRenderedCubeMap* cubeMap, void*, unsigned int flags)
{
    cubeMap->ReleaseReference_00ee82b0();
    if (flags & 1)
        operator delete(cubeMap, 0x64);
    return cubeMap;
}

extern "C" void _ReadWriteBarrier(void);
extern int DAT_0109b944;
extern int DAT_0110102c;

// Entry points for base initialization and teardown absent from the shared headers.
void __fastcall InitializeObjectNET(NiObjectNET* object);
void __fastcall InitializeTexture(NiTexture* texture) throw();
void __fastcall DestroyTexture(NiTexture* texture);
void __fastcall DestroyObjectNET(NiObjectNET* object);

// @fnv 0x00ee8240
NiRenderedCubeMap* __fastcall ConstructCubeMap(NiRenderedCubeMap* cubeMap) throw()
{
    InitializeObjectNET(cubeMap);
    *(int**)cubeMap = &DAT_0109b944;
    cubeMap->m_kFormatPrefs.m_ePreferredPixelLayout = NiTexture::TextureFormatPreferences::PIX_DEFAULT;
    cubeMap->m_kFormatPrefs.m_eAlphaFormat = NiTexture::TextureFormatPreferences::ALPHA_DEFAULT;
    cubeMap->m_kFormatPrefs.m_eMipFlag = NiTexture::TextureFormatPreferences::MIP_DEFAULT;
    *(volatile int*)&cubeMap->m_pkRendererData = 0;
    InitializeTexture(cubeMap);
    cubeMap->m_spRenderTargetBuffer.m_pObject = 0;
    _ReadWriteBarrier();
    *(int**)cubeMap = &DAT_0110102c;
    memset(cubeMap->m_ppCubeMapFaces, 0, 0x18);
    cubeMap->unk48 = 0;
    return cubeMap;
}

struct Item
{
    virtual ~Item();
};

// @fnv 0x00ee82b0
// src: GUESS 0x00ee82b0 (confidence: medium)
void NiRenderedCubeMap::ReleaseReference_00ee82b0()
{
    NiRefObject** next = (NiRefObject**)(m_ppCubeMapFaces + 6);
    int count = 5;
    do
    {
        NiRefObject* p = *--next;
        if (p && InterlockedDecrement((volatile long*)p + 1) == 0)
            p->DeleteThis();
        --count;
    } while (count >= 0);
    NiRefObject* p = m_spRenderTargetBuffer.m_pObject;
    if (p && InterlockedDecrement((volatile long*)p + 1) == 0)
        p->DeleteThis();
    *(int*)this = (int)&DAT_0109b944;
    if (m_pkRendererData)
        delete (Item*)m_pkRendererData;
    DestroyTexture(this);
    DestroyObjectNET(this);
}

struct S_00ee8330_RefObject
{
    virtual ~S_00ee8330_RefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((LONG*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((LONG*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct S_00ee8330_Buffer : S_00ee8330_RefObject
{
    static S_00ee8330_Buffer* Create(unsigned int uiWidth, unsigned int uiHeight);
};

inline void AssignFace(void*& face, S_00ee8330_Buffer* object)
{
    if (face != object)
    {
        if (face)
            ((S_00ee8330_Buffer*)face)->DecRefCount();
        face = object;
        if (face)
            ((S_00ee8330_Buffer*)face)->IncRefCount();
    }
}

extern bool DAT_011f4ac0;
extern int DAT_011ab3c8;
extern bool DAT_011ab3c4;

inline bool S_00ee8330_IsPowerOf2(unsigned int ui)
{
    if (ui == 0)
        return false;
    return (ui & (ui - 1)) == 0;
}

struct S_00ee8330_Renderer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual bool CreateRenderedCubeMapRendererData(NiRenderedCubeMap* pkCubeMap);
};

// Allocates a cube map, creates six face buffers, copies three globals into fields, and calls the renderer to create renderer data.
// @fnv 0x00ee8330
// src: XBOX_PDB 0x00ee8330
NiRenderedCubeMap* NiRenderedCubeMap::Create_00ee8330(unsigned int uiFaceSize, NiRenderer* pkRenderer,
                                                     NiTexture::TextureFormatPreferences& kPrefs)
{
    if (!pkRenderer || !S_00ee8330_IsPowerOf2(uiFaceSize))
        return 0;

    NiRenderedCubeMap* pkThis = new NiRenderedCubeMap;
    pkThis->m_kFormatPrefs = kPrefs;

    for (unsigned int ui = 0; ui < 6; ui++)
        AssignFace(pkThis->m_ppCubeMapFaces[ui], S_00ee8330_Buffer::Create(uiFaceSize, uiFaceSize));

    pkThis->m_bUseDepthBuffer = DAT_011f4ac0;
    pkThis->m_ePixelFormat = (_D3DFORMAT)DAT_011ab3c8;
    pkThis->m_bUseMipMaps = DAT_011ab3c4;

    if (!((S_00ee8330_Renderer*)pkRenderer)->CreateRenderedCubeMapRendererData(pkThis))
    {
        delete pkThis;
        return 0;
    }
    return pkThis;
}
