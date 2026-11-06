// fallout_shared/tessound.cpp: TESSound (4 functions)

#define FNV_TESFILE_H  // the shared TESFile below replaces layout_support.h's stub
#include "../../include/NiFile.h"
#include "tessound.h"
#include "../../include/AutoMemContext.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESSound.h"
#include "../../include/TESSoundFile.h"
#include "../../include/TESSound__SOUND_DATA.h"
#include <malloc.h>
#include "../../include/TESFile.h"

const char kTESSoundFileLabel[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSound.cpp";

// Source line of the default-objects context in the original PC file (0x559).
enum
{
    kGenerateDefaultObjectsSourceLine = 0x559
};

// @fnv 0x005e2ef0
void TESSound::ResetFormData()
{
    data.soundFlags = 0;
    data.maxAttenuation = 0;
    data.minAttenuation = 0;
    data.frequencyAdjustment = 0;
    data.staticAttenuation = 0;
    data.unk03 = 0;
    data.stopTime = 0;
    data.attenuationCurve[0] = 100;
    data.attenuationCurve[1] = 50;
    data.attenuationCurve[2] = 20;
    data.attenuationCurve[3] = 5;
    data.attenuationCurve[4] = 0;
    data.reverbAttenuation = 80;
    data.unk1c = 0;
    data.unk20 = 0;
    data.unk18 = 128;
}

// @fnv 0x005e3600
void TESSound::InitializeMagicSystem()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TES_DEFAULT_OBJECTS, true, kTESSoundFileLabel,
                           kGenerateDefaultObjectsSourceLine);
}

// @fnv 0x005e2b70
TESSound::TESSound()
{
    SetFormType(ENUM_FORM_ID_SOUN_ID);
    m_cSoundFlag = 0;
    ResetFormData();
}

// Loads a SOUN record: reads the header, then handles EDID, OBND, FNAM, RNAM, SNDD, SNDX, ANAM, GNAM and HNAM chunks, converting endianness where required.
// @fnv 0x005e3160
bool TESSound::Load(TESFile* file)
{
    if (static_cast<TESFileFormInt*>(file)->GetTESForm() != ENUM_FORM_ID_SOUN_ID)
        return false;
    LoadRecordHeader(file);
    int iChunkID;
    while ((iChunkID = file->GetChunkID()) != 0)
    {
        switch (iChunkID)
        {
        case 0x44494445:  // EDID
        {
            char* pChunkBuffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(pChunkBuffer, 0x200);
            SetEditorID_AtRuntime(pChunkBuffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4D414E46:  // FNAM
        {
            char* pChunkBuffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(pChunkBuffer, 0);
            SetSoundFile(static_cast<const char*>(pChunkBuffer));
            break;
        }
        case 0x4D414E52:  // RNAM
            ReadTypedData(file, &m_cSoundFlag, sizeof(m_cSoundFlag));
            break;
        case 0x44444E53:  // SNDD
            // SNDD stores the 36-byte prefix, before frequencyVariance.
            ReadTypedData(file, &data, offsetof(TESSound__SOUND_DATA, frequencyVariance));
            if (file->IsEndianConversionRequired())
                data.Endian();
            break;
        case 0x58444E53:  // SNDX
        {
            TESSound__SOUND_DATA2 oldSoundData;
            ReadTypedData(file, &oldSoundData, sizeof(oldSoundData));
            if (file->IsEndianConversionRequired())
                oldSoundData.Endian();
            data.minAttenuation = oldSoundData.iMin;
            data.maxAttenuation = oldSoundData.iMax;
            data.frequencyAdjustment = oldSoundData.m_cPitchAdjustment;
            data.soundFlags = oldSoundData.iFlags;
            data.staticAttenuation = oldSoundData.m_uiFrequency;
            data.stopTime = oldSoundData.m_aucAttenuationBytes;
            break;
        }
        case 0x4D414E41:  // ANAM
            ReadTypedData(file, data.attenuationCurve, sizeof(data.attenuationCurve));
            if (file->IsEndianConversionRequired())
            {
                BSEndian(&data.attenuationCurve[0], EndianSizeTag<2>());
                BSEndian(&data.attenuationCurve[1], EndianSizeTag<2>());
                BSEndian(&data.attenuationCurve[2], EndianSizeTag<2>());
                BSEndian(&data.attenuationCurve[3], EndianSizeTag<2>());
                BSEndian(&data.attenuationCurve[4], EndianSizeTag<2>());
            }
            if (data.attenuationCurve[0] == 100 && data.attenuationCurve[1] == 75 &&
                data.attenuationCurve[2] == 50 && data.attenuationCurve[3] == 25 &&
                data.attenuationCurve[4] == 0)
            {
                data.attenuationCurve[0] = 100;
                data.attenuationCurve[1] = 50;
                data.attenuationCurve[2] = 20;
                data.attenuationCurve[3] = 5;
                data.attenuationCurve[4] = 0;
            }
            break;
        case 0x4D414E47:  // GNAM
            ReadTypedData(file, &data.reverbAttenuation, sizeof(data.reverbAttenuation));
            break;
        case 0x4D414E48:  // HNAM
            ReadTypedData(file, &data.unk18, sizeof(data.unk18));
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}
