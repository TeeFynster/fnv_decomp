
// src/staging/blk_00dc0000_o2_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00dc0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00dc0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct FUN_00dd4b10_struct
{
    void __thiscall AssignFromSource(const void* p);
};
struct FUN_00dd4b40_Class
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    void __thiscall SetValues(const unsigned int* p);
};
struct FUN_00dd5170_class
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    void __thiscall CopySixInts(const int* p);
};
struct FUN_00dd8c20_class
{
    int m_field;
    int SumListValues();
};
template <class K, class V, class O> class HashEntryTable
{
  public:
    void clear();
};
template <class K> struct KeyMarker
{
};
struct FUN_00ddf050_cls
{
    void ClearContainer();
};
extern "C" void __cdecl hkpConstraintConstructionKit_computeConstraintInfo(int* p1, int* p2);
struct FUN_00dd0420_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    FUN_00dd0420_Class* __thiscall hkpGenericConstraintDataScheme_hkpGenericConstraintDataScheme(int arg);
};
struct FUN_00dd4b70_class
{
    void __thiscall hkpMoppCompiler_enableInterleavedBuilding(unsigned char value);
};
extern int DAT_0102e388;
struct FUN_00dd51d0_class
{
    int m_00;
    int m_04;
    int m_08;
    void InitializeFields_00dd51d0();
};
struct FUN_00ddfb70_cls
{
    int m_00;
    int m_04;
    FUN_00ddfb70_cls* hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment();
};
struct FUN_00dccb70_Class
{
    void SetTableValue(int arg1, unsigned short value);
};
struct CountArray
{
    int m_00;
    int m_04;
    int m_08;
    void __thiscall EnsureCapacity(void* p, int n);
};
void* __cdecl _D1A0E0GetMemoryRouter();
struct FUN_00dc9e70_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    FUN_00dc9e70_Class* InitializeFields_00dc9e70();
};
struct FUN_00dcc5a0_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, int);
};
struct FUN_00dcc5a0_class
{
    int m_00;
    int m_04;
    FUN_00dcc5a0_vt* m_08;
    FUN_00dcc5a0_class* ProcessAndReturnValue_00dcc5a0(int arg);
};
struct FUN_00cb0a70
{
    void __thiscall m(int);
};
void __cdecl Object_ProcessState_00dccae0(void* a, void* b);
struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};
void __cdecl Runtime_UpdateState_00dccb10(char* p);
extern int DAT_010d77b4[];
extern void __cdecl _Deallocate(void* p);
struct FUN_00dcd4b0_Class
{
    void* m_ppVirtualMethodTable;
    FUN_00dcd4b0_Class* __thiscall InitializeAndMaybeFree(int flags);
};
struct DDA7C0OStream
{
    void __thiscall writeInt32(unsigned int);
};
struct FUN_00dda6b0_Class
{
    void __thiscall WriteUInt32Triple(const unsigned int* p);
};
struct D2B3D0Map
{
    void clear();
};
struct FUN_00ddf030_Class
{
    void __thiscall Clear_Thunk(int arg);
};
extern int DAT_010d8094;
struct FUN_00ddfb80_s
{
    void* m_vt;
    unsigned short m_02;
    unsigned short m_04;
    unsigned short m_06;
    unsigned short m_08;
    void* m_0c;
    void* m_10;
};
FUN_00ddfb80_s* __fastcall hkpShapeDisplayBuilder_hkpShapeDisplayBuilder(FUN_00ddfb80_s* self, int, const void* src);
int __stdcall Object_ReturnArgument_00dc1660(int a1);
extern int DAT_011b7b88;
struct FUN_00dc1670_cls
{
    int m_00;
    FUN_00dc1670_cls* hkStructureLayout_hkStructureLayout();
};
void __stdcall hkIArchive_readArrayGeneric(float* out, int a, int b);
float hkIArchive_readFloat32();
struct ArrayBlock
{
    unsigned int* values;
    int size;
    unsigned int reservedAndFlags;
};
struct AllocatorState
{
    int unk00, unk04, unk08, unk0C;
    void* pool;
    void* GetPool() const
    {
        return pool;
    }
};
extern "C" AllocatorState* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl hkArrayUtil__reserve(void*, ArrayBlock*, int, int);
struct ArrayHost
{
    int unk00, unk04, unk08;
    ArrayBlock array;
    void ResizeArray(int desired);
};
struct FUN_00dcc180_Interface
{
    virtual void FUN_00dcc180_00();
    virtual void FUN_00dcc180_01();
    virtual void FUN_00dcc180_02();
    virtual void FUN_00dcc180_03(unsigned char* value);
};
struct FUN_00dcc180_Class
{
    int unk00;
    int unk04;
    FUN_00dcc180_Interface* unk08;

    unsigned char* __thiscall hkIstream_isOk(unsigned char* value);
};
struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void Forward(int a);
};
struct FUN_00dcc660_cls
{
    int unk00;
    int unk04;
    Target* m_pFlagTarget;
    void InvokeVirtualMethod_00dcc660(int a);
};
struct FUN_00dcc670_Manager
{
    virtual void FUN_00dcc670_v0();
    virtual void FUN_00dcc670_v1();
    virtual void FUN_00dcc670_v2();
    virtual int FUN_00dcc670_v3(int* value);
};
struct FUN_00dcc670_Class
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;

    int* __thiscall InitFromValue(int* value);
};
extern int DAT_010d7540;
extern FUN_00dcc670_Manager* DAT_01268364;
extern int g_unk01269bb4;
int* __cdecl Object_GetGlobalObjectAddress_00dccb00();
extern int DAT_01269be4;
int* __cdecl Runtime_GetDAT01269be4Address();
struct FUN_00dced30_cls
{
    virtual void m_v00(int arg);
};
void __cdecl Object_ForwardCall_00dced30(FUN_00dced30_cls* pObject);
extern int DAT_01269c44;
int __cdecl Object_ComputeValue_00dced40();
struct FUN_00d4dfc0_class
{
    void __thiscall FUN_00d4dfc0(unsigned int value);
};
void __cdecl Runtime_ProcessState_00dced50(FUN_00d4dfc0_class* object, unsigned int value);
struct S_00dd4bb0_Class
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned int GetPackedValue();
};
extern float DAT_0101e2bc;
extern float DAT_010181bc;
extern float DAT_0101df44;
struct FUN_00dd50f0_cls
{
    float m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    unsigned char m_14;
    FUN_00dd50f0_cls* hkpMoppSplitter_hkpMoppSplitParams_hkpMoppSplitParams(int mode);
};
// FUN_00dd5150: initialises six float members of the object: five of them to
// 1.0 and the last one to the global float constant DAT_01016248; returns the
// object pointer.
extern float DAT_01016248;
struct FUN_00dd5150_cls
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0c;
    float m_f10;
    float m_f14;
    void* hkpMoppCostFunction_hkpMoppSplitCostParams_hkpMoppSplitCostParams(int arg);
};
extern void* DAT_010d7ba8;
struct FUN_00dd5150_component
{
    void hkpMoppCostFunction_hkpMoppSplitCostParams_hkpMoppSplitCostParams(int value);
};
struct FUN_00dd51a0
{
    void** vftable;
    short unk04;
    short enabled06;
    FUN_00dd5150_component component08;

    FUN_00dd51a0(const int* data);
    void CopySixInts(const int* data);
};
unsigned char* __cdecl LessThan(unsigned char* output, const unsigned int* left, const unsigned int* right);
unsigned char* __cdecl CompareLessThan(unsigned char* outValue, unsigned int left, unsigned int right);
// Constructor for the object handled by FUN_00dd7110.
//
// The class holds a run of scalar members; every one of them is zeroed by the
// constructor except m_iUninitialised08, which is left for the caller to fill
// in later.  The ten members cleared through the initialiser list are stored
// first (in declaration order), the two cleared in the constructor body are
// stored afterwards.
struct FUN_00dd7110_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    FUN_00dd7110_cls();
};
struct FUN_00dd8bc0_Node
{
    int m_00;
    FUN_00dd8bc0_Node* m_next;
    int m_08;
    int m_0c;
    unsigned char* m_pRayStart;
    unsigned char* m_kRayEnd;
};
struct FUN_00dd8bc0_cls
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
    FUN_00dd8bc0_Node m_kNode;
    void _makeTopValid();
    unsigned int GetUsedMemory();
};
struct S_00dd8cf0_Ret
{
    bool v;
    S_00dd8cf0_Ret()
    {}
};
struct S_00dd8cf0
{
    bool __thiscall IsValidChunk(int v);
    S_00dd8cf0_Ret __thiscall AllMatch(const int* arr, int n);
};
extern int DAT_010d7c34;
// Object built by Construct: it installs its own vtable, clears a couple
// of members and then hands the object over to FUN_00dd7f10 for a full reset.
struct SpawnedObject
{
    int* m_vptr;
    int m_04;
    int m_08;
    int m_0c;
    int* m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int* m_a4;
    int* m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    void _init_00dd7f10();
    SpawnedObject* Construct(int value);
};
// src: HAVOK_LIB 0x00dd7f10
void SpawnedObject::_init_00dd7f10()
{
    m_c0 = 0;
    m_bc = 0;
    m_08 = 0;
    m_0c = 0;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_5c = 0;
    m_60 = 0;
    m_64 = 0;
    m_68 = 0;
    m_6c = 0;
    m_70 = 0;
    m_74 = 0;
    m_78 = 0;
    m_7c = 0;
    m_80 = 0;
    m_84 = 0;
    m_88 = 0;
    m_8c = 0;
    m_90 = 0;
    m_94 = 0;
    m_9c = 0;
    m_14 = 0;
    m_a0 = 3;
    m_10 = (int*)&m_9c;
    m_a8 = (int*)&m_a4;
    m_a4 = (int*)&m_a4;
}
struct FUN_00ddfbb0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
    void ClearField10();
};
void __cdecl FUN_00c90510();
struct FUN_00dcc130_Class
{
    int* m_vtbl;
    unsigned short unk04;
    unsigned short enabled06;
    int unk08;
    int* __thiscall hkIstream_hkIstream(int* value);
};
struct S_00dcc740_Cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    S_00dcc740_Cls* __thiscall ReadSignedShort(unsigned short* out);
};
struct IniTokenStream
{
    void* m_vt;
};
extern "C" void ReadIniLine(void);
// src: HAVOK_LIB 0x00dcc240
static __declspec(noinline) unsigned short readInteger64(IniTokenStream* stream, unsigned char* negative)
{
    *negative = 0;
    ReadIniLine();
    return (unsigned short)(int)(stream != 0);
}
extern void(__stdcall* DAT_00fdf05c)(int*);
extern void(__stdcall* DAT_00fdf100)(int*);
struct Lock_dd9
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    int uNewnk;
    int uTmpnk;
    int* m_pkCriticalSection;
    int FindEntry(int iKey);
    int InvokeRecord(int iIndex, int iArg);
    int hkProcessFactory_createProcess(int iKey, int iArg);
};
extern int DAT_010d7db8;
struct Bool1
{
    char v;
    Bool1(char x) : v(x)
    {}
};
struct Base_00d60b40
{
    void* vft;
    void __thiscall FUN_00d60b40(int a, Bool1 b);
};
struct FUN_00dda690 : Base_00d60b40
{
    FUN_00dda690(int a);
};
struct S_00dcc240_Reader
{
    int unk00;
    int unk04;
    unsigned short unk08;
};
struct S_00dcc790_Class
{
    unsigned int m_00;
    unsigned int m_04;
    S_00dcc240_Reader* m_08;

    S_00dcc790_Class* __thiscall ReadSignedValue(unsigned short* result);
};
extern "C" void __cdecl SkipWhitespace(void);
// src: HAVOK_LIB 0x00dcc240
static __declspec(noinline) unsigned short readInteger64(unsigned char* ok, S_00dcc240_Reader* reader)
{
    *ok = 0;
    SkipWhitespace();
    return reader->unk08;
}
typedef __int64 FNVInt64;
struct S_00dcc8a0_Reader
{
    virtual int read(int count);
    virtual int charAt(int pos);
};
struct S_00dcc8a0_Handle
{
    S_00dcc8a0_Reader* reader;
};
struct FUN_00dcc8a0_Class
{
    int unk00;
    int unk04;
    S_00dcc8a0_Handle unk08;

    FUN_00dcc8a0_Class* __thiscall ParseSignedInt(FNVInt64* out);
};
static __declspec(noinline) FNVInt64 S_00dcc8a0_ParseInt(S_00dcc8a0_Handle h, unsigned char* neg)
{
    *neg = 0;
    S_00dcc8a0_Reader* reader = h.reader;
    int count = reader->charAt(0);
    if (count < 3)
        return 0;
    return (FNVInt64)reader->read(count);
}

struct Stream285
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int Read(char*, int);
    virtual void Advance(int);
    virtual void slot6();
    virtual void BeginPeek(int);
    virtual void EndPeek();
};
inline bool Space285(char c)
{
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}
static __declspec(noinline) void SkipWhitespace285(Stream285* stream)
{
    char buffer[64];
    stream->BeginPeek(64);
    int count = stream->Read(buffer, 64);
    while (count)
    {
        int i = 0;
        for (; i < count; ++i)
            if (!Space285(buffer[i]))
            {
                stream->EndPeek();
                stream->Advance(i);
                return;
            }
        stream->BeginPeek(64);
        count = stream->Read(buffer, 64);
    }
}
int __cdecl j_strncmp(const char*, const char*, unsigned);
struct Reader285
{
    int unk00, unk04;
    Stream285* stream;
    Reader285* ReadData_00dcc4a0(bool* value);
};
// @fnv 0x00dcc4a0
// src: GUESS 0x00dcc4a0 (confidence: low)
Reader285* Reader285::ReadData_00dcc4a0(bool* value)
{
    SkipWhitespace285(stream);
    char buffer[6];
    stream->BeginPeek(6);
    int count = stream->Read(buffer, 6);
    if (count >= 4 && j_strncmp(buffer, "true", 4) == 0 && (count == 4 || Space285(buffer[4])))
    {
        *value = true;
        stream->EndPeek();
        stream->Advance(4);
        return this;
    }
    if (count >= 5 && j_strncmp(buffer, "false", 4) == 0 && (count == 5 || Space285(buffer[5])))
    {
        *value = false;
        stream->EndPeek();
        stream->Advance(5);
        return this;
    }
    stream->EndPeek();
    return this;
}
