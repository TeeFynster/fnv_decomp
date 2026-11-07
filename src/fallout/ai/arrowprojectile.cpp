#include "../../../include/ProcessLists.h"
// src/fallout/ai/arrowprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/arrowprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/Actor.h"
#include "../../../include/ArrowProjectile.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/BSSimpleList.h"
#include "../../../include/Projectile.h"
#include "../../../include/MobileObject.h"

bool __fastcall FUN_008256d0(BSSimpleList<ArrowProjectile*>* node);
BSSimpleList<ArrowProjectile*>* __fastcall FUN_00726070(BSSimpleList<ArrowProjectile*>* node);
void __fastcall FUN_00470470(BSSimpleList<ArrowProjectile*>* node);

struct ActorList
{
    unsigned int ProcessArray_GetProcessLevelTail(int type);
    unsigned int ProcessArray_GetProcessLevelHead(int type);
    MobileObject* ProcessArray_GetItem(unsigned int i);
};



extern ProcessLists DAT_011e0e80;

// @fnv 0x008cddd0
// src: XBOX_PDB 0x008cddd0
void ArrowProjectile_DeleteAttachedArrows(MobileObject* owner, bool bFlag)
{
    if (owner == 0 || owner->IsProjectile())
        return;

    bool bHigh = true;
    bool bLow = true;
    if (owner->IsActor())
    {
        Actor* pActor = (Actor*)owner;
        BaseProcess* process = pActor->GetCurrentProcess();
        if (process)
        {
            if (process->GetArrowProjectiles())
            {
                BSSimpleList<ArrowProjectile*>* node = process->GetArrowProjectiles();
                while (node && !FUN_008256d0(node))
                {
                    Projectile* projectile = reinterpret_cast<Projectile*>(node->GetItem());
                    if (projectile)
                    {
                        if (projectile->ArrowProjectile_GetAttachedRef() == owner)
                        {
                            projectile->ArrowProjectile_ClearAttachedRef();
                            if (!projectile->FUN_00440d80())
                            {
                                if (bFlag)
                                    projectile->MarkForDeletion(true);
                                else
                                    projectile->EffectSetting_SetAreaSound(3);
                            }
                        }
                        if (projectile->FUN_00440d80())
                            projectile->Set3D(0, true);
                    }
                    node = FUN_00726070(node);
                }
                FUN_00470470(process->GetArrowProjectiles());
            }
            if (process->FUN_0045cd60() == 0)
            {
                bHigh = true;
                bLow = false;
            }
            else if (process->FUN_0045cd60() == 1)
            {
                bHigh = false;
                bLow = true;
            }
        }
    }

    if (bHigh)
    {
        MobileObject* object = 0;
        for (unsigned int i = 0; i < DAT_011e0e80.FUN_00717e50()->ProcessArray_GetProcessLevelTail(0); i++)
        {
            bool bStopped = false;
            object = DAT_011e0e80.FUN_00717e50()->ProcessArray_GetItem(i);
            if (object->IsProjectile())
            {
                ArrowProjectile* arrow = dynamic_cast<ArrowProjectile*>(object);
                if (arrow)
                {
                    if (reinterpret_cast<Projectile*>(arrow)->ArrowProjectile_GetAttachedRef() == owner)
                    {
                        reinterpret_cast<Projectile*>(arrow)->ArrowProjectile_ClearAttachedRef();
                        if (!object->FUN_00440d80())
                        {
                            if (bFlag)
                            {
                                arrow->MarkForDeletion(true);
                                bStopped = true;
                            }
                            else
                            {
                                reinterpret_cast<Projectile*>(arrow)->EffectSetting_SetAreaSound(3);
                            }
                        }
                    }
                    if (arrow->FUN_00440d80())
                        arrow->Set3D(0, true);
                }
            }
        }
    }

    if (bLow)
    {
        MobileObject* object = 0;
        for (unsigned int i = DAT_011e0e80.FUN_00717e50()->ProcessArray_GetProcessLevelHead(1);
             i < DAT_011e0e80.FUN_00717e50()->ProcessArray_GetProcessLevelTail(1); i++)
        {
            bool bStopped = false;
            object = DAT_011e0e80.FUN_00717e50()->ProcessArray_GetItem(i);
            if (object->IsProjectile())
            {
                ArrowProjectile* arrow = dynamic_cast<ArrowProjectile*>(object);
                if (arrow)
                {
                    if (reinterpret_cast<Projectile*>(arrow)->ArrowProjectile_GetAttachedRef() == owner)
                    {
                        reinterpret_cast<Projectile*>(arrow)->ArrowProjectile_ClearAttachedRef();
                        if (!object->FUN_00440d80())
                        {
                            arrow->MarkForDeletion(true);
                            bStopped = true;
                        }
                    }
                    if (arrow->FUN_00440d80())
                        arrow->Set3D(0, true);
                }
            }
        }
    }
}
