
// src/unmapped/debugtextparticlesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/debug/debugtextpages/debugtextparticlesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/hkMemoryRouter.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkAabb.h"
#define HKSTRINGPTR_THROWING_DEFAULT_CONSTRUCTOR
#include "../../include/hkStringPtr.h"
#include "../../include/hkaSkeleton.h"

extern "C" void* g_012682bc;

// @fnv 0x00ca34b0
// src: COMMUNITY 0x00ca34b0
void* __cdecl hkPackedNiTriStripsData_GetRTTI()
{
    return &g_012682bc;
}

extern int DAT_0102e388;
extern int DAT_010c6fb0;

// @fnv 0x00ca3560
// src: GUESS 0x00ca3560 (confidence: low)
void __fastcall Object_UpdateFields_00ca3560(int** self, int)
{
    self[4] = &DAT_010c6fb0;
    self[0] = &DAT_0102e388;
}

class CA34C0Object
{
  public:
    static void* __cdecl operator new(unsigned int size);
    static void __cdecl operator delete(void* p);

    CA34C0Object();
    virtual ~CA34C0Object();

    int m_iObjectReferenceCount;
};

class CA34C0Base : public CA34C0Object
{
  public:
    CA34C0Base() : m_flags(0)
    {}

    int unk08;
    int unk0C;
    unsigned short m_flags;
};

class CA34C0Derived : public CA34C0Base
{
  public:
    CA34C0Derived()
    {
        unk08 = 0;
        unk0C = 0;
        unk14 = 0;
        unk18 = 0;
        unk20 = 0;
        unk24 = 0;
    }

    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

// Allocates and constructs a new CA34C0Derived object, returning it as a CA34C0Object pointer.
// @fnv 0x00ca34c0
CA34C0Object* __cdecl CreateCA34C0Derived()
{
    return new CA34C0Derived;
}

// @fnv 0x00ca3550
// src: COMMUNITY 0x00ca3550
int __cdecl hkPackedNiTriStripsShape_getType()
{
    return 0x17;
}

struct Allocator
{
    void MemoryManager_Deallocate(void* p);
};
extern Allocator DAT_011f6238;
struct Special
{
    void FUN_00ca2140();
    Special* FUN_00ca2aa0(unsigned int flags);
};
// Calls FUN_00ca2140, then if flags bit 0 is set and this is non-null, frees the block at this minus the byte stored before it, and returns this.
// @fnv 0x00ca2aa0
Special* Special::FUN_00ca2aa0(unsigned int flags)
{
    FUN_00ca2140();
    if ((flags & 1) && this)
    {
        unsigned char shift = *((unsigned char*)this - 1);
        DAT_011f6238.MemoryManager_Deallocate((char*)this - shift);
    }
    return this;
}

#include <xmmintrin.h>
#include <string.h>
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
inline void __cdecl operator delete(void*, void*)
{}
struct MemoryAllocator
{
    virtual void ReportDiagnostic();
    virtual void* allocate(int bytes);
    virtual void unused2();
    virtual void* allocateBuffer(int& bytes);
    virtual void freeBuffer(void* buffer, int bytes);
};
extern "C" hkMemoryRouter& hkMemoryRouter_getInstance();
extern "C" void __cdecl hkArrayUtil__reserve(MemoryAllocator*, void*, int, int);
const char* __cdecl hkString_strDup_00cb1410(const char*);
extern "C" void FUN_00ec8d5f(char*, unsigned int, const char*, unsigned int);
inline hkStringPtr::~hkStringPtr() throw()
{
    Object_UpdateFields_00cb0c00();
}

struct HavokBool
{
    char value;
    HavokBool(bool b) : value(b)
    {}
    void operator=(bool b)
    {
        value = b;
    }
    operator bool() const
    {
        return value != 0;
    }
};
struct BoneName : hkStringPtr
{
    using hkStringPtr::operator=;
    HavokBool locked;
    BoneName() : hkStringPtr(), locked(false)
    {}
};
extern const char DAT_010c7384[];
extern const char DAT_010c7338[];
extern const char DAT_010c732c[];
extern const char DAT_010c30bc[];
extern const __m128 DAT_010c71e0;
extern const __m128 DAT_010c7170;
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_010c4c00;
extern const __m128 DAT_010c4c10;
extern const __m128 DAT_010c71b0;
extern const float DAT_01012068;
extern void* DAT_010c4dec;
struct SimdScalar
{
    __m128 value;
    __forceinline SimdScalar(const __m128& x) : value(x)
    {}
    __forceinline SimdScalar(float x)
    {
        value = _mm_load_ps1(&x);
    }
    __forceinline operator float() const
    {
        float x;
        _mm_store_ss(&x, value);
        return x;
    }
    __forceinline __m128 broadcast() const
    {
        return value;
    }
};
struct Rotation;
struct ShapeVector
{
    __m128 value;
    __forceinline ShapeVector()
    {}
    __forceinline ShapeVector(const __m128& x) : value(x)
    {}
    __forceinline ShapeVector(const ShapeVector& x) : value(x.value)
    {}
    __forceinline void operator=(const ShapeVector& x)
    {
        value = x.value;
    }
    __forceinline void setAdd(const ShapeVector& a, const ShapeVector& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    __forceinline void add4(const ShapeVector& x)
    {
        value = _mm_add_ps(value, x.value);
    }
    __forceinline void setSub(const ShapeVector& a, const ShapeVector& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void SetProduct(const ShapeVector& a, const ShapeVector& b)
    {
        value = _mm_mul_ps(a.value, b.value);
    }
    __forceinline void addMul(const ShapeVector& a, const ShapeVector& b)
    {
        value = _mm_add_ps(value, _mm_mul_ps(a.value, b.value));
    }
    __forceinline void setAddMul(const ShapeVector& a, const ShapeVector& b, const ShapeVector& c)
    {
        value = _mm_add_ps(a.value, _mm_mul_ps(b.value, c.value));
    }
    __forceinline void broadcast(int i)
    {
        value = _mm_shuffle_ps(value, value, 0);
    }
    __forceinline void setBroadcast3(const ShapeVector& a)
    {
        value = _mm_shuffle_ps(a.value, a.value, 255);
    }
    __forceinline SimdScalar dot3(const ShapeVector& a) const
    {
        __m128 product = _mm_mul_ps(value, a.value);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(product, product, 85), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 170), xySum);
    }
    __forceinline void setCross(const ShapeVector& a, const ShapeVector& b)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 201), _mm_shuffle_ps(b.value, b.value, 210));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 210), _mm_shuffle_ps(b.value, b.value, 201));
        value = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setRotated(const Rotation& q, const ShapeVector& direction, bool inverse);
    __forceinline SimdScalar length4() const
    {
        __m128 square = _mm_mul_ps(value, value);
        __m128 sum = _mm_add_ps(_mm_shuffle_ps(square, square, 78), square);
        __m128 other = _mm_shuffle_ps(sum, sum, 177);
        return _mm_sqrt_ss(_mm_add_ps(sum, other));
    }
    __forceinline void normalize3()
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        __m128 length = dot3(*this).value;
        __m128 equal = _mm_cmpeq_ss(length, zero);
        __m128 approx = _mm_rsqrt_ss(length);
        __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(length, approx), approx)));
        __m128 inverse = _mm_andnot_ps(equal, refined);
        inverse = _mm_shuffle_ps(inverse, inverse, 0);
        value = _mm_mul_ps(inverse, value);
    }
    __forceinline void mul4(const SimdScalar& scale)
    {
        value = _mm_mul_ps(scale.broadcast(), value);
    }
};
struct Rotation
{
    ShapeVector value;
    void setMul(const Rotation*, const Rotation*);
    __forceinline void operator=(const __m128& q)
    {
        value.value = q;
    }
};
// src: COMMUNITY 0x00c66320
__declspec(noinline) void Rotation::setMul(const Rotation* left, const Rotation* right)
{
    const __m128 a = left->value.value;
    const __m128 b = right->value.value;
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(b, b, 201), _mm_shuffle_ps(a, a, 210));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(b, b, 210), _mm_shuffle_ps(a, a, 201));
    __m128 cross = _mm_sub_ps(cross1, cross0);
    __m128 aw = _mm_shuffle_ps(a, a, 255);
    aw = _mm_shuffle_ps(aw, aw, 0);
    __m128 sum = _mm_add_ps(_mm_mul_ps(aw, b), cross);
    __m128 bw = _mm_shuffle_ps(b, b, 255);
    bw = _mm_shuffle_ps(bw, bw, 0);
    sum = _mm_add_ps(_mm_mul_ps(bw, a), sum);
    __m128 product = _mm_mul_ps(a, b);
    __m128 xySum = _mm_add_ss(_mm_shuffle_ps(product, product, 85), product);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 170), xySum);
    dot = _mm_shuffle_ps(dot, dot, 0);
    __m128 real = _mm_sub_ps(product, dot);
    value.value = _mm_shuffle_ps(sum, _mm_unpackhi_ps(sum, real), 196);
}
__forceinline void ShapeVector::setRotated(const Rotation& quaternion, const ShapeVector& direction, bool inverse)
{
    const ShapeVector& q = quaternion.value;
    ShapeVector minusHalf(DAT_010c71e0);
    ShapeVector qreal;
    qreal.setBroadcast3(q);
    ShapeVector q2minus1;
    q2minus1.setAddMul(minusHalf, qreal, qreal);
    ShapeVector result;
    result.SetProduct(direction, q2minus1);
    ShapeVector dot(q.dot3(direction).value);
    dot.broadcast(0);
    result.addMul(dot, q);
    ShapeVector cross;
    if (inverse)
        cross.setCross(direction, q);
    else
        cross.setCross(q, direction);
    result.addMul(qreal, cross);
    setAdd(result, result);
}
// hkQsTransform (0x00ce5070 = hkQsTransform::setFromTransform; reference pose element) over this unit's ShapeVector/Rotation stand-ins.
struct SkeletonQsTransform
{
    ShapeVector translation;
    Rotation rotation;
    ShapeVector scale;
    void setFromTransformNoScale(const SkeletonQsTransform*);
    __forceinline void setIdentity()
    {
        translation.value = _mm_setzero_ps();
        rotation.value.value = DAT_010c71b0;
        scale.value = _mm_load1_ps(&DAT_01012068);
    }
    __forceinline void SetConjugate(const SkeletonQsTransform& source)
    {
        translation.setRotated(source.rotation, source.translation, true);
        translation.value = _mm_xor_ps(translation.value, DAT_010c44d0);
        rotation.value.value = _mm_xor_ps(source.rotation.value.value, DAT_010c4c00);
        __m128 mixed = _mm_shuffle_ps(source.scale.value, _mm_unpackhi_ps(source.scale.value, DAT_010c7170), 196);
        __m128 reciprocal = _mm_rcp_ps(mixed);
        reciprocal =
            _mm_sub_ps(_mm_add_ps(reciprocal, reciprocal), _mm_mul_ps(_mm_mul_ps(reciprocal, mixed), reciprocal));
        scale.value = _mm_and_ps(reciprocal, DAT_010c4c10);
    }
    __forceinline void SetProduct(const SkeletonQsTransform& a, const SkeletonQsTransform& b)
    {
        ShapeVector translated;
        translated.setRotated(a.rotation, b.translation, false);
        translation.setAdd(a.translation, translated);
        rotation.setMul(&a.rotation, &b.rotation);
        scale.value = _mm_mul_ps(b.scale.value, a.scale.value);
    }
};
struct ErrorStream
{
    int unk00, unk04, unk08, unk0C;
    ErrorStream(char* b, int n)
    {
        FUN_00cb1600(b, n);
    }
    void FUN_00cb1600(char*, int);
    void ProcessAndReturnValue_00cc01c0(const char*);
    ~ErrorStream()
    {
        FUN_00cc00e0();
    }
    void FUN_00cc00e0();
};
struct ErrorHandler
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void report(int, unsigned int, const char*, const char*, int);
};
extern ErrorHandler* DAT_01268360;
template <class T> static __forceinline void arrayDestruct(T* p, int count)
{
    for (int i = 0; i < count; ++i)
        p[i].~T();
}
template <class T> static __forceinline void arrayConstruct(T* p, int count)
{
    for (int i = 0; i < count; ++i)
        ::new (p + i) T;
}
struct ContainerHeapAllocator
{
    __forceinline MemoryAllocator& get(const void*) const
    {
        return ((MemoryAllocator&)hkMemoryRouter_getInstance().heap());
    }
};
template <class T> struct HavokArrayBase
{
    T* data;
    int size;
    int capacity;
    __forceinline HavokArrayBase()
    {
        capacity = 0x80000000;
        data = 0;
        size = 0;
    }
    __forceinline void reserve(MemoryAllocator& heap, int count)
    {
        int old = capacity & 0x3fffffff;
        if (old < count)
            hkArrayUtil__reserve(&heap, this, count < 2 * old ? 2 * old : count, sizeof(T));
    }
    __forceinline void SetSizeAndGrow(MemoryAllocator& heap, int count)
    {
        reserve(heap, count);
        arrayDestruct(data + count, size - count);
        arrayConstruct(data + size, count - size);
        size = count;
    }
};
template <> __forceinline HavokArrayBase<short>::HavokArrayBase()
{
    data = 0;
    size = 0;
    capacity = 0x80000000;
}
template <> __forceinline HavokArrayBase<BoneName>::HavokArrayBase()
{
    data = 0;
    size = 0;
    capacity = 0x80000000;
}
template <class T> struct HavokArray : HavokArrayBase<T>
{
    HavokArray() : HavokArrayBase<T>()
    {}
    __forceinline HavokBool isEmpty() const
    {
        return this->size == 0;
    }
    __forceinline ~HavokArray()
    {
        MemoryAllocator& allocator = ContainerHeapAllocator().get(this);
        arrayDestruct(this->data, this->size);
        if (this->capacity >= 0)
            allocator.freeBuffer(this->data, (this->capacity & 0x3fffffff) * sizeof(T));
        this->data = 0;
        this->size = 0;
        this->capacity = 0x80000000;
    }
    __forceinline void reserve(int count)
    {
        HavokArrayBase<T>::reserve(ContainerHeapAllocator().get(this), count);
    }
    __forceinline void SetSizeAndGrow(int count)
    {
        HavokArrayBase<T>::SetSizeAndGrow(ContainerHeapAllocator().get(this), count);
    }
};
static __forceinline void destroyBones(BoneName* bones, int count)
{
    for (int i = 0; i < count; ++i)
        bones[i].~BoneName();
}
static __forceinline void constructBones(BoneName* bones, int count)
{
    for (int i = 0; i < count; ++i)
        ::new (bones + i) BoneName;
}
static __forceinline void resizeBones(HavokArray<BoneName>& bones, int count)
{
    bones.reserve(count);
    destroyBones(bones.data + count, bones.size - count);
    constructBones(bones.data + bones.size, count - bones.size);
    bones.size = count;
}
typedef hkReferencedObject RigBase;
__forceinline void* __cdecl hkaSkeleton::operator new(unsigned int n)
{
    RigBase* memory = (RigBase*)((MemoryAllocator&)hkMemoryRouter_getInstance().heap()).allocate(n);
    memory->m_usMemSizeAndFlags = (unsigned short)n;
    return memory;
}
__forceinline HavokArray<short>& hkaSkeleton::getParents()
{
    return reinterpret_cast<HavokArray<short>&>(m_kParentIndices);
}
__forceinline hkArray<hkQsTransform>& hkaSkeleton::getPose()
{
    return m_kReferencePose;
}
// this unit's array and hkQsTransform layouts over the reference pose
typedef HavokArray<SkeletonQsTransform> PoseArray;
__forceinline HavokArray<BoneName>& hkaSkeleton::getBones()
{
    return reinterpret_cast<HavokArray<BoneName>&>(m_kBones);
}
// hkArray() for each skeleton member: the shared hkArray's own constructor.
__forceinline hkaSkeleton::hkaSkeleton()
{
}
typedef hkaSkeleton Rig;
struct Shape
{
    int unk00, unk04, unk08, kind;
    float radius;
    int unk14, unk18, unk1C;
    __forceinline float getRadius() const
    {
        return radius;
    }
    __m128 endpointA, endpointB;
};
struct SceneNode
{
    int unk00, unk04, unk08, unk0C;
    Shape* shape;
    int unk14;
    SceneNode* parent;
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70;
    unsigned int taggedName;
    __forceinline const char* getName() const
    {
        return (const char*)(taggedName & ~1u);
    }
    int unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    SkeletonQsTransform transform;
};
struct NodeList
{
    SceneNode** data;
    int size;
    int capacity;
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
};
struct Attachment
{
    int unk00, unk04;
    SceneNode* node;
};
struct AttachmentList
{
    int unk00;
    Attachment** data;
    unsigned int size;
};
static __forceinline int* allocateIndices(MemoryAllocator& heap, int& count)
{
    if (count)
    {
        int bytes = count * 4;
        int* data = (int*)heap.allocateBuffer(bytes);
        count = bytes / 4;
        return data;
    }
    return 0;
}
struct IndexArrayBase
{
    int* data;
    int size;
    int capacity;
    __forceinline IndexArrayBase(int* p, int n, int cap) : data(p), size(n), capacity(cap)
    {}
    static __forceinline IndexArrayBase allocate(MemoryAllocator& heap, int& count)
    {
        int* p = allocateIndices(heap, count);
        return IndexArrayBase(p, count, count ? count : 0x80000000);
    }
};
struct IndexArray : IndexArrayBase
{
    __forceinline IndexArray(int count) : IndexArrayBase(IndexArrayBase::allocate(((MemoryAllocator&)hkMemoryRouter_getInstance().heap()), count))
    {}
    __forceinline ~IndexArray()
    {
        MemoryAllocator* heap = &((MemoryAllocator&)hkMemoryRouter_getInstance().heap());
        if ((capacity & 0x80000000u) == 0)
            heap->freeBuffer(data, (capacity & 0x3fffffff) * 4);
    }
};
static __forceinline float vectorLength4(const __m128& v)
{
    __m128 sum = _mm_mul_ps(v, v);
    __m128 temp = _mm_shuffle_ps(sum, sum, 78);
    sum = _mm_add_ps(temp, sum);
    temp = _mm_shuffle_ps(sum, sum, 177);
    sum = _mm_add_ps(temp, sum);
    return _mm_cvtss_f32(_mm_sqrt_ss(sum));
}
static __forceinline void copyName(char* d, const char* s)
{
    FUN_00ec8d5f(d, 41, s, 40);
}
// Builds an hkaSkeleton rig from scene nodes and attachments, computing parent links, relative transforms, bone names, and shape-derived attachment positions.
// @fnv 0x00ca21c0
Rig* __stdcall BuildRigFromNodes(NodeList* nodes, NodeList* sorted, AttachmentList* attachments)
{
    Rig* rig;
    rig = new Rig;
    unsigned long baseCount;
    {
        HavokArray<short>& parentArray = rig->getParents();
        PoseArray& poseArray = (PoseArray&)rig->getPose();
        int nodeCount = nodes->size;
        int attachmentCount = attachments->size;
        int totalCount = attachmentCount + nodeCount;
        baseCount = nodeCount;
        parentArray.SetSizeAndGrow(attachmentCount + nodeCount);
        poseArray.SetSizeAndGrow(totalCount);
        rig->getBones().SetSizeAndGrow(totalCount);
    }
    IndexArray indices(attachments->size);
    int i = 0;
    if (nodes->GetLogicalSize() > 0)
        do
        {
            long parentIndex = -1;
            if (i)
            {
                SceneNode* prev = sorted->data[i - 1];
                SceneNode* parent = prev->parent;
                for (int j = 0; j < i; ++j)
                    if (nodes->data[j] == parent)
                    {
                        parentIndex = j;
                        break;
                    }
            }
            rig->getParents().data[i] = (short)parentIndex;
            SceneNode* node = nodes->data[i];
            for (unsigned int j = 0; j < attachments->size; ++j)
                if (node == attachments->data[j]->node)
                    indices.data[j] = i;
            if (0 <= parentIndex)
            {
                SceneNode* parent = nodes->data[parentIndex];
                SkeletonQsTransform childTransform, parentTransform;
                childTransform.setFromTransformNoScale(&node->transform);
                parentTransform.setFromTransformNoScale(&parent->transform);
                SkeletonQsTransform& outTransform = ((PoseArray&)rig->getPose()).data[i];
                SkeletonQsTransform inverse;
                inverse.SetConjugate(parentTransform);
                outTransform.SetProduct(inverse, childTransform);
            }
            else
                ((PoseArray&)rig->getPose()).data[i].setFromTransformNoScale(&node->transform);
            const char* text = (const char*)(node->taggedName & ~1u);
            if (text)
            {
                hkStringPtr& boneName = rig->getBones().data[i];
                boneName = hkString_strDup_00cb1410(text);
            }
            else
            {
                char buffer[512];
                {
                    ErrorStream stream(buffer, 512);
                    stream.ProcessAndReturnValue_00cc01c0(DAT_010c7384);
                    DAT_01268360->report(1, 0xabbacc14, buffer, DAT_010c7338, 721);
                }
                rig->getBones().data[i] = (const char*)0;
            }
            rig->getBones().data[i].locked = 0 != i;
        } while (++i < nodes->size);
    for (unsigned int i = 0; i < attachments->size; ++i)
    {
        SceneNode* node = attachments->data[i]->node;
        unsigned int parentIndex = indices.data[i];
        Shape* shape = node->shape;
        if (shape)
        {
            ShapeVector position(_mm_setzero_ps());
            if (shape->kind == 5)
            {
                ShapeVector a(shape->endpointA), b(shape->endpointB);
                ShapeVector center = a.length4() > b.length4() ? a : b;
                float radius = shape->getRadius();
                ShapeVector direction;
                direction.setSub(a, b);
                direction.normalize3();
                direction.value = _mm_mul_ps(direction.value, _mm_load_ps1(&radius));
                center.add4(direction);
                position = center;
            }
            if (4 == shape->kind)
                position.value.m128_f32[0] = shape->getRadius() * 2.0;
            if (6 == shape->kind)
                position.value.m128_f32[0] = shape->getRadius() * 2.0;
            if (1 == shape->kind)
                position.value.m128_f32[0] = shape->getRadius() * 2.0;
            char name[45];
            if (node->getName())
            {
                copyName(name, node->getName());
                name[40] = 0;
            }
            else
                strcpy_s(name, 40, DAT_010c30bc);
            strcat_s(name, 45, DAT_010c732c);
            unsigned long index = i + baseCount;
            hkStringPtr& boneName = rig->getBones().data[index];
            boneName = hkString_strDup_00cb1410(name);
            rig->getBones().data[index].locked = true;
            rig->getParents().data[index] = (short)parentIndex;
            ((PoseArray&)rig->getPose()).data[index].setIdentity();
            ((PoseArray&)rig->getPose()).data[index].translation = position;
        }
    }
    if (!rig->getBones().isEmpty())
        rig->m_name.UpdateState_00cb0c30(rig->getBones().data);
    else
        rig->m_name = (const char*)0;
    return rig;
}

typedef unsigned __int64 uint64;
struct Manager;
struct Provider;
struct ProviderTable
{
    void* unk00;
    void*(__thiscall* allocate)(Provider*, unsigned);
    void* unk08;
    void* unk0c;
    void(__thiscall* free)(Provider*, void*, unsigned);
};
struct Provider
{
    ProviderTable* vtbl;
};
struct VecTable
{
    void* unk00;
    void*(__thiscall* allocate)(void*, unsigned int);
    void(__thiscall* free)(void*, void*);
};
struct CountedObject
{
    unsigned unk00, unk04, unk08, count;
};
struct SectionInfo
{
    unsigned int enabled;
    unsigned int unk04, unk08, unk0c, unk10;
    unsigned int geometry;
};
struct Section
{
    unsigned int unk00, unk04, unk08, unk0c;
    SectionInfo info;
};
struct RendererTable
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void(__thiscall* bounds)(void*, void*, void*);
};
struct Renderer
{
    RendererTable* vtbl;
};
struct RenderContext
{
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
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    Renderer* renderer;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    void* attachment;
};
struct Inner
{
    unsigned unk00, unk04;
    RenderContext* context;
};
struct CollectionCount
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, count;
};
struct Target;
struct TargetTable
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9c;
    void* unka0;
    void* unka4;
    void* unka8;
    void* unkac;
    void* unkb0;
    void* unkb4;
    void* unkb8;
    void* unkbc;
    void* unkc0;
    void(__thiscall* notify)(Target*);
};
struct Target
{
    TargetTable* vtbl;
    unsigned unk04;
    void* flags;
    void Object_DoNothing();
};
struct Node
{
    unsigned unk00, unk04, unk08;
    Target* target;
};
struct Collection
{
    unsigned unk00, unk04;
    Node** nodes;
    unsigned count;
    unsigned unk10, unk14, unk18, unk1c;
    int* indices;
    unsigned unk24, unk28;
    CollectionCount* counter;
};
struct StatePart
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, state;
};
struct Flags
{
    unsigned int unk00, unk04, unk08, unk0c;
    StatePart info;
};
struct Item;
struct Float4
{
    __m128 value;
    __forceinline Float4& operator=(const Float4& a)
    {
        value = a.value;
        return *this;
    }
    __forceinline void splat(float f)
    {
        value = _mm_set1_ps(f);
    }
};
struct SourceVec
{
    void* vtbl;
    Item** data;
    unsigned int count;
    unsigned int capacity;
    SourceVec();
    ~SourceVec();
};
struct Storage;
struct PointerVec
{
    void* vtbl;
    Item** data;
    unsigned int size;
    unsigned int capacity;
    PointerVec();
    ~PointerVec();
    void CopyTo(Storage*);
};
struct Bool8;
template <class T> struct ArrayCore
{
    T* data;
    int count;
    unsigned int mask;
    __forceinline ArrayCore() : data(0), count(0), mask(0x80000000u)
    {}
    __forceinline ~ArrayCore()
    {}
    __forceinline void clear()
    {
        count = 0;
    }
    __forceinline unsigned int capacity() const
    {
        return mask & 0x3fffffffu;
    }
    __forceinline void release(Provider& provider)
    {
        clear();
        if (!(mask & 0x80000000u))
            provider.vtbl->free(&provider, data, capacity() * sizeof(T));
        data = 0;
        mask = 0x80000000u;
    }
};
template <class T> struct TempArray : ArrayCore<T>
{
    __forceinline ~TempArray();
};
template <class T> struct LocalArray : TempArray<T>
{
    T* last;
    __forceinline LocalArray(int capacity);
    __forceinline ~LocalArray();
    __forceinline Bool8 moved() const;
};
typedef TempArray<void*> SmallVec;
typedef TempArray<void*> RightSmallVec;
typedef LocalArray<void*> ScratchVec;
typedef LocalArray<void*> RightScratchVec;
struct Storage
{
    void* unknown;
    Item** data;
    unsigned int count;
    unsigned int capacity;
    void CopyTo(PointerVec* newItems);
};
struct Builder
{
    void* vtable;
    unsigned handle;
    unsigned count;
    unsigned capacity;
    Builder();
    ~Builder();
};
struct Item
{
    void* source;
    void* collection;
    void* scene;
    void* bounding;
    void* payload;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int mask;
    unsigned char active;
    Item();
    static void* operator new(unsigned int);
    void FUN_00ca2020();
};
struct AllocatorExtended : Allocator
{
    void* Game_DoHeapAlloc(unsigned int bytes);
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);
enum PreparationResult
{
    PreparationSucceeded,
    PreparationFailed
};
PreparationResult __cdecl hkaRagdollUtils_reorderForRagdoll(SmallVec* a, RightSmallVec* b);
void* __cdecl hkaRagdollUtils_createRagdollInstanceFromSkeleton(void* x, SmallVec* a, RightSmallVec* b);
uint64 __cdecl BSPrecisionTimer_GetTimer();
struct Grower
{
    void BSSimpleArray_Resize(unsigned int newCap, unsigned int old);
};
struct Appender
{
    unsigned int BSSimpleArray_GetNextIndex_2();
};
extern int DAT_01071aec;
extern int DAT_010c7310;
extern int DAT_0104e190;
extern float DAT_0104e148;
extern float DAT_0104da48;
struct Pair8;
static __forceinline void free8(Provider* a, void* ptr, int n)
{
    a->vtbl->free(a, ptr, n * 8);
}
struct Pair8
{
    unsigned int a, b;
};
struct Array8
{
    Pair8* data;
    unsigned int count;
    unsigned int mask;
    __forceinline Array8() : data(0), count(0), mask(0x80000000)
    {}
    __forceinline ~Array8()
    {
        hkMemoryRouter* ctx = (&hkMemoryRouter::getInstance());
        Provider* allocator = ((Provider*)ctx->m_heap);
        count = 0;
        if ((mask & 0x80000000u) == 0)
            free8(allocator, data, mask & 0x3fffffff);
    }
};
struct SceneRecord
{
    unsigned int resource;
    unsigned int unk04;
    unsigned char kind;
    Array8 array;
    Float4 minimum;
    Float4 maximum;
    __forceinline SceneRecord()
    {
        unk04 = 0;
        kind = 2;
    }
};
struct FUN_0056e550;
struct BoundTable
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    void* unk98;
    void(__thiscall* attach)(FUN_0056e550*, void*);
};
struct FUN_0056e550
{
    BoundTable* vtbl;
    unsigned unk04;
    void* resource;
    FUN_0056e550(SceneRecord*);
    unsigned unk0c, unk10, unk14;
    static __forceinline void* operator new(unsigned n)
    {
        return Object_DispatchCommandFour(n);
    }
    static void operator delete(void*);
};
struct PayloadArgs
{
    void* collection;
    Manager* owner;
    void* resource;
};
struct FUN_00d1fa50
{
    unsigned unk00;
    unsigned short size;
    unsigned short flags;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    FUN_00d1fa50(PayloadArgs*);
    void ResetEntries();
    static __forceinline void* operator new(unsigned int size)
    {
        hkMemoryRouter* alloc = (&hkMemoryRouter::getInstance());
        FUN_00d1fa50* p = (FUN_00d1fa50*)((Provider*)alloc->m_heap)->vtbl->allocate(((Provider*)alloc->m_heap), size);
        p->size = (unsigned short)size;
        return p;
    }
    static void operator delete(void*);
};
extern float DAT_012682b4;
extern float DAT_011ac39c;

struct PrecisionTimer
{
    uint64 started, finished;
    __forceinline void reset(float elapsed)
    {
        started = BSPrecisionTimer_GetTimer();
        finished = (__int64)(elapsed * DAT_011ac39c);
    }
};
struct Manager
{
    void* vtable;
    Storage storage;
    unsigned int option;
    bool active;
    unsigned int idleCount;
    PrecisionTimer timer;
    void CollectShaderNodes(void* source, SourceVec* result);
    void TraverseSceneNode(Item* input, SmallVec* first, RightSmallVec* second);
    void CollectMixedTypeNodes(SmallVec* first, Builder* builder);
    void* BuildRigFromNodes(SmallVec* first, RightSmallVec* second, Builder* build);
    bool bhkRagdollPenetrationUtil_Initialize(void* source, unsigned int flags);
    __forceinline unsigned int storageCount()
    {
        unsigned int n = storage.count;
        return n;
    }
};
struct Bool8
{
    char value;
    __forceinline Bool8(bool x) : value(x)
    {}
    __forceinline operator bool() const
    {
        return value != 0;
    }
};
static __forceinline char** counters()
{
    return (char**)&(&hkMemoryRouter::getInstance())->m_stack.m_next.m_storage;
}
template <class T> static __forceinline void release_stack(T* memory)
{
    *counters() = (char*)memory;
}
template <class T> __forceinline TempArray<T>::~TempArray()
{
    hkMemoryRouter* context = (&hkMemoryRouter::getInstance());
    this->release(*((Provider*)context->m_heap));
}
template <class T> __forceinline LocalArray<T>::LocalArray(int capacity)
{
    char** counter = counters();
    char* start = *counter;
    *counter = start + ((capacity * sizeof(T) + 127) & ~127);
    this->data = (T*)start;
    this->mask = capacity | 0x80000000u;
    last = this->data;
}
template <class T> __forceinline Bool8 LocalArray<T>::moved() const
{
    return last != this->data;
}
template <class T> __forceinline LocalArray<T>::~LocalArray()
{
    if (!moved())
        this->clear();
    release_stack(last);
}
__forceinline SourceVec::SourceVec() : vtbl(&DAT_01071aec), data(0), count(0), capacity(0)
{}
__forceinline PointerVec::PointerVec() : vtbl(&DAT_010c7310), data(0), size(0), capacity(0)
{}
__forceinline Builder::Builder() : vtable(&DAT_0104e190), handle(0), count(0), capacity(0)
{}
__forceinline SourceVec::~SourceVec()
{
    vtbl = &DAT_01071aec;
    if (data)
    {
        ((VecTable*)vtbl)->free(this, data);
    }
}
__forceinline PointerVec::~PointerVec()
{
    vtbl = &DAT_010c7310;
    if (data)
    {
        ((VecTable*)vtbl)->free(this, data);
        data = 0;
        size = capacity = 0;
    }
}
__forceinline Builder::~Builder()
{
    vtable = &DAT_0104e190;
    if (handle)
    {
        ((VecTable*)vtable)->free(this, (void*)handle);
        handle = 0;
        count = capacity = 0;
    }
}
__forceinline Item::Item()
    : source(0), collection(0), scene(0), bounding(0), payload(0), unknown14(0), unknown18(0), mask(0x80000000),
      active(1)
{}
__forceinline void* Item::operator new(unsigned int n)
{
    return ((AllocatorExtended*)&DAT_011f6238)->Game_DoHeapAlloc(n);
}
static __forceinline void add_pointer(PointerVec& vec, Item* const& ptr)
{
    if (vec.size == vec.capacity)
    {
        if (vec.capacity == 0)
        {
            vec.data = (Item**)((VecTable*)vec.vtbl)->allocate(&vec, 4);
            vec.capacity = 4;
        }
        else
        {
            unsigned int newSize = vec.capacity > 1024 ? vec.capacity + 1024 : vec.capacity * 2;
            ((Grower*)&vec)->BSSimpleArray_Resize(newSize, vec.size);
            vec.capacity = newSize;
        }
    }
    ++vec.size;
    vec.data[vec.size - 1] = ptr;
}
static __forceinline void update_min_max(Float4& low, Float4& high, const hkAabb& in)
{
    high.value = _mm_max_ps(high.value, reinterpret_cast<const Float4&>(in.m_kMaximumCorner.x).value);
    low.value = _mm_min_ps(low.value, reinterpret_cast<const Float4&>(in.m_kMinimumCorner.x).value);
}
static __forceinline int countOf(Collection* c)
{
    CollectionCount* counter = c->counter;
    return (int)counter->count;
}
struct FilterBits
{
    unsigned int bits;
    __forceinline FilterBits(unsigned int x) : bits(x)
    {}
    __forceinline operator unsigned int() const
    {
        unsigned int v = bits;
        return v;
    }
    __forceinline bool test() const
    {
        return (unsigned char)(bits >> 14) & 1;
    }
    __forceinline void clear()
    {
        bits &= ~0x4000u;
    }
};
static __forceinline void processNode(Collection* group, int inner)
{
    int idx = group->indices[inner];
    if (idx < 0)
        return;
    Node* node = group->nodes[idx];
    if (!node)
        return;
    Target* target = node->target;
    if (!target)
        return;
    Flags* base = (Flags*)target->flags;
    StatePart* info = base ? &base->info : 0;
    unsigned int state = info ? info->state : 0;
    FilterBits filter(state);
    if (filter.test())
    {
        filter.clear();
        if (base)
        {
            target->Object_DoNothing();
            info = &base->info;
            target->Object_DoNothing();
            if (info)
                info->state = filter;
        }
        target->vtbl->notify(target);
    }
}
static __forceinline void setResource(SceneRecord& r, unsigned int opt)
{
    unsigned int v = (opt << 16) | 0x1e;
    r.resource = v;
}
// Rebuilds the storage list from source data, reusing existing items, creating new ones with bounding boxes, and removing stale entries.
// @fnv 0x00ca2ad0
// src: COMMUNITY 0x00ca2ad0
bool Manager::bhkRagdollPenetrationUtil_Initialize(void* source, unsigned int flags)
{
    int inner;
    int work;
    option = flags;
    SourceVec original;
    CollectShaderNodes(source, &original);
    PointerVec retained;
    bool unavailable = false;
    for (unsigned int outer = 0; outer < original.count; ++outer)
    {
        ScratchVec left(64);
        RightScratchVec right(64);
        TraverseSceneNode(original.data[outer], &left, &right);
        if (right.count == 0)
            continue;
        bool reused = false;
        for (inner = 0; (unsigned int)inner < storage.count && !reused; ++inner)
        {
            Item*& item = storage.data[inner];
            Item* value = item;
            if (original.data[outer] == value->source)
            {
                int count = (int)left.count;
                CountedObject* group = (CountedObject*)value->collection;
                if (count == (int)group->count)
                {
                    add_pointer(retained, item);
                    reused = true;
                }
            }
        }
        if (reused)
            continue;
        Builder temp;
        CollectMixedTypeNodes(&left, &temp);
        Item* entry = new Item;
        if (hkaRagdollUtils_reorderForRagdoll(&left, &right) != PreparationFailed)
        {
            entry->source = original.data[outer];
            entry->scene = BuildRigFromNodes(&left, &right, &temp);
            if (entry->scene)
                entry->collection = hkaRagdollUtils_createRagdollInstanceFromSkeleton(entry->scene, &left, &right);
            if (entry->collection)
            {
                Inner* obj = (Inner*)((Collection*)entry->collection)->nodes[0];
                {
                    RenderContext* context = obj ? obj->context : 0;
                    Float4 maxv;
                    maxv.splat(DAT_0104e148);
                    Float4 minv;
                    minv.splat(DAT_0104da48);
                    Float4 boxStorage[sizeof(hkAabb) / sizeof(Float4)];
                    hkAabb& box = reinterpret_cast<hkAabb&>(boxStorage);
                    for (work = 0; work < (int)left.count; ++work)
                    {
                        SectionInfo* section = &((Section*)left.data[work])->info;
                        if (section->enabled)
                        {
                            Renderer* renderer = context->renderer;
                            renderer->vtbl->bounds(renderer, &section->geometry, &box);
                            update_min_max(minv, maxv, box);
                        }
                    }
                    reinterpret_cast<Float4&>(box.m_kMinimumCorner.x) = minv;
                    reinterpret_cast<Float4&>(box.m_kMaximumCorner.x) = maxv;
                    SceneRecord record;
                    setResource(record, option);
                    record.minimum = reinterpret_cast<const Float4&>(box.m_kMinimumCorner.x);
                    record.maximum = reinterpret_cast<const Float4&>(box.m_kMaximumCorner.x);
                    entry->bounding = new FUN_0056e550(&record);
                    Inner* attachObj = (Inner*)((Collection*)entry->collection)->nodes[0];
                    if (attachObj && attachObj->context)
                    {
                        Inner* o2 = (Inner*)((Collection*)entry->collection)->nodes[0];
                        void* attachment = o2 && o2->context ? o2->context->attachment : 0;
                        FUN_0056e550* bound = (FUN_0056e550*)entry->bounding;
                        if (bound)
                            bound->vtbl->attach(bound, attachment);
                    }
                    PayloadArgs args = {((Collection*)entry->collection)->counter, this,
                                        ((FUN_0056e550*)entry->bounding)->resource};
                    entry->payload = new FUN_00d1fa50(&args);
                    ((FUN_00d1fa50*)entry->payload)->ResetEntries();
                    timer.reset(DAT_012682b4 * 1000.0);
                }
            }
        }
        else
            unavailable = true;
        if (entry->bounding && entry->source && entry->payload && entry->collection && entry->scene)
        {
            unsigned int n = ((Appender*)&retained)->BSSimpleArray_GetNextIndex_2();
            retained.data[n] = entry;
        }
        else
        {
            entry->FUN_00ca2020();
            DAT_011f6238.MemoryManager_Deallocate(entry);
        }
    }
    for (inner = 0; (unsigned int)inner < storageCount(); ++inner)
    {
        Item*& previous = storage.data[inner];
        int found = -1;
        for (unsigned int j = 0; j < retained.size; ++j)
        {
            if (retained.data && retained.data[j] == previous)
            {
                found = j;
                break;
            }
        }
        if (found == -1)
        {
            Item* p = previous;
            if (p)
            {
                p->FUN_00ca2020();
                DAT_011f6238.MemoryManager_Deallocate(p);
            }
        }
    }
    retained.CopyTo(&storage);
    bool result = storage.count > 0;
    active = (!result && !unavailable);
    if (active)
    {
        if (++idleCount > 5)
        {
            active = false;
            idleCount = 0;
        }
    }
    else
        idleCount = 0;
    for (unsigned int outer = 0; outer < storage.count; ++outer)
    {
        for (int bone = 0; bone < countOf((Collection*)storage.data[outer]->collection); ++bone)
        {
            processNode((Collection*)storage.data[outer]->collection, bone);
        }
    }
    return result;
}
