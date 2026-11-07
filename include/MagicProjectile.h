#pragma once

#include "MobileObject.h"
#include "NiPoint3.h"
#include <stddef.h>

class BCaster_S;
class Caster807;
class EffectItem;
class EffectSetting;
class MagicCaster;
class MagicItem;
class ProjectileCell;
class SceneNode;

class MagicProjectile : public MobileObject
{
public:
    struct NodePointer
    {
        SceneNode* value;
        operator SceneNode*() const;
        NodePointer& operator=(SceneNode*);
    };

    struct AudioPlaybackHandle
    {
        unsigned int soundID;
        unsigned int state;
        unsigned int flags;
        AudioPlaybackHandle& operator=(const AudioPlaybackHandle&);
        bool FUN_00ad8ce0();
        void FUN_00ad8d10();
        bool FUN_00ad8b60(float x, float y, float z);
        void FUN_00ad8f20(SceneNode*);
        bool FUN_00ad8830(bool);
    };

    int unk88;
    int unk8C;
    int unk90;
    MagicCaster* m_magicCaster;
    MagicItem* m_magicItem;
    EffectItem* m_effectItem;
    EffectSetting* m_avEffect;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    NodePointer nodeB4;
    int unkB8;
    NodePointer spineNode;
    NodePointer soundNode;
    TESObjectREFR* sourceReference;
    AudioPlaybackHandle sound;
    unsigned char unkD4[0x7C];

    MagicProjectile();
    virtual ~MagicProjectile();

    virtual void OnHit(NiPoint3 kPos, void* pvTarget, TESObjectREFR* pkRef, int iFlags);
    virtual void v308();
    virtual bool IsActive();
    virtual void V196();
    virtual void UpdateCaster(BCaster_S* caster);
    virtual void vf198();
    virtual void vf199();

    unsigned short GetSaveRecordSize(unsigned int);
    void SaveGame_0081e8c0(unsigned int);
    void LoadGame_0081e980(unsigned int, unsigned int);
    void ResolveMagicReferences(unsigned int, unsigned int);
    void ResolveMagicReferences(int arg1, int arg2);
    void InitEffect();
    ProjectileCell* GetParentCell();
    void InitializeProjectile(int arg1, int arg2);
    Caster807* GetCaster();
    void Process(BGSLoadFormBuffer*);
    void Process(float);
    void Process(int);
    void KillAreaEffectGeometry();
    void TESObjectREFR_Set3DSimple(SceneNode*);
    EffectSetting* GetAVEffect();
};

typedef char MagicProjectile_size_check[(sizeof(MagicProjectile) == 0x150) ? 1 : -1];
typedef char MagicProjectile_unk88_offset_check[(offsetof(MagicProjectile, unk88) == 0x88) ? 1 : -1];
typedef char MagicProjectile_unk8C_offset_check[(offsetof(MagicProjectile, unk8C) == 0x8C) ? 1 : -1];
typedef char MagicProjectile_unk90_offset_check[(offsetof(MagicProjectile, unk90) == 0x90) ? 1 : -1];
typedef char MagicProjectile_caster_offset_check[(offsetof(MagicProjectile, m_magicCaster) == 0x94) ? 1 : -1];
typedef char MagicProjectile_item_offset_check[(offsetof(MagicProjectile, m_magicItem) == 0x98) ? 1 : -1];
typedef char MagicProjectile_effect_item_offset_check[(offsetof(MagicProjectile, m_effectItem) == 0x9C) ? 1 : -1];
typedef char MagicProjectile_effect_offset_check[(offsetof(MagicProjectile, m_avEffect) == 0xA0) ? 1 : -1];
typedef char MagicProjectile_unkA4_offset_check[(offsetof(MagicProjectile, unkA4) == 0xA4) ? 1 : -1];
typedef char MagicProjectile_unkA8_offset_check[(offsetof(MagicProjectile, unkA8) == 0xA8) ? 1 : -1];
typedef char MagicProjectile_unkAC_offset_check[(offsetof(MagicProjectile, unkAC) == 0xAC) ? 1 : -1];
typedef char MagicProjectile_unkB0_offset_check[(offsetof(MagicProjectile, unkB0) == 0xB0) ? 1 : -1];
typedef char MagicProjectile_node_offset_check[(offsetof(MagicProjectile, nodeB4) == 0xB4) ? 1 : -1];
typedef char MagicProjectile_unkB8_offset_check[(offsetof(MagicProjectile, unkB8) == 0xB8) ? 1 : -1];
typedef char MagicProjectile_spine_offset_check[(offsetof(MagicProjectile, spineNode) == 0xBC) ? 1 : -1];
typedef char MagicProjectile_sound_node_offset_check[(offsetof(MagicProjectile, soundNode) == 0xC0) ? 1 : -1];
typedef char MagicProjectile_source_offset_check[(offsetof(MagicProjectile, sourceReference) == 0xC4) ? 1 : -1];
typedef char MagicProjectile_sound_offset_check[(offsetof(MagicProjectile, sound) == 0xC8) ? 1 : -1];
typedef char MagicProjectile_unkD4_offset_check[(offsetof(MagicProjectile, unkD4) == 0xD4) ? 1 : -1];
