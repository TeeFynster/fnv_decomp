#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4

// src/staging/blk_00c60000_od_o2_gf_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy /GF (unit src/staging/blk_00c60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_00c60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/hkVector4.h"
#include "../../include/BSDecalPlacementVectorExtraData.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiObject.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiPSysModifier.h"
#include "../../include/NiColorA.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiBinaryExtraData.h"
#include "../../include/NiPSysCylinderEmitter.h"
#include "../../include/NiPSysVolumeEmitter.h"
#include "../../include/NiPSysPositionModifier.h"
#include "../../include/NiStream.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPSysData.h"
#include "../../include/BSPSysSimpleColorModifier.h"
#include "../../include/NiTArray.h"
extern "C" void* g_01204388;
struct FUN_00c600f0_Class
{
    void* __thiscall BSPSysStripUpdateModifier_GetRTTI();
};
struct FUN_00c60930_class
{
    void FUN_00c31670(void*);
    void BSPSysSimpleColorModifier_RegisterStreamables(void* a);
};
extern "C" void* g_01204390;
struct FUN_00c60d40_Class
{
    void* __thiscall BSPSysSimpleColorModifier_GetRTTI();
};
struct FUN_00c61420_Class
{
    void* __thiscall BSWArray_CreateClone(void* p);
};
struct FUN_00a99870_Class
{
    void __thiscall CopyMembers_00a99870(int, int);
};
// src: XBOX_PDB 0x00a99870
void __thiscall FUN_00a99870_Class::CopyMembers_00a99870(int, int)
{}
struct FUN_00c61430_Class
{
    void __thiscall ForwardCall_00c61430(int, int);
};
struct FUN_00c61450_Class
{
    void FUN_00a99a90(int);
    void BSWArray_LoadBinary(int a);
};
struct FUN_00a9af00_class
{
    void NiBinaryExtraData_LinkObject(int a);
};
struct FUN_00c61470_class : FUN_00a9af00_class
{
    void CallBaseWithArg(int a);
};
struct FUN_00c61490_Class
{
    bool RegisterStreamables_00a89ae0(const void* arg);
    bool IsNot(const void* arg);
};
struct FUN_00c614c0_Class
{
    void __thiscall SaveBinary_00a89210(void*);
    void __thiscall BSWArray_SaveBinary(void* ap);
};
struct FUN_00c614e0_Class
{
    char IsEqual_00a998e0(int arg);
    char BSWArray_IsEqual(int arg);
};
extern NiFixedString* DAT_012043a0;
extern "C" void* g_012043a4;
struct FUN_00c61810_class
{
    void* BSWArray_GetRTTI();
};
struct FUN_00c61820_class
{
    void* PArrayPoint_Copy(int);
};
struct FUN_00c61f60_class
{
    void __thiscall NiPSysAirFieldModifier_RegisterStreamables(int);
    void __thiscall BSPSysArrayEmitter_RegisterStreamables(int);
};
struct FUN_00c61f80_cls
{
    void FUN_00c31b60(void* apParam);
    void BSPSysArrayEmitter_SaveBinary(void* apParam);
};
struct FUN_00c627e0_Class
{
    void __thiscall BSPSysArrayEmitter_SetupArray();
    void __thiscall BSPSysArrayEmitter_SetEmitterObj(void* p);
};
extern "C" void* g_012043b8;
struct FUN_00c632e0_Class
{
    void* __thiscall PArrayPoint_GetRTTI();
};
struct FUN_00c31670_class
{
    void __thiscall FUN_00c31670(int a);
};
struct FUN_00c63950_class
{
    void __thiscall ForwardToOther(int a);
};
struct GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_012043c8;
struct FUN_00c63aa0_class
{
    GlobalObject_00a7b610* BSParentVelocityModifier_GetRTTI();
};
void __cdecl NiFixedString_CopyMemory_00c63c30(int, int);
void __cdecl CallWithSameArgumentTwice(int a);
struct FUN_00c644d0_Class
{
    unsigned char Equals(const char*);
    unsigned char BSDecalPlacementVectorExtraData_IsEqual(const char*);
};
extern "C" void* g_012043d4;
struct FUN_00c64600_Class
{
    void* __thiscall GetGlobalPointer();
};
struct FUN_00c64b70 : NiObject
{
    bool RegisterStreamables(NiStream& stream);
};
struct FUN_00c64fc0_class
{
    int __thiscall GetThisAddress(int);
};
struct C00c541e0
{
    bool FUN_00a7b3d0(int);
    bool BSAttachPoints_IsEqual(int a);
};
extern "C" void* DAT_012043f0;
struct FUN_00c657e0_class
{
    void* GetGlobalDataPtr();
};
extern "C" void NiFreeAlias(void*);
extern int DAT_010c377c;
// 0x00c62890 is the NiTArray<NiPointer<NiAVObject>, NiTMallocInterface<NiPointer<NiAVObject> > > destructor in blk_00c60000_od.cpp's overlay.
struct AVObjectArrayDestructorEntry : NiTArray<NiPointer<NiAVObject>, NiTMallocInterface<NiPointer<NiAVObject> > >
{
    void FUN_00c62890();
};
extern "C" void NiFreeAlias(void*);
extern int DAT_010c3a08;
struct FUN_00c65680_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void __thiscall FUN_00c65680();
};
struct FUN_00c600c0_class
{
    void* __thiscall UpdateState_00c5fd50();
    void* __thiscall FUN_00c600c0(unsigned int flags);
    static void __cdecl operator delete(void* p, unsigned int size);
};
struct FUN_00c613a0_Class
{
    void __thiscall FUN_00c613a0();
    void* __thiscall FUN_00c617e0(unsigned int flags);
    void operator delete(void* p, unsigned int size);
};
extern "C" void NiFree(void*);
extern MemoryManager g_memoryManager;
struct FUN_00c63210_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* __thiscall FUN_00c63210(int flag);
};
struct FUN_00a7b300_shell
{
    void __thiscall DestroyFields_00a7b300();
};
struct FUN_00c632f0_class
{
    void* __thiscall FUN_00c632f0(unsigned int flags);
};
void __cdecl operator delete(void*, int);
struct FUN_00c63840_Class : NiPSysModifier
{
    void __thiscall CopyModifierWithValue(NiPSysModifier* dst, CloningProcess* proc);
};
struct SStream;
struct SObj;
void __cdecl CallAnimCallback(SStream*, SObj*);
struct FUN_00c63970_class : NiPSysModifier
{
    void __thiscall BSParentVelocityModifier_SaveBinary(void* stream);
};
void __cdecl FUN_00c63b40(void* p);
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c64610_Class
{
    void __thiscall FUN_00c63b40();
    void* __thiscall FUN_00c64610(unsigned int flags);
};
struct FUN_00c64930_Class
{
    void BSReference_LinkObject(int a);
};
struct FUN_00c64940_Class
{
    bool BSReference_RegisterStreamables(int a);
};
struct FUN_00c64c30_Class
{
    bool __thiscall BSNodeReferences_IsEqual(int a);
};
extern int DAT_010c3384;
struct FUN_00c60240 : NiPSysPositionModifier
{
    int m_vt;
    float m_f[4];
    float m_v[4];
    float m_w[4];
    FUN_00c60240();
};
struct FUN_00c60950_class : NiPSysModifier
{
    void BSPSysSimpleColorModifier_SaveBinary(NiStream* stream);
};
int _sprintf_s(char*, unsigned int, const char*, ...);
size_t _strlen(const char*);
struct FUN_00c62090_Class
{
    char* __thiscall BuildAttachTypeString(const char* name, int type);
};
extern GlobalObject_00a7b610 g_012043b0;
struct FUN_00c63320_Class
{
    GlobalObject_00a7b610* __thiscall BSPSysArrayEmitter_GetRTTI();
};
struct FUN_00c65210_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    unsigned short m_18;
    void __thiscall BSAttachPoints_SaveBinary(NiStream& stream);
};
void __cdecl NiStreamSaveBinary_unsigned_int(NiStream& stream, const unsigned int& count);
extern "C" void* __cdecl NiMalloc(unsigned int size);
struct FUN_00c65760_Class
{
    int* m_pVtbl;
    void* m_pData;
    unsigned short m_iArrayLength;
    unsigned short m_iFlags;
    unsigned short m_iPad;
    unsigned short m_iType;
    void* __thiscall InitArray(unsigned short count, unsigned short type);
};
struct FUN_00c61b10
{
    char m_iWordAt00[0x6c];
    FUN_00c61b10();
    ~FUN_00c61b10();
    static void* operator new(unsigned int size);
};
FUN_00c61b10* BSPSysArrayEmitter_CreateObject();
extern "C" void* __cdecl NiMalloc(unsigned int);
struct FUN_00c63260_class
{
    int* m_ppVirtualMethodTable;
    void* m_data;
    unsigned short m_uiX;
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short m_uiY;
    FUN_00c63260_class(unsigned short x, unsigned short y);
};
extern NiPoint3 _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;
extern int DAT_010c37fc;
struct FUN_00c63330 : NiPSysPositionModifier
{
    FUN_00c63330();
};
int strcpy_s(char* dst, unsigned int size, const char* src);
size_t strlen(const char*);
struct FUN_00c64780_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void BSReference_SetName(const char* apName);
};
struct FUN_00c65710_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* __thiscall FUN_00c65710(unsigned int flags);
};
struct FUN_00c60000_Class
{
    bool __thiscall IsEqualWithFloat(void* arg);
};
struct FUN_00c60700_Data
{
    unsigned char padding[0x18];
    NiColorA group00;
    NiColorA group10;
    NiColorA group20;
    float value30;
    float value34;
    float value38;
    float value3c;
    float value40;
    float value44;
};
struct FUN_00c60700_Class : NiPSysModifier
{
    void BSPSysSimpleColorModifier_CopyMembers(NiPSysModifier* dst, CloningProcess& proc);
};
template <class T> void __cdecl ReadBinaryValue(NiStream& stream, T& value);
struct FUN_00c60850_Class : public NiPSysModifier
{
    void BSPSysSimpleColorModifier_LoadBinary(NiStream& stream);
};
struct MyIsEqual
{
    bool __thiscall FUN_00c31830(NiObject*);
};
struct FUN_00c60a10_Class
{
    unsigned char m_00[0x48];
    float m_48;
    float m_4c;
    float m_50;
    float m_54;
    float m_58;
    float m_5c;

    bool __thiscall BSPSysSimpleColorModifier_IsEqual(NiObject*);
};
void __cdecl FUN_00c31750(void);
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c60d10_Class
{
    void FUN_00c31750();
    void* __thiscall FUN_00c60d10(unsigned int flags);
};
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};
struct FUN_00c612b0_Class : NiAVObject, A51BF0Base
{
    unsigned char m_data[19];

    FUN_00c612b0_Class();
};
extern NiFixedString DAT_011f49e0;
NiAVObject* __cdecl BSWArray_CreateObject();
struct FUN_00a7b330_shell
{
    void CopyMembers_00a7b330(void* a, void* b);
};
struct FUN_00c61830_class
{
    void ForwardCall_00c61830(void* a, void* b);
};
struct FUN_00c62390_class
{
    void BSPSysArrayEmitter_GetAPoint(void*, void*);
};
struct FUN_00c61ba0_class : FUN_00c62390_class
{
    void ForwardToBase(void* a, void* b, void* c);
};
template <class T> void ReadBinaryValue(NiStream&, T&);
struct FUN_00c63900_class : NiPSysModifier
{
    void LoadModifierData(NiStream& stream);
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c31750_Class
{
    void __thiscall FUN_00c31750();
};
struct FUN_00c63a70_Class
{
    void* __thiscall FUN_00c63a70(unsigned int flags);
};
struct FUN_00c64500_Class : FUN_00c61490_Class
{
    bool BSDecalPlacementVectorExtraData_RegisterStreamables(const void* arg);
};
struct A46BB0Object
{
    bool IsEqual(A46BB0Object*);
};
int __cdecl __stricmp(const char*, const char*);
struct FUN_00c64980_Class : A46BB0Object
{
    bool BSReference_IsEqual(A46BB0Object* arg);
};
struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* AssignInternedString(unsigned int);
};
struct FUN_00c64dc0_Class
{
    char m_iWordAt00;
    char m_cByteAtOffset1;
    char m_cByteAtOffset2;
    char m_cByteAtOffset3;
    FUN_0043ba10_shell m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_0043ba10_shell* BSAttachPointPair_SetChild(unsigned int a);
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c64e70_Class
{
    void __thiscall FUN_00c64e70();
    void* __thiscall FUN_00c65650(unsigned int flags);
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct SpawnedObject_b9118
{
    char m00[0x60];
    SpawnedObject_b9118();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
SpawnedObject_b9118* BSPSysSimpleColorModifier_CreateObject();
class C61330Base
{
  public:
    C61330Base(int iA, int iB);
    virtual ~C61330Base();

    int unk04;
};
class FUN_00c61330 : public C61330Base
{
  public:
    void Initialize();

    FUN_00c61330(int iA, int iB);
    virtual ~FUN_00c61330();
};
struct FUN_00c61c50_sub
{
    void FUN_00c628c0(unsigned int n);
    void NiTArray_NiPointer_NiAVObject_NiTMallocInterface_NiPointer_NiAVObject_SetAt(unsigned int n, unsigned int* p);
};
struct FUN_00c61c50_cls
{
    unsigned int pad0[0x18];
    unsigned int* m_60;
    unsigned short pad1[1];
    unsigned short m_66;
    void NiPSysVolumeEmitter_CopyMembers(unsigned int a, unsigned int b);
    void BSPSysArrayEmitter_CopyMembers(unsigned int x, unsigned int y);
};
struct FUN_00c62140_Elem;
struct FUN_00c62140_Item;
struct FUN_00c62140_Val
{
    float m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    unsigned char m_08;
};
struct FUN_00c62140_Item
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    void NiAVObject_Update(FUN_00c62140_Val* pVal);
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
    FUN_00c62140_Elem** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
struct FUN_00c62140_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual FUN_00c62140_Item* v03();
};
struct FUN_00c62140_Pad
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
struct FUN_00c62140_Pad5
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};
struct FUN_00c62140_Sub
{
    void NiTArray_NiPointer_NiAVObject_NiTMallocInterface_NiPointer_NiAVObject_RemoveAll();
};
struct FUN_00c62140_cls
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
    FUN_00c62140_Obj* m_54;
    int unk58;
    FUN_00c62140_Sub m_5c;

    void BSPSysArrayEmitter_SetupArray();
    void BSPSysArrayEmitter_SetObjectPointers(FUN_00c62140_Elem* pElem);
};
struct S_00c62cc0_Class
{
    void* unk0;
    void* unk4;
    unsigned short m_8;
    unsigned short m_kPointA;
    unsigned short unk_c;
    unsigned short m_usTrailingValue;

    void FUN_00c628c0(unsigned int arg);
    void NiTArray_NiPointer_NiAVObject_NiTMallocInterface_NiPointer_NiAVObject_SetAt(unsigned int arg1, unsigned int arg2);
    unsigned int FUN_00c62cc0(unsigned int arg);
};
struct S_00c62cc0_Locals
{
    unsigned int value;
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
};
// FUN_00c634b0: thiscall (this in ecx), 2 stack params (a1 pointer, unsigned short index).
class XVec12
{
  public:
    float m_00;
    float m_04;
    float m_08;
};
class XSub30
{
  public:
    unsigned int unk00;
    unsigned int Call0045bb20(XVec12* out);
};
class XItem12
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void Call004578c0(unsigned int r, float f);
};
class XItem28
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    void Call0063c8a0(XSub30* arg);
};
class XObj70
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    XItem12* m_20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58,
        unk5c, unk60, unk64, unk68, unk6c;
    XItem28* m_70;
};
class FUN_00c634b0_cls
{
  public:
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14;
    float m_18;
    unsigned int m_1c;
    unsigned int m_20, m_24, m_28, m_2c;
    XSub30 m_30;
    void BSParentVelocityModifier_Initialize(XObj70* a1, unsigned short idx);
};
extern NiPoint3 NiPoint3_ZERO;
struct FUN_00c63780_c
{
    int pad[9];
    NiPoint3 v;
    void ResetVector();
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct PositionModifierObject_b9439
{
    char m00[0x3c];
    PositionModifierObject_b9439();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
PositionModifierObject_b9439* CreatePositionModifierObject();
struct Pad32
{
    unsigned int a0, a1, a2, a3, a4, a5, a6, a7;
};
struct ArgObj
{
    void FUN_0096a610(void* p);
};
struct FUN_00c63a00_cls
{
    void FUN_00c319e0(void* a);
    void BSParentVelocityModifier_GetViewerStrings(ArgObj* a1);
};
unsigned int __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int v);
unsigned int __cdecl NiGetViewerString_00a7d550(const char* name, float f);
struct S_00c643d0_Foo
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    unsigned short m_uiItemCount;
    void* m_entries[16];

    void __thiscall FUN_00a9a4e0(int arg);
    void __thiscall BSDecalPlacementVectorExtraData_SaveBinary(int arg);
};
extern "C" void __cdecl NiStreamSaveBinary_unsigned_short(int arg, void* object);
extern "C" void __cdecl NiPoint3_SaveBinary(int arg, void* data, int count);
class FUN_00c64b90_target;
class FUN_00c64b90_item
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_18;
};
class FUN_00c64b90_target
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30(unsigned int value);
};
class FUN_00c64b90_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FUN_00c64b90_item** m_0c;
    int unk10;
    unsigned short m_14;
    void BSNodeReferences_SaveBinary(FUN_00c64b90_target* a1);
    void nullsub_3(FUN_00c64b90_target* a1);
};
void __cdecl NiStreamSaveBinary_unsigned_int(FUN_00c64b90_target* a1, unsigned int* p);
struct FUN_00c64da0_cls
{
    int unk00;
    void Callee0043ba10(int a);
    void BSAttachPointPair_SetParent(int a);
};
struct DispatchStub_c64
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void** m10;
    int unk14;
    unsigned short m18;
    void DispatchToItems(int a8, int cc);
};
struct ItemCallee_c64
{
    void BSAttachPoints_AddPair(int a1, int a2);
};
struct FUN_00c65180_VTable
{
    virtual void FUN_00c65180_v0();
    virtual void FUN_00c65180_v1();
    virtual void FUN_00c65180_v2();
    virtual void FUN_00c65180_v3();
    virtual void FUN_00c65180_v4();
    virtual void FUN_00c65180_v5();
    virtual void FUN_00c65180_v6();
    virtual void FUN_00c65180_v7();
    virtual void FUN_00c65180_v8(void* p);
};
struct FUN_00c65180_Class
{
    unsigned char __thiscall FUN_00a7b290(FUN_00c65180_VTable* p);

    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void** m_10;
    int m_14;
    unsigned short m_18;

    unsigned char __thiscall VisitEntries(FUN_00c65180_VTable* p);
};
struct Point3ParameterData
{
    float unk00;
    float unk04;
    float unk08;
    float m_fXValue;
    float m_fYValue;
    float unk14;
    float unk18;
};
// The blk_00c60000_od.cpp overlay binds this clone constructor to the simple-color modifier constructor at 0x00c60240.
class SimpleColorModifierClone : public BSPSysSimpleColorModifier
{
  public:
    SimpleColorModifierClone();
};
// CloneObject 0x00c60670 copies the simple-color modifier via CopyMemberData 0x00c60700 in the same overlay.
class SimpleColorModifierCloner : public BSPSysSimpleColorModifier
{
  public:
    void CopyMemberData(SimpleColorModifierClone* pkDest, CloningProcess& kCloning);
    SimpleColorModifierClone* CloneObject(CloningProcess& kCloning);
};
struct FUN_00c615a0_class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0c;
    void FUN_00a99b20(NiTPrimitiveArray<unsigned int>* values);
    void AppendGlobalAndFormatValues(NiTPrimitiveArray<unsigned int>* values);
};
extern "C" void* g_012043a4;
extern const char str_0109df4c[];
struct GlobalObject_00a7b610;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(GlobalObject_00a7b610* value);
char* __cdecl NiGetViewerString_00a7d510(const char* format, unsigned int value);
struct Unused20
{
    int a, b, c, d, e, f, g, h;
};
struct C639a0Cls : MyIsEqual
{
    char pad[0x20];
    float m_20;
    bool __thiscall BSParentVelocityModifier_IsEqual(NiObject* pObject);
};

#include <xmmintrin.h>
extern float DAT_01011d78;
__forceinline void hkVector4::normalize()
{
    __m128 squared = _mm_mul_ps(m_vComponents, m_vComponents);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
    sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), sum);
    __m128 estimate = _mm_rsqrt_ss(sum);
    __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(sum, estimate), estimate));
    __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction);
    inverse = _mm_andnot_ps(_mm_cmpeq_ss(sum, _mm_set_ss(DAT_01011d78)), inverse);
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), m_vComponents);
}
struct InputRef
{
    const hkVector4* p;
    InputRef(const hkVector4* q) : p(q)
    {}
    operator const hkVector4*() const
    {
        return p;
    }
    const hkVector4* operator->() const
    {
        return p;
    }
};
struct TargetVector
{
    unsigned int unk00, unk04, unk08, unk0c;
    hkVector4 vector;
};
struct Holder
{
    TargetVector* hkaPose_accessBoneLocalSpace(int);
};
struct Entry
{
    Holder* holder;
    short index;
    short unk06;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    hkVector4 position;
    unsigned int unk40, unk44, unk48, unk4c;
};
extern float DAT_01017d00, DAT_01267d30, DAT_01267d24, DAT_01011d78;
extern __m128 DAT_01017d10;
extern double DAT_01023128;
struct Constraint
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
    unsigned short unkb0;
    bool enabled;
    unsigned char unkb3;
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
    Entry entries[1];
    float bhkRagdollController_LimitBoneRot(unsigned int, InputRef);
};
// The shared SIMD union does not trigger MSVC's default GS heuristic.
// Preserve the original function's stack cookie.
#pragma strict_gs_check(on)
// @fnv 0x00c755e0
// src: XBOX_PDB 0x00c755e0
float Constraint::bhkRagdollController_LimitBoneRot(unsigned int index, InputRef input)
{
    float distance = 0.0f;
    __m128 oldPosition = entries[index].position.m_vComponents;
    __m128 newPosition = input->m_vComponents;
    __m128 difference = _mm_and_ps(_mm_sub_ps(newPosition, oldPosition), DAT_01017d10);
    __m128 epsilon;
    epsilon = _mm_set1_ps(DAT_01017d00);
    if ((_mm_movemask_ps(_mm_cmple_ps(difference, epsilon)) & 7) != 7)
    {
        hkVector4 delta;
        delta.setMulInverse(input, &entries[index].position);
        distance = delta.GetAngle();
        float limit = enabled ? DAT_01267d30 : DAT_01267d24;
        if (distance > limit * DAT_01023128)
        {
            distance = (float)(limit * DAT_01023128);
            hkVector4 axis;
            delta.hkQuaternion_getAxis(&axis);
            axis.normalize();
            delta.hkQuaternion_setAxisAngle(&axis, distance);
        }
        {
            hkVector4 result;
            result.setMul(&delta, &entries[index].position);
            result.normalize_005611c0();
            TargetVector* target = entries[index].holder->hkaPose_accessBoneLocalSpace(entries[index].index);
            __m128 updated = result.m_vComponents;
            target->vector.m_vComponents = updated;
            entries[index].position.m_vComponents = updated;
        }
    }
    return distance;
}

#pragma strict_gs_check(off)

static __forceinline __m128 cross3(__m128 a, __m128 b)
{
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(first, second);
}
static __forceinline __m128 dot4(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ps(_mm_shuffle_ps(p, p, 0x4e), p);
    return _mm_add_ps(s, _mm_shuffle_ps(s, s, 0xb1));
}
static __forceinline __m128 blendXYZW(__m128 a, __m128 b)
{
    return _mm_shuffle_ps(a, _mm_unpackhi_ps(a, b), 0xc4);
}
// src: COMMUNITY 0x00c66320
inline void hkVector4::setMul(const hkVector4* a, const hkVector4* b)
{
    __m128 xyz = cross3(a->m_vComponents, b->m_vComponents);
    xyz = _mm_add_ps(xyz, _mm_mul_ps(_mm_shuffle_ps(a->m_vComponents, a->m_vComponents, 0xff), b->m_vComponents));
    xyz = _mm_add_ps(xyz, _mm_mul_ps(_mm_shuffle_ps(b->m_vComponents, b->m_vComponents, 0xff), a->m_vComponents));
    __m128 p = _mm_mul_ps(a->m_vComponents, b->m_vComponents);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    __m128 w = _mm_sub_ps(p, _mm_shuffle_ps(s, s, 0));
    m_vComponents = blendXYZW(xyz, w);
}
// src: COMMUNITY 0x005611c0
inline void hkVector4::normalize_005611c0()
{
    __m128 s = ::dot4(m_vComponents, m_vComponents);
    __m128 e = _mm_rsqrt_ss(s);
    __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(s, e), e));
    __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), correction);
    inverse = _mm_andnot_ps(_mm_cmpeq_ss(s, _mm_set_ss(0.0f)), inverse);
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), m_vComponents);
}
