
// src/fallout_shared/havok/teshavokutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teshavokutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/Setting.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
#include "../../../include/NiObjectNET.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/bhkCollisionObject.h"
#include "../../../include/bhkWorldObject.h"
// CombatNode_teshavokutilities: local type (was include/CombatNode.h, which had no evidence of one real class); its methods are 0x00505c00 TESCombatStyle::GetPowerAttackF, 0x00505c20 TESCombatStyle::GetPowerAttackB, 0x005524b0 TESCombatStyle::GetPowerAttackChance, 0x006a9560 TESCombatStyle::GetPowerAttackL
class CombatNode_teshavokutilities
{
public:
    unsigned int FUN_00726070();
    signed char GetByteAtOffset8C();
    bool HasCombatFlag(int);
    signed char FUN_0073cb80();
    signed char TESCombatStyle_GetPowerAttackF();
    signed char GetByteAtOffset9A();
    signed char GetByteAtOffset9B();
    signed char FUN_009e8670();
};
#include "../../../include/bhkFilter.h"

extern float DAT_0104da48;
extern float DAT_0104e148;

struct FUN_006295a0_shell
{
    void __thiscall hkVector4_setAll(float);
    void hkAabb_setEmpty();
};

// Calls FUN_004589c0 with DAT_0104da48 on this object and with DAT_0104e148 on the object at offset 0x10.
// @fnv 0x006295a0
// src: COMMUNITY 0x006295a0
void FUN_006295a0_shell::hkAabb_setEmpty()
{
    hkVector4_setAll(DAT_0104da48);
    ((FUN_006295a0_shell*)((char*)this + 0x10))->hkVector4_setAll(DAT_0104e148);
}

float TESHavokUtilities_GetSceneGraphMass(NiAVObject* object);
// @fnv 0x0062c300
// src: XBOX_PDB 0x0062c300
float TESHavokUtilities_GetSceneGraphMass(NiAVObject* object)
{
    float fmass = 0.0f;
    if (object)
    {
        bhkCollisionObject* pCollisionObject = bhkCollisionObject::GetFromNiAVObject(object);
        bhkWorldObject* pWorldObject = pCollisionObject ? pCollisionObject->bhkNiCollisionObject_GetWorldObject() : 0;
        if (pWorldObject)
            fmass += pWorldObject->bhkRigidBody_GetMass();
        NiNode* pnode = (NiNode*)object->IsSceneNode();
        if (pnode && pnode->GetNumChildren())
        {
            for (unsigned int i = 0; i < pnode->GetNumChildren(); ++i)
                fmass += TESHavokUtilities_GetSceneGraphMass(pnode->GetAt(i));
        }
    }
    return fmass;
}

struct FUN_0062be70_shell
{
    char pad[0x30];
    CombatNode_teshavokutilities m_node;
    void ForwardCall_0062be70();
};

// @fnv 0x0062be70
// src: GUESS 0x0062be70 (confidence: low)
void FUN_0062be70_shell::ForwardCall_0062be70()
{
    m_node.FUN_00726070();
}

extern "C" void* __cdecl bhkUtilFunctions_GetNiAVObject(void*);

// @fnv 0x0062b4e0
// src: XBOX_PDB 0x0062b4e0
TESObjectREFR* __cdecl TESHavokUtilities_FindCollidableRef(void* object)
{
    TESObjectREFR* result = 0;
    if (object)
    {
        void* reference = bhkUtilFunctions_GetNiAVObject(object);
        if (reference)
            result = TESObjectREFR::GetReferenceFromNiAVObject(reference);
    }
    return result;
}

extern Setting originalRuntimeFloatSetting1034;
extern Setting originalRuntimeFloatSetting1035;
extern Setting originalRuntimeFloatSetting1036;
extern Setting originalRuntimeFloatSetting1037;
extern Setting originalRuntimeFloatSetting1038;
extern Setting g_011d0d2c;
extern Setting g_011d0f30;

// @fnv 0x0062b520
// src: COMMUNITY 0x0062b520
float TESHavokUtilities_ScaleGameplayImpulseForce(float value, bhkWorldObject* object, bool scale)
{
    if (!object)
        return value;
    float fMultiplier = 1.0f;
    bhkFilter layer = object->bhkWorldObject_GetCollisionFilter();
    switch (layer.CFilter_GetLayer())
    {
    case 14:
        fMultiplier *= *originalRuntimeFloatSetting1035.Float();
        break;
    case 8:
    case 29:
        fMultiplier *= *originalRuntimeFloatSetting1036.Float();
        break;
    case 10:
        fMultiplier *= *originalRuntimeFloatSetting1037.Float();
        break;
    case 20:
        fMultiplier *= *g_011d0f30.Float();
        break;
    default:
        fMultiplier *= *g_011d0d2c.Float();
        break;
    }
    if (scale)
    {
        float f = object->bhkRigidBody_GetMass();
        if (f < *originalRuntimeFloatSetting1038.Float())
            fMultiplier *= f / *originalRuntimeFloatSetting1038.Float();
    }
    fMultiplier *= *originalRuntimeFloatSetting1034.Float();
    return fMultiplier * value;
}

struct FUN_0043b5b0_shell
{
    void hkpWorldObject_markForRead();
};
struct TgtOps
{
    void* GetSourceFiles();
};
struct FUN_0043b5f0_shell
{
    void hkpWorldObject_unmarkForRead();
};
int __fastcall GetReferenceFlags(void*);
struct FUN_0043b560_shell
{
    void* GetSourceFilesFromObject();
};
// Calls GetReferenceFlags on this, then if non-null runs FUN_0043b5b0, GetSourceFiles and FUN_0043b5f0, returning the source files pointer.
// @fnv 0x0043b560
void* FUN_0043b560_shell::GetSourceFilesFromObject()
{
    void* result = 0;
    {
        FUN_0043b5b0_shell* obj = reinterpret_cast<FUN_0043b5b0_shell*>(GetReferenceFlags(this));
        if (obj)
        {
            obj->hkpWorldObject_markForRead();
            result = reinterpret_cast<TgtOps*>(obj)->GetSourceFiles();
            reinterpret_cast<FUN_0043b5f0_shell*>(obj)->hkpWorldObject_unmarkForRead();
        }
    }
    return result;
}

// @fnv 0x0062bc10
// src: XBOX_PDB 0x0062bc10
void __cdecl TESHavokUtilities_RemoveHavokFromSceneGraph(NiAVObject* pObject)
{
    if (pObject != 0)
    {
        void* r = pObject->NiAVObject_GetCollisionObject();
        if (r != 0)
        {
            pObject->AssignCollisionObject(0);
        }
        if (pObject->IsSceneNode() != 0)
        {
            NiNode* self = static_cast<NiNode*>(pObject);
            for (unsigned int i = 0; i < self->FUN_0043b480(); i++)
            {
                TESHavokUtilities_RemoveHavokFromSceneGraph(self->FUN_0043b4a0(i));
            }
        }
    }
}

struct ShapeContainer
{
    virtual void Reserved();
    virtual unsigned int Count();
};

struct CollisionShape
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
    virtual unsigned int Count();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ShapeContainer container;
    int GetType();
    CollisionShape* GetChild();
};

struct ShapeWrapper
{
    CollisionShape* GetShape();
};


// Recursively walks an NiAVObject tree, adding collision shape counts to firstCount or secondCount depending on shape type.
// @fnv 0x0062bd00
void CountCollisionShapes(NiAVObject* object, unsigned int* firstCount, unsigned int* secondCount)
{
    if (object)
    {
        bhkCollisionObject* collision4 = bhkCollisionObject::GetFromNiAVObject(object);
        if (collision4)
        {
            bhkWorldObject* world7 = collision4->bhkNiCollisionObject_GetWorldObject();
            if (world7)
            {
                ShapeWrapper* wrapper_2 = reinterpret_cast<ShapeWrapper*>(world7->bhkWorldObject_GetShape());
                CollisionShape* shape5 = wrapper_2 ? wrapper_2->GetShape() : 0;
                if (shape5)
                {
                    if (shape5->GetType() == 23)
                    {
                        CollisionShape* list7 = shape5;
                        *secondCount += list7->container.Count();
                    }
                    else if (shape5->GetType() == 6)
                    {
                        CollisionShape* collection = shape5;
                        *firstCount += collection->Count();
                    }
                    else if (shape5->GetType() == 10)
                    {
                        CollisionShape* parent = shape5;
                        CollisionShape* child9 = parent->GetChild();
                        if (child9)
                            *secondCount += child9->container.Count();
                    }
                }
            }
        }
        if (object->IsSceneNode())
        {
            NiNode* node5 = static_cast<NiNode*>(object);
            for (unsigned int index2 = 0; index2 < node5->GetNumChildren(); ++index2)
                CountCollisionShapes(node5->GetAt(index2), firstCount, secondCount);
        }
    }
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting721;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting722;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting723;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting724;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting725;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting726;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting728;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting729;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting730;
extern Setting g_011cf600;
extern Setting g_011cf2fc;
extern float DAT_01013974;
// Selects a factor and threshold from value against several float settings, then returns factor times a distance-scaled multiplier or zero.
// @fnv 0x0062be90
float __cdecl ComputeDistanceFactor(float value, float distance)
{
    float factor = 0.0f;
    float threshold = DAT_01013974;
    if (value < *originalRuntimeFloatSetting721.Float())
        factor = 0.0f;
    else if (value < *originalRuntimeFloatSetting722.Float())
    {
        factor = *g_011cf600.Float();
        threshold = *originalRuntimeFloatSetting728.Float();
    }
    else if (value < *originalRuntimeFloatSetting723.Float())
    {
        factor = *originalRuntimeFloatSetting724.Float();
        threshold = *originalRuntimeFloatSetting729.Float();
    }
    else
    {
        factor = *originalRuntimeFloatSetting725.Float();
        threshold = *originalRuntimeFloatSetting730.Float();
    }
    float scale =
        distance > threshold ? *g_011cf2fc.Float() + distance * *originalRuntimeFloatSetting726.Float() : 0.0;
    return factor * scale;
}

class Target62B
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7C();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void SetOwner(NiAVObject* pkOwner);

    NiAVObject* GetOwner();
};

class Handle62B
{
  public:
    void Reset(void* pvObject);
    Target62B* Get() const;

    Target62B* m_pPointer;
};

// @fnv 0x0062bc90
void NiAVObject::AssignCollisionObject(NiCollisionObject* pvTarget)
{
    reinterpret_cast<Handle62B&>(m_spCollisionObject).Reset(pvTarget);
    if (reinterpret_cast<Handle62B&>(m_spCollisionObject).Get() && reinterpret_cast<Handle62B&>(m_spCollisionObject).Get()->GetOwner() != this)
        reinterpret_cast<Handle62B&>(m_spCollisionObject).Get()->SetOwner(this);
}

struct BGSAcousticSpace;
struct SoundPlaybackManager
{
    static void __cdecl ResetAcousticSpace(BGSAcousticSpace*);
};
struct MapH
{
    bool RemoveAt(unsigned int);
};
struct Ref
{
    BGSAcousticSpace* GetNext();
};
struct FUN_0061f890_shell
{
    char pad[0x18];
    MapH m_map;
    bool BGSAcousticSpaceListener_DequeueRemoval(NiAVObject* object, bool flag);
};
// @fnv 0x0061f890
// src: XBOX_PDB 0x0061f890
bool FUN_0061f890_shell::BGSAcousticSpaceListener_DequeueRemoval(NiAVObject* object, bool flag)
{
    bool removed = m_map.RemoveAt((unsigned int)object);
    if (removed && flag)
        SoundPlaybackManager::ResetAcousticSpace(((Ref*)object)->GetNext());
    return removed;
}

unsigned int GetBSXFlags(unsigned int handle, unsigned int type);


// Returns true for an actor with health or a knocked state, or if GetBSXFlags(handle, 0x48) equals 0x48.
// @fnv 0x0062c3c0
// src: XBOX_PDB 0x0062c3c0
bool TESHavokUtilities_Should3DRagDoll(TESObjectREFR* refr, unsigned int handle)
{
    if (refr != 0 && refr->IsActor() && (refr->HasHealth(0) || refr->GetHasKnockedState()))
    {
        return true;
    }
    if (GetBSXFlags(handle, 0x48) == 0x48)
    {
        return true;
    }
    return false;
}

#include <xmmintrin.h>
struct __declspec(align(16)) PhysicsTransform
{
    __m128 vector;
    void FUN_006815c0();
    void hkVector4_sub4(unsigned int operation);
    void normalize3_0062aea0();
    void hkVector4_mul4(void* data);
    void hkVector4_add4(int value);
};
struct __declspec(align(16)) PhysicsData
{
    __m128 vector;
    void FUN_005dbf20(float size);
};
struct PhysicsState
{
    int hkpRigidBody_getLinearVelocity();
    void OnTrigger(PhysicsTransform* data);
};
struct PhysicsObject
{
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual void Unknown20();
    virtual void Unknown21();
    virtual void Unknown22();
    virtual void Unknown23();
    virtual void Unknown24();
    virtual void Unknown25();
    virtual void Unknown26();
    virtual void Unknown27();
    virtual void Unknown28();
    virtual void Unknown29();
    virtual void Unknown30();
    virtual void Unknown31();
    virtual void Unknown32();
    virtual void Unknown33();
    virtual void Unknown34();
    virtual void Unknown35();
    virtual void Unknown36();
    virtual void Unknown37();
    virtual void Unknown38();
    virtual void Unknown39();
    virtual void Unknown40();
    virtual void Unknown41();
    virtual void Unknown42();
    virtual void Unknown43();
    virtual void Unknown44();
    virtual void Unknown45();
    virtual void Unknown46();
    virtual void Unknown47();
    virtual void Unknown48();
    virtual void Unknown49();
    virtual void Unknown50();
    virtual void Unknown51();
    virtual void Unknown52();
    virtual void Unknown53();
    virtual void Unknown54();
    virtual void Unknown55();
    virtual void Unknown56();
    virtual void Unknown57();
    virtual void Unknown58();
    virtual void Unknown59();
    virtual void UpdateTransform(PhysicsTransform* out);
    PhysicsState* GetReferenceFlags();
};
struct MaterialSelector
{
    int form;
    int index;
    int family;
    int region;
    int kind;
};
extern float DAT_0119acc8[];
extern const float DAT_01016088;

// Recursively updates the physics collision scale of a scene node and its children based on a size coefficient and material type.
// @fnv 0x0062b660
void __cdecl SetCollisionScale(NiAVObject* node, unsigned int operation, float size, MaterialSelector* material)
{
    if (node)
    {
        bhkCollisionObject* runtime = bhkCollisionObject::GetFromNiAVObject(node);
        if (runtime)
        {
            PhysicsObject* body = reinterpret_cast<PhysicsObject*>(runtime->bhkNiCollisionObject_GetWorldObject());
            if (body)
            {
                int code = reinterpret_cast<bhkWorldObject*>(body)->bhkWorldObject_GetCollisionFilter().CFilter_GetBipedPart();
                float coefficient = DAT_0119acc8[code];
                if (material && material->kind != -1)
                {
                    if ((material->kind == 1 || material->kind == 2) && code == 1)
                        coefficient = DAT_01016088;
                    if ((material->kind == 3 || material->kind == 4) && (code == 5 || code == 6 || code == 7))
                        coefficient = DAT_01016088;
                    if ((material->kind == 5 || material->kind == 6) && (code == 11 || code == 12 || code == 13))
                        coefficient = DAT_01016088;
                    if ((material->kind == 7 || material->kind == 8 || material->kind == 9) &&
                        (code == 8 || code == 9 || code == 10))
                        coefficient = DAT_01016088;
                    if ((material->kind == 10 || material->kind == 11 || material->kind == 12) &&
                        (code == 14 || code == 15 || code == 16))
                        coefficient = DAT_01016088;
                }
                float scale = size * coefficient;
                PhysicsTransform transform;
                transform.FUN_006815c0();
                body->UpdateTransform(&transform);
                transform.hkVector4_sub4(operation);
                transform.normalize3_0062aea0();
                PhysicsState* state = body->GetReferenceFlags();
                PhysicsData volume;
                volume.FUN_005dbf20(scale);
                transform.hkVector4_mul4(&volume);
                transform.hkVector4_add4(state->hkpRigidBody_getLinearVelocity());
                state->OnTrigger(&transform);
            }
        }
        NiNode* children = node->IsSceneNode();
        if (children)
        {
            for (unsigned int i = 0; i < children->FUN_0043b480(); ++i)
            {
                NiAVObject* child = children->FUN_0043b4a0(i);
                SetCollisionScale(child, operation, size, material);
            }
        }
    }
}

struct SeqArray;
struct Inner62c;
struct NiSeq;

struct Inner62c
{
    void FUN_00483710();
};

struct NiSeq
{
    Inner62c* FUN_0044ddc0();
    unsigned int QUserData();
};

struct SeqArray
{
    int m0;
    int m4;
    int m8;
    SeqArray();
    ~SeqArray();
    int FUN_00726070();
    NiSeq*& NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(unsigned int i);
};

struct UnkACobj
{
    void CopySourceArray(SeqArray* arr);
};

class VtObj
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual Inner62c* v116();

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
    UnkACobj* unkAC;
};

void __cdecl CollectTreeResultValues(Inner62c* a, SeqArray* b);
void __cdecl hkpWorldOperationUtil_mergeIslands(Inner62c* a, NiSeq* b, NiSeq* c);

// Copies or collects entries into a local array, then compares each later entry’s owner and value with the first entry.
// @fnv 0x0062c430
// src: XBOX_PDB 0x0062c430
void __cdecl TESHavokUtilities_ConsolidateSimIslands(VtObj* apVtObj)
{
    if (apVtObj != 0)
    {
        SeqArray arr5;

        if (apVtObj->unkAC != 0)
            apVtObj->unkAC->CopySourceArray(&arr5);
        else
            CollectTreeResultValues(apVtObj->v116(), &arr5);

        if (arr5.FUN_00726070() != 0)
        {
            Inner62c* owner3 = arr5.NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(0)->FUN_0044ddc0();

            if (owner3 != 0)
            {
                owner3->FUN_00483710();

                for (int i = 1; i < arr5.FUN_00726070(); i++)
                {
                    unsigned int b;
                    unsigned int a2;
                    a2 = arr5.NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(0)->QUserData();
                    b = arr5.NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(i)->QUserData();
                    if (owner3 == arr5.NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(i)->FUN_0044ddc0() && a2 != b)
                        hkpWorldOperationUtil_mergeIslands(owner3, arr5.NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(0), arr5.NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(i));
                }

                owner3->FUN_00483710();
            }
        }
    }
}
