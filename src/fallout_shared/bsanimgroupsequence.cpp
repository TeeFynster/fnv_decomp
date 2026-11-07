// fallout_shared/bsanimgroupsequence.cpp: animation sequences and sound playback (20 functions)

#include "../../include/BSAnimGroupSequence.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/GO.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiControllerSequence.h"
#include "../../include/NiAVObjectPalette.h"
#include "../../include/BSAudio.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiTextKeyExtraData.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESSound.h"
#include "../../include/TESAnimGroup.h"
#include "../../include/TESSaveLoadGame.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiDefaultAVObjectPalette.h"
#include "../../include/NiMemObject.h"
#include "../../include/NiPointer.h"
#include "../../include/NiBlendInterpolator.h"
#include "../../include/NiMultiTargetTransformController.h"

// NiControllerSequence.h only forward-declares these records; their shared
// definitions and object-name accessor are not available yet.
class NiControllerSequence__InterpArrayItem
{
public:
    NiInterpolator* m_pkInterpolator;
    NiPointer<NiInterpController> m_spInterpController;
    NiBlendInterpolator* m_pkBlendInterpolator;
    unsigned char m_ucPriority;
    unsigned char m_ucArrayItemID;
    char trailing[2];
};
class NiControllerSequence__IDTag
{
public:
    NiFixedString m_kAVObjectName;
    char fields[16];
    NiFixedString* GetObjectName();
};

extern const NiRTTI g_012031b8;
extern const NiRTTI DAT_011f36bc;
// The shared transform controller lacks this animation-update member.
class AnimationInterpolatorNode : public NiMultiTargetTransformController
{
  public:
    void UpdateInterpolatorsAtTime(float, bool);
};


extern PlayerCharacter* g_thePlayer;
extern TESDataHandler* g_dataHandler;
// No shared declaration is available for the sound-distance predicate.
bool CanPlaySequenceSoundAt(TESSound*, NiPoint3, float);
// NiTextKeyExtraData.h only forward-declares the text-key record.
class TimedTextEntry
{
  public:
    float m_fTime;
    NiFixedString m_kText;
    NiFixedString& Text();
    float Time();
};
extern const float DAT_01023850;
const NiFixedString& FixedStrings_QAttachSound();
extern "C" int _strnicmp(const char*, const char*, unsigned int);
int BSstricmp(const char*, const char*);
extern "C" char* strchr(const char*, int);
extern "C" char* __insecure_strcpy(char*, const char*);
int Warning(const char*, ...);

// Scans the sequence's tag array for a matching object name and returns its priority byte, writing the matching index to indexOut when given.
// @fnv 0x004ef9a0
unsigned char BSAnimGroupSequence::GetPriority(const char* objectName, unsigned int* indexOut)
{
    for (unsigned int i = 0; i < m_uiNumControlledBlocks; ++i)
    {
        const char* name = m_pkIDTags[i].GetObjectName()->operator const char*();
        if (!name)
            Warning("NULL object name found in tag array for sequence '%s'.",
                    GetName().operator const char*());
        if (name && !BSstricmp(name, objectName))
        {
            if (indexOut)
                *indexOut = i;
            return m_pInterpArray[i].m_ucArrayItemID;
        }
    }
    return 0;
}

// @fnv 0x004efdc0
bool BSAnimGroupSequence::Deactivate(float easeOutTime, bool transition)
{
    if (m_pkAccumulationRoot)
    {
        switch (static_cast<int>(m_spAnimGroup->GetType()))
        {
        case 23:
        case 24:
        case 25: {
            NiTimeController* controller =
                m_pkAccumulationRoot->GetController(&g_012031b8);
            if (controller)
            {
                BGSCameraPath* state = reinterpret_cast<BGSCameraPath*>(controller);
                if (state->GetPrevPath())
                {
                    controller = m_pkAccumulationRoot->GetParent()->GetController(&DAT_011f36bc);
                    if (controller)
                        static_cast<AnimationInterpolatorNode*>(controller)
                            ->UpdateInterpolatorsAtTime(m_fLastTime, true);
                }
            }
        }
        break;
        }
    }
    return NiControllerSequence::Deactivate(easeOutTime, transition);
}


// @fnv 0x004eeb00
BSAnimGroupSequence::~BSAnimGroupSequence()
{}

// Returns 0.0f unless the sequence's state at offset 0x44 is 1-3, otherwise evaluates the helper at afTime plus the offset at 0x48 with clamping.
// @fnv 0x004eec60
// src: XBOX_PDB 0x004eec60
float BSAnimGroupSequence::GetScaledTime(float afTime)
{
    switch (m_eAnimationState)
    {
    case 1:
    case 2:
    case 3:
        break;
    default:
        return 0.0f;
    }
    return ComputeScaledTime_00a30970(afTime + m_fSequenceOffset, true);
}

// Reads a time, a byte, and three ints from the buffer, stores fTime minus fBase into f48, sets f4c and f50 to -DAT_01023850, then calls FUN_004eec60 with fBase.
// @fnv 0x004efd10
// src: COMMUNITY 0x004efd10
void BSAnimGroupSequence::LoadGameBGS_004efd10(BGSLoadFormBuffer* pBuffer, float fBaseTime)
{
    float fTime = 0.0f;
    pBuffer->ReadTypedData(&fTime, 4u);
    m_fSequenceOffset = fTime - fBaseTime;
    unsigned char ucByte = 0;
    pBuffer->ReadTypedData(&ucByte, 1u);
    m_eAnimationState = static_cast<AnimState>(ucByte);
    pBuffer->ReadTypedData(&m_fLastTime, 4u);
    pBuffer->ReadTypedData(&m_fWeightAdjustedLastTime, 4u);
    pBuffer->ReadTypedData(&m_fDestinationFrame, 4u);
    m_fStartTime = -DAT_01023850;
    m_fEndTime = -DAT_01023850;
    GetScaledTime(fBaseTime);
}

extern NiFixedString* DAT_011c61c8;

// @fnv 0x004ef990
// src: XBOX_PDB 0x004ef990
const NiFixedString& __cdecl FixedStrings_QAttachSound()
{
    return *DAT_011c61c8;
}

// @fnv 0x004eec20
// src: XBOX_PDB 0x004eec20
NiObject* __thiscall BSAnimGroupSequence::CreateClone(CloningProcess* arCloneData)
{
    return NiControllerSequence::MakeClone(*arCloneData);
}

// @fnv 0x004eec40
// src: XBOX_PDB 0x004eec40
void BSAnimGroupSequence::GetViewerStrings_004eec40(NiTPrimitiveArray<const char*>* pkStrings)
{
    NiControllerSequence::AddViewerStrings(pkStrings);
}

// @fnv 0x004ef970
// src: XBOX_PDB 0x004ef970
void NiAVObject::SetHasMovingSound(bool enabled)
{
    SetBit(enabled, 0x20000);
}

extern TESSaveLoadGame* g_TESSaveLoadGame;

// @fnv 0x004efaa0
// src: COMMUNITY 0x004efaa0
unsigned short BSAnimGroupSequence_GetSequenceSaveSize()
{
    unsigned short v = 0;
    v += 4;
    v += 4;
    if (g_TESSaveLoadGame->FUN_008df040() < 0x71)
        v += 4;
    v += 4;
    v += 4;
    v += 4;
    return v;
}

// @fnv 0x004efb20
// src: COMMUNITY 0x004efb20
void BSAnimGroupSequence::SaveGameTES_004efb20(float afTime)
{
    float foffset = m_fSequenceOffset + afTime;
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&foffset, 4u);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_eAnimationState, 4u);
    if (g_TESSaveLoadGame->FUN_008df040() < 0x71)
    {
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&foffset, 4u);
    }
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_fLastTime, 4u);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_fWeightAdjustedLastTime, 4u);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_fDestinationFrame, 4u);
}


// @fnv 0x004eedd0
bool BSAnimGroupSequence::AttachToOwner(NiAVObject* target, int argument)
{
    return ResolveTransformInterpolators(target, reinterpret_cast<NiAVObject*>(m_pkOwnerManager->GetStringAtOffset()), argument);
}

unsigned short __cdecl BSAnimGroupSequence_GetSequenceSaveSize();

// @fnv 0x004efb10
// src: XBOX_PDB 0x004efb10
unsigned short __thiscall BSAnimGroupSequence::GetSaveSize_004efb10()
{
    return BSAnimGroupSequence_GetSequenceSaveSize();
}

// The shared sequence lacks the block-count accessor at 0x0084e3a0 and the
// clearing member at 0x004efa50. Both take the sequence in ECX.
unsigned int __fastcall GetSequenceControlledBlockCount(NiControllerSequence* sequence);
// @fnv 0x004efa50
void __fastcall ClearSequenceBlendInterpolators(NiControllerSequence* sequence)
{
    int i;
    for (i = 0; i < GetSequenceControlledBlockCount(sequence); ++i)
        sequence->m_pInterpArray[i].m_pkBlendInterpolator = 0;
}

// Adds value to m_0x48 and saves the sum, m_0x44, m_0x34, m_0x38 and m_0x54 into the save buffer.
// @fnv 0x004efc90
// src: COMMUNITY 0x004efc90
void __thiscall BSAnimGroupSequence::SaveGameBGS_004efc90(BGSSaveFormBuffer* buffer, float value)
{
    float temp = m_fSequenceOffset + value;
    buffer->SaveData(&temp, 4, 0);
    unsigned char byte2 = m_eAnimationState;
    buffer->SaveData(&byte2, 1, 0);
    buffer->SaveData(&m_fLastTime, 4, 0);
    buffer->SaveData(&m_fWeightAdjustedLastTime, 4, 0);
    buffer->SaveData(&m_fDestinationFrame, 4, 0);
}



void __cdecl NiControllerSequence_CreateSequenceFromFile(int, int, GO*);

// Constructs a sequence from the cloned object returned in value, then assigns it to target.
// @fnv 0x004eeb60
void __cdecl AssignNewObjectFromValue(int arg1, int arg2, GO* target)
{
    {
        GO value(0);

        NiControllerSequence_CreateSequenceFromFile(arg1, arg2, &value);

        target->operator=(new BSAnimGroupSequence(0, reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(static_cast<const GO&>(value)))));
    }
}

// @fnv 0x004efbc0
// src: XBOX_PDB 0x004efbc0
void BSAnimGroupSequence::LoadGame_004efbc0(float value)
{
    float loadedValue;

    g_TESSaveLoadGame->ReadTypedData(&loadedValue, 4);
    g_TESSaveLoadGame->ReadTypedData(&m_eAnimationState, 4);

    if (g_TESSaveLoadGame->FUN_008df040() < 0x71)
        g_TESSaveLoadGame->ReadTypedData(&loadedValue, 4);

    m_fSequenceOffset = loadedValue - value;

    g_TESSaveLoadGame->ReadTypedData(&m_fLastTime, 4);
    g_TESSaveLoadGame->ReadTypedData(&m_fWeightAdjustedLastTime, 4);
    g_TESSaveLoadGame->ReadTypedData(&m_fDestinationFrame, 4);

    m_fStartTime = -DAT_01023850;
    m_fEndTime = -DAT_01023850;

    this->GetScaledTime(value);
}

extern unsigned char DAT_01096968;
// @fnv 0x004eecb0
// src: COMMUNITY 0x004eecb0
void BSAnimGroupSequence::ValidateTargets()
{
    if (!m_pkOwnerManager)
        return;
    NiDefaultAVObjectPalette* root = static_cast<NiDefaultAVObjectPalette*>(m_pkOwnerManager->GetStringAtOffset());
    NiDefaultAVObjectPalette* object = root;
    if (m_pkAccumulationRoot)
        m_pkAccumulationRoot = root->FindAVObject(m_pkAccumulationRoot->GetName());
    for (unsigned int index = 0; index < m_uiNumControlledBlocks; index++)
    {
        NiControllerSequence__IDTag* tag = &m_pkIDTags[index];
        if (!object->vf38()->GetObjectByName(*tag->GetObjectName()))
        {
            root->AddNamedAVObject(*tag->GetObjectName(), 0);
            m_pInterpArray[index].m_spInterpController = static_cast<NiInterpController*>(0);
            m_pInterpArray[index].m_pkBlendInterpolator = 0;
            m_pInterpArray[index].m_ucPriority = DAT_01096968;
        }
    }
}

// The shared sequence lacks the 0x004eee00 member declaration. The original
// no-argument thiscall entry also accepts its sequence in ECX as this free helper.
// @fnv 0x004eee00
void __fastcall UpdateSequenceEntryStates(NiControllerSequence* sequence)
{
    NiAVObjectPalette* manager = sequence->m_pkOwnerManager->GetStringAtOffset();
    NiAVObjectPalette* cachedManager = manager;
    if (sequence->m_pkAccumulationRoot != 0)
        sequence->m_pkAccumulationRoot = manager->FindAVObject(static_cast<const NiFixedString&>(sequence->m_kAccumulationRootName));
    for (unsigned int i = 0; i < sequence->m_uiNumControlledBlocks; ++i)
    {
        NiControllerSequence__IDTag* entry = &sequence->m_pkIDTags[i];
        const char* active = entry->GetObjectName()->operator const char*();
        if (active == 0 || cachedManager->FindAVObject(static_cast<const NiFixedString&>(*entry->GetObjectName())) == 0)
        {
            sequence->m_pInterpArray[i].m_spInterpController = static_cast<NiInterpController*>(0);
            sequence->m_pInterpArray[i].m_pkBlendInterpolator = 0;
            sequence->m_pInterpArray[i].m_ucPriority = DAT_01096968;
        }
    }
}

// NiControllerSequence.h lacks these two accessors (0x00598040 reads +0x3c,
// 0x0059bb30 reads +0x24). Their folded bodies take the sequence in ECX.
float __fastcall GetSequenceScaledLastTime(NiControllerSequence* sequence);
NiTimeController__CycleType __fastcall GetSequenceCycleType(NiControllerSequence* sequence);
void CopySoundText(char*, const char*);
char* FindSoundChar(char*, int);
// @fnv 0x004eef00
bool __cdecl PlaySequenceSounds(NiControllerSequence* sequence, TESObjectREFR* reference)
{
    bool result2 = false;
    if (sequence && sequence->GetState() == 1)
    {
        float previous = sequence->GetField4C();
        float current4 = GetSequenceScaledLastTime(sequence);
        if (previous != -DAT_01023850 && current4 != -DAT_01023850 && previous != current4)
        {
            bool wrapped5 = false;
            if (current4 < previous)
                wrapped5 = true;
            unsigned int count8 = 0;
            TimedTextEntry* keys2 = 0;
            if (sequence->GetName_00700300())
                keys2 = sequence->GetName_00700300()->GetKeys(&count8);
            for (unsigned int index = 0; index < count8; index++)
            {
                char* text_2 = (char*)(const char*)keys2[index].Text();
                if (!text_2)
                    continue;
                float time5 = keys2[index].Time();
                bool play3 = false;
                NiAVObject* node9 = 0;
                if (wrapped5 && (time5 > previous || time5 <= current4))
                    play3 = true;
                else if (time5 >= previous && time5 < current4)
                    play3 = true;
                if (play3 && _strnicmp("Sound: ", text_2, 7))
                {
                    play3 = false;
                    if (!_strnicmp("Enum: StopSounds ", text_2, 17))
                    {
                        char* suffix6 = 0;
                        char nodeName5[32];
                        nodeName5[0] = 0;
                        char* stopNewline4 = FindSoundChar(text_2, 13);
                        if (stopNewline4)
                            *stopNewline4 = 0;
                        suffix6 = text_2 + 16;
                        if (*suffix6 && suffix6[1])
                            CopySoundText(nodeName5, suffix6 + 1);
                        if (stopNewline4)
                            *stopNewline4 = 13;
                        if (reference->GetNiNode())
                        {
                            if (nodeName5[0])
                                node9 = static_cast<const NiNode*>(reference->GetNiNode())->GetObjectByName(NiFixedString(static_cast<const char*>(nodeName5)));
                            else
                                node9 = static_cast<const NiNode*>(reference->GetNiNode())->GetObjectByName(FixedStrings_QAttachSound());
                            if (!node9)
                                node9 = reference->GetNiNode();
                        }
                        if (node9)
                            BSAudio::GetSingleton()->BSAudio_StopMovingSounds(node9, 1.0f, 0x40000000u);
                    }
                    else if (!_strnicmp("Enum: HitShader", text_2, 15))
                        g_thePlayer->ApplyHitShaderToReference(reference);
                }
                TESSound* sound2 = 0;
                char* space8 = 0;
                char objectName3[32];
                objectName3[0] = 0;
                if (play3)
                {
                    char* newline = FindSoundChar(text_2, 13);
                    if (newline)
                        *newline = 0;
                    space8 = FindSoundChar(text_2 + 7, 32);
                    if (space8)
                    {
                        CopySoundText(objectName3, space8 + 1);
                        *space8 = 0;
                    }
                    sound2 = g_dataHandler->GetSoundByEditorID(text_2 + 7);
                    if (newline)
                        *newline = 13;
                }
                if (sound2)
                {
                    BSSoundHandle handle;
                    NiPoint3 position4 = NiPoint3::ZERO;
                    unsigned int flags2 = TESSound::GetPlaybackFlags(sound2->CopyBig().iFlags);
                    bool special2 = (sound2->CopyBig().iFlags & 0x40) && !(sound2->CopyBig().iFlags & 0x800);
                    bool looping5 = (flags2 & 0x10) != 0;
                    flags2 |= reference == g_thePlayer ? 0x200000 : 0;
                    if (reference && reference->GetNiNode())
                    {
                        if (objectName3[0])
                            node9 = static_cast<const NiNode*>(reference->GetNiNode())->GetObjectByName(NiFixedString(static_cast<const char*>(objectName3)));
                        else
                            node9 = static_cast<const NiNode*>(reference->GetNiNode())->GetObjectByName(FixedStrings_QAttachSound());
                        if (looping5 && !node9)
                            node9 = reference->GetNiNode();
                        if (node9)
                            node9->SetHasMovingSound(true);
                        reference->GetNiNode()->SetHasMovingSound(true);
                        if (node9)
                            position4 = node9->NiAVObject_GetWorldTranslate();
                        else
                            position4 = reference->GetNiNode()->NiAVObject_GetWorldTranslate();
                    }
                    if (reference &&
                        (looping5 || special2 || CanPlaySequenceSoundAt(sound2, position4, 1.0f)))
                    {
                        if (looping5)
                            handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                     flags2 | 0x40002002);
                        else
                        {
                            if (sound2->CopyBig().iFlags & 0x40)
                                handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                         flags2 | 0x40002101);
                            else
                                handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                         flags2 | 0x40002102);
                        }
                    }
                    else if (!reference)
                    {
                        if (looping5)
                            handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                     flags2 | 0x40000022);
                        else
                        {
                            if (sound2->CopyBig().iFlags & 0x40)
                                handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                         flags2 | 0x40000121);
                            else
                                handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                         flags2 | 0x40000122);
                        }
                    }
                    if (node9)
                        handle.SetObjectToFollow(node9);
                    handle.SetPosition(position4.x, position4.y, position4.z);
                    handle.Play(looping5);
                }
                if (space8)
                    *space8 = 32;
            }
        }
        if (GetSequenceCycleType(sequence))
        {
            result2 = true;
            if (sequence->TESCombatStyle_GetTargetingFOV() == -DAT_01023850)
                result2 = false;
            else if (GetSequenceScaledLastTime(sequence) < sequence->GetEndKeyTime_00508100())
                result2 = false;
        }
    }
    return result2;
}
