#include "../../../../include/NiTStringPointerMap.h"
#include <string.h>
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBlendInterpolator.h"
#include "../../../../include/NiBlendTransformInterpolator.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiInterpController.h"
#include "../../../../include/NiMultiTargetTransformController.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/NiTransformController.h"
#include "../../../../include/NiTransformInterpolator.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/NiTStringPointerMap.h"

inline void* operator new(size_t, void* pointer) throw()
{
    return pointer;
}

// These value temporaries are uninitialized in the original functions.
inline NiQuaternion::NiQuaternion() {}
inline NiQuatTransform::NiQuatTransform() {}
inline NiQuaternion& NiQuaternion::operator=(const NiQuaternion& value)
{
    memcpy(this, &value, sizeof(value));
    return *this;
}

inline bool ControllerActive(const NiTimeController* self)
{
    return (self->m_uiObjectFlags >> 3) & 1;
}
inline bool NiTimeController::GetManagerControlled() const
{
    return (m_uiObjectFlags >> 5) & 1;
}

inline bool TargetSelectiveUpdate(const NiAVObject* target)
{
    return (target->m_uFlags >> 1) & 1;
}

// @fnv 0x00a2ffe0
NiInterpolator* NiMultiTargetTransformController::GetInterpolatorAtIndex(unsigned short index)
{
    NiAVObject* source = m_ppTargetObjects[index];
    NiQuaternion rotate;
    NiQuatTransform transform;
    rotate.FromRotationMatrix(source->m_kLocal.m_Rotate);
    memcpy(&transform.x, &source->m_kLocal.m_Translate, sizeof(NiPoint3));
    *reinterpret_cast<NiQuaternion*>(&transform.qx) = rotate;
    transform.scale = source->m_kLocal.m_fScale;
    return (NiInterpolator*)::new (NiMemObject::operator new(sizeof(NiTransformInterpolator))) NiTransformInterpolator(transform);
}

// @fnv 0x00a2fd40
// src: XBOX_PDB 0x00a2fd40
char* __fastcall NiMultiTargetTransformController_GetInterpolatorID(NiMultiTargetTransformController* self, int, unsigned short usIndex)
{
    return self->m_ppTargetObjects[usIndex]->m_kName.m_kHandle;
}

void __fastcall DestroyInterpolatorArray(void* pThis);
void __cdecl FUN_00aa1460(void* ptr, unsigned int size);
void __cdecl NiMemObject_ReleaseStorage_00aa1490(void* ptr, unsigned int size);

// @fnv 0x00a2ff70
void* __fastcall FUN_00a2ff70(char* pThis, int, unsigned int flags)
{
    if (flags & 2)
    {
        int count = *(int*)(pThis - 4);
        char* base = pThis - 4;
        char* cur = pThis + count * 0x30;
        while (--count >= 0)
        {
            cur -= 0x30;
            DestroyInterpolatorArray(cur);
        }
        if (flags & 1)
        {
            NiMemObject_ReleaseStorage_00aa1490(base, 0x30);
        }
        return base;
    }
    DestroyInterpolatorArray(pThis);
    if (flags & 1)
    {
        FUN_00aa1460(pThis, 0x30);
    }
    return pThis;
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];

void __fastcall ResizeTargets(NiMultiTargetTransformController*, int, unsigned short);

void __fastcall CopyBlendMemberData(NiBlendTransformInterpolator*, int, NiBlendTransformInterpolator*, CloningProcess*);

// @fnv 0x00a30070
void __fastcall CloneTo(NiMultiTargetTransformController* self, int, NiMultiTargetTransformController* pkDest, CloningProcess* kCloning)
{
    self->NiInterpController::CopyMemberData(pkDest, *kCloning);
    reinterpret_cast<void (__thiscall*)(NiMultiTargetTransformController*, unsigned short)>(&ResizeTargets)(pkDest, self->m_usNumInterps);
    for (unsigned short us = 0; us < self->m_usNumInterps; ++us)
    {
        reinterpret_cast<void (__thiscall*)(NiBlendTransformInterpolator*, NiBlendTransformInterpolator*, CloningProcess*)>(&CopyBlendMemberData)(
            &self->m_pkBlendInterpolators[us], &pkDest->m_pkBlendInterpolators[us], kCloning);
    }
}

class ShaderBufferRecord;


// Calls the base ProcessClone, then clones each target transform interpolator and remaps its target object through the cloning process's pointer map.
// @fnv 0x00a300d0
// src: XBOX_PDB 0x00a300d0
void __fastcall NiMultiTargetTransformController_ProcessClone(NiMultiTargetTransformController* self, int, CloningProcess* kCloning)
{
    self->NiTimeController::ProcessClone(*kCloning);

    ShaderBufferRecord* pkClone = 0;
    ((NiTStringPointerMap<ShaderBufferRecord*>*)kCloning->m_pCloneMap)->GetAt((const char*)self, pkClone);
    NiMultiTargetTransformController* pkDest = (NiMultiTargetTransformController*)pkClone;

    unsigned short m_usPassCountLocal = self->m_usNumInterps;
    for (unsigned short us = 0; us < m_usPassCountLocal; us++)
    {
        self->m_pkBlendInterpolators[us].ProcessClone(*kCloning);
        if (self->m_ppTargetObjects[us] != 0)
        {
            bool bFound = ((NiTStringPointerMap<ShaderBufferRecord*>*)kCloning->m_pCloneMap)
                              ->GetAt((const char*)self->m_ppTargetObjects[us], pkClone);
            pkDest->m_ppTargetObjects[us] = bFound ? (NiAVObject*)pkClone : 0;
        }
        m_usPassCountLocal = self->m_usNumInterps;
    }
}

void __fastcall DestroyMultiTargetController(NiMultiTargetTransformController* self) throw();

// Destroys the controller and optionally frees its storage.
// @fnv 0x00a30280
void* __fastcall FUN_00a30280(void* pThis, int, unsigned int flags)
{
    DestroyMultiTargetController(static_cast<NiMultiTargetTransformController*>(pThis));
    if (flags & 1)
    {
        FUN_00aa1460(pThis, 0x40);
    }
    return pThis;
}

// @fnv 0x00a2fa30
// src: XBOX_PDB 0x00a2fa30
char* __fastcall NiMultiTargetTransformController_GetInterpolator(NiMultiTargetTransformController* self, int, unsigned short ausIndex)
{
    return reinterpret_cast<char*>(&self->m_pkBlendInterpolators[ausIndex]);
}

// @fnv 0x00a2fa50
// src: XBOX_PDB 0x00a2fa50
char* __fastcall NiMultiTargetTransformController_CreateBlendInterpolator(NiMultiTargetTransformController* self, int, unsigned short ausIndex, bool a, bool b, float c, unsigned char d)
{
    return reinterpret_cast<char*>(&self->m_pkBlendInterpolators[ausIndex]);
}

// @fnv 0x00a2fa70
// src: XBOX_PDB 0x00a2fa70
void __fastcall NiMultiTargetTransformController_GuaranteeTimeRange(NiMultiTargetTransformController* self, int, float afValueA, float afValueB)
{
    for (unsigned short us = 0; us < self->m_usNumInterps; us++)
        self->m_pkBlendInterpolators[us].SetActiveTimeRange(afValueA, afValueB);
}

extern int DAT_011f36bc;
// @fnv 0x00a2fbd0
// src: COMMUNITY 0x00a2fbd0
int* __cdecl NiMultiTargetTransformController_GetRTTI()
{
    return &DAT_011f36bc;
}

// @fnv 0x00a30240
unsigned short __fastcall FindTargetIndex(NiMultiTargetTransformController* self, int, const NiFixedString* arName)
{
    unsigned short us;
    for (us = 0; us < self->m_usNumInterps; us++)
    {
        if (self->m_ppTargetObjects[us] && self->m_ppTargetObjects[us]->m_kName.m_kHandle == arName->m_kHandle)
            return us;
    }
    return NiInterpController::INVALID_INDEX;
}

extern const NiRTTI g_targetRTTI;
// @fnv 0x00a302a0
bool __fastcall IsTargetOfType(NiTimeController* self)
{
    NiObjectNET* target = self->m_pkTarget;
    if (target)
    {
        const NiRTTI* type = target->GetRTTI();
        while (type)
        {
            if (type == &g_targetRTTI)
                return true;
            type = type->m_pBaseRTTI;
        }
    }
    return false;
}

// The shared controller has no default-construction entry point. Keep its
// original construction sequence here without duplicating its class layout.
extern void* const g_multiTargetTransformControllerVtable[];
void* __fastcall ConstructInterpController(void*) throw();
inline NiMultiTargetTransformController* ConstructMultiTargetController(void* memory) throw()
{
    NiMultiTargetTransformController* self = static_cast<NiMultiTargetTransformController*>(memory);
    ConstructInterpController(self);
    *reinterpret_cast<void* const**>(self) = g_multiTargetTransformControllerVtable;
    self->m_pkBlendInterpolators = 0;
    self->m_ppTargetObjects = 0;
    self->m_usNumInterps = 0;
    return self;
}

// @fnv 0x00a302d0
NiObject* __fastcall CloneMultiTargetController(NiMultiTargetTransformController* self, int, CloningProcess* process)
{
    void* memory = BSFadeNode::operator new(sizeof(NiMultiTargetTransformController));
    NiMultiTargetTransformController* clone = memory ? ConstructMultiTargetController(memory) : 0;
    reinterpret_cast<void (__thiscall*)(NiMultiTargetTransformController*, NiMultiTargetTransformController*, CloningProcess*)>(&CloneTo)(self, clone, process);
    return clone;
}

// @fnv 0x00a30330
NiMultiTargetTransformController* __cdecl CreateCtl()
{
    void* memory = BSFadeNode::operator new(sizeof(NiMultiTargetTransformController));
    return memory ? ConstructMultiTargetController(memory) : 0;
}

// @fnv 0x00a30370
// src: XBOX_PDB 0x00a30370
void __cdecl NiStreamLoadBinary_unsigned_short(NiStream* stream, const void* data)
{
    NiBinaryStream* binary = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(stream) + 0x24c);
    NiBinaryStream::ReadFunction transfer = reinterpret_cast<NiBinaryStream::ReadFunction*>(binary)[2];
    *reinterpret_cast<unsigned int*>(&stream) = 2;
    reinterpret_cast<unsigned int*>(binary)[1] += transfer(binary, const_cast<void*>(data), 2, reinterpret_cast<unsigned int*>(&stream), 1);
}

// @fnv 0x00a303a0
// src: XBOX_PDB 0x00a303a0
void __cdecl NiStreamSaveBinary_unsigned_short(NiStream* stream, const void* data)
{
    NiBinaryStream* binary = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(stream) + 0x250);
    NiBinaryStream::WriteFunction transfer = reinterpret_cast<NiBinaryStream::WriteFunction*>(binary)[3];
    *reinterpret_cast<unsigned int*>(&stream) = 2;
    reinterpret_cast<unsigned int*>(binary)[1] += transfer(binary, data, 2, reinterpret_cast<unsigned int*>(&stream), 1);
}

typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];

extern "C" double __cdecl fabs(double);

extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
extern float DAT_01096b8c;

// If active, iterates targets with selective update, blends each via Update, and applies non-sentinel translate, rotate and scale values.
// @fnv 0x00a2fbe0
void __fastcall UpdateTargets(NiMultiTargetTransformController* self, int, NiUpdateData* UpdateData)
{
    if (ControllerActive(self))
    {
        NiQuatTransform kTransform;
        memcpy(&kTransform.x, &DAT_011a8400, sizeof(NiPoint3));
        memcpy(&kTransform.qx, &DAT_011f3704, sizeof(NiQuaternion));
        kTransform.scale = DAT_01096b8c;
        for (int us = 0; us < self->m_usNumInterps; us++)
        {
            if (self->m_ppTargetObjects[us] &&
                TargetSelectiveUpdate(self->m_ppTargetObjects[us]))
            {
                if (self->m_pkBlendInterpolators[us].UpdateTransform(
                        UpdateData->fTime, (NiAVObject*)self->m_ppTargetObjects[us], kTransform))
                {
                    if (kTransform.x != -3.4028234663852886e+38)
                        memcpy(&self->m_ppTargetObjects[us]->m_kLocal.m_Translate, &kTransform.x, sizeof(NiPoint3));
                    if (kTransform.qy != -3.4028234663852886e+38)
                        reinterpret_cast<NiQuaternion*>(&kTransform.qx)->ToRotationMatrix(self->m_ppTargetObjects[us]->m_kLocal.m_Rotate);
                    if (kTransform.scale != -3.4028234663852886e+38)
                        self->m_ppTargetObjects[us]->m_kLocal.m_fScale = (float)fabs(kTransform.scale);
                }
            }
        }
    }
}

unsigned char __fastcall ControllersCompatible(NiMultiTargetTransformController*, int, void*);
// @fnv 0x00a2fae0
bool __fastcall EqualMultiTargetControllers(NiMultiTargetTransformController* self, int, NiMultiTargetTransformController* other)
{
    if (!reinterpret_cast<unsigned char (__thiscall*)(NiMultiTargetTransformController*, void*)>(&ControllersCompatible)(self, other))
        return false;
    if (other->m_usNumInterps != self->m_usNumInterps)
        return false;
    for (unsigned short index = 0; index < self->m_usNumInterps; index++)
    {
        if (self->m_ppTargetObjects[index] && !other->m_ppTargetObjects[index])
            return false;
        if (!self->m_ppTargetObjects[index] && other->m_ppTargetObjects[index])
            return false;
        if (self->m_ppTargetObjects[index] && !static_cast<const NiObject*>(other->m_ppTargetObjects[index])->IsEqual(self->m_ppTargetObjects[index]))
            return false;
    }
    return true;
}

extern float DAT_0109643c;
extern float DAT_01015f5c;
extern double DAT_010231b0;
extern double DAT_010241b0;

// @fnv 0x00a2fde0
void __fastcall ResetIfFlagClear(NiTimeController*);

void __fastcall UpdateTimeRange(NiMultiTargetTransformController* self)
{
    if (!self->GetManagerControlled())
    {
        self->m_fLoKeyTime = DAT_0109643c;
        self->m_fHiKeyTime = DAT_01015f5c;
        for (unsigned short index = 0; index < self->m_usNumInterps; ++index)
        {
            float endTime = DAT_01015f5c;
            float startTime = DAT_0109643c;
            static_cast<NiBlendInterpolator*>(self->m_pkBlendInterpolators)[index].GetInterpolatorTimeRange(startTime, endTime);
            if (startTime < self->m_fLoKeyTime)
                self->m_fLoKeyTime = startTime;
            if (endTime > self->m_fHiKeyTime)
                self->m_fHiKeyTime = endTime;
        }
        if (self->m_fLoKeyTime == DAT_010231b0 && self->m_fHiKeyTime == DAT_010241b0)
            ResetIfFlagClear(self);
    }
}

// Stream storage is opaque in the shared headers; retain the original inline
// callback and position access through the shared method declarations.
inline unsigned int NiBinaryStream::BinaryRead(void* data, unsigned int size, unsigned int* sizes, unsigned int count)
{
    unsigned int result = reinterpret_cast<ReadFunction*>(this)[2](this, data, size, sizes, count);
    reinterpret_cast<unsigned int*>(this)[1] += result;
    return result;
}
inline unsigned int NiBinaryStream::BinaryWrite(const void* data, unsigned int size, unsigned int* sizes, unsigned int count)
{
    unsigned int result = reinterpret_cast<WriteFunction*>(this)[3](this, data, size, sizes, count);
    reinterpret_cast<unsigned int*>(this)[1] += result;
    return result;
}
inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

template <class T>
inline void NiBinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void WriteBinaryValue(NiStream& kStream, const T& value)
{
    NiBinaryStreamSave(*kStream.GetBinaryStream(), &value);
}

// SaveBinary
// Saves the base controller, the target count, then each target's link ID to the stream.
// @fnv 0x00a30440
void __fastcall SaveMultiTargetBinary(NiMultiTargetTransformController* self, int, NiStream& kStream)
{
    self->NiObject::SaveBinary(kStream);
    WriteBinaryValue(kStream, self->m_usNumInterps);
    for (unsigned short us = 0; us < self->m_usNumInterps; us++)
        kStream.SaveLinkID(reinterpret_cast<const NiObject*>(self->m_ppTargetObjects[us]));
}

struct FUN_00a304b0_arr
{
    char pad00[8];
    unsigned short m_usCapacity;
    unsigned short m_usElementCount;
    unsigned short m_usPad0c;
    unsigned short m_usGrow;

    void FUN_0096ad30(unsigned int ItemUpdateArray);
    void FUN_0096ae90(unsigned int uiIndex, void** ppItem);
};

void* __cdecl NiViewerStrings_NiGetViewerString_Title(int);
void* __cdecl NiGetViewerString_00a7d490(const char*, unsigned short);
extern int DAT_011f36bc;

void __fastcall WriteManagerControlledFlag(NiMultiTargetTransformController*, int, FUN_00a304b0_arr*);

// @fnv 0x00a304b0
void __fastcall GetMultiTargetViewerStrings(NiMultiTargetTransformController* self, int, FUN_00a304b0_arr* pArr)
{
    reinterpret_cast<void (__thiscall*)(NiMultiTargetTransformController*, FUN_00a304b0_arr*)>(&WriteManagerControlledFlag)(self, pArr);
    void* pItem = NiViewerStrings_NiGetViewerString_Title(DAT_011f36bc);
    unsigned int usIndex = pArr->m_usElementCount;
    if (usIndex >= pArr->m_usCapacity)
    {
        pArr->FUN_0096ad30(usIndex + pArr->m_usGrow);
    }
    pArr->FUN_0096ae90(usIndex, &pItem);

    pItem = NiGetViewerString_00a7d490("m_usNumInterps", self->m_usNumInterps);
    usIndex = pArr->m_usElementCount;
    if (usIndex >= pArr->m_usCapacity)
    {
        pArr->FUN_0096ad30(usIndex + pArr->m_usGrow);
    }
    pArr->FUN_0096ae90(usIndex, &pItem);
}

extern "C" int __cdecl strcmp(const char* pcA, const char* pcB);

// @fnv 0x00a2fd60
unsigned short __fastcall FindItemIndexByName(const NiMultiTargetTransformController* self, int, const char* name)
{
    if (!name)
        return NiInterpController::INVALID_INDEX;
    for (unsigned short index = 0; index < self->m_usNumInterps; index++)
    {
        if (self->m_ppTargetObjects[index] && strcmp(self->m_ppTargetObjects[index]->m_kName.m_kHandle, name) == 0)
            return index;
    }
    return NiInterpController::INVALID_INDEX;
}

// @fnv 0x00a2fa20
unsigned short __fastcall GetMultiTargetCount(const NiMultiTargetTransformController* self)
{
    return self->m_usNumInterps;
}

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* pkStream, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiComponentSize = sizeof(T);
    pkStream->BinaryRead(pValue, uiNumEls * uiComponentSize, &uiComponentSize, 1);
}
inline void ReadBinaryValue(NiStream& kStream, unsigned short& usValue)
{
    NiBinaryStreamLoad(&kStream.Istr(), &usValue, 1);
}

// Calls FUN_00a2f910, reads m_usNumInterps, passes it to FUN_00a2feb0, then assigns returned pointers to m_ppTargetObjects.
// @fnv 0x00a303d0
void __fastcall LoadMultiTargetBinary(NiMultiTargetTransformController* self, int, NiStream& kStream)
{
    self->NiInterpController::LoadBinary(kStream);
    ReadBinaryValue(kStream, self->m_usNumInterps);
    reinterpret_cast<void (__thiscall*)(NiMultiTargetTransformController*, unsigned short)>(&ResizeTargets)(self, self->m_usNumInterps);
    for (unsigned short us = 0; us < self->m_usNumInterps; us++)
        self->m_ppTargetObjects[us] = reinterpret_cast<NiAVObject*>(kStream.DeserializeObject());
}

extern MemoryManager g_memoryManager;
void NiFree(void*);
inline void operator delete(void* p)
{
    g_memoryManager.Deallocate(p);
}
void __fastcall DestroyControllerBase(NiTimeController*) throw();
// @fnv 0x00a2fb70
void __fastcall DestroyMultiTargetController(NiMultiTargetTransformController* self) throw()
{
    *reinterpret_cast<void* const**>(self) = g_multiTargetTransformControllerVtable;
    delete[] self->m_pkBlendInterpolators;
    NiFree(self->m_ppTargetObjects);
    DestroyControllerBase(self);
}
