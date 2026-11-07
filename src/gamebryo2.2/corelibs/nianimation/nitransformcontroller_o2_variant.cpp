
// src/gamebryo2.2/corelibs/nianimation/nitransformcontroller_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nianimation/nitransformcontroller.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/StrArr.h"
#define FNV_V4_UNALIGNED
#include "../../../../include/V4.h"
#include <string.h>

// The generated animation headers must use the shared base and container types.
#define FNV_LAYOUT_SUPPORT_H
#define FNV_NIOBJECT_H
#define FNV_NIOBJECTNET_H
#define FNV_NIPOINT3_H
#define FNV_NIFIXEDSTRING_H
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
template <class K, class V> class NiTPointerMap;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

#include "nitransformcontroller_nimemobject_decl.h"
#include "nitransformcontroller_types_NiCloningProcess.h"
#include "nitransformcontroller_types_NiBoolInterpController.h"
#include "nitransformcontroller_types_NiTransformInterpolator.h"
#include "nitransformcontroller_types_NiControllerSequence__IDTag.h"
#include "nitransformcontroller_stream_decl.h"

// Preserve the generated animation code's inline reference-count operations.
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

struct RefObj
{
    virtual void vf0();
    virtual void vf4();
    volatile long refCount;
};
void __fastcall FUN_00a6d290(void*);
struct Unknown
{
    void ReleaseReference_00a360d0();
};
// @fnv 0x00a360d0
// src: GUESS 0x00a360d0 (confidence: medium)
void Unknown::ReleaseReference_00a360d0()
{
    RefObj* p = *(RefObj**)((char*)this + 0x34);
    if (p)
    {
        if (InterlockedDecrement(&p->refCount) == 0)
            p->vf4();
    }
    FUN_00a6d290(this);
}

struct FakeTransformController : NiSingleInterpController
{
    void NiTransformController_LoadBinary(NiStream&);
};
// @fnv 0x00a36190
// src: XBOX_PDB 0x00a36190
void FakeTransformController::NiTransformController_LoadBinary(NiStream& kStream)
{
    NiSingleInterpController::LoadBinary(kStream);
    if (*(unsigned int*)((char*)&kStream + 0xD8) < 0x0A010068)
        kStream.ResetStreamState();
}

extern int g_011f371c;

// @fnv 0x00a36480
// src: COMMUNITY 0x00a36480
int* __cdecl NiBlendAccumTransformInterpolator_GetRTTI()
{
    return &g_011f371c;
}

void __fastcall NiBlendAccumTransformInterpolator_ReleaseStorage_00a39290(void*);
void __cdecl _delete(void*, unsigned int);
struct S_00a36490
{
    void* __thiscall FUN_00a36490(unsigned int);
};
// @fnv 0x00a36490
void* __thiscall S_00a36490::FUN_00a36490(unsigned int flag)
{
    NiBlendAccumTransformInterpolator_ReleaseStorage_00a39290(this);
    if (flag & 1)
        _delete(this, 0x58);
    return this;
}

extern "C" void* g_011f36ec;

// @fnv 0x00a36580
// src: COMMUNITY 0x00a36580
void* __cdecl NiTransformController_GetRTTI()
{
    return &g_011f36ec;
}

namespace fnv_00a36840 {
void __stdcall FUN_00a390a0(StrArr*);
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
extern const char* g_011f36ec;
// @fnv 0x00a36840
// src: XBOX_PDB 0x00a36840
void __stdcall NiTransformController_GetViewerStrings(StrArr* pkStrings)
{
    FUN_00a390a0(pkStrings);
    char* pszString = NiViewerStrings_NiGetViewerString_Title(g_011f36ec);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pszString);
}
}  // namespace fnv_00a36840

// NiQuatTransform parts copied as plain words, as the POD assignments of the original do.
struct Point3Words
{
    unsigned int w[3];
};
struct QuatWords
{
    unsigned int w[4];
};
__forceinline NiQuaternion::NiQuaternion()
{}
__forceinline NiQuatTransform::NiQuatTransform()
{}
struct S00a36100
{
    char _pad[0x2c];
    NiAVObject* m_spReferencedObject;

    NiTransformInterpolator* NiTransformController_CreatePoseInterpolator(unsigned short usIndex);
};

// @fnv 0x00a36100
// src: XBOX_PDB 0x00a36100
NiTransformInterpolator* S00a36100::NiTransformController_CreatePoseInterpolator(unsigned short usIndex)
{
    NiAVObject* pkTarget = m_spReferencedObject;
    NiQuaternion kRotate;
    kRotate.FromRotationMatrix(pkTarget->m_kLocal.m_Rotate);
    NiQuatTransform kTransform;
    kTransform.scale = pkTarget->m_kLocal.m_fScale;
    *reinterpret_cast<Point3Words*>(&kTransform.x) = *reinterpret_cast<const Point3Words*>(&pkTarget->m_kLocal.m_Translate);
    *reinterpret_cast<QuatWords*>(&kTransform.qx) = *reinterpret_cast<const QuatWords*>(&kRotate);

    return new NiTransformInterpolator(kTransform);
}

struct FUN_00a2f8a0_Holder
{
    void BSMultiTargetTreadTransfController_CopyMembers(NiInterpController* pkDest, CloningProcess& kCloning);
};

struct FUN_00a38ef0_Class : NiInterpController
{
    NiInterpolator* m_spControllerInterpolator;
    void NiSingleInterpController_CopyMembers(FUN_00a38ef0_Class* pkDest, CloningProcess& kCloning);
};

// @fnv 0x00a38ef0
// src: GAMEBRYO_LIB 0x00a38ef0
void FUN_00a38ef0_Class::NiSingleInterpController_CopyMembers(FUN_00a38ef0_Class* pkDest, CloningProcess& kCloning)
{
    ((FUN_00a2f8a0_Holder*)this)->BSMultiTargetTreadTransfController_CopyMembers(pkDest, kCloning);

    if (m_spControllerInterpolator != 0)
    {
        NiInterpolator* pkNew = (NiInterpolator*)&((NiControllerSequence__IDTag*)m_spControllerInterpolator)
                                    ->
                                    operator=(*(const NiControllerSequence__IDTag*)&kCloning);
        NiInterpolator* pkOld = pkDest->m_spControllerInterpolator;
        if (pkOld != pkNew)
        {
            if (pkOld != 0)
                pkOld->NiRefObject::DecRefCount();
            pkDest->m_spControllerInterpolator = pkNew;
            if (pkNew != 0)
                pkNew->NiRefObject::IncRefCount();
        }
    }
}

extern int DAT_0109687c;
struct NiTimeController_Call
{
    void SetControllerActive();
};
struct S_00a36560
{
    void* NiTransformController_NiTransformController();
};
// @fnv 0x00a36560
// src: EXE 0x00a36560
void* S_00a36560::NiTransformController_NiTransformController()
{
    ((NiTimeController_Call*)this)->SetControllerActive();
    *(void**)this = &DAT_0109687c;
    return this;
}

extern int DAT_01096694;
struct NiSingleInterpControllerBase
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
    NiSingleInterpControllerBase();
};
struct FUN_00a35a80_Obj
{
    void BSMultiTargetTreadTransfController_AllocateStorage(int a1, int a2);
};
struct FUN_00a36070 : NiSingleInterpControllerBase
{
    void* m_spControllerInterpolator;
    unsigned short unk38;
    int unk3c;
    unsigned short unk40;
    FUN_00a36070(int a1, int a2);
};
// @fnv 0x00a36070
FUN_00a36070::FUN_00a36070(int a1, int a2)
{
    m_spControllerInterpolator = 0;
    unk38 = 0;
    unk3c = 0;
    *(int**)this = &DAT_01096694;
    unk40 = 0;
    ((FUN_00a35a80_Obj*)this)->BSMultiTargetTreadTransfController_AllocateStorage(a1, a2);
}

extern double DAT_010241b0;
extern "C" void _ReadWriteBarrier(void);

struct Tgt
{
    void FUN_00a4e2e0(unsigned int a, unsigned int b, unsigned int c);
    void FUN_00a4e3b0(unsigned int a, unsigned int b, unsigned int c);
    void FUN_00a4e350(unsigned int a, unsigned int b, unsigned int c);
};

struct V3
{
    float f0;
    float f1;
    float f2;
};

struct FUN_00a364b0_cls
{
    virtual void vf00();
    unsigned int unk04;
    unsigned int unk08;
    V3 m_t;
    V4 m_r;
    float unk28;
    Tgt* unk2c;

    void NiTransformInterpolator_SetPoseValue(V3 aT0, V4 aR0, float fScale);
};

// @fnv 0x00a364b0
// src: XBOX_PDB 0x00a364b0
void FUN_00a364b0_cls::NiTransformInterpolator_SetPoseValue(V3 aT0, V4 aR0, float fScale)
{
    if (aR0.f1 != DAT_010241b0)
    {
        memcpy(&m_r, &aR0, sizeof(m_r));
        _ReadWriteBarrier();
        if (unk2c)
            unk2c->FUN_00a4e2e0(0, 0, 0);
    }
    if (fScale != DAT_010241b0)
    {
        unk28 = fScale;
        if (unk2c)
            unk2c->FUN_00a4e3b0(0, 0, 0);
    }
    if (aT0.f0 != DAT_010241b0)
    {
        m_t = aT0;
        _ReadWriteBarrier();
        if (unk2c)
            unk2c->FUN_00a4e350(0, 0, 0);
    }
}

// Apply the source object's local transform (as a quaternion transform) to the given node.

class A36590RTTI;
extern const A36590RTTI g_kA36590NodeRTTI;

struct A36590Point3
{
    float x;
    float y;
    float z;
};

struct A36590Matrix3
{
    float m_pEntry00;
    float m_pEntry01;
    float m_pEntry02;
    float m_pEntry10;
    float m_pEntry11;
    float m_pEntry12;
    float m_pEntry20;
    float m_pEntry21;
    float m_pEntry22;
};

// local form of NiQuaternion: 0x00a36590 needs the local ctor/assignment split; the shared form changes bytes.
struct A36590Quaternion
{
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    void FromRotationMatrix(const A36590Matrix3& kRot);
};

struct A36590QuatTransform
{
    A36590Point3 m_kTranslate;
    A36590Quaternion m_kRotate;
    float m_fScale;
};

class A36590Object
{
  public:
    A36590Object* DynamicCast(const A36590RTTI* pkRTTI);
};

class A36590Node : public A36590Object
{
  public:
    void SetTargetTransform(A36590QuatTransform kTransform);
};

class A36590Controller
{
  public:
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
    NiAVObject* m_pkSource;

    void NiTransformController_SynchronizePoseInterpolator(A36590Object* pkObject, int iUnused);
};

// @fnv 0x00a36590
// src: XBOX_PDB 0x00a36590
void A36590Controller::NiTransformController_SynchronizePoseInterpolator(A36590Object* pkObject, int iUnused)
{
    A36590Node* pkNode = !pkObject ? 0 : (A36590Node*)pkObject->DynamicCast(&g_kA36590NodeRTTI);
    NiAVObject* pkSource = m_pkSource;

    A36590Quaternion kRotate;
    kRotate.FromRotationMatrix(reinterpret_cast<const A36590Matrix3&>(pkSource->m_kLocal.m_Rotate));

    A36590QuatTransform kTransform;
    kTransform.m_kTranslate = reinterpret_cast<const A36590Point3&>(pkSource->m_kLocal.m_Translate);
    kTransform.m_kRotate = kRotate;
    kTransform.m_fScale = pkSource->m_kLocal.m_fScale;
    pkNode->SetTargetTransform(kTransform);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);

class NiTransformInitA
{
  public:
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
    void* InitA(int a, float b, int c);
};

class NiTransformInitB
{
  public:
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
    void* InitB(int a, float b, int c);
};

// @fnv 0x00a36620
// src: XBOX_PDB 0x00a36620
void* __stdcall NiTransformController_CreateBlendInterpolator(int a1, int a2, unsigned char a3, float a4, int a5)
{
    void* obj;
    if (a3 != 0)
    {
        obj = NiTransformInitA::operator new(0x58);
        if (obj != 0)
        {
            return ((NiTransformInitA*)obj)->InitA(a2, a4, a5);
        }
    }
    else
    {
        obj = NiTransformInitB::operator new(0x30);
        if (obj != 0)
        {
            return ((NiTransformInitB*)obj)->InitB(a2, a4, a5);
        }
    }
    return 0;
}

#include <math.h>
struct Interp_00a36680
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
    virtual bool Update(float, void*, void*);
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
    virtual bool AlwaysUpdate();
};
struct UpdData_00a36680
{
    float fTime;
};
struct QuatXf_00a36680
{
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
};
extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
extern float DAT_01096b8c;
extern const float DAT_01096324;
struct Flags_00a36680
{
    bool b0 : 1;
    bool b1 : 1;
    bool b2 : 1;
    bool b3 : 1;
    bool b4 : 1;
    bool bManager : 1;
};

struct TransformCtl_t : NiTimeController
{
    void NiTransformController_Update(UpdData_00a36680&);
    unsigned short GetField(unsigned short uMask, unsigned short uPos) const
    {
        return (*(const unsigned short*)((const char*)this + 8) & uMask) >> uPos;
    }
    bool GetManagerControlled() const
    {
        return (bool)GetField(0x20, 5);
    }
};

// @fnv 0x00a36680
// src: XBOX_PDB 0x00a36680
void TransformCtl_t::NiTransformController_Update(UpdData_00a36680& UpdateData)
{
    Interp_00a36680*& spInterp = *(Interp_00a36680**)((char*)this + 0x34);
    if (GetManagerControlled())
    {
        *(float*)((char*)this + 0x28) = DAT_01096324;
    }
    else if (AdvanceController(UpdateData.fTime) && (!spInterp || !spInterp->AlwaysUpdate()))
    {
        return;
    }
    if (spInterp)
    {
        QuatXf_00a36680 kTransform;
        kTransform.m_kTranslate = DAT_011a8400;
        *reinterpret_cast<QuatWords*>(&kTransform.m_kRotate) = *reinterpret_cast<const QuatWords*>(&DAT_011f3704);
        kTransform.m_fScale = DAT_01096b8c;
        if (spInterp->Update(*(float*)((char*)this + 0x28), *(void**)((char*)this + 0x2c), &kTransform))
        {
            NiAVObject* pkTarget = *(NiAVObject**)((char*)this + 0x2c);
            if (kTransform.m_kTranslate.x != -3.4028234663852886e+38)
                pkTarget->m_kLocal.m_Translate = kTransform.m_kTranslate;
            if (kTransform.m_kRotate.m_fVectorY != -3.4028234663852886e+38)
                kTransform.m_kRotate.ToRotationMatrix(pkTarget->m_kLocal.m_Rotate);
            if (kTransform.m_fScale != -3.4028234663852886e+38)
                pkTarget->m_kLocal.m_fScale = fabs(kTransform.m_fScale);
        }
    }
}
