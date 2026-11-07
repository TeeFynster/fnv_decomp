// src/staging/blk_00e00000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00e00000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e00000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/FinishingFlag.h"
#include "../../include/Transform.h"

struct __declspec(align(16)) FinishedObject
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    void* secondaryVtable;
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
    FinishedObject(FinishingFlag);
};
// @fnv 0x00e005f0
// src: GUESS 0x00e005f0 (confidence: low)
void* __cdecl Runtime_EvaluateValue_00e005f0()
{
    FinishingFlag finish(0);
    FinishedObject object(finish);
    return object.vtable;
}

// Havok type-registration helper: construct the class in finish-loading mode (flag 0) on the stack,
// then return its static registration data.
extern char DAT_010e8ab0[];
struct __declspec(align(16)) S_00e00cd0_Obj
{
    void* m_vtbl;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void* m_vtbl10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    S_00e00cd0_Obj(FinishingFlag flag);
};

// @fnv 0x00e00cd0
// src: HAVOK_LIB 0x00e00cd0
const char* __cdecl getVtablehkpFastMeshShape()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S_00e00cd0_Obj obj(flag);
    return DAT_010e8ab0;
}

// Havok vtable getter: finish-construct a throwaway instance in an aligned scratch buffer (the
// FinishingFlag constructor only re-installs the vtable and runs the members'
// finish constructors) and return its vtable pointer.

struct hkFinishMemberE01710
{
    void* m_ptr;
    hkFinishMemberE01710(FinishingFlag flag);
};

inline void* operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}

struct __declspec(align(16)) hkObjectE01710
{
    virtual ~hkObjectE01710();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkFinishMemberE01710 m_member18;
    hkFinishMemberE01710 m_member1c;

    hkObjectE01710(FinishingFlag flag) : m_member18(flag), m_member1c(flag)
    {}
};

// @fnv 0x00e01710
// src: GUESS 0x00e01710 (confidence: low)
void* hkObjectE01710_AllocateStorage_00e01710()
{
    union
    {
        hkObjectE01710* pAligned;
        __declspec(align(16)) unsigned int auiStorage[sizeof(hkObjectE01710) / sizeof(unsigned int)];
    } u;
    FinishingFlag flag;
    new (u.auiStorage) hkObjectE01710(flag);
    return *(void**)u.auiStorage;
}

namespace fnv_00e01eb0 {

struct FinishMember
{
    void* m_ptr;
    FinishMember(FinishingFlag flag);
};

struct __declspec(align(16)) FinishObject
{
    virtual void vfn00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int unk10;
    FinishMember m_member14;
    FinishMember m_member18;
    int unk1C;

    FinishObject(FinishingFlag flag) : m_member14(flag), m_member18(flag)
    {}
};

// @fnv 0x00e01eb0
// src: GUESS 0x00e01eb0 (confidence: low)
void* __cdecl Runtime_UpdateState_00e01eb0()
{
    FinishingFlag f;
    f.m_bFinishing = 0;
    FinishObject o(f);
    return *(void**)&o;
}
}  // namespace fnv_00e01eb0

// RTTI identifies hkpNullCollisionFilter. The finish constructor installs its
// primary and four interface type headers; its filter kind is at offset0x20.
struct __declspec(align(16)) FUN_00e00a80
{
    virtual ~FUN_00e00a80();
    unsigned short memorySizeAndFlags;
    short referenceCount;
    void* collidableFilterInterface;
    void* shapeCollectionFilterInterface;
    void* rayShapeCollectionFilterInterface;
    void* rayCollidableFilterInterface;
    unsigned unk18, unk1c;
    unsigned filterType;
    FUN_00e00a80(FinishingFlag);
};
// Complete, naturally padded object representation backs the placement lifetime.
struct __declspec(align(16)) FilterStorage402
{
    void* primaryTypeHeader;
    unsigned short memorySizeAndFlags;
    short referenceCount;
    void* collidableFilterInterface;
    void* shapeCollectionFilterInterface;
    void* rayShapeCollectionFilterInterface;
    void* rayCollidableFilterInterface;
    unsigned unk18, unk1c;
    unsigned filterType;
};
// @fnv 0x00e00a60
// src: GUESS 0x00e00a60 (confidence: low)
unsigned Object_ProcessAndReturnValue_00e00a60()
{
    FilterStorage402 storage;
    new (&storage) FUN_00e00a80(FinishingFlag(0));
    return *reinterpret_cast<unsigned*>(&storage);
}

class __declspec(align(16)) S00e000e0_Object
{
  public:
    S00e000e0_Object(FinishingFlag flag);  // FUN_00d50c00
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00e000e0
// src: GUESS 0x00e000e0 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00e000e0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e000e0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

struct FUN_00e00290_sub
{
    void ReturnSelf(FinishingFlag kHandle);
    int m_00;
};
extern int DAT_010cc040;
extern int DAT_010d79e8;
struct SmallArray_e00290
{
    void* m_pData;
    unsigned short m_usSize;
    unsigned short m_usCapacityAndFlags;
};
struct __declspec(align(16)) FUN_00e00290_obj
{
    int* m_pVtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    SmallArray_e00290 m_kArray;
    FUN_00e00290_sub m_kSub;
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
// @fnv 0x00e00290
// src: HAVOK_LIB 0x00e00290
int* __cdecl getVtablehkpConstraintChainInstance()
{
    FinishingFlag kHandle(0);
    FUN_00e00290_obj kObj;
    kObj.m_pVtbl = &DAT_010cc040;
    kObj.m_kArray.m_pData = 0;
    kObj.m_kArray.m_usSize = 0;
    kObj.m_kArray.m_usCapacityAndFlags = 0x8000;
    kObj.m_kSub.ReturnSelf(kHandle);
    return &DAT_010d79e8;
}

class __declspec(align(16)) S00e003b0_Object
{
  public:
    S00e003b0_Object(FinishingFlag flag);  // FUN_00e003d0
    void* m_ppVirtualMethodTable;
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
};

// @fnv 0x00e003b0
// src: GUESS 0x00e003b0 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00e003b0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e003b0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00e004d0_Object
{
  public:
    S00e004d0_Object(FinishingFlag flag);  // FUN_00e004f0
    void* m_ppVirtualMethodTable;
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
};

// @fnv 0x00e004d0
// src: GUESS 0x00e004d0 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00e004d0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e004d0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00e006b0_Object
{
  public:
    S00e006b0_Object(FinishingFlag flag);  // FUN_00e006d0
    void* m_ppVirtualMethodTable;
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

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00e006b0
// src: GUESS 0x00e006b0 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00e006b0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e006b0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00e00b80_Object
{
  public:
    S00e00b80_Object(FinishingFlag flag);  // FUN_00e00ba0
    void* m_ppVirtualMethodTable;
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
};

// @fnv 0x00e00b80
// src: HAVOK_LIB 0x00e00b80
const void* __cdecl getVtablehkpGroupFilter()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e00b80_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00e00f90_Object
{
  public:
    S00e00f90_Object(FinishingFlag flag);  // FUN_00e00fb0
    void* m_ppVirtualMethodTable;
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

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00e00f90
// src: GUESS 0x00e00f90 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00e00f90()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e00f90_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00e01230_Object
{
  public:
    S00e01230_Object(FinishingFlag flag);  // FUN_00e01250
    virtual void vf00();
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
};

// @fnv 0x00e01230
// src: GUESS 0x00e01230 (confidence: low)
const void* __cdecl Runtime_UpdateState_00e01230()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e01230_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}

struct LoadedPointer
{
    int m_uiFilterValue;
    LoadedPointer(FinishingFlag flag);
};
struct __declspec(align(16)) LoadedObject
{
    virtual void vf00();
    int unk04;
    LoadedPointer m_pHeadNode;
    LoadedPointer m_iSecondInteger;
    LoadedPointer m_third;
    LoadedObject(FinishingFlag flag) : m_pHeadNode(flag), m_iSecondInteger(flag), m_third(flag)
    {}
};
// @fnv 0x00e01830
// src: GUESS 0x00e01830 (confidence: low)
const void* Runtime_UpdateState_00e01830()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    LoadedObject object(flag);
    return *reinterpret_cast<const void**>(&object);
}

class __declspec(align(16)) S00e01e50_Object
{
  public:
    S00e01e50_Object(FinishingFlag flag);  // FUN_00e4ad00
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00e01e50
// src: GUESS 0x00e01e50 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00e01e50()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e01e50_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00e020f0_Object
{
  public:
    S00e020f0_Object(FinishingFlag flag);  // FUN_00e4ae80
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00e020f0
// src: GUESS 0x00e020f0 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00e020f0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e020f0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

struct FUN_00e02180_sub
{
    void ReturnSelf(FinishingFlag kHandle);
    int m_00;
};
extern int DAT_010e9ccc;
struct __declspec(align(16)) FUN_00e02180_obj
{
    int* m_pVtbl;
    int unk04;
    FUN_00e02180_sub m_kSub08;
    int unk0C;
    FUN_00e02180_sub m_kSub10;
    FUN_00e02180_sub m_kSub14;
    FUN_00e02180_sub m_kSub18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};
// @fnv 0x00e02180
// src: GUESS 0x00e02180 (confidence: low)
int* __cdecl Object_ProcessAndReturnValue_00e02180()
{
    FinishingFlag kHandle(0);
    FUN_00e02180_obj kObj;
    kObj.m_pVtbl = &DAT_010e9ccc;
    kObj.m_kSub08.ReturnSelf(kHandle);
    kObj.m_kSub10.ReturnSelf(kHandle);
    kObj.m_kSub14.ReturnSelf(kHandle);
    kObj.m_kSub18.ReturnSelf(kHandle);
    return kObj.m_pVtbl;
}

class __declspec(align(16)) S00e02730_Object
{
  public:
    S00e02730_Object(FinishingFlag flag);  // FUN_00e4af80
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00e02730
// src: GUESS 0x00e02730 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00e02730()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e02730_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

#include <xmmintrin.h>
struct S_00e11530_Node
{
    S_00e11530_Node* next;
    int unk04;
    int unk08;
    int unk0c;
    __m128 bounds;
};

struct S_00e11530_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_00e11530_Node* unk14;

    __m128* ProcessEntries_00e11530(__m128* out);
};

// @fnv 0x00e11530
// src: GUESS 0x00e11530 (confidence: low)
__m128* S_00e11530_Owner::ProcessEntries_00e11530(__m128* out)
{
    S_00e11530_Node* node = unk14;
    __m128 value = unk14->bounds;
    out[0] = value;
    out[1] = value;
    if (node)
    {
        __m128 fTargetUpperBound = value;
        __m128 fMinimumInputValue = value;
        do
        {
            value = node->bounds;
            node = node->next;
            fTargetUpperBound = _mm_min_ps(fTargetUpperBound, value);
            fMinimumInputValue = _mm_max_ps(fMinimumInputValue, value);
        } while (node);
        out[0] = fTargetUpperBound;
        out[1] = fMinimumInputValue;
    }
    return out;
}

struct VecQ
{
    float x, y, z, w;
};

extern VecQ DAT_012683a0;

struct __declspec(align(16)) RotationQ
{
    float m_col[12];
};

struct ShapeQ
{
    void ProcessEntries_00e11a90(const Transform* t);
    void UpdateFields_00e11b40(const RotationQ* r);
};

// @fnv 0x00e11b40
// src: GUESS 0x00e11b40 (confidence: low)
void ShapeQ::UpdateFields_00e11b40(const RotationQ* r)
{
    __declspec(align(16)) Transform t;
    *reinterpret_cast<VecQ*>(&t.m_f30) = DAT_012683a0;
    t.r[0] = *(const __m128*)&r->m_col[0];
    t.r[1] = *(const __m128*)&r->m_col[4];
    t.r[2] = *(const __m128*)&r->m_col[8];
    ProcessEntries_00e11a90(&t);
}

extern unsigned __int64 g_unk01268370[6];
struct __declspec(align(16)) Rot
{
    unsigned __int64 d[6];
};
struct Owner
{
    void ProcessEntries_00e11a90(const Transform* xf);
    void UpdateFields_00e11ca0(const __m128* src);
};
// @fnv 0x00e11ca0
// src: GUESS 0x00e11ca0 (confidence: low)
void Owner::UpdateFields_00e11ca0(const __m128* src)
{
    Rot rot;
    rot.d[0] = g_unk01268370[0];
    rot.d[1] = g_unk01268370[1];
    rot.d[2] = g_unk01268370[2];
    rot.d[3] = g_unk01268370[3];
    rot.d[4] = g_unk01268370[4];
    rot.d[5] = g_unk01268370[5];
    __declspec(align(16)) Transform xf;
    xf.r[0] = *(__m128*)&rot.d[0];
    xf.r[1] = *(__m128*)&rot.d[2];
    xf.r[2] = *(__m128*)&rot.d[4];
    xf.r[3] = *src;
    ProcessEntries_00e11a90(&xf);
}

struct S00e00d70_Arg
{
    int value;
    S00e00d70_Arg(int v) : value(v)
    {}
};

struct __declspec(align(16)) S00e00d70_Object
{
    void* first;
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
    void hkpCylinderShape_hkpCylinderShape_00d57b20(S00e00d70_Arg arg);
};

// @fnv 0x00e00d70
// src: GUESS 0x00e00d70 (confidence: low)
int __cdecl hkpCylinderShape_hkpCylinderShape_00d57b20_EvaluateValue_00e00d70()
{
    S00e00d70_Object object;
    object.hkpCylinderShape_hkpCylinderShape_00d57b20(S00e00d70_Arg(0));
    return (int)object.first;
}

namespace N {
// Exe 0x00e195c0 FUN_00e195c0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    N::LocalM128 _mm_load_ps(const float*);
    N::LocalM128 _mm_load_ss(const float*);
    N::LocalM128 _mm_set_ss(float);
    N::LocalM128 _mm_set1_ps(float);
    N::LocalM128 _mm_shuffle_ps(N::LocalM128, N::LocalM128, int);
    N::LocalM128 _mm_mul_ps(N::LocalM128, N::LocalM128);
    N::LocalM128 _mm_add_ps(N::LocalM128, N::LocalM128);
    N::LocalM128 _mm_add_ss(N::LocalM128, N::LocalM128);
    void _mm_store_ps(float*, N::LocalM128);
    float _mm_cvtss_f32(N::LocalM128);
}
}

// Exe 0x00e195c0: unit-local Vector4f view; declarations and layout are preserved.
struct __declspec(align(16)) BlkVector4fView
{
    float v[4];
    void addScaled(const N::LocalM128& scale, const BlkVector4fView& n)
    {
        N::_mm_store_ps(v, N::_mm_add_ps(N::_mm_mul_ps(N::_mm_shuffle_ps(scale, scale, 0), N::_mm_load_ps(n.v)),
                                         N::_mm_load_ps(v)));
    }
};
inline float maxScore(float a, float b)
{
    return a > b ? a : b;
}
inline N::LocalM128 scaleNormal(const BlkVector4fView& n, const N::LocalM128& s)
{
    return N::_mm_mul_ps(N::_mm_shuffle_ps(s, s, 0), N::_mm_load_ps(n.v));
}
struct Vertex
{
    Vertex* next;
    Vertex* prev;
    int unk08;
    int unk0c;
    BlkVector4fView position;
    BlkVector4fView normal;
    BlkVector4fView extra;
    int handle40;
    int handle44;
    Vertex() : handle40(-1), handle44(-1)
    {}
    void copy(const Vertex& a)
    {
        position = a.position;
        normal = a.normal;
        extra = a.extra;
        handle40 = a.handle40;
        handle44 = a.handle44;
    }
};
inline bool vertexLess(const Vertex* a, const Vertex* b)
{
    for (int i = 0; i < 3; ++i)
    {
        if (b->position.v[i] < a->position.v[i])
            return false;
        if (b->position.v[i] > a->position.v[i])
            return true;
    }
    return false;
}
struct VertexTriple
{
    Vertex* values[3];
    Vertex*& operator[](int n)
    {
        return values[n];
    }
    Vertex* const& operator[](int n) const
    {
        return values[n];
    }
};
struct EdgeTriple
{
    unsigned int values[3];
    unsigned int& operator[](int n)
    {
        return values[n];
    }
    const unsigned int& operator[](int n) const
    {
        return values[n];
    }
};
union __declspec(align(16)) EdgeQuad
{
    float v[4];
    unsigned int bits[4];
};
struct EdgeNode
{
    EdgeNode* next;
    EdgeNode* volatile prev;
    VertexTriple vertices;
    EdgeTriple edges;
    EdgeQuad normal;
    EdgeQuad extra;
    int unk40;
    EdgeNode()
    {}
    void copy(const EdgeNode& a)
    {
        vertices = a.vertices;
        edges = a.edges;
        normal = a.normal;
        extra.bits[0] = a.extra.bits[0];
        extra.bits[1] = a.extra.bits[1];
        extra.bits[2] = a.extra.bits[2];
        extra.bits[3] = a.extra.bits[3];
        unk40 = a.unk40;
    }
};
struct EdgeMesh
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
    EdgeNode* head;
    int count;
};
struct EdgeRef
{
    EdgeNode* node;
    int index;
    EdgeRef(EdgeNode* n, int i) : node(n), index(i)
    {}
    Vertex* first() const
    {
        return node->vertices[index];
    }
    Vertex* second() const
    {
        return node->vertices[(9 >> (index << 1)) & 3];
    }
};
struct EdgeAllocator;
template <class T> struct EdgeArray
{
    T* data;
    int size;
    int capacity;
    EdgeArray() : data(0), size(0), capacity(0x80000000)
    {}
    int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    void grow(int elementSize);
};
struct EdgeAllocator
{
    virtual void f0();
    virtual void f4();
    virtual void f8();
    virtual void fc();
    virtual void release(void*, int);
    template <class T> void reserve(EdgeArray<T>& array, int needed, int elementSize);
    template <class T> void clear(EdgeArray<T>& array, int elementSize);
};
struct EdgeMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    EdgeAllocator* allocator;
};
EdgeMemory* hkMemoryRouter_getInstance();
void hkArrayUtil__reserve(void*, void*, int, int);
void FUN_00c90940(void*, void*, int);
float Hkgpmesh_ComputeValues_00e13870(EdgeNode*, int);
float ClampedAcos(float);
template <class T> inline void EdgeAllocator::reserve(EdgeArray<T>& array, int needed, int elementSize)
{
    int available = array.capacity & 0x3fffffff;
    if (available < needed)
    {
        int next = available * 2;
        if (needed >= next)
            next = needed;
        hkArrayUtil__reserve(this, &array, next, elementSize);
    }
}
template <class T> inline void EdgeArray<T>::grow(int elementSize)
{
    EdgeMemory* memory = hkMemoryRouter_getInstance();
    if (size == (capacity & 0x3fffffff))
        FUN_00c90940(memory->allocator, this, elementSize);
}
template <class T> inline void EdgeAllocator::clear(EdgeArray<T>& array, int elementSize)
{
    array.size = 0;
    if ((array.capacity & 0x80000000) == 0)
        release(array.data, (array.capacity & 0x3fffffff) * elementSize);
    array.data = 0;
    array.capacity = 0x80000000;
}
struct PoolPage
{
    unsigned int storage[640];
    void* freeHead;
    int used;
};
struct EdgePool
{
    PoolPage** pages;
    int pageCount;
    int unk08;
    void* head;
    int size;
    int unk14;
    PoolPage* AllocateChainedSlotBlock();
    template <class T> T* allocate(const T& value)
    {
        PoolPage* page;
        if (!pageCount || !(page = pages[0])->freeHead)
            page = AllocateChainedSlotBlock();
        T* item = (T*)page->freeHead;
        page->freeHead = item->next;
        ++page->used;
        item->copy(value);
        item->prev = 0;
        item->next = (T*)head;
        if (head)
            ((T*)head)->prev = item;
        ++size;
        head = item;
        return item;
    }
};
struct PointerSlotArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* slots[1];
};
extern PointerSlotArray* DAT_0126ebe8;
extern int DAT_0126ebec;
extern int DAT_0126ebf0;
inline void registerEdge(EdgeNode* node, int tag)
{
    if (!(DAT_0126ebf0 & 1))
    {
        DAT_0126ebf0 |= 1;
        DAT_0126ebe8 = 0;
        DAT_0126ebec = 0;
    }
    node->edges[tag] = (unsigned int)DAT_0126ebe8 + DAT_0126ebec;
    if (DAT_0126ebe8)
        DAT_0126ebe8->slots[DAT_0126ebec] = (void*)((unsigned int)node + tag);
}
struct EdgeProcessor
{
    int unk00;
    int unk04;
    EdgePool vertices;
    EdgePool edges;
    void UpdateTriangleNormal(EdgeNode*);
    void ProcessEntries_00e195c0(float threshold, float distance, const EdgeMesh* mesh);
};
// @fnv 0x00e195c0
// src: GUESS 0x00e195c0 (confidence: low)
void EdgeProcessor::ProcessEntries_00e195c0(float threshold, float distance, const EdgeMesh* mesh)
{
    EdgeArray<EdgeRef> refs;
    EdgeArray<float> scores;
    {
        int required = mesh->count * 3;
        EdgeMemory* memory = hkMemoryRouter_getInstance();
        memory->allocator->reserve(refs, required, 8);
    }
    {
        int required = mesh->count * 3;
        EdgeMemory* memory = hkMemoryRouter_getInstance();
        memory->allocator->reserve(scores, required, 4);
    }
    for (EdgeNode* node = mesh->head; node; node = node->next)
    {
        int edge = 0;
        do
        {
            EdgeRef current(node, edge);
            Vertex* second = current.second();
            Vertex* first = current.first();
            if (!(vertexLess(second, first) && (node->edges[edge] & ~3u)))
                if ((node->edges[edge] & ~3u) && Hkgpmesh_ComputeValues_00e13870(node, edge) > 0.0f)
                {
                    refs.grow(8);
                    EdgeRef* ref = (EdgeRef*)refs.data + refs.size;
                    if (ref)
                    {
                        ref->node = node;
                        ref->index = edge;
                    }
                    ++refs.size;
                    scores.grow(4);
                    ((float*)scores.data)[scores.size++] = 0.0f;
                }
        } while (++edge < 3);
    }
    for (int index = 0; index < refs.size; ++index)
    {
        EdgeRef ref = ((EdgeRef*)refs.data)[index];
        EdgeNode* adjacent = (EdgeNode*)(ref.node->edges[ref.index] & ~3u);
        N::LocalM128 product = N::_mm_mul_ps(N::_mm_load_ps(ref.node->normal.v), N::_mm_load_ps(adjacent->normal.v));
        N::LocalM128 y = N::_mm_shuffle_ps(product, product, 0x55);
        N::LocalM128 z = N::_mm_shuffle_ps(product, product, 0xaa);
        y = N::_mm_add_ss(y, product);
        z = N::_mm_add_ss(z, y);
        ((float*)scores.data)[index] = ClampedAcos(N::_mm_cvtss_f32(z));
    }
    float maximum = 0.0f;
    for (int index = 0; index < refs.size; ++index)
    {
        float score = ((float*)scores.data)[index];
        maximum = maxScore(score, maximum);
    }
    for (int index = 0; index < refs.size; ++index)
        ((float*)scores.data)[index] /= maximum;
    for (int index = 0; index < refs.size; ++index)
    {
        if (((float*)scores.data)[index] > threshold)
        {
            EdgeRef ref = ((EdgeRef*)refs.data)[index];
            Vertex* first = ref.node->vertices[ref.index];
            __declspec(align(16)) BlkVector4fView a = first->position;

            N::LocalM128 p = scaleNormal(first->normal, N::_mm_set_ss(distance));
            Vertex* second = ref.node->vertices[(9 >> (2 * ref.index)) & 3];
            __declspec(align(16)) BlkVector4fView b = second->position;
            N::LocalM128 q = scaleNormal(second->normal, N::_mm_set_ss(distance));
            N::_mm_store_ps(a.v, N::_mm_add_ps(p, N::_mm_load_ps(a.v)));
            N::_mm_store_ps(b.v, N::_mm_add_ps(q, N::_mm_load_ps(b.v)));
            Vertex* va = vertices.allocate(Vertex());
            Vertex* vb = vertices.allocate(Vertex());
            N::_mm_store_ps(va->position.v, N::_mm_load_ps(a.v));
            N::_mm_store_ps(vb->position.v, N::_mm_load_ps(b.v));
            EdgeNode* edge = edges.allocate(EdgeNode());
            edge->vertices[0] = va;
            edge->vertices[1] = vb;
            edge->vertices[2] = va;
            UpdateTriangleNormal(edge);
            registerEdge(edge, 0);
            registerEdge(edge, 1);
            registerEdge(edge, 2);
        }
    }
    {
        EdgeMemory* memory = hkMemoryRouter_getInstance();
        memory->allocator->clear(scores, 4);
    }
    {
        EdgeMemory* memory = hkMemoryRouter_getInstance();
        memory->allocator->clear(refs, 8);
    }
}

struct LoadedName_E001F0
{
    LoadedName_E001F0(FinishingFlag flag);
    int m_iWordAt00;
};

class ChainActionBase_E001F0
{
  public:
    ChainActionBase_E001F0(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    LoadedName_E001F0 m_kMember;
};

class __declspec(align(16)) ChainAction_E001F0 : public ChainActionBase_E001F0
{
  public:
    ChainAction_E001F0(FinishingFlag flag) : ChainActionBase_E001F0(flag)
    {}
    virtual void vf00();
    void* constraintInstance;
};

// @fnv 0x00e001f0
// src: HAVOK_LIB 0x00e001f0
const void* __cdecl getVtablehkpConstraintChainInstanceAction()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    ChainAction_E001F0 kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}

struct S00e01490_Member
{
    S00e01490_Member(FinishingFlag flag);
    int m_iWordAt00;
};

class __declspec(align(16)) S00e01490_Object
{
  public:
    S00e01490_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
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
    S00e01490_Member m_kMember;
};

// @fnv 0x00e01490
// src: GUESS 0x00e01490 (confidence: low)
const void* __cdecl Runtime_UpdateState_00e01490()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e01490_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}

struct SceneFinishString
{
    void* m_ptr;
    SceneFinishString(FinishingFlag flag);
};

struct __declspec(align(16)) SceneFinishObject
{
    virtual void vfn00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    SceneFinishString m_member08;
    SceneFinishString m_member0C;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;

    SceneFinishObject(FinishingFlag flag) : m_member08(flag), m_member0C(flag)
    {}
};

// @fnv 0x00e01c60
// src: GUESS 0x00e01c60 (confidence: medium)
void* __cdecl Object_GetConstructedVirtualTable_00e01c60()
{
    FinishingFlag f;
    f.m_bFinishing = 0;
    SceneFinishObject o(f);
    return *(void**)&o;
}

struct S00e01d10_Member
{
    S00e01d10_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class __declspec(align(16)) S00e01d10_Object
{
  public:
    S00e01d10_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S00e01d10_Member m_kMember;
    int unk24;
    int unk28;
    int unk2C;
};

// @fnv 0x00e01d10
// src: GUESS 0x00e01d10 (confidence: low)
const void* __cdecl Runtime_UpdateState_00e01d10()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e01d10_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}

struct S00e022a0_Member
{
    S00e022a0_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class __declspec(align(16)) S00e022a0_Object
{
  public:
    S00e022a0_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    S00e022a0_Member m_kMember;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

// @fnv 0x00e022a0
// src: GUESS 0x00e022a0 (confidence: low)
const void* __cdecl Object_ProcessAndReturnValue_00e022a0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00e022a0_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}
