#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkBool.h"
#include "hkpShape.h"
#include "hkMonitorStream.h"

class hkpCollisionDispatcher;
class hkpCollisionAgent;
class hkpCdBody;
class hkpContactMgr;
class hkpContactMgrFactory;
class hkpCdBodyPairCollector;
class hkpCdPointCollector;
class hkpConstraintOwner;
class hkStatisticsCollector;
class hkVector4;
class hkpAgentData;
class FourByteState;
class AgentProcessingInput;
class AgentSubtypeMarker;
class WorldOperationEntry;
class CollisionAgentContext;
class ShapeSweepParameters;
class CollisionAgentEntry;
class IntegerPair;
struct SpawnRequest;
struct SrcRec;
struct Src;

typedef int hkBool32;
typedef unsigned char hkUchar;
typedef char hkChar;
typedef unsigned short hkContactPointId;
typedef float hkTime;

namespace hkAgent3
{
    typedef int AgentType;
    enum Symmetric
    {
        IS_SYMMETRIC,
        IS_NOT_SYMMETRIC,
        IS_NOT_SYMMETRIC_AND_FLIPPED
    };

    typedef hkpAgentData* (__cdecl* CreateFunc)(const AgentProcessingInput& input, FourByteState* entry,
                                               hkpAgentData* agentData);
    typedef void (__cdecl* DestroyFunc)(FourByteState* entry, hkpAgentData* agentData, hkpContactMgr* mgr,
                                        hkpConstraintOwner& constraintOwner, hkpCollisionDispatcher* dispatcher);
    typedef hkpAgentData* (__cdecl* ProcessFunc)(const AgentSubtypeMarker& input, FourByteState* entry,
                                                hkpAgentData* agentData, hkVector4* separatingNormalOut,
                                                WorldOperationEntry& result);
    typedef void (__cdecl* SepNormalFunc)(const AgentProcessingInput& input, FourByteState* entry,
                                          hkpAgentData* agentData, hkVector4& separatingNormalOut);
    typedef hkpAgentData* (__cdecl* CleanupFunc)(FourByteState* entry, hkpAgentData* agentData, hkpContactMgr* mgr,
                                                hkpConstraintOwner& constraintOwner);
    typedef void (__cdecl* RemovePointFunc)(FourByteState* entry, hkpAgentData* agentData,
                                            hkContactPointId idToRemove);
    typedef void (__cdecl* CommitPotentialFunc)(FourByteState* entry, hkpAgentData* agentData,
                                                hkContactPointId iContactPointId);
    typedef void (__cdecl* CreateZombieFunc)(FourByteState* entry, hkpAgentData* agentData,
                                             hkContactPointId idTobecomeZombie);
    typedef void (__cdecl* UpdateFilterFunc)(FourByteState* entry, hkpAgentData* agentData, const hkpCdBody& bodyA,
                                             const hkpCdBody& bodyB, const CollisionAgentContext& input,
                                             hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner);
    typedef void (__cdecl* CalcStatisticsFunc)(FourByteState* entry, hkpAgentData* agentData,
                                               const CollisionAgentContext& input, hkStatisticsCollector* collector);
    typedef void (__cdecl* InvalidateTimFunc)(FourByteState* entry, hkpAgentData* agentData,
                                              const CollisionAgentContext& input);
    typedef void (__cdecl* WarpTimeFunc)(FourByteState* entry, hkpAgentData* agentData, hkTime oldTime,
                                         hkTime newTime, const CollisionAgentContext& input);
}

#include "hkpCollisionQualityInfo.h"

class hkpCollisionDispatcher : public hkReferencedObject
{
public:
    enum
    {
        HK_MAX_RESPONSE_TYPE = 8,
        HK_MAX_SHAPE_TYPE = 32,
        HK_MAX_AGENT2_TYPES = 64,
        HK_MAX_AGENT3_TYPES = 16,
        HK_MAX_COLLISION_QUALITIES = 8
    };

    static void* __cdecl operator new(std::size_t nbytes);

    typedef hkpCollisionAgent* (__cdecl* CreateFunc)(const hkpCdBody& collA, const hkpCdBody& collB,
                                                     const CollisionAgentContext& env, hkpContactMgr* mgr);
    typedef void (__cdecl* GetPenetrationsFunc)(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                const CollisionAgentContext& input,
                                                hkpCdBodyPairCollector& collector);
    typedef void (__cdecl* GetClosestPointsFunc)(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                 const CollisionAgentContext& input, hkpCdPointCollector& output);
    typedef void (__cdecl* LinearCastFunc)(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                           const ShapeSweepParameters& input, hkpCdPointCollector& castCollector,
                                           hkpCdPointCollector* startCollector);
    typedef hkChar CollisionQualityIndex;

    struct CollisionAgentFunctionTable
    {
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);
        class CommandArgument;
        CreateFunc m_pCreateFunc;
        GetPenetrationsFunc m_pQueryPenetrationsFunc;
        GetClosestPointsFunc m_pGetPenetrationsFunc;
        LinearCastFunc m_pLinearCastFunc;
        hkBool m_bIsFlipped;
        hkBool m_bIsPredictive;

        CollisionAgentFunctionTable();
    };

    struct Agent3FunctionTable
    {
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);
        class CommandArgument;
        Agent3FunctionTable();

        __declspec(align(16)) hkAgent3::CreateFunc m_pCreateFunc;
        hkAgent3::DestroyFunc m_pAgent3DestroyFuncs;
        hkAgent3::CleanupFunc m_pAgentFunction3;
        hkAgent3::RemovePointFunc m_pAgentFunction4;
        hkAgent3::CommitPotentialFunc m_pAgentFunction5;
        hkAgent3::CreateZombieFunc m_pCreateZombieFunc;
        hkAgent3::UpdateFilterFunc m_pUpdateFilterFunc;
        hkAgent3::CalcStatisticsFunc m_pCalcStats;
        hkAgent3::InvalidateTimFunc m_pAgentFunction10;
        hkAgent3::WarpTimeFunc m_pAgentFunction11;
        hkAgent3::SepNormalFunc m_pAgentFunction7;
        hkAgent3::ProcessFunc m_pAgentFunction8;
        hkBool m_bIsPredictive;
        hkBool m_bAgentFlag1;
        hkBool m_bAgentFlag2;
    };

    struct IntegerPair
    {
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);
        class CommandArgument;
        hkpShapeType m_iSecond;
        hkpShapeType m_iFirst;
    };

    struct SymmetricAgent3FunctionTable : public Agent3FunctionTable
    {
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);
        class CommandArgument;
        hkAgent3::Symmetric m_eSymmetric;
    };

    struct AgentTypePairPriority
    {
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);
        class CommandArgument;
        char m_iAgentTypeA;
        char m_iAgentTypeB;
        char m_priority;
    };

    typedef AgentTypePairPriority DebugTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];

    enum CollisionQualityLevel
    {
        COLLISION_QUALITY_INVALID,
        COLLISION_QUALITY_PSI,
        COLLISION_QUALITY_SIMPLIFIED_TOI,
        COLLISION_QUALITY_TOI,
        COLLISION_QUALITY_TOI_HIGHER,
        COLLISION_QUALITY_TOI_FORCED,
        COLLISION_QUALITY_CHARACTER,
        COLLISION_QUALITY_TMP_EXPAND_MANIFOLD
    };

    hkpCollisionDispatcher(CreateFunc defaultCreationFunction, hkpContactMgrFactory* defaultContactMgrFactory);
    virtual ~hkpCollisionDispatcher() throw();
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;

    hkAgent3::AgentType getAgent3Type(hkpShapeType typeA, hkpShapeType typeB, hkBool32 predicitve) const;
    hkAgent3::CreateFunc getAgent3CreateFunc(hkAgent3::AgentType type);
    hkAgent3::DestroyFunc getAgent3DestroyFunc(hkAgent3::AgentType type);
    hkAgent3::CleanupFunc getAgent3CleanupFunc(hkAgent3::AgentType type);
    hkAgent3::ProcessFunc getAgent3ProcessFunc(hkAgent3::AgentType type);
    hkAgent3::SepNormalFunc getAgent3SepNormalFunc(hkAgent3::AgentType type);
    hkAgent3::Symmetric getAgent3Symmetric(hkAgent3::AgentType type);
    hkBool32 hasAlternateType(hkpShapeType type, hkpShapeType alternateType);
    hkAgent3::RemovePointFunc getAgent3RemovePointFunc(hkAgent3::AgentType type);
    hkAgent3::CommitPotentialFunc getAgent3CommitPotentialFunc(hkAgent3::AgentType type);
    hkAgent3::CreateZombieFunc getAgent3CreateZombieFunc(hkAgent3::AgentType type);
    hkpCollisionQualityInfo* getCollisionQualityInfo(CollisionQualityIndex index);
    LinearCastFunc getLinearCastFunc(hkpShapeType typeA, hkpShapeType typeB) const;
    void internalRegisterCollisionAgent(hkUchar agentTypesTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE], int agentType,
                                        hkpShapeType typeA, hkpShapeType typeB, hkpShapeType origA,
                                        hkpShapeType origB, DebugTable* debugTable, int recursionDepth);
    void RegisterAgentType(signed char (*table)[32], signed char agentType, int typeA, int typeB,
                           signed char origA, signed char origB, CollisionAgentEntry (*entries)[32], int depth);
    void registerAlternateShapeType(int primaryType, int alternateType);
    void debugPrintTable();
    void updateShapeInheritance(int primaryType, int alternateType, bool recurse);

    void Set(bool b);
    void FreeBuffers();
    void SetSlotPair(hkReferencedObject* factory, int responseA, int responseB);
    void SetContactMgrFactory(hkpContactMgrFactory* factory, int responseA);
    void MergeBitsRecursive(unsigned int dstIndex, unsigned int srcIndex, int depth);
    void RegisterAgentType(void* table, int agentType, int typeA, int typeB, int origA, int origB,
                           int entries, int depth);
    void RegisterAgentType(char* table, int agentType, int typeA, int typeB, int origA, int origB,
                           int entries, int depth);
    void AppendRecordAndRegisterAgents(CollisionAgentFunctionTable* record, int typeA, int typeB);
    void AddSpawnEntry(SpawnRequest* request, int typeA, int typeB);
    void AddSpawnEntry(CollisionAgentFunctionTable* record, int typeA, int typeB);
    int AddEntry(SrcRec* record, int typeA, int typeB);
    int AddEntry(Agent3FunctionTable* record, int typeA, int typeB);
    void Destroy();
    hkpCollisionDispatcher* hkpCollisionDispatcher_hkpCollisionDispatcher(unsigned int creationFunction, unsigned int factory);
    void Reset_cfb080();
    void hkpCollisionDispatcher_resetCreationFunctions();
    void hkpCollisionDispatcher_initCollisionQualityInfo(Src* source);

    hkpContactMgrFactory* m_apContactMgrFactoriesByResponsePair[HK_MAX_RESPONSE_TYPE][HK_MAX_RESPONSE_TYPE];
    __declspec(align(16)) hkUint32 m_auiAlternateTypeFlags[HK_MAX_SHAPE_TYPE];
    int m_iEntryCount;
    __declspec(align(16)) hkUchar m_agent2TypeMap[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    hkUchar m_agent3TypeMap[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    CollisionAgentFunctionTable m_agent2Funcs[HK_MAX_AGENT2_TYPES];
    int m_iAgent2FunctionCount;
    __declspec(align(16)) hkUchar m_ucAgent2TypeTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    __declspec(align(16)) hkUchar m_ucAgent3TypeTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    SymmetricAgent3FunctionTable m_kAgent3FunctionTable[HK_MAX_AGENT3_TYPES];
    __declspec(align(16)) hkChar m_aucByteGrid[10][10];
    __declspec(align(16)) hkpCollisionQualityInfo m_pCollisionQualityInfo[HK_MAX_COLLISION_QUALITIES];
    union
    {
        hkReal m_fExpectedMaxLinearVelocity;
        struct
        {
            hkBool m_bEnableDeprecatedFeature;
            union
            {
                char unk1e21;
                char m_cUnknownByte;
            };
            char unk1e22;
            hkBool m_debugWarnings;
        };
    };
    ::IntegerPair* m_pShapeInheritance;
    int m_numShapeInheritance;
    int m_shapeInheritanceCapacity;
    CollisionAgentEntry* m_tableDiscrete;
    CollisionAgentEntry* m_tableContinuous;
    CollisionAgentEntry* m_tableDiscrete3;
    CollisionAgentEntry* m_tableContinuous3;
};
