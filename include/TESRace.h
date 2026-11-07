#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESDescription.h"
#include "TESSpellList.h"
#include "TESReactionForm.h"
#include "RaceDefinitionData.h"
#include "TESAttributes.h"
#include "TESModel.h"
#include "TESTexture.h"
#include "BGSTextureModel.h"
#include "NiTPrimitiveArray.h"
#include "FaceGenMatrix.h"

template <class T> class NiPointer;

class NiTexture;

class TESHair;
class TESEyes;
class TESNPC;
class BGSVoiceType;
class BSFaceGenNiNode;
class FaceGenUndo;

enum SEX;
enum BIPED_OBJECT;

class TESRace : public TESForm, public TESFullName, public TESDescription, public TESSpellList, public TESReactionForm
{
public:
    TESRace();
    virtual ~TESRace();
    virtual void InitItem();

    void* Destroy(unsigned int flags);
    void SetBodyModelPath(int sex, int part, const char* path);
    void SetHeadModelPath(int sex, int part, const char* path);
    void SetBodyTextureModelPath(int sex, const char* path);
    void ResetFormData();
    void ClearFaceGenUndo();
    TESModel* GetHeadPartModel(SEX sex, int part);
    bool GetBipedObjectModelPath(TESNPC* npc, BIPED_OBJECT part, char* path);
    TESModel* GetBipedObjectModel(SEX sex, BIPED_OBJECT part);
    TESModel* GetBodyPartModel(SEX sex, int part);
    TESModel* GetHeadPartModel_00613970(int sex, int part);
    TESModel* GetBodyPartModel_00613a20(int sex, int part);
    TESTexture* GetBodyPartTexture(int sex, int part);
    TESTexture* GetBodyPartTexture(unsigned int sex, unsigned int part);
    TESTexture* GetBodyPartTexture(int sex, unsigned int part);
    void BuildBodyTexturePath(TESNPC* npc, char* path);
    void SetDefaultHairColor(SEX sex, unsigned char color);
    void SetDefaultVoiceType(SEX sex, BGSVoiceType* voice);
    BGSTextureModel* GetBodyTextureModel(int sex);
    FaceGenMatrix<float> (*GetMeanFaceCoord(SEX sex))[2];
    bool BuildBodyModTexturePath(TESNPC* npc, char* path, char* texturePath);
    bool GetSkinTextures(NiPointer<NiTexture>& texture, NiPointer<NiTexture>& normalMap, TESNPC* npc, BIPED_OBJECT part, bool firstPerson);
    float GetHeight(SEX sex);
    float GetWeight(SEX sex);
    bool BuildFaceGenHead(BSFaceGenNiNode*& head, BSFaceGenNiNode*& hair, TESNPC* npc, bool arg3, bool arg4, SEX sex);
    TESEyes* GetReferencedValue();
    TESHair* TESRace_GetDefaultHair(SEX sex);
    TESHair* TESRace_GetDefaultHair(int sex);
    unsigned short GetFaceCoordNum_00607350();
    TESForm* __thiscall AudioMarker_GetMediaLocationController();

    RaceDefinitionData Data;
    TESAttributes m_kMaleAttributes;
    TESAttributes m_kFemaleAttributes;
    BSSimpleList<TESHair*> m_kHairList;
    TESHair* m_apDefaultHairStyles[2];
    unsigned char m_acDefaultHairColors[2];
    unsigned char unk9E[2];
    float m_fFaceGenMainClamp;
    float m_fFaceGenFaceClamp;
    BSSimpleList<TESEyes*> m_kEyeList;
    TESModel m_kBodyPartModels[2][8];
    TESTexture m_kBodyPartTextures[2][8];
    TESTexture m_kHeadPartTextures[2][3];
    TESModel m_kHeadPartModels[2][3];
    BGSTextureModel m_kFaceGenTextureModels[2];
    FaceGenMatrix<float> m_kFirstFloatPairBySex[2][2];
    FaceGenMatrix<float> m_kSecondFloatPairBySex[2][2];
    unsigned short m_usRaceAttribute;
    unsigned char unk4FA[2];
    BGSVoiceType* m_apDefaultVoiceTypes[2];
    TESRace* m_pOlderRace;
    TESRace* m_pYoungerRace;
    BSStringT<char> strEditorID;
    NiTPrimitiveArray<FaceGenUndo*> m_kFaceGenUndoList;
};

