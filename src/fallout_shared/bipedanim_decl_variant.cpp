
// src/fallout_shared/bipedanim_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x004abd30: the skeleton of src/fallout_shared/bipedanim.cpp
// with declarations corrected to what the original code does (bipedanim_decls.h: BipedAnim += void FUN_004abd30(IO_TASK_PRIORITY priority, NiPointer<QueuedHelmet>& queuedHelmet, QueuedFile* file);). Move the function to its real unit once
// that unit declares it this way.

#include "bipedanim_decls_decl_bipedanim.h"

// @fnv 0x004abd30
// src: XBOX_PDB 0x004abd30
void BipedAnim::QueueBipedParts(IO_TASK_PRIORITY priority, NiPointer<QueuedHelmet>& queuedHelmet, QueuedFile* file)
{
    unsigned int modelFlags;
    TESNPC* npc;
    int i;
    NiPointer<QueuedHelmet> pHelmetQueueEntry(0);
    modelFlags = 0;
    npc = dynamic_cast<TESNPC*>(m_pActor->GetObjectReference());
    if (npc)
    {
        for (i = 0; i < 20; i++)
        {
            if (object[i].m_pModel && object[i].m_pModel != (TESModel*)-1)
            {
                modelFlags |= object[i].m_pModel->TESModel_GetSkinFlags();
                if (IsSlotHidden((BIPED_OBJECT)i) && *DAT_011c5ef0.Bool() && BSFaceGenManager_GetUseFaceGenHeads() &&
                    CanLoadHiddenBipedObjects())
                {
                    RequestModelLoad(priority, file, pHelmetQueueEntry, (BIPED_OBJECT)i);
                }
                else
                {
                    if (m_pActor == g_thePlayer)
                    {
                        TESModel* firstPersonModel = GetModelForSlot((BIPED_OBJECT)i, object[i].m_pModel);
                        if (firstPersonModel != object[i].m_pModel)
                            g_modelLoader->ProcessModelRequest(firstPersonModel, priority, file, 3, true, false, false);
                    }
                    g_modelLoader->ProcessModelRequest(object[i].m_pModel, priority, file, 3, true, false, false);
                    TESBipedModelForm* biped = TESBipedModelForm::GetFormAsBipedModel(object[i].pParent);
                    if (biped)
                    {
                        const char* path = reinterpret_cast<const char*>(biped->GetBipedConstraint());
                        if (*path)
                            g_modelLoader->QueueFile(path, priority, file, 3, true, false, false);
                    }
                }
            }
        }
    }
    queuedHelmet = pHelmetQueueEntry;
    QueueBipedObjectLoads(modelFlags, priority, file);
}
