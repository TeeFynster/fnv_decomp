#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../include/NiTArray.h"
// fallout_shared/globalfunc_o2_variant.cpp: Holder, SearchObject, ObjectCandidate, BeamPassShader and more (34 functions)

#include <windows.h>
#include "../../include/MEM_CONTEXT.h"
#include "../../include/AutoMemContext.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/hkBool.h"
#include "../../include/hkError.h"
#include "../../include/hkpUnaryAction.h"
// src/fallout_shared/globalfunc_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/globalfunc.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/NiNode.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiPoint3.h"
#include "../../include/LANGUAGE.h"
#include "../../include/hkVector4.h"
#include "../../include/NiStream.h"
#include "../../include/Vec4.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiRefObject.h"
#include "../../include/Transform.h"
#include "../../include/NiPoint3.h"
#include "../../include/bhkRefObject.h"
bool ConvertLocalizedString(const char* input, char* output, unsigned int capacity);
bool UpdateObjectVisibility(NiAVObject* object);
bool RemoveInvalidChildNodes(NiNode* object);
bool HandleUnparentedObjectNode(NiNode* object);
void SetObjectFormID(NiAVObject* object, unsigned int referenceID);
bool IsObjectNetValid(NiObjectNET* object);
float GetAngleFromVector(const NiPoint3& vector);
int CountCollisionObjects(NiAVObject* object, bool skipPhantoms, bool skipBlendObjects, bool skipUnknown);
LANGUAGE GetConfiguredLanguage();
bool IsSettingEnabled();

extern int DAT_0126f74c;
struct BeamStage
{
    void ApplyPairToState(unsigned int);
};
struct InBa
{
    char _0[0x1c];
    int f1c;
    char _1[0xF8];
    int f118;
};
struct OutBa
{
    char _0[0xc];
    InBa* fC;
};
// @fnv 0x00ba6240
// src: XBOX_PDB 0x00ba6240
void __stdcall ParticleShader_SetupGeometryTextures(OutBa* a1)
{
    InBa* p = a1->fC;
    int cond = 0;
    if (p)
        cond = (p->f1c == 0x11);
    InBa* q = cond ? p : 0;
    if (!q)
        return;
    int b = DAT_0126f74c;
    int e = *(int*)(b + 0x24);
    int v = q->f118;
    BeamStage* s = *(BeamStage**)e;
    *(int*)((char*)s + 8) = v;
    s->ApplyPairToState(3);
    ((NiD3DPass*)s)->ApplyRenderStateChanges(false);
}

struct S86870
{
    virtual void d00() = 0;
    virtual void d01() = 0;
    virtual void d02() = 0;
    virtual void d03() = 0;
    virtual void d04() = 0;
    virtual void d05() = 0;
    virtual void d06() = 0;
    virtual void d07() = 0;
    virtual void d08() = 0;
    virtual void d09() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
    virtual void d26() = 0;
    virtual void d27() = 0;
    virtual void d28() = 0;
    virtual void d29() = 0;
    virtual void d30() = 0;
    virtual void d31() = 0;
    virtual void d32() = 0;
    virtual void d33() = 0;
    virtual void d34() = 0;
    virtual void d35() = 0;
    virtual void d36() = 0;
    virtual void d37() = 0;
    virtual void d38() = 0;
    virtual void d39() = 0;
    virtual void d40() = 0;
    virtual void d41() = 0;
    virtual void d42() = 0;
    virtual void d43() = 0;
    virtual void d44() = 0;
    virtual void* GetLink(char* p) = 0;
    void bhkSerializable_LinkObject(NiStream* s);
    void bhkUnaryAction_LinkObject(NiStream* s);
};
// @fnv 0x00c86870
// src: XBOX_PDB 0x00c86870
void S86870::bhkUnaryAction_LinkObject(NiStream* s)
{
    char tmp;
    void* p = GetLink(&tmp);
    NiObject* o = s->GetLoadedObject();
    if (o)
        *(int*)((char*)p + 4) = *(int*)((char*)o + 8);
    bhkSerializable_LinkObject(s);
}

#include "../../include/NiTMallocInterface.h"
#include "../../include/hkOstream.h"
#include "../../include/bhkUnaryAction.h"
template <class T, class A> struct NiTPrimitiveArrayWithAllocator
{
    char _0[8];
    unsigned short m_8;
    unsigned short m_kOutgoingTangent;
    unsigned short m_C;
    unsigned short m_E;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
extern const char* const g_0126811c_arg1;
char* __cdecl _FUN_00a7d330(const char*);
void __stdcall bhkSerializable_GetViewerStrings(NiTPrimitiveArrayWithAllocator<char*, NiTMallocInterface<char*> >*);
// @fnv 0x00c87be0
// src: XBOX_PDB 0x00c87be0
void __stdcall bhkAction_GetViewerStrings(NiTPrimitiveArrayWithAllocator<char*, NiTMallocInterface<char*> >* p)
{
    bhkSerializable_GetViewerStrings(p);
    char* v = _FUN_00a7d330(g_0126811c_arg1);
    unsigned int idx = p->m_kOutgoingTangent;
    if (idx >= p->m_8)
    {
        p->SetSize(p->m_E + idx);
    }
    p->SetAt(idx, v);
}

namespace fnv_00c86790 {
struct RetVal
{
    int a;
    int b;
};
struct Holder
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
    virtual RetVal* MyVirt(int*);
    void FUN_00c87650(NiStream*);
    void bhkUnaryAction_LoadBinary(NiStream*);
};
// @fnv 0x00c86790
// src: XBOX_PDB 0x00c86790
void Holder::bhkUnaryAction_LoadBinary(NiStream* stream)
{
    stream->ResetStreamState();
    FUN_00c87650(stream);
    int tmp;
    RetVal* p = MyVirt(&tmp);
    p->b = 0;
}
}  // namespace fnv_00c86790

short __cdecl FindIndexByKey(void* apSkeleton, const char* apName, int aiUnk);
struct ArmTarget_S
{
    float fA;
    float fB;
    bool bActive;
};
struct ArmIKData_S
{
    char pad00[0x10];
    int iState;
    ArmTarget_S xTarget;
    char pad[0x30 - 0x20];
};
struct ArmBones_S
{
    unsigned short sUpper;
    unsigned short sFore;
    unsigned short sHand;
    bool IsValid() const
    {
        return sUpper != 0xffff && sFore != 0xffff && sHand != 0xffff;
    }
};
struct SkelHolder_S
{
    char pad[0xc];
    void* pSkeleton;
};
struct FUN_00c75460_S
{
    char pad000[0x42];
    bool bEnabled;
    char pad043[0x1a0 - 0x43];
    ArmIKData_S xArms[2];
    char pad200[0x10];
    ArmBones_S xLeft;
    ArmBones_S xRight;
    char pad21c[0x2a4 - 0x21c];
    SkelHolder_S* pHolder;
    bool bhkRagdollController_InitGrabIK();
};
// @fnv 0x00c75460
// src: XBOX_PDB 0x00c75460
bool FUN_00c75460_S::bhkRagdollController_InitGrabIK()
{
    bool bResult = bEnabled;
    if (bResult)
    {
        void* pSkeleton = pHolder->pSkeleton;
        if (pSkeleton)
        {
            xLeft.sUpper = FindIndexByKey(pSkeleton, "Bip01 L UpperArm", 0);
            xLeft.sFore = FindIndexByKey(pSkeleton, "Bip01 L ForeArm", 0);
            xLeft.sHand = FindIndexByKey(pSkeleton, "Bip01 L Hand", 0);
            xRight.sUpper = FindIndexByKey(pSkeleton, "Bip01 R UpperArm", 0);
            xRight.sFore = FindIndexByKey(pSkeleton, "Bip01 R ForeArm", 0);
            xRight.sHand = FindIndexByKey(pSkeleton, "Bip01 R Hand", 0);
            if (!xLeft.IsValid())
                bResult = false;
            if (!xRight.IsValid())
                bResult = false;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        xArms[i].iState = 0;
        xArms[i].xTarget.fA = 0.0f;
        xArms[i].xTarget.fB = 0.0f;
        xArms[i].xTarget.bActive = false;
    }
    return bResult;
}

void __cdecl BSRenderState_SetZFunc(int, int);

// @fnv 0x00ba5de0
// src: XBOX_PDB 0x00ba5de0
void __stdcall ParticleShader_SetupGeometryRenderStates(OutBa* a1, int unused)
{
    InBa* p = a1->fC;
    int c = 0;
    if (p != 0)
    {
        c = (p->f1c == 0x11);
    }
    unsigned int mask = (c != 0) ? 0xffffffffu : 0u;
    InBa* sel = (InBa*)(mask & (unsigned int)p);
    int arr[8];
    arr[0] = 7;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;
    arr[5] = 5;
    arr[6] = 6;
    arr[7] = 0;
    int idx = *(int*)((char*)sel + 0x114);
    BSRenderState_SetZFunc(arr[idx - 1], 0);
}

struct CallTarget_00ba5320
{
    int ParticleShader_UpdateFov();
};
struct SearchObject
{
    int ParticleShader_SetupPassConstants(unsigned int arg0);
};
// @fnv 0x00ba5ed0
// src: XBOX_PDB 0x00ba5ed0
int SearchObject::ParticleShader_SetupPassConstants(unsigned int arg0)
{
    unsigned int callResult0 = (unsigned int)((CallTarget_00ba5320*)this)->ParticleShader_UpdateFov();
    return (int)callResult0;
}

struct S_00c85ef0_Pair
{
    int first;
    int second;
    S_00c85ef0_Pair()
    {}
};
struct S_00c85ef0_Map
{
    S_00c85ef0_Pair FindEntry(int key, int def);
};
struct S_00c85ef0_Ret
{
    __int64 v;
    S_00c85ef0_Ret(__int64 x) : v(x)
    {}
};
// @fnv 0x00c85ef0
// src: XBOX_PDB 0x00c85ef0
S_00c85ef0_Ret bhkWorldObject_GetProperty(S_00c85ef0_Map* map, int key)
{
    int r = 0;
    if (map)
        r = map->FindEntry(key, 0).first;
    return S_00c85ef0_Ret(r);
}

extern int DAT_01268118;

class FUN_00c86720_base
{
  public:
    virtual void unk00();
    ~FUN_00c86720_base();
    int unk04;
};

class FUN_00c86720 : public FUN_00c86720_base
{
  public:
    virtual ~FUN_00c86720();
    void unk08();
};

// @fnv 0x00c86720
FUN_00c86720::~FUN_00c86720()
{
    this->unk08();
    DAT_01268118--;
}

struct FUN_00c867d0_out
{
    void* unk00;
    void* unk04;
};

struct FUN_00c867d0_inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* unk14;
    void* unk18;
};

class FUN_00c867d0_cls
{
  public:
    void* unk00;
    void* unk04;
    FUN_00c867d0_inner* unk08;
    void* bhkAction_CopyCinfo(FUN_00c867d0_out* out);
    void bhkUnaryAction_CopyCinfo(FUN_00c867d0_out* out);
};

// @fnv 0x00c867d0
// src: XBOX_PDB 0x00c867d0
void FUN_00c867d0_cls::bhkUnaryAction_CopyCinfo(FUN_00c867d0_out* out)
{
    this->bhkAction_CopyCinfo(out);

    void* value;
    if (this != 0 && this->unk08 != 0)
        value = this->unk08->unk18;
    else
        value = 0;

    out->unk04 = value;
}


struct FUN_00c86800_Link
{
    int unk00;
    void* m04;
};

struct FUN_00c86800_Node
{
    int unk00;
    int unk04;
    int unk08;
    void* key0C;
};

struct FUN_00c86800_Target
{
    int unk00;
    int unk04;
    void* m08;
};

// GetAt at 0x00a53c30 is the shared NiTMapBase lookup; this clone table uses object-pointer keys.
struct FUN_00c86800_Table
{
    NiTPointerMap<void*, void*>* map;
};

struct FUN_00c86800_Class : S86870
{
    void bhkUnaryAction_CopyMembers(int a1, FUN_00c86800_Table* a2);
    void bhkSerializable_CopyMembers(int a1, FUN_00c86800_Table* a2);
};

// @fnv 0x00c86800
// src: XBOX_PDB 0x00c86800
void FUN_00c86800_Class::bhkUnaryAction_CopyMembers(int a1, FUN_00c86800_Table* a2)
{
    char key;
    FUN_00c86800_Link* link = (FUN_00c86800_Link*)GetLink(&key);
    FUN_00c86800_Node* node = (FUN_00c86800_Node*)link->m04;
    void* keyValue = node ? node->key0C : 0;
    FUN_00c86800_Table* table = a2;
    link->m04 = 0;
    if (keyValue != 0)
    {
        if (table->map->GetAt(keyValue, (void*&)a2))
        {
            FUN_00c86800_Target* target = (FUN_00c86800_Target*)a2;
            link->m04 = target ? target->m08 : 0;
        }
    }
    bhkSerializable_CopyMembers(a1, table);
}

struct FUN_00c868f0_inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_18;
};

class FUN_00c868f0_cls
{
  public:
    int unk00;
    int unk04;
    FUN_00c868f0_inner* m_08;
    bool BSAnimNotes_IsEqual(FUN_00c868f0_cls* other);
    unsigned char bhkUnaryAction_IsEqual(FUN_00c868f0_cls* other);
};

// @fnv 0x00c868f0
// src: XBOX_PDB 0x00c868f0
unsigned char FUN_00c868f0_cls::bhkUnaryAction_IsEqual(FUN_00c868f0_cls* other)
{
    unsigned char result = this->BSAnimNotes_IsEqual(other);
    if (result)
    {
        FUN_00c868f0_inner* l = 0;
        if (this != 0)
        {
            l = this->m_08;
        }
        void* left = l != 0 ? l->m_18 : 0;
        FUN_00c868f0_inner* r = 0;
        if (other != 0)
        {
            r = other->m_08;
        }
        void* right = r != 0 ? r->m_18 : 0;
        result = left == right;
    }
    return result;
}

extern __declspec(thread) unsigned int threadContext;
inline unsigned int& currentAllocationMode()
{
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&threadContext) + 0x2b4);
}

class ScopedAllocationMode
{
    unsigned int previous;

  public:
    ScopedAllocationMode() : previous(currentAllocationMode())
    {
        currentAllocationMode() = 16;
    }
    ~ScopedAllocationMode()
    {
        currentAllocationMode() = previous;
    }
};

class ObjectCandidate
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual int QueryValue();
    virtual void slot38();
    virtual void slot39();
    virtual void Reset();
    int unk04;
    int activeObject;
    bool bhkUnaryAction_Add(class Item* item);
    void ProcessEntity(Item*);
};
class Item
{
  public:
    int unk00;
    int unk04;
    int matchingValue;
    void bhkWorld_Add_00c6b3c0(int);
};
// @fnv 0x00c86ab0
// src: XBOX_PDB 0x00c86ab0
bool ObjectCandidate::bhkUnaryAction_Add(Item* item)
{
    ScopedAllocationMode guard;
    int current = this ? activeObject : 0;
    bool result = false;
    if (current != 0)
    {
        if (item)
        {
            if (QueryValue() != item->matchingValue)
            {
                Reset();
                ProcessEntity(item);
                item->bhkWorld_Add_00c6b3c0(current);
                result = true;
            }
        }
        else
        {
            Reset();
        }
    }
    return result;
}

extern __declspec(thread) int g_tlsHeapContext;

int sprintf_s(char* buffer, unsigned int size, const char* format, ...);
char* __cdecl NiGetViewerString_00a7d5e0(const char* className, const char* name);

struct HeapContextGuard
{
    int saved;
    HeapContextGuard(int ctx)
    {
        saved = g_tlsHeapContext;
        g_tlsHeapContext = ctx;
    }
    ~HeapContextGuard()
    {
        g_tlsHeapContext = saved;
    }
};

extern const char* g_name86b80;
typedef NiTPrimitiveArrayWithAllocator<char*, NiTMallocInterface<char*> > StringArray;

inline void AddString(StringArray* arr, char*& s)
{
    unsigned int idx = arr->m_kOutgoingTangent;
    if (idx >= arr->m_8)
        arr->SetSize(arr->m_E + idx);
    arr->SetAt(idx, s);
}

struct HkObject86b80
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_pHkObject;
};

struct Wrapper86b80
{
    int unk00;
    int unk04;
    HkObject86b80* m_pObject;

    void bhkAction_GetViewerStrings(StringArray* arr);
    void bhkUnaryAction_GetViewerStrings(StringArray* arr);
};

// @fnv 0x00c86b80
// src: XBOX_PDB 0x00c86b80
void Wrapper86b80::bhkUnaryAction_GetViewerStrings(StringArray* arr)
{
    HeapContextGuard guard(0x10);
    bhkAction_GetViewerStrings(arr);
    char* s = _FUN_00a7d330(g_name86b80);
    AddString(arr, s);
    void* p;
    if (this && m_pObject)
        p = m_pObject->m_pHkObject;
    else
        p = 0;
    char buf[0x20];
    sprintf_s(buf, 0x20, "0x%08X", p);
    s = NiGetViewerString_00a7d5e0("hkpRigidBody", buf);
    AddString(arr, s);
}

extern int DAT_01268124;

class FUN_00c86cb0_base
{
  public:
    virtual void unk00();
    ~FUN_00c86cb0_base();
    int unk04;
};

class FUN_00c86cb0 : public FUN_00c86cb0_base
{
  public:
    virtual ~FUN_00c86cb0();
    void unk08();
};

// @fnv 0x00c86cb0
FUN_00c86cb0::~FUN_00c86cb0()
{
    this->unk08();
    DAT_01268124--;
}

struct InnerData
{
    float unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    hkVector4 q20;
    hkVector4 q30;
    float x40, y44, z48, w4c;
};
struct OutputData
{
    unsigned int unk00, unk04, unk08, unk0c;
    hkVector4 a10;
    hkVector4 b20;
    float x30, y34, z38, w3c;
};
void __stdcall bhkUnaryAction_CopyCinfo(OutputData*);
struct FUN_00c86d20_Class
{
    int unk00, unk04;
    InnerData* inner;
    void __thiscall bhkMouseSpringAction_CopyCinfo(OutputData* dest);
};
// @fnv 0x00c86d20
// src: XBOX_PDB 0x00c86d20
void FUN_00c86d20_Class::bhkMouseSpringAction_CopyCinfo(OutputData* dest)
{
    bhkUnaryAction_CopyCinfo(dest);
    dest->x30 = (this && inner) ? inner->x40 : 0.0f;
    dest->y34 = (this && inner) ? inner->y44 : 0.0f;
    dest->w3c = (this && inner) ? inner->w4c : 0.0f;
    if (this)
    {
        InnerData* current = inner;
        if (current)
        {
            dest->a10.SetQuaternionComponentsFromVector(&current->q20);
            dest->b20.SetQuaternionComponentsFromVector(&current->q30);
            dest->z38 = current->z48;
            return;
        }
    }
    dest->a10.x = 0.0f;
    dest->a10.y = 0.0f;
    dest->a10.z = 0.0f;
    dest->a10.w = 0.0f;
    dest->b20.x = 0.0f;
    dest->b20.y = 0.0f;
    dest->b20.z = 0.0f;
    dest->b20.w = 0.0f;
    dest->z38 = 0.0f;
}

struct FUN_00c871c0_tls
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
extern __declspec(thread) FUN_00c871c0_tls g_tls;

struct FUN_00c871c0_pool
{
    void MemoryManager_Deallocate(int);
};
extern FUN_00c871c0_pool DAT_011f6238;

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

class FUN_00c871c0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    char* m_0c;
    void bhkBoxShape_KillCinfo(bool flag);
};

// @fnv 0x00c871c0
// src: XBOX_PDB 0x00c871c0
void FUN_00c871c0_cls::bhkBoxShape_KillCinfo(bool flag)
{
    TlsFlagGuard guard;
    if (flag)
    {
        char* p = m_0c;
        if (p != 0)
        {
            unsigned char len = (unsigned char)p[-1];
            DAT_011f6238.MemoryManager_Deallocate((int)(p - len));
        }
        m_0c = 0;
    }
}

extern __declspec(thread) int g_iC878C0AllocTag;

struct BC878C0AllocTagScope
{
    int m_iSaved;

    BC878C0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC878C0AllocTag;
        g_iC878C0AllocTag = aiAllocationTag;
    }
    ~BC878C0AllocTagScope()
    {
        g_iC878C0AllocTag = m_iSaved;
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

typedef NiTArray<char*, NiTMallocInterface<char*> > BC878C0StringArray;

extern const char* g_pcC878C0Name;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);

class FUN_00c878c0_cls
{
  public:
    void AddDebugStrings(BC878C0StringArray* pkArray);
    void bhkSerializable_GetViewerStrings(BC878C0StringArray* pkArray);
};

// @fnv 0x00c878c0
// src: XBOX_PDB 0x00c878c0
void FUN_00c878c0_cls::bhkSerializable_GetViewerStrings(BC878C0StringArray* pkArray)
{
    BC878C0AllocTagScope kScope(0x10);
    AddDebugStrings(pkArray);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcC878C0Name);
    pkArray->Add(pcName);
}

extern int DAT_01268154;
struct FUN_00c877b0
{
    virtual ~FUN_00c877b0();
};
struct FUN_00c87970 : FUN_00c877b0
{
    virtual ~FUN_00c87970();
    void bhkSerializable_Kill();
};
// @fnv 0x00c87970
FUN_00c87970::~FUN_00c87970()
{
    bhkSerializable_Kill();
    --DAT_01268154;
}

// FUN_00ead0d0 - walks a singly linked list and returns the first node whose
// flag field is set (0 if the list ends or the head pointer is null).
// The original was written as a tail-recursive helper; MSVC's tail-call
// optimisation turns it into the loop that is actually emitted here.
struct FadeNodeEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FadeNodeEntry* m_pNext;  // +0x18
    int m_iFlag;             // +0x1c
};

// @fnv 0x00ead0d0
// src: XBOX_PDB 0x00ead0d0
FadeNodeEntry* __stdcall NiCollisionData_FindAncestorWithCollisionData(FadeNodeEntry* pHead)
{
    if (pHead == 0)
    {
        return 0;
    }

    FadeNodeEntry* pNode = pHead->m_pNext;
    if (pNode == 0)
    {
        return 0;
    }

    if (pNode->m_iFlag != 0)
    {
        return pNode;
    }

    return NiCollisionData_FindAncestorWithCollisionData(pNode);
}

struct InBaFull
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    int f1c;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC, unk100, unk104;
    int f108;
    int f10C;
};
int __cdecl GetTableValue(int);
void __cdecl DevCallbackMode(int, int);
void __cdecl AddToTwoCounters(int, int, int);

// @fnv 0x00ba5e60
// src: XBOX_PDB 0x00ba5e60
void __stdcall ParticleShader_SetupGeometryAlphaBlending(OutBa* a1)
{
    InBaFull* p = reinterpret_cast<InBaFull*>(a1->fC);
    int bMatch = 0;
    if (p != 0)
    {
        bMatch = (p->f1c == 0x11);
    }
    InBaFull* q = bMatch ? p : 0;
    DevCallbackMode(1, 0);
    if (q != 0)
    {
        AddToTwoCounters(GetTableValue(q->f108), GetTableValue(q->f10C), 0);
    }
    else
    {
        AddToTwoCounters(6, 7, 0);
    }
}

struct CollisionObjectCountContext
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    int iCount;
    void* pUserData;
    void* pAuxiliaryData;
    unsigned int uiFilterFlags;
};
void bhkWorld_DoObjectRec(NiAVObject*, CollisionObjectCountContext*,
                  void (*)(NiCollisionObject*, CollisionObjectCountContext*));

struct C69EE0Properties
{
    int unk;
    int unkCur;
    int unkValue;
    unsigned int m_uiValue1;
};
extern "C" C69EE0Properties* GetExtraDataChecked(NiAVObject* pkObject);
static inline unsigned int C69EE0IsEnabled(NiAVObject* pkObject)
{
    C69EE0Properties* pkProps = GetExtraDataChecked(pkObject);
    return pkProps ? (pkProps->m_uiValue1 & 2) : 0;
}
extern void (*DAT_011afe8c)(NiCollisionObject*, CollisionObjectCountContext*);

// @fnv 0x00c69ee0
// src: XBOX_PDB 0x00c69ee0
bool bhkWorld_RemoveObjects(NiAVObject* pkObject, bool bRecurse, bool bForce)
{
    bool bResult = false;
    if (pkObject && (bForce || C69EE0IsEnabled(pkObject)))
    {
        bResult = bForce;
        CollisionObjectCountContext kContext;
        kContext.pCurrentObject = 0;
        kContext.bRecurse = bRecurse;
        kContext.uiTraversalFlags = 1;
        if (DAT_011afe8c)
            bhkWorld_DoObjectRec(pkObject, &kContext, DAT_011afe8c);
    }
    return bResult;
}

__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile const*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile const*);

struct StageReturn
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int m_uiRefCount;
    void ReturnToPool();
    void Release()
    {
        if (--m_uiRefCount == 0)
            ReturnToPool();
    }
};

void __cdecl AssignStageFromPool(StageReturn*&);

struct StageReturnPtr
{
    StageReturn* m_pStage;
    StageReturnPtr() : m_pStage(0)
    {}
    ~StageReturnPtr()
    {
        if (m_pStage)
        {
            m_pStage->Release();
        }
    }
    operator StageReturn*&()
    {
        return m_pStage;
    }
    operator StageReturn*() const
    {
        return m_pStage;
    }
};



// This unit inlines the atomic operations used by its reference pointers.
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T> class NiD3DPointer
{
  public:
    T* m_pObject;
    NiD3DPointer(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            static_cast<NiRefObject*>(m_pObject)->IncRefCount();
    }
    ~NiD3DPointer()
    {
        if (m_pObject)
            static_cast<NiRefObject*>(m_pObject)->DecRefCount();
    }
    NiD3DPointer& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                static_cast<NiRefObject*>(m_pObject)->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                static_cast<NiRefObject*>(m_pObject)->IncRefCount();
        }
        return *this;
    }
    NiD3DPointer& operator=(const NiD3DPointer& r)
    {
        return *this = r.m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct D3DRenderStateGroup
{
    void SetRenderState(unsigned int uiState, unsigned int uiValue, bool bSave);
};
D3DRenderStateGroup* __cdecl FUN_00e7f5d0();

inline unsigned int NiD3DPass::GetStageCount() const
{
    return m_uiStageCount;
}

inline void NiD3DPass::SetRenderState(unsigned int state, unsigned int value, bool save)
{
    if (!m_pkRenderStateGroup)
        m_pkRenderStateGroup = FUN_00e7f5d0();
    m_pkRenderStateGroup->SetRenderState(state, value, save);
}

// The shared pass does not yet declare the indexed stage setter.
void SetPassStage(NiD3DPass*, unsigned int, StageReturn*);
typedef void (__thiscall *SetPassStageFunction)(NiD3DPass*, unsigned int, StageReturn*);

void __cdecl ConfigureBeamStage(StageReturn*, int, int, int, int);

struct NiD3DPassPtr
{
    NiD3DPass* m_pObject;
    NiD3DPassPtr() : m_pObject(0)
    {}
    ~NiD3DPassPtr()
    {
        if (m_pObject)
        {
            if (--m_pObject->m_uiRefCount == 0)
            {
                m_pObject->DestroyPass();
            }
        }
    }
    NiD3DPassPtr& operator=(const NiD3DPassPtr& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
            {
                if (--m_pObject->m_uiRefCount == 0)
                {
                    m_pObject->DestroyPass();
                }
            }
            m_pObject = ptr.m_pObject;
            if (m_pObject)
            {
                ++m_pObject->m_uiRefCount;
            }
        }
        return *this;
    }
    operator NiD3DPass*() const
    {
        return m_pObject;
    }
    NiD3DPass* operator->() const
    {
        return m_pObject;
    }
};

class BeamPassShader
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70;
    NiD3DPassPtr m_spPass0;
    NiD3DPassPtr m_spPass1;
    NiD3DPointer<NiD3DPixelShader> m_spPixelShaderObject;
    NiD3DPointer<NiD3DVertexShader> m_spVertexShaderObject;

    void UpdateFields_00ba59e0();
};

// @fnv 0x00ba59e0
// src: GUESS 0x00ba59e0 (confidence: low)
void BeamPassShader::UpdateFields_00ba59e0()
{
    NiD3DPassPtr spRenderPass;
    StageReturnPtr spStage;

    spRenderPass = m_spPass0;
    if (spRenderPass->GetStageCount() < 1)
    {
        AssignStageFromPool(spStage);
        ConfigureBeamStage(spStage, 0, 1, 2, 1);
        reinterpret_cast<SetPassStageFunction>(SetPassStage)(spRenderPass, spRenderPass->m_uiCurrentStage, spStage);
    }
    reinterpret_cast<NiD3DPointer<NiD3DPixelShader>&>(spRenderPass->m_spVertexShader) = m_spPixelShaderObject;
    reinterpret_cast<NiD3DPointer<NiD3DVertexShader>&>(spRenderPass->m_spPixelShader) = m_spVertexShaderObject;
    spRenderPass->SetRenderState(0xa8, 0xf, true);
    spRenderPass->SetRenderState(0x1b, 1, true);
    spRenderPass->SetRenderState(0x13, 5, true);
    spRenderPass->SetRenderState(0x14, 6, true);
    spRenderPass->SetRenderState(0xf, 0, true);
    spRenderPass->SetRenderState(0x34, 0, true);
    spRenderPass->SetRenderState(7, 1, true);
    spRenderPass->SetRenderState(0x17, 4, true);
    spRenderPass->SetRenderState(0xe, 0, true);

    spRenderPass = m_spPass1;
    if (spRenderPass->GetStageCount() < 1)
    {
        AssignStageFromPool(spStage);
        ConfigureBeamStage(spStage, 0, 1, 2, 1);
        reinterpret_cast<SetPassStageFunction>(SetPassStage)(spRenderPass, spRenderPass->m_uiCurrentStage, spStage);
    }
    reinterpret_cast<NiD3DPointer<NiD3DPixelShader>&>(spRenderPass->m_spVertexShader) = m_spPixelShaderObject;
    reinterpret_cast<NiD3DPointer<NiD3DVertexShader>&>(spRenderPass->m_spPixelShader) = m_spVertexShaderObject;
    spRenderPass->SetRenderState(0xa8, 0xf, true);
    spRenderPass->SetRenderState(0x1b, 1, true);
    spRenderPass->SetRenderState(0x13, 5, true);
    spRenderPass->SetRenderState(0x14, 6, true);
    spRenderPass->SetRenderState(0xf, 0, true);
    spRenderPass->SetRenderState(0x34, 0, true);
    spRenderPass->SetRenderState(7, 1, true);
    spRenderPass->SetRenderState(0x17, 4, true);
    spRenderPass->SetRenderState(0xe, 0, true);
}

void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);

// The original scratch vector is left uninitialized.
struct Update
{
    void NiDX9Renderer_SetModelTransform(Transform*, int);
};
struct Shader
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void apply(void*, void*, int, int, int, void*, int, Transform*, void*, int, int);
};
struct Source
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
    void* unk60;
    int unk64;
    int unk68;
    bool unk6c;
    int unk70;
    int unk74;
    int unk78;
    float unk7c;
    int unk80;
    float unk84;
    int unk88;
    float unk8c;
    NiPoint3 unk90;
    NiPoint3 unk9c;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    NiPoint3 unkb8;
    Vec4 unkc4;
    Vec4 unkd4;
    Vec4 unke4;
    Vec4 unkf4;
    float unk104;
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
    float unk130;
    float unk134;
    float unk138;
    NiPoint3 unk13c;
    float unk148;
};
struct Arg
{
    int unk00;
    int unk04;
    int unk08;
    Source* unk0c;
};
struct Extra
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
};
struct Geom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* unk20;
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
    // Geometry stores the 0x34-byte rotation/position/scale transform prefix.
    float unk68[13];
    int unk9c;
    int unka0;
    int unka4;

    Transform& GetWorldTransform()
    {
        return *reinterpret_cast<Transform*>(unk68);
    }
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    Extra* unkb8;
    int unkbc;
};
struct Manager
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
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    void* unk5c;
};
extern Geom** DAT_011f91e0;
extern int DAT_011f91c0;
extern int DAT_0126f74c;
extern int DAT_012003ec;
extern int DAT_011f4288;
struct Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Update* unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Shader* unk30;
    Shader* unk34;
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
    void* unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    float unk84;
    float unk88;
    float unk8c;
    float unk90;
    NiPoint3 unk94;
    int unka0;
    Vec4 unka4;
    NiPoint3 unkb4;
    float unkc0;
    float unkc4;
    float unkc8;
    int unkcc;
    int unkd0;
    NiPoint3 unkd4;
    NiPoint3 unke0;
    NiPoint3 unkec;
    float unkf8;
    Vec4 unkfc;
    Vec4 unk10c;
    Vec4 unk11c;
    void ParticleShader_SetupGeometryConstants(Arg*);
};
inline int isSource(Source* p)
{
    if (!p)
        return false;
    return p->unk1c == 17;
}
// @fnv 0x00ba5ee0
// src: XBOX_PDB 0x00ba5ee0
void Obj::ParticleShader_SetupGeometryConstants(Arg* arg)
{
    Geom* geom = *DAT_011f91e0;
    unk18->NiDX9Renderer_SetModelTransform(&geom->GetWorldTransform(), 0);
    Source* raw = arg->unk0c;
    Source* source = isSource(raw) ? raw : 0;
    if (source)
    {
        unk84 = source->unk104;
        unk88 = source->unk7c;
        unk8c = source->unk84;
        unk90 = source->unk8c;
        memcpy(&unkd4, &source->unk90, sizeof(NiPoint3));
        memcpy(&unke0, &source->unk9c, sizeof(NiPoint3));
        NiPoint3 point = source->unk13c;
        if (!source->unk6c)
        {
            // These NiTransform operations use only rotation, position, and scale.
            float transformStorage[13];
            Transform& transform = *reinterpret_cast<Transform*>(transformStorage);
            geom->GetWorldTransform().FUN_004b4880(&transform);
            NiPoint3 result;
            NiPoint3* __restrict moved = transform.ComputeValue_00524c40(&result, &point);
            memcpy(&point, moved, sizeof(NiPoint3));
        }
        unkec.x = point.x;
        unkec.y = point.y;
        unkec.z = point.z;
        unkf8 = source->unk148;
        unkfc = source->unkc4;
        unk10c = source->unkd4;
        unk11c = source->unke4;
        unk94.x = source->unkb8.x;
        unk94.y = source->unkb8.y;
        unk94.z = source->unkb8.z;
        unka4.x = source->unkf4.x;
        unka4.y = source->unkf4.y;
        unka4.z = source->unkf4.z;
        unka4.w = source->unkf4.w;
        if (source->unk6c)
        {
            unkb4.x = geom->GetWorldTransform().position.x;
            unkb4.y = geom->GetWorldTransform().position.y;
            unkb4.z = geom->GetWorldTransform().position.z;
        }
        else
        {
            unkb4.z = unkb4.y = unkb4.x = 0.0f;
        }
        unkc0 = source->unk130;
        unkc4 = 1.0f / source->unk134;
        unkc8 = 1.0f / source->unk138;
        if (!DAT_012003ec)
            DAT_012003ec = DAT_011f91c0 >= 2 ? 78 : 26;
        FUN_00ec44d0(unk70, source->unk60, DAT_012003ec * 48);
    }
    void* data = geom->unk20 ? geom->unk20 : &DAT_011f4288;
    int extra = geom->unkb8->unk34;
    int other = geom->unkbc;
    if (unk30)
    {
        void* resource = ((Manager*)DAT_0126f74c)->unk44;
        if (resource)
            unk30->apply(resource, geom, other, 0, extra, arg, 0, &geom->GetWorldTransform(), data, 0, 1);
    }
    if (unk34)
    {
        void* resource = ((Manager*)DAT_0126f74c)->unk5c;
        if (resource)
            unk34->apply(resource, geom, other, 0, extra, arg, 0, &geom->GetWorldTransform(), data, 0, 1);
    }
}

struct C868_L3
{
    int unk00, unk04, unk08;
    void* m_0c;
};

struct C868_L2
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    C868_L3* m_18;
};

struct C868_Iface
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30(void* p);
};

extern "C" void _ReadWriteBarrier(void);

class FUN_00c868b0_cls
{
  public:
    int unk00, unk04;
    C868_L2* m_08;
    void SaveSerializeData(C868_Iface* a1);
    void bhkUnaryAction_SaveBinary(C868_Iface* a1);
};

// @fnv 0x00c868b0
// src: XBOX_PDB 0x00c868b0
void FUN_00c868b0_cls::bhkUnaryAction_SaveBinary(C868_Iface* a1)
{
    C868_L3* l3;
    if (this != 0 && m_08 != 0)
        l3 = m_08->m_18;
    else
        l3 = 0;
    _ReadWriteBarrier();

    void* z;
    if (l3 != 0)
        z = l3->m_0c;
    else
        z = 0;

    a1->vfn_30(z);
    this->SaveSerializeData(a1);
}

extern int DAT_01268154;
extern int DAT_01268118;
extern int DAT_01268124;
extern int DAT_0102016c;
extern int DAT_0102009c;
extern int DAT_0101ffcc;


class TESObjectDoorController
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
};

class RefObjC86D : public TESObjectDoorController
{
  public:
    int* m_vptr;
    int unk04;
    int unk08;
    int unk0C;

    __forceinline RefObjC86D()
    {
        ((bhkRefObject*)this)->Initialize();
        m_vptr = &DAT_0102016c;
        unk0C = 0;
        DAT_01268154++;
        m_vptr = &DAT_0102009c;
        DAT_01268118++;
        m_vptr = &DAT_0101ffcc;
        DAT_01268124++;
    }
};

// @fnv 0x00c86de0
// src: EXE 0x00c86de0
RefObjC86D* __cdecl bhkMouseSpringAction_CreateObject()
{
    return new RefObjC86D;
}

void bhkSerializable_CloneCritLock();
void bhkSerializable_CloneCritUnlock();
void* __cdecl Object_DispatchCommandFour(unsigned int bytes);
extern int DAT_0102016c;
extern int DAT_0102009c;
extern int DAT_0101ffcc;

class AllocatedNode
{
  public:
    int* vtable;
    int unk04;
    int unk08;
    int unk0c;

    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    void UpdateState_00c87c30();

    AllocatedNode()
    {
        UpdateState_00c87c30();
        vtable = &DAT_0102016c;
        unk0c = 0;
        ++DAT_01268154;
        vtable = &DAT_0102009c;
        ++DAT_01268118;
        vtable = &DAT_0101ffcc;
        ++DAT_01268124;
    }
};

class FUN_00c87010_cls : public FUN_00c86800_Class
{
  public:
    AllocatedNode* bhkMouseSpringAction_CreateClone(FUN_00c86800_Table* p);
};

// @fnv 0x00c87010
// src: XBOX_PDB 0x00c87010
AllocatedNode* FUN_00c87010_cls::bhkMouseSpringAction_CreateClone(FUN_00c86800_Table* p)
{
    ScopedAllocationMode mode;
    bhkSerializable_CloneCritLock();
    AllocatedNode* node = new AllocatedNode();
    bhkUnaryAction_CopyMembers((int)node, p);
    bhkSerializable_CloneCritUnlock();
    return node;
}

// Retained locally: include/hkOstream.h lacks the (char*, int, hkBool) constructor at 0x00cc0500.
extern hkError* g_hkErrorInstance;

// This is a Bethesda entity wrapper: virtual slots 37/39/50 and flags at +0x10 do not match hkpWorld.
struct EntityActionInterface
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
    virtual unsigned int IsLocked();
    virtual void v38();
    virtual void AddActionPre(hkpUnaryAction* a);
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
    virtual void AddActionPost(hkpUnaryAction* a);
    int unk04;
    int unk08;
    int unk0c;
    unsigned char m_flags;
};
struct hkWorldHolderS
{
    int unk00;
    int unk04;
    int unk08;
    EntityActionInterface* m_pOwningWorld;
};
struct bhkWorldRefS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkWorldHolderS* m_pHkObject;
};
// @fnv 0x00c86940
// src: XBOX_PDB 0x00c86940
void bhkUnaryAction::ProcessEntity(hkpUnaryAction* action)
{
    TlsFlagGuard mode;
    hkWorldHolderS* holder = this && m_pHavokObject ? reinterpret_cast<bhkWorldRefS*>(m_pHavokObject)->m_pHkObject : 0;
    _ReadWriteBarrier();
    if (holder)
    {
        EntityActionInterface* world = holder->m_pOwningWorld;
        if (world)
        {
            unsigned int locked = world->IsLocked();
            if (!locked && reinterpret_cast<unsigned int>(action->m_pEntity) <= locked)
            {
                world->AddActionPre(action);
                if (!(world->m_flags & 0x30))
                {
                    {
                        char buf[512];
                        hkOstream ostr(buf, sizeof(buf), true);
                        ostr << "A unary action is being added to the world before its target entities.\n";
                        g_hkErrorInstance->message(
                            1, 0x234f24fc, buf, "D:\\_Fallout3\\Platforms\\Common\\Code\\BSHavok\\bhkUnaryAction.cpp",
                            200);
                    }
                    world->AddActionPost(action);
                }
            }
        }
    }
}

extern __declspec(thread) unsigned int t_uiMemContext7100;
inline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(t_uiMemContext7100);
    t_uiMemContext7100 = context;
}
inline AutoMemContext::~AutoMemContext()
{
    t_uiMemContext7100 = m_eMemoryContext;
}

extern MemoryManager g_kMemoryManager;

class __declspec(align(16)) Aligned7100
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        unsigned char* pucMem = (unsigned char*)g_kMemoryManager.Allocate(uiSize + 0x10);
        unsigned char ucOffset = (unsigned char)(0x10 - ((unsigned int)pucMem & 0xf));
        pucMem += ucOffset;
        pucMem[-1] = ucOffset;
        return pucMem;
    }
    Aligned7100() throw();
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
};

class Owner7100
{
  public:
    Aligned7100* bhkMouseSpringAction_CreateCinfo(bool* pbCreated);
    void SetObject(Aligned7100* pkObject);

    int unk00;
    int unk04;
    int m_iActive;
    Aligned7100* m_pPointer;
};

// @fnv 0x00c87100
// src: XBOX_PDB 0x00c87100
Aligned7100* Owner7100::bhkMouseSpringAction_CreateCinfo(bool* pbCreated)
{
    AutoMemContext kContext(0x10);
    bool bCreate = m_pPointer == 0;
    *pbCreated = bCreate;
    if (bCreate)
    {
        m_pPointer = new Aligned7100;
        if (m_iActive)
            SetObject(m_pPointer);
    }
    return m_pPointer;
}

struct TlsBlock_t
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
    unsigned int m_2b4;
};

extern __declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    unsigned int m_saved;
    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct S00c87a70_Obj : ObjectCandidate
{
    bool bhkAction_Add(Item* arg);
};

// @fnv 0x00c87a70
// src: XBOX_PDB 0x00c87a70
bool S00c87a70_Obj::bhkAction_Add(Item* arg)
{
    TlsGuard_t guard;
    int active = this ? activeObject : 0;
    bool result = false;
    if (active != 0)
    {
        if (arg != 0)
        {
            int v = QueryValue();
            if (v != arg->matchingValue)
            {
                Reset();
                arg->bhkWorld_Add_00c6b3c0(active);
                result = true;
            }
        }
        else
        {
            Reset();
        }
    }
    return result;
}

struct PhysWorld_c87b
{
    bool AddItem(void* pkEntity);
};

struct World_c87b
{
    // the Havok world pointer lives at +0x350 of the (large) world object
    PhysWorld_c87b* GetPhysWorld() const
    {
        return *(PhysWorld_c87b* const*)((const char*)this + 0x350);
    }
};

class EntityOwner_c87b
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
    virtual World_c87b* GetWorld();
    int unk04;
    void* m_pkEntity;

    PhysWorld_c87b* GetPhysWorld()
    {
        World_c87b* pkWorld = GetWorld();
        return pkWorld ? pkWorld->GetPhysWorld() : 0;
    }
    bool bhkAction_Remove();
};

// @fnv 0x00c87b40
// src: XBOX_PDB 0x00c87b40
bool EntityOwner_c87b::bhkAction_Remove()
{
    HeapContextGuard kContext(0x10);
    bool bResult = false;
    PhysWorld_c87b* pkPhysWorld = GetPhysWorld();
    if (pkPhysWorld)
        bResult = pkPhysWorld->AddItem(m_pkEntity);
    return bResult;
}


struct RefPtr6b3c0
{
    NiRefObject* m_p;
    RefPtr6b3c0(NiRefObject* p)
    {
        m_p = p;
        if (m_p)
            m_p->IncRefCount();
    }
    RefPtr6b3c0(const RefPtr6b3c0& other)
    {
        m_p = other.m_p;
        if (m_p)
            m_p->IncRefCount();
    }
    __declspec(noinline) RefPtr6b3c0& operator=(const RefPtr6b3c0& other)
    {
        if (m_p != other.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = other.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
    __forceinline ~RefPtr6b3c0()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    operator NiRefObject*() const
    {
        return m_p;
    }
};
struct Entry6b3c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NiRefObject* unk10;
    void Prepare();  // 0xc90510
};

struct Target6b3c0
{
    void Add(Entry6b3c0* entry);  // 0xc97370
};

extern MemoryManager g_memoryManager6b3c0;

struct Node6b3c0
{
    RefPtr6b3c0 m_ptr;
    Node6b3c0* m_next;
    Node6b3c0(const RefPtr6b3c0& ptr) : m_ptr(ptr), m_next(0)
    {}
    static void* operator new(unsigned int size)
    {
        return g_memoryManager6b3c0.Allocate(size);
    }
};

struct RefSet6b3c0
{
    RefPtr6b3c0 m_pTileTemplate;
    Node6b3c0* m_saved;
    void Insert(const RefPtr6b3c0& ref);  // 0xc68b50
};

extern bool DAT_012677a2;
extern unsigned int DAT_011afe80;

class World6b3c0
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
    virtual Target6b3c0* GetTarget();  // +0x94
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int* unk2C;
    unsigned int unk30;
    int unk34;
    int unk38;
    Entry6b3c0** pending3C;
    unsigned int pendingCount40;
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
    RefSet6b3c0 refs90;

    void Flush(int* items, unsigned int count);  // 0xc674d0
    void Step1();                                // 0xc676e0
    void Step2();                                // 0xc6aac0
    void Step3();                                // 0xc67850
    void bhkWorld_Add_00c6b3c0(Entry6b3c0* entry);
};

// Defined here (as in the original unit) so the compiler sees Insert never modifies its argument.
void RefSet6b3c0::Insert(const RefPtr6b3c0& ref)
{
    if (ref.m_p == 0)
        return;
    if (m_pTileTemplate.m_p != 0)
    {
        Node6b3c0* node = new Node6b3c0(m_pTileTemplate);
        node->m_next = m_saved;
        m_saved = node;
    }
    m_pTileTemplate = ref;
}

// @fnv 0x00c6b3c0
// src: XBOX_PDB 0x00c6b3c0
void World6b3c0::bhkWorld_Add_00c6b3c0(Entry6b3c0* entry)
{
    TlsFlagGuard guard;
    if (this != 0)
    {
        Target6b3c0* target = GetTarget();
        if (target != 0)
        {
            if (unk18 > 0)
            {
                if (pendingCount40 >= 100)
                {
                    if (unk30 > 0 && !DAT_012677a2)
                    {
                        if (unk30 >= 3000)
                            unk30 = 3000;
                        unsigned int total = unk30;
                        unsigned int count = DAT_011afe80;
                        if (total < count)
                            count = total;
                        unsigned int rest = total - count;
                        Flush(unk2C + rest, count);
                        unk30 = rest;
                        DAT_012677a2 = true;
                    }
                    Step1();
                    Step2();
                    Step3();
                }
                entry->Prepare();
                pending3C[pendingCount40] = entry;
                pendingCount40++;
            }
            else
            {
                target->Add(entry);
            }
            if (entry != 0)
            {
                NiRefObject* obj = entry->unk10;
                if (obj != 0)
                {
                    RefPtr6b3c0 sp(obj);
                    refs90.Insert(sp);
                }
            }
        }
    }
}

inline void Swap86(unsigned long* p)
{
    *p = _byteswap_ulong(*p);
}
struct NiStream86
{
    char _pad[0x1e5];
    unsigned char m_bSameEndian;
};
struct Block86
{
    int m_00, m_04, m_08, m_0c;
    unsigned long m_aulData[12];
};
struct FUN_00c86790_t
{
    void bhkUnaryAction_LoadBinary(NiStream86* pkStream);
};
class FUN_00c86e80_t
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
    virtual Block86* GetBlock(int* piSize);
    void bhkMouseSpringAction_LoadBinary(NiStream86* pkStream);
};
// @fnv 0x00c86e80
// src: XBOX_PDB 0x00c86e80
void FUN_00c86e80_t::bhkMouseSpringAction_LoadBinary(NiStream86* pkStream)
{
    ((FUN_00c86790_t*)this)->bhkUnaryAction_LoadBinary(pkStream);
    if (pkStream->m_bSameEndian == 1)
        return;
    int iSize;
    Block86* pkBlock = GetBlock(&iSize);
    Swap86(&pkBlock->m_aulData[0]);
    Swap86(&pkBlock->m_aulData[1]);
    Swap86(&pkBlock->m_aulData[2]);
    Swap86(&pkBlock->m_aulData[3]);
    Swap86(&pkBlock->m_aulData[4]);
    Swap86(&pkBlock->m_aulData[5]);
    Swap86(&pkBlock->m_aulData[6]);
    Swap86(&pkBlock->m_aulData[7]);
    Swap86(&pkBlock->m_aulData[8]);
    Swap86(&pkBlock->m_aulData[9]);
    Swap86(&pkBlock->m_aulData[10]);
    Swap86(&pkBlock->m_aulData[11]);
}

struct FUN_00c86f10_arg
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

class FUN_00c86f10_cls
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
    void bhkUnaryAction_SaveBinary(FUN_00c86f10_arg* a);
    void bhkMouseSpringAction_SaveBinary(FUN_00c86f10_arg* a1);
};

// @fnv 0x00c86f10
// src: XBOX_PDB 0x00c86f10
void FUN_00c86f10_cls::bhkMouseSpringAction_SaveBinary(FUN_00c86f10_arg* a1)
{
    unsigned int tmp;
    volatile unsigned int* p = vGet((unsigned char*)&tmp + 3);
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
        p[12] = _byteswap_ulong(p[12]);
        p[13] = _byteswap_ulong(p[13]);
        p[14] = _byteswap_ulong(p[14]);
        p[15] = _byteswap_ulong(p[15]);
    }
    bhkUnaryAction_SaveBinary(a1);
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
        p[12] = _byteswap_ulong(p[12]);
        p[13] = _byteswap_ulong(p[13]);
        p[14] = _byteswap_ulong(p[14]);
        p[15] = _byteswap_ulong(p[15]);
    }
}
