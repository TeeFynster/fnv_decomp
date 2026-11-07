#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// havok/common/internal/geometryprocessing/convexhull/hkgpconvexhull.cpp: hkVector4, hkMatrix3, hkTransform, Owner and more (89 functions)

#include "fnv_asm_helpers.h"
#include "../../../../../../include/hkTypeIsClass.h"
// QueuedElements_hkgpconvexhull: local type (was include/QueuedElements.h, which had no evidence of one real class); no method of it is bound to a named game function
class QueuedElements_hkgpconvexhull
{
public:
    void** m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/Data.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkErrStream.h"
#include "../../../../../../include/hkError.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkSingleton.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/NiPoint3.h"
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkOstream.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkQuaternion.h"
// Preserve the non-throwing router lookup used by this unit's array cleanup.
hkMemoryRouter& __cdecl getHavokMonitorStream() throw();
inline void* __cdecl hkErrStream::operator new(std::size_t, void* p) { return p; }
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

// @fnv 0x00d74dd0
// src: HAVOK_LIB 0x00d74dd0
void FUN_00d74dd0_Class::hkgpConvexHull_deleteUserObject()
{
    if (m_10) {
        (*(void (__thiscall*)(void*, int))(*reinterpret_cast<void***>(*reinterpret_cast<void****>(m_10))))(m_10, 1);
    }
    m_10 = 0;
}

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
// @fnv 0x00d75850
// src: HAVOK_LIB 0x00d75850
void FUN_00d75850_class::hkgpConvexHull_reset()
{
    m2->hkgpConvexHullImpl_reset(0);
    if (m4) {
        void (__thiscall *fn)(int, int) = *(void (__thiscall **)(int, int))*reinterpret_cast<void (__thiscall **)(int, int)>(m4);
        fn(m4, 1);
    }
    m4 = 0;
}

// @fnv 0x00d76300
// src: HAVOK_LIB 0x00d76300
int __stdcall hkgpConvexHull_getNeighbour(const int* pValues, int iIndex)
{
    return (pValues[iIndex + 5] & ~3);
}

struct FUN_00d7c200_cls { void __thiscall FreeAll(); };
void __fastcall FlushQueuedElements(QueuedElements_hkgpconvexhull* self);
struct FUN_00d7c950_cls {
    void __thiscall ProcessState_00d7c950();
};
// @fnv 0x00d7c950
// src: GUESS 0x00d7c950 (confidence: low)
void __thiscall FUN_00d7c950_cls::ProcessState_00d7c950()
{
    ((FUN_00d7c200_cls*)((char*)this + 8))->FreeAll();
    FlushQueuedElements((QueuedElements_hkgpconvexhull*)((char*)this + 0x20));
}

// @fnv 0x00d752c0
// src: HAVOK_LIB 0x00d752c0
int __stdcall hkgpConvexHull_getVertex(int* arr, int idx)
{
    return *(int*)((char*)arr + idx * 4 + 8);
}

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
// @fnv 0x00d74df0
// src: GUESS 0x00d74df0 (confidence: medium)
int CpuObject::GetNestedValue()
{
    return value->value;
}

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

// Returns the ValueBlock stored in the object's Implementation.
// @fnv 0x00d74e50
ValueBlock FUN_00d74e50_cls::GetValueBlock()
{
    return m_pImpl->m_kValue;
}

struct PayloadOwner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iPayload;
};

// @fnv 0x00d74ed0
// src: GUESS 0x00d74ed0 (confidence: high)
int* __stdcall Hkgpconvexhull_GetPayloadAddress(PayloadOwner* apOwner)
{
    return &apOwner->m_iPayload;
}

struct TargetCallee {
    void ProcessEntries_00d7a5a0(void* p1, void* p2, void* p3, void* p4, float p5);
};

struct FUN_00d74ee0_Class : FUN_00d74dd0_Class {
    void ForwardToCallee(void* p1, void* p2, void* p3, void* p4, float p5);
};

// Forwards the five arguments to the callee stored at m_08 via FUN_00d7a5a0.
// @fnv 0x00d74ee0
void FUN_00d74ee0_Class::ForwardToCallee(void* p1, void* p2, void* p3, void* p4, float p5) {
    ((TargetCallee*)m_08)->ProcessEntries_00d7a5a0(p1, p2, p3, p4, p5);
}

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

// @fnv 0x00d75060
// src: GUESS 0x00d75060 (confidence: low)
int D75060Outer::GetUnk24_00d75060()
{
    return unk08->unk24;
}

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

extern hkError* DAT_01268360;
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

// @fnv 0x00d75070
// src: HAVOK_LIB 0x00d75070
int Owner::hkgpConvexHull_getIndex(Request* request) {
    unsigned int textStorage[sizeof(hkErrStream) / sizeof(unsigned int) + 128];
    hkErrStream& text = *reinterpret_cast<hkErrStream*>(textStorage);
    ChildData* child = unk08;
    if (child->flag1b5 == 0) {
        new(&text) hkErrStream(textStorage + sizeof(hkErrStream) / sizeof(unsigned int), 512);
        text.hkOstream::operator<<("No index available (") << static_cast<unsigned int>(child->unk1b0) << ")";
        if (DAT_01268360->message(3, 0x79f9d886, reinterpret_cast<char*>(textStorage + sizeof(hkErrStream) / sizeof(unsigned int)), ".\\GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp", 0x148))
            __debugbreak();
        text.hkOstream::~hkOstream();
    }
    return request->unk34;
}

// @fnv 0x00d75120
// src: GUESS 0x00d75120 (confidence: low)
int __stdcall Object_ReadPointedValue_00d75120(int* p)
{
    return *p;
}

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

// @fnv 0x00d75130
// src: GUESS 0x00d75130 (confidence: low)
int D75130Outer::EvaluateValue_00d75130()
{
    return unk08->unk40;
}

namespace fnv_00d75140 {

struct Owner {
    int unk00;
    int unk04;
    Data* unk08;
    int* ComputeValue_00d75140();
};
// @fnv 0x00d75140
// src: GUESS 0x00d75140 (confidence: low)
int* Owner::ComputeValue_00d75140() { return *reinterpret_cast<int**>(reinterpret_cast<char*>(unk08) + 0x3c); }
}  // namespace fnv_00d75140

// @fnv 0x00d75200
// src: GUESS 0x00d75200 (confidence: low)
int __stdcall Object_ReadPointedValue_00d75200(const int* value)
{
    return *value;
}

extern hkError* g_hkError;

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

// @fnv 0x00d75210
// src: HAVOK_LIB 0x00d75210
int S_00d75210_Self::hkgpConvexHull_getPlaneIndex(const S_00d75210_Data* v) const throw()
{
    S_00d75210_Config* cfg = m_pConfiguration;
    if (!cfg->m_hasIndex)
    {
        // Havok builds this with /GS-; a non-char buffer keeps /GS from adding a cookie.
        unsigned int buf[128];
        void* streamStorage[sizeof(hkErrStream) / sizeof(void*)];
        new(streamStorage) hkErrStream(buf, sizeof(buf));
        hkErrStream& ostr = *reinterpret_cast<hkErrStream*>(streamStorage);
        ostr.hkOstream::operator<<("No index available (") << cfg->m_1b0 << ")";
        if (g_hkError->message(3, 0x79f9d886, (const char*)buf, ".\\GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp", 328))
            __debugbreak();
        ostr.hkOstream::~hkOstream();
    }
    return v->m_uiEdgeIndex;
}

struct D762F0Target {
    void update();
};

struct D762F0Owner {
    int unk00;
    int unk04;
    D762F0Target* m_target;

    void ForwardCall_00d762f0();
};

// @fnv 0x00d762f0
// src: GUESS 0x00d762f0 (confidence: low)
void D762F0Owner::ForwardCall_00d762f0()
{
    m_target->update();
}

struct D76910Inner { void ProcessEntries_00d7cf00(); };
struct D76910Owner {
    int unk00;
    int unk04;
    D76910Inner* inner;
    void ForwardCall_00d76910();
};
// @fnv 0x00d76910
// src: GUESS 0x00d76910 (confidence: low)
void D76910Owner::ForwardCall_00d76910()
{
    inner->ProcessEntries_00d7cf00();
}

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

// Optionally clears a byte at offset 0x1b5 of unk08, stores value into unk08->unk04, then calls unk08->FUN_00d7d2a0().
// @fnv 0x00d76990
void FUN_00d76990_Class::SetValue(float value, bool clearFlag) {
    if (clearFlag)
        *(reinterpret_cast<unsigned char*>(unk08) + 0x1b5) = 0;
    unk08->unk04 = value;
    unk08->ProcessEntries_00d7d2a0();
}

extern "C" __m128 _mm_setr_ps(float a, float b, float c, float d);

struct __declspec(align(16)) hkVec4 {
    float x, y, z, w;
};

struct Shape {
    float ComputeValues_00d768b0(const hkVec4& v);
    float ProcessAndReturnValue_00d76840(const hkVec4& v);
    float ProcessAndReturnValue_00d769c0(const NiPoint3& p);
};

// Builds a 4-component vector from p and returns the difference of FUN_00d768b0 and FUN_00d76840 evaluated on it.
// @fnv 0x00d769c0
// src: GUESS 0x00d769c0 (confidence: low)
float Shape::ProcessAndReturnValue_00d769c0(const NiPoint3& p)
{
    hkVec4 v;
    *(__m128*)&v.x = _mm_setr_ps(p.x, p.y, p.z, 0.0f);
    return ComputeValues_00d768b0(v) - ProcessAndReturnValue_00d76840(v);
}

struct AudioSink {
    void hkgpConvexHullImpl_generateIndexedFaces_int_int(void* apFirst, void* apSecond, bool abIsNull, void* apThird);
};

struct FUN_00d76c50_cls {
    int unk00;
    int unk04;
    AudioSink* m_pSink;

    void DispatchToSink(void* apKey, void* apFirst, void* apSecond, void* apThird);
};

// Forwards apFirst, apSecond, apThird and whether apKey is null to the sink's FUN_00d7df60.
// @fnv 0x00d76c50
void FUN_00d76c50_cls::DispatchToSink(void* apKey, void* apFirst, void* apSecond,
                                    void* apThird)
{
    m_pSink->hkgpConvexHullImpl_generateIndexedFaces_int_int(apFirst, apSecond, apKey == 0, apThird);
}

namespace fnv_00d76c80 {
struct Target { float Call(int a, int b, int c); };
struct Owner { int unk00; int unk04; Target* unk08; void DispatchCall(int a, int b, int c); };
// @fnv 0x00d76c80
void Owner::DispatchCall(int aiArg1, int aiArg2, int aiArg3) { unk08->Call(aiArg1, aiArg2, aiArg3); }
}  // namespace fnv_00d76c80

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

// Stores v into the m_00 field of unk08, then calls unk08's FUN_00d81510 with a, b, 0, 0.
// @fnv 0x00d771c0
// src: HAVOK_LIB 0x00d771c0
void FUN_00d771c0_Owner::hkgpConvexHull_build(int a, int b, const Vec4i& v)
{
    unk08->m_00 = v;
    unk08->hkgpConvexHullImpl_build(a, b, 0, 0);
}

struct FUN_00d83430_class {
    void AllocateStorage_00d83430(int, int, int, float);
};
struct FUN_00d790a0_class {
    int unk00;
    int unk04;
    FUN_00d83430_class* unk08;
    void hkgpConvexHull_splitByPlane(int a, int b, int c, float d);
};
// Calls FUN_00d83430 on the object stored at unk08, passing the four arguments through unchanged.
// @fnv 0x00d790a0
// src: HAVOK_LIB 0x00d790a0
void FUN_00d790a0_class::hkgpConvexHull_splitByPlane(int aiArg1, int aiArg2, int aiArg3, float afArg4) {
    unk08->AllocateStorage_00d83430(aiArg1, aiArg2, aiArg3, afArg4);
}

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

// @fnv 0x00d79f90
// src: HAVOK_LIB 0x00d79f90
void __cdecl hkgpConvexHull_createVoronoiFeatures(S_00d79f90_World* world, int a, void* b, int n, float d)
{
    HkgpconvexhullGsEhscNogsNoehsc_ReleaseStorage_00d79ab0(world, a, b, d);
    S_00d79f90_Result* res = world->hkgpConvexHull_clone();
    res->ProcessEntries_00d78720(-d, S_00d79f90_Opts());
    hkgpConvexHull_booleanSubtraction_00d79580(res, b, n, 1e-07f);
    delete res;
}


struct S_00d7a010_Obj {
    virtual ~S_00d7a010_Obj() throw();
    void operator delete(void* p) throw();
};

void __cdecl hkgpConvexHull_createVoronoiFeatures(int a, int b, hkArrayBase<S_00d7a010_Obj*>& out, int c, float f) throw();

// Calls FUN_00d79f90 to fill an array of objects, deletes each element, then clears and deallocates the array via the heap.
// @fnv 0x00d7a010
void __cdecl DeleteCollectedObjects(int a, int b, int c, float f)
{
    hkArrayBase<S_00d7a010_Obj*> objs;
    hkgpConvexHull_createVoronoiFeatures(a, b, objs, c, f);
    for (int i = 0; i < objs.GetLogicalSize(); i++)
        delete objs[i];
    objs._clearAndDeallocate(getHavokMonitorStream().heap());
}

struct S_00d7c200 {
    void** m_kBlocks;
    int m_iBlockCount;
    int unk8;
    int unkC;
    int unk10;
    void FreeAll();
};
// @fnv 0x00d7c200
void S_00d7c200::FreeAll() {
    for (int i = 0; i < m_iBlockCount; i++) {
        void* p = m_kBlocks[i];
        getHavokMonitorStream().heap().blockFree(p, 0x808);
    }
    m_iBlockCount = 0;
    unkC = 0;
    unk10 = 0;
}

hkMemoryRouter* hkMemoryRouter_getInstance();
int ResizeAudioStream(hkMemoryAllocator* alloc, void* array, int elemSize);

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

// @fnv 0x00d7c340
S_00d7c340_Block* S_00d7c340::AllocateBlock()
{
    hkMemoryAllocator* heap = &hkMemoryRouter_getInstance()->heap();
    S_00d7c340_Elem* next = 0;
    S_00d7c340_Block* block = (S_00d7c340_Block*)heap->blockAlloc(sizeof(S_00d7c340_Block));
    S_00d7c340_Elem* head;
    for (int i = 31; i >= 0; --i) {
        S_00d7c340_Elem* e = &block->elems[i];
        e->next = next;
        head = e;
        next = e;
    }
    block->numUsed = 0;
    block->freeList = head;

    hkMemoryAllocator* alloc = &hkMemoryRouter_getInstance()->heap();
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(alloc, this, sizeof(S_00d7c340_Block*));
    S_00d7c340_Block** p = m_data + m_iElementCount;
    for (int k = 0; k < 1; k++)
        p[k] = block;
    m_iElementCount++;
    if (m_iElementCount > 1)
    {
        S_00d7c340_Block* t = m_data[0];
        m_data[0] = m_data[m_iElementCount - 1];
        m_data[m_iElementCount - 1] = t;
    }
    return block;
}

namespace fnv_00d7c8d0 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

// @fnv 0x00d7c8d0
void __fastcall DestroyQueuedElements(QueuedElements_hkgpconvexhull* self) throw()
{
    for (int i = 0; i < self->m_04; i++) {
        void* pItem = self->m_00[i];
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        reinterpret_cast<hkMemoryAllocator*>(pAllocator)->blockFree(pItem, 0x908);
    }
    self->m_04 = 0;
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCapacity = self->m_08;
    self->m_04 = 0;
    if ((uCapacity & 0x80000000) == 0)
        reinterpret_cast<hkMemoryAllocator*>(pAllocator)->bufFree(self->m_00, (uCapacity & 0x3fffffff) * 4);
    self->m_08 = 0x80000000;
    self->m_00 = 0;
}
}  // namespace fnv_00d7c8d0

namespace fnv_00d7ce20 {

hkMemoryRouter* hkMemoryRouter_getInstance() throw();


struct S_00d7ce20_Elem16 { int unk0; int unk4; int unk8; int unkC; };
struct S_00d7ce20_Elem48 { int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; };
struct S_00d7ce20_Elem64 { int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; };

void __fastcall ClearPointBlocks(hkArrayBase<void*>* blocks) throw();
struct S_00d7ce20_FreeListA {
    hkArrayBase<void*> m_kBlocks;
    int unkC;
    int unk10;
    int unk14;
    void FreeAll() throw();
    ~S_00d7ce20_FreeListA() throw()
    {
        FreeAll();
        ClearPointBlocks(&m_kBlocks);
    }
};
struct S_00d7ce20_Base {
    virtual ~S_00d7ce20_Base() throw() {}
};
struct S_00d7ce20_Pools : S_00d7ce20_Base {
    int unk4;
    S_00d7ce20_FreeListA m_kPointA;
    QueuedElements_hkgpconvexhull m_kPointB;
    int unk44;
    virtual ~S_00d7ce20_Pools() throw()
    {
        ::FlushQueuedElements(&m_kPointB);
        fnv_00d7c8d0::DestroyQueuedElements(&m_kPointB);
    }
};

struct FUN_00d7ce20 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d7ce20_Pools m_pools;
    hkArray<S_00d7ce20_Elem64> m_48;
    hkArray<S_00d7ce20_Elem16> m_54;
    hkArray<S_00d7ce20_Elem48> m_60;

    void hkgpConvexHullImpl_reset(int) throw();
    ~FUN_00d7ce20() throw();
};

// @fnv 0x00d7ce20
FUN_00d7ce20::~FUN_00d7ce20() throw()
{
    hkgpConvexHullImpl_reset(0);
}
}  // namespace fnv_00d7ce20

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
// Allocates a node from the bank's free list, copies the source node's value fields, links it at the head of the list and returns it.
// @fnv 0x00d7ef20
Node *PoolList::CloneNode(Node *source) {
    NodeBank *bank;
    if (bankValid == 0 || (*banks)->freeHead == 0)
        bank = hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_allocateNewPool();
    else
        bank = *banks;
    Node *node = bank->freeHead;
    bank->freeHead = node->link0;
    bank->allocated += 1;
    node->value10 = source->value10;
    node->value14 = source->value14;
    node->value18 = source->value18;
    node->value1c = source->value1c;
    node->value20 = source->value20;
    node->value24 = source->value24;
    node->value28 = source->value28;
    node->value2c = source->value2c;
    node->value30 = source->value30;
    node->value34 = source->value34;
    node->link4 = 0;
    Node *oldHead = head;
    node->link0 = oldHead;
    oldHead = head;
    if (oldHead != 0)
        oldHead->link4 = node;
    activeCount += 1;
    head = node;
    return node;
}

namespace fnv_00d7f060 {
struct D76940Shell { void ReleaseStorage_00d76940(); };
struct D7f060Owner;

BSAudio* __cdecl hkMemoryRouter_getInstance();
struct D7f060Owner {
    int unk00;
    unsigned short soundId;
    D7f060Owner* FUN_00d7f060(unsigned int flags);
};
// Calls FUN_00d76940, and if flags has bit 0 set, releases this object's soundId through the audio service, then returns this.
// @fnv 0x00d7f060
D7f060Owner* D7f060Owner::FUN_00d7f060(unsigned int flags)
{
    ((D76940Shell*)this)->ReleaseStorage_00d76940();
    if (flags & 1) {
        BSAudio* audio = hkMemoryRouter_getInstance();
        reinterpret_cast<hkMemoryAllocator*>(audio->pListener)->blockFree(this, soundId);
    }
    return this;
}
}  // namespace fnv_00d7f060

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

// Sets m_04 from DAT_0106ea1c and initialises the byte flags m_00 and m_08 through m_0d, then returns this.
// @fnv 0x00d74d40
// src: HAVOK_LIB 0x00d74d40
FUN_00d74d40_cls* FUN_00d74d40_cls::hkgpConvexHull_BuildConfig_BuildConfig()
{
    m_04 = DAT_0106ea1c;
    m_00 = 0;
    m_08 = 0;
    m_09 = 1;
    m_0a = 0;
    m_0b = 1;
    m_0c = 0;
    m_0d = 0;
    return this;
}

struct FUN_00d74d70_cls {
    int m_00;
    unsigned char m_04;
    float m_08;
    float m_0c;
    unsigned char m_10;
    unsigned char m_11;
    FUN_00d74d70_cls* hkgpConvexHull_SimplifyConfig_SimplifyConfig();
};

// @fnv 0x00d74d70
// src: HAVOK_LIB 0x00d74d70
FUN_00d74d70_cls* FUN_00d74d70_cls::hkgpConvexHull_SimplifyConfig_SimplifyConfig() {
    volatile int* p00 = (volatile int*)&m_00;
    *p00 = -1;
    m_04 = 1;
    volatile float* p08 = &m_08;
    *p08 = 0.0f;
    volatile float* p0c = &m_0c;
    *p0c = 0.0f;
    volatile unsigned char* p10 = &m_10;
    *p10 = 0;
    volatile unsigned char* p11 = &m_11;
    *p11 = 0;
    return this;
}

extern float DAT_0104da4c;

struct FUN_00d74d90_cls {
    int m_i00;
    float m_f04;

    FUN_00d74d90_cls* InitializeFields_00d74d90();
};

// @fnv 0x00d74d90
// src: GUESS 0x00d74d90 (confidence: low)
FUN_00d74d90_cls* FUN_00d74d90_cls::InitializeFields_00d74d90()
{
    m_f04 = DAT_0104da4c;
    m_i00 = 1;
    return this;
}

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

// @fnv 0x00d74e10
// src: GUESS 0x00d74e10 (confidence: medium)
int FUN_00d74e10_cls::GetInnerField1A8()
{
    return m_pInner->m_i1a8;
}

struct FUN_00d74e20_class {
    void* m_00; void* m_04; char* m_08;
    hkVector4 __thiscall GetFieldAtD0();
};
// Returns the four-int value stored at offset 0xd0 from the pointer in m_08.
// @fnv 0x00d74e20
hkVector4 FUN_00d74e20_class::GetFieldAtD0() {
    return *reinterpret_cast<const hkVector4*>(m_08+0xd0);
}

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

// @fnv 0x00d75050
// src: GUESS 0x00d75050 (confidence: low)
int FUN_00d75050_cls::EvaluateValue_00d75050()
{
    return m_pInner->m_i28;
}

struct FUN_00d7a180_target {
    void ProcessEntries_00d7a180();
};

struct FUN_00d752d0_cls {
    void* m_00;
    void* m_04;
    FUN_00d7a180_target* m_08;
    void ForwardCall_00d752d0();
};

// @fnv 0x00d752d0
// src: GUESS 0x00d752d0 (confidence: low)
void FUN_00d752d0_cls::ForwardCall_00d752d0() {
    m_08->ProcessEntries_00d7a180();
}

extern hkError* g_diagLogger;

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

// @fnv 0x00d75390
float FUN_00d75390_cls::GetMass() {
    DiagState* st = m_08;
    if (st->m_1b4 != 0) {
    } else {
        unsigned int streamStorage[sizeof(hkErrStream) / sizeof(unsigned int) + 128];
        hkErrStream& s = *reinterpret_cast<hkErrStream*>(streamStorage);
        new(&s) hkErrStream(streamStorage + sizeof(hkErrStream) / sizeof(unsigned int), 0x200);
        s.hkOstream::operator<<("No mass properties available (") << st->m_1b0 << ")";
        if (g_diagLogger->message(3, 0x79f9d887, reinterpret_cast<char*>(streamStorage + sizeof(hkErrStream) / sizeof(unsigned int)), ".\\GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp", 0x14e) != 0) {
            __debugbreak();
        }
        s.hkOstream::~hkOstream();
    }
    return m_08->m_1a4;
}

extern "C" double __cdecl pow(double base, double exponent);

extern const double DAT_010d35e8;
extern const double DAT_010d35e0;

struct FUN_00d75440_cls {
    float hkgpConvexHull_getVolume();
    double GetMass();
    float ComputeScaledPowerRatio();
};

// Raises the value from FUN_00d752e0 to DAT_010d35e8, scales by DAT_010d35e0, divides by GetMass and returns the float result.
// @fnv 0x00d75440
float FUN_00d75440_cls::ComputeScaledPowerRatio()
{
    float base = this->hkgpConvexHull_getVolume();
    float powered = (float)pow((double)base, DAT_010d35e8);
    double scaled = (double)powered * DAT_010d35e0;
    double dDivisor = this->GetMass();
    return (float)(scaled / dDivisor);
}

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

// Builds a temporary FUN_00d75820_Tmp8 and forwards a1, a2, its address and a3 to m08's FUN_00d7a200.
// @fnv 0x00d75820
void FUN_00d75820_cls::CallTargetWithTemp(int a1, float a2, int a3)
{
    FUN_00d75820_Tmp8 tmpArg;
    this->m08->ProcessEntries_00d7a200(a1, a2, &tmpArg, a3);
}

struct FUN_00d7b330_cls {
    void ProcessEntries_00d7b330(int a1, int a2, float a3);
};

struct FUN_00d76100_cls {
    void* unk00;
    void* unk04;
    FUN_00d7b330_cls* m_08;
    void hkgpConvexHull_isPointInside(int a1, int a2, float a3);
};

// @fnv 0x00d76100
// src: HAVOK_LIB 0x00d76100
void FUN_00d76100_cls::hkgpConvexHull_isPointInside(int a1, int a2, float a3) {
    m_08->ProcessEntries_00d7b330(a1, a2, a3);
}

struct FUN_00d7caa0_class {
    void __thiscall ProcessEntries_00d7caa0(float, int);
};

struct FUN_00d76920_class {
    void* m_00;
    void* m_04;
    FUN_00d7caa0_class* m_08;
    void hkgpConvexHull_fetchBevelPlanes(float, int);
};

// @fnv 0x00d76920
// src: HAVOK_LIB 0x00d76920
void __thiscall FUN_00d76920_class::hkgpConvexHull_fetchBevelPlanes(float f, int i) {
    m_08->ProcessEntries_00d7caa0(f, i);
}

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

// @fnv 0x00d77bc0
// src: GUESS 0x00d77bc0 (confidence: low)
void FUN_00d77bc0_cls::UpdateFields_00d77bc0() {
    SpawnedObject* self = reinterpret_cast<SpawnedObject*>(this);
    TailCallee* next = reinterpret_cast<TailCallee*>(self->m_08);
    next->Tail();
}

namespace fnv_00d77bd0 {
struct Inner
{
    void Run();
};

struct FUN_00d77bd0_cls
{
    int unk00;
    int unk04;
    Inner* m_pInner;
    void ForwardCall_00d77bd0();
};

// @fnv 0x00d77bd0
// src: GUESS 0x00d77bd0 (confidence: low)
void FUN_00d77bd0_cls::ForwardCall_00d77bd0()
{
    m_pInner->Run();
}
}  // namespace fnv_00d77bd0

struct ArgPair
{
    int m_kPointA;
    int m_kPointB;
};

void __cdecl hkgpConvexHull_createCompound(int first, ArgPair* apPairs, int count);

// Builds an ArgPair from a1 and a2 and passes it with a0 and count 2 to FUN_00d78ea0.
// @fnv 0x00d79060
void __cdecl CallWithPair(int aiFirst, int aiFirstValue, int aiSecondValue)
{
    ArgPair pair;

    pair.m_kPointA = aiFirstValue;
    pair.m_kPointB = aiSecondValue;
    hkgpConvexHull_createCompound(aiFirst, &pair, 2);
}

struct D79090Target {
    void update();
};

struct D79090Owner {
    int unk00;
    int unk04;
    D79090Target* m_target;

    void ForwardCall_00d79090();
};

// @fnv 0x00d79090
// src: GUESS 0x00d79090 (confidence: low)
void D79090Owner::ForwardCall_00d79090()
{
    m_target->update();
}

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

// Calls FUN_00d79250_helper, then either invokes doIt(1) on the returned object or on each item from start to m_04, resetting m_04 to 0.
// @fnv 0x00d79510
// src: HAVOK_LIB 0x00d79510
bool __cdecl hkgpConvexHull_booleanSubtraction(FUN_00d79510_A* a, FUN_00d79510_B* b,
                          FUN_00d79510_Object* apObject, float afValue)
{
    int start = ((FUN_00d79510_Record*)apObject)->m_04;
    FUN_00d79510_Record* p = (FUN_00d79510_Record*)apObject;
    FUN_00d79250_helper(a, b, &apObject, apObject, afValue);
    if (apObject) {
        apObject->FUN_00d79510_doIt(1);
        return true;
    }
    for (int i = start; i < p->m_04; i++) {
        FUN_00d79510_Item* pItem = p->m_00[i];
        if (pItem) {
            pItem->FUN_00d79510_doIt(1);
        }
    }
    p->m_04 = 0;
    return false;
}

static int SortKeyOf(void* p)
{
    return ((int*)p)[0xe];
}

// @fnv 0x00d7a420
void __cdecl QuickSortByKey(void** apArray, int lo, int hi, int ctx)
{
    int i;
    int j;
    __declspec(align(16)) struct PivotSlot { void* p; } pivotSlot;

    for (;;) {
        i = lo;
        pivotSlot.p = apArray[(lo + hi) >> 1];
        j = hi;
        for (;;) {
            int key = SortKeyOf(pivotSlot.p);
            while (SortKeyOf(apArray[i]) < key)
                i++;
            while (key < SortKeyOf(apArray[j]))
                j--;
            if (j < i)
                break;
            if (j != i) {
                void* a = apArray[i];
                void* b = apArray[j];
                apArray[j] = a;
                apArray[i] = b;
            }
            j--;
            i++;
            if (i > j)
                break;
        }
        if (lo < j)
            QuickSortByKey(apArray, lo, j, ctx);
        if (i >= hi)
            break;
        lo = i;
    }
}

struct RandomGenerator {
    unsigned int stateFlags;
    unsigned int seed;
    void hkPseudoRandomGenerator_getRandomVector11(float* components);
};
// Advances the LCG seed four times and writes four floats in [-1,1] into components.
// @fnv 0x00d7a4b0
// src: HAVOK_LIB 0x00d7a4b0
void RandomGenerator::hkPseudoRandomGenerator_getRandomVector11(float* components)
{
    seed = seed * 1664525u + 1013904223u;
    components[0] = (float)((float)seed * 2.3283064365386963e-10) * 2.0 - 1.0;
    seed = seed * 1664525u + 1013904223u;
    components[1] = (float)((float)seed * 2.3283064365386963e-10) * 2.0 - 1.0;
    seed = seed * 1664525u + 1013904223u;
    components[2] = (float)((float)seed * 2.3283064365386963e-10) * 2.0 - 1.0;
    seed = seed * 1664525u + 1013904223u;
    components[3] = (float)((float)seed * 2.3283064365386963e-10) * 2.0 - 1.0;
}

struct Record {
    unsigned int payload;
    float key;
};

static __forceinline bool Greater(const Record &a,const Record &b) { return a.key-b.key>0.0f; }

// Sorts records in [left, right] by key using an in-place quicksort with a middle pivot and recursive partitioning.
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

// Releases each queued element through the heap, then resets the queue count and related counters.
// @fnv 0x00d7c250
void __fastcall FlushQueuedElements(QueuedElements_hkgpconvexhull* self)
{
    for (int i = 0; i < self->m_04; i++) {
        void* element = self->m_00[i];
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        router->m_heap->blockFree(element, 0x908);
    }
    self->m_04 = 0;
    self->m_0c = 0;
    self->m_10 = 0;
}

// FUN_00d7c2a0 - create a new object of type 0x808 and append it to the
// item list of this container.
//
// The container keeps an array of item pointers (m_00), the number of items
// (m_04) and a capacity/flags field (m_08).  The new object is allocated
// through the creation interface found at offset 0x10 of the global manager;
// the object itself starts with a free list of 32 linked 64 byte blocks.

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

// @fnv 0x00d7c2a0
// src: HAVOK_LIB 0x00d7c2a0
void* FUN_00d7c2a0_cls::hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_allocateNewPool()
{
    hkMemoryRouter* pManager = hkMemoryRouter_getInstance();
    void* prev = 0;
    unsigned char* pObject = (unsigned char*)pManager->m_heap->blockAlloc(0x808);

    // Build the free list of the 32 blocks that start at obj + 0x00: every
    // block points at the next one, the last one points at null.
    int i = 31;
    unsigned char* p = pObject + 0x7c0;
    void* cur = 0;
    while (i >= 0) {
        *(void**)p = prev;
        cur = p;
        prev = p;
        --i;
        p -= 0x40;
    }
    *(int*)(pObject + 0x804) = 0;
    *(void**)(pObject + 0x800) = cur;

    // Grow the item array when it is full.
    hkMemoryRouter* pManager2 = hkMemoryRouter_getInstance();
    if (m_04 == (m_08 & 0x3fffffff)) {
        ResizeAudioStream(pManager2->m_heap, this, 4);
    }

    // Append the new object and move the previous first item to the end.
    MakeSlot(m_00, m_04) = (void*)pObject;
    m_04++;
    if (m_04 > 1) {
        void* last = m_00[m_04 - 1];
        void* first = m_00[0];
        m_00[0] = last;
        m_00[m_04 - 1] = first;
    }
    return pObject;
}

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

struct D7C850_Class {
    void** m_00;
    int m_04;
    unsigned int m_08;
    void ClearAndFlush();
};

// @fnv 0x00d7c850
void D7C850_Class::ClearAndFlush()
{
    for (int i = 0; i < m_04; i++) {
        void* element = m_00[i];
        hkMemoryRouter* service = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        service->m_heap->blockFree(element, 0x808);
    }
    m_04 = 0;
    hkMemoryRouter* service = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* target = service->m_heap;
    unsigned int flags = m_08;
    m_04 = 0;
    if (!(flags & 0x80000000u))
        target->bufFree(m_00, (flags & 0x3fffffffu) * 4);
    m_08 = 0x80000000u;
    m_00 = 0;
}

extern char DAT_0103d078;

struct RetBlock64
{
	__m128 m_v0;
	__m128 m_v1;
	__m128 m_v2;
	__m128 m_v3;
};

struct RetBlock16
{
	__m128 m_v0;
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
	__m128 m_v120;
	__m128 m_v130;
	__m128 m_v140;
	__m128 m_v150;
	__m128 m_v160;
	int unk170, unk174, unk178, unk17C;
	int unk180, unk184, unk188, unk18C;
	int unk190, unk194, unk198, unk19C;
	int unk1A0, unk1A4, unk1A8, unk1AC;
	int m_i1B0;
	unsigned char m_b1B4;
};

class FUN_00d75490_cls
{
public:
	int unk00;
	int unk04;
	SharedOwner *m_pSharedOwner;
	void GetMassProperties(RetBlock64 *pOut64, RetBlock16 *pOut16);
};

// Asserts when the owner has no mass properties, then copies four vectors from the owner into pOut64 and one vector into pOut16.
// @fnv 0x00d75490
void FUN_00d75490_cls::GetMassProperties(RetBlock64 *pOut64, RetBlock16 *pOut16)
{
	SharedOwner *pOwner = m_pSharedOwner;
	if (pOwner->m_b1B4 == 0)
	{
		unsigned int buf[0x80];
		void* streamStorage[sizeof(hkErrStream) / sizeof(void*)];
		hkErrStream& dbgStr = *reinterpret_cast<hkErrStream*>(streamStorage);

		new(&dbgStr) hkErrStream(buf, 0x200);
		dbgStr.hkOstream::operator<<("No mass properties available (") << static_cast<unsigned int>(pOwner->m_i1B0) << &DAT_0103d078;
		hkError* pAssertMgr = DAT_01268360;
		if (pAssertMgr->message(3, 0x79f9d887, (char *)buf, ".\\GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp", 0x14e))
		{
			__debugbreak();
		}
		dbgStr.hkOstream::~hkOstream();
	}
	__m128 *pSrcVec = &m_pSharedOwner->m_v120;
	pOut64->m_v0 = *pSrcVec;
	pOut64->m_v1 = pSrcVec[1];
	pOut64->m_v2 = pSrcVec[2];
	pOut64->m_v3 = pSrcVec[3];
	pOut16->m_v0 = m_pSharedOwner->m_v160;
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int numElements, int sizeElem);


static inline hkVector4* ExpandHullVectors(hkArrayBase<hkVector4>& array, int n)
{
    hkMemoryAllocator& alloc = getHavokMonitorStream().heap();
    int oldSize = array.m_iElementCount;
    int required = oldSize + n;
    const int cap = array.getCapacity();
    if (cap < required) {
        int cap2 = 2 * cap;
        int newSize = (required < cap2) ? cap2 : required;
        hkArrayUtil__reserve(&alloc, &array, newSize, sizeof(hkVector4));
    }
    array.m_iElementCount += n;
    return array.m_data + oldSize;
}

struct D76250Shape {
    int getNumVertices() const;
    const hkVector4& getVertex(int i) const;

    void CopyVerticesToArray(hkArrayBase<hkVector4>& vertices) const;
};

// Expands the vector array by the shape's vertex count and copies each vertex from the shape into the newly allocated slots.
// @fnv 0x00d76250
void D76250Shape::CopyVerticesToArray(hkArrayBase<hkVector4>& vertices) const
{
    hkVector4* dst = ExpandHullVectors(vertices, getNumVertices());
    int i = 0;
    int numVertices = getNumVertices();
    for (; i < numVertices; i++) {
        hkVector4* d = dst++;
        *d = getVertex(i);
    }
}

struct FUN_00d81510_cls {
    void hkgpConvexHullImpl_build(int a1, int a2, int a3, int a4);
};

struct FUN_00d77320_cls {
    int unk00;
    int unk04;
    FUN_00d81510_cls* m_08;

    void CopyAndDispatch(int* a1, int a2, const __m128* a3, const unsigned int* a4);
};

// Copies four unsigned ints from a4 into m_08, stores the __m128 from a3 at offset 0xe0, then calls FUN_00d81510 on m_08 with a1, a2, 1, 0.
// @fnv 0x00d77320
void FUN_00d77320_cls::CopyAndDispatch(int* a1, int a2, const __m128* pVec, const unsigned int* pUInts)
{
    unsigned int* dst = (unsigned int*)m_08;
    dst[0] = pUInts[0];
    dst[1] = pUInts[1];
    dst[2] = pUInts[2];
    dst[3] = pUInts[3];
    *(__m128*)((char*)m_08 + 0xe0) = *pVec;
    m_08->hkgpConvexHullImpl_build((int)a1, a2, 1, 0);
}

struct FnvCpu_FUN_00d74e00_CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    int value;
    int GetValue_00d74e00();
};
// @fnv 0x00d74e00
// src: GUESS 0x00d74e00 (confidence: high)
int FnvCpu_FUN_00d74e00_CpuObject::GetValue_00d74e00()
{
    return value;
}

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

// If the entity's unk1b4 is zero, builds a message via a local helper and asserts on failure, then returns the entity's unk1a0.
// @fnv 0x00d752e0
// src: HAVOK_LIB 0x00d752e0
float S_00d752e0_Class::hkgpConvexHull_getVolume() {
    S_00d752e0_Entity* entity = this->unk08;
    if (entity->unk1b4 == 0) {
        unsigned int streamStorage[sizeof(hkErrStream) / sizeof(unsigned int) + 128];
        hkErrStream& localBuilder = *reinterpret_cast<hkErrStream*>(streamStorage);
        new(&localBuilder) hkErrStream(streamStorage + sizeof(hkErrStream) / sizeof(unsigned int), 0x200);

        localBuilder.hkOstream::operator<<(str_010d358c) << static_cast<unsigned int>(entity->unk1b0) << &DAT_0103d078;

        if (DAT_01268360->message(
                3,
                0x79f9d887,
                reinterpret_cast<char*>(streamStorage + sizeof(hkErrStream) / sizeof(unsigned int)),
                str_010d3540,
                0x14e)) {
            __debugbreak();
        }

        localBuilder.hkOstream::~hkOstream();
    }
    return this->unk08->unk1a0;
}

// Recursive quicksort partition over 12-byte records keyed by a float at +8;
// the key delta is scaled by the double literal -1.0 before testing against 0.0.
struct SortRec12 {
    unsigned int m0;
    unsigned int m4;
    float key;
};

// Partitions SortRec12 records around a pivot key and recurses on the left part, looping on the right part.
// @fnv 0x00d7b160
// src: HAVOK_LIB 0x00d7b160
void __cdecl hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedEdge_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedEdge(SortRec12* apRecords, int lo, int hi, int aiUnused)
{
    for (;;) {
        int i = lo;
        int j = hi;
        __declspec(align(16)) SortRec12 pv = apRecords[(hi + lo) >> 1];
        float pivot = pv.key;

        for (;;) {
            for (;;) {
                if (((apRecords[i].key - pivot) * -1.0 > 0.0) == 0) {
                    break;
                }
                ++i;
            }
            for (;;) {
                if (0 == ((pivot - apRecords[j].key) * -1.0 > 0.0)) {
                    break;
                }
                --j;
            }
            if (j < i) {
                break;
            }
            int size = j != i; if (size) {
                SortRec12& right = apRecords[j];
                SortRec12& left = apRecords[i];
                __declspec(align(16)) SortRec12 t = right;
                right = left;
                left = t;
            }
            --j;
            ++i;
            if (i > j) {
                break;
            }
        }

        if (lo < j) {
            hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedEdge_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedEdge(apRecords, lo, j, aiUnused);
        }
        if (i >= hi) {
            return;
        } else { lo = i; }
    }
}

extern "C" {
__m128 __cdecl _mm_sub_ps(__m128, __m128);
__m128 __cdecl _mm_mul_ps(__m128, __m128);
__m128 __cdecl _mm_shuffle_ps(__m128, __m128, unsigned int);
__m128 __cdecl _mm_add_ss(__m128, __m128);
void __cdecl _mm_store_ss(float*, __m128);
}
struct DistanceScalar {
    __m128 q;
    __forceinline DistanceScalar(__m128 v) : q(v) {}
    __forceinline float getReal() const { float f; _mm_store_ss(&f,q); return f; }
};
struct DistanceVector {
    __m128 q;
    __forceinline DistanceVector() {}
    __forceinline DistanceVector(const DistanceVector& v) : q(v.q) {}
    __forceinline void operator=(const DistanceVector& v) { q=v.q; }
    __forceinline void setSub(const DistanceVector& a,const DistanceVector& b) { q=_mm_sub_ps(a.q,b.q); }
    __forceinline DistanceScalar lengthSquared() const {
        __m128 d=_mm_mul_ps(q,q);
        __m128 y=_mm_shuffle_ps(d,d,0x55);
        __m128 z=_mm_shuffle_ps(d,d,0xaa);
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
// Sorts the array in place with the midpoint element as pivot and DistanceLess for comparisons.
// @fnv 0x00d7aaf0
// src: GUESS 0x00d7aaf0 (confidence: medium)
void Hkgpconvexhull_SortDistanceVectors(DistanceVector* apVectors,int aiLow,int aiHigh,DistanceLess less)
{
    for (;;) {
        int i=aiLow,j=aiHigh;
        DistanceVector pivot=apVectors[(aiLow+aiHigh)>>1];
        do {
            while(less(apVectors[i],pivot)) ++i;
            while(less(pivot,apVectors[j])) --j;
            if(j<i) break;
            if(j!=i) {
                DistanceVector temp=apVectors[j];
                apVectors[j]=apVectors[i];
                apVectors[i]=temp;
            }
            --j;
            ++i;
        } while(i<=j);
        if(aiLow<j) Hkgpconvexhull_SortDistanceVectors(apVectors,aiLow,j,less);
        if(i>=aiHigh) break;
        aiLow=i;
    }
}

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
struct S00d7d1c0_Base {
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p, int size);
    unsigned short m04;
};
inline void* operator new(unsigned int, void* p) { return p; }
struct S00d7d1c0_Derived : S00d7d1c0_Base {
    S00d7d1c0_M08 m08;
    QueuedElements_hkgpconvexhull m20;
    ~S00d7d1c0_Derived() {
        FlushQueuedElements(&m20);
        fnv_00d7c8d0::DestroyQueuedElements(&m20);
        m08.FreeAll();
        m08.ClearAndFlush();
    }
    S00d7d1c0_Derived* hkgpAbstractMesh_hkgpConvexHullImpl_Edge_hkgpConvexHullImpl_Vertex_hkgpConvexHullImpl_Triangle_hkContainerHeapAllocator_Destroy(int flags);
};
// @fnv 0x00d7d1c0
// src: COMMUNITY 0x00d7d1c0
S00d7d1c0_Derived* S00d7d1c0_Derived::hkgpAbstractMesh_hkgpConvexHullImpl_Edge_hkgpConvexHullImpl_Vertex_hkgpConvexHullImpl_Triangle_hkContainerHeapAllocator_Destroy(int flags)
{
    this->~S00d7d1c0_Derived();
    new (static_cast<S00d7d1c0_Base*>(this)) S00d7d1c0_Base();
    if (flags & 1) {
        hkMemoryRouter* r = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        r->m_heap->blockFree(this, m04);
    }
    return this;
}

extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" void _mm_store_ps(float*, __m128);

// Writes a 4x4 array using the input components and the value minus 1.
// @fnv 0x00d74c70
// src: GUESS 0x00d74c70 (confidence: low)
void __cdecl Hkgpconvexhull_ComputeValues_00d74c70(const __m128* input, float value, float* apMatrix)
{
    float scalar = value - 1.0f;
    __m128 vector = *input;
    __m128 s = _mm_load_ss(&scalar);
    __m128 splat = _mm_shuffle_ps(s, s, 0);
    float product[4];
    float squared[4];
    _mm_store_ps(product, _mm_mul_ps(splat, vector));
    _mm_store_ps(squared, _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&scalar), _mm_load_ss(&scalar), 0), _mm_mul_ps(vector, vector)));
    apMatrix[0] = squared[0] + 1.0f;
    float first = input->m128_f32[0] * product[1];
    apMatrix[4] = first;
    float second = input->m128_f32[0] * product[2];
    apMatrix[8] = second;
    apMatrix[12] = product[0] * input->m128_f32[3];
    apMatrix[1] = apMatrix[4];
    apMatrix[5] = squared[1] + 1.0f;
    apMatrix[9] = input->m128_f32[1] * product[2];
    apMatrix[13] = product[1] * input->m128_f32[3];
    apMatrix[2] = apMatrix[8];
    apMatrix[6] = apMatrix[9];
    apMatrix[10] = squared[2] + 1.0f;
    apMatrix[14] = product[2] * input->m128_f32[3];
    apMatrix[3] = 0.0f;
    apMatrix[7] = 0.0f;
    apMatrix[11] = 0.0f;
    apMatrix[15] = 1.0f;
}

extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern const double DAT_010d3698;
extern const float DAT_010d3690;
extern const double DAT_010d3688;

struct S00d75fc0_Node {
    S00d75fc0_Node* next;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int keyX;
    int keyY;
};

struct S00d75fc0_Key { int x, y, z; };

struct S00d75fc0_Cell {
    hkVec4 lo;
    hkVec4 hi;
    S00d75fc0_Key key;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};

struct S00d75fc0_Cfg {
    bool Find(S00d75fc0_Key k) const
    {
        for (S00d75fc0_Node* n = head; n; n = n->next) {
            if (k.x == n->keyX && k.y == n->keyY)
                return true;
        }
        return false;
    }

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    S00d75fc0_Node* head;
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    __m128 origin;
    __m128 invCellSize;
};

struct S00d75fc0_Grid {
    int unk00;
    int unk04;
    S00d75fc0_Cfg* cfg;
    bool ProcessEntries_00d75fc0(const hkVec4* pos);
};

// Transforms pos into grid cell coordinates using c->origin and c->invCellSize, then returns whether c->Find finds that cell key.
// @fnv 0x00d75fc0
// src: GUESS 0x00d75fc0 (confidence: low)
bool S00d75fc0_Grid::ProcessEntries_00d75fc0(const hkVec4* apPosition)
{
    S00d75fc0_Cfg* c = cfg;
    hkVec4 v = *apPosition;
    __m128* pv = (__m128*)&v;
    *pv = _mm_mul_ps(_mm_sub_ps(*pv, c->origin), c->invCellSize);
    S00d75fc0_Cell cell;
    for (int i = 0; i < 3; ++i) {
        float x = (&v.x)[i];
        float t = x > DAT_010d3698 ? DAT_010d3690 : x;
        float c = t < DAT_010d3688 ? -8192.0f : t;
        float fRoundOffset = c < 0.0f ? -0.5f : 0.5f;
        (&cell.key.x)[i] = (int)(fRoundOffset + c);
    }
    return c->Find(cell.key);
}

extern "C" double fabs(double);

struct S00d78b90_Node {
    virtual void Release(int flags);
    void ForwardCall_00d762f0();
    float hkgpConvexHull_getVolume();
    bool ForwardCall_00d77bd0(int idx, int arg);
};

struct S00d78b90_Node2 {
    float hkgpConvexHull_getVolume();
};

S00d78b90_Node* hkgpConvexHull_clone();

struct S00d78b90_Store {
    int GetInnerField1A8();
    int EvaluateValue_00d75050();
};

struct S00d78b90_Store2 {
    S00d78b90_Node* hkgpConvexHull_clone();
};

// @fnv 0x00d78b90
// src: HAVOK_LIB 0x00d78b90
S00d78b90_Node* hkgpConvexHull_volumeSimplify(S00d78b90_Store* apStore, float fThreshold, int arg3) {
    if (apStore->GetInnerField1A8() == 3) {
        S00d78b90_Node* best = hkgpConvexHull_clone();
        float f = best->hkgpConvexHull_getVolume();
        int lo = 4;
        int hi = apStore->EvaluateValue_00d75050();
        while (((hi - lo) & ~1) != 0) {
            int mid = (hi + lo) >> 1;
            S00d78b90_Node* node = ((S00d78b90_Store2*)apStore)->hkgpConvexHull_clone();
            node->ForwardCall_00d762f0();
            if (!node->ForwardCall_00d77bd0(mid, arg3)) {
                if (node != 0)
                    node->Release(1);
                break;
            }
            float v = ((S00d78b90_Node2*)node)->hkgpConvexHull_getVolume();
            float r = (v - f) / f;
            volatile float fAbsRatio = (float)fabs(r);
            if (fAbsRatio < fThreshold) {
                S00d78b90_Node* old = best;
                best = node;
                hi = mid;
                node = old;
            } else {
                lo = mid;
            }
            if (node != 0)
                node->Release(1);
        }
        return best;
    }
    return 0;
}

struct PoolEntryHead {
    int unk08, unk0C, unk10, unk14, unk18, unk1C;
};
struct PoolEntryBlock {
    int b00, b04, b08, b0C, b10, b14, b18, b1C;
};
struct PoolEntryTail {
    int unk40, unk44;
};
struct PoolEntryData {
    PoolEntryHead head;
    PoolEntryBlock block;
    PoolEntryTail tail;
    PoolEntryData& operator=(const PoolEntryData& o)
    {
        head = o.head;
        block = o.block;
        tail = o.tail;
        return *this;
    }
};

struct PoolEntry {
    PoolEntry* next;
    PoolEntry* prev;
    PoolEntryData data;
};

struct PoolBlock {
    PoolEntry entries[32];
    PoolEntry* freeList;
    int numUsed;

    PoolEntry* take()
    {
        PoolEntry* e = freeList;
        freeList = e->next;
        numUsed++;
        return e;
    }
};

struct PoolBlockArray {
    PoolBlock** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    PoolBlock* AllocateBlock();
};

struct FUN_00d7efc0_cls {
    PoolBlockArray m_kBlocks;
    PoolEntry* m_pFirstNode;
    int m_uiItemCount;

    PoolEntry* hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHull_Vertex_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Triangle_32_struct_hkContainerHeapAllocator_allocate(const PoolEntry* src);
};

// Allocates a new PoolEntry from the pool, copies src->data into it, and prepends it to the m_pFirstNode list.
// @fnv 0x00d7efc0
// src: HAVOK_LIB 0x00d7efc0
PoolEntry* FUN_00d7efc0_cls::hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHull_Vertex_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Triangle_32_struct_hkContainerHeapAllocator_allocate(const PoolEntry* apSource)
{
    PoolBlock* block;
    if (m_kBlocks.m_iElementCount == 0 || m_kBlocks.m_data[0]->freeList == 0)
        block = m_kBlocks.AllocateBlock();
    else
        block = m_kBlocks.m_data[0];
    PoolEntry* node = block->take();
    node->data = apSource->data;
    node->prev = 0;
    node->next = m_pFirstNode;
    if (m_pFirstNode)
        m_pFirstNode->prev = node;
    m_uiItemCount++;
    m_pFirstNode = node;
    return node;
}

struct FUN_00d74db0_cls {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* __thiscall GetField0cAddress();
};

// @fnv 0x00d74db0
// src: GUESS 0x00d74db0 (confidence: low)
void* FUN_00d74db0_cls::GetField0cAddress() {
    return &m_0c;
}

extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);

extern const hkVec4 DAT_010c44d0;
struct ShapeHelper {
    void ProcessEntries_00d76320(const hkVec4* apInput, hkVec4* apOutput);
};
// XORs the input with DAT_010c44d0, passes it to ShapeHelper, and returns three component products summed with the input's w.
// @fnv 0x00d76840
// src: GUESS 0x00d76840 (confidence: low)
float Shape::ProcessAndReturnValue_00d76840(const hkVec4& avInput)
{
    hkVec4 kNegated;
    hkVec4 kResult;
    *(__m128*)&kNegated = _mm_xor_ps(*(__m128*)&avInput, *(__m128*)&DAT_010c44d0);
    ((ShapeHelper*)this)->ProcessEntries_00d76320(&kNegated, &kResult);
    __m128 kW;
    if (&avInput) kW = _mm_shuffle_ps(*(__m128*)&avInput, *(__m128*)&avInput, 0xff);
    __m128 kP = _mm_mul_ps(*(__m128*)&avInput, *(__m128*)&kResult);
    __m128 kSum = _mm_add_ss(_mm_shuffle_ps(kP, kP, 0x55), kP);
    kSum = _mm_add_ss(_mm_shuffle_ps(kP, kP, 0xaa), kSum);
    kSum = _mm_add_ss(kSum, kW);
    float fResult;
    _mm_store_ss(&fResult, kSum);
    return fResult;
}

struct S00d79250_Obj {
    virtual ~S00d79250_Obj();
    int hkgpConvexHull_splitByPlane(const hkVec4& point, S00d79250_Obj** first, S00d79250_Obj** second, float tolerance);
};
struct S00d79250_World { S00d79250_Obj* hkgpConvexHull_clone(); };
struct S00d79250_Data {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50;
    hkVec4* points;
};
struct S00d79250_Shape {
    int unk00; int unk04;
    S00d79250_Data* data;
    int hkgpConvexHull_getNumPlanes();
    float ProcessAndReturnValue_00d76840(const hkVec4& point);
};
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int numElements, int sizeElem);
template <typename T>
static __forceinline void AppendHullPointer(hkArrayBase<T*>& array, T* value)
{
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    if (array.m_iElementCount == (array.m_iCapacityState & 0x3fffffff)) {
        ResizeAudioStream(router->m_heap, &array, sizeof(T*));
    }
    T** p = array.m_data + array.m_iElementCount;
    __assume(p != 0);
    new (p) T*(value);
    array.m_iElementCount++;
}

// Selects the remaining point with the highest score and passes it to FUN_00d790a0, updating or disposing of objects based on the result.
// @fnv 0x00d79250
// src: HAVOK_LIB 0x00d79250
void __cdecl hkgpConvexHull_booleanSplit(S00d79250_World* world, S00d79250_Shape* shape,
                          S00d79250_Obj** output, hkArrayBase<S00d79250_Obj*>* discarded, float tolerance)
{
    S00d79250_Obj* current = world->hkgpConvexHull_clone();
    S00d79250_Data* data = shape->data;
    hkArrayBase<int> indices;
    if (output) *output = 0;
    if (discarded) discarded->m_iElementCount = 0;
    int numIndices = shape->hkgpConvexHull_getNumPlanes();
    indices._setSize(getHavokMonitorStream().heap(), numIndices);
    int i = 0;
    int n = shape->hkgpConvexHull_getNumPlanes();
    for (; i < n; i++)
        indices[i] = i;
    while (current && indices.GetLogicalSize() > 0) {
        int best = 0;
        float bestScore = shape->ProcessAndReturnValue_00d76840(data->points[indices[best]]);
        for (int i = best + 1; i < indices.GetLogicalSize(); i++) {
            float score = shape->ProcessAndReturnValue_00d76840(data->points[indices[i]]);
            if (score > bestScore) {
                bestScore = score;
                best = i;
            }
        }
        const hkVec4& point = data->points[indices[best]];
        indices.m_iElementCount--;
        if (indices.m_iElementCount != best)
            indices[best] = indices[indices.m_iElementCount];
        S00d79250_Obj* pieces[2];
        switch (current->hkgpConvexHull_splitByPlane(point, &pieces[0], &pieces[1], tolerance)) {
        case 1:
            if (discarded) AppendHullPointer(*discarded, current);
            else if (current) delete current;
            current = 0;
            break;
        case 3:
            delete current;
            current = pieces[1];
            if (discarded) {
                if (pieces[0]) AppendHullPointer(*discarded, pieces[0]);
            } else if (pieces[0]) {
                delete pieces[0];
            }
            break;
        }
    }
    if (output) *output = current;
    else if (current) delete current;
    indices._clearAndDeallocate(getHavokMonitorStream().heap());
}

struct __declspec(align(16)) Vector333 {int x,y,z,w; Vector333(){} Vector333(const Vector333&o){*reinterpret_cast<__m128*>(this)=*reinterpret_cast<const __m128*>(&o);} Vector333& operator=(const Vector333&o){*reinterpret_cast<__m128*>(this)=*reinterpret_cast<const __m128*>(&o);return *this;}};
struct Record333 {
 int unk00,unk04,unk08,unk0c;
 Vector333 vec;
 int keys[3];
 float scalar;
 int value30,value34,unk38,unk3c;
 Record333(const Record333& other){Copy(other);}
 void Copy(const Record333& other){
  vec=other.vec;
  for(int k=0;k<3;++k)keys[k]=other.keys[k];
  scalar=other.scalar;value30=other.value30;value34=other.value34;
 }
 Record333& operator=(const Record333&other){Copy(other);return *this;}
 bool Greater(const Record333&other)const{
 for(int k=0;k<3;++k){int a=keys[k],b=other.keys[k];if(b<a)return true;if(b>a)return false;}return false;}
 bool operator<(const Record333&other)const{
  for(int k=0;k<3;++k){if(keys[k]<other.keys[k])return true;if(keys[k]>other.keys[k])return false;}return false;
 }
};
__forceinline void Swap333(Record333&a,Record333&b){Record333 temp=b;b=a;a=temp;}
// Recursively sorts a range of Record333 elements in base using the Hoare partition scheme with a midpoint pivot.
// @fnv 0x00d7af90
// src: GUESS 0x00d7af90 (confidence: medium)
void Hkgpconvexhull_SortRecordRange(Record333*apRecords,int aiLow,int aiHigh,int ctx){
 for(;;){
  int i=aiLow,j=aiHigh;
  Record333 pivot=apRecords[(aiLow+aiHigh)>>1];
  do{
   while(apRecords[i]<pivot)++i;
   while(apRecords[j].Greater(pivot))--j;
   if(j<i)break;
   if(j!=i){Swap333(apRecords[i],apRecords[j]);}
   --j;++i;
  }while(i<=j);
  if(aiLow<j)Hkgpconvexhull_SortRecordRange(apRecords,aiLow,j,ctx);
  if(i>=aiHigh)break;
  aiLow=i;
 }
}

struct D7ListNode {
    D7ListNode* n00;
    D7ListNode* n04;
    int u08; int u0c; int u10; int u14; int u18; int u1c;
    int u20; int u24; int u28; int u2c;
    int ref30;
    int DecRef() { --ref30; return ref30; }
};
struct D7Head {
    int h00; int h04; int h08;
    D7ListNode* h0c;
    int h10;
    int h14;
    void hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_release(void* p);
    void hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Triangle_32_struct_hkContainerHeapAllocator_release(void* p);
    void Remove(D7ListNode* e)
    {
        D7ListNode* nxt = e->n00;
        D7ListNode* prv = e->n04;
        if (nxt) nxt->n04 = prv;
        if (prv) prv->n00 = nxt;
        else h0c = nxt;
        --h10;
    }
};
struct D7Vec3 { int x; int y; int z; __int64 DotYZ(const D7Vec3& o) const { return (__int64)y * o.y + (__int64)z * o.z; } };
struct D7Node {
    D7ListNode* n00;
    D7ListNode* n04;
    D7ListNode* elems[3];
    int child[3];
    D7Vec3 v;
    int u2c;
    int lo30; int hi34;
    int u38; int u3c;
    int stamp40;
    __int64 Dist(const D7Node* a) const
    {
        return (__int64)v.x * a->v.x + a->v.DotYZ(v) + *(const __int64*)&lo30;
    }
};
struct D7Pair {
    D7Node* node;
    int idx;

    __forceinline D7Pair() {}
    __forceinline D7Pair(D7Node* n,int i):node(n),idx(i) {}
    __forceinline D7Pair Next() const { D7Pair n; n.node=node; n.idx=(9>>(idx*2))&3; return n; }
    __forceinline D7Pair Prev() const { D7Pair n; n.node=node; n.idx=(18>>(idx*2))&3; return n; }
    __forceinline D7Pair Adjacent() const {
        unsigned int p=node->child[idx];
        D7Pair n; n.idx=p&3; n.node=(D7Node*)(p&~3u); return n;
    }
    __forceinline void Unlink()
    {
        if (node->child[idx] & ~3) { D7Pair a = Adjacent(); a.node->child[a.idx] = 0; }
        node->child[idx] = 0;
    }
};
static __forceinline int D7Next(int i) { return (9 >> (i * 2)) & 3; }
static __forceinline int D7Prev(int i) { return (0x12 >> (i * 2)) & 3; }
struct D7Owner {
    int o00; int o04; int o08; int o0c; int o10; int o14;
    D7Head headA;
    D7Head headB;
    int o48;
    int o4c;
    int o50;
    int o54;
    int o58;
    int o5c;
    int o60;
    int o64;
    int o68;
    int o6c;
    int o70;
    int o74;
    int o78;
    int o7c;
    int o80;
    int o84;
    int o88;
    int o8c;
    int o90;
    int o94;
    int o98;
    int o9c;
    int oa0;
    int oa4;
    int oa8;
    int oac;
    int ob0;
    int ob4;
    int ob8;
    int obc;
    int oc0;
    int oc4;
    int oc8;
    int occ;
    int od0;
    int od4;
    int od8;
    int odc;
    int oe0;
    int oe4;
    int oe8;
    int oec;
    int of0;
    int of4;
    int of8;
    int ofc;
    int o100;
    int o104;
    int o108;
    int o10c;
    int o110;
    int o114;
    int o118;
    int o11c;
    int o120;
    int o124;
    int o128;
    int o12c;
    int o130;
    int o134;
    int o138;
    int o13c;
    int o140;
    int o144;
    int o148;
    int o14c;
    int o150;
    int o154;
    int o158;
    int o15c;
    int o160;
    int o164;
    int o168;
    int o16c;
    int o170;
    int o174;
    int o178;
    int o17c;
    int o180;
    int o184;
    int o188;
    int o18c;
    int o190;
    int o194;
    int o198;
    int o19c;
    int o1a0;
    int o1a4;
    int o1a8;
    int stamp1ac;
    void __thiscall hkgpConvexHullImpl_clearHorizon(D7Node* arg1, D7Pair* pair, D7Pair* out);
};
static __forceinline void UnlinkNode(D7Head* head, D7ListNode* nxt, D7ListNode* prv)
{
    if (nxt) nxt->n04 = prv;
    if (prv) prv->n00 = nxt;
    else head->h0c = nxt;
    --head->h10;
}
// Recursively visits adjacent pairs when Dist(arg1) is non-negative, unlinks and removes their nodes and elements, or copies the pair to out.
// @fnv 0x00d7c3e0
// src: HAVOK_LIB 0x00d7c3e0
void __thiscall D7Owner::hkgpConvexHullImpl_clearHorizon(D7Node* arg1, D7Pair* pair, D7Pair* apOutPair)
{
    if (!pair->node) return;
    if (pair->node->stamp40 == stamp1ac) return;
    pair->node->stamp40 = stamp1ac;
    if (pair->node->Dist(arg1) >= 0) {
        { D7Pair n=pair->Adjacent(); hkgpConvexHullImpl_clearHorizon(arg1,&n,apOutPair); }
        { D7Pair n=pair->Next().Adjacent(); hkgpConvexHullImpl_clearHorizon(arg1,&n,apOutPair); }
        { D7Pair n=pair->Prev().Adjacent(); hkgpConvexHullImpl_clearHorizon(arg1,&n,apOutPair); }
        pair->Unlink();
        pair->Next().Unlink();
        pair->Prev().Unlink();
        D7Node* pNode = pair->node;
        for (int i = 0; i < 3; i++) {
            D7ListNode* o = pNode->elems[i];
            pNode->elems[i]->ref30--;
            if (o->ref30 == 0) {
                D7ListNode* e = pNode->elems[i];
                headA.Remove(e);
                headA.hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_release(e);
            }
        }
        headB.Remove((D7ListNode*)pNode);
        headB.hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Triangle_32_struct_hkContainerHeapAllocator_release(pNode);
    } else {
        *apOutPair = *pair;
    }
}

struct hkgpVertex {
    hkgpVertex* m_next;
    int m_flag;
    int unk08, unk0c, unk10, unk14, unk18;
    int m_uiEdgeIndex;
    int m_uiX[3];
};

struct hkgpTriangle {
    hkgpTriangle* m_next;
    hkgpTriangle* m_pSecondNode;
    hkgpVertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
};

static inline unsigned int HKGP_NEXT(unsigned int i) { return (9 >> (i << 1)) & 3; }

static __forceinline bool isGreater(const hkgpVertex* a, const hkgpVertex* b)
{
    for (int k = 0; k < 3; ++k)
    {
        if (a->m_uiX[k] < b->m_uiX[k]) return false;
        if (a->m_uiX[k] > b->m_uiX[k]) return true;
    }
    return false;
}

static __forceinline bool isGreaterB(const hkgpVertex* a, const hkgpVertex* b)
{
    for (int k = 0; k < 3; ++k)
    {
        const int& bv = b->m_uiX[k];
        const int& av = a->m_uiX[k];
        if (av < bv) return false;
        if (av > bv) return true;
    }
    return false;
}

struct hkgpEdge {
    hkgpTriangle* m_pkTriangle;
    unsigned int m_uiEdgeIndex;

    hkgpEdge() {}
    hkgpEdge(hkgpTriangle* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    hkgpEdge next() const { return hkgpEdge(m_pkTriangle, HKGP_NEXT(m_uiEdgeIndex)); }
    hkgpVertex* start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    hkgpVertex* end() const { return m_pkTriangle->m_kVertices[HKGP_NEXT(m_uiEdgeIndex)]; }
    bool isNaked() const { return (m_pkTriangle->m_ppLinks[m_uiEdgeIndex] & ~3u) == 0; }
    __forceinline bool isCanonical() const { return !isGreater(start(), end()) || isNaked(); }
    __forceinline bool isCanonicalB() const { return !isGreaterB(start(), end()) || isNaked(); }
};

struct FUN_00d7c970_cls {
    hkgpEdge m_kEdge;
    void hkgpAbstractMesh_struct_hkgpConvexHullImpl_Edge_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHullImpl_Triangle_struct_hkContainerHeapAllocator_EdgeIterator_next();
};

// Advances m_kEdge through triangle edges until a canonical edge is found, returning when one is located.
// @fnv 0x00d7c970
// src: HAVOK_LIB 0x00d7c970
void FUN_00d7c970_cls::hkgpAbstractMesh_struct_hkgpConvexHullImpl_Edge_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHullImpl_Triangle_struct_hkContainerHeapAllocator_EdgeIterator_next()
{
    while (m_kEdge.m_pkTriangle)
    {
        do { m_kEdge = m_kEdge.next(); } while (m_kEdge.m_uiEdgeIndex != 0 && !m_kEdge.isCanonical());
        if (m_kEdge.m_uiEdgeIndex != 0 && m_kEdge.isCanonicalB()) return;
        m_kEdge = hkgpEdge(m_kEdge.m_pkTriangle->m_next, 0);
        if (m_kEdge.m_pkTriangle && m_kEdge.isCanonicalB()) return;
    }
}

struct HullVertex {
    HullVertex* m_pSecondNode;
    HullVertex* m_next;
    int m_unk08;
    int m_unk0c;
    float m_sx;
    float m_sy;
    float m_sz;
    float m_sw;
    int m_uiX[3];
};
struct HullTriangle {
    HullTriangle* m_next;
    HullTriangle* m_pSecondNode;
    HullVertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
};
static inline int nextIndex(int i) { return (9 >> (i << 1)) & 3; }
static __forceinline bool greater(const HullVertex* a, const HullVertex* b)
{
    for (int i = 0; i < 3; ++i) {
        if (a->m_uiX[i] < b->m_uiX[i]) return false;
        if (a->m_uiX[i] > b->m_uiX[i]) return true;
    }
    return false;
}
static __forceinline bool less(const HullVertex* a, const HullVertex* b)
{
    for (int i = 0; i < 3; ++i) {
        if (b->m_uiX[i] < a->m_uiX[i]) return false;
        if (b->m_uiX[i] > a->m_uiX[i]) return true;
    }
    return false;
}
struct HullEdge {
    HullTriangle* m_pkTriangle;
    int m_uiEdgeIndex;
    HullEdge() {}
    HullEdge(HullTriangle* t, int i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    HullEdge next() const { return HullEdge(m_pkTriangle, nextIndex(m_uiEdgeIndex)); }
    HullVertex* start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    HullVertex* end() const { return m_pkTriangle->m_kVertices[nextIndex(m_uiEdgeIndex)]; }
    bool isNaked() const { return (m_pkTriangle->m_ppLinks[m_uiEdgeIndex] & ~3u) == 0; }
    __forceinline bool isCanonical() const { return !greater(start(), end()) || isNaked(); }
    __forceinline bool isCanonicalL() const { return !less(end(), start()) || isNaked(); }
};
struct HullEdgeIterator {
    HullEdge m_kEdge;
    HullEdgeIterator(HullEdge e);
    void hkgpAbstractMesh_struct_hkgpConvexHullImpl_Edge_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHullImpl_Triangle_struct_hkContainerHeapAllocator_EdgeIterator_next();
};
// Constructs a HullEdgeIterator from a HullEdge, calling FUN_00d7c970 if the edge has a triangle and is not canonical.
// @fnv 0x00d7d220
HullEdgeIterator::HullEdgeIterator(HullEdge akEdge) : m_kEdge(akEdge)
{
    if (m_kEdge.m_pkTriangle && !m_kEdge.isCanonical()) hkgpAbstractMesh_struct_hkgpConvexHullImpl_Edge_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHullImpl_Triangle_struct_hkContainerHeapAllocator_EdgeIterator_next();
}

#include <windows.h>
struct S_00d7f6a0_Head {
    char m0;
    float m4;
    char m8, m9, mA, mB, mC, mD;
    S_00d7f6a0_Head();
};


template <int N> struct S_00d7f6a0_Pool {
    hkArrayBase<void*> m_items;
    int m_iThirdValue;
    int m_10;
    int m_14;
    S_00d7f6a0_Pool() : m_iThirdValue(0), m_10(0) {}
};

struct S_00d7f6a0_RefObj {
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    S_00d7f6a0_RefObj() { m_sReferenceCount = 1; }
    virtual ~S_00d7f6a0_RefObj() throw();
};

struct S_00d7f6a0_Inner : S_00d7f6a0_RefObj {
    S_00d7f6a0_Pool<0x808> m_kPointA;
    S_00d7f6a0_Pool<0x908> m_kPointB;
    S_00d7f6a0_Inner() {}
    virtual ~S_00d7f6a0_Inner() throw();
};

static long s_nextId;

struct FUN_00d7f6a0 : S_00d7f6a0_Head {
    S_00d7f6a0_Inner m_inner;
    hkArrayBase<int> m_iThirdValue;
    hkArrayBase<int> m_iFourthElementInteger;
    hkArrayBase<int> m_usTrailingValue;
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
    long m_iOwnerObjectOffset;
    FUN_00d7f6a0();
    void Reset(int) throw();
};

// Assigns InterlockedExchangeAdd on s_nextId to m_iOwnerObjectOffset, then calls Reset(0).
// @fnv 0x00d7f6a0
FUN_00d7f6a0::FUN_00d7f6a0()
{
    m_iOwnerObjectOffset = InterlockedExchangeAdd(&s_nextId, 1);
    Reset(0);
}

struct S76320_Node {
    S76320_Node* m_next;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_uiFilterValue;
};

struct S76320_Sorter {
    int unk00;
};

void __cdecl hkGeometryProcessing_buildTransposedArray(hkArrayBase<hkVector4>* points, S76320_Sorter* sorter);
void __cdecl hkVector4_FindSupportingVertex(S76320_Sorter* sorter, int a1, int a2);

struct S76320_Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    S76320_Node* m_kNode;
    int m_uiItemCount;
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
    S76320_Sorter m_sorter;
    int m_built;
};

struct S76320_Cls {
    int unk00;
    int unk04;
    S76320_Owner* m_pOwnerObject;
    void ProcessEntries_00d76320(int a1, int a2);
};

// Collects node vectors into a temporary array, sorts them via m_sorter, frees the array, then calls FUN_00dea810 with a1 and a2.
// @fnv 0x00d76320
// src: GUESS 0x00d76320 (confidence: low)
void S76320_Cls::ProcessEntries_00d76320(int a1, int a2)
{
    S76320_Owner* owner = m_pOwnerObject;
    if (owner->m_built == 0) {
        hkArrayBase<hkVector4> points;
        points.m_data = 0;
        points.m_iElementCount = 0;
        points.m_iCapacityState = 0x80000000;
        hkVector4* dst = ExpandHullVectors(points, owner->m_uiItemCount);
        for (S76320_Node* node = owner->m_kNode; node; node = node->m_next) {
            *dst++ = node->m_uiFilterValue;
        }
        hkGeometryProcessing_buildTransposedArray(&points, &owner->m_sorter);
        hkMemoryAllocator& alloc = getHavokMonitorStream().heap();
        points.m_iElementCount = 0;
        if ((points.m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(points.m_data, (points.m_iCapacityState & 0x3fffffff) * sizeof(hkVector4));
        points.m_data = 0;
        points.m_iCapacityState = 0x80000000;
    }
    hkVector4_FindSupportingVertex(&owner->m_sorter, a1, a2);
}

extern const float DAT_01012054;
extern const float DAT_0106c288;
extern const char str_010d3574[];

struct SplitObject {
    virtual ~SplitObject();
    int unk04;
    ChildData* data;
    int hkgpConvexHull_getNumPlanes();
    const hkVec4& hkgpConvexHull_getPlane(int);
    __declspec(noinline) int GetInnerField1A8();
    int ForwardCall_00d762f0();
    float hkgpConvexHull_getVolume();
};
// src: GUESS 0x00d74e10 (confidence: medium)
__declspec(noinline) int SplitObject::GetInnerField1A8() { return data->unk1a8; }
struct PlaneSplitter {
    int hkgpConvexHull_splitByPlane(const hkVec4&,SplitObject*&,SplitObject*&,float);
};
struct PairPredicate {
    virtual void v0();
    virtual bool* test(bool*,SplitObject**,int);
};
SplitObject* CallWithPair(int,SplitObject*,SplitObject*);
union SplitWorkspace { void* stream[sizeof(hkErrStream) / sizeof(void*)]; SplitObject* pair[2]; };

static __forceinline void CheckSplitIndex(SplitObject* source,hkErrStream& stream) {
    ChildData* data=source->data;
    if(!data->flag1b5) {
        unsigned int buffer[128];
        new(&stream) hkErrStream(buffer,512);
        stream.hkOstream::operator<<(str_010d3574) << static_cast<unsigned int>(data->unk1b0) << &DAT_0103d078;
        if(DAT_01268360->message(3,0x79f9d886,(char*)buffer,str_010d3540,0x148)) __debugbreak();
        stream.hkOstream::~hkOstream();
    }
}
// Iterates source planes, splits with splitter, keeps the pair with the highest score that passes predicate, returning the best score.
// @fnv 0x00d79850
// src: HAVOK_LIB 0x00d79850
float hkgpConvexHull_findBestUnion(SplitObject* source,PlaneSplitter* splitter,PairPredicate* predicate,SplitObject*& outFirst,SplitObject*& outSecond)
{
    float best=-1.0f;
    outFirst=0;
    outSecond=0;
    SplitWorkspace workspace;
    CheckSplitIndex(source,*reinterpret_cast<hkErrStream*>(workspace.stream));
    for(int i=0;i<source->hkgpConvexHull_getNumPlanes();++i) {
        const hkVec4* __restrict src=&source->hkgpConvexHull_getPlane(i);
        hkVec4 plane=*src;
        SplitObject* pFirst;
        SplitObject* pSecond;
        int result=splitter->hkgpConvexHull_splitByPlane(plane,pFirst,pSecond,DAT_0106c288);
        SplitObject* second=*(SplitObject* volatile*)&pSecond;
        SplitObject* first=*(SplitObject* volatile*)&pFirst;
        if(result==3 && first && second && first->GetInnerField1A8()==3 && second->GetInnerField1A8()==3 && !second->ForwardCall_00d762f0() && second->hkgpConvexHull_getVolume()>best && !first->ForwardCall_00d762f0()) {
            SplitObject* combined=CallWithPair(0,*(SplitObject* volatile*)&source,second);
            if(combined) {
                if(combined->GetInnerField1A8()==3 && !combined->ForwardCall_00d762f0()) {
                    workspace.pair[0]=combined;
                    workspace.pair[1]=first;
                    bool accepted;
                    if(*predicate->test(&accepted,workspace.pair,2)) {
                        delete outFirst;
                        delete outSecond;
                        best=second->hkgpConvexHull_getVolume();
                        outFirst=combined;
                        outSecond=first;
                        pFirst=0;
                        goto cleanupSecond;
                    }
                }
                delete combined;
            }
        }
        if(first) delete first;
cleanupSecond:
        if(second) delete second;
    }
    return best;
}

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_move_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ps(float*, __m128);

extern float DAT_01011d78;
extern float DAT_0104da48;
extern float DAT_0104e148;
extern __m128 DAT_01267e30;
extern __m128 DAT_01268370;
extern __m128 DAT_01268380;
extern __m128 DAT_01268390;
extern __m128 DAT_012683a0;
void* __cdecl FUN_00cd4b50();

struct FUN_00d7ac40_sub {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
};

__declspec(align(16)) struct FUN_00d7ac40_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d7ac40_sub m_10;
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
    int m_4c;
    int unk50;
    int unk54;
    int m_58;
    int unk5c;
    int unk60;
    int m_64;
    int unk68;
    int unk6c;
    __m128 m_70;
    __m128 m_80;
    __m128 m_90;
    __m128 m_a0;
    __m128 m_b0;
    __m128 m_c0;
    __m128 m_d0;
    __m128 m_e0;
    __m128 m_f0;
    __m128 m_100;
    __m128 m_110;
    __m128 m_120;
    __m128 m_130;
    __m128 m_140;
    __m128 m_150;
    __m128 m_160;
    __m128 m_170;
    __m128 m_180;
    __m128 m_190;
    float m_1a0;
    float m_1a4;
    int m_1a8;
    int m_1ac;
    int unk1b0;
    unsigned char m_1b4;
    unsigned char m_1b5;
    int unk1b6;

    void __thiscall hkgpConvexHullImpl_reset(unsigned char flag);
};

// Calls m_10.v0c(), clears several fields, and initializes vectors from constants and data returned by FUN_00cd4b50().
// @fnv 0x00d7ac40
// src: XBOX_PDB 0x00d7ac40
void FUN_00d7ac40_cls::hkgpConvexHullImpl_reset(unsigned char flag)
{
    m_10.v0c();
    __m128 vDefault = _mm_setr_ps(DAT_01011d78, DAT_01011d78, DAT_01011d78, DAT_0104da48);
    __m128 bScalar = _mm_load_ss(&DAT_0104da48);
    m_58 = 0;
    m_4c = 0;
    m_64 = 0;
    m_1b4 = 0;
    m_1b5 = 0;
    m_1ac = 0;
    _mm_store_ps((float*)&m_70, vDefault);
    _mm_store_ps((float*)&m_80, vDefault);
    __m128 tShuffle = _mm_move_ss(vDefault, bScalar);
    __m128 cScalar = _mm_load_ss(&DAT_0104e148);
    __m128 vb = _mm_shuffle_ps(tShuffle, tShuffle, 0);
    __m128 vc = _mm_shuffle_ps(cScalar, cScalar, 0);
    _mm_store_ps((float*)&m_90, vb);
    _mm_store_ps((float*)&m_a0, vc);
    _mm_store_ps((float*)&m_b0, vb);
    _mm_store_ps((float*)&m_c0, vc);
    m_120 = DAT_01268370;
    m_130 = DAT_01268380;
    m_140 = DAT_01268390;
    m_150 = DAT_012683a0;
    m_160 = DAT_01267e30;
    float z = 0.0f;
    char* p = (char*)FUN_00cd4b50();
    m_170 = *(__m128*)p;
    m_180 = *(__m128*)(p + 0x10);
    m_190 = *(__m128*)(p + 0x20);
    __m128 zz = DAT_01267e30;
    m_1a0 = z;
    m_1a4 = z;
    m_d0 = zz;
    m_1a8 = -1;
    m_100 = DAT_01267e30;
    m_110 = DAT_01267e30;
    m_f0 = DAT_01267e30;
    if (!flag) {
        m_e0 = DAT_01267e30;
    }
}

extern "C" void _ReadWriteBarrier(void);

struct S_00d790d0_Item {
    virtual ~S_00d790d0_Item();
    void ForwardCall_00d762f0();
    int UpdateFields_00d756a0(hkVector4* v, S_00d790d0_Item** a, S_00d790d0_Item** b, float f);
    int hkgpConvexHull_splitByPlane(int r);
};

struct S_00d790d0_Pair {
    S_00d790d0_Item* a;
    S_00d790d0_Item* b;
};

template <typename T>
static __forceinline void AppendHullItem(hkArrayBase<T*>& array, T* value)
{
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    if (array.m_iElementCount == (array.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(router->m_heap, &array, sizeof(T*));
    T** p = array.m_data + array.m_iElementCount;
    for (int k = 0; k < 1; k++) p[k] = value;
    array.m_iElementCount++;
}

template <typename T>
static __forceinline void AppendHullItemRef(hkArrayBase<T*>& array, T*& value)
{
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    if (array.m_iElementCount == (array.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(router->m_heap, &array, sizeof(T*));
    T** p = array.m_data + array.m_iElementCount;
    for (int k = 0; k < 1; k++) p[k] = value;
    array.m_iElementCount++;
}

template <typename T>
__forceinline void hkArrayBase<T>::removeAt(int i)
{
    m_iElementCount--;
    if (m_iElementCount != i) m_data[i] = m_data[m_iElementCount];
}

// S_00d790d0_Item* FUN_00d76cf0();

// Repeats the array traversal count times and replaces an item with two outputs when the result is 3 and both outputs are nonnull.
// @fnv 0x00d790d0
// src: HAVOK_LIB 0x00d790d0
void __stdcall hkgpConvexHull_subdivide(int aiSteps, hkArrayBase<S_00d790d0_Item*>* apItems, float afParam) {
    __declspec(align(16)) hkVector4 v;
    S_00d790d0_Pair vPair;
    S_00d790d0_Item* a;
    apItems->m_iElementCount = 0;
    AppendHullItem(*apItems, (S_00d790d0_Item*)hkgpConvexHull_clone());
    int n;
    if (aiSteps > 0) {
        n = aiSteps;
        do {
            for (int i = 0, sz = apItems->m_iElementCount; i < sz; i++) {
                S_00d790d0_Item* e = apItems->m_data[i];
                e->ForwardCall_00d762f0();
                int res = e->UpdateFields_00d756a0(&v, &vPair.a, &vPair.b, afParam);
                int r = e->hkgpConvexHull_splitByPlane(res);
                if (r == 3) {
                    a = vPair.a;
                    _ReadWriteBarrier();
                    if (a && vPair.b) {
                        AppendHullItem(*apItems, a);
                        AppendHullItemRef(*apItems, vPair.b);
                        apItems->removeAt(i);
                        delete e;
                    } else {
                        delete a;
                        delete vPair.b;
                    }
                }
            }
        } while (--n != 0);
    }
}

namespace fnv_00d74f10 {
extern "C" void __cdecl __debugbreak();
extern const char DAT_010d3574[];
extern const char DAT_0103d078[];
extern const char DAT_010d3540[];

extern hkError* DAT_01268360;

struct FUN_00d74f10_class {
    int unk00;
    int unk04;
    char* item08;
    int hkgpConvexHull_getNumPlanes();
};
// If the node flag at offset 0x1b5 is clear, builds a buffer and calls a service method, then returns the int at offset 0x58 of item08.
// @fnv 0x00d74f10
// src: HAVOK_LIB 0x00d74f10
int FUN_00d74f10_class::hkgpConvexHull_getNumPlanes() {
    char* node = item08;
    void* storage[128];
    void* streamStorage[sizeof(hkErrStream) / sizeof(void*)];
    hkErrStream& b = *reinterpret_cast<hkErrStream*>(streamStorage);
    if (!node[0x1b5]) {
        new(&b) hkErrStream(storage, 512);
        b.hkOstream::operator<<(DAT_010d3574) << *reinterpret_cast<unsigned int*>(node + 0x1b0) << DAT_0103d078;
        int iResult = DAT_01268360->message(3,0x79f9d886,(char*)storage,DAT_010d3540,0x148);
        if (iResult != 0) __debugbreak();
        b.hkOstream::~hkOstream();
    }
    return *(int*)(item08 + 0x58);
}
}  // namespace fnv_00d74f10

namespace fnv_00d74fb0 {
extern const char str_010d3574[];
extern const char str_010d3540[];
extern const char DAT_0103d078[];

extern hkError* DAT_01268360;
struct S_00d74fb0_Inner {
    char pad[0x54];
    char* unk54;
    char pad2[0x1b0 - 0x58];
    int unk1b0;
    char pad3[0x1b5 - 0x1b4];
    char unk1b5;
};
struct S_00d74fb0_Obj {
    int unk00, unk04;
    S_00d74fb0_Inner* unk08;
    char* hkgpConvexHull_getPlane(unsigned int idx);
};
// If the inner object's flag is clear, reports a message using its value, then returns a pointer into its data at idx * 16.
// @fnv 0x00d74fb0
// src: HAVOK_LIB 0x00d74fb0
char* S_00d74fb0_Obj::hkgpConvexHull_getPlane(unsigned int uiIndex)
{
    S_00d74fb0_Inner* p = unk08;
    if (!p->unk1b5) {
        unsigned int buf[128];
        void* streamStorage[sizeof(hkErrStream) / sizeof(void*)];
        new(streamStorage) hkErrStream(buf, 0x200);
        hkErrStream& s = *reinterpret_cast<hkErrStream*>(streamStorage);
        s.hkOstream::operator<<(str_010d3574) << static_cast<unsigned int>(p->unk1b0) << DAT_0103d078;
        if (DAT_01268360->message(3, 0x79f9d886, (const char*)buf, str_010d3540, 0x148))
            __debugbreak();
        s.hkOstream::~hkOstream();
    }
    return unk08->unk54 + (uiIndex << 4);
}
}  // namespace fnv_00d74fb0

namespace fnv_00d75560 {
struct SubObject_cls {
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
    int m_1b0;
    unsigned char m_1b4;
};

struct FUN_00d75560_cls;

extern hkError* DAT_01268360;
extern char DAT_0103d078;
extern char str_010d358c;
extern char str_010d3540;

extern "C" void __debugbreak();

struct FUN_00d75560_cls {
    unsigned int unk00;
    unsigned int unk04;
    SubObject_cls* m_08;

    void* hkgpConvexHull_getWorldInertia();
};

// If sub->m_1b4 is zero, builds a log string from sub->m_1b0 and writes it via DAT_01268360, then returns a pointer to m_08 + 0x170.
// @fnv 0x00d75560
// src: HAVOK_LIB 0x00d75560
void* FUN_00d75560_cls::hkgpConvexHull_getWorldInertia()
{
    SubObject_cls* sub = m_08;
    if (sub->m_1b4 == 0) {
        void* streamStorage[sizeof(hkErrStream) / sizeof(void*)];
        hkErrStream& sb = *reinterpret_cast<hkErrStream*>(streamStorage);
        unsigned int buf[0x80];
        new(&sb) hkErrStream(buf, 0x200);
        sb.hkOstream::operator<<(&str_010d358c) << static_cast<unsigned int>(sub->m_1b0) << &DAT_0103d078;
        if (DAT_01268360->message(3, 0x79f9d887, reinterpret_cast<const char*>(buf), &str_010d3540, 0x14e) != 0) {
            __debugbreak();
        }
        sb.hkOstream::~hkOstream();
    }
    return (char*)m_08 + 0x170;
}
}  // namespace fnv_00d75560

namespace fnv_00d75600 {
extern const char str_010d358c[];
extern const char str_010d3540[];
extern const char DAT_0103d078[];

extern hkError* DAT_01268360;
struct S_00d75600_Inner {
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
};
struct S_00d75600_Obj {
    int unk00, unk04;
    S_00d75600_Inner* unk08;
    int* hkgpConvexHull_getCenterOfMass();
};
// If the inner object's unk1b4 flag is clear, formats a debug message and reports it via DAT_01268360, then returns a pointer to the inner object's unk150 field.
// @fnv 0x00d75600
// src: HAVOK_LIB 0x00d75600
int* S_00d75600_Obj::hkgpConvexHull_getCenterOfMass()
{
    S_00d75600_Inner* p = unk08;
    if (!p->unk1b4) {
        unsigned int buf[128];
        void* streamStorage[sizeof(hkErrStream) / sizeof(void*)];
        new(streamStorage) hkErrStream(buf, 0x200);
        hkErrStream& s = *reinterpret_cast<hkErrStream*>(streamStorage);
        s.hkOstream::operator<<(str_010d358c) << static_cast<unsigned int>(p->unk1b0) << DAT_0103d078;
        if (DAT_01268360->message(3, 0x79f9d887, (const char*)buf, str_010d3540, 0x14e))
            __debugbreak();
        s.hkOstream::~hkOstream();
    }
    return &unk08->unk150;
}
}  // namespace fnv_00d75600

namespace fnv_00d76940 {
extern int DAT_010d36e0;
extern int DAT_0102e388;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00d7ce20_cls {
    void FUN_00d7ce20();
};

struct FUN_00d76940_member {
    virtual void vDtor(unsigned int auiFlags);
};

struct FUN_00d76940_cls {
    int m_vptr;
    int unk04;
    FUN_00d7ce20_cls* m_08;
    int unk0c;
    FUN_00d76940_member* m_10;

    void ReleaseStorage_00d76940();
};

// Destroys the object by releasing m_08 via the audio allocator and calling vDtor on m_10, then nulls m_10 and updates the vtable pointer.
// @fnv 0x00d76940
// src: GUESS 0x00d76940 (confidence: medium)
void FUN_00d76940_cls::ReleaseStorage_00d76940()
{
    m_vptr = (int)&DAT_010d36e0;
    FUN_00d7ce20_cls* pObj = m_08;
    if (pObj != 0) {
        pObj->FUN_00d7ce20();
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        reinterpret_cast<hkMemoryAllocator*>(pAllocator)->blockFree(pObj, 0x1c0);
    }
    FUN_00d76940_member* pMember = m_10;
    if (pMember != 0) {
        pMember->vDtor(1);
    }
    m_10 = 0;
    m_vptr = (int)&DAT_0102e388;
}
}  // namespace fnv_00d76940

namespace fnv_00d76ca0 {

hkMemoryRouter* hkMemoryRouter_getInstance();

struct S_00d76ca0_Inner {
    S_00d76ca0_Inner* FUN_00d7f6a0();
};

struct __declspec(novtable) S_00d76ca0_Base {
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00d76ca0_Base() { m_sReferenceCount = 1; }
    virtual void vf0() {}
};

struct FUN_00d76ca0 : S_00d76ca0_Base {
    S_00d76ca0_Inner* m08;
    int m0c;
    int m10;
    FUN_00d76ca0();
};

// Requests a 0x1c0-byte block from the router heap, stores the result of FUN_00d7f6a0() when nonnull, and zeros m0c and m10.
// @fnv 0x00d76ca0
FUN_00d76ca0::FUN_00d76ca0() {
    hkMemoryAllocator& h = hkMemoryRouter_getInstance()->heap();
    void* p = h.blockAlloc(0x1c0);
    m08 = p ? ((S_00d76ca0_Inner*)p)->FUN_00d7f6a0() : 0;
    m0c = 0;
    m10 = 0;
}
}  // namespace fnv_00d76ca0

namespace fnv_00d76cf0 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct D76Iface {
    virtual void v00();
    virtual void* v04();
};

struct D76Sub {
    int unk00;
    void* AllocateAndProcessEntries_00d7f720();
};

struct D76Old {
    int unk00;
    void FUN_00d7ce20();
};

struct D76Child {
    int unk00;
    unsigned short m_04;
    void* m_08;
    int m_0c;
    void* m_10;
    D76Child* FUN_00d76ca0();
};

struct FUN_00d76cf0_cls {
    int unk00;
    unsigned short unk04;
    void* m_08;
    int m_0c;
    void* m_10;

    D76Child* hkgpConvexHull_clone();
};

// Allocates a D76Child, releases its existing m_08 object, then initializes m_08, m_0c, and m_10 from source fields.
// @fnv 0x00d76cf0
// src: HAVOK_LIB 0x00d76cf0
D76Child* FUN_00d76cf0_cls::hkgpConvexHull_clone()
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = (hkMemoryAllocator*)pHolder->m_heap;
    D76Child* pNew = (D76Child*)pAllocator->blockAlloc(0x14);
    pNew->m_04 = 0x14;
    pNew = pNew->FUN_00d76ca0();
    D76Old* pOld = (D76Old*)pNew->m_08;
    if (pOld != 0) {
        pOld->FUN_00d7ce20();
        hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = (hkMemoryAllocator*)pHolder2->m_heap;
        pAllocator2->blockFree(pOld, 0x1c0);
    }
    pNew->m_08 = 0;
    pNew->m_08 = ((D76Sub*)m_08)->AllocateAndProcessEntries_00d7f720();
    pNew->m_0c = m_0c;
    void* pVal;
    if (m_10 != 0) {
        pVal = ((D76Iface*)m_10)->v04();
    } else {
        pVal = 0;
    }
    pNew->m_10 = pVal;
    return pNew;
}
}  // namespace fnv_00d76cf0

struct TriangleVertex {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30;
    int m_uiEdgeIndex; // 0x34
};

struct Triangle {
    Triangle* m_next;
    int unk04;
    TriangleVertex* m_kVertices[3];
};

void __cdecl hkArrayUtil__reserve(void* alloc, void* array, int newCap, int elemSize) throw();


inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return getHavokMonitorStream().heap();
}

template <typename T>
__forceinline void hkArrayUtil::destruct(T* p, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; ++i) {
        p[i].~T();
    }
}

template <typename T>
__forceinline void hkArrayUtil::construct(T* p, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; ++i) {
        new ((void*)(p + i)) T;
    }
}

template <typename T>
__forceinline void hkArrayBase<T>::clear()
{
    hkArrayUtil::destruct(m_data, m_iElementCount, hkTypeIsClass());
    m_iElementCount = 0;
}

template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0) {
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    }
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    clearAndDeallocate();
}

template <typename T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int cap = getCapacity();
    if (cap < n) {
        int cap2 = 2 * cap;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(static_cast<void*>(&alloc), this, newSize, sizeof(T));
    }
}

template <typename T>
__forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    hkArrayUtil::destruct(m_data + n, m_iElementCount - n, hkTypeIsClass());
    hkArrayUtil::construct(m_data + m_iElementCount, n - m_iElementCount, hkTypeIsClass());
    m_iElementCount = n;
}

template <typename T>
static __forceinline void AppendHullIndex(hkArrayBase<T>& array, const T& t) throw()
{
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    if (array.m_iElementCount == (array.m_iCapacityState & 0x3fffffff)) {
        ResizeAudioStream(router->m_heap, &array, sizeof(T));
    }
    T* p = array.m_data + array.m_iElementCount;
    __assume(p != 0);
    new ((void*)p) T(t);
    array.m_iElementCount++;
}

struct GraphEdgeBase {
    Triangle* face;
    int corner;
    __forceinline GraphEdgeBase(Triangle* f, int c) : face(f), corner(c) {}
    __forceinline TriangleVertex*& start() const { return face->m_kVertices[corner]; }
    __forceinline TriangleVertex*& end() const { return face->m_kVertices[(9 >> (corner << 1)) & 3]; }
};
struct GraphEdge : GraphEdgeBase {
    __forceinline GraphEdge(Triangle* f, int c) : GraphEdgeBase(f,c) {}
    __forceinline GraphEdge(const GraphEdge& other) : GraphEdgeBase(other.face,other.corner) {}
};
struct HkHull : ChildData {
    void hkgpConvexHullImpl_generateVertexAdjacencyGraph(hkArray<int>& indices, hkArray<int>& offsets);
};

// Builds adjacency lists from triangle edges, then flattens each list into indices and records its starting offset.
// @fnv 0x00d80f90
// src: HAVOK_LIB 0x00d80f90
void HkHull::hkgpConvexHullImpl_generateVertexAdjacencyGraph(hkArray<int>& indices, hkArray<int>& offsets) {
    if (!this->flag1b5) {
        unsigned int buffer[128];
        void* streamStorage[sizeof(hkErrStream) / sizeof(void*)];
        hkErrStream& stream = *reinterpret_cast<hkErrStream*>(streamStorage);
        new(&stream) hkErrStream(buffer, 512);
        stream.hkOstream::operator<<("No index available (") << static_cast<unsigned int>(this->unk1b0) << &DAT_0103d078;
        if (DAT_01268360->message(3, 0x79f9d886, (const char*)buffer, ".\\GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp", 328)) {
            fnv_Breakpoint();
        }
        stream.hkOstream::~hkOstream();
    }

    void* linksStorage[sizeof(hkArray<hkArray<int> >) / sizeof(void*)];
    hkArray<hkArray<int> >& links = *reinterpret_cast<hkArray<hkArray<int> >*>(linksStorage);
    new (&links) hkArray<hkArray<int> >;
        links.setSize(this->unk028);

        for (Triangle* tri = (Triangle*)this->unk03c; tri != 0; tri = tri->m_next) {
            for (int i = 0; i < 3; ++i) {
                GraphEdge edge(tri,i);
                hkArray<int>& list = links[edge.start()->m_uiEdgeIndex];
                AppendHullIndex(list, edge.end()->m_uiEdgeIndex);
            }
        }

        indices.m_iElementCount = 0;
        indices.reserve(3 * this->unk040 + this->unk028);
        offsets.setSize(this->unk028);

        int i = 0;
        int offset = 0;
        for (; i < links.m_iElementCount; ++i) {
            int count = links[i].m_iElementCount;
            AppendHullIndex(indices, count);
            for (int j = 0; j < links[i].m_iElementCount; ++j) {
                AppendHullIndex(indices, links[i][j]);
            }
            offsets[i] = offset;
            offset += links[i].m_iElementCount + 1;
        }
    links.clearAndDeallocate();
}


bool __cdecl hkgpConvexHull_booleanSubtraction(S_00d79f90_Result*, S_00d79f90_Result*, hkArray<S_00d79f90_Result*>*, float);
static __forceinline bool splitPiece(S_00d79f90_Result* const& a, S_00d79f90_Result* const& b, hkArray<S_00d79f90_Result*>& out, float eps) {
    out.m_iElementCount = 0;
    return hkgpConvexHull_booleanSubtraction(a, b, &out, eps);
}
static __forceinline void releasePiece(S_00d79f90_Result* item) {
    if (item)
        ((FUN_00d79510_Item*)item)->FUN_00d79510_doIt(1);
}
// Splits the world's initial piece against each input piece, collecting surviving sub-pieces into output and returning whether any remain.
// @fnv 0x00d79580
// src: HAVOK_LIB 0x00d79580
bool __cdecl hkgpConvexHull_booleanSubtraction_00d79580(S_00d79f90_World* world, hkArray<S_00d79f90_Result*>* inputs, hkArray<S_00d79f90_Result*>* output, float afEpsilon) {
    void* currentStorage[sizeof(hkArray<S_00d79f90_Result*>) / sizeof(void*)];
    void* nextStorage[sizeof(hkArray<S_00d79f90_Result*>) / sizeof(void*)];
    void* piecesStorage[sizeof(hkArray<S_00d79f90_Result*>) / sizeof(void*)];
    hkArray<S_00d79f90_Result*>& current = *new (currentStorage) hkArray<S_00d79f90_Result*>;
    hkArray<S_00d79f90_Result*>& next = *new (nextStorage) hkArray<S_00d79f90_Result*>;
    hkArray<S_00d79f90_Result*>& pieces = *new (piecesStorage) hkArray<S_00d79f90_Result*>;
    S_00d79f90_Result* pInitialPiece = world->hkgpConvexHull_clone();
    AppendHullIndex(current, pInitialPiece);
    for (int i = 0; i < inputs->m_iElementCount; ++i) {
        int count = current.m_iElementCount;
        for (int j = 0; j < count; ++j) {
            if (splitPiece(current.m_data[j], inputs->m_data[i], pieces, afEpsilon)) {
                releasePiece(current.m_data[j]);
                for (int k = 0; k < pieces.m_iElementCount; ++k) {
                    AppendHullIndex(next, pieces.m_data[k]);
                    void (FUN_00d76990_Class::*setValue)(float, bool) = &FUN_00d76990_Class::SetValue;
                    (((FUN_00d76990_Class*)pieces.m_data[k])->*setValue)(0.9999f, false);
                }
            } else {
                AppendHullIndex(next, current.m_data[j]);
            }
        }
        current.swap(next);
        next.m_iElementCount = 0;
    }
    for (int i = 0; i < current.m_iElementCount; ++i)
        AppendHullIndex(*output, current.m_data[i]);
    bool result = current.m_iElementCount > 0;
    pieces.clearAndDeallocate();
    next.clearAndDeallocate();
    current.clearAndDeallocate();
    return result;
}

extern const char str_010d36a0[];
extern const char str_0103d078[];
extern const char str_010d3540[];
typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
#include "../../../../../../include/hkResult.h"
typedef __int64 hkInt64;
typedef unsigned __w64 hk_size_t;
class hkClass;
#include "../../../../../../include/hkPadSpu.h"   // Havok 7.1 hkPadSpu (was a unit-local ValueWrapper copy)
template<typename T> struct TypeSizeConstant { enum { val = sizeof(T) }; };

template<typename TYPE>
inline void hkMemoryAllocator::_bufFree(void* p, int numElem) { ReturnMemory(p, numElem * TypeSizeConstant<TYPE>::val); }

template<typename T>
__forceinline T& __cdecl hkSingleton<T>::GetMonitorStream() { return *s_instance; }

class hkStatisticsCollector;

class hkStreamWriter;

template <typename T>
__forceinline T* hkArrayBase<T>::_expandBy(hkMemoryAllocator& alloc, int n)
{
    int oldsize = m_iElementCount;
    GrowArrayCapacity(alloc, m_iElementCount + n);
    m_iElementCount += n;
    return m_data + oldsize;
}

extern "C" {
extern __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern __m128 _mm_add_ps(__m128 _A, __m128 _B);
extern __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern __m128 _mm_sqrt_ss(__m128 _A);
extern __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
extern __m128 _mm_setr_ps(float _A, float _B, float _C, float _D);
extern __m128 _mm_load_ss(float const*_A);
extern void _mm_store_ss(float *_V, __m128 _A);};
typedef __m128 hkQuadReal;
// Preserve the original aggregate copy as integer loads and stores.
union __declspec(intrin_type) __declspec(align(16)) HavokQuadStorage { float m128_f32[4]; unsigned __int64 m128_u64[2]; };

inline hkSimdReal::hkSimdReal(const __m128& x) { m_vValue = x; }
inline hkSimdReal::hkSimdReal(float x) { m_vValue = (_mm_load_ss)(&x); }
inline hkSimdReal::operator float() const { float s; (_mm_store_ss)(&s, m_vValue); return s; }
__forceinline __m128 hkSimdReal::broadcast() const { return (_mm_shuffle_ps)(m_vValue, m_vValue, 0); }
__forceinline const __m128& hkSimdReal::getQuad() const { return m_vValue; }

typedef const hkSimdReal& hkSimdRealParameter;extern "C" {
double __cdecl fabs([SA_Pre(Null=SA_No)] [SA_Pre(Deref=1,Valid=SA_Yes,Access=SA_Read)] double _X);inline float fabsf([SA_Pre(Null=SA_No)] [SA_Pre(Deref=1,Valid=SA_Yes,Access=SA_Read)] float _X)
{return ((float)fabs((double)_X)); }
}
namespace MathUtilities
{inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
}
inline const hkQuaternion& __cdecl hkQuaternion::GetIdentityTransform()
{
extern const hkQuaternion g_kIdentityQuaternion;
return g_kIdentityQuaternion;
}
__forceinline hkRotation::hkRotation() {}
__forceinline void hkRotation::operator=(const hkRotation& other)
{
m_kColumn0 = other.m_kColumn0;
m_kColumn1 = other.m_kColumn1;
m_kColumn2 = other.m_kColumn2;
}

__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
(*(hkQuadReal*)&m_quadS) = (_mm_setr_ps)(a,b,c,d);
}
__forceinline void hkVector4::add4(const hkVector4& v)
{
(*(hkQuadReal*)&m_quadS) = (_mm_add_ps)( (*(hkQuadReal*)&m_quadS), (*(hkQuadReal*)&v.m_quadS) );
}
__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
(*(hkQuadReal*)&m_quadS) = (_mm_add_ps)((*(hkQuadReal*)&v0.m_quadS), (*(hkQuadReal*)&v1.m_quadS));
}
__forceinline void hkVector4::sub4(const hkVector4& v)
{
(*(hkQuadReal*)&m_quadS) = (_mm_sub_ps)( (*(hkQuadReal*)&m_quadS), (*(hkQuadReal*)&v.m_quadS) );
}
__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
(*(hkQuadReal*)&m_quadS) = (_mm_sub_ps)((*(hkQuadReal*)&v0.m_quadS), (*(hkQuadReal*)&v1.m_quadS));
}
__forceinline void hkVector4::mul4(const hkVector4& v)
{
(*(hkQuadReal*)&m_quadS) = (_mm_mul_ps)( (*(hkQuadReal*)&m_quadS), (*(hkQuadReal*)&v.m_quadS) );
}
__forceinline void hkVector4::mul4(hkSimdRealParameter s)
{
(*(hkQuadReal*)&m_quadS) = (_mm_mul_ps)( s.broadcast(), (*(hkQuadReal*)&m_quadS) );
}
__forceinline void hkVector4::addMul4(hkSimdRealParameter r, const hkVector4& v1)
{
(*(hkQuadReal*)&m_quadS) = (_mm_add_ps)( (*(hkQuadReal*)&m_quadS),
(_mm_mul_ps)( r.broadcast(), (*(hkQuadReal*)&v1.m_quadS)) );
}
__forceinline void hkVector4::setCross( const hkVector4& v0, const hkVector4& v1 )
{
hkQuadReal cross0;
cross0 = (_mm_mul_ps)(
(_mm_shuffle_ps)((*(hkQuadReal*)&v0.m_quadS), (*(hkQuadReal*)&v0.m_quadS), (((3) << 6) | ((0) << 4) | ((2) << 2) | ((1)))),
(_mm_shuffle_ps)((*(hkQuadReal*)&v1.m_quadS), (*(hkQuadReal*)&v1.m_quadS), (((3) << 6) | ((1) << 4) | ((0) << 2) | ((2)))) );
hkQuadReal cross1;
cross1 = (_mm_mul_ps)(
(_mm_shuffle_ps)((*(hkQuadReal*)&v0.m_quadS), (*(hkQuadReal*)&v0.m_quadS), (((3) << 6) | ((1) << 4) | ((0) << 2) | ((2)))),
(_mm_shuffle_ps)((*(hkQuadReal*)&v1.m_quadS), (*(hkQuadReal*)&v1.m_quadS), (((3) << 6) | ((0) << 4) | ((2) << 2) | ((1)))) );
(*(hkQuadReal*)&m_quadS) = (_mm_sub_ps)(cross0, cross1);}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
hkQuadReal x2 = (_mm_mul_ps)((*(hkQuadReal*)&m_quadS),(*(hkQuadReal*)&a.m_quadS));
hkQuadReal xySum = (_mm_add_ss)( (_mm_shuffle_ps)(x2,x2,(((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
return (_mm_add_ss)( (_mm_shuffle_ps)(x2,x2,(((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))), xySum);}
__forceinline hkSimdReal hkVector4::length3() const
{
return (_mm_sqrt_ss)( this->dot3(*this).getQuad() );
}
__forceinline hkReal& hkVector4::operator() (int a)
{
return reinterpret_cast<hkReal*>(&(*(hkQuadReal*)&m_quadS))[a];
}
__forceinline const hkReal& hkVector4::operator() (int a) const
{
return reinterpret_cast<const hkReal*>(&(*(hkQuadReal*)&m_quadS))[a];
}
__forceinline const hkVector4& __cdecl hkVector4::getZero()
{
extern hkVector4 g_vZero;
return g_vZero;
}
__forceinline hkVector4& hkMatrix3::getColumn(int x)
{
return (&m_kColumn0)[x];
}
__forceinline const hkVector4& hkMatrix3::getColumn(int x) const
{
return (&m_kColumn0)[x];
}
__forceinline hkReal& hkMatrix3::operator() (int r, int c)
{
return getColumn(c)(r);
}
__forceinline const hkReal& hkMatrix3::operator() (int r, int c) const
{
return getColumn(c)(r);
}
__forceinline void hkMatrix3::setCols( const hkVector4& r0,
const hkVector4& r1,
const hkVector4& r2)
{
m_kColumn0 = r0;
m_kColumn1 = r1;
m_kColumn2 = r2;
}
__forceinline void hkMatrix3::operator= ( const hkMatrix3& a )
{
m_kColumn0 = a.getColumn(0);
m_kColumn1 = a.getColumn(1);
m_kColumn2 = a.getColumn(2);
}
__forceinline void hkTransform::setTranslation(const hkVector4& t)
{
*reinterpret_cast<hkVector4*>(&m_row3) = t;
}
__forceinline void hkTransform::SetBodyOrientation(const hkRotation& rotation)
{
*reinterpret_cast<hkRotation*>(&m_row0) = rotation;
}
__forceinline void hkTransform::SetBodyOrientation(const hkQuaternion& quatRotation)
{
reinterpret_cast<hkRotation*>(&m_row0)->set(quatRotation);
}
__forceinline const hkTransform& __cdecl hkTransform::GetIdentityTransform()
{
extern hkTransform g_kIdentityTransform;
return g_kIdentityTransform;
}

__forceinline hkVector4::hkVector4(const hkVector4& v) { *reinterpret_cast<HavokQuadStorage*>(this) = *reinterpret_cast<const HavokQuadStorage*>(&v); }
__forceinline hkMatrix3::hkMatrix3() {}
__forceinline hkTransform::hkTransform() {}
__forceinline void hkTransform::operator=(const hkTransform& t) {
    *reinterpret_cast<hkRotation*>(&m_row0) = *reinterpret_cast<const hkRotation*>(&t.m_row0);
    *reinterpret_cast<hkVector4*>(&m_row3) = *reinterpret_cast<const hkVector4*>(&t.m_row3);
}
__forceinline hkAabb::hkAabb() {}

class hkgpConvexHull : public hkReferencedObject
{
public:
__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(getHavokMonitorStream().heap().blockAlloc(static_cast<int>(nbytes))); b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes); ; return b; }
struct Vertex {};
struct Triangle {};
public:
struct ConvexHullRecord
{
ConvexHullRecord();
hkBool m_bFlagAtOffset00;
hkReal m_fValueAtOffset04;
hkBool m_bFlagAtOffset08;
hkBool m_bFlagAtOffset09;
hkBool m_bFlagAtOffset0A;
hkBool m_bFlagAtOffset0B;
hkBool m_bFlagAtOffset0C;
hkBool m_bFlagAtOffset0D;
};
public:
hkgpConvexHull();
private:
inline hkgpConvexHull(const hkgpConvexHull& ch) : hkReferencedObject(ch) {}
private:
friend class hkgpConvexHullImpl;};
struct hkGeometryProcessing
{
template <typename T,const int N,typename ALLOCATOR=hkContainerHeapAllocator>
struct DynamicMemoryAllocator
{
struct Item
{
hkUint8 m_data[sizeof(T)];
};
struct Pool
{
__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; void* obj = getHavokMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)); ; return obj; } __forceinline void __cdecl operator delete(void* p) { if (p) { ; getHavokMonitorStream().heap().ReleaseBlock(p, sizeof(Pool)); } } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class CommandArgument;
Item m_items[N];
Item* m_free;
int m_uiBufferCapacity;
};
inline DynamicMemoryAllocator() {}
inline ~DynamicMemoryAllocator();
__forceinline T* allocate() { return(new(allocateItem()) T()); }
__forceinline T* allocate(const T& value) { return(new(allocateItem()) T(value)); }
inline void release(T* item);
__forceinline bool needRelease() const { return(false); }
__forceinline void clear();
private:
inline Item* allocateItem();
inline Pool* GetOrCreatePool();
inline void releasePool(Pool* pool) const;
DynamicMemoryAllocator(const DynamicMemoryAllocator&) {}
void operator=(const DynamicMemoryAllocator&) {}
private:
hkArray<Pool*,ALLOCATOR> m_pools;
};
struct VectorBasis
{
hkVector4 m_uiX;
hkVector4 m_uiY;
hkVector4 m_uiZ;
};};class TriangleEdgeTopology
{
public:
static __forceinline hkUlong uid2ulong(void* t,hkUint32 i) { return (*(const hkUlong*)&t)+(hkUlong)i; }
typedef hkUlong Uid;template <typename EDGE,typename VERTEX,typename TRIANGLE,typename VERTEX_MEMBER=VERTEX*>
struct Edge
{
public:
typedef VERTEX tVertex;
typedef VERTEX_MEMBER tMVertex;
typedef TRIANGLE tTriangle;
protected:
static __forceinline unsigned ip1mod3(unsigned i);
static __forceinline unsigned ip2mod3(unsigned i);
public:
__forceinline static const EDGE& null() { static const EDGE e(0,0);return(e); }
public:
__forceinline Edge() {}
__forceinline Edge(tTriangle* t,unsigned i) : m_pkTriangle(t),m_uiEdgeIndex(i) {}
__forceinline Edge(const Uid& id) { unpackUid(id,m_pkTriangle,m_uiEdgeIndex); }
__forceinline EDGE next() const { return(EDGE(m_pkTriangle,ip1mod3(m_uiEdgeIndex))); }
__forceinline EDGE prev() const { return(EDGE(m_pkTriangle,ip2mod3(m_uiEdgeIndex))); }
__forceinline EDGE link() const { return(EDGE(m_pkTriangle->link(m_uiEdgeIndex))); }
__forceinline EDGE turnCcw() const { return(link().next()); }
__forceinline EDGE turnCw() const { return(prev().link()); }
__forceinline EDGE nextCw() const { return(link().prev()); }
__forceinline EDGE nextCcw() const { return(link().next()); }
__forceinline EDGE prevCw() const { return(prev().link()); }
__forceinline EDGE prevCcw() const { return(next().link()); }
__forceinline EDGE master() const { if(isMaster()) return(EDGE(m_pkTriangle,m_uiEdgeIndex)); else return(link()); }
__forceinline TRIANGLE* triangle() const { return(m_pkTriangle); }
__forceinline int index() const { return((int)m_uiEdgeIndex); }
__forceinline Uid uid() const { return packUid(m_pkTriangle,m_uiEdgeIndex); }
__forceinline tMVertex& start() const { return(m_pkTriangle->vertex(m_uiEdgeIndex)); }
__forceinline tMVertex& end() const { return(m_pkTriangle->vertex(ip1mod3(m_uiEdgeIndex))); }
__forceinline tMVertex& apex() const { return(m_pkTriangle->vertex(ip2mod3(m_uiEdgeIndex))); }
__forceinline EDGE self() const { return(EDGE(m_pkTriangle,m_uiEdgeIndex)); }
__forceinline bool isValid() const { return(triangle()!=0); }
__forceinline bool isMaster() const { return(tVertex::isOrdered(start(),end())||isNaked()); }
__forceinline bool isNaked() const { return(!link().isValid()); }
__forceinline bool isBound() const { return(!isNaked()); }
__forceinline bool canBind(const Edge& edge) const { return((!edge.isValid())||((start()==edge.end())&&(end()==edge.start()))); }
__forceinline bool tryBind(const Edge& edge) const { const bool cb(canBind(edge));if(cb) bind(edge);return(cb); }
__forceinline void bind(const Edge& edge) const;
__forceinline void bindSides() const;
__forceinline void unbind() const;
__forceinline EDGE flip() const;
template <typename FNC>
__forceinline void applyFan(FNC& fnc) const;
__forceinline bool operator==(const EDGE& e) const { return(uid()==e.uid()); }
__forceinline bool operator!=(const EDGE& e) const { return(uid()!=e.uid()); }
protected:
tTriangle* m_pkTriangle;
hkUint32 m_uiEdgeIndex;
};};struct AllocatedLinkedList
{
typedef TriangleEdgeTopology::Uid Uid;
template <typename T,typename BASE,typename ALLOCATOR=hkGeometryProcessing::DynamicMemoryAllocator<T,32> >
struct List
{
struct Item : BASE
{
__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; void* obj = getHavokMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)); ; return obj; } __forceinline void __cdecl operator delete(void* p) { if (p) { ; getHavokMonitorStream().heap().ReleaseBlock(p, sizeof(Item)); } } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class CommandArgument;
__forceinline T* next() const { return(m_next); }
__forceinline T*& next() { return(m_next); }
__forceinline T* prev() const { return(m_pSecondNode); }
__forceinline T*& prev() { return(m_pSecondNode); }
public:
Item() : BASE() {}
Item& operator=(const Item&) { return(*this); }
protected:
Item(const Item& other) : BASE(other) {}
private:
T* m_next;
T* m_pSecondNode;
};
List() : m_uiBufferCapacity(0),m_iAllocatedCount(0) {}
inline ~List();
inline void reset();
inline T* allocate(const T& value=T());
inline void release(T* item);
inline void moveUp(T* item);
inline void moveDown(T* item);
__forceinline T* getFirst() const { return(m_uiBufferCapacity); }
__forceinline T* getLast() const { T* t=getFirst();if(t) { while(t->next()) t=t->next(); } return(t); }
__forceinline int GetLogicalSize() const { return(m_iAllocatedCount); }
private:
List(const List&) {}
void operator=(const List&) {}
private:
ALLOCATOR m_pThreadAllocator;
T* m_uiBufferCapacity;
int m_iAllocatedCount;
hkUint32 m_uiUniqueId;
};
template <typename VERTEX,typename BASE>
struct Vertex : List<VERTEX,BASE>::Item
{
typedef typename List<VERTEX,BASE>::Item tBase;
__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; void* obj = getHavokMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)); ; return obj; } __forceinline void __cdecl operator delete(void* p) { if (p) { ; getHavokMonitorStream().heap().ReleaseBlock(p, sizeof(Vertex)); } } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class CommandArgument;
static __forceinline bool isOrdered(const VERTEX* a,const VERTEX* b)
{
const int c((*a).compare(*b));
;
if(c<0) return(true);
if(c>0) return(false);
return(true);
}
};
template <typename TRIANGLE,typename BASE,typename VERTEX>
struct Triangle : List<TRIANGLE,BASE>::Item
{
typedef typename List<TRIANGLE,BASE>::Item tBase;
typedef const VERTEX& vParm;
__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; void* obj = getHavokMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)); ; return obj; } __forceinline void __cdecl operator delete(void* p) { if (p) { ; getHavokMonitorStream().heap().ReleaseBlock(p, sizeof(Triangle)); } } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class CommandArgument;
__forceinline void setVertices(vParm a,vParm b,vParm c) { m_kVertices[0]=a;m_kVertices[1]=b;m_kVertices[2]=c; }
__forceinline bool hasReferences() const { return(0!=((link(0)|link(1)|link(2))>>2)); }
__forceinline VERTEX vertex(int i) const { return(m_kVertices[i]); }
__forceinline VERTEX& vertex(int i) { return(m_kVertices[i]); }
__forceinline Uid link(int i) const { return(m_ppLinks[i]); }
__forceinline Uid& link(int i) { return(m_ppLinks[i]); }
private:
VERTEX m_kVertices[3];
Uid m_ppLinks[3];
};};
template <typename EDGE,typename VERTEX,typename TRIANGLE,typename ALLOCATOR=hkContainerHeapAllocator>
class hkgpAbstractMesh : public hkReferencedObject
{
public:
__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(getHavokMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes))); b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes); ; return b; } typedef hkGeometryProcessing::DynamicMemoryAllocator<VERTEX,32,ALLOCATOR> VertexPoolAllocator;
typedef hkGeometryProcessing::DynamicMemoryAllocator<TRIANGLE,32,ALLOCATOR> TrianglePoolAllocator;
typedef AllocatedLinkedList::List<VERTEX,typename VERTEX::tBase,VertexPoolAllocator> VertexList;
typedef AllocatedLinkedList::List<TRIANGLE,typename VERTEX::tBase,TrianglePoolAllocator> TriangleList;
VertexList m_kVertices;
TriangleList m_uiTriangleCount;};class hkgpConvexHullImpl
{
public:
struct Plane { int m_iThirdValue[3]; hkInt64 m_iFourthElementInteger; int m_uiEdgeIndex; };
struct Vertex : AllocatedLinkedList::Vertex<Vertex, hkgpConvexHull::Vertex>
{
hkVector4 m_pObservedSource;
int m_uiX[3];
float m_vCenterOfMass;
int m_refs;
int m_uiEdgeIndex;
};
struct Triangle : AllocatedLinkedList::Triangle<Triangle, hkgpConvexHull::Triangle, Vertex*>
{
Plane m_kTriangleNormal;
int m_iTriangleIndex;
int m_uiEdgeIndex;
};
struct Edge : TriangleEdgeTopology::Edge<Edge, Vertex, Triangle, Vertex*> { };
typedef hkgpAbstractMesh<Edge, Vertex, Triangle, hkContainerHeapAllocator> Mesh;
struct ConvexHullVertexTransform
{
static __forceinline hkVector4 get(const hkgpConvexHullImpl* ch, const Vertex* v) { return ch->transform(*v); }
};
hkVector4 transform(const Vertex& v) const
{
hkVector4 r;
r.set(hkReal(v.m_uiX[0]), hkReal(v.m_uiX[1]), hkReal(v.m_uiX[2]), 0.0f);
r.mul4(m_vVertexScale);
r.add4(m_vRayOrigins);
return r;
}
template <typename P> const hkVector4& GetCenterOfMass() const throw();
template <typename P> __forceinline void fetchWorldPositions(hkArray<hkVector4>& positions) const
{
hkVector4* pp = positions.expandBy(m_pMesh.m_kVertices.GetLogicalSize());
for (const Vertex* v = m_pMesh.m_kVertices.getFirst(); v; v = v->next())
{
*pp++ = ConvexHullVertexTransform::get(this, v);
}
}
static __forceinline void accumulateMass(const hkMatrix3& m, int a, int b, int c, hkReal det, hkVector4& diag, hkVector4& offd)
{

diag(a) += (m(a,0)*m(a,1) + m(a,1)*m(a,2) + m(a,2)*m(a,0) + m(a,0)*m(a,0) + m(a,1)*m(a,1) + m(a,2)*m(a,2)) * det;

offd(a) += (m(b,0)*m(c,1) + m(b,1)*m(c,2) + m(b,2)*m(c,0) + m(b,0)*m(c,2) + m(b,1)*m(c,0) + m(b,2)*m(c,1)
+ m(b,0)*m(c,0)*2.0 + m(b,1)*m(c,1)*2.0 + m(b,2)*m(c,2)*2.0) * det;
}
static __forceinline void translateInertia(hkReal mass, const hkVector4& oldcom, const hkVector4& newcom, hkMatrix3& inertia)
{
hkMatrix3 a, b, w, q;
a.SetDiagonalElements(oldcom);
b.SetDiagonalElements(newcom);
w.SetProduct(a, a);
q.SetProduct(b, b);
q.transpose();
w.sub(q);
inertia.addMul(mass, w);
}
hkResult hkgpConvexHullImpl_buildMassProperties_hkgpConvexHullImpl_PositionAsTransform();
hkgpConvexHull::ConvexHullRecord m_pConfiguration;
Mesh m_pMesh;
hkArray<Vertex> m_kVertexArray;
hkArray<hkVector4> m_kPlaneArray;
hkArray<hkGeometryProcessing::VectorBasis> m_kGeometryRecordArray;
hkVector4 m_vVectorPair[2];
hkAabb m_kAabbPair[2];
hkVector4 m_kVectorAtOffsetD0;
hkVector4 m_kVectorAtOffsetE0;
hkVector4 m_vRayOrigins;
hkVector4 m_vScale;
hkVector4 m_vVertexScale;
hkTransform m_kLocalTransform;
hkVector4 m_vOffset;
hkMatrix3 m_kTransformMatrix;
float m_iBufferSize;
float m_fVertexStride;
int m_eVertexFloatDimensions;
int m_iTriangleIndex;
unsigned int m_uiUniqueId;
bool m_bFirstImplementationFlag;};

// Updates center, area, volume, and inertia-related state based on vertex dimensionality.
// @fnv 0x00d7b600
// src: XBOX_PDB 0x00d7b600
hkResult hkgpConvexHullImpl::hkgpConvexHullImpl_buildMassProperties_hkgpConvexHullImpl_PositionAsTransform()
{
if (!m_bFirstImplementationFlag)
{
if (m_eVertexFloatDimensions == 3)
{
const hkVector4 base = GetCenterOfMass<ConvexHullVertexTransform>();
hkVector4 com = hkVector4::getZero();
hkVector4 diag = hkVector4::getZero();
hkVector4 offd = hkVector4::getZero();
hkReal vol = 0;
hkReal area = 0;
for (const Triangle* pt = m_pMesh.m_uiTriangleCount.getFirst(); pt; pt = pt->next())
{
hkMatrix3 m;
m.setCols(ConvexHullVertexTransform::get(this, pt->vertex(0)), ConvexHullVertexTransform::get(this, pt->vertex(1)), ConvexHullVertexTransform::get(this, pt->vertex(2)));
m.getColumn(0).sub4(base);
m.getColumn(1).sub4(base);
m.getColumn(2).sub4(base);
const hkVector4 org = m.getColumn(0);
const hkReal det = m.GetDeterminant();
hkVector4 ab; ab.setSub4(m.getColumn(1), org);
hkVector4 ac; ac.setSub4(m.getColumn(2), org);
ab.setCross(ab, ac);
area += ab.length3();
hkVector4 s = org;
s.add4(m.getColumn(1));
s.add4(m.getColumn(2));
com.addMul4(det, s);
vol += det;
accumulateMass(m, 0, 1, 2, det, diag, offd);
accumulateMass(m, 1, 2, 0, det, diag, offd);
accumulateMass(m, 2, 0, 1, det, diag, offd);
}
com.mul4(hkSimdReal(1.0 / (vol * 4.0)));
com.add4(base);
m_kLocalTransform.setTranslation(com);
m_fVertexStride = area / 2.0;
m_iBufferSize = vol / 6.0;
if (m_iBufferSize > 1.1920928955078125e-07)
{
diag.mul4(hkSimdReal(1.0 / (vol * 10.0)));
offd.mul4(hkSimdReal(1.0 / (vol * 20.0)));
hkMatrix3 inertiaM;
hkVector4 c0; c0.set(diag(1) + diag(2), -offd(2), -offd(1), 0.0f);
hkVector4 c1; c1.set(-offd(2), diag(0) + diag(2), -offd(0), 0.0f);
hkVector4 c2; c2.set(-offd(1), -offd(0), diag(0) + diag(1), 0.0f);
inertiaM.setCols(c0, c1, c2);
com.sub4(base);
translateInertia(1.0f, com, hkVector4::getZero(), inertiaM);
hkRotation eigenVectors;
hkVector4 eigenValues;
if (inertiaM.DiagonalizeSymmetric(reinterpret_cast<hkMatrix3&>(eigenVectors), eigenValues, 128, 1e-4f) == HK_FAILURE)
{

if(1) { hkUint32 assertBuf[128]; void* ostrStore[sizeof(hkErrStream) / sizeof(void*)]; new(&ostrStore) hkErrStream(assertBuf,sizeof(assertBuf)); hkErrStream& ostr = *reinterpret_cast<hkErrStream*>(&ostrStore); ostr.hkOstream::operator<<(str_010d36a0) << m_uiUniqueId << str_0103d078; if ( hkError::GetMonitorStream().message(hkError::MESSAGE_ERROR, 0x45465, (const char*)assertBuf, str_010d3540, 1753) ) { fnv_Breakpoint(); } ostr.hkOstream::~hkOstream(); } else;
}
reinterpret_cast<hkMatrix3&>(eigenVectors).transpose();
eigenVectors.Orthonormalize();
m_kTransformMatrix = inertiaM;
inertiaM.SetFromRotation(eigenVectors);
m_vOffset.set(inertiaM(0, 0), inertiaM(1, 1), inertiaM(2, 2), 0.0f);
reinterpret_cast<hkMatrix3&>(eigenVectors).transpose();
m_kLocalTransform.SetBodyOrientation(eigenVectors);
}
else
{

;
m_kLocalTransform.SetBodyOrientation(hkQuaternion::GetIdentityTransform());
m_iBufferSize = 0;
m_kTransformMatrix.getColumn(0) = hkVector4::getZero();
m_kTransformMatrix.getColumn(1) = hkVector4::getZero();
m_kTransformMatrix.getColumn(2) = hkVector4::getZero();
m_vOffset = hkVector4::getZero();
}
m_bFirstImplementationFlag = true;
}
else if (m_eVertexFloatDimensions == 2)
{
hkArray<hkVector4> vertices;
const hkReal oneThird = 1.0f / 3.0f;
hkVector4 com = hkVector4::getZero();
hkReal total_area2 = 0;
fetchWorldPositions<ConvexHullVertexTransform>(vertices);
for (int i = 1; i < vertices.GetLogicalSize() - 1; ++i)
{
const hkVector4* o = &vertices[0];
hkVector4 a; a.setSub4(vertices[i], *o);
hkVector4 b; b.setSub4(vertices[i + 1], *o);
hkVector4 plane; plane.setCross(a, b);
const hkReal area2 = MathUtilities::fabs(plane.dot3(m_kVectorAtOffsetE0));
total_area2 += area2;
hkVector4 center; center.setAdd4(a, b);
center.mul4(hkSimdReal(oneThird * area2));
com.add4(center);
}
m_bFirstImplementationFlag = true;
m_fVertexStride = total_area2 / 2.0;
m_kTransformMatrix(0, 0) = 1.0f;
m_vOffset.set(1.0f, 0.0f, 0.0f, 0.0f);
com.mul4(hkSimdReal(1.0f / total_area2));
com.add4(vertices[0]);
m_kLocalTransform.setTranslation(com);
}
else
{
m_bFirstImplementationFlag = true;
m_fVertexStride = 0;
m_iBufferSize = 0;
m_kTransformMatrix = hkMatrix3::GetIdentityTransform();
m_vOffset = hkVector4::getZero();
m_kLocalTransform = hkTransform::GetIdentityTransform();
}
}
return m_bFirstImplementationFlag ? HK_SUCCESS : HK_FAILURE;}
