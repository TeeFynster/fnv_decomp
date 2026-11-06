// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPSYSEMITTERCTLR_H
#define FNV_NIPSYSEMITTERCTLR_H

#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObject.h"
#include "NiObjectNET.h"
#include "layout_support.h"
class NiInterpController;
class NiInterpolator;
class NiFloatData;
class CloningProcess;
class NiStream;
class NiPSysEmitterCtlr;
class NiPSysModifier;
class NiPSysModifierCtlr;
class NiSingleInterpController;
class NiTPrimitiveSet_float_;
class NiTSet_float_NiTMallocInterface_float___;
#pragma pack(push, 4)
class NiTimeController : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    unsigned short m_uiObjectFlags;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    float m_fFrequency;                              // +0xC, 4 bytes
    float m_fPhase;                                  // +0x10, 4 bytes
    float m_fLoKeyTime;                              // +0x14, 4 bytes
    float m_fHiKeyTime;                              // +0x18, 4 bytes
    float m_fStartTime;                              // +0x1C, 4 bytes
    float m_fLastTime;                               // +0x20, 4 bytes
    float m_fWeightAdjustedLastTime;                 // +0x24, 4 bytes
    float m_fControllerTime;                         // +0x28, 4 bytes
    NiObjectNET* m_pkTarget;                         // +0x2C, 4 bytes
    NiPointer<NiTimeController> m_spNextController;  // +0x30, 4 bytes
    // const NiRTTI* __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController*, CloningProcess&)
    // void __cdecl NiTimeController::*(NiStream&)
    // void __cdecl NiTimeController::*(NiStream&)
    // bool __cdecl NiTimeController::*(NiStream&)
    // void __cdecl NiTimeController::*(NiStream&)
    // bool __cdecl NiTimeController::*(NiObject*)
    // void __cdecl NiTimeController::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiTimeController::*(unsigned short, unsigned short, unsigned short)
    // unsigned short __cdecl NiTimeController::*(unsigned short, unsigned short)
    // void __cdecl NiTimeController::*(bool, unsigned short)
    // bool __cdecl NiTimeController::*(unsigned short)
    // NiTimeController
    // void __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController::AnimType)
    // NiTimeController::AnimType __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController::CycleType)
    // NiTimeController::CycleType __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // NiObjectNET* __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiObjectNET*)
    // unsigned int __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController*)
    // NiTimeController* __cdecl NiTimeController::*()
    // float __cdecl NiTimeController::*()
    // bool __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController*)
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(CloningProcess&)
    // void __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // NiTimeController& __cdecl NiTimeController::*(const NiTimeController&)
    // void __cdecl NiTimeController::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTimeController) == 52);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_uiObjectFlags) == 8);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fFrequency) == 12);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fPhase) == 16);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fLoKeyTime) == 20);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fHiKeyTime) == 24);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fStartTime) == 28);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fLastTime) == 32);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fWeightAdjustedLastTime) == 36);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fControllerTime) == 40);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_pkTarget) == 44);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_spNextController) == 48);
#pragma pack(push, 4)
class NiInterpController : public NiTimeController
{
  public:
    // base NiTimeController at +0x0, size 52
    // const NiRTTI* __cdecl NiInterpController::*()
    // void __cdecl NiInterpController::*(NiInterpController*, CloningProcess&)
    // void __cdecl NiInterpController::*(NiStream&)
    // void __cdecl NiInterpController::*(NiStream&)
    // bool __cdecl NiInterpController::*(NiStream&)
    // void __cdecl NiInterpController::*(NiStream&)
    // bool __cdecl NiInterpController::*(NiObject*)
    // void __cdecl NiInterpController::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiInterpController::*(NiUpdateData&)
    // bool __cdecl NiInterpController::*()
    // void __cdecl NiInterpController::*(bool)
    // NiInterpController
    // void __cdecl NiInterpController::*()
    // NiInterpController& __cdecl NiInterpController::*(const NiInterpController&)
    // void __cdecl NiInterpController::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiInterpController) == 52);
#pragma pack(push, 4)
class NiSingleInterpController : public NiInterpController
{
  public:
    // base NiInterpController at +0x0, size 52
    NiPointer<NiInterpolator> m_spControllerInterpolator;  // +0x34, 4 bytes
    // const NiRTTI* __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*(NiSingleInterpController*, CloningProcess&)
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // bool __cdecl NiSingleInterpController::*(NiStream&)
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // bool __cdecl NiSingleInterpController::*(NiObject*)
    // void __cdecl NiSingleInterpController::*(NiTPrimitiveArray<char *>*)
    // unsigned short __cdecl NiSingleInterpController::*()
    // const char* __cdecl NiSingleInterpController::*(unsigned short)
    // unsigned short __cdecl NiSingleInterpController::*(const char*)
    // unsigned short __cdecl NiSingleInterpController::*(const NiFixedString&)
    // NiInterpolator* __cdecl NiSingleInterpController::*(unsigned short)
    // void __cdecl NiSingleInterpController::*(NiInterpolator*, unsigned short)
    // void __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*(float, float)
    // void __cdecl NiSingleInterpController::*(CloningProcess&)
    // NiSingleInterpController
    // bool __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*()
    // NiSingleInterpController& __cdecl NiSingleInterpController::*(const NiSingleInterpController&)
    // void __cdecl NiSingleInterpController::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiSingleInterpController) == 56);
FNV_STATIC_ASSERT(offsetof(NiSingleInterpController, m_spControllerInterpolator) == 52);
#pragma pack(push, 4)
class NiPSysModifierCtlr : public NiSingleInterpController
{
  public:
    // base NiSingleInterpController at +0x0, size 56
    NiFixedString m_kTargetModifierName;  // +0x38, 4 bytes
    NiPSysModifier* m_pkTargetModifier;   // +0x3C, 4 bytes
    void LoadBinary(NiStream& stream);
    void LinkObject(NiStream& stream);
    void ProcessClone(CloningProcess& process);
    void CopyMemberData(NiPSysModifierCtlr* destination, CloningProcess& process);
    // const NiRTTI* __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(NiPSysModifierCtlr*, CloningProcess&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // bool __cdecl NiPSysModifierCtlr::*(NiStream&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // bool __cdecl NiPSysModifierCtlr::*(NiObject*)
    // void __cdecl NiPSysModifierCtlr::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(NiObjectNET*)
    // const NiFixedString& __cdecl NiPSysModifierCtlr::*()
    // NiPSysModifier* __cdecl NiPSysModifierCtlr::*()
    // const char* __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(CloningProcess&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // NiPSysModifierCtlr
    // bool __cdecl NiPSysModifierCtlr::*(NiObjectNET*)
    // void __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(const NiFixedString&)
    // NiPSysModifierCtlr& __cdecl NiPSysModifierCtlr::*(const NiPSysModifierCtlr&)
    // void __cdecl NiPSysModifierCtlr::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysModifierCtlr) == 64);
FNV_STATIC_ASSERT(offsetof(NiPSysModifierCtlr, m_kTargetModifierName) == 56);
FNV_STATIC_ASSERT(offsetof(NiPSysModifierCtlr, m_pkTargetModifier) == 60);
#pragma pack(push, 4)
class NiPSysModifierBoolCtlr : public NiPSysModifierCtlr
{
  public:
    NiPSysModifierBoolCtlr() throw();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysModifierBoolCtlr) == 64);

class NiInterpolator : public NiObject
{
  public:
    // slots 0x08-0x64 are the shared NiObject virtuals (Clone is NiObject::MakeClone, 0x48)
    virtual void ProcessClone(CloningProcess& process);
};

class NiFloatInterpolator : public NiInterpolator
{
  public:
    NiFloatInterpolator(NiFloatData* data) throw();
    void SetAnimationKeys(void* keys, unsigned int count, unsigned int keyType);
};

class NiBoolInterpolator : public NiInterpolator
{
  public:
    NiBoolInterpolator(void* data) throw();
    void SetAnimationKeys(void* keys, unsigned int keyType, unsigned int count);
};

class NiBoolInterpController : public NiInterpolator
{
  public:
    NiBoolInterpolator* LinkObject(NiStream* stream);
};

#pragma pack(push, 4)
class NiTSet_float_NiTMallocInterface_float___
{
  public:
    float* m_pBase;                      // +0x0, 4 bytes
    unsigned int m_uiElementCount;       // +0x4, 4 bytes
    unsigned int m_uiAllocatedCapacity;  // +0x8, 4 bytes
    // NiTSet<float,NiTMallocInterface<float> >
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // unsigned int __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // float* __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // GetAt
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int)
    // bool __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // bool __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int, const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // Realloc
    // int __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // NiTSet<float,NiTMallocInterface<float> >& __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const NiTSet<float,NiTMallocInterface<float> >&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // void* __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTSet_float_NiTMallocInterface_float___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTSet_float_NiTMallocInterface_float___, m_pBase) == 0);
FNV_STATIC_ASSERT(offsetof(NiTSet_float_NiTMallocInterface_float___, m_uiElementCount) == 4);
FNV_STATIC_ASSERT(offsetof(NiTSet_float_NiTMallocInterface_float___, m_uiAllocatedCapacity) == 8);
#pragma pack(push, 4)
class NiTPrimitiveSet_float_ : public NiTSet_float_NiTMallocInterface_float___
{
  public:
    // base NiTSet<float,NiTMallocInterface<float> > at +0x0, size 12
    // NiTPrimitiveSet<float>
    // void __cdecl NiTPrimitiveSet<float>::*()
    // NiTPrimitiveSet<float>& __cdecl NiTPrimitiveSet<float>::*(const NiTPrimitiveSet<float>&)
    // void __cdecl NiTPrimitiveSet<float>::*()
    // void* __cdecl NiTPrimitiveSet<float>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveSet_float_) == 12);
#pragma pack(push, 4)
class NiPSysEmitterCtlr : public NiPSysModifierCtlr
{
  public:
    static void* operator new(unsigned int size);
    // base NiPSysModifierCtlr at +0x0, size 64
    NiPointer<NiInterpolator> m_spVisibilityInterpolator;  // +0x40, 4 bytes
    NiInterpolator* m_pEmitterActiveInterpolator;          // +0x44, 4 bytes
    float m_fScaledLastTime;                               // +0x48, 4 bytes
    bool m_bIsInitialized;                                 // +0x4C, 1 bytes
    unsigned char layoutPadding4D[3];
    NiTPrimitiveSet_float_ m_kBirthRateKeys;  // +0x50, 12 bytes
    void LoadBinary(NiStream& stream);
    void LinkObject(NiStream& stream);
    void ProcessClone(CloningProcess& process);
    void CopyMemberData(NiPSysEmitterCtlr* destination, CloningProcess& process);
    NiObject* MakeClone(CloningProcess& process);
    // slots 0x08-0x88 are the shared NiObject virtuals
    virtual void vfn_8C();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9C();
    virtual void vfn_A0();
    virtual void vfn_A4();
    virtual void vfn_A8();
    virtual void vfn_AC();
    virtual void vfn_B0();
    virtual void vfn_B4();
    virtual void vfn_B8();
    virtual void vfn_BC();
    virtual void vfn_C0();
    virtual void vfn_C4();
    virtual void SetInterpolator(NiInterpolator* interpolator, unsigned int index);
    // const NiRTTI* __cdecl NiPSysEmitterCtlr::*()
    // NiObject* __cdecl NiPSysEmitterCtlr::*(CloningProcess&)
    // void __cdecl NiPSysEmitterCtlr::*(NiPSysEmitterCtlr*, CloningProcess&)
    // void __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // void __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // bool __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // void __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // bool __cdecl NiPSysEmitterCtlr::*(NiObject*)
    // NiObject* __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(NiTPrimitiveArray<char *>*)
    // NiPSysEmitterCtlr
    // void __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(NiUpdateData&)
    // NiFloatInterpolator* __cdecl NiPSysEmitterCtlr::*()
    // NiBoolInterpolator* __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(NiFloatInterpolator*)
    // void __cdecl NiPSysEmitterCtlr::*(NiBoolInterpolator*)
    // void __cdecl NiPSysEmitterCtlr::*(float, float)
    // void __cdecl NiPSysEmitterCtlr::*()
    // unsigned short __cdecl NiPSysEmitterCtlr::*()
    // const char* __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // unsigned short __cdecl NiPSysEmitterCtlr::*(const char*)
    // NiInterpolator* __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // void __cdecl NiPSysEmitterCtlr::*(NiInterpolator*, unsigned short)
    // NiInterpolator* __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // void __cdecl NiPSysEmitterCtlr::*(NiInterpolator*, unsigned short)
    // NiBlendInterpolator* __cdecl NiPSysEmitterCtlr::*(unsigned short, bool, bool, float, unsigned char)
    // void __cdecl NiPSysEmitterCtlr::*(CloningProcess&)
    // unsigned short __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // bool __cdecl NiPSysEmitterCtlr::*(NiInterpolator*, unsigned short)
    // bool __cdecl NiPSysEmitterCtlr::*(NiObjectNET*)
    // bool __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(float, float, float, float, float, float)
    // void __cdecl NiPSysEmitterCtlr::*()
    // NiPSysEmitterCtlr& __cdecl NiPSysEmitterCtlr::*(const NiPSysEmitterCtlr&)
    // void __cdecl NiPSysEmitterCtlr::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysEmitterCtlr) == 92);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitterCtlr, m_spVisibilityInterpolator) == 64);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitterCtlr, m_pEmitterActiveInterpolator) == 68);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitterCtlr, m_fScaledLastTime) == 72);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitterCtlr, m_bIsInitialized) == 76);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitterCtlr, m_kBirthRateKeys) == 80);
#endif
