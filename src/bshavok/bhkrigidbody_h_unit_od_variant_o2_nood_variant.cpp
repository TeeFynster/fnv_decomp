
// src/bshavok/bhkrigidbody_h_unit_od_variant_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/bshavok/bhkrigidbody_h_unit_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/bshavok/bhkrigidbody_h_unit_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bshavok/bhkrigidbody_h_unit.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "bhkrigidbody.h"

struct S8d280_Quad
{
    __m128 m_vComponents;
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

struct S8d280_Mat
{
    S8d280_Quad r0;
    S8d280_Quad r1;
    S8d280_Quad r2;
    S8d280_Quad r3;
    void setIdentity()
    {
        r0.setZero4();
        r1.setZero4();
        r2.setZero4();
        r0(0) = 1.0f;
        r1(1) = 1.0f;
        r2(2) = 1.0f;
        r3.setZero4();
    }
};

class FUN_00c8d280_cls : public bhkRefObject
{
  public:
    S8d280_Mat* bhkRigidBody_GetTransform(S8d280_Mat* out);
};

// @fnv 0x00c8d280
// src: XBOX_PDB 0x00c8d280
S8d280_Mat* FUN_00c8d280_cls::bhkRigidBody_GetTransform(S8d280_Mat* out)
{
    if (this != 0)
    {
        if (m_pHavokObject != 0)
        {
            S8d280_Mat* src = (S8d280_Mat*)((char*)m_pHavokObject + 0xf0);
            out->r0.m_vComponents = src->r0.m_vComponents;
            out->r1.m_vComponents = src->r1.m_vComponents;
            out->r2.m_vComponents = src->r2.m_vComponents;
            out->r3.m_vComponents = src->r3.m_vComponents;
            return out;
        }
    }
    out->setIdentity();
    return out;
}

// Preserves full 2026-10-24 prior contributor reconstruction; prior observed  /Od compiler mismatch.

extern unsigned int DAT_0126fd98;
struct ThreadState
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
};
extern __declspec(thread) ThreadState s_tlsData;
struct MemoryContext
{
    unsigned int previous;
    MemoryContext() : previous(s_tlsData.unk2b4)
    {
        s_tlsData.unk2b4 = 0x10;
    }
    ~MemoryContext()
    {
        s_tlsData.unk2b4 = previous;
    }
};
struct InspectorList
{
    unsigned int state00;
    void** items;
    unsigned short capacity, length, occupied, growth;
    void Grow(unsigned int count);
    void SetAt(unsigned int index, void** entry);
    __forceinline void append(void*& entry)
    {
        unsigned int location = length;
        if (location >= capacity)
            Grow(location + growth);
        SetAt(location, &entry);
    }
    __forceinline void appendInline(void* const& entry)
    {
        unsigned int location = length;
        if (location >= capacity)
            Grow(location + growth);
        if (location >= length)
        {
            length = (unsigned short)(location + 1);
            if (entry)
                ++occupied;
        }
        else if (entry)
        {
            if (!items[location])
                ++occupied;
        }
        else
        {
            if (items[location])
                --occupied;
        }
        items[location] = entry;
    }
};
struct InspectionField
{
    virtual void unused00();
    virtual void unused04();
    virtual const NiRTTI* description();
};
struct InspectionNode
{
    InspectionField* item;
    InspectionNode* next;
};
struct MaterialInspector
{
    unsigned int field00, field04, field08, field0c, field10;
    InspectionNode firstField;
    void BaseInspect(InspectorList*);
    void ReadInfo(void*);
    void bhkRigidBody_GetViewerStrings(InspectorList*);
};
struct PointFormat
{
    float x, y, z;
    PointFormat()
    {}
    __forceinline PointFormat(float a, float b, float c) : x(a), y(b), z(c)
    {}
    void* format(const char*) const;
};
struct QuaternionFormat
{
    float w, x, y, z;
    void* format(const char*) const;
};
struct __declspec(align(16)) FloatVector
{
    float x, y, z, w;
    __forceinline FloatVector& operator=(const FloatVector& other)
    {
        *(__m128*)this = *(const __m128*)&other;
        return *this;
    }
};
struct __declspec(align(16)) FloatMatrix3
{
    FloatVector a, b, c;
    __forceinline FloatMatrix3& operator=(const FloatMatrix3& other)
    {
        a = other.a;
        b = other.b;
        c = other.c;
        return *this;
    }
};
struct Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void*, unsigned int);
};
struct AllocatorHolder
{
    unsigned int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
    Allocator& getAllocator()
    {
        return *allocator;
    }
};
extern AllocatorHolder* GetAllocator();
struct __declspec(align(16)) AlignedDynamicArray
{
    unsigned int unk00, unk04, unk08;
    void* data;
    unsigned int count, capacity;
    unsigned int unk18, unk1c;
    FloatVector unk20;
    FloatVector rotation;
    FloatVector position;
    FloatVector linVelocity;
    FloatVector angVelocity;
    FloatMatrix3 inertia;
    FloatVector centerOfMass;
    float mass, linDamp, angDamp, unkbc, friction, restitution;
    float maxLinVel, maxAngVel, penetration;
    signed char motionType;
    unsigned char unkd5, unkd6, unkd7;
    unsigned int unkd8, unkdc;
    AlignedDynamicArray();
    const char* quality();
    __forceinline void ClearAndRelease(Allocator& a)
    {
        count = 0;
        if ((capacity & 0x80000000u) == 0)
            a.Free(data, (capacity & 0x3fffffff) * 8);
    }
    __forceinline ~AlignedDynamicArray()
    {
        ClearAndRelease(GetAllocator()->getAllocator());
    }
};
extern void* __cdecl MakeHeading(const char*);
extern void* __cdecl MakeFloat(const char*, float);
extern void* __cdecl MakeInt(const char*, const char*);
extern void* __cdecl MakeCount(const char*, unsigned int);
extern void __cdecl ExtractPoint(PointFormat*, const FloatVector*);
extern void __cdecl AddMotion(InspectorList*, int);
extern int __cdecl FormatText(char*, unsigned int, const char*, ...);
// @fnv 0x00c8f870
// src: XBOX_PDB 0x00c8f870
void MaterialInspector::bhkRigidBody_GetViewerStrings(InspectorList* output)
{
    MemoryContext context;
    BaseInspect(output);
    {
        void* entry = MakeHeading(DAT_012681c0.m_pcName);
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                output->Grow(index + output->growth);
            output->SetAt(index, &entry);
        }
    }
    AlignedDynamicArray info;
    ReadInfo(&info);
    {
        void* entry;
        PointFormat point;
        QuaternionFormat rotation;
        ExtractPoint(&point, &info.rotation);
        rotation.x = info.position.x;
        rotation.y = info.position.y;
        rotation.z = info.position.z;
        rotation.w = info.position.w;
        entry = point.format("Position");
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                output->Grow(index + output->growth);
            output->SetAt(index, &entry);
        }
        entry = rotation.format("Rotation");
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                output->Grow(index + output->growth);
            output->SetAt(index, &entry);
        }
        ExtractPoint(&point, &info.centerOfMass);
        entry = point.format("COM");
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                output->Grow(index + output->growth);
            output->SetAt(index, &entry);
        }
        entry = MakeFloat("MASS", info.mass);
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                output->Grow(index + output->growth);
            output->SetAt(index, &entry);
        }
        entry = MakeFloat("LINDAMP", info.linDamp);
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                output->Grow(index + output->growth);
            output->SetAt(index, &entry);
        }
        entry = MakeFloat("ANGDAMP", info.angDamp);
        {
            unsigned int index = output->length;
            if (index >= output->capacity)
                output->Grow(index + output->growth);
            output->SetAt(index, &entry);
        }
        entry = MakeFloat("FRICTION", info.friction);
        output->append(entry);
        entry = MakeFloat("REST", info.restitution);
        output->append(entry);
        AddMotion(output, info.motionType);
        entry = MakeFloat("MAXLINVEL", info.maxLinVel);
        output->append(entry);
        entry = MakeFloat("MAXANGVEL", info.maxAngVel);
        output->append(entry);
        ExtractPoint(&point, &info.linVelocity);
        entry = point.format("LinVel");
        output->append(entry);
        ExtractPoint(&point, &info.angVelocity);
        entry = point.format("AngVel");
        output->append(entry);
        FloatMatrix3 inertia;
        inertia = info.inertia;
        PointFormat diagonal;
        diagonal.x = inertia.a.x;
        diagonal.y = inertia.b.y;
        diagonal.z = inertia.c.z;
        entry = diagonal.format("InertiaTensor");
        output->append(entry);
        entry = MakeFloat("PENDEPTH", info.penetration);
        output->append(entry);
        entry = MakeInt("QUALITYTYPE", info.quality());
        output->append(entry);
        unsigned int count = 0;
        InspectionNode* node = &firstField;
        while (node && node->item)
        {
            ++count;
            node = node->next;
        }
        entry = MakeCount("ACTCONCOUNT", count);
        output->append(entry);
    }
    for (InspectionNode* current = &firstField; current && current->item; current = current->next)
    {
        InspectionField* field = current->item;
        const char* name = field->description()->m_pcName;
        char message[128];
        FormatText(message, 128, "%s: 0x%8X", name, field);
        output->appendInline(MakeInt("ACTCON", message));
    }
}

struct Q8f6e0_Tls;
extern Q8f6e0_Tls* hkMemoryRouter_getInstance();
struct Q8f6e0_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int bytes);
};
struct Q8f6e0_Tls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Q8f6e0_Heap* heap;
};
struct Q8f6e0_Mem
{
    int unk00;
    int total;
    int(__cdecl* alloc)(Q8f6e0_Mem*, void*, int, int, int);
    int Read(void* p, int n, int x, int y)
    {
        int done = alloc(this, p, n, (int)x, (int)y);
        total += done;
        return done;
    }
};
struct Q8f6e0_Report
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void log(int a, int b, const char* msg, const char* file, int line);
};
struct __declspec(align(16)) Q8f6e0_Pre
{
    int unk00;
    int unk04;
    unsigned char flag08;
    void* data;
    int size;
    unsigned int capFlags;
    unsigned char flag18;
    unsigned short unk1a;
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
    __forceinline Q8f6e0_Pre()
    {
        data = 0;
        size = 0;
        capFlags = 0x80000000;
        flag08 = 1;
        unk00 = 0;
        unk04 = 0;
        flag18 = 1;
        unk1a = 0xffff;
    }
    ~Q8f6e0_Pre();
};
__forceinline Q8f6e0_Pre::~Q8f6e0_Pre()
{
    Q8f6e0_Heap& h = *hkMemoryRouter_getInstance()->heap;
    size = 0;
    if ((capFlags & 0x80000000) == 0)
        h.ReturnMemory(data, (capFlags & 0x3fffffff) * 8);
}
struct Q8f6e0_Dummy
{
    void FromOldCinfo(Q8f6e0_Pre* p);
};
struct Q8f6e0_Arg
{
    int unk00;
    unsigned int count;
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
    char name[260];
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
    Q8f6e0_Mem* mem;
};
extern int __cdecl BSsprintf(char* buf, int n, const char* fmt, ...);
extern Q8f6e0_Report* DAT_01268360;
extern const char str_010c6118[];
extern const char str_010c60dc[];
struct Q8f6e0_Obj
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
    virtual int vA8();
    virtual void vac();
    virtual void vb0();
    virtual Q8f6e0_Dummy* vB4(unsigned char* p);
    int bhkRigidBody_LoadCInfo(Q8f6e0_Arg* a);
    int bhkSerializable_LoadCInfo(Q8f6e0_Arg* a);
};
// @fnv 0x00c8f6e0
// src: XBOX_PDB 0x00c8f6e0
int Q8f6e0_Obj::bhkRigidBody_LoadCInfo(Q8f6e0_Arg* a)
{
    unsigned char flag;
    int r = this->vA8();
    Q8f6e0_Dummy* pD = this->vB4(&flag);
    bool warn = false;
    bool recovered = false;
    if (a->count < 0x23u)
    {
        Q8f6e0_Pre pre;
        Q8f6e0_Mem* m = a->mem;
        m->Read(&pre, 0xe0, 0, 0);
        pD->FromOldCinfo(&pre);
        recovered = true;
    }
    else
    {
        bhkSerializable_LoadCInfo(a);
    }
    if (warn || recovered)
    {
        char buf[0x100];
        BSsprintf(buf, 0x100, str_010c6118, a->name);
        DAT_01268360->log(!recovered, 0x234f2250, buf, str_010c60dc, 0x220);
    }
    return r;
}
