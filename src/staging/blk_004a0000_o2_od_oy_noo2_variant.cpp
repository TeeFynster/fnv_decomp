#include "../../include/NiColorA.h"

// src/staging/blk_004a0000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy (unit src/staging/blk_004a0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_004a0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include "../../include/HitArray.h"
#include "../../include/NiPoint3.h"

struct __declspec(align(16)) ImpactVector4
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        float components[4];
    };
};
struct HitBody;
struct HitInfo
{
    ImpactVector4 normal;
    float fraction;
    int unk14, unk18, unk1c;
    unsigned int keys[8];
    int unk40, unk44, unk48, unk4c;
    HitBody* body;
    int unk54, unk58, unk5c;
};
struct FUN_004a3c20
{
    ImpactVector4 from, to;
    int filter, unk24, unk28, unk2c;
    ImpactVector4 normal;
    float fraction;
    int shapeKey, unk48, unk4c;
    unsigned int keys[8];
    int unk70, unk74, unk78, unk7c;
    HitBody* body;
    int unk84, unk88, unk8c;
    ImpactVector4 transform;
    int unkA0, unkA4, unkA8;
    bool flag;
    FUN_004a3c20();
    void bhkPickData_SetFilter(unsigned int);
    void bhkPickData_SetFrom(const NiPoint3&);
    void bhkPickData_SetTo(const NiPoint3&);
    void bhkPickData_SetAllCollector(void*);
    HitArray* DialoguePackage_GetCurrentDialogItem();
};
struct FUN_004a3a70
{
    unsigned int vtable;
    float earlyOut;
    int unk08, unk0c;
    unsigned int data;
    int size, capacity, unk1c;
    unsigned char hitStorage[8 * sizeof(HitInfo)];
    FUN_004a3a70();
    ~FUN_004a3a70();
};
struct FUN_008c71b0
{
    unsigned int value;
    FUN_008c71b0(unsigned int);
    void CFilter_SetLayer(int);
    unsigned int CFilter_GetGroup();
};
struct FUN_004a37b0
{
    NiPoint3 position, normal, tangent;
    int unk24;
    void* reference;
    int unk2c;
    void* texture;
    int unk34;
    float width, height, depth, lifetime;
    int unk48;
    float radius;
    int unk50;
    float parallax, shininess, scale;
    NiPoint3 color;
    int unk6c;
    unsigned char rotation, unk71, unk72, flag73, flag74, flag75, flag76, unk77;
    int unk78, unk7c;
    FUN_004a37b0();
};
struct World
{
    void** vtable;
};
struct Cell
{
    World* TESObjectCELL_GetbhkWorld();
};
struct Prompt
{
    void FUN_00476930(int, NiPoint3&);
};
struct Scene
{
    Prompt* NiAVObject_GetRotate_006a9540();
    NiPoint3& GetTranslate_0043c490();
};
struct Ref
{
    Cell* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    Scene* FUN_00490e40();
    float ActorPackage_GetPackageStartTime();
    float FUN_00488d50();
    Ref* NiAVObject_GetParent();
    void TESObjectCELL_AddDecal(FUN_004a37b0*, int, char);
};
struct RefHandle
{
    Ref* Modelloader_GetReferencedThis();
};
struct HitBody
{
    RefHandle shape;
    unsigned int hkpCollidable_getCollisionFilterInfo();
};
struct Shape
{
    unsigned int bhkShape_GetSubshapeMaterial(unsigned int);
};
struct ImpactData
{
    float GetModifierValue();
    float BGSImpactData_GetDecalMinWidth();
    void* FUN_006733e0();
    bool BGSImpactData_GetIsParallax();
    float FUN_004a41c0();
    bool BGSImpactData_GetParallaxPasses();
    bool CallMemberAtOffset54();
    bool BGSImpactData_GetIsAlphaBlend();
    float FUN_004a40e0();
    float TESCombatStyle_GetWeaponMinRangeMult();
    float FUN_00598040();
    unsigned int GetNextFromSubobject();
};
struct Gate
{
    bool MenuConsole_IsVisible();
};
Gate* __cdecl FUN_0071b160(int);
bool __cdecl IsStartMenuFlag1Set();
float __cdecl FUN_00476b70(float, float);
struct Splatter
{
    void FUN_006233c0(int);
    void DecalCaster_SetCollision(int, unsigned char);
    void DecalCaster_Add(World*);
};
Splatter* __cdecl FUN_00622a70(float, bool);
struct FloatSetting
{
    float* Setting_Float_00403e20();
};
struct IntSetting
{
    int* Setting_Int();
};
extern FloatSetting DAT_011c5818, DAT_011c584c;
extern IntSetting DAT_011c5868;
extern const float DAT_01017868, DAT_0101e578, DAT_01018f5c, DAT_0101e574, DAT_0101e570;
void* __cdecl MakeLine(const NiPoint3&, const NiColorA&, const NiPoint3&, const NiColorA&,
                           bool);
struct TESView
{
    void FUN_00458e20(void*, float);
    Ref* TES_GetLandGeometry(const NiPoint3&);
    Ref* TES_GetCellForPoint(NiPoint3);
};
extern TESView* g_TES;
Shape* __cdecl bhkShape_Getbhk(Ref*);
NiPoint3 __cdecl FUN_004a3760(float, const NiPoint3&);
NiPoint3& __cdecl HK2NINS(NiPoint3&, const ImpactVector4&);
Ref* __cdecl bhkUtilFunctions_GetNiAVObject(HitBody*);
void* __cdecl TESObjectREFR_FindReferenceFor3D(Ref*);
bool __cdecl IsAcousticSpaceFormTypeAllowed(void*, bool);
float __cdecl RandomFloatTwoPi();
float __cdecl FUN_00406cc0(float);
struct ImpactTask
{
    int remaining;
    bool finished;
    unsigned char unk05;
    unsigned short unk06;
    ImpactData* impact;
    RefHandle reference;
    void BGSDecalEmitter_Update();
};
// @fnv 0x004a2d50
// src: XBOX_PDB 0x004a2d50
void ImpactTask::BGSDecalEmitter_Update()
{
    if (FUN_0071b160(1)->MenuConsole_IsVisible() || IsStartMenuFlag1Set())
        return;
    if (!reference.Modelloader_GetReferencedThis()->GetHavokWorldObjectCountInSceneGraph_0084e3a0() || !reference.Modelloader_GetReferencedThis()->FUN_00490e40())
    {
        finished = true;
        return;
    }
    if (remaining > 0 && impact && reference.Modelloader_GetReferencedThis()->ActorPackage_GetPackageStartTime() <= reference.Modelloader_GetReferencedThis()->FUN_00488d50())
    {
        NiPoint3 direction;
        reference.Modelloader_GetReferencedThis()->FUN_00490e40()->NiAVObject_GetRotate_006a9540()->FUN_00476930(2, direction);
        direction.Unitize_004a0c10();
        NiPoint3 origin = reference.Modelloader_GetReferencedThis()->FUN_00490e40()->GetTranslate_0043c490();
        float radius = FUN_00476b70(impact->BGSImpactData_GetDecalMinWidth(), impact->GetModifierValue());
        Splatter* splatter = FUN_00622a70(radius, true);
        splatter->FUN_006233c0(0);
        splatter->DecalCaster_SetCollision(8, 0);
        splatter->DecalCaster_SetCollision(29, 0);
        Cell* cell = reference.Modelloader_GetReferencedThis()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        World* world = cell ? cell->TESObjectCELL_GetbhkWorld() : 0;
        FUN_004a3c20 ray;
        if (world)
        {
            splatter->DecalCaster_Add(world);
            float distance = *DAT_011c5818.Setting_Float_00403e20();
            NiPoint3 end = static_cast<const NiPoint3&>(origin).FUN_00439e90(direction.ApplyScaled(distance));
            end.x += FUN_00476b70(DAT_0101e578, DAT_01017868);
            end.y += FUN_00476b70(DAT_0101e578, DAT_01017868);
            end.z += FUN_00476b70(DAT_0101e578, DAT_01017868);
            float drop = -*DAT_011c584c.Setting_Float_00403e20() *
                         (reference.Modelloader_GetReferencedThis()->ActorPackage_GetPackageStartTime() / reference.Modelloader_GetReferencedThis()->FUN_00488d50());
            end.z += drop;
            if (*DAT_011c5868.Setting_Int() > 0)
            {
                void* line = MakeLine(origin, NiColorA(0, 1, 0, 1), end,
                                          NiColorA(0, 1, 1, 1), true);
                g_TES->FUN_00458e20(line, DAT_01018f5c);
            }
            FUN_008c71b0 filter(0);
            filter.CFilter_SetLayer(39);
            ray.bhkPickData_SetFilter(filter.value);
            ray.bhkPickData_SetFrom(origin);
            ray.bhkPickData_SetTo(end);
            FUN_004a3a70 collector;
            ray.bhkPickData_SetAllCollector(&collector);
            bool rayHit = ((bool(__thiscall*)(World*, FUN_004a3c20*))world->vtable[50])(world, &ray);
            int count = ray.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->FUN_00726070();
            bool placed = false;
            for (int hit = 0; !placed && hit < count; ++hit)
            {
                HitBody* body = ray.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->GetEntryAt(hit)->body;
                if (body)
                {
                    unsigned int key = -1;
                    for (int keyIndex = 0;
                         keyIndex < 8 && ray.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->GetEntryAt(hit)->keys[keyIndex] != -1;
                         ++keyIndex)
                    {
                        key = ray.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->GetEntryAt(hit)->keys[keyIndex];
                    }
                    Shape* shape = bhkShape_Getbhk(body->shape.Modelloader_GetReferencedThis());
                    if (!shape)
                        continue;
                    unsigned int material = shape->bhkShape_GetSubshapeMaterial(key);
                    void* texture = impact ? impact->FUN_006733e0() : 0;
                    if (!texture)
                        continue;
                    NiPoint3 position = static_cast<const NiPoint3&>(origin).FUN_00439e90(FUN_004a3760(
                        ray.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->GetEntryAt(hit)->fraction, static_cast<const NiPoint3&>(end).SubtractIntoVector(origin)));
                    NiPoint3 normal;
                    HK2NINS(normal, ray.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->GetEntryAt(hit)->normal);
                    bool landscape = FUN_008c71b0(body->hkpCollidable_getCollisionFilterInfo()).CFilter_GetGroup() == 1;
                    Ref* target = 0;
                    if (landscape)
                    {
                        target = g_TES->TES_GetLandGeometry(position);
                        if (target && target->NiAVObject_GetParent())
                            target = target->NiAVObject_GetParent();
                    }
                    else
                        target = bhkUtilFunctions_GetNiAVObject(body);
                    void* object = TESObjectREFR_FindReferenceFor3D(target);
                    if (!landscape && (!object || !IsAcousticSpaceFormTypeAllowed(object, true)))
                        continue;
                    Ref* owner = g_TES->TES_GetCellForPoint(position);
                    FUN_004a37b0 decal;
                    decal.position = position;
                    decal.normal = normal;
                    decal.width = radius;
                    decal.height = radius;
                    decal.depth = DAT_0101e574;
                    decal.lifetime = RandomFloatTwoPi();
                    decal.rotation = (unsigned char)(int)FUN_00406cc0(FUN_00476b70(0, DAT_0101e570));
                    decal.reference = target;
                    decal.texture = texture;
                    decal.flag73 = impact->BGSImpactData_GetIsParallax();
                    decal.radius = impact->FUN_004a41c0();
                    decal.flag76 = impact->BGSImpactData_GetParallaxPasses();
                    decal.flag74 = impact->CallMemberAtOffset54();
                    decal.flag75 = impact->BGSImpactData_GetIsAlphaBlend();
                    decal.parallax = impact->FUN_004a40e0();
                    decal.shininess = impact->TESCombatStyle_GetWeaponMinRangeMult();
                    decal.scale = impact->FUN_00598040();
                    decal.color =
                        NiPoint3((unsigned char)(impact->GetNextFromSubobject() & 255) / 255.0,
                                 (unsigned char)(((unsigned short)impact->GetNextFromSubobject() >> 8) & 255) / 255.0,
                                 (unsigned char)((impact->GetNextFromSubobject() >> 16) & 255) / 255.0);
                    owner->TESObjectCELL_AddDecal(&decal, 1, 0);
                    placed = true;
                }
            }
            if (placed)
                --remaining;
        }
    }
    else
        finished = true;
}

#include <xmmintrin.h>
struct FUN_004b4cf0_shell
{
    __m128* FUN_004b4cf0(unsigned int index);
};

struct FUN_004b4ab0_Class
{
    __m128 value;
    void hkVector4__setRotatedInverseDir(FUN_004b4cf0_shell* matrix, __m128* vector);
};

// @fnv 0x004b4ad0
// src: COMMUNITY 0x004b4ad0
void FUN_004b4ab0_Class::hkVector4__setRotatedInverseDir(FUN_004b4cf0_shell* matrix, __m128* vector)
{
    __m128 row0 = *matrix->FUN_004b4cf0(0);
    __m128 row1 = *matrix->FUN_004b4cf0(1);
    __m128 row2 = *matrix->FUN_004b4cf0(2);
    __m128 low = _mm_unpacklo_ps(row0, row1);
    __m128 high = _mm_shuffle_ps(_mm_unpackhi_ps(row0, row1), row2, 0xe4);
    row0 = _mm_movelh_ps(low, row2);
    row1 = _mm_shuffle_ps(_mm_movehl_ps(row0, low), row2, 0xd4);
    row2 = high;
    __m128 sx = _mm_shuffle_ps(*vector, *vector, 0);
    __m128 x = _mm_mul_ps(row0, sx);
    __m128 sy = _mm_shuffle_ps(*vector, *vector, 0x55);
    __m128 y = _mm_mul_ps(row1, sy);
    __m128 sz = _mm_shuffle_ps(*vector, *vector, 0xaa);
    __m128 z = _mm_mul_ps(row2, sz);
    value = _mm_add_ps(_mm_add_ps(x, y), z);
}
