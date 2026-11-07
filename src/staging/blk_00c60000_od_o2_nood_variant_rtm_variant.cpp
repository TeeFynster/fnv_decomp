#include <xmmintrin.h>
typedef ::__m128 LocalM128;
#define FNV64_HKVECTOR4_OWN_DEFAULT
// src/staging/blk_00c60000_od_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00c60000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00c60000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00c60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00c60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#define FNV_VEC4_SIMD
#include "../../include/Vec4.h"
#include <stddef.h>
#include <string.h>
#include "../../include/BSDecalPlacementVectorExtraData.h"
#include "../../include/BSPSysSimpleColorModifier.h"
#include "../../include/Bound.h"
#include "../../include/hkVector4.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiBinaryExtraData.h"
#include "../../include/NiObject.h"
#include "../../include/NiTPointerList.h"
#include "../../include/NiPSysCylinderEmitter.h"
#include "../../include/NiPSysData.h"
#include "../../include/NiPSysModifier.h"
#include "../../include/NiPSysPositionModifier.h"
#include "../../include/NiPSysVolumeEmitter.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../include/NiStream.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiTransform.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiColorA.h"
#include "../../include/Setting.h"
#include "../../include/NiMatrix3.h"
#include "../../include/bhkFilter.h"
#include "../../include/bhkWorldObject.h"
#include "../../include/hkBool.h"
#include "../../include/hkMatrix4.h"
#include "../../include/hkVector4.h"
#include "../../include/hkpAllCdPointCollector.h"
#include "../../include/hkpCdBody.h"
#include "../../include/hkpCollidable.h"
#include "../../include/hkpRigidBody.h"
#include "../../include/hkpShape.h"
#include "../../include/hkpShapeInfo.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
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
struct NiFixedString;
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
struct CloningProcess;
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
NiPSysCylinderEmitter* BSPSysArrayEmitter_CreateObject();
extern "C" void* __cdecl NiMalloc(unsigned int);
extern NiPoint3 _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;
extern int DAT_010c37fc;
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
struct FUN_00c60700_Group
{
    unsigned int value00;
    unsigned int value04;
    unsigned int value08;
    unsigned int value0c;
};
struct FUN_00c60700_Data
{
    unsigned char padding[0x18];
    FUN_00c60700_Group group00;
    FUN_00c60700_Group group10;
    FUN_00c60700_Group group20;
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
struct FUN_004a4cc0_shell
{
    bool __thiscall FUN_004a4cc0(void*);
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
int __cdecl __stricmp(const char*, const char*);
struct FUN_00c64980_Class : NiObject
{
    bool BSReference_IsEqual(NiObject* arg);
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
class XSub30
{
  public:
    unsigned int unk00;
    unsigned int Call0045bb20(NiPoint3* out);
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
struct BSPSysSimpleColorModifierCand
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiColorA m_kColor1;
    NiColorA m_kColor2;
    NiColorA m_kColor3;
    float m_fFadeInPercent;
    float m_fFadeOutPercent;
    float m_fColor1End;
    float m_fColor2Start;
    float m_fColor2End;
    float m_fColor3Start;

    void UpdateParticleColors(float fTime, NiPSysData* pkData);
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
struct C639a0Cls : NiPSysModifier
{
    char pad[0x20];
    float m_20;
    bool __thiscall BSParentVelocityModifier_IsEqual(NiObject* pObject);
};
struct VirtualResult
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};
class __declspec(align(16)) AlignedOwnerNode
{
  public:
    AlignedOwnerNode(AlignedOwnerNode* owner);
    ~AlignedOwnerNode();
    void CollectPoints();

    int m_000;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    char m_20[8];
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    int m_2b8;
    int m_2bc;
    int m_2c0;
    int m_2c4;
    int m_2c8;
    int m_2cc;
    int m_2d0;
    int m_2d4;
    int m_2d8;
    int m_2dc;
    int m_2e0;
    int m_2e4;
    int m_2e8;
    int m_2ec;
    int m_2f0;
    int m_2f4;
    int m_2f8;
    int m_2fc;
    int m_300;
    int m_304;
    int m_308;
    int m_30c;
    int m_310;
    int m_314;
    int m_318;
    int m_31c;
    int m_320;
    int m_324;
    int m_328;
    int m_32c;
    int m_330;
    int m_334;
    int m_338;
    int m_33c;
    int m_340;
    int m_344;
    int m_348;
    int m_34c;
    int m_350;
    int m_354;
    int m_358;
    int m_35c;
    int m_360;
    int m_364;
    int m_368;
    int m_36c;
    int m_370;
    int m_374;
    int m_378;
    int m_37c;
    int m_380;
    int m_384;
    int m_388;
    int m_38c;
    int m_390;
    int m_394;
    int m_398;
    int m_39c;
    int m_3a0;
    int m_3a4;
    int m_3a8;
    int m_3ac;
    int m_3b0;
    int m_3b4;
    int m_3b8;
    int m_3bc;
    int m_3c0;
    int m_3c4;
};
class ProxyBase
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
    virtual VirtualResult* v37();
    virtual void v38();
    void DoLockCall();
    int m_04;
    void* m_08;
    int m_0c;
};
class CharacterProxy : public ProxyBase
{
  public:
    AlignedOwnerNode m_kPoints;

    void bhkCharacterProxy_Integrate(unsigned int formID);
};
struct PointLoader
{
    void ReadPointsFromFile(unsigned int formID, int* value, AlignedOwnerNode* tmp, AlignedOwnerNode* owner);
};
extern "C" void _ReadWriteBarrier();
extern float DAT_01267e30;
__forceinline hkpRigidBody* hkGetRigidBody(const hkpCollidable* collidable)
{
    if (collidable->m_kBroadPhaseHandle.m_type == 1)
    {
        return (hkpRigidBody*)collidable->getOwner();
    }
    return 0;
}
struct MaterialSource
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual int getMaterial(unsigned int shapeKey);
};
MaterialSource* __cdecl bhkUtilFunctions_FindbhkShapeCollection(const hkpCdBody* body);
extern bool(__cdecl* DAT_01267bc8)(int material);
inline bool IsSpecialMaterial(int material)
{
    if (!DAT_01267bc8)
    {
        return false;
    }
    return DAT_01267bc8(material);
}
struct GroundPoint
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
    const hkpCdBody* m_kCollidable;
    int m_uiCollisionShapeKey;
};
struct GroundController
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    unsigned int m_flags;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int m_iMaterialIndex;
    int m_layer;
    int unk43c;
    hkVector4 m_fVelocity;

    void SetFlag(unsigned int uiMask, bool bSet)
    {
        if (bSet)
        {
            m_flags |= uiMask;
        }
        else
        {
            m_flags &= ~uiMask;
        }
    }
    bool GetFlag(unsigned int uiMask) const
    {
        return (m_flags & uiMask) != 0;
    }

    void bhkCharacterController_SetSupportMaterial(const GroundPoint* point);
};
extern bool DAT_012677a3;
extern unsigned char DAT_012677cc;
extern float DAT_011afe78, DAT_011afe74, DAT_012677c4;
extern unsigned long DAT_0126835c;
extern char str_010c41fc[], str_010c41f8[];
extern int DAT_010c3bd4, DAT_010c3bb8;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
struct Result;
union Scratch
{
    float threshold;
    Result* result;
    volatile unsigned int stamp;
};
struct TraceBool
{
    char value;
    TraceBool(bool b)
    {
        value = (char)b;
    }
    operator bool() const
    {
        return value != 0;
    }
};
struct TraceEntry
{
    const char* tag;
    unsigned int time;
    unsigned int extra;
    void SetTime()
    {
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        time = stamp;
    }
};
struct TraceBuffer
{
    int unk00;
    TraceEntry* current;
    int unk08;
    TraceEntry* end;
    static TraceBuffer& GetInstance()
    {
        return *(TraceBuffer*)TlsGetValue(DAT_0126835c);
    }
    TraceBool MemoryAvailable() const
    {
        return current < end;
    }
    TraceEntry* Expand()
    {
        TraceEntry* e = current;
        return e;
    }
};
inline void TraceBegin(const char* tag, Scratch& scratch)
{
    TraceBuffer& stream = TraceBuffer::GetInstance();
    if (stream.MemoryAvailable())
    {
        TraceEntry* e = stream.Expand();
        e->tag = tag;
        _ReadWriteBarrier();
        scratch.stamp = (unsigned int)__rdtsc();
        e->time = scratch.stamp;
        stream.current = e + 1;
    }
}
inline void TraceEnd(const char* tag, Scratch& scratch)
{
    TraceBuffer& stream = TraceBuffer::GetInstance();
    if (stream.MemoryAvailable())
    {
        TraceEntry* e = stream.Expand();
        e->tag = tag;
        _ReadWriteBarrier();
        scratch.stamp = (unsigned int)__rdtsc();
        e->time = scratch.stamp;
        stream.current = e + 1;
    }
}
struct Result
{
    int field00;
    int field04;
    int field08;
    int field0c;
    float field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    void Clear()
    {
        field10 = 1.0f;
        field50 = 0;
        field14 = -1;
        field40 = 0;
        field20 = -1;
    }
    void ProcessEntries_009c1aa0(Result*);
    void CopyRayCastResultAndRootCollidable(Result*) throw();
};
struct Collector
{
    int field00;
    float fraction;
    int field08, field0c;
    Result result;
    void Finalize();
};
struct Query
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    Result result;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    void* filter;
    Collector* collector;
    struct HitResultList* hits;
    bool disabled;
    void bhkPickData_CalcTo();
};
struct HitResultList
{
    int field00, field04, field08, field0c;
    Result* result;
    int count;
    void hknpAllHitsCollector_sortHits();
};
struct World
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    void hkpWorld_castRay(Query*, void*);
    void hkpWorld_castRay_00c92040(Query*, Result*);
};
struct __declspec(align(16)) CastVector
{
    float x, y, z, w;
};
struct CastCollectorBase
{
    int* vtable;
    ~CastCollectorBase()
    {
        vtable = &DAT_010c3bb8;
    }
};
struct __declspec(align(16)) WorldRayCaster : CastCollectorBase
{
    int field04;
    int field08;
    int field0c;
    CastVector from;
    CastVector to;
    CastVector direction;
    int field40;
    int field44;
    WorldRayCaster()
    {
        vtable = &DAT_010c3bd4;
        field40 = 0;
        field44 = 0;
    }
    void hkpWorldRayCaster_castRay(int, Query*, int, void*, void*);
};
struct FilterCast : WorldRayCaster
{
    __forceinline FilterCast(World* world, Query* query, void* cache, void* collector)
    {
        int mode = world->field7c;
        hkpWorldRayCaster_castRay(world->field58, query, mode, cache, collector);
    }
};
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
struct RayCaster
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
    virtual World* GetWorld();
    bool bhkWorld_PickObject(Query* query);
};
struct SseBlock
{
    LocalM128 m_00;
    LocalM128 m_10;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    int m_30;

    SseBlock& UpdateState_00c6d670(const SseBlock& o);
};
// Reconstruction adapted from an unverified 2026-10-26 contribution by another contributor.
extern "C"
{
using ::_mm_add_ss;
using ::_mm_andnot_ps;
using ::_mm_cmpeq_ss;
using ::_mm_mul_ps;
using ::_mm_mul_ss;
using ::_mm_rsqrt_ss;
using ::_mm_set_ss;
using ::_mm_setr_ps;
using ::_mm_setzero_ps;
using ::_mm_shuffle_ps;
using ::_mm_sqrt_ss;
using ::_mm_store_ss;
using ::_mm_sub_ps;
using ::_mm_sub_ss;
}
extern "C" double __cdecl cos(_In_ double _X);
extern "C" inline float cosf(_In_ float _X)
{
    return ((float)cos((double)_X));
}
inline float __cdecl cos(_In_ float _X)
{
    return (cosf(_X));
}
struct FxRTTI
{
    const char* m_pcName;
    const FxRTTI* m_pBaseRTTI;
};
extern const FxRTTI DAT_012043f8, DAT_0126831c, DAT_01268310, DAT_0126864c;
extern const float DAT_01011d78, DAT_01017718, DAT_01016248;
extern const double DAT_0102f248, DAT_01066808, DAT_01020758, DAT_0102fc70, DAT_01023128;
extern const char* DAT_0109b220;
extern "C" long(__stdcall* DAT_00fdf1c4)(long*);
struct FxString
{
    const char* m_kHandle;
    FxString(const char* pcString)
    {
        if (!pcString)
            m_kHandle = DAT_0109b220;
        else
            m_kHandle = FUN_00a5b690(pcString);
    }
    ~FxString()
    {
        if (m_kHandle != DAT_0109b220)
            DAT_00fdf1c4((long*)(m_kHandle - 8));
    }
    static const char* __cdecl FUN_00a5b690(const char*);
};
struct FxObject;
FxObject* __cdecl NiObject_DynamicCast(const FxRTTI*, FxObject*);
struct ExtraData
{
    unsigned unk00, unk04, unk08, unk0c, unk10;
    FxObject* m_pkProperties;
    FxObject** GetProperties()
    {
        return &m_pkProperties;
    }
};
struct CastResult
{
    unsigned unk00, unk04, unk08, unk0c;
    ExtraData* m_pkExtra;
    ExtraData* GetExtra() const
    {
        return m_pkExtra;
    }
};
struct CastObject
{
    CastResult* FUN_00653290(const FxRTTI*);
};
struct FxAVObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual FxAVObject* IsSceneNode();
    unsigned unk04, unk08, unk0c, unk10, unk14, unk18;
    CastObject* m_pkCast;
};
struct FxNode : FxAVObject
{
    unsigned unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    FxNode** m_ppkChildren;
    unsigned short m_usMaxSize, m_usSize;
};
__forceinline FxNode* FirstChild(FxNode* pkNode)
{
    return pkNode && pkNode->IsSceneNode() && pkNode->m_usSize > 0 ? pkNode->m_ppkChildren[0] : 0;
}
__forceinline FxNode* FirstChildP(FxNode* pkNode)
{
    if (!pkNode)
        return pkNode;
    return pkNode->IsSceneNode() && pkNode->m_usSize > 0 ? pkNode->m_ppkChildren[0] : 0;
}
__forceinline FxObject** Properties(FxNode* pkNode)
{
    if (pkNode->m_pkCast)
    {
        CastResult* pkCast = pkNode->m_pkCast->FUN_00653290(&DAT_012043f8);
        if (pkCast && pkCast->GetExtra())
            return pkCast->GetExtra()->GetProperties();
    }
    return 0;
}
struct SceneObject
{
    unsigned unk00, unk04, unk08, unk0c;
    NiPoint3 origin;
    float originW;
    NiPoint3 end;
    float endW;
};
__forceinline Vec4 DifferenceOf(const SceneObject* o)
{
    Vec4 v;
    v.m_vComponents = _mm_sub_ps(_mm_setr_ps(o->origin.x, o->origin.y, o->origin.z, o->originW),
                                 _mm_setr_ps(o->end.x, o->end.y, o->end.z, o->endW));
    return v;
}
__forceinline Vec4 DifferenceOfMid(const SceneObject* o)
{
    Vec4 v;
    LocalM128 a = _mm_setr_ps(o->origin.x, o->origin.y, o->origin.z, o->originW);
    LocalM128 b = _mm_setr_ps(o->end.x, o->end.y, o->end.z, o->endW);
    _ReadWriteBarrier();
    v.m_vComponents = _mm_sub_ps(a, b);
    return v;
}
struct VfxSource
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int Type();
    unsigned unk10, unk14, unk18, unk1c;
    Vec4 m_kInitialDirection;
    unsigned unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    Vec4 m_kFinalDirection;
    unsigned unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    unsigned unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    float m_fOriginAngle;
    float m_fFinalAngle;
};
struct SourceLink
{
    unsigned unk00;
    VfxSource* m_pkSource;
    VfxSource* GetSource() const
    {
        return m_pkSource;
    }
};
struct SourceProperty
{
    SourceLink* ReadCompleteObject();
    SourceLink* UpdateState_00c747b0();
};
struct ShaderHolder
{
    unsigned unk00, unk04, unk08;
    VfxSource* m_pkSource;
    VfxSource* GetSource() const
    {
        return m_pkSource;
    }
};
struct ShaderLink
{
    unsigned unk00;
    ShaderHolder* m_pkHolder;
    ShaderHolder* GetHolder() const
    {
        return m_pkHolder;
    }
};
struct ShaderProperty
{
    ShaderLink* ReadCompleteObject();
};
__forceinline VfxSource* FindSource(FxObject** ppkProperties)
{
    FxObject* pkInitial = *ppkProperties;
    SourceProperty* pkProp = (SourceProperty*)NiObject_DynamicCast(&DAT_0126831c, pkInitial);
    VfxSource* pkSource = pkProp ? pkProp->ReadCompleteObject()->GetSource() : 0;
    if (!pkProp)
    {
        FxObject* pkFallback = *ppkProperties;
        ShaderProperty* pkShader = (ShaderProperty*)NiObject_DynamicCast(&DAT_01268310, pkFallback);
        if (pkShader)
        {
            ShaderHolder* pkHolder = pkShader->ReadCompleteObject()->GetHolder();
            VfxSource* pkAlt = pkHolder ? pkHolder->GetSource() : 0;
            if (pkAlt && pkAlt->Type() == 2)
                pkSource = pkAlt;
        }
    }
    return pkSource;
}
extern Setting DAT_01267d98, DAT_01267de0;
struct EffectOutput
{
    unsigned unk00, unk04, unk08, unk0c;
    Vec4 m_kLightVector;
    Vec4 m_kDisplacement;
    unsigned unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    float m_fOriginX, m_fOriginY, m_fOriginZ, m_fAngleZ, m_fAngleX, m_fAngleY;
};
struct EffectName
{
    const char* m_pcText;
};
struct EffectRequest
{
    unsigned unk00;
    EffectName* m_pkName;
};
struct SceneEffect
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    unsigned unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
    void* m_pkScene;
    static FxNode* __cdecl BSUtilities_GetObjectByName_00c4b470(void*, FxString*, int);
    SceneObject* bhkRagdollController_GetCapsuleBoneShapeInfo(FxNode*);
    bool bhkRagdollController_ExtractBipedSetupData(EffectOutput* pkOutput, EffectRequest* pkRequest);
};
struct SRC
{
    int m_00, m_04, m_08, m_0c;
    float m_10, m_14, m_18, m_1c;
    LocalM128 m_20;
};
struct DST
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    float m_30;
};
struct VEC
{
    float q[4];
    void FUN_00a38560();
    void NiQuaternion_ToRotation(void*);
};
void* __cdecl FUN_00458620(void*, const void*);
// @fnv 0x00c74d50
struct LOC
{
    float s;
    char quat[16];
};
// src: COMMUNITY 0x00c74d50
DST* __cdecl HK2NI_00c74d50(DST* dst, const SRC* src)
{
    LOC a;
    VEC* q = (VEC*)&a.quat;
    q->q[1] = src->m_10;
    q->q[2] = src->m_14;
    q->q[3] = src->m_18;
    q->q[0] = src->m_1c;
    q->FUN_00a38560();
    q->NiQuaternion_ToRotation(dst);
    FUN_00458620(&dst->m_24, src);
    _mm_store_ss(&a.s, src->m_20);
    dst->m_30 = a.s;
    return dst;
}
extern "C" void _ReadWriteBarrier();
inline NiPoint3 NiPoint3::operator*(float scale) const
{
    return NiPoint3(x * scale, y * scale, z * scale);
}
inline const NiPoint3& ZeroPoint()
{
    return reinterpret_cast<const NiPoint3&>(NiPoint3_ZERO);
}
extern Bound DAT_011f4288;
extern float DAT_010c72bc, DAT_011b0194;
static float DAT_01267bcc;
extern const double DAT_0104f2f0, DAT_010c4ab8, DAT_010240c0;
struct ShapeRef
{
    virtual void Reserved();
    virtual void Destroy();
    long references;
    void* shape;
    int unk0c;
    float radius;
    void IncRefCount()
    {
        InterlockedIncrement(&references);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&references))
            Destroy();
    }
};
struct ShapePointer : NiPointer<ShapeRef>
{
    ShapePointer& operator=(ShapeRef* incoming)
    {
        if (m_pObject != incoming)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = incoming;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    void FUN_0066b0d0(ShapeRef*);
    void FUN_00c663d0(ShapePointer const&);
};
extern ShapePointer DAT_01267be0;
struct Geometry
{
    int unk00, unk04, unk08;
    NiPoint3 center, extents;
};
struct NodeBounds
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Bound* bound;
    Bound* GetBound() const
    {
        return bound ? bound : &DAT_011f4288;
    }
    void* hkpCharacterProxy_getPosition();
};
Geometry* __cdecl BSBound_Find(NodeBounds*);
void* __cdecl Object_DispatchCommandFour(unsigned int);
struct HeapAllocator
{
    virtual void v0();
    virtual void* Allocate(int);
    virtual void v8();
    virtual void vc();
    virtual void Deallocate(void*, int);
};
struct HeapContext
{
    int unk00, unk04, unk08, unk0c;
    HeapAllocator* allocator;
    HeapAllocator* GetAllocator() const
    {
        return allocator;
    }
};
HeapContext* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(HeapAllocator*, void*, int);
struct RawArray
{
    void** data;
    int count;
    unsigned int capacity;
    __forceinline void Add(void* value)
    {
        HeapAllocator* allocator = hkMemoryRouter_getInstance()->allocator;
        if (count == (capacity & 0x3fffffff))
            ResizeAudioStream(allocator, this, 4);
        data[count++] = value;
    }
    void Clear8()
    {
        HeapAllocator* allocator = hkMemoryRouter_getInstance()->GetAllocator();
        count = 0;
        if (!(capacity & 0x80000000))
            allocator->Deallocate(data, (capacity & 0x3fffffff) * 8);
    }
};
struct PtrArray : RawArray
{
};
struct CompoundInfo
{
    int material;
    RawArray shapes;
    RawArray extra;
    CompoundInfo() : material(0)
    {
        shapes.data = 0;
        shapes.count = 0;
        shapes.capacity = 0x80000000;
        extra.data = 0;
        extra.count = 0;
        extra.capacity = 0x80000000;
    }
    void FUN_00c71120();
    ~CompoundInfo()
    {
        FUN_00c71120();
    }
};
struct FUN_00cab710 : ShapeRef
{
    FUN_00cab710(NiPoint3 const&, NiPoint3 const&, float);
    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    static void operator delete(void*);
};
struct FUN_00c6d290 : ShapeRef
{
    FUN_00c6d290(CompoundInfo const&);
    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    static void operator delete(void*);
};
struct FUN_00cd8160
{
    int unk00;
    unsigned short size, refs;
    int unk08, unk0c;
    float radius;
    int unk14, unk18, unk1c;
    static void* operator new(unsigned int n)
    {
        HeapContext* ctx = hkMemoryRouter_getInstance();
        FUN_00cd8160* result = (FUN_00cd8160*)ctx->allocator->Allocate(n);
        result->size = (unsigned short)n;
        return result;
    }
    static void operator delete(void*);
    FUN_00cd8160(float r);
};
struct ShapeInput;
struct __declspec(align(16)) AuxInfo
{
    unsigned int flags;
    FUN_00cd8160* shape;
    int unk08;
    PtrArray entries;
    int unk18, unk1c;
    unsigned char transform[64];
    void FUN_0056e0b0();
    ~AuxInfo()
    {
        entries.Clear8();
    }
    AuxInfo(ShapeInput* input, NodeBounds*& nodeOut, unsigned int& flagsOut);
};
struct ShapeInput;
struct ShapeOwner;
extern MemoryManager DAT_011f6238;
struct FUN_00c6d1e0 : ShapeRef
{
    int unk14, unk18, unk1c;
    FUN_00c6d1e0(AuxInfo const&, ShapeOwner*);
    static void* operator new(unsigned int n)
    {
        unsigned char* p = (unsigned char*)DAT_011f6238.Game_DoHeapAlloc(n + 16);
        unsigned char offset = 16 - ((unsigned int)p & 15);
        p += offset;
        p[-1] = offset;
        return p;
    }
    static void operator delete(void*);
};
ShapeRef* __cdecl MakeConvex(NiPoint3 const&, NiPoint3 const&, float, float);
struct ShapeInput
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
    float margin;
    float maxSize;
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
    NodeBounds* node;
    unsigned int flags;
    int unk088;
    int unk08c;
    int unk090;
    unsigned char flag94, flag95, flag96, flag97;
    int unk098;
    int unk09c;
    ShapeRef* existingShape;
    int unk0a4;
    int unk0a8;
    float scale;
    unsigned int index;
    unsigned int GetFlags() const
    {
        return flags;
    }
    float GetScale() const
    {
        return scale;
    }
    ShapeRef* GetShape() const
    {
        return existingShape;
    }
    unsigned int GetIndex() const
    {
        if (existingShape)
            return 0;
        return index;
    }
};
__forceinline AuxInfo::AuxInfo(ShapeInput* input, NodeBounds*& nodeOut, unsigned int& flagsOut)
{
    FUN_0056e0b0();
    unsigned int f = input->GetFlags() & 0xffffff80;
    nodeOut = input->node;
    _ReadWriteBarrier();
    flagsOut = f | 0x20;
}
struct ShapeOwner
{
    int unk000;
    int unk004;
    NodeBounds* node;
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    unsigned int flags;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    float maxRadius;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    float height;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    float fullHeight;
    int unk568;
    int unk56c;
    float centerX;
    float centerY;
    float heightAccum;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    ShapePointer aux;
    int unk59c;
    unsigned int shapeCount;
    ShapePointer shapes[2];
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    NiPoint3 dimensions;
    __forceinline void SetShape(unsigned int index, ShapeRef* incoming)
    {
        shapes[index] = incoming;
    }
    float GetMaxRadius() const
    {
        return maxRadius;
    }
    float GetBoundRadius(ShapeRef* bound) const
    {
        return bound && bound->shape ? ((ShapeRef*)bound->shape)->radius : DAT_010c72bc;
    }
    ShapeRef* GetCurrentObject();
    void SetMode(unsigned int);
    void* bhkCharacterProxy_MarkRead();
    void bhkCharacterController_InitShapes(ShapeInput* input);
};
namespace P064Intrinsics {
typedef ::__m128 LocalM128;
extern "C"
{
using ::_mm_mul_ps;
using ::_mm_load_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_add_ss;
using ::_mm_sub_ss;
using ::_mm_mul_ss;
using ::_mm_div_ss;
using ::_mm_shuffle_ps;
using ::_mm_xor_ps;
using ::_mm_and_ps;
using ::_mm_andnot_ps;
using ::_mm_cmpeq_ss;
using ::_mm_cmple_ps;
using ::_mm_sqrt_ss;
using ::_mm_rsqrt_ss;
using ::_mm_rcp_ps;
using ::_mm_set_ss;
using ::_mm_set_ps1;
using ::_mm_setzero_ps;
using ::_mm_unpackhi_ps;
using ::_mm_store_ss;
using ::_mm_cvtss_f32;
using ::_mm_movemask_ps;
}
}
typedef P064Intrinsics::LocalM128 P064Quad;
struct P064Bool
{
    char value;
    P064Bool(bool b) : value(b)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct P064Quaternion
{
    P064Quad value;

    __declspec(noinline) void setMul(const P064Quaternion*, const P064Quaternion*);
    P064Bool IsNormalized();
    __declspec(noinline) void setMulInverse(const P064Quaternion*, const P064Quaternion*);
    float GetAngle();
    void hkQuaternion_getAxis(P064Quad*);
    void hkQuaternion_setAxisAngle(const P064Quad*, float);
    void normalize_005611c0();
};
struct P064Transform
{
    P064Quad translation;
    P064Quaternion rotation;
    P064Quad scale;
    __forceinline P064Transform& operator=(const P064Transform& other)
    {
        translation = other.translation;
        rotation.value = other.rotation.value;
        scale = other.scale;
        return *this;
    }
    __forceinline P064Transform(const P064Transform& other)
    {
        *this = other;
    }
    P064Transform()
    {}
};
struct P064Skeleton
{
    int unk00, unk04, unk08;
    short* parents;
    int unk10, unk14, unk18;
    int count;
};
struct P064Pose
{
    P064Skeleton* skeleton;
    P064Transform* local;
    int unk08, unk0c;
    P064Transform* model;
    int unk14, unk18;
    unsigned int* flags;
    int unk20, unk24;
    bool synchronized;
    P064Transform* hkaPose_calculateBoneModelSpace(int);
    P064Quad* hkaPose_accessBoneLocalSpace(int);
    P064Transform* accessBoneModelSpace(int, int);
};
struct P064Point
{
    P064Quad value;
    void hkVector4_setTransformedInversePos_00c7f840(const P064Point*, const void*);
};
struct P064Slot
{
    P064Pose* pose;
    short bone;
    short referenceBone;
    float weight;
    int unk0c;
    P064Quad target;
    P064Quad direction;
    P064Quaternion previous;
    bool initialized;
    bool active;
    short unk42;
    int unk44, unk48, unk4c;
};
struct P064Aim
{
    P064Quad target;
    P064Quad offset;
    P064Quad direction;
    float weight;
};
P064Bool __cdecl hkaLookAtIkSolver_solve(const P064Aim*, const P064Point*, float, P064Transform*, int);
extern float DAT_01267d3c, DAT_01267d30, DAT_01267d24;
extern P064Quad DAT_01017d10;
extern const float DAT_01017d00;
extern P064Quad DAT_010c71e0, DAT_010c7170, DAT_010c44d0, DAT_010c4c00, DAT_010c4c10, DAT_010c71b0;
extern const float DAT_01011d78, DAT_01017718, DAT_01016248;
static __forceinline void P064Assign(P064Quad& dst, const P064Quad& src)
{
    dst = src;
}
static __forceinline P064Quad P064Dot(const P064Quad& a, const P064Quad& b)
{
    P064Quad p = P064Intrinsics::_mm_mul_ps(a, b);
    return P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(p, p, 170),
                                      P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(p, p, 85), p));
}
static __forceinline P064Quad P064Cross(const P064Quad& a, const P064Quad& b)
{
    return P064Intrinsics::_mm_sub_ps(P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(a, a, 201),
                                                                 P064Intrinsics::_mm_shuffle_ps(b, b, 210)),
                                      P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(a, a, 210),
                                                                 P064Intrinsics::_mm_shuffle_ps(b, b, 201)));
}
static __forceinline P064Quad P064Rotate(const P064Quad& q, P064Quad v, bool inverse = false)
{
    P064Quad w = P064Intrinsics::_mm_shuffle_ps(q, q, 255);
    P064Quad dot = P064Dot(v, q);
    P064Quad crossA = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 201),
                                                 P064Intrinsics::_mm_shuffle_ps(q, q, 210));
    P064Quad crossB = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 210),
                                                 P064Intrinsics::_mm_shuffle_ps(q, q, 201));
    P064Quad cross;
    if (inverse)
        cross = P064Intrinsics::_mm_sub_ps(crossA, crossB);
    else
        cross = P064Intrinsics::_mm_sub_ps(crossB, crossA);
    P064Quad sum = P064Intrinsics::_mm_add_ps(
        P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(w, w), DAT_010c71e0), v),
        P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(dot, dot, 0), q));
    P064Quad result = P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(cross, w), sum);
    return P064Intrinsics::_mm_add_ps(result, result);
}
static __forceinline P064Quad P064InitialRotate(const P064Quad& q, const P064Quad& v, bool inverse = false)
{
    P064Quad w = P064Intrinsics::_mm_shuffle_ps(q, q, 255);
    P064Quad dot = P064Dot(v, q);
    P064Quad crossA = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 201),
                                                 P064Intrinsics::_mm_shuffle_ps(q, q, 210));
    P064Quad crossB = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 210),
                                                 P064Intrinsics::_mm_shuffle_ps(q, q, 201));
    P064Quad cross;
    if (inverse)
        cross = P064Intrinsics::_mm_sub_ps(crossA, crossB);
    else
        cross = P064Intrinsics::_mm_sub_ps(crossB, crossA);
    P064Quad sum = P064Intrinsics::_mm_add_ps(
        P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(w, w), DAT_010c71e0), v),
        P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(dot, dot, 0), q));
    P064Quad result = P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(cross, w), sum);
    return P064Intrinsics::_mm_add_ps(result, result);
}
static __forceinline P064Quad P064InverseRotate(const P064Quad& q, const P064Quad& v)
{
    P064Quad w = P064Intrinsics::_mm_shuffle_ps(q, q, 255);
    P064Quad dot = P064Dot(v, q);
    P064Quad crossA = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 201),
                                                 P064Intrinsics::_mm_shuffle_ps(q, q, 210));
    P064Quad crossB = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 210),
                                                 P064Intrinsics::_mm_shuffle_ps(q, q, 201));
    P064Quad cross = P064Intrinsics::_mm_sub_ps(crossA, crossB);
    P064Quad sum = P064Intrinsics::_mm_add_ps(
        P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(w, w), DAT_010c71e0), v),
        P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(dot, dot, 0), q));
    P064Quad result = P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(cross, w), sum);
    return P064Intrinsics::_mm_add_ps(result, result);
}
static __forceinline P064Quad P064Normalize(const P064Quad& v, const P064Quad& zero, const P064Quad& three,
                                            const P064Quad& half)
{
    P064Quad length = P064Dot(v, v);
    P064Quad r = P064Intrinsics::_mm_rsqrt_ss(length);
    P064Quad corrected = P064Intrinsics::_mm_mul_ss(
        P064Intrinsics::_mm_mul_ss(half, r),
        P064Intrinsics::_mm_sub_ss(three, P064Intrinsics::_mm_mul_ss(P064Intrinsics::_mm_mul_ss(length, r), r)));
    corrected = P064Intrinsics::_mm_andnot_ps(P064Intrinsics::_mm_cmpeq_ss(length, zero), corrected);
    return P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(corrected, corrected, 0), v);
}
static __forceinline float P064Length(const P064Quad& v)
{
    return P064Intrinsics::_mm_cvtss_f32(P064Intrinsics::_mm_sqrt_ss(P064Dot(v, v)));
}
static __forceinline P064Transform* P064Model(P064Pose* pose, int bone)
{
    if (!(pose->flags[bone] & 2))
        return pose->model + bone;
    return pose->hkaPose_calculateBoneModelSpace(bone);
}
static __forceinline P064Transform* P064Local(P064Pose* pose, int bone, P064Transform* __restrict scratch)
{
    if (!(pose->flags[bone] & 1))
        return pose->local + bone;
    {
        P064Transform* models = pose->model;
        P064Transform* src = models + bone;
        short parent = pose->skeleton->parents[bone];
        if (parent != -1)
        {
            P064Transform* p = P064Model(pose, parent);
            P064Transform* dst = pose->local + bone;
            P064Transform& inverse = *scratch;
            inverse.translation =
                P064Intrinsics::_mm_xor_ps(P064InverseRotate(p->rotation.value, p->translation), DAT_010c44d0);
            inverse.rotation.value = P064Intrinsics::_mm_xor_ps(p->rotation.value, DAT_010c4c00);
            P064Quad scale = P064Intrinsics::_mm_shuffle_ps(
                P064Intrinsics::_mm_load_ps(p->scale.m128_f32),
                P064Intrinsics::_mm_unpackhi_ps(P064Intrinsics::_mm_load_ps(p->scale.m128_f32), DAT_010c7170), 196);
            P064Quad r = P064Intrinsics::_mm_rcp_ps(scale);
            inverse.scale = P064Intrinsics::_mm_and_ps(
                P064Intrinsics::_mm_sub_ps(P064Intrinsics::_mm_add_ps(r, r),
                                           P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_mul_ps(r, scale), r)),
                DAT_010c4c10);
            dst->translation =
                P064Intrinsics::_mm_add_ps(P064Rotate(inverse.rotation.value, src->translation), inverse.translation);
            dst->rotation.setMul(&inverse.rotation, &src->rotation);
            dst->scale = P064Intrinsics::_mm_mul_ps(src->scale, inverse.scale);
        }
        else
        {
            pose->local[bone] = models[bone];
        }
        pose->flags[bone] &= ~1u;
    }
    return pose->local + bone;
}
struct P064Controller
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
    short unkb0;
    bool enabled;
    bool running;
    int unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    P064Quad transformTranslation;
    P064Quaternion transformRotation;
    P064Slot slots[2];
    bool constrained;
    int activeSlot;
    __declspec(noinline) float bhkRagdollController_LimitBoneRot(int, P064Quaternion*);
    bool bhkRagdollController_BoneTrack(int, const P064Point*);
};
struct P064Scalar
{
    union
    {
        P064Quad value;
        float lanes[4];
    };
    P064Scalar(float f) : value(P064Intrinsics::_mm_set_ss(f))
    {}
};
// src: COMMUNITY 0x00c66320
__declspec(noinline) void P064Quaternion::setMul(const P064Quaternion* first, const P064Quaternion* second)
{
    P064Quad left = first->value;
    P064Quad right = second->value;
    P064Quad product = P064Intrinsics::_mm_mul_ps(right, left);
    P064Quad sum = P064Dot(left, right);
    P064Quad realPart = P064Intrinsics::_mm_sub_ps(product, P064Intrinsics::_mm_shuffle_ps(sum, sum, 0));
    P064Quad ca = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(right, right, 210),
                                             P064Intrinsics::_mm_shuffle_ps(left, left, 201));
    P064Quad cb = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(right, right, 201),
                                             P064Intrinsics::_mm_shuffle_ps(left, left, 210));
    P064Quad cross = P064Intrinsics::_mm_sub_ps(ca, cb);
    P064Quad leftW = P064Intrinsics::_mm_shuffle_ps(left, left, 255);
    leftW = P064Intrinsics::_mm_shuffle_ps(leftW, leftW, 0);
    P064Quad lv = P064Intrinsics::_mm_mul_ps(leftW, right);
    P064Quad rightW = P064Intrinsics::_mm_shuffle_ps(right, right, 255);
    rightW = P064Intrinsics::_mm_shuffle_ps(rightW, rightW, 0);
    P064Quad rv = P064Intrinsics::_mm_mul_ps(rightW, left);
    P064Quad vectorPart = P064Intrinsics::_mm_add_ps(rv, P064Intrinsics::_mm_add_ps(lv, cross));
    P064Quaternion result;
    result.value =
        P064Intrinsics::_mm_shuffle_ps(vectorPart, P064Intrinsics::_mm_unpackhi_ps(vectorPart, realPart), 196);
    *this = result;
}
// src: COMMUNITY 0x00c74ac0
__declspec(noinline) void P064Quaternion::setMulInverse(const P064Quaternion* a, const P064Quaternion* b)
{
    P064Quad x = a->value, y = b->value;
    P064Quad cross = P064Cross(y, x);
    P064Quad xw = P064Intrinsics::_mm_shuffle_ps(x, x, 255);
    P064Quad yw = P064Intrinsics::_mm_shuffle_ps(y, y, 255);
    P064Quad vectorPart =
        P064Intrinsics::_mm_sub_ps(cross, P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(xw, xw, 0), y));
    vectorPart = P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(yw, yw, 0), x),
                                            vectorPart);
    P064Quad product = P064Intrinsics::_mm_mul_ps(y, x);
    P064Quad pairs = P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_shuffle_ps(product, product, 78), product);
    P064Quad sum = P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_shuffle_ps(pairs, pairs, 177), pairs);
    sum = P064Intrinsics::_mm_shuffle_ps(sum, sum, 0);
    P064Quaternion result;
    result.value = P064Intrinsics::_mm_shuffle_ps(vectorPart, P064Intrinsics::_mm_unpackhi_ps(vectorPart, sum), 196);
    *this = result;
}
// src: XBOX_PDB 0x00c755e0
__declspec(noinline) float P064Controller::bhkRagdollController_LimitBoneRot(int index, P064Quaternion* current)
{
    float angle = 0.0f;
    P064Slot& slot = slots[index];
    P064Quad difference =
        P064Intrinsics::_mm_and_ps(P064Intrinsics::_mm_sub_ps(current->value, slot.previous.value), DAT_01017d10);
    if ((P064Intrinsics::_mm_movemask_ps(
             P064Intrinsics::_mm_cmple_ps(difference, P064Intrinsics::_mm_set_ps1(DAT_01017d00))) &
         7) != 7)
    {
        P064Quaternion delta;
        delta.setMulInverse(current, &slot.previous);
        angle = delta.GetAngle();
        float degrees = enabled ? DAT_01267d30 : DAT_01267d24;
        double limit = degrees * 0.01745329238474369;
        if (angle > limit)
        {
            angle = (float)limit;
            P064Quad axis;
            delta.hkQuaternion_getAxis(&axis);
            P064Quad z = P064Intrinsics::_mm_set_ss(DAT_01011d78), t = P064Intrinsics::_mm_set_ss(DAT_01017718),
                     h = P064Intrinsics::_mm_set_ss(DAT_01016248);
            axis = P064Normalize(axis, z, t, h);
            delta.hkQuaternion_setAxisAngle(&axis, angle);
        }
        P064Quaternion rotation;
        rotation.setMul(&delta, &slot.previous);
        rotation.normalize_005611c0();
        P064Transform* destination = reinterpret_cast<P064Transform*>(slot.pose->hkaPose_accessBoneLocalSpace(slot.bone));
        destination->rotation.value = rotation.value;
        slot.previous.value = rotation.value;
    }
    return angle;
}
struct CharacterVector
{
    hkVector4 vector;
    float& component(int index)
    {
        return reinterpret_cast<float*>(&vector)[index];
    }
    void set(float a, float b, float c, float d)
    {
        vector.m_vComponents = _mm_setr_ps(a, b, c, d);
    }
};
struct ParticleArgument
{
    int unk00;
    int unk04;
    int unk08;
    int type;
};
struct ParticleResult
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ParticleArgument* inner;
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
};
struct ParticleOwner
{
    ParticleResult* hkpCharacterProxy_getShapePhantom();
};
struct ParticleSlot
{
    int unk00;
    int unk04;
    float value;
    int unk0c;
    void setTransformedPos_00c7f640(void* argument, hkVector4* vector);
};
struct CharacterProbeLocal
{
    int unk00;
    int unk04;
    ParticleOwner* owner;
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    unsigned char flags;
    unsigned char unk415, unk416, unk417;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    float elevation;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    ParticleSlot firstSlots[2];
    ParticleSlot secondSlots[2];
    float baseOffset;
    float height;
    void bhkCharacterController_InitFrontBack();
};
extern "C" double __cdecl atan(double);
__forceinline float AimMin(float a, float b)
{
    return a < b ? a : b;
}
__forceinline float AimMax(float a, float b)
{
    return a > b ? a : b;
}
struct AimNode_c70060
{
    int unk00, unk04;
    char* object;
};
extern float DAT_011b0148;
struct AimController_c70060
{
    unsigned int field_000;
    unsigned int field_004;
    unsigned int field_008;
    unsigned int field_00c;
    unsigned int field_010;
    unsigned int field_014;
    unsigned int field_018;
    unsigned int field_01c;
    unsigned int field_020;
    unsigned int field_024;
    unsigned int field_028;
    unsigned int field_02c;
    unsigned int field_030;
    unsigned int field_034;
    unsigned int field_038;
    unsigned int field_03c;
    unsigned int field_040;
    unsigned int field_044;
    unsigned int field_048;
    unsigned int field_04c;
    unsigned int field_050;
    unsigned int field_054;
    unsigned int field_058;
    unsigned int field_05c;
    unsigned int field_060;
    unsigned int field_064;
    unsigned int field_068;
    unsigned int field_06c;
    unsigned int field_070;
    unsigned int field_074;
    unsigned int field_078;
    unsigned int field_07c;
    unsigned int field_080;
    unsigned int field_084;
    unsigned int field_088;
    unsigned int field_08c;
    unsigned int field_090;
    unsigned int field_094;
    unsigned int field_098;
    unsigned int field_09c;
    unsigned int field_0a0;
    unsigned int field_0a4;
    unsigned int field_0a8;
    unsigned int field_0ac;
    unsigned int field_0b0;
    unsigned int field_0b4;
    unsigned int field_0b8;
    unsigned int field_0bc;
    unsigned int field_0c0;
    unsigned int field_0c4;
    unsigned int field_0c8;
    unsigned int field_0cc;
    unsigned int field_0d0;
    unsigned int field_0d4;
    unsigned int field_0d8;
    unsigned int field_0dc;
    unsigned int field_0e0;
    unsigned int field_0e4;
    unsigned int field_0e8;
    unsigned int field_0ec;
    unsigned int field_0f0;
    unsigned int field_0f4;
    unsigned int field_0f8;
    unsigned int field_0fc;
    unsigned int field_100;
    unsigned int field_104;
    unsigned int field_108;
    unsigned int field_10c;
    unsigned int field_110;
    unsigned int field_114;
    unsigned int field_118;
    unsigned int field_11c;
    unsigned int field_120;
    unsigned int field_124;
    unsigned int field_128;
    unsigned int field_12c;
    unsigned int field_130;
    unsigned int field_134;
    unsigned int field_138;
    unsigned int field_13c;
    unsigned int field_140;
    unsigned int field_144;
    unsigned int field_148;
    unsigned int field_14c;
    unsigned int field_150;
    unsigned int field_154;
    unsigned int field_158;
    unsigned int field_15c;
    unsigned int field_160;
    unsigned int field_164;
    unsigned int field_168;
    unsigned int field_16c;
    unsigned int field_170;
    unsigned int field_174;
    unsigned int field_178;
    unsigned int field_17c;
    unsigned int field_180;
    unsigned int field_184;
    unsigned int field_188;
    unsigned int field_18c;
    unsigned int field_190;
    unsigned int field_194;
    unsigned int field_198;
    unsigned int field_19c;
    unsigned int field_1a0;
    unsigned int field_1a4;
    unsigned int field_1a8;
    unsigned int field_1ac;
    unsigned int field_1b0;
    unsigned int field_1b4;
    unsigned int field_1b8;
    unsigned int field_1bc;
    unsigned int field_1c0;
    unsigned int field_1c4;
    unsigned int field_1c8;
    unsigned int field_1cc;
    unsigned int field_1d0;
    unsigned int field_1d4;
    unsigned int field_1d8;
    unsigned int field_1dc;
    unsigned int field_1e0;
    unsigned int field_1e4;
    unsigned int field_1e8;
    unsigned int field_1ec;
    unsigned int field_1f0;
    unsigned int field_1f4;
    unsigned int field_1f8;
    unsigned int field_1fc;
    unsigned int field_200;
    unsigned int field_204;
    unsigned int field_208;
    unsigned int field_20c;
    unsigned int field_210;
    unsigned int field_214;
    unsigned int field_218;
    unsigned int field_21c;
    unsigned int field_220;
    unsigned int field_224;
    unsigned int field_228;
    unsigned int field_22c;
    unsigned int field_230;
    unsigned int field_234;
    unsigned int field_238;
    unsigned int field_23c;
    unsigned int field_240;
    unsigned int field_244;
    unsigned int field_248;
    unsigned int field_24c;
    unsigned int field_250;
    unsigned int field_254;
    unsigned int field_258;
    unsigned int field_25c;
    unsigned int field_260;
    unsigned int field_264;
    unsigned int field_268;
    unsigned int field_26c;
    unsigned int field_270;
    unsigned int field_274;
    unsigned int field_278;
    unsigned int field_27c;
    unsigned int field_280;
    unsigned int field_284;
    unsigned int field_288;
    unsigned int field_28c;
    unsigned int field_290;
    unsigned int field_294;
    unsigned int field_298;
    unsigned int field_29c;
    unsigned int field_2a0;
    unsigned int field_2a4;
    unsigned int field_2a8;
    unsigned int field_2ac;
    unsigned int field_2b0;
    unsigned int field_2b4;
    unsigned int field_2b8;
    unsigned int field_2bc;
    unsigned int field_2c0;
    unsigned int field_2c4;
    unsigned int field_2c8;
    unsigned int field_2cc;
    unsigned int field_2d0;
    unsigned int field_2d4;
    unsigned int field_2d8;
    unsigned int field_2dc;
    unsigned int field_2e0;
    unsigned int field_2e4;
    unsigned int field_2e8;
    unsigned int field_2ec;
    unsigned int field_2f0;
    unsigned int field_2f4;
    unsigned int field_2f8;
    unsigned int field_2fc;
    unsigned int field_300;
    unsigned int field_304;
    unsigned int field_308;
    unsigned int field_30c;
    unsigned int field_310;
    unsigned int field_314;
    unsigned int field_318;
    unsigned int field_31c;
    unsigned int field_320;
    unsigned int field_324;
    unsigned int field_328;
    unsigned int field_32c;
    unsigned int field_330;
    unsigned int field_334;
    unsigned int field_338;
    unsigned int field_33c;
    unsigned int field_340;
    unsigned int field_344;
    unsigned int field_348;
    unsigned int field_34c;
    unsigned int field_350;
    unsigned int field_354;
    unsigned int field_358;
    unsigned int field_35c;
    unsigned int field_360;
    unsigned int field_364;
    unsigned int field_368;
    unsigned int field_36c;
    unsigned int field_370;
    unsigned int field_374;
    unsigned int field_378;
    unsigned int field_37c;
    unsigned int field_380;
    unsigned int field_384;
    unsigned int field_388;
    unsigned int field_38c;
    unsigned int field_390;
    unsigned int field_394;
    unsigned int field_398;
    unsigned int field_39c;
    unsigned int field_3a0;
    unsigned int field_3a4;
    unsigned int field_3a8;
    unsigned int field_3ac;
    unsigned int field_3b0;
    unsigned int field_3b4;
    unsigned int field_3b8;
    unsigned int field_3bc;
    unsigned int field_3c0;
    unsigned int field_3c4;
    unsigned int field_3c8;
    unsigned int field_3cc;
    unsigned int field_3d0;
    unsigned int field_3d4;
    unsigned int field_3d8;
    unsigned int field_3dc;
    unsigned int field_3e0;
    unsigned int field_3e4;
    unsigned int field_3e8;
    unsigned int field_3ec;
    unsigned int field_3f0;
    unsigned int field_3f4;
    unsigned int field_3f8;
    unsigned int field_3fc;
    unsigned int field_400;
    unsigned int field_404;
    unsigned int field_408;
    unsigned int field_40c;
    unsigned int field_410;
    unsigned int field_414;
    unsigned int field_418;
    unsigned int field_41c;
    unsigned int field_420;
    unsigned int field_424;
    unsigned int field_428;
    unsigned int field_42c;
    unsigned int field_430;
    unsigned int field_434;
    unsigned int field_438;
    unsigned int field_43c;
    unsigned int field_440;
    unsigned int field_444;
    unsigned int field_448;
    unsigned int field_44c;
    float field_450;
    float field_454;
    float field_458;
    float field_45c;
    float field_460;
    float field_464;
    float field_468;
    float field_46c;
    unsigned int field_470;
    unsigned int field_474;
    unsigned int field_478;
    unsigned int field_47c;
    unsigned int field_480;
    unsigned int field_484;
    unsigned int field_488;
    unsigned int field_48c;
    unsigned int field_490;
    unsigned int field_494;
    unsigned int field_498;
    unsigned int field_49c;
    unsigned int field_4a0;
    unsigned int field_4a4;
    unsigned int field_4a8;
    unsigned int field_4ac;
    unsigned int field_4b0;
    unsigned int field_4b4;
    unsigned int field_4b8;
    unsigned int field_4bc;
    unsigned int field_4c0;
    unsigned int field_4c4;
    unsigned int field_4c8;
    unsigned int field_4cc;
    unsigned int field_4d0;
    unsigned int field_4d4;
    unsigned int field_4d8;
    unsigned int field_4dc;
    unsigned int field_4e0;
    unsigned int field_4e4;
    unsigned int field_4e8;
    unsigned int field_4ec;
    unsigned int field_4f0;
    unsigned int field_4f4;
    unsigned int field_4f8;
    unsigned int field_4fc;
    unsigned int field_500;
    unsigned int field_504;
    unsigned int field_508;
    unsigned int field_50c;
    unsigned int field_510;
    unsigned int field_514;
    unsigned int field_518;
    unsigned int field_51c;
    unsigned int field_520;
    unsigned int field_524;
    unsigned int field_528;
    unsigned int field_52c;
    float field_530;
    unsigned int field_534;
    unsigned int field_538;
    unsigned int field_53c;
    unsigned int field_540;
    unsigned int field_544;
    unsigned int field_548;
    unsigned int field_54c;
    float field_550;
    float field_554;
    float field_558;
    unsigned int field_55c;
    unsigned int field_560;
    unsigned int field_564;
    unsigned int field_568;
    unsigned int field_56c;
    unsigned int field_570;
    unsigned int field_574;
    unsigned int field_578;
    unsigned int field_57c;
    unsigned int field_580;
    unsigned int field_584;
    unsigned int field_588;
    unsigned int field_58c;
    unsigned int field_590;
    AimNode_c70060* field_594;
    unsigned int field_598;
    unsigned int field_59c;
    unsigned int field_5a0;
    unsigned int field_5a4;
    unsigned int field_5a8;
    unsigned int field_5ac;
    unsigned int field_5b0;
    unsigned int field_5b4;
    unsigned int field_5b8;
    unsigned int field_5bc;
    unsigned int field_5c0;
    unsigned int field_5c4;
    unsigned int field_5c8;
    unsigned int field_5cc;
    unsigned int field_5d0;
    unsigned int field_5d4;
    unsigned int field_5d8;
    unsigned int field_5dc;
    unsigned int field_5e0;
    unsigned int field_5e4;
    unsigned int field_5e8;
    unsigned int field_5ec;
    unsigned int field_5f0;
    float field_5f4;
    void bhkCharacterController_FindSupportPoint(int index, Vec4* result);
    void bhkCharacterController_CalculatePitchAndRoll();
};
struct S00c70550_Point3
{
    float x, y, z;
};
void __stdcall SubtractVectors(Vec4* pOut);
void __cdecl FUN_00458620(S00c70550_Point3* pOut, const Vec4* pIn);
class FUN_00c70550_cls
{
  public:
    float bhkCharacterController_GetFallDistance();
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    float m_fOriginZ;
};
struct C74570_Ctrl
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
    virtual void Apply(float t, void* data);
};
struct C74570_Obj
{
    void Update();
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
    C74570_Ctrl ctrl;
};
struct C74570_Item
{
    int unk00;
    int unk04;
    C74570_Obj* obj;
};
struct C74570_Node
{
    C74570_Item* item;
    C74570_Node* next;
};
struct C74570_Mat
{
    Vec4 r0;
    Vec4 r1;
    Vec4 r2;
    void Build(void* out, float angle);
};
struct C74570_Xf
{
    Vec4 a;
    void Combine(void* p, void* q);
};
extern float DAT_01267c14;
extern float DAT_01267c18;
extern float DAT_011b02dc;
extern float DAT_011b02e0;
extern float DAT_01064f60;
extern double DAT_010c4b20;
struct C74570_This
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
    virtual float Eval(float t);
    int unk04;
    bool enabled;
    C74570_Node list;
    void bhkWindListener_Update(float dt);
};
struct P064Vector
{
    P064Quad value;
    void FUN_00c7f7a0(const void*, const void*);
};
struct MainClass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    P064Quad m_10;
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
    P064Pose* m_88;
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    P064Pose* m_f0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    short m_144;
    short unk146;
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
    unsigned char m_190;
    bool __thiscall bhkRagdollController_GetEyeOffset(void* out);
};
class SupportScalar
{
    P064Quad value;

  public:
    __forceinline SupportScalar(const P064Quad& q) : value(q)
    {}
    __forceinline operator float() const
    {
        float result;
        P064Intrinsics::_mm_store_ss(&result, value);
        return result;
    }
};
class SupportVector
{
    P064Quad value;

  public:
    __forceinline SupportVector()
    {}
    __forceinline void Difference(const SupportVector& a, const SupportVector& b)
    {
        value = P064Intrinsics::_mm_sub_ps(a.value, b.value);
    }
    __forceinline float& operator()(int lane)
    {
        return reinterpret_cast<float*>(&value)[lane];
    }
    __forceinline SupportScalar Dot(const SupportVector& b) const
    {
        P064Quad product = P064Intrinsics::_mm_mul_ps(value, b.value);
        P064Quad xy = P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(product, product, 0x55), product);
        return P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(product, product, 0xaa), xy);
    }
    __forceinline SupportScalar SquaredLength() const
    {
        return Dot(*this);
    }
    __forceinline SupportScalar Component(int lane) const
    {
        switch (lane)
        {
        case 0:
            return value;
        case 1:
            return P064Intrinsics::_mm_shuffle_ps(value, value, 0x55);
        case 2:
            return P064Intrinsics::_mm_shuffle_ps(value, value, 0xaa);
        default:
            return P064Intrinsics::_mm_shuffle_ps(value, value, 0xff);
        }
    }
};
struct SupportListener
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
    float m_fGlyphExtent[4];

    void Blend(unsigned index, float elevation)
    {
        if (m_fGlyphExtent[index] == 1.17549435e-38f)
            m_fGlyphExtent[index] = elevation;
        else
        {
            m_fGlyphExtent[index] += elevation;
            m_fGlyphExtent[index] *= 0.5;
        }
    }
    void bhkCharacterListener_AddSupportHeight2(const SupportVector* corners, const SupportVector& point);
};
// Exact matching requires correcting the compiler settings: the original is optimized, while these checks use /Od.
extern int DAT_01034ec4;
struct S00c6e680_C6RayInput
{
    LocalM128 from;
    LocalM128 to;
    bool enableShapeCollectionFilter;
    unsigned int filterInfo;
    unsigned int unk28;
    unsigned int unk2C;

    __forceinline S00c6e680_C6RayInput() : enableShapeCollectionFilter(false), filterInfo(0)
    {}
};
struct S00c6e680_C6RayOutput
{
    LocalM128 normal;
    float hitFraction;
    int m_uiExtraInfo;
    int unk18;
    int unk1C;
    unsigned int shapeKeys[8];
    void* rootCollidable;

    __forceinline S00c6e680_C6RayOutput() : hitFraction(1.0f), m_uiExtraInfo(-1), rootCollidable(0)
    {
        shapeKeys[0] = -1;
    }
};
struct S00c6e680_C6RayOutputPlain
{
    LocalM128 normal;
    float hitFraction;
    int m_uiExtraInfo;
    int unk18;
    int unk1C;
    unsigned int shapeKeys[8];
    void* rootCollidable;

    __forceinline void reset()
    {
        hitFraction = 1.0f;
        m_uiExtraInfo = -1;
        rootCollidable = 0;
        shapeKeys[0] = -1;
    }
};
struct S00c6e680_C6Collector
{
    void* table;
    float earlyOutHitFraction;
    unsigned int unk08;
    unsigned int unk0C;
    S00c6e680_C6RayOutputPlain output;
    void* unk60;

    __forceinline S00c6e680_C6Collector() : table(&DAT_01034ec4), unk60(0)
    {
        output.reset();
        earlyOutHitFraction = 1.0f;
    }
    __forceinline ~S00c6e680_C6Collector()
    {
        table = &DAT_01034ec4;
    }
};
struct S00c6e680_C6PickData
{
    S00c6e680_C6RayInput input;
    S00c6e680_C6RayOutput output;
    void* unk80;
    char unk84[12];
    LocalM128 unk90;
    unsigned int unkA0;
    S00c6e680_C6Collector* collectorPointer;
    unsigned int unkA8;
    bool unkAC;
    S00c6e680_C6Collector collector;

    __forceinline S00c6e680_C6PickData() : unk80(0), unkA0(0), unkAC(false)
    {}

    __forceinline ~S00c6e680_C6PickData()
    {}
};
struct S00c6e680_C6Bool
{
    char m_cBooleanValue;
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
struct S00c6e680_C6World
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
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual bool Pick(S00c6e680_C6PickData&);
};
struct S00c6e680_C6WorldObject
{
    __forceinline S00c6e680_C6World* GetWorld()
    {
        return *(S00c6e680_C6World**)((char*)this + 0x350);
    }
};
struct S00c6e680_C6HolderResult
{
    unsigned int unk00;
    unsigned int unk04;
    S00c6e680_C6WorldObject* object;
};
struct S00c6e680_Holder
{
    void* hkpCharacterProxy_getShapePhantom();
};
struct S00c6e680_Ctrl
{
    void bhkCharacterController_GetCollisionFilter(unsigned int&);
};
struct S00c6e680_Class : S00c6e680_Ctrl
{
    void bhkCharacterController_FindSupportPoint(int index, LocalM128* position);
};

extern P064Quad probe_vectors[16];
extern void probe_consume(char*, int);
namespace P064Intrinsics {
using ::_mm_load_ss;
}

extern unsigned int DAT_011afe80;
extern unsigned char DAT_012677a2;
extern bool DAT_011b0c44;
// The shared vector has no setAnd or lessEqual3 declarations.
inline void Vec4SetAnd(Vec4& result, const Vec4& a, const Vec4& b)
{
    result.m_vComponents = _mm_and_ps(a.m_vComponents, b.m_vComponents);
}
inline int Vec4LessEqual3(const Vec4& a, const Vec4& b)
{
    return _mm_movemask_ps(_mm_cmple_ps(a.m_vComponents, b.m_vComponents)) & 7;
}
inline void Vec4::setSub4(const Vec4& a, const Vec4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

// These velocity helpers are not declared by the shared bhkWorldObject.
// A single fastcall object argument preserves their ECX-only member-call ABI.
P064Quad* __fastcall bhkRigidBody_GetLinearVelocity_00560d80(bhkWorldObject* body);
P064Quad* __fastcall bhkRigidBody_GetAngularVelocity(bhkWorldObject* body);
struct QueuedShape
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned char flags;
};
struct ShapeLink
{
    unsigned int unk00, unk04, unk08;
    QueuedShape* shape;
    signed char displacement;
    unsigned char unk11, unk12, unk13;
    unsigned int unk14;
    unsigned char kind;
};
struct IntegerMapEntry
{
    unsigned int unk00, unk04, unk08;
    bhkWorldObject* body;
    ShapeLink link;
    void FUN_00c90510();
};
struct QueueReceiver
{
    void hkpWorld_addEntity(IntegerMapEntry*, int);
    void hkpWorld_addPhantom(IntegerMapEntry*);
};
struct QueueManager
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
    virtual QueueReceiver* receiver();
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    unsigned int deferred;
    unsigned int unk1c, unk20, unk24, unk28;
    IntegerMapEntry** bodies;
    unsigned int bodyCount;
    IntegerMapEntry** shapes;
    unsigned int shapeCount;
    void bhkWorld_AddEntities(IntegerMapEntry**, unsigned int);
    void ClearIndexedValues();
    void bhkWorld_AddBatchedActions();
    void ProcessConstraints();
    void bhkWorld_Add_00c6b0a0(IntegerMapEntry* entry);
};

// @fnv 0x00c6b0a0
// src: XBOX_PDB 0x00c6b0a0
void QueueManager::bhkWorld_Add_00c6b0a0(IntegerMapEntry* entry)
{
    if (!this)
        return;
    QueueReceiver* destination = receiver();
    if (!destination)
        return;
    if (entry->link.kind == 1)
    {
        if (deferred > 0)
        {
            bhkWorldObject* body = entry->body;
            if (!body || (body->iFlags & 0x30))
                return;
            if (bodyCount >= 3000)
            {
                if (bodyCount > 0)
                {
                    bodyCount = 3000;
                    unsigned int removeCount = DAT_011afe80;
                    if (removeCount > 3000)
                        removeCount = 3000;
                    unsigned int remaining = 3000 - removeCount;
                    bhkWorld_AddEntities(bodies + remaining, removeCount);
                    bodyCount = remaining;
                    DAT_012677a2 = 1;
                }
                ClearIndexedValues();
                bhkWorld_AddBatchedActions();
                ProcessConstraints();
            }
            body->iFlags |= 0x10;
            entry->FUN_00c90510();
            bodies[bodyCount++] = entry;
        }
        else
        {
            bhkWorldObject* body = entry->body;
            if (!body || (body->iFlags & 0x30))
                return;
            int active = 1;
            if (DAT_011b0c44)
            {
                if ((body->GetFilter().value & 0x7f) == 8)
                {
                }
                else
                {
                    Vec4 d0;
                    d0.setSub4(*(const Vec4*)bhkRigidBody_GetLinearVelocity_00560d80(body), *(const Vec4*)&DAT_01267e30);
                    Vec4 tolerance;
                    P064Quad tolss = P064Intrinsics::_mm_load_ss(&DAT_01017d00);
                    tolerance.m_vComponents = _mm_shuffle_ps(*reinterpret_cast<const LocalM128*>(&tolss), *reinterpret_cast<const LocalM128*>(&tolss), 0);
                    Vec4SetAnd(d0, d0, *(const Vec4*)&DAT_01017d10);
                    if (Vec4LessEqual3(d0, tolerance) == 7)
                    {
                        Vec4 d1;
                        d1.setSub4(*(const Vec4*)bhkRigidBody_GetAngularVelocity(body), *(const Vec4*)&DAT_01267e30);
                        Vec4SetAnd(d1, d1, *(const Vec4*)&DAT_01017d10);
                        if (Vec4LessEqual3(d1, tolerance) == 7)
                            active = 0;
                    }
                }
            }
            destination->hkpWorld_addEntity(entry, active);
        }
    }
    else
    {
        if (deferred > 0)
        {
            ShapeLink* link = &entry->link;
            if (link->kind != 2)
                return;
            ShapeLink* owner = reinterpret_cast<ShapeLink*>(reinterpret_cast<char*>(link) + link->displacement);
            if (!owner)
                return;
            QueuedShape* shape = owner->shape;
            if (!shape || (shape->flags & 0x30))
                return;
            if (shapeCount >= 200)
            {
                if (bodyCount > 0 && !DAT_012677a2)
                {
                    if (bodyCount >= 3000)
                        bodyCount = 3000;
                    unsigned int currentCount = bodyCount;
                    unsigned int removeCount = DAT_011afe80;
                    if (currentCount < removeCount)
                        removeCount = currentCount;
                    unsigned int remaining = currentCount - removeCount;
                    bhkWorld_AddEntities(bodies + remaining, removeCount);
                    bodyCount = remaining;
                    DAT_012677a2 = 1;
                }
                ClearIndexedValues();
                bhkWorld_AddBatchedActions();
                ProcessConstraints();
            }
            shape->flags |= 0x10;
            entry->FUN_00c90510();
            shapes[shapeCount++] = entry;
        }
        else
        {
            ShapeLink* link = &entry->link;
            if (link->kind != 2)
                return;
            ShapeLink* owner = reinterpret_cast<ShapeLink*>(reinterpret_cast<char*>(link) + link->displacement);
            if (!owner)
                return;
            QueuedShape* shape = owner->shape;
            if (!shape || (shape->flags & 0x30))
                return;
            destination->hkpWorld_addPhantom(entry);
        }
    }
}

// src: COMMUNITY 0x00560e10
__declspec(noinline) P064Quad* __fastcall bhkRigidBody_GetAngularVelocity(bhkWorldObject* body)
{
    P064Quad a0 = probe_vectors[0];
    P064Quad a1 = probe_vectors[1];
    P064Quad a2 = probe_vectors[2];
    P064Quad a3 = probe_vectors[3];
    P064Quad a4 = probe_vectors[4];
    P064Quad a5 = probe_vectors[5];
    P064Quad a6 = probe_vectors[6];
    P064Quad a7 = probe_vectors[7];
    probe_vectors[0] = P064Intrinsics::_mm_sub_ps(a0, a1);
    probe_vectors[1] = P064Intrinsics::_mm_sub_ps(a1, a2);
    probe_vectors[2] = P064Intrinsics::_mm_sub_ps(a2, a3);
    probe_vectors[3] = P064Intrinsics::_mm_sub_ps(a3, a4);
    probe_vectors[4] = P064Intrinsics::_mm_sub_ps(a4, a5);
    probe_vectors[5] = P064Intrinsics::_mm_sub_ps(a5, a6);
    probe_vectors[6] = P064Intrinsics::_mm_sub_ps(a6, a7);
    probe_vectors[7] = P064Intrinsics::_mm_sub_ps(a7, a0);
    return probe_vectors;
}

using ::_mm_set_ps1;
using ::_mm_load_ss;

struct ScalarRead
{
    float value;
    operator float() const
    {
        return value;
    }
};
struct ScaleValue
{
    float getScale();
};
struct PhysicsBody
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
    unsigned int unk02c;
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
    ScaleValue scale;
    void RetainReference();
    void removeReference();
};
struct ContactInput
{
    LocalM128 position;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    PhysicsBody* body;
    PhysicsBody* GetBody()
    {
        return body;
    }
};
struct Prefix
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
};
struct ControllerPrefix
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
};
struct ControllerFields
{
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
    LocalM128 unk0e0;
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
    float unk1e4;
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
    PhysicsBody* unk220;
    float unk224;
};
struct Controller : ControllerPrefix, ControllerFields
{
    bool HasFirst() const
    {
        return (unk004 & 1) != 0;
    }
    bool HasFourth() const
    {
        return ((unk004 >> 3) & 1) != 0;
    }
    void bhkCharacterController_objectInteractionCallback(void*, ContactInput*, LocalM128*);
};
struct Owner : Prefix, Controller
{
    void getPosition(LocalM128*);
};
extern float DAT_011b0128;
extern const float DAT_01011d78;
// @fnv 0x00c6f280
// src: XBOX_PDB 0x00c6f280
void Controller::bhkCharacterController_objectInteractionCallback(void*, ContactInput* contact, LocalM128* velocity)
{
    ScaleValue* scaleValue = &contact->GetBody()->scale;
    float scale = scaleValue->getScale();
    LocalM128 square = _mm_mul_ps(*velocity, *velocity);
    LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(square, square, 0x55), square);
    sum = _mm_add_ss(_mm_shuffle_ps(square, square, 0xaa), sum);
    ScalarRead length;
    _mm_store_ss(&length.value, _mm_sqrt_ss(sum));
    float result = length;
    if (scale > 0.0f && scale < DAT_011b0128)
    {
        unsigned int kind = contact->body->unk02c & 0x7f;
        float factor;
        switch (kind)
        {
        case 6:
            factor = 0.0f;
            break;
        case 10:
            if (scale > DAT_011b0128 * 0.5)
                factor = 0.1f;
            else
                factor = 3.0f;
            break;
        case 14:
            factor = 0.1f;
            break;
        default:
            factor = 2.0f;
            break;
        }
        float ratio = length / scale;
        if (ratio > 1000.0)
            factor *= 1000.0 / ratio;
        if (!HasFirst() && HasFourth())
        {
            // Keep the original byte-buffer stack protection with the shared vector layout.
            __declspec(align(16)) unsigned char deltaStorage[sizeof(Vec4)];
            Vec4 delta;
            (this->*static_cast<void (Controller::*)(LocalM128*)>(&Owner::getPosition))(reinterpret_cast<LocalM128*>(deltaStorage));
            delta.m_vComponents = *reinterpret_cast<const LocalM128*>(deltaStorage);
            delta.m_vComponents = _mm_sub_ps(contact->position, delta.m_vComponents);
            if (delta.m_vComponents.m128_f32[2] > unk1e4 * 0.8999999761581421)
            {
                LocalM128 v = unk0e0;
                LocalM128 sq = _mm_mul_ps(v, v);
                LocalM128 mag = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
                mag = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), mag);
                LocalM128 inv = _mm_rsqrt_ss(mag);
                LocalM128 normalized = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inv),
                                               _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(mag, inv), inv)));
                normalized = _mm_andnot_ps(_mm_cmpeq_ss(mag, _mm_set_ss(DAT_01011d78)), normalized);
                *velocity = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(normalized, normalized, 0), v), _mm_set_ps1(result));
            }
        }
        LocalM128 scalar = _mm_load_ss(&factor);
        LocalM128 splat = _mm_shuffle_ps(scalar, scalar, 0);
        *velocity = _mm_mul_ps(splat, *velocity);
        result = factor * (float)length;
    }
    else
        *velocity = _mm_setzero_ps();
    if (result > unk224)
    {
        unk224 = result;
        PhysicsBody* body = contact->body;
        if (body)
            body->RetainReference();
        if (unk220)
            unk220->removeReference();
        unk220 = body;
    }
}

namespace SimdC {
typedef ::__m128 LocalM128;
using ::_mm_set_ps;
using ::_mm_setr_ps;
using ::_mm_setzero_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_shuffle_ps;
using ::_mm_add_ss;
using ::_mm_sub_ss;
using ::_mm_mul_ss;
using ::_mm_rsqrt_ss;
using ::_mm_cmpeq_ss;
using ::_mm_set_ss;
using ::_mm_load_ss;
using ::_mm_set_ps1;
using ::_mm_andnot_ps;
using ::_mm_cvtss_f32;
using ::_mm_store_ss;
using ::_mm_store_ps;
using ::_mm_load_ps;
using ::_mm_move_ss;

}
extern "C" unsigned long __readfsdword(unsigned long);
extern "C" double __cdecl sqrt(double);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct Vec3C
{
    float x, y, z;
    float dot(const Vec3C& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
    Vec3C operator*(float scale) const
    {
        Vec3C r = {scale * x, scale * y, scale * z};
        return r;
    }
    Vec3C& operator-=(const Vec3C& b)
    {
        x -= b.x;
        y -= b.y;
        z -= b.z;
        return *this;
    }
};
struct NP3
{
    float x, y, z;
    NP3()
    {}
    NP3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    NP3 operator*(float s) const
    {
        return NP3(x * s, y * s, z * s);
    }
    NP3 operator/(float s) const
    {
        float inv = 1.0f / s;
        return NP3(x * inv, y * inv, z * inv);
    }
};
struct BodyC;
struct ShapeC;
struct CollidableC;
struct WorldC;
struct ParentC;
struct RayInputC;
struct RayOutputC;
struct HkBoolC
{
    char value;
};
struct Vec4C
{
    SimdC::LocalM128 value;
    Vec4C()
    {}
    Vec4C(SimdC::LocalM128 x) : value(x)
    {}
    operator SimdC::LocalM128() const
    {
        return value;
    }
    Vec4C& operator=(SimdC::LocalM128 x)
    {
        value = x;
        return *this;
    }
    Vec4C& operator=(const Vec4C& o)
    {
        value = o.value;
        return *this;
    }
};
struct NodeC
{
    unsigned int unk00, unk04;
    BodyC* body;
};
struct MaterialC
{
    unsigned int unk00, unk04, unk08, unk0c;
    union
    {
        unsigned int flags;
        struct
        {
            unsigned char flagLo, flagMid, flagHi, flagTop;
        };
    };
    char typeC() const
    {
        return flags & 0x1f;
    }
    unsigned char typeU() const
    {
        return flags & 0x1f;
    }
    int typeI() const
    {
        return flags & 0x1f;
    }
};
struct ShapeC
{
    virtual void v00();
    virtual int type();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual HkBoolC RayCast(RayInputC*, RayOutputC*);
    unsigned int unk04;
    MaterialC* material;
    int kind;
    float radius;
};
struct ShapeChildrenC
{
    unsigned int unk00, unk04, unk08, unk0c;
    ShapeC* first;
    unsigned int unk14, unk18, unk1c;
    ShapeC* second;
};
struct ShapeInterfaceC
{
    virtual void v00();
    virtual int type();
};
struct WrappedShapeC
{
    unsigned int unk00, unk04, unk08;
    int kind;
    ShapeInterfaceC shape;
    unsigned int unk14;
    ShapeChildrenC* children;
};
struct CollidableC
{
    ShapeC* shape;
    unsigned int unk04, unk08, unk0c;
    signed char ownerOffset;
    unsigned char unk11, unk12, unk13;
    unsigned int unk14;
    unsigned char ownerType, unk19, unk1a, unk1b;
    unsigned int material;
    __forceinline unsigned char ownerKind() const
    {
        return ownerType;
    }
    BodyC* owner()
    {
        return ownerType == 1 ? reinterpret_cast<BodyC*>(reinterpret_cast<char*>(this) + ownerOffset) : 0;
    }
};
struct ContactC
{
    SimdC::LocalM128 position, normal;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    CollidableC* collidable;
    unsigned int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
};
struct ContactListC
{
    ContactC* data;
    int count;
};
struct ResponseC
{
    SimdC::LocalM128 normal, other;
    float unk20, unk24, friction, weight;
    unsigned int unk30, unk34, unk38, unk3c;
    void UpdateState_00c6d670(const ResponseC*);
};
struct ResultC
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44;
    ResponseC* data;
    int count;
};
struct TransformC
{
    SimdC::LocalM128 axisX, axisY, axisZ, translation;
};
struct BodyC
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    NodeC* sceneNode;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int filter;
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
    SimdC::LocalM128 transform;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    float motionValue;
    unsigned int unk0e4;
    unsigned char motionType;
    unsigned char unk0e9;
    unsigned short unk0ea;
    unsigned int unk0ec;
    TransformC worldTransform;
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
    CollidableC** collidables;
    int collidableCount;
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
    Vec3C velocity;
    void FUN_00c90510();
    void FUN_00c905b0();
};
struct ProxyC
{
    const char* hkpCharacterProxy_getLinearVelocity();
};
struct ParentPrefixC
{
    virtual void pv00();
    unsigned int unk004;
    ProxyC* proxy;
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
    unsigned int nearProxy;
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
};
struct ListenerC
{
    virtual void lv00();
    virtual void bhkCharacterController_processConstraintsCallback(void*, ContactListC*, ResultC*);
    void bhkCharacterListener_AddSupportHeight2(TransformC*, ContactC*);
};
struct ParentC : ParentPrefixC, ListenerC
{
    union
    {
        unsigned int flags;
        struct
        {
            unsigned char flagLo, flagMid, flagHi, flagTop;
        };
    };
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    float threshold;
    unsigned int unk024;
    unsigned int material;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    Vec4C normal;
    float minX;
    float minY;
    float minZ;
    float minW;
    float height;
    unsigned int unk064;
    bool allAuxiliary;
    unsigned char unk069;
    unsigned short unk06a;
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
    SimdC::LocalM128 initialNormal;
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
    float scale;
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
    NodeC* node;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    NodeC* shapeNode;
    unsigned int unk198;
    unsigned int unk19c;
    TransformC transform;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    int accepted;
    BodyC* reference;
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
    unsigned int entries;
    char getFlag(unsigned int n) const
    {
        return (unsigned char)(flags >> n) & 1;
    }
    void SetFlag(unsigned int m, bool b)
    {
        if (b)
            flags |= m;
        else
            flags &= ~m;
    }
    virtual void bhkCharacterController_processConstraintsCallback(void*, ContactListC*, ResultC*);
    void bhkCharacterProxy_MarkRead();
    void SubtractVectors(Vec4C*);
    bool bhkCharacterController_IsStep(ContactC*);
    void bhkCharacterController_SetSupportMaterial(ContactC*);
    ParentC* bhkCharacterController_Getbhk(void*);
};
struct TLSC
{
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
    unsigned int context;
};
extern unsigned int DAT_0126fd98;
extern __declspec(thread) TLSC g_tlsBlock;
static __forceinline TLSC* currentTLS()
{
    return &g_tlsBlock;
}
struct ContextC
{
    unsigned int old;
    __forceinline ContextC()
    {
        old = currentTLS()->context;
        currentTLS()->context = 16;
    }
    __forceinline ~ContextC()
    {
        currentTLS()->context = old;
    }
};

struct PointerArrayC
{
    CollidableC** data;
    int count;
    int capacity;
    PointerArrayC() : data(0), count(0), capacity(0x80000000)
    {}
    ~PointerArrayC()
    {
        HeapContext* system = hkMemoryRouter_getInstance();
        HeapAllocator* a = system->allocator;
        count = 0;
        if (!(static_cast<unsigned int>(capacity) & 0x80000000))
            a->Deallocate(data, (capacity & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }
};
void hkArrayUtil__reserve(HeapAllocator*, PointerArrayC*, int, int);
void ExtractStiltCapsuleInfo(ShapeC*, const void*, SimdC::LocalM128*);
bool bhkCharacterController_IsHurtfulBody(BodyC*);
extern float DAT_011c3d18;
struct ComponentC
{
    SimdC::LocalM128 value;
    float EvaluateValue_004586d0();
};
struct ComponentSourceC
{
    ComponentC hkVector4_getSimdAt(int) const;
};
float HK2NI(float);
__declspec(noinline) Vec3C* FUN_00458620(Vec3C* output, const void* input)
{
    const ComponentSourceC* src = reinterpret_cast<const ComponentSourceC*>(input);
    output->x = HK2NI(src->hkVector4_getSimdAt(0).EvaluateValue_004586d0());
    output->y = HK2NI(src->hkVector4_getSimdAt(1).EvaluateValue_004586d0());
    output->z = HK2NI(src->hkVector4_getSimdAt(2).EvaluateValue_004586d0());
    return output;
}

struct PointerC
{
    void FUN_0066b0d0(void*);
};
extern MemoryManager _g_memoryManager;
struct FUN_00c6d9f0
{
    PointerC object;
    Vec3C position, normal, velocity;
    FUN_00c6d9f0() throw();
    static void* operator new(unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
};
struct EntryListC
{
    void PushItem(FUN_00c6d9f0**);
};

extern float DAT_01267bb0;
extern BodyC* DAT_01267bb4;
extern SimdC::LocalM128 DAT_01267c00, DAT_01267bf0;
extern unsigned int DAT_01267c10;
extern float DAT_010c4aa0, DAT_010c4a9c, DAT_010a5898, DAT_010c4a98, DAT_011b0128, DAT_01015f5c;
extern double DAT_010c4ab0, DAT_010c4aa8;
struct MotionC
{
    float FUN_00c86430();
};
bool bhkRigidBody_IsMotionTypeDynamic(const int&);
int __fastcall hkpCharacterContext_getState(void*);
MaterialC* bhkUtilFunctions_FindbhkShapeCollection(CollidableC*);
struct RayVecC
{
    SimdC::LocalM128 value;
    void hkVector4_setTransformedInversePos(TransformC*, SimdC::LocalM128*);
};
struct RayInputC
{
    RayVecC from, to;
    int filter;
    int collectionFilter;
    unsigned int unk28, unk2c;
};
struct RayOutputFieldsC
{
    SimdC::LocalM128 normal;
    float fraction;
    int key, unk18, unk1c;
    int keys[8];
    void* root;
    void reset()
    {
        fraction = 1.0f;
        key = -1;
        root = 0;
        keys[0] = -1;
    }
};
struct RayOutputC : RayOutputFieldsC
{
    RayOutputC()
    {
        reset();
    }
};
extern int DAT_01034ec4;
struct RayHitCollectorC
{
    float fraction;
    RayHitCollectorC()
    {
        fraction = 1.0f;
    }
    virtual void CollectRayHit(const void*, const void*) = 0;
    virtual ~RayHitCollectorC()
    {}
};
struct CollectorC : RayHitCollectorC
{
    unsigned int unk08, unk0c;
    RayOutputFieldsC result;
    void* object;
    CollectorC()
    {
        object = 0;
        result.reset();
        fraction = 1.0f;
    }
    virtual void CollectRayHit(const void*, const void*);
};
static __forceinline float laneValue(SimdC::LocalM128 v)
{
    return v.m128_f32[0];
}
static __forceinline float laneStored(SimdC::LocalM128 v)
{
    float out;
    SimdC::_mm_store_ss(&out, v);
    return out;
}

static __forceinline SimdC::LocalM128 zaxis(float z)
{
    return SimdC::_mm_setr_ps(0.0f, 0.0f, z, 0.0f);
}
static __forceinline void lengthSquared(SimdC::LocalM128 v, float& out)
{
    SimdC::LocalM128 q = SimdC::_mm_mul_ps(v, v);
    SimdC::_mm_store_ss(&out, SimdC::_mm_add_ss(SimdC::_mm_shuffle_ps(q, q, 0xaa),
                                                SimdC::_mm_add_ss(SimdC::_mm_shuffle_ps(q, q, 0x55), q)));
}
static __forceinline float lengthSquaredValue(SimdC::LocalM128 v)
{
    float out;
    lengthSquared(v, out);
    return out;
}
static const float kZero = 0.0f;
static __forceinline SimdC::LocalM128 normalized(SimdC::LocalM128 v)
{
    SimdC::LocalM128 q = SimdC::_mm_mul_ps(v, v);
    SimdC::LocalM128 d =
        SimdC::_mm_add_ss(SimdC::_mm_shuffle_ps(q, q, 0xaa), SimdC::_mm_add_ss(SimdC::_mm_shuffle_ps(q, q, 0x55), q));
    SimdC::LocalM128 r = SimdC::_mm_rsqrt_ss(d);
    SimdC::LocalM128 mask = SimdC::_mm_cmpeq_ss(d, SimdC::_mm_set_ss(kZero));
    SimdC::LocalM128 n =
        SimdC::_mm_mul_ss(SimdC::_mm_mul_ss(SimdC::_mm_set_ss(0.5f), r),
                          SimdC::_mm_sub_ss(SimdC::_mm_set_ss(3.0f), SimdC::_mm_mul_ss(SimdC::_mm_mul_ss(d, r), r)));
    n = SimdC::_mm_andnot_ps(mask, n);
    return SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(n, n, 0), v);
}

static __forceinline float mulf(float a, float b)
{
    return a * b;
}
static __forceinline float invf(float a)
{
    return 1.0f / a;
}
static __forceinline void normalize3InPlace(SimdC::LocalM128* v)
{
    SimdC::LocalM128 n = *v;
    float len2;
    lengthSquared(n, len2);
    if (len2 != 0.0f)
    {
        float inv = 1.0f / (float)sqrt((double)len2);
        SimdC::LocalM128 s = SimdC::_mm_load_ss(&inv);
        *v = SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(s, s, 0), n);
    }
}
static __forceinline void normInPlace(SimdC::LocalM128* v)
{
    float len2;
    lengthSquared(*v, len2);
    if (len2 != 0.0f)
    {
        float inv = 1.0f / (float)sqrt((double)len2);
        SimdC::LocalM128 s = SimdC::_mm_load_ss(&inv);
        *v = SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(s, s, 0), *v);
    }
}
static __forceinline void normP(SimdC::LocalM128* v, SimdC::LocalM128 n)
{
    float len2;
    lengthSquared(n, len2);
    if (len2 != 0.0f)
    {
        float inv = 1.0f / (float)sqrt((double)len2);
        SimdC::LocalM128 s = SimdC::_mm_load_ss(&inv);
        *v = SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(s, s, 0), n);
    }
}
static __forceinline void normR(SimdC::LocalM128& v)
{
    float len2;
    lengthSquared(v, len2);
    if (len2 != 0.0f)
    {
        float inv = 1.0f / (float)sqrt((double)len2);
        SimdC::LocalM128 s = SimdC::_mm_load_ss(&inv);
        v = SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(s, s, 0), v);
    }
}
static __forceinline float lenSqV(SimdC::LocalM128 v)
{
    float o;
    lengthSquared(v, o);
    return o;
}

static __forceinline void constructPointers(CollidableC** dst, CollidableC** src, int count)
{
    for (int i = 0; i < count; ++i)
    {
        CollidableC** p = dst + i;
        if (p)
            *p = src[i];
    }
}
static __forceinline int countMinValue(int a, int b)
{
    return a < b ? a : b;
}

// @fnv 0x00c711d0
// src: COMMUNITY 0x00c711d0
void ParentC::bhkCharacterController_processConstraintsCallback(void*, ContactListC* contacts, ResultC* results)
{
    ContextC contextGuard;
    flags &= ~4u;
    minX = minY = minZ = minW = 1.1754943508222875e-38f;
    normal = SimdC::_mm_setzero_ps();
    if (flagHi & 1)
    {
        if (reference)
            reference->FUN_00c905b0();
        reference = 0;
    }
    Vec4C zeroVector = SimdC::_mm_setzero_ps();
    accepted = 0;
    float radiusSquared = 0.0f;
    int additionalResponses = 0, auxiliary = 0;
    bool haveNormal = false;
    normal.value = initialNormal;
    bool haveSphere = false;
    Vec4C sphere0, sphere1;
    BodyC* sphereTransformBody;
    if (!(flagLo & 1) && !getFlag(5) && node && (sphereTransformBody = node->body) != 0 && shapeNode && shapeNode->body)
    {
        BodyC* bodyOwner;
        bodyOwner = shapeNode->body;
        WrappedShapeC* wrappedShape = reinterpret_cast<WrappedShapeC*>(bodyOwner);
        if (wrappedShape->kind == 9 && wrappedShape->shape.type() == 3)
        {
            ShapeC* firstSphere = wrappedShape->children->first;
            if (firstSphere && firstSphere->kind == 5)
            {
                ExtractStiltCapsuleInfo(firstSphere, &sphereTransformBody->transform, &sphere0.value);
                ShapeC* b;
                b = wrappedShape->children->second;
                if (b && b->kind == 5)
                {
                    ExtractStiltCapsuleInfo(b, &sphereTransformBody->transform, &sphere1.value);
                    float accumulated = b->radius;
                    radiusSquared = (float)(accumulated * DAT_010c4ab0);
                    radiusSquared *= radiusSquared;
                    haveSphere = true;
                }
            }
        }
    }
    int contactCount = countMinValue(results->count, contacts->count);
    bool hasMaterial2;
    hasMaterial2 = false;
    for (int contactIndex = 0; contactIndex < contactCount; ++contactIndex)
    {
        ResponseC* response = &results->data[contactIndex];
        ContactC* contact = &contacts->data[contactIndex];
        CollidableC* source = contact->collidable;
        BodyC* bodyOwner = source->owner();
        unsigned int materialByte = source->material;
        if (getFlag(16) && (flags & 0x200000) && bhkCharacterController_IsHurtfulBody(bodyOwner) && bodyOwner)
        {
            // The owner carries a scene node at offset 0x0c.
            NodeC* nodeBody;
            nodeBody = bodyOwner->sceneNode;
            if (nodeBody)
            {
                Vec3C velocity;
                BodyC* rb = nodeBody->body;
                FUN_00458620(&velocity, rb ? &rb->velocity : reinterpret_cast<Vec3C*>(&DAT_01267e30));
                float squaredMagnitude = velocity.y * velocity.y + velocity.x * velocity.x + velocity.z * velocity.z;
                if (squaredMagnitude > 0.0f)
                {
                    Vec3C other = {0, 0, 0};
                    ParentC* owner = this;
                    ProxyC* proxy;
                    proxy = owner->proxy;
                    if (proxy)
                    {
                        owner->bhkCharacterProxy_MarkRead();
                        FUN_00458620(&other, proxy->hkpCharacterProxy_getLinearVelocity());
                        owner->bhkCharacterProxy_MarkRead();
                    }
                    float velocityDot = other.dot(velocity);
                    NP3 sc(velocityDot * velocity.x, velocityDot * velocity.y, velocityDot * velocity.z);
                    float inverse = 1.0f / squaredMagnitude;
                    float projectedX, projectedY, projectedZ;
                    projectedX = sc.x * inverse;
                    projectedY = sc.y * inverse;
                    projectedZ = sc.z * inverse;
                    float projectionDot = projectedY * velocity.y + projectedX * velocity.x + projectedZ * velocity.z;
                    if (projectionDot > 0.0f)
                    {
                        velocity.x -= projectedX;
                        velocity.y -= projectedY;
                        velocity.z -= projectedZ;
                        squaredMagnitude = velocity.dot(velocity);
                    }
                    if (squaredMagnitude > 0.0f)
                    {
                        FUN_00c6d9f0* entry = new FUN_00c6d9f0;
                        {
                            FUN_00c6d9f0* added = entry;
                            entry->object.FUN_0066b0d0(nodeBody);
                            FUN_00458620(&entry->position, contact);
                            FUN_00458620(&entry->normal, &contact->normal);
                            memcpy(&entry->velocity, &velocity, sizeof(velocity));
                            reinterpret_cast<EntryListC*>(&entries)->PushItem(&added);
                        }
                    }
                }
            }
        }
        unsigned long materialKind;
        materialKind = materialByte & 0x7f;
        hasMaterial2 |= materialKind == 2;
        bool eligibleContact = !getFlag(11);
        SimdC::LocalM128 normalLane = SimdC::_mm_shuffle_ps(contact->normal, contact->normal, 0xaa);
        float normalZ = laneStored(normalLane);
        bool acceptContact = eligibleContact;
        if (bodyOwner && normalZ > DAT_010c4aa8 && bodyOwner->motionType == 4 && !DAT_01267bb4)
        {
            ParentC* owner = this;
            Vec4C transformBody;
            SubtractVectors(&transformBody);
            transformBody.value.m128_f32[2] += height;
            SimdC::LocalM128 contactPosition = contact->position;
            float contactZ = laneStored(SimdC::_mm_shuffle_ps(contactPosition, contactPosition, 0xaa));
            if (contactZ <= laneStored(SimdC::_mm_shuffle_ps(transformBody, transformBody, 0xaa)))
            {
                CollectorC collectorState;
                PointerArrayC array;
                NodeC* n = node;
                BodyC* sourceBody = n->body;
                HeapAllocator* memoryAllocator = hkMemoryRouter_getInstance()->allocator;
                long pObj;
                int px = sourceBody->collidableCount;
                pObj = px > array.count ? array.count : px;
                int capacity = array.capacity & 0x3fffffff;
                if (capacity < px)
                {
                    int next = capacity * 2;
                    if (px >= next)
                        next = px;
                    hkArrayUtil__reserve(memoryAllocator, &array, next, 4);
                }
                CollidableC** sourceData = sourceBody->collidables;
                CollidableC** copyData;
                copyData = array.data;
                for (int copyIndex = 0; copyIndex < pObj; ++copyIndex)
                    copyData[copyIndex] = sourceData[copyIndex];
                constructPointers(array.data + pObj, sourceBody->collidables + pObj, px - pObj);
                array.count = px;
                static const Vec4C upOffset(zaxis(DAT_010c4aa0));
                static const Vec4C downOffset(zaxis(DAT_010c4a9c));
                Vec4C rayFrom = SimdC::_mm_add_ps(contact->position, upOffset);
                Vec4C rayTo = SimdC::_mm_sub_ps(rayFrom, downOffset);
                DAT_01267bb0 = DAT_01015f5c;
                for (int rayIndex = 0; rayIndex < array.count; ++rayIndex)
                {
                    CollidableC* tmp = array.data[rayIndex];
                    BodyC* b = tmp->owner();
                    if (!b || b->motionType != 4)
                        continue;
                    RayInputC input;
                    input.filter = 0;
                    input.collectionFilter = 0;
                    RayOutputC rayOutput;
                    input.from.hkVector4_setTransformedInversePos(&b->worldTransform, &rayFrom.value);
                    input.to.hkVector4_setTransformedInversePos(&b->worldTransform, &rayTo.value);
                    tmp->shape->RayCast(&input, &rayOutput);
                    if (rayOutput.fraction < 1.0f)
                    {
                        this->material = b->filter & 0x7f;
                        int layer = this->material;
                        int idx;
                        idx = -1;
                        for (int k = 0; 8 > k; ++k)
                        {
                            int next = rayOutput.keys[k];
                            if (next == -1)
                                break;
                            idx = next;
                        }
                        if (idx == -1)
                        {
                            ShapeC* s = tmp->shape;
                            if (!s)
                                continue;
                            MaterialC* m = s->material;
                            if (!m)
                                continue;
                            if (m->typeI() != 0xf)
                                continue;
                        }
                        else
                        {
                            if (layer == 0x11)
                                continue;
                            MaterialC* m = bhkUtilFunctions_FindbhkShapeCollection(tmp);
                            if (!m || m->typeI() != 0xf)
                                continue;
                        }
                        {
                            SimdC::LocalM128 frac = SimdC::_mm_load_ss(&rayOutput.fraction);
                            SimdC::LocalM128 to4 = rayTo, from4 = rayFrom;
                            SimdC::LocalM128 fromZ = SimdC::_mm_shuffle_ps(from4, from4, 0xaa);
                            SimdC::LocalM128 toZ = SimdC::_mm_shuffle_ps(to4, to4, 0xaa);
                            float intersectionHeight;
                            SimdC::_mm_store_ss(
                                &intersectionHeight,
                                SimdC::_mm_add_ss(fromZ, SimdC::_mm_mul_ss(SimdC::_mm_sub_ss(toZ, fromZ), frac)));
                            if (intersectionHeight > DAT_01267bb0)
                            {
                                DAT_01267bb0 = intersectionHeight;
                                DAT_01267bb4 = b;
                            }
                        }
                    }
                }
            }
        }
        Vec4C direction;
        direction = response->normal;
        if (bodyOwner)
        {
            switch (materialKind)
            {
            case 2: {
                long n = bodyOwner->motionType;
                if (4 == n || n == 5)
                {
                    response->friction = DAT_010a5898;
                    break;
                }
            }
            case 10: {
                if (!(flagHi & 1))
                {
                    direction = zaxis(1.0f);
                    normalZ = 1.0f;
                    response->weight = 0;
                    if (bhkRigidBody_IsMotionTypeDynamic(bodyOwner->motionType))
                        response->other = zeroVector;
                }
                eligibleContact = false;
                break;
            }
            case 4:
            case 5:
            case 6:
                if (!(flagHi & 1))
                {
                    float f;
                    f = reinterpret_cast<MotionC*>(&bodyOwner->motionValue)->FUN_00c86430();
                    if (f < DAT_011b0128)
                        response->other = zeroVector;
                    direction = zaxis(1.0f);
                    normalZ = 1.0f;
                }
                eligibleContact = false;
                break;
            default:
                if (haveSphere && !getFlag(5))
                {
                    ContactC* sphereContact = contact;
                    if (lengthSquaredValue(SimdC::_mm_sub_ps(sphereContact->position, sphere0)) < radiusSquared)
                    {
                        SetFlag(0x20, true);
                    }
                    else if (lengthSquaredValue(SimdC::_mm_sub_ps(sphereContact->position, sphere1)) < radiusSquared)
                    {
                        SetFlag(0x20, true);
                    }
                }
                break;
            }
        }
        if (!bodyOwner)
        {
            switch (materialKind)
            {
            case 12:
            case 16:
            case 22:
            case 23:
            case 24:
            case 41:
                response->other = zeroVector;
                continue;
            case 14:
                if (flagHi & 1)
                    response->other = zeroVector;
                break;
            case 30: {
                CollidableC* tmp = contact->collidable;
                void* ownerObject = tmp->ownerKind() == 2 ? reinterpret_cast<char*>(tmp) + tmp->ownerOffset : 0;
                ParentC* collidable = this->bhkCharacterController_Getbhk(ownerObject);
                if (collidable->flags & 0x8000000)
                {
                    response->normal = zeroVector;
                    response->other = zeroVector;
                }
                else
                {
                    response->normal.m128_f32[2] = 0;
                    normInPlace(&response->normal);
                }
                break;
            }
            default:
                break;
            }
            continue;
        }
        if (normalZ >= 0.0f)
        {
            acceptContact = true;
            if (normalZ < threshold)
            {
                if (!bhkCharacterController_IsStep(contact))
                {
                    if ((eligibleContact || getFlag(11)) && normalZ < (double)(float)0.2f)
                        acceptContact = false;
                    if (additionalResponses < 4 && eligibleContact)
                    {
                        ResponseC* accumulated = &results->data[results->count];
                        accumulated->UpdateState_00c6d670(response);
                        SimdC::_mm_store_ps(accumulated->other.m128_f32, zeroVector);
                        accumulated->normal.m128_f32[2] = 0;
                        accumulated->normal = normalized(accumulated->normal);
                        additionalResponses += 1;
                        results->count += 1;
                        if (acceptContact)
                            auxiliary++;
                    }
                }
                else
                {
                    if (!(flags & 0x1800))
                        response->weight = 0;
                    direction.value.m128_f32[2] = 1.0f;
                    {
                        Vec4C& d = direction;
                        d = normalized(d);
                    }
                    flags |= 0x404;
                    response->normal = direction;
                }
            }
            else
            {
                if (!(flagHi & 1) && (flagLo & 1))
                    ListenerC::bhkCharacterListener_AddSupportHeight2(&transform, contact);
                flags |= 0x400;
                if (!getFlag(3))
                    response->friction = DAT_010c4a98;
            }
            if (!hkpCharacterContext_getState(&this->nearProxy))
                response->weight *= scale;
            if (acceptContact)
            {
                {
                    unsigned int& f = flags;
                    f |= 0x200;
                }
                accepted += 1;
                this->bhkCharacterController_SetSupportMaterial(&contacts->data[contactIndex]);
                if (haveNormal)
                    direction = SimdC::_mm_add_ps(direction, normal);
                else
                    haveNormal = true;
                normal = direction;
                if (flagHi & 1)
                {
                    bodyOwner->FUN_00c90510();
                    if (reference)
                        reference->FUN_00c905b0();
                    reference = bodyOwner;
                }
            }
        }
    }
    if (hasMaterial2)
        flags |= 0x20000000;
    else
        flags &= ~0x20000000;
    allAuxiliary = accepted == auxiliary;
    {
        Vec4C& nr = normal;
        normP(&nr.value, nr.value);
    }
}

namespace CastSimd {
typedef ::__m128 LocalM128;
extern "C"
{
using ::_mm_load_ps1;
using ::_mm_load_ss;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_shuffle_ps;
}
}

template <class T> struct RefPtrStub
{
    T* ptr;
    operator T*() const
    {
        return ptr;
    }
    T* operator->() const
    {
        return ptr;
    }
};

struct SimdScalar
{
    CastSimd::LocalM128 quad;
    SimdScalar(float f)
    {
        quad = CastSimd::_mm_load_ps1(&f);
    }
};

inline hkVector4::hkVector4() {}
inline void hkVector4::setAddMul(const hkVector4& a, const hkVector4& b, const SimdScalar& s)
{
    const CastSimd::LocalM128& aq = reinterpret_cast<const CastSimd::LocalM128&>(a.m_vComponents);
    const CastSimd::LocalM128& bq = reinterpret_cast<const CastSimd::LocalM128&>(b.m_vComponents);
    CastSimd::LocalM128& quad = reinterpret_cast<CastSimd::LocalM128&>(m_vComponents);
    CastSimd::LocalM128 product = CastSimd::_mm_mul_ps(bq, s.quad);
    quad = CastSimd::_mm_add_ps(aq, product);
}
inline void hkVector4::addMul(const float& f, const hkVector4& b)
{
    const CastSimd::LocalM128& bq = reinterpret_cast<const CastSimd::LocalM128&>(b.m_vComponents);
    CastSimd::LocalM128& quad = reinterpret_cast<CastSimd::LocalM128&>(m_vComponents);
    CastSimd::LocalM128 scalar = CastSimd::_mm_load_ss(&f);
    CastSimd::LocalM128 splat = CastSimd::_mm_shuffle_ps(scalar, scalar, 0);
    CastSimd::LocalM128 product = CastSimd::_mm_mul_ps(splat, bq);
    quad = CastSimd::_mm_add_ps(product, quad);
}

struct CdPoint
{
    CastSimd::LocalM128 m0;
    CastSimd::LocalM128 m1;
    CastSimd::LocalM128 m2;
    CastSimd::LocalM128 m3;
    CastSimd::LocalM128 m4;
    CastSimd::LocalM128 m5;
    CastSimd::LocalM128 m6;
};

extern void* DAT_0104da28;
extern float DAT_0104da48;
extern float DAT_0104da4c;



void DestroyCdPointCollector();
struct __declspec(align(16)) CdPointCollectorStorage
{
    unsigned char bytes[sizeof(hkpAllCdPointCollector)];
    hkpAllCdPointCollector& Get()
    {
        return *reinterpret_cast<hkpAllCdPointCollector*>(bytes);
    }
    CdPointCollectorStorage()
    {
        hkpAllCdPointCollector& collector = Get();
        collector.m_fEarlyOutDistance = DAT_0104da48;
        *reinterpret_cast<void**>(&collector) = &DAT_0104da28;
        collector.contacts.data = collector.contacts.local;
        collector.contacts.capacity = 0x80000008;
        collector.contacts.count = 0;
    }
    ~CdPointCollectorStorage()
    {
        typedef void (__thiscall *Destructor)(hkpAllCdPointCollector*);
        reinterpret_cast<Destructor>(&DestroyCdPointCollector)(&Get());
    }
};
// The shared collector still returns an incomplete hkBoolStub; use the real Havok bool locally.
inline hkBool CollectorDidHit(const hkpAllCdPointCollector& collector)
{
    return collector.contacts.count > 0;
}

struct LinearCastInput
{
    hkVector4 m_vTo;
    float m_fMaxExtraPenetration;
    float m_fMaxExtraPenetrationAgainstFixed;
};

struct ShapePhantom
{
    void InvokeInterfaceCall(const hkVector4& pos, const LinearCastInput& input, hkpAllCdPointCollector& coll,
                      void* startCollector);
};

struct ContactListener
{
    virtual void unk0();
    virtual void unk4();
    virtual void processPoint(int a, CdPoint* p);
};

struct CharProxy
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    ContactListener m_kListener;  // 0x410
    unsigned int m_flags;         // 0x414
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    hkVector4 m_fVelocity;  // 0x4f0
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    RefPtrStub<ShapePhantom> m_pPhantom;  // 0x594
    void SubtractVectors(hkVector4& out);
    void bhkCharacterController_SetPosition(const hkVector4& in);
    void bhkCharacterController_MoveAsProjectile(float dt);
};

// @fnv 0x00c72250
// src: COMMUNITY 0x00c72250
void CharProxy::bhkCharacterController_MoveAsProjectile(float dt)
{
    hkVector4 pos;
    if ((unsigned char)(m_flags >> 19) & 1 && m_pPhantom != 0)
    {
        CdPointCollectorStorage collectorStorage;
        hkpAllCdPointCollector& collector = collectorStorage.Get();
        LinearCastInput input;
        input.m_fMaxExtraPenetration = DAT_0104da4c;
        input.m_fMaxExtraPenetrationAgainstFixed = DAT_0104da4c;
        SubtractVectors(pos);
        input.m_vTo.setAddMul(pos, m_fVelocity, SimdScalar(dt));
        m_pPhantom->InvokeInterfaceCall(pos, input, collector, 0);
        if (CollectorDidHit(collector))
        {
            collector.sortHits();
            for (int i = 0; i < collector.contacts.count; i++)
                m_kListener.processPoint(0, reinterpret_cast<CdPoint*>(&collector.contacts.data[i]));
        }
        bhkCharacterController_SetPosition(input.m_vTo);
    }
    else
    {
        SubtractVectors(pos);
        pos.addMul(dt, m_fVelocity);
        bhkCharacterController_SetPosition(pos);
    }
}

using ::_mm_add_ps;
using ::_mm_load_ss;
using ::_mm_store_ps;

union __declspec(align(16)) VecBoxQ
{
    LocalM128 q;
    __int8 i8[16];
};
union __declspec(align(16)) Lane128Q
{
    float f32[4];
    unsigned __int64 u64[2];
    __int8 i8[16];
};
struct QsTransform
{
    Lane128Q translation, rotation, scale;
};
inline NiTransform::NiTransform() {}

struct TransformWorkspace
{
    QsTransform transform;
};

int __cdecl FindIndexByKey(void*, const char*, int);
void __cdecl NI2HK_00c74dd0(void*, NiTransform*);

struct Obj1C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    LocalM128 m_10;
    LocalM128 m_20;
};
struct MidObj
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short* m_0c;
};
struct SObj
{
    int unk00;
    int unk04;
    int unk08;
    MidObj* m_0c;
    int unk10;
    int unk14;
    int unk18;
    Obj1C* m_1c;
};
struct Src58
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
    NiTransform m_68;
};
struct Rec48
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    LocalM128 m_10;
    LocalM128 m_20;
};
struct Param1
{
    Rec48* __thiscall hkaPose_calculateBoneModelSpace(int idx);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Rec48* m_10;
    int unk14;
    int unk18;
    unsigned int* m_1c;
};
struct FrameRecord
{
    int state;
    short indexA;
    short indexB;
    int unk08;
    int unk0c;
    LocalM128 directionA;
    LocalM128 directionB;
    LocalM128 unk30;
    LocalM128 unk40;
};
struct Cls79340
{
    bool __thiscall bhkRagdollController_InitBoneParams(Param1* a1, const char* a2, int a3);
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
    Src58* m_58;
    int unk5c;
    NiMatrix3 m_60;
    int unk84;
    int m_88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    short unkb0;
    char m_b2;
    char unkb3;
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    FrameRecord records[2];
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
    SObj* m_2a4;
};

extern unsigned int DAT_01012068;
extern const float DAT_01017718;
extern const float DAT_01016248;

// @fnv 0x00c79340
// src: COMMUNITY 0x00c79340
bool __thiscall Cls79340::bhkRagdollController_InitBoneParams(Param1* a1, const char* a2, int a3)
{
    bool ok = true;
    Param1* pA1 = a1;
    MidObj* mo = m_2a4->m_0c;
    int r = FindIndexByKey(mo, a2, 0);

    records[a3].indexA = r;
    if ((short)r == -1)
    {
        ok = false;
    }
    else
    {
        unsigned short* tab = m_2a4->m_0c->m_0c;
        short r2 = (short)tab[(short)r];
        records[a3].indexB = r2;
        if (r2 == -1)
            ok = false;
    }
    m_b2 = 0;
    if (ok)
    {

        NiTransform t;
        memcpy(&t, &m_58->m_68, sizeof(t));
        TransformWorkspace xformBuf;
        typedef NiMatrix3 (NiMatrix3::*MatrixProduct)(const NiMatrix3&) const;
        typedef NiMatrix3* (__thiscall NiMatrix3::*MatrixProductInto)(NiMatrix3*, const NiMatrix3*);
        MatrixProduct product = &NiMatrix3::operator*;
        // Reuse the transform workspace for the matrix result through the original x86 return-buffer ABI.
        NiMatrix3* pm = (m_60.*reinterpret_cast<MatrixProductInto>(product))(
            reinterpret_cast<NiMatrix3*>(&xformBuf.transform), &t.m_Rotate);
        t.m_Rotate = *pm;
        t.m_fScale = 1.0f;
        NI2HK_00c74dd0(&xformBuf.transform, &t);

        VecBoxQ Vb;
        Vb.q =
            _mm_setr_ps(*reinterpret_cast<const float*>(&DAT_01011d78), *reinterpret_cast<const float*>(&DAT_01012068),
                        *reinterpret_cast<const float*>(&DAT_01011d78), *reinterpret_cast<const float*>(&DAT_01011d78));
        int w1 = records[a3].indexA;
        Rec48* ptrA;
        if (!(pA1->m_1c[w1] & 2))
            ptrA = pA1->m_10 + w1;
        else
            ptrA = pA1->hkaPose_calculateBoneModelSpace(w1);
        int w2 = records[a3].indexB;
        Rec48* ptrB;
        if (!(pA1->m_1c[w2] & 2))
            ptrB = pA1->m_10 + w2;
        else
            ptrB = pA1->hkaPose_calculateBoneModelSpace(w2);

        LocalM128 vd2;
        LocalM128 vc9;
        {
            LocalM128 q = ptrB->m_10;
            LocalM128 qw = _mm_shuffle_ps(q, q, 0xff);
            LocalM128 prod = _mm_mul_ps(q, Vb.q);
            LocalM128 sy = _mm_shuffle_ps(prod, prod, 0x55);
            sy = _mm_add_ss(sy, prod);
            LocalM128 sz = _mm_shuffle_ps(prod, prod, 0xaa);
            LocalM128 dot = _mm_add_ss(sz, sy);
            LocalM128 qd2 = _mm_shuffle_ps(q, q, 0xd2);
            LocalM128 qc9 = _mm_shuffle_ps(q, q, 0xc9);
            vd2 = _mm_shuffle_ps(Vb.q, Vb.q, 0xd2);
            LocalM128 t1 = _mm_mul_ps(qc9, vd2);
            vc9 = _mm_shuffle_ps(Vb.q, Vb.q, 0xc9);
            LocalM128 t2 = _mm_mul_ps(qd2, vc9);
            t2 = _mm_sub_ps(t2, t1);
            t2 = _mm_mul_ps(t2, qw);
            LocalM128 ww = _mm_mul_ps(qw, qw);
            ww = _mm_add_ps(ww, *reinterpret_cast<const LocalM128*>(&DAT_010c71e0));
            ww = _mm_mul_ps(ww, Vb.q);
            LocalM128 dq = _mm_shuffle_ps(dot, dot, 0);
            dq = _mm_mul_ps(dq, q);
            LocalM128 res = _mm_add_ps(ww, dq);
            res = _mm_add_ps(t2, res);
            res = _mm_add_ps(res, res);
            records[a3].directionB = res;
        }
        {
            LocalM128 q = ptrA->m_10;
            LocalM128 prod = _mm_mul_ps(q, Vb.q);
            LocalM128 sy = _mm_shuffle_ps(prod, prod, 0x55);
            sy = _mm_add_ss(sy, prod);
            LocalM128 sz = _mm_shuffle_ps(prod, prod, 0xaa);
            LocalM128 qd2 = _mm_shuffle_ps(q, q, 0xd2);
            LocalM128 qc9 = _mm_shuffle_ps(q, q, 0xc9);
            LocalM128 qw = _mm_shuffle_ps(q, q, 0xff);
            LocalM128 t1 = _mm_mul_ps(qc9, vd2);
            LocalM128 t2 = _mm_mul_ps(qd2, vc9);
            t2 = _mm_sub_ps(t2, t1);
            t2 = _mm_mul_ps(t2, qw);
            LocalM128 ww = _mm_mul_ps(qw, qw);
            ww = _mm_add_ps(ww, *reinterpret_cast<const LocalM128*>(&DAT_010c71e0));
            ww = _mm_mul_ps(ww, Vb.q);
            LocalM128 dot = _mm_add_ss(sz, sy);
            LocalM128 dq = _mm_shuffle_ps(dot, dot, 0);
            dq = _mm_mul_ps(dq, q);
            LocalM128 res = _mm_add_ps(ww, dq);
            res = _mm_add_ps(t2, res);
            res = _mm_add_ps(res, res);
            records[a3].directionA = res;
        }
        {
            const LocalM128* pv = &records[a3].directionA;
            LocalM128 v = *pv;
            LocalM128 sq = _mm_mul_ps(v, v);
            LocalM128 ny = _mm_shuffle_ps(sq, sq, 0x55);
            ny = _mm_add_ss(ny, sq);
            LocalM128 nz = _mm_shuffle_ps(sq, sq, 0xaa);
            LocalM128 len = _mm_add_ss(nz, ny);
            LocalM128 rr = _mm_rsqrt_ss(len);
            LocalM128 lr = _mm_mul_ss(len, rr);
            lr = _mm_mul_ss(lr, rr);
            LocalM128 f = _mm_sub_ss(_mm_set_ss(DAT_01017718), lr);
            LocalM128 inv = _mm_mul_ss(_mm_set_ss(DAT_01016248), rr);
            inv = _mm_mul_ss(inv, f);
            LocalM128 isz = _mm_cmpeq_ss(len, _mm_load_ss(reinterpret_cast<const float*>(&DAT_01011d78)));
            LocalM128 sel = _mm_andnot_ps(isz, inv);
            LocalM128 splat = _mm_shuffle_ps(sel, sel, 0);
            records[a3].directionA = _mm_mul_ps(splat, v);
        }

        Obj1C* o = m_2a4->m_1c;
        if (o != 0 && a3 == 1)
        {
            _mm_store_ps(reinterpret_cast<float*>(&records[1].directionB), o->m_10);
            records[1].directionA = m_2a4->m_1c->m_20;
        }
        records[a3].state = m_88;
    }
    return ok;
}

union __declspec(align(16)) PitchRollQuad
{
    ::LocalM128 value;
    signed char m128_i8[16];
    PitchRollQuad& operator=(const PitchRollQuad& v)
    {
        value = v.value;
        return *this;
    }
    PitchRollQuad& operator=(const ::LocalM128& v)
    {
        value = v;
        return *this;
    }
};

namespace PitchRollIntrinsics {
extern "C" ::LocalM128(_mm_setr_ps)(float, float, float, float);
}
extern "C" double __cdecl sin(_In_ double _X);
extern "C" inline float sinf(_In_ float _X)
{
    return ((float)sin((double)_X));
}
inline float __cdecl sin(_In_ float _X)
{
    return (sinf(_X));
}
struct __declspec(align(16)) FUN_005611c0_t
{
    PitchRollQuad value;
    void normalize_005611c0();
};
struct __declspec(align(16)) Rotation
{
    PitchRollQuad r0, r1, r2;
};
struct __declspec(align(16)) FUN_008cd6a0_Class
{
    PitchRollQuad r0, r1, r2, r3;
    void hkRotation_set(void*);
    void hkMatrix3f_mul(Rotation*);
};
struct FUN_00c9e910_Class
{
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
    FUN_008cd6a0_Class transform;
    void hkpShapePhantom_setTransform(int);
};
struct TargetObject
{
    unsigned int unk00, unk04;
    FUN_00c9e910_Class* object;
    void Object_DoNothing();
};

struct RotationOwner
{
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
    unsigned int flags;
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
    float angle1;
    float angle2;
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
    TargetObject* target;
    void bhkCharacterController_ApplyPitchAndRoll(FUN_005611c0_t* arg);
};
// @fnv 0x00c6e420
// src: XBOX_PDB 0x00c6e420
void RotationOwner::bhkCharacterController_ApplyPitchAndRoll(FUN_005611c0_t* arg)
{
    FUN_005611c0_t vector;
    vector.value = arg->value;
    vector.normalize_005611c0();
    TargetObject* t = target;
    FUN_00c9e910_Class* object = t ? t->object : 0;
    FUN_008cd6a0_Class transform;
    transform.r0 = object->transform.r0;
    transform.r1 = object->transform.r1;
    transform.r2 = object->transform.r2;
    transform.r3 = object->transform.r3;
    transform.hkRotation_set(&vector);
    Rotation rotation;
    if (angle1 != 0.0f && (static_cast<unsigned char>(flags >> 25) & 1))
    {
        float c = cos(angle1);
        float s = sin(angle1);
        rotation.r0 = (PitchRollIntrinsics::_mm_setr_ps)(1.0f, 0.0f, 0.0f, 0.0f);
        rotation.r1 = (PitchRollIntrinsics::_mm_setr_ps)(0.0f, c, -s, 0.0f);
        rotation.r2 = (PitchRollIntrinsics::_mm_setr_ps)(0.0f, s, c, 0.0f);
        transform.hkMatrix3f_mul(&rotation);
    }
    if (angle2 != 0.0f && (static_cast<unsigned char>(flags >> 26) & 1))
    {
        float c = cos(angle2);
        float s = sin(angle2);
        rotation.r0 = (PitchRollIntrinsics::_mm_setr_ps)(c, 0.0f, s, 0.0f);
        rotation.r1 = (PitchRollIntrinsics::_mm_setr_ps)(0.0f, 1.0f, 0.0f, 0.0f);
        rotation.r2 = (PitchRollIntrinsics::_mm_setr_ps)(-s, 0.0f, c, 0.0f);
        transform.hkMatrix3f_mul(&rotation);
    }
    if (t)
    {
        FUN_00c9e910_Class* object = t->object;
        if (object)
        {
            t->Object_DoNothing();
            object->hkpShapePhantom_setTransform((int)&transform);
            t->Object_DoNothing();
        }
    }
}

namespace FootIKIntrinsics {
extern "C"
{
using ::_mm_setr_ps;
using ::_mm_load_ss;
}
}
extern float DAT_01267d48, DAT_01267d54, DAT_01267d60, DAT_01267d6c, DAT_01267d78;
extern float DAT_01267dc0, DAT_01267dd8, DAT_01267da8, DAT_01267db4, DAT_01267c1c;
extern int DAT_01267dcc;
extern const double DAT_010217d8;
extern const float DAT_01011d78, DAT_01016248, DAT_0102caf8, DAT_0101712c;
extern const P064Quad DAT_010ec7f0, DAT_010c7160;

namespace FootIKDetail {

struct __declspec(align(16)) Scalar
{
    P064Quad value;
    __forceinline Scalar(const Scalar& x)
    {
        value = x.value;
    }
    __forceinline Scalar& operator=(const Scalar& x)
    {
        value = x.value;
        return *this;
    }
    __forceinline Scalar(float x)
    {
        value = FootIKIntrinsics::_mm_load_ss(&x);
    }
    __forceinline Scalar(P064Quad x)
    {
        value = x;
    }
    __forceinline operator float() const
    {
        float x;
        P064Intrinsics::_mm_store_ss(&x, value);
        return x;
    }
    __forceinline P064Quad splat() const
    {
        return P064Intrinsics::_mm_shuffle_ps(value, value, 0);
    }
    __forceinline Scalar operator-() const
    {
        return Scalar(P064Intrinsics::_mm_sub_ss(DAT_010c7160, value));
    }
};
struct __declspec(align(16)) Vec
{
    P064Quad v;
    __forceinline Vec()
    {}
    __forceinline Vec(const Vec& a)
    {
        v = a.v;
    }
    __forceinline Vec& operator=(const Vec& a)
    {
        v = a.v;
        return *this;
    }
    __forceinline void interpolateVector(const Vec& a, const Vec& b, const Scalar& t)
    {
        P064Quad w = t.splat();
        P064Quad remaining = P064Intrinsics::_mm_sub_ps(DAT_010ec7f0, w);
        v = P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(remaining, a.v), P064Intrinsics::_mm_mul_ps(w, b.v));
    }
};
struct __declspec(align(16)) Quaternion
{
    P064Quad v;
    __forceinline Quaternion()
    {}
    __forceinline Quaternion(const Quaternion& a)
    {
        v = a.v;
    }
    __forceinline Quaternion& operator=(const Quaternion& a)
    {
        v = a.v;
        return *this;
    }
    __declspec(noalias) void setMul(const Quaternion&, const Quaternion&);
    void normalize_005611c0();
    void hkQuaternion_decomposeRestAxis(const Vec&, Vec&, float&);
    void hkQuaternion_setAxisAngle(const Vec&, float);
};
// local form of hkQsTransform: 0x00c76350 needs the 0x30-byte three-packet pose record and its inline inverse/product forms.
struct __declspec(align(16)) FootIKQsTransformLocal_00c76350
{
    Vec translation;
    Quaternion rotation;
    Vec scale;
    __forceinline FootIKQsTransformLocal_00c76350()
    {}
    __forceinline FootIKQsTransformLocal_00c76350(const FootIKQsTransformLocal_00c76350& a)
    {
        translation.v = a.translation.v;
        rotation.v = a.rotation.v;
        scale.v = a.scale.v;
    }
    __forceinline void interpolate(const FootIKQsTransformLocal_00c76350&, const FootIKQsTransformLocal_00c76350&, const Scalar&);
    __forceinline void setInverseAfter(const FootIKQsTransformLocal_00c76350&);
    __forceinline void setInverseFinal(const FootIKQsTransformLocal_00c76350&);
    __forceinline void SetConjugate(const FootIKQsTransformLocal_00c76350&);
    __forceinline void setMulFinal(const FootIKQsTransformLocal_00c76350&, const FootIKQsTransformLocal_00c76350&);
    __forceinline void SetProduct(const FootIKQsTransformLocal_00c76350&, const FootIKQsTransformLocal_00c76350&);
    __forceinline FootIKQsTransformLocal_00c76350& operator=(const FootIKQsTransformLocal_00c76350& a)
    {
        translation.v = a.translation.v;
        rotation.v = a.rotation.v;
        scale.v = a.scale.v;
        return *this;
    }
};
template <class T> struct Array
{
    T* data;
    int size, capacity;
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
};
struct Skeleton
{
    int unk00, unk04, unk08;
    short* parents;
    int unk10, unk14, unk18;
    int count;
};
struct Pose
{
    Skeleton* skeleton;
    FootIKQsTransformLocal_00c76350* local;
    int unk08, unk0c;
    FootIKQsTransformLocal_00c76350* model;
    int unk14, unk18;
    // Cache bits: local invalid, model invalid, and temporary descendant mark.
    Array<unsigned int> flags;
    bool localDirty, modelDirty;
    FootIKQsTransformLocal_00c76350& hkaPose_calculateBoneModelSpace(int);
    __forceinline FootIKQsTransformLocal_00c76350& getModel(int i)
    {
        if (!(flags[i] & 2))
            return model[i];
        return hkaPose_calculateBoneModelSpace(i);
    }
    __forceinline FootIKQsTransformLocal_00c76350& getLocalAfter(int i);
    __forceinline FootIKQsTransformLocal_00c76350& getLocalFinal(int i);
    __forceinline FootIKQsTransformLocal_00c76350& getLocal(int i);
    __forceinline void propagateFinal(int i);
    __forceinline void propagate(int i);
};
struct Input
{
    FootIKQsTransformLocal_00c76350 modelFromWorld;
    FootIKQsTransformLocal_00c76350 worldFromModel;
    bool enabled;
    void* raycast;
    float gain, upGain, downGain, verticalError, ascendingGain, ungroundedGain;
    int unk80;
    bool unk84;
    void InitializeDefaults();
};
struct Output
{
    float height;
    bool hit;
};
struct Solver
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    short bone;
    short unk1a;
    int unk1c, unk20, unk24, unk28, unk2c;
    Vec target;
    Vec unk40, unk50, unk60, unk70;
    float offset;
    int unk84, unk88, unk8c;
    void hkaFootPlacementIkSolver_doFootPlacement(const Input&, Output&, Pose*);
};
struct Leg
{
    Solver* solver;
    float height;
    int unk08, unk0c;
    Vec unk10, unk20, unk30, unk40, unk50, unk60, unk70, unk80;
    FootIKQsTransformLocal_00c76350 previous;
    short body;
    short unkc2;
    int unkc4, unkc8, unkcc;
};
struct Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int type();
    Shape* hkpMalleableConstraintData_getWrappedConstraintData();
    int unk04, unk08, unk0c;
    Vec vertices[10];
    unsigned char unkc0, unkc1, unkc2, vertex;
};
struct Body
{
    int unk00, unk04, unk08;
    Shape* shape;
};
struct Bodies
{
    int unk00, unk04, unk08, unk0c, unk10;
    Body** data;
    int unk18, unk1c;
    int* lookup;
};
struct Controller
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    Bodies* bodies;
    int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84;
    Pose* pose;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    int unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    bool unk220, disabled, unk222, fullGain;
    int unk224;
    int frames;
    Leg* legs;
    int legCount;
    int unk234;
    short unk238, currentLeg;
    float height;
    bool blend, keepTarget, reset, fullBlend;
    float offset;
    void bhkRagdollController_DoFootIK(const FootIKQsTransformLocal_00c76350&);
};
float __cdecl GetElapsedSeconds();
__forceinline float realValue(P064Quad v)
{
    float value;
    P064Intrinsics::_mm_store_ss(&value, v);
    return value;
}

template <class C, class V> __forceinline V& component(C& object, V C::*entry)
{
    return object.*entry;
}
template <class C, class V> __forceinline const V& component(const C& object, V C::*entry)
{
    return object.*entry;
}
__forceinline void rotateInverseOut(P064Quad& out, const P064Quad& v, const P064Quad& q)
{
    P064Quad w = P064Intrinsics::_mm_shuffle_ps(q, q, 0xff);
    P064Quad prod = P064Intrinsics::_mm_mul_ps(v, q);
    P064Quad sum2 =
        P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(prod, prod, 0xaa),
                                   P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(prod, prod, 0x55), prod));
    P064Quad cross = P064Intrinsics::_mm_sub_ps(P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 0xc9),
                                                                           P064Intrinsics::_mm_shuffle_ps(q, q, 0xd2)),
                                                P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 0xd2),
                                                                           P064Intrinsics::_mm_shuffle_ps(q, q, 0xc9)));
    cross = P064Intrinsics::_mm_mul_ps(cross, w);
    P064Quad b =
        P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(w, w), DAT_010c71e0), v);
    P064Quad c = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(sum2, sum2, 0), q);
    P064Quad r = P064Intrinsics::_mm_add_ps(cross, P064Intrinsics::_mm_add_ps(b, c));
    out = P064Intrinsics::_mm_add_ps(r, r);
}
__forceinline void rotateForwardOut(P064Quad& out, const P064Quad& v, const P064Quad& q)
{
    P064Quad w = P064Intrinsics::_mm_shuffle_ps(q, q, 0xff);
    P064Quad prod = P064Intrinsics::_mm_mul_ps(q, v);
    P064Quad dot =
        P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(prod, prod, 0xaa),
                                   P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(prod, prod, 0x55), prod));
    P064Quad cross = P064Intrinsics::_mm_sub_ps(P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 0xd2),
                                                                           P064Intrinsics::_mm_shuffle_ps(q, q, 0xc9)),
                                                P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 0xc9),
                                                                           P064Intrinsics::_mm_shuffle_ps(q, q, 0xd2)));
    P064Quad a = P064Intrinsics::_mm_mul_ps(cross, w);
    P064Quad b =
        P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(w, w), DAT_010c71e0), v);
    P064Quad c = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(dot, dot, 0), q);
    P064Quad r = P064Intrinsics::_mm_add_ps(a, P064Intrinsics::_mm_add_ps(b, c));
    out = P064Intrinsics::_mm_add_ps(r, r);
}
__forceinline void FootIKQsTransformLocal_00c76350::SetConjugate(const FootIKQsTransformLocal_00c76350& parent)
{
    rotateInverseOut(translation.v, parent.translation.v, parent.rotation.v);
    translation.v = P064Intrinsics::_mm_xor_ps(translation.v, DAT_010c44d0);
    rotation.v = P064Intrinsics::_mm_xor_ps(parent.rotation.v, DAT_010c4c00);
    P064Quad s = P064Intrinsics::_mm_shuffle_ps(parent.scale.v,
                                                P064Intrinsics::_mm_unpackhi_ps(parent.scale.v, DAT_010c7170), 0xc4);
    P064Quad r = P064Intrinsics::_mm_rcp_ps(s);
    P064Quad correction = P064Intrinsics::_mm_mul_ps(r, s);
    correction = P064Intrinsics::_mm_mul_ps(correction, r);
    P064Quad twice = P064Intrinsics::_mm_add_ps(r, r);
    r = P064Intrinsics::_mm_sub_ps(twice, correction);
    scale.v = P064Intrinsics::_mm_and_ps(r, DAT_010c4c10);
}
__forceinline void FootIKQsTransformLocal_00c76350::SetProduct(const FootIKQsTransformLocal_00c76350& a, const FootIKQsTransformLocal_00c76350& b)
{
    P064Quad rotated;
    rotateForwardOut(rotated, b.translation.v, a.rotation.v);
    translation.v = P064Intrinsics::_mm_add_ps(rotated, a.translation.v);
    rotation.setMul(a.rotation, b.rotation);
    scale.v = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_load_ps(b.scale.v.m128_f32), a.scale.v);
}
__forceinline void FootIKQsTransformLocal_00c76350::interpolate(const FootIKQsTransformLocal_00c76350& a, const FootIKQsTransformLocal_00c76350& b, const Scalar& t)
{
    scale.interpolateVector(a.scale, b.scale, t);
    translation.interpolateVector(a.translation, b.translation, t);
    float remaining = 1.0f - float(t);
    P064Quad prod = P064Intrinsics::_mm_mul_ps(a.rotation.v, b.rotation.v);
    P064Quad pair = P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_shuffle_ps(prod, prod, 0x4e), prod);
    Scalar dot(P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_shuffle_ps(pair, pair, 0xb1), pair));
    const Scalar& signedT = float(dot) < 0.0f ? -t : t;
    float signedWeight = float(signedT);
    Quaternion mixed;
    P064Quad right = P064Intrinsics::_mm_mul_ps(Scalar(signedWeight).splat(), b.rotation.v);
    mixed.v = P064Intrinsics::_mm_add_ps(right, P064Intrinsics::_mm_mul_ps(Scalar(remaining).splat(), a.rotation.v));
    mixed.normalize_005611c0();
    rotation = mixed;
}
__forceinline void relative(Pose* pose, int i, const FootIKQsTransformLocal_00c76350& parent, const FootIKQsTransformLocal_00c76350& child)
{
    FootIKQsTransformLocal_00c76350 inverseTransform;
    FootIKQsTransformLocal_00c76350& destination = pose->local[i];
    inverseTransform.SetConjugate(parent);
    destination.SetProduct(inverseTransform, child);
}
__forceinline FootIKQsTransformLocal_00c76350& Pose::getLocal(int i)
{
    if (!(flags[i] & 1))
        return local[i];
    {
        const FootIKQsTransformLocal_00c76350& child = model[i];
        short p = skeleton->parents[i];
        if (p != -1)
        {
            const FootIKQsTransformLocal_00c76350& parent = getModel(p);
            relative(this, i, parent, child);
        }
        else
            local[i] = child;
        flags[i] &= ~1;
    }
    return local[i];
}
__forceinline void Pose::propagate(int i)
{
    // Preserve descendant locals before invalidating their model transforms.
    int n = skeleton->count;
    flags[i] |= 4;
    for (int j = i + 1; j < n; ++j)
    {
        short p = skeleton->parents[j];
        if (p != -1 && (flags[p] & 4))
        {
            getLocal(j);
            flags[j] |= 4;
            localDirty = false;
        }
    }
    for (int j = i + 1; j < n; ++j)
    {
        unsigned int& f = flags[j];
        if (f & 4)
            f = (f & ~4) | 2;
    }
}
__forceinline float lower(float a, float b)
{
    return a < b ? a : b;
}
__forceinline float upper(float a, float b)
{
    return a > b ? a : b;
}

struct RealRef
{
    const float* data;
    __forceinline RealRef(const float& x) : data(&x)
    {}
    __forceinline operator float() const
    {
        return *data;
    }
};

__forceinline void adjustRoot(Vec& position, const float& height, float& adjustment)
{
    RealRef oldHeight(position.v.m128_f32[2]);
    float target = oldHeight;
    target += height;
    RealRef gain(DAT_01267dc0);
    float smooth = height * gain + oldHeight;
    float delta = smooth - target;
    float maxDelta = DAT_01267dd8;
    if (delta > maxDelta)
        smooth = target + maxDelta;
    if (delta < -maxDelta)
        smooth = target - maxDelta;
    adjustment = smooth - oldHeight;
    component(position, &Vec::v).m128_f32[2] = smooth;
}

__forceinline void FootIKQsTransformLocal_00c76350::setInverseAfter(const FootIKQsTransformLocal_00c76350& parent)
{
    rotateInverseOut(translation.v, parent.translation.v, parent.rotation.v);
    translation.v = P064Intrinsics::_mm_xor_ps(translation.v, DAT_010c44d0);
    rotation.v = P064Intrinsics::_mm_xor_ps(parent.rotation.v, P064Intrinsics::_mm_load_ps(DAT_010c4c00.m128_f32));
    P064Quad s = P064Intrinsics::_mm_shuffle_ps(parent.scale.v,
                                                P064Intrinsics::_mm_unpackhi_ps(parent.scale.v, DAT_010c7170), 0xc4);
    P064Quad r = P064Intrinsics::_mm_rcp_ps(s);
    P064Quad correction = P064Intrinsics::_mm_mul_ps(r, s);
    correction = P064Intrinsics::_mm_mul_ps(correction, r);
    P064Quad twice = P064Intrinsics::_mm_add_ps(r, r);
    r = P064Intrinsics::_mm_sub_ps(twice, correction);
    scale.v = P064Intrinsics::_mm_and_ps(r, DAT_010c4c10);
}

__forceinline void relativeAfter(Pose* pose, int i, const FootIKQsTransformLocal_00c76350& parent, const FootIKQsTransformLocal_00c76350& child)
{
    FootIKQsTransformLocal_00c76350 inverseTransform;
    FootIKQsTransformLocal_00c76350& destination = pose->local[i];
    inverseTransform.setInverseAfter(parent);
    destination.SetProduct(inverseTransform, child);
}

__forceinline FootIKQsTransformLocal_00c76350& Pose::getLocalAfter(int i)
{
    if (!(flags[i] & 1))
        return local[i];
    {
        const FootIKQsTransformLocal_00c76350& child = model[i];
        short p = skeleton->parents[i];
        if (p != -1)
        {
            const FootIKQsTransformLocal_00c76350& parent = getModel(p);
            relativeAfter(this, i, parent, child);
        }
        else
            local[i] = child;
        flags[i] &= ~1;
    }
    return local[i];
}

__forceinline void rotateInverseOutFinal(P064Quad& out, const P064Quad& v, const P064Quad& q)
{
    P064Quad w = P064Intrinsics::_mm_shuffle_ps(q, q, 0xff);
    P064Quad prod = P064Intrinsics::_mm_mul_ps(v, q);
    P064Quad sum2 =
        P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(prod, prod, 0xaa),
                                   P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(prod, prod, 0x55), prod));
    P064Quad cross = P064Intrinsics::_mm_sub_ps(P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 0xc9),
                                                                           P064Intrinsics::_mm_shuffle_ps(q, q, 0xd2)),
                                                P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 0xd2),
                                                                           P064Intrinsics::_mm_shuffle_ps(q, q, 0xc9)));
    cross = P064Intrinsics::_mm_mul_ps(cross, w);
    P064Quad b =
        P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(w, w), DAT_010c71e0), v);
    P064Quad c = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(sum2, sum2, 0), q);
    P064Quad r = P064Intrinsics::_mm_add_ps(cross, P064Intrinsics::_mm_add_ps(b, c));
    out = P064Intrinsics::_mm_add_ps(r, r);
}

__forceinline void rotateForwardOutFinal(P064Quad& out, const P064Quad& v, const P064Quad& q)
{
    P064Quad w = P064Intrinsics::_mm_shuffle_ps(q, q, 0xff);
    P064Quad prod = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_load_ps(q.m128_f32), v);
    P064Quad dot =
        P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(prod, prod, 0xaa),
                                   P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(prod, prod, 0x55), prod));
    P064Quad cross = P064Intrinsics::_mm_sub_ps(P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 0xd2),
                                                                           P064Intrinsics::_mm_shuffle_ps(q, q, 0xc9)),
                                                P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(v, v, 0xc9),
                                                                           P064Intrinsics::_mm_shuffle_ps(q, q, 0xd2)));
    P064Quad a = P064Intrinsics::_mm_mul_ps(cross, w);
    P064Quad b =
        P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(w, w), DAT_010c71e0), v);
    P064Quad c = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(dot, dot, 0), q);
    P064Quad r = P064Intrinsics::_mm_add_ps(a, P064Intrinsics::_mm_add_ps(b, c));
    out = P064Intrinsics::_mm_add_ps(r, r);
}

__forceinline void FootIKQsTransformLocal_00c76350::setInverseFinal(const FootIKQsTransformLocal_00c76350& parent)
{
    rotateInverseOutFinal(translation.v, parent.translation.v, parent.rotation.v);
    translation.v = P064Intrinsics::_mm_xor_ps(translation.v, DAT_010c44d0);
    rotation.v = P064Intrinsics::_mm_xor_ps(parent.rotation.v, DAT_010c4c00);
    P064Quad s = P064Intrinsics::_mm_shuffle_ps(parent.scale.v,
                                                P064Intrinsics::_mm_unpackhi_ps(parent.scale.v, DAT_010c7170), 0xc4);
    P064Quad r = P064Intrinsics::_mm_rcp_ps(s);
    P064Quad correction = P064Intrinsics::_mm_mul_ps(r, s);
    correction = P064Intrinsics::_mm_mul_ps(correction, r);
    P064Quad twice = P064Intrinsics::_mm_add_ps(r, r);
    r = P064Intrinsics::_mm_sub_ps(twice, correction);
    scale.v = P064Intrinsics::_mm_and_ps(r, DAT_010c4c10);
}

__forceinline void FootIKQsTransformLocal_00c76350::setMulFinal(const FootIKQsTransformLocal_00c76350& a, const FootIKQsTransformLocal_00c76350& b)
{
    P064Quad rotated;
    rotateForwardOutFinal(rotated, b.translation.v, a.rotation.v);
    translation.v = P064Intrinsics::_mm_add_ps(rotated, a.translation.v);
    rotation.setMul(a.rotation, b.rotation);
    scale.v = P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_load_ps(b.scale.v.m128_f32), a.scale.v);
}

__forceinline void relativeFinal(Pose* pose, int i, const FootIKQsTransformLocal_00c76350& parent, const FootIKQsTransformLocal_00c76350& child)
{
    FootIKQsTransformLocal_00c76350 inverseTransform;
    FootIKQsTransformLocal_00c76350& destination = pose->local[i];
    inverseTransform.setInverseFinal(parent);
    destination.setMulFinal(inverseTransform, child);
}

__forceinline FootIKQsTransformLocal_00c76350& Pose::getLocalFinal(int i)
{
    if (!(flags[i] & 1))
        return local[i];
    {
        const FootIKQsTransformLocal_00c76350& child = model[i];
        short p = skeleton->parents[i];
        if (p != -1)
        {
            const FootIKQsTransformLocal_00c76350& parent = getModel(p);
            relativeFinal(this, i, parent, child);
        }
        else
            local[i] = child;
        flags[i] &= ~1;
    }
    return local[i];
}

__forceinline void Pose::propagateFinal(int i)
{
    // Preserve descendant locals before invalidating their model transforms.
    int n = skeleton->count;
    flags[i] |= 4;
    for (int j = i + 1; j < n; ++j)
    {
        short p = skeleton->parents[j];
        if (p != -1 && (flags[p] & 4))
        {
            getLocalFinal(j);
            flags[j] |= 4;
            localDirty = false;
        }
    }
    for (int j = i + 1; j < n; ++j)
    {
        unsigned int& f = flags[j];
        if (f & 4)
            f = (f & ~4) | 2;
    }
}

// @fnv 0x00c76350
// src: XBOX_PDB 0x00c76350
void Controller::bhkRagdollController_DoFootIK(const FootIKQsTransformLocal_00c76350& world)
{
    Input inputData;
    inputData.InitializeDefaults();
    Output result;
    inputData.worldFromModel = world;
    inputData.gain = !fullGain ? DAT_01267d48 : 1.0f;
    inputData.upGain = DAT_01267d54;
    inputData.downGain = DAT_01267d60;
    inputData.ascendingGain = DAT_01267d6c;
    inputData.verticalError = DAT_01267d78;
    if (!fullGain)
        inputData.enabled = !disabled;
    else
        inputData.enabled = false;
    inputData.raycast = this;
    {
        FootIKQsTransformLocal_00c76350 rootTransform = pose->getModel(0);
        Vec rootPosition = rootTransform.translation;
        float adjustment;
        adjustRoot(rootPosition, height, adjustment);
        rootTransform.translation = rootPosition;
        P064Quad shift = FootIKIntrinsics::_mm_setr_ps(DAT_01011d78, DAT_01011d78, adjustment, DAT_01011d78);
        inputData.worldFromModel.translation.v =
            P064Intrinsics::_mm_add_ps(shift, inputData.worldFromModel.translation.v);
        Pose* p = pose;
        p->propagate(0);
        FootIKQsTransformLocal_00c76350& saved = p->model[0];
        saved = rootTransform;
        p->flags[0] = 1;
        p->modelDirty = false;
    }
    for (int i = 0; i < legCount; ++i)
    {

        Vec rootOut = legs[i].solver->target;
        legs[i].solver->offset = offset;
        if (!keepTarget)
            legs[i].solver->target.v = P064Intrinsics::_mm_setzero_ps();
        short bone = legs[i].solver->bone;
        FootIKQsTransformLocal_00c76350 original = pose->getLocal(bone);
        component(inputData, &Input::modelFromWorld) = pose->getModel(legs[i].solver->bone);
        currentLeg = (short)i;
        unk238 = 0;
        float start = GetElapsedSeconds();

        legs[i].solver->hkaFootPlacementIkSolver_doFootPlacement(inputData, result, pose);
        float q = GetElapsedSeconds();
        legs[i].height = component(result, &Output::height);
        DAT_01267c1c += (q - start) * 1000.0;
        FootIKQsTransformLocal_00c76350 solved = pose->getLocalAfter(bone);
        if (blend)
        {
            if (reset)
                legs[i].previous = solved;
            short high = legs[i].body;
            if (high != -1)
            {
                int index = bodies->lookup[high] - 1;
                Body* body = 0 > index ? 0 : bodies->data[index];
                Shape* shape = body->shape;
                if (shape->type() == 13)
                    shape = shape->hkpMalleableConstraintData_getWrappedConstraintData();
                if (shape->type() == 2)
                {
                    Vec axis = shape->vertices[shape->vertex];
                    Vec perpendicular;
                    float end;
                    solved.rotation.hkQuaternion_decomposeRestAxis(axis, perpendicular, end);
                    solved.rotation.hkQuaternion_setAxisAngle(axis, end);
                }
            }
            Scalar t(DAT_01016248);
            original.interpolate(solved, legs[i].previous, t);
            legs[i].previous = original;
        }
        Pose* p = pose;
        p->propagateFinal(bone);
        p->local[bone] = original;
        p->flags[bone] = 2;
        p->localDirty = false;
        legs[i].solver->target = rootOut;
    }
    if (reset)
        reset = false;
    float weight = fullBlend ? 1.0f : DAT_01267da8;
    float a = legs[0].height;
    float b = legs[1].height;
    float low = lower(a, b);
    float a2 = legs[0].height;
    float b2 = legs[1].height;
    float bodyIndex = upper(a2, b2);
    if (!disabled)
    {
        float delta = weight * low + (1.0f - weight) * bodyIndex;
        delta *= DAT_01267db4;
        height += delta;
    }
    float second = height;
    float raised = DAT_0102caf8 < second ? second : DAT_0102caf8;
    float capped = DAT_0101712c > raised ? raised : DAT_0101712c;
    height = capped;
    if (disabled)
    {
        height *= DAT_010217d8;
        frames++;
        int frameCount = frames;
        _ReadWriteBarrier();
        if (DAT_01267dcc == frameCount)
        {
            fullGain = false;
            frames = 0;
            disabled = false;
            unk222 = false;
            reset = true;
            return;
        }
        fullGain = false;
    }
    else
    {
        _ReadWriteBarrier();
        fullGain = false;
    }
}

inline void quaternionProduct(P064Quad& out, const Quaternion& a, const Quaternion& b)
{

    P064Quad left = a.v;
    P064Quad right = b.v;
    P064Quad cross =
        P064Intrinsics::_mm_sub_ps(P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(right, right, 0xd2),
                                                              P064Intrinsics::_mm_shuffle_ps(left, left, 0xc9)),
                                   P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(right, right, 0xc9),
                                                              P064Intrinsics::_mm_shuffle_ps(left, left, 0xd2)));
    P064Quad lw = P064Intrinsics::_mm_shuffle_ps(left, left, 0xff);
    P064Quad rw = P064Intrinsics::_mm_shuffle_ps(right, right, 0xff);
    P064Quad xyz =
        P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(lw, lw, 0), right), cross);
    xyz = P064Intrinsics::_mm_add_ps(P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(rw, rw, 0), left), xyz);
    P064Quad prod = P064Intrinsics::_mm_mul_ps(right, left);
    P064Quad dot =
        P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(prod, prod, 0xaa),
                                   P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(prod, prod, 0x55), prod));
    P064Quad w = P064Intrinsics::_mm_sub_ps(prod, P064Intrinsics::_mm_shuffle_ps(dot, dot, 0));
    Quaternion result;
    result.v = P064Intrinsics::_mm_shuffle_ps(xyz, P064Intrinsics::_mm_unpackhi_ps(xyz, w), 0xc4);
    out = result.v;
}

// src: COMMUNITY 0x00c66320
__declspec(noinline) void Quaternion::setMul(const Quaternion& a, const Quaternion& b)
{
    P064Quad value;
    quaternionProduct(value, a, b);
    v = value;
}

}  // namespace FootIKDetail
