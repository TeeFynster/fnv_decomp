
// src/havok/common/serialize/resource/hkobjectresource.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/resource/hkobjectresource.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryAllocator.h"


struct FUN_00e04eb0_class
{
    char _pad[0x10];
    hkReferencedObject* m_p;
    void hkObjectResource_setClassNameRegistry(hkReferencedObject* p);
};

// @fnv 0x00e04eb0
// src: XBOX_PDB 0x00e04eb0
void FUN_00e04eb0_class::hkObjectResource_setClassNameRegistry(hkReferencedObject* apObject)
{
    if (apObject)
        apObject->addReference();
    if (m_p)
        m_p->removeReference();
    m_p = apObject;
}

namespace fnv_00e04ee0 {
struct FUN_00e04ee0_class
{
    void __thiscall hkObjectResource_setTypeInfoRegistry(hkReferencedObject* p);
    char _pad[0x14];
    hkReferencedObject* m_p;
};

// @fnv 0x00e04ee0
// src: XBOX_PDB 0x00e04ee0
void __thiscall FUN_00e04ee0_class::hkObjectResource_setTypeInfoRegistry(hkReferencedObject* apObject)
{
    if (apObject)
        apObject->addReference();
    if (m_p)
        m_p->removeReference();
    m_p = apObject;
}
}  // namespace fnv_00e04ee0

struct D481D0Class
{
    const char* getName() const;
};

struct FUN_00e04ea0_class
{
    char _pad[0xc];
    D481D0Class* p;
    const char* hkObjectResource_getContentsTypeName();
};

// @fnv 0x00e04ea0
// src: HAVOK_SRC 0x00e04ea0
const char* FUN_00e04ea0_class::hkObjectResource_getContentsTypeName()
{
    return p->getName();
}

struct FUN_00e05090_class
{
    virtual FUN_00e05090_class* FUN_00e05090(int flags);
    unsigned short m_resourceId;
    void ReleaseResource();
};

FUN_00e05090_class* FUN_00e05090_class::FUN_00e05090(int flags)
{
    ReleaseResource();

    if (flags & 1)
    {
        hkMemoryRouter& router = hkMemoryRouter::getInstance();
        reinterpret_cast<hkMemoryAllocator*>(router.m_heap)->blockFree(this, m_resourceId);
    }

    return this;
}

int __cdecl hkString_strCmp(int, int);

class FUN_00d46d40_s
{
  public:
    const char* FUN_00d46d40();
    FUN_00d46d40_s* FUN_00d46d50();

    hkBool hkClass_isSuperClass(FUN_00d46d40_s* pkNode);
};

// @fnv 0x00d46d80
// src: HAVOK_LIB 0x00d46d80
hkBool FUN_00d46d40_s::hkClass_isSuperClass(FUN_00d46d40_s* pkNode)
{
    while (pkNode)
    {
        if (hkString_strCmp((int)pkNode->FUN_00d46d40(), (int)FUN_00d46d40()) == 0)
            return true;
        pkNode = pkNode->FUN_00d46d50();
    }
    return false;
}

// @fnv 0x00e04e50
// src: GUESS 0x00e04e50 (confidence: high)
int __cdecl Hkobjectresource_ReturnZero()
{
    return 0;
}

// @fnv 0x00e04e60
// src: COMMUNITY 0x00e04e60
void __stdcall nullsub_90(int a, int b)
{}

struct FUN_00e04e70_class
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual int vf6(void* first, void* second);
    int unknown04;
    void* value08;
    void* value0c;
    int hkObjectResource_stealContentsPointer(void* first, void* second);
};
// Calls vf6 with the two arguments, clears value08 and value0c, and returns the result of vf6.
// @fnv 0x00e04e70
// src: HAVOK_SRC 0x00e04e70
int FUN_00e04e70_class::hkObjectResource_stealContentsPointer(void* first, void* second)
{
    int result = vf6(first, second);
    value08 = 0;
    value0c = 0;
    return result;
}

struct FUN_00e04f10_Manager
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual hkReferencedObject* GetSecond();
    virtual hkReferencedObject* GetFirst();
};
extern "C" FUN_00e04f10_Manager* DAT_01268b08;
extern "C" void* DAT_010ea4dc[];
struct FUN_00e04f10_Values
{
    int first, second;
};
class FUN_00e04f10_Class
{
  public:
    void** vtable;
    unsigned short unk04, refCount;
    FUN_00e04f10_Values values;
    hkReferencedObject* first;
    hkReferencedObject* second;
    FUN_00e04f10_Class* Initialize(const FUN_00e04f10_Values* init);
};
// @fnv 0x00e04f10
FUN_00e04f10_Class* FUN_00e04f10_Class::Initialize(const FUN_00e04f10_Values* pInitValues)
{
    refCount = 1;
    vtable = DAT_010ea4dc;
    values = *pInitValues;
    hkReferencedObject* resource = DAT_01268b08->GetFirst();
    if (resource)
        resource->addReference();
    first = resource;
    resource = DAT_01268b08->GetSecond();
    if (resource)
        resource->addReference();
    second = resource;
    return this;
}

namespace fnv_00e04f80 {
struct Resource_00e04f80
{
    const char* FUN_00d46d40();
    unsigned int FUN_00d470d0();
};

struct ListenerVTable_00e04f80;
struct Listener_00e04f80
{
    ListenerVTable_00e04f80* methods;
};
typedef void (Listener_00e04f80::*ResourceCallback_00e04f80)(hkReferencedObject*, const char*);
struct ListenerVTable_00e04f80
{
    ResourceCallback_00e04f80 vfunc00;
    ResourceCallback_00e04f80 vfunc04;
    ResourceCallback_00e04f80 vfunc08;
    ResourceCallback_00e04f80 vfunc0c;
    ResourceCallback_00e04f80 vfunc10;
    ResourceCallback_00e04f80 onResourceRemoved;
};

struct Registry_00e04f80
{
    char* hkClass_isSuperClass(char* status, Resource_00e04f80* resource);
};

extern Registry_00e04f80 DAT_01268748;
extern char DAT_010ea4dc;
extern char DAT_0102e388;

struct FUN_00e04f80_class
{
    void* vtable;
    unsigned short resourceId;
    unsigned short unk06;
    hkReferencedObject* owner;
    Resource_00e04f80* resource;
    hkReferencedObject* context;
    Listener_00e04f80* listener;

    void ReleaseResource();
};

// @fnv 0x00e04f80
void FUN_00e04f80_class::ReleaseResource()
{
    Resource_00e04f80* oldResource = resource;
    vtable = &DAT_010ea4dc;
    if (oldResource)
    {
        char status;
        if (*DAT_01268748.hkClass_isSuperClass(&status, oldResource))
        {
            owner->removeReference();
        }
        else
        {
            Listener_00e04f80* handler = listener;
            if (handler)
            {
                ListenerVTable_00e04f80* methods = handler->methods;
                ResourceCallback_00e04f80* callbackSlot = &methods->onResourceRemoved;
                const char* name = resource->FUN_00d46d40();
                (handler->**callbackSlot)(owner, name);
            }

            unsigned int uiResourceId = resource->FUN_00d470d0();
            hkReferencedObject* savedOwner = owner;
            hkMemoryRouter& router = hkMemoryRouter::getInstance();
            reinterpret_cast<hkMemoryAllocator*>(router.m_heap)->blockFree(savedOwner, uiResourceId);
        }
    }

    if (listener)
        ((hkReferencedObject*)listener)->removeReference();
    ((volatile FUN_00e04f80_class*)this)->listener = 0;

    hkReferencedObject* pRemainingContext = ((volatile FUN_00e04f80_class*)this)->context;
    if (pRemainingContext)
        pRemainingContext->removeReference();
    ((volatile FUN_00e04f80_class*)this)->context = 0;
    ((volatile FUN_00e04f80_class*)this)->vtable = &DAT_0102e388;
}
}  // namespace fnv_00e04f80

namespace fnv_00e05030 {
struct FUN_00d46d40_s
{
    const char* FUN_00d46d40();
    hkBool hkClass_isSuperClass(FUN_00d46d40_s* other);
};

struct Registry
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual FUN_00d46d40_s* GetClassByName(const char* name);
};

struct MyClass
{
    int unk00;
    int unk04;
    void* unk08;
    D481D0Class* unk0C;
    Registry* unk10;

    void* LookupByName(const char* name, hkBool b);
};

// Looks up two registry nodes by the object's name and the given name, compares them, and returns unk08 if they match or name is null, otherwise 0.
// @fnv 0x00e05030
void* MyClass::LookupByName(const char* pcName, hkBool abMatch)
{
    if (pcName)
    {
        Registry* reg = unk10;
        const char* n = unk0C->getName();
        FUN_00d46d40_s* node1 = reg->GetClassByName(n);
        FUN_00d46d40_s* node2 = reg->GetClassByName(pcName);
        abMatch = node2->hkClass_isSuperClass(node1);
        if (abMatch.m_cBooleanValue)
            return unk08;
        return 0;
    }
    return unk08;
}
}  // namespace fnv_00e05030
