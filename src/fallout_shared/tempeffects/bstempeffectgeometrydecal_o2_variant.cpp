
// src/fallout_shared/tempeffects/bstempeffectgeometrydecal_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tempeffects/bstempeffectgeometrydecal.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/tempeffects/bstempeffectgeometrydecal.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tempeffects/bstempeffectgeometrydecal.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../include/NiRTTI.h"
#include "../../../include/BSDismemberSkinInstance.h"
#include "../../../include/BSTempEffectGeometryDecal.h"
extern const NiRTTI g_011d6b04;
extern unsigned char* DAT_011f5b04;
unsigned char* NiParallelUpdateTaskManager_Get();
extern "C" void __cdecl PowFloat(float, int);
void __cdecl ForwardFloatAndInt(float f, int i);
struct NiFixedString;
extern NiFixedString* DAT_011c6228;
NiFixedString* __cdecl FixedStrings_GetDecal();
extern const NiRTTI g_011f5b2c;
void* __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
struct FUN_00685e60_shell
{
    void __thiscall NiSkinPartition_ReplacePartitions(unsigned int, unsigned int);
};
extern "C" void __cdecl _delete(void* p, unsigned int size);

extern "C" void __cdecl _Call_a5d3a0();
extern int DAT_0109e47c;
struct FUN_00a81f90_class
{
    void* __thiscall NiSkinPartition_NiSkinPartition();
};
// @fnv 0x00a81f90
// src: EXE 0x00a81f90
void* __thiscall FUN_00a81f90_class::NiSkinPartition_NiSkinPartition()
{
    _Call_a5d3a0();
    *(int*)this = (int)&DAT_0109e47c;
    *(int*)((char*)this + 0xc) = 0;
    return this;
}

#include <windows.h>
#include "../../../include/NiSkinInstance.h"
void __cdecl _NiFree_00aa10f0(void* p) throw();
struct S_00a85580_RefObject
{
    virtual ~S_00a85580_RefObject() throw();
    virtual void DeleteThis() throw();
    volatile LONG m_uiRefCount;
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> struct S_00a85580_Pointer
{
    T* m_pObject;
    ~S_00a85580_Pointer() throw()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
};
struct S_00a85580_Object
{
    virtual ~S_00a85580_Object() throw();
    int m_uiRefCount;
};
struct S_00a85580_Renderer;
extern S_00a85580_Renderer* DAT_011f4748;
struct FUN_00a85580;
struct S_00a85580_Renderer
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void PurgeSkinInstance(FUN_00a85580* skin) throw();
};
struct FUN_00a85580 : S_00a85580_Object
{
    S_00a85580_Pointer<S_00a85580_RefObject> unk8;
    S_00a85580_Pointer<S_00a85580_RefObject> unkC;
    int unk10;
    void* unk14;
    ~FUN_00a85580() throw();
};
// @fnv 0x00a85580
FUN_00a85580::~FUN_00a85580() throw()
{
    _NiFree_00aa10f0(unk14);
    if (DAT_011f4748)
        DAT_011f4748->PurgeSkinInstance(this);
}
