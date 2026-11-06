// Source layout: TESObjectREFR. PC corrections are in generate_headers.py.
#ifndef FNV_PACKAGELOCATION_REFERENCE_H
#define FNV_PACKAGELOCATION_REFERENCE_H

#include "layout_support.h"
#include "ExtraDataList.h"
#include "PlacedObjectInfo.h"
#include "TESChildCell.h"
#include "../../include/TESForm.h"
#pragma pack(push, 4)
class TESObjectREFR : public TESForm
{
  public:
    TESChildCell tESChildCellComponent;  // +0x18
    TESSound* m_pSoundForm;              // +0x1C
    PlacedObjectInfo data;                       // +0x20
    float m_fObjectScale;                     // +0x3C
    TESObjectCELL* m_pOwningCell;          // +0x40
    ExtraDataList m_kExtraDataCollection;               // +0x44
    CellDataNode* m_pRenderData;        // +0x64
    virtual void Unk_4E(void);
    virtual void Unk_4F(void);
    virtual void Unk_50(void);
    virtual void Unk_51(void);
    virtual bool CastShadows(void);
    virtual void Unk_53(void);
    virtual void Unk_54(void);
    virtual void Unk_55(void);
    virtual void Unk_56(void);
    virtual void Unk_57(void);
    virtual void Unk_58(void);
    virtual void Unk_59(void);
    virtual void Unk_5A(void);
    virtual void Unk_5B(void);
    virtual void Unk_5C(void);
    virtual void Unk_5D(void);
    virtual void Unk_5E(void);
    virtual TESObjectREFR* RemoveItem(TESForm* toRemove, ExtraDataList* extraList, unsigned int count,
                                      unsigned int unk3, unsigned int unk4, TESObjectREFR* destRef, unsigned int unk6,
                                      unsigned int unk7, unsigned int unk8, unsigned char unk9);
    virtual void Unk_60(void);
    virtual void Unk_61(void);
    virtual void Unk_62(void);
    virtual void Unk_63(void);
    virtual void AddItem(TESForm* item, ExtraDataList* xDataList, unsigned int Quantity);
    virtual void Unk_65(void);
    virtual void Unk_66(void);
    virtual void Unk_67(void);
    virtual bool GetIsChildSize(bool checkHeight);
    virtual unsigned int GetActorUnk0148(void);
    virtual void SetActorUnk0148(unsigned int arg0);
    virtual void Unk_6B(void);
    virtual void Unk_6C(void);
    virtual void Unk_6D(void);
    virtual void Unk_6E(void);
    virtual void Unk_6F(void);
    virtual void Unk_70(void);
    virtual void AnimateNiNode(void);
    virtual void GenerateNiNode(bool arg0);
    virtual void Set3D(NiNode* niNode, bool unloadArt);
    virtual NiNode* GetNiNode(void);
    virtual void Unk_75(void);
    virtual void Unk_76(void);
    virtual void Unk_77(void);
    virtual void Unk_78(void);
    virtual AnimData* GetAnimData(void);
    virtual ValidBip01Names* GetValidBip01Names(void);
    virtual ValidBip01Names* CallGetValidBip01Names(void);
    virtual void SetValidBip01Names(ValidBip01Names validBip01Names);
    virtual NiPoint3* GetPos(void) const;
    virtual void Unk_7E(unsigned int arg0);
    virtual void Unk_7F(void);
    virtual void Unk_80(unsigned int arg0);
    virtual void Unk_81(unsigned int arg0);
    virtual void Unk_82(void);
    virtual unsigned int Unk_83(void);
    virtual void Unk_84(unsigned int arg0);
    virtual unsigned int Unk_85(void);
    virtual bool IsCharacter(void);
    virtual bool Unk_87(void);
    virtual bool Unk_88(void);
    virtual void Unk_89(void);
    virtual void Unk_8A(void);
    virtual void Unk_8B(void);
    virtual bool Unk_8C(void);
    virtual bool Unk_8D(void);
    virtual void Unk_8E(void);
    virtual void Unk_8F(void);
    enum
    {
        CHANGE_SCRIPT_VARIABLES = 0x80000000u
    };
    ScriptLocals* GetReferenceLocals();
    TESObjectCELL* GetParentCell();
    TESObjectREFR* GetLinkedRef();
    TESBoundObject* GetObjectReference();
    ExtraDataList* GetExtraData();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObjectREFR) == 0x68);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, tESChildCellComponent) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, m_pSoundForm) == 0x1C);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, data) == 0x20);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, m_fObjectScale) == 0x3C);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, m_pOwningCell) == 0x40);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, m_kExtraDataCollection) == 0x44);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, m_pRenderData) == 0x64);
#endif
