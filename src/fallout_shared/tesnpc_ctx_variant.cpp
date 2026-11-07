
// tesnpc_ctx_variant.cpp: context variant of src/fallout_shared/tesnpc.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "../../include/Actor.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESRaceForm.h"
#include "../../include/ActorSkillData.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/SEX.h"
#include "../../include/TESModel.h"
#include "../../include/TESNPC.h"
#include "../../include/TESRace.h"
#include "../../include/TESHair.h"
#include "../../include/TESEyes.h"
#include "../../include/NiNode.h"
#include "../../include/MiddleHighProcess.h"
#include "../../include/NiTimeController.h"
#include "../../include/NiControllerManager.h"

class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
class ActorAnimData
{
public:
    NiControllerManager* GetControllerManager_00496940();
};
// The shared FaceGenMatrix omits the checked row-element accessor (0x0060b370).
// This method-only adapter retains that API without duplicating matrix storage.
struct FaceGenCoordinateValue
{
    float* value;
    unsigned int offset;
    const float* NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt();
};
class FaceGenCoordinateBasis
{
public:
    FaceGenCoordinateValue ForwardCall_0060b370(unsigned int, unsigned int);
};

class Helper009f8770
{
  public:
    void TESForm_LoadGameDataOLD(void* apDst, int aiSize);
};
class FUN_00484d40_Host
{
  public:
    void TESForm_LoadNumericID(unsigned int* apFormID, int aiSize);
};
class FUN_009611e0_shell
{
  public:
    int NiAVObject_GetParent();
};
class FUN_006141f0_shell
{
  public:
    void BuildAppearance(TESActorBase* apBase, void* apData, SEX aeSex, bool abFlag);
};
class FUN_004eaf60_shell
{
  public:
    bool PlayerCharacter_Is3rdPerson();
};
class FUN_0043c610_shell
{
  public:
    void RunVirtualMethod28();
};
class GlobalObject_0040c150
{
  public:
    const char* FUN_00403df0();
};
extern GlobalObject_0040c150 g_011d2b38, g_011d2718, g_011d3e44;
extern bool DAT_011c5cb4;
int __fastcall Character_GetBiped(char* apRef);
TESForm* TESForm_GetFormByNumericID(unsigned int auiFormID);
void FNV_Warning(const char* apFormat, ...);
void __cdecl RecurseAndRemoveObjectsFromPalette(NiNode* apNode, NiControllerManager* apManager);
void __cdecl ApplyFaceGenTextures(NiNode* apNode, void* apData);
class FaceRefr
{
  public:
    void TESObjectREFR_Set3D(NiNode* apNode, bool abQueue);
    NiNode* Actor_Load3D(bool abFlag);
};
class PlayerFace
{
  public:
    void PlayerCharacter_SetFirstPerson(bool abFlag);
    void PlayerCharacter_Setup3rdPerson3D(NiNode* apNode, bool abFlag);
};
class FUN_005dd590
{
  public:
    int data[0x3c];
    FUN_005dd590();
    ~FUN_005dd590();
};
class FaceGenPaletteEntry
{
  public:
    int data[0xe];
    ~FaceGenPaletteEntry();
};
class QHeadLocal : public FaceGenPaletteEntry
{
  public:
    QHeadLocal(TESNPC* apNPC, int aiFlag);
    void QueuedHead_Run();
    void QueuedHead_Attach(Actor* apActor, int aiValue);
};



// @fnv 0x00609f60
// src: XBOX_PDB 0x00609f60
void TESNPC::LoadFaceGen(Actor* apActor)
{
    bool bChanged = false;
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            unsigned int uiNumRows = m_kFaceGenCoordinates[i][j].NiAVObject_GetParent();
            unsigned int uiNumCols = m_kFaceGenCoordinates[i][j].FUN_00441110();
            for (unsigned int r = 0; r < uiNumRows; r++)
            {
                for (unsigned int c = 0; c < uiNumCols; c++)
                {
                    float fValue;
                    ((Helper009f8770*)this)->TESForm_LoadGameDataOLD(&fValue, 4);
                    if (*((FaceGenCoordinateBasis*)&m_kFaceGenCoordinates[i][j])->ForwardCall_0060b370(r, c).NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt() != fValue)
                    {
                        *(float*)((FaceGenCoordinateBasis*)&m_kFaceGenCoordinates[i][j])->ForwardCall_0060b370(r, c).NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt() = fValue;
                        bChanged = true;
                    }
                }
            }
        }
    }
    bool bPrevHadRace = false;
    if (TESNPC_GetRace())
        bPrevHadRace = false;
    else
        FNV_Warning("MODELS: %s has a bad current race when loading facegen", TESFullName::GetFullName());
    unsigned int uiNewRace;
    ((FUN_00484d40_Host*)this)->TESForm_LoadNumericID(&uiNewRace, 4);
    TESRace* pRace = dynamic_cast<TESRace*>(TESForm_GetFormByNumericID(uiNewRace));
    if (uiNewRace && !pRace)
        FNV_Warning("MODELS: NPC %s could not find race %08X", TESFullName::GetFullName(), uiNewRace);
    if (GetFormRace() != pRace)
        bChanged = true;
    SetFormRace(pRace);
    bool bNowHasRace = false;
    if (TESNPC_GetRace())
        bNowHasRace = false;
    else
        FNV_Warning("MODELS: %s has a bad new race when loading facegen", TESFullName::GetFullName());
    unsigned int uiNewHairFormID;
    ((FUN_00484d40_Host*)this)->TESForm_LoadNumericID(&uiNewHairFormID, 4);
    TESHair* pReadHair = dynamic_cast<TESHair*>(TESForm_GetFormByNumericID(uiNewHairFormID));
    if (uiNewHairFormID && !pReadHair)
        FNV_Warning("MODELS: NPC %s could not find hair %08X", TESFullName::GetFullName(), uiNewHairFormID);
    if (m_pHair != pReadHair)
        bChanged = true;
    m_pHair = pReadHair;
    unsigned int uiEyes;
    ((FUN_00484d40_Host*)this)->TESForm_LoadNumericID(&uiEyes, 4);
    TESEyes* pCurEyeForm = dynamic_cast<TESEyes*>(TESForm_GetFormByNumericID(uiEyes));
    if (uiEyes && !pCurEyeForm)
        FNV_Warning("MODELS: NPC %s could not find eyes %08X", TESFullName::GetFullName(), uiEyes);
    if (m_pEyes != pCurEyeForm)
        bChanged = true;
    m_pEyes = pCurEyeForm;
    float fScaleMultiplier;
    ((Helper009f8770*)this)->TESForm_LoadGameDataOLD(&fScaleMultiplier, 4);
    unsigned int uiCurHairColor;
    ((Helper009f8770*)this)->TESForm_LoadGameDataOLD(&uiCurHairColor, 4);
    if (m_fHairLength != fScaleMultiplier || iHairColor != uiCurHairColor)
        bChanged = true;
    m_fHairLength = fScaleMultiplier;
    iHairColor = uiCurHairColor;
    bool bLoadedFemale;
    ((Helper009f8770*)this)->TESForm_LoadGameDataOLD(&bLoadedFemale, 1);
    if (TESActorBaseData::GetFlag(1) != bLoadedFemale)
        bChanged = true;
    TESActorBaseData::UpdateFlagBit(1, bLoadedFemale, true);
    if (bChanged)
    {
        NiAVObject* p3D = apActor->TESObjectREFR::Get3DSimple();
        NiNode* pNode = 0;
        if (p3D)
            pNode = p3D->IsSceneNode();
        if (bPrevHadRace == bNowHasRace)
        {
            if (pNode)
            {
                NiControllerManager* pAnimManager = 0;
                if (apActor->Actor_GetAnimation() &&
                    ((ActorAnimData*)apActor->Actor_GetAnimation())->GetControllerManager_00496940())
                    pAnimManager = (NiControllerManager*)((ActorAnimData*)apActor->Actor_GetAnimation())
                                       ->GetControllerManager_00496940()
                                       ->GetStringAtOffset();
                NiControllerManager* pkManager = pAnimManager;
                // TESObjectREFR slots 0x1B0 and 0x1AC return the face and head roots.
                NiNode* pFace = (NiNode*)apActor->vfn_1b0(false);
                if (pFace && ((FUN_009611e0_shell*)pFace)->NiAVObject_GetParent())
                {
                    RecurseAndRemoveObjectsFromPalette(pFace, pkManager);
                    ((NiNode*)((FUN_009611e0_shell*)pFace)->NiAVObject_GetParent())->RemoveObject(pFace);
                }
                pFace = (NiNode*)apActor->vfn_1ac(false);
                if (pFace && ((FUN_009611e0_shell*)pFace)->NiAVObject_GetParent())
                {
                    RecurseAndRemoveObjectsFromPalette(pFace, pkManager);
                    ((NiNode*)((FUN_009611e0_shell*)pFace)->NiAVObject_GetParent())->RemoveObject(pFace);
                }
            }
            ResetFaceGen();
            if (Character_GetBiped((char*)apActor))
                UpdateBodyModel(apActor, (BipedAnim*)Character_GetBiped((char*)apActor));
            if ((NiNode*)apActor->vfn_1ac(false) && (NiNode*)apActor->vfn_1b0(false))
            {
                FUN_005dd590 kData;
                ((FUN_006141f0_shell*)GetFormRace())->BuildAppearance(this, &kData, SEX_SEX_MALE, false);
                ApplyFaceGenTextures((NiNode*)apActor->vfn_1ac(false), &kData);
                ApplyFaceGenTextures((NiNode*)apActor->vfn_1b0(false), &kData);
            }
        }
        else
        {
            NiNode* pParent = 0;
            ResetFaceGen();
            bool bWasFirstPerson = ((FUN_004eaf60_shell*)g_thePlayer)->PlayerCharacter_Is3rdPerson();
            ((PlayerFace*)g_thePlayer)->PlayerCharacter_SetFirstPerson(false);
            if (pNode && bPrevHadRace != bNowHasRace)
            {
                pParent = (NiNode*)((FUN_009611e0_shell*)apActor->TESObjectREFR::Get3DSimple())->NiAVObject_GetParent();
                ((FaceRefr*)apActor)->TESObjectREFR_Set3D(0, true);
            }
            if (bNowHasRace)
                SetModelFilePath(g_011d2b38.FUN_00403df0());
            else if (TESActorBase::GetSex() == SEX_SEX_FEMALE)
                SetModelFilePath(g_011d2718.FUN_00403df0());
            else
                SetModelFilePath(g_011d3e44.FUN_00403df0());
            if (pParent)
            {
                DAT_011c5cb4 = true;
                NiNode* pNew3D = ((FaceRefr*)apActor)->Actor_Load3D(false);
                if (!(NiNode*)apActor->vfn_1b0(false) && !(NiNode*)apActor->vfn_1ac(false))
                {
                    TESNPC* m_pActorBaseFormItem = (TESNPC*)apActor->GetActorBase();
                    QHeadLocal kHead(m_pActorBaseFormItem, 0);
                    kHead.QueuedHead_Run();
                    ((FUN_0043c610_shell*)&kHead)->RunVirtualMethod28();
                    kHead.QueuedHead_Attach(apActor, Character_GetBiped((char*)apActor));
                }
                pParent->AttachChildInAvailableSlot((NiAVObject*)pNew3D, true);
                DAT_011c5cb4 = false;
                if (apActor == (Actor*)g_thePlayer)
                    ((PlayerFace*)g_thePlayer)->PlayerCharacter_Setup3rdPerson3D(pNew3D, false);
                apActor->AnimateNiNode();
                MiddleHighProcess* pProcess = dynamic_cast<MiddleHighProcess*>(apActor->GetProcess());
                if (pProcess)
                    pProcess->ApplyProcessLevelChange(apActor);
            }
            ((PlayerFace*)g_thePlayer)->PlayerCharacter_SetFirstPerson(!bWasFirstPerson);
        }
    }
}

struct ElemT;
// The runtime controller subtype provides slot 63; NiTimeController itself
// does not declare this extension.
typedef void (__thiscall *SetControllerData)(NiTimeController*, int, void*);
struct ElemRet;
struct ListT
{
    virtual void y00();
    virtual void y01();
    virtual void y02();
    virtual void y03();
    virtual void y04();
    virtual void y05();
    virtual void y06();
    virtual void y07();
    virtual void y08();
    virtual void y09();
    virtual void y10();
    virtual void y11();
    virtual void y12();
    virtual void y13();
    virtual void y14();
    virtual void y15();
    virtual void y16();
    virtual void y17();
    virtual void y18();
    virtual void y19();
    virtual void y20();
    virtual void y21();
    virtual void y22();
    virtual void y23();
    virtual void y24();
    virtual void y25();
    virtual void y26();
    virtual void y27();
    virtual void y28();
    virtual void y29();
    virtual void y30();
    virtual void y31();
    virtual void y32();
    virtual void y33();
    virtual void y34();
    virtual void y35();
    virtual void y36();
    virtual void y37();
    virtual void y38();
    virtual ElemT* v39(const NiFixedString&);
    unsigned int FUN_0043b480();
    ElemT* FUN_0043b4a0(unsigned int);
    NiObjectNET* FUN_0050d100();
    int FUN_00a59d30(int);
    void NiAVObject_RemoveProperty(int);
    void NiAVObject_AttachProperty(void*);
};
struct PartT;
struct ElemT
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual PartT* v7();
    NiFixedString& GetName();
};
struct FUN_00633c90
{
    FUN_00633c90(int);
    ~FUN_00633c90();
    ListT* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(PartT*);
    int f0;
};
struct FUN_004037b0
{
    FUN_004037b0();
    ~FUN_004037b0();
    void* Modelloader_GetReferencedThis();
    int f0;
    int f4;
};
#include "../../include/NiMemObject.h"
// NiMemObject's operator delete (0x00aa1460) takes the size; the shared header also declares a one-argument form.
struct FUN_00a6aa40 : NiMemObject
{
    static void operator delete(void*, unsigned int);
    FUN_00a6aa40();
    void SetBaseTexture(void*);
    void FUN_004f3200(int);
    void FUN_0060aeb0(int);
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
};
struct MgrT
{
    void FUN_004568c0(void*, FUN_00633c90*, int, int);
};
extern MgrT* DAT_011dea10;
extern char DAT_0104aac0;
extern char DAT_0104aab0;
extern char DAT_0104aa80;
extern char DAT_0104a64c;
int __cdecl BSstrcmp(char const*, char const*);
void __cdecl BSStringT_char_SPrintF(void*, const char*, ...);
void __cdecl FUN_00b57e30(void*, int, int);
// @fnv 0x0060a950
// src: XBOX_PDB 0x0060a950
void TESNPC::SwapEyes(TESEyes* param)
{
    FUN_00633c90 a(0);
    FUN_00633c90 eye(0);
    ElemT* cur;
    if (((FUN_00633c90*)&m_pkPrimaryFaceGenNode)->Modelloader_GetReferencedThis())
    {
        long count;
        count = ((FUN_00633c90*)&m_pkPrimaryFaceGenNode)->Modelloader_GetReferencedThis()->FUN_0043b480();
        unsigned int ptr;
        for (ptr = 0; ptr < count; ptr++)
        {
            cur = ((FUN_00633c90*)&m_pkPrimaryFaceGenNode)->Modelloader_GetReferencedThis()->FUN_0043b4a0(ptr);
            if (BSstrcmp((const char*)cur->GetName(), &DAT_0104aac0) == 0)
                a.FUN_0066b0d0(cur->v7());
            if (BSstrcmp((const char*)cur->GetName(), &DAT_0104aab0) == 0)
                eye.FUN_0066b0d0(cur->v7());
        }
        if (a.Modelloader_GetReferencedThis() && eye.Modelloader_GetReferencedThis())
        {
            FUN_004037b0 p40;
            if (param)
                BSStringT_char_SPrintF(&p40, &DAT_0104a64c, param->TESTexture::GetTextureResourceName());
            else
                BSStringT_char_SPrintF(&p40, &DAT_0104aa80);
            FUN_00633c90 c(0);
            DAT_011dea10->FUN_004568c0(p40.Modelloader_GetReferencedThis(), &c, 0, 0);
            if (c.Modelloader_GetReferencedThis())
            {
                NiObjectNET* x;
                x = a.Modelloader_GetReferencedThis()->FUN_0050d100();
                NiObjectNET* x2;
                x2 = eye.Modelloader_GetReferencedThis()->FUN_0050d100();
                if (x && x2)
                {
                    NiTimeController* b3;
                    b3 = x->GetControllers();
                    (!b3 ? 0 : ((int)b3->FUN_00441110() >= 8 && (int)b3->FUN_00441110() <= 12));
                    NiTimeController* nw;
                    nw = (!b3 ? 0 : ((int)b3->FUN_00441110() >= 8 && (int)b3->FUN_00441110() <= 12)) ? b3 : 0;
                    NiTimeController* m40;
                    m40 = x2->GetControllers();
                    NiTimeController* found;
                    found = (!m40 ? 0 : ((int)m40->FUN_00441110() >= 8 && (int)m40->FUN_00441110() <= 12)) ? m40 : 0;
                    if (nw && found)
                    {
                        (*reinterpret_cast<SetControllerData**>(nw))[63](nw, 0, c.Modelloader_GetReferencedThis());
                        (*reinterpret_cast<SetControllerData**>(found))[63](found, 0, c.Modelloader_GetReferencedThis());
                        return;
                    }
                }
                FUN_00a6aa40* p44;
                p44 = new FUN_00a6aa40;
                p44->SetBaseTexture(c.Modelloader_GetReferencedThis());
                p44->FUN_004f3200(3);
                p44->FUN_0060aeb0(2);
                if (a.Modelloader_GetReferencedThis()->FUN_00a59d30(5))
                    a.Modelloader_GetReferencedThis()->NiAVObject_RemoveProperty(5);
                a.Modelloader_GetReferencedThis()->NiAVObject_AttachProperty(p44);
                if (eye.Modelloader_GetReferencedThis()->FUN_00a59d30(5))
                    eye.Modelloader_GetReferencedThis()->NiAVObject_RemoveProperty(5);
                eye.Modelloader_GetReferencedThis()->NiAVObject_AttachProperty(p44);
            }
        }
        cur = ((FUN_00633c90*)&m_pkPrimaryFaceGenNode)->Modelloader_GetReferencedThis()->v39(NiFixedString((const char*)&DAT_0104aac0));
        if (cur)
            FUN_00b57e30(cur, 0, 0);
        cur = ((FUN_00633c90*)&m_pkPrimaryFaceGenNode)->Modelloader_GetReferencedThis()->v39(NiFixedString((const char*)&DAT_0104aab0));
        if (cur)
            FUN_00b57e30(cur, 0, 0);
    }
}
