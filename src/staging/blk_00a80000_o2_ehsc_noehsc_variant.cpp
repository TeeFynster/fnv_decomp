
// src/staging/blk_00a80000_o2_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/staging/blk_00a80000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00a80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/MemoryManager.h"
#include "../../include/BSFadeNode.h"
#include "../../include/NiAlphaAccumulator.h"
#include "../../include/NiRefObject.h"
#include "../../include/Ni2DBuffer.h"
#include "../../include/NiDepthStencilBuffer.h"
#include "../../include/NiPointer.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiBound.h"
#include "../../include/NiCollisionObject.h"
#include "../../include/NiCullingProperty.h"
#include "../../include/NiProperty.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiDirectionalLight.h"
#include "../../include/NiParticleMeshes.h"
#include "../../include/NiLODData.h"
#include "../../include/NiTFixedStringMap_NiAVObject___.h"
#include "../../include/Pair.h"
extern "C" void __cdecl _Call_a5d3a0();
extern const void* NiCollisionObject_vftable;
NiCollisionObject::NiCollisionObject()
{
    _Call_a5d3a0();
}
extern unsigned char* DAT_011f5b04;
void __cdecl NiParallelUpdateTaskManager_WaitRenderSema(int);
void __cdecl NiParallelUpdateTaskManager_BeginUpdate();
int __cdecl NiSkinData_BoneVertData_Compare(const unsigned short* a, const unsigned short* b);
struct FUN_00a744a0 { void Init(); };
extern const void* DAT_0109e984;
BSFadeNode* NiScreenElements_CreateObject();
struct FUN_00a87900_class {
    void NiScreenElementsData_UpdateBound();
};
extern int DAT_011f5b84;
void __cdecl InitializeGameSystems();
void __cdecl NiMainSDM_Shutdown();
void __cdecl NiStaticDataManager_SetRootLibrary(void*, void*);
struct FUN_00a8a5f0_class {
    void* UpdateState_00a8a5f0();
};
struct FUN_00a8f060_class {
    void NiPixelData_FreeData();
};
extern "C" void NiFreeAlias(void*);
struct FUN_00a8f080_Class {
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void SetValues(int a, int b);
};
struct SdmBase;
extern SdmBase* DAT_011f5e34;
struct FUN_00a8f730 {
    void __thiscall Release();
};
extern char DAT_011f5d30;
int __cdecl GetGlobalDataPtr();
extern int DAT_011f5e44;
extern int DAT_011f5e4c;
void ResetStreamLinkIDSet();
extern int DAT_0109f814;
struct FUN_00a8ff50 {
    int m_p;
    short m_s1;
    short m_s2;
    int m_i1;
    int m_i2;
    int m_i3;
    FUN_00a8ff50();
};
void __cdecl NiFreeAlias(void*);
struct FUN_00a96440_class {
    char m_auiShapeKeys[0x4c];
    void* m_pField;
    void SetField(void* pNew);
};
void NiFree(void*);
struct FUN_00a96460_class {
    char pad[0x54];
    void* m_0x54;
    void NiParticlesData_ReplaceSizes(void* p);
};
void NiFreeAlias(void*);
struct FUN_00a96480_Class {
    void* m_5c;
    void NiParticlesData_ReplaceRotationAngles(void* p);
};
extern "C" void __cdecl NiFreeAlias(void*);
struct FUN_00a964a0_Class {
    void* m_p;
    void NiParticlesData_ReplaceTextureIndices(void* p);
};
struct CloningProcess;
struct NiBinaryExtraData;
struct NiFloatsExtraData;
struct FUN_00a99c40_shell : public NiExtraData {
    void NiIntegerExtraData_CopyMembers(NiBinaryExtraData* dst, CloningProcess* cp);
};
extern const void* DAT_0109e47c;
BSFadeNode* NiSkinPartition_CreateObject();
unsigned int __cdecl NiString_GetBestBufferSize(unsigned int a);
struct NiExtraDataHelper {
    void FUN_00a7b2e0();
};
extern int DAT_0109fb94;
void* __cdecl NiVectorExtraData_CreateObject();
extern int DAT_010a02e4;
NiProperty* __cdecl NiSpecularProperty_CreateObject();
extern const void* DAT_010a0a6c;
NiParticleMeshes* __cdecl NiParticleMeshes_CreateObject();
void __cdecl NiFree(void*);
void* __cdecl NiMalloc(unsigned int);
struct FUN_00a99800_shell {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    unsigned int m_iThirdValue;
    void* m_10;
    void AssignPointerArray(unsigned int count, const void* src);
};
extern const void* DAT_010a12cc;
void __fastcall FUN_00a71f60(void*);
void* __cdecl NiAmbientLight_CreateObject();
extern unsigned int kVtbl_NiAlphaAccumulator;
NiAlphaAccumulator* CreateNiAlphaAccumulator();
struct FUN_00a9be80 {
    const void* m_vft;
    int m_ref;
    int m_data;
    FUN_00a9be80(int data);
};
extern volatile long DAT_011f4400;
extern const void* DAT_010a1478;
extern const void* vftable_NiRefObject;
struct FUN_00a84c90_class {
    char pad[0x44];
    int field44;
    short field48;
    FUN_00a84c90_class* ResetFields();
};
extern unsigned char DAT_011f5fb4;
extern unsigned char DAT_011f5fb5;
extern unsigned char DAT_011f5fb6;
extern unsigned char DAT_011f5fb7;
extern unsigned char DAT_011f5fb8;
extern unsigned char DAT_011f5fb9;
extern unsigned char DAT_011f5fba;
extern unsigned char DAT_011f5fbb;
extern unsigned char DAT_011f5fbc;
extern unsigned char DAT_011f5fbd;
extern unsigned char DAT_011f5fbe;
extern unsigned char DAT_011f5fbf;
extern unsigned char DAT_011f5fc0;
extern unsigned char DAT_011f5fc1;
extern int DAT_011f5fc4;
extern int DAT_011f5fc8;
extern int DAT_011f5fcc;
extern int DAT_011f5fd0;
extern int DAT_011f5fd4;
extern int DAT_011f5fd8;
extern int DAT_011f5fdc;
extern int DAT_011f5fe0;
extern int DAT_011f5fe4;
extern int DAT_011f5fe8;
extern int DAT_011f5fec;
extern int DAT_011f5ff0;
extern int DAT_011f5ff4;
extern int DAT_011f5ff8;
extern unsigned char DAT_011f6000;
void __cdecl NiShaderConstantMapEntry_InitializeAttribTable();
struct FUN_00a85520_class {
    void FUN_00a85520(float* dst, float scale);
};
extern const void* DAT_0109e834;
struct FUN_00a87140_class {
    void* vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
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
    int m_c4;
    int m_c8;
    char m_cc;
    void FUN_00a87140_ctor();
};
FUN_00a87140_class* BSSegmentedTriShape_CreateObject();
struct FUN_00a94c00_shell {
    char m_iWordAt00[0xfc];
    int m_fc;
    int m_100;
    int m_104;
    float m_108;
    float m_10c;
    float m_110;
    void NiSpotLight_CopyMembers(NiDirectionalLight* dst, CloningProcess& cp);
};
extern MemoryManager g_memoryManager;
extern char* DAT_010a05e4;
struct FUN_00a96800_shell {
    char m_auiShapeKeys[0x44];
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void ReleaseStorage_00a96800();
    void DestroyGeometryData();
};
extern int DAT_0109e470;
void NiFree(void*);
struct FUN_00a81bd0_class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void UpdateState_00a81bd0();
};
struct Stub {
    void NiTStringPointerMap_NiAVObject_RemoveAt(void* p);
};
extern int DAT_0109f73c;
extern void* _EmptyFS;
extern int (__stdcall* DAT_00fdf1c4)(void*);
extern const void* vftable_NiRefObject;
struct FUN_00a8f810_class {
    void SetVtableAndProcessState_00a8f810();
};
struct CloningProcess;
void __cdecl NiFree(void*);
struct FUN_00a8a670_shell {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void ForwardCall_00a8a670();
};
extern const void* vftable_SdmDerived;
extern const void* vftable_SdmBase;
void _NiFree(void*);
extern MemoryManager _g_memoryManager;
struct SdmDerived {
    void* m_vt;
    void* m_iWordAt04;
    void* m_8;
    void* FUN_00a8fa10(char flag);
};
extern char DAT_0109f9a4[];
extern void __cdecl _NiFree(void*);
extern MemoryManager _g_memoryManager;
struct FUN_00a90260_class
{
    void* m_vft;
    void* m_iWordAt04;

    void* __thiscall FUN_00a90260(int flags);
};
struct FUN_00a5a390_shell {
    void DestroyFogProperty();
    FUN_00a5a390_shell* FUN_00a950f0(bool bDel);
};
void __cdecl operator delete(void* p, unsigned int);
void __cdecl NiShaderConstantMapEntry_InitializeAttribTable();
void __cdecl NiShaderConstantMapEntry_SDMInit_NiShaderConstantMapEntry_InitializeObjectTable();
void __cdecl NiShaderConstantMapEntry__SDMInit();
struct SpawnedRef {
    virtual void Vslot00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern int DAT_0109e04c;
struct FUN_00a80580_sub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    void Cleanup();
};
struct FUN_00a80580_cls {
    void* m_vptr;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98;
    FUN_00a80580_sub m_sub9c;
    SpawnedRef* m_b8;
    SpawnedRef* m_bc;

    void BaseTeardown();
    void UpdateFields_00a80580();
};
extern const void* DAT_0109e174;
void FUN_00a5d3d0();
struct FUN_00a80fc0_class {
    void __thiscall FUN_00a80fc0();
};
extern float DAT_011ab3f8;
static const float kPi = 3.1415927f;
extern "C" double __cdecl fabs(double);
float __cdecl NiFastATan2(float y, float x);
void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_0109e32c;
struct FUN_00a81760_obj
{
    void* m_pVTable;
    char unk04[0x54];
    unsigned short m_58;
    unsigned short m_5a;

    void FUN_00a7b690();
};
FUN_00a81760_obj* __cdecl NiTriShapeDynamicData_CreateObject();
struct S_a819e0_O {
virtual ~S_a819e0_O() {}
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
};
void NiParallelUpdateTaskManager_Shutdown();
// FUN_00a81ba0 : constructor of a plain object whose first member is the
// class vtable pointer. Clears the dword fields at +4..+0x18, a word at +0x22
// and a dword at +0x28.
extern int DAT_0109e470;
struct FUN_00a81ba0_cls
{
    void* m_pVTable;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int unk1c;
    unsigned short unk20;
    volatile unsigned short m_22;
    unsigned int unk24;
    unsigned int m_28;

    FUN_00a81ba0_cls();
};
struct FUN_00a84c60_cls
{
    unsigned short m_00;
    FUN_00a84c60_cls* ClearField00_00a84c60();
};
struct FUN_00a84ca0_entry {
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
    void* unk44;
    int unk48;
};
extern MemoryManager g_memoryManager;
struct FUN_00a84ca0_class {
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
    void* m_40;
    unsigned int m_44;

    void FreeEntryResources();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
struct RefCountedObject {
    virtual void UnknownVirtual();
    virtual void DeleteThis();
    volatile long referenceCount;
};
struct CloneObject {
    int unk00;
    int unk04;
    RefCountedObject* first;
    RefCountedObject* second;

    void CreateVertexBufferSet(CloneObject* destination, void* process);
    void CopyRefCountedPointers(CloneObject* destination, void* process);
};
void* __cdecl Object_DispatchCommandFour(unsigned int size) throw();
extern int DAT_01069b14;
struct SpawnedObject
{
    void* m_pVTable;
    int unk04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int unk2c;
    int m30;

    void InitBase() throw();
};
SpawnedObject* __cdecl NiSkinInstance_CreateObject() throw();
// FUN_00a87790: thiscall, 10 bytes.
// Loads the vtable pointer of this, reads the function pointer stored in
// vtable slot 0xdc and tail-jumps to it, forwarding the single stack
// argument of this method.
struct FUN_00a87790_cls
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
    virtual void Tail(int a);
    void NiScreenElements_Draw(int a);
};
struct FUN_00a88c60_Point2 {
    float unk00;
    float unk04;

    bool __thiscall ForwardCall_0051c330(const FUN_00a88c60_Point2* other);
};
struct FUN_00a88c60_Class {
    float unk00;
    float unk04;
    float unk08;
    FUN_00a88c60_Point2 unk0C;
    FUN_00a88c60_Point2 unk14;
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

    int __thiscall ProcessAndReturnValue_00a88c60(FUN_00a88c60_Class* other);
};
void NiCompUtility_DecompressFloatArray(const short* psCompressed, unsigned int uiUnused, float fProjectionAlongAim, float fHalfRange, float* pfValues, unsigned int ItemUpdateArray);
struct FUN_00a89760_base {
    virtual ~FUN_00a89760_base();
};
struct FUN_00a89760_cls : FUN_00a89760_base {
    virtual ~FUN_00a89760_cls();
};
struct BaseCls {
    void __thiscall FUN_00a67b20(int, int, int, int, int, int, int);
};
extern "C" void* __cdecl _NiMalloc_00aa1070(int);
extern int DAT_0109f23c;
struct FUN_00a8a680_cls {
    void* m_vft;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
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
    void* m_40;
    void* InitWithBuffer(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
};
struct DecodePair {unsigned char first,second;};
struct Decoder {
 unsigned int unk00,unk04;
 unsigned char* input;
 unsigned int unk0c;
 DecodePair table[256];
 void DecodeToOutput(unsigned int* output);
};
struct BlockColorDecoder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned char* cursor;

    unsigned int ReadWord()
    {
        unsigned int value = (unsigned short)(cursor[1] * (unsigned short)256 + cursor[0]);
        cursor += 2;
        return value;
    }

    void DecodeBlockColors(unsigned char* output);
};
extern const double runtimeInitializationDouble5;
void DecodeBlockColors();
struct A8BD20Entry {
    unsigned char m_ucLow;
    unsigned char m_ucHigh;
};
class FUN_00a8bd20 {
public:
    int unk00;
    void (*m_pfnCallback)();
    int unk08;
    int unk0C;
    A8BD20Entry m_akTable[256];

    FUN_00a8bd20();
};
extern "C" void __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int size);
struct FUN_00a8bdf0_cls {
    void (__thiscall* m_00)(FUN_00a8bdf0_cls* self, unsigned char* out);
    void (__thiscall* m_04)(FUN_00a8bdf0_cls* self, unsigned char* out);
    int m_08;
    int m_0c;
    void CopyGeneratedRows(unsigned char* dst, unsigned int a2, unsigned int count);
};
class FUN_00a8f140_cls {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiRefObject* m_10;

    void SetRefObject(NiRefObject* obj);
};
struct S_00a8f2c0_Arg { int unk00; int unk04; int unk08; int unk0c; };
extern const void* DAT_0109f4dc;
struct S_00a8f2c0_Sub {
    int unk00;
    void FUN_00a5f860(S_00a8f2c0_Arg* c);
};
struct S_00a8f2c0_Obj {
    void* vft;
    int unk04;
    int unk08;
    int unk0c;
    S_00a8f2c0_Sub sub;
    static void* operator new(unsigned int n) { return BSFadeNode::operator new(n); }
    S_00a8f2c0_Obj() throw() {
        FUN_00a5d3a0();
        vft = (void*)&DAT_0109f4dc;
        unk08 = 0;
        unk0c = 0;
        sub.unk00 = 0;
    }
    void FUN_00a5d3a0();
    void SetRefObject(S_00a8f2c0_Arg* c);
};
S_00a8f2c0_Obj* __cdecl CreateFadeNodeFromArg(int a, int b, S_00a8f2c0_Arg* c);
extern const void* DAT_0109f9bc;
void __cdecl ReleaseObjectArray(void*);
struct FUN_00a910f0_class {
    void* vft;
    void* buffer;
    FUN_00a910f0_class* FUN_00a910f0(unsigned char flags);
};
struct FUN_00aa4060_class {
    void MemoryManager_Deallocate(void* object);
};
extern FUN_00aa4060_class DAT_011f6238;
struct NiParticleBase {
    void* vtable;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    unsigned int unknown8c;
    unsigned int unknown90;
    unsigned int unknown94;
    unsigned int unknown98;
    void __thiscall FUN_00a5ecb0(int);
};
struct NiParticleBuffer {
    void* data;
    unsigned int count;
    unsigned short capacity;
    unsigned short used;
    unsigned short growth;
    unsigned short flags;
    void __thiscall FUN_0060bef0(int);
};
struct NiParticleSubobject {
    void* first;
    void* second;
    void* third;
    void* fourth;
    void __thiscall FUN_00a69940();
};
struct NiParticleObject : NiParticleBase {
    NiParticleBuffer buffer;
    NiParticleSubobject firstMember;
    NiParticleSubobject secondMember;
};
extern void* __cdecl Object_DispatchCommandFour(unsigned int);
extern const char DAT_010a1024;
NiParticleObject* __cdecl CreateNiParticleObject();
extern int DAT_010a13ac;
void __declspec(noreturn) FUN_00aa0dc0();
struct FUN_00a9b4a0_Class {
    void __thiscall UpdateFields_00a9b4a0();
};
extern unsigned short DAT_011f5f7c;
extern unsigned short DAT_011f5f7e;
extern unsigned short DAT_011f5f80;
extern unsigned short DAT_011f5f82;
extern unsigned short DAT_011f5f84;
extern unsigned short DAT_011f5f86;
extern unsigned short DAT_011f5f88;
extern unsigned short DAT_011f5f8a;
extern unsigned short DAT_011f5f8c;
extern int DAT_011f5f90;
extern int DAT_011f5f94;
extern int DAT_011f5f98;
extern int DAT_011f5f9c;
extern int DAT_011f5fa0;
extern int DAT_011f5fa4;
extern int DAT_011f5fa8;
extern int DAT_011f5fac;
extern int DAT_011f5fb0;
extern unsigned char DAT_011f6001;
void __cdecl NiShaderConstantMapEntry_SDMInit_NiShaderConstantMapEntry_InitializeObjectTable();
extern "C" void* DAT_0109b220;
struct ReferenceHandle
{
    volatile long* value;
    void operator=(const ReferenceHandle& other)
    {
        volatile long* next = other.value;
        if (value != next) {
            if (next != DAT_0109b220)
                InterlockedIncrement(next - 2);
            if (value != DAT_0109b220)
                InterlockedDecrement(value - 2);
            value = next;
        }
    }
};
struct RefCountedPair
{
    unsigned int identifier;
    ReferenceHandle handle;
    RefCountedPair* Assign(const RefCountedPair* other);
};
struct FUN_00a9ff00_Child
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct FUN_00a9ff00_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00a9ff00_Child* unk10;
};
struct FUN_00a9ff00_Obj
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
    virtual int v37(int a, int b, int c);
};
int __cdecl FUN_00a9fe90(int a, int b, FUN_00a9ff00_Obj* c, int d, int e);
int __cdecl ProcessArgWithObj(FUN_00a9ff00_Arg* a, FUN_00a9ff00_Obj* b);
extern unsigned char* DAT_011f5b04;
int __cdecl NiParallelUpdateTaskManager_SignalRenderSema();
struct FnvRing {
    unsigned int unk00;
    unsigned int m_pRayCursor;
    unsigned int m_pFirstNode;
    unsigned int m_pTail;

    unsigned int Count() const {
        if (m_pFirstNode == 0xffffffffu) {
            return 0;
        }
        if (m_pFirstNode >= m_pTail) {
            return m_pRayCursor - m_pFirstNode + m_pTail;
        }
        return m_pTail - m_pFirstNode;
    }
};
struct FnvQueueState {
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
    virtual void va0(int a, void* p, int b, int c);
    int Probe(int kind);
    unsigned int unk04;
    FnvRing m_r0;
    FnvRing m_r1;
    FnvRing m_r2;
    FnvRing m_r3;
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
    void* m_19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned char m_1b0;
};
void __cdecl NiParallelUpdateTaskManager_EndUpdate();
class BA87920Base {
public:
    static void* operator new(unsigned int uiSize);

    BA87920Base() throw();
    virtual ~BA87920Base();

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
};
class BA87920Object : public BA87920Base {
public:
    __forceinline BA87920Object()
        : m_pkFirst(0), m_pkSecond(0), m_usA(0), m_usB(0), m_usC(0), m_usD(0), m_usE(0), m_usF(0), m_usG(0), m_bFlag(false)
    {
    }
    virtual ~BA87920Object();

    void* m_pkFirst;
    void* m_pkSecond;
    unsigned short m_usA;
    unsigned short m_usB;
    unsigned short m_usC;
    unsigned short m_usD;
    unsigned short m_usE;
    unsigned short m_usF;
    unsigned short m_usG;
    bool m_bFlag;
};
BA87920Object* __cdecl CreateBA87920Object();
extern float g_fRadiansPerRevolution;
extern float DAT_011f52e0[];
extern float DAT_011f4ae0[];
struct TexXformPoint2 {
    float x;
    float y;
};
inline void TexXformSinCos(float fRadians, float& fSin, float& fCos)
{
    int iIndex = (int)(512.0 / g_fRadiansPerRevolution * fRadians) & 0x1ff;
    fSin = DAT_011f52e0[iIndex];
    fCos = DAT_011f4ae0[iIndex];
}
struct TexXformMatrix3 {
    float m_afEntries[3][3];
    void SetCol(unsigned int uiCol, float f0, float f1, float f2)
    {
        m_afEntries[0][uiCol] = f0;
        m_afEntries[1][uiCol] = f1;
        m_afEntries[2][uiCol] = f2;
    }
};
struct TexXform {
    TexXformPoint2 m_kTranslate;
    float m_fRotation;
    TexXformPoint2 m_kScaleFactors;
    TexXformPoint2 m_kCenter;
    bool m_bTransform;
    TexXformMatrix3 m_kTransformMatrix;
    int m_eTransformMethod;

    void UpdateMatrix();
};
extern int DAT_0109f23c;
struct NiPairHolder {
    void* m_vt;
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
    void FUN_00a67c00();
};
NiPairHolder* __cdecl CreateNiPairHolder(void);
struct AlphaBlockDecoder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned char* cursor;
    void DecodeAlphaBlock(unsigned char* output);
};
struct HashNode_cls {
    HashNode_cls* m_pNext;
    unsigned int m_key;
    unsigned int m_uiFilterValue;
};
struct SdmBase {
    unsigned int m_unk00;
    unsigned int m_bucketCount;
    HashNode_cls** m_buckets;
};
unsigned int __cdecl Object_FindGlobalHashValue(unsigned int* pKey);
extern const void* DAT_0109f7f4;
extern unsigned int DAT_011f5e48;
struct FNVObj {
    const void* vft;
    unsigned int references;
    ReferenceHandle handle;
    FNVObj* NiMaterialLibrary_NiMaterialLibrary(const ReferenceHandle& src);
};
extern "C" void* DAT_0109b220;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
struct HandleSlot
{
    volatile long* value;

    void operator=(const ReferenceHandle& other)
    {
        volatile long* next = other.value;
        if (value != next) {
            if (next != DAT_0109b220)
                InterlockedIncrement(next - 2);
            if (value != DAT_0109b220)
                InterlockedDecrement(value - 2);
            value = next;
        }
    }
};
struct FUN_00a9bda0
{
    unsigned int identifier;
    HandleSlot handle;

    FUN_00a9bda0(unsigned int id, const ReferenceHandle* src);
};
extern "C" void* DAT_0109b220;
extern int (__stdcall* DAT_00fdf1c4)(void*);
extern "C" void* __cdecl FUN_00a5b690(int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
struct S{int a; float f;};
int CompareFloatDescending(S* pA, S* pB);
struct CustomBlockDecoder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned char* cursor;

    unsigned short ReadWord()
    {
        unsigned short value = (unsigned short)(cursor[1] * (unsigned short)256 + cursor[0]);
        cursor += 2;
        return value;
    }

    void DecodePaletteBlock(unsigned char* dst);
};
void __cdecl _memmove(void*,const void*,unsigned int);
struct RleDecoder {
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
 unsigned short unk10c,count;
 unsigned int unk110;
 unsigned char stride,unk115,unk116,unk117;
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
 unsigned int run;
 bool repeat;
 unsigned char value0,value1,value2;
 unsigned char value3;
 void Decode(NiBinaryStream& stream, unsigned char* dest,unsigned int unused);
};
void __stdcall nullsub_2(int, int, int, int, int, int, int, int);
extern void __cdecl NiParticleMeshes_LoadBinary();
void __cdecl NiScreenElements_LoadBinary();
extern "C" void __cdecl NiParticleMeshes_SaveBinary();
void __cdecl NiScreenElements_SaveBinary();
extern "C" void __cdecl ReadGroup();
void __cdecl BSTextureSet_LoadBinary();
void __stdcall nullsub_3(int);
struct S_00a8d8b0;
void __cdecl AdvancePosition(S_00a8d8b0*, void*, unsigned int);
struct FUN_00a5e3a0_Helper { void* Game_DoHeapAlloc(unsigned int); };
struct PixelRow4 {
    unsigned char rgba[4];
    PixelRow4() {}
    static void* operator new[](unsigned int size) {
        return ((FUN_00a5e3a0_Helper*)&DAT_011f6238)->Game_DoHeapAlloc(size);
    }
};
struct ImageConverter {
    unsigned int unknown000;
    unsigned int unknown004;
    unsigned int unknown008;
    unsigned int unknown00c;
    unsigned int unknown010;
    unsigned int unknown014;
    unsigned int unknown018;
    unsigned int unknown01c;
    unsigned int unknown020;
    unsigned int unknown024;
    unsigned int unknown028;
    unsigned int unknown02c;
    unsigned int unknown030;
    unsigned int unknown034;
    unsigned int unknown038;
    unsigned int unknown03c;
    unsigned int unknown040;
    unsigned int unknown044;
    unsigned int unknown048;
    unsigned int unknown04c;
    unsigned int unknown050;
    unsigned int unknown054;
    unsigned int unknown058;
    unsigned int unknown05c;
    unsigned int unknown060;
    unsigned int unknown064;
    unsigned int unknown068;
    unsigned int unknown06c;
    unsigned int unknown070;
    unsigned int unknown074;
    unsigned int unknown078;
    unsigned int unknown07c;
    unsigned int unknown080;
    unsigned int unknown084;
    unsigned int unknown088;
    unsigned int unknown08c;
    unsigned int unknown090;
    unsigned int unknown094;
    unsigned int unknown098;
    unsigned int unknown09c;
    unsigned int unknown0a0;
    unsigned int unknown0a4;
    unsigned int unknown0a8;
    unsigned int unknown0ac;
    unsigned int unknown0b0;
    unsigned int unknown0b4;
    unsigned int unknown0b8;
    unsigned int unknown0bc;
    unsigned int unknown0c0;
    unsigned int unknown0c4;
    unsigned int unknown0c8;
    unsigned int unknown0cc;
    unsigned int unknown0d0;
    unsigned int unknown0d4;
    unsigned int unknown0d8;
    unsigned int unknown0dc;
    unsigned int unknown0e0;
    unsigned int unknown0e4;
    unsigned int unknown0e8;
    unsigned int unknown0ec;
    unsigned int unknown0f0;
    unsigned int unknown0f4;
    unsigned int unknown0f8;
    unsigned int unknown0fc;
    unsigned int unknown100;
    unsigned short unknown104;
    unsigned short pixelCount;
    unsigned char bitsPerPixel;
    unsigned char unknown109;
    unsigned short unknown10a;
    unsigned int unknown10c;
    unsigned int unknown110;
    unsigned int unknown114;
    unsigned int unknown118;
    unsigned int unknown11c;
    unsigned int unknown120;
    unsigned int unknown124;
    unsigned int unknown128;
    unsigned int unknown12c;
    unsigned int unknown130;
    unsigned int unknown134;
    unsigned int unknown138;
    unsigned int unknown13c;
    unsigned int unknown140;
    unsigned int unknown144;
    unsigned int unknown148;
    unsigned int unknown14c;
    unsigned int unknown150;
    unsigned int unknown154;
    unsigned int unknown158;
    unsigned int unknown15c;
    unsigned int inputCapacity;
    unsigned char* inputBuffer;
    unsigned int outputCapacity;
    PixelRow4* outputBuffer;
    void ReadPixels(S_00a8d8b0* stream);
};
inline NiRefObject::~NiRefObject() {
    InterlockedDecrement(&DAT_011f4400);
}
struct StringHandle_a8f {
    volatile long* value;
    ~StringHandle_a8f() throw() {
        if (value != DAT_0109b220)
            InterlockedDecrement(value - 2);
    }
};
class FUN_00a8f490 : public NiRefObject {
public:
    virtual ~FUN_00a8f490();
    StringHandle_a8f m_08;
};
struct FUN_00a923a0_class {
    unsigned short __thiscall NiParticlesData_GetActiveVertexCount();
};
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
#include <math.h>
extern "C" float epsilon;
struct FUN_00a88970_q { float w, x, y, z; void Set(float fW, float fX, float fY, float fZ); };
struct FUN_00a88970_v { void* m_pvVtbl; float x, y, z; };
FUN_00a88970_q NiQuaternion_Exp(const FUN_00a88970_v& v);
struct FUN_00a81a40_shell {
    int __thiscall NiTaskManager_GetNumTasks(int ai);
};
void* NiMalloc(unsigned int uiSize);
struct FUN_00a8a620 {
    unsigned int m_uiSize;
    void* m_pBuffer;
    void* m_pCursor;
    int m_iUsed;

    FUN_00a8a620(unsigned int uiSize);
};

struct P03MM { void* Allocate(unsigned int); };


struct SpawnedRecord {
    int m_p;
    short m_s1;
    short m_s2;
    int m_i1;
    int m_i2;
    int m_i3;
    SpawnedRecord() throw();
    ~SpawnedRecord() {}
    static void* operator new[](unsigned int size) throw() { return reinterpret_cast<P03MM*>(&DAT_011f6238)->Allocate(size); }
};

// @fnv 0x00a90290
// src: GUESS 0x00a90290 (confidence: low)
SpawnedRecord* Runtime_GetIndexedValue_00a90290(unsigned int n) {
    return new SpawnedRecord[n];
}
