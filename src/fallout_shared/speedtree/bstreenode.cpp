#include "../../../include/BSTreeNode.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/BGSBodyPart.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/bhkCapsuleShape.h"
#include "../../../include/NiObject.h"
#include "../../../include/NiProperty.h"
#include "../../../include/NiRTTI.h"
#include "../../../include/bhkCollisionObject.h"
#include "../../../include/bhkTransformShape.h"
#include "../../../include/NiAlphaProperty.h"

// src/fallout_shared/speedtree/bstreenode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/speedtree/bstreenode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00622430_shell
{
    unsigned int __thiscall bhkTransformShape_GetCInfoSize();
};

// @fnv 0x00622430
// src: COMMUNITY 0x00622430
unsigned int __thiscall FUN_00622430_shell::bhkTransformShape_GetCInfoSize()
{
    return 0x50;
}

extern NiRTTI g_011d5e70;

// @fnv 0x0066b5b0
const NiRTTI* BSTreeNode::GetRTTI() const
{
    return &g_011d5e70;
}

// @fnv 0x0066b5c0
NiNode* BSTreeNode::GetBranchesNode()
{
    return static_cast<NiNode*>(GetAt(0));
}

// @fnv 0x0066b5e0
NiNode* BSTreeNode::GetFrondNode()
{
    return static_cast<NiNode*>(GetAt(1));
}

// @fnv 0x0066b600
NiNode* BSTreeNode::GetLeavesNode()
{
    return static_cast<NiNode*>(GetAt(2));
}

void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// @fnv 0x0066b680
void* BSTreeNode::FUN_0066b680(unsigned int flags)
{
    this->BSTreeNode::~BSTreeNode();
    if (flags & 1)
        __Dummy_00b6fef0(this, 248);
    return this;
}

// @fnv 0x0066be30
bool BSTreeNode::SetLeafTextureVariant(unsigned char acTest)
{
    if (!static_cast<NiTriBasedGeom*>(m_spLeafMesh))
    {
        return false;
    }
    if (acTest == 0xff)
    {
        reinterpret_cast<NiAVObject*>(static_cast<NiTriBasedGeom*>(m_spLeafMesh))
            ->SetAppCulled(true);
    }
    else
    {
        reinterpret_cast<NiAVObject*>(static_cast<NiTriBasedGeom*>(m_spLeafMesh))
            ->SetAppCulled(false);
        NiAlphaProperty* pprop = reinterpret_cast<NiAlphaProperty*>(
            reinterpret_cast<NiAVObject*>(static_cast<NiTriBasedGeom*>(m_spLeafMesh))
                ->GetProperty(0));
        if (pprop)
        {
            pprop->NiAlphaProperty_SetTestRef(acTest);
        }
    }
    return true;
}

struct NiCullingProcess;
extern "C" unsigned char __cdecl BSTreeManager_GetTreesEnabled();
// If FUN_0054ee20() returns nonzero, forwards the culling call to FUN_00a5dbe0 with arCuller.
// @fnv 0x0066bf50
void __thiscall BSTreeNode::OnVisible(NiCullingProcess& arCuller)
{
    if (BSTreeManager_GetTreesEnabled())
    {
        reinterpret_cast<NiNode*>(this)->NiNode::OnVisible(arCuller);
    }
}

struct FUN_00c6c290_holder
{
    void FUN_00c6c290();
};

struct FUN_0066d410_shell : public FUN_00c6c290_holder
{
    void ForwardCall_0066d410();
};

// @fnv 0x0066d410
// src: GUESS 0x0066d410 (confidence: low)
void FUN_0066d410_shell::ForwardCall_0066d410()
{
    FUN_00c6c290();
}

extern const NiRTTI g_012683d0;

struct FUN_0066d430_shell
{
    const NiRTTI* GetRTTI() const;
};

// @fnv 0x0066d430
const NiRTTI* FUN_0066d430_shell::GetRTTI() const
{
    return &g_012683d0;
}

void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

struct FUN_0066d440_shell
{
    void ForwardCall_0066d470();
    void* FUN_0066d440(unsigned int flags);
};

// @fnv 0x0066d440
void* FUN_0066d440_shell::FUN_0066d440(unsigned int flags)
{
    this->ForwardCall_0066d470();
    if (flags & 1)
        __Dummy_00b6fef0(this, 20);
    return this;
}

struct FUN_0066d470_shell
{
    void ForwardCall_0066d410();
    void ForwardCall_0066d470();
};

// @fnv 0x0066d470
// src: GUESS 0x0066d470 (confidence: low)
void FUN_0066d470_shell::ForwardCall_0066d470()
{
    this->ForwardCall_0066d410();
}

struct FUN_0066d510_shell
{
    const void* bhkMultiSphereShape_GetRTTI();
};

extern const void* g_012683e0;

// @fnv 0x0066d510
// src: COMMUNITY 0x0066d510
const void* FUN_0066d510_shell::bhkMultiSphereShape_GetRTTI()
{
    return &g_012683e0;
}

struct FUN_0066d520_shell
{
    void FUN_00cb78b0();
    void* FUN_0066d520(unsigned int flags);
};

void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

// @fnv 0x0066d520
void* __thiscall FUN_0066d520_shell::FUN_0066d520(unsigned int flags)
{
    this->FUN_00cb78b0();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x14);
    return this;
}

struct GlobalObjectO2_00a7b610
{
};
GlobalObjectO2_00a7b610 g_012681b4;

struct FUN_0066d610_shell
{
    GlobalObjectO2_00a7b610* GetGlobalObject();
};

// @fnv 0x0066d610
GlobalObjectO2_00a7b610* FUN_0066d610_shell::GetGlobalObject()
{
    return &g_012681b4;
}

// @fnv 0x0066d730
// src: COMMUNITY 0x0066d730
unsigned int __thiscall bhkCapsuleShape::retn_48() const
{
    return 0x30;
}

struct FUN_0066da50_t
{
    void FUN_0066da50();
};

struct FUN_0066d7a0_shell
{
    int m0;
    FUN_0066da50_t m1;
    void RunInner();
};

// @fnv 0x0066d7a0
void FUN_0066d7a0_shell::RunInner()
{
    m1.FUN_0066da50();
}

// @fnv 0x0066b620
NiTriBasedGeom* BSTreeNode::GetLeafMesh()
{
    return static_cast<NiTriBasedGeom*>(m_spLeafMesh);
}

extern const char* const g_012683d0_arg1;

struct FUN_0066d400_shell
{
    const char* const* GetArg1Ptr();
};

// @fnv 0x0066d400
const char* const* FUN_0066d400_shell::GetArg1Ptr()
{
    return &g_012683d0_arg1;
}

// Gets the node's NiAVObject and sets its app-culled flag to the inverse of abVisible; returns false if there is no object.
// @fnv 0x0066bc40
bool __thiscall BSTreeNode::SetBranchVisible(bool abVisible)
{
    NiAVObject* object = GetBranchesNode();
    if (!object)
        return false;
    object->SetAppCulled(!abVisible);
    return true;
}

// Gets the frond node, sets its app-culled flag to the inverse of abVisible, and returns false if no leaf exists.
// @fnv 0x0066bc90
bool __thiscall BSTreeNode::SetFrondVisible(bool abVisible)
{
    NiNode* pnode = GetFrondNode();
    if (pnode == 0)
        return false;
    ((NiAVObject*)pnode)->SetAppCulled(!abVisible);
    return true;
}

struct FUN_0066d3d0_shell
{
    void __thiscall bhkPCollisionObject_bhkPCollisionObject(void*);
};
extern int DAT_01066acc;
struct FUN_0066d3a0_shell
{
    void* __thiscall bhkSPCollisionObject_bhkSPCollisionObject(void*);
};
// @fnv 0x0066d3a0
// src: EXE 0x0066d3a0
void* __thiscall FUN_0066d3a0_shell::bhkSPCollisionObject_bhkSPCollisionObject(void* arg)
{
    reinterpret_cast<FUN_0066d3d0_shell*>(this)->bhkPCollisionObject_bhkPCollisionObject(arg);
    *reinterpret_cast<void**>(this) = &DAT_01066acc;
    return this;
}

namespace fnv_0066d3d0 {
struct FUN_00c6b950_shell
{
    void* __thiscall FUN_00c6b950(unsigned int);
};
extern void* DAT_01066b94;

struct FUN_0066d3d0_shell
{
    void* m0;
    void* __thiscall bhkPCollisionObject_bhkPCollisionObject(unsigned int a);
};

// Calls FUN_00c6b950 with a, then sets m0 to point at DAT_01066b94 and returns this.
// @fnv 0x0066d3d0
// src: EXE 0x0066d3d0
void* __thiscall FUN_0066d3d0_shell::bhkPCollisionObject_bhkPCollisionObject(unsigned int a)
{
    ((FUN_00c6b950_shell*)this)->FUN_00c6b950(a);
    m0 = &DAT_01066b94;
    return this;
}
}  // namespace fnv_0066d3d0

extern "C" void __cdecl hkActionCinfo_hkActionCinfo();
extern "C" void __cdecl FUN_0056e270();
struct FUN_0056e120_shell
{
    void __thiscall bhkTransform_setIdentity();
};
struct FUN_0066d550_shell
{
    void* Initialize();
};
// @fnv 0x0066d550
void* FUN_0066d550_shell::Initialize()
{
    ((void(__thiscall*)(void*))hkActionCinfo_hkActionCinfo)(this);
    ((unsigned int*)this)[1] = 0;
    ((void(__thiscall*)(void*))FUN_0056e270)((char*)this + 0x10);
    ((FUN_0056e120_shell*)((char*)this + 0x10))->bhkTransform_setIdentity();
    return this;
}

struct FUN_00c8bed0_holder
{
    void __thiscall FUN_00c8bed0();
};
void __cdecl _delete(void*, unsigned int);
// @fnv 0x0066d620
void* bhkTransformShape::Destroy(unsigned int flags)
{
    ((FUN_00c8bed0_holder*)this)->FUN_00c8bed0();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

void __cdecl _delete(void* p, unsigned int size);
// A struct argument keeps the deletion flags on the stack, preserving the
// original thiscall ABI without a stand-in capsule class.
struct CapsuleDeleteFlags
{
    unsigned int value;
};

// @fnv 0x0066d740
void* __fastcall DestroyCapsuleShape(bhkCapsuleShape* shape, CapsuleDeleteFlags flags)
{
    shape->bhkCapsuleShape::~bhkCapsuleShape();
    if (flags.value & 1)
        _delete(shape, 0x14);
    return shape;
}

struct FUN_0056e900_shell
{
    void __thiscall StepAndReturnThis();
};
struct FUN_006299a0_shell
{
    void __thiscall ProcessAndReturnValue_006299a0();
};
struct FUN_0066d770_shell
{
    void* __thiscall hkMultiSphereShapeCinfo_hkMultiSphereShapeCinfo();
};
// Calls StepAndReturnThis on this and FUN_006299a0 on the object at this+4, then returns this.
// @fnv 0x0066d770
// src: XBOX_PDB 0x0066d770
void* __thiscall FUN_0066d770_shell::hkMultiSphereShapeCinfo_hkMultiSphereShapeCinfo()
{
    ((FUN_0056e900_shell*)this)->StepAndReturnThis();
    ((FUN_006299a0_shell*)((char*)this + 4))->ProcessAndReturnValue_006299a0();
    return this;
}

// Gets the node and, if present, sets its app-culled flag to the inverse of abVisible; returns whether a node was found.
// @fnv 0x0066bce0
bool __thiscall BSTreeNode::SetLeavesVisible(bool abVisible)
{
    NiNode* pnode;
    pnode = GetLeavesNode();
    if (pnode == 0)
        return false;
    ((NiAVObject*)pnode)->SetAppCulled(!abVisible);
    return true;
}

// If this object has a property container and apProp is non-null, replaces any existing property slot 5 with apProp and returns whether it attached.
// @fnv 0x0066bec0
bool BSTreeNode::SetTexturingProperty(NiTexturingProperty* apProp)
{
    NiTexturingProperty* pprop = 0;
    if (!static_cast<NiTriBasedGeom*>(m_spLeafMesh) || !apProp)
        return false;
    pprop = (NiTexturingProperty*)((NiAVObject*)static_cast<NiTriBasedGeom*>(m_spLeafMesh))->GetProperty(5);
    if (pprop)
    {
        if (pprop == apProp)
            return false;
        ((NiAVObject*)static_cast<NiTriBasedGeom*>(m_spLeafMesh))->RemoveProperty(5);
    }
    ((NiAVObject*)static_cast<NiTriBasedGeom*>(m_spLeafMesh))->AttachProperty(reinterpret_cast<NiObject*>(apProp));
    return true;
}

struct FUN_0094db80_shell
{
    void NiAlphaProperty_SetTestRef(unsigned char);
};
// Looks up the node for a type; if mode is 0xff it culls the node, otherwise it unculls it and passes mode to the node's property 0.
// @fnv 0x0066bdb0
bool BSTreeNode::SetFrondTextureVariant(unsigned short type, unsigned char mode)
{
    NiAVObject* node = reinterpret_cast<NiAVObject*>(GetFrondMesh(type));
    if (node == 0)
        return false;
    if (mode == 0xff)
    {
        node->SetAppCulled(true);
    }
    else
    {
        node->SetAppCulled(false);
        NiObject* property = (NiObject*)((NiAVObject*)node)->GetProperty(0);
        if (property != 0)
            ((FUN_0094db80_shell*)property)->NiAlphaProperty_SetTestRef(mode);
    }
    return true;
}

struct NiCamera;
extern double gModifierZero;
extern "C" unsigned int __cdecl BSTreeManager_GetCamera();
extern bool __cdecl NodeInFrustum(NiAVObject*, NiCamera*);
#include "../../../include/MEM_CONTEXT.h"
// @fnv 0x0066bf80
void BSTreeNode::UpdateDownwardPass(NiUpdateData& data, unsigned int flags)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TREEART, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeNode.cpp", 0x20d);
    if (!BSTreeManager_GetTreesEnabled())
        return;
    if (data.fTime > gModifierZero)
    {
        if (!NodeInFrustum((NiAVObject*)this, (NiCamera*)BSTreeManager_GetCamera()))
            return;
    }
    SetWindAmplitude(data.fTime);
    reinterpret_cast<NiNode*>(this)->NiNode::UpdateDownwardPass(
        data, flags);
}

class NiTexture;

struct bhkWorldObject;

extern char g_01268444_arg1;
NiObject* __cdecl NiObject_DynamicCast(const NiRTTI* apRTTI, NiObject* apObject);

// @fnv 0x0066d7c0
bhkSimpleShapePhantom* BSTreeNode::GetLeafObject()
{
    NiObject* pResult4 = 0;
    BGSBodyPart* pPart8 = reinterpret_cast<BGSBodyPart*>(GetFrondNode());
    if (pPart8)
    {
        NiPointer<NiTexture> spRetainedObject((NiTexture*)pPart8->GetPartName());
        if (spRetainedObject)
        {
            bhkWorldObject* pWorld5 = ((bhkCollisionObject*)(NiTexture*)spRetainedObject)->bhkNiCollisionObject_GetWorldObject();
            pResult4 = NiObject_DynamicCast((const NiRTTI*)&g_01268444_arg1, (NiObject*)pWorld5);
        }
    }
    return reinterpret_cast<bhkSimpleShapePhantom*>(pResult4);
}

// Frees the two geometry pointer arrays owned by the object and nulls their pointers.
// @fnv 0x0066b6c0
BSTreeNode::~BSTreeNode()
{
    if (m_pBranchMeshes)
    {
        delete[] m_pBranchMeshes;
        m_pBranchMeshes = 0;
    }
    if (m_pFrondMeshes)
    {
        delete[] m_pFrondMeshes;
        m_pFrondMeshes = 0;
    }
}

// Returns the entry at index from m_pFrondMeshes if the list pointer and entries are valid and index is in range, otherwise returns 0.
// @fnv 0x0066b840
NiTriBasedGeom* BSTreeNode::GetFrondMesh(unsigned short index)
{
    if (static_cast<BSTreeModel*>(m_spModel) == 0 || m_pFrondMeshes == 0 || index >= m_spModel->FUN_006699d0())
        return 0;
    return static_cast<NiTriBasedGeom*>(m_pFrondMeshes[index]);
}

struct S_0066ba30_Str
{
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    S_0066ba30_Str();
    ~S_0066ba30_Str();
};
struct S_0066ba30_Obj;
// Validates the model, object array and object, then clears the node's old object, sets the new one and stores it at index.
// @fnv 0x0066ba30
bool BSTreeNode::SetFrondGeometry(unsigned short index, NiTriBasedGeom* apObj)
{
    S_0066ba30_Str name5;
    if (!m_spModel || !m_pFrondMeshes || !apObj)
        return false;
    unsigned short count = m_spModel->FUN_006699d0();
    if (index >= count)
        return false;
    NiNode* pNode2 = GetFrondNode();
    if (!pNode2)
        return false;
    if (m_pFrondMeshes[index])
        pNode2->RemoveObject(reinterpret_cast<NiAVObject*>(static_cast<NiTriBasedGeom*>(m_pFrondMeshes[index])));
    pNode2->AttachChildInAvailableSlot(reinterpret_cast<NiAVObject*>(apObj), true);
    m_pFrondMeshes[index] = apObj;
    return true;
}

struct VisNodeAlpha70
{
    void Method0094db80(unsigned char aAlpha);
};

// @fnv 0x0066bd30
bool BSTreeNode::SetBranchTextureVariant(unsigned short aType, unsigned char aMode)
{
    NiAVObject* node = reinterpret_cast<NiAVObject*>(GetBranchMesh(aType));
    if (node == 0)
        return false;
    if (aMode == 0xff)
    {
        node->SetAppCulled(true);
    }
    else
    {
        node->SetAppCulled(false);
        VisNodeAlpha70* alpha = (VisNodeAlpha70*)node->GetProperty(0);
        if (alpha)
            alpha->Method0094db80(aMode);
    }
    return true;
}

// @fnv 0x0066c070
void BSTreeNode::UpdateSelectedDownwardPass(NiUpdateData& kUpdate, unsigned int uiFlags)
{
    AutoMemContext kMemContext(MEM_CONTEXT_MEM_CONTEXT_TREEART, true,
                               "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeNode.cpp",
                               0x223);
    if (!BSTreeManager_GetTreesEnabled())
        return;
    if (kUpdate.fTime > gModifierZero)
    {
        if (!NodeInFrustum((NiAVObject*)this, (NiCamera*)BSTreeManager_GetCamera()))
            return;
    }
    SetWindAmplitude(kUpdate.fTime);
    reinterpret_cast<NiNode*>(this)->NiNode::UpdateSelectedDownwardPass(
        reinterpret_cast<NiUpdateData&>(kUpdate), uiFlags);
}

extern char DAT_01066c5c;
extern unsigned int DAT_012683dc;

struct FUN_0066d490_base
{
    FUN_0066d490_base();
    ~FUN_0066d490_base();
};

struct FUN_0066d490_cls : FUN_0066d490_base
{
    void* m_vptr;
    void bhkMultiSphereShape_Init(unsigned int a1);
    FUN_0066d490_cls(unsigned int a1);
};

// Sets the vtable pointer, calls FUN_00cb7b80 with a1, and increments DAT_012683dc.
// @fnv 0x0066d490
FUN_0066d490_cls::FUN_0066d490_cls(unsigned int a1)
{
    *(void* volatile*)&m_vptr = &DAT_01066c5c;
    this->bhkMultiSphereShape_Init(a1);
    DAT_012683dc = DAT_012683dc + 1;
}

extern char DAT_01066d44;
extern unsigned int DAT_012681b0;

struct FUN_0066d590_base
{
    FUN_0066d590_base();
    ~FUN_0066d590_base();
};

struct FUN_0066d590_cls : FUN_0066d590_base
{
    void* m_vptr;
    void bhkTransformShape_Init(unsigned int a1);
    FUN_0066d590_cls(unsigned int a1);
};

// Sets the vtable pointer, calls FUN_00c8c5b0 with the given id, and increments DAT_012681b0.
// @fnv 0x0066d590
FUN_0066d590_cls::FUN_0066d590_cls(unsigned int a1)
{
    *(void* volatile*)&m_vptr = &DAT_01066d44;
    this->bhkTransformShape_Init(a1);
    DAT_012681b0 = DAT_012681b0 + 1;
}

extern "C" int __cdecl BSsprintf(char* text, unsigned size, const char* fmt, ...);
extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* s);

struct S_0066d880_List
{
    void FUN_0096a610(char** item);
};
struct S_0066d880_Obj
{
    unsigned char CombatProcedure_GetFinished();
    int FUN_008d6f30();
};
extern "C" void __cdecl NiNode_GetViewerStrings();

// The shared NiNode header does not declare its viewer-string override.
// @fnv 0x0066d880
void BSTreeNode::GetViewerStrings(NiViewerStringsArray* list)
{
    reinterpret_cast<void (__thiscall*)(NiNode*, void*)>(NiNode_GetViewerStrings)(this, list);
    char* name = NiViewerStrings_NiGetViewerString_Title("BSTreeNode");
    reinterpret_cast<S_0066d880_List*>(list)->FUN_0096a610(&name);
    char* text;
    if (m_spModel.operator->())
    {
        text = new char[0x20];
        if (m_spModel.operator->()->CombatProcedure_GetFinished())
            BSsprintf(text, 0x20, "Type = Instance");
        else
            BSsprintf(text, 0x20, "Type = Base");
        reinterpret_cast<S_0066d880_List*>(list)->FUN_0096a610(&text);
        text = new char[0x20];
        BSsprintf(text, 0x20, "Seed = %d", reinterpret_cast<S_0066d880_Obj*>(m_spModel.operator->())->FUN_008d6f30());
        reinterpret_cast<S_0066d880_List*>(list)->FUN_0096a610(&text);
    }
    else
    {
        text = new char[0x20];
        BSsprintf(text, 0x20, "-No Model-");
        reinterpret_cast<S_0066d880_List*>(list)->FUN_0096a610(&text);
    }
}

extern void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern void* __cdecl FormHeap_Allocate(unsigned int size);
extern float DAT_01016b78;
extern void* __cdecl GetFltValueAtOffset16();

// Retained until NiNode supports the original sized-only allocation cleanup:
// its inherited unsized delete changes the constructor's exception tails.
struct FUN_00a5ecb0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    FUN_00a5ecb0(int initial);
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void*, unsigned int);
};

struct FUN_0051cf00
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    FUN_0051cf00();
    void SetMode_0051d000(int enabled);
    void FUN_006404b0(float size, float a, float b, float c);
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void*, unsigned int);
};
struct FUN_0066b640
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
    virtual void v8c(void*);
    unsigned int unk04, unk08, unk0c, unk10;
    FUN_0066b640();
    void bhkNiCollisionObject_SetWorldObject(void* p);
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void*, unsigned int);
};
// Initializes the tree controller: sets up slots, allocates arrays from the tree list counts, creates controllers and attaches the chosen object.
// @fnv 0x0066b120
BSTreeNode::BSTreeNode(void* initial, void* external) : m_spModel(0), m_spLeafMesh(0)
{
    BSFadeNode_SetLODMultType(6);
    m_spModel = reinterpret_cast<BSTreeModel*>(initial);
    NiAVObject_SetSelectiveUpdate(1);
    FUN_00a5ecb0* pkCurrentObject = new FUN_00a5ecb0(0);
    NiNode::AddObjectAt(0, reinterpret_cast<NiAVObject*>(pkCurrentObject));
    pkCurrentObject = new FUN_00a5ecb0(0);
    NiNode::AddObjectAt(1, reinterpret_cast<NiAVObject*>(pkCurrentObject));
    FUN_0066b640* pController;
    FUN_0051cf00* controller = new FUN_0051cf00();
    controller->SetMode_0051d000(1);
    controller->FUN_006404b0(DAT_01016b78, 1.0f, 0.0f, 0.0f);
    NiNode::AddObjectAt(2, reinterpret_cast<NiAVObject*>(controller));

    unsigned short count;
    unsigned short i = m_spModel.operator->()->GetNumBranchLODLevels();
    if (i != 0)
    {
        m_pBranchMeshes = new NiPointer<NiTriBasedGeom>[i];
        for (count = 0; count < i; ++count)
            m_pBranchMeshes[count] = 0;
    }
    else
    {
        m_pBranchMeshes = 0;
    }
    i = m_spModel.operator->()->FUN_006699d0();
    if (i != 0)
    {
        m_pFrondMeshes = new NiPointer<NiTriBasedGeom>[i];
        for (count = 0; count < i; ++count)
            m_pFrondMeshes[count] = 0;
    }
    else
    {
        m_pFrondMeshes = 0;
    }
    m_spLeafMesh = 0;
    SetExtraDataName(GetFltValueAtOffset16());
    void* chosen = external ? external : m_spModel.operator->()->ConvertFloatToUInt();
    if (chosen)
    {
        pController = new FUN_0066b640();
        pController->bhkNiCollisionObject_SetWorldObject(external ? external : m_spModel.operator->()->ConvertFloatToUInt());
        pController->v8c(this);
    }
    m_fWindTime = 0.0f;
}

// Returns the object at usIndex from m_pBranchMeshes if the header exists, the array exists and usIndex is below the header count; otherwise returns 0.
// @fnv 0x0066b7d0
NiTriBasedGeom* BSTreeNode::GetBranchMesh(unsigned short usIndex)
{
    if (!static_cast<BSTreeModel*>(m_spModel) || !m_pBranchMeshes || usIndex >= m_spModel->GetNumBranchLODLevels())
        return 0;
    return static_cast<NiTriBasedGeom*>(m_pBranchMeshes[usIndex]);
}

// Clears the handler's current path if one is set, assigns pkPath to the handler, and stores it in m_kPathRef.
// @fnv 0x0066bbb0
void BSTreeNode::SetBillboardObject(NiTriBasedGeom* pkPath)
{
    if (!pkPath)
        return;

    NiNode* pkHandler = GetLeavesNode();
    if (!pkHandler)
        return;

    if (static_cast<NiTriBasedGeom*>(m_spLeafMesh))
        pkHandler->RemoveObject(reinterpret_cast<NiAVObject*>(static_cast<NiTriBasedGeom*>(m_spLeafMesh)));
    pkHandler->AttachChildInAvailableSlot(reinterpret_cast<NiAVObject*>(pkPath), true);
    m_spLeafMesh = pkPath;
}

struct FnvScopedContext
{
    int previousContext;
    int currentContext;
    FnvScopedContext();
    ~FnvScopedContext();
};
// Validates index and type against the model, clears the slot's existing object, sets the new object on the actor, and stores it in the slot.
// @fnv 0x0066b8b0
bool BSTreeNode::SetBranchGeometry(unsigned short index, NiTriBasedGeom* type)
{
    FnvScopedContext guard;
    if (!static_cast<BSTreeModel*>(m_spModel) || !m_pBranchMeshes || !type)
        return false;
    unsigned short maxIndex = m_spModel->GetNumBranchLODLevels();
    if (index >= maxIndex)
        return false;
    NiNode* actor = GetBranchesNode();
    if (!actor)
        return false;
    if (static_cast<NiTriBasedGeom*>(m_pBranchMeshes[index]))
    {
        actor->RemoveObject(reinterpret_cast<NiAVObject*>(static_cast<NiTriBasedGeom*>(m_pBranchMeshes[index])));
    }
    actor->AttachChildInAvailableSlot(reinterpret_cast<NiAVObject*>(type), true);
    m_pBranchMeshes[index] = type;
    return true;
}

