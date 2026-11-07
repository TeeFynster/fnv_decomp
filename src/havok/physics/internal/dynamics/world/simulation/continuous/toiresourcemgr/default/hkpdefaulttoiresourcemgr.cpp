
// src/havok/physics/internal/dynamics/world/simulation/continuous/toiresourcemgr/default/hkpdefaulttoiresourcemgr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/dynamics/world/simulation/continuous/toiresourcemgr/default/hkpdefaulttoiresourcemgr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../../../include/hkArray.h"
#include "../../../../../../../../../../include/hkBool.h"
#include "../../../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../../../include/hkResult.h"
#include "../../../../../../../../../../include/MemoryManager.h"
#include "../../../../../../../../../../include/hkMemoryRouter.h"

extern char g_0126955c_arg0;

// Calls two virtual functions on self: one with a pointer to g_0126955c_arg0, then one with no arguments.
// @fnv 0x00d9fb50
// src: XBOX_PDB 0x00d9fb50
void __stdcall hkpDefaultToiResourceMgr_calcContentStatistics(void* self, int aiUnused)
{
    (*(void(__thiscall**)(void*, char*))(*(char**)self + 0x18))(self, &g_0126955c_arg0);
    (*(void(__thiscall**)(void*))(*(char**)self + 0x1c))(self);
}

struct hkpToiEvent;

// Local until include/hkpToiResources.h exists; the resource buffer is at +0x18.
struct hkpToiResources
{
    int m_iFirstValue;
    int m_iSecondInteger;
    int m_iThirdValue;
    int m_iFourthValue;
    int m_iFifthInteger;
    int m_numRequiredStepsForSolver;
    char* m_pCharacterBuffer;
    int m_iCharacterBufferSize;
};

// Local until include/hkpDefaultToiResourceMgr.h exists; reflected size is 0x10.
class hkpDefaultToiResourceMgr
{
  public:
    hkpDefaultToiResourceMgr();
    virtual ~hkpDefaultToiResourceMgr();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_iNumToiResources;
    int m_iMaxNumToiResources;

    void* AllocateMemory(int, int, hkpToiResources*);
    void* FUN_00d9fc70(unsigned char flag);

    hkBool Object_UpdateFields_00d9fb40(const hkpToiEvent& event) throw();
    hkResult AllocateToiResources(const hkpToiEvent& event, const hkArray<hkpToiEvent>& otherEvents,
                                    hkpToiResources& resourcesOut);
};

extern int DAT_010d4310;

// @fnv 0x00d9fb90
hkpDefaultToiResourceMgr::hkpDefaultToiResourceMgr()
{
    m_sReferenceCount = 1;
    *(void**)this = (void*)&DAT_010d4310;
    m_iMaxNumToiResources = 0x20000;
}

hkMemoryRouter* __cdecl _D1A0E0GetMemoryRouter();

// Returns the resource buffer through the solver allocator, using the allocated byte count.
// @fnv 0x00d9fc30
void* hkpDefaultToiResourceMgr::AllocateMemory(int, int, hkpToiResources* pInfo)
{
    int size = m_iNumToiResources;
    char* buffer = pInfo->m_pCharacterBuffer;
    hkMemoryRouter* pRouter = _D1A0E0GetMemoryRouter();
    // The solver allocator occupies the router slot at 0x18.
    MemoryManager* manager = *(MemoryManager**)((char*)pRouter + 0x18);
    typedef void* (__thiscall* ReturnBufferFunction)(MemoryManager*, char*, int);
    return (*(ReturnBufferFunction**)manager)[4](manager, buffer, size);
}

typedef void(__thiscall* FUN_00d9fc70_Callback)(MemoryManager*, void*, unsigned short);

// Destroys the manager, optionally releases its storage, and returns this.
// @fnv 0x00d9fc70
void* hkpDefaultToiResourceMgr::FUN_00d9fc70(unsigned char flag)
{
    this->hkpDefaultToiResourceMgr::~hkpDefaultToiResourceMgr();

    if (flag & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        MemoryManager* memoryManager = reinterpret_cast<MemoryManager*>(router->m_heap);
        unsigned short size = m_usMemSizeAndFlags;
        FUN_00d9fc70_Callback callback = (*(FUN_00d9fc70_Callback**)memoryManager)[2];

        callback(memoryManager, this, size);
    }

    return this;
}

// @fnv 0x00d9fb70
// src: GUESS 0x00d9fb70 (confidence: high)
int __cdecl hkpDefaultToiResourceMgr_ReturnOne()
{
    return 1;
}

// FUN_00d9fc60
// Returns the address of the global registration object that lives at
// DAT_0126955c.  The startup code fills that object (13 dwords) through a
// constructor call, and this getter hands out its address.
extern int DAT_0126955c;

// @fnv 0x00d9fc60
// src: GUESS 0x00d9fc60 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00d9fc60()
{
    return &DAT_0126955c;
}

// @fnv 0x00d9fb80
// src: GUESS 0x00d9fb80 (confidence: high)
int __stdcall Object_ReturnZero_00d9fb80(int arg0)
{
    return 0;
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

inline hkMemoryAllocator& solverAllocator(hkMemoryRouter& router)
{
    return **(hkMemoryAllocator**)((char*)&router + 0x18);
}

template <class T> inline T* hkMemoryAllocator::_bufAlloc(int& n)
{
    int nb = n * sizeof(T);
    T* p = static_cast<T*>(bufAlloc(nb));
    n = nb / sizeof(T);
    return p;
}

// @fnv 0x00d9fbb0
hkResult hkpDefaultToiResourceMgr::AllocateToiResources(const hkpToiEvent& event,
                                                       const hkArray<hkpToiEvent>& otherEvents,
                                                       hkpToiResources& resourcesOut)
{
    if (Object_UpdateFields_00d9fb40(event))
    {
        m_iNumToiResources = resourcesOut.m_iCharacterBufferSize = m_iMaxNumToiResources;
        resourcesOut.m_pCharacterBuffer = solverAllocator(hkMemoryRouter_getInstance())._bufAlloc<char>(m_iNumToiResources);
        resourcesOut.m_iThirdValue = 1000;
        resourcesOut.m_iFourthValue = 1000;
        resourcesOut.m_iSecondInteger = 1000;
        resourcesOut.m_iFifthInteger = 3;
        resourcesOut.m_numRequiredStepsForSolver = 4;
        resourcesOut.m_iFirstValue = 3;
        return HK_SUCCESS;
    }
    return HK_FAILURE;
}
