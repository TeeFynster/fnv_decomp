
// src/staging/blk_00da0000_o2_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/staging/blk_00da0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00da0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkResult.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/BSAudio.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkArray.h"
#include "../../include/hkBool.h"
extern "C" void __cdecl ReturnSelf(void*);
extern int DAT_010d461c;
struct FUN_00da07b0_class
{
    void __thiscall ReturnSelf(void*);
};
void __cdecl finishLoadedObjecthkSimpleLocalFrame(void* a, void* b);
void __cdecl InitBlockPool(void*);
void* __cdecl InitAndReturnTail(void* a, void* b, void* c);
void __cdecl Object_InvokeVirtualMethod_00da08c0(void** a);
extern int DAT_010c59f4;
extern int DAT_010c6bec;
void __cdecl Object_UpdateFields_00da08e0(void* a, int b);
extern int DAT_010c6fd0;
void __cdecl Runtime_UpdateState_00da0b10(int* p);
extern int DAT_010d6014;
struct FUN_00db7ab0_class
{
    void* __thiscall SetVtableAndProcessState_00db7ab0(void* a, void* b, void* c);
};
int __cdecl Crc32ShiftRight8(unsigned int a);
void __cdecl Object_HkAgent1nMachine_Destroy_Thunk(void*);
void __cdecl hkListAgent3_ProcessAndReturnValue_00da6de0(void*);
void __cdecl Hkplistagent3_HkAgent1nMachine_WarpTime_Thunk(void*);
void __cdecl Object_UpdateFields_00da6e60(void*);
void __cdecl BuildEventIndex(void);
void* __cdecl InitAndReturnTail(void* a, void* b, void* c);
void* __cdecl Runtime_ForwardCall_00da6e10(void* a, void* b, void* c);
void __cdecl Object_InitializeDispatchFunctionTable(void* p);
void __cdecl finishLoadedObjecthkpLinkedCollidable(char* a, int b);
struct FUN_00da0740_vt
{
    virtual void v0(int);
};
void __cdecl Object_InvokeVirtualMethod_00da0740(FUN_00da0740_vt* p);
struct FUN_00cb0a70_class
{
    void __thiscall ReturnSelf(int);
};
void __cdecl Object_UpdateFields_00da0760(void* a, void* b);
struct FUN_00db7cf0_class
{
    int __thiscall hkVersionPatchManager_UidFromClassVersion_getName(int a, int b);
};
extern int g_unk0126958c;
void* __cdecl Runtime_GetUnk0126958cAddress();
extern char DAT_012695bc;
char* __cdecl Runtime_GetDAT012695bcAddress(void);
extern int DAT_012695ec;
int* __cdecl Object_GetGlobalObjectAddress_00da0660(void);
extern int g_unk0126961c;
int* __cdecl Runtime_GetUnk0126961cAddress();
struct FUN_00da0720_Class
{
    virtual void vf00(int value);
};
void __cdecl Object_InvokeVirtualMethod_00da0720(FUN_00da0720_Class* param_1);
struct CpuOpaque;
extern CpuOpaque DAT_0126967c;
CpuOpaque* __cdecl Runtime_GetDAT0126967cAddress();
extern int DAT_012696c4;
int* __cdecl Runtime_GetDAT012696c4Address();
// FUN_00da08a0 : cdecl, 13 bytes
//   mov ecx, [esp+4]
//   mov eax, [ecx]
//   mov edx, [eax]
//   push 0
//   call edx
//   ret
// Calls slot 0 of the object's vtable with the argument 0.
struct FUN_00da08a0_cls
{
    virtual int v00(int a);
};
int __cdecl Object_InvokeVirtualMethod_00da08a0(FUN_00da08a0_cls* pObj);
extern int DAT_0126970c;
int* __cdecl Runtime_GetDAT0126970cAddress();
extern int DAT_01269754;
void* __cdecl Runtime_GetDAT01269754Address(void);
extern int DAT_010c6bec;
void* __cdecl Runtime_GetDAT010c6becAddress(void);
struct DA0920FinishFlag
{
    int m_bFinishing;
};
class DA0920Half
{
  public:
    short m_uiFilterValue;

    void operator=(float f)
    {
        int t = *reinterpret_cast<int*>(&f);
        m_uiFilterValue = static_cast<short>(t >> 16);
    }
};
class DA0920Base
{
  public:
    short unk004;
    short unk006;
    short unk008;
    short unk00A;
    short unk00C;
    short unk00E;
    short unk010;
    short unk012;
    short unk014;
    short unk016;
    short unk018;
    short unk01A;
    short unk01C;
    short unk01E;
    short unk020;
    short unk022;
    short unk024;
    short unk026;
    short unk028;
    short unk02A;
    short unk02C;
    short unk02E;
    short unk030;
    short unk032;
    short unk034;
    short unk036;
    short unk038;
    short unk03A;
    short unk03C;
    short unk03E;
    short unk040;
    short unk042;
    short unk044;
    short unk046;
    short unk048;
    short unk04A;
    short unk04C;
    short unk04E;
    short unk050;
    short unk052;
    short unk054;
    short unk056;
    short unk058;
    short unk05A;
    short unk05C;
    short unk05E;
    short unk060;
    short unk062;
    short unk064;
    short unk066;
    short unk068;
    short unk06A;
    short unk06C;
    short unk06E;
    short unk070;
    short unk072;
    short unk074;
    short unk076;
    short unk078;
    short unk07A;
    short unk07C;
    short unk07E;
    short unk080;
    short unk082;
    short unk084;
    short unk086;
    short unk088;
    short unk08A;
    short unk08C;
    short unk08E;
    short unk090;
    short unk092;
    short unk094;
    short unk096;
    short unk098;
    short unk09A;
    short unk09C;
    short unk09E;
    short unk0A0;
    short unk0A2;
    short unk0A4;
    short unk0A6;
    short unk0A8;
    short unk0AA;
    short unk0AC;
    short unk0AE;
    short unk0B0;
    short unk0B2;
    short unk0B4;
    short unk0B6;
    short unk0B8;
    short unk0BA;
    short unk0BC;
    short unk0BE;
    short unk0C0;
    short unk0C2;
    short unk0C4;
    short unk0C6;
    short unk0C8;
    short unk0CA;
    short unk0CC;
    short unk0CE;
    short unk0D0;
    short unk0D2;
    short unk0D4;
    short unk0D6;
    short unk0D8;
    short unk0DA;
    short unk0DC;
    short unk0DE;
    short unk0E0;
    short unk0E2;
    short unk0E4;
    short unk0E6;
    short unk0E8;
    short unk0EA;
    short unk0EC;
    short unk0EE;
    short unk0F0;
    short unk0F2;
    short unk0F4;
    short unk0F6;
    short unk0F8;
    short unk0FA;
    short unk0FC;
    short unk0FE;
    short unk100;
    short unk102;
    short unk104;
    short unk106;
    short unk108;
    short unk10A;
    short unk10C;
    short unk10E;
    short unk110;
    short unk112;
    short unk114;
    short unk116;
    short unk118;
    short unk11A;
    short unk11C;
    DA0920Half m_fWeight;

    DA0920Base(DA0920FinishFlag flag)
    {
        if (flag.m_bFinishing)
            m_fWeight = 1.0f;
    }
    virtual void vfunc00();

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
class DA0920Object : public DA0920Base
{
  public:
    DA0920Object(DA0920FinishFlag flag) : DA0920Base(flag)
    {}
    virtual void vfunc00();
};
void ConstructDA0920Object(void* p, int finishing);
extern int g_unk010c6c64;
void* __cdecl Runtime_GetUnk010c6c64Address();
extern int DAT_0126979c;
void* __cdecl Runtime_GetDAT0126979cAddress();
extern void* DAT_012697cc;
void* Object_GetGlobalObjectAddress_00da09a0();
struct CpuOpaque;
extern CpuOpaque DAT_012697fc;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00da09c0();
extern int DAT_0126982c;
void* __cdecl Object_GetGlobalObjectAddress_00da09e0();
struct CpuOpaque;
extern CpuOpaque DAT_0126985c;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00da0a00();
extern int DAT_0126988c;
void* __cdecl Object_GetGlobalObjectAddress_00da0a20();
// FUN_00da0a40 : a one-line function - getter
extern int g_target_00da0a40;
void* Object_GetGlobalObjectAddress_00da0a40();
extern int DAT_012698ec;
void* __cdecl Object_GetGlobalObjectAddress_00da0a60();
// FUN_00da0a80 : returns the address of a global data object.
extern int DAT_0126991c;
int* __cdecl Object_GetGlobalObjectAddress_00da0a80(void);
extern int DAT_0126994c;
int __cdecl Object_ComputeValue_00da0aa0();
struct CpuOpaque;
extern CpuOpaque DAT_0126997c;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00da0ac0();
extern int DAT_012699ac;
int* __cdecl Object_GetGlobalObjectAddress_00da0ae0(void);
struct FUN_00da0af0_Class
{
    virtual void vf00(int value);
};
void __cdecl Runtime_ForwardCall_00da0af0(FUN_00da0af0_Class* param_1);
extern int DAT_01269a0c;
void* __cdecl Object_GetGlobalObjectAddress_00da0b00();
extern int DAT_010c6fd0;
void* __cdecl Object_GetGlobalObjectAddress_00da0b20();
unsigned char* __cdecl CheckDuplicateValues(unsigned char* result, int* values);
struct FUN_00db0060_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    void __thiscall hk1AxisSweep_AabbInt_set(int* param_2, int param_3);
};
struct DB7570Pair
{
    unsigned int m_key;
    unsigned int m_uiFilterValue;
};
class DB7570Map
{
  public:
    int unk00;
    DB7570Pair* m_data;
    int m_iElementCount;

    hkResult Lookup(unsigned int key, unsigned int& valueOut) const;
};
extern "C" int __cdecl CompareStringsCaseInsensitive(int a1, int a2);
struct FUN_00db75b0_entry
{
    int unk00;
    int unk04;
};
struct FUN_00db75b0_class
{
    int unk00;
    FUN_00db75b0_entry* unk04;
    int unk08;

    unsigned int __thiscall hkClassEnum_getValueOfName(int a1, unsigned int* a2);
};
struct FUN_00db78a0_item
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
};
class FUN_00db78a0_cls
{
  public:
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0c(void* field, void* item);
    void hkVtableClassRegistry_registerList(FUN_00db78a0_item** a, void** b);
};
BSAudio* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}
struct MapPair
{
    unsigned int key;
    unsigned int val;
};
struct HashEntryTable
{
    MapPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int GetFirstIterator() const
    {
        int i;
        for (i = 0; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned int)-1)
                break;
        }
        return i;
    }
    int getNext(int it) const
    {
        int i;
        for (i = it + 1; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned int)-1)
                break;
        }
        return i;
    }
    bool isValid(int it) const
    {
        return it <= m_iPairCount;
    }
    unsigned int GetIteratorKey(int it) const
    {
        return m_kPrimitiveElement[it].key;
    }
    unsigned int getValue(int it) const
    {
        return m_kPrimitiveElement[it].val;
    }

    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocator& alloc, unsigned int key, unsigned int val);
};
struct MapHolder
{
    int unk00, unk04;
    HashEntryTable m_map;

    void CopyMapEntries(const MapHolder& other);
};
// ForwardToInner: forwards a 64-bit value to a member function held at this->m_08.
struct SpawnedInner
{
    void GetB(__int64 v);
};
struct SpawnedOuter
{
    int unk00;
    int unk04;
    SpawnedInner* m_08;

    void ForwardToInner(__int64 v);
};
struct CallTarget_00dba270
{
    int Splice(int, int, int, int, int);
};
struct SearchObject
{
    int ProcessAndReturnValue_00dba320(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
class DBA340Object
{
  public:
    int ProcessAndReturnValue_00dba320(void* pvA, void* pvB, void* pvC, int iFlag);
    int ForwardCall_00dba340(void* pvA, void* pvB, void* pvC);
};
struct DBB100Class
{
    const char* getName() const;
};
struct DBB100Registry
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual const DBB100Class* getClassByObject(const void* object) const;
};
struct DBB100Writer
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void WriteCString(const char* s);
};
static void Object_UpdateFields_00dbb100(const DBB100Registry* registry, const void* object, DBB100Writer* writer);
void DBB100WriteClassNames(const DBB100Registry* registry, const void** objects, DBB100Writer* writer);
hkMemoryRouter* __cdecl da06d0_getRouter();
struct Elem
{
    int unk00;
    int unk04;
};
struct Buffer
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
    Elem* m_ppData;
    int m_iElementCount;
    int m_pRayCursor;
};
void __cdecl cleanupLoadedObjecthkpLinkedCollidable(Buffer* self);
struct SweepBounds
{
    unsigned int minX, minY, minZ, key;
    unsigned int maxX, maxY, maxZ, reserved;
};
struct SweepPair
{
    unsigned int first, second;
};
inline unsigned int separatedYZ(const SweepBounds& a, const SweepBounds& b)
{
    return ((a.maxY - b.minY) | (a.maxZ - b.minZ) | (b.maxY - a.minY) | (b.maxZ - a.minZ)) & 0x80000000u;
}
inline SweepPair* emitPair(const SweepBounds& a, const SweepBounds& b, SweepPair* out, SweepPair* end, int& skipped)
{
    if (out < end)
    {
        out->first = a.key;
        out->second = b.key;
        ++out;
    }
    else
        ++skipped;
    return out;
}
__forceinline SweepPair* collideOne(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out, SweepPair* end,
                                    int& skipped)
{
    const unsigned int maxX = bounds->maxX;

    while (scan->minX < maxX)
    {
        unsigned int d0 = separatedYZ(*bounds, scan[0]);
        unsigned int d1 = separatedYZ(*bounds, scan[1]);
        unsigned int d2 = separatedYZ(*bounds, scan[2]);
        unsigned int d3 = separatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
            {
                out = emitPair(*bounds, scan[0], out, end, skipped);
            }
            if (!d1 && scan[1].minX <= maxX)
            {
                out = emitPair(*bounds, scan[1], out, end, skipped);
            }
            if (!d2 && scan[2].minX <= maxX)
            {
                out = emitPair(*bounds, scan[2], out, end, skipped);
            }
            if (!d3 && scan[3].minX <= maxX)
            {
                out = emitPair(*bounds, scan[3], out, end, skipped);
            }
        }
        scan += 4;
    }
    return out;
}
int __cdecl SweepCollidePairs(const SweepBounds* bounds, int count, SweepPair* pairs, int capacity, int& skipped);
struct DBA430Listener
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vslot10(int a, int b);
};
struct DBA430Inner
{
    void __thiscall Sync(DBA430Listener* listener);
    void __thiscall Mark();
};
BSAudio* __cdecl hkMemoryRouter_getInstance();
struct DBA430Owner
{
    int m_00;
    int m_04;
    int m_08;
    DBA430Inner m_0C;

    void Reset();
};
union FeaturePair
{
    unsigned short pair;
    struct
    {
        unsigned char first;
        unsigned char second;
        unsigned char detail;
        unsigned char flags;
    };
};
struct FeatureCache
{
    FeaturePair entries[8];
    unsigned char dimension;
    unsigned char count;
    bool result;
};
__forceinline int excludedAxis(int flags)
{
    signed char bits = static_cast<signed char>(flags >> 4);
    return (bits & 1) ? 0 : ((bits & 2) ? 1 : 2);
}
__forceinline void addCell(int& mask, int cell)
{
    int bit = 1 << (cell * 2);
    if (!(mask & (bit * 2)))
        mask += bit;
}
__forceinline void UpdateAxisMask(int& mask, unsigned char value, int axis)
{
    unsigned int bits = value >> 4;
    int x = (~bits) & 1;
    int y = (~(bits >> 1)) & 1;
    int z = (~(bits >> 2)) & 1;
    if (axis != 0)
        addCell(mask, y + 2 * z);
    if (axis != 1)
        addCell(mask, x + 2 * z + 4);
    if (axis != 2)
        addCell(mask, x + 2 * y + 8);
}
__forceinline void addEdge(int& mask, int value)
{
    int axis = value & 15;
    unsigned int bits = value >> 4;
    int x = (~bits) & 1;
    int y = (~(bits >> 1)) & 1;
    int z = (~(bits >> 2)) & 1;
    if (axis == 0)
        addCell(mask, y + 2 * z);
    else if (axis == 1)
        addCell(mask, x + 2 * z + 4);
    else
        addCell(mask, x + 2 * y + 8);
}
void __stdcall CheckFeatureCacheCoverage(FeatureCache* cache, int firstFlags, int secondFlags);
void __cdecl nullsub_104();
void __cdecl nullsub_106(void);
void nullsub_105();
void nullsub_107();
void __cdecl nullsub_109();
void __cdecl nullsub_108();
void __cdecl nullsub_110();
void __cdecl nullsub_111();
void __cdecl nullsub_112();
void __cdecl nullsub_113();
void nullsub_114();
void __cdecl nullsub_115();
void __cdecl nullsub_116();
void __cdecl nullsub_117();
void __cdecl nullsub_118();
void __cdecl nullsub_119();
void __cdecl nullsub_120();
struct CallbackHolder
{
    int unk00;
    int unk04;
    int unk08;
    void(__stdcall* callback)(void* argument);
};
extern void*(__stdcall* DAT_00fdf110)();
struct FUN_00da2b30_Class
{
    int unk00;
    int unk04;
    CallbackHolder* holder;

    void InvokeCallback();
};
extern int DAT_010d4de4;
extern int DAT_01269a9c;
struct FUN_00da2840_Obj
{
    void __thiscall hkStackTracerWin32Data_init();
};
struct FUN_00da2b90_Obj
{
    int unk00;
    short unk04;
    short unk06;
    int* unk08;

    unsigned int* __thiscall Initialize();
};
struct DA2D70Listener
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(void* object, int value);
};
struct DA2D70Object
{
    int unk00;
    unsigned short unk04;

    void __thiscall ReleaseStackTraceModule();
    void* __thiscall NotifyAudioListener(int flags);
};
extern BSAudio* __cdecl hkMemoryRouter_getInstance();
void __cdecl nullsub_21();
void __cdecl hkAgent1nMachine_VisitAllAgents(int a, int b, void* pvCallback);
void __cdecl ProcessCollisionEntry();
void __cdecl Object_HkAgent1nMachine_VisitAllAgents_Thunk(int a, int b);
void* __cdecl hkpAgent1nSector_ProcessEntries_00da3510(void*, void*);
void* __cdecl Runtime_ForwardCall_00da6e10(void* a, void* b, void* c);
extern int DAT_010cf7d4;
extern int DAT_010cf804;
extern char str_010cf830[];
struct SubObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_00d87790(int flags);
};
struct CreatedObject
{
    void* vtable;
    unsigned short allocatedSize;
    unsigned short enabled;
    const char* typeName;
    SubObject base;

    void Init()
    {
        union Flag
        {
            unsigned char byte;
            unsigned int word;
        } flag;

        allocatedSize = 0x20;
        enabled = 1;
        flag.byte = 0;
        unsigned int arg = flag.word;

        vtable = &DAT_010cf7d4;
        typeName = str_010cf830;
        base.FUN_00d87790(arg);
        vtable = &DAT_010cf804;
    }
};
void* __cdecl hkDefaultClassNameRegistrycreate();
struct FUN_00db7c00_obj
{
    virtual void vslot00(int value);
};
void __cdecl Object_Vslot00_Thunk(FUN_00db7c00_obj* p);
// 0x00db7c10  /MT /O2 /GS /EHsc /Gy   target: B8 28 9B 26 01 C3  (mov eax, offset DAT_01269b28; ret)
extern int DAT_01269b28;
int* Runtime_GetDAT01269b28Address();
extern int DAT_010cce28;
struct hkLoadedObjectDB7C
{
    int* m_ppVirtualMethodTable;
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
    FUN_00cb0a70_class m_name;
};
void __cdecl InitLoadedObject(void* pvObject, int iFinishing);
extern "C" void __cdecl FUN_00ec658f(const void*);
extern unsigned char DAT_01269b80;
extern void* DAT_010d6260;
extern void* DAT_01269b78;
extern void* FUN_00fde2a0;
extern unsigned short DAT_01269b7e;
void* __cdecl hkLogger_nullLogger();
typedef void(__cdecl* FuncDA34)();
void __cdecl ExecuteMoppAabbQuery();
void __cdecl hkCpuPairGetClosestPointsJob();
void __cdecl hkCpuWorldGetClosestPointsJob();
void __cdecl hkCpuPairLinearCastJob();
void __cdecl hkCpuWorldLinearCastJob();
void __cdecl ProcessWorkQueue();
void __cdecl ProcessAabbTree();
void __cdecl SplitJob();
void __cdecl hkpCollisionQueryJobQueueUtils_finishCollisionJob();
struct FuncTableDA34
{
    FuncDA34 m_func0;
    FuncDA34 m_func1;
    FuncDA34 m_func2;
    FuncDA34 m_func3;
    FuncDA34 m_func4;
    FuncDA34 m_func5;
    FuncDA34 m_func6;
};
extern FuncTableDA34 DAT_01269af0;
struct RegisterInfoDA34
{
    FuncTableDA34* m_table;
    int m_numFuncs;
    FuncDA34 m_funcA;
    FuncDA34 m_funcB;
};
class DispatcherDA34
{
  public:
    void SetEntry(int type, RegisterInfoDA34 info);
};
void __cdecl hkpCollisionQueryJobQueueUtils_registerWithJobQueue(DispatcherDA34* dispatcher);
void Runtime_DoNothing_00da82d0();
inline unsigned int mySeparatedYZ(const SweepBounds& a, const SweepBounds& b)
{
    return ((a.maxZ - b.minZ) | (a.maxY - b.minY) | (b.maxY - a.minY) | (b.maxZ - a.minZ)) & 0x80000000u;
}
template <bool swapPairs>
__forceinline SweepPair* collideOneT(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out, SweepPair* end,
                                     int& skipped)
{
    const unsigned int maxX = bounds->maxX;
    while (scan->minX < maxX)
    {
        unsigned int d0 = mySeparatedYZ(*bounds, scan[0]);
        unsigned int d1 = mySeparatedYZ(*bounds, scan[1]);
        unsigned int d2 = mySeparatedYZ(*bounds, scan[2]);
        unsigned int d3 = mySeparatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
            {
                if (swapPairs)
                    out = emitPair(scan[0], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[0], out, end, skipped);
            }
            if (!d1 && scan[1].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[1], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[1], out, end, skipped);
            }
            if (!d2 && scan[2].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[2], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[2], out, end, skipped);
            }
            if (!d3 && scan[3].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[3], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[3], out, end, skipped);
            }
        }
        scan += 4;
    }
    return out;
}
template <>
__forceinline SweepPair* collideOneT<false>(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out,
                                            SweepPair* end, int& skipped)
{
    const unsigned int maxX = bounds->maxX;
    while (scan->minX < maxX)
    {
        unsigned int d0;
        unsigned int d1 = (d0 = mySeparatedYZ(*bounds, scan[0]), mySeparatedYZ(*bounds, scan[1]));
        unsigned int d2 = mySeparatedYZ(*bounds, scan[2]);
        unsigned int d3 = mySeparatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
            {
                if (false)
                    out = emitPair(scan[0], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[0], out, end, skipped);
            }
            if (!d1 && scan[1].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[1], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[1], out, end, skipped);
            }
            if (!d2 && scan[2].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[2], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[2], out, end, skipped);
            }
            if (!d3 && scan[3].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[3], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[3], out, end, skipped);
            }
        }
        scan += 4;
    }
    return out;
}
int __cdecl CollideSweepBounds(const SweepBounds* a1, int count1, const SweepBounds* a2, int count2,
                               SweepPair* __restrict pairs, int capacity, int& skipped);
static float getNormalSignFromFeatureBitSet(unsigned short arg);
unsigned short volatile g_in_db09f0;
float volatile g_out_db09f0;
void drive_db09f0(void);
extern int DAT_010d52d0;
extern "C" unsigned int stub_val(void);
static int* Runtime_GetMaskedValue_00db0db0(unsigned int a);
int stub_caller(void);
struct FUN_00db7c80_class
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int* Get0cAddress_00db7c80();
};



namespace hkRouterDA24 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkRouterDA24::hkMemoryRouter_getInstance().heap();
}

template <class T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    for (int i = 0; i < m_iElementCount; i++)
        m_data[i].~T();
    m_iElementCount = 0;
    if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    m_data = 0;
    m_iCapacityState = DONT_DEALLOCATE_FLAG;
}

template <class T, class Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    hkArrayBase<T>::_clearAndDeallocate(Allocator().get(this));
}

void __cdecl hkMemoryAllocator_ProcessEntries_00da12b0(int iParam, float fParam, hkBool bFlag, hkArray<int>& kFirst,
                          hkArray<int>& kSecond) throw();

// @fnv 0x00da24b0
// src: GUESS 0x00da24b0 (confidence: low)
void __cdecl hkArray_ProcessState_00da24b0(int iParam, float fParam)
{
    hkArray<int> kFirst;
    hkArray<int> kSecond;
    hkMemoryAllocator_ProcessEntries_00da12b0(iParam, fParam, false, kFirst, kSecond);
}
