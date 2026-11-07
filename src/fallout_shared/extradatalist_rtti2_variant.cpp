// src/fallout_shared/extradatalist_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (BSExtraData). The skeleton of src/fallout_shared/extradatalist.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include <stddef.h>
#include "game_constants.h"
#include "../../include/ExtraDataList.h"
enum DIALOGUE_EMOTION;
enum SIT_SLEEP_STATE;
#include "../../include/Actor.h"
#include "../../include/AlchemyItem.h"
#include "../../include/ExtraLastFinishedSequence.h"
#include "../../include/ExtraAudioBuoyMarker.h"
#include "../../include/ExtraAudioMarker.h"
#include "../../include/ExtraFollower.h"
#include "../../include/ExtraHasNoRumors.h"
#include "../../include/ExtraHeadingTarget.h"
#include "../../include/ExtraInfoGeneralTopic.h"
#include "../../include/ExtraItemDropper.h"
#include "../../include/ExtraLeveledItem.h"
#include "../../include/ExtraMapMarker.h"
#include "../../include/ExtraPackage.h"
#include "../../include/ExtraPackageStartLocation.h"
#include "../../include/ExtraPersistentCell.h"
#include "../../include/ExtraPoison.h"
#include "../../include/ExtraReferencePointer.h"
#include "../../include/ExtraRunOncePacks.h"
#include "../../include/ExtraTeleport.h"
#include "../../include/ExtraTresPassPackage.h"
#include "../../include/NonActorMagicCaster.h"
#include "../../include/NonActorMagicTarget.h"
#include "../../include/SCaster.h"

namespace extra_save {

class SForm
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual bool vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual const char* vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13C();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14C();
    virtual void vf150();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    unsigned char FUN_0041ca90();
    void WriteScriptLocals();
    SForm* FUN_0054ddd0();
    void Save();
    unsigned char InterfaceManager_GetMenuMode();
    void SaveTopic();
};
struct Obj34
{
    int FUN_0040a1e0();
};
struct Obj44
{
    int RefreshItem();
};
struct ListItem
{
    SForm* form;
    char flag;
};
// Exe 0x004235e0 SaveShell::FUN_004235e0: opaque package-list accessor view.

struct FormNode
{
    bool FUN_008256d0();
    SForm** FUN_006815c0();
    FormNode* FUN_00726070();
};
struct LockSaveData
{
    unsigned char level;
    SForm* key;
    unsigned char flags;
};
struct GenericExtra : public ::BSExtraData
{
    unsigned char TESRegionData_GetOverride();
    GenericExtra* FUN_0044ddc0();
    union
    {
        short s;
        float f;
        char c;
        int i;
        SForm* form;
        LockSaveData* p;
    } d;
    union
    {
        SForm* form;
        int i;
    } d10;
};
struct FormIDEntry
{
    unsigned int formID;
    unsigned char recordType;
    unsigned char changeFlags[4];
};

struct SSaveGame
{
    unsigned int FUN_00825c00();
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_SaveGameDataOLD(void* data, int size);
    void TESSaveLoadGame_SaveNumericID(void* data, int size);
    unsigned char FUN_008df040();
    FormIDEntry* FUN_004fd3e0();
};
struct DebugFlag
{
    bool* FUN_00408d60();
};
struct SaveLock
{
    void BSSpinLock_Lock(int a);
    void BSSpinLock_Unlock();
};
struct PackageMgr
{
    bool FUN_00469860(unsigned int id);
};

extern SSaveGame* DAT_011de45c;
extern DebugFlag DAT_011de4e8;
extern SaveLock DAT_011c3920;
extern PackageMgr* DAT_011c3f2c;
void __cdecl ProgramFlow(const char* fmt, ...);
void __cdecl Warning_005b5e40(const char* fmt, ...);
SForm* __cdecl TESForm_GetFormByNumericID(unsigned int id);
unsigned char __cdecl BSstrlen(char* s);
void __cdecl ActiveEffect_SaveActiveEffectList(void* p, int a);

struct SaveShell : public ExtraDataList
{
    void ExtraDataList_SaveGameTES(unsigned int flags, SForm* form);
};

}
namespace extra_save {

// @fnv 0x004235e0
// src: COMMUNITY 0x004235e0
void SaveShell::ExtraDataList_SaveGameTES(unsigned int flags, SForm* form)
{
    unsigned int blkA4;
    GenericExtra* extra;
    unsigned int cnt;
    short zero;
    unsigned int kPosB;
    short count9;
    int tagA2;

    zero = 0;
    blkA4 = 0;
    kPosB = DAT_011de45c->FUN_00825c00();
    if (*DAT_011de4e8.FUN_00408d60())
    {
        kPosB = DAT_011de45c->FUN_00825c00();
    }
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        tagA2 = 0x424c4f4b;
        DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&tagA2, 4);
        blkA4 = DAT_011de45c->FUN_00825c00();
        DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&zero, 2);
    }
    DAT_011c3920.BSSpinLock_Lock(0);
    count9 = 0;
    cnt = DAT_011de45c->FUN_00825c00();
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&count9, 2);
    extra = (GenericExtra*)pHead;
    while (extra)
    {
        unsigned char type = extra->TESRegionData_GetOverride();
        unsigned int before = DAT_011de45c->FUN_00825c00();
        switch (extra->TESRegionData_GetOverride())
        {
        case 36:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                short v = extra->d.s;
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&v, 2);
            }
            break;
        case 37:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                float v = extra->d.f;
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&v, 4);
            }
            break;
        case 38:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                char v = extra->d.c;
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&v, 1);
            }
            break;
        case 141:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                char v = extra->d.c;
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&v, 1);
            }
            break;
        case 39:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                float v = extra->d.f;
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&v, 4);
            }
            break;
        case 40:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                float v = extra->d.f;
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&v, 4);
            }
            break;
        case 42:
            if (flags & 0x1000)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                LockSaveData* p = extra->d.p;
                unsigned int iD = 0;
                if (p->key)
                {
                    iD = p->key->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                }
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(p, 1);
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&iD, 4);
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&p->flags, 1);
            }
            break;
        case 48:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                float v = extra->d.f;
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&v, 4);
            }
            break;
        case 33:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                unsigned int id = extra->d.form->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&id, 4);
            }
            break;
        case 34:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                unsigned int id = extra->d.form->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&id, 4);
            }
            break;
        case 35:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                int v = extra->d.i;
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&v, 4);
            }
            break;
        case 22:
        case 23:
        case 62:
        case 71:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
            }
            break;
        case 31:
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
            break;
        case 13:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                unsigned int id = extra->d.form->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                SForm* kObj = extra->d10.form;
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&id, 4);
                kObj->WriteScriptLocals();
            }
            break;
        case 47:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ::ExtraLeveledItem* x = dynamic_cast< ::ExtraLeveledItem*>((::BSExtraData*)extra);
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&x->iIndex, 4);
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&x->m_bIsLeveledItem, 1);
            }
            break;
        case 25: {
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
            ExtraPackage* x = dynamic_cast< ::ExtraPackage*>((::BSExtraData*)extra);
            unsigned int id = x->package->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            unsigned int iD8 = 0;
            if (x->form14)
            {
                iD8 = x->form14->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            }
            DAT_011de45c->TESSaveLoadGame_SaveNumericID(&id, 4);
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&x->unk10, 4);
            DAT_011de45c->TESSaveLoadGame_SaveNumericID(&iD8, 4);
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&x->unk18, 1);
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&x->unk19, 1);
            if (DAT_011de45c->FUN_008df040() >= 0x40 && DAT_011c3f2c->FUN_00469860(id))
            {
                unsigned char b = x->package->FUN_0041ca90();
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&b, 1);
                ((SForm*)x->package)->vf150();
            }
            break;
        }
        case 26:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ExtraTresPassPackage* x =
                    dynamic_cast< ::ExtraTresPassPackage*>((::BSExtraData*)extra);
                unsigned int id = 0;
                if (x->package)
                {
                    id = ((SForm*)x->package)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                }
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&id, 4);
                if (x->package)
                {
                    ((SForm*)x->package)->vf150();
                }
            }
            break;
        case 28:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ::ExtraReferencePointer* x = dynamic_cast< ::ExtraReferencePointer*>((::BSExtraData*)extra);
                unsigned int id = x->ref->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&id, 4);
            }
            break;
        case 46:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
            }
            break;
        case 27: {
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
            short n = 0;
            unsigned int pos2 = DAT_011de45c->FUN_00825c00();
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&n, 2);
            ExtraRunOncePacks* x = dynamic_cast< ::ExtraRunOncePacks*>((::BSExtraData*)extra);
            ExtraSavePackageListView* kIter = x->list;
            while (kIter && !kIter->IsEmpty())
            {
                ListItem* item = kIter->GetItem();
                if (item)
                {
                    unsigned int id = item->form->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                    DAT_011de45c->TESSaveLoadGame_SaveNumericID(&id, 4);
                    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&item->flag, 1);
                    n++;
                }
                kIter = kIter->GetNext();
            }
            *(short*)pos2 = n;
            break;
        }
        case 24: {
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
            ::ExtraPackageStartLocation* x = dynamic_cast< ::ExtraPackageStartLocation*>((::BSExtraData*)extra);
            unsigned int iD = 0;
            if (x->loc)
            {
                iD = x->loc->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            }
            else
            {
                Warning_005b5e40("SAVELOAD: Saving package start location on %08X %s, but the location is NULL.",
                             form->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), form->vf130());
            }
            DAT_011de45c->TESSaveLoadGame_SaveNumericID(&iD, 4);
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(x->pos, 0xc);
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&x->unk1C, 4);
            break;
        }
        case 29: {
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
            ::ExtraFollower* x = dynamic_cast< ::ExtraFollower*>((::BSExtraData*)extra);
            short n = 0;
            unsigned int pos2 = DAT_011de45c->FUN_00825c00();
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&n, 2);
            FormNode* kIter = (FormNode*)x->list;
            while (kIter && !kIter->FUN_008256d0())
            {
                SForm* f = *kIter->FUN_006815c0();
                if (f)
                {
                    unsigned int id = f->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                    DAT_011de45c->TESSaveLoadGame_SaveNumericID(&id, 4);
                    n++;
                }
                kIter = kIter->FUN_00726070();
            }
            *(short*)pos2 = n;
            break;
        }
        case 50:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ::NonActorMagicCaster* X = dynamic_cast< ::NonActorMagicCaster*>((::BSExtraData*)extra);
                int a = 0;
                if (X->GetSelectedMagicItem())
                {
                    a = ((Obj34*)X->GetSelectedMagicItem())->FUN_0040a1e0();
                }
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&a, 4);
                int b = 0;
                if (X->GetCurrentMagicTarget())
                {
                    b = ((Obj44*)X->GetCurrentMagicTarget())->RefreshItem();
                }
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&b, 4);
                unsigned int c = 0;
                if (X->GetCasterReference())
                {
                    c = X->GetCasterReference()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                }
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&c, 4);
            }
            break;
        case 51:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ::NonActorMagicTarget* x = dynamic_cast< ::NonActorMagicTarget*>((::BSExtraData*)extra);
                unsigned int iD = 0;
                if (x->GetMagicTargetReference())
                {
                    iD = x->GetMagicTargetReference()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                }
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&iD, 4);
                ActiveEffect_SaveActiveEffectList(x->GetActiveEffectList(), 0);
            }
            break;
        case 43:
            if (flags & 0x20000)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ::ExtraTeleport* x = dynamic_cast< ::ExtraTeleport*>((::BSExtraData*)extra);
                ((SForm*)x->data)->Save();
            }
            break;
        case 63:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ::ExtraPoison* x = dynamic_cast< ::ExtraPoison*>((::BSExtraData*)extra);
                unsigned int iD = ((SForm*)x->poison)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&iD, 4);
            }
            break;
        case 65:
            if (flags & 0x10000000)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ::ExtraLastFinishedSequence* x = dynamic_cast< ::ExtraLastFinishedSequence*>((::BSExtraData*)extra);
                unsigned char len = BSstrlen(x->name);
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&len, 1);
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(x->name, len);
            }
            break;
        case 44:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ::ExtraMapMarker* x = dynamic_cast< ::ExtraMapMarker*>((::BSExtraData*)extra);
                unsigned char b = ((SForm*)x->data)->InterfaceManager_GetMenuMode();
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&b, 1);
            }
            break;
        case 144:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ::ExtraAudioMarker* x = dynamic_cast< ::ExtraAudioMarker*>((::BSExtraData*)extra);
            }
            break;
        case 145:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ::ExtraAudioBuoyMarker* x = dynamic_cast< ::ExtraAudioBuoyMarker*>((::BSExtraData*)extra);
            }
            break;
        case 12:
            if (form && form->vf100())
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                ExtraPersistentCell* x =
                    dynamic_cast< ::ExtraPersistentCell*>((::BSExtraData*)extra);
                unsigned int iD = 0;
                if (x->cell)
                {
                    iD = ((SForm*)x->cell)->FUN_0054ddd0()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                }
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&iD, 4);
            }
            break;
            break;
        case 57: {
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
            ::ExtraItemDropper* x = dynamic_cast< ::ExtraItemDropper*>((::BSExtraData*)extra);
            unsigned int id = 0;
            if (x->dropper)
            {
                id = x->dropper->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            }
            DAT_011de45c->TESSaveLoadGame_SaveNumericID(&id, 4);
            break;
            break;
        }
        case 70: {
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
            ExtraHeadingTarget* x = dynamic_cast< ::ExtraHeadingTarget*>((::BSExtraData*)extra);
            unsigned int id = 0;
            if (x->target)
            {
                id = x->target->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            }
            DAT_011de45c->TESSaveLoadGame_SaveNumericID(&id, 4);
            break;
        }
        case 73:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                unsigned int id = extra->d.form->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&id, 4);
            }
            break;
        case 74:
            if (flags & 0)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                char v = extra->d.c;
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&v, 1);
            }
            break;
        case 77: {
            ::ExtraInfoGeneralTopic* x = dynamic_cast< ::ExtraInfoGeneralTopic*>((::BSExtraData*)extra);
            if (x->topic)
            {
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
                x->topic->SaveTopic();
            }
            break;
        }
        case 78: {
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&type, 1);
            ::ExtraHasNoRumors* x = dynamic_cast< ::ExtraHasNoRumors*>((::BSExtraData*)extra);
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&x->value, 1);
        }
        }
        if (before != DAT_011de45c->FUN_00825c00())
        {
            count9++;
        }
        extra = extra->FUN_0044ddc0();
    }
    *(short*)cnt = count9;
    if (*DAT_011de4e8.FUN_00408d60())
    {
        unsigned int endPos = DAT_011de45c->FUN_00825c00();
        FormIDEntry* hdr = DAT_011de45c->FUN_004fd3e0();
        if (hdr)
        {
            SForm* f = TESForm_GetFormByNumericID(hdr->formID);
            ProgramFlow("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         endPos - kPosB, hdr->formID, f->vf130(), *(int*)hdr->changeFlags, 0x2c1f,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ExtraDataList.cpp");
        }
        else
        {
            ProgramFlow("SaveGame(): %-5i ending at line %i in file %s", endPos - kPosB, 0x2c1f,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ExtraDataList.cpp");
        }
    }
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int _end = DAT_011de45c->FUN_00825c00();
        unsigned int blk = blkA4;
        if (_end > blk + 0xffff)
        {
            Warning_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ExtraDataList.cpp", 0x2c1f);
        }
        *(short*)blkA4 = (short)(_end - blk);
    }
    DAT_011c3920.BSSpinLock_Unlock();
}

}

namespace load_extra_fixup {
class R;
class H
{
  public:
    void ExtraDataList_SetItemDropper();
    void ExtraDataList_AddDroppedItem();
};
class O;
class G
{
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual void g28();
    virtual void g29();
    virtual void g30();
    virtual void g31();
    virtual void g32();
    virtual void g33();
    virtual void g34();
    virtual void g35();
    virtual void g36();
    virtual void g37();
    virtual void g38();
    virtual void g39();
    virtual void g40();
    virtual void g41();
    virtual void g42();
    virtual void g43();
    virtual void g44();
    virtual void g45();
    virtual void g46();
    virtual void g47();
    virtual void g48();
    virtual void g49();
    virtual void g50();
    virtual void g51();
    virtual void g52();
    virtual void g53();
    virtual void g54();
    virtual void g55();
    virtual void g56();
    virtual void g57();
    virtual void g58();
    virtual void g59();
    virtual void g60();
    virtual void g61();
    virtual void g62();
    virtual void g63();
    virtual void g64();
    virtual void g65();
    virtual void g66();
    virtual void g67();
    virtual void g68();
    virtual void g69();
    virtual void g70();
    virtual void g71();
    virtual void g72();
    virtual void g73();
    virtual void g74();
    virtual void g75();
    virtual void g76();
    virtual void g77();
    virtual void g78();
    virtual void g79();
    virtual void g80();
    virtual void g81();
    virtual void g82();
    virtual void g83();
    virtual void g84();
    virtual void g85();
    virtual void v86();
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void ComputePackageFlags(G*);
    bool FUN_008256d0();
    G** FUN_006815c0();
    void FUN_0063f7b0();
    void FUN_00726c60(G**);
    G* FUN_00726070();
    void RemoveMatchingItem(R* const&);
    H* BSFile_GetDevice(O*);
    void DoorTeleportData_InitLoadGame();
};
class R
{
  public:
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    G* script;
};
class O
{
  public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual void o7();
    virtual void o8();
    virtual void o9();
    virtual void o10();
    virtual void o11();
    virtual void o12();
    virtual void o13();
    virtual void o14();
    virtual void o15();
    virtual void o16();
    virtual void o17();
    virtual void o18();
    virtual void o19();
    virtual void o20();
    virtual void o21();
    virtual void o22();
    virtual void o23();
    virtual void o24();
    virtual void o25();
    virtual void o26();
    virtual void o27();
    virtual void o28();
    virtual void o29();
    virtual void o30();
    virtual void o31();
    virtual void o32();
    virtual void o33();
    virtual void o34();
    virtual void o35();
    virtual void o36();
    virtual void o37();
    virtual void o38();
    virtual void o39();
    virtual void o40();
    virtual void o41();
    virtual void o42();
    virtual void o43();
    virtual void o44();
    virtual void o45();
    virtual void o46();
    virtual void o47();
    virtual void o48();
    virtual void o49();
    virtual void o50();
    virtual void o51();
    virtual void o52();
    virtual void o53();
    virtual void o54();
    virtual void o55();
    virtual void o56();
    virtual void o57();
    virtual void o58();
    virtual void o59();
    virtual void o60();
    virtual void o61();
    virtual void o62();
    virtual void o63();
    virtual bool v64();
    R* FUN_004181e0();
};
class E
{
  public:
    void* vt;
    int unk04;
    int unk08;
    G* m0c;
    int unk10;
    G* m14;
};
// The shared classes omit these reference setters; inherit their layouts and
// declare only the missing nonvirtual methods here.
class CasterReferenceSetter : public NonActorMagicCaster
{
  public:
    void FUN_0050f9c0(TESObjectREFR*);
};
class TargetReferenceSetter : public NonActorMagicTarget
{
  public:
    void FUN_0050f9a0(TESObjectREFR*);
};
class LMgr
{
  public:
    bool FUN_00469860(int);
};
class GameQ
{
  public:
    unsigned char FUN_008df040();
};
extern LMgr* DAT_011c3f2c;
extern GameQ* DAT_011de45c;
extern char DAT_01183028;
extern char DAT_01183254;
extern char DAT_011841cc;
extern char DAT_011830cc;
extern char DAT_011846d4;
extern char DAT_01183b2c;
extern char DAT_01184638;
extern char DAT_0118444c;
void* FUN_00ec43fb(void*, int, void*, void*, int);
TESForm* TESForm_GetFormByNumericID(G*);
int FUN_0040a250(G*);
int FUN_00825550(G*);
void ActiveEffect_InitLoadGameActiveEffectList(int, int);
class ListQ
{
  public:
    void* vt;
    int unk04;
    int unk08;
    G* m0c;
};
class ThisQ
{
  public:
    E* BaseExtraList_GetExtraData(int);
    void BaseExtraList_RemoveExtra_00410140(int);
    void ExtraDataList_RemoveReferencePointer();
    void FUN_00419d10(G*);
    ListQ* ExtraDataList_GetFollowerExtra();
    G* ExtraDataList_GetTeleport();
    G* ExtraDataList_GetDroppedItemList();
    G* ExtraDataList_GetItemDropper();
    void ExtraDataList_SetItemDropper(G*);
    G* ExtraDataList_GetHeadTrackTargetExtra();
    void ExtraDataList_SetHeadTrackTargetExtra(G*);
    void ExtraDataList_InitLoadGame(unsigned int a1, int a2, O* a3, void* a4);
};
// @fnv 0x00426020
// src: XBOX_PDB 0x00426020
void ThisQ::ExtraDataList_InitLoadGame(unsigned int a1, int a2, O* a3, void* a4)
{
    bool b = false;
    {
        G* v;
        if (a3 && a3->v64())
            b = true;
        if (a1 & 0)
        {
            E* e = BaseExtraList_GetExtraData(0xd);
            if (e && a4)
            {
                G* c = (G*)FUN_00ec43fb(a4, 0, &DAT_01183028, &DAT_01183254, 0);
                if (b)
                {
                    R* t;
                    O* r = a3;
                    t = r->FUN_004181e0();
                    if (t)
                        c = t ? (G*)&t->script : 0;
                }
                int id = 0;
                if (e->m0c)
                    id = e->m0c->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                if (c)
                {
                    if (!c->FUN_00726070() || c->FUN_00726070()->GetHavokWorldObjectCountInSceneGraph_0084e3a0() != id)
                        BaseExtraList_RemoveExtra_00410140(0xd);
                }
            }
        }
        if (a1 & 0)
        {
            E* e2 = BaseExtraList_GetExtraData(0x1c);
            if (e2)
            {
                G* f2 = e2->m0c;
                e2->m0c = (G*)dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(f2));
                if (!e2->m0c)
                    ExtraDataList_RemoveReferencePointer();
            }
        }
        if (a1 & 0)
        {
            E* e3 = BaseExtraList_GetExtraData(0x3f);
            if (e3)
            {
                G* f3 = e3->m0c;
                G* c3 = (G*)dynamic_cast<AlchemyItem*>(TESForm_GetFormByNumericID(f3));
                if (c3)
                    FUN_00419d10(c3);
            }
        }
        if (b)
        {
            E* e4 = BaseExtraList_GetExtraData(0x19);
            if (e4)
            {
                if (DAT_011c3f2c->FUN_00469860(e4->m0c->GetHavokWorldObjectCountInSceneGraph_0084e3a0()))
                    e4->m0c->v86();
                if (e4->m14)
                {
                    G* f4 = e4->m14;
                    e4->m14 = (G*)dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(f4));
                }
                e4->m0c->ComputePackageFlags(e4->m14);
            }
            if (a1 & 0)
            {
                E* e5 = BaseExtraList_GetExtraData(0x1a);
                if (e5 && e5->m0c)
                    e5->m0c->v86();
            }
            ListQ* l = ExtraDataList_GetFollowerExtra();
            if (l)
            {
                G* n = l->m0c;
                while (n && !n->FUN_008256d0())
                {
                    G* c6;
                    G* f6 = 0;
                    c6 = *n->FUN_006815c0();
                    if (c6)
                        f6 = (G*)dynamic_cast<Actor*>(TESForm_GetFormByNumericID(c6));
                    if (!f6)
                        n->FUN_0063f7b0();
                    else
                    {
                        n->FUN_00726c60(&f6);
                        n = n->FUN_00726070();
                    }
                }
            }
        }
        else if (!b)
        {
            if (a1 & 0)
            {
                NonActorMagicCaster* x = dynamic_cast<NonActorMagicCaster*>((BSExtraData*)BaseExtraList_GetExtraData(0x32));
                if (x)
                {
                    G* v5c = (G*)x->GetSelectedMagicItem();
                    G* v60 = (G*)x->GetCurrentMagicTarget();
                    G* v58 = (G*)x->GetCasterReference();
                    if (v5c)
                        x->SetSelectedMagicItem((MagicItem*)FUN_0040a250(v5c));
                    if (v60)
                        x->SetMagicTarget((MagicTarget*)FUN_00825550(v60));
                    if (v58)
                        ((CasterReferenceSetter*)x)->FUN_0050f9c0(dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(v58)));
                }
                NonActorMagicTarget* y = dynamic_cast<NonActorMagicTarget*>((BSExtraData*)BaseExtraList_GetExtraData(0x33));
                if (y)
                {
                    G* v64 = (G*)y->GetMagicTargetReference();
                    if (v64)
                        ((TargetReferenceSetter*)y)->FUN_0050f9a0(dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(v64)));
                    ActiveEffect_InitLoadGameActiveEffectList((int)y->GetActiveEffectList(), 0);
                }
            }
            if (a1 & 0x20000)
            {
                G* h = ExtraDataList_GetTeleport();
                h->DoorTeleportData_InitLoadGame();
            }
        }
        if (DAT_011de45c->FUN_008df040() < 0x46)
        {
            G* n7 = ExtraDataList_GetDroppedItemList();
            G* prev = 0;
            while (n7 && !n7->FUN_008256d0())
            {
                G* f7 = *n7->FUN_006815c0();
                G* c7 = f7;
                if (c7)
                    f7 = (G*)dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(c7));
                if (!f7)
                {
                    if (!prev)
                    {
                        n7->FUN_0063f7b0();
                        if (n7->FUN_008256d0())
                            n7 = 0;
                    }
                    else
                    {
                        prev->RemoveMatchingItem((R*)c7);
                        n7 = prev->FUN_00726070();
                    }
                }
                else
                {
                    n7->FUN_00726c60(&f7);
                    f7->BSFile_GetDevice(a3)->ExtraDataList_SetItemDropper();
                    prev = n7;
                    n7 = n7->FUN_00726070();
                }
            }
        }
        if (DAT_011de45c->FUN_008df040() >= 0x46)
        {
            G* f8 = ExtraDataList_GetItemDropper();
            if (f8)
            {
                G* c8 = (G*)dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(f8));
                ExtraDataList_SetItemDropper(c8);
                if (c8)
                    c8->BSFile_GetDevice(a3)->ExtraDataList_AddDroppedItem();
            }
        }
        v = ExtraDataList_GetHeadTrackTargetExtra();
        if (v)
        {
            G* f9 = v;
            v = (G*)dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(f9));
            ExtraDataList_SetHeadTrackTargetExtra(v);
        }
    }
}

}
