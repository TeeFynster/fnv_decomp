// fallout_shared/bgscamerashot.cpp: BGSCameraShot (16 functions)

#include "layout_support.h"
#include "../../include/BGSImpactData.h"
#include "../../include/CombatProcedure.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESImageSpaceModifiableForm.h"
#include "../../include/TESModel.h"

#include "../../include/BSAudio.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/NiUpdateData.h"
#include "../../include/NiPoint3.h"

#include "bgscamerashot_decls.h"
#include "../../include/BGSCameraShot.h"
#include "../../include/BGSCameraShot__CAMERA_SHOT_DATA.h"
#include "../../include/TESFile.h"

// @fnv 0x0058bf50
void BGSCameraShot::ResetFormData()
{
    Data.m_eAction = BGSCameraShot__CAM_ACTION_CA_HIT;
    Data.pInputFile = BGSCameraShot__CAM_OBJECT_CO_TARGET;
    Data.m_eAttacker = BGSCameraShot__CAM_OBJECT_CO_ATTACKER;
    Data.m_fTimeMultiplier = 1.0f;
    Data.m_fMinTime = 0.0f;
    Data.m_fTargetPercent = 0.0f;
    Data.iFlags = 3;
    Data.fMaxTime = 0.0f;
    Data.m_fCameraValue1 = 0.0f;
    Data.m_fCameraValue2 = 0.0f;
}

// @fnv 0x0058c550
void BGSCameraShot::InitItem()
{
    if (GetInitialized())
        return;
    TESImageSpaceModifiableForm::InitItem(this);
    if (Data.m_fTimeMultiplier < *reinterpret_cast<const double*>(0x01032980))
    {
        Warning(reinterpret_cast<const char*>(0x01032930), GetName());
        Data.m_fTimeMultiplier = *reinterpret_cast<const float*>(0x0101e2bc);
    }
    SetInitializationState(true);
}

// @fnv 0x009c6ba0
void BGSCameraShot::ResetCameraShot()
{
    ((VATS*)this)->ProcessVATSCommands();
    if (((CameraTargetResetFields*)this)->node)
        ((CameraTargetResetFields*)this)->node->ResetCameraState();
    ((CameraTargetResetFields*)this)->field0c = 0;
    ((CameraTargetResetFields*)this)->node = 0;
    ((CameraTargetResetFields*)this)->f14 = 0.0f;
    ((CameraTargetResetFields*)this)->f18 = 0.0f;
    if (((CameraTargetResetFields*)this)->a)
    {
        ImageSpaceModifierInstance_Stop(((CameraTargetResetFields*)this)->a);
        ((CameraTargetResetFields*)this)->a = 0;
    }
    if (((CameraTargetResetFields*)this)->b)
    {
        ImageSpaceModifierInstance_Stop(((CameraTargetResetFields*)this)->b);
        ((CameraTargetResetFields*)this)->b = 0;
    }
}

// Reads a BGSCameraShot record from a TESFile: validates the form type, then parses EDID, OBND, MODL/MODT, MNAM and DATA chunks into the shot's data.
// @fnv 0x0058c090
bool BGSCameraShot::Load(TESFile* file)
{
    if (((TESFileFormInt*)file)->GetTESForm() != 0x5b)
        return false;
    LoadRecordHeader(file);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x4d414e4d: {
            unsigned int modifier = 0;
            file->GetChunkData(&modifier);
            ((CombatProcedure*)((char*)this + 0x30))->Initialize((CombatController*)modifier);
            break;
        }
        case 0x41544144:
            if (file->GetChunkSize() == 32)
            {
                CameraShotLegacyData legacyData;
                memset(&legacyData, 0, 32);
                ((BGSImpactData*)this)->ReadTypedData(file, &legacyData, 32);
                if (file->IsEndianConversionRequired())
                    legacyData.ProcessState_0058c2e0();
                Data.m_eAction = (BGSCameraShot__CAM_ACTION)legacyData.action;
                Data.pInputFile = (BGSCameraShot__CAM_OBJECT)legacyData.location;
                Data.m_eAttacker = (BGSCameraShot__CAM_OBJECT)legacyData.target;
                Data.iFlags = legacyData.flags;
                Data.m_fMinTime = legacyData.playerMult;
                Data.m_fTimeMultiplier = legacyData.globalMult;
                Data.fMaxTime = legacyData.maxTime;
                Data.m_fCameraValue1 = legacyData.minTime;
            }
            else
            {
                memset(&Data, 0, 40);
                file->GetChunkData(&Data, 40);
                if (file->IsEndianConversionRequired())
                    Data.ProcessState_0058c3c0();
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(int*, EndianSizeTag<3>);

struct FUN_0058c2e0_shell
{
    int field_0x00;
    int field_0x04;
    int field_0x08;
    int field_0x0c;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    void ProcessState_0058c2e0();
};

// Byte-swaps all eight 32-bit fields of the object via BSEndian, in the order 0x10, 0x14, 0x00, 0x04, 0x08, 0x0c, 0x18, 0x1c.
// @fnv 0x0058c2e0
// src: GUESS 0x0058c2e0 (confidence: low)
void FUN_0058c2e0_shell::ProcessState_0058c2e0()
{
    BSEndian(&field_0x10, EndianSizeTag<3>());
    BSEndian(&field_0x14, EndianSizeTag<3>());
    BSEndian(&field_0x00, EndianSizeTag<3>());
    BSEndian(&field_0x04, EndianSizeTag<3>());
    BSEndian(&field_0x08, EndianSizeTag<3>());
    BSEndian(&field_0x0c, EndianSizeTag<3>());
    BSEndian(&field_0x18, EndianSizeTag<3>());
    BSEndian(&field_0x1c, EndianSizeTag<3>());
}

void* __memcpy(void*, const void*, unsigned int);
struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};
// Casts apCopy to BGSCameraShot, returns if it fails, then copies the base form and 0x28 bytes from offset 0x38 into this.
// @fnv 0x0058bfc0
void BGSCameraShot::CopyFrom(const TESForm* apCopy)
{
    BGSCameraShot* pcopy;
    pcopy = dynamic_cast<BGSCameraShot*>(const_cast<TESForm*>(apCopy));
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents((TESForm*)pcopy);
    __memcpy(&Data, &pcopy->Data, 0x28);
}

// @fnv 0x0058d630
// src: XBOX_PDB 0x0058d630
bool BGSCameraShot::IsInitialized()
{
    if (Data.m_eAction == 3)
        return false;
    if (TESModel::GetModelLength() == 0)
        return true;
    if ((NiNode*)m_spPositionNode != 0)
        return true;
    return false;
}

struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm*);
};
int _memcmp(const void*, const void*, unsigned int);
// @fnv 0x0058c020
bool BGSCameraShot::Compare(TESForm* apCompare)
{
    BGSCameraShot* pCameraShot = dynamic_cast<BGSCameraShot*>(apCompare);
    if (!pCameraShot)
        return true;
    if (reinterpret_cast<FUN_005e79a0_t*>(this)->TESForm_CompareAllComponents(pCameraShot))
        return true;
    if (_memcmp(&Data, &pCameraShot->Data, 0x28))
        return true;
    return false;
}

struct FUN_00487450_shell
{
    void FUN_00487450();
};
struct FUN_00485e00_shell
{
    void TESForm___SaveData(int, int);
};
bool __cdecl TESForm_QEndianSwapOnSave();

// The shared class inherits SaveForm but does not declare its override.
class BGSCameraShotRecordWriter : public BGSCameraShot
{
public:
    virtual void SaveForm();
};

// @fnv 0x0058c4d0
void BGSCameraShotRecordWriter::SaveForm()
{
    TESForm::BeginFormRecord();
    ((TESModel*)((char*)this + 0x18))->WriteToBuffer(0x4C444F4D, 0x54444F4D);
    if (TESForm_QEndianSwapOnSave())
        Data.ProcessState_0058c3c0();
    ((FUN_00485e00_shell*)this)->TESForm___SaveData((int)((char*)this + 0x38), 0x28);
    if (TESForm_QEndianSwapOnSave())
        Data.ProcessState_0058c3c0();
    ((FUN_00487450_shell*)((char*)this + 0x30))->FUN_00487450();
    TESForm::FinishFormRecord();
}

// Byte-swaps each of the ten 32-bit fields of the object via BSEndian.
// @fnv 0x0058c3c0
// src: GUESS 0x0058c3c0 (confidence: low)
void BGSCameraShot__CAMERA_SHOT_DATA::ProcessState_0058c3c0()
{
    BSEndian(reinterpret_cast<int*>(&m_fMinTime), EndianSizeTag<3>());
    BSEndian(reinterpret_cast<int*>(&m_fTargetPercent), EndianSizeTag<3>());
    BSEndian(reinterpret_cast<int*>(&m_fTimeMultiplier), EndianSizeTag<3>());
    BSEndian(reinterpret_cast<int*>(&m_eAction), EndianSizeTag<3>());
    BSEndian(reinterpret_cast<int*>(&pInputFile), EndianSizeTag<3>());
    BSEndian(reinterpret_cast<int*>(&m_eAttacker), EndianSizeTag<3>());
    BSEndian(reinterpret_cast<int*>(&iFlags), EndianSizeTag<3>());
    BSEndian(reinterpret_cast<int*>(&fMaxTime), EndianSizeTag<3>());
    BSEndian(reinterpret_cast<int*>(&m_fCameraValue1), EndianSizeTag<3>());
    BSEndian(reinterpret_cast<int*>(&m_fCameraValue2), EndianSizeTag<3>());
}

// @fnv 0x0058be90
BGSCameraShot::~BGSCameraShot()
{
    ((StateNode*)this)->ResetCameraState();
}

// @fnv 0x0058d4f0
bool BGSCameraShot::IsNotFlag4Set()
{
    return (Data.iFlags & 4) == 0 ? true : false;
}

// External helpers not yet declared by the shared camera-shot header.
struct CameraShotAccess
{
    float GetPositionTime();
    bool IsFlag20Set();
    bool IsFlagSet();
};

// Camera position helpers.
extern NiPoint3 NiPoint3_ZERO;
extern float DAT_011ca738, DAT_011ca73c, DAT_011ca740;
struct Rotation
{
    void DecomposeToEulerAngles(float*, float*, float*);
};
struct CameraNode
{
    const NiPoint3& NiAVObject_GetWorldTranslate();
    Rotation* NiAVObject_GetRotate_006a9540();
};
struct NodePointer
{
    CameraNode* Modelloader_GetReferencedThis();
};
struct VATSLocation
{
    NiPoint3 VATS_GetTargetPercentagePos(float);
};
extern VATSLocation DAT_011f2250;
// @fnv 0x0058d510
NiPoint3 BGSCameraShot::GetCameraPosition()
{
    NiPoint3 position = NiPoint3_ZERO;
    if (((CameraShotAccess*)this)->GetPositionTime() > 0.0)
    {
        position = DAT_011f2250.VATS_GetTargetPercentagePos(((CameraShotAccess*)this)->GetPositionTime());
    }
    else if (((NodePointer*)&m_pTargetNode)->Modelloader_GetReferencedThis())
    {
        position = ((NodePointer*)&m_pTargetNode)->Modelloader_GetReferencedThis()->NiAVObject_GetWorldTranslate();
    }
    if (m_bUpdateNodePosition == 1 && ((NodePointer*)&m_spPositionNode)->Modelloader_GetReferencedThis())
    {
        ((NodePointer*)&m_spPositionNode)
            ->Modelloader_GetReferencedThis()
            ->NiAVObject_GetRotate_006a9540()
            ->DecomposeToEulerAngles(&DAT_011ca738, &DAT_011ca73c, &DAT_011ca740);
    }
    else
    {
        DAT_011ca738 = 0.0f;
        DAT_011ca73c = 0.0f;
        DAT_011ca740 = 0.0f;
    }
    return position;
}

// SetupCamera v01 - worker10 one-pass transcription (history draw, fnvrec v1.1)
extern NiPoint3 NiPoint3_ZERO;
extern float DAT_011f21d4;
extern unsigned char DAT_011ca728;
extern unsigned char DAT_011ca729;
extern unsigned char DAT_011e07c3;
extern float DAT_011ca72c;
extern float DAT_011ca730;
extern float DAT_011ca734;
extern NiPoint3 DAT_011ca7a8;
extern NiPoint3 DAT_011ca75c;
extern int DAT_011f4a18;
extern int DAT_011f3714;
extern int DAT_011f3e50;
extern int DAT_011f3e48;

int __cdecl Warning_005b5e40(const char*, const char*);
void* __cdecl NiObject_DynamicCast(void*, void*);
void __cdecl BSUtils_SetPhaseRecurse(void*, float);

struct CamNodeX
{
    void* NiObjectNET_GetController(void*);
    void NiAVObject_Update(void*);
    NiPoint3* GetTranslate_0043c490();
    int NiNode_GetAtChecked(int);
};
struct NodePtrObj
{
    void* m_pObject;
    CamNodeX* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(void*);
};
struct ModelLoader
{
    int ModelLoader_LoadFile(const char*, int, int, int, int, int);
    int ModelLoader_ReleaseFile(const char*);
};
extern ModelLoader* g_modelLoader;
struct LookupObj
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0a();
    virtual void Unk_0b();
    virtual void Unk_0c();
    virtual void Unk_0d();
    virtual void Unk_0e();
    virtual void Unk_0f();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1a();
    virtual void Unk_1b();
    virtual void Unk_1c();
    virtual void Unk_1d();
    virtual void Unk_1e();
    virtual void Unk_1f();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2a();
    virtual void Unk_2b();
    virtual void Unk_2c();
    virtual void Unk_2d();
    virtual void Unk_2e();
    virtual void Unk_2f();
    virtual void Unk_30();
    virtual int vfn_c4(int);
};
struct Lookup2
{
    int NiTransformInterpolator_GetRotData(int*, int*, unsigned char*);
    bool NiPathInterpolator_GetFollow();
};
struct St28
{
    int f00;
    float f04;
    float f08;
    int f0c;
    int f10;
    int f14;
    int f18;
};
struct FoundObj
{
    St28* FUN_0045bbe0();
};
struct Glob79c
{
    float* Setting_Float_00403e20();
};
extern Glob79c DAT_011ca79c;
struct VatsSub
{
    bool EffectSetting_IsFlagSetAny(int);
};
struct VatsState
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    VatsSub* sub14;
};
struct VATSObj
{
    VatsState* VATS_GetCurrentAction();
};
// PlayerObj_bgscamerashot: local type (was include/PlayerObj.h, which had no evidence of one real class); its methods are 0x00567400 TESObjectREFR::GetScale, 0x008aded0 Actor::PlayPickUpSound, 0x0095edf0 PlayerCharacter::Setup3rdPersonCameraCaster
class TESBoundObject;

class PlayerObj_bgscamerashot
{
public:
    void ShowStartMenuMessageOnce();
    void PlayerCharacter_SetIsAMurderer();
    void PlayerCharacter_RewardKarma(int);
    float TESObjectREFR_GetScale_00567400();
    void PlayActorSound(TESBoundObject* o, int a1, int a2);
    void SyncHolderValue();
};
extern PlayerObj_bgscamerashot* DAT_011dea3c;

// Loads the VATS camera model, validates its NiCamera child and FOV, stores param1, and updates camera globals and sounds based on param2 and Data.m_eAction.
// @fnv 0x0058c5d0
void BGSCameraShot::SetupCamera(void* param1, int iMode)
{
    void* myFoundPtr;
    if (TESModel::GetModelLength())
    {
        ((NodePtrObj*)&m_spPositionNode)->FUN_0066b0d0((void*)g_modelLoader->ModelLoader_LoadFile(GetModelFilePath(), 0, 1, 1, 0, 0));
    }
    myFoundPtr = ((NodePtrObj*)&m_spPositionNode)->Modelloader_GetReferencedThis()
                     ? NiObject_DynamicCast(&DAT_011f4a18, (void*)((NodePtrObj*)&m_spPositionNode)->Modelloader_GetReferencedThis()->NiNode_GetAtChecked(0))
                     : 0;
    if (!myFoundPtr)
    {
        Warning_005b5e40(
            "DEFAULT: VATS Camera '%s' doesn't have an NiCamera as the first child. This camera will not be used.",
            GetModelFilePath());
        ((NodePtrObj*)&m_spPositionNode)->FUN_0066b0d0(0);
        g_modelLoader->ModelLoader_ReleaseFile(GetModelFilePath());
    }
    if (((NodePtrObj*)&m_spPositionNode)->Modelloader_GetReferencedThis())
    {
        NiUpdateData auxPtr(DAT_011f21d4, true, false);
        if (((CameraShotAccess*)this)->IsFlag20Set())
        {
            BSUtils_SetPhaseRecurse(((NodePtrObj*)&m_spPositionNode)->Modelloader_GetReferencedThis(), -DAT_011f21d4);
        }
        ((NodePtrObj*)&m_spPositionNode)->Modelloader_GetReferencedThis()->NiAVObject_Update(&auxPtr);
        if ((signed char)m_bUpdateNodePosition == -1 && !m_bFlag75)
        {
            void* queriedVal = ((NodePtrObj*)&m_spPositionNode)->Modelloader_GetReferencedThis()->NiObjectNET_GetController(&DAT_011f3714);
            if (queriedVal)
            {
                void* clonePtr = queriedVal;
                int held2 = ((LookupObj*)clonePtr)->vfn_c4(0);
                void* altObj2Val = NiObject_DynamicCast(&DAT_011f3e50, (void*)held2);
                void* myAltPtr = 0;
                if (altObj2Val)
                {
                    int resA;
                    int chkBPtr;
                    unsigned char flagCX;
                    int answer = ((Lookup2*)altObj2Val)->NiTransformInterpolator_GetRotData(&resA, &chkBPtr, &flagCX);
                    (void)answer;
                    if (resA)
                    {
                        m_bUpdateNodePosition = 1;
                    }
                }
                else
                {
                    myAltPtr = NiObject_DynamicCast(&DAT_011f3e48, (void*)held2);
                }
                if (myAltPtr && ((Lookup2*)myAltPtr)->NiPathInterpolator_GetFollow())
                {
                    m_bUpdateNodePosition = 1;
                }
                if ((signed char)m_bUpdateNodePosition == -1)
                {
                    m_bUpdateNodePosition = 0;
                }
            }
        }
        if (((NodePtrObj*)&m_spPositionNode)->Modelloader_GetReferencedThis()->GetTranslate_0043c490()->HasEqualComponents(NiPoint3_ZERO))
        {
            Warning_005b5e40("DEFAULT: VATS Camera '%s' doesn't have any position data.", GetModelFilePath());
        }
        St28 attrs2;
        attrs2 = *((FoundObj*)myFoundPtr)->FUN_0045bbe0();
        if (attrs2.f08 / attrs2.f04 < (double)0.74f)
        {
            Warning_005b5e40("DEFAULT: VATS Camera '%s' has a bad FOV that was not created for a 4x3 aspect ratio.",
                         GetModelFilePath());
        }
    }
    m_pReference = (TESObjectREFR*)param1;
    DAT_011e07c3 = 1;
    switch (iMode)
    {
    case 0:
        DAT_011ca728 = 1;
        DAT_011ca734 = *DAT_011ca79c.Setting_Float_00403e20();
        break;
    case 1:
        DAT_011ca728 = 0;
        break;
    case 2:
        if (Data.m_eAction == 3)
        {
            DAT_011ca728 = 1;
            if (Data.m_fCameraValue1 > 0.0f)
            {
                DAT_011ca734 = Data.m_fCameraValue1;
            }
            else
            {
                DAT_011ca734 = *DAT_011ca79c.Setting_Float_00403e20();
            }
        }
        break;
    }
    DAT_011ca72c = 0.0f;
    DAT_011ca730 = 0.0f;
    DAT_011ca7a8 = NiPoint3_ZERO;
    DAT_011ca75c = NiPoint3_ZERO;
    VatsState* vatsPtr2 = ((VATSObj*)&DAT_011f2250)->VATS_GetCurrentAction();
    if (vatsPtr2 && !DAT_011ca729 &&
        (vatsPtr2->sub14->EffectSetting_IsFlagSetAny(4) || vatsPtr2->sub14->EffectSetting_IsFlagSetAny(8) || vatsPtr2->sub14->EffectSetting_IsFlagSetAny(0x10)))
    {
        if (Data.m_eAction == 2)
        {
            DAT_011ca729 = 1;
            BSSoundHandle camIn2 = BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByEditorName("UIVATSCameraIn", 0x121);
            camIn2.Play(false);
        }
    }
    else
    {
        if (DAT_011ca729 && Data.m_eAction != 2)
        {
            DAT_011ca729 = 0;
            BSSoundHandle bannerOutPtr = BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByEditorName("UIVATSCameraOut", 0x121);
            bannerOutPtr.Play(false);
        }
    }
    DAT_011dea3c->SyncHolderValue();
}

struct M3
{
    float m[9];
};
struct Frus
{
    float left;
    float right;
    float top;
    float bottom;
    float nearPlane;
    float farPlane;
    bool orthographic;
};
struct Host56
{
    M3 TESObjectREFR_GetOrientation();
};
struct Rot56
{
};
struct Node60
{
    const NiPoint3& NiAVObject_GetWorldTranslate();
    Host56* NiAVObject_GetRotate_006a9540();
};
struct Prop
{
    const Frus& FUN_0045bbe0();
};
struct Anim
{
    const Frus& FUN_0045bbe0();
    void FUN_00a6faf0(Frus*);
};
struct MidX
{
    Anim* FUN_006629f0();
};
struct Node6c
{
    void NiAVObject_Update(const NiUpdateData&);
    const NiPoint3& GetTranslate_0043c490();
    Prop* NiNode_GetAtChecked(int);
};
struct NiPtr60
{
    Node60* object;
    Node60* Modelloader_GetReferencedThis();
};
struct NiPtr6c
{
    Node6c* object;
    Node6c* Modelloader_GetReferencedThis();
};
struct Rend
{
    unsigned int FUN_004dee10();
    unsigned int FUN_004dee70();
};
Rend* __cdecl NiXenonRenderer_GetRenderer();
MidX* __cdecl Main_GetWorldSceneGraph();
struct GObj
{
    virtual void w000();
    virtual void w001();
    virtual void w002();
    virtual void w003();
    virtual void w004();
    virtual void w005();
    virtual void w006();
    virtual void w007();
    virtual void w008();
    virtual void w009();
    virtual void w010();
    virtual void w011();
    virtual void w012();
    virtual void w013();
    virtual void w014();
    virtual void w015();
    virtual void w016();
    virtual void w017();
    virtual void w018();
    virtual void w019();
    virtual void w020();
    virtual void w021();
    virtual void w022();
    virtual void w023();
    virtual void w024();
    virtual void w025();
    virtual void w026();
    virtual void w027();
    virtual void w028();
    virtual void w029();
    virtual void w030();
    virtual void w031();
    virtual void w032();
    virtual void w033();
    virtual void w034();
    virtual void w035();
    virtual void w036();
    virtual void w037();
    virtual void w038();
    virtual void w039();
    virtual void w040();
    virtual void w041();
    virtual void w042();
    virtual void w043();
    virtual void w044();
    virtual void w045();
    virtual void w046();
    virtual void w047();
    virtual void w048();
    virtual void w049();
    virtual void w050();
    virtual void w051();
    virtual void w052();
    virtual void w053();
    virtual void w054();
    virtual void w055();
    virtual void w056();
    virtual void w057();
    virtual void w058();
    virtual void w059();
    virtual void w060();
    virtual void w061();
    virtual void w062();
    virtual void w063();
    virtual void w064();
    virtual void w065();
    virtual void w066();
    virtual void w067();
    virtual void w068();
    virtual void w069();
    virtual void w070();
    virtual void w071();
    virtual void w072();
    virtual void w073();
    virtual void w074();
    virtual void w075();
    virtual void w076();
    virtual void w077();
    virtual void w078();
    virtual void w079();
    virtual void w080();
    virtual void w081();
    virtual void w082();
    virtual void w083();
    virtual void w084();
    virtual void w085();
    virtual void w086();
    virtual void w087();
    virtual void w088();
    virtual void w089();
    virtual void w090();
    virtual void w091();
    virtual void w092();
    virtual void w093();
    virtual void w094();
    virtual void w095();
    virtual void w096();
    virtual void w097();
    virtual void w098();
    virtual void w099();
    virtual void w100();
    virtual void w101();
    virtual void w102();
    virtual void w103();
    virtual void w104();
    virtual void w105();
    virtual void w106();
    virtual void w107();
    virtual void w108();
    virtual void w109();
    virtual void w110();
    virtual void w111();
    virtual void w112();
    virtual void w113();
    virtual void w114();
    virtual void w115();
    virtual void w116();
    virtual void w117();
    virtual void w118();
    virtual void w119();
    virtual void w120();
    virtual void w121();
    virtual void w122();
    virtual void w123();
    virtual void w124();
    virtual void w125();
    virtual void w126();
    virtual void w127();
    virtual void w128();
    virtual void w129();
    virtual void w130();
    virtual void w131();
    virtual void w132();
    virtual void w133();
    virtual void w134();
    virtual void w135();
    virtual void w136();
    virtual void w137();
    virtual void w138();
    virtual bool Check22c(int);
    void PlayerCharacter_SetFirstPerson(int);
    void PlayerCharacter_UpdateChaseCamera(NiPoint3*, NiPoint3*, int);
};
float* __fastcall Setting_Float_00403e20(void*);
void __cdecl NiMatrix3_TransformVertices(const M3&, void*, int, NiPoint3&, NiPoint3&);
void __cdecl NiMatrix3_TransformVertices(Host56*, void*, int, NiPoint3&, NiPoint3&);
extern NiPoint3 DAT_011ca77c;
extern NiPoint3 DAT_011ca75c;
extern NiPoint3 DAT_011e0808;
extern NiPoint3 DAT_011ca7a8;
extern NiPoint3 DAT_011f426c;
extern float DAT_011ca72c;
extern float DAT_011ca730;
extern float DAT_011ca734;
extern unsigned char DAT_011ca728;
extern unsigned char DAT_011ca729;
extern Host56* DAT_011f21f0;
extern float DAT_011ca76c;
extern float DAT_011ca7d0;
// Updates the camera node with NiUpdateData, adjusts its position and frustum, and tracks camera-in transition progress.
// @fnv 0x0058cf60
void BGSCameraShot::UpdateCamera(float afTime)
{
    if (!((NiPtr6c*)&m_spPositionNode)->Modelloader_GetReferencedThis())
        return;
    NiUpdateData upd(afTime, true, false);
    ((NiPtr6c*)&m_spPositionNode)->Modelloader_GetReferencedThis()->NiAVObject_Update(upd);
    DAT_011ca77c = ((NiPtr6c*)&m_spPositionNode)->Modelloader_GetReferencedThis()->GetTranslate_0043c490();
    NiPoint3 pt = DAT_011ca77c;
    if (m_bFlag74 && !reinterpret_cast<GObj*>(DAT_011dea3c)->Check22c(0))
        reinterpret_cast<GObj*>(DAT_011dea3c)->PlayerCharacter_SetFirstPerson(1);
    else
    {
        if (((CameraShotAccess*)this)->IsFlagSet())
        {
            if (!IsNotFlag4Set() || ((Host56*)m_pReference) == 0 || Data.pInputFile != 2)
            {
                NiPoint3 tmpA = pt;
                NiMatrix3_TransformVertices(DAT_011f21f0->TESObjectREFR_GetOrientation(), &DAT_011f426c, 1, tmpA, pt);
            }
            else
            {
                NiPoint3 tmpB = pt;
                NiMatrix3_TransformVertices(((Host56*)m_pReference)->TESObjectREFR_GetOrientation(), &DAT_011f426c, 1, tmpB, pt);
            }
        }
        else if (((NiPtr60*)&m_pLocationNode)->Modelloader_GetReferencedThis())
        {
            NiPoint3 tmpC = pt;
            NiMatrix3_TransformVertices(((NiPtr60*)&m_pLocationNode)->Modelloader_GetReferencedThis()->NiAVObject_GetRotate_006a9540(), &DAT_011f426c, 1, tmpC, pt);
        }
        if (((NiPtr60*)&m_pLocationNode)->Modelloader_GetReferencedThis())
        {
            bool bReset = false;
            if (DAT_011ca75c.HasEqualComponents(DAT_011f426c))
            {
                DAT_011ca75c = DAT_011e0808;
                bReset = true;
            }
            NiPoint3 kPos = ((NiPtr60*)&m_pLocationNode)->Modelloader_GetReferencedThis()->NiAVObject_GetWorldTranslate();
            pt.ComputeValue_0063c8a0(kPos);
            reinterpret_cast<GObj*>(DAT_011dea3c)->PlayerCharacter_UpdateChaseCamera(&pt, &kPos, 0);
            DAT_011e0808 = pt;
            if (DAT_011ca728)
            {
                DAT_011ca7a8 = DAT_011e0808 - DAT_011ca75c;
                if (static_cast<const NiPoint3&>(DAT_011ca7a8).Length() <= *Setting_Float_00403e20(&DAT_011ca76c))
                {
                    DAT_011ca728 = 0;
                    DAT_011ca72c = 0.0f;
                }
                else if (Data.m_eAction == 0)
                {
                    DAT_011ca728 = 0;
                    DAT_011ca72c = 0.0f;
                }
                else
                {
                    if (bReset && !DAT_011ca729)
                    {
                        BSSoundHandle snd = BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByEditorName("UIVATSCameraIn", 0x121);
                        snd.Play(false);
                    }
                    DAT_011ca730 = (1.0f / DAT_011ca734) * (afTime - DAT_011ca72c);
                    if (DAT_011ca730 >= 1.0)
                    {
                        DAT_011ca728 = 0;
                        DAT_011ca72c = 0.0f;
                    }
                    else
                        DAT_011e0808 = DAT_011ca75c + DAT_011ca7a8 * DAT_011ca730;
                }
            }
            Prop* pCam = ((NiPtr6c*)&m_spPositionNode)->Modelloader_GetReferencedThis()->NiNode_GetAtChecked(0);
            if (pCam)
            {
                Frus kOrigFrustum = pCam->FUN_0045bbe0();
                Anim* pMainCamera = Main_GetWorldSceneGraph()->FUN_006629f0();
                Frus kFrustum = pMainCamera->FUN_0045bbe0();
                float scale =
                    (double)NiXenonRenderer_GetRenderer()->FUN_004dee10() / (double)NiXenonRenderer_GetRenderer()->FUN_004dee70() / 1.3333334f;
                kFrustum.left = kOrigFrustum.left * scale;
                kFrustum.right = kOrigFrustum.right * scale;
                kFrustum.top = kOrigFrustum.top;
                kFrustum.bottom = kOrigFrustum.bottom;
                pMainCamera->FUN_00a6faf0(&kFrustum);
            }
        }
    }
    if ((GetCameraPosition() - pt).Length() <= *Setting_Float_00403e20(&DAT_011ca7d0))
        m_bFlag74 = 1;
}
