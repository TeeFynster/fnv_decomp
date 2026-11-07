// fallout/interface/menus/dialogmenu.cpp: DialogMenu, TESTopicInfo and response list boxes (23 functions)

#include "dialogmenu_decls.h"
#include "dialogmenu_runtime.h"

// @fnv 0x007628C0
bool LocalDialogMenu::HandleMenuInput(int button, float value)
{
    if (DialogMenuInterfaceCalls::GetSelectedTargetIndex(DialogMenuInterfaceCalls::Dialog))
    {
        switch (button)
        {
        case 9:
            // The Menu tile getter shares the canonical +4 pointer getter.
            if (reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<TESTopic*>*>(this)->GetNext())
                    ->ContainsTrait(ms_iDialogMenuValue))
                HandleSelection(0, 0);
            else
                HandleSelection(-1, m_kResponseListBox.GetHighlightedItem());
            return true;
        }
    }
    return false;
}

// Sets the goodbye type to forced or natural based on the topic's parent rumor flag and its next response matching a conversation topic.
// @fnv 0x00762860
void LocalDialogMenu::SetCurrentTopic(MenuTopic* topic)
{
    // The MenuTopic info/original-topic accessors share the canonical +18/+1C
    // getters; the first predicate shares TESTopic's flag predicate.
    if (reinterpret_cast<TESTopic*>(reinterpret_cast<NiAVObject*>(topic)->GetParent())->IsRemappedRumors())
        m_eGoodbyeState = eForceGoodbye;
    else if (reinterpret_cast<TESTopic*>(reinterpret_cast<TESResponse*>(topic)->GetNext()) ==
             TESTopic::GetAudioBackendData(DIALOGUE_TYPE_DT_CONVERSATION, 2))
        m_eGoodbyeState = eNaturalGoodbye;
}

// @fnv 0x00762FF0
LocalDialogMenu::DialogState LocalDialogMenu::BeginDialogueResponse(bool usePrefix)
{
    MenuTopic* topic = pDialogueItem->GetSelectedTopic();
    DialogueResponse* response = topic ? topic->GetActiveResponse() : 0;
    DialogState state = eSpeechIdle;
    if (topic)
        sprintf_s(m_cCurrentTopicLabel, 128, "%s (%d)",
                  reinterpret_cast<TESTopic*>(reinterpret_cast<TESResponse*>(topic)->GetNext())->GetName(),
                  reinterpret_cast<TESForm*>(reinterpret_cast<TESResponse*>(topic)->GetNext())->GetFormID());
    else
        TaskQueueInterface::CopyStringToBuffer(m_cCurrentTopicLabel, 128, "----");
    if (response)
    {
        char text[512];
        bool responseStarted = false;
        m_bResponseStarted = true;
        topic->NextResponse();
        m_pDialogueSpeaker->vfn_264(0.0f, response, true);
        m_kActorProcessResult =
            reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)->GetLogDate())
                ->GetActorSoundHandle(false);
        if (!m_bServiceDialogue)
        {
            if (usePrefix)
            {
                if (pDialogueItem->ActiveEffect_IsActive())
                {
                    if (reinterpret_cast<BSStringT<char>*>(
                            &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response)->GetItem())
                            ->String())
                        sprintf_s(text, 512, "%s %s", DAT_011d27fc.String(),
                                  reinterpret_cast<BSStringT<char>*>(
                                      &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response)->GetItem())
                                      ->String());
                    else
                        sprintf_s(text, 512, "%s", DAT_011d27fc.String());
                }
                else
                {
                    if (reinterpret_cast<BSStringT<char>*>(
                            &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response)->GetItem())
                            ->String())
                        sprintf_s(text, 512, "%s %s", DAT_011d3fe8.String(),
                                  reinterpret_cast<BSStringT<char>*>(
                                      &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response)->GetItem())
                                      ->String());
                    else
                        sprintf_s(text, 512, "%s", DAT_011d3fe8.String());
                }
            }
            else
            {
                if (reinterpret_cast<BSStringT<char>*>(
                        &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response)->GetItem())
                        ->String())
                    TaskQueueInterface::CopyStringToBuffer(
                        text, 512,
                        reinterpret_cast<BSStringT<char>*>(
                            &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response)->GetItem())
                            ->String());
                else
                    TaskQueueInterface::CopyStringToBuffer(text, 512, " ");
            }
            m_pTiles[2]->Set(0xFC4, text, true);
            reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<TESTopic*>*>(this)->GetNext())
                ->Set(ms_iDialogMenuValue, 1);
            state = ePlaySpeech;
        }
    }
    else
    {
        if (!m_bResponseStarted)
            Warning("MENUS: (Dialog Menu) Topic %s has no responses, which shouldn't happen.",
                    topic ? reinterpret_cast<TESSoundFile*>(reinterpret_cast<char*>(reinterpret_cast<TESResponse*>(topic)->GetNext()) + 24)
                                ->GetSoundFile()
                          : "NULL");
        if (DAT_011d9518 && m_eGoodbyeState != eForceGoodbye && !DAT_011d9518->IsGoodbye())
        {
            DAT_011d9518->RunResultScript(true, reinterpret_cast<MobileObject*>(m_pDialogueSpeaker));
            TESTopicInfo* follow;
            bool bDispositionFailure;
            follow = FindFollowupTopicInfo(DAT_011d9518, &bDispositionFailure,
                                           reinterpret_cast<LocalDialogueItem*>(pDialogueItem)->GetInfo(), g_thePlayer,
                                           false, false);
            if (follow && topic)
            {
                BSSimpleList<MenuTopic*>* pNewTopicList =
                    reinterpret_cast<BSSimpleList<MenuTopic*>*>(new BSSimpleList<TESTopic*>);
                MenuTopic* pNextTopic =
                    new MenuTopic(reinterpret_cast<LocalDialogueItem*>(topic)->GetQuest(),
                                  reinterpret_cast<TESTopic*>(reinterpret_cast<TESResponse*>(topic)->GetNext()), follow,
                                  m_pDialogueSpeaker, false);
                pNextTopic->FillResponseList();
                reinterpret_cast<BSSimpleList<MediaSet*>*>(pNewTopicList)
                    ->AddTail(reinterpret_cast<MediaSet*>(pDialogueItem->GetFirstTopic()));
                reinterpret_cast<BSSimpleList<MediaSet*>*>(pNewTopicList)
                    ->AddTail(reinterpret_cast<MediaSet* const&>(pNextTopic));
                pDialogueItem->AddHeadIfNotNull(pNewTopicList);
                pDialogueItem->SelectTopic(true);
                if (reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pNextTopic)->GetParent())
                        ->IsChallengeFlagSet())
                {
                    if (pDialogueItem->ShouldSkipTopic(pNextTopic))
                        pNextTopic = pDialogueItem->GetSelectedTopic();
                    else
                    {
                        if ((int)reinterpret_cast<TimeGlobal*>(pDialogueItem)->GetTimeStamp() > 0)
                        {
                            g_thePlayer->RewardXP(reinterpret_cast<TimeGlobal*>(pDialogueItem)->GetTimeStamp());
                            TopicMenuController::IncrementMiscStat(12);
                        }
                        else
                            TopicMenuController::IncrementMiscStat(12);
                    }
                }
                else if (reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pNextTopic)->GetParent())
                             ->GetActorValue() ||
                         reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pNextTopic)->GetParent())
                             ->GetPerk())
                {
                    PerkEntryConditionSet* pConditions =
                        reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pNextTopic)->GetParent())
                            ->GetInfoConditions();
                    BSSimpleList<TESConditionItem*>* pConditionItem =
                        reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                            &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pConditions)->GetItem());
                    while (pConditionItem && pConditionItem->GetItem())
                    {
                        DialogMenuConditionFunction* function = reinterpret_cast<DialogMenuConditionFunction*>(
                            reinterpret_cast<TESTopicInfoData*>(pConditionItem->GetItem())->GetLinkToList());
                        if (function && function->function == 14)
                        {
                            ActorValue::Index value = function->actorValue;
                            int required = (int)pConditionItem->GetItem()->GetConditionValue();
                            int current = g_thePlayer->actorValueOwner.GetActorValueAsInteger(value);
                            if (current < required)
                                TopicMenuController::IncrementMiscStat(31);
                            else
                                TopicMenuController::IncrementMiscStat(12);
                            break;
                        }
                        pConditionItem = reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                            reinterpret_cast<BSSimpleList<TESTopic*>*>(pConditionItem)->GetNext());
                    }
                }
                SetCurrentTopic(pNextTopic);
                pDialogueItem->RunTopicResultScript();
                m_bResponseStarted = false;
                DAT_011d9518 = reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pNextTopic)->GetParent());
                return BeginDialogueResponse(usePrefix);
            }
            DAT_011d9518 = 0;
        }
        if (!m_bServiceDialogue || m_eDialogState == eServiceFadeOut)
        {
            pDialogueItem->UpdateTopicList();
            if (!pDialogueItem->SelectTopic(true) && m_eGoodbyeState == eInDialogue)
                m_eGoodbyeState = eInvalidChoiceList;
            if (m_eGoodbyeState != eInDialogue)
            {
                Close();
                m_fCameraTransitionTime = 0.0f;
                state = eCameraZoomOut;
                m_eDialogState = eCameraZoomOut;
            }
            else
            {
                reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<TESTopic*>*>(this)->GetNext())
                    ->Set(ms_iDialogMenuValue, 0);
                LoadTopicsList();
                state = eSpeechIdle;
            }
        }
    }
    if (bPaused)
        m_eStateBeforePause = state;
    return state;
}

// @fnv 0x007638B0
void LocalDialogMenu::LoadTopicsList()
{
    m_kResponseListBox.Clear();
    int iIndex = 0;
    int iTopicHeight = 0;
    char text[512];
    bool bNextTopic = pDialogueItem->SelectTopic(true);
    while (bNextTopic)
    {
        MenuTopic* pTopic = pDialogueItem->GetSelectedTopic();
        bool bDisabled = false;
        TESFullName* pFullName = 0;
        if (reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent())->GetActorValue())
        {
            pFullName =
                reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent())->GetActorValue();
        }
        else
        {
            pFullName = reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent())->GetPerk();
        }
        if (pFullName)
        {
            sprintf_s(text, 512, "[%s", reinterpret_cast<TESSoundFile*>(pFullName)->GetSoundFile());
            if (reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent())
                    ->IsChallengeFlagSet())
            {
                MobileObjectView* actor = 0;
                if (m_pDialogueSpeaker->IsActor())
                    actor = m_pDialogueSpeaker;
                else if (m_pDialogueSpeaker->MobileObject_IsTalkingActivator())
                    actor = reinterpret_cast<MobileObjectView*>(
                        reinterpret_cast<BGSExplosion*>(reinterpret_cast<LocalDialogueItem*>(m_pDialogueSpeaker)
                                                            ->SelectDefaultResponseList()
                                                            ->GetObjectReference())
                            ->BGSExplosion_GetImpactDataSet());
                sprintf_s(
                    text, 512, "%s, %i", text,
                    ComputeWeightedValue(
                        g_thePlayer->actorValueOwner.GetActorValueFloatByIndex(ActorValue::ActorValue__Index_SPEECH),
                        m_pDialogueSpeaker->IsActor() ? (float)static_cast<ActorView*>(m_pDialogueSpeaker)->CalculateDisposition(g_thePlayer, 0)
                                                      : *DAT_011d0a24.Float(),
                        reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent())
                            ->GetNextSpeakerType()));
                ConcatDialogText(text, 512, "%");
            }
            else
            {
                PerkEntryConditionSet* pConditions =
                    reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent())
                        ->GetInfoConditions();
                BSSimpleList<TESConditionItem*>* cursor = reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                    &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pConditions)->GetItem());
                while (cursor && cursor->GetItem())
                {
                    DialogMenuConditionFunction* function = reinterpret_cast<DialogMenuConditionFunction*>(
                        reinterpret_cast<TESTopicInfoData*>(cursor->GetItem())->GetLinkToList());
                    if (function && function->function == 14)
                    {
                        ActorValue::Index value = function->actorValue;
                        int required = (int)cursor->GetItem()->GetConditionValue();
                        int current = g_thePlayer->actorValueOwner.GetActorValueAsInteger(value);
                        if (current < required)
                        {
                            sprintf_s(text, 512, "%s %d/%d", text, current, required);
                            bDisabled = true;
                        }
                        else
                            sprintf_s(text, 512, "%s %d", text, required);
                        break;
                    }
                    cursor = reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                        reinterpret_cast<BSSimpleList<TESTopic*>*>(cursor)->GetNext());
                }
            }
            sprintf_s(
                text, 512, "%s]  %s", text,
                reinterpret_cast<BSStringT<char>*>(&reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pTopic)->GetItem())
                    ->String());
        }
        else
        {
            if (reinterpret_cast<BSStringT<char>*>(&reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pTopic)->GetItem())
                    ->String())
                TaskQueueInterface::CopyStringToBuffer(
                    text, 512,
                    reinterpret_cast<BSStringT<char>*>(
                        &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pTopic)->GetItem())
                        ->String());
            else
            {
                text[0] = 0;
                Warning("ERROR: DialogMenu::LoadTopicsList(): has a topic without topictext OR info prompt: %s",
                        pTopic->pTopic ? pTopic->pTopic->GetName() : "unknown");
            }
        }
        Tile* pItemTile = m_kResponseListBox.AddItem(iIndex, text, 0, 0);
        sprintf_s(text, 512, "topic_%i", iIndex);
        pItemTile->SetName(text);
        pItemTile->Set(0xFAC, iIndex);
        pItemTile->Set(
            Tile::GetTraitID("_line_alpha"),
            pTopic->m_bInfoHasBeenRead &&
                    !reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent())->IsFlagSet()
                ? 255
                : 128);
        if (bDisabled)
            pItemTile->SetSpeechChallengeFailure_0071aa60(true);
        if (iIndex <= 2)
            iTopicHeight += (int)reinterpret_cast<TileListBoxCalls_dialogmenu_decls*>(pItemTile)->GetFloat(0xFB0);
        bNextTopic = pDialogueItem->AdvanceTopic();
        ++iIndex;
    }
    m_pTiles[3]->Set(0xFB0, (float)iTopicHeight, false);
    reinterpret_cast<Tile*>(reinterpret_cast<TimeGlobal*>(&m_kResponseListBox)->GetTimeStamp())
        ->Set(Tile::GetTraitID("_height"),
              reinterpret_cast<TileListBoxCalls_dialogmenu_decls*>(reinterpret_cast<BSSimpleList<TESTopic*>*>(this)->GetNext())
                  ->GetFloat(Tile::GetTraitID("_ScrollbarHeight")),
              true);
    reinterpret_cast<Tile*>(reinterpret_cast<TimeGlobal*>(&m_kResponseListBox)->GetTimeStamp())
        ->Set(DAT_011d9504, 0.0f, false);
    m_kResponseListBox.Synchronize();
    m_uiDialogMenuFlags = g_timeGlobal.GetTimeStamp();
}

// @fnv 0x00761A20
Tile* LocalDialogMenu::Create(MobileObjectView* speaker, TESTopic* topic, MobileObjectView* alternate)
{
    InterfaceManager* pManager = InterfaceManager_GetSingleton();
    Tile* existing = reinterpret_cast<Tile*>(Tile::FindMenuById(1009));
    if (existing)
        return existing;
    if (!speaker)
    {
        Warning(
            "MENUS: DialogMenu::Create() called with a null speaker, which shouldn't happen.  Notify your friendly Interface programmer!");
        return 0;
    }
    Tile* m_pFourthMenuObject = pManager->CombatController_GetCombatState()->ReadFile("Data\\Menus\\Dialog\\dialog_menu.xml");
    DAT_011d9510 = static_cast<LocalDialogMenu*>(m_pFourthMenuObject->GetMenu());
    if (DAT_011d9510 && DAT_011d9510->GetClass() == (unsigned int)DialogMenu_GetClassStatic())
    {
        DAT_011d9510->SetTileMenu(reinterpret_cast<TileMenu*>(m_pFourthMenuObject), false);
        if (!DAT_011d9510->DialogMenu_IsWellFormedMenu())
        {
            Warning("MENUS: Dialogue Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (reinterpret_cast<TileListBoxCalls_dialogmenu_decls*>(m_pFourthMenuObject)->GetFloat(0xFA7) == 6006.0 ||
            reinterpret_cast<TileListBoxCalls_dialogmenu_decls*>(m_pFourthMenuObject)->GetFloat(0xFA7) == 102.0)
            m_pFourthMenuObject->Set(0xFAD, Tile::GetInterfaceScale(), true);
        DAT_011d9510->m_pDialogueSpeaker = speaker;
        ImageSpaceModifierInstanceForm::Stop(TESImageSpaceModifier::GetGetHit());
        if (speaker->GetFaceGenNodeBiped(0))
            speaker->GetFaceGenNodeBiped(0)->StopMoving(true);
        if (speaker->GetFaceGenNodeSkinned(0))
            speaker->GetFaceGenNodeSkinned(0)->StopMoving(true);
        TESPackage* pCurrentPackage = speaker->GetCurrentPackage();
        if (speaker->IsActor())
        {
            ActorView* actor = reinterpret_cast<ActorView*>(speaker);
            TESPackage* extra = reinterpret_cast<TESObjectREFR*>(actor)->GetExtraData()->GetPackageOverride();
            if (extra && extra->GetPackType() == 15)
                DAT_011a008c = extra->GetPackageFloatValue();
        }
        if (!pCurrentPackage || pCurrentPackage->GetPackType() != 28 || speaker->vfn_2c8() != g_thePlayer)
        {
            if (speaker->IsActor() && !speaker->vfn_274(true))
                reinterpret_cast<ActorView*>(speaker)->SetSpeakingState(false);
            if (speaker->vfn_274(true))
            {
                reinterpret_cast<ActorView*>(speaker)->StopMoving();
                speaker->vfn_280(g_thePlayer, 0, 0, true, false, true, false, false, false);
            }
            else
                speaker->vfn_280(g_thePlayer, 0, 0, true, false, true, false, false, false);
        }
        MobileObjectView* pTopicSpeaker = speaker;
        if (alternate)
            pTopicSpeaker = alternate;
        if (DAT_011d9510->pDialogueItem->Initialize(pTopicSpeaker, topic))
            DAT_011d9510->SetCurrentTopic(DAT_011d9510->pDialogueItem->GetFirstTopic());
        if (DAT_011d9510->pDialogueItem->GetFirstTopic())
            DAT_011d9518 = reinterpret_cast<TESTopicInfo*>(
                reinterpret_cast<NiAVObject*>(DAT_011d9510->pDialogueItem->GetFirstTopic())->GetParent());
        g_thePlayer->vfn_278(true);
        if (speaker->IsActor())
        {
            reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(speaker)->GetLogDate())
                ->SetProcessTarget(reinterpret_cast<MobileObject*>(speaker), 2);
            speaker->vfn_278(true);
        }
        DAT_011d9510->m_bPauseRequested = g_thePlayer->PlayerCharacter_Is3rdPerson();
        if (DAT_011d9510->m_eGoodbyeState != eForceGoodbye)
        {
            g_thePlayer->Show1stPerson(true);
            g_thePlayer->FocusOnActor(speaker, 0.0f, true);
        }
        if (!DAT_011d9510->m_pDialogueDepthOfFieldModifier)
        {
            float distance = (*speaker->GetPos() - *g_thePlayer->GetPos()).Length();
            DAT_011d9510->m_pDialogueDepthOfFieldModifier = ImageSpaceModifierInstanceDOF::CreateAndRegister(
                distance, *DAT_011d46fc.Float(), ImageSpaceModifierInstanceDOF::DOF_BACK, 0.0f, 0.0f, 0.0f);
            DAT_011d9510->m_pDialogueDepthOfFieldModifier->ImageSpaceModifierInstance_SetPermanent(true);
        }
        g_thePlayer->SetAimingWeapon(false, false, false);
        g_thePlayer->UpdatePlayerInventory();
        DAT_011d9510->m_kResponseListBox.Initialize(DAT_011d9510->m_pTiles[3], "DM_TopicTemplate");
        DAT_011d9510->m_pTiles[3]->GetNamedChild("lb_scrollbar")->Set(0xFA2, 40);
        DAT_011d9510->m_pTiles[3]->GetNamedChild("lb_highlight_box")->Set(0xFA1, 40);
        DAT_011d9510->m_pTiles[3]->GetNamedChild("lb_highlight_box")->Set(0xFB1, 960);
        DAT_011d9508 = Tile::GetTraitID("_DialogVisible");
        ms_iDialogMenuValue = Tile::GetTraitID("_ShowingText");
        DAT_011d9504 = Tile::GetTraitID("_current_value");
        bool bSubtitles =
            *DAT_011d8934.Bool() || speaker->IsActor() && reinterpret_cast<ActorView*>(speaker)->ShouldShowSubtitles();
        reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<TESTopic*>*>(DAT_011d9510)->GetNext())
            ->Set(Tile::GetTraitID("_ShowSubtitles"), bSubtitles);
        DAT_011d9510->m_pTiles[1]->Set(0xFC4, speaker->GetFullName(), true);
        if (Cmd_Default_Execute() && !InterfaceManager_GetSingleton()->kTutorialManager.HasBeenShown(17))
            DAT_011d9510->m_bSuppressDialogueText = true;
        else
            DAT_011d9510->BeginDialogueResponse(false);
        DAT_011d9510->SetMenuVisibility(false);
        BSAudio::EnableAudio();
        reinterpret_cast<DialogMenuAudioCalls*>(BSAudio::GetSingleton())->EnableAudio();
        speaker->SetAltered(true);
        DialogMenuInterfaceCalls::SetHUDVisible(false);
        return m_pFourthMenuObject;
    }
    else
    {
        if (DAT_011d9510 && reinterpret_cast<BSSimpleList<TESTopic*>*>(DAT_011d9510)->GetNext())
            delete DAT_011d9510;
    }
    return 0;
}

// Advances the dialogue camera zoom/speech state machine, closing the menu and updating the player's focus and camera each frame.
// @fnv 0x00762950
void LocalDialogMenu::UpdateDialog()
{
    if (bPaused || DialogMenuInterfaceCalls::IsConsoleActive())
        return;
    if (m_eDialogState != eCameraZoomOut)
    {
        if (!reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)->GetLogDate() ||
            reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)->GetLogDate())
                    ->GetCurrentFadeState() == 2 ||
            reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)->GetLogDate())
                    ->GetCurrentFadeState() >= 4)
        {
            Close();
            m_fCameraTransitionTime = 0.0f;
            m_eDialogState = eCameraZoomOut;
        }
    }
    if (reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)->GetLogDate() &&
        reinterpret_cast<HighProcess*>(reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)->GetLogDate())
            ->GetProcessLevel() &&
        m_eDialogState != eCameraZoomOut)
    {
        Close();
        m_fCameraTransitionTime = 0.0f;
        m_eDialogState = eCameraZoomOut;
    }
    switch (m_eDialogState)
    {
    case eCameraZoomIn:
        if (m_bSuppressDialogueText && m_fCameraTransitionTime == 0.0)
        {
            m_bSuppressDialogueText =
                InterfaceManager_GetSingleton()->kTutorialManager.ShowMessage(17, DialogMenu_GetClassStatic(), (unsigned int)*DAT_011d3ee0.Float() * 1400);
            if (!m_bSuppressDialogueText)
            {
                if (m_pDialogueSpeaker)
                    m_pDialogueSpeaker->bDialogueSelected = true;
                BeginDialogueResponse(false);
            }
        }
        else if (!m_bSuppressDialogueText && m_fCameraTransitionAlpha >= 0.1)
            reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<TESTopic*>*>(this)->GetNext())->Set(DAT_011d9508, 1);
        m_fCameraTransitionTime += g_timeGlobal.FUN_0084d030();
        m_fCameraTransitionAlpha = BSMIN(m_fCameraTransitionTime / *DAT_011d3ee0.Float(), 1.0f);
        if (m_fCameraTransitionAlpha == 1.0)
        {
            if (!m_bSuppressDialogueText)
            {
                m_fCameraTransitionTime = 0.0f;
                m_eDialogState = ePlaySpeech;
            }
            else if (InterfaceManager_GetSingleton()->kTutorialManager.HasBeenShown(17) && DialogMenuInterfaceCalls::GetSelectedTargetIndex(DialogMenuInterfaceCalls::Dialog))
            {
                m_fCameraTransitionTime = 0.0f;
                reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<TESTopic*>*>(this)->GetNext())
                    ->Set(DAT_011d9508, 1);
                if (m_pDialogueSpeaker)
                    m_pDialogueSpeaker->bDialogueSelected = true;
                BeginDialogueResponse(false);
                m_eDialogState = ePlaySpeech;
            }
        }
        break;
    case ePlaySpeech:
        if (DAT_011d951c > 0.0)
        {
            DAT_011d951c -= g_timeGlobal.FUN_0084d030();
            break;
        }
        if (m_pDialogueSpeaker && m_pDialogueSpeaker->bDialogueSelected)
        {
            m_fCameraTransitionTime = 0.0f;
            m_eDialogState = eLoadSpeech;
            m_uiDialogMenuFlags = g_timeGlobal.GetTimeStamp();
        }
        break;
    case eLoadSpeech:
        if (!m_pDialogueSpeaker->bDialogueSelected)
        {
            m_pDialogueSpeaker->MobileObject_StopCurrentDialogue();
            if (DAT_011d9594 == 0)
                DAT_011d9594 = g_timeGlobal.GetTimeStamp();
            if (g_timeGlobal.GetTimeStamp() - DAT_011d9594 >= 500.0)
                ActorView::SetActorDialogueState(reinterpret_cast<TESForm*>(m_pDialogueSpeaker)->GetFormID(), true);
        }
        else
        {
            m_fCameraTransitionTime = 0.0f;
            m_eDialogState = BeginDialogueResponse(false);
            DAT_011d9594 = 0;
        }
        break;
    case eSpeechIdle:
        if (m_bServiceDialogue && m_bServiceMenuRequested)
            m_eDialogState = eServiceFadeOut;
        break;
    case eServiceFadeOut:
        if (m_bServiceMenuRequested && m_eFadeState == 4)
        {
            BeginDialogueResponse(false);
            m_bServiceMenuRequested = false;
            m_eDialogState = eSpeechIdle;
        }
        break;
    case eCameraZoomOut:
        m_fCameraTransitionTime += g_timeGlobal.FUN_0084d030();
        m_fCameraTransitionAlpha = 1.0f - BSMIN(m_fCameraTransitionTime / *DAT_011d243c.Float(), 1.0f);
        if (m_fCameraTransitionAlpha == 0.0)
        {
            DAT_011f21d0 = true;
            DAT_011f21d1 = !m_bPauseRequested;
            g_thePlayer->FocusOnActor(m_pDialogueSpeaker, 0.0f, true);
            g_thePlayer->UpdateCamera(false, false);
            m_pDialogueDepthOfFieldModifier->FUN_0063f790(0.0f);
            delete reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<TESTopic*>*>(this)->GetNext());
            return;
        }
        break;
    }
    if (g_thePlayer->IsInThirdPerson())
        m_pDialogueSpeaker->vfn_264(g_timeGlobal.FUN_0084d030(), 0, false);
    g_thePlayer->FocusOnActor(m_pDialogueSpeaker,
                              (float)(m_fCameraTransitionAlpha * (DAT_011a008c == 0.0 ? 1.0 : DAT_011a008c / 100.0)),
                              m_eDialogState == eCameraZoomOut);
    g_thePlayer->UpdateCamera(false, false);
    m_pDialogueDepthOfFieldModifier->FUN_0063f790(*DAT_011d318c.Float() * m_fCameraTransitionAlpha);
}

// @fnv 0x00762160
void LocalDialogMenu::Close()
{
    if (DAT_011d9510)
    {
        MobileObjectView* speaker = DAT_011d9510->m_pDialogueSpeaker;
        ActorView* actor = 0;
        if (speaker->IsActor())
            actor = static_cast<ActorView*>(speaker);
        TESTopicInfo* pInfo = DAT_011d9518;
        bool runEndScript =
            DAT_011d9510->m_eGoodbyeState == eForceGoodbye || DAT_011d9510->m_eGoodbyeState == eInvalidChoiceList;
        if (DAT_011d9510->m_eGoodbyeState == eInvalidChoiceList)
            Warning("MENUS: (Dialog Menu) Invalid choice list encountered.  Closing menu...");
        if (speaker->GetFaceGenNodeBiped(0))
            speaker->GetFaceGenNodeBiped(0)->StopMoving(false);
        if (speaker->GetFaceGenNodeSkinned(0))
            speaker->GetFaceGenNodeSkinned(0)->StopMoving(false);
        speaker->MobileObject_StopCurrentDialogue();
        speaker->vfn_278(false);
        g_thePlayer->vfn_278(false);
        speaker->vfn_288();
        DAT_011d9514 = false;
        if (reinterpret_cast<PlayerQuestData*>(speaker)->GetLogDate())
        {
            reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(speaker)->GetLogDate())->SetDialogueEmotion(DIALOGUE_EMOTION_DE_NEUTRAL);
            if (actor && !reinterpret_cast<PlayerCharacterView*>(actor)->HasCombatState())
                reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(actor)->GetLogDate())
                    ->CheckForNewPackage(reinterpret_cast<Actor*>(actor), true);
        }
        if (actor && reinterpret_cast<PlayerQuestData*>(actor)->GetLogDate())
            reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(actor)->GetLogDate())->RestorePreviousReference(true);
        if (reinterpret_cast<PlayerQuestData*>(speaker)->GetLogDate() && actor && !actor->vfn_22c(false) &&
            !actor->vfn_2e8())
            reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(speaker)->GetLogDate())
                ->UpdateActorProcess(*DAT_011cd450.Float());
        if (actor)
            actor->StopMoving();
        g_thePlayer->UpdatePlayerState();
        reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(g_thePlayer)->GetLogDate())->RestorePreviousReference(true);
        if (pInfo && runEndScript && !pInfo->IsGoodbye())
        {
            pInfo->RunResultScript(true, reinterpret_cast<MobileObject*>(speaker));
            pInfo->AddTopicList();
            pInfo = 0;
            if (actor && !reinterpret_cast<PlayerCharacterView*>(actor)->HasCombatState() &&
                reinterpret_cast<PlayerQuestData*>(actor)->GetLogDate() &&
                reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(actor)->GetLogDate())
                    ->CheckForNewPackage(reinterpret_cast<Actor*>(actor), true))
                reinterpret_cast<BaseProcess*>(reinterpret_cast<PlayerQuestData*>(actor)->GetLogDate())->UpdateCurrentPackage(reinterpret_cast<Actor*>(actor));
        }
        reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<TESTopic*>*>(DAT_011d9510)->GetNext())->Set(0xFA3, 1);
        DAT_011d9510->LoadMenuData();
    }
    reinterpret_cast<DialogMenuAudioCalls*>(BSAudio::GetSingleton())->DeactivateAudio();
    BSAudio::DeactivateAudio();
}

// @fnv 0x007624f0
void LocalDialogMenu::HandleSelection(int id, Tile* tile)
{
    bool bSpeechChallenge = false;
    if (m_eDialogState == eCameraZoomIn || m_eDialogState == eCameraZoomOut)
        return;
    if (m_uiDialogMenuFlags)
    {
        if (g_timeGlobal.GetTimeStamp() - m_uiDialogMenuFlags >= 500)
            m_uiDialogMenuFlags = 0;
        else
            return;
    }
    if (id == -1 && m_kResponseListBox.ContainsKey(tile) &&
        pDialogueItem->DialogMenu_SetClickedMenuItem((int)reinterpret_cast<TileListBoxCalls_dialogmenu_decls*>(tile)->GetFloat(0xFAC)))
    {
        MenuTopic* pTopic = pDialogueItem->GetSelectedTopic();
        bool wasNew = pTopic->m_bInfoHasBeenRead;
        pTopic->m_bInfoHasBeenRead = false;
        if (reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent())->IsChallengeFlagSet())
        {
            bSpeechChallenge = true;
            if (pDialogueItem->ShouldSkipTopic(pTopic))
                pTopic = pDialogueItem->GetSelectedTopic();
            else
            {
                if ((int)reinterpret_cast<TimeGlobal*>(DAT_011d9510->pDialogueItem)->GetTimeStamp() > 0)
                {
                    g_thePlayer->RewardXP(reinterpret_cast<TimeGlobal*>(DAT_011d9510->pDialogueItem)->GetTimeStamp());
                    TopicMenuController::IncrementMiscStat(12);
                }
                else
                    TopicMenuController::IncrementMiscStat(12);
            }
        }
        else if (reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent())->GetActorValue() ||
                 reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent())->GetPerk())
        {
            PerkEntryConditionSet* pConditions =
                reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent())
                    ->GetInfoConditions();
            BSSimpleList<TESConditionItem*>* pConditionItem = reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                &reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pConditions)->GetItem());
            while (pConditionItem && pConditionItem->GetItem())
            {
                DialogMenuConditionFunction* function = reinterpret_cast<DialogMenuConditionFunction*>(
                    reinterpret_cast<TESTopicInfoData*>(pConditionItem->GetItem())->GetLinkToList());
                if (function && function->function == 14)
                {
                    ActorValue::Index value = function->actorValue;
                    int required = (int)pConditionItem->GetItem()->GetConditionValue();
                    int current = g_thePlayer->actorValueOwner.GetActorValueAsInteger(value);
                    if (current < required)
                    {
                        if (wasNew)
                            TopicMenuController::IncrementMiscStat(31);
                    }
                    else
                        TopicMenuController::IncrementMiscStat(12);
                    break;
                }
                pConditionItem = reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                    reinterpret_cast<BSSimpleList<TESTopic*>*>(pConditionItem)->GetNext());
            }
        }
        SetCurrentTopic(pTopic);
        pDialogueItem->RunTopicResultScript();
        m_bResponseStarted = false;
        DAT_011d9518 = reinterpret_cast<TESTopicInfo*>(reinterpret_cast<NiAVObject*>(pTopic)->GetParent());
        m_eDialogState = BeginDialogueResponse(bSpeechChallenge);
    }
    else if (reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<TESTopic*>*>(this)->GetNext())
                 ->ContainsTrait(ms_iDialogMenuValue) &&
             id == 0)
        m_eDialogState = eLoadSpeech;
}

// @fnv 0x007627e0
ActorValueInfo* TESTopicInfo::GetActorValue()
{
    return m_pPerkSkillStat && reinterpret_cast<TESBoundObject*>(m_pPerkSkillStat)->GetFormType() != 0x56
               ? reinterpret_cast<ActorValueInfo*>(m_pPerkSkillStat)
               : 0;
}

// @fnv 0x00762820
BGSPerk* TESTopicInfo::GetPerk()
{
    return m_pPerkSkillStat && reinterpret_cast<TESBoundObject*>(m_pPerkSkillStat)->GetFormType() == 0x56
               ? reinterpret_cast<BGSPerk*>(m_pPerkSkillStat)
               : 0;
}

// @fnv 0x007627c0
bool TESTopicInfo::IsChallengeFlagSet()
{
    return (m_Data.flags & 0x80) ? true : false;
}

// Returns true only if all four pointers stored at offset 0x30 in this DialogMenu are non-null.
// @fnv 0x007620f0
// src: COMMUNITY 0x007620f0
bool LocalDialogMenu::DialogMenu_IsWellFormedMenu()
{
    for (int iIndex = 0; iIndex < 4; ++iIndex)
    {
        if (((void**)((char*)this + 0x30))[iIndex] == 0)
            return false;
    }
    return true;
}

// @fnv 0x00763fd0
bool TESTopicInfo::IsFlagSet()
{
    return (bool)(*reinterpret_cast<char*>(reinterpret_cast<char*>(this) + 0x26) & 2);
}

void __cdecl RemoveDialogListBoxFromRegistry(void*);

// @fnv 0x007643c0
DialogListBox::~DialogListBox()
{
    ClearItems();
    RemoveDialogListBoxFromRegistry(this);
}

// @fnv 0x007620e0
// src: XBOX_PDB 0x007620e0
int __cdecl DialogMenu_GetClassStatic()
{
    return 0x3f1;
}

void __cdecl _Deallocate(void*);

// Destroys the dialogue menu, optionally frees it, and returns its address.
// @fnv 0x00761930
void* LocalDialogMenu::ScalarDeletingDestructor(unsigned int flags)
{
    this->~LocalDialogMenu();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x00764290
// src: GUESS 0x00764290 (confidence: low)
void DialogMenu_ProcessEntries_00764290()
{
    MenuTopic* pMenuTopicEntry;
    TopicMenuController* pmgr;
    if (DAT_011d9510)
    {
        pmgr = *(TopicMenuController**)((char*)DAT_011d9510 + 0x70);
        pMenuTopicEntry = 0;
        for (pmgr->SelectTopic(true); (pMenuTopicEntry = pmgr->GetSelectedTopic()) != 0; pmgr->AdvanceTopic())
            pMenuTopicEntry->m_bInfoHasBeenRead = 1;
    }
}

struct WeatherEntry;
struct BSSimpleList_WeatherEntry
{
  public:
    void* m_item;
    void* m_next;
    void Sort(int(__cdecl*)(WeatherEntry*, WeatherEntry*)) const;
};

// Sorts the list using the given comparison function, then synchronizes the list box.
// @fnv 0x00764900
void DialogListBox::SortAndSynchronize(int(__cdecl* apCompareFn)(ListBoxItem_int_*, ListBoxItem_int_*))
{
    reinterpret_cast<BSSimpleList_WeatherEntry*>(reinterpret_cast<char*>(this) + 4)->Sort(reinterpret_cast<int(__cdecl*)(WeatherEntry*, WeatherEntry*)>(apCompareFn));
    Synchronize();
}

// @fnv 0x00763ff0
// src: XBOX_PDB 0x00763ff0
void DialogMenu_ServiceStart()
{
    if (DAT_011d9510 && DAT_011d9510->m_eGoodbyeState == 0)
    {
        DAT_011d9510->m_bServiceDialogue = true;
        DAT_011d9510->m_bServiceMenuRequested = true;
        if (DAT_011d9510->pDialogueItem->GetSelectedTopic())
        {
            DAT_011d9510->m_pDialogueSpeaker->vfn_264(
                0.0f, DAT_011d9510->pDialogueItem->GetSelectedTopic()->GetActiveResponse(), false);
            *(bool*)((char*)DAT_011d9510->m_pDialogueSpeaker + 0x7c) = true;
        }
        DAT_011d9510->LoadMenuData();
    }
}

// @fnv 0x00764200
void LocalDialogMenu::SetActive(bool abActive)
{
    if (((const unsigned char*)this)[0x131] && !abActive)
    {
        m_kActorProcessResult.Play(false);
        ((unsigned char*)this)[0x131] = 0;
        ((int*)this)[0x28 / 4] = ((int*)this)[0x134 / 4];
    }
    else if (!((const unsigned char*)this)[0x131] && abActive)
    {
        m_kActorProcessResult.Pause();
        ((unsigned char*)this)[0x131] = 1;
        ((int*)this)[0x134 / 4] = ((int*)this)[0x28 / 4];
        ((int*)this)[0x28 / 4] = 2;
    }
}

void __cdecl ImageSpaceModifierInstance_Stop(void*);
void __cdecl MenuTopicManager_Destroy();

// @fnv 0x00761960
LocalDialogMenu::~LocalDialogMenu()
{
    DAT_011d9514 = false;
    if (DAT_011d9510->m_pDialogueDepthOfFieldModifier)
    {
        ImageSpaceModifierInstance_Stop(m_pDialogueDepthOfFieldModifier);
        m_pDialogueDepthOfFieldModifier = 0;
    }
    MenuTopicManager_Destroy();
    DAT_011d9510 = 0;
}

struct SpeakerStandIn
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void SayResponse(float delay, void* response);
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
    bool bDialogueStarted;
};

struct TopicStandIn : public TESTopic
{
    TESTopicInfo* FindInfo(MobileObjectView* speaker, PlayerCharacterView* player);
    TESQuest* GetQuestForInfo(TESTopicInfo* info);
};

// If a dialogue menu exists, clears its flag, finds the topic's info for the player, speaks the first response, and refreshes the topics.
// @fnv 0x007640a0
void StartDialogueForTopic(TESTopic* topic)
{
    if (DAT_011d9510)
    {
        DAT_011d9510->m_bServiceDialogue = false;
        if (topic)
        {
            TESTopicInfo* info4 = ((TopicStandIn*)topic)->FindInfo(DAT_011d9510->m_pDialogueSpeaker, g_thePlayer);
            MenuTopic* menuTopic = new MenuTopic(((TopicStandIn*)topic)->GetQuestForInfo(info4), topic, info4,
                                                 DAT_011d9510->m_pDialogueSpeaker, false);
            menuTopic->FillResponseList();
            ((SpeakerStandIn*)DAT_011d9510->m_pDialogueSpeaker)
                ->SayResponse(0.0f, menuTopic->GetActiveResponse(0));
            ((SpeakerStandIn*)DAT_011d9510->m_pDialogueSpeaker)->bDialogueStarted = true;
            delete menuTopic;
        }
        DAT_011d9510->RefreshTopics();
    }
}

void __cdecl AddToHeadList(DialogListBox* object);
// @fnv 0x007642f0
DialogListBox::DialogListBox()
{
    m_pHighlightedTile = 0;
    m_pSelectedTile = 0;
    m_pListTile = 0;
    pTemplateName = 0;
    usFlags = 0;
    m_usSelectedIndex = 0;
    m_fThirdListValue = 0.0f;
    m_fSecondListValue = 0.0f;
    m_fFirstListValue = 0.0f;
    SetSelectionMode(0, 1);
    AddToHeadList(this);
}
