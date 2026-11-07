
// shadowscenenode_od_variant_ctxr_variant.cpp: rename variant for 0x006056f0 (integration 2026-10-30): the unit's skeleton with strncmp renamed, whose names are bound elsewhere.
// src/bsshader/shadowscenenode_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/shadowscenenode.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// The copied point constructor binds to 0x00416870, NiPoint3 in other units.
#include "../../include/NiPoint3.h"
#include "../../include/Setting.h"

struct FUN_00c5b5a0_cls
{
    int __thiscall BSPortalGraph_GetAlwaysRenderAt(int idx);
};
extern "C" char DAT_01203144, DAT_01203150, DAT_011f9426, DAT_011f9434, DAT_01016264, DAT_01023128, DAT_01070c80,
    DAT_01070c70;
struct Rect2180
{
    float x[4];
    Rect2180(float, float, float, float);
};
struct Frustum2180
{
    float left, right, top, bottom, nearz, farz;
    bool ortho;
    Frustum2180(bool);
};
struct Update2180
{
    int data[3];
    void FUN_0043d410(float, bool, bool);
};
struct String2180
{
    int value;
    String2180(const char*);
    ~String2180();
};
struct Provider2180
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual float get();
};
Provider2180* Main_GetWorldSceneGraph();
int Renderer_GetScreenHeight();
int Renderer_GetScreenWidth();
float tan_0057dd70(float);
struct FUN_00a712f0
{
    int bytes[0x114 / 4];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    FUN_00a712f0();
    void FUN_00712e60(const Rect2180&);
    void NiCamera_SetMaxFarNearRatio(float);
    void FUN_00a6faf0(const Frustum2180&);
    void SetLookAt(const NiPoint3&, const NiPoint3&);
    void NiCamera_SetMinNearPlaneDist(float);
    void NiAVObject_Update(const Update2180&);
    void AssignFixedString(const String2180&);
};
struct Target2180
{
    FUN_00a712f0* BlackJackMenu_SetupCamera();
};
extern "C" int __cdecl strncmp_r006056f0(const char*, const char*, unsigned int);

struct UpdateObject;
struct UpdateList
{
    unsigned vtable;
    unsigned buffer;
    unsigned size;
    unsigned capacity;
    void FUN_0096a610(const unsigned&);
    void NiTObjectArray_NiPointer_NiTexture_Add(const struct LocalNodePtr&);
};
struct LocalNodePtr
{
    UpdateObject* root;
    LocalNodePtr(UpdateObject*);
    ~LocalNodePtr();
};
struct NodeRecord
{
    unsigned first;
    unsigned second;
    unsigned third;
    unsigned fourth;
    unsigned fifth;
    unsigned sixth;
    unsigned seventh;
    unsigned eighth;
};
struct UpdatePacket
{
    NodeRecord records[4];
    unsigned identity;
    unsigned region;
    float weight;
    unsigned flags;
    unsigned sex;
    UpdateList primary;
    UpdateList secondary;
    UpdateList names;
    UpdateList nodes;
    bool enabled;
    bool dirty;
    unsigned short unknownD6;
    unsigned unknownD8;
    unsigned unknownDC;
    unsigned unknownE0;
    unsigned tailE4;
    unsigned tailE8;
    UpdatePacket();
    ~UpdatePacket();
};
struct UpdateObject
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual UpdateObject* GetList();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual UpdateObject* GetNode();
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
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual bool IsReady();
    virtual void SetReady(bool);
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
    virtual void slot084();
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
    virtual UpdateObject* GetRenderNode(int);
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual UpdateObject* GetRoot();
    UpdateObject* NiNode_GetAtChecked(unsigned);
    unsigned NiNode_GetChildCount();
    UpdateObject* FUN_0043b4a0(unsigned);
    unsigned FUN_00a59d30(unsigned);
    UpdateObject* FUN_00413f40();
    const char* FUN_0043b1b0();
    UpdateObject* GetBackTexture();
    bool FUN_008256d0();
    unsigned* FUN_006815c0();
    unsigned GetHeadPartModel_00613970(unsigned, unsigned);
    unsigned GetBodyPartTexture(unsigned, unsigned);
};
struct NodePointer
{
    UpdateObject* root;
    NodePointer& FUN_0066b0d0(UpdateObject*);
    UpdateObject* Modelloader_GetReferencedThis();
};
struct RefList
{
    UpdateObject* item;
    RefList* next;
    UpdateObject* FUN_00726070();
};
struct UpdateOwner
{
    unsigned unknown000;
    unsigned unknown004;
    unsigned unknown008;
    unsigned unknown00C;
    unsigned unknown010;
    unsigned unknown014;
    unsigned unknown018;
    unsigned unknown01C;
    unsigned unknown020;
    unsigned unknown024;
    unsigned unknown028;
    unsigned unknown02C;
    unsigned unknown030;
    unsigned unknown034;
    unsigned unknown038;
    unsigned unknown03C;
    unsigned unknown040;
    unsigned unknown044;
    unsigned unknown048;
    unsigned unknown04C;
    unsigned unknown050;
    unsigned unknown054;
    unsigned unknown058;
    unsigned unknown05C;
    unsigned unknown060;
    unsigned unknown064;
    unsigned unknown068;
    unsigned unknown06C;
    unsigned unknown070;
    unsigned unknown074;
    unsigned unknown078;
    unsigned unknown07C;
    unsigned unknown080;
    unsigned unknown084;
    unsigned unknown088;
    unsigned unknown08C;
    unsigned unknown090;
    unsigned unknown094;
    unsigned unknown098;
    unsigned unknown09C;
    unsigned unknown0A0;
    unsigned unknown0A4;
    unsigned unknown0A8;
    unsigned unknown0AC;
    unsigned unknown0B0;
    unsigned unknown0B4;
    unsigned unknown0B8;
    unsigned unknown0BC;
    unsigned unknown0C0;
    unsigned unknown0C4;
    unsigned unknown0C8;
    unsigned unknown0CC;
    unsigned unknown0D0;
    unsigned unknown0D4;
    unsigned unknown0D8;
    unsigned unknown0DC;
    unsigned unknown0E0;
    unsigned unknown0E4;
    unsigned unknown0E8;
    unsigned unknown0EC;
    unsigned unknown0F0;
    unsigned unknown0F4;
    unsigned unknown0F8;
    unsigned unknown0FC;
    unsigned unknown100;
    unsigned unknown104;
    unsigned unknown108;
    RefList references;
    unsigned unknown114;
    unsigned unknown118;
    unsigned unknown11C;
    unsigned unknown120;
    unsigned unknown124;
    unsigned unknown128;
    unsigned unknown12C;
    unsigned unknown130;
    unsigned unknown134;
    unsigned unknown138;
    unsigned unknown13C;
    unsigned unknown140;
    unsigned unknown144;
    unsigned unknown148;
    unsigned unknown14C;
    unsigned unknown150;
    unsigned unknown154;
    unsigned unknown158;
    unsigned unknown15C;
    unsigned unknown160;
    unsigned unknown164;
    unsigned unknown168;
    unsigned unknown16C;
    unsigned unknown170;
    unsigned unknown174;
    unsigned unknown178;
    unsigned unknown17C;
    unsigned unknown180;
    unsigned unknown184;
    unsigned unknown188;
    unsigned unknown18C;
    unsigned unknown190;
    unsigned unknown194;
    unsigned unknown198;
    unsigned unknown19C;
    unsigned unknown1A0;
    unsigned unknown1A4;
    unsigned unknown1A8;
    unsigned unknown1AC;
    unsigned unknown1B0;
    unsigned unknown1B4;
    unsigned unknown1B8;
    unsigned unknown1BC;
    unsigned unknown1C0;
    NodePointer previous;
    NodePointer current;
    unsigned FUN_00603b50();
    float GetHairLength();
    unsigned FUN_00602150();
    unsigned FUN_005f0cc0();
    unsigned TESDataHandler_GetRegionList();
    void FUN_00603ad0(UpdatePacket&);
    void CreatePartTexture(unsigned, LocalNodePtr&);
    void TESNPC_FixNPCNormals(UpdateObject* object);
};
bool FUN_00605d20();
const void* TESRace_GetHeadPartNodeName(unsigned);
bool General_bFaceGenTexturing_Get();
UpdateObject* BSUtilities_GetObjectByName(UpdateObject*, const void*);
UpdateObject* NiObject_DynamicCast(void*, unsigned);
bool MatchGeometryVertices(UpdateObject*, UpdateObject*, float, bool, unsigned);
void ApplyFaceGenTextures(UpdateObject*, UpdatePacket&);
extern unsigned DAT_0101f5f8;
extern unsigned DAT_011f4a5c;
extern char DAT_0104a7bc;
extern float DAT_01016248;
extern "C" int __cdecl strncmp_r006056f0(const char*, const char*, unsigned);
// @fnv 0x006056f0
// src: COMMUNITY 0x006056f0
void UpdateOwner::TESNPC_FixNPCNormals(UpdateObject* object)
{
    if (!object || !FUN_00605d20())
        return;
    UpdateObject* rootNode = object->GetRoot();
    unsigned entry = 0;
    UpdateObject* currentNode = current.FUN_0066b0d0(object->GetRenderNode(0)).Modelloader_GetReferencedThis();
    UpdateObject* found = BSUtilities_GetObjectByName(rootNode, TESRace_GetHeadPartNodeName(0));
    UpdateObject* node = found ? found->GetNode() : 0;
    if (!node || !currentNode)
        return;
    UpdateObject* nested;
    UpdateObject* list;
    UpdateObject* root;
    unsigned count;
    UpdateObject* key;
    if (!currentNode->IsReady())
    {
        found = BSUtilities_GetObjectByName(rootNode, &DAT_0101f5f8);
        if (found)
        {
            nested = found->GetList();
            if (nested)
            {
                found = nested->NiNode_GetAtChecked(0);
                if (found)
                {
                    list = found->GetList();
                    if (list)
                    {
                        entry = list->NiNode_GetChildCount();
                        for (unsigned i = 0; i < entry; i++)
                        {
                            found = list->FUN_0043b4a0(i);
                            root = found ? found->GetNode() : 0;
                            if (root)
                            {
                                count = root->FUN_00a59d30(2);
                                key = NiObject_DynamicCast(&DAT_011f4a5c, count);
                                if (key && !strncmp_r006056f0(key->FUN_00413f40()->FUN_0043b1b0(), &DAT_0104a7bc, 4))
                                {
                                    if (MatchGeometryVertices(root, node, DAT_01016248, true, 0))
                                    {
                                        currentNode->SetReady(true);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    entry = nested->NiNode_GetChildCount();
                    for (unsigned j = 0; j < entry; j++)
                    {
                        found = nested->FUN_0043b4a0(j);
                        root = found ? found->GetNode() : 0;
                        if (root)
                        {
                            count = root->FUN_00a59d30(2);
                            key = NiObject_DynamicCast(&DAT_011f4a5c, count);
                            if (key && !strncmp_r006056f0(key->FUN_00413f40()->FUN_0043b1b0(), &DAT_0104a7bc, 4))
                            {
                                if (MatchGeometryVertices(root, node, DAT_01016248, true, 0))
                                {
                                    currentNode->SetReady(true);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (references.FUN_00726070())
    {
        UpdatePacket packet;
        packet.identity = FUN_00603b50();
        packet.weight = GetHairLength();
        packet.flags = FUN_00602150();
        packet.sex = FUN_005f0cc0();
        packet.region = TESDataHandler_GetRegionList();
        FUN_00603ad0(packet);
        if (!packet.flags && references.FUN_00726070()->GetBackTexture() &&
            !references.FUN_00726070()->GetBackTexture()->FUN_008256d0())
            packet.flags = *references.FUN_00726070()->GetBackTexture()->FUN_006815c0();
        for (unsigned k = 0; k < 8; k++)
        {
            packet.primary.FUN_0096a610(references.FUN_00726070()->GetHeadPartModel_00613970(FUN_005f0cc0(), k));
            packet.secondary.FUN_0096a610(references.FUN_00726070()->GetBodyPartTexture(FUN_005f0cc0(), k));
            references.FUN_00726070();
            packet.names.FUN_0096a610((unsigned)TESRace_GetHeadPartNodeName(k));
            references.FUN_00726070();
            if (General_bFaceGenTexturing_Get())
            {
                LocalNodePtr ptr(0);
                CreatePartTexture(k, ptr);
                packet.nodes.NiTObjectArray_NiPointer_NiTexture_Add(ptr);
            }
        }
        references.FUN_00726070();
        packet.enabled = General_bFaceGenTexturing_Get();
        ApplyFaceGenTextures(previous.Modelloader_GetReferencedThis(), packet);
        ApplyFaceGenTextures(current.Modelloader_GetReferencedThis(), packet);
    }
}
