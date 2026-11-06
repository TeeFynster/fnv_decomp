#pragma once

#include "NiRefObject.h"
#include "NiAVObject.h"
#include "PathingLocation.h"
#include "PathingActorData.h"
#include "NiPoint3.h"

class Actor;
class Arg1Class;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class EvadeActor;
class MoveActor454;
class PathingAvoidNodeArray;
class PathingDebugOutput;
class PathingRequestOwner;
class NiMatrix3;
template <class T, unsigned int N> class BSSimpleArray;
enum PATHING_REQUEST_TYPE;

class PathingRequest : public NiRefObject
{
public:
    PathingRequest();
    PathingRequest(PathingRequest*);
    PathingRequest(PathingRequestOwner*);
    virtual ~PathingRequest();
    virtual void DeleteThis();
    virtual void CopyTo(PathingRequest*);
    virtual void vfn_c();
    virtual PATHING_REQUEST_TYPE GetType();
    virtual void PrintDebugInfo(PathingDebugOutput*);
    virtual void SaveGame(BGSSaveFormBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);
    virtual void InitLoadGame(BGSLoadFormBuffer*);

    static PathingRequest* CreateRequestForType(PATHING_REQUEST_TYPE);

    void SetUseSoft(bool);
    void SetTargetAngle(float);
    void InitFromActor(Actor*);
    void InitFromActor(EvadeActor*);
    void InitFromActor(MoveActor454*);
    void SetInitialPathHeading(float);
    void SetCantOpenDoors(bool);
    void SetCanSwim(bool);
    void SetOrigin(PathingLocation*);
    void SetDestination(PathingLocation*);
    void SetByteAtOffset9B(bool);
    void SetByteAtOffset9B(int);
    void SetByteAtA1(int);
    void SetSmoothingRandomness(float);
    void SetCurvedPath(int);
    void SetCenterRadius(float);
    void SetActorRadius(float);
    void SetAvoidNodeArray(BSSimpleArray<void*, 1024>*);
    void SetGoalZDelta(float);
    void DestroyPathingRequest();
    void IncRefCount();
    void DecRefCount();

    PathingLocation& GetOffsetC();
    PathingLocation* GetOrigin();
    PathingLocation* GetStartLoc();
    float GetSmoothingRandomness();
    float GetFloatAtOffset68();
    float GetFloatAtOffset68() const;
    float GetFieldB4Float();
    float GetFloatAtOffsetB0();
    float GetFloatAtOffsetB0() const;
    float GetCenterRadius();
    float GetMinRadius();
    float GetMaxRadius();
    float GetTargetRadius();
    float GetActorRadius();
    float GetGoalZDelta();
    bool IsRandomBelowRadiusThreshold();
    bool GetByteAtOffset9E() const;
    bool GetByteAtOffsetA1();
    bool GetByteAtOffset9B();
    int FUN_008cdd90();  // 0x008cdd90 (folded getter): the int at +0xa8, PathBuilder's pass limit
    bool FUN_006cd1d0(); // 0x006cd1d0: the byte at +0xa3
    const NiMatrix3& GetRotate();
    PathingAvoidNodeArray* GetString() const;
    BSSimpleArray<void*, 1024>* GetString();
    PathingAvoidNodeArray* GetAvoidNodes() const;

    void FUN_00507610(float);
    bool FUN_00505c00();
    float FUN_00507e10();
    int FUN_006377e0();
    float FUN_006a78f0() const;
    NiPoint3 FUN_006a7910();
    NiPoint3 FUN_006a7910() const;
    bool FUN_006a7940() const;
    bool FUN_006a7980() const;
    bool FUN_006a79a0() const;
    PathingLocation* FUN_006a9540();
    PathingActorData* FUN_006c9900();
    const PathingActorData* FUN_006c9900() const;
    void FUN_006d1bc0(PathingLocation*);
    void FUN_006d30e0(int);
    void FUN_006d3100(Arg1Class*);
    void FUN_006d3120();
    void FUN_006d3ae0(float);
    void FUN_006d61e0(int);
    void FUN_006d61e0(void*);
    void FUN_006e2980(NiPoint3&, float);
    void FUN_006e2980(NiPoint3*, float);
    void FUN_006e29b0(PathingActorData*);
    void FUN_006e2b20(void*);
    void FUN_006e3230(BGSSaveFormBuffer*);
    void FUN_006e4320(float);
    void FUN_006e4bf0();
    void FUN_006e4ef0(float);
    void FUN_006e5ee0(float);
    void FUN_00705b10(int);
    bool FUN_0073cb80() const;
    void FUN_008df000();
    float FUN_009b0bd0() const;
    void FUN_009db930(unsigned int);

    Actor* pActor;
    PathingLocation Origin;
    PathingLocation Destination;
    union
    {
        struct
        {
            PathingActorData PathingActorState;
        };
    };
    float m_fFirstValueAfterActorData;
    float m_fSecondValueAfterActorData;
    float PathingActorSpatialData;
    float fWeaponSpread;
    float m_fCenterRadius;
    NiPoint3 Center;
    float m_fFloatAfterCenter;
    float m_fPathingRadius;
    float m_fAvoidanceRadius;
    NiPointer<PathingAvoidNodeArray> m_pPathingAvoidNodeArray;
    bool bCantOpenDoors;
    bool bFaceTargetAtGoal;
    bool PathingOptions;
    bool bAllowIncompletePath;
    bool m_bAllowDoorTraversal;
    bool bCanSwim;
    bool bCanFly;
    bool m_bCanWalk;
    bool m_bCanJump;
    bool m_bCanClimb;
    bool m_bCanUseDoors;
    bool m_bCanRun;
    bool bIgnoreLocks;
    struct
    {
        unsigned char byte0;
        unsigned char byte1;
        unsigned char byte2;
    } layoutPaddingA5;
    int m_iRequestType;
    bool m_bCanOpenDoors;
    struct
    {
        unsigned char byte0;
        unsigned char byte1;
        unsigned char byte2;
    } layoutPaddingAD;
};
