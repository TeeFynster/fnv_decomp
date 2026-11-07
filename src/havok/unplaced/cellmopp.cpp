
// src/havok/unplaced/cellmopp.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/cellmopp.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/NiPoint3.h"
#include "../../../include/CellMopp.h"

class C621EF0Object
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual unsigned int GetFormID();
};

struct GlobalObject_004aff00
{
    void RemoveAll();
};
// @fnv 0x00621e60
void CellMopp::Remove()
{
    Kill();
    ((GlobalObject_004aff00*)((char*)this + 8))->RemoveAll();
}

struct FUN_00622290_cls
{
    int __thiscall CFilter_CFilter(int a, int b, int c);
    void __thiscall SetPackedValue(int a, int b, int c);
};

// Calls SetPackedValue with the three arguments, then returns this.
// @fnv 0x00622290
// src: XBOX_PDB 0x00622290
int __thiscall FUN_00622290_cls::CFilter_CFilter(int a, int b, int c)
{
    SetPackedValue(a, b, c);
    return (int)this;
}

struct FUN_006222c0_class
{
    void SetPackedValue(unsigned int a, unsigned int c, unsigned int b);
};

// @fnv 0x006222c0
void FUN_006222c0_class::SetPackedValue(unsigned int auiLow, unsigned int auiHigh, unsigned int auiMid)
{
    *(unsigned int*)this = (auiHigh << 0x10) | (auiMid << 8) | auiLow;
}

struct FUN_006222f0_Class
{
    void bhkRigidBodyCinfo_SetShape_0(int a);
};
// @fnv 0x006222f0
// src: COMMUNITY 0x006222f0
void FUN_006222f0_Class::bhkRigidBodyCinfo_SetShape_0(int aiValue)
{
    *(int*)((char*)this + 4) = aiValue;
    *(int*)((char*)this + 0x24) = aiValue;
}

extern const char* const g_01268350_arg1;

#include "../../../include/bhkBvTreeShape.h"

// @fnv 0x006223c0
const char* const* bhkBvTreeShape::GetArg1Ptr()
{
    return &g_01268350_arg1;
}

void* __fastcall bhkBvTreeShape_GetShapeCollection(void*);

struct FUN_006223d0
{
    void* bhkBvTreeShape_GetShapeCollection();
};

// @fnv 0x006223d0
// src: XBOX_PDB 0x00577190
void* FUN_006223d0::bhkBvTreeShape_GetShapeCollection()
{
    return ::bhkBvTreeShape_GetShapeCollection(this);
}

extern "C" void* g_01268350;

struct FUN_00622420_Class
{
    void* __thiscall GetGlobalPtr();
};

// @fnv 0x00622420
void* __thiscall FUN_00622420_Class::GetGlobalPtr()
{
    return &g_01268350;
}

int __fastcall NiTArray_char_NiTMallocInterface_char_GetEffectiveSize(void*);


// @fnv 0x00622470
bool CellMopp::IsCreated()
{
    return NiTArray_char_NiTMallocInterface_char_GetEffectiveSize(reinterpret_cast<char*>(this) + 8) != 0;
}

struct Base537
{
    void hkUnaryActionCinfo_hkUnaryActionCinfo();
};
// 0x00622490 initializes parameters at +0x10 via 0x006224c0, not a NiRefObject-derived CellMopp.
struct HeightFieldResetCall
{
    void __thiscall Reset();
};
struct FUN_00622490 : Base537
{
    FUN_00622490();
};
// @fnv 0x00622490
FUN_00622490::FUN_00622490()
{
    hkUnaryActionCinfo_hkUnaryActionCinfo();
    ((HeightFieldResetCall*)((char*)this + 0x10))->Reset();
}

struct FUN_00622570_Class
{
    unsigned char m_kPointB;
    unsigned char* UpdateState_00622570(unsigned char b);
};

// @fnv 0x00622570
// src: GUESS 0x00622570 (confidence: low)
unsigned char* FUN_00622570_Class::UpdateState_00622570(unsigned char aucValue)
{
    m_kPointB = aucValue;
    return &m_kPointB;
}

// Calls the CellMopp destructor, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00621d90
void* __thiscall CellMopp::Destroy(unsigned int flags)
{
    this->CellMopp::~CellMopp();
    if (flags & 1)
        operator delete(this, 24);
    return this;
}

extern "C" void* DAT_0104dbac;
extern "C" int DAT_012682cc;
struct FUN_00622390_Class
{
    void __thiscall FUN_0056e6f0();
    void* __thiscall bhkBvTreeShape_bhkBvTreeShape();
};
// @fnv 0x00622390
// src: EXE 0x00622390
void* __thiscall FUN_00622390_Class::bhkBvTreeShape_bhkBvTreeShape()
{
    FUN_0056e6f0();
    *(void**)this = &DAT_0104dbac;
    ++DAT_012682cc;
    return this;
}

struct FUN_00622440_Class
{
    void __thiscall FUN_00caff80();
    void* __thiscall FUN_00622440(unsigned int flags);
    static void operator delete(void* p, unsigned int size);
};

// @fnv 0x00622440
void* __thiscall FUN_00622440_Class::FUN_00622440(unsigned int flags)
{
    FUN_00caff80();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}

struct This5380d0
{
    bool bhkWorld_RemoveBody(unsigned int);
};
struct Flt
{
    operator unsigned int();
};
struct Arr
{
    unsigned int* GetAt(int);
};
// Gets the array from LookupFirstFormID and, if non-null, calls FUN_005380d0 on each non-zero element of the list at this+8.
// @fnv 0x00621e80
void CellMopp::Kill()
{
    unsigned int* pArray = reinterpret_cast<unsigned int*>(LookupFirstFormID());
    if (pArray)
    {
        for (unsigned int i = 0; i < NiTArray_char_NiTMallocInterface_char_GetEffectiveSize((char*)this + 8); ++i)
        {
            unsigned int p = *(Flt*)((Arr*)((char*)this + 8))->GetAt(i);
            if (p)
                ((This5380d0*)pArray)->bhkWorld_RemoveBody(p);
        }
    }
}

void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00ca4da0
{
    ~FUN_00ca4da0();
};
struct FUN_006223f0 : FUN_00ca4da0
{
    void* __thiscall Delete(unsigned int flags);
};
// Runs the base destructor, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006223f0
void* FUN_006223f0::Delete(unsigned int flags)
{
    this->FUN_00ca4da0::~FUN_00ca4da0();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}

// 0x006224c0 extends the scale/resolution initializer with fields at +0x30 and +0x34.
struct HeightFieldSampleParameters
{
    void InitializeHeightFieldParameters();
    void* __thiscall Reset();
};

// Calls InitializeHeightFieldParameters, then zeroes the int at offset 0x30 and the float at 0x34, and returns this.
// @fnv 0x006224c0
void* HeightFieldSampleParameters::Reset()
{
    InitializeHeightFieldParameters();
    *(int*)((char*)this + 0x30) = 0;
    *(float*)((char*)this + 0x34) = 0.0f;
    return this;
}

extern int DAT_011cc1c8;

// @fnv 0x00621dc0
CellMopp::~CellMopp()
{
    --DAT_011cc1c8;
    Remove();
}

extern int g_i622310Count;

class B622310Base
{
  public:
    int unk04;

    B622310Base();
    virtual ~B622310Base();
};

class FUN_00622310 : public B622310Base
{
  public:
    void bhkTriSampledHeightFieldBvTreeShape_Init(void* pvArg);

    FUN_00622310(void* pvArg);
    virtual ~FUN_00622310();
};

// Calls FUN_00cb0820 with pvArg, then increments g_i622310Count.
// @fnv 0x00622310
FUN_00622310::FUN_00622310(void* pvArg)
{
    bhkTriSampledHeightFieldBvTreeShape_Init(pvArg);
    g_i622310Count++;
}

// 0x006224f0 sets scale[4], two grid resolutions, height limits and a projection flag at +0x20.
struct HeightFieldScaleAndResolution
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m10;
    int m14;
    float m18;
    float m1c;
    void FUN_006815c0();
    void FUN_004b4d50(float a, float b, float c, float d);
};
struct HeightFieldProjectionFlag
{
    unsigned char m_kPointB;
    void FUN_006815c0();
    unsigned char* UpdateState_00622570(unsigned char b);
};
extern float DAT_01012054;
struct SampledHeightFieldParameters : HeightFieldScaleAndResolution
{
    HeightFieldProjectionFlag m20;
    SampledHeightFieldParameters* InitializeHeightFieldParameters();
};
// @fnv 0x006224f0
SampledHeightFieldParameters* SampledHeightFieldParameters::InitializeHeightFieldParameters()
{
    ((HeightFieldScaleAndResolution*)this)->FUN_006815c0();
    m20.FUN_006815c0();
    FUN_004b4d50(1.0f, 1.0f, 1.0f, 0.0f);
    m10 = 2;
    m14 = 2;
    m18 = 0.0f;
    m1c = DAT_01012054;
    m20.UpdateState_00622570(0);
    return this;
}

int __cdecl C621EF0Lookup(unsigned int auiFormId);

// @fnv 0x00621ef0
int CellMopp::LookupFirstFormID()
{
    if (m_kThirdFollowingStreamField.GetSize() && (bhkRigidBody*)m_kThirdFollowingStreamField.GetAt(0))
        return C621EF0Lookup(((C621EF0Object*)(bhkRigidBody*)m_kThirdFollowingStreamField.GetAt(0))->GetFormID());
    else
        return 0;
}

struct B006815c0
{
    B006815c0();
};

struct FUN_00622730_S : public B006815c0
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void NiQuaternion_FromAngleAxisX(float angle);
};

struct FUN_005610f0_Class
{
    void bhkRigidBody_SetNiPosition(NiPoint3* pos);
    void bhkRigidBody_SetNiRotation(FUN_00622730_S* rot);
};

struct FUN_0056d2c0_Class
{
    void bhkWorld_Add(void* obj);
    void bhkWorld_SetDebugObjectColor(void* obj, unsigned int color);
};

unsigned int __cdecl PackBytesBigEndian(int r, int g, int b, int a);

// @fnv 0x00622590
bool CellMopp::PlaceGridObjects(bhkWorld* p1, const NiPoint3* pPos, int p3)
{
    bool bResultTmp = false;
    if (p1 && IsCreated())
    {
        FUN_00622730_S kRot;
        kRot.NiQuaternion_FromAngleAxisX(1.5707964f);
        float offsetY2 = 0.0f;
        int kIdx = 0;
        for (unsigned int aI = 0; aI < 2; aI++)
        {
            float _offsetX = -2048.0f;
            for (unsigned int j8 = 0; j8 < 2; j8++)
            {
                FUN_005610f0_Class* pObj4 = (FUN_005610f0_Class*)(bhkRigidBody*)m_kThirdFollowingStreamField.GetAt(kIdx++);
                NiPoint3 kPos = *pPos;
                kPos.x += _offsetX;
                kPos.y += offsetY2;
                pObj4->bhkRigidBody_SetNiPosition(&kPos);
                pObj4->bhkRigidBody_SetNiRotation(&kRot);
                _offsetX += 2048.0;
            }
            offsetY2 += 2048.0;
        }
        if (LookupFirstFormID() == 0)
        {
            for (unsigned int k = 0; k < (unsigned int)NiTArray_char_NiTMallocInterface_char_GetEffectiveSize(&m_kThirdFollowingStreamField); k++)
            {
                FUN_005610f0_Class* pObj3 = (FUN_005610f0_Class*)(bhkRigidBody*)m_kThirdFollowingStreamField.GetAt(k);
                ((FUN_0056d2c0_Class*)p1)->bhkWorld_Add(pObj3);
                ((FUN_0056d2c0_Class*)p1)->bhkWorld_SetDebugObjectColor(pObj3, PackBytesBigEndian(0xdc, 0x96, 0x28, 0xff));
            }
        }
    }
    return bResultTmp;
}
