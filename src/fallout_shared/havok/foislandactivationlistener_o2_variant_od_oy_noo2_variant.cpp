#include "../../../include/NiTransform.h"
#include "../../../include/hkpIslandActivationListener.h"


// src/fallout_shared/havok/foislandactivationlistener_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout_shared/havok/foislandactivationlistener_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/havok/foislandactivationlistener_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/foislandactivationlistener.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/havok/foislandactivationlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/foislandactivationlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl _Deallocate(void*);
extern int DAT_0104de10;
extern int DAT_011f942c;
void BSShaderManager_ResetMotionBluredObject();
struct hkVector4;
struct TopicH
{
    NiPoint3* GetAddTopicList();
    NiPoint3& _ref_006815c0();
};
void HK2NI_00624b10(NiTransform*, NiPoint3*);
NiPoint3& SetNiPoint3FromHkVector4(NiPoint3&, const hkVector4&);
NiTransform* HK2NI_00624ad0(NiTransform* arNiTran, TopicH* arTopicH);

#include <xmmintrin.h>
struct Node96;
struct Ref96;
struct Physics96;
struct Geometry96;
struct Input96
{
    struct Array96* GetExtraPartList();
};
struct Array96
{
    int FUN_00726070();
    Node96*& NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(int);
};
struct Extra96
{
    void* ExtraDataList_GetModelSwap();
};
struct Cell96
{
    void TESObjectCELL_AttachReference3D(Ref96*, int);
};
struct Ref96
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual bool IsDisabled();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual bool NeedsUpdate();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual unsigned int GetNode();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual bool NeedsReset();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void Reset();
    Extra96* BSFile_GetDevice();
    Cell96* FUN_008d6f30();
    void* BGSSaveFormBuffer_GetForm();
};
struct FUN_0056ded0
{
    __m128 x, y, z, position;
    FUN_0056ded0();
};
struct Geometry96
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void SetFlags(int);
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void GetTransform(FUN_0056ded0*);
};
struct Physics96
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void SetTransform(NiTransform*);
    Node96* FUN_0044ddc0();
    bool bhkNiCollisionObject_GSetLocal();
    void bhkNiCollisionObject_SetSetLocal(bool);
};
struct Descriptor96
{
    int hkpCollidable_getCollisionFilterInfo();
};
struct Node96
{
    Descriptor96* TESDataHandler_GetWorldSpaceList();
};
struct Filter96
{
    int value;
    Filter96(int);
    int CFilter_GetLayer();
};
Physics96* FUN_004b5a50(Node96*);
Ref96* TESObjectREFR_FindReferenceFor3D(Node96*);
Geometry96* bhkEntity_Getbhk(const void*);
unsigned int GetBSXFlags(unsigned int, unsigned int);
struct Shadow96
{
    void FUN_00b5d9f0(unsigned int, int);
};
Shadow96* FUN_00450b80(unsigned int);
extern void* DAT_011ca27c;
extern void* DAT_011ca280;
extern char DAT_012681c0;
bool NiObject_IsKindOf(const void*, Geometry96*);
void bhkWorld_SetMotion(Node96*, int, bool, bool, bool);
struct Manager96
{
    void FOIslandActivationListener_islandDeactivatedCallback(Input96*);
};

// @fnv 0x00624720
// src: COMMUNITY 0x00624720
void Manager96::FOIslandActivationListener_islandDeactivatedCallback(Input96* input)
{
    if (!input)
        return;
    Array96* items = input->GetExtraPartList();
    int count = items->FUN_00726070();
    for (int i = 0; i < count; i++)
    {
        Node96* node = items->NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(i);
        Physics96* physics = FUN_004b5a50(node);
        Node96* linked = physics ? physics->FUN_0044ddc0() : 0;
        Ref96* ref = linked ? TESObjectREFR_FindReferenceFor3D(linked) : 0;
        void* model = ref ? ref->BSFile_GetDevice()->ExtraDataList_GetModelSwap() : 0;
        bool flag8 = ref && GetBSXFlags(ref->GetNode(), 8) ? true : false;
        bool flag128 = ref && GetBSXFlags(ref->GetNode(), 128) ? true : false;
        if (ref)
        {
            if (ref->NeedsReset())
                ref->Reset();
            if (!ref->IsDisabled() && !model && ((flag8 && flag128) || !flag8))
            {
                Cell96* cell = ref->FUN_008d6f30();
                if (cell)
                    cell->TESObjectCELL_AttachReference3D(ref, 0);
                if (ref->NeedsUpdate())
                    BSShaderManager_ResetMotionBluredObject();
            }
            else
            {
                if (!ref->IsDisabled())
                    FUN_00450b80(0)->FUN_00b5d9f0(ref->GetNode(), 0);
            }
            if (ref->BGSSaveFormBuffer_GetForm() == DAT_011ca27c || ref->BGSSaveFormBuffer_GetForm() == DAT_011ca280)
                bhkWorld_SetMotion(linked, 5, true, false, true);
        }
        if (Filter96(node->TESDataHandler_GetWorldSpaceList()->hkpCollidable_getCollisionFilterInfo()).CFilter_GetLayer() == 20 && ref && !ref->IsDisabled())
        {
            Geometry96* geometry = bhkEntity_Getbhk(node);
            if (geometry && NiObject_IsKindOf(&DAT_012681c0, geometry))
            {
                Geometry96* target = geometry;
                target->SetFlags(4);
                Physics96* body = FUN_004b5a50(node);
                if (body && !body->bhkNiCollisionObject_GSetLocal())
                {
                    body->bhkNiCollisionObject_SetSetLocal(true);
                    FUN_0056ded0 transform;
                    NiTransform niTransform;
                    target->GetTransform(&transform);
                    HK2NI_00624ad0(&niTransform, (TopicH*)&transform);
                    body->SetTransform(&niTransform);
                    body->bhkNiCollisionObject_SetSetLocal(false);
                }
            }
        }
    }
}
