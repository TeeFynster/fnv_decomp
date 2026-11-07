#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkOstream.h"
#include "../../../../../include/hkError.h"

// src/havok/common/serialize/packfile/hkpackfilewriter_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/serialize/packfile/hkpackfilewriter.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/packfile/hkpackfilewriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/packfile/hkpackfilewriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void __cdecl ResizeAudioStream(void* a, void* b, int c);

struct TaggedName
{
    const char* tagged;
    const char* text() const
    {
        return (const char*)((unsigned int)tagged & ~1u);
    }
};
struct RigidBody
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c;
    int field20, field24, field28, field2c, field30, field34, field38, field3c;
    int field40, field44, field48, field4c, field50, field54, field58, field5c;
    int field60, field64, field68, field6c, field70;
    TaggedName name;
};
struct Constraint
{
    int field00, field04, field08, field0c, field10;
    RigidBody* bodyA;
    RigidBody* bodyB;
};
struct Bone
{
    TaggedName name;
    int lockTranslation;
};
struct Skeleton
{
    int field00, field04, field08;
    short* parents;
    int field10, field14;
    Bone* bones;
    int boneCount;
};
inline hkMemoryRouter* router()
{
    return (&hkMemoryRouter::getInstance());
}

int __cdecl hkString_strCmp(const char*, const char*) throw();
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & (int)0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    this->_clearAndDeallocate(*reinterpret_cast<hkMemoryAllocator*>(::router()->m_heap));
}

template <class T> struct LocalArray : hkArray<T>
{
    T* initial;
    LocalArray(int count) throw()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
        hkMemoryRouter* router = ::router();
        T* allocated = (T*)router->m_stack.m_next.m_storage;
        router->m_stack.m_next.m_storage = (void*)((int)((char*)allocated + ((count * sizeof(T) + 127) & ~127)));
        this->m_data = allocated;
        this->m_iCapacityState = count | 0x80000000;
        initial = allocated;
    }
    void clear()
    {
        this->m_iElementCount = 0;
    }
    static void resetStack(T* p)
    {
        ::router()->m_stack.m_next.m_storage = (void*)((int)p);
    }
    ~LocalArray() throw()
    {
        if (initial == this->m_data)
            clear();
        resetStack(initial);
    }
    void AddBack(T value) throw()
    {
        hkMemoryRouter* router = ::router();
        if (this->m_iElementCount == (this->m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_heap, this, sizeof(T));
        this->m_data[this->m_iElementCount++] = value;
    }
};
struct Ragdoll
{
    void* vtable;
    unsigned short allocationSize;
    unsigned short references;
    Ragdoll* __thiscall FUN_00ce2510(hkArray<RigidBody*>*, hkArray<Constraint*>*, Skeleton*, hkArray<int>*) throw();
};
// @fnv 0x00cea810
// src: HAVOK_LIB 0x00cea810
Ragdoll* __cdecl hkaRagdollUtils_createRagdollInstanceFromSkeleton(Skeleton* skeleton, const hkArray<RigidBody*>& bodies,
                              const hkArray<Constraint*>& constraints)
{
    int count = skeleton->boneCount;
    LocalArray<RigidBody*> matchedBodies(count);
    LocalArray<Constraint*> matchedConstraints(count - 1);
    LocalArray<int> boneToBody(count);
    char buffer[512];
    bool missingName = false;
    for (int i = 0; i < count; ++i)
    {
        Bone& bone = skeleton->bones[i];
        short parent = skeleton->parents[i];
        if (!(bone.name.text()))
        {
            missingName = true;
            break;
        }
        RigidBody* body = 0;
        for (int j = 0; j < bodies.m_iElementCount; ++j)
        {
            RigidBody* candidate = bodies.m_data[j];
            const char* name = candidate->name.text();
            if (name && hkString_strCmp(name, bone.name.text()) == 0)
            {
                if (!body)
                    body = candidate;
                else
                {
                    hkOstream message(static_cast<void*>(buffer), 512);
                    message.ProcessAndReturnValue_00cc01c0("Some RBS have duplicated names : ").ProcessAndReturnValue_00cc01c0((const char*)name);
                    hkError::s_instance->message(1, 0xabba98aa, buffer, ".\\Utils\\hkaRagdollUtils.cpp", 0x26b);
                }
            }
        }
        if (!body)
        {
            boneToBody.AddBack(-1);
            continue;
        }
        boneToBody.AddBack(matchedBodies.m_iElementCount);
        matchedBodies.AddBack(body);
        if (parent == -1)
            continue;
        RigidBody* parentBody = matchedBodies.m_data[boneToBody.m_data[parent]];
        Constraint* constraint = 0;
        for (int j = 0; j < constraints.m_iElementCount; ++j)
        {
            Constraint* candidate = constraints.m_data[j];
            RigidBody* a = candidate->bodyA;
            RigidBody* b = candidate->bodyB;
            if (a == body && b == parentBody)
            {
                if (!constraint)
                    constraint = candidate;
                else
                {
                    hkOstream message(static_cast<void*>(buffer), 512);
                    message.ProcessAndReturnValue_00cc01c0("Found more than one constraint between rigid bodies ")
                        .ProcessAndReturnValue_00cc01c0((const char*)(a->name.text()))
                        .ProcessAndReturnValue_00cc01c0(" and ")
                        .ProcessAndReturnValue_00cc01c0((const char*)(b->name.text()));
                    hkError::s_instance->message(1, 0xabba82ff, buffer, ".\\Utils\\hkaRagdollUtils.cpp", 0x291);
                }
            }
        }
        if (!constraint)
        {
            hkOstream message(static_cast<void*>(buffer), 512);
            message.ProcessAndReturnValue_00cc01c0("Couldn't find constraint for bone : ").WriteName(*reinterpret_cast<const hkStringPtr*>(&bone));
            hkError::s_instance->message(1, 0xabba9f9f, buffer, ".\\Utils\\hkaRagdollUtils.cpp", 0x298);
            return 0;
        }
        matchedConstraints.AddBack(constraint);
    }
    if (missingName)
    {
        {
            hkOstream message(static_cast<void*>(buffer), 512);
            message.ProcessAndReturnValue_00cc01c0("Some bones have no name - can't create rag doll");
            hkError::s_instance->message(1, 0xabbae6a2, buffer, ".\\Utils\\hkaRagdollUtils.cpp", 0x2a3);
        }
        return 0;
    }
    if (!matchedBodies.m_iElementCount)
    {
        hkOstream message(static_cast<void*>(buffer), 512);
        message.ProcessAndReturnValue_00cc01c0("Skeleton has no associated rigid bodies - can't create rag doll");
        hkError::s_instance->message(1, 0xabbae6e4, buffer, ".\\Utils\\hkaRagdollUtils.cpp", 0x2aa);
        return 0;
    }
    {
        Ragdoll* result = (Ragdoll*)reinterpret_cast<hkMemoryAllocator*>(::router()->m_heap)->blockAlloc(0x30);
        result->allocationSize = 0x30;
        result = result->FUN_00ce2510(&matchedBodies, &matchedConstraints, skeleton, &boneToBody);
        return result;
    }

    return 0;
}
