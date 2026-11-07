// src/staging/blk_00dc0000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00dc0000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


#include <windows.h>
#include "../../include/hkArray.h"
#include "../../include/hkBool.h"
#include "../../include/hkLargeBlockAllocator.h"
#include "../../include/hkMemoryRouter.h"
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
void __cdecl Object_ProcessState_00dccae0(void* a, void* iValue);
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
unsigned char* __cdecl CompareLessThan(unsigned char* pResult, unsigned int left, unsigned int right);
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
static unsigned short readInteger64(unsigned char* ok, S_00dcc240_Reader* reader);
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
// GetEntryRef (0x00dcb1a0) indexes 8-byte records; the Xbox PDB hkEntry is 12 bytes.
struct TableFilterEntry
{
    int m_uiFilterValue;
    int m_04;
};
struct hkTableDCB1
{
    int m_00;
    int m_04;
    int m_08;
    TableFilterEntry* m_entries;
};
class hkOwnerDCB1;
struct hkRefDCB1
{
    const hkOwnerDCB1* m_pOwnerObject;
    int m_uiFilterValue;

    hkRefDCB1(const hkOwnerDCB1* pkOwner, int iValue) : m_pOwnerObject(pkOwner), m_uiFilterValue(iValue)
    {}
};
class hkOwnerDCB1
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkTableDCB1* m_table;

    hkRefDCB1 GetEntryRef(int iIndex) const;
};
struct S_00dcc600_Inner
{
    int __thiscall ReadChar();
};
static __declspec(noinline) int S_00dcc600_Reset(S_00dcc600_Inner* stream)
{
    int count = 0;
    int c = stream->ReadChar();

    while (c != -1 && count < 4)
    {
        ++count;
        c = stream->ReadChar();
    }

    return count;
}
struct S_00dcc600_Class
{
    int m_00;
    int m_04;
    S_00dcc600_Inner* m_08;

    int __thiscall ReadUntilValue(unsigned char* buffer, int length, signed char value);
};
void __cdecl nullsub_121();
void __cdecl nullsub_122();
void __cdecl Object_DoNothing_00dd4b00();
struct Bool388
{
    unsigned char value;
    Bool388()
    {}
    Bool388(unsigned char v) : value(v)
    {}
};
struct Block388
{
    unsigned int previousSize, sizeAndFlags;
    unsigned char Flags() const
    {
        return reinterpret_cast<const unsigned char*>(&sizeAndFlags)[0];
    }
};
struct Allocator388
{
    unsigned int unk00, unk04, unk08;
    Block388* lower;
    Bool388 ValidateBlock(Block388* block);
};
static void Runtime_UpdateState_00dd8fd0(unsigned char* a, unsigned char* b);
extern "C" unsigned char* GetPtr();
void Caller(unsigned char* a);
// The c85750 router exposes its heap at +0x10, as in the shared hkMemoryRouter.
namespace hkRouterDDFB {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return *hkRouterDDFB::hkMemoryRouter_getInstance().m_heap;
}
struct hkPairDDFB
{
    void* m_object;
    void* m_key;

    hkPairDDFB(void* object, void* key) : m_object(object), m_key(key)
    {}
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
};
template <class T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    new (m_data + m_iElementCount) T(t);
    m_iElementCount++;
}
class hkOwnerDDFB
{
  public:
    int unk00;
    int unk04;
    hkArray<hkPairDDFB> m_pairs;

    void AddPairIfKeyAbsent(void* object, void* key);
};
struct S_00dcb0b0_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
struct S_00dcb0b0_Class
{
    int unk00;
    int unk04;
    int unk08;
    S_00dcb0b0_Target* unk0C;

    void __thiscall CallTargetV6();
};
struct stub_cls
{
    int unk00;
    int unk04;
};
static stub_cls* volatile g_stub_self;
static int volatile g_stub_v;
static int volatile g_stub_out;
extern "C" int stub_val(void);
static float readFloat(int arg);
float stub_caller(void);
class FUN_00dcc5c0_cls
{
  public:
    int unk00;
    int unk04;
    int m_08;

    FUN_00dcc5c0_cls* __thiscall GetFloatValue(float* out);
};
// ReadSignedInt: thiscall member returning this; parses an int through FUN_00dcc240
// (per-TU private convention: stream on the stack, sign-flag address in EAX),
// negates it when the flag byte is set, and stores it through the int* argument.
struct S_00dcc7e0_Stream
{
    void* m_vt;
};
extern "C" void ReadIniLine(void);
// src: HAVOK_LIB 0x00dcc240
static __declspec(noinline) int readInteger64(S_00dcc7e0_Stream* stream, unsigned char* negative)
{
    *negative = 0;
    ReadIniLine();
    return (int)(stream != 0);
}
struct FUN_00dcc7e0_Class
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;

    FUN_00dcc7e0_Class* __thiscall ReadSignedInt(int* out);
};
typedef __int64 FNVInt64;
struct S_dcc860_Reader
{
    virtual int read(int count);
    virtual int charAt(int pos);
};
struct S_dcc860_Handle
{
    S_dcc860_Reader* reader;
};
struct FUN_00dcc860_Class
{
    int unk00;
    int unk04;
    S_dcc860_Handle unk08;

    FUN_00dcc860_Class* __thiscall ReadInt64(FNVInt64* out);
};
static __declspec(noinline) FNVInt64 S_dcc860_ParseInt(S_dcc860_Handle h, unsigned char* neg)
{
    *neg = 0;
    S_dcc860_Reader* reader = h.reader;
    int count = reader->charAt(0);
    if (count < 3)
        return 0;
    return (FNVInt64)reader->read(count);
}
struct S00dcd1b0_Pool
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void ReturnMemory(void* p, int size);
};
struct S00dcd1b0_Obj
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
    char* m_34;
    int m_38;
    int unk3C;
    ArrayBlock m_40;
    unsigned char m_4c;
    void hkpMeshShape_initWeldingInfo(int value);
};
struct S00dcd270_Rec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char unk10;
    char unk11;
    short unk12;
    int unk14;
    int unk18;
    int unk1c;
    void* unk20;
    int unk24;
    void* unk28;
    int unk2c;
    int unk30;
    int unk34;
};
struct S00dcd270_Arr
{
    S00dcd270_Rec* m_data;
    int m_iElementCount;
    int m_cap;
};
extern "C" void __cdecl ResizeAudioStream(void*, S00dcd270_Arr*, int);
extern char DAT_01267e30;
struct S00dcd270_cls
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
    S00dcd270_Arr arr;
    S00dcd270_Rec* AddRecord(const S00dcd270_Rec* a0);
};
// The original 0x00dd8c40 chunk validator belongs to hkLargeBlockAllocator;
// its unused local declaration and partial Chunk copy are unnecessary in this RTM unit.
extern "C" int getCstyleArraySize();
int Object_ProcessAndReturnValue_00dc1be0();
struct S_00dc6fc0_Target
{
    virtual void v00();
    virtual int v01();
};
struct S_00dc6fc0_Class
{
    int unk00;
    int unk04;
    int unk08;
    S_00dc6fc0_Target* m_0c;

    int __thiscall ProcessAndTransformResult_00dc6fc0();
};
struct TokenReader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int read(void* buffer, int count);
    virtual void skip(int count);
    virtual void v6();
    virtual void prepare(int count);
    virtual void reset();
};
static void SkipWhitespace(TokenReader* stream);
extern TokenReader* volatile inputStream;
void MatchCaller();
struct CpuOpaque;
extern CpuOpaque DAT_01269c14;
CpuOpaque* __cdecl Runtime_GetDAT01269c14Address();
struct RefObj
{
    void __thiscall FUN_00c905b0();
};
inline void memCpy4_d061(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}
template <class T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        memCpy4_d061(m_data + index, m_data + m_iElementCount, sizeof(T));
}
struct FUN_00dceb90_Class
{
    void* vftable;
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
    hkArray<RefObj*> m_refs;
    void RemoveRef(int index);
};
#include <math.h>
struct SubB
{
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
};
struct ObjB
{
    float f00;
    SubB* p4;
    int u08;
    float f0c;
    float f10;
    float f14;
};
struct ObjA
{
    int u00;
    int u04;
    signed char m08;
    unsigned char u09;
    unsigned char u0a;
    unsigned char u0b;
    float f0c;
    float f10;
    union
    {
        float f14;
        void* p14;
    } u14;
    float f18;
    float f1c;
    float f20;
};
__forceinline float Limit(const float& current, const float& target, const float& d, const float& limit)
{
    float ad = fabsf(d);
    if (ad > limit)
        return target + (d > 0.0f ? limit : -limit);
    return current;
}
__forceinline float Clamp(const float& value, const float& hi, const float& lo)
{
    return value < lo ? lo : (hi < value ? hi : value);
}
void __cdecl _hkCalcMotorData(ObjA* a, ObjB* b, float* out);
#ifndef _INCLUDED_MM2
// Exe 0x00dcfec0 FUN_00dcfec0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
#endif
#ifndef _INCLUDED_MM2
extern "C"
{
    LocalM128 _mm_setzero_ps();
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_or_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    int _mm_movemask_ps(LocalM128);
}
#endif
extern LocalM128 DAT_010c7170;
static __forceinline LocalM128 choose(LocalM128 mask, LocalM128 yes, LocalM128 no)
{
    return _mm_or_ps(_mm_andnot_ps(mask, no), _mm_and_ps(mask, yes));
}
static __forceinline LocalM128 sum4(LocalM128 v)
{
    LocalM128 pair = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4e), v);
    return _mm_add_ps(_mm_shuffle_ps(pair, pair, 0xb1), pair);
}
static __forceinline LocalM128 dot4(LocalM128 a, LocalM128 b)
{
    return sum4(_mm_mul_ps(a, b));
}
struct OW
{
    const LocalM128* p;
    OW(const LocalM128* q) : p(q)
    {}
};
static int hkpProcessFlyingColors(const LocalM128* self, OW other, const LocalM128* a);
volatile int g_s, g_a, g_o, g_r;
void mask_test_caller();
static void CopyFloatsFromBytes(float* dst, const unsigned char* src);
unsigned char volatile g_src[4];
float volatile g_dst[4];
void caller();
struct BEStoreTarget
{
    unsigned char m_00;
    unsigned char m_01;
    unsigned char m_02;
    unsigned char m_03;
    unsigned char m_04;
};
extern "C" unsigned int be_store_value(void);
static void StoreBigEndian(BEStoreTarget* self, unsigned int value);
void be_store_caller(BEStoreTarget* self);
// @fnv 0x00dcb460
struct DispatchTarget
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void forward(int value);
};
struct Entry
{
    int key;
    DispatchTarget* target;
};
struct Table
{
    int a, b, c;
    Entry* entries;
    unsigned int StructArrayImplementation__find(unsigned int);
    DispatchTarget* entryAt(unsigned int i)
    {
        return entries[i].target;
    }
};
struct Owner
{
    int a, b, c;
    Table* table;
    int context;
    void StructArrayImplementation_Object_asObject(unsigned int);
};
// src: XBOX_PDB 0x00dcb460
void Owner::StructArrayImplementation_Object_asObject(unsigned int i)
{
    table->entryAt(table->StructArrayImplementation__find(i))->forward(context);
}
#include <stdlib.h>
// Text reader: read the next number as a double.
class DCC5E0Stream
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Skip(int iCount);
    int Peek();
    char* m_pcCursor;
};
static __declspec(noinline) double DCC5E0ReadNumber(DCC5E0Stream* pkStream)
{
    double dValue = strtod(pkStream->m_pcCursor, &pkStream->m_pcCursor);
    return dValue;
}
class DCC5E0Reader
{
  public:
    int unk00;
    int unk04;
    DCC5E0Stream* m_pDataStream;

    DCC5E0Reader& ReadDouble(double& rdValue);
};
// Adjustor thunk: the secondary-base (+0x10) vtable entry for an override defined on the derived class.
class DD470Primary
{
  public:
    virtual void FUN_00dcd470();
    int unk04;
    int unk08;
    int unk0C;
};
class DD470Secondary
{
  public:
    virtual void FUN_00dcd470();
};
class DD470Derived : public DD470Primary, public DD470Secondary
{
  public:
    DD470Derived();
// @fnv 0x00dcd470
    virtual void FUN_00dcd470();
};
DD470Derived::DD470Derived()
{}
// Stand-in for the class owning this function.
//   +0x0c : int*   array of packed triples
//   +0x18 : CRITICAL_SECTION*  shared lock
class FUN_00dd9240_cls
{
  public:
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int* m_pEntryData;
    int m_unk10;
    int m_unk14;
    CRITICAL_SECTION* m_pCrit;

    int hkProcessFactory_getProcessName(int index);
};
int __cdecl hkString_strCmp(unsigned int entry, unsigned int flag);
// Stand-in for the class owning this function.
//   +0x0c : int*   array of 12-byte records (first dword = flagged pointer)
//   +0x10 : int    record count
//   +0x18 : CRITICAL_SECTION*  shared lock
class FUN_00dd9270_cls
{
  public:
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int* m_pEntryData;
    int m_uiItemCount;
    int m_unk14;
    CRITICAL_SECTION* m_pCrit;

    int FindEntry(unsigned int flag);
};
// Stand-in for the class owning this function.
//   +0x0c : record*  array of 12-byte records
//   +0x18 : CRITICAL_SECTION*  shared lock
class FUN_00dd92f0_cls
{
  public:
    struct Record
    {
        int m_i00;
        int(__cdecl* m_pFn)(int);
        int m_i08;
    };

    int m_i00;
    int m_i04;
    int m_i08;
    Record* m_pRecords;
    int m_i10;
    int m_i14;
    CRITICAL_SECTION* m_pCrit;

    int InvokeRecord(int index, int arg);
};
double FUN_00ecdf2d(const char* s, char** end);
static float readFloat(TokenReader* stream);
float MatchCaller(TokenReader* s);
void __stdcall Object_DoNothing_00dccb60(int value);
extern "C"
{
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    void _mm_store_ss(float*, LocalM128);
}
class S00dd0ff0_SimdReal
{
  public:
    S00dd0ff0_SimdReal(const LocalM128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    LocalM128 m_vValue;
};
class S00dd0ff0_Vector4
{
  public:
    void setMul4(const S00dd0ff0_Vector4& a, const S00dd0ff0_Vector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void mul4(const S00dd0ff0_Vector4& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    void add4(const S00dd0ff0_Vector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    void sub4(const S00dd0ff0_Vector4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    void setAdd4(const S00dd0ff0_Vector4& a, const S00dd0ff0_Vector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void setW(const S00dd0ff0_Vector4& w)
    {
        m_vComponents = _mm_shuffle_ps(m_vComponents, _mm_unpackhi_ps(m_vComponents, w.m_vComponents), 0xc4);
    }
    void setBroadcast(const S00dd0ff0_Vector4& v, int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        }
        else
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
        }
    }
    S00dd0ff0_SimdReal horizontalAdd3() const
    {
        LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xySum);
    }
    S00dd0ff0_SimdReal horizontalAdd4() const
    {
        LocalM128 sum0 = _mm_add_ps(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x4e), m_vComponents);
        LocalM128 sum1 = _mm_shuffle_ps(sum0, sum0, 0xb1);
        return _mm_add_ps(sum0, sum1);
    }
    LocalM128 m_vComponents;
};
struct S00dd0ff0_VelocityAccumulator
{
    unsigned char m_type;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    S00dd0ff0_Vector4 m_vLinearVelocity;
    S00dd0ff0_Vector4 m_vAngularVelocity;
    S00dd0ff0_Vector4 m_vInverseInertiaAndMass;
};
template <typename TYPE> inline const TYPE* S00dd0ff0_addByteOffsetConst(const TYPE* base, long offset)
{
    return reinterpret_cast<const TYPE*>(reinterpret_cast<const char*>(base) + offset);
}
struct S00dd0ff0_AccumulatorOffset
{
    int m_offset;
    const S00dd0ff0_VelocityAccumulator& getAccumulator(const S00dd0ff0_VelocityAccumulator* base)
    {
        return *S00dd0ff0_addByteOffsetConst(base, m_offset);
    }
};
class S00dd0ff0_Jacobian
{
  public:
    S00dd0ff0_Vector4 m_kLinearJacobian;
    S00dd0ff0_Vector4 m_kAngularVelocity[2];

    float getDiag(const S00dd0ff0_VelocityAccumulator& mA, const S00dd0ff0_VelocityAccumulator& mB) const
    {
        S00dd0ff0_Vector4 ang0;
        ang0.setMul4(m_kAngularVelocity[0], m_kAngularVelocity[0]);
        S00dd0ff0_Vector4 ang1;
        ang1.setMul4(m_kAngularVelocity[1], m_kAngularVelocity[1]);
        ang0.mul4(mA.m_vInverseInertiaAndMass);
        ang1.mul4(mB.m_vInverseInertiaAndMass);
        ang0.add4(ang1);
        S00dd0ff0_Vector4 dw;
        dw.setAdd4(mA.m_vInverseInertiaAndMass, mB.m_vInverseInertiaAndMass);
        ang0.setW(dw);
        float x = ang0.horizontalAdd4();
        return float(x + 1.1920928955078125e-07);
    }

    float getNonDiagDifferentObjects_With2ndBodyFromFirstObject(const S00dd0ff0_VelocityAccumulator& mB,
                                                                const S00dd0ff0_Jacobian& jacB) const
    {
        S00dd0ff0_Vector4 lin;
        lin.setMul4(m_kLinearJacobian, jacB.m_kLinearJacobian);
        S00dd0ff0_Vector4 ang;
        ang.setMul4(m_kAngularVelocity[1], jacB.m_kAngularVelocity[0]);
        S00dd0ff0_Vector4 invMassB;
        invMassB.setBroadcast(mB.m_vInverseInertiaAndMass, 3);
        S00dd0ff0_Vector4 linB;
        linB.setMul4(invMassB, lin);
        ang.mul4(mB.m_vInverseInertiaAndMass);
        ang.sub4(linB);
        return ang.horizontalAdd3();
    }
};
struct S00dd0ff0_Triple
{
    float m_lower;
    float m_diag;
    float m_upper;
};
inline float S00dd0ff0_max2(float a, float b)
{
    return (a > b) ? a : b;
}
static void FactorTridiagonal(int numConstraints, float cfm, S00dd0ff0_Jacobian* jac,
                              S00dd0ff0_AccumulatorOffset* accumsOffsets,
                              const S00dd0ff0_VelocityAccumulator* accumsBase, S00dd0ff0_Triple* triple,
                              int bufferSize);
volatile int g_S00dd0ff0_n;
volatile float g_S00dd0ff0_cfm;
volatile int g_S00dd0ff0_jac;
volatile int g_S00dd0ff0_offs;
volatile int g_S00dd0ff0_base;
volatile int g_S00dd0ff0_triple;
volatile int g_S00dd0ff0_size;
void S00dd0ff0_Caller();
struct S_00dd1180_Hdr
{
    union
    {
        float f00;
        struct
        {
            unsigned char type;
            unsigned char unk01;
            unsigned short n;
        };
    };
    unsigned int size;
    float f08;
    float f0c;
};
void hkStiffSpringChainBuildJacobian(int n, float a, float b, float c, char** src, int stride, int u1, int u2, char** pp);
typedef LocalM128* V;
struct Wrap
{
    V p;
    Wrap(V q) : p(q)
    {}
};
static V Object_ProcessAndReturnValue_00dd3020(V B, V A, V C, V O, Wrap E, V D, V M1, V M2);
void call_interleave(V B, V A, V C, V O, Wrap E, V D, V M1, V M2);

namespace S00dcfec0_Intrinsics {
extern "C"
{
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_sqrt_ss(LocalM128);
}
}

float __cdecl Atan2(float a, float b);

struct S00dcfec0_SimdReal
{
    LocalM128 m_vValue;
    __forceinline S00dcfec0_SimdReal(float x) : m_vValue(S00dcfec0_Intrinsics::_mm_load_ss(&x))
    {}
    __forceinline S00dcfec0_SimdReal(LocalM128 r) : m_vValue(r)
    {}
    __forceinline operator float() const
    {
        float s;
        ::_mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct S00dcfec0_V
{
    LocalM128 m_vComponents;

    template <int I> __forceinline S00dcfec0_V permuted() const
    {
        S00dcfec0_V r;
        r.m_vComponents = ::_mm_shuffle_ps(m_vComponents, m_vComponents, I);
        return r;
    }
    __forceinline void permuteC()
    {
        m_vComponents = ::_mm_shuffle_ps(m_vComponents, m_vComponents, 0xc9);
    }
    __forceinline void permuteD()
    {
        m_vComponents = ::_mm_shuffle_ps(m_vComponents, m_vComponents, 0xd2);
    }
    __forceinline S00dcfec0_V operator*(const S00dcfec0_V& other) const
    {
        S00dcfec0_V r;
        r.m_vComponents = ::_mm_mul_ps(m_vComponents, other.m_vComponents);
        return r;
    }
    __forceinline S00dcfec0_V operator-(const S00dcfec0_V& other) const
    {
        S00dcfec0_V r;
        r.m_vComponents = ::_mm_sub_ps(m_vComponents, other.m_vComponents);
        return r;
    }

    __forceinline void setSum(const S00dcfec0_V& a, const S00dcfec0_V& b)
    {
        m_vComponents = ::_mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline S00dcfec0_SimdReal length() const
    {
        return S00dcfec0_Intrinsics::_mm_sqrt_ss(dot3(*this).m_vValue);
    }
    __forceinline void scale(const S00dcfec0_SimdReal& x)
    {
        m_vComponents = ::_mm_mul_ps(::_mm_shuffle_ps(x.m_vValue, x.m_vValue, 0), m_vComponents);
    }

    __forceinline S00dcfec0_V()
    {}
    __forceinline S00dcfec0_V(const S00dcfec0_V& v) : m_vComponents(v.m_vComponents)
    {}
    __forceinline void operator=(const S00dcfec0_V& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline S00dcfec0_SimdReal dot3(const S00dcfec0_V& b) const
    {
        LocalM128 m = ::_mm_mul_ps(m_vComponents, b.m_vComponents);
        LocalM128 y = ::_mm_add_ss(::_mm_shuffle_ps(m, m, 0x55), m);
        return ::_mm_add_ss(::_mm_shuffle_ps(m, m, 0xaa), y);
    }
    __forceinline void crossFirst(const S00dcfec0_V& v0, const S00dcfec0_V& v1)
    {
        *this = v0.permuted<0xc9>() * v1.permuted<0xd2>() - v0.permuted<0xd2>() * v1.permuted<0xc9>();
    }
    __forceinline void crossSecond(const S00dcfec0_V& v0, const S00dcfec0_V& v1)
    {
        LocalM128 y = v1.m_vComponents;
        LocalM128 x = v0.m_vComponents;
        LocalM128 cross0 = ::_mm_mul_ps(::_mm_shuffle_ps(x, x, 0xc9), ::_mm_shuffle_ps(y, y, 0xd2));
        LocalM128 cross1 = ::_mm_mul_ps(::_mm_shuffle_ps(x, x, 0xd2), ::_mm_shuffle_ps(y, y, 0xc9));
        m_vComponents = ::_mm_sub_ps(cross0, cross1);
    }
};

struct S00dcfec0_Basis
{
    S00dcfec0_V cols[3];
    __forceinline S00dcfec0_V& column(int i)
    {
        return cols[i];
    }
};
// @fnv 0x00dcfec0
// src: GUESS 0x00dcfec0 (confidence: low)
void __cdecl Object_UpdateFields_00dcfec0(const S00dcfec0_V& a, const S00dcfec0_V& b, const S00dcfec0_V& c, const S00dcfec0_V& d,
                          S00dcfec0_V& out, float& outAngle)
{
    S00dcfec0_V axis;
    axis.setSum(b, a);
    float len = axis.length();
    if (len > (double)1e-16f)
    {
        axis.scale(1.0f / len);
    }
    else
    {
        axis = b;
    }
    S00dcfec0_Basis basis;
    {
        S00dcfec0_V& first = basis.column(0);
        S00dcfec0_V& second = basis.column(1);
        S00dcfec0_V& third = basis.column(2);
        first = axis;
        second.crossFirst(axis, d);
        third.crossSecond(second, first);
    }
    float dr = basis.column(1).dot3(c);
    float dq = basis.column(2).dot3(c);
    float angle = Atan2(dr, dq);
    outAngle = angle;
    out = axis;
}

struct AllocatorStatisticsDD8D
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
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
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    void __thiscall hkLargeBlockAllocator_calculateStatistics(unsigned int* out);
};
// @fnv 0x00dd8d70
// src: HAVOK_LIB 0x00dd8d70
void __thiscall AllocatorStatisticsDD8D::hkLargeBlockAllocator_calculateStatistics(unsigned int* out)
{
    out[0] = ((FUN_00dd8c20_class*)this)->SumListValues();
    out[1] = (unsigned int)m_c0;
    out[3] = out[0] - (unsigned int)m_c0;
    out[5] = (unsigned int)((hkLargeBlockAllocator*)this)->findLargestBlockSize();
    out[4] = 0;
}
