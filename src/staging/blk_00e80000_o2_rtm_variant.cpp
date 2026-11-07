// src/staging/blk_00e80000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e80000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00e80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/MemoryManager.h"
#include "../../include/_D3DFORMAT.h"
#include "../../include/_D3DDEVTYPE.h"
#include "../../include/BSFadeNode.h"
#include "../../include/NiAlphaProperty.h"
#include "../../include/NiD3DGeometryGroupManager.h"
#include "../../include/NiD3DShaderProgramCreator.h"
#include "../../include/NiProperty.h"
#include "../../include/NiColor.h"
#include "../../include/NiD3DShaderFactory.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiD3DRenderState.h"
#include "../../include/NiDX9RenderState.h"
#include "../../include/NiTListItem.h"
#include "../../include/NiTPointerList.h"
#include "../../include/NiD3DShaderProgramFactory.h"
#include "../../include/NiDX9IndexBufferManager.h"
#include "../../include/NiDX9VertexBufferManager.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTMapItem.h"
#include "../../include/NiTPointerMap.h"

typedef NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned int,
    NiDX9VertexBufferManager::NiDX9VBInfo*> VertexBufferMapBase;
typedef NiTPointerMap<unsigned int, NiDX9VertexBufferManager::NiDX9VBInfo*> VertexBufferMap;
#include "../../include/NiPoint3.h"
#include "../../include/Vec4.h"
struct FUN_00e891f0_Class {
    void __thiscall NiD3DTextureStageGroup_RemoveAllStageStates();
};
extern "C" void __cdecl operator delete(void* p, unsigned int size);
extern int DAT_010efc34;
void __cdecl FUN_00e68830();
struct FUN_00e8aa40_Class {
    int __thiscall FUN_00e8aa40(bool flag);
};
void __stdcall Runtime_UpdateState_00e8b490(int* paiValues, int iFirst, int iSecond);
void NiD3DShaderProgramFactory__SDMShutdown();
extern "C" void __cdecl FUN_00e93400();
extern MemoryManager g_memoryManager;
extern bool DAT_0126f0d0;
void __cdecl NiVBSet_DetermineUsageAndPool(void* apData);
struct FUN_00e95b80_Class {
    void __thiscall SetVirtualTable_00e95b80();
};
struct FUN_00e97790_Class {
    int __thiscall InitFromSource(int a, int b);
};
int __cdecl NiDX9ShaderConstantManager_Create(int a, int b);
extern "C" void __cdecl NiFreeAlias(void*);
extern int DAT_010f0f7c;
struct FUN_00e98640_Class {
    void __thiscall ReleaseStorage_00e98640();
};
struct FUN_00e81d00_Class {
    char m_auiShapeKeys[0x38];
    void* m_pRenderState;
    void* m_pShaderObject;
    void* m_pD3DDevice;
    void __thiscall NiD3DShaderConstantMap_SetD3DRenderer(void* renderer);
};
void __fastcall ClearFields(void* self);
extern "C" void __cdecl NiMemObject_ReleaseStorage_00aa1490(void*, unsigned int);
struct FUN_00e89560_Class {
    void* m_ptr;
    void* m_obj;
    void __thiscall ReleaseStorage_00e89560();
};
extern int DAT_0126f9a0;
struct P03MM { void* __thiscall Allocate(unsigned int); };
void NiD3DTextureStageGroup_InitializePools();
struct NiConsoleRendererStub {
    void* m_pCurrentRenderState;
    void* m_pD3DDevice;
};
struct FUN_00e89760_Class {
    void __thiscall NiD3DShaderProgram_SetD3DRenderer(NiConsoleRendererStub* renderer);
};
extern int DAT_011f4500;
void __cdecl ReleaseShaderNodes();
extern NiD3DShaderProgramCreator* DAT_0126fa54;
extern const unsigned char DAT_010bc868[];
extern int DAT_010f0af4;
void __cdecl NiD3DShaderProgramCreatorObj__SDMInit();
extern int DAT_010f0e50;
extern int DAT_010f0e70;
extern "C" void __cdecl NiFree(void*);
extern int DAT_010f0eb0;
extern int DAT_010f0ed0;
void __cdecl NiFree(void*);
struct FUN_00e941d0_Node { unsigned int pad[9]; unsigned int count; unsigned int pad2[5]; FUN_00e941d0_Node* next; FUN_00e941d0_Node* prev; };
struct FUN_00e941d0_This { int pad[11]; FUN_00e941d0_Node* head; };
FUN_00e941d0_Node* __fastcall RemoveFirstNodeAtLeast(FUN_00e941d0_This* self, int, unsigned int value);
extern "C" void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00e98610_Node {
    void* m_next;
    void* m_auiShapeKeys;
    void* m_data;
    void* m_pAuxiliaryObject;
    void* m_pad3;
    void* m_pad4;
    void* m_pSecondNode;
};
extern int DAT_0126fa58;
void __cdecl FreeNodeList();
struct FUN_00e89350_Class {
    unsigned char m_00;
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
    unsigned char m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    unsigned char m_a8;
    int m_ac;
    int m_b0;
    unsigned char m_b4;
    FUN_00e89350_Class();
};
extern NiColor DAT_011f4998;
extern NiColor DAT_011f499c;
extern NiColor DAT_011f49a0;
struct FUN_00e93fb0_Class {
    char __thiscall CopyColorIfChanged(FUN_00e93fb0_Class* p);
};
struct FUN_00e8a1f0_Class {
    char __thiscall GetEntryData(int b, int* c, int* d, char* e, char* f);
};
extern int DAT_010f0ac0;
extern NiD3DShaderProgramCreator* DAT_0126fa50;
void __cdecl NiD3DShaderProgramCreatorAsm__SDMInit();
unsigned int __fastcall NiPixelFormat_GetNumComponents(char* self, int);
void __cdecl _NiFree(void* p);
extern int DAT_010efdd8;
extern int DAT_010efdf8;
extern int DAT_010efdd8;
void __cdecl _NiFree(void* p);
void __cdecl _NiFree(void* p);
extern int DAT_010efe54;
extern MemoryManager _g_memoryManager;
extern int DAT_010efe54;
extern int DAT_010efe74;
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void*);
extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00e8f800_Class {
    void* m_vptr;
    char m_auiShapeKeys[4];
    void* m_data;

    void* __thiscall FUN_00e8f800(bool deleting);
};
extern unsigned char DAT_010f02b0[];
extern unsigned char DAT_010f02d0[];
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void* p);
extern int DAT_0126fa04;
void __cdecl NiStaticDataManager_AddLibrary(void*, void*);
void __cdecl NiDX9RendererSDM_Init();
void __cdecl NiDX9RendererSDM_Shutdown();
struct FUN_00e91e30_This {
    void* UpdateState_00e91e30();
};
extern void* DAT_0126fa0c;
struct FUN_00e92080_This {
    virtual void Release(int);
};
void NiD3DShaderFactory__SDMShutdown();
extern int DAT_010f0df0;
extern int DAT_010f0e10;
extern int DAT_010f0e30;
void __cdecl _NiFree(void* p);
struct FUN_00e93400_Class {
    void __thiscall FUN_00e93400();
};
extern int DAT_010f0e90;
void _NiFree(void* p);
struct FUN_00e934d0_Class {
    void FUN_00e934d0();
};
struct FUN_00e935b0_Class {
    char m_auiShapeKeys[0x10];
    bool m_flag;
    void FreeIfFlagged(int* a);
};
extern int DAT_010f0df0;
extern "C" void __cdecl NiFree(void*);
extern int DAT_010f0df0;
extern int DAT_010f0e10;
extern MemoryManager _g_memoryManager;
struct FUN_00e93610_Class {
    void* m_vptr;
    char m_auiShapeKeys[3];
    void* m_data;

    FUN_00e93610_Class* __thiscall FUN_00e93610(int flags);
};
void __cdecl NiFree(void* p);
extern int DAT_010f0e50;
extern MemoryManager g_memoryManager;
struct FUN_00e93670_Class {
    void* m_ppVirtualMethodTable;
    void* m_auiShapeKeys;
    void* m_ptr;
    void* __thiscall FUN_00e93670(int unused);
};
void __cdecl FUN_00e934d0();
struct FUN_00e936f0_Class {
    void __thiscall FUN_00e934d0();
    void* __thiscall FUN_00e936f0(bool b);
};
void __cdecl _NiFree(void* p);
struct Program;
Program* DAT_0126fa10;
void __cdecl RemoveProgramFromMap(Program* program);
struct FUN_00e94070_Class {
    void* m_obj;
    char m_auiShapeKeys[0x48 - 4];
    void* m_ptr;
    void __thiscall ReleaseOwnedObject(FUN_00e94070_Class* p);
};
struct FUN_00e942d0_Class {
    void __thiscall ClearAllData();
};
extern int DAT_0126fa30;
void __stdcall NiVBSet_FreeBlock(void* p);
void __cdecl _NiFree(void* p);
struct FUN_00e94390_Class {
    void* m_vptr;
    void* m_ptr;

    void* __thiscall FUN_00e94390(int flags);
};
extern int DAT_010f0f94;
extern int DAT_010f0fb4;
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void*);
struct FUN_00e94850_Class {
    int* m_ppVirtualMethodTable;
    int m_auiShapeKeys;
    void* m_data;

    int* __thiscall FUN_00e94850(int deleting);
};
extern int DAT_010f10f4;
struct FUN_00e89970_Object {
    virtual void FUN_00e89970_Object_0();
    virtual void FUN_00e89970_Object_1();
    virtual void __stdcall FUN_00e89970_Object_2();
};
struct FUN_00e96c90_Class {
    void* m_ppVirtualMethodTable;
    unsigned char m_auiShapeKeys[0x2c];
    void* m_30;
    void* m_34;
    FUN_00e89970_Object* m_38;

    void __thiscall FUN_00e89970();
    void __thiscall UpdateState_00e96c90();
};
extern "C" void __cdecl operator delete(void* p, unsigned int size);
void __cdecl FUN_00e989c0();
extern int DAT_010f1550;
struct FUN_00e97870_Class {
    void* m_ppVirtualMethodTable;
    FUN_00e97870_Class(unsigned char flag);
};
extern unsigned int DAT_011c1118;
extern int DAT_0126fa58;
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int);
};
void AllocateNodeList();
struct FUN_00e98b10_Class {
    void*** m_ppVirtualMethodTable;
    void* m_data;
    FUN_00e98b10_Class* __thiscall FUN_00e98b10(unsigned char flag);
};
extern void** DAT_010f16dc;
extern MemoryManager _g_memoryManager;
struct SpawnedObject {
    void __thiscall ReleaseResources();
};
struct GlobalHolder {
    void __thiscall MemoryManager_Deallocate(SpawnedObject* p);
};
extern SpawnedObject* DAT_0126f72c;
extern GlobalHolder DAT_011f6238;
void __cdecl ClearSpawnedObject();
struct FUN_00e81b60_Entry {
    unsigned int m_key;
    int m_uiFilterValue;
};
struct FUN_00e81b60_Class {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_uiEdgeIndex[3];
    FUN_00e81b60_Entry* m_entries[3];

    int __thiscall LookupEntry(unsigned int a, unsigned int b, int c, int d);
};
extern int DAT_01101294;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern "C" void __cdecl _NiFreeE81(void* pvMem) throw();
class FUN_00e81c00 : public NiRefObject {
public:
    virtual ~FUN_00e81c00() throw();

    int m_iType;
    NiFixedString m_kControlPoint;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    NiFixedString m_kSecondaryString;
    int unk28;
    int unk2C;
    void* m_pConstantData;
    bool m_bOwnsData;
};
struct ConstantTarget {
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
    virtual bool SetConstant(int reg, const float* data, int count);
};
extern Vec4 DAT_0126f8a0;
extern Vec4 DAT_0126f8b0;
extern Vec4 DAT_0126f900;
int __stdcall SetConstantSum(ConstantTarget* target, int reg, int type1, int type2, int iUnused1, int iUnused2);
struct E87B60AlphaProperty {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short m_uiObjectFlags;
    unsigned char m_ucAlphaThreshold;

    bool GetAlphaBlending() const { return (m_uiObjectFlags & 1) != 0; }
    unsigned int GetSrcBlendMode() const { return (m_uiObjectFlags >> 1) & 0xf; }
    unsigned int GetDestBlendMode() const { return (m_uiObjectFlags >> 5) & 0xf; }
    bool GetAlphaTesting() const { return ((unsigned short)(m_uiObjectFlags >> 9) & 1) != 0; }
    unsigned int GetTestMode() const { return (m_uiObjectFlags >> 10) & 7; }
    unsigned char GetTestRef() const { return m_ucAlphaThreshold; }
};
class FUN_00e87c30_arg
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned char unk18;
};
struct StencilPropStub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short m_flags;
    unsigned int m_ref;
    unsigned int m_uiMask;
};
struct FUN_00e88000_pair {
    int key;
    int val;
};
extern FUN_00e88000_pair DAT_011bfce8;
struct StateDefault {
    int type;
    unsigned int value;
};
struct RenderStateSetting {
    unsigned int unk00;
    unsigned int value;
};
extern unsigned int DAT_011bf558;
extern unsigned int DAT_011bf560;
extern StateDefault DAT_011c04f0[];
extern StateDefault DAT_011c0538[];
extern unsigned short DAT_0126f958[];
extern unsigned short DAT_0126f92c[];
// Decompiled: dispatch a table value to a virtual slot on this.
typedef void (__stdcall *FUN_00e88830_Slot)(void* self, int code, int value);
extern unsigned short DAT_0126f958[];
struct S_00e88930_Item {
    int val;
    int unk04;
};
// 256-byte span of not-yet-identified fields.
struct E88980Block {
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
};
struct E88980SamplerState {
    unsigned int m_uiCurrentValue;
    unsigned int m_uiPrevValue;
};
extern unsigned short g_ausE88980SamplerMapping[];
typedef void (__stdcall *FUN_00e88a20_Slot)(void* self, int code, int value);
char __fastcall NiD3DRenderState_GetForceNormalizeNormals(void* self);
extern unsigned short DAT_0126f92c[];
struct SlotGroup {
    int m_uiItemCount;
    int unk04;
    int m_iSlotIds[5];
    bool m_bSlotEnabled[5];
};
struct LightSlots {
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
    SlotGroup m_groupA;
    SlotGroup m_groupB;
    int m_countC;
    bool m_flagC[5];

    void NiD3DTextureStageGroup_SetSamplerState(int key, int value, bool typeA, bool flag);
};
extern unsigned short DAT_0126f948[8];
struct SlotDispatcher
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
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual int v30(int a, unsigned short b, int c, int d);
};
extern SlotDispatcher* DAT_0126f99c;
struct FUN_00e89250_cls
{
    int unk00[3];
    int m_0c[8];
    unsigned char m_2c[8];
    int unk34[2];
    int m_3c[8];
    unsigned char m_5c[8];
    int DispatchSlots(int param);
};
struct FUN_00e89410_Class
{
    void* __thiscall DispatchSlots(unsigned int index);
    void* __thiscall NiD3DTextureStageGroup_SetAllStageSamplers(unsigned int index);
    void* __thiscall GetItemByIndex(unsigned int index);
};
extern unsigned int DAT_011bf558;
struct ScalarDeletingObject {
    void ReleaseStorage_00e89560();
    void* DestroyScalarObject(unsigned char flags);
};
extern "C" void __cdecl _NiFree_00aa10f0(void*);
extern int DAT_010ef73c;
extern int DAT_0101dce4;
extern volatile long DAT_011f4400;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
// Three __stdcall virtual slots end in Release; this interface declares no device operations.
struct ReleaseInterface {
    virtual void __stdcall GetType();
    virtual void __stdcall GetFlags();
    virtual void __stdcall Release();
};
struct FUN_00e89840_Class {
    void* m_ppVirtualMethodTable;
    int m_04;
    int m_08;
    void* m_0c;
    void* m_10;
    int m_14;
    void* m_18;
    int m_1c;
    ReleaseInterface* m_20;
    int m_24;
    int m_28;
    void UpdateFields_00e89840();
};
struct FUN_00e89ae0_obj;
typedef int (__stdcall *FUN_00e89ae0_vfn)(FUN_00e89ae0_obj*, int, int, int);
struct FUN_00e89ae0_obj { void** vtbl; };
struct FUN_00e89ae0_cls {
    int unk0000; int unk0004; int unk0008; int unk000C; int unk0010; int unk0014; int unk0018; int unk001C; int unk0020; int unk0024; int unk0028; int unk002C;
    int unk0030; int unk0034; int unk0038; int unk003C; int unk0040; int unk0044; int unk0048; int unk004C; int unk0050; int unk0054; int unk0058; int unk005C;
    int unk0060; int unk0064; int unk0068; int unk006C; int unk0070; int unk0074; int unk0078; int unk007C; int unk0080; int unk0084; int unk0088; int unk008C;
    int unk0090; int unk0094; int unk0098; int unk009C; int unk00A0; int unk00A4; int unk00A8; int unk00AC; int unk00B0; int unk00B4; int unk00B8; int unk00BC;
    int unk00C0; int unk00C4; int unk00C8; int unk00CC; int unk00D0; int unk00D4; int unk00D8; int unk00DC; int unk00E0; int unk00E4; int unk00E8; int unk00EC;
    int unk00F0; int unk00F4; int unk00F8; int unk00FC; int unk0100; int unk0104; int unk0108; int unk010C; int unk0110; int unk0114; int unk0118; int unk011C;
    int unk0120; int unk0124; int unk0128; int unk012C; int unk0130; int unk0134; int unk0138; int unk013C; int unk0140; int unk0144; int unk0148; int unk014C;
    int unk0150; int unk0154; int unk0158; int unk015C; int unk0160; int unk0164; int unk0168; int unk016C; int unk0170; int unk0174; int unk0178; int unk017C;
    int unk0180; int unk0184; int unk0188; int unk018C; int unk0190; int unk0194; int unk0198; int unk019C; int unk01A0; int unk01A4; int unk01A8; int unk01AC;
    int unk01B0; int unk01B4; int unk01B8; int unk01BC; int unk01C0; int unk01C4; int unk01C8; int unk01CC; int unk01D0; int unk01D4; int unk01D8; int unk01DC;
    int unk01E0; int unk01E4; int unk01E8; int unk01EC; int unk01F0; int unk01F4; int unk01F8; int unk01FC; int unk0200; int unk0204; int unk0208; int unk020C;
    int unk0210; int unk0214; int unk0218; int unk021C; int unk0220; int unk0224; int unk0228; int unk022C; int unk0230; int unk0234; int unk0238; int unk023C;
    int unk0240; int unk0244; int unk0248; int unk024C; int unk0250; int unk0254; int unk0258; int unk025C; int unk0260; int unk0264; int unk0268; int unk026C;
    int unk0270; int unk0274; int unk0278; int unk027C; int unk0280; int unk0284; int unk0288; int unk028C; int unk0290; int unk0294; int unk0298; int unk029C;
    int unk02A0; int unk02A4; int unk02A8; int unk02AC; int unk02B0; int unk02B4; int unk02B8; int unk02BC; int unk02C0; int unk02C4; int unk02C8; int unk02CC;
    int unk02D0; int unk02D4; int unk02D8; int unk02DC; int unk02E0; int unk02E4; int unk02E8; int unk02EC; int unk02F0; int unk02F4; int unk02F8; int unk02FC;
    int unk0300; int unk0304; int unk0308; int unk030C; int unk0310; int unk0314; int unk0318; int unk031C; int unk0320; int unk0324; int unk0328; int unk032C;
    int unk0330; int unk0334; int unk0338; int unk033C; int unk0340; int unk0344; int unk0348; int unk034C; int unk0350; int unk0354; int unk0358; int unk035C;
    int unk0360; int unk0364; int unk0368; int unk036C; int unk0370; int unk0374; int unk0378; int unk037C; int unk0380; int unk0384; int unk0388; int unk038C;
    int unk0390; int unk0394; int unk0398; int unk039C; int unk03A0; int unk03A4; int unk03A8; int unk03AC; int unk03B0; int unk03B4; int unk03B8; int unk03BC;
    int unk03C0; int unk03C4; int unk03C8; int unk03CC; int unk03D0; int unk03D4; int unk03D8; int unk03DC; int unk03E0; int unk03E4; int unk03E8; int unk03EC;
    int unk03F0; int unk03F4; int unk03F8; int unk03FC; int unk0400; int unk0404; int unk0408; int unk040C; int unk0410; int unk0414; int unk0418; int unk041C;
    int unk0420; int unk0424; int unk0428; int unk042C; int unk0430; int unk0434; int unk0438; int unk043C; int unk0440; int unk0444; int unk0448; int unk044C;
    int unk0450; int unk0454; int unk0458; int unk045C; int unk0460; int unk0464; int unk0468; int unk046C; int unk0470; int unk0474; int unk0478; int unk047C;
    int unk0480; int unk0484; int unk0488; int unk048C; int unk0490; int unk0494; int unk0498; int unk049C; int unk04A0; int unk04A4; int unk04A8; int unk04AC;
    int unk04B0; int unk04B4; int unk04B8; int unk04BC; int unk04C0; int unk04C4; int unk04C8; int unk04CC; int unk04D0; int unk04D4; int unk04D8; int unk04DC;
    int unk04E0; int unk04E4; int unk04E8; int unk04EC; int unk04F0; int unk04F4; int unk04F8; int unk04FC; int unk0500; int unk0504; int unk0508; int unk050C;
    int unk0510; int unk0514; int unk0518; int unk051C; int unk0520; int unk0524; int unk0528; int unk052C; int unk0530; int unk0534; int unk0538; int unk053C;
    int unk0540; int unk0544; int unk0548; int unk054C; int unk0550; int unk0554; int unk0558; int unk055C; int unk0560; int unk0564; int unk0568; int unk056C;
    int unk0570; int unk0574; int unk0578; int unk057C; int unk0580; int unk0584; int unk0588; int unk058C; int unk0590; int unk0594; int unk0598; int unk059C;
    int unk05A0; int unk05A4; int unk05A8; int unk05AC; int unk05B0; int unk05B4; int unk05B8; int unk05BC; int unk05C0; int unk05C4; int unk05C8; int unk05CC;
    int unk05D0; int unk05D4; int unk05D8; int unk05DC; int unk05E0; int unk05E4; int unk05E8; int unk05EC; int unk05F0; int unk05F4; int unk05F8; int unk05FC;
    int unk0600; int unk0604; int unk0608; int unk060C; int unk0610; int unk0614; int unk0618; int unk061C; int unk0620; int unk0624; int unk0628; int unk062C;
    int unk0630; int unk0634; int unk0638; int unk063C; int unk0640; int unk0644; int unk0648; int unk064C; int unk0650; int unk0654; int unk0658; int unk065C;
    int unk0660; int unk0664; int unk0668; int unk066C; int unk0670; int unk0674; int unk0678; int unk067C; int unk0680; int unk0684; int unk0688; int unk068C;
    int unk0690; int unk0694; int unk0698; int unk069C; int unk06A0; int unk06A4; int unk06A8; int unk06AC; int unk06B0; int unk06B4; int unk06B8; int unk06BC;
    int unk06C0; int unk06C4; int unk06C8; int unk06CC; int unk06D0; int unk06D4; int unk06D8; int unk06DC; int unk06E0; int unk06E4; int unk06E8; int unk06EC;
    int unk06F0; int unk06F4; int unk06F8; int unk06FC; int unk0700; int unk0704; int unk0708; int unk070C; int unk0710; int unk0714; int unk0718; int unk071C;
    int unk0720; int unk0724; int unk0728; int unk072C; int unk0730; int unk0734; int unk0738; int unk073C; int unk0740; int unk0744; int unk0748; int unk074C;
    int unk0750; int unk0754; int unk0758; int unk075C; int unk0760; int unk0764; int unk0768; int unk076C; int unk0770; int unk0774; int unk0778; int unk077C;
    int unk0780; int unk0784; int unk0788; int unk078C; int unk0790; int unk0794; int unk0798; int unk079C; int unk07A0; int unk07A4; int unk07A8; int unk07AC;
    int unk07B0; int unk07B4; int unk07B8; int unk07BC; int unk07C0; int unk07C4; int unk07C8; int unk07CC; int unk07D0; int unk07D4; int unk07D8; int unk07DC;
    int unk07E0; int unk07E4; int unk07E8; int unk07EC; int unk07F0; int unk07F4; int unk07F8; int unk07FC; int unk0800; int unk0804; int unk0808; int unk080C;
    int unk0810; int unk0814; int unk0818; int unk081C; int unk0820; int unk0824; int unk0828; int unk082C; int unk0830; int unk0834; int unk0838; int unk083C;
    int unk0840; int unk0844; int unk0848; int unk084C; int unk0850; int unk0854; int unk0858; int unk085C; int unk0860; int unk0864; int unk0868; int unk086C;
    int unk0870; int unk0874; int unk0878; int unk087C; int unk0880; int unk0884; int unk0888; int unk088C; int unk0890; int unk0894; int unk0898; int unk089C;
    int unk08A0; int unk08A4; int unk08A8; int unk08AC; int unk08B0; int unk08B4; int unk08B8; int unk08BC; int unk08C0; int unk08C4; int unk08C8; int unk08CC;
    int unk08D0; int unk08D4; int unk08D8; int unk08DC; int unk08E0; int unk08E4; int unk08E8; int unk08EC; int unk08F0; int unk08F4; int unk08F8; int unk08FC;
    int unk0900; int unk0904; int unk0908; int unk090C; int unk0910; int unk0914; int unk0918; int unk091C; int unk0920; int unk0924; int unk0928; int unk092C;
    int unk0930; int unk0934; int unk0938; int unk093C; int unk0940; int unk0944; int unk0948; int unk094C; int unk0950; int unk0954; int unk0958; int unk095C;
    int unk0960; int unk0964; int unk0968; int unk096C; int unk0970; int unk0974; int unk0978; int unk097C; int unk0980; int unk0984; int unk0988; int unk098C;
    int unk0990; int unk0994; int unk0998; int unk099C; int unk09A0; int unk09A4; int unk09A8; int unk09AC; int unk09B0; int unk09B4; int unk09B8; int unk09BC;
    int unk09C0; int unk09C4; int unk09C8; int unk09CC; int unk09D0; int unk09D4; int unk09D8; int unk09DC; int unk09E0; int unk09E4; int unk09E8; int unk09EC;
    int unk09F0; int unk09F4; int unk09F8; int unk09FC; int unk0A00; int unk0A04; int unk0A08; int unk0A0C; int unk0A10; int unk0A14; int unk0A18; int unk0A1C;
    int unk0A20; int unk0A24; int unk0A28; int unk0A2C; int unk0A30; int unk0A34; int unk0A38; int unk0A3C; int unk0A40; int unk0A44; int unk0A48; int unk0A4C;
    int unk0A50; int unk0A54; int unk0A58; int unk0A5C; int unk0A60; int unk0A64; int unk0A68; int unk0A6C; int unk0A70; int unk0A74; int unk0A78; int unk0A7C;
    int unk0A80; int unk0A84; int unk0A88; int unk0A8C; int unk0A90; int unk0A94; int unk0A98; int unk0A9C; int unk0AA0; int unk0AA4; int unk0AA8; int unk0AAC;
    int unk0AB0; int unk0AB4; int unk0AB8; int unk0ABC; int unk0AC0; int unk0AC4; int unk0AC8; int unk0ACC; int unk0AD0; int unk0AD4; int unk0AD8; int unk0ADC;
    int unk0AE0; int unk0AE4; int unk0AE8; int unk0AEC; int unk0AF0; int unk0AF4; int unk0AF8; int unk0AFC; int unk0B00; int unk0B04; int unk0B08; int unk0B0C;
    int unk0B10; int unk0B14; int unk0B18; int unk0B1C; int unk0B20; int unk0B24; int unk0B28; int unk0B2C; int unk0B30; int unk0B34; int unk0B38; int unk0B3C;
    int unk0B40; int unk0B44; int unk0B48; int unk0B4C; int unk0B50; int unk0B54; int unk0B58; int unk0B5C; int unk0B60; int unk0B64; int unk0B68; int unk0B6C;
    int unk0B70; int unk0B74; int unk0B78; int unk0B7C; int unk0B80; int unk0B84; int unk0B88; int unk0B8C; int unk0B90; int unk0B94; int unk0B98; int unk0B9C;
    int unk0BA0; int unk0BA4; int unk0BA8; int unk0BAC; int unk0BB0; int unk0BB4; int unk0BB8; int unk0BBC; int unk0BC0; int unk0BC4; int unk0BC8; int unk0BCC;
    int unk0BD0; int unk0BD4; int unk0BD8; int unk0BDC; int unk0BE0; int unk0BE4; int unk0BE8; int unk0BEC; int unk0BF0; int unk0BF4; int unk0BF8; int unk0BFC;
    int unk0C00; int unk0C04; int unk0C08; int unk0C0C; int unk0C10; int unk0C14; int unk0C18; int unk0C1C; int unk0C20; int unk0C24; int unk0C28; int unk0C2C;
    int unk0C30; int unk0C34; int unk0C38; int unk0C3C; int unk0C40; int unk0C44; int unk0C48; int unk0C4C; int unk0C50; int unk0C54; int unk0C58; int unk0C5C;
    int unk0C60; int unk0C64; int unk0C68; int unk0C6C; int unk0C70; int unk0C74; int unk0C78; int unk0C7C; int unk0C80; int unk0C84; int unk0C88; int unk0C8C;
    int unk0C90; int unk0C94; int unk0C98; int unk0C9C; int unk0CA0; int unk0CA4; int unk0CA8; int unk0CAC; int unk0CB0; int unk0CB4; int unk0CB8; int unk0CBC;
    int unk0CC0; int unk0CC4; int unk0CC8; int unk0CCC; int unk0CD0; int unk0CD4; int unk0CD8; int unk0CDC; int unk0CE0; int unk0CE4; int unk0CE8; int unk0CEC;
    int unk0CF0; int unk0CF4; int unk0CF8; int unk0CFC; int unk0D00; int unk0D04; int unk0D08; int unk0D0C; int unk0D10; int unk0D14; int unk0D18; int unk0D1C;
    int unk0D20; int unk0D24; int unk0D28; int unk0D2C; int unk0D30; int unk0D34; int unk0D38; int unk0D3C; int unk0D40; int unk0D44; int unk0D48; int unk0D4C;
    int unk0D50; int unk0D54; int unk0D58; int unk0D5C; int unk0D60; int unk0D64; int unk0D68; int unk0D6C; int unk0D70; int unk0D74; int unk0D78; int unk0D7C;
    int unk0D80; int unk0D84; int unk0D88; int unk0D8C; int unk0D90; int unk0D94; int unk0D98; int unk0D9C; int unk0DA0; int unk0DA4; int unk0DA8; int unk0DAC;
    int unk0DB0; int unk0DB4; int unk0DB8; int unk0DBC; int unk0DC0; int unk0DC4; int unk0DC8; int unk0DCC; int unk0DD0; int unk0DD4; int unk0DD8; int unk0DDC;
    int unk0DE0; int unk0DE4; int unk0DE8; int unk0DEC; int unk0DF0; int unk0DF4; int unk0DF8; int unk0DFC; int unk0E00; int unk0E04; int unk0E08; int unk0E0C;
    int unk0E10; int unk0E14; int unk0E18; int unk0E1C; int unk0E20; int unk0E24; int unk0E28; int unk0E2C; int unk0E30; int unk0E34; int unk0E38; int unk0E3C;
    int unk0E40; int unk0E44; int unk0E48; int unk0E4C; int unk0E50; int unk0E54; int unk0E58; int unk0E5C; int unk0E60; int unk0E64; int unk0E68; int unk0E6C;
    int unk0E70; int unk0E74; int unk0E78; int unk0E7C; int unk0E80; int unk0E84; int unk0E88; int unk0E8C; int unk0E90; int unk0E94; int unk0E98; int unk0E9C;
    int unk0EA0; int unk0EA4; int unk0EA8; int unk0EAC; int unk0EB0; int unk0EB4; int unk0EB8; int unk0EBC; int unk0EC0; int unk0EC4; int unk0EC8; int unk0ECC;
    int unk0ED0; int unk0ED4; int unk0ED8; int unk0EDC; int unk0EE0; int unk0EE4; int unk0EE8; int unk0EEC; int unk0EF0; int unk0EF4; int unk0EF8; int unk0EFC;
    int unk0F00; int unk0F04; int unk0F08; int unk0F0C; int unk0F10; int unk0F14; int unk0F18; int unk0F1C; int unk0F20; int unk0F24; int unk0F28; int unk0F2C;
    int unk0F30; int unk0F34; int unk0F38; int unk0F3C; int unk0F40; int unk0F44; int unk0F48; int unk0F4C; int unk0F50; int unk0F54; int unk0F58; int unk0F5C;
    int unk0F60; int unk0F64; int unk0F68; int unk0F6C; int unk0F70; int unk0F74; int unk0F78; int unk0F7C; int unk0F80; int unk0F84; int unk0F88; int unk0F8C;
    int unk0F90; int unk0F94; int unk0F98; int unk0F9C; int unk0FA0; int unk0FA4; int unk0FA8; int unk0FAC; int unk0FB0; int unk0FB4; int unk0FB8; int unk0FBC;
    int unk0FC0; int unk0FC4; int unk0FC8; int unk0FCC; int unk0FD0; int unk0FD4; int unk0FD8; int unk0FDC; int unk0FE0; int unk0FE4; int unk0FE8; int unk0FEC;
    int unk0FF0; int unk0FF4; int unk0FF8; int unk0FFC; int unk1000; int unk1004; int unk1008; int unk100C; int unk1010; int unk1014; int unk1018; int unk101C;
    int unk1020; int unk1024; int unk1028; int unk102C; int unk1030; int unk1034; int unk1038; int unk103C; int unk1040; int unk1044; int unk1048; int unk104C;
    int unk1050; int unk1054; int unk1058; int unk105C; int unk1060; int unk1064; int unk1068; int unk106C; int unk1070; int unk1074; int unk1078; int unk107C;
    int unk1080; int unk1084; int unk1088; int unk108C; int unk1090; int unk1094; int unk1098; int unk109C; int unk10A0; int unk10A4; int unk10A8; int unk10AC;
    int unk10B0; int unk10B4; int unk10B8; int unk10BC; int unk10C0; int unk10C4; int unk10C8; int unk10CC; int unk10D0; int unk10D4; int unk10D8; int unk10DC;
    int unk10E0; int unk10E4; int unk10E8; int unk10EC; int unk10F0; int unk10F4;
    FUN_00e89ae0_obj* m_10f8;
    bool IsVtblCallSucceeded(int a1, int a2, int a3, int a4);
};
struct E89B40Device {
    virtual long __stdcall vfunc00();
    virtual long __stdcall vfunc01();
    virtual long __stdcall vfunc02();
    virtual long __stdcall vfunc03();
    virtual long __stdcall vfunc04();
    virtual long __stdcall vfunc05();
    virtual long __stdcall vfunc06();
    virtual long __stdcall vfunc07();
    virtual long __stdcall vfunc08();
    virtual long __stdcall vfunc09();
    virtual long __stdcall vfunc0A();
    virtual long __stdcall vfunc0B();
    virtual long __stdcall vfunc0C();
    virtual long __stdcall vfunc0D();
    virtual long __stdcall vfunc0E();
    virtual long __stdcall vfunc0F();
    virtual long __stdcall vfunc10();
    virtual long __stdcall vfunc11();
    virtual long __stdcall vfunc12();
    virtual long __stdcall vfunc13();
    virtual long __stdcall vfunc14();
    virtual long __stdcall vfunc15();
    virtual long __stdcall vfunc16();
    virtual long __stdcall vfunc17();
    virtual long __stdcall vfunc18();
    virtual long __stdcall vfunc19();
    virtual long __stdcall vfunc1A();
    virtual long __stdcall vfunc1B();
    virtual long __stdcall vfunc1C();
    virtual long __stdcall vfunc1D();
    virtual long __stdcall vfunc1E();
    virtual long __stdcall vfunc1F();
    virtual long __stdcall vfunc20();
    virtual long __stdcall vfunc21();
    virtual long __stdcall vfunc22();
    virtual long __stdcall vfunc23();
    virtual long __stdcall vfunc24();
    virtual long __stdcall vfunc25();
    virtual long __stdcall vfunc26();
    virtual long __stdcall vfunc27();
    virtual long __stdcall vfunc28();
    virtual long __stdcall vfunc29();
    virtual long __stdcall vfunc2A();
    virtual long __stdcall vfunc2B();
    virtual long __stdcall vfunc2C();
    virtual long __stdcall vfunc2D();
    virtual long __stdcall vfunc2E();
    virtual long __stdcall vfunc2F();
    virtual long __stdcall vfunc30();
    virtual long __stdcall vfunc31();
    virtual long __stdcall vfunc32();
    virtual long __stdcall vfunc33();
    virtual long __stdcall vfunc34();
    virtual long __stdcall vfunc35();
    virtual long __stdcall vfunc36();
    virtual long __stdcall vfunc37();
    virtual long __stdcall vfunc38();
    virtual long __stdcall vfunc39();
    virtual long __stdcall vfunc3A();
    virtual long __stdcall vfunc3B();
    virtual long __stdcall vfunc3C();
    virtual long __stdcall vfunc3D();
    virtual long __stdcall vfunc3E();
    virtual long __stdcall vfunc3F();
    virtual long __stdcall vfunc40();
    virtual long __stdcall vfunc41();
    virtual long __stdcall vfunc42();
    virtual long __stdcall vfunc43();
    virtual long __stdcall vfunc44();
    virtual long __stdcall vfunc45();
    virtual long __stdcall vfunc46();
    virtual long __stdcall vfunc47();
    virtual long __stdcall vfunc48();
    virtual long __stdcall vfunc49();
    virtual long __stdcall vfunc4A();
    virtual long __stdcall vfunc4B();
    virtual long __stdcall vfunc4C();
    virtual long __stdcall vfunc4D();
    virtual long __stdcall vfunc4E();
    virtual long __stdcall vfunc4F();
    virtual long __stdcall vfunc50();
    virtual long __stdcall vfunc51();
    virtual long __stdcall vfunc52();
    virtual long __stdcall vfunc53();
    virtual long __stdcall vfunc54();
    virtual long __stdcall vfunc55();
    virtual long __stdcall vfunc56();
    virtual long __stdcall vfunc57();
    virtual long __stdcall vfunc58();
    virtual long __stdcall vfunc59();
    virtual long __stdcall vfunc5A();
    virtual long __stdcall vfunc5B();
    virtual long __stdcall vfunc5C();
    virtual long __stdcall vfunc5D();
    virtual long __stdcall vfunc5E();
    virtual long __stdcall vfunc5F();
    virtual long __stdcall SetState(unsigned int uiA, unsigned int uiB, unsigned int uiC);
};
class E89B40Renderer {
public:
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int unk0EA0;
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    int unk0EB0;
    int unk0EB4;
    int unk0EB8;
    int unk0EBC;
    int unk0EC0;
    int unk0EC4;
    int unk0EC8;
    int unk0ECC;
    int unk0ED0;
    int unk0ED4;
    int unk0ED8;
    int unk0EDC;
    int unk0EE0;
    int unk0EE4;
    int unk0EE8;
    int unk0EEC;
    int unk0EF0;
    int unk0EF4;
    int unk0EF8;
    int unk0EFC;
    int unk0F00;
    int unk0F04;
    int unk0F08;
    int unk0F0C;
    int unk0F10;
    int unk0F14;
    int unk0F18;
    int unk0F1C;
    int unk0F20;
    int unk0F24;
    int unk0F28;
    int unk0F2C;
    int unk0F30;
    int unk0F34;
    int unk0F38;
    int unk0F3C;
    int unk0F40;
    int unk0F44;
    int unk0F48;
    int unk0F4C;
    int unk0F50;
    int unk0F54;
    int unk0F58;
    int unk0F5C;
    int unk0F60;
    int unk0F64;
    int unk0F68;
    int unk0F6C;
    int unk0F70;
    int unk0F74;
    int unk0F78;
    int unk0F7C;
    int unk0F80;
    int unk0F84;
    int unk0F88;
    int unk0F8C;
    int unk0F90;
    int unk0F94;
    int unk0F98;
    int unk0F9C;
    int unk0FA0;
    int unk0FA4;
    int unk0FA8;
    int unk0FAC;
    int unk0FB0;
    int unk0FB4;
    int unk0FB8;
    int unk0FBC;
    int unk0FC0;
    int unk0FC4;
    int unk0FC8;
    int unk0FCC;
    int unk0FD0;
    int unk0FD4;
    int unk0FD8;
    int unk0FDC;
    int unk0FE0;
    int unk0FE4;
    int unk0FE8;
    int unk0FEC;
    int unk0FF0;
    int unk0FF4;
    int unk0FF8;
    int unk0FFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    E89B40Device* m_pkDevice;

    bool SetDeviceState(unsigned int uiA, unsigned int uiB, unsigned int uiC, unsigned int uiUnused);
};
extern int DAT_010efb7c;
extern int DAT_010a080c;
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);
struct FUN_00e8a9e0_mgr {
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
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void Call57(void* apObj);
};
struct FUN_00e8a9e0_child {
    virtual void v00();
    virtual void v04();
    virtual void __stdcall Release();
};
struct FUN_00e8a9e0_owner {
    int unk00;
};
struct FUN_00e8a9e0_cls {
    int m_vptr;
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
    FUN_00e8a9e0_owner* m_pSharedOwner;
    FUN_00e8a9e0_child* m_pChildObject;

    void BaseCleanup();
    FUN_00e8a9e0_cls* FUN_00e8a9e0(unsigned char acFlags);
};
struct CubeMapSource {
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual int __stdcall GetSurfaceLevel(int a, unsigned int b, int* c);
};
struct CubeMapSurface {
    virtual void v00();
    virtual void v01();
    virtual void __stdcall Release();
};
extern "C" void __cdecl NiDX9SourceTextureData_CopyDataToSurfaceLevel(int a, unsigned int b, int c, int d);
extern "C" void* __cdecl GetHResultName(int r);
extern "C" void __cdecl Object_DoNothing(const char* fmt, unsigned int i, void* s);
struct FUN_00e8aaf0_cls {
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
    CubeMapSource* m_64;
    unsigned int m_68;
    void __thiscall NiDX9SourceCubeMapData_CopyDataToSurface(int a1, int a2);
};
class MobileTargetObj {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64();
    virtual void v68(int a, int b, int c, int d);
};
class FUN_00e8b170_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    MobileTargetObj* m_pFlagTarget;
    unsigned int unk24;
    unsigned int unk28;
    unsigned char unk2C;
    unsigned char unk2D;
    unsigned short unk2E;
    unsigned int unk30;
    unsigned int unk34;

    void NiDX9LightManager_InitRenderModes();
};
class FUN_00e8b1f0_cls {
public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1C;
    unsigned int m_unk20;
    unsigned int m_unk24;
    unsigned int m_unk28;
    unsigned int m_unk2C;
    unsigned int m_unk30;
    unsigned int m_unk34;
    unsigned int m_nextIndex;
    unsigned int m_bits[128];
    int AllocateBitIndex();
};
struct S_00e8b4b0_Class {
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
    unsigned char m_70;
    unsigned char m_71;

    void __thiscall UpdateFromSource(int value);
    S_00e8b4b0_Class* __thiscall Init(int value1, int value2);
};
struct Key {
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
 unsigned int mark;
};
struct Value {
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
 unsigned int index;
};
struct Item { Item* next; Key* key; Value* value; };
struct PoolNode { PoolNode* next; PoolNode* prev; void* data; };
struct LockObj { unsigned int value; void BSSpinLock_Lock(char*); };
extern LockObj DAT_011c5f80;
extern unsigned int DAT_011c5f84;
extern PoolNode* DAT_011c5f58;
struct Com { virtual void __stdcall f0(); virtual void __stdcall f1(); virtual void __stdcall Release(); };
struct ListCleanup { void FUN_004ed900(); };
void _delete(void*,unsigned int);
struct Target {
 virtual void f0();
 virtual unsigned int Hash(Key*);
 unsigned int bucketCount;
 Item** buckets;
 unsigned int count;
 PoolNode* head;
 PoolNode* tail;
 unsigned int listCount;
 Com* object;
 unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38;
 unsigned int bits[8];
 void ClearBit(unsigned int index) { unsigned int word=index>>5; unsigned int mask=1<<(index&31); bits[word]&=~mask; }
 Item* NiTMapIterator_GetFirstPos();
 void ProcessEntries_00e8b630();
};
extern int DAT_010efdd8;
extern int DAT_010efdf8;
extern "C" void* __cdecl _NiMalloc_00aa1070(unsigned int);
extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
struct Observer {
    virtual void __stdcall Slot0();
    virtual void __stdcall Slot1();
};
struct MapProcessor {
    int* vtable;
    unsigned int bucketCount;
    void* buckets;
    unsigned int itemCount;
    int field10;
    int field14;
    int field18;
    Observer* observer1c;
    void* volatile context20;
    int index24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    unsigned char data3c[512];
    void NiDX9LightManager_InitRenderModes();
    MapProcessor* NiDX9LightManager_NiDX9LightManager(void* context, Observer* observer);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* p);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* cs);
void* __cdecl NiMemset(void* dst, int val, unsigned int size);
void* __cdecl NiMalloc(unsigned int size);
extern volatile long DAT_011f4400;
struct ComStub {
    virtual long __stdcall QueryInterface(void* riid, void** out);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
extern "C" char* DAT_0109b220;
extern "C" void (__stdcall* DAT_00fdf1c0)(void*);
extern "C" void (__stdcall* DAT_00fdf1c4)(void*);
class FUN_00e8e330_cls {
public:
    char** m_00;
    unsigned int m_04;
    unsigned int m_08;

    void ResizeStringArray(unsigned int newCap);
    void PushBack(char* const* src);
};
struct ListNode_b5254 {
    ListNode_b5254* m_00;
    ListNode_b5254* m_04;
    unsigned int m_08;
};
struct NodePool_b5254 {
    unsigned int m_00;
    ListNode_b5254* Alloc();
};
extern "C" ListNode_b5254* DAT_0126f0f8;
extern "C" ListNode_b5254* DAT_0126f0fc;
extern "C" NodePool_b5254 DAT_0126f100;
static inline unsigned int& NextKey_b5254(ListNode_b5254*& pos) {
    unsigned int& e = pos->m_08;
    pos = pos->m_00;
    return e;
}
void AddKeyToList(unsigned int key);
struct FUN_00e940a0_Global {
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0c;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1c;
    int unk_20;
    int unk_24;
    int unk_28;
    int unk_2c;
    int unk_30;
    int unk_34;
    int unk_38;
    int unk_3c;
    int unk_40;
    int unk_44;
    void* unk_48;
};
extern FUN_00e940a0_Global* DAT_011f4a64;
struct FUN_00e940a0_Class {
    void* m_00;
    void __thiscall ReleaseGlobalSlot();
};
extern "C" void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00e94150_Node {
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
    FUN_00e94150_Node* m_3c;
    FUN_00e94150_Node* m_40;
};
struct FUN_00e94150_Class {
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
    FUN_00e94150_Node* m_2c;

    void __thiscall RemoveNode(FUN_00e94150_Node* node);
};
class FUN_00e95b60_cls {
public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_00e95b60_cls* Reset();
};
struct S_00e97790_This {
    void __thiscall NiD3DShaderConstantManager_NiD3DShaderConstantManager(void* p);
};
struct FUN_00e984d0_Struct {
    int unk00;
    int unk04;
    int unk08;
    int (__cdecl *unk0c)(FUN_00e984d0_Struct*, int, int, int*, int);
};
void __cdecl Runtime_UpdateState_00e984d0(FUN_00e984d0_Struct* pStruct, int aiArg1, int aiArg2);
struct FnvCpu_FUN_00e98e10_CpuTarget { void NiPick_Results_ClearArray(); };
struct FnvCpu_FUN_00e98e10_CpuOwner {
    void ProcessState_00e98e10();
};
typedef bool (__cdecl *FNV_CondFn_e9c8c0)(float, void*, unsigned int, void*, unsigned int);
class FUN_00e9c8c0_obj {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual unsigned int GetIndex();
};
extern FNV_CondFn_e9c8c0* DAT_0126fa94;
bool __cdecl CallConditionFunction(float afValue, FUN_00e9c8c0_obj* apFirst, unsigned int auiFirstArg, FUN_00e9c8c0_obj* apSecond, unsigned int auiSecondArg);
typedef int (__cdecl *FUN_00e9c950_handler)(float, void*, int, void*, int, int, int, int, int, int);
extern FUN_00e9c950_handler* DAT_0126fa98;
class FUN_00e9c950_cls_key
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual int Slot3();
};
int DispatchPairHandler(float afValue, FUN_00e9c950_cls_key* pFirst, int aiFirstArg, FUN_00e9c950_cls_key* pSecond, int aiSecondArg, int aiArg6, int aiArg7, int aiArg8, int aiArg9, int aiArg10);
struct DispatchObj_b4010 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};
typedef void (__cdecl *DispatchFn_b4010)(float, DispatchObj_b4010*, int, int, int, int, int);
extern DispatchFn_b4010* DAT_0126fa9c;
void __cdecl DispatchByVirtualIndex(float afValue, DispatchObj_b4010* apObj, int aiArg2, int aiArg3, int aiArg4, int aiArg5, int aiArg6);
struct FUN_00e9e840_Class
{
    virtual int m_virtual00(int value);
    virtual int m_virtual01(int value);
    virtual int m_virtual02(int value);
    virtual int m_virtual03(int value);
    virtual int m_virtual04(int value);
    virtual int m_virtual05(int value);
    virtual int m_virtual06(int value);
    virtual int m_virtual07(int value);
    virtual bool m_virtual08(int value);
    virtual bool m_virtual09(int value);

    bool __thiscall ProcessAndTransformResult_00e9e840(int value);
};
inline int FUN_00e9e840_Class::m_virtual01(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual02(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual03(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual04(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual05(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual06(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual07(int value)
{
    return value;
}
inline bool FUN_00e9e840_Class::m_virtual08(int value)
{
    return value != 0;
}
inline bool FUN_00e9e840_Class::m_virtual09(int value)
{
    return value != 0;
}
// src: GUESS 0x00e9e840 (confidence: low)
bool FUN_00e9e840_Class::ProcessAndTransformResult_00e9e840(int value)
{
    return !m_virtual09(value);
}
struct ItemArrayOwner {
    unsigned int unk00;
    unsigned int unk04;
    void** pItems;
    unsigned short unk0C;
    unsigned short count;
    unsigned int unk10;
    unsigned int foundIndex;
};
bool __cdecl CallConditionFunction(float a1, void* a2, unsigned int a3, void* a4, unsigned int a5);
bool __cdecl FindMatchingItemPair(float afValue, ItemArrayOwner* apOwnerA, unsigned int a3, ItemArrayOwner* apOwnerB, unsigned int a5);
struct FNVItemHolder {
    int m_00;
    int m_04;
    void** m_08;
    unsigned short m_0c;
    unsigned short m_0e;
    int m_10;
    int m_14;
};
bool __cdecl DispatchPairHandler(float f, void* item, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
bool __cdecl FindItemByPredicate(float f, FNVItemHolder* holder, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
// Candidate for FindMatchingPair (167 bytes)
//
// Searches two fixed-size index tables for a pair of entries that satisfy a
// comparison predicate.  On success the index of the outer table entry and of
// the inner table entry are stored back into the two table descriptors and the
// function reports true; otherwise it reports false.
struct E9EB60_Item
{
    int unk00;
    int unk04;
    void** m_ppData;
    unsigned short unk0c;
    unsigned short m_uiItemCount;
    int unk10;
    int m_result;
};
extern "C" bool __cdecl E9C950_probe(float a0, void* a1, int a2, void* a3,
                                     int a4, int a5, int a6, int a7, int a8, int a9);
bool __cdecl FindMatchingPair(float a0, E9EB60_Item* a1, int a2, E9EB60_Item* pListB, int a4, int a5, int a6, int a7, int a8, int a9);
struct FogProperty {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned short flags;
    float depth;
    float red, green, blue;
};
static int to_int(float f) { float t = f; return *(int*)&t; }
// Grow the object pool: allocate a block of N entries and push every entry onto the free set.
class E94B0MemoryManager {
public:
    void* Allocate(unsigned int uiSize);
};
extern E94B0MemoryManager g_kE94B0MemoryManager;
struct E94B0Entry {
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
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
};
E94B0Entry* __cdecl E94B0AllocEntries(unsigned int ItemUpdateArray) throw();
struct E94B0Block {
    E94B0Block(unsigned int ItemUpdateArray) throw() : m_uiCount(ItemUpdateArray), m_pkNext(0)
    {
        if (ItemUpdateArray > 0)
            m_pkEntryArray = E94B0AllocEntries(ItemUpdateArray);
        else
            m_pkEntryArray = 0;
    }

    static void* operator new(unsigned int uiSize) { return g_kE94B0MemoryManager.Allocate(uiSize); }

    E94B0Entry* GetAt(unsigned int uiIndex)
    {
        if (uiIndex >= m_uiCount)
            return 0;
        return &m_pkEntryArray[uiIndex];
    }

    E94B0Entry* m_pkEntryArray;
    unsigned int m_uiCount;
    E94B0Block* m_pkNext;
};
class E94B0Pool {
public:
    E94B0Entry** m_ppkFree;
    unsigned int m_uiAllocated;
    unsigned int m_uiFree;
    E94B0Block* m_pkBlocks;

    void Realloc(unsigned int uiNewSize);

    void AddFree(E94B0Entry* pkEntry)
    {
        if (m_uiFree == m_uiAllocated)
            Realloc(m_uiAllocated > 0 ? 2 * m_uiAllocated : 1);
        m_ppkFree[m_uiFree] = pkEntry;
        m_uiFree++;
    }

    void AddBlock(unsigned int ItemUpdateArray);
};
struct PoolItemStub {
    bool m_bIsCubeMap;
};
struct GlobalPoolStub {
    PoolItemStub** m_apFree;
    unsigned int m_unk04;
    int m_numFree;
    unsigned int m_unk0c;
    unsigned int m_growBy;
    unsigned int m_unk14;
    void __thiscall Grow(unsigned int growBy);
};
PoolItemStub* __cdecl AllocatePoolItem();
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern float DAT_0126f9c4;
struct Matrix { NiPoint3 a,b,c; };
struct LightSource {
float f00;
float f04;
float f08;
float f0c;
float f10;
float f14;
float f18;
float f1c;
float f20;
float f24;
float f28;
float f2c;
float f30;
float f34;
float f38;
float f3c;
float f40;
float f44;
float f48;
float f4c;
float f50;
float f54;
float f58;
float f5c;
float f60;
float f64;
float f68;
float f6c;
float f70;
float f74;
float f78;
float f7c;
float f80;
float f84;
float f88;
float f8c;
float f90;
float f94;
float f98;
unsigned char unk9c; unsigned char kind; unsigned char unk9e; unsigned char unk9f;
float fa0;
float fa4;
int fa8;
float fac;
float fb0;
float fb4;
float fb8;
float fbc;
float fc0;
float fc4;
Matrix matrix;
float fec;
float ff0;
float ff4;
float ff8;
float ffc;
float f100;
float f104;
float f108;
float f10c;
float f110;
};
struct LightState {
int f00;
float f04;
float f08;
float f0c;
float f10;
float f14;
float f18;
float f1c;
float f20;
float f24;
float f28;
float f2c;
float f30;
float f34;
float f38;
float f3c;
float f40;
float f44;
float f48;
float f4c;
float f50;
float f54;
float f58;
float f5c;
float f60;
float f64;
int f68;
bool UpdateFromSource(LightSource* source);
};
extern "C" void __cdecl _NiFree_00aa10f0(void* p);
extern int DAT_010f0ef0;
struct FUN_00e89740_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    void Cleanup();
};
void NiD3DTextureStageGroup_ShutdownPools();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plValue);
extern char* DAT_0109b220;
struct StringTable {
    static void IncRefCount(char* pcHandle)
    {
        if (pcHandle != DAT_0109b220)
            InterlockedIncrement((long volatile*)(pcHandle - 8));
    }
    static void DecRefCount(char* pcHandle)
    {
        if (pcHandle != DAT_0109b220)
            InterlockedDecrement((long volatile*)(pcHandle - 8));
    }
};
class FixedStr {
public:
    FixedStr& operator=(const FixedStr& kString)
    {
        if (m_kHandle != kString.m_kHandle) {
            char* pcHandle = kString.m_kHandle;
            StringTable::IncRefCount(pcHandle);
            StringTable::DecRefCount(m_kHandle);
            m_kHandle = pcHandle;
        }
        return *this;
    }
    char* m_kHandle;
};
FixedStr* NiTNewInterface_NiFixedString_Allocate(unsigned int ItemUpdateArray);
// array new
void Object_ProcessEntries_00a644a0(FixedStr* pkArray);
// array delete
class FixedStrArray {
public:
    void ResizeStringArray(unsigned int uiMaxSize);

    FixedStr* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
};
struct Ptr_e98cb0 {
    NiRefObject* m_p;
    void Release() { NiRefObject* r = m_p; if (r && InterlockedDecrement((long volatile*)&r->m_uiRefCount) == 0) r->DeleteThis(); }
    void Clear() {
        NiRefObject* r = m_p;
        if (r) {
            if (InterlockedDecrement((long volatile*)&r->m_uiRefCount) == 0) r->DeleteThis();
            m_p = 0;
        }
    }
};
// Both members release NiRefObject references; shared Pair holds two scalar integers.
struct RetainedObjectReferences {
    Ptr_e98cb0 first;
    Ptr_e98cb0 second;
};
struct E98CB0Arr {
    int vtbl;
    RetainedObjectReferences** m_pBase;
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short pad;
    int unk10;
    void NiPick_Results_ClearArray(bool bFree);
};
struct NiColor3 {
    float m_r;
    float m_g;
    float m_kPointB;
    __forceinline NiColor3() : m_r(0.0f), m_g(0.0f), m_kPointB(0.0f) {}
};
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern volatile long DAT_011f4400;
struct SubObjF8 {
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
    void __thiscall ReturnThis2() throw();
    SubObjF8() {
        ReturnThis2();
    }
};
struct PairEntry {
    int key;
    int val;
};
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern int DAT_0126f918;
extern int DAT_0126f91c;
extern int DAT_0126f920;
extern int DAT_0126f924;
extern int DAT_0126f928;
extern unsigned short DAT_0126f92c[];
extern unsigned short DAT_0126f948[8];
extern unsigned short DAT_0126f958[];
struct FUN_00e8bf80_Object {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38;
    int m_uiItemCount;
    void __thiscall NiDX9VertexBufferManager_EndFrame();
};
struct FUN_00e8d350_Class {
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

    int* __thiscall NiDX9FragmentShader_GetShaderInstanceDesc();
};
struct Item9ea;
bool DispatchByVirtualIndex(float fTime, Item9ea* pkItem, void* p2, void* p3, void* p4, void* p5, void* p6);
struct Seq9ea
{
    int m_00;
    int m_04;
    Item9ea** m_ppGeometries;
    short m_0c;
    unsigned short m_usElementCount;
    int m_10;
    unsigned int m_uiLast;
};
bool NiUnionBV_UnionTriTestIntersect(float fTime, Seq9ea* pkSeq, void* p2, void* p3, void* p4, void* p5, void* p6);
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
struct ColorWithAlpha { float r,g,b,a; ColorWithAlpha(float red,float green,float blue):r(red),g(green),b(blue) {} void addScaled(const ColorWithAlpha& source,float factor) { r+=source.r*factor;g+=source.g*factor;b+=source.b*factor; } };
struct ActiveLight;
struct SceneLight {
 unsigned int field00;
 unsigned int field04;
 unsigned int field08;
 unsigned int field0c;
 unsigned int field10;
 unsigned int field14;
 unsigned int field18;
 unsigned int field1c;
 unsigned int field20;
 unsigned int field24;
 unsigned int field28;
 unsigned int field2c;
 unsigned int field30;
 unsigned int field34;
 unsigned int field38;
 unsigned int field3c;
 unsigned int field40;
 unsigned int field44;
 unsigned int field48;
 unsigned int field4c;
 unsigned int field50;
 unsigned int field54;
 unsigned int field58;
 unsigned int field5c;
 unsigned int field60;
 unsigned int field64;
 unsigned int field68;
 unsigned int field6c;
 unsigned int field70;
 unsigned int field74;
 unsigned int field78;
 unsigned int field7c;
 unsigned int field80;
 unsigned int field84;
 unsigned int field88;
 unsigned int field8c;
 unsigned int field90;
 unsigned int field94;
 unsigned int field98;
 unsigned char enabled; unsigned char direct; unsigned short field9e;
 unsigned int fielda0;
 unsigned int fielda4;
 unsigned int fielda8;
 unsigned int fieldac;
 unsigned int fieldb0;
 unsigned int fieldb4;
 unsigned int fieldb8;
 unsigned int fieldbc;
 unsigned int fieldc0;
 float intensity;
 float red;
 float green;
 float blue;
 unsigned int fieldd4;
 unsigned int fieldd8;
 unsigned int fielddc;
 unsigned int fielde0;
 unsigned int fielde4;
 unsigned int fielde8;
 ActiveLight* active;
};
struct ActiveLight {
 unsigned int field00;
 unsigned int field04;
 unsigned int field08;
 unsigned int field0c;
 unsigned int field10;
 unsigned int field14;
 unsigned int field18;
 unsigned int field1c;
 unsigned int field20;
 unsigned int field24;
 unsigned int field28;
 unsigned int field2c;
 unsigned int field30;
 unsigned int field34;
 unsigned int field38;
 unsigned int field3c;
 unsigned int field40;
 unsigned int field44;
 unsigned int field48;
 unsigned int field4c;
 unsigned int field50;
 unsigned int field54;
 unsigned int field58;
 unsigned int field5c;
 unsigned int field60;
 unsigned int field64;
 unsigned int field68;
 unsigned int field6c;
 bool stale; bool applied; unsigned short field72;
 bool UpdateFromSource(SceneLight*);
 ActiveLight* Init(SceneLight*, unsigned int);
};
struct LightDevice {
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
 virtual void slot54();
 virtual void slot58();
 virtual void slot5c();
 virtual void slot60();
 virtual void slot64();
 virtual void slot68();
 virtual void slot6c();
 virtual void slot70();
 virtual void slot74();
 virtual void slot78();
 virtual void slot7c();
 virtual void slot80();
 virtual void slot84();
 virtual void slot88();
 virtual void slot8c();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual void slot9c();
 virtual void slota0();
 virtual void slota4();
 virtual void slota8();
 virtual void slotac();
 virtual void slotb0();
 virtual void slotb4();
 virtual void slotb8();
 virtual void slotbc();
 virtual void slotc0();
 virtual void slotc4();
 virtual void slotc8();
 virtual void __stdcall SetLight(unsigned int, ActiveLight*);
 virtual void slotd0();
 virtual void __stdcall EnableLight(unsigned int, int);
};
struct LightInputNode { LightInputNode* next; SceneLight* light; };
struct LightInput { unsigned int field00,field04,field08; LightInputNode* head; };
inline SceneLight*& nextLight(PoolNode*& node) { SceneLight*& item=(SceneLight*&)node->data; node=node->next; return item; }
struct ShadowSceneLightList { PoolNode* head; PoolNode* tail; unsigned int count; void* InsertHead(SceneLight* const*); SceneLight* FUN_004edf00();
 __forceinline void recycle(PoolNode* node) { node->data=0; DAT_011c5f80.BSSpinLock_Lock(0); node->prev=0; node->next=DAT_011c5f58; --DAT_011c5f84; DAT_011c5f58=node; if (!DAT_011c5f84) DAT_011c5f80.value=0; }
 __forceinline SceneLight* remove(PoolNode*& node) { if(node==head) { PoolNode* old=head; head=old->next; if(head) head->prev=0; else tail=0; SceneLight* element=(SceneLight*)old->data; recycle(old); --count; return element; } else if(node==tail) { return FUN_004edf00(); } else { PoolNode* prev=node->prev; PoolNode* next=node->next; if(prev)prev->next=next; if(next)next->prev=prev; SceneLight* element=(SceneLight*)node->data; recycle(node); --count; return element; } }
};
extern const float runtimeFloatSettingDefault9;
struct LightManager { unsigned int field00,field04,field08,field0c; ShadowSceneLightList active; LightDevice* device; MobileTargetObj* render; unsigned int field24,field28; unsigned char field2c; bool enabled; unsigned short field2e;
 unsigned int AllocateBitIndex(); void InsertOrUpdate(SceneLight*,ActiveLight*); void NiDX9LightManager_UpdateLights(LightInput* input); };
struct S00e8f190_Iface { void** vtable; };
typedef int (__thiscall *S00e8f190_Query)(void* vt, S00e8f190_Iface* object, int a, int b, int c, int d, S00e8f190_Iface** result, int zero);
typedef void (__fastcall *S00e8f190_Release)(void* flag, void* vt, S00e8f190_Iface* object, void* flag2);
struct S00e8f190_Cls {
    int unk00;
    int unk04;
    S00e8f190_Iface* object;
    S00e8f190_Iface* __thiscall FUN_00e8f190(int a, int b, int c, int d, void* flag);
};
extern "C" const char str_010f0184[];
extern unsigned int DAT_011bf560;
extern unsigned int DAT_011bf558;
struct Stage321 {
    int m_00;
    unsigned int m_04;
    int m_08;
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
    int m_60;

    void ReturnToPool() throw();
    void AcquireReference() { ++m_60; }
    void DecRef() { if (--m_60 == 0) ReturnToPool(); }
};
struct StagePtr {
    Stage321* m_p;
    StagePtr(Stage321* o) : m_p(o) { if (m_p) m_p->AcquireReference(); }
};
struct StageArray {
    void* m_vtbl;
    StagePtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void NiD3DPass_SetAtGrow(unsigned int size) throw();
    void Set(unsigned int index, const StagePtr& obj) throw();
    void SetAtGrow(unsigned int index, const StagePtr& obj) {
        if (index >= m_usMaxSize)
            NiD3DPass_SetAtGrow(index + m_usGrowBy);
        Set(index, obj);
    }
};
struct StageSet {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_14;
    int m_18;
    int m_1C;
    StageArray m_20;

    int NiD3DPass_SetStage(unsigned int index, Stage321* obj);
};
struct S00e81b00_Mat {
    float m00, m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38, m3c;
};
static void CopyMatrix(S00e81b00_Mat* dst, const S00e81b00_Mat* src);
void S00e81b00_Caller(S00e81b00_Mat* dst, const S00e81b00_Mat* src);
typedef unsigned int UINT;
typedef unsigned long DWORD;
struct SurfDesc { UINT Format, Type, Usage, Pool, MultiSampleType, MultiSampleQuality, Width, Height; };
struct VolDesc { UINT Format, Type, Usage, Pool, Width, Height, Depth; };
struct BaseTex {
 virtual long __stdcall QueryInterface(const void*,void**);
 virtual unsigned __stdcall AddRef();
 virtual unsigned __stdcall Release();
 virtual long __stdcall GetDevice(void**);
 virtual long __stdcall SetPrivateData(const void*,const void*,unsigned,unsigned);
 virtual long __stdcall GetPrivateData(const void*,void*,unsigned*);
 virtual long __stdcall FreePrivateData(const void*);
 virtual unsigned __stdcall SetPriority(unsigned);
 virtual unsigned __stdcall GetPriority();
 virtual void __stdcall PreLoad();
 virtual int __stdcall GetType();
 virtual unsigned __stdcall SetLOD(unsigned);
 virtual unsigned __stdcall GetLOD();
 virtual unsigned __stdcall GetLevelCount();
 virtual long __stdcall SetAutoGenFilterType(unsigned);
 virtual unsigned __stdcall GetAutoGenFilterType();
 virtual void __stdcall GenerateMipSubLevels();
};
struct Tex2D : BaseTex { virtual long __stdcall GetLevelDesc(unsigned, SurfDesc*); };
struct TexCube : BaseTex { virtual long __stdcall GetLevelDesc(unsigned, SurfDesc*); };
struct TexVol : BaseTex { virtual long __stdcall GetLevelDesc(unsigned, VolDesc*); };
void __cdecl GetPixelTemplateForFormat(UINT format, void* out);
struct TextureInfo {
    int unk00;
    int unk04;
    int unk08;
    UINT m_fMaxFriction;
    UINT m_height;
    int m_format14;
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
    DWORD m_levelCount;

    bool InitFromTexture(BaseTex* pTexture);
};
void __cdecl FUN_00aa1460(void* pvMem, unsigned int uiSize);
class ControllerE8B {
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
    void* m_pvHandle;
    unsigned char unk70;
    bool m_bModifierActive;
    unsigned short unk72;
};
class KeyObjectE8B {
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
    void* m_pvMapEntry;
};
class OwnerE8B {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4c();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5c();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6c();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7c();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8c();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9c();
    virtual void unka0();
    virtual void unka4();
    virtual void unka8();
    virtual void unkac();
    virtual void unkb0();
    virtual void unkb4();
    virtual void unkb8();
    virtual void unkbc();
    virtual void unkc0();
    virtual void unkc4();
    virtual void unkc8();
    virtual void unkcc();
    virtual void unkd0();
    virtual void __stdcall ReleaseHandle(void* pvHandle, int iFlags);
};
struct VBDesc {
    int iFormat;
    int iType;
    int iUsage;
    int iPool;
    unsigned int uiSize;
    unsigned int uiFVF;
};
struct VertexBuffer;
struct VertexBufferVtbl {
    void* s00; void* s04; void* s08; void* s0c;
    void* s10; void* s14; void* s18; void* s1c;
    void* s20; void* s24; void* s28; void* s2c;
    long (__stdcall *Unlock)(VertexBuffer* self);
    long (__stdcall *GetDesc)(VertexBuffer* self, VBDesc* desc);
};
struct VertexBuffer {
    VertexBufferVtbl* vtbl;
};
struct VBEntry {
    int unk00;
    int unk04;
    VertexBuffer* pkVB;
    unsigned int uiElapsedMilliseconds;
    unsigned int uiFlags;
    unsigned int uiSize;
};
struct C_00e8f010 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    unsigned int uiStreamCount;
    unsigned int* puiStrides;
    void FUN_00e8f010(int fvf);
};
struct FUN_00e69b40_shell {
    unsigned int GetEntry(unsigned int index);
};
struct Outer;
extern "C" void* memmove(void* dst, const void* src, unsigned int n);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
// Six 32-bit fields occupy 0x18 bytes; this record has no scalar spin-lock operations.
struct SixIntegerRecord {
    int d00; int d04; int d08; int d0c; int d10; int d14;
};
struct TwoComponentVector { float x, y; };
struct Point4 { TwoComponentVector kXY; float z, w; };
struct ThisObj {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    void* pvSrc;
    int unk44;
    void* pvDst;
    unsigned int uiLen;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    SixIntegerRecord kLock;
    bool NiDX9VertexBufferManager_AllocateBufferSpace(Outer* outer, unsigned int arg);
    void* NiDX9VertexBufferManager_LockVB(VertexBuffer* vb, unsigned int offset, unsigned int size, unsigned int flags);
    VBEntry* NiDX9VertexBufferManager_PackTransformedVB(C_00e8f010* owner, unsigned short count, const TwoComponentVector* pos, const float* col, const unsigned int* uv, unsigned int streamFlags, VBEntry* existing, void* data);
};
struct S00e8f360_Desc {
    unsigned int Format;
    unsigned int Type;
    unsigned int Usage;
    unsigned int Pool;
    unsigned int Size;
};
enum { S00e8f360_FMT16 = 101, S00e8f360_RTIB = 7 };
struct S00e8f360_IB {
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetDevice(void**) = 0;
    virtual long __stdcall SetPrivateData(const void*, const void*, unsigned long, unsigned long) = 0;
    virtual long __stdcall GetPrivateData(const void*, void*, unsigned long*) = 0;
    virtual long __stdcall FreePrivateData(const void*) = 0;
    virtual unsigned long __stdcall SetPriority(unsigned long) = 0;
    virtual unsigned long __stdcall GetPriority() = 0;
    virtual void __stdcall PreLoad() = 0;
    virtual unsigned int __stdcall GetType() = 0;
    virtual long __stdcall Lock(unsigned int, unsigned int, void**, unsigned int) = 0;
    virtual long __stdcall Unlock() = 0;
    virtual long __stdcall GetDesc(S00e8f360_Desc*) = 0;
};
struct S00e8f360_Dev {
    virtual long __stdcall v00() = 0;
    virtual long __stdcall v01() = 0;
    virtual long __stdcall v02() = 0;
    virtual long __stdcall v03() = 0;
    virtual long __stdcall v04() = 0;
    virtual long __stdcall v05() = 0;
    virtual long __stdcall v06() = 0;
    virtual long __stdcall v07() = 0;
    virtual long __stdcall v08() = 0;
    virtual long __stdcall v09() = 0;
    virtual long __stdcall v10() = 0;
    virtual long __stdcall v11() = 0;
    virtual long __stdcall v12() = 0;
    virtual long __stdcall v13() = 0;
    virtual long __stdcall v14() = 0;
    virtual long __stdcall v15() = 0;
    virtual long __stdcall v16() = 0;
    virtual long __stdcall v17() = 0;
    virtual long __stdcall v18() = 0;
    virtual long __stdcall v19() = 0;
    virtual long __stdcall v20() = 0;
    virtual long __stdcall v21() = 0;
    virtual long __stdcall v22() = 0;
    virtual long __stdcall v23() = 0;
    virtual long __stdcall v24() = 0;
    virtual long __stdcall v25() = 0;
    virtual long __stdcall v26() = 0;
    virtual long __stdcall CreateIndexBuffer(unsigned int, unsigned int, unsigned int, unsigned int, S00e8f360_IB**, void*) = 0;
};
extern const char str_010f0184[];
extern const char str_010f0200[];
extern const char str_010eddd0[];
typedef void (__cdecl *S00e8f360_LogFn)(const char*);
struct S00e8f360_Mgr {
    void* m_pOwnerObject;
    void* m_pThreadAllocator;
    S00e8f360_Dev* m_device;
    S00e8f360_IB* m_indexBuffer;
    unsigned int m_indexBufferSize;
    S00e8f360_IB* EnsureIndexBuffer(unsigned int minQuads, unsigned int quadCount, bool populate, unsigned int usage, unsigned int pool);
};
extern "C" void* __cdecl memset(void*, int, unsigned int);
struct IDirect3DDevice9Like;
struct D3DINDEXBUFFER_DESC_L
{
    int Format;
    int Type;
    unsigned int Usage;
    int Pool;
    unsigned int Size;
};
struct IDirect3DIndexBuffer9Like
{
    virtual long __stdcall QueryInterface(void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall Slot03() = 0;
    virtual long __stdcall Slot04() = 0;
    virtual long __stdcall Slot05() = 0;
    virtual long __stdcall Slot06() = 0;
    virtual long __stdcall Slot07() = 0;
    virtual long __stdcall Slot08() = 0;
    virtual long __stdcall Slot09() = 0;
    virtual long __stdcall Slot10() = 0;
    virtual long __stdcall Lock(unsigned int OffsetToLock, unsigned int SizeToLock, void** ppbData, unsigned int Flags) = 0;
    virtual long __stdcall Unlock() = 0;
    virtual long __stdcall GetDesc(D3DINDEXBUFFER_DESC_L* pDesc) = 0;
};
struct Resource8F6D0 {
    virtual long __stdcall QueryInterface(void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct Chip8F6D0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Resource8F6D0* m_pkResource;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    ~Chip8F6D0();
    static void operator delete(void* pvMem, unsigned int uiSize);
};
struct Entry8F6D0 {
    int unk00;
    int unk04;
    Chip8F6D0* m_apChips[5];
    static void operator delete(void* pvMem, unsigned int uiSize);
};
#include <string.h>
struct FUN_00e93470_Output {
    unsigned int flags;
    const char* text;
    unsigned int data;
};
struct FUN_00e93470_Class {
    unsigned int m_field00;
    unsigned int m_field04;
    unsigned int m_field08;
    unsigned int m_field0c;
    unsigned char m_copyText;
    void __thiscall FUN_00e93470(FUN_00e93470_Output* out, const char* text, unsigned int data);
};
extern "C" void* __cdecl _NiMalloc_00aa1070(unsigned int length);
extern "C" void __cdecl FUN_00ec65a6(void* destination, unsigned int length, const char* source);
struct RefBaseE989 {
    unsigned int m_uiRefCount;
    RefBaseE989() : m_uiRefCount(0) {}
    virtual ~RefBaseE989() { InterlockedDecrement(&DAT_011f4400); }
};
struct ComReleaseE989 {
    virtual long __stdcall QueryInterface(void* riid, void** out);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct ShaderDataE989 : RefBaseE989 {
    void* m_08; void* m_0c; void* m_10; void* m_14;
    int m_18; int m_1c; int m_20; int m_24; int m_28; int m_2c;
    void* m_30; void* m_34; void* m_38; void* m_3c;
    int m_40; int m_44; int m_48; int m_4c; int m_50; int m_54;
    void* m_58; void* m_5c; void* m_60; void* m_64;
    int m_68; int m_6c; int m_70; int m_74; int m_78; int m_7c;
    ComReleaseE989* m_80;
    virtual ~ShaderDataE989() throw();
};
struct FUN_00e9ca50_Object {
    virtual void FUN_00e9ca50_Virtual0();
    virtual void FUN_00e9ca50_Virtual1();
    virtual void FUN_00e9ca50_Virtual2();
    virtual int FUN_00e9ca50_GetIndex();
};
typedef void (__cdecl *FUN_00e9ca50_Entry)(
    float,
    FUN_00e9ca50_Object *,
    int,
    int,
    int,
    int,
    int,
    int,
    int,
    int,
    int,
    int);
extern void **DAT_0126faa0;
void __cdecl NiBoundingVolume_FindTriIntersect( float value, FUN_00e9ca50_Object *object, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10);
struct FUN_00e9ec90 {
    void* m_pData;
    virtual ~FUN_00e9ec90();
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }
};
static const void* kNull = 0;
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void _ReadWriteBarrier();
void* Object_DispatchCommandFour(unsigned int size);
struct S00e8fa80_Node {
    volatile unsigned int key;
    unsigned char flag;
    void* buffers[5];
    void Initialize() {
        key = 0; flag = 0;
        memset(buffers, 0, sizeof(buffers));
    }
};
struct S00e8fa80_Map {
    unsigned int unk00, unk04, unk08, unk0c;
    bool __thiscall FUN_00a53c30(unsigned int packed, S00e8fa80_Node*& out);
    void __thiscall InsertOrUpdate(unsigned int packed, S00e8fa80_Node* node);
};
struct S00e8fa80_Obj {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    S00e8fa80_Map map1c, map2c, map3c;
    S00e8fa80_Node* GetOrCreateNode(int a, unsigned int b, int c);
};
void* Object_DispatchCommandFour(unsigned int size);
struct BlockLink {unsigned int next; unsigned int prev; BlockLink() : next(0), prev(0) {} };
struct AllocationBlock {
    void* unk00;
    void* unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    BlockLink link;
};
struct FUN_00a64330_Obj {
    unsigned int __thiscall NiTArray_void_cdecl_NiStream_NiObject_NiTMallocInterface_void_cdecl_NiStream_NiObject_AddFirstEmpty(AllocationBlock** key);
};
struct BlockAllocator {
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
    FUN_00a64330_Obj unk2C;
    unsigned int __thiscall NiVBBlock_AllocateChip(unsigned int size);
};
extern int DAT_0126fa58;
void AllocateNodeList();
// Creates and uploads a cube texture resource.
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct TextureSurface;
struct DeviceResource;
struct ResourceConfig;
struct TextureInput;
struct TextureDescription {
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
};
struct ResourceOwner {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    DeviceResource* resource;
};
struct ResourceConfig {
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
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
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
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
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
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    bool mipmaps; unsigned char unk6f5; unsigned short unk6f6;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    TextureDescription* renderTargets[22];
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int defaultTarget;
};
struct DirectResource {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    TextureDescription description;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int* width;
    unsigned int* height;
    unsigned int* sizes;
    unsigned int unk070;
    unsigned int levels;
    unsigned int unk078;
    unsigned int faces;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    void* source;

    const TextureDescription& GetDescription() const { return description; }
    unsigned int GetWidth(unsigned int level = 0) const { return width[level]; }
    unsigned int GetHeight(unsigned int level = 0) const { return height[level]; }
    unsigned int GetLevels() const { return levels; }
    unsigned int GetFaces() const { return faces; }
    unsigned int GetSize() const { return sizes[GetLevels()] * GetFaces(); }
    void* GetPalette() const { return source; }
};
struct TextureSurface {
    virtual void v0();
    virtual unsigned long Release();
    volatile long references;
    void IncRefCount() { InterlockedIncrement(&references); }
    void DecRefCount() { if (!InterlockedDecrement(&references)) Release(); }
    TextureDescription description;
    void* source;
    unsigned int unk050;
    unsigned int* width;
    unsigned int* height;
    unsigned int* sizes;
    unsigned int levels;
    unsigned int unk064;
    unsigned int flags;
    unsigned int faces;

    const TextureDescription& GetDescription() const { return description; }
    unsigned int GetWidth(unsigned int level = 0) const { return width[level]; }
    unsigned int GetHeight(unsigned int level = 0) const { return height[level]; }
    unsigned int GetLevels() const { return levels; }
    unsigned int GetFaces() const { return faces; }
    unsigned int GetSize() const { return sizes[GetLevels()] * GetFaces(); }
    void* GetPalette() const { return source; }
    unsigned int GetFlags() const { return flags; }
};
struct TextureInput {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    struct InputDescription { unsigned int unk00, unk04, mode, unk0c, unk10, unk14, unk18; } description;
    void* resourceId;
    DirectResource* direct;
    TextureSurface* surface;
    const InputDescription& GetPreferences() const { return description; }
    DirectResource* GetDirect() const { return direct; }
    TextureSurface* GetSurface() const { return surface; }
    void* GetFilename() const { return resourceId; }
};
struct DeviceResource {
    virtual void Delete(unsigned int);
    unsigned int unk004;
    ResourceOwner* owner;
    unsigned int width;
    unsigned int height;
    TextureDescription description;
    unsigned int unk058;
    unsigned int unk05c;
    ResourceConfig* config;
    void* texture;
    unsigned int levels;
    bool fallback; bool mipmaps; unsigned short unk06e;
    unsigned int bytes;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int flags;

    void SetDescription(const TextureDescription& other) { description = other; }
    void SetDimensions(unsigned int x, unsigned int y) { width = x; height = y; }
    void FUN_00e687a0(TextureInput*, ResourceConfig*);
    bool SetProgram(void*);
    TextureDescription* NiDX9TextureData_FindMatchingPixelFormat(TextureDescription*, void*, TextureDescription**);
    bool NiDX9SourceCubeMapData_CreateCubeMap();
    void NiDX9SourceCubeMapData_CopyRendererDataToCubeMapFace(DirectResource*, unsigned int);
    void NiDX9SourceCubeMapData_CopyDataToSurface(TextureSurface*, unsigned int);
};
struct PlainResource58 {
    void* vtable;
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
    unsigned int flags;

    void FUN_00e687a0(TextureInput*, ResourceConfig*);
    PlainResource58(TextureInput* input, ResourceConfig* config) {
        FUN_00e687a0(input, config);
        vtable = &DAT_010efc34;
        flags = 0;
    }
};
struct ResourceManager {
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual TextureSurface* GetTexture(void*, unsigned int, unsigned int);
    virtual void unused4();
    virtual TextureSurface* PrepareTexture(TextureSurface*, TextureDescription*, TextureSurface*, bool);
};
struct DepthDevice {
    virtual void __stdcall ReportDiagnostic();
    virtual void __stdcall unused1();
    virtual void __stdcall unused2();
    virtual void __stdcall FlushUsageData();
    virtual void __stdcall unused4();
    virtual void __stdcall unused5();
    virtual void __stdcall unused6();
    virtual void __stdcall unused7();
    virtual void __stdcall unused8();
    virtual void __stdcall unused9();
    virtual long __stdcall CreateResource(unsigned int, _D3DDEVTYPE, _D3DFORMAT, int, int, int);
};
struct CreationContext {
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
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
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
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
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
    unsigned int width;
    _D3DDEVTYPE deviceType;
    unsigned int unk5cc;
    _D3DFORMAT adapterFormat;

    void GetCreationInfo(unsigned int& w, _D3DDEVTYPE& h, _D3DFORMAT& f) {
        w = width;
        h = deviceType;
        f = adapterFormat;
    }
};
extern void* __cdecl Object_DispatchCommandFour(unsigned int);
extern TextureSurface* __cdecl DispatchIfHighBitSet(TextureInput*, unsigned int, int);
extern ResourceManager* __cdecl FUN_00a76640();
extern void __cdecl Object_DoNothing(const void*, ...);
extern int __cdecl FUN_00e7bd20(TextureDescription*);
extern char DAT_010efd88, DAT_010ed4dc;
extern unsigned char DAT_011f4508;
extern CreationContext* DAT_011f4748;
extern DepthDevice* DAT_0126f0d8;
extern unsigned int DAT_0126f9bc, DAT_0126f9c0;
inline bool IsPowerOfTwo(unsigned int value) {
    if (value == 0) return false;
    return (value & (value - 1)) == 0;
}
DeviceResource* __cdecl NiDX9SourceCubeMapData_Create(TextureInput* input, ResourceConfig* config);
struct ShaderComponent093 {
    int type;
    int format;
    char width;
    char flag;
    short unk0a;
};
struct ShaderRequest093 {
    unsigned int NiPixelFormat_GetNumComponents();
    int unknown00;
    unsigned int kind;
    int disabled;
    int unk0c;
    int unk10;
    ShaderComponent093 components[4];
};
struct ShaderTraits093 { int kind; int ordering; };
struct ShaderChoices093 {
    void* choice00;
    void* choice04;
    void* choice08;
    void* choice0c;
    void* choice10;
    void* choice14;
    void* choice18;
    void* choice1c;
    void* choice20;
    void* choice24;
    void* choice28;
    void* choice2c;
    void* choice30;
    void* choice34;
    void* choice38;
    void* choice3c;
    void* choice40;
    void* choice44;
    void* choice48;
    void* choice4c;
    void* choice50;
    void* choice54;
};
struct ShaderValidator093 {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual bool Accept(ShaderRequest093*, void*);
};
struct PixelComponentReader093 {
    char GetEntryData(int, int*, int*, char*, char*);
};
__declspec(noinline) char PixelComponentReader093::GetEntryData(int index, int* type, int* format, char* width, char* flag) {
    ShaderRequest093* request = (ShaderRequest093*)this;
    *flag = request->components[index].flag;
    *width = request->components[index].width;
    *format = request->components[index].format;
    *type = request->components[index].type;
    return *type != 19;
}
void* __stdcall NiDX9TextureData_FindMatchingPixelFormat(ShaderRequest093* request, ShaderTraits093* traits, ShaderChoices093* choices);
struct FUN_00e8b0c0_Item {
    char m_uiStandInValue[0x4c];
    void* m_4c;
    char m_iValueAfterStandIn[0x68 - 0x50];
    int m_68;
};
struct FUN_00e8b0c0_Owner {
    char m_auiShapeKeys[0x3c];
    FUN_00e8b0c0_Item* m_3c;
};
struct FUN_00e8b0c0_Ret {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual FUN_00e8b0c0_Ret* v5(FUN_00e8b0c0_Item* a, void* b, FUN_00e8b0c0_Item* c, unsigned char d);
    int m_04;
    char m_auiShapeKeys[0x6c - 0x08];
    unsigned int m_6c;
};
struct FUN_00e8b0c0_Class {
    char m_00[8];
    FUN_00e8b0c0_Owner* m_08;
    char m_0c[8];
    char m_14[0x50];
    int m_64;
    char m_68[4];
    unsigned char m_6c;
    unsigned char m_6d;
    char m_6e[0x84 - 0x6e];
    int m_84;

    void __thiscall UpdateChangedEntries();
    void __thiscall NiDX9SourceCubeMapData_CopyDataToSurface(FUN_00e8b0c0_Ret* p, int idx);
};
extern "C" bool __stdcall SetProgram(void* a);
struct FUN_00e98910_Target {
    virtual void vf00();
    virtual int __stdcall vf04();
};
extern int DAT_0101dce4;
extern int DAT_010f16cc;
struct FUN_00e98910_Class {
    int* unk00;
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
    FUN_00e98910_Target* unk80;
    void* unk84;

    FUN_00e98910_Class* __thiscall NiD3DShaderConstantManager_NiD3DShaderConstantManager(int* context);
};
extern "C" void __cdecl NiFree(void*);
extern "C" void __cdecl NiMemObject_ReleaseStorage_00aa1490(void*, unsigned int);
struct E895A0_Sdo {
    void ReleaseStorage_00e89560();
    void* DestroyScalarObject(unsigned char flags);
};
struct E895A0_Node : E895A0_Sdo {
    void* m_block;
    int m_04;
    E895A0_Node* m_next;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};
struct E895A0_Object {
    void* m_00;
    int m_04;
    int m_08;
    E895A0_Node* m_0c;
    void __thiscall ReleaseStorage_00e895a0();
};

struct Item_cd60 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    ComStub* m_pkHolder;
    int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38;
    void __thiscall SetVirtualTable_00e95b80();
};

struct Entry_cd60 {
    int unk00;
    int unk04;
    void* items[5];
};

template <class TAlloc, class TKEY, class TVAL>
inline void* NiTMapBase<TAlloc, TKEY, TVAL>::GetFirstPos() const
{
    for (unsigned int i = 0; i < m_uiHashSize; ++i)
        if (m_ppkHashTable[i] != 0)
            return m_ppkHashTable[i];
    return 0;
}

// RemoveAll cannot throw; inlined map destruction needs no unwind handler.
template <>
__declspec(nothrow) void VertexBufferMapBase::RemoveAll();

// This unit calls the out-of-line iterator at 0x00b57f20 in its first cleanup.
template <>
__declspec(noalias) void VertexBufferMapBase::GetNext(void*& pos,
    unsigned int& key, NiDX9VertexBufferManager::NiDX9VBInfo*& value) const;

// @fnv 0x00e8cd60
// src: COMMUNITY 0x00e8cd60
void NiDX9VertexBufferManager::DestroyDefaultBuffers()
{
    VertexBufferMap* map = &this->first;
    {
        void* current = map->GetFirstPos();
        unsigned int key;
        NiDX9VertexBufferManager::NiDX9VBInfo* value;

        while (current != 0) {
            map->GetNext(current, key, value);

            if (value != 0) {
                Entry_cd60* entry = (Entry_cd60*)value;
                void** pp = entry->items;
                for (int n = 5; n != 0; --n) {
                    Item_cd60* item = (Item_cd60*)*pp;
                    if (item != 0) {
                        ComStub* holder = item->m_pkHolder;
                        if (holder != 0)
                            holder->Release();
                        ((FUN_00e95b80_Class*)item)->SetVirtualTable_00e95b80();
                        operator delete(item, 0x3c);
                    }
                    ++pp;
                }
                operator delete(entry, 0x1c);
            }
        }

    }
    map->RemoveAll();
}

extern int DAT_010efe94;
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);

struct ShaderEntry093 : FUN_00e95b80_Class {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    ComStub* resource;
    int unk24, unk28, unk2c, unk30, unk34, unk38;
};
class NiDX9VertexBufferManager::NiDX9VBInfo {
public:
    unsigned int unk00, unk04;
    ShaderEntry093* entries[5];
};
template <class TAlloc, class TKEY, class TVAL>
__forceinline NiTMapBase<TAlloc, TKEY, TVAL>::~NiTMapBase()
{
    RemoveAll();
    _NiFree_00aa10f0(m_ppkHashTable);
}

template <class TKEY, class TVAL>
__forceinline NiTPointerMap<TKEY, TVAL>::~NiTPointerMap()
{
    this->RemoveAll();
}

template <>
inline void VertexBufferMapBase::GetNext(void*& pos, unsigned int& key,
    NiDX9VertexBufferManager::NiDX9VBInfo*& value) const
{
    EntryType* current = (EntryType*)pos;
    key = current->m_key;
    value = current->m_val;
    if (current->m_pkNext) { pos = current->m_pkNext; return; }
    for (unsigned int i = KeyToHashIndex(current->m_key) + 1; i < m_uiHashSize; ++i)
    {
        EntryType* next = m_ppkHashTable[i];
        if (next) { pos = next; return; }
    }
    pos = 0;
}
// @fnv 0x00e8ceb0
// src: GUESS 0x00e8ceb0 (confidence: low)
void NiDX9VertexBufferManager::ReleaseStorage_00e8ceb0() {
    NiDX9VertexBufferManager* self = this;
    *(void**)self = &DAT_010efe94;
    VertexBufferMap* map;
    for (unsigned int group = 0; group < 3; ++group) {
        switch (group) {
        case 0: map = &self->first; break;
        case 1: map = &self->second; break;
        case 2: map = &self->third; break;
        }
        void* pos = map->GetFirstPos();
        while (pos) {
            unsigned int key;
            NiDX9VertexBufferManager::NiDX9VBInfo* record;
            map->GetNext(pos, key, record);
            if (record) {
                for (unsigned int i = 0; i < 5; ++i) {
                    ShaderEntry093* entry = record->entries[i];
                    if (entry) {
                        if (entry->resource) entry->resource->Release();
                        entry->SetVirtualTable_00e95b80();
                        FUN_00aa1460(entry, sizeof(ShaderEntry093));
                    }
                }
                FUN_00aa1460(record, sizeof(NiDX9VertexBufferManager::NiDX9VBInfo));
            }
        }
    }
    self->first.RemoveAll();
    self->second.RemoveAll();
    self->third.RemoveAll();
    self->device->Release();
    self->device = 0;
    _NiFree_00aa10f0(self->allocation);
    DeleteCriticalSection(&self->lock);
    self->third.VertexBufferMap::~NiTPointerMap();
    self->second.VertexBufferMap::~NiTPointerMap();
    self->first.VertexBufferMap::~NiTPointerMap();
    *(void**)self = &DAT_0101dce4;
    InterlockedDecrement(&DAT_011f4400);
}

extern "C" void __cdecl ShutdownE6EC20();
extern "C" void __cdecl DestroyBucketTable();
extern "C" void __cdecl DestroyGlobalQueues();
extern "C" void __cdecl NiD3DShader_ShutdownPools();
extern "C" void __cdecl ResetGlobalString();
void __cdecl NiD3DTextureStageGroup_ShutdownPools();
void __cdecl NiD3DShaderFactory__SDMShutdown();
extern "C" void __cdecl NiD3DShaderProgramFactory_UnregisterShaderCreator(void*);
extern "C" void __cdecl NiD3DShaderProgramCreator_SetD3DRenderer(void*);
extern unsigned char DAT_0126fa00;
extern NiD3DShaderProgramCreator* DAT_0126fa3c;

// @fnv 0x00e91c80
// src: COMMUNITY 0x00e91c80
void __cdecl NiDX9RendererSDM_Shutdown()
{
    if (DAT_0126fa00)
    {
        DAT_0126fa00 = 0;
        ResetGlobalString();
        void* p = DAT_0126fa3c;
        if (p)
        {
            NiD3DShaderProgramFactory_UnregisterShaderCreator(p);
            if (DAT_0126fa3c)
                delete DAT_0126fa3c;
        }
        DAT_0126fa3c = 0;
        p = DAT_0126fa54;
        if (p)
        {
            NiD3DShaderProgramFactory_UnregisterShaderCreator(p);
            if (DAT_0126fa54)
                delete DAT_0126fa54;
        }
        DAT_0126fa54 = 0;
        p = DAT_0126fa50;
        if (p)
        {
            NiD3DShaderProgramFactory_UnregisterShaderCreator(p);
            if (DAT_0126fa50)
                delete DAT_0126fa50;
        }
        DAT_0126fa50 = 0;
        NiD3DShaderProgramCreator_SetD3DRenderer(0);
        NiD3DShaderProgramFactory__SDMShutdown();
        NiD3DShaderFactory__SDMShutdown();
        DestroyBucketTable();
        NiD3DShader_ShutdownPools();
        DestroyGlobalQueues();
        NiD3DTextureStageGroup_ShutdownPools();
        ShutdownE6EC20();
    }
}

// @fnv 0x00e94290
// src: COMMUNITY 0x00e94290
void __cdecl NiVBSet_DeleteBlocks()
{
    FreeNodeList();
    FUN_00e98640_Class* node = reinterpret_cast<FUN_00e98640_Class*>(DAT_0126fa30);
    if (node)
    {
        FUN_00e98640_Class* next;
        do
        {
            next = reinterpret_cast<FUN_00e98640_Class*>(
                reinterpret_cast<int*>(node)[0x3c / 4]);
            node->ReleaseStorage_00e98640();
            operator delete(node, 0x44);
            node = next;
        } while (node);
    }
    DAT_0126fa30 = 0;
}
