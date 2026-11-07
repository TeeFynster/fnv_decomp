#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// src/havok/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdBodyPairCollector.h"
#include "../../../../../../../include/hkpMultiSphereShape.h"
#include "../../../../../../../include/hkpMultiSphereTriangleAgent.h"
#include "../../../../../../../include/hkpTriangleShape.h"

namespace SphereTriangleProcessSimd {
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
extern "C" {
LocalM128 _mm_load_ss(const float*);
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_add_ps(LocalM128, LocalM128);
}
}

__forceinline float hkpTriangleShape::getRadius() const { return m_fSphereRadius; }
__forceinline const hkVector4_S* hkpTriangleShape::GetIndexedVertices() const { return reinterpret_cast<const hkVector4_S*>(&m_kVertexA); }

extern "C" {
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
void _ReadWriteBarrier(void);
unsigned __int64 __rdtsc(void);
}
struct VectorWords { unsigned int x, y, z, w; };
struct FloatWords { float x, y, z, w; };
// local form of hkVector4: 0x00d38b00 needs a trivial union with SphereTriangleProcessSimd packet and integer tag views.
union SphereTrianglePacketLocal_00d38b00 { SphereTriangleProcessSimd::LocalM128 q; VectorWords bits; FloatWords values; };
struct TransformStorage { VectorWords x, y, z, translation; };
struct CollisionInput { unsigned int flags, quality; float tolerance; };
struct TriangleCache { float edge0, edge1, edge2, inverseArea; };
struct ClosestPointUtilities { SphereTrianglePacketLocal_00d38b00 normal; float distance; };
struct Contact {
    SphereTrianglePacketLocal_00d38b00 position, normal;
    const hkpCdBody* bodyA;
    const hkpCdBody* bodyB;
};
struct ContactCollector {
    virtual void destructor();
    virtual void AddContact(const Contact&);
};
struct TimerRecord { const char* name; unsigned int ticks; unsigned int extra; };
struct Monitor { TimerRecord* start; TimerRecord* next; TimerRecord* capacity; TimerRecord* limit; };
extern unsigned long DAT_0126835c;
void __cdecl hkpCollideTriangleUtil_closestPointTriangle(const SphereTrianglePacketLocal_00d38b00*, const SphereTrianglePacketLocal_00d38b00*, TriangleCache*, ClosestPointUtilities*, unsigned char*);
static __forceinline SphereTriangleProcessSimd::LocalM128 TransformPoint(const SphereTriangleProcessSimd::LocalM128& tx, const SphereTriangleProcessSimd::LocalM128& ty, const SphereTriangleProcessSimd::LocalM128& tz, const SphereTriangleProcessSimd::LocalM128& tt, const SphereTriangleProcessSimd::LocalM128& v)
{
    return SphereTriangleProcessSimd::_mm_add_ps(
        SphereTriangleProcessSimd::_mm_add_ps(SphereTriangleProcessSimd::_mm_mul_ps(SphereTriangleProcessSimd::_mm_shuffle_ps(v, v, 0), tx),
                   SphereTriangleProcessSimd::_mm_mul_ps(SphereTriangleProcessSimd::_mm_shuffle_ps(v, v, 0x55), ty)),
        SphereTriangleProcessSimd::_mm_add_ps(SphereTriangleProcessSimd::_mm_mul_ps(SphereTriangleProcessSimd::_mm_shuffle_ps(v, v, 0xaa), tz),
                   tt));
}
static __forceinline VectorWords CopyWords(const VectorWords& from) {return from;}
static __forceinline VectorWords CopyOther(const VectorWords& from) { VectorWords r = {from.x,from.y,from.z,from.w}; return r; }
struct SphereTriangleClosestPointReceiver : hkpMultiSphereTriangleAgent {
    void closestPoints(const hkpCdBody*, const hkpCdBody*, const CollisionInput*, ContactCollector*);
};
// @fnv 0x00d38390
void SphereTriangleClosestPointReceiver::closestPoints(const hkpCdBody* bodyA, const hkpCdBody* bodyB, const CollisionInput* input, ContactCollector* collector)
{
    volatile unsigned int timerTicks;
    ClosestPointUtilities closest;
    {
        Monitor* timerMonitor = static_cast<Monitor*>(TlsGetValue(DAT_0126835c));
        TimerRecord* timerRecord = timerMonitor->next;
        if (timerRecord < timerMonitor->limit) {
            timerRecord->name = "TtMultiSphereTriangle";
            _ReadWriteBarrier();
            timerTicks = static_cast<unsigned int>(__rdtsc());
            timerRecord->ticks = timerTicks;
            timerMonitor->next = timerRecord + 1;
        }
    }
    const hkpMultiSphereShape* __restrict spheres = static_cast<const hkpMultiSphereShape*>(bodyA->m_pCollisionShape);
    const hkpTriangleShape* triangle = static_cast<const hkpTriangleShape*>(bodyB->m_pCollisionShape);
    SphereTrianglePacketLocal_00d38b00 triangleWorld[3];
    {
    const TransformStorage* __restrict tb = static_cast<const TransformStorage*>(bodyB->m_pMotionState);
    SphereTrianglePacketLocal_00d38b00 bxv; bxv.bits = CopyOther(tb->x); SphereTriangleProcessSimd::LocalM128 bx = bxv.q;
    SphereTrianglePacketLocal_00d38b00 byv; byv.bits = CopyWords(tb->y); SphereTriangleProcessSimd::LocalM128 by = byv.q;
    SphereTrianglePacketLocal_00d38b00 bzv; bzv.bits = CopyOther(tb->z); SphereTriangleProcessSimd::LocalM128 bz = bzv.q;
    closest.normal.bits = CopyWords(tb->translation); SphereTriangleProcessSimd::LocalM128 bt = closest.normal.q;
    const SphereTrianglePacketLocal_00d38b00* triVerts = reinterpret_cast<const SphereTrianglePacketLocal_00d38b00*>(&triangle->m_kVertexA);
    for (int i = 2; i >= 0; --i) {
        triangleWorld[i].q = TransformPoint(bx, by, bz, bt, triVerts[i].q);
    }
    }
    SphereTrianglePacketLocal_00d38b00 spheresWorld[8];
    const SphereTrianglePacketLocal_00d38b00* sourceSphere = reinterpret_cast<const SphereTrianglePacketLocal_00d38b00*>(spheres->m_kSpheres);
    const int count = spheres->m_iSphereCount;
    {
    const TransformStorage* __restrict ta = static_cast<const TransformStorage*>(bodyA->m_pMotionState);
    closest.normal.bits = CopyWords(ta->x); SphereTriangleProcessSimd::LocalM128 ax = closest.normal.q;
    SphereTrianglePacketLocal_00d38b00 ayv; ayv.bits = CopyWords(ta->y); SphereTriangleProcessSimd::LocalM128 ay = ayv.q;
    SphereTrianglePacketLocal_00d38b00 azv; azv.bits = CopyWords(ta->z); SphereTriangleProcessSimd::LocalM128 az = azv.q;
    SphereTrianglePacketLocal_00d38b00 atv; atv.bits = CopyWords(ta->translation); SphereTriangleProcessSimd::LocalM128 at = atv.q;
    int sphereIndex = count - 1;
    do {
        spheresWorld[sphereIndex].q = TransformPoint(ax, ay, az, at, sourceSphere[sphereIndex].q);
    } while (--sphereIndex >= 0);
    }
    const SphereTrianglePacketLocal_00d38b00* originalSource=sourceSphere;
    Contact contact;
    contact.bodyA = bodyA;
    contact.bodyB = bodyB;
    {
        for (int index = 0; index < count; ++index) {
        TriangleCache* triPlane = reinterpret_cast<TriangleCache*>(&m_kTriangleNormal);
            const SphereTrianglePacketLocal_00d38b00* current = &spheresWorld[index];
            float radiusSum=*static_cast<const volatile float*>(&triangle->m_fSphereRadius)+sourceSphere[index].values.w;
            hkpCollideTriangleUtil_closestPointTriangle(current, triangleWorld, triPlane, &closest, 0);
const float& distance = closest.distance;
float threshold = input->tolerance + radiusSum;
            if (distance < threshold) {
                float offset = triangle->m_fSphereRadius - distance;
                SphereTriangleProcessSimd::LocalM128 off = SphereTriangleProcessSimd::_mm_load_ss(&offset);
                contact.position.q = SphereTriangleProcessSimd::_mm_add_ps(current->q, SphereTriangleProcessSimd::_mm_mul_ps(SphereTriangleProcessSimd::_mm_shuffle_ps(off, off, 0), closest.normal.q));
                contact.normal.q = closest.normal.q;
                contact.normal.values.w = distance - radiusSum;
                collector->AddContact(contact);
            }


        }
    }
    {
        Monitor* timerMonitor = static_cast<Monitor*>(TlsGetValue(DAT_0126835c));
        TimerRecord* timerRecord = timerMonitor->next;
        if (timerRecord < timerMonitor->limit) {
            timerRecord->name = "Et";
            _ReadWriteBarrier();
            timerTicks = static_cast<unsigned int>(__rdtsc());
            timerRecord->ticks = timerTicks;
            timerMonitor->next = timerRecord + 1;
        }
    }
}

template<class T> class ProcessValue {
    T value;
public:
    __forceinline ProcessValue() {}
    __forceinline ProcessValue(T x) : value(x) {}
    __forceinline operator T() const { return value; }
    __forceinline T val() const { return value; }
};

class ProcessTransform;
class ProcessScalar {
    SphereTriangleProcessSimd::LocalM128 value;
public:
    ProcessScalar(float x) { value = SphereTriangleProcessSimd::_mm_load_ss(&x); }
    __forceinline SphereTriangleProcessSimd::LocalM128 broadcast() const { return SphereTriangleProcessSimd::_mm_shuffle_ps(value, value, 0); }
};
class ProcessVector {
    SphereTriangleProcessSimd::LocalM128 value;
public:
    __forceinline void operator=(const ProcessVector& x) { value = x.value; }
    __forceinline float& operator()(int i) { return reinterpret_cast<float*>(&value)[i]; }
    __forceinline const float& operator()(int i) const { return reinterpret_cast<const float*>(&value)[i]; }
    __forceinline void addScaled(const ProcessVector& a, const ProcessVector& b, const ProcessScalar& scale) {
        value = SphereTriangleProcessSimd::_mm_add_ps(a.value, SphereTriangleProcessSimd::_mm_mul_ps(scale.broadcast(), b.value));
    }
    __forceinline void transform(const ProcessTransform&, const ProcessVector&);
};
class ProcessMatrix {
    ProcessVector x, y, z;
public:
    __forceinline ProcessVector& column(int i) { return (&x)[i]; }
    __forceinline const ProcessVector& column(int i) const { return (&x)[i]; }
};
class __declspec(align(16)) ProcessRotation : public ProcessMatrix {};
class ProcessTransform {
    ProcessRotation rotation;
    ProcessVector translation;
public:
    __forceinline ProcessTransform(const ProcessTransform& t) {
        const ProcessVector x = t.rotation.column(0);
        const ProcessVector y = t.rotation.column(1);
        const ProcessVector z = t.rotation.column(2);
        const ProcessVector w = t.rotation.column(3);
        rotation.column(0) = x;
        rotation.column(1) = y;
        rotation.column(2) = z;
        rotation.column(3) = w;
    }
    __forceinline const ProcessRotation& getRotation() const { return rotation; }
    __forceinline const ProcessVector& getTranslation() const { return translation; }
};
void ProcessVector::transform(const ProcessTransform& t, const ProcessVector& b) {
    const ProcessRotation& r = t.getRotation();
    SphereTriangleProcessSimd::LocalM128 x = SphereTriangleProcessSimd::_mm_shuffle_ps(b.value, b.value, 0);
    SphereTriangleProcessSimd::LocalM128 rx = SphereTriangleProcessSimd::_mm_mul_ps(r.column(0).value, x);
    SphereTriangleProcessSimd::LocalM128 y = SphereTriangleProcessSimd::_mm_shuffle_ps(b.value, b.value, 0x55);
    SphereTriangleProcessSimd::LocalM128 ry = SphereTriangleProcessSimd::_mm_mul_ps(r.column(1).value, y);
    SphereTriangleProcessSimd::LocalM128 z = SphereTriangleProcessSimd::_mm_shuffle_ps(b.value, b.value, 0xaa);
    SphereTriangleProcessSimd::LocalM128 rz = SphereTriangleProcessSimd::_mm_mul_ps(r.column(2).value, z);
    value = SphereTriangleProcessSimd::_mm_add_ps(SphereTriangleProcessSimd::_mm_add_ps(rx, ry), SphereTriangleProcessSimd::_mm_add_ps(rz, t.getTranslation().value));
}
static __forceinline void processPoints(const ProcessTransform& t, const ProcessVector* src, int count, ProcessVector* dst) {
    ProcessTransform copy = t;
    int i = count - 1;
    do { dst[i].transform(copy, src[i]); } while (--i >= 0);
}

struct ProcessTimerRecord {
    const char* name;
    unsigned ticks, extra;
    __forceinline void setTime() {
        unsigned ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        this->ticks = ticks;
    }
};
struct ProcessMonitor {
    ProcessValue<char*> start, end, capacity, limit;
    static __forceinline ProcessMonitor& instance() {
        return *static_cast<ProcessMonitor*>(TlsGetValue(DAT_0126835c));
    }
    __forceinline bool available() { return end.val() < limit.val(); }
};
// Accessors adapt the shared layouts to the SIMD helper types used below.
struct ProcessBody : hkpCdBody {
    __forceinline const void* getShape() const { return m_pCollisionShape; }
    __forceinline const ProcessTransform& getTransform() const { return *static_cast<const ProcessTransform*>(m_pMotionState); }
};
struct ProcessTriangle : hkpTriangleShape {
    __forceinline const ProcessVector* GetIndexedVertices() const { return reinterpret_cast<const ProcessVector*>(&m_kVertexA); }
};
struct ProcessSpheres : hkpMultiSphereShape {
    __forceinline const ProcessVector* getSpheres() const { return reinterpret_cast<const ProcessVector*>(m_kSpheres); }
    __forceinline int getNumSpheres() const { return m_iSphereCount; }
};
struct ProcessContact {
    ProcessVector position, normal;
    __forceinline ProcessVector& getPosition() { return position; }
    __forceinline void setNormal(const ProcessVector& v) { normal = v; }
    __forceinline void setDistance(float distance) { normal(3) = distance; }
};
struct ProcessPoint {
    ProcessContact contact;
    ProcessValue<unsigned> id;
};
struct ProcessOutput {
    ProcessValue<ProcessPoint*> first;
    ProcessValue<void*> owner;
    ProcessPoint* reserve(int = 1) { return first; }
    void commit(int count = 1) { first = first + count; }
    void abort(int = 1) {}
};
struct ProcessInput {
    ProcessValue<void*> dispatcher;
    ProcessValue<int> weld;
    ProcessValue<float> tolerance;
    float getTolerance() const { return tolerance; }
};
struct ProcessClosest {
    ProcessVector direction;
    ProcessValue<float> distance;
};
struct ProcessManager {
    virtual void destroy();
    virtual void classType();
    virtual void statistics();
    virtual unsigned short addImpl(const ProcessBody&, const ProcessBody&, const ProcessInput&, ProcessOutput&, const void*, ProcessContact&) = 0;
    virtual int reserveImpl(int) = 0;
    virtual void removeImpl(unsigned short, void*) = 0;
    __forceinline unsigned short add(const ProcessBody& a, const ProcessBody& b, const ProcessInput& i, ProcessOutput& o, const void* cache, ProcessContact& p) {
        return addImpl(a, b, i, o, cache, p);
    }
    __forceinline void remove(unsigned short id, void* owner) { removeImpl(id, owner); }
};
extern "C" int __cdecl hkpCollideTriangleUtil_closestPointTriangle(const ProcessVector&, const ProcessVector*, const hkpMultiSphereTriangleAgent::TriangleNormal&, ProcessClosest&, void* = 0);
struct SphereTriangleProcessReceiver : hkpMultiSphereTriangleAgent {
    void hkpMultiSphereTriangleAgent_processCollision(const ProcessBody&, const ProcessBody&, const ProcessInput&, ProcessOutput&);
};
// @fnv 0x00d38b00
// src: HAVOK_SRC 0x00d38b00
void SphereTriangleProcessReceiver::hkpMultiSphereTriangleAgent_processCollision(const ProcessBody& a, const ProcessBody& b, const ProcessInput& input, ProcessOutput& output) {
    {
        ProcessMonitor& monitor = ProcessMonitor::instance();
        if (monitor.available()) {
            ProcessTimerRecord* record = reinterpret_cast<ProcessTimerRecord*>(monitor.end.val());
            record->name = "TtMultiSphereTri";
            record->setTime();
            monitor.end = reinterpret_cast<char*>(record + 1);
        }
    }
    const ProcessSpheres* spheres = static_cast<const ProcessSpheres*>(a.getShape());
    const ProcessTriangle* triangle = static_cast<const ProcessTriangle*>(b.getShape());
    const ProcessVector* vertices = triangle->GetIndexedVertices();
    ProcessVector triangleWorld[3];
    processPoints(b.getTransform(), vertices, 3, triangleWorld);
    const ProcessVector* localSpheres = spheres->getSpheres();
    const int count = spheres->getNumSpheres();
    ProcessVector sphereWorld[8];
    processPoints(a.getTransform(), localSpheres, count, sphereWorld);
    const ProcessVector* current = sphereWorld;
    const ProcessVector* local = localSpheres;
    for (int j = count - 1; j >= 0; ++current, ++local, --j) {
        const float sphereRadius = (*local)(3);
        const float radiusSum = sphereRadius + triangle->getRadius();
        {
            ProcessClosest closest;
            hkpCollideTriangleUtil_closestPointTriangle(*current, triangleWorld, m_kTriangleNormal, closest);
            if (closest.distance < radiusSum + input.getTolerance()) {
                ProcessPoint* point = output.reserve(1);
                point->contact.getPosition().addScaled(*current, closest.direction, triangle->getRadius() - closest.distance);
                point->contact.setNormal(closest.direction);
                point->contact.setDistance(closest.distance - radiusSum);
                if (m_ids[j] == 0xffff) {
                    m_ids[j] = reinterpret_cast<ProcessManager*>(m_pContactManager)->add(a, b, input, output, 0, point->contact);
                }
                if (m_ids[j] != 0xffff) {
                    output.commit(1);
                    point->id = m_ids[j];
                } else {
                    output.abort(1);
                }
                continue;
            }
        }
        if (m_ids[j] != 0xffff) {
            reinterpret_cast<ProcessManager*>(m_pContactManager)->remove(m_ids[j], output.owner.val());
            m_ids[j] = 0xffff;
        }
    }
    {
        ProcessMonitor& monitor = ProcessMonitor::instance();
        if (monitor.available()) {
            ProcessTimerRecord* record = reinterpret_cast<ProcessTimerRecord*>(monitor.end.val());
            record->name = "Et";
            record->setTime();
            monitor.end = reinterpret_cast<char*>(record + 1);
        }
    }
}
