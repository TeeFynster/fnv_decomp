#pragma once

#include "ActorPathHandler.h"
#include "NiPoint3.h"
#include "MagicTarget.h"

class TESTopicInfo;
class TESObjectREFR;
class NiNode;

class DetailedActorPathHandler : public ActorPathHandler
{
public:
    DetailedActorPathHandler(int a1, int a2);
    DetailedActorPathHandler(void* apActor, void* apMover, NiPointer<PathingSolution>* apPathPtr, void* apRequest);
    ~DetailedActorPathHandler();

    unsigned char pad14[0x08];
    NiPoint3 m_kPathVector1;
    NiPoint3 m_kPathVector2;
    NiPoint3 m_kPathVector3;
    NiPoint3 m_kActorPosition;
    NiPoint3 m_kPathVector4;
    BSSimpleList<TESTopicInfo*> ActorAvoidEntryList;
    unsigned int ByteAndFlagState;
    unsigned int m_uiPathPointIndex;
    float m_fPathValue1;
    float m_fPathValue2;
    float m_fSplineParameter;
    float m_fPathValue4;
    float m_fPathValue5;
    int m_iPathValue1;
    float m_fPathValue6;
    float m_fPathValue7;
    float m_fPathValue8;
    float m_fPathValue9;
    float m_fPathValue10;
    float m_fPathValue11;
    float m_fPathValue12;
    float m_fPathValue13;
    NiPoint3 m_kPathVector5;
    float m_fPathValue14;
    float m_fPathValue15;
    float m_fPathValue16;
    float m_fPathValue17;
    float m_fPathValue18;
    bool m_bHasPathingSolution;
    bool m_bPathingRequestPending;
    unsigned char padC2[0x02];
    float m_fElapsedTime;
    int eState;
    int m_iPathParameter1;
    int m_iPathParameter2;
    int m_iPathValue2;
    void* m_pPathTargetReference;
    bool m_bPathFlag1;
    bool m_bPathFlag2;
    bool m_bPathFlag3;
    bool m_bPathFlag4;
    bool m_bPathFlag5;
    bool m_bPathFlag6;
    bool m_bPathFlag7;
    unsigned char padE3[1];

    virtual bool GetPathingDelta(NiPoint3* outDelta);
    bool TurnToAngle(float angle, bool keepActorHeading);
    bool StartTurningToAngle(float angle, bool keepActorHeading, bool ignoreInitialRotation);
    void SetInitialPathState();
    void TransitionFrom(ActorPathHandler* previous);
    static void UpdateSceneNode(NiNode*);
    void HandleReferenceUpdate(TESObjectREFR*, bool, bool);
};
