#pragma once

#include "BSSimpleList.h"
#include "NiPoint3.h"

class Actor;
class BGSLoadGameBuffer;
class DetectionViewData;

class ActorCause
{
public:
    Actor* m_00;
    BSSimpleList<DetectionViewData*>* m_04;
    NiPoint3 m_08;
    union
    {
        unsigned int m_14;
        int m_iFadeIndex;
    };
    int m_18;

    ActorCause(Actor* actor);
    ~ActorCause();

    void IncRefCount();
    unsigned int DecRefCount();
    unsigned short GetCount();
    void Update(int arg);
    unsigned short GetRefCount_0047d3d0();
    ActorCause* UpdateState_0066e010(Actor* actor);

    static void ClearActorCauseList(BGSLoadGameBuffer* buffer);
    static void SaveActorCauses(BGSLoadGameBuffer* buffer);
    static void LoadReferencesFromBuffer(BGSLoadGameBuffer* buffer);

    static BSSimpleList<ActorCause*> ms_kActorCauseList;
};
