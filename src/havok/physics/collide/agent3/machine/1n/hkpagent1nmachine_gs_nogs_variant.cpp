#include "../../../../../../../include/hkpAgent3Input.h"
#include "../../../../../../../include/hkContactPointMaterial.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkStepInfo.h"
#include "../../../../../../../include/hkpCollisionInput.h"
#include "../../../../../../../include/hkpContactMgr.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../include/hkpAgentMachineMode.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkVector4_S.h"
#include "../../../../../../../include/hkpAgent1nSector.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/AgentSectorPointerArray.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/QuantizedFloat8.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../include/hkpSphereRepShape.h"

// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachine_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachine.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/1n/hkpagent1nmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void ProcessEntryPair();
void hkAgent1nMachine_VisitAllAgents(int, int, void*);
void hkAgent1nMachine_UpdateShapeCollectionFilter(int b, int a);
typedef unsigned int BlockPoolsize_t;
struct BlockPoolAllocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct BlockPoolMemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BlockPoolAllocator* m_pStreamAllocator;

    BlockPoolAllocator& heap() { return *m_pStreamAllocator; }
};
extern "C" BlockPoolMemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(BlockPoolAllocator* alloc, void* array, int numElements, int sizeElem);
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);
struct BlockPoolBlock {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    int unk18;

    BlockPoolBlock() { unk00 = 0; }
    static void* operator new(BlockPoolsize_t, void* p) throw() { return p; }
};
typedef hkArrayBase<BlockPoolBlock*> BlockPoolArray;
void __cdecl InitBlockPool(BlockPoolArray* blocks);
// hkAgentNmMachine: update the collision filter of one agent entry
struct S_00da40e0_ConstraintOwner;
struct __declspec(align(16)) S_00da40e0_MotionState {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
};

struct S_00da40e0_ShapeCollectionFilter {
    virtual hkBool IsCollisionEnabled(const hkpCollisionInput& input, const hkpCdBody& a,
        const hkpCdBody& b, const hkpShapeContainer& containerShapeA,
        const hkpShapeContainer& containerShapeB, unsigned int keyA, unsigned int keyB) const = 0;
};
struct S_00da40e0_CollidableCollidableFilter {
    virtual void unk0();
};
struct S_00da40e0_ShapeKeyPair {
    unsigned int m_uiShapeKeyA;
    unsigned int m_uiShapeKeyB;
};
struct S_00da40e0_Entry {
    unsigned char m_ucAgentType;
    unsigned char m_ucNnTrackType;
    unsigned char m_usNumContactPoints;
    unsigned char m_iElementCount;
    S_00da40e0_ShapeKeyPair m_kShapeKeyPair;
};
struct S_00da40e0_AgentData;
typedef void (__cdecl *S_00da40e0_DestroyFunc)(S_00da40e0_Entry* entry, S_00da40e0_AgentData* agentData,
    hkpContactMgr* mgr, S_00da40e0_ConstraintOwner& constraintOwner, hkpCollisionDispatcher* dispatcher);
typedef void (__cdecl *S_00da40e0_UpdateFilterFunc)(S_00da40e0_Entry* entry, S_00da40e0_AgentData* agentData,
    const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
    hkpContactMgr* mgr, S_00da40e0_ConstraintOwner& constraintOwner);

struct S_00da40e0_FilterHolder;

struct S_00da40e0_FilterHolder : S_00da40e0_CollidableCollidableFilter {
    int unk04;
    int unk08;
};
struct S_00da40e0_Filter : S_00da40e0_FilterHolder, S_00da40e0_ShapeCollectionFilter {
};
struct S_00da40e0_Input {
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
    const hkpShapeContainer* m_containerA;
    const hkpShapeContainer* m_containerB;
    const hkpCollisionInput* m_pRayCastInput;
    hkpContactMgr* m_pContactManager;
    S_00da40e0_ConstraintOwner* m_pConstraintOwner;
};
const hkpCdBody* __cdecl hkAgentMachine_processTransformedShapes(const hkpCdBody* cdBody, hkpCdBody* newCdBodies,
    S_00da40e0_MotionState* newMotionStates, int numSlots, unsigned char& changeCounter);
S_00da40e0_Entry* __cdecl ProcessCollisionEntry(const S_00da40e0_Input& aInput, S_00da40e0_Entry* entry, S_00da40e0_AgentData* agentData);
// hkpAgent1nMachine shape-collection filter visitor (one container side): re-check the filter for
struct ShapeCollectionFilter1n {
    virtual hkBool IsCollisionEnabled(const hkpCollisionInput& input, const hkpCdBody& a,
        const hkpCdBody& b, const hkpShapeContainer& containerShapeB, unsigned int keyB) const = 0;
    virtual hkBool IsCollisionEnabled(const hkpCollisionInput& input, const hkpCdBody& a,
        const hkpCdBody& b, const hkpShapeContainer& containerShapeA,
        const hkpShapeContainer& containerShapeB, unsigned int keyA, unsigned int keyB) const = 0;
};
struct Filter1n : S_00da40e0_FilterHolder, ShapeCollectionFilter1n {
};
S_00da40e0_Entry* __cdecl ProcessEntryPair(const S_00da40e0_Input& in, S_00da40e0_Entry* entry, S_00da40e0_AgentData* agentData);

extern const float DAT_01012054;

struct FourByteState
{
    unsigned char m_ucAgentType;
    unsigned char m_ucNnTrackType;
    unsigned char m_usNumContactPoints;
    unsigned char m_iElementCount;
};
struct ByteStateWithThreeIntegers : public FourByteState
{
    int m_uiCollisionShapeKey;
    int m_unk08;
    int m_unk0C;
};
struct ByteStateWithMixedNumericData : public FourByteState
{
    int m_uiCollisionShapeKey;
    int m_unk08;
    float m_fFloatValue;
    hkVector4 m_vSeparatingNormal;
};


struct CollisionAgentContext;
typedef void (__cdecl *InvalidateTimFunc)(FourByteState* entry, void* agentData, CollisionAgentContext& input);
struct CollisionAgentContext
{
    char* m_pCollisionDispatcher;
};
void hkpAgent1nSector_ProcessEntries_00da3510(AgentSectorPointerArray& agentTrack, CollisionAgentContext& input);
typedef void (__cdecl *Da35FuncPtr)(void* entry, void* payload, float fa, float fb, void* holder);
void __cdecl _hkAgent1nMachine_WarpTime(hkpAgent1nSector*** container, float fa, float fb, void** holder);
static void* __cdecl Da35Search(hkpAgent1nSector*** container, int key1, int key2, void** out)
{
    hkpAgent1nSector** streams = *container;
    hkpAgent1nSector* stream = *streams;
    int size = stream->m_uiAgentCount;
    streams += 1;
    for (;;) {
        unsigned char* end = (unsigned char*)stream + size + 0x10;
        unsigned char* p = (unsigned char*)stream + 0x10;
        do {
            unsigned char cmd = p[0];
            switch (cmd) {
            case 2: case 3: case 6: case 10: case 11: case 14: {
                unsigned char* payload = p + 0x10;
                if (*(int*)(p + 8) == key2 && *(int*)(p + 4) == key1) {
                    *out = payload;
                    return p;
                }
                p += p[3];
                break;
            }
            case 4: case 5: case 12: case 13: {
                unsigned char* payload = p + 0x20;
                if (*(int*)(p + 8) == key2 && *(int*)(p + 4) == key1) {
                    *out = payload;
                    return p;
                }
                p += p[3];
                break;
            }
            case 0:
                p += p[3];
                break;
            case 1:
                return 0;
            case 7: case 8: case 9:
                break;
            default:
                break;
            }
        } while (p < end);
        stream = *streams;
        size = stream->m_uiAgentCount;
        streams += 1;
    }
}
struct BlockPoolHeap : BlockPoolAllocator {
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};
__forceinline BlockPoolHeap& fullHeap()
{
    return static_cast<BlockPoolHeap&>(hkMemoryRouter_getInstance().heap());
}
void hkAgent1nMachine_Destroy(BlockPoolArray* blocks, hkpCollisionDispatcher* dispatcher, hkpContactMgr* mgr, S_00da40e0_ConstraintOwner& owner);
#include <string.h>
#include "../../../../../../../include/hkMatrix3.h"
struct StreamAllocator : BlockPoolAllocator {
    virtual void ReleaseBlock(void*, int);
};
struct StreamRecord { int first; int second; void* third; void* fourth; };
struct StreamHeader { void* a; void* b; void* c; void* d; void* e; void* f; void* g; void* h; };
__forceinline static void streamCopy(void* dst, const void* src, int count) {
    const int* s = (const int*)src;
    int* d = (int*)dst;
    do {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    } while (--count > 0);
}
void __cdecl hkMemUtil_memMove(void*, const void*, unsigned int);
typedef unsigned char* (__cdecl *StreamTransform)(void*, unsigned char*, unsigned char*);
void hkAgent1nMachine_VisitAllAgents(int array_arg, int header_arg, void* callback);

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
#include "../../../../../../../include/hkResult.h"
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;

extern "C"
{
extern const hkReal g_afRealLookupTable[256];
}




class hkStatisticsCollector;

typedef __m128 hkQuadReal;
typedef const hkVector4_S&hkVector4Parameter;



__forceinline hkQuadReal&hkVector4_S::getQuad()
{
return m_vComponents;
}
__forceinline const hkQuadReal&hkVector4_S::getQuad()const
{
return m_vComponents;
}
__forceinline void hkVector4_S::setSub4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
__forceinline hkReal&hkVector4_S::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
__forceinline const hkReal&hkVector4_S::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}

__forceinline void hkVector4_S::operator=(const hkVector4_S& v)
{
m_vComponents=v.m_vComponents;
}

__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getStart() { return m_start.val(); }
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable() { return getEnd()<getCapacityMinus16(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end=ptr; }

__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}
typedef hkUint16 hkContactPointId;

__forceinline hkContactPoint& hkContactPoint::operator=(const hkContactPoint& other)
{
m_vContactPosition.m_vComponents=other.m_vContactPosition.m_vComponents;
m_vSeparatingNormal.m_vComponents=other.m_vSeparatingNormal.m_vComponents;
return *this;
}
inline const hkVector4&hkContactPoint::getPosition()const
{
return m_vContactPosition;
}
inline const hkVector4&hkContactPoint::getNormal()const
{
return m_vSeparatingNormal;
}
inline hkReal hkContactPoint::getDistance()const
{
return reinterpret_cast<const hkReal*>(&m_vSeparatingNormal.m_vComponents)[3];
}
class Vector4WithInt24W:public hkVector4_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};

#include "../../../../../../../include/hkpBufferSize.h"
struct __declspec(align(16)) hkpShapeBuffer { char m_data[HK_SHAPE_BUFFER_SIZE]; };
typedef hkUint32 hkpShapeKey;
class ShapeKeyCombination
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
hkpShapeKey m_uiShapeKeyA;
hkpShapeKey m_uiShapeKeyB;};
__forceinline hkpShapeType hkpShape::getType()const
{
return *reinterpret_cast<const hkpShapeType*>(&m_type);
}

__forceinline const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
__forceinline const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
__forceinline hkpCdBody::hkpCdBody(const hkpCdBody*parent)
{
m_parent=parent;
m_pMotionState=parent->m_pMotionState;
}
__forceinline void hkpCdBody::SetCollisionShapeAndKey(const hkpShape*shape,hkpShapeKey key)
{
m_pCollisionShape=shape;
m_uiCollisionShapeKey=key;
}
struct GskAgentInput;
struct WorldOperationEntry;
class hkpConstraintOwner;
class hkpCollisionAgent;


struct AgentSubtypeMarker:public hkpAgent3Input
{};

class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;
__forceinline hkAgent3::RemovePointFunc hkpCollisionDispatcher::getAgent3RemovePointFunc(hkAgent3::AgentType type)
{
return m_kAgent3FunctionTable[type].m_pAgentFunction4;
}
__forceinline hkAgent3::CommitPotentialFunc hkpCollisionDispatcher::getAgent3CommitPotentialFunc(hkAgent3::AgentType type)
{
return m_kAgent3FunctionTable[type].m_pAgentFunction5;
}
__forceinline hkAgent3::CreateZombieFunc hkpCollisionDispatcher::getAgent3CreateZombieFunc(hkAgent3::AgentType type)
{
return m_kAgent3FunctionTable[type].m_pCreateZombieFunc;
}
__forceinline hkBool32 hkpCollisionDispatcher::hasAlternateType(hkpShapeType type,hkpShapeType alternateType)
{
;
;
return(m_auiAlternateTypeFlags[type]&(1<<alternateType));
}
class ConvexFeaturePairCache;
class ContactImpulseInfo
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
hkReal m_fAccumulatedImpulse;};
class PhysicsMaterial:public ContactImpulseInfo,public hkContactPointMaterial
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}public:
hkReal m_uiUserData;
typedef hkUint32 UserData;};
__declspec(align(16))class ContactDataPhysicsMaterial:public PhysicsMaterial
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}UserData m_aiContactData[7];};
hkContactPointId hkpContactMgr::addContactPoint(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp)
{
return CreateContactPoint(a,b,input,output,contactCache,cp);
}
void hkpContactMgr::removeContactPoint(hkContactPointId cpId,hkpConstraintOwner&constraintOwner)
{
removeContactPointImpl(cpId,constraintOwner);
}
struct ContactPointWithId
{
hkContactPoint m_kPoint;
hkPadSpu<hkUint32>m_usContactPointId;};
struct GskAgentInput:public hkpCollisionInput
{
public:
GskAgentInput();
public:
hkStepInfo m_pStepInfo;
mutable hkPadSpu<hkpCollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};
class ConvexFeaturePairCache
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const hkTransform&btoa);};
__declspec(align(16))class HeapContactFeatureCache:public ConvexFeaturePairCache
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};enum{HK_MAX_CONTACT_POINT=256};
struct CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
hkPadSpu<ContactPointWithId*>m_pAlignedPairData;
hkPadSpu<hkpConstraintOwner*>m_pConstraintOwner;
ContactPointWithId m_akContactPoints[HK_MAX_CONTACT_POINT];
struct CollisionCacheState
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(CollisionContactResults::CollisionCacheState));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
inline CollisionCacheState();
inline void flip();
public:
hkContactPoint m_vContactPoint;
hkPadSpu<hkReal>m_uiCommandId;
hkPadSpu<hkReal>m_fSeparation;
HeapContactFeatureCache m_kGskCache;
ContactDataPhysicsMaterial m_kProperties;
};
struct CollisionCacheState m_fTimeOfImpact;};
struct WorldOperationEntry:public CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}public:
struct ContactPointAgentEntry
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(WorldOperationEntry::ContactPointAgentEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
ContactPointWithId*m_vContactPoint;
FourByteState*m_pAgentEntry;
hkpAgentData*m_pUserData;
};
struct ContactPointBuffer
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(WorldOperationEntry::ContactPointBuffer));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
void reset()
{
m_pFirstFreeContactPoint=&m_akContactRecords[0];
m_ppFirstFreeContactPointer=&m_apContactPointPointers[0];
}
ContactPointAgentEntry*m_pFirstFreeContactPoint;
ContactPointWithId**m_ppFirstFreeContactPointer;
ContactPointWithId*m_apContactPointPointers[HK_MAX_CONTACT_POINT];
ContactPointAgentEntry m_akContactRecords[HK_MAX_CONTACT_POINT];
};
public:
hkPadSpu<ContactPointBuffer*>m_akContactRecords;};
namespace hkVector4Util_S
{
__forceinline void __cdecl dot3_3vs3(const hkVector4_S&a0,const hkVector4_S&b0,const hkVector4_S&a1,const hkVector4_S&b1,const hkVector4_S&a2,const hkVector4_S&b2,hkVector4_S&dotsOut);}
inline void __cdecl hkVector4Util_S::dot3_3vs3(const hkVector4_S&a0,const hkVector4_S&b0,const hkVector4_S&a1,const hkVector4_S&b1,const hkVector4_S&a2,const hkVector4_S&b2,hkVector4_S&dotsOut)
{
register hkQuadReal c0=_mm_mul_ps(a0.getQuad(),b0.getQuad());
register hkQuadReal c1=_mm_mul_ps(a1.getQuad(),b1.getQuad());
register hkQuadReal c2=_mm_mul_ps(a2.getQuad(),b2.getQuad());
{hkQuadReal _tmp,_ctmp;_tmp=_mm_unpacklo_ps(c0,c1);_ctmp=_mm_shuffle_ps(_mm_unpackhi_ps(c0,c1),c2,(((3)<<6)|((2)<<4)|((1)<<2)|((0))));c0=_mm_movelh_ps(_tmp,c2);c1=_mm_shuffle_ps(_mm_movehl_ps(c0,_tmp),c2,(((3)<<6)|((1)<<4)|((1)<<2)|((0))));c2=_ctmp;};
dotsOut.getQuad()=_mm_add_ps(_mm_add_ps(c0,c1),c2);}
struct hkpAgent1nTrack_S;
struct ShapeKeyAgentEntry:FourByteState
{
ShapeKeyCombination m_kShapeKeyPair;};
struct EmptyMarker
{};
typedef hkpAgentData*(*hkAgent1nMachine_VisitorCallback)(EmptyMarker&vin,ShapeKeyAgentEntry*entry,hkpAgentData*agentData);
extern "C"
{
void __cdecl ResetAgentTrack(hkpAgent1nTrack_S&agentTrack);
void __cdecl BuildShapeCollectionBWorldOperations(hkpAgent1nTrack_S&agentTrack,const AgentSubtypeMarker&input,const hkpShapeContainer*shapeContainterB,const hkpShapeKey*hitList,WorldOperationEntry&output);
void __cdecl BuildShapePairWorldOperations(hkpAgent1nTrack_S&agentTrack,const AgentSubtypeMarker&input,const hkpShapeContainer*shapeContainerA,const hkpShapeContainer*shapeCollectionB,const ShapeKeyCombination*hitList,WorldOperationEntry&output);
void __cdecl UpdateAgentTrackShapeFilter(hkpAgent1nTrack_S&agentTrack,EmptyMarker&vin);
void __cdecl hkAgentNmMachine_UpdateShapeCollectionFilter(hkpAgent1nTrack_S&agentTrack,EmptyMarker&vin);
void __cdecl VisitTrackedAgents(hkpAgent1nTrack_S&agentTrack,EmptyMarker&vin,hkpContactMgr*mgr,hkAgent1nMachine_VisitorCallback visitor);
void __cdecl DestroyAgentTrack(hkpAgent1nTrack_S&agentTrack,hkpCollisionDispatcher*dispatch,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
void __cdecl CollideTrackedAgents(hkpAgent1nTrack_S&track,const hkpCollisionInput&input);
void __cdecl UpdateTrackedAgentTimes(hkpAgent1nTrack_S&track,hkTime oldTime,hkTime newTime,const hkpCollisionInput&input);
ShapeKeyAgentEntry*hkAgent1nMachine_FindAgent(hkpAgent1nTrack_S&agentTrack,ShapeKeyCombination keyPair,hkpAgentData**agentDataOut);
}


extern hkResult __cdecl FindContactsAgainstConvexShapes(const hkTransform&transA,const hkpConvexShape*shapeA,const hkpConvexShape**shapesB,int numShapesB,const hkTransform&aTb,hkContactPoint**pointsOut);
enum hkContactPairCompare
{
HK_CONTACT_PAIR_NO_CONFLICT,
HK_CONTACT_PAIR_REJECT_NEW,
HK_CONTACT_PAIR_CONFLICT
};
// Retain the original SIMD dot product and scalar extraction at the call site.
static __forceinline hkReal contactNormalDot3(const hkVector4& a,const hkVector4& b)
{
hkQuadReal x2=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,0x55),x2);
hkReal result;
_mm_store_ss(&result,_mm_add_ss(_mm_shuffle_ps(x2,x2,0xaa),xySum));
return result;
}
static __forceinline hkContactPairCompare contactPointIsValid(hkReal radiusA,const hkContactPoint&pointToCheck,const hkpCollisionQualityInfo&qi,hkReal radiusB,const ContactPointWithId&referenceCdPoint)
{
const hkContactPoint*referencePoint=&referenceCdPoint.m_kPoint;
hkVector4_S diff;diff.setSub4(reinterpret_cast<const hkVector4_S&>(referencePoint->getPosition()),reinterpret_cast<const hkVector4_S&>(pointToCheck.getPosition()));
// Materialize both normals before the products to retain the original SIMD evaluation.
hkVector4_S dots;
hkVector4_S normal0;normal0=reinterpret_cast<const hkVector4_S&>(pointToCheck.getNormal());
hkVector4_S normal1;normal1=reinterpret_cast<const hkVector4_S&>(referencePoint->getNormal());
hkVector4Util_S::dot3_3vs3(normal0,diff,normal1,diff,normal0,normal1,dots);
hkReal d0=-dots(1);
hkReal d1=dots(0);
hkReal n0n1=dots(2);
d0+=(n0n1-1.0f)*radiusA;
d1+=(n0n1-1.0f)*radiusA;
hkReal radiusSum=radiusA+radiusB;
if(d0>radiusSum)
{
return HK_CONTACT_PAIR_NO_CONFLICT;
}
if(n0n1>0.9999f&&referenceCdPoint.m_usContactPointId==(0xffff))
{
return HK_CONTACT_PAIR_NO_CONFLICT;
}
const hkReal dist0=pointToCheck.getDistance();
const hkReal dist1=referenceCdPoint.m_kPoint.getDistance();
if(referenceCdPoint.m_usContactPointId==(0xffff)&&n0n1<0.8f&&d0+d1<0.1f&&dist0+dist1<-radiusSum*2.0f)
{
return HK_CONTACT_PAIR_CONFLICT;
}
hkReal minDeltaDistanceToAcceptNewPoint=0.0f;
if(referenceCdPoint.m_usContactPointId !=(0xffff))
{
minDeltaDistanceToAcceptNewPoint=qi.m_fMinimumCollisionSeparation*0.05f;
}
if(pointToCheck.getDistance()<=referencePoint->getDistance()-minDeltaDistanceToAcceptNewPoint)
{
return HK_CONTACT_PAIR_NO_CONFLICT;
}
return HK_CONTACT_PAIR_REJECT_NEW;}
// @fnv 0x00da3930
// src: GUESS 0x00da3930 (confidence: low)
void __cdecl hkpAgent3Input_ProcessEntries_00da3930(hkpAgent3Input&input,const hkpShapeContainer*shapeCollection,WorldOperationEntry&output)
{
int numConflictContacts=0;
hkUint16 conflictContacts[HK_MAX_CONTACT_POINT];
hkUint16 newIds[HK_MAX_CONTACT_POINT];
hkpShapeBuffer shapeBuffer;
WorldOperationEntry::ContactPointBuffer*potentialContacts=output.m_akContactRecords;
{
const hkpConvexShape*shapeA=static_cast<const hkpConvexShape*>(input.m_pBodyA->getShape());
WorldOperationEntry::ContactPointAgentEntry*contactRefPtr=&potentialContacts->m_akContactRecords[0];
for(int i=0;contactRefPtr<potentialContacts->m_pFirstFreeContactPoint;i++,contactRefPtr++)
{
newIds[i]=(0xffff);
ContactPointWithId*check=contactRefPtr->m_vContactPoint;
{
hkBool hasConflict=false;
for(ContactPointWithId**pref=&potentialContacts->m_apContactPointPointers[0];pref<potentialContacts->m_ppFirstFreeContactPointer;pref++)
{
ContactPointWithId*ref=*pref;
if(check !=ref)
{
hkReal radiusB=0.0f;
hkContactPairCompare contactPairCheckResult=contactPointIsValid(shapeA->getRadius(),check->m_kPoint,*reinterpret_cast<const GskAgentInput*>(input.m_pRayCastInput.val())->m_pCollisionQualityInfo.val(),radiusB,*ref);
if(contactPairCheckResult !=HK_CONTACT_PAIR_NO_CONFLICT)
{
if(contactPairCheckResult==HK_CONTACT_PAIR_REJECT_NEW)
{
goto tryNextPoint;
}
hasConflict=true;
}
}
}
if(hasConflict)
{
conflictContacts[numConflictContacts++]=hkUint16(i);
}
}
{
WorldOperationEntry::ContactPointAgentEntry*toCommit=&potentialContacts->m_akContactRecords[i];
ShapeKeyAgentEntry*entry=reinterpret_cast<ShapeKeyAgentEntry*>(toCommit->m_pAgentEntry);
const hkpShape*shape=shapeCollection->GetShapeForKey(entry->m_kShapeKeyPair.m_uiShapeKeyB,shapeBuffer);
hkpCdBody modifiedBodyB(input.m_pBodyB);
modifiedBodyB.SetCollisionShapeAndKey(shape,entry->m_kShapeKeyPair.m_uiShapeKeyB);
newIds[i]=input.m_pContactManager->addContactPoint(*input.m_pBodyA,modifiedBodyB,*reinterpret_cast<const GskAgentInput*>(input.m_pRayCastInput.val()),output,0,toCommit->m_vContactPoint->m_kPoint);
if(newIds[i]!=(0xffff))
{
input.m_pContactManager->ReserveContactPoints(-1);
}
}
tryNextPoint:;
}
}
{
hkpCollisionDispatcher*dis=reinterpret_cast<const GskAgentInput*>(input.m_pRayCastInput.val())->m_pCollisionDispatcher;
for(int a=0;a<numConflictContacts;a++)
{
int i=conflictContacts[a];
WorldOperationEntry::ContactPointAgentEntry*cr=&potentialContacts->m_akContactRecords[i];
dis->getAgent3CreateZombieFunc(cr->m_pAgentEntry->m_ucNnTrackType)(cr->m_pAgentEntry,cr->m_pUserData,(0xffff));
}
}
while(numConflictContacts>=2)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "Conflicts";h->setTime();mStream.setEnd((char*)(h+1));}};
int p0=0;
int p1=1;
{
hkReal minDot=2.0f;
for(int a=0;a<numConflictContacts;a++)
{
WorldOperationEntry::ContactPointAgentEntry*refA=&potentialContacts->m_akContactRecords[conflictContacts[a]];
const hkVector4*normalA=&refA->m_vContactPoint->m_kPoint.getNormal();
for(int b=a+1;b<numConflictContacts;b++)
{
WorldOperationEntry::ContactPointAgentEntry*refB=&potentialContacts->m_akContactRecords[conflictContacts[b]];
hkReal d=contactNormalDot3(*normalA,refB->m_vContactPoint->m_kPoint.getNormal());
if(d<minDot)
{
minDot=d;p0=a;p1=b;
}
}
}
}
{
WorldOperationEntry::ContactPointAgentEntry*ref0=&potentialContacts->m_akContactRecords[conflictContacts[p0]];
WorldOperationEntry::ContactPointAgentEntry*ref1=&potentialContacts->m_akContactRecords[conflictContacts[p1]];
ShapeKeyAgentEntry*header0=reinterpret_cast<ShapeKeyAgentEntry*>(ref0->m_pAgentEntry);
ShapeKeyAgentEntry*header1=reinterpret_cast<ShapeKeyAgentEntry*>(ref1->m_pAgentEntry);
const hkpConvexShape*shapeA=static_cast<const hkpConvexShape*>(input.m_pBodyA->getShape());
if(!reinterpret_cast<const GskAgentInput*>(input.m_pRayCastInput.val())->m_pCollisionDispatcher->hasAlternateType(shapeA->getType(),HK_SHAPE_CONVEX)){break;}
const hkpConvexShape*shape0=static_cast<const hkpConvexShape*>(shapeCollection->GetShapeForKey(header0->m_kShapeKeyPair.m_uiShapeKeyB,shapeBuffer));
if(!reinterpret_cast<const GskAgentInput*>(input.m_pRayCastInput.val())->m_pCollisionDispatcher->hasAlternateType(shape0->getType(),HK_SHAPE_CONVEX)){break;}
hkpShapeBuffer shapeBuffer2;
const hkpConvexShape*shape1=static_cast<const hkpConvexShape*>(shapeCollection->GetShapeForKey(header1->m_kShapeKeyPair.m_uiShapeKeyB,shapeBuffer2));
if(!reinterpret_cast<const GskAgentInput*>(input.m_pRayCastInput.val())->m_pCollisionDispatcher->hasAlternateType(shape1->getType(),HK_SHAPE_CONVEX)){break;}
const hkpConvexShape*shapesB[2]={shape0,shape1};
hkContactPoint*points[2]={&ref0->m_vContactPoint->m_kPoint,&ref1->m_vContactPoint->m_kPoint};
FindContactsAgainstConvexShapes(input.m_pBodyA->getTransform(),shapeA,shapesB,2,input.m_kTransform,points);
}
conflictContacts[p1]=conflictContacts[--numConflictContacts];
conflictContacts[p0]=conflictContacts[--numConflictContacts];
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
if(numConflictContacts)
{
if(newIds[conflictContacts[0]]!=(0xffff))
{
input.m_pContactManager->removeContactPoint(newIds[conflictContacts[0]],*output.m_pConstraintOwner.val());
newIds[conflictContacts[0]]=(0xffff);
input.m_pContactManager->ReserveContactPoints(1);
}
}
{
hkpCollisionDispatcher*dis=reinterpret_cast<const GskAgentInput*>(input.m_pRayCastInput.val())->m_pCollisionDispatcher;
WorldOperationEntry::ContactPointAgentEntry*cr=potentialContacts->m_pFirstFreeContactPoint;
int numPotential=int(cr-&potentialContacts->m_akContactRecords[0]);
for(int i=numPotential-1;i>=0;i--)
{
cr--;
hkContactPointId iContactPointId=newIds[i];
if(iContactPointId !=(0xffff))
{
dis->getAgent3CommitPotentialFunc(cr->m_pAgentEntry->m_ucNnTrackType)(cr->m_pAgentEntry,cr->m_pUserData,iContactPointId);
cr->m_vContactPoint->m_usContactPointId=iContactPointId;
}
else
{
input.m_pContactManager->ReserveContactPoints(-1);
dis->getAgent3RemovePointFunc(cr->m_pAgentEntry->m_ucNnTrackType)(cr->m_pAgentEntry,cr->m_pUserData,iContactPointId);
output.m_pAlignedPairData=output.m_pAlignedPairData-1;
*cr->m_vContactPoint=*output.m_pAlignedPairData;
}
}
}
}
