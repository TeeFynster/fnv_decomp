#pragma once

#include "NiRefObject.h"
#include "NiPoint3.h"
#include "NiAVObject.h"
#include "AnimIdle.h"

class ReferenceObstacleArray;
class ObstacleSource;
class bhkRigidBody;
class NavMeshInfo;

class ObstacleData : public NiRefObject
{
  public:
    struct RigidBodyPointer
    {
        bhkRigidBody* m_pObject;

        bhkRigidBody* Get() const;
        bhkRigidBody* operator->() const;
        operator bhkRigidBody*() const;
    };

    struct NavMeshInfoArray
    {
        void* unk00;
        NavMeshInfo** data;
        unsigned int cap;
        unsigned int count;

        unsigned int GetSize();
        unsigned int GetFlags();
        NavMeshInfo*& GetAt(unsigned int index);
        void Clear(bool freeBuffer);
        unsigned int Add(NavMeshInfo*& item);
    };

    ObstacleData();
    virtual ~ObstacleData();

    void IncRefCount();
    void DecRefCount();

    union
    {
        ReferenceObstacleArray* m_pReferenceObstacleArray;
        ObstacleSource* source;
        unsigned int unk08;
    };
    union
    {
        RigidBodyPointer m_pRigidBody;
        RigidBodyPointer reference;
    };
    NiPoint3 kTranslate;
    char acRotate[0x24];
    NiPoint3 kMinBoundsCur;
    NiPoint3 kMaxPoint;
    char pad58[0x18];
    union
    {
        unsigned int lastUpdate;
        unsigned int generation;
    };
    bool bFlag74;
    char unk75[3];
    union
    {
        NavMeshInfoArray kNavMeshInfos;
        NavMeshInfoArray meshes;
    };
    NiPointer<AnimIdle> m_kGeometry;

    RigidBodyPointer& GetReference()
    {
        return m_pRigidBody;
    }
    NavMeshInfoArray& GetMeshes()
    {
        return kNavMeshInfos;
    }
};
