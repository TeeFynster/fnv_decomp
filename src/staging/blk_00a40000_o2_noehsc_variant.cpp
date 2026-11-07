
// src/staging/blk_00a40000_o2_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/staging/blk_00a40000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00a40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTArray.h"
#include "../../include/NiFlipController.h"
#include "../../include/AnimIdle.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiPointer.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSFrustumFOVController.h"
#include "../../include/NiFloatData.h"
#include "../../include/NiFloatInterpolator.h"
#include "../../include/NiObject.h"
#include "../../include/MemoryManager.h"
#include "../../include/NP.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiGPUProgram.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiStream.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTMapItem.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/NiTStringTemplateMap.h"
#include "../../include/NiVBSet.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" void __fastcall NiBlendInterpolator_NiBlendInterpolator(void*);
extern int DAT_0109750c;
struct FUN_00a409b0_class
{
    void* vtbl;
    FUN_00a409b0_class();
};
void __fastcall NiBlendInterpolator_NiBlendInterpolator(void*);
void* __cdecl NiBlendTransformInterpolator_CreateObject();
float NiInterpScalar_Linear(float a, float b, float c);
void __fastcall NiBlendInterpolator_NiBlendInterpolator(void*);
extern int DAT_01097904;
struct FUN_00a42f60
{
    void* m_pVTable;
    char m_auiShapeKeys[0x2C];
    float m_f;
    FUN_00a42f60();
};
struct FUN_00a44850_holder : NiObject
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_p;
    float m_f;
    void CopyMembersStreamAndFields(FUN_00a44850_holder* dst, CloningProcess* proc);
};
extern MemoryManager g_memoryManager;
struct Map_00a4da90
{
    void FUN_00a4d660();
    void* ReleaseIfFlagged(int);
};
void __fastcall FUN_00a57f80(void*);
void __cdecl _delete(void*, unsigned int);
struct FUN_00a51af0_class
{
    void* __thiscall FUN_00a51af0(unsigned char flags);
};
void __cdecl NiFreeAlias(void*);
extern "C" char* __cdecl _strcat_s(char* destination, unsigned int destinationSize, const char* source);
char* __cdecl SafeStrcat(char* destination, unsigned int destinationSize, const char* source);
extern const char* _EmptyFS;
struct FUN_00a57870_Class
{
    int m_iWordAt00;
    const char* m_cByteAtOffset1;
    void ReleaseString();
};
void* __cdecl BSBlendTreadTransfInterpolator_CreateObject();
extern "C" void NiFree(void*);
extern MemoryManager _g_memoryManager;
extern int DAT_010997f4;
struct BaseHolder
{
    void FUN_00a57f20(int, int);
};
void* __cdecl NiBSplineFloatInterpolator_CreateObject();
void __fastcall _Call_a5d3a0(void*);
extern int DAT_01099e54;
void* __cdecl NiBSplineData_CreateObject();
void* __cdecl NiMalloc(unsigned int);
void* __cdecl fnv_zlib_memset(void* dst, void* src, unsigned int size);
extern int DAT_0109a2a4;
extern MemoryManager g_memoryManager;
void __cdecl NiFree(void*);
struct FUN_00a54160_class
{
    void* vtbl;
    void* p;
    void* __thiscall FUN_00a54160(unsigned char flags);
};
void __cdecl NiStandardizeFilePath(NiFixedString*);
void __cdecl NiImageConverter_ConvertFilenameToPlatformSpecific_(void*, void*);
struct FUN_00a5fba0_class
{
    void __thiscall NiSourceTexture_SetFilePath(const NiFixedString* kFilename);
};
unsigned int __stdcall NiGlobalStringTable_HashFunction(const char* s, unsigned int len);
extern "C" unsigned int __cdecl _strcpy_s(char* dst, unsigned int size, const char* src);
void __cdecl _fnv_StandardizeFilePath(char*);
void __cdecl NiStandardizeFilePath(NiFixedString* k);
extern int DAT_0109b00c;
struct FUN_004a4650_ListBase
{
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll();
};
struct FUN_00a5a390_shell
{
    void ReleaseStorage_00a5a390();
    void DestroyFogProperty();
};
extern char DAT_010976ec;
struct FUN_00a414c0_class
{
    void* m_pVTable;
    void* m_p;
    FUN_00a414c0_class* __thiscall FUN_00a414c0(unsigned char flags);
};
extern int DAT_010976fc;
struct A51BF0Base
{
    static void* operator new(unsigned int);
};
struct A51BF0
{
    void* vtbl;
    int pad;
    int a;
    int b;
    int c;
    bool d;
    void FUN_00a5d3a0();
};
A51BF0* CreateA51BF0();
float Runtime_UpdateState_00a42070(float param_1, float param_2, float param_3, float param_4, float param_5);
struct FUN_00a44f90_class
{
    void* vtbl;
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
    float m_38;
    float m_3c;
    float m_40;
    float m_44;
    char m_48;
    char m_49;
    char m_4a;
    char m_4b;
    FUN_00a44f90_class();
};
extern int DAT_01097f84;
void __cdecl _NiFree(void*);
struct FUN_00a57890_shell
{
    void* m_iWordAt00;
    const char* m_cByteAtOffset1;
    void __thiscall AssignStringRef(const char** s);
};
extern int DAT_011f4500;
extern int DAT_011f4504;
extern char DAT_011f4580;
struct CRITICAL_SECTION_STUB
{
    int a;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION_STUB*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION_STUB*);
void __fastcall NiTexture_AddTextureToList(int param_1);
struct ControllerAllocation
{
    ControllerAllocation* FUN_00a40520(void* target, float value, unsigned int flags);
};
ControllerAllocation* __stdcall NiGeomMorpherController_CreateBlendInterpolator(unsigned int ReportDiagnostic, void* target, unsigned int unused2,
                                             float value, unsigned int flags);
struct FUN_00a413d0_pair
{
    unsigned int m_key0;
    unsigned int m_key1;
};
struct FUN_00a413d0_cls
{
    unsigned int m_unk00;
    FUN_00a413d0_pair** m_ppItems;
    unsigned short m_unk08;
    unsigned short m_uiItemCount;
    int FindPairIndex(unsigned int key0, unsigned int key1);
};
class HandlerObject
{
  public:
    virtual void unk00();
    virtual void Handle(void* pArg);
};
struct HandlerEntry
{
    unsigned int m_key;
    HandlerObject* m_pEntryObject;
};
struct HandlerArg
{
    int unk00;
    int unk04;
    unsigned int m_key;
};
class FUN_00a41410_cls
{
  public:
    int unk00;
    HandlerEntry** m_ppEntries;
    unsigned short unk08;
    unsigned short m_uiItemCount;

    void DispatchByKey(HandlerArg* a1);
};
struct S_00a42290_Q : NiRefObject
{
    int unk08;
    int unk0c;
    int unk10;
    bool unk14;
    S_00a42290_Q() throw() : unk08(0), unk0c(0), unk10(0), unk14(false)
    {}
    virtual ~S_00a42290_Q() throw()
    {}
    void FUN_00a3ccb0(void* a, unsigned int b, int c);
};
struct S_00a42290_Ptr
{
    S_00a42290_Q* p;
    S_00a42290_Ptr& FUN_0066b0d0(S_00a42290_Q* q);
};
struct S_00a42290_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00a42290_Ptr m10;
    int unk14;
    void NiFloatInterpolator_SetKeys(void* a, unsigned int b, int c);
};
class A42380Owner
{
  public:
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
    NiPointer<NiRefObject> m_spTransformData;

    void UpdateFields_00a42380(NiRefObject* pkData);
};
extern const NiRTTI NiNodeRTTI_a42b70;
extern const NiRTTI CtrlRTTI_A_a42b70;
extern const NiRTTI CtrlRTTI_B_a42b70;
extern const NiRTTI CtrlRTTI_C_a42b70;
struct StubController : NiObject
{
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
    StubController* m_pkNext;
};
struct StubAVObject;
struct StubChildArray
{
    void* m_pVTable;
    StubAVObject** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};
struct StubAVObject : NiObject
{
    int unk08;
    StubController* m_pControllers;
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
    StubChildArray m_kChildList;
};
static inline bool IsKindOfRTTI(const NiRTTI* pkTarget, const NiObject* pkObj)
{
    for (const NiRTTI* r = pkObj->GetRTTI(); r; r = r->m_pBaseRTTI)
        if (r == pkTarget)
            return true;
    return false;
}
void __cdecl NiOldAnimationConverter_ConvertRollController(StubController* p);
void __cdecl CreateInterpolator(StubController* p);
void __cdecl ConvertLegacyController(StubController* p);
void __cdecl NiOldAnimationConverter_RecurseScene(void* pArg, StubAVObject* pkObject);
extern int DAT_011f4304;
void __cdecl NiOldAnimationConverter_RecurseScene(void* a1, void* a2);
void __cdecl NiOldAnimationConverter_Convert(int* param1, NiObject* param2);
struct FUN_00a42f80_base
{
    virtual ~FUN_00a42f80_base();
};
struct FUN_00a42f80_cls : FUN_00a42f80_base
{
    virtual ~FUN_00a42f80_cls();
};
struct FUN_00a44830_base
{
    virtual ~FUN_00a44830_base();
};
struct FUN_00a44830_cls : FUN_00a44830_base
{
    virtual ~FUN_00a44830_cls();
};
extern "C" void _NiFreeAlias(void*);
extern "C" void __cdecl ReleaseObjectArray(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct SP
{
    NiRefObject* value;
    ~SP() throw()
    {
        if (value)
            value->DecRefCount();
    }
    SP& operator=(NiRefObject* p) throw()
    {
        if (value)
        {
            value->DecRefCount();
            value = 0;
        }
        return *this;
    }
};
struct RawArray
{
    virtual ~RawArray() throw()
    {
        _NiFreeAlias(data);
    }
    void** data;
    unsigned short maxSize, size, used, grow;
    void* RemoveAt(unsigned i) throw()
    {
        if (i >= size)
            return 0;
        void* p = data[i];
        data[i] = 0;
        if (p)
            --used;
        if (i == (unsigned short)(size - 1))
            --size;
        return p;
    }
};
struct RefArray
{
    virtual ~RefArray() throw()
    {
        ReleaseObjectArray(data);
    }
    SP* data;
    unsigned short maxSize, size, used, grow;
    SP FUN_00a47540(unsigned) throw();
};
struct FUN_00a478f0 : NiRefObject
{
    void* raw;
    RawArray rawArray;
    RefArray refArray;
    SP reference;
    virtual void unused();
    ~FUN_00a478f0() throw();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern int DAT_0109893c;
struct RefPointer
{
    NiRefObject* object;
    void Clear()
    {
        if (object)
        {
            object->DecRefCount();
            object = 0;
        }
    }
    void Release()
    {
        if (object)
            object->DecRefCount();
    }
};
struct ParentData
{
    void* vtable;
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
    void FUN_00a6d290();
};
void __cdecl _NiFree_00aa10f0(void*);
struct FUN_00a49d60 : public ParentData
{
    RefPointer first;
    RefPointer second;
    void* resource;
    ~FUN_00a49d60();
};
extern void* __cdecl _NiMalloc_00aa1070(unsigned int size);
struct FUN_00a54110
{
    int* pBuffer;
    unsigned int reservedSize;
    unsigned int size;

    FUN_00a54110(unsigned int count);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class NiObjectBase572
{
  public:
    virtual ~NiObjectBase572() throw();

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
};
class FUN_00a572d0 : public NiObjectBase572
{
  public:
    virtual ~FUN_00a572d0() throw();

    NiPointer<NiRefObject> m_spFirst;
    NiFixedString m_kName;
    NiPointer<NiRefObject> m_spSecond;
};
struct FUN_00a57580_cls
{
    int m_iWordAt00;
    int m_uiItemCount;
    int(__cdecl* m_fn)(FUN_00a57580_cls*, int, int, int*, int);
};
int __cdecl InvokeAndAccumulate(FUN_00a57580_cls* p, int v);
struct FUN_00a575b0_Object
{
    void* unk00;
    int unk04;
    int(__cdecl* unk08)(void*, int, int, int*, int);
};
void __cdecl NiStreamLoadBinary_00a575b0(FUN_00a575b0_Object* object, int value);
struct FUN_00a59c60_target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
};
class FUN_00a59c60_cls
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41(int a, int b);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00a59c60_target* m_18;
    void NiAVObject_Update(int a1);
};
struct SingletonTarget
{
    void __thiscall NiGlobalStringTable_FreeStrings();
};
extern SingletonTarget* g_011f42c0;
void __cdecl NiGlobalStringTable_FreeUnusedStrings();
extern void __cdecl _NiFree_00aa10f0(char* psz);
extern int DAT_0102102c;
struct Ent
{
    void* m_f0;
    char* m_str;
    int m_unk8;
    int m_unkC;
};
inline char* GetStr(Ent* e)
{
    return e->m_str;
}
struct CSImpl
{
    void* m_iFourthElementInteger[6];
};
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CSImpl* pcs);
struct FUN_00a5b470_cls
{
    int m_pad4;
    int m_pad8;
    int m_padC;
    Ent m_entries[0x200];
    char m_gap[0x74];
    CSImpl m_cs;
    void ResetEntries();
};
__declspec(dllimport) void __stdcall InitializeCriticalSection(void* pkSection);
extern int g_iA5B530Default;
struct A5B530Entry
{
    int* m_piSource;
    int m_iValue;
    short m_sA;
    short m_sB;
    short m_sC;
    short m_sCount;

    A5B530Entry()
    {
        m_sA = 0;
        m_sCount = 1;
        m_sB = 0;
        m_sC = 0;
        m_iValue = 0;
        m_piSource = &g_iA5B530Default;
    }
};
struct A5B530CriticalSection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class FUN_00a5b530
{
  public:
    A5B530Entry m_akEntries[0x201];
    int unk2010;
    int unk2014;
    int unk2018;
    int unk201C;
    int unk2020;
    int unk2024;
    int unk2028;
    int unk202C;
    int unk2030;
    int unk2034;
    int unk2038;
    int unk203C;
    int unk2040;
    int unk2044;
    int unk2048;
    int unk204C;
    int unk2050;
    int unk2054;
    int unk2058;
    int unk205C;
    int unk2060;
    int unk2064;
    int unk2068;
    int unk206C;
    int unk2070;
    int unk2074;
    int unk2078;
    int unk207C;
    A5B530CriticalSection m_kLock;

    FUN_00a5b530();
};
class A5B660StringTable
{
  public:
    ~A5B660StringTable();

    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }

    static A5B660StringTable* ms_pStringTable;

    static void ClearStaticStringTable();
};
struct FUN_00a5b870_cls
{
    int unk00;
    unsigned short* m_pData;
    unsigned short unk08;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    void __thiscall SetEntry(unsigned int index, unsigned short* value);
};
// NiRefObject
extern void* __cdecl Object_DispatchCommandFour(unsigned int);
extern int DAT_0109b5ac;
extern int DAT_0101fbd4;
struct NiObjectBase
{
    void __thiscall FUN_00a5aa20();
};
struct ObjectState
{
    void* reference;
    unsigned int count;
    unsigned short first;
    unsigned short second;
    unsigned short third;
    unsigned short enabled;
};
NiObjectBase* __cdecl NiNode_CreateObject();
// Constructor of a derived object: base ctor call, then a 16-bit field and the vtable pointer.
extern int DAT_0109b72c;
struct FUN_00a5f1e0_cls
{
    void* m_pVTable;       // +0x00
    int m_i04;             // +0x04
    int m_i08;             // +0x08
    int m_i0C;             // +0x0C
    int m_i10;             // +0x10
    unsigned short m_w14;  // +0x14
    unsigned short m_w16;  // +0x16
    unsigned short m_w18;  // +0x18

    void Init();  // base constructor (external)

    FUN_00a5f1e0_cls();
};
class A5F4D0Property
{
  public:
    A5F4D0Property();
    virtual ~A5F4D0Property();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class FUN_00a5f4d0 : public A5F4D0Property
{
  public:
    unsigned short m_usFlags;

    FUN_00a5f4d0();
    virtual ~FUN_00a5f4d0();
};
extern int DAT_0109b9ec;
extern int DAT_0109b944;
extern int DAT_0109b220;
struct FUN_00a5fca0_cls
{
    void* m_vptr;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    NiRefObject* m_24;
    int unk28, unk2C;
    int m_30;
    int m_34;
    NiRefObject* m_38;
    NiRefObject* m_3c;

    void NiTexture_RemoveTextureFromList();
    void DestroyFogProperty();
    void UpdateFields_00a5fca0();
};
// Destructor of an owning pointer array: remove and free every element, then the base frees the storage.
extern MemoryManager g_kA1450MemoryManager;
void __cdecl A1450NiFree(void* pvMem);
struct A1450Element
{
    int unk00;

    static void operator delete(void* pvMem)
    {
        g_kA1450MemoryManager.Deallocate(pvMem);
    }
};
typedef NiTArray<A1450Element*, NiTMallocInterface<A1450Element*> > A1450Array;
template <> inline NiTArray<A1450Element*, NiTMallocInterface<A1450Element*> >::~NiTArray()
{
        A1450NiFree(m_pBase);
    }
template <> inline A1450Element* NiTArray<A1450Element*, NiTMallocInterface<A1450Element*> >::RemoveEnd()
{
        if (m_usSize == 0)
            return 0;
        m_usSize--;
        A1450Element* pkElement = m_pBase[m_usSize];
        m_pBase[m_usSize] = 0;
        if (pkElement)
            m_usESize--;
        return pkElement;
    }
class A1450OwnedArray : public A1450Array
{
  public:
    void ClearAndDestroy();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class FUN_00a423f0_cls
{
  public:
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
    NiRefObject* m_pObject;

    void NiLookAtInterpolator_SetScaleInterpolator(NiRefObject* obj);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern const NiRTTI DAT_011f36ec;
struct ConvertedController;
struct ControllerInterpolator;
struct ControllerHost
{
    ConvertedController* NiObjectNET_GetController(const NiRTTI*);
    void FUN_00a5c000(ConvertedController*);
    void NiObjectNET_RemoveController(StubController*);
};
struct ControllerFields
{
    virtual void Slot00();
    virtual void DeleteThis() throw();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void SetTarget(ControllerHost*);
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Update();
    virtual void Slot48();
    virtual void* GetInterpolator(unsigned int);
    virtual void SetInterpolator(ControllerInterpolator*, unsigned int);
    unsigned int refCount;
    int unk08;
    unsigned short flags;
    unsigned short unk0e;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    float startTime;
    float stopTime;
    void IncRefCount() throw()
    {
        InterlockedIncrement((volatile long*)&refCount);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement((volatile long*)&refCount))
            DeleteThis();
    }
};
struct ConvertedController : ControllerFields
{
    NiPointer<ConvertedController> next;
    ConvertedController* NiTransformController_NiTransformController();
};
struct ControllerInterpolator : ControllerFields
{
    unsigned short cycle;
    unsigned short unk32;
    int unk34;
    int data;
    ControllerInterpolator* FUN_00a3f060(void*, void*);
    void UpdateIfFlagged();
    void SetFlag1(bool value)
    {
        if (value)
            flags |= 2;
        else
            flags &= (unsigned short)~2;
    }
    void SetFlag2(bool value)
    {
        if (value)
            flags |= 4;
        else
            flags &= (unsigned short)~4;
    }
    void SetFlag3(bool value)
    {
        if (value)
            flags |= 8;
        else
            flags &= (unsigned short)~8;
    }
    void SetFlag5(bool value)
    {
        if (value)
            flags |= 32;
        else
            flags &= (unsigned short)~32;
    }
    void SetFlag6(bool value)
    {
        if (value)
            flags |= 64;
        else
            flags &= (unsigned short)~64;
    }
    void SetFlag4(bool value)
    {
        if (value)
            flags |= 16;
        else
            flags &= (unsigned short)~16;
        if (value)
            UpdateIfFlagged();
    }
};
struct LegacyController : StubController
{
    unsigned short flags;
    unsigned short unk36;
    int unk38;
    int unk3c;
    void* firstData;
    void* secondData;
    int unk48;
    int unk4c;
    float startTime;
    float stopTime;
    unsigned short cycle;
    unsigned short unk5a;
    int unk5c;
    int data;
    bool Flag1() const
    {
        return (flags >> 1) & 1;
    }
    bool Flag2() const
    {
        return (flags >> 2) & 1;
    }
    bool Flag3() const
    {
        return (flags >> 3) & 1;
    }
    bool Flag4() const
    {
        return (flags >> 4) & 1;
    }
    bool Flag5() const
    {
        return (flags >> 5) & 1;
    }
    bool Flag6() const
    {
        return (flags >> 6) & 1;
    }
};
void __cdecl CopyControllerSettings(StubController*, ConvertedController*);
void __cdecl ConvertLegacyController(StubController* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern NiRTTI g_011f3f38, g_011f3f28, g_011f4a38, g_011f36ec;
struct Obj
{
    virtual void slot0() throw();
    virtual void DeleteThis() throw();
    virtual const NiRTTI* GetType() const throw();
    volatile long refs;
    const char* name;
    Obj* controller;
    Obj** extras;
    unsigned short count;
    unsigned short capacity;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Obj* next;
    Obj* Cast(const NiRTTI*) throw();
    bool RemoveExtraDataAt(unsigned short) throw();
    void ClearExtraData() throw();
    void Inc() throw()
    {
        InterlockedIncrement(&refs);
    }
    void Dec() throw()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
inline bool IsKind(const NiRTTI* type, const Obj* object) throw()
{
    for (const NiRTTI* r = object->GetType(); r; r = r->m_pBaseRTTI)
        if (r == type)
            return true;
    return false;
}
inline Obj* CastInline(const NiRTTI* type, Obj* object) throw()
{
    if (!object)
        return 0;
    return (int)IsKind(type, object) ? object : 0;
}
struct Ptr
{
    Obj* p;
    Ptr(Obj* q) throw() : p(q)
    {
        if (p)
            p->Inc();
    }
    ~Ptr() throw()
    {
        if (p)
            p->Dec();
    }
    void operator=(Obj* q) throw()
    {
        if (p != q)
        {
            if (p)
                p->Dec();
            p = q;
            if (p)
                p->Inc();
        }
    }
};
struct Result
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
    static void* operator new(unsigned int) throw();
    Result(const char*, int, int) throw();
    void SetReferencedObject_00a47420(Obj*) throw();
    void AddSeq(void*, Obj*) throw();
};
Result* __cdecl CreateResultFromStreamObject(NiStream* stream, unsigned int index, const char* name);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern unsigned int g_011f3f48;
NiGPUProgram* CreateResultFromStreamObject(NiStream*, unsigned int, void*) throw();
void GetGPUProgram(NiStream* stream, unsigned int index, NiPointer<NiGPUProgram>& result, void* extra);
void __cdecl NiFreeA4D(void* pvMem) throw();
void __cdecl FUN_00a57130(int a1);
void __cdecl NiColorExtraDataController_SaveBinary(int a1);
void __cdecl NiInterpScalar_AdjustBezier(float a0, float a1, float* p2, float a3, float a4, float* p5, float a6, float a7, float* p8,
                          float* p9);
struct FUN_00a44840_stub
{
    void* __thiscall NiObject_CreateClone(unsigned int);
};
namespace a47 {
struct Ptr
{
    NiRefObject* m_p;
    Ptr(NiRefObject* p = 0) throw() : m_p(p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    Ptr(const Ptr& o) throw() : m_p(o.m_p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    ~Ptr() throw()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    Ptr& operator=(NiRefObject* p) throw()
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
    operator NiRefObject*() const throw()
    {
        return m_p;
    }
    bool operator!=(const Ptr& o) const throw()
    {
        return m_p != o.m_p;
    }
    bool operator!=(NiRefObject* p) const throw()
    {
        return m_p != p;
    }
    Ptr& operator=(const Ptr& o) throw()
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
};
typedef NiTArray<a47::Ptr, NiTNewInterface<a47::Ptr> > Arr;
// @fnv 0x00a47540
}
template <> a47::Ptr NiTArray<a47::Ptr, NiTNewInterface<a47::Ptr> >::RemoveAt(unsigned int i) throw()
{
    if (i >= m_usSize)
        return a47::Ptr(0);
    a47::Ptr sp = m_pBase[i];
    m_pBase[i] = a47::Ptr(0);
    if (sp != a47::Ptr(0))
        m_usESize--;
    if (i == (unsigned short)(m_usSize - 1))
        m_usSize--;
    return sp;
}
namespace a47 {

}

extern "C" void __cdecl FUN_00a39010();
void __cdecl NiBoolInterpController_SaveBinary();
extern int g_011f36dc_arg1;
template <class T> class NiTMallocInterface;
template <class T, class Alloc> class NiTArray;
struct A5D6E0This : NiRefObject
{
    void AppendCameraPathEntries(NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >*);
};
extern void* __cdecl NiViewerStrings_NiGetViewerString_Title(int);
extern void* __cdecl NiGetViewerString_00a7d5a0(const char*, void*);
extern void* __cdecl NiGetViewerString_00a7d510(const char*, unsigned int);
extern void __cdecl NiObjectNET_CopyMembers();
void __cdecl NiProperty_CopyMembers();
void __cdecl SaveNiObjectLinks();
void __cdecl NiSequenceStreamHelper_SaveBinary();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*) throw();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*) throw();
extern "C" void __cdecl _ReadWriteBarrier(void);
struct GO633 : public NiPointer<AnimIdle>
{
};
struct S654
{
    NiTListItem<GO633>* m_pkHead;
    NP NiTPointerListBase_NiPropertyPtr_Remove(GO633& item) throw();
};
struct ExtraOwner
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
    S654 list;
    void NiAVObject_RemoveProperty_0(int type, NiPointer<AnimIdle>& output);
};
extern int DAT_0101dce4;
extern char DAT_011f4400;
void __cdecl _delete(void*, unsigned int);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* Addend);
class CloneMapA5d6
{
  public:
    virtual ~CloneMapA5d6();
};
class CloningProcessA5d6
{
  public:
    CloningProcessA5d6(unsigned int uiHashSize);

    CloneMapA5d6* m_pCloneMap;
    CloneMapA5d6* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
};
extern void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern char* __cdecl FUN_00a5b690(const char* text);
extern void __cdecl NiStandardizeFilePath(void* fixed);
extern void __cdecl NiImageConverter_ConvertFilenameToPlatformSpecific_(void* fixed, void* out);
extern int DAT_0109b220;
extern unsigned char DAT_011a9594;
extern void(__stdcall* DAT_00fdf1c0)(void*);
extern void(__stdcall* DAT_00fdf1c4)(void*);
struct FnvSourceTexture
{
    virtual void Delete(unsigned char);
    virtual void slot004();
    virtual void slot008();
    virtual void slot012();
    virtual void slot016();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot032();
    virtual void slot036();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot052();
    virtual void slot056();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot072();
    virtual void slot076();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot092();
    virtual void slot096();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot112();
    virtual void slot116();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot132();
    virtual void slot136();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot152();
    virtual void slot156();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual bool IsLoaded();

    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    int width;
    int height;
    int depth;
    int unk24;
    int unk28;
    int unk2c;
    char* filename;
    char* normalizedName;
    int unk38;
    int unk3c;
    unsigned char unk40;
    unsigned char flags;
    unsigned short unk42;
    int source;

    FnvSourceTexture* __thiscall NiSourceTexture_NiSourceTexture();
};
FnvSourceTexture* __cdecl NiSourceTexture_CreateTexture(int source, const char* name, const int* size, unsigned char flags);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
void __cdecl NiFreeD510(void* pvMem);


inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}





template <class T>
inline NiPointer<T>::NiPointer(T* pObject)
{
    m_pObject = pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T>
inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T>
inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& ptr)
{
    if (m_pObject != ptr.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = ptr.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

// @fnv 0x00a5d510
void NiObject::ResolveObjectPointer(NiPointer<NiObject>& spCopy)
{
    NiStream kStream;
    kStream.InsertObject(this);
    char* pcBuffer = 0;
    int iBufferSize = 0;
    kStream.NiStream::Save(pcBuffer, iBufferSize);
    kStream.NiStream::Load(pcBuffer, iBufferSize);
    // The shared stream keeps its top-level object array in opaque storage at +0x220.
    NiPointer<NiObject> spRetainedObject = reinterpret_cast<NiObject**>(kStream.m_kTopObjects.m_pBase)[0];
    NiFreeD510(pcBuffer);
    spCopy = spRetainedObject;
}

// BSFrustumFOVController::MakeClone, from src/gamebryo2.2/corelibs/nianimation/bsfrustumfovcontroller.cpp: the original has
// no EH frame around the new-expression although the NiFloatInterpController constructor may throw (no throw()), so it was
// built without /EHsc like the rest of this unit.
// @fnv 0x00a42e90
NiObject* BSFrustumFOVController::MakeClone(CloningProcess& cloning)
{
    BSFrustumFOVController* p = new BSFrustumFOVController;
    NiFloatInterpController::CopyMemberData(p, &cloning);
    return p;
}

inline void NiInterpolator::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiInterpolator::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T>
inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T>
inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

// BSFrustumFOVController::LinkObject, from src/gamebryo2.2/corelibs/nianimation/bsfrustumfovcontroller.cpp (no EH frame).
// @fnv 0x00a42d00
void BSFrustumFOVController::LinkObject(NiStream& kStream)
{
    NiFloatInterpController::LinkObject(kStream);
    if (*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(&kStream) + 0xD8) < 0x0A010068)
    {
        NiFloatData* pkData = static_cast<NiFloatData*>(kStream.GetLoadedObject());
        m_spControllerInterpolator = new NiFloatInterpolator(pkData);
        m_spControllerInterpolator->Collapse();
    }
}

// NiFlipController::LoadFromStream, from src/gamebryo2.2/corelibs/nianimation/niflipcontroller.cpp: the original has no EH
// frame around its NiFloatData and NiFloatInterpolator new-expressions, so it was built without /EHsc.
struct A4F610StreamIo
{
    void* m_00;
    unsigned int m_iFirstInteger;
    unsigned int(__cdecl* Transfer)(A4F610StreamIo*, const void*, unsigned int, unsigned int*, unsigned int);
    void Read4(const void* data)
    {
        unsigned int bytes = 4;
        unsigned int result = Transfer(this, data, 4, &bytes, 1);
        m_iFirstInteger += result;
    }
};
extern MemoryManager DAT_011f6238;
inline NiFloatData::NiFloatData()
{
    m_uiNumKeys = 0;
    m_pKeyArray = 0;
    m_eRequestType = (NiAnimationKey::KeyType)0;
    m_ucKeyDataSize = 0;
}
struct A4F610KeyPair
{
    float t;
    float v;
    ~A4F610KeyPair();
};
void* operator new[](unsigned int size)
{
    return DAT_011f6238.Allocate(size);
}
// Reads a float range and step from the stream, builds a NiFloatData key array and a NiFloatInterpolator, and stores it in m_spControllerInterpolator.
// @fnv 0x00a4f610
void __thiscall NiFlipController::LoadFromStream(NiStream* stream)
{
    NiFloatInterpController::LoadBinary(*stream);
    (*(A4F610StreamIo**)((char*)stream + 0x24c))->Read4(&m_eAffectedMap);
    if ((*(unsigned int*)((char*)stream + 0xd8)) < 0x0a010068)
    {
        float fStart;
        float fStep;
        (*(A4F610StreamIo**)((char*)stream + 0x24c))->Read4(&fStart);
        (*(A4F610StreamIo**)((char*)stream + 0x24c))->Read4(&fStep);
        unsigned int count = stream->ReadUnsignedInteger();
        NiFloatData* data = new NiFloatData();
        if (count > 0)
        {
            A4F610KeyPair* keys = new A4F610KeyPair[count + 1];
            float run = fStart;
            for (unsigned int i = 0; i < count; ++i)
            {
                keys[i].t = run;
                keys[i].v = (float)i;
                run += fStep;
            }
            keys[count].t = run;
            keys[count].v = (float)(count - 1);
            data->SetColorKeys((TimedAnimationKey*)keys, count + 1, (NiAnimationKey::KeyType)5);
            m_fLoKeyTime = fStart;
            m_fHiKeyTime = run;
        }
        NiFloatInterpolator* interp = new NiFloatInterpolator(data);
        NiInterpolator* pOldInterp = m_spControllerInterpolator.m_pObject;
        if (pOldInterp != interp)
        {
            if (pOldInterp)
            {
                if (InterlockedDecrement((long*)&pOldInterp->m_uiRefCount) == 0)
                    pOldInterp->DeleteThis();
            }
            m_spControllerInterpolator.m_pObject = interp;
            if (interp)
                InterlockedIncrement((long*)&interp->m_uiRefCount);
        }
        m_spControllerInterpolator.m_pObject->Collapse();
    }
    else
    {
        stream->ReadUnsignedInteger();
    }
}
