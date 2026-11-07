
// src/staging/blk_00560000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_00560000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00560000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/NiTransform.h"
#include "../../include/NiPoint3.h"
#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../include/hkVector4.h"
#include <string.h>
#pragma intrinsic(memcpy)

class LocalBlock20;
class FUN_00577110_slot;

class FUN_00577110_cls
{
  public:
    FUN_00577110_slot* GetSlot(unsigned int index, LocalBlock20* scratch);
    void ProcessState_00577110();
};

class __declspec(align(16)) LocalBlock20
{
  public:
    LocalBlock20();
    void Init();
    char buffer[0x10];
};

class FUN_00577110_slot
{
  public:
    void Run();
};

// @fnv 0x00577110
// src: GUESS 0x00577110 (confidence: low)
void FUN_00577110_cls::ProcessState_00577110()
{
    LocalBlock20 local;
    local.Init();
    GetSlot(0, &local)->Run();
    GetSlot(1, &local)->Run();
    GetSlot(2, &local)->Run();
}

struct __declspec(align(16)) FUN_0056ded0
{
    unsigned char transformData[64];
    FUN_0056ded0();
};
FUN_0056ded0& __cdecl FUN_0056df80(FUN_0056ded0& destination, const NiTransform& source);
struct FUN_0056df20_Class
{
    void bhkShapePhantom_setTransform(FUN_0056ded0*);
    void bhkShapePhantom_SetTransform(const NiTransform& src);
};
// Built from prior 2026-10-25 contributions, with byte-addressable transform storage.
// @fnv 0x0056df20
// src: XBOX_PDB 0x0056df20
void FUN_0056df20_Class::bhkShapePhantom_SetTransform(const NiTransform& src)
{
    FUN_0056ded0 local;
    bhkShapePhantom_setTransform(&FUN_0056df80(local, src));
}

extern const NiMatrix3 g_kIdentity56D;


class Color56D
{
  public:
    Color56D(float fR, unsigned int uiG, unsigned int uiB);
    float r, g, b;
};

class MotionType56D
{
  public:
    void Set(int iType);
    unsigned int m_uiType;
};

class Shape56D
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
    void* GetShape();
    void* m_pvVtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class BoxShape56D : public Shape56D
{
  public:
    BoxShape56D(const hkVector4& m_kPoint2);
};

class SphereShape56D : public Shape56D
{
  public:
    SphereShape56D(float fRadius, int iFlags);
};

class MotionInfo56D
{
  public:
    MotionInfo56D();
    hkVector4 m_kA;
    hkVector4 m_kB;
    hkVector4 m_kC;
    hkVector4 m_kCubicCoefficient;
};

class BoxBodyCinfo56D
{
  public:
    BoxBodyCinfo56D();
    ~BoxBodyCinfo56D();
    unsigned int m_uiFilterInfo;
    int unk04;
    MotionType56D m_kMotion;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_kMin;
    hkVector4 m_kMax;
};

class BodyCinfo56D
{
  public:
    BodyCinfo56D();
    ~BodyCinfo56D();
    unsigned int m_uiFilterInfo;
    void* m_pvShape;
    MotionType56D m_kMotion;
    int unk0c;
    hkVector4 m_kPathOffset;
    hkVector4 m_kRotationMatrix;
    hkVector4 m_kLinearVelocity;
    hkVector4 m_kAngularVelocity;
    hkVector4 m_kInertia;
};

class BoxBody56D
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
    BoxBody56D(BoxBodyCinfo56D& kInfo);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
};

class Body56D
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
    Body56D(BodyCinfo56D& kInfo);
    void SetTransform(const NiTransform& kXform);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
};

class Node56D;

class Collision56D
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
    Collision56D(Node56D* pkNode);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
};

class Property56D
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
    Property56D();
    void SetMode(int iMode, int iFlags);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

class Node56D
{
  public:
    void SetScale(float fScale);
    void SetColor(const Color56D& kColor);
    void AttachProperty(Property56D* pkProperty);
};

class Physics56D
{
  public:
    void Attach(Node56D* pkNode, int iFlags);
};

class Holder56D
{
  public:
    void Add(void* pvObject);
    Physics56D* Get();
};

class Loaded56D
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    Holder56D m_kHolder;
};

// GetBound (0x0041fbe0) returns primitive data; GetExtents (0x00413fc0) returns its radii, unlike Bound's sphere layout.
class PrimitiveCollisionSource
{
  public:
    int GetType();
    NiPoint3 GetExtents();
};

class Layer56D
{
  public:
    unsigned int GetLayer();
};

class ExtraList56D
{
  public:
    PrimitiveCollisionSource* GetBound();
    Layer56D* GetLayerData();
};

class World56D
{
  public:
    void AddHolder(Physics56D* pkPhysics);
};

class Middle56D
{
  public:
    World56D* GetWorld();
};

void __cdecl NI2HK(hkVector4& kOut, const NiPoint3& kIn);
float __cdecl NI2HK_004a3e90(float fValue);

class Ref56D
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual Node56D* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const NiPoint3* GetPos();
    ExtraList56D* GetExtraData();
    Middle56D* GetMiddle();
    void SetScale(float fScale);
    NiMatrix3 GetRotation();
    void TESObjectREFR_InitHavokForPrimitiveTrigger();
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
    Loaded56D* m_pkLoaded;
};

// The shared SIMD union needs the same stack protection as the original vector storage.
#pragma strict_gs_check(push, on)
// @fnv 0x0056d7e0
// src: COMMUNITY 0x0056d7e0
void Ref56D::TESObjectREFR_InitHavokForPrimitiveTrigger()
{
    PrimitiveCollisionSource* pkBound = GetExtraData()->GetBound();
    World56D* pkWorld = GetMiddle() ? GetMiddle()->GetWorld() : 0;
    if (pkWorld)
    {
        Shape56D* pkShape = 0;
        MotionInfo56D kUnused;
        hkVector4 m_kPoint2;
        SetScale(1.0f);
        Get3D()->SetScale(1.0f);
        Color56D kColor(0.0f, 0, 0);
        Get3D()->SetColor(kColor);
        NiTransform kXform;
        kXform.m_Rotate = GetRotation();
        kXform.m_Translate = *GetPos();
        kXform.m_fScale = 1.0f;
        Layer56D* pkLayer = GetExtraData()->GetLayerData();
        unsigned int uiLayer = pkLayer ? pkLayer->GetLayer() : 0x16;
        if (uiLayer != 0x17 && pkBound->GetType() == 1 && kXform.m_Rotate == g_kIdentity56D)
        {
            BoxBodyCinfo56D kInfo;
            hkVector4 kVec;
            NiPoint3 kPt;
            kPt = pkBound->GetExtents() + kXform.m_Translate;
            NI2HK(kVec, kPt);
            kInfo.m_kMax = kVec;
            kPt = pkBound->GetExtents() * -1.0f + kXform.m_Translate;
            NI2HK(kVec, kPt);
            kInfo.m_kMin = kVec;
            kInfo.m_kMotion.Set(2);
            unsigned int uiFilterInfo = 0x50000;
            uiFilterInfo |= uiLayer;
            kInfo.m_uiFilterInfo = uiFilterInfo;
            m_pkLoaded->m_kHolder.Add(new BoxBody56D(kInfo));
        }
        else
        {
            if (pkBound->GetType() == 1)
            {
                NI2HK(m_kPoint2, pkBound->GetExtents());
                pkShape = new BoxShape56D(m_kPoint2);
            }
            if (pkBound->GetType() == 2)
                pkShape = new SphereShape56D(NI2HK_004a3e90(pkBound->GetExtents().x), 0);
            BodyCinfo56D kInfo;
            kInfo.m_pvShape = pkShape->GetShape();
            kInfo.m_kMotion.Set(2);
            unsigned int uiFilterInfo = 0x50000;
            uiFilterInfo |= uiLayer;
            kInfo.m_uiFilterInfo = uiFilterInfo;
            Body56D* pkBody = new Body56D(kInfo);
            pkBody->SetTransform(kXform);
            m_pkLoaded->m_kHolder.Add(pkBody);
        }
        Collision56D* pkCollision = new Collision56D(Get3D());
        Property56D* pkProperty = new Property56D();
        pkProperty->SetMode(2, 1);
        Get3D()->AttachProperty(pkProperty);
        m_pkLoaded->m_kHolder.Get()->Attach(Get3D(), 0);
        pkWorld->AddHolder(m_pkLoaded->m_kHolder.Get());
    }
}

#pragma strict_gs_check(pop)

struct UpdateData264
{
    float time;
    bool updateControllers, isMultiThreaded, flags6, flags7, flags8;
    UpdateData264(float, bool, bool);
};
struct HavokTransform264
{
    __m128 rotation[3];
    __m128 translation;
    HavokTransform264();
    void hkTransform_setIdentity();
};
void __cdecl FUN_0056df80(HavokTransform264*, const NiTransform*);
struct NativeA264
{
    void hkNiTriStripsShape_CalcWorldAabb(const HavokTransform264&);
};
struct NativeB264
{
    void hkPackedNiTriStripsShape_CalcWorldAabb(const HavokTransform264&);
};
struct Shape264
{
};
struct ShapeA264 : Shape264
{
    NativeA264* GetReferenceFlags();
};
struct ShapeB264 : Shape264
{
    NativeB264* GetReferenceFlags();
};
struct WrappedShape264 : Shape264
{
    Shape264* bhkBvTreeShape_GetShapeCollection();
};
struct World264
{
    Shape264* bhkWorldObject_GetShape();
};
struct Collision264
{
    World264* bhkNiCollisionObject_GetWorldObject();
};
struct Scene264;
struct SceneChildren264
{
    unsigned int FUN_0043b480();
    Scene264* FUN_0043b4a0(unsigned int);
};
struct Scene264
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual SceneChildren264* AsNode();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
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
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void Update(UpdateData264&);
    const NiTransform& NiAVObject_GetWorldRotate();
};
Collision264* __cdecl FUN_0043b610(Scene264*);
bool __cdecl NiObject_IsKindOf(const void*, const void*);
extern char DAT_012682e8, DAT_012682dc, DAT_012682d0;
struct Owner264
{
    void TESObjectREFR_PreCalcTriStripsShapeAabb(Scene264*);
};
// @fnv 0x00576d50
// src: COMMUNITY 0x00576d50
void Owner264::TESObjectREFR_PreCalcTriStripsShapeAabb(Scene264* scene)
{
    if (!scene)
        return;
    UpdateData264 update(0.0f, true, false);
    scene->Update(update);
    // Preserve the original raw transform copy without invoking member copy constructors.
    unsigned char transform[sizeof(NiTransform)];
    memcpy(transform, &scene->NiAVObject_GetWorldRotate(), sizeof(transform));
    HavokTransform264 converted;
    converted.hkTransform_setIdentity();
    FUN_0056df80(&converted, reinterpret_cast<const NiTransform*>(transform));
    Collision264* collision = FUN_0043b610(scene);
    World264* world = collision ? collision->bhkNiCollisionObject_GetWorldObject() : 0;
    Shape264* shape = world ? world->bhkWorldObject_GetShape() : 0;
    if (shape)
    {
        NativeA264* nativeA = 0;
        NativeB264* nativeB = 0;
        if (NiObject_IsKindOf(&DAT_012682e8, shape))
        {
            ShapeA264* typed = (ShapeA264*)shape;
            nativeA = typed->GetReferenceFlags();
        }
        else if (NiObject_IsKindOf(&DAT_012682dc, shape))
        {
            ShapeB264* typed = (ShapeB264*)shape;
            nativeB = typed->GetReferenceFlags();
        }
        else if (NiObject_IsKindOf(&DAT_012682d0, shape))
        {
            WrappedShape264* typed = (WrappedShape264*)shape;
            Shape264* child = typed->bhkBvTreeShape_GetShapeCollection();
            if (child && NiObject_IsKindOf(&DAT_012682e8, child))
            {
                ShapeA264* typedA = (ShapeA264*)child;
                nativeA = typedA->GetReferenceFlags();
            }
            else if (child && NiObject_IsKindOf(&DAT_012682dc, child))
            {
                ShapeB264* typedB = (ShapeB264*)child;
                nativeB = typedB->GetReferenceFlags();
            }
        }
        if (nativeA)
            nativeA->hkNiTriStripsShape_CalcWorldAabb(converted);
        if (nativeB)
            nativeB->hkPackedNiTriStripsShape_CalcWorldAabb(converted);
    }
    SceneChildren264* children = scene->AsNode();
    if (children)
    {
        unsigned int count = children->FUN_0043b480();
        for (unsigned int i = 0; i < count; ++i)
            TESObjectREFR_PreCalcTriStripsShapeAabb(children->FUN_0043b4a0(i));
    }
}
