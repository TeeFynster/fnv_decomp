#include "../../../../include/NiFlipController.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiAlphaController.h"
#include "../../../../include/NiFloatData.h"
#include "../../../../include/NiFloatInterpolator.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiTexture.h"
#include "../../../../include/NiStream.h"

// src/gamebryo2.2/corelibs/nianimation/niflipcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niflipcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00a4f300
void* NiFlipController::GetEntryAt(int uiIndex)
{
    unsigned short size = m_kTextureSwapList.m_usSize;
    if ((unsigned int)uiIndex < size)
    {
        NiPointer<NiTexture>* arr = m_kTextureSwapList.m_pBase;
        return arr[uiIndex].m_pObject;
    }
    return 0;
}

extern "C" const void* g_011f3fd4;

// @fnv 0x00a4f5d0
// src: COMMUNITY 0x00a4f5d0
const void* __cdecl NiFlipController_GetRTTI()
{
    return &g_011f3fd4;
}

// @fnv 0x00a4f970
void* __cdecl CreateNiFlipController()
{
    void* p = BSFadeNode::operator new(0x54);
    if (p)
        return ((NiFlipController*)p)->FUN_00a4f820();
    return 0;
}

void* __cdecl _NiMalloc(unsigned int);
int __cdecl _NiSprintf(char*, unsigned int, const char*, ...);
// Returns the cached string at offset 0x50, lazily formatting the integer at offset 0x4c into a 15-byte buffer with "%d" if it is null.
// @fnv 0x00a4f320
const char* __thiscall NiFlipController::GetFormattedValue()
{
    char* pcFormattedValue = (char*)m_pkBuf;
    if (!pcFormattedValue)
    {
        pcFormattedValue = (char*)_NiMalloc(15);
        m_pkBuf = pcFormattedValue;
        _NiSprintf(pcFormattedValue, 15, "%d", m_eAffectedMap);
        pcFormattedValue = (char*)m_pkBuf;
    }
    return pcFormattedValue;
}

extern NiRTTI g_011f49a4;

// Walks pkTarget's NiRTTI base chain and returns true if it reaches g_011f49a4, false for a null target or RTTI.
// @fnv 0x00a4f5e0
// src: GUESS 0x00a4f5e0 (confidence: medium)
bool __stdcall Object_HasRTTIInBaseChain(NiObjectNET* pkTarget)
{
    if (!pkTarget)
        return false;
    const NiRTTI* pkRTTI = pkTarget->GetRTTI();
    if (!pkRTTI)
        return false;
    while (pkRTTI)
    {
        if (pkRTTI == &g_011f49a4)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    }
    return false;
}

inline void* NiFlipController::GetSrc(unsigned int i)
{
    unsigned short cnt = m_kTextureSwapList.m_usSize;
    NiPointer<NiTexture>* arr = m_kTextureSwapList.m_pBase;
    if (i < cnt)
        return arr[i].m_pObject;
    return 0;
}

// Calls the base copy, copies the int at offset 0x4c to dst, then copies each source entry via GetSrc and FUN_00a4f8a0.
// @fnv 0x00a4f920
// src: GAMEBRYO_LIB 0x00a4f920
void __thiscall NiFlipController::CopyMembers_00a4f920(NiAlphaController* dst, CloningProcess& proc)
{
    NiFloatInterpController::CopyMemberData(dst, &proc);
    ((NiFlipController*)dst)->m_eAffectedMap = m_eAffectedMap;
    for (unsigned int i = 0; i < m_kTextureSwapList.m_usSize; ++i)
    {
        void* e = this->GetSrc(i);
        ((NiFlipController*)dst)->AttachTexture(e, i);
    }
}

struct FUN_00a40520
{
    static void* operator new(unsigned int size)
    {
        return BSFadeNode::operator new(size);
    }
    unsigned char _pad[12];
    unsigned char m_uiObjectFlags;
    unsigned char _pad2[39];
    __declspec(nothrow) FUN_00a40520(bool, float, unsigned char);
};
// @fnv 0x00a4f2c0
// src: XBOX_PDB 0x00a4f2c0
FUN_00a40520* __stdcall NiFlipController_CreateBlendInterpolator(unsigned short usIndex, bool bManagerControlled, bool bAccumulateAnimations,
                                     float fWeightThreshold, unsigned char ucArraySize)
{
    FUN_00a40520* pkInterp = new FUN_00a40520(bManagerControlled, fWeightThreshold, ucArraySize);
    pkInterp->m_uiObjectFlags |= 2;
    return pkInterp;
}

// @fnv 0x00a4f350
// src: XBOX_PDB 0x00a4f350
bool NiFlipController::RegisterStreamables_00a4f350(NiStream& kStream)
{
    if (!NiFloatInterpController::RegisterStreamables(kStream))
        return false;
    unsigned int uiSize = m_kTextureSwapList.m_usSize;
    unsigned int uiIndex;
    NiTexture* pkTexture;
    for (uiIndex = 0; uiIndex < uiSize; ++uiIndex)
    {
        pkTexture = m_kTextureSwapList.m_pBase[uiIndex].m_pObject;
        if (pkTexture)
            ((NiObject*)pkTexture)->RegisterStreamables(kStream);
    }
    return true;
}

// Allocates a NiFlipController, initialises it via FUN_00a4f820, copies from kCloning via FUN_00a4f920, and returns it as a NiObject.
// @fnv 0x00a4fa20
void* NiFlipController::CreateFlipController(CloningProcess& kCloning)
{
    NiFlipController* pkObject = (NiFlipController*)NiFloatInterpController::operator new(0x54);
    if (pkObject)
        pkObject = (NiFlipController*)pkObject->FUN_00a4f820();
    else
        pkObject = 0;
    CopyMembers_00a4f920((NiAlphaController*)pkObject, kCloning);
    return (NiObject*)pkObject;
}

// @fnv 0x00a4f270
void NiFlipController::GetFloatValue(float* pfOut)
{
    *pfOut = (float)m_uiPosition;
}

// Compares the base controller and affected map.
// @fnv 0x00a4f290
// src: GAMEBRYO_LIB 0x00a4f290
unsigned char NiFlipController::IsEqual_00a4f290(NiFlipController* param)
{
    if (!NiFloatInterpController::IsEqual(param))
    {
        return 0;
    }

    return m_eAffectedMap == param->m_eAffectedMap;
}

struct FNVWriter
{
    void* unk00;
    unsigned int written;
    void* unk08;
    unsigned int(__cdecl* Write)(FNVWriter*, const void*, unsigned int, unsigned int*, unsigned int);
    void SaveResult(const void* data)
    {
        unsigned int bytes = 4;
        unsigned int result = Write(this, data, 4, &bytes, 1);
        written += result;
    }
};
// Calls the base save, writes the field at 0x4c and a count, then saves each of the count objects from the array at 0x3c via the stream.
// @fnv 0x00a4f4e0
void __thiscall NiFlipController::SaveToStream(NiStream* stream)
{
    NiFloatInterpController::SaveBinary(*stream);
    FNVWriter* writer = *(FNVWriter**)((char*)stream + 0x250);
    writer->SaveResult(&m_eAffectedMap);

    unsigned int count = m_kTextureSwapList.m_usSize;
    writer = *(FNVWriter**)((char*)stream + 0x250);
    {
        unsigned int bytes = 4;
        writer->written += writer->Write(writer, &count, 4, &bytes, 1);
    }
    for (unsigned int i = 0; i < count; ++i)
    {
        void* object = m_kTextureSwapList.m_pBase[i].m_pObject;
        stream->SaveLinkID(reinterpret_cast<const NiObject*>(object));
    }
}

char** NiTObjectArray_NiPointer_NiTexture_NiTObjectArray_NiPointer_NiTexture(unsigned int ItemUpdateArray) throw();

template <class T, class A>
inline NiTArray<T, A>::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    m_usMaxSize = (unsigned short)uiMaxSize;
    m_usGrowBy = (unsigned short)uiGrowBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = (T*)NiTObjectArray_NiPointer_NiTexture_NiTObjectArray_NiPointer_NiTexture(m_usMaxSize);
    else
        m_pBase = 0;
}

template <class T>
inline NiTPrimitiveArray<T>::NiTPrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy) throw()
    : NiTArray<T, NiTMallocInterface<T> >(uiMaxSize, uiGrowBy)
{}

// @fnv 0x00a4f820
NiFlipController::NiFlipController() : m_kTextureSwapList(1, 1)
{
    m_uiPosition = 0;
    m_eAffectedMap = 0;
    m_pkBuf = 0;
}

void* _NiMalloc_00aa1070(unsigned int uiSize);
void* FUN_00ec61c0(void* pDest, int iValue, int iCount);

struct FUN_00a6d220
{
    FUN_00a6d220();
    virtual void v00();
    int unk;
    int unkCur;
    int unk0c;
    int unkValue;
    int uNewnk;
    int uTmpnk;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
};

struct MapBase_a4d
{
    MapBase_a4d(unsigned int uiHashSize = 37)
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(void*) * m_uiHashSize;
        m_ppkHashTable = (void**)_NiMalloc_00aa1070(uiSize);
        FUN_00ec61c0(m_ppkHashTable, 0, m_uiHashSize * sizeof(void*));
    }
    virtual void v00();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

struct MapMid_a4d : MapBase_a4d
{
    MapMid_a4d(unsigned int uiHashSize = 37) : MapBase_a4d(uiHashSize)
    {
        m_bCopy = false;
    }
    bool m_bCopy;
};

struct Map_a4d : MapMid_a4d
{
    Map_a4d(unsigned int uiHashSize = 37) : MapMid_a4d(uiHashSize)
    {}
    virtual void v00();
};

struct FUN_00a4da20_cls : FUN_00a6d220
{
    FUN_00a4da20_cls();
    virtual void v00();
    Map_a4d kMap;
};

// Default constructor for a class that embeds a Map_a4d, which initialises its hash table with the default size.
// @fnv 0x00a4da20
FUN_00a4da20_cls::FUN_00a4da20_cls()
{}

// NiFlipController::Update: advance the interpolator, round its value to a texture index, clamp it,
// and assign that texture to the affected map (regular map slot, or shader map at index - 0x400).

extern float DAT_01096324;         // NiTimeController::INVALID_TIME
extern const double DAT_01016408;  // 0.5
struct NiUpdateDataF
{
    float m_fTime;
};

struct MapF
{
    void SetTexture(NiTexture* pkTexture);
};
struct ShaderMapArrayF
{
    void* m_vtbl;
    MapF** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short GetSize() const
    {
        return m_usSize;
    }
};
struct NiTexturingPropertyF
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void* m_aMapsVtbl;
    MapF** m_aMapsBase;
    unsigned short m_usMapsMax;
    unsigned short m_usMapsSize;
    int unk28;
    ShaderMapArrayF* m_pShaderMaps;
    MapF* GetShaderMap(unsigned int uiIndex) const;
    unsigned int GetShaderMapCount() const
    {
        return m_pShaderMaps ? m_pShaderMaps->GetSize() : 0;
    }
};

// Advances the flip controller's interpolator and applies the resulting texture index to the target's affected map or shader map.
// @fnv 0x00a4f3a0
void NiFlipController::UpdateFlipController(NiUpdateDataF& kUpdate)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = DAT_01096324;
    }
    else if (AdvanceController(kUpdate.m_fTime) &&
             (!m_spControllerInterpolator.m_pObject || !m_spControllerInterpolator.m_pObject->AlwaysUpdate()))
    {
        return;
    }

    if (m_spControllerInterpolator.m_pObject)
    {
        float fValue;
        if (m_spControllerInterpolator.m_pObject->UpdateFloat(m_fControllerTime, m_pkTarget, fValue))
        {
            unsigned int uiSize = m_kTextureSwapList.m_usSize;
            m_uiPosition = (unsigned int)(fValue + DAT_01016408);
            if (m_uiPosition >= uiSize)
                m_uiPosition = uiSize - 1;

            NiTexturingPropertyF* pkProp = (NiTexturingPropertyF*)m_pkTarget;
            if (pkProp)
            {
                if (m_eAffectedMap < pkProp->m_usMapsSize && pkProp->m_aMapsBase[m_eAffectedMap])
                {
                    pkProp->m_aMapsBase[m_eAffectedMap]->SetTexture(m_kTextureSwapList.m_pBase[m_uiPosition].m_pObject);
                }
                else
                {
                    unsigned int uiShaderMapIndex = m_eAffectedMap - 0x400;
                    if (uiShaderMapIndex < pkProp->GetShaderMapCount() && pkProp->GetShaderMap(uiShaderMapIndex))
                    {
                        pkProp->GetShaderMap(uiShaderMapIndex)->SetTexture(m_kTextureSwapList.m_pBase[m_uiPosition].m_pObject);
                    }
                }
            }
        }
    }
}

void __cdecl NiFree(void* pkData) throw();
void __cdecl j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(void* pkData) throw();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plCount);

template <class T, class A>
inline NiTArray<T, A>::~NiTArray()
{
    j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(m_pBase);
}

extern const void* g_NiFlipControllerVTable;

// The shared single-interpolator base has no explicit destructor declaration.
// Keep its inlined cleanup here until that lifecycle declaration is available.
// @fnv 0x00a4f570
void __fastcall DestroyNiFlipController(NiFlipController* controller, void*)
{
    void* buffer = controller->m_pkBuf;
    *(const void**)controller = &g_NiFlipControllerVTable;
    NiFree(buffer);
    controller->m_pkBuf = 0;
    controller->m_kTextureSwapList.NiTArray<NiPointer<NiTexture>, NiTMallocInterface<NiPointer<NiTexture> > >::~NiTArray();
    NiInterpolator* interpolator = controller->m_spControllerInterpolator.m_pObject;
    if (interpolator)
    {
        if (InterlockedDecrement((long*)&interpolator->m_uiRefCount) == 0)
            interpolator->DeleteThis();
    }
    controller->NiTimeController::~NiTimeController();
}

void __cdecl _delete(void*, unsigned int);

// @fnv 0x00a4f880
void* __fastcall DestroyFlipControllerIfFlagged(NiFlipController* controller, void*, unsigned int flags)
{
    DestroyNiFlipController(controller, 0);
    if (flags & 1)
        _delete(controller, 0x54);
    return controller;
}

inline bool NiFlipController::GetManagerControlled() const
{
    return ((m_uiObjectFlags >> 5) & 1) ? true : false;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);

struct StreamIo
{
    void* m_00;
    unsigned int m_iFirstInteger;
    unsigned int(__cdecl* Transfer)(StreamIo*, const void*, unsigned int, unsigned int*, unsigned int);
    void Read4(const void* data)
    {
        unsigned int bytes = 4;
        unsigned int result = Transfer(this, data, 4, &bytes, 1);
        m_iFirstInteger += result;
    }
};

extern MemoryManager DAT_011f6238;

// Keep construction inline and nonthrowing as in the original unit.
__declspec(nothrow) inline NiFloatData::NiFloatData()
{
    m_uiNumKeys = 0;
    m_pKeyArray = 0;
    m_eRequestType = (NiAnimationKey::KeyType)0;
    m_ucKeyDataSize = 0;
}

struct KeyPair
{
    float t;
    float v;
    ~KeyPair();
};

void* operator new[](unsigned int size)
{
    return DAT_011f6238.Allocate(size);
}

// 0x00a4f610 NiFlipController::LoadFromStream is in src/staging/blk_00a40000_o2_noehsc_variant.cpp (built without /EHsc).

// Grows the array if needed, increments the reference count of p, stores a copy of p in the array slot, then decrements the count and releases if zero.
// @fnv 0x00a4f8a0
// src: COMMUNITY 0x00a4f8a0
void __thiscall NiFlipController::AttachTexture(void* apRef, unsigned int aiIndex)
{
    if (m_kTextureSwapList.m_usSize <= aiIndex)
        m_kTextureSwapList.SetSize(aiIndex + 1);
    NiTexture* pRef = (NiTexture*)apRef;
    apRef = pRef;
    void* slot = apRef;
    if (pRef != 0)
        InterlockedIncrement((long*)&pRef->m_uiRefCount);
    NiTPrimitiveArray<NiPointer<NiTexture> >* pArr = &m_kTextureSwapList;
    if (aiIndex >= pArr->m_usMaxSize)
        pArr->SetSize(aiIndex + pArr->m_usGrowBy);
    pArr->NiTArray<NiPointer<NiTexture>, NiTMallocInterface<NiPointer<NiTexture> > >::SetAt(aiIndex, *(NiPointer<NiTexture>*)&slot);
    if (pRef != 0)
    {
        if (InterlockedDecrement((long*)&pRef->m_uiRefCount) == 0)
            pRef->DeleteThis();
    }
}

// Links the base controller, then loads the texture swap list when a target is present.
// @fnv 0x00a4f990
// src: GAMEBRYO_LIB 0x00a4f990
void NiFlipController::LinkObject_00a4f990(NiStream& kStream) throw()
{
    NiFloatInterpController::LinkObject(kStream);
    if (m_pkTarget)
    {
        unsigned int uiSize = kStream.GetLinkID();
        m_kTextureSwapList.SetSize(uiSize);
        for (unsigned int i = 0; i < uiSize; i++)
        {
            NiTexture* pkTex = (NiTexture*)kStream.GetLoadedObject();
            NiTexture* spTex = pkTex;
            if (pkTex)
                InterlockedIncrement((long*)&pkTex->m_uiRefCount);
            m_kTextureSwapList.NiTArray<NiPointer<NiTexture>, NiTMallocInterface<NiPointer<NiTexture> > >::SetAt(i, *(NiPointer<NiTexture>*)&spTex);
            if (pkTex)
            {
                if (InterlockedDecrement((long*)&pkTex->m_uiRefCount) == 0)
                    pkTex->DeleteThis();
            }
        }
    }
}

