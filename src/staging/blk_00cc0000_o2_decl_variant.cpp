#include "../../include/NiTArray.h"

// src/staging/blk_00cc0000_o2_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00ccc440: the skeleton of src/staging/blk_00cc0000_o2.cpp
// with declarations corrected to what the original code does (unit: struct MM { void Deallocate(void*); }; -> struct MM { void Deallocate(void*); void* Allocate(unsigned ). Move the function to its real unit once
// that unit declares it this way.

// src/staging/blk_00cc0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/AutoMemContext.h"
#include "../../include/NiStream.h"
// bhkConstraintBaseSI_blk_00cc0000_o2_decl_variant: local type (was include/bhkConstraintBaseSI.h, which had no evidence of one real class); its methods are 0x00c8a230 hkConstraintCinfo::LoadBinary, 0x00c8a330 hkConstraintCinfo::LoadMotor (no shared hkConstraintCinfo header yet)
class hkRefObjSI;

struct ConstraintDataSI;
struct NiStreamSI;

class bhkConstraintBaseSI_blk_00cc0000_o2_decl_variant
{
public:
    void* m_pVtable;
    ConstraintDataSI* m_pData;

    void LoadBinaryBase(NiStream& kStream);
    hkRefObjSI* LoadMotorSI(NiStream& kStream);
    void LoadBinaryBase(NiStreamSI& kStream);
    hkRefObjSI* LoadMotorSI(NiStreamSI& kStream);
};
// bhkLimitedHingeVector_blk_00cc0000_o2_decl_variant: local type (was include/bhkLimitedHingeVector.h, which had no evidence of one real class); its methods are 0x004b4db0 bhkVector4::operator=
class bhkLimitedHingeVector_blk_00cc0000_o2_decl_variant
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
// bhkSaveOwner_blk_00cc0000_o2_decl_variant: local type (was include/bhkSaveOwner.h, which had no evidence of one real class); its methods are 0x00c9fc00 bhkConvexShape::SaveBinary, 0x00cd02d0 bhkConvexListShape::SaveBinary

class CountedOwner;
class SaveStreamFields;

class bhkSaveOwner_blk_00cc0000_o2_decl_variant
{
public:
    unsigned int unk00;
    int unk04;
    CountedOwner* m_pSharedOwner;

    int GetCount();
    void bhkConvexShape_SaveBinary(NiStream* stream);
    void SaveLinkedObjects(NiStream* stream);
    void bhkConvexShape_SaveBinary(SaveStreamFields* stream);
    void SaveLinkedObjects(SaveStreamFields* stream);
};
#include "../../include/BSFadeNode.h"
#include "../../include/StrArr.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/NiMatrix3.h"
#include "../../include/bhkConstraint.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkFixedConstraint.h"
#include "../../include/bhkGenericConstraint.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkArray.h"
#include "../../include/hkOstream.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkStreamWriter.h"
#include "../../include/NiTransform.h"
#include "../../include/bhkConvexShape.h"
#include "../../include/bhkConvexSweepShape.h"
#include "../../include/hkMatrix3.h"
#include "../../include/hkVector4.h"
#define FNV_TRANSFORM_NO_SSE
#include "../../include/Transform.h"
#undef FNV_TRANSFORM_NO_SSE
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
    void* Allocate(unsigned int size);
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
    bhkLimitedHingeVector_blk_00cc0000_o2_decl_variant m_kPointA;
    bhkLimitedHingeVector_blk_00cc0000_o2_decl_variant m_kPointB;
    bhkLimitedHingeVector_blk_00cc0000_o2_decl_variant m_iThirdValue;
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
void __fastcall hkpRagdollConstraintData_getTarget(char* self, int, char* arg);
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
    CC1AD0BinaryStreamSave(*kStream.m_pBackingStream, &value);
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
struct CC3320Vector
{
    void SetQuaternionComponentsFromVector(const float* pfValues);
};
struct CC3320Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC3320Vector m_kPivot;
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
struct S_00cc4b90_Alloc
{
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00cc4b90_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00cc4b90_Alloc* unk10;
    S_00cc4b90_Alloc& heap()
    {
        return *unk10;
    }
};
S_00cc4b90_Router* hkMemoryRouter_getInstance() throw();
extern float DAT_01017b78;
struct S_00cc4b90_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00cc4b90_RefObj();
    void* operator new(unsigned int n)
    {
        S_00cc4b90_RefObj* b = static_cast<S_00cc4b90_RefObj*>(hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(n));
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
    CC5DD0BinaryStreamSave(*kStream.m_pBackingStream, &value);
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
struct NiStreamSI
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
    NiBinaryStreamSI* m_pUnderlyingStream;
};
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
struct FUN_00cc7a40_class : bhkConstraintBaseSI_blk_00cc0000_o2_decl_variant
{
    void hkPrismaticConstraintCinfo_LoadBinary(NiStreamSI& kStream);
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
template <class T> inline void SerializeValue(NiStream& stream, const T& value)
{
    unsigned int size = sizeof(T);
    stream.m_pkOstr->BinaryWrite(&value, size, &size, 1);
}
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
    hkReferencedObject* m_pPointer;
    FUN_00cc9d00(int a, int b, hkReferencedObject* pkObject);
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
// 0x00ccf350 reads a link at +0x18 and a physics transform at +0x20; Data.h defines neither.
struct PhysicsTransformShapeView
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Link403* link;
    int unk1c;
    Transform transform;
};
extern Transform DAT_01268370;
extern const char* g_012686b0;
extern const char g_010c6050[], g_010c604c[];
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
void __cdecl HK2NI_00624b10(NiTransform*, const Transform*);
void __cdecl FUN_00458620(NiPoint3*, const hkVector4*);
struct Holder403
{
    int unk00, unk04;
    PhysicsTransformShapeView* data;
    void bhkConvexShape_GetViewerStrings(StrArr*);
    const Transform& GetTransform() const
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
struct CC61F0ConstraintBase
{
    int unk00;
    CC61F0ConstraintData* m_pUserData;
    void LoadBinaryBase(CC61F0Stream& kStream);
};
struct FUN_00cc61f0_class : CC61F0ConstraintBase
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
    CCC920BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
template <class T> inline void CCC920SaveBinary(CCC920Stream& kStream, const T* pValues, unsigned int ItemUpdateArray)
{
    CCC920BinaryStreamSave(*kStream.m_pBackingStream, pValues, ItemUpdateArray);
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
    ShapeCCD(const ShapeCinfoCCD& kCinfo, const hkArray<hkVector4>& planes, float fRadius);

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
    // The constructor at 0x00d59bd0 takes an hkArray<hkVector4> at +0x14, not a Vector.
    hkArray<hkVector4> m_kPlanes;
    int unk20;
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
struct CE340Vec4
{
    float x, y, z, w;
};
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
    CE340Array<CE340Vec4> m_arr08;
    CE340Array<CE340Vec4> m_arr14;
};
typedef FUN_00ccd3a0_arg CE340Stream;
void __cdecl bhkStream_SwapHKArray(CE340Data* data, void* ctx, CE340Array<CE340Vec4>* arr);
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
struct hkMemoryAllocStub
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void deallocateChunk(void* p, int nbytes);
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
struct SaveStreamStub
{
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
    virtual void SaveLinkID(void* obj);
};
struct SaveStreamFields : SaveStreamStub
{
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
    unsigned char m_bUnk1E4;
    unsigned char unk1E5;
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
    int unk24C;
    NiBinaryStream* m_pOstr;
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
    __forceinline void reserve(S_00cc4b90_Alloc& alloc, int n)
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
struct AGStream : SaveStreamFields
{
    void NiStream_ReadMultipleLinkIDs();
};
struct AGOwner : bhkSaveOwner_blk_00cc0000_o2_decl_variant
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
// 0x00cd2a10 searches 16-byte entries by the +0 key and replaces the two-word value at +8; no shared hkEntry exists.
struct CollisionFilterPairEntry
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
    CollisionFilterPairEntry* m_entries;
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

inline void* __cdecl operator new[](unsigned int size)
{
    return g_memoryManager.Allocate(size);
}
struct MeshMetadata654
{
    unsigned int a, b;
    static void* operator new(unsigned int size)
    {
        char* p = (char*)g_memoryManager.Allocate(size + 16);
        unsigned char offset = (unsigned char)(16 - ((unsigned char)(unsigned int)p & 15));
        p += offset;
        p[-1] = offset;
        return p;
    }
    MeshMetadata654(unsigned int x, unsigned int y)
    {
        b = y;
        a = x;
    }
};
struct Mesh654
{
    unsigned int vertexCount;
    float* vertices;
    unsigned int triangleCount;
    unsigned short* triangles;
    MeshMetadata654* metadata;
    void bhkExtendedMeshShapeData_Block_LoadBinary(BCC9B80Stream&);
};
// @fnv 0x00ccc440
// src: COMMUNITY 0x00ccc440
void Mesh654::bhkExtendedMeshShapeData_Block_LoadBinary(BCC9B80Stream& stream)
{
    TlsFlagGuard guard;
    BCC9B80LoadBinary(stream, vertexCount);
    vertices = new float[vertexCount * 3];
    BCC9B80BinaryStreamLoad(*stream.m_pUnderlyingStream, vertices, vertexCount * 3);
    BCC9B80LoadBinary(stream, triangleCount);
    triangles = new unsigned short[triangleCount * 3];
    BCC9B80BinaryStreamLoad(*stream.m_pUnderlyingStream, triangles, triangleCount * 3);
    unsigned int a, b;
    BCC9B80LoadBinary(stream, b);
    BCC9B80LoadBinary(stream, a);
    metadata = new MeshMetadata654(b, a);
}
