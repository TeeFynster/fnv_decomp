
// src/fallout/ai/combat/projectile_gf_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy /GF (unit src/fallout/ai/combat/projectile.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include "../../../../include/NiPoint3.h"

// FUN_009c0d80 reconstruction WIP.
// Built on unverified prior work by "another contributor" (2026-10-24) and an earlier
// "you" attempt (2026-10-23); logic revalidated and conventions corrected under this
// claim by GLM (Z.ai), agent zai_coord_01. Credit for the overall control-flow
// reconstruction belongs to the prior contributors.
// Build flags: /MT /O2 /GS /EHsc /Gy. __cdecl, caller pops, 6 params.
struct __declspec(align(16)) PhysicsVector
{
    float x, y, z, w;
};
struct EventInfo
{
    PhysicsVector normal;  // 16
    float time;            // 0x10
    int unk14, unk18, unk1c;
    char indexBytes[32];  // 0x20..0x40
    int unk40, unk44, unk48, unk4c;
    int eventHandle;  // 0x50
    EventInfo* hkpWorldRayCastOutput_hkpWorldRayCastOutput_00696c30(EventInfo* entry);
    EventInfo* CopyRayCastResultAndRootCollidable(EventInfo* entry);
};
struct EventCursor
{
    int FUN_00726070();
    EventInfo* GetEntryAt(int index);
};
struct EventStream
{
    EventCursor* TESDataHandler_GetWorldSpaceList();
};
struct Filter
{
    unsigned int value;
};
struct FormBase
{
    int CFilter_GetLayer();
    bool FUN_009c19e0();
};
struct EventEntity
{
    void** vtable;
    FormBase* bhkWorldObject_GetCollisionFilter(unsigned int* out);
    void* BSFile_GetDevice();
};
struct Scene
{
    EventStream* DialoguePackage_GetCurrentDialogItem();
    void bhkPickData_NiGetFrom(NiPoint3* out);
    void bhkPickData_NiGetTo(NiPoint3* out);
    void bhkPickData_NiCalcHitPoint(NiPoint3* out);
    void bhkPickData_NiGetLength(NiPoint3* out);
    Filter* ConstructCF845(Filter* out);
};
// Ray-pick query, not Animation: ctor 0x004a3c20 and collector getter 0x008cdd90 match BhkPickData in bgsdecalmanager.cpp.
struct RayPickQuery
{
    EventStream* DialoguePackage_GetCurrentDialogItem();
    PhysicsVector rayOrigin, rayDirection;  // 0x00..0x20
    unsigned int filter;                    // 0x20
    unsigned int unk24, unk28, unk2c;
    EventInfo hit;                  // 0x30..0x84
    PhysicsVector cachedDirection;  // 0x90
    void* world;                    // 0xa0
    int unka4, unka8;
    bool unkac;
    RayPickQuery();
    void bhkPickData_SetFilter(unsigned int filterValue);
    void bhkPickData_SetFrom(NiPoint3* origin);
    void bhkPickData_SetLength(NiPoint3* direction);
    void bhkPickData_SetAllCollector(void* collector);
};
struct HitEntry
{
    EventInfo info;
};
struct HitCollection
{
    HitEntry* entries;
    int size, capacity, allocator;
    HitEntry inlineHits[8];
};
struct __declspec(align(16)) Collector
{
    void** vtable;
    float earlyOutFraction;
    int unk08, unk0c;
    HitCollection hits;  // 0x10.. ; total size 0x340
    Collector();
    void FUN_004a3bc0();
    ~Collector()
    {
        FUN_004a3bc0();
    }
};
struct SoundSource
{
    const char* TESSound_GetFilename();
};
struct RenderManager
{
    SoundSource* FUN_004fd3e0();
};
struct VisualNode
{
    NiPoint3* NiAVObject_GetWorldTranslate();
};
struct Controller
{
    void** vtable;
    RenderManager* FUN_004181e0();
    Controller* Sky_GetMode();
    bool Projectile_IsFlagSet(int);
    void Projectile_SetRange(float);
    void Projectile_SetMovementDelta(NiPoint3 point, bool flag);
    EventEntity* Projectile_GetShooter();
};
struct AudioPlaybackHandle
{
    unsigned int soundID;
    bool assumeSuccess;
    int state;
    void FUN_00483710();
    ~AudioPlaybackHandle()
    {
        FUN_00483710();
    }
    void FUN_00ad8b60(float, float, float);
    void FUN_00ad8830(int);
};
struct AudioSystem
{
    AudioPlaybackHandle BSAudio_GetSoundHandleByFilename(const char* path, int flags, SoundSource* source);
    void* TESMain_GetThread();
};
struct WorldTarget
{
    void** vtable;
};
struct Color
{
    float red, green, blue, alpha;
    void FUN_00414430(float, float, float, float);
};
struct RenderElement
{
    void UpdateProperties();
    void NiAVObject_SetTranslate(NiPoint3* at);
};
struct AudioController
{
    void FUN_00458e20(RenderElement* element, float volume);
};
struct FloatSetting
{
    int type;
    float value;
    float* Setting_Float_00403e20();
};
struct FormTypeDescriptor;
extern FormTypeDescriptor DAT_01268444;
extern AudioController* DAT_011dea10;
extern EventEntity* DAT_011dea3c;
extern unsigned char DAT_011f20a4;
extern FloatSetting DAT_011f210c;
extern float DAT_010162c0, DAT_01017870, DAT_0101712c;
extern double DAT_010231b0, DAT_01088210;
extern NiPoint3 DAT_011a9484;
extern int GetAVObjectForCollidable(int handle);
extern EventEntity* TESObjectREFR_FindReferenceFor3D(int handle);
extern int hkpGetPhantom(int handle);
extern EventEntity* bhkEntity_Getbhk(int form);
extern void Script_SetActionFlag(Controller* player, void* sound, int flags);
extern bool NiObject_IsKindOf(FormTypeDescriptor* descriptor, EventEntity* entity);
extern EventEntity* FindFirstCollisionObject(int handle);
struct ParentEntity : EventEntity
{
    EventEntity* bhkNiCollisionObject_GetWorldObject();
};
extern bool CanProjectileHit(EventEntity* reference, int eventHandle, Controller* player, int eventOwner);
extern bool Projectile_PickSceneGraph(RayPickQuery* packet, int handle, int arg3, int arg4);
extern void HK2NINS(NiPoint3* out, EventInfo* info);
extern AudioSystem* BSAudio_QInstance();
extern RenderElement* CreateOctahedron(float scale, Color* color, int arg3);
typedef int(__thiscall* GetKindFn)(EventEntity*);
typedef NiPoint3*(__thiscall* GetPositionFn)(EventEntity*);
typedef NiPoint3*(__thiscall* GetLocationFn)(WorldTarget*);
typedef VisualNode*(__thiscall* GetVisualFn)(Controller*);
typedef bool(__thiscall* DispatchFn)(Controller*, EventEntity*, NiPoint3*, NiPoint3*, int, int, int);
// @fnv 0x009c0d80
// src: XBOX_PDB 0x009c0d80
int __cdecl Projectile_ProcessTargetPick(Scene* scene, Controller* player, int eventOwner, float* hitTime, bool acceptUnknown,
                         float maximumTime)
{
    if (eventOwner == 0 && player != 0)
        eventOwner = (int)player->FUN_004181e0();
    bool picked = false;
    int result = 0;
    if (scene != 0 && scene->DialoguePackage_GetCurrentDialogItem() != 0)
    {
        NiPoint3 initialPosition;
        NiPoint3 initialDirection;
        scene->bhkPickData_NiGetFrom(&initialPosition);
        scene->bhkPickData_NiGetLength(&initialDirection);
        bool partialMatch = false;
        EventEntity* lastReference = 0;
        for (int i = 0; !picked && i < scene->DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->FUN_00726070(); ++i)
        {
            EventInfo info;
            info.hkpWorldRayCastOutput_hkpWorldRayCastOutput_00696c30(scene->DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->GetEntryAt(i));
            if (info.time > maximumTime)
                continue;
            int handle = GetAVObjectForCollidable(info.eventHandle);
            EventEntity* reference = TESObjectREFR_FindReferenceFor3D(handle);
            if (handle != 0)
            {
                bool candidate = true;
                int form = hkpGetPhantom(info.eventHandle);
                EventEntity* entity2 = form != 0 ? bhkEntity_Getbhk(form) : 0;
                if (entity2 != 0)
                {
                    candidate = false;
                    unsigned int filterA, filterB;
                    if (player != 0 && reference != 0 &&
                        (entity2->bhkWorldObject_GetCollisionFilter(&filterA)->CFilter_GetLayer() == 0x17 ||
                         entity2->bhkWorldObject_GetCollisionFilter(&filterB)->CFilter_GetLayer() == 0x18))
                    {
                        Script_SetActionFlag(player, reference->BSFile_GetDevice(), 0x80);
                        if (player->Sky_GetMode() != 0)
                            Script_SetActionFlag(player->Sky_GetMode(), reference->BSFile_GetDevice(), 0x100);
                    }
                    unsigned int filterC;
                    if (NiObject_IsKindOf(&DAT_01268444, entity2) ||
                        (acceptUnknown && entity2->bhkWorldObject_GetCollisionFilter(&filterC)->CFilter_GetLayer() == 0x1e))
                    {
                        partialMatch = true;
                        lastReference = reference;
                        {
                            ParentEntity* parentId = (ParentEntity*)FindFirstCollisionObject(handle);
                            EventEntity* parent2 = parentId != 0 ? parentId->bhkNiCollisionObject_GetWorldObject() : 0;
                            if (parent2 != 0)
                            {
                                unsigned int filterD;
                                if (parent2->bhkWorldObject_GetCollisionFilter(&filterD)->FUN_009c19e0() ||
                                    ((GetKindFn)parent2->vtable[0x94 / 4])(parent2) == 0)
                                {
                                    RayPickQuery pickQuery;
                                    NiPoint3 origin;
                                    scene->bhkPickData_NiGetFrom(&origin);
                                    NiPoint3 direction;
                                    scene->bhkPickData_NiGetLength(&direction);
                                    initialDirection *= DAT_010162c0;
                                    direction *= DAT_010162c0;
                                    Filter sceneFilter;
                                    pickQuery.bhkPickData_SetFilter(scene->ConstructCF845(&sceneFilter)->value);
                                    pickQuery.bhkPickData_SetFrom(&origin);
                                    pickQuery.bhkPickData_SetLength(&direction);
                                    Collector collector;
                                    pickQuery.bhkPickData_SetAllCollector(&collector);
                                    bool hit = Projectile_PickSceneGraph(&pickQuery, handle, 0, 1);
                                    if (hit)
                                    {
                                        if (pickQuery.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->FUN_00726070() > 0)
                                        {
                                            info.CopyRayCastResultAndRootCollidable(pickQuery.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->GetEntryAt(0));
                                            candidate = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            labelAfterPartial:
                if (!CanProjectileHit(reference, info.eventHandle, player, eventOwner))
                    candidate = false;
                if (candidate)
                {
                    if (player != 0)
                    {
                        NiPoint3 hitPoint = initialDirection * info.time;
                        NiPoint3 aimPoint = initialPosition + hitPoint;
                        NiPoint3 tempPoint;
                        HK2NINS(&tempPoint, &info);
                        if (player->Projectile_IsFlagSet(1))
                        {
                            player->Projectile_SetRange(hitPoint.Length());
                            player->Projectile_SetMovementDelta(hitPoint, false);
                        }
                        int lastIndex = -1;
                        for (int k = 0; k < 8 && reinterpret_cast<int*>(info.indexBytes)[k] != -1; ++k)
                        {
                            lastIndex = reinterpret_cast<int*>(info.indexBytes)[k];
                        }
                        picked = ((DispatchFn)player->vtable[0x32c / 4])(player, reference, &aimPoint, &tempPoint,
                                                                         info.eventHandle, lastIndex, 0x24);
                        if (picked)
                            result = handle;
                    }
                    else
                    {
                        picked = true;
                        result = handle;
                    }
                    if (picked && hitTime != 0)
                        *hitTime = info.time;
                }
            }
        }
        if (player != 0)
        {
            if (!picked)
            {
                if (maximumTime != DAT_010231b0)
                {
                    NiPoint3 away = initialDirection * maximumTime;
                    NiPoint3 dst = initialPosition + away;
                    if (player->Projectile_IsFlagSet(1))
                    {
                        player->Projectile_SetRange(away.Length());
                        player->Projectile_SetMovementDelta(away, false);
                    }
                    ((DispatchFn)player->vtable[0x32c / 4])(player, 0, &dst, &DAT_011a9484, 0, -1, 8);
                }
            }
            if (!picked && partialMatch)
            {
                if (lastReference != 0 && lastReference == DAT_011dea3c)
                {
                    NiPoint3 impact;
                    scene->bhkPickData_NiCalcHitPoint(&impact);
                    if (player->FUN_004181e0() != 0)
                    {
                        if (player->FUN_004181e0()->FUN_004fd3e0() != 0)
                        {
                            int flags = 0x102;
                            AudioPlaybackHandle sound =
                                BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(player->FUN_004181e0()->FUN_004fd3e0()->TESSound_GetFilename(),
                                                             flags, player->FUN_004181e0()->FUN_004fd3e0());
                            sound.FUN_00ad8b60(impact.x, impact.y, impact.z);
                            sound.FUN_00ad8830(0);
                            if (DAT_011f20a4 != 0 && ((GetVisualFn)player->vtable[0x1d0 / 4])(player) != 0)
                            {
                                Color color;
                                color.FUN_00414430(0.0f, 1.0f, 1.0f, DAT_01017870);
                                RenderElement* visual = CreateOctahedron(DAT_0101712c, &color, 1);
                                visual->UpdateProperties();
                                visual->NiAVObject_SetTranslate(((GetVisualFn)player->vtable[0x1d0 / 4])(player)->NiAVObject_GetWorldTranslate());
                                DAT_011dea10->FUN_00458e20(visual, *DAT_011f210c.Setting_Float_00403e20());
                            }
                        }
                    }
                }
            }
            else if (player->FUN_004181e0()->FUN_004fd3e0() != 0 &&
                     ((picked && lastReference != DAT_011dea3c) || !picked) && player->Projectile_GetShooter() != DAT_011dea3c &&
                     BSAudio_QInstance()->TESMain_GetThread() != 0)
            {
                NiPoint3 at, saved, direction, extra, position;
                WorldTarget* world = (WorldTarget*)BSAudio_QInstance()->TESMain_GetThread();
                position = *((GetLocationFn)world->vtable[3])(world);
                if (lastReference != 0)
                    saved = *((GetPositionFn)lastReference->vtable[0x1f4 / 4])(lastReference);
                else
                    scene->bhkPickData_NiGetTo(&saved);
                scene->bhkPickData_NiGetFrom(&at);
                direction = saved - at;
                extra = position - at;
                float mag = extra.Dot(direction);
                float len = direction.Dot(direction);
                float ratio = mag / len;
                NiPoint3 projected = at + ratio * direction;
                float distance = (position - projected).Length();
                if (distance < DAT_01088210)
                {
                    int flags = 0x102;
                    AudioPlaybackHandle sound =
                        BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(player->FUN_004181e0()->FUN_004fd3e0()->TESSound_GetFilename(), flags,
                                                     player->FUN_004181e0()->FUN_004fd3e0());
                    sound.FUN_00ad8b60(projected.x, projected.y, projected.z);
                    sound.FUN_00ad8830(0);
                    if (DAT_011f20a4 != 0)
                    {
                        Color color;
                        color.FUN_00414430(0.0f, 1.0f, 1.0f, DAT_01017870);
                        RenderElement* visual = CreateOctahedron(DAT_0101712c, &color, 1);
                        visual->UpdateProperties();
                        visual->NiAVObject_SetTranslate(&projected);
                        DAT_011dea10->FUN_00458e20(visual, *DAT_011f210c.Setting_Float_00403e20());
                    }
                }
            }
        }
    }
    return result;
}
