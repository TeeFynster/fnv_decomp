#include "../../include/Setting.h"
// 0x00408d60 returns the setting value at +4 (or a fallback byte for null this).

// fallout_shared/bgsdecalmanager_decls.h: declares NiColorA, Setting, NiRenderer, DecalVtableCall
#ifndef BGSDECALMANAGER_DECLS_H
#define BGSDECALMANAGER_DECLS_H

#include "layout_support.h"
#ifndef FNV_FORCEINLINE
#define FNV_FORCEINLINE inline
#endif

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class TESObjectCELL;
class BSTempEffectSimpleDecal;
class BSFaceGenAnimationData;
class NiProperty;
class NiTexture;
class ParentSpaceNode;
class NiColorA;
template <class T> class DecalNiPointer
{
  public:
    T* m_pObject;
};
#include "../../include/NiColorA.h"

template <> class DecalNiPointer<BSFaceGenAnimationData>
{
  public:
    BSFaceGenAnimationData* m_pObject;
    operator BSFaceGenAnimationData*() const;
};
template <> class DecalNiPointer<NiTexture>
{
  public:
    NiTexture* m_pObject;
    ~DecalNiPointer();
};

#include "../../include/BSSimpleArray.h"
template <class T> class DecalNiTPointerAllocator
{
};
template <class Allocator, class T> class DecalNiTPointerListBase
{
  public:
    T& GetNext(void*&);
    DecalNiPointer<NiTexture> RemovePos(void*&);
};

class TESTopic;
// 0x0043b1b0 -> 0x0043b1d0 loads the first pointer as a string; this is a folded string view, not list traversal.
struct FirstPointerStringView_0043b1b0
{
    const char* FUN_0043b1b0();
};
#include "../../include/TESTopicInfoData.h"

extern Setting DAT_011c5904;
extern int DAT_011c57ec;
extern unsigned int DAT_011c57f4;
extern "C" const char DAT_0101e1c8[];
extern "C" const char DAT_0101e19c[];
extern "C" const char DAT_0101e174[];

#include "../../include/NiRenderer.h"
NiRenderer* NiXenonRenderer_GetRenderer();
int __cdecl Warning(const char*, ...);

class DecalVtableCall
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
};

#endif
