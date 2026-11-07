
// src/havok/animation/ragdoll/utils/hkaragdollutils_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/ragdoll/utils/hkaragdollutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/ragdoll/utils/hkaragdollutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/utils/hkaragdollutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkErrStream.h"
#include "../../../../../include/hkError.h"

extern "C"
{
    int __cdecl hkaRagdollUtils_reorderForRagdoll(void*, void*);
    int __cdecl HkaragdollutilsFpfast_ProcessEntries_00ce9db0(void*, void*);
    int __cdecl alignConstraintSpacesToChildren(void*);
}

// @fnv 0x00cea7c0
// src: HAVOK_LIB 0x00cea7c0
int __cdecl hkaRagdollUtils_reorderAndAlignForRagdoll(void* p1, void* p2, void* p3)
{
    if (hkaRagdollUtils_reorderForRagdoll(p1, p2))
        return 1;
    if (HkaragdollutilsFpfast_ProcessEntries_00ce9db0(p2, p3))
        return 1;
    if (alignConstraintSpacesToChildren(p2))
        return 1;
    return 0;
}

struct Item
{
    int unk00[11];
    int unk2c;
};
struct Container
{
    int unk00[2];
    Item** items;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct Counter
{
    int unk00[12];
    int unk30;
};
extern "C" void __cdecl AssignNodeFlags(int, int, int);
void __cdecl hkaRagdollUtils_setCollisionLayer(Container* c, int value, Counter* counter);
struct Inner
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual int getSomething();
};
struct Obj
{
    char pad0[0xc];
    Inner* inner;
};
static bool IsSupportedRagdollConstraint(Obj* obj, bool reportError) throw();
void caller(Obj* obj);
struct SpawnedAllocator
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct SpawnedGlobal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};
SpawnedGlobal* __cdecl hkMemoryRouter_getInstance() throw();
struct SpawnedObject
{
    int unk00;
    unsigned short m_size04;
    int Init(void* a, void* b, int c, void* d);
};
struct SourceRecord
{
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
    int m_i2c;
};
int __cdecl SpawnObjectFromRecord(SourceRecord* src);

#include <xmmintrin.h>
struct StringRef
{
    const char* text;
    StringRef() throw()
    {
        FUN_00cb0a60();
    }
    void FUN_00cb0a60() throw();
    void UpdateState_00cb0c10(const char*) throw();
    void UpdateState_00cb0c30(const void*) throw();
};
struct Bone
{
    StringRef name;
    bool lockTranslation;
    void Object_UpdateFields_00cb0c00() throw();
};
struct Quaternion
{
    __m128 value;
    __forceinline const __m128& getVector() const
    {
        return value;
    }
    __declspec(noinline) void setMul(const Quaternion*, const Quaternion*) throw();
};

extern unsigned int DAT_011c16bc;
extern "C" void __fastcall FUN_00ec408c(unsigned int);
// src: COMMUNITY 0x00c66320
void Quaternion::setMul(const Quaternion* first, const Quaternion* second) throw()
{
    unsigned int cookie = DAT_011c16bc;
    __m128 a = first->value;
    __m128 b = second->value;
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                              _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
    __m128 aw = _mm_shuffle_ps(a, a, 0xff);
    __m128 bw = _mm_shuffle_ps(b, b, 0xff);
    __m128 xyz = _mm_add_ps(_mm_add_ps(_mm_mul_ps(aw, b), cross), _mm_mul_ps(bw, a));
    __m128 product = _mm_mul_ps(a, b);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    __m128 scalar = _mm_sub_ps(product, _mm_shuffle_ps(sum, sum, 0));
    value = _mm_shuffle_ps(xyz, _mm_unpackhi_ps(xyz, scalar), 0xc4);
    FUN_00ec408c(cookie);
}
// hkQsTransform layout (translation, quaternion, scale; 0x00ce5070 = hkQsTransform::setFromTransform) over this unit's raw __m128/Quaternion stand-ins.
struct RagdollQsTransform
{
    __m128 translation;
    __forceinline const __m128& getTranslation() const
    {
        return translation;
    }
    Quaternion rotation;
    __m128 scale;
    __forceinline const __m128& getScale() const
    {
        return scale;
    }
    void setFromTransformNoScale(const RagdollQsTransform*) throw();
};
extern const __m128 DAT_010c71e0;
extern const __m128 DAT_010c7170;
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_010c4c00;
extern const __m128 DAT_010c4c10;
void __cdecl hkArrayUtil__reserve(SpawnedAllocator*, void*, int, int) throw();
struct SimdVector
{
    __m128 quad;
    __forceinline SimdVector()
    {}
    __forceinline SimdVector(__m128 inputValue) : quad(inputValue)
    {}
    __forceinline operator __m128() const
    {
        return quad;
    }
};
static __forceinline void composeTransforms(RagdollQsTransform& destination, const RagdollQsTransform& parent, const RagdollQsTransform& child)
{
    SimdVector qForward = parent.rotation.value;
    SimdVector wForward = _mm_shuffle_ps(qForward, qForward, 0xff);
    SimdVector vForward = child.translation;
    __m128 dotForward = _mm_mul_ps(vForward, qForward);
    __m128 dForward = _mm_add_ss(_mm_shuffle_ps(dotForward, dotForward, 0x55), dotForward);
    dForward = _mm_add_ss(_mm_shuffle_ps(dotForward, dotForward, 0xaa), dForward);
    __m128 crossForward =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(qForward, qForward, 0xc9), _mm_shuffle_ps(vForward, vForward, 0xd2)),
                   _mm_mul_ps(_mm_shuffle_ps(qForward, qForward, 0xd2), _mm_shuffle_ps(vForward, vForward, 0xc9)));
    __m128 tForward = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(wForward, wForward), DAT_010c71e0), vForward);
    crossForward = _mm_mul_ps(crossForward, wForward);
    tForward = _mm_add_ps(tForward, _mm_mul_ps(_mm_shuffle_ps(dForward, dForward, 0), qForward));
    tForward = _mm_add_ps(crossForward, tForward);
    destination.translation = _mm_add_ps(_mm_add_ps(tForward, tForward), parent.translation);
    destination.rotation.setMul(&parent.rotation, &child.rotation);
    destination.scale = _mm_mul_ps(child.scale, parent.scale);
}
template <class T> struct ArrayLocalForm
{ // local form of hkArray: 0x00ceb2c0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* data;
    int size;
    int capacity;
    ArrayLocalForm() throw() : data(0), size(0), capacity(0x80000000)
    {}
    void reserve(SpawnedAllocator* allocator, int count) throw()
    {
        int available = capacity & 0x3fffffff;
        if (available < count)
        {
            int grown = available * 2;
            if (count >= grown)
                grown = count;
            hkArrayUtil__reserve(allocator, this, grown, sizeof(T));
        }
    }
    void reserve(int count) throw()
    {
        SpawnedGlobal* holder = hkMemoryRouter_getInstance();
        reserve(holder->m_pAllocator, count);
    }
    void resize(int count) throw()
    {
        reserve(count);
        size = count;
    }
    __forceinline void SetSizeAndGrow(int count) throw();
};
static __forceinline void destroyBones(Bone* bone, int count) throw()
{
    for (int i = 0; i < count; ++i)
    {
        bone->Object_UpdateFields_00cb0c00();
        ++bone;
    }
}
static __forceinline void constructBones(Bone* bone, int count) throw()
{
    for (int i = 0; i < count; ++i, ++bone)
    {
        if (bone)
        {
            bone->name.FUN_00cb0a60();
            bone->lockTranslation = false;
        }
    }
}
template <> __forceinline void ArrayLocalForm<Bone>::SetSizeAndGrow(int count) throw()
{
    reserve(count);
    destroyBones(data + count, size - count);
    constructBones(data + size, count - size);
    size = count;
}
extern unsigned int DAT_010c4dec;
struct SkeletonHeader
{
    const void* vtable;
    unsigned short memorySize;
    unsigned short references;
    __forceinline SkeletonHeader() throw() : references(1), memorySize(0x48)
    {
        vtable = &DAT_010c4dec;
    }
};
struct Skeleton : SkeletonHeader
{
    StringRef name;
    ArrayLocalForm<short> parents;
    ArrayLocalForm<Bone> bones;
    ArrayLocalForm<RagdollQsTransform> pose;
    ArrayLocalForm<StringRef> floatSlots;
    ArrayLocalForm<int> localFrames;
    __forceinline Skeleton() throw()
    {}
    __forceinline void* operator new(unsigned int bytes)
    {
        SpawnedGlobal* holder = hkMemoryRouter_getInstance();
        SpawnedAllocator* allocator = holder->m_pAllocator;
        Skeleton* result = static_cast<Skeleton*>(allocator->allocate(bytes));
        result->memorySize = static_cast<unsigned short>(bytes);
        return result;
    }
};
struct RigidBody
{
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
    const char* name;
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    RagdollQsTransform transform;
};
struct BodyList
{
    RigidBody** data;
    int size;
    int capacity;
};
struct Constraint
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    RigidBody* parent;
};
struct ConstraintList
{
    Constraint** data;
    int size;
    int capacity;
};

// @fnv 0x00ceb2c0
// src: COMMUNITY 0x00ceb2c0
Skeleton* __cdecl hkaRagdollUtils_constructSkeletonForRagdoll(BodyList* bodies, ConstraintList* constraints) throw()
{
    Skeleton* result = new Skeleton;
    int count = bodies->size;
    result->bones.SetSizeAndGrow(count);
    result->parents.resize(count);
    result->pose.resize(count);
    for (int i = 0; i < count; ++i)
    {
        int parentIndex = -1;
        if (i)
        {
            RigidBody* parent = constraints->data[i - 1]->parent;
            for (int j = 0; j < i; ++j)
            {
                if (bodies->data[j] == parent)
                {
                    parentIndex = j;
                    break;
                }
            }
        }
        result->parents.data[i] = (short)parentIndex;
        RigidBody* body = bodies->data[i];
        Bone& currentBone = result->bones.data[i];
        if (parentIndex >= 0)
        {
            RigidBody* parent = bodies->data[parentIndex];
            RagdollQsTransform childPose, parentPose;
            childPose.setFromTransformNoScale(&body->transform);
            parentPose.setFromTransformNoScale(&parent->transform);
            RagdollQsTransform& output = result->pose.data[i];
            const __m128& q = parentPose.rotation.value;
            SimdVector w = _mm_shuffle_ps(q, q, 0xff);
            SimdVector v = parentPose.getTranslation();
            SimdVector dot = _mm_mul_ps(q, v);
            SimdVector d = _mm_add_ss(_mm_shuffle_ps(dot, dot, 0x55), dot);
            d = _mm_add_ss(_mm_shuffle_ps(dot, dot, 0xaa), d);
            __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)),
                                      _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9)));
            cross = _mm_mul_ps(cross, w);
            SimdVector t = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
            t = _mm_add_ps(t, _mm_mul_ps(_mm_shuffle_ps(d, d, 0), q));
            t = _mm_add_ps(cross, t);
            RagdollQsTransform inversePose;
            t = _mm_add_ps(t, t);
            t = _mm_xor_ps(t, DAT_010c44d0);
            inversePose.translation = t;
            inversePose.rotation.value = _mm_xor_ps(q, DAT_010c4c00);
            __m128 scale = parentPose.scale;
            __m128 scaleWithOne = _mm_shuffle_ps(scale, _mm_unpackhi_ps(scale, DAT_010c7170), 0xc4);
            __m128 reciprocal = _mm_rcp_ps(scaleWithOne);
            __m128 inverseScale = _mm_and_ps(_mm_sub_ps(_mm_add_ps(reciprocal, reciprocal),
                                                        _mm_mul_ps(_mm_mul_ps(reciprocal, scaleWithOne), reciprocal)),
                                             DAT_010c4c10);
            inversePose.scale = inverseScale;
            composeTransforms(output, inversePose, childPose);
        }
        else
        {
            result->pose.data[i].setFromTransformNoScale(&body->transform);
        }
        const char* name = reinterpret_cast<const char*>(reinterpret_cast<unsigned int>(body->name) & ~1u);
        if (name)
            currentBone.name.UpdateState_00cb0c10(name);
        else
        {
            int buffer[128];
            hkErrStream stream(buffer, 512);
            stream << "Rigid Body name could not be found";
            hkError::s_instance->message(1, 0xabbacc14, reinterpret_cast<const char*>(buffer), ".\\Utils\\hkaRagdollUtils.cpp",
                                  558);
        }
        currentBone.lockTranslation = i != 0;
    }
    if (result->bones.size > 0)
        result->name.UpdateState_00cb0c30(result->bones.data);
    return result;
}
