// src/havok/common/serialize/data/native/hkdataobjectnative_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/serialize/data/native/hkdataobjectnative.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../../../../include/Pair.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkClass.h"
#include "../../../../../../include/hkClassMember.h"
#include "../../../../../../include/hkError.h"
#include "../../../../../../include/hkOstream.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkDataArrayNative.h"

// The router at 0x00c85750 stores its heap at +0x10, as in the shared hkMemoryRouter layout.
template <typename AllocatorType>
inline AllocatorType& GetRouterHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<AllocatorType*>(router.m_heap);
}

// Unused declarations copied from the parent unit have been removed.

hkMemoryRouter* _D1A0E0GetMemoryRouter();
struct FUN_00dbc640_class
{
    int m_00;
    unsigned short m_04;

    void __thiscall FUN_00dbb3f0();

    FUN_00dbc640_class* __thiscall FUN_00dbc640(int flags);
};
FUN_00dbc640_class* FUN_00dbc640_class::FUN_00dbc640(int flags)
{
    this->FUN_00dbb3f0();

    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockFree(this, this->m_04);
    }

    return this;
}
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

inline Pair::Pair() throw()
{}



inline void* __cdecl hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(GetRouterHeap<hkMemoryAllocator>(hkMemoryRouter_getInstance()).blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = (unsigned short)nbytes;
    return b;
}

extern const char str_010d64dc[];
extern const char str_010d64d0[];
extern const char str_010d64bc[];
extern const char str_010d6394[];
extern char DAT_010d6334[];

struct S00dbb260_Rec
{
    int unk00;
    int unk04;
    int unk08;
    hkClass* unk0C;
};

struct S00dbb260_World
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
    virtual S00dbb260_Rec* vf24(const char* name);
};

struct S00dbb260_Result
{
    int vt;
    unsigned short size;
    unsigned short unk06;
    int unk08;
    Pair sub;
    S00dbb260_World* world;
};

// @fnv 0x00dbb260
// src: XBOX_PDB 0x00dbb260
static __declspec(noinline) S00dbb260_Result* hkNativeDataObjectImplCreate(Pair* args, S00dbb260_World* world)
{
    if (!!args->b)
    {
        S00dbb260_Rec* a;
        a = world->vf24(reinterpret_cast<hkClass*>(args->b)->getName());
        if ((bool)a)
        {
            args->b = reinterpret_cast<int>(a->unk0C);
        }
        else
        {
            {
                char j[0x200];
                hkOstream writer(j, 0x200);
                writer << str_010d64bc << reinterpret_cast<void*>(args->a) << str_010d64d0
                       << reinterpret_cast<hkClass*>(args->b)->getName() << str_010d64dc;
                hkError::s_instance->message(1, 0x1800473A, j, str_010d6394, 0x2C7);
            }
            args->a = 0;
            args->b = 0;
        }
    }
    S00dbb260_Result* rec;
    rec = (S00dbb260_Result*)GetRouterHeap<hkMemoryAllocator>(hkMemoryRouter_getInstance()).blockAlloc(0x18);
    rec->size = 0x18;
    rec->unk06 = 0;
    rec->unk08 = 0;
    rec->vt = (int)DAT_010d6334;
    rec->sub.Imath_Vec2_int_Vec2_int(*args);
    rec->world = world;
    return rec;
}

S00dbb260_Result* S00dbb260_Entry(Pair* a, S00dbb260_World* w)
{
    return hkNativeDataObjectImplCreate(a, w);
}

struct ClassLookupDBC
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual hkClass* lookup(void* object);
};
struct WorldDBC
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual hkClass* find(const char* name);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual WorldDBC* findObjectType(const char* name);
    int unk04;
    int unk08;
    hkClass* type;
};
extern const char DAT_010d6394[];
extern const char DAT_010d63bc[];
extern const char DAT_010d63f8[];
extern const char DAT_010d6400[];
extern const char DAT_010d64bc[];
extern const char DAT_010d64d0[];
extern const char DAT_010d64dc[];

struct ResultDBC
{
    void* object;
    hkClass* type;
};
// src: XBOX_PDB 0x00dbb140
static __declspec(noinline) ResultDBC getVariantWithMostDerivedClass(hkClass* type, void* object, ClassLookupDBC* lookup, WorldDBC* world)
{
    ResultDBC result = {0, 0};
    if (type && object)
    {
        if (type->GetLastNodeFlag().m_cBooleanValue)
        {
            hkClass* actual = lookup->lookup(object);
            hkClass* found = actual ? world->find(actual->getName()) : 0;
            result.type = found;
            result.object = found ? object : 0;
            if (!found)
            {
                char buffer[512];
                hkOstream stream(buffer, 512);
                stream << DAT_010d63bc << type->getName() << DAT_010d63f8 << object << DAT_010d6400;
                hkError::s_instance->message(1, 0x3476d70f, buffer, DAT_010d6394, 0x37);
            }
        }
        else
        {
            result.object = object;
            result.type = type;
        }
    }
    return result;
}
class NativeDBC : public hkReferencedObject
{
  public:
    int zero;
    Pair value;
    WorldDBC* world;
    NativeDBC(const Pair& p, WorldDBC* w) : zero(0), world(w)
    {
        value.Imath_Vec2_int_Vec2_int(p);
    }
};
// src: XBOX_PDB 0x00dbb260
static __declspec(noinline) NativeDBC* hkNativeDataObjectImplCreate(WorldDBC* world, Pair* value)
{
    if (value->b)
    {
        WorldDBC* found = world->findObjectType(reinterpret_cast<hkClass*>(value->b)->getName());
        if (found)
            value->b = reinterpret_cast<int>(found->type);
        else
        {
            {
                char buffer[512];
                hkOstream stream(buffer, 512);
                stream << DAT_010d64bc << reinterpret_cast<void*>(value->a) << DAT_010d64d0
                       << reinterpret_cast<hkClass*>(value->b)->getName() << DAT_010d64dc;
                hkError::s_instance->message(1, 0x1800473a, buffer, DAT_010d6394, 0x2c7);
            }
            value->a = 0;
            value->b = 0;
        }
    }
    return new NativeDBC(*value, world);
}
struct DescriptorDBC
{
    int unk00;
    int unk04;
    WorldDBC* world;
    ClassLookupDBC* lookup;
};
// @fnv 0x00dbc000
// src: XBOX_PDB 0x00dbc000
NativeDBC* hkDataArrayNative::asObject(int index)
{
    Pair value;
    value.a = 0;
    value.b = 0;
    unsigned high = 0;
    switch (m_18)
    {
    case 20: {
        ResultDBC v = getVariantWithMostDerivedClass((hkClass*)m_1c, *(void**)(((char*)m_0C) + m_14 * index), ((DescriptorDBC*)m_08)->lookup, ((DescriptorDBC*)m_08)->world);
        value.a = reinterpret_cast<int>(v.object);
        high = (unsigned)v.type;
        break;
    }
    case 25: {
        ResultDBC v = getVariantWithMostDerivedClass((hkClass*)m_1c, ((char*)m_0C) + m_14 * index, ((DescriptorDBC*)m_08)->lookup, ((DescriptorDBC*)m_08)->world);
        value.a = reinterpret_cast<int>(v.object);
        high = (unsigned)v.type;
        break;
    }
    case 28:
        value = *(Pair*)(m_14 * index + ((char*)m_0C));
        high = (unsigned)value.b;
        break;
    default:
        return 0;
    }
    value.b = (int)high;
    if (value.a && value.b)
        return hkNativeDataObjectImplCreate((WorldDBC*)((DescriptorDBC*)m_08), &value);
    return 0;
}
