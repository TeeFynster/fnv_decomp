// fallout/ai/escortpackage.cpp: EscortActorPackageData (10 functions)

#include "../../../include/EscortActorPackageData.h"
#include "../../../include/UseWeaponActorPackageData.h"
#include "../../../include/Actor.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESPackage.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"

// Initializes the use-weapon package data and clears its reference target.
// @fnv 0x0067d8f0
UseWeaponActorPackageData::UseWeaponActorPackageData()
{
    m_pUseTarget = 0;
}

// Adds apActor to the head of the list at offset 0x10 only if it is not already in that list.
// @fnv 0x009f0a20
void __thiscall EscortActorPackageData::RegisterActor(Actor* apActor)
{
    if (!(m_kActorList.IsInList(apActor)))
        m_kActorList.AddHead(apActor);
}

// If the deleted reference is an Actor, casts it to Actor and forwards it to RemoveActorFromList.
// @fnv 0x009f0b70
void EscortActorPackageData::SetReferenceTarget(TESObjectREFR* apDeletedObj)
{
    Actor* pactor;
    if (!apDeletedObj->IsActor())
        return;
    pactor = reinterpret_cast<Actor*>(apDeletedObj);
    RemoveActorFromList(pactor);
}

// @fnv 0x009f0a60
void EscortActorPackageData::RemoveActorFromList(Actor* actor)
{
    m_kActorList.Remove(actor);
}

struct RefH
{
    bool IsDeleted() const;
};

struct FUN_008bc860_class
{
    bool Actor_CouldBeFollowing(Actor*);
};

struct FUN_0055d3b0_class
{
    bool FUN_0055d3b0(void*);
};

struct ListStandin
{
    void _ref_00905330(Actor* const&);
    bool _ref_008256d0();
};

extern void** __fastcall _ref_006815c0(void*);
extern void* __fastcall _ref_00726070(void*);

// @fnv 0x009f0a80
// src: COMMUNITY 0x009f0a80
int EscortActorPackageData::GetNumEscortedActorsOfType(Actor* apEscorter, void* apType)
{
    void* pNode;
    int iCount;

    pNode = (void*)&m_kActorList;
    while (pNode)
    {
        Actor* pactor = (Actor*)*_ref_006815c0(pNode);
        pNode = _ref_00726070(pNode);
        if (pactor)
        {
            if (((RefH*)pactor)->IsDeleted() || !((FUN_008bc860_class*)pactor)->Actor_CouldBeFollowing(apEscorter))
            {
                ((ListStandin*)&m_kActorList)->_ref_00905330(pactor);
                if (!((ListStandin*)&m_kActorList)->_ref_008256d0())
                {
                    pNode = (void*)&m_kActorList;
                }
            }
        }
    }

    iCount = 0;
    for (pNode = (void*)&m_kActorList; pNode; pNode = _ref_00726070(pNode))
    {
        Actor* pactor = (Actor*)*_ref_006815c0(pNode);
        if (pactor && ((FUN_0055d3b0_class*)pactor)->FUN_0055d3b0(apType))
        {
            iCount++;
        }
    }

    return iCount;
}


extern void** __fastcall _ref_006815c0(void*);
extern void* __fastcall _ref_00726070(void*);

// Writes the form at offset 8, then each non-null form from the list at offset 0x10, and stores the count at the saved buffer position.
// @fnv 0x009f0bb0
void EscortActorPackageData::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SerializeFormData(pPackage, 0);

    unsigned int isaveGameCount = 0;
    unsigned int isaveGameBufferPos = apSaveGameBuffer->StartVariableSizedValue();
    void* pCurrentElementNext = (void*)&m_kActorList;
    while (pCurrentElementNext)
    {
        void* pForm = *_ref_006815c0(pCurrentElementNext);
        if (pForm)
        {
            apSaveGameBuffer->SerializeFormData(pForm, 0);
            isaveGameCount++;
        }
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
    }
    apSaveGameBuffer->SaveVariableSizedValue_00865ff0(isaveGameCount, isaveGameBufferPos);
}



extern TESForm* _ref_004839c0(unsigned int);

// The shared TESPackage header does not yet declare this accessor.
extern const TESEscortPackageData* __fastcall GetEscortPackageData(TESPackage* package);

// Resolves a TESPackage from the buffer's form id, stores its result, then reads a count of Actors and adds each to a list.
// @fnv 0x009f0c40
void EscortActorPackageData::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    pPackage = dynamic_cast<TESPackage*>(_ref_004839c0(apLoadGameBuffer->BGSLoadGameBuffer::ReadFormIdentifier()));
    m_pEscortPackageData = pPackage ? GetEscortPackageData(pPackage) : 0;

    unsigned int isaveGameCount = apLoadGameBuffer->BGSLoadGameBuffer::ReadElementCount();
    for (unsigned int uiIndex = 0; uiIndex < isaveGameCount; uiIndex++)
    {
        Actor* pForm = 0;
        apLoadGameBuffer->BGSLoadGameBuffer::ReadFormIdentifier(&pForm);
        m_kActorList.AddHead(pForm);
    }
}

// Removes all actors before the list and package-data base are destroyed.
// @fnv 0x009f09b0
EscortActorPackageData::~EscortActorPackageData()
{
    m_kActorList.RemoveAll();
}

struct ActorListNode
{
    bool IsEmpty();
    Actor** GetItemPtr();
    void SetItem(Actor* const&);
    void RemoveItem(Actor* const&);
    ActorListNode* GetNext();
    void RemoveHead();
};

// Walks the actor list, re-resolves each entry via _ref_004839c0, removes entries that fail, then stores the buffer's actor.
// @fnv 0x009f0cf0
void EscortActorPackageData::InitLoadGame(BGSLoadFormBuffer* apArg)
{
    ActorListNode* pNode = (ActorListNode*)&m_kActorList;
    ActorListNode* pPrev = 0;
    while (pNode && !pNode->IsEmpty())
    {
        Actor* pActor = *pNode->GetItemPtr();
        bool bRemove = false;
        if (pActor)
        {
            pActor = pActor ? dynamic_cast<Actor*>(_ref_004839c0((unsigned int)pActor)) : 0;
            if (pActor)
                pNode->SetItem(pActor);
            else
                bRemove = true;
        }
        else
        {
            bRemove = true;
        }
        if (bRemove)
        {
            if (pPrev)
            {
                pPrev->RemoveItem(*pNode->GetItemPtr());
                pNode = pPrev->GetNext();
            }
            else
            {
                pNode->RemoveHead();
            }
        }
        else
        {
            pPrev = pNode;
            pNode = pNode->GetNext();
        }
    }
    pActor = apArg->GetActor();
}
