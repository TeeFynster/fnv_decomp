#pragma once

#include "TESActorBase.h"
#include "TESRaceForm.h"
#include "ActorSkillData.h"
#include "BSSimpleArray.h"
#include "NiAVObject.h"
#include "MagicTarget.h"
#include "FaceGenMatrix.h"

class Actor;
class Biped;
class BipedAnim;
class BGSBipedModelList;
class BGSHeadPart;
class BSFaceGenNiNode;
class FaceGenUndo;
class NiTexture;
class TESClass;
class TESCombatStyle;
class TESEyes;
class TESHair;
class TESRace;
class ValidBip01Names;

class TESNPC : public TESActorBase, public TESRaceForm
{
public:
    TESNPC();
    virtual ~TESNPC();

    // All 104 primary slots are inherited from TESActorBase.
    virtual void ClearData();
    virtual void InitItem();
    virtual void Revert(BGSLoadFormBuffer*);
    virtual TESCombatStyle* GetCombatStyle() const;
    virtual void SetCombatStyle(TESCombatStyle*);
    virtual int GetActorValue(ActorValue::Index actorValue);

    bool Activate(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int);
    bool Load(TESFile*);
    virtual void LoadGame(BGSLoadFormBuffer*);
    void UpdateActorFaceGen(TESObjectREFR*, BipedAnim*, BSFaceGenNiNode*, BSFaceGenNiNode*);
    void UpdateActorFaceGen(Actor*, Biped*, unsigned int, unsigned int);
    void UpdateModel3D(TESObjectREFR*, bool, bool, bool, bool);
    void UpdateActorBaseData(bool);
    void RebuildHeadModel(TESObjectREFR*, BipedAnim*, bool);
    void RebuildHeadModel(TESObjectREFR*, void*);
    void RebuildHeadModel(TESObjectREFR*, void*, int);
    void AttachHeadParts(TESObjectREFR*, NiNode*);
    void ResetFormData();
    void Copy(TESForm*);
    void CopyActorBaseData(TESNPC*);
    void CollectNPCsByRaceAndSex(TESRace*, SEX, BSSimpleArray<TESNPC*, 1024>*);
    float GetHairLength();
    TESEyes* FUN_00602150();
    unsigned int TESDataHandler_GetRegionList();
    void SetField1F0(TESNPC*);
    BipedAnim* GetBipedAnimationForReference(TESObjectREFR*);
    void UpdateHeadParts(TESObjectREFR*, BipedAnim*);
    bool InitWornObject(TESObjectREFR*, BipedAnim*, TESBoundObject*);
    void GetFaceGenNodes(BSFaceGenNiNode*&, BSFaceGenNiNode*&);
    void GetFaceGenNodes(unsigned int*, unsigned int*);
    TESHair* GetHair();
    float GetWeight();
    float GetDefaultHeight();
    void GetFaceGenCoords(FaceGenMatrix<float> (&)[2][2]);
    void GetFaceGenCoords(FaceGenCoord (&)[4]);
    TESRace* GetRace();
    void SetActorValue(ActorValue::Index, int);
    ActorSkillData* GetTextureManager();
    void UpdateBodyModel(TESObjectREFR*, BipedAnim*);
    BSSimpleList<BGSHeadPart*>* InterfaceManager_GetVATSEffect();
    void SetHair(TESHair*);
    void SetEyes(TESEyes*);
    void SetHairLength(float);
    void ResetFaceGen();
    void Reset3DForLoadedActors(unsigned char);
    FaceGenMatrix<float> (*GetOffsetFaceCoord())[2];
    void RefreshActorAppearance(Actor*);
    void LoadFaceGen(Actor*);
    TESRace* TESNPC_GetRace();
    int GetSex();
    SEX GetSex(bool);
    void AutoCalcStats(bool);
    void InitWornForm(Actor*, ValidBip01Names*, bool);
    int FUN_005f0cc0();
    BSSimpleList<const char*>* GetModelFiles(bool, bool);
    void SwapEyes(TESEyes*);
    void InitDefaultWorn(Actor*, bool, bool, bool, bool);
    void InitDefaultWorn(TESObjectREFR*, bool, bool, bool, bool);
    TESClass* GetClass();
    TESNPC* GetCopyFrom();
    void SetClass(TESClass*);
    int GetActorSex();
    TESRace* GetRaceData();
    FaceGenMatrix<float> (*GetMorphData())[2];
    void SetMorphData(FaceGenMatrix<float> (*)[2]);
    void* GetFaceGen();
    void MarkModified(unsigned int);

    // The biped component view overlaps inherited storage at 0xE0.
    __forceinline BGSBipedModelList& GetBipedModelListComponent()
    {
        return *reinterpret_cast<BGSBipedModelList*>(
            reinterpret_cast<unsigned char*>(&data) - 0x34);
    }
    __declspec(property(get=GetBipedModelListComponent)) BGSBipedModelList& biped;

    struct Data
    { // TESNPC::Data is a distinct nested 28-byte skill values/offsets record, not the global ::Data.
        unsigned char ucSkillValues[14];
        unsigned char ucSkillOffsets[14];
    };

    union
    {
        ActorSkillData data;
        Data kData;
    };
    TESClass* m_pClass;
    FaceGenMatrix<float> m_kFaceGenCoordinates[2][2];
    FaceGenMatrix<float> (*m_pOffsetFaceCoordinates)[2];
    TESHair* m_pHair;
    float m_fHairLength;
    TESEyes* m_pEyes;
    NiPointer<BSFaceGenNiNode> m_pkPrimaryFaceGenNode;
    NiPointer<BSFaceGenNiNode> m_pkSecondaryFaceGenNode;
    NiPointer<NiTexture> m_pkFaceGenTexture;
    unsigned short m_usLastRace;
    unsigned short lastRacePadding;
    TESCombatStyle* m_pCombatStyle;
    unsigned int iHairColor;
    BSSimpleList<BGSHeadPart*> m_kHeadPartList;
    int m_eImpactMaterial;
    unsigned int m_ulTopicFlags;
    TESRace* m_pAssignedRace;
    TESNPC* m_pTemplateNPC;
    float m_fGlyphExtent;
    float fWeight;
    BSSimpleArray<FaceGenUndo*, 1024> undoStates;
};

