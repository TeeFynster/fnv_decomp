#include "../../../../../../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
// The original's timer stamp helper, a unit-local view (declared only here, as before).
struct ProfRec_hkpcontinuoussimulation_rtm_variant : hkMonitorStream::TimerCommand
{
    void stamp();
};
#include "../../../../../../../include/hkBool.h"
// The RTM unit uses an intrinsic union without byte lanes. Adding byte lanes
// changes alias analysis and the generated code for FUN_00d0cb00.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
// Exe 0x00d0cb00 FUN_00d0cb00: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_mul_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_add_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_sub_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 _A, LocalM128 _B, unsigned int _Imm8);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_movelh_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_movehl_ps(LocalM128 _A, LocalM128 _B);
#endif
// LocalVecArray: unit-local copy of the former shared stand-in Vec. This unit uses it as a 12-byte {m_pData, m_iArrayLength, m_iCapacity} array header (the hkArray layout), not as a point.
#include <xmmintrin.h>
class Matrix;
class Scalar;
class Simd;
class Tok;
class Mask;
class Elem;
class Iter;
class CIter;
class CMutIter;
class Mat3;
class Mat4;
class hkVector4;
class hkQuaternion;

class LocalVecArray
{
public:
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        struct
        {
            void* m_pData;
            int m_iArrayLength;
            int m_iCapacity;
        };
    };

    LocalVecArray();
    LocalVecArray(float a, float b, float c);
    // Keep the implicit copy constructor, copy assignment and destructor trivial.

    void negative(const LocalVecArray& n);
    void inv(const Matrix& m, const LocalVecArray& n);
    void point(const Matrix& m, const LocalVecArray& b);
    void difference(const LocalVecArray& a, const LocalVecArray& b);
    Scalar dot(const LocalVecArray& n) const;
    Scalar at(int i) const;
    void set(float a, float b, float c, float d);

    Simd lengthSquared() const;
    void mul(const Simd& factor);
    void SetProduct(const Simd& factor, const LocalVecArray& v);

    void resize(unsigned n);
    Tok& operator[](unsigned i);
    void release(int elemSize);

    LocalVecArray& operator-=(const LocalVecArray& v);
    LocalVecArray& operator+=(const LocalVecArray& v);
    LocalVecArray operator*(float scale) const;
    LocalVecArray operator+(const LocalVecArray& v) const;
    LocalVecArray operator-(const LocalVecArray& v) const;
    float Squared() const;
    float Length() const;
    float Normalize();
    float Dot(const LocalVecArray& v) const;
    LocalVecArray Cross(const LocalVecArray& v) const;
    LocalVecArray ApplyScaled(float scale);
    LocalVecArray ApplyScaled(float scale) const;
    void ProcessState_00acf580(unsigned n, Tok value);
    LocalVecArray GetNegatedVector();
    LocalVecArray GetNegatedVector() const;
    LocalVecArray FUN_0053d1a0(const LocalVecArray& v);
    LocalVecArray FUN_004b3800(const LocalVecArray& v);
    LocalVecArray FUN_004b3800(const LocalVecArray& v) const;
    LocalVecArray FUN_00439e90(const LocalVecArray& v);
    LocalVecArray FUN_00439e90(const LocalVecArray& v) const;
    LocalVecArray SubtractIntoVector(const LocalVecArray& v);
    LocalVecArray SubtractIntoVector(const LocalVecArray& v) const;
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    void FUN_006815c0();
    void ScaleComponents(float scale);
    LocalVecArray& ComputeValue_0063c8a0(const LocalVecArray& v);
    float FUN_004a7290();
    float FUN_004a7290() const;
    void SetQuaternionComponentsFromVector(const float* values);
    void FUN_00a38560();
    void NiQuaternion_ToRotation(void* value);

    LocalVecArray& ScaleByInverse(float divisor);
    float FUN_00457910();
    LocalVecArray* FastNavMeshTriLocation_GetLocation();
    bool HasEqualComponents(const LocalVecArray& v);

    LocalM128 get() const;
    void set(LocalM128 value);
    void operator=(const LocalM128& value);
    operator LocalM128() const;
    LocalM128& getQuad();
    const LocalM128& getQuad() const;
    LocalM128& quad();
    const LocalM128& quad() const;
    float& operator()(int component);
    const float& operator()(int component) const;
    void setZero4();
    void setSub4(const LocalVecArray& a, const LocalVecArray& b);
    void setAdd4(const LocalVecArray& a, const LocalVecArray& b);
    void setMul4(const LocalVecArray& a, const LocalVecArray& b);
    void setMul4(const Scalar& a, const LocalVecArray& b);
    void add4(const LocalVecArray& v);
    void mul4(const LocalVecArray& v);
    void mul4(const Scalar& value);
    void add3clobberW(const LocalVecArray& v);
    void sub3clobberW(const LocalVecArray& v);
    void setBroadcast3clobberW(const LocalVecArray& v, int component);
    Scalar horizontalAdd3() const;
    void setCross(const LocalVecArray& a, const LocalVecArray& b);
    Scalar dot3(const LocalVecArray& v) const;
    Scalar lengthSquared3() const;
    Scalar lengthInverse3() const;
    void normalize3();
    Scalar getSimdAt(int component) const;
    void setInterpolate4(const LocalVecArray& a, const LocalVecArray& b, const Scalar& fraction);
    void setAddMul4(const LocalVecArray& a, const LocalVecArray& b, const Scalar& scale);
    void setNeg4(const LocalVecArray& v);
    Mask compareLessThanZero4() const;
    void SetRotatedDirection(const hkQuaternion& rotation, const LocalVecArray& direction);
    void setRotatedTranslation(const hkQuaternion& rotation, const LocalVecArray& direction);
    void cross(const LocalVecArray& a, const LocalVecArray& b);
    Scalar squared() const;
    Scalar inverseLength() const;
    void normalize();
    void negate(const LocalVecArray& v);

    void setTransformedPos_00c7f640(const void* matrix, const hkVector4& point);
    void setTransformedPos_00c7f640(Mat4* matrix, void* point);
    void setTransformedPos_00c7f640(const void* matrix, const LocalVecArray* point);
    void setTransformedPos_00c7f640(const void* matrix, const void* point);
    void hkVector4_setRotatedDir(Mat3* matrix, void* point);
    void hkVector4_setRotatedDir(const void* matrix, const LocalVecArray* point);
    void Normalize_00b12790();
    void Diff_00b13040(LocalVecArray* out, const LocalVecArray* v);
    LocalVecArray* ScaleSwizzled(LocalVecArray* out, float factor);
    void AddVector(LocalVecArray* out, const LocalVecArray* v);
    float Dot(const LocalVecArray& v);
    LocalVecArray* FUN_004a3c90(const LocalVecArray* v);
    LocalVecArray* FUN_0062b0a0(LocalVecArray* out, LocalVecArray* v);
    LocalVecArray* hkVector4_lengthInverse3(LocalVecArray* target);

    void FUN_00cf7690(Elem* value);
    void UpdateState_00b1e970();
    Iter begin();
    Iter end();
    CIter UpdateState_00b33030(CIter first, CIter last);
    void m_vStrips_clear();
    unsigned int size() const;
    unsigned int capacity() const;
    void ClearAllElements();
    void B2EDestroyRange_Thunk(Elem* first, Elem* last);
    bool InitBuffer(unsigned int count);
    Elem* _Ucopy(Elem* first, Elem* last, Elem* out);
    LocalVecArray& CTreeEngine_SetLeafTextures(const LocalVecArray& v);
    CMutIter ProcessAndReturnValue_00aceb80(CMutIter first, CMutIter last);
    void ProcessState_00acac40();
    LocalVecArray& ReleaseStorage_00ad61e0(const LocalVecArray& v);
};
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkMotionState.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkSweptTransform.h"
// src/havok/physics/dynamics/world/simulation/continuous/hkpcontinuoussimulation_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/world/simulation/continuous/hkpcontinuoussimulation.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/dynamics/world/simulation/continuous/hkpcontinuoussimulation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/continuous/hkpcontinuoussimulation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00d0c6d0_Body {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    unsigned short m_a8;
};
struct S_00d0c6d0_Pair {
    int unk0;
    S_00d0c6d0_Body* m_apEntities[2];
};
struct S_00d0c6d0_Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S_00d0c6d0_Pair* m_pair;
};
struct S_00d0c6d0_Entry {
    S_00d0c6d0_Obj* m_obj;
    int m_iWordAt04;
    int m_8;
};
struct S_00d0c6d0_EntryArray {
    S_00d0c6d0_Entry* m_data;
    int m_iElementCount;
};
struct S_00d0c6d0_ByteArray {
    unsigned char* m_data;
    int m_iElementCount;
};
void hkLs_toiActivateConstraintsLinkingActivatedEntities(S_00d0c6d0_EntryArray* aEntries, int* aIndex, S_00d0c6d0_ByteArray* table);
struct Base { void hkpSimulation_resetCollisionInformationForEntities(int*, int, int, unsigned int); };
struct Object : Base {
    void hkpContinuousSimulation_removeToiEventsOfEntities(int*, int);
    void hkpContinuousSimulation_removeToiEventsOfEntity(int);
    void ProcessEntries(int*, int, int, unsigned int);
};
extern int DAT_010cd45c;
struct Callback { virtual void Invoke(int value); };
struct Receiver {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Invoke(void* data, unsigned int size);
};
struct Manager { int unk00; int unk04; int unk08; int unk0c; int unk10; };
Manager* __cdecl hkMemoryRouter_getInstance();
struct FUN_00d0d0d0_cls {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    void* unk30;
    int unk34;
    int unk38;
    struct Subobject {
        int unk00; int unk04; int unk08;
        Callback* unk0c;
        void ProcessArgument(void* managerValue);
        void Object_DoNothing();
    } sub3c;
    void SetVtableAndProcessState_00cf86d0();
    void Destroy();
};
void __cdecl InitAndDispatch();
struct S_00d0f2e0
{
    void* hkpSimulation_processAgentsOfEntities(void* a, void* b, void* c, void (__cdecl *pfnCallback)(), int iFlags);
    void* hkpContinuousSimulation_collideEntitiesNarrowPhaseContinuous(void* a, void* b, void* c);
};
struct TimeStep {float start,end,delta,inverse;};
struct World {
 TimeStep& time(){return *reinterpret_cast<TimeStep*>(reinterpret_cast<char*>(this)+80);}
};
struct Context {
 World*& world(){return *reinterpret_cast<World**>(reinterpret_cast<char*>(this)+120);}
 int& depth(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+148);}
 int& pending(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+140);}
 int& otherPending(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+144);}
 unsigned char& locked(){return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this)+156);}
 int& mode(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+164);}
 void FUN_00c91120();void UpdateFields_00c91140();
};
struct Body { unsigned char& motion(){return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this)+232);} void* state(){return reinterpret_cast<char*>(this)+240;} };
void __cdecl hkSweptTransformUtil_backStepMotionState(float,void*);
void __cdecl hkRigidMotionUtilStep(TimeStep*,Body**,int,int);
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(World*,Body**,int);
struct Controller {
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void process(Body**,int,Context*,int);
 int flags,kind,capacity,mode;float start,end;
 void hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(Body**,int,Context*,int);
 void hkpContinuousSimulation_collideEntitiesNarrowPhaseContinuous(Body**,int,World*);
 void ProcessBodies(Body**,int,Context*,int);
};
struct SpawnedObject
{
    unsigned int unkD4_dummy;
};
bool *__cdecl IsLessByUnkD4(bool *pbResult, SpawnedObject *pObjectA, SpawnedObject *pObjectB);
struct Element {
    char pad[0xd4];
    unsigned int priority;
};
struct SubItem {
    char pad0[4];
    Element* volatile array[1];
    char pad1[0x12];
    unsigned char index;
};
struct Item {
    char pad[0x30];
    SubItem* volatile sub;
};
hkBool __cdecl CompareItemPriority(const Item* apItemA, const Item* apItemB);
struct D0BD00Entry {
    float m_uiCommandId;
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
};
struct D0BD00Track {
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
    D0BD00Entry* m_entries;
    int m_iNumberOfEntries;
};
struct D0BD00Binding {
    int unk00;
    int unk04;
    D0BD00Track* m_pTrack;
};
struct D0BD00Controller {
    int unk00;
    int unk04;
    int unk08;
    D0BD00Binding* m_pBinding;

    void OffsetEntries(float offset);
};
extern "C" double fabs(double);
struct FUN_00d0bd30_q {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    signed char m_1c;
};
struct FUN_00d0bd30_p {
    FUN_00d0bd30_q* m_00;
    int unk04;
    float m_08;
};
int __cdecl hkLs_areVelocitiesOk(float scale, FUN_00d0bd30_p* pParams, float* pafValues, int aiCount, char** ppTable);
// ---------------------------------------------------------------------------
// Stand-in types for the simulation object that owns the scope table.
//
//   this + 0x30 : ScopeEntry* m_30  - the table of 0x70-byte scope entries
//   this + 0x34 : int         m_34  - the number of live entries
//
// The scope table entry is 0x70 bytes wide; the copy performed when an entry
// is removed moves it in 8-byte chunks (14 of them), so the entry is viewed
// here as a run of ScopeChunk pairs.  The lookup key lives at +0x14.
// ---------------------------------------------------------------------------
struct ScopeChunk {
    unsigned int lo;
    unsigned int hi;
};
struct ScopeEntry {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_key14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
};
struct ScopeQuery {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};
class FUN_00d0bfc0_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    ScopeEntry* m_30;
    volatile int m_34;

    void RemoveMatchingEntries(ScopeQuery* q);
};
struct SolverBody {
    hkVector4 m_unk00;
    hkVector4 m_unk10;
    hkVector4 m_unk20;
    hkVector4 m_unk30;
    hkVector4 m_unk40;
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};
struct VelocityEntry {
    hkVector4 m_unk00;
    hkVector4 m_unk10;
};
struct Entity {
    int m_unk00;
    char m_auiShapeKeys[0xec];
    hkMotionState m_kMotionState;
};
struct EntityRaw {
    int m_unk00;
    int m_unk04[0x28];
    unsigned int m_solverIndex;
};
struct Island {
    int m_unk00[0x12];
    Entity** m_kActorEntries;
    int m_iActorEntryCount;
};
struct ByteArray {
    unsigned char* m_data;
};
struct SolverInfo {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    char* m_apEntities;
    int m_unk10;
    int m_unk14;
    char* m_velocities;
};
struct EntityB {
    char m_auiShapeKeys[0xa4];
    unsigned int m_solverIndex;
    char m_pAuxiliaryObject[0x108];
    hkVector4 m_unk1b0;
    hkVector4 m_unk1c0;
};
void UpdateIslandMotionStates(Island* island, ByteArray* flags, SolverInfo* info);
struct ReportSink {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(const char* name, unsigned int value, int flag);
    virtual void v4();
    virtual void v5(int level, const char* name, void* base, unsigned int bytes, unsigned int data);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned char m_10;
};
struct FilePool {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_getMemSize();
};
struct FUN_00d0c8d0_cls {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    void* m_30;
    unsigned int m_34;
    unsigned int m_38;
    FilePool m_3C;
    unsigned int m_48;

    void hkReferencedObject_calcContentStatistics(ReportSink* sink, void* data);
    void ReportMemoryUsage(ReportSink* a1, int a2);
};
unsigned int hkStatisticsCollector_getAllocatedSize(void* base, unsigned int bytes);
extern char DAT_01269514;
struct InfoBlock {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short m_06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char m_0a;
};
struct Child {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int v08();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    InfoBlock* m_28;
};
struct ItemObj {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Child* m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned char m_1c;
};
struct Entry {
    ItemObj* m_00;
    int m_04;
    int m_08;
};
struct FloatSrc {
    unsigned int unk00;
    unsigned int unk04;
    float m_08;
};
struct SrcA {
    FloatSrc* m_00;
    int m_04;
    unsigned int unk08;
    int m_0c;
};
struct HolderBase {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* m_10;
};
void __cdecl ResizeAudioStream(void* alloc, LocalVecArray* vec, unsigned int elemSize);
int __cdecl hkVector4_ProcessEntries_00d9f6f0(int a, int b, int c, int d, void* e);
int __cdecl hkLs_areVelocitiesOk(float f, Entry* entry, void* out, int a, int b);
unsigned char* __cdecl CollectMatchingEntries(unsigned char* pResult, SrcA* pSrc, LocalVecArray* pVec, int a4, LocalVecArray* dst);
struct S_00d0d150_Vector4 {
    LocalM128 m_vComponents;
    void operator=(const S_00d0d150_Vector4& v) { m_vComponents = v.m_vComponents; }
};
struct S_00d0d150_QualityInfo {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    char m_bUseContinuousPhysics;
    char unk35;
    char unk36;
    char unk37;
    int unk38;
    int unk3c;
};
struct S_00d0d150_Dispatcher {
    int unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    int unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    int unk320, unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    int unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c;
    int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c;
    int unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc;
    int unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4, unk3f8, unk3fc;
    int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c;
    int unk420, unk424, unk428, unk42c, unk430, unk434, unk438, unk43c;
    int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c;
    int unk460, unk464, unk468, unk46c, unk470, unk474, unk478, unk47c;
    int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c;
    int unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4, unk4b8, unk4bc;
    int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc;
    int unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4, unk4f8, unk4fc;
    int unk500, unk504, unk508, unk50c, unk510, unk514, unk518, unk51c;
    int unk520, unk524, unk528, unk52c, unk530, unk534, unk538, unk53c;
    int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c;
    int unk560, unk564, unk568, unk56c, unk570, unk574, unk578, unk57c;
    int unk580, unk584, unk588, unk58c, unk590, unk594, unk598, unk59c;
    int unk5a0, unk5a4, unk5a8, unk5ac, unk5b0, unk5b4, unk5b8, unk5bc;
    int unk5c0, unk5c4, unk5c8, unk5cc, unk5d0, unk5d4, unk5d8, unk5dc;
    int unk5e0, unk5e4, unk5e8, unk5ec, unk5f0, unk5f4, unk5f8, unk5fc;
    int unk600, unk604, unk608, unk60c, unk610, unk614, unk618, unk61c;
    int unk620, unk624, unk628, unk62c, unk630, unk634, unk638, unk63c;
    int unk640, unk644, unk648, unk64c, unk650, unk654, unk658, unk65c;
    int unk660, unk664, unk668, unk66c, unk670, unk674, unk678, unk67c;
    int unk680, unk684, unk688, unk68c, unk690, unk694, unk698, unk69c;
    int unk6a0, unk6a4, unk6a8, unk6ac, unk6b0, unk6b4, unk6b8, unk6bc;
    int unk6c0, unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8, unk6dc;
    int unk6e0, unk6e4, unk6e8, unk6ec, unk6f0, unk6f4, unk6f8, unk6fc;
    int unk700, unk704, unk708, unk70c, unk710, unk714, unk718, unk71c;
    int unk720, unk724, unk728, unk72c, unk730, unk734, unk738, unk73c;
    int unk740, unk744, unk748, unk74c, unk750, unk754, unk758, unk75c;
    int unk760, unk764, unk768, unk76c, unk770, unk774, unk778, unk77c;
    int unk780, unk784, unk788, unk78c, unk790, unk794, unk798, unk79c;
    int unk7a0, unk7a4, unk7a8, unk7ac, unk7b0, unk7b4, unk7b8, unk7bc;
    int unk7c0, unk7c4, unk7c8, unk7cc, unk7d0, unk7d4, unk7d8, unk7dc;
    int unk7e0, unk7e4, unk7e8, unk7ec, unk7f0, unk7f4, unk7f8, unk7fc;
    int unk800, unk804, unk808, unk80c, unk810, unk814, unk818, unk81c;
    int unk820, unk824, unk828, unk82c, unk830, unk834, unk838, unk83c;
    int unk840, unk844, unk848, unk84c, unk850, unk854, unk858, unk85c;
    int unk860, unk864, unk868, unk86c, unk870, unk874, unk878, unk87c;
    int unk880, unk884, unk888, unk88c, unk890, unk894, unk898, unk89c;
    int unk8a0, unk8a4, unk8a8, unk8ac, unk8b0, unk8b4, unk8b8, unk8bc;
    int unk8c0, unk8c4, unk8c8, unk8cc, unk8d0, unk8d4, unk8d8, unk8dc;
    int unk8e0, unk8e4, unk8e8, unk8ec, unk8f0, unk8f4, unk8f8, unk8fc;
    int unk900, unk904, unk908, unk90c, unk910, unk914, unk918, unk91c;
    int unk920, unk924, unk928, unk92c, unk930, unk934, unk938, unk93c;
    int unk940, unk944, unk948, unk94c, unk950, unk954, unk958, unk95c;
    int unk960, unk964, unk968, unk96c, unk970, unk974, unk978, unk97c;
    int unk980, unk984, unk988, unk98c, unk990, unk994, unk998, unk99c;
    int unk9a0, unk9a4, unk9a8, unk9ac, unk9b0, unk9b4, unk9b8, unk9bc;
    int unk9c0, unk9c4, unk9c8, unk9cc, unk9d0, unk9d4, unk9d8, unk9dc;
    int unk9e0, unk9e4, unk9e8, unk9ec, unk9f0, unk9f4, unk9f8, unk9fc;
    int unka00, unka04, unka08, unka0c, unka10, unka14, unka18, unka1c;
    int unka20, unka24, unka28, unka2c, unka30, unka34, unka38, unka3c;
    int unka40, unka44, unka48, unka4c, unka50, unka54, unka58, unka5c;
    int unka60, unka64, unka68, unka6c, unka70, unka74, unka78, unka7c;
    int unka80, unka84, unka88, unka8c, unka90, unka94, unka98, unka9c;
    int unkaa0, unkaa4, unkaa8, unkaac, unkab0, unkab4, unkab8, unkabc;
    int unkac0, unkac4, unkac8, unkacc, unkad0, unkad4, unkad8, unkadc;
    int unkae0, unkae4, unkae8, unkaec, unkaf0, unkaf4, unkaf8, unkafc;
    int unkb00, unkb04, unkb08, unkb0c, unkb10, unkb14, unkb18, unkb1c;
    int unkb20, unkb24, unkb28, unkb2c, unkb30, unkb34, unkb38, unkb3c;
    int unkb40, unkb44, unkb48, unkb4c, unkb50, unkb54, unkb58, unkb5c;
    int unkb60, unkb64, unkb68, unkb6c, unkb70, unkb74, unkb78, unkb7c;
    int unkb80, unkb84, unkb88, unkb8c, unkb90, unkb94, unkb98, unkb9c;
    int unkba0, unkba4, unkba8, unkbac, unkbb0, unkbb4, unkbb8, unkbbc;
    int unkbc0, unkbc4, unkbc8, unkbcc, unkbd0, unkbd4, unkbd8, unkbdc;
    int unkbe0, unkbe4, unkbe8, unkbec, unkbf0, unkbf4, unkbf8, unkbfc;
    int unkc00, unkc04, unkc08, unkc0c, unkc10, unkc14, unkc18, unkc1c;
    int unkc20, unkc24, unkc28, unkc2c, unkc30, unkc34, unkc38, unkc3c;
    int unkc40, unkc44, unkc48, unkc4c, unkc50, unkc54, unkc58, unkc5c;
    int unkc60, unkc64, unkc68, unkc6c, unkc70, unkc74, unkc78, unkc7c;
    int unkc80, unkc84, unkc88, unkc8c, unkc90, unkc94, unkc98, unkc9c;
    int unkca0, unkca4, unkca8, unkcac, unkcb0, unkcb4, unkcb8, unkcbc;
    int unkcc0, unkcc4, unkcc8, unkccc, unkcd0, unkcd4, unkcd8, unkcdc;
    int unkce0, unkce4, unkce8, unkcec, unkcf0, unkcf4, unkcf8, unkcfc;
    int unkd00, unkd04, unkd08, unkd0c, unkd10, unkd14, unkd18, unkd1c;
    int unkd20, unkd24, unkd28, unkd2c, unkd30, unkd34, unkd38, unkd3c;
    int unkd40, unkd44, unkd48, unkd4c, unkd50, unkd54, unkd58, unkd5c;
    int unkd60, unkd64, unkd68, unkd6c, unkd70, unkd74, unkd78, unkd7c;
    int unkd80, unkd84, unkd88, unkd8c, unkd90, unkd94, unkd98, unkd9c;
    int unkda0, unkda4, unkda8, unkdac, unkdb0, unkdb4, unkdb8, unkdbc;
    int unkdc0, unkdc4, unkdc8, unkdcc, unkdd0, unkdd4, unkdd8, unkddc;
    int unkde0, unkde4, unkde8, unkdec, unkdf0, unkdf4, unkdf8, unkdfc;
    int unke00, unke04, unke08, unke0c, unke10, unke14, unke18, unke1c;
    int unke20, unke24, unke28, unke2c, unke30, unke34, unke38, unke3c;
    int unke40, unke44, unke48, unke4c, unke50, unke54, unke58, unke5c;
    int unke60, unke64, unke68, unke6c, unke70, unke74, unke78, unke7c;
    int unke80, unke84, unke88, unke8c, unke90, unke94, unke98, unke9c;
    int unkea0, unkea4, unkea8, unkeac, unkeb0, unkeb4, unkeb8, unkebc;
    int unkec0, unkec4, unkec8, unkecc, unked0, unked4, unked8, unkedc;
    int unkee0, unkee4, unkee8, unkeec, unkef0, unkef4, unkef8, unkefc;
    int unkf00, unkf04, unkf08, unkf0c, unkf10, unkf14, unkf18, unkf1c;
    int unkf20, unkf24, unkf28, unkf2c, unkf30, unkf34, unkf38, unkf3c;
    int unkf40, unkf44, unkf48, unkf4c, unkf50, unkf54, unkf58, unkf5c;
    int unkf60, unkf64, unkf68, unkf6c, unkf70, unkf74, unkf78, unkf7c;
    int unkf80, unkf84, unkf88, unkf8c, unkf90, unkf94, unkf98, unkf9c;
    int unkfa0, unkfa4, unkfa8, unkfac, unkfb0, unkfb4, unkfb8, unkfbc;
    int unkfc0, unkfc4, unkfc8, unkfcc, unkfd0, unkfd4, unkfd8, unkfdc;
    int unkfe0, unkfe4, unkfe8, unkfec, unkff0, unkff4, unkff8, unkffc;
    int unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c;
    int unk1020, unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c;
    int unk1040, unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c;
    int unk1060, unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c;
    int unk1080, unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c;
    int unk10a0, unk10a4, unk10a8, unk10ac, unk10b0, unk10b4, unk10b8, unk10bc;
    int unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc;
    int unk10e0, unk10e4, unk10e8, unk10ec, unk10f0, unk10f4, unk10f8, unk10fc;
    int unk1100, unk1104, unk1108, unk110c, unk1110, unk1114, unk1118, unk111c;
    int unk1120, unk1124, unk1128, unk112c, unk1130, unk1134, unk1138, unk113c;
    int unk1140, unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c;
    int unk1160, unk1164, unk1168, unk116c, unk1170, unk1174, unk1178, unk117c;
    int unk1180, unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c;
    int unk11a0, unk11a4, unk11a8, unk11ac, unk11b0, unk11b4, unk11b8, unk11bc;
    int unk11c0, unk11c4, unk11c8, unk11cc, unk11d0, unk11d4, unk11d8, unk11dc;
    int unk11e0, unk11e4, unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc;
    int unk1200, unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c;
    int unk1220, unk1224, unk1228, unk122c, unk1230, unk1234, unk1238, unk123c;
    int unk1240, unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c;
    int unk1260, unk1264, unk1268, unk126c, unk1270, unk1274, unk1278, unk127c;
    int unk1280, unk1284, unk1288, unk128c, unk1290, unk1294, unk1298, unk129c;
    int unk12a0, unk12a4, unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc;
    int unk12c0, unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc;
    int unk12e0, unk12e4, unk12e8, unk12ec, unk12f0, unk12f4, unk12f8, unk12fc;
    int unk1300, unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c;
    int unk1320, unk1324, unk1328, unk132c, unk1330, unk1334, unk1338, unk133c;
    int unk1340, unk1344, unk1348, unk134c, unk1350, unk1354, unk1358, unk135c;
    int unk1360, unk1364, unk1368, unk136c, unk1370, unk1374, unk1378, unk137c;
    int unk1380, unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c;
    int unk13a0, unk13a4, unk13a8, unk13ac, unk13b0, unk13b4, unk13b8, unk13bc;
    int unk13c0, unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc;
    int unk13e0, unk13e4, unk13e8, unk13ec, unk13f0, unk13f4, unk13f8, unk13fc;
    int unk1400, unk1404, unk1408, unk140c, unk1410, unk1414, unk1418, unk141c;
    int unk1420, unk1424, unk1428, unk142c, unk1430, unk1434, unk1438, unk143c;
    int unk1440, unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c;
    int unk1460, unk1464, unk1468, unk146c, unk1470, unk1474, unk1478, unk147c;
    int unk1480, unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c;
    int unk14a0, unk14a4, unk14a8, unk14ac, unk14b0, unk14b4, unk14b8, unk14bc;
    int unk14c0, unk14c4, unk14c8, unk14cc, unk14d0, unk14d4, unk14d8, unk14dc;
    int unk14e0, unk14e4, unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc;
    int unk1500, unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c;
    int unk1520, unk1524, unk1528, unk152c, unk1530, unk1534, unk1538, unk153c;
    int unk1540, unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c;
    int unk1560, unk1564, unk1568, unk156c, unk1570, unk1574, unk1578, unk157c;
    int unk1580, unk1584, unk1588, unk158c, unk1590, unk1594, unk1598, unk159c;
    int unk15a0, unk15a4, unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc;
    int unk15c0, unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc;
    int unk15e0, unk15e4, unk15e8, unk15ec, unk15f0, unk15f4, unk15f8, unk15fc;
    int unk1600, unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c;
    int unk1620, unk1624, unk1628, unk162c, unk1630, unk1634, unk1638, unk163c;
    int unk1640, unk1644, unk1648, unk164c, unk1650, unk1654, unk1658, unk165c;
    int unk1660, unk1664, unk1668, unk166c, unk1670, unk1674, unk1678, unk167c;
    int unk1680, unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c;
    int unk16a0, unk16a4, unk16a8, unk16ac, unk16b0, unk16b4, unk16b8, unk16bc;
    int unk16c0, unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc;
    int unk16e0, unk16e4, unk16e8, unk16ec, unk16f0, unk16f4, unk16f8, unk16fc;
    int unk1700, unk1704, unk1708, unk170c, unk1710, unk1714, unk1718, unk171c;
    int unk1720, unk1724, unk1728, unk172c, unk1730, unk1734, unk1738, unk173c;
    int unk1740, unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c;
    int unk1760, unk1764, unk1768, unk176c, unk1770, unk1774, unk1778, unk177c;
    int unk1780, unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c;
    int unk17a0, unk17a4, unk17a8, unk17ac, unk17b0, unk17b4, unk17b8, unk17bc;
    int unk17c0, unk17c4, unk17c8, unk17cc, unk17d0, unk17d4, unk17d8, unk17dc;
    int unk17e0, unk17e4, unk17e8, unk17ec, unk17f0, unk17f4, unk17f8, unk17fc;
    int unk1800, unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c;
    int unk1820, unk1824, unk1828, unk182c, unk1830, unk1834, unk1838, unk183c;
    int unk1840, unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c;
    int unk1860, unk1864, unk1868, unk186c, unk1870, unk1874, unk1878, unk187c;
    int unk1880, unk1884, unk1888, unk188c, unk1890, unk1894, unk1898, unk189c;
    int unk18a0, unk18a4, unk18a8, unk18ac, unk18b0, unk18b4, unk18b8, unk18bc;
    int unk18c0, unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc;
    int unk18e0, unk18e4, unk18e8, unk18ec, unk18f0, unk18f4, unk18f8, unk18fc;
    int unk1900, unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c;
    int unk1920, unk1924, unk1928, unk192c, unk1930, unk1934, unk1938, unk193c;
    int unk1940, unk1944, unk1948, unk194c, unk1950, unk1954, unk1958, unk195c;
    int unk1960, unk1964, unk1968, unk196c, unk1970, unk1974, unk1978, unk197c;
    int unk1980, unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c;
    int unk19a0, unk19a4, unk19a8, unk19ac, unk19b0, unk19b4, unk19b8, unk19bc;
    int unk19c0, unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc;
    int unk19e0, unk19e4, unk19e8, unk19ec, unk19f0, unk19f4, unk19f8, unk19fc;
    int unk1a00, unk1a04, unk1a08, unk1a0c, unk1a10, unk1a14, unk1a18, unk1a1c;
    int unk1a20, unk1a24, unk1a28, unk1a2c, unk1a30, unk1a34, unk1a38, unk1a3c;
    int unk1a40, unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c;
    int unk1a60, unk1a64, unk1a68, unk1a6c, unk1a70, unk1a74, unk1a78, unk1a7c;
    int unk1a80, unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c;
    int unk1aa0, unk1aa4, unk1aa8, unk1aac, unk1ab0, unk1ab4, unk1ab8, unk1abc;
    int unk1ac0, unk1ac4, unk1ac8, unk1acc, unk1ad0, unk1ad4, unk1ad8, unk1adc;
    int unk1ae0, unk1ae4, unk1ae8, unk1aec, unk1af0, unk1af4, unk1af8, unk1afc;
    int unk1b00, unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c;
    int unk1b20, unk1b24, unk1b28, unk1b2c, unk1b30, unk1b34, unk1b38, unk1b3c;
    int unk1b40, unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c;
    int unk1b60, unk1b64, unk1b68, unk1b6c, unk1b70, unk1b74, unk1b78, unk1b7c;
    int unk1b80, unk1b84, unk1b88, unk1b8c, unk1b90, unk1b94, unk1b98, unk1b9c;
    int unk1ba0, unk1ba4, unk1ba8, unk1bac, unk1bb0, unk1bb4, unk1bb8, unk1bbc;
    int unk1bc0, unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4, unk1bd8, unk1bdc;
    int unk1be0, unk1be4, unk1be8, unk1bec, unk1bf0, unk1bf4, unk1bf8, unk1bfc;
    S_00d0d150_QualityInfo m_pCollisionQualityInfo[8];
};
struct S_00d0d150_World {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    S_00d0d150_Dispatcher* m_pDispatcher;
};
struct S_00d0d150_Collidable {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this)) + m_iOwnerOffset; }
};
struct S_00d0d150_Entity;
struct S_00d0d150_AgentNnEntry {
    int unk00;
    int unk04;
    void* m_pContactManager;
    signed char m_cAgentType;
    char unk0d;
    char unk0e;
    char unk0f;
    S_00d0d150_Collidable* m_kCollidable[2];
};
struct S_00d0d150_Properties {
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    int unk08;
    int unk0c;
    int unk10;
    S_00d0d150_Properties() { m_fAccumulatedImpulse = 0.0f; m_fImpulseLimit = 0.0f; }
};
struct S_00d0d150_ToiEvent {
    float m_uiCommandId;
    float m_fSeparation;
    char m_cEventType;
    S_00d0d150_Entity* m_kActorEntries[2];
    void* m_pContactManager;
    S_00d0d150_Properties m_kProperties;
    int m_aiContactData[7];
    int unk48;
    int unk4c;
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
};
struct S_00d0d150_ProcessCdPoint {
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
    int m_usContactPointId;
    int unk24;
    int unk28;
    int unk2c;
};
struct S_00d0d150_ToiInfo {
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
    float m_uiCommandId;
    float m_fSeparation;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S_00d0d150_Properties m_kProperties;
    int m_aiContactData[7];
};
struct S_00d0d150_CollisionOutput {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d0d150_ProcessCdPoint m_akContactPoints[256];
    S_00d0d150_ToiInfo m_fTimeOfImpact;
};
inline void* __cdecl operator new(unsigned int, void* where) throw() { return where; }
template <class T>
static __forceinline T* S_00d0d150_Array_expandByUnchecked(hkArrayBase<T>& self, int n);

template <class T>
static __forceinline T* S_00d0d150_Array_expandByUnchecked(hkArrayBase<T>& self, int n)
{
        int oldsize = self.m_iElementCount;
        self.m_iElementCount = oldsize + n;
        int numToConstruct = self.m_iElementCount - oldsize;
        T* p = self.m_data + oldsize;
        for (int i = 0; i < numToConstruct; ++i)
            new (p + i) T;
        return self.m_data + oldsize;
    }
struct S_00d0d150_ErrStream {
    int unk0;
    int unk4;
    int unk8;
    S_00d0d150_ErrStream(void* buf, int bufSize) throw();
    ~S_00d0d150_ErrStream() throw();
    S_00d0d150_ErrStream& operator<<(const char* s) throw();
};
struct S_00d0d150_Error {
    virtual void vfn0();
    virtual void vfn4();
    virtual void vfn8();
    virtual int message(int type, int id, const char* description, const char* file, int line) throw();
};
extern S_00d0d150_Error* DAT_01268360;
static __forceinline void S_00d0d150_memCpy4(void* dst, const void* src, int numWords)
{
    const int* s = static_cast<const int*>(src);
    int* d = static_cast<int*>(dst);
    for (int i = 0; i != numWords; i++)
        *(d++) = *(s++);
}
struct S_00d0d150 {
    int unk00;
    int unk04;
    int unk08;
    S_00d0d150_World* m_pOwningWorld;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    hkArrayBase<S_00d0d150_ToiEvent> m_kToiEventQueue;

    void QueueToiEvent(const S_00d0d150_CollisionOutput& result, const S_00d0d150_AgentNnEntry& entry) throw();
};
extern float DAT_0104da48;
extern double DAT_0104e138;
extern int DAT_01269200;
struct ThingVCallObject {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18(int aiA, int aiB, void* apP, void* apS);
};
struct ThingX {
    int unk00;
    int unk04;
    ThingVCallObject* m_pObject;
    unsigned char m_bKind;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    int m_iA;
    int m_iB;
};
struct ThingEntry {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iValue;
};
struct ThingP {
    unsigned char* m_pTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_iCached;

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
    ThingEntry* m_afEntries;
};
struct ThingBlock {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
};
struct ThingHead {
    void* m_pSelf;
    int unk04;
    int unk08;
    int unk0c;
    int m_iSub;
    int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
};
struct ThingFloatBlock {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    float m_fValue;
    int unk34; int unk38; int unk3c;
};
struct ThingFlagBlock {
    int m_iFlags;
    int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
};
struct ThingS {
    ThingHead m_pFirstNode;
    ThingBlock m_blk0040;
    ThingBlock m_blk0080;
    ThingBlock m_blk00C0;
    ThingBlock m_blk0100;
    ThingBlock m_blk0140;
    ThingBlock m_blk0180;
    ThingBlock m_blk01C0;
    ThingBlock m_blk0200;
    ThingBlock m_blk0240;
    ThingBlock m_blk0280;
    ThingBlock m_blk02C0;
    ThingBlock m_blk0300;
    ThingBlock m_blk0340;
    ThingBlock m_blk0380;
    ThingBlock m_blk03C0;
    ThingBlock m_blk0400;
    ThingBlock m_blk0440;
    ThingBlock m_blk0480;
    ThingBlock m_blk04C0;
    ThingBlock m_blk0500;
    ThingBlock m_blk0540;
    ThingBlock m_blk0580;
    ThingBlock m_blk05C0;
    ThingBlock m_blk0600;
    ThingBlock m_blk0640;
    ThingBlock m_blk0680;
    ThingBlock m_blk06C0;
    ThingBlock m_blk0700;
    ThingBlock m_blk0740;
    ThingBlock m_blk0780;
    ThingBlock m_blk07C0;
    ThingBlock m_blk0800;
    ThingBlock m_blk0840;
    ThingBlock m_blk0880;
    ThingBlock m_blk08C0;
    ThingBlock m_blk0900;
    ThingBlock m_blk0940;
    ThingBlock m_blk0980;
    ThingBlock m_blk09C0;
    ThingBlock m_blk0A00;
    ThingBlock m_blk0A40;
    ThingBlock m_blk0A80;
    ThingBlock m_blk0AC0;
    ThingBlock m_blk0B00;
    ThingBlock m_blk0B40;
    ThingBlock m_blk0B80;
    ThingBlock m_blk0BC0;
    ThingBlock m_blk0C00;
    ThingBlock m_blk0C40;
    ThingBlock m_blk0C80;
    ThingBlock m_blk0CC0;
    ThingBlock m_blk0D00;
    ThingBlock m_blk0D40;
    ThingBlock m_blk0D80;
    ThingBlock m_blk0DC0;
    ThingBlock m_blk0E00;
    ThingBlock m_blk0E40;
    ThingBlock m_blk0E80;
    ThingBlock m_blk0EC0;
    ThingBlock m_blk0F00;
    ThingBlock m_blk0F40;
    ThingBlock m_blk0F80;
    ThingBlock m_blk0FC0;
    ThingBlock m_blk1000;
    ThingBlock m_blk1040;
    ThingBlock m_blk1080;
    ThingBlock m_blk10C0;
    ThingBlock m_blk1100;
    ThingBlock m_blk1140;
    ThingBlock m_blk1180;
    ThingBlock m_blk11C0;
    ThingBlock m_blk1200;
    ThingBlock m_blk1240;
    ThingBlock m_blk1280;
    ThingBlock m_blk12C0;
    ThingBlock m_blk1300;
    ThingBlock m_blk1340;
    ThingBlock m_blk1380;
    ThingBlock m_blk13C0;
    ThingBlock m_blk1400;
    ThingBlock m_blk1440;
    ThingBlock m_blk1480;
    ThingBlock m_blk14C0;
    ThingBlock m_blk1500;
    ThingBlock m_blk1540;
    ThingBlock m_blk1580;
    ThingBlock m_blk15C0;
    ThingBlock m_blk1600;
    ThingBlock m_blk1640;
    ThingBlock m_blk1680;
    ThingBlock m_blk16C0;
    ThingBlock m_blk1700;
    ThingBlock m_blk1740;
    ThingBlock m_blk1780;
    ThingBlock m_blk17C0;
    ThingBlock m_blk1800;
    ThingBlock m_blk1840;
    ThingBlock m_blk1880;
    ThingBlock m_blk18C0;
    ThingBlock m_blk1900;
    ThingBlock m_blk1940;
    ThingBlock m_blk1980;
    ThingBlock m_blk19C0;
    ThingBlock m_blk1A00;
    ThingBlock m_blk1A40;
    ThingBlock m_blk1A80;
    ThingBlock m_blk1AC0;
    ThingBlock m_blk1B00;
    ThingBlock m_blk1B40;
    ThingBlock m_blk1B80;
    ThingBlock m_blk1BC0;
    ThingBlock m_blk1C00;
    ThingBlock m_blk1C40;
    ThingBlock m_blk1C80;
    ThingBlock m_blk1CC0;
    ThingBlock m_blk1D00;
    ThingBlock m_blk1D40;
    ThingBlock m_blk1D80;
    ThingBlock m_blk1DC0;
    ThingBlock m_blk1E00;
    ThingBlock m_blk1E40;
    ThingBlock m_blk1E80;
    ThingBlock m_blk1EC0;
    ThingBlock m_blk1F00;
    ThingBlock m_blk1F40;
    ThingBlock m_blk1F80;
    ThingBlock m_blk1FC0;
    ThingBlock m_blk2000;
    ThingBlock m_blk2040;
    ThingBlock m_blk2080;
    ThingBlock m_blk20C0;
    ThingBlock m_blk2100;
    ThingBlock m_blk2140;
    ThingBlock m_blk2180;
    ThingBlock m_blk21C0;
    ThingBlock m_blk2200;
    ThingBlock m_blk2240;
    ThingBlock m_blk2280;
    ThingBlock m_blk22C0;
    ThingBlock m_blk2300;
    ThingBlock m_blk2340;
    ThingBlock m_blk2380;
    ThingBlock m_blk23C0;
    ThingBlock m_blk2400;
    ThingBlock m_blk2440;
    ThingBlock m_blk2480;
    ThingBlock m_blk24C0;
    ThingBlock m_blk2500;
    ThingBlock m_blk2540;
    ThingBlock m_blk2580;
    ThingBlock m_blk25C0;
    ThingBlock m_blk2600;
    ThingBlock m_blk2640;
    ThingBlock m_blk2680;
    ThingBlock m_blk26C0;
    ThingBlock m_blk2700;
    ThingBlock m_blk2740;
    ThingBlock m_blk2780;
    ThingBlock m_blk27C0;
    ThingBlock m_blk2800;
    ThingBlock m_blk2840;
    ThingBlock m_blk2880;
    ThingBlock m_blk28C0;
    ThingBlock m_blk2900;
    ThingBlock m_blk2940;
    ThingBlock m_blk2980;
    ThingBlock m_blk29C0;
    ThingBlock m_blk2A00;
    ThingBlock m_blk2A40;
    ThingBlock m_blk2A80;
    ThingBlock m_blk2AC0;
    ThingBlock m_blk2B00;
    ThingBlock m_blk2B40;
    ThingBlock m_blk2B80;
    ThingBlock m_blk2BC0;
    ThingBlock m_blk2C00;
    ThingBlock m_blk2C40;
    ThingBlock m_blk2C80;
    ThingBlock m_blk2CC0;
    ThingBlock m_blk2D00;
    ThingBlock m_blk2D40;
    ThingBlock m_blk2D80;
    ThingBlock m_blk2DC0;
    ThingBlock m_blk2E00;
    ThingBlock m_blk2E40;
    ThingBlock m_blk2E80;
    ThingBlock m_blk2EC0;
    ThingBlock m_blk2F00;
    ThingBlock m_blk2F40;
    ThingBlock m_blk2F80;
    ThingBlock m_blk2FC0;
    ThingFloatBlock m_blk3000;
    ThingBlock m_blk3040;
    ThingFlagBlock m_blk3080;
};
struct FUN_00d0daa0_cls {
    int unk00;

    void QueueToiEvent(ThingS* apS, ThingX* apX);
    void InitAndDispatch(ThingX* apX, ThingP* apP, ThingS* apS);
};
void __cdecl hkAgentNnMachine_ProcessAgent(ThingX* apX, ThingP* apP, ThingS* apS, int aiValue);
// Stand-in for the object at ms+0x20; its member is the thiscall helper.
struct SlotObj_b2089
{
    void hkVector4_setRotatedDir(void* dst, void* src);
};
struct World_b2089
{
    int unk00;
    int unk04;
    int unk08;
    char* m_0c;     // +0x0c: base of per-entry records
    int unk10;
    int unk14;
    char* m_18;     // +0x18: vector table
};
struct EntryList_b2089
{
    void** m_pData; // +0x00
    int m_iArrayLength;   // +0x04
};
void hkVector4_setRotatedDir_ProcessEntries_00d0bf30(World_b2089* world, EntryList_b2089* pEntries);
extern float DAT_010c7948[];
struct CollisionMotion {
    int unk00, unk04;
    unsigned char type;
};
struct CollisionBody {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    CollisionMotion motion;
    hkBool hkpEntity_isFixedOrKeyframed();
};
struct CollisionManager {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int constraint;
};
struct CollisionProperties {
    float impulse, solverData;
    int unk08;
    unsigned char friction, restitution, maximumImpulse;
    unsigned char unk0f;
    int unk10;
};
struct CollisionEvent {
    float time, separatingVelocity;
    int flags;
    CollisionBody* bodyA;
    CollisionBody* bodyB;
    CollisionManager* manager;
    CollisionProperties properties;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c;
    hkVector4 position, normal;
};
struct CollisionParameters {
    float friction, restitution, maximumImpulse;
    float separatingVelocity, extraVelocity, deltaTime;
    bool limitBreached;
};
struct CollisionOutput {
    float impulse, velocityA, velocityB;
};
struct __declspec(align(16)) CollisionStateData {
    unsigned short type, count;
    int* constraint;
    CollisionProperties* properties;
    hkVector4* point;
};
struct CollisionQueue {
    CollisionBody** data;
    int size;
    int cap;
    __forceinline void add(CollisionBody* b) {
        CollisionBody** p = data + size;
        __assume(p != 0);
        *p = b;
        ++size;
    }
};
void __cdecl hkpCollision_ProcessBodyResponse(hkVector4*, float, CollisionParameters*, CollisionMotion*, CollisionMotion*, CollisionManager*, CollisionOutput*);
void __cdecl hkpWorldCallbackUtil_fireContactImpulseLimitBreached(void*, CollisionStateData*, int);
void __cdecl ProcessCollisionEvent(void* context, CollisionEvent* event, float deltaTime, CollisionQueue* queue);
// expanded integer AABB into thread-stack local arrays, add them to the 3-axis sweep, then remove duplicate pairs.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" void _mm_prefetch(char const* p, int hint);
extern unsigned long DAT_0126835c;
extern char DAT_010cc624[];
// "LtBroadPhase"
extern char DAT_010cd3e8[];
// "StGatherAabbs"
extern char DAT_010cc5fc[];
// "St3AxisSweep"
extern char DAT_010cc5f0[];
// "StRemoveDup"
extern char DAT_01076f38[];
// "lt"
struct MonitorStreamD0 {
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_capacityEnd;
};
struct TimerCommandD0 {
    const char* m_name;
    unsigned int m_uiCommandId;
    int unk08;
};
struct TimerListCommandD0 {
    const char* m_name;
    unsigned int m_uiCommandId;
    int unk08;
    const char* m_firstSub;
};
struct BoundingVolumeDataD0 {
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_ucUnknownByte;
};
struct AabbUint32D0 {
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_expansionMaxXYZ;
};
struct CollidableD0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_kBroadPhaseHandle;
    int unk28;
    int unk2c;
    BoundingVolumeDataD0 m_kBoundingVolumeData;
};
struct PairArrayD0 {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct BroadPhaseD0 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual void UpdatePairs(int** handles, AabbUint32D0* aabbs, int numObjects, PairArrayD0& newPairs, PairArrayD0& delPairs);
    int unk04;
    int unk08;
    int unk0c;
    int m_pWorldLock;
    void lockImplementation();
    void unlockImplementation();
    void lock() { if (m_pWorldLock) lockImplementation(); }
    void unlock() { if (m_pWorldLock) unlockImplementation(); }
};
struct CollisionInputD0;
struct WorldD0 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    BroadPhaseD0* m_pJobSemaphore;
    int unk5c, unk60, unk64, unk68, unk6c, unk70, unk74;
    CollisionInputD0* m_pCollisionInput;
};
static inline void UncompressExpandedAabbD0(const BoundingVolumeDataD0& in, AabbUint32D0& out)
{
    int shift = in.m_ucExpansionShift;
    unsigned int m0 = in.m_kMinimumCorner[0] - (in.m_ucExpansionMin[0] << shift);
    unsigned int m1 = in.m_kMinimumCorner[1] - (in.m_ucExpansionMin[1] << shift);
    unsigned int m2 = in.m_kMinimumCorner[2] - (in.m_ucExpansionMin[2] << shift);
    out.m_kMinimumCorner[0] = m0;
    out.m_kMinimumCorner[1] = m1;
    out.m_kMinimumCorner[2] = m2;
    unsigned int x0 = in.m_kMaximumCorner[0] + (in.m_ucExpansionMax[0] << shift);
    unsigned int x1 = in.m_kMaximumCorner[1] + (in.m_ucExpansionMax[1] << shift);
    unsigned int x2 = in.m_kMaximumCorner[2] + (in.m_ucExpansionMax[2] << shift);
    out.m_kMaximumCorner[0] = x0;
    out.m_kMaximumCorner[1] = x1;
    out.m_kMaximumCorner[2] = x2;
}
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(CollisionInputD0* input, CollidableD0** collidables, int numCollidables);
void __cdecl hkpTypedBroadPhaseDispatcher_removeDuplicates(PairArrayD0& newPairs, PairArrayD0& delPairs);
static inline void TimerBeginListD0(const char* name, const char* firstSub)
{
    MonitorStreamD0* s = (MonitorStreamD0*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd) {
        TimerListCommandD0* h = (TimerListCommandD0*)s->m_kRayEnd;
        h->m_name = name;
        h->m_firstSub = firstSub;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
static inline void TimerCommandD0Write(const char* name)
{
    MonitorStreamD0* s = (MonitorStreamD0*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd) {
        TimerCommandD0* h = (TimerCommandD0*)s->m_kRayEnd;
        h->m_name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
static inline void* AllocateStackD0(int nbytes)
{
    Manager* mem = hkMemoryRouter_getInstance();
    void* p = (void*)mem->unk00;
    mem->unk00 += (nbytes + 127) & ~127;
    return p;
}
static inline void FreeStackD0(void* p)
{
    hkMemoryRouter_getInstance()->unk00 = (int)p;
}
void __stdcall UpdateBroadPhasePairs(CollidableD0** collidables, int numCollidables, WorldD0* world, PairArrayD0& newPairs, PairArrayD0& delPairs);
// Havok-style query: collect candidate pairs from the source into a temporary array, skip entries
// below the level or already flagged (>= 8), mark unflagged owners once (callback), and append every
// accepted object to the output array.
struct HeapL {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
struct RouterL {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HeapL* m_pStreamAllocator;
    HeapL& heap() { return *m_pStreamAllocator; }
};
RouterL* GetRouterL() throw();
void ReserveMoreL(HeapL& alloc, void* arr, int elemSize) throw();
template <typename T> inline void ConstructWithCopyL(T* p, int n, const T& t) { for (int i = 0; i < n; i++) p[i] = t; }
template <class T> struct ArrL {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ArrL() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~ArrL() { _clearAndDeallocate(GetRouterL()->heap()); }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void _clearAndDeallocate(HeapL& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
    }
    void _pushBack(HeapL& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ReserveMoreL(alloc, this, sizeof(T));
        ConstructWithCopyL<T>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void AddBack(const T& t) { _pushBack(GetRouterL()->heap(), t); }
    T& operator[](int i) { return m_data[i]; }
};
struct ObjL {
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_iValueAtOffset04;
};
struct MotionL {
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40;
};
struct OwnerL {
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c, m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
    int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0, m_a4;
    unsigned short m_uiEdgeIndex;
    unsigned short m_aa;
    int m_ac, m_b0, m_b4, m_b8, m_bc, m_c0, m_c4, m_c8, m_cc, m_d0, m_d4, m_d8, m_dc, m_e0, m_e4;
    unsigned char m_type;
    unsigned char m_e9, m_ea, m_eb;
    int m_ec;
    MotionL m_pMotionState;
};
struct NodeL {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    OwnerL* getOwner() { return (OwnerL*)((char*)this + m_iOwnerOffset); }
};
struct ItemPairL {
    ObjL* m_obj;
    NodeL* m_node;
};
struct ListL {
    void Collect(ArrL<ItemPairL>* out) throw();
};
struct SrcL {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ListL m_kNode;
};
void OnFirstVisitL(void* target, float fValue, void* arg) throw();
inline bool IsSaturatedL(OwnerL* owner, unsigned char** ppFlags)
{
    return owner->m_type != 5 && (*ppFlags)[owner->m_uiEdgeIndex] >= 8;
}
inline void VisitL(OwnerL* owner, unsigned char** ppFlags, float fValue)
{
    if (owner->m_type != 5)
    {
        if ((*ppFlags)[owner->m_uiEdgeIndex] == 0)
        {
            (*ppFlags)[owner->m_uiEdgeIndex] = 1;
            MotionL* motion = &owner->m_pMotionState;
            OnFirstVisitL(&motion->m_40, fValue, motion);
        }
    }
}
void CollectUnsaturatedObjects(SrcL* pSource, int level, float fValue, unsigned char** ppFlags, ArrL<ObjL*>* out);
void __stdcall nullsub_66(int, int, int);
void __stdcall nullsub_67(int a);
struct MotionBody {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc;
    int unke0; int unke4;
    unsigned char m_type;
};
struct BodyPair {
    int unk0;
    MotionBody* m_apEntities[2];
};
struct PairOwner {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    BodyPair* m_pair;
};
struct PairEntry {
    PairOwner* m_pOwnerObject;
    int m_iWordAt04;
    int m_8;
};
struct PairEntryArray {
    PairEntry* m_data;
    int m_iElementCount;
};
template <class T> inline void SwapT(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
void PartitionMotionPairs(PairEntryArray* apEntryArray, int* apiFixedCount, int index);
extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);
// FUN_00d0ef40 v1 - Havok collide step: monitor ticks, reverse vcall loop, two ctx array loops
extern char DAT_010cc64c[];
// TtCollide
extern char DAT_010cc634[];
// TtIslandPostCollideCb
extern char DAT_010c41f8[];
// Et
extern int DAT_01269200;
struct Param { int m_00; int m_04; float m_08; float m_0c;
    void set(const Param& o) { *this = o; } };
struct Sub78 {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    Param m_50;
};
struct BodyA {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int m_cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    unsigned char m_e8; unsigned char m_e9; unsigned char m_ea; unsigned char m_eb;
    int unk0ec;
};
class VObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void vcall8(int, void*);
};
struct Elem70 {
    int m_00; int m_04; int m_08;
    BodyA* m_0c; BodyA* m_10; VObj* m_14;
    int m_18;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
};
struct BodyL {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    void* m_48; int m_4c;
};
struct Arr28 { BodyL** m_data; int m_uiItemCount; };
struct Sub1E0 {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    float m_10c; float m_110; int m_114;
    void setTimes(float scale, const Param& step) { m_10c = scale * step.m_08; m_110 = (float)m_114 * step.m_0c; }
};
struct Ctx {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    Arr28 m_aiIndexedValues;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    Sub78* m_78;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int m_8c; int m_90; int m_94; int m_98;
    unsigned char m_9c; unsigned char m_9d; unsigned char m_9e; unsigned char m_9f;
    int m_a0; int m_a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int m_198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    Param m_1d0;
    Sub1E0 m_1e0;
    int m_2f8; int m_2fc; float m_300;
    Sub1E0* solverInfo() { return &m_1e0; }
    void FUN_00c91120();
    void UpdateFields_00c91140();
};
void __cdecl hkpWorldCallbackUtil_fireIslandPostCollideCallback(Ctx*, BodyL*, Param*);
template<int Mode> static inline void TickWrite(const char* name, volatile unsigned int& t)
{
    MonitorStreamD0* s = (MonitorStreamD0*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd) {
        TimerCommandD0* h = (TimerCommandD0*)s->m_kRayEnd;
        h->m_name = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        if (Mode == 1) _ReadBarrier();
        if (Mode == 2) _WriteBarrier();
        h->m_uiCommandId = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
static inline void ReleaseCtx(Ctx* c)
{
    --c->m_94;
    if (c->m_94 != 0) return;
    if (c->m_9c != 0) return;
    if (c->m_8c) c->FUN_00c91120();
    if (c->m_a4 != 1) return;
    if (c->m_90) c->UpdateFields_00c91140();
}
struct ThisFull {
    int m_00; int m_04; int m_08;
    Ctx* m_0c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int m_28; int m_2c;
    Elem70* m_30; int m_34;
    void hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(void*, int, Ctx*, int);
    void hkpContinuousSimulation_collideIslandNarrowPhaseContinuous(BodyL*, void*);
};
union StepArg { Param* step; volatile unsigned int tick; };
void __fastcall hkpContinuousSimulation_collideInternal(ThisFull* th, void* edx_unused, StepArg arg);
struct Tmp {
    int unk00;
    int unk04;
    int unk08;
    void EnsureCapacity(void* a, int n);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void* a, int id, int z);
    int FindSlot(void* o);
    void ProcessArgument(void* a);
    void Object_DoNothing();
};
struct IFace {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int v, void* p);
};
struct Obj {
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
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char unkE8;
};
struct D0C290Entry {
    int unk00;
    int unk04;
    int unk08;
    Obj* m_0c;
    Obj* m_10;
    IFace* m_14;
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
};
class FUN_00d0c290_cls {
public:
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
    D0C290Entry* m_30;
    int m_34;
    void hkpContinuousSimulation_removeToiEventsOfEntities(int* ids, int n);
};
struct D0C290Pair { unsigned int lo, hi; };
template <int N>
static __forceinline void memCpyOneAlignedD0C2(void* dst, const void* src)
{
    int i = 0;
    do
    {
        ((D0C290Pair*)dst)[i] = ((const D0C290Pair*)src)[i];
    } while (++i < N / 8);
}
extern const char str_010cd440[];
extern const char str_010c41f8[];
struct __declspec(align(16)) S00d0c9c0_Ctx {
    void* m_pData;
    int m_iValue;
    int unk08;
    int unk0c;
    ThingBlock m_kStorage[192];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301c;
    int unk3020;
    int unk3024;
    int unk3028;
    int unk302c;
    float m_fValue;
    int unk3034;
    int unk3038;
    int unk303c;
    int unk3040;
    int unk3044;
    int unk3048;
    int unk304c;
    float m_fCoefficientA;
    float m_fB;
    int unk3058;
    int unk305c;
    int unk3060;
    int unk3064;
    int unk3068;
    int unk306c;
    int unk3070;
    int unk3074;
    int unk3078;
    int unk307c;
    int m_iFlags;
    int unk3084;
    int unk3088;
    int unk308c;
};
void __stdcall hkpContinuousSimulation_processAgentNnEntries(ThingX** apEntries, int aiCount, ThingP* apP, int aiValue, bool abAlt);
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
struct S_00d0e210_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};
struct S_00d0e210_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};
static inline void S_00d0e210_Timer(const char* name)
{
    S_00d0e210_MonitorStream* s = (S_00d0e210_MonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_pCurrentCommand) {
        S_00d0e210_TimerCommand* h = (S_00d0e210_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
struct S_00d0e210_Heap {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S_00d0e210_Router {
    char* m_stackCurrent;
    int unk04;
    int unk08;
    int unk0c;
    S_00d0e210_Heap* m_pStreamAllocator;
    S_00d0e210_Heap& heap() { return *m_pStreamAllocator; }
};
template <class T>
static __forceinline void S_00d0e210_Array_destroy(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void S_00d0e210_Array__clearAndDeallocate(hkArrayBase<T>& self, S_00d0e210_Heap& alloc) throw();

template <class T>
static __forceinline void S_00d0e210_Array_destroy(hkArrayBase<T>& self) throw()
{ S_00d0e210_Array__clearAndDeallocate(self, ((S_00d0e210_Router*)hkMemoryRouter_getInstance())->heap()); }

template <class T>
static __forceinline void S_00d0e210_Array__clearAndDeallocate(hkArrayBase<T>& self, S_00d0e210_Heap& alloc) throw()
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct S_00d0e210_ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { S_00d0e210_Array_destroy(self); }
};
template <typename T, int N>
struct S_00d0e210_Inplace : hkArray<T, S_00d0e210_ArrayPolicy> {
    T m_kStorage[N];
    S_00d0e210_Inplace() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
};
struct S_00d0e210_Island;
struct S_00d0e210_Motion { int unk00; };
struct S_00d0e210_Entity {
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
    short unk28;
    unsigned char unk2A;
    unsigned char unk2B;
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
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    S_00d0e210_Island* unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char unkE8;
    unsigned char unkE9;
    unsigned char unkEA;
    unsigned char unkEB;
    int unkEC;
    S_00d0e210_Motion unkF0;
};
typedef S_00d0e210_Inplace<S_00d0e210_Entity*, 2> S_00d0e210_PtrArray;
struct S_00d0e210_ToiEvent;
struct S_00d0e210_ContactMgr {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void removeToi(S_00d0e210_Island* island, int* props);
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void simulate(S_00d0e210_ToiEvent& event, float dt, S_00d0e210_PtrArray& entities);
};
struct S_00d0e210_Pair { int a; int b; };
struct S_00d0e210_ToiEvent {
    float m_uiCommandId;
    int unk04;
    int unk08;
    S_00d0e210_Entity* m_kActorEntries[2];
    S_00d0e210_ContactMgr* m_pContactManager;
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
    S_00d0e210_Island* island()
    {
        S_00d0e210_Entity* x = m_kActorEntries[0];
        if (x->unkE8 == 5)
            x = m_kActorEntries[1];
        return x->unkCC;
    }
    S_00d0e210_Island* islandOf()
    {
        if (m_kActorEntries[0]->unkE8 != 5)
            return m_kActorEntries[0]->unkCC;
        return m_kActorEntries[1]->unkCC;
    }
    void copyFrom(const S_00d0e210_ToiEvent& o)
    {
        const S_00d0e210_Pair* s = (const S_00d0e210_Pair*)&o;
        S_00d0e210_Pair* d = (S_00d0e210_Pair*)this;
        for (int i = 0; i != 14; i++)
            d[i] = s[i];
    }
};
struct S_00d0e210_ToiArray : hkArray<S_00d0e210_ToiEvent, S_00d0e210_ArrayPolicy> {
    void removeAt(int i) throw()
    {
        m_iElementCount--;
        if (m_iElementCount != i)
            m_data[i].copyFrom(m_data[m_iElementCount]);
    }
};
struct S_00d0e210_World {
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
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int unk98;
    unsigned char m_bBlockExecutingPendingOperations;
    unsigned char unk9D;
    unsigned char unk9E;
    unsigned char unk9F;
    int unkA0;
    int unkA4;
    void FUN_00c91120();
    void UpdateFields_00c91140();
    void lockCriticalOperations() throw() { m_iCriticalOperationsLockCount++; }
    void unlockCriticalOperations() throw()
    {
        if (--m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount != 0)
                FUN_00c91120();
            if (unkA4 == 1 && m_iQueuedOperationCount != 0)
                UpdateFields_00c91140();
        }
    }
};
struct S_00d0e210_StepInfo {
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
};
void __cdecl UpdateRotationInterpolation(float time, S_00d0e210_Motion* motion) throw();
void __cdecl hkpWorldAgentUtil_invalidateTim(S_00d0e210_Entity* entity, int arg) throw();
struct S_00d0e210_Sim {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void activate(S_00d0e210_Entity** entities, int numEntities, int arg, int* out);
    int unk04;
    int unk08;
    S_00d0e210_World* m_pOwningWorld;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S_00d0e210_ToiArray m_kToiEventQueue;
    int unk3C;
    void hkpContinuousSimulation_handleSimpleToi(S_00d0e210_StepInfo* info, S_00d0e210_ToiEvent& event, int unused, float dt) throw();
};
struct D0FE00TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};
struct D0FE00MonitorStream {
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
};
extern DWORD g_D0FE00TlsIndex;
__forceinline D0FE00MonitorStream& D0FE00GetMonitorStream()
{
    return *(D0FE00MonitorStream*)TlsGetValue(g_D0FE00TlsIndex);
}
__forceinline void D0FE00TimerBegin(const char* name)
{
    D0FE00MonitorStream& mStream = D0FE00GetMonitorStream();
    if (mStream.memoryAvailable()) {
        D0FE00TimerCommand* h = (D0FE00TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime();
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}
struct D0FE00World {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int m_postSimulationCallbacks;
};
void __cdecl hkpWorldCallbackUtil_firePostSimulationCallback(D0FE00World* world);
extern int g_D0FE00SimulationState;
extern const char g_D0FE00TimerPostSimCb[];
extern const char g_D0FE00TimerEnd[];
struct D0FE00Simulation {
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3C();
    virtual void markEntities(int value, int* list);
    int unk04;
    int unk08;
    D0FE00World* m_pOwningWorld;
    int unk10;
    float m_fElapsedSimulationTime;
    int unk18;
    int unk1C;
    float m_frameMarkerTime;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int m_entitiesToActivate;
    int m_iActorEntryCount;

    int hkpContinuousSimulation_advanceTimeInternal();
    int hkpContinuousSimulation_advanceTime();
};
struct Se4b0_Heap {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct Se4b0_Router {
    int unk00, unk04, unk08, unk0c;
    Se4b0_Heap* m_pStreamAllocator;
    Se4b0_Heap& heap() { return *m_pStreamAllocator; }
};
inline Se4b0_Router* Se4b0_router()
{
    return reinterpret_cast<Se4b0_Router*>(hkMemoryRouter_getInstance());
}
template <typename T> inline void Se4b0_construct(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++) p[i] = t;
}
template <class T>
static __forceinline void Se4b0_Arr__clearAndDeallocate(hkArrayBase<T>& self, Se4b0_Heap& alloc);

template <class T>
static __forceinline void Se4b0_Arr_AddBack(hkArrayBase<T>& self, const T& t);

template <class T>
static __forceinline void Se4b0_Arr__clearAndDeallocate(hkArrayBase<T>& self, Se4b0_Heap& alloc)
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(self.m_data, self.getCapacity() * sizeof(T));
    }

template <class T>
static __forceinline void Se4b0_Arr_AddBack(hkArrayBase<T>& self, const T& t)
{
        Manager* r = hkMemoryRouter_getInstance();
        if (self.m_iElementCount == self.getCapacity())
            ResizeAudioStream(reinterpret_cast<void*>(r->unk10), reinterpret_cast<LocalVecArray*>((&self)), sizeof(T));
        Se4b0_construct<T>(self.m_data + self.m_iElementCount, 1, t);
        self.m_iElementCount++;
    }
inline void Se4b0_freeStack(void* p)
{
    hkMemoryRouter_getInstance()->unk00 = reinterpret_cast<int>(p);
}
template <class T> struct Se4b0_LocalArr : hkArrayBase<T> {
    T* m_pStackAllocation;
    Se4b0_LocalArr(int n)
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
        Manager* m = hkMemoryRouter_getInstance();
        int p = m->unk00;
        m->unk00 = p + n * sizeof(T);
        this->m_data = reinterpret_cast<T*>(p);
        this->m_iCapacityState = 0x80000000 | 1000;
        m_pStackAllocation = reinterpret_cast<T*>(p);
    }
    void release()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        Se4b0_freeStack(m_pStackAllocation);
        this->_clearAndDeallocate(Se4b0_router()->heap());
    }
};
struct Se4b0_Body;
struct __declspec(align(16)) Se4b0_Step {
    float start, end, delta, inverse;
};
struct Se4b0_WorldView {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    Se4b0_Step step;
};
inline Se4b0_Step& Se4b0_step(World* w)
{
    return reinterpret_cast<Se4b0_WorldView*>(w)->step;
}
struct Se4b0_Constraint {
    ItemObj* item;
    unsigned int entityA;
    unsigned int entityB;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Se4b0_Body* getOther(Se4b0_Body* e)
    {
        return reinterpret_cast<Se4b0_Body*>(entityB ^ entityA ^ reinterpret_cast<unsigned int>(e));
    }
};
struct Se4b0_Instance {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    Se4b0_Constraint* internal;
};
struct Se4b0_Transform {
    float rotation00, rotation01, rotation02, rotation03;
    float rotation10, rotation11, rotation12, rotation13;
    float rotation20, rotation21, rotation22, rotation23;
    float positionX, positionY, positionZ, positionW;
};
struct Se4b0_MotionState {
    Se4b0_Transform transform;
    Se4b0_Transform swept;
};
void hkSweptTransformUtil_lerp2(const Se4b0_Transform& swept, float t, Se4b0_Transform& out);
void hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(void* arr, int lo, int hi, void* cmp);
struct Se4b0_Dispatcher {
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c();
    virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2c();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3c();
    virtual void s40(); virtual void s44();
    virtual void process(Se4b0_Body** bodies, int n, World* world, void* ctx, hkBool b);
};
struct Se4b0_Owner {
    int unk00, unk04;
    Se4b0_Dispatcher* dispatcher;
};
struct Se4b0_Body {
    int unk00, unk04;
    Se4b0_Owner* owner;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4;
    unsigned short storageIndex;
    unsigned short unkaa;
    Se4b0_Constraint* constraints;
    unsigned short numConstraints;
    unsigned short unkb2;
    Se4b0_Instance** slaves;
    int numSlaves;
    int unkbc, unkc0, unkc4, unkc8;
    void* context;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4;
    unsigned char motionType, unke9, unkea, unkeb;
    int unkec;
    Se4b0_MotionState motionState;
    Se4b0_Owner* getOwner() const { return owner; }
    void* getContext() const { return context; }
};
struct Se4b0_States {
    unsigned char* m_data;
    int m_iElementCount;
    unsigned char& operator[](int i) { return m_data[i]; }
};
inline void Se4b0_ensure(Se4b0_Body* body, float time, Se4b0_States& states)
{
    if (states[body->storageIndex] == 0) {
        states[body->storageIndex] = 1;
        Se4b0_MotionState* ms = &body->motionState;
        hkSweptTransformUtil_lerp2(ms->swept, time, ms->transform);
    }
}
__forceinline void Se4b0_visit(Se4b0_Body* body, Se4b0_Constraint* c, int level, float time,
    Se4b0_States& states, hkArrayBase<Se4b0_Body*>* outBodies, hkArrayBase<ItemObj*>* outItems)
{
    if (level <= c->item->m_1c) {
        Se4b0_Body* other = c->getOther(body);
        if (other->motionType == 5) {
            Se4b0_Arr_AddBack((*(outItems)), c->item);
        } else if (states[other->storageIndex] != 16) {
            Se4b0_Arr_AddBack((*(outItems)), c->item);
            if (states[other->storageIndex] < 2) {
                Se4b0_Arr_AddBack(*outBodies, other);
                Se4b0_ensure(other, time, states);
                states[other->storageIndex] = 2;
            }
        }
    }
}
void hkLs_toiActivateEntitiesAndCheckConstraints(World* world, int level, float time, hkArrayBase<Se4b0_Body*>* bodies, Se4b0_States* states, hkArrayBase<Se4b0_Body*>* outBodies, hkArrayBase<ItemObj*>* outItems);
// Baseline from the attributed contributor draft dated 2026-10-28.
// Current-claim official checking is required; no padding instructions are inserted.
struct S_00d0d150_Entity {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac;
    int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc;
    int unkd0;
    unsigned int m_uiUniqueId;
};
static __forceinline float& getSubStepTime(Context* ctx) {
    return reinterpret_cast<float&>(reinterpret_cast<Ctx*>(ctx)->unk0dc);
}
static __forceinline TimeStep& getContextTimeStep(Context* ctx) {
    return reinterpret_cast<TimeStep&>(reinterpret_cast<Ctx*>(ctx)->m_1d0);
}
static __forceinline void unlockContext(Context* ctx) {
    if (--ctx->depth() == 0 && !ctx->locked()) {
        if (ctx->pending())
            ctx->FUN_00c91120();
        if (ctx->mode() == 1 && ctx->otherPending())
            ctx->UpdateFields_00c91140();
    }
}
struct S00d0e9c0_StepInfo {
    TimeStep s;
    __forceinline S00d0e9c0_StepInfo(float start, float end) {
        s.start = start;
        s.end = end;
        s.delta = end - start;
        s.inverse = (s.delta == 0.0f) ? 0.0f : (1.0f / s.delta);
    }
};
struct S00d0e9c0_DwordPair { int a, b; };
static __forceinline void memCpyOneAligned112(void* dst, const void* src) {
    for (int i = 0; i < 14; i++) {
        static_cast<S00d0e9c0_DwordPair*>(dst)[i] = static_cast<const S00d0e9c0_DwordPair*>(src)[i];
    }
}
static __forceinline void removeToiEventAt(hkArrayBase<S_00d0d150_ToiEvent>& arr, int index) {
    arr.m_iElementCount--;
    if (arr.m_iElementCount != index) {
        memCpyOneAligned112(arr.m_data + index, arr.m_data + arr.m_iElementCount);
    }
}
struct S00d0e9c0_Key {
    unsigned int hi; unsigned int lo;
    __forceinline bool operator<(const S00d0e9c0_Key& o) const { return hi < o.hi || (hi == o.hi && lo < o.lo); }
};
struct S_00d0e9c0 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17(Context* ctx, S_00d0d150_ToiEvent* ev, float fStepTime, float fSubStepTime);

    int unk04;
    int unk08;
    Context* m_iValueAtOffset0C;
    int unk10;
    float m_kRayStart;
    float m_kRayEnd;
    float m_stepTime;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    hkArrayBase<S_00d0d150_ToiEvent> m_kToiEventQueue;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int m_iToiEventCount;

    int hkpContinuousSimulation_handleAllToisTill(float arg1);
    hkBool hkpContinuousSimulation_fireEarliestToiCallbacksAndCheckEnabled(S_00d0d150_ToiEvent* ev, float* fSubStepTime);
    void hkpContinuousSimulation_handleSimpleToi(Context* ctx, S_00d0d150_ToiEvent* ev, float fStepTime, float fSubStepTime);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _mm_prefetch(const char*, int);
extern unsigned long DAT_0126835c;
extern char DAT_010cc624[], DAT_010cd3e8[], DAT_010cc5fc[], DAT_010cc5f0[];
extern char DAT_010cd3d8[], DAT_010c41f8[], DAT_010cc5e4[], DAT_010cc5d8[], DAT_01076f38[];
struct ScratchSpan {
    unsigned* start;
    int count;
    unsigned capacity;
    unsigned* original;
};
void __cdecl hkpTypedBroadPhaseDispatcher_removeDuplicates(ScratchSpan*, ScratchSpan*);
struct RenderSink {
    void __thiscall DispatchPairs(unsigned*, int);
    void __thiscall hkpTypedBroadPhaseDispatcher_addPairs(unsigned*, int, void*);
};
struct Dispatcher {
    virtual void slot00(); virtual void slot04();
    virtual void slot08(); virtual void slot0c();
    virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1c();
    virtual void slot20(); virtual void slot24();
    virtual void slot28();
    virtual void Dispatch(unsigned**, unsigned*, int, ScratchSpan*, ScratchSpan*);
    unsigned unk04, unk08, unk0c;
    int enabled;
    void __thiscall hkpBroadPhase_lockImplementation();
    void __thiscall hkpBroadPhase_unlockImplementation();
};
struct Allocator {
    virtual void slot00(); virtual void slot04();
    virtual void slot08(); virtual void slot0c();
    virtual void Free(unsigned*, unsigned);
    virtual void slot14(); virtual void slot18();
    virtual void slot1c(); virtual void slot20();
    virtual bool Available(int);
};
struct S00d0d3f0_Router {
    int cur;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* alloc;
    Allocator& heap() { return *alloc; }
};
static inline S00d0d3f0_Router* S00d0d3f0_router() { return (S00d0d3f0_Router*)hkMemoryRouter_getInstance(); }
struct Region { unsigned unk00, unk04; unsigned data; };
struct RenderParams {
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    Dispatcher* dispatcher;
    unsigned unk05c;
    unsigned unk060;
    RenderSink* sink;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    World* texture;
    Region* region;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    unsigned unk1a4;
    unsigned unk1a8;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    unsigned unk1f0;
    unsigned unk1f4;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    unsigned unk2b0;
    unsigned unk2b4;
    unsigned unk2b8;
    unsigned unk2bc;
    unsigned unk2c0;
    unsigned unk2c4;
    unsigned unk2c8;
    unsigned unk2cc;
    unsigned unk2d0;
    unsigned unk2d4;
    unsigned unk2d8;
    unsigned unk2dc;
    unsigned unk2e0;
    unsigned unk2e4;
    unsigned unk2e8;
    unsigned unk2ec;
    unsigned unk2f0;
    unsigned unk2f4;
    unsigned unk2f8;
    unsigned unk2fc;
    unsigned unk300;
    unsigned unk304;
    unsigned unk308;
    unsigned unk30c;
    unsigned unk310;
    unsigned unk314;
    unsigned unk318;
    unsigned unk31c;
    unsigned unk320;
    unsigned unk324;
    unsigned unk328;
    unsigned unk32c;
    unsigned unk330;
    unsigned unk334;
    unsigned unk338;
    unsigned batchCount;
    void __thiscall EnterLock(unsigned);
    void __thiscall hkpWorld_unlockIslandForConstraintUpdate(unsigned);
};
struct CompressedBounds {
    unsigned minX, minY, minZ;
    unsigned char minMarginX, minMarginY, minMarginZ, shift;
    unsigned maxX, maxY, maxZ;
    unsigned char maxMarginX, maxMarginY, maxMarginZ, reserved;
};
struct Source {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    CompressedBounds bounds;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    unsigned unkc8;
    unsigned handle;
};
struct TraceCmd {
    const char* name;
    unsigned time0;
    unsigned time1;
    const char* category;
    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        time0=ticks;
    }
};
struct TraceState {
    unsigned unk00;
    char* cursor;
    unsigned unk08;
    char* end;
};
static __forceinline void Trace(unsigned char* event, unsigned char* category=0)
{
    TraceState* state=(TraceState*)TlsGetValue(DAT_0126835c);
    char* cursor=state->cursor;
    if (cursor<state->end) {
        TraceCmd* h=(TraceCmd*)cursor;
        h->name=(const char*)event;
        if (category) h->category=(const char*)category;
        h->setTime();
        state->cursor=cursor+(category ? 16 : 12);
    }
}
void __stdcall hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(Source** sources, int count, RenderParams* context, void* marker);
extern const char str_010cc54c[];
extern const char str_010c41f8[];
struct S00d0d8b0_Array {
    unsigned char** m_data;
    int m_iElementCount;
    int GetLogicalSize() const { return m_iElementCount; }
    unsigned char* operator[](int i) const { return m_data[i]; }
};
struct S00d0d8b0_Coll {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54;
    int m_lastSize;
    S00d0d8b0_Array m_kSectors;
    int getSectorSize(int i) const { return (i + 1 == m_kSectors.GetLogicalSize()) ? m_lastSize : 0x200; }
};
struct S00d0d8b0_Props {
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    int unk08;
    int unk0c;
    int unk10;
};
struct S00d0d8b0_Toi {
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
    float m_uiCommandId;
    float m_fSeparation;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S00d0d8b0_Props m_kProperties;
    int m_aiContactData[7];
};
struct S00d0d8b0_Out {
    S_00d0d150_ProcessCdPoint* m_firstFree;
    S00d0d8b0_Coll* m_pOwnerObject;
    int unk08;
    int unk0c;
    S_00d0d150_ProcessCdPoint m_akContactPoints[256];
    S00d0d8b0_Toi m_fTimeOfImpact;
    void* m_potential;
    S00d0d8b0_Out(S00d0d8b0_Coll* owner) : m_pOwnerObject(owner) { m_fTimeOfImpact.m_uiCommandId = 3.40282e+38f; m_fTimeOfImpact.m_kProperties.m_fAccumulatedImpulse = 0.0f; m_fTimeOfImpact.m_kProperties.m_fImpulseLimit = 0.0f; }
    void reset() { m_firstFree = &m_akContactPoints[0]; m_fTimeOfImpact.m_uiCommandId = 3.40282e+38f; m_potential = 0; }
    bool hasToi() const { return m_fTimeOfImpact.m_uiCommandId != 3.40282e+38f; }
};
struct S00d0d8b0_Obj {
    void QueueToiEvent(S00d0d8b0_Out* out, ThingX* x);
    void hkpContinuousSimulation_collideIslandNarrowPhaseContinuous(S00d0d8b0_Coll* coll, ThingP* p);
};
static __forceinline void WriteClock(const char* name) {
    MonitorStreamD0* s = (MonitorStreamD0*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd) {
        TimerCommandD0* h = (TimerCommandD0*)s->m_kRayEnd;
        h->m_name = name;
        _ReadWriteBarrier();
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        h->m_uiCommandId = ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
#include <string.h>
typedef unsigned int U32;
typedef unsigned char U8;
class BoolFlag {
    char value;
public:
    inline BoolFlag() {}
    inline BoolFlag(bool b) {value=static_cast<char>(b);}
    inline operator bool() const {return value!=0;}
    inline BoolFlag& operator=(bool b) {value=char(b);return *this;}
    inline BoolFlag operator==(bool b) const {return int(value)==int(b);}
    inline BoolFlag operator!=(bool b) const {return int(value)!=int(b);}
};
struct Heap {
    virtual void s00();virtual void s04();virtual void s08();virtual void s0c();
    virtual __declspec(nothrow) void freeBuffer(void*,int) throw();
    template<class T> inline void release(void* p,int n) {freeBuffer(p,n*sizeof(T));}
};
struct StackArena {
    char* top;
    int unk04,unk08;
    __forceinline void* take(int n) {char* p=top;top=p+n;return p;}
    __forceinline void put(void* p) {top=static_cast<char*>(p);}
};
// hkMemoryRouter::get is bound to 0x00c85750 in other units; its first three words hold the stack allocator.
inline StackArena& routerStack() {return reinterpret_cast<StackArena&>(hkMemoryRouter::getInstance().m_stack.m_next.m_storage);}
inline Heap& routerHeap() {return *reinterpret_cast<Heap*>(hkMemoryRouter::getInstance().m_heap);}
struct ArrayOps {
    static __declspec(nothrow) void __cdecl hkArrayUtil__reserve(Heap&,void*,int,int) throw();
    static __declspec(nothrow) void __cdecl ResizeAudioStream(Heap&,void*,int) throw();
    __forceinline static void GrowArray(Heap& a,void* p,int n) {ResizeAudioStream(a,p,n);}
};
template<class T> __forceinline void releaseArena(T* p) {routerStack().put(p);}
template<class T> __forceinline T* allocateArena(int n) {return static_cast<T*>(routerStack().take((n*sizeof(T)+127)&~127));}
struct SelectHeap {
    inline Heap& get(const void*) const {return routerHeap();}
};
template<class T> __forceinline void copyOne(T* dst,const T* src) {*reinterpret_cast<unsigned int*>(dst)=*reinterpret_cast<const unsigned int*>(src);}
struct ScalarTag {};
struct ObjectTag {};
template<class T> struct ElementTag {typedef ObjectTag type;};
template<class T> struct ElementTag<T*> {typedef ScalarTag type;};
template<class T> __forceinline void destroyElements(T*,int,ScalarTag) {}
template<class T> __forceinline void destroyElements(T* p,int n,ObjectTag) {for(int i=0;i<n;++i)p[i].~T();}
template<class T> __forceinline void copyElements(T* p,int n,const T& value) {for(int i=0;i<n;++i)p[i]=value;}
template<class T> __forceinline void destroyRange(T* p,int n) {destroyElements(p,n,typename ElementTag<T>::type());}
template<class T> __forceinline void assignRange(T* p,int n,const T* q) {for(int j=0;j<n;++j)p[j]=q[j];}
template<class T> class ListBase {
protected:
    T* data;
    int size;
    int flags;
protected:
    __forceinline __declspec(nothrow) ListBase(const ListBase&) throw() {}
    __forceinline ListBase& operator=(const ListBase&) {return *this;}
public:
    enum { SizeMask=0x3fffffff, Borrowed=int(0x80000000u), Signed=-1 };
    __forceinline __declspec(nothrow) ListBase() throw():data(0),size(0),flags(Borrowed) {}
    __forceinline __declspec(nothrow) ListBase(T* p,int n,int cap) throw():data(p),size(n),flags(cap|Borrowed) {}
    __forceinline int GetLogicalSize() const {return size;}
    __forceinline int getCapacity() const {return flags&SizeMask;}
    __forceinline bool isEmpty() const {return size==0;}
    __forceinline T* begin() {return data;}
    __forceinline const T* begin() const {return data;}
    __forceinline T& operator[](int i) {return data[i];}
    __forceinline const T& operator[](int i) const {return data[i];}
    __forceinline void clear() {destroyRange(data,size);size=0;}
    __forceinline void drop(Heap& a) {
        clear();
        if((flags&Borrowed)==0)a.release<T>(data,getCapacity());
        data=0;flags=Borrowed;
    }
    __forceinline void reserveWith(Heap& a,int n) {
        const int capacity=getCapacity();if(capacity<n) {int doubled=2*capacity;int requested=(n<doubled)?doubled:n;ArrayOps::hkArrayUtil__reserve(a,this,requested,sizeof(T));}
    }
    __forceinline void pushBackUnchecked(const T& value) {
        copyElements(data+size,1,value);++size;
    }
    __forceinline T* expandByUnchecked(int n) {int old=size;size=old+n;return data+old;}
    __forceinline void removeAt(int i) {--size;if(size!=i)copyOne(data+i,data+size);}
    __declspec(nothrow) void splice(Heap&,int,int,const T*,int);
    __declspec(noinline) __declspec(nothrow) void Search(Heap&,int,const T*,int) throw();
    __declspec(noinline) __declspec(nothrow) void CallWithFlag(Heap&,int,const T&) throw();

};
template<class T> __declspec(nothrow) void ListBase<T>::splice(Heap& a,int at,int erased,const T* source,int n) {
        int result=n+size-erased;
        int moving=size-at-erased;
        if(result>getCapacity())reserveWith(a,result);
        destroyRange(data+at,erased);
        memmove(data+at+n,data+at+erased,moving*sizeof(T));
        assignRange(data+at,n,source);
        size=result;
    }
template<class T> __declspec(noinline) __declspec(nothrow) void ListBase<T>::Search(Heap& a,int at,const T* source,int n) throw() {splice(a,at,0,source,n);}
template<class T> __declspec(noinline) __declspec(nothrow) void ListBase<T>::CallWithFlag(Heap& a,int at,const T& value) throw() {Search(a,at,&value,1);}
template<class T> class List : public ListBase<T> {
public:
    __forceinline __declspec(nothrow) List() throw() {}
    __forceinline __declspec(nothrow) List(T* p,int n,int cap) throw():ListBase<T>(p,n,cap) {}
    __forceinline __declspec(nothrow) ~List() throw() {ClearAndRelease();}
    __forceinline void ClearAndRelease() {this->drop(SelectHeap().get(this));}
    __forceinline void reserve(int n) {this->reserveWith(SelectHeap().get(this),n);}
    __forceinline void aiRecipeIndex(int i,const T& t) {this->CallWithFlag(SelectHeap().get(this),i,t);}
    __forceinline void aiRecipeIndex(int i,const T* p,int n) {this->Search(SelectHeap().get(this),i,p,n);}
};
template<class T,int N> class InlineList : public List<T> {
    T storage[N];
public:
    __forceinline __declspec(nothrow) InlineList(int n=0) throw():List<T>(storage,n,N) {}
    __forceinline __declspec(nothrow) ~InlineList() throw() {}
};
template<class T> class ArenaList : public List<T> {
    T* original;
public:
    __forceinline __declspec(nothrow) ArenaList(int n) throw() {
        this->data=allocateArena<T>(n);
        this->flags=n|ListBase<T>::Borrowed;
        original=this->data;
    }
    __forceinline BoolFlag wasReallocated() const {return original!=this->data;}
    __forceinline __declspec(nothrow) ~ArenaList() throw() {
        if(!wasReallocated())this->clear();
        releaseArena(original);
    }
};
struct DynamicNode;
struct SolverIsland {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44;
    List<DynamicNode*> entities;
    inline const List<DynamicNode*>& GetEntities() const {return entities;}
};
template<class E,class S> class StoredEnum {
    S storage;
public:
    inline StoredEnum() {}
    inline StoredEnum(E e):storage(S(e)) {}
    inline operator E() const {return E(storage);}
    inline void operator=(E e) {storage=S(e);}
    inline BoolFlag operator==(E e) const {return storage==S(e);}
    inline BoolFlag operator!=(E e) const {return storage!=S(e);}
};
struct Motion {
    enum MotionType { Invalid=0,Dynamic=1,Keyframed=4,Fixed=5,MOTION_KEYFRAMED=4 };
    int unk00,unk04;
    StoredEnum<MotionType,U8> type;
    U8 unk09,unk0a,unk0b;
    int unk0c;
    hkMotionState state;
    inline hkMotionState* GetMotionState() {return &state;}
    inline MotionType getType() const {return type;}
};
struct DynamicNode {
    U32 unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    U32 unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    U32 unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    U32 unk60,unk64,unk68,unk6c,unk70;
    const char* m_name;
    U32 unk78,unk7c;
    inline const char* getName() const {return m_name;}
    U32 unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4;
    unsigned short m_usStorageIndex,unkaa;
    U32 unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8;
    SolverIsland* island;
    U32 unkd0,unkd4,unkd8,unkdc;
    Motion movement;
    inline BoolFlag isFixed() const {return movement.type==Motion::Fixed;}
    inline BoolFlag isFixedOrKeyframed() const {return movement.type==Motion::Fixed || movement.type==Motion::Keyframed;}
    inline SolverIsland* GetSimulationIsland() const {return island;}
    inline Motion* getMotion() {return &movement;}
    inline Motion* getRigidMotion() {return &movement;}
};
struct ConstraintPair { int unk00;DynamicNode* bodies[2]; };
struct Constraint {
    U32 unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    ConstraintPair* pair;
    enum ConstraintPriority { PriorityZero=0,PriorityForced=5 };
    inline DynamicNode* getEntityA() const {return pair->bodies[0];}
    inline DynamicNode* getEntityB() const {return pair->bodies[1];}
};
struct Schema;
struct Accumulator;
struct SolverElement;
struct ResourceInfo;
struct TimeInterval;
struct BackupTransform;
struct ConstraintQuery;
template<class T> struct UnsignedShortArray {T* m_pRayStart;T* m_kRayEnd;T* m_pTileTemplate;T* m_pValues;};
struct Resources {
    TimeInterval* m_pStepInfo;
    ResourceInfo* m_pSolverInfo;
    ConstraintQuery* m_pConstraintQueryIn;
    Accumulator* m_pVelocityAccumulatorA;
    Accumulator* m_pVelocityAccumulatorB;
    Accumulator* m_pVelocityAccumulatorC;
    BackupTransform* m_pBodyABackup;
    BackupTransform* m_pBodyBBackup;
    UnsignedShortArray<Schema> m_akBufferStates[2];
    SolverElement* m_pBufferA;
    SolverElement* m_pBufferB;
    SolverElement* m_pBufferC;
    SolverElement* m_pBufferD;
};
struct SchemaRecord {Constraint* m_pHavokConstraint;Schema* m_pConstraintSchema;float m_fAllowedPenetrationDepth;};
struct CollisionInput {};
struct ProcessInput : CollisionInput {};
struct Scene {
    U32 unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    U32 unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    U32 unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    U32 unk60,unk64,unk68,unk6c,unk70,unk74;
    ProcessInput* input;
    inline ProcessInput* getCollisionInputRw() {return input;}
};
struct StateTable {
    unsigned char* data;
    int size;
    __forceinline unsigned char& operator[](int i) {return data[i];}
};
struct Limits {
    Constraint::ConstraintPriority priority;
    int entities,contacts,constraints,fullSteps,extraSteps;
};
struct PairEvent;
struct PairManager {
    virtual void s00();virtual void s04();virtual void s08();virtual void s0c();
    virtual void s10();virtual void s14();virtual void s18();virtual void s1c();
    virtual void s20();virtual void s24();virtual void s28();virtual void s2c();
    virtual void s30();virtual void s34();virtual void s38();virtual void s3c();
    virtual void s40();virtual void s44();
    virtual __declspec(nothrow) void confirm(PairEvent&,float,List<DynamicNode*>&) throw();
};
struct PairEvent {
    float time;
    int unk04,unk08;
    DynamicNode* bodies[2];
    PairManager* manager;
};
struct Violation { Constraint* constraint; const void* point; const void* properties; };
struct ResourceManager {
    virtual void s00();virtual void s04();virtual void s08();virtual void s0c();
    virtual __declspec(nothrow) int violations(List<Violation>&) throw();
    virtual __declspec(nothrow) int overflow() throw();
};
// hkTraceStream: the -Od lib shows hkToiPrintf at these sites; the SDK macro is if(0) hkTraceStream::GetMonitorStream().dontPrintf.
struct TraceStream {
    static TraceStream* s_instance;
    static inline TraceStream& GetMonitorStream() {return *s_instance;}
    void __cdecl dontPrintf(const char*,const char*,...);
};
__declspec(nothrow) void hkSweptTransformUtil_backStepMotionState(float,hkMotionState&) throw();
__declspec(nothrow) void hkSolveUpload() throw();
__declspec(nothrow) void hkpConstraintSolverResources_ProcessEntries_00d88670(Resources&,DynamicNode* const*,int) throw();
__declspec(nothrow) BoolFlag hkpConstraintSolverSetup_internalIsMemoryOkForNewAccumulators(Resources&,DynamicNode**,int) throw();
__declspec(nothrow) BoolFlag CheckTotalsWithinLimits(Resources&,Constraint**,int) throw();
__declspec(nothrow) void hkpConstraintSolverSetup_subSolve(Resources&,int) throw();
__declspec(nothrow) void hkpConstraintSolverSetup_internalAddJacobianSchemas(Resources&,Constraint**,int,List<SchemaRecord>&) throw();
__declspec(nothrow) void Object_ProcessEntries_00d0cb00(Resources&,ProcessInput&,List<SchemaRecord>&,int&,Constraint::ConstraintPriority,StateTable&,const List<DynamicNode*>&,List<DynamicNode*>&) throw();
__declspec(nothrow) void hkLs_toiActivateEntitiesAndCheckConstraints(ProcessInput&,Constraint::ConstraintPriority,float,const List<DynamicNode*>&,StateTable&,List<DynamicNode*>&,List<Constraint*>&) throw();
__declspec(nothrow) void hkLs_backstepAndFreezeEntireIsland(float,SolverIsland*,StateTable&,List<DynamicNode*>&) throw();
__declspec(nothrow) void hkpWorldAgentUtil_invalidateTim(DynamicNode*,const CollisionInput&) throw();
__declspec(nothrow) void hkVector4_setRotatedDir_ProcessEntries_00d0bf30(Resources&,const List<DynamicNode*>&) throw();
__declspec(nothrow) BoolFlag CollectMatchingEntries(Resources&,const List<SchemaRecord>&,ProcessInput&,List<Violation>*) throw();
__declspec(nothrow) void Object_UpdateFields_00d8aac0(const ResourceInfo&,Schema*,Accumulator*,SolverElement*) throw();
__declspec(nothrow) void hkpConstraintSolverSetup_oneStepIntegrate(const ResourceInfo&,const TimeInterval&,const Accumulator*,DynamicNode* const*,int) throw();
__declspec(nothrow) void UpdateIslandMotionStates(SolverIsland*,StateTable&,Resources&) throw();
__declspec(nothrow) void PartitionMotionPairs(List<SchemaRecord>&,int&,int) throw();
__declspec(nothrow) void hkLs_toiActivateConstraintsLinkingActivatedEntities(List<SchemaRecord>&,int&,StateTable&) throw();
// 0x00cf1510 takes the shared Havok swept transform and four-column transform in other units.
__declspec(nothrow) void hkSweptTransformUtil_lerp2(const hkSweptTransform&,float,hkTransform&) throw();
__forceinline void updateEntity(DynamicNode* node,float time) {
    hkMotionState* m=node->getMotion()->GetMotionState();
    hkSweptTransformUtil_lerp2(m->m_kSweptTransform,time,m->m_kMotionTransform);
}
__forceinline void restoreState(hkMotionState* m) {
    reinterpret_cast<hkRotation*>(m)->hkRotation_set(m->m_kSweptTransform.m_qRotation1);
    LocalM128 center=m->m_kSweptTransform.m_vCenterOfMassLocal.m_vComponents;
    LocalM128 y=_mm_mul_ps(_mm_shuffle_ps(center,center,0x55),m->m_kMotionTransform.m_row1);
    LocalM128 x=_mm_mul_ps(_mm_shuffle_ps(center,center,0),m->m_kMotionTransform.m_row0);
    LocalM128 z=_mm_mul_ps(_mm_shuffle_ps(center,center,0xaa),m->m_kMotionTransform.m_row2);
    m->m_kMotionTransform.m_row3=_mm_sub_ps(m->m_kSweptTransform.m_vCenterOfMass1.m_vComponents,_mm_add_ps(_mm_add_ps(y,x),z));
}
__declspec(noinline) __declspec(nothrow) void PartitionMotionPairs(List<SchemaRecord>& a,int& cursor,int n) throw() {
    for(int i=a.GetLogicalSize()-n;i<a.GetLogicalSize();++i) {
        Constraint* c=a[i].m_pHavokConstraint;
        if(c->getEntityA()->isFixedOrKeyframed() || c->getEntityB()->isFixedOrKeyframed()) {
            SchemaRecord tmp=a[cursor++];
            a[cursor-1]=a[i];a[i]=tmp;
        }
    }
}
// src: HAVOK_LIB 0x00d0c6d0
__declspec(noinline) __declspec(nothrow) void hkLs_toiActivateConstraintsLinkingActivatedEntities(List<SchemaRecord>& a,int& cursor,StateTable& state) throw() {
    for(int i=cursor;i<a.GetLogicalSize();++i) {
        Constraint* c=a[i].m_pHavokConstraint;
        if(state[c->getEntityA()->m_usStorageIndex]==16 && state[c->getEntityB()->m_usStorageIndex]==16) {
            SchemaRecord tmp=a[cursor++];a[cursor-1]=a[i];a[i]=tmp;
        }
    }
}
struct SolveStepData { int unk00,unk04; float delta; };
struct SolveResourcesView { SolveStepData* step; void* solver; void* query; void* accumulators; };
struct SolvePoint { hkVector4 position,normal; };
struct SolveAtoms {
    U32 unk00;
    unsigned short unk04,m_iElementCount;
    unsigned short unk08;
    U8 stride,unk0b;
    U32 unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    SolvePoint points[1];
};
struct SolveConstraintData {
    virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0c();
    virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1c();
    virtual int GetType();
    U32 unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;
    SolveAtoms* atoms;
};
struct SolveConstraint {
    U32 unk00,unk04,unk08;
    SolveConstraintData* data;
    U32 unk10,unk14,unk18;
    U8 priority;
};
struct SolveRecord { SolveConstraint* constraint; void* schema; float depth; };
struct SolveViolation { SolveConstraint* constraint; const SolvePoint* point; const void* properties; };
extern "C" __declspec(nothrow) int __cdecl hkVector4_ProcessEntries_00d9f6f0(void*,void*,void*,int,float*) throw();
extern "C" __declspec(nothrow) int __cdecl hkLs_areVelocitiesOk(float,SolveRecord*,float*,int,void*) throw();
__declspec(noinline) __declspec(nothrow) BoolFlag CollectMatchingEntries(Resources& originalResources,const List<SchemaRecord>& originalRecords,ProcessInput& scene,List<Violation>* originalViolations)
{
    void* world=&originalResources;
    void* matrices=const_cast<List<SchemaRecord>*>(&originalRecords);
    void* violations=originalViolations;
    SolveResourcesView* resources=reinterpret_cast<SolveResourcesView*>(world);
    ListBase<SolveRecord>* records=reinterpret_cast<ListBase<SolveRecord>*>(matrices);
    ListBase<SolveViolation>* rejected=reinterpret_cast<ListBase<SolveViolation>*>(violations);
    float velocities[256];
    bool satisfied=true;
    for(int i=0;i<records->GetLogicalSize();++i) {
        SolveRecord& record=records->begin()[i];
        if(record.constraint->priority!=5) continue;
        int n=hkVector4_ProcessEntries_00d9f6f0(resources->solver,record.schema,resources->accumulators,256,velocities);
        int violated=hkLs_areVelocitiesOk(resources->step->delta,&record,velocities,n,&scene);
        if(violated<0) continue;
        if(!rejected) return BoolFlag(false);
        satisfied=false;
        
        if(rejected->GetLogicalSize()==rejected->getCapacity())
            ArrayOps::GrowArray(routerHeap(),rejected,12);
        SolveViolation& entry=*rejected->expandByUnchecked(1);
        entry.constraint=record.constraint;
        if(record.constraint->data->GetType()==11) {
            SolveAtoms* atoms=record.constraint->data->atoms;
            entry.point=atoms->points+violated;
            entry.properties=reinterpret_cast<U8*>(atoms->points+atoms->m_iElementCount)+atoms->stride*static_cast<short>(violated);
        } else {
            entry.point=0;
            entry.properties=0;
        }
    }
    return BoolFlag(satisfied);
}
int hkLs_localizedSolveToi(const Limits& limits,Resources& resources,PairEvent& event,ResourceManager& callbacks,Scene* world,List<DynamicNode*>& active,StateTable& states,float timeStep) throw();
template<class T> class ScanPointer {T p;public:__forceinline ScanPointer(){} __forceinline ScanPointer(T q):p(q){} __forceinline void operator=(T q){p=q;} __forceinline operator T()const{return p;} __forceinline T const& val()const{return p;}};
// Resolve an event and remove obsolete queued events.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" LocalM128 _mm_setzero_ps();
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern int DAT_01269200;
extern float DAT_0104f498;
extern float DAT_01016248;
extern char DAT_010cd540[];
extern char DAT_010cd534[];
extern char DAT_010cd520[];
extern char DAT_010cd514[];
extern char DAT_01076f38[];
void __cdecl hkString_memSet(void* p, int v, int n);
void __cdecl hkReferencedObject_addReferences(void* data, int size, int elem);
void __cdecl hkReferencedObject_removeReferences(void* data, int size, int elem);
typedef unsigned long DWORD;
struct ProfPairRec : ProfRec_hkpcontinuoussimulation_rtm_variant {const char* m_subName;};
struct HeapObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct Node {
    int unk00; int unk04; int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
};
struct FlagIndex16 {
    unsigned short value;
    FlagIndex16(unsigned short v) : value(v) {}
    operator unsigned short() const { return value; }
};
struct FlagView {
    unsigned char* volatile data;
    const unsigned char& operator[](const FlagIndex16& index) const {
        return data[index];
    }
};
struct Owner {
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c, m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
    int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0, m_a4;
    unsigned short m_uiEdgeIndex;
    unsigned short m_aa;
    int m_ac, m_b0, m_b4, m_b8, m_bc, m_c0, m_c4, m_c8;
    Island* m_cc;
    __forceinline Island* GetSimulationIsland() const { return m_cc; }
    __forceinline hkBool isFixed() const { return motion.type==5; }
    int m_d0, m_d4, m_d8, m_dc;
    CollisionMotion motion;
    int m_ec;
};
struct EventReleaseObj;
struct Entry70 {
    float time, separatingVelocity;
    int flags;
    Owner* bodies[2];
    EventReleaseObj* m_14;
    CollisionProperties properties;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    hkVector4 position, normal;
};
struct Arr70 {
    Entry70* m_data;
    int m_iElementCount;
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline Entry70& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int);
    int unk08; int unk0c; int unk10; int unk14;
    struct PhaseObj* m_phase;
    int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44;
};
struct PhaseObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int collide(void* a, void* b, void* q);
    virtual void v10();
    virtual void v14();
    virtual void v18(void* a, void* b, void* c);
};
struct CtrObj {
    int unk00; int unk04; int unk08;
    int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90;
    int m_ref94;
    int unk98;
    unsigned char m_9c;
    unsigned char unk9d; unsigned char unk9e; unsigned char unk9f;
    int unkA0;
    int m_a4;
    void FUN_00c91120();
    void UpdateFields_00c91140();
};
struct Arg0 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74;
    void* m_78;
    __forceinline void* getInput() const { return m_78; }
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int m_1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int m_1e0;
    float hkpWorld_getCurrentPsiTime();
};
struct Elem {
    int unk00;
    int unk04;
    int m_08;
    void FUN_00c905b0();
};
struct PtrArr {
    Elem** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    Elem* m_inline[64];
    __forceinline PtrArr() : m_data(m_inline),m_iElementCount(0),m_iCapacityState(0x80000040) {}
    __forceinline int GetLogicalSize() const {return m_iElementCount;}
    __forceinline Elem** begin() {return m_data;}
    __forceinline Elem*& operator[](int i) {return m_data[i];}
    __forceinline void clear() {m_iElementCount=0;}
    __forceinline void removeAt(int i) {--m_iElementCount;if(m_iElementCount!=i)m_data[i]=m_data[m_iElementCount];}
    __forceinline void dispose() {
        HeapObj* heap=(HeapObj*)hkMemoryRouter_getInstance()->unk10;
        int cap=m_iCapacityState;
        m_iElementCount=0;
        if(cap>=0)heap->ReturnMemory(m_data,(cap&0x3fffffff)*4);
    }
};
struct EventReleaseObj {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void call20(Island* a, CollisionProperties* b);
};
struct BigObj {
    int unk00; int unk04; int unk08; int unk0c;
    hkVector4 m_v10;
    hkVector4 m_v20;
    int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; 
    float m_10c;
    float m_110;
    int m_114;
    int m_118;
    int m_11c;
    float m_120;
    int unk124, unk128, unk12c;
    void UpdateState_00d105b0(void* arg);
    void UpdateFields_00c90e60(float a, float b);
};
struct Times {
    float tA;
    float tB;
    float diff;
    float recip;
};
struct __declspec(align(16)) Obj2 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; 
    void hkpConstraintQueryIn_set(void* big, float* tA, int v);
};
struct EventQuery {
    int mode;
    int budgetA,budgetB,budgetC;
    int limitA,limitB;
    int flagsA,flagsB;
    __forceinline EventQuery() {
        budgetA=1000;budgetB=1000;budgetC=1000;
        limitA=4;limitB=4;flagsA=0;flagsB=0;mode=3;
    }
};
struct SolverState {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};
struct SolverFlagView {
    unsigned char* data;
    int debugSize;
    __forceinline SolverFlagView() {}
    __forceinline SolverFlagView(unsigned char* p,int) : data(p) {}
    __forceinline unsigned char* begin() { return data; }
    __forceinline unsigned char& operator[](int i) {return data[i];}
    __forceinline const unsigned char& operator[](int i) const {return data[i];}
};
struct ScopedFlags : SolverFlagView {
    __forceinline ScopedFlags(int n) {
        Manager* r=hkMemoryRouter_getInstance();
        unsigned char* p=(unsigned char*)r->unk00;
        r->unk00=(int)p+((n+127)&~127);
        data=p;
    }
    __forceinline void dispose() {hkMemoryRouter_getInstance()->unk00=(int)data;}
};
struct Self;
int __cdecl hkpConstraintSolverSetup_shutdownSolver(void* out);
int __cdecl InitializeConstraintSolverResources(float* f, BigObj* big, Obj2* o2, int a, int b, void* mid);
struct Self {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void notify(Elem**, int, void*, void*);
    int unk04; int unk08;
    CtrObj* m_ctr;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    Arr70 m_arr30;
    int pad7c; int pad80; int pad84; int pad88; int pad8c; int pad90; int pad94; int pad98; int pad9c; int pada0; int pada4; int pada8; int padac; int padb0; int padb4; int padb8; int padbc; int padc0; int padc4; int padc8; int padcc; int padd0; int padd4; int padd8; int paddc; int pade0; int pade4; int pade8; int padec; int padf0; int padf4; int padf8; int padfc; int pad100; int pad104; int pad108; int pad10c; int pad110; int pad114; int pad118; int pad11c; int pad120; int pad124; int pad128; int pad12c; int pad130; int pad134; int pad138; int pad13c; int pad140; int pad144; int pad148; int pad14c; int pad150; int pad154; int pad158; int pad15c; int pad160; int pad164; int pad168; int pad16c; int pad170; int pad174; int pad178; int pad17c; int pad180; int pad184; int pad188; int pad18c; int pad190; int pad194; int pad198; int pad19c; int pad1a0; int pad1a4; int pad1a8; int pad1ac; int pad1b0; int pad1b4;
    int m_1b8;
    int unkBC; int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC;
    int unkE0;
    void hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(Elem** data, int n, Arg0* a0, int z);
    __forceinline void process(Arg0*, Elem**, int, void*);
    __forceinline void release(Entry70&);
    __forceinline void scan(const Island*,const SolverFlagView&,Arr70&);
    void hkpContinuousSimulation_simulateToi(Arg0* a0, Entry70* pair, float fa, float fb);
};
static __forceinline void clockOne(const char* name) {
    hkMonitorStream& stream=*(hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if(stream.m_end.m_storage<stream.m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerCommand* command=reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.m_end.m_storage);
        command->m_commandAndMonitor=name;
        static_cast<ProfRec_hkpcontinuoussimulation_rtm_variant*>(command)->stamp();
        stream.m_end.m_storage=reinterpret_cast<char*>(command+1);
    }
}
static __forceinline void clockTwo(const char* name,const char* sub) {
    hkMonitorStream& stream=*(hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if(stream.m_end.m_storage<stream.m_capacityMinus16.m_storage) {
        ProfPairRec* command=(ProfPairRec*)stream.m_end.m_storage;
        command->m_commandAndMonitor=name;command->m_subName=sub;
        static_cast<ProfRec_hkpcontinuoussimulation_rtm_variant*>(command)->stamp();
        stream.m_end.m_storage=reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)(command+1));
    }
}
static __forceinline void copyProbe(void* destination,const void* source) {
    unsigned i=0;
    do { static_cast<__int64*>(destination)[i]=static_cast<const __int64*>(source)[i]; } while(++i<14);
}
__forceinline void Arr70::removeAt(int index) {
    --m_iElementCount;
    if(m_iElementCount!=index)copyProbe(m_data+index,m_data+m_iElementCount);
}
__forceinline void Self::release(Entry70& event) {
    Island* island=!event.bodies[0]->isFixed()?event.bodies[0]->GetSimulationIsland():event.bodies[1]->GetSimulationIsland();
    event.m_14->call20(island,&event.properties);
}
__forceinline void Self::scan(const Island* island,const SolverFlagView& flags,Arr70& events) {
    ScanPointer<Entry70*> data;
    for(int i=events.GetLogicalSize()-1;i>=0;--i) {
        data=events.m_data;
        Entry70& event=((Entry70*)data)[i];
        if((event.bodies[0]->GetSimulationIsland()==island && flags[event.bodies[0]->m_uiEdgeIndex]==16) ||
           (event.bodies[1]->GetSimulationIsland()==island && flags[event.bodies[1]->m_uiEdgeIndex]==16)) {
            release(events[i]);
            --events.m_iElementCount;
            if(events.m_iElementCount!=i){data=events.m_data;copyProbe((Entry70*)data+i,(Entry70*)data+events.m_iElementCount);}
        }
    }
}
__forceinline void Self::process(Arg0* world,Elem** data,int count,void* input) {
    if(count) {
        hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(data,count,world,0);
        if(DAT_01269200!=1)notify(data,count,input,&m_arr30.unk0c);
    }
}
static __forceinline void prepareProbe(Arg0* world,const Entry70& event,float delta,Times& step,BigObj& solver,Obj2& input) {
    step.tA=event.time;
    step.tB=world->hkpWorld_getCurrentPsiTime();
    step.diff=step.tB-step.tA;
    step.recip=1.0f/step.diff;
    solver.UpdateState_00d105b0(&world->m_1e0);
    solver.m_114=1;
    solver.m_120=1.0f;
    solver.m_118=1;
    solver.m_120=1.0f;
    solver.m_10c=delta;
    solver.m_110=1.0f/delta;
    solver.m_v10.m_vComponents=_mm_setzero_ps();
    solver.m_v20.m_vComponents=_mm_setzero_ps();
    solver.UpdateFields_00c90e60(DAT_01016248,DAT_0104f498);
    input.hkpConstraintQueryIn_set(&solver,&step.tA,world->m_1b8);
}
int __cdecl hkLs_localizedSolveToi(const EventQuery&,SolverState&,Entry70&,PhaseObj&,Arg0*,PtrArr&,SolverFlagView&,float);
struct SolveConstraint;
struct SolveSchemaInfo {SolveConstraint* constraint;void* schema;float depth;};
void __cdecl reserveSolveArray(HeapObj&,void*,int,int);
template<class T> struct SolveArray {
    T* data;int size,capacity;
    __forceinline SolveArray():data(0),size(0),capacity(0x80000000){}
    __forceinline ~SolveArray(){if(capacity>=0)((HeapObj*)hkMemoryRouter_getInstance()->unk10)->ReturnMemory(data,(capacity&0x3fffffff)*sizeof(T));}
    __forceinline int GetLogicalSize()const{return size;}
    __forceinline T* begin(){return data;}
    __forceinline T& operator[](int i){return data[i];}
    __forceinline const T& operator[](int i)const{return data[i];}
    __forceinline void clear(){size=0;}
    __forceinline void reserve(int n){if(n>(capacity&0x3fffffff))reserveSolveArray(*(HeapObj*)hkMemoryRouter_getInstance()->unk10,this,n,sizeof(T));}
    __forceinline void pushBackUnchecked(const T& v){data[size++]=v;}
    __forceinline void AddBack(const T& v){reserve(size+1);pushBackUnchecked(v);}
    __forceinline void removeAt(int i){--size;if(size!=i)data[i]=data[size];}
    __forceinline void aiRecipeIndex(int i,const T* values,int count){reserve(size+count);for(int j=size-1;j>=i;--j)data[j+count]=data[j];for(int j=0;j<count;++j)data[i+j]=values[j];size+=count;}
    __forceinline void aiRecipeIndex(int i,const T& value){aiRecipeIndex(i,&value,1);}
};
template<class T,int N> struct SolveInlineArray:SolveArray<T> {
    T storage[N];
    __forceinline SolveInlineArray(){this->data=storage;this->capacity=N|0x80000000;}
};
template<class T> struct SolveLocalArray:SolveArray<T> {
    T* allocation;
    __forceinline SolveLocalArray(int n){Manager* r=hkMemoryRouter_getInstance();allocation=(T*)r->unk00;r->unk00+=((n*sizeof(T)+127)&~127);this->data=allocation;this->capacity=n|0x80000000;}
    __forceinline ~SolveLocalArray(){if(this->data==allocation)this->clear();hkMemoryRouter_getInstance()->unk00=(int)allocation;}
};
struct SolveBufferState {void* begin;void* end;void* current;void* processed;};
struct SolveStateView {
    Times* step;BigObj* solver;Obj2* query;
    void* accumulators;void* accumulatorsEnd;void* accumulatorsCurrent;
    void* backups;void* backupsEnd;
    SolveBufferState schemas[2];
    void* temporaries;void* temporariesEnd;void* temporariesCurrent;void* temporariesProcessed;
};
struct SolveContact {
    virtual void f00();virtual void f04();virtual void f08();virtual void f0c();
    virtual void f10();virtual void f14();virtual void f18();virtual void f1c();
    virtual void f20();virtual void f24();virtual void f28();virtual void f2c();
    virtual void f30();virtual void f34();virtual void f38();virtual void f3c();
    virtual void f40();virtual void f44();
    virtual void solve(Entry70&,float,SolveArray<Owner*>&);
};
struct SolveControl {
    virtual void f00();virtual void f04();virtual void f08();virtual void f0c();
    virtual int GetViolations(SolveArray<SolveViolation>&);
    virtual int outOfMemory();
};
void __cdecl updateSolveTransform(Owner*,float);
void __cdecl projectSolveTransform(Owner*);
void __cdecl validateSolveConstraints(SolverState&,void*,SolveArray<SolveSchemaInfo>&,int&,int,SolverFlagView&,const SolveArray<Owner*>&,SolveArray<Owner*>&);
void __cdecl activateSolveEntities(void*,int,float,const SolveArray<Owner*>&,SolverFlagView&,SolveArray<Owner*>&,SolveArray<SolveConstraint*>&);
hkBool __cdecl canAddSolveBodies(SolverState&,Owner**,int);
hkBool __cdecl canAddSolveConstraints(SolverState&,SolveConstraint**,int);
void __cdecl addSolveAccumulators(SolverState&,Owner*const*,int);
void __cdecl addSolveSchemas(SolverState&,SolveConstraint**,int,SolveArray<SolveSchemaInfo>&);
void __cdecl freezeSolveIsland(float,Island*,SolverFlagView&,SolveArray<Owner*>&);
void __cdecl invalidateSolveBody(Owner*,void*);
void __cdecl activateSolveFixed(SolveArray<SolveSchemaInfo>&,int&,int);
void __cdecl activateSolveLinked(SolveArray<SolveSchemaInfo>&,int&,SolverFlagView&);
void __cdecl solveStep(SolverState&,int);
void __cdecl resetSolveAccumulators(SolverState&,const SolveArray<Owner*>&);
hkBool __cdecl validateCriticalSolve(SolverState&,const SolveArray<SolveSchemaInfo>&,void*,SolveArray<SolveViolation>*);
void __cdecl stepSolveJacobians(BigObj*,void*,void*,void*);
void __cdecl finishSolveStep(SolverState&);
void __cdecl backstepSolveBody(Owner*,float);
void __cdecl integrateSolveBodies(BigObj&,Times&,const void*,Owner*const*,int);
void __cdecl restoreSolveTransforms(Island*,SolverFlagView&,SolverState&);
// src: XBOX_PDB 0x00d0f300
__declspec(noinline) int __cdecl hkLs_localizedSolveToi(const EventQuery& query,SolverState& state,Entry70& event,PhaseObj& phase,Arg0* world,PtrArr& output,SolverFlagView& inputflags,float rotation)
{
    SolverFlagView flags(inputflags.begin(),0);
    SolveStateView& resources=(SolveStateView&)state;
    SolveArray<Owner*>& active=(SolveArray<Owner*>&)output;
    SolveControl& control=(SolveControl&)phase;
    SolveInlineArray<SolveSchemaInfo,64> constraints;
    int boundary=0;
    Island* island=!event.bodies[0]->isFixed()?event.bodies[0]->GetSimulationIsland():event.bodies[1]->GetSimulationIsland();
    SolveLocalArray<Owner*> touched(island->m_iActorEntryCount);
    if(!event.bodies[0]->isFixed()) {
        touched.pushBackUnchecked(event.bodies[0]);
        updateSolveTransform(event.bodies[0],event.time);
        flags[event.bodies[0]->m_uiEdgeIndex]=2;
    }
    if(!event.bodies[1]->isFixed()) {
        touched.pushBackUnchecked(event.bodies[1]);
        updateSolveTransform(event.bodies[1],event.time);
        flags[event.bodies[1]->m_uiEdgeIndex]=2;
    }
    SolveInlineArray<Owner*,64> pending;
    ((SolveContact*)event.m_14)->solve(event,rotation,pending);
    if(!pending.GetLogicalSize()) {
        if(!event.bodies[0]->isFixed())projectSolveTransform(event.bodies[0]);
        if(!event.bodies[1]->isFixed())projectSolveTransform(event.bodies[1]);
        return 1;
    }
    Owner* initialA=pending[0];
    Owner* initialB=pending.GetLogicalSize()>1?pending[1]:0;
    flags[initialA->m_uiEdgeIndex]=6;
    if(initialB)flags[initialB->m_uiEdgeIndex]=6;
    addSolveAccumulators(state,&touched[0],touched.GetLogicalSize());
    hkBool preset(true);
    SolveInlineArray<Owner*,64> additional;
    SolveInlineArray<SolveConstraint*,64> extraConstraints;
    for(int steps=query.limitA;steps>0;--steps) {
        for(;;) {
            extraConstraints.clear();additional.clear();
            int nextBoundary=boundary;
            if(!preset) {
                if(boundary<constraints.GetLogicalSize()) {
                    pending.clear();
                    validateSolveConstraints(state,world->getInput(),constraints,nextBoundary,query.mode,flags,touched,pending);
                    if(!pending.GetLogicalSize())break;
                }else break;
            }
            activateSolveEntities(world->getInput(),query.mode,event.time,pending,flags,additional,extraConstraints);
            preset=false;
            if(!canAddSolveBodies(state,additional.begin(),additional.GetLogicalSize()) ||
               !canAddSolveConstraints(state,extraConstraints.begin(),extraConstraints.GetLogicalSize()) ||
               query.budgetC<constraints.GetLogicalSize()+extraConstraints.GetLogicalSize() ||
               query.budgetA<active.GetLogicalSize()+touched.GetLogicalSize()+additional.GetLogicalSize() ||
               query.budgetB<active.GetLogicalSize()+pending.GetLogicalSize()) {
                for(int i=0;i<pending.GetLogicalSize();++i)flags[pending[i]->m_uiEdgeIndex]=8;
                for(int i=0;i<additional.GetLogicalSize();++i)flags[additional[i]->m_uiEdgeIndex]=1;
                int response=control.outOfMemory();
                if(response==2) {
                    freezeSolveIsland(event.time,island,flags,active);
                    for(int i=0;i<active.GetLogicalSize();++i)invalidateSolveBody(active[i],world->getInput());
                    active.clear();return 0;
                }
                break;
            }
            addSolveAccumulators(state,additional.begin(),additional.GetLogicalSize());
            addSolveSchemas(state,extraConstraints.begin(),extraConstraints.GetLogicalSize(),constraints);
            boundary=nextBoundary;
            for(int i=0;i<touched.GetLogicalSize();++i)if(flags[touched[i]->m_uiEdgeIndex]==16)touched.removeAt(i--);
            active.aiRecipeIndex(active.GetLogicalSize(),pending.begin(),pending.GetLogicalSize());
            touched.reserve(touched.GetLogicalSize()+additional.GetLogicalSize());
            for(int i=0;i<additional.GetLogicalSize();++i)if(additional[i]->motion.type!=4)touched.pushBackUnchecked(additional[i]);
            activateSolveFixed(constraints,boundary,extraConstraints.GetLogicalSize());
            activateSolveLinked(constraints,boundary,flags);
            solveStep(state,1);
            if(!extraConstraints.GetLogicalSize() && !additional.GetLogicalSize())break;
        }
        solveStep(state,0);
    }
    if(resources.schemas[1].begin!=resources.schemas[1].current) {
        resetSolveAccumulators(state,touched);
        hkBool satisfied=validateCriticalSolve(state,constraints,world->getInput(),0);
        if(!satisfied) {
            int retries=query.limitB;
            while(!satisfied && --retries>=0) {
                stepSolveJacobians(resources.solver,resources.schemas[1].begin,resources.accumulators,resources.temporaries);
                resetSolveAccumulators(state,touched);
                satisfied=validateCriticalSolve(state,constraints,world->getInput(),0);
            }
        }
        if(!satisfied) {
            SolveInlineArray<SolveViolation,32> violated;
            validateCriticalSolve(state,constraints,world->getInput(),&violated);
            int response=control.GetViolations(violated);
            if(response==2) {
                freezeSolveIsland(event.time,island,flags,active);
                for(int i=0;i<active.GetLogicalSize();++i)invalidateSolveBody(active[i],world->getInput());
                active.clear();return 0;
            }
        }
    }
    finishSolveStep(state);
    if(!active.GetLogicalSize()) {
        active.aiRecipeIndex(0,initialA);flags[active[0]->m_uiEdgeIndex]=16;
        if(initialB){active.aiRecipeIndex(1,initialB);flags[active[1]->m_uiEdgeIndex]=16;}
    }
    for(int i=0;i<active.GetLogicalSize();++i)backstepSolveBody(active[i],event.time);
    integrateSolveBodies(*resources.solver,*resources.step,resources.accumulators,active.begin(),active.GetLogicalSize());
    restoreSolveTransforms(island,flags,state);
    for(int i=0;i<active.GetLogicalSize();++i)invalidateSolveBody(active[i],world->getInput());
    return 0;
}
extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
struct AdvanceSimulation;
struct Res { DWORD unk; };
struct hkTimeSection {
    volatile DWORD* tick;
    __forceinline hkTimeSection(const char* name, volatile DWORD& ticks) throw() : tick(&ticks) {
        hkMonitorStream* b = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (b->m_end.m_storage < b->m_capacityMinus16.m_storage) {
            hkMonitorStream::TimerCommand* r = reinterpret_cast<hkMonitorStream::TimerCommand*>(b->m_end.m_storage);
            r->m_commandAndMonitor = name;
            _ReadWriteBarrier();
            *tick = (DWORD)__rdtsc();
            r->m_time0 = *tick;
            b->m_end.m_storage = reinterpret_cast<char*>(r + 1);
        }
    }
    __forceinline ~hkTimeSection() throw() {
        hkMonitorStream* b = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (b->m_end.m_storage < b->m_capacityMinus16.m_storage) {
            hkMonitorStream::TimerCommand* r = reinterpret_cast<hkMonitorStream::TimerCommand*>(b->m_end.m_storage);
            r->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            *tick = (DWORD)__rdtsc();
            r->m_time0 = *tick;
            b->m_end.m_storage = reinterpret_cast<char*>(r + 1);
        }
    }
};
struct OuterTimeSection {
    bool ordered;
    volatile DWORD* tick;
    __forceinline OuterTimeSection(const char* name, volatile DWORD& ticks) throw() : ordered(false), tick(&ticks) {
        hkMonitorStream* b = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (b->m_end.m_storage < b->m_capacityMinus16.m_storage) {
            hkMonitorStream::TimerCommand* r = reinterpret_cast<hkMonitorStream::TimerCommand*>(b->m_end.m_storage);
            r->m_commandAndMonitor = name;
            _ReadWriteBarrier();
            *tick = (DWORD)__rdtsc();
            r->m_time0 = *tick;
            b->m_end.m_storage = reinterpret_cast<char*>(r + 1);
        }
    }
    __forceinline ~OuterTimeSection() throw() {
        hkMonitorStream* b = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (b->m_end.m_storage < b->m_capacityMinus16.m_storage) {
            hkMonitorStream::TimerCommand* r = reinterpret_cast<hkMonitorStream::TimerCommand*>(b->m_end.m_storage);
            r->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            *tick = (DWORD)__rdtsc();
            r->m_time0 = *tick;
            b->m_end.m_storage = reinterpret_cast<char*>(r + 1);
        }
        if (ordered) { _ReadWriteBarrier(); }
    }
};
struct AdvanceSimulation {
    DWORD unk00,unk04,unk08,unk0C,unk10;
    float m_f14;
    DWORD unk18,unk1C,unk20,unk24;
    Res* m_p28;
    DWORD unk2C,unk30;
    DWORD m_34;
    Res* hkpSimulation_reCollideAfterStepFailure() throw();
    float GetClampedSimulationTime() throw();
    Res* hkpContinuousSimulation_handleAllToisTill(float f) throw();
    Res* hkpContinuousSimulation_advanceTimeInternal();
};
struct Holder_cls {
    unsigned char unk00[0x10];
    void* m_pAllocator;
};
struct Calc_cls {
    float Get();
};
struct ArrayRef_cls {
    int* m_pData;
    int m_iArrayLength;
    unsigned int m_iFlags;
};
struct Flags_cls {
    char* m_pBytes;
    unsigned char unk04[0xc];
    void* m_pHolder;
};
extern "C" void _ReadWriteBarrier(void);
extern "C" void __cdecl ResizeAudioStream(void* allocator, ArrayRef_cls* arr, int n);
void __cdecl hkLs_backstepAndFreezeEntireIsland(float a1, char* owner, Flags_cls* flags, ArrayRef_cls* arr);

template<class T> inline void CopyOne(T* p,int n,const T& v) { for(int j=0;j<n;++j)p[j]=v; }
struct WorkBuf {
    int unk000;
    int unk001;
    int unk002;
    int unk003;
    int unk004;
    int unk005;
    int unk006;
    int unk007;
    int unk008;
    int unk009;
    int unk010;
    int unk011;
    int unk012;
    int unk013;
    int unk014;
    int unk015;
    int unk016;
    int unk017;
    int unk018;
    int unk019;
    int unk020;
    int unk021;
    int unk022;
    int unk023;
    int unk024;
    int unk025;
    int unk026;
    int unk027;
    int unk028;
    int unk029;
    int unk030;
    int unk031;
    int unk032;
    int unk033;
    int unk034;
    int unk035;
    int unk036;
    int unk037;
    int unk038;
    int unk039;
    int unk040;
    int unk041;
    int unk042;
    int unk043;
    int unk044;
    int unk045;
    int unk046;
    int unk047;
    int unk048;
    int unk049;
    int unk050;
    int unk051;
    int unk052;
    int unk053;
    int unk054;
    int unk055;
    int unk056;
    int unk057;
    int unk058;
    int unk059;
    int unk060;
    int unk061;
    int unk062;
    int unk063;
    int unk064;
    int unk065;
    int unk066;
    int unk067;
    int unk068;
    int unk069;
    int unk070;
    int unk071;
    int unk072;
    int unk073;
    int unk074;
    int unk075;
    int unk076;
    int unk077;
    int unk078;
    int unk079;
    int unk080;
    int unk081;
    int unk082;
    int unk083;
    int unk084;
    int unk085;
    int unk086;
    int unk087;
    int unk088;
    int unk089;
    int unk090;
    int unk091;
    int unk092;
    int unk093;
    int unk094;
    int unk095;
    int unk096;
    int unk097;
    int unk098;
    int unk099;
    int unk100;
    int unk101;
    int unk102;
    int unk103;
    int unk104;
    int unk105;
    int unk106;
    int unk107;
    int unk108;
    int unk109;
    int unk110;
    int unk111;
    int unk112;
    int unk113;
    int unk114;
    int unk115;
    int unk116;
    int unk117;
    int unk118;
    int unk119;
    int unk120;
    int unk121;
    int unk122;
    int unk123;
    int unk124;
    int unk125;
    int unk126;
    int unk127;
    int unk128;
    int unk129;
    int unk130;
    int unk131;
    int unk132;
    int unk133;
    int unk134;
    int unk135;
    int unk136;
    int unk137;
    int unk138;
    int unk139;
    int unk140;
    int unk141;
    int unk142;
    int unk143;
    int unk144;
    int unk145;
    int unk146;
    int unk147;
    int unk148;
    int unk149;
    int unk150;
    int unk151;
    int unk152;
    int unk153;
    int unk154;
    int unk155;
    int unk156;
    int unk157;
    int unk158;
    int unk159;
    int unk160;
    int unk161;
    int unk162;
    int unk163;
    int unk164;
    int unk165;
    int unk166;
    int unk167;
    int unk168;
    int unk169;
    int unk170;
    int unk171;
    int unk172;
    int unk173;
    int unk174;
    int unk175;
    int unk176;
    int unk177;
    int unk178;
    int unk179;
    int unk180;
    int unk181;
    int unk182;
    int unk183;
    int unk184;
    int unk185;
    int unk186;
    int unk187;
    int unk188;
    int unk189;
    int unk190;
    int unk191;
    int unk192;
    int unk193;
    int unk194;
    int unk195;
    int unk196;
    int unk197;
    int unk198;
    int unk199;
    int unk200;
    int unk201;
    int unk202;
    int unk203;
    int unk204;
    int unk205;
    int unk206;
    int unk207;
    int unk208;
    int unk209;
    int unk210;
    int unk211;
    int unk212;
    int unk213;
    int unk214;
    int unk215;
    int unk216;
    int unk217;
    int unk218;
    int unk219;
    int unk220;
    int unk221;
    int unk222;
    int unk223;
    int unk224;
    int unk225;
    int unk226;
    int unk227;
    int unk228;
    int unk229;
    int unk230;
    int unk231;
    int unk232;
    int unk233;
    int unk234;
    int unk235;
    int unk236;
    int unk237;
    int unk238;
    int unk239;
    int unk240;
    int unk241;
    int unk242;
    int unk243;
    int unk244;
    int unk245;
    int unk246;
    int unk247;
    int unk248;
    int unk249;
    int unk250;
    int unk251;
    int unk252;
    int unk253;
    int unk254;
    int unk255;
};
extern "C" LocalM128 _mm_load_ps(const float* p);
extern "C" void _mm_store_ps(float* p, LocalM128 a);
extern "C" LocalM128 _mm_load_ss(const float* p);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
struct BodyX {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4;
    unsigned short m_a8;
};
// Constraint internal prefix: entity pointers at +4/+8, unlike include/Pair.h's two integers.
struct ConstraintEntityLink {
    int unk00;
    BodyX* m_apEntities[2];
};
struct QX {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18;
    unsigned char m_1c;
    unsigned char unk1d;
    unsigned short unk1e;
    int unk20; int unk24; int unk28; int unk2c;
    ConstraintEntityLink* m_30;
};
struct Dest {
    int unk00; int unk04; int unk08; int unk0c;
    hkVector4 m_10;
    hkVector4 m_20;
};
struct ObjX {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    int unk90; int unk94; int unk98; int unk9c;
    int unka0;
    Dest* m_a4;
    int unka8; int unkac; int unkb0; int unkb4;
    int unkb8; int unkbc; int unkc0; int unkc4;
    int unkc8; int unkcc; int unkd0; int unkd4;
    int unkd8; int unkdc; int unke0; int unke4;
    int unke8; int unkec; int unkf0; int unkf4;
    int unkf8; int unkfc; int unk100; int unk104;
    int unk108; int unk10c; int unk110; int unk114;
    int unk118; int unk11c; int unk120; int unk124;
    int unk128; int unk12c;
    hkVector4 m_130;
    hkVector4 m_140;
    float getW() const { return m_140.m_vComponents.m128_f32[3]; }
    int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c;
    int unk170; int unk174; int unk178; int unk17c;
    hkVector4 m_180;
};
struct ArrObj {
    ObjX** m_data;
    int m_iElementCount;
};
struct BodyVec {
    BodyX** m_data;
    int m_iElementCount;
    unsigned int m_cap;
};
struct FlagsX {
    unsigned char* m_data;
    int m_iElementCount;
};
static __forceinline LocalM128 SplatW(float f) { LocalM128 s = _mm_load_ss(&f); return _mm_shuffle_ps(s, s, 0); }
// Keep the raw SIMD assignment inline in this unit on the approved headers too.
inline void hkVector4::operator=(const LocalM128& value) { m_vComponents = value; }
// @fnv 0x00d0cb00
// src: GUESS 0x00d0cb00 (confidence: low)
__declspec(nothrow) void Object_ProcessEntries_00d0cb00(Resources& resources, ProcessInput& input, List<SchemaRecord>& schemaList, int& index, Constraint::ConstraintPriority priority, StateTable& states, const List<DynamicNode*>& objects, List<DynamicNode*>& outBodies) throw()
{
    SrcA* p0 = (SrcA*)&resources;
    char** p1 = (char**)&input;
    LocalVecArray* entries = (LocalVecArray*)&schemaList;
    int* idx = &index;
    int level = priority;
    FlagsX* flags = (FlagsX*)&states;
    ArrObj* objs = (ArrObj*)&objects;
    BodyVec* outVec = (BodyVec*)&outBodies;
    int sz = objs->m_iElementCount;
    Manager* mem = hkMemoryRouter_getInstance();
    int savedTop = mem->unk00;
    mem->unk00 = savedTop + ((sz * 32 + 127) & ~127);
    hkVector4* out = (hkVector4*)savedTop;
    int i = 0;
    {
        for (i = 0; i < objs->m_iElementCount; i++) {
            ObjX* o = objs->m_data[i];
            Dest* d = (Dest*)((char*)o->m_a4 + p0->m_0c);
            *out++ = d->m_10.m_vComponents;
            *out++ = d->m_20.m_vComponents;
            LocalM128 diff;
            diff = _mm_sub_ps(o->m_140.m_vComponents, o->m_130.m_vComponents);
            d->m_10 = diff;
            LocalM128 scaled;
            scaled = _mm_mul_ps(SplatW(o->getW()), diff);
            d->m_10 = scaled;
            LocalM128 scaled2;
            scaled2 = _mm_mul_ps(SplatW(o->getW()), o->m_180.m_vComponents);
            d->m_20 = scaled2;
        }
    }
    int cur = *idx;
    if (cur < entries->m_iArrayLength) {
        WorkBuf buf;
        for (; cur < entries->m_iArrayLength; cur++) {
            Entry* elem = &static_cast<Entry*>(entries->m_pData)[cur];
            QX* q = (QX*)elem->m_00;
            if (level <= (int)q->m_1c) {
                BodyX** pair = q->m_30->m_apEntities;
                unsigned char* base = flags->m_data;
                int sel = base[pair[0]->m_a8] == 0x10 ? 1 : 0;
                BodyX* body = pair[sel];
                if (base[body->m_a8] & 4) {
                    int j = (*idx)++;
                    Entry* arr = static_cast<Entry*>(entries->m_pData);
                    Entry tmp = arr[j];
                    arr[j] = arr[cur];
                    arr[cur] = tmp;
                } else {
                    int n = hkVector4_ProcessEntries_00d9f6f0(p0->m_04, elem->m_04, p0->m_0c, 0x100, &buf);
                    if (hkLs_areVelocitiesOk(p0->m_00->m_08, (FUN_00d0bd30_p*)elem, (float*)&buf, n, p1) != -1) {
                        flags->m_data[body->m_a8] |= 4;
                        Manager* m2 = hkMemoryRouter_getInstance();
                        if (outVec->m_iElementCount == (int)(outVec->m_cap & 0x3fffffff)) {
                            ResizeAudioStream((void*)m2->unk10, (LocalVecArray*)outVec, 4);
                        }
                        CopyOne(outVec->m_data + outVec->m_iElementCount,1,body);
                        outVec->m_iElementCount++;
                        int j = (*idx)++;
                        Entry* arr = static_cast<Entry*>(entries->m_pData);
                    Entry tmp = arr[j];
                        arr[j] = arr[cur];
                        arr[cur] = tmp;
                    }
                }
            }
        }
    }
    hkVector4* in = (hkVector4*)savedTop;
    int k = 0;
    {
        for (k = 0; k < objs->m_iElementCount; k++) {
            ObjX* o = objs->m_data[k];
            Dest* d = (Dest*)((char*)o->m_a4 + p0->m_0c);
            d->m_10 = in->m_vComponents;
            in++;
            d->m_20 = in->m_vComponents;
            in++;
        }
    }
    hkMemoryRouter_getInstance()->unk00 = savedTop;
}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    __if_exists(A::destroy) { A::destroy(*this); }
    __if_not_exists(A::destroy) { clearAndDeallocate(); }
}
