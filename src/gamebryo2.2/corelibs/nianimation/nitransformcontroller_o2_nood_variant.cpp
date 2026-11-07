
// src/gamebryo2.2/corelibs/nianimation/nitransformcontroller_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nianimation/nitransformcontroller.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// The NiPointer assignment in 0x00a361c0 is inlined (Gamebryo NiSmartPointer.inl bodies).
#define FNV64_NIPOINTER_INLINE_BODIES
#include "NiRefObject_inline.h"

#include "nitransformcontroller_nimemobject_decl.h"
#include "nitransformcontroller_types_NiCloningProcess.h"
#include "nitransformcontroller_types_NiBoolInterpController.h"
#include "nitransformcontroller_types_NiTransformInterpolator.h"
#include "nitransformcontroller_types_NiControllerSequence__IDTag.h"
#include "nitransformcontroller_stream_decl.h"
// NiInterpolator re-declares the reference-count helpers; they are NiRefObject's inline bodies.
__forceinline void NiInterpolator::IncRefCount()
{
    NiRefObject::IncRefCount();
}
__forceinline void NiInterpolator::DecRefCount()
{
    NiRefObject::DecRefCount();
}

struct FUN_00a38e00 : NiSingleInterpController
{
    FUN_00a38e00() throw();
};

class ObjectA36810 : public FUN_00a38e00
{
  public:
    virtual void Dummy();
};

// @fnv 0x00a36810
// src: EXE 0x00a36810
NiObject* __cdecl NiTransformController_CreateObject()
{
    return new ObjectA36810;
}

// FUN_00a360b0 - forwards its single argument to a helper and reports the
// helper's byte sized result as a bool.

extern "C" unsigned char __stdcall Helper00a39030(void* pObject);

// @fnv 0x00a360b0
// src: XBOX_PDB 0x00a360b0
bool __stdcall NiTransformController_IsEqual(void* pObject)
{
    return Helper00a39030(pObject);
}

class NiTransformData;

// Constructor NiTransformInterpolator::NiTransformInterpolator(NiTransformData*)
struct NiTransformInterpolatorMem
{
    NiTransformInterpolator* FUN_00a3fa30(NiTransformData* pkData);
};

// NiInterpolator virtual table up to Collapse (slot 47)
struct NiInterpolatorVirtuals
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Collapse();
};

struct FUN_00a361c0_cls : public NiSingleInterpController
{
    void NiTransformController_LinkObject(NiStream& kStream);
};

// @fnv 0x00a361c0
// src: XBOX_PDB 0x00a361c0
void FUN_00a361c0_cls::NiTransformController_LinkObject(NiStream& kStream)
{
    NiSingleInterpController::LinkObject(kStream);

    unsigned int uiFileVersion = *(unsigned int*)((char*)&kStream + 0xd8);
    if (uiFileVersion < 0x0a010068)
    {
        NiTransformData* pkData = (NiTransformData*)kStream.GetLoadedObject();
        void* pMem = NiMemObject::operator new(0x48);
        m_spControllerInterpolator = pMem ? ((NiTransformInterpolatorMem*)pMem)->FUN_00a3fa30(pkData) : 0;
        ((NiInterpolatorVirtuals*)m_spControllerInterpolator.m_pObject)->Collapse();
    }
}

struct FUN_00a367c0_helper
{
    void NiSingleInterpController_CopyMembers(ObjectA36810* pkClone, CloningProcess& cloning);
};

// @fnv 0x00a367c0
// src: XBOX_PDB 0x00a367c0
ObjectA36810* __fastcall NiTransformController_CreateClone(ObjectA36810* pThis, void*, CloningProcess& cloning)
{
    ObjectA36810* pNewInstance = new ObjectA36810;
    ((FUN_00a367c0_helper*)pThis)->NiSingleInterpController_CopyMembers(pNewInstance, cloning);
    return pNewInstance;
}
