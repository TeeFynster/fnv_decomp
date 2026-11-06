// fallout_shared/bipedanim.cpp: BipedAnim, BipedAnimWeap, FaceLoader, BipedAnimHelper (75 functions)

#include "bipedanim_decls.h"
#include "../../include/GO.h"
// local form of BSPackedTask: 0x0087b360 needs a direct char[20] member for the original /GS cookie (union form extent 46 vs 66).
struct PackedTaskGsLocal_0087b360 { int f0, f1, f2; char buf[20]; };

// @fnv 0x004ad4a0
NiAVObject* BipedAnim::AttachBipedModel(NiNode* model, NiNode* parent, BIPED_OBJECT slot, bool firstPerson, bool hair,
                                        BSFaceGenModel* faceModel)
{
    NiAVObject* pResult;
    {
        BipedSkinAttachment attachment;
        attachment.face = 0;
        pResult = 0;
        attachment.attachNode = parent;
        NiPointer<NiAVObject> spDataCopy(0);
        model->FUN_004add70();
        attachment.face = faceModel;
        if (!attachment.face && IsSlotHidden(slot))
            attachment.face = GetFaceGenModelForSlot(slot);
        model->FUN_00440460(NiPoint3::ZERO);
        if (parent && model->FUN_0043b480() >= 2 && model->FUN_0043b4a0(1) && model->FUN_0043b4a0(1)->IsGeometry())
        {
            attachment.attachNode = new NiNode(0);
            parent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(attachment.attachNode), true);
            pResult = attachment.attachNode;
        }
        BipedSkinBoneMetadata metadata;
        metadata.extra = model->GetExtraData(FUN_004ab220());
        metadata.bones = metadata.extra;
        if (metadata.bones)
        {
            NiNode* boneNode = GetBoneNode(BIPED_BONE_BIPED_BONE_WEAPON);
            if (boneNode)
                boneNode->RemoveExtraDataByName(FUN_004ab220());
            boneNode->AddExtraData(FUN_004ab220(), metadata.bones);
            for (unsigned int j = 0; j < model->FUN_0043b480(); ++j)
            {
                NiAVObject* child = model->FUN_0043b4a0(j);
                if (child->IsGeometry() && child->IsGeometry()->GetSkinInstance())
                {
                    reinterpret_cast<BoneListExtraView*>(metadata.bones)->children.FUN_004700d0(model->FUN_0043b4a0(j));
                }
            }
        }
        GlobalObject_004aff00 removed(0, 1);
        for (unsigned int i = 0; i < model->FUN_0043b480(); ++i)
        {
            BipedSkinnedChild skinned;
            skinned.child = model->FUN_0043b4a0(i);
            if (skinned.child && !skinned.child->IsGeometry())
            {
                ((BipedChildArray*)&removed)->Add(skinned.child);
                model->RemoveObject(skinned.child);
                continue;
            }
            if (firstPerson && BIPED_OBJECT_TEXT(skinned.child) &&
                !_strnicmp(BIPED_OBJECT_TEXT(skinned.child), DAT_01188b98[2], BSStringLength(DAT_01188b98[2])))
            {
                ((BipedChildArray*)&removed)->Add(skinned.child);
                model->RemoveObject(skinned.child);
                continue;
            }
            if (BIPED_OBJECT_TEXT(skinned.child))
            {
                BSStringT<char> name(BIPED_OBJECT_TEXT(skinned.child));
                name.FUN_004afad0();
                char prefix[10];
                if (hair)
                {
                    FUN_004add50(prefix, name, 9);
                    prefix[9] = 0;
                    if (!FUN_00404dc0(prefix, "pipboyoff"))
                    {
                        ((BipedChildArray*)&removed)->Add(skinned.child);
                        model->RemoveObject(skinned.child);
                        continue;
                    }
                }
                else
                {
                    FUN_004add50(prefix, name, 8);
                    prefix[8] = 0;
                    if (!FUN_00404dc0(prefix, "pipboyon"))
                    {
                        ((BipedChildArray*)&removed)->Add(skinned.child);
                        model->RemoveObject(skinned.child);
                        continue;
                    }
                }
            }
            skinned.geom = (NiTriBasedGeom*)skinned.child;
            if (skinned.geom && skinned.geom->FUN_005495f0() && skinned.geom->GetSkinInstance() && attachment.face &&
                m_pActor && m_pActor->GetObjectReference() && m_pActor->GetObjectReference()->GetFormType() == ENUM_FORM_ID_NPC__ID)
            {
                TESNPC* m_pActorBaseFormItem;
                m_pActorBaseFormItem = (TESNPC*)m_pActor->GetObjectReference();
                FaceGenCoord coords[4];
                NiPointer<NiAVObject> copiedData(0);
                skinned.geom->FUN_005495f0()->ResolveObjectPointer(*(NiPointer<NiObject>*)&spDataCopy);
                copiedData = (NiAVObject*)spDataCopy;
                skinned.geom->ReplaceModelData((NiGeometryData*)(NiAVObject*)copiedData);
                if (skinned.geom->GetSkinInstance() &&
                    ((NiSkinPartition*)((NiObjectNET*)skinned.geom->GetSkinInstance())->GetControllers()))
                {
                    ((NiSkinPartition*)((NiObjectNET*)skinned.geom->GetSkinInstance())->GetControllers())
                        ->ResolveObjectPointer(*(NiPointer<NiObject>*)&spDataCopy);
                    NiPointer<NiAVObject> partition((NiAVObject*)spDataCopy);
                    skinned.geom->SetSkinInstance((NiSkinInstance*)skinned.geom->GetSkinInstance()->Clone());
                    skinned.geom->GetSkinInstance()->FUN_004addc0((NiSkinPartition*)(NiAVObject*)partition);
                }
                m_pActorBaseFormItem->GetFaceGenCoords(coords);
                if (FUN_0043faf0())
                    attachment.face->ApplyFaceGenMorphs(&coords, skinned.geom, false);
            }
            UpdateSkinInstance(skinned.geom, false);
            skinned.skin = skinned.geom->GetSkinInstance();
            if (skinned.skin)
            {
                if (!pResult)
                    pResult = skinned.child;
                BipedSkinBoneBinding binding;
                binding.count = (unsigned int)((LowProcess*)skinned.skin->GetSkinData())->LowProcess::GetActiveCombatTarget();
                binding.boneArray = (NiAVObject**)((TimeGlobal*)skinned.skin)->GetTimeStamp();
                for (unsigned int j = 0; j < binding.count; ++j)
                {
                    if (!BIPED_OBJECT_TEXT(binding.boneArray[j]))
                    {
                        Warning(
                            "MODELS: Bone %i for part '%s->%s' is unnamed.\r\nMake sure all the vertices are skinned to a named bone.",
                            j, model->GetParent() ? BIPED_OBJECT_TEXT(model->GetParent()) : "NULL",
                            BIPED_OBJECT_TEXT(model));
                        continue;
                    }
                    binding.pBone = FUN_004ade00(root, BIPED_OBJECT_NAME(binding.boneArray[j]));
                    if (binding.pBone)
                        skinned.skin->SetBone(j, binding.pBone);
                }
                if (attachment.attachNode)
                {
                    ((BGSQuestObjective*)skinned.skin)->SetOwnerQuest((TESQuest*)parent);
                    attachment.attachNode->AttachChildInAvailableSlot(static_cast<NiAVObject*>(skinned.child), true);
                }
            }
        }
        model->FUN_004add70();
        return pResult;
    }
}

// The supplied identity for this span differs from its PC receiver semantics.
// Removes the biped weapon and related weapon/quiver nodes from the reference's 3D, updating the actor's process and weapon model state.
// @fnv 0x00571b50
void BipedAnim::AttachFaceGenNode()
{
    if (!((TESObjectREFR*)this)->Get3DSimple())
        return;
    BipedWeaponOwner pOwnerContext;
    {
        BipedEquippedWeapon weaponInfo;
        weaponInfo.weapon = 0;
        weaponInfo.changes = ((TESObjectREFR*)this)->GetExtraData()->GetContainerChangeData();
        if (weaponInfo.changes)
        {
            InventoryStackRecord* item = weaponInfo.changes->GetInventoryEntryData(BIPED_OBJECT_BO_WEAPON, false);
            if (item)
            {
                weaponInfo.weapon = (TESObjectWEAP*)item->FUN_0044ddc0();
                delete item;
            }
        }

        if (((TESObjectREFR*)this) == g_thePlayer)
        {
            if (g_thePlayer->IsAlert() && g_thePlayer->FUN_005721e0())
                g_thePlayer->SetAimingWeapon(false, false, false);
            pOwnerContext.biped = g_thePlayer->GetBipedAnimation(true);
        }
        else
        {
            pOwnerContext.biped = (BipedAnim*)((TESObjectREFR*)this)->GetValidBip01Names();  // vtable slot 122 (+0x1e8)
        }
        pOwnerContext.actor = 0;
        if (((TESObjectREFR*)this)->IsActor())
            pOwnerContext.actor = (Actor*)((TESObjectREFR*)this);
        if (((TESObjectREFR*)this) == g_thePlayer)
        {
            pOwnerContext.biped = g_thePlayer->GetBipedAnimation(true);
            DAT_011f2250.FUN_009c8950(false, true);
            if (pOwnerContext.biped)
                pOwnerContext.biped->RemoveBipedWeapon();
            pOwnerContext.biped = g_thePlayer->GetBipedAnimation(false);
            if (g_thePlayer->IsAlert())
                DialogMenuInterfaceCalls::SetHUDVisible(false);
            Interface::ClearGunScope();
        }
        pOwnerContext.process = pOwnerContext.actor->GetProcess();
        if (pOwnerContext.biped)
        {
            FUN_00572220(true);
            pOwnerContext.biped->RemoveBipedWeapon();
            FUN_00572220(false);
        }
        else
        {
            bool m_bHeaderParsed = false;
            {
                NiNode* pWeaponNode;
                {
                    NiAVObject* pBackpack =
                        SceneObjectLookup::GetObjectByName(((TESObjectREFR*)this)->GetNiNode(), "Backpack");
                    if (pBackpack)
                        pBackpack->GetParent()->RemoveObject(pBackpack);
                    pWeaponNode = 0;
                    {
                        NiNode* pNode = 0;
                        if (pOwnerContext.process)
                        {
                            pWeaponNode = pOwnerContext.process->GetTorchAttachNode(0);
                            m_bHeaderParsed = pWeaponNode && pWeaponNode->FUN_00453470();
                            if (!m_bHeaderParsed)
                            {
                                pWeaponNode = pOwnerContext.process->GetLeftWeaponBone(0);
                                bool bow = false;
                                if (pWeaponNode)
                                {
                                    for (unsigned int i = 0; i < pWeaponNode->FUN_0043b480(); ++i)
                                    {
                                        NiAVObject* child = pWeaponNode->FUN_0043b4a0(i);
                                        if (child && BIPED_OBJECT_TEXT(child) &&
                                            !FUN_00408b20(BIPED_OBJECT_TEXT(child), "Bow"))
                                        {
                                            bow = true;
                                            break;
                                        }
                                    }
                                }
                                if (bow)
                                    m_bHeaderParsed = pWeaponNode && pWeaponNode->FUN_00453470();
                            }
                            if (!m_bHeaderParsed)
                            {
                                BipedWeaponSearch nodes;
                                {
                                    nodes.root = ((TESObjectREFR*)this)->GetNiNode();
                                    nodes.search = nodes.root;
                                    nodes.found = 0;
                                    if (nodes.root)
                                    {
                                        NiAVObject* object = SceneObjectLookup::GetObjectByName(nodes.search, "Weapon");
                                        nodes.found = (NiNode*)object;
                                        if (nodes.found)
                                        {
                                            m_bHeaderParsed = true;
                                            pWeaponNode = nodes.found;
                                        }
                                    }
                                }
                            }
                        }
                        if (weaponInfo.weapon)
                        {
                            TESModel* model = weaponInfo.weapon ? (TESModel*)((char*)weaponInfo.weapon + 0x3c) : 0;
                            if (model && m_bHeaderParsed)
                                g_modelLoader->FUN_0045a5e0(model->GetModelFilePath());
                        }
                    }
                }
            }
        }
        if (pOwnerContext.process)
        {
            NiNode* pWeaponNode = pOwnerContext.process->GetTorchAttachNode(0);
            if (pWeaponNode)
            {
                reinterpret_cast<SceneObjectRemover*>(FUN_00450b80(0))->RemoveObject(pWeaponNode);
                pWeaponNode->DetachAllChildren();
            }
            if (((TESObjectREFR*)this)->IsCreature())
            {
                BipedWeaponSearch nodes;
                {
                    nodes.root = ((TESObjectREFR*)this)->GetNiNode();
                    nodes.search = nodes.root;
                    nodes.found = 0;
                    if (nodes.root)
                    {
                        NiAVObject* object = SceneObjectLookup::GetObjectByName(nodes.search, "Weapon");
                        nodes.found = (NiNode*)object;
                        if (nodes.found)
                        {
                            reinterpret_cast<SceneObjectRemover*>(FUN_00450b80(0))->RemoveObject(nodes.found);
                            nodes.found->DetachAllChildren();
                        }
                    }
                }
            }
            pWeaponNode = pOwnerContext.process->GetLeftWeaponBone(0);
            if (pWeaponNode)
            {
                bool bow = false;
                for (unsigned int i = 0; i < pWeaponNode->FUN_0043b480(); ++i)
                {
                    NiAVObject* child = pWeaponNode->FUN_0043b4a0(i);
                    if (child && BIPED_OBJECT_TEXT(child) && !FUN_00408b20(BIPED_OBJECT_TEXT(child), "Bow"))
                    {
                        bow = true;
                        break;
                    }
                }
                if (bow)
                {
                    reinterpret_cast<SceneObjectRemover*>(FUN_00450b80(0))->RemoveObject(pWeaponNode);
                    pWeaponNode->DetachAllChildren();
                }
            }
        }
        if (pOwnerContext.actor)
        {
            BaseProcess* active = pOwnerContext.actor->GetProcess();
            if (!pOwnerContext.biped && active && !g_dataHandler->FUN_004226e0() && !g_TESSaveLoadGame->GetLoading())
                pOwnerContext.actor->SetReloadState(false);
            pOwnerContext.actor->SetLightingNode(((TESObjectREFR*)this)->Get3DSimple());
            if (pOwnerContext.actor->GetProcess())
            {
                BGSBipedModelList* models = BGSBipedModelList::GetBipedModelList(weaponInfo.weapon);
                if (models && ((BSSimpleList<BGSPerkEntry*>*)models)->GetNext())
                    pOwnerContext.actor->GetProcess()->ResetActorModel((RESET_3D_FLAGS)1);
            }
        }
    }
}

// @fnv 0x004ae250
void BipedAnim::AttachFaceGenNode(NiNode* rootNode, NiNode* objectNode, NiNode* sourceNode, BipedAnim* biped,
                                  BIPED_OBJECT slot, BSFaceGenModel* face)
{
    BipedAttachmentTarget attachment;
    {
        attachment.metadata = 0;
        NiStringExtraData* pName = 0;
        {
            attachment.parent = 0;
            if (sourceNode)
                attachment.metadata = sourceNode->GetExtraData(FUN_004ae780());
            if (!attachment.metadata)
                attachment.metadata = objectNode->GetExtraData(FUN_004ae780());
            if (attachment.metadata)
            {
                pName = (NiStringExtraData*)FUN_00653270(&DAT_011f4a38, (NiProperty*)attachment.metadata);
                if (pName)
                {
                    NiAVObject* found = FUN_004ade00(rootNode, BIPED_EXTRA_STRING(pName));
                    attachment.parent = (NiNode*)found;
                    if (!attachment.parent)
                    {
                        TESObjectREFR* ref = TESObjectREFR::GetReferenceFromNiAVObject(rootNode);
                        if (ref && ref->GetObjectReference() && ref->GetObjectReference()->GetFormType() == 43)
                            HandleUnparentedObjectNode(objectNode);
                        else
                            Warning("MODELS: Could not find parent node '%s' for object '%s'.",
                                    BIPED_STRING_TEXT(BIPED_EXTRA_STRING(pName)), BIPED_OBJECT_TEXT(objectNode));
                    }
                }
                else
                    Warning("MODELS: Extra data 'Prn' on '%s' is not an NiStringExtraData.",
                            BIPED_OBJECT_TEXT(objectNode));
            }
            else
                Warning("MODELS: Could not find parent node extra data for '%s'.", BIPED_OBJECT_TEXT(objectNode));
            float fScale = 1.0f;
            if (attachment.parent)
            {
                fScale = attachment.parent->GetFloatAt64();
                attachment.parent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(objectNode), true);
                NiUpdateData UpdateData((float)g_timeGlobal.GetTimeStamp(), false, false);
                objectNode->UpdateDownwardPass(UpdateData, 0);
                ShadowSceneNode* shadowScene = FUN_00450b80(0);
                shadowScene->AddObject(objectNode);
                NiAVObject* scabbard = SceneObjectLookup::GetObjectByName(objectNode, "Scb");
                if (scabbard)
                {
                    attachment.parent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(scabbard), true);
                    SetCollisionRefFlag(attachment.parent, true);
                    scabbard->UpdateSceneObject();
                    objectNode->FUN_004add70();
                }
            }
            NiAVObject* pBackpackNode = SceneObjectLookup::GetObjectByName(objectNode, "Backpack");
            if (pBackpackNode)
            {
                if (rootNode == g_thePlayer->GetNode(true))
                    pBackpackNode->FUN_00450f90(true);
                else
                {
                    pBackpackNode->FUN_00440490(fScale);
                    attachment.metadata = pBackpackNode->GetExtraData(NiFixedString("UPB"));
                    if (attachment.metadata)
                    {
                        pName = (NiStringExtraData*)FUN_00653270(&DAT_011f4a38, (NiProperty*)attachment.metadata);
                        if (pName)
                        {
                            NiAVObject* found = FUN_004ade00(rootNode, BIPED_EXTRA_STRING(pName));
                            attachment.parent = (NiNode*)found;
                            if (attachment.parent)
                                attachment.parent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(pBackpackNode), true);
                        }
                    }
                }
            }
            if (biped && biped == g_thePlayer->GetBipedAnimation(true))
                FUN_00c6a2e0(objectNode, true, true);
            else
            {
                switch (slot)
                {
                case BIPED_OBJECT_BO_WEAPON: {
                    bhkCollisionObject* pCollision = bhkCollisionObject::GetFromNiAVObject(objectNode);
                    if (pCollision)
                    {
                        bhkWorldObject* pBody = pCollision ? pCollision->FUN_006fa820() : 0;
                        bhkShape* pShape = pBody ? pBody->FUN_004ae6a0() : 0;
                        if (!pShape)
                            Warning("HAVOK: Weapon '%s' doesn't have a good Havok shape on it.",
                                    BIPED_OBJECT_TEXT(objectNode));
                        if (pBody && pBody->FUN_0043b4f0().FUN_0043b4d0() != 5)
                            Warning("MODELS: Weapon '%s' needs to have the layer defined as a WEAPON.",
                                    BIPED_OBJECT_TEXT(objectNode));
                    }
                    else
                        Warning("HAVOK: Weapon '%s' doesn't have any Havok data on it.", BIPED_OBJECT_TEXT(objectNode));
                    break;
                }
                }
                FUN_00c6a350(objectNode, 4, true, true, true);
            }
        }
    }
}

// Assigns the biped model form or race to the matching biped slots, removing parts whose parent differs and optionally swapping in the 1st-person model.
// @fnv 0x004abad0
void BipedAnim::SetBipedObject(TESForm* form, TESModel* model, BIPED_OBJECT slot)
{
    TESBipedModelForm* pBipedModelForm = TESBipedModelForm::GetFormAsBipedModel(form);
    TESRace* pRace = dynamic_cast<TESRace*>(form);
    bool bUse1stPerson = false;
    char szFileName[260];
    unsigned int i;
    if (model && g_thePlayer->IsPlayerBipedAnimation(this))
        bUse1stPerson = IsModelPathMatch(model, szFileName);
    if (pBipedModelForm)
    {
        for (i = 0; i < 20; ++i)
            if (pBipedModelForm->HasBipedModel((BIPED_OBJECT)i, false, 0) && object[i].pParent != form)
            {
                if (object[i].pParent && dynamic_cast<TESRace*>(object[i].pParent))
                    RemovePart((BIPED_OBJECT)i, true, 0);
                else
                    RemovePartsByParent(object[i].pParent);
            }
        for (i = 0; i < 20; ++i)
            if (pBipedModelForm->HasBipedModel((BIPED_OBJECT)i, true, 0))
            {
                if (bUse1stPerson)
                    model = FUN_004afa20((BIPED_OBJECT)i, szFileName);
                object[i].pParent = form;
                object[i].m_pModel = model;
                break;
            }
    }
    else if (pRace)
    {
        RemovePart(slot, true, 0);
        if (bUse1stPerson)
            model = FUN_004afa20(slot, szFileName);
        object[slot].pParent = form;
        object[slot].m_pModel = model;
    }
}

// @fnv 0x004ad290
NiAVObject* BipedAnim::PrepareBipedModel(NiNode* model, BIPED_OBJECT slot, bool first, bool hair, BSFaceGenModel* face)
{
    NiAVObject* result = model;
    NiNode* multi = (NiNode*)FUN_00653270(&DAT_011f9140, (NiProperty*)model);
    NiPointer<NiNode> temp(0);
    if (!result)
        return result;
    object[slot].bHasAnimation = Animation::RemoveKeyframeControllers(model);
    if (!root)
        return result;
    if (object[slot].bHasAnimation)
    {
        NiNode* pSource = model;
        NiPointer<NiNode> spAttach(0);
        NiAVObject* pFound = SceneObjectLookup::GetObjectByName(root, "SkinAttachment");
        if (pFound)
            spAttach = (NiNode*)pFound;
        else
            spAttach = root->GetParent();
        NiAVObject* pSkinned = 0;
        if (multi)
            for (unsigned int j = 0; j < multi->FUN_0043b480(); ++j)
            {
                NiNode* child = (NiNode*)multi->FUN_0043b4a0(j);
                pSkinned = AttachBipedModel(child, 0, slot, first, hair, face);
            }
        else
            pSkinned = AttachBipedModel(pSource, spAttach, slot, first, hair, face);
        result = pSkinned;
        if (result != model)
        {
            NiPointer<NiNode> release(model);
        }
    }
    else
        result = 0;
    return result;
}

// @fnv 0x004ab250
void BipedAnim::UpdateRaceSex(TESRace* race, SEX sex)
{
    if (!race)
        return;
    bool empty = true;
    int i;
    for (i = 0; i < 20; ++i)
        if (m_kPreviousObjects[i].pParent)
            empty = false;
    if (m_pActor && m_pActor->GetNiNode())
    {
        for (i = 0; i < 20; ++i)
        {
            if (empty)
                m_kPreviousObjects[i] = object[i];
            memset(&object[i], 0, 16);
        }
    }
    else
    {
        if (empty)
            memset(m_kPreviousObjects, 0, 320);
        memset(object, 0, 320);
    }
    for (i = 0; i < 3; ++i)
        if (DAT_01188be8[DAT_01188b88[i]] == -1 || (bone[DAT_01188be8[DAT_01188b88[i]]].cFlags & 1))
            SetBipedObject(race, race->GetBipedObjectModel(sex, (BIPED_OBJECT)DAT_01188b88[i]),
                           (BIPED_OBJECT)DAT_01188b88[i]);
}

// Queues the NPC's biped parts selected by flags and, if the race provides a modified model path, queues that model for loading.
// @fnv 0x004abfe0
void BipedAnim::QueueBipedObjectLoads(unsigned int flags, IO_TASK_PRIORITY priority, QueuedFile* parent)
{
    if (!flags)
        return;
    TESNPC* npc = (TESNPC*)dynamic_cast<TESFaction*>(m_pActor->GetObjectReference());
    if (npc)
    {
        if (flags & 2)
            LoadBipedObject(npc, (BIPED_OBJECT)2, priority, parent);
        if (flags & 4)
            LoadBipedObject(npc, (BIPED_OBJECT)4, priority, parent);
        if (flags & 8)
            LoadBipedObject(npc, (BIPED_OBJECT)3, priority, parent);
        char base[260], mod[260];
        ((TESRace*)((TESHairCanBeNPCData*)npc)->FUN_004ac110())->BuildBodyTexturePath(npc, base);
        if (((TESRace*)((TESHairCanBeNPCData*)npc)->FUN_004ac110())->BuildBodyModTexturePath(npc, base, mod))
            g_modelLoader->QueueModelFilePath(mod, priority, parent);
    }
}

// Determines the biped skin slot from the object's skin name prefix, warning on unrecognized names, or returns -1 if no shader property applies.
// @fnv 0x004af360
BIPED_OBJECT BipedAnim::GetBipedObjectFromShaderProperty(NiAVObject* object, BSShaderPPLightingProperty* property)
{
    if (!property)
        property = FindLightingShaderProperty(object);
    if (property && property->FUN_004a2020(10))
    {
        BipedSkinNameMatch skinMatch;
        skinMatch.name = (const char*)((BSFadeNode*)((TESTopicInfoData*)object)->GetLinkToList())->FUN_0043b1b0();
        skinMatch.slot = (BIPED_OBJECT)2;
        int i = 0;
        for (i = 0; i < 5; ++i)
            if (skinMatch.name && !_strnicmp(skinMatch.name, DAT_01188c38[i], BSStringLength(DAT_01188c38[i])))
                break;
        switch (i)
        {
        case 0:
        case 1:
        case 4:
            skinMatch.slot = (BIPED_OBJECT)2;
            break;
        case 2:
            skinMatch.slot = (BIPED_OBJECT)3;
            break;
        case 3:
            skinMatch.slot = (BIPED_OBJECT)4;
            break;
        default:
            Warning("MODELS: Bad skin name '%s' on '%s'.", skinMatch.name,
                    (const char*)((BSFadeNode*)((TESTopicInfoData*)object->GetParent())->GetLinkToList())
                        ->FUN_0043b1b0());
        }
        return skinMatch.slot;
    }
    return (BIPED_OBJECT)-1;
}

// Builds a Data\Meshes path from the model's path with the extension replaced by "1st.nif" and returns whether that file exists.
// @fnv 0x004af950
bool BipedAnim::IsModelPathMatch(TESModel* model, char* output)
{
    TaskQueueInterface::CopyStringToBuffer(output, 260, model->GetModelFilePath());
    char* extension = FUN_0040ab30(output, '.');
    if (extension)
    {
        *extension = 0;
        strcat_s(extension, 260 - (extension - output), "1st.nif");
        char path[260];
        sprintf_s(path, 260, "Data\\%s\\%s", kMeshesFolder, output);
        if (FileFinder::Exist(path, 0, 6, 1))
            return true;
    }
    return false;
}

// Returns the geometry's shader property if it is a BSShaderPPLightingProperty with a value between 8 and 12, otherwise null.
// @fnv 0x004af290
BSShaderPPLightingProperty* BipedAnim::FindLightingShaderProperty(NiAVObject* object)
{
    if (!object || !object->IsGeometry())
        return 0;
    NiTriBasedGeom* m_pShaderGeometry = (NiTriBasedGeom*)object;
    BipedRenderProperties renderProps;
    renderProps.alpha = m_pShaderGeometry->GetProperty(FUN_004af350());
    renderProps.material = m_pShaderGeometry->GetProperty(FUN_004af340());
    renderProps.shader = (BSShaderPPLightingProperty*)m_pShaderGeometry->GetProperty(3);
    BSShaderPPLightingProperty* pLightingProp =
        (!renderProps.shader ? false
                             : (((NiTimeController*)renderProps.shader)->FUN_00441110() >= 8 &&
                                ((NiTimeController*)renderProps.shader)->FUN_00441110() <= 12))
            ? renderProps.shader
            : 0;
    return pLightingProp;
}

// If the NPC's race resolves a hair model path for the slot, queues that model and its _n variant with the model loader.
// @fnv 0x004ac130
void BipedAnim::LoadBipedObject(TESNPC* npc, BIPED_OBJECT slot, IO_TASK_PRIORITY priority, QueuedFile* parent)
{
    char base[260], mod[260];
    if (((TESRace*)((TESHairCanBeNPCData*)npc)->FUN_004ac110())->GetBipedObjectModelPath(npc, slot, base))
    {
        g_modelLoader->QueueModelFilePath(base, priority, parent);
        BSShaderManager::BuildTexturePath(mod, base, "_n", true);
        if (mod[0])
            g_modelLoader->QueueModelFilePath(mod, priority, parent);
    }
}

// @fnv 0x004aae70
void BipedAnim::CompleteModelLoadTask()
{
    g_modelLoader->CallContainedObject();
    ((ActorTaskManager*)&g_011c5cf0)->QueryPerformanceCounter(0);
    for (int i = 0; i < 20; ++i)
    {
        RemovePart((BIPED_OBJECT)i, true, 0);
        ClearBipedObject(&m_kPreviousObjects[i], true, 0);
    }
    ((ActorTaskManager*)&g_011c5cf0)->WaitForTasksDuringRendering();
    g_modelLoader->FUN_004aaf10();
}

// @fnv 0x004afa50
TESModel* BipedAnim::GetModelForSlot(BIPED_OBJECT slot, TESModel* model)
{
    char path[260];
    if (model == &DAT_011c5d10[slot])
        return model;
    if (IsModelPathMatch(model, path))
        return FUN_004afa20(slot, path);
    return model;
}

// Returns true if the biped object's model exists and its FUN_004ae8f0 check succeeds.
// @fnv 0x004ae8a0
bool BipedAnim::IsSlotHidden(BIPED_OBJECT slot)
{
    TESModel* model = object[slot].m_pModel;
    return model && model->FUN_004ae8f0();
}

// @fnv 0x004af240
void BipedAnim::ApplyReferenceExtraData(NiNode* model, NiNode* clone, BIPED_OBJECT slot, TESObjectREFR* requester)
{
    NiExtraData* extra = model->GetExtraData(FUN_00448a80());
    if (extra)
    {
        NiExtraData* addon = extra;
        if (addon->FUN_00448a40())
            TESObjectREFR::ApplyReferenceExtraData(clone);
    }
}

// Returns true only if both INI boolean settings at g_011d5a10 and g_011d5a44 are enabled.
// @fnv 0x004abfa0
bool BipedAnim::CanLoadHiddenBipedObjects()
{
    return *((SettingT<INISettingCollection>*)&g_011d5a10)->Bool() &&
           *((SettingT<INISettingCollection>*)&g_011d5a44)->Bool();
}

struct NiNode;
struct TESObjectREFR;
struct FUN_004aaca0_S
{
    void InitBoneSlots(NiNode*);
    FUN_004aaca0_S* Construct(int a, NiNode* n);
};
// Zeroes the object's memory, stores a at offset 0x2b0, and if n is non-null calls InitBoneSlots(n); returns this.
// @fnv 0x004aaca0
FUN_004aaca0_S* FUN_004aaca0_S::Construct(int a, NiNode* pNode)
{
    memset(this, 0, 0x2b4);
    memset((char*)this + 0x16c, 0, 0x140);
    *(int*)((char*)this + 0x2b0) = a;
    if (pNode == 0)
    {
    }
    else
    {
        InitBoneSlots(pNode);
    }
    return this;
}

struct BipedAnimObject;
struct TESForm;
struct FUN_004aaff0_S
{
    void ClearBipedObject(BipedAnimObject*, bool, TESForm*);
    void FUN_004aaff0(int a, bool b, TESForm* f);
};
// Calls ClearBipedObject with a pointer computed from this, a*16+0x2c, passing b and f.
// @fnv 0x004aaff0
void FUN_004aaff0_S::FUN_004aaff0(int aiIndex, bool abFlag, TESForm* apForm)
{
    ClearBipedObject((BipedAnimObject*)((char*)this + aiIndex * 16 + 0x2c), abFlag, apForm);
}

bool __cdecl IsConditionMet();
void __cdecl FUN_004ab0c0(NiAVObject*);

struct BipedAnim_Ext : public BipedAnim
{
    void FUN_004ab130(NiAVObject*);
};

struct TaskQueueInterface_Ext
{
    void FUN_0087acb0(NiAVObject*);
};

TaskQueueInterface_Ext* __cdecl FUN_004537b0();

// @fnv 0x004ab020
void BipedAnim::ClearBipedObject(BipedAnimObject* apObj, bool abClear, TESForm* aiClearValue)
{
    if (apObj->m_pSceneObject)
    {
        reinterpret_cast<BipedAnim_Ext*>(this)->FUN_004ab130(apObj->m_pSceneObject);
        if (!IsConditionMet())
            FUN_004ab0c0(apObj->m_pSceneObject);
        else
            FUN_004537b0()->FUN_0087acb0(apObj->m_pSceneObject);
        g_modelLoader->FUN_0045a5e0(apObj->m_pModel->GetModelFilePath());
        apObj->m_pSceneObject = 0;
    }
    if (abClear)
    {
        apObj->pParent = 0;
        apObj->m_pModel = reinterpret_cast<TESModel*>(aiClearValue);
    }
}

// @fnv 0x004abf80
int __fastcall FUN_004abf80(unsigned char* pThis)
{
    return pThis[0x14] & 0xe;
}

struct FUN_004ac110_shell : public TESNPC
{
    TESRace* FUN_004ac110();
};

// @fnv 0x004ac110
TESRace* FUN_004ac110_shell::FUN_004ac110()
{
    return (TESRace*)((BGSBipedModelList*)((char*)this + 0x10c))->GetList();
}

struct PA
{
    int z[4];
    PA(int);
};
struct PB
{
    int z[4];
    PB(int);
};
int FUN_004ad1b0();
char FUN_004ad1c0();
struct FUN_004ad0c0_S
{
    PA* a;
    PB* b;
    int c;
    char d;
    FUN_004ad0c0_S* Init(int x);
};
// Allocates a PA and a PB from x, stores results of FUN_004ad1b0 and FUN_004ad1c0, and returns this.
// @fnv 0x004ad0c0
FUN_004ad0c0_S* FUN_004ad0c0_S::Init(int aiValue)
{
    a = new PA(aiValue);
    b = new PB(aiValue);
    c = FUN_004ad1b0();
    d = FUN_004ad1c0();
    return this;
}

struct FUN_004ad1d0_Virt
{
    virtual ~FUN_004ad1d0_Virt();
};

struct FUN_004ad1d0_Obj
{
    FUN_004ad1d0_Virt* p0;
    FUN_004ad1d0_Virt* p4;
};

// Deletes the two objects pointed to by p0 and p4.
// @fnv 0x004ad1d0
void __fastcall FUN_004ad1d0(FUN_004ad1d0_Obj* pThis)
{
    delete pThis->p0;
    delete pThis->p4;
}

struct FUN_004ad240_c
{
    char pad[0x10];
    float x;
    float y;
    float z;
    void SetScale(float afScale);
};

// Sets the x, y and z fields to the given scale value.
// @fnv 0x004ad240
void FUN_004ad240_c::SetScale(float afScale)
{
    z = afScale;
    y = afScale;
    x = afScale;
}

void __fastcall FUN_004ad1d0(void*);

// @fnv 0x004ad270
void __fastcall FUN_004ad270(void* p)
{
    FUN_004ad1d0(p);
}

void __cdecl _fnv_CopyFilePath(char* dst, unsigned int dstSize, const char* src, unsigned int count);

// Copies count characters from src to dst via _fnv_CopyFilePath, passing count + 1 as the destination size.
// @fnv 0x004add50
void __cdecl FUN_004add50(char* dst, const char* src, unsigned int count)
{
    _fnv_CopyFilePath(dst, count + 1, src, count);
}

struct FUN_004add70_shell : public NiNode
{
    void FUN_004add70();
};

void __fastcall FUN_004afc80(void* p);
void __fastcall TrimTrailingNullPointers(void* p);

// Calls FUN_004afc80 and TrimTrailingNullPointers on the sub-object at offset 0x9C of this node.
// @fnv 0x004add70
void FUN_004add70_shell::FUN_004add70()
{
    FUN_004afc80(reinterpret_cast<char*>(this) + 0x9C);
    TrimTrailingNullPointers(reinterpret_cast<char*>(this) + 0x9C);
}

struct FUN_004adda0_shell : public NiSkinInstance
{
    void SetBone(unsigned int, NiAVObject*);
};

// @fnv 0x004adda0
void FUN_004adda0_shell::SetBone(unsigned int uiIndex, NiAVObject* pkBone)
{
    (*(NiAVObject***)((char*)this + 0x14))[uiIndex] = pkBone;
}

struct DummyArr
{
    void FUN_00558dd0(int);
};

struct DummyThis
{
    char pad[0xc];
    DummyArr arr;
};

struct StackArg
{
    int val;
};

// @fnv 0x004addc0
void __fastcall FUN_004addc0(DummyThis* this_ptr, StackArg aStackArg)
{
    this_ptr->arr.FUN_00558dd0(aStackArg.val);
}

void __cdecl FUN_00c4b470(int, int, int);

// @fnv 0x004ade00
void __cdecl FUN_004ade00(int a1, int a2)
{
    FUN_00c4b470(a1, a2, 1);
}

void __fastcall FUN_004afc20(void* pThis);

// @fnv 0x004ade20
void __fastcall FUN_004ade20(void* pThis)
{
    FUN_004afc20(pThis);
}

struct FUN_004ae6a0_shell : public bhkWorldObject
{
    bhkShape* FUN_004ae6a0();
};

void* __fastcall GetStringCStr(void*);
bhkShape* __cdecl FUN_004a3a40(void*);

// @fnv 0x004ae6a0
bhkShape* FUN_004ae6a0_shell::FUN_004ae6a0()
{
    return FUN_004a3a40(GetStringCStr(this));
}

struct Dummy_004ae6c0
{
    BSStringT<char>* FUN_004ae700();
};

// Calls FUN_004ae700 to get a BSStringT<char> and returns its character buffer, or null if the string pointer is null.
// @fnv 0x004ae6c0
const char* __fastcall GetStringCStr(Dummy_004ae6c0* pThis)
{
    BSStringT<char>* str = pThis->FUN_004ae700();
    return str ? (const char*)*str : 0;
}

struct SrcList;
struct FormS
{
    SrcList* GetSourceFiles();
};
struct FUN_004ae700_S
{
    FormS* FUN_004ae750();
    void SetShaderName();
    SrcList* FUN_004ae700();
};
// @fnv 0x004ae700
SrcList* FUN_004ae700_S::FUN_004ae700()
{
    SrcList* r = 0;
    FormS* f = FUN_004ae750();
    if (f)
    {
        SetShaderName();
        r = f->GetSourceFiles();
        SetShaderName();
    }
    return r;
}

int __fastcall GetReferenceFlags(void*);

// Returns the result of GetReferenceFlags on p when p is non-null, otherwise returns 0.
// @fnv 0x004ae750
int __fastcall FUN_004ae750(void* p)
{
    return p ? GetReferenceFlags(p) : 0;
}

// @fnv 0x004ae8f0
int __fastcall FUN_004ae8f0(unsigned char* p)
{
    return p[0x14] & 1;
}

struct FUN_004af860_shell : public NiSourceTexture
{
    bool FUN_004af860();
};

// @fnv 0x004af860
bool FUN_004af860_shell::FUN_004af860()
{
    return (((char*)this)[0x43] & 0) != 0;
}

struct FUN_004af880_shell : public NiSourceTexture
{
    void FUN_004af880();
};

// @fnv 0x004af880
void FUN_004af880_shell::FUN_004af880()
{
    *((char*)this + 0x43) = *((char*)this + 0x43);
}

class BSFaceGenManager;
extern BSFaceGenManager* DAT_011d59e8;

// Returns the NiTexture stored at offset 0x11a0 of DAT_011d59e8, or a null NiPointer if DAT_011d59e8 is null.
// @fnv 0x004af8a0
NiTexture* __cdecl FUN_004af8a0()
{
    return DAT_011d59e8 ? *(const NiPointer<NiTexture>*)((const char*)DAT_011d59e8 + 0x11a0) : NiPointer<NiTexture>(0);
}

struct FUN_004afa20_shell : public BipedAnim
{
    TESModel* FUN_004afa20(int, char*);
};

struct TESFullNameSetFullNameAccess : public TESFullName
{
    void SetFullName(const char* name);
};

// @fnv 0x004afa20
TESModel* FUN_004afa20_shell::FUN_004afa20(int aeBipedObject, char* ap1stPersonFileName)
{
    reinterpret_cast<TESFullName*>(&DAT_011c5d10[aeBipedObject])
            ->*reinterpret_cast<void (TESFullName::*)(const char*)>(&TESFullNameSetFullNameAccess::SetFullName);
    reinterpret_cast<TESFullNameSetFullNameAccess*>(&DAT_011c5d10[aeBipedObject])
        ->TESFullNameSetFullNameAccess::SetFullName(ap1stPersonFileName);
    return &DAT_011c5d10[aeBipedObject];
}

void __cdecl FUN_004afb00(char*, int);

struct BSStringT_layout
{
    char* m_data;
    unsigned short m_dataLen;
};

// If m_data is set, calls FUN_004afb00 on it with m_dataLen + 1 as the size.
// @fnv 0x004afad0
void __fastcall FUN_004afad0(BSStringT_layout* thisPtr)
{
    if (thisPtr->m_data)
    {
        FUN_004afb00(thisPtr->m_data, thisPtr->m_dataLen + 1);
    }
}

extern int DAT_01016ca4;
struct S4411
{
    void FUN_0043fd40(int, int);
    S4411* InitWithGlobal(int a, int b);
};
// Calls FUN_0043fd40 with the two arguments, stores the address of DAT_01016ca4 in the object's first field, and returns this.
// @fnv 0x004aff00
S4411* S4411::InitWithGlobal(int aiArg1, int aiArg2)
{
    FUN_0043fd40(aiArg1, aiArg2);
    *reinterpret_cast<int**>(this) = &DAT_01016ca4;
    return this;
}

struct Dummy_004f8a90
{
    void FUN_004f8a90(int, int*);
};

struct FUN_004f8a30_shell2
{
    int FUN_004f8a30(int arg1);
};

// Calls FUN_004f8a90 with arg1 and a local result, then returns that result.
// @fnv 0x004f8a30
int FUN_004f8a30_shell2::FUN_004f8a30(int arg1)
{
    int result = 0;
    ((Dummy_004f8a90*)this)->FUN_004f8a90(arg1, &result);
    return result;
}

struct FUN_009cdae0_shell : public NiAVObject
{
    float GetFloatAt64();
};

// @fnv 0x009cdae0
float FUN_009cdae0_shell::GetFloatAt64()
{
    return *(float*)((char*)this + 0x64);
}

NiAVObject* __cdecl FUN_00c4b310(NiAVObject*, NiFixedString*, int);

// @fnv 0x004aae30
NiAVObject* __cdecl FUN_004aae30(NiAVObject* apObject, NiFixedString* a2)
{
    return FUN_00c4b310(apObject, a2, 1);
}

extern NiFixedString* DAT_011c61e4;

// @fnv 0x004ab220
const NiFixedString& FUN_004ab220()
{
    return *DAT_011c61e4;
}

struct FUN_004ad030_shell
{
    int pad0[75];
    int flags;
    bool GetFlag();
};

// @fnv 0x004ad030
bool FUN_004ad030_shell::GetFlag()
{
    return (flags & 0x2000) ? true : false;
}

extern int DAT_011f4300;

// @fnv 0x004ad1b0
int __cdecl FUN_004ad1b0()
{
    return DAT_011f4300;
}

namespace fnv_004ad1c0 {
extern unsigned char DAT_011a94a8;

// @fnv 0x004ad1c0
unsigned char __cdecl FUN_004ad1c0()
{
    return DAT_011a94a8;
}
}  // namespace fnv_004ad1c0

extern NiFixedString* DAT_011c61e8;

// @fnv 0x004ae780
const NiFixedString& __cdecl FUN_004ae780()
{
    return *DAT_011c61e8;
}

// @fnv 0x004af340
int FUN_004af340()
{
    return 5;
}

// @fnv 0x004af350
unsigned int FUN_004af350()
{
    return 2;
}

struct FUN_004aae50_shell : BipedAnim
{
    void FUN_004aae50();
};

// @fnv 0x004aae50
void FUN_004aae50_shell::FUN_004aae50()
{
    CompleteModelLoadTask();
}

struct FUN_004afb80_struct
{
    void __thiscall LockAtOffset();
};

struct FUN_004aaef0_shell
{
    FUN_004afb80_struct* m_p;
    void __thiscall CallContainedObject();
};

// @fnv 0x004aaef0
void __thiscall FUN_004aaef0_shell::CallContainedObject()
{
    m_p->LockAtOffset();
}

// Removes every biped part whose parent object is apForm, iterating over the 0x14 part slots.
// @fnv 0x004aaf90
void BipedAnim::RemovePartsByParent(TESForm* apForm)
{
    if (apForm == 0)
        return;
    for (int i = 0; i < 0x14; i++)
    {
        if (object[i].pParent == apForm)
            RemovePart((BIPED_OBJECT)i, 1, 0);
    }
}

struct FUN_004ad010_shell
{
    bool IsFlag4Set();
};
// @fnv 0x004ad010
bool FUN_004ad010_shell::IsFlag4Set()
{
    return *(unsigned char*)(this + 0x100) & 4;
}

struct Host0087b360
{
    void ProcessPackedTask(PackedTaskGsLocal_0087b360 const&);
    void FUN_0087b360(int a, int b);
};
// @fnv 0x0087b360
void Host0087b360::FUN_0087b360(int aiFirst, int aiSecond)
{
    PackedTaskGsLocal_0087b360 task;
    task.f0 = 0x15;
    task.f1 = aiFirst;
    task.f2 = aiSecond;
    ProcessPackedTask(task);
}

struct FUN_004aaf10_shell
{
    void __thiscall UnlockAtOffset();
    void __thiscall FUN_004aaf10();
};

// @fnv 0x004aaf10
void __thiscall FUN_004aaf10_shell::FUN_004aaf10()
{
    reinterpret_cast<FUN_004aaf10_shell*>(*reinterpret_cast<int*>(this))->UnlockAtOffset();
}

struct FUN_004ab730_shell
{
    bool __thiscall IsFlagSet();
};

// @fnv 0x004ab730
bool __thiscall FUN_004ab730_shell::IsFlagSet()
{
    return reinterpret_cast<unsigned char*>(this)[0x100] & 0x10;
}

struct FUN_004aaf30_Entry
{
    void* ptr;
    int f04;
    int f08;
    int f0C;
};
struct FUN_004aaf30_Holder
{
    char pad[0x2C];
    FUN_004aaf30_Entry entries[20];
    void* FindEntry(void* p);
};
// Searches the 20 entries for one whose ptr equals p and returns a pointer to it, or null if p is null or no match is found.
// @fnv 0x004aaf30
void* FUN_004aaf30_Holder::FindEntry(void* apTarget)
{
    int i;
    if (apTarget == 0)
        return 0;
    for (i = 0; i < 20; ++i)
    {
        if (entries[i].ptr == apTarget)
            return &entries[i];
    }
    return 0;
}

struct FUN_004adde0_shell
{
    unsigned char pad[0xbc];
    NiPointer<NiNode> m_ptr;
    void FUN_004adde0(NiNode* apGO);
};

// @fnv 0x004adde0
void FUN_004adde0_shell::FUN_004adde0(NiNode* apGO)
{
    m_ptr = apGO;
}

extern const char* DAT_01188b98[];
extern PlayerCharacter* _g_thePlayer;
struct FUN_004aeb20_holder : BipedAnim
{
    void AttachFaceGenModel(BSFaceGenModel* apfgModel, NiNode* apNode, BIPED_OBJECT aeBipedObject);
};
// @fnv 0x004aeb20
void FUN_004aeb20_holder::AttachFaceGenModel(BSFaceGenModel* apFaceGenModel, NiNode* apNode, BIPED_OBJECT aeBipedObject)
{
    NiNode* pcloneNode = 0;
    if (apFaceGenModel && apNode)
    {
        BIPED_BONE boneIndex = (BIPED_BONE)DAT_01188be8[aeBipedObject];
        bool b1st = false;
        if (m_pActor == _g_thePlayer && _g_thePlayer->IsPlayerBipedAnimation(this))
            b1st = true;
        pcloneNode = apNode;
        NiAVObject* ppartClone;
        bool bfirstPerson = false;
        bool bpipboy = object[6].pParent;
        if (m_pActor == _g_thePlayer && _g_thePlayer->IsPlayerBipedAnimation(this))
            bfirstPerson = true;
        ppartClone = PrepareBipedModel(pcloneNode, aeBipedObject, bfirstPerson, bpipboy, apFaceGenModel);
        if (!ppartClone)
        {
            ppartClone = pcloneNode;
            AttachFaceGenNode(root, pcloneNode, 0, this, aeBipedObject, apFaceGenModel);
        }
        if (ppartClone)
        {
            BSStringT<char> newName;
            newName.PrintfString("%s %s (%08X)", DAT_01188b98[aeBipedObject], object[aeBipedObject].pParent->GetName(),
                            object[aeBipedObject].pParent->GetFormID());
            ppartClone->SetName(NiFixedString(newName));
            ApplyReferenceExtraData(apNode, pcloneNode, aeBipedObject, m_pActor);
            if (!object[aeBipedObject].bHasAnimation && ppartClone->IsSceneNode())
            {
                NiNode* pparent = ppartClone->GetParent();
                if (bone[boneIndex].pParent)
                    bone[boneIndex].pParent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(ppartClone), true);
                else if (ppartClone->GetParent())
                    root->AttachChildInAvailableSlot(static_cast<NiAVObject*>(ppartClone), true);
            }
            object[aeBipedObject].m_pSceneObject = ppartClone;
        }
    }
    if (m_pActor && m_pActor->Get3DSimple())
        m_pActor->Get3DSimple()->UpdateSceneObject();
}

struct TESObjectSTAT;
struct FUN_004ab500_shell : TESObjectWEAP
{
    TESObjectSTAT* GetModSlotStat(unsigned char iModSlots);
};
// Returns the TESObjectSTAT pointer stored at one of eight offsets selected by the low three bits of iModSlots.
// @fnv 0x004ab500
TESObjectSTAT* FUN_004ab500_shell::GetModSlotStat(unsigned char uiModSlotMask)
{
    if (uiModSlotMask & 1)
    {
        if (uiModSlotMask & 2)
        {
            if (uiModSlotMask & 4)
            {
                return *(TESObjectSTAT**)((char*)this + 0x26c);
            }
            else
            {
                return *(TESObjectSTAT**)((char*)this + 0x260);
            }
        }
        else
        {
            if (uiModSlotMask & 4)
            {
                return *(TESObjectSTAT**)((char*)this + 0x268);
            }
            else
            {
                return *(TESObjectSTAT**)((char*)this + 0x254);
            }
        }
    }
    else
    {
        if (uiModSlotMask & 2)
        {
            if (uiModSlotMask & 4)
            {
                return *(TESObjectSTAT**)((char*)this + 0x264);
            }
            else
            {
                return *(TESObjectSTAT**)((char*)this + 0x258);
            }
        }
        else
        {
            if (uiModSlotMask & 4)
            {
                return *(TESObjectSTAT**)((char*)this + 0x25c);
            }
            else
            {
                return *(TESObjectSTAT**)((char*)this + 0x250);
            }
        }
    }
}

struct FUN_004aad00_shell
{
    struct BoneEntry
    {
        unsigned char flag;
        unsigned char pad[3];
        NiAVObject* bone;
    };

    NiAVObject* root;
    BoneEntry bones[5];

    void InitBoneSlots(NiAVObject*);
};

extern const char* DAT_01188b74[5];

// Looks up the root "Bip01" and five named bones under pBone, storing each found bone and setting its flag, or warning when a bone is missing.
// @fnv 0x004aad00
void FUN_004aad00_shell::InitBoneSlots(NiAVObject* pBone)
{
    int i;

    root = SceneObjectLookup::GetObjectByName(pBone, "Bip01");

    for (i = 0; i < 5; ++i)
    {
        GO bone(reinterpret_cast<int>(SceneObjectLookup::GetObjectByName(pBone, DAT_01188b74[i])));

        if (bone.operator unsigned int() && reinterpret_cast<NiAVObject*>(bone.operator unsigned int())->IsSceneNode())
        {
            bones[i].flag |= 1;
            bones[i].bone = reinterpret_cast<NiAVObject*>(bone.operator unsigned int());
        }
        else
        {
            Warning("MODELS: Missing bone '%s' for '%s'", DAT_01188b74[i],
                    reinterpret_cast<BSFadeNode*>(const_cast<NiFixedString*>(&pBone->GetName()))->FUN_0043b1b0());
        }
    }
}

struct StatFormPart
{
    virtual void vfn_0();
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
};
struct StaticObj : public StatFormPart, public TESModel
{
};

struct WeapAccess : public TESObjectWEAP
{
    TESModel* GetModTESModel(unsigned char iModSlots, bool abFirst);
    StaticObj* GetStaticModel();
    StaticObj* GetModStatic(unsigned char iModSlots);
};

struct BipedAnimWeap : public BipedAnim
{
    void SetWeaponModel(TESObjectWEAP* apWeapon, unsigned char iModSlots);
};

// Removes the weapon biped part, resolves the weapon's mod/static TESModel, and stores the weapon and model into the BIPED_OBJECT_BO_WEAPON slot.
// @fnv 0x004ab400
void BipedAnimWeap::SetWeaponModel(TESObjectWEAP* apWeapon, unsigned char iModSlots)
{
    if (!apWeapon || apWeapon->GetFormType() != 0x28 ||
        (apWeapon == object[BIPED_OBJECT_BO_WEAPON].pParent && object[BIPED_OBJECT_BO_WEAPON].m_pSceneObject))
        return;

    RemovePart(BIPED_OBJECT_BO_WEAPON, true, 0);
    TESModel* m_kModelObjectsItem = ((WeapAccess*)apWeapon)->GetModTESModel(iModSlots, true);
    if (this == g_thePlayer->GetBipedAnimation(true) || this == g_thePlayer->GetBipedAnimation(false))
    {
        StaticObj* pStaticModel = ((WeapAccess*)apWeapon)->GetStaticModel();
        if (iModSlots && apWeapon->GetFormID() != 0x1735d4)
        {
            StaticObj* pModStaticModel = 0;
            pModStaticModel = ((WeapAccess*)apWeapon)->GetModStatic(iModSlots);
            if (pModStaticModel)
                pStaticModel = pModStaticModel;
        }
        if (pStaticModel)
            m_kModelObjectsItem = pStaticModel;
    }
    object[BIPED_OBJECT_BO_WEAPON].pParent = apWeapon;
    object[BIPED_OBJECT_BO_WEAPON].m_pModel = m_kModelObjectsItem;
}

struct NotificationProbe : NiAVObject
{
    virtual void UpdateAttach(NiAVObject*, int);
};
struct SkinDataProbe
{
    unsigned int FUN_008041a0();
};
struct SkinInstanceProbe : NiSkinInstance
{
    void FUN_00437730(NiAVObject*);
};
struct SceneNodeProbe : NiNode
{
    NiAVObject* FUN_009611e0();
};
struct HandleVectorProbe
{
    void FUN_004afc50(const NiPointer<NiAVObject>&);
};
extern bool __cdecl FUN_0043b300(const NiRTTI*, NiNode*);
extern const char* __cdecl FUN_0044a670(const char*);
extern int __cdecl FUN_00ec7ec0(const char*, const char*, const char*);
extern void __cdecl FUN_005b5e40(const char*, ...);
extern const char DAT_0101f8d8[];
extern const char DAT_0101f890[];
extern const char DAT_0101f840[];
extern const char DAT_0101f7c8[];

// @fnv 0x004ade40
void __cdecl FUN_004ade40(NiNode* source, NiAVObject* object, NiAVObject* notify, bool report)
{
    if (!object)
        return;

    NiNode* node = object->IsSceneNode();
    if (object->IsGeometry())
    {
        NiSkinInstance* geometry;
        NiTriBasedGeom* skin = static_cast<NiTriBasedGeom*>(object);
        geometry = skin->GetSkinInstance();
        if (geometry)
        {
            NiAVObject* boneCount;
            unsigned int replacement = reinterpret_cast<SkinDataProbe*>(geometry->GetData())->FUN_008041a0();
            NiAVObject** bones = geometry->GetBones();
            for (unsigned int i = 0; i < replacement; ++i)
            {
                if (bones[i])
                {
                    boneCount = FUN_004ade00(source, bones[i]->GetName());
                    if (boneCount)
                    {
                        geometry->SetBone(i, boneCount);
                    }
                    else
                    {
                        geometry->SetBone(i, source);
                        if (report)
                        {
                            if (node && !FUN_00ec7ec0((const char*)object->GetName(), (const char*)bones[i]->GetName(),
                                                      FUN_0044a670((const char*)bones[i]->GetName())))
                            {
                                FUN_005b5e40(DAT_0101f8d8, (const char*)bones[i]->GetName(),
                                             (const char*)static_cast<SceneNodeProbe*>(node)->FUN_009611e0()->GetName(),
                                             (const char*)node->GetName());
                            }
                            else if (node && source)
                            {
                                FUN_005b5e40(DAT_0101f890, (const char*)bones[i]->GetName(),
                                             (const char*)node->GetName(), (const char*)source->GetName());
                            }
                            else
                            {
                                FUN_005b5e40(DAT_0101f840, (const char*)bones[i]->GetName());
                            }
                        }
                    }
                }
            }
            if (notify)
            {
                reinterpret_cast<SkinInstanceProbe*>(geometry)->FUN_00437730(notify);
                static_cast<NotificationProbe*>(notify)->UpdateAttach(object, 1);
            }
        }
    }
    bool printed = false;
    if (node)
    {
        node->FUN_004add70();
        GlobalObject_004aff00 children(0, 1);
        for (unsigned int j = 0; j < node->FUN_0043b480(); ++j)
        {
            NiAVObject* childNode = node->FUN_0043b4a0(j);
            NiNode* child = 0;
            if (childNode)
                child = childNode->IsSceneNode();
            else
                continue;
            if (FUN_0043b300(&DAT_011f9140, node) && child)
            {
                FUN_004ade40(source, childNode, notify, true);
                continue;
            }
            if (!childNode->IsGeometry())
            {
                if (!printed && child && reinterpret_cast<NiNode*>(childNode)->FUN_00453470())
                {
                    FUN_005b5e40(DAT_0101f7c8,
                                 (const char*)static_cast<SceneNodeProbe*>(node)->FUN_009611e0()->GetName(),
                                 (const char*)node->GetName(), (const char*)source->GetName());
                    printed = true;
                }
                {
                    NiPointer<NiAVObject> item(childNode);
                    reinterpret_cast<HandleVectorProbe*>(&children)->FUN_004afc50(item);
                }
                node->RemoveObject(childNode);
                continue;
            }
            FUN_004ade40(source, childNode, notify, report);
        }
        node->FUN_004add70();
    }
}

class ATM
{
  public:
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
int __cdecl strcpy_s(char*, unsigned int, const char*);
BSFaceGenModel* __cdecl GetOrCreateFaceGenModel(void*, int, int, int, int, int, int);
void* __cdecl BuildEgmFilename(BSStringT<char>*, const char*, int);
struct FaceLoader : BipedAnim
{
    BSFaceGenModel* FUN_004ae790(int slot);
};
// @fnv 0x004ae790
BSFaceGenModel* FaceLoader::FUN_004ae790(int slot)
{
    ((ATM*)&g_011c5cf0)->QueryPerformanceCounter(0);
    TESModel* model = object[slot].m_pModel;
    BSFaceGenModel* result = 0;
    if (model)
    {
        BSStringT<char> name;
        char path[260];
        strcpy_s(path, 260, "Meshes\\");
        strcat_s(path, 260, model->GetModelFilePath());
        result = GetOrCreateFaceGenModel(BuildEgmFilename(&name, path, -1), 0, 0, 0, 1, -1, 0);
    }
    ((ATM*)&g_011c5cf0)->WaitForTasksDuringRendering();
    return result;
}

struct C4AEDE0Object;

class C4AEDE0Ptr
{
  public:
    C4AEDE0Ptr(C4AEDE0Object* pkObject);
    ~C4AEDE0Ptr();

    C4AEDE0Object* m_pPointer;
};

class C4AEDE0Queue
{
  public:
    void QueueFull(int iA, int iB, C4AEDE0Ptr& spResult, int iC);
    void QueueItem(int iA, int iB, int iC);
};

// Constructs a null C4AEDE0Ptr and passes it with iA, iB and iC to QueueFull.
// @fnv 0x004aede0
void C4AEDE0Queue::QueueItem(int iA, int iB, int iC)
{
    C4AEDE0Ptr spResult(0);
    QueueFull(iA, iB, spResult, iC);
}

class B4AEE60Owner;

class B4AEE60Request
{
  public:
    void* Get();
    void FUN_006f74f0(void* pvResult);
};

struct B4AEE60Slot
{
    int m_iHandle;
    int unk04;
    int unk08;
    int unk0C;
};

class B4AEE60ModelLoader
{
  public:
    void FUN_004450c0(B4AEE60Owner* pkOwner, B4AEE60Request* pkRequest, int iParamA, int iParamB, int iSlot);
};

extern B4AEE60ModelLoader* g_pModelLoader;

class B4AEE60Owner
{
  public:
    void RequestModelLoad(int iParamA, int iParamB, B4AEE60Request* pkRequest, int iSlot);

    int unk00;
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
    B4AEE60Slot m_akSlots[4];
};

// If the request has no result yet, starts a model load for the given slot when its handle is valid, otherwise completes the request with null.
// @fnv 0x004aee60
void B4AEE60Owner::RequestModelLoad(int iParamA, int iParamB, B4AEE60Request* pkRequest, int iSlot)
{
    if (pkRequest->Get())
        return;

    if (m_akSlots[iSlot].m_iHandle != 0 && m_akSlots[iSlot].m_iHandle != -1)
        g_pModelLoader->FUN_004450c0(this, pkRequest, iParamA, iParamB, iSlot);
    else
        pkRequest->FUN_006f74f0(0);
}

struct ActorCalls
{
    BaseProcess* FUN_008d8520();
    void FUN_008b0b00(bool);
    Animation* FUN_008b70d0();
    bool FUN_008a16d0();
};
struct PlayerCalls
{
    bool FUN_00950b30(BipedAnim*);
    BipedAnim* FUN_00950b00(bool);
};
struct BGSLoadShell
{
    bool FUN_0042ce10();
};
struct AnimShell
{
    void FUN_004994f0(int, bool);
};
extern BGSLoadShell* DAT_011ddf38;
NiAVObject* __cdecl FUN_004aeed0(TESForm*, TESModel*, int, TESObjectREFR*, NiNode*);
int __cdecl FUN_00406f60(void*, const char*, ...);
struct FUN_004ab750_shell : BipedAnim
{
    void FUN_004ab750(TESObjectWEAP* apWeapon, unsigned char iModSlots);
};
// Rebuilds the weapon model for a weapon form, names it, and updates the actor's animation and weapon-drawn state.
// @fnv 0x004ab750
void FUN_004ab750_shell::FUN_004ab750(TESObjectWEAP* apWeapon, unsigned char iModSlots)
{
    if (!apWeapon || (int)apWeapon->GetFormType() != 0x28 ||
        (apWeapon == object[5].pParent && object[5].m_pSceneObject))
        return;
    {
        ((BipedAnimWeap*)this)->SetWeaponModel(apWeapon, iModSlots);
        int slot = 5;
        if (m_pActor == _g_thePlayer)
            object[5].m_pSceneObject =
                FUN_004aeed0(object[5].pParent, object[5].m_pModel, slot, m_pActor,
                             _g_thePlayer->GetNode(((PlayerCalls*)_g_thePlayer)->FUN_00950b30(this)));
        else
            object[5].m_pSceneObject = FUN_004aeed0(object[5].pParent, object[5].m_pModel, slot, m_pActor, 0);
        if (!object[5].m_pSceneObject)
            return;
        {
            BSStringT<char> str;
            FUN_00406f60(&str, "%s %s (%08X)", DAT_01188b98[5], object[5].pParent->GetName(),
                         object[5].pParent->GetFormID());
            object[5].m_pSceneObject->SetName(NiFixedString((const char*)str));
            if (((FUN_004ab730_shell*)apWeapon)->IsFlagSet() && object[7].m_pSceneObject)
                object[7].m_pSceneObject->FUN_00450f90(true);
            if (m_pActor->IsActor())
            {
                TESObjectREFR* pActor = m_pActor;
                BaseProcess* pProc = ((ActorCalls*)pActor)->FUN_008d8520();
                if (pProc && !g_dataHandler->FUN_004226e0() && !g_TESSaveLoadGame->GetLoading() &&
                    this != ((PlayerCalls*)_g_thePlayer)->FUN_00950b00(true))
                    ((ActorCalls*)pActor)->FUN_008b0b00(true);
                if (pProc && !DAT_011ddf38->FUN_0042ce10())
                {
                    Animation* anim = 0;
                    if (m_pActor == _g_thePlayer && this == ((PlayerCalls*)_g_thePlayer)->FUN_00950b00(true))
                        anim = _g_thePlayer->GetAnimation(true);
                    else
                        anim = ((ActorCalls*)pActor)->FUN_008b70d0();
                    if (anim)
                        ((AnimShell*)anim)->FUN_004994f0(4, false);
                    if (m_pActor == _g_thePlayer && this == ((PlayerCalls*)_g_thePlayer)->FUN_00950b00(true))
                        ((ActorCalls*)pActor)
                            ->FUN_008d8520()
                            ->PlayAnimation(((ActorCalls*)pActor)->FUN_008a16d0(), this,
                                                _g_thePlayer->GetAnimation(true), (Actor*)pActor);
                    else
                        ((ActorCalls*)pActor)
                            ->FUN_008d8520()
                            ->PlayAnimation(((ActorCalls*)pActor)->FUN_008a16d0(), this,
                                                ((ActorCalls*)pActor)->FUN_008b70d0(), (Actor*)pActor);
                }
            }
        }
    }
}

struct BuildContext
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    BuildContext(float);
    ~BuildContext();
};
struct LoadedObject
{
    void SetFlags(int);
    void SetName(void*);
    void SetTransform(void*);
};
struct ModelSource
{
    LoadedObject* Load(BuildContext*);
};
struct ObjectPtr
{
    LoadedObject* value;
    ObjectPtr(int);
    ~ObjectPtr();
    void Assign(LoadedObject*);
    LoadedObject* Get();
};
struct Loader
{
    LoadedObject* Load(ModelSource*, BuildContext*);
};
extern Loader* DAT_011dea10;
extern int DAT_011f426c;
bool __cdecl IsSpecial(ModelSource*);
void __cdecl FinishObject(LoadedObject*);
struct Attachment
{
    void Attach(LoadedObject*);
};
struct ParentObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual Attachment* GetAttachment();
};
struct FormObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual bool IsReady();
};
struct EquipSlot
{
    FormObject* form;
    ParentObject* parent;
    LoadedObject* object;
    int unk0C;
};
struct FUN_004ae910_cls
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    EquipSlot slots[20];
    LoadedObject* LoadSlotObject(void*, ModelSource*, int);
};
// @fnv 0x004ae910
LoadedObject* FUN_004ae910_cls::LoadSlotObject(void* owner, ModelSource* source, int slot)
{
    if (slots[slot].object)
        return 0;
    if (owner && source)
    {
        int aId = DAT_01188be8[slot];
        BuildContext context(1.0f);
        ObjectPtr holder(0);
        LoadedObject* pTemp;
        if (IsSpecial(source))
        {
            holder.Assign(DAT_011dea10->Load(source, &context));
            pTemp = holder.Get();
        }
        else
        {
            pTemp = source->Load(&context);
        }
        LoadedObject* kObj = pTemp;
        int unused = 0;
        if (kObj)
        {
            if (FUN_0043b300(&DAT_011f9140, (NiNode*)kObj))
            {
                LoadedObject* pLoadedObject = kObj;
                pLoadedObject->SetFlags(7);
            }
            kObj->SetName(&DAT_011f426c);
            kObj->SetTransform(&DAT_011a9448);
            if (slots[slot].parent)
            {
                Attachment* attachment = slots[slot].parent->GetAttachment();
                if (attachment)
                    attachment->Attach(kObj);
            }
            if (slots[slot].form && slots[slot].form->IsReady())
                FinishObject(kObj);
            return kObj;
        }
    }
    return 0;
}

struct CloneContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float x;
    float y;
    float z;
    CloneContext(float);
    ~CloneContext();
};
struct ObjectOps : NiAVObject
{
    NiAVObject* CloneWith(CloneContext&);
    void ClearData();
    void Finish();
    int ParentCount();
    void SetType(int);
};
struct TesOps
{
    NiAVObject* CloneModel(NiAVObject*, CloneContext&);
};
bool FUN_004b5bf0(NiAVObject*);
void FUN_004b7660(NiAVObject*);
void FUN_004af240(NiAVObject*, NiAVObject*, int, TESObjectREFR*);
void FUN_00578060(NiAVObject*);
void FUN_004ae250(NiAVObject*, NiAVObject*, NiAVObject*, int, int, int);
bool FUN_0043b300(const NiRTTI*, NiAVObject*);

void FNV_Warning(const char*, ...);
NiAVObject* FUN_004aae30(NiAVObject*, NiFixedString*);
// @fnv 0x004aeed0
NiAVObject* __cdecl FUN_004aeed0(TESForm* form, TESModel* model, int slot, TESObjectREFR* ref, NiAVObject* root)
{
    if (!model || !ref)
        return 0;
    const char* pathB = model->GetModelFilePath();
    if (!pathB || !*pathB)
        return 0;
    NiAVObject* target4 = root;
    if (!target4)
        target4 = ref->Get3DSimple();
    if (!target4)
        return 0;
    NiAVObject* parent5 = target4;
    NiAVObject* loaded6 = g_modelLoader->LoadFile(pathB, 3, true, false, false, false);
    CloneContext context4(1.0f);
    NiPointer<NiAVObject> copy3(0);
    NiAVObject* selected3;
    if (FUN_004b5bf0(loaded6))
    {
        copy3 = ((TesOps*)g_TES)->CloneModel(loaded6, context4);
        selected3 = copy3;
    }
    else
        selected3 = ((ObjectOps*)loaded6)->CloneWith(context4);
    NiAVObject* result5 = selected3;
    bool skinned2 = false;
    TESModelTextureSwap* swapTmp = model->GetAsModelMaterialSwap();
    if (swapTmp)
        swapTmp->ApplyTextureSwaps(result5);
    if (form && form->Unk_2B())
        FUN_004b7660(result5);
    FUN_004af240(loaded6, result5, slot, ref);
    FUN_00578060(result5);
    NiPointer<NiExtraData> extra(result5->GetExtraData(FUN_004ab220()));
    ((ObjectOps*)result5)->ClearData();
    if (extra)
    {
        result5->AddExtraData(FUN_004ab220(), extra);
        extra = 0;
    }
    if (result5)
    {
        if (FUN_0043b300(&DAT_011f9140, result5))
        {
            NiAVObject* fade = result5;
            ((ObjectOps*)fade)->SetType(7);
        }
        result5->FUN_00440460(NiPoint3::ZERO);
        result5->FUN_0043fa80(DAT_011a9448);
        if (FUN_004910d0((NiNode*)result5))
            skinned2 = true;
        if (skinned2)
            FNV_Warning("MODELS: Tyring to add skinned object '%s' as an add on to skeleton.",
                        (const char*)result5->GetName());
        else
            FUN_004ae250(parent5, result5, loaded6, 0, slot, 0);
        if (!skinned2 && result5->IsSceneNode())
        {
            int count9 = ((ObjectOps*)result5)->ParentCount();
            NiAVObject* attach7 = 0;
            if (!count9)
            {
                if (slot != -1 && DAT_01188be8[slot] != -1)
                {
                    NiAVObject* found5 = FUN_004aae30(parent5, (NiFixedString*)DAT_01188b74[DAT_01188be8[slot]]);
                    attach7 = found5;
                }
                if (attach7)
                    ((NiNode*)attach7)->AttachChildInAvailableSlot(static_cast<NiAVObject*>(result5), true);
                else
                    ((NiNode*)parent5)->AttachChildInAvailableSlot(static_cast<NiAVObject*>(result5), true);
            }
        }
        ((ObjectOps*)result5)->Finish();
    }
    return result5;
}

class BipedAnimHelper : public BipedAnim
{
  public:
    void ApplySkinTextures(NiAVObject* apObject, bool abArg2);
};

// Resolves the biped object's skin textures for the NPC and applies them to the shader property, warning if the race texture is missing.
// @fnv 0x004af490
void BipedAnimHelper::ApplySkinTextures(NiAVObject* apObject, bool abArg2)
{
    BSShaderPPLightingProperty* pLightingProp5 = FindLightingShaderProperty(apObject);
    if (!pLightingProp5)
        return;

    int bipedObject = GetBipedObjectFromShaderProperty(apObject, pLightingProp5);
    if (bipedObject == -1)
        return;

    FaceGenCoord coords3[4];

    TESNPC* pNPC = dynamic_cast<TESNPC*>(m_pActor->GetObjectReference());

    NiPointer<NiTexture> _ptrA(0);
    NiPointer<NiTexture> ptrB3(0);

    if (pNPC)
        pNPC->GetFaceGenCoords(coords3);

    bool bResultTmp = false;
    if (abArg2)
        bResultTmp = pNPC->FUN_004ac110()->GetSkinTextures(_ptrA, ptrB3, pNPC, (BIPED_OBJECT)bipedObject, true);
    else
        bResultTmp = pNPC->FUN_004ac110()->GetSkinTextures(_ptrA, ptrB3, pNPC, (BIPED_OBJECT)bipedObject, false);

    if (pNPC && !bResultTmp)
    {
        Warning("TEXTURES: Missing '%s' race texture for '%s' in race '%s'.",
                FUN_00464f30(DAT_01199e8c[((TESActorBase*)pNPC)->GetSex()], false),
                FUN_00464f30(DAT_01188b98[bipedObject], true), pNPC->FUN_004ac110()->TESFullName::GetFullName());
    }
    else
    {
        reinterpret_cast<PPLightingTextureSlots*>(pLightingProp5)->SetTexture(0, _ptrA);

        NiSourceTexture* pSourceTex = (NiSourceTexture*)FUN_00653270(&DAT_011f444c, (NiProperty*)(NiTexture*)_ptrA);
        const char* pFilename = 0;
        bool bUnknown9 = true;
        if (pSourceTex)
        {
            bUnknown9 = !pSourceTex->FUN_004af860();
            pSourceTex->FUN_004af880();
            pFilename = pSourceTex->GetFilename();
        }

        char buffer[260];
        FUN_00b4f5e0(buffer, pFilename, "_n", true);
        if (buffer[0])
        {
            NiPointer<NiTexture> normalTexX(0);
            FUN_00b55840(buffer, bUnknown9, normalTexX, true, false);
            if (normalTexX)
                reinterpret_cast<PPLightingTextureSlots*>(pLightingProp5)->SetNormalTexture(0, normalTexX);
        }

        reinterpret_cast<PPLightingTextureSlots*>(pLightingProp5)->SetTexture(1, ptrB3);
        reinterpret_cast<PPLightingTextureSlots*>(pLightingProp5)->SetNormalTexture(1, FUN_004af8a0());
        pLightingProp5->SetFlag(10, true);
    }
}

namespace fnv_004ad050 {
struct NiObjectCopyInfo
{
    int unk00, unk04, unk08, unk0c;
    NiObjectCopyInfo(unsigned int);
    ~NiObjectCopyInfo();
};
struct BaseS
{
    BaseS();
};
struct FUN_004ad240_c
{
    void SetScale(float);
};
struct FUN_004ad050 : NiObjectCopyInfo
{
    BaseS m10;
    FUN_004ad050(float f);
};
// Constructs a NiObjectCopyInfo with type 257 and sets its scale to f.
// @fnv 0x004ad050
FUN_004ad050::FUN_004ad050(float afScale) : NiObjectCopyInfo(257)
{
    ((FUN_004ad240_c*)this)->SetScale(afScale);
}
}  // namespace fnv_004ad050

struct BipedLoadAccess : BipedAnim
{
    void UpdateBipedObjects(bool);
    void ApplySkinTextures(NiAVObject*, bool);
    void FUN_004ab750(TESObjectWEAP*, unsigned char);
};
struct ActorLoadAccess : Actor
{
    void FUN_00571760(TESObjectWEAP*);
    bool FUN_008a16d0();
    Animation* FUN_008b70d0();
};
struct PlayerLoadAccess : PlayerCharacter
{
    BipedAnim* FUN_00950b00(bool);
};
struct ItemLoadAccess : InventoryStackRecord
{
    unsigned char FUN_004bd820();
    bool FUN_004bd8d0(unsigned char, float&);
};
struct WeapLoadAccess : TESObjectWEAP
{
    bool FUN_004ad030();
};

struct DataLoadAccess : NiGeometryData
{
    void FUN_00a5d510(NiPointer<NiGeometryData>&);
};
struct CloneLoadAccess : NiNode
{
    NiObject* FUN_00a5d2c0(CloningProcess&);
    void FUN_00a5a040();
};
struct TESLoadAccess : TES
{
    NiNode* FUN_00457ba0(NiNode*, CloningProcess&);
};
struct ExtraLoadAccess : ExtraDataList
{
    ExtraDismemberedLimbs* FUN_0042e8c0();
};
struct RefrLoadAccess : TESObjectREFR
{
    ExtraLoadAccess* FUN_005d43c0();
};
struct NodeLoadAccess : NiNode
{
    void FUN_00b4dec0(int);
};
void FUN_004b7660(NiNode*);
bool FUN_004b5bf0(NiAVObject*);
bool FUN_004abfa0();
void FUN_00709c20(TESModel*);
void FUN_004af240(NiNode*, NiNode*, BIPED_OBJECT, TESObjectREFR*);
int __cdecl FUN_00406f60(BSStringT<char>*, const char*, ...);
// Rebuilds the biped's 20 equipment slots by loading or reusing NIF models, applying textures and face-gen morphs, and attaching them to the actor's skeleton.
// @fnv 0x004ac1e0
void BipedLoadAccess::UpdateBipedObjects(bool force)
{
    bool hasHead = false;
    bool first = object[6].pParent;
    if (m_pActor == g_thePlayer && g_thePlayer->IsPlayerBipedAnimation(this))
        hasHead = true;
    if (DAT_011c5cb4)
        FUN_006570e0(m_pActor->GetObjectReference());
    for (int slot = 0; slot < 20; slot++)
    {
        if (object[slot].m_pModel && object[slot].m_pModel == m_kPreviousObjects[slot].m_pModel &&
            object[slot].pParent == m_kPreviousObjects[slot].pParent && m_kPreviousObjects[slot].m_pSceneObject)
        {
            bool reload = false;
            object[slot] = m_kPreviousObjects[slot];
            memset(&m_kPreviousObjects[slot], 0, sizeof(BipedAnimObject));
            if (DAT_011c5cb4 && object[slot].m_pSceneObject)
            {
                NiNode* existing = object[slot].m_pSceneObject->IsSceneNode();
                if (existing)
                {
                    for (unsigned int child = 0; child < existing->FUN_0043b480(); child++)
                        ApplySkinTextures(existing->FUN_0043b4a0(child), false);
                }
                else
                    ApplySkinTextures(object[slot].m_pSceneObject, false);
            }
            if (slot == 7 && object[5].pParent && ((FUN_004ab730_shell*)object[5].pParent)->IsFlagSet() &&
                object[slot].m_pSceneObject)
                object[slot].m_pSceneObject->FUN_00450f90(true);
            if (!reload)
                continue;
        }
        else
        {
            if (m_kPreviousObjects[slot].m_pSceneObject)
                ClearBipedObject(&m_kPreviousObjects[slot], true, 0);
            else
                memset(&m_kPreviousObjects[slot], 0, sizeof(BipedAnimObject));
        }
        bool mods = false;
        unsigned char modScope = 0;
        if (slot == 5 && object[slot].pParent)
        {
            if (m_pActor == g_thePlayer)
            {
                TESObjectWEAP* weapon = (TESObjectWEAP*)object[slot].pParent;
                ItemLoadAccess* pWeaponInfo = (ItemLoadAccess*)g_thePlayer->GetProcess()->GetActiveWeapon();
                modScope = pWeaponInfo->FUN_004bd820();
                float info = 0.0f;
                mods = pWeaponInfo->FUN_004bd8d0(14, info);
                FUN_004ab750(weapon, modScope);
                if (weapon->GetHasScope() && this == ((PlayerLoadAccess*)g_thePlayer)->FUN_00950b00(false))
                {
                    if (!((WeapLoadAccess*)weapon)->FUN_004ad030() || mods)
                        FUN_00709c20(weapon->FUN_00504e60());
                }
            }
            else
                ((ActorLoadAccess*)m_pActor)->FUN_00571760((TESObjectWEAP*)object[slot].pParent);
            continue;
        }
        if (object[slot].m_pModel && object[slot].m_pModel != (TESModel*)-1)
        {
            if (hasHead)
            {
                switch (slot)
                {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    break;
                default:
                    continue;
                }
            }
            if (!force && IsSlotHidden((BIPED_OBJECT)slot) && m_pActor != g_thePlayer && *DAT_011c5ef0.Bool() &&
                FUN_0043faf0() && FUN_004abfa0())
            {
                QueueItem(IO_TASK_PRIORITY_IO_TASK_PRIORITY_CRITICAL, 0, (BIPED_OBJECT)slot);
                continue;
            }
            if (!object[slot].m_pModel->GetModelLength())
                continue;
            int node = DAT_01188be8[slot];
            NiAVObject* result;
            NiNode* _clone = g_modelLoader->LoadFile(object[slot].m_pModel->GetModelFilePath(), 3, true, false,
                                                     IsSlotHidden((BIPED_OBJECT)slot), false);
            CloningProcess boneIndex(1.0f);
            NiPointer<NiNode> copy(0);
            NiObject* model;
            if (FUN_004b5bf0(_clone))
            {
                copy = ((TESLoadAccess*)g_TES)->FUN_00457ba0(_clone, boneIndex);
                model = copy;
            }
            else
                model = ((CloneLoadAccess*)_clone)->FUN_00a5d2c0(boneIndex);
            NiNode* boneIndexd = model->IsSceneNode();
            result = 0;
            if (boneIndexd)
            {
                TESModelTextureSwap* fade = object[slot].m_pModel ? object[slot].m_pModel->GetAsModelMaterialSwap() : 0;
                if (fade)
                    fade->ApplyTextureSwaps(boneIndexd);
                if (object[slot].pParent && object[slot].pParent->Unk_2B())
                    FUN_004b7660(boneIndexd);
                BSFadeNode* swap = boneIndexd->IsFadeNode();
                if (swap)
                    ((NodeLoadAccess*)swap)->FUN_00b4dec0(7);
                boneIndexd->FUN_00440460(NiPoint3::ZERO);
                boneIndexd->FUN_0043fa80(DAT_011a9448);
                result = PrepareBipedModel(boneIndexd, (BIPED_OBJECT)slot, hasHead, first, 0);
                if (!result)
                {
                    result = boneIndexd;
                    if (this && IsSlotHidden((BIPED_OBJECT)slot))
                    {
                        BSFaceGenModel* face = GetFaceGenModelForSlot((BIPED_OBJECT)slot);
                        if (face)
                        {
                            for (unsigned int index = 0; index < boneIndexd->FUN_0043b480(); index++)
                            {
                                NiAVObject* childNode = boneIndexd->FUN_0043b4a0(index);
                                NiTriBasedGeom* geometry = childNode->IsTriBasedGeometry();
                                if (childNode && !geometry)
                                    FUN_005b5e40("FaceGen NIF contains non-geometry at root: '%s'",
                                                 object[slot].m_pModel->GetModelFilePath());
                                if (geometry && geometry->FUN_005495f0() && m_pActor &&
                                    m_pActor->GetObjectReference() &&
                                    m_pActor->GetObjectReference()->GetFormType() == ENUM_FORM_ID_NPC__ID)
                                {
                                    TESNPC* newData = (TESNPC*)m_pActor->GetObjectReference();
                                    FaceGenCoord coords[4];
                                    NiPointer<NiGeometryData> data(0);
                                    NiPointer<NiGeometryData> npc(0);
                                    ((DataLoadAccess*)geometry->FUN_005495f0())->FUN_00a5d510(data);
                                    npc = (NiGeometryData*)data;
                                    geometry->ReplaceModelData(npc);
                                    newData->GetFaceGenCoords(coords);
                                    if (!FUN_0043faf0() || face->ApplyFaceGenMorphs(&coords, geometry, false))
                                    {
                                        NiMatrix3 rotation;
                                        rotation.MakeYRotation(-1.57079637f);
                                        geometry->FUN_0043fa80(geometry->FUN_006a9540() * rotation);
                                    }
                                }
                            }
                        }
                    }
                    AttachFaceGenNode(root, boneIndexd, 0, this, (BIPED_OBJECT)slot, 0);
                    if (!g_TESSaveLoadGame->GetLoading() && slot == 5)
                    {
                        ActorLoadAccess* actor = (ActorLoadAccess*)m_pActor;
                        if (actor->GetProcess())
                        {
                            if (m_pActor == g_thePlayer && this == ((PlayerLoadAccess*)g_thePlayer)->FUN_00950b00(true))
                                actor->GetProcess()->PlayAnimation(actor->FUN_008a16d0(), this,
                                                                       g_thePlayer->GetAnimation(true), actor);
                            else
                                actor->GetProcess()->PlayAnimation(actor->FUN_008a16d0(), this,
                                                                       actor->FUN_008b70d0(), actor);
                        }
                    }
                }
            }
            if (result)
            {
                BSStringT<char> name;
                FUN_00406f60(&name, "%s %s (%08X)", DAT_01188b98[slot], object[slot].pParent->GetName(),
                             object[slot].pParent->GetFormID());
                result->SetName(NiFixedString(name));
                FUN_004af240(_clone, boneIndexd, (BIPED_OBJECT)slot, m_pActor);
                if (!object[slot].bHasAnimation && result->IsSceneNode())
                {
                    NiNode* parent = result->GetParent();
                    if (node == -1)
                    {
                        FUN_005b5e40("MODELS: The biped part '%s' should be skinned for '%s'.",
                                     object[slot].m_pModel->GetModelFilePath(), m_pActor->GetFullName());
                        if (parent)
                            parent->RemoveObject(result);
                        else
                        {
                            NiPointer<NiAVObject> release(result);
                        }
                        result = 0;
                    }
                    else
                    {
                        if (bone[node].pParent)
                            bone[node].pParent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(result), true);
                        else if (result->GetParent())
                            root->AttachChildInAvailableSlot(static_cast<NiAVObject*>(result), true);
                    }
                }
                ExtraDismemberedLimbs* limbs = ((RefrLoadAccess*)m_pActor)->FUN_005d43c0()->FUN_0042e8c0();
                if (limbs)
                {
                    for (int limb = 0; limb < 15; limb++)
                        if (limbs->IsBitSet(limb))
                            AddNodeEntries(limb, result);
                }
                if (slot == 7 && object[5].pParent && ((FUN_004ab730_shell*)object[5].pParent)->IsFlagSet() && result)
                    result->FUN_00450f90(true);
                object[slot].m_pSceneObject = result;
            }
        }
    }
    ((CloneLoadAccess*)m_pActor->Get3DSimple())->FUN_00a5a040();
}
