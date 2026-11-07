
// src/fallout_shared/havok/bgsacousticspacelistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/bgsacousticspacelistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/PlayerCharacter.h"
#include "../../../include/BGSAcousticSpaceListener.h"
#include "../../../include/RootContactPoint.h"

void __cdecl _Deallocate(void* ptr);

// Calls FUN_0061f5d0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0061f5a0
void* __thiscall BGSAcousticSpaceListener::Destroy(unsigned int flags)
{
    FUN_0061f5d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Flt
{
    operator unsigned int() const;
};

// @fnv 0x0061f6c0
// src: XBOX_PDB 0x0061f6c0
unsigned int PlayerCharacter::QCameraRigidBody()
{
    return *reinterpret_cast<const Flt*>(reinterpret_cast<const char*>(this) + 0xDEC);
}

struct BGSAcousticSpace;
struct SoundPlaybackManager
{
    static void __cdecl ResetAcousticSpace(BGSAcousticSpace*);
};
// @fnv 0x0061f8e0
// src: COMMUNITY 0x0061f8e0
void BGSAcousticSpaceListener::DequeueAllRemovals(bool abDoRemoval)
{
    void* pos2 = m_map.GetFirstPos();
    while (pos2)
    {
        TESObjectREFR* key;
        int value2;
        m_map.GetNext(pos2, key, value2);
        SoundPlaybackManager::ResetAcousticSpace(key->GetAcousticSpace());
    }
    m_map.RemoveAll();
}

extern PlayerCharacter* _g_thePlayer;
struct W_0043b4f0
{
    unsigned int GetSourceFilesFromObject();
};
TESObjectREFR* __cdecl TESHavokUtilities_FindCollidableRef(void*);
// @fnv 0x0061f7b0
bool BGSAcousticSpaceListener::CheckAcousticSpaceListener(RootContactPoint* pPoint)
{
    TESObjectREFR* apTestRef = 0;
    if (_g_thePlayer->PlayerCharacter_Is3rdPerson())
    {
        if (pPoint->m_pRootCollidableB ==
            reinterpret_cast<void*>(reinterpret_cast<W_0043b4f0*>(_g_thePlayer->QCameraRigidBody())
                ->GetSourceFilesFromObject()))
            apTestRef = TESHavokUtilities_FindCollidableRef((void*)pPoint->m_pRootCollidableA);
    }
    else
    {
        TESObjectREFR* pAcousticSpaceLeft = TESHavokUtilities_FindCollidableRef((void*)pPoint->m_pRootCollidableB);
        if (pAcousticSpaceLeft == reinterpret_cast<TESObjectREFR*>(_g_thePlayer))
            apTestRef = TESHavokUtilities_FindCollidableRef((void*)pPoint->m_pRootCollidableA);
    }
    if (apTestRef)
    {
        if (m_ucState)
            SetCopyMapEntry(apTestRef);
        else
            SoundPlaybackManager::ResetAcousticSpace(apTestRef->GetAcousticSpace());
    }
    return false;
}

// @fnv 0x0061f940
void BGSAcousticSpaceListener::UpdateAcousticSpaceRefCounts(float afTime)
{
    void* iter = m_map.GetFirstPos();
    while (iter)
    {
        int icount;
        TESObjectREFR* key;
        m_map.GetNext(iter, key, icount);
        m_map.SetAt(key, --icount);
    }
    bool bloop = true;
    while (bloop)
    {
        bloop = false;
        void* iter2 = m_map.GetFirstPos();
        while (iter2)
        {
            int icount;
            TESObjectREFR* key;
            m_map.GetNext(iter2, key, icount);
            if (icount == 0)
            {
                m_map.RemoveAt(key);
                SoundPlaybackManager::ResetAcousticSpace(key->GetAcousticSpace());
                bloop = true;
                break;
            }
        }
    }
}

struct TgtOps
{
    void* GetSourceFiles();
};
// @fnv 0x0061f630
void BGSAcousticSpaceListener::CheckPlayerReference(TESObjectREFR* apEntity)
{
    if (!_g_thePlayer)
        return;
    if (_g_thePlayer->PlayerCharacter_Is3rdPerson())
    {
        if (((TgtOps*)apEntity)->GetSourceFiles() ==
            (void*)((W_0043b4f0*)(_g_thePlayer->QCameraRigidBody()))->GetSourceFilesFromObject())
            SoundPlaybackManager::ResetAcousticSpace(0);
    }
    else
    {
        TESObjectREFR* apTestRef = TESHavokUtilities_FindCollidableRef(((TgtOps*)apEntity)->GetSourceFiles());
        if (apTestRef == (TESObjectREFR*)_g_thePlayer)
            SoundPlaybackManager::ResetAcousticSpace(0);
    }
}

struct FUN_0082eae0_shell
{
    static void __cdecl SetAcousticSpace(BGSAcousticSpace*);
};

struct FNV_GetObjectReference_shell
{
    BGSAcousticSpace* __thiscall _FNV_GetObjectReference();
};

// @fnv 0x0061f6e0
bool __thiscall BGSAcousticSpaceListener::CheckAcousticSpaceEntered(RootContactPoint* pPoint)
{
    TESObjectREFR* pAcousticSpaceRef = 0;

    if (_g_thePlayer->PlayerCharacter_Is3rdPerson())
    {
        if (pPoint->m_pRootCollidableB == reinterpret_cast<void*>(reinterpret_cast<W_0043b4f0*>(_g_thePlayer->QCameraRigidBody())->GetSourceFilesFromObject()))
        {
            pAcousticSpaceRef = TESHavokUtilities_FindCollidableRef((void*)pPoint->m_pRootCollidableA);
        }
    }
    else
    {
        TESObjectREFR* apTestRef = TESHavokUtilities_FindCollidableRef((void*)pPoint->m_pRootCollidableB);
        if (apTestRef == reinterpret_cast<TESObjectREFR*>(_g_thePlayer))
        {
            pAcousticSpaceRef = TESHavokUtilities_FindCollidableRef((void*)pPoint->m_pRootCollidableA);
        }
    }

    if (pAcousticSpaceRef)
    {
        if (!m_ucState || !BGSAcousticSpaceListener_DequeueRemoval(pAcousticSpaceRef, false))
        {
            FUN_0082eae0_shell::SetAcousticSpace(
                reinterpret_cast<FNV_GetObjectReference_shell*>(pAcousticSpaceRef)->_FNV_GetObjectReference());
        }
        return true;
    }

    return false;
}

// Destructor of the class; the body is empty, so the compiler-generated member destructors run.
// @fnv 0x0061f5d0
BGSAcousticSpaceListener::~BGSAcousticSpaceListener()
{}

struct S_00620260_A
{
    virtual void vfn_00();
};
struct S_00620260_B
{
    void FUN_006ecd40(S_00620260_B* other);
};
struct S_00620260_T : S_00620260_A, S_00620260_B
{
    S_00620260_T* FindDerivedByKey(int b);
};
struct S_00620260_C
{
    virtual void vfn_00();
    virtual S_00620260_T* vfn_04(int a, int b);
    S_00620260_T* cur;
    S_00620260_T* BGSZoneTargetListener_AddZone(int a, int b);
};
// @fnv 0x00620260
// src: COMMUNITY 0x00620260
S_00620260_T* S_00620260_C::BGSZoneTargetListener_AddZone(int a, int b)
{
    S_00620260_T* r = cur ? cur->FindDerivedByKey(b) : 0;
    if (!r)
    {
        r = vfn_04(a, b);
        r->FUN_006ecd40(cur);
        cur = r;
    }
    return r;
}
