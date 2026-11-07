// src/fallout_shared/tesobjectanio_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesobjectanio.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


#include "tesobjectanio_decls.h"
struct SFTX
{
    void SetFormType(int);
};
struct B2_4fe
{
    B2_4fe();
    virtual ~B2_4fe();
    unsigned char pad[0x1c];
};
struct FUN_00511950 : public TESForm, public B2_4fe
{
    int pAnim;
    FUN_00511950();
    virtual ~FUN_00511950();
};
void operator delete(void*);
struct FUN_005119e0_obj
{
    void FUN_00511a10();
    void* Destroy(unsigned int flags);
};
struct FUN_004855a0
{
    void __thiscall M();
};
struct FUN_00485680
{
    void __thiscall M();
};
struct S_0048a520
{
    void __thiscall ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct _ref_0084e3a0_t
{
    unsigned int __thiscall _ref_0084e3a0();
};
unsigned int __cdecl _FUN_00485910(unsigned int, unsigned int);
struct FUN_00511d10_shell
{
    void __thiscall TESObjectANIO_Save();
};
class B511A10Form
{
  public:
    virtual ~B511A10Form();

    unsigned char m_cFormType;
    unsigned int m_iFormFlags;
    unsigned int m_iFormID;
    void* m_pkSourceFile;
    void* m_pkNextSourceFile;
};
class B511A10TextureSwap
{
  public:
    virtual ~B511A10TextureSwap();

    const char* m_pcModel;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
    float m_fBound;
    void* m_pkTextures;
    unsigned int m_uiValue1;
    void* m_pkSwapItem;
    void* m_pkSwapNext;
};
class FUN_00511a10_cls : public B511A10Form, public B511A10TextureSwap
{
  public:
    virtual ~FUN_00511a10_cls();
    void ClearData();
};

struct AnimationObjectComparison : TESObjectANIO
{
    bool TESObjectANIO_Compare(TESForm* otherForm);
};

// @fnv 0x00511dc0
// src: XBOX_PDB 0x00511dc0
bool AnimationObjectComparison::TESObjectANIO_Compare(TESForm* otherForm)
{
    TESObjectANIO* otherAnimation = dynamic_cast<TESObjectANIO*>(otherForm);
    if (!otherAnimation)
        return true;
    if (TESForm::Compare(otherAnimation))
        return true;
    if (pObject != otherAnimation->pObject)
        return true;
    return false;
}

struct FUN_005e78f0_t
{
    void __thiscall TESForm_CopyAllComponents(TESForm*);
};
struct AnimationCopyEntry : TESObjectANIO
{
    void __thiscall TESObjectANIO_Copy(TESForm* apCopy);
};
// @fnv 0x00511d70
// src: XBOX_PDB 0x00511d70
void AnimationCopyEntry::TESObjectANIO_Copy(TESForm* apCopy)
{
    TESObjectANIO* panimObj = dynamic_cast<TESObjectANIO*>(apCopy);
    if (panimObj == 0)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(apCopy);
    pObject = panimObj->pObject;
}
