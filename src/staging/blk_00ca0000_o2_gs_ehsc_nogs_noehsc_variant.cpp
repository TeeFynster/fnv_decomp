#include "../../include/NiTArray.h"

// src/staging/blk_00ca0000_o2_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/staging/blk_00ca0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00ca0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/AutoMemContext.h"
#include "../../include/NiPointer.h"
#include "../../include/NiRefObject.h"
#include "../../include/hkMemoryAllocator.h"
// BaseCinfo_blk_00ca0000_o2_gs_ehsc_nogs_noehsc_variant: local type (was include/BaseCinfo.h, which had no evidence of one real class); no method of it is bound to a named game function
#include <stddef.h>

class NiStream;

class BaseCinfo_blk_00ca0000_o2_gs_ehsc_nogs_noehsc_variant
{
public:
    unsigned int unk00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;

    static void* operator new(size_t size) throw();
    static void operator delete(void*);

    __forceinline BaseCinfo_blk_00ca0000_o2_gs_ehsc_nogs_noehsc_variant()
        : m_iWordAt04(0), m_8(1), m_iThirdValue(0), m_10(0)
    {}

    void v00();
    void v04();
    void LoadBinary(NiStream& kStream);
};
#include "../../include/LandTextureParameters.h"
#include "../../include/CA0E60Array.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiPoint3.h"
#include "../../include/StrArr.h"
#include "../../include/bhkCapsuleShape.h"
#include "../../include/bhkCharacterPointCollector.h"
#include "../../include/bhkPackedNiTriStripsShape.h"
#include "../../include/bhkSphereShape.h"
#include "../../include/bhkRagdollTemplateData.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkSerializable.h"
#include "../../include/hkBool.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkpShapePhantom.h"
void __cdecl ReleaseStorage_00ca3570(void);
void __cdecl _delete(void* p, int);
struct FUN_00ca3980_class
{
    FUN_00ca3980_class* __thiscall FUN_00ca3980(int);
};
extern "C" void NiFreeAlias(void*);
extern int DAT_010c759c;
struct FUN_00ca4470_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void __thiscall UpdateState_00ca4470();
};
struct FUN_00ca5310_class
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_p;
};
float __fastcall GetField24Float(struct FUN_00ca5310_class* a);
struct FUN_00ca6590_t
{
    int __thiscall ProcessState_00ca6590();
    FUN_00ca6590_t* __thiscall FUN_00ca6650(int flags);
};
void __cdecl _delete(void* p, unsigned int size);
struct FUN_00ca9840_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    void SetFieldValue(float v);
};
extern int DAT_010c8288;
struct FUN_00ca9a80
{
    int a, b, c, d, e;
    FUN_00ca9a80();
};
extern "C" int __cdecl hkString_strLen(int);
struct FUN_00cb0a80_class
{
    int __thiscall hkStringPtr_getLength();
};
char ToUpperAscii(char c);
char ToLowerAscii(char param_1);
void __cdecl FUN_00cc9640();
extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00cb9b60_class
{
    FUN_00cb9b60_class* DestroyIfFlagged(int flag);
};
struct FUN_00cbc8f0_cls
{
    void hkpSimpleContactConstraintData_getContactPointIdAt(int arg);
};
struct GlobalObject_0045cfe0
{
    GlobalObject_0045cfe0(const char* name, int flags);
    void* m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
};
struct FUN_00cbf400_class : GlobalObject_0045cfe0
{
    FUN_00cbf400_class();
};
extern int DAT_010c7310;
struct FUN_00ca0d40_class
{
    void __thiscall UpdateFields_00ca0d40();
};
void __cdecl FUN_00ca4490();
extern MemoryManager _g_memoryManager;
struct FUN_00ca4a90_Class
{
    FUN_00ca4a90_Class* __thiscall FUN_00ca4a90(int flags);
};
extern int DAT_01030a24;
extern int DAT_01030b0c;
extern int DAT_01030bf4;
extern int DAT_01066e2c;
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_01268274;
extern int DAT_01268324;
void __cdecl RegisterStaticCollisionAgent(void*);
void __cdecl hkPredGskAgent3_registerAgent3(void*, int, int);
void __cdecl RegisterScriptHandlers(void*);
void __cdecl hkpBoxBoxAgent_registerAgent(void*);
void __cdecl hkBoxBoxAgent3_registerAgent3(void*);
void __cdecl Object_UpdateFields_00d3fd00(void*);
void __cdecl hkpSphereCapsuleAgent_registerAgent(void*);
void __cdecl Object_UpdateFields_00d3dca0(void*);
void __cdecl hkpSphereBoxAgent_registerAgent(void*);
void __cdecl RegisterHandlers(void*);
void __cdecl Object_UpdateFields_00d3abc0(void*);
void __cdecl hkCapsuleTriangleAgent3_registerAgent3(void*);
void __cdecl hkpMultiSphereTriangleAgent_staticGetPenetrations_UpdateState_00d389f0(void*);
void __cdecl hkpMultiRayConvexAgent_registerAgent(void*);
void __cdecl hkpBvTreeStreamAgent_registerMultiRayAgent(void*);
void __cdecl hkpAgentRegisterUtil__registerTerminalAgents(void* a);
struct FUN_00cbbfa0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00cbbfa0_class();
};
struct FUN_00ca5540_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_p;
    int GetEntryValue(int i);
};
extern int DAT_010c8d14;
struct FUN_00cba080_class
{
    int m_vtbl;
    void* m_data;
    int m_8;
    int m_iThirdValue;
    FUN_00cba080_class* __thiscall FUN_00cba080(int flag);
};
extern int DAT_010c8d00;
extern void(__cdecl* DAT_010c8d08)(void*);
struct FUN_00cba030_class
{
    int m_vtbl;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    FUN_00cba030_class* __thiscall FUN_00cba030(int flag);
};
struct FUN_00ca2020_Class
{
    void FUN_00ca2020();
};
struct FUN_00ca20e0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void ClearAndFreeEntries();
};
void __cdecl _NiFree(void*);
struct FUN_00ca4440_Class
{
    void* m_vtbl;
    void* m_data;
    FUN_00ca4440_Class* __thiscall FUN_00ca4440(unsigned int flags);
};
extern int(__stdcall* DAT_00fdf1c4)(void*);
extern void(__stdcall* DAT_00fdf1c0)(void*);
struct FUN_00ca47a0_Class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    FUN_00ca47a0_Class* __thiscall AssignFrom(FUN_00ca47a0_Class* other);
};
struct FUN_00ca5340_class
{
    int __thiscall FUN_00ca5290();
    FUN_00ca5340_class* __thiscall FUN_00ca5340(int flags);
};
extern int _data_011c16bc;
extern int DAT_010c44e4;
extern int DAT_010c761c;
extern int DAT_012682d8;
extern int DAT_012686d0;
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};
struct S_00cb79d0_Base : public A51BF0Base
{
    void* m_vptr;
    char m_iWordAt04[8];
    int m_iThirdValue;
    int m_10;

    S_00cb79d0_Base();
};
bhkPackedNiTriStripsShape* CreatePackedNiTriStripsShape();
struct HC1Base
{
    bool BSPackedAdditionalGeometryData_RegisterStreamables(NiStream*);
    bool bhkPackedNiTriStripsShape_RegisterStreamables(NiStream*);
};
float __fastcall Object_GetNestedFloatOrOne_00ca6620(void* p, int);
float __cdecl hkpConstraintData_getMaxLinearImpulse();
extern int DAT_0102e388;
void __fastcall Object_SetVirtualTable_00ca9900(int* p);
void __cdecl _delete(void* p, int size);
struct FUN_00ca9920_class
{
    void __thiscall FUN_00ca9860();
    FUN_00ca9920_class* __thiscall FUN_00ca9920(int flags);
};
struct FUN_00cac980_Holder
{
    void* hkpCharacterProxy_getShapePhantom();
};
struct BaseThunk
{
    bool BSTextureSet_RegisterStreamables(NiStream&);
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00cac980_Holder* m_8;
};
struct FUN_00cac070_Stub : BaseThunk
{
    void bhkCharacterProxy_RegisterStreamables(NiStream&);
};
struct FUN_00cac920_Class
{
    char pad[0x30];
    void* m_30;
    char pad2[0x24];
    float m_58;
    float m_5c;
    void __thiscall hkpCharacterProxy_setPosition(void* body);
};
extern int DAT_010c8b0c;
extern int DAT_01268648;
struct FUN_00cb99a0_class
{
    void __thiscall FUN_00cb99a0(int a);
};
struct FUN_00cb9b30_class : FUN_00cb99a0_class
{
    int m_vtbl;
    FUN_00cb9b30_class(int a);
};
struct FUN_00cc66b0
{
    virtual ~FUN_00cc66b0();
};
struct FUN_00cb9c10_class : FUN_00cc66b0
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c10_class* __thiscall FUN_00cb9c10(int flags);
};
extern int DAT_010c8cc8;
struct FUN_00cb9c30_class
{
    int m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c30_class();
};
extern int DAT_010c8ce4;
struct FUN_00cb9c50_class
{
    int m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c50_class();
};
struct MemoryManagerReallocateHelper
{
    void* __thiscall Reallocate(void* p, unsigned int size);
};
struct FUN_00cb9cc0_class
{
    void* __thiscall ReallocateArray(void* p, unsigned int count);
};
void __stdcall Runtime_ProcessEntries_00cb9d50(int* p, unsigned int n);
struct FUN_00cba000_class
{
    int m_vtbl;
    void* m_data;
    int m_8;
    int m_iThirdValue;
    ~FUN_00cba000_class();
};
extern void(__stdcall* DAT_010c8d1c)(void*);
void __cdecl FUN_00cba1d0();
struct FUN_00cba6d0_class
{
    FUN_00cba6d0_class* __thiscall FUN_00cba6d0(int flags);
};
extern float g_fCA0CD0StepTime;
extern float DAT_011ac39c;
__int64 CA0CD0GetPerformanceCounter();
class CA0CD0World
{
  public:
    void Reset();
};
struct CA0CD0Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CA0CD0World* m_pkWorld;
    int unk14;
    int unk18;
    int unk1C;
    bool m_bValueAt0C;
};
class CA0CD0Manager
{
  public:
    int unk00;
    int unk04;
    CA0CD0Entry** m_ppkEntries;
    unsigned int m_uiCount;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __int64 m_i64StartTime;
    __int64 m_i64Duration;

    void ResetEntries();
};
extern int DAT_010c7310;
extern void(__stdcall* DAT_010c7318)(void*);
extern MemoryManager _g_memoryManager;
struct FUN_00ca0d70_Class
{
    int m_vtbl;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void* __thiscall FUN_00ca0d70(unsigned char flag);
};
struct SubObject04
{
    virtual ~SubObject04();
    virtual void Slot1();
    virtual void Free(void* apPtr);
    int unk04;
    int unk08;
    int unk0c;

    SubObject04();
};
struct Flag18
{
    unsigned char m_v;
    Flag18()
    {
        m_v = 0;
    }
    ~Flag18();
};
SubObject04::SubObject04()
{
    unk04 = 0;
    unk08 = 0;
    unk0c = 0;
}
struct GuardBase04
{
    GuardBase04()
    {}
    ~GuardBase04();
};
struct FUN_00ca0dc0_cls : GuardBase04
{
    virtual ~FUN_00ca0dc0_cls();
    SubObject04 m_sub04;
    int unk14;
    unsigned char m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;

    FUN_00ca0dc0_cls();
};
// BSSimpleArray-style container of pointer-sized elements.
struct CA1080_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};
struct CA1080_Holder
{
    int unk00;
    int unk04;
    int unk08;
    CA1080_Shape* shape;
};
struct CA1080_Entry
{
    CA1080_Holder* holder;
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
};
struct CA1080_Node
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
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
    CA1080_Entry* entries;
    unsigned short entryCount;
    unsigned short unkb2;
    CA1080_Holder** holders;
    int holderCount;
};
struct CA1080_NodeList
{
    CA1080_Node** data;
    int count;
    CA1080_Node* GetAt(int i) const
    {
        return data[i];
    }
};
struct CA1080_PtrArray
{
    virtual void v00();
    virtual void** Allocate(unsigned int count);
    virtual void v08();
    virtual void** Reallocate(void** data, unsigned int count);

    void** data;
    unsigned int size;
    unsigned int capacity;

    void Add(void* item)
    {
        if (size == capacity)
        {
            if (capacity == 0)
            {
                data = Allocate(4);
                capacity = 4;
            }
            else
            {
                unsigned int newCap = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                if (data)
                {
                    data = Reallocate(data, newCap);
                }
                else
                {
                    data = Allocate(newCap);
                    capacity = newCap;
                }
                capacity = newCap;
            }
        }
        size++;
        data[size - 1] = item;
    }
};
void __stdcall CollectMixedTypeNodes(CA1080_NodeList* list, CA1080_PtrArray* out);
extern int DAT_01267e64;
extern int DAT_012681c0;
extern int DAT_011f4428;
struct SceneLookupBase_cls
{
    void* Find(const void* key);
};
struct SceneHost_cls : SceneLookupBase_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SceneHost_cls* m_10;
};
struct SceneLeaf_cls : SceneLookupBase_cls
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
    virtual int v37();
};
struct SceneNode_cls : SceneLookupBase_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    SceneHost_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    SceneNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
struct SceneWalker_cls
{
    void TraverseSceneNode(SceneNode_cls* node, int a2, int a3);
    void CollectLeafObjects(SceneLeaf_cls* leaf, int a2, int a3);
};
struct FNVTaskElement
{
};
extern "C" void __fastcall nullsub_14(FNVTaskElement* element);
struct FNVTaskAllocator
{
    virtual void fn00();
    virtual void fn04();
    virtual void fn08();
    virtual void fn0c();
    virtual void Free(void* memory, unsigned int byteCount);
};
struct FNVTaskMemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FNVTaskAllocator* allocator;
};
extern "C" FNVTaskMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FNVTaskDynamicBuffer
{
    void* entries;
    int elementCount;
    unsigned int capacityAndFlags;
    void __thiscall Clear();
};
extern __declspec(thread) int g_iCA2020AllocTag;
struct CA2020AllocTagScope
{
    int m_iSaved;

    CA2020AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA2020AllocTag;
        g_iCA2020AllocTag = aiAllocationTag;
    }
    ~CA2020AllocTagScope()
    {
        g_iCA2020AllocTag = m_iSaved;
    }
};
class CA2020Object
{
  public:
    virtual ~CA2020Object();
};
class CA2020Referenced
{
  public:
    void removeReference();
};
class CA2020Array
{
  public:
    ~CA2020Array();

    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapacityAndFlags;
};
class FUN_00ca2020_Holder
{
  public:
    ~FUN_00ca2020_Holder();

    int unk00;
    CA2020Referenced* m_pkShape;
    CA2020Object* m_pkFirst;
    CA2020Object* m_pkSecond;
    CA2020Referenced* m_pkBody;
    CA2020Array m_kEntries;
};
struct FUN_00a5d3d0_class
{
    void __thiscall FUN_00a5d3d0();
};
struct FUN_00ca3570_class : FUN_00a5d3d0_class
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;

    void __thiscall ReleaseStorage_00ca3570();
};
extern "C" char DAT_010c740c[];
extern MemoryManager _g_memoryManager;
struct Record
{
    int m_iValue;
    int m_iField04;
    int m_iField08;
};
struct Table
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int* m_pValues;
};
struct Owner
{
    int unk00[29];
    Table* m_pTable;

    int GetValueByIndex(unsigned int a1);
};
struct FUN_00ca3b10_cls
{
    int m_iWordAt00;
    unsigned char m_iWordAt04;
    int m_8;

    bool hkpMeshShape_isWeldingEnabled();
};
void __cdecl _NiFree_00aa10f0(void*);
struct PrimaryPart
{
    virtual ~PrimaryPart()
    {}
    unsigned int unknown_04, unknown_08, unknown_0c;
};
struct SecondaryPart
{
    virtual ~SecondaryPart()
    {}
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
};
struct CombinedBase : PrimaryPart, SecondaryPart
{
    virtual ~CombinedBase()
    {}
};
struct ResourceMember
{
    virtual ~ResourceMember()
    {
        _NiFree_00aa10f0(data);
    }
    void* data;
};
struct FUN_00ca4490 : CombinedBase
{
    ResourceMember resource;
    virtual ~FUN_00ca4490();
};
struct FUN_00ca4780_tableEntry
{
    unsigned int m_iIndex;
    void* m_pIntegerData;
};
struct FUN_00ca4780_cls
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    FUN_00ca4780_tableEntry* m_pTable;
    void* hkNiTriStripsShape_getCollisionFilterInfo(unsigned int a1);
};
struct S_00ca49a0_Obj
{
    long m_refs;
    virtual void vfn0();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_refs))
            DeleteThis();
    }
};
struct S_00ca49a0_Ptr
{
    S_00ca49a0_Obj* m_p;
    S_00ca49a0_Ptr(S_00ca49a0_Obj* p = 0)
    {
        m_p = p;
        if (m_p)
            m_p->IncRefCount();
    }
    S_00ca49a0_Ptr(const S_00ca49a0_Ptr& o)
    {
        m_p = o.m_p;
        if (m_p)
            m_p->IncRefCount();
    }
    ~S_00ca49a0_Ptr()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    S_00ca49a0_Ptr& operator=(const S_00ca49a0_Ptr& o)
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
struct S_00ca49a0_Elem
{
    S_00ca49a0_Ptr obj;
    int unk04;
    S_00ca49a0_Elem(int v = 0) : obj(0)
    {
        unk04 = v;
    }
    bool operator==(const S_00ca49a0_Elem& o) const
    {
        return obj.m_p == o.obj.m_p && unk04 == o.unk04;
    }
    bool operator!=(const S_00ca49a0_Elem& o) const
    {
        return !(*this == o);
    }
};
struct S_00ca49a0_Array
{
    int unk00;
    S_00ca49a0_Elem* m_pBase;
    int unk08;
    unsigned int m_uiESize;
    unsigned int m_uiCount;
    void NiTLargeArray_hkNiTriStripsData_NiTMallocInterface_hkNiTriStripsData_SetAt(unsigned int idx, const S_00ca49a0_Elem& e);
};
struct HandlePage
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    unsigned short m_40;
};
struct HandleSlot
{
    HandlePage* m_pHandlePage;
    int m_04;
};
struct HandleOwner
{
    bool __thiscall IsDegenerate(unsigned int handle);
};
class HandleManager
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    int m_50;
    int m_54;
    int m_58;
    int m_5C;
    int m_60;
    int m_64;
    int m_68;
    int m_6C;
    int m_70;
    int m_74;
    int m_78;
    int m_7C;
    int m_80;
    int m_84;
    HandleSlot* m_88;
    int m_8C;
    int m_90;

    int __thiscall hkNiTriStripsShape_getNextKey(int handle);
};
struct RefEntryObject
{
    virtual void Unknown();
    virtual void Release();
    volatile long referenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            Release();
    }
};
struct RecordEntry
{
    NiPointer<RefEntryObject> object;
    unsigned int value;
    RecordEntry() : object(), value(0)
    {}
};
struct RecordArray
{
    void* vtable;
    RecordEntry* records;
    unsigned int capacity;
    unsigned int count;
    unsigned int elementSize;
    void ClearRecords();
};
class FUN_00ca4d20_cls;
class FNVSub3Blob
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVSub4
{
  public:
    void Attach(void* p);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVEntry
{
  public:
    unsigned int unk00;
    unsigned int unk04;
};
class FNVSub2
{
  public:
    void Reset();
    void Grow(void* p);
    void Store(unsigned int index, FNVEntry* entry);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int unk10;
    void* m_14;
};
class FNVArg
{
  public:
    unsigned int unk00;
    float m_04;
    FNVSub2 m_08;
    FNVSub4 m_20;
};
class FUN_00ca4d20_cls
{
  public:
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
    FNVSub3Blob m_80;
    float m_90;
    unsigned int unk94;
    FNVEntry* m_98;
    unsigned int unk9c;
    int m_a0;
    void CopyEntriesToArg(FNVArg* a1);
};
struct S_00ca4e10_T
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00ca4e10_Out
{
    int unk00;
    void* unk04;
};
struct S_00ca4e10_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual char* v10();
};
struct S_00ca4e10_Cls
{
    int unk00;
    int unk04;
    S_00ca4e10_Obj* unk08;
    void bhkShape_CopyCinfo(S_00ca4e10_Out* out);
    char* bhkBvTreeShape_CopyCinfo(S_00ca4e10_Out* out);
};
extern int DAT_012682d8;
struct FUN_00cd2de0
{
    virtual ~FUN_00cd2de0();
};
struct FUN_00ca5290 : FUN_00cd2de0
{
    virtual ~FUN_00ca5290();
    void bhkSerializable_Kill();
};
extern int DAT_012682dc;
int* __cdecl bhkPackedNiTriStripsShape_GetRTTI();
struct MatchData
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
    int value84;
};
struct MatchObject
{
    int unk00;
    int unk04;
    MatchData* data;
    bool __thiscall bhkShape_IsEqual(MatchObject* rhs);
    bool __thiscall Equals(MatchObject* rhs);
};
struct S_00ca59d0_Out;
struct S_00ca59d0_Bin
{
    int unk00;
    unsigned int unk04;
    unsigned int(__cdecl* unk08)(S_00ca59d0_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* unk0C)(S_00ca59d0_Bin*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* buf, unsigned int bytes, unsigned int* compSize, unsigned int n)
    {
        unk04 += unk0C(this, buf, bytes, compSize, n);
    }
};
template <class T> inline void S_00ca59d0_Save(S_00ca59d0_Bin& bin, const T* p, unsigned int n)
{
    unsigned int uiSize = sizeof(T);
    bin.Write(p, n * sizeof(T), &uiSize, 1);
}
struct S_00ca59d0_Stream
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
    virtual void v12(int link);
    int unk4;
    int unk8;
    int unkC;
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
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    S_00ca59d0_Bin* unk250;
};
struct S_00ca59d0_Vec4
{
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};
struct S_00ca59d0_Member
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    S_00ca59d0_Vec4 unk90;
    float unkA0;
};
struct S_00ca59d0_Self
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
    virtual void v41(int out);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45(int* out);
    int unk04;
    S_00ca59d0_Member* unk08;
    void bhkShape_SaveBinary(S_00ca59d0_Stream* s);
    void bhkPackedNiTriStripsShape_SaveBinary(S_00ca59d0_Stream* s);
};
struct TlsBlock_t
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
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};
__declspec(thread) TlsBlock_t g_tlsBlock;
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};
struct Owned_t
{
    void Destroy();
};
struct PoolFree_t
{
    void Free(void* p);
};
extern PoolFree_t DAT_011f6238;
struct FUN_00ca5a80_cls
{
    int unk00;
    int unk04;
    int unk08;
    Owned_t* m_0c;

    void ReleaseOwned(bool flag);
};
// FUN_00ca6600 : a one-line function - getter
extern int g_target_00ca6600;
void* bhkNiTriStripsShape_GetRTTI();
extern int DAT_012680f8;
extern int DAT_012686d0;
extern int DAT_012682e4;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct OwnerBase
{
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};
struct ChainA_cls : public OwnerBase
{
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls()
    {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};
struct ChainB_cls : public ChainA_cls
{
    virtual void unkB1();
    ChainB_cls()
    {
        DAT_012686d0 += 1;
    }
};
struct SpawnedObject : public ChainB_cls
{
    virtual void unkD2();
    SpawnedObject()
    {
        DAT_012682e4 += 1;
    }
};
SpawnedObject* bhkNiTriStripsShape_CreateObject();
struct ArgB
{
    unsigned int unk00, unk04, unk08, unk0c;
    float f10;
};
struct S_00ca6810_Callable
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54(int arg);
};
struct S_00ca6810_Entry
{
    S_00ca6810_Callable* callable;
    int unk04;
};
struct S_00ca6810_Inner
{
    void* unk00;
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
    S_00ca6810_Entry* unk98;
    int unk9c;
    int unkA0;
};
extern S_00ca6810_Callable* DAT_012682f0;
struct S_00ca6810_Class
{
    void* unk00;
    int unk04;
    S_00ca6810_Inner* unk08;

    void __thiscall BSPackedAdditionalGeometryData_RegisterStreamables(int arg);
    void __thiscall bhkNiTriStripsShape_RegisterStreamables(int arg);
};
struct S_00ca6880_Node
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
};
struct S_00ca6880_Class
{
    int unk00;
    int unk04;
    S_00ca6880_Node* unk08;
    char __thiscall bhkShape_IsEqual(S_00ca6880_Class* arg);
    char __thiscall IsEquivalent(S_00ca6880_Class* arg);
};
static inline int Val(S_00ca6880_Class* o)
{
    if (o && o->unk08)
        return o->unk08->unka0;
    return 0;
}
extern __declspec(thread) int g_threadAllocationContext;
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
extern int DAT_010c771c;
extern int DAT_012682e4;
struct AllocationContextGuard
{
    int previous;
    AllocationContextGuard()
    {
        previous = g_threadAllocationContext;
        g_threadAllocationContext = 16;
    }
    ~AllocationContextGuard()
    {
        g_threadAllocationContext = previous;
    }
};
struct FNVShape : S_00cb79d0_Base
{
    FNVShape()
    {
        m_vptr = &DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        ++DAT_012680f8;
        m_vptr = &DAT_010c44e4;
        ++DAT_012686d0;
        m_vptr = &DAT_010c771c;
        ++DAT_012682e4;
    }
};
struct FNVShapeHost
{
    virtual void Slot00() = 0;
    virtual void Slot04() = 0;
    virtual void Slot08() = 0;
    virtual void Slot0c() = 0;
    virtual void Slot10() = 0;
    virtual void Slot14() = 0;
    virtual void Slot18() = 0;
    virtual void Slot1c() = 0;
    virtual void Slot20() = 0;
    virtual void Slot24() = 0;
    virtual void Slot28() = 0;
    virtual void Slot2c() = 0;
    virtual void Slot30() = 0;
    virtual void Slot34() = 0;
    virtual void Slot38() = 0;
    virtual void Slot3c() = 0;
    virtual void Slot40() = 0;
    virtual void Slot44() = 0;
    virtual void Slot48() = 0;
    virtual void Slot4c() = 0;
    virtual void Slot50() = 0;
    virtual void Slot54() = 0;
    virtual void Slot58() = 0;
    virtual void Slot5c() = 0;
    virtual void Slot60() = 0;
    virtual void Slot64() = 0;
    virtual void Slot68() = 0;
    virtual void Slot6c() = 0;
    virtual void Slot70() = 0;
    virtual void Slot74() = 0;
    virtual void Slot78() = 0;
    virtual void Slot7c() = 0;
    virtual void Slot80() = 0;
    virtual void Slot84() = 0;
    virtual void Slot88() = 0;
    virtual void Slot8c() = 0;
    virtual void Slot90() = 0;
    virtual void Slot94() = 0;
    virtual void Slot98() = 0;
    virtual void Slot9c() = 0;
    virtual void Slota0() = 0;
    virtual void Slota4() = 0;
    virtual void Slota8() = 0;
    virtual void Slotac() = 0;
    virtual void Slotb0() = 0;
    virtual void Slotb4() = 0;
    virtual void Slotb8() = 0;
    virtual void Slotbc() = 0;
    virtual void Slotc0() = 0;
    virtual void AssignShape(FNVShape* shape, int flags) = 0;
    FNVShape* CreateShape(int flags);
};
struct S_00ca7310_Arr
{
    int* m_data;
    int m_iElementCount;
    unsigned int m_pRayCursor;
    S_00ca7310_Arr() : m_data(0), m_iElementCount(0), m_pRayCursor(0x80000000)
    {}
};
struct S_00ca7310_Root
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00ca7310_Root()
    {
        unk00 = 0;
    }
};
struct S_00ca7310_Vec
{
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    S_00ca7310_Vec()
    {
        unk10 = 0.0f;
        unk14 = 0.0f;
        unk18 = 0.0f;
        unk1C = 0.0f;
    }
};
struct FUN_00ca7310 : S_00ca7310_Root
{
    S_00ca7310_Vec vec;
    int unk20;
    S_00ca7310_Arr unk24;
    S_00ca7310_Arr unk30;
    S_00ca7310_Arr unk3C;
    S_00ca7310_Arr unk48;
    S_00ca7310_Arr unk54;
    S_00ca7310_Arr unk60;
    S_00ca7310_Arr unk6C;
    S_00ca7310_Arr unk78;
    S_00ca7310_Arr unk84;
    S_00ca7310_Arr unk90;
    S_00ca7310_Arr unk9C;
    S_00ca7310_Arr unkA8;
    FUN_00ca7310();
};
struct MotionByte
{
    void FindFloatTableIndex(const float*);
};
struct MotionInstance
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void SetMass(float);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void SetInertia(const float*);
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void SetGridPosition(const void*);
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
    MotionByte linearDamping;
    MotionByte angularDamping;
};
struct MotionStorage
{
    MotionInstance* FUN_00ca9270(const void*, const void*);
    MotionInstance* FUN_00d1e690(const void*, const void*);
    MotionInstance* FUN_00d21930(const void*, const void*);
    MotionInstance* FUN_00d1dfa0(const void*, const void*);
    MotionInstance* FUN_00ca9240(const void*, const void*);
    MotionInstance* InitFixedRigidMotion(const void*, const void*);
};
float NiMin(float, float);
float NiMax(float, float);
void hkpRigidBody_createDynamicRigidMotion(int type, const void* position, const void* rotation, float mass, const float* inertia,
                  const void* center, float linearDamping, float angularDamping, MotionStorage* storage);
struct Ctx
{
    void* pThis;
    int a1;
    char a2;
};
struct Obj
{
    virtual void v0();
    virtual void v1(Ctx*);
};
struct C
{
    char pad[0x8c];
    Obj** m8c;
    int m90;
    void NotifyAll(int a1, char a2);
};
extern int DAT_0126830c;
class FUN_00ca9860_base
{
  public:
    virtual ~FUN_00ca9860_base();
};
class FUN_00ca9860_cls : public FUN_00ca9860_base
{
  public:
    virtual ~FUN_00ca9860_cls();
    void bhkSerializable_Kill();
};
extern int DAT_01268310;
int __cdecl Runtime_EvaluateValue_00ca9910();
struct S_00ca9940_Child
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual unsigned int vfn_20();
};
struct S_00ca9940_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00ca9940_Child* m_pChildObject;
};
void __cdecl hkBallAndSocketConstraintCinfo_ApplyScale(float f, S_00ca9940_Child* c);
void __cdecl hkHingeConstraintCinfo_ApplyScale(float f, S_00ca9940_Child* c);
void __cdecl hkMalleableConstraintCinfo_ApplyScale(float f, S_00ca9940_Obj* o);
struct FUN_00ca9aa0;
struct State
{
    unsigned int value;
    State() : value(0)
    {}
};
struct BaseOwner
{
    virtual void Act();
    unsigned short unk04;
    unsigned short unk06;
    State unk08;
    BaseOwner() : unk06(1), unk08()
    {}
};
struct InternalPart
{
    unsigned short mode;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    InternalPart() : mode(1)
    {}
    ~InternalPart();
};
void __fastcall hkpBridgeConstraintAtom_init(InternalPart* part, unsigned int command, FUN_00ca9aa0* parent);
struct FUN_00ca9aa0 : BaseOwner
{
    virtual void Act();
    unsigned int unk0c;
    InternalPart part;
    float value;
    FUN_00ca9aa0();
};
class BCA9D50BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCA9D50BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCA9D50BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BCA9D50Stream
{
  public:
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
    unsigned int m_uiFileVersion;
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
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BCA9D50BinaryStream* m_pUnderlyingStream;
    BCA9D50BinaryStream* m_pBackingStream;
};
template <class T>
inline void BCA9D50BinaryStreamSave(BCA9D50BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BCA9D50SaveBinary(BCA9D50Stream& kStream, const T& value)
{
    BCA9D50BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
class BCA9D50Object;
void __cdecl bhkConstraintManager_SaveBinary(BCA9D50Stream& kStream, BCA9D50Object* pkObject);
struct BCA9D50Data
{
    int unk00;
    int unk04;
    int unk08;
    BCA9D50Object* m_pPointer;
    int unk10;
    int unk14;
    int unk18;
    float m_fValue;
};
class BCA9D50Base
{
  public:
    void SaveBinary(BCA9D50Stream& kStream);
};
class BCA9D50Wrapper : public BCA9D50Base
{
  public:
    int unk00;
    BCA9D50Data* m_pUserData;

    void hkMalleableConstraintCinfo_SaveBinary(BCA9D50Stream& kStream);
};
struct FUN_00ca9b40_Obj
{
    void __thiscall UpdateFields_00ca9b40(int value);
};
struct FUN_00ca9e50_Obj
{
    int unk00;
    FUN_00ca9b40_Obj* unk04;

    void __thiscall ProcessState_00ca9e50(int value);
};
extern int DAT_01268318;
class PolyBase
{
  public:
    virtual ~PolyBase();
};
class FUN_00caa140_cls : public PolyBase
{
  public:
    virtual ~FUN_00caa140_cls();
    void bhkSerializable_Kill();
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct SpawnedObject20_b9537
{
    char m00[0x14];
    SpawnedObject20_b9537();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
SpawnedObject20_b9537* CreateSpawnedObject20();
unsigned int __cdecl PackBytesBigEndian(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
struct FUN_00cac9a0_Obj
{
    void __thiscall getCinfo(int value);
};
struct FUN_00cabfd0_Obj
{
    int unk00;
    int unk04;
    FUN_00cac9a0_Obj* unk08;

    void __thiscall bhkCharacterProxy_GetCinfo(int value);
};
struct FUN_00cabff0_res
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
};
struct FUN_00cabff0_cls
{
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
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual FUN_00cabff0_res* SlotB4(int* p);
    void FUN_00c87650(int a);
    void bhkCharacterProxy_LoadBinary(int a);
};
void __fastcall ReadLinkID(int a);
struct S_00cac0b0_Arg
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c(int value);
};
struct S_00cac0b0_Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00cac0b0_Obj
{
    int unk00;
    int unk04;
    S_00cac0b0_Inner* unk08;
    S_00cac0b0_Inner* hkpCharacterProxy_getShapePhantom();
};
struct S_00cac0b0_cls
{
    int unk00;
    int unk04;
    S_00cac0b0_Obj* unk08;
    void bhkCharacterProxy_SaveBinary(S_00cac0b0_Arg* a);
    void SaveSerializeData(S_00cac0b0_Arg* a);
};
struct FUN_00cac110_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void bhkCharacterController_UnMarkWrite();
};
class CAC680World
{
  public:
    void Update();
};
class CAC680Listener
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void OnUpdate();

    int unk04;
};
class CAC680Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void Toggle();

    int unk04;
    CAC680World* m_pkWorld;
    int unk0C;
    CAC680Listener m_kListener;

    void ToggleAndUpdate();
};
// Rect-like record used by InitRect and its helper.
struct FUN_00cb0ed0_rect
{
    volatile int m_fMinimumU;
    volatile int m_fMinimumV;
    volatile int m_fMaximumU;
    volatile int m_fMaximumV;
    volatile bool m_bValueAt0C;
};
void __cdecl ResizeBuffer(FUN_00cb0ed0_rect* pRect, int aFlag);
void __cdecl InitRect(FUN_00cb0ed0_rect* pRect, int nLeft, int nSize);
static __declspec(noinline) char CB1030ToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (char)(c - 'A' + 'a');
    return c;
}
// Exported elsewhere through a function pointer, which keeps the helper's cdecl stack arguments.
char(__cdecl* g_pfnCB1030ToLower)(char) = CB1030ToLower;
int __cdecl CompareCaseInsensitive(const char* pcA, const char* pcB, int n);
// FUN_00cb75d0 : default constructor of the object whose first member holds
// the class table pointer.  The constructor clears three trailing dword
// members, sets a byte flag to 1 and installs the table pointer last.
extern int DAT_010c88b8;
struct FUN_00cb75d0_cls
{
    void* m_pVTable;
    int m_iValue04;
    unsigned char m_bValue08;
    int m_iValue0c;
    int m_iValue10;

    FUN_00cb75d0_cls();
};
static float DAT_010c8ae4 = 0.016f;
extern double DAT_010241b0;
struct S_00cb9770_Foo
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
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual float V41(float value);

    int unk04;
    unsigned short unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    float unk20;
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
    float unk50;

    void __thiscall bhkForceController_ApplyForce();
    bool GetActive()
    {
        return ((this->unk08 >> 3) & 1) != 0;
    }
    void __thiscall UpdateActiveState(float* param);
};
extern int DAT_01268188;
extern int DAT_0108febc;
struct FUN_00c87c30
{
    void* vtable;
    int unk04;
    int unk08;
    FUN_00c87c30();
};
struct InitializedField
{
    int value;
    InitializedField() : value(0)
    {}
    ~InitializedField();
};
struct FUN_00cb99a0 : FUN_00c87c30
{
    InitializedField unk0c;
    FUN_00cb99a0(char* source);
    void SpawnAndAttach(char* source);
};
extern int DAT_012680f8;
extern int DAT_01268274;
extern int DAT_01268250;
extern int DAT_01268324;
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126864c;
GlobalObjectO2_00a7b610* __cdecl bhkBallAndSocketConstraint_GetRTTI();
struct CB9B80Header
{
    int unk00;
};
struct CB9B80BaseInfo
{
    int unk00;
};
struct CB9B80Info : CB9B80Header, CB9B80BaseInfo
{
};
class CB9B80RefObject
{
  public:
    CB9B80RefObject();
    virtual ~CB9B80RefObject();

    int unk04;
    int unk08;
};
class CB9B80SerializableObject : public CB9B80RefObject
{
  public:
    CB9B80SerializableObject() : m_pkWorld(0)
    {}

    void* m_pkWorld;
};
class CB9B80WorldObject : public CB9B80SerializableObject
{
  public:
    CB9B80WorldObject()
    {
        ++ms_uiCount;
    }
    virtual ~CB9B80WorldObject();

    static unsigned int ms_uiCount;
};
class FUN_00cb9b80 : public CB9B80WorldObject
{
  public:
    FUN_00cb9b80(CB9B80Info* pkInfo);
    virtual ~FUN_00cb9b80();

    void Init(CB9B80BaseInfo* pkInfo);

    static unsigned int ms_uiCount;
};
struct CpuOpaque;
extern CpuOpaque DAT_01268610;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00cb9c00();
class FUN_00cb9c70_item
{
  public:
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
    virtual void v20();
    virtual void v21(int a1);
};
class FUN_00cb9c70_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00cb9c70_item** m_ppItems;
    unsigned int m_uiCount;
    bool Check(int a1);
    bool bhkRagdollTemplate_RegisterStreamables(int a1);
};
struct ArgStandIn
{
    NiRefObject* FUN_00a63430();
};
class FUN_00cb9ee0_cls
{
  public:
    void AssignRefCountedArray(ArgStandIn* arg);
    void FUN_00a7b3b0(ArgStandIn* arg);

    char unk00[0x10];
    NiRefObject** m_10;
    unsigned int m_14;
};
class BCB9F60BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCB9F60BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCB9F60BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BCB9F60Stream
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void SaveLinkID(void* pkObject);

  public:
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
    unsigned int m_uiFileVersion;
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
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BCB9F60BinaryStream* m_pUnderlyingStream;
    BCB9F60BinaryStream* m_pBackingStream;
};
template <class T>
inline void BCB9F60BinaryStreamSave(BCB9F60BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BCB9F60SaveBinary(BCB9F60Stream& kStream, const T& value)
{
    BCB9F60BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
class BCB9F60ExtraData
{
  public:
    void SaveBinary(BCB9F60Stream& kStream);
};
class BCB9F60LinkData : public BCB9F60ExtraData
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void** m_ppkObjects;
    unsigned int m_uiCount;

    void bhkRagdollTemplate_SaveBinary(BCB9F60Stream& kStream);
};
// Releases the resource held by the object and resets it to its empty state.
typedef void(__stdcall* FreeFn)(void*);
struct FUN_00cb9fd0_cls
{
    void* m_ppVirtualMethodTable;
    void* m_pData;
    int m_i08;
    int m_i0c;
    void ResetAndFreeData();
};
class FUN_00cba0d0_cls
{
  public:
    virtual void v0();
    virtual void v1();
    long m_04;
};
void __stdcall ReleaseItems(FUN_00cba0d0_cls** items, unsigned int count);
extern void* DAT_0109b220;
extern int(__stdcall* DAT_00fdf1c4)(void*);
void* __cdecl FUN_00a5b690(int flag);
class CBaseOwner
{
  public:
    virtual void unk00();
    unsigned int unk04;
    CBaseOwner();
    ~CBaseOwner();
};
class CSlot08
{
  public:
    void* p;
    CSlot08(void* v)
    {
        p = v;
    }
    ~CSlot08();
};
class CSubA
{
  public:
    virtual void unkA00();
    unsigned int unkA04;
    unsigned int unkA08;
    unsigned int unkA0c;
    CSubA()
    {
        unkA04 = 0;
        unkA08 = 0;
        unkA0c = 0;
    }
    ~CSubA();
};
class CSubB
{
  public:
    virtual void unkB00();
    unsigned int unkB04;
    unsigned int unkB08;
    unsigned int unkB0c;
    CSubB()
    {
        unkB04 = 0;
        unkB08 = 0;
        unkB0c = 0;
    }
    ~CSubB();
};
class FUN_00cba110 : public CBaseOwner
{
  public:
    CSlot08 m_08;
    CSubA m_0c;
    CSubB m_1c;
    FUN_00cba110();
};
extern int DAT_01268400;
void* __cdecl bhkRagdollTemplateData_GetRTTI();
extern unsigned int DAT_01268418;
void hkMemorySystem_replaceInstance(unsigned int a1);
// FUN_00cbd960 registers the 0x00cbd7a0 comparison helper in the global
// callback slot at 0x01268430, which is later called indirectly with two
// arguments (see the indirect call through 0x01268430).
extern void(__cdecl* DAT_01268430)(void*, void*);
void __cdecl InsertIntoContext(void* pList, void* pContext);
void __cdecl hkpFixedBufferCdPointCollector_registerDefaultAddCdPointFunction(void);
extern int DAT_01268434;
struct PrimaryBase
{
    virtual ~PrimaryBase();
};
struct HolderBase
{
    void Release();
};
struct FUN_00cbd970 : PrimaryBase
{
    int unk04;
    virtual ~FUN_00cbd970();
};
struct WriteStream
{
    void* unk00;
    unsigned int transferred;
    void* unk08;
    int(__cdecl* write)(WriteStream*, const void*, unsigned int, unsigned int*, int);
};
struct BufferOwner
{
    void* unk00;
    unsigned char* buffer;
    void __thiscall hkConstraintCinfo_SaveBinary(void*);
    void __thiscall WriteToStream(void*);
};
extern "C" void _ReadWriteBarrier(void);
extern float DAT_0104da48;
struct FUN_00cbe820_sub
{
    void Init(float* value);
};
struct FUN_00cbe820_cls
{
    short m_00;
    int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c;
    int m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c, m_80, m_84, m_88, m_8c;
    short m_90;
    short m_92;
    short m_94;
    unsigned char m_96;
    FUN_00cbe820_sub m_97;
    float m_98;

    FUN_00cbe820_cls* hkpHingeConstraintData_Atoms_Atoms();
};
struct FUN_00cbe880_Class
{
    int m_iWordAt00;
    void __thiscall UpdateFields_00cbe880();
};
extern "C" void __cdecl FUN_00c9eec0();
unsigned char __stdcall bhkWorldObject_Add(void*);
void* __cdecl PackBytesBigEndian(int, int, int, int);
struct FUN_00c68e30_cls
{
    void __thiscall bhkWorld_SetDebugObjectColor(void* a, void* b);
};
struct FUN_00cbe890_cls
{
    int m_auiShapeKeys[7];
    unsigned char m_1c;
    unsigned char __thiscall bhkCollisionBox_Add(void* a);
};
// Release the per-body lists: destroy every inner array, then free the outer array.
struct CBF490Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
struct CBF490MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CBF490Allocator* m_pStreamAllocator;

    CBF490Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" CBF490MemoryRouter& __cdecl CBF490GetMemoryRouter() throw();
template <class T> inline void CBF490Deallocate(CBF490Allocator& alloc, T* p, int numElem)
{
    alloc.ReturnMemory(p, numElem * sizeof(T));
}
template <class T> __forceinline void CBF490Destruct(T* p, int n)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}
template <class T> struct CBF490Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~CBF490Array() throw()
    {
        CBF490Allocator& alloc = CBF490GetMemoryRouter().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    __forceinline void ClearAndRelease() throw()
    {
        CBF490Allocator& alloc = CBF490GetMemoryRouter().heap();
        CBF490Destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            CBF490Deallocate(alloc, m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
class CBF490Lists
{
  public:
    int unk00;
    int unk04;
    int unk08;
    CBF490Array<CBF490Array<int> > m_kLists;

    void ClearLists();
};
class CBFC60Dispatcher
{
  public:
    void SetEnableChecks(hkBool bEnable);
};
void __cdecl hkpListAgent_registerAgent(CBFC60Dispatcher* pkDispatcher);
void __cdecl hkpCollectionAgent3_registerAgent3(CBFC60Dispatcher* pkDispatcher);
void __cdecl hkpCollectionCollectionAgent3_registerAgent3(CBFC60Dispatcher* pkDispatcher);
void __cdecl RegisterConvexListAgentCollisionFuncs(CBFC60Dispatcher* pkDispatcher);
void __cdecl RegisterAgent3Entries(CBFC60Dispatcher* pkDispatcher);
void __cdecl hkpHeightFieldAgent_registerAgent(CBFC60Dispatcher* pkDispatcher);
void __cdecl hkpAgentRegisterUtil__registerListAgents(CBFC60Dispatcher* pkDispatcher);
struct TypedObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetKind();
};
struct PropHolder
{
    int unk00;
    int unk04;
    int unk08;
    TypedObj* pObj;
};
struct PassEntry
{
    PropHolder* pHolder;
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
};
struct ShaderData
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
    PassEntry* pPasses;
    unsigned short usPassCount;
    unsigned short unkb2;
    PropHolder** ppExtra;
    int iExtraCount;
};
struct ShaderProp
{
    int unk00;
    int unk04;
    ShaderData* pData;
};
struct CastResult
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ShaderProp* pShader;
};
struct RttiObject
{
    CastResult* DynamicCast(const void* type);
};
extern const int g_kShaderRtti;
struct GeomNode;
struct ChildNode
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
    GeomNode** ppChildren;
    unsigned short unka4;
    unsigned short usChildCount;
};
struct GeomNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ChildNode* GetAsNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    RttiObject* pProp;
};
struct GeomArray
{
    virtual void v00();
    virtual GeomNode** Allocate(unsigned int count);
    GeomNode** pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    void Grow(unsigned int newCap, unsigned int size);

    __forceinline void Add(GeomNode* p)
    {
        if (uiSize == uiCapacity)
        {
            if (uiCapacity == 0)
            {
                pData = Allocate(4);
                uiCapacity = 4;
            }
            else
            {
                unsigned int newCap = uiCapacity > 0x400 ? uiCapacity + 0x400 : uiCapacity * 2;
                Grow(newCap, uiSize);
                uiCapacity = newCap;
            }
        }
        pData[++uiSize - 1] = p;
    }
};
struct GeomCollector
{
    void CollectShaderNodes(GeomNode* pObj, GeomArray* pArray);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class PrimaryCA3
{
  public:
    virtual ~PrimaryCA3()
    {}

    int unk04, unk08, unk0C;
};
class SecondaryCA3
{
  public:
    virtual ~SecondaryCA3()
    {}
};
class BaseCA3 : public PrimaryCA3, public SecondaryCA3
{
  public:
    virtual ~BaseCA3()
    {}

    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    int unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70;
    int unk74, unk78, unk7C, unk80;
};
class FUN_00ca3b90 : public BaseCA3
{
  public:
    virtual ~FUN_00ca3b90();

    NiPointer<NiRefObject> m_pReferencedObject;
};
// The pack prelude keeps only the declaration of this file-static helper (used by a
// neighbouring function's function-pointer table); provide its body so the unit links.
void* NiMalloc(unsigned int size);
void NiFree(void* p);
struct PtrEntry
{
    NiPointer<NiRefObject> m_pReferencedObject;
    int m_iValue;
    PtrEntry() : m_pReferencedObject(0), m_iValue(0)
    {}
    bool operator==(const PtrEntry& other) const
    {
        return m_pReferencedObject == other.m_pReferencedObject && m_iValue == other.m_iValue;
    }
    bool operator!=(const PtrEntry& other) const
    {
        return !(*this == other);
    }
};
struct PtrEntryArray
{
    virtual ~PtrEntryArray();
    PtrEntry* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void Resize(unsigned int uiMaxSize);
};
// Prelude helper whose body the unit prelude omits.
// Create a counted shape wrapper under the Havok allocation tag and the world lock, then register it with this owner.
extern __declspec(thread) int g_iCA56B0AllocTag;
struct CA56B0AllocTagScope
{
    int m_iSaved;

    CA56B0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA56B0AllocTag;
        g_iCA56B0AllocTag = aiAllocationTag;
    }
    ~CA56B0AllocTagScope()
    {
        g_iCA56B0AllocTag = m_iSaved;
    }
};
void CA56B0Lock();
void CA56B0Unlock();
class CA56B0RefObject
{
  public:
    CA56B0RefObject();
    virtual ~CA56B0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};
class CA56B0Shape : public CA56B0RefObject
{
  public:
    CA56B0Shape() : m_pUserData(0), m_pkExtra(0)
    {
        ++ms_iCount;
    }
    virtual ~CA56B0Shape();

    void* m_pUserData;
    void* m_pkExtra;

    static int ms_iCount;
};
class CA56B0MidShape : public CA56B0Shape
{
  public:
    CA56B0MidShape()
    {
        ++ms_iCount;
    }
    virtual ~CA56B0MidShape();

    static int ms_iCount;
};
class CA56B0ListShape : public CA56B0MidShape
{
  public:
    CA56B0ListShape()
    {
        ++ms_iCount;
    }
    virtual ~CA56B0ListShape();

    static int ms_iCount;
};
class CA56B0Owner
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual void UnkB4();
    virtual void UnkB8();
    virtual void UnkBC();
    virtual void UnkC0();
    virtual void AddShape(CA56B0Shape* pkShape, int iIndex);

    CA56B0Shape* CreateListShape(int iIndex);
};
struct ReadBin
{
    int unk00;
    unsigned int position;
    unsigned int(__cdecl* read)(ReadBin*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes, unsigned int* sizes, unsigned int n)
    {
        position += read(this, data, bytes, sizes, n);
    }
};
template <class T> inline void Load(ReadBin& bin, T* data, unsigned int n)
{
    unsigned int size = sizeof(T);
    bin.Read(data, n * sizeof(T), &size, 1);
}
struct ReadStream
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
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    ReadBin* binary;
    void ReadLinkID();
};
struct ReadData
{
    int unk00, unk04;
    int value08;
    int unk0c;
    float vector10[4];
};
struct CA5940
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual ReadData* GetData(char* out);
    void bhkShape_LoadBinary(ReadStream* stream);
    void ReadDataFromStream(ReadStream* stream);
};
extern __declspec(thread) int g_CA6E60AllocTag;
struct CA6E60AllocTagScope
{
    int m_iSaved;

    CA6E60AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CA6E60AllocTag;
        g_CA6E60AllocTag = aiAllocationTag;
    }
    ~CA6E60AllocTagScope()
    {
        g_CA6E60AllocTag = m_iSaved;
    }
};
class CA6E60Buffer
{
  public:
    virtual ~CA6E60Buffer()
    {
        NiFreeAlias(m_pResource);
    }

    void* m_pResource;
};
class CA6E60Data
{
  public:
    static void operator delete(void* pvMem)
    {
        unsigned char ucOffset = static_cast<unsigned char*>(pvMem)[-1];
        _g_memoryManager.Deallocate(static_cast<char*>(pvMem) - ucOffset);
    }

    int unk00;
    int unk04;
    CA6E60Buffer m_kBuffer;
};
class CA6E60Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    CA6E60Data* m_pUserData;

    void ReleaseData(bool bRelease);
};
extern char* DAT_012682e8;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);
char* __cdecl NiGetViewerString_00a7d510(const char*, unsigned int);
char* __cdecl NiGetViewerString_00a7d4d0(const char*, int);
struct PartFlags
{
    void* vtable;
    int references;
    int unk08;
    unsigned short flags;
};
struct PartValue
{
    int value;
    void AppendToViewerStrings(StrArr* output);
};
struct DiagnosticShape : S_00ca6810_Class
{
    void bhkShapeCollection_GetViewerStrings(StrArr* output);
    void AppendSubpartDiagnostics(StrArr* output);
    unsigned int Count() const
    {
        return this && unk08 ? (unsigned int)unk08->unkA0 : 0;
    }
    S_00ca6810_Entry& Part(unsigned int index) const
    {
        if (this && unk08)
            return unk08->unk98[index];
        return *reinterpret_cast<S_00ca6810_Entry*>(&DAT_012682f0);
    }
};
struct LockFlag_t
{
    bool m_kPointB;
    LockFlag_t(bool b) : m_kPointB(b)
    {}
    LockFlag_t(const LockFlag_t& o) : m_kPointB(o.m_kPointB)
    {}
};
struct WorldLock_t
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Mark(unsigned int id, LockFlag_t flag);
};
extern WorldLock_t* g_pWorldLock_01268360;
struct CAC300Allocator
{
    virtual void fn00();
    virtual void* Alloc(unsigned int size);
};
struct CAC300Owner
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
    virtual void SetObject(hkReferencedObject* obj);
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
    virtual void Apply(int arg);

    void bhkCharacterProxy_Init(int arg);
};
// Prelude helper whose body the unit prelude omits.
// Factory: create a new 0x40-byte object.
class BA2D0Object
{
  public:
    BA2D0Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

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
};
BA2D0Object* CreateBA2D0Object();
// Prelude helper whose body the unit prelude omits.
// NiTMap destructor: remove all entries, then the base map frees its hash table.
void __cdecl CBC740NiFree(void* pvMem);
class CBC740MapBase
{
  public:
    virtual ~CBC740MapBase()
    {
        RemoveAll();
        CBC740NiFree(m_ppkHashTable);
    }
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00cbc740 : public CBC740MapBase
{
  public:
    virtual ~FUN_00cbc740();
};
extern __declspec(thread) int g_iCBEA40AllocTag;
struct BCBEA40AllocTagScope
{
    int m_iSaved;

    BCBEA40AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCBEA40AllocTag;
        g_iCBEA40AllocTag = aiAllocationTag;
    }
    ~BCBEA40AllocTagScope()
    {
        g_iCBEA40AllocTag = m_iSaved;
    }
};
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

typedef NiTArray<char*, NiTMallocInterface<char*> > BCBEA40StringArray;
extern const char* g_pcCBEA40Name;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
class BCBEA40Owner
{
  public:
    void bhkSimpleShapePhantom_GetViewerStrings(BCBEA40StringArray* pkArray);
    void AddNameToArray(BCBEA40StringArray* pkArray);
};
// Registers a batch of classes with the registry while it is temporarily locked.
class CBFC10Bool
{
  public:
    CBFC10Bool(bool b)
    {
        m_cBool = (char)b;
    }
    char m_cBool;
};
class CBFC10Registry
{
  public:
    void Set(CBFC10Bool bLocked);
};
void __cdecl CBFC10RegisterA(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterB(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterC(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterD(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterE(CBFC10Registry* pkRegistry);
void __cdecl RegisterAll(CBFC10Registry* pkRegistry);
extern unsigned int DAT_011b1730;
extern unsigned int DAT_011b1734;
struct FUN_00ca3dc0_cls
{
    int unk00;
    int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned short m_10;
    unsigned short unk12;
    void* m_14;
    void* m_18;
    int unk1C;
    void* m_20;
    void* m_24;
    void __thiscall hkPackedNiTriStripsData_SaveBinary(S_00ca59d0_Stream* s);
};
struct SArr046
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int size);
    void FUN_0096ae90(unsigned int index, char*& value);
    void AppendReference(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        FUN_0096ae90(index, value);
    }
    __forceinline void Append(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
        {
            m_usESize += (unsigned short)-1;
        }
        m_pBase[index] = value;
    }
};
struct InnerEntry046
{
    void* f0;
    int f4;
    void* f8;
};
struct Inner046
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short m_uiItemCount;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    InnerEntry046* m_entries;
};
struct SubObj046
{
    int unk00[0x21];
    Inner046* m_84;
};
struct NodePtr046
{
    void* m_p;
    void AppendToViewerStrings(SArr046* arr);
};
extern int DAT_012682dc;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char* a);
char* __cdecl NiGetViewerString_00a7d510(const char* s, unsigned int n);
char* __cdecl NiGetViewerString_00a7d4d0(const char* s, int n);
struct ThisCls046
{
    int unk00;
    int unk04;
    SubObj046* m_8;
    void bhkShapeCollection_GetViewerStrings(SArr046* arr);
    void AppendSubpartNames(SArr046* arr);
};
extern int DAT_01268340;
class FUN_00cabf50 : public bhkSerializable
{
  public:
    virtual ~FUN_00cabf50();
    int m_0c;
    bhkCharacterPointCollector m_kCollector;
    void bhkSerializable_Kill();
};
struct LinkedObject
{
    int unk00[2];
    int m_iValue;  // +0x08
};
struct LinkStream
{
    LinkedObject* FUN_00a63430();
};
class LinkBase
{
  public:
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
    virtual LandTextureParameters* GetHavokData(char& rcFlag);  // +0xb4
    void bhkSerializable_LinkObject(LinkStream& kStream);                     // base LinkObject
};
class LinkWrapper : public LinkBase
{
  public:
    void CopyHavokValueFromStream(LinkStream& kStream);
};
struct FUN_00cb9d80_child
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(void* context);
};
typedef int(__cdecl* FUN_00cb9d80_read_fn)(void* stream, void* data, unsigned int size, void* result, int flag);
struct FUN_00cb9d80_stream
{
    int unk00;
    int position;
    int unk08;
    FUN_00cb9d80_read_fn read;
};
struct FUN_00a641f0_class
{
    void __thiscall WriteObjectLink(void* object);
};
void __stdcall nullsub_3(void* context);
struct FUN_00cb9d80_class
{
    int unk00;
    int unk04;
    int* unk08;
    int unk0c;
    FUN_00cb9d80_child** unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int* unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;

    void __thiscall ReadFromStream(void* context);
};
extern int DAT_0108ff98;
extern int DAT_010c5dc0;
struct Cinfo_13 : public BaseCinfo_blk_00ca0000_o2_gs_ehsc_nogs_noehsc_variant
{
    __forceinline Cinfo_13()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_0 : public BaseCinfo_blk_00ca0000_o2_gs_ehsc_nogs_noehsc_variant
{
    __forceinline Cinfo_0()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_1 : public BaseCinfo_blk_00ca0000_o2_gs_ehsc_nogs_noehsc_variant
{
    __forceinline Cinfo_1()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_2 : public BaseCinfo_blk_00ca0000_o2_gs_ehsc_nogs_noehsc_variant
{
    __forceinline Cinfo_2()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_7 : public BaseCinfo_blk_00ca0000_o2_gs_ehsc_nogs_noehsc_variant
{
    __forceinline Cinfo_7()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct RagdollBase
{
    virtual ~RagdollBase();
    void ReadGroup(NiStream& kStream);
};
struct FUN_00ca0ca0_Class
{
    void* m_vtbl;
    FUN_00ca0ca0_Class* __thiscall FUN_00ca0ca0(int flags);
};
struct MemMgr_00aa4060
{
    void __thiscall MemoryManager_Deallocate(FUN_00ca0ca0_Class* p);
};
extern int DAT_010c7304;
struct WalkPlacement
{
};
inline void* operator new(unsigned int, WalkPlacement, void* p)
{
    return p;
}
struct WalkRTTI
{
    const char* name;
    WalkRTTI* parent;
};
extern WalkRTTI DAT_01267b70, DAT_0126817c;
extern int DAT_0126818c;
struct WalkObject
{
    virtual void v0();
    virtual void v4();
    virtual WalkRTTI* GetRTTI();
    int ref;
    struct WalkBody* body;
    struct WalkType* fallback;
    WalkObject* FUN_00653290(const WalkRTTI*);
    __forceinline WalkObject* AsItem()
    {
        if (!this)
            return 0;
        return IsKind(&DAT_0126818c) ? this : 0;
    }
    bool IsKind(const void* type)
    {
        for (WalkRTTI* r = GetRTTI(); r; r = r->parent)
            if (r == type)
                return true;
        return false;
    }
};
inline WalkObject* KindCast(WalkObject* item)
{
    if (!item)
        return 0;
    return item->IsKind(&DAT_0126818c) ? item : 0;
}
struct WalkType
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};
struct WalkBody
{
    int unk, unkCur, unkValue;
    WalkType* type;
};
struct WalkLink
{
    WalkObject* item;
    WalkLink* next;
    WalkObject* GetItem()
    {
        return item;
    }
    WalkLink* Next()
    {
        return next;
    }
};
struct WalkLeaf
{
    int unk, unkCur;
    void* object;
    int unk0c, uNewnk;
    WalkLink links;
};
class NiAVObject;
class NiRTTI;
class GarbageCollectorObjectPtr
{
  public:
    WalkObject* object;
    int high;
};
GarbageCollectorObjectPtr* __cdecl bhkWorldObject_GetProperty(GarbageCollectorObjectPtr*, NiAVObject*, const NiRTTI*);
struct WalkAlloc
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void Free(void*, int) throw();
};
struct WalkRouter
{
    int unk, unkCur, unkValue, unk0c;
    WalkAlloc* heap;
    WalkAlloc& Heap()
    {
        return *heap;
    }
};
void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> __forceinline void WalkDestruct(T* ptr, int count)
{
    for (int i = 0; i < count; ++i)
        ptr[i].~T();
}
template <class T> inline void WalkDeallocate(WalkAlloc& alloc, T* ptr, int count)
{
    alloc.Free(ptr, count * int(sizeof(T)));
}
struct WalkArray
{
    void** data;
    int size;
    int capacity;
    WalkArray() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ~WalkArray()
    {
        WalkAlloc& alloc = ((WalkRouter*)hkMemoryRouter_getInstance())->Heap();
        ClearAndRelease(alloc);
    }
    void ClearAndRelease(WalkAlloc& alloc)
    {
        WalkDestruct(data, size);
        size = 0;
        if ((capacity & 0x80000000) == 0)
            WalkDeallocate(alloc, data, capacity & 0x3fffffff);
        data = 0;
        capacity = 0x80000000;
    }

    __forceinline void Add(void* const& value)
    {
        FNVTaskAllocator* alloc = hkMemoryRouter_getInstance()->allocator;
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(alloc, this, 4);
        *new (WalkPlacement(), &data[size]) void* = value;
        ++size;
    }
};
inline WalkObject* GetRoot(void* obj)
{
    GarbageCollectorObjectPtr temp;
    return bhkWorldObject_GetProperty(&temp, (NiAVObject*)obj, (const NiRTTI*)&DAT_01267b70)->object;
}
void __stdcall CollectLeafObjects(WalkLeaf* leaf, WalkArray* outObjects, WalkArray* outBodies);
struct TlsBlock_ca57
{
    unsigned int m_2b4;
};
extern __declspec(thread) TlsBlock_ca57 g_tls;
struct TlsFlagGuard_ca57
{
    unsigned int m_saved;
    TlsFlagGuard_ca57()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 16;
    }
    ~TlsFlagGuard_ca57()
    {
        g_tls.m_2b4 = m_saved;
    }
};
class Pool_ca57
{
  public:
    void* __thiscall Game_DoHeapAlloc(unsigned int);
};
class Node_ca57
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    Node_ca57();
    static void operator delete(void*) throw()
    {}
    void* operator new(unsigned int size) throw()
    {
        unsigned char* raw = (unsigned char*)((Pool_ca57*)&DAT_011f6238)->Game_DoHeapAlloc(size);
        unsigned char lo = (unsigned char)raw;
        lo &= 0x0f;
        unsigned char pad = 0x10;
        pad -= lo;
        raw += pad;
        raw[-1] = pad;
        return raw;
    }
};
class Owner_ca57
{
  public:
    unsigned int unk00, unk04, m_08;
    unsigned int* m_0c;
    void bhkPackedNiTriStripsShape_CopyCinfo(unsigned int*);
    unsigned int* GetOrCreateNode(bool*);
};
int __cdecl bhkShape_CanShare(int param_1);
int __cdecl bhkExtendedMeshShape_CanShare(int param_1);
struct FNVHeapAllocator : FNVTaskAllocator
{
    template <typename T> void _bufFree(void* p, int numElem)
    {
        Free(p, numElem * sizeof(T));
    }
};
struct FNVHeapRouter : FNVTaskMemoryRouter
{
    FNVHeapAllocator& heap()
    {
        return *(FNVHeapAllocator*)allocator;
    }
};
template <typename T> struct FNVArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(FNVHeapAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~FNVArray()
    {
        _clearAndDeallocate(((FNVHeapRouter*)hkMemoryRouter_getInstance())->heap());
    }
};
struct FUN_00ca73c0
{
    int unk00[9];
    FNVArray<int> unk24;
    FNVArray<int> unk30;
    FNVArray<int> unk3C;
    FNVArray<int> unk48;
    FNVArray<char> unk54;
    FNVArray<int> unk60;
    FNVArray<int> unk6C;
    FNVArray<int> unk78;
    FNVArray<int> unk84;
    FNVArray<int> unk90;
    FNVArray<int> unk9C;
    FNVArray<int> unkA8;
    ~FUN_00ca73c0();
};
struct PositionCommand
{
    unsigned char opcode;
    void* sender;
    float x;
    float y;
    float z;
};
struct PositionQueue
{
    void hkpWorld_queueOperation(PositionCommand* command);
};
struct PositionOwner
{
    int unk00;
    int unk04;
    PositionQueue* queue;

    void OnTrigger(float* position);
    void SendPositionCommand(float* position);
};
void __cdecl bhkConstraint_LoadBinary();
void __cdecl bhkBallAndSocketConstraint_LoadBinary();
char Runtime_ReturnConstant_0xff();
unsigned int __cdecl PackColorBigEndian(float, float, float, float);
struct RNG_cabbd0
{
    int unk00;
    unsigned int m_uiState;

    unsigned int Next()
    {
        m_uiState = m_uiState * 1664525 + 1013904223;
        return m_uiState;
    }
};
unsigned int __cdecl hkColor_getRandomColor(RNG_cabbd0* rng);
extern int DAT_011b1a58[8];
extern char DAT_00ffffff;
int __cdecl CombineIndexedMaskAndShift(int a, int b);
struct SomeClass
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
};
int* __fastcall ahkpCharacterProxy_GetCdPoints(SomeClass* pThis);
struct FnvCpu_FUN_00cac950_CpuObject
{
    char* hkpCharacterProxy_getLinearVelocity();
};
struct FUN_00CAFEC0_This
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
    void** unk60;
    int unk64;
    float unk68;
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
};
struct FUN_00CAFEC0_Class
{
    float __thiscall GetTableValue(int param_2, int param_3);
};
struct FUN_00cb0a70_Class
{
    void* ReturnSelf(int a);
};
int __cdecl FUN_00ec6cc4(char*, const char*, char*);
void __cdecl hkString_sprintf(char* a, const char* b, char* c);
extern "C" int __cdecl FUN_00ec8a19(const char*, const char*, unsigned int);
int __cdecl j_strncmp(const char* s1, const char* s2, unsigned int count);
void __stdcall isOk_00cd4af0(int a1);
unsigned int __stdcall hkRotation_isOk(unsigned int param_1);
void __cdecl bhkPCollisionObject_LoadBinary(void);
void __cdecl bhkSPCollisionObject_LoadBinary(void);
void __cdecl bhkPCollisionObject_LinkObject();
void __cdecl bhkSPCollisionObject_LinkObject();
void __cdecl bhkCollisionObject_RegisterStreamables();
void __cdecl bhkBlendCollisionObject_RegisterStreamables();
bool __cdecl bhkCollisionObject_IsEqual(int param_1, int param_2);
bool __cdecl bhkSPCollisionObject_IsEqual(int param_1, int param_2);
extern int DAT_012683e8;
struct FUN_00c86720
{
    virtual ~FUN_00c86720();
};
struct FUN_00cb83f0 : FUN_00c86720
{
    void bhkSerializable_Kill();
    virtual ~FUN_00cb83f0();
};
struct CpuOpaque;
extern CpuOpaque DAT_012683ec;
CpuOpaque* __cdecl bhkOrientHingedBodyAction_GetRTTI();
void __cdecl bhkUnaryAction_CopyMembers();
void __cdecl bhkOrientHingedBodyAction_CopyMembers();
extern "C" void __cdecl FUN_00aa1460(void* self, int size);
struct FUN_00cb8480_class
{
    void FUN_00cb83f0();
    FUN_00cb8480_class* FUN_00cb8480(char flag);
};
struct FUN_00d2acf0
{
    void* vtable;
    unsigned short memorySizeAndFlags;
    unsigned short referenceCount;
    unsigned int unk08, unk0C, unk10, unk14;
    unsigned int unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34;
    unsigned int unk38, unk3C, unk40, unk44;
    unsigned int unk48, unk4C, unk50, unk54;
    unsigned int unk58, unk5C;

    FUN_00d2acf0(void* source, void* start, void* end, float nearValue, float farValue, int flags);
    void FUN_00c905b0();

    static void* operator new(unsigned int bytes)
    {
        FNVTaskMemoryRouter* router = hkMemoryRouter_getInstance();
        FUN_00d2acf0* object = (FUN_00d2acf0*)((CAC300Allocator*)router->allocator)->Alloc(bytes);
        object->memorySizeAndFlags = (unsigned short)bytes;
        return object;
    }
    static void operator delete(void* object);
};
struct FUN_00cb88d0_owner : CAC300Owner
{
    void __thiscall CreateShapeAndApply(void* parameters);
};
extern GlobalObjectO2_00a7b610 g_012683ec;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(GlobalObjectO2_00a7b610* p);
struct FUN_00cb89c0_cls
{
    void bhkUnaryAction_GetViewerStrings(SArr046* arr);
    void AppendGlobalReference(SArr046* arr);
};
struct CpuOpaque;
extern CpuOpaque DAT_012683f4;
CpuOpaque* __cdecl bhkForceController_GetRTTI();
void __cdecl FUN_00a7b3d0();
void __cdecl bhkExtraData_IsEqual();
class CBADDynamicArray : public CA0E60Array
{
  public:
    void Runtime_ProcessEntries_00cb9d50(void** elements, unsigned int count);
    void ReleaseItems(void** elements, unsigned int count);
    void BSSimpleArray_NiPointer_bhkRagdollTemplateData_1024_SetSize(unsigned int requestedSize, bool compact);
};
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_01268408;
GlobalObjectO2_00a7b610* __cdecl bhkRagdollTemplate_GetRTTI();
struct FUN_00cbaf90_Obj
{
    void FUN_00cbaf90();
};
void __cdecl FUN_00aa1460(void* p, unsigned int size);
struct FUN_00cbb130_Class : FUN_00cbaf90_Obj
{
    unsigned int __thiscall FUN_00cbb130(unsigned char flag);
};
extern int DAT_010c9194;
struct FUN_00cbc460
{
    void* m_ppVirtualMethodTable;
    unsigned short m_04;
    unsigned short m_w06;
    // volatile keeps the vptr store ahead of the zero stores, as in the original
    void* volatile m_p08;
    void* volatile m_p0c;
    void* volatile m_p10;
    void* volatile m_p14;
    void* volatile m_p18;
    void* volatile m_p1c;
    void* volatile m_p20;
    void* volatile m_p24;
    void* volatile m_p28;
    void* volatile m_p2c;
    void* volatile m_p30;
    FUN_00cbc460();
};
void __cdecl ClearLists();
void __cdecl Runtime_ClearLists_Thunk();
struct HeapAllocator
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern HeapAllocator g_heapAllocator;
struct RefStub
{
    void IncRefCount();
    void DecRefCount();
};
struct RefHolder
{
    RefStub* object;
    RefHolder()
    {}
    ~RefHolder()
    {
        if (object)
            object->DecRefCount();
    }
};
struct ThreadLocalData
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
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int heapIndex;
};
extern __declspec(thread) ThreadLocalData g_threadLocalData;
struct HeapIndexGuard
{
    int saved;
    HeapIndexGuard(int index)
    {
        saved = g_threadLocalData.heapIndex;
        g_threadLocalData.heapIndex = index;
    }
    ~HeapIndexGuard()
    {
        g_threadLocalData.heapIndex = saved;
    }
};
extern int DAT_010c7600;
struct ShapePrefix
{
    int unk00;
    float unk04;
    ShapePrefix() : unk00(0), unk04(0.0f)
    {}
};
struct ShapeStrips
{
    void* vtbl;
    void* pBase;
    unsigned int maxSize;
    unsigned int size;
    unsigned int eSize;
    unsigned int growBy;

    ShapeStrips(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        maxSize = uiMaxSize;
        growBy = uiGrowBy;
        size = 0;
        eSize = 0;
        if (uiMaxSize > 0)
            pBase = g_heapAllocator.Allocate(uiMaxSize);
        else
            pBase = 0;
        vtbl = &DAT_010c7600;
    }
};
struct ShapeVector
{
    float x;
    float y;
    float z;
    float w;
    ShapeVector()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
};
struct ShapeData : ShapePrefix
{
    ShapeStrips strips;
    ShapeVector scale;

    static void* operator new(unsigned int size)
    {
        char* p = (char*)g_heapAllocator.Allocate(size + 16);
        unsigned char off = (unsigned char)(16 - ((unsigned char)(unsigned int)p & 15));
        p += off;
        p[-1] = off;
        return p;
    }
    static void operator delete(void* p)
    {
        if (p)
        {
            unsigned char off = ((unsigned char*)p)[-1];
            g_heapAllocator.Deallocate((char*)p - off);
        }
    }

    ShapeData()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
    void SetScale()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
};
struct ShapeOwnerTarget
{
    void CopyEntriesToArg(ShapeData* data);
};
struct MyObj
{
    int unk00;
    int unk04;
    ShapeOwnerTarget* unk08;
    ShapeData* unk0c;

    void bhkShape_CopyCinfo(ShapeData* data);
    ShapeData* GetOrCreateShapeData(bool* created);
};
struct FNV_InnerObject
{
    virtual void __fastcall Call0(int);
    virtual void __fastcall Call1(int);
    virtual void __fastcall Call2(int);
    virtual void __fastcall Call3(int);
    virtual void __fastcall Call4(int);
    virtual void __fastcall Call5(int);
    virtual void __fastcall Call6(int);
    virtual void __fastcall Call7(int);
    virtual void __fastcall Call8(int);
};
struct FNV_OwnerObject
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
    FNV_InnerObject inner;
    void __fastcall hkpRigidBody_setInertiaInvLocal(int);
};
struct CA8B80Command;
struct CA8B80Queue
{
    void __thiscall Push(CA8B80Command*);
};
struct FUN_00ca8a30_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    CA8B80Queue* m_8;
    void __thiscall PushCommand(NiPoint3*);
    void __thiscall hkpRigidBody_setAngularVelocity(NiPoint3*);
};
struct FUN_00ca8a30_Local
{
    unsigned char m_kPointB;
    FUN_00ca8a30_Class* m_p;
    float m_uiX;
    float m_uiY;
    float m_uiZ;
};
extern int DAT_0108febc;
extern int DAT_010c81ac;
extern int DAT_01268188;
extern int DAT_0126830c;
extern __declspec(thread) int tls_memContext;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
void __cdecl _delete(void* p, int size);
struct ScopedMemContext_ca9e60
{
    int m_iOld;
    ScopedMemContext_ca9e60(int context)
    {
        m_iOld = tls_memContext;
        tls_memContext = context;
    }
    ~ScopedMemContext_ca9e60()
    {
        tls_memContext = m_iOld;
    }
};
struct Holder_ca9e60
{
    void* p;
    Holder_ca9e60(void* q) : p(q)
    {}
    ~Holder_ca9e60()
    {
        if (p)
            _delete(p, 0x10);
    }
};
struct Host_ca9e60
{
    void* __thiscall bhkMalleableConstraint_Clone(void* arg);
    void __thiscall bhkConstraint_CopyMembers(void* a, void* b);
};
void __cdecl DispatchToTarget();
void __cdecl bhkHingeLimitsConstraint_SetEntityB();
extern int DAT_01268334;
extern int DAT_01268338;
extern int DAT_0126833c;
unsigned int __cdecl hkColor_getRandomColor(int*);
unsigned int __cdecl hkColor_getRandomColor_00cabe90();
struct CA0F0Result
{
    int unk00;
    int unk04;
    int m_8;
};
struct CA0F0Object : BaseThunk
{
    int __thiscall GetResultValue();
};
struct RefCountedCAC4B0
{
    int unk00;
    long m_iRefCount;
};
struct ShapeHolderCAC4B0
{
    int unk00;
    int unk04;
    int unk08;
    RefCountedCAC4B0* m_pkShape;
};
struct WorldObjectCAC4B0
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
    void* m_pkUserData;
    ShapeHolderCAC4B0* hkpCharacterProxy_getShapePhantom();
};
void __cdecl bhkCharacterProxy_RembhkRefs();
struct RefObjectCAC4B0
{
    void UpdateReference(bool bAdd);
    int unk00;
    int unk04;
    WorldObjectCAC4B0* m_pkHavokObject;
    WorldObjectCAC4B0* GetHavokObject()
    {
        return this ? m_pkHavokObject : 0;
    }
};
struct ShapeRefCAC4B0 : public RefObjectCAC4B0
{
    void bhkCharacterProxy_Link(bool bAdd);
};
class BufferOwnerC5E0
{
  public:
    void FreeBuffer(bool bFree);

    int unk00;
    int unk04;
    int unk08;
    void* pvContextData;
};
extern "C" int DAT_0126834c;
struct CAFBase
{
    virtual ~CAFBase();
};
struct FUN_00caff80 : CAFBase
{
    virtual ~FUN_00caff80();
    void bhkSerializable_Kill();
};
// FUN_00cb0aa0: allocator-backed string dup. Takes the source string in the
// caller's edi (private convention derived for this static noinline helper):
// length via FUN_00cb10d0 (+1 for the NUL), block allocated through the task
// memory router's allocator, contents filled by FUN_00cb1090.
struct FNVTaskMemoryRouter;
extern "C" int __cdecl hkString_strLen(int);
extern "C" FNVTaskMemoryRouter* __cdecl hkMemoryRouter_getInstance();
extern "C" void* __cdecl AllocateWithHeader(void* allocator, unsigned int count);
extern "C" void __cdecl hkString_strCpy(void* block, int value);
struct CbobRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* allocator;
};
static void* strDup(char* s);
void zz_probe_call(char* s);
struct Cb1b80Arr
{
    int* m_data;
    int m_flags;
    int m_uiItemCount;
    Cb1b80Arr* hkMultiMap_unsigned_int64_unsigned_int64_struct_hkMultiMapOperations_unsigned_int64_struct_hkContainerHeapAllocator_hkMultiMap_unsigned_int64_unsigned_int64_struct_hkMultiMapOperations_unsigned_int64_struct_hkContainerHeapAllocator(void* data, unsigned int size);
};
void __cdecl bhkCollisionObject_SaveBinary(void);
void __cdecl bhkSPCollisionObject_SaveBinary(void);
extern int DAT_0102009c;
extern int DAT_0102016c;
extern int DAT_010c8914;
extern int DAT_01268118;
extern int DAT_01268154;
struct S00cb84f0_Obj : FUN_00c87c30
{
    int unk0c;
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    S00cb84f0_Obj()
    {
        *(void**)this = (void*)&DAT_0102016c;
        unk0c = 0;
        DAT_01268154 += 1;
        *(void**)this = (void*)&DAT_0102009c;
        DAT_01268118 += 1;
        *(void**)this = (void*)&DAT_010c8914;
    }
};
void* __cdecl bhkOrientHingedBodyAction_CreateObject();
void __cdecl FUN_00a6d290(void);
struct FUN_00aa4060_Class
{
    void __thiscall MemoryManager_Deallocate(void* p);
};
struct FUN_00cb9260_Class
{
    int __thiscall FUN_00cb9260(unsigned char flags);
};
extern "C" void __cdecl CopyMembers_00a7b330();
void __cdecl bhkRagdollTemplate_CopyMembers();
struct FUN_00cbadb0_Dispatch
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
};
struct FUN_00cbadb0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
    virtual ~FUN_00cbadb0_Obj();

    void* m_items;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;

    void ReleaseItems(void* items, unsigned int count);
};
extern int DAT_010c8d28;
struct FUN_00cbaec0_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(void* data);
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiReservedSize;
    void __thiscall ReleaseItems(void* data, unsigned int size);
    FUN_00cbaec0_Obj* __thiscall ReleaseAndDestroy(unsigned char flags);
};
struct ArrayCBAF90
{
    virtual __forceinline ~ArrayCBAF90()
    {
        RemoveAll();
    }
    virtual void v04();
    virtual void Deallocate(void* pvBase);
    void ReleaseItems(void* pvBase, unsigned int ItemUpdateArray);
    __forceinline void RemoveAll()
    {
        if (m_pBase)
        {
            ReleaseItems(m_pBase, m_uiSize);
            Deallocate(m_pBase);
            m_pBase = 0;
            m_uiAllocated = 0;
            m_uiSize = 0;
        }
    }
    void* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiAllocated;
};
struct ObjectCBAF90
{
    virtual ~ObjectCBAF90();
    int unk04;
    int unk08;
};
struct FUN_00cbaf90 : public ObjectCBAF90
{
    virtual ~FUN_00cbaf90();
    ArrayCBAF90 m_kArray;
};
struct CBB050Array
{
    void BSSimpleArray_NiPointer_bhkRagdollTemplateData_1024_SetSize(unsigned int count, bool enabled);
};
struct CBB050Object
{
    int unk00;
    int unk04;
    int unk08;
    CBB050Array array;
    void FUN_00a7b4a0(ReadStream* stream);
    void bhkRagdollTemplate_LoadBinary(ReadStream* stream);
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_011f49e0;
struct FUN_00cbaf20_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    FUN_00cbaf20_class();
    void AssignFixedString(const NiFixedString& name);
};
FUN_00cbaf20_class* CreateNamedObject();
struct FUN_00cbf540_class
{
    void __thiscall CreateObjects(int* a, int b);
};
struct FUN_00cbf6b0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void __thiscall EnsureObjectsCreated(int v);
};
extern int(__stdcall* DAT_00fdf1d0)();
extern int DAT_010c925c;
struct FUN_00cbf6e0_cls
{
    void* m_ppVirtualMethodTable;
    FUN_00cbf6e0_cls* FUN_00cbf6e0(unsigned int flags);
};

#include <xmmintrin.h>
struct VecNode
{
    float unk00;
    float unk04;
    float unk08;
    float copyW;
    float x;
    float y;
    float z;
    float w;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
};

// @fnv 0x00cac890
// src: COMMUNITY 0x00cac890
void __stdcall hkpCharacterProxy_convertFractionToDistance(VecNode* nodes, int count, const __m128* axis)
{
    VecNode* cur = nodes;

    int c = count - 1;
    if (c >= 0)
        do
        {
            float value = cur->w;
            __m128 v = *(__m128 const*)&cur->x;
            float dot;

            cur->copyW = value;

            __m128 prod = _mm_mul_ps(v, *axis);
            __m128 s1 = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
            __m128 s2 = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), s1);
            _mm_store_ss(&dot, s2);

            cur->w = value * -dot;
            cur = (VecNode*)((float*)cur + 28);
        } while (--c >= 0);
}

extern "C" unsigned __int64 __rdtsc(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier();
extern unsigned long DAT_0126835c;
extern char DAT_010c9278;
extern char DAT_010c41f8;
struct S00cbf950_TraceEntry
{
    const char* name;
    unsigned int tick;
    unsigned int unk08;
};
struct S00cbf950_Trace
{
    int unk00;
    S00cbf950_TraceEntry* next;
    int unk08;
    S00cbf950_TraceEntry* end;
    inline void mark(const char* n, volatile unsigned int& t)
    {
        S00cbf950_TraceEntry* e = next;
        if (e < end)
        {
            e->name = n;
            _ReadWriteBarrier();
            t = (unsigned int)__rdtsc();
            e->tick = t;
            next = e + 1;
        }
    }
};
struct S00cbf950_Input
{
    __m128 low, high, extra;
};
struct S00cbf950_Bounds
{
    __m128 low, high;
};
struct S00cbf950_Body
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
    virtual void va();
    virtual void vb();
    virtual void vc();
    virtual void vd();
    virtual void ve();
    virtual void vf();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual unsigned int GetSize();
    virtual void v19();
    virtual void Fill(const S00cbf950_Bounds*, unsigned char*);
};
struct S00cbf950_Target;
struct WorkState
{
    union
    {
        int offset;
        volatile unsigned int beginTick;
    };
    union
    {
        unsigned int size;
        int remaining;
        volatile unsigned int endTick;
    };
    S00cbf950_Target* volatile owner;
};
struct S00cbf950_Target
{
    void hkpWorldRayCaster_castRay(S00cbf950_Body*, const S00cbf950_Input*, int, unsigned char*, int);
    void ProcessEntries_00cbf950(S00cbf950_Body*, const S00cbf950_Input*, int, int, int, int);
};
// @fnv 0x00cbf950
// src: GUESS 0x00cbf950 (confidence: low)
void S00cbf950_Target::ProcessEntries_00cbf950(S00cbf950_Body* body, const S00cbf950_Input* input, int count, int mode, int offset,
                                    int step)
{
    WorkState state;
    state.owner = this;
    ((S00cbf950_Trace*)TlsGetValue(DAT_0126835c))->mark(&DAT_010c9278, state.beginTick);
    S00cbf950_Bounds bounds;
    __m128 v = input[0].low;
    bounds.low = _mm_min_ps(v, input[0].high);
    bounds.high = _mm_max_ps(v, input[0].high);
    const S00cbf950_Input* cur = input + 1;
    for (int i = count - 2; i >= 0; i--)
    {
        bounds.low = _mm_min_ps(_mm_min_ps(bounds.low, cur->high), cur->low);
        bounds.high = _mm_max_ps(_mm_max_ps(bounds.high, cur->high), cur->low);
        cur++;
    }
    state.size = body->GetSize();
    FNVTaskMemoryRouter* arena = hkMemoryRouter_getInstance();
    unsigned char* saved = (unsigned char*)arena->unk00;
    arena->unk00 = saved + ((state.size + 127) & ~127);
    body->Fill(&bounds, saved);
    const S00cbf950_Input* walk = input;
    state.offset = offset;
    for (state.remaining = count - 1; state.remaining >= 0; state.remaining--)
    {
        state.owner->hkpWorldRayCaster_castRay(body, walk, mode, saved, state.offset);
        *(volatile int*)&state.offset += step;
        walk++;
    }
    hkMemoryRouter_getInstance()->unk00 = saved;
    ((S00cbf950_Trace*)TlsGetValue(DAT_0126835c))->mark(&DAT_010c41f8, state.endTick);
}
