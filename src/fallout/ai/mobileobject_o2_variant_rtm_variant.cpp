// src/fallout/ai/mobileobject_o2_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/mobileobject_o2_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/fallout/ai/mobileobject_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/mobileobject.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
class ExtraDismemberedLimbs;
class bhkCharacterController;
#include "../../../include/HitArray.h"
#include "../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../../include/layout_support.h"
#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "mobileobject_private/mobileobject_types_TESPackage.h"
#include "mobileobject_private/mobileobject_interface.h"
#include "../../../include/BSAudio.h"
#include "../../../include/BSSoundHandle.h"
extern TESDataHandler* g_dataHandler;
#include "mobileobject_private/mobileobject_packet.h"
bhkCharacterController* CopyCharacterControllerVector(bhkCharacterController* output, const NiPoint3& point);
struct UnkCallee
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4(int, int);
};
struct UnkRet
{
    char _0[16];
    UnkCallee* p10;
};
struct UnkHolder
{
    char _0[12];
    volatile int mC;
    volatile int m10;
    volatile int m14;
    UnkRet* hkMemoryRouter_getInstance();
    void UpdateState_00c72210();
};

extern const char str_010c4ad8[], str_010c4ac0[], str_010c41f8[];
extern "C" void _ReadWriteBarrier();
#include <xmmintrin.h>
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern const float DAT_01267bcc;
extern float DAT_01267bc4, DAT_010181bc, DAT_01017d00;
extern float DAT_01011d78, DAT_01012054, DAT_011b014c, DAT_01267bb0;
extern double DAT_01032980, DAT_0103c7c8;
extern __m128 DAT_01267e30, DAT_01017d10, DAT_010c71e0, DAT_010c44d0;
__forceinline void AddMovement(NiPoint3& out,const NiPoint3& rhs){out.x=(float)(rhs.x+out.x);out.y=(float)(rhs.y+out.y);out.z=(float)(rhs.z+out.z);}
extern NiPoint3 DAT_011f426c;

struct S00c73170_Flags { unsigned int value; __forceinline void Or(unsigned int m) { value |= m; } __forceinline void Clear(unsigned int m) { value &= ~m; } __forceinline void Set(unsigned int m, bool on) { if (on) Or(m); else Clear(m); } __forceinline bool Bit(int n) const { return (value >> n) & 1; } };
class S00c73170_Bool { public: __forceinline S00c73170_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); } __forceinline operator bool() const { return m_cBooleanValue != 0; } char m_cBooleanValue; };
struct TraceEntry {
    const char* label; unsigned long tick; unsigned long unused;
    __forceinline void setTime() {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        tick=ticks;
    }
};
template<typename T> class S00c73170_Pad { public: __forceinline T& val() { return m_kStorage; } __forceinline const T& val() const { return m_kStorage; } __forceinline void operator=(const T& p) { m_kStorage = p; } T m_kStorage; };
struct TraceBuffer {
    S00c73170_Pad<char*> m_kRayStart, m_kRayEnd, m_pRayCursor, m_pCurrentCommand;
    static __forceinline TraceBuffer& GetMonitorStream() { return *(TraceBuffer*)TlsGetValue(DAT_0126835c); }
    __forceinline char* GetStreamEnd() { return m_kRayEnd.val(); }
    __forceinline char* getCapacityMinus16() { return m_pCurrentCommand.val(); }
    __forceinline S00c73170_Bool memoryAvailable() { return GetStreamEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_kRayEnd = ptr; }
};
__forceinline void Trace(const char* label) {
    TraceBuffer& mStream = TraceBuffer::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        TraceEntry* h = reinterpret_cast<TraceEntry*>(mStream.GetStreamEnd());
        h->label=label;
        h->setTime();
        mStream.setEnd((char*)(h+1));
    }
}

class S00c73170_Real {
public:
    __forceinline S00c73170_Real(const __m128& x) : m_vValue(x) {}
    __forceinline S00c73170_Real(float x) { m_vValue = _mm_load_ss(&x); }
    __forceinline operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __m128 m_vValue;
};
class S00c73170_Vec {
public:
    __forceinline S00c73170_Vec() {}
    __forceinline S00c73170_Vec(const S00c73170_Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void operator=(const S00c73170_Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void set(float a, float b, float c, float d) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    __forceinline float& operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
    __forceinline const float& operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void setAll3(float a) { m_vComponents = _mm_set_ps1(a); }
    __forceinline void setSub4(const S00c73170_Vec& a, const S00c73170_Vec& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setAdd4(const S00c73170_Vec& a, const S00c73170_Vec& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setAbs4(const S00c73170_Vec& v) { m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10); }
    __forceinline void setNeg4(const S00c73170_Vec& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0); }
    __forceinline void setMul4(const S00c73170_Vec& a, const S00c73170_Vec& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setMul4(const S00c73170_Real& r, const S00c73170_Vec& v) { m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents); }
    __forceinline void addMul4(const S00c73170_Real& r, const S00c73170_Vec& v) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents)); }
    __forceinline void addMul4(const S00c73170_Vec& x, const S00c73170_Vec& y) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents)); }
    __forceinline void setAddMul4(const S00c73170_Vec& a, const S00c73170_Vec& x, const S00c73170_Vec& y) { m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents)); }
    __forceinline void setCross(const S00c73170_Vec& v0, const S00c73170_Vec& v1) {
        __m128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline S00c73170_Real dot3(const S00c73170_Vec& a) const {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00c73170_Real length3() const {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        __m128 lenSq = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
        return _mm_sqrt_ss(lenSq);
    }
    __forceinline bool equals3(const S00c73170_Vec& v, float epsilon = 1e-3f) const {
        S00c73170_Vec t;
        t.setSub4(*this, v);
        t.setAbs4(t);
        S00c73170_Vec epsilon_v;
        epsilon_v.setAll3(epsilon);
        return (_mm_movemask_ps(_mm_cmple_ps(t.m_vComponents, epsilon_v.m_vComponents)) & 7) == 7;
    }
    __forceinline bool equals4(const S00c73170_Vec& v, float epsilon = 1e-3f) const {
        S00c73170_Vec t;
        t.setSub4(*this, v);
        t.setAbs4(t);
        S00c73170_Vec epsilon_v;
        epsilon_v.setAll3(epsilon);
        return (_mm_movemask_ps(_mm_cmple_ps(t.m_vComponents, epsilon_v.m_vComponents)) & 15) == 15;
    }
    __forceinline bool equalsV(__m128 v, float epsilon = 1e-3f) const { S00c73170_Vec t; t.m_vComponents=_mm_sub_ps(m_vComponents,v); t.setAbs4(t); S00c73170_Vec epsilon_v; epsilon_v.setAll3(epsilon); return (_mm_movemask_ps(_mm_cmple_ps(t.m_vComponents, epsilon_v.m_vComponents)) & 15) == 15; }
    __forceinline void SetRotatedDirection(const S00c73170_Vec& quat, const S00c73170_Vec& direction);
    __m128 m_vComponents;
};
__forceinline void S00c73170_Vec::SetRotatedDirection(const S00c73170_Vec& quat, const S00c73170_Vec& direction) {
    S00c73170_Vec minusHalf; minusHalf.m_vComponents = DAT_010c71e0;
    S00c73170_Vec qreal; qreal.m_vComponents = _mm_shuffle_ps(quat.m_vComponents, quat.m_vComponents, 0xff);
    S00c73170_Vec q2minus1; q2minus1.setAddMul4(minusHalf, qreal, qreal);
    S00c73170_Vec ret; ret.setMul4(direction, q2minus1);
    S00c73170_Vec imagDotDir; imagDotDir.m_vComponents = quat.dot3(direction).m_vValue;
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    ret.addMul4(imagDotDir, quat);
    S00c73170_Vec imagCrossDir; imagCrossDir.setCross(quat, direction);
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}
__forceinline const S00c73170_Vec& S00c73170_Zero() { return reinterpret_cast<const S00c73170_Vec&>(DAT_01267e30); }
__forceinline void SetInt(int& out,int v){out=v;}
__forceinline bool EqualsV(__m128 a, __m128 b, float epsilon = 1e-3f) { S00c73170_Vec t; t.m_vComponents=_mm_sub_ps(b,a); t.setAbs4(t); S00c73170_Vec epsilon_v; epsilon_v.setAll3(epsilon); return (_mm_movemask_ps(_mm_cmple_ps(t.m_vComponents, epsilon_v.m_vComponents)) & 15) == 15; }
__forceinline void ScaleV(float scale,NiPoint3& out,const NiPoint3& input){out.x=scale*input.x;out.y=scale*input.y;out.z=scale*input.z;}
struct MovementInput {
    float dt, angle, unk08, speed;
    NiPoint3 displacement; unsigned int unk1c;
    float scale; bool active;
};
struct Rotation {
    S00c73170_Vec q;
    void __thiscall hkQuaternion_setAxisAngle(const S00c73170_Vec* axis, float angle);
};
struct State {
    unsigned int unk00;
    int hkpCharacterContext_getState();
};
struct Action {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void update(void*);
};
struct ActionSet { Action* GetIndexedValue_00cbc510(unsigned int); };
struct RefObj { void FUN_00c905b0(); };
struct S00c73170_RefPtr { RefObj* m_p; __forceinline void Clear() { if(m_p) m_p->FUN_00c905b0(); m_p=0; } };
struct BooleanFloatQuery {
    S00c73170_Vec normal, position;
    unsigned int material, unk24;
    struct Block32 { unsigned int a,b,c,d,e,f,g,h; } info;
    unsigned int object, unk4c;
    Block32 extra;
    void InitializeFields_006212c0(const BooleanFloatQuery*);
};
struct Body {
        unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
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
    int mode;
    HitArray* ahkpCharacterProxy_GetCdPoints();
    S00c73170_Vec* hkpCharacterProxy_getPosition();
    void hkpCharacterProxy_setPosition(S00c73170_Vec*);
    void hkpCharacterProxy_setLinearVelocity(S00c73170_Vec*);
};
struct Gravity {     unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
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
    float acceleration;
};
extern Gravity* DAT_01267bb4;
struct AllocatorHolder { unsigned int unk00,unk04,unk08,unk0c; void* allocator; };
AllocatorHolder* hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void*,HitArray*,unsigned int);
__forceinline void HitArray::Append(const BooleanFloatQuery* src) {
    AllocatorHolder* holder=hkMemoryRouter_getInstance();
    if(size==(capacity&0x3fffffff)) ResizeAudioStream(holder->allocator,this,0x70);
    BooleanFloatQuery* dst=data+size;
    if(dst) {
        dst->normal=src->normal;dst->position=src->position;
        dst->material=src->material;dst->unk24=src->unk24;
        dst->info=src->info;
        dst->object=src->object;dst->unk4c=src->unk4c;
        dst->extra=src->extra;
    }
    ++size;
}
void __cdecl FUN_00458620(NiPoint3*,const S00c73170_Vec*);
bool __cdecl AreVectorsEqual(NiPoint3*,NiPoint3*,float);
void __cdecl NI2HK(S00c73170_Vec*,NiPoint3*);
struct Inspect { unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,count; };
struct ReadyInterface {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual int Ready();
};
struct MovementController {
        unsigned int unk000;
    unsigned int unk004;
    Body* body;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
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
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    State state;
    unsigned int unk3e4;
    unsigned int unk3e8;
    ActionSet* actions;
    unsigned int actionIndex;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    S00c73170_Flags fl;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    float value430;
    unsigned int value434;
    unsigned int value438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    S00c73170_Vec value450;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned char byte478,unk479,unk47a,unk47b;
    unsigned int unk47c;
    unsigned int value480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    S00c73170_Vec value4a0;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    S00c73170_Vec axis;
    S00c73170_Vec normal;
    unsigned int value4e0;
    unsigned int unk4e4;
    float time4e8;
    float inverse4ec;
    S00c73170_Vec velocity;
    S00c73170_Vec extraVelocity;
    S00c73170_Vec desiredVelocity;
    unsigned int value520;
    float value524;
    float value528;
    float value52c;
    float value530;
    unsigned int unk534;
    float value538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    float scale568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    float value578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    S00c73170_RefPtr ref630;
    float value634;
    S00c73170_RefPtr ref638;
    HitArray hits;
    void SubtractVectors(S00c73170_Vec*);
    void SetPosition_005620e0(NiPoint3*);
    void ClearList();
    Inspect* bhkCharacterController_GetWorld();
    void bhkCharacterController_ClearPush();
    void bhkCharacterController_ChangeSize(float);
    float Evaluate(float,float);
    unsigned char bhkCharacterController_GetIsSwimming();
    unsigned char bhkCharacterController_GetUseZ();
    void bhkCharacterController_ApplyPitchAndRoll(Rotation*);
    S00c73170_Vec* bhkCharacterProxy_GethkLinearVelocity();
    Action* FUN_00933810();
    void bhkCharacterProxy_SetLinearVelocity(S00c73170_Vec*);
    void bhkCharacterController_MoveAsProjectile(float);
    void bhkCharacterController_InitFrontBack();
    void CallTargetWithArgs(S00c73170_Vec*,unsigned int*);
    void bhkCharacterProxy_Integrate(unsigned int*);
    void bhkCharacterController_UnMarkWrite();
    Body* Bipedanim_GetReferenceFlagsOrZero();
    void bhkCharacterController_CalculatePitchAndRoll();
};
// @fnv 0x00c73170
// src: XBOX_PDB 0x00c73170
extern "C" int __fastcall bhkCharacterController_Move(MovementController* self, void*, MovementInput* in) {
    int result=0;
    struct SpeedTrace { float value; } speedTrace;
    Rotation rot;
    if (self->state.hkpCharacterContext_getState()==4) {
        Trace(str_010c4ad8);
        NiPoint3 temp;
        {
        S00c73170_Vec position;
        self->SubtractVectors(&position);
        FUN_00458620(&temp,&position);
        }
        AddMovement(temp,in->displacement);
        self->SetPosition_005620e0(&temp);
        self->actions->GetIndexedValue_00cbc510(self->actionIndex)->update(self);
        NiPoint3* v;
        if(in->dt>0) {
            ScaleV(1.0f/in->dt,temp,in->displacement);
            v=&temp;
        } else v=&DAT_011f426c;
        double x=v->x;
        _ReadWriteBarrier();
        double scale=DAT_01267bcc;
        self->velocity(0)=x*scale;
        self->velocity(1)=v->y*scale;
        self->velocity(2)=v->z*scale;
        self->velocity(3)=0;
        Trace(str_010c41f8);
        return 0;
    }
    self->fl.Clear(0xc0);
    self->ClearList();
    self->ref630.Clear();
    self->value634=0;
    self->ref638.Clear();
    self->scale568=in->scale/DAT_01267bc4;
    float dt=in->dt;
    int ready=((ReadyInterface*)self)->Ready();
    bool skip=in->dt<=DAT_01032980 || !ready;
    if(!skip) {
    if(self->fl.Bit(22)) {
        if(self->bhkCharacterController_GetWorld()->count>0) goto done;
        self->fl.Clear(0x400000);
    }
    bool idle=AreVectorsEqual(&in->displacement,&DAT_011f426c,DAT_010181bc);
    bool mode20=self->fl.Bit(20);
    bool mode19=self->fl.Bit(19);
    if(!idle) { self->bhkCharacterController_ClearPush(); self->value528=0;self->value52c=0; }
    idle &= self->extraVelocity.equals3(S00c73170_Zero());
    if(!idle) self->fl.Or(8); else self->fl.Clear(8);
    Trace(str_010c4ac0);
    {
    S00c73170_Vec negAxis;
    self->bhkCharacterController_ChangeSize(dt);
    self->value434=0x24; self->value438=0;
    float speed=self->Evaluate(in->speed,in->dt);
    in->speed=speed;
    rot.hkQuaternion_setAxisAngle(&self->axis,-speed);
    self->time4e8=in->dt;
    self->inverse4ec=1.0f/in->dt;
    NiPoint3* displacement=&in->displacement;
    {
        NiPoint3 tempStore=*displacement;
        NiPoint3& temp=tempStore;
        if(!self->bhkCharacterController_GetIsSwimming() && !self->fl.Bit(11)) temp.z=0;
        temp.y=temp.y;
        float& reciprocal=speedTrace.value;
        reciprocal=self->inverse4ec;
        temp*=reciprocal;
        NI2HK(&self->desiredVelocity,&temp);
    }
    if(self->bhkCharacterController_GetUseZ() && in->angle!=0) {
        S00c73170_Vec axisAngle; axisAngle.set(-1.0f,0.0f,0.0f,0.0f);
        Rotation q;
        q.hkQuaternion_setAxisAngle(&axisAngle,in->angle);
        self->desiredVelocity.SetRotatedDirection(q.q,self->desiredVelocity);
    }
    float* stepOut=&self->value578;*stepOut=self->value538;
    S00c73170_Vec down; down.set(0.0f,-1.0f,0.0f,0.0f);
    negAxis.setNeg4(self->axis);
    if(self->fl.Bit(25) || self->fl.Bit(26) || self->fl.Bit(0)) self->bhkCharacterController_ApplyPitchAndRoll(&rot);
    S00c73170_Vec rotated; rotated.SetRotatedDirection(rot.q,down);
    if(!idle || !rotated.equals3(self->normal)) self->value530=DAT_011b014c;
    Body* savedBody=self->body;
    self->normal=rotated;
    if(mode19) {
        self->velocity=*self->bhkCharacterProxy_GethkLinearVelocity();
        self->value4a0=S00c73170_Zero();
        Trace(str_010c4ad8);
        self->FUN_00933810()->update(self);
        Trace(str_010c41f8);
        self->bhkCharacterProxy_SetLinearVelocity(&self->velocity);
        self->bhkCharacterController_MoveAsProjectile(self->time4e8);
    } else {
        DAT_01267bb4=0;
        self->velocity=*self->bhkCharacterProxy_GethkLinearVelocity();
        if(idle && self->state.hkpCharacterContext_getState()!=2) self->velocity(2)=0;
        if(in->active || self->state.hkpCharacterContext_getState()!=0 || !displacement->HasEqualComponents(DAT_011f426c) || self->value450.equals4(S00c73170_Zero())) {
            self->fl.Clear(0x600);
            self->fl.Or(0x10000);
            self->bhkCharacterController_InitFrontBack();
            self->CallTargetWithArgs(&negAxis,&self->value480);
            self->fl.Clear(0x10000);
            bool contact=self->value480==2 && !self->byte478;
            if(self->fl.value&0x2000) {
                if(!(contact || self->fl.Bit(9)) || self->velocity(2)<=0) { self->fl.Clear(0x2000); contact=false; }
                else {
                    S00c73170_Vec v=self->velocity;
                    float length=v.length3();
                    if(length>0) {
                        S00c73170_Real inv=1.0f/length;
                        if(contact && self->fl.Bit(9) && self->value450(2)>=self->value430) {
                            S00c73170_Vec dir; dir.setMul4(inv,v);
                            float dot=dir.dot3(self->value450);
                            if(dot<=DAT_0103c7c8) self->fl.Clear(0x2000);
                        }
                    }
                    contact=false;
                }
            } else contact|=self->fl.Bit(9);
            self->fl.Set(0x100,contact);
        }
        Trace(str_010c4ad8);
        self->actions->GetIndexedValue_00cbc510(self->actionIndex)->update(self);
        Trace(str_010c41f8);
        if(self->body) self->body->hkpCharacterProxy_setLinearVelocity(&self->velocity);
        bool changed=true;
        if(idle && self->state.hkpCharacterContext_getState()!=2 && (self->state.hkpCharacterContext_getState()!=5 || self->velocity(2)==0) && savedBody->ahkpCharacterProxy_GetCdPoints()->size<=self->hits.size) {
            changed=false;
            for(int i=0;!changed;++i) {
                HitArray* loopArray=savedBody->ahkpCharacterProxy_GetCdPoints();
                if(i>=loopArray->size) break;
 HitArray* currentArray=savedBody->ahkpCharacterProxy_GetCdPoints();
 if(!EqualsV(currentArray->data[i].normal.m_vComponents,self->hits.data[i].normal.m_vComponents)) changed=true;
 else {
 currentArray=savedBody->ahkpCharacterProxy_GetCdPoints();
 BooleanFloatQuery* previous=&self->hits.data[i];
 S00c73170_Vec pos=self->hits.data[i].position;
 if(!pos.equals4(currentArray->data[i].position) ||
                       previous->material!=savedBody->ahkpCharacterProxy_GetCdPoints()->data[i].material) changed=true;
                    else {
                        BooleanFloatQuery& previousObject=self->hits.data[i];
                        if(previousObject.object!=savedBody->ahkpCharacterProxy_GetCdPoints()->data[i].object) changed=true;
                    }
                }
            }
        }
        if(changed) {
            if(mode20) savedBody->mode=1;
            else savedBody->mode=4;
            self->bhkCharacterProxy_Integrate(&self->value4e0);
            savedBody->mode=4;
        } else {
            self->velocity=S00c73170_Zero();
            if(self->body) self->body->hkpCharacterProxy_setLinearVelocity(&self->velocity);
        }
        if(DAT_01267bb4 && !(self->fl.value&0x2000)) {
            self->bhkCharacterController_UnMarkWrite();
            Body* target=self->Bipedanim_GetReferenceFlagsOrZero();
            S00c73170_Vec position=*target->hkpCharacterProxy_getPosition();
            float gravity=DAT_01267bb4->acceleration*self->time4e8;
            position(2)=self->value578+DAT_01267bb0+gravity;
            target->hkpCharacterProxy_setPosition(&position);
            position(2)=gravity+DAT_01267bb0;
            self->bhkCharacterController_UnMarkWrite();
        }
        self->value520=11;
        int size=savedBody->ahkpCharacterProxy_GetCdPoints()->size;
        int n=size>5?5:size;
        for(int i=0;i<n;++i) {
            if(i<self->hits.size) self->hits.data[i].InitializeFields_006212c0(&savedBody->ahkpCharacterProxy_GetCdPoints()->data[i]);
            else {
                self->hits.Append(&savedBody->ahkpCharacterProxy_GetCdPoints()->data[i]);
            }
        }
    }
    }
    if(self->fl.Bit(25) || self->fl.Bit(26)) self->bhkCharacterController_CalculatePitchAndRoll();
    if(self->fl.value&0xc0) SetInt(result,2);
    Trace(str_010c41f8);
    if(self->value524>0) {
        float remaining=self->value524-dt;
        self->value524=remaining;
        if(remaining<=0) { self->value524=0; self->extraVelocity.setZero4(); }
    }
    if(self->value530>0) self->value530-=dt;
    self->fl.Clear(0x1000);
    done: ;
    }
    return result;
}
