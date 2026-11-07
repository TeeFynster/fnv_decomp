#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/NiPoint3.h"


// src/havok/common/internal/geometryprocessing/convexhull/hkgpconvexhull_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/internal/geometryprocessing/convexhull/hkgpconvexhull.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/geometryprocessing/convexhull/hkgpconvexhull.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/convexhull/hkgpconvexhull.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00d74dd0_Class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void hkgpConvexHull_deleteUserObject();
};
struct FUN_00d7ac40_class
{
    void hkgpConvexHullImpl_reset(int);
};
struct FUN_00d75850_class
{
    int m0;
    int m1;
    FUN_00d7ac40_class* m2;
    int m3;
    int m4;
    void hkgpConvexHull_reset();
};
int __stdcall hkgpConvexHull_getNeighbour(const int* p, int i);
struct FUN_00d7c200_cls
{
    void __thiscall FreeAll();
};
struct FUN_00d7c250_cls
{
    void __thiscall FlushQueuedElements();
};
struct FUN_00d7c950_cls
{
    void __thiscall ProcessState_00d7c950();
};
int __stdcall hkgpConvexHull_getVertex(int* arr, int idx);
struct CpuScalar
{
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
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    CpuScalar* value;
    int GetNestedValue();
};
struct ValueBlock
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
};
struct Implementation
{
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
struct FUN_00d74e50_cls
{
    int unk00;
    int unk04;
    Implementation* m_pImpl;

    ValueBlock GetValueBlock();
};
struct PayloadOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iPayload;
};
int* __stdcall Hkgpconvexhull_GetPayloadAddress(PayloadOwner* apOwner);
struct TargetCallee
{
    void ProcessEntries_00d7a5a0(void* p1, void* p2, void* p3, void* p4, float p5);
};
struct FUN_00d74ee0_Class : FUN_00d74dd0_Class
{
    void ForwardToCallee(void* p1, void* p2, void* p3, void* p4, float p5);
};
struct D75060Inner
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
    int unk24;
};
struct D75060Outer
{
    int unk00;
    int unk04;
    D75060Inner* unk08;

    int GetUnk24_00d75060();
};
struct TextBuffer
{
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
struct ChildData
{
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
struct Request
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
};
struct ErrorReporter
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual int message(int type, int hash, const char* text, const char* file, int line);
};
extern ErrorReporter* DAT_01268360;
void __debugbreak();
struct Owner
{
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
struct D75130Inner
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
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
};
struct D75130Outer
{
    int unk00;
    int unk04;
    D75130Inner* unk08;

    int EvaluateValue_00d75130();
};
int __stdcall Object_ReadPointedValue_00d75200(const int* value);
struct S_00d75210_ErrStream
{
    void* m_vt;
    int unk04;
    int unk08;
    S_00d75210_ErrStream(void* buf, int bufSize) throw();
    ~S_00d75210_ErrStream() throw();
    S_00d75210_ErrStream& operator<<(const char* s) throw();
    S_00d75210_ErrStream& operator<<(unsigned int u) throw();
};
struct S_00d75210_Error
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};
extern S_00d75210_Error* g_hkError;
struct S_00d75210_Data
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
    int m_uiEdgeIndex;
};
struct S_00d75210_Config
{
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
struct S_00d75210_Self
{
    int unk00;
    int unk04;
    S_00d75210_Config* m_pConfiguration;
    int hkgpConvexHull_getPlaneIndex(const S_00d75210_Data* v) const throw();
};
struct D762F0Target
{
    void update();
};
struct D762F0Owner
{
    int unk00;
    int unk04;
    D762F0Target* m_target;

    void ForwardCall_00d762f0();
};
struct D76910Inner
{
    void ProcessEntries_00d7cf00();
};
struct D76910Owner
{
    int unk00;
    int unk04;
    D76910Inner* inner;
    void ForwardCall_00d76910();
};
struct FUN_00d76990_State
{
    int unk00;
    float unk04;
    void ProcessEntries_00d7d2a0();
};
struct FUN_00d76990_Class
{
    int unk00;
    int unk04;
    FUN_00d76990_State* unk08;
    void SetValue(float value, bool clearFlag);
};
struct __declspec(align(16)) hkVec4
{
    float x, y, z, w;
};
struct Shape
{
    float ComputeValues_00d768b0(const hkVec4& v);
    float ProcessAndReturnValue_00d76840(const hkVec4& v);
    float ProcessAndReturnValue_00d769c0(const NiPoint3& p);
};
struct AudioSink
{
    void hkgpConvexHullImpl_generateIndexedFaces_int_int(void* apFirst, void* apSecond, bool abIsNull, void* apThird);
};
struct FUN_00d76c50_cls
{
    int unk00;
    int unk04;
    AudioSink* m_pSink;

    void DispatchToSink(void* apKey, void* apFirst, void* apSecond, void* apThird);
};
struct Vec4i
{
    int x, y, z, w;
};
struct FUN_00d81510_Class
{
    Vec4i m_00;
    void hkgpConvexHullImpl_build(int a, int b, int c, int d);
};
struct FUN_00d771c0_Owner
{
    int unk00;
    int unk04;
    FUN_00d81510_Class* unk08;
    void hkgpConvexHull_build(int a, int b, const Vec4i& v);
};
struct FUN_00d83430_class
{
    void AllocateStorage_00d83430(int, int, int, float);
};
struct FUN_00d790a0_class
{
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
struct S_00d7a010_Alloc
{
    virtual void unk0();
    virtual void unk4();
    virtual void ReleaseBlock(void* p, int n);
    virtual void unkc();
    virtual void ReturnMemory(void* p, int n) throw();
};
struct S_00d7a010_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00d7a010_Alloc* m_pStreamAllocator;
    static S_00d7a010_Router& hkMemoryRouter_getInstance() throw();
    S_00d7a010_Alloc& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};
template <typename T> struct S_00d7a010_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00d7a010_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline void _clearAndDeallocate(S_00d7a010_Alloc& a) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};
struct S_00d7a010_Obj
{
    virtual ~S_00d7a010_Obj() throw();
    void operator delete(void* p) throw();
};
void __cdecl hkgpConvexHull_createVoronoiFeatures(int a, int b, S_00d7a010_Array<S_00d7a010_Obj*>& out, int c, float f) throw();
void __cdecl DeleteCollectedObjects(int a, int b, int c, float f);
struct S_00d7c200_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void ReleaseBlock(void* p, int nbytes);
};
struct S_00d7c200_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d7c200_Heap* m_pStreamAllocator;
    static S_00d7c200_Router& GetMonitorStream();
    S_00d7c200_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
struct S_00d7c200
{
    void** m_kBlocks;
    int m_iBlockCount;
    int unk8;
    int unkC;
    int unk10;
    void FreeAll();
};
struct S_00d7c340_Allocator
{
    virtual void vfn_00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct S_00d7c340_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d7c340_Allocator* unk10;
    S_00d7c340_Allocator* heap()
    {
        return unk10;
    }
};
S_00d7c340_Router* hkMemoryRouter_getInstance();
int ResizeAudioStream(S_00d7c340_Allocator* alloc, void* array, int elemSize);
struct S_00d7c340_Elem
{
    S_00d7c340_Elem* next;
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
};
struct S_00d7c340_Block
{
    S_00d7c340_Elem elems[32];
    S_00d7c340_Elem* freeList;
    int numUsed;
};
struct S_00d7c340
{
    S_00d7c340_Block** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00d7c340_Block* AllocateBlock();
};
struct UnknownBlock
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};
struct Node
{
    Node* link0;
    Node* link4;
    void* unk08;
    void* unk0c;
    int value10, value14, value18, value1c, value20, value24, value28;
    float value2c;
    int value30, value34;
};
struct NodeBank
{
    UnknownBlock unk000, unk040, unk080, unk0c0, unk100, unk140, unk180, unk1c0;
    UnknownBlock unk200, unk240, unk280, unk2c0, unk300, unk340, unk380, unk3c0;
    UnknownBlock unk400, unk440, unk480, unk4c0, unk500, unk540, unk580, unk5c0;
    UnknownBlock unk600, unk640, unk680, unk6c0, unk700, unk740, unk780, unk7c0;
    Node* freeHead;
    int allocated;
};
struct PoolList
{
    NodeBank** banks;
    int bankValid;
    void* unk08;
    Node* head;
    int activeCount;
    NodeBank* hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_allocateNewPool();
    Node* CloneNode(Node* source);
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
struct FUN_00d74d70_cls
{
    int m_00;
    unsigned char m_04;
    float m_08;
    float m_0c;
    unsigned char m_10;
    unsigned char m_11;
    FUN_00d74d70_cls* hkgpConvexHull_SimplifyConfig_SimplifyConfig();
};
extern float DAT_0104da4c;
struct FUN_00d74d90_cls
{
    int m_i00;
    float m_f04;

    FUN_00d74d90_cls* InitializeFields_00d74d90();
};
struct SpawnedInner
{
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
struct FUN_00d74e10_cls
{
    int unk00;
    int unk04;
    SpawnedInner* m_pInner;

    int GetInnerField1A8();
};
struct FUN_00d74e20_class
{
    void* m_00;
    void* m_04;
    char* m_08;
    hkVector4 __thiscall GetFieldAtD0();
};
struct Inner
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
    int m_i28;
};
struct FUN_00d75050_cls
{
    int unk00;
    int unk04;
    Inner* m_pInner;

    int EvaluateValue_00d75050();
};
struct FUN_00d7a180_target
{
    void ProcessEntries_00d7a180();
};
struct FUN_00d752d0_cls
{
    void* m_00;
    void* m_04;
    FUN_00d7a180_target* m_08;
    void ForwardCall_00d752d0();
};
struct DiagStream
{
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
struct DiagLogger
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Report(int level, unsigned int hash, char* msg, const char* file, int line);
};
extern DiagLogger* g_diagLogger;
struct DiagState
{
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
struct FUN_00d75390_cls
{
    unsigned int unk00;
    unsigned int unk04;
    DiagState* m_08;
    float GetMass();
};
extern "C" double __cdecl pow(double base, double exponent);
extern const double DAT_010d35e8;
extern const double DAT_010d35e0;
struct FUN_00d75440_cls
{
    float hkgpConvexHull_getVolume();
    double GetMass();
    float ComputeScaledPowerRatio();
};
struct FUN_00d75820_Tmp8
{
    int m00;
    int m04;
};
struct FUN_00d75820_Target
{
    void ProcessEntries_00d7a200(int a, float b, FUN_00d75820_Tmp8* c, int d);
};
struct FUN_00d75820_cls
{
    int m00;
    int m04;
    FUN_00d75820_Target* m08;

    void CallTargetWithTemp(int a1, float a2, int a3);
};
struct FUN_00d7b330_cls
{
    void ProcessEntries_00d7b330(int a1, int a2, float a3);
};
struct FUN_00d76100_cls
{
    void* unk00;
    void* unk04;
    FUN_00d7b330_cls* m_08;
    void hkgpConvexHull_isPointInside(int a1, int a2, float a3);
};
struct FUN_00d7caa0_class
{
    void __thiscall ProcessEntries_00d7caa0(float, int);
};
struct FUN_00d76920_class
{
    void* m_00;
    void* m_04;
    FUN_00d7caa0_class* m_08;
    void hkgpConvexHull_fetchBevelPlanes(float, int);
};
struct SpawnedObject
{
    void* m_00;
    void* m_04;
    void* m_08;
};
struct TailCallee
{
    void Tail();
};
class FUN_00d77bc0_cls
{
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
struct D79090Target
{
    void update();
};
struct D79090Owner
{
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
struct FUN_00d79510_Item
{
    virtual void FUN_00d79510_doIt(int);
};
// the record the table lives in: the item array at +0, the count at +4
struct FUN_00d79510_Record
{
    FUN_00d79510_Item** m_00;
    int m_04;
};
// the third parameter: an object with a virtual at vtable slot 0
struct FUN_00d79510_Object
{
    virtual void FUN_00d79510_doIt(int);
    int m_04;
};
struct FUN_00d79510_A;
struct FUN_00d79510_B;
void __cdecl FUN_00d79250_helper(FUN_00d79510_A* a, FUN_00d79510_B* b, FUN_00d79510_Object** out, void* p, float f);
bool __cdecl hkgpConvexHull_booleanSubtraction(FUN_00d79510_A* a, FUN_00d79510_B* b, FUN_00d79510_Object* c, float f);
static int SortKeyOf(void* p)
{
    return ((int*)p)[0xe];
}
void __cdecl QuickSortByKey(void** arr, int lo, int hi, int ctx);
struct RandomGenerator
{
    unsigned int stateFlags;
    unsigned int seed;
    void hkPseudoRandomGenerator_getRandomVector11(float* components);
};
struct Record
{
    unsigned int payload;
    float key;
};
static __forceinline bool Greater(const Record& a, const Record& b)
{
    return a.key - b.key > 0.0f;
}
// @fnv 0x00d7b270
// src: HAVOK_LIB 0x00d7b270
extern "C" void hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedTriangle_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedTriangle(Record* records, int left, int right, int context)
{
    int i;
    int j;
    __declspec(align(16)) Record pivot;

    for (;;)
    {
        i = left;
        j = right;
        pivot = records[(left + right) >> 1];

        do
        {
            while (Greater(records[i], pivot))
            {
                ++i;
            }
            while (Greater(pivot, records[j]))
            {
                --j;
            }
            if (j >= i)
            {
                if (j != i)
                {
                    Record temp = records[j];
                    records[j] = records[i];
                    records[i] = temp;
                }
                --j;
                ++i;
            }
        } while (i <= j);

        if (left < j)
        {
            hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedTriangle_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedTriangle(records, left, j, context);
        }
        if (i >= right)
        {
            return;
        }
        left = i;
    }
}

// The script object that receives the queued elements: its third virtual
// function is the one that is called with the element and the command id.
struct ScriptHandler
{
    virtual void v00();
    virtual void v01();
    virtual void v02(void* element, int command);
};
// What FUN_00c85750() hands back: the audio system object, whose field at
// offset 0x10 is the script handler that owns the vtable.
struct AudioSystem
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    ScriptHandler* m_10;
};
// The audio system object the game hands out.
// The layout of the object this method belongs to: a queue of elements at
// m_00 with its length at m_04, plus two counters that are cleared again.
// FUN_00d7c2a0 - create a new object of type 0x808 and append it to the
// item list of this container.
//
// The container keeps an array of item pointers (m_00), the number of items
// (m_04) and a capacity/flags field (m_08).  The new object is allocated
// through the creation interface found at offset 0x10 of the global manager;
// the object itself starts with a free list of 32 linked 64 byte blocks.
struct GlobalManager
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
};
// The creation interface: slot 1 takes the object type id and returns a
// freshly allocated object of that type.
struct CreateIface
{
    virtual void* v0();
    virtual void* v1(int);
};
void __cdecl ResizeAudioStream(void*, void*, int);
// A writable handle for one slot of the item array.
struct SlotRef
{
    void** m_slot;
    void operator=(void* p)
    {
        *m_slot = p;
    }
};
static __forceinline SlotRef MakeSlot(void** a, int i)
{
    SlotRef r;
    r.m_slot = a + i;
    return r;
}
struct FUN_00d7c2a0_cls
{
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
struct D7C850_Target
{
    virtual void v_dummy0();
    virtual void v_dummy1();
    virtual void v1(void* element, unsigned int flags);  // vtable offset 0x08
    virtual void v_dummy2();
    virtual void v2(void* data, unsigned int size);  // vtable offset 0x10
};
struct D7C850_Holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    D7C850_Target* m_10;
};
struct D7C850_Class
{
    void** m_00;
    int m_04;
    unsigned int m_08;
    void ClearAndFlush();
};
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
class DbgStr_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    void Init(char* buf, int size);
    DbgStr_cls* Append(const char* pszPrefix, int value, const char* pszSuffix);
    DbgStr_cls* Pad(void);
    DbgStr_cls* Last(void);
    void Release(void);
};
class AssertMgr_cls
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void);
    virtual void vtbl08(void);
    virtual int vtbl0C(int level, unsigned int id, char* buf, const char* file, int line);
};
class FUN_00d75490_cls
{
  public:
    int unk00;
    int unk04;
    SharedOwner* m_pSharedOwner;
    void GetMassProperties(RetBlock64* pOut64, RetBlock16* pOut16);
};
struct D76250Allocator;
struct D76250MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D76250Allocator* m_pStreamAllocator;

    D76250Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace fnvc_adapt {
extern "C" D76250MemoryRouter& __cdecl hkMemoryRouter_getInstance();
}
void __cdecl hkArrayUtil__reserve(D76250Allocator* alloc, void* array, int numElements, int sizeElem);
typedef hkArray<hkVector4> D76250VectorArray;
struct D76250Shape
{
    int getNumVertices() const;
    const hkVector4& getVertex(int i) const;

    void CopyVerticesToArray(D76250VectorArray& vertices) const;
};
struct FUN_00d81510_cls
{
    void hkgpConvexHullImpl_build(int a1, int a2, int a3, int a4);
};
struct FUN_00d77320_cls
{
    int unk00;
    int unk04;
    FUN_00d81510_cls* m_08;

    void CopyAndDispatch(int* a1, int a2, const __m128* a3, const unsigned int* a4);
};
struct FnvCpu_FUN_00d74e00_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    int value;
    int GetValue_00d74e00();
};
struct S_00cc01c0_Class
{
    S_00cc01c0_Class* EvaluateValue_00cc02d0();
    void ProcessAndReturnValue_00cc01c0();
    S_00cc01c0_Class* ProcessAndReturnValue_00cc01c0(const char*, int, char*);
};
struct S_00d752e0_Entity
{
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
struct S_00d752e0_Class
{
    int unk00;
    int unk04;
    S_00d752e0_Entity* unk08;
    float hkgpConvexHull_getVolume();
};
extern const char str_010d3540[];
extern const char str_010d358c[];
struct S_00cb1600_Class
{
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
struct SortRec12
{
    unsigned int m0;
    unsigned int m4;
    float key;
};
void __cdecl hkAlgorithm_quickSortRecursive_struct_hkgpConvexHullImpl_SortedEdge_class_hkAlgorithm_less_struct_hkgpConvexHullImpl_SortedEdge(SortRec12* base, int lo, int hi, int unkArg);
struct DistanceScalar
{
    __m128 q;
    __forceinline DistanceScalar(__m128 v) : q(v)
    {}
    __forceinline float getReal() const
    {
        float f;
        _mm_store_ss(&f, q);
        return f;
    }
};
struct DistanceVector
{
    __m128 q;
    __forceinline DistanceVector()
    {}
    __forceinline DistanceVector(const DistanceVector& v) : q(v.q)
    {}
    __forceinline void operator=(const DistanceVector& v)
    {
        q = v.q;
    }
    __forceinline void setSub(const DistanceVector& a, const DistanceVector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline DistanceScalar lengthSquared() const
    {
        __m128 d = _mm_mul_ps(q, q);
        __m128 y = _mm_shuffle_ps(d, d, 0x55);
        __m128 z = _mm_shuffle_ps(d, d, 0xaa);
        return DistanceScalar(_mm_add_ss(z, _mm_add_ss(y, d)));
    }
};
struct DistanceLess
{
    const DistanceVector* reference;
    __forceinline bool operator()(const DistanceVector& a, const DistanceVector& b) const
    {
        DistanceVector da, db;
        da.setSub(a, *reference);
        db.setSub(b, *reference);
        struct Floats
        {
            float first;
            float second;
        };
        Floats values;
        _mm_store_ss(&values.first, da.lengthSquared().q);
        _mm_store_ss(&values.second, db.lengthSquared().q);
        return values.first < values.second;
    }
};
void Hkgpconvexhull_SortDistanceVectors(DistanceVector* pa, int lo, int hi, DistanceLess less);
struct S00d7d1c0_Alloc
{
    virtual void s0();
    virtual void s1();
    virtual void s2(void* p, int size);
};
struct S00d7d1c0_Router
{
    int u00;
    int u04;
    int u08;
    int u0c;
    S00d7d1c0_Alloc* m10;
};
struct S00d7d1c0_M08
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    void FreeAll();
    void ClearAndFlush();
};
struct S00d7d1c0_M20
{
    void FlushQueuedElements();
    void FUN_00d7c8d0();
};
struct S00d7d1c0_Base
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p, int size);
    unsigned short m04;
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct S00d7d1c0_Derived : S00d7d1c0_Base
{
    S00d7d1c0_M08 m08;
    S00d7d1c0_M20 m20;
    ~S00d7d1c0_Derived()
    {
        m20.FlushQueuedElements();
        m20.FUN_00d7c8d0();
        m08.FreeAll();
        m08.ClearAndFlush();
    }
    S00d7d1c0_Derived* hkgpAbstractMesh_hkgpConvexHullImpl_Edge_hkgpConvexHullImpl_Vertex_hkgpConvexHullImpl_Triangle_hkContainerHeapAllocator_Destroy(int flags);
};

class Ostream_d751
{
  public:
    Ostream_d751(void* pvBuffer, int iSize) throw();
    ~Ostream_d751() throw();
    Ostream_d751& operator<<(const char* pcString) throw();
    Ostream_d751& operator<<(int iValue) throw();
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
};

class Error_d751
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int eType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
};
extern Error_d751* g_pkErrorD751;

struct ConvexHullData_d751
{
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
    int unk1A8;
    int unk1AC;
    int m_iConfig;
    char unk1B4;
    bool m_bHasIndexing;
};

struct Vertex_d751
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
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    unsigned int m_uiPosition;
};

class ConvexHull_d751
{
  public:
    int unk00;
    int unk04;
    ConvexHullData_d751* m_data;

    unsigned int hkgpConvexHull_getIndex_00d75150(const Vertex_d751* pkVertex) const;
};

// @fnv 0x00d75150
// src: HAVOK_LIB 0x00d75150
unsigned int ConvexHull_d751::hkgpConvexHull_getIndex_00d75150(const Vertex_d751* pkVertex) const
{
    const ConvexHullData_d751* pkData = m_data;
    if (!pkData->m_bHasIndexing)
    {
        unsigned int assertBuf[128];
        Ostream_d751 ostr(assertBuf, sizeof(assertBuf));
        ostr << "No index available (" << pkData->m_iConfig << ")";
        if (g_pkErrorD751->message(3, 0x79f9d886, (const char*)assertBuf,
                                   ".\\GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp", 328))
            __debugbreak();
    }
    return pkVertex->m_uiPosition;
}

struct Allocator
{
    virtual void a0();
    virtual void* Alloc(int size);
    virtual void Free(void* p, int bytes);
};
struct Singleton
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    Allocator* m_10;
};

void __cdecl hkArrayUtil__reserve(Allocator* ctx, void* pVec, int sz, int elem);

struct Elem64
{
    __m128 m_00, m_10;
    int m_20, m_24, m_28;
    float m_2c;
    int m_30, m_34, m_38, m_3c;
    __forceinline Elem64() : m_2c(0), m_34(-1)
    {}
    __forceinline void operator=(const Elem64& s)
    {
        m_10 = s.m_10;
        m_20 = s.m_20;
        m_24 = s.m_24;
        m_28 = s.m_28;
        m_2c = s.m_2c;
        m_30 = s.m_30;
        m_34 = s.m_34;
    }
};
template <class T> struct CloneArray
{
    T* m_pData;
    int m_iArrayLength, m_iCapacity;
    __forceinline int capacity() const
    {
        return m_iCapacity & 0x3fffffff;
    }
    __forceinline void reserve(Allocator& a, int n)
    {
        if (capacity() < n)
        {
            int twice = capacity() * 2;
            int cap = n < twice ? twice : n;
            hkArrayUtil__reserve(&a, this, cap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        Singleton* s = reinterpret_cast<Singleton*>(hkMemoryRouter_getInstance());
        reserve(*s->m_10, n);
        int extra = n - m_iArrayLength;
        T* start = m_pData + m_iArrayLength;
        for (int j = 0; j < extra; ++j)
            new (start + j) T;
        m_iArrayLength = n;
    }
    __forceinline T& operator[](int i)
    {
        return m_pData[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_pData[i];
    }
};
struct CloneNode
{
    CloneNode* m_00;
    CloneNode* m_04;
};
static __forceinline CloneNode* firstNode(CloneNode* node)
{
    if (node)
    {
        while (node->m_00)
            node = node->m_00;
    }
    return node;
}
struct CloneFace
{
    CloneNode* m_00;
    CloneNode* m_04;
    unsigned long vertices[3];
    unsigned long links[3];
};
static __forceinline unsigned long packEdge(void* ptr, unsigned int tag)
{
    return *(const unsigned long*)&ptr + (unsigned long)tag;
}
template <class Derived> struct EdgeStorage
{
    CloneFace* face;
    unsigned int corner;
    __forceinline EdgeStorage(unsigned long k)
    {
        corner = k & 3;
        k &= ~3UL;
        face = *(CloneFace**)&k;
    }
    __forceinline EdgeStorage(CloneFace* f, unsigned int c) : face(f), corner(c)
    {}
    __forceinline unsigned long key() const
    {
        return packEdge(face, corner);
    }
    __forceinline Derived adjacent() const
    {
        return Derived(face->links[corner]);
    }
    __forceinline void bind(const Derived& other) const
    {
        face->links[corner] = other.key();
        if (other.face)
            other.face->links[other.corner] = key();
    }
};
struct CloneEdge : EdgeStorage<CloneEdge>
{
    __forceinline CloneEdge(unsigned long k) : EdgeStorage<CloneEdge>(k)
    {}
    __forceinline CloneEdge(CloneFace* f, unsigned int c) : EdgeStorage<CloneEdge>(f, c)
    {}
    __forceinline CloneEdge(const CloneEdge& s) : EdgeStorage<CloneEdge>(s.face, s.corner)
    {}
};
struct Sub18
{
    int m_00, m_04, m_08;
    CloneNode* m_0c;
    int m_10, m_14;
    int CloneNode(void* node);
};
struct Sub30
{
    int m_00, m_04, m_08;
    CloneNode* m_0c;
    int m_10, m_14;
    CloneFace* hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHull_Vertex_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Triangle_32_struct_hkContainerHeapAllocator_allocate(void* node);
};
enum MapStatus
{
    MapFound,
    MapMissing
};
struct CloneMapBase
{
    struct Entry
    {
        unsigned long key, value;
    };
    Entry* data;
    int size, mask;
    CloneMapBase() : data(0), size(0), mask(-1)
    {}
    ~CloneMapBase()
    {
        Object_DoNothing();
    }
    void EnsureCapacity(Allocator*, int);
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Allocator*, unsigned long, unsigned long);
    unsigned long LookupHashEntry(unsigned long, unsigned long) const;
    MapStatus hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(unsigned long);
    void ProcessArgument(Allocator*);
    void Object_DoNothing();
};
struct CloneHeapMap : CloneMapBase
{
    CloneHeapMap(int n = 0)
    {
        reserve(n);
    }
    ~CloneHeapMap()
    {
        clear();
    }
    __forceinline void reserve(int n)
    {
        Singleton* s = (Singleton*)hkMemoryRouter_getInstance();
        EnsureCapacity(s->m_10, n);
    }
    __forceinline int insert(unsigned long k, unsigned long v)
    {
        Singleton* s = (Singleton*)hkMemoryRouter_getInstance();
        return hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(s->m_10, k, v);
    }
    void clear()
    {
        Singleton* s = (Singleton*)hkMemoryRouter_getInstance();
        ProcessArgument(s->m_10);
    }
};
template <class K, class V> struct CloneMap
{
    CloneHeapMap map;
    __forceinline V find(K k, V v) const
    {
        return (V)map.LookupHashEntry((unsigned long)k, (unsigned long)v);
    }
    __forceinline int insert(K k, V v)
    {
        return map.insert((unsigned long)k, (unsigned long)v);
    }
    MapStatus remove(K k)
    {
        return map.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove((unsigned long)k);
    }
    void reserve(int n)
    {
        map.reserve(n);
    }
};
struct ThisCls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    Sub18 m_18;
    Sub30 m_30;
    CloneArray<Elem64> m_48;
    CloneArray<__m128> m_54;
    __m128 m_60;
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
    int m_1b0;
    unsigned char m_1b4;
    unsigned char m_1b5;
    unsigned char m_1b6;
    unsigned char m_1b7;
    int m_1b8;
    int m_1bc;
    ThisCls* FUN_00d7f6a0();
    ThisCls* AllocateAndProcessEntries_00d7f720();
};

// @fnv 0x00d7f720
// src: GUESS 0x00d7f720 (confidence: low)
ThisCls* ThisCls::AllocateAndProcessEntries_00d7f720()
{
    Singleton* s = reinterpret_cast<Singleton*>(hkMemoryRouter_getInstance());
    Allocator* alloc = s->m_10;
    ThisCls* dst;
    void* fields2 = alloc->Alloc(0x1c0);
    if (fields2 != 0)
    {
        dst = ((ThisCls*)fields2)->FUN_00d7f6a0();
    }
    else
    {
        dst = 0;
    }
    dst->m_00 = m_00;
    dst->m_04 = m_04;
    dst->m_08 = m_08;
    dst->m_0c = m_0c;
    dst->m_d0 = m_d0;
    dst->m_e0 = m_e0;
    dst->m_f0 = m_f0;
    dst->m_100 = m_100;
    dst->m_110 = m_110;
    dst->m_120 = m_120;
    dst->m_130 = m_130;
    dst->m_140 = m_140;
    dst->m_150 = m_150;
    dst->m_160 = m_160;
    dst->m_1a0 = m_1a0;
    dst->m_1a4 = m_1a4;
    dst->m_1a8 = m_1a8;
    dst->m_1ac = m_1ac;
    dst->m_1b4 = m_1b4;
    dst->m_1b5 = m_1b5;
    dst->m_48.SetSizeAndGrow(m_48.m_iArrayLength);
    {
        int i = 0;
        if (m_48.m_iArrayLength > 0)
            do
            {
                dst->m_48[i] = m_48[i];
                ++i;
            } while (i < m_48.m_iArrayLength);
    }
    dst->m_54.SetSizeAndGrow(m_54.m_iArrayLength);
    {
        int i = 0;
        if (m_54.m_iArrayLength > 0)
            do
            {
                dst->m_54[i] = m_54[i];
                ++i;
            } while (i < m_54.m_iArrayLength);
    }
    CloneMap<unsigned long, unsigned long> low;
    if (m_18.m_10)
    {
        low.reserve(m_18.m_10);
        CloneNode* node = firstNode(m_18.m_0c);
        if (node)
        {
            do
            {
                int v = dst->m_18.CloneNode(node);
                low.insert((unsigned long)node, v);
                node = node->m_04;
            } while (node);
        }
    }
    if (m_30.m_10)
    {
        CloneMap<unsigned long, unsigned long> a;
        a.reserve(m_30.m_10);
        CloneNode* node = firstNode(m_30.m_0c);
        if (node)
            do
            {
                CloneFace* base = dst->m_30.hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Triangle_struct_hkgpAbstractMeshDefinitions_List_struct_hkgpConvexHullImpl_Vertex_struct_hkgpConvexHull_Vertex_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Vertex_32_struct_hkContainerHeapAllocator_Item_struct_hkGeometryProcessing_PoolAllocator_struct_hkgpConvexHullImpl_Triangle_32_struct_hkContainerHeapAllocator_allocate(node);
                unsigned long* x = base->vertices;
                int count = 3;
                do
                {
                    *x = low.find(*x, 0);
                    ++x;
                    --count;
                } while (count);
                for (int i = 0; i < 3; ++i)
                {
                    CloneEdge current(base, i);
                    CloneEdge mapped(a.find(current.adjacent().key(), 0));
                    if (mapped.face)
                    {
                        a.remove(current.adjacent().key());
                        current.bind(mapped);
                    }
                    else
                    {
                        a.insert((unsigned long)CloneEdge((CloneFace*)node, i).key(), current.key());
                    }
                }
                node = node->m_04;
            } while (node);
    }

    return dst;
}
