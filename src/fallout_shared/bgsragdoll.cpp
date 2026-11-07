// fallout_shared/bgsragdoll.cpp: BGSRagdoll (33 functions)

#include "../../include/BSStringT.h"

#include "../../include/BaseFormComponent.h"
#include "../../include/TESForm.h"
#include "../../include/TESModel.h"
#include "../../include/FileEntryList.h"
#include "../../include/SaveMetadata.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/RagdollFeedbackData__RagdollFeedbackSystemData.h"
#include "../../include/RagdollAnimationData.h"
#include "../../include/FootIK_DATA__FootIKSystem_DATA.h"
#include "../../include/FootIK_DATA.h"
#include "../../include/LookIK_DATA.h"
#include "../../include/GrabIK_DATA.h"
#include "../../include/PoseMatching_DATA__PoseMatching_System_DATA.h"
#include "../../include/RagdollFeedbackProfile.h"
#include "../../include/BGSBodyPartData.h"
#include "../../include/BGSRagdoll.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESFile.h"
#include <malloc.h>

// No shared definition is available for this array element.
class FootIK_DATA__FootIK_Leg_DATA
{
  public:
    short m_sFirstLegValue;   // +0x0, 2 bytes
    short m_sSecondLegValue;  // +0x2, 2 bytes
    short m_sThirdLegValue;   // +0x4, 2 bytes
    bool m_bFourthLegValue;   // +0x6, 1 bytes
    unsigned char layoutPadding7[1];
    float ShortBooleanFloatComponents;               // +0x8, 4 bytes
    float BooleanFloatComponentData;                 // +0xC, 4 bytes
    float SixFloatParameterBlock;                    // +0x10, 4 bytes
    float SixFloatAndFloatTripletData;               // +0x14, 4 bytes
    float m_fFourthComponentValue;                   // +0x18, 4 bytes
    float m_fFifthFloatValue;                          // +0x1C, 4 bytes
    float ThreeFloatScalarsAndTwoFloatTriples[3];    // +0x20, 12 bytes
    float TwoFloatAndTwoThreeElementFloatArrays[3];  // +0x2C, 12 bytes
};
// No shared definition is available for this array element.
class LookIK_DATA__LookIK_Head_DATA
{
  public:
    short m_sFirstHeadValue;                      // +0x0, 2 bytes
    short m_sSecondHeadValue;                     // +0x2, 2 bytes
    float ShortPairTwoVectorTwoScalarData[3];     // +0x4, 12 bytes
    float ShortPairTwoVectorThreeScalarData[3];   // +0x10, 12 bytes
    float ShortAndTwoFloatTriplesAndThreeFloats;  // +0x1C, 4 bytes
    float VectorPairScalarData;                   // +0x20, 4 bytes
    float FloatTripleAndThreeFloats;              // +0x24, 4 bytes
};
// No shared definition is available for this array element.
class GrabIK_DATA__GrabIK_Arm_DATA
{
  public:
    short m_sFirstArmValue;   // +0x0, 2 bytes
    short m_sSecondArmValue;  // +0x2, 2 bytes
    short m_sThirdArmValue;   // +0x4, 2 bytes
};

class SandboxProcedureData;
class TESObjectREFR;
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTArray.h"

// The shared data layouts do not yet declare their endian helpers.
void __fastcall SwapRagdollFeedbackEndian(RagdollFeedbackData__RagdollFeedbackSystemData*);
void __fastcall SwapPoseMatchingEndian(PoseMatching_DATA__PoseMatching_System_DATA*);

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);

// This record helper returns the full register value; TESFile::GetTESForm returns a byte.
unsigned int __fastcall GetRagdollRecordType(TESFile* file);

int __cdecl Warning(const char*, ...);
void __cdecl operator delete(void*);

// The shared string header lacks the BSStringT comparison overload at 0x00501c90.
struct RagdollStringOperations : BSStringT<char>
{
    int CompareText(const BSStringT<char>* string, bool ignoreCase);
};

// Shared ragdoll headers lack these copy/compare declarations. These views add no data.
struct RagdollAnimationOperations : RagdollAnimationData
{
    void CopyFrom(const RagdollAnimationOperations&);
    bool Differs(const RagdollAnimationOperations&);
};
struct FootIKOperations : FootIK_DATA
{
    void CopyData(const FootIK_DATA&);
    bool Differs(const FootIK_DATA&);
};
struct LookIKOperations : LookIK_DATA
{
    void CopyData(const LookIK_DATA&);
    bool Differs(const LookIK_DATA&);
};
struct GrabIKOperations : GrabIK_DATA
{
    void CopyData(const GrabIK_DATA&);
    bool Differs(const GrabIK_DATA&);
};
struct RagdollFeedbackOperations : RagdollFeedbackProfile
{
    void CopyData(const RagdollFeedbackProfile&);
    bool Differs(const RagdollFeedbackProfile&);
};
struct RagdollOperations : BGSRagdoll
{
    void CopyData(TESForm*);
    bool Differs(TESForm*);
};

// @fnv 0x005edd00
void BGSRagdoll::ResetFormData()
{
    struct InitLocals
    {
        TESObjectREFR* grabName;
        TESObjectREFR* lookName;
        TESObjectREFR* footName;
        unsigned int grabIndex;
        unsigned int lookIndex;
        unsigned int footIndex;
    } locals;

    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter1 = 0.8f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.fHeirGain = 0.17f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter3 = 0.05f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.fVelGain = 0.6f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter5 = 1.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.fSnapGain = 0.1f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter7 = 0.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter8 = 3.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter9 = 0.3f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter10 = 0.3f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter11 = 3.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter12 = 14.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter13 = 18.0f;

    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)->Clear(true);

    for (locals.footIndex = 0;
         locals.footIndex <
         reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kFootIKData.m_kFootNames)->GetSize();
         ++locals.footIndex)
    {
        locals.footName =
            reinterpret_cast<NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*>(&m_kFootIKData.m_kFootNames)
                ->GetAt(locals.footIndex);
        ::operator delete(locals.footName);
    }
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kFootIKData.m_kLegData)->Clear(true);
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kFootIKData.m_kFootNames)->Clear(true);

    m_kFootIKData.m_kRagdollFeedbackData.fOnOffGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.fGroundAscendingGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.fGroundDescendingGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.fFootRaisedGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.m_fAdditionalFeedbackGain1 = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.m_fAdditionalFeedbackGain2 = 0.0f;

    for (locals.lookIndex = 0;
         locals.lookIndex <
         reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kLookIKData.m_kLookNames)->GetSize();
         ++locals.lookIndex)
    {
        locals.lookName =
            reinterpret_cast<NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*>(&m_kLookIKData.m_kLookNames)
                ->GetAt(locals.lookIndex);
        ::operator delete(locals.lookName);
    }
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kLookIKData.m_kHeadData)->Clear(true);
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kLookIKData.m_kLookNames)->Clear(true);

    for (locals.grabIndex = 0;
         locals.grabIndex <
         reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kGrabIKData.m_kGrabNames)->GetSize();
         ++locals.grabIndex)
    {
        locals.grabName =
            reinterpret_cast<NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*>(&m_kGrabIKData.m_kGrabNames)
                ->GetAt(locals.grabIndex);
        ::operator delete(locals.grabName);
    }
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kGrabIKData.m_kGrabArmData)->Clear(true);
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kGrabIKData.m_kGrabNames)->Clear(true);

    m_kRagdollFeedbackProfile.m_kRagdollFeedbackData.m_sFirstRagdollFeedbackIndex = -1;
    m_kRagdollFeedbackProfile.m_kRagdollFeedbackData.m_sSecondRagdollFeedbackIndex = -1;
    m_kRagdollFeedbackProfile.m_kRagdollFeedbackData.m_sThirdRagdollFeedbackIndex = -1;
    m_kRagdollAnimationData.bEnabled = false;
    m_kFootIKData.bEnabled = false;
    m_kLookIKData.bEnabled = false;
    m_kGrabIKData.bEnabled = false;
    m_kRagdollFeedbackProfile.bEnabled = false;
    m_pActorBase = 0;
    m_pBodyPartDataCur = 0;
}

// @fnv 0x005ed680
BGSRagdoll::BGSRagdoll()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x63));
    ResetFormData();
}

// @fnv 0x005eea20
void BGSRagdoll::InitItem()
{
    if (GetInitialized())
        return;

    TESForm::ClearData();

    unsigned int formID = reinterpret_cast<unsigned int>(m_pBodyPartDataCur);
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        m_pBodyPartDataCur = dynamic_cast<BGSBodyPartData*>(TESForm::GetFormByID(formID));
        if (!m_pBodyPartDataCur)
            Warning("MASTERFILE: Could not find body part data (%08X) for ragdoll '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }

    formID = reinterpret_cast<unsigned int>(m_pActorBase);
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        m_pActorBase = dynamic_cast<TESActorBase*>(TESForm::GetFormByID(formID));
        if (!m_pActorBase)
            Warning("MASTERFILE: Could not find preview actor (%08X) for ragdoll '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }

    SetInitializationState(true);
}

// Reads a BGSRagdoll record from a TESFile, handling EDID, OBND, MODL/MODT, DATA, XNAM, TNAM, RAFD, RAFB, RAPS and ANAM chunks.
// @fnv 0x005ee640
bool BGSRagdoll::LoadForm(TESFile* file)
{
    if (GetRagdollRecordType(file) != 0x63)
        return false;
    LoadRecordHeader(file);
    struct LoadLocals
    {
        char* filename;
        unsigned int i;
        unsigned int count;
        unsigned int body;
        unsigned int preview;
        SaveMetadata saved;
        char* editorID;
        int chunk;
    } locals;
    while ((locals.chunk = file->GetChunkID()) != 0)
    {
        switch (locals.chunk)
        {
        case 0x44494445: {
            locals.editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(locals.editorID, 512);
            SetEditorID_AtRuntime(locals.editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x41544144: {
            file->GetChunkData(&locals.saved, sizeof(locals.saved));
            if (file->IsEndianConversionRequired())
                locals.saved.SwapEndianFourShorts();
            reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)
                ->SetSize(locals.saved.m_usFootIndexCount, true);
            m_kFootIKData.m_kLegData.SetSize(locals.saved.m_usLegDataCount, true);
            m_kLookIKData.m_kHeadData.SetSize(locals.saved.m_usHeadDataCount, true);
            m_kGrabIKData.m_kGrabArmData.SetSize(locals.saved.m_usGrabArmDataCount, true);
            m_kRagdollAnimationData.bEnabled = locals.saved.m_bRagdollAnimationEnabled;
            m_kFootIKData.bEnabled = locals.saved.m_bFootIKEnabled;
            m_kLookIKData.bEnabled = locals.saved.m_bLookIKEnabled;
            m_kGrabIKData.bEnabled = locals.saved.m_bGrabIKEnabled;
            m_kRagdollFeedbackProfile.bEnabled = locals.saved.m_bRagdollFeedbackEnabled;
            break;
        }
        case 0x4d414e58: {
            locals.preview = 0;
            file->GetChunkData(&locals.preview);
            m_pActorBase = reinterpret_cast<TESActorBase*>(locals.preview);
            break;
        }
        case 0x4d414e54: {
            locals.body = 0;
            file->GetChunkData(&locals.body);
            m_pBodyPartDataCur = reinterpret_cast<BGSBodyPartData*>(locals.body);
            break;
        }
        case 0x44464152:
            file->GetChunkData(&m_kRagdollAnimationData.m_kRagdollFeedbackData,
                               sizeof(m_kRagdollAnimationData.m_kRagdollFeedbackData));
            if (file->IsEndianConversionRequired())
                SwapRagdollFeedbackEndian(&m_kRagdollAnimationData.m_kRagdollFeedbackData);
            break;
        case 0x42464152: {
            file->GetChunkData(
                &reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)
                     ->GetAt(0),
                reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)
                        ->GetSize() *
                    2);
            locals.count =
                reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)
                    ->GetSize();
            if (file->IsEndianConversionRequired())
            {
                for (locals.i = 0; locals.i < locals.count; ++locals.i)
                    BSEndian(
                        &reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)
                             ->GetAt(locals.i),
                        EndianSizeTag<2>());
            }
            break;
        }
        case 0x53504152:
            file->GetChunkData(&m_kRagdollFeedbackProfile.m_kRagdollFeedbackData,
                               sizeof(m_kRagdollFeedbackProfile.m_kRagdollFeedbackData));
            if (file->IsEndianConversionRequired())
                SwapPoseMatchingEndian(&m_kRagdollFeedbackProfile.m_kRagdollFeedbackData);
            break;
        case 0x4d414e41: {
            locals.filename = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(locals.filename, 0);
            m_kRagdollFeedbackProfile.m_kAnimationFileName.Set(locals.filename, 0);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

void __fastcall RagdollFeedbackData_RagdollFeedbackSystemData_RagdollFeedbackSystemData(void*);
void __fastcall BSSimpleArray_short_1024_BSSimpleArray_short_1024(void*);

// @fnv 0x005ed760
// src: COMMUNITY 0x005ed760
void* __fastcall BGSRagdoll_Feedback_Init(char* pThis)
{
    *pThis = 0;
    RagdollFeedbackData_RagdollFeedbackSystemData_RagdollFeedbackSystemData(pThis + 4);
    BSSimpleArray_short_1024_BSSimpleArray_short_1024(pThis + 0x40);
    return pThis;
}

extern float const g_011c3bb8_arg1;
extern float const g_011d8aa4_arg1;
extern float DAT_010231a8;

// Fills the 15-element float/int block at pThis with constant values and returns pThis.
// @fnv 0x005ed790
// src: XBOX_PDB 0x005ed790
void* __fastcall RagdollFeedbackData_RagdollFeedbackSystemData_RagdollFeedbackSystemData(float* pThis)
{
    pThis[0] = g_011c3bb8_arg1;
    pThis[1] = 0.8f;
    pThis[2] = DAT_010231a8;
    pThis[3] = 0.2f;
    pThis[4] = 0.1f;
    pThis[5] = 0.3f;
    pThis[6] = 0.0f;
    pThis[7] = 50.0f;
    pThis[8] = 50.0f;
    pThis[9] = g_011d8aa4_arg1;
    pThis[10] = g_011d8aa4_arg1;
    pThis[11] = 50.0f;
    pThis[12] = 50.0f;
    ((int*)pThis)[13] = 10000;
    ((int*)pThis)[14] = 30000;
    return pThis;
}

// FootIKSystem's constructor must precede both arrays, but the shared class has no constructor declaration.
struct FootIKFeedbackConstruction : FootIK_DATA__FootIKSystem_DATA
{
    FootIKFeedbackConstruction();
};
struct FootIKConstruction
{
    bool bEnabled;
    FootIKFeedbackConstruction feedback;
    BSSimpleArray<const char*, 1024> names;
    BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024> legs;
    FootIKConstruction();
};

// @fnv 0x005ed850
FootIKConstruction::FootIKConstruction() : bEnabled(false)
{}

// Sets the first seven floats of pThis to 0.0f and returns pThis.
// @fnv 0x005ed8c0
// src: GUESS 0x005ed8c0 (confidence: low)
float* __fastcall Object_ComputeValue_005ed8c0(float* pThis)
{
    pThis[0] = 0.0f;
    pThis[1] = 0.0f;
    pThis[2] = 0.0f;
    pThis[3] = 0.0f;
    pThis[4] = 0.0f;
    pThis[5] = 0.0f;
    pThis[6] = 0.0f;
    return pThis;
}

// @fnv 0x005ed910
LookIK_DATA::LookIK_DATA() : bEnabled(false)
{}

// @fnv 0x005ed980
GrabIK_DATA::GrabIK_DATA() : bEnabled(false)
{}

void __fastcall InitDefaults(void*);

// @fnv 0x005ed9f0
RagdollFeedbackProfile::RagdollFeedbackProfile() : bEnabled(false)
{
    InitDefaults(&m_kRagdollFeedbackData);
}

// Initializes the object's fields: three shorts to -1, a byte to 0, and floats to 0, 0, 0.1, 0, then returns pThis.
// @fnv 0x005eda60
void* __fastcall InitDefaults(char* pThis)
{
    *(short*)(pThis + 0x0) = -1;
    *(short*)(pThis + 0x2) = -1;
    *(short*)(pThis + 0x4) = -1;
    *(char*)(pThis + 0x6) = 0;
    *(float*)(pThis + 0x8) = 0.0f;
    *(float*)(pThis + 0xc) = 0.0f;
    *(float*)(pThis + 0x10) = 0.1f;
    *(float*)(pThis + 0x14) = 0.0f;
    return pThis;
}

// Byte-swaps four consecutive 16-bit values starting at thisPtr via BSEndian.
// @fnv 0x005ee510
void SaveMetadata::SwapEndianFourShorts()
{
    BSEndian(&m_usFootIndexCount, EndianSizeTag<2>());
    BSEndian(&m_usLegDataCount, EndianSizeTag<2>());
    BSEndian(&m_usHeadDataCount, EndianSizeTag<2>());
    BSEndian(&m_usGrabArmDataCount, EndianSizeTag<2>());
}

unsigned int __cdecl BSStringLength(const char* apString);
namespace RagdollStrings
{
int __cdecl Copy(char* apDest, unsigned int auiSize, const char* apSrc);
}


// Clears this object's arrays, resizes them to match arData, copies the arm data and duplicated strings, then copies bEnabled.
// @fnv 0x005ed360
void GrabIKOperations::CopyData(const GrabIK_DATA& arSource)
{
    ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)this + 0x14))->Clear(true);
    for (unsigned int ui = 0; ui < ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)this + 4))->GetSize(); ui++)
        delete (void*)((BSSimpleArray<unsigned int, 1024>*)((char*)this + 4))->GetAt(ui);
    ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)this + 4))->Clear(true);

    ((BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>*)((char*)this + 0x14))
        ->SetSize(((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)&arSource + 0x14))->GetSize(), true);
    ((BSSimpleArray<const char*, 1024>*)((char*)this + 4))->SetSize(((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)&arSource + 4))->GetSize(), true);

    for (unsigned int ui = 0; ui < ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)&arSource + 0x14))->GetSize(); ui++)
        ((BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>*)((char*)this + 0x14))->GetAt(ui) =
            ((BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>*)((char*)&arSource + 0x14))->GetAt(ui);

    for (unsigned int ui = 0; ui < ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)&arSource + 4))->GetSize(); ui++)
    {
        unsigned int uiLength = BSStringLength((const char*)((BSSimpleArray<unsigned int, 1024>*)((char*)&arSource + 4))->GetAt(ui)) + 1;
        char* pString = new char[uiLength];
        RagdollStrings::Copy(pString, uiLength, (const char*)((BSSimpleArray<unsigned int, 1024>*)((char*)&arSource + 4))->GetAt(ui));
        ((BSSimpleArray<unsigned int, 1024>*)((char*)this + 4))->GetAt(ui) = (unsigned int)pString;
    }

    bEnabled = arSource.bEnabled;
}


// @fnv 0x005ed4f0
bool RagdollFeedbackOperations::Differs(const RagdollFeedbackProfile& arOther)
{
    bool bret = false;
    if (((RagdollStringOperations*)((char*)this + 4))
            ->CompareText((const BSStringT<char>*)((const char*)&arOther + 4), true))
        bret = true;
    if (bret || bEnabled != arOther.bEnabled ||
        *(short*)((char*)this + 0xc) != *(const short*)((const char*)&arOther + 0xc) ||
        *(short*)((char*)this + 0xe) != *(const short*)((const char*)&arOther + 0xe) ||
        *(short*)((char*)this + 0x10) != *(const short*)((const char*)&arOther + 0x10) ||
        *(float*)((char*)this + 0x14) != *(const float*)((const char*)&arOther + 0x14) ||
        *(float*)((char*)this + 0x1c) != *(const float*)((const char*)&arOther + 0x1c) ||
        *(unsigned char*)((char*)this + 0x12) != *(const unsigned char*)((const char*)&arOther + 0x12) ||
        *(float*)((char*)this + 0x20) != *(const float*)((const char*)&arOther + 0x20) ||
        *(float*)((char*)this + 0x18) != *(const float*)((const char*)&arOther + 0x18))
        bret = true;
    return bret;
}


// Copies a string, a flag and several numeric fields from arData into this object.
// @fnv 0x005ed5f0
void RagdollFeedbackOperations::CopyData(const RagdollFeedbackProfile& arSource)
{
    *(BSStringT<char>*)((char*)this + 4) = *(const BSStringT<char>*)((const char*)&arSource + 4);
    bEnabled = arSource.bEnabled;
    *(unsigned short*)((char*)this + 0xc) = *(const unsigned short*)((const char*)&arSource + 0xc);
    *(unsigned short*)((char*)this + 0xe) = *(const unsigned short*)((const char*)&arSource + 0xe);
    *(unsigned short*)((char*)this + 0x10) = *(const unsigned short*)((const char*)&arSource + 0x10);
    *(float*)((char*)this + 0x14) = *(const float*)((const char*)&arSource + 0x14);
    *(float*)((char*)this + 0x1c) = *(const float*)((const char*)&arSource + 0x1c);
    *(unsigned char*)((char*)this + 0x12) = *(const unsigned char*)((const char*)&arSource + 0x12);
    *(float*)((char*)this + 0x18) = *(const float*)((const char*)&arSource + 0x18);
    *(float*)((char*)this + 0x20) = *(const float*)((const char*)&arSource + 0x20);
}

namespace fnv_005edfb0 {

// Frees each element of three arrays at offsets 0xb0, 0xd4 and 0xf8, then clears those arrays and the objects at 0x80, 0xc0, 0xe4 and 0x108.
// @fnv 0x005edfb0
void __fastcall ClearRagdollData(BGSRagdoll* ragdoll)
{
    ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)ragdoll + 0x80))->Clear(true);

    for (unsigned int ui = 0; ui < ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)ragdoll + 0xb0))->GetSize(); ui++)
        delete (void*)((BSSimpleArray<unsigned int, 1024>*)((char*)ragdoll + 0xb0))->GetAt(ui);
    ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)ragdoll + 0xc0))->Clear(true);
    ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)ragdoll + 0xb0))->Clear(true);

    for (unsigned int ui = 0; ui < ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)ragdoll + 0xd4))->GetSize(); ui++)
        delete (void*)((BSSimpleArray<unsigned int, 1024>*)((char*)ragdoll + 0xd4))->GetAt(ui);
    ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)ragdoll + 0xe4))->Clear(true);
    ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)ragdoll + 0xd4))->Clear(true);

    for (unsigned int ui = 0; ui < ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)ragdoll + 0xf8))->GetSize(); ui++)
        delete (void*)((BSSimpleArray<unsigned int, 1024>*)((char*)ragdoll + 0xf8))->GetAt(ui);
    ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)ragdoll + 0x108))->Clear(true);
    ((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)ragdoll + 0xf8))->Clear(true);
}
}  // namespace fnv_005edfb0

void __cdecl BSEndian(unsigned int*, EndianSizeTag<4>);

// Byte-swaps each of the 15 unsigned int fields of this struct via BSEndian.
// @fnv 0x005ee380
void __fastcall SwapRagdollFeedbackEndian(RagdollFeedbackData__RagdollFeedbackSystemData* data)
{
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_fFeedbackParameter1), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->fHeirGain), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_fFeedbackParameter3), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->fVelGain), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_fFeedbackParameter5), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->fSnapGain), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_fFeedbackParameter7), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_fFeedbackParameter8), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_fFeedbackParameter9), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_fFeedbackParameter10), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_fFeedbackParameter11), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_fFeedbackParameter12), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_fFeedbackParameter13), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->ThreeFloatsAndTwoIntegers), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_uiFeedbackParameter14), EndianSizeTag<4>());
}

void __cdecl BSEndian(unsigned int*, EndianSizeTag<4>);

// Byte-swaps the three 16-bit and four 32-bit fields of the struct via BSEndian.
// @fnv 0x005ee580
void __fastcall SwapPoseMatchingEndian(PoseMatching_DATA__PoseMatching_System_DATA* data)
{
    BSEndian(reinterpret_cast<unsigned short*>(&data->m_sFirstRagdollFeedbackIndex), EndianSizeTag<2>());
    BSEndian(reinterpret_cast<unsigned short*>(&data->m_sSecondRagdollFeedbackIndex), EndianSizeTag<2>());
    BSEndian(reinterpret_cast<unsigned short*>(&data->m_sThirdRagdollFeedbackIndex), EndianSizeTag<2>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->ShortFlagFloatRecord), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->FourFloatRecord), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->FourFloatParameterBlock), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<unsigned int*>(&data->m_fFourthParameter), EndianSizeTag<4>());
}


// Casts apCopy to BGSRagdoll, then copies its fields and embedded sub-objects into this ragdoll.
// @fnv 0x005eeb70
void RagdollOperations::CopyData(TESForm* apCopy)
{
    BGSRagdoll* pcopy = dynamic_cast<BGSRagdoll*>(apCopy);
    if (!pcopy)
        return;
    TESForm::CopyFrom(apCopy);
    m_pActorBase = pcopy->m_pActorBase;
    m_pBodyPartDataCur = pcopy->m_pBodyPartDataCur;
    m_iRagdollType = pcopy->m_iRagdollType;
    ((RagdollAnimationOperations*)((char*)this + 0x40))->CopyFrom(*(RagdollAnimationOperations*)((char*)pcopy + 0x40));
    ((FootIKOperations*)((char*)this + 0x90))->CopyData(*(FootIK_DATA*)((char*)pcopy + 0x90));
    ((LookIKOperations*)((char*)this + 0xd0))->CopyData(*(LookIK_DATA*)((char*)pcopy + 0xd0));
    ((GrabIKOperations*)((char*)this + 0xf4))->CopyData(*(GrabIK_DATA*)((char*)pcopy + 0xf4));
    ((RagdollFeedbackOperations*)((char*)this + 0x118))->CopyData(*(RagdollFeedbackProfile*)((char*)pcopy + 0x118));
}


// Compares this BGSRagdoll with apCompare field by field, returning true if any compared member differs or the cast fails.
// @fnv 0x005eec60
bool RagdollOperations::Differs(TESForm* apCompare)
{
    BGSRagdoll* pcomp = dynamic_cast<BGSRagdoll*>(apCompare);
    if (!pcomp)
        return true;
    if (TESForm::Compare(pcomp))
        return true;
    if (m_iRagdollType != pcomp->m_iRagdollType)
        return true;
    if (((RagdollAnimationOperations*)((char*)this + 0x40))->Differs(*(RagdollAnimationOperations*)((char*)pcomp + 0x40)))
        return true;
    if (((FootIKOperations*)((char*)this + 0x90))->Differs(*(FootIK_DATA*)((char*)pcomp + 0x90)))
        return true;
    if (((LookIKOperations*)((char*)this + 0xd0))->Differs(*(LookIK_DATA*)((char*)pcomp + 0xd0)))
        return true;
    if (((GrabIKOperations*)((char*)this + 0xf4))->Differs(*(GrabIK_DATA*)((char*)pcomp + 0xf4)))
        return true;
    if (((RagdollFeedbackOperations*)((char*)this + 0x118))->Differs(*(RagdollFeedbackProfile*)((char*)pcomp + 0x118)))
        return true;
    if (m_pBodyPartDataCur != pcomp->m_pBodyPartDataCur)
        return true;
    return false;
}


extern int DAT_010472d0;

// The constructor and destructor store the BSSimpleArray<char const *,1024> vftable 0x010472d0.
// @fnv 0x005eede0
template <>
BSSimpleArray<const char*, 1024>::BSSimpleArray()
{
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(this)->BSSimpleArray_float_1024_InitialSetup(0, false);
}

// @fnv 0x005eee10
template <>
BSSimpleArray<const char*, 1024>::~BSSimpleArray()
{
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(this)->Clear(true);
}

// @fnv 0x005edb10
FootIK_DATA::~FootIK_DATA()
{}

// @fnv 0x005edb70
LookIK_DATA::~LookIK_DATA()
{}

// @fnv 0x005edbd0
GrabIK_DATA::~GrabIK_DATA()
{}

namespace fnv_005ef010 {

// Shared array specialization lacks the virtual allocator and resize helpers.
struct FootIKArrayResize
{
    virtual void v0();
    virtual FootIK_DATA__FootIK_Leg_DATA* Allocate(unsigned int n);
    FootIK_DATA__FootIK_Leg_DATA* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    void ConstructSpawnItems(FootIK_DATA__FootIK_Leg_DATA* p, unsigned int n);
    void FUN_005ef860(unsigned int newAlloc, unsigned int copy);
    void BSSimpleArray_FootIK_DATA_FootIK_Leg_DATA_1024_SetLength(unsigned int aiNewSize, bool abFreeMemory);
};

// @fnv 0x005ef010
// src: COMMUNITY 0x005ef010
void FootIKArrayResize::BSSimpleArray_FootIK_DATA_FootIK_Leg_DATA_1024_SetLength(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        ((BSSimpleArray<SandboxProcedureData, 1024>*)this)->Clear(abFreeMemory);
    }
    else if (aiNewSize > uiAllocSize)
    {
        if (uiAllocSize == 0)
        {
            pBuffer = Allocate(aiNewSize);
            uiAllocSize = aiNewSize;
        }
        else
        {
            FUN_005ef860(aiNewSize, uiSize);
            uiAllocSize = aiNewSize;
        }
        ConstructSpawnItems(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
    else if (aiNewSize < uiSize)
    {
        ((BSSimpleArray<unsigned char, 1024>*)this)->ReleaseElements(reinterpret_cast<unsigned char*>(pBuffer + aiNewSize), uiSize - aiNewSize);
        uiSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= uiAllocSize >> 2)
        {
            FUN_005ef860(aiNewSize, aiNewSize);
            uiAllocSize = aiNewSize;
        }
    }
    else
    {
        ConstructSpawnItems(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
}
}  // namespace fnv_005ef010

namespace fnv_005ef1f0 {

// Shared array specialization lacks the virtual allocator and resize helpers.
struct LookIKArrayResize
{
    virtual void v0();
    virtual LookIK_DATA__LookIK_Head_DATA* Allocate(unsigned int n);
    LookIK_DATA__LookIK_Head_DATA* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    void ConstructEntries(LookIK_DATA__LookIK_Head_DATA* p, unsigned int n);
    void BSSimpleArray_PathingLocation_1024_ReallocateBuffer(unsigned int newAlloc, unsigned int copy);
    void BSSimpleArray_LookIK_DATA_LookIK_Head_DATA_1024_SetLength(unsigned int aiNewSize, bool abFreeMemory);
};

// @fnv 0x005ef1f0
// src: COMMUNITY 0x005ef1f0
void LookIKArrayResize::BSSimpleArray_LookIK_DATA_LookIK_Head_DATA_1024_SetLength(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        ((BSSimpleArray<SandboxProcedureData, 1024>*)this)->Clear(abFreeMemory);
    }
    else if (aiNewSize > uiAllocSize)
    {
        if (uiAllocSize == 0)
        {
            pBuffer = Allocate(aiNewSize);
            uiAllocSize = aiNewSize;
        }
        else
        {
            BSSimpleArray_PathingLocation_1024_ReallocateBuffer(aiNewSize, uiSize);
            uiAllocSize = aiNewSize;
        }
        ConstructEntries(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
    else if (aiNewSize < uiSize)
    {
        ((BSSimpleArray<unsigned char, 1024>*)this)->ReleaseElements(reinterpret_cast<unsigned char*>(pBuffer + aiNewSize), uiSize - aiNewSize);
        uiSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= uiAllocSize >> 2)
        {
            BSSimpleArray_PathingLocation_1024_ReallocateBuffer(aiNewSize, aiNewSize);
            uiAllocSize = aiNewSize;
        }
    }
    else
    {
        ConstructEntries(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
}
}  // namespace fnv_005ef1f0

namespace fnv_005ef3d0 {

// Shared array specialization lacks the virtual allocator and resize helpers.
struct GrabIKArrayResize
{
    virtual void Destroy(bool);
    virtual GrabIK_DATA__GrabIK_Arm_DATA* Allocate(unsigned int);
    GrabIK_DATA__GrabIK_Arm_DATA* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    void FUN_005efc90(unsigned int, unsigned int);
    void ConstructItems(GrabIK_DATA__GrabIK_Arm_DATA*, unsigned int);
    void BSSimpleArray_GrabIK_DATA_GrabIK_Arm_DATA_1024_SetLength(unsigned int aiNewSize, bool abFreeMemory);
};

// @fnv 0x005ef3d0
// src: COMMUNITY 0x005ef3d0
void GrabIKArrayResize::BSSimpleArray_GrabIK_DATA_GrabIK_Arm_DATA_1024_SetLength(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        ((BSSimpleArray<SandboxProcedureData, 1024>*)this)->Clear(abFreeMemory);
    }
    else if (aiNewSize > uiAllocSize)
    {
        if (uiAllocSize == 0)
        {
            pBuffer = Allocate(aiNewSize);
            uiAllocSize = aiNewSize;
        }
        else
        {
            FUN_005efc90(aiNewSize, uiSize);
            uiAllocSize = aiNewSize;
        }
        ConstructItems(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
    else if (aiNewSize < uiSize)
    {
        ((BSSimpleArray<unsigned char, 1024>*)this)->ReleaseElements(reinterpret_cast<unsigned char*>(pBuffer + aiNewSize), uiSize - aiNewSize);
        uiSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= uiAllocSize >> 2)
        {
            FUN_005efc90(aiNewSize, aiNewSize);
            uiAllocSize = aiNewSize;
        }
    }
    else
    {
        ConstructItems(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
}
}  // namespace fnv_005ef3d0

namespace fnv_005ee110 {


bool __cdecl _FUN_00401500();
void __cdecl _FUN_00485910(unsigned int, unsigned int);
void __cdecl _FUN_00485990(unsigned int, void*, unsigned int);
void __cdecl TESForm_AddChunkArray16_ForwardCall_00485730(void*, void*, void*);
void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);

// @fnv 0x005ee110
void __fastcall SaveRagdoll(BGSRagdoll* ragdoll)
{
    SaveMetadata saveData;

    reinterpret_cast<TESForm*>(ragdoll)->BeginFormRecord();

    reinterpret_cast<TESModel*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x18)
        ->WriteToBuffer(0x4c444f4d, 0x54444f4d);

    _FUN_00485910(0x5245564e, 1);

    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(&saveData) + 0x00) =
        reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x80)->GetSize();

    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(&saveData) + 0x02) =
        reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(reinterpret_cast<unsigned char*>(ragdoll) + 0xc0)->GetSize();

    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(&saveData) + 0x04) =
        reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(reinterpret_cast<unsigned char*>(ragdoll) + 0xe4)->GetSize();

    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(&saveData) + 0x06) =
        reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x108)->GetSize();

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(&saveData) + 0x08) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x40);

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(&saveData) + 0x09) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x90);

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(&saveData) + 0x0a) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(ragdoll) + 0xd0);

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(&saveData) + 0x0b) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(ragdoll) + 0xf4);

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(&saveData) + 0x0c) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x118);

    if (_FUN_00401500())
        saveData.SwapEndianFourShorts();

    _FUN_00485990(0x41544144, &saveData, 0x0e);

    if (_FUN_00401500())
        saveData.SwapEndianFourShorts();

    if (*reinterpret_cast<TESActorBase**>(reinterpret_cast<unsigned char*>(ragdoll) + 0x144))
    {
        unsigned int itempint;
        itempint = (*reinterpret_cast<TESActorBase**>(reinterpret_cast<unsigned char*>(ragdoll) + 0x144))->GetFormID();
        _FUN_00485910(0x4d414e58, itempint);
    }

    if (*reinterpret_cast<BGSBodyPartData**>(reinterpret_cast<unsigned char*>(ragdoll) + 0x140))
    {
        unsigned int itempint;
        itempint = (*reinterpret_cast<BGSBodyPartData**>(reinterpret_cast<unsigned char*>(ragdoll) + 0x140))->GetFormID();
        _FUN_00485910(0x4d414e54, itempint);
    }

    if (_FUN_00401500())
        SwapRagdollFeedbackEndian(reinterpret_cast<RagdollFeedbackData__RagdollFeedbackSystemData*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x44));

    _FUN_00485990(0x44464152, reinterpret_cast<unsigned char*>(ragdoll) + 0x44, 0x3c);

    if (_FUN_00401500())
        SwapRagdollFeedbackEndian(reinterpret_cast<RagdollFeedbackData__RagdollFeedbackSystemData*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x44));

    if (reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x80)->GetSize() > 0)
    {
        TESForm_AddChunkArray16_ForwardCall_00485730(reinterpret_cast<void*>(0x42464152),
                     &reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x80)->GetAt(0),
                     reinterpret_cast<void*>(
                         reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x80)->GetSize()));
    }

    if (_FUN_00401500())
        SwapPoseMatchingEndian(reinterpret_cast<PoseMatching_DATA__PoseMatching_System_DATA*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x124));

    _FUN_00485990(0x53504152, reinterpret_cast<unsigned char*>(ragdoll) + 0x124, 0x18);

    if (_FUN_00401500())
        SwapPoseMatchingEndian(reinterpret_cast<PoseMatching_DATA__PoseMatching_System_DATA*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x124));

    if (reinterpret_cast<BSStringT<char>*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x11c)->Length())
    {
        TESForm_AddChunkArray(0x4d414e41,
                     const_cast<char*>(
                         reinterpret_cast<BSStringT<char>*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x11c)
                             ->String()),
                     reinterpret_cast<BSStringT<char>*>(reinterpret_cast<unsigned char*>(ragdoll) + 0x11c)->Length() +
                         1);
    }

    reinterpret_cast<TESForm*>(ragdoll)->FinishFormRecord();
}
}  // namespace fnv_005ee110

// @fnv 0x005edaf0
RagdollAnimationData::~RagdollAnimationData()
{}

// @fnv 0x005edc30
BGSRagdoll::~BGSRagdoll()
{
    fnv_005edfb0::ClearRagdollData(this);
}
