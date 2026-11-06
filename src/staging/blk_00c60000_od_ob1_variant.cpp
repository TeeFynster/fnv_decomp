#include "../../include/NiPointer.h"
#include "../../include/NiTListItem.h"
#include "../../include/NiTArray.h"

// src/staging/blk_00c60000_od_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/staging/blk_00c60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00c60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include <stddef.h>
#include <string.h>
#pragma intrinsic(memcpy)
#include "../../include/BSDecalPlacementVectorExtraData.h"
#include "../../include/BSFaceGenMorphData.h"
#include "../../include/BSPSysSimpleColorModifier.h"
#include "../../include/Mat3.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiAllocator.h"
#include "../../include/NiBinaryExtraData.h"
#include "../../include/NiColorA.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiObject.h"
#include "../../include/NiPSysCylinderEmitter.h"
#include "../../include/NiPSysModifier.h"
#include "../../include/NiPSysPositionModifier.h"
#include "../../include/NiPSysVolumeEmitter.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiStream.h"
#include "../../include/StrMem.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; with NiPoint3 (its in-class inline bodies, no stand-in constructor/operators), 0x00c63c30 does not match.
#include "../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void FUN_00416870(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool FUN_004390c0(const LocalVec3* other);
    bool FUN_004390c0(const LocalVec3* other) const;
    bool FUN_004390c0(const char* other);
    void FUN_00439180(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void FUN_00439ef0();
    LocalVec3 FUN_00439ef0(const LocalVec3& other);
    LocalVec3 FUN_00439ef0(const LocalVec3& other) const;
    LocalVec3 FUN_00439ef0(LocalVec3* other);
    LocalVec3 FUN_00439ef0(const LocalVec3* other);
    void FUN_00439ef0(LocalVec3* output, const LocalVec3* other);
    LocalVec3* FUN_00439ef0(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void FUN_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 FUN_0053d280(float divisor);
    float FUN_00589850();
    float FUN_00589850() const;
    void FUN_0063c8a0(const LocalVec3* other);
    void FUN_0063c8a0(void* other);
    void FUN_006815c0();
    float FUN_00b04d40(LocalVec3* other);
    float FUN_00b04d40(const LocalVec3& other) const;
    LocalVec3 FUN_00b05000(const Mat& matrix);
    LocalVec3 FUN_00b05000(const Matrix4* matrix);
    void FUN_00b12790();
    LocalVec3 FUN_00b13040(void* other);
    LocalVec3 FUN_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& FUN_00b2a1c0(void* other);
    void FUN_00ddc870();
    void FUN_00e0f6e0();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

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
template <class T> inline bool operator==(const NiPointer<T>& lhs, const NiPointer<T>& rhs)
{
    return lhs.m_pObject == rhs.m_pObject;
}
template <class T> inline bool operator!=(const NiPointer<T>& lhs, const NiPointer<T>& rhs)
{
    return lhs.m_pObject != rhs.m_pObject;
}
extern "C" void* g_01204388;
struct FUN_00c600f0_Class
{
    void* __thiscall FUN_00c600f0();
};
extern "C" void* g_01204390;
struct FUN_00c60d40_Class
{
    void* __thiscall FUN_00c60d40();
};
struct FUN_00c61420_Class
{
    void* __thiscall FUN_00c61420(void* p);
};
struct FUN_00a99870_Class
{
    void __thiscall FUN_00a99870(int, int);
};
void __thiscall FUN_00a99870_Class::FUN_00a99870(int, int)
{}
struct FUN_00c61430_Class
{
    void __thiscall FUN_00c61430(int, int);
};
struct FUN_00c61450_Class
{
    void FUN_00a99a90(int);
    void FUN_00c61450(int a);
};
struct FUN_00a9af00_class
{
    void FUN_00a9af00(int a);
};
struct FUN_00c61470_class : FUN_00a9af00_class
{
    void CallBaseWithArg(int a);
};
struct FUN_00c61490_Class
{
    bool FUN_00a89ae0(const void* arg);
    bool IsNot(const void* arg);
};
struct FUN_00c614c0_Class
{
    void __thiscall FUN_00a89210(void*);
    void __thiscall FUN_00c614c0(void* ap);
};
struct FUN_00c614e0_Class
{
    char FUN_00a998e0(int arg);
    char FUN_00c614e0(int arg);
};
extern NiFixedString* DAT_012043a0;
extern "C" void* g_012043a4;
struct FUN_00c61810_class
{
    void* FUN_00c61810();
};
struct FUN_00c61820_class
{
    void* FUN_00c61820(int);
};
struct FUN_00c61f60_class
{
    void __thiscall FUN_00c2f4f0(int);
    void __thiscall FUN_00c61f60(int);
};
struct FUN_00c61f80_cls
{
    void FUN_00c31b60(void* apParam);
    void FUN_00c61f80(void* apParam);
};
struct FUN_00c627e0_Class
{
    void __thiscall FUN_00c62140();
    void __thiscall FUN_00c627e0(void* p);
};
extern "C" void* g_012043b8;
struct FUN_00c632e0_Class
{
    void* __thiscall FUN_00c632e0();
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
void __cdecl FUN_00c63c30(int, int);
void __cdecl CallWithSameArgumentTwice(int a);
struct FUN_00c644d0_Class
{
    unsigned char Equals(const char*);
    unsigned char FUN_00c644d0(const char*);
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
    bool FUN_00c65290(int a);
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
    void* __thiscall FUN_00c5fd50();
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
    void __thiscall FUN_00c63970(void* stream);
};
void __cdecl FUN_00c63b40(void* p);
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c64930_Class
{
    void FUN_00c64930(int a);
};
struct FUN_00c64940_Class
{
    bool FUN_00c64940(int a);
};
struct FUN_00c64c30_Class
{
    bool __thiscall FUN_00c64c30(int a);
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
int _sprintf_s(char*, unsigned int, const char*, ...);
size_t _strlen(const char*);
struct FUN_00c62090_Class
{
    char* __thiscall BuildAttachTypeString(const char* name, int type);
};
extern GlobalObject_00a7b610 g_012043b0;
struct FUN_00c63320_Class
{
    GlobalObject_00a7b610* __thiscall FUN_00c63320();
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
    void __thiscall FUN_00c65210(NiStream& stream);
};
void __cdecl FUN_0044adf0(NiStream& stream, const unsigned int& count);
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
FUN_00c61b10* FUN_00c61e70();
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
    void FUN_00c64780(const char* apName);
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
    void FUN_00c60700(NiPSysModifier* dst, CloningProcess& proc);
};
template <class T> void __cdecl ReadBinaryValue(NiStream& stream, T& value);
struct FUN_00c60850_Class : public NiPSysModifier
{
    void FUN_00c60850(NiStream& stream);
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

    bool __thiscall FUN_00c60a10(NiObject*);
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
NiAVObject* __cdecl FUN_00c61510();
struct FUN_00a7b330_shell
{
    void FUN_00a7b330(void* a, void* b);
};
struct FUN_00c61830_class
{
    void FUN_00c61830(void* a, void* b);
};
struct FUN_00c62390_class
{
    void FUN_00c62390(void*, void*);
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
struct FUN_00c64500_Class : FUN_00c61490_Class
{
    bool FUN_00c64500(const void* arg);
};
struct A46BB0Object
{
    bool IsEqual(A46BB0Object*);
};
int __cdecl __stricmp(const char*, const char*);
struct FUN_00c64980_Class : A46BB0Object
{
    bool FUN_00c64980(A46BB0Object* arg);
};
struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* FUN_0043ba10(unsigned int);
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
    FUN_0043ba10_shell* FUN_00c64dc0(unsigned int a);
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c64e70_Class
{
    void __thiscall FUN_00c64e70();
    void* __thiscall FUN_00c65650(unsigned int flags);
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct SpawnedObject_b9118
{
    char m00[0x60];
    SpawnedObject_b9118();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
SpawnedObject_b9118* FUN_00c607d0();
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
    void SetSize(unsigned int n);
    void FUN_00c62b90(unsigned int n, unsigned int* p);
};
struct FUN_00c61c50_cls
{
    unsigned int pad0[0x18];
    unsigned int* m_60;
    unsigned short pad1[1];
    unsigned short m_66;
    void FUN_00c31b10(unsigned int a, unsigned int b);
    void FUN_00c61c50(unsigned int x, unsigned int y);
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
    void FUN_00a59c60(FUN_00c62140_Val* pVal);
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
    void FUN_00c62f40();
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

    void FUN_00c62140();
    void FUN_00c62200(FUN_00c62140_Elem* pElem);
};
struct S_00c62cc0_Class
{
    void* unk0;
    void* unk4;
    unsigned short m_8;
    unsigned short m_kPointA;
    unsigned short unk_c;
    unsigned short m_usTrailingValue;

    void SetSize(unsigned int arg);
    void FUN_00c62b90(unsigned int arg1, unsigned int arg2);
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
    void FUN_00c634b0(XObj70* a1, unsigned short idx);
};
struct FUN_00c63780_c
{
    int pad[9];
    NiPoint3 v;
    void ResetVector();
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct PositionModifierObject_b9439
{
    char m00[0x3c];
    PositionModifierObject_b9439();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
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
    void FUN_00c63a00(ArgObj* a1);
};
unsigned int __cdecl FUN_00a7d330(unsigned int v);
unsigned int __cdecl FUN_00a7d550(const char* name, float f);
struct S_00c643d0_Foo
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    unsigned short m_uiItemCount;
    void* m_entries[16];

    void __thiscall FUN_00a9a4e0(int arg);
    void __thiscall FUN_00c643d0(int arg);
};
extern "C" void __cdecl FUN_00a303a0(int arg, void* object);
extern "C" void __cdecl FUN_00a417b0(int arg, void* data, int count);
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
    void FUN_00c64b90(FUN_00c64b90_target* a1);
    void FUN_00a89af0(FUN_00c64b90_target* a1);
};
void __cdecl FUN_0044adf0(FUN_00c64b90_target* a1, unsigned int* p);
struct FUN_00c64da0_cls
{
    int unk00;
    void Callee0043ba10(int a);
    void FUN_00c64da0(int a);
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
    void FUN_00c65490(int a1, int a2);
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

extern char* DAT_0109b220;
extern int DAT_010c3384;
// These inline bodies belong to this unit's original /Ob1 implementation.
inline NiFixedString::operator const char*() const
{
    return m_kHandle;
}

// NiPSysModifier.h lacks the (NiFixedString const&, unsigned int) constructor.
struct Base316
{
    virtual void vf0();
    int unk04, unk08, unk0c, unk10, unk14;
    Base316(const NiFixedString&, unsigned int);
};
struct FUN_00c60100 : Base316
{
    NiColorA first, second, third;
    float f48, f4c, f50, f54, f58, f5c;
    FUN_00c60100(const char*, const NiColorA&, const NiColorA&, const NiColorA&, float, float, float, float, float,
                 float);
};
// @fnv 0x00c60100
FUN_00c60100::FUN_00c60100(const char* name, const NiColorA& c1, const NiColorA& c2, const NiColorA& c3, float a,
                           float b, float c, float d, float e, float f)
    : Base316(NiFixedString(name), 3000), first(c1), second(c2), third(c3), f48(a), f4c(b), f50(c), f54(d), f58(e),
      f5c(f)
{}

struct EmitBaseB10
{
    virtual ~EmitBaseB10();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    unsigned int unk44, unk48, unk4c, unk50, unk54;
    EmitBaseB10();
};
struct PrimArrayBaseB10
{
    virtual ~PrimArrayBaseB10();
    void* m_data;
    unsigned short m_pRayCursor, m_iElementCount, m_uiItemCount, m_growBy;
    PrimArrayBaseB10(unsigned short initial, unsigned short grow)
    {
        m_pRayCursor = initial;
        m_growBy = grow;
        m_iElementCount = 0;
        m_uiItemCount = 0;
        if (m_pRayCursor > 0)
        {
            unsigned int uiBytes = m_pRayCursor * 4;
            m_data = NiMalloc(uiBytes);
        }
        else
            m_data = 0;
    }
};
template <class T> struct PrimArrayB10 : PrimArrayBaseB10
{
    PrimArrayB10(unsigned short capacity = 0, unsigned short grow = 1) : PrimArrayBaseB10(capacity, grow)
    {}
};
namespace emitB10 {
struct FUN_00c61b10 : EmitBaseB10
{
    unsigned int unk58;
    PrimArrayB10<void*> m_kThirdFollowingStreamField;
    virtual ~FUN_00c61b10();
    FUN_00c61b10();
};
// @fnv 0x00c61b10
FUN_00c61b10::FUN_00c61b10() : unk58(2), m_kThirdFollowingStreamField(0, 1)
{}
}

extern char* g_pcEmptyString;

// The named position-modifier constructor and its state are absent from the shared headers.
class NiPSysPositionModifierBase
{
  public:
    NiPSysPositionModifierBase(const NiFixedString& kName, unsigned int uiOrder);
    virtual void v00();
    unsigned int m_04;
    char* m_pcName;
    unsigned int m_uiUpdateOrder;
    unsigned int m_uiValue1;
    unsigned char m_14;
    unsigned char m_15;
    unsigned char m_16;
    unsigned char m_17;
};
class FUN_00c633b0 : public NiPSysPositionModifierBase
{
  public:
    FUN_00c633b0(const char* pcName);
    float m_f18;
    int m_1c;
    float m_f20;
    NiPoint3 m_kPoint24;
    NiPoint3 m_kPoint30;
};
// @fnv 0x00c633b0
FUN_00c633b0::FUN_00c633b0(const char* pcName) : NiPSysPositionModifierBase(NiFixedString(pcName), 0xbb8)
{
    m_kPoint24 = NiPoint3::ZERO;
    m_kPoint30 = NiPoint3::ZERO;
    m_f20 = 0.0f;
    m_f18 = 0.0f;
}

inline const char* NiRTTI::GetName() const
{
    return m_pcName;
}
extern const NiRTTI DAT_011f4428;

char* __cdecl FUN_00a7d330(const char* pcText);
void* NiMalloc645(unsigned int uiSize);
void NiFree645(void* p);

template <class T> struct PrimArray645
{
    void* m_vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    static T* Allocate(unsigned int auiCount)
    {
        return (T*)NiMalloc645(sizeof(T) * auiCount);
    }
    void SetSize(unsigned int uiMaxSize)
    {
        if (uiMaxSize == m_usMaxSize)
            return;
        unsigned int i;
        if (uiMaxSize < m_usSize)
        {
            for (i = uiMaxSize; i < m_usSize; i++)
            {
                if (m_pBase[i] != T(0))
                {
                    m_pBase[i] = T(0);
                    m_usESize--;
                }
            }
            m_usSize = (unsigned short)uiMaxSize;
        }
        T* pSaveBase = m_pBase;
        m_usMaxSize = (unsigned short)uiMaxSize;
        if (uiMaxSize > 0)
        {
            m_pBase = Allocate(m_usMaxSize);
            for (i = 0; i < m_usSize; i++)
                m_pBase[i] = pSaveBase[i];
            for (i = m_usSize; i < m_usMaxSize; i++)
                m_pBase[i] = T(0);
        }
        else
        {
            m_pBase = 0;
        }
        NiFree645(pSaveBase);
    }
    void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != T(0))
                m_usESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int FUN_0096a610(const T& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};
typedef PrimArray645<char*> ViewerStrings645;

struct Parent645
{
    void FUN_00a99d70(ViewerStrings645* pkStrings);
};

struct Obj645 : Parent645
{
    void FUN_00c645c0(ViewerStrings645* pkStrings);
};

// @fnv 0x00c645c0
void Obj645::FUN_00c645c0(ViewerStrings645* pkStrings)
{
    Parent645::FUN_00a99d70(pkStrings);
    pkStrings->FUN_0096a610(FUN_00a7d330(DAT_011f4428.GetName()));
}

extern const char* DAT_012043ec;
void* NiMalloc64d(unsigned int uiSize);

struct ModBase64d
{
    virtual void V00();
    int m_04;
    int m_08;
    ModBase64d(const char* pcName);
    ~ModBase64d();
};

struct ArrBase64d
{
    virtual void V00();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    static void* Allocate(unsigned int auiCount)
    {
        return NiMalloc64d(4 * auiCount);
    }
    ArrBase64d(unsigned int uiMaxSize, unsigned int uiGrowBy)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
        {
            m_pBase = Allocate(m_usMaxSize);
        }
        else
        {
            m_pBase = 0;
        }
    }
};

struct Arr64d : ArrBase64d
{
    Arr64d(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) : ArrBase64d(uiMaxSize, uiGrowBy)
    {}
    virtual void V00();
};

inline const char* GetDefaultName64d()
{
    return DAT_012043ec;
}

struct FUN_00c64de0 : ModBase64d
{
    Arr64d m_kArray;
    FUN_00c64de0();
    virtual void V00();
};

// @fnv 0x00c64de0
FUN_00c64de0::FUN_00c64de0() : ModBase64d(GetDefaultName64d())
{}

struct ViewerStrings
{
    void FUN_0096a610(const unsigned int& s);
};

namespace fnv_00c60b20 {
extern const char str_010c3494[];
extern const char str_010c3480[];
extern const char str_010c3470[];
extern const char str_010c345c[];
extern const char str_010c3450[];
extern const char str_010c3440[];
extern const char str_010c3438[];
extern const char str_010c3430[];
extern const char str_010c3428[];

struct RTTI_Stub
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};

char* __cdecl FUN_00a7d330(const char* name);

unsigned int __cdecl strlen(const char*);
void* __cdecl FUN_00aa1070(unsigned int);
int __cdecl FUN_00a305b0(char*, unsigned int, const char*, ...);
extern const char str_0109dcec[];
extern const char str_0109c360[];
inline unsigned int __cdecl FUN_00a7d550(const char* label, float value)
{
    unsigned int length = strlen(label) + 20;
    char* result = static_cast<char*>(FUN_00aa1070(length));
    FUN_00a305b0(result, length, str_0109dcec, value);
    return reinterpret_cast<unsigned int>(result);
}

extern const char str_0109dca0[];
inline char* __cdecl FUN_00a7d330(const char* name)
{
    char* result = static_cast<char*>(FUN_00aa1070(strlen(name) + 9));
    FUN_00a305b0(result, strlen(name) + 9, str_0109dca0, name);
    return result;
}

struct ModifierBase_Stub
{
    void FUN_00c319e0(ViewerStrings* strings);
};
}  // namespace fnv_00c60b20

// NiColorA::GetViewerString (0x00a69720), inlined by this unit's original.
inline char* NiColorA::GetViewerString(const char* label) const
{
    using namespace fnv_00c60b20;
    unsigned int length = fnv_00c60b20::strlen(label) + 36;
    char* result = static_cast<char*>(fnv_00c60b20::FUN_00aa1070(length));
    fnv_00c60b20::FUN_00a305b0(result, length, str_0109c360, r, g, b, a);
    return result;
}

// @fnv 0x00c60b20
void BSPSysSimpleColorModifier::FUN_00c60b20(ViewerStrings* strings)
{
    using namespace fnv_00c60b20;
    reinterpret_cast<ModifierBase_Stub*>(this)->FUN_00c319e0(strings);
    strings->FUN_0096a610((unsigned int)fnv_00c60b20::FUN_00a7d330(reinterpret_cast<RTTI_Stub*>(&g_01204390)->GetName()));
    strings->FUN_0096a610((unsigned int)fnv_00c60b20::FUN_00a7d550(str_010c3494, color1End * 100.0));
    strings->FUN_0096a610((unsigned int)fnv_00c60b20::FUN_00a7d550(str_010c3480, color2Start * 100.0));
    strings->FUN_0096a610((unsigned int)fnv_00c60b20::FUN_00a7d550(str_010c3470, color2End * 100.0));
    strings->FUN_0096a610((unsigned int)fnv_00c60b20::FUN_00a7d550(str_010c345c, color3Start * 100.0));
    strings->FUN_0096a610((unsigned int)fnv_00c60b20::FUN_00a7d550(str_010c3450, fadeIn * 100.0));
    strings->FUN_0096a610((unsigned int)fnv_00c60b20::FUN_00a7d550(str_010c3440, fadeOut * 100.0));
    strings->FUN_0096a610((unsigned int)color1.GetViewerString(str_010c3438));
    strings->FUN_0096a610((unsigned int)color2.GetViewerString(str_010c3430));
    strings->FUN_0096a610((unsigned int)color3.GetViewerString(str_010c3428));
}

void* NiMalloc(unsigned int size);
void NiFree(void* p);

struct CmpRefObject
{
    virtual ~CmpRefObject();
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

struct CmpPtr
{
    CmpRefObject* m_pObject;
    CmpPtr(CmpRefObject* object = 0)
    {
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~CmpPtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    CmpPtr& operator=(const CmpPtr& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator!=(const CmpPtr& other) const
    {
        return m_pObject != other.m_pObject;
    }
};

inline CmpPtr* CmpPtrArrayAllocate(unsigned int count) { return (CmpPtr*)NiMalloc(sizeof(CmpPtr) * count); }
typedef NiTArray<CmpPtr, NiTMallocInterface<CmpPtr> > CmpPtrArray;


// @fnv 0x00c63030
template <> void NiTArray<CmpPtr, NiTMallocInterface<CmpPtr> >::Compact()
{
    if (m_usESize == m_usSize)
        return;

    if (m_usESize)
    {
        for (unsigned short i = 0, j = 0; i < m_usSize; i++)
        {
            if (m_pBase[i] != CmpPtr(0))
            {
                if (m_pBase[j] != m_pBase[i])
                    m_pBase[j] = m_pBase[i];
                j++;
            }
        }
    }

    CmpPtr* pSaveBase = m_pBase;
    m_usMaxSize = m_usSize = m_usESize;
    if (m_usMaxSize > 0)
    {
        m_pBase = CmpPtrArrayAllocate(m_usMaxSize);
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pSaveBase);
}

extern unsigned char DAT_011f426c;
inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
{}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& b) const
{
    return NiPoint3(x - b.x, y - b.y, z - b.z);
}
inline NiPoint3 NiPoint3::operator/(float f) const
{
    float reciprocal = 1.0f / f;
    return NiPoint3(x * reciprocal, y * reciprocal, z * reciprocal);
}
__forceinline bool NiPoint3::operator==(const NiPoint3& b) const
{
    return x == b.x && y == b.y && z == b.z;
}
inline NiPoint3 operator*(float f, const NiPoint3& b)
{
    return NiPoint3(f * b.x, f * b.y, f * b.z);
}
namespace fnv_00c63520 {
extern unsigned char DAT_011f426c;
extern unsigned char DAT_011f4270;
extern unsigned char DAT_011f4274;
struct MovingObject
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
    NiPoint3 position;
};
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    MovingObject* object;
    inline MovingObject* GetObject() const
    {
        const Owner* source = this;
        return source->object;
    }
};
struct Particle
{
    NiPoint3 position;
    int unk0c, unk10, unk14, unk18;
};
struct System
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
    unsigned short count;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Particle* particles;
    __forceinline unsigned short GetCount() const
    {
        return count;
    }
};
struct Modifier
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
    virtual void Reset();
    int unk04, unk08, unk0c;
    Owner* owner;
    int unk14;
    float elapsed, lastTime, scale;
    NiPoint3 previous, offset;
    void FUN_00c63520(float time, System* system);
};
// @fnv 0x00c63520
void Modifier::FUN_00c63520(float time, System* system)
{
    if (!system->GetCount())
        return;
    MovingObject* object5 = owner->GetObject();
    if (!object5)
    {
        Reset();
        return;
    }
    if (static_cast<const NiPoint3&>(previous) == (*reinterpret_cast<const NiPoint3*>(&DAT_011f426c)))
    {
        offset = (*reinterpret_cast<const NiPoint3*>(&DAT_011f426c));
        lastTime = time;
        previous = object5->position;
    }
    unsigned int count2 = system->GetCount();
    NiPoint3 position = object5->position;
    float delta8 = time - lastTime;
    if (delta8 != 0.0)
    {
        NiPoint3 movement = (scale * (position - previous)) / delta8;
        NiPoint3 difference2 = movement - offset;
        if (difference2 != (*reinterpret_cast<const NiPoint3*>(&DAT_011f426c)))
        {
            Particle* particle = system->particles;
            while (count2--)
            {
                particle->position += difference2;
                ++particle;
            }
        }
        offset = movement;
    }
    elapsed = delta8;
    lastTime = time;
    previous = position;
}

}  // namespace fnv_00c63520

extern MemoryManager DAT_011f6238;
struct FUN_00c64640
{
    unsigned short m_usPassCountLocal;
    short pad;
    NiPoint3 a[8];
    NiPoint3 b[8];
    FUN_00c64640();
    static void* operator new(unsigned n)
    {
        return DAT_011f6238.Allocate(n);
    }
};
struct BaseX
{
    void FUN_00a99c40(BaseX* p, int a);
};
struct ObjX : BaseX
{
    int pad[4];
    unsigned short m10;
    FUN_00c64640* m14[1];
    void FUN_00c640f0(ObjX* p, int a);
};
inline void DbgX()
{
    const char* a;
    const char* b;
    const char* c;
    const char* d;
    const char* e;
}
// @fnv 0x00c640f0
void ObjX::FUN_00c640f0(ObjX* p, int a)
{
    FUN_00a99c40(p, a);
    p->m10 = m10;
    for (int i = 0; i < m10; i++)
    {
        p->m14[i] = new FUN_00c64640;
        p->m14[i]->m_usPassCountLocal = m14[i]->m_usPassCountLocal;
        for (int j = 0; j < m14[i]->m_usPassCountLocal; j++)
        {
            p->m14[i]->a[j] = m14[i]->a[j];
            p->m14[i]->b[j] = m14[i]->b[j];
        }
    }
    DbgX();
}

namespace fnv_00c64270 {
extern MemoryManager DAT_011f6238;
void FUN_00a30370(NiStream& kStream, unsigned short* pusVal);
void ReadElements(NiStream& kStream, float* pfVals, unsigned int ItemUpdateArray);
inline void ReadPointsFromFile(NiStream& kStream, NiPoint3* pkPts, unsigned int uiElementCount)
{
    ReadElements(kStream, &pkPts->x, uiElementCount * 3);
}
struct FUN_00c64640
{
    unsigned short m_usNum;
    NiPoint3 m_akA[8];
    NiPoint3 m_akB[8];
    FUN_00c64640();
    static void* operator new(unsigned int uiSize)
    {
        int aiD[5];
        return DAT_011f6238.Allocate(uiSize);
    }
    static void operator delete(void* pv);
};
struct BaseY
{
    void FUN_00a99d30(NiStream& kStream);
    int m_ai[4];
};
struct ObjY : BaseY
{
    unsigned short m_usElementCount;
    FUN_00c64640* m_apRecs[1];
    void FUN_00c64270(NiStream& kStream);
};
// @fnv 0x00c64270
void ObjY::FUN_00c64270(NiStream& kStream)
{
    FUN_00a99d30(kStream);
    FUN_00a30370(kStream, &m_usElementCount);
    for (int i = 0; i < m_usElementCount; i++)
    {
        m_apRecs[i] = new FUN_00c64640;
        FUN_00a30370(kStream, &m_apRecs[i]->m_usNum);
        ReadPointsFromFile(kStream, m_apRecs[i]->m_akA, m_apRecs[i]->m_usNum);
        ReadPointsFromFile(kStream, m_apRecs[i]->m_akB, m_apRecs[i]->m_usNum);
    }
}
}  // namespace fnv_00c64270

namespace fnv_00c65040 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pl);
extern char* DAT_0109b220;
void FUN_00a26df0(NiStream& kStream, unsigned int& uiVal);
struct MapX
{
    void FUN_00c4c920(unsigned int uiSize);
};
struct BaseX
{
    void FUN_00a7b4a0(NiStream& kStream);
};
struct ObjM : BaseX
{
    int m_i0, m_i4, m_i8;
    MapX m_kFormatEntries;
    void FUN_00c65490(NiFixedString& kKey, NiFixedString& kVal);
    void Insert(NiFixedString& kKey, NiFixedString& kVal)
    {
        int aiD[3];
        FUN_00c65490(kKey, kVal);
    }
    void FUN_00c65040(NiStream& kStream);
};
// @fnv 0x00c65040
void ObjM::FUN_00c65040(NiStream& kStream)
{
    FUN_00a7b4a0(kStream);
    unsigned int ItemUpdateArray = 0;
    FUN_00a26df0(kStream, ItemUpdateArray);
    m_kFormatEntries.FUN_00c4c920(ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        NiFixedString kKey;
        NiFixedString kVal;
        kStream.ReadStringTableEntry(kKey);
        kStream.ReadStringTableEntry(kVal);
        Insert(kKey, kVal);
    }
}
}  // namespace fnv_00c65040

// BSWArray derives from NiIntegersExtraData, which owns a count and int buffer.
// The shared no-argument NiExtraData constructor does not bind to the required 0x00a7b2e0.
struct ExtraData244
{
    virtual ~ExtraData244();
    int references;
    void* name;
    ExtraData244();
};
struct IntegerExtraData244 : ExtraData244
{
    unsigned int count;
    int* values;
    virtual ~IntegerExtraData244();
    IntegerExtraData244()
    {
        values = 0;
        count = 0;
    }
};
struct FUN_00c612b0 : IntegerExtraData244
{
    virtual ~FUN_00c612b0();
    void FUN_00c61610();
    FUN_00c612b0();
};
// @fnv 0x00c612b0
FUN_00c612b0::FUN_00c612b0()
{
    FUN_00c61610();
}

struct C616Node
{
    int m_unk00;
    C616Node* m_pNext;
};

extern NiFixedString* DAT_012043a0;
extern "C" void* g_012043a4;

inline bool C616Contains(C616Node* node)
{
    while (node != 0)
    {
        if ((void*)node == (void*)&g_012043a4)
            return true;
        node = node->m_pNext;
    }
    return false;
}

// @fnv 0x00c61630
void* FUN_00c61630(NiAVObject* host)
{
    void* result2 = 0;
    if (host != 0)
    {
        NiFixedString* key = DAT_012043a0;
        NiExtraData* obj2 = host->FUN_00a5bdd0(*key);
        if (obj2 == 0)
        {
            result2 = 0;
        }
        else
        {
            result2 = C616Contains(reinterpret_cast<C616Node*>(const_cast<NiRTTI*>(obj2->GetRTTI()))) ? (void*)obj2 : 0;
        }
    }
    return result2;
}

namespace fnv_00c616c0 {
extern MemoryManager DAT_011f6238;
}
__forceinline void* NiFixedString::operator new(size_t size)
{
    return fnv_00c616c0::DAT_011f6238.Allocate(size);
}
namespace fnv_00c616c0 {
extern char str_010c3610[];
extern "C" void* g_0109b220;

char* __cdecl FUN_00a5b690(const char* arg);

extern "C" void* g_012043a0;

// @fnv 0x00c616c0
void __cdecl FUN_00c616c0()
{
    g_012043a0 = new NiFixedString(static_cast<const char*>(str_010c3610));
}
}  // namespace fnv_00c616c0


struct SubBase
{
    SubBase(unsigned short x, unsigned short y);
    virtual ~SubBase();
    int m_data;
    unsigned short m_uiX;
    unsigned short m_uiY;
};

struct SubObj : SubBase
{
    SubObj() : SubBase(0, 1)
    {}
    virtual ~SubObj();
};

struct BaseObj
{
    BaseObj(int a, int b, float f0, float f1, float f2, float f3, float f4, float f5, NiColorA q, float g0, float g1,
            float g2, float g3);
    virtual ~BaseObj();
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
    void FUN_00c62140();
};

struct FUN_00c61a10 : BaseObj
{
    int m_58;
    SubObj m_5c;
    FUN_00c61a10(int p1, int p2, int p3, float f0, float f1, float f2, float f3, float f4, float f5, NiColorA q, float g0,
                 float g1, float g2, float g3);
    virtual ~FUN_00c61a10();
};

// @fnv 0x00c61a10
FUN_00c61a10::FUN_00c61a10(int p1, int p2, int p3, float f0, float f1, float f2, float f3, float f4, float f5, NiColorA q,
                           float g0, float g1, float g2, float g3)
    : BaseObj(p1, p2, f0, f1, f2, f3, f4, f5, q, g0, g1, g2, g3), m_58(p3)
{
    SubObj* sub;
    FUN_00c62140();
}

inline void NiAVObject::IncRefCount()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}
inline void NiAVObject::DecRefCount()
{
    if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        DeleteThis();
}
struct Node62
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
    NiPointer<NiAVObject>* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    NiPointer<NiAVObject>& GetAt(unsigned int index)
    {
        return m_pBase[index];
    }
};
extern NiFixedString g_kExtraName62;
// local form of NiTListItem: 0x00c62200 needs the original node/helper inline split; shared-node trial shifts frame slots by four bytes.
struct Item62
{
    Item62* m_pkNext;
    Item62* m_pkPrev;
    NiPointer<NiAVObject> m_element;
    void SetElement(const NiPointer<NiAVObject>& p);
};
struct List62
{
    Item62* m_pkHead;
    Item62* m_pkTail;
    unsigned int m_uiCount;
    Item62* NewItem();
    void* Add62(const NiPointer<NiAVObject>& p)
    {
        Item62* pkItem = NewItem();
        pkItem->SetElement(p);
        pkItem->m_pkNext = 0;
        pkItem->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkItem;
        else
            m_pkHead = pkItem;
        m_pkTail = pkItem;
        ++m_uiCount;
        return pkItem;
    }
};
struct Collector62
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
    NiAVObject* unk54;
    int unk58;
    List62 unk5c;
    int GetMode() const
    {
        return unk58;
    }
    void FUN_00c62200(NiAVObject* pkObj);
};

// @fnv 0x00c62200
void Collector62::FUN_00c62200(NiAVObject* pkObj)
{
    if (pkObj)
    {
        Node62* pkNode2 = reinterpret_cast<Node62*>(pkObj->IsSceneNode());
        NiAVObject* pkExcl = unk54;
        if (pkObj == pkExcl)
            return;
        bool bAdd2;
        switch (GetMode())
        {
        case 0:
            bAdd2 = bool(pkObj->IsGeometry());
            break;
        case 1:
            bAdd2 = pkObj->GetExtraData(*reinterpret_cast<const NiFixedString*>(static_cast<const char*>(g_kExtraName62))) != 0;
            break;
        default:
            bAdd2 = pkNode2 != 0;
            break;
        }
        if (bAdd2)
        {
            unk5c.Add62(pkObj);
        }
        if (pkNode2)
        {
            unsigned int i2 = pkNode2->GetSize();
            while (i2--)
                FUN_00c62200(pkNode2->GetAt(i2));
        }
    }
}

extern double DAT_01029790;
int __cdecl FUN_00ecadb8();

inline float UnitRandom()
{
    return (float)(FUN_00ecadb8() / DAT_01029790);
}

class FUN_00c62390_cls
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
    int m_58;
    int unk5C;
    void** m_60;
    unsigned short unk64;
    unsigned short m_66;

    int GetMode() const
    {
        return m_58;
    }
    void* GetAt(unsigned int i)
    {
        void*& r = m_60[i];
        return r;
    }
    void FUN_00c625f0(void* a, void* b, void* c);
    void FUN_00c62470(void* a, void* b, void* c);
    void FUN_00c62390(void* a1, void* a2);
};

// @fnv 0x00c62390
void FUN_00c62390_cls::FUN_00c62390(void* a1, void* a2)
{
    void* pick;
    unsigned int n = m_66;
    if (n != 0)
    {
        unsigned int idx = (unsigned int)((double)n * UnitRandom());
        if (idx == n)
        {
            idx--;
        }
        pick = GetAt(idx);
    }
    else
    {
        pick = 0;
    }
    switch (GetMode())
    {
    case 0:
        FUN_00c625f0(pick, a1, a2);
        break;
    default:
        FUN_00c62470(pick, a1, a2);
        break;
    }
}

inline NiPoint3 NiPoint3::operator*(float scale) const
{
    return NiPoint3(scale * x, scale * y, scale * z);
}
float FUN_004579e0(float);
inline float NiPoint3::Length() const
{
    float squared = x * x + y * y + z * z;
    return FUN_004579e0(squared);
}

namespace fnv_00c625f0 {
extern int __cdecl FUN_00ecadb8(void);
extern double DAT_01029790;

struct Matrix9
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    NiPoint3 FUN_004b4500(const NiPoint3& point)
    {
        return NiPoint3(m00 * point.x + m01 * point.y + m02 * point.z, m10 * point.x + m11 * point.y + m12 * point.z,
                        m20 * point.x + m21 * point.y + m22 * point.z);
    }
};

struct GeometryData
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
    virtual unsigned short GetVertexCount();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* vertices;
    NiPoint3* normals;
};

struct Geometry
{
    void** vtable;
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
    struct DataPtr
    {
        GeometryData* object;
        GeometryData* operator->() const
        {
            return object;
        }
    } modelData;
    NiPoint3* GetVertices() const
    {
        return modelData->vertices;
    }
    NiPoint3* GetNormals() const
    {
        return modelData->normals;
    }
};

struct EmitterObject
{
    void** vtable;
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
    Matrix9 rotation;
    int unk8c;
    int unk90;
    int unk94;
    float scale;
    float GetScale() const
    {
        return scale;
    }
};

typedef Geometry*(__thiscall* GetGeometryFunction)(EmitterObject*);
typedef unsigned short(__thiscall* GetVertexCountFunction)(GeometryData*);

struct EmitterSampler
{
    void FUN_00c625f0(EmitterObject* object, NiPoint3& position, NiPoint3& direction);
};

// @fnv 0x00c625f0
void EmitterSampler::FUN_00c625f0(EmitterObject* object, NiPoint3& position, NiPoint3& direction)
{
    Geometry* geometry = object ? ((GetGeometryFunction)object->vtable[6])(object) : 0;
    if (geometry)
    {
        unsigned short count = geometry->modelData->GetVertexCount();
        int index = (unsigned int)((double)count * (float)(FUN_00ecadb8() / DAT_01029790));
        if (index == count)
            index--;
        position = geometry->GetVertices()[index];
        position *= object->GetScale();
        if (geometry->GetNormals())
        {
            NiPoint3 normal = geometry->GetNormals()[index];
            normal = object->rotation.FUN_004b4500(normal);
            direction = normal * static_cast<const NiPoint3&>(direction).Length();
        }
    }
    else
    {
        position = NiPoint3::ZERO;
    }
}
}  // namespace fnv_00c625f0

void __cdecl FUN_00aa10f0(void* p);

struct S00c62800_Arr
{
    int vptr;
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline ~S00c62800_Arr();
};

__forceinline S00c62800_Arr::~S00c62800_Arr()
{
    *(int*)this = (int)&DAT_010c377c;
    void* data = m_data;
    FUN_00aa10f0(data);
}

struct S00c62800_Base
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
    __forceinline ~S00c62800_Base();
};

__forceinline S00c62800_Base::~S00c62800_Base()
{
    ((FUN_00c31750_Class*)this)->FUN_00c31750();
}

struct S00c62800_Obj : S00c62800_Base
{
    S00c62800_Arr m_aiIndexedValues;
    __forceinline ~S00c62800_Obj();
    void* __thiscall FUN_00c62800(unsigned int flags);
};

__forceinline S00c62800_Obj::~S00c62800_Obj()
{}

// @fnv 0x00c62800
void* __thiscall S00c62800_Obj::FUN_00c62800(unsigned int flags)
{
    this->S00c62800_Obj::~S00c62800_Obj();
    if (flags & 1)
        operator delete(this, 0x6c);
    return this;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" void* __cdecl NiMalloc(unsigned int size);
extern "C" void __cdecl NiFree(void* p);

struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

// Exe NiTArray<NiPointer<RefObj>>::Compact: preserve the original inline pointer comparison.
__forceinline bool operator!=(const ::NiPointer<RefObj>& left, const ::NiPointer<RefObj>& right) { return left.m_pObject != right.m_pObject; }


template <class T> struct MallocIf
{
    static T* Allocate(unsigned int auiCount)
    {
        return (T*)NiMalloc(sizeof(T) * auiCount);
    }
};



// @fnv 0x00c628c0
template <class T, class TAlloc> void NiTArray<T, TAlloc>::SetSize(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != T(0))
            {
                m_pBase[i] = T(0);
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    T* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = MallocIf<T>::Allocate(m_usMaxSize);
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = T(0);
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pSaveBase);
}

template class NiTArray<NiPointer<RefObj> , NiTMallocInterface<NiPointer<RefObj>> >;

struct RefC62
{
    virtual void v00();
    virtual void v04();
    volatile long m_04;
    void Inc()
    {
        InterlockedIncrement(&m_04);
    }
    void Dec()
    {
        if (!InterlockedDecrement(&m_04))
            v04();
    }
};
struct PtrC62
{
    RefC62* m_00;
    PtrC62(RefC62* p = 0)
    {
        m_00 = p;
        if (m_00)
            m_00->Inc();
    }
    PtrC62(const PtrC62& p)
    {
        m_00 = p.m_00;
        if (m_00)
            m_00->Inc();
    }
    ~PtrC62()
    {
        if (m_00)
            m_00->Dec();
    }
    PtrC62& operator=(const PtrC62&);
    bool operator!=(const PtrC62& p) const
    {
        return m_00 != p.m_00;
    }
};
struct ArrayC62
{
    void* m_00;
    PtrC62* m_04;
    unsigned short m_08, m_0a, m_0c, m_0e;
    PtrC62 FUN_00c62d10(unsigned int i);
};
inline void FrameC62()
{
    struct Slots
    {
        unsigned int m_00, m_04;
    } slots;
    (void)&slots;
}
// @fnv 0x00c62d10
PtrC62 ArrayC62::FUN_00c62d10(unsigned int i)
{
    if (i >= m_0a)
        return PtrC62();
    PtrC62 result = m_04[i];
    m_04[i] = PtrC62(), FrameC62();
    if (result != PtrC62())
        --m_0c;
    if (i == (unsigned short)(m_0a - 1))
        --m_0a;
    return result;
}

inline char* StrMem::GetText() const
{
    return text;
}
inline unsigned int StrMem::GetLength() const
{
    return length == 0xffff ? (unsigned int)_strlen(GetText()) : (unsigned int)length;
}
inline StrMem::~StrMem()
{
    Set(0, 0);
}
namespace fnv_00c63c30 {
struct NiManager630
{
    NiAllocator* allocator;
};
extern NiManager630* DAT_011f6080;
extern const double DAT_01017cf8;
float FUN_004579e0(float);
extern int DAT_012043d0;
extern int DAT_0109b220;

extern MemoryManager g_mm630;

char* __cdecl FUN_00a5b690(const char* s);
int __cdecl FUN_004b75a0(void* p, const char* name);
long __cdecl FUN_00eca6d3(const char* s);

}  // namespace fnv_00c63c30

inline void Mat3::GetColumn(unsigned int col, ::NiPoint3& out) const
{
    out.x = (&m00)[col];
    out.y = (&m10)[col];
    out.z = (&m20)[col];
}

inline LocalVec3::LocalVec3()
{}

inline float LocalVec3::Length() const
{
    float squared = x * x + y * y + z * z;
    return fnv_00c63c30::FUN_004579e0(squared);
}

inline void LocalVec3::FUN_004a0c10()
{
    float length = Length();
    if (length > fnv_00c63c30::DAT_01017cf8)
    {
        float reciprocal = 1.0f / length;
        x *= reciprocal;
        y *= reciprocal;
        z *= reciprocal;
    }
    else
    {
        x = 0;
        y = 0;
        z = 0;
    }
}

namespace fnv_00c63c30 {
struct Child
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
    Mat3 m34;
    LocalVec3 m58;
};

extern const LocalVec3 ZERO;
struct VecGroup
{
    unsigned short m0;
    unsigned short pad2;
    LocalVec3 m4[8];
    LocalVec3 m64[8];
    VecGroup()
    {
        m0 = 0;
        for (int i = 0; i < 8; i++)
        {
            m4[i].x = ZERO.x;
            m4[i].y = ZERO.y;
            m4[i].z = ZERO.z;
            m64[i].x = ZERO.x;
            m64[i].y = ZERO.y;
            m64[i].z = ZERO.z;
        }
    }
    __forceinline static void* operator new(unsigned int n)
    {
        return g_mm630.Allocate(n);
    }
};

}  // namespace fnv_00c63c30

inline BSDecalPlacementVectorExtraData::ExtraList::ExtraList()
{
    size = 0;
    head = 0;
    tail = 0;
}

inline BSDecalPlacementVectorExtraData::BSDecalPlacementVectorExtraData(int v)
{
    m_iValue = v;
    count = 0;
    for (int i = 0; i < 8; i++)
        groups[i] = 0;
}

inline void* BSDecalPlacementVectorExtraData::operator new(unsigned n)
{
    unsigned size = n ? n : 1;
    unsigned alignment = 4;
    return fnv_00c63c30::DAT_011f6080->allocator->vfn_04(size, alignment, 1, true, 0, -1, 0);
}

namespace fnv_00c63c30 {
struct ChildPtr
{
    Child* object;
    operator Child*() const
    {
        Child* element = object;
        return element;
    }
};
struct ChildArray
{
    ChildPtr* data;
    unsigned short capacity, size, used, grow;
    ChildPtr& GetAt(unsigned int i) const
    {
        return data[i];
    }
};
struct ObjC63
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    int m4;
    char* m8;
    void* GetMesh()
    {
        void* name = m8;
        return name;
    }
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
    ChildArray children;
    BSDecalPlacementVectorExtraData* GetExtraData(int key);
    bool AddExtraData(int key, BSDecalPlacementVectorExtraData* p);
};

// @fnv 0x00c63c30
bool __cdecl FUN_00c63c30(ObjC63* obj, ObjC63* root)
{
    if (obj->v0c())
    {
        if (!DAT_012043d0)
            DAT_012043d0 = (int)new NiFixedString("DVPG");
        BSDecalPlacementVectorExtraData* extra = root->GetExtraData(DAT_012043d0);
        ObjC63* p = obj;
        if (p->GetMesh() && FUN_004b75a0(p->GetMesh(), "DecalPlacementVectorGroup"))
        {
            if (!extra)
            {
                extra = new BSDecalPlacementVectorExtraData(0);
                root->AddExtraData(DAT_012043d0, extra);
            }
            StrMem str4("DecalPlacementVectorGroup");
            const char* suffix3 = (const char*)p->GetMesh();
            suffix3 += str4.GetLength();
            int idx = (int)FUN_00eca6d3(suffix3);
            if ((int)extra->count < 8 && idx < 8 && extra->groups[idx] == 0)
            {
                VecGroup* pv = new VecGroup();
                for (int i = 0; i < (int)p->children.used; i++)
                {
                    if (i < 8)
                    {
                        Child* child = (Child*)p->children.GetAt(i);
                        Mat3 m = child->m34;
                        LocalVec3 v5;
                        m.GetColumn(2, reinterpret_cast<::NiPoint3&>(v5));
                        v5.FUN_004a0c10();
                        memcpy(&pv->m4[pv->m0], &child->m58, sizeof(LocalVec3));
                        memcpy(&pv->m64[pv->m0], &v5, sizeof(LocalVec3));
                        pv->m0++;
                    }
                }
                extra->groups[idx] = pv;
                extra->count++;
            }
            return true;
        }
        else
        {
            unsigned i = 0;
            while (i < p->children.size)
            {
                Child* c = (Child*)p->children.GetAt(i);
                if (c)
                {
                    if (FUN_00c63c30((ObjC63*)c, root))
                        c = 0;
                }
                i++;
            }
        }
    }
    return false;
}
}  // namespace fnv_00c63c30

extern int DAT_010c1364;
class FactoryObject : public NiObject
{
  public:
    static void* operator new(unsigned int size)
    {
        return BSFaceGenMorphData::operator new(size);
    }
    virtual ~FactoryObject();
    FactoryObject()
    {
        value = 0;
    }
    int value;
};
// @fnv 0x00c64810
FactoryObject* __cdecl FUN_00c64810()
{
    return new FactoryObject;
}

namespace fnv_00c649f0 {
extern int DAT_010c13f4;
extern int DAT_01069d84;
class C649F0_SubBase
{
  public:
    void FUN_0068ac40(unsigned int a, unsigned int b);
};
class C649F0_Sub : public C649F0_SubBase
{
  public:
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    __forceinline C649F0_Sub()
    {
        int unused;
        (void)unused;
        FUN_0068ac40(0, 1);
        m_00 = &DAT_01069d84;
    }
};
class C649F0_Object : public NiObject
{
  public:
    C649F0_Sub m_08;
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    virtual ~C649F0_Object();
};
// @fnv 0x00c649f0
C649F0_Object* __cdecl FUN_00c649f0()
{
    return new C649F0_Object;
}
}  // namespace fnv_00c649f0

extern int DAT_011f4280;

class FNVListObj
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};

class FNVSubHelper
{
  public:
    void __thiscall FUN_00c4c8d0(void* p);
};

class FNVCtxHelper
{
  public:
    void __thiscall FUN_00853130(void* a, void* b);
};

inline bool InList(void*& p)
{
    while (p != 0)
    {
        if (p == (void*)&DAT_011f4280)
            return true;
        p = *(void**)((char*)p + 4);
    }
    return false;
}

class FUN_00c64c40_cls
{
  public:
    bool __thiscall FUN_00c64c40(void* a1, FNVListObj* a2);
};

// @fnv 0x00c64c40
bool FUN_00c64c40_cls::FUN_00c64c40(void* a1, FNVListObj* a2)
{
    void* local2;
    void* m18;
    void* p3;
    bool found2;
    void* r9;
    void* m9;
    {
        void* out;
        {
            unsigned int pad[6];
        }

        if (a2 == 0)
        {
            r9 = 0;
        }
        else
        {
            p3 = a2->v2();
            found2 = InList(p3);
            r9 = (void*)((found2 ? -1 : 0) & (int)a2);
        }

        local2 = r9;
        if (local2 != 0)
        {
            m18 = *(void**)((char*)local2 + 0x18);
            if (m18 != 0)
            {
                m9 = *(void**)((char*)m18 + 8);
                out = 0;
                if (*(void**)((char*)a1 + 0x5c4) != 0 && m9 != 0)
                {
                    static_cast<FNVCtxHelper*>(*(void**)((char*)a1 + 0x5c4))->FUN_00853130(m9, &out);
                }
                if (out != 0)
                {
                    static_cast<FNVSubHelper*>((void*)((char*)this + 8))->FUN_00c4c8d0(&local2);
                    return true;
                }
            }
        }
    }
    return false;
}

namespace fnv_00c64d10 {
struct FUN_00c64d10
{
    NiFixedString m_pHeadNode;
    NiFixedString m_iSecondInteger;
    FUN_00c64d10(int first, int second);
    void FUN_00c64da0(int value);
    void FUN_00c64dc0(int value);
};
// @fnv 0x00c64d10
FUN_00c64d10::FUN_00c64d10(int first, int second) : m_pHeadNode(), m_iSecondInteger()
{
    FUN_00c64da0(first);
    FUN_00c64dc0(second);
}
}  // namespace fnv_00c64d10

extern const char* g_c64e70Empty;
struct C64e70Elem
{
    NiFixedString m_name;
    NiFixedString m_target;
    ~C64e70Elem()
    {}
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

inline void C64e70ArrayFree(C64e70Elem** p) { NiFree(p); }
typedef NiTArray<C64e70Elem*, NiTMallocInterface<C64e70Elem*> > C64e70Array;
template <> inline NiTArray<C64e70Elem*, NiTMallocInterface<C64e70Elem*> >::~NiTArray()
{
        C64e70ArrayFree(m_pBase);
    }
template <> inline void NiTArray<C64e70Elem*, NiTMallocInterface<C64e70Elem*> >::RemoveAll()
{
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }

struct C64e70Base
{
    virtual ~C64e70Base();
    int unk04;
    int unk08;
};

struct FUN_00c64e70 : C64e70Base
{
    C64e70Array m_ppData;
    virtual ~FUN_00c64e70();
};

// @fnv 0x00c64e70
FUN_00c64e70::~FUN_00c64e70()
{
    unsigned int count = m_ppData.m_usESize;
    for (unsigned int i = 0; i < count; i++)
    {
        delete m_ppData.m_pBase[i];
    }
    m_ppData.RemoveAll();
}

namespace fnv_00c65490 {
extern MemoryManager DAT_011f6238;
struct FUN_00c64d10
{
    int m_pHeadNode;
    int m_iSecondInteger;
    FUN_00c64d10(int first, int second);
    static void* operator new(unsigned int size)
    {
        int unused[4];
        (void)unused;
        return DAT_011f6238.Allocate(size);
    }
    static void operator delete(void* p);
};
struct C65490_List
{
    void FUN_00c4c8d0(FUN_00c64d10* const& item);
};
struct C65490_Owner
{
    int unk00;
    int unk04;
    int unk08;
    C65490_List m_kNode;
    void FUN_00c65490(int first, int second);
};
// @fnv 0x00c65490
void C65490_Owner::FUN_00c65490(int first, int second)
{
    FUN_00c64d10* item = new FUN_00c64d10(first, second);
    m_kNode.FUN_00c4c8d0(item);
}
}  // namespace fnv_00c65490

namespace fnv_00c65530 {
extern MemoryManager DAT_011f6238;
extern int DAT_0109b220;
int __cdecl FUN_00a5b690(const char* s);

extern NiFixedString* DAT_012043ec;

// @fnv 0x00c65530
void __cdecl FUN_00c65530()
{
    DAT_012043ec = new NiFixedString("ATP");
}
}  // namespace fnv_00c65530

namespace fnv_00c655d0 {
extern const char* DAT_0109b220;
extern MemoryManager DAT_011f6238;
}
inline void NiFixedString::operator delete(void* p)
{
    fnv_00c655d0::DAT_011f6238.Deallocate(p);
}
namespace fnv_00c655d0 {
extern NiFixedString* DAT_012043ec;
// @fnv 0x00c655d0
void FUN_00c655d0()
{
    delete DAT_012043ec;
    DAT_012043ec = 0;
}
}  // namespace fnv_00c655d0

void __cdecl FUN_00aa10f0(void* p);
// NiExtraData's virtual destructor changes the original staged destructor at 0x00c613a0.
struct FUN_00a7b300
{
    virtual void vf00();
    int m_04;
    int m_08;
    int m_0C;
    ~FUN_00a7b300();
};
struct C613A0_StringsData : FUN_00a7b300
{
    void* m_pData;
    ~C613A0_StringsData()
    {
        FUN_00aa10f0(m_pData);
        m_pData = 0;
    }
};
struct C613A0_Extra : C613A0_StringsData
{
    ~C613A0_Extra();
};
// @fnv 0x00c613a0
C613A0_Extra::~C613A0_Extra()
{}

struct SetAtRefObject
{
    virtual ~SetAtRefObject();
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

typedef NiPointer<SetAtRefObject> SetAtPointer;

struct SetAtArray
{
    void* m_ppVirtualMethodTable;
    SetAtPointer* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00c62b90(unsigned int uiIndex, const SetAtPointer& element);
};

// @fnv 0x00c62b90
void SetAtArray::FUN_00c62b90(unsigned int uiIndex, const SetAtPointer& element)
{
    static SetAtPointer kNull(0);
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != kNull)
            m_usESize++;
    }
    else
    {
        if (element != kNull)
        {
            if (m_pBase[uiIndex] == kNull)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != kNull)
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}

extern unsigned int DAT_011c16bc;

extern "C" int(__stdcall* DAT_00fdf1c0)(void*);
extern "C" int(__stdcall* DAT_00fdf1c4)(void*);

class S00c62f40_RefObject
{
  public:
    virtual void vf00();
    virtual void vf04();

    int m_uiRefCount;

    void IncRefCount()
    {
        DAT_00fdf1c0(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (DAT_00fdf1c4(&m_uiRefCount) == 0)
            vf04();
    }
};

class S00c62f40_Pointer
{
  public:
    __forceinline S00c62f40_Pointer(S00c62f40_RefObject* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
        {
            m_pObject->IncRefCount();
        }
    }

    __forceinline ~S00c62f40_Pointer()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }

    S00c62f40_Pointer& __thiscall FUN_006e5cc0(const S00c62f40_Pointer& source)
    {
        if (m_pObject != source.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = source.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    S00c62f40_RefObject* m_pObject;
};

class S00c62f40_Array
{
  public:
    void* m_ppVirtualMethodTable;
    S00c62f40_Pointer* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_00c62f40();
};

// @fnv 0x00c62f40
void S00c62f40_Array::FUN_00c62f40()
{
    unsigned short index;

    for (index = 0; index < m_usSize; ++index)
    {
        {
            m_pBase[index].FUN_006e5cc0(S00c62f40_Pointer());
        }
    }

    m_usSize = 0;
    m_usESize = 0;
}

// Preserve the no-throw deallocation contract used by this destructor.
__forceinline void DeallocateNoThrow(MemoryManager& manager, void* memory) throw()
{
    manager.Deallocate(memory);
}

namespace fnv_00c63b40 {
struct BaseB3
{
    virtual ~BaseB3();
    int unk04, unk08, unk0c, unk10;
};
struct MidB3 : BaseB3
{
    __forceinline virtual ~MidB3()
    {}
};
struct ListBaseB3
{
    __forceinline ~ListBaseB3()
    {}
};
struct ListB3 : ListBaseB3
{
    int unk00, unk04, unk08;
    void FUN_00c64710();
    __forceinline ~ListB3()
    {
        int a, b, c;
        FUN_00c64710();
    }
};
extern MemoryManager DAT_011f6238;
// BSDecalPlacementVectorExtraData's destructor (vftable 0x010c38ac). The shared class cannot carry it yet: with the
// list's destructors inline (base EH state around RemoveAll 0x00c64710) and NiIntegerExtraData's inline (vftable
// 0x010a0d24 + ~NiExtraData 0x00a7b300), this body still lacks 12 bytes of frame and 0x00c63c30 loses a 4-byte slot.
struct BSDecalPlacementVectorExtraData_DtorView : MidB3
{
    void* groups[8];
    ListB3 list;
    virtual ~BSDecalPlacementVectorExtraData_DtorView();
};
// @fnv 0x00c63b40
BSDecalPlacementVectorExtraData_DtorView::~BSDecalPlacementVectorExtraData_DtorView()
{
    for (int i = 0; i < 8; i++)
    {
        if (groups[i])
        {
            void* p = groups[i];
            DeallocateNoThrow(DAT_011f6238, p);
        }
        groups[i] = 0;
    }
}
}  // namespace fnv_00c63b40

extern "C" int __cdecl rand();
inline void ScalePoint(NiPoint3& point, float scale)
{
    point.FUN_00439180(scale);
}
struct M68Q
{
    NiPoint3 FUN_004b4500(const NiPoint3& v) const;
};
struct NodeQ
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
    M68Q k68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    NiPoint3 kPos;
};
struct CamQ
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
    float f98;
};
inline void Dead3()
{
    int d1;
    int d2;
    int d3;
}
inline void Dead6()
{
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
}
inline float Rand01()
{
    return rand() / 32767.0;
}
// @fnv 0x00c62470
void FUN_00c62390_cls::FUN_00c62470(void* a, void* b, void* c)
{
    if (a)
    {
        NodeQ* pParent = *(NodeQ**)((char*)a + 0x18);
        if (GetMode() != 1 && pParent)
        {
            *(NiPoint3*)b = ((NodeQ*)a)->kPos.FUN_00439ef0(pParent->kPos);
            Dead3();
            *(NiPoint3*)b = pParent->kPos.FUN_00439e90(((NiPoint3*)b)->ApplyScaled(Rand01()));
            Dead6();
            if (unk10)
            {
                float fScale = ((CamQ*)unk10)->f98;
                if (fScale != 1.0 && fScale != 0.0)
                    ScalePoint(*(NiPoint3*)b, 1.0f / fScale);
            }
        }
        else
        {
            *(NiPoint3*)b = ((NodeQ*)a)->kPos;
            if (GetMode() == 1)
                *(NiPoint3*)c = ((NodeQ*)a)->k68.FUN_004b4500(*(NiPoint3*)c);
            Dead3();
        }
    }
    else
    {
        *(NiPoint3*)b = *(NiPoint3*)&DAT_011f426c;
    }
}

extern NiFixedString* DAT_012043ac;
struct ExtraData850 : NiExtraData
{
    ExtraData850(const NiFixedString& kName) : NiExtraData(kName)
    {}
    virtual ~ExtraData850();
};
// @fnv 0x00c61850
ExtraData850* __cdecl FUN_00c61850()
{
    ExtraData850* pkData = new ExtraData850(*DAT_012043ac);
    pkData->SetName(DAT_011f49e0);
    return pkData;
}

struct FUN_00c656b0
{
    NiFixedString m_kName;
    NiFixedString m_kValue;
    ~FUN_00c656b0();
};

// @fnv 0x00c656b0
FUN_00c656b0::~FUN_00c656b0()
{}

namespace fnv_00c618f0 {
extern MemoryManager DAT_011f6238;

extern char* DAT_0109b220;
extern const char str_010c36b0[];
char* __cdecl FUN_00a5b690(const char* text);
void __cdecl FormHeap_Free(void* buffer);

extern NiFixedString* DAT_012043ac;

// @fnv 0x00c618f0
void FUN_00c618f0()
{
    DAT_012043ac = new NiFixedString(str_010c36b0);
}
}  // namespace fnv_00c618f0

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
inline void S61_Pad1()
{
    int a;
}
inline void S61_Pad2()
{
    int a;
    int b;
}
inline void S61_Pad12()
{
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    int a8;
    int a9;
    int a10;
    int a11;
}
struct RefObjV61
{
    virtual void Unk00();
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
template <class T> class NiPointer61
{
  public:
    T* m_pObject;
    NiPointer61(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer61()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
};
typedef NiPointer61<RefObjV61> Ptr61;
struct CloneMap61
{
    bool FUN_00a53c30(void* key, void*& out);
};
struct Cloning61
{
    CloneMap61* m_pCloneMap;
};
struct PtrArray61
{
    void* vtbl;
    Ptr61* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    Ptr61& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
    void FUN_00c62b90(unsigned int i, Ptr61& p);
    Ptr61 FUN_00c62d10(unsigned int i);
    void Compact();
};
struct Base61
{
    void FUN_00c31c90(Cloning61& c);
};
struct Emitter61 : Base61
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
    PtrArray61 m_kArray;
    void FUN_00c61cc0(Cloning61& kCloning);
};

// @fnv 0x00c61cc0
void Emitter61::FUN_00c61cc0(Cloning61& kCloning)
{
    Base61::FUN_00c31c90(kCloning);
    void* pkClone4;
    Emitter61* pkDest9;
    bool bCloned3 = kCloning.m_pCloneMap->FUN_00a53c30(this, pkClone4);
    if (bCloned3)
    {
        pkDest9 = (Emitter61*)pkClone4;
        unsigned int uiCount4 = pkDest9->m_kArray.GetSize();
        unsigned int uiFound2 = 0;
        while (uiCount4--)
        {
            void* pkNew;
            S61_Pad2();
            bool bNewA = kCloning.m_pCloneMap->FUN_00a53c30(pkDest9->m_kArray.GetAt(uiCount4), pkNew);
            if (bNewA)
            {
                uiFound2++;
                S61_Pad2();
                Ptr61 spNew3 = (RefObjV61*)pkNew;
                S61_Pad1();
                pkDest9->m_kArray.FUN_00c62b90(uiCount4, spNew3);
            }
            else
            {
                pkDest9->m_kArray.FUN_00c62d10(uiCount4);
            }
        }
        S61_Pad12();
        if (uiFound2 != pkDest9->m_kArray.GetSize())
            pkDest9->m_kArray.Compact();
    }
}
