
// src/gamebryo2.2/corelibs/nianimation/nirotdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nirotdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiRotData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

extern const NiRTTI g_011f3f50;

// @fnv 0x00a48150
// src: COMMUNITY 0x00a48150
const NiRTTI* __cdecl NiRotData_GetRTTI()
{
    return &g_011f3f50;
}

extern unsigned char DAT_011f3764[];
extern void(__cdecl* DAT_011f38d0[])(TimedRotationKey*);

// Releases the current key array, then stores the new key pointer, count and interpolation type, or clears them when no keys are given.
// @fnv 0x00a48220
void NiRotData::SetKeys(TimedRotationKey* pkKeys, unsigned int uiNumKeys, NiAnimationKey::KeyType eInterpType)
{
    if (m_pKeyArray)
        DAT_011f38d0[m_eRequestType](m_pKeyArray);
    if (pkKeys && uiNumKeys)
    {
        m_ucKeyDataSize = DAT_011f3764[eInterpType];
        m_pKeyArray = pkKeys;
        m_uiNumKeys = uiNumKeys;
        m_eRequestType = eInterpType;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = NiAnimationKey::NOINTERP;
        m_ucKeyDataSize = 0;
    }
}

void __cdecl ReleaseObjectArray(void*);
extern int DAT_0109844c;
struct MM00a47ba0
{
    void __thiscall _DeallocateAlias(void*);
};
extern MM00a47ba0 g_memoryManager;
struct Struct00a47ba0
{
    int _0;
    void* _4;
    void* FUN_00a47ba0(unsigned int);
};
// @fnv 0x00a47ba0
void* Struct00a47ba0::FUN_00a47ba0(unsigned int auiFlags)
{
    void* p = _4;
    ((void**)this)[0] = (void*)&DAT_0109844c;
    ReleaseObjectArray(p);
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

extern int DAT_010984ec;
void __cdecl _delete(void*, unsigned int);

// @fnv 0x00a481e0
void* __fastcall DestroyRotData(NiRotData* self, int, unsigned int auiFlags)
{
    TimedRotationKey* pk = self->m_pKeyArray;
    *(void**)self = (void*)&DAT_010984ec;
    if (pk)
        DAT_011f38d0[self->m_eRequestType](pk);
    ((NiRefObject*)self)->NiRefObject::~NiRefObject();
    if (auiFlags & 1)
        _delete(self, 0x18);
    return self;
}

namespace fnv_00a49d00 {
// Reads the rotation key data stored at offset 0x40 of the NiRotData and writes its key, count, key size and key array to the output pointers, or zeros if absent.
// @fnv 0x00a49d00
void __fastcall GetRotKeyData(NiRotData* pThis, int, TimedRotationKey** ppkKeysOut, int* piKeyOut, int* piCountOut,
                              unsigned char* pKeySize)
{
    NiRotData* pkKey = *(NiRotData**)((char*)pThis + 0x40);
    if (pkKey)
    {
        *piKeyOut = pkKey->m_uiNumKeys;
        *piCountOut = pkKey->m_eRequestType;
        *pKeySize = pkKey->m_ucKeyDataSize;
        *ppkKeysOut = pkKey->m_pKeyArray;
    }
    else
    {
        *piKeyOut = 0;
        *piCountOut = 0;
        *ppkKeysOut = 0;
        *pKeySize = 0;
    }
}
}  // namespace fnv_00a49d00

struct SelfStub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52(char*);
    void BSShaderLightingProperty_CopyMembers(char*, void*);
    void Lighting30ShaderProperty_CopyMembers(char*, void*);
};
// Calls FUN_00b702b0 with the given arguments, then invokes v52 on the same char pointer.
// @fnv 0x00b665d0
// src: COMMUNITY 0x00b665d0
void SelfStub::Lighting30ShaderProperty_CopyMembers(char* a, void* b)
{
    BSShaderLightingProperty_CopyMembers(a, b);
    v52(a);
}

struct S00b66600
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52(int);
};
void __fastcall BSShaderLightingProperty_CopyTo(S00b66600*, int, int);
// Calls FUN_00b70290 with the two int arguments, then invokes the virtual method v52 on the object with the second argument.
// @fnv 0x00b66600
// src: XBOX_PDB 0x00b66600
void __fastcall BSShaderPPLightingProperty_CopyTo(S00b66600* p, int aiFirst, int aiSecond)
{
    BSShaderLightingProperty_CopyTo(p, aiFirst, aiSecond);
    p->v52(aiSecond);
}

extern void* DAT_011f3b10[];

// @fnv 0x00a48160
bool __fastcall IsRotDataEqual(NiRotData* self, int, NiObject* pkObject)
{
    NiRotData* pkData = (NiRotData*)pkObject;
    if (!self->NiObject::IsEqual(pkObject))
        return false;
    if (self->m_uiNumKeys != pkData->m_uiNumKeys)
        return false;
    if (self->m_eRequestType != pkData->m_eRequestType)
        return false;
    if (self->m_ucKeyDataSize != pkData->m_ucKeyDataSize)
        return false;
    void(__cdecl * pfnEqualFunc)(TimedRotationKey*) = (void(__cdecl*)(TimedRotationKey*))DAT_011f3b10[self->m_eRequestType];
    for (unsigned int ui = 0; ui < self->m_uiNumKeys; ++ui)
    {
        unsigned int uiKeyOffset = self->m_ucKeyDataSize * ui;
        TimedRotationKey* pkB = (TimedRotationKey*)((char*)pkData->m_pKeyArray + uiKeyOffset);
        TimedRotationKey* pkA = (TimedRotationKey*)((char*)self->m_pKeyArray + uiKeyOffset);
        if (!((bool(__cdecl*)(TimedRotationKey*, TimedRotationKey*))pfnEqualFunc)(pkA, pkB))
            return false;
    }
    return true;
}

struct NiRTTIAccess
{
    void* m_pIntegerData;
};

void* __cdecl _FUN_00a7d330(void* pObject);
char* __cdecl NiGetViewerString_00a7d510(char const* pName, unsigned int uiValue);
void __stdcall AppendCameraPathEntries(StrArr* apViewerStrings);

// @fnv 0x00a484c0
void __fastcall AppendNumKeysToStringArray(NiRotData* self, int, StrArr* apViewerStrings)
{
    AppendCameraPathEntries(apViewerStrings);

    char* pString =
        static_cast<char*>(_FUN_00a7d330(reinterpret_cast<const NiRTTIAccess*>(&g_011f3f50)->m_pIntegerData));

    unsigned int uiSize = apViewerStrings->m_usSize;
    if (uiSize >= apViewerStrings->m_usMaxSize)
        apViewerStrings->SetSize(uiSize + apViewerStrings->m_usGrowBy);
    apViewerStrings->SetAt(uiSize, pString);

    pString = NiGetViewerString_00a7d510("self->m_uiNumKeys", self->m_uiNumKeys);

    uiSize = apViewerStrings->m_usSize;
    if (uiSize >= apViewerStrings->m_usMaxSize)
        apViewerStrings->SetSize(uiSize + apViewerStrings->m_usGrowBy);
    apViewerStrings->SetAt(uiSize, pString);
}

struct FUN_00b66620_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int m_d8;
    void BSShaderPPLightingProperty_SetClampD3D(int value);
};

// Stores 3 when the incoming value differs from 3, otherwise 0.
// @fnv 0x00b66620
// src: XBOX_PDB 0x00b66620
void FUN_00b66620_cls::BSShaderPPLightingProperty_SetClampD3D(int value)
{
    m_d8 = (value != 3) ? 3 : 0;
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(
        this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += uiBytesRead;
    return uiBytesRead;
}

inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24C);
}

template <class T> void NiBinaryStreamLoad(NiBinaryStream& is, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    unsigned int uiBytesToRead = sizeof(T) * uiNumEls;
    is.BinaryRead(pValue, uiBytesToRead, &uiSize, 1);
}

template <class T> void ReadValueFromBinaryStream(NiBinaryStream& is, T* pValue)
{
    int iDummy;
    unsigned int uiBytesToRead = sizeof(int);
    is.BinaryRead(&iDummy, uiBytesToRead, &uiBytesToRead, 1);
    *pValue = (T)iDummy;
}

template <class T> void ReadBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(kStream.Istr(), &value, 1);
}

template <class T> void ReadStreamValue(NiStream& kStream, T& value)
{
    ReadValueFromBinaryStream(kStream.Istr(), &value);
}

extern unsigned char DAT_011f3764[];
typedef TimedRotationKey*(__cdecl* CreateFunction)(NiStream&, unsigned int);
typedef void(__cdecl* FillDerivedValsFunction)(TimedRotationKey*, unsigned int, unsigned char);
extern CreateFunction g_apfnCreateKey[];
extern FillDerivedValsFunction g_apfnFillDerived[];

// Loads the key count and key type from the stream, creates and fills the key array, then stores it via FUN_00a48220.
// @fnv 0x00a48380
void __fastcall LoadRotData(NiRotData* self, int, NiStream& kStream)
{
    self->NiObject::LoadBinary(kStream);

    unsigned int uiNumKeys;
    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        NiAnimationKey::KeyType eRotType;
        ReadStreamValue(kStream, eRotType);

        self->m_ucKeyDataSize = DAT_011f3764[eRotType];

        CreateFunction pfnCreateFunc = g_apfnCreateKey[eRotType];
        TimedRotationKey* pkRotKeys = pfnCreateFunc(kStream, uiNumKeys);

        FillDerivedValsFunction pfnFillDerivedFunc = g_apfnFillDerived[eRotType];
        pfnFillDerivedFunc(pkRotKeys, uiNumKeys, self->m_ucKeyDataSize);

        self->SetKeys(pkRotKeys, uiNumKeys, eRotType);
    }
}

inline unsigned int BinaryRead2(NiBinaryStream& is, void* pvBuffer, unsigned int uiTotalBytes,
                                unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead =
        (*reinterpret_cast<NiBinaryStream::ReadFunction*>(reinterpret_cast<char*>(&is) + 0xC))(
            &is, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&is) + 4) += uiBytesRead;
    return uiBytesRead;
}

template <class T> void NiBinaryStreamLoad2(NiBinaryStream& is, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    unsigned int uiBytesToRead = sizeof(T) * uiNumEls;
    BinaryRead2(is, pValue, uiBytesToRead, &uiSize, 1);
}

template <class T> void NiStreamLoadBinary2(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad2(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x250), &value, 1);
}
typedef void(__cdecl* KeyLinkFunction)(NiStream&, TimedRotationKey*, unsigned int);
extern KeyLinkFunction DAT_011f3a80[];

// Loads the object header, key count, request type, and key array from the stream using the key link function table.
// @fnv 0x00a48440
void __fastcall LinkRotData(NiRotData* self, int, NiStream& kStream)
{
    self->NiObject::LinkObject(kStream);
    NiStreamLoadBinary2(kStream, self->m_uiNumKeys);
    if (self->m_uiNumKeys > 0)
    {
        NiStreamLoadBinary2(kStream, self->m_eRequestType);
        DAT_011f3a80[self->m_eRequestType](kStream, self->m_pKeyArray, self->m_uiNumKeys);
    }
}

extern int(__stdcall* DAT_00fdf1c0)(void*);
extern int(__stdcall* DAT_00fdf1c4)(void*);

void __cdecl NiAnimationKey_CopySequence(int a1, int a2, void* a3, unsigned int a4, float a5, float a6, TimedRotationKey** a7,
                          unsigned int* a8);

// Obtains an object, fills its keys using the current key data and time arguments, then assigns it to ppRival with reference counting.
// @fnv 0x00a48280
void __fastcall CopyRotData(NiRotData* self, int, float fTime, float fDuration, NiRotData** ppRival)
{
    NiRotData* pNew = 0;

    self->ResolveObjectPointer(reinterpret_cast<NiPointer<NiObject>&>(pNew));

    NiRotData* pCopy = pNew;
    if (pCopy != 0)
        DAT_00fdf1c0(&pCopy->m_uiRefCount);

    if (self->m_uiNumKeys > 0)
    {
        TimedRotationKey* pKeys = 0;
        unsigned int uiNumKeys = 0;
        NiAnimationKey_CopySequence(2, self->m_eRequestType, self->m_pKeyArray, self->m_uiNumKeys, fTime, fDuration, &pKeys, &uiNumKeys);
        pCopy->SetKeys(pKeys, uiNumKeys, (NiAnimationKey::KeyType)self->m_eRequestType);
    }

    NiRotData* pOld = *ppRival;
    int(__stdcall * releaseRef)(void*) = DAT_00fdf1c4;

    if (pOld != pCopy)
    {
        if (pOld != 0)
        {
            if (releaseRef(&pOld->m_uiRefCount) == 0)
                pOld->DeleteThis();
        }

        *ppRival = pCopy;

        if (pCopy != 0)
            DAT_00fdf1c0(&pCopy->m_uiRefCount);
    }

    if (pCopy != 0)
    {
        if (releaseRef(&pCopy->m_uiRefCount) == 0)
            pCopy->DeleteThis();
    }

    NiRotData* pDestroy = pNew;
    if (pDestroy != 0)
    {
        if (releaseRef(&pDestroy->m_uiRefCount) == 0)
            pDestroy->DeleteThis();
    }
}
