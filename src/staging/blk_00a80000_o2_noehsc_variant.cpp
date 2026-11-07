#include "../../include/NiTArray.h"

// src/staging/blk_00a80000_o2_noehsc_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/staging/blk_00a80000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00a80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include <stddef.h>
#include "../../include/MemoryManager.h"
#include "../../include/NiParticleMeshes.h"
#include "../../include/NiDirectionalLight.h"
#include "../../include/BSFadeNode.h"
#include "../../include/NiAlphaAccumulator.h"
#include "../../include/NiCollisionObject.h"
#include "../../include/NiCullingProperty.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiLODData.h"
#include "../../include/NiPixelData.h"
#include "../../include/NiProperty.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiPixelFormat.h"
#include "../../include/NiTFixedStringMap_NiAVObject___.h"
extern "C" void __cdecl _Call_a5d3a0();
extern const void* NiCollisionObject_vftable;
extern unsigned char* DAT_011f5b04;
void __cdecl NiParallelUpdateTaskManager_WaitRenderSema(int);
void __cdecl NiParallelUpdateTaskManager_BeginUpdate();
int __cdecl NiSkinData_BoneVertData_Compare(const unsigned short* a, const unsigned short* b);
struct FUN_00a744a0
{
    void Init();
};
extern const void* DAT_0109e984;
BSFadeNode* NiScreenElements_CreateObject();
struct FUN_00a87900_class
{
    void NiScreenElementsData_UpdateBound();
};
extern int DAT_011f5b84;
void __cdecl InitializeGameSystems();
void __cdecl NiMainSDM_Shutdown();
void __cdecl NiStaticDataManager_SetRootLibrary(void*, void*);
struct FUN_00a8a5f0_class
{
    void* UpdateState_00a8a5f0();
};
struct FUN_00a8f060_class
{
    void NiPixelData_FreeData();
};
extern "C" void NiFreeAlias(void*);
struct FUN_00a8f080_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void SetValues(int a, int b);
};
struct SdmBase;
extern SdmBase* DAT_011f5e34;
struct FUN_00a8f730
{
    void __thiscall Release();
};
extern char DAT_011f5d30;
int __cdecl GetGlobalDataPtr();
extern int DAT_011f5e44;
extern int DAT_011f5e4c;
void ResetStreamLinkIDSet();
extern int DAT_0109f814;
struct FUN_00a8ff50
{
    int m_p;
    short m_s1;
    short m_s2;
    int m_i1;
    int m_i2;
    int m_i3;
    FUN_00a8ff50();
};
void __cdecl NiFreeAlias(void*);
struct FUN_00a96440_class
{
    char m_auiShapeKeys[0x4c];
    void* m_pField;
    void SetField(void* pNew);
};
void NiFree(void*);
struct FUN_00a96460_class
{
    char pad[0x54];
    void* m_0x54;
    void NiParticlesData_ReplaceSizes(void* p);
};
void NiFreeAlias(void*);
struct FUN_00a96480_Class
{
    void* m_5c;
    void NiParticlesData_ReplaceRotationAngles(void* p);
};
extern "C" void __cdecl NiFreeAlias(void*);
struct FUN_00a964a0_Class
{
    void* m_p;
    void NiParticlesData_ReplaceTextureIndices(void* p);
};
struct NiBinaryExtraData;
struct NiFloatsExtraData;
struct FUN_00a99c40_shell : public NiExtraData
{
    void NiIntegerExtraData_CopyMembers(NiBinaryExtraData* dst, CloningProcess* cp);
};
extern const void* DAT_0109e47c;
BSFadeNode* NiSkinPartition_CreateObject();
unsigned int __cdecl NiString_GetBestBufferSize(unsigned int a);
extern int DAT_0109fb94;
void* __cdecl NiVectorExtraData_CreateObject();
extern int DAT_010a02e4;
NiProperty* __cdecl NiSpecularProperty_CreateObject();
extern const void* DAT_010a0a6c;
NiParticleMeshes* __cdecl NiParticleMeshes_CreateObject();
void __cdecl NiFree(void*);
void* __cdecl NiMalloc(unsigned int);
struct FUN_00a99800_shell
{
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
struct FUN_00a9be80
{
    const void* m_vft;
    int m_ref;
    int m_data;
    FUN_00a9be80(int data);
};
extern volatile long DAT_011f4400;
extern const void* DAT_010a1478;
extern const void* vftable_NiRefObject;
struct FUN_00a84c90_class
{
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
struct FUN_00a85520_class
{
    void FUN_00a85520(float* dst, float scale);
};
extern const void* DAT_0109e834;
struct FUN_00a87140_class
{
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
struct FUN_00a94c00_shell
{
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
struct FUN_00a96800_shell
{
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
struct FUN_00a81bd0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void UpdateState_00a81bd0();
};
struct Stub
{
    void NiTStringPointerMap_NiAVObject_RemoveAt(void* p);
};
extern int DAT_0109f73c;
extern void* _EmptyFS;
extern int(__stdcall* DAT_00fdf1c4)(void*);
extern const void* vftable_NiRefObject;
struct FUN_00a8f810_class
{
    void SetVtableAndProcessState_00a8f810();
};
void __cdecl NiFree(void*);
struct FUN_00a8a670_shell
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void ForwardCall_00a8a670();
};
extern const void* vftable_SdmDerived;
extern const void* vftable_SdmBase;
void _NiFree(void*);
extern MemoryManager _g_memoryManager;
struct SdmDerived
{
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
struct FUN_00a5a390_shell
{
    void DestroyFogProperty();
    FUN_00a5a390_shell* FUN_00a950f0(bool bDel);
};
void __cdecl operator delete(void* p, unsigned int);
void __cdecl NiShaderConstantMapEntry_InitializeAttribTable();
void __cdecl NiShaderConstantMapEntry_SDMInit_NiShaderConstantMapEntry_InitializeObjectTable();
void __cdecl NiShaderConstantMapEntry__SDMInit();
extern int DAT_0109e04c;
struct FUN_00a80580_sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    void Cleanup();
};
struct FUN_00a80580_cls
{
    void* m_vptr;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98;
    FUN_00a80580_sub m_sub9c;
    NiRefObject* m_b8;
    NiRefObject* m_bc;

    void BaseTeardown();
    void UpdateFields_00a80580();
};
extern const void* DAT_0109e174;
void FUN_00a5d3d0();
struct FUN_00a80fc0_class
{
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
struct S_a819e0_O
{
    virtual ~S_a819e0_O()
    {}
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
struct FUN_00a84ca0_entry
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
    void* unk44;
    int unk48;
};
extern MemoryManager g_memoryManager;
struct FUN_00a84ca0_class
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
    void* m_40;
    unsigned int m_44;

    void FreeEntryResources();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
struct RefCountedObject
{
    virtual void UnknownVirtual();
    virtual void DeleteThis();
    volatile long referenceCount;
};
struct CloneObject
{
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
struct FUN_00a88c60_Point2
{
    float unk00;
    float unk04;

    bool __thiscall ForwardCall_0051c330(const FUN_00a88c60_Point2* other);
};
struct FUN_00a88c60_Class
{
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
void NiCompUtility_DecompressFloatArray(const short* psCompressed, unsigned int uiUnused, float fProjectionAlongAim, float fHalfRange,
                  float* pfValues, unsigned int ItemUpdateArray);
struct FUN_00a89760_base
{
    virtual ~FUN_00a89760_base();
};
struct FUN_00a89760_cls : FUN_00a89760_base
{
    virtual ~FUN_00a89760_cls();
};
struct BaseCls
{
    void __thiscall FUN_00a67b20(int, int, int, int, int, int, int);
};
extern "C" void* __cdecl _NiMalloc_00aa1070(int);
extern int DAT_0109f23c;
struct FUN_00a8a680_cls
{
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
struct DecodePair
{
    unsigned char first, second;
};
struct Decoder
{
    unsigned int unk00, unk04;
    unsigned char* input;
    unsigned int unk0c;
    DecodePair table[256];
    void DecodeToOutput(unsigned int* output);
};
struct BlockColorDecoder
{
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
struct A8BD20Entry
{
    unsigned char m_ucLow;
    unsigned char m_ucHigh;
};
class FUN_00a8bd20
{
  public:
    int unk00;
    void (*m_pfnCallback)();
    int unk08;
    int unk0C;
    A8BD20Entry m_akTable[256];

    FUN_00a8bd20();
};
extern "C" void __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int size);
struct FUN_00a8bdf0_cls
{
    void(__thiscall* m_00)(FUN_00a8bdf0_cls* self, unsigned char* out);
    void(__thiscall* m_04)(FUN_00a8bdf0_cls* self, unsigned char* out);
    int m_08;
    int m_0c;
    void CopyGeneratedRows(unsigned char* dst, unsigned int a2, unsigned int count);
};
class FUN_00a8f140_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiRefObject* m_10;

    void SetRefObject(NiRefObject* obj);
};
struct S_00a8f2c0_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
extern const void* DAT_0109f4dc;
struct S_00a8f2c0_Sub
{
    int unk00;
    void FUN_00a5f860(S_00a8f2c0_Arg* c);
};
struct S_00a8f2c0_Obj
{
    void* vft;
    int unk04;
    int unk08;
    int unk0c;
    S_00a8f2c0_Sub sub;
    static void* operator new(unsigned int n)
    {
        return BSFadeNode::operator new(n);
    }
    S_00a8f2c0_Obj() throw()
    {
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
struct FUN_00a910f0_class
{
    void* vft;
    void* buffer;
    FUN_00a910f0_class* FUN_00a910f0(unsigned char flags);
};
struct FUN_00aa4060_class
{
    void MemoryManager_Deallocate(void* object);
};
extern FUN_00aa4060_class DAT_011f6238;
struct NiParticleBase
{
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
struct NiParticleBuffer
{
    void* data;
    unsigned int count;
    unsigned short capacity;
    unsigned short used;
    unsigned short growth;
    unsigned short flags;
    void __thiscall FUN_0060bef0(int);
};
struct NiParticleSubobject
{
    void* first;
    void* second;
    void* third;
    void* fourth;
    void __thiscall FUN_00a69940();
};
struct NiParticleObject : NiParticleBase
{
    NiParticleBuffer buffer;
    NiParticleSubobject firstMember;
    NiParticleSubobject secondMember;
};
extern void* __cdecl Object_DispatchCommandFour(unsigned int);
extern const char DAT_010a1024;
NiParticleObject* __cdecl CreateNiParticleObject();
extern int DAT_010a13ac;
void __declspec(noreturn) FUN_00aa0dc0();
struct FUN_00a9b4a0_Class
{
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
        if (value != next)
        {
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

struct MemMgr : MemoryManager
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
void __cdecl NiFree(void* p);

struct WeightEntry
{
    unsigned int index;
    float weight;
};

struct WeightArray
{
    WeightEntry* m_data;
    unsigned int m_pRayCursor;
    unsigned int m_iElementCount;

    WeightArray() throw();
    ~WeightArray()
    {
        NiFree(m_data);
    }
    void SetCapacity(unsigned int cap);
    void Normalize();

    void Add(const WeightEntry& entry)
    {
        if (m_iElementCount == m_pRayCursor)
            SetCapacity(m_pRayCursor > 0 ? m_pRayCursor * 2 : 1);
        m_data[m_iElementCount] = entry;
        m_iElementCount++;
    }

    static void* operator new[](unsigned int size)
    {
        return static_cast<MemMgr&>(g_memoryManager).Allocate(size);
    }
    static void operator delete[](void* p)
    {
        static_cast<MemMgr&>(g_memoryManager).Deallocate(p);
    }
};

struct BoneWeight
{
    unsigned short vertex;
    unsigned short pad02;
    float weight;
};

struct SkinBone
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
    BoneWeight* weights;
    unsigned short weightCount;
    unsigned short unk4A;
};

struct SkinData
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
    SkinBone* bones;
    unsigned int boneCount;
};

// @fnv 0x00a84810
// src: COMMUNITY 0x00a84810
WeightArray* __stdcall NiSkinPartition_CreateVertexInteractions(unsigned int vertexCount, SkinData* skin)
{
    WeightArray* arrays = new WeightArray[vertexCount];
    unsigned int boneCount = skin->boneCount;
    for (unsigned int i = 0; i < boneCount; i++)
    {
        SkinBone* bone = &skin->bones[i];
        for (unsigned int j = 0; j < bone->weightCount; j++)
        {
            WeightEntry entry;
            entry.index = i;
            entry.weight = bone->weights[j].weight;
            arrays[bone->weights[j].vertex].Add(entry);
        }
    }
    for (unsigned int k = 0; k < vertexCount; k++)
    {
        if (arrays[k].m_iElementCount == 0)
        {
            delete[] arrays;
            return 0;
        }
        arrays[k].Normalize();
        arrays[k].Normalize();
    }
    return arrays;
}

void __cdecl _NiFree_00aa10f0(void* p);  // NiFree

struct S911d0_Entry
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_pkName0;
    void* m_pkName1;
    void* m_pkName2;
};

class S911d0_EntryPool
{
  public:
    void FindOrAdd(S911d0_Entry** ppkEntry);  // Delete
};
extern S911d0_EntryPool* DAT_011f5e50;



template <class T, class A> inline NiTArray<T,A>::~NiTArray() { _NiFree_00aa10f0(m_pBase); }
template <class T, class A> inline unsigned int NiTArray<T,A>::GetSize() const { return m_usSize; }
template <class T, class A> inline const T& NiTArray<T,A>::GetAt(unsigned int i) const { return m_pBase[i]; }
template <class T, class A> inline T& NiTArray<T,A>::GetAt(unsigned int i) { return m_pBase[i]; }
template <class T, class A> inline void NiTArray<T,A>::SetAt(unsigned int uiIndex,const T& element) {
 if(uiIndex>=m_usSize) { m_usSize=(unsigned short)(uiIndex+1);if(element!=0)m_usESize++; }
 else if(element!=0) { if(m_pBase[uiIndex]==0)m_usESize++; }
 else if(m_pBase[uiIndex]!=0)m_usESize--;
 m_pBase[uiIndex]=element;
}
class S911d0_Base
{
  public:
    virtual ~S911d0_Base();  // FUN_00a7b8c0
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
};

class FUN_00a911d0 : public S911d0_Base
{
  public:
    virtual ~FUN_00a911d0();
    NiTArray<S911d0_Entry*, NiTMallocInterface<S911d0_Entry*> > m_kEntries;
};

// @fnv 0x00a911d0
FUN_00a911d0::~FUN_00a911d0()
{
    for (unsigned int i = 0; i < m_kEntries.GetSize(); i++)
    {
        S911d0_Entry* pkEntry = m_kEntries.GetAt(i);
        m_kEntries.SetAt(i, 0);
        if (pkEntry)
        {
            DAT_011f6238.MemoryManager_Deallocate(pkEntry->m_pkName0);
            DAT_011f6238.MemoryManager_Deallocate(pkEntry->m_pkName1);
            DAT_011f6238.MemoryManager_Deallocate(pkEntry->m_pkName2);
            S911d0_Entry* pkDelete = pkEntry;
            DAT_011f5e50->FindOrAdd(&pkDelete);
        }
    }
    m_kEntries.FUN_00a90180(0);
}

extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);
extern int DAT_010a2484;
extern const NiPixelFormat DAT_011aa210;
extern const NiPixelFormat DAT_011aa2e8;
extern const NiPixelFormat DAT_011aa2a0;
typedef NiPalette::PaletteColorEntry BmpColor;
// These operations are inline in this unit in the original binary.
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}
inline void NiPixelData::SetPalette(NiPalette* p)
{
    NiPalette* palette = static_cast<NiPalette*>(m_spPalette.value);
    if (palette != p)
    {
        if (palette)
            static_cast<NiRefObject*>(palette)->DecRefCount();
        m_spPalette.value = p;
        if (m_spPalette.value)
            static_cast<NiRefObject*>(static_cast<NiPalette*>(m_spPalette.value))->IncRefCount();
    }
}

struct BmpStream
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Seek(int, int);
    unsigned int position;
    unsigned int(__cdecl* read)(BmpStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* dst, unsigned int size)
    {
        unsigned int component = 1;
        position += read(this, dst, size, &component, 1);
    }
};
struct BmpReader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Header(BmpStream&, unsigned int&, unsigned int&, NiPixelFormat&, bool&, unsigned int&);
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
    unsigned int width, height;
    NiPixelFormat format;
    unsigned short bpp;
    unsigned int colorCount, dataOffset;
    bool flip;
    NiPixelData* AllocateStorage_00a8e810(BmpStream& stream, NiPixelData* optional);
};
// @fnv 0x00a8e810
// src: GUESS 0x00a8e810 (confidence: low)
NiPixelData* BmpReader::AllocateStorage_00a8e810(BmpStream& stream, NiPixelData* optional)
{
    bool mipmap;
    unsigned int w, h, faces;
    NiPixelFormat headerFormat;
    DAT_00fdf05c(&unk080);
    if (!Header(stream, w, h, headerFormat, mipmap, faces))
    {
        DAT_00fdf100(&unk080);
        return 0;
    }
    NiPixelData* dest;
    if (optional && optional->m_puiWidth[0] == width && optional->m_puiHeight[0] == height && optional->m_kPixelFormat == format)
        dest = optional;
    else
        dest = new NiPixelData(width, height, format);
    if (format == DAT_011aa210)
    {
        BmpColor colors[256];
        stream.Read(colors, colorCount * sizeof(BmpColor));
        BmpColor* color = colors;
        for (unsigned int i = 0; i < colorCount; ++i, ++color)
        {
            unsigned char temp = color->r;
            color->r = color->b;
            color->b = temp;
            color->a = 255;
        }
        dest->SetPalette(new NiPalette(false, 256, colors));
    }
    else
    {
        stream.Seek(colorCount * sizeof(BmpColor), DAT_010a2484);
    }
    int extra = dataOffset - 54 - colorCount * sizeof(BmpColor);
    if (extra > 0)
        stream.Seek(extra, DAT_010a2484);
    unsigned int imageSize = (((width * bpp + 31) & ~31) >> 3) * height;
    unsigned int rowSize = dest->m_puiWidth[0] * dest->m_uiPixelStride;
    if (bpp == 4)
    {
        unsigned int packedSize = (width >> 1) + (width & 1);
        unsigned int padding = (packedSize & 3) ? 4 - (packedSize & 3) : 0;
        unsigned char* input = (unsigned char*)NiMalloc(packedSize + padding);
        unsigned char* row;
        int step;
        if (flip)
        {
            row = dest->Pixels() + rowSize * (dest->m_puiHeight[0] - 1);
            step = -(int)rowSize;
        }
        else
        {
            row = dest->Pixels();
            step = rowSize;
        }
        for (unsigned int y = 0; y < height; ++y, row += step)
        {
            stream.Read(input, packedSize + padding);
            unsigned char* out = row;
            unsigned char* in = input;
            for (unsigned int x = 0; x < packedSize; ++x)
            {
                *out++ = *in >> 4;
                *out++ = *in & 15;
                ++in;
            }
        }
        NiFree(input);
    }
    else
    {
        if (flip)
        {
            unsigned char* row = dest->Pixels() + rowSize * (height - 1);
            unsigned int y;
            if (rowSize & 3)
            {
                unsigned int padding = 4 - (rowSize & 3);
                unsigned char dummy[4];
                for (y = 0; y < height; ++y)
                {
                    stream.Read(row, rowSize);
                    stream.Read(dummy, padding);
                    row -= rowSize;
                }
            }
            else
            {
                for (y = 0; y < height; ++y)
                {
                    stream.Read(row, rowSize);
                    row -= rowSize;
                }
            }
        }
        else
        {
            if (rowSize & 3)
            {
                unsigned int padding = 4 - (rowSize & 3);
                unsigned char* row = dest->Pixels();
                unsigned char dummy[4];
                for (unsigned int y = 0; y < height; ++y, row += rowSize)
                {
                    stream.Read(row, rowSize);
                    stream.Read(dummy, padding);
                }
            }
            else
            {
                stream.Read(dest->Pixels(), imageSize);
            }
        }
    }
    if (format == DAT_011aa2e8 || format == DAT_011aa2a0)
    {
        unsigned int pixelStride = dest->m_uiPixelStride;
        unsigned int count = width * height;
        unsigned char* pixel = dest->Pixels();
        for (unsigned int i = 0; i < count; ++i, pixel += pixelStride)
        {
            unsigned char swap = pixel[0];
            pixel[0] = pixel[2];
            pixel[2] = swap;
        }
    }
    DAT_00fdf100(&unk080);
    return dest;
}

inline void* operator new[](unsigned int size, int) throw()
{
    return static_cast<MemMgr&>(g_memoryManager).Allocate(size);
}

struct Interaction
{
    unsigned int bone;
    float weight;
};

struct TempRecord
{
    void* data;
    unsigned int size;
    unsigned int count;
    ~TempRecord()
    {
        NiFree(data);
    }
    static void operator delete[](void* block)
    {
        g_memoryManager.Deallocate(block);
    }
};

struct Holder
{
    void* data;
    unsigned int size;
    unsigned int count;
    unsigned short index;
    unsigned short flags;
    ~Holder()
    {
        NiFree(data);
    }
    static void operator delete(void* block)
    {
        g_memoryManager.Deallocate(block);
    }
    bool ContainsSortedSubset(const Holder* other);
};

__declspec(noinline) bool Holder::ContainsSortedSubset(const Holder* other)
{
    unsigned int i = 0;
    for (unsigned int j = 0; j < other->count; ++j, ++i)
    {
        while (i < count &&
               static_cast<const unsigned short*>(data)[i] < static_cast<const unsigned short*>(other->data)[j])
            ++i;
        if (i == count ||
            static_cast<const unsigned short*>(data)[i] != static_cast<const unsigned short*>(other->data)[j])
            return false;
    }
    return true;
}

struct SourceGeometry
{
    unsigned int unk00, unk04;
    unsigned short vertexCount, unk0a;
    unsigned int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned short triangleCount, unk42;
    unsigned short GetCount() const
    {
        return vertexCount;
    }
    unsigned short GetTriangleCount() const
    {
        return triangleCount;
    }
};

struct SkinBuildData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned short unk1c;
    unsigned short triangleTotal;
    unsigned int unk20;
    unsigned short influencesPerVertex;
    unsigned short unk26;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int boneCount;
};

struct C082d30
{
    void* data;
    unsigned int size;
    unsigned int count;
    void AppendMatchingIndices(int, void*, unsigned int);
    void Grow(unsigned int);
};

__declspec(noinline) void C082d30::AppendMatchingIndices(int partition, void* assignments, unsigned int triangleTotal)
{
    const int* map = static_cast<const int*>(assignments);
    for (unsigned int triangle = 0; triangle < triangleTotal; ++triangle)
    {
        if (map[triangle] != partition)
            continue;
        if (count == size)
            Grow(size == 0 ? 1 : 2 * size);
        static_cast<unsigned short*>(data)[count] = static_cast<unsigned short>(triangle);
        ++count;
    }
}

struct FUN_00a81ba0
{
    void* m_pVTable;
    unsigned short* m_04;
    float* m_08;
    unsigned short* m_0c;
    unsigned char* m_10;
    unsigned short* m_14;
    unsigned short* m_18;
    unsigned short unk1c;
    unsigned short triangleTotal;
    unsigned short unk20;
    volatile unsigned short m_22;
    unsigned short influencesPerVertex;
    unsigned short unk26;
    unsigned int m_28;

    FUN_00a81ba0() throw();
    ~FUN_00a81ba0()
    {}
    unsigned short* BuildVertexRemapTable(C082d30*, SourceGeometry*);
    void BuildTriangleList(C082d30*, SourceGeometry*, unsigned short*);
    void PopulateSkinData(C082d30*, Holder*, SourceGeometry*, TempRecord*, bool, bool, unsigned char, unsigned int);
};
typedef FUN_00a81ba0 OutputRecord;

void __cdecl _memmove(void*, const void*, unsigned int);

struct HolderArray
{
    Holder** volatile data;
    unsigned int capacity;
    unsigned int count;
};

struct GeometryBuilder
{
    unsigned int unk00, unk04, count;
    OutputRecord* output;
    TempRecord* NiSkinPartition_CreateVertexInteractions(unsigned int, SkinBuildData*);
    bool ReduceGroupWeights(SourceGeometry*, unsigned char, unsigned char, TempRecord*);
    bool BuildTriangleSetMapping(SourceGeometry*, SkinBuildData*, unsigned char, TempRecord*, HolderArray*, void**,
                      OutputRecord**);
    bool NiSkinPartition_MakePartitions(SourceGeometry*, SkinBuildData*, unsigned char, unsigned char, bool, OutputRecord**,
                      unsigned short*, unsigned char*);
};

__declspec(noinline) void FUN_00a81ba0::PopulateSkinData(C082d30* triangles, Holder* bones, SourceGeometry* geometry,
                                                         TempRecord* interactions, bool padBones, bool makePalette,
                                                         unsigned char width, unsigned int totalBones)
{
    unsigned int paletteCount = bones->count;
    if (paletteCount < width)
        paletteCount = width;
    unk20 = static_cast<unsigned short>(paletteCount);
    triangleTotal = static_cast<unsigned short>(triangles->count);
    m_04 = static_cast<unsigned short*>(NiMalloc(2 * unk20));
    for (unsigned int i = 0; i < unk20; ++i)
        m_04[i] = i < bones->count ? static_cast<unsigned short*>(bones->data)[i] : 0;
    unsigned short* translation = BuildVertexRemapTable(triangles, geometry);
    BuildTriangleList(triangles, geometry, translation);
    NiFree(translation);
    float* destination;
    if (padBones)
    {
        influencesPerVertex = width;
        unsigned int count = influencesPerVertex * unk1c;
        m_08 = static_cast<float*>(NiMalloc(sizeof(float) * count));
        m_10 = static_cast<unsigned char*>(NiMalloc(count));
        unsigned int* remap = static_cast<unsigned int*>(NiMalloc(sizeof(unsigned int) * totalBones));
        for (unsigned int bone = 0; bone < bones->count; ++bone)
            remap[m_04[bone]] = bone;
        destination = m_08;
        unsigned char* palette = m_10;
        float* weights = static_cast<float*>(NiMalloc(sizeof(float) * influencesPerVertex));
        unsigned char* paletteIndices = static_cast<unsigned char*>(NiMalloc(influencesPerVertex));
        for (unsigned int vertex = 0; vertex < unk1c; ++vertex)
        {
            const TempRecord& record = interactions[m_0c[vertex]];
            const Interaction* entries = static_cast<const Interaction*>(record.data);
            unsigned int slot = 0;
            for (; slot < record.count; ++slot)
            {
                weights[slot] = entries[slot].weight;
                paletteIndices[slot] = static_cast<unsigned char>(remap[entries[slot].bone]);
            }
            for (; slot < influencesPerVertex; ++slot)
            {
                weights[slot] = 0.0f;
                paletteIndices[slot] = 0;
            }
            for (unsigned int outputSlot = 0; outputSlot < influencesPerVertex; ++outputSlot)
            {
                unsigned int selected = 0;
                float largest = weights[0];
                for (unsigned int candidate = 1; candidate < influencesPerVertex; ++candidate)
                {
                    if (weights[candidate] > largest)
                    {
                        selected = candidate;
                        largest = weights[candidate];
                    }
                }
                *destination++ = weights[selected];
                *palette++ = paletteIndices[selected];
                weights[selected] = -1.0f;
            }
        }
        NiFree(weights);
        NiFree(paletteIndices);
        NiFree(remap);
    }
    else
    {
        influencesPerVertex = unk20;
        unsigned int count = influencesPerVertex * unk1c;
        m_08 = static_cast<float*>(NiMalloc(sizeof(float) * count));
        destination = m_08;
        for (unsigned int vertex = 0; vertex < unk1c; ++vertex)
        {
            const TempRecord& record = interactions[m_0c[vertex]];
            const Interaction* entries = static_cast<const Interaction*>(record.data);
            unsigned int slot = 0;
            for (; slot < bones->count; ++slot)
            {
                float weight = 0.0f;
                unsigned int bone = static_cast<const unsigned short*>(bones->data)[slot];
                for (unsigned int interaction = 0; interaction < record.count; ++interaction)
                {
                    if (entries[interaction].bone == bone)
                    {
                        weight = entries[interaction].weight;
                        break;
                    }
                }
                *destination++ = weight;
            }
            for (; slot < unk20; ++slot)
                *destination++ = 0.0f;
        }
        if (makePalette)
        {
            m_10 = static_cast<unsigned char*>(NiMalloc(count));
            unsigned char* palette = m_10;
            for (unsigned int vertex = 0; vertex < unk1c; ++vertex)
                for (unsigned int bone = 0; bone < unk20; ++bone)
                    *palette++ = static_cast<unsigned char>(bone);
        }
    }
}

// @fnv 0x00a84980
// src: COMMUNITY 0x00a84980
bool GeometryBuilder::NiSkinPartition_MakePartitions(SourceGeometry* source, SkinBuildData* other, unsigned char first,
                                   unsigned char second, bool mode, OutputRecord** outputs, unsigned short* indices,
                                   unsigned char* changes)
{
    HolderArray holders = {0, 0, 0};
    void* data;
    TempRecord* records = NiSkinPartition_CreateVertexInteractions(source->GetCount(), other);
    if (!records)
    {
        NiFree(records);
        return false;
    }

    bool success = ReduceGroupWeights(source, first, second, records);
    if (success)
    {
        success = BuildTriangleSetMapping(source, other, first, records, &holders, &data, outputs);
        if (outputs && indices && changes)
        {
            for (unsigned int i = 0; i < holders.count; ++i)
            {
                Holder** entries = holders.data;
                Holder* current = entries[i];
                indices[i] = current->index;
                if (i)
                {
                    Holder* previous = entries[i - 1];
                    if (current->ContainsSortedSubset(previous) && current->count == previous->count)
                        changes[i] = 0;
                    else
                        changes[i] = 1;
                }
                else
                {
                    changes[0] = 1;
                }
            }
        }
        OutputRecord* result = new (0) OutputRecord[count];
        bool padBones = (first != second);
        C082d30 scratch;
        scratch.data = 0;
        scratch.size = 0;
        scratch.count = 0;
        for (unsigned int i = 0; i < count; ++i)
        {
            scratch.AppendMatchingIndices(i, data, source->GetTriangleCount());
            Holder* current = const_cast<Holder**&>(holders.data)[i];
            result[i].PopulateSkinData(&scratch, current, source, records, padBones, mode, second,
                                       (*(SkinBuildData* volatile*)&other)->boneCount);
            scratch.count = 0;
            delete current;
        }
        NiFree(data);
        while (count)
        {
            unsigned int i = 0;
            for (; i < count; ++i)
            {
                if (!(unsigned short)result[i].unk1c)
                {
                    for (unsigned int j = i; j < count - 1; ++j)
                    {
                        _memmove(&result[j], &result[j + 1], sizeof(OutputRecord));
                        outputs[j] = outputs[j + 1];
                        indices[j] = indices[j + 1];
                        changes[j] = changes[j + 1];
                    }
                    --count;
                    break;
                }
            }
            if (i == count)
                break;
        }
        output = result;
        NiFree(scratch.data);
    }
    delete[] records;
    NiFree(holders.data);
    return success;
}
