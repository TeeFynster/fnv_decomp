#pragma once

#include "PathingLocation.h"

class Actor;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class IDebugText;
class NiNode;
class TESObjectCELL;
class TESObjectREFR;
template <class T> class NiPointer;

// Bethesda PathingGraphNode: one node of a PathingSolution, 0x3C bytes: flags, the PathingLocation (0x28, with its
// own vtable) at +4, the spline tangent at +0x2C and the teleport door at +0x38. No vtable of its own.
// The FUN_ names are the units' names for accessors whose real name is not certain (the comment says what they do).
class PathingGraphNode
{
  public:
    unsigned int iFlags;       // +0x00 bits 0..1 = 3 teleport door node, bit 2 transition node
    PathingLocation Location;  // +0x04
    NiPoint3 Tangent;          // +0x2C
    TESObjectREFR* m_pDoorRef; // +0x38

    PathingGraphNode* Copy();
    const PathingLocation& GetLocation();
    const NiPoint3& GetTangent();
    void CreateDrawNode(NiPointer<NiNode>& node);
    TESObjectCELL* GetContainingCell();
    void SetTangent(const NiPoint3& tangent);
    bool IsTeleportDoorNode();
    void SetTeleportDoor(TESObjectREFR* door);
    void SetTransitionFlag(bool transition);
    bool IsTransitionNode();                         // 0x006ca0c0
    bool IsValidForActor(Actor* actor);
    TESObjectREFR* GetTeleportDoor();
    void WriteDebugString(IDebugText* text);
    void SaveGame(BGSSaveFormBuffer* buffer);
    void LoadGame(BGSLoadFormBuffer* buffer);

    const NiPoint3& FUN_005d8a70();                  // 0x005d8a70 folded: returns this+0x2C (Tangent)
    void FORenderedMenu_SetScreenLightColor(const NiPoint3& tangent);      // 0x006b0570 folded NiPoint3 store at +0x2C (SetTangent)
    void SetDirection(const NiPoint3& tangent);      // 0x006b0570
    bool PathingNode_IsTeleportDoorNode();                             // 0x006e2330 (iFlags & 3) == 3
    bool PathingNode_IsTeleportDoorNode() const;
    PathingLocation& FUN_00717e50();                 // 0x00717e50 folded: returns this+4 (Location)
    const PathingLocation& FUN_00717e50() const;
    PathingLocation* GetLocationPointer();           // 0x00717e50
    TESObjectREFR* GetField38() const;               // m_pDoorRef
};
