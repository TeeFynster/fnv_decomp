#include "../../../../../include/hkArrayBase.h"

// src/havok/physics/dynamics/action/hkpbinaryaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/action/hkpbinaryaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpBinaryAction.h"

struct DDCC60World
{
    void removeReference(void);
};

struct S_00d49310_Lock
{
    ~S_00d49310_Lock(void);
};

extern int DAT_010cc320;
extern int DAT_010cc2fc;
extern int _DAT_0102e388;

struct FUN_00cf4de0_class
{
    void ReleaseReferencedObjectsAndLock(void);
};

// Resets the vtable, releases the two referenced objects at offsets 0x18 and 0x1c, then destroys the lock at 0x14 and resets the vtable again.
// @fnv 0x00cf4de0
// src: GUESS 0x00cf4de0 (confidence: medium)
void FUN_00cf4de0_class::ReleaseReferencedObjectsAndLock(void)
{
    *(void**)this = &DAT_010cc320;
    if (*(void**)((char*)this + 0x18))
    {
        ((DDCC60World*)*(void**)((char*)this + 0x18))->removeReference();
        *(void**)((char*)this + 0x18) = 0;
    }
    if (*(void**)((char*)this + 0x1c))
    {
        ((DDCC60World*)*(void**)((char*)this + 0x1c))->removeReference();
        *(void**)((char*)this + 0x1c) = 0;
    }
    *(void**)this = &DAT_010cc2fc;
    ((S_00d49310_Lock*)((char*)this + 0x14))->~S_00d49310_Lock();
    *(void**)this = &_DAT_0102e388;
}

struct FUN_00c97510
{
    void ProcessPointer(void*);
};

struct FUN_00cf4cc0_class
{
    void hkpBinaryAction_entityRemovedCallback(void* arg);
};

// @fnv 0x00cf4cc0
// src: HAVOK_SRC 0x00cf4cc0
void FUN_00cf4cc0_class::hkpBinaryAction_entityRemovedCallback(void* arg)
{
    void* p = *(void**)((char*)this + 8);
    if (p)
        ((FUN_00c97510*)p)->ProcessPointer(this);
}

struct FUN_00cf4d30_class
{
    void SetRefObject(void* arg);
};
struct RefObj
{
    void RetainReference(void);
};
struct WorldObj
{
    void HandleObjectPointerPair(void*, void*);
    void HandleWorldObjectPair(void*, void*);
};

// Releases the current reference object, stores arg as the new one, and notifies the world object of the change.
// @fnv 0x00cf4d30
void FUN_00cf4d30_class::SetRefObject(void* arg)
{
    ((RefObj*)arg)->RetainReference();
    if (*(void**)((char*)this + 0x1c))
    {
        WorldObj* pWorld = (WorldObj*)*(void**)((char*)this + 8);
        if (pWorld)
            pWorld->HandleWorldObjectPair(this, *(void**)((char*)this + 0x1c));
        ((DDCC60World*)*(void**)((char*)this + 0x1c))->removeReference();
        *(void**)((char*)this + 0x1c) = 0;
    }
    *(void**)((char*)this + 0x1c) = arg;
    WorldObj* w2 = (WorldObj*)*(void**)((char*)this + 8);
    if (w2)
        w2->HandleObjectPointerPair(this, arg);
}

namespace fnv_00d4f850 {
struct RefObj
{
    void RetainReference(void);
};

struct FUN_00d4f850_class : hkReferencedObject
{
    void SetReferencedObject(hkReferencedObject* obj);
};

// @fnv 0x00d4f850
void FUN_00d4f850_class::SetReferencedObject(hkReferencedObject* apObject)
{
    if (apObject)
        ((RefObj*)apObject)->RetainReference();
    if (*(DDCC60World**)((char*)this + 0xac))
        (*(DDCC60World**)((char*)this + 0xac))->removeReference();
    *(hkReferencedObject**)((char*)this + 0xac) = apObject;
}
}  // namespace fnv_00d4f850

struct FUN_00cf4ce0_class
{
    int unk00;
    int unk04;
    void* unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* unk18;
    void hkpBinaryAction_setEntityA(void* newAction);
};

struct FUN_00c90510_class
{
    void FUN_00c90510();
};

struct FUN_00c905b0_class
{
    void FUN_00c905b0();
};

struct FUN_00c976a0_class
{
    void RemoveActionFromEntity(void*, void*);
};

struct FUN_00c92bd0_class
{
    void hkpWorld_attachActionToEntity(void*, void*);
};

// @fnv 0x00cf4ce0
// src: HAVOK_LIB 0x00cf4ce0
void FUN_00cf4ce0_class::hkpBinaryAction_setEntityA(void* newAction)
{
    ((FUN_00c90510_class*)newAction)->FUN_00c90510();
    if (unk18)
    {
        if (unk08)
        {
            ((FUN_00c976a0_class*)unk08)->RemoveActionFromEntity(this, unk18);
        }
        ((FUN_00c905b0_class*)unk18)->FUN_00c905b0();
        unk18 = 0;
    }
    unk18 = newAction;
    if (unk08)
    {
        ((FUN_00c92bd0_class*)unk08)->hkpWorld_attachActionToEntity(this, newAction);
    }
}

struct NameStr
{
    NameStr() throw();
    char* p;
};
struct Ref
{
    virtual ~Ref();
    unsigned short flags;
    short refs;
    Ref() : refs(1)
    {}
};
struct Act : Ref
{
    void* world;
    void* island;
    unsigned long userData;
    NameStr name;
    Act(unsigned long u) : world(0), island(0), userData(u)
    {}
};
struct FUN_00cf4d80 : Act
{
    void* a;
    void* b;
    void Init() throw();
    virtual ~FUN_00cf4d80();
    FUN_00cf4d80(void* x, void* y, unsigned long u);
};
// Constructs the object from two pointers and a userData value, calling Init() when either pointer is non-null.
// @fnv 0x00cf4d80
FUN_00cf4d80::FUN_00cf4d80(void* x, void* y, unsigned long uiUserData) : Act(uiUserData), a(x), b(y)
{
    if (b || a)
        Init();
}

template <int SIZE> __forceinline void memCpyOneAlignedXcf4e30(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXcf4e30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXcf4e30 {
extern "C" hkMemoryRouterXcf4e30& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T>
static __forceinline void hkArrayXcf4e30_AddBack(hkArrayBase<T>& self, const T& e)
{
        hkMemoryRouterXcf4e30& router = hkRouterXcf4e30::hkMemoryRouter_getInstance();
        if (self.m_iElementCount == self.getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, (&self), sizeof(T));
        memCpyOneAlignedXcf4e30<sizeof(T)>(self.m_data + self.m_iElementCount, &e);
        self.m_iElementCount++;
    }

class hkOwnerXcf4e30
{
  public:
    int unk00[6];
    void* m_kPointA;
    void* m_kPointB;

    void GetPointers(hkArrayBase<void*>& out);
};

// @fnv 0x00cf4e30
void hkOwnerXcf4e30::GetPointers(hkArrayBase<void*>& out)
{
    hkArrayXcf4e30_AddBack(out, m_kPointA);
    hkArrayXcf4e30_AddBack(out, m_kPointB);
}
