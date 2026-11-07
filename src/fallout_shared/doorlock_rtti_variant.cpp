// Actor ownership check for door access data.
#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#include "../../include/Actor.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESFaction.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESForm.h"
#include "../../include/TESGlobal.h"
#include "../../include/DoorAccessData.h"

class TESObjectCELL;
class LockExtraData;
class PathingActorData;

// Local fallback: shared DoorAccessData.h lacks the Actor* ownership overload at 0x005021c0 (also bound by doorlock.cpp).

FNV_STATIC_ASSERT(sizeof(DoorAccessData) == 24);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pSourceCell) == 0);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pDestinationCell) == 4);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pTeleportData) == 8);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pKeyForm) == 12);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_iLockLevel) == 16);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pLockLevelGlobal) == 20);

extern Actor* g_thePlayer;

// @fnv 0x005021c0
// src: XBOX_PDB 0x005021c0
bool DoorAccessData::DoorLock_IsAnOwner(Actor* ref, bool b)
{
    bool r7 = false;
    if (m_pKeyForm && ref)
    {
        r7 = true;
        TESForm* obj5 = reinterpret_cast<TESForm*>(ref->GetActorUnk0148());
        if (!obj5)
            obj5 = ref->TESObjectREFR::BGSSaveFormBuffer_GetForm();
        TESActorBase* base = 0;
        switch (obj5->GetFormType())
        {
        case 0x2a:
        case 0x2b:
            base = dynamic_cast<TESActorBase*>((TESBoundObject*)obj5);
            break;
        }
        if (m_pKeyForm != obj5)
        {
            TESFaction* fac = 0;
            if (m_pKeyForm && m_pKeyForm->GetFormType() == 8)
                fac = (TESFaction*)m_pKeyForm;
            int rank5 = 0;
            if (!fac || !b)
            {
                if (!m_pLockLevelGlobal || m_pLockLevelGlobal->GetValue() == 0.0)
                    r7 = false;
            }
            if (fac && base)
            {
                rank5 = base->GetFactionRank(fac, ref == g_thePlayer);
                if (rank5 < m_iLockLevel)
                    r7 = false;
            }
        }
    }
    return r7;
}
