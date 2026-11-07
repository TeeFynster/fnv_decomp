#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiControllerSequence.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"

// src/gamebryo2.2/corelibs/nianimation/nicontrollersequence_fpfast_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy /fp:fast (unit src/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern const char* const g_011c7d74_arg1;
const char* const* __cdecl NiControllerSequence_GetRTTI();
struct BaseH
{
    virtual ~BaseH();
};
extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);
struct FUN_00a30580_shell
{
    bool __thiscall IsNotInChain(void* arg);
};
void __cdecl ReleaseObjectArray(void*);
struct MM_00a34450
{
    void __thiscall _DeallocateAlias(void*);
};
extern MM_00a34450 g_memoryManager;
extern int DAT_01096620;
struct FUN_00a34450_shell
{
    void* __thiscall FUN_00a34450(unsigned int);
};
struct SeqInterpArrayItem
{
    void* m_spControllerInterpolator;
    void* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned char m_auiShapeKeys[2];
};
struct SeqIDTag
{
    char* m_kAVObjectName;
    char* m_kPropertyType;
    char* m_kCtlrType;
    char* m_kCtlrID;
    char* m_kInterpolatorID;
};
struct FUN_00a33bf0_s : NiObject
{
    char* m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    SeqInterpArrayItem* m_pInterpArray;
    SeqIDTag* m_pkIDTags;
    float m_fWeight;
    void* m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    unsigned char m_pad34[0xc];
    void* m_pkOwnerManager;
    unsigned char m_pad44[0x18];
    char* m_kAccumulationRootName;
    unsigned char m_pad60[0xc];
    void** m_pkAnimNotes;
    unsigned short m_usNumAnimNotes;
    void SaveToStream(NiStream& kStream);
};
struct FUN_00a2e420_shell
{
    unsigned char NiControllerManager_StopTransSourceSequence(float);
};
struct FUN_00a30540_shell
{
    void NiControllerSequence_DetachInterpolators();
};
extern float DAT_01015f5c;
extern double DAT_010241b0;
struct FUN_00a35030_shell : NiControllerSequence
{
    unsigned char SetEaseOut(float fEaseOutTime, bool bTransition);
};
struct FUN_00a30900_shell
{
    void AttachInterpolators(char m_ucRegionPriority);
};
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};
struct FUN_00a316a0_shell
{
    void* __thiscall FUN_00a316a0();
};
void* __cdecl NiControllerSequence_CreateObject();
extern char DAT_01096584;
extern void* _EmptyFS;
extern int(__stdcall* DAT_00fdf1c4)(void*);
struct FUN_00a31500_shell
{
    void __thiscall NiControllerSequence_InterpArrayItem_Free(int);
};
struct FUN_00a315b0_shell
{
    void __thiscall NiControllerSequence_IDTag_Free(int);
};
struct FUN_00a31740_shell
{
    void __thiscall FUN_00a31740(int);
};
struct FUN_00a35640_shell
{
    void __thiscall ProcessState_00a35640();
};
struct RefBase
{
    virtual void First()
    {}
    virtual void Release()
    {}
};
extern "C" unsigned int __cdecl strlen(const char* s);
void __cdecl FUN_00a305b0(char* out, unsigned int size, const char* fmt, const char* a, const char* b, const char* c);
void __cdecl FUN_00ec65a6(char* c, unsigned int b, const char* a);
struct FUN_00a307c0_entry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};
struct FUN_00a307c0_item
{
    const char* name;
    const char* ctrl;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
};
struct FUN_00a307c0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_00a307c0_entry* m_14;
    FUN_00a307c0_item* m_18;
    void GetEntryText(unsigned int idx, char* out);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* Addend);
struct S_00a30880_RefObject
{
    virtual ~S_00a30880_RefObject()
    {}
    virtual void V01()
    {}

    long m_lRefCount;
};
struct S_00a30880_Base
{
    virtual void V00()
    {}
    virtual void V01()
    {}
    virtual void V02()
    {}
    virtual void V03()
    {}
    virtual void V04()
    {}
    virtual void V05()
    {}
    virtual void V06()
    {}
    virtual void V07()
    {}
    virtual void V08()
    {}
    virtual void V09()
    {}
    virtual void V10()
    {}
    virtual void V11()
    {}
    virtual void V12()
    {}
    virtual void V13()
    {}
    virtual void V14()
    {}
    virtual void V15()
    {}
    virtual void V16()
    {}
    virtual void V17()
    {}
    virtual void V18()
    {}
    virtual void V19()
    {}
    virtual void V20()
    {}
    virtual void V21()
    {}
    virtual void V22()
    {}
    virtual void V23()
    {}
    virtual void V24()
    {}
    virtual void V25()
    {}
    virtual void V26()
    {}
    virtual void V27()
    {}
    virtual void V28()
    {}
    virtual void V29()
    {}
    virtual void V30()
    {}
    virtual void V31()
    {}
    virtual void V32()
    {}
    virtual void V33()
    {}
    virtual void V34()
    {}

    virtual void Target(float fValue, unsigned int uiFlags)
    {}
};
struct S_00a30880_Item
{
    void* m_spControllerInterpolator;
    S_00a30880_RefObject* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned char m_auiShapeKeys[2];
};
struct S_00a30880_Foo : S_00a30880_Base
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    S_00a30880_Item* m_pInterpArray;
    void* unk18;
    float unk1c;
    void* unk20;
    unsigned int unk24;
    float unk28;
    float unk2c;
    float unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;

    void ReleaseItems();
};
extern "C" double __cdecl fmod(double, double);
struct SequenceA30970 : NiObject
{
    char* name08;
    unsigned int arraySize0c;
    unsigned int arrayGrow10;
    SeqInterpArrayItem* interpolators14;
    SeqIDTag* tags18;
    float weight1c;
    void* textKeys20;
    int cycleType24;
    float frequency28;
    float begin2c;
    float end30;
    float lastTime34;
    float accumulated38;
    float scaled3c;
    float __thiscall ComputeScaledTime_00a30970(float time, bool update);
};
struct FUN_00a30c80_shell
{
    unsigned __int64 __thiscall IsNotInChain(void* arg);
    bool __thiscall CanSyncTo(void* arg);
};
bool __stdcall MatchesTextKeys(void* arg);
struct FUN_00a30cc0_target
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual bool V23(void* pOther);
};
struct FUN_00a30cc0_cls
{
    FUN_00a30cc0_target* m_pKey0;
    FUN_00a30cc0_target* m_pKey4;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
    unsigned char m_bFlag0D;

    unsigned char Equals(FUN_00a30cc0_cls* other);
};
struct RefView
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
    virtual bool v21(NiStream&);
};
struct ObjectView
{
    int vtable;
    int refs;
    bool FUN_00a5d2f0(NiStream&);
};
struct ItemView
{
    RefView* interpolator;
    RefView* controller;
    void* blend;
    unsigned int settings;
};
struct TagView
{
    char* object;
    char* property;
    char* type;
    char* controller;
    char* interpolator;
};
struct SequenceView : ObjectView
{
    char* name;
    unsigned int count;
    unsigned int grow;
    ItemView* items;
    TagView* tags;
    float weight;
    RefView* text;
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
    char* root;
    int unk60;
    int unk64;
    int unk68;
    RefView** notes;
    unsigned short noteCount;
    bool RegisterStreamables_00a30ea0(NiStream&);
};
__declspec(dllimport) long __stdcall InterlockedIncrement(long* p);
__declspec(dllimport) long __stdcall InterlockedDecrement(long* p);
extern void* _EmptyFS;
struct FixedStr
{
    char* m_handle;
    FixedStr() : m_handle((char*)_EmptyFS)
    {}
    static void AcquireReference(char* h)
    {
        if (h != _EmptyFS)
            InterlockedIncrement((long*)(h - 8));
    }
    static void DecRef(char* h)
    {
        if (h != _EmptyFS)
            InterlockedDecrement((long*)(h - 8));
    }
    FixedStr& operator=(const FixedStr& o)
    {
        char* h = o.m_handle;
        if (m_handle != h)
        {
            AcquireReference(h);
            DecRef(m_handle);
            m_handle = h;
        }
        return *this;
    }
};
struct FUN_00a312d0
{
    FixedStr m_kAVObjectName;
    FixedStr m_kPropertyType;
    FixedStr m_kCtlrType;
    FixedStr m_kCtlrID;
    FixedStr m_kInterpolatorID;
    void ClearIdentifiers();
    FUN_00a312d0(const FixedStr& a, const FixedStr& b, const FixedStr& c, const FixedStr& d, const FixedStr& e);
};
extern int DAT_0109b220;
extern int(__stdcall* DAT_00fdf1c4)(void*);
struct S_00aa4060_Class
{
    void MemoryManager_Deallocate(void* apMemory);
};
extern S_00aa4060_Class DAT_011f6238;
struct FUN_00a315b0_Elem
{
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    char* m_10;
};
class FUN_00a315b0_Base
{
  public:
    void NiControllerSequence_IDTag_Destroy();
};
class FUN_00a315b0_cls
{
  public:
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    char* m_10;

    FUN_00a315b0_cls* NiControllerSequence_IDTag_Free(unsigned char acFlags);
};
struct a31740_Ref
{
    virtual void v00();
    virtual void Release();
    int refCount;
};
struct a31740_Mem
{
    void __thiscall _DeallocateAlias(void*);
};
extern a31740_Mem g_memMgr31740;
struct FUN_00a31740_cls
{
    a31740_Ref* m_pReference;

    void* FUN_00a31740(unsigned char acFlags);
};
extern int(__stdcall* DAT_00fdf1c0)(void*);
extern int(__stdcall* DAT_00fdf1c4)(void*);
struct FUN_00a317e0_ref
{
    virtual ~FUN_00a317e0_ref();
    virtual void DeleteThis();
    int m_uiRefCount;
};
struct FUN_00a317e0_interp
{
    void* m_spControllerInterpolator;
    void* unk04;
    void* unk08;
    void* unk0C;
    void __thiscall ReleaseReferencedObjectsAndResetFlags();
};
struct FUN_00a317e0_tag
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void __thiscall ResetStrings();
};
struct FUN_00a317e0_t
{
    void* unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    FUN_00a317e0_interp* m_pInterpArray;
    FUN_00a317e0_tag* m_pkIDTags;

    void __thiscall AssignInterpolatorRef(int index, FUN_00a317e0_ref** output);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
struct RefObj
{
    virtual void V00();
    virtual void Release();
    long m_iObjectReferenceCount;
};
struct SlotEntry
{
    RefObj* m_pEntryObject;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned char m_unk0c;
    unsigned char m_flag0d;
    unsigned char m_unk0e;
    unsigned char m_unk0f;
};
struct SlotInfo
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    void NiControllerSequence_IDTag_Operator_Set(unsigned int value);
};
struct FUN_00a32bc0_cls
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_uiItemCount;
    unsigned int m_unk10;
    SlotEntry* m_pSlots;
    SlotInfo* m_pInfos;

    bool NiControllerSequence_ReallocateArrays();
    int AssignSlot(RefObj* p1, unsigned int p2, unsigned char p3);
};
struct FUN_00a34480_obj
{
    virtual void V00();
    virtual void V01();
    virtual FUN_00a34480_obj* V02();
    FUN_00a34480_obj* m_pNext;
    unsigned short m_word08;
    unsigned short unk0a;
    float m_f0c;
};
extern int DAT_011f36b4;
struct FUN_00a34480_cls
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
    unsigned short m_word24;
    unsigned short unk26;
    float m_f28;

    bool AssignControllers(void* a1, FUN_00a34480_obj* a2);
    bool FUN_00a34480(void* a1, FUN_00a34480_obj* a2);
};
extern void* DAT_011f36dc;
extern char DAT_01044a7c, DAT_01096678, DAT_0105ac84, DAT_0109666c;
extern char DAT_01096664, DAT_01044c94, DAT_01044c90, DAT_0109665c;
extern char DAT_01096654, DAT_010477f4, DAT_01096648, DAT_0109663c;
extern char DAT_01096630, DAT_01096624;
struct OutputArray
{
    void* unk00;
    void** data;
    unsigned short capacity;
    unsigned short length;
    unsigned short populated;
    unsigned short growth;
    void FUN_0096ad30(unsigned int capacity);
    void FUN_0096ae90(unsigned int index, void** value);
    void Append(void* value)
    {
        unsigned int index = length;
        if (index >= capacity)
            FUN_0096ad30(index + growth);
        FUN_0096ae90(index, &value);
    }
};
struct ControlItem
{
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned char unk0c;
    unsigned char priority;
    unsigned short unk0e;
};
struct TagItem
{
    const char* first;
    const char* second;
    const char* third;
    const char* fourth;
    const char* fifth;
};
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
void* __cdecl FormatStringWithType(const char*, void*);
void* __cdecl NiGetViewerString_00a7d510(const char*, unsigned int);
void* __cdecl NiGetViewerString_00a7d550(const char*, float);
void* __cdecl NiTimeController_GetViewerString(const char*, void*);
int __cdecl FUN_00a305b0(char*, unsigned int, const char*, ...);
void* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);
struct Position
{
    unsigned int i;
    unsigned int tagOffset;
};
struct Sequence
{
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned int itemCount;
    void* unk10;
    ControlItem* controls;
    TagItem* tags;
    float mainWeight;
    void* unk20;
    void* interp;
    float fadeIn;
    float fadeOut;
    float duration;
    float offset;
    float rate;
    float extra3c;
    void* unk40;
    void* name;
    float start;
    float end;
    float total;
    void AppendCameraPathEntries(OutputArray*);
    void FUN_00a34540(OutputArray* output);
};
static const float g_fSeqNegInfinity = -3.402823466e+38f;
struct SeqA34f20;
struct SeqPtrArray
{
    unsigned int AddSeq(SeqA34f20* const& pkSeq);
};
struct SeqOwner
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
    int unk38;
    int unk3c;
    int unk40;
    SeqPtrArray m_kPlayingSequences;
};
struct SeqA34f20
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    char* m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    void* m_pInterpArray;
    void* m_pkIDTags;
    float m_fWeight;
    void* m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fScaledLastTime;
    SeqOwner* m_pkOwnerManager;
    int m_eAnimationState;
    float m_fSequenceOffset;
    float m_fStartTime;
    float m_fEndTime;
    float m_fDestinationFrame;
    SeqA34f20* m_pkTimeSyncSequence;

    bool CanSyncWithSequence(SeqA34f20* pkSequence);
    bool SetTimeSyncSequence(SeqA34f20* pkTimeSyncSeq);
    void SetAnimationCycleType(char m_ucRegionPriority);

    __forceinline bool SetState(int eState)
    {
        bool bWasInactive = m_eAnimationState == 0;
        m_eAnimationState = eState;
        if (bWasInactive)
        {
            m_pkOwnerManager->m_kPlayingSequences.AddSeq(this);
        }
        return bWasInactive;
    }

    bool StartSequence(char m_ucRegionPriority, bool bStartOver, float fWeight, float fEaseInTime,
                       SeqA34f20* pkTimeSyncSeq, bool bTransition);
};
struct SomeObjectB3718
{
    virtual void V00();
    virtual void V01();
    virtual void V02(void* pv, unsigned int ItemUpdateArray, int iFlag);
};
struct HolderB3718
{
    SomeObjectB3718* m_pEntryObject;
};
extern HolderB3718* DAT_011f6080;
void __cdecl _NiFree_00aa10f0(void* pv);
struct FUN_00a30750_shell
{
    char* m_kPointA[5];
    void NiControllerSequence_IDTag_Destroy();
};
extern int EmptyFS;
struct EqObj
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
    virtual bool equal(EqObj* other);
};
struct TCEq
{
    bool IsSameAs(NiObject* other);
};
struct SeqTagCmp
{
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    bool equal(const SeqTagCmp& x) const
    {
        return a == x.a && b == x.b && c == x.c && d == x.d && e == x.e;
    }
};
extern "C" int __cdecl FUN_00aa1360(const char* a, const char* b);
struct SeqTK
{
    EqObj* p;
    operator EqObj*() const
    {
        return p;
    }
    EqObj* operator->() const
    {
        return p;
    }
};
struct SeqEqStand : SequenceA30970
{
    SeqTK& textKeys()
    {
        return *(SeqTK*)&textKeys20;
    }
    EqObj* owner40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    void* root5c;
    unsigned char IsEqual_00a30fb0(SeqEqStand* other);
};
extern const char str_01020fd4[];
extern const char str_01020fc8[];
extern const char str_01020fc0[];
extern const char str_01020fb8[];
extern const char str_01020fac[];
extern const char str_01020fa0[];
extern const char str_01020f94[];
extern const char str_0109655c[];
struct S_00a31140_Allocator
{
    void* __thiscall Game_DoHeapAlloc(unsigned int);
};
extern "C" void __cdecl FUN_00ec623a(void*, const char*, const char*, const char*);
void* __cdecl FormatStringWithType(const char* arg1, void* arg2);
// Copy a group of five ref-counted fixed strings (the ref count sits 8 bytes before the text).
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern char* g_pcA1400NullString;
class A1400FixedString
{
  public:
    A1400FixedString& operator=(const A1400FixedString& kOther)
    {
        if (m_pcHandle != kOther.m_pcHandle)
        {
            char* pcNew = kOther.m_pcHandle;
            if (pcNew != g_pcA1400NullString)
                InterlockedIncrement((long volatile*)(pcNew - 8));
            if (m_pcHandle != g_pcA1400NullString)
                InterlockedDecrement((long volatile*)(m_pcHandle - 8));
            m_pcHandle = pcNew;
        }
        return *this;
    }

    char* m_pcHandle;
};
class A1400StringGroup
{
  public:
    A1400FixedString m_kName0;
    A1400FixedString m_kName1;
    A1400FixedString m_kName2;
    A1400FixedString m_kName3;
    A1400FixedString m_kName4;

    A1400StringGroup& NiControllerSequence_IDTag_Operator_Set(const A1400StringGroup& kOther);
};
struct IDTagA33a50
{
    char* m_kAVObjectName;
    char* m_kPropertyType;
    char* m_kCtlrType;
    char* m_kCtlrID;
    char* m_kInterpolatorID;
    void ReadFromStream(NiStream& kStream, unsigned int& uiPaletteLink);
};
struct AnimationSequence;
struct UpdateActiveArray
{
    void FindOrAdd(AnimationSequence* const& sequence);
};
struct UpdateNote
{
    int unk00;
    int unk04;
    int unk08;
    float time;
};
struct UpdateNoteManager
{
    void DispatchByKey(UpdateNote* note);
};
struct UpdateOwner
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
    int unk38;
    int unk3c;
    int unk40;
    UpdateActiveArray active;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    UpdateNoteManager* noteManager;
};
struct AnimationSequence : S_00a30880_Base
{
    unsigned int refs;
    char* name;
    unsigned int count;
    unsigned int grow;
    void* interpolators;
    void* tags;
    float weight;
    void* keys;
    int cycle;
    float frequency;
    float begin;
    float end;
    float lastTime;
    float weightedTime;
    float scaledTime;
    UpdateOwner* owner;
    int state;
    float offset;
    float startTime;
    float endTime;
    float destFrame;
    AnimationSequence* partner;
    char* root;
    int unk60;
    int unk64;
    short noteIndex;
    unsigned short unk6a;
    UpdateNote** notes;
    unsigned short noteCount;
    float GetMorphedTime(AnimationSequence*, float);
    float ComputeScaledTime_00a30970(float, bool);
    void NiControllerSequence_SetInterpsWeightAndTime(float, float, float);
    void Update_00a34ba0(float time, bool update);
    __forceinline bool SetState(int value)
    {
        bool inactive = state == 0;
        state = value;
        if (inactive)
        {
            AnimationSequence* self = this;
            owner->active.FindOrAdd(self);
        }
        return inactive;
    }
};
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RefObject
{
    virtual void Virtual0();
    virtual void Release();
    volatile long referenceCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            Release();
    }
    void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }
};
struct NiPointerRef
{
    RefObject* m_pObject;
    void operator=(RefObject* p)
    {
        RefObject* pOld = m_pObject;
        RefObject* pNew = p;
        if (pOld != pNew)
        {
            if (pOld)
                pOld->DecRefCount();
            m_pObject = pNew;
            if (pNew)
                pNew->IncRefCount();
        }
    }
};
struct NiItem
{
    unsigned int m0;
    NiPointerRef object4;
    unsigned int m8;
    unsigned int mc;
};
struct SequenceLink : NiObject
{
    unsigned int unk08;
    unsigned int count0c;
    unsigned int unk10;
    NiItem* items14;
    unsigned int unk18;
    unsigned int unk1c;
    NiPointerRef object20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    RefObject* object40;
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
    NiPointerRef* objects6c;
    unsigned short count70;
    void __thiscall LinkSequenceSource(NiStream*);
};
extern int(__stdcall* DAT_00fdf1c0)(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct A33950RefObject
{
    virtual void Unused();
    virtual void Release();
    volatile long refCount;
};
struct A33950Object
{
    A33950RefObject* first;
    A33950RefObject* second;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char flag0d;
    void LoadFromStream(NiStream* stream);
};
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct FUN_00a344f0_cls
{
    void __thiscall NiControllerSequence_CopyMembers(void* obj, unsigned int param);
    void* FUN_00a344f0(unsigned int param);
};
extern const float DAT_010141cc;
struct FUN_00a350d0_seq : SeqA34f20
{
    bool StartBlend(SeqA34f20* pkTarget, float fTime, float m_fTimeout, int iPriority, float fSeqWeight,
                      float fTargetWeight, SeqA34f20* pkPartner);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

extern MemoryManager _g_memoryManager;

extern int DAT_0109b220;
extern float DAT_01096548;
extern float DAT_01015f5c;

struct SeqFixedString
{
    char* m_kHandle;

    SeqFixedString() : m_kHandle((char*)DAT_0109b220)
    {}
    SeqFixedString& operator=(const SeqFixedString& kString)
    {
        if (m_kHandle != kString.m_kHandle)
        {
            char* kHandle = kString.m_kHandle;
            if (kHandle != (char*)DAT_0109b220)
                InterlockedIncrement((long volatile*)(kHandle - 8));
            if (m_kHandle != (char*)DAT_0109b220)
                InterlockedDecrement((long volatile*)(m_kHandle - 8));
            m_kHandle = kHandle;
        }
        return *this;
    }
};

struct SeqFixedHandle
{
    char* m_kHandle;
};

struct SeqNiObject
{
    SeqNiObject();
    virtual ~SeqNiObject();
    unsigned int m_uiRefCount;
};

struct SeqInterpItem
{
    void* m_spControllerInterpolator;
    void* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned short m_usFlags;

    SeqInterpItem();
    ~SeqInterpItem();
    static void* operator new[](unsigned int uiSize)
    {
        return _g_memoryManager.Allocate(uiSize);
    }
};

struct SeqTag
{
    SeqFixedString m_kAVObjectName;
    SeqFixedString m_kPropertyType;
    SeqFixedString m_kCtlrType;
    SeqFixedString m_kCtlrID;
    SeqFixedString m_kInterpolatorID;

    SeqTag();
    ~SeqTag();
    static void* operator new[](unsigned int uiSize)
    {
        return _g_memoryManager.Allocate(uiSize);
    }
};

struct SeqRefObj
{
    void* vt;
    unsigned int m_uiRefCount;
};
struct SeqPtr
{
    SeqRefObj* m_pObject;
    SeqPtr(SeqRefObj* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            InterlockedIncrement((long volatile*)&m_pObject->m_uiRefCount);
    }
};
struct ControllerSequence : SeqNiObject
{
    SeqFixedString m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    SeqInterpItem* m_pInterpArray;
    SeqTag* m_pkSeqTagArray;
    float m_fWeight;
    SeqPtr m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fScaledLastTime;
    void* m_pkOwnerManager;
    int m_eAnimationState;
    float m_fSequenceOffset;
    float m_fStartTime;
    float m_fEndTime;
    float m_fDestinationFrame;
    void* m_pkTimeSyncSequence;
    SeqFixedHandle m_kAccumulationRootName;
    void* m_pkAccumulationRoot;
    void* m_spStringPalette;
    short m_sCurAnimNIdx;
    void* m_spAnimNotes;
    unsigned short m_usNumNotes;
    bool m_bRemoveActivatorsOnDeactivate;

    ControllerSequence(const SeqFixedString& kName, unsigned int uiArraySize, unsigned int uiArrayGrowBy);
    virtual ~ControllerSequence();
};

// @fnv 0x00a32a10
ControllerSequence::ControllerSequence(const SeqFixedString& kName, unsigned int uiArraySize,
                                       unsigned int uiArrayGrowBy)
    : m_uiNumControlledBlocks(uiArraySize), m_uiNumIDTags(uiArrayGrowBy), m_pInterpArray(0), m_pkSeqTagArray(0),
      m_fWeight(1.0f), m_fFrequency(1.0f), m_fFirstKeyTime(DAT_01096548)
{
    m_eAnimationCycleType = 0;
    m_pkOwnerManager = 0;
    float fInvalid = DAT_01015f5c;
    m_eAnimationState = 0;
    m_fLastKeyTime = fInvalid;
    m_fLastTime = fInvalid;
    m_fWeightAdjustedLastTime = fInvalid;
    m_fScaledLastTime = fInvalid;
    m_fSequenceOffset = fInvalid;
    m_fStartTime = fInvalid;
    m_fEndTime = fInvalid;
    m_fDestinationFrame = fInvalid;
    m_pkTimeSyncSequence = 0;
    m_kAccumulationRootName.m_kHandle = (char*)DAT_0109b220;
    m_pkAccumulationRoot = 0;
    m_spStringPalette = 0;
    m_sCurAnimNIdx = -1;
    m_spAnimNotes = 0;
    m_usNumNotes = 0;
    m_bRemoveActivatorsOnDeactivate = false;
    m_kName = kName;
    if (m_uiNumControlledBlocks > 0)
    {
        m_pInterpArray = new SeqInterpItem[m_uiNumControlledBlocks];
        m_pkSeqTagArray = new SeqTag[m_uiNumControlledBlocks];
    }
}
