// Local declarations used by teleportdoorsearch.cpp.

#pragma once

#include "../../../include/ActorMover.h"
#include "../../../include/DoorAccessData.h"
#include "../../../include/ExtraLock.h"
#include "../../../include/ExtraRadioData.h"
#include "../../../include/NiFormArray.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESObjectDOOR.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESWorldSpace.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/TeleportDoorSearch.h"
#include "../../../include/QuestDialogueInfo.h"

class TopicInfoArray;
class TESBoundObject;
class SandboxProcedureData;
class TESIdleForm;
class PathingActorData;
class ParentSpaceNode;
class TeleportLink;

struct PointerPairData
{
    void* a;
    void* b;
};


template <class N, class L> class AStarNode
{
  public:
    float cost, fitness;
    bool exterior;
    TESWorldSpace* world;
    TESObjectCELL* cell;
    TESObjectREFR* door;
    NiPoint3 pos;
};
