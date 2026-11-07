
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiD3DShaderProgram.h"
#include "../../../../include/NiTMapBase.h"
#include "../../../../include/NiTPointerAllocator.h"

class NiShader;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiShader*> ShaderMapBase;

extern "C" void __cdecl _delete(void*, unsigned int);


// Calls FUN_00e89840, then deletes this with size 0x2c when flags has bit 1 set, and returns this.
// @fnv 0x00e898a0
void* NiD3DShaderProgram::DestroyIfFlagged(unsigned int flags)
{
    UpdateFields_00e89840();
    if (flags & 1)
        _delete(this, 0x2c);
    return this;
}

struct Direct3DDeviceInterface
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual char const* GetName();
};
struct Program
{
    char _pad[0x14];
    ShaderMapBase* pkMap;
};
extern Program* DAT_0126fa10;
// If the global Program and its map exist, gets the device's name and removes that entry from the map.
// @fnv 0x00e93790
void RemoveDeviceFromMap(Direct3DDeviceInterface* pkD3DDevice)
{
    if (!DAT_0126fa10)
        return;
    if (!pkD3DDevice)
        return;
    char const* psz = pkD3DDevice->GetName();
    if (!psz)
        return;
    ShaderMapBase* pkM = DAT_0126fa10->pkMap;
    if (!pkM)
        return;
    pkM->RemoveAt(psz);
}

void __cdecl _NiFreeAlias(void*);
extern int DAT_010f119c;
struct S
{
    void SetVtableAndProcessState_00e971d0();
    void RemoveDeviceAndClearShader();
};
struct ComObj
{
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
// Sets the vtable, frees the two pointers at offsets 0x3C and 0x40, releases and clears the ComObj at 0x44, then calls FUN_00e89b70.
// @fnv 0x00e971d0
// src: GUESS 0x00e971d0 (confidence: low)
void S::SetVtableAndProcessState_00e971d0()
{
    void* v1 = *(void**)((char*)this + 0x3C);
    *(void**)this = (void*)&DAT_010f119c;
    _NiFreeAlias(v1);
    _NiFreeAlias(*(void**)((char*)this + 0x40));
    ComObj* p = *(ComObj**)((char*)this + 0x44);
    if (p)
    {
        p->Release();
        *(ComObj**)((char*)this + 0x44) = 0;
    }
    RemoveDeviceAndClearShader();
}

__declspec(noinline) void RemoveDeviceFromMap(Direct3DDeviceInterface*);
extern int DAT_010ef87c;

struct FUN_00e69970_class
{
    void __thiscall ClearShader(void* a);
};

// Sets the vtable, removes this device from the map, calls FUN_00e69970 when offset 0x34 is nonzero using the pointer at 0x24, then calls FUN_00e89840.
// @fnv 0x00e89b70
// src: GUESS 0x00e89b70 (confidence: medium)
__declspec(noinline) void S::RemoveDeviceAndClearShader()
{
    char* self = (char*)this;
    *(void**)self = (void*)&DAT_010ef87c;
    RemoveDeviceFromMap((Direct3DDeviceInterface*)this);
    if (*(void**)(self + 0x34) != 0)
    {
        ((FUN_00e69970_class*)*(void**)(self + 0x24))->ClearShader(this);
    }
    ((NiD3DShaderProgram*)this)->UpdateFields_00e89840();
}
