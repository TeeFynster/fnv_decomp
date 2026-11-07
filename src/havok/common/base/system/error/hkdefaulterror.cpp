#include "../../../../../../include/hkArray.h"

// src/havok/common/base/system/error/hkdefaulterror.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/error/hkdefaulterror.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00626490_Class
{
    int LookupHashEntry(int first, int second);
};
struct FUN_00d2b3b0_Class
{
    int unk00;
    int unk04;
    FUN_00626490_Class helper;
    unsigned char* hkDefaultError_isEnabled(unsigned char* result, int value);
};
// @fnv 0x00d2b3b0
// src: HAVOK_LIB 0x00d2b3b0
unsigned char* FUN_00d2b3b0_Class::hkDefaultError_isEnabled(unsigned char* result, int value)
{
    *result = (helper.LookupHashEntry(value, 0) == 0);
    return result;
}

struct D2B3D0Map
{
    void clear();
};

struct D2B3D0Owner
{
    int unk00;
    int unk04;
    D2B3D0Map m_map;

    void hkDefaultError_enableAll();
};

// @fnv 0x00d2b3d0
// src: XBOX_PDB 0x00d2b3d0
void D2B3D0Owner::hkDefaultError_enableAll()
{
    m_map.clear();
}

struct FUN_00cb18f0_t
{
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(int value);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(int managerValue, int value, int flag);
};
struct FUN_00c85750_return
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
FUN_00c85750_return* __cdecl hkMemoryRouter_getInstance();
struct FUN_00d2b5c0_class
{
    int unk00;
    int unk04;
    FUN_00cb18f0_t sub;
    void hkDefaultError_setEnabled(int value, char flag);
};
// If flag is set, forwards value to sub.FUN_00cb1fb0; otherwise passes manager->unk10 and value to sub.FUN_00cb1870.
// @fnv 0x00d2b5c0
// src: HAVOK_LIB 0x00d2b5c0
void FUN_00d2b5c0_class::hkDefaultError_setEnabled(int value, char flag)
{
    if (flag != 0)
    {
        sub.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(value);
        return;
    }
    FUN_00c85750_return* manager = hkMemoryRouter_getInstance();
    sub.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(manager->unk10, value, 1);
}

namespace fnv_00d2b710 {
struct ManagerVTable
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void notify(void* object, unsigned short value);
};
struct AudioState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ManagerVTable* unk10;
};
struct Base
{
    void ClearAndReset();
};
struct Widget : Base
{
    int unk00;
    unsigned short unk04;
    int unk06;
    void* GetSelfWithNotify(unsigned char flags);
};
extern AudioState* __cdecl hkMemoryRouter_getInstance();
// Calls the base function, and if bit 0 of flags is set, notifies the audio manager's vtable with this object and unk04, then returns this.
// @fnv 0x00d2b710
void* Widget::GetSelfWithNotify(unsigned char flags)
{
    ClearAndReset();
    if (flags & 1)
    {
        AudioState* state = hkMemoryRouter_getInstance();
        state->unk10->notify(this, unk04);
    }
    return this;
}
}  // namespace fnv_00d2b710

struct D2B600Allocator;

struct D2B600MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2B600Allocator* m_pStreamAllocator;

    D2B600Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D2B600MemoryRouter& __cdecl D2B600GetMemoryRouter();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct D2B600Object
{
    int unk00;
};

static __forceinline void ConstructArray46(D2B600Object** p, int n, D2B600Object* const& e)
{
        for (int i = 0; i < n; i++)
            p[i] = e;
    }
typedef hkArray<D2B600Object*> D2B600ObjectArray;
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
return reinterpret_cast<hkMemoryAllocator&>(D2B600GetMemoryRouter().heap());
}
template<> __forceinline void hkArrayBase<D2B600Object*>::_pushBack(hkMemoryAllocator& sharedAlloc, D2B600Object* const& e)
{
D2B600Allocator& alloc = reinterpret_cast<D2B600Allocator&>(sharedAlloc);

        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(D2B600Object*));
        ConstructArray46(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    
}


struct D2B600Container
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    D2B600ObjectArray m_kTrackedObjects;

    void AppendObject(D2B600Object* object, int iUnused);
};

// Appends the given object pointer to the container's object array via its push-back method.
// @fnv 0x00d2b600
void D2B600Container::AppendObject(D2B600Object* object, int iUnused)
{
    m_kTrackedObjects.pushBack(object);
}

extern char DAT_010ce5d4[];

struct D2B640Sub
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;

    void EnsureCapacity(int first, int second);
};

struct D2B640Object
{
    void* m_vtbl;
    unsigned short unk04;
    unsigned short m_06;
    D2B640Sub m_08;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;

    D2B640Object* Initialize(int a1, int a2);
};

// @fnv 0x00d2b640
D2B640Object* D2B640Object::Initialize(int a1, int a2)
{
    *(unsigned short volatile*)&m_06 = 1;
    m_vtbl = DAT_010ce5d4;
    D2B640Sub* sub = (D2B640Sub*)((char*)this + 8);
    *(unsigned int volatile*)&sub->m_00 = 0;
    *(unsigned int volatile*)&sub->m_04 = 0;
    *(unsigned int volatile*)&sub->m_08 = 0xffffffffu;
    FUN_00c85750_return* pResult = hkMemoryRouter_getInstance();
    sub->EnsureCapacity(pResult->unk10, 0);
    *(unsigned int volatile*)&m_14 = 0;
    *(unsigned int volatile*)&m_18 = 0;
    *(unsigned int volatile*)&m_1c = 0x80000000u;
    *(unsigned int volatile*)&m_20 = (unsigned int)a1;
    m_24 = (unsigned int)a2;
    return this;
}

struct D2B6Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct D2B6Sub
{
    int unk00;
    int unk04;
    int unk08;

    void ProcessArgument(int value);
    void Object_DoNothing();
};

extern int DAT_0102e388;

struct FUN_00d2b6b0_cls
{
    int m_vptr00;
    int unk04;
    D2B6Sub m_sub;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void ClearAndReset();
};

// Frees m_pData via the allocator when the capacity flag is clear, resets the data pointer and capacity, then reinitializes m_sub and sets the vtable.
// @fnv 0x00d2b6b0
void FUN_00d2b6b0_cls::ClearAndReset()
{
    FUN_00c85750_return* pHolder = hkMemoryRouter_getInstance();
    D2B6Allocator* pAllocator = (D2B6Allocator*)pHolder->unk10;
    m_iArrayLength = 0;
    unsigned int uCapacityFlags = m_uCapBits;
    if ((uCapacityFlags & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_pData, (uCapacityFlags & 0x3fffffffu) * 4);
    }
    m_pData = 0;
    m_uCapBits = 0x80000000u;
    D2B6Sub* pSub = &m_sub;
    pSub->ProcessArgument(hkMemoryRouter_getInstance()->unk10);
    pSub->Object_DoNothing();
    m_vptr00 = (int)&DAT_0102e388;
}

extern "C" int __cdecl Vsnprintf(char* buf, unsigned size, const char* fmt, ...);

struct S_00d2b3e0_Mgr
{
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    void ReleaseReference();
    int hkStackTracer_getStackTrace(void** trace, int max);
    void hkStackTracer_dumpStackTrace(void** trace, int count, void(__cdecl* cb)(const char*, int), int user);
};
extern S_00d2b3e0_Mgr* DAT_01269a84;
S_00d2b3e0_Mgr* __cdecl hkStackTracer_create();

struct S_00d2b3e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void(__cdecl* m_callback)(const char*, int);
    int m_user;
    void hkDefaultError_showMessage(const char* kind, int code, const char* msg, const char* file, int line, char trace);
};

// Formats a message with optional file/line/code/kind, invokes m_callback, and optionally dumps a stack trace via DAT_01269a84.
// @fnv 0x00d2b3e0
// src: HAVOK_LIB 0x00d2b3e0
void S_00d2b3e0::hkDefaultError_showMessage(const char* kind, int code, const char* msg, const char* file, int line, char trace)
{
    unsigned int buf[512];
    if (code == 0 && file == 0)
        Vsnprintf((char*)buf, 0x800, "%s\n", msg);
    else
        Vsnprintf((char*)buf, 0x800, "%s(%d): [0x%08X] %s : %s\n", file, line, code, kind, msg);
    ((char*)buf)[0x7ff] = 0;
    m_callback((char*)buf, m_user);
    if (trace)
    {
        if (!DAT_01269a84)
        {
            S_00d2b3e0_Mgr* pCurMgr = hkStackTracer_create();
            S_00d2b3e0_Mgr* pOldMgr = DAT_01269a84;
            if (pOldMgr)
                pOldMgr->ReleaseReference();
            DAT_01269a84 = pCurMgr;
        }
        void* frames[20];
        int n = DAT_01269a84->hkStackTracer_getStackTrace(frames, 20);
        if (n > 2)
        {
            m_callback("Stack trace is:\n", m_user);
            DAT_01269a84->hkStackTracer_dumpStackTrace(frames + 2, n - 2, m_callback, m_user);
        }
    }
}

struct FUN_00d2b5b0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void hkDefaultError_sectionEnd();
};
// @fnv 0x00d2b5b0
// src: XBOX_PDB 0x00d2b5b0
void FUN_00d2b5b0_Class::hkDefaultError_sectionEnd()
{
    unk18--;
}

struct Bool8
{
    unsigned char value;
    Bool8()
    {}
    Bool8(bool v) : value(v ? 1 : 0)
    {}
    operator bool() const
    {
        return value != 0;
    }
};

struct D2ErrorHost
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual Bool8 v14(int value);
    int unk04, unk08, unk0c, unk10;
    struct Array
    {
        int* data;
        int size;
        int GetLogicalSize() const
        {
            return size;
        }
        int back() const
        {
            return data[size - 1];
        }
    } items;
    void hkDefaultError_showMessage(const char* name, int key, int a3, int a4, int a5, Bool8 flags);
    int hkDefaultError_message(int mode, int index, int a3, int a4, int a5);
};

// Resolves index to last item if -1, validates it via v14, maps mode to a name and flag, calls FUN_00d2b3e0, returns 1 for modes 2 or 3.
// @fnv 0x00d2b4f0
// src: HAVOK_LIB 0x00d2b4f0
int D2ErrorHost::hkDefaultError_message(int mode, int index, int aiArg3, int aiArg4, int aiArg5)
{
    if (index == -1)
    {
        if (items.GetLogicalSize() != 0)
            index = items.back();
    }
    if (!v14(index))
        return 0;
    const char* name = "";
    Bool8 flag(false);
    switch (mode)
    {
    case 0:
        name = "Report";
        break;
    case 1:
        name = "Warning";
        break;
    case 2:
        name = "Assert";
        flag = true;
        break;
    case 3:
        name = "Error";
        flag = true;
        break;
    }
    hkDefaultError_showMessage(name, index, aiArg3, aiArg4, aiArg5, flag);
    if (mode == 2 || mode == 3)
        return 1;
    return 0;
}
