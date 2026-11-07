#include "../../include/hkArrayBase.h"
#include "../../include/NiTArray.h"
#include "../../include/hkArray.h"
// src/staging/blk_00cc0000_o2_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00cc0000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include <math.h>
#include "../../include/NiObject.h"
#include "../../include/NiTMap.h"
#include "../../include/NiTMapItem.h"
// ExtraMember_blk_00cc0000_o2_rtm_variant: local type (was include/ExtraMember.h, which had no evidence of one real class); its methods are 0x0066b0d0 NiPointer<PathingSolution>::operator=
class ExtraMember_blk_00cc0000_o2_rtm_variant
{
public:
    void* vptr;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int count;

    ExtraMember_blk_00cc0000_o2_rtm_variant();
    ExtraMember_blk_00cc0000_o2_rtm_variant(int initial);
    ~ExtraMember_blk_00cc0000_o2_rtm_variant();
    void Reset(int value);
};
// bhkConstraintBaseSI_blk_00cc0000_o2_rtm_variant: local type (was include/bhkConstraintBaseSI.h, which had no evidence of one real class); its methods are 0x00c8a230 hkConstraintCinfo::LoadBinary, 0x00c8a330 hkConstraintCinfo::LoadMotor (no shared hkConstraintCinfo header yet)
class hkRefObjSI;

struct ConstraintDataSI;

class bhkConstraintBaseSI_blk_00cc0000_o2_rtm_variant
{
public:
    void* m_pVtable;
    ConstraintDataSI* m_pData;

    void LoadBinaryBase(NiStream& kStream);
    hkRefObjSI* LoadMotorSI(NiStream& kStream);
};
// bhkLimitedHingeVector_blk_00cc0000_o2_rtm_variant: local type (was include/bhkLimitedHingeVector.h, which had no evidence of one real class); its methods are 0x004b4db0 bhkVector4::operator=
class bhkLimitedHingeVector_blk_00cc0000_o2_rtm_variant
{
public:
    union
    {
        struct
        {
            int unk00;
            int unk04;
            int unk08;
            int unk0C;
        };
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        float value[4];
        unsigned char vecData[16];
    };

    void SetQuaternionComponentsFromVector(const float*);
};
// bhkSaveOwner_blk_00cc0000_o2_rtm_variant: local type (was include/bhkSaveOwner.h, which had no evidence of one real class); its methods are 0x00c9fc00 bhkConvexShape::SaveBinary, 0x00cd02d0 bhkConvexListShape::SaveBinary
#include "../../include/NiStream.h"

class CountedOwner;

class bhkSaveOwner_blk_00cc0000_o2_rtm_variant
{
public:
    unsigned int unk00;
    int unk04;
    CountedOwner* m_pSharedOwner;

    int GetCount();
    void bhkConvexShape_SaveBinary(NiStream* stream);
    void SaveLinkedObjects(NiStream* stream);
};
#define FNV_TRANSFORM_NO_SSE
#include "../../include/Transform.h"
#undef FNV_TRANSFORM_NO_SSE

// src/staging/blk_00cc0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/AutoMemContext.h"
#include "../../include/BSFadeNode.h"
#include "../../include/StrArr.h"
#include "../../include/Vec4.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiTransform.h"
#include "../../include/NiMatrix3.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMemoryAllocator.h"

#include "../../include/hkOstream.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkaSkeleton.h"
#include "../../include/hkpShape.h"
#include "../../include/hkpShapeContainer.h"
#include "../../include/hkpListShape.h"
#include "../../include/hkStreamWriter.h"
#include "../../include/bhkConstraint.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkFixedConstraint.h"
#include "../../include/bhkGenericConstraint.h"
#include "../../include/bhkConvexShape.h"
#include "../../include/bhkConvexSweepShape.h"
#include "../../include/hkMatrix3.h"
#include "../../include/hkVector4.h"
#include "../../include/hkTransform.h"
#include "../../include/bhkListShape.h"
#include "../../include/hkBool.h"
#include "../../include/hkQuaternion.h"
#include "../../include/hkQsTransform.h"
extern "C" void* DAT_010c9314;
extern "C" void __cdecl _delete(void* p, int flags);
void __cdecl FUN_00cc1520();
struct FUN_00cc1710_Class
{
    FUN_00cc1710_Class* __thiscall FUN_00cc1710(int a);
};
struct FUN_00cc1970 : NiExtraData
{
    void LoadBinary(NiStream& stream);
};
struct FUN_00a7b290_shell
{
    bool FUN_00a7b290(NiStream* apStream);
};
struct FUN_00cc1990_class : FUN_00a7b290_shell
{
    bool bhkExtraData_RegisterStreamables(NiStream* apStream);
};
extern "C" void NiFreeAlias(void*);
extern int DAT_010c9490;
struct FUN_00cc1ab0_class
{
    void __thiscall DestroyAndFreeAlias();
};
void __cdecl FUN_00cc1e40();
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00cc1f60_Class
{
    void* __thiscall FUN_00cc1f60(bool flag);
};
void __cdecl FUN_00cc2ac0();
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00cc2b40_class
{
    FUN_00cc2b40_class* __thiscall FUN_00cc2b40(int flag);
};
struct MM
{
    void Deallocate(void*);
};
extern MM g_memoryManager;
extern int DAT_0108ffb4;
struct FUN_009ba5f0_shell
{
    void SetChildObject(int);
};
struct FUN_00cc8920_shell : FUN_009ba5f0_shell
{
    int* m_p;
    FUN_00cc8920_shell* FUN_00cc8920(int a);
};
void __cdecl FUN_00cc8ce0();
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00cc8da0_Class
{
    FUN_00cc8da0_Class* FUN_00cc8da0(bool b);
};
extern "C" void __cdecl _delete(void*, int);
extern "C" void __cdecl FUN_00d54e60();
struct FUN_00ccb160_class
{
    void* __thiscall FUN_00ccb160(int arg);
};
void __cdecl FUN_00ccbc00();
void __cdecl _delete(void*, unsigned int);
struct FUN_00ccc420_class
{
    void* __thiscall FUN_00ccc420(int);
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00ccc720_holder
{
    void FUN_00ccc720();
    void* __thiscall DestroyHolder(int arg);
};
void FUN_00ccd080();
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00ccd150_cls
{
    FUN_00ccd150_cls* __thiscall FUN_00ccd150(int flags);
};
extern "C" void __cdecl _delete(void*, int);
struct FUN_00ccf870_class
{
    int FUN_00ccf740();
    int FUN_00ccf870(int flags);
};
extern float DAT_0104da48;
struct FUN_00cd3290_class
{
    void bhkCharacterPointCollector_reset();
};
struct FUN_00cdea00_cls
{
    void __thiscall hkpRagdollConstraintData_setConeLimitStabilization(char param_2);
};
struct FUN_00cdf250_class
{
    void __thiscall hkMatrix3_setMul(int* a, int b);
    void __thiscall hkpRagdollConstraintData_setTargetRelativeOrientationOfBodies(int a);
};
void __cdecl NiFreeAlias(void* p);
extern MM g_memoryManager;
struct FUN_00cc19e0_class
{
    void* m_kPointA;
    void* m_p;
    void* __thiscall FUN_00cc19e0(bool flag);
};
extern int DAT_0126810c;
extern int DAT_01268238;
extern int DAT_01268208;
extern int DAT_012685a0;
extern int DAT_01030394;
extern int DAT_0103078c;
extern int DAT_010306b4;
extern int DAT_010c4694;
struct FUN_00cc23c0_class
{
    bhkRefObject* __thiscall InitializeRefObject();
};
struct FUN_00cc3d30_class
{
    void* m_p;
    void* m_pUnk0;
    void* m_pUnk1;
    void* m_pData;
    void __thiscall FreeDataIfRequested(bool flag);
};
extern int DAT_0126860c;
struct FUN_00cc66b0 : bhkConstraint
{
    ~FUN_00cc66b0();
};
extern "C" void __cdecl FUN_00d54e60();
extern "C" void __cdecl _delete(void*, int);
extern int DAT_010ca4dc;
extern int DAT_0126866c;
struct FUN_00ccb180_class
{
    int* m_p;
    FUN_00ccb180_class* __thiscall FUN_00ccb180(int flag);
};
void __cdecl IncRefCountAllEntries();
void __cdecl ReleaseAllNodes();
struct H_00c8c810
{
    void __thiscall bhkShape_Link(bool);
};
struct FUN_00ccfe20_class
{
    void __thiscall bhkConvexListShape_Link(bool a);
};
void __fastcall hkpRagdollConstraintData_setMaxFrictionTorque(void* self, int, float v);
void __stdcall SetContactNormal(int a, int b);
void __stdcall hkpRagdollConstraintData_setTwistMotor(int param_1);
void __stdcall SetContactNormal(int a, int b);
void __stdcall hkpRagdollConstraintData_setConeMotor(int param_1);
struct FUN_00cdf290_cls
{
    void __thiscall SetFlagAndClearFloats(int a, char b);
};
struct MyObj
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
};
struct OutS
{
    bhkLimitedHingeVector_blk_00cc0000_o2_rtm_variant m_kPointA;
    bhkLimitedHingeVector_blk_00cc0000_o2_rtm_variant m_kPointB;
    bhkLimitedHingeVector_blk_00cc0000_o2_rtm_variant m_iThirdValue;
};
void __fastcall bhkConvexShape_CopyCinfo(MyObj* self, int, OutS* out);
void __fastcall CopyHingeVectors(MyObj* self, int edx, OutS* out);
extern int _data_011c16bc;
struct FUN_00cce990
{
    void* m_p;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cce990();
    static void* __cdecl operator new(unsigned int size);
};
FUN_00cce990* __stdcall bhkConvexTransformShape_CreateObject();
struct FUN_00ccf060_stub
{
    void __thiscall ReleaseActiveResource();
};
struct FUN_00ccf100_class : H_00c8c810
{
    void* m_pVtable;
    unsigned int m_uiRefCount;
    void* m_pData;
    void bhkConvexTransformShape_Link(bool flag);
};
extern int DAT_0102016c;
extern int DAT_010c5ef4;
extern int DAT_010c955c;
extern int DAT_01268154;
extern int DAT_01268194;
extern int DAT_012685ac;
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};
struct S_00cb79d0_Base
{
    void* m_pVtable;
    unsigned int m_uiField1;
    unsigned int m_uiField2;
    S_00cb79d0_Base();
};
struct DerivedStandin : A51BF0Base, S_00cb79d0_Base
{
    unsigned int m_uiField3;

    DerivedStandin() : S_00cb79d0_Base()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0102016c);
        m_uiField3 = 0;
        DAT_01268154 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c5ef4);
        DAT_01268194 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c955c);
        DAT_012685ac += count;
    }
};
void* CreateDerivedStandin();
struct FUN_00cc4180_Class
{
    void __thiscall FUN_00cc4180();
    void* __thiscall FUN_00cc4200(int flag);
};
struct FUN_00cc47f0_t
{
    void __thiscall FUN_00cc47f0();
    FUN_00cc47f0_t* __thiscall FUN_00cc48e0(int a);
};
extern int DAT_010c99e0;
struct FUN_00cc4990
{
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cc4990();
};
extern int DAT_010c9af0;
struct FUN_00cc51c0
{
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cc51c0();
};
struct FUN_00cc5f10_Class
{
    void __thiscall FUN_00cc5e60();
    FUN_00cc5f10_Class* __thiscall FUN_00cc5f10(unsigned int flag);
};
typedef NiPoint3 NiPoint3_local;
NiPoint3_local& __cdecl HK2NINS(NiPoint3_local& result, hkVector4 const& value);
char* __cdecl NiGetViewerString_00a7d550(char const* name, float value);
extern double const DAT_0102f248;
struct FUN_00cc7090_Constraint
{
    unsigned char m_pad0000[0x20];
    hkVector4 m_twistAxisA;
    hkVector4 m_planeAxisA;
    unsigned char m_pad0040[0x10];
    hkVector4 m_kPivotInA;
    hkVector4 m_twistAxisB;
    hkVector4 m_planeAxisB;
    unsigned char m_pad0080[0x10];
    hkVector4 m_kPivotInB;
    unsigned char m_pad00A0[0x58];
    float m_fMaxFrictionTrq;
    unsigned char m_pad00FC[0x08];
    float m_fTwistMinAngle;
    float m_fTwistMaxAngle;
    unsigned char m_pad010C[0x10];
    float m_fConeMinAngle;
    unsigned char m_pad0120[0x0C];
    float m_fPlaneMinAngle;
    float m_fPlaneMaxAngle;
};
struct FUN_00cc7090_class
{
    void* m_pVtable;
    FUN_00cc7090_Constraint* m_pConstraint;

    void __thiscall hkConstraintCinfo_GetViewerStrings(StrArr* strArr);
    void __thiscall AppendConstraintParams(StrArr* strArr);
};
extern int DAT_010c9d60;
struct FUN_00cc7590
{
    void* m_pVtable;
    int m_iRefCount;
    int m_iData1;
    int m_iData2;
    int m_iData3;
    FUN_00cc7590();
};
extern "C" void __cdecl _delete(void* p, int flags);
extern "C" void __cdecl FUN_00d50020();
struct FUN_00cc7da0_shell
{
    FUN_00cc7da0_shell* FUN_00cc7da0(int flags);
};
extern int DAT_010c9f38;
struct FUN_00cc7f10
{
    int* m_pVTable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cc7f10();
};
struct FUN_00cc94b0_Class
{
    void __thiscall FreeSpawnedStorage();
};
struct FUN_00cc9540_Class : FUN_00cc94b0_Class
{
    FUN_00cc9540_Class* __thiscall FUN_00cc9540(char flag);
};
struct FUN_00cca8d0_shell
{
    void __thiscall FUN_00cca8d0();
};
struct FUN_00cca9a0_class : FUN_00cca8d0_shell
{
    FUN_00cca8d0_shell* __thiscall DestroyOrDelete(int flags);
};
struct FUN_00cca9c0_class
{
    void hkTriangleShapeCinfo_Scale(float scale);
};
bool __fastcall bhkExtendedMeshShapeData_IsEqual(char* p, int, char* q);
struct FUN_00ccd170_cls
{
    void __thiscall UpdateState_00ccd170(float scale);
};
struct NiStreamResolveLinkID
{
    void* __thiscall DeserializeObject();
};
struct NiStreamVirtual
{
    virtual void* m_pVtable00();
    virtual void* m_pVtable04();
    virtual void* m_pVtable08();
    virtual void* m_pVtable0C();
    virtual void* m_pVtable10();
    virtual void* m_pVtable14();
    virtual void* m_pVtable18();
    virtual void* m_pVtable1C();
    virtual void* m_pVtable20();
    virtual void* m_pVtable24();
    virtual void m_pVtable28(void*);
};
struct FUN_00ccf570_class
{
    void __thiscall bhkConvexShape_LoadBinary(NiStream* stream);
    void __thiscall bhkConvexSweepShape_LoadBinary(NiStream* stream);
};
extern "C" void __cdecl _delete(void* p, int flags);
struct FUN_00ccf5b0_shell
{
    void __thiscall FUN_00ccf4f0();
    FUN_00ccf5b0_shell* __thiscall FUN_00ccf5b0(bool flag);
};
extern int DAT_010cb3c4;
struct FUN_00cd44c0_cls
{
    int m_vft;
    unsigned short m_kPointA;
    unsigned short m_kPointB;
    FUN_00cd44c0_cls* SetVirtualTable_00cd44c0();
};
extern int DAT_010cb3f0;
struct FUN_00cd47e0_t
{
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned char m_bFlag;
    unsigned short m_usFlags;
    FUN_00cd47e0_t();
};
struct Matrix
{
    unsigned char m_ucUnknownByte[0x30];
    bool* __thiscall HasFiniteValues(bool* value);
};
struct FUN_00cda090_counter
{
    unsigned char m_ucUnknownByte[0x1C];
    int m_uiItemCount;
};
struct FUN_00cda090_class
{
    FUN_00cda090_counter* m_pCounter;
    Matrix* m_pMatrix1;
    void* m_pUnknown08;
    void* m_pUnknown0C;
    Matrix* m_pMatrix2;
    void* m_pUnknown14;
    void* m_pUnknown18;
    unsigned int* m_pFlags;

    bool* __thiscall FUN_00cda090(bool* result);
};
void __stdcall hkpRagdollConstraintData_setPlaneMotor(int a);
void __fastcall hkpRagdollConstraintData_getTarget(char* self, int, char* apMatrix);
class CC1AD0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CC1AD0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(CC1AD0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};
class CC1AD0Object;
class CC1AD0Stream
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
    virtual void SaveLinkID(CC1AD0Object* pkObject);

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
    CC1AD0BinaryStream* m_pBackingStream;
};
template <class T>
inline void CC1AD0BinaryStreamSave(CC1AD0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void CC1AD0SaveBinary(CC1AD0Stream& kStream, const T& value)
{
    CC1AD0BinaryStreamSave(*kStream.m_pkOstr, &value);
}
class CC1AD0ExtraData
{
  public:
    void SaveBinary(CC1AD0Stream& kStream);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
class CC1AD0ListExtra : public CC1AD0ExtraData
{
  public:
    CC1AD0Object** m_ppkObjects;
    int unk14;
    int unk18;
    unsigned int m_uiCount;

    void bhkExtraData_SaveBinary(CC1AD0Stream& kStream);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct ArrayRefObject
{
    virtual void vf0();
    virtual void DeleteThis();
    long volatile refs;
    void DecRef()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
    void AcquireReference()
    {
        InterlockedIncrement(&refs);
    }
};
struct RefBool
{
    bool value;
    RefBool(bool v) : value(v)
    {}
    operator bool() const
    {
        return value;
    }
};
struct ArrayRefPtr
{
    ArrayRefObject* ptr;
    ArrayRefPtr() : ptr(0)
    {}
    ~ArrayRefPtr()
    {
        if (ptr)
            ptr->DecRef();
    }
    RefBool operator!=(ArrayRefObject* other) const
    {
        return ptr != other;
    }
    ArrayRefPtr& operator=(const ArrayRefPtr& rhs)
    {
        if (ptr != rhs.ptr)
        {
            if (ptr)
                ptr->DecRef();
            ptr = rhs.ptr;
            if (ptr)
                ptr->AcquireReference();
        }
        return *this;
    }
};
void* __cdecl _NiMalloc_00aa1070(unsigned);
void __cdecl _NiFree_00aa10f0(void*);
struct ReferenceArray
{
    void* vtable;
    ArrayRefPtr* data;
    unsigned capacity, used, live;
    void Resize(unsigned);
};
extern int DAT_01268598;
int __cdecl bhkExtraData_GetRTTI();
struct FUN_00cc1e40_tls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) FUN_00cc1e40_tls g_tls_00cc1e40;
struct TlsFlagGuard_00cc1e40
{
    unsigned int m_saved;
    TlsFlagGuard_00cc1e40()
    {
        m_saved = g_tls_00cc1e40.m_2b4;
        g_tls_00cc1e40.m_2b4 = 0x10;
    }
    ~TlsFlagGuard_00cc1e40()
    {
        g_tls_00cc1e40.m_2b4 = m_saved;
    }
};
void __cdecl _NiFree_00aa10f0(void* apMemory);
struct Base_00cc1e40
{
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    ~Base_00cc1e40();
};
struct Member_00cc1e40
{
    virtual void unk00();
    void* m_04;
    void Destroy();
    ~Member_00cc1e40()
    {
        void* p = m_04;
        _NiFree_00aa10f0(p);
    }
};
class FUN_00cc1e40_cls : public Base_00cc1e40
{
  public:
    Member_00cc1e40 m_0c;
    virtual ~FUN_00cc1e40_cls();
};
struct FUN_00cc1d80_object
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    FUN_00cc1d80_object();
    static void* __cdecl operator new(unsigned int bytes);
    void __thiscall AssignFixedString(void* value);
};
extern "C" char DAT_011f49e0;
FUN_00cc1d80_object* __cdecl CreateObjectWithGlobal();
extern __declspec(thread) int g_iCC1F80AllocTag;
struct BCC1F80AllocTagScope
{
    int m_iSaved;

    BCC1F80AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC1F80AllocTag;
        g_iCC1F80AllocTag = aiAllocationTag;
    }
    ~BCC1F80AllocTagScope()
    {
        g_iCC1F80AllocTag = m_iSaved;
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

typedef NiTArray<char*, NiTMallocInterface<char*> > BCC1F80StringArray;
extern const char* g_pcCC1F80Name;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
class CC1F80Node
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void CollectNames(BCC1F80StringArray* pkArray);
};
class CC1F80Group
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC1F80Node** m_ppkChildren;
    int unk14;
    int unk18;
    unsigned int m_uiChildCount;

    void CollectOwnNames(BCC1F80StringArray* pkArray);
    void CollectAllNames(BCC1F80StringArray* pkArray);
};
extern "C" __declspec(thread) unsigned int g_tlsMode;
struct ThreadModeGuard
{
    unsigned int previous;
    ThreadModeGuard() : previous(g_tlsMode)
    {
        g_tlsMode = 16;
    }
    ~ThreadModeGuard()
    {
        g_tlsMode = previous;
    }
};
struct OutputBuffer
{
    void* unk00;
    void* unk04;
    void* unk08;
    struct ListStorage
    {
        void __thiscall Resize(unsigned int count);
    } list;
    void __thiscall AddRefObject(void* value);
};
struct SceneNode
{
    virtual void unknown_slot_00();
    virtual void unknown_slot_04();
    virtual void unknown_slot_08();
    virtual void unknown_slot_0c();
    virtual void unknown_slot_10();
    virtual void unknown_slot_14();
    virtual void unknown_slot_18();
    virtual void unknown_slot_1c();
    virtual void unknown_slot_20();
    virtual void unknown_slot_24();
    virtual void unknown_slot_28();
    virtual void unknown_slot_2c();
    virtual void unknown_slot_30();
    virtual void unknown_slot_34();
    virtual void unknown_slot_38();
    virtual void unknown_slot_3c();
    virtual void unknown_slot_40();
    virtual void unknown_slot_44();
    virtual void* ReadValue(void* context);
};
struct SceneList
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    SceneNode** entries;
    void* unk14;
    void* unk18;
    unsigned int count;
    void __thiscall CopyMembers_00a7b330(OutputBuffer* dest, void* context);
    void __thiscall WriteSceneList(OutputBuffer* dest, void* context);
};
void* Object_DispatchCommandFour(unsigned int size);
struct ThreadHeapState
{
    unsigned char unk000[0x2b4];
    unsigned int m_2b4;
};
extern __declspec(thread) ThreadHeapState g_threadHeapState;
struct TlsHeapGuard
{
    unsigned int saved;
    TlsHeapGuard()
    {
        saved = g_threadHeapState.m_2b4;
        g_threadHeapState.m_2b4 = 0x10;
    }
    ~TlsHeapGuard()
    {
        g_threadHeapState.m_2b4 = saved;
    }
};
class SpawnedThing
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
    static void* operator new(unsigned int size);
    SpawnedThing();
};
class FUN_00cc22a0_cls
{
  public:
    void* CreateAndAttach(unsigned int arg);
    void Attach(SpawnedThing* obj, unsigned int arg);
};
void* SpawnedThing::operator new(unsigned int size)
{
    return Object_DispatchCommandFour(size);
}
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct RefObject24_b9018
{
    char m00[0x18];
    RefObject24_b9018();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
RefObject24_b9018* CreateRefObject24();
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
    int m_2b4;
};
extern __declspec(thread) TlsBlock_t g_tlsBlock;
struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t(int saved)
    {
        m_saved = saved;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};
void bhkSerializable_CloneCritLock();
void bhkSerializable_CloneCritUnlock();
class SpawnedObject_t
{
  public:
    virtual void unk00();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    void* operator new(unsigned int size);
    SpawnedObject_t();
};
struct FUN_00cc2480_cls
{
    int unk00;
    int unk04;
    void bhkWorldObject_CopyMembers(SpawnedObject_t* obj, unsigned int arg);
    SpawnedObject_t* bhkCachingShapePhantom_CreateClone(unsigned int arg);
};
struct ThreadTlsBlock
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) ThreadTlsBlock g_tls;
struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        g_tls.m_2b4 = m_saved;
    }
};
class FUN_00cc2a00_alloc
{
  public:
    unsigned char* Alloc(unsigned int size);
};
extern FUN_00cc2a00_alloc DAT_011f6238;
class FUN_00cc2a00_obj
{
  public:
    void Init();
};
class FUN_00cc2a00_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    FUN_00cc2a00_obj* m_08;
    FUN_00cc2a00_obj* m_0c;

    void Attach(FUN_00cc2a00_obj* obj);
    FUN_00cc2a00_obj* bhkShapePhantom_CreateCInfo(bool* out);
};
extern int DAT_012685b0;
void* __cdecl bhkSpringAction_GetRTTI();
struct Col4
{
    float r, g, b, a;
    Col4& operator*=(float s)
    {
        r *= s;
        g *= s;
        b *= s;
        a *= s;
        return *this;
    }
};
struct S_00cc2d20_result
{
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    Col4 m_kPointA;
    Col4 m_kPointB;
};
struct S_00cc2d20_argument
{
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    float m_f10;
};
struct S_00cc2d20_class
{
    virtual void* v00(char*)
    {
        return 0;
    }
    virtual void* v01(char*)
    {
        return 0;
    }
    virtual void* v02(char*)
    {
        return 0;
    }
    virtual void* v03(char*)
    {
        return 0;
    }
    virtual void* v04(char*)
    {
        return 0;
    }
    virtual void* v05(char*)
    {
        return 0;
    }
    virtual void* v06(char*)
    {
        return 0;
    }
    virtual void* v07(char*)
    {
        return 0;
    }
    virtual void* v08(char*)
    {
        return 0;
    }
    virtual void* v09(char*)
    {
        return 0;
    }
    virtual void* v10(char*)
    {
        return 0;
    }
    virtual void* v11(char*)
    {
        return 0;
    }
    virtual void* v12(char*)
    {
        return 0;
    }
    virtual void* v13(char*)
    {
        return 0;
    }
    virtual void* v14(char*)
    {
        return 0;
    }
    virtual void* v15(char*)
    {
        return 0;
    }
    virtual void* v16(char*)
    {
        return 0;
    }
    virtual void* v17(char*)
    {
        return 0;
    }
    virtual void* v18(char*)
    {
        return 0;
    }
    virtual void* v19(char*)
    {
        return 0;
    }
    virtual void* v20(char*)
    {
        return 0;
    }
    virtual void* v21(char*)
    {
        return 0;
    }
    virtual void* v22(char*)
    {
        return 0;
    }
    virtual void* v23(char*)
    {
        return 0;
    }
    virtual void* v24(char*)
    {
        return 0;
    }
    virtual void* v25(char*)
    {
        return 0;
    }
    virtual void* v26(char*)
    {
        return 0;
    }
    virtual void* v27(char*)
    {
        return 0;
    }
    virtual void* v28(char*)
    {
        return 0;
    }
    virtual void* v29(char*)
    {
        return 0;
    }
    virtual void* v30(char*)
    {
        return 0;
    }
    virtual void* v31(char*)
    {
        return 0;
    }
    virtual void* v32(char*)
    {
        return 0;
    }
    virtual void* v33(char*)
    {
        return 0;
    }
    virtual void* v34(char*)
    {
        return 0;
    }
    virtual void* v35(char*)
    {
        return 0;
    }
    virtual void* v36(char*)
    {
        return 0;
    }
    virtual void* v37(char*)
    {
        return 0;
    }
    virtual void* v38(char*)
    {
        return 0;
    }
    virtual void* v39(char*)
    {
        return 0;
    }
    virtual void* v40(char*)
    {
        return 0;
    }
    virtual void* v41(char*)
    {
        return 0;
    }
    virtual void* v42(char*)
    {
        return 0;
    }
    virtual void* v43(char*)
    {
        return 0;
    }
    virtual void* v44(char*)
    {
        return 0;
    }
    virtual S_00cc2d20_result* v45(char*)
    {
        return 0;
    }

    void __thiscall ClonePhysicsData(void* arg1, void* arg2);
    void __thiscall bhkDashpotAction_CopyMembers(void* arg1, S_00cc2d20_argument* arg2);
};
extern float DAT_01013974;
extern float DAT_0101e2bc;
struct FUN_00cc2f40_cls
{
    volatile unsigned int m_00;
    volatile unsigned int m_04;
    volatile unsigned int m_08;
    unsigned int unk0C;
    volatile float m_10;
    volatile float m_14;
    volatile float m_18;
    volatile float m_1c;
    volatile float m_20;
    volatile float m_24;
    volatile float m_28;
    volatile float m_2c;
    float m_30;
    float m_34;
    float m_38;
    unsigned char m_3c;
    unsigned char m_3d;
    FUN_00cc2f40_cls();
};
typedef unsigned int CC2F90size_t;
struct CC2F90MemoryManager
{
    void* Allocate(unsigned int uiSize);
};
extern CC2F90MemoryManager g_CC2F90MemoryManager;
extern __declspec(thread) int g_CC2F90AllocTag;
struct CC2F90AllocTagScope
{
    int m_iSaved;

    CC2F90AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CC2F90AllocTag;
        g_CC2F90AllocTag = aiAllocationTag;
    }
    ~CC2F90AllocTagScope()
    {
        g_CC2F90AllocTag = m_iSaved;
    }
};
inline void* CC2F90AlignedAlloc(unsigned int uiSize)
{
    char* pcMem = (char*)g_CC2F90MemoryManager.Allocate(uiSize);
    unsigned char ucOffset = (unsigned char)(16 - ((unsigned char)(unsigned int)pcMem & 0xf));
    pcMem += ucOffset;
    pcMem[-1] = ucOffset;
    return pcMem;
}
struct CC2F90Child
{
    CC2F90Child();

    static void* operator new(CC2F90size_t, void* pvMem)
    {
        return pvMem;
    }
};
struct CC2F90Owner
{
    int unk00;
    int unk04;
    void* m_pParentNode;
    CC2F90Child* m_pkChild;

    void CopyParentFieldsToChild(CC2F90Child* pkChild);
    CC2F90Child* bhkSpringAction_CreateCinfo(bool* pbCreated);
};
extern int DAT_012685b8;
struct FUN_00cc3270_base
{
    virtual ~FUN_00cc3270_base();
};
struct FUN_00cc3270 : FUN_00cc3270_base
{
    virtual ~FUN_00cc3270();
};
extern int DAT_012685bc;
void* __cdecl Object_GetGlobalObjectAddress_00cc32e0();
int __cdecl bhkNiTriStripsShape_GetCinfoSize();
void __cdecl FUN_00aa1460(void* p, unsigned int size);
struct S_00cc3300
{
    int unk00, unk04, unk08, unk0c;
    void FUN_00cc3270();
    S_00cc3300* FUN_00cc3300(unsigned int flags);
};
extern float DAT_01267e30;
struct CC3320Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_afPivot[4];
    float m_fMinimum;
    float m_fMaximum;
};
struct CC3320Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bhkLimitedHingeVector_blk_00cc0000_o2_rtm_variant m_kPivot;
    int unk14;
    int unk18;
    int unk1C;
    float m_fMinimum;
    float m_fMaximum;
    bool m_bStreamFlag;
};
class CC3320Base
{
  public:
    void GetInfo(CC3320Info* pkInfo);
};
class CC3320Constraint : public CC3320Base
{
  public:
    int unk00;
    int unk04;
    CC3320Data* m_pUserData;

    static const float* GetPivot(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_afPivot : &DAT_01267e30;
    }
    static float GetMax(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_fMaximum : 0.0f;
    }
    static float GetMin(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_fMinimum : 0.0f;
    }

    void bhkMotorAction_CopyCinfo(CC3320Info* pkInfo);
};
struct FUN_00cc3440_obj
{
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
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned char unk1E4;
    unsigned char m_1e5;
};
struct FUN_00cc3440_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual unsigned int* vGet(FUN_00cc3440_obj** pp);
    void bhkUnaryAction_LoadBinary(FUN_00cc3440_obj* a);
    void SwapEndianFields(FUN_00cc3440_obj* a1);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct PacketReader
{
    void __thiscall bhkUnaryAction_SaveBinary(void* context);
    void __thiscall ReadPacketWithByteSwap(void* context);
};
typedef unsigned int*(__thiscall* GetPacketBlock)(PacketReader*, unsigned char*);
extern int DAT_012685c4;
class FUN_00cc39b0_base
{
  public:
    virtual void unk00();
    ~FUN_00cc39b0_base();
    int unk04;
};
class FUN_00cc39b0 : public FUN_00cc39b0_base
{
  public:
    virtual ~FUN_00cc39b0();
    void unk08();
};
extern int DAT_012685c8;
void* __cdecl bhkDashpotAction_GetRTTI();
extern int DAT_010c970c;
extern int DAT_012685c4;
struct DerivedStandin2 : A51BF0Base, S_00cb79d0_Base
{
    unsigned int m_uiField3;

    DerivedStandin2() : S_00cb79d0_Base()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0102016c);
        m_uiField3 = 0;
        DAT_01268154 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c5ef4);
        DAT_01268194 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c970c);
        DAT_012685c4 += count;
    }
};
void* CreateDerivedStandin2();
struct FUN_00cc3bd0_arg
{
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
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned char unk1E4;
    unsigned char m_1e5;
};
struct FUN_00cc3bd0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(unsigned char* out);
    void bhkBinaryAction_LoadBinary(FUN_00cc3bd0_arg* a);
    void bhkDashpotAction_LoadBinary(FUN_00cc3bd0_arg* a1);
};
struct FUN_00cc3c50_arg
{
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
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned char m_1e4;
};
struct FUN_00cc3c50_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(unsigned char* out);
    void DispatchChainNodes(FUN_00cc3c50_arg* a);
    void bhkDashpotAction_SaveBinary(FUN_00cc3c50_arg* a1);
};
extern int DAT_012685d4;
int* __cdecl bhkAngularDashpotAction_GetRTTI();
struct FUN_00cc4220_source
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
};
struct FUN_00cc4220_output
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
};
struct FUN_00cc4220_class
{
    void* unk00;
    void* unk04;
    FUN_00cc4220_source* m_p;

    void __thiscall WriteScriptTargetInfo(void* p);
    void __thiscall bhkAngularDashpotAction_CopyCinfo(void* p);
};
extern "C" float DAT_012683b0[4];
inline void CC4400Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}
struct CC4400Stream
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
    unsigned char unk1E4;
    unsigned char m_ucPlatform;
};
struct CC4400Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned long m_aulValues0;
    unsigned long m_aulValues1;
    unsigned long m_aulValues2;
    unsigned long m_aulValues3;
    unsigned long m_aulValues4;
    unsigned long m_aulValues5;
};
class CC4400Base
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
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual CC4400Data* GetData(unsigned int* puiSize);

    void Load(CC4400Stream* pkStream);
};
class CC4400Object : public CC4400Base
{
  public:
    void bhkAngularDashpotAction_LoadBinary(CC4400Stream* pkStream);
};
extern int g_012685e0;
int* __cdecl Object_GetGlobalObjectAddress_00cc4860();
extern int g_ctorCountA;
extern int g_ctorCountD;
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
    ChainA_cls()
    {
        m_0c = 0;
        g_ctorCountA += 1;
    }
};
struct SpawnedObject : public ChainA_cls
{
    virtual void unkD2();
    SpawnedObject()
    {
        g_ctorCountD += 1;
    }
};
SpawnedObject* bhkBreakableConstraint_CreateObject();
struct S_00cc4b90_Tls
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
    int ctx;
};
__declspec(thread) S_00cc4b90_Tls DAT_tls;
struct S_00cc4b90_Ctx
{
    int saved;
    __forceinline S_00cc4b90_Ctx(int c)
    {
        saved = DAT_tls.ctx;
        DAT_tls.ctx = c;
    }
    __forceinline ~S_00cc4b90_Ctx()
    {
        DAT_tls.ctx = saved;
    }
};
hkMemoryRouter* hkMemoryRouter_getInstance() throw();
extern float DAT_01017b78;
struct S_00cc4b90_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00cc4b90_RefObj();
    void* operator new(unsigned int n)
    {
        S_00cc4b90_RefObj* b = static_cast<S_00cc4b90_RefObj*>(hkMemoryRouter_getInstance()->heap().blockAlloc(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*)
    {}
};
struct S_00cc4b90_Base : S_00cc4b90_RefObj
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00cc4b90_Base(int a);
};
struct __declspec(novtable) S_00cc4b90_Mid : S_00cc4b90_Base
{
    float f20;
    S_00cc4b90_Mid() : S_00cc4b90_Base(0), f20(DAT_01017b78)
    {}
};
struct S_00cc4b90_Obj : S_00cc4b90_Mid
{
    unsigned char b24;
    unsigned char b25;
    S_00cc4b90_Obj()
    {
        b24 = 0;
        b25 = 0;
    }
};
struct S_00cc4b90_Cls
{
    int unk0;
    S_00cc4b90_Obj* m_p;
    int GetObjSize();
};
struct FUN_00cc4e90_stream;
typedef unsigned int(__cdecl* FUN_00cc4e90_readfn)(FUN_00cc4e90_stream* s, void* dst, unsigned int size,
                                                   unsigned int* outCount, unsigned int count);
struct FUN_00cc4e90_stream
{
    int unk00;
    unsigned int m_04;
    int unk08;
    FUN_00cc4e90_readfn m_0c;
};
struct FUN_00cc4e90_sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_18;
    int unk1C;
    int unk20;
    int unk24;
};
void __cdecl bhkConstraintManager_SaveBinary(int a1, int v);
class FUN_00cc4e90_cls
{
  public:
    int unk00;
    FUN_00cc4e90_sub* m_04;
    void __thiscall hkConstraintCinfo_SaveBinary(int a1);
    void LoadSubData(int a1);
};
extern int DAT_012685e8;
struct SpawnedBase
{
    virtual ~SpawnedBase();
};
struct FUN_00cc5090 : SpawnedBase
{
    virtual ~FUN_00cc5090();
};
extern int g_unk012685ec;
void* __cdecl bhkWheelConstraint_GetRTTI(void);
struct BinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_vContactPosition;
    void* m_pOwnerObject;
    int(__cdecl* m_write)(BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* data, unsigned int count)
    {
        unsigned int actualCount = count;
        m_vContactPosition += m_write(this, data, count, &actualCount, 1);
    }
};
struct StreamContext
{
    BinaryStream* OutputStream()
    {
        return *reinterpret_cast<BinaryStream**>(reinterpret_cast<unsigned char*>(this) + 0x250);
    }
};
struct FUN_00cc5730_class
{
    void* m_ppVirtualMethodTable;
    unsigned char* m_objectData;
    void __thiscall hkConstraintCinfo_SaveBinary(StreamContext* context);
    void __thiscall hkWheelConstraintCinfo_SaveBinary(StreamContext* context);
};
extern int DAT_012685f4;
class FUN_00cc58c0_base
{
  public:
    virtual void unk00();
    ~FUN_00cc58c0_base();
    int unk04;
};
class FUN_00cc58c0 : public FUN_00cc58c0_base
{
  public:
    virtual ~FUN_00cc58c0();
    void unk08();
};
extern int DAT_0108febc;
extern int DAT_010c52bc;
extern int DAT_01268188;
extern int DAT_012685f4;
struct CC5930_Base
{
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiData08;
    CC5930_Base();
    static void* __cdecl operator new(unsigned int size);
};
struct CC5930_Obj : CC5930_Base
{
    unsigned int m_uiData0C;

    CC5930_Obj()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0108febc);
        m_uiData0C = 0;
        DAT_01268188 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c52bc);
        DAT_012685f4 += count;
    }
};
CC5930_Obj* __cdecl CreateCC5930Obj();
struct CC5D40BinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(CC5D40BinaryStream* pkStream, void* pvBuffer, unsigned int uiSize, unsigned int* puiSizes,
                              unsigned int ItemUpdateArray);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};
class CC5D40Stream
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
    CC5D40BinaryStream* m_pUnderlyingStream;
};
template <class T> inline void CC5D40BinaryStreamLoad(CC5D40BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void CC5D40LoadBinary(CC5D40Stream& kStream, T& value)
{
    CC5D40BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}
struct CC5D40Vector4
{
    float x;
    float y;
    float z;
    float w;
};
struct CC5D40Constraint
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    CC5D40Vector4 m_kPivotA;
    CC5D40Vector4 m_kPivotB;
    int unk40;
    float m_fTau;
};
class CC5D40RefObject
{
  public:
    int unk00;
    CC5D40Constraint* m_pkConstraint;

    void LoadBinary(CC5D40Stream& kStream);
};
class CC5D40BallJoint : public CC5D40RefObject
{
  public:
    void hkStiffSpringConstraintCinfo_LoadBinary(CC5D40Stream& kStream);
};
class CC5DD0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CC5DD0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(CC5DD0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};
class CC5DD0Object;
class CC5DD0Stream
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
    virtual void SaveLinkID(CC5DD0Object* pkObject);

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
    CC5DD0BinaryStream* m_pBackingStream;
};
template <class T>
inline void CC5DD0BinaryStreamSave(CC5DD0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void CC5DD0SaveBinary(CC5DD0Stream& kStream, const T& value)
{
    CC5DD0BinaryStreamSave(*kStream.m_pkOstr, &value);
}
struct CC5DD0Vector4
{
    float x;
    float y;
    float z;
    float w;
};
struct CC5DD0Constraint
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    CC5DD0Vector4 m_kPivotA;
    CC5DD0Vector4 m_kPivotB;
    int unk40;
    float m_fTau;
};
class CC5DD0RefObject
{
  public:
    int unk00;
    CC5DD0Constraint* m_pkConstraint;

    void SaveBinary(CC5DD0Stream& kStream);
};
class CC5DD0BallJoint : public CC5DD0RefObject
{
  public:
    void hkStiffSpringConstraintCinfo_SaveBinary(CC5DD0Stream& kStream);
};
extern int DAT_01268600;
struct FUN_00cc5e60 : bhkConstraint
{
    ~FUN_00cc5e60();
};
extern int DAT_01268604;
int* __cdecl Runtime_GetDAT01268604Address();
struct FUN_00cc5ee0_interface
{
    virtual void __thiscall FUN_00cc5ee0_call(int value) = 0;
};
struct FUN_00cc5ee0_class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;

    void __thiscall ClearInterface(char param_2);
};
extern int DAT_01268618;
class FUN_00cc7450_base
{
  public:
    virtual void unk00();
    ~FUN_00cc7450_base();
    int unk04;
};
class FUN_00cc7450 : public FUN_00cc7450_base
{
  public:
    virtual ~FUN_00cc7450();
    void unk08();
};
extern int DAT_0126861c;
void* __cdecl bhkPrismaticConstraint_GetRTTI();
// FUN_00cc74d0 : a one-line function - getter
extern int g_target_00cc74d0;
void* _GetCInfoSize_20();
// FUN_00cc75b0: thiscall, one stack arg (int a1).
class FUN_00cc75b0_F
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
    float m_b4;
};
class FUN_00cc75b0_C
{
  public:
    FUN_00cc75b0_F* m_00;
};
class FUN_00cc75b0_B
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00cc75b0_F* m_08;
    FUN_00cc75b0_F* m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned char unk1c;
    unsigned char m_1d;
};
class FUN_00cc75b0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00cc75b0_B* m_08;
    FUN_00cc75b0_C* m_0c;
    void Call(int a1);
    void bhkPrismaticConstraint_Init(int a1);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct NiBinaryStreamSI
{
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamSI* pThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, 0, 0);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
template <class T> inline void NiStreamLoadBinarySI(NiBinaryStreamSI& kBinStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.BinaryRead(&value, uiSize, &uiSize, 1);
}
struct hkVector4SI
{
    float x;
    float y;
    float z;
    float w;
};

#include "../../include/hkRotation.h"

struct hkTransformSI
{
    hkRotation m_rotation;
    hkVector4SI m_vTranslation;
};
void __cdecl SwapRotHelper(hkTransformSI* pkTransform);
inline void Swap32SI(void* p)
{
    *(unsigned int*)p = _byteswap_ulong(*(unsigned int*)p);
}
inline void SwapVector4SI(hkVector4SI* v)
{
    Swap32SI(&v->x);
    Swap32SI(&v->y);
    Swap32SI(&v->z);
    Swap32SI(&v->w);
}
inline void SwapTransformSI(hkTransformSI* t)
{
    SwapVector4SI(&t->m_vTranslation);
    SwapRotHelper(t);
}
struct ConstraintDataSI
{
    void* m_pVtable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkTransformSI m_kBodyALocalFrame;
    hkTransformSI m_kBodyBLocalFrame;
    unsigned short unkA0;
    unsigned char m_bMotorEnabled;
    unsigned char unkA3;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    float m_fB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    float m_fC8;
    float m_fCC;
    void SetMotorSI(hkReferencedObject* pMotor);
};
struct FUN_00cc7a40_class : bhkConstraintBaseSI_blk_00cc0000_o2_rtm_variant
{
    void hkPrismaticConstraintCinfo_LoadBinary(NiStream& kStream);
};
extern int DAT_01268624;
class FUN_00cc7d00_base
{
  public:
    virtual void unk00();
    ~FUN_00cc7d00_base();
    int unk04;
};
class FUN_00cc7d00 : public FUN_00cc7d00_base
{
  public:
    virtual ~FUN_00cc7d00();
    void unk08();
};
extern int DAT_01268628;
int* __cdecl bhkFixedConstraint_GetRTTI();
int __cdecl bhkListShape_GetCinfoSize();
struct CpuOpaque;
extern CpuOpaque DAT_01268f78;
CpuOpaque* __cdecl bhkGenericConstraint_GetRTTI();
extern int DAT_01268188;
extern int DAT_01268f74;
extern int DAT_01268624;
struct S_00cc7dc0_Arg
{
    int unk00;
    int unk04;
};
struct __declspec(novtable) S_00cc7dc0_Root
{
    unsigned int unk04;
    unsigned int unk08;
    int unk0c;
    S_00cc7dc0_Root()
    {
        Initialize();
        unk0c = 0;
    }
    virtual ~S_00cc7dc0_Root();
    void Initialize();
};
struct S_00cc7dc0_A : S_00cc7dc0_Root
{
    S_00cc7dc0_A()
    {
        DAT_01268188++;
    }
    virtual ~S_00cc7dc0_A();
};
struct S_00cc7dc0_B : S_00cc7dc0_A
{
    S_00cc7dc0_B()
    {
        DAT_01268f74++;
    }
    virtual ~S_00cc7dc0_B();
};
struct S_00cc7dc0_Init
{
    void SpawnAndAttach(S_00cc7dc0_Arg* a);
};
struct FUN_00cc7dc0 : S_00cc7dc0_B
{
    FUN_00cc7dc0(S_00cc7dc0_Arg* a);
    void SpawnAndAttach(S_00cc7dc0_Arg* a);
    virtual ~FUN_00cc7dc0();
};
extern int DAT_01268630;
struct FUN_00cc8480 : bhkConstraint
{
    ~FUN_00cc8480();
};
extern int g_unk01268634;
void* __cdecl bhkHingeLimitsConstraint_GetRTTI();
extern __declspec(thread) int g_iCC8770AllocTag;
struct BCC8770AllocTagScope
{
    int m_iSaved;

    BCC8770AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC8770AllocTag;
        g_iCC8770AllocTag = aiAllocationTag;
    }
    ~BCC8770AllocTagScope()
    {
        g_iCC8770AllocTag = m_iSaved;
    }
};
void __cdecl BCC8770Lock();
void __cdecl BCC8770Unlock();
class BCC8770CloningProcess;
class BCC8770RefObject
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BCC8770RefObject();
    virtual ~BCC8770RefObject();

    int unk04;
    int unk08;
};
class BCC8770Shape : public BCC8770RefObject
{
  public:
    BCC8770Shape() : m_pkShape(0)
    {
        ms_uiInstances++;
    }
    virtual ~BCC8770Shape();

    void* m_pkShape;

    static unsigned int ms_uiInstances;
};
class BCC8770DerivedShape : public BCC8770Shape
{
  public:
    BCC8770DerivedShape()
    {
        ms_uiInstances++;
    }
    virtual ~BCC8770DerivedShape();

    static unsigned int ms_uiInstances;
};
class BCC8770Source
{
  public:
    void CopyMemberData(BCC8770DerivedShape* pkDest, BCC8770CloningProcess& kCloning);
    BCC8770DerivedShape* CloneDerivedShape(BCC8770CloningProcess& kCloning);
};
extern __declspec(thread) int g_tlsMemContext;
struct SerializationMemoryContext
{
    int previous;
    SerializationMemoryContext() : previous(g_tlsMemContext)
    {
        g_tlsMemContext = 16;
    }
    ~SerializationMemoryContext()
    {
        g_tlsMemContext = previous;
    }
};
struct ConstraintSerializationData
{
    hkVector4 unk00;
    hkVector4 unk10;
    hkVector4 unk20;
    hkVector4 planeA;
    hkVector4 axis;
    hkVector4 pivot;
    hkVector4 unk60;
    hkVector4 unk70;
    int unk80;
    float minAngle;
    float maxAngle;
};
struct ConstraintSerializer
{
    void* m_vtbl;
    ConstraintSerializationData* data;
    void SerializeBase(StrArr* strings);
    void SerializeConstraintData(StrArr* strings);
};
extern const char DAT_010c8388[];
extern const char DAT_010c8378[];
extern const char DAT_010c8368[];
extern const char DAT_010c835c[];
extern const char DAT_010c8350[];
inline void AppendConstraintString(StrArr* strings, char* text)
{
    unsigned int index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
    {
        strings->SetSize(index + strings->m_usGrowBy);
    }
    strings->SetAt(index, text);
}
extern int DAT_0126863c;
struct S_cc8ce0_Base
{
    virtual ~S_cc8ce0_Base();
    void bhkSerializable_Kill();
};
struct FUN_00cc8ce0 : S_cc8ce0_Base
{
    ~FUN_00cc8ce0();
};
extern int DAT_01268640;
int* __cdecl bhkBallSocketConstraintChain_GetRTTI();
int __cdecl Object_ComputeValue_00cc8d60();
extern int DAT_01268f84;
int* bhkConstraintChain_GetRTTI();
void __cdecl bhkStream_SaveBinary(NiStream& stream, void* pValue);
struct HavokData_cc8
{
    char pad[0x24];
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
};
struct FUN_00cc8f60_cls
{
    int unk00;
    HavokData_cc8* m_pUserData;
    char pad08[0x18];
    int m_20;

    void hkConstraintChainCinfo_SaveBinary(NiStream& stream);
    void hkBallSocketChainCinfo_SaveBinary(NiStream& stream);
};
extern __declspec(thread) int g_iCC90D0MemContext;
class CC90D0MemContext
{
  public:
    CC90D0MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCC90D0MemContext;
        g_iCC90D0MemContext = aiMemoryContext;
    }
    ~CC90D0MemContext()
    {
        g_iCC90D0MemContext = m_iPrevious;
    }

    int m_iPrevious;
};
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
class CC90D0RefObject
{
  public:
    CC90D0RefObject();
    virtual ~CC90D0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};
class CC90D0Level1 : public CC90D0RefObject
{
  public:
    CC90D0Level1() : m_pPointer(0)
    {
        ++ms_uiInstances;
    }
    virtual ~CC90D0Level1();

    void* m_pPointer;

    static unsigned int ms_uiInstances;
};
class CC90D0Level2 : public CC90D0Level1
{
  public:
    CC90D0Level2()
    {
        ++ms_uiInstances;
    }
    virtual ~CC90D0Level2();

    static unsigned int ms_uiInstances;
};
class CC90D0Level3 : public CC90D0Level2
{
  public:
    CC90D0Level3()
    {
        ++ms_uiInstances;
    }
    virtual ~CC90D0Level3();

    static unsigned int ms_uiInstances;
};
class CC90D0World
{
  public:
    void AddObject(CC90D0Level3* pkObject, void* pvInfo);

    CC90D0Level3* CreateAndAddObject(void* pvInfo);
};
extern int DAT_01268648;
struct FUN_00cc9640 : bhkConstraint
{
    ~FUN_00cc9640();
};
extern int DAT_0108febc;
extern int DAT_010c8b0c;
extern int DAT_01268188;
extern int DAT_01268648;
struct PhysicsAllocator
{
    static void* __cdecl operator new(unsigned int size);
};
struct PhysicsReference
{
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    PhysicsReference();
};
struct PhysicsObject : PhysicsAllocator, PhysicsReference
{
    unsigned int m_uiData;

    PhysicsObject() : PhysicsReference()
    {
        unsigned int count = 1;
        m_pVtable = &DAT_0108febc;
        m_uiData = 0;
        DAT_01268188 += count;
        m_pVtable = &DAT_010c8b0c;
        DAT_01268648 += count;
    }
};
PhysicsObject* __cdecl CreatePhysicsObject();
// MakeClone for a Havok wrapper: under the world lock, create a new wrapper and copy our data into it.
extern __declspec(thread) int g_iCC9940AllocTag;
struct CC9940AllocTagScope
{
    int m_iSaved;

    CC9940AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC9940AllocTag;
        g_iCC9940AllocTag = aiAllocationTag;
    }
    ~CC9940AllocTagScope()
    {
        g_iCC9940AllocTag = m_iSaved;
    }
};
void __cdecl CC9940LockWorld();
void __cdecl CC9940UnlockWorld();
extern int g_iCC9940RefObjectCount;
extern int g_iCC9940WrapperCount;
class CC9940Root
{
  public:
    CC9940Root();
    virtual ~CC9940Root();
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};
class CC9940Holder : public CC9940Root
{
  public:
    CC9940Holder() : m_pkHavokObject(0)
    {}
    virtual ~CC9940Holder();
    void* m_pkHavokObject;
};
class CC9940RefObject : public CC9940Holder
{
  public:
    CC9940RefObject()
    {
        ++g_iCC9940RefObjectCount;
    }
    virtual ~CC9940RefObject();
};
class CC9940Wrapper : public CC9940RefObject
{
  public:
    CC9940Wrapper()
    {
        ++g_iCC9940WrapperCount;
    }
    virtual ~CC9940Wrapper();

    void CopyMemberData(CC9940Wrapper* pkDest, int iCloning);
    CC9940Wrapper* bhkBallAndSocketConstraint_Clone(int iCloning);
};
class BCC9B80BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCC9B80BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BCC9B80Stream
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
    BCC9B80BinaryStream* m_pUnderlyingStream;
};
template <class T> inline void BCC9B80BinaryStreamLoad(BCC9B80BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BCC9B80LoadBinary(BCC9B80Stream& kStream, T& value)
{
    BCC9B80BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}
struct BCC9B80Vector4
{
    float x;
    float y;
    float z;
    float w;
};
struct BCC9B80ShapeData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BCC9B80Vector4 m_kMin;
    BCC9B80Vector4 m_kMax;
};
class BCC9B80Base
{
  public:
    void LoadBinary(BCC9B80Stream& kStream);

    int unk00;
    BCC9B80ShapeData* m_pUserData;
};
class FUN_00cc9b80_cls : public BCC9B80Base
{
  public:
    void hkBallAndSocketConstraintCinfo_LoadBinary(BCC9B80Stream& kStream);
};
class CC9C60Base
{
  public:
    virtual ~CC9C60Base();

    void Shutdown();
};
class FUN_00cc9c60 : public CC9C60Base
{
  public:
    virtual ~FUN_00cc9c60();

    static unsigned int ms_uiInstances;
};
struct BaseObject
{
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
    BaseObject(int a, int b);
    virtual ~BaseObject();
};
struct FUN_00cc9d00 : BaseObject
{
    NiRefObject* m_pPointer;
    FUN_00cc9d00(int a, int b, NiRefObject* pkObject);
    virtual ~FUN_00cc9d00();
};
struct CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void Invoke();
};
struct CpuObject
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
    CpuInterface* target;
    void hkpMoppBvTreeShape_getContainer();
};
extern int DAT_01268658;
void* __cdecl bhkMoppBvTreeShape_GetRTTI();
int __cdecl bhkMoppBvTreeShape_GetCinfoSize();
struct S_00cc9df0_Val
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_f;
};
struct S_00cc9df0_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S_00cc9df0_Val* m_kPointA;
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
    S_00cc9df0_Val* m_kPointB;
};
struct S_00cc9df0_Out
{
    int unk00;
    int unk04;
    S_00cc9df0_Val* m_v;
    float m_fValue;
};
struct S_00cc9df0_Cls;
inline S_00cc9df0_Val* GetA(S_00cc9df0_Data* d)
{
    return d ? d->m_kPointA : 0;
}
inline S_00cc9df0_Val* GetB(S_00cc9df0_Data* d)
{
    return d ? d->m_kPointB : 0;
}
struct S_00cc9df0_Cls
{
    int unk00;
    int unk04;
    S_00cc9df0_Data* m_iFourthElementInteger;
    void bhkBvTreeShape_CopyCinfo(S_00cc9df0_Out* out);
    void SetRatioFromValues(S_00cc9df0_Out* out);
};
inline S_00cc9df0_Data* GetD(S_00cc9df0_Cls* c)
{
    return c ? c->m_iFourthElementInteger : 0;
}
// Apply a scale: multiply the Havok shape's radius by the scale, refresh the shape, then the base handles the rest.
struct CC9F10Scale
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScale;
};
struct CC9F10Shape
{
    void Refresh();
};
struct CC9F10HavokData
{
    int unk00;
    int unk04;
    CC9F10Shape* m_pkShape;
    float m_fBoundRadius;
};
class CC9F10Object
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual CC9F10HavokData* GetHavokData(bool* pbOwned);

    void ApplyBaseScale(int iFlags, CC9F10Scale* pkScale);
    void bhkMoppBvTreeShape_CopyMembers(int iFlags, CC9F10Scale* pkScale);
};
struct Owner_Target
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};
class FUN_00cca0e0_cls
{
  public:
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual Owner_Target* v45(unsigned int* p);
    void bhkBvTreeShape_LoadBinary(unsigned int a);
    void bhkMoppBvTreeShape_LoadBinary(unsigned int param);
};
void __cdecl ReadBlobObject(unsigned int a, unsigned int* b);
extern __declspec(thread) int g_iCCA1B0MemContext;
class CCA1B0MemContext
{
  public:
    CCA1B0MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCCA1B0MemContext;
        g_iCCA1B0MemContext = aiMemoryContext;
    }
    ~CCA1B0MemContext()
    {
        g_iCCA1B0MemContext = m_iPrevious;
    }

    int m_iPrevious;
};
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
class CCA1B0RefObject
{
  public:
    CCA1B0RefObject();
    virtual ~CCA1B0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};
class CCA1B0Level1 : public CCA1B0RefObject
{
  public:
    CCA1B0Level1() : m_pkFirst(0), m_pkSecond(0)
    {
        ++ms_uiInstances;
    }
    virtual ~CCA1B0Level1();

    void* m_pkFirst;
    void* m_pkSecond;

    static unsigned int ms_uiInstances;
};
class CCA1B0Level2 : public CCA1B0Level1
{
  public:
    CCA1B0Level2()
    {
        ++ms_uiInstances;
    }
    virtual ~CCA1B0Level2();

    static unsigned int ms_uiInstances;
};
class CCA1B0Level3 : public CCA1B0Level2
{
  public:
    CCA1B0Level3()
    {
        ++ms_uiInstances;
    }
    virtual ~CCA1B0Level3();

    static unsigned int ms_uiInstances;
};
class CCA1B0World
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void AddObject(CCA1B0Level3* pkObject, void* pvInfo);

    CCA1B0Level3* bhkMoppBvTreeShape_CreateClone(void* pvInfo);
};
extern int DAT_01268664;
int __cdecl bhkTriangleShape_GetRTTI();
class CCAA80Object
{
  public:
    CCAA80Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
CCAA80Object* __cdecl CreateCCAA80Object();
extern "C" void _ReadWriteBarrier(void);
struct FUN_00ccab60_arg
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
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
};
struct FUN_00ccab60_rec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    unsigned int m1C;
    unsigned int m20;
    unsigned int m24;
    unsigned int m28;
    unsigned int m2C;
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
};
struct FUN_00ccab60_cls
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual FUN_00ccab60_rec* GetRec(FUN_00ccab60_arg*& a);
    void bhkConvexShape_LoadBinary(FUN_00ccab60_arg* a);
    void ProcessRecord(FUN_00ccab60_arg* a1);
};
struct FUN_00ccabf0_Param
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned char unk01e4;
};
struct FUN_00ccabf0_Data
{
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0c;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
    volatile unsigned int unk18;
    volatile unsigned int unk1c;
    volatile unsigned int unk20;
    volatile unsigned int unk24;
    volatile unsigned int unk28;
    volatile unsigned int unk2c;
    volatile unsigned int unk30;
    volatile unsigned int unk34;
    volatile unsigned int unk38;
    volatile unsigned int unk3c;
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long value);
struct FUN_00ccabf0_class
{
    virtual void FUN_00ccabf0_00();
    virtual void FUN_00ccabf0_01();
    virtual void FUN_00ccabf0_02();
    virtual void FUN_00ccabf0_03();
    virtual void FUN_00ccabf0_04();
    virtual void FUN_00ccabf0_05();
    virtual void FUN_00ccabf0_06();
    virtual void FUN_00ccabf0_07();
    virtual void FUN_00ccabf0_08();
    virtual void FUN_00ccabf0_09();
    virtual void FUN_00ccabf0_0a();
    virtual void FUN_00ccabf0_0b();
    virtual void FUN_00ccabf0_0c();
    virtual void FUN_00ccabf0_0d();
    virtual void FUN_00ccabf0_0e();
    virtual void FUN_00ccabf0_0f();
    virtual void FUN_00ccabf0_10();
    virtual void FUN_00ccabf0_11();
    virtual void FUN_00ccabf0_12();
    virtual void FUN_00ccabf0_13();
    virtual void FUN_00ccabf0_14();
    virtual void FUN_00ccabf0_15();
    virtual void FUN_00ccabf0_16();
    virtual void FUN_00ccabf0_17();
    virtual void FUN_00ccabf0_18();
    virtual void FUN_00ccabf0_19();
    virtual void FUN_00ccabf0_1a();
    virtual void FUN_00ccabf0_1b();
    virtual void FUN_00ccabf0_1c();
    virtual void FUN_00ccabf0_1d();
    virtual void FUN_00ccabf0_1e();
    virtual void FUN_00ccabf0_1f();
    virtual void FUN_00ccabf0_20();
    virtual void FUN_00ccabf0_21();
    virtual void FUN_00ccabf0_22();
    virtual void FUN_00ccabf0_23();
    virtual void FUN_00ccabf0_24();
    virtual void FUN_00ccabf0_25();
    virtual void FUN_00ccabf0_26();
    virtual void FUN_00ccabf0_27();
    virtual void FUN_00ccabf0_28();
    virtual void FUN_00ccabf0_29();
    virtual void FUN_00ccabf0_2a();
    virtual void FUN_00ccabf0_2b();
    virtual void FUN_00ccabf0_2c();

    virtual FUN_00ccabf0_Data* __thiscall FUN_00ccabf0_45(unsigned char* value);

    void __thiscall bhkConvexShape_SaveBinary(FUN_00ccabf0_Param* param);
    void __thiscall bhkTriangleShape_SaveBinary(FUN_00ccabf0_Param* param);
};
extern __declspec(thread) int g_iCCB080AllocTag;
struct BCCB080AllocTagScope
{
    int m_iSaved;

    BCCB080AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCB080AllocTag;
        g_iCCB080AllocTag = aiAllocationTag;
    }
    ~BCCB080AllocTagScope()
    {
        g_iCCB080AllocTag = m_iSaved;
    }
};
typedef NiTArray<char*, NiTMallocInterface<char*> > BCCB080StringArray;
extern const char* g_pcCCB080Name;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
class FUN_00ccb080_cls
{
  public:
    void bhkConvexShape_GetViewerStrings(BCCB080StringArray* pkArray);
    void AddNameToArray(BCCB080StringArray* pkArray);
};
extern int DAT_01268670;
void* __cdecl bhkPlaneShape_GetRTTI();
int __cdecl _sub_CCB140_GetCinfoSize();
extern int g_unk01268f90;
void* bhkHeightFieldShape_GetRTTI();
extern int DAT_01030bf4;
extern int DAT_010ca5c4;
extern int DAT_010ca4dc;
extern int DAT_012680f8;
extern int DAT_01268f8c;
extern int DAT_0126866c;
struct AllocationBase
{
    static void* __cdecl operator new(unsigned int size);
};
struct S_00c87c30_Base
{
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    S_00c87c30_Base();
};
struct TargetObject : AllocationBase, S_00c87c30_Base
{
    TargetObject() : S_00c87c30_Base()
    {
        m_pVtable = &DAT_01030bf4;
        unsigned int count = 1;
        m_uiData1 = 0;
        m_uiData2 = 0;
        DAT_012680f8 += count;
        m_pVtable = &DAT_010ca5c4;
        DAT_01268f8c += count;
        m_pVtable = &DAT_010ca4dc;
        DAT_0126866c += count;
    }
};
TargetObject* __cdecl CreateTargetObject();
struct FUN_00ccb2b0_Param
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_f10;
};
struct FUN_00ccb2b0_Obj
{
    void** m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3c;
};
class FUN_00ccb2b0_cls
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
    virtual FUN_00ccb2b0_Obj* GetScale(unsigned char* flag);
    void bhkShape_CopyMembers(int a1, FUN_00ccb2b0_Param* p2);
    void bhkPlaneShape_CopyMembers(int a1, FUN_00ccb2b0_Param* p2);
};
inline void CCB350Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}
struct CCB350Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned long m_aulValues[12];
};
class CCB350Stream
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
    char unk1E4;
    char m_cLittleEndian;
};
class CCB350Base
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual CCB350Data* GetData(unsigned int* puiSize);

    void LoadBase(CCB350Stream* pkStream);
};
class CCB350Object : public CCB350Base
{
  public:
    void bhkPlaneShape_LoadBinary(CCB350Stream* pkStream);
};
struct FUN_00ccb3e0_Data
{
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0C;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
    volatile unsigned int unk18;
    volatile unsigned int unk1C;
    volatile unsigned int unk20;
    volatile unsigned int unk24;
    volatile unsigned int unk28;
    volatile unsigned int unk2C;
    volatile unsigned int unk30;
    volatile unsigned int unk34;
    volatile unsigned int unk38;
    volatile unsigned int unk3C;
};
struct FUN_00ccb3e0_Class
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
    virtual void vf20();
    virtual void vf21();
    virtual void bhkPlaneShape_SaveBinary(unsigned char* arg);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual FUN_00ccb3e0_Data* bhkPlaneShape_CreateCinfo(unsigned char* value);
    void __thiscall bhkShape_SaveBinary(unsigned char* arg);
};
typedef unsigned int CCB730size_t;
struct CCB730MemoryManager
{
    void* Allocate(unsigned int uiSize);
};
extern CCB730MemoryManager g_CCB730MemoryManager;
extern __declspec(thread) int g_CCB730AllocTag;
struct CCB730AllocTagScope
{
    int m_iSaved;

    CCB730AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CCB730AllocTag;
        g_CCB730AllocTag = aiAllocationTag;
    }
    ~CCB730AllocTagScope()
    {
        g_CCB730AllocTag = m_iSaved;
    }
};
inline void* CCB730AlignedAlloc(unsigned int uiSize)
{
    char* pcMem = (char*)g_CCB730MemoryManager.Allocate(uiSize);
    unsigned char ucOffset = (unsigned char)(16 - ((unsigned char)(unsigned int)pcMem & 0xf));
    pcMem += ucOffset;
    pcMem[-1] = ucOffset;
    return pcMem;
}
struct CCB730Child
{
    CCB730Child() throw()
        : m_pkOwnerManager(0), m_f10(0.0f), m_f14(0.0f), m_f18(0.0f), m_f1C(0.0f), m_f20(0.0f), m_f24(0.0f),
          m_f28(0.0f), m_f2C(0.0f), m_f30(0.0f), m_f34(0.0f), m_f38(0.0f), m_f3C(0.0f)
    {}

    void* m_pkOwnerManager;
    int unk04;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;

    static void* operator new(CCB730size_t, void* pvMem)
    {
        return pvMem;
    }
};
struct CCB730Owner
{
    int unk00;
    int unk04;
    void* m_pParentNode;
    CCB730Child* m_pkChild;

    void bhkPlaneShape_CopyCinfo(CCB730Child* pkChild);
    CCB730Child* bhkPlaneShape_CreateCinfo(bool* pbCreated);
};
extern int DAT_01268684;
void* __cdecl bhkExtendedMeshShapeData_GetRTTI();
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct FunObjBase_b9645
{
    FunObjBase_b9645();
    virtual void unk00();
    unsigned int m_04;
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};
struct FunObj_b9645 : public FunObjBase_b9645
{
    virtual void unk10();
    unsigned int m_08;
    unsigned int m_0c;
    FunObj_b9645()
    {
        m_08 = 0;
        m_0c = 0;
    }
};
FunObj_b9645* CreateFunObj();
// Decompilation candidate for FUN_00ccba30 (0x00ccba30, 32 bytes).
//
// Shape: a member function that (1) forwards its single argument to a virtual
// slot of an object held at offset 0x14 of itself and (2) hands the same
// argument to its own member helper FUN_00aa0ad0.
struct TargetObj
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v15(NiStream* stream);
};
struct HC1Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    TargetObj* m_pEntryObject;
    bool __thiscall BSPackedAdditionalGeometryData_RegisterStreamables(NiStream* stream);
    void __thiscall bhkExtendedMeshShape_RegisterStreamables(NiStream* stream);
};
struct FUN_00ccba50_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_14;
    char bhkShape_IsEqual(FUN_00ccba50_cls* p);
    char Equals(FUN_00ccba50_cls* p);
};
// GetValueForArg: thiscall, 37 bytes, 1 stack argument.
// Returns 0x24 when the argument is -1, otherwise it asks the object held in
// the member pointer at this+8 for a record and returns that record's +4 field.
struct FUN_00d55530_result
{
    int m_00;
    int m_04;
};
struct FUN_00d55530_cls
{
    FUN_00d55530_result* __thiscall hkpExtendedMeshShape_getMeshMaterial(int arg);
};
struct FUN_00ccba70_cls
{
    int unk00;
    int unk04;
    FUN_00d55530_cls* m_08;
    int GetValueForArg(int arg);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
struct RefObjCC
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> struct NiPtrCC
{
    T* m_pObject;
    NiPtrCC(T* p = 0) : m_pObject(p)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPtrCC();
    NiPtrCC& operator=(T* pObject)
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
};
struct FUN_00ccbaa0
{
    void* m_p0;
    NiPtrCC<RefObjCC> m_sp;
    FUN_00ccbaa0(RefObjCC* p);
};
extern int DAT_0126867c;
int __cdecl bhkExtendedMeshShape_GetRTTI();
int __cdecl bhkPackedNiTriStripsShape_GetCinfoSize();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct FNVRefObj;
struct FNVRefVTable
{
    void(__thiscall* m_method00)(FNVRefObj*);
    void(__thiscall* m_release)(FNVRefObj*);
};
struct FNVRefObj
{
    FNVRefVTable* m_ppVirtualMethodTable;
    volatile long m_refcount;
};
struct FNVHolder
{
    void* m_ppVirtualMethodTable;
    FNVRefObj* m_object;
};
struct FNVParam
{
    FNVRefObj* __thiscall FUN_00a63430();
};
struct FNVTarget
{
    void* m_ppVirtualMethodTable;
    void __thiscall bhkShape_LinkObject(FNVParam*);
    void __thiscall AssignRefObject(FNVParam*);
};
typedef FNVHolder*(__thiscall* FNVQuery)(FNVTarget*, bool*);
struct S_00ccc620_BinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    int unk08;
    unsigned int(__cdecl* m_pfnWrite)(S_00ccc620_BinStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSize, uiNumComponents);
    }
};
struct S_00ccc620_Stream
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
    S_00ccc620_BinStream* unk250;
};
template <class T> inline void WriteBinaryArray(S_00ccc620_BinStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    unsigned int uiBytes = uiNumEls * sizeof(T);
    kStream.Write(pkValue, uiBytes, &uiSize, 1);
}
struct S_00ccc620_Pair
{
    int a;
    int b;
};
struct S_00ccc620_Obj
{
    unsigned int unk00;
    float* unk04;
    unsigned int unk08;
    unsigned short* unk0c;
    S_00ccc620_Pair* unk10;
    void bhkExtendedMeshSubPart_SaveBinary(S_00ccc620_Stream& kStream);
};
class CCCF00BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CCCF00BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(CCCF00BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n)
    {
        unsigned int size = n;
        return BinaryWrite(p, n, &size, 1);
    }
};
class CCCF00Stream
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
    virtual void SaveLinkID(void* pvObject);

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
    CCCF00BinaryStream* m_pBackingStream;
};
struct CCCF00Vector4
{
    float x;
    float y;
    float z;
    float w;
};
struct CCCF00Entity
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
    CCCF00Vector4 m_kValue;
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
    float m_fMass;
};
class CCCF00RigidBody
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
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void Unlock(bool bLocked);
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void Lock(bool& bLocked);

    int unk04;
    CCCF00Entity* m_pkEntity;
    int unk0C;
    int unk10;
    void* m_pvLinked;

    void bhkShape_SaveBinary(CCCF00Stream& kStream);
    void bhkExtendedMeshShape_SaveBinary(CCCF00Stream& kStream);
};
// FUN_00ccd0f0 : a one-line function - getter
extern int g_target_00ccd0f0;
void* Runtime_GetTarget00ccd0f0Address();
extern void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct FUN_00ccd100
{
    void* vtable;
    unsigned int refCount;
    unsigned int flags;
    unsigned int dataA;
    unsigned int dataB;
    FUN_00ccd100();
    static void* __cdecl operator new(unsigned int bytes)
    {
        return Object_DispatchCommandFour(bytes);
    }
};
FUN_00ccd100* __cdecl bhkCylinderShape_CreateObject();
extern "C" void _ReadWriteBarrier(void);
struct S_00ccd330_Arg
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
    unsigned char unk1E4;
    unsigned char m1E5;
};
struct S_00ccd330_Data
{
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
};
struct S_00ccd330_Foo
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual S_00ccd330_Data* FUN_v45(void** value);
    S_00ccd330_Data* m_pData;
    void __thiscall bhkConvexShape_LoadBinary(S_00ccd330_Arg* a1);
    void bhkCapsuleShape_LoadBinary(S_00ccd330_Arg* a1);
};
struct FUN_00ccd3a0_arg
{
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
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned char m_1e4;
};
struct FUN_00ccd3a0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(unsigned char* out);
    void bhkConvexShape_SaveBinary(FUN_00ccd3a0_arg* a);
    void bhkCapsuleShape_SaveBinary(FUN_00ccd3a0_arg* a1);
};
extern int g_012686a0;
int* __cdecl bhkConvexVerticesShape_GetRTTI();
// Constructor of a four-level Havok wrapper class: each level bumps its own live-instance counter.
extern int g_iCDC40LevelACount;
extern int g_iCDC40LevelBCount;
extern int g_iCDC40LevelCCount;
extern int g_iCDC40LevelDCount;
class CDC40Root
{
  public:
    CDC40Root();
    virtual ~CDC40Root();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};
class CDC40Holder : public CDC40Root
{
  public:
    CDC40Holder() : m_pkHavokObject(0), m_uiData(0)
    {}
    virtual ~CDC40Holder();
    void* m_pkHavokObject;
    unsigned int m_uiData;
};
class CDC40LevelA : public CDC40Holder
{
  public:
    CDC40LevelA()
    {
        ++g_iCDC40LevelACount;
    }
    virtual ~CDC40LevelA();
};
class CDC40LevelB : public CDC40LevelA
{
  public:
    CDC40LevelB()
    {
        ++g_iCDC40LevelBCount;
    }
    virtual ~CDC40LevelB();
};
class CDC40LevelC : public CDC40LevelB
{
  public:
    CDC40LevelC()
    {
        ++g_iCDC40LevelCCount;
    }
    virtual ~CDC40LevelC();
};
class FUN_00ccdc40 : public CDC40LevelC
{
  public:
    FUN_00ccdc40();
    virtual ~FUN_00ccdc40();
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct RefObject20_b9084
{
    char m00[0x14];
    RefObject20_b9084();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
RefObject20_b9084* CreateRefObject20();
struct FUN_00ccdd70_arg
{
    unsigned int m_u00;
    unsigned int m_u04;
    unsigned int m_u08;
    unsigned int m_u0C;
    float m_f10;
};
class CdResultObj
{
  public:
    virtual void v00();
    void hkConvexVerticesShapeCinfo_Scale(float value);
};
class FUN_00ccdd70_cls
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
    virtual CdResultObj* GetResult(unsigned char* flag);
    void bhkShape_CopyMembers(int a1, FUN_00ccdd70_arg* a2);
    void ApplyResultValue(int a1, FUN_00ccdd70_arg* a2);
};
struct CCDDE0Stream
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
    unsigned char unk1E4;
    unsigned char m_ucPlatform;
};
struct CCDDE0Vector3
{
    float x;
    float y;
    float z;
};
struct CCDDE0Data
{
    int unk00;
    float m_fScale;
    CCDDE0Vector3 m_kMin;
    CCDDE0Vector3 m_kMax;
};
struct CCDDE0Shape;
extern float DAT_010c72bc;
void CCDDE0SwapVector(CCDDE0Data* pkData, CCDDE0Shape* pkShape, CCDDE0Vector3* pkVector);
void CCDDE0ConvertVector(CCDDE0Stream* pkStream, CCDDE0Vector3* pkVector);
class CCDDE0Base
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
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual CCDDE0Shape* GetShape();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual CCDDE0Data* GetData(unsigned int* puiSize);

    void Load(CCDDE0Stream* pkStream);
};
class CCDDE0Object : public CCDDE0Base
{
  public:
    void bhkConvexVerticesShape_LoadBinary(CCDDE0Stream* pkStream);
};
extern __declspec(thread) int g_iCCE110AllocTag;
struct BCCE110AllocTagScope
{
    int m_iSaved;

    BCCE110AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCE110AllocTag;
        g_iCCE110AllocTag = aiAllocationTag;
    }
    ~BCCE110AllocTagScope()
    {
        g_iCCE110AllocTag = m_iSaved;
    }
};
typedef NiTArray<char*, NiTMallocInterface<char*> > BCCE110StringArray;
extern const char* g_pcCCE110Name;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
class FUN_00cce110_cls
{
  public:
    void bhkConvexShape_GetViewerStrings(BCCE110StringArray* pkArray);
    void AppendNameToArray(BCCE110StringArray* pkArray);
};
extern int DAT_012686b0;
int* __cdecl bhkConvexTransformShape_GetRTTI();
int __cdecl bhkConvexTransformShape_GetCInfoSize();
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);
struct FUN_00cce9e0_cls
{
    int unk00;

    void BaseCleanup();

    FUN_00cce9e0_cls* FUN_00cce9e0(unsigned char acFlags);
};
struct BCCECC0Data
{
    int unk00;
    int unk04;
    void* m_pvUserData;
};
struct BCCECC0Extra
{
    int unk00;
    int unk04;
    void* m_pvUserData;
};
class BCCECC0Node
{
  public:
    BCCECC0Extra* FUN_00a63430();
};
class BCCECC0Wrapper
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual BCCECC0Data* GetData(bool* pbCreated);

    void bhkShape_LinkObject(BCCECC0Node* pkNode);
    void SetUserDataFromNode(BCCECC0Node* pkNode);
};
struct FUN_00cced20_C
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
    virtual void v54(int a);
};
struct FUN_00cced20_B
{
    int unk00;
    int unk04;
    FUN_00cced20_C* m_08;
};
struct FUN_00cced20_A
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00cced20_B* m_18;
};
struct FUN_00cced20_cls
{
    int unk00;
    int unk04;
    FUN_00cced20_A* m_08;

    void BSPackedAdditionalGeometryData_RegisterStreamables(int a);
    void ForwardToNestedVtable(int a1);
};
extern __declspec(thread) int gThreadAllocState;
struct ManagedReference
{
    virtual void unused();
    virtual void destroy();
    volatile long references;
};
struct ResourceRecord
{
    void* unk00;
    void* unk04;
    ManagedReference* resource;
};
struct OwnerRecord
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    ResourceRecord* active;
};
struct ScopedThreadSetting
{
    int prior;
    ScopedThreadSetting() : prior(gThreadAllocState)
    {
        gThreadAllocState = 16;
    }
    ~ScopedThreadSetting()
    {
        gThreadAllocState = prior;
    }
};
struct TaskTls
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
    int context;
};
__declspec(thread) TaskTls g_taskTls;
struct Output403
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
    virtual void Output(StrArr*);
};
struct Link403
{
    int unk00, unk04;
    Output403* target;
};
// 0x00ccf350 reads a child link at 0x18 and a physics transform at 0x20; Data has neither member.
struct PhysicsTransformShapeView
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Link403* link;
    int unk1c;
    hkTransform transform;
};
extern hkTransform DAT_01268370;
extern const char* g_012686b0;
extern const char g_010c6050[], g_010c604c[];
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
void __cdecl HK2NI_00624b10(NiTransform*, const hkTransform*);
void __cdecl FUN_00458620(NiPoint3*, const hkVector4*);
struct Holder403
{
    int unk00, unk04;
    PhysicsTransformShapeView* data;
    void bhkConvexShape_GetViewerStrings(StrArr*);
    const hkTransform& GetTransform() const
    {
        if (this && data)
            return data->transform;
        return DAT_01268370;
    }
    void AppendTransformStrings(StrArr*);
};
extern int DAT_012686b8;
void* __cdecl bhkConvexSweepShape_GetRTTI();
// FUN_00ccf560 - a virtual forwarder.
//
// The object pointer arrives in ECX (a __thiscall member).  The function reads
// the object's vtable pointer and tail-jumps to the virtual that lives at
// vtable offset 0xbc, forwarding its own 4-byte stack argument IN PLACE.
//
// Forwarding the argument in place is what keeps the frame frameless and puts
// the jump target in EAX (a forward with no forwarded argument would use EDX).
//
// The 47 dummy virtuals only place the forwarded virtual at vtable offset 0xbc:
// the first virtual of a class sits at vptr+0, so offset 0xbc is the 48th slot.
extern int DAT_012686c4;
void* __cdecl bhkConvexListShape_GetRTTI();
// FUN_00ccf810: thiscall, 21 bytes, 2 stack args.
// test ecx,ecx / je end / mov ecx,[ecx+8] / test ecx,ecx / je end
// mov eax,[ecx] / mov eax,[eax+0x38] / jmp eax / end: ret 8
// Forwards the two stack arguments to virtual slot 0x38 of the object
// pointed to by the member at this+8.
struct Target
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void Tail(int a, int b);
};
struct FUN_00ccf810_cls
{
    int unk00;
    int unk04;
    Target* volatile m_08;
    void bhkConvexListShape_GetSupportingVertex(int a, int b);
};
struct Link
{
    void* m_type;
    unsigned int m_flags;
    void* m_object;
};
struct RefObject
{
    void** m_ppVirtualMethodTable;
    unsigned int m_flags;
    Link* m_link;
};
struct LinkCollection
{
    unsigned int m_type;
    unsigned int m_flags;
    unsigned int m_pRayCursor;
    unsigned int m_generation;
    Link** m_ppLinks;
    int m_uiItemCount;
};
struct Owner
{
    void** m_ppVirtualMethodTable;
    void __thiscall bhkShape_CopyMembers(void* item, void* key);
    void __thiscall bhkConvexListShape_CopyMembers(void* item, void* key);
};
typedef LinkCollection*(__thiscall* AcquireLinks)(Owner*, unsigned char*);
typedef bool(__thiscall* CheckRef)(RefObject*, void*);
typedef RefObject*(__thiscall* FindRef)(RefObject*, void*);
struct FNVCountInterface
{
    virtual void Reserved();
    virtual unsigned int GetCount();
};
struct FNVNotificationReceiver
{
    virtual void Reserved00();
    virtual void Reserved01();
    virtual void Reserved02();
    virtual void Reserved03();
    virtual void Reserved04();
    virtual void Reserved05();
    virtual void Reserved06();
    virtual void Reserved07();
    virtual void Reserved08();
    virtual void Reserved09();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Notify(int context);
};
struct FNVNotificationEntry
{
    void* m_unknown00;
    void* m_unknown04;
    FNVNotificationReceiver* m_receiver;
};
struct FNVNotificationCollection
{
    unsigned int m_unknown00;
    unsigned int m_unknown04;
    unsigned int m_unknown08;
    unsigned int m_unknown0c;
    unsigned int m_unknown10;
    FNVCountInterface m_countInterface;
    unsigned int m_unknown18;
    unsigned int m_unknown1c;
    unsigned int m_unknown20;
    unsigned int m_unknown24;
    unsigned int m_unknown28;
    unsigned int m_unknown2c;
    unsigned int m_unknown30;
    unsigned int m_unknown34;
    unsigned int m_unknown38;
    unsigned int m_unknown3c;
    unsigned int m_unknown40;
    FNVNotificationEntry** m_entries;
};
struct FNVNotificationOwner
{
    unsigned int m_unknown00;
    unsigned int m_unknown04;
    FNVNotificationCollection* m_pShapeCollection;
    void NotifyAllReceivers(int context);
    void BSPackedAdditionalGeometryData_RegisterStreamables(int context);
};
class CCFA00RefObject
{
  public:
    virtual ~CCFA00RefObject();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
};
struct CCFA00Entry
{
    int unk00;
    int unk04;
    CCFA00RefObject* m_pPointer;
};
class CCFA00List
{
  public:
    virtual void vfunc00();
    virtual int GetSize();
};
struct CCFA00Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    CCFA00List m_kList;
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
    CCFA00Entry** m_ppkEntries;
};
class CCFA00Holder
{
  public:
    int unk00;
    int unk04;
    CCFA00Data* m_pUserData;

    void IncRefCountAllEntries();
};
struct ObjC;
struct SubObj14
{
    virtual void vfn0();
    virtual int vfn1();
};
struct ObjA
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    SubObj14 m_14;
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
    ObjC** m_44;
};
struct ObjD
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
    virtual void v53(int p1, int p2);
};
struct ObjC
{
    unsigned int unk00;
    unsigned int unk04;
    ObjD* m_08;
};
class FUN_00ccfad0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    ObjA* m_08;
    void bhkConvexListShape_BuildDisplayGeometry(int a1, int a2);
};
struct ItemFlags
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int flags;
};
struct ItemEntry
{
    unsigned int unk00;
    unsigned int unk04;
    ItemFlags* details;
};
struct CountProvider
{
    virtual void unused();
    virtual unsigned int LastIndex();
};
struct ItemContainer
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    CountProvider counter;
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
    ItemEntry** entries;
};
struct ItemCollection
{
    unsigned int unk00;
    unsigned int unk04;
    ItemContainer* container;
    unsigned int unk0c;
    unsigned int defaultFlags;
    unsigned int __thiscall GetItemFlags(unsigned int index);
};
struct FNVArray
{
    int* m_data;
    int m_iElementCount;
    unsigned int m_capacityFlags;
    void __thiscall hkArrayBase__spliceInto(void* allocator, int index, int removeCount, const int* source, int insertCount);
};
extern void __cdecl hkArrayUtil__reserve(void* allocator, void* array, int newCapacity, int elementSize);
extern void __cdecl hkMemUtil_memMove(void* dest, const void* src, unsigned int byteCount);
void __stdcall nullsub_36(int a, int b, int c, int d);
int __cdecl Object_ReturnSix();
extern int DAT_010cb344;
struct FUN_00cd3c90_cls
{
    void* m_pVtable;
    unsigned short m_uiValue1;
    unsigned short m_uiUnk;

    void* InitializeFields_00cd3c90();
};
extern float DAT_01013970;
struct SpawnedObjectBase
{
    unsigned short m_unk00;
    unsigned short m_unk02;
    float m_unk04;

    SpawnedObjectBase()
    {
        m_unk04 = DAT_01013970;
        m_unk02 = 1;
    }
};
struct FUN_00cd3f90 : SpawnedObjectBase
{
    virtual void Unk00();

    FUN_00cd3f90();
};
extern char DAT_010cb398[];
struct FUN_00cd4260_cls
{
    void* m_vptr;
    unsigned short unk04;
    unsigned short m_w06;

    FUN_00cd4260_cls* SetVirtualTable_00cd4260();
};
extern int DAT_012686e8;
int* __cdecl bhkCharControllerShape_GetRTTI();
extern float DAT_0101df44;
class FUN_00cd8a10_cls
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
    unsigned char m_60;
    unsigned char unk61;
    unsigned char unk62;
    unsigned char unk63;
    unsigned int m_64;
    float m_68;
    float m_6c;
    float m_70;
    float m_74;
    float m_78;
    float m_7c;
    unsigned int m_80;
    unsigned char m_84;

    FUN_00cd8a10_cls* InitializeDefaults();
};
void __stdcall Runtime_SetOutputByteFlag(unsigned char* flag, int unused);
struct FUN_00cd9ee0_info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_uiItemCount;
};
class FUN_00cd9ee0_cls
{
  public:
    FUN_00cd9ee0_info* m_pObjectInfo;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int* m_pEntryData;
    int unk20;
    int unk24;
    unsigned char m_flag28;
    unsigned char m_flag29;
    void FUN_00cd9ee0();
};
struct FUN_00cd9f10_cls
{
    void** m_ppVirtualMethodTable;
    void* m_pData04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int* m_pArr1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned char m_28;
    unsigned char m_29;
    void FUN_00cd9f10(void** p);
};
void __cdecl hkString_memCpy(void* a, void* b, int c);
class FUN_00cd9f60_cls
{
  public:
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void* m_10;
    unsigned int unk14;
    unsigned int unk18;
    int* m_1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned char m_28;
    unsigned char m_29;
    void FUN_00cd9f60(int* p);
};
void __cdecl AllocateFillBlock(void* dst, int value, unsigned int size);
struct FlagTableOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int m_uiItemCount;
};
class FUN_00cd9fe0_cls
{
  public:
    FlagTableOwner* m_pSharedOwner;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_10;
    unsigned int unk14;
    unsigned int unk18;
    int* m_pFlags;
    unsigned int unk20;
    unsigned int unk24;
    unsigned char m_28;
    unsigned char m_29;

    void* FUN_00cd9fe0();
};
class FUN_00cda010_owner
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int m_iArrayLength;
};
class FUN_00cda010_cls
{
  public:
    FUN_00cda010_owner* m_pSharedOwner;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int* m_pFlags;
    unsigned int unk20;
    unsigned int unk24;
    unsigned char m_bCheck28;
    unsigned char m_bCheck29;
    bool* CheckFlagCombinations(bool* result);
};
struct hkMemoryAllocator;
hkMemoryRouter& __cdecl GetMemoryRouter();
struct HavokArrayUtilities
{
    static void __cdecl GrowArrayCapacity(hkMemoryAllocator& alloc, void* array, int capacity, int elemSize);
};
struct Elem30
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
};
struct SolverInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_iCapacityFlags;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int m_numWords;
};
struct SolverBuffers
{
    SolverInfo* m_info;
    hkArray<Elem30> m_arrayA;
    hkArray<Elem30> m_arrayB;
    hkArray<int> m_arrayC;
    int unk28;
    hkArray<unsigned int> m_bits;

    void InitSingle(int arg);
    void InitMulti(int arg);
    void InitBuffers(int mode, int unused, int arg);
};
struct FUN_00cdb2a0_cls
{
    volatile unsigned int m_i00;
    volatile unsigned int m_i04;
    volatile unsigned int m_i08;
    volatile unsigned int m_i0c;
    volatile unsigned int m_i10;
    volatile unsigned int m_i14;
    volatile unsigned int m_i18;
    volatile unsigned int m_i1c;
    volatile unsigned int m_i20;
    volatile unsigned int m_i24;
    volatile unsigned int m_i28;
    volatile unsigned int m_i2c;
    volatile unsigned int m_i30;
    volatile unsigned int m_i34;

    void InitBuffers(unsigned int a1, unsigned int a2, unsigned int a3);
    FUN_00cdb2a0_cls* hkaPose_hkaPose(unsigned int a1, unsigned int a2, unsigned int a3);
};
struct S_00cdb2f0_Arr
{
    int* data;
    int size;
    unsigned int cap;
    S_00cdb2f0_Arr() : data(0), size(0), cap(0x80000000)
    {}
};
struct FUN_00cdb2f0
{
    int unk00;
    S_00cdb2f0_Arr a04;
    S_00cdb2f0_Arr a10;
    S_00cdb2f0_Arr a1c;
    int unk28;
    S_00cdb2f0_Arr a2c;
    void __thiscall InitBuffers(int arg1, int arg2, int* values);
    FUN_00cdb2f0(int arg1, int arg2, int arg3, int arg4);
};
class FUN_00cdb3d0_cls
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
    int m_28;
    void SetField28(int value);
};
struct CallTarget_00cde880
{
    int ReplaceRange(int, int, int, int, int);
};
struct SearchObject
{
    int ProcessAndReturnValue_00cde920(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
class FUN_00cde940_cls
{
  public:
    void ProcessAndReturnValue_00cde920(int p1, int p2, int p3, int p4);
    void ForwardCall_00cde940(int p1, int p2, int p3);
};
struct FUN_00cdea80_cls
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
    int m_e8;
    int hkpRagdollConstraintData_getConeMotor();
};
class FUN_00cdeaa0_cls
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
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int m_iE4;
    unsigned int hkpRagdollConstraintData_getPlaneMotor();
};
struct FUN_00cdeac0_cls
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
    unsigned char unkA0;
    unsigned char unkA1;
    unsigned char m_bA2;
    unsigned char* __thiscall CopyFieldA2ToOutput_00cdeac0(unsigned char* pOut);
};
class RefObj
{
  public:
    RefObj()
    {
        m_sReferenceCount = 1;
    }
    virtual void v0();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
class RangeBase : public RefObj
{
  public:
    RangeBase()
    {
        m_bEnableState = false;
    }
    virtual void v0();
    struct HkBool
    {
        char m_cBooleanValue;
        HkBool()
        {}
        HkBool(bool b)
        {
            m_cBooleanValue = (char)b;
        }
        HkBool& operator=(bool b)
        {
            m_cBooleanValue = (char)b;
            return *this;
        }
    } m_bEnableState;
};
class FUN_00cdf560 : public RangeBase
{
  public:
    FUN_00cdf560(int iUnused);
    virtual void v0();
    float m_fMinimum;
    float m_fMaximum;
    float m_fFactor;
    float m_fScaleA;
    float m_fExponent;
    float m_fScaleB;
};
struct CDF760FinishFlag
{
    int m_bFinishing;
};
struct CDF760Member
{
    int unk00;
    int unk04;
    void* m_pvOwner;

    void hkpBridgeConstraintAtom_init(void* pvOwner);

    CDF760Member(CDF760FinishFlag flag)
    {
        if (flag.m_bFinishing)
            hkpBridgeConstraintAtom_init(m_pvOwner);
    }
};
class FUN_00cdf760
{
  public:
    int unk04;
    int unk08;
    int unk0C;
    CDF760Member m_kMember;

    FUN_00cdf760(CDF760FinishFlag flag);
    virtual void vfunc00();
};
extern __declspec(thread) int g_iCC2950AllocTag;
struct BCC2950AllocTagScope
{
    int m_iSaved;

    BCC2950AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC2950AllocTag;
        g_iCC2950AllocTag = aiAllocationTag;
    }
    ~BCC2950AllocTagScope()
    {
        g_iCC2950AllocTag = m_iSaved;
    }
};
typedef NiTArray<char*, NiTMallocInterface<char*> > BCC2950StringArray;
extern const char* g_pcCC2950Name;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
class FUN_00cc2950_cls
{
  public:
    void CC2950BaseGetViewerStrings(BCC2950StringArray* pkArray);
    void AddNameToViewerStrings(BCC2950StringArray* pkArray);
};
struct S_arg
{
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
    unsigned char unk1E4;
    unsigned char m_1E5;
};
struct S_res
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
};
class C
{
  public:
    virtual void* v00();
    virtual void* v01();
    virtual void* v02();
    virtual void* v03();
    virtual void* v04();
    virtual void* v05();
    virtual void* v06();
    virtual void* v07();
    virtual void* v08();
    virtual void* v09();
    virtual void* v0A();
    virtual void* v0B();
    virtual void* v0C();
    virtual void* v0D();
    virtual void* v0E();
    virtual void* v0F();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v1A();
    virtual void* v1B();
    virtual void* v1C();
    virtual void* v1D();
    virtual void* v1E();
    virtual void* v1F();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    virtual void* v29();
    virtual void* v2A();
    virtual void* v2B();
    virtual void* v2C();
    virtual S_res* v45(S_arg** out);
    void bhkBinaryAction_LoadBinary(S_arg* arg);
    void ProcessAndByteSwapResult(S_arg* arg);
};
inline void CC2E50Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}
struct CC2E50Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned long m_ul10;
    unsigned long m_ul14;
    unsigned long m_ul18;
    unsigned long m_ul1C;
    unsigned long m_ul20;
    unsigned long m_ul24;
    unsigned long m_ul28;
    unsigned long m_ul2C;
    unsigned long m_ul30;
    unsigned long m_ul34;
    unsigned long m_ul38;
};
__forceinline void CC2E50SwapData(CC2E50Data* pkData)
{
    CC2E50Swap(pkData->m_ul10);
    CC2E50Swap(pkData->m_ul14);
    CC2E50Swap(pkData->m_ul18);
    CC2E50Swap(pkData->m_ul1C);
    CC2E50Swap(pkData->m_ul20);
    CC2E50Swap(pkData->m_ul24);
    CC2E50Swap(pkData->m_ul28);
    CC2E50Swap(pkData->m_ul2C);
    CC2E50Swap(pkData->m_ul30);
    CC2E50Swap(pkData->m_ul34);
    CC2E50Swap(pkData->m_ul38);
}
struct CC2E50Stream
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
    bool m_bLittleEndian;
};
class CC2E50Object
{
  public:
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual CC2E50Data* GetData(char* pcUnused);

    void SaveBase(CC2E50Stream* pkStream);
    void bhkSpringAction_SaveBinary(CC2E50Stream* pkStream);
};
struct CC3840Data
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
    float m_fSpinRate;
    float m_fGain;
};
extern const char* g_pcCC3840Name;
class CC3840Base
{
  public:
    void CollectBaseNames(BCC1F80StringArray* pkArray);
};
class CC3840Node : public CC3840Base
{
  public:
    int unk00;
    int unk04;
    CC3840Data* m_pUserData;

    static float GetSpinRate(CC3840Node* p)
    {
        return (p && p->m_pUserData) ? p->m_pUserData->m_fSpinRate : 0.0f;
    }
    static float GetGain(CC3840Node* p)
    {
        return (p && p->m_pUserData) ? p->m_pUserData->m_fGain : 0.0f;
    }
    void bhkMotorAction_GetViewerStrings(BCC1F80StringArray* pkArray);
};
struct BinaryInput
{
    int unk00;
    unsigned int position;
    unsigned int(__cdecl* reader)(BinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* dst, unsigned int size)
    {
        unsigned int componentSize = size;
        position += reader(this, dst, size, &componentSize, 1);
    }
};
struct LoadStream
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
    BinaryInput* input;
};
struct ConstraintData
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
};
struct ConstraintLoader
{
    int unk00;
    ConstraintData* data;
    void hkConstraintCinfo_LoadBinary(LoadStream*);
    void hkWheelConstraintCinfo_LoadBinary(LoadStream*);
};
// Lazily create the Havok helper object; report the object size.
extern __declspec(thread) int g_iCC5AE0AllocTag;
struct CC5AE0AllocTagScope
{
    int m_iSaved;

    CC5AE0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC5AE0AllocTag;
        g_iCC5AE0AllocTag = aiAllocationTag;
    }
    ~CC5AE0AllocTagScope()
    {
        g_iCC5AE0AllocTag = m_iSaved;
    }
};
struct CC5AE0Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct CC5AE0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC5AE0Allocator* m_pStreamAllocator;

    CC5AE0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" CC5AE0MemoryRouter& __cdecl CC5AE0GetMemoryRouter();
class CC5AE0Helper
{
  public:
    CC5AE0Helper();
    virtual ~CC5AE0Helper();

    static void* operator new(unsigned int nbytes)
    {
        CC5AE0Helper* p = static_cast<CC5AE0Helper*>(CC5AE0GetMemoryRouter().heap().AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        CC5AE0GetMemoryRouter().heap().ReleaseBlock(p, nbytes);
    }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
};
class CC5AE0Owner
{
  public:
    int unk00;
    CC5AE0Helper* m_pkHelper;

    unsigned int EnsureHelperAllocated();
};
struct CC61F0BinaryStream
{
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CC61F0BinaryStream* pThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, 0, 0);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
template <class T> inline void CC61F0LoadBinary(CC61F0BinaryStream& kBinStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.BinaryRead(&value, uiSize, &uiSize, 1);
}
struct CC61F0Stream
{
    void* m_pVtable;
    unsigned int m_uiNifVersion;
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
    unsigned char unk1E4;
    unsigned char m_bLittleEndian;
    unsigned short unk1E6;
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
    CC61F0BinaryStream* m_pUnderlyingStream;
};
struct CC61F0Vector4
{
    float x;
    float y;
    float z;
    float w;
};
struct CC61F0Rotation
{
    CC61F0Vector4 m_kColumn0;
    CC61F0Vector4 m_kColumn1;
    CC61F0Vector4 m_kColumn2;
};
void __cdecl CC61F0SwapRotation(CC61F0Rotation* pkRotation);
struct CC61F0ConstraintData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    CC61F0Rotation m_kRotA;
    CC61F0Rotation m_kRotB;
    int unk80;
    int unk84;
    float m_f88;
    float m_f8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    float m_fA0;
    int unkA4;
    int unkA8;
    int unkAC;
    float m_fB0;
    float m_fB4;
};
struct FUN_00cc61f0_class : bhkConstraintBaseSI_blk_00cc0000_o2_rtm_variant
{
    void hkRagdollLimitsConstraintCinfo_LoadBinary(CC61F0Stream& kStream);
};
struct CC63E0_Stream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_vContactPosition;
    void* m_pOwnerObject;
    unsigned int(__cdecl* m_write)(CC63E0_Stream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* data, unsigned int count)
    {
        unsigned int actualCount = count;
        m_vContactPosition += m_write(this, data, count, &actualCount, 1);
    }
};
struct CC63E0_Context
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
    unsigned char m_1e4;
    unsigned char unk1E5;
    unsigned char unk1E6;
    unsigned char unk1E7;
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
    CC63E0_Stream* m_stream;
};
struct CC63E0_Block
{
    float m00;
    float m04;
    float m08;
    float m0C;
    float m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
};
struct CC63E0_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    CC63E0_Block m_20;
    CC63E0_Block m_50;
    int unk80;
    int unk84;
    int m_88;
    int m_8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int m_A0;
    int unkA4;
    int unkA8;
    int unkAC;
    int m_B0;
    int m_B4;
};
void __cdecl CC63E0_SwapBlock(CC63E0_Block* b);
struct CC63E0_Obj
{
    void* m_ppVirtualMethodTable;
    CC63E0_Data* m_data;
    void SaveBase(CC63E0_Context* ctx);
    void hkRagdollLimitsConstraintCinfo_SaveBinary(CC63E0_Context* ctx);
};
struct __declspec(novtable) ReferenceRoot78
{
    unsigned int unk04;
    unsigned int unk08;
    static void* __cdecl operator new(unsigned int size);
    static void __cdecl operator delete(void*);
    virtual ~ReferenceRoot78();
    void Initialize();
    ReferenceRoot78()
    {
        Initialize();
    }
};
struct ConstraintBase78 : ReferenceRoot78
{
    unsigned int data;
    ConstraintBase78()
    {
        data = 0;
        ++DAT_01268188;
    }
    virtual ~ConstraintBase78();
};
struct Constraint78 : ConstraintBase78
{
    Constraint78()
    {
        ++DAT_0126860c;
    }
    virtual ~Constraint78();
};
Constraint78* __cdecl CreateConstraint();
// Create a counted shape wrapper under the Havok allocation tag and the world lock, then register it with this owner.
extern __declspec(thread) int g_iCC69D0AllocTag;
struct CC69D0AllocTagScope
{
    int m_iSaved;

    CC69D0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC69D0AllocTag;
        g_iCC69D0AllocTag = aiAllocationTag;
    }
    ~CC69D0AllocTagScope()
    {
        g_iCC69D0AllocTag = m_iSaved;
    }
};
void CC69D0Lock();
void CC69D0Unlock();
class CC69D0RefObject
{
  public:
    CC69D0RefObject();
    virtual ~CC69D0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};
class CC69D0Shape : public CC69D0RefObject
{
  public:
    CC69D0Shape() : m_pUserData(0)
    {
        ++ms_iCount;
    }
    virtual ~CC69D0Shape();

    void* m_pUserData;

    static int ms_iCount;
};
class CC69D0ListShape : public CC69D0Shape
{
  public:
    CC69D0ListShape()
    {
        ++ms_iCount;
    }
    virtual ~CC69D0ListShape();

    static int ms_iCount;
};
class CC69D0Owner
{
  public:
    void AddShape(CC69D0Shape* pkShape, int iIndex);
    CC69D0Shape* CreateListShape(int iIndex);
};
extern int DAT_010c8ce4;
struct Child_00cc6ab0
{
    void* m_pVtable;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }

    Child_00cc6ab0() : m_08(1), m_0c(0), m_10(0)
    {
        m_pVtable = &DAT_010c8ce4;
        m_04 = 0;
    }
};
static __forceinline Child_00cc6ab0* Make_00cc6ab0(Child_00cc6ab0* obj)
{
    Child_00cc6ab0* p = (Child_00cc6ab0*)((char*)obj + 4);
    new (obj) Child_00cc6ab0();
    return p;
}
struct Owner_00cc6ab0
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_08;
    Child_00cc6ab0* m_0c;

    void Attach(void* pChild);
    Child_00cc6ab0* bhkRagdollConstraint_CreateCinfo(bool* out);
};
struct CC77E0Allocator
{
    virtual void vfunc00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct CC77E0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC77E0Allocator* m_pStreamAllocator;

    CC77E0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" CC77E0MemoryRouter& __cdecl hkMemoryRouterCC77();
extern __declspec(thread) int g_CC77E0AllocTag;
struct CC77E0AllocTagScope
{
    int m_iSaved;

    CC77E0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CC77E0AllocTag;
        g_CC77E0AllocTag = aiAllocationTag;
    }
    ~CC77E0AllocTagScope()
    {
        g_CC77E0AllocTag = m_iSaved;
    }
};
class CC77E0Child
{
  public:
    CC77E0Child();
    virtual ~CC77E0Child();

    static void* operator new(unsigned int uiSize)
    {
        void* p = hkMemoryRouterCC77().heap().AllocateMemoryBlock(uiSize);
        static_cast<CC77E0Child*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    int unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
    int unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    int unkC8, unkCC;
};
class CC77E0Owner
{
  public:
    int unk00;
    CC77E0Child* m_pkChild;

    int EnsureChildAllocated();
};
template <class T> inline void WriteBinaryArray(NiBinaryStream& kBinStream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.Write(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void SerializeValue(NiStream& kStream, const T& kValue)
{
    WriteBinaryArray(*kStream.m_pkOstr, &kValue, 1);
}
struct SaveMatrix
{
    float m[16];
};
struct SaveData
{
    char pad00[0x20];
    SaveMatrix kFirst;
    SaveMatrix kSecond;
    char pad60[2];
    bool bFlag;
    char padA3[9];
    void* pLinked;
    char padB0[4];
    unsigned int uiB4;
    char padB8[0x10];
    unsigned int uiC8;
    unsigned int uiCC;
};
struct FUN_00cc7bc0_shell
{
    void* m_pVtable;
    SaveData* m_pData;
    void hkConstraintCinfo_SaveBinary(NiStream& kStream);
    void SaveShape(void* pLinked, NiStream& kStream);
    void hkPrismaticConstraintCinfo_SaveBinary(NiStream& kStream);
};
extern __declspec(thread) int g_iCC7F30AllocTag;
struct BCC7F30AllocTagScope
{
    int m_iSaved;

    BCC7F30AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC7F30AllocTag;
        g_iCC7F30AllocTag = aiAllocationTag;
    }
    ~BCC7F30AllocTagScope()
    {
        g_iCC7F30AllocTag = m_iSaved;
    }
};
class BCC7F30Allocator
{
  public:
    virtual void VFunc00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void ReleaseBlock(void* pvMem, int iNumBytes);
};
class BCC7F30Router
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BCC7F30Allocator* m_pkHeap;

    BCC7F30Allocator& heap()
    {
        return *m_pkHeap;
    }
};
BCC7F30Router* BCC7F30GetRouter();
class BCC7F30ReferencedObject
{
  public:
    void* operator new(unsigned int uiNumBytes)
    {
        BCC7F30ReferencedObject* pkObject =
            static_cast<BCC7F30ReferencedObject*>(BCC7F30GetRouter()->heap().AllocateMemoryBlock(uiNumBytes));
        pkObject->m_usMemSizeAndFlags = (unsigned short)uiNumBytes;
        return pkObject;
    }
    void operator delete(void* pvMem)
    {
        BCC7F30ReferencedObject* pkObject = static_cast<BCC7F30ReferencedObject*>(pvMem);
        BCC7F30GetRouter()->heap().ReleaseBlock(pvMem, pkObject->m_usMemSizeAndFlags);
    }

    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class BCC7F30Shape : public BCC7F30ReferencedObject
{
  public:
    BCC7F30Shape();

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
class BCC7F30Wrapper
{
  public:
    void Init(BCC7F30Shape* pkShape, int iArg);
    void InitWithShape(BCC7F30Shape* pkShape, int iArg);
};
class BCC8950BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCC8950BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BCC8950Stream
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
    BCC8950BinaryStream* m_pUnderlyingStream;
};
template <class T> inline void BCC8950BinaryStreamLoad(BCC8950BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BCC8950LoadBinary(BCC8950Stream& kStream, T& value)
{
    BCC8950BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}
struct BCC8950Transform
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
};
struct BCC8950ConstraintData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BCC8950Transform m_kTransformA;
    BCC8950Transform m_kTransformB;
    int unk80;
    float m_fMinAngle;
    float m_fMaxAngle;
};
class BCC8950Base
{
  public:
    void LoadBinary(BCC8950Stream& kStream);
};
class BCC8950Constraint : public BCC8950Base
{
  public:
    void hkHingeLimitsConstraintCinfo_LoadBinary(BCC8950Stream& kStream);

    int unk00;
    BCC8950ConstraintData* m_pUserData;
};
// Lazily create the Havok helper object; report the object size.
extern __declspec(thread) int g_iCC9890AllocTag;
struct CC9890AllocTagScope
{
    int m_iSaved;

    CC9890AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC9890AllocTag;
        g_iCC9890AllocTag = aiAllocationTag;
    }
    ~CC9890AllocTagScope()
    {
        g_iCC9890AllocTag = m_iSaved;
    }
};
struct CC9890Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct CC9890MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC9890Allocator* m_pStreamAllocator;

    CC9890Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" CC9890MemoryRouter& __cdecl CC9890GetMemoryRouter();
class CC9890Helper
{
  public:
    CC9890Helper();
    virtual ~CC9890Helper();

    static void* operator new(unsigned int nbytes)
    {
        CC9890Helper* p = static_cast<CC9890Helper*>(CC9890GetMemoryRouter().heap().AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        CC9890GetMemoryRouter().heap().ReleaseBlock(p, nbytes);
    }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
};
class CC9890Owner
{
  public:
    int unk00;
    CC9890Helper* m_pkHelper;

    unsigned int GetOrCreateHelperSize();
};
struct CcaArg
{
    int unkCur;
    int unkValue;
    int uNewnk;
    int unk00C;
    int uTmpnk;
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
    unsigned char m_b1e4;
};
struct CcaRes
{
    int unk;
    int unk04;
    void* m_08;
    unsigned int m_0c;
};
struct CcaOwner
{
    virtual ~CcaOwner()
    {}
    virtual void vf();
    virtual void vfCur();
    virtual void vfValue();
    virtual void vNewf();
    virtual void vTmpf();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
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
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41(int a);
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual CcaRes* vf45(int& out);
    void bhkBvTreeShape_SaveBinary(CcaArg* a);
};
void __cdecl NiStream_WriteObjectBuffer(CcaArg* a, void* p);
struct FUN_00cca130_cls : CcaOwner
{
    void ProcessArg(CcaArg* a1);
};
__declspec(thread) unsigned int DAT_0126fd98;
struct FUN_00cca450_param_item
{
    void* unk00;
    void* unk04;
    struct FUN_00cca450_hook* unk08;
};
struct FUN_00cca450_hook
{
    void __thiscall FUN_00c905b0();
};
struct FUN_00cca450_class
{
    void __thiscall TailOne(FUN_00cca450_param_item*);
    void __thiscall bhkMoppBvTreeShape_PostInit(FUN_00cca450_param_item*);
};
extern const char* g_01268658;
char* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);
int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
struct MoppCode570
{
    int unk00, unk04, unk08, unk0c;
    hkVector4 offset;
};
struct MoppData570
{
    int unk00, unk04, unk08, unk0c, unk10;
    MoppCode570* code;
};
struct MoppOwner570
{
    int unk00, unk04;
    MoppData570* data;
    void BaseOutput(StrArr*);
    void OutputMoppCodeInfo(StrArr*);
};
typedef unsigned int CCADB0size_t;
struct CCADB0MemoryManager
{
    void* Allocate(unsigned int uiSize);
};
extern CCADB0MemoryManager g_CCADB0MemoryManager;
extern __declspec(thread) int g_CCADB0AllocTag;
struct CCADB0AllocTagScope
{
    int m_iSaved;

    CCADB0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CCADB0AllocTag;
        g_CCADB0AllocTag = aiAllocationTag;
    }
    ~CCADB0AllocTagScope()
    {
        g_CCADB0AllocTag = m_iSaved;
    }
};
extern const float g_fCCADB0DefaultScale;
struct CCADB0Child
{
    CCADB0Child() throw()
        : m_pkOwnerManager(0), m_fScale(g_fCCADB0DefaultScale), m_f10(0.0f), m_f14(0.0f), m_f18(0.0f), m_f1C(0.0f),
          m_f20(0.0f), m_f24(0.0f), m_f28(0.0f), m_f2C(0.0f), m_f30(0.0f), m_f34(0.0f), m_f38(0.0f), m_f3C(0.0f)
    {}

    void* m_pkOwnerManager;
    float m_fScale;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;

    static void* operator new(CCADB0size_t uiSize) throw()
    {
        return g_CCADB0MemoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem)
    {}
};
struct CCADB0Owner
{
    int unk00;
    int unk04;
    void* m_pParentNode;
    CCADB0Child* m_pkChild;

    void CCADB0Attach(CCADB0Child* pkChild);
    CCADB0Child* bhkTriangleShape_CreateCinfo(bool* pbCreated);
};
extern int DAT_012686d0;
extern int DAT_01268678;
extern int DAT_010c44e4;
extern int DAT_010ca744;
struct BccObj : S_00c87c30_Base
{
    unsigned int m_14;
    BccObj() : S_00c87c30_Base()
    {
        m_pVtable = &DAT_01030bf4;
        unsigned int* q = &m_uiData1;
        q[0] = 0;
        q[1] = 0;
        DAT_012680f8 += 1;
        m_pVtable = &DAT_010c44e4;
        DAT_012686d0 += 1;
        m_pVtable = &DAT_010ca744;
        m_14 = 0;
        DAT_01268678 += 1;
    }
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void* p)
    {}
};
struct BccOwner
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
    virtual void v49(BccObj* node, int a1);
    BccObj* CreateBccObj(int a1);
};
// SaveBinary of an element array: the count, then each element saves itself.
class CCC920BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CCC920BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(CCC920BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n, unsigned int uiComponentSize)
    {
        unsigned int size = uiComponentSize;
        return BinaryWrite(p, n, &size, 1);
    }
};
class CCC920Stream
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
    CCC920BinaryStream* m_pBackingStream;
};
template <class T>
inline void CCC920BinaryStreamSave(CCC920BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void CCC920SaveBinary(CCC920Stream& kStream, const T& value)
{
    CCC920BinaryStreamSave(*kStream.m_pkOstr, &value);
}
template <class T> inline void CCC920SaveBinary(CCC920Stream& kStream, const T* pValues, unsigned int ItemUpdateArray)
{
    CCC920BinaryStreamSave(*kStream.m_pkOstr, pValues, ItemUpdateArray);
}
struct CCC920Element
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    void SaveBinary(CCC920Stream& kStream);
};
class CCC920Array
{
  public:
    void* m_pVtbl;
    int unk04;
    unsigned int m_uiCount;
    CCC920Element* m_pkVertexElements;

    void bhkExtendedMeshShapeData_SaveBinary(CCC920Stream& kStream);
};
extern __declspec(thread) int g_iCCDE60MemContext;
class CCDE60MemContext
{
  public:
    CCDE60MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCCDE60MemContext;
        g_iCCDE60MemContext = aiMemoryContext;
    }
    ~CCDE60MemContext()
    {
        g_iCCDE60MemContext = m_iPrevious;
    }

    int m_iPrevious;
};
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
class CCDE60Object
{
  public:
    CCDE60Object();
    virtual ~CCDE60Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
class CCDE60World
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void AddObject(CCDE60Object* pkObject, void* pvInfo);

    CCDE60Object* bhkConvexVerticesShape_CreateClone(void* pvInfo);
};
class AllocatorCCD
{
  public:
    virtual void vfn00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};
struct MemoryCCD
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocatorCCD* m_pHeapAllocator;

    AllocatorCCD& heap()
    {
        return *m_pHeapAllocator;
    }
};
MemoryCCD* __cdecl GetMemoryCCD();
extern __declspec(thread) int g_iAllocTagCCD;
struct AllocTagScopeCCD
{
    int m_iSaved;

    AllocTagScopeCCD(int aiAllocationTag)
    {
        m_iSaved = g_iAllocTagCCD;
        g_iAllocTagCCD = aiAllocationTag;
    }
    ~AllocTagScopeCCD()
    {
        g_iAllocTagCCD = m_iSaved;
    }
};
class ReferencedObjectCCD
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        ReferencedObjectCCD* pkObject =
            static_cast<ReferencedObjectCCD*>(GetMemoryCCD()->heap().AllocateMemoryBlock(uiSize));
        pkObject->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return pkObject;
    }
    static void operator delete(void* pvMem);

    virtual ~ReferencedObjectCCD();

    void removeReference();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
struct ShapeCinfoCCD
{
    int m_iVertices;
    int m_iArrayCapacity;
    int m_iFlags;
};
extern float g_fConvexRadiusCCD;
class ShapeCCD : public ReferencedObjectCCD
{
  public:
    ShapeCCD(const ShapeCinfoCCD& kCinfo, const hkVector4& m_kPoint2, float fRadius);

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
};
struct InfoCCD
{
    int unk00;
    int unk04;
    int m_iVertices;
    int m_iArrayCapacity;
    int unk10;
    hkVector4 m_kHalfExtents;
};
class BodyCCD
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void SetShape(ShapeCCD* pkShape);
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void SetInfo(const InfoCCD* pkInfo);

    void SetShapeFromInfo(const InfoCCD* pkInfo);
};
struct CE340Allocator
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct CE340Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CE340Allocator* m_pStreamAllocator;
    CE340Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
CE340Router* CE340GetRouter() throw();
template <class T> struct CE340Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    CE340Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~CE340Array()
    {
        _clearAndDeallocate(CE340GetRouter()->heap());
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void _clearAndDeallocate(CE340Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReleaseBlock(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void swap(CE340Array& a)
    {
        T* d = m_data;
        m_data = a.m_data;
        a.m_data = d;
        int s = m_iElementCount;
        m_iElementCount = a.m_iElementCount;
        a.m_iElementCount = s;
        int c = m_iCapacityState;
        m_iCapacityState = a.m_iCapacityState;
        a.m_iCapacityState = c;
    }
};
struct CE340Data
{
    int unk00;
    int unk04;
    CE340Array<Vec4> m_arr08;
    CE340Array<Vec4> m_arr14;
};
typedef FUN_00ccd3a0_arg CE340Stream;
void __cdecl bhkStream_SwapHKArray(CE340Data* data, void* ctx, CE340Array<Vec4>* arr);
void __cdecl bhkStream_SaveBinary(CE340Stream* stream, void* value);
struct CE340Obj
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void SetFlag(bool flag);
    virtual void* GetContext();
    virtual void v2B();
    virtual void v2C();
    virtual CE340Data* GetData(bool* flag);
    void SaveBase(CE340Stream* stream);
    void SaveWithArrays(CE340Stream* stream);
};
// Release the cached Havok data when requested.
extern __declspec(thread) int g_iCCE860AllocTag;
struct CCE860AllocTagScope
{
    int m_iSaved;

    CCE860AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCE860AllocTag;
        g_iCCE860AllocTag = aiAllocationTag;
    }
    ~CCE860AllocTagScope()
    {
        g_iCCE860AllocTag = m_iSaved;
    }
};
class CCE860MemoryManager
{
  public:
    void Deallocate(void* pvMem);
};
extern CCE860MemoryManager g_kCCE860MemoryManager;
inline void __cdecl operator delete(void* pvMem)
{
    g_kCCE860MemoryManager.Deallocate(pvMem);
}
class CCE860Data
{
  public:
    ~CCE860Data();
    int unk00;
};
class CCE860Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    CCE860Data* m_pUserData;

    void ReleaseData(bool bRelease);
};
class ArgCCE;
class TargetCCE
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7C();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8C();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9C();
    virtual void vfnA0();
    virtual void vfnA4();
    virtual void vfnA8();
    virtual void vfnAC();
    virtual void vfnB0();
    virtual void vfnB4();
    virtual void vfnB8();
    virtual void vfnBC();
    virtual void vfnC0();
    virtual void vfnC4();
    virtual void vfnC8();
    virtual void vfnCC();
    virtual bool Process(ArgCCE* pkArg);
};
struct LinkCCE
{
    int unk00;
    int unk04;
    TargetCCE* m_pkTarget;
};
struct BodyCCE
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    LinkCCE* m_pkLink;
};
class BaseCCE
{
  public:
    bool Process(ArgCCE* pkArg);

    void* m_ppVirtualMethodTable;
    int unk04;
    BodyCCE* m_pkBody;
};
inline TargetCCE* GetTargetCCE(BaseCCE* pkObject)
{
    if (pkObject && pkObject->m_pkBody && pkObject->m_pkBody->m_pkLink)
        return pkObject->m_pkBody->m_pkLink->m_pkTarget;
    return 0;
}
class DerivedCCE : public BaseCCE
{
  public:
    bool ProcessWithTarget(ArgCCE* pkArg);
};
__declspec(thread) unsigned int currentAllocationContext = 0x3b;
struct ThreadContextGuard
{
    unsigned int oldValue;
    ThreadContextGuard() : oldValue(currentAllocationContext)
    {
        currentAllocationContext = 0x10;
    }
    ~ThreadContextGuard()
    {
        currentAllocationContext = oldValue;
    }
};
struct StandinClass
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* m_pData;
    void* __thiscall bhkConvexSweepShape_CreateCinfo(bool* result);
};
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int size);
};
extern float DAT_010c72bc;
extern MM g_memoryManager;
struct AllocatedBlock
{
    unsigned int unk00;
    float value04;
    unsigned int unk08;
    float value0c;
    float value10;
};
class BCCFA50Arg;
class BCCFA50Shape
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
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void VFuncA0();
    virtual void VFuncA4();
    virtual void VFuncA8();
    virtual void VFuncAC();
    virtual void VFuncB0();
    virtual void VFuncB4();
    virtual void VFuncB8();
    virtual void VFuncBC();
    virtual void VFuncC0();
    virtual void VFuncC4();
    virtual void VFuncC8();
    virtual void VFuncCC();
    virtual bool Process(BCCFA50Arg* pkArg);
};
struct BCCFA50Child
{
    int unk00;
    int unk04;
    BCCFA50Shape* m_pkShape;
};
class BCCFA50Counter
{
  public:
    virtual void VFunc00();
    virtual int GetCount();
};
struct BCCFA50HavokList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    BCCFA50Counter m_kCounter;
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
    BCCFA50Child** m_ppkChildren;
};
class BCCFA50Wrapper
{
  public:
    bool BaseProcess(BCCFA50Arg* pkArg);
    __forceinline BCCFA50HavokList* GetList()
    {
        return this ? m_pkList : 0;
    }
    bool ProcessChildren(BCCFA50Arg* pkArg);

    int unk00;
    int unk04;
    BCCFA50HavokList* m_pkList;
};
// Returns the lazily created settings block, creating it under the Havok allocation tag and registering it when owned.
extern __declspec(thread) int g_iCCFFD0AllocTag;
struct CCFFD0AllocTagScope
{
    int m_iSaved;

    CCFFD0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCFFD0AllocTag;
        g_iCCFFD0AllocTag = aiAllocationTag;
    }
    ~CCFFD0AllocTagScope()
    {
        g_iCCFFD0AllocTag = m_iSaved;
    }
};
class CCFFD0MemoryManager
{
  public:
    void* Allocate(unsigned int uiSize);
};
extern CCFFD0MemoryManager g_kCCFFD0MemoryManager;
extern float g_fCCFFD0DefaultScale;
class CCFFD0Settings
{
  public:
    CCFFD0Settings()
    {
        m_pUserData = 0;
        m_fScale = g_fCCFFD0DefaultScale;
        m_pEntries = 0;
        m_iEntryCount = 0;
        m_iCapacityAndFlags = 0x80000000;
    }

    static void* operator new(unsigned int uiSize, void* pvMem) throw()
    {
        return pvMem;
    }

    void* m_pUserData;
    float m_fScale;
    int unk08;
    int unk0C;
    void* m_pEntries;
    int m_iEntryCount;
    int m_iCapacityAndFlags;
};
class CCFFD0Owner
{
  public:
    int unk00;
    int unk04;
    void* m_pkWorld;
    CCFFD0Settings* m_pkSettings;

    void Register(CCFFD0Settings* pkSettings);
    CCFFD0Settings* GetOrCreateSettings(bool* pbCreated);
};
template <class T> inline void SaveBinaryValue(NiBinaryStream* stream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    stream->BinaryWrite(&value, sizeof(T), &uiSize, 1);
}
struct LinkedObjStub
{
    int unk00;
    int unk04;
    void* m_pLinked;
};
struct CountedSub
{
    virtual void v00();
    virtual int GetCount();
};
struct CountedOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    CountedSub m_sub;
};
struct SavedData
{
    int unk00;
    int unk04;
    char m_cUnk08;
    int m_iUnk0C;
    hkArray<LinkedObjStub*> m_ppData;
};
void bhkStream_SwapHKArray(SavedData* data, void* source, hkArray<LinkedObjStub*>* out);
inline int bhkSaveOwner_blk_00cc0000_o2_rtm_variant::GetCount()
{
    CountedOwner* owner = m_pSharedOwner;
    return owner ? owner->m_sub.GetCount() : 0;
}
struct StateCountSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_iArrayLength;
};
struct StateResetPart
{
    int unk00;
};
struct StateResetTarget
{
    StateCountSource* m_pSource;
    StateResetPart m_kPart;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int* m_piStates;
    int unk20;
    int unk24;
    bool m_bFlag28;
    bool m_bFlag29;

    StateResetPart* ResetStates();
};
extern int DAT_0102016c;
extern int DAT_0102009c;
extern int DAT_010c9634;
extern int DAT_01268154;
extern int DAT_01268118;
extern int DAT_012685b8;
struct C200125Base
{
    void UpdateState_00c87c30();
};
struct C200125Object : C200125Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }

    C200125Object()
    {
        unsigned int count = 1;
        UpdateState_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_0102009c;
        DAT_01268118 += count;
        m_pVtable = &DAT_010c9634;
        DAT_012685b8 += count;
    }
};
struct C200125Owner
{
    void bhkUnaryAction_CopyMembers(C200125Object* object, unsigned int argument);
    C200125Object* bhkMotorAction_CreateClone(unsigned int argument);
};
struct CC4560Obj
{
    void* __thiscall hkAngularDashpotActionCinfo_hkAngularDashpotActionCinfo();
};
struct CC4560Owner
{
    void* unk00;
    void* unk04;
    void* m_p;
    void* m_q;
    void __thiscall bhkAngularDashpotAction_CopyCinfo(void* p);
    void* __thiscall bhkAngularDashpotAction_CreateCinfo(bool* pbCreated);
};
struct SaveStream;
typedef unsigned int(__cdecl* SaveStreamWriteFn)(SaveStream*, const void*, unsigned int, unsigned int*, unsigned int);
struct SaveStream
{
    void* unk00;
    unsigned int m_04;
    void* unk08;
    SaveStreamWriteFn m_0c;
    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int num)
    {
        unsigned int r = m_0c(this, p, n, sizes, num);
        m_04 += r;
        return r;
    }
    unsigned int Write(const void* p, unsigned int n)
    {
        unsigned int cnt = n;
        return BinaryWrite(p, n, &cnt, 1);
    }
};
struct SaveCtx
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    SaveStream* m_pBinaryStream;
};
class FUN_00cc8a10_cls
{
  public:
    void* unk00;
    unsigned char* m_pSub;
    void hkConstraintCinfo_SaveBinary(SaveCtx* ctx);
    void WriteSubData(int a1);
};
static inline void CC8A10Write(SaveCtx* c, void* p, unsigned int n)
{
    c->m_pBinaryStream->Write(p, n);
}
// bhk wrapper LoadBinary: load the parent part, then fix up the Havok cinfo block when the
// stream's endianness differs (translation swapped inline, rotation through the shared helper).
struct TransformDataX
{
    unsigned int m_rotation00, m_rotation04, m_rotation08, m_rotation0c;
    unsigned int m_rotation10, m_rotation14, m_rotation18, m_rotation1c;
    unsigned int m_rotation20, m_rotation24, m_rotation28, m_rotation2c;
    unsigned int m_uiX, m_uiY, m_uiZ, m_w;
};
struct CinfoX
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    TransformDataX m_kMotionTransform;
};
void __cdecl bhkStream_Endian(TransformDataX* pkRotation);
static inline void SwapDword(unsigned int& v)
{
    v = _byteswap_ulong(v);
}
struct bhkParentX
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(),
        v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44();
    virtual CinfoX* GetCinfo(int* piSize);
    void bhkConvexShape_LoadBinary(NiStream& kStream);
};
struct bhkDerivedX : bhkParentX
{
    void bhkConvexTransformShape_LoadBinary(NiStream& kStream);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
namespace cce {
struct Block
{
    char pad[0x30];
    unsigned long m_kPointA;
    unsigned long m_kPointB;
    unsigned long m_iThirdValue;
    unsigned long m_iFourthElementInteger;
};
void __cdecl bhkStream_Endian(Block* b);
inline void Swap32(unsigned long& v)
{
    v = _byteswap_ulong(v);
}
inline void SwapBlock(Block* b)
{
    Swap32(b->m_kPointA);
    Swap32(b->m_kPointB);
    Swap32(b->m_iThirdValue);
    Swap32(b->m_iFourthElementInteger);
    bhkStream_Endian(b);
}
struct Hdr
{
    char pad[0x10];
    Block m_kBlock;
};
struct Info
{
    int unk;
    int unkCur;
    void* m_pName;
};
struct Meta
{
    char pad[0x18];
    Info* m_pObjectInfo;
};
struct Writer
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
    virtual void SetName(void* p);
    char pad[0x1e4 - 4];
    unsigned char m_ucMode;
};
struct Obj
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
    virtual void va();
    virtual void vaCur();
    virtual void vaValue();
    virtual void vac();
    virtual void vb();
    virtual Hdr* GetHeader(int* pSize);
    int unkCur;
    Meta* m_pMeta;
    void bhkConvexShape_SaveBinary(Writer* w);
    void bhkConvexTransformShape_SaveBinary(Writer* w);
};
static inline void* GetName(Obj* o)
{
    return (o && o->m_pMeta && o->m_pMeta->m_pObjectInfo) ? o->m_pMeta->m_pObjectInfo->m_pName : 0;
}
// @fnv 0x00ccec00
// src: XBOX_PDB 0x00ccec00
void Obj::bhkConvexTransformShape_SaveBinary(Writer* w)
{
    w->SetName(GetName(this));
    int iSize;
    Hdr* h = GetHeader(&iSize);
    if (w->m_ucMode != 1)
        SwapBlock(&h->m_kBlock);
    bhkConvexShape_SaveBinary(w);
    if (w->m_ucMode != 1)
        SwapBlock(&h->m_kBlock);
}
}
extern char g_vtblInst0104da28[];
extern char g_vtblInst010cb300[];
struct ContactPointPair
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
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
};
// hkArray<?>'s fields (m_data, m_size, m_capacityAndFlags), initialised in the body: the original stores them after the
// second vtable store, where the shared hkArray's member constructors would run before the body.
struct FUN_00cd3410_ArrayFields
{
    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapFlags;
    void Init()
    {
        m_pData = 0;
        m_uiLogicalSize = 0;
        m_iCapFlags = (int)0x80000000;
    }
};
struct FUN_00cd3410
{
    void* volatile m_pVtable;            // 0x00
    volatile float m_fEarlyOutDistance;  // 0x04
    int m_unk08;                         // 0x08
    int m_unk0c;                         // 0x0c
    void* m_pHits;                       // 0x10
    int m_iHitsSize;                     // 0x14
    int m_iHitsCapFlags;                 // 0x18
    int m_unk1c;                         // 0x1c
    ContactPointPair m_kHits[8];         // 0x20 (8 * 112 = 0x380)
    volatile unsigned int m_3a0;         // 0x3a0
    FUN_00cd3410_ArrayFields m_a1;                    // 0x3a4
    FUN_00cd3410_ArrayFields m_a2;                    // 0x3b0
    FUN_00cd3410_ArrayFields m_a3;                    // 0x3bc

    FUN_00cd3410(unsigned int param);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
extern const float runtimeFloatSettingDefault92;
extern const float runtimeFloatSettingDefault506;
extern const float g_011db1d4_arg1;
struct Defaults
{
    float strength, damping, gain, recovery, maxVelocity, u14, u18, u1c, u20, u24, u28, u2c;
    Defaults()
        : strength(.17f), damping(0), gain(1), recovery(.6f), maxVelocity(.05f), u14(runtimeFloatSettingDefault92),
          u18(runtimeFloatSettingDefault506), u1c(.1f), u20(.3f), u24(.3f), u28(g_011db1d4_arg1), u2c(.1f)
    {}
    Defaults(int)
    {}
    Defaults* hkaKeyFrameHierarchyUtility_ControlData_ControlData();
};
template <class T> struct Array
{
    T* data;
    int size;
    int capacity;
    Array() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        int c = capacity & 0x3fffffff;
        if (c < n)
        {
            int doubled = c * 2;
            hkArrayUtil__reserve(&alloc, this, n < doubled ? doubled : n, sizeof(T));
        }
    }
    __forceinline void resizeUninitialized(int n)
    {
        reserve(hkMemoryRouter_getInstance()->heap(), n);
        size = n;
    }
    __forceinline void resize(int n)
    {
        reserve(hkMemoryRouter_getInstance()->heap(), n);
        int delta = n - size;
        T* start = data + size;
        for (int i = 0; i < delta; i++)
            new (start + i) T;
        size = n;
    }
    __forceinline void resize(int n, T value)
    {
        reserve(hkMemoryRouter_getInstance()->heap(), n);
        int delta = n - size;
        T* start = data + size;
        for (int i = 0; i < delta; i++)
            start[i] = value;
        size = n;
    }
};
struct Skeleton
{
    int u00, u04, u08;
    short* parents;
    int u10, u14, u18;
    int count;
};
struct Binding
{
    int u00, u04;
    void* name;
    int boneCount;
    int u10, u14, u18, u1c;
    int* remapping;
    int u24, u28;
    Skeleton* skeleton;
    void FUN_00c90510();
};
struct PoseView
{
    int count;
    void* name;
    short* parents;
};
void __cdecl hkaKeyFrameHierarchyUtility_initialize(PoseView*, Transform*);
struct FUN_00cdb400
{
    Array<Defaults> defaults;
    Array<int> auxiliary;
    PoseView pose;
    int u24, u28;
    Array<Transform> transforms;
    Binding* binding;
    Array<short> parents;
    FUN_00cdb400(Binding* input);
};
class hkTargetCC01
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void handle(void* pv);
};
class hkObjCC01
{
  public:
    int unk00;
    int unk04;
    hkTargetCC01* m_target;

    void* DispatchToTarget(void* pv);
};
extern "C" int __cdecl Vsnprintf(char* dst, int maxlen, const char* fmt, ...);
extern "C" int __cdecl hkString_strLen(const char* s);
// src: HAVOK_LIB 0x00cc0080
static __declspec(noinline) void writeString(hkStreamWriter* writer, const char* str)
{
    if (str)
    {
        writer->write(str, hkString_strLen(str));
    }
    else
    {
        writer->write("(null)", 6);
    }
}
struct FUN_00cc0370_Class : hkOstream
{
    FUN_00cc0370_Class& WriteInt64(__int64 val);
};
extern "C" void* DAT_010c9314;
struct OwnerManager
{
    virtual void* Reserved0();
    virtual void* Reserved1();
    virtual void* Reserved2();
    virtual void* Reserved3();
    virtual void* CreateOwner(void* owner);
};
extern "C" OwnerManager* DAT_01268364;
struct FUN_00cc04d0_Class
{
    void* m_pVtable;
    unsigned short m_iFlags;
    unsigned short m_iUnk;
    void* m_pSharedOwner;

    FUN_00cc04d0_Class* __thiscall FUN_00cc04d0(void* owner);
};
struct FUN_00cc0550_VirtualObject
{
    virtual void vf00();
    virtual void* vf04(int value);
};
struct FUN_00cc0550_Holder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    FUN_00cc0550_VirtualObject* unk10;
};
struct FUN_00cc0550_Allocated
{
    void* m_pVtable;
    unsigned short m_usField04;
    unsigned short m_usField06;
    void* m_pField08;
    int m_iField0C;
};
extern "C" void* DAT_010c933c;
struct FUN_00cc0550_class
{
    void* m_pVtable;
    unsigned short m_usField04;
    unsigned short m_usField06;
    FUN_00cc0550_Allocated* m_pField08;

    FUN_00cc0550_class* __thiscall InitializeWithValue(int value);
};
struct FUN_00d46d40_s
{
    const char* FUN_00d46d40();
};
FUN_00d46d40_s* __cdecl Runtime_GetDAT01268b54Address();
struct hkSourceCC08
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0C();
};
extern hkSourceCC08* DAT_01268b08;
struct hkObjCC08
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18(const char* name, int value);

    void hkResource_getContents_class_hkRootLevelContainer();
};
struct CpuOpaque;
extern CpuOpaque DAT_01268590;
CpuOpaque* __cdecl bhkPoseArray_GetRTTI();
struct FUN_00a5d2f0_shell
{
    bool FUN_00a5d2f0(void* apStream);
};
struct FUN_00cc1310_class : FUN_00a5d2f0_shell
{
    unsigned int m_uiUnk0;
    unsigned int m_uiUnk4;
    unsigned int m_uiCount;
    void* m_pData;
    bool bhkPoseArray_RegisterStreamables(void* apStream);
};
struct Stream
{
    int unk0;
    int total;
    int unk8;
    int (*io)(Stream* s, void* buf, int size, int* out, int n);
    void Rd(void* p)
    {
        int sz = 4;
        total += io(this, p, 4, &sz, 1);
    }
};
struct Item
{
    unsigned int count;
    char** data;
};
struct Loader
{
    char pad[0x250];
    Stream* stream;
    void Read(unsigned int* p);
    void WriteObjectLink(unsigned int* p);
};
void __stdcall nullsub_3(Loader* l);
void bhkPoseArray_bhkPose_SaveBinary(Loader* l, char* p);
static inline void ReadU(Loader* l, void* p)
{
    l->stream->Rd(p);
}
struct Obj
{
    int unk0, unk4;
    unsigned int count1;
    unsigned int* arr1;
    unsigned int count2;
    Item** arr2;
    void ReadFromStream(Loader* l);
};
void __cdecl FUN_00a5d430(void);
void __cdecl bhkExtraData_ProcessClone(void);
struct RefObjC
{
    virtual ~RefObjC();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> struct LargeArrayC
{
    virtual ~LargeArrayC();
    T* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void SetSize(unsigned int uiMaxSize);
    __declspec(noinline) void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_uiSize)
        {
            m_uiSize = uiIndex + 1;
            if (element.m_pObject)
                m_uiESize++;
        }
        else
        {
            if (element.m_pObject)
            {
                if (!m_pBase[uiIndex].m_pObject)
                    m_uiESize++;
            }
            else
            {
                if (m_pBase[uiIndex].m_pObject)
                    m_uiESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_uiMaxSize)
            SetSize(uiIndex + m_uiGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(const T& element)
    {
        return SetAtGrow(m_uiSize, element);
    }
};
struct OwnerC
{
    int unk00, unk04, unk08;
    LargeArrayC<NiPointer<RefObjC> > m_kArray;
    void AddRefObject(RefObjC* pkObject);
};
void __cdecl hkConstraintCinfo_GetViewerStrings();
void __cdecl hkBallAndSocketConstraintCinfo_GetViewerStrings();
struct S_54d0_Poly
{
    void* m_pVtable;
};
struct S_54d0_Child
{
    void* m_pUnk00;

    S_54d0_Child()
    {}
};
struct S_54d0_Heap
{
    void* Allocate(unsigned int uiSize);
};
extern S_54d0_Heap g_54d0Heap;
extern int DAT_010c9af0;
struct S_54d0_Node : S_54d0_Poly, S_54d0_Child
{
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;

    static void* operator new(unsigned int uiSize)
    {
        return g_54d0Heap.Allocate(uiSize);
    }

    S_54d0_Node()
    {
        S_54d0_Child* pkSelf = this;
        m_uiRefCount = 1;
        m_uiValue1 = 0;
        m_uiData1 = 0;
        m_pVtable = (void*)&DAT_010c9af0;
        pkSelf->m_pUnk00 = 0;
    }
};
struct S_54d0_Owner
{
    void* m_pUnk00;
    void* m_pUnk04;
    void* m_pUnk08;
    S_54d0_Child* m_pData;

    void Attach(unsigned int uiNode);
    S_54d0_Child* __thiscall bhkWheelConstraint_CreateCinfo(bool* pbCreated);
};
struct CC7970_Allocator
{
    void* __thiscall Game_DoHeapAlloc(unsigned int);
};
struct CC7970_RefData
{
    unsigned int m_uiFilterValue;
};
struct CC7970_RefObject
{
    void* m_pVtable;
    CC7970_RefData m_data;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiReserved;
};
static __forceinline CC7970_RefData* CC7970_CreateReference()
{
    CC7970_RefObject* object = reinterpret_cast<CC7970_RefObject*>(
        reinterpret_cast<CC7970_Allocator*>(&DAT_011f6238)->Game_DoHeapAlloc(sizeof(CC7970_RefObject)));
    if (object)
    {
        CC7970_RefData* data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010c9d60;
        data->m_uiFilterValue = 0;
        return data;
    }
    return 0;
}
struct CC7970_Owner
{
    unsigned int m_unk00, m_unk04, m_flag08;
    CC7970_RefData* m_pData;
    void __thiscall CopyFromSource(CC7970_RefObject* object);
    CC7970_RefData* __thiscall GetOrCreateRefData(bool* created);
};
void hkGenericConstraintCinfo_LoadBinary();
void hkFixedConstraintCinfo_LoadBinary();
void __cdecl hkGenericConstraintCinfo_SaveBinary();
void __cdecl hkFixedConstraintCinfo_SaveBinary();
void* Object_DispatchCommandFour(unsigned int);
void FUN_00aa1460(void*, unsigned int);
extern int DAT_01268188;
extern int DAT_01268f74;
extern int DAT_01268624;
// Constructor stand-in for the twelve-byte bhkRefObject base.
struct FUN_00c87c30
{
    virtual ~FUN_00c87c30();
    unsigned int references;
    void* handle;
    FUN_00c87c30();
};
// The pack's bhkConstraint shell omits its base and data member.
// This stand-in models the actual sixteen-byte constraint layout.
class Constraint348 : public FUN_00c87c30
{
  public:
    void* constraint;
    Constraint348() : constraint(0)
    {
        ++DAT_01268188;
    }
    virtual ~Constraint348();
};
bhkFixedConstraint* CreateFixedConstraint();
struct FUN_00d53d90 : S_00cc4b90_RefObj
{
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
    FUN_00d53d90();
};
struct S_00cc9020_Cls
{
    int unk00;
    FUN_00d53d90* m_object;
    int __thiscall EnsureObject();
};
void __cdecl bhkBvTreeShape_LinkObject();
void __cdecl bhkMoppBvTreeShape_LinkObject();
// Forward declaration of the target function
void __cdecl bhkBvTreeShape_RegisterStreamables();
void __cdecl bhkMoppBvTreeShape_RegisterStreamables();
void __cdecl bhkBvTreeShape_IsEqual();
void __cdecl bhkMoppBvTreeShape_IsEqual();
struct FUN_00cce5e0_class
{
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned int m_uiData3;
    FUN_00cce5e0_class* __thiscall Construct();
};
struct Cls00ccf5a0
{
    void bhkShape_LinkObject(int a);
    void bhkConvexSweepShape_LinkObject(int a);
};
void __cdecl hkArrayUtil__reserve(void* alloc, void* arr, int cap, int elemSize);
struct FE50Router
{
    int m0, m4, m8, mc;
    void* m10;
};
struct FE50Iter
{
    virtual void v00();
    virtual unsigned int GetCount();
    virtual void* GetFirst();
    virtual void* GetNext(void* it);
};
struct FE50Hk
{
    char pad00[0x14];
    FE50Iter m_kIter;
    float m18;
    char pad1c[0x28];
    void** m44;
    bool hkpConvexListShape_getUseCachedAabb();
};
struct FE50Arr
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct FE50Out
{
    int m0, m4;
    unsigned char m8;
    float mc;
    Array<void*> m10;
};
struct FE50Wrap
{
    int m0, m4;
    FE50Hk* m8;
    void bhkConvexShape_CopyCinfo(FE50Out* out);
    float GetF()
    {
        if (this && m8)
            return m8->m18;
        return 0.0f;
    }
    int GetB()
    {
        if (this && m8)
            return m8->hkpConvexListShape_getUseCachedAabb();
        return 0;
    }
    unsigned int GetCount()
    {
        FE50Hk* p;
        if (this && (p = m8) != 0)
            return p->m_kIter.GetCount();
        if (0)
            return m8->m_kIter.GetCount();
        return 0;
    }
    void* GetFirst()
    {
        FE50Hk* p;
        if (this && (p = m8) != 0)
            return p->m_kIter.GetFirst();
        if (0)
            return m8->m_kIter.GetFirst();
        return 0;
    }
    void* GetNext(void* it)
    {
        FE50Hk* p;
        if (this && (p = m8) != 0)
            return p->m_kIter.GetNext(it);
        if (0)
            return m8->m_kIter.GetNext(it);
        return 0;
    }
    void* GetAt(unsigned int i)
    {
        if (this && m8)
            return m8->m44[i];
        return 0;
    }
    void FillOutput(FE50Out* out);
};
struct AGBinStream
{
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(AGBinStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline void AGLoadBinary(AGBinStream& kStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&value, uiSize, &uiSize, 1);
}
struct AGStream : NiStream
{
    void NiStream_ReadMultipleLinkIDs();
};
struct AGOwner : bhkSaveOwner_blk_00cc0000_o2_rtm_variant
{
    void bhkConvexShape_LoadBinary(AGStream* stream);
    void LoadSavedData(AGStream* stream);
};
struct FnvCpu_FUN_00cd0cf0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    void SetValue(unsigned char arg0);
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* pkSection);
struct hkWorldCD29
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
    void* m_pWorldLock;
};
class hkWorldObjectCD29
{
  public:
    int unk00;
    int unk04;
    hkWorldCD29* m_pOwningWorld;

    void LockWorldCriticalSection(int iUnused);
};
extern void(__stdcall* DAT_00fdf100)(int*);
struct B
{
    char pad[0xc4];
    int* f;
};
struct A
{
    int unk0;
    int unk4;
    B* b;
    void ProcessState_00cd2960(int a);
};
void Object_DoNothing_00cd2980();
void Runtime_DoNothing_00cd2990();
void __cdecl Object_DoNothing_00cd29a0();
int __fastcall Object_EvaluateValue_00cd29b0(char* self, int);
struct FUN_00cd29f0_cls
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
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    unsigned int unk88;
    void __thiscall hkpWorldObject_setTreeData(unsigned int v);
};
struct FnvCpu_FUN_00cd2a00_CpuObject
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
    int value;
    int GetValue_00cd2a00();
};
struct hkPairCD2A
{
    int m_kPointA;
    int m_kPointB;
};
// A 16-byte keyed pair record: key at +0, reserved word at +4, and a two-word value at +8 (no shared hkEntry type).
struct KeyedPairRecord
{
    int m_key;
    int m_04;
    hkPairCD2A m_uiFilterValue;
};
class hkObjCD2A
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74;
    KeyedPairRecord* m_entries;
    int m_iNumberOfEntries;

    void SetEntryValue(int iKey, hkPairCD2A kValue, int iUnused);
};
void __stdcall nullsub_37(int, int, int, int);
int __stdcall Runtime_ReturnConstant_112(int arg0, int arg1);
struct FUN_00cdb3c0_class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* __thiscall GetUnk38_00cdb3c0();
};
extern "C" void* __cdecl fnv_zlib_memset(void* dest, int val, unsigned int count) throw();
void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize) throw();
void __cdecl hkArrayUtil__reserve(void* allocator, void* array, int newCapacity, int elementSize) throw();
template <typename T> inline void ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <typename T> struct MyArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    enum
    {
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    __forceinline MyArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}

    __forceinline int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator* alloc, int n) throw()
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = cap * 2;
            int newCap = n < cap2 ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newCap, sizeof(T));
        }
    }

    __forceinline void SetSizeAndGrow(int n, T fill) throw()
    {
        hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        GrowArrayCapacity(router->m_pStreamAllocator, n);
        ConstructWithCopy<T>(m_data + m_iElementCount, n - m_iElementCount, fill);
        m_iElementCount = n;
    }

    __forceinline void AddBack(const T& val) throw()
    {
        hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        }
        ConstructWithCopy<T>(m_data + m_iElementCount, 1, val);
        m_iElementCount++;
    }

    __forceinline ~MyArray() throw()
    {
        hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        hkMemoryAllocator* alloc = router->m_pStreamAllocator;
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        {
            alloc->ReleaseBlock(m_data, m_iCapacityState & 0x3fffffff);
        }
    }
};
template <typename T> struct MyLocalArray : public MyArray<T>
{
    void* m_initialStack;

    __forceinline MyLocalArray(int capacity) throw()
    {
        hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        int numBytes = capacity * sizeof(T);
        int aligned = (numBytes + 0x7f) & ~0x7f;
        void* p = (void*)router->unk00;
        router->unk00 = (int)((char*)p + aligned);
        this->m_iCapacityState = capacity | MyArray<T>::DONT_DEALLOCATE_FLAG;
        this->m_data = (T*)p;
        this->m_initialStack = p;
    }

    __forceinline ~MyLocalArray() throw()
    {
        void* p = m_initialStack;
        if (p == this->m_data)
        {
            this->m_iElementCount = 0;
        }
        ((hkMemoryRouter*)hkMemoryRouter_getInstance())->unk00 = (int)p;
    }
};
struct SomeFilter
{
    int unk00;
    int unk04;
    int unk08;
    const unsigned short* unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
void __cdecl CollectUnusedIndices(SomeFilter* filter, MyArray<short>& out) throw();
struct FUN_00cdea20_cls
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
    int m_e0;

    int hkpRagdollConstraintData_getTwistMotor() const;
};
struct CC0280Stream
{
    virtual void Write(const char* str, int len);
};
int hkString_strLen(int);
// src: HAVOK_LIB 0x00cc0080
static void __declspec(noinline) writeString(CC0280Stream* s, const char* str)
{
    if (str == 0)
    {
        s->Write("(null)", 6);
        return;
    }
    s->Write(str, hkString_strLen((int)str));
}
struct CC0280Writer : hkOstream
{
    CC0280Writer* WriteBool(bool b);
};
int __cdecl hkString_strLen(int);
int __cdecl Vsnprintf(char*, unsigned int, const char*, ...);
struct WriterObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void Write(const char* s, int len);
};
// src: HAVOK_LIB 0x00cc0080
static __declspec(noinline) void writeString(WriterObj* obj, const char* str)
{
    if (!str)
        obj->Write("(null)", 6);
    else
        obj->Write(str, hkString_strLen((int)str));
}
struct FUN_00cc01e0_class
{
    void* m_kPointA;
    void* m_kPointB;
    WriterObj* m_obj;
    FUN_00cc01e0_class* __thiscall WriteShort(short v);
};
struct Param4
{
    int value;
};
struct D274C0Child
{
    void* m_ppVirtualMethodTable;
    unsigned short m_memorySize;
    unsigned short m_sReferenceCount;
    int unk08, unk0c, unk10, unk14, unk18;
    D274C0Child* __thiscall FUN_00d274c0(int first, int second, Param4 third);
};
struct FUN_00cc0500_Class
{
    void* m_ppVirtualMethodTable;
    unsigned short m_memorySize;
    unsigned short m_sReferenceCount;
    D274C0Child* m_pChildAtom;
    FUN_00cc0500_Class* __thiscall FUN_00cc0500(int first, int second, Param4 third);
};
struct S00cc0850_Entry
{
    void* __thiscall hkResource_getContents_class_hkRootLevelContainer();
};
struct S00cc0850_Registry
{
    void* __thiscall FUN_00d46d40(int flags);
};
struct S00cc0850_Slot
{
    void* __thiscall FindByName(void* key);
    void* __thiscall ProcessEntries_00d48150(const char* name, int flags);
};
void* __cdecl hkSerializeUtil_load(int owner, int a, int b);
extern int DAT_01268b9c;
extern const char str_010c93d0[];
extern const char str_010c93c0[];
int __cdecl hkpHavokSnapshot_load(int owner, int* result);
extern "C" void __stdcall FUN_00ec5fce(void*, unsigned int, unsigned int, const void*);
extern "C" void FUN_004381b0();
struct FUN_00a5d3d0
{
    virtual void dummy();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    ~FUN_00a5d3d0();
};
struct FUN_00cc1520 : FUN_00a5d3d0
{
    virtual void dummy();
    char* m_pName;
    unsigned int m_uiCount;
    void** m_pEntryData;
    ~FUN_00cc1520();
};
extern int DAT_01268188;
extern int DAT_012685f4;
extern int DAT_0108febc;
extern int DAT_010c52bc;
extern __declspec(thread) int g_ThreadData;
extern void* __cdecl Object_DispatchCommandFour(unsigned int bytes);
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
void __cdecl MemoryManager_Deallocate(void* p);
struct S_00cc5b90_Node
{
    int* vtable;
    int data04;
    int data08;
    int data0c;
    void __thiscall UpdateState_00c87c30();
};
struct S_00cc5b90_Scope
{
    volatile int savedState;
    S_00cc5b90_Scope()
    {
        int* currentState = reinterpret_cast<int*>(reinterpret_cast<char*>(&g_ThreadData) + 0x2b4);
        savedState = *currentState;
        *currentState = 16;
    }
    __forceinline ~S_00cc5b90_Scope()
    {
        int* currentState = reinterpret_cast<int*>(reinterpret_cast<char*>(&g_ThreadData) + 0x2b4);
        *currentState = savedState;
    }
};
struct S_00cc5b90_PendingAllocation
{
    S_00cc5b90_Node* object;
    explicit S_00cc5b90_PendingAllocation(S_00cc5b90_Node* p) : object(p)
    {}
    __forceinline ~S_00cc5b90_PendingAllocation()
    {
        if (object)
            MemoryManager_Deallocate(object);
    }
    void Transfer()
    {
        object = 0;
    }
};
struct S_00cc5b90_Owner
{
    void __thiscall bhkConstraint_CopyMembers(S_00cc5b90_Node*, int);
    S_00cc5b90_Node* __thiscall AllocateNode(int arg);
};
struct SaveBody
{
    unsigned int field000;
    unsigned int field004;
    unsigned int field008;
    unsigned int field00c;
    unsigned int field010;
    unsigned int field014;
    unsigned int field018;
    unsigned int field01c;
    SaveMatrix transform;
    SaveMatrix inverse;
    unsigned short flags;
    unsigned char enabled;
    unsigned char unk0a3;
    unsigned int field0a4;
    unsigned int field0a8;
    unsigned int field0ac;
    unsigned int field0b0;
    unsigned int field0b4;
    unsigned int field0b8;
    unsigned int field0bc;
    unsigned int field0c0;
    unsigned int field0c4;
    unsigned int field0c8;
    unsigned int field0cc;
    unsigned int field0d0;
    unsigned int field0d4;
    unsigned int field0d8;
    unsigned int field0dc;
    unsigned int field0e0;
    unsigned int field0e4;
    unsigned int field0e8;
    unsigned int field0ec;
    unsigned int field0f0;
    unsigned int field0f4;
    unsigned int field0f8;
    unsigned int field0fc;
    unsigned int field100;
    unsigned int field104;
    unsigned int field108;
    unsigned int field10c;
    unsigned int field110;
    unsigned int field114;
    unsigned int field118;
    unsigned int field11c;
    unsigned int field120;
    unsigned int field124;
    unsigned int field128;
    unsigned int field12c;
    unsigned int field130;
};
struct SaveObject
{
    int unk00;
    SaveBody* body;
    void hkConstraintCinfo_SaveBinary(SaveCtx*);
    void SaveShape(unsigned int, SaveCtx*);
    void hkRagdollConstraintCinfo_SaveBinary(SaveCtx*);
};
extern int DAT_0108febc;
extern int DAT_010c9e5c;
extern int DAT_010c9d7c;
extern int DAT_01268188;
extern int DAT_01268f74;
extern int DAT_01268624;
void bhkSerializable_CloneCritLock();
void bhkSerializable_CloneCritUnlock() throw();
void* Object_DispatchCommandFour(unsigned int size);
struct ThreadHeapContext
{
    unsigned int m_allocationTag;
};
extern __declspec(thread) ThreadHeapContext g_threadHeapContext;
struct PhysicsNode
{
    void* m_ppVirtualMethodTable;
    unsigned int m_sReferenceCount;
    unsigned int m_flags;
    unsigned int m_data;
    void UpdateState_00c87c30();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    PhysicsNode()
    {
        UpdateState_00c87c30();
        m_ppVirtualMethodTable = &DAT_0108febc;
        unsigned int increment = 1;
        m_data = 0;
        DAT_01268188 += increment;
        m_ppVirtualMethodTable = &DAT_010c9e5c;
        DAT_01268f74 += increment;
        m_ppVirtualMethodTable = &DAT_010c9d7c;
        DAT_01268624 += increment;
    }
};
struct AllocationScope
{
    unsigned int m_previousTag;
    AllocationScope()
    {
        m_previousTag = g_threadHeapContext.m_allocationTag;
        g_threadHeapContext.m_allocationTag = 16;
    }
    __forceinline ~AllocationScope() throw()
    {
        bhkSerializable_CloneCritUnlock();
        g_threadHeapContext.m_allocationTag = m_previousTag;
    }
};
struct PhysicsWorld
{
    void bhkConstraint_CopyMembers(PhysicsNode*, bool);
    PhysicsNode* CreateNode(bool);
};
struct S00cc9af0_Inner
{
    virtual void Run(int v);
};
struct S00cc9af0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    void* m_pData;
    void bhkBallAndSocketConstraint_KillCinfo(bool b);
};
extern const float g_fCCE1C0DefaultScale;
struct CCE1C0MemoryManager
{
    void* Allocate(unsigned int uiSize);
};
extern CCE1C0MemoryManager g_CCE1C0MemoryManager;
extern __declspec(thread) int g_CCE1C0AllocTag;
struct CCE1C0AllocTagScope
{
    int m_iSaved;

    CCE1C0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CCE1C0AllocTag;
        g_CCE1C0AllocTag = aiAllocationTag;
    }
    ~CCE1C0AllocTagScope()
    {
        g_CCE1C0AllocTag = m_iSaved;
    }
};
struct CCE1C0Vec
{
    float x, y, z, w;
};

struct CCE1C0Child
{
    CCE1C0Child() throw() : m_pkOwnerManager(0), m_fScale(g_fCCE1C0DefaultScale), m_arr08(), m_arr14()
    {}

    void* m_pkOwnerManager;
    float m_fScale;
    hkArrayBase<CCE1C0Vec> m_arr08;
    hkArrayBase<CCE1C0Vec> m_arr14;

    static void* operator new(unsigned int uiSize) throw()
    {
        return g_CCE1C0MemoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem)
    {}
};
struct CCE1C0Owner
{
    int unk00;
    int unk04;
    void* m_pParentNode;
    CCE1C0Child* m_pkChild;

    void bhkConvexVerticesShape_CopyCinfo(CCE1C0Child* pkChild);
    CCE1C0Child* GetOrCreateChild(bool* pbCreated);
};
extern __declspec(thread) unsigned int t_uiMemContextC01;

template <typename T, typename Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    clearAndDeallocate();
}

template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    m_iElementCount = 0;
}

template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& allocator)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        allocator.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter_getInstance()->heap();
}
hkMemoryRouter& __cdecl GetMemoryRouterC01();
class FUN_00cdb360_cls
{
  public:
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    FUN_00cdb360_cls* hkaKeyFrameHierarchyUtility_ControlData_ControlData();
};
// 10024 bytes of scratch stack space with no array type (the original frame
// carries no /GS cookie), spelled as nested scalar blocks sized 8..8192.
struct CcScratch8
{
    int m0, m1;
};
struct CcScratch32
{
    CcScratch8 m0, m1, m2, m3;
};
struct CcScratch256
{
    CcScratch32 m0, m1, m2, m3, m4, m5, m6, m7;
};
struct CcScratch512
{
    CcScratch256 m0, m1;
};
struct CcScratch1K
{
    CcScratch256 m0, m1, m2, m3;
};
struct CcScratch8K
{
    CcScratch1K m0, m1, m2, m3, m4, m5, m6, m7;
};
struct CcScratchBuf
{
    CcScratch8K a;
    CcScratch1K b;
    CcScratch512 c;
    CcScratch256 d;
    CcScratch32 e;
    CcScratch8 f;
};
struct Cc0230Self
{
    void* unk00;
    void* unk04;
    hkStreamWriter* unk08;
    Cc0230Self* WriteUInt16(unsigned short w);
};
extern const char str_01094cf0[];
struct FloatArgStream
{
    void* m_pVtable;
    unsigned short m_iFlags;
    unsigned short m_iUnk;
    void* m_pSharedOwner;
    FloatArgStream* WriteFloat(float value);
};
extern const char str_010c9328[];
struct S00cc03c0_Obj
{
    void* unk00;
    unsigned int unk04;
    hkStreamWriter* unk08;
    S00cc03c0_Obj* __thiscall WriteToStream(unsigned __int64 v);
};
struct T
{
    char pad[0x20];
    unsigned short m_20;
};
static T* getAnyNonFixedIsland(T* a, T* b);
T* volatile g_a;
T* volatile g_b;
T* volatile g_sink;
void caller();
extern int DAT_010c93fc;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct CC1290Object
{
    void __thiscall FUN_00a5d3a0();

    void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }

    CC1290Object()
    {
        FUN_00a5d3a0();
        m_pVtable = reinterpret_cast<void*>(&DAT_010c93fc);
        m_uiValue1 = 0;
        m_uiData1 = 0;
        m_uiData2 = 0;
        m_uiData3 = 0;
    }

    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned int m_uiData3;
};
CC1290Object* __cdecl CreateCC1290Object();
struct LoadMM
{
    void* Allocate(unsigned int);
};
extern LoadMM loadManager;
struct LoadTLS
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
    int context;
};
extern __declspec(thread) LoadTLS loadTLS;
struct LoadScope
{
    int old;
    LoadScope()
    {
        old = loadTLS.context;
        loadTLS.context = 16;
    }
    ~LoadScope()
    {
        loadTLS.context = old;
    }
};
struct LoadIO
{
    int unk00;
    unsigned int position;
    unsigned int(__cdecl* read)(LoadIO*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* p)
    {
        unsigned int size = 4;
        position += read(this, p, 4, &size, 1);
    }
};
struct LoadString
{
    void* value;
    LoadString();
    ~LoadString();
    static void* operator new[](unsigned int n)
    {
        return loadManager.Allocate(n);
    }
};
struct LoadElem
{
    int a, b, c, d, e, f, g, h, i, j, k, l;
};
struct LoadGroup
{
    unsigned int count;
    LoadElem* data;
    LoadGroup() : count(0), data(0)
    {}
    static void* operator new(unsigned int n)
    {
        return loadManager.Allocate(n);
    }
};
struct LoadGroupPtr
{
    LoadGroup* value;
    static void* operator new[](unsigned int n)
    {
        return loadManager.Allocate(n);
    }
};
struct LoadStream278
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
    LoadIO* io;
    void ReadString(LoadString&);
};
void __cdecl LoadElement(LoadStream278&, LoadElem&);
struct LoadObject
{
    int unk00, unk04;
    unsigned int stringCount;
    LoadString* strings;
    unsigned int groupCount;
    LoadGroup** groups;
    void BaseLoad(LoadStream278&);
    void bhkPoseArray_LoadBinary(LoadStream278&);
};
extern int DAT_010c970c;
extern int DAT_012685c4;
struct CC3D60Base
{
    void UpdateState_00c87c30();
};
struct CC3D60Object : CC3D60Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }

    CC3D60Object()
    {
        unsigned int count = 1;
        FUN_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_010c5ef4;
        DAT_01268194 += count;
        m_pVtable = &DAT_010c970c;
        DAT_012685c4 += count;
    }
};
struct CC3D60Owner
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
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52(CC3D60Object* object, unsigned int argument);
    CC3D60Object* CreateObject(unsigned int argument);
};
#include <xmmintrin.h>
extern __declspec(thread) unsigned int memoryCategory;
struct ScopedMemoryCategory
{
    unsigned int previous;
    ScopedMemoryCategory() : previous(memoryCategory)
    {
        memoryCategory = 16;
    }
    ~ScopedMemoryCategory()
    {
        memoryCategory = previous;
    }
};
struct CCVector
{
    __m128 value;
    __forceinline void set(float x, float y, float z, float w)
    {
        value = _mm_setr_ps(x, y, z, w);
    }
    __forceinline CCVector& operator=(const CCVector& other)
    {
        value = other.value;
        return *this;
    }
};
struct ShapeInfoCC3
{
    unsigned int unk00;
    unsigned int m_uiArg1;
    unsigned int m_uiArg2;
    unsigned int unk0c;
    float pivotAx, pivotAy, pivotAz, pivotAw;
    float pivotBx, pivotBy, pivotBz, pivotBw;
    float m_fBoundRadius;
    float m_fFriction;
};
class FUN_00d4d980 : public hkReferencedObject
{
  public:
    FUN_00d4d980(unsigned int a, unsigned int b, int c);  // FUN_00d4d980

    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __forceinline void assign(float ax, float ay, float az, float aw, float bx, float by, float bz, float bw)
    {
        m_kMinimumCorner.value = _mm_setr_ps(ax, ay, az, aw);
        m_kMaximumCorner.value = _mm_setr_ps(bx, by, bz, bw);
    }
    CCVector m_kMinimumCorner;
    CCVector m_kMaximumCorner;
    float m_fBoundRadius;
    float m_fFriction;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
};
class ShapeOwnerCC3
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
    virtual void AddShape(FUN_00d4d980* pkShape);
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
    virtual void Update(ShapeInfoCC3* pkInfo);
    void CreateShapeFromInfo(ShapeInfoCC3* pkInfo);
};
extern int DAT_010c97e4;
extern int DAT_012685d0;
struct CC42A0Base
{
    void UpdateState_00c87c30();
};
struct CC42A0Object : CC42A0Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }

    CC42A0Object()
    {
        unsigned int count = 1;
        FUN_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_010c5ef4;
        DAT_01268194 += count;
        m_pVtable = &DAT_010c97e4;
        DAT_012685d0 += count;
    }
};
CC42A0Object* CreateCC42A0Object();
struct SaveValues460
{
    unsigned long unk00, unk04, unk08, unk0C;
    volatile unsigned long value10, value14, value18, value1C, value20, value24;
};
struct SaveObject460
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual SaveValues460* GetData(bool* flag);
    void DispatchChainNodes(FUN_00cc3c50_arg* stream);
    void bhkAngularDashpotAction_SaveBinary(FUN_00cc3c50_arg* stream);
};
inline void SwapValues460(SaveValues460* data)
{
    data->value10 = _byteswap_ulong(data->value10);
    data->value14 = _byteswap_ulong(data->value14);
    data->value18 = _byteswap_ulong(data->value18);
    data->value1C = _byteswap_ulong(data->value1C);
    data->value20 = _byteswap_ulong(data->value20);
    data->value24 = _byteswap_ulong(data->value24);
}
void* __cdecl CreateF4A30Result(void* a, int b);
struct ObjHook : S_00cc4b90_Obj
{
    void ahkpBreakableConstraintData_SetChild(void* child);
};
namespace c4a80 {
struct Cls
{
    int unk0;
    S_00cc4b90_Obj* m_p;
    int hkBreakableConstraintCinfo_CloneData(S_00cc4b90_Obj* shape, int a2);
    int ReleaseObject(S_00cc4b90_Obj* shape, int a2);
};
// @fnv 0x00cc4a80
// src: XBOX_PDB 0x00cc4a80
int Cls::hkBreakableConstraintCinfo_CloneData(S_00cc4b90_Obj* shape, int a2)
{
    S_00cc4b90_Ctx ctx(0x10);
    S_00cc4b90_Obj* src = m_p;
    if (shape == 0)
        shape = new S_00cc4b90_Obj();
    if (src->unk18 != 0)
    {
        void* child = CreateF4A30Result((void*)src->unk18, a2);
        if (child != 0)
        {
            ((ObjHook*)shape)->ahkpBreakableConstraintData_SetChild(child);
            ((FUN_00cca450_hook*)child)->FUN_00c905b0();
        }
    }
    shape->f20 = src->f20;
    unsigned char b = *(volatile unsigned char*)&src->b24;
    shape->b24 = b;
    return ReleaseObject(shape, a2);
}
}
extern __declspec(thread) unsigned int t_uiMemContext4D40;
inline unsigned int GetMemContext4D40()
{
    return t_uiMemContext4D40;
}
inline void SetMemContext4D40(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContext4D40 = m_uiGeometryShaderFlags;
}
extern MemoryManager g_kMemoryManager4D40;
class PolyBase4D40
{
  public:
    void* m_pVtable;
};
// 0x00cc4d40 creates four breakable-constraint cinfo fields; the unrelated Interface type is one byte.
struct BreakableConstraintInfoFields
{
    BreakableConstraintInfoFields()
    {}
    int m_iFirst;
    int m_iArrayLength;
    int m_iA;
    int m_iB;
};
class Object4D40 : public PolyBase4D40, public BreakableConstraintInfoFields
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return g_kMemoryManager4D40.Allocate(uiSize);
    }
    Object4D40()
    {
        BreakableConstraintInfoFields* self = this;
        m_iArrayLength = 1;
        m_iA = 0;
        m_iB = 0;
        m_pVtable = &DAT_010c99e0;
        self->m_iFirst = 0;
    }
};
class Owner4D40
{
  public:
    BreakableConstraintInfoFields* GetOrCreateInterface(bool* pbCreated);
    void SetObject(Object4D40* pkObject);

    int unk00;
    int unk04;
    int m_iActive;
    BreakableConstraintInfoFields* m_pkInterface;
};
extern __declspec(thread) int g_tlsMemContext;
struct ViewerMemoryContext
{
    int previous;
    ViewerMemoryContext() : previous(g_tlsMemContext)
    {
        g_tlsMemContext = 16;
    }
    ~ViewerMemoryContext()
    {
        g_tlsMemContext = previous;
    }
};
struct ViewerStrings
{
    void* vtable;
    char** values;
    unsigned short capacity, count, used, growth;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
    void Append(char* value)
    {
        unsigned int index = count;
        if (index >= capacity)
            FUN_0096ad30(index + growth);
        FUN_0096ae90(index, value);
    }
};
inline void AppendViewerString(ViewerStrings* strings, char* value)
{
    unsigned int index = strings->count;
    if (index >= strings->capacity)
        strings->FUN_0096ad30(index + strings->growth);
    strings->FUN_0096ae90(index, value);
}
struct ViewerConstraint
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual int type();
};
struct ConstraintViewer
{
    virtual ~ConstraintViewer();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void GetStrings(ViewerStrings*);
    void SetChildObject(ViewerConstraint*);
};
ConstraintViewer* __cdecl CreateSaver(int);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
char* __cdecl NiGetViewerString(const char*, bool);
extern const char DAT_010c9a04[], DAT_010c99f8[];
struct ViewerFlag
{
    unsigned char value;
    operator bool() const
    {
        return value != 0;
    }
};
struct ViewerData
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    ViewerConstraint* constraint;
    int unk1C;
    float strength;
    ViewerFlag enabled;
    ViewerConstraint* GetConstraint()
    {
        return constraint;
    }
};
struct DataViewer
{
    void* vtable;
    ViewerData* data;
    void hkConstraintCinfo_GetViewerStrings(ViewerStrings*);
    ViewerData* GetData()
    {
        return data;
    }
    float Strength()
    {
        return GetData() ? GetData()->strength : 0.0f;
    }
    bool Enabled()
    {
        return GetData() ? bool(GetData()->enabled) : false;
    }
    ViewerConstraint* Constraint()
    {
        return GetData() ? GetData()->GetConstraint() : 0;
    }
    void hkBreakableConstraintCinfo_GetViewerStrings(ViewerStrings* strings);
};
struct FUN_00d4f2a0
{
    int unk00;
    unsigned short m_us4;
    FUN_00d4f2a0();
    void* operator new(unsigned int, unsigned int n)
    {
        void* b = hkMemoryRouter_getInstance()->heap().blockAlloc(n);
        ((FUN_00d4f2a0*)b)->m_us4 = (unsigned short)n;
        return b;
    }
    void operator delete(void*, unsigned int)
    {}
};
struct S00cc6030_Cls
{
    void* unk00;
    FUN_00d4f2a0* unk04;
    int hkRagdollLimitsConstraintCinfo_CreateData();
};
struct FUN_00d52fc0 : S_00cc4b90_RefObj
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
    FUN_00d52fc0();
};
struct CC86C0Owner
{
    int unk00;
    FUN_00d52fc0* m_pObject;
    int hkHingeLimitsConstraintCinfo_CreateData();
};
extern int DAT_010ca050;
static __forceinline CC7970_RefData* CC8850_CreateReference()
{
    CC7970_RefObject* object = reinterpret_cast<CC7970_RefObject*>(
        reinterpret_cast<CC7970_Allocator*>(&DAT_011f6238)->Game_DoHeapAlloc(sizeof(CC7970_RefObject)));
    if (object)
    {
        CC7970_RefData* data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010ca050;
        data->m_uiFilterValue = 0;
        return data;
    }
    return 0;
}
struct CC8850_Owner
{
    unsigned int m_unk00, m_unk04, m_flag08;
    CC7970_RefData* m_pData;
    void __thiscall CopyFromSource(CC7970_RefObject* object);
    CC7970_RefData* __thiscall GetOrCreateReference(bool* created);
};
struct A9410Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* pointer, unsigned int size);
};
struct O9410;
struct G9410
{
    O9410* m_pSharedOwner;
    G9410(void* p)
    {
        m_pSharedOwner = (O9410*)p;
    }
    ~G9410();
};
struct O9410
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    void* m_pData;
    unsigned int m_uiCount;
    unsigned int m_uiValue1;

    void SetChildObject(int flag);
    void UpdateState_00cc9410();
};
G9410::~G9410()
{
    m_pSharedOwner->m_pVtable = &DAT_0108ffb4;
    m_pSharedOwner->SetChildObject(0);
}
extern "C" void* DAT_010ca22c;
extern __declspec(thread) int DAT_012722b4;
struct S00cc9560_TlsFlag
{
    int m_saved;
    S00cc9560_TlsFlag()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00cc9560_TlsFlag()
    {
        DAT_012722b4 = m_saved;
    }
};
struct CacheValueVbase
{
    void* m_pVtbl;
};
struct CacheValueFields
{
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    CacheValueFields()
    {
        m_uiRefCount = 0;
        m_uiValue1 = 1;
        m_uiData1 = 0;
        m_uiData2 = 0;
    }
};
struct CacheValueMid
{
    unsigned int m_uiData3;
    unsigned int m_uiData4;
    CacheValueMid()
    {
        m_uiData3 = 0;
        m_uiData4 = 0;
    }
};
struct CacheValue : CacheValueVbase, CacheValueFields, CacheValueMid
{
    unsigned int m_uiCapacityAndFlags;
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiFinalFlags;
    CacheValue() : CacheValueFields(), CacheValueMid()
    {
        m_uiCapacityAndFlags = 0x80000000;
        m_pVtbl = &DAT_010ca22c;
        m_pData = 0;
        m_uiSize = 0;
        m_uiFinalFlags = 0x80000000;
    }
    static void* operator new(unsigned int size) throw()
    {
        return reinterpret_cast<CC7970_Allocator*>(&DAT_011f6238)->Game_DoHeapAlloc(size);
    }
};
struct CacheOwner
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_pSharedOwner;
    CacheValueFields* m_pIntegerData;
    void __thiscall bhkBallSocketConstraintChain_CopyCinfo(void* value);
    void* __thiscall GetOrCreateCacheValue(bool* created);
};
extern int DAT_010c8cc8;
static __forceinline CC7970_RefData* CC9A20_CreateReference()
{
    CC7970_RefObject* object = reinterpret_cast<CC7970_RefObject*>(
        reinterpret_cast<CC7970_Allocator*>(&DAT_011f6238)->Game_DoHeapAlloc(sizeof(CC7970_RefObject)));
    if (object)
    {
        CC7970_RefData* data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010c8cc8;
        data->m_uiFilterValue = 0;
        return data;
    }
    return 0;
}
struct CC9A20_Owner
{
    unsigned int m_unk00, m_unk04, m_flag08;
    CC7970_RefData* m_pData;
    void __thiscall CopyFromSource(CC7970_RefObject* object);
    CC7970_RefData* __thiscall EnsureReference(bool* created);
};
extern int DAT_010ca744;
extern "C" int DAT_01268678;
extern "C" int(__cdecl* DAT_00fdf1c4)(void*);
struct FUN_00ccbc00_elem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_14;
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
struct FUN_00ccbc00_inner
{
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
    FUN_00ccbc00_elem* m_b4;
    unsigned int m_b8;
};
struct CcbcOwnerBase
{
    void bhkSerializable_Kill();
    void FUN_00cd2de0();
    ~CcbcOwnerBase()
    {
        FUN_00cd2de0();
    }
};
struct RefSmartPtr
{
    NiRefObject* ptr;
    ~RefSmartPtr()
    {
        NiRefObject* p = ptr;
        if (p)
        {
            if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0)
                p->DeleteThis();
        }
    }
};
class FUN_00ccbc00 : public CcbcOwnerBase
{
  public:
    void* volatile m_pVtable;
    unsigned int unk04;
    FUN_00ccbc00_inner* volatile m_08;
    unsigned int unk0c;
    unsigned int unk10;
    RefSmartPtr m_14;
    ~FUN_00ccbc00();
};
class S00ccd2c0_Obj
{
  public:
    void UpdateState_00ccd170(float value);
};
struct S00ccd2c0_Arg2
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    float m_10;
};
class S00ccd2c0_cls
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
    virtual S00ccd2c0_Obj* v45(bool* flag);
    int bhkShape_CopyMembers(void* a1, S00ccd2c0_Arg2* a2);
    int bhkCylinderShape_CopyMembers(void* a1, S00ccd2c0_Arg2* a2);
};
static volatile float S00ccd2c0_sink;
// src: GUESS 0x00ccd170 (confidence: low)
__declspec(noinline) void S00ccd2c0_Obj::UpdateState_00ccd170(float value)
{
    S00ccd2c0_sink = value;
}
struct CCD460Owner
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
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49(FUN_00ccd100* object, unsigned int argument);
    FUN_00ccd100* bhkCylinderShape_CreateClone(unsigned int argument);
};
struct EE60Vec
{
    __m128 m_vComponents;

    __forceinline void operator=(const EE60Vec& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
};

#include "../../include/hkMatrix3.h"

struct EE60Xf
{
    hkMatrix3 m_rotation;
    EE60Vec m_vTranslation;

    __forceinline void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};
extern __declspec(thread) int g_EE60Ctx;
inline int GetMemContext()
{
    return g_EE60Ctx;
}
inline void SetMemContext(int aiMemoryContext)
{
    g_EE60Ctx = aiMemoryContext;
}
struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = GetMemContext();
        SetMemContext(aiMemoryContext);
    }
    ~MemContextGuard()
    {
        SetMemContext(m_iSaved);
    }
};
class EE60MemMgr
{
  public:
    void* Allocate(unsigned int);
};
extern EE60MemMgr g_EE60MemMgr;
extern float DAT_010c72bc;
struct CcEE60Data
{
    int unk00;
    float m_f04;
    int unk08;
    int unk0C;
    EE60Xf m_kMotionTransform;

    static void* operator new(unsigned int nbytes)
    {
        unsigned char* p = (unsigned char*)g_EE60MemMgr.Allocate(nbytes + 16);
        unsigned char offset = (unsigned char)(16 - ((unsigned int)p & 15));
        p += offset;
        p[-1] = offset;
        return p;
    }
    static void operator delete(void* p);

    CcEE60Data()
    {
        unk00 = 0;
        m_f04 = DAT_010c72bc;
        unk08 = 0;
        m_kMotionTransform.setIdentity();
    }
};
class CcEE60Self
{
  public:
    int unk00;
    int unk04;
    int m_08;
    CcEE60Data* m_data;

    void bhkConvexTransformShape_CopyCinfo(CcEE60Data* d);
    CcEE60Data* bhkConvexTransformShape_CreateCinfo(bool* created);
};
struct CD05E0_Alloc
{
    void __thiscall MemoryManager_Deallocate(void* p);
};
struct CD05E0_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct CD05E0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct CD05E0_Owner
{
    int unk00;
    int unk04;
    int unk08;
    CD05E0_Obj* m_pEntryObject;
    void bhkConvexListShape_KillCinfo(bool release);
};
struct WorkingState
{
    __declspec(align(16)) unsigned char data[512];
};
struct Arg;
struct ActionTarget
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void apply(Arg* first, Arg* second);
};
struct Result
{
    int ReportDiagnostic;
    int unused4;
    ActionTarget* action;
};
struct Cursor
{
    virtual void reserved0();
    virtual void reserved1();
    virtual int first();
    virtual int next(int index);
    virtual void FunctionAtSlot4();
    virtual Result* lookup(int index, WorkingState* state);
};
struct Collection
{
    int unk00, unk04, unk08, unk0C;
    Cursor cursor;
};
struct Dispatcher
{
    int unk00, unk04;
    Collection* collection;
    void ApplyAll(Arg* argument1, Arg* argument2);
};
static inline ActionTarget* getAction(Dispatcher* d, int position, WorkingState& state)
{
    Collection* c;
    if (d && (c = d->collection) != 0)
    {
        Result* result = c->cursor.lookup(position, &state);
        if (result)
            return result->action;
    }
    return 0;
}
struct TargetAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void ReleaseBlock(void* data, int size);
    void ReturnMemory(void* data, int size)
    {
        ReleaseBlock(data, size);
    }
};
struct TargetContact
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
};
template <class T> struct AllocatorArray
{
    T* data;
    int size;
    int capacityAndFlags;
    static void deallocate(TargetAllocator& a, T* p, int n)
    {
        a.ReturnMemory(p, n * int(sizeof(T)));
    }
    int GetLogicalSize() const
    {
        return size;
    }
    int getCapacity() const
    {
        return capacityAndFlags & 0x3fffffff;
    }
    void ClearAndRelease(TargetAllocator& allocator)
    {
        size = 0;
        if (!(capacityAndFlags & 0x80000000))
            deallocate(allocator, data, getCapacity());
        data = 0;
        capacityAndFlags = 0x80000000;
    }
    void ClearAndRelease()
    {
        ClearAndRelease(reinterpret_cast<TargetAllocator&>(hkMemoryRouter_getInstance()->heap()));
    }
    ~AllocatorArray()
    {
        ClearAndRelease(reinterpret_cast<TargetAllocator&>(hkMemoryRouter_getInstance()->heap()));
    }
};
struct TargetCollectorBase
{
    virtual ~TargetCollectorBase();
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
};
struct FUN_00cd3490 : TargetCollectorBase
{
    AllocatorArray<hkReferencedObject*> references;
    AllocatorArray<unsigned int> indices;
    AllocatorArray<TargetContact> contacts;
    virtual ~FUN_00cd3490();
};
struct __declspec(align(16)) hkMatrix3_Scaled
{
    __m128 col0;
    __m128 col1;
    __m128 col2;
    const __m128* __thiscall FUN_00cd4d40(const __m128* scale, const hkMatrix3_Scaled* source);
};
struct FUN_00cd7d20_Class
{
    void __thiscall hkCharControllerShape_getAabb(float* param1, float param2, float* param3);
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);
void __cdecl FUN_00aa1460(void* p);
extern float DAT_010c72bc;
namespace nd {

}
class FUN_00cce290
{
  public:
    int m_iWordAt00;
    float m_iWordAt04;
    hkArrayBase<char> m_8;
    hkArrayBase<char> m_14;
    FUN_00cce290() : m_iWordAt00(0)
    {}
    ~FUN_00cce290();
};
struct SrcD;
void __cdecl LoadIntoArray(SrcD* src, hkArrayBase<char>* a, hkArrayBase<char>* b);
struct SrcD
{
    int m_iWordAt00;
    int m_iWordAt04;
};
class FUN_00cd7e80
{
  public:
    char pad[0x14];
    FUN_00cd7e80(FUN_00cce290* data);
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void* p)
    {
        FUN_00aa1460(p);
    }
};
FUN_00cd7e80* CreateFromSource(SrcD* src);
struct FUN_00cdb290
{
    void syncLocalSpace();
    StateResetPart* ResetStates();
    StateResetPart* FUN_00cdb0a0();
};
struct EntryState
{
    unsigned int id;
    unsigned char active, mode;
    unsigned short category;
};
struct __declspec(align(16)) EntryData
{
    __m128 coordinates, rotation, metadata;
};
struct FUN_00cdd2d0_Input
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    EntryState* states;
    int size;
    int unk20;
    EntryData* entries;
};
// @fnv 0x00cdd2d0
// src: GUESS 0x00cdd2d0 (confidence: high)
extern "C" void __cdecl Animation_CopyActiveEntries(FUN_00cdd2d0_Input* input, EntryData* output)
{
    int count = input->size;
    int index = 0;
    if (count <= 0)
        return;
    unsigned int offset = 0;
    do
    {
        if (input->states[index].active)
        {
            const __m128* value = (const __m128*)((const char*)input->entries + offset);
            __m128* destination = (__m128*)((char*)output + offset);
            *destination = *value;
        }
        ++index;
        offset += sizeof(EntryData);
    } while (index < count);
}
namespace scdd360 {

struct Slot
{
    int m_iData;
    bool m_bValueAt0C;
};

struct Table
{
    int unk000;
    int unk004;
    int unk008;
    short* m_psCounts;
    int unk010;
    int unk014;
    Slot* m_pkSlots;
    int m_iArrayLength;
};

struct Flag
{
    bool b;
};

// @fnv 0x00cdd360
// src: GUESS 0x00cdd360 (confidence: medium)
void Object_SetActiveSlotFlags(Table* pkTable, Flag kOnlyActive)
{
    int iCount = pkTable->m_iArrayLength;
    for (int i = 0; i < iCount; ++i)
    {
        if (pkTable->m_psCounts[i] > 0 || !kOnlyActive.b)
            pkTable->m_pkSlots[i].m_bValueAt0C = true;
    }
}

}
struct hkVector4_s
{
    __m128 m_vComponents;
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
};

#include "../../include/hkRotation.h"

struct hkTransform_s
{
    hkRotation m_rotation;
    hkVector4_s m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};
struct hkBool_s
{
    char m_cBooleanValue;
    hkBool_s(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
struct RagdollAtoms_s
{
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    RagdollAtoms_s();
};
struct RefObjectBase_s
{
    virtual void vfunc00();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    RefObjectBase_s()
    {
        m_sReferenceCount = 1;
    }
};
struct ConstraintDataBase_s : RefObjectBase_s
{
    int m_ulUserData;
    ConstraintDataBase_s()
    {
        m_ulUserData = 0;
    }
    void setSolvingFlag(hkBool_s flag);
};
struct FUN_00cdf2f0 : ConstraintDataBase_s
{
    int unk0C;
    RagdollAtoms_s m_kBridgeAtoms;
    hkTransform_s m_kBodyALocalFrame;
    hkTransform_s m_kBodyBLocalFrame;
    unsigned short unkA0;
    unsigned char unkA2;
    unsigned char unkA3;
    volatile unsigned short unkA4;
    unsigned short unkA6;
    int unkA8;
    int unkAC;
    hkRotation m_rotationB0;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    unsigned char unkF0;
    unsigned char unkF1;
    unsigned char unkF2;
    unsigned char unkF3;
    unsigned char unkF4;
    unsigned char unkF5;
    unsigned char unkF6;
    unsigned char unkF7;
    float unkF8;
    unsigned char unkFC;
    unsigned char unkFD;
    unsigned char unkFE;
    unsigned char unkFF;
    unsigned char unk100;
    unsigned char unk101;
    unsigned char unk102;
    unsigned char unk103;
    float unk104;
    float unk108;
    float unk10C;
    unsigned char unk110;
    unsigned char unk111;
    unsigned char unk112;
    unsigned char unk113;
    unsigned char unk114;
    unsigned char unk115;
    unsigned char unk116;
    unsigned char unk117;
    float unk118;
    float unk11C;
    float unk120;
    unsigned char unk124;
    unsigned char unk125;
    unsigned char unk126;
    unsigned char unk127;
    unsigned char unk128;
    unsigned char unk129;
    unsigned char unk12A;
    unsigned char unk12B;
    float unk12C;
    float unk130;
    float unk134;

    FUN_00cdf2f0();
};
extern "C" void _ReadWriteBarrier();
extern float DAT_0104da48;
struct CdfSubObject
{
    volatile unsigned char m_00;
    void FindFloatTableIndex(float* value);
};
class CdfObject
{
  public:
    volatile unsigned short m_00;   // +0x0
    volatile unsigned char unk02;   // +0x2
    volatile unsigned char unk03;   // +0x3
    volatile unsigned char unk04;   // +0x4
    volatile unsigned char unk05;   // +0x5
    volatile unsigned char unk06;   // +0x6
    volatile unsigned char unk07;   // +0x7
    volatile unsigned char unk08;   // +0x8
    volatile unsigned char unk09;   // +0x9
    volatile unsigned char unk0a;   // +0xa
    volatile unsigned char unk0b;   // +0xb
    volatile unsigned char unk0c;   // +0xc
    volatile unsigned char unk0d;   // +0xd
    volatile unsigned char unk0e;   // +0xe
    volatile unsigned char unk0f;   // +0xf
    volatile unsigned char unk10;   // +0x10
    volatile unsigned char unk11;   // +0x11
    volatile unsigned char unk12;   // +0x12
    volatile unsigned char unk13;   // +0x13
    volatile unsigned char unk14;   // +0x14
    volatile unsigned char unk15;   // +0x15
    volatile unsigned char unk16;   // +0x16
    volatile unsigned char unk17;   // +0x17
    volatile unsigned char unk18;   // +0x18
    volatile unsigned char unk19;   // +0x19
    volatile unsigned char unk1a;   // +0x1a
    volatile unsigned char unk1b;   // +0x1b
    volatile unsigned char unk1c;   // +0x1c
    volatile unsigned char unk1d;   // +0x1d
    volatile unsigned char unk1e;   // +0x1e
    volatile unsigned char unk1f;   // +0x1f
    volatile unsigned char unk20;   // +0x20
    volatile unsigned char unk21;   // +0x21
    volatile unsigned char unk22;   // +0x22
    volatile unsigned char unk23;   // +0x23
    volatile unsigned char unk24;   // +0x24
    volatile unsigned char unk25;   // +0x25
    volatile unsigned char unk26;   // +0x26
    volatile unsigned char unk27;   // +0x27
    volatile unsigned char unk28;   // +0x28
    volatile unsigned char unk29;   // +0x29
    volatile unsigned char unk2a;   // +0x2a
    volatile unsigned char unk2b;   // +0x2b
    volatile unsigned char unk2c;   // +0x2c
    volatile unsigned char unk2d;   // +0x2d
    volatile unsigned char unk2e;   // +0x2e
    volatile unsigned char unk2f;   // +0x2f
    volatile unsigned char unk30;   // +0x30
    volatile unsigned char unk31;   // +0x31
    volatile unsigned char unk32;   // +0x32
    volatile unsigned char unk33;   // +0x33
    volatile unsigned char unk34;   // +0x34
    volatile unsigned char unk35;   // +0x35
    volatile unsigned char unk36;   // +0x36
    volatile unsigned char unk37;   // +0x37
    volatile unsigned char unk38;   // +0x38
    volatile unsigned char unk39;   // +0x39
    volatile unsigned char unk3a;   // +0x3a
    volatile unsigned char unk3b;   // +0x3b
    volatile unsigned char unk3c;   // +0x3c
    volatile unsigned char unk3d;   // +0x3d
    volatile unsigned char unk3e;   // +0x3e
    volatile unsigned char unk3f;   // +0x3f
    volatile unsigned char unk40;   // +0x40
    volatile unsigned char unk41;   // +0x41
    volatile unsigned char unk42;   // +0x42
    volatile unsigned char unk43;   // +0x43
    volatile unsigned char unk44;   // +0x44
    volatile unsigned char unk45;   // +0x45
    volatile unsigned char unk46;   // +0x46
    volatile unsigned char unk47;   // +0x47
    volatile unsigned char unk48;   // +0x48
    volatile unsigned char unk49;   // +0x49
    volatile unsigned char unk4a;   // +0x4a
    volatile unsigned char unk4b;   // +0x4b
    volatile unsigned char unk4c;   // +0x4c
    volatile unsigned char unk4d;   // +0x4d
    volatile unsigned char unk4e;   // +0x4e
    volatile unsigned char unk4f;   // +0x4f
    volatile unsigned char unk50;   // +0x50
    volatile unsigned char unk51;   // +0x51
    volatile unsigned char unk52;   // +0x52
    volatile unsigned char unk53;   // +0x53
    volatile unsigned char unk54;   // +0x54
    volatile unsigned char unk55;   // +0x55
    volatile unsigned char unk56;   // +0x56
    volatile unsigned char unk57;   // +0x57
    volatile unsigned char unk58;   // +0x58
    volatile unsigned char unk59;   // +0x59
    volatile unsigned char unk5a;   // +0x5a
    volatile unsigned char unk5b;   // +0x5b
    volatile unsigned char unk5c;   // +0x5c
    volatile unsigned char unk5d;   // +0x5d
    volatile unsigned char unk5e;   // +0x5e
    volatile unsigned char unk5f;   // +0x5f
    volatile unsigned char unk60;   // +0x60
    volatile unsigned char unk61;   // +0x61
    volatile unsigned char unk62;   // +0x62
    volatile unsigned char unk63;   // +0x63
    volatile unsigned char unk64;   // +0x64
    volatile unsigned char unk65;   // +0x65
    volatile unsigned char unk66;   // +0x66
    volatile unsigned char unk67;   // +0x67
    volatile unsigned char unk68;   // +0x68
    volatile unsigned char unk69;   // +0x69
    volatile unsigned char unk6a;   // +0x6a
    volatile unsigned char unk6b;   // +0x6b
    volatile unsigned char unk6c;   // +0x6c
    volatile unsigned char unk6d;   // +0x6d
    volatile unsigned char unk6e;   // +0x6e
    volatile unsigned char unk6f;   // +0x6f
    volatile unsigned char unk70;   // +0x70
    volatile unsigned char unk71;   // +0x71
    volatile unsigned char unk72;   // +0x72
    volatile unsigned char unk73;   // +0x73
    volatile unsigned char unk74;   // +0x74
    volatile unsigned char unk75;   // +0x75
    volatile unsigned char unk76;   // +0x76
    volatile unsigned char unk77;   // +0x77
    volatile unsigned char unk78;   // +0x78
    volatile unsigned char unk79;   // +0x79
    volatile unsigned char unk7a;   // +0x7a
    volatile unsigned char unk7b;   // +0x7b
    volatile unsigned char unk7c;   // +0x7c
    volatile unsigned char unk7d;   // +0x7d
    volatile unsigned char unk7e;   // +0x7e
    volatile unsigned char unk7f;   // +0x7f
    volatile unsigned char unk80;   // +0x80
    volatile unsigned char unk81;   // +0x81
    volatile unsigned char unk82;   // +0x82
    volatile unsigned char unk83;   // +0x83
    volatile unsigned char unk84;   // +0x84
    volatile unsigned char unk85;   // +0x85
    volatile unsigned char unk86;   // +0x86
    volatile unsigned char unk87;   // +0x87
    volatile unsigned char unk88;   // +0x88
    volatile unsigned char unk89;   // +0x89
    volatile unsigned char unk8a;   // +0x8a
    volatile unsigned char unk8b;   // +0x8b
    volatile unsigned char unk8c;   // +0x8c
    volatile unsigned char unk8d;   // +0x8d
    volatile unsigned char unk8e;   // +0x8e
    volatile unsigned char unk8f;   // +0x8f
    volatile unsigned short m_90;   // +0x90
    volatile unsigned char m_92;    // +0x92
    volatile unsigned char unk93;   // +0x93
    unsigned short m_94;            // +0x94
    unsigned short m_96;            // +0x96
    volatile unsigned char unk98;   // +0x98
    volatile unsigned char unk99;   // +0x99
    volatile unsigned char unk9a;   // +0x9a
    volatile unsigned char unk9b;   // +0x9b
    volatile unsigned char unk9c;   // +0x9c
    volatile unsigned char unk9d;   // +0x9d
    volatile unsigned char unk9e;   // +0x9e
    volatile unsigned char unk9f;   // +0x9f
    volatile unsigned char unka0;   // +0xa0
    volatile unsigned char unka1;   // +0xa1
    volatile unsigned char unka2;   // +0xa2
    volatile unsigned char unka3;   // +0xa3
    volatile unsigned char unka4;   // +0xa4
    volatile unsigned char unka5;   // +0xa5
    volatile unsigned char unka6;   // +0xa6
    volatile unsigned char unka7;   // +0xa7
    volatile unsigned char unka8;   // +0xa8
    volatile unsigned char unka9;   // +0xa9
    volatile unsigned char unkaa;   // +0xaa
    volatile unsigned char unkab;   // +0xab
    volatile unsigned char unkac;   // +0xac
    volatile unsigned char unkad;   // +0xad
    volatile unsigned char unkae;   // +0xae
    volatile unsigned char unkaf;   // +0xaf
    volatile unsigned char unkb0;   // +0xb0
    volatile unsigned char unkb1;   // +0xb1
    volatile unsigned char unkb2;   // +0xb2
    volatile unsigned char unkb3;   // +0xb3
    volatile unsigned char unkb4;   // +0xb4
    volatile unsigned char unkb5;   // +0xb5
    volatile unsigned char unkb6;   // +0xb6
    volatile unsigned char unkb7;   // +0xb7
    volatile unsigned char unkb8;   // +0xb8
    volatile unsigned char unkb9;   // +0xb9
    volatile unsigned char unkba;   // +0xba
    volatile unsigned char unkbb;   // +0xbb
    volatile unsigned char unkbc;   // +0xbc
    volatile unsigned char unkbd;   // +0xbd
    volatile unsigned char unkbe;   // +0xbe
    volatile unsigned char unkbf;   // +0xbf
    volatile unsigned char unkc0;   // +0xc0
    volatile unsigned char unkc1;   // +0xc1
    volatile unsigned char unkc2;   // +0xc2
    volatile unsigned char unkc3;   // +0xc3
    volatile unsigned char unkc4;   // +0xc4
    volatile unsigned char unkc5;   // +0xc5
    volatile unsigned char unkc6;   // +0xc6
    volatile unsigned char unkc7;   // +0xc7
    volatile unsigned char unkc8;   // +0xc8
    volatile unsigned char unkc9;   // +0xc9
    volatile unsigned char unkca;   // +0xca
    volatile unsigned char unkcb;   // +0xcb
    volatile unsigned char unkcc;   // +0xcc
    volatile unsigned char unkcd;   // +0xcd
    volatile unsigned char unkce;   // +0xce
    volatile unsigned char unkcf;   // +0xcf
    volatile unsigned char unkd0;   // +0xd0
    volatile unsigned char unkd1;   // +0xd1
    volatile unsigned char unkd2;   // +0xd2
    volatile unsigned char unkd3;   // +0xd3
    volatile unsigned char unkd4;   // +0xd4
    volatile unsigned char unkd5;   // +0xd5
    volatile unsigned char unkd6;   // +0xd6
    volatile unsigned char unkd7;   // +0xd7
    volatile unsigned char unkd8;   // +0xd8
    volatile unsigned char unkd9;   // +0xd9
    volatile unsigned char unkda;   // +0xda
    volatile unsigned char unkdb;   // +0xdb
    volatile unsigned char unkdc;   // +0xdc
    volatile unsigned char unkdd;   // +0xdd
    volatile unsigned char unkde;   // +0xde
    volatile unsigned char unkdf;   // +0xdf
    volatile unsigned short m_e0;   // +0xe0
    volatile unsigned char m_e2;    // +0xe2
    volatile unsigned char unke3;   // +0xe3
    volatile unsigned char m_e4;    // +0xe4
    volatile unsigned char unke5;   // +0xe5
    volatile unsigned char unke6;   // +0xe6
    volatile unsigned char unke7;   // +0xe7
    volatile unsigned char unke8;   // +0xe8
    volatile unsigned char unke9;   // +0xe9
    volatile unsigned char unkea;   // +0xea
    volatile unsigned char unkeb;   // +0xeb
    volatile unsigned short m_ec;   // +0xec
    volatile unsigned char m_ee;    // +0xee
    volatile unsigned char unkef;   // +0xef
    volatile unsigned char unkf0;   // +0xf0
    volatile unsigned char unkf1;   // +0xf1
    volatile unsigned char unkf2;   // +0xf2
    volatile unsigned char unkf3;   // +0xf3
    volatile unsigned char unkf4;   // +0xf4
    volatile unsigned char unkf5;   // +0xf5
    volatile unsigned char unkf6;   // +0xf6
    volatile unsigned char unkf7;   // +0xf7
    volatile unsigned char unkf8;   // +0xf8
    volatile unsigned char unkf9;   // +0xf9
    volatile unsigned char unkfa;   // +0xfa
    volatile unsigned char unkfb;   // +0xfb
    volatile unsigned char unkfc;   // +0xfc
    volatile unsigned char unkfd;   // +0xfd
    volatile unsigned char unkfe;   // +0xfe
    volatile unsigned char unkff;   // +0xff
    volatile unsigned short m_100;  // +0x100
    volatile unsigned char m_102;   // +0x102
    volatile unsigned char unk103;  // +0x103
    volatile unsigned char unk104;  // +0x104
    volatile unsigned char unk105;  // +0x105
    volatile unsigned char m_106;   // +0x106
    volatile unsigned char unk107;  // +0x107
    volatile unsigned char unk108;  // +0x108
    volatile unsigned char unk109;  // +0x109
    volatile unsigned char unk10a;  // +0x10a
    volatile unsigned char unk10b;  // +0x10b
    volatile unsigned char unk10c;  // +0x10c
    volatile unsigned char unk10d;  // +0x10d
    volatile unsigned char unk10e;  // +0x10e
    volatile unsigned char unk10f;  // +0x10f
    volatile unsigned char unk110;  // +0x110
    volatile unsigned char unk111;  // +0x111
    volatile unsigned char unk112;  // +0x112
    volatile unsigned char unk113;  // +0x113
    unsigned short m_114;           // +0x114
    unsigned char m_116;            // +0x116
    volatile unsigned char unk117;  // +0x117
    volatile unsigned char unk118;  // +0x118
    volatile unsigned char unk119;  // +0x119
    volatile unsigned char m_11a;   // +0x11a
    volatile unsigned char unk11b;  // +0x11b
    volatile unsigned char unk11c;  // +0x11c
    volatile unsigned char unk11d;  // +0x11d
    volatile unsigned char unk11e;  // +0x11e
    volatile unsigned char unk11f;  // +0x11f
    volatile unsigned char unk120;  // +0x120
    volatile unsigned char unk121;  // +0x121
    volatile unsigned char unk122;  // +0x122
    volatile unsigned char unk123;  // +0x123
    volatile unsigned char unk124;  // +0x124
    volatile unsigned char unk125;  // +0x125
    volatile unsigned char unk126;  // +0x126
    volatile unsigned char unk127;  // +0x127
    unsigned short m_128;           // +0x128
    volatile unsigned char m_12a;   // +0x12a
    CdfSubObject m_12b;             // +0x12b
    float m_12c;                    // +0x12c

    CdfObject* hkpRagdollConstraintData_Atoms_Atoms();
};
#include <string.h>
struct NamedEntryC136
{
    const char* m_name;
    int m_uiFilterValue;
};
struct ClassInfoC136
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NamedEntryC136* m_entries;
    int m_iNumberOfEntries;
};
struct NameSetC136
{
    int unk00;
    int unk04;
    unsigned int m_numNames;
    const char** m_ppNames;
    bool ContainsAllNames(const ClassInfoC136* pkInfo);
};
struct __declspec(align(16)) Q1420V4
{
    float x;
    float y;
    float z;
    float w;
    Q1420V4& operator=(const Q1420V4& o)
    {
        *(__m128*)this = *(const __m128*)&o;
        return *this;
    }
};
struct Q1420Xf
{
    Q1420V4 r0;
    Q1420V4 r1;
    Q1420V4 r2;
};
struct Q1420Entry
{
    int unk00;
    Q1420Xf* unk04;
};
struct Q1420Item
{
    const char* unk00;
    int unk04;
};
struct Q1420Source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Q1420Item* unk18;
    int unk1C;
};
struct Q1420Helper
{
    int unk00;
    int unk04;
    unsigned int unk08;
    const char** unk0C;
    int unk10;
    Q1420Entry** unk14;

    void bhkPoseArray_CreatePoseForRagdoll(Q1420Xf* dest, Q1420Source* source, int index);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char DAT_010c94a4, DAT_010c9498, str_010c9488;
extern "C" unsigned int DAT_0109b220;
char* __cdecl FUN_00a5b690(const char* name);
struct FUN_00a7b2e0
{
    unsigned int unk04, unk08;

    FUN_00a7b2e0();
    virtual ~FUN_00a7b2e0();
};
inline ExtraMember_blk_00cc0000_o2_rtm_variant::ExtraMember_blk_00cc0000_o2_rtm_variant()
{
    unk14 = 0;
    count = 1;
    unk18 = 0;
    unk1c = 0;
    unk10 = 0;
    vptr = &DAT_010c9498;
}
struct NameRef
{
    char* name;
    NameRef(const char* n)
    {
        name = FUN_00a5b690(n);
    }
    ~NameRef() throw()
    {
        if ((unsigned int)name != DAT_0109b220)
            InterlockedDecrement((long volatile*)(name - 8));
    }
};
struct FUN_00cc1d80 : FUN_00a7b2e0
{
    ExtraMember_blk_00cc0000_o2_rtm_variant member;

    void AssignFixedString(const void*);
    FUN_00cc1d80();
    ~FUN_00cc1d80();
};
class CC4180Base
{
  public:
    virtual ~CC4180Base();

    void Shutdown();
};
class FUN_00cc4180 : public CC4180Base
{
  public:
    virtual ~FUN_00cc4180();

    static unsigned int ms_uiInstances;
};
class CC47F0Base
{
  public:
    virtual ~CC47F0Base();
};
extern int g_iCC47F0Count;
class FUN_00cc47f0 : public CC47F0Base
{
  public:
    void Release();

    virtual ~FUN_00cc47f0();
};
extern "C" void __cdecl operator_delete_sized(void* pvMem, unsigned int uiSize);
class FUN_00cc7e50
{
  public:
    FUN_00cc7e50();
    virtual ~FUN_00cc7e50();

    static void operator delete(void* pvMem, unsigned int uiSize)
    {
        operator_delete_sized(pvMem, uiSize);
    }

    int unk04;
    int unk08;
    int unk0C;
};
struct FUN_00cc9dd0
{
    FUN_00cc9dd0();
    virtual ~FUN_00cc9dd0();

    static void operator delete(void* p, unsigned int size);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct FUN_00ccbb50
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ~FUN_00ccbb50();
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
class FUN_00ccc720 : public NiRefObject
{
  public:
    unsigned int unk08;
    FUN_00ccbb50* entries;
    virtual ~FUN_00ccc720();
};
extern "C" unsigned __int64 __rdtsc(void);
extern "C" int DAT_0126835c;
extern "C" void* DAT_00fdf044;
struct FUN_00cdfe00_Object
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
    virtual int* vf40();
};
void __cdecl hkpWorldConstraintUtil_removeAndDeleteModifier(int* a, FUN_00cdfe00_Object* b, int c);
typedef void*(__stdcall* TlsGetValueFunc)(int);
void hkpResponseModifier_clearSurfaceVelocity(FUN_00cdfe00_Object* param1, FUN_00cdfe00_Object* param2);
struct LocalBinaryStream
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(LocalBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* p, unsigned int bytes, unsigned int* sizes, unsigned int count)
    {
        unsigned int result = read(this, p, bytes, sizes, count);
        position += result;
        return result;
    }
    void Read(void* p, unsigned int bytes)
    {
        unsigned int size = bytes;
        BinaryRead(p, bytes, &size, 1);
    }
};
struct LocalStream
{
    void* vtable;
    unsigned int version;
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
    LocalBinaryStream* input;
};
struct RagdollConstraintData
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    __m128 axisA;
    __m128 planeA;
    __m128 binormalA;
    __m128 pivotA;
    __m128 axisB;
    __m128 planeB;
    __m128 binormalB;
    __m128 pivotB;
    unsigned short atomType;
    unsigned char enabled;
    unsigned char unk0a3;
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
    float maxFrictionTorque;
    unsigned int unk0fc;
    unsigned int unk100;
    float twistMin;
    float twistMax;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    float coneMax;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    float planeMin;
    float planeMax;
    void hkpRagdollConstraintData_setTwistMotor(hkReferencedObject*);
    void hkpRagdollConstraintData_setPlaneMotor(hkReferencedObject*);
    void hkpRagdollConstraintData_setConeMotor(hkReferencedObject*);
};
struct FUN_00d53200_class
{
    void* vtable;
    RagdollConstraintData* data;
    void hkConstraintCinfo_LoadBinary(LocalStream&);
    hkReferencedObject* hkConstraintCinfo_LoadMotor(LocalStream&);
    void hkRagdollConstraintCinfo_LoadBinary(LocalStream&);
};
extern const float DAT_01011d78;
extern const float DAT_01016248;
extern const float DAT_01017718;
__forceinline void Normalize(__m128& v)
{
    __m128 vector = v;
    __m128 squared = _mm_mul_ps(vector, vector);
    __m128 sum = _mm_shuffle_ps(squared, squared, 0x55);
    sum = _mm_add_ss(sum, squared);
    squared = _mm_shuffle_ps(squared, squared, 0xaa);
    sum = _mm_add_ss(squared, sum);
    __m128 reciprocal = _mm_rsqrt_ss(sum);
    __m128 zero = _mm_set_ss(0.0f);
    __m128 three = _mm_set_ss(3.0f);
    __m128 half = _mm_set_ss(0.5f);
    __m128 correction = _mm_mul_ss(sum, reciprocal);
    correction = _mm_mul_ss(correction, reciprocal);
    correction = _mm_sub_ss(three, correction);
    __m128 scale = _mm_mul_ss(half, reciprocal);
    scale = _mm_mul_ss(scale, correction);
    sum = _mm_cmpeq_ss(sum, zero);
    scale = _mm_andnot_ps(sum, scale);
    scale = _mm_shuffle_ps(scale, scale, 0);
    v = _mm_mul_ps(scale, vector);
}
struct CopyAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& bytes);
    virtual void ReleaseBlock(void* data, int bytes);
};
struct CopyArray
{
    __m128* data;
    int size;
    int capacity;
};
struct CopyOutput
{
    int unk00;
    int unk04;
    CopyArray vertices;
    CopyArray planes;
};
struct CopyShape
{
    void FUN_00d59200(CopyArray*);
    const CopyArray& FUN_00d58d50();
};
struct CopyOwner
{
    int unk00;
    int unk04;
    CopyShape* shape;
    void bhkConvexShape_CopyCinfo(CopyOutput*);
    void bhkConvexVerticesShape_CopyCinfo(CopyOutput* out);
};
extern float DAT_0104da48;
struct ContactSource
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
    unsigned int m_uiCollisionFilterData;
    void FUN_00c905b0();
};
struct ContactHit;
struct ContactListener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void OnEnter(ContactHit* hit);
    virtual void OnStay(ContactHit* hit);
};
struct ContactHandler
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ContactListener* m_kListener;
};
struct ContactUser
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
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    ContactHandler* m_handler;
};
struct ContactOwner
{
    int unk00;
    int unk04;
    ContactUser* m_user;
    void* getUserData() const
    {
        return m_user;
    }
};
struct ContactCollidable;
__forceinline void getUserOut(const ContactCollidable* c, ContactUser*& out);
struct ContactCollidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    void* getOwner() const
    {
        return (char*)this + m_iOwnerOffset;
    }
};
struct ContactHit
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
    ContactCollidable* m_kCollidable;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
};
struct CopyBlock8
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};
template <int N> struct MemCpyAligned
{
    static __forceinline void copy(void* dst, const void* src)
    {
        const CopyBlock8* s = (const CopyBlock8*)src;
        CopyBlock8* d = (CopyBlock8*)dst;
        for (int i = 0; i < N / 8; i++)
            d[i] = s[i];
        if (N == 4)
            *(unsigned int*)dst = *(const unsigned int*)src;
    }
};
__forceinline void getUserOut(const ContactCollidable* c, ContactUser*& out)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    out = owner ? owner->m_user : 0;
}
__forceinline void* getUserData(const ContactCollidable* c)
{
    const ContactOwner* owner = (const ContactOwner*)c->getOwner();
    return owner ? owner->getUserData() : 0;
}
__forceinline ContactUser* getUser(const ContactCollidable* c)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    return owner ? owner->m_user : 0;
}
__forceinline ContactUser* getUser2(const ContactCollidable* c)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    if (!owner)
    {
        return 0;
    }
    return owner->m_user;
}
template <class T>
static __forceinline void ContactArray_removeAt(hkArrayBase<T>& self, int index);

template <class T>
static __forceinline void ContactArray_removeAt(hkArrayBase<T>& self, int index)
{
        self.m_iElementCount--;
        if (self.m_iElementCount != index)
        {
            MemCpyAligned<sizeof(T)>::copy(&self.m_data[index], &self.m_data[self.m_iElementCount]);
        }
    }
struct TriggerCollector : FUN_00cd3410
{
    hkArrayBase<ContactSource*>& sources()
    {
        return *(hkArrayBase<ContactSource*>*)&m_a1;
    }
    hkArrayBase<int>& states()
    {
        return *(hkArrayBase<int>*)&m_a2;
    }
    hkArrayBase<ContactHit>& hits()
    {
        return *(hkArrayBase<ContactHit>*)&m_a3;
    }
    void ProcessContactEvents();
};
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_rcp_ps(__m128);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern const __m128 DAT_010c71e0;
extern const __m128 DAT_010c7170;
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_010c4c00;
extern const __m128 DAT_010c4c10;

__forceinline hkVector4& QuaternionVector(hkQuaternion& q)
{
    return reinterpret_cast<hkVector4&>(q);
}
__forceinline const hkVector4& QuaternionVector(const hkQuaternion& q)
{
    return reinterpret_cast<const hkVector4&>(q);
}

__forceinline void hkVector4::addMul4(__m128 s, const hkVector4& b)
{
    m_vComponents =
    _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
}

__forceinline void hkVector4::setNeg4(const hkVector4& a)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
    _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
    _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline __m128 Dot3Quad(const hkVector4& self, const hkVector4& v)
{
    __m128 x2 = _mm_mul_ps(self.m_vComponents, v.m_vComponents);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
}

__forceinline void hkQuaternion::SetConjugate(const hkQuaternion& q)
{
    QuaternionVector(*this).m_vComponents = _mm_xor_ps(QuaternionVector(q).m_vComponents, DAT_010c4c00);
}

// src: COMMUNITY 0x00c66320
__declspec(noinline) void hkQuaternion::setMul(const hkQuaternion& a, const hkQuaternion& b)
{
    struct RawVector
    {
        __m128 value;
    };
    RawVector storage;
    hkVector4& imaginary = *(hkVector4*)&storage;
    imaginary.setCross(QuaternionVector(a), QuaternionVector(b));
    __m128 aw = _mm_shuffle_ps(QuaternionVector(a).m_vComponents, QuaternionVector(a).m_vComponents, 0xff);
    __m128 bw = _mm_shuffle_ps(QuaternionVector(b).m_vComponents, QuaternionVector(b).m_vComponents, 0xff);
    imaginary.m_vComponents =
    _mm_add_ps(imaginary.m_vComponents, _mm_mul_ps(aw, QuaternionVector(b).m_vComponents));
    imaginary.m_vComponents =
    _mm_add_ps(imaginary.m_vComponents, _mm_mul_ps(bw, QuaternionVector(a).m_vComponents));
    __m128 dot = Dot3Quad(QuaternionVector(a), QuaternionVector(b));
    dot = _mm_shuffle_ps(dot, dot, 0);
    __m128 real = _mm_sub_ps(_mm_mul_ps(QuaternionVector(a).m_vComponents, QuaternionVector(b).m_vComponents), dot);
    QuaternionVector(*this).m_vComponents =
    _mm_shuffle_ps(imaginary.m_vComponents, _mm_unpackhi_ps(imaginary.m_vComponents, real), 0xc4);
}
__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(QuaternionVector(quat).m_vComponents, QuaternionVector(quat).m_vComponents, 0xff);
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = Dot3Quad(QuaternionVector(quat), direction);
    ret.addMul4(imagDotDir, QuaternionVector(quat));
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(QuaternionVector(quat), direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}
__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(QuaternionVector(quat).m_vComponents, QuaternionVector(quat).m_vComponents, 0xff);
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = Dot3Quad(QuaternionVector(quat), direction);
    ret.addMul4(imagDotDir, QuaternionVector(quat));
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(direction, QuaternionVector(quat));
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}
__forceinline hkQsTransform::hkQsTransform() {}

__forceinline void hkQsTransform::operator=(const hkQsTransform& t)
{
    m_vTranslation = t.m_vTranslation;
    QuaternionVector(m_rotation) = QuaternionVector(t.m_rotation);
    m_vScale = t.m_vScale;
}

__forceinline void hkQsTransform::SetConjugate(const hkQsTransform& t)
{
    m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
    m_vTranslation.setNeg4(m_vTranslation);
    m_rotation.SetConjugate(t.m_rotation);
    hkVector4 scale;
    scale.m_vComponents = _mm_shuffle_ps(
    (t.m_vScale.m_vComponents), _mm_unpackhi_ps((t.m_vScale.m_vComponents), DAT_010c7170), 0xc4);
    m_vScale.setReciprocal4(scale);
    m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
}

__forceinline void hkQsTransform::SetProduct(const hkQsTransform& t1, const hkQsTransform& t2)
{
    hkVector4 temp;
    temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
    m_vTranslation.setAdd4(temp, t1.m_vTranslation);
    m_rotation.setMul(t1.m_rotation, t2.m_rotation);
    m_vScale.m_vComponents = _mm_mul_ps((t2.m_vScale.m_vComponents), (t1.m_vScale.m_vComponents));
}

__forceinline void hkQsTransform::SetMulInverse(const hkQsTransform& a, const hkQsTransform& b)
{
    hkQsTransform h;
    h.SetConjugate(a);
    SetProduct(h, b);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" int DAT_0126835c;
unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern char DAT_010c9544[];
extern char DAT_010c41f8[];
struct Key4
{
    int v;
    Key4(const Key4& other) : v(other.v)
    {}
};
struct Mat4
{
    __m128 rows[4];
};
struct ObjInfo
{
    __m128 point;
    float dist;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
};
struct Query
{
    int f00;
    int f04;
    int f08;
    int f0c;
    ObjInfo info;
};
struct PointPair
{
    __m128 p0;
    __m128 p1;
    int key;
    int filter;
};
struct HitBool
{
    unsigned char value;
    HitBool(bool b) : value(b)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
class PickObj
{
  public:
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual HitBool TestInfo(PointPair* pts, ObjInfo* info);
};
struct Entry
{
    PickObj* obj;
    int f04;
    Mat4* mat;
    int f0c;
    int f10;
    int f14;
    int f18;
    Key4 key;
};
struct EntryPair
{
    int first;
    Entry* second;
};
struct SubObj
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c;
    int f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44, f48, f4c, f50, f54, f58, f5c;
    int f60, f64, f68, f6c, f70, f74, f78;
    int f7c;
};
struct RayArg
{
    __m128 p0;
    __m128 p1;
    unsigned char f20;
    unsigned char f21;
    unsigned char f22;
    unsigned char f23;
    Key4 key;
};
struct BestOut
{
    __m128 v;
    float f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    Entry* entry;
};
bool __cdecl bhkCollisionFilter_IsCollisionEnabled(Key4 a, Key4 b);
void __stdcall hkVector4_setRotatedDir(void* a, BestOut* b);
struct Rotation3
{
    __m128 a, b, c;
};
static __forceinline void Transpose(Rotation3& out, const Mat4* m)
{
    __m128 r0 = m->rows[0];
    __m128 r1 = m->rows[1];
    __m128 r2 = m->rows[2];
    __m128 lo = _mm_unpacklo_ps(r0, r1);
    __m128 hi = _mm_unpackhi_ps(r0, r1);
    out.a = _mm_movelh_ps(lo, r2);
    out.b = _mm_shuffle_ps(_mm_movehl_ps(hi, lo), r2, 0xd4);
    out.c = _mm_shuffle_ps(hi, r2, 0xe4);
}
static __forceinline void TransformPoint(__m128& out, const Mat4* m, const __m128& pt)
{
    __m128 t0 = _mm_sub_ps(pt, m->rows[3]);
    __m128 c0 = m->rows[0];
    __m128 c1 = m->rows[1];
    __m128 c2 = m->rows[2];
    {
        __m128 tmp = _mm_unpacklo_ps(c0, c1);
        __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(tmp, c2);
        tmp = _mm_movehl_ps(c0, tmp);
        c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
        c2 = ctmp;
    }
    __m128 b0 = _mm_shuffle_ps(t0, t0, 0);
    __m128 b1 = _mm_shuffle_ps(t0, t0, 0x55);
    __m128 b2 = _mm_shuffle_ps(t0, t0, 0xaa);
    __m128 r0 = _mm_mul_ps(c0, b0);
    __m128 r1 = _mm_mul_ps(c1, b1);
    __m128 r2 = _mm_mul_ps(c2, b2);
    out = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
class PickSelf
{
  public:
    int f00;
    int f04;
    SubObj* sub;
    int f0c, f10, f14, f18, f1c, f20, f24, f28, f2c;
    int f30, f34, f38, f3c, f40, f44, f48, f4c;
    int f50, f54, f58, f5c, f60, f64, f68, f6c;
    int f70, f74, f78, f7c, f80, f84, f88, f8c;
    int f90, f94, f98, f9c, fa0, fa4, fa8, fac;
    int fb0, fb4, fb8, fbc, fc0, fc4, fc8, fcc;
    int fd0, fd4, fd8, fdc, fe0, fe4, fe8, fec;
    int ff0, ff4, ff8, ffc, f100, f104, f108, f10c;
    int f110, f114, f118, f11c, f120, f124, f128, f12c;
    int f130, f134, f138, f13c, f140, f144, f148, f14c;
    int f150, f154, f158, f15c;
    EntryPair* pairs;
    int count;
    void hkpCachingShapePhantomRay_castRay(RayArg* arg1, BestOut* arg2);
};
extern "C" int DAT_012685ac;
void __cdecl bhkSerializable_Kill();
struct FUN_00c8a720
{
    void* vtable;
    virtual ~FUN_00c8a720();
};
struct FUN_00cc2ac0 : FUN_00c8a720
{
    virtual ~FUN_00cc2ac0();
};
inline float scalar(const __m128& value)
{
    float result;
    _mm_store_ss(&result, value);
    return result;
}
static const __m128 signMask = {-0.0f, -0.0f, -0.0f, -0.0f};
inline float cosineAngle(float angle)
{
    return static_cast<float>(cos(angle));
}
__forceinline __m128 readQuad(const __m128* __restrict p)
{
    return *p;
}
__forceinline const __m128& readQuadRef(const __m128* __restrict p)
{
    return *p;
}
__forceinline __m128 readFloats(const float* __restrict p)
{
    return _mm_load_ps(p);
}
__forceinline const __m128& readFloatsRef(const float* __restrict p)
{
    return *reinterpret_cast<const __m128*>(p);
}
struct Bool
{
    char value;
    Bool(bool v) : value(v)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct Shape
{
    int unk00, unk04, unk08, type;
    __m128 unk10, vertexA, vertexB, vertexC;
    Bool isTriangle() const
    {
        Bool result = type == 3;
        _ReadWriteBarrier();
        return result;
    }
};
struct Body
{
    Shape* shape;
    int key;
    void* transform;
    Body* parent;
    signed char bodyOffset;
    char unk11, unk12, unk13;
    int unk14, unk18, unk1c, unk20, unk24;
    char kind, unk29, unk2a, unk2b;
    unsigned flags;
    void FUN_00c90510();
    Bool isSpecial() const
    {
        Bool result = kind == 1;
        _ReadWriteBarrier();
        return result;
    }
    Bool isFlagged() const
    {
        Bool result = (flags & 0x7f) == 30;
        _ReadWriteBarrier();
        return result;
    }
};
struct Input
{
    __m128 position, direction;
    Body* a;
    Body* b;
};
struct ShapeKeys
{
    unsigned keys[8];
};
struct Collision
{
    __m128 position, direction;
    Body* a;
    int state;
    ShapeKeys shapeKeysA;
    Body* b;
    int key;
    ShapeKeys shapeKeysB;
    Collision()
    {}
    __forceinline Collision(const Collision& c)
    {
        _mm_store_ps(position.m128_f32, c.position);
        _mm_store_ps(direction.m128_f32, c.direction);
        a = c.a;
        state = c.state;
        shapeKeysA = c.shapeKeysA;
        b = c.b;
        key = c.key;
        shapeKeysB = c.shapeKeysB;
    }
};
struct PointMatrix
{
    __m128 x, y, z;
};
struct PointVector
{
    __m128 value;
    void hkVector4_setRotatedDir(const PointMatrix&, const PointVector&);
};
template <class T> struct PointArray
{
    T* data;
    int count;
    unsigned capacity;
    void reserve()
    {
        hkMemoryRouter* ctx = hkMemoryRouter_getInstance();
        if (count == int(capacity & 0x3fffffff))
            ResizeAudioStream(ctx->unk10, this, sizeof(T));
    }
    __forceinline void append(const T& value)
    {
        reserve();
        new (data + count) T(value);
        ++count;
    }
    T& expand()
    {
        reserve();
        return data[count++];
    }
    __forceinline void appendPointer(Body* value)
    {
        reserve();
        T* item = data + count;
        _ReadWriteBarrier();
        *item = value;
        ++count;
    }
    int find(Body* value) const
    {
        for (int i = 0; i < count; ++i)
            if (data[i] == value)
                return i;
        return -1;
    }
};
struct Collector
{
    int unk00, unk04, unk08, unk0c;
    PointArray<Collision> collisions;
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
    PointArray<Body*> bodies;
    PointArray<int> states;
    PointArray<Collision> pending;
    void ProcessEntries_00cd3080();
    void bhkCharacterPointCollector_addCdPoint(Input* input);
};
extern float DAT_01267e30;
extern float DAT_01267e34;
extern float DAT_01267e38;
extern float DAT_01267e3c;
extern const float DAT_01018238;
extern const float DAT_01050de4;
extern const float DAT_01012054;
extern const float DAT_01016248;
extern const float DAT_01030ff0;
struct S00cd8920_Vec
{
    float x;
    float y;
    float z;
    float w;
};
struct S00cd8920_Pair
{
    short a;
    short b;
};
struct S00cd8920_Obj
{
    const struct Skeleton* unk00;
    short unk04a;
    short unk04b;
    short unk08;
    unsigned short unk0A;
    unsigned int unk0C;
    S00cd8920_Vec unk10;
    S00cd8920_Vec unk20;
    S00cd8920_Vec unk30;
    S00cd8920_Vec unk40;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
    float unk60;
    float unk64;
    float unk68;
    float unk6C;
    float unk70;
    bool unk74;

    S00cd8920_Obj* hkaFootPlacementIkSolver_Setup_Setup();
};
#include <xmmintrin.h>

#include <intrin.h>
struct ConstraintInput
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void disable();
};
struct TimerEvent
{
    const char* name;
    unsigned int ticks;
    unsigned int auxiliary;
};
struct TimerBuffer
{
    TimerEvent* begin;
    TimerEvent* current;
    TimerEvent* storage;
    TimerEvent* end;
    void emit(const char* name)
    {
        TimerEvent* event = current;
        if (event < end)
        {
            event->name = name;
            _ReadWriteBarrier();
            volatile unsigned int ticks = (unsigned int)__rdtsc();
            event->ticks = ticks;
            current = event + 1;
        }
    }
};
struct ConstraintRecord
{
    unsigned short type;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0c;
    unsigned short size;
    unsigned short unk12;
    unsigned int unk14, unk18, unk1c;
    ConstraintRecord() : type(27), size(32)
    {}
    static void* operator new(unsigned int n)
    {
        return hkMemoryRouter_getInstance()->heap().blockAlloc(n);
    }
};
void* __cdecl FindModifierConstraintAtom(void*, int);
void __cdecl hkpWorldConstraintUtil_addModifier(void*, ConstraintInput*, ConstraintRecord*);
void __cdecl hkpResponseModifier_disableConstraint(void* owner, ConstraintInput* input);
struct S00ccaaf0_arg
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    float m_f10;
};
class S00ccaaf0_cls
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
    virtual FUN_00cca9c0_class* vb4(unsigned char* out);
    void bhkTriangleShape_CopyMembers(void* a1, S00ccaaf0_arg* a2);
};
struct CC2B60Src
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
    float m_30[4];
    float m_40[4];
    float m_50;
    float m_54;
    float m_58;
    unsigned char m_5c;
    unsigned char m_5d;
};
struct CC2B60Dst
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    bhkLimitedHingeVector_blk_00cc0000_o2_rtm_variant m_10;
    bhkLimitedHingeVector_blk_00cc0000_o2_rtm_variant m_20;
    float m_30;
    float m_34;
    float m_38;
    unsigned char m_3c;
    unsigned char m_3d;
};
struct CC2F90Owner_SV
{
    int unk00;
    int unk04;
    CC2B60Src* m_pParentNode;
    void* m_pkChild;

    void __thiscall WriteScriptTargetInfo(void* p);
    void CopyParentFieldsToChild(CC2B60Dst* pkChild);
};
struct MalleableConstraintStrength
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    float strength;

    float __thiscall hkpMalleableConstraintData_getStrength() const;
};
extern float DAT_01017868;
struct FNVEffectRec
{
    unsigned short m_sType;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned short m_sSize;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    float m_fValue20;
    float m_fValue24;
};
void* __cdecl FindModifierConstraintAtom(void* p, int type);
void __cdecl hkpResponseModifier_setImpulseScalingForContact(FUN_00cdfe00_Object* a1, int a2, int a3, ConstraintInput* a4, float a5, float a6);
void __cdecl hkpResponseModifier_setLowSurfaceViscosity(FUN_00cdfe00_Object* pNode, ConstraintInput* pObj);
#include <xmmintrin.h>
namespace CE6Memory {
hkMemoryRouter* hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
}
struct CE6Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void* p, int n);
};
struct CE6Vec
{
    __m128 v;
};
struct CE6Array
{
    CE6Vec* data;
    int size;
    int capacity;
    CE6Array() : data(0), size(0), capacity(0x80000000)
    {}
    ~CE6Array()
    {
        clear(CE6Memory::hkMemoryRouter_getInstance()->heap());
    }
    void clear(hkMemoryAllocator& alloc)
    {
        size = 0;
        if (!(capacity & 0x80000000))
            reinterpret_cast<CE6Heap&>(alloc).Free(data, (capacity & 0x3fffffff) * sizeof(CE6Vec));
        data = 0;
        capacity = 0x80000000;
    }
    void reserve(hkMemoryAllocator& heap, int n)
    {
        int cap = capacity & 0x3fffffff;
        if (cap < n)
        {
            int doubled = cap * 2;
            CE6Memory::hkArrayUtil__reserve(&heap, this, n < doubled ? doubled : n, sizeof(CE6Vec));
        }
    }
    void resize(int n)
    {
        reserve(CE6Memory::hkMemoryRouter_getInstance()->heap(), n);
        size = n;
    }
};
struct CE6Hull
{
    CE6Array a, b;
    ~CE6Hull();
};
struct CE6View
{
    CE6Vec* data;
    int count;
    int stride;
    CE6View(const CE6Array& a)
    {
        count = a.size;
        stride = sizeof(CE6Vec);
        data = a.data;
    }
};
void __cdecl InitAndSetB(const CE6View*, CE6Hull*);
struct CE6Shape
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
    virtual int Count();
    virtual CE6Vec* Vertices(CE6Vec* buffer);
};
struct CE6Owner
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
    virtual void Output(void* first, CE6Hull* hull, void* second, const char* name);
    int unk04;
    CE6Shape* unk08;
    void bhkConvexVerticesShape_BuildDisplayGeometry(void* first, void* second);
};
struct EdaTls_t
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
struct TlsGuard_t_SV
{
    int m_saved;
    TlsGuard_t_SV()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t_SV()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
class FUN_00cceda0_cls
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
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void v0C4(void* p, unsigned int a);

    void* bhkConvexTransformShape_CreateClone(unsigned int arg);
};

struct Vector59
{
    __m128 m_vComponents;
    void operator=(const Vector59& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void mul4f(float s)
    {
        __m128 r = _mm_load_ss(&s);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }
};

struct FUN_00d4f0f0
{
    int unk00;
    unsigned short GetAllocationSize;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Vector59 v0;
    Vector59 v1;
    int unk40;
    float scale;
    int unk48;
    int unk4C;

    void* operator new(unsigned int n)
    {
        hkMemoryRouter* r = hkMemoryRouter_getInstance();
        FUN_00d4f0f0* b = (FUN_00d4f0f0*)r->heap().blockAlloc(n);
        b->GetAllocationSize = (unsigned short)n;
        return b;
    }
    void operator delete(void* p);
    FUN_00d4f0f0();
};

struct Params59
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float factor;
};

struct Owner59
{
    int unk00;
    FUN_00d4f0f0* src;
    void ReleaseObject(FUN_00d4f0f0* node, Params59* params);
    void hkStiffSpringConstraintCinfo_CloneData(FUN_00d4f0f0* node, Params59* params);
};

// @fnv 0x00cc59c0
// src: XBOX_PDB 0x00cc59c0
void Owner59::hkStiffSpringConstraintCinfo_CloneData(FUN_00d4f0f0* node, Params59* params)
{
    S_00cc4b90_Ctx ctx(0x10);
    FUN_00d4f0f0* s = src;
    if (!node)
    {
        node = new FUN_00d4f0f0();
    }
    node->v0.m_vComponents = s->v0.m_vComponents;
    node->v1.m_vComponents = s->v1.m_vComponents;
    node->scale = s->scale;
    float f = params->factor;
    if (f != 1.0f)
    {
        node->v0.mul4f(f);
        node->v1.mul4f(f);
    }
    ReleaseObject(node, params);
}

extern __declspec(thread) S_00cc4b90_Tls Cc9Tls;
struct Cc9Context
{
    int saved;
    __forceinline Cc9Context(int value)
    {
        saved = Cc9Tls.ctx;
        Cc9Tls.ctx = value;
    }
    __forceinline ~Cc9Context()
    {
        Cc9Tls.ctx = saved;
    }
};
extern "C" void _ReadWriteBarrier();
struct ScaleLane
{
    __m128 value;
    __forceinline ScaleLane(float v)
    {
        value = _mm_load_ss(&v);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
struct Cc9Vector
{
    union
    {
        __m128 value;
        float lane[4];
    };
    __forceinline void multiply(const ScaleLane& factor)
    {
        value = _mm_mul_ps(factor.broadcast(), _mm_load_ps(reinterpret_cast<const float*>(&value)));
    }
    Cc9Vector& operator=(const Cc9Vector& other)
    {
        value = other.value;
        return *this;
    }
};
// array element of two vectors that FUN_00cc9270 copies and scales together (e.g. a ray start/end); identity unknown
struct Cc9VectorPair
{
    Cc9Vector a, b;
};

struct Cc9Arr
{
    Cc9VectorPair* data;
    int size;
    int capFlags;
    __forceinline void reserve(hkMemoryAllocator& allocator, int n)
    {
        int cap = capFlags & 0x3fffffff;
        if (cap < n)
        {
            int doubled = cap * 2;
            hkArrayUtil__reserve(&allocator, this, n < doubled ? doubled : n, sizeof(Cc9VectorPair));
        }
    }
    __forceinline void resizeUninitialized(int n)
    {
        reserve(hkMemoryRouter_getInstance()->heap(), n);
        size = n;
    }
};

struct Cc9Src
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Cc9VectorPair* data;
    int size;
};

struct Cc9Arg
{
    unsigned int unk00, unk04, unk08, unk0c;
    float scale;
};

struct Cc9View
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Cc9Arr arr;
    unsigned int unk24, unk28, unk2c, unk30;
};

struct Cc9Owner
{
    unsigned int unk00;
    Cc9Src* src;
    void ReleaseObject(FUN_00d53d90* dest, Cc9Arg* arg);
    void hkBallSocketChainCinfo_CloneData(FUN_00d53d90* dest, Cc9Arg* arg);
};

// @fnv 0x00cc9270
// src: XBOX_PDB 0x00cc9270
void Cc9Owner::hkBallSocketChainCinfo_CloneData(FUN_00d53d90* dest, Cc9Arg* arg)
{
    Cc9Context scope(16);
    Cc9Src* src = this->src;
    Cc9View* d;
    if (dest)
    {
        d = reinterpret_cast<Cc9View*>(dest);
    }
    else
    {
        d = reinterpret_cast<Cc9View*>(new FUN_00d53d90());
    }
    int count = src->size;
    Cc9Arr* arr = &d->arr;
    arr->resizeUninitialized(count);
    int n = src->size;
    Cc9VectorPair* s = src->data;
    Cc9VectorPair* dst = arr->data;
    for (int i = 0; i < n; i++)
    {
        dst[i].a = s[i].a;
        dst[i].b = s[i].b;
    }
    float scale = arg->scale;
    if (scale != 1.0f)
    {
        for (int j = 0; j < d->arr.size; j++)
        {
            Cc9VectorPair* p = arr->data;
            p[j].a.multiply(ScaleLane(scale));
            p = arr->data;
            p[j].b.multiply(ScaleLane(scale));
        }
    }
    this->ReleaseObject(reinterpret_cast<FUN_00d53d90*>(d), arg);
}

struct Cdc90Layout
{
    int unk00;
    int unk04;
    float* unk08;
    int unk0c;
    int unk10;
    float* unk14;
    int unk18;
};

// @fnv 0x00ccdc90
// src: XBOX_PDB 0x00ccdc90
void CdResultObj::hkConvexVerticesShapeCinfo_Scale(float value)
{
    Cdc90Layout* self = reinterpret_cast<Cdc90Layout*>(this);

    for (int i = 0; i < self->unk0c; ++i)
    {
        __m128* vector = reinterpret_cast<__m128*>(self->unk08 + i * 4);
        __m128 scalar = _mm_load_ss(&value);
        __m128 multiplier = _mm_shuffle_ps(scalar, scalar, 0);
        *vector = _mm_mul_ps(multiplier, *vector);
    }

    for (int i = 0; i < self->unk18; ++i)
    {
        float* element = self->unk14 + i * 4 + 3;
        *element *= value;
    }
}

class GroundScalar
{
    __m128 lane;

  public:
    GroundScalar()
    {}
    GroundScalar(const __m128& value) : lane(value)
    {}
    GroundScalar(float value)
    {
        lane = _mm_load_ss(&value);
    }
    operator float() const
    {
        float result;
        _mm_store_ss(&result, lane);
        return result;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(lane, lane, 0);
    }
    __forceinline const __m128& quad() const
    {
        return lane;
    }
};

class GroundVector
{
    __m128 lanes;

  public:
    __forceinline GroundVector()
    {}
    __forceinline GroundVector(const GroundVector& value) : lanes(value.lanes)
    {}
    __forceinline GroundVector(const __m128& value) : lanes(value)
    {}
    __forceinline GroundVector(float x, float y, float z, float w = 0.0f)
    {
        set(x, y, z, w);
    }
    __forceinline void operator=(const GroundVector& value)
    {
        lanes = value.lanes;
    }
    __forceinline void operator=(const __m128& value)
    {
        lanes = value;
    }
    __forceinline void set(float x, float y, float z, float w = 0.0f)
    {
        lanes = _mm_setr_ps(x, y, z, w);
    }
    __forceinline float& operator()(int i)
    {
        return lanes.m128_f32[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return lanes.m128_f32[i];
    }
    __forceinline void setSub4(const GroundVector& a, const GroundVector& b)
    {
        lanes = _mm_sub_ps(a.lanes, b.lanes);
    }
    __forceinline GroundScalar dot3(const GroundVector& b) const
    {
        __m128 product = _mm_mul_ps(lanes, b.lanes);
        __m128 y = _mm_shuffle_ps(product, product, 0x55);
        __m128 z = _mm_shuffle_ps(product, product, 0xaa);
        return _mm_add_ss(z, _mm_add_ss(y, product));
    }
    __forceinline GroundScalar length3() const
    {
        __m128 square = dot3(*this).quad();
        return _mm_sqrt_ss(square);
    }
    __forceinline GroundScalar getSimdAt(int i) const
    {
        switch (i)
        {
        case 0:
            return lanes;
        case 1:
            return _mm_shuffle_ps(lanes, lanes, 0x55);
        case 2:
            return _mm_shuffle_ps(lanes, lanes, 0xaa);
        default:
            return _mm_shuffle_ps(lanes, lanes, 0xff);
        }
    }
    __forceinline void mul4(const GroundScalar& factor)
    {
        lanes = _mm_mul_ps(factor.broadcast(), lanes);
    }
    __forceinline void addMul4(const GroundScalar& factor, const GroundVector& value)
    {
        lanes = _mm_add_ps(lanes, _mm_mul_ps(factor.broadcast(), value.lanes));
    }
};

struct SessionPoint
{
    float x, y, z;
};
struct MotionInput
{
    float step;
    GroundVector surface, forward, up, velocity, movement;
    float maxSpeed;
    GroundVector constraint;
};
struct MotionBasis
{
    GroundVector origin, forward;
};
struct FUN_00c6cba0_class;
struct MotionState
{

    virtual void slot0();

    virtual void slot1();

    virtual void slot2();

    virtual void slot3();

    virtual void slot4();

    virtual void slot5();

    virtual void slot6();

    virtual void slot7();

    virtual void enter(FUN_00c6cba0_class* character);
};

struct MotionStateManager
{
    MotionState* GetIndexedValue_00cbc510(unsigned int state);
};

struct CharacterVtable
{

    void(__thiscall* slot0)(FUN_00c6cba0_class*);

    void(__thiscall* slot1)(FUN_00c6cba0_class*);

    void(__thiscall* slot2)(FUN_00c6cba0_class*);

    void(__thiscall* slot3)(FUN_00c6cba0_class*);

    void(__thiscall* slot4)(FUN_00c6cba0_class*);

    void(__thiscall* slot5)(FUN_00c6cba0_class*);

    void(__thiscall* slot6)(FUN_00c6cba0_class*);

    void(__thiscall* slot7)(FUN_00c6cba0_class*);

    void(__thiscall* slot8)(FUN_00c6cba0_class*);

    void(__thiscall* slot9)(FUN_00c6cba0_class*);

    void(__thiscall* slot10)(FUN_00c6cba0_class*);

    void(__thiscall* slot11)(FUN_00c6cba0_class*);

    void(__thiscall* slot12)(FUN_00c6cba0_class*);

    void(__thiscall* slot13)(FUN_00c6cba0_class*);

    void(__thiscall* slot14)(FUN_00c6cba0_class*);

    void(__thiscall* slot15)(FUN_00c6cba0_class*);

    void(__thiscall* slot16)(FUN_00c6cba0_class*);

    void(__thiscall* slot17)(FUN_00c6cba0_class*);

    void(__thiscall* slot18)(FUN_00c6cba0_class*);

    void(__thiscall* slot19)(FUN_00c6cba0_class*);

    void(__thiscall* slot20)(FUN_00c6cba0_class*);

    void(__thiscall* slot21)(FUN_00c6cba0_class*);

    void(__thiscall* slot22)(FUN_00c6cba0_class*);

    void(__thiscall* slot23)(FUN_00c6cba0_class*);

    void(__thiscall* slot24)(FUN_00c6cba0_class*);

    void(__thiscall* slot25)(FUN_00c6cba0_class*);

    void(__thiscall* slot26)(FUN_00c6cba0_class*);

    void(__thiscall* slot27)(FUN_00c6cba0_class*);

    void(__thiscall* slot28)(FUN_00c6cba0_class*);

    void(__thiscall* slot29)(FUN_00c6cba0_class*);

    void(__thiscall* slot30)(FUN_00c6cba0_class*);

    void(__thiscall* slot31)(FUN_00c6cba0_class*);

    void(__thiscall* slot32)(FUN_00c6cba0_class*);

    void(__thiscall* slot33)(FUN_00c6cba0_class*);

    void(__thiscall* slot34)(FUN_00c6cba0_class*);

    void(__thiscall* slot35)(FUN_00c6cba0_class*);

    void(__thiscall* slot36)(FUN_00c6cba0_class*);

    MotionBasis*(__thiscall* getBasis)(FUN_00c6cba0_class*);
};

struct CharacterFlags
{

    unsigned int bits;

    bool active() const
    {
        return (bits >> 8) & 1;
    }

    bool special() const
    {
        return (bits >> 10) & 1;
    }

    bool airborne() const
    {
        return (bits >> 11) & 1;
    }
};

struct FUN_00c6cba0_class
{

    CharacterVtable* vtable;

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

    MotionStateManager* stateManager;

    unsigned int stateId;

    unsigned int unk3f4;

    unsigned int unk3f8;

    unsigned int unk3fc;

    unsigned int unk400;

    unsigned int unk404;

    unsigned int unk408;

    unsigned int unk40c;

    unsigned int unk410;

    CharacterFlags flags;

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

    GroundVector up;

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

    GroundVector constraint;

    unsigned int unk4b0;

    unsigned int unk4b4;

    unsigned int unk4b8;

    unsigned int unk4bc;

    GroundVector forward;

    GroundVector surface;

    unsigned int unk4e0;

    unsigned int unk4e4;

    float timeStep;

    float getTimeStep() const
    {
        return timeStep;
    }

    unsigned int unk4ec;

    GroundVector velocity;

    unsigned int unk500;

    unsigned int unk504;

    unsigned int unk508;

    unsigned int unk50c;

    GroundVector movement;

    unsigned int motionState;

    unsigned int unk524;

    unsigned int unk528;

    unsigned int unk52c;

    unsigned int unk530;

    unsigned int unk534;

    unsigned int unk538;

    unsigned int unk53c;

    unsigned int unk540;

    float height;

    unsigned int unk548;

    float acceleration;

    unsigned int unk550;

    unsigned int unk554;

    unsigned int unk558;

    unsigned int unk55c;

    unsigned int unk560;

    unsigned int unk564;

    float scale;

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

    bool following;

    unsigned char unk611;

    unsigned char unk612;

    unsigned char unk613;

    unsigned int unk614;

    unsigned int unk618;

    unsigned int unk61c;

    GroundVector goal;

    void bhkCharacterController_GetPosition(SessionPoint* result);

    void SubtractVectors(GroundVector* result);

    void bhkCharacterController_UpdateState();

    void bhkCharacterController_ApplyVelocityMod();
};

void __cdecl hkpCharacterMovementUtil_calculateMovement(MotionInput* input, GroundVector* velocity);

extern float DAT_012686e4;

struct MotionController
{

    unsigned int unk00;

    unsigned int unk04;

    bool stopVertical;

    void bhkCharacterStateOnGround_Update(FUN_00c6cba0_class* character);
};

// @fnv 0x00cd4800
// src: XBOX_PDB 0x00cd4800
void MotionController::bhkCharacterStateOnGround_Update(FUN_00c6cba0_class* character)
{
    if (!character->flags.active() && !character->following)
    {
        if (stopVertical)
            character->velocity(2) = 0.0f;
        SessionPoint position;
        character->bhkCharacterController_GetPosition(&position);
        character->height = position.z;
        character->motionState = 2;
        character->bhkCharacterController_UpdateState();
        character->stateManager->GetIndexedValue_00cbc510(character->stateId)->enter(character);
        return;
    }
    if (character->following)
    {
        GroundVector goal = character->goal;
        GroundVector position;
        character->SubtractVectors(&position);
        GroundVector delta;
        delta.setSub4(position, goal);
        float distance = delta.length3();
        if (distance > float(DAT_012686e4 * 64.0) || character->motionState != 11)
            character->following = false;
    }
    MotionInput input;
    input.step = 1.0f;
    input.surface = character->surface;
    input.forward = character->forward;
    input.up = character->up;
    input.velocity = character->velocity;
    if (character->flags.airborne())
        input.movement.set(character->movement.getSimdAt(1), character->movement.getSimdAt(0),
                           character->movement.getSimdAt(2), 0.0f);
    else
        input.movement.set(character->movement.getSimdAt(1), character->movement.getSimdAt(0), 0.0f, 0.0f);
    input.maxSpeed = 500.0f;
    input.constraint = character->constraint;
    hkpCharacterMovementUtil_calculateMovement(&input, &character->velocity);
    if (!character->flags.airborne())
    {
        character->velocity(2) = input.velocity(2);
        MotionBasis* basis = character->vtable->getBasis(character);
        GroundVector gravity = basis->forward;
        gravity.mul4(GroundScalar(float(character->acceleration * 0.5 * character->scale)));
        character->velocity.addMul4(GroundScalar(character->getTimeStep()), gravity);
    }
    character->bhkCharacterController_ApplyVelocityMod();
    if (character->motionState != 11 && (character->motionState != 1 || character->flags.special()))
        character->bhkCharacterController_UpdateState();
}

namespace N {
// Exe 0x00cd73e0 FUN_00cd73e0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
}
}
struct TriangleVector
{
    union
    {
        N::LocalM128 m_vComponents;
        float lane[4];
    };

    __forceinline float& operator()(int i)
    {
        return lane[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return lane[i];
    }

    __forceinline void setSub4(const TriangleVector& a, const TriangleVector& b)
    {
        m_vComponents = N::_mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(float s)
    {
        m_vComponents = N::_mm_mul_ps(m_vComponents, N::_mm_set_ps1(s));
    }
    __forceinline void setMul4(float s, const TriangleVector& a)
    {
        m_vComponents = N::_mm_mul_ps(N::_mm_set_ps1(s), a.m_vComponents);
    }
    __forceinline void setZero4()
    {
        m_vComponents = N::_mm_setzero_ps();
    }
    __forceinline void setCross(const TriangleVector& a, const TriangleVector& b)
    {
        m_vComponents = N::_mm_sub_ps(N::_mm_mul_ps(N::_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                                    N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2)),
                                      N::_mm_mul_ps(N::_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                                    N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9)));
    }
};

template <class T> __forceinline void hkSwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

// local form of hkMatrix4: 0x00cd73e0 needs inline transpose3 and original SIMD column aliases; shared adaptation does not reproduce exe bytes.
struct TriangleMatrix
{
    TriangleVector m_kColumn0;
    TriangleVector m_kColumn1;
    TriangleVector m_kColumn2;
    TriangleVector m_kColumn3;

    __forceinline float& operator()(int r, int c)
    {
        return (&m_kColumn0)[c](r);
    }

    __forceinline void transpose3()
    {
        hkSwap((*this)(0, 1), (*this)(1, 0));
        hkSwap((*this)(0, 2), (*this)(2, 0));
        hkSwap((*this)(1, 2), (*this)(2, 1));
    }
};

struct TriangleInput
{
    TriangleVector m_kPointA;
    TriangleVector m_kPointB;
    TriangleVector m_iThirdValue;
};

struct TriangleWeights
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
    float m_iFourthElementInteger;
};

// @fnv 0x00cd73e0
// src: GUESS 0x00cd73e0 (confidence: low)
void Object_UpdateFields_00cd73e0(const TriangleInput* tri, const TriangleWeights* p, TriangleMatrix* out, TriangleVector* nrm)
{
    TriangleVector e0;
    e0.setSub4(tri->m_iThirdValue, tri->m_kPointB);
    TriangleVector e2;
    e2.setSub4(tri->m_kPointA, tri->m_iThirdValue);
    TriangleVector e1;
    e1.setSub4(tri->m_kPointB, tri->m_kPointA);
    N::LocalM128 weight = N::_mm_load_ss(&p->m_w);
    weight = N::_mm_shuffle_ps(weight, weight, 0);

    TriangleVector n;
    n.setCross(e0, e2);
    n.m_vComponents = N::_mm_mul_ps(n.m_vComponents, weight);
    nrm->m_vComponents = n.m_vComponents;

    TriangleVector v0;
    v0.setMul4(p->m_uiX, e0);
    TriangleVector v1;
    v1.setMul4(p->m_uiY, e2);
    TriangleVector v2;
    v2.setMul4(p->m_uiZ, e1);

    N::LocalM128 normal9 = N::_mm_shuffle_ps(n.m_vComponents, n.m_vComponents, 0xc9);
    N::LocalM128 normal2 = N::_mm_shuffle_ps(n.m_vComponents, n.m_vComponents, 0xd2);
    out->m_kColumn0.m_vComponents =
        N::_mm_sub_ps(N::_mm_mul_ps(N::_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9), normal2),
                      N::_mm_mul_ps(N::_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2), normal9));
    out->m_kColumn1.m_vComponents =
        N::_mm_sub_ps(N::_mm_mul_ps(N::_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9), normal2),
                      N::_mm_mul_ps(N::_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2), normal9));
    out->m_kColumn2.m_vComponents =
        N::_mm_sub_ps(N::_mm_mul_ps(N::_mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9), normal2),
                      N::_mm_mul_ps(N::_mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2), normal9));
    out->transpose3();

    out->m_kColumn0(3) = (*nrm)(0);
    out->m_kColumn1(3) = (*nrm)(1);
    out->m_kColumn2(3) = (*nrm)(2);
    out->m_kColumn3.setZero4();
    out->m_kColumn3(0) = -p->m_uiX * p->m_iFourthElementInteger;
}

#include <xmmintrin.h>
namespace fnv_00cd8a50 {
namespace N {

// Exe 0x00cd73e0 FUN_00cd73e0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;

extern "C"
{

    LocalM128 _mm_mul_ps(LocalM128, LocalM128);

    LocalM128 _mm_add_ps(LocalM128, LocalM128);

    LocalM128 _mm_sub_ps(LocalM128, LocalM128);

    LocalM128 _mm_add_ss(LocalM128, LocalM128);

    LocalM128 _mm_sub_ss(LocalM128, LocalM128);

    LocalM128 _mm_and_ps(LocalM128, LocalM128);

    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);

    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);

    LocalM128 _mm_load_ps1(const float*);

    LocalM128 _mm_load_ss(const float*);

    void _mm_store_ss(float*, LocalM128);

    int _mm_movemask_ps(LocalM128);
}

}

static __forceinline N::LocalM128 broadcast(float f)
{

    N::LocalM128 scalar = N::_mm_load_ss(&f);

    return N::_mm_shuffle_ps(scalar, scalar, 0);
}

extern float DAT_0104da48;

extern float DAT_01017d00;

extern N::LocalM128 DAT_01017d10;

extern N::LocalM128 DAT_010c7160;

class ScalarLane
{
    N::LocalM128 value;

  public:
    ScalarLane()
    {}
    ScalarLane(const N::LocalM128& v) : value(v)
    {}
    ScalarLane(float f)
    {
        value = N::_mm_load_ss(&f);
    }
    operator float() const
    {
        float f;
        N::_mm_store_ss(&f, value);
        return f;
    }
    __forceinline N::LocalM128 splat() const
    {
        return N::_mm_shuffle_ps(value, value, 0);
    }
    __forceinline const N::LocalM128& raw() const
    {
        return value;
    }
};
inline ScalarLane operator-(const ScalarLane& s)
{
    return N::_mm_sub_ss(DAT_010c7160, s.raw());
}
class FootVector
{
    N::LocalM128 value;

  public:
    FootVector()
    {}
    FootVector(const FootVector& a) : value(a.value)
    {}
    FootVector(const N::LocalM128& a) : value(a)
    {}
    operator N::LocalM128() const
    {
        return value;
    }
    __forceinline void operator=(const FootVector& a)
    {
        value = a.value;
    }
    __forceinline void operator=(const N::LocalM128& a)
    {
        value = a;
    }
    __forceinline void addScaled(const FootVector& base, const FootVector& axis, const ScalarLane& scale)
    {
        value = N::_mm_add_ps(base.value, N::_mm_mul_ps(scale.splat(), axis.value));
    }
    __forceinline void subtract(const FootVector& a, const FootVector& b)
    {
        value = N::_mm_sub_ps(a.value, b.value);
    }
    __forceinline ScalarLane dot(const FootVector& a) const
    {
        N::LocalM128 p = N::_mm_mul_ps(value, a.value);
        N::LocalM128 xy = N::_mm_add_ss(N::_mm_shuffle_ps(p, p, 0x55), p);
        return N::_mm_add_ss(N::_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    __forceinline int close3(const FootVector& other) const
    {
        N::LocalM128 delta = N::_mm_and_ps(N::_mm_sub_ps(value, other.value), DAT_01017d10);
        N::LocalM128 limit = N::_mm_load_ps1(&DAT_01017d00);
        return (N::_mm_movemask_ps(N::_mm_cmple_ps(delta, limit)) & 7) == 7;
    }
};
struct RaycastInterface
{
    virtual void unused() = 0;
    virtual HitBool castFilteredRay(const FootVector&, const FootVector&, unsigned int, float&, FootVector&) = 0;
    virtual HitBool RayCast(const FootVector&, const FootVector&, float&, FootVector&) = 0;
};
struct FootCastInput
{
    FootVector transform0, transform1, transform2, transform3, transform4, transform5;
    int enabled;
    RaycastInterface* world;
    float onOffGain, ascendingGain, descendingGain, plantedGain, raisedGain, unlockGain;
    unsigned int collisionFilter;
    bool useFilter;
};
struct FootPlacementSolver
{
    FootVector transform0, transform1, transform2, transform3;
    FootVector up;
    FootVector unk50, unk60;
    float unk70, unk74, unk78, rayUpDistance, rayDownDistance;
    __forceinline bool query(const FootCastInput& c, const FootVector& a, const FootVector& b, float& f,
                             FootVector& n) const
    {
        return c.useFilter ? bool(c.world->castFilteredRay(a, b, c.collisionFilter, f, n))
                           : bool(c.world->RayCast(a, b, f, n));
    }
    bool hkaFootPlacementIkSolver_castFoot(const FootCastInput&, const FootVector&, const FootVector&, FootVector&, FootVector&) const;
};
// @fnv 0x00cd8a50
// src: XBOX_PDB 0x00cd8a50
bool FootPlacementSolver::hkaFootPlacementIkSolver_castFoot(const FootCastInput& context, const FootVector& start, const FootVector& end,
                                       FootVector& position, FootVector& normal) const
{
    const float r = rayUpDistance;
    const float h = rayDownDistance;
    const float length = h + r;
    HitBool startHit = false;
    float startFraction = DAT_0104da48;
    FootVector startNormal;
    {
        FootVector low, high;
        low.addScaled(start, up, -h);
        high.addScaled(start, up, r);
        startHit = query(context, high, low, startFraction, startNormal);
    }
    HitBool endHit = false;
    float endFraction = DAT_0104da48;
    FootVector endNormal;
    if (!end.close3(start))
    {
        FootVector low, high;
        low.addScaled(end, up, -h);
        high.addScaled(end, up, r);
        float queryFraction;
        endHit = query(context, high, low, queryFraction, endNormal);
        if (endHit)
        {
            const float projection = endNormal.dot(up);
            if (projection <= 0.0f)
                endHit = false;
            else
            {
                FootVector ray, hit;
                ray.subtract(low, high);
                hit.addScaled(high, ray, queryFraction);
                const float planeDistance = -hit.dot(endNormal);
                FootVector from;
                from.addScaled(start, up, r);
                const float denominator = -length * projection;
                const float numerator = -(float(endNormal.dot(from)) + planeDistance);
                const float fraction = numerator / denominator;
                endFraction = fraction;
            }
        }
    }
    if (!startHit && !endHit)
        return false;
    float chosenFraction;
    if (!startHit || startFraction > endFraction)
    {
        chosenFraction = endFraction;
        normal = endNormal;
    }
    else
    {
        chosenFraction = startFraction;
        normal = startNormal;
    }
    const float displacement = chosenFraction * length - r;
    position.addScaled(start, up, -displacement);
    return true;
}
}  // namespace fnv_00cd8a50

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern char DAT_010cb7b8[];
extern char DAT_010c41f8[];
extern const float DAT_01012068;
inline void CopyPropertyVector(Vec4& destination, const Vec4& source)
{
    *reinterpret_cast<__m128*>(&destination) = *reinterpret_cast<const __m128*>(&source);
}
inline void Vec4::zero()
{
    __m128 t = _mm_load_ss(&DAT_01012068);
    *reinterpret_cast<__m128*>(this) = _mm_shuffle_ps(t, t, 0);
}
struct Property
{
    unsigned short type, unk02;
    int unk04, unk08, unk0c;
    unsigned short size, unk12;
    int unk14, unk18, unk1c;
    Vec4 value20, value30;
    static void* operator new(unsigned int n)
    {
        return hkMemoryRouter_getInstance()->heap().blockAlloc(n);
    }
};
// Allocate the property without invoking Vec4's zero-initializing constructor.
inline Property* AllocateProperty()
{
    Property* property = static_cast<Property*>(Property::operator new(sizeof(Property)));
    if (property)
    {
        property->type = 0x18;
        property->size = 0x40;
        return property;
    }
    return 0;
}
struct ObjectData
{
    int unk00, unk04, unk08, unk0c, unk10;
    int index;
};
struct Obj40
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
    virtual ObjectData* v40();
};
Property* FindModifierConstraintAtom(ObjectData*, int);
void hkpWorldConstraintUtil_addModifier(ObjectData*, Obj40*, Property*);
struct ObjArg
{
    Obj40* p;
    ObjArg(Obj40* q) : p(q)
    {}
};
// @fnv 0x00cdf960
// src: COMMUNITY 0x00cdf960
void hkpResponseModifier_setInvMassScalingForContact(Obj40* a, int b, ObjArg c, const Vec4* d)
{
    ObjectData* p = a->v40();
    if (p)
    {
        Obj40* other = c.p;
        _ReadWriteBarrier();
        other->v18();
        TimerBuffer* timer = (TimerBuffer*)TlsGetValue(DAT_0126835c);
        TimerEvent* entry = timer->current;
        if (entry < timer->end)
        {
            entry->name = DAT_010cb7b8;
            _ReadWriteBarrier();
            volatile unsigned stamp = (unsigned)__rdtsc();
            entry->ticks = stamp;
            timer->current = entry + 1;
        }
        Property* q = FindModifierConstraintAtom(p, 0x18);
        if (!q)
        {
            Property* created = AllocateProperty();
            hkpWorldConstraintUtil_addModifier(p, other, created);
            if (b == p->index)
            {
                CopyPropertyVector(created->value20, *d);
                created->value30.zero();
            }
            else
            {
                created->value20.zero();
                CopyPropertyVector(created->value30, *d);
            }
        }
        else
        {
            if (b == p->index)
                CopyPropertyVector(q->value20, *d);
            else
                CopyPropertyVector(q->value30, *d);
            if (q->value20.w == 0.0f && q->value30.w == 0.0f)
            {
                q->value20.w = 1.0f;
                q->value30.w = 1.0f;
            }
        }
        timer = (TimerBuffer*)TlsGetValue(DAT_0126835c);
        entry = timer->current;
        if (entry < timer->end)
        {
            entry->name = DAT_010c41f8;
            _ReadWriteBarrier();
            volatile unsigned stamp = (unsigned)__rdtsc();
            entry->ticks = stamp;
            timer->current = entry + 1;
        }
    }
}

#include <xmmintrin.h>
namespace fnv_00cd44e0 {
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
#include <xmmintrin.h>
inline float altScalar(__m128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}
extern const float DAT_01011d78;
inline float laneXn(const __m128& source, float& scratch)
{
    _mm_store_ss(&scratch, source);
    return scratch;
}
inline float laneZn(const __m128& source, float& scratch)
{
    _mm_store_ss(&scratch, _mm_shuffle_ps(source, source, 0xaa));
    return scratch;
}

inline __m128 factors(__m128 x, float y, float z)
{
    return _mm_set_ps(DAT_01011d78, z, y, _mm_cvtss_f32(x));
}
inline bool flag(unsigned int f, unsigned int shift)
{
    return ((unsigned char)(f >> shift) & 1) != 0;
}
extern "C" __m128 _mm_load_ss(const float*);
class SwimScale
{
    __m128 value;

  public:
    SwimScale(float a)
    {
        value = _mm_load_ss(&a);
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
__forceinline void applyVelocity(__m128& velocity, float acceleration, const __m128& direction, float factor)
{
    SwimScale a(factor);
    __m128 g = _mm_mul_ps(a.splat(), direction);
    SwimScale b(acceleration);
    velocity = _mm_add_ps(velocity, _mm_mul_ps(b.splat(), g));
}
inline float laneX(const __m128& source, volatile float& scratch)
{
    _mm_store_ss(const_cast<float*>(&scratch), source);
    return scratch;
}
inline float laneZ(const __m128& source, volatile float& scratch)
{
    __m128 v = source;
    _mm_store_ss(const_cast<float*>(&scratch), _mm_shuffle_ps(v, v, 0xaa));
    return scratch;
}
struct MotionState;
struct MotionBasis
{
    __m128 x, y, z;
};
struct MotionState
{
    void** methods;
    MotionBasis* GetBasis()
    {
        typedef MotionBasis*(__thiscall * Fn)(MotionState*);
        return reinterpret_cast<Fn>(methods[37])(this);
    }
    unsigned int field004;
    MotionState* field008;
    unsigned int field00c;
    unsigned int field010;
    unsigned int field014;
    unsigned int field018;
    unsigned int field01c;
    unsigned int field020;
    unsigned int field024;
    unsigned int field028;
    unsigned int field02c;
    unsigned int field030;
    unsigned int field034;
    unsigned int field038;
    unsigned int field03c;
    unsigned int field040;
    unsigned int field044;
    unsigned int field048;
    unsigned int field04c;
    unsigned int field050;
    unsigned int field054;
    unsigned int field058;
    unsigned int field05c;
    unsigned int field060;
    unsigned int field064;
    unsigned int field068;
    unsigned int field06c;
    unsigned int field070;
    unsigned int field074;
    unsigned int field078;
    unsigned int field07c;
    unsigned int field080;
    unsigned int field084;
    unsigned int field088;
    unsigned int field08c;
    unsigned int field090;
    unsigned int field094;
    unsigned int field098;
    unsigned int field09c;
    unsigned int field0a0;
    unsigned int field0a4;
    unsigned int field0a8;
    unsigned int field0ac;
    unsigned int field0b0;
    unsigned int field0b4;
    unsigned int field0b8;
    unsigned int field0bc;
    unsigned int field0c0;
    unsigned int field0c4;
    unsigned int field0c8;
    unsigned int field0cc;
    unsigned int field0d0;
    unsigned int field0d4;
    unsigned int field0d8;
    unsigned int field0dc;
    unsigned int field0e0;
    unsigned int field0e4;
    unsigned int field0e8;
    unsigned int field0ec;
    unsigned int field0f0;
    unsigned int field0f4;
    unsigned int field0f8;
    unsigned int field0fc;
    unsigned int field100;
    unsigned int field104;
    unsigned int field108;
    unsigned int field10c;
    unsigned int field110;
    unsigned int field114;
    unsigned int field118;
    unsigned int field11c;
    unsigned int field120;
    unsigned int field124;
    unsigned int field128;
    unsigned int field12c;
    unsigned int field130;
    unsigned int field134;
    unsigned int field138;
    unsigned int field13c;
    unsigned int field140;
    unsigned int field144;
    unsigned int field148;
    unsigned int field14c;
    unsigned int field150;
    unsigned int field154;
    unsigned int field158;
    unsigned int field15c;
    unsigned int field160;
    unsigned int field164;
    unsigned int field168;
    unsigned int field16c;
    unsigned int field170;
    unsigned int field174;
    unsigned int field178;
    unsigned int field17c;
    unsigned int field180;
    unsigned int field184;
    unsigned int field188;
    unsigned int field18c;
    unsigned int field190;
    unsigned int field194;
    unsigned int field198;
    unsigned int field19c;
    unsigned int field1a0;
    unsigned int field1a4;
    unsigned int field1a8;
    unsigned int field1ac;
    unsigned int field1b0;
    unsigned int field1b4;
    unsigned int field1b8;
    unsigned int field1bc;
    unsigned int field1c0;
    unsigned int field1c4;
    unsigned int field1c8;
    unsigned int field1cc;
    unsigned int field1d0;
    unsigned int field1d4;
    unsigned int field1d8;
    unsigned int field1dc;
    unsigned int field1e0;
    unsigned int field1e4;
    unsigned int field1e8;
    unsigned int field1ec;
    unsigned int field1f0;
    unsigned int field1f4;
    unsigned int field1f8;
    unsigned int field1fc;
    unsigned int field200;
    unsigned int field204;
    unsigned int field208;
    unsigned int field20c;
    unsigned int field210;
    unsigned int field214;
    unsigned int field218;
    unsigned int field21c;
    unsigned int field220;
    unsigned int field224;
    unsigned int field228;
    unsigned int field22c;
    unsigned int field230;
    unsigned int field234;
    unsigned int field238;
    unsigned int field23c;
    unsigned int field240;
    unsigned int field244;
    unsigned int field248;
    unsigned int field24c;
    unsigned int field250;
    unsigned int field254;
    unsigned int field258;
    unsigned int field25c;
    unsigned int field260;
    unsigned int field264;
    unsigned int field268;
    unsigned int field26c;
    unsigned int field270;
    unsigned int field274;
    unsigned int field278;
    unsigned int field27c;
    unsigned int field280;
    unsigned int field284;
    unsigned int field288;
    unsigned int field28c;
    unsigned int field290;
    unsigned int field294;
    unsigned int field298;
    unsigned int field29c;
    unsigned int field2a0;
    unsigned int field2a4;
    unsigned int field2a8;
    unsigned int field2ac;
    unsigned int field2b0;
    unsigned int field2b4;
    unsigned int field2b8;
    unsigned int field2bc;
    unsigned int field2c0;
    unsigned int field2c4;
    unsigned int field2c8;
    unsigned int field2cc;
    unsigned int field2d0;
    unsigned int field2d4;
    unsigned int field2d8;
    unsigned int field2dc;
    unsigned int field2e0;
    unsigned int field2e4;
    unsigned int field2e8;
    unsigned int field2ec;
    unsigned int field2f0;
    unsigned int field2f4;
    unsigned int field2f8;
    unsigned int field2fc;
    unsigned int field300;
    unsigned int field304;
    unsigned int field308;
    unsigned int field30c;
    unsigned int field310;
    unsigned int field314;
    unsigned int field318;
    unsigned int field31c;
    unsigned int field320;
    unsigned int field324;
    unsigned int field328;
    unsigned int field32c;
    unsigned int field330;
    unsigned int field334;
    unsigned int field338;
    unsigned int field33c;
    unsigned int field340;
    unsigned int field344;
    unsigned int field348;
    unsigned int field34c;
    unsigned int field350;
    unsigned int field354;
    unsigned int field358;
    unsigned int field35c;
    unsigned int field360;
    unsigned int field364;
    unsigned int field368;
    unsigned int field36c;
    unsigned int field370;
    unsigned int field374;
    unsigned int field378;
    unsigned int field37c;
    unsigned int field380;
    unsigned int field384;
    unsigned int field388;
    unsigned int field38c;
    unsigned int field390;
    unsigned int field394;
    unsigned int field398;
    unsigned int field39c;
    unsigned int field3a0;
    unsigned int field3a4;
    unsigned int field3a8;
    unsigned int field3ac;
    unsigned int field3b0;
    unsigned int field3b4;
    unsigned int field3b8;
    unsigned int field3bc;
    unsigned int field3c0;
    unsigned int field3c4;
    unsigned int field3c8;
    unsigned int field3cc;
    unsigned int field3d0;
    unsigned int field3d4;
    unsigned int field3d8;
    unsigned int field3dc;
    unsigned int field3e0;
    unsigned int field3e4;
    unsigned int field3e8;
    unsigned int field3ec;
    unsigned int field3f0;
    unsigned int field3f4;
    unsigned int field3f8;
    unsigned int field3fc;
    unsigned int field400;
    unsigned int field404;
    unsigned int field408;
    unsigned int field40c;
    unsigned int field410;
    unsigned int field414;
    unsigned int field418;
    unsigned int field41c;
    unsigned int field420;
    unsigned int field424;
    unsigned int field428;
    unsigned int field42c;
    unsigned int field430;
    unsigned int field434;
    unsigned int field438;
    unsigned int field43c;
    unsigned int field440;
    unsigned int field444;
    unsigned int field448;
    unsigned int field44c;
    __m128 field450;
    unsigned int field460;
    unsigned int field464;
    unsigned int field468;
    unsigned int field46c;
    unsigned int field470;
    unsigned int field474;
    unsigned int field478;
    unsigned int field47c;
    unsigned int field480;
    unsigned int field484;
    unsigned int field488;
    unsigned int field48c;
    unsigned int field490;
    unsigned int field494;
    unsigned int field498;
    unsigned int field49c;
    __m128 field4a0;
    unsigned int field4b0;
    unsigned int field4b4;
    unsigned int field4b8;
    unsigned int field4bc;
    __m128 field4c0;
    __m128 field4d0;
    unsigned int field4e0;
    unsigned int field4e4;
    float field4e8;
    unsigned int field4ec;
    __m128 field4f0;
    unsigned int field500;
    unsigned int field504;
    unsigned int field508;
    unsigned int field50c;
    __m128 field510;
    unsigned int field520;
    unsigned int field524;
    unsigned int field528;
    unsigned int field52c;
    unsigned int field530;
    unsigned int field534;
    unsigned int field538;
    float field53c;
    unsigned int field540;
    unsigned int field544;
    unsigned int field548;
    float field54c;
    unsigned int field550;
    unsigned int field554;
    unsigned int field558;
    unsigned int field55c;
    float field560;
    float field564;
    unsigned int field568;
    unsigned int field56c;
    unsigned int field570;
    unsigned int field574;
    float field578;
    unsigned int field57c;
    float getScale() const
    {
        return field54c;
    }
    float getStep() const
    {
        return field4e8;
    }
    void bhkCharacterController_UpdateState();
    void bhkCharacterController_ApplyVelocityMod();
    void bhkCharacterProxy_MarkRead();
    __m128* hkpCharacterProxy_getPosition();
};

extern float DAT_012686e0;
void hkpCharacterMovementUtil_calculateMovement(void*, __m128*);
__forceinline void applyVelocityP(__m128& velocity, MotionState* o, const __m128& direction, float factor)
{
    SwimScale a(factor);
    __m128 g = _mm_mul_ps(a.splat(), direction);
    SwimScale b(o->getStep());
    velocity = _mm_add_ps(velocity, _mm_mul_ps(b.splat(), g));
}
__forceinline void applyVelocityN(__m128& velocity, MotionState* o, const __m128& direction, float factor)
{
    SwimScale a(factor);
    __m128 g = _mm_mul_ps(a.splat(), direction);
    SwimScale b(-o->getStep());
    velocity = _mm_add_ps(velocity, _mm_mul_ps(b.splat(), g));
}

struct Snapshot
{
    float weight;
    __m128 position, rotation, previous, velocity, factors;
    float scale;
    __m128 extra;
};
// @fnv 0x00cd44e0
// src: XBOX_PDB 0x00cd44e0
__declspec(noinline) void __stdcall bhkCharacterStateSwimming_Update(MotionState* object)
{
    Snapshot state;
    state.weight = 1.0f;
    state.position = object->field4d0;
    __m128 rotation = object->field4c0;
    state.rotation = rotation;
    state.velocity = object->field4f0;
    {
        const __m128* p = &object->field510;
        const __m128* q = reinterpret_cast<const __m128*>(&object->field500);
        float scratch;
        _mm_store_ss(&scratch, _mm_shuffle_ps(object->field510, object->field510, 0xaa));
        float z = scratch;
        _mm_store_ss(&scratch, *p);
        float x = scratch;
        float y;
        _mm_store_ss(&y, _mm_shuffle_ps(q[1], q[1], 0x55));
        state.factors = _mm_setr_ps(y, x, z, 0.0f);
    }
    state.scale = 100.0f;
    state.extra = object->field4a0;
    unsigned int f = *(unsigned int*)&object->field414;
    bool initialSupported = flag(f, 8) && flag(f, 8);
    if (initialSupported)
        state.previous = object->field450;
    else
        state.previous = rotation;
    __m128* __restrict velocity = &object->field4f0;
    hkpCharacterMovementUtil_calculateMovement(&state, velocity);
    __m128* parent = (__m128*)&DAT_01267e30;
    MotionState* parentObject = object->field008;
    if (parentObject)
    {
        object->bhkCharacterProxy_MarkRead();
        parent = parentObject->hkpCharacterProxy_getPosition();
        object->bhkCharacterProxy_MarkRead();
    }
    float height = altScalar(_mm_shuffle_ps(*parent, *parent, 0xaa)) - object->field578;
    if (object->field560 >= 0.5f)
        height += 0.5 * object->field564 * object->field560;
    object->GetBasis();
    __m128 direction = object->GetBasis()->y;
    object->GetBasis();
    {
        unsigned int* pf = (unsigned int*)&object->field414;
        *pf |= 0x400;
    }
    if (height > object->field53c)
    {
        if (object->field520 == 1)
        {
            object->bhkCharacterController_UpdateState();
            goto done;
        }
        if (altScalar(_mm_shuffle_ps(*velocity, *velocity, 0xaa)) > 0.0f)
        {
            object->field4f0.m128_f32[2] = 0.0f;
        }
        else
        {
            _ReadWriteBarrier();
        }
    }
    else if (object->field560 < 0.5f)
    {
        if (object->field520 == 1 && flag(object->field414, 10))
        {
            object->bhkCharacterController_UpdateState();
            goto done;
        }
        if (!(height < object->field53c - float(DAT_012686e0 * 10.0)))
            goto done;
        applyVelocityN(*velocity, object, direction, object->getScale());
        goto done;
    }
    else
    {
        if (object->field54c == 1.0f)
            goto done;
        unsigned int flags = object->field414;
        if (flag(flags, 8) || flag(flags, 9))
            goto done;
    }
    applyVelocityP(*velocity, object, direction, object->getScale());
done:
    object->bhkCharacterController_ApplyVelocityMod();
    if (object->field520 == 0)
        object->bhkCharacterController_UpdateState();
}
}  // namespace fnv_00cd44e0
