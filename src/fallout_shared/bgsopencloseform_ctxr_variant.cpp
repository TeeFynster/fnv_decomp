
// Open/close activation handler (0x0047a560).
#include "../../include/BGSOpenCloseForm.h"
#include "../../include/ExtraDataList.h"
#include "../../include/LowProcess.h"
#include "../../include/Setting.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiControllerSequence.h"
#include "../../include/NiNode.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiUpdateData.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectDOOR.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/NiPoint3.h"
#include "bgsopencloseform_packet_decls.h"

class SoundH
{
  public:
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0(unsigned int);
};
class BSAudio;
class BSAudioSoundHandle;
class BSAudioS_
{
  public:
    static BSAudio* GetSingleton();
};
class BSAudio2
{
  public:
    BSAudioSoundHandle GetSoundHandleByFormID_00ad73b0(unsigned int);
};
class TaskQ2
{
  public:
    void QueueTaskIfPresent(void*);
};
class RefX
{
  public:
    void SetQuickKeysEnabled(int);
};
extern Setting DAT_011c4c64;

class BSAudioSoundHandle
{
  public:
    int m0;
    unsigned char m4;
    int m8;
    BSAudioSoundHandle();
    ~BSAudioSoundHandle();
    void ExtraDataList_GetSound(const void*);
    bool Play(bool);
    bool FUN_00ad8b60(float, float, float);
};

extern TESObjectREFR* _g_thePlayer;
BGSOpenCloseForm* GetOpenCloseForm(TESForm*);
// Folded accessor at 0x00407840; the shared door has no secondary-sound getter.
TESSound* __fastcall GetDoorSecondarySound(TESObjectDOOR*);
// The original SetLinkedReference call passes the list in ECX and the reference
// on the stack. A value aggregate keeps the latter argument on the stack under
// MSVC fastcall; the shared ExtraDataList does not declare this method.
struct LinkedReferenceArgument
{
    TESObjectREFR* reference;
};
void __fastcall SetLinkedReference(ExtraDataList*, LinkedReferenceArgument);
bool AILinearTaskThreadManager_ShouldQueue3DTask();
void bhkWorld_Activate(NiAVObject*, bool, bool, int);
void bhkWorld_RemoveObjects(void*, bool, bool);
NiFixedString& FUN_0047a500();
NiFixedString& FUN_0047a510();

// @fnv 0x0047a560
// src: XBOX_PDB 0x0047a560
void BGSOpenCloseForm_HandleActivate(TESObjectREFR* apRefr, TESObjectREFR* apActor, BGSOpenCloseForm* apForm)
{
    if (!apRefr)
        return;
    bool bFlag = false;
    if (apRefr->GetNiNode())
    {
        if (apRefr->GetNiNode()->NiObjectNET::GetControllers())
        {
            NiTimeController* p3d = apRefr->GetNiNode()->NiObjectNET::GetControllers();
            NiControllerManager* pAV = (NiControllerManager*)NiObject_DynamicCast(&DAT_011f36ac, (NiProperty*)p3d);
            if (pAV)
            {
                NiControllerSequence* pSeqA = pAV->NiControllerManager_GetSequenceByName(FUN_0047a500());
                NiControllerSequence* pSeqB = pAV->NiControllerManager_GetSequenceByName(FUN_0047a510());
                if (pSeqA && pSeqB)
                {
                    bFlag = true;
                    if (pSeqA->GetState() != 1 && pSeqB->GetState() != 1)
                    {
                        NiControllerSequence* p2c;
                        SoundH* p28 = 0;
                        TESObjectDOOR* pPathNodeDoor = dynamic_cast<TESObjectDOOR*>(apForm);
                        if (!apRefr->GetAction(OBJECT_ACTION_OBJECT_ACTION_OPEN))
                        {
                            if (pPathNodeDoor)
                                p28 = (SoundH*)pPathNodeDoor->GetOpenSound();
                            p2c = pSeqA;
                            apRefr->PerformAction(OBJECT_ACTION_OBJECT_ACTION_OPEN);
                        }
                        else
                        {
                            if (pPathNodeDoor)
                                p28 = (SoundH*)GetDoorSecondarySound(pPathNodeDoor);
                            p2c = pSeqB;
                            apRefr->CloseReference(OBJECT_ACTION_OBJECT_ACTION_OPEN);
                        }
                        if (!*DAT_011c4c64.Bool() && apActor && apActor->IsActor() &&
                            apActor != _g_thePlayer && apRefr->GetNiNode())
                        {
                            bool bSkip = true;
                            if (static_cast<const TESForm*>(apRefr->GetObjectReference())->GetFormType() == ENUM_FORM_ID_DOOR_ID)
                            {
                                TESBoundObject* pObj = apRefr->GetObjectReference();
                                if (((TESObjectDOOR*)pObj)->IsSlidingDoor())
                                    bSkip = false;
                            }
                            if (bSkip)
                            {
                                void* pNi = apRefr->GetNiNode();
                                if (AILinearTaskThreadManager_ShouldQueue3DTask())
                                {
                                    ((TaskQ2*)TaskQueueInterface::GetSingleton())->QueueTaskIfPresent(pNi);
                                }
                                else
                                {
                                    bhkWorld_Activate((NiAVObject*)pNi, 1, 1, 0);
                                    bhkWorld_RemoveObjects(pNi, 1, 1);
                                }
                            }
                        }
                        pAV->FUN_0047aa40(true);
                        pAV->FUN_0047aab0(p2c, 0, 0, 1.0f, 0.0f, static_cast<NiControllerSequence*>(0));
                        p2c->PathingLOSGridMap_SetSightRadius(-DAT_0101ab70);
                        if (p28)
                        {
                            BSAudioSoundHandle h;
                            if (apActor == _g_thePlayer)
                            {
                                h.ExtraDataList_GetSound(&((BSAudio2*)BSAudioS_::GetSingleton())
                                                    ->GetSoundHandleByFormID_00ad73b0(p28->GetHavokWorldObjectCountInSceneGraph_0084e3a0(0x80000121u)));
                            }
                            else
                            {
                                h.ExtraDataList_GetSound(
                                    &((BSAudio2*)BSAudioS_::GetSingleton())->GetSoundHandleByFormID_00ad73b0(p28->GetHavokWorldObjectCountInSceneGraph_0084e3a0(0x102)));
                                NiPoint3 pt = *static_cast<const TESObjectREFR*>(apRefr)->GetPos();
                                h.FUN_00ad8b60(pt.x, pt.y, pt.z);
                            }
                            h.Play(false);
                        }
                        SetLinkedReference(apRefr->GetExtraData(), reinterpret_cast<const LinkedReferenceArgument&>(apActor));
                        apRefr->MarkAsModified(0x80000000u);
                        if (p2c == pSeqA && apActor == _g_thePlayer)
                        {
                            BGSOpenCloseForm* pOCF = GetOpenCloseForm(apRefr->GetObjectReference());
                            if (pOCF && pOCF->GetBlockActivatesWhileOpening())
                                ((RefX*)_g_thePlayer)->SetQuickKeysEnabled(1);
                        }
                    }
                }
            }
        }
    }
    if (!bFlag)
    {
        bool bOpen = false;
        switch (BGSOpenCloseForm::GetOpenState(apRefr))
        {
        case BGSOpenCloseForm::OPEN:
        case BGSOpenCloseForm::OPENING:
            apRefr->CloseReference(OBJECT_ACTION_OBJECT_ACTION_OPEN);
            break;
        default:
            bOpen = true;
            apRefr->PerformAction(OBJECT_ACTION_OBJECT_ACTION_OPEN);
            break;
        }
        BGSOpenCloseForm* pOCF2 = GetOpenCloseForm(apRefr->GetObjectReference());
        if (pOCF2)
        {
            if (bOpen)
                pOCF2->HandleOpenAnimationFinish(apRefr, apActor);
            else
                pOCF2->HandleCloseFinish(apRefr, apActor);
        }
    }
}
