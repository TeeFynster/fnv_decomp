#include <xmmintrin.h>
typedef ::__m128 LocalM128;
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form

// src/staging/blk_00c60000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00c60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00c60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#define FNV_VEC4_SIMD
#include "../../include/Vec4.h"
#include "../../include/Bound.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiPSysData.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}

inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}

__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
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
#include "../../include/Setting.h"
#include "../../include/hkVector4.h"
#include "../../include/hkMatrix4.h"
#include "../../include/NiTPointerList.h"
#include "../../include/hkpCdBody.h"
#include "../../include/hkpCollidable.h"
#include "../../include/hkpRigidBody.h"
#include "../../include/hkpShape.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiStream.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiColorA.h"
#include "../../include/hkpShapeInfo.h"
#include "../../include/BSDecalPlacementVectorExtraData.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiObject.h"
#include "../../include/BSPSysSimpleColorModifier.h"
#include "../../include/NiPSysModifier.h"
#include "../../include/NiBinaryExtraData.h"
#include "../../include/NiPSysCylinderEmitter.h"
#include "../../include/NiPSysVolumeEmitter.h"
#include "../../include/NiPSysPositionModifier.h"
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
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
struct NiExtraDataSaveHelper
{
    void SaveBinary(NiStream& s);
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
struct NiPoint3_ZERO
{
    int x;
    int y;
    int z;
};
extern NiPoint3_ZERO _NiPoint3_ZERO;
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
struct IsEqualHelper
{
    bool __thiscall IsEqual(NiObject* arg);
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
struct NiPoint3_c
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
extern NiPoint3_c NiPoint3_ZERO;
struct FUN_00c63780_c
{
    int pad[9];
    NiPoint3_c v;
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
struct C639a0Cls : MyIsEqual
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

// @fnv 0x00c6cf30
// src: COMMUNITY 0x00c6cf30
void CharacterProxy::bhkCharacterProxy_Integrate(unsigned int formID)
{
    volatile unsigned int id = formID;
    this->DoLockCall();
    if (this)
    {
        PointLoader* loader = (PointLoader*)this->m_08;
        if (loader)
        {
            AlignedOwnerNode tmp(&this->m_kPoints);
            VirtualResult* result = this->v37();
            loader->ReadPointsFromFile(id, &result->m_10, &tmp, &this->m_kPoints);
            this->m_kPoints.CollectPoints();
        }
    }
    this->DoLockCall();
}

extern "C" void _ReadWriteBarrier();


inline const hkpCollidable* hkpCdBody::getRootCollidable() const
{
    const hkpCdBody* body = this;
    while (body->m_parent)
    {
        body = body->m_parent;
    }
    return reinterpret_cast<const hkpCollidable*>(body);
}
inline void* hkpCollidable::getOwner() const
{
    return (void*)((char*)this + m_iOwnerOffset);
}
inline const hkVector4& hkpRigidBody::getLinearVelocity() const
{
    return m_pMotionState.m_kTranslationalVelocity;
}

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

// @fnv 0x00c6e980
// src: XBOX_PDB 0x00c6e980
void GroundController::bhkCharacterController_SetSupportMaterial(const GroundPoint* point)
{
    if (m_iMaterialIndex == 0xf)
    {
        return;
    }
    const hkpCdBody* body = point->m_kCollidable;
    int material = 0x24;
    if (!body)
    {
        return;
    }
    int layer = body->getRootCollidable()->m_kBroadPhaseHandle.m_uiCollisionFilterData & 0x7f;
    m_layer = layer;
    hkpRigidBody* rb = hkGetRigidBody(body->getRootCollidable());
    const hkVector4* velocity = rb ? &rb->getLinearVelocity() : (const hkVector4*)&DAT_01267e30;
    m_fVelocity.m_vComponents = velocity->m_vComponents;

    if (point->m_uiCollisionShapeKey == -1)
    {
        const hkpShape* shape = body->m_pCollisionShape;
        if (shape && shape->m_ulUserData)
        {
            material = reinterpret_cast<const hkpShapeInfo*>(shape->m_ulUserData)->m_flags & 0x1f;
        }
    }
    else if (layer != 0x11)
    {
        MaterialSource* src = bhkUtilFunctions_FindbhkShapeCollection(body);
        if (src)
        {
            material = src->getMaterial(point->m_uiCollisionShapeKey);
        }
    }

    if (m_iMaterialIndex == 0x24 || material == 0xf)
    {
        m_iMaterialIndex = material;
        bool b = false;
        if (DAT_01267bc8)
        {
            b = DAT_01267bc8(material);
        }
        _ReadWriteBarrier();
        if (b)
        {
            m_flags |= 0x1000000;
        }
        else
        {
            m_flags &= ~0x1000000;
        }
        _ReadWriteBarrier();
        if (((unsigned char)(m_flags >> 16) & 1) || material == 0xf)
        {
            _ReadWriteBarrier();
            if (m_iMaterialIndex == 0xf)
            {
                m_flags |= 0x20000;
            }
            else
            {
                m_flags &= ~0x20000;
            }
        }
    }
}

namespace fnv_00c741e0 {
typedef ::__m128 LocalM128;
using ::_mm_store_ps;
using ::_mm_setzero_ps;
using ::_mm_setr_ps;
extern "C" unsigned long __readfsdword(unsigned long);

extern "C" unsigned int DAT_0126fd98;
extern "C" float DAT_011b0148;
extern "C" double DAT_01023128;
extern "C" float DAT_010162c0;
extern "C" float DAT_01017b78;
extern "C" float DAT_01012054;
extern "C" LocalM128 DAT_01267e30;
union T741_V
{
    __forceinline T741_V(const LocalM128& q)
    {
        m_vComponents = q;
    }
    LocalM128 m_vComponents;
    float m_f[4];
    unsigned char m_kPointB[16];
};

struct T741_Src
{
    int f000;
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int fa4;
    float fa8;
    float fac;
};

extern __declspec(thread) int T741_tlsVal;

struct T741_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* Alloc(int& size);
    __forceinline void* BufAlloc(int& num)
    {
        int sz = num * 112;
        void* p = Alloc(sz);
        num = sz / 112;
        return p;
    }
};
struct T741_Owner
{
    int f00;
    int f04;
    int f08;
    int f0c;
    T741_Alloc* m_alloc;
    __forceinline T741_Alloc& heap()
    {
        return *m_alloc;
    }
};
T741_Owner* hkMemoryRouter_getInstance();

struct T741_B0
{
    T741_B0();
    virtual ~T741_B0();
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int f0a4;
    int f0a8;
    int f0ac;
    int f0b0;
    int f0b4;
    int f0b8;
    int f0bc;
    int f0c0;
    int f0c4;
    int f0c8;
    int f0cc;
    int f0d0;
    int f0d4;
    int f0d8;
    int f0dc;
    int f0e0;
    int f0e4;
    int f0e8;
    int f0ec;
    int f0f0;
    int f0f4;
    int f0f8;
    int f0fc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    int f130;
    int f134;
    int f138;
    int f13c;
    int f140;
    int f144;
    int f148;
    int f14c;
    int f150;
    int f154;
    int f158;
    int f15c;
    int f160;
    int f164;
    int f168;
    int f16c;
    int f170;
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0;
    int f1d4;
    int f1d8;
    int f1dc;
    int f1e0;
    int f1e4;
    int f1e8;
    int f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    int f210;
    int f214;
    int f218;
    int f21c;
    int f220;
    int f224;
    int f228;
    int f22c;
    int f230;
    int f234;
    int f238;
    int f23c;
    int f240;
    int f244;
    int f248;
    int f24c;
    int f250;
    int f254;
    int f258;
    int f25c;
    int f260;
    int f264;
    int f268;
    int f26c;
    int f270;
    int f274;
    int f278;
    int f27c;
    int f280;
    int f284;
    int f288;
    int f28c;
    int f290;
    int f294;
    int f298;
    int f29c;
    int f2a0;
    int f2a4;
    int f2a8;
    int f2ac;
    int f2b0;
    int f2b4;
    int f2b8;
    int f2bc;
    int f2c0;
    int f2c4;
    int f2c8;
    int f2cc;
    int f2d0;
    int f2d4;
    int f2d8;
    int f2dc;
    int f2e0;
    int f2e4;
    int f2e8;
    int f2ec;
    int f2f0;
    int f2f4;
    int f2f8;
    int f2fc;
    int f300;
    int f304;
    int f308;
    int f30c;
    int f310;
    int f314;
    int f318;
    int f31c;
    int f320;
    int f324;
    int f328;
    int f32c;
    int f330;
    int f334;
    int f338;
    int f33c;
    int f340;
    int f344;
    int f348;
    int f34c;
    int f350;
    int f354;
    int f358;
    int f35c;
    int f360;
    int f364;
    int f368;
    int f36c;
    int f370;
    int f374;
    int f378;
    int f37c;
    int f380;
    int f384;
    int f388;
    int f38c;
    int f390;
    int f394;
    int f398;
    int f39c;
    int f3a0;
    int f3a4;
    int f3a8;
    int f3ac;
    int f3b0;
    int f3b4;
    int f3b8;
    int f3bc;
    int f3c0;
    int f3c4;
    int f3c8;
    int f3cc;
    int f3d0;
    int f3d4;
    int f3d8;
    int f3dc;
};
struct T741_B1
{
    T741_B1(int a, int b);
    virtual ~T741_B1();
    int f3e4;
    int f3e8;
    int f3ec;
    int f3f0;
    int f3f4;
    int f3f8;
    int f3fc;
    int f400;
    int f404;
    int f408;
    int f40c;
};
struct T741_B2a
{
    T741_B2a(const T741_V& v, float a, float b);
    virtual ~T741_B2a();
    int f414;
    int f418;
    int f41c;
    int f420;
    int f424;
    int f428;
    int f42c;
    int f430;
    int f434;
    int f438;
    int f43c;
    int f440;
    int f444;
    int f448;
    int f44c;
    float f450[4];
    __forceinline void Reset()
    {
        f414 = 0;
        *(LocalM128*)f450 = _mm_setzero_ps();
    }
};
struct T741_B3
{
    int f460;
    int f464;
    int f468;
    int f46c;
    int f470;
    int f474;
    int f478;
    int f47c;
    int f480;
    int f484;
    int f488;
    int f48c;
    float f490[4];
    float f4a0[4];
    float f4b0;
    bool f4b4;
    int f4b8;
    int f4bc;
    __forceinline T741_B3()
    {
        f4b0 = 0.0f;
        _mm_store_ps(f490, _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f));
        f480 = 2;
        _mm_store_ps(f4a0, _mm_setr_ps(0.0f, 0.0f, 0.0f, 0.0f));
        f4b4 = false;
    }
};
struct T741_M3
{
    float f4c0[4];
    float f4d0[4];
    int f4e0;
    int f4e4;
    int f4e8;
    int f4ec;
    int f4f0;
    int f4f4;
    int f4f8;
    int f4fc;
    __forceinline T741_M3()
    {
        _mm_store_ps(f4c0, _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f));
        _mm_store_ps(f4d0, _mm_setr_ps(1.0f, 0.0f, 0.0f, 0.0f));
    }
    ~T741_M3();
};
struct T741_M4
{
    float f500[4];
    int f510;
    int f514;
    int f518;
    int f51c;
    int f520;
    float f524;
    float f528;
    float f52c;
    float f530;
    float f534;
    float f538;
    int f53c;
    int f540;
    float f544;
    float f548;
    float f54c;
    float f550;
    float f554;
    float f558;
    int f55c;
    int f560;
    int f564;
    int f568;
    int f56c;
    float f570[4];
    int f580;
    int f584;
    int f588;
    int f58c;
    int f590;
    int f594;
    int f598;
    __forceinline T741_M4()
    {
        _mm_store_ps(f500, DAT_01267e30);
        f520 = 0;
        f524 = 0.0f;
        f528 = 0.0f;
        f52c = 0.0f;
        f530 = 0.0f;
        f534 = 0.0f;
        f538 = 0.0f;
        f544 = 0.0f;
        f548 = 0.0f;
        f54c = 1.0f;
        f550 = 0.0f;
        f554 = 0.0f;
        f558 = 1.0f;
        _mm_store_ps(f570, DAT_01267e30);
        f594 = 0;
        f598 = 0;
    }
    ~T741_M4();
};
struct T741_E
{
    int v;
    T741_E();
    ~T741_E();
};
struct T741_M6
{
    float f5f0;
    float f5f4;
    float f5f8;
    float f5fc;
    int f600;
    int f604;
    int f608;
    __forceinline T741_M6()
    {
        f5f0 = 2.0f;
        f600 = 0;
        f5f4 = 10.0f;
        f604 = 0;
        f5f8 = 2.0f;
        f608 = 0;
        f5fc = -1.0f;
    }
    ~T741_M6();
};
struct T741_M7
{
    float f620[4];
    int f630;
    __forceinline T741_M7()
    {
        _mm_store_ps(f620, DAT_01267e30);
        f630 = 0;
    }
    ~T741_M7();
};
struct T741_M8
{
    float f634;
    int f638;
    __forceinline T741_M8()
    {
        f634 = 0.0f;
        f638 = 0;
    }
    ~T741_M8();
};
struct T741_Arr
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline T741_Arr()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
        int n = 5;
        void* data = hkMemoryRouter_getInstance()->heap().BufAlloc(n);
        int cap = n;
        if (!n)
            cap = 0x80000000;
        m_data = data;
        m_iElementCount = n;
        m_cap = cap;
    }
    ~T741_Arr();
};
struct T741_M10
{
    int f648;
    int f64c;
    __forceinline T741_M10()
    {
        f648 = 0;
        f64c = 0;
    }
    ~T741_M10();
};
struct T741_Guard
{
    int m_old;
    __forceinline T741_Guard()
    {
        m_old = T741_tlsVal;
        T741_tlsVal = 0x10;
    }
    __forceinline ~T741_Guard()
    {
        T741_tlsVal = m_old;
    }
};

struct FUN_00c741e0 : T741_B0, T741_B1, T741_B2a, T741_B3
{
    T741_M3 m4c0;
    T741_M4 m500;
    int f59c;
    int f5a0;
    T741_E m5a4[2];
    int f5ac;
    int f5b0;
    int f5b4;
    int f5b8;
    int f5bc;
    int f5c0;
    int f5c4;
    int f5c8;
    int f5cc;
    int f5d0;
    int f5d4;
    int f5d8;
    int f5dc;
    int f5e0;
    int f5e4;
    int f5e8;
    int f5ec;
    T741_M6 m5f0;
    int f60c;
    bool f610;
    int f614;
    int f618;
    int f61c;
    T741_M7 m620;
    T741_M8 m630;
    T741_Arr m63c;
    T741_M10 m648;
    FUN_00c741e0(T741_Src* p);
    virtual ~FUN_00c741e0();
    void bhkCharacterController_Init(T741_Src* p);
};

// @fnv 0x00c741e0
FUN_00c741e0::FUN_00c741e0(T741_Src* p)
    : T741_B1(p->fa4, p->f09c),
      T741_B2a(T741_V(_mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f)), (float)(DAT_011b0148 * DAT_01023128), p->fac * p->fa8),
      f59c(2), f5a0(2), f60c(0), f610(false)
{
    T741_Guard guard;
    Reset();
    m63c.m_iElementCount = 0;
    bhkCharacterController_Init(p);
}
}  // namespace fnv_00c741e0

namespace fnv_00c66320 {
typedef ::__m128 LocalM128;
using ::_mm_store_ps;
using ::_mm_shuffle_ps;
using ::_mm_mul_ps;
using ::_mm_sub_ps;
using ::_mm_add_ps;
using ::_mm_add_ss;
using ::_mm_unpackhi_ps;
using ::_mm_load_ps;

static __forceinline void multiply(LocalM128* out, const LocalM128* a, const LocalM128* b);

// @fnv 0x00c66320
// src: COMMUNITY 0x00c66320
void __fastcall hkQuaternion_setMul(LocalM128* out, void*, const LocalM128* a, const LocalM128* b)
{
    __declspec(align(16)) char result[16];
    LocalM128 value;
    multiply(&value, a, b);
    _mm_store_ps((float*)result, value);
    *out = _mm_load_ps((const float*)result);
}

static __forceinline void multiply(LocalM128* out, const LocalM128* a, const LocalM128* b)
{
    LocalM128 x = *a;
    LocalM128 y = *b;
    LocalM128 t0 = _mm_shuffle_ps(x, x, 0xd2);
    LocalM128 t1 = _mm_shuffle_ps(y, y, 0xc9);
    t1 = _mm_mul_ps(t1, t0);
    LocalM128 t2 = _mm_shuffle_ps(x, x, 0xc9);
    t0 = _mm_shuffle_ps(y, y, 0xd2);
    t0 = _mm_mul_ps(t0, t2);
    t0 = _mm_sub_ps(t0, t1);
    t1 = _mm_shuffle_ps(x, x, 0xff);
    t1 = _mm_shuffle_ps(t1, t1, 0);
    t1 = _mm_mul_ps(t1, y);
    t1 = _mm_add_ps(t1, t0);
    t0 = _mm_shuffle_ps(y, y, 0xff);
    y = _mm_mul_ps(y, x);
    t0 = _mm_shuffle_ps(t0, t0, 0);
    t0 = _mm_mul_ps(t0, x);
    t0 = _mm_add_ps(t0, t1);
    t1 = _mm_shuffle_ps(y, y, 0x55);
    t1 = _mm_add_ss(t1, y);
    x = _mm_shuffle_ps(y, y, 0xaa);
    x = _mm_add_ss(x, t1);
    t1 = t0;
    x = _mm_shuffle_ps(x, x, 0);
    y = _mm_sub_ps(y, x);
    t0 = _mm_unpackhi_ps(t0, y);
    *out = _mm_shuffle_ps(t1, t0, 0xc4);
}
}  // namespace fnv_00c66320

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
// @fnv 0x00c696d0
// src: XBOX_PDB 0x00c696d0
bool RayCaster::bhkWorld_PickObject(Query* query)
{
    __declspec(align(16)) unsigned char storage[sizeof(FilterCast)];
    Scratch scratch;
    if (!DAT_012677a3)
    {
        scratch.threshold = DAT_012677cc ? DAT_011afe78 : DAT_011afe74;
        if (DAT_012677c4 > scratch.threshold)
        {
            query->disabled = true;
            query->result.Clear();
            return false;
        }
    }
    TraceBegin(str_010c41fc, scratch);
    bool found = false;
    World* world = GetWorld();
    if (world)
    {
        query->bhkPickData_CalcTo();
        scratch.result = &query->result;
        scratch.result->Clear();
        HitResultList* hits = query->hits;
        if (hits)
        {
            void* cache = query->filter;
            if (cache)
            {
                ((FilterCast*)storage)->FilterCast::FilterCast(world, query, cache, hits);
            }
            else
                world->hkpWorld_castRay(query, hits);
            if (hits->count)
            {
                hits->hknpAllHitsCollector_sortHits();
                Result* hit = hits->result;
                scratch.result->ProcessEntries_009c1aa0(hit);
                scratch.result->field50 = hit->field50;
                found = true;
            }
        }
        else
        {
            Collector* collector = query->collector;
            if (collector)
            {
                Result* collected = &collector->result;
                collected->Clear();
                collector->fraction = 1.0f;
                void* cache = query->filter;
                if (cache)
                {
                    ((FilterCast*)storage)->FilterCast::FilterCast(world, query, cache, collector);
                }
                else
                    world->hkpWorld_castRay(query, collector);
                if (collector->result.field50)
                {
                    scratch.result->CopyRayCastResultAndRootCollidable(collected);
                    found = true;
                }
            }
            else
            {
                world->hkpWorld_castRay_00c92040(query, scratch.result);
                found = query->result.field50 != 0;
            }
        }
    }
    TraceEnd(str_010c41f8, scratch);
    return found;
}

// hkMatrix4-style copy: assign four 16-byte columns and return *this.

__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

// The shared assignment returns void; this out-of-line copy also returns its destination.
// @fnv 0x00c6cd60
hkMatrix4& __fastcall AssignMatrix(hkMatrix4* destination, void*, const hkMatrix4& other)
{
    destination->m_kColumn0 = other.m_kColumn0;
    destination->m_kColumn1 = other.m_kColumn1;
    destination->m_kColumn2 = other.m_kColumn2;
    destination->m_kColumn3 = other.m_kColumn3;
    return *destination;
}

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

// @fnv 0x00c6d670
// src: GUESS 0x00c6d670 (confidence: low)
SseBlock& SseBlock::UpdateState_00c6d670(const SseBlock& o)
{
    m_00 = o.m_00;
    m_10 = o.m_10;
    m_20 = o.m_20;
    m_24 = o.m_24;
    m_28 = o.m_28;
    m_2c = o.m_2c;
    m_30 = o.m_30;
    return *this;
}

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

__forceinline float& Vec4::operator()(int i)
{
    return reinterpret_cast<float*>(&m_vComponents)[i];
}

__forceinline void Vec4::operator=(const Vec4& v)
{
    m_vComponents = v.m_vComponents;
}

// Preserve this unit's scalar length result using the shared vector storage.
__forceinline float Vec4Length3(const Vec4& value)
{
    float result;
    LocalM128 sq = _mm_mul_ps(value.m_vComponents, value.m_vComponents);
    LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), sum);
    _mm_store_ss(&result, _mm_sqrt_ss(sum));
    return result;
}

__forceinline void Vec4::normalize3()
{
    LocalM128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
    LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), sum);
    LocalM128 inv = _mm_rsqrt_ss(sum);
    LocalM128 zero = _mm_set_ss(DAT_01011d78);
    LocalM128 three = _mm_set_ss(DAT_01017718);
    LocalM128 half = _mm_set_ss(DAT_01016248);
    LocalM128 isZero = _mm_cmpeq_ss(sum, zero);
    LocalM128 r = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(sum, inv), inv));
    r = _mm_andnot_ps(isZero, _mm_mul_ss(_mm_mul_ss(half, inv), r));
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
}

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

// @fnv 0x00c77ac0
// src: XBOX_PDB 0x00c77ac0
bool SceneEffect::bhkRagdollController_ExtractBipedSetupData(EffectOutput* pkOutput, EffectRequest* pkRequest)
{
    struct MidContext
    {
        SceneObject* object;
        float angleY;
        float angleX;
    };
    MidContext context;
    EffectName* pkName = pkRequest->m_pkName;
    FxNode* pkRoot = BSUtilities_GetObjectByName_00c4b470(m_pkScene, &FxString(pkName->m_pcText), 1);
    FxNode* pkMid = FirstChild(pkRoot);
    _ReadWriteBarrier();
    FxNode* pkEnd = FirstChildP(pkMid);
    if (!pkRoot || !pkMid || !pkEnd)
        return false;

    SceneObject* pkRootObj = bhkRagdollController_GetCapsuleBoneShapeInfo(pkRoot);
    context.object = bhkRagdollController_GetCapsuleBoneShapeInfo(pkMid);
    SceneObject* pkEndObj = bhkRagdollController_GetCapsuleBoneShapeInfo(pkEnd);
    FxObject** ppkMidProps = Properties(pkMid);
    FxObject** ppkEndProps = Properties(pkEnd);
    if (!pkRootObj || !context.object || !pkEndObj || !ppkMidProps || !ppkEndProps)
        return false;

    VfxSource* pkBase = FindSource(ppkMidProps);
    if (!pkBase)
        return false;

    float fAngleDifference = DAT_01066808 - pkBase->m_fFinalAngle * DAT_0102f248 - DAT_01020758;
    fAngleDifference = fAngleDifference * DAT_01023128;
    fAngleDifference = cos(fAngleDifference);
    context.angleX = -fAngleDifference;
    fAngleDifference = pkBase->m_fOriginAngle * DAT_0102f248 + DAT_01066808 - DAT_0102fc70;
    fAngleDifference = fAngleDifference * DAT_01023128;
    fAngleDifference = cos(fAngleDifference);
    context.angleY = fAngleDifference;
    // Keep the original SIMD byte buffers for /GS stack placement, using the shared Vec4 view.
    __declspec(align(16)) char kDirectionStorage[sizeof(Vec4)];
    Vec4& kDirection = *reinterpret_cast<Vec4*>(kDirectionStorage);
    kDirection = pkBase->m_kInitialDirection;

    VfxSource* pkFinal = FindSource(ppkEndProps);
    VfxSource* pkSpecial = 0;
    if (!pkFinal)
    {
        FxObject* pkSpecialObject = *ppkEndProps;
        SourceProperty* pkProp = (SourceProperty*)NiObject_DynamicCast(&DAT_0126864c, pkSpecialObject);
        pkSpecial = pkProp ? pkProp->UpdateState_00c747b0()->GetSource() : 0;
        if (!pkSpecial)
            return false;
    }
    __declspec(align(16)) char kFinalStorage[sizeof(Vec4)];
    Vec4& kFinal = *reinterpret_cast<Vec4*>(kFinalStorage);
    if (pkFinal)
        kFinal = pkFinal->m_kFinalDirection;
    else
        kFinal = pkSpecial->m_kInitialDirection;
    __declspec(align(16)) char kDisplacementStorage[sizeof(Vec4)];
    Vec4& kDisplacement = *reinterpret_cast<Vec4*>(kDisplacementStorage);
    kDisplacement = DifferenceOf(pkEndObj);
    fAngleDifference = *DAT_01267d98.Setting_Float_00403e20() + kFinal(0);
    if (pkSpecial)
    {
        Vec4Length3(DifferenceOf(pkRootObj));
        Vec4Length3(DifferenceOfMid(context.object));
    }

    EffectOutput* __restrict result = pkOutput;
    result->m_kLightVector = kDirection;
    result->m_kLightVector.normalize3();
    if (Vec4Length3(kDisplacement) < 0.5f)
        kDisplacement.m_vComponents = _mm_setzero_ps();
    pkOutput->m_kDisplacement = kDisplacement;
    pkOutput->m_fAngleZ = -*DAT_01267de0.Setting_Float_00403e20();
    pkOutput->m_fOriginZ =
        (context.object->origin.x - context.object->end.x) + 2.0 * pkEndObj->origin.x + fAngleDifference;
    pkOutput->m_fOriginX = pkEndObj->origin.x;
    pkOutput->m_fOriginY = pkOutput->m_fOriginZ - 2.0 * fAngleDifference;
    pkOutput->m_fAngleX = context.angleX;
    pkOutput->m_fAngleY = context.angleY;
    return true;
}

namespace fnv_00c7b1f0 {
using ::_mm_setr_ps;
using ::_mm_load_ps;
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct StringHeader_c7
{
    volatile long refs;
    unsigned int length;
};

struct Alloc_c7
{
    virtual void Slot0();
    virtual void* Alloc(unsigned int size);
};

struct Heap_c7
{
    unsigned char* cursor;
    unsigned int pad04_000;
    unsigned int pad04_001;
    unsigned int pad04_002;
    Alloc_c7* alloc;
};

struct Root_c7
{
    unsigned int pad00_000;
    unsigned int pad00_001;
    unsigned int pad00_002;
    unsigned int m0c;
    unsigned int pad10_000;
    unsigned int pad10_001;
    unsigned int pad10_002;
    unsigned int m1c;
    unsigned int pad20_000;
    unsigned int pad20_001;
    unsigned int m28;
    unsigned int m2c;
    unsigned int m30;
};

struct Holder_c7
{
    unsigned int pad00_000;
    unsigned int pad00_001;
    Root_c7* root;
};

struct Matrix_c7
{
    LocalM128 row0, row1, row2;
    Matrix_c7& operator=(const Matrix_c7& r)
    {
        _mm_store_ps((float*)&row0, _mm_load_ps((const float*)&r.row0));
        _mm_store_ps((float*)&row1, _mm_load_ps((const float*)&r.row1));
        _mm_store_ps((float*)&row2, _mm_load_ps((const float*)&r.row2));
        return *this;
    }
};

struct Elem_c7
{
    unsigned int pad00;
    Matrix_c7* m4;
};

struct List_c7
{
    unsigned int pad00_000;
    unsigned int pad00_001;
    unsigned int pad00_002;
    unsigned int pad00_003;
    unsigned int count;
    Elem_c7** items;
    unsigned int pad18_000;
    unsigned char ContainsAllNames(Root_c7* r);
};

struct Cursor_c7
{
    unsigned char* saved;
    unsigned int count;
    Cursor_c7(unsigned int n);
    Cursor_c7(unsigned int n, const int& c, int& result);
    ~Cursor_c7();
};

struct ListPtr_c7
{
    List_c7* data;
    List_c7* operator->() const
    {
        return data;
    }
    operator List_c7*() const
    {
        return data;
    }
    unsigned int GetSize() const
    {
        return data->count;
    }
};

struct Glob_c7
{
    void FUN_00e92760(void* a, ListPtr_c7* pp);
};

struct FUN_00ce14b0
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
    FUN_00ce14b0(unsigned int a, unsigned int b, unsigned int c, Vec4* v);
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
    unsigned int hkaPoseMatchingUtility_addCandidatePose(unsigned char* a, unsigned int b, float c);
};

extern Glob_c7 DAT_011b02f0;
extern "C" void* DAT_0109b220;

Heap_c7* __cdecl hkMemoryRouter_getInstance();
inline void* FUN_00ce14b0::operator new(unsigned int size)
{
    Heap_c7* h = hkMemoryRouter_getInstance();
    Alloc_c7* a = h->alloc;
    return a->Alloc(size);
}
inline Cursor_c7::Cursor_c7(unsigned int n)
{
    Heap_c7* h = hkMemoryRouter_getInstance();
    unsigned char* base = h->cursor;
    unsigned int bytes = (((n * 3) << 4) + 0x7f) & 0xffffff80;
    h->cursor += bytes;
    saved = base;
}
inline Cursor_c7::Cursor_c7(unsigned int n, const int& c, int& result)
{
    Heap_c7* h = hkMemoryRouter_getInstance();
    result = c;
    unsigned char* base = h->cursor;
    unsigned int bytes = (((n * 3) << 4) + 0x7f) & 0xffffff80;
    h->cursor += bytes;
    saved = base;
}
inline Cursor_c7::~Cursor_c7()
{
    hkMemoryRouter_getInstance()->cursor = saved;
}
unsigned short __cdecl FindIndexByKey(Root_c7* r, const char* name, int flag);
void* __cdecl FUN_00a5b690(void* p);
unsigned int __cdecl CallWithGlobal(int a, unsigned int b, Matrix_c7* c, unsigned char* d);

struct Actor_c7
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
    unsigned char unk040, unk041;
    unsigned char m_42;
    unsigned char unk043;
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
    FUN_00ce14b0* m_248;
    void* m_24c;
    ListPtr_c7 m_250;
    unsigned char m_254;
    unsigned char unk255, unk256, unk257;
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
    Holder_c7* m_2a4;
    bool IsBodyValid();
    void bhkRagdollController_InitPoseMatching(void* a1, short a2, short a3, short a4);
};

// Preserve stack protection formerly induced by the vector byte-array views.
#pragma strict_gs_check(push, on)
// @fnv 0x00c7b1f0
// src: XBOX_PDB 0x00c7b1f0
void Actor_c7::bhkRagdollController_InitPoseMatching(void* a1, short a2, short a3, short a4)
{
    if (m_42 == 0)
    {
        return;
    }
    void* old = m_24c;
    if (old != a1)
    {
        m_24c = FUN_00a5b690(a1);
        if (old != DAT_0109b220)
        {
            StringHeader_c7* header = (StringHeader_c7*)old - 1;
            InterlockedDecrement(&header->refs);
        }
    }
    Holder_c7* holder = m_2a4;
    Root_c7* root = holder->root;
    unsigned int idx1, idx2;
    unsigned int idx3;
    if (a2 != -1)
    {
        idx1 = (unsigned short)a2;
    }
    else
    {
        idx1 = FindIndexByKey(root, "Bip01 NonAccum", 0);
    }
    if (a3 != -1)
    {
        idx2 = (unsigned short)a3;
    }
    else
    {
        idx2 = FindIndexByKey(root, "Bip01 Head", 0);
    }
    if (a4 != -1)
    {
        idx3 = (unsigned short)a4;
    }
    else
    {
        idx3 = FindIndexByKey(root, "Bip01 R UpperArm", 0);
    }
    Vec4 vec;
    vec.m_vComponents = _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f);
    if (!IsBodyValid())
    {
        if ((short)idx1 != -1 && (short)idx2 != -1 && (short)idx3 != -1)
        {
            return;
        }
    }
    m_248 = new FUN_00ce14b0(idx1, idx2, idx3, &vec);
    DAT_011b02f0.FUN_00e92760(a1, &m_250);
    if (m_250 == 0)
    {
        return;
    }
    for (unsigned int i = 0; i < m_250.GetSize(); i++)
    {
        Elem_c7* volatile e = m_250->items[i];
        int n = root->m1c;
        int count = n;
        Cursor_c7 g1(n);
        Matrix_c7* dst = (Matrix_c7*)g1.saved;
        int copyCount;
        Cursor_c7 g2(n, count, copyCount);
        unsigned char* old2 = g2.saved;
        if (copyCount > 0)
        {
            for (int k = 0; k < copyCount; k++)
            {
                Matrix_c7* mats = e->m4;
                dst[k] = mats[k];
            }
            copyCount = count;
        }
        unsigned int data = root->m0c;
        CallWithGlobal(copyCount, data, dst, old2);
        m_248->hkaPoseMatchingUtility_addCandidatePose(old2, 0, 0.0f);
    }
    m_254 = m_250->ContainsAllNames(root);
}
#pragma strict_gs_check(pop)
}  // namespace fnv_00c7b1f0

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
// Preserve this routine's existing trivial NiPoint3 value ABI independently of
// the shared NiPoint3 declaration pulled in by NiAVObject.
class ShapePoint3
{
  public:
    float x, y, z;
    ShapePoint3()
    {}
    ShapePoint3(float xx, float yy, float zz)
    {
        x = xx;
        y = yy;
        z = zz;
    }
    ShapePoint3 operator*(float scale) const
    {
        return ShapePoint3(x * scale, y * scale, z * scale);
    }
};
inline const ShapePoint3& ZeroPoint()
{
    return reinterpret_cast<const ShapePoint3&>(NiPoint3_ZERO);
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
template <class T> inline NiPointer<T>::NiPointer()
{
    m_pObject = 0;
}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew)
{
    m_pObject = pkNew;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer<T>& kSrc)
{
    m_pObject = kSrc.m_pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}
template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}
struct ShapePointer : NiPointer<ShapeRef>
{
    ShapePointer& operator=(ShapeRef* incoming)
    {
        NiPointer<ShapeRef>::operator=(incoming);
        return *this;
    }
    void FUN_0066b0d0(ShapeRef*);
    void FUN_00c663d0(ShapePointer const&);
};
extern ShapePointer DAT_01267be0;
struct Geometry
{
    int unk00, unk04, unk08;
    ShapePoint3 center, extents;
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
    FUN_00cab710(ShapePoint3 const&, ShapePoint3 const&, float);
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
        unsigned char* p = (unsigned char*)DAT_011f6238.Allocate(n + 16);
        unsigned char offset = 16 - ((unsigned int)p & 15);
        p += offset;
        p[-1] = offset;
        return p;
    }
    static void operator delete(void*);
};
ShapeRef* __cdecl MakeConvex(ShapePoint3 const&, ShapePoint3 const&, float, float);
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
    ShapePoint3 dimensions;
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
// @fnv 0x00c72410
// src: COMMUNITY 0x00c72410
void ShapeOwner::bhkCharacterController_InitShapes(ShapeInput* input)
{
    shapeCount = 2;
    float diameter, radius;
    float scratch;
    ShapePoint3 extents, center;
    if (input->GetShape())
    {
        shapes[input->GetIndex()] = input->GetShape();
        ShapeRef* bound = GetCurrentObject();
        radius = GetBoundRadius(bound) * DAT_011b0194;
        diameter = 0;
    }
    else
    {
        ShapePoint3 scaled, b;
        if (input->node && !input->flag96)
        {
            Geometry* geometry;
            geometry = BSBound_Find(input->node);
            if (geometry)
            {
                extents = geometry->extents * input->GetScale();
                center = geometry->center * input->GetScale();
                scaled = ZeroPoint();
            }
            else
            {
                NodeBounds* fallbackNode = input->node;
                Bound* local = fallbackNode->GetBound();
                if (flags & 1)
                {
                    extents.y = local->radius;
                    scratch = (float)(input->scale * DAT_0104f2f0);
                    extents.z = scratch;
                    extents.x = scratch;
                }
                else
                {
                    extents.z = local->radius;
                    scratch = (float)(input->scale * DAT_0104f2f0);
                    extents.y = scratch;
                    extents.x = scratch;
                }
                center = ZeroPoint();
                scaled = ZeroPoint();
            }
        }
        else
        {
            float scale = input->flag96 ? 1.0f : input->scale;
            extents.x = (float)(23.0 * scale);
            extents.y = (float)(DAT_010c4ab8 * scale);
            extents.z = (float)(DAT_010240c0 * scale);
            center = ZeroPoint();
            scaled = ZeroPoint();
        }
        if (extents.x > extents.z || extents.y > extents.z)
            flags |= 1;
        float z;
        diameter = 0;
        if (flags & 1)
        {
            scaled = center;
            scaled.z = 0;
            if (extents.x > extents.y)
            {
                diameter = (float)(2.0 * extents.x);
                if (extents.y < extents.z)
                {
                    radius = extents.y;
                    z = extents.z;
                }
                else
                {
                    radius = extents.z;
                    z = extents.y;
                }
                scaled.x += extents.x - radius;
                b = scaled;
                b.x = (float)(scaled.x * -1.0);
            }
            else
            {
                diameter = (float)(2.0 * extents.y);
                if (extents.x < extents.z)
                {
                    radius = extents.x;
                    z = extents.z;
                }
                else
                {
                    radius = extents.z;
                    z = extents.x;
                }
                scaled.y += extents.y - radius;
                b = scaled;
                b.y = (float)(scaled.y * -1.0);
            }
            if (z * 0.75 > radius)
            {
                z -= radius;
                scaled.z = (float)(z * 2.0 + radius + scaled.z);
                b.z = scaled.z;
                height = (float)(input->margin * 2.0);
                heightAccum += height;
                if (input->maxSize == 0)
                    input->maxSize = radius * DAT_01267bcc;
                CompoundInfo info;
                ShapeRef* halfLength = new FUN_00cab710(scaled, b, radius);
                scaled.z = z;
                scaled.y = (float)(scaled.y - 8.0);
                ShapePoint3 sideA = scaled;
                float sideZ = (float)(z + 1.0);
                scaled.z = sideZ;
                sideA.z = (float)(sideA.z - 1.0);
                ShapeRef* left = new FUN_00cab710(scaled, sideA, (float)(z - 1.0));
                b.z = z;
                b.y = (float)(b.y + 8.0);
                ShapePoint3 sideB = b;
                b.z = sideZ;
                sideB.z = (float)(sideB.z - 1.0);
                ShapeRef* right = new FUN_00cab710(b, sideB, (float)(z - 1.0));
                info.shapes.Add(halfLength ? halfLength->shape : 0);
                info.shapes.Add(left ? left->shape : 0);
                info.shapes.Add(right ? right->shape : 0);
                info.extra.Add(0);
                info.extra.Add(0);
                info.extra.Add(0);
                input->index = 0;
                shapes[input->GetIndex()].FUN_0066b0d0(new FUN_00c6d290(info));
            }
        }
        else
        {
            diameter = extents.z + extents.z;
            radius = (float)((extents.x + extents.y) * 0.5);
            scaled.z += extents.z - radius;
            b = scaled;
            b.z = (float)(scaled.z * -1.0);
            float limit = (float)(radius * 0.75);
            limit *= DAT_01267bcc;
            if (maxRadius < limit)
                maxRadius = limit;
        }
        centerX = center.x * DAT_01267bcc;
        centerY = center.y * DAT_01267bcc;
        ShapePointer& first = shapes[0];
        if (!first.m_pObject)
        {
            float h = scaled.z + radius;
            h *= DAT_01267bcc;
            h += input->margin * 2;
            height = h;
            heightAccum += height;
            if (input->maxSize == 0)
                input->maxSize = radius * DAT_01267bcc;
            if (flags & 1)
            {
                input->index = 0;
                shapes[input->GetIndex()].FUN_0066b0d0(new FUN_00cab710(scaled, b, radius));
            }
            else
            {
                first.FUN_0066b0d0(new FUN_00cab710(scaled, b, radius));
                if (input->flag96)
                {
                    if (DAT_01267be0.m_pObject == 0)
                        DAT_01267be0.FUN_0066b0d0(MakeConvex(scaled, b, radius, GetMaxRadius()));
                    shapes[1].FUN_00c663d0(DAT_01267be0);
                }
                else
                    shapes[1].FUN_0066b0d0(MakeConvex(scaled, b, radius, GetMaxRadius()));
            }
        }
    }
    float units = DAT_01267bcc;
    float width = radius * units;
    dimensions.x = width;
    dimensions.z = width;
    dimensions.y = units * diameter;
    float total = extents.z * 2;
    fullHeight = units * total;
    SetMode(input->GetIndex());
    if (input->flag94)
        hkMemoryRouter_getInstance();
    if (input->flag95)
    {
        NodeBounds* auxNode;
        unsigned int preparedFlags;
        float auxRadius;
        AuxInfo info(input, auxNode, preparedFlags);
        info.flags = preparedFlags;
        info.shape = 0;

        if (auxNode)
        {
            Bound* local = auxNode->bound;
            Bound existing = local ? *local : DAT_011f4288;
            auxRadius = existing.radius;
        }
        else
        {
            NodeBounds* n = node;
            if (n)
            {
                bhkCharacterProxy_MarkRead();
                n->hkpCharacterProxy_getPosition();
                bhkCharacterProxy_MarkRead();
            }
            auxRadius = 1;
        }
        if (!(auxRadius > 0))
            auxRadius = 1;
        info.shape = new FUN_00cd8160(auxRadius * DAT_01267bcc);
        aux = new FUN_00c6d1e0(info, this);
    }
}


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

// @fnv 0x00c78610
// src: XBOX_PDB 0x00c78610
bool P064Controller::bhkRagdollController_BoneTrack(int index, const P064Point* point)
{
    P064Aim aim;
    aim.weight = slots[index].weight;
    aim.offset = P064Intrinsics::_mm_setzero_ps();
    aim.target = slots[index].target;
    P064Quad direction = P064InitialRotate(P064Model(slots[index].pose, slots[index].referenceBone)->rotation.value,
                                           slots[index].direction);
    P064Quad directionLength = P064Dot(direction, direction);
    P064Quad directionReciprocal = P064Intrinsics::_mm_rsqrt_ss(directionLength);
    P064Scalar zero(DAT_01011d78);
    P064Scalar three(DAT_01017718);
    P064Scalar half(DAT_01016248);
    P064Quad directionScale = P064Intrinsics::_mm_mul_ss(
        P064Intrinsics::_mm_mul_ss(half.value, directionReciprocal),
        P064Intrinsics::_mm_sub_ss(
            three.value, P064Intrinsics::_mm_mul_ss(P064Intrinsics::_mm_mul_ss(directionLength, directionReciprocal),
                                                    directionReciprocal)));
    directionScale =
        P064Intrinsics::_mm_andnot_ps(P064Intrinsics::_mm_cmpeq_ss(directionLength, zero.value), directionScale);
    aim.direction =
        P064Intrinsics::_mm_mul_ps(P064Intrinsics::_mm_shuffle_ps(directionScale, directionScale, 0), direction);
    P064Point position;
    position.hkVector4_setTransformedInversePos_00c7f840(point, &transformTranslation);
    if (constrained && index == 1)
    {
        const P064Quad* referenceAddress = slots[0].pose->hkaPose_accessBoneLocalSpace(index);
        P064Quad normalTarget = slots[1].target;
        P064Quad reference = *referenceAddress;
        P064Quad normal = P064Normalize(P064Cross(normalTarget, reference), zero.value, three.value, half.value);
        P064Quad projected = P064Normalize(P064Cross(normal, slots[1].target), zero.value, three.value, half.value);
        P064Quad projectedSquared = P064Intrinsics::_mm_mul_ps(projected, projected);
        reference = *slots[0].pose->hkaPose_accessBoneLocalSpace(index);
        P064Quad squaredLength = P064Intrinsics::_mm_add_ss(
            P064Intrinsics::_mm_shuffle_ps(projectedSquared, projectedSquared, 170),
            P064Intrinsics::_mm_add_ss(P064Intrinsics::_mm_shuffle_ps(projectedSquared, projectedSquared, 85),
                                       projectedSquared));
        float rawDistance;
        P064Intrinsics::_mm_store_ss(
            &rawDistance,
            P064Intrinsics::_mm_div_ss(P064Dot(projected, reference), P064Intrinsics::_mm_sqrt_ss(squaredLength)));
        float distance = rawDistance;
        P064Quad delta =
            P064Intrinsics::_mm_sub_ps(position.value, P064Model(slots[1].pose, slots[1].bone)->translation);
        float magnitude;
        P064Intrinsics::_mm_store_ss(&magnitude, P064Intrinsics::_mm_sqrt_ss(P064Dot(delta, delta)));
        P064Quad unit = P064Normalize(delta, zero.value, three.value, half.value);
        if (magnitude < rawDistance)
            position.value = P064Intrinsics::_mm_add_ps(
                position.value, P064Intrinsics::_mm_mul_ps(unit, P064Intrinsics::_mm_set_ps1(distance)));
        aim.offset = *slots[0].pose->hkaPose_accessBoneLocalSpace(1);
    }
    P064Transform saved;
    saved = *P064Local(slots[index].pose, slots[index].bone, &saved);
    P064Quad previousDelta = P064Intrinsics::_mm_and_ps(
        P064Intrinsics::_mm_sub_ps(slots[index].previous.value, *reinterpret_cast<const P064Quad*>(&DAT_01267e30)),
        DAT_01017d10);
    if ((P064Intrinsics::_mm_movemask_ps(
             P064Intrinsics::_mm_cmple_ps(previousDelta, P064Intrinsics::_mm_set_ps1(DAT_01017d00))) &
         7) == 7)
        P064Assign(slots[index].previous.value, saved.rotation.value);
    bool changed = hkaLookAtIkSolver_solve(&aim, &position, 1.0f, slots[index].pose->accessBoneModelSpace(slots[index].bone, 1), 0);
    P064Transform updated;
    updated = *P064Local(slots[index].pose, slots[index].bone, &updated);
    float angle = slots[index].initialized ? bhkRagdollController_LimitBoneRot(index, &updated.rotation) : 0.0f;
    if (!P064Model(slots[index].pose, slots[index].bone)->rotation.IsNormalized())
    {
        int bone = slots[index].bone;
        P064Pose* pose = slots[index].pose;
        int count = pose->skeleton->count;
        pose->flags[bone] |= 4;
        for (int child = bone + 1; child < count; ++child)
        {
            short parent = pose->skeleton->parents[child];
            if (parent != -1 && (pose->flags[parent] & 4))
            {
                P064Local(pose, child, &updated);
                pose->flags[child] |= 4;
                pose->synchronized = false;
            }
        }
        for (int child = bone + 1; child < count; ++child)
        {
            unsigned int& flag = pose->flags[child];
            unsigned int value = flag;
            if (value & 4)
                flag = (value & ~4u) | 2;
        }
        pose->local[bone] = saved;
        pose->flags[bone] = 2;
        pose->synchronized = false;
    }
    slots[index].initialized = true;
    if (enabled && angle < DAT_01267d3c * 0.01745329238474369)
    {
        slots[index].previous.value = DAT_010c71b0;
        if (index != 0 && constrained)
        {
            slots[activeSlot].active = false;
            --activeSlot;
        }
        else
        {
            enabled = false;
            running = false;
        }
    }
    return !changed;
}

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
    hkVector4 firstSlots[2];
    hkVector4 secondSlots[2];
    float baseOffset;
    float height;
    void bhkCharacterController_InitFrontBack();
};

// Keep the stack protection originally induced by the local SIMD storage.
#pragma strict_gs_check(push, on)
// @fnv 0x00c6e820
// src: COMMUNITY 0x00c6e820
void CharacterProbeLocal::bhkCharacterController_InitFrontBack()
{
    if ((flags & 1) == 0)
        return;

    ParticleResult* result = owner ? owner->hkpCharacterProxy_getShapePhantom() : 0;
    float base = baseOffset;
    float offset = height * 0.5 - base;
    float opposite = offset * -1.0;
    if (result->inner->type != 9)
        base = -baseOffset * 0.5;

    hkVector4 vector;
    vector.m_vComponents = _mm_setr_ps(DAT_01011d78, offset, base, DAT_01011d78);
    hkVector4* slots = firstSlots;
    for (int i = 0; i < 2; i++)
    {
        slots[i].setTransformedPos_00c7f640(*reinterpret_cast<const hkTransform*>(&result->unkb0), vector);
        float previous = slots[i].m_f[2];
        slots[i].m_f[2] = elevation + previous;
        vector.m_f[1] = opposite;
    }

    vector.m_vComponents = _mm_setr_ps(opposite, DAT_01011d78, base, DAT_01011d78);
    slots = secondSlots;
    for (int i = 0; i < 2; i++)
    {
        slots[i].setTransformedPos_00c7f640(*reinterpret_cast<const hkTransform*>(&result->unkb0), vector);
        slots[i].m_f[2] = slots[i].m_f[2] + elevation;
        vector.m_f[0] = offset;
    }
}

#pragma strict_gs_check(pop)

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
    void bhkCharacterController_FindSupportPoint(int index, hkVector4* result);
    void bhkCharacterController_CalculatePitchAndRoll();
};
// Keep the stack protection originally induced by the local SIMD storage.
#pragma strict_gs_check(push, on)
// @fnv 0x00c70060
// src: COMMUNITY 0x00c70060
void AimController_c70060::bhkCharacterController_CalculatePitchAndRoll()
{
    hkVector4 position;
    float difference, angle;
    if (((unsigned char)(field_414 >> 18) & 1) || !(field_530 > 0.0f))
        return;
    if ((field_414 & 1))
    {
        if (((unsigned char)(field_414 >> 25) & 1))
        {
            difference = field_460;
            angle = field_464;
            if (difference == 1.1754943508222875e-38f)
            {
                bhkCharacterController_FindSupportPoint(0, &position);
                difference =
                    P064Intrinsics::_mm_cvtss_f32(P064Intrinsics::_mm_shuffle_ps(reinterpret_cast<const P064Quad&>(position.m_vComponents), reinterpret_cast<const P064Quad&>(position.m_vComponents), 0xaa));
            }
            if (angle == 1.1754943508222875e-38f)
            {
                bhkCharacterController_FindSupportPoint(1, &position);
                angle = P064Intrinsics::_mm_cvtss_f32(P064Intrinsics::_mm_shuffle_ps(reinterpret_cast<const P064Quad&>(position.m_vComponents), reinterpret_cast<const P064Quad&>(position.m_vComponents), 0xaa));
            }
            difference = angle - difference;
            if (difference != 0.0f)
            {
                difference /= field_5f4;
                volatile float roundedAngle = (float)atan(difference);
                angle = roundedAngle;
                if (angle > 0.0f)
                {
                    if (angle > DAT_011b0148 * 0.01745329238474369)
                        angle = (float)(DAT_011b0148 * 0.01745329238474369);
                }
                else
                {
                    if (angle < DAT_011b0148 * -0.01745329238474369)
                        angle = (float)(DAT_011b0148 * -0.01745329238474369);
                }
            }
            else
                angle = 0.0f;
            difference = angle - field_550;
            if (difference != 0.0f)
            {
                if (field_558 > 1.0f)
                    field_558 = 1.0f;
                field_550 += difference * field_558;
            }
        }
        if (((unsigned char)(field_414 >> 26) & 1))
        {
            difference = field_468;
            angle = field_46c;
            if (difference == 1.1754943508222875e-38f)
            {
                bhkCharacterController_FindSupportPoint(2, &position);
                difference =
                    P064Intrinsics::_mm_cvtss_f32(P064Intrinsics::_mm_shuffle_ps(reinterpret_cast<const P064Quad&>(position.m_vComponents), reinterpret_cast<const P064Quad&>(position.m_vComponents), 0xaa));
            }
            if (angle == 1.1754943508222875e-38f)
            {
                bhkCharacterController_FindSupportPoint(3, &position);
                angle = P064Intrinsics::_mm_cvtss_f32(P064Intrinsics::_mm_shuffle_ps(reinterpret_cast<const P064Quad&>(position.m_vComponents), reinterpret_cast<const P064Quad&>(position.m_vComponents), 0xaa));
            }
            difference = angle - difference;
            if (difference != 0.0f)
            {
                difference /= field_5f4;
                volatile float roundedAngle = (float)atan(difference);
                angle = roundedAngle;
                if (angle > 0.0f)
                {
                    if (angle > DAT_011b0148 * 0.01745329238474369)
                        angle = (float)(DAT_011b0148 * 0.01745329238474369);
                }
                else
                {
                    if (angle < DAT_011b0148 * -0.01745329238474369)
                        angle = (float)(DAT_011b0148 * -0.01745329238474369);
                }
            }
            else
                angle = 0.0f;
            difference = angle - field_554;
            if (difference != 0.0f)
            {
                if (field_558 > 1.0f)
                    field_558 = 1.0f;
                field_554 += difference * field_558;
            }
        }
    }
    else
    {
        char* object = field_594 ? field_594->object : 0;
        position.hkVector4_setRotatedInverseDir(*reinterpret_cast<const hkRotation*>(object + 0xb0), *reinterpret_cast<const hkVector4*>(&field_450));
        double ucLimitOffset = DAT_011b0148 * 0.01745329238474369;
        unsigned int flags = field_414;
        P064Quad rotation;
        rotation = P064Intrinsics::_mm_load_ps((const float*)&position);
        float limit = (float)ucLimitOffset;
        if (((unsigned char)(flags >> 26) & 1))
        {
            float angle = AimMax(AimMin((float)(P064Intrinsics::_mm_cvtss_f32(rotation) * -1.0), limit), -limit);
            float difference = angle - field_554;
            if (difference != 0.0f)
            {
                if (field_558 > 1.0f)
                    field_558 = 1.0f;
                field_554 += difference * field_558;
            }
        }
        if (((unsigned char)(flags >> 25) & 1))
        {
            double raw = P064Intrinsics::_mm_cvtss_f32(P064Intrinsics::_mm_shuffle_ps(rotation, rotation, 0x55));
            float angle = AimMax(raw < limit ? (float)raw : limit, -limit);
            float difference = angle - field_550;
            if (difference != 0.0f)
            {
                if (field_558 > 1.0f)
                    field_558 = 1.0f;
                field_550 += difference * field_558;
            }
        }
    }
}

#pragma strict_gs_check(pop)


struct S00c70550_Point3
{
    float x, y, z;
};

void __stdcall SubtractVectors(hkVector4* pOut);
void __cdecl FUN_00458620(S00c70550_Point3* pOut, const hkVector4* pIn);

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

// Keep the stack protection originally induced by the local SIMD storage.
#pragma strict_gs_check(push, on)
// @fnv 0x00c70550
// src: XBOX_PDB 0x00c70550
float FUN_00c70550_cls::bhkCharacterController_GetFallDistance()
{
    float fResult = 0.0f;
    if (m_fOriginZ != 0.0f)
    {
        hkVector4 kPos;
        SubtractVectors(&kPos);
        S00c70550_Point3 kPoint;
        FUN_00458620(&kPoint, &kPos);
        fResult = m_fOriginZ - kPoint.z;
    }
    return fResult;
}

#pragma strict_gs_check(pop)

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

// Preserve stack protection formerly induced by the vector byte-array views.
#pragma strict_gs_check(push, on)
// @fnv 0x00c74570
// src: XBOX_PDB 0x00c74570
void C74570_This::bhkWindListener_Update(float dt)
{
    if (!enabled)
        return;
    if (DAT_01267c14 == 0.0f)
        return;
    C74570_Node* node = &list;
    C74570_Node*& n = node;
    float sign = (float)(1 - (int)(dt / DAT_010c4b20));
    for (; n; n = n->next)
    {
        {
            if (!n->item)
                break;
            C74570_Obj* obj = n->item->obj;
            float a = Eval(DAT_01267c14) + DAT_01267c14 * 0.25;
            if (a < 0.0f)
                a = 0.0f;
            if (a > DAT_011b02dc)
                a = DAT_011b02dc;
            a *= sign;
            float b = Eval(DAT_01064f60);
            b = DAT_01267c18 + b;
            if (b > DAT_011b02e0)
                b -= DAT_011b02e0;
            else if (b < 0.0f)
                b += DAT_011b02e0;
            Vec4 v0;
            C74570_Xf xf;
            Vec4 v1;
            v1.m_vComponents = _mm_setr_ps(0.0f, a, 0.0f, 0.0f);
            v0.m_vComponents = _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f);
            C74570_Mat m;
            m.Build(&v0, b);
            xf.Combine(&m, &v1);
            if (obj)
            {
                obj->Update();
                obj->ctrl.Apply(dt, &xf);
            }
        }
    }
}
#pragma strict_gs_check(pop)

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
// @fnv 0x00c757b0
// src: COMMUNITY 0x00c757b0
bool MainClass::bhkRagdollController_GetEyeOffset(void* out)
{
    bool result = false;
    if (m_190)
    {
        P064Vector local;
        local.value = *m_f0->hkaPose_accessBoneLocalSpace(1);
        P064Transform* ptr = P064Model(m_88, m_144);
        local.FUN_00c7f7a0(ptr, &local);
        local.FUN_00c7f7a0(&m_10, &local);
        FUN_00458620(out, &local);
        result = true;
    }
    return result;
}

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
// @fnv 0x00c6c890
// src: XBOX_PDB 0x00c6c890
void SupportListener::bhkCharacterListener_AddSupportHeight2(const SupportVector* corners, const SupportVector& point)
{
    SupportVector delta[4];
    for (unsigned i = 0; i < 4; i++)
    {
        delta[i].Difference(point, corners[i]);
        delta[i](2) = 0.0f;
    }
    unsigned nearIndex = (float(delta[0].SquaredLength()) < float(delta[1].SquaredLength())) ? 0 : 1;
    Blend(nearIndex, point.Component(2));
    nearIndex = (float(delta[2].SquaredLength()) < float(delta[3].SquaredLength())) ? 2 : 3;
    Blend(nearIndex, point.Component(2));
}

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

// @fnv 0x00c6e680
// src: COMMUNITY 0x00c6e680
void S00c6e680_Class::bhkCharacterController_FindSupportPoint(int index, LocalM128* position)
{
    unsigned int pick;
    bool none = false;
    S00c6e680_C6PickData filterInfo;
    filterInfo.collectorPointer = &filterInfo.collector;
    filterInfo.unkA8 = 0;

    *position = *(LocalM128*)((char*)this + ((index + 0x5B) << 4));
    filterInfo.input.from = *position;
    position->m128_f32[2] = position->m128_f32[2] - DAT_0104f2f0;

    filterInfo.unk90 = (*(LocalM128*)&DAT_01267e30);
    filterInfo.input.to = *position;

    bhkCharacterController_GetCollisionFilter(pick);
    filterInfo.input.filterInfo = pick;

    S00c6e680_C6WorldObject* v =
        ((S00c6e680_C6HolderResult*)(*(S00c6e680_Holder**)((char*)this + 8)
                                         ? (*(S00c6e680_Holder**)((char*)this + 8))->hkpCharacterProxy_getShapePhantom()
                                         : 0))
            ->object;

    S00c6e680_C6World* world = v ? v->GetWorld() : 0;
    bool hit = world->Pick(filterInfo);
    if (hit != none && hit)
    {
        float fraction;
        fraction = 1.0f - filterInfo.collector.output.hitFraction;
        position->m128_f32[2] = fraction * DAT_0104f2f0 + position->m128_f32[2];
    }
}

struct VectorData
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float m_10;
    float unk14;
    float unk18;
    float unk1c;
    P064Quad m_20;
};

struct Vec4Sink
{
    void __thiscall setTransformedPos_00c7f640(int arg, P064Quad* value);
};

// @fnv 0x00c6d620
// src: COMMUNITY 0x00c6d620
void __cdecl ExtractStiltCapsuleInfo(VectorData* data, int arg, Vec4Sink* callee)
{
    P064Quad value = data->m_20;
    ((float*)&value)[2] += data->m_10;
    callee->setTransformedPos_00c7f640(arg, &value);
}


class BodyC66
{
  public:
    void MarkForWrite()
    {}
    void unmarkForWrite()
    {}
    void hkpWorld_shiftBroadPhase(const hkVector4& delta, hkVector4& out, int flags);
};

class ControllerBaseC66
{
  public:
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
    virtual BodyC66* GetBody();

    int m_unk04[23];
};

class ControllerC66 : public ControllerBaseC66
{
  public:
    void bhkWorld_SethkOrigin(const hkVector4& position);

    hkVector4 m_v60;
};

// The original vector storage triggered /GS protection for these stack locals.
#pragma strict_gs_check(push, on)
// @fnv 0x00c66c00
// src: COMMUNITY 0x00c66c00
void ControllerC66::bhkWorld_SethkOrigin(const hkVector4& position)
{
    hkVector4 delta;
    delta.setSub4(position, m_v60);
    BodyC66* pkBody = GetBody();
    GetBody()->MarkForWrite();
    hkVector4 moved;
    pkBody->hkpWorld_shiftBroadPhase(delta, moved, 0);
    GetBody()->unmarkForWrite();
    m_v60.add4(moved);
}
#pragma strict_gs_check(pop)

union __declspec(align(16)) VecBoxQ
{
    LocalM128 q;
    __int8 i8[16];
};
using ::_mm_and_ps;
using ::_mm_movemask_ps;
using ::_mm_cmple_ps;
using ::_mm_set_ps1;
using ::_mm_add_ps;
extern const float DAT_01013ea4;

struct ProxyHolder
{
    const char* hkpCharacterProxy_getLinearVelocity();
    void hkpCharacterProxy_setLinearVelocity(const LocalM128* v);
};
struct VecSrc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    LocalM128 vec10;
};

// @fnv 0x00c6ca30
// src: XBOX_PDB 0x00c6ca30
void __stdcall bhkCharacterListener_characterInteractionCallback(ProxyHolder* a, ProxyHolder* b, VecSrc* src)
{
    LocalM128 p = *(const LocalM128*)a->hkpCharacterProxy_getLinearVelocity();
    VecBoxQ db;
    db.q = _mm_and_ps(_mm_sub_ps(p, *(const LocalM128*)&DAT_01267e30), *(const LocalM128*)&DAT_01017d10);
    LocalM128& d = db.q;
    if ((_mm_movemask_ps(_mm_cmple_ps(d, _mm_set_ps1(DAT_01013ea4))) & 7) == 7)
        return;
    LocalM128 zero = _mm_set_ss(DAT_01011d78);
    LocalM128 dir = src->vec10;
    dir.m128_f32[2] = 0.0f;
    p.m128_f32[2] = 0.0f;
    LocalM128 three = _mm_set_ss(DAT_01017718);
    LocalM128 sq = _mm_mul_ps(dir, dir);
    LocalM128 len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    LocalM128 r = _mm_rsqrt_ss(len);
    LocalM128 inv =
        _mm_andnot_ps(_mm_cmpeq_ss(len, zero), _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r),
                                                          _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, r), r))));
    dir = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), dir), p);
    p = _mm_add_ps(*(const LocalM128*)b->hkpCharacterProxy_getLinearVelocity(), dir);
    b->hkpCharacterProxy_setLinearVelocity(&p);
}

struct S00c7fcc0_Out
{
    void* node;
    int unk04;
    int unk08;
    int unk0c;
    P064Quad m10;
    P064Quad m20;
};

struct S00c7fcc0_Spill
{
    int key;
    struct S00c7fcc0_Type* ti;
};

struct S00c7fcc0_Ctx
{
    P064Quad a0;
    P064Quad a1;
    P064Quad a2;
    P064Quad a3;
    P064Quad b0;
    P064Quad b1;
    P064Quad c0;
    P064Quad c1;
    P064Quad c2;
    P064Quad c3;
    P064Quad d;
    P064Quad e0;
    P064Quad e1;
    P064Quad f;
};

extern char DAT_0126832c;
extern char DAT_01267e64;
extern char DAT_012683c8;

struct S00c7fcc0_Flags
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    unsigned int flags;
};

struct S00c7fcc0_Sub
{
    int t00;
    int t04;
    int t08;
    int t0c;
    S00c7fcc0_Flags base;
};

struct S00c7fcc0_Node
{
    void** vtbl;
    int unk04;
    S00c7fcc0_Sub* sub;
    int n0c;
    int n10;
    int n14;
    int n18;
    int n1c;
    P064Quad m20;
    P064Quad m30;
    void* bhkWorldObject_GetShape();
    bool bhkWorldObject_IsAddedToWorld();
};

struct S00c7fcc0_Type
{
    int s00;
    int s04;
    int s08;
    int s0c;
    S00c7fcc0_Node* node;
    int unk14;
    float f18;
};

struct S00c7fcc0_Child;
struct S00c7fcc0_Obj
{
    void** vtbl;
    int q04;
    int q08;
    int q0c;
    int q10;
    int q14;
    int q18;
    S00c7fcc0_Obj* unk1c;
    int o20;
    int o24;
    int o28;
    int o2c;
    int o30;
    int o34;
    int o38;
    int o3c;
    int o40;
    int o44;
    int o48;
    int o4c;
    int o50;
    int o54;
    int o58;
    int o5c;
    int o60;
    int o64;
    float f68;
    S00c7fcc0_Type* FUN_00653290(const FxRTTI* t);
};

struct S00c7fcc0_Child
{
    int c00;
    int c04;
    int c08;
    int c0c;
    int c10;
    int c14;
    int c18;
    int c1c;
    int c20;
    int c24;
    int c28;
    int c2c;
    int c30;
    int c34;
    int c38;
    int c3c;
    int c40;
    int c44;
    int c48;
    int c4c;
    int c50;
    int c54;
    int c58;
    int c5c;
    int c60;
    int c64;
    int c68;
    int c6c;
    int c70;
    int c74;
    int c78;
    int c7c;
    int c80;
    int c84;
    int c88;
    int c8c;
    int c90;
    int c94;
    int c98;
    int c9c;
    S00c7fcc0_Obj** kids;
    unsigned short unkA4;
    unsigned short count;
    bool FUN_00cab3c0(int a, void* p, void* q);
};

void* NiObject_DynamicCast(void* a, void* b);
bool NiObject_IsKindOf(void* a, void* b);
void FUN_0056df80(void* a, void* b);
struct S00c7fcc0_M
{
    void hkRotation_set(void* p);
    void hkTransform_setMul(void* p, void* q);
};

// @fnv 0x00c7fcc0
// src: XBOX_PDB 0x00c7fcc0
bool bhkUtilFunctions_ClosestBody_ClosestBody(S00c7fcc0_Obj* self, int a2, S00c7fcc0_Out* out, bool flag)
{
    S00c7fcc0_Ctx ctx;
    volatile S00c7fcc0_Spill sp;
    sp.key = a2;
    bool result = false;
    S00c7fcc0_Obj* me = self;
    S00c7fcc0_Child* ch;
    if (me)
    {
        if (me->unk1c)
        {
            S00c7fcc0_Type* t0 = me->unk1c->FUN_00653290(&DAT_012043f8);
            sp.ti = t0;
            if (t0)
            {
                S00c7fcc0_Node* node = t0->node;
                if (node)
                {
                    S00c7fcc0_Flags* b = node->sub ? &node->sub->base : 0;
                    unsigned int v = b ? b->flags : 0;
                    unsigned int k = v & 0x7f;
                    if (k != 8 && k != 0x1d)
                        goto done;
                    unsigned int s = (v >> 8) & 0x1f;
                    bool ok;
                    if (s != 1)
                    {
                        if (s - 2 <= 0xe)
                            ok = true;
                        else
                            goto done;
                    }
                    else
                    {
                        ok = (flag == 0);
                    }
                    if (!ok)
                        goto done;
                    void* a = node->bhkWorldObject_GetShape();
                    if (!a)
                        goto done;
                    S00c7fcc0_Child* edi = (S00c7fcc0_Child*)NiObject_DynamicCast(&DAT_0126832c, a);
                    if (!edi)
                        goto done;
                    (*(void(__thiscall**)(void*, void*))(*(char**)node + 0xf4))(node, &ctx.a0);
                    if (NiObject_IsKindOf(&DAT_01267e64, sp.ti))
                    {
                        if (!node->bhkWorldObject_IsAddedToWorld() || sp.ti->f18 == 1.0f)
                        {
                            FUN_0056df80(&ctx.a0, &me->f68);
                            if (NiObject_IsKindOf(&DAT_012683c8, node))
                            {
                                ctx.c0 = ctx.a0;
                                ctx.c1 = ctx.a1;
                                ctx.c2 = ctx.a2;
                                ctx.c3 = ctx.a3;
                                ((S00c7fcc0_M*)&ctx.d)->hkRotation_set(&node->m20);
                                ctx.f = node->m30;
                                ((S00c7fcc0_M*)&ctx.a0)->hkTransform_setMul(&ctx.c0, &ctx.d);
                            }
                        }
                    }
                    else
                    {
                        (*(void(__thiscall**)(void*, void*))(*(char**)node + 0xf4))(node, &ctx.a0);
                    }
                    if (edi->FUN_00cab3c0(sp.key, &ctx.a0, &ctx.b0))
                    {
                        if (!out->node || ((float*)&out->m20)[3] > ctx.b1.m128_f32[3])
                        {
                            P064Quad t0 = ctx.b0;
                            out->node = node;
                            _ReadWriteBarrier();
                            out->m10 = t0;
                            P064Quad t1 = ctx.b1;
                            out->m20 = t1;
                        }
                    }
                }
            }
        }
    done:
        ch = ((S00c7fcc0_Child * (__thiscall*)(S00c7fcc0_Obj*)) me->vtbl[3])(me);
        if (ch)
        {
            for (unsigned int i = 0; i < ch->count; i++)
            {
                S00c7fcc0_Obj* kid = ch->kids[i];
                result |= bhkUtilFunctions_ClosestBody_ClosestBody(kid, sp.key, out, flag);
            }
        }
    }
    return result;
}
