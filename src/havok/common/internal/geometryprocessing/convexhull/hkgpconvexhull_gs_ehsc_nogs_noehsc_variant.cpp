#include <xmmintrin.h>
typedef ::__m128 LocalM128;
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

#include "fnv_asm_helpers.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/NiPoint3.h"
#include "../../../../../../include/Vec4.h"
// local form of hkVector4: 0x00d75cb0 needs original packet calls (shared extent 447 vs 384).


// Define FNV_VECTOR_USE_LOCAL_SSE when __m128 and intrinsics are already declared.
#if !defined(FNV_VECTOR_USE_LOCAL_SSE)
#include <xmmintrin.h>
#endif

class Scalar;
class Comparison;
class Transform;
class hkRotation;

class HullVectorCallLocal_00d75cb0
{
public:
    union
    {
        LocalM128 q;
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };

    __forceinline HullVectorCallLocal_00d75cb0() {}
    __forceinline HullVectorCallLocal_00d75cb0(const HullVectorCallLocal_00d75cb0& vector) : q(vector.q) {}
    __forceinline HullVectorCallLocal_00d75cb0(const LocalM128& vector) : q(vector) {}
    HullVectorCallLocal_00d75cb0(float x, float y, float z);
    __forceinline HullVectorCallLocal_00d75cb0& operator=(const HullVectorCallLocal_00d75cb0& vector)
    {
        q = vector.q;
        return *this;
    }
    __forceinline void operator=(const LocalM128& vector)
    {
        q = vector;
    }
    operator LocalM128() const;
    HullVectorCallLocal_00d75cb0 operator*(float value) const;
    HullVectorCallLocal_00d75cb0 operator+(const HullVectorCallLocal_00d75cb0& vector) const;
    HullVectorCallLocal_00d75cb0 operator-() const;
    float& operator()(int index);
    const float& operator()(int index) const;
    LocalM128& packet();
    const LocalM128& packet() const;

    void set(float x, float y, float z, float w = 0.0f);
    void zero();
    void setZero4();
    void subtract(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b);
    void sub(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b);
    void setSub(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b);
    void setSub4(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b);
    void add(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b);
    void setAdd(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b);
    void setAdd4(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b);
    void add4(const HullVectorCallLocal_00d75cb0& vector);
    void mul(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b);
    void mul4(const HullVectorCallLocal_00d75cb0& vector);
    void mul4(const Scalar& scalar);
    void multiply(const Scalar& scalar);
    void scale(const Scalar& scalar);
    void product(const Scalar& scalar, const HullVectorCallLocal_00d75cb0& vector);
    void cross(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b);
    void setCross(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b);
    void negate(const HullVectorCallLocal_00d75cb0& vector);
    void setNeg4(const HullVectorCallLocal_00d75cb0& vector);
    void addMul(const HullVectorCallLocal_00d75cb0& a, LocalM128 scale, const HullVectorCallLocal_00d75cb0& b);
    void setAddMul4(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b, const Scalar& scalar);
    void interpolate(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b, const Scalar& t);
    void setInterpolate4(const HullVectorCallLocal_00d75cb0& a, const HullVectorCallLocal_00d75cb0& b, const Scalar& t);
    void Interpolate(const HullVectorCallLocal_00d75cb0& oldValue, const HullVectorCallLocal_00d75cb0& newValue, float factor);
    void SetTransformedPoint(const Transform& transform, const HullVectorCallLocal_00d75cb0& point);

    Scalar getSimdAt(int index) const;
    Scalar dot(const HullVectorCallLocal_00d75cb0& vector) const;
    Scalar dot3(const HullVectorCallLocal_00d75cb0& vector) const;
    float DotProduct(const HullVectorCallLocal_00d75cb0& vector);
    Scalar sum() const;
    Scalar norm() const;
    Scalar lengthSquared3() const;
    Scalar length3() const;
    float length() const;
    Scalar inverseLength() const;
    void normalize();
    void normalize3();
    Comparison compareLessThanZero4() const;
    int getMajorAxis() const;
    int maxAxisSecond() const;
    int maxAxis() const;
    float GetAngle();

    void SetComponents(float x, float y, float z);
    HullVectorCallLocal_00d75cb0 SubtractIntoVector(const HullVectorCallLocal_00d75cb0& vector);
    HullVectorCallLocal_00d75cb0 FUN_00439e90(const HullVectorCallLocal_00d75cb0& vector);
    void ScaleComponents(float value);
    void Unitize_004a0c10();
    void normalize_005611c0();
    void setMul(const HullVectorCallLocal_00d75cb0* a, const HullVectorCallLocal_00d75cb0* b);
    void setMulInverse(const HullVectorCallLocal_00d75cb0* a, const HullVectorCallLocal_00d75cb0* b);
    void hkQuaternion_getAxis(HullVectorCallLocal_00d75cb0* vector);
    void setTransformedPos_00c7f640(const Transform& transform, const HullVectorCallLocal_00d75cb0& point);
    void hkQuaternion_setAxisAngle(const HullVectorCallLocal_00d75cb0* vector, float value);
    void FUN_00cb26e0(const hkRotation* rotation);

    template <int I> void splat(const HullVectorCallLocal_00d75cb0& vector);

    static const HullVectorCallLocal_00d75cb0& getZero();
};

#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkVector4.h"
#include <string.h>
// src/havok/common/internal/geometryprocessing/convexhull/hkgpconvexhull_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/internal/geometryprocessing/convexhull/hkgpconvexhull.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/geometryprocessing/convexhull/hkgpconvexhull.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/convexhull/hkgpconvexhull.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00d74dd0_Class {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void hkgpConvexHull_deleteUserObject();
};
struct FUN_00d7ac40_class {
    void hkgpConvexHullImpl_reset(int);
};
struct FUN_00d75850_class {
    int m0;
    int m1;
    FUN_00d7ac40_class* m2;
    int m3;
    int m4;
    void hkgpConvexHull_reset();
};
int __stdcall hkgpConvexHull_getNeighbour(const int* p, int i);
struct FUN_00d7c200_cls { void __thiscall FreeAll(); };
struct FUN_00d7c950_cls {
    void __thiscall ProcessState_00d7c950();
};
int __stdcall hkgpConvexHull_getVertex(int* arr, int idx);
struct CpuScalar {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    int value;
};
struct CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    CpuScalar* value;
    int GetNestedValue();
};
struct ValueBlock {
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
};
struct Implementation {
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
    ValueBlock m_kValue;
};
struct FUN_00d74e50_cls {
    int unk00;
    int unk04;
    Implementation* m_pImpl;

    ValueBlock GetValueBlock();
};
struct PayloadOwner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iPayload;
};
int* __stdcall Hkgpconvexhull_GetPayloadAddress(PayloadOwner* apOwner);
struct TargetCallee {
    void ProcessEntries_00d7a5a0(void* p1, void* p2, void* p3, void* p4, float p5);
};
struct FUN_00d74ee0_Class : FUN_00d74dd0_Class {
    void ForwardToCallee(void* p1, void* p2, void* p3, void* p4, float p5);
};
struct D75060Inner {
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
};
struct D75060Outer {
    int unk00;
    int unk04;
    D75060Inner* unk08;

    int GetUnk24_00d75060();
};
struct TextBuffer {
    int unk00;
    int unk04;
    int unk08;
    int storage[128];
    void FUN_00cb1600(char* buffer, int capacity);
    TextBuffer* ProcessAndReturnValue_00cc01c0(const char* first, const char* middle, const char* last);
    TextBuffer* ProcessAndReturnValue_00cc01c0();
    TextBuffer* EvaluateValue_00cc02d0();
    void FUN_00cc00e0();
};
struct ChildData {
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
    char unk1b4;
    char flag1b5;
};
struct Request {
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
};
struct ErrorReporter {
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual int message(int type, int hash, const char* text, const char* file, int line);
};
extern ErrorReporter* DAT_01268360;
void __debugbreak();
struct Owner {
    int unk00;
    int unk04;
    ChildData* unk08;
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
    int hkgpConvexHull_getIndex(Request* request);
};
int __stdcall Object_ReadPointedValue_00d75120(int* p);
struct D75130Inner {
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
};
struct D75130Outer {
    int unk00;
    int unk04;
    D75130Inner* unk08;

    int EvaluateValue_00d75130();
};
int __stdcall Object_ReadPointedValue_00d75200(const int* value);
struct S_00d75210_ErrStream {
    void* m_vt;
    int unk04;
    int unk08;
    S_00d75210_ErrStream(void* buf, int bufSize) throw();
    ~S_00d75210_ErrStream() throw();
    S_00d75210_ErrStream& operator<<(const char* s) throw();
    S_00d75210_ErrStream& operator<<(unsigned int u) throw();
};
struct S_00d75210_Error {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};
extern S_00d75210_Error* g_hkError;
struct S_00d75210_Data {
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
    int m_uiEdgeIndex;
};
struct S_00d75210_Config {
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
    unsigned int m_1b0;
    char unk1b4;
    bool m_hasIndex;
};
struct S_00d75210_Self {
    int unk00;
    int unk04;
    S_00d75210_Config* m_pConfiguration;
    int hkgpConvexHull_getPlaneIndex(const S_00d75210_Data* v) const throw();
};
struct D762F0Target {
    void update();
};
struct D762F0Owner {
    int unk00;
    int unk04;
    D762F0Target* m_target;

    void ForwardCall_00d762f0();
};
struct D76910Inner { void ProcessEntries_00d7cf00(); };
struct D76910Owner {
    int unk00;
    int unk04;
    D76910Inner* inner;
    void ForwardCall_00d76910();
};
struct FUN_00d76990_State {
    int unk00;
    float unk04;
    void ProcessEntries_00d7d2a0();
};
struct FUN_00d76990_Class {
    int unk00;
    int unk04;
    FUN_00d76990_State* unk08;
    void SetValue(float value, bool clearFlag);
};
using ::_mm_setr_ps;
struct __declspec(align(16)) hkVec4 {
    float x, y, z, w;
};
struct Shape {
    float ComputeValues_00d768b0(const hkVec4& v);
    float ProcessAndReturnValue_00d76840(const hkVec4& v);
    float ProcessAndReturnValue_00d769c0(const NiPoint3& p);
};
struct AudioSink {
    void hkgpConvexHullImpl_generateIndexedFaces_int_int(void* apFirst, void* apSecond, bool abIsNull, void* apThird);
};
struct FUN_00d76c50_cls {
    int unk00;
    int unk04;
    AudioSink* m_pSink;

    void DispatchToSink(void* apKey, void* apFirst, void* apSecond, void* apThird);
};
struct Vec4i {
    int x, y, z, w;
};
struct FUN_00d81510_Class {
    Vec4i m_00;
    void hkgpConvexHullImpl_build(int a, int b, int c, int d);
};
struct FUN_00d771c0_Owner {
    int unk00;
    int unk04;
    FUN_00d81510_Class* unk08;
    void hkgpConvexHull_build(int a, int b, const Vec4i& v);
};
struct FUN_00d83430_class {
    void AllocateStorage_00d83430(int, int, int, float);
};
struct FUN_00d790a0_class {
    int unk00;
    int unk04;
    FUN_00d83430_class* unk08;
    void hkgpConvexHull_splitByPlane(int a, int b, int c, float d);
};
struct S_00d79f90_Opts
{
    int mode;
    float value;
    S_00d79f90_Opts();
};
struct S_00d79f90_Result
{
    virtual ~S_00d79f90_Result();
    void ProcessEntries_00d78720(float f, const S_00d79f90_Opts& opts);
};
struct S_00d79f90_World
{
    S_00d79f90_Result* hkgpConvexHull_clone();
};
void __cdecl HkgpconvexhullGsEhscNogsNoehsc_ReleaseStorage_00d79ab0(S_00d79f90_World* world, int a, void* b, float c);
void __cdecl hkgpConvexHull_booleanSubtraction_00d79580(S_00d79f90_Result* res, void* b, int n, float eps);
void __cdecl hkgpConvexHull_createVoronoiFeatures(S_00d79f90_World* world, int a, void* b, int n, float d);
struct S_00d7a010_Alloc {
    virtual void unk0();
    virtual void unk4();
    virtual void ReleaseBlock(void* p, int n);
    virtual void unkc();
    virtual void ReturnMemory(void* p, int n) throw();
};
struct S_00d7a010_Router {
    int unk0; int unk4; int unk8; int unkc;
    S_00d7a010_Alloc* m_pStreamAllocator;
    static S_00d7a010_Router& hkMemoryRouter_getInstance() throw();
    S_00d7a010_Alloc& heap() throw() { return *m_pStreamAllocator; }
};
template <typename T>
struct S_00d7a010_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00d7a010_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline void _clearAndDeallocate(S_00d7a010_Alloc& a) throw() {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
};
struct S_00d7a010_Obj {
    virtual ~S_00d7a010_Obj() throw();
    void operator delete(void* p) throw();
};
void __cdecl hkgpConvexHull_createVoronoiFeatures(int a, int b, S_00d7a010_Array<S_00d7a010_Obj*>& out, int c, float f) throw();
void __cdecl DeleteCollectedObjects(int a, int b, int c, float f);
struct S_00d7c200_Heap {
    virtual void v0();
    virtual void v1();
    virtual void ReleaseBlock(void* p, int nbytes);
};
struct S_00d7c200_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d7c200_Heap* m_pStreamAllocator;
    static S_00d7c200_Router& GetMonitorStream();
    S_00d7c200_Heap& heap() { return *m_pStreamAllocator; }
};
struct S_00d7c200 {
    void** m_kBlocks;
    int m_iBlockCount;
    int unk8;
    int unkC;
    int unk10;
    void FreeAll();
};
struct S_00d7c340_Allocator {
    virtual void vfn_00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct S_00d7c340_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d7c340_Allocator* unk10;
    S_00d7c340_Allocator* heap() { return unk10; }
};
S_00d7c340_Router* hkMemoryRouter_getInstance();
int ResizeAudioStream(S_00d7c340_Allocator* alloc, void* array, int elemSize);
struct S_00d7c340_Elem {
    S_00d7c340_Elem* next;
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44;
};
struct S_00d7c340_Block {
    S_00d7c340_Elem elems[32];
    S_00d7c340_Elem* freeList;
    int numUsed;
};
struct S_00d7c340 {
    S_00d7c340_Block** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00d7c340_Block* AllocateBlock();
};
struct UnknownBlock {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};
struct Node {
    Node *link0;
    Node *link4;
    void *unk08;
    void *unk0c;
    int value10, value14, value18, value1c, value20, value24, value28;
    float value2c;
    int value30, value34;
};
struct NodeBank {
    UnknownBlock unk000, unk040, unk080, unk0c0, unk100, unk140, unk180, unk1c0;
    UnknownBlock unk200, unk240, unk280, unk2c0, unk300, unk340, unk380, unk3c0;
    UnknownBlock unk400, unk440, unk480, unk4c0, unk500, unk540, unk580, unk5c0;
    UnknownBlock unk600, unk640, unk680, unk6c0, unk700, unk740, unk780, unk7c0;
    Node *freeHead;
    int allocated;
};
struct PoolList {
    NodeBank **banks;
    int bankValid;
    void *unk08;
    Node *head;
    int activeCount;
    NodeBank *hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_allocateNewPool();
    Node *CloneNode(Node *source);
};
extern float DAT_0106ea1c;
class FUN_00d74d40_cls
{
public:
    unsigned char m_00;
    float m_04;
    volatile unsigned char m_08;
    volatile unsigned char m_09;
    volatile unsigned char m_0a;
    volatile unsigned char m_0b;
    volatile unsigned char m_0c;
    volatile unsigned char m_0d;

    FUN_00d74d40_cls* hkgpConvexHull_BuildConfig_BuildConfig();
};
struct FUN_00d74d70_cls {
    int m_00;
    unsigned char m_04;
    float m_08;
    float m_0c;
    unsigned char m_10;
    unsigned char m_11;
    FUN_00d74d70_cls* hkgpConvexHull_SimplifyConfig_SimplifyConfig();
};
extern float DAT_0104da4c;
struct FUN_00d74d90_cls {
    int m_i00;
    float m_f04;

    FUN_00d74d90_cls* InitializeFields_00d74d90();
};
struct SpawnedInner {
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
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int m_i1a8;
};
struct FUN_00d74e10_cls {
    int unk00;
    int unk04;
    SpawnedInner* m_pInner;

    int GetInnerField1A8();
};
struct FUN_00d74e20_class {
    void* m_00; void* m_04; char* m_08;
    hkVector4 __thiscall GetFieldAtD0();
};
struct Inner {
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
    int m_i28;
};
struct FUN_00d75050_cls {
    int unk00;
    int unk04;
    Inner* m_pInner;

    int EvaluateValue_00d75050();
};
struct FUN_00d7a180_target {
    void ProcessEntries_00d7a180();
};
struct FUN_00d752d0_cls {
    void* m_00;
    void* m_04;
    FUN_00d7a180_target* m_08;
    void ForwardCall_00d752d0();
};
struct DiagStream {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_buf[128];
    void FUN_00cb1600(unsigned int* buf, unsigned int size);
    DiagStream* ProcessAndReturnValue_00cc01c0(const char* fmt, unsigned int count, const char* tail);
    DiagStream* EvaluateValue_00cc02d0();
    void ProcessAndReturnValue_00cc01c0();
    void FUN_00cc00e0();
};
struct DiagLogger {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Report(int level, unsigned int hash, char* msg, const char* file, int line);
};
extern DiagLogger* g_diagLogger;
struct DiagState {
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    float m_1a4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int m_1b0;
    unsigned char m_1b4;
};
struct FUN_00d75390_cls {
    unsigned int unk00;
    unsigned int unk04;
    DiagState* m_08;
    float GetMass();
};
extern "C" double __cdecl pow(double base, double exponent);
extern const double DAT_010d35e8;
extern const double DAT_010d35e0;
struct FUN_00d75440_cls {
    float hkgpConvexHull_getVolume();
    double GetMass();
    float ComputeScaledPowerRatio();
};
struct FUN_00d75820_Tmp8 {
    int m00;
    int m04;
};
struct FUN_00d75820_Target {
    void ProcessEntries_00d7a200(int a, float b, FUN_00d75820_Tmp8* c, int d);
};
struct FUN_00d75820_cls {
    int m00;
    int m04;
    FUN_00d75820_Target* m08;

    void CallTargetWithTemp(int a1, float a2, int a3);
};
struct FUN_00d7b330_cls {
    void ProcessEntries_00d7b330(int a1, int a2, float a3);
};
struct FUN_00d76100_cls {
    void* unk00;
    void* unk04;
    FUN_00d7b330_cls* m_08;
    void hkgpConvexHull_isPointInside(int a1, int a2, float a3);
};
struct FUN_00d7caa0_class {
    void __thiscall ProcessEntries_00d7caa0(float, int);
};
struct FUN_00d76920_class {
    void* m_00;
    void* m_04;
    FUN_00d7caa0_class* m_08;
    void hkgpConvexHull_fetchBevelPlanes(float, int);
};
struct SpawnedObject {
    void* m_00;
    void* m_04;
    void* m_08;
};
struct TailCallee {
    void Tail();
};
class FUN_00d77bc0_cls {
public:
    void UpdateFields_00d77bc0();
};
struct ArgPair
{
    int m_kPointA;
    int m_kPointB;
};
void __cdecl hkgpConvexHull_createCompound(int first, ArgPair* apPairs, int count);
void __cdecl CallWithPair(int a0, int a1, int a2);
struct D79090Target {
    void update();
};
struct D79090Owner {
    int unk00;
    int unk04;
    D79090Target* m_target;

    void ForwardCall_00d79090();
};
// FUN_00d79510 (0x00d79510, 102 bytes)
//
// The function walks the item table of a record and asks every item to
// "do it" (the virtual at vtable slot 0, called with the argument 1).
// Before that it hands the record to FUN_00d79250 (0x00d79250) with five
// arguments: the two leading pointers, the address of the third parameter
// (the callee clears *arg3), the record itself (the callee clears the
// record's +4 field) and the float.
//
// The callee is only DECLARED here on purpose: the checker then binds the
// call relocation to the original's own target 0x00d79250.
// an item of the table: a virtual at vtable slot 0
struct FUN_00d79510_Item {
    virtual void FUN_00d79510_doIt(int);
};
// the record the table lives in: the item array at +0, the count at +4
struct FUN_00d79510_Record {
    FUN_00d79510_Item** m_00;
    int m_04;
};
// the third parameter: an object with a virtual at vtable slot 0
struct FUN_00d79510_Object {
    virtual void FUN_00d79510_doIt(int);
    int m_04;
};
struct FUN_00d79510_A;
struct FUN_00d79510_B;
void __cdecl FUN_00d79250_helper(FUN_00d79510_A* a, FUN_00d79510_B* b,
                                 FUN_00d79510_Object** out, void* p, float f);
bool __cdecl hkgpConvexHull_booleanSubtraction(FUN_00d79510_A* a, FUN_00d79510_B* b, FUN_00d79510_Object* c, float f);
static int SortKeyOf(void* p)
{
    return ((int*)p)[0xe];
}
void __cdecl QuickSortByKey(void** arr, int lo, int hi, int ctx);
struct RandomGenerator {
    unsigned int stateFlags;
    unsigned int seed;
    void hkPseudoRandomGenerator_getRandomVector11(float* components);
};
struct Record {
    unsigned int payload;
    float key;
};
static __forceinline bool Greater(const Record &a,const Record &b) { return a.key-b.key>0.0f; }
// @fnv 0x00d7b270
// src: HAVOK_LIB 0x00d7b270
extern "C" void hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedTriangle_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedTriangle(Record* records, int left, int right, int context)
{
    int i;
    int j;
    __declspec(align(16)) Record pivot;

    for (;;) {
        i = left;
        j = right;
        pivot = records[(left + right) >> 1];

        do {
            while (Greater(records[i],pivot)) {
                ++i;
            }
            while (Greater(pivot,records[j])) {
                --j;
            }
            if (j >= i) {
                if (j != i) {
                    Record temp = records[j];
                    records[j] = records[i];
                    records[i] = temp;
                }
                --j;
                ++i;
            }
        } while (i <= j);

        if (left < j) {
            hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedTriangle_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedTriangle(records, left, j, context);
        }
        if (i >= right) {
            return;
        }
        left = i;
    }
}

// The script object that receives the queued elements: its third virtual
// function is the one that is called with the element and the command id.
struct ScriptHandler {
    virtual void v00();
virtual void v01();
virtual void v02(void* element, int command);
};
// What FUN_00c85750() hands back: the audio system object, whose field at
// offset 0x10 is the script handler that owns the vtable.
struct AudioSystem {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    ScriptHandler* m_10;
};
// FUN_00d7c2a0 - create a new object of type 0x808 and append it to the
// item list of this container.
//
// The container keeps an array of item pointers (m_00), the number of items
// (m_04) and a capacity/flags field (m_08).  The new object is allocated
// through the creation interface found at offset 0x10 of the global manager;
// the object itself starts with a free list of 32 linked 64 byte blocks.
struct GlobalManager {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
};
// The creation interface: slot 1 takes the object type id and returns a
// freshly allocated object of that type.
struct CreateIface {
    virtual void* v0();
    virtual void* v1(int);
};
void __cdecl ResizeAudioStream(void*, void*, int);
// A writable handle for one slot of the item array.
struct SlotRef {
    void** m_slot;
    void operator=(void* p) { *m_slot = p; }
};
static __forceinline SlotRef MakeSlot(void** a, int i) { SlotRef r; r.m_slot = a + i; return r; }
struct FUN_00d7c2a0_cls {
    void** m_00;
    int m_04;
    int m_08;
    void* hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_allocateNewPool();
};
// Candidate for ClearAndFlush (115 bytes).
//
// Reconstructed shape (from the original bytes):
//
//   this+0x00  void**   an array of element pointers
//   this+0x04  int      the number of elements
//   this+0x08  unsigned a size/flag word: bit 31 marks "already handed over",
//                        the low 30 bits hold an element count
//
//   the service object lives at holder+0x10 and is polymorphic.  Slot 0x08 is
//   called once per element with (element, 0x808), slot 0x10 is called once
//   with (data, byte size) when the buffer has not been handed over yet.
//
// The two "count = 0" stores and the "array = 0" store are immediate stores:
// the zero constant would have to be live across the calls, so MSVC 2008 does
// not materialise it in a register.
struct D7C850_Target {
    virtual void v_dummy0();
    virtual void v_dummy1();
    virtual void v1(void* element, unsigned int flags);   // vtable offset 0x08
    virtual void v_dummy2();
    virtual void v2(void* data, unsigned int size);        // vtable offset 0x10
};
struct D7C850_Holder {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    D7C850_Target* m_10;
};
struct D7C850_Class {
    void** m_00;
    int m_04;
    unsigned int m_08;
    void ClearAndFlush();
};
extern char DAT_0103d078;
struct RetBlock64
{
	LocalM128 m_v0;
	LocalM128 m_v1;
	LocalM128 m_v2;
	LocalM128 m_v3;
};
struct RetBlock16
{
	LocalM128 m_v0;
};
struct SharedOwner
{
	int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
	int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
	int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
	int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
	int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
	int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
	int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
	int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
	int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
	LocalM128 m_v120;
	LocalM128 m_v130;
	LocalM128 m_v140;
	LocalM128 m_v150;
	LocalM128 m_v160;
	int unk170, unk174, unk178, unk17C;
	int unk180, unk184, unk188, unk18C;
	int unk190, unk194, unk198, unk19C;
	int unk1A0, unk1A4, unk1A8, unk1AC;
	int m_i1B0;
	unsigned char m_b1B4;
};
class DbgStr_cls
{
public:
	int unk00;
	int unk04;
	int unk08;
	void Init(char *buf, int size);
	DbgStr_cls *Append(const char *pszPrefix, int value, const char *pszSuffix);
	DbgStr_cls *Pad(void);
	DbgStr_cls *Last(void);
	void Release(void);
};
class AssertMgr_cls
{
public:
	virtual void vtbl00(void);
	virtual void vtbl04(void);
	virtual void vtbl08(void);
	virtual int vtbl0C(int level, unsigned int id, char *buf, const char *file, int line);
};
class FUN_00d75490_cls
{
public:
	int unk00;
	int unk04;
	SharedOwner *m_pSharedOwner;
	void GetMassProperties(RetBlock64 *pOut64, RetBlock16 *pOut16);
};
struct D76250Allocator;
struct D76250MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D76250Allocator* m_pStreamAllocator;

    D76250Allocator& heap() { return *m_pStreamAllocator; }
};
namespace fnvc_adapt { extern "C" D76250MemoryRouter& __cdecl hkMemoryRouter_getInstance(); }
void __cdecl hkArrayUtil__reserve(D76250Allocator* alloc, void* array, int numElements, int sizeElem);

struct D76250VectorArrayLocalForm { // local form of hkArray: 0x00d774a0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    hkVector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void reserve(D76250Allocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(hkVector4));
        }
    }

    hkVector4* expandBy(int n)
    {
        D76250Allocator& alloc = fnvc_adapt::hkMemoryRouter_getInstance().heap();
        int oldSize = m_iElementCount;
        reserve(alloc, oldSize + n);
        m_iElementCount += n;
        return m_data + oldSize;
    }
};
struct D76250Shape {
    int getNumVertices() const;
    const hkVector4& getVertex(int i) const;

    void CopyVerticesToArray(D76250VectorArrayLocalForm& vertices) const;
};
struct FUN_00d81510_cls {
    void hkgpConvexHullImpl_build(int a1, int a2, int a3, int a4);
};
struct FUN_00d77320_cls {
    int unk00;
    int unk04;
    FUN_00d81510_cls* m_08;

    void CopyAndDispatch(int* a1, int a2, const LocalM128* a3, const unsigned int* a4);
};
struct FnvCpu_FUN_00d74e00_CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    int value;
    int GetValue_00d74e00();
};
struct S_00cc01c0_Class {
    S_00cc01c0_Class* EvaluateValue_00cc02d0();
    void ProcessAndReturnValue_00cc01c0();
    S_00cc01c0_Class* ProcessAndReturnValue_00cc01c0(const char*, int, char*);
};
struct S_00d752e0_Entity {
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
    float unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    char unk1b4;
};
struct S_00d752e0_Class {
    int unk00;
    int unk04;
    S_00d752e0_Entity* unk08;
    float hkgpConvexHull_getVolume();
};
extern const char str_010d3540[];
extern const char str_010d358c[];
struct S_00cb1600_Class {
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
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;

    void FUN_00cb1600(int*, unsigned int);
    S_00cc01c0_Class* ProcessAndReturnValue_00cc01c0(const char*, int, char*);
    void FUN_00cc00e0();
};
// Recursive quicksort partition over 12-byte records keyed by a float at +8;
// the key delta is scaled by the double literal -1.0 before testing against 0.0.
struct SortRec12 {
    unsigned int m0;
    unsigned int m4;
    float key;
};
void __cdecl hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedEdge_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedEdge(SortRec12* base, int lo, int hi, int unkArg);
extern "C" {
using ::_mm_sub_ps;
using ::_mm_mul_ps;
using ::_mm_shuffle_ps;
using ::_mm_add_ss;
using ::_mm_store_ss;
}
struct DistanceScalar {
    LocalM128 q;
__forceinline DistanceScalar(LocalM128 v) : q(v) {}
__forceinline float getReal() const { float f; _mm_store_ss(&f,q); return f; }
};
struct DistanceVector {
    LocalM128 q;
    __forceinline DistanceVector() {}
    __forceinline DistanceVector(const DistanceVector& v) : q(v.q) {}
    __forceinline void operator=(const DistanceVector& v) { q=v.q; }
    __forceinline void setSub(const DistanceVector& a,const DistanceVector& b) { q=_mm_sub_ps(a.q,b.q); }
    __forceinline DistanceScalar lengthSquared() const {
        LocalM128 d=_mm_mul_ps(q,q);
        LocalM128 y=_mm_shuffle_ps(d,d,0x55);
        LocalM128 z=_mm_shuffle_ps(d,d,0xaa);
        return DistanceScalar(_mm_add_ss(z,_mm_add_ss(y,d)));
    }
};
struct DistanceLess {
    const DistanceVector* reference;
    __forceinline bool operator()(const DistanceVector& a,const DistanceVector& b) const {
        DistanceVector da,db;
        da.setSub(a,*reference);
        db.setSub(b,*reference);
        struct Floats {
            float first;
            float second;
        };
        Floats values;
        _mm_store_ss(&values.first,da.lengthSquared().q);
        _mm_store_ss(&values.second,db.lengthSquared().q);
        return values.first<values.second;
    }
};
void Hkgpconvexhull_SortDistanceVectors(DistanceVector* pa,int lo,int hi,DistanceLess less);
struct S00d7d1c0_Alloc {
    virtual void s0();
    virtual void s1();
    virtual void s2(void* p, int size);
};
struct S00d7d1c0_Router {
    int u00;
    int u04;
    int u08;
    int u0c;
    S00d7d1c0_Alloc* m10;
};
struct S00d7d1c0_M08 {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    void FreeAll();
    void ClearAndFlush();
};
struct S00d7d1c0_M20 {
    void FlushQueuedElements();
    void FUN_00d7c8d0();
};
struct S00d7d1c0_Base {
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p, int size);
    unsigned short m04;
};
inline void* operator new(unsigned int, void* p) { return p; }
struct S00d7d1c0_Derived : S00d7d1c0_Base {
    S00d7d1c0_M08 m08;
    S00d7d1c0_M20 m20;
    ~S00d7d1c0_Derived() {
        m20.FlushQueuedElements();
        m20.FUN_00d7c8d0();
        m08.FreeAll();
        m08.ClearAndFlush();
    }
    S00d7d1c0_Derived* hkgpAbstractMesh_hkgpConvexHullImpl_Edge_hkgpConvexHullImpl_Vertex_hkgpConvexHullImpl_Triangle_hkContainerHeapAllocator_Destroy(int flags);
};

using ::_mm_load_ss;
using ::_mm_setr_ps;
using ::_mm_sub_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_add_ss;
using ::_mm_shuffle_ps;
using ::_mm_store_ss;

inline hkSimdReal::hkSimdReal() {}
inline hkSimdReal::hkSimdReal(float f) { q() = _mm_load_ss(&f); }
inline hkSimdReal::hkSimdReal(const LocalM128& v) { q() = v; }
inline LocalM128& hkSimdReal::q() { return reinterpret_cast<LocalM128&>(*this); }
inline const LocalM128& hkSimdReal::q() const { return reinterpret_cast<const LocalM128&>(*this); }
inline hkSimdReal::operator float() const { float s; _mm_store_ss(&s, q()); return s; }

inline const LocalM128& hkSimdReal::getQuad() const { return q(); }
inline LocalM128 hkSimdReal::broadcast() const { return _mm_shuffle_ps(q(), q(), 0); }
__forceinline hkVector4::hkVector4(const hkVector4& v) { memcpy(this, &v, sizeof(*this)); }
__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    LocalM128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    return _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), s);
}


__forceinline float& hkVector4::operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
__forceinline const float& hkVector4::operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
__forceinline LocalM128& hkVector4::getQuad() { return m_vComponents; }
__forceinline const LocalM128& hkVector4::getQuad() const { return m_vComponents; }
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}
__forceinline hkSimdReal hkVector4::length3() const { return _mm_sqrt_ss(dot3(*this).q()); }

static __forceinline hkSimdReal vectorDistance3(const hkVector4& a, const hkVector4& b)
{
    hkVector4 d;
    d.setSub4(a, b);
    return d.length3();
}

extern float DAT_0104da48;

struct S_00d75cb0_Node
{
    S_00d75cb0_Node* m_next;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_pos;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
};

struct S_00d75cb0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    S_00d75cb0_Node* m_pFirstNode;
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
    int unkE8;
    int unkEC;
    hkVector4 m_offset;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    hkVector4 m_vScale;
};

struct S_00d75cb0_Ref
{
    hkVector4* p;
    S_00d75cb0_Ref(hkVector4* q) : p(q) {}
};

struct S_00d75cb0
{
    int unk00;
    int unk04;
    S_00d75cb0_Obj* m_obj;

    void ProcessEntries_00d75cb0(int mode, const hkVector4& point, hkVector4& closest);
};

// @fnv 0x00d75cb0
// src: GUESS 0x00d75cb0 (confidence: low)
void S_00d75cb0::ProcessEntries_00d75cb0(int mode, const hkVector4& point, hkVector4& closest)
{
    hkSimdReal best(DAT_0104da48);

    if (mode == 0)
    {
        const hkVector4* pp = &point;
        S_00d75cb0_Obj* obj = m_obj;
        hkVector4* cp = &closest;
        *cp = *pp;
        for (S_00d75cb0_Node* node = obj->m_pFirstNode; node; node = node->m_next)
        {
            hkVector4 d;
            d.setSub4(*pp, node->m_pos);
            hkSimdReal dist = d.lengthSquared3();
            if (dist < best)
            {
                best = dist;
                cp->m_vComponents = node->m_pos.m_vComponents;
            }
        }
    }
    else
    {
        const hkVector4* pp = &point;
        S_00d75cb0_Obj* obj = m_obj;
        hkVector4* cp = &closest;
        *cp = *pp;
        for (S_00d75cb0_Node* node = obj->m_pFirstNode; node; node = node->m_next)
        {
            hkVector4 v;
            v.m_vComponents = _mm_setr_ps((float)node->m_uiX, (float)node->m_uiY, (float)node->m_uiZ, 0.0f);
            v.mul4(obj->m_vScale);
            v.add4(obj->m_offset);
            hkVector4 d;
            d.setSub4(*pp, v);
            hkSimdReal dist = d.lengthSquared3();
            if (dist < best)
            {
                best = dist;
                cp->m_vComponents = v.m_vComponents;
            }
        }
    }
}

int __cdecl Vsnprintf(void* buf, int size, const char* fmt, unsigned int arg);
int __cdecl hkString_strLen(int x);
extern const char str_010c1a98[];

struct Cc0080Stream {
    virtual void Write(const char* s, int n);
};

// Private-convention callee: str arrives in esi (entry null-check), out in edi
// (used second, both live across FUN_00cb10d0).
// src: HAVOK_LIB 0x00cc0080
static __declspec(noinline) void writeString(Cc0080Stream* out, const char* str) {
    if (!str)
        out->Write("(null)", 6);
    else
        out->Write(str, hkString_strLen((int)str));
}

struct FUN_00cc02d0_cls {
    int m_00;
    int m_04;
    Cc0080Stream* m_08;

    FUN_00cc02d0_cls* EvaluateValue_00cc02d0(int arg);
};

// @fnv 0x00cc02d0
// src: GUESS 0x00cc02d0 (confidence: low)
FUN_00cc02d0_cls* FUN_00cc02d0_cls::EvaluateValue_00cc02d0(int arg) {
    char buf[0x2728];
    Vsnprintf(buf, 0x2728, str_010c1a98, arg);
    writeString(m_08, buf);
    return this;
}

using ::_mm_mul_ps;
using ::_mm_add_ps;
struct GridVec4 {
    LocalM128 m_vComponents;
};
struct GridCell {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int x, y, z;
};
struct TESFileRecordLoader {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec;
    GridVec4 m_offset;
    int unk100, unk104, unk108, unk10c;
    GridVec4 m_vScale;
    void getCellPosition(const GridCell& c, GridVec4& out) const
    {
        out.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_setr_ps((float)c.x, (float)c.y, (float)c.z, 0.0f), m_vScale.m_vComponents), m_offset.m_vComponents);
    }
};
struct GridOwner {
    int unk00, unk04;
    TESFileRecordLoader* m_grid;
    void GetCellPosition_Thunk(GridVec4& out, const GridCell& c) const;
};
// @fnv 0x00d74e80
// src: GUESS 0x00d74e80 (confidence: medium)
void GridOwner::GetCellPosition_Thunk(GridVec4& out, const GridCell& c) const
{
    m_grid->getCellPosition(c, out);
}

using ::_mm_unpackhi_ps;
using ::_mm_shuffle_ps;
using ::_mm_rcp_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_and_ps;
using ::_mm_add_ss;
using ::_mm_sub_ss;
using ::_mm_store_ss;

extern const LocalM128 DAT_010c7170;
extern const LocalM128 DAT_01017d10;
extern const LocalM128 DAT_010c7160;

struct S00d756a0_Ostream {
    int m_00;
    int m_04;
    int m_08;
    void FUN_00cb1600(char* buf, int size);
    S00d756a0_Ostream* ProcessAndReturnValue_00cc01c0(const char* s);
    S00d756a0_Ostream* EvaluateValue_00cc02d0(int v);
    void FUN_00cc00e0();
    S00d756a0_Ostream(char* buf, int size) { FUN_00cb1600(buf, size); }
    ~S00d756a0_Ostream() { FUN_00cc00e0(); }
};

inline LocalM128 S00d756a0_quadReciprocal(LocalM128 r)
{
    LocalM128 e = _mm_rcp_ps(r);
    return _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, r), e));
}

__forceinline void hkVector4::setXYZW(const hkVector4& xyz, const hkVector4& w)
{
    m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, w.m_vComponents), 0xc4);
}
__forceinline void hkVector4::setAbs4(const hkVector4& v) { m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10); }

struct S00d756a0_Plain {
    float x, y, z, w;
};

struct S00d756a0_Shape {
    int m_00;
    int m_04;
    char* m_08;
    void GetMassProperties(hkVector4* axes, hkVector4* ext);
    void UpdateFields_00d756a0(S00d756a0_Plain& out);
};

// @fnv 0x00d756a0
// src: GUESS 0x00d756a0 (confidence: low)
void S00d756a0_Shape::UpdateFields_00d756a0(S00d756a0_Plain& out)
{
    char* obj = m_08;
    if (*(bool*)(obj + 0x1b4) == false) {
        char buf[0x200];
        S00d756a0_Ostream os(buf, 0x200);
        os.ProcessAndReturnValue_00cc01c0(str_010d358c)->EvaluateValue_00cc02d0(*(int*)(obj + 0x1b0))->ProcessAndReturnValue_00cc01c0(&DAT_0103d078);
        if (DAT_01268360->message(3, 0x79f9d887, buf, str_010d3540, 0x14e)) {
            __debugbreak();
        }
    }

    {
    hkVector4 axes[4];
    hkVector4 ext;
    GetMassProperties(axes, &ext);

    hkVector4 tmp;
    tmp.setXYZW(ext, *(const hkVector4*)&DAT_010c7170);
    ext.m_vComponents = S00d756a0_quadReciprocal(tmp.m_vComponents);
    hkVector4 absv;
    absv.setAbs4(ext);

    const float* c = absv.m_vComponents.m128_f32;
    int idx;
    if (c[0] < c[1]) {
        idx = (c[1] < c[2]) ? 2 : 1;
    } else {
        idx = (c[0] < c[2]) ? 2 : 0;
    }

    out = *(S00d756a0_Plain*)&axes[idx];
    LocalM128 s1 = _mm_mul_ps(*(LocalM128*)&out, axes[3].m_vComponents);
    LocalM128 a = _mm_add_ss(_mm_shuffle_ps(s1, s1, 0x55), s1);
    LocalM128 b = _mm_add_ss(_mm_shuffle_ps(s1, s1, 0xaa), a);
    float w;
    _mm_store_ss(&w, _mm_sub_ss(DAT_010c7160, b));
    out.w = w;
    }
}

using ::_mm_load_ss;
using ::_mm_set_ss;
using ::_mm_set_ps1;
extern "C" void _ReadWriteBarrier();
extern "C" {
using ::_mm_load_ps;
using ::_mm_store_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_min_ps;
using ::_mm_max_ps;
using ::_mm_cmple_ps;
using ::_mm_movemask_ps;
using ::_mm_add_ss;
using ::_mm_sqrt_ss;
using ::_mm_set_ps;
LocalM128 _mm_set1_ps(float);
using ::_mm_cvtss_f32;
}

__forceinline LocalM128& Vec4::getQuad() { return *(LocalM128*)this; }
__forceinline const LocalM128& Vec4::getQuad() const { return *(const LocalM128*)this; }
__forceinline void Vec4::setMax(const Vec4& a, const Vec4& b) {
    getQuad() = _mm_max_ps(a.getQuad(), b.getQuad());
}
struct Box {
    Vec4::Aligned lo;
    Vec4::Aligned hi;
    __forceinline Box() : lo(Vec4::Uninitialized), hi(Vec4::Uninitialized) {}
    __forceinline Box(const Box& value) : lo(Vec4::Uninitialized), hi(Vec4::Uninitialized) {
        memcpy(this, &value, sizeof(*this));
    }
};

struct Impl {
    int u00; int u04; int u08; int u0c;
    int u10; int u14; int u18; int u1c;
    int u20; int u24; int u28; int u2c;
    int u30; int u34; int u38; int u3c;
    int u40; int u44; int u48; int u4c;
    int u50; int u54; int u58; int u5c;
    int u60; int u64; int u68; int u6c;
    int u70; int u74; int u78; int u7c;
    int u80; int u84; int u88; int u8c;
    Box boxes[2];
    int ud0,ud4,ud8,udc;
    int ue0,ue4,ue8,uec;
    Vec4::Aligned offset;
    int u100,u104,u108,u10c;
    Vec4::Aligned scale;
};

struct PointNode {
    PointNode* next;
    int flag,unk08,unk0c;
    Vec4::Aligned source;
    int x,y,z;
};
struct HullAccess {
    int unk00,unk04;
    Impl* data;
    __declspec(noinline) int EvaluateValue_00d75050();
    __declspec(noinline) PointNode* GetUnk24_00d75060();
    __declspec(noinline) Vec4* Hkgpconvexhull_GetPayloadAddress(PointNode* node);
    __declspec(noinline) PointNode* Object_ReadPointedValue_00d75120(PointNode* node);
    __declspec(noinline) Vec4* GetCellPosition_Thunk(Vec4* out, PointNode* node);
};
// src: GUESS 0x00d75050 (confidence: low)
__declspec(noinline) int HullAccess::EvaluateValue_00d75050() { return data->u28; }
// src: GUESS 0x00d75060 (confidence: low)
__declspec(noinline) PointNode* HullAccess::GetUnk24_00d75060() { return (PointNode*)data->u24; }
// src: GUESS 0x00d74ed0 (confidence: high)
__declspec(noinline) Vec4* HullAccess::Hkgpconvexhull_GetPayloadAddress(PointNode* node) { return &node->source; }
// src: GUESS 0x00d75120 (confidence: low)
__declspec(noinline) PointNode* HullAccess::Object_ReadPointedValue_00d75120(PointNode* node) { return node->next; }
// src: GUESS 0x00d74e80 (confidence: medium)
__declspec(noinline) Vec4* HullAccess::GetCellPosition_Thunk(Vec4* out, PointNode* node) {
    LocalM128 pos=_mm_setr_ps((float)node->x,(float)node->y,(float)node->z,0.0f);
    (*(LocalM128*)out)=_mm_add_ps(_mm_mul_ps(pos,(*(LocalM128*)&data->scale)),(*(LocalM128*)&data->offset));
    return out;
}

using ::_mm_store_ss;
using ::_mm_load_ps1;
static __forceinline LocalM128 broadcast(float f) { LocalM128 q=_mm_load_ss(&f); return _mm_shuffle_ps(q,q,0); }
static __forceinline float scalar(LocalM128 q) { float f; _mm_store_ss(&f,q); return f; }

static __forceinline LocalM128 scaleBroadcast(float f) { LocalM128 q=_mm_load_ss(&f); return _mm_shuffle_ps(q,q,0); }
struct Self {
    int unk00; int unk04; Impl* m_pClassImpl;
    Box __thiscall ProcessEntries_00d75920(int index, float a2, float a3);
};

// @fnv 0x00d75920
// src: GUESS 0x00d75920 (confidence: low)
Box __thiscall Self::ProcessEntries_00d75920(int index, float a2, float a3)
{
    int idx = index;
    Box* box = m_pClassImpl->boxes + idx;
    Box temp;
    if ((_mm_movemask_ps(_mm_cmple_ps((*(LocalM128*)&box->hi),
                                       (*(LocalM128*)&box->lo))) & 7) == 0)
        goto tail;
    if (((HullAccess*)this)->EvaluateValue_00d75050() <= 0)
        goto tail;
    {
        PointNode* node;
        if (idx == 0) {
            node = ((HullAccess*)this)->GetUnk24_00d75060();
            Vec4* p = ((HullAccess*)this)->Hkgpconvexhull_GetPayloadAddress(node);
            (*(LocalM128*)&box->lo) = ( (*(LocalM128*)p));
            (*(LocalM128*)&box->hi) = ( (*(LocalM128*)p));
            node = ((HullAccess*)this)->Object_ReadPointedValue_00d75120(node);
            if (!node)
                goto tail;
            for (;;) {
                Vec4* q = ((HullAccess*)this)->Hkgpconvexhull_GetPayloadAddress(node);
                (*(LocalM128*)&box->lo) = ( _mm_min_ps((*(LocalM128*)&box->lo),
                                                          (*(LocalM128*)q)));
                (*(LocalM128*)&box->hi) = ( _mm_max_ps((*(LocalM128*)&box->hi),
                                                          (*(LocalM128*)q)));
                node = ((HullAccess*)this)->Object_ReadPointedValue_00d75120(node);
                if (!node)
                    break;
            }
        } else {
            node = ((HullAccess*)this)->GetUnk24_00d75060();
            (*(LocalM128*)&box->lo) = (
                *(LocalM128*)((HullAccess*)this)->GetCellPosition_Thunk(&temp.lo, node));
            (*(LocalM128*)&box->hi) = (
                *(LocalM128*)((HullAccess*)this)->GetCellPosition_Thunk(&temp.lo, node));
            node = ((HullAccess*)this)->Object_ReadPointedValue_00d75120(node);
            if (!node)
                goto tail;
            for (;;) {
                Vec4* r = ((HullAccess*)this)->GetCellPosition_Thunk(&temp.lo, node);
                LocalM128 rq=(*(LocalM128*)r); _ReadWriteBarrier();
                (*(LocalM128*)&box->lo)=_mm_min_ps((*(LocalM128*)&box->lo),rq); _ReadWriteBarrier();
                box->hi.setMax(box->hi,*r);
                node = ((HullAccess*)this)->Object_ReadPointedValue_00d75120(node);
                if (!node)
                    break;
            }
        }
    }
tail:
    if (a2 == 1.0 && !(a3 > 0.0)) {
        return *box;
    }
    temp = *box;
    LocalM128 high;
    if (a3 > 0.0) {
        LocalM128 thi = _mm_load_ps((const float*)&temp.hi);
        LocalM128 tlo = (*(LocalM128*)&temp.lo);
        LocalM128 d = _mm_sub_ps(thi, tlo);
        LocalM128 sq = _mm_mul_ps(d, d);
        float len = scalar(_mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa),
                                     _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq))));
        float margin = (float)(a3 * 0.5 * (double)len);
        LocalM128 mv = _mm_setr_ps(margin, margin, margin, 0.0f);
        (*(LocalM128*)&temp.lo) = ( _mm_sub_ps(tlo, mv));
        high=_mm_add_ps(thi,mv); (*(LocalM128*)&temp.hi)=high;
    }
    else { high=_mm_load_ps((const float*)&temp.hi); _ReadWriteBarrier(); }
    if (a2 != 1.0) {
        float s = (float)(a2 * 0.5);
        LocalM128 thi = high;
        LocalM128 tlo = (*(LocalM128*)&temp.lo);
        LocalM128 ext = _mm_mul_ps(scaleBroadcast(s), _mm_sub_ps(thi, tlo));
        LocalM128 center = _mm_mul_ps(broadcast(0.5f), _mm_add_ps(thi, tlo));
        (*(LocalM128*)&temp.lo) = ( _mm_sub_ps(center, ext));
        (*(LocalM128*)&temp.hi) = ( _mm_add_ps(center, ext));
    }
    return temp;
}

using ::_mm_add_ps;
using ::_mm_mul_ps;

struct S00d76120_Node {
    S00d76120_Node* m_00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_10;
    int m_20;
    int m_24;
    int m_28;
};

struct S00d76120_Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    S00d76120_Node* m_24;
    int m_28;
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
    int unkE8;
    int unkEC;
    LocalM128 m_f0;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    LocalM128 m_110;
};

struct S00d76120_ArrLocalForm { // local form of hkArray: 0x00d76120 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    hkVector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    __forceinline void reserve(D76250Allocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(hkVector4));
        }
    }

    __forceinline hkVector4* expandBy(int n)
    {
        D76250Allocator& alloc = fnvc_adapt::hkMemoryRouter_getInstance().heap();
        int oldSize = m_iElementCount;
        reserve(alloc, oldSize + n);
        m_iElementCount += n;
        return m_data + oldSize;
    }

    __forceinline hkVector4* expandBy2(int n)
    {
        D76250Allocator& alloc = *(D76250Allocator*)hkMemoryRouter_getInstance()->heap();
        int oldSize = m_iElementCount;
        int want = oldSize + n;
        int cap = getCapacity();
        if (cap < want) {
            if (want < cap * 2) want = cap * 2;
            hkArrayUtil__reserve(&alloc, this, want, sizeof(hkVector4));
        }
        m_iElementCount += n;
        return &m_data[oldSize];
    }
};

struct S00d76120_cls {
    void* m_00;
    void* m_04;
    union {
        S00d76120_Owner* m_08;
        S00d76120_Owner* m_08b;
    };
    void ProcessState_00d76120(int mode, S00d76120_ArrLocalForm& arr);

    __forceinline void copyRaw(S00d76120_ArrLocalForm& arr) const
    {
        S00d76120_Owner* o = m_08;
        hkVector4* dst = arr.expandBy(o->m_28);
        for (S00d76120_Node* node = o->m_24; node != 0; node = node->m_00) {
            *dst++ = node->m_10;
        }
    }

    __forceinline void copyScaled(S00d76120_ArrLocalForm& arr) const
    {
        S00d76120_Owner* o = m_08b;
        hkVector4* dst = arr.expandBy2(o->m_28);
        for (S00d76120_Node* node = o->m_24; node != 0; node = node->m_00) {
            LocalM128 v = _mm_setr_ps((float)node->m_20, (float)node->m_24, (float)node->m_28, 0.0f);
            hkVector4 r;
            r.m_vComponents = _mm_add_ps(_mm_mul_ps(v, o->m_110), o->m_f0);
            *dst++ = r;
        }
    }
};

// @fnv 0x00d76120
// src: GUESS 0x00d76120 (confidence: low)
void S00d76120_cls::ProcessState_00d76120(int mode, S00d76120_ArrLocalForm& arr) {
    if (mode == 0) {
        copyRaw(arr);
    } else {
        copyScaled(arr);
    }
}

struct S_00d76410_Alloc {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S_00d76410_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d76410_Alloc* m_pStreamAllocator;
    S_00d76410_Alloc& heap() { return *m_pStreamAllocator; }
};
void __cdecl hkArrayUtil__reserve(S_00d76410_Alloc* alloc, void* array, int numElements, int elemSize);
static __forceinline S_00d76410_Router& getRouter() { return *reinterpret_cast<S_00d76410_Router*>(hkMemoryRouter_getInstance()); }
template <typename T>
struct S_00d76410_ArrayLocalForm { // local form of hkArray: 0x00d76410 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void GrowArrayCapacity(S_00d76410_Alloc& alloc, int n)
    {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void reserve(int n) { GrowArrayCapacity(getRouter().heap(), n); }
    __forceinline T* _expandBy(S_00d76410_Alloc& alloc, int n)
    {
        int oldSize = m_iElementCount;
        GrowArrayCapacity(alloc, oldSize + n);
        m_iElementCount += n;
        return m_data + oldSize;
    }
    __forceinline T* expandBy(int n) { return _expandBy(getRouter().heap(), n); }
    __forceinline void pushBackUnchecked(const T& e) { m_data[m_iElementCount] = e; m_iElementCount++; }
};
using ::_mm_mul_ps;
using ::_mm_add_ps;

static __forceinline hkVector4& nextOutput(hkVector4*& dst) {
    hkVector4* result=dst; ++dst; return *result;
}
struct S_00d76410_Tri {
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
};
struct S_00d76410_Geometry {
    S_00d76410_ArrayLocalForm<hkVector4> m_kVertices;
    S_00d76410_ArrayLocalForm<S_00d76410_Tri> m_uiTriangleCount;
};
template <typename T>
struct S_00d76410_Pad {
    T m_kStorage;
    T val() const { return m_kStorage; }
};
struct S_00d76410_Vertex {
    S_00d76410_Vertex* m_next;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_pObservedSource;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
};
struct S_00d76410_Triangle {
    S_00d76410_Triangle* m_next;
    int unk04;
    S_00d76410_Vertex* m_vertex0;
    S_00d76410_Vertex* m_vertex1;
    S_00d76410_Vertex* m_vertex2;
};
struct S_00d76410_Map {
    S_00d76410_Vertex** m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    S_00d76410_Map() { m_kPrimitiveElement = 0; m_iCapacityFlags = 0; m_iPairCount = -1; }
    ~S_00d76410_Map() throw();
    int GetLogicalSize() const { return m_iCapacityFlags & 0x7fffffff; }
    void EnsureCapacity(S_00d76410_Alloc& alloc, int numElements);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(S_00d76410_Alloc& alloc, S_00d76410_Vertex* key, int val);
    int LookupHashEntry(S_00d76410_Vertex* key, int def);
    void ProcessArgument(S_00d76410_Alloc& alloc);
    __forceinline void writeIndex(S_00d76410_Vertex* v,int& out) { out=LookupHashEntry(v,-1); }
    __forceinline void reserve(int n) { EnsureCapacity(getRouter().heap(), n); }
    __forceinline void insert(S_00d76410_Vertex* key, int value) { hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(getRouter().heap(), key, value); }
    __forceinline void clear() { ProcessArgument(getRouter().heap()); }
};
struct S_00d76410_Hull {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    S_00d76410_Vertex* m_kVertices;
    int m_iStridedVertexCount;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    S_00d76410_Triangle* m_uiTriangleCount;
    int m_iTriangleCount;
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    hkVector4 m_offset;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    hkVector4 m_vScale;
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
    int m_eVertexFloatDimensions;
    __forceinline void getPosition(const S_00d76410_Vertex* v, hkVector4& out) const
    {
        LocalM128 position = _mm_setr_ps((float)v->m_uiX, (float)v->m_uiY, (float)v->m_uiZ, 0.0f);
        position = _mm_mul_ps(position, m_vScale.m_vComponents);
        out.m_vComponents = _mm_add_ps(position, m_offset.m_vComponents);
    }
};
struct S_00d76410_HullData {
    char unk00;
};
struct S_00d76410_Builder {
    int unk00;
    int unk04;
    S_00d76410_Hull* m_data;
    __forceinline void generateConvex(bool useSource, S_00d76410_Geometry& geom) const throw();
    __forceinline void generatePlanar(bool useSource, S_00d76410_Geometry& geom) const throw();
    void hkgpConvexHull_generateGeometry(int mode, S_00d76410_Geometry& geom) const throw();
};
__forceinline void S_00d76410_Builder::generateConvex(bool useSource, S_00d76410_Geometry& geom) const throw()
{
        int vertexBase = geom.m_kVertices.GetLogicalSize();
        S_00d76410_Map map;
        map.reserve(0);
        hkVector4* dst = geom.m_kVertices.expandBy(m_data->m_iStridedVertexCount);
        S_00d76410_Tri* tri = geom.m_uiTriangleCount.expandBy(m_data->m_iTriangleCount);
        map.reserve(m_data->m_iStridedVertexCount);
        for (S_00d76410_Vertex* v = m_data->m_kVertices; v; v = v->m_next) {
            int index = map.GetLogicalSize() + vertexBase;
            map.insert(v, index);
            if (useSource) {
                *dst++ = v->m_pObservedSource;
            } else {
                m_data->getPosition(v, nextOutput(dst));
            }
        }
        for (S_00d76410_Triangle* t = m_data->m_uiTriangleCount; t; t = t->m_next) {
            map.writeIndex(t->m_vertex0,tri->m_kPointA);
            map.writeIndex(t->m_vertex1,tri->m_kPointB);
            map.writeIndex(t->m_vertex2,tri->m_iThirdValue);
            tri->m_iMaterialIndex = -1;
            tri++;
        }
        map.clear();
}
__forceinline void S_00d76410_Builder::generatePlanar(bool useSource, S_00d76410_Geometry& geom) const throw()
{
        int vertexBase = geom.m_kVertices.GetLogicalSize();
        S_00d76410_ArrayLocalForm<int> indices;
        indices.m_data = 0;
        indices.m_iElementCount = 0;
        indices.m_iCapacityState = 0x80000000;
        hkVector4* dst = geom.m_kVertices.expandBy(m_data->m_iStridedVertexCount);
        S_00d76410_Tri* tri = geom.m_uiTriangleCount.expandBy(2 * m_data->m_iStridedVertexCount - 4);
        indices.reserve(m_data->m_iStridedVertexCount);
        for (S_00d76410_Vertex* v = m_data->m_kVertices; v; v = v->m_next) {
            indices.pushBackUnchecked(vertexBase + indices.GetLogicalSize());
            if (useSource) {
                *dst++ = v->m_pObservedSource;
            } else {
                m_data->getPosition(v, nextOutput(dst));
            }
        }
        for (int i = 1, last = indices.GetLogicalSize() - 1; i < last; i++) {
            tri->m_kPointA = indices.m_data[0];
            tri->m_kPointB = indices.m_data[i];
            tri->m_iThirdValue = indices.m_data[i + 1];
            tri++;
            tri->m_kPointA = indices.m_data[0];
            tri->m_kPointB = indices.m_data[i + 1];
            tri->m_iThirdValue = indices.m_data[i];
            tri++;
        }
        S_00d76410_Alloc& alloc = getRouter().heap();
        indices.m_iElementCount = 0;
        if ((indices.m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(indices.m_data, indices.getCapacity() * sizeof(int));
}
// @fnv 0x00d76410
// src: COMMUNITY 0x00d76410
void S_00d76410_Builder::hkgpConvexHull_generateGeometry(int mode, S_00d76410_Geometry& geom) const throw()
{
    bool useSource = (mode == 0);
    switch (m_data->m_eVertexFloatDimensions) {
    case 3:
        generateConvex(useSource, geom);
        break;
    case 2:
        generatePlanar(useSource, geom);
        break;
    }
}

struct S_00d77380_Strided {
    char* data;
    int count;
    int stride;
};

struct S_00d77380_Allocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReleaseBlock(void* p, int bytes);
};

struct S_00d77380_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d77380_Allocator* m_pStreamAllocator;
    S_00d77380_Allocator& heap() { return *m_pStreamAllocator; }
};
namespace fnvc_adapt2 { extern "C" S_00d77380_Router& __cdecl hkMemoryRouter_getInstance(); }
void __cdecl hkArrayUtil__reserve(S_00d77380_Allocator* alloc, void* array, int numElements, int sizeElem);

__forceinline void hkVector4::set(float x, float y, float z, float w) { m_vComponents = _mm_setr_ps(x, y, z, w); }

struct S_00d77380_ArrayLocalForm { // local form of hkArray: 0x00d77380 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    hkVector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00d77380_ArrayLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~S_00d77380_ArrayLocalForm()
    {
        S_00d77380_Allocator& alloc = fnvc_adapt2::hkMemoryRouter_getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReleaseBlock(m_data, getCapacity() * sizeof(hkVector4));
    }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void reserve(int n)
    {
        S_00d77380_Allocator& alloc = fnvc_adapt2::hkMemoryRouter_getInstance().heap();
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(hkVector4));
        }
    }
    void SetSizeAndGrow(int n) { reserve(n); m_iElementCount = n; }
    int GetLogicalSize() const { return m_iElementCount; }
    hkVector4* begin() { return m_iElementCount ? m_data : 0; }
    hkVector4& operator[](int i) { return m_data[i]; }
};

struct S_00d77380 {
    int CopyAndDispatch(const hkVector4* verts, int count, int a, int b);
    int ProcessEntries_00d77380(S_00d77380_Strided* s, int a, int b);
};
// @fnv 0x00d77380
// src: GUESS 0x00d77380 (confidence: low)
int S_00d77380::ProcessEntries_00d77380(S_00d77380_Strided* s, int a, int b)
{
    if (s->stride == 16)
        return CopyAndDispatch((const hkVector4*)s->data, s->count, a, b);
    const char* src = s->data;
    S_00d77380_ArrayLocalForm arr;
    arr.SetSizeAndGrow(s->count);
    for (int i = 0; i < s->count; i++) {
        const float* f = (const float*)src;
        arr[i].set(f[0], f[1], f[2]);
        src += s->stride;
    }
    return CopyAndDispatch(arr.begin(), arr.GetLogicalSize(), a, b);
}

extern const char str_010d3574[];
extern const float s_faderClearedAlpha;
void __cdecl hkArrayUtil__reserve(void*,void*,int,int);
using ::_mm_mul_ps;
using ::_mm_sub_ps;
using ::_mm_add_ps;
using ::_mm_add_ss;
using ::_mm_shuffle_ps;
using ::_mm_sqrt_ss;
using ::_mm_load_ps1;
using ::_mm_store_ss;

struct ExportStream {
    int unk00,unk04,unk08;
    void FUN_00cb1600(char*,int);
    ExportStream* ProcessAndReturnValue_00cc01c0(const char*,int,char*);
    ExportStream* EvaluateValue_00cc02d0();
    void ProcessAndReturnValue_00cc01c0();
    void FUN_00cc00e0();
};
struct OffsetVector { int x,y,z,w; };
struct OffsetView { LocalM128* data; int size; int stride; };
struct OffsetArray {
    LocalM128* data;
    int size;
    int capacity;
    __forceinline void init() { data=0; size=0; capacity=0x80000000; }
    __forceinline void reserve(int n) {
        S_00d7a010_Router& router=S_00d7a010_Router::hkMemoryRouter_getInstance();
        if((capacity&0x3fffffff)<n) hkArrayUtil__reserve(router.m_pStreamAllocator,this,n,16);
    }
    __forceinline void AddBack(const LocalM128& value) {
        S_00d7a010_Router& router=S_00d7a010_Router::hkMemoryRouter_getInstance();
        if(size==(capacity&0x3fffffff)) ResizeAudioStream(router.m_pStreamAllocator,this,16);
                LocalM128* dest=data+size;
        for(int j=0;j<1;++j) dest[j]=value;
        ++size;
    }
    __forceinline void clearAndFree() {
        S_00d7a010_Alloc& a=S_00d7a010_Router::hkMemoryRouter_getInstance().heap();
        size=0;
        if((capacity&0x80000000)==0) a.ReturnMemory(data,(capacity&0x3fffffff)*16);
    }
};
union OffsetWorkspace { ExportStream stream; OffsetArray array; };
struct OffsetOwner {
    int unk00,unk04;
    ChildData* state;
    OffsetVector* hkgpConvexHull_getCenterOfMass();
    OffsetVector* ForwardCall_00d752d0();
    int hkgpConvexHull_getNumPlanes();
    OffsetVector* hkgpConvexHull_getPlane(int);
    __declspec(noinline) int GetInnerField1A8();
    __declspec(noinline) void* GetValue_00d74e00();
    ValueBlock GetValueBlock();
    int EvaluateValue_00d75050();
    PayloadOwner* GetUnk24_00d75060();
    __declspec(noinline) LocalM128* Hkgpconvexhull_GetPayloadAddress(PayloadOwner* n);
    __declspec(noinline) PayloadOwner* Object_ReadPointedValue_00d75120(PayloadOwner* n);
    void ProcessEntries_00d77840(LocalM128*,int,const ValueBlock&,void*);
    void ProcessEntries_00d774a0(LocalM128*,int,void*);
    void ProcessEntries_00d77380(const OffsetView&,const ValueBlock&,void*);
    void hkgpConvexHull_build_00d77200(const OffsetView&,void*);
    void ForwardCall_00d762f0();
    void SetValue(float,bool);
};
// src: GUESS 0x00d74e10 (confidence: medium)
int OffsetOwner::GetInnerField1A8() { return state->unk1a8; }
// src: GUESS 0x00d74e00 (confidence: high)
void* OffsetOwner::GetValue_00d74e00() { return state; }
// src: GUESS 0x00d74ed0 (confidence: high)
LocalM128* OffsetOwner::Hkgpconvexhull_GetPayloadAddress(PayloadOwner* n) { return (LocalM128*)&n->m_iPayload; }
// src: GUESS 0x00d75120 (confidence: low)
PayloadOwner* OffsetOwner::Object_ReadPointedValue_00d75120(PayloadOwner* n) { return *(PayloadOwner**)n; }
static __forceinline float OffsetMaximum(float a,float b) { return a>b?a:b; }
// @fnv 0x00d78720
// src: GUESS 0x00d78720 (confidence: low)
void S_00d79f90_Result::ProcessEntries_00d78720(float f,const S_00d79f90_Opts& opts)
{
    OffsetOwner* owner=(OffsetOwner*)this;
    ChildData* state=owner->state;
    OffsetWorkspace work;
    if(!state->flag1b5) {
        char buffer[512];
        ExportStream& stream=work.stream;
        stream.FUN_00cb1600(buffer,512);
        stream.ProcessAndReturnValue_00cc01c0(str_010d3574,state->unk1b0,&DAT_0103d078)->EvaluateValue_00cc02d0()->ProcessAndReturnValue_00cc01c0();
        if(DAT_01268360->message(3,0x79f9d886,buffer,str_010d3540,0x148)) __debugbreak();
        stream.FUN_00cc00e0();
    }
    OffsetVector centerCopy=*(owner->state->unk1b4?owner->hkgpConvexHull_getCenterOfMass():owner->ForwardCall_00d752d0());
    LocalM128 center=(LocalM128&)centerCopy;
    OffsetArray& array=work.array;
    switch(opts.mode) {
    case 1: {
        array.init();
        array.reserve(owner->hkgpConvexHull_getNumPlanes());
        for(int i=0;i<owner->hkgpConvexHull_getNumPlanes();++i) {
            OffsetVector plane=*owner->hkgpConvexHull_getPlane(i);
            LocalM128 v=(LocalM128&)plane;
            LocalM128 m=_mm_mul_ps(v,center);
            LocalM128 z=_mm_add_ss(_mm_shuffle_ps(m,m,0xaa),_mm_shuffle_ps(v,v,0xff));
            LocalM128 y=_mm_add_ss(_mm_shuffle_ps(m,m,0x55),m);
            float dot;
            _mm_store_ss(&dot,_mm_add_ps(z,y));
            float displacement=OffsetMaximum(opts.value+dot,f);
            ((hkVec4&)plane).w-=displacement;
            array.AddBack((LocalM128&)plane);
        }
        if(owner->GetInnerField1A8()==2) owner->ProcessEntries_00d77840(array.data,array.size,owner->GetValueBlock(),owner->GetValue_00d74e00());
        else owner->ProcessEntries_00d774a0(array.data,array.size,owner->GetValue_00d74e00());
        array.clearAndFree();
        break;
    }
    case 0: {
        array.init();
        array.reserve(owner->EvaluateValue_00d75050());
        for(PayloadOwner* node=owner->GetUnk24_00d75060();node;node=owner->Object_ReadPointedValue_00d75120(node)) {
            LocalM128* point=owner->Hkgpconvexhull_GetPayloadAddress(node);
            LocalM128 c=center;
            LocalM128 delta=_mm_sub_ps(*point,c);
            LocalM128 q=_mm_mul_ps(delta,delta);
            LocalM128 y=_mm_shuffle_ps(q,q,0x55);
            LocalM128 z=_mm_shuffle_ps(q,q,0xaa);
            LocalM128 sum=_mm_add_ss(z,_mm_add_ss(y,q));
            float length;
            _mm_store_ss(&length,_mm_sqrt_ss(sum));
            if(length>opts.value) {
                float radius=length+f;
                if(radius<opts.value) radius=opts.value;
                radius/=length;
                LocalM128 value=_mm_add_ps(_mm_mul_ps(_mm_load_ps1(&radius),delta),c);
                S_00d7a010_Router& router=S_00d7a010_Router::hkMemoryRouter_getInstance();
                if(array.size==(array.capacity&0x3fffffff)) ResizeAudioStream(router.m_pStreamAllocator,&array,16);
                LocalM128* dest=array.data+array.size;
                for(int j=0;j<1;++j) dest[j]=value;
                ++array.size;
            } else {
                S_00d7a010_Router& router=S_00d7a010_Router::hkMemoryRouter_getInstance();
                if(array.size==(array.capacity&0x3fffffff)) ResizeAudioStream(router.m_pStreamAllocator,&array,16);
                LocalM128* dest=array.data+array.size;
                for(int j=0;j<1;++j) dest[j]=*point;
                ++array.size;
            }
        }
        if(owner->GetInnerField1A8()==2) {
            OffsetView view={array.data,array.size,16};
            owner->ProcessEntries_00d77380(view,owner->GetValueBlock(),owner->GetValue_00d74e00());
        } else {
            OffsetView view={array.data,array.size,16};
            owner->hkgpConvexHull_build_00d77200(view,owner->GetValue_00d74e00());
        }
        array.clearAndFree();
        break;
    }
    }
    owner->ForwardCall_00d762f0();
    owner->SetValue(s_faderClearedAlpha,false);
}

using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_shuffle_ps;

struct BlendOptions {
    unsigned char m_00;
    float m_04;
    unsigned char m_08,m_09,m_0a,m_0b,m_0c,m_0d;
    void hkgpConvexHull_BuildConfig_BuildConfig();
};
struct BlendObject {
    virtual ~BlendObject();
    unsigned short size;
    int unk08,unk0c,unk10;
    BlendObject* FUN_00d76ca0();
    int hkgpConvexHull_build_00d77200(void* vertices,BlendOptions* options);
};
struct BlendFactory {
    virtual void v0();
    virtual void* alloc(int size);
};
struct BlendHeap {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc();
    virtual void ReturnMemory(void*,int);
};
struct BlendRouter {
    int unk00,unk04,unk08;
    BlendHeap* heap;
    BlendFactory* factory;
};
static __forceinline BlendRouter* router() { return (BlendRouter*)hkMemoryRouter_getInstance(); }
struct BlendInput {
    const float* data;
    int count;
    int stride;
};
struct BlendArray {
    LocalM128* data;
    int count;
    int capacity;
    __forceinline LocalM128* AllocatePair() {
        BlendRouter* h=router();
        if(count==(capacity&0x3fffffff)) ResizeAudioStream((void*)h->heap,this,16);
        return data+count++;
    }
    __forceinline void clearAndFree(BlendHeap& heap) {
        count=0;
        if((capacity&0x80000000)==0) heap.ReturnMemory(data,(capacity&0x3fffffff)*16);
    }
    __forceinline ~BlendArray() { clearAndFree(*router()->heap); }
};
struct BlendSpan { LocalM128* data; int count; int stride; };
static __forceinline LocalM128 loadVector(const BlendInput* input,int index) {
    const float* p=(const float*)((const char*)input->data+index*input->stride);
    return _mm_setr_ps(p[0],p[1],p[2],input->stride>=16?p[3]:0.0f);
}
// @fnv 0x00d78ca0
// src: GUESS 0x00d78ca0 (confidence: low)
BlendObject* __cdecl Object_ProcessEntries_00d78ca0(const BlendInput* a,const BlendInput* b,const LocalM128* scale) {
    int total=a->count;
    total*=b->count;
    BlendArray out;
    out.data=0;
    out.count=0;
    out.capacity=0x80000000;
    BlendRouter* h=router();
    if((out.capacity&0x3fffffff)<total) hkArrayUtil__reserve((D76250Allocator*)h->heap,&out,total,16);
    for(int i=0;i<a->count;++i) {
        LocalM128 va=loadVector(a,i);
        for(int j=0;j<b->count;++j) {
            LocalM128 vb=loadVector(b,j);
            LocalM128* dst=out.AllocatePair();
            *dst=_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*scale,*scale,0),vb),va);
        }
    }
    BlendObject* result;
    {
    BlendOptions options;
    options.hkgpConvexHull_BuildConfig_BuildConfig();
    options.m_00=1;
    h=router();
    BlendObject* obj=(BlendObject*)h->factory->alloc(20);
    obj->size=20;
    result=obj->FUN_00d76ca0();
    BlendSpan span;
    span.data=out.data;
    span.count=out.count;
    span.stride=16;
    if(result->hkgpConvexHull_build_00d77200(&span,&options)==-1) {
        if(result) delete result;
        result=0;
    }
    }
    return result;
}

using ::_mm_set_ps1;
using ::_mm_set_ss;
using ::_mm_load_ss;
using ::_mm_move_ss;
using ::_mm_shuffle_ps;
using ::_mm_load_ps;
extern "C" void _ReadWriteBarrier();
using ::_mm_load_ps1;

using ::_mm_add_ps;

using ::_mm_mul_ps;
extern LocalM128 DAT_01267e30;
extern double DAT_0104e138;
struct Node352 {
    Node352* next;
    unsigned int unk04, unk08, unk0c;
    HullVectorCallLocal_00d75cb0 point;
};
struct Centroid352 {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    Node352* head;
    int count;
    unsigned int unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c;
    unsigned int unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c;
    HullVectorCallLocal_00d75cb0 centroid;
    const HullVectorCallLocal_00d75cb0& ProcessEntries_00d7a180();
};
// @fnv 0x00d7a180
// src: GUESS 0x00d7a180 (confidence: low)
const HullVectorCallLocal_00d75cb0& Centroid352::ProcessEntries_00d7a180() {

    HullVectorCallLocal_00d75cb0& output = centroid;
    if (output.q.m128_f32[3] == DAT_0104e138) {
        output.q = DAT_01267e30;
        Node352* node=head;
        if (node) {
            do {
                output.q = _mm_add_ps(node->point.q, output.q);
                node=node->next;
            } while (node);
        }
        if (count) {
            float inverse=1.0f/(float)count;
            LocalM128 scalar=_mm_load_ss(&inverse); LocalM128 s=_mm_shuffle_ps(scalar,scalar,0);
            output.q=_mm_mul_ps(s,output.q);
        }
        output.q.m128_f32[3]=0.0f;
    }
    return output;
}

using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_add_ss;
using ::_mm_shuffle_ps;
using ::_mm_store_ss;
extern "C" double fabs(double x);

struct __declspec(align(16)) S_00d7a200_V4 {
    float x, y, z, w;
};

struct S_00d7a200_Node {
    S_00d7a200_Node* m_next;
    int m_flag;
    int unk08;
    int unk0c;
    __declspec(align(16)) S_00d7a200_V4 m_pos;
    int unk20;
    int unk24;
    int unk28;
    float m_fHitFraction;
};

struct S_00d7a200_Owner {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;
    int unk18; int unk1c; int unk20;
    S_00d7a200_Node* m_pFirstNode;
    int ProcessEntries_00d7a200(const S_00d7a200_V4& plane, float tol, int* counts, float* range);
};

static __forceinline float S_00d7a200_Min(float a, float b) { return (b < a) ? b : a; }
static __forceinline float S_00d7a200_Max(float a, float b) { return (a < b) ? b : a; }

// @fnv 0x00d7a200
// src: GUESS 0x00d7a200 (confidence: low)
int S_00d7a200_Owner::ProcessEntries_00d7a200(const S_00d7a200_V4& plane, float tol, int* counts, float* range)
{
    float local[2];
    if (!range) range = local;
    counts[1] = 0;
    counts[0] = 0;
    range[0] = range[1] = 0.0f;
    for (S_00d7a200_Node* n = m_pFirstNode; n; n = n->m_next) {
        LocalM128 pl = *(const LocalM128*)&plane;
        LocalM128 m = _mm_mul_ps(*(const LocalM128*)&n->m_pos, pl);
        LocalM128 a = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_shuffle_ps(pl, pl, 0xff));
        LocalM128 b = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
        float d;
        _mm_store_ss(&d, _mm_add_ps(a, b));
        if (n->m_flag == 0) {
            range[0] = range[1] = d;
        } else {
            range[0] = S_00d7a200_Min(range[0], d);
            range[1] = S_00d7a200_Max(range[1], d);
        }
        float ad = (float)fabs(d);
        if (ad < tol) {
            n->m_fHitFraction = 0.0f;
        } else {
            n->m_fHitFraction = d;
            if (d > 0.0f) counts[0]++; else counts[1]++;
        }
    }
    int pos = counts[0];
    if (pos && counts[1]) return 3;
    if (counts[1] > pos) return 2;
    return pos != 0;
}

extern const char str_010d365c[];
extern const char str_010d35f0[];

struct CharBuffer
{
    char* begin;
    char* end;
    unsigned int capacity;
    void FUN_00cb1600(char*, unsigned int);
    CharBuffer* ProcessAndReturnValue_00cc01c0(const char*);
    void FUN_00cc00e0();
};

struct BlockAllocAB
{
    virtual void v00();
    virtual void v04();
    __declspec(nothrow) virtual void ReleaseBlock(void* p, int size);
};

template <int SIZE> __forceinline void MemCpyOneAB(void* dst, const void* src)
{
    for (int i = 0; i < SIZE / 4; i++)
        ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i];
}

template <class T> struct ArrAB
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            MemCpyOneAB<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

struct PoolItem40
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};

struct PoolBlock40
{
    PoolItem40 m_items[32];
    int unk800;
    int m_iAllocatedCount;

    static void operator delete(void* p, unsigned int size)
    {
        ((BlockAllocAB*)hkMemoryRouter_getInstance()->heap())->ReleaseBlock(p, size);
    }
};

struct PoolAllocator40
{
    ArrAB<PoolBlock40*> m_pools;

    void hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_release(PoolItem40* item);
};

// @fnv 0x00d7adb0
// src: HAVOK_LIB 0x00d7adb0
void PoolAllocator40::hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_release(PoolItem40* item)
{
    if (item)
    {
        for (int i = 0; i < m_pools.GetLogicalSize(); ++i)
        {
            if (item >= m_pools[i]->m_items && item <= m_pools[i]->m_items + 31)
            {
                if (--m_pools[i]->m_iAllocatedCount == 0)
                {
                    delete m_pools[i];
                    m_pools.removeAt(i);
                }
                return;
            }
        }
        char buf[512];
        CharBuffer ostr;
        ostr.FUN_00cb1600(buf, 0x200);
        ostr.ProcessAndReturnValue_00cc01c0(str_010d365c);
        if (DAT_01268360->message(3, 0x90355365, buf, str_010d35f0, 0xaf))
            __debugbreak();
        ostr.FUN_00cc00e0();
    }
}

namespace fnv_00d7aea0 {
extern const char str_010d365c[];
extern const char str_010d35f0[];

struct CharBuffer
{
    char* begin;
    char* end;
    unsigned int capacity;
    void FUN_00cb1600(char*, unsigned int);
    CharBuffer* ProcessAndReturnValue_00cc01c0(const char*);
    void FUN_00cc00e0();
};

struct BlockAllocAB
{
    virtual void v00();
    virtual void v04();
    __declspec(nothrow) virtual void ReleaseBlock(void* p, int size);
};

template <int SIZE> __forceinline void MemCpyOneAB(void* dst, const void* src)
{
    for (int i = 0; i < SIZE / 4; i++)
        ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i];
}

template <class T> struct ArrAB
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            MemCpyOneAB<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

struct PoolItem48
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
};

struct PoolBlock48
{
    PoolItem48 m_items[32];
    int unk900;
    int m_iAllocatedCount;

    static void operator delete(void* p, unsigned int size)
    {
        ((BlockAllocAB*)hkMemoryRouter_getInstance()->heap())->ReleaseBlock(p, size);
    }
};

struct PoolAllocator48
{
    ArrAB<PoolBlock48*> m_pools;

    void hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Triangle_32_struct_hkContainerHeapAllocator_release(PoolItem48* item);
};

// @fnv 0x00d7aea0
// src: HAVOK_LIB 0x00d7aea0
void PoolAllocator48::hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Triangle_32_struct_hkContainerHeapAllocator_release(PoolItem48* item)
{
    if (item)
    {
        for (int i = 0; i < m_pools.GetLogicalSize(); ++i)
        {
            if (item >= m_pools[i]->m_items && item <= m_pools[i]->m_items + 31)
            {
                if (--m_pools[i]->m_iAllocatedCount == 0)
                {
                    delete m_pools[i];
                    m_pools.removeAt(i);
                }
                return;
            }
        }
        char buf[512];
        CharBuffer ostr;
        ostr.FUN_00cb1600(buf, 0x200);
        ostr.ProcessAndReturnValue_00cc01c0(str_010d365c);
        if (DAT_01268360->message(3, 0x90355365, buf, str_010d35f0, 0xaf))
            __debugbreak();
        ostr.FUN_00cc00e0();
    }
}
}  // namespace fnv_00d7aea0

extern "C" {
using ::_mm_xor_ps;
using ::_mm_mul_ps;
using ::_mm_shuffle_ps;
using ::_mm_add_ss;
using ::_mm_store_ss;
}
extern LocalM128 DAT_010c44d0;
struct ProjectionAllocator {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc();
    virtual void ReturnMemory(void*,int);
};
struct ProjectionArray: D76250VectorArrayLocalForm {
    __forceinline ProjectionArray() { m_data=0; m_iElementCount=0; m_iCapacityState=0x80000000; }
    __forceinline ~ProjectionArray() {
        ProjectionAllocator& a=(ProjectionAllocator&)fnvc_adapt::hkMemoryRouter_getInstance().heap();
        m_iElementCount=0;
        if((m_iCapacityState&0x80000000)==0) a.ReturnMemory(m_data,getCapacity()*sizeof(hkVector4));
    }
    __forceinline hkVector4* _expandBy(D76250Allocator& alloc,int n) {
        int oldSize=m_iElementCount;
        reserve(alloc,oldSize+n);
        m_iElementCount+=n;
        return m_data+oldSize;
    }
    __forceinline hkVector4* expandBy(int n) {
        return _expandBy(fnvc_adapt::hkMemoryRouter_getInstance().heap(),n);
    }
};
struct ProjectionVertex {
    ProjectionVertex* next;
    int unk04,unk08,unk0c;
    hkVector4 value;
};
void __cdecl hkGeometryProcessing_buildTransposedArray(D76250VectorArrayLocalForm*,D76250VectorArrayLocalForm*);
void __cdecl hkVector4_FindSupportingVertex(D76250VectorArrayLocalForm*,const hkVector4*,hkVector4*);
struct ProjectionHull {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    ProjectionVertex* vertices; int numVertices;
    int unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    D76250VectorArrayLocalForm cached;
    __forceinline void build() {
        ProjectionArray temp;
        hkVector4* out=temp.expandBy(numVertices);
        for(ProjectionVertex* v=vertices;v;v=v->next) *out++=v->value;
        hkGeometryProcessing_buildTransposedArray(&temp,&cached);

    }
    __forceinline void support(const hkVector4& dir,hkVector4& out) {
        if(cached.m_iElementCount==0) build();
        hkVector4_FindSupportingVertex(&cached,&dir,&out);
    }
    float GetDirectionalProjectionSpan(const hkVector4& direction,float& lower,float& upper);
};
static __forceinline float dot3(const hkVector4& a,const hkVector4& b) {
    LocalM128 p=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
    LocalM128 y=_mm_shuffle_ps(p,p,0x55);
    LocalM128 z=_mm_shuffle_ps(p,p,0xaa);
    float f; _mm_store_ss(&f,_mm_add_ss(z,_mm_add_ss(y,p))); return f;
}
// @fnv 0x00d7c610
// src: GUESS 0x00d7c610 (confidence: medium)
float ProjectionHull::GetDirectionalProjectionSpan(const hkVector4& direction,float& lower,float& upper) {
    hkVector4 opposite;
    opposite.m_vComponents=_mm_xor_ps(direction.m_vComponents,DAT_010c44d0);
    hkVector4 first,second;
    support(direction,first);
    support(opposite,second);
    upper=dot3(direction,first);
    lower=dot3(direction,second);
    return upper-lower;
}

namespace fnv_00d7e740 {
extern const char str_010d3574[];
struct ExportStream {
    int unk00,unk04,unk08;
    void FUN_00cb1600(char*,int);
    ExportStream* ProcessAndReturnValue_00cc01c0(const char*,int,char*);
    ExportStream* EvaluateValue_00cc02d0();
    void ProcessAndReturnValue_00cc01c0();
    void FUN_00cc00e0();
};

struct ExportAllocator {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void ReturnMemory(void*, int);
};

template<class T> struct ExportArray {
    T* data;
    int size;
    int capacity;
    __forceinline void init() { data=0; size=0; capacity=0x80000000; }
    __forceinline void init(T* p,int n) { data=p; size=0; capacity=0x80000000|n; }
    __forceinline int getCapacity() const { return capacity & 0x3fffffff; }
    __forceinline void reserve(int n) {
        D76250Allocator& a=fnvc_adapt::hkMemoryRouter_getInstance().heap();
        if(getCapacity()<n) {
            int cap2=getCapacity()*2;
            int newcap=n<cap2?cap2:n;
            hkArrayUtil__reserve(&a,this,newcap,sizeof(T));
        }
    }
    __forceinline void AddBack(const T& v) {
        D76250Allocator& a=fnvc_adapt::hkMemoryRouter_getInstance().heap();
        if(size==getCapacity()) ResizeAudioStream((void*)&a,this,sizeof(T));
        T* p=data+size;
        for(int i=0;i<1;++i) p[i]=v;
        ++size;
    }
    __forceinline void clearAndFree() {
        ExportAllocator& a=(ExportAllocator&)fnvc_adapt::hkMemoryRouter_getInstance().heap();
        size=0;
        if((capacity & 0x80000000)==0) a.ReturnMemory(data,getCapacity()*sizeof(T));
    }
};
template<class T,int N> struct ExportLocalArray:ExportArray<T> {
    T storage[N];
    __forceinline ExportLocalArray() { this->init(storage,N); }
    __forceinline ~ExportLocalArray() { this->clearAndFree(); }
};

struct ExportVertex {
    ExportVertex* next;
    int flag;
    int unk08,unk0c,unk10,unk14,unk18;
    int index;
    int x,y,z,unk2c,unk30;
    int alternateIndex;
};
struct ExportInt3 { int x,y,z; };
struct ExportFace {
    ExportFace* next;
    int unk04;
    ExportVertex* vertices[3];
    unsigned int links[3];
    int unk20,unk24,unk28,unk2c,unk30,unk34;
    int mark;
};
struct ExportNullEdge { ExportFace* face; int corner; __forceinline ExportNullEdge():face(0),corner(0) {} };
struct ExportEdge {
    int corner;
    ExportFace* face;
    __forceinline ExportEdge():face(0),corner(0) {}
    __forceinline ExportEdge(ExportFace* f,int c):face(f),corner(c) {}
    __forceinline ExportVertex* vertex() const { return face->vertices[corner]; }
    __forceinline ExportEdge next() const { return ExportEdge(face,(9>>(corner*2))&3); }
    __forceinline ExportEdge adjacent() const {
        unsigned int link=face->links[corner];
        return ExportEdge((ExportFace*)(link&~3u),link&3);
    }
};
static __forceinline ExportFace* Adjacent(ExportFace* f,int i) { return (ExportFace*)(f->links[i]&~3u); }
static __forceinline int NextCorner(int i) { return (9>>(i*2))&3; }

union ExportWorkspace { ExportStream stream; ExportArray<ExportFace*> sorted; ExportArray<ExportVertex*> map; };
struct ExportCompare { unsigned char dummy; };
void __cdecl QuickSortByKey(void**,int,int,ExportCompare);

struct ExportShape {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    ExportVertex* vertices;
    int numVertices,unk2c,unk30,unk34,unk38;
    ExportFace* faces;
    int numFaces,unk44,unk48,unk4c,unk50,unk54;
    int numPolygons;
    int unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;
    int unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc;
    int unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc;
    int unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c;
    int unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c;
    int unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c;
    int unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c;
    int unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c;
    int unk1a0,unk1a4;
    int dimension,unk1ac,index;
    unsigned char unk1b4;
    bool indexed;
    int hkgpConvexHullImpl_generateIndexedFaces_unsigned_char_unsigned_short(ExportArray<unsigned char>& sizes,ExportArray<unsigned short>& indices,bool useIndex,bool rotate);
};

// @fnv 0x00d7e740
// src: HAVOK_LIB 0x00d7e740
int ExportShape::hkgpConvexHullImpl_generateIndexedFaces_unsigned_char_unsigned_short(ExportArray<unsigned char>& sizes,ExportArray<unsigned short>& indices,bool useIndex,bool rotate)
{
    int count=0;
    ExportWorkspace workspace;
    if(!indexed) {
        char buffer[512];
        ExportStream& stream=workspace.stream;
        stream.FUN_00cb1600(buffer,512);
        stream.ProcessAndReturnValue_00cc01c0(str_010d3574,index,&DAT_0103d078)->EvaluateValue_00cc02d0()->ProcessAndReturnValue_00cc01c0();
        if(DAT_01268360->message(3,0x79f9d886,buffer,str_010d3540,0x148)) __debugbreak();
        stream.FUN_00cc00e0();
    }
    sizes.size=0;
    sizes.reserve(numPolygons);
    indices.size=0;
    indices.reserve(numVertices*3);
    if(dimension==3) {
        ExportArray<ExportFace*>& sorted=workspace.sorted; sorted.init();
        sorted.reserve(numFaces);
        for(ExportFace* f=faces;f;f=f->next) { ExportFace** p=sorted.data+sorted.size; for(int j=0;j<1;++j) p[j]=f; ++sorted.size; }
        ExportCompare compare;
        compare.dummy=0;
        if(sorted.size>1) QuickSortByKey((void**)sorted.data,0,sorted.size-1,compare);
        for(int i=0,n=sorted.size;i<n;++i) {
            ExportFace* f=sorted.data[i];
            if(f->mark==count) {
                static const ExportNullEdge nullEdge;
                ExportEdge e; e.face=nullEdge.face; e.corner=nullEdge.corner;
                for(int j=0;j<3;++j) {
                    if(Adjacent(f,j)->mark!=count) { e=ExportEdge(f,j); break; }
                }
                if(e.face) {
                    ExportVertex* start=e.vertex();
                    int num=0;
                    do {
                        ++num;
                        if(useIndex) indices.AddBack((unsigned short)e.vertex()->index);
                        else indices.AddBack((unsigned short)e.vertex()->alternateIndex);
                        e=e.next();
                        while(e.adjacent().face->mark==count) e=e.adjacent().next();
                    } while(e.vertex()!=start);
                    sizes.AddBack((unsigned char)num);
                    ++count;
                }
            }
        }
        sorted.clearAndFree();
    } else if(dimension==2) {
        count=1;
        sizes.AddBack((unsigned char)numVertices);
        if(useIndex) {
            for(ExportVertex* v=vertices;v;v=v->next) indices.AddBack((unsigned short)v->index);
        } else {
            for(int i=0;i<numVertices;++i) indices.AddBack((unsigned short)i);
        }
    }
    if(rotate && count) {
        ExportArray<ExportVertex*>& map=workspace.map; map.init();
        unsigned short* polygon=indices.data;
        map.reserve(numVertices);
        for(ExportVertex* v=vertices;v;v=v->next) map.AddBack(v);
        for(int p=0;p<sizes.size;++p) {
            int n=sizes.data[p];
            if(n>=3) {
                __int64 best=-1;
                int corner=-1;
                for(int i=0;i<n;++i) {
                    ExportVertex* c=map.data[polygon[(i+2)%n]];
                    ExportVertex* b=map.data[polygon[(i+1)%n]];
                    ExportVertex* a=map.data[polygon[i]];
                    ExportInt3 d={b->x-a->x,b->y-a->y,b->z-a->z};
                    int ex=c->x-a->x,ey=c->y-a->y,ez=c->z-a->z;
                    int cx=d.y*ez-d.z*ey;
                    int cy=d.z*ex-d.x*ez;
                    int cz=d.x*ey-d.y*ex;
                    __int64 area=(__int64)cx*cx+(__int64)cy*cy+(__int64)cz*cz;
                    if(area>best) { best=area; corner=i; }
                }
                if(corner>0) {
                    ExportLocalArray<unsigned short,32> temp;
                    unsigned short* dest=polygon;
                    temp.reserve(corner);
                    temp.size=corner;
                    for(int i=0;i<corner;++i) temp.data[i]=polygon[i];
                    for(int i=corner;i<n;++i) *dest++=polygon[i];
                    for(int i=0;i<corner;++i) *dest++=temp.data[i];
                }
            }
            polygon+=n;
        }
        map.clearAndFree();
    }
    return count;
}
}  // namespace fnv_00d7e740

using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_add_ss;
using ::_mm_shuffle_ps;
using ::_mm_store_ss;

struct __declspec(align(16)) FUN_00d7a0b0_Matrix {
    LocalM128 m_row0;
    LocalM128 m_row1;
    LocalM128 m_row2;
    LocalM128 m_row3;
};

struct __declspec(align(16)) FUN_00d7a0b0_Vertex {
    FUN_00d7a0b0_Vertex* m_next;
    int unk04;
    int unk08;
    int unk0C;
    LocalM128 m_pos;
};

struct FUN_00d7a0b0_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    FUN_00d7a0b0_Vertex* m_kVertices;
    void ProcessEntries_00d7a0b0(const FUN_00d7a0b0_Matrix* m, const LocalM128* scale, LocalM128* out);
};

// @fnv 0x00d7a0b0
// src: GUESS 0x00d7a0b0 (confidence: low)
void FUN_00d7a0b0_cls::ProcessEntries_00d7a0b0(const FUN_00d7a0b0_Matrix* m, const LocalM128* scale, LocalM128* out)
{

    float best = 0.0f;
    FUN_00d7a0b0_Vertex* bestNode = 0;
    FUN_00d7a0b0_Vertex* node = m_kVertices;
    while (node != 0) {
        LocalM128 v = node->m_pos;
        LocalM128 ry = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), m->m_row1);
        LocalM128 sum = ry;
        sum = _mm_add_ps(sum, _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), m->m_row0));
        sum = _mm_add_ps(sum, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), m->m_row2));
        LocalM128 p = _mm_add_ps(sum, m->m_row3);

        LocalM128 q = _mm_mul_ps(*scale, p);
        LocalM128 s = _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q);
        LocalM128 t = _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), s);

        float d;
        _mm_store_ss(&d, t);

        if (bestNode == 0 || best < d) {
            best = d;
            *out = p;
            bestNode = node;
        }
        node = node->m_next;
    }
}

extern "C" {
using ::_mm_load_ss;
using ::_mm_store_ps;
}

extern float DAT_01011d78;

struct SpatialNode {
    SpatialNode* m_next;
    int unk04;
    int unk08;
    int unk0C;
    LocalM128 m_pos;
};

struct SpatialSimd {
    LocalM128 q;
};

__declspec(align(16)) struct SpatialVec4 {
    float x;
    float y;
    float z;
    float w;
};

struct FUN_00d7a350_cls {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    SpatialNode* m_24;

    SpatialSimd ProcessEntries_00d7a350(const LocalM128& p);
};

static __forceinline LocalM128 SpatialDist4(LocalM128 diff)
{
    LocalM128 sq = _mm_mul_ps(diff, diff);
    LocalM128 y = _mm_shuffle_ps(sq, sq, 0x55);
    LocalM128 z = _mm_shuffle_ps(sq, sq, 0xaa);
    return _mm_add_ss(z, _mm_add_ss(y, sq));
}

// @fnv 0x00d7a350
// src: GUESS 0x00d7a350 (confidence: low)
SpatialSimd FUN_00d7a350_cls::ProcessEntries_00d7a350(const LocalM128& p)
{
    SpatialVec4 bestS;
    _mm_store_ps(&bestS.x, _mm_load_ss(&DAT_01011d78));
    LocalM128 bestPt = p;
    for (SpatialNode* node = m_24; node != 0; node = node->m_next) {
        LocalM128 t = SpatialDist4(_mm_sub_ps(p, node->m_pos));
        float dist;
        _mm_store_ss(&dist, t);
        SpatialVec4 c;
        _mm_store_ps(&c.x, t);
        float bestF;
        _mm_store_ss(&bestF, _mm_load_ss(&bestS.x));
        if (dist > bestF) {
            bestS = c;
            bestPt = node->m_pos;
        }
    }
    SpatialSimd r;
    r.q = SpatialDist4(_mm_sub_ps(p, bestPt));
    return r;
}

extern const char str_010d3574[];
struct D76250Allocator : S_00d7a010_Alloc {};

struct PolygonStream {
    int unk00, unk04, unk08;
    void FUN_00cb1600(char*, int) throw();
    PolygonStream& ProcessAndReturnValue_00cc01c0(const char*) throw();
    PolygonStream& EvaluateValue_00cc02d0(unsigned int) throw();
    void FUN_00cc00e0() throw();
};

template<class T> struct PolygonArray {
    T* data;
    int size;
    int capacityAndFlags;
    __forceinline PolygonArray() : data(0), size(0), capacityAndFlags(0x80000000) {}
    struct NoInit {};
    __forceinline explicit PolygonArray(NoInit) {}
    __forceinline void init() { data = 0; size = 0; capacityAndFlags = 0x80000000; }
    __forceinline PolygonArray(T* p, int cap) : data(p), size(0), capacityAndFlags(cap | 0x80000000) {}
    __forceinline int capacity() const { return capacityAndFlags & 0x3fffffff; }
    __forceinline void reserve(D76250Allocator& a, int n) {
        if (capacity() < n) {
            int cap2 = 2 * capacity();
            int newSize = n < cap2 ? cap2 : n;
            hkArrayUtil__reserve(&a, this, newSize, sizeof(T));
        }
    }
    __forceinline void reserve(int n) {
        reserve(fnvc_adapt::hkMemoryRouter_getInstance().heap(), n);
    }
    __forceinline static void construct(T* p, int n, const T& value) {
        for (int i = 0; i < n; ++i) p[i] = value;
    }
    __forceinline void pushBackUnchecked(const T& value) {
        construct(data + size, 1, value);
        ++size;
    }
    __forceinline void AddBack(const T& value) {
        D76250MemoryRouter& router = fnvc_adapt::hkMemoryRouter_getInstance();
        if (size == capacity()) ResizeAudioStream((void*)&router.heap(), this, sizeof(T));
        pushBackUnchecked(value);
    }
    __forceinline void ClearAndRelease(D76250Allocator& a) {
        size = 0;
        if ((capacityAndFlags & 0x80000000) == 0) a.ReturnMemory(data, capacity() * sizeof(T));
    }
    __forceinline void release() { ClearAndRelease(fnvc_adapt::hkMemoryRouter_getInstance().heap()); }
};
template<class T, int N> struct PolygonInplaceArray : PolygonArray<T> {
    T storage[N];
    __forceinline PolygonInplaceArray() : PolygonArray<T>(storage, N) {}
};

struct PolygonInt3 {
    int x, y, z;
    __forceinline void setSub(const PolygonInt3& a, const PolygonInt3& b) {
        y = a.y - b.y; x = a.x - b.x; z = a.z - b.z;
    }
    __forceinline void setCross(const PolygonInt3& a, const PolygonInt3& b) {
        x = a.y * b.z - a.z * b.y;
        y = a.z * b.x - a.x * b.z;
        z = a.x * b.y - a.y * b.x;
    }
    __forceinline __int64 lengthSquared() const {
        return (__int64)x * x + (__int64)y * y + (__int64)z * z;
    }
};
struct PolygonVertex {
    PolygonVertex* next;
    int flag;
    int unk08, unk0c;
    hkVec4 position;
    PolygonInt3 integerPosition;
    float distance;
    int unk30;
    int index;
    __forceinline int getID() const { return *(const int*)&position.w & 0xc0ffffff; }
    __forceinline const int& getIndex() const { return index; }
};
static __forceinline __int64 polygonAreaSquared(const PolygonVertex* a, const PolygonVertex* b, const PolygonVertex* c) {
    PolygonInt3 ab, ac, cross;
    ab.x = b->integerPosition.x - a->integerPosition.x;
    ab.y = b->integerPosition.y - a->integerPosition.y;
    ab.z = b->integerPosition.z - a->integerPosition.z;
    ac.x = c->integerPosition.x - a->integerPosition.x;
    ac.y = c->integerPosition.y - a->integerPosition.y;
    ac.z = c->integerPosition.z - a->integerPosition.z;
    cross.setCross(ab, ac);
    return cross.lengthSquared();
}
struct PolygonTriangle {
    PolygonTriangle* next;
    int unk04;
    PolygonVertex* vertices[3];
    unsigned int links[3];
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    int component;
    __forceinline PolygonTriangle* neighbor(int edge) const {
        return (PolygonTriangle*)(links[edge] & ~3);
    }
};
struct PolygonLess {
    bool flag;
    __forceinline PolygonLess() : flag(false) {}
};
void __cdecl QuickSortByKey(PolygonTriangle**, int, int, PolygonLess);
struct PolygonEdge {
    PolygonTriangle* triangle;
    int edge;
    __forceinline PolygonEdge() : triangle(0), edge(0) {}
    __forceinline PolygonEdge(PolygonTriangle* t, int e) : triangle(t), edge(e) {}
    __forceinline static int nextIndex(int e) { return (9 >> (e + e)) & 3; }
    __forceinline PolygonEdge getNext() const { return PolygonEdge(triangle, nextIndex(edge)); }
    __forceinline PolygonEdge getTwin() const {
        unsigned int link = triangle->links[edge];
        PolygonEdge r; r.edge = link & 3; r.triangle = (PolygonTriangle*)(link & ~3); return r;
    }
    __forceinline void advance(int component) {
        *this = getNext();
        while (triangle->neighbor(edge)->component == component) {
            *this = getTwin();
            *this = getNext();
        }
    }
    __forceinline PolygonVertex* vertex() const { return triangle->vertices[edge]; }
};
static __forceinline PolygonEdge findBoundary(PolygonTriangle* t, int component) {
    static const PolygonEdge invalid;
    PolygonEdge result = invalid;
    for (int i = 0; i < 3; ++i) {
        if (t->neighbor(i)->component != component) {
            result = PolygonEdge(t, i);
            break;
        }
    }
    return result;
}

struct PolygonMesh {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    PolygonVertex* vertexHead;
    int vertexCount;
    int unk2c, unk30, unk34, unk38;
    PolygonTriangle* triangleHead;
    int triangleCount;
    int unk44, unk48, unk4c, unk50, unk54;
    int polygonCount;
    int unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4;
    int dimension;
    int unk1ac;
    int errorValue;
    char unk1b4;
    bool hasIndices;
    int hkgpConvexHullImpl_generateIndexedFaces_int_int(PolygonArray<int>& counts, PolygonArray<int>& indices, bool ids, bool rotate);
};

// @fnv 0x00d7df60
// src: HAVOK_LIB 0x00d7df60
int PolygonMesh::hkgpConvexHullImpl_generateIndexedFaces_int_int(PolygonArray<int>& counts, PolygonArray<int>& indices, bool ids, bool rotate)
{
    int numPolygons = 0;
    PolygonArray<void*> scratch((PolygonArray<void*>::NoInit()));
    if (!hasIndices) {
        char buffer[512];
        PolygonStream& stream = *(PolygonStream*)&scratch;
        stream.FUN_00cb1600(buffer, sizeof(buffer));
        stream.ProcessAndReturnValue_00cc01c0(str_010d3574).EvaluateValue_00cc02d0((unsigned int)errorValue).ProcessAndReturnValue_00cc01c0((const char*)&DAT_0103d078);
        if (DAT_01268360->message(3, 0x79f9d886, buffer, str_010d3540, 0x148)) __debugbreak();
        stream.FUN_00cc00e0();
    }
    counts.size = 0;
    counts.reserve(polygonCount);
    indices.size = 0;
    indices.reserve(vertexCount * 3);
    if (dimension == 3) {
        PolygonArray<void*>& triangles = scratch;
        triangles.init();
        triangles.reserve(triangleCount);
        for (PolygonTriangle* t = triangleHead; t; t = t->next) triangles.pushBackUnchecked((void*)t);
        PolygonLess comparator = PolygonLess();
        if (triangles.size > 1) QuickSortByKey((PolygonTriangle**)triangles.data, 0, triangles.size - 1, comparator);
        int i = 0;
        int numTriangles = triangles.size;
        for (; i < numTriangles; ++i) {
            PolygonTriangle* t = (PolygonTriangle*)triangles.data[i];
            if (t->component == numPolygons) {
                PolygonEdge e = findBoundary(t, numPolygons);
                if (e.triangle) {
                    PolygonVertex* first = e.vertex();
                    int length = 0;
                    do {
                        ++length;
                        if (ids) indices.AddBack(e.vertex()->getID());
                        else { const int& r = e.vertex()->getIndex(); indices.AddBack(r); }
                        e.advance(numPolygons);
                    } while (e.vertex() != first);
                    counts.AddBack(length);
                    ++numPolygons;
                }
            }
        }
        triangles.release();
    } else if (dimension == 2) {
        numPolygons = 1;
        int count = vertexCount;
        counts.AddBack(count);
        if (ids) {
            for (PolygonVertex* v = vertexHead; v; v = v->next) indices.AddBack(v->getID());
        } else {
            for (int i = 0; i < vertexCount; ++i) indices.AddBack(i);
        }
    }
    if (rotate && numPolygons) {
        PolygonArray<void*>& vertices = scratch;
        vertices.init();
        int* polygon = indices.data;
        vertices.reserve(vertexCount);
        for (PolygonVertex* v = vertexHead; v; v = v->next) vertices.AddBack((void*)v);
        for (int i = 0; i < counts.size; ++i) {
            int length = counts.data[i];
            if (length >= 3) {
                __int64 bestArea = -1;
                int bestCorner = -1;
                for (int j = 0; j < length; ++j) {
                    __int64 area = polygonAreaSquared((PolygonVertex*)vertices.data[polygon[j]],
                        (PolygonVertex*)vertices.data[polygon[(j + 1) % length]],
                        (PolygonVertex*)vertices.data[polygon[(j + 2) % length]]);
                    if (area > bestArea) { bestArea = area; bestCorner = j; }
                }
                if (bestCorner > 0) {
                    PolygonInplaceArray<int, 32> temp;
                    int* out = polygon;
                    temp.reserve(bestCorner);
                    temp.size = bestCorner;
                    for (int j = 0; j < bestCorner; ++j) temp.data[j] = polygon[j];
                    for (int j = bestCorner; j < length; ++j) *out++ = polygon[j];
                    for (int j = 0; j < bestCorner; ++j) *out++ = temp.data[j];
                    temp.release();
                }
            }
            polygon += length;
        }
        vertices.release();
    }
    return numPolygons;
}

using ::_mm_load_ps;
using ::_mm_load_ss;
using ::_mm_shuffle_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;

extern const double DAT_01011588;
extern const char str_010d3574[];
extern const char str_010d3540[];

union D81340Vec4 {
    LocalM128 q;
    struct { float x; float y; float z; float w; };
};

struct D81340Dbg {
    void* unk00;
    int unk04;
    int unk08;
    void __thiscall FUN_00cb1600(char* buf, unsigned int n);
    D81340Dbg* __thiscall ProcessAndReturnValue_00cc01c0(const char* fmt, int a, const char* b);
    D81340Dbg* __thiscall EvaluateValue_00cc02d0();
    void __thiscall ProcessAndReturnValue_00cc01c0();
    void __thiscall FUN_00cc00e0();
};

struct D81340Workspace {
    union {
        D81340Dbg stream;
        struct { float lower; float upper; } bounds;
    };
    float bestR;
    float result;
    float bestD;
};
struct D81340Transform { D81340Vec4 c0,c1,c2,c3; };

struct D81340F090 { float __thiscall hkgpConvexHullImpl_getOrientedRectangle(const D81340Vec4& dir, void* b, void* c); };
struct D81340F610 { int m_auiShapeKeys; float __thiscall GetDirectionalProjectionSpan(const D81340Vec4& dir, float* b, float* c); };

struct D81340Cls {
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
    D81340Vec4* m_54;
    int m_58;
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
    int m_e0;
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
    int m_1a8;
    int unk1ac;
    void* m_1b0;
    unsigned char unk1b4;
    unsigned char m_1b5;
    unsigned char unk1b6;
    unsigned char unk1b7;
    float __thiscall GetDirectionalProjectionSpan(int, float*, float*);
    float __thiscall hkgpConvexHullImpl_getOrientedRectangle(int, D81340Vec4*, D81340Transform*);
    void __thiscall ProcessEntries_00d81340(D81340Vec4& a0, D81340Transform& a1);
};

// @fnv 0x00d81340
// src: GUESS 0x00d81340 (confidence: low)
void D81340Cls::ProcessEntries_00d81340(D81340Vec4& a0, D81340Transform& a1) {
    D81340Workspace workspace;
    if (m_1a8 < 3) {
        hkgpConvexHullImpl_getOrientedRectangle((int)&m_e0, &a0, &a1);
        return;
    }
    if (!m_1b5) {
        char buffer[0x200];
        D81340Dbg& stream = workspace.stream;
        stream.FUN_00cb1600(buffer, 0x200);
        stream.ProcessAndReturnValue_00cc01c0(str_010d3574, (int)m_1b0, &DAT_0103d078)->EvaluateValue_00cc02d0()->ProcessAndReturnValue_00cc01c0();
        if (DAT_01268360->message(3, 0x79f9d886, buffer, str_010d3540, 0x148)) __debugbreak();
        stream.FUN_00cc00e0();
    }
    float& u18 = workspace.bounds.lower;
    float& u1c = workspace.bounds.upper;
    float t14;
    float& t24 = workspace.bestR;
    float& r = workspace.result;
    float& t2c = workspace.bestD;
    t24 = DAT_0104da48;
    t2c = DAT_0104da48;
    D81340Vec4 v30;
    D81340Transform v40;
    float s;
    for (int i = 0; i < m_58; ++i) {
        int elem = (int)m_54 + i * 16;
        r = GetDirectionalProjectionSpan(elem, &u18, &u1c);
        if (r < t24) {
            int elem2 = (int)m_54 + i * 16;
            t14 = hkgpConvexHullImpl_getOrientedRectangle(elem2, &v30, &v40) * (u1c - u18);
            if (t14 < t2c) {
                t24 = r;
                t2c = t14;
                a0.q = v30.q;
                a0.q.m128_f32[2] = r;
                a1.c0.q = v40.c0.q;
                a1.c1.q = v40.c1.q;
                a1.c2.q = v40.c2.q;
                a1.c3.q = v40.c3.q;
            }
        }
    }
    volatile float& distance = a0.z;
    distance *= DAT_01011588;
    s = -distance;
    LocalM128 sv = _mm_load_ss(&s);
    LocalM128 sb = _mm_shuffle_ps(sv, sv, 0);
    a1.c3.q = _mm_add_ps(_mm_mul_ps(sb, a1.c2.q), a1.c3.q);
}

struct SupportVector { LocalM128 q; };
struct SupportShape {
    void ProcessEntries_00d76320(const SupportVector& input, SupportVector& output);
    float ComputeValues_00d768b0(const SupportVector& input);
};

// @fnv 0x00d768b0
// src: GUESS 0x00d768b0 (confidence: low)
float SupportShape::ComputeValues_00d768b0(const SupportVector& input)
{
    SupportVector normal;
    ProcessEntries_00d76320(input, normal);
    LocalM128 c = normal.q;
    LocalM128 a = input.q;
    LocalM128 offset = _mm_shuffle_ps(a, a, 0xff);
    a = _mm_mul_ps(a, c);
    LocalM128 y = _mm_shuffle_ps(a, a, 0x55);
    LocalM128 z = _mm_shuffle_ps(a, a, 0xaa);
    LocalM128 sum = _mm_add_ss(z, _mm_add_ss(y, a));
    float result;
    _mm_store_ss(&result, _mm_add_ss(sum, offset));
    return result;
}

extern float DAT_0104e148;
class PlaneScalar {
    LocalM128 value;
public:
    PlaneScalar(const LocalM128& q):value(q) {}
    PlaneScalar() {}
    operator float() const { float result; _mm_store_ss(&result,value); return result; }
    __forceinline const LocalM128& quad() const { return value; }
};
inline PlaneScalar __cdecl operator+(const PlaneScalar& a,const PlaneScalar& b) {
    return _mm_add_ss(a.quad(),b.quad());
}
struct PlaneVector {
    LocalM128 value;
    __forceinline PlaneScalar dot(const PlaneVector& b) const {
        LocalM128 product=_mm_mul_ps(value,b.value);
        LocalM128 xy=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
        return _mm_add_ss(_mm_shuffle_ps(product,product,0xaa),xy);
    }
    __forceinline PlaneScalar offset(int i) const {
        switch(i) {
        case 0: return value;
        case 1: return _mm_shuffle_ps(value,value,0x55);
        case 2: return _mm_shuffle_ps(value,value,0xaa);
        default: return _mm_shuffle_ps(value,value,0xff);
        }
    }
};
struct PlaneArgument {
    const PlaneVector* p;
    PlaneArgument(const PlaneVector* v):p(v) {}
};
struct PlaneHull {
    int hkgpConvexHull_getNumPlanes();
    const PlaneVector& hkgpConvexHull_getPlane(int i);
    float hkgpConvexHull_maximumDistanceToPlanes(PlaneArgument point);
};
static __forceinline float greaterValue(float a,float b) { return a>b?a:b; }
// @fnv 0x00d75880
// src: XBOX_PDB 0x00d75880
float PlaneHull::hkgpConvexHull_maximumDistanceToPlanes(PlaneArgument point) {
    float best=DAT_0104e148;
    int i=0;
    if(i<hkgpConvexHull_getNumPlanes()) {
      const PlaneVector* query=point.p;
      do {
        const PlaneVector& plane=hkgpConvexHull_getPlane(i);
        best=greaterValue(best,plane.dot(*query)+plane.offset(3));
      } while(++i<hkgpConvexHull_getNumPlanes());
    }
    return best;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);

using ::_mm_sub_ss;
using ::_mm_shuffle_ps;
using ::_mm_store_ss;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_add_ss;
using ::_mm_load_ps;
using ::_mm_store_ps;

extern unsigned long DAT_0126835c;
extern float DAT_01011d78;
extern const LocalM128 DAT_010c7160;

struct Tt_ProfRec {
    const char* m_pName;
    unsigned long m_iTick;
    unsigned long unk08;
};
struct Tt_ProfBuf {
    unsigned long unk00;
    Tt_ProfRec* m_pCur;
    unsigned long unk08;
    Tt_ProfRec* m_pRecordEnd;
};

struct __declspec(align(16)) Tt_Mat3 {
    LocalM128 r0;
    LocalM128 r1;
    LocalM128 r2;
    int invert_00cd4f10(float eps);
};

struct __declspec(align(16)) Tt_W {
    float x, y, z, w;
};


using ::_mm_setr_ps;
struct Tt_Simd {
    LocalM128 m_vValue;
    Tt_Simd(const LocalM128& x) : m_vValue(x) {}
    operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
};
static __forceinline Tt_Simd operator-(const Tt_Simd& r)
{
    extern const LocalM128 DAT_010c7160;
    return _mm_sub_ss(DAT_010c7160, r.m_vValue);
}
struct __declspec(align(16)) Tt_V4 {
    LocalM128 m_vComponents;
    __forceinline void set(float a, float b, float c, float d = 0) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    __forceinline float& operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
    __forceinline const float& operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
    __forceinline Tt_Simd getW() const { return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff); }
    __forceinline Tt_Simd dot4xyz1(const Tt_V4& a) const
    {
        LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        LocalM128 zwSum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
        return _mm_add_ps(xySum, zwSum);
    }
};
struct __declspec(align(16)) Tt_M3 {
    Tt_V4 m_col[3];
    int invert_00cd4f10(float eps);
    __forceinline void setRows(const Tt_V4& r0, const Tt_V4& r1, const Tt_V4& r2)
    {
        m_col[0].set(r0(0), r1(0), r2(0));
        m_col[1].set(r0(1), r1(1), r2(1));
        m_col[2].set(r0(2), r1(2), r2(2));
    }
};
static __forceinline void Tt_setMul3(Tt_V4& out, const Tt_M3& a, const Tt_V4& b)
{
    const LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const LocalM128 r0 = _mm_mul_ps(a.m_col[0].m_vComponents, b0);
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const LocalM128 r1 = _mm_mul_ps(a.m_col[1].m_vComponents, b1);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(a.m_col[2].m_vComponents, b2);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

struct S_00d77840 {
    int unk00;
    int ProcessEntries_00d77380(D76250VectorArrayLocalForm* view, const hkVector4* sph, int a4);
    int ProcessEntries_00d77840(const hkVector4* pts, int n, const hkVector4* sph, int a4);
};

static __forceinline void release_out(D76250VectorArrayLocalForm& out)
{
    D76250Allocator& a3 = fnvc_adapt::hkMemoryRouter_getInstance().heap();
    int cap = out.m_iCapacityState;
    out.m_iElementCount = 0;
    if ((cap & 0x80000000) == 0) {
        int n = cap & 0x3fffffff;
        S_00d7a010_Alloc& al = *(S_00d7a010_Alloc*)&a3;
        al.ReturnMemory(out.m_data, n * (int)sizeof(hkVector4));
    }
}

// @fnv 0x00d77840
// src: GUESS 0x00d77840 (confidence: low)
int S_00d77840::ProcessEntries_00d77840(const hkVector4* pts, int n, const hkVector4* sph, int a4)
{
    LocalM128 p;
    (void)p;
    D76250VectorArrayLocalForm out;
    out.m_data = 0;
    out.m_iElementCount = 0;
    out.m_iCapacityState = (int)0x80000000;
    volatile unsigned long tick;

    Tt_ProfBuf* pb = (Tt_ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pb->m_pCur < pb->m_pRecordEnd) {
        Tt_ProfRec* rec = pb->m_pCur;
        rec->m_pName = "TtVertexEnumeration";
        _ReadWriteBarrier();
        tick = (unsigned long)__rdtsc();
        rec->m_iTick = tick;
        pb->m_pCur = rec + 1;
    }

    int need = 3 * n;
    D76250Allocator& alloc = fnvc_adapt::hkMemoryRouter_getInstance().heap();
    out.reserve(alloc, need);

    const Tt_V4* planes = (const Tt_V4*)pts;
    const Tt_V4& projectionPlane = *(const Tt_V4*)sph;
    Tt_V4 b;
    for (int i = 0; i < n; i++) {
        b(0) = -planes[i].getW();
        for (int j = i + 1; j < n; j++) {
            b(1) = -planes[j].getW();
            Tt_M3 A;
            A.setRows(planes[i], planes[j], projectionPlane);
            b(2) = -projectionPlane.getW();
            if (A.invert_00cd4f10(1.1920929e-7f) == 0) {
                Tt_V4 x;
                Tt_setMul3(x, A, b);
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j && ((p = planes[k].m_vComponents), ((const Tt_V4&)p).dot4xyz1(x)) > 1.1920929e-7f) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    D76250Allocator& a2 = fnvc_adapt::hkMemoryRouter_getInstance().heap();
                    if (out.m_iElementCount == out.getCapacity())
                        ResizeAudioStream(&a2, &out, 0x10);
                    _mm_store_ps((float*)(out.m_data + out.m_iElementCount), x.m_vComponents);
                    out.m_iElementCount++;
                }
            }
        }
    }

    pb = (Tt_ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pb->m_pCur < pb->m_pRecordEnd) {
        Tt_ProfRec* rec = pb->m_pCur;
        rec->m_pName = "Et";
        _ReadWriteBarrier();
        tick = (unsigned long)__rdtsc();
        rec->m_iTick = tick;
        pb->m_pCur = rec + 1;
    }

    if (out.m_iElementCount >= 3) {
        D76250VectorArrayLocalForm* view = (D76250VectorArrayLocalForm*)&b;
        view->m_data = out.m_data;
        view->m_iElementCount = out.m_iElementCount;
        view->m_iCapacityState = 0x10;
        int result = ProcessEntries_00d77380(view, sph, a4);
        release_out(out);
        return result;
    }
    release_out(out);
    return -1;
}

extern "C" {
using ::_mm_sub_ss;
using ::_mm_mul_ss;
using ::_mm_rsqrt_ss;
using ::_mm_cmpeq_ss;
using ::_mm_andnot_ps;
using ::_mm_set_ss;
}
extern const LocalM128 DAT_010c7160;



class S00d79ab0_SimdReal {
public:
    S00d79ab0_SimdReal(const LocalM128& x) : m_vValue(x) {}
    S00d79ab0_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const LocalM128& getQuad() const { return m_vValue; }
private:
    LocalM128 m_vValue;
};
inline S00d79ab0_SimdReal __cdecl operator*(const S00d79ab0_SimdReal& r, const S00d79ab0_SimdReal& s) { return _mm_mul_ss(r.getQuad(), s.getQuad()); }
inline S00d79ab0_SimdReal __cdecl operator+(const S00d79ab0_SimdReal& r, const S00d79ab0_SimdReal& s) { return _mm_add_ss(r.getQuad(), s.getQuad()); }
inline S00d79ab0_SimdReal __cdecl operator-(const S00d79ab0_SimdReal& r) { return _mm_sub_ss(DAT_010c7160, r.getQuad()); }





// Keep this variant local: the shared vector changes FUN_00d79ab0's instruction scheduling.
class S00d79ab0_Vector4 {
public:
    __forceinline void setSub4(const S00d79ab0_Vector4& v0, const S00d79ab0_Vector4& v1) { m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents); }
    __forceinline S00d79ab0_SimdReal dot3(const S00d79ab0_Vector4& a) const
    {
        LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00d79ab0_SimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline S00d79ab0_SimdReal distanceToSquared3(const S00d79ab0_Vector4& p) const
    {
        S00d79ab0_Vector4 d;
        d.setSub4(*this, p);
        return d.lengthSquared3();
    }
    __forceinline S00d79ab0_SimdReal lengthInverse3() const
    {
        const LocalM128 half = _mm_set_ss(0.5f);
        const LocalM128 three = _mm_set_ss(3.0f);
        const LocalM128 zero = _mm_set_ss(0.0f);
        const LocalM128 len2 = this->dot3(*this).getQuad();
        const LocalM128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const LocalM128 approx = _mm_rsqrt_ss(len2);
        const LocalM128 refined = _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3()
    {
        LocalM128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    __forceinline float& operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
    __forceinline void operator=(const S00d79ab0_Vector4& v) { m_vComponents = v.m_vComponents; }
    LocalM128 m_vComponents;
};

struct S00d79ab0_TypeIsPod {};
template <typename T> struct S00d79ab0_IsPodType { typedef S00d79ab0_TypeIsPod type; };

struct S00d79ab0_ArrayUtil {
    template <typename T>
    static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, S00d79ab0_TypeIsPod)
    {
        for (int i = 0; i < n; ++i) {
            t[i] = tcopy;
        }
    }
    static __forceinline void GrowArrayCapacity(S_00d7a010_Alloc& a, void* array, int reqElem, int sizeElem) { hkArrayUtil__reserve(&a, array, reqElem, sizeElem); }
    static __forceinline void GrowArray(S_00d7a010_Alloc& a, void* array, int sizeElem) { ResizeAudioStream(&a, array, sizeElem); }
};

template <typename T>
static __forceinline void S00d79ab0_bufFree(S_00d7a010_Alloc& a, void* p, int numElem) { a.ReturnMemory(p, numElem * (int)sizeof(T)); }

struct S00d79ab0_ContainerHeapAllocator {
    __forceinline S_00d7a010_Alloc& get(const void*) { return S_00d7a010_Router::hkMemoryRouter_getInstance().heap(); }
};

template <typename T>
class S00d79ab0_ArrayBaseLocalForm { // local form of hkArrayBase: 0x00d79ab0 needs the original constructor stores; shared base construction changes bytes.
public:
    __forceinline S00d79ab0_ArrayBaseLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~S00d79ab0_ArrayBaseLocalForm() {}
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline void clear() { m_iElementCount = 0; }
    __forceinline void _clearAndDeallocate(S_00d7a010_Alloc& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0) {
            S00d79ab0_bufFree<T>(alloc, m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void _reserveExactly(S_00d7a010_Alloc& alloc, int n)
    {
        if (getCapacity() < n) {
            S00d79ab0_ArrayUtil::GrowArrayCapacity(alloc, this, n, sizeof(T));
        }
    }
    __forceinline void pushBackUnchecked(const T& t)
    {
        S00d79ab0_ArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, typename S00d79ab0_IsPodType<T>::type());
        m_iElementCount++;
    }
    __forceinline void _pushBack(S_00d7a010_Alloc& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity()) {
            S00d79ab0_ArrayUtil::GrowArray(alloc, this, sizeof(T));
        }
        S00d79ab0_ArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, typename S00d79ab0_IsPodType<T>::type());
        m_iElementCount++;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T>
class S00d79ab0_Array : public S00d79ab0_ArrayBaseLocalForm<T> {
public:
    typedef S00d79ab0_ContainerHeapAllocator AllocatorType;
    __forceinline S00d79ab0_Array() : S00d79ab0_ArrayBaseLocalForm<T>() {}
    __forceinline ~S00d79ab0_Array() { ClearAndRelease(); }
    __forceinline void ClearAndRelease() { S00d79ab0_ArrayBaseLocalForm<T>::_clearAndDeallocate(AllocatorType().get(this)); }
    __forceinline void AddBack(const T& e) { S00d79ab0_ArrayBaseLocalForm<T>::_pushBack(AllocatorType().get(this), e); }
    __forceinline void reserveExactly(int size) { S00d79ab0_ArrayBaseLocalForm<T>::_reserveExactly(AllocatorType().get(this), size); }
};

struct S00d79ab0_RadialSort {
    __forceinline S00d79ab0_RadialSort(const S00d79ab0_Vector4& c) : m_kCenterPosition(c) {}
    const S00d79ab0_Vector4& m_kCenterPosition;
};
void __cdecl Hkgpconvexhull_SortDistanceVectors(S00d79ab0_Vector4* pArr, int d, int h, S00d79ab0_RadialSort cmpLess);
template <typename T, typename L>
__forceinline void __cdecl S00d79ab0_quickSort(T* pArr, int iSize, L cmpLess)
{
    if (iSize > 1) {
        int low = 0;
        int high = iSize - 1;
        Hkgpconvexhull_SortDistanceVectors(pArr, low, high, cmpLess);
    }
}

class S00d79ab0_Bool {
public:
    __forceinline S00d79ab0_Bool& operator=(bool b) { m_cBooleanValue = (char)(b ? 1 : 0); return *this; }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
private:
    char m_cBooleanValue;
};

struct S00d79ab0_Impl {
    int unk00;
    int unk04;
    char unk08;
    S00d79ab0_Bool m_flag09;
    S00d79ab0_Bool m_flag0a;
    char unk0b;
    S00d79ab0_SimdReal ProcessEntries_00d7a350(const S00d79ab0_Vector4& c) const;
    int AllocateStorage_00d83430(float planeW, class S00d79ab0_Hull** posOut, class S00d79ab0_Hull** negOut, float thickness) const;
};
struct S00d79ab0_ImplFlags {
    int unk1b0;
    S00d79ab0_Bool m_bFirstImplementationFlag;
    S00d79ab0_Bool m_bSecondImplementationFlag;
};

class S00d79ab0_Hull {
public:
    virtual ~S00d79ab0_Hull();
    void operator delete(void* p);
    S00d79ab0_Hull* hkgpConvexHull_clone() const;
    int hkgpConvexHull_splitByPlane(const S00d79ab0_Vector4& plane, S00d79ab0_Hull** posOut, S00d79ab0_Hull** negOut, float thickness) const;
    void SetValue(float minCosAngle, bool keepPlanes);
    int ForwardCall_00d762f0();
    int unk04;
    S00d79ab0_Impl* m_data;
    __forceinline bool hasIndexing() const { return reinterpret_cast<const S00d79ab0_ImplFlags*>(reinterpret_cast<const char*>(m_data) + 0x1b0)->m_bSecondImplementationFlag; }
    __forceinline bool hasMassProperties() const { return reinterpret_cast<const S00d79ab0_ImplFlags*>(reinterpret_cast<const char*>(m_data) + 0x1b0)->m_bFirstImplementationFlag; }
};

// src: HAVOK_LIB 0x00d790a0
__declspec(noinline) int S00d79ab0_Hull::hkgpConvexHull_splitByPlane(const S00d79ab0_Vector4& plane, S00d79ab0_Hull** posOut, S00d79ab0_Hull** negOut, float thickness) const
{
    return m_data->AllocateStorage_00d83430(plane.m_vComponents.m128_f32[3], posOut, negOut, thickness);
}

template <typename T>
inline T __cdecl S00d79ab0_max2(T x, T y) { return x > y ? x : y; }

// @fnv 0x00d79ab0
// src: GUESS 0x00d79ab0 (confidence: low)
void __cdecl HkgpconvexhullGsEhscNogsNoehsc_ReleaseStorage_00d79ab0(const S00d79ab0_Hull* domain, const S00d79ab0_Array<S00d79ab0_Vector4>& points, S00d79ab0_Array<S00d79ab0_Hull*>& cells, float margin)
{
    const float eps = 1.1920928955078125e-06f;
    const float offset = S00d79ab0_max2(eps, margin * 2 + eps);
    const float offsetSquared = offset * offset;
    const S00d79ab0_SimdReal planeOffset = -offset * 0.5;
    const S00d79ab0_SimdReal half = 0.5f;
    S00d79ab0_Array<S00d79ab0_Vector4> unique;
    S00d79ab0_Array<S00d79ab0_Vector4> sorted;
    unique.reserveExactly(points.GetLogicalSize());
    sorted.reserveExactly(points.GetLogicalSize());
    for (int i = 0; i < points.GetLogicalSize(); ++i) {
        bool found = false;
        for (int j = 0; j < unique.GetLogicalSize(); ++j) {
            if (unique[j].distanceToSquared3(points[i]) <= offsetSquared) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique.pushBackUnchecked(points[i]);
            sorted.pushBackUnchecked(points[i]);
        }
    }
    float maxDistance = -1.0f;
    for (int i = 0; i < unique.GetLogicalSize(); ++i) {
        S00d79ab0_Hull* cell = domain->hkgpConvexHull_clone();
        S00d79ab0_Vector4 center = unique[i];
        S00d79ab0_quickSort(&sorted[0], sorted.GetLogicalSize(), S00d79ab0_RadialSort(center));
        cell->m_data->m_flag09 = false;
        cell->m_data->m_flag0a = false;
        for (int j = 0; cell && j < sorted.GetLogicalSize(); ++j) {
            const S00d79ab0_Vector4& p = sorted[j];
            S00d79ab0_Vector4 plane;
            plane.setSub4(p, center);
            const float distanceSquared = plane.lengthSquared3();
            if (distanceSquared > offsetSquared) {
                plane.normalize3();
                plane(3) = -half * (plane.dot3(p) + plane.dot3(center) + planeOffset);
                S00d79ab0_Hull* parts[2] = { 0, 0 };
                switch (cell->hkgpConvexHull_splitByPlane(plane, 0, &parts[1], eps)) {
                case 3:
                    delete cell;
                    cell = parts[1];
                    maxDistance = -1.0f;
                    break;
                case 1:
                    delete cell;
                    cell = 0;
                    break;
                case 2:
                    if (maxDistance < 0.0) {
                        maxDistance = cell->m_data->ProcessEntries_00d7a350(center);
                    }
                    if (distanceSquared > maxDistance * 4.0) {
                        j = sorted.GetLogicalSize();
                    }
                    break;
                }
            }
        }
        if (cell) {
            if (domain->hasIndexing())
                cell->SetValue(0.9999f, false);
            if (domain->hasMassProperties())
                cell->ForwardCall_00d762f0();
            cells.AddBack(cell);
        }
    }
}

extern "C" {
using ::_mm_sub_ps;
using ::_mm_mul_ps;
using ::_mm_add_ss;
using ::_mm_shuffle_ps;
using ::_mm_sqrt_ss;
using ::_mm_store_ss;
}
class S00d7cf00_SimdReal {
public:
    __forceinline S00d7cf00_SimdReal(const hkSimdReal& v) : m_vValue(v.q()) {}
    S00d7cf00_SimdReal(const LocalM128& x) : m_vValue(x) {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline const LocalM128& getQuad() const { return m_vValue; }
    LocalM128 m_vValue;
};

struct S00d7cf00_Vertex {
    S00d7cf00_Vertex* m_next;
    S00d7cf00_Vertex* m_pSecondNode;
    int unk08;
    int unk0c;
    hkVector4 m_pObservedSource;
    int m_uiX[3];
    __forceinline int compare(const S00d7cf00_Vertex& o) const
    {
        for (int i = 0; i < 3; ++i) {
            if (m_uiX[i] < o.m_uiX[i]) return -1;
            if (m_uiX[i] > o.m_uiX[i]) return 1;
        }
        return 0;
    }
    static __forceinline bool isOrdered(const S00d7cf00_Vertex* a, const S00d7cf00_Vertex* b)
    {
        const int c((*a).compare(*b));
        if (c < 0) return true;
        if (c > 0) return false;
        return true;
    }
};
struct S00d7cf00_Triangle {
    S00d7cf00_Triangle* m_next;
    S00d7cf00_Triangle* m_pSecondNode;
    S00d7cf00_Vertex* m_kVertices[3];
    unsigned long m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int m_iTriangleValueAtOffset0x38;
};
struct S00d7cf00_HullEdge;
template <typename T>
static __forceinline void S00d7cf00_ulong2uid(unsigned long uid, T*& t, unsigned& i)
{
    i = (unsigned)(uid & 3);
    uid &= ~3;
    t = *(T**)&uid;
}
template <typename T>
static __forceinline void S00d7cf00_unpackUid(unsigned long uid, T*& t, unsigned& i) { S00d7cf00_ulong2uid(uid, t, i); }
struct S00d7cf00_TopoEdge {
    __forceinline S00d7cf00_TopoEdge(S00d7cf00_Triangle* t, unsigned i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    __forceinline S00d7cf00_TopoEdge(const unsigned long& id) { S00d7cf00_unpackUid(id, m_pkTriangle, m_uiEdgeIndex); }
    static __forceinline unsigned ip1mod3(unsigned i) { return (9 >> (i << 1)) & 3; }
    __forceinline S00d7cf00_HullEdge link() const;
    __forceinline S00d7cf00_Triangle* triangle() const { return m_pkTriangle; }
    __forceinline S00d7cf00_Vertex*& start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    __forceinline S00d7cf00_Vertex*& end() const { return m_pkTriangle->m_kVertices[ip1mod3(m_uiEdgeIndex)]; }
    __forceinline bool isValid() const { return triangle() != 0; }
    __forceinline bool isNaked() const;
    __forceinline bool isMaster() const { return S00d7cf00_Vertex::isOrdered(start(), end()) || isNaked(); }
    S00d7cf00_Triangle* m_pkTriangle;
    unsigned m_uiEdgeIndex;
};
struct S00d7cf00_HullEdge : S00d7cf00_TopoEdge {
    __forceinline S00d7cf00_HullEdge(S00d7cf00_Triangle* t, int i) : S00d7cf00_TopoEdge(t, i) {}
    __forceinline S00d7cf00_HullEdge(unsigned long id) : S00d7cf00_TopoEdge(id) {}
    __forceinline bool samePlane() const { return triangle()->m_iTriangleValueAtOffset0x38 == link().triangle()->m_iTriangleValueAtOffset0x38; }
};
__forceinline S00d7cf00_HullEdge S00d7cf00_TopoEdge::link() const { return S00d7cf00_HullEdge(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]); }
__forceinline bool S00d7cf00_TopoEdge::isNaked() const { return !link().isValid(); }
struct S00d7cf00_FreeAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
    __forceinline void _bufFree(void* p, int numElem) { ReturnMemory(p, numElem * (int)sizeof(hkVector4)); }
};
class S00d7cf00_ArrayLocalForm { // local form of hkArray: 0x00d7cf00 needs the original inline/out-of-line helper split; shared replacement changes bytes.
public:
    __forceinline S00d7cf00_ArrayLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~S00d7cf00_ArrayLocalForm() { ClearAndRelease(); }
    __forceinline D76250Allocator& alloc() { return fnvc_adapt::hkMemoryRouter_getInstance().heap(); }
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline hkVector4& operator[](int i) { return m_data[i]; }
    __forceinline void clear() { m_iElementCount = 0; }
    __forceinline void ClearAndRelease() { _clearAndDeallocate((S00d7cf00_FreeAllocator&)alloc()); }
    __forceinline void _clearAndDeallocate(S00d7cf00_FreeAllocator& a)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            a._bufFree(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(D76250Allocator& a, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&a, this, newSize, sizeof(hkVector4));
        }
    }
    __forceinline hkVector4* _expandBy(D76250Allocator& a, int n)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(a, m_iElementCount + n);
        m_iElementCount += n;
        return m_data + oldsize;
    }
    __forceinline hkVector4* expandBy(int n) { return _expandBy(alloc(), n); }
    hkVector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct S00d7cf00_Hull {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    S00d7cf00_Vertex* m_firstVertex;
    int m_iStridedVertexCount;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    S00d7cf00_Triangle* m_firstTriangle;
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
    int m_eVertexFloatDimensions;
    __forceinline void fetchWorldPositions(S00d7cf00_ArrayLocalForm& positions) const
    {
        hkVector4* p = positions.expandBy(m_iStridedVertexCount);
        for (const S00d7cf00_Vertex* v = m_firstVertex; v; v = v->m_next)
            *p++ = v->m_pObservedSource;
    }
    float ProcessEntries_00d7cf00() const;
};
// @fnv 0x00d7cf00
// src: GUESS 0x00d7cf00 (confidence: low)
float S00d7cf00_Hull::ProcessEntries_00d7cf00() const
{
    float sum = 0.0f;
    switch (m_eVertexFloatDimensions) {
    case 0:
        return 0.0f;
    case 1: {
        const S00d7cf00_Vertex* a = m_firstVertex;
        const S00d7cf00_Vertex* b = a->m_next;
        sum = vectorDistance3(a->m_pObservedSource, b->m_pObservedSource);
    } break;
    case 2: {
        S00d7cf00_ArrayLocalForm positions;
        fetchWorldPositions(positions);
        int prev = positions.GetLogicalSize() - 1;
        for (int i = 0; i < positions.GetLogicalSize(); prev = i++)
            sum += vectorDistance3(positions[prev], positions[i]);
    } break;
    case 3:
        for (S00d7cf00_Triangle* t = m_firstTriangle; t; t = t->m_next) {
            for (int i = 0; i < 3; ++i) {
                S00d7cf00_HullEdge e(t, i);
                if (e.isMaster()) {
                    if (t->m_iTriangleValueAtOffset0x38 == -1 || !e.samePlane())
                        sum += vectorDistance3(e.start()->m_pObservedSource, e.end()->m_pObservedSource);
                }
            }
        }
        break;
    }
    return sum;
}

using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_add_ss;
using ::_mm_shuffle_ps;
using ::_mm_xor_ps;
using ::_mm_store_ss;
extern "C" void* __cdecl memcpy(void* d, const void* s, unsigned int n);

extern double DAT_01032980;
extern double DAT_0101dae8;
extern unsigned int DAT_0126a3e0;

struct __declspec(align(16)) S_00d827b0_Sign {
    unsigned int a, b, c, d;
};
extern LocalM128 DAT_010c44d0;



struct __declspec(align(16)) S_00d827b0_Xf {
    float c0x, c0y, c0z, c0w;
    float c1x, c1y, c1z, c1w;
    float c2x, c2y, c2z, c2w;
    float c3x, c3y, c3z, c3w;
    void MultiplyInPlace(const S_00d827b0_Xf* other);
};

static __forceinline LocalM128 S_00d827b0_load(const void* p) { return *(const LocalM128*)p; }
static __forceinline void S_00d827b0_store(void* p, LocalM128 v) { *(LocalM128*)p = v; }
static __forceinline unsigned int S_00d827b0_ubit(const void* p) { return *(const unsigned int*)p; }
static __forceinline void S_00d827b0_uput(void* p, unsigned int u) { *(unsigned int*)p = u; }

static __forceinline float supportDot(const hkVector4& a, const hkVector4& b) {
    LocalM128 prod = _mm_mul_ps(S_00d827b0_load(&a.quad.m128_f32[0]), S_00d827b0_load(&b.quad.m128_f32[0]));
    LocalM128 ys = _mm_shuffle_ps(prod, prod, 0x55);
    LocalM128 zs = _mm_shuffle_ps(prod, prod, 0xaa);
    float dot;
    _mm_store_ss(&dot, _mm_add_ss(zs, _mm_add_ss(ys, prod)));
    return dot;
}

struct S_00d827b0_Param {
    hkVector4* points;
    int count;
};

struct S_00d827b0_Node {
    S_00d827b0_Node* next;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 pos;
};

struct PlaneFace {
    PlaneFace* next;
    int unk04;
    S_00d827b0_Node* vertices[3];
};

extern "C" void __cdecl Hkgpconvexhull_ComputeValues_00d74c70(hkVector4* v, float t, S_00d827b0_Xf* out);

struct FixBool { char value; };

struct S_00d827b0_Owner {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20;
    S_00d827b0_Node* m_pFirstNode;
    int m_uiItemCount;
    int unk2c, unk30, unk34, unk38;
    PlaneFace* m_faces;
    int unk40, unk44, unk48;
    int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    int unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    int unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8;
    int unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8;
    int unkec, unkf0, unkf4, unkf8, unkfc, unk100, unk104, unk108;
    int unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128;
    int unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148;
    int unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168;
    int unk16c, unk170, unk174, unk178, unk17c, unk180, unk184, unk188;
    int unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8;
    int unk1ac, unk1b0;
    FixBool m_b1b4;
    FixBool m_b1b5;

    float ProcessEntries_00d7a810(S_00d827b0_Param* p, S_00d827b0_Xf* xf, hkVector4* out);
    void ProcessEntries_00d7a0b0(S_00d827b0_Xf* xf, hkVector4* dir, hkVector4* out);
    void hkgpConvexHullImpl_build(hkVector4* data, int n, int a, int b);
    void ProcessEntries_00d7d2a0();
    void hkgpConvexHullImpl_buildMassProperties_hkgpConvexHullImpl_PositionAsTransform();
    void CopyMemory_00d827b0(S_00d827b0_Param* param);
};


using ::_mm_sub_ps;
using ::_mm_load_ss;
using ::_mm_sub_ss;
using ::_mm_mul_ss;
using ::_mm_rsqrt_ss;
using ::_mm_cmpeq_ss;
using ::_mm_andnot_ps;
extern float DAT_01017718;
extern float DAT_01016248;
extern float DAT_01011d78;

static __forceinline LocalM128 dotThree(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(p,p,0xaa), _mm_add_ss(_mm_shuffle_ps(p,p,0x55),p));
}

// src: GUESS 0x00d7a810 (confidence: low)
__declspec(noinline) float S_00d827b0_Owner::ProcessEntries_00d7a810(S_00d827b0_Param* p, S_00d827b0_Xf* xf, hkVector4* out)
{
    float best = DAT_0104da4c;
    for (int i=0; i<p->count; ++i) {
        for (PlaneFace* face = m_faces; face; face=face->next) {
            hkVector4 positions[3];
            for (int j=0; j<3; ++j) {
                LocalM128 q=face->vertices[j]->pos.m_vComponents;
                positions[j].quad=_mm_add_ps(_mm_add_ps(_mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(q,q,0),S_00d827b0_load(&xf->c0x)),
                    _mm_mul_ps(_mm_shuffle_ps(q,q,0x55),S_00d827b0_load(&xf->c1x))),
                    _mm_mul_ps(_mm_shuffle_ps(q,q,0xaa),S_00d827b0_load(&xf->c2x))),
                    S_00d827b0_load(&xf->c3x));
            }
            LocalM128 a=_mm_sub_ps(positions[1].quad,positions[0].quad);
            LocalM128 b=_mm_sub_ps(positions[2].quad,positions[0].quad);
            LocalM128 n=_mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(b,b,0xd2),_mm_shuffle_ps(a,a,0xc9)),
                _mm_mul_ps(_mm_shuffle_ps(b,b,0xc9),_mm_shuffle_ps(a,a,0xd2)));
            LocalM128 lengthSquared=dotThree(n,n);
            LocalM128 r=_mm_rsqrt_ss(lengthSquared);
            LocalM128 inv=_mm_mul_ss(_mm_mul_ss(_mm_load_ss(&DAT_01016248),r),
                _mm_sub_ss(_mm_load_ss(&DAT_01017718),_mm_mul_ss(_mm_mul_ss(lengthSquared,r),r)));
            inv=_mm_andnot_ps(_mm_cmpeq_ss(lengthSquared,_mm_load_ss(&DAT_01011d78)),inv);
            hkVector4 plane;
            plane.quad=_mm_mul_ps(_mm_shuffle_ps(inv,inv,0),n);
            float offset;
            _mm_store_ss(&offset,_mm_sub_ss(DAT_010c7160,dotThree(plane.quad,positions[0].quad)));
            plane.quad.m128_f32[3]=offset;
            float distance;
            _mm_store_ss(&distance,_mm_add_ss(dotThree(p->points[i].m_vComponents,plane.quad),_mm_shuffle_ps(plane.quad,plane.quad,0xff)));
            if (best<distance) { best=distance; out->quad=plane.quad; }
        }
    }
    return best;
}

// src: GUESS 0x00d74c70 (confidence: low)
extern "C" __declspec(noinline) void __cdecl Hkgpconvexhull_ComputeValues_00d74c70(hkVector4* v, float t, S_00d827b0_Xf* out)
{
    float scale=t-1.0f;
    LocalM128 s=_mm_load_ss(&scale);
    s=_mm_shuffle_ps(s,s,0);
    LocalM128 scaled=_mm_mul_ps(s,v->quad);
    LocalM128 squared=_mm_mul_ps(s,_mm_mul_ps(v->quad,v->quad));
    out->c0x=1.0f+squared.m128_f32[0];
    out->c1x=v->quad.m128_f32[0]*scaled.m128_f32[1];
    out->c2x=v->quad.m128_f32[0]*scaled.m128_f32[2];
    out->c3x=scaled.m128_f32[0]*v->quad.m128_f32[3];
    out->c0y=out->c1x;
    out->c1y=1.0f+squared.m128_f32[1];
    out->c2y=v->quad.m128_f32[1]*scaled.m128_f32[2];
    out->c3y=scaled.m128_f32[1]*v->quad.m128_f32[3];
    out->c0z=out->c2x;
    out->c1z=out->c2y;
    out->c2z=1.0f+squared.m128_f32[2];
    out->c3z=scaled.m128_f32[2]*v->quad.m128_f32[3];
    out->c0w=out->c1w=out->c2w=0.0f;
    out->c3w=1.0f;
}


// @fnv 0x00d827b0
// src: GUESS 0x00d827b0 (confidence: low)
void S_00d827b0_Owner::CopyMemory_00d827b0(S_00d827b0_Param* param)
{
    FixBool b5 = m_b1b5;
    FixBool b4 = m_b1b4;
    int limit = param->count + 0x40;
    S_00d827b0_Xf xf;
    memcpy(&xf, &DAT_0126a3e0, 0x40);
    int iter = 0;
    unsigned char ok = 0;
    if (limit > 0) {
        do {
            LocalM128 plane;
            hkVector4& vec = *(hkVector4*)&plane;
            float result = ProcessEntries_00d7a810(param, &xf, &vec);
            if (!(result > DAT_01032980))
                break;

            hkVector4 neg;
            LocalM128 nq = _mm_xor_ps(DAT_010c44d0, plane);
            hkVector4 support;
            const unsigned int* g = (const unsigned int*)&DAT_01267e30;
            unsigned int gx = g[0];
            unsigned int gy = g[1];
            unsigned int gz = g[2];
            unsigned int gw = g[3];
            S_00d827b0_store(&neg.quad.m128_f32[0], nq);
            S_00d827b0_uput(&support.quad.m128_f32[0], gx);
            S_00d827b0_uput(&support.quad.m128_f32[1], gy);
            S_00d827b0_uput(&support.quad.m128_f32[2], gz);
            S_00d827b0_uput(&support.quad.m128_f32[3], gw);
            ProcessEntries_00d7a0b0(&xf, &neg, &support);

            const float& wkeep = plane.m128_f32[3];
            LocalM128 prod = _mm_mul_ps(support.quad, plane);
            float dot;
            _mm_store_ss(&dot, _mm_add_ss(_mm_shuffle_ps(prod,prod,0xaa),_mm_add_ss(_mm_shuffle_ps(prod,prod,0x55),prod)));
            float negSum=-(wkeep+dot);
            if (!(negSum * negSum > DAT_0101dae8))
                break;

            vec.quad.m128_f32[3] = -dot;
            S_00d827b0_Xf backup;
            memcpy(&backup, &xf, 0x40);
            float t = (negSum + result) / negSum;
            Hkgpconvexhull_ComputeValues_00d74c70(&vec, t, &xf);
            xf.MultiplyInPlace(&backup);
            ok = 1;
            ++iter;
        } while (iter < limit);

        if (ok) {
            D76250VectorArrayLocalForm arr;
            int extra = m_uiItemCount;
            arr.m_data = 0;
            arr.m_iElementCount = 0;
            arr.m_iCapacityState = 0x80000000;
            D76250Allocator& alloc = fnvc_adapt::hkMemoryRouter_getInstance().heap();
            int oldSize = arr.m_iElementCount;
            int need = oldSize + extra;
            int cap = arr.m_iCapacityState & 0x3fffffff;
            if (cap < need) {
                int cap2 = cap + cap;
                int newSize = (need < cap2) ? cap2 : need;
                hkArrayUtil__reserve(&alloc, &arr, newSize, (int)sizeof(hkVector4));
            }
            arr.m_iElementCount = arr.m_iElementCount + extra;
            hkVector4* dst = arr.m_data + oldSize;
            for (S_00d827b0_Node* n = m_pFirstNode; n; n = n->next)
                *dst++ = n->pos;

            for (int i = 0; i < arr.m_iElementCount; ++i) {
                unsigned int* s = (unsigned int*)&arr.m_data[i].m_vComponents;
                hkVector4 v;
                S_00d827b0_uput(&v.quad.m128_f32[0], s[0]);
                S_00d827b0_uput(&v.quad.m128_f32[1], s[1]);
                S_00d827b0_uput(&v.quad.m128_f32[2], s[2]);
                S_00d827b0_uput(&v.quad.m128_f32[3], s[3]);
                LocalM128 q = S_00d827b0_load(&v.quad.m128_f32[0]);
                LocalM128 yy = _mm_shuffle_ps(q, q, 0x55);
                LocalM128 xx = _mm_shuffle_ps(q, q, 0x00);
                LocalM128 zz = _mm_shuffle_ps(q, q, 0xaa);
                arr.m_data[i].m_vComponents = _mm_add_ps(
                    _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(yy, S_00d827b0_load(&xf.c1x)), _mm_mul_ps(xx, S_00d827b0_load(&xf.c0x))),
                        _mm_mul_ps(zz, S_00d827b0_load(&xf.c2x))),
                    S_00d827b0_load(&xf.c3x));
            }

            hkgpConvexHullImpl_build(arr.m_data, arr.m_iElementCount, 0, 0);
            if (b5.value)
                ProcessEntries_00d7d2a0();
            if (b4.value)
                hkgpConvexHullImpl_buildMassProperties_hkgpConvexHullImpl_PositionAsTransform();

            S_00d7a010_Alloc& heap = (S_00d7a010_Alloc&)fnvc_adapt::hkMemoryRouter_getInstance().heap();
            arr.m_iElementCount = 0;
            if ((arr.m_iCapacityState & 0x80000000) == 0)
                heap.ReturnMemory(arr.m_data, (arr.m_iCapacityState & 0x3fffffff) * sizeof(hkVector4));
        }
    }
}

using ::_mm_add_ps;



struct S00d82ad0_Vtx {
    S00d82ad0_Vtx* next;
    S00d82ad0_Vtx* prev;
    int unk08;
    int unk0c;
    hkVector4 m_pObservedSource;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    float m_data;
};

struct S00d82ad0_Tri {
    S00d82ad0_Tri* next;
    S00d82ad0_Tri* prev;
    S00d82ad0_Vtx* m_kVertices[3];
    unsigned long m_ppLinks[3];
    __forceinline S00d82ad0_Vtx*& vertex(unsigned i) { return m_kVertices[i]; }
    __forceinline unsigned long& link(unsigned i) { return m_ppLinks[i]; }
};

struct S00d82ad0_E {
    S00d82ad0_Tri* m_pkTriangle;
    unsigned m_uiEdgeIndex;
    static __forceinline unsigned ip1mod3(unsigned i) { return (0x09 >> (i << 1)) & 3; }
    static __forceinline unsigned ip2mod3(unsigned i) { return (0x12 >> (i << 1)) & 3; }
    __forceinline S00d82ad0_E() {}
    __forceinline S00d82ad0_E(S00d82ad0_Tri* t, unsigned i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    __forceinline S00d82ad0_E(const unsigned long& id) { unsigned long uid = id; m_uiEdgeIndex = (unsigned)(uid & 3); uid &= ~3; m_pkTriangle = *(S00d82ad0_Tri**)&uid; }
    __forceinline S00d82ad0_E next() const { return S00d82ad0_E(m_pkTriangle, ip1mod3(m_uiEdgeIndex)); }
    __forceinline S00d82ad0_E prev() const { return S00d82ad0_E(m_pkTriangle, ip2mod3(m_uiEdgeIndex)); }
    __forceinline S00d82ad0_E link() const { return S00d82ad0_E(m_pkTriangle->link(m_uiEdgeIndex)); }
    __forceinline S00d82ad0_E turnCcw() const { return link().next(); }
    __forceinline S00d82ad0_E turnCw() const { return prev().link(); }
    __forceinline unsigned long uid() const { return (*(const unsigned long*)&m_pkTriangle) + (unsigned long)m_uiEdgeIndex; }
    __forceinline S00d82ad0_Vtx*& start() const { return m_pkTriangle->vertex(m_uiEdgeIndex); }
    __forceinline S00d82ad0_Vtx*& end() const { return m_pkTriangle->vertex(ip1mod3(m_uiEdgeIndex)); }
    __forceinline S00d82ad0_Vtx*& apex() const { return m_pkTriangle->vertex(ip2mod3(m_uiEdgeIndex)); }
    __forceinline S00d82ad0_E self() const { return S00d82ad0_E(m_pkTriangle, m_uiEdgeIndex); }
    __forceinline bool isValid() const { return m_pkTriangle != 0; }
    __forceinline bool operator!=(const S00d82ad0_E& e) const { return uid() != e.uid(); }
    template <class F>
    __forceinline void applyFan(F& fnc) const
    {
        S00d82ad0_E base(self());
        S00d82ad0_E curr(base);
        do {
            if (fnc(curr)) curr = curr.turnCw(); else return;
        } while (curr.isValid() && (curr != base));
        if (!curr.isValid()) {
            curr = base.turnCcw();
            while (curr.isValid()) {
                if (fnc(curr)) curr = curr.turnCcw(); else return;
            }
        }
    }
};

struct S00d82ad0_Edge {
    S00d82ad0_Tri* m_pkTriangle;
    int m_uiEdgeIndex;
    float m_uiFilterValue;
    __forceinline S00d82ad0_Edge() {}
    __forceinline S00d82ad0_Vtx* vertex() const { int i = m_uiEdgeIndex; return m_pkTriangle->m_kVertices[i]; }
};

struct S00d82ad0_Less {
};

void __cdecl hkArrayUtil__reserve(void* alloc, void* arr, int n, int elemSize);
void __cdecl hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedEdge_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedEdge(S00d82ad0_Edge* data, int lo, int hi, S00d82ad0_Less cmp);

struct S00d82ad0_Alloc {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S00d82ad0_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d82ad0_Alloc* m_pStreamAllocator;
    S00d82ad0_Alloc& heap() { return *m_pStreamAllocator; }
};

static __forceinline S00d82ad0_Router* S00d82ad0_router()
{
    return (S00d82ad0_Router*)hkMemoryRouter_getInstance();
}

struct S00d82ad0_VecArr {
    hkVector4* m_data;
    int m_iElementCount;
    int m_capFlags;
    S00d82ad0_VecArr() : m_data(0), m_iElementCount(0), m_capFlags((int)0x80000000) {}
    void destroy()
    {
        S00d82ad0_Alloc& a = S00d82ad0_router()->heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0) a.ReturnMemory(m_data, (m_capFlags & 0x3fffffff) * sizeof(hkVector4));
        m_data = 0;
        m_capFlags = (int)0x80000000;
    }
    __forceinline hkVector4* expandBy(int n)
    {
        S00d82ad0_Alloc& a = S00d82ad0_router()->heap();
        int oldSize = m_iElementCount;
        int newSize = oldSize + n;
        int cap = m_capFlags & 0x3fffffff;
        if (cap < newSize) {
            int c2 = cap + cap;
            hkArrayUtil__reserve(&a, this, newSize < c2 ? c2 : newSize, sizeof(hkVector4));
        }
        m_iElementCount += n;
        return m_data + oldSize;
    }
};

struct S00d82ad0_EdgeArr {
    S00d82ad0_Edge* m_data;
    int m_iElementCount;
    int m_capFlags;
    S00d82ad0_EdgeArr() : m_data(0), m_iElementCount(0), m_capFlags((int)0x80000000) {}
    void destroy()
    {
        S00d82ad0_Alloc& a = S00d82ad0_router()->heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0) a.ReturnMemory(m_data, (m_capFlags & 0x3fffffff) * sizeof(S00d82ad0_Edge));
        m_data = 0;
        m_capFlags = (int)0x80000000;
    }
    void reserve(int n)
    {
        S00d82ad0_Router* r = S00d82ad0_router();
        if ((m_capFlags & 0x3fffffff) < n) hkArrayUtil__reserve(r->m_pStreamAllocator, this, n, sizeof(S00d82ad0_Edge));
    }
    S00d82ad0_Edge& AllocatePair()
    {
        S00d82ad0_Router* r = S00d82ad0_router();
        if (m_iElementCount == (m_capFlags & 0x3fffffff)) ResizeAudioStream(r->m_pStreamAllocator, this, sizeof(S00d82ad0_Edge));
        S00d82ad0_Edge* t = m_data + m_iElementCount;
        for (int i = 0; i < 1; ++i) {
            ::new ((void*)(t + i)) S00d82ad0_Edge;
        }
        return m_data[m_iElementCount++];
    }
};

struct S00d82ad0_Stream {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(char* buf, int size);
    S00d82ad0_Stream& ProcessAndReturnValue_00cc01c0(const char* s);
    S00d82ad0_Stream& WriteInt(int v);
    void FUN_00cc00e0();
};

struct S00d82ad0_Err {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int type, int id, const char* text, const char* file, int line);
};

extern S00d82ad0_Err* g_01268360;
extern const float g_01011d78;

struct S00d82ad0_Tri3 {
    hkVector4 a;
    hkVector4 b;
    hkVector4 c;
    hkVector4& FUN_00cd51c0(hkVector4& out);
};

struct S00d82ad0_VtxList {
    int unk00;
    int unk04;
    int unk08;
    S00d82ad0_Vtx* m_pHeadNode;
    int m_iElementCount;
    void hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_release(S00d82ad0_Vtx* v);
    void remove(S00d82ad0_Vtx* v)
    {
        S00d82ad0_Vtx* n = v->next;
        S00d82ad0_Vtx* p = v->prev;
        if (n) n->prev = p;
        if (p) p->next = n;
        else m_pHeadNode = n;
        --m_iElementCount;
        hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_release(v);
    }
};



struct S00d82ad0_Hull {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S00d82ad0_VtxList m_kVertices;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    S00d82ad0_Tri* m_firstTriangle;
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    hkVector4 m_offset;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    hkVector4 m_vScale;
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
    int m_eVertexFloatDimensions;
    int unk1ac;
    int unk1b0;
    char m_hasPlanes;
    char m_bSecondImplementationFlag;

    static __forceinline LocalM128 position(const S00d82ad0_Vtx* v, const LocalM128& scale, const LocalM128& offset, const float& w)
    {
        LocalM128 p = _mm_setr_ps((float)v->m_uiX, (float)v->m_uiY, (float)v->m_uiZ, 1.0f);
        return _mm_add_ps(_mm_mul_ps(p, scale), offset);
    }
    __forceinline hkVector4 transform(const S00d82ad0_Vtx& v) const
    {
        hkVector4 r;
        r.m_vComponents = _mm_setr_ps((float)v.m_uiX, (float)v.m_uiY, (float)v.m_uiZ, 0.0f);
        r.m_vComponents = _mm_mul_ps(r.m_vComponents, m_vScale.m_vComponents);
        r.m_vComponents = _mm_add_ps(r.m_vComponents, m_offset.m_vComponents);
        return r;
    }

    bool ProcessEntries_00d82ad0(int numVerticesToKeep, bool abOptionalVertexReduction);
    void CopyMemory_00d827b0(S00d82ad0_VecArr& v);
    void ProcessEntries_00d7d2a0();
    void hkgpConvexHullImpl_buildMassProperties_hkgpConvexHullImpl_PositionAsTransform();
    int hkgpConvexHullImpl_build(hkVector4* p, int n, int a, int b);
};

template <class F>
static __forceinline void S00d82ad0_fan(const S00d82ad0_E& start, F& f)
{
    S00d82ad0_E e = start;
    do {
        f(e);
        e = e.prev().link();
    } while (e.isValid() && e != start);
    if (!e.isValid()) {
        e = start.link().next();
        while (e.isValid()) {
            f(e);
            e = e.link().next();
        }
    }
}

static __forceinline float S00d82ad0_tetrahedronVolume6(const hkVector4& a, const hkVector4& b, const hkVector4& c, const hkVector4& d)
{
    S00d82ad0_Tri3 m;
    m.a.m_vComponents = _mm_sub_ps(b.m_vComponents, a.m_vComponents);
    m.b.m_vComponents = _mm_sub_ps(c.m_vComponents, a.m_vComponents);
    m.c.m_vComponents = _mm_sub_ps(d.m_vComponents, a.m_vComponents);
    hkVector4 out;
    float f;
    _mm_store_ss(&f, m.FUN_00cd51c0(out).m_vComponents);
    return f;
}

struct S00d82ad0_AreaFn {
    const S00d82ad0_Hull* m_pHull;
    float m_area;
    __forceinline S00d82ad0_AreaFn(const S00d82ad0_Hull* h) : m_pHull(h), m_area(0.0f) {}
    __forceinline bool operator()(S00d82ad0_E e)
    {
        const hkVector4 a = m_pHull->transform(*e.end());
        const hkVector4 b = m_pHull->transform(*e.start());
        const hkVector4 c = m_pHull->transform(*e.apex());
        const hkVector4 d = m_pHull->transform(*e.link().apex());
        m_area += S00d82ad0_tetrahedronVolume6(a, b, c, d);
        return true;
    }
};

struct S00d82ad0_CountFn {
    bool m_changed;
    __forceinline S00d82ad0_CountFn() : m_changed(false) {}
    __forceinline bool operator()(S00d82ad0_E e)
    {
        float& c = e.end()->m_data;
        float d = c + 1.0f;
        c = d;
        if (d > 1.0f) m_changed = true;
        return true;
    }
};

template <class T, class L>
static __forceinline void S00d82ad0_sort(T* p, int size, L cmp = L())
{
    if (size > 1) hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedEdge_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedEdge(p, 0, size - 1, cmp);
}

// @fnv 0x00d82ad0
// src: GUESS 0x00d82ad0 (confidence: low)
bool S00d82ad0_Hull::ProcessEntries_00d82ad0(int numVerticesToKeep, bool abOptionalVertexReduction)
{
    if (numVerticesToKeep < 4) numVerticesToKeep = 4;
    if (m_kVertices.m_iElementCount > numVerticesToKeep) {
        char hasPlanes = m_bSecondImplementationFlag;
        char hasIndexing = m_hasPlanes;
        S00d82ad0_VecArr originalVertices;
        S00d82ad0_EdgeArr edges;
        if (m_eVertexFloatDimensions != 3) {
            char buf[0x200];
            S00d82ad0_Stream s;
            s.FUN_00cb1600(buf, 0x200);
            s.ProcessAndReturnValue_00cc01c0("Invalid dimension for this operation (").WriteInt(3).ProcessAndReturnValue_00cc01c0(" required)");
            if (g_01268360->message(3, 0x79f9d888, buf, ".\\GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp", 0x154)) {
                __debugbreak();
            }
            s.FUN_00cc00e0();
        }
        if (abOptionalVertexReduction) {
            hkVector4* dst = originalVertices.expandBy(m_kVertices.m_iElementCount);
            for (S00d82ad0_Vtx* v = m_kVertices.m_pHeadNode; v; v = v->next) {
                *dst++ = v->m_pObservedSource;
            }
        }
        edges.reserve(m_kVertices.m_iElementCount);
        while (m_kVertices.m_iElementCount > numVerticesToKeep) {
                        edges.m_iElementCount = 0;
            for (S00d82ad0_Vtx* v = m_kVertices.m_pHeadNode; v; v = v->next) v->m_data = 0.0f;
            for (S00d82ad0_Tri* t = m_firstTriangle; t; t = t->next) {
                for (int i = 0; i < 3; ++i) {
                    if (t->m_kVertices[i]->m_data == 0.0f) {
                        S00d82ad0_AreaFn fn(this);
                        S00d82ad0_E(t, i).applyFan(fn);
                        float area = fn.m_area;
                        S00d82ad0_Edge& ne = edges.AllocatePair();
                        ne.m_uiFilterValue = area;
                        ne.m_pkTriangle = t;
                        ne.m_uiEdgeIndex = i;
                        t->m_kVertices[i]->m_data = 1.0f;
                    }
                }
            }
            for (S00d82ad0_Vtx* v = m_kVertices.m_pHeadNode; v; v = v->next) v->m_data = 0.0f;
            S00d82ad0_sort<S00d82ad0_Edge, S00d82ad0_Less>(edges.m_data, edges.m_iElementCount);
            int numToRemove = m_kVertices.m_iElementCount - numVerticesToKeep;
            int numRemoved = 0;
            if (numToRemove > 0) {
                for (; numRemoved < numToRemove; ++numRemoved) {
                    edges.m_data[numRemoved].vertex()->m_data += 1.0f;
                    S00d82ad0_CountFn fn;
                    S00d82ad0_E(edges.m_data[numRemoved].m_pkTriangle, edges.m_data[numRemoved].m_uiEdgeIndex).applyFan(fn);
                    if (fn.m_changed) break;
                }
                for (int j = 0; j < numRemoved; ++j) {
                    m_kVertices.remove(edges.m_data[j].vertex());
                }
            }
            S00d82ad0_VecArr positions;
            hkVector4* dst = positions.expandBy(m_kVertices.m_iElementCount);
            for (S00d82ad0_Vtx* v = m_kVertices.m_pHeadNode; v; v = v->next) {
                *dst++ = v->m_pObservedSource;
            }
            if (hkgpConvexHullImpl_build(positions.m_data, positions.m_iElementCount, 0, 0) == -1) {
                positions.destroy();
                edges.destroy();
                originalVertices.destroy();
                return false;
            }
            positions.destroy();
        }
        if (abOptionalVertexReduction) CopyMemory_00d827b0(originalVertices);
        if (hasPlanes) ProcessEntries_00d7d2a0();
        if (hasIndexing) hkgpConvexHullImpl_buildMassProperties_hkgpConvexHullImpl_PositionAsTransform();
        edges.destroy();
        originalVertices.destroy();
    }
    return true;
}

#include <math.h>
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_add_ss;
using ::_mm_shuffle_ps;
using ::_mm_load_ps1;
using ::_mm_load_ss;
static __forceinline LocalM128 HullBroadcast(float f) { LocalM128 v=_mm_load_ss(&f); return _mm_shuffle_ps(v,v,0); }
using ::_mm_store_ss;
using ::_mm_store_ps;
extern "C" double __cdecl fabs(double);
struct HullAllocator {
    virtual void v00();
    __declspec(nothrow) virtual void* BlockAlloc(int iSize) throw();
    virtual void v08();
    virtual void v0c();
    __declspec(nothrow) virtual void BufFree(void* p, int iSize) throw();
};
struct HullMemory {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HullAllocator* m_pAllocator;
};
void __cdecl hkArrayUtil__reserve(HullAllocator* pAlloc, void* pArray, int iNewCap, int iElemSize) throw();
void __cdecl ResizeAudioStream(HullAllocator* pAlloc, void* pArray, int iElemSize) throw();
struct ErrReporter {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    __declspec(nothrow) virtual int Message(int iType, int aiSoundId, const char* pDesc, const char* pFile, int iLine) throw();
};
struct ErrStream {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __declspec(nothrow) ErrStream(void* pBuf, int iSize) throw();
    __declspec(nothrow) ~ErrStream() throw();
    __declspec(nothrow) ErrStream& operator<<(const char* s) throw();
};
extern const double DAT_01012060;
extern const double DAT_01011588;
extern const LocalM128 DAT_010ec7f0;
class HullVec {
    LocalM128 q;
public:
    __forceinline operator LocalM128() const { return q; }
    __forceinline void operator=(const HullVec& v) { q=v.q; }
    __forceinline void setInterpolate4(const HullVec& first,const HullVec& second,float fraction) {
        LocalM128 t=HullBroadcast(fraction);
        LocalM128 s=_mm_sub_ps(DAT_010ec7f0,t);
        q=_mm_add_ps(_mm_mul_ps(s,first.q),_mm_mul_ps(t,second.q));
    }
    __forceinline float dot4xyz1(const HullVec& v) const {
        LocalM128 product=_mm_mul_ps(q,v.q);
        LocalM128 xy=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
        LocalM128 zw=_mm_add_ss(_mm_shuffle_ps(product,product,0xaa),_mm_shuffle_ps(q,q,0xff));
        float value; _mm_store_ss(&value,_mm_add_ps(xy,zw)); return value;
    }
};
struct SplitVertex {
    SplitVertex* m_pNext;
    int unk04;
    int unk08;
    int unk0c;
    HullVec m_pos;
    int unk20;
    int unk24;
    int unk28;
    float m_fDist;
};
struct SplitTriangle {
    SplitTriangle* m_pNext;
    int unk04;
    SplitVertex* m_pVerts[3];
};
struct HullConfig {
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
};
struct HullVector4 {
    LocalM128 m_vComponents;
    void Set(const LocalM128& v) throw() { m_vComponents = v; }
};
struct VecArrayBase {
    HullVec* m_pData;
    int m_uiLogicalSize;
    int m_iCapAndFlags;
    __forceinline HullVec& operator[](int i) { return m_pData[i]; }
    __forceinline int GetSize() const { return m_uiLogicalSize; }
    __forceinline void Clear() throw()
    {
        HullMemory* pMem = ((HullMemory*)&fnvc_adapt::hkMemoryRouter_getInstance());
        HullAllocator* pAlloc = pMem->m_pAllocator;
        int iCap = m_iCapAndFlags;
        m_uiLogicalSize = 0;
        if ((iCap & 0x80000000) == 0) {
            pAlloc->BufFree(m_pData, (iCap & 0x3fffffff) * 16);
        }
        m_pData = 0;
        m_iCapAndFlags = 0x80000000;
    }
    __forceinline void Reserve(int n) throw()
    {
        HullMemory* pMem = ((HullMemory*)&fnvc_adapt::hkMemoryRouter_getInstance());
        HullAllocator* pAlloc = pMem->m_pAllocator;
        int iCap = m_iCapAndFlags & 0x3fffffff;
        if (iCap < n) {
            int iCap2 = iCap * 2;
            hkArrayUtil__reserve((D76250Allocator*)pAlloc, this, n < iCap2 ? iCap2 : n, 16);
        }
    }
    __forceinline void PushBack(const HullVec& v) throw()
    {
        HullMemory* pMem = ((HullMemory*)&fnvc_adapt::hkMemoryRouter_getInstance());
        if (m_uiLogicalSize == (m_iCapAndFlags & 0x3fffffff)) {
            ResizeAudioStream((D76250Allocator*)pMem->m_pAllocator, this, 16);
        }
        HullVec* dst=m_pData+m_uiLogicalSize; for(int i=0;i<1;++i) dst[i]=v;
        m_uiLogicalSize++;
    }
};
struct VecArray : VecArrayBase {
    __forceinline VecArray() throw()
    {
        m_pData = 0;
        m_uiLogicalSize = 0;
        m_iCapAndFlags = 0x80000000;
    }
    __forceinline ~VecArray() throw()
    {
        Clear();
    }
};
struct ErrorWork {
    int unk00, unk04, unk08;
    void FUN_00cb1600(void* buf, int size) throw();
    ErrorWork& ProcessAndReturnValue_00cc01c0(const char* text) throw();
    void FUN_00cc00e0() throw();
};
struct __declspec(align(16)) SplitRawVec { unsigned int x,y,z,w; };
struct SplitWork {
    VecArrayBase back;
    union { float rounded; SplitVertex** edge; } scratch;
    union { VecArrayBase front; SplitRawVec position; ErrorWork stream; } current;
};
inline void* operator new(unsigned int, HullVec* place) { return place; }
struct HullImpl;
struct FUN_00d76ca0 {
    __declspec(nothrow) virtual ~FUN_00d76ca0() throw();
    unsigned short m_uMemSize;
    unsigned short m_uRefCount;
    HullImpl* m_pImpl;
    int unk0c;
    int unk10;
    __declspec(nothrow) FUN_00d76ca0() throw();
    __declspec(nothrow) static void* operator new(unsigned int n)
    {
        HullMemory* mem = (HullMemory*)&fnvc_adapt::hkMemoryRouter_getInstance();
        FUN_00d76ca0* p = (FUN_00d76ca0*)mem->m_pAllocator->BlockAlloc(n);
        p->m_uMemSize = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p) throw();
};
struct HullImpl {
    HullConfig m_pConfiguration;
    int unk010; int unk014; int unk018; int unk01c; int unk020;
    SplitVertex* m_pVertexData;
    int m_iNumVertices;
    int unk02c; int unk030; int unk034; int unk038;
    SplitTriangle* m_pTriangles;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    HullVec m_vE0;
    int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4;
    int m_iDimension;
    __declspec(noinline) int ProcessEntries_00d7a200(const HullVec&,float,int*,float*) const;
    int hkgpConvexHullImpl_build(const HullVec*,int,bool,const HullImpl*);
    int AllocateStorage_00d83430(const HullVec& plane,FUN_00d76ca0** ppFront,FUN_00d76ca0** ppBack,float fEps) const;
};
inline float HullCrtAbs(float f) { return (float)fabs((double)f); }
inline float HullFabsf(float f) { return ::fabsf(f); }
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
inline float StageHigh(float f,float& dst){dst=(float)fabs((double)f); _ReadWriteBarrier(); return dst;}
inline float StageLow(float f,float& dst){dst=(float)fabs((double)f); _ReadWriteBarrier(); double result=dst; _ReadWriteBarrier(); dst=result; _ReadWriteBarrier(); return dst;}
template<class T> inline T HullMin(T a,T b) { return a<b?a:b; }
template<class T> inline T HullMax(T a,T b) { return a>b?a:b; }
// src: GUESS 0x00d7a200 (confidence: low)
__declspec(noinline) int HullImpl::ProcessEntries_00d7a200(const HullVec& plane,float eps,int* counts,float* bounds) const {
 float localBounds[2];
 if(!bounds) bounds=localBounds;
 counts[0]=counts[1]=0;
 bounds[1]=0; bounds[0]=0;
 for(SplitVertex* v=m_pVertexData;v;v=v->m_pNext) {
   float distance=plane.dot4xyz1(v->m_pos);
   if(v->unk04==0) { bounds[1]=distance; bounds[0]=distance; }
   else { bounds[0]=HullMin(distance,bounds[0]); bounds[1]=HullMax(distance,bounds[1]); }
   if(HullFabsf(distance)<eps) v->m_fDist=0;
   else { v->m_fDist=distance; if(distance>0) ++counts[0]; else ++counts[1]; }
 }
 if(counts[0] && counts[1]) return 3;
 if(counts[1]>counts[0]) return 2;
 if(counts[0]) return 1;
 return 0;
}
// @fnv 0x00d83430
// src: GUESS 0x00d83430 (confidence: low)
int HullImpl::AllocateStorage_00d83430(const HullVec& plane, FUN_00d76ca0** ppFront, FUN_00d76ca0** ppBack, float fEps) const
{
    SplitWork workspace;
    {
        FUN_00d76ca0** pp0 = ppFront;
        if (pp0 != 0) {
            *pp0 = 0;
        }
        FUN_00d76ca0** pp1 = ppBack;
        if (pp1 != 0) {
            *pp1 = 0;
        }
    }
    switch (m_iDimension) {
    case 3: {
        int counts[2]={0,0};
        float range[2];
        if (ProcessEntries_00d7a200(plane,fEps,counts,range)==3) {
        VecArrayBase& front=workspace.current.front; front.m_pData=0; front.m_uiLogicalSize=0; front.m_iCapAndFlags=0x80000000;
VecArrayBase& back=workspace.back; back.m_pData=0; back.m_uiLogicalSize=0; back.m_iCapAndFlags=0x80000000;
        float rMin=range[0],rMax=range[1];
        {
            float ext = rMax - rMin;
            workspace.scratch.rounded=HullMin<double>(StageLow(rMin,workspace.scratch.rounded),StageHigh(rMax,workspace.scratch.rounded)); _ReadWriteBarrier();
            if (ext <= fEps || workspace.scratch.rounded <= fEps) {
                if ((rMin + rMax) * DAT_01011588 >= DAT_01012060) {
                    back.Clear(); front.Clear(); return 1;
                }
                back.Clear(); front.Clear(); return 2;
            }
        }
        front.Reserve(m_iNumVertices / 4 + counts[0]);
        back.Reserve(m_iNumVertices / 4 + counts[1]);
            SplitVertex* v;
            for (v = m_pVertexData; v != 0; v = v->m_pNext) {
                float d = v->m_fDist;
                if (d == 0.0f) {
                    front.PushBack(v->m_pos);
                    back.PushBack(v->m_pos);
                } else if (d > 0.0f) {
                    front.PushBack(v->m_pos);
                } else {
                    back.PushBack(v->m_pos);
                }
            }
            SplitTriangle* tri;
            for (tri = m_pTriangles; tri != 0; tri = tri->m_pNext) {
                int i = 0;

                workspace.scratch.edge=tri->m_pVerts;
                for (; i < 3; i++,workspace.scratch.edge++) {
                    SplitVertex* v0=*workspace.scratch.edge;
                    float d0 = v0->m_fDist;
                    if (d0 > 0.0f) {
                        SplitVertex* v1 = tri->m_pVerts[(9 >> (i << 1)) & 3];
                        float d1 = v1->m_fDist;
                        if (d1 * d0 < DAT_01012060) {
                            HullVec first=v0->m_pos;
                            HullVec second=v1->m_pos;
                            HullVec intersection;
                            float t=d0/(d0-d1);
                            intersection.setInterpolate4(first,second,t);
                            front.PushBack(intersection);
                            back.PushBack(intersection);
                        }
                    }
                }
            }
            if (ppFront != 0) {
                FUN_00d76ca0* o = new FUN_00d76ca0();
                *ppFront = o;
                o->m_pImpl->m_pConfiguration = m_pConfiguration;
            }
            if (ppBack != 0) {
                FUN_00d76ca0* o = new FUN_00d76ca0();
                *ppBack = o;
                o->m_pImpl->m_pConfiguration = m_pConfiguration;
            }
            bool bFront = ppFront != 0 && (*ppFront)->m_pImpl->hkgpConvexHullImpl_build(&front[0],front.GetSize(), 0, this) == m_iDimension;
            FUN_00d76ca0** pBack = ppBack;
            bool bBack = pBack != 0 && (*pBack)->m_pImpl->hkgpConvexHullImpl_build(&back[0],back.GetSize(), 0, this) == m_iDimension;
            FUN_00d76ca0** pF;
            if (!bFront && (pF = ppFront) != 0) {
                delete *pF;
                *pF = 0;
            }
            if (!bBack && pBack != 0) {
                delete *pBack;
                *pBack = 0;
            }
            back.Clear(); front.Clear(); return 3;
        }
        if(counts[1]>counts[0]) return 2;
        if(counts[0]) return 1;
        return 0;

    }
    case 2: {
        int iNeg = 0;
        int iPos = 0;
        SplitVertex* v;
        for (v = m_pVertexData; v != 0; v = v->m_pNext) {
            HullVec p = plane;
            float d = plane.dot4xyz1(v->m_pos);
            v->m_fDist = d;
            if (HullFabsf(d) <= fEps) {
                v->m_fDist = 0.0f;
            } else if (d < 0.0f) {
                iNeg++;
            } else {
                iPos++;
            }
        }
        if (iNeg == 0) {
            if (iPos != 0) {
                return 1;
            }
            return 0;
        }
        if (iPos == 0) {
            return 2;
        }
        VecArrayBase parts[2];
        parts[0].m_pData=0; parts[0].m_uiLogicalSize=0; parts[0].m_iCapAndFlags=0x80000000;
        parts[1].m_pData=0; parts[1].m_uiLogicalSize=0; parts[1].m_iCapAndFlags=0x80000000;
        SplitVertex* prev = m_pVertexData;
        if (prev != 0) {
            while (prev->m_pNext != 0) {
                prev = prev->m_pNext;
            }
        }
        SplitVertex* cur = m_pVertexData;
        while (cur != 0) {
const SplitRawVec* __restrict src=(const SplitRawVec*)&cur->m_pos;
unsigned int wordY=src->y;
double prod=cur->m_fDist*prev->m_fDist;
workspace.current.position.x=src->x;
workspace.current.position.y=wordY;
workspace.current.position.z=src->z;
workspace.current.position.w=src->w;
const HullVec& position=*(const HullVec*)&workspace.current.position;
            if (prod < DAT_01012060) {
                float t = prev->m_fDist / (prev->m_fDist - cur->m_fDist);
                HullVec intersection;
                intersection.setInterpolate4(prev->m_pos,position,t);
                parts[0].PushBack(intersection);
                parts[1].PushBack(intersection);
            }
            if (cur->m_fDist <= 0.0f) {
                parts[0].PushBack(position);
            }
            if (cur->m_fDist >= 0.0f) {
                parts[1].PushBack(position);
            }
            prev = cur;
            cur = cur->m_pNext;
        }
        FUN_00d76ca0** pp = ppBack;
        if (pp != 0) {
            *pp = new FUN_00d76ca0();
            (*pp)->m_pImpl->m_pConfiguration = m_pConfiguration;
            (*pp)->m_pImpl->m_vE0 = m_vE0;
            if ((*pp)->m_pImpl->hkgpConvexHullImpl_build(parts[0].m_pData,parts[0].m_uiLogicalSize, 1, this) != m_iDimension) {
                delete *pp;
                *pp = 0;
            }
        }
        pp = ppFront;
        if (pp != 0) {
            *pp = new FUN_00d76ca0();
            (*pp)->m_pImpl->m_pConfiguration = m_pConfiguration;
            (*pp)->m_pImpl->m_vE0 = m_vE0;
            if ((*pp)->m_pImpl->hkgpConvexHullImpl_build(parts[1].m_pData,parts[1].m_uiLogicalSize, 1, this) != m_iDimension) {
                delete *pp;
                *pp = 0;
            }
        }
        VecArrayBase* last=parts+2;
        int remaining=2;
        while(--remaining>=0) { --last; last->Clear(); }
        return 3;
    }
    default: {
        unsigned int buf[128];
        ErrorWork& stream=workspace.current.stream;
        stream.FUN_00cb1600(buf, 0x200);
        stream.ProcessAndReturnValue_00cc01c0("Current dimension not implemented for that operation");
        if (((ErrReporter*)DAT_01268360)->Message(3, 0x3a86e3ef, (const char*)buf, ".\\GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp", 0x854)) {
            __debugbreak();
        }
        stream.FUN_00cc00e0();
        return 4;
    }
    }
}

extern "C" void _ReadWriteBarrier();
using ::_mm_load_ps;
using ::_mm_add_ps;
using ::_mm_mul_ps;
using ::_mm_set_ps1;
using ::_mm_load_ss;

using ::_mm_setr_ps;
extern double DAT_0104e138;

struct VecNode {
    VecNode* m_next;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_20;
    int m_24;
    int m_28;
};

struct CentroidHull {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    VecNode* m_24;
    int m_28;
    int unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    union {
        LocalM128 m_80;
        struct {
            float unk80;
            float unk84;
            float unk88;
            float m_8c;
        };
    };
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    LocalM128 m_f0;
    int unk100, unk104, unk108, unk10C;
    LocalM128 m_110;

    void* ProcessEntries_00d7aa30();
};

// @fnv 0x00d7aa30
// src: GUESS 0x00d7aa30 (confidence: low)
void* CentroidHull::ProcessEntries_00d7aa30()
{
    LocalM128* out = &m_80;
    if ((double)((float*)out)[3] == DAT_0104e138) {
        m_80 = _mm_load_ps((const float*)&DAT_01267e30);
        _ReadWriteBarrier();
        VecNode* node = m_24;
        if (node != 0) {
            do {
                LocalM128 v = _mm_setr_ps((float)node->m_20, (float)node->m_24, (float)node->m_28, 0.0f);
                *out = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v, m_110), m_f0), *out);
                node = node->m_next;
            } while (node != 0);
        }
        int count = m_28;
        if (count != 0) {
            float r = 1.0f / (float)count;
            LocalM128 s = _mm_load_ss(&r);
            s = _mm_shuffle_ps(s, s, 0);
            LocalM128 o = _mm_load_ps((const float*)out);
            *out = _mm_mul_ps(s, o);
        }
        ((float*)out)[3] = 0.0f;
    }
    return out;
}

// Cached centroid of the transformed hull vertices.

using ::_mm_mul_ps;
using ::_mm_add_ss;
using ::_mm_sub_ss;
using ::_mm_shuffle_ps;
using ::_mm_set_ss;
using ::_mm_load_ss;
using ::_mm_load_ps1;
using ::_mm_store_ss;
using ::_mm_cvtss_f32;
extern "C" double __cdecl sqrt(double);
extern const char str_010d358c[];
extern const char str_010d3540[];
extern const LocalM128 DAT_010c7160;
struct MessageStream {
    int unk00, unk04, unk08;
    void FUN_00cb1600(void*, int);
    MessageStream* ProcessAndReturnValue_00cc01c0(const char*, int, const char*);
    MessageStream* EvaluateValue_00cc02d0();
    void ProcessAndReturnValue_00cc01c0();
    void FUN_00cc00e0();
};
struct BasisTransform {
    PlaneVector axes[3];
    PlaneVector origin;
};
struct PlaneShape {
    int unk00, unk04;
    ChildData* state;
    void GetMassProperties(BasisTransform*, void*);
    float ProcessAndReturnValue_00d769c0(const PlaneVector&);
    void ProcessEntries_00d76a20(PlaneVector* planes);
};
static __forceinline LocalM128 dot3(const LocalM128& a, const LocalM128& b) {
    LocalM128 p = _mm_mul_ps(a,b);
    LocalM128 y = _mm_shuffle_ps(p,p,0x55);
    LocalM128 z = _mm_shuffle_ps(p,p,0xaa);
    y = _mm_add_ss(y,p);
    return _mm_add_ss(z,y);
}
static __forceinline float scalarValue(LocalM128 v) {
    float value;
    _mm_store_ss(&value,v);
    return value;
}
template<class T> static __forceinline void swapValues(T& a,T& b) {
    T t=a; a=b; b=t;
}
static __forceinline LocalM128 MajorPlaneBroadcast(float value) {
    LocalM128 scalar=_mm_load_ss(&value);
    return _mm_shuffle_ps(scalar,scalar,0);
}
static __forceinline void CopyMajorPlane(PlaneVector& dst, const PlaneVector& src) { dst.value=src.value; }
static __forceinline void normalize(PlaneVector& out) {
    LocalM128 v=out.value;
    float len; _mm_store_ss(&len,dot3(v,v));
    if (len!=0.0f) {
        float inv=1.0f/(float)sqrt(len);
        LocalM128 scale=MajorPlaneBroadcast(inv);
        out.value=_mm_mul_ps(scale,v);
    }
}
// @fnv 0x00d76a20
// src: GUESS 0x00d76a20 (confidence: low)
void PlaneShape::ProcessEntries_00d76a20(PlaneVector* planes) {
    ChildData* data=state;
    if (!data->unk1b4) {
        char message[512];
        MessageStream stream;
        stream.FUN_00cb1600(message,512);
        stream.ProcessAndReturnValue_00cc01c0(str_010d358c,data->unk1b0,&DAT_0103d078)->EvaluateValue_00cc02d0()->ProcessAndReturnValue_00cc01c0();
        if (DAT_01268360->message(3,0x79f9d887,(char*)message,str_010d3540,334)) __debugbreak();
        stream.FUN_00cc00e0();
    }
    BasisTransform transform;
    {
        float other[3];
        GetMassProperties(&transform,other);
    }
    float scores[3];
    __declspec(align(8)) int indices[3];
    indices[0]=0; indices[1]=1; indices[2]=2;
    scores[0]=ProcessAndReturnValue_00d769c0(transform.axes[0]);
    scores[1]=ProcessAndReturnValue_00d769c0(transform.axes[1]);
    scores[2]=ProcessAndReturnValue_00d769c0(transform.axes[2]);
    for (int i=0;i<2;++i) {
        if (scores[i]<scores[i+1]) {
            swapValues(scores[i],scores[i+1]);
            swapValues(indices[i],indices[i+1]);
            i=-1;
        }
    }
    for (int k=0;k<3;++k) {
        CopyMajorPlane(planes[k],transform.axes[indices[k]]);
        normalize(planes[k]);
        float offset=scalarValue(_mm_sub_ss(DAT_010c7160,dot3(planes[k].value,transform.origin.value)));
        planes[k].value.m128_f32[3]=offset;
    }
}

extern LocalM128 DAT_01268370;
extern LocalM128 DAT_01268380;
extern LocalM128 DAT_01268390;
extern LocalM128 DAT_012683a0;
__forceinline LocalM128 sampleRead(const hkVector4& v) { LocalM128 value=v.m_vComponents; _ReadWriteBarrier();return value;}
struct SampleTransform {
    hkVector4 x,y,z,w;
    __forceinline SampleTransform(const hkVector4& a,const hkVector4& b,const hkVector4& c,const hkVector4& d) {
        x=a; y=b; z=c; w=d;
    }
};
extern const char str_010d36fc[];
struct SamplePoint: hkVector4 {
    void setTransformedPos_00c7f640(const SampleTransform&,const hkVector4&);
};
struct SampleBuilder {
    int unk00,unk04;
    ChildData* hull;
    void ForwardCall_00d76d80(hkVector4&,SampleTransform&);
    bool hkgpConvexHull_isPointInside(const hkVector4&,unsigned char,float);
};
struct SampleStream {
    int unk00,unk04,unk08;
    void FUN_00cb1600(char*,int);
    void ProcessAndReturnValue_00cc01c0(const char*);
    void FUN_00cc00e0();
};
struct SampleTrivialVector { LocalM128 m_vComponents; };
union SampleWorkspace { SampleTrivialVector extents; SampleStream stream; __forceinline SampleWorkspace(const hkVector4& v):extents((const SampleTrivialVector&)v) {} };
static __forceinline void appendSample(D76250VectorArrayLocalForm& out,const hkVector4& value) {
    D76250Allocator& alloc=fnvc_adapt::hkMemoryRouter_getInstance().heap();
    if(out.m_iElementCount==out.getCapacity()) ResizeAudioStream((void*)&alloc,&out,16);
    hkVector4* dest=out.m_data+out.m_iElementCount;
    for(int i=0;i<1;++i) dest[i]=value;
    ++out.m_iElementCount;
}
struct SampleBuilderRef { SampleBuilder* value; };
struct SampleRandomRef { RandomGenerator* value; };
// @fnv 0x00d76fa0
// src: XBOX_PDB 0x00d76fa0
void __cdecl hkgpConvexHull_createRandomSamples(SampleBuilderRef builder,SampleRandomRef random,int count,D76250VectorArrayLocalForm& out) {
    SampleWorkspace workspace(*(const hkVector4*)&DAT_01267e30);
    hkVector4 a=*(hkVector4*)&DAT_01268370;
    hkVector4 b=*(hkVector4*)&DAT_01268380;
    hkVector4 c=*(hkVector4*)&DAT_01268390;
    hkVector4 d=*(hkVector4*)&DAT_012683a0;
    SampleTransform transform(a,b,c,d);
    builder.value->ForwardCall_00d76d80((hkVector4&)workspace.extents,transform);
    for(int i=0;i<count;++i) {
        SamplePoint point;
        int trial=0;
        do {
            hkVector4 r;
            random.value->hkPseudoRandomGenerator_getRandomVector11((float*)&r);
            const hkVector4& e=(const hkVector4&)workspace.extents;
            point.m_vComponents=_mm_mul_ps(sampleRead(e),sampleRead(r));
            point.setTransformedPos_00c7f640(transform,point);
            if(builder.value->hkgpConvexHull_isPointInside(point,builder.value->hull->flag1b5,0.0f)) {
                goto accepted;
            }
        } while(++trial<1024);
        {
            char buffer[512];
            SampleStream& stream=workspace.stream;
            stream.FUN_00cb1600(buffer,512);
            stream.ProcessAndReturnValue_00cc01c0(str_010d36fc);
            DAT_01268360->message(1,0x1559e,buffer,str_010d3540,0xe22);
            stream.FUN_00cc00e0();
            return;
        }
accepted:
        appendSample(out,point);
    }
}

namespace tolerance { extern const float DAT_0104da4c=1.1920928955078125e-7f; }
using ::_mm_load_ss;
using ::_mm_shuffle_ps;
using ::_mm_sub_ss;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_add_ss;
using ::_mm_store_ss;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);



void __cdecl ResizeAudioStream(void*,void*,int);
namespace enumeration_rework {
typedef ::PlaneScalar PlaneScalar;
static __forceinline PlaneScalar operator-(const PlaneScalar& s) {
    return _mm_sub_ss(DAT_010c7160,s.quad());
}
class PlaneVector: public ::PlaneVector {
public:
    operator LocalM128() const {return value;}
    __forceinline void operator=(const PlaneVector& v) {value=v.value;}
    __forceinline void operator=(const LocalM128& v) {value=v;}
    __forceinline float& lane(int i) {return value.m128_f32[i];}
    __forceinline const float& lane(int i) const {return value.m128_f32[i];}
    __forceinline void set(float x,float y,float z,float w=0) {value=_mm_setr_ps(x,y,z,w);}
    __forceinline PlaneScalar scalar(int i) const {
        switch(i) {
        case 0:return value;
        case 1:return _mm_shuffle_ps(value,value,85);
        case 2:return _mm_shuffle_ps(value,value,170);
        default:return _mm_shuffle_ps(value,value,255);
        }
    }
    __forceinline void broadcast(const PlaneVector& v,int i) {
        if(i==0) value=_mm_shuffle_ps(v.value,v.value,0);
        else if(i==1) value=_mm_shuffle_ps(v.value,v.value,85);
        else if(i==2) value=_mm_shuffle_ps(v.value,v.value,170);
        else if(i==3) value=_mm_shuffle_ps(v.value,v.value,255);
    }
    __forceinline void mul(const PlaneVector& a,const PlaneVector& b) {value=_mm_mul_ps(a.value,b.value);}
    __forceinline void addMul(const PlaneVector& a,const PlaneVector& b) {
        LocalM128 product=_mm_mul_ps(a.value,b.value);value=_mm_add_ps(value,product);
    }
    __forceinline PlaneScalar distance(const PlaneVector& v) const {
        LocalM128 planeq=value; _ReadWriteBarrier();
        LocalM128 product=_mm_mul_ps(v,planeq);
        LocalM128 xy=_mm_add_ss(_mm_shuffle_ps(product,product,85),product);
        LocalM128 zw=_mm_add_ss(_mm_shuffle_ps(product,product,170),_mm_shuffle_ps(planeq,planeq,255));
        return _mm_add_ps(xy,zw);
    }
};
struct PlaneMatrix {
    PlaneVector c0,c1,c2;
    __forceinline PlaneMatrix() {}
    __forceinline void rows(const PlaneVector& a,const PlaneVector& b,const PlaneVector& c) {
        c0.set(a.lane(0),b.lane(0),c.lane(0));
        c1.set(a.lane(1),b.lane(1),c.lane(1));
        c2.set(a.lane(2),b.lane(2),c.lane(2));
    }
    int invert_00cd4f10(float);
    __forceinline void transform(const PlaneVector& v,PlaneVector& out) const {
        PlaneVector x,y,z;
        x.broadcast(v,0);y.broadcast(v,1);z.broadcast(v,2);
        PlaneVector sum;
        sum.mul(x,c0);sum.addMul(y,c1);sum.addMul(z,c2);
        out=sum;
    }
};
struct EnumerationTimer {
    const char* tag;
    unsigned int clock0,clock1;
    __forceinline void sample() {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        clock0=ticks;
    }
};
struct EnumerationStream {
    char *start,*end,*capacity,*limit;
};
static __forceinline void markEnumeration(const char* tag) {
    EnumerationStream* s=(EnumerationStream*)TlsGetValue(DAT_0126835c);
    if(s->end<s->limit) {
        EnumerationTimer* c=(EnumerationTimer*)s->end;
        c->tag=tag;
        c->sample();
        s->end=(char*)(c+1);
    }
}
struct PlanePointArray: D76250VectorArrayLocalForm {
    __forceinline PlanePointArray() {m_data=0;m_iElementCount=0;m_iCapacityState=0x80000000;}
    __forceinline ~PlanePointArray() {
        S_00d7a010_Alloc& heap=S_00d7a010_Router::hkMemoryRouter_getInstance().heap();
        m_iElementCount=0;
        if((m_iCapacityState&0x80000000)==0) heap.ReturnMemory(m_data,getCapacity()*sizeof(PlaneVector));
    }
    __forceinline void reserve(int n) {
        D76250Allocator& heap=fnvc_adapt::hkMemoryRouter_getInstance().heap();
        D76250VectorArrayLocalForm::reserve(heap,n);
    }
    __forceinline void append(const PlaneVector& v) {
        D76250Allocator& heap=fnvc_adapt::hkMemoryRouter_getInstance().heap();
        if(m_iElementCount==getCapacity()) ResizeAudioStream((void*)&heap,this,sizeof(PlaneVector));
        PlaneVector* dst=(PlaneVector*)m_data+m_iElementCount;
        for(int n=0;n<1;++n) dst[n]=v;
        ++m_iElementCount;
    }
};
struct PlaneHull: ::PlaneHull {
    int hkgpConvexHull_build(const PlaneVector*,int,int);
    int ProcessEntries_00d774a0(const PlaneVector*,int,int);
};
// @fnv 0x00d774a0
// src: GUESS 0x00d774a0 (confidence: low)
int PlaneHull::ProcessEntries_00d774a0(const PlaneVector* planes,int count,int config)
{
    PlanePointArray points;
    markEnumeration("TtVertexEnumeration");
    PlaneMatrix matrix;
    PlaneVector rhs;
    points.reserve(3*count);
    for(int a=0;a<count;++a) {
        rhs.lane(0)=-planes[a].scalar(3);
        for(int b=a+1;b<count;++b) {
            rhs.lane(1)=-planes[b].scalar(3);
            for(int c=b+1;c<count;++c) {
                matrix.rows(planes[a],planes[b],planes[c]);
                rhs.lane(2)=-planes[c].scalar(3);
                if(matrix.invert_00cd4f10(1.1920928955078125e-7f)==0) {
                    bool accepted=true;
                    PlaneVector vertex;
                    matrix.transform(rhs,vertex);
                    for(int d=0;d<count;++d) {
                        if(d==a||d==b||d==c) continue;
                        float distance=planes[d].distance(vertex);
                        if(distance>1.1920928955078125e-7f) {accepted=false;break;}
                    }
                    if(accepted) points.append(vertex);
                }
            }
        }
    }
    markEnumeration("Et");
    if(points.m_iElementCount>3) return hkgpConvexHull_build((PlaneVector*)points.m_data,points.m_iElementCount,config);
    return -1;
}

}

extern "C" {
using ::_mm_load_ps;
void _ReadWriteBarrier();
using ::_mm_add_ss;
using ::_mm_add_ps;
using ::_mm_sub_ss;
using ::_mm_sub_ps;
using ::_mm_mul_ss;
using ::_mm_mul_ps;
using ::_mm_sqrt_ss;
using ::_mm_rsqrt_ss;
using ::_mm_cmpeq_ss;
using ::_mm_andnot_ps;
using ::_mm_xor_ps;
using ::_mm_shuffle_ps;
using ::_mm_set_ss;
using ::_mm_load_ss;

using ::_mm_store_ss;

double sqrt(double);
}



extern float DAT_01012054;

inline hkMemoryRouter* Holder() { return (hkMemoryRouter*)hkMemoryRouter_getInstance(); }

void __cdecl hkArrayUtil__reduce(HullAllocator* alloc, void* arr, int elemSize, int unused, int n);
struct IndexVertex {
    IndexVertex* m_pNext;
    int unk04;
    int unk08;
    int unk0c;
    LocalM128 m_pos;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int unk2c;
    int unk30;
    int m_uiEdgeIndex;
};
struct HullFace {
    HullFace* m_pNext;
    int unk04;
    IndexVertex* m_vert[3];
    unsigned int m_kEdge[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int m_planeIndex;
    int unk3c;
    int unk40;
    int m_uiEdgeIndex;
};
struct IndexEdge;
template<class E> struct IndexEdgeBase {
    HullFace* m_face;
    unsigned int m_ucOperationType;
    IndexEdgeBase() {}
    IndexEdgeBase(HullFace* f,int t):m_face(f),m_ucOperationType(t) {}
    IndexEdgeBase(unsigned int packed) { m_ucOperationType=packed&3; m_face=(HullFace*)(packed&~3u); }
    HullFace* triangle() const { return m_face; }
    E next() const { return E(m_face,(9>>(m_ucOperationType*2))&3); }
    E prev() const { return E(m_face,(18>>(m_ucOperationType*2))&3); }
    E link() const { return E(m_face->m_kEdge[m_ucOperationType]); }
};
struct IndexEdge:IndexEdgeBase<IndexEdge> {
    IndexEdge() {}
    IndexEdge(HullFace*f,int i):IndexEdgeBase<IndexEdge>(f,i) {}
    IndexEdge(unsigned int packed):IndexEdgeBase<IndexEdge>(packed) {}
    IndexEdge(const IndexEdge& e) { m_face=e.m_face; m_ucOperationType=e.m_ucOperationType; }
};
struct FaceArea {
    HullFace* m_face;
    float m_area;
};
struct FaceLess { unsigned char context; FaceLess() : context(0) {} };
void __cdecl hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedTriangle_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedTriangle(FaceArea* arr, int lo, int hi, FaceLess cmp);
struct HullBool {
    unsigned char m_cBooleanValue;
};
struct HullVec4 {
    LocalM128 m_vComponents;
    HullBool* FUN_00c7f520(HullBool* out, float eps);
};
struct __declspec(align(16)) HullFloat4 {
    float x;
    float y;
    float z;
    float w;
};
union HullPlane {
    LocalM128 m_vComponents;
    HullFloat4 m_fields;
};
template <class T> struct HullArrayBase {
    T* m_data;
    int m_iElementCount;
    int m_capAndFlags;
    T& operator[](int i) { return m_data[i]; }
};
template<class T>struct HullArray:HullArrayBase<T> {
    HullArray() {m_data=0;m_iElementCount=0;m_capAndFlags=0x80000000;}
};
struct FacePtrMap {
    void* m_kPrimitiveElement;
    int m_num;
    int m_iPairCount;
    FacePtrMap() : m_kPrimitiveElement(0), m_num(0), m_iPairCount(-1) { Reserve(0); }
    void EnsureCapacity(HullAllocator* alloc, int n);
    void Reserve(int n)
    {
        hkMemoryRouter* h = Holder();
        HullAllocator* a = ((HullAllocator*)h->m_heap);
        EnsureCapacity(a, n);
    }
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(HullAllocator* alloc, HullFace* key, int val);
    void Insert(HullFace* key, int val)
    {
        hkMemoryRouter* h = Holder();
        HullAllocator* a = ((HullAllocator*)h->m_heap);
        hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(a, key, val);
    }
    int LookupHashEntry(HullFace* key, int def);
    void ProcessArgument(HullAllocator* alloc);
    void Object_DoNothing();
};
inline void PushEdge(HullArray<IndexEdge>& a, const IndexEdge& e)
{
    hkMemoryRouter* h = Holder();
    if (a.m_iElementCount == (a.m_capAndFlags & 0x3fffffff)) {
        ResizeAudioStream((void*)((HullAllocator*)h->m_temp), (void*)&a, 8);
    }
    new (&a.m_data[a.m_iElementCount]) IndexEdge(e);
    a.m_iElementCount++;
}
inline void PushPlane(HullArray<LocalM128>* a, const LocalM128& v)
{
    hkMemoryRouter* h = Holder();
    if (a->m_iElementCount == (a->m_capAndFlags & 0x3fffffff)) {
        ResizeAudioStream((void*)((HullAllocator*)h->m_heap), (void*)a, 0x10);
    }
    LocalM128* dst = a->m_data + a->m_iElementCount;
    for (int i = 0; i < 1; ++i) dst[i] = v;
    a->m_iElementCount++;
}
inline float Real(LocalM128 a) { float f; _mm_store_ss(&f,a); return f; }
inline LocalM128 Splat(float a) { return _mm_shuffle_ps(_mm_load_ss(&a),_mm_load_ss(&a),0); }

inline LocalM128 Dot3(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
}
inline LocalM128 Cross(LocalM128 a, LocalM128 b)
{
    LocalM128 c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(c0, c1);
}
inline LocalM128 PlanarCross(const LocalM128& a, LocalM128 b)
{
    LocalM128 c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(c0, c1);
}
class GeoScalar {
    LocalM128 value;
public:
    GeoScalar() {}
    GeoScalar(const LocalM128& x):value(x) {}
    GeoScalar(float x) { value=_mm_load_ss(&x); }
    operator float() const { float f; _mm_store_ss(&f,value); return f; }
    const LocalM128& quad() const { return value; }
};
inline GeoScalar operator+(const GeoScalar& a,const GeoScalar& b) { return _mm_add_ss(a.quad(),b.quad()); }
class GeoVector {
    LocalM128 value;
public:
    GeoScalar dot(const GeoVector& b) const {
        LocalM128 prod=_mm_mul_ps(_mm_load_ps((const float*)&value),b.value);
        LocalM128 sum=_mm_add_ss(_mm_shuffle_ps(prod,prod,85),prod);
        return _mm_add_ss(_mm_shuffle_ps(prod,prod,170),sum);
    }
    GeoScalar at(int i) const {
        switch(i) {
        case 0:return value;
        case 1:return _mm_shuffle_ps(value,value,85);
        case 2:return _mm_shuffle_ps(value,value,170);
        default:return _mm_shuffle_ps(value,value,255);
        }
    }
};
struct HullBuilder {
    int unk00;
    float m_fScalar;
    int unk08;
    unsigned char unk0c;
    unsigned char m_bFixup;
    unsigned char unk0e;
    unsigned char unk0f;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    IndexVertex* m_kVertices;
    int m_iStridedVertexCount;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    HullFace* m_faces;
    int m_numFaces;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    HullArray<LocalM128> m_kPlaneArray;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    int fielda0;
    int fielda4;
    int fielda8;
    int fieldac;
    int fieldb0;
    int fieldb4;
    int fieldb8;
    int fieldbc;
    int fieldc0;
    int fieldc4;
    int fieldc8;
    int fieldcc;
    int fieldd0;
    int fieldd4;
    int fieldd8;
    int fielddc;
    LocalM128 m_e0;
    LocalM128 m_f0;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    LocalM128 m_110;
    int field120;
    int field124;
    int field128;
    int field12c;
    int field130;
    int field134;
    int field138;
    int field13c;
    int field140;
    int field144;
    int field148;
    int field14c;
    int field150;
    int field154;
    int field158;
    int field15c;
    int field160;
    int field164;
    int field168;
    int field16c;
    int field170;
    int field174;
    int field178;
    int field17c;
    int field180;
    int field184;
    int field188;
    int field18c;
    int field190;
    int field194;
    int field198;
    int field19c;
    int field1a0;
    int field1a4;
    int m_dimension;
    int unk1ac;
    int unk1b0;
    unsigned char unk1b4;
    unsigned char m_bPlanesBuilt;
    HullFloat4* ProcessEntries_00d7aa30();
    void ProcessEntries_00d7d2a0();
};
inline LocalM128 Xform(const HullBuilder* h, const IndexVertex* v)
{
    return _mm_add_ps(_mm_mul_ps(_mm_setr_ps((float)v->m_uiX, (float)v->m_uiY, (float)v->m_uiZ, 0.0f), h->m_110), h->m_f0);
}
// @fnv 0x00d7d2a0
// src: GUESS 0x00d7d2a0 (confidence: low)
void HullBuilder::ProcessEntries_00d7d2a0()
{
    if (m_bPlanesBuilt != 0) {
        return;
    }
    HullPlane p;
    HullArray<FaceArea> areas;
    FacePtrMap map;
    HullArray<LocalM128> facePlanes;
    int numFaces = m_numFaces;
    if (numFaces != 0) {
        hkMemoryRouter* h = Holder();
        if ((areas.m_capAndFlags & 0x3fffffff) < numFaces) {
            hkArrayUtil__reserve(((HullAllocator*)h->m_temp), &areas, numFaces, 8);
        }
        for (HullFace* f = m_faces; f != 0; f = f->m_pNext) {
            int k = areas.m_iElementCount++;
            FaceArea* e = &areas.m_data[k];
            e->m_face = f;
            IndexVertex* v2 = f->m_vert[2];
            IndexVertex* v1 = f->m_vert[1];
            IndexVertex* v0 = f->m_vert[0];
            LocalM128 a = Xform(this, v0);
            LocalM128 b = _mm_sub_ps(Xform(this, v1), a);
            LocalM128 c = _mm_sub_ps(Xform(this, v2), a);
            e->m_area = Real(_mm_sqrt_ss(Dot3(Cross(b, c), Cross(b, c))));
        }
        FaceLess cmp;
        if (areas.m_iElementCount > 1) {
            hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedTriangle_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedTriangle(areas.m_data, 0, areas.m_iElementCount - 1, cmp);
        }
        int idx = 0;
        map.Reserve(m_numFaces);
        int n = m_numFaces;
        hkMemoryRouter* hh = Holder();
        HullAllocator* heap = ((HullAllocator*)hh->m_temp);
        int cap = facePlanes.m_capAndFlags & 0x3fffffff;
        if (cap < n) {
            int newCap = cap + cap;
            if (n >= newCap) {
                newCap = n;
            }
            hkArrayUtil__reserve(heap, &facePlanes, newCap, 0x10);
        }
        facePlanes.m_iElementCount = n;
        for (HullFace* f = m_faces; f != 0; f = f->m_pNext) {
            map.Insert(f, idx);
            IndexVertex* v2 = f->m_vert[2];
            IndexVertex* v1 = f->m_vert[1];
            IndexVertex* v0 = f->m_vert[0];
            LocalM128 a = Xform(this, v0);
            LocalM128 b = _mm_sub_ps(Xform(this, v1), a);
            LocalM128 c = _mm_sub_ps(Xform(this, v2), a);
            p.m_vComponents = Cross(b, c);
            float lenSq;
            _mm_store_ss(&lenSq, Dot3(p.m_vComponents, p.m_vComponents));
            if (lenSq != 0.0f) {
                float inv = 1.0f / (float)sqrt(lenSq);
                p.m_vComponents = _mm_mul_ps(Splat(inv), p.m_vComponents);
            }
            p.m_fields.w = Real(_mm_sub_ss(DAT_010c7160, Dot3(p.m_vComponents, a)));
            facePlanes[idx] = p.m_vComponents;
            f->m_uiEdgeIndex = idx;
            f->m_planeIndex = -1;
            idx++;
        }
    }
    int vi = 0;
    for (IndexVertex* v = m_kVertices; v != 0; v = v->m_pNext) {
        v->m_uiEdgeIndex = vi;
        vi++;
    }
    m_kPlaneArray.m_iElementCount = 0;
    if (m_dimension == 3) {
        HullArray<IndexEdge> stack;
        for (int i = 0; i < areas.m_iElementCount; i++) {
            HullFace* f = areas.m_data[i].m_face;
            if (f->m_planeIndex != -1) {
                continue;
            }
            int pi = map.LookupHashEntry(f, -1);
            LocalM128* ref = &facePlanes.m_data[pi];
            f->m_planeIndex = m_kPlaneArray.m_iElementCount;
            PushPlane(&m_kPlaneArray, *ref);
            stack.m_iElementCount = 0;
            PushEdge(stack, IndexEdge(f,0).link());
            PushEdge(stack, IndexEdge(f,1).link());
            PushEdge(stack, IndexEdge(f,2).link());
            while (stack.m_iElementCount != 0) {
                IndexEdge edge = stack.m_data[stack.m_iElementCount-1];
                HullFace* nf=edge.triangle();
                stack.m_iElementCount--;
                if (nf->m_planeIndex != -1) {
                    continue;
                }
                int ni = map.LookupHashEntry(nf, -1);
                HullVec4* other = (HullVec4*)&facePlanes.m_data[ni];
                HullBool res;
                if (other->FUN_00c7f520(&res, 1e-4f)->m_cBooleanValue != 0) {
                    float d;
                    _mm_store_ss(&d, Dot3(_mm_load_ps((const float*)&other->m_vComponents),*ref));
                    if (!(d >= m_fScalar)) {
                        continue;
                    }
                }
                nf->m_planeIndex = f->m_planeIndex;
                PushEdge(stack, edge.next().link());
                PushEdge(stack, edge.prev().link());
            }
        }
        hkMemoryRouter* hh = Holder();
        HullAllocator* heap = ((HullAllocator*)hh->m_temp);
        int scap = stack.m_capAndFlags;
        stack.m_iElementCount = 0;
        if ((scap & 0x80000000) == 0) {
            heap->BufFree(stack.m_data, (scap & 0x3fffffff) * 8);
        }
    } else if (m_dimension == 2) {
        HullFloat4 centroid = *ProcessEntries_00d7aa30();
        IndexVertex* prev = m_kVertices;
        if (prev != 0) {
            while (prev->m_pNext != 0) {
                prev = prev->m_pNext;
            }
        }
        for (IndexVertex* v = m_kVertices; v != 0; v = v->m_pNext) {
            LocalM128 va = Xform(this, prev);
            LocalM128 edge = _mm_sub_ps(Xform(this, v), va);
            HullArray<LocalM128>* pl = &m_kPlaneArray;
            hkMemoryRouter* h = Holder();
            if (pl->m_iElementCount == (pl->m_capAndFlags & 0x3fffffff)) {
                ResizeAudioStream((void*)((HullAllocator*)h->m_heap), (void*)pl, 0x10);
            }
            HullPlane* p = (HullPlane*)&pl->m_data[pl->m_iElementCount++];
            HullPlane n;
            n.m_vComponents = PlanarCross(m_e0, edge);
            p->m_vComponents = n.m_vComponents;
            float lenSq;
            _mm_store_ss(&lenSq, Dot3(n.m_vComponents, n.m_vComponents));
            if (lenSq != 0.0f) {
                float inv = 1.0f / (float)sqrt(lenSq);
                p->m_vComponents = _mm_mul_ps(Splat(inv), n.m_vComponents);
            }
            p->m_fields.w = Real(_mm_sub_ss(DAT_010c7160, Dot3(_mm_load_ps((float*)&va), p->m_vComponents)));
            LocalM128 q = p->m_vComponents;
            float d;
            d = ((const GeoVector*)p)->dot(*(const GeoVector*)&centroid) + ((const GeoVector*)&q)->at(3);
            if (d > 0.0f) {
                p->m_vComponents = _mm_xor_ps(q, *(const LocalM128*)&DAT_010c44d0);
            }
            prev = v;
        }
    } else if (m_dimension == 1) {
        IndexVertex* first = m_kVertices;
        LocalM128 va = Xform(this, first);
        IndexVertex* last = m_kVertices;
        if (last != 0) {
            while (last->m_pNext != 0) {
                last = last->m_pNext;
            }
        }
        LocalM128 b = Xform(this, last);
        LocalM128 d = _mm_sub_ps(b, va);
        LocalM128 lenSq = Dot3(d, d);
        LocalM128 eq = _mm_cmpeq_ss(lenSq, _mm_set_ss(0.0f));
        LocalM128 r = _mm_rsqrt_ss(lenSq);
        LocalM128 t = _mm_mul_ss(_mm_mul_ss(lenSq, r), r);
        LocalM128 inv = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), r), _mm_sub_ss(_mm_set_ss(3.0f), t));
        inv = _mm_andnot_ps(eq, inv);
        p.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), d);
        p.m_fields.w = Real(_mm_sub_ss(DAT_010c7160, Dot3(b, p.m_vComponents)));
        HullArray<LocalM128>* pl = &m_kPlaneArray;
        PushPlane(pl, p.m_vComponents);
        p.m_vComponents = _mm_mul_ps(Splat(DAT_01012054), p.m_vComponents);
        p.m_fields.w = Real(_mm_sub_ss(DAT_010c7160, Dot3(va, p.m_vComponents)));
        PushPlane(pl, p.m_vComponents);
    }
    if (m_bFixup != 0) {
        HullArray<LocalM128>& planes=m_kPlaneArray;
        for (IndexVertex* v = m_kVertices; v != 0; v = v->m_pNext) {
            for (int i = 0; i < planes.m_iElementCount; i++) {
                float d = ((const GeoVector*)&planes.m_data[i])->dot(*(const GeoVector*)&v->m_pos) + ((const GeoVector*)&planes.m_data[i])->at(3);
                HullPlane* p=(HullPlane*)&planes.m_data[i];
                if(d>0.0f) p->m_fields.w=p->m_fields.w-d;
            }
        }
    }
    if (m_kPlaneArray.m_iElementCount != 0) {
        HullArray<LocalM128>* pl = &m_kPlaneArray;
        hkMemoryRouter* h = Holder();
        if (pl->m_iElementCount < (pl->m_capAndFlags & 0x3fffffff)) {
            hkArrayUtil__reduce(((HullAllocator*)h->m_heap), pl, 0x10, 0, pl->m_iElementCount);
        }
    }
    m_bPlanesBuilt = 1;
    {
        hkMemoryRouter* hh = Holder();
        HullAllocator* heap = ((HullAllocator*)hh->m_temp);
        int cap = facePlanes.m_capAndFlags;
        facePlanes.m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            heap->BufFree(facePlanes.m_data, (cap & 0x3fffffff) * 16);
        }
        facePlanes.m_data = 0;
        facePlanes.m_capAndFlags = 0x80000000;
    }
    map.ProcessArgument(((HullAllocator*)Holder()->m_heap));
    map.Object_DoNothing();
    {
        hkMemoryRouter* hh = Holder();
        HullAllocator* heap = ((HullAllocator*)hh->m_temp);
        int cap = areas.m_capAndFlags;
        areas.m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            heap->BufFree(areas.m_data, (cap & 0x3fffffff) * 8);
        }
    }
}

using ::_mm_load_ss;
using ::_mm_set_ss;
using ::_mm_store_ss;
using ::_mm_store_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_add_ss;
using ::_mm_shuffle_ps;
using ::_mm_unpacklo_ps;
using ::_mm_move_ss;

extern float DAT_01011d78;


class MatchScalar {
    hkVec4 data;
public:
    MatchScalar(float x) { _mm_store_ps(&data.x,_mm_load_ss(&x)); }
    MatchScalar(const LocalM128& v) { _mm_store_ps(&data.x,v); }
    operator float() const { float x; _mm_store_ss(&x,*(const LocalM128*)&data); return x; }
};
class MatchVector {
public:
    LocalM128 data;
    void operator=(const MatchVector& v) { data=v.data; }
    void set(float x,float y,float z,float w) { data=_mm_setr_ps(x,y,z,w); }
    void mul4(const MatchVector& v) { data=_mm_mul_ps(data,v.data); }
    void add4(const MatchVector& v) { data=_mm_add_ps(data,v.data); }
    MatchScalar distanceToSquared3(const MatchVector& v) const {
        LocalM128 delta=_mm_sub_ps(data,v.data);
        LocalM128 square=_mm_mul_ps(delta,delta);
        return _mm_add_ss(_mm_shuffle_ps(square,square,0xaa),_mm_add_ss(_mm_shuffle_ps(square,square,0x55),square));
    }
};


struct ProbeNode {
    ProbeNode* next;
    int unk04, unk08, unk0c;
    MatchVector source;
    int x,y,z;
};
struct ProbeHull {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    ProbeNode* vertices;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec;
    MatchVector offset,unk100,scale;
};
struct ProbeSource {
    static const MatchVector& position(ProbeHull*, ProbeNode* n) { return n->source; }
};
struct ProbeTransform {
    static MatchVector position(ProbeHull* h, ProbeNode* n) {
        MatchVector v;
        v.set((float)n->x,(float)n->y,(float)n->z,0.0f);
        v.mul4(h->scale);
        v.add4(h->offset);
        return v;
    }
};
template<class P> static __forceinline void probeScan(ProbeHull* h,const MatchVector& input,MatchVector& output) {
    MatchScalar best(0.0f);
    output=input;
    for(ProbeNode* n=h->vertices;n;n=n->next) {
        MatchScalar distance=input.distanceToSquared3(P::position(h,n));
        if(distance>best) {
            best=distance;
            output=P::position(h,n);
        }
    }
}
struct ProbeObj {
    int unk00,unk04;
    ProbeHull* hull;
    void Helper_00d75e30(int mode,const MatchVector& input,MatchVector& output);
};
// @fnv 0x00d75e30
// src: GUESS 0x00d75e30 (confidence: low)
void ProbeObj::Helper_00d75e30(int mode,const MatchVector& input,MatchVector& output) {
    if(mode==0) probeScan<ProbeSource>(hull,input,output);
    else probeScan<ProbeTransform>(hull,input,output);
}

extern const char str_010d3574[];
extern float DAT_0104da4c;
extern const LocalM128 DAT_010ec7f0;
extern "C" {
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_add_ss;
using ::_mm_shuffle_ps;
using ::_mm_load_ss;
using ::_mm_store_ss;
double fabs(double);
}
struct ClipStream {
    int unk00,unk04,unk08;
    void FUN_00cb1600(char*,int);
    ClipStream* ProcessAndReturnValue_00cc01c0(const char*,int,char*);
    ClipStream* EvaluateValue_00cc02d0();
    void ProcessAndReturnValue_00cc01c0();
    void FUN_00cc00e0();
};
class ClipSimdReal {
public:
    ClipSimdReal(const LocalM128& x):m_vValue(x) {}
    ClipSimdReal(float x) { m_vValue=_mm_load_ss(&x); }
    operator float() const { float s; _mm_store_ss(&s,m_vValue); return s; }
    __forceinline float get(float& s) const { _mm_store_ss(&s,m_vValue); return s; }
    __forceinline void store(float& s) const { _mm_store_ss(&s,m_vValue); }
    __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(m_vValue,m_vValue,0); }
private:
    LocalM128 m_vValue;
};
class __declspec(align(16)) ClipVector {
public:
    __forceinline ClipSimdReal dot4xyz1(const ClipVector& a) const {
        LocalM128 x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
        LocalM128 xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,0x55),x2);
        LocalM128 zwSum=_mm_add_ss(_mm_shuffle_ps(x2,x2,0xaa),_mm_shuffle_ps(m_vComponents,m_vComponents,0xff));
        return _mm_add_ps(xySum,zwSum);
    }
    __forceinline void setInterpolate4(const ClipVector& v0,const ClipVector& v1,const ClipSimdReal& _t) {
        LocalM128 t=_t.broadcast();
        LocalM128 s=_mm_sub_ps(DAT_010ec7f0,t);
        m_vComponents=_mm_add_ps(_mm_mul_ps(s,v0.m_vComponents),_mm_mul_ps(t,v1.m_vComponents));
    }
    __forceinline void operator=(const ClipVector& v) { m_vComponents=v.m_vComponents; }
    LocalM128 m_vComponents;
};
static inline float ClipFabs(float r) { return (float)fabs(r); }
struct ClipHull {
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
    ClipVector* planes;
    int numPlanes;
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
    int index;
    unsigned char unk1b4;
    bool indexed;
    __forceinline void mustHaveIndex() const;
    bool ProcessEntries_00d7a5a0(const ClipVector& a,const ClipVector& b,float& t0,float& t1,float planeThickness) const;
};
__forceinline void ClipHull::mustHaveIndex() const
{
    if(!indexed) {
        char buffer[512];
        ClipStream stream;
        stream.FUN_00cb1600(buffer,512);
        stream.ProcessAndReturnValue_00cc01c0(str_010d3574,index,&DAT_0103d078)->EvaluateValue_00cc02d0()->ProcessAndReturnValue_00cc01c0();
        if(DAT_01268360->message(3,0x79f9d886,buffer,str_010d3540,0x148)) __debugbreak();
        stream.FUN_00cc00e0();
    }
}
// @fnv 0x00d7a5a0
// src: GUESS 0x00d7a5a0 (confidence: low)
bool ClipHull::ProcessEntries_00d7a5a0(const ClipVector& a,const ClipVector& b,float& t0,float& t1,float planeThickness) const
{
    mustHaveIndex();
    ClipVector pa=a;
    ClipVector pb=b;
    t0=0.0f;
    t1=1.0f;
    struct __declspec(align(16)) ClipWalk { int offset,index; float first,second; };
    ClipWalk walk; walk.index=0;
    if(walk.index<numPlanes) { walk.offset=0; do {
        const ClipVector& plane=*reinterpret_cast<const ClipVector*>(reinterpret_cast<const unsigned char*>(planes)+walk.offset);
        float d[2]; ClipSimdReal first=plane.dot4xyz1(pa); d[0]=first.get(walk.first); ClipSimdReal second=plane.dot4xyz1(pb); d[1]=second.get(walk.second);
        int mask=0;
        for(int j=0;j<2;++j) {
            if(d[j]>planeThickness) mask+=1<<j;
            if(ClipFabs(d[j])<0.00000011920928955078125f) d[j]=0.0f;
        }
        if(mask==3) return false;
        if(d[0]*d[1]<0.0f) {
            const float t=d[0]/(d[0]-d[1]);
            if(d[0]<0.0f) t0=t; else t1=t;
            pa.setInterpolate4(a,b,t0);
            pb.setInterpolate4(a,b,t1);
        }
    ++walk.index; walk.offset+=sizeof(ClipVector); } while(walk.index<numPlanes); }
    return true;
}

using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_add_ss;
using ::_mm_shuffle_ps;
using ::_mm_store_ss;
using ::_mm_store_ps;
using ::_mm_load_ps;
using ::_mm_load_ps1;
using ::_mm_load_ss;

extern const char str_010d3574[];
extern float DAT_01011d78;


class BevelScalar {
    LocalM128 q;
public:
    BevelScalar() {}
    BevelScalar(const LocalM128& v): q(v) {}
    BevelScalar(float v) { q=_mm_load_ss(&v); }
    operator float() const { float v; _mm_store_ss(&v,q); return v; }
    __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(q,q,0); }
};
class BevelVector {
public:
    LocalM128 q;
    __forceinline void operator=(const BevelVector& v) { q=v.q; }
    __forceinline void operator=(const LocalM128& v) { q=v; }
    __forceinline void set(float x,float y,float z,float w=0) { q=_mm_setr_ps(x,y,z,w); }
    __forceinline void add(const BevelVector& v) { q=_mm_add_ps(q,v.q); }
    __forceinline void sum(const BevelVector& a,const BevelVector& b) { q=_mm_add_ps(a.q,b.q); }
    __forceinline void mul(const BevelVector& v) { q=_mm_mul_ps(q,v.q); }
    __forceinline void mul(const BevelScalar& v) { q=_mm_mul_ps(v.broadcast(),q); }
    inline BevelScalar dot(const BevelVector& v) const {
        LocalM128 prod=_mm_mul_ps(q,v.q);
        LocalM128 xy=_mm_add_ss(_mm_shuffle_ps(prod,prod,85),prod);
        return _mm_add_ss(_mm_shuffle_ps(prod,prod,170),xy);
    }
    inline BevelScalar squared() const { return dot(*this); }
    __forceinline int normalize() {
        const float sq=squared();
        if(sq!=0.0f) { mul(1.0f/sqrtf(sq)); return 0; }
        return 1;
    }
    inline float& operator()(int i) { return reinterpret_cast<float*>(&q)[i]; }
    inline const float& operator()(int i) const { return reinterpret_cast<const float*>(&q)[i]; }
    inline BevelScalar at(int i) const {
        switch(i) { case 0:return q; case 1:return _mm_shuffle_ps(q,q,85); case 2:return _mm_shuffle_ps(q,q,170); default:return _mm_shuffle_ps(q,q,255); }
    }
};
template<class T> inline T bevelMaximum(T a,T b) { return a>b?a:b; }
struct BevelVertex {
    BevelVertex* m_next;
    BevelVertex* m_pSecondNode;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_pos[3];
    static __forceinline bool ordered(const BevelVertex* a,const BevelVertex* b) {
        for(int k=0;k<3;k++) {
            if(a->m_pos[k]<b->m_pos[k]) return true;
            if(a->m_pos[k]>b->m_pos[k]) return false;
        }
        return true;
    }
};

struct BevelTri {
    BevelTri* m_next;
    BevelTri* m_pSecondNode;
    BevelVertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int m_kTriangleNormal;
    __forceinline BevelVertex*& vertex(int i) { return m_kVertices[i]; }
    __forceinline unsigned int& link(int i) { return m_ppLinks[i]; }
};


template<class E> struct BevelEdgeBase {
protected:
    BevelTri* face;
    unsigned int corner;
    static __forceinline unsigned advance(unsigned i) { return (9>>(i<<1))&3; }
public:
    __forceinline BevelEdgeBase() {}
    __forceinline BevelEdgeBase(BevelTri* f,unsigned i):face(f),corner(i) {}
    __forceinline BevelEdgeBase(const unsigned int& id) {
        unsigned int value=id;
        corner=value&3; value&=~3;
        face=*(BevelTri**)&value;
    }
    __forceinline E link() const { return E(face->link(corner)); }
    __forceinline BevelTri* triangle() const { return face; }
    __forceinline BevelVertex*& start() const { return face->vertex(corner); }
    __forceinline BevelVertex*& end() const { return face->vertex(advance(corner)); }
    __forceinline bool valid() const { return triangle()!=0; }
    __forceinline bool unbound() const { return !link().valid(); }
    __forceinline bool master() const { return BevelVertex::ordered(start(),end())||unbound(); }
};
struct BevelEdge: BevelEdgeBase<BevelEdge> {
    __forceinline BevelEdge(BevelTri* f,int i):BevelEdgeBase<BevelEdge>(f,i) {}
    __forceinline BevelEdge(const unsigned int& id):BevelEdgeBase<BevelEdge>(id) {}
    __forceinline BevelEdge(const BevelEdge& e) { face=e.face; corner=e.corner; }
    __forceinline bool samePlane() const { return triangle()->m_kTriangleNormal==link().triangle()->m_kTriangleNormal; }
};
struct BevelArray {
    BevelVector* m_data; int m_iElementCount,m_cap;
    __forceinline const BevelVector& operator[](int i) const { return m_data[i]; }
    __forceinline void append(const BevelVector& v) {
        S_00d7c340_Router* r=hkMemoryRouter_getInstance();
        if(m_iElementCount==(m_cap&0x3fffffff)) ResizeAudioStream(r->unk10,this,16);
        BevelVector* dst=m_data+m_iElementCount;
        for(int k=0;k<1;k++) dst[k]=v;
        m_iElementCount++;
    }
};
struct BevelHull {
    int m_00;
    int m_04;
    int m_08;
    char m_0c;
    char m_walk;
    char m_0e;
    char m_0f;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    BevelVertex* m_firstVertex;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    BevelTri* m_firstTri;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    BevelArray m_kPlaneArray;
    int m_60; int m_64; int m_68; int m_6c; int m_70; int m_74;
    int m_78; int m_7c; int m_80; int m_84; int m_88; int m_8c; int m_90; int m_94;
    int m_98; int m_9c; int m_a0; int m_a4; int m_a8; int m_ac; int m_b0; int m_b4;
    int m_b8; int m_bc; int m_c0; int m_c4; int m_c8; int m_cc; int m_d0; int m_d4;
    int m_d8; int m_dc; int m_e0; int m_e4; int m_e8; int m_ec;
    BevelVector m_offset;
    BevelVector m_unk100;
    BevelVector m_vScale;
    int m_120; int m_124; int m_128; int m_12c; int m_130; int m_134; int m_138; int m_13c;
    int m_140; int m_144; int m_148; int m_14c; int m_150; int m_154; int m_158; int m_15c;
    int m_160; int m_164; int m_168; int m_16c; int m_170; int m_174; int m_178; int m_17c;
    int m_180; int m_184; int m_188; int m_18c; int m_190; int m_194; int m_198; int m_19c;
    int m_1a0; int m_1a4;
    int m_eVertexFloatDimensions;
    int m_1ac;
    unsigned int m_uiUniqueId;
    char m_1b4;
    char m_hasIndices;

    void ProcessEntries_00d7caa0(float maxCos, BevelArray& out) const;
    __forceinline BevelVector position(const BevelVertex* v) const {
        BevelVector point;
        point.set((float)v->m_pos[0],(float)v->m_pos[1],(float)v->m_pos[2],DAT_01011d78);
        point.mul(m_vScale); point.add(m_offset); return point;
    }
};


struct BevelStream {
    void* vtable; int unk04,unk08;
    void FUN_00cb1600(char*,int) throw();
    BevelStream& ProcessAndReturnValue_00cc01c0(const char*) throw();
    BevelStream& EvaluateValue_00cc02d0(unsigned int) throw();
    void FUN_00cc00e0() throw();
};
// @fnv 0x00d7caa0
// src: GUESS 0x00d7caa0 (confidence: low)
void BevelHull::ProcessEntries_00d7caa0(float maxCos, BevelArray& out) const {
    if(!m_hasIndices) {
        char msg[512];
        BevelStream stream;
        stream.FUN_00cb1600(msg,512);
        stream.ProcessAndReturnValue_00cc01c0(str_010d3574).EvaluateValue_00cc02d0(m_uiUniqueId).ProcessAndReturnValue_00cc01c0((const char*)&DAT_0103d078);
        if(((S_00d75210_Error*)DAT_01268360)->message(3,0x79f9d886,msg,str_010d3540,328)) { __debugbreak(); stream.FUN_00cc00e0(); } else stream.FUN_00cc00e0();
    }
    if(m_eVertexFloatDimensions!=3) return;
    for(BevelTri* tri=m_firstTri;tri;tri=tri->m_next) {
        for(int i=0;i<3;++i) {
            BevelEdge edge(tri,i);
            BevelEdge neighbor(edge.link());
            if(edge.master() && !edge.samePlane()) {
                const BevelVector& a=m_kPlaneArray[edge.triangle()->m_kTriangleNormal];
                const BevelVector& b=m_kPlaneArray[neighbor.triangle()->m_kTriangleNormal];
                float angle=a.dot(b);
                if(angle<maxCos) {
                    BevelVector plane;
                    plane.sum(a,b);
                    if(plane.normalize()==0) {
                        plane(3)=plane.dot(position(m_firstVertex));
                        if(m_walk) {
                            for(BevelVertex* v=m_firstVertex->m_next;v;v=v->m_next) {
                                plane(3)=bevelMaximum(plane.at(3),plane.dot(position(v)));
                            }
                        }
                        plane(3)=-plane(3);
                        out.append(plane);
                    }
                }
            }
        }
    }
}

using ::_mm_mul_ss;
using ::_mm_add_ps;


extern const char str_010d3574[];
extern const char str_010d3540[];

struct BoxStream {
    int unk00;
    int unk04;
    int unk08;
    BoxStream* FUN_00cb1600(void* buf, int size);
    BoxStream* ProcessAndReturnValue_00cc01c0(const char*,int,char*);
    BoxStream* EvaluateValue_00cc02d0();
    void ProcessAndReturnValue_00cc01c0();
    void FUN_00cc00e0();
};
struct BoxScalar;
class __declspec(align(16)) BoxVector {
    LocalM128 value;
public:
    LocalM128& q() { return value; }
    const LocalM128& q() const { return value; }
    BoxVector& operator=(const BoxVector& v) { value=v.value; return *this; }
    __forceinline BoxScalar dot(const BoxVector& v) const;
    __forceinline void scale(float f);
    __forceinline void cross(const BoxVector& a,const BoxVector& b);
    __forceinline int normalize();
};
extern float DAT_0104da48;

class BoxScalar {
    LocalM128 m_vValue;
public:
    BoxScalar() {}
    BoxScalar(float f):m_vValue(_mm_load_ss(&f)) {}
    BoxScalar(const LocalM128& r) : m_vValue(r) {}
    const LocalM128& get() const { return m_vValue; }
    LocalM128 broadcast() const { return _mm_shuffle_ps(m_vValue,m_vValue,0); }
    operator float() const { float f; _mm_store_ss(&f, m_vValue); return f; }
};
__forceinline BoxScalar BoxVector::dot(const BoxVector& v) const {
    LocalM128 product=_mm_mul_ps(value,v.value);
    LocalM128 xy=_mm_add_ss(_mm_shuffle_ps(product,product,85),product);
    return _mm_add_ss(_mm_shuffle_ps(product,product,170),xy);
}
__forceinline BoxScalar operator*(const BoxScalar& a, const BoxScalar& b)
{
    return _mm_mul_ss(a.get(), b.get());
}
__forceinline void BoxVector::cross(const BoxVector& a,const BoxVector& b)
{
    LocalM128 first=_mm_mul_ps(_mm_shuffle_ps(a.q(),a.q(),201),_mm_shuffle_ps(b.q(),b.q(),210));
    LocalM128 second=_mm_mul_ps(_mm_shuffle_ps(a.q(),a.q(),210),_mm_shuffle_ps(b.q(),b.q(),201));
    value=_mm_sub_ps(first,second);
}
__forceinline void hkSetMul4(BoxVector& v, float s, const BoxVector& a)
{
    LocalM128 r = _mm_load_ss(&s); r = _mm_shuffle_ps(r, r, 0);
    v.q() = _mm_mul_ps(r, a.q());
}
__forceinline void hkAddMul4(BoxVector& v, float s, const BoxVector& a)
{
    LocalM128 r = _mm_load_ss(&s); r = _mm_shuffle_ps(r, r, 0);
    v.q() = _mm_add_ps(_mm_mul_ps(r, a.q()), v.q());
}
__forceinline void hkSubMul4(BoxVector& v, LocalM128 r, const BoxVector& a)
{
    v.q() = _mm_sub_ps(v.q(), _mm_mul_ps(_mm_shuffle_ps(r, r, 0), a.q()));
}
__forceinline void hkSet(BoxVector& v, float a, float b, float c, float d)
{
    v.q() = _mm_setr_ps(a, b, c, d);
}
__forceinline void BoxVector::scale(float f) {
    BoxScalar factor(_mm_load_ss(&f)); value=_mm_mul_ps(factor.broadcast(),value);
}
__forceinline int BoxVector::normalize() {
    float squared=dot(*this);
    if(squared!=0.0f) {
        float root=(float)sqrt(squared); scale(1.0f/root); return 0;
    }
    return 1;
}

__forceinline void scalarDot(BoxScalar& out,const BoxVector& a,const BoxVector& b) { out=a.dot(b); }
using ::_mm_load_ps;
__forceinline LocalM128 quadDot(LocalM128 a,LocalM128 b) { LocalM128 p=_mm_mul_ps(a,b); LocalM128 xy=_mm_add_ss(_mm_shuffle_ps(p,p,85),p);return _mm_add_ss(_mm_shuffle_ps(p,p,170),xy); }
struct BoxTransform {
    BoxVector m_kColumn0;
    BoxVector m_kColumn1;
    BoxVector m_kColumn2;
    BoxVector m_vTranslation;
};

template <class T> struct BoxPointer {
    T m_kStorage;
    T val() const { return m_kStorage; }
};

struct BoxFace {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int m_kTriangleNormal;
};

struct BoxEdge {
    BoxFace* m_tri;
    int m_uiEdgeIndex;
    BoxEdge(BoxFace* t, int i) : m_tri(t), m_uiEdgeIndex(i) {}
};

struct BoxIterator {
    BoxFace* m_tri;
    int m_uiEdgeIndex;
    void FUN_00d7d220(BoxEdge e);
    void hkgpAbstractMesh_struct_hkgpConvexHullImpl_Edge_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHullImpl_Triangle_struct_hkContainerHeapAllocator_EdgeIterator_next();
    operator const void*() const { return m_tri ? this : 0; }
};

struct BoxHull {
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
    BoxFace* m_firstTri;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    BoxVector* m_kPlaneArray;
    int m_iValue;
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
    int m_eVertexFloatDimensions;
    int unk1ac;
    int m_uiEdgeIndex;
    char unk1b4;
    char m_hasIndex;
    float GetDirectionalProjectionSpan(const BoxVector& axis, float& mn, float& mx) const;
    float hkgpConvexHullImpl_getOrientedRectangle(BoxPointer<const BoxVector*> plane, BoxVector& halfExtents, BoxTransform& transform) const;
};

// @fnv 0x00d7f090
// src: XBOX_PDB 0x00d7f090
float BoxHull::hkgpConvexHullImpl_getOrientedRectangle(BoxPointer<const BoxVector*> plane, BoxVector& halfExtents, BoxTransform& transform) const
{
    if (!m_hasIndex) {
        unsigned int buf[128];
        BoxStream s;
        s.FUN_00cb1600(buf, 0x200);
        s.ProcessAndReturnValue_00cc01c0(str_010d3574,m_uiEdgeIndex,&DAT_0103d078)->EvaluateValue_00cc02d0()->ProcessAndReturnValue_00cc01c0();
int result=DAT_01268360->message(3, 0x79f9d886, (const char*)buf, str_010d3540, 0x148);
        if (result == 0) {
            s.FUN_00cc00e0();
        } else if (result > 0) {
            __debugbreak();
            s.FUN_00cc00e0();
        } else {
            __debugbreak();
            s.FUN_00cc00e0();
        }
    }
    float centers[2] = { DAT_0104da48, DAT_0104da48 };
    float extents[2] = { DAT_0104da48, DAT_0104da48 };
    float bestArea = DAT_0104da48;
    BoxVector axes[2]; for(int k=0;k<8;++k) reinterpret_cast<unsigned int*>(axes)[k]=reinterpret_cast<const unsigned int*>(&DAT_01267e30)[k%4];
    if (m_eVertexFloatDimensions == 3) {
        BoxIterator it;
        BoxVector e;
        BoxVector n;
        for (it.FUN_00d7d220(BoxEdge(m_firstTri, 0)); it; it.hkgpAbstractMesh_struct_hkgpConvexHullImpl_Edge_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHullImpl_Triangle_struct_hkContainerHeapAllocator_EdgeIterator_next()) {
            BoxFace* o = (BoxFace*)(it.m_tri->m_ppLinks[it.m_uiEdgeIndex] & ~3);
            int pb = o->m_kTriangleNormal;
            int pa = it.m_tri->m_kTriangleNormal;
            if (pa == pb)
                continue;
            const BoxVector* __restrict pDir = plane.val();
            const BoxVector& dir = *pDir;
            const BoxVector& b = m_kPlaneArray[pb];
            const BoxVector& a = m_kPlaneArray[pa];
            BoxScalar db,da;scalarDot(db,b,dir);da=quadDot(_mm_load_ps((const float*)&a.q()),dir.q()); float product=BoxScalar(_mm_mul_ss(da.get(),db.get()));
            if(product<=0.0f) {
                e.cross(a,b);
                const LocalM128 dir_yzx = _mm_shuffle_ps(dir.q(), dir.q(), 0xc9);
                const LocalM128 dir_zxy = _mm_shuffle_ps(dir.q(), dir.q(), 0xd2);
                n.q() = _mm_sub_ps(
                    _mm_mul_ps(dir_yzx, _mm_shuffle_ps(e.q(), e.q(), 0xd2)),
                    _mm_mul_ps(dir_zxy, _mm_shuffle_ps(e.q(), e.q(), 0xc9)));
                if(n.normalize()==0) {
                    e.q() = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(n.q(), n.q(), 0xc9), dir_zxy),
                        _mm_mul_ps(_mm_shuffle_ps(n.q(), n.q(), 0xd2), dir_yzx));
                    if(e.normalize()==0) {
                        float r0[2], r1[2];
                        float f0 = GetDirectionalProjectionSpan(n, r0[0], r0[1]);
                        float f1 = GetDirectionalProjectionSpan(e, r1[0], r1[1]);
                        float area = f0 * f1;
                        if (area < bestArea) {
                            bestArea = area;
                            axes[0] = n;
                            extents[0] = f0;
                            axes[1] = e;
                            extents[1] = f1;
                            centers[0] = (r0[0] + r0[1]) * 0.5;
                            centers[1] = (r1[0] + r1[1]) * 0.5;
                        }
                    }
                }
            }
        }
    } else if (m_eVertexFloatDimensions == 2) {
        for (int i = 0; i < m_iValue; i++) {
            BoxVector v = m_kPlaneArray[i];
            const BoxVector* __restrict pDir = plane.val();
            const BoxVector& dir = *pDir;
            BoxVector n;
            n.q() = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v.q(), v.q(), 0xd2), _mm_shuffle_ps(dir.q(), dir.q(), 0xc9)), _mm_mul_ps(_mm_shuffle_ps(v.q(), v.q(), 0xc9), _mm_shuffle_ps(dir.q(), dir.q(), 0xd2)));
            if(n.normalize()==0) {
                float r0[2], r1[2];
                float f0 = GetDirectionalProjectionSpan(v, r0[0], r0[1]);
                float f1 = GetDirectionalProjectionSpan(n, r1[0], r1[1]);
                float area = f0 * f1;
                if (area < bestArea) {
                    bestArea = area;
                    axes[0] = v;
                    extents[0] = f0;
                    axes[1] = n;
                    extents[1] = f1;
                    centers[0] = (r0[0] + r0[1]) * 0.5;
                    centers[1] = (r1[0] + r1[1]) * 0.5;
                }
            }
        }
    }
    hkSetMul4(transform.m_vTranslation, centers[0], axes[0]);
    hkAddMul4(transform.m_vTranslation, centers[1], axes[1]);
    const BoxVector& dir = *plane.val();
    hkSubMul4(transform.m_vTranslation, _mm_shuffle_ps(dir.q(), dir.q(), 0xff), dir);
    transform.m_kColumn1 = axes[1];
    transform.m_kColumn0 = axes[0];
    transform.m_kColumn2 = dir;
    hkSet(halfExtents, extents[0] * 0.5, extents[1] * 0.5, 0.0f, 0.0f);
    return bestArea;
}

namespace S00d81510_Intrinsics {
extern "C" {
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_add_ss;
using ::_mm_sub_ss;
using ::_mm_min_ps;
using ::_mm_max_ps;
using ::_mm_and_ps;
using ::_mm_rcp_ps;
using ::_mm_unpackhi_ps;
using ::_mm_shuffle_ps;
using ::_mm_load_ss;
using ::_mm_setr_ps;
using ::_mm_store_ss;
}
}
extern const char str_010d3718[];
extern const char str_010d3540[];
extern const LocalM128 DAT_010c7160;
extern const LocalM128 DAT_010c7170;
extern const LocalM128 DAT_01017d10;

namespace S00d81510_Constants {
static const double DAT_01032980 = double(1e-4f);
}
struct S00d81510_Stream {
    int unk00;
    int unk04;
    int unk08;
    S00d81510_Stream* FUN_00cb1600(void* buf, int size);
    S00d81510_Stream& ProcessAndReturnValue_00cc01c0(const char* s);
    void FUN_00cc00e0();
};
class S00d81510_SimdReal {
public:
    __forceinline S00d81510_SimdReal(const hkSimdReal& v) : m_vValue(v.q()) {}
    __forceinline S00d81510_SimdReal(const LocalM128& x) : m_vValue(x) {}
    __forceinline S00d81510_SimdReal(float x) { m_vValue = S00d81510_Intrinsics::_mm_load_ss(&x); }
    __forceinline operator float() const { float s; S00d81510_Intrinsics::_mm_store_ss(&s, m_vValue); return s; }
    __forceinline LocalM128 broadcast() const { return S00d81510_Intrinsics::_mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const LocalM128& getQuad() const { return m_vValue; }
    LocalM128 m_vValue;
};
typedef const S00d81510_SimdReal& S00d81510_SimdParam;
__forceinline S00d81510_SimdReal operator-(S00d81510_SimdParam r)
{
    return S00d81510_Intrinsics::_mm_sub_ss(DAT_010c7160, r.getQuad());
}
__forceinline float S00d81510_sqrt(float r) { return sqrtf(r); }
__forceinline float S00d81510_sqrtInverse(float r) { return 1.0f / S00d81510_sqrt(r); }
template <typename T> __forceinline T S00d81510_min2(T x, T y) { return x < y ? x : y; }
template <typename T> __forceinline T S00d81510_max2(T x, T y) { return x > y ? x : y; }
template <typename T> __forceinline void S00d81510_swap(T& x, T& y) { T t(x); x = y; y = t; }
__forceinline LocalM128 S00d81510_quadReciprocal(LocalM128 r)
{
    LocalM128 e = S00d81510_Intrinsics::_mm_rcp_ps(r);
    return S00d81510_Intrinsics::_mm_sub_ps(S00d81510_Intrinsics::_mm_add_ps(e, e), S00d81510_Intrinsics::_mm_mul_ps(S00d81510_Intrinsics::_mm_mul_ps(e, r), e));
}



__forceinline void hkVector4::sub4(const hkVector4& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
__forceinline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents); }
__forceinline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents); }
__forceinline void hkVector4::setReciprocal3(const hkVector4& v)
{
    hkVector4 v1111; v1111.getQuad() = DAT_010c7170;
    hkVector4 tmp; tmp.setXYZW(v, v1111);
    m_vComponents = S00d81510_quadReciprocal(tmp.m_vComponents);
}
__forceinline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
__forceinline const hkVector4& __cdecl hkVector4::getZero() { return *reinterpret_cast<const hkVector4*>(&DAT_01267e30); }
static __forceinline int vectorNormalize3IfNotZero(hkVector4& v)
{
    const float lengthSqrd3 = v.lengthSquared3();
    if (lengthSqrd3 != 0.0f) {
        v.mul4(hkSimdReal(S00d81510_sqrtInverse(lengthSqrd3)));
        return 0;
    }
    return 1;
}
static __forceinline void vectorSetInt24W(hkVector4& v, int value) { (reinterpret_cast<unsigned int*>(&v))[3] = value |= 0x3f000000; }
static __forceinline int vectorMajorAxis(const hkVector4& v)
{
    hkVector4 tmp;
    tmp.setAbs4(v);
    return tmp(0) < tmp(1) ? (tmp(1) < tmp(2) ? 2 : 1) : (tmp(0) < tmp(2) ? 2 : 0);
}

struct S00d81510_TypeIsPod {};
struct S00d81510_TypeIsClass {};
struct S00d81510_Vertex;
__forceinline void* operator new(unsigned int, S00d81510_Vertex* p) throw() { return p; }

struct S00d81510_Allocator {
    virtual void vtbl00();
    virtual void vtbl04();
    virtual void vtbl08();
    virtual void vtbl0c();
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(T);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};
struct S00d81510_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d81510_Allocator* m_pStreamAllocator;
    __forceinline S00d81510_Allocator& heap() { return *m_pStreamAllocator; }
};
extern "C" void __cdecl hkArrayUtil__reserve(S00d81510_Allocator* alloc, void* array, int numElements, int sizeElem);

template <typename T> __forceinline void S00d81510_construct(T* t, int n, S00d81510_TypeIsPod) {}
template <typename T> __forceinline void S00d81510_destruct(T* t, int n, S00d81510_TypeIsPod) {}
template <typename T> __forceinline void S00d81510_construct(T* t, int n, S00d81510_TypeIsClass)
{
    for (int i = 0; i < n; ++i) {
        ::new (t + i) T;
    }
}
template <typename T> __forceinline void S00d81510_destruct(T* t, int n, S00d81510_TypeIsClass)
{
    for (int i = 0; i < n; ++i) {
        static_cast<T*>(t)[i].~T();
    }
}

template <typename T, typename Tag>
class S00d81510_ArrayBaseLocalForm { // local form of hkArrayBase: 0x00d81510 needs the original constructor stores; shared base construction changes bytes.
public:
    __forceinline S00d81510_ArrayBaseLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~S00d81510_ArrayBaseLocalForm() {}
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline void clear() { S00d81510_destruct(m_data, m_iElementCount, Tag()); m_iElementCount = 0; }
    __forceinline void _clearAndDeallocate(S00d81510_Allocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(S00d81510_Allocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S00d81510_Allocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        S00d81510_destruct(m_data + n, m_iElementCount - n, Tag());
        S00d81510_construct(m_data + m_iElementCount, n - m_iElementCount, Tag());
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct S00d81510_ContainerHeapAllocator {
    __forceinline S00d81510_Allocator& get(const void*) { return reinterpret_cast<S00d81510_Router&>(*hkMemoryRouter_getInstance()).heap(); }
};
template <typename T, typename Tag>
class S00d81510_Array : public S00d81510_ArrayBaseLocalForm<T, Tag> {
public:
    typedef S00d81510_ContainerHeapAllocator AllocatorType;
    __forceinline S00d81510_Array() : S00d81510_ArrayBaseLocalForm<T, Tag>() {}
    __forceinline ~S00d81510_Array() { ClearAndRelease(); }
    __forceinline void ClearAndRelease() { S00d81510_ArrayBaseLocalForm<T, Tag>::_clearAndDeallocate(AllocatorType().get(this)); }
    __forceinline void SetSizeAndGrow(int n) { S00d81510_ArrayBaseLocalForm<T, Tag>::_setSize(AllocatorType().get(this), n); }
    void SwapThreeInts(S00d81510_Array& a);
};

struct S00d81510_Item {
    __forceinline S00d81510_Item() {}
    __forceinline S00d81510_Item(const S00d81510_Item& o) {}
    __forceinline S00d81510_Item& operator=(const S00d81510_Item& o) { return *this; }
    S00d81510_Vertex* m_next;
    S00d81510_Vertex* m_pSecondNode;
};
struct S00d81510_Vertex : S00d81510_Item {
    __forceinline S00d81510_Vertex() { m_2c = 0.0f; m_uiEdgeIndex = -1; }
    hkVector4 m_pObservedSource;
    int m_uiX[3];
    float m_2c;
    int m_refs;
    int m_uiEdgeIndex;
};
__forceinline bool operator==(const S00d81510_Vertex& a, const S00d81510_Vertex& b)
{
    return a.m_uiX[0] == b.m_uiX[0] && a.m_uiX[1] == b.m_uiX[1];
}
__forceinline bool operator!=(const S00d81510_Vertex& a, const S00d81510_Vertex& b) { return !(a == b); }
__forceinline int S00d81510_round(float x) { return (int)(x + (x < 0 ? -0.5f : 0.5f)); }

struct S00d81510_Less {};
void __cdecl Hkgpconvexhull_SortRecordRange(S00d81510_Vertex* pArr, int d, int h, S00d81510_Less cmpLess);
template <typename T, typename L> __forceinline void S00d81510_quickSort(T* pArr, int iSize, L cmpLess)
{
    if (iSize > 1) {
        int low = 0;
        int high = iSize - 1;
        Hkgpconvexhull_SortRecordRange(pArr, low, high, cmpLess);
    }
}
template <typename T> __forceinline void S00d81510_quickSort(T* pArr, int iSize) { S00d81510_quickSort(pArr, iSize, S00d81510_Less()); }

struct S00d81510_VertexList {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;
    int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c;
    S00d81510_Vertex* CloneNode(const S00d81510_Vertex& v);
    __forceinline S00d81510_Vertex* allocate(const S00d81510_Vertex& v = S00d81510_Vertex()) { return CloneNode(v); }
};
struct S00d81510_Bool {
    char m_cBooleanValue;
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
};
typedef S00d81510_Array<hkVector4, S00d81510_TypeIsPod> S00d81510_VecArray;
typedef S00d81510_Array<S00d81510_Vertex, S00d81510_TypeIsClass> S00d81510_VertexArray;

class __declspec(align(16)) S00d81510_Hull {
public:
    S00d81510_Bool m_bFlagAtOffset00;
    char unk01; char unk02; char unk03;
    int unk04;
    S00d81510_Bool m_bFlagAtOffset08;
    S00d81510_Bool m_bFlagAtOffset09;
    S00d81510_Bool m_bFlagAtOffset0A;
    S00d81510_Bool m_bFlagAtOffset0B;
    S00d81510_Bool m_bFlagAtOffset0C;
    char unk0d; char unk0e; char unk0f;
    int unk10;
    int unk14;
    S00d81510_VertexList m_meshVertices;
    S00d81510_VertexArray m_kVertices;
    int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc;
    hkVector4 m_kVectorAtOffsetD0;
    hkVector4 m_kVectorAtOffsetE0;
    hkVector4 m_domainCenter;
    hkVector4 m_domainScale;
    hkVector4 m_domainScaleInv;
    int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4;
    int m_eVertexFloatDimensions;

    void hkgpConvexHullImpl_reset(bool planar);
    bool hkgpConvexHullImpl_flushPending();
    void ProcessEntries_00d7d2a0();
    void hkgpConvexHullImpl_buildMassProperties_hkgpConvexHullImpl_PositionAsTransform();
    int hkgpConvexHullImpl_build(const hkVector4* points, int numPoints, bool planar, const S00d81510_Hull* domainSource);

    __forceinline S00d81510_Vertex transformChecked(const hkVector4& x, bool& outOfRange) const
    {
        S00d81510_Vertex v;
        hkVector4 tx = x;
        tx.sub4(m_domainCenter);
        v.m_pObservedSource = x;
        tx.mul4(m_domainScale);
        for (int i = 0; i < 3; ++i) {
            outOfRange |= (tx(i) > 8191.0 || tx(i) < -8192.0);
            v.m_uiX[i] = S00d81510_round(S00d81510_max2(-8192.0f, S00d81510_min2(8191.0f, tx(i))));
        }
        return v;
    }
    __forceinline S00d81510_Vertex transform(const hkVector4& x) const
    {
        bool outOfRange;
        return transformChecked(x, outOfRange);
    }
    __forceinline static void makeVertex(const S00d81510_Vertex& v, S00d81510_Vertex* dst)
    {
        *dst = v;
        dst->m_refs = 0;
    }
    __forceinline static int orientation(const S00d81510_Vertex& a, const S00d81510_Vertex& b, const S00d81510_Vertex& c)
    {
        const int d0 = (b.m_uiX[0] - a.m_uiX[0]) * (c.m_uiX[1] - a.m_uiX[1]);
        const int d1 = (b.m_uiX[1] - a.m_uiX[1]) * (c.m_uiX[0] - a.m_uiX[0]);
        return d0 - d1;
    }
    template <int A, int B> __forceinline void swapCoordinates()
    {
        for (int i = 0, n = m_kVertices.GetLogicalSize(); i < n; ++i) {
            S00d81510_swap(m_kVertices[i].m_uiX[A], m_kVertices[i].m_uiX[B]);
        }
    }
    __forceinline void projectOnMajorAxis(const hkVector4& plane)
    {
        switch (vectorMajorAxis(plane)) {
        case 0: swapCoordinates<0, 2>(); break;
        case 1: swapCoordinates<1, 2>(); break;
        }
    }
};

// @fnv 0x00d81510
// src: COMMUNITY 0x00d81510
int S00d81510_Hull::hkgpConvexHullImpl_build(const hkVector4* points, int numPoints, bool planar, const S00d81510_Hull* domainSource)
{
    if (numPoints && (((unsigned long)points) & 15)) {
        S00d81510_VecArray aligned;
        aligned.SetSizeAndGrow(numPoints);
        for (int i = 0; i < numPoints; ++i) {
            aligned[i].set(points[i](0), points[i](1), points[i](2), points[i](3));
        }
        return hkgpConvexHullImpl_build(&aligned[0], numPoints, planar, domainSource);
    }
    hkgpConvexHullImpl_reset(planar);
    if (numPoints > 0) {
        if (domainSource) {
            m_domainCenter = domainSource->m_domainCenter;
            m_domainScale = domainSource->m_domainScale;
            m_domainScaleInv = domainSource->m_domainScaleInv;
        } else if (m_bFlagAtOffset0C) {
            m_domainCenter.set(0, 0, 0, 0);
            m_domainScale.set(1, 1, 1, 0);
            m_domainScaleInv.set(1, 1, 1, 0);
        } else {
            hkVector4 auiLowerBounds = points[0];
            hkVector4 auiUpperBounds = points[0];
            for (int i = 1; i < numPoints; ++i) {
                auiLowerBounds.setMin4(auiLowerBounds, points[i]);
                auiUpperBounds.setMax4(auiUpperBounds, points[i]);
            }
            for (int i = 0; i < 3; ++i) {
                if (auiLowerBounds(i) < -3.40282e38f || auiUpperBounds(i) > 3.40282e38f) {
                    char buffer[512];
                    S00d81510_Stream ostr;
                    ostr.FUN_00cb1600(buffer, 512);
                    ostr.ProcessAndReturnValue_00cc01c0(str_010d3718);
                    if (DAT_01268360->message(3, 0x405a2174, buffer, str_010d3540, 0x228))
                        __debugbreak();
                    ostr.FUN_00cc00e0();
                }
                if ((auiUpperBounds(i) - auiLowerBounds(i)) < 1e-5f) {
                    const float c = (auiUpperBounds(i) + auiLowerBounds(i)) / 2;
                    auiLowerBounds(i) = S00d81510_min2(auiLowerBounds(i), c - 1e-5f);
                    auiUpperBounds(i) = S00d81510_max2(auiUpperBounds(i), c + 1e-5f);
                }
            }
            hkVector4 ext;
            ext.setSub4(auiUpperBounds, auiLowerBounds);
            ext.mul4(hkSimdReal(0.5f));
            hkVector4 center;
            center.setAdd4(auiLowerBounds, ext);
            ext.setReciprocal3(ext);
            m_domainCenter = center;
            m_domainScale = ext;
            m_domainCenter(3) = 0;
            m_domainScale(3) = 0;
            m_domainScale.mul4(hkSimdReal(8191.0f));
            m_domainScaleInv.setReciprocal3(m_domainScale);
        }
        m_eVertexFloatDimensions = S00d81510_min2(numPoints - 1, 3);
        m_kVectorAtOffsetD0 = hkVector4::getZero();
        if (planar) {
            m_eVertexFloatDimensions = 2;
        } else {
            m_kVectorAtOffsetE0 = hkVector4::getZero();
            if (numPoints > 1) {
                m_kVectorAtOffsetD0.setSub4(points[1], points[0]);
            }
            if (numPoints > 2) {
                for (int i = 0; i < numPoints; ++i) {
                    const hkVector4 o = points[i];
                    for (int j = i + 1; j < numPoints; ++j) {
                        hkVector4 e0;
                        e0.setSub4(points[j], o);
                        for (int k = j + 1; k < numPoints; ++k) {
                            hkVector4 e1;
                            e1.setSub4(points[k], o);
                            hkVector4 cross;
                            cross.setCross(e0, e1);
                            const S00d81510_SimdReal len = cross.lengthSquared3();
                            if (len > m_kVectorAtOffsetE0.lengthSquared3()) {
                                m_kVectorAtOffsetE0 = cross;
                                if (len > float(S00d81510_Constants::DAT_01032980)) {
                                    i = j = k = numPoints;
                                }
                            }
                        }
                    }
                }
                if (vectorNormalize3IfNotZero(m_kVectorAtOffsetE0) != 0) {
                    m_kVectorAtOffsetE0.set(1, 0, 0, 0);
                }
                m_kVectorAtOffsetE0(3) = -S00d81510_SimdReal(m_kVectorAtOffsetE0.dot3(points[0]));
            }
        }
        m_kVertices.clear();
        m_kVertices.SetSizeAndGrow(numPoints);
        for (int i = 0; i < numPoints; ++i) {
            m_kVertices[i] = transform(points[i]);
            if (m_bFlagAtOffset08) {
                vectorSetInt24W(m_kVertices[i].m_pObservedSource, i);
            }
        }
        if (!planar && m_bFlagAtOffset0B) {
            S00d81510_quickSort(&m_kVertices[0], m_kVertices.GetLogicalSize());
        }
        bool redo;
        do {
            redo = false;
            switch (m_eVertexFloatDimensions) {
            case 0:
                makeVertex(m_kVertices[0], m_meshVertices.allocate());
                break;
            case 1: {
                int iMin = 0;
                int iMax = 0;
                for (int i = 1; i < numPoints; ++i) {
                    const S00d81510_SimdReal d = m_kVectorAtOffsetD0.dot3(m_kVertices[i].m_pObservedSource);
                    if (d < m_kVectorAtOffsetD0.dot3(m_kVertices[iMin].m_pObservedSource)) iMin = i;
                    if (d > m_kVectorAtOffsetD0.dot3(m_kVertices[iMax].m_pObservedSource)) iMax = i;
                }
                S00d81510_Vertex a = m_kVertices[iMin];
                S00d81510_Vertex b = m_kVertices[iMax];
                if (a != b) {
                    S00d81510_Vertex* va = m_meshVertices.allocate();
                    S00d81510_Vertex* vb = m_meshVertices.allocate();
                    makeVertex(a, va);
                    makeVertex(b, vb);
                } else {
                    m_eVertexFloatDimensions = 0;
                    redo = true;
                }
                break;
            }
            case 2: {
                S00d81510_VertexArray hull;
                int numHull = 0;
                projectOnMajorAxis(m_kVectorAtOffsetE0);
                S00d81510_quickSort(&m_kVertices[0], m_kVertices.GetLogicalSize());
                hull.SetSizeAndGrow(numPoints * 2);
                for (int i = 0; i < numPoints; ++i) {
                    while (numHull >= 2 && orientation(hull[numHull - 2], hull[numHull - 1], m_kVertices[i]) <= 0) {
                        --numHull;
                    }
                    hull[numHull++] = m_kVertices[i];
                }
                for (int i = numPoints - 2, t = numHull + 1; i >= 0; --i) {
                    while (numHull >= t && orientation(hull[numHull - 2], hull[numHull - 1], m_kVertices[i]) <= 0) {
                        --numHull;
                    }
                    hull[numHull++] = m_kVertices[i];
                }
                if (numHull > 3) {
                    m_kVertices.SwapThreeInts(hull);
                    m_kVertices.SetSizeAndGrow(numHull - 1);
                    projectOnMajorAxis(m_kVectorAtOffsetE0);
                    for (int i = 0; i < m_kVertices.GetLogicalSize(); ++i) {
                        makeVertex(m_kVertices[i], m_meshVertices.allocate());
                    }
                    m_kVertices.clear();
                } else {
                    projectOnMajorAxis(m_kVectorAtOffsetE0);
                    m_eVertexFloatDimensions = 1;
                    redo = true;
                }
                break;
            }
            case 3:
                if (!hkgpConvexHullImpl_flushPending()) {
                    if (m_bFlagAtOffset00) {
                        m_eVertexFloatDimensions = 2;
                        redo = true;
                    } else {
                        m_eVertexFloatDimensions = -1;
                    }
                }
                break;
            }
        } while (redo);
    }
    if (m_eVertexFloatDimensions != -1) {
        if (m_bFlagAtOffset09) ProcessEntries_00d7d2a0();
        if (m_bFlagAtOffset0A) hkgpConvexHullImpl_buildMassProperties_hkgpConvexHullImpl_PositionAsTransform();
    }
    return m_eVertexFloatDimensions;
}

// src: HAVOK_LIB 0x00d752c0
__declspec(noinline) int __stdcall hkgpConvexHull_getVertex(int* arr, int idx) { return arr[idx + 2]; }
struct HullPlaneOwner {
    void UpdateFields_00d75b80(LocalM128& out, const int* triangle);
};
// @fnv 0x00d75b80
// src: GUESS 0x00d75b80 (confidence: low)
void __thiscall HullPlaneOwner::UpdateFields_00d75b80(LocalM128& out, const int* triangle)
{
    OffsetOwner* owner = (OffsetOwner*)this;
    LocalM128 p0 = *owner->Hkgpconvexhull_GetPayloadAddress((PayloadOwner*)hkgpConvexHull_getVertex((int*)triangle, 0));
    LocalM128 p1 = *owner->Hkgpconvexhull_GetPayloadAddress((PayloadOwner*)hkgpConvexHull_getVertex((int*)triangle, 1));
    LocalM128 e1 = _mm_sub_ps(p1, p0);
    LocalM128 p2 = *owner->Hkgpconvexhull_GetPayloadAddress((PayloadOwner*)hkgpConvexHull_getVertex((int*)triangle, 2));
    LocalM128 e2 = _mm_sub_ps(p2, p0);

    LocalM128 a = _mm_mul_ps(_mm_shuffle_ps(e2, e2, 0xc9), _mm_shuffle_ps(e1, e1, 0xd2));
    LocalM128 b = _mm_mul_ps(_mm_shuffle_ps(e2, e2, 0xd2), _mm_shuffle_ps(e1, e1, 0xc9));
    LocalM128 n = _mm_sub_ps(b, a);

    LocalM128 sq = _mm_mul_ps(n, n);
    LocalM128 t = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    LocalM128 dot = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), t);

    LocalM128 r = _mm_rsqrt_ss(dot);
    LocalM128 dd = _mm_mul_ss(_mm_mul_ss(dot, r), r);
    LocalM128 mask = _mm_cmpeq_ss(dot, _mm_set_ss(0.0f));
    LocalM128 k = _mm_sub_ss(_mm_set_ss(3.0f), dd);
    LocalM128 s = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), r), k);
    s = _mm_andnot_ps(mask, s);

    LocalM128 nn = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), n);
    _mm_store_ps(out.m128_f32, n);
    _mm_store_ps(out.m128_f32, nn);

    LocalM128 q = _mm_mul_ps(nn, p0);
    LocalM128 d = _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q));
    LocalM128 w = _mm_sub_ss(DAT_010c7160, d);

    float wf;
    _mm_store_ss(&wf, w);
    out.m128_f32[3] = wf;
}

class ScalarPlaneQ {
    LocalM128 value;
public:
    ScalarPlaneQ(const LocalM128& a):value(a){}
    ScalarPlaneQ(float a){value=_mm_load_ss(&a);}
    ScalarPlaneQ(){}
    operator float() const {float f;_mm_store_ss(&f,value);return f;}
    __forceinline const LocalM128& quad() const {return value;}
};
inline ScalarPlaneQ operator+(const ScalarPlaneQ& a,const ScalarPlaneQ& b){return _mm_add_ss(a.quad(),b.quad());}

struct PlaneTransformQ;
struct PlaneVectorQ {
    LocalM128 q;
    __forceinline void SetTransformedPoint(const PlaneTransformQ& t,const PlaneVectorQ& src);
    __forceinline void operator=(const PlaneVectorQ& a) { q=a.q; }
    __forceinline void setW(float w) { q.m128_f32[3]=w; }
    __forceinline ScalarPlaneQ dot(const PlaneVectorQ& point) const {
        LocalM128 product=_mm_mul_ps(q,point.q);
        LocalM128 xy=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
        return _mm_add_ss(_mm_shuffle_ps(product,product,0xaa),xy);
    }
    __forceinline ScalarPlaneQ lane(int i) const {
        switch(i) { case 0:return q;case 1:return _mm_shuffle_ps(q,q,0x55);case 2:return _mm_shuffle_ps(q,q,0xaa);
        default:return _mm_shuffle_ps(q,q,0xff); }
    }
};
struct PlaneVertexQ {
    PlaneVertexQ* next; int flag,unk08,unk0c;
    PlaneVectorQ position;
};
struct PlaneFaceQ {
    PlaneFaceQ* next; int unk04;
    PlaneVertexQ* vertices[3];
};
struct PlanePointsQ {
    PlaneVectorQ* data; int size; int capacityAndFlags;
    __forceinline int GetLogicalSize() const { return size; }
    __forceinline const PlaneVectorQ& operator[](int i) const { return data[i]; }
};
struct PlaneTransformQ { PlaneVectorQ rows[4]; };

__forceinline void PlaneVectorQ::SetTransformedPoint(const PlaneTransformQ& t,const PlaneVectorQ& src) {
    LocalM128 x=_mm_mul_ps(_mm_shuffle_ps(src.q,src.q,0),t.rows[0].q);
    LocalM128 y=_mm_mul_ps(_mm_shuffle_ps(src.q,src.q,0x55),t.rows[1].q);
    LocalM128 z=_mm_mul_ps(_mm_shuffle_ps(src.q,src.q,0xaa),t.rows[2].q);
    q=_mm_add_ps(_mm_add_ps(_mm_add_ps(x,y),z),t.rows[3].q);
}
struct PlaneHullQ {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    PlaneVertexQ* vertices; int numVertices,unk2c,unk30,unk34,unk38;
    PlaneFaceQ* faces;
    float ProcessEntries_00d7a810(const PlanePointsQ& points,const PlaneTransformQ& transform,PlaneVectorQ& out);
};
// @fnv 0x00d7a810
// src: GUESS 0x00d7a810 (confidence: low)
float PlaneHullQ::ProcessEntries_00d7a810(const PlanePointsQ& points,const PlaneTransformQ& transform,PlaneVectorQ& out) {
    float best=DAT_0104da4c;
    for(int i=0;i<points.GetLogicalSize();++i) {
        const PlaneVectorQ& point=points[i];
        for(PlaneFaceQ* face=faces;face;face=face->next) {
            PlaneVectorQ tp[3];
            for(int k=0;k<3;++k) tp[k].SetTransformedPoint(transform,face->vertices[k]->position);
            LocalM128 a=_mm_sub_ps(tp[1].q,tp[0].q);
            LocalM128 b=_mm_sub_ps(tp[2].q,tp[0].q);
            LocalM128 cross=_mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(b,b,0xd2),_mm_shuffle_ps(a,a,0xc9)),
                _mm_mul_ps(_mm_shuffle_ps(b,b,0xc9),_mm_shuffle_ps(a,a,0xd2)));
            LocalM128 s=_mm_mul_ps(cross,cross);
            LocalM128 len=_mm_add_ss(_mm_shuffle_ps(s,s,0xaa),_mm_add_ss(_mm_shuffle_ps(s,s,0x55),s));
            LocalM128 r=_mm_rsqrt_ss(len);
            LocalM128 three=_mm_set_ss(3.0f);
            LocalM128 half=_mm_set_ss(0.5f);
            LocalM128 zero=_mm_set_ss(0.0f);
            LocalM128 t=_mm_mul_ss(_mm_mul_ss(len,r),r);
            LocalM128 scale=_mm_mul_ss(_mm_mul_ss(half,r),_mm_sub_ss(three,t));
            scale=_mm_andnot_ps(_mm_cmpeq_ss(len,zero),scale);
            PlaneVectorQ plane;
            plane.q=_mm_mul_ps(_mm_shuffle_ps(scale,scale,0),cross);
            LocalM128 dp=_mm_mul_ps(plane.q,tp[0].q);
            LocalM128 d=_mm_add_ss(_mm_shuffle_ps(dp,dp,0xaa),_mm_add_ss(_mm_shuffle_ps(dp,dp,0x55),dp));
            float offset; _mm_store_ss(&offset,_mm_sub_ss(DAT_010c7160,d));
            plane.setW(offset);
            float support=plane.dot(point)+plane.lane(3);
            if(support>best) { best=support; out=plane; }
        }
    }
    return best;
}

namespace N {
typedef ::__m128 LocalM128;
extern "C" {
using ::_mm_add_ss;
using ::_mm_mul_ps;
using ::_mm_shuffle_ps;
using ::_mm_sqrt_ss;
using ::_mm_store_ss;
using ::_mm_sub_ps;
}
}
extern const char str_010d37a8[];
extern const char str_010d3574[];
struct S83_Vec4 {
    N::LocalM128 q;
    __forceinline void operator=(const S83_Vec4& v) { q = v.q; }
};
struct S83_Vertex {
    S83_Vertex* next;
    int unk04;
    int unk08;
    int unk0c;
    S83_Vec4 point;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int removalFlag;
};
struct S83_Tri {
    S83_Tri* next;
    int unk04;
    S83_Vertex* v[3];
};
struct S83_Options {
    int vertexLimit;
    unsigned char reseat;
    float tolerance;
    int unk0c;
    unsigned char rebuild;
    unsigned char modified;
};
struct S83_Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int bytes);

    template<class T> __forceinline void freeElements(void* p,int count) { ReturnMemory(p,count*sizeof(T)); }

};
static __forceinline S83_Alloc& S83_heap() { return *reinterpret_cast<S83_Alloc*>(hkMemoryRouter_getInstance()->heap()); }
struct S83_PlainElement {};
struct S83_ElementOps {
    template<class T> static __forceinline void create(T*,int,S83_PlainElement) {}
    template<class T> static __forceinline void discard(T*,int,S83_PlainElement) {}
    template<class T> static __forceinline void copy(T* dest,int count,const T& value,S83_PlainElement) {
        for(int i=0;i<count;++i) dest[i]=value;
    }
};
struct S83_HeapAccess {
    __forceinline S83_Alloc& get(const void*) { return S83_heap(); }
};
extern void __cdecl hkArrayUtil__reserve(S83_Alloc&,void*,int,int);
extern void __cdecl ResizeAudioStream(S83_Alloc&,void*,int);
template <class T> struct S83_ArrayBaseLocalForm { // local form of hkArrayBase: 0x00d83f30 needs the original constructor stores; shared base construction changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline S83_ArrayBaseLocalForm() : m_data(0),m_iElementCount(0),m_iCapacityState(0x80000000) {}
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void grow(S83_Alloc& heap,int required) {
        int oldCapacity=getCapacity();
        if(oldCapacity<required) {
            int doubled=oldCapacity*2;
            hkArrayUtil__reserve(heap,this,required<doubled?doubled:required,sizeof(T));
        }
    }
    __forceinline void resize(S83_Alloc& heap,int n) {
        grow(heap,n);
        S83_ElementOps::discard(m_data+n,m_iElementCount-n,S83_PlainElement());
        S83_ElementOps::create(m_data+m_iElementCount,n-m_iElementCount,S83_PlainElement());
        m_iElementCount=n;
    }
    __forceinline T* appendSpace(S83_Alloc& heap,int n) {
        int old=m_iElementCount;
        grow(heap,m_iElementCount+n);
        S83_ElementOps::create(m_data+m_iElementCount,n,S83_PlainElement());
        m_iElementCount+=n;
        return m_data+old;
    }
    __forceinline void append(S83_Alloc& heap,const T& value) {
        if(m_iElementCount==getCapacity()) ResizeAudioStream(heap,this,sizeof(T));
        S83_ElementOps::copy(m_data+m_iElementCount,1,value,S83_PlainElement());
        ++m_iElementCount;
    }
    __forceinline int indexOf(const T& v) const {
        for(int i=0;i<m_iElementCount;++i) if(m_data[i]==v) return i;
        return -1;
    }
    __forceinline void clear() {
        S83_ElementOps::discard(m_data,m_iElementCount,S83_PlainElement());
        m_iElementCount=0;
    }
    __forceinline void release(S83_Alloc& heap) {
        clear();
        if((m_iCapacityState & 0x80000000)==0) heap.freeElements<T>(m_data,getCapacity());
        m_data=0;
        m_iCapacityState=0x80000000;
    }
};
template<class T> struct S83_OwnedArray : S83_ArrayBaseLocalForm<T> {
    __forceinline S83_OwnedArray() : S83_ArrayBaseLocalForm<T>() {}
    __forceinline ~S83_OwnedArray() { clearAndFree(); }
    __forceinline void clearAndFree() { this->release(S83_HeapAccess().get(this)); }
    __forceinline void reserve(int n) { this->grow(S83_HeapAccess().get(this),n); }
    __forceinline void SetSizeAndGrow(int n) { this->resize(S83_HeapAccess().get(this),n); }
    __forceinline T* expandBy(int n) { return this->appendSpace(S83_HeapAccess().get(this),n); }
    __forceinline void AddBack(const T& v) { this->append(S83_HeapAccess().get(this),v); }
};
template<class T> struct S83_Array : S83_OwnedArray<T> {};
struct S83_Fmt {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(char* buffer, int capacity);
    S83_Fmt* ProcessAndReturnValue_00cc01c0(const char* text);
    S83_Fmt* ProcessAndReturnValue_00cc01c0(const char* text, int code, const char* tail);
    S83_Fmt* EvaluateValue_00cc02d0();
    void ProcessAndReturnValue_00cc01c0();
    void FUN_00cc00e0();
};
static __forceinline float S83_lenSq(const S83_Vertex* a, const S83_Vertex* b) {
    N::LocalM128 d = N::_mm_sub_ps(a->point.q, b->point.q);
    N::LocalM128 sq = N::_mm_mul_ps(d, d);
    N::LocalM128 y = N::_mm_shuffle_ps(sq, sq, 0x55);
    N::LocalM128 z = N::_mm_shuffle_ps(sq, sq, 0xaa);
    float f;
    N::_mm_store_ss(&f, N::_mm_add_ss(z, N::_mm_add_ss(y, sq)));
    return f;
}
static __forceinline float S83_area(const S83_Tri* t) {
    const N::LocalM128& p0 = t->v[0]->point.q;
    N::LocalM128 u = N::_mm_sub_ps(t->v[1]->point.q, p0);
    N::LocalM128 w = N::_mm_sub_ps(t->v[2]->point.q, p0);
    N::LocalM128 cr = N::_mm_sub_ps(N::_mm_mul_ps(N::_mm_shuffle_ps(w, w, 0xd2), N::_mm_shuffle_ps(u, u, 0xc9)),
                           N::_mm_mul_ps(N::_mm_shuffle_ps(w, w, 0xc9), N::_mm_shuffle_ps(u, u, 0xd2)));
    N::LocalM128 sq = N::_mm_mul_ps(cr, cr);
    N::LocalM128 y = N::_mm_shuffle_ps(sq, sq, 0x55);
    N::LocalM128 z = N::_mm_shuffle_ps(sq, sq, 0xaa);
    float f;
    N::_mm_store_ss(&f, N::_mm_sqrt_ss(N::_mm_add_ss(z, N::_mm_add_ss(y, sq))));
    return f;
}
struct S83_Mesh {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    S83_Vertex* vertices;
    int vertexCount;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    S83_Tri* triangles;
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
    int state;
    int unk1ac;
    int diagnosticCode;
    unsigned char flag1b4;
    unsigned char flag1b5;
    void ProcessEntries_00d83f30(S83_Options* options);
    void ProcessEntries_00d82ad0(int limit, bool reseat);
    int hkgpConvexHullImpl_build(const S83_Vec4* points, int numPoints, int a, int b);
    void ProcessEntries_00d7d2a0();
    void hkgpConvexHullImpl_buildMassProperties_hkgpConvexHullImpl_PositionAsTransform();
    void hkgpConvexHullImpl_generateIndexedFaces_int_int(S83_Array<int>* a, S83_Array<int>* b, int c, int d);
};
// @fnv 0x00d83f30
// src: GUESS 0x00d83f30 (confidence: low)
void S83_Mesh::ProcessEntries_00d83f30(S83_Options* options)
{
    unsigned char oldFlagA = flag1b4;
    unsigned char oldFlagB = flag1b5;
    bool changed = options->modified != 0;
    switch (state) {
    case 0:
    case 1:
    case 2:
        return;
    case 3:
        break;
    default: {
        int text[128];
        S83_Fmt fmt;
        fmt.FUN_00cb1600((char*)text, 0x200);
        fmt.ProcessAndReturnValue_00cc01c0(str_010d37a8);
        if (DAT_01268360->message(3, 0x3e0abbab, (char*)text, str_010d3540, 0x57b))
            fnv_Breakpoint();
        fmt.FUN_00cc00e0();
        return;
    }
    }
    if (options->vertexLimit >= 4) {
        int before = vertexCount;
        ProcessEntries_00d82ad0(options->vertexLimit, options->reseat != 0);
        changed = vertexCount != before;
    }
    if (options->tolerance > 0.0f) {
        float maxArea = options->tolerance + options->tolerance;
        bool again;
        do {
            again = false;
            S83_Tri* sel = 0;
            float value = maxArea;
            for (S83_Tri* t = triangles; t; t = t->next) {
                float area = S83_area(t);
                if (area < value) {
                    value = area;
                    sel = t;
                }
            }
            if (sel) {
            int longest = 0;
            value = S83_lenSq(sel->v[0], sel->v[1]);
            for (int i = 1; i < 3; i++) {
                float l = S83_lenSq(sel->v[i], sel->v[(i + 1) % 3]);
                if (l > value) {
                    value = l;
                    longest = i;
                }
            }
            if (longest == 0) sel->v[2]->removalFlag = -1;
            else if (longest == 1) sel->v[0]->removalFlag = -1;
            else sel->v[1]->removalFlag = -1;
            S83_Array<S83_Vec4> pts;
            pts.reserve(vertexCount);
            for (S83_Vertex* v = vertices; v; v = v->next) {
                if (v->removalFlag != -1)
                    pts.AddBack(v->point);
            }
            if (hkgpConvexHullImpl_build(pts.m_data, pts.m_iElementCount, 0, 0) == 3)
                ProcessEntries_00d7d2a0();
            changed = true;
            again = true;

            }
        } while (again && state == 3);
    }
    if (options->rebuild != 0 && state == 3) {
        if (!flag1b5) {
            int text[128];
            S83_Fmt fmt;
            fmt.FUN_00cb1600((char*)text, 0x200);
            fmt.ProcessAndReturnValue_00cc01c0(str_010d3574, diagnosticCode, &DAT_0103d078)->EvaluateValue_00cc02d0()->ProcessAndReturnValue_00cc01c0();
            if (DAT_01268360->message(3, 0x79f9d886, (char*)text, str_010d3540, 0x148))
                fnv_Breakpoint();
            fmt.FUN_00cc00e0();
        }
        S83_Array<int> a;
        S83_Array<int> b;
        S83_Array<int> used;
        do {
            a.m_iElementCount = 0;
            b.m_iElementCount = 0;
            used.m_iElementCount = 0;
            hkgpConvexHullImpl_generateIndexedFaces_int_int(&a, &b, 0, 0);
            for (int k = 0; k < b.m_iElementCount; k++) {
                if (used.indexOf(b.m_data[k]) == -1)
                    used.AddBack(b.m_data[k]);
            }
            if (used.m_iElementCount >= vertexCount) break;
            changed = true;
            S83_Array<S83_Vec4> all;
            S83_Array<S83_Vec4> sub;
            {
                int n = vertexCount;
                S83_Vec4* dst = all.expandBy(n);
                for (S83_Vertex* v = vertices; v; v = v->next)
                    *dst++ = v->point;
            }
            sub.SetSizeAndGrow(used.m_iElementCount);
            for (int i = 0; i < used.m_iElementCount; i++)
                sub.m_data[i] = all.m_data[used.m_data[i]];
            if (hkgpConvexHullImpl_build(sub.m_data, sub.m_iElementCount, 0, 0) == 3)
                ProcessEntries_00d7d2a0();


        } while (state == 3);



    }
    if (changed && state == 3) {
        S83_Array<S83_Vec4> all;
        S83_Vec4* dst = all.expandBy(vertexCount);
        for (S83_Vertex* v = vertices; v; v = v->next)
            *dst++ = v->point;
        hkgpConvexHullImpl_build(all.m_data, all.m_iElementCount, 0, 0);
        if (oldFlagB) ProcessEntries_00d7d2a0();
        if (oldFlagA) hkgpConvexHullImpl_buildMassProperties_hkgpConvexHullImpl_PositionAsTransform();

    }
}

extern "C" {
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_add_ss;
using ::_mm_sub_ss;
using ::_mm_mul_ss;
using ::_mm_cmpeq_ss;
using ::_mm_rsqrt_ss;
using ::_mm_andnot_ps;
using ::_mm_set_ss;
using ::_mm_store_ss;
}
extern const char str_010d36ec[];
extern const char str_010d3540[];
extern const LocalM128 DAT_010c7160;

struct S00d7fb80_Stream {
    int unk00;
    int unk04;
    int unk08;
    S00d7fb80_Stream* FUN_00cb1600(void* buf, int size);
    S00d7fb80_Stream& ProcessAndReturnValue_00cc01c0(const char* s);
    void FUN_00cc00e0();
};
class S00d7fb80_SimdReal {
public:
    __forceinline S00d7fb80_SimdReal(const LocalM128& x) : m_vValue(x) {}
    __forceinline operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const LocalM128& getQuad() const { return m_vValue; }
    LocalM128 m_vValue;
};
typedef const S00d7fb80_SimdReal& S00d7fb80_SimdParam;
__forceinline S00d7fb80_SimdReal operator-(S00d7fb80_SimdParam r)
{
    return _mm_sub_ss(DAT_010c7160, r.getQuad());
}


// Keep this variant local: the shared vector changes FUN_00d7fb80's generated bytes.
class __declspec(align(16)) S00d7fb80_Vector4 {
public:
    __forceinline void operator=(const S00d7fb80_Vector4& v) { m_vComponents = v.m_vComponents; }
    __forceinline float& operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
    __forceinline const float& operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
    __forceinline void set(float a, float b, float c, float d) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    __forceinline void mul4(const S00d7fb80_Vector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void add4(const S00d7fb80_Vector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const S00d7fb80_Vector4& a, const S00d7fb80_Vector4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setCross(const S00d7fb80_Vector4& v0, const S00d7fb80_Vector4& v1)
    {
        LocalM128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        LocalM128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline S00d7fb80_SimdReal dot3(const S00d7fb80_Vector4& a) const
    {
        LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00d7fb80_SimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline S00d7fb80_SimdReal lengthInverse3() const
    {
        const LocalM128 half = _mm_set_ss(0.5f);
        const LocalM128 three = _mm_set_ss(3.0f);
        const LocalM128 zero = _mm_set_ss(0.0f);
        const LocalM128 len2 = this->dot3(*this).getQuad();
        const LocalM128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const LocalM128 approx = _mm_rsqrt_ss(len2);
        const LocalM128 refined = _mm_mul_ss(
            _mm_mul_ss(half, approx),
            _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3()
    {
        LocalM128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    __forceinline static const S00d7fb80_Vector4& getZero() { return *reinterpret_cast<const S00d7fb80_Vector4*>(&DAT_01267e30); }
    LocalM128 m_vComponents;
};

__forceinline S00d7fb80_Vector4 S00d7fb80_crossOffset(const S00d7fb80_Vector4& a, const S00d7fb80_Vector4& b, const S00d7fb80_Vector4& c)
{
    S00d7fb80_Vector4 ab;
    ab.setSub4(b, a);
    S00d7fb80_Vector4 ac;
    ac.setSub4(c, a);
    S00d7fb80_Vector4 n;
    n.setCross(ab, ac);
    return n;
}
__forceinline S00d7fb80_Vector4 S00d7fb80_planeEquation(const S00d7fb80_Vector4& a, const S00d7fb80_Vector4& b, const S00d7fb80_Vector4& c, bool normalize)
{
    S00d7fb80_Vector4 n = S00d7fb80_crossOffset(a, b, c);
    if (normalize) {
        n.normalize3();
    }
    n(3) = -n.dot3(a);
    return n;
}

struct S00d7fb80_TypeIsClass {};
template <typename T> __forceinline void S00d7fb80_destruct(T* t, int n, S00d7fb80_TypeIsClass)
{
    for (int i = 0; i < n; ++i) {
        static_cast<T*>(t)[i].~T();
    }
}
template <unsigned int ELEMENTSIZE, unsigned int ALIGN>
__forceinline void S00d7fb80_memCpyOneAligned(void* dst, const void* src)
{
    typedef unsigned __int64 CopyType;
    unsigned int i = 0;
    do {
        static_cast<CopyType*>(dst)[i] = static_cast<const CopyType*>(src)[i];
    } while (++i < ELEMENTSIZE / sizeof(CopyType));
}

struct S00d7fb80_Allocator {
    virtual void vtbl00();
    virtual void vtbl04();
    virtual void vtbl08();
    virtual void vtbl0c();
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(T);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};
struct S00d7fb80_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d7fb80_Allocator* m_pStreamAllocator;
    __forceinline S00d7fb80_Allocator& heap() { return *m_pStreamAllocator; }
};
template <typename T>
class S00d7fb80_ArrayBaseLocalForm { // local form of hkArrayBase: 0x00d7fb80 needs the original constructor stores; shared base construction changes bytes.
public:
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline void clear() { S00d7fb80_destruct(m_data, m_iElementCount, S00d7fb80_TypeIsClass()); m_iElementCount = 0; }
    __forceinline void removeAt(int index)
    {
        S00d7fb80_destruct(&m_data[index], 1, S00d7fb80_TypeIsClass());
        m_iElementCount--;
        if (m_iElementCount != index) {
            S00d7fb80_memCpyOneAligned<sizeof(T), __alignof(T)>(m_data + index, m_data + m_iElementCount);
        }
    }
    __forceinline void popBack(int numElemsToRemove = 1)
    {
        S00d7fb80_destruct(m_data + m_iElementCount - numElemsToRemove, numElemsToRemove, S00d7fb80_TypeIsClass());
        m_iElementCount -= numElemsToRemove;
    }
    __forceinline void _clearAndDeallocate(S00d7fb80_Allocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct S00d7fb80_ContainerHeapAllocator {
    __forceinline S00d7fb80_Allocator& get(const void*) { return reinterpret_cast<S00d7fb80_Router&>(*hkMemoryRouter_getInstance()).heap(); }
};
template <typename T>
class S00d7fb80_Array : public S00d7fb80_ArrayBaseLocalForm<T> {
public:
    __forceinline void ClearAndRelease() { S00d7fb80_ArrayBaseLocalForm<T>::_clearAndDeallocate(S00d7fb80_ContainerHeapAllocator().get(this)); }
};

template <typename T>
struct S00d7fb80_Item {
    __forceinline S00d7fb80_Item() {}
    __forceinline S00d7fb80_Item(const S00d7fb80_Item& o) {}
    __forceinline S00d7fb80_Item& operator=(const S00d7fb80_Item& o) { return *this; }
    __forceinline T* next() const { return m_next; }
    T* m_next;
    T* m_pSecondNode;
};
struct S00d7fb80_Vertex : S00d7fb80_Item<S00d7fb80_Vertex> {
    __forceinline S00d7fb80_Vertex() { m_2c = 0.0f; m_uiEdgeIndex = -1; }
    S00d7fb80_Vector4 m_pObservedSource;
    int m_uiX[3];
    float m_2c;
    int m_refs;
    int m_uiEdgeIndex;
};
struct S00d7fb80_Plane {
    __forceinline S00d7fb80_Plane() { m_uiEdgeIndex = -1; }
    int m_uiX[3];
    __int64 m_offset;
    int m_uiEdgeIndex;
};
typedef unsigned long S00d7fb80_Uid;
struct S00d7fb80_Triangle;
template <typename VERTEX>
struct S00d7fb80_TriangleBase : S00d7fb80_Item<S00d7fb80_Triangle> {
    __forceinline VERTEX& vertex(int i) { return m_kVertices[i]; }
    __forceinline S00d7fb80_Uid& link(int i) { return m_ppLinks[i]; }
    VERTEX m_kVertices[3];
    S00d7fb80_Uid m_ppLinks[3];
};
struct S00d7fb80_Triangle : S00d7fb80_TriangleBase<S00d7fb80_Vertex*> {
    __forceinline S00d7fb80_Triangle() { m_uiEdgeIndex = -1; }
    __forceinline ~S00d7fb80_Triangle() {}
    S00d7fb80_Plane m_kTriangleNormal;
    int m_40;
    int m_uiEdgeIndex;
};
__forceinline S00d7fb80_Uid S00d7fb80_uid2ulong(void* t, unsigned int i) { return (*(const unsigned long*)&t) + (unsigned long)i; }
__forceinline S00d7fb80_Uid S00d7fb80_packUid(void* t, unsigned int i) { return S00d7fb80_uid2ulong(t, i); }
template <typename T>
__forceinline void S00d7fb80_ulong2uid(unsigned long uid, T*& t, unsigned int& i)
{
    i = (unsigned int)(uid & 3);
    uid &= ~3;
    t = *(T**)&uid;
}
template <typename T>
__forceinline void S00d7fb80_unpackUid(S00d7fb80_Uid uid, T*& t, unsigned int& i) { S00d7fb80_ulong2uid(uid, t, i); }

template <typename EDGE, typename VERTEX, typename TRIANGLE, typename VERTEX_MEMBER>
struct S00d7fb80_TopoEdge {
    static __forceinline unsigned ip1mod3(unsigned i) { return (0x09 >> (i << 1)) & 3; }
    __forceinline S00d7fb80_TopoEdge() {}
    __forceinline S00d7fb80_TopoEdge(TRIANGLE* t, unsigned i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    __forceinline S00d7fb80_TopoEdge(const S00d7fb80_Uid& id) { S00d7fb80_unpackUid(id, m_pkTriangle, m_uiEdgeIndex); }
    __forceinline EDGE next() const { return EDGE(m_pkTriangle, ip1mod3(m_uiEdgeIndex)); }
    __forceinline EDGE link() const { return EDGE(m_pkTriangle->link(m_uiEdgeIndex)); }
    __forceinline EDGE nextCcw() const { return link().next(); }
    __forceinline TRIANGLE* triangle() const { return m_pkTriangle; }
    __forceinline S00d7fb80_Uid uid() const { return S00d7fb80_packUid(m_pkTriangle, m_uiEdgeIndex); }
    __forceinline VERTEX_MEMBER& start() const { return m_pkTriangle->vertex(m_uiEdgeIndex); }
    __forceinline VERTEX_MEMBER& end() const { return m_pkTriangle->vertex(ip1mod3(m_uiEdgeIndex)); }
    __forceinline bool isValid() const { return triangle() != 0; }
    __forceinline bool isNaked() const { return !link().isValid(); }
    __forceinline void bind(const S00d7fb80_TopoEdge& edge) const
    {
        m_pkTriangle->link(m_uiEdgeIndex) = edge.uid();
        if (edge.isValid()) edge.m_pkTriangle->link(edge.m_uiEdgeIndex) = uid();
    }
    __forceinline bool operator!=(const EDGE& e) const { return uid() != e.uid(); }
    TRIANGLE* m_pkTriangle;
    unsigned int m_uiEdgeIndex;
};
struct S00d7fb80_Edge : S00d7fb80_TopoEdge<S00d7fb80_Edge, S00d7fb80_Vertex, S00d7fb80_Triangle, S00d7fb80_Vertex*> {
    typedef S00d7fb80_TopoEdge<S00d7fb80_Edge, S00d7fb80_Vertex, S00d7fb80_Triangle, S00d7fb80_Vertex*> tBase;
    __forceinline S00d7fb80_Edge(S00d7fb80_Triangle* t, int i) : tBase(t, i) {}
    __forceinline S00d7fb80_Edge(S00d7fb80_Uid id) : tBase(id) {}
};
struct S00d7fb80_VertexList {
    int unk00; int unk04; int unk08;
    S00d7fb80_Vertex* m_uiBufferCapacity;
    int m_iAllocatedCount; int unk14;
    S00d7fb80_Vertex* allocateItem();
    S00d7fb80_Vertex* CloneNode(const S00d7fb80_Vertex& v);
    __forceinline S00d7fb80_Vertex* allocate(const S00d7fb80_Vertex& v = S00d7fb80_Vertex()) { return CloneNode(v); }
};
struct S00d7fb80_TriangleList {
    int unk00; int unk04; int unk08;
    S00d7fb80_Triangle* m_uiBufferCapacity;
    int m_iAllocatedCount; int unk14;
    S00d7fb80_Triangle* allocateItem();
    S00d7fb80_Triangle* hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHull_Vertex_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Triangle_32_struct_hkContainerHeapAllocator_allocate(const S00d7fb80_Triangle& t);
    __forceinline S00d7fb80_Triangle* allocate(const S00d7fb80_Triangle& t = S00d7fb80_Triangle()) { return hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHull_Vertex_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Triangle_32_struct_hkContainerHeapAllocator_allocate(t); }
    __forceinline S00d7fb80_Triangle* getFirst() const { return m_uiBufferCapacity; }
};
__forceinline void* operator new(unsigned int, S00d7fb80_Vertex* p) throw() { return p; }
__forceinline void* operator new(unsigned int, S00d7fb80_Triangle* p) throw() { return p; }

__declspec(noinline) S00d7fb80_Vertex* S00d7fb80_VertexList::CloneNode(const S00d7fb80_Vertex& v)
{
    S00d7fb80_Vertex* item = new (allocateItem()) S00d7fb80_Vertex(v);
    item->m_pSecondNode = 0;
    item->m_next = m_uiBufferCapacity;
    if (m_uiBufferCapacity) m_uiBufferCapacity->m_pSecondNode = item;
    m_uiBufferCapacity = item;
    m_iAllocatedCount++;
    return item;
}
// src: HAVOK_LIB 0x00d7efc0
__declspec(noinline) S00d7fb80_Triangle* S00d7fb80_TriangleList::hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHull_Vertex_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Triangle_32_struct_hkContainerHeapAllocator_allocate(const S00d7fb80_Triangle& t)
{
    S00d7fb80_Triangle* item = new (allocateItem()) S00d7fb80_Triangle(t);
    item->m_pSecondNode = 0;
    item->m_next = m_uiBufferCapacity;
    if (m_uiBufferCapacity) m_uiBufferCapacity->m_pSecondNode = item;
    m_uiBufferCapacity = item;
    m_iAllocatedCount++;
    return item;
}
struct S00d7fb80_Bool {
    char m_cBooleanValue;
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
};
template <typename T> __forceinline void S00d7fb80_swap(T& x, T& y) { T t(x); x = y; y = t; }

class __declspec(align(16)) S00d7fb80_Hull {
public:
    S00d7fb80_Bool m_bFlagAtOffset00;
    char unk01; char unk02; char unk03;
    int unk04; int unk08; int unk0c; int unk10; int unk14;
    S00d7fb80_VertexList m_meshVertices;
    S00d7fb80_TriangleList m_meshTriangles;
    S00d7fb80_Array<S00d7fb80_Vertex> m_kVertices;
    int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc;
    S00d7fb80_Vector4 m_kVectorAtOffsetE0;
    S00d7fb80_Vector4 m_domainCenter;
    S00d7fb80_Vector4 m_domainScale;
    S00d7fb80_Vector4 m_domainScaleInv;
    int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4;
    int m_eVertexFloatDimensions;
    int m_uiUniqueId;

    bool hkgpConvexHullImpl_flushPending();
    void hkgpConvexHullImpl_clearHorizon(const S00d7fb80_Vertex& v, const S00d7fb80_Edge& edge, S00d7fb80_Edge& out);

    template <typename T> static __forceinline T mul_32x32(int a, int b) { return (T)a * (T)b; }
    static __forceinline __int64 distanceToPlane(const S00d7fb80_Vertex& v, const S00d7fb80_Plane& p)
    {
        return mul_32x32<__int64>(v.m_uiX[0], p.m_uiX[0]) + mul_32x32<__int64>(v.m_uiX[1], p.m_uiX[1]) + mul_32x32<__int64>(v.m_uiX[2], p.m_uiX[2]) + p.m_offset;
    }
    static __forceinline bool makePlane(const S00d7fb80_Vertex& a, const S00d7fb80_Vertex& b, const S00d7fb80_Vertex& c, S00d7fb80_Plane& plane)
    {
        int ab[3]; ab[0] = b.m_uiX[0] - a.m_uiX[0]; ab[1] = b.m_uiX[1] - a.m_uiX[1]; ab[2] = b.m_uiX[2] - a.m_uiX[2];
        int ac[3]; ac[0] = c.m_uiX[0] - a.m_uiX[0]; ac[1] = c.m_uiX[1] - a.m_uiX[1]; ac[2] = c.m_uiX[2] - a.m_uiX[2];
        plane.m_uiX[0] = ab[1] * ac[2] - ab[2] * ac[1];
        plane.m_uiX[1] = ab[2] * ac[0] - ab[0] * ac[2];
        plane.m_uiX[2] = ab[0] * ac[1] - ab[1] * ac[0];
        plane.m_offset = 0;
        if (plane.m_uiX[0] | plane.m_uiX[1] | plane.m_uiX[2]) {
            plane.m_offset = -distanceToPlane(a, plane);
            return true;
        }
        return false;
    }
    static __forceinline bool makeTriangle(S00d7fb80_Vertex* a, S00d7fb80_Vertex* b, S00d7fb80_Vertex* c, S00d7fb80_Triangle* t)
    {
        t->vertex(0) = a;
        t->vertex(1) = b;
        t->vertex(2) = c;
        t->m_40 = 0;
        t->m_uiEdgeIndex = -1;
        a->m_refs++;
        b->m_refs++;
        c->m_refs++;
        return makePlane(*a, *b, *c, t->m_kTriangleNormal);
    }
    static __forceinline void makeVertex(const S00d7fb80_Vertex& v, S00d7fb80_Vertex* dst)
    {
        *dst = v;
        dst->m_refs = 0;
    }
    __forceinline S00d7fb80_Vector4 transform(const S00d7fb80_Vertex& v) const
    {
        S00d7fb80_Vector4 x;
        x.set((float)v.m_uiX[0], (float)v.m_uiX[1], (float)v.m_uiX[2], 0.0f);
        x.mul4(m_domainScaleInv);
        x.add4(m_domainCenter);
        return x;
    }
    __forceinline S00d7fb80_Triangle* locateBoundaryExhaustive(const S00d7fb80_Vertex& x) const
    {
        for (S00d7fb80_Triangle* t = m_meshTriangles.getFirst(); t; t = t->next()) {
            const __int64 d = distanceToPlane(x, t->m_kTriangleNormal);
            if (d > 0) {
                return t;
            }
        }
        return 0;
    }
    static __forceinline S00d7fb80_Edge nextHorizon(const S00d7fb80_Edge& edge)
    {
        S00d7fb80_Edge e = edge.next();
        while (!e.isNaked()) {
            e = e.nextCcw();
        }
        return e;
    }
    __forceinline bool insert(const S00d7fb80_Vertex& x)
    {
        S00d7fb80_Triangle* root = locateBoundaryExhaustive(x);
        if (root) {
            S00d7fb80_Vertex* newVertex = m_meshVertices.allocate();
            S00d7fb80_Edge edge(0, 0);
            makeVertex(x, newVertex);
            m_uiUniqueId++;
            hkgpConvexHullImpl_clearHorizon(*newVertex, S00d7fb80_Edge(root, 0), edge);
            while (!edge.isNaked()) {
                edge = edge.next();
            }
            const S00d7fb80_Edge first = edge;
            S00d7fb80_Triangle* firstT = 0;
            S00d7fb80_Triangle* lastT = 0;
            while (first != (edge = nextHorizon(edge))) {
                S00d7fb80_Triangle* t = m_meshTriangles.allocate();
                makeTriangle(newVertex, edge.end(), edge.start(), t);
                edge.bind(S00d7fb80_Edge(t, 1));
                if (lastT) {
                    S00d7fb80_Edge(lastT, 0).bind(S00d7fb80_Edge(t, 2));
                } else {
                    firstT = t;
                }
                lastT = t;
            }
            while (edge != first) {
            }
            S00d7fb80_Triangle* t = m_meshTriangles.allocate();
            makeTriangle(newVertex, edge.end(), edge.start(), t);
            edge.bind(S00d7fb80_Edge(t, 1));
            S00d7fb80_Edge(lastT, 0).bind(S00d7fb80_Edge(t, 2));
            S00d7fb80_Edge(t, 0).bind(S00d7fb80_Edge(firstT, 2));
            return true;
        }
        return false;
    }
};

// @fnv 0x00d7fb80
// src: XBOX_PDB 0x00d7fb80
bool S00d7fb80_Hull::hkgpConvexHullImpl_flushPending()
{
    const int numVertices = m_kVertices.GetLogicalSize();
    bool result = false;
    if (numVertices < 4) {
        char buffer[512];
        S00d7fb80_Stream ostr;
        ostr.FUN_00cb1600(buffer, 512);
        ostr.ProcessAndReturnValue_00cc01c0(str_010d36ec);
        if (DAT_01268360->message(3, 0x642cf968, buffer, str_010d3540, 0x2f4))
            fnv_Breakpoint();
        ostr.FUN_00cc00e0();
    }
    m_kVectorAtOffsetE0 = S00d7fb80_Vector4::getZero();
    for (int i = 0; i < numVertices; ++i) {
        S00d7fb80_Vertex a = m_kVertices[i];
        for (int j = i + 1; j < numVertices; ++j) {
            const S00d7fb80_Vertex& b = m_kVertices[j];
            for (int k = j + 1; k < numVertices; ++k) {
                const S00d7fb80_Vertex& c = m_kVertices[k];
                S00d7fb80_Plane plane;
                if (makePlane(a, b, c, plane)) {
                    if (m_bFlagAtOffset00) {
                        const S00d7fb80_Vector4 eq = S00d7fb80_planeEquation(transform(a), transform(b), transform(c), true);
                        if (eq.lengthSquared3() > m_kVectorAtOffsetE0.lengthSquared3()) {
                            m_kVectorAtOffsetE0 = eq;
                        }
                    }
                    for (int l = k + 1; l < numVertices; ++l) {
                        const __int64 d = distanceToPlane(m_kVertices[l], plane);
                        if (d != 0) {
                            S00d7fb80_Vertex* v[4];
                            v[0] = m_meshVertices.allocate();
                            v[1] = m_meshVertices.allocate();
                            v[2] = m_meshVertices.allocate();
                            v[3] = m_meshVertices.allocate();
                            makeVertex(m_kVertices[i], v[0]);
                            makeVertex(m_kVertices[j], v[1]);
                            makeVertex(m_kVertices[k], v[2]);
                            makeVertex(m_kVertices[l], v[3]);
                            if (d > 0) {
                                S00d7fb80_swap(v[0], v[1]);
                            }
                            S00d7fb80_Triangle* t[4] = { m_meshTriangles.allocate(), m_meshTriangles.allocate(), m_meshTriangles.allocate(), m_meshTriangles.allocate() };
                            makeTriangle(v[0], v[1], v[2], t[0]);
                            makeTriangle(v[0], v[3], v[1], t[1]);
                            makeTriangle(v[0], v[2], v[3], t[2]);
                            makeTriangle(v[1], v[3], v[2], t[3]);
                            S00d7fb80_Edge(t[0], 0).bind(S00d7fb80_Edge(t[1], 2));
                            S00d7fb80_Edge(t[0], 1).bind(S00d7fb80_Edge(t[3], 2));
                            S00d7fb80_Edge(t[0], 2).bind(S00d7fb80_Edge(t[2], 0));
                            S00d7fb80_Edge(t[1], 0).bind(S00d7fb80_Edge(t[2], 2));
                            S00d7fb80_Edge(t[2], 1).bind(S00d7fb80_Edge(t[3], 1));
                            S00d7fb80_Edge(t[3], 0).bind(S00d7fb80_Edge(t[1], 1));
                            m_kVertices.removeAt(l);
                            m_kVertices.removeAt(k);
                            m_kVertices.removeAt(j);
                            m_kVertices.removeAt(i);
                            i = j = k = l = numVertices;
                            result = true;
                        }
                    }
                }
            }
        }
    }
    if (result) {
        while (m_kVertices.GetLogicalSize() > 0) {
            const S00d7fb80_Vertex& back = m_kVertices[m_kVertices.GetLogicalSize() - 1];
            insert(back);
            m_kVertices.popBack(1);
        }
        m_kVertices.ClearAndRelease();
    }
    return result;
}

extern "C" {
using ::_mm_sub_ps;
using ::_mm_add_ps;
using ::_mm_mul_ps;
using ::_mm_add_ss;
using ::_mm_sub_ss;
using ::_mm_mul_ss;
using ::_mm_shuffle_ps;
using ::_mm_rsqrt_ss;
using ::_mm_cmpeq_ss;
using ::_mm_andnot_ps;
using ::_mm_setzero_ps;
using ::_mm_set_ss;
using ::_mm_load_ss;
using ::_mm_store_ss;
double fabs(double);
void* memcpy(void*,const void*,unsigned int);
}
extern const float DAT_010141cc;
extern const float s_faderClearedAlpha;
extern const char str_010d3748[];
extern const char str_010d3540[];

static __forceinline float expandAbs(float f) { return fabs(f); }
class ExpandTruth {
    char value;
public:
    __forceinline ExpandTruth() {}
    __forceinline ExpandTruth(bool b) { value=static_cast<char>(b); }
    __forceinline operator bool() const { return value!=0; }
    __forceinline ExpandTruth& operator=(bool b) { value=static_cast<char>(b);return *this; }
    __forceinline ExpandTruth operator==(bool b) const { return (int)value==(int)b; }
    __forceinline ExpandTruth operator!=(bool b) const { return (int)value!=(int)b; }
};
struct ExpandScalar {
    LocalM128 q;
    __forceinline ExpandScalar(const float& f) : q(_mm_load_ss(&f)) {}
    __forceinline ExpandScalar(LocalM128 v) : q(v) {}
};
struct __declspec(align(16)) ExpandVector {
    union { LocalM128 q; struct { int x,y,z,w; } bits; };
    __forceinline void assign(const ExpandVector& v) { q=v.q; }
    __forceinline float& operator[](int i) { return q.m128_f32[i]; }
    __forceinline const float& operator[](int i) const { return q.m128_f32[i]; }
    __forceinline void setZero() { q=_mm_setzero_ps(); }
    __forceinline void setSub(const ExpandVector& a,const ExpandVector& b) { q=_mm_sub_ps(a.q,b.q); }
    __forceinline void setAdd(const ExpandVector& a,const ExpandVector& b) { q=_mm_add_ps(a.q,b.q); }
    __forceinline void setAddMul(const ExpandVector& a,const ExpandVector& b,const ExpandScalar& s) {
        LocalM128 mul=_mm_mul_ps(_mm_shuffle_ps(s.q,s.q,0),b.q);
        q=_mm_add_ps(mul,a.q);
    }
    __forceinline void setCross(const ExpandVector& a,const ExpandVector& b) {
        LocalM128 t0=_mm_mul_ps(_mm_shuffle_ps(b.q,b.q,0xc9),_mm_shuffle_ps(a.q,a.q,0xd2));
        LocalM128 t1=_mm_mul_ps(_mm_shuffle_ps(b.q,b.q,0xd2),_mm_shuffle_ps(a.q,a.q,0xc9));
        q=_mm_sub_ps(t1,t0);
    }
    __forceinline void normalize3() {
        LocalM128 sq=_mm_mul_ps(q,q);
        LocalM128 len=_mm_add_ss(_mm_shuffle_ps(sq,sq,0xaa),_mm_add_ss(_mm_shuffle_ps(sq,sq,0x55),sq));
        LocalM128 r=_mm_rsqrt_ss(len);
        LocalM128 zero=_mm_set_ss(DAT_01011d78);
        LocalM128 three=_mm_set_ss(DAT_01017718);
        LocalM128 half=_mm_set_ss(DAT_01016248);
        LocalM128 rr=_mm_mul_ss(len,r); rr=_mm_mul_ss(rr,r);
        LocalM128 nr=_mm_mul_ss(_mm_mul_ss(half,r),_mm_sub_ss(three,rr));
        LocalM128 inv=_mm_andnot_ps(_mm_cmpeq_ss(len,zero),nr);
        q=_mm_mul_ps(_mm_shuffle_ps(inv,inv,0),q);
    }
    __forceinline void mul(const ExpandScalar& s) { q=_mm_mul_ps(q,_mm_shuffle_ps(s.q,s.q,0)); }
    unsigned char* FUN_00c7f520(unsigned char*,float) const;
};
static __forceinline void makeSide(const ExpandVector& input,ExpandVector& output) {
    int least=0,first=1,second=2;
    float ax=expandAbs(input[0]);
    float ay=expandAbs(input[1]);
    float az=expandAbs(input[2]);
    if(ay<ax) { first=0;least=1;ax=ay; }
    if(az<ax) { second=least;least=2; }
    output.setZero();output[first]=input[second];output[second]=-input[first];
}

struct ExpandHeap {
    virtual void unknown0();
    virtual void unknown4();
    virtual void unknown8();
    virtual void unknownC();
    virtual void ReturnMemory(void*,int);
};
struct ExpandRouter {
    int unk00,unk04,unk08,unk0c;
    ExpandHeap* heap;
    static ExpandRouter* hkMemoryRouter_getInstance();
};
struct ExpandArray {
    ExpandVector* data;
    int size;
    int capacity;
    __forceinline void init() {data=0;size=0;capacity=0x80000000;}
    __forceinline void clearAndFree() {
        ExpandHeap& heap=(ExpandHeap&)fnvc_adapt::hkMemoryRouter_getInstance().heap();
        size=0;
        if ((capacity&0x80000000)==0) heap.ReturnMemory(data,(capacity&0x3fffffff)*sizeof(ExpandVector));
    }
    __forceinline void reserve(int n) {
        D76250Allocator& heap=fnvc_adapt::hkMemoryRouter_getInstance().heap();
        const int cap=capacity&0x3fffffff;
        if (cap<n) {
            int twice=cap*2;
            int newSize=n<twice?twice:n;
            hkArrayUtil__reserve(&heap,this,newSize,sizeof(ExpandVector));
        }
    }
    __forceinline void SetSizeAndGrow(int n,const ExpandVector& value) {
        reserve(n);
        int count=n-size;
        ExpandVector* p=&data[size];
        for (int i=0;i<count;++i) p[i].assign(value);
        size=n;
    }
    __forceinline ExpandVector& AllocatePair() {
        D76250MemoryRouter& router=fnvc_adapt::hkMemoryRouter_getInstance();
        if (size==(capacity&0x3fffffff)) ResizeAudioStream((void*)&router.heap(),this,sizeof(ExpandVector));
        return data[size++];
    }
    __forceinline void AddBack(const ExpandVector& value) {
        D76250MemoryRouter& router=fnvc_adapt::hkMemoryRouter_getInstance();
        if (size==(capacity&0x3fffffff)) ResizeAudioStream((void*)&router.heap(),this,sizeof(ExpandVector));
        ExpandVector* p=data+size;
        for(int i=0;i<1;++i) p[i].assign(value);
        ++size;
    }
};
struct __declspec(align(16)) ExpandHeader { int a,b,c,d; };
struct ExpandBool { unsigned char value; };
struct ExpandPointNode {
    int unk00,unk04,unk08,unk0c;
    ExpandVector point;
};
struct ExpandState {
    ExpandHeader header;
    int unk10,unk14,unk18,unk1c,unk20;
    ExpandPointNode* first;
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
    ExpandVector normal;
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
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int dimension;
    int unk1ac,unk1b0;
    bool flagA,flagB;
    int hkgpConvexHullImpl_build(const ExpandVector*,int,int,int);
};
struct ExpandView {
    const ExpandVector* data;
    int size;
    int stride;
    __forceinline void set(const ExpandArray& a) { data=a.data;size=a.size;stride=16; }
};
struct ExpandStream {
    int unk00,unk04,unk08;
    void FUN_00cb1600(char*,int);
    void ProcessAndReturnValue_00cc01c0(const char*);
    void FUN_00cc00e0();
};
struct ExpandValidity { int unk00,unk04,unk08; unsigned char unk0c,unk0d,unk0e,valid; };
union ExpandAV { ExpandArray points; ExpandStream stream; ExpandValidity validity; };
struct ExpandShape {
    int unk00,unk04;
    ExpandState* state;
    __declspec(noinline) int GetInnerField1A8();
    const ExpandVector& ForwardCall_00d752d0() const;
    __declspec(noinline) void GetValueBlock(ExpandVector*) const;
    int EvaluateValue_00d75050() const;
    int GetUnk24_00d75060() const;
    const ExpandVector& Hkgpconvexhull_GetPayloadAddress(int) const;
    __declspec(noinline) int Object_ReadPointedValue_00d75120(int) const;
    int EvaluateValue_00d75130() const;
    int ComputeValue_00d75140() const;
    int Object_ReadPointedValue_00d75200(int) const;
    void UpdateFields_00d75b80(ExpandVector*,int) const;
    int hkgpConvexHull_getVertex(int,int) const;
    void ProcessState_00d76120(int,ExpandArray&) const;
    __declspec(noinline) int hkgpConvexHull_build(const ExpandVector*,int,const ExpandHeader&);
    __declspec(noinline) int hkgpConvexHull_build_00d77200(const ExpandView&,const ExpandHeader&);
    void SetValue(float,bool);
    void ForwardCall_00d762f0();
    bool hkgpConvexHull_expandByPlanarMargin(float radius);
};
// src: GUESS 0x00d74e10 (confidence: medium)
__declspec(noinline) int ExpandShape::GetInnerField1A8() { return state->dimension; }
__declspec(noinline) void ExpandShape::GetValueBlock(ExpandVector* out) const {
    memcpy(out,&state->normal,sizeof(*out));
}
// src: HAVOK_LIB 0x00d771c0
__declspec(noinline) int ExpandShape::hkgpConvexHull_build(const ExpandVector* vertices,int count,const ExpandHeader& header) {
    state->header=header;
    return state->hkgpConvexHullImpl_build(vertices,count,0,0);
}
// src: COMMUNITY 0x00d77200
__declspec(noinline) int ExpandShape::hkgpConvexHull_build_00d77200(const ExpandView& view,const ExpandHeader& header) {
    if (view.stride==16) return hkgpConvexHull_build(view.data,view.size,header);
    ExpandArray vertices; vertices.init();
    vertices.reserve(view.size);
    vertices.size=view.size;
    const char* src=(const char*)view.data;
    for (int i=0;i<view.size;++i) {
        ExpandVector& dst=vertices.data[i];
        const ExpandVector& v=*(const ExpandVector*)src;
        dst.q=_mm_setr_ps(v[0],v[1],v[2],0.0f);
        src+=view.stride;
    }
    int result=hkgpConvexHull_build(vertices.data,vertices.size,header); vertices.clearAndFree(); return result;
}
// src: GUESS 0x00d75120 (confidence: low)
__declspec(noinline) int ExpandShape::Object_ReadPointedValue_00d75120(int v) const { return *(const int*)v; }
// @fnv 0x00d77be0
// src: XBOX_PDB 0x00d77be0
bool ExpandShape::hkgpConvexHull_expandByPlanarMargin(float radius)
{
    float halfRadius=radius*0.5;
    ExpandState* source=state;
    ExpandHeader saved=source->header;
    struct __declspec(align(2)) { ExpandTruth flagB, flagA; } flags; flags.flagB=state->flagB;
    flags.flagA=state->flagA;
    __declspec(align(8)) ExpandAV av;
    switch (GetInnerField1A8()) {
    case 0: {
        ExpandArray& points=av.points; points.init();
        ExpandVector seed;
        seed.bits.x=source->first->point.bits.x;
seed.bits.y=source->first->point.bits.y;
seed.bits.z=source->first->point.bits.z;
seed.bits.w=source->first->point.bits.w;
        points.SetSizeAndGrow(6,seed);
        points.data[0][0]+=halfRadius;
        points.data[1][0]-=halfRadius;
        points.data[2][1]+=halfRadius;
        points.data[3][1]-=halfRadius;
        points.data[4][2]+=halfRadius;
        points.data[5][2]-=halfRadius;
        ExpandView view; view.set(points);
        hkgpConvexHull_build_00d77200(view,saved);
        points.clearAndFree();
        break;
    }
    case 1: {
        ExpandArray& points=av.points; points.init();
        points.reserve(10);
        ProcessState_00d76120(0,points);
        {
        ExpandVector a=points.data[0];
        ExpandVector b=points.data[1];
        ExpandVector delta;
        delta.setSub(b,a);
        ExpandVector perpendicular;
        makeSide(delta,perpendicular);
        ExpandVector cross;
        cross.setCross(delta,perpendicular);
        perpendicular.normalize3();
        perpendicular.mul(ExpandScalar(halfRadius));
        cross.normalize3();
        cross.mul(ExpandScalar(halfRadius));
        points.AllocatePair().setAdd(perpendicular,a);
        points.AllocatePair().setSub(a,perpendicular);
        points.AllocatePair().setAdd(cross,a);
        points.AllocatePair().setSub(a,cross);
        points.AllocatePair().setAdd(perpendicular,b);
        points.AllocatePair().setSub(b,perpendicular);
        points.AllocatePair().setAdd(cross,b);
        points.AllocatePair().setSub(b,cross);
        }
        ExpandView view; view.set(points);
        hkgpConvexHull_build_00d77200(view,saved);
        points.clearAndFree();
        break;
    }
    case 2: {
        ExpandArray& points=av.points; points.init();
        ExpandVector seed=ForwardCall_00d752d0();
        ExpandVector normal;
        GetValueBlock(&normal);
        points.reserve(3*EvaluateValue_00d75050());
        ProcessState_00d76120(0,points);
        for (int v=GetUnk24_00d75060();v;v=Object_ReadPointedValue_00d75120(v)) {
            const ExpandVector* position=&Hkgpconvexhull_GetPayloadAddress(v);
            const ExpandVector& pos=*position;
            points.AllocatePair().setAddMul(pos,normal,ExpandScalar(radius));
            points.AllocatePair().setAddMul(pos,normal,ExpandScalar(-radius));
        }
        ExpandView view; view.set(points);
        if (hkgpConvexHull_build_00d77200(view,saved)!=3) {
            points.size=0;
            points.AddBack(seed);
            view.set(points);
            hkgpConvexHull_build_00d77200(view,saved);
            bool result=hkgpConvexHull_expandByPlanarMargin(radius); points.clearAndFree(); return result;
        }
        points.clearAndFree();
        break;
    }
    case 3: {
        ExpandArray& points=av.points; points.init();
        points.reserve(6*EvaluateValue_00d75130());
        ProcessState_00d76120(0,points);
        for (int f=ComputeValue_00d75140();f;f=Object_ReadPointedValue_00d75200(f)) {
            ExpandVector plane;
            UpdateFields_00d75b80(&plane,f);
            
            if (*(unsigned char*)plane.FUN_00c7f520(&av.validity.valid,DAT_010141cc)) {
                for (int i=0;i<3;++i) {
                    const ExpandVector& pos=Hkgpconvexhull_GetPayloadAddress(hkgpConvexHull_getVertex(f,i));
                    points.AllocatePair().setAddMul(pos,plane,ExpandScalar(radius));
                }
            }
        }
        ExpandView view; view.set(points);
        hkgpConvexHull_build_00d77200(view,saved);
        points.clearAndFree();
        break;
    }
    default: {
        do {
        char buffer[512];
        ExpandStream& stream=av.stream;
        stream.FUN_00cb1600(buffer,512);
        stream.ProcessAndReturnValue_00cc01c0("Invalid dimemsions for that operation");
        if (DAT_01268360->message(3,0x172cdf48,buffer,".\\GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp",0xa77)) __debugbreak();
        stream.FUN_00cc00e0();
        } while(0);
        break;
    }
    }
    if (GetInnerField1A8()==3) {
        if (flags.flagB) SetValue(s_faderClearedAlpha,false);
        if (flags.flagA) ForwardCall_00d762f0();
        return true;
    }
    return false;
}
