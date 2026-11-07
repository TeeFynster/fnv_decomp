#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// src/staging/blk_00c60000_od_o2_nood_variant_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00c60000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/staging/blk_00c60000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00c60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00c60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#define FNV_VEC4_SIMD
#include "../../include/Vec4.h"
#include "../../include/NiAVObject.h"
#include "../../include/hkpRigidBody.h"
#include "../../include/hkpCollidable.h"
#include "../../include/SETTING_VALUE.h"
#include "../../include/Setting.h"
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
#include "../../include/Bound.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiStream.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiColorA.h"
#include "../../include/hkpCdBody.h"
#include "../../include/hkpShape.h"
#include "../../include/hkpShapeInfo.h"
#include "../../include/BSDecalPlacementVectorExtraData.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiObject.h"
#include "../../include/hkMatrix4.h"
#include "../../include/hkVector4.h"
// 0x00c62890 is the NiTArray<NiPointer<NiAVObject>, NiTMallocInterface<NiPointer<NiAVObject> > > destructor (RTTI at 0x010c377c).
#include "../../include/NiTArray.h"
#include "../../include/BSPSysSimpleColorModifier.h"
#include "../../include/NiPSysModifier.h"
#include "../../include/NiBinaryExtraData.h"
#include "../../include/NiPSysCylinderEmitter.h"
#include "../../include/NiPSysVolumeEmitter.h"
#include "../../include/NiPSysPositionModifier.h"
#include "../../include/NiPSysData.h"
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
// The unused clone declarations targeted BSPSysSimpleColorModifier (constructor 0x00c60240), not NiObject.
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
inline const NiPoint3& ZeroPoint()
{
    return NiPoint3::ZERO;
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
union CharacterVector
{
    LocalM128 vector;
    signed char bytes[16];
    float& component(int index)
    {
        return reinterpret_cast<float*>(bytes)[index];
    }
    void set(float a, float b, float c, float d)
    {
        vector = _mm_setr_ps(a, b, c, d);
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
struct AimVector_c70060
{
    P064Quad q;
    void hkVector4_setRotatedInverseDir(int, int);
};
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
    void bhkCharacterController_FindSupportPoint(int index, AimVector_c70060* result);
    void bhkCharacterController_CalculatePitchAndRoll();
};
union S00c70550_Vector
{
    __int8 m_i8[16];
    LocalM128 m_vComponents;
    struct
    {
        float x, y, z, w;
    };
};
struct S00c70550_Point3
{
    float x, y, z;
};
void __stdcall SubtractVectors(S00c70550_Vector* pOut);
void __cdecl FUN_00458620(S00c70550_Point3* pOut, const S00c70550_Vector* pIn);
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
union C74570_Vec
{
    LocalM128 q;
    char bytes[16];  // the real xmmintrin __m128 also overlays __int8 m128_i8[16]
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
    C74570_Vec r0;
    C74570_Vec r1;
    C74570_Vec r2;
    void Build(void* out, float angle);
};
struct C74570_Xf
{
    C74570_Vec a;
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
void __cdecl ExtractStiltCapsuleInfo(VectorData* data, int arg, Vec4* callee);

namespace N {
typedef ::__m128 LocalM128;
extern "C"
{
}
}

extern float DAT_012677d8;

// Keep this aggregate for the by-value temporary in FUN_00c68750: VC9 /GS
// emits its original 88-byte body with the cookie. Using hkVector4 (which has
// user-declared constructors) drops the cookie and produces 66 bytes instead.
struct __declspec(align(16)) ScaledVector
{
    N::LocalM128 m_vComponents;

    void set(float x, float y, float z, float w = 0.0f)
    {
        m_vComponents.m128_f32[0] = x;
        m_vComponents.m128_f32[1] = y;
        m_vComponents.m128_f32[2] = z;
        m_vComponents.m128_f32[3] = w;
    }
};

void __stdcall bhkWorld_SethkOrigin(ScaledVector* v);

// @fnv 0x00c68750
// src: XBOX_PDB 0x00c68750
void __stdcall bhkWorld_SetOrigin(const NiPoint3* p)
{
    ScaledVector v;
    v.set(p->x * DAT_012677d8, p->y * DAT_012677d8, p->z * DAT_012677d8);
    bhkWorld_SethkOrigin(&v);
}
