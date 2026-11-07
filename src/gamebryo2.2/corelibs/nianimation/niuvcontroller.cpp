#include "../../../../include/NiUVController.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiUVData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nianimation/niuvcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niuvcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Reads fields at offsets 0x20, 0x28, 0x4a and 0x24 from the pointer at this+0x48 into the out params and returns the 0x24 value, or zeros if null.
// @fnv 0x00a45a90
int __thiscall NiUVController::GetSomeValues(int* piValue1, int* piValue2, char* c)
{
    NiUVData* p = m_pData.m_pObject;
    if (p)
    {
        *piValue1 = p->m_uiNumUTilingKeys;
        *piValue2 = p->m_uiUTilingKeyStride;
        *c = p->m_ucByte4A;
        return (int)p->m_pUTilingKeys;
    }
    else
    {
        *piValue1 = 0;
        *piValue2 = 0;
        *c = 0;
        return 0;
    }
}

extern int g_011f3f18;

// @fnv 0x00a45b30
// src: COMMUNITY 0x00a45b30
int* __cdecl NiUVController_GetRTTI()
{
    return &g_011f3f18;
}

// @fnv 0x00a459f0
int __thiscall NiUVController::GetDataFromMember(int* piValue1, int* piValue2, char* c)
{
    NiUVData* p = m_pData.m_pObject;
    if (p)
    {
        *piValue1 = p->m_uiNumUOffsetKeys;
        *piValue2 = p->m_uiUOffsetKeyStride;
        *c = p->m_ucByte48;
        return (int)p->m_pUOffsetKeys;
    }
    else
    {
        *piValue1 = 0;
        *piValue2 = 0;
        *c = 0;
        return 0;
    }
}

// Reads three ints and a byte from the object at this+0x48 into the out params and returns another int, or zeroes them if that pointer is null.
// @fnv 0x00a45ae0
int __thiscall NiUVController::GetSomePtrValues(int* piValue1, int* piValue2, char* c)
{
    NiUVData* p = m_pData.m_pObject;
    if (p)
    {
        *piValue1 = p->m_uiNumVTilingKeys;
        *piValue2 = p->m_uiVTilingKeyStride;
        *c = p->m_ucByte4B;
        return (int)p->m_pVTilingKeys;
    }
    else
    {
        *piValue1 = 0;
        *piValue2 = 0;
        *c = 0;
        return 0;
    }
}

// Reads fields from the object at this+0x48 (offset 0x14) into the three out-params and returns q[1], or zeroes them and returns 0 when that pointer is null.
// @fnv 0x00a45a40
int __thiscall NiUVController::GetSomeData(int* piFirst, int* piSecond, char* c)
{
    NiUVData* p = m_pData.m_pObject;
    if (p)
    {
        *piFirst = p->m_uiNumVOffsetKeys;
        *piSecond = p->m_uiVOffsetKeyStride;
        *c = p->m_ucByte49;
        return (int)p->m_pVOffsetKeys;
    }
    else
    {
        *piFirst = 0;
        *piSecond = 0;
        *c = 0;
        return 0;
    }
}

void __cdecl _delete(void* p, unsigned int flags);


// Calls FUN_00a45b60, then if bit 0 of flags is set deletes this with size 0x50, and returns this.
// @fnv 0x00a46000
void* __thiscall NiUVController::DestroyIfFlagged(unsigned int flags)
{
    ProcessAndReturnValue_00a45b60();
    if (flags & 1)
        _delete(this, 0x50);
    return this;
}

struct MyOstr
{
    int _0;
    int _4;
    void* _8;
    int(__cdecl* _C)(MyOstr*, void*, unsigned int, unsigned int*, unsigned int);
    int Write(void* pBuf, unsigned int uiSize)
    {
        unsigned int ui = uiSize;
        int i = _C(this, pBuf, uiSize, &ui, 1);
        _4 += i;
        return i;
    }
};
struct MyStream
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void SaveObject(void* p);
    char _004[0x24C];
    MyOstr* m_pBackingStream;
};
struct Base44
{
    void FUN_00a6d730(MyStream* kStream);
    void FUN_00a6d5e0(MyStreamWriter* stream);
    bool RegisterStreamables(void* stream);
    void LinkObject(void* stream);
};

// Keep the stream argument opaque across the approved and working NiStream tags.
// @fnv 0x00a46070
void __fastcall SaveUVController(NiUVController* controller, void*, MyStream* kStream)
{
    ((Base44*)controller)->FUN_00a6d730(kStream);
    kStream->m_pBackingStream->Write(&controller->m_usValue, 2);
    kStream->SaveObject(controller->m_pData.m_pObject);
}

struct BaseCall
{
    int Destroy();
    void FUN_00a6d830(StrArr*);
};
char* _FUN_00a7d330(const char*);

// @fnv 0x00a46150
// src: XBOX_PDB 0x00a46150
void NiUVController::GetViewerStrings_00a46150(StrArr* pStrArr)
{
    ((BaseCall*)this)->FUN_00a6d830(pStrArr);
    char* s = _FUN_00a7d330((const char*)g_011f3f18);
    unsigned int a = *(unsigned short*)((char*)pStrArr + 0xA);
    unsigned int b = *(unsigned short*)((char*)pStrArr + 8);
    if (a >= b)
    {
        unsigned int c = *(unsigned short*)((char*)pStrArr + 0xE);
        pStrArr->SetSize(c + a);
    }
    pStrArr->SetAt(a, s);
}

// @fnv 0x00a45970
// src: XBOX_PDB 0x00a45970
bool __thiscall NiUVController::RegisterStreamables_00a45970(void* stream)
{
    NiStream& kStream = *(NiStream*)stream;
    if (!((Base44*)this)->RegisterStreamables(stream))
        return false;
    NiUVData* pkUVData = m_pData.m_pObject;
    if (pkUVData)
        pkUVData->RegisterStreamables(kStream);
    return true;
}

// @fnv 0x00a45cf0
// src: XBOX_PDB 0x00a45cf0
void NiUVController::Update_00a45cf0(NiUpdateData& UpdateData)
{
    if (!AdvanceController(UpdateData.fTime))
        m_bUpdateEnabled = 1;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

// Replaces the UV data reference, clears the cached key indices, and updates the time bounds.
// @fnv 0x00a45fa0
void __thiscall NiUVController::AssignRefObj(NiUVData* apRefObj)
{
    if (m_pData.m_pObject != apRefObj)
    {
        NiUVData* pOld = m_pData.m_pObject;
        if (pOld)
        {
            if (!InterlockedDecrement((volatile long*)&pOld->m_uiRefCount))
                pOld->DeleteThis();
        }
        m_pData.m_pObject = apRefObj;
        if (apRefObj)
            InterlockedIncrement((volatile long*)&apRefObj->m_uiRefCount);
    }
    m_uiLastIdx0 = 0;
    m_uiLastIdx2 = 0;
    m_uiLastIdx1 = 0;
    m_uiLastIdx3 = 0;
    ResetKeyTimeExtrema();
}

// Links the controller to the stream, replacing its UV data pointer with the stream's object and updating reference counts.
// @fnv 0x00a45910
void NiUVController::LinkUVData(void* stream)
{
    NiStream& kStream = *(NiStream*)stream;
    ((Base44*)this)->LinkObject(stream);
    NiUVData* pkData = (NiUVData*)kStream.GetLoadedObject();
    NiUVData* pOld = m_pData.m_pObject;
    if (pOld != pkData)
    {
        if (pOld)
        {
            if (InterlockedDecrement((volatile long*)&pOld->m_uiRefCount) == 0)
                pOld->DeleteThis();
        }
        m_pData.m_pObject = pkData;
        if (pkData)
            InterlockedIncrement((volatile long*)&pkData->m_uiRefCount);
    }
}

// @fnv 0x00a45b40
void NiUVController::ResetRefObject()
{
    NiUVData* p = m_pData.m_pObject;
    *(float*)&p->unk38 = 0.0f;
    *(float*)&p->unk3C = 0.0f;
    *(float*)&p->unk40 = 1.0f;
    *(float*)&p->unk44 = 1.0f;
    ResetControllerState();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct RefObject
{
    virtual void Acquire();
    virtual void ReleaseObject();
    volatile long refCount;

    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            ReleaseObject();
    }
};

struct SharedRef
{
    RefObject* ptr;
    ~SharedRef() throw()
    {
        if (ptr)
            ptr->DecRefCount();
    }
    void Reset()
    {
        if (ptr)
        {
            ptr->DecRefCount();
            ptr = 0;
        }
    }
};

extern int DAT_01098064;

extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

// @fnv 0x00a45b60
// src: GUESS 0x00a45b60 (confidence: low)
int __thiscall NiUVController::ProcessAndReturnValue_00a45b60()
{
    *(void**)this = &DAT_01098064;
    SharedRef* owner = (SharedRef*)&m_pData;
    owner->Reset();
    // Preserve the separate member-destruction read used by the original destructor.
    _ReadWriteBarrier();
    owner->~SharedRef();
    return ((BaseCall*)this)->Destroy();
}

void* __cdecl Object_DispatchCommandFour(unsigned int size) throw();

// The construction adapter initializes this member after installing the vtable.
template <> inline NiPointer<NiUVData>::NiPointer()
{
}

// The header has no explicit constructor; keep its initialization here while
// inheriting all layout and member declarations from the shared class.
struct UVControllerConstruction : NiUVController
{
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }

    UVControllerConstruction() throw()
    {
        *(void**)this = &DAT_01098064;
        *(void* volatile*)&m_pData.m_pObject = 0;
        _ReadWriteBarrier();
        *(unsigned short volatile*)&m_usValue = 0;
        m_uiLastIdx0 = 0;
        m_uiLastIdx2 = 0;
        m_uiLastIdx1 = 0;
        m_uiLastIdx3 = 0;
        m_bChanged = 0;
    }
};

// @fnv 0x00a45f50
// src: EXE 0x00a45f50
NiUVController* __cdecl NiUVController_CreateObject() throw()
{
    NiUVController* p = new UVControllerConstruction;
    return p;
}

struct OutputWriter
{
    int reserved00;
    int writtenBytes;
    int(__cdecl* writeCallback)(OutputWriter*, void*, unsigned int, unsigned int*, unsigned int);
    int Write(void* bytes, unsigned int count)
    {
        unsigned int written = count;
        int result = writeCallback(this, bytes, count, &written, 1);
        writtenBytes += result;
        return result;
    }
};
struct MyStreamWriter : MyStream
{
    void ReadLinkID();
    OutputWriter* Output()
    {
        return *reinterpret_cast<OutputWriter**>(&_004[0x248]);
    }
};


// @fnv 0x00a46020
void NiUVController::WriteToStream(MyStreamWriter* stream)
{
    ((Base44*)this)->FUN_00a6d5e0(stream);
    stream->Output()->Write(&m_usValue, sizeof(m_usValue));
    stream->ReadLinkID();
}

// IsEqual: base comparison, then the type value and the (optional) child object must match.

template <> inline NiPointer<NiUVData>::operator NiUVData*() const
{
    return m_pObject;
}

struct UVControllerBaseComparison
{
    bool IsEqual(UVControllerBaseComparison* object);
};

inline bool operator==(const NiPointer<NiUVData>& pointer, const NiUVData* object)
{
    return pointer.m_pObject == object;
}

// @fnv 0x00a459a0
bool NiUVController::IsEqual(NiObject* pkObject) const
{
    NiUVController* pkOther = (NiUVController*)pkObject;
    if (!((UVControllerBaseComparison*)this)->IsEqual((UVControllerBaseComparison*)pkOther))
        return false;

    if (m_usValue != pkOther->m_usValue)
        return false;

    if ((m_pData == 0) != (pkOther->m_pData == 0))
        return false;

    if (m_pData && !static_cast<const NiObject*>((NiUVData*)m_pData)->IsEqual((NiUVData*)pkOther->m_pData))
        return false;

    return true;
}

struct CloneableObj
{
    void __thiscall FUN_00a6cfe0(void* pObject, unsigned int flags);
};


// Allocates a controller and copies its base state, key indices, texture set, and UV data.
// @fnv 0x00a460c0
unsigned int* __thiscall NiUVController::CloneUVData(unsigned int flags)
{
    NiUVController* pUVData = new UVControllerConstruction;

    ((CloneableObj*)this)->FUN_00a6cfe0(pUVData, flags);

    pUVData->m_uiLastIdx0 = m_uiLastIdx0;
    pUVData->m_uiLastIdx2 = m_uiLastIdx2;
    pUVData->m_uiLastIdx1 = m_uiLastIdx1;
    pUVData->m_uiLastIdx3 = m_uiLastIdx3;
    pUVData->m_usValue = m_usValue;

    if (m_pData.m_pObject)
    {
        pUVData->AssignRefObj(m_pData.m_pObject);
    }

    return reinterpret_cast<unsigned int*>(pUVData);
}

extern float DAT_01016970;
extern float DAT_01015f5c;

// Computes the time bounds from the first and last keys of each UV channel.
// @fnv 0x00a45bc0
// src: XBOX_PDB 0x00a45bc0
void __thiscall NiUVController::ResetKeyTimeExtrema()
{
    m_fLoKeyTime = DAT_01016970;
    m_fHiKeyTime = DAT_01015f5c;
    NiUVData* pChan = m_pData.m_pObject;
    if (pChan)
    {
        float* pData = (float*)pChan->m_pUOffsetKeys;
        int iCount = (int)pChan->m_uiNumUOffsetKeys;
        unsigned char s = pChan->m_ucByte48;
        if (pData)
        {
            if (pData[0] < 3.4028234663852886e+38)
                m_fLoKeyTime = pData[0];
            iCount -= 1;
            if (*(float*)((char*)pData + s * iCount) > -3.4028234663852886e+38)
                m_fHiKeyTime = *(float*)((char*)pData + s * iCount);
        }
    }
    pChan = m_pData.m_pObject;
    if (pChan)
    {
        float* pData = (float*)pChan->m_pVOffsetKeys;
        int iCount = (int)pChan->m_uiNumVOffsetKeys;
        unsigned char s = pChan->m_ucByte49;
        if (pData)
        {
            if (pData[0] < m_fLoKeyTime)
                m_fLoKeyTime = pData[0];
            iCount -= 1;
            if (*(float*)((char*)pData + s * iCount) > m_fHiKeyTime)
                m_fHiKeyTime = *(float*)((char*)pData + s * iCount);
        }
    }
    pChan = m_pData.m_pObject;
    if (pChan)
    {
        float* pData = (float*)pChan->m_pUTilingKeys;
        int iCount = (int)pChan->m_uiNumUTilingKeys;
        unsigned char s = pChan->m_ucByte4A;
        if (pData)
        {
            if (pData[0] < m_fLoKeyTime)
                m_fLoKeyTime = pData[0];
            iCount -= 1;
            if (*(float*)((char*)pData + s * iCount) > m_fHiKeyTime)
                m_fHiKeyTime = *(float*)((char*)pData + s * iCount);
        }
    }
    pChan = m_pData.m_pObject;
    if (pChan)
    {
        int iCount = (int)pChan->m_uiNumVTilingKeys;
        unsigned char s = pChan->m_ucByte4B;
        float* pData = (float*)pChan->m_pVTilingKeys;
        if (pData)
        {
            if (pData[0] < m_fLoKeyTime)
                m_fLoKeyTime = pData[0];
            iCount -= 1;
            if (*(float*)((char*)pData + s * iCount) > m_fHiKeyTime)
                m_fHiKeyTime = *(float*)((char*)pData + s * iCount);
        }
    }
}

float __cdecl InterpolateKey(float fTime, UVKey* pkKeys, int eType, unsigned int uiNumKeys, unsigned int* puiLastIdx,
                             unsigned char ucSize);
struct UVPoint
{
    float x;
    float y;
};
struct UVGeomData
{
    int unk00;
    int unk04;
    unsigned short m_usVertices;
    unsigned short unk0a;
    unsigned short m_usTrianglePoints;
    UVPoint* __thiscall NiGeometryData_GetTextureSet(unsigned short usSet);
    void __thiscall FUN_00a67090(unsigned short usFlags);
    unsigned short GetTextureSets()
    {
        return m_usTrianglePoints & 1;
    }
};
struct UVGeom;

struct UVGeom
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    UVGeomData* m_spGeometryData;
};

// Applies animated UV offset and tiling to the target geometry's texture coordinates when m_bChanged is set.
// @fnv 0x00a45d10
void NiUVController::UpdateUVTransform()
{
    if (!m_bChanged)
        return;

    UVGeomData* pkData = ((UVGeom*)m_pkTarget)->m_spGeometryData;
    if (m_usValue >= pkData->GetTextureSets())
        return;

    float fAnimOffsetU, fAnimOffsetV, fAnimTilingU, fAnimTilingV;
    {
        unsigned int uiNumKeys;
        int eType;
        unsigned char ucSize;
        UVKey* pkKeys;

        fAnimOffsetU = 0.0f;
        pkKeys = GetDataFromMember(uiNumKeys, eType, ucSize);
        if (pkKeys)
            fAnimOffsetU = InterpolateKey(m_fControllerTime, pkKeys, eType, uiNumKeys, &m_uiLastIdx0, ucSize);

        fAnimOffsetV = 0.0f;
        pkKeys = GetSomeData(uiNumKeys, eType, ucSize);
        if (pkKeys)
            fAnimOffsetV = InterpolateKey(m_fControllerTime, pkKeys, eType, uiNumKeys, &m_uiLastIdx2, ucSize);

        fAnimTilingU = 1.0f;
        pkKeys = GetSomeValues(uiNumKeys, eType, ucSize);
        if (pkKeys)
            fAnimTilingU = InterpolateKey(m_fControllerTime, pkKeys, eType, uiNumKeys, &m_uiLastIdx1, ucSize);

        fAnimTilingV = 1.0f;
        pkKeys = GetSomePtrValues(uiNumKeys, eType, ucSize);
        if (pkKeys)
            fAnimTilingV = InterpolateKey(m_fControllerTime, pkKeys, eType, uiNumKeys, &m_uiLastIdx3, ucSize);
    }

    float fScaleU = fAnimTilingU / (*(float*)&m_pData.m_pObject->unk40);
    float fPrevOffsetU = (*(float*)&m_pData.m_pObject->unk38);
    float fScaleV = fAnimTilingV / (*(float*)&m_pData.m_pObject->unk44);
    float fPrevOffsetV = (*(float*)&m_pData.m_pObject->unk3C);

    UVPoint* pkTex = pkData->NiGeometryData_GetTextureSet(m_usValue);

    float fDeltaU = fAnimOffsetU - fPrevOffsetU * fScaleU;
    float fDeltaV = fAnimOffsetV - fPrevOffsetV * fScaleV;
    UVPoint kTrans;
    kTrans.x = 0.5 * (1.0f - fScaleU) - fDeltaU;
    kTrans.y = 0.5 * (1.0f - fScaleV) + fDeltaV;

    unsigned short usVertexCount = pkData->m_usVertices;
    for (unsigned short i = 0; i < usVertexCount; i++)
    {
        pkTex[i].x = pkTex[i].x * fScaleU + kTrans.x;
        pkTex[i].y = pkTex[i].y * fScaleV + kTrans.y;
    }

    NiUVData* pkUV = m_pData.m_pObject;
    (*(float*)&pkUV->unk38) = fAnimOffsetU;
    (*(float*)&pkUV->unk3C) = fAnimOffsetV;
    (*(float*)&pkUV->unk40) = fAnimTilingU;
    (*(float*)&pkUV->unk44) = fAnimTilingV;

    pkData->FUN_00a67090(8);
    m_bChanged = false;
}
