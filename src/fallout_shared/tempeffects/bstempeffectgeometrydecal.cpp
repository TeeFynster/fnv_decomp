#include "../../../include/BSDismemberSkinInstance.h"
#include "../../../include/BSTempEffectGeometryDecal.h"
#include "../../../include/NiPoint3.h"
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
#include "../../../include/NiSkinInstance.h"
#include "../../../include/NiTriShape.h"
#include "../../../include/BSThread.h"
#include "../../../include/GO.h"
#include "../../../include/NiRTTI.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TESActorBaseData.h"
#include "../../../include/NiPoint2.h"
#include "../../../include/NiNode.h"

// src/fallout_shared/tempeffects/bstempeffectgeometrydecal.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tempeffects/bstempeffectgeometrydecal.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern const NiRTTI g_011d6b04;

// @fnv 0x006838a0
// src: COMMUNITY 0x006838a0
const NiRTTI* __thiscall BSTempEffectGeometryDecal::GetRTTI_006838a0() const
{
    return &g_011d6b04;
}

extern unsigned char* DAT_011f5b04;

// @fnv 0x00683a60
// src: COMMUNITY 0x00683a60
unsigned char* NiParallelUpdateTaskManager_Get()
{
    return DAT_011f5b04;
}

extern "C" void __cdecl PowFloat(float, int);

// @fnv 0x00685d20
void __cdecl ForwardFloatAndInt(float afValue, int aiValue)
{
    PowFloat(afValue, aiValue);
}

extern NiFixedString* DAT_011c6228;

// @fnv 0x00688460
// src: COMMUNITY 0x00688460
NiFixedString* __cdecl FixedStrings_GetDecal()
{
    return DAT_011c6228;
}

struct GlobalObjectO2_00a7b610
{
    int dummy;
};
GlobalObjectO2_00a7b610 g_011f5b2c;

// @fnv 0x00688590
const NiRTTI* BSDismemberSkinInstance::GetRTTI() const
{
    return (const NiRTTI*)&g_011f5b2c;
}

void* __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

// Calls FUN_00688610, then if bit 0 of flags is set calls __Dummy_00b6fef0 with this and 0x40, and returns this.
// @fnv 0x006885e0
void* __thiscall BSDismemberSkinInstance::FUN_006885e0(unsigned int flags)
{
    SetVtableAndProcessState_00688610();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x40);
    return this;
}

struct FUN_00685e60_shell
{
    void __thiscall NiSkinPartition_ReplacePartitions(unsigned int, unsigned int);
};

// @fnv 0x00685e60
// src: COMMUNITY 0x00685e60
void __thiscall FUN_00685e60_shell::NiSkinPartition_ReplacePartitions(unsigned int a, unsigned int b)
{
    *(unsigned int*)(this + 0x0C) = a;
    *(unsigned int*)(this + 0x08) = b;
}

extern "C" void __cdecl _delete(void* p, unsigned int size);
// Calls FUN_00a85580, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x006885a0
void* NiSkinInstance::FUN_006885a0(unsigned int flags)
{
    this->FUN_00a85580();
    if (flags & 1)
        _delete(this, 0x34);
    return this;
}

// Calls FUN_00688770 on this, then deletes this with size 100 when flags has bit 0 set, and returns this.
// @fnv 0x006838d0
void* __thiscall BSTempEffectGeometryDecal::FUN_006838d0(unsigned int flags)
{
    this->FUN_00688770();
    if (flags & 1)
        _delete(this, 100);
    return this;
}

struct FUN_00685d40_shell
{
    void* __thiscall ResetToZero();
};

// Sets the four floats at offsets 0x0, 0x4, 0x8 and 0xc of this object to 0.0f and returns this.
// @fnv 0x00685d40
void* __thiscall FUN_00685d40_shell::ResetToZero()
{
    *(float*)((char*)this + 0xc) = 0.0f;
    *(float*)((char*)this + 0x8) = 0.0f;
    *(float*)((char*)this + 0x4) = 0.0f;
    *(float*)((char*)this + 0x0) = 0.0f;
    return this;
}

struct RefObj
{
    void* __thiscall _FNV_GetObjectReference();
};
struct Class87d40
{
    void __thiscall NiSkinInstance_Deform(void*, unsigned int, unsigned int, int, int, int, int, int);
    void __thiscall ForwardActorBaseData(void*, int, int, int, int, int);
};
// Calls FUN_00a855f0 with the object reference, thread ID and fatigue obtained from a1, plus a2 through a6.
// @fnv 0x00687d40
void __thiscall Class87d40::ForwardActorBaseData(void* apObject, int aiArg2, int aiArg3, int aiArg4, int aiArg5,
                                                 int aiArg6)
{
    NiSkinInstance_Deform(((RefObj*)apObject)->_FNV_GetObjectReference(), ((BSThread*)apObject)->GetThreadID(),
                 ((TESActorBaseData*)apObject)->GetFatigue(), aiArg2, aiArg3, aiArg4, aiArg5, aiArg6);
}

struct NineDw
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
    void FUN_004b45b0(void* p);
};

// Copies the nine dwords from src into the data member at offset 0x68.
// @fnv 0x00688430
// src: COMMUNITY 0x00688430
void __thiscall NiTriShape::NiAVObject_SetWorldRotate(NineDw* apSource)
{
    *reinterpret_cast<NineDw*>(&m_kWorld) = *apSource;
}

extern int DAT_01069a84;

// Calls FUN_006884c0 with a, b, c, then sets the vtable, stores e at +0x34 and d at +0x38, sets the byte at +0x3c to 1, and returns this.
// @fnv 0x00688470
void* __thiscall BSDismemberSkinInstance::ConstructShell(int aiArg1, int aiArg2, int aiArg3, int aiValue38, int aiValue34)
{
    FUN_006884c0(aiArg1, aiArg2, aiArg3);
    *(int*)this = (int)&DAT_01069a84;
    unk34 = aiValue34;
    unk38 = (Partition*)aiValue38;
    unk3C = 1;
    return this;
}

// @fnv 0x00688610
// src: GUESS 0x00688610 (confidence: low)
void __thiscall BSDismemberSkinInstance::SetVtableAndProcessState_00688610()
{
    *reinterpret_cast<int**>(this) = &DAT_01069a84;
    if (unk38)
    {
        void* p = unk38;
        ::operator delete(p);
        unk38 = 0;
        unk34 = 0;
    }
    NiSkinInstance::FUN_00a85580();
}

struct Flt
{
    operator unsigned int();
};
struct CtlV
{
    CtlV* GetNext() const;
};
struct FUN_00688730_shell
{
    CtlV* GetNextIfSet();
};
// Returns the result of GetNext on the CtlV stored at offset 0xb8 when that pointer is non-null, otherwise returns 0.
// @fnv 0x00688730
CtlV* FUN_00688730_shell::GetNextIfSet()
{
    if ((unsigned int)(*(Flt*)((char*)this + 0xb8)))
        return ((CtlV*)(unsigned int)(*(Flt*)((char*)this + 0xb8)))->GetNext();
    return 0;
}

// @fnv 0x00683a70
// src: COMMUNITY 0x00683a70
bool BSTempEffectGeometryDecal::ShouldAddTriangle(int triangle, int base, bool strip, const unsigned short* indices, const NiPoint3* vertices,
                         const unsigned short* remap)
{
    int flags;
    {
        bool result = false;
        flags = 0;
        for (int i = 0; i < 3; ++i)
        {
            int inside;
            {
                unsigned short vertex = 0;
                inside = 0;
                if (strip)
                    vertex = indices[triangle + i] + base;
                else
                    vertex = indices[triangle * 3 + i] + base;
                if (remap)
                    vertex = remap[vertex];
                if (vertices[vertex].x < 0.0)
                    flags |= 1;
                else if (vertices[vertex].x > 1.0)
                    flags |= 2;
                else
                    ++inside;
                if (vertices[vertex].y < 0.0)
                    flags |= 4;
                else if (vertices[vertex].y > 1.0)
                    flags |= 8;
                else
                    ++inside;
                if (vertices[vertex].z > 0.10000000149011612)
                {
                    flags |= 16;
                    ++inside;
                }
                if (inside == 3)
                    return true;
            }
        }
        if (((flags & 3) == 3 || (flags & 12) == 12) && (flags & 16))
            result = true;
        return result;
    }
}

struct DtorOwner00685e80
{
    void UpdateState_00a81bd0();
};
typedef void (__thiscall DtorOwner00685e80::*DtorMemberPointer)();
extern void __stdcall FUN_0065ee50_Helper(void* object, unsigned int size, int count, DtorMemberPointer destructor);
void __cdecl operator delete(void* p);
struct FUN_00685e80_Class
{
    void* DestroyOrFree(unsigned int flags);
};
// @fnv 0x00685e80
void* FUN_00685e80_Class::DestroyOrFree(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_0065ee50_Helper(this, 0x2c, *(int*)((char*)this - 4), &DtorOwner00685e80::UpdateState_00a81bd0);
        if (flags & 1)
            operator delete((char*)this - 4);
        return (char*)this - 4;
    }
    ((DtorOwner00685e80*)this)->UpdateState_00a81bd0();
    if (flags & 1)
        operator delete(this);
    return this;
}

// Candidate for claim clm_74791658c0c54ad694b5: ReadWeights, 165 bytes.
struct VecOwner
{
    float* GetElem(int i);
};
struct Calc
{
    int m0;  // +0
    int m4;  // +4
    void Helper(int a);
    void ReadWeights(int a, VecOwner* b);
};
void Calc::Helper(int a)
{}
float* VecOwner::GetElem(int i)
{
    return 0;
}
// @fnv 0x00685d70
void Calc::ReadWeights(int aiIndex, VecOwner* apOwner)
{
    Helper(aiIndex);
    int iAddress = aiIndex * this->m4 + this->m0;
    float f, g;
    float* pFloats;
    pFloats = (float*)iAddress;
    f = pFloats[0];
    g = 1.0f - f;
    *apOwner->GetElem(0) = f;
    f = pFloats[1];
    g = g - f;
    *apOwner->GetElem(1) = f;
    f = pFloats[2];
    g = g - f;
    *apOwner->GetElem(2) = f;
    *apOwner->GetElem(3) = g;
}

struct Cell4
{
    unsigned int value;
};

struct FUN_00685e20_cls
{
    int m_base;
    int m_iElementIndex;
    void __thiscall Touch(int index);
    void __thiscall GetCellAt(int index, Cell4* out);
};

// @fnv 0x00685e20
void __thiscall FUN_00685e20_cls::GetCellAt(int index, Cell4* out)
{
    Touch(index);
    Cell4* p = (Cell4*)(m_base + index * m_iElementIndex);
    *out = *p;
}

struct SpawnBase
{
    SpawnBase();
    virtual ~SpawnBase();
    int unk04;
};

struct SpawnFieldA
{
    SpawnFieldA(int a1);
    int unk00;
    ~SpawnFieldA();
};

struct SpawnFieldB
{
    int unk00;
    SpawnFieldB(int a1);
};

struct FUN_006884c0 : SpawnBase
{
    virtual void unk08();
    virtual ~FUN_006884c0();

    SpawnFieldA m_08;
    SpawnFieldB m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;

    FUN_006884c0(int a1, int a2, int a3);
};

// @fnv 0x006884c0
FUN_006884c0::FUN_006884c0(int aiFieldA, int aiFieldB, int aiFieldC) : m_08(aiFieldA), m_0c(0)
{
    m_10 = aiFieldB;
    m_14 = aiFieldC;
    m_18 = -1;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_30 = 0;
}

struct A8660Skin;

struct A8660Controller
{
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
    virtual bool IsActive();
};

struct A8660Solution
{
    A8660Skin* GetSkin();
    unsigned int GetCount();
    A8660Controller* GetController();
};

// @fnv 0x00688660
void BSTempEffectGeometryDecal::FinalizePath()
{
    if (!((A8660Solution*)m_sp2C.operator->())->GetSkin())
        return;
    if (!bInitialized)
    {
        if (((A8660Solution*)m_sp30.operator->())->GetCount() > 1 && ((A8660Solution*)m_sp2C.operator->())->GetCount() > 1)
        {
            A8660Controller* pkController = ((A8660Solution*)m_sp2C.operator->())->GetController();
            if (pkController && pkController->IsActive())
                Smooth();
            else
                Straighten();
        }
    }
    Finalize();
    m_sp2C = 0;
    m_sp30 = 0;
}

extern int DAT_011c57f0;

struct Stateful_cls
{
    int unk00;
};

struct Obj_cls
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58(void* p);
    Obj_cls* Modelloader_GetReferencedThis();
    Obj_cls* NiAVObject_GetParent();
    int NiNode_GetChildCount();
    void RemoveEffect(void* p);
};

struct Node_cls
{
    Stateful_cls* FUN_00a59d30(int n);
};

// If m_28 is clear, runs FUN_006828a0(f), sets a node's 0xbc float to m_10/m_08, and when m_10 > m_08 links m_34/m_1c objects and sets m_28.
// @fnv 0x006888a0
// src: COMMUNITY 0x006888a0
bool BSTempEffectGeometryDecal::Update_006888a0(float afValue)
{
    Obj_cls* outTmp;
    bool ok5;
    Stateful_cls* aSt;
    Node_cls* node7;
    Stateful_cls* t_;
    if (unk28 != 0)
    {
        return false;
    }
    ok5 = FUN_006828a0(afValue);
    node7 = (Node_cls*)Get3D();
    t_ = node7->FUN_00a59d30(3);
    aSt = t_;
    *(float*)((char*)aSt + 0xbc) = m_fFirstFloatValue / m_fParticleParameter5;
    if (m_fFirstFloatValue > m_fParticleParameter5)
    {
        outTmp = 0;
        if (((Obj_cls*)m_sp34.operator->()) != 0)
        {
            ((Obj_cls*)m_sp34.operator->())->v58(((Obj_cls*)m_spGeometry.operator->()));
            if (((Obj_cls*)m_sp34.operator->())->NiAVObject_GetParent() != 0)
            {
                outTmp = ((Obj_cls*)m_sp34.operator->())->NiAVObject_GetParent();
                outTmp->RemoveEffect(this);
            }
        }
        if (outTmp != 0)
        {
            if (((Obj_cls*)m_sp34.operator->())->NiNode_GetChildCount() == 0)
            {
                ((Obj_cls*)m_sp34.operator->())->NiAVObject_GetParent()->v58(((Obj_cls*)m_sp34.operator->()));
                DAT_011c57f0 = DAT_011c57f0 - 1;
            }
        }
        unk28 = 1;
    }
    return ok5;
}

struct GlobalRuntime
{
    bool __thiscall TESSaveLoadGame_UseSaveGameBlocks();
    char* __thiscall FUN_004fd3e0();
};

struct FeatureState
{
    unsigned char* __thiscall FUN_00408d60();
};

extern GlobalRuntime* DAT_011de45c;
extern FeatureState DAT_011de4e8;
extern char str_01012c78;
extern char str_01012cb0;
extern char str_01069ba0;

void* __cdecl TESForm_GetFormByNumericID(void* object);
void __cdecl ProgramFlow(const char* format, ...);

typedef unsigned int(__fastcall* VirtualQuery)(void* object);

// Builds a flags value from DAT_011de45c state and, when DAT_011de4e8 is set, logs details of the current object via FUN_0040fbe0.
// @fnv 0x00688a10
unsigned short BSTempEffectGeometryDecal::GetRuntimeFlags()
{
    unsigned short usFlags = 0;
    unsigned short usInitialFlags = usFlags;

    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        usFlags += 4;
        usFlags += 2;
    }

    if (*DAT_011de4e8.FUN_00408d60())
    {
        char* current = DAT_011de45c->FUN_004fd3e0();
        if (current)
        {
            void* related = TESForm_GetFormByNumericID(*reinterpret_cast<void**>(current));
            ProgramFlow(&str_01012cb0, usFlags - usInitialFlags, *reinterpret_cast<void**>(current),
                         reinterpret_cast<VirtualQuery>((*reinterpret_cast<void***>(related))[0x4c])(related),
                         *reinterpret_cast<unsigned int*>(current + 5), 0x72f, &str_01069ba0);
        }
        else
        {
            ProgramFlow(&str_01012c78, usFlags - usInitialFlags, 0x72f, &str_01069ba0);
        }
    }
    return usFlags;
}

struct Pt3Obj
{
    float x;
    float y;
    float z;
    void FUN_006815c0();
    void ScaleComponents(float f);
};
struct ArrayPoint : Pt3Obj
{
    ArrayPoint();
};
struct Pt3Arr
{
    float x;
    float y;
    float z;
    Pt3Arr();
};
extern double DAT_01030f28;
extern double DAT_01011588;
extern double DAT_010231d8;
void __cdecl NiMatrix3_TransformVertices(void* a, void* b, int c, void* d, void* e);
float __cdecl BSMAX_00404010(float a, float b);
float __cdecl FUN_00408840(float a);
struct Calc685
{
    static float ForwardFloatAndInt(float f, int i);
};
struct Obj16
{
    float x;
    float y;
    float z;
    float w;
    Obj16();
};
struct Obj4c
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
    void* m_44;
    unsigned short m_48;
    unsigned short m_4a;
    Obj4c();
};
struct Pair8
{
    unsigned short w;
    unsigned short p;
    float f;
    Pair8();
};
struct BigObj2c
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    int m_18;
    unsigned short m_1c;
    unsigned short m_1e;
    unsigned short m_20;
    unsigned short m_22;
    unsigned short m_24;
    unsigned short p26;
    int m_28;
    BigObj2c();
    ~BigObj2c();
};
void* __cdecl _NiMalloc_00aa1070(unsigned int n);
void* __cdecl Object_DispatchCommandFour(unsigned int n);
struct Obj18c
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    Obj18c();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void NiSkinPartition_ReplacePartitions(void* p, int n);
};
void __cdecl FUN_00401460(void* dst, void* src, unsigned int n);
void __cdecl FormHeapFreeAndLog_00401030(void* p);
extern double DAT_01012060;
extern void(__cdecl* DAT_00fdf0c8)();
extern GlobalObjectO2_00a7b610 g_011f49d8;
unsigned char __cdecl NiObject_IsExactKindOf(GlobalObjectO2_00a7b610* g, void* p);
void __cdecl ourMemset(void* p, int v, unsigned int n);
struct GeomObj
{
    NiSkinInstance* NiGeometry_GetSkinInstance();
};
struct CtrlObj
{
    unsigned int FUN_0044ddc0();
};
struct SkinBase
{
    CtrlObj* NiObjectNET_GetControllers();
};
struct ThirteenDw
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
};
struct ConvObjA
{
    NineDw* NiAVObject_GetWorldRotate();
};
struct ConvObjB
{
    ThirteenDw* NiAVObject_GetWorldRotate();
};
struct Obj1bc
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
    NiPoint3 FUN_004b4500(NiPoint3* in);
};
struct SphB
{
    Pt3Obj m_afExtents;
    int m_0c;
    int m_10;
    int m_14;
};
struct SphA
{
    Pt3Obj m_afExtents;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
};
struct RetC4
{
    RetC4(const RetC4&);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
};
RetC4 __cdecl BSUtilities_GetRotationZToVector(NiPoint3 pt);
struct SphC
{
    Pt3Obj m_afExtents;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    void FUN_004a0c90(float f);
    SphA FUN_0043f8d0(const RetC4& r);
};
struct Src38
{
    int m_00;
    int m_04;
    int m_08;
};
struct Obj160
{
    int m_00;
    int m_04;
    int m_08;
    void Subtract(Src38* p);
};
struct Small
{
    int m_00;
    int m_04;
    int m_08;
    void NiTConvertingStrideIterator_NiTConvertingStrideIterator();
    void ReadWeights(int idx, void* p);
    void GetCellAt(int idx, void* p);
    void NiGeometryDataIteratorNiPoint3_Get(int idx, void* p);
};
struct ChainObj
{
    void* NiTimeController_GetNext();
    unsigned short FUN_0047d370();
    unsigned char FUN_00a67360(int a);
    void NiGeometryData_GetVerticesIterator(Small* p);
    void GetBounds(Small* p);
    void GetKeyAndMode(int a, Small* p);
    void GetOutRec(Small* p);
    void FillOutRec674(Small* p);
    void NiGeometryData_UnlockPackedVertexData();
};
struct MidObj
{
    ChainObj* NiGeometry_GetModelData();
};
struct Entry4
{
    unsigned char b0;
    unsigned char b1;
    unsigned short w;
};

struct Ctrl150
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    short s20;
    unsigned short m_22;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
};
struct CtrlHolder
{
    Ctrl150* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct SkinMid
{
    void* FUN_005585e0();
    void nullsub_2(Small* a, Small* b, Small* c, Small* d, int n, Pt3Arr* p1, Pt3Obj* p2, int m);
};
struct XD8Obj
{
    int FUN_008d6f30();
    int FUN_008041a0();
};
struct BigEntry
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    unsigned short s1c;
    unsigned short m_1e;
    unsigned short t20;
    unsigned short m_22;
    unsigned short t24;
    unsigned short m_26;
    int t28;
};
extern NiPoint3 DAT_011f426c;

// Builds per-part skin partition data from the skin instance and control tables, then passes the assembled arrays to CreateDecalGeometry.
// @fnv 0x00683c10
void BSTempEffectGeometryDecal::BuildSkinPartitions()
{
    unsigned short* a1c4LocalAF;
    float* a1c0LocalAN;
    Obj1bc obj1bcLocalAE;
    Obj4c* arr198LocalAB;
    int count194LocalBA;
    int* a190LocalAI;
    Obj18c* x18cLocalCE;
    void* savedLocalAB;
    ThirteenDw thirteenLocalAI;
    Ctrl150* ctrl150LocalAG;
    int total14cLocalAC;
    unsigned short* a148LocalAD;
    void* p144LocalEF;
    int z140LocalBM;
    int flag13cLocalAL;
    NineDw nineLocalBC;
    unsigned char* a114LocalBI;
    unsigned short word110LocalBC;
    Pt3Arr* arr10cLocalAB;
    Pt3Obj sph2LocalAI;
    int cntFcLocalBB;
    unsigned short* aF8LocalBB;
    unsigned short wordF4LocalAD;
    unsigned int flagsLocalBC;
    unsigned char byteE9LocalBH;
    Pt3Obj* arrE8LocalFA;
    float ptE4LocalAB[3];
    void* xD8LocalDC;
    int* aD4LocalAA;
    unsigned short* aD0LocalBA;
    Pt3Obj ptCCLocalAD;
    int cntC0LocalBB;
    SphC sph3LocalCK;
    Small s3LocalBN;
    unsigned char byte89LocalAD;
    int cnt88LocalFB;
    SphA sph1LocalAC;
    Small s4LocalAA;
    BigObj2c* arr54LocalAD;
    Pt3Obj pt50LocalAN;
    Small s2LocalAK;
    void* data38LocalAM;
    Pt3Arr* arr34LocalCA;
    NiSkinInstance* skinInstLocalAA;
    Small s1LocalBB;
    Small s5LocalAF;
    unsigned short word14LocalBL;
    Obj16* arr10LocalCD;

    skinInstLocalAA = ((GeomObj*)((const char*)m_sp2C.operator->()))->NiGeometry_GetSkinInstance();
    savedLocalAB = 0;
    if (NiObject_IsExactKindOf(&g_011f49d8, skinInstLocalAA))
        savedLocalAB = skinInstLocalAA;
    else
        return;
    flagsLocalBC = ((SkinBase*)skinInstLocalAA)->NiObjectNET_GetControllers()->FUN_0044ddc0();

    sph1LocalAC.m_afExtents.FUN_006815c0();

    nineLocalBC = *((ConvObjA*)((const char*)m_sp2C.operator->()))->NiAVObject_GetWorldRotate();

    nineLocalBC.FUN_004b45b0(&obj1bcLocalAE);

    sph2LocalAI.FUN_006815c0();
    *(NiPoint3*)&sph2LocalAI = obj1bcLocalAE.FUN_004b4500(&m_44);

    sph3LocalCK.m_afExtents.FUN_006815c0();
    sph3LocalCK.FUN_004a0c90(m_54);
    sph1LocalAC = sph3LocalCK.FUN_0043f8d0(BSUtilities_GetRotationZToVector(m_44));

    thirteenLocalAI = *((ConvObjB*)((const char*)m_sp2C.operator->()))->NiAVObject_GetWorldRotate();
    ((Obj160*)&thirteenLocalAI.m_24)->Subtract((Src38*)&m_38);

    s1LocalBB.NiTConvertingStrideIterator_NiTConvertingStrideIterator();
    s2LocalAK.NiTConvertingStrideIterator_NiTConvertingStrideIterator();
    s3LocalBN.NiTConvertingStrideIterator_NiTConvertingStrideIterator();
    s4LocalAA.NiTConvertingStrideIterator_NiTConvertingStrideIterator();
    s5LocalAF.NiTConvertingStrideIterator_NiTConvertingStrideIterator();
    p144LocalEF = ((MidObj*)((const char*)m_sp2C.operator->()))->NiGeometry_GetModelData()->NiTimeController_GetNext();
    z140LocalBM = 0;
    data38LocalAM = 0;
    arr198LocalAB = 0;
    xD8LocalDC = 0;
    ctrl150LocalAG = 0;
    (void)p144LocalEF;
    (void)z140LocalBM;
    data38LocalAM = (void*)((XD8Obj*)((SkinMid*)skinInstLocalAA)->FUN_005585e0())->FUN_008d6f30();
    if (data38LocalAM == 0)
        return;
    cntFcLocalBB = (int)((ChainObj*)p144LocalEF)->FUN_0047d370();
    byteE9LocalBH = ((MidObj*)((const char*)m_sp2C.operator->()))->NiGeometry_GetModelData()->FUN_00a67360(0);
    ((MidObj*)((const char*)m_sp2C.operator->()))->NiGeometry_GetModelData()->NiGeometryData_GetVerticesIterator(&s1LocalBB);
    ((MidObj*)((const char*)m_sp2C.operator->()))->NiGeometry_GetModelData()->GetBounds(&s2LocalAK);
    ((MidObj*)((const char*)m_sp2C.operator->()))->NiGeometry_GetModelData()->GetKeyAndMode(0, &s3LocalBN);
    ((MidObj*)((const char*)m_sp2C.operator->()))->NiGeometry_GetModelData()->GetOutRec(&s4LocalAA);
    ((MidObj*)((const char*)m_sp2C.operator->()))->NiGeometry_GetModelData()->FillOutRec674(&s5LocalAF);
    word110LocalBC = 0;
    byte89LocalAD = 0;
    count194LocalBA = 0;
    ctrl150LocalAG = ((CtrlHolder*)((SkinBase*)skinInstLocalAA)->NiObjectNET_GetControllers())->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    flag13cLocalAL = ctrl150LocalAG->m_22 > 0;
    (void)flag13cLocalAL;
    for (int iValueDA = 0; iValueDA < (int)flagsLocalBC; iValueDA = iValueDA + 1)
    {
        {
            unsigned short wordD4ValueBD;
            unsigned char byteCDValueAL;
            int intCCValueDC;

            byteCDValueAL = ((BSDismemberSkinInstance*)savedLocalAB)->GetField38()[iValueDA].b0;
            wordD4ValueBD = ((BSDismemberSkinInstance*)savedLocalAB)->GetField38()[iValueDA].w;
            if ((int)wordD4ValueBD > 1000)
                wordD4ValueBD = (unsigned short)((int)wordD4ValueBD / 1000);
            else if ((int)wordD4ValueBD > 100)
            {
                while ((int)wordD4ValueBD > 100)
                    wordD4ValueBD = (unsigned short)(wordD4ValueBD - 100);
            }
            intCCValueDC = (int)wordD4ValueBD;
            if (byteCDValueAL != 0)
            {
                if ((1 << (intCCValueDC + 1)) & m_60)
                {
                    byte89LocalAD = 1;
                    word110LocalBC += ((BigEntry*)ctrl150LocalAG)[iValueDA].m_1e;
                    count194LocalBA = count194LocalBA + 1;
                }
            }
        }
    }

    if (!byte89LocalAD)
        return;
    total14cLocalAC = (int)word110LocalBC * 3;
    aF8LocalBB = new unsigned short[total14cLocalAC];
    aD4LocalAA = new int[cntFcLocalBB];
    word14LocalBL = 0;
    (void)word14LocalBL;
    a1c4LocalAF = new unsigned short[total14cLocalAC];
    aD0LocalBA = new unsigned short[cntFcLocalBB];
    a190LocalAI = new int[cntFcLocalBB];
    cnt88LocalFB = count194LocalBA;
    a148LocalAD = new unsigned short[count194LocalBA];
    a1c0LocalAN = new float[cntFcLocalBB * 4];
    a114LocalBI = new unsigned char[cntFcLocalBB * 4];
    ourMemset(aD4LocalAA, -1, cntFcLocalBB << 2);
    arr54LocalAD = new BigObj2c[count194LocalBA];
    arr34LocalCA = new Pt3Arr[cntFcLocalBB];
    arr10LocalCD = new Obj16[cntFcLocalBB];
    arr10cLocalAB = 0;
    arrE8LocalFA = 0;
    arr10cLocalAB = new Pt3Arr[cntFcLocalBB];
    arrE8LocalFA = (Pt3Obj*)new ArrayPoint[cntFcLocalBB];
    ((SkinMid*)skinInstLocalAA)
        ->nullsub_2(&s1LocalBB, &s4LocalAA, &s5LocalAF, &s2LocalAK, cntFcLocalBB, arr10cLocalAB, arrE8LocalFA, 0xc);
    xD8LocalDC = ((SkinMid*)skinInstLocalAA)->FUN_005585e0();
    data38LocalAM = (void*)((XD8Obj*)xD8LocalDC)->FUN_008d6f30();
    z140LocalBM = ((XD8Obj*)xD8LocalDC)->FUN_008041a0();
    arr198LocalAB = new Obj4c[z140LocalBM];
    for (int jValueBA = 0; jValueBA < z140LocalBM; jValueBA = jValueBA + 1)
    {
        {
            Obj4c* dstValueBG;

            dstValueBG = (Obj4c*)((char*)arr198LocalAB + jValueBA * 0x4c);
            *(ThirteenDw*)dstValueBG = *(ThirteenDw*)&((Obj4c*)data38LocalAM)[jValueBA];
            if (jValueBA == 0)
                dstValueBG->m_44 = new Pair8[cntFcLocalBB * 4];
            else
                dstValueBG->m_44 = new Pair8[cntFcLocalBB];
        }
    }

    (*reinterpret_cast<NiPoint3*>(ptE4LocalAB)) = *(NiPoint3*)&sph2LocalAI;

    pt50LocalAN.FUN_006815c0();

    ptCCLocalAD.FUN_006815c0();
    for (int kValueBC = 0; kValueBC < cntFcLocalBB; kValueBC = kValueBC + 1)
    {
        {
            float tmp200ValueAC;
            float gPtAValueAG[3];
            float gPtBValueBI[3];
            float tmp1e4ValueAC;

            (*reinterpret_cast<NiPoint3*>(gPtAValueAG)) = DAT_011f426c;
            *(NiPoint3*)&pt50LocalAN = *(NiPoint3*)&arr10cLocalAB[kValueBC];
            *(NiPoint3*)&ptCCLocalAD = *(NiPoint3*)&arrE8LocalFA[kValueBC];
            s4LocalAA.ReadWeights(kValueBC, &arr10LocalCD[kValueBC]);
            tmp200ValueAC = arr10LocalCD[kValueBC].x + arr10LocalCD[kValueBC].y + arr10LocalCD[kValueBC].z;
            arr10LocalCD[kValueBC].w = 1.0f - tmp200ValueAC;
            if ((double)arr10LocalCD[kValueBC].w < DAT_01030f28)
                arr10LocalCD[kValueBC].w = 0.0f;
            pt50LocalAN.ScaleComponents(*(float*)&thirteenLocalAI.m_30);
            (*reinterpret_cast<NiPoint3*>(gPtBValueBI)) = DAT_011f426c;
            NiMatrix3_TransformVertices(&thirteenLocalAI, &thirteenLocalAI.m_24, 1, &pt50LocalAN, &(*reinterpret_cast<NiPoint3*>(gPtBValueBI)));
            NiMatrix3_TransformVertices(&sph1LocalAC, &DAT_011f426c, 1, &(*reinterpret_cast<NiPoint3*>(gPtBValueBI)), &(*reinterpret_cast<NiPoint3*>(gPtAValueAG)));
            arr34LocalCA[kValueBC].x = (*reinterpret_cast<NiPoint3*>(gPtAValueAG)).x / m_50 + 0.5f;
            arr34LocalCA[kValueBC].y = (*reinterpret_cast<NiPoint3*>(gPtAValueAG)).y / m_50 + 0.5f;
            tmp1e4ValueAC = 1.0f - BSMAX_00404010(0.0f, (*reinterpret_cast<NiPoint3*>(ptE4LocalAB)).DotProduct((NiPoint3*)&ptCCLocalAD));
            arr34LocalCA[kValueBC].z =
                Calc685::ForwardFloatAndInt(tmp1e4ValueAC, 10) * (1.0f - FUN_00408840((*reinterpret_cast<NiPoint3*>(gPtAValueAG)).z) / 256.0f);
        }
    }

    wordF4LocalAD = 0;
    cntC0LocalBB = 0;
    count194LocalBA = 0;
    for (int mValueBC = 0; mValueBC < (int)flagsLocalBC; mValueBC = mValueBC + 1)
    {
        {
            unsigned short* x214ValueAG;
            unsigned short wordD4bValueBD;
            unsigned char byteCD2ValueAH;
            int intCC2ValueAH;

            x214ValueAG = 0;
            byteCD2ValueAH = ((BSDismemberSkinInstance*)savedLocalAB)->GetField38()[mValueBC].b0;
            wordD4bValueBD = ((BSDismemberSkinInstance*)savedLocalAB)->GetField38()[mValueBC].w;
            if ((int)wordD4bValueBD > 1000)
                wordD4bValueBD = (unsigned short)((int)wordD4bValueBD / 1000);
            else if ((int)wordD4bValueBD > 100)
            {
                while ((int)wordD4bValueBD > 100)
                    wordD4bValueBD = (unsigned short)(wordD4bValueBD - 100);
            }
            intCC2ValueAH = (int)wordD4bValueBD;
            if (byteCD2ValueAH != 0)
            {
                if ((1 << (intCC2ValueAH + 1)) & m_60)
                {
                    unsigned short word224ValueAP;
                    int x220ValueAE;
                    int x21cValueBB;
                    unsigned short word218ValueAB;

                    x21cValueBB = ((BigEntry*)ctrl150LocalAG)[mValueBC].t28;
                    (void)x21cValueBB;
                    word110LocalBC = ((BigEntry*)ctrl150LocalAG)[mValueBC].m_1e;
                    if (x214ValueAG == 0)
                        x214ValueAG = (unsigned short*)((BigEntry*)ctrl150LocalAG)[mValueBC].m_14;
                    word218ValueAB = 0;
                    word224ValueAP = 0;
                    (void)word218ValueAB;
                    (void)word224ValueAP;
                    ourMemset(a190LocalAI, -1, cntFcLocalBB << 2);
                    ourMemset(a1c0LocalAN, 0, (cntFcLocalBB << 2) << 2);
                    ourMemset(a114LocalBI, 0, cntFcLocalBB << 2);
                    x220ValueAE = 0;
                    for (int nValueEC = 0; nValueEC < (int)word110LocalBC; nValueEC = nValueEC + 1)
                    {
                        {
                            unsigned char byte236ValueBG;
                            unsigned char byte235ValueBC;
                            unsigned short w234ValueAA;
                            unsigned short w230ValueAH;
                            unsigned short w22cValueAP;

                            byte235ValueBC = 0;
                            byte236ValueBG = 1;
                            w230ValueAH = 0;
                            w22cValueAP = 0;
                            w234ValueAA = 0;
                            if (flag13cLocalAL)
                            {
                                w230ValueAH = (unsigned short)(x214ValueAG[nValueEC] + cntC0LocalBB);
                                w22cValueAP = (unsigned short)(x214ValueAG[nValueEC + 1] + cntC0LocalBB);
                                w234ValueAA = (unsigned short)(x214ValueAG[nValueEC + 2] + cntC0LocalBB);
                            }
                            else
                            {
                                w230ValueAH = (unsigned short)(x214ValueAG[nValueEC * 3] + cntC0LocalBB);
                                w22cValueAP = (unsigned short)(x214ValueAG[nValueEC * 3 + 1] + cntC0LocalBB);
                                w234ValueAA = (unsigned short)(x214ValueAG[nValueEC * 3 + 2] + cntC0LocalBB);
                            }
                            if (w230ValueAH == w22cValueAP || w230ValueAH == w234ValueAA || w22cValueAP == w234ValueAA)
                            {
                                if (flag13cLocalAL)
                                    x220ValueAE = (x220ValueAE == 0);
                                continue;
                            }
                            byte235ValueBC = ShouldAddTriangle(nValueEC, cntC0LocalBB, flag13cLocalAL != 0, x214ValueAG,
                                                          (Pt3Obj*)arr34LocalCA, 0);
                            if (byte235ValueBC && byte236ValueBG)
                            {
                                {
                                    for (int tValueEC = 0; tValueEC < 3; tValueEC = tValueEC + 1)
                                    {
                                        {
                                            unsigned short w244ValueBP;
                                            unsigned short w240ValueAG;

                                            w240ValueAG = flag13cLocalAL ? x214ValueAG[nValueEC + tValueEC]
                                                                         : x214ValueAG[nValueEC * 3 + tValueEC];
                                            w244ValueBP = (unsigned short)(w240ValueAG + cntC0LocalBB);
                                            if (aD4LocalAA[w244ValueBP] == -1)
                                            {
                                                unsigned char tmp248ValueAJ[4];

                                                aD4LocalAA[w244ValueBP] = (int)word14LocalBL;
                                                aF8LocalBB[wordF4LocalAD] = (unsigned short)word14LocalBL;
                                                wordF4LocalAD++;

                                                s5LocalAF.GetCellAt((int)w244ValueBP, tmp248ValueAJ);
                                                for (int uValueAA = 0; uValueAA < 4; uValueAA = uValueAA + 1)
                                                {
                                                    if ((double)((float*)&arr10LocalCD[w244ValueBP])[uValueAA] !=
                                                        DAT_01012060)
                                                    {
                                                        unsigned short w254ValueAM;
                                                        Obj4c* elemValueAK;

                                                        w254ValueAM = (unsigned short)tmp248ValueAJ[3 - uValueAA];
                                                        w254ValueAM =
                                                            ((unsigned short*)((BigEntry*)ctrl150LocalAG)[mValueBC]
                                                                 .m_04)[w254ValueAM];
                                                        elemValueAK = &arr198LocalAB[w254ValueAM];
                                                        ((Pair8*)elemValueAK->m_44)[elemValueAK->m_48].w =
                                                            word14LocalBL;
                                                        ((Pair8*)elemValueAK->m_44)[elemValueAK->m_48].f =
                                                            ((float*)&arr10LocalCD[w244ValueBP])[uValueAA];
                                                        elemValueAK->m_48++;
                                                    }
                                                }

                                                word14LocalBL++;
                                            }
                                            else
                                            {
                                                aF8LocalBB[wordF4LocalAD] = (unsigned short)aD4LocalAA[w244ValueBP];
                                                wordF4LocalAD++;
                                            }
                                            if (a190LocalAI[w244ValueBP] == -1)
                                            {
                                                unsigned char tmp258ValueCN[4];

                                                s5LocalAF.GetCellAt((int)w244ValueBP, tmp258ValueCN);
                                                for (int u2ValueDD = 0; u2ValueDD < 4; u2ValueDD = u2ValueDD + 1)
                                                {
                                                    if ((double)((float*)&arr10LocalCD[w244ValueBP])[u2ValueDD] !=
                                                        DAT_01012060)
                                                    {
                                                        unsigned short w264ValueAE;
                                                        int idx260ValueAD;

                                                        w264ValueAE = (unsigned short)tmp258ValueCN[3 - u2ValueDD];
                                                        idx260ValueAD = (int)word224ValueAP * 4 + u2ValueDD;
                                                        a1c0LocalAN[idx260ValueAD] =
                                                            ((float*)&arr10LocalCD[w244ValueBP])[u2ValueDD];
                                                        a114LocalBI[idx260ValueAD] = (unsigned char)w264ValueAE;
                                                    }
                                                }

                                                a190LocalAI[w244ValueBP] = (int)word224ValueAP;
                                                a1c4LocalAF[word218ValueAB] = (unsigned short)word224ValueAP;
                                                word218ValueAB++;
                                                aD0LocalBA[word224ValueAP] = (unsigned short)aD4LocalAA[w244ValueBP];
                                                word224ValueAP++;
                                            }
                                            else
                                            {
                                                a1c4LocalAF[word218ValueAB] = (unsigned short)a190LocalAI[w244ValueBP];
                                                word218ValueAB++;
                                            }
                                        }
                                    }
                                }
                                if (flag13cLocalAL)
                                {
                                    if (x220ValueAE)
                                    {
                                        int sw274ValueCD;
                                        int sw270ValueCC;
                                        int sw26cValueAA;
                                        int sw268ValueDC;

                                        sw270ValueCC = (int)aF8LocalBB[wordF4LocalAD - 3];
                                        sw274ValueCD = (int)aF8LocalBB[wordF4LocalAD - 1];
                                        aF8LocalBB[wordF4LocalAD - 3] = (unsigned short)sw274ValueCD;
                                        aF8LocalBB[wordF4LocalAD - 1] = (unsigned short)sw270ValueCC;
                                        sw26cValueAA = (int)a1c4LocalAF[word218ValueAB - 3];
                                        sw268ValueDC = (int)a1c4LocalAF[word218ValueAB - 1];
                                        a1c4LocalAF[word218ValueAB - 3] = (unsigned short)sw268ValueDC;
                                        a1c4LocalAF[word218ValueAB - 1] = (unsigned short)sw26cValueAA;
                                    }
                                }
                            }
                        nextN:
                            if (flag13cLocalAL)
                                x220ValueAE = (x220ValueAE == 0);
                        }
                    }

                    if ((int)word224ValueAP > 0)
                    {
                        int tmp278ValueAL;

                        arr54LocalAD[count194LocalBA].m_1e = (unsigned short)((int)word218ValueAB / 3);
                        arr54LocalAD[count194LocalBA].m_14 = _NiMalloc_00aa1070((unsigned int)word218ValueAB << 1);
                        FUN_00401460(arr54LocalAD[count194LocalBA].m_14, a1c4LocalAF,
                                     (unsigned int)word218ValueAB << 1);
                        arr54LocalAD[count194LocalBA].m_1c = word224ValueAP;
                        arr54LocalAD[count194LocalBA].m_0c = _NiMalloc_00aa1070((unsigned int)word224ValueAP << 1);
                        FUN_00401460(arr54LocalAD[count194LocalBA].m_0c, aD0LocalBA, (unsigned int)word224ValueAP << 1);
                        arr54LocalAD[count194LocalBA].m_20 = (unsigned short)((BigEntry*)ctrl150LocalAG)[mValueBC].t20;
                        arr54LocalAD[count194LocalBA].m_04 =
                            _NiMalloc_00aa1070((unsigned int)(unsigned short)((BigEntry*)ctrl150LocalAG)[mValueBC].t20 << 1);
                        FUN_00401460(arr54LocalAD[count194LocalBA].m_04,
                                     (void*)((BigEntry*)ctrl150LocalAG)[mValueBC].m_04,
                                     (unsigned int)(unsigned short)((BigEntry*)ctrl150LocalAG)[mValueBC].t20 << 1);
                        arr54LocalAD[count194LocalBA].m_24 = (unsigned short)((BigEntry*)ctrl150LocalAG)[mValueBC].t24;
                        tmp278ValueAL = (int)arr54LocalAD[count194LocalBA].m_24 * (int)word224ValueAP;
                        arr54LocalAD[count194LocalBA].m_08 = _NiMalloc_00aa1070((unsigned int)tmp278ValueAL << 2);
                        arr54LocalAD[count194LocalBA].m_10 = _NiMalloc_00aa1070((unsigned int)tmp278ValueAL);
                        FUN_00401460(arr54LocalAD[count194LocalBA].m_08, a1c0LocalAN,
                                     (unsigned int)((int)arr54LocalAD[count194LocalBA].m_24 * 4 *
                                                    (int)arr54LocalAD[count194LocalBA].m_1c));
                        FUN_00401460(arr54LocalAD[count194LocalBA].m_10, a114LocalBI,
                                     (unsigned int)((int)arr54LocalAD[count194LocalBA].m_24 *
                                                    (int)arr54LocalAD[count194LocalBA].m_1c));
                        if ((unsigned int)count194LocalBA >= (unsigned int)cnt88LocalFB)
                            DAT_00fdf0c8();
                        a148LocalAD[count194LocalBA] = (unsigned short)wordD4bValueBD;
                        count194LocalBA = count194LocalBA + 1;
                    }
                }
            }
            cntC0LocalBB += ((BigEntry*)ctrl150LocalAG)[mValueBC].s1c;
        }
    }

    delete arr10LocalCD;
    x18cLocalCE = 0;
    if (count194LocalBA > 0)
    {
        x18cLocalCE = new Obj18c;
        x18cLocalCE->NiSkinPartition_ReplacePartitions(arr54LocalAD, count194LocalBA);
    }
    if ((int)word14LocalBL > 0)
    {
        unsigned short* x284ValueBI;
        Pt3Obj* x280ValueAD;
        Pt3Obj* x27cValueBB;

        x284ValueBI = new unsigned short[wordF4LocalAD];
        FUN_00401460(x284ValueBI, aF8LocalBB, (unsigned int)wordF4LocalAD << 1);
        x280ValueAD = (Pt3Obj*)new ArrayPoint[word14LocalBL];
        x27cValueBB = (Pt3Obj*)new ArrayPoint[word14LocalBL];
        for (int pValueFC = 0; pValueFC < cntFcLocalBB; pValueFC = pValueFC + 1)
        {
            {
                Pt3Obj t2a0ValueAI;
                Pt3Obj t294ValueAJ;

                t294ValueAJ.FUN_006815c0();

                t2a0ValueAI.FUN_006815c0();
                if (aD4LocalAA[pValueFC] != -1)
                {
                    s1LocalBB.NiGeometryDataIteratorNiPoint3_Get(pValueFC, &t294ValueAJ);
                    s2LocalAK.NiGeometryDataIteratorNiPoint3_Get(pValueFC, &t2a0ValueAI);
                    x280ValueAD[aD4LocalAA[pValueFC]] = t294ValueAJ;
                    x27cValueBB[aD4LocalAA[pValueFC]] = *(Pt3Obj*)&arr34LocalCA[pValueFC];
                }
            }
        }

        for (int qValueAC = 0; qValueAC < z140LocalBM; qValueAC = qValueAC + 1)
        {
            {
                void* old44ValueHA;
                Obj4c* eValueCC;

                eValueCC = &arr198LocalAB[qValueAC];
                old44ValueHA = eValueCC->m_44;
                arr198LocalAB[qValueAC].m_44 = new Pair8[eValueCC->m_48];
                FUN_00401460(arr198LocalAB[qValueAC].m_44, old44ValueHA, (unsigned int)eValueCC->m_48 << 3);
                delete old44ValueHA;
            }
        }

        if (x18cLocalCE != 0)
            CreateDecalGeometry(((const char*)m_sp2C.operator->()), (int)word14LocalBL, (int)wordF4LocalAD, x280ValueAD, x27cValueBB,
                                x284ValueBI, arr198LocalAB, x18cLocalCE, a148LocalAD);
        else
            CreateDecalGeometry(((const char*)m_sp2C.operator->()), (int)word14LocalBL, (int)wordF4LocalAD, x280ValueAD, x27cValueBB,
                                x284ValueBI, arr198LocalAB, 0, 0);
        m_5c = (int)word14LocalBL;
    }
    else
    {
        for (int q2ValueAH = 0; q2ValueAH < z140LocalBM; q2ValueAH = q2ValueAH + 1)
        {
            delete arr198LocalAB[q2ValueAH].m_44;
            arr198LocalAB[q2ValueAH].m_44 = 0;
        }

        delete arr198LocalAB;
    }
    delete arr10cLocalAB;
    delete arrE8LocalFA;
    delete aF8LocalBB;
    delete aD4LocalAA;
    delete arr34LocalCA;
    delete a1c4LocalAF;
    delete aD0LocalBA;
    delete a190LocalAI;
    delete a1c0LocalAN;
    delete a114LocalBI;
    delete a148LocalAD;
    if (byteE9LocalBH)
        ((MidObj*)((const char*)m_sp2C.operator->()))->NiGeometry_GetModelData()->NiGeometryData_UnlockPackedVertexData();
    (void)cnt88LocalFB;
    (void)arr54LocalAD;
    (void)(*reinterpret_cast<NiPoint3*>(ptE4LocalAB));
    (void)cntC0LocalBB;
}

struct DPoint
{
    float x, y, z;
    DPoint();
    DPoint& Subtract(const DPoint&);
    DPoint& ScaleComponents(float);
    float DotProduct(const DPoint&);
};
struct DMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    DMatrix();
    DMatrix FUN_004b45b0();
    DPoint FUN_004b4500(const DPoint*);
    void FUN_004a0c90(float);
    DMatrix FUN_0043f8d0(const DMatrix*);
};
struct DTransform
{
    DMatrix rotation;
    DPoint position;
    float scale;
};
struct DPartition
{
    int unk00;
    unsigned short* bones;
    float* weights;
    unsigned short* vertexMap;
    unsigned char* boneIndices;
    unsigned short* triangles;
    int unk18;
    unsigned short vertexCount, triangleCount, boneCount, stripCount, weightsPerVertex, unk26;
    int unk28;
    DPartition();
    ~DPartition();
};
struct DBoneWeight
{
    unsigned short index, unk02;
    float weight;
    DBoneWeight();
};
struct DBone
{
    DTransform transform;
    int unk34, unk38, unk3c, unk40;
    DBoneWeight* weights;
    unsigned short count, unk4a;
    DBone();
};
struct DPartitionData
{
    unsigned int FUN_0044ddc0();
    DPartition* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct DSkinData
{
    DBone* FUN_008d6f30();
    int FUN_008041a0();
};
struct DSkin
{
    DPartitionData* NiObjectNET_GetControllers();
    DSkinData* FUN_005585e0();
    void ForwardActorBaseData(void*, DPoint*, DPoint*, int, int, int);
};
struct DGeometryData
{
    unsigned short FUN_004a8ae0();
    DPoint* BGSSaveFormBuffer_GetForm();
    DPoint* FUN_0059bb30();
};
struct DGeometry
{
    DSkin* NiGeometry_GetSkinInstance();
    DTransform& NiAVObject_GetWorldRotate();
    DGeometryData* NiGeometry_GetModelData();
};
struct DNewPartition
{
    int unk00, unk04, unk08, unk0c;
    DNewPartition();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void NiSkinPartition_ReplacePartitions(DPartition*, int);
};
extern GlobalObjectO2_00a7b610 g_011f49d8;
extern DPoint NiPoint3_ZERO;
bool __cdecl NiObject_IsExactKindOf(GlobalObjectO2_00a7b610*, DSkin*);
DMatrix __cdecl BSUtilities_GetRotationZToVector(DPoint);
void __cdecl NiMatrix3_TransformVertices(DMatrix*, DPoint*, int, DPoint*, DPoint*);
float __cdecl BSMAX_00404010(float, float);
float __cdecl DecalPower(float, int);
float __cdecl FloatAbs(float);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete[](void*);
void* __cdecl NiMalloc(unsigned int);
void* __cdecl memcpy(void*, const void*, unsigned int);
void* __cdecl memset(void*, int, unsigned int);
extern "C" __declspec(dllimport) void __stdcall DebugBreak();

// Projects the skin's vertices onto the decal plane, rebuilds the selected body-part partitions and bones, and passes the new geometry to CreateDecalGeometry.
// @fnv 0x00685ef0
void BSTempEffectGeometryDecal::BuildDecalGeometry()
{
    unsigned short* partitionIndices_10;
    float* weights_6;
    DBone* newBones_3;
    int selectedCount_12;
    int* localRemap_40;
    DNewPartition* newPartition_14;
    DSkin* dismember_9;
    DPartition* partitions_15;
    int indexCapacity_4;
    unsigned short* flags_7;
    int boneCount_4;
    int strips_17;
    unsigned short* vertexMap_22;
    unsigned char* boneIndices_1;
    unsigned short triangleCount_33;
    int* remap_1;
    DPoint* positions_6;
    int sourceVertexCount_3;
    unsigned short* indices_3;
    unsigned short indexCount_11;
    int partitionCount_10;
    DPoint* normals_17;
    DSkinData* skinData_1;
    unsigned short* triangleData_17;
    unsigned short* partitionMap_7;
    bool selected_21;
    unsigned int flagCapacity_0;
    DBone* boneData_4;
    DPartition* outputPartitions_22;
    DBone* bones_53;
    DPoint* texcoords_0;
    DSkin* skin_1;
    unsigned short outputVertexCount_4;
    if (m_60 == 0)
        return;
    skin_1 = ((DGeometry*)m_sp2C.operator->())->NiGeometry_GetSkinInstance();
    dismember_9 = 0;
    if (NiObject_IsExactKindOf(&g_011f49d8, skin_1))
        dismember_9 = skin_1;
    else
        return;
    partitionCount_10 = skin_1->NiObjectNET_GetControllers()->FUN_0044ddc0();
    DMatrix basis_6;
    DMatrix worldRotation_4 = ((DGeometry*)m_sp2C.operator->())->NiAVObject_GetWorldRotate().rotation;
    DMatrix inverse_11 = worldRotation_4.FUN_004b45b0();
    DPoint localDirection_29;
    localDirection_29 = inverse_11.FUN_004b4500(&(*(DPoint*)&m_44));
    DMatrix rotation_6;
    rotation_6.FUN_004a0c90(m_54);
    basis_6 = rotation_6.FUN_0043f8d0(&BSUtilities_GetRotationZToVector((*(DPoint*)&m_44)));
    DTransform transform_40 = ((DGeometry*)m_sp2C.operator->())->NiAVObject_GetWorldRotate();
    transform_40.position.Subtract((*(DPoint*)&m_38));
    boneData_4 = skin_1->FUN_005585e0()->FUN_008d6f30();
    if (boneData_4 == 0 || boneData_4->weights == 0)
        return;
    boneCount_4 = 0;
    bones_53 = 0;
    newBones_3 = 0;
    skinData_1 = 0;
    partitions_15 = 0;
    sourceVertexCount_3 = ((DGeometry*)m_sp2C.operator->())->NiGeometry_GetModelData()->FUN_004a8ae0();
    triangleCount_33 = 0;
    triangleData_17 = 0;
    vertexMap_22 = 0;
    selected_21 = false;
    selectedCount_12 = 0;
    partitions_15 = skin_1->NiObjectNET_GetControllers()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    strips_17 = partitions_15->stripCount > 0;
    for (int scanPartitionIndex = 0; scanPartitionIndex < partitionCount_10; scanPartitionIndex++)
    {
        unsigned char scanEnabled_1 = ((BSDismemberSkinInstance*)dismember_9)->GetField38()[scanPartitionIndex].enabled;
        unsigned short scanPart_50 = ((BSDismemberSkinInstance*)dismember_9)->GetField38()[scanPartitionIndex].bodyPart;
        if (scanPart_50 > 1000)
            scanPart_50 /= 1000;
        else if (scanPart_50 > 100)
        {
            while (scanPart_50 > 100)
                scanPart_50 -= 100;
        }
        int scanPartIndex_40 = scanPart_50;
        if (scanEnabled_1 && ((1 << (scanPartIndex_40 + 1)) & m_60))
        {
            selected_21 = true;
            triangleCount_33 += partitions_15[scanPartitionIndex].triangleCount;
            selectedCount_12++;
        }
    }
    if (!selected_21)
        return;
    indexCapacity_4 = triangleCount_33 * 3;
    indices_3 = new unsigned short[indexCapacity_4];
    remap_1 = new int[sourceVertexCount_3];
    partitionIndices_10 = new unsigned short[indexCapacity_4];
    partitionMap_7 = new unsigned short[sourceVertexCount_3];
    localRemap_40 = new int[sourceVertexCount_3];
    flagCapacity_0 = partitionCount_10;
    flags_7 = new unsigned short[partitionCount_10];
    weights_6 = new float[sourceVertexCount_3 * 4];
    boneIndices_1 = new unsigned char[sourceVertexCount_3 * 4];
    memset(remap_1, -1, sourceVertexCount_3 * 4);
    outputPartitions_22 = new DPartition[selectedCount_12];
    texcoords_0 = new DPoint[sourceVertexCount_3];
    positions_6 = 0;
    normals_17 = 0;
    positions_6 = new DPoint[sourceVertexCount_3];
    normals_17 = new DPoint[sourceVertexCount_3];
    skin_1->ForwardActorBaseData(((DGeometry*)m_sp2C.operator->())->NiGeometry_GetModelData(), positions_6, normals_17, 0, 0, 12);
    skinData_1 = skin_1->FUN_005585e0();
    bones_53 = skinData_1->FUN_008d6f30();
    boneCount_4 = skinData_1->FUN_008041a0();
    newBones_3 = new DBone[boneCount_4];
    for (int allocBoneIndex = 0; allocBoneIndex < boneCount_4; allocBoneIndex++)
    {
        DBone* allocBone = &newBones_3[allocBoneIndex];
        allocBone->transform = bones_53[allocBoneIndex].transform;
        if (allocBoneIndex == 0)
            allocBone->weights = new DBoneWeight[sourceVertexCount_3 * 4];
        else
            allocBone->weights = new DBoneWeight[sourceVertexCount_3];
    }
    DPoint normalDirection_1 = localDirection_29;
    DPoint vertex_3;
    DPoint normal_35;
    for (int projectionVertex = 0; projectionVertex < sourceVertexCount_3; projectionVertex++)
    {
        DPoint projected_8 = NiPoint3_ZERO;
        vertex_3 = positions_6[projectionVertex];
        normal_35 = normals_17[projectionVertex];
        DPoint world_20 = NiPoint3_ZERO;
        vertex_3.ScaleComponents(transform_40.scale);
        NiMatrix3_TransformVertices(&transform_40.rotation, &transform_40.position, 1, &vertex_3, &world_20);
        NiMatrix3_TransformVertices(&basis_6, &NiPoint3_ZERO, 1, &world_20, &projected_8);
        texcoords_0[projectionVertex].x = projected_8.x / m_50 + 0.5f;
        texcoords_0[projectionVertex].y = projected_8.y / m_50 + 0.5f;
        float opacity_6 = 1.0f - BSMAX_00404010(0.0f, normalDirection_1.DotProduct(normal_35));
        texcoords_0[projectionVertex].z = DecalPower(opacity_6, 10) * (1.0f - FloatAbs(projected_8.z) / 200.0f);
    }
    indexCount_11 = 0;
    outputVertexCount_4 = 0;
    selectedCount_12 = 0;
    for (int buildPartitionIndex = 0; buildPartitionIndex < partitionCount_10; buildPartitionIndex++)
    {
        unsigned char buildEnabled_2 = ((BSDismemberSkinInstance*)dismember_9)->GetField38()[buildPartitionIndex].enabled;
        unsigned short buildPart_43 = ((BSDismemberSkinInstance*)dismember_9)->GetField38()[buildPartitionIndex].bodyPart;
        if (buildPart_43 > 1000)
            buildPart_43 /= 1000;
        else if (buildPart_43 > 100)
        {
            while (buildPart_43 > 100)
                buildPart_43 -= 100;
        }
        int buildPartIndex_11 = buildPart_43;
        if (buildEnabled_2 && ((1 << (buildPartIndex_11 + 1)) & m_60))
        {
            triangleCount_33 = partitions_15[buildPartitionIndex].triangleCount;
            triangleData_17 = partitions_15[buildPartitionIndex].triangles;
            vertexMap_22 = partitions_15[buildPartitionIndex].vertexMap;
            strips_17 = partitions_15[buildPartitionIndex].stripCount > 0;
            unsigned short localIndexCount_3 = 0;
            unsigned short localVertexCount_22 = 0;
            memset(localRemap_40, -1, sourceVertexCount_3 * 4);
            memset(weights_6, 0, sourceVertexCount_3 * 4 * 4);
            memset(boneIndices_1, 0, sourceVertexCount_3 * 4);
            int winding_3 = 0;
            int cursor_15 = 0;
            for (int triangleIndex = 0; triangleIndex < triangleCount_33; triangleIndex++)
            {
                bool accepted_3 = false;
                bool valid_1 = true;
                unsigned short first_20 = triangleData_17[cursor_15];
                unsigned short second_11 = triangleData_17[cursor_15 + 1];
                unsigned short third_53 = triangleData_17[cursor_15 + 2];
                first_20 = vertexMap_22[first_20];
                second_11 = vertexMap_22[second_11];
                third_53 = vertexMap_22[third_53];
                if (first_20 == second_11 || first_20 == third_53 || second_11 == third_53)
                {
                    if (strips_17)
                    {
                        winding_3 = !winding_3;
                        cursor_15++;
                    }
                    else
                        cursor_15 += 3;
                    continue;
                }
                accepted_3 = ShouldAddTriangle(triangleIndex, 0, strips_17 != 0, triangleData_17, texcoords_0, vertexMap_22);
                if (accepted_3 && valid_1)
                {
                    for (int corner = 0; corner < 3; corner++)
                    {
                        unsigned short localIndex = triangleData_17[cursor_15 + corner];
                        unsigned short sourceIndex = vertexMap_22[localIndex];
                        if (remap_1[sourceIndex] == -1)
                        {
                            remap_1[sourceIndex] = outputVertexCount_4;
                            indices_3[indexCount_11] = outputVertexCount_4;
                            indexCount_11++;
                            outputVertexCount_4++;
                        }
                        else
                        {
                            indices_3[indexCount_11] = remap_1[sourceIndex];
                            indexCount_11++;
                        }
                        if (localRemap_40[sourceIndex] == -1)
                        {
                            for (int influence = 0; influence < partitions_15[buildPartitionIndex].weightsPerVertex;
                                 influence++)
                            {
                                int sourceWeight_14 =
                                    localIndex * partitions_15[buildPartitionIndex].weightsPerVertex + influence;
                                int destWeight_2 =
                                    localVertexCount_22 * partitions_15[buildPartitionIndex].weightsPerVertex +
                                    influence;
                                weights_6[destWeight_2] = partitions_15[buildPartitionIndex].weights[sourceWeight_14];
                                boneIndices_1[destWeight_2] =
                                    partitions_15[buildPartitionIndex].boneIndices[sourceWeight_14];
                            }
                            localRemap_40[sourceIndex] = localVertexCount_22;
                            partitionIndices_10[localIndexCount_3] = localVertexCount_22;
                            localIndexCount_3++;
                            partitionMap_7[localVertexCount_22] = remap_1[sourceIndex];
                            localVertexCount_22++;
                        }
                        else
                        {
                            partitionIndices_10[localIndexCount_3] = localRemap_40[sourceIndex];
                            localIndexCount_3++;
                        }
                    }
                    if (strips_17 && winding_3)
                    {
                        int firstIndex_14 = indices_3[indexCount_11 - 3];
                        int lastIndex_7 = indices_3[indexCount_11 - 1];
                        indices_3[indexCount_11 - 3] = lastIndex_7;
                        indices_3[indexCount_11 - 1] = firstIndex_14;
                        int firstLocal_1 = partitionIndices_10[localIndexCount_3 - 3];
                        int lastLocal_23 = partitionIndices_10[localIndexCount_3 - 1];
                        partitionIndices_10[localIndexCount_3 - 3] = lastLocal_23;
                        partitionIndices_10[localIndexCount_3 - 1] = firstLocal_1;
                    }
                }
                if (strips_17)
                {
                    winding_3 = !winding_3;
                    cursor_15++;
                }
                else
                    cursor_15 += 3;
            }
            if (localVertexCount_22 > 0)
            {
                outputPartitions_22[selectedCount_12].triangleCount = localIndexCount_3 / 3;
                outputPartitions_22[selectedCount_12].triangles = (unsigned short*)NiMalloc(localIndexCount_3 * 2);
                memcpy(outputPartitions_22[selectedCount_12].triangles, partitionIndices_10, localIndexCount_3 * 2);
                outputPartitions_22[selectedCount_12].vertexCount = localVertexCount_22;
                outputPartitions_22[selectedCount_12].vertexMap = (unsigned short*)NiMalloc(localVertexCount_22 * 2);
                memcpy(outputPartitions_22[selectedCount_12].vertexMap, partitionMap_7, localVertexCount_22 * 2);
                outputPartitions_22[selectedCount_12].boneCount = partitions_15[buildPartitionIndex].boneCount;
                outputPartitions_22[selectedCount_12].bones =
                    (unsigned short*)NiMalloc(partitions_15[buildPartitionIndex].boneCount * 2);
                memcpy(outputPartitions_22[selectedCount_12].bones, partitions_15[buildPartitionIndex].bones,
                       partitions_15[buildPartitionIndex].boneCount * 2);
                outputPartitions_22[selectedCount_12].weightsPerVertex =
                    partitions_15[buildPartitionIndex].weightsPerVertex;
                int weightCount = outputPartitions_22[selectedCount_12].weightsPerVertex * localVertexCount_22;
                outputPartitions_22[selectedCount_12].weights = (float*)NiMalloc(weightCount * 4);
                outputPartitions_22[selectedCount_12].boneIndices = (unsigned char*)NiMalloc(weightCount);
                memcpy(outputPartitions_22[selectedCount_12].weights, weights_6,
                       outputPartitions_22[selectedCount_12].weightsPerVertex * 4 *
                           outputPartitions_22[selectedCount_12].vertexCount);
                memcpy(outputPartitions_22[selectedCount_12].boneIndices, boneIndices_1,
                       outputPartitions_22[selectedCount_12].weightsPerVertex *
                           outputPartitions_22[selectedCount_12].vertexCount);
                if ((unsigned int)selectedCount_12 >= flagCapacity_0)
                    DebugBreak();
                flags_7[selectedCount_12] = buildPart_43;
                selectedCount_12++;
            }
        }
    }
    newPartition_14 = 0;
    if (selectedCount_12 > 0)
    {
        newPartition_14 = new DNewPartition;
        newPartition_14->NiSkinPartition_ReplacePartitions(outputPartitions_22, selectedCount_12);
    }
    if (outputVertexCount_4 > 0)
    {
        unsigned short* finalIndices_1 = new unsigned short[indexCount_11];
        memcpy(finalIndices_1, indices_3, indexCount_11 * 2);
        DPoint* sourcePositions_18 = ((DGeometry*)m_sp2C.operator->())->NiGeometry_GetModelData()->BGSSaveFormBuffer_GetForm();
        DPoint* sourceNormals_7 = ((DGeometry*)m_sp2C.operator->())->NiGeometry_GetModelData()->FUN_0059bb30();
        DPoint* finalPositions_26 = new DPoint[outputVertexCount_4];
        DPoint* finalTexcoords_13 = new DPoint[outputVertexCount_4];
        for (int iSourceVertexIndex = 0; iSourceVertexIndex < sourceVertexCount_3; iSourceVertexIndex++)
        {
            if (remap_1[iSourceVertexIndex] != -1)
            {
                DPoint* sourcePosition_3 = &sourcePositions_18[iSourceVertexIndex];
                DPoint* sourceNormal_28 = &sourceNormals_7[iSourceVertexIndex];
                finalPositions_26[remap_1[iSourceVertexIndex]] = *sourcePosition_3;
                finalTexcoords_13[remap_1[iSourceVertexIndex]] = texcoords_0[iSourceVertexIndex];
            }
        }
        for (int copyBoneIndex = 0; copyBoneIndex < boneCount_4; copyBoneIndex++)
        {
            DBone* sourceBone_18 = &bones_53[copyBoneIndex];
            DBone* copyBone_11 = &newBones_3[copyBoneIndex];
            for (int weightIndex = 0; weightIndex < sourceBone_18->count; weightIndex++)
            {
                unsigned short boneSourceIndex = sourceBone_18->weights[weightIndex].index;
                if (remap_1[boneSourceIndex] != -1)
                {
                    copyBone_11->weights[copyBone_11->count].index = remap_1[boneSourceIndex];
                    copyBone_11->weights[copyBone_11->count].weight = sourceBone_18->weights[weightIndex].weight;
                    copyBone_11->count++;
                }
            }
            DBoneWeight* oldWeights_41 = copyBone_11->weights;
            newBones_3[copyBoneIndex].weights = new DBoneWeight[copyBone_11->count];
            memcpy(newBones_3[copyBoneIndex].weights, oldWeights_41, copyBone_11->count * 8);
            delete[] oldWeights_41;
        }
        if (newPartition_14)
            CreateDecalGeometry(((DGeometry*)m_sp2C.operator->()), outputVertexCount_4, indexCount_11, finalPositions_26,
                                finalTexcoords_13, finalIndices_1, newBones_3, newPartition_14, flags_7);
        else
            CreateDecalGeometry(((DGeometry*)m_sp2C.operator->()), outputVertexCount_4, indexCount_11, finalPositions_26,
                                finalTexcoords_13, finalIndices_1, newBones_3, 0, 0);
        m_5c = outputVertexCount_4;
    }
    else
    {
        for (int cleanupBoneIndex = 0; cleanupBoneIndex < boneCount_4; cleanupBoneIndex++)
        {
            delete[] newBones_3[cleanupBoneIndex].weights;
            newBones_3[cleanupBoneIndex].weights = 0;
        }
        delete[] newBones_3;
    }
    delete[] positions_6;
    delete[] normals_17;
    delete[] indices_3;
    delete[] partitionIndices_10;
    delete[] partitionMap_7;
    delete[] remap_1;
    delete[] localRemap_40;
    delete[] weights_6;
    delete[] boneIndices_1;
    delete[] texcoords_0;
    delete[] flags_7;
}

struct NiObj;
struct ObjC;

unsigned char __cdecl NiObject_IsKindOf(const NiRTTI* rtti, NiAVObject* obj);
void __cdecl FUN_00b57e30(void* a, int b, int c);
extern const NiRTTI DAT_011f444c;

struct PtrHolder
{
    void* FUN_0066b0d0(void* p);
};
struct VSub
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void v36(int a, GO* s);
};
struct VSubOwner
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    VSub sub;
};
struct ObjB
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    PtrHolder m_7c;
    int w80;
    int w84;
    int w88;
    int w8c;
    int w90;
    int w94;
    int w98;
    int w9c;
    int wa0;
    int wa4;
    int wa8;
    int wac;
    int wb0;
    int wb4;
    int wb8;
    int wbc;
    int wc0;
    int wc4;
    int wc8;
    int wcc;
    int wd0;
    static void* operator new(unsigned int n);
    static void operator delete(void*, unsigned int);
    ObjB();
    void BSShaderProperty_SetDepthBias(float f);
};
struct SkinDataX
{
    int FUN_008041a0();
    int GetOffsetC(DPoint* p);
};
struct SkinX
{
    SkinDataX* FUN_005585e0();
    int* FUN_00825c00();
    int TESMain_GetThread();
};
struct ObjC
{
    int cf00;
    int cf04;
    int cf08;
    int cf0c;
    int cf10;
    int cf14;
    int cf18;
    int cf1c;
    int cf20;
    int cf24;
    int cf28;
    int cf2c;
    int cf30;
    int cf34;
    int cf38;
    int cf3c;
    int cf40;
    int cf44;
    static void* operator new(unsigned int n);
    static void operator delete(void*, unsigned int);
    ObjC(int partList, DBone* bone, int x);
};

struct ObjE
{
    virtual ~ObjE();
    int ef04;
    int ef08;
    int ef0c;
    static void* operator new(unsigned int n);
    static void operator delete(void*, unsigned int);
    ObjE();
    unsigned char NiSkinPartition_MakePartitions(void* p);
};
struct GeomX
{
    int GetTranslate_0043c490();
    int NiAVObject_GetRotate_006a9540();
    float GetFloatAt64();
    int NiAVObject_GetWorldTranslate();
    NineDw* NiAVObject_GetWorldRotate();
    float NiAVObject_GetWorldScale();
};

// Builds a NiTriShape from the given points and indices, attaches skin/partition data and copies transform properties from the geometry, then stores the shape.
// @fnv 0x00687d90
void BSTempEffectGeometryDecal::CreateDecalGeometry(DGeometry* geom, unsigned short ausVertexCount, unsigned short ausIndexCount,
                                 DPoint* apVertices, DPoint* d, unsigned short* apIndices, DBone* bone,
                                 DNewPartition* apNewPartition, unsigned short* apPartMap)
{
    NiTriShape* objA =
        new NiTriShape(ausVertexCount, (NiPoint3*)apVertices, (NiPoint3*)d, (void*)0, (NiPoint2*)0, 0, 0, ausIndexCount / 3, apIndices);
    objA->AssignFixedString(*FixedStrings_GetDecal());
    ObjB* entries;
    entries = new ObjB();
    objA->NiAVObject_AttachProperty(entries);
    entries->BSShaderProperty_SetDepthBias(1.0f);
    GO strLocal(0);
    ((VSubOwner*)m_58)->sub.v36(0, &strLocal);
    NiObj* partCount;
    partCount = strLocal;
    if (NiObject_IsKindOf(&DAT_011f444c, (NiAVObject*)partCount))
        entries->m_7c.FUN_0066b0d0(partCount);
    SkinX* count;
    count = (SkinX*)geom->NiGeometry_GetSkinInstance();
    int objD;
    objD = count->FUN_005585e0()->FUN_008041a0();
    ObjC* textObj;
    textObj = new ObjC(objD, bone, count->FUN_005585e0()->GetOffsetC(apVertices));
    int* s;
    s = count->FUN_00825c00();
    long objC;
    int* partList = new int[objD];
    for (objC = 0; objC < objD; objC++)
        partList[objC] = s[objC];
    int skin;
    skin = 0;
    unsigned int vertexMap[15];
    if (apNewPartition)
    {
        skin = (int)((DPartitionData*)apNewPartition)->FUN_0044ddc0();
    }
    else
    {
        long idx;
        idx = 2;
        for (unsigned int bitIdx = 0; bitIdx < 15; bitIdx++)
        {
            if (m_60 & idx)
            {
                vertexMap[skin] = bitIdx;
                skin++;
            }
            idx = idx << 1;
        }
    }
    Entry4* kIter;
    kIter = new Entry4[skin];
    {
        long j;
        for (j = 0; j < skin; j++)
        {
            kIter[j].b0 = 1;
            kIter[j].b1 = 1;
            if (apPartMap)
                kIter[j].w = apPartMap[j];
            else
                kIter[j].w = (unsigned short)vertexMap[j];
        }
    }
    BSDismemberSkinInstance* arr1 = new BSDismemberSkinInstance(textObj, count->TESMain_GetThread(), partList, kIter, skin);
    if (apNewPartition)
    {
        arr1->BSMultiBound_SetShape((NiSkinPartition*)apNewPartition);
        objA->SetSkinInstance(arr1);
    }
    else
    {
        ObjE* val;
        val = new ObjE();
        if (val->NiSkinPartition_MakePartitions(objA->NiGeometry_GetModelData(textObj, 0x12, 4, 1, 0, 0, 0)))
        {
            arr1->BSMultiBound_SetShape((NiSkinPartition*)val);
            objA->SetSkinInstance(arr1);
        }
        else
        {
            delete val;
            delete arr1;
        }
    }
    objA->NiAVObject_SetTranslate(((GeomX*)((DGeometry*)m_sp2C.operator->()))->GetTranslate_0043c490());
    objA->SetRotate_0043fa80(((GeomX*)((DGeometry*)m_sp2C.operator->()))->NiAVObject_GetRotate_006a9540());
    objA->NiAVObject_SetScale(((GeomX*)((DGeometry*)m_sp2C.operator->()))->GetFloatAt64());
    objA->NiAVObject_SetWorldTranslate(((GeomX*)((DGeometry*)m_sp2C.operator->()))->NiAVObject_GetWorldTranslate());
    objA->NiAVObject_SetWorldRotate(((GeomX*)((DGeometry*)m_sp2C.operator->()))->NiAVObject_GetWorldRotate());
    objA->SetValue(((GeomX*)((DGeometry*)m_sp2C.operator->()))->NiAVObject_GetWorldScale());
    objA->UpdateWorldBound();
    objA->UpdateProperties();
    FUN_00b57e30(objA, 0, 0);
    m_spGeometry = objA;
    unk20 = (int)((DGeometry*)m_sp2C.operator->());
}

// Detaches m_spGeometry from its parent, deletes m_pData, and clears m_sp2C and m_sp30.
// @fnv 0x00688770
BSTempEffectGeometryDecal::~BSTempEffectGeometryDecal()
{
    if (m_spGeometry)
    {
        if (m_spGeometry->GetParent())
            m_spGeometry->GetParent()->RemoveObject(m_spGeometry);
        m_spGeometry = 0;
    }
    if (m_pData)
        delete m_pData;
    m_sp2C = 0;
    m_sp30 = 0;
}

struct SaveGameBuffer688
{
    char* FUN_00825c00();
    void TESSaveLoadGame_SaveGameDataOLD(const void* pvData, unsigned int uiSize);
};
struct SaveForm688
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetName();
};
void __cdecl Warning_005b5e40(const char* pcMessage, const char* pcFile, int iLine);

// Writes a BLOK-tagged save block for the decal, logs the record size and form info, and back-patches the block size.
// @fnv 0x00688b00
// src: COMMUNITY 0x00688b00
void BSTempEffectGeometryDecal::SaveGameTES_00688b00()
{
    unsigned short usSize = 0;
    char* pcSizePos = 0;
    char* pStart = ((SaveGameBuffer688*)DAT_011de45c)->FUN_00825c00();
    if (*DAT_011de4e8.FUN_00408d60())
        pStart = ((SaveGameBuffer688*)DAT_011de45c)->FUN_00825c00();
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiTag = 'BLOK';
        ((SaveGameBuffer688*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&uiTag, 4);
        pcSizePos = ((SaveGameBuffer688*)DAT_011de45c)->FUN_00825c00();
        ((SaveGameBuffer688*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&usSize, 2);
    }

    if (*DAT_011de4e8.FUN_00408d60())
    {
        char* pcEnd = ((SaveGameBuffer688*)DAT_011de45c)->FUN_00825c00();
        char* pcRecord = DAT_011de45c->FUN_004fd3e0();
        if (pcRecord)
        {
            SaveForm688* pForm = (SaveForm688*)TESForm_GetFormByNumericID(*(void**)pcRecord);
            ProgramFlow(
                "SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", pcEnd - pStart,
                *(unsigned int*)pcRecord, pForm->GetName(), *(unsigned int*)(pcRecord + 5), 0x783,
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectGeometryDecal.cpp");
        }
        else
        {
            ProgramFlow(
                "SaveGame(): %-5i ending at line %i in file %s", pcEnd - pStart, 0x783,
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectGeometryDecal.cpp");
        }
    }
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        char* pCur = ((SaveGameBuffer688*)DAT_011de45c)->FUN_00825c00();
        char* pBlock = pcSizePos;
        if (pCur > pBlock + 0xffff)
            Warning_005b5e40(
                "SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectGeometryDecal.cpp",
                0x783);
        *(unsigned short*)pcSizePos = (unsigned short)(pCur - pBlock);
    }
}

struct SubDef
{
    SubDef();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct Obj4
{
    unsigned int GetVal();
};

struct Aux30
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, m_30;
};

// Initializes BSTempEffect and members, copying a5, a6, and a3->m_30 into their corresponding fields.
// @fnv 0x00683900
BSTempEffectGeometryDecal::BSTempEffectGeometryDecal(int a1, float a2, const Aux30* a3, Obj4* a4, SubDef a5, SubDef a6, float a11,
                                   float a12, unsigned int a13)
    : BSTempEffect((TESObjectCELL*)a1, a2), m_spGeometry(0), m_sp2C(0), m_sp30(0), m_sp34(0)
{
    unk28 = 0;
    m_spGeometry = 0;
    m_pData = 0;
    m_sp2C = (NiAVObject*)a4;
    m_sp30 = (NiAVObject*)a4->GetVal();
    *(SubDef*)&m_38 = a5;
    *(SubDef*)&m_44 = a6;
    m_50 = a11;
    m_54 = a12;
    m_60 = a13;
    m_5c = 0;
    m_58 = a3->m_30;
}

extern char str_01015718[];
extern char str_010156a8[];
extern char str_01015588[];
extern char str_01015500[];
extern char str_010154a0[];
extern char str_01015440[];

struct DecalLoad688Size
{
    unsigned char low, middleLow, middleHigh, high;
};
struct DecalLoad688Header
{
    int formID;
    unsigned char flags;
    DecalLoad688Size dataSize;
    unsigned char version;
};
struct DecalLoad688Reader
{
    void TESSaveLoadGame_LoadGameDataOLD(void* data, unsigned int size);
};
struct DecalLoad688Version
{
    unsigned char FUN_008df040();
};
struct DecalLoad688Buffer
{
    unsigned int FUN_00825c00();
};
struct DecalLoad688Runtime
{
    DecalLoad688Header* BGSProjectile_GetExplosion();
};
void __cdecl Warning_005b5e40(const char* format, ...);

// Reads a four-byte marker and two-byte value, then logs when the current buffer position differs from their sum.
// @fnv 0x00688c90
// src: COMMUNITY 0x00688c90
bool BSTempEffectGeometryDecal::LoadGameTES_00688c90()
{
    bool result5 = 1;
    unsigned short count = 0;
    unsigned int base = 0;
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int blok;
        ((DecalLoad688Reader*)DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&blok, 4);
        if (blok != 0x424c4f4b)
        {
            DecalLoad688Header* form7 = ((DecalLoad688Runtime*)DAT_011de45c)->BGSProjectile_GetExplosion();
            if (form7)
            {
                SaveForm688* obj_2 = (SaveForm688*)TESForm_GetFormByNumericID((void*)(form7->formID));
                Warning_005b5e40(str_01015718, &str_01069ba0, 1932, form7->formID, obj_2->GetName(), form7->version,
                             *(int*)&form7->dataSize);
            }
            else
            {
                Warning_005b5e40(str_010156a8, &str_01069ba0, 1932, ((DecalLoad688Version*)DAT_011de45c)->FUN_008df040());
            }
        }
        base = ((DecalLoad688Buffer*)DAT_011de45c)->FUN_00825c00();
        ((DecalLoad688Reader*)DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&count, 2);
    }
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int cur4 = ((DecalLoad688Buffer*)DAT_011de45c)->FUN_00825c00();
        DecalLoad688Header* form2 = ((DecalLoad688Runtime*)DAT_011de45c)->BGSProjectile_GetExplosion();
        if (form2)
        {
            SaveForm688* obj3 = (SaveForm688*)TESForm_GetFormByNumericID((void*)(form2->formID));
            if (cur4 > count + base)
            {
                Warning_005b5e40(str_01015588, cur4 - (count + base), &str_01069ba0, 2104, form2->formID, obj3->GetName(),
                             form2->version, *(int*)&form2->dataSize);
            }
            else if (cur4 < count + base)
            {
                Warning_005b5e40(str_01015500, (count + base) - cur4, &str_01069ba0, 2104, form2->formID, obj3->GetName(),
                             form2->version, *(int*)&form2->dataSize);
            }
        }
        else
        {
            if (cur4 > count + base)
            {
                Warning_005b5e40(str_010154a0, cur4 - (count + base), &str_01069ba0, 2104,
                             ((DecalLoad688Version*)DAT_011de45c)->FUN_008df040());
            }
            else if (cur4 < count + base)
            {
                Warning_005b5e40(str_01015440, (count + base) - cur4, &str_01069ba0, 2104,
                             ((DecalLoad688Version*)DAT_011de45c)->FUN_008df040());
            }
        }
    }
    return result5;
}
