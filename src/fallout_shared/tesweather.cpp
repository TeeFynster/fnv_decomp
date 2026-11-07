// fallout_shared/tesweather.cpp: TESWeather, TESWeather__WeatherSoundList, TESWeather__WeatherSound, WeatherSave and more (13 functions)

#include "layout_support.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESModel.h"
#include "../../include/TESTexture1024.h"
#include "../../include/TESWeather__WeatherSoundList.h"
#include "../../include/TESWeather.h"
#include "tesweather_decls.h"

// Helpers not yet declared by the shared image-space component.
class WeatherImageSpaceFunctions : public TESImageSpaceModifiableCountForm<6>
{
  public:
    void TESImageSpaceModifiableCountForm_6_SetFormImageSpaceModifying(unsigned int index, unsigned int formID);
    void ReleaseSoundSlots();
};

// @fnv 0x005807f0
TESWeather::TESWeather()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x35));
    ResetFormData();
}

// @fnv 0x00581b40
void TESWeather::ResetFormData()
{
    m_iCloudLayerCount = 3;
    memset(m_auiWeatherColors, 0, sizeof(m_auiWeatherColors));
    memset(m_aucWeatherFlags, 0, sizeof(m_aucWeatherFlags));
    memset(m_afFogDistances, 0, sizeof(m_afFogDistances));
    m_afFogDistances[4] = 1.0F;
    m_afFogDistances[5] = 1.0F;
    memset(m_aucCloudLayerSpeeds, 0, sizeof(m_aucCloudLayerSpeeds));
    memset(m_auiCloudLayerColors, 0, sizeof(m_auiCloudLayerColors));
}

// @fnv 0x00581b00
void TESWeather::InitItem()
{
    if (IsFormInitialized())
        return;
    TESImageSpaceModifiableCountForm<6>::InitItem(this);
    SetInitializationState(true);
}

// @fnv 0x00581be0
void TESWeather::ClearData()
{
    soundList.ClearWeatherSounds();
}

// @fnv 0x00581c00
void TESWeather::MakeDefault()
{
    m_iCloudLayerCount = 3;
    m_kCloudLayerTextures[0].SetTexture("Sky\\WastelandCloudCloudyUpper01.dds");
    m_kCloudLayerTextures[1].SetTexture("Sky\\WastelandCloudHorizon01.dds");
    m_kCloudLayerTextures[2].SetTexture("Sky\\WastelandCloudCloudyLower01.dds");
    m_aucCloudLayerSpeeds[0] = 0x33;
    m_auiCloudLayerColors[0][0] = 0x5B4B46;
    m_auiCloudLayerColors[0][1] = 0x9B9B9B;
    m_auiCloudLayerColors[0][2] = 0x6C5953;
    m_auiCloudLayerColors[0][3] = 0x1C140F;
    m_aucWeatherFlags[0] = 0x33;
    m_aucWeatherFlags[3] = 0xFF;
    m_aucWeatherFlags[4] = 0xFF;
    m_aucWeatherFlags[5] = 0xFF;
    m_aucWeatherFlags[6] = 0x00;
    m_aucWeatherFlags[7] = 0xFF;
    m_aucWeatherFlags[8] = 0x00;
    m_aucWeatherFlags[9] = 0xFF;
    m_aucWeatherFlags[10] = 0x32;
    m_aucWeatherFlags[11] = 0x00;
    m_afFogDistances[2] = 27852.8F;
    m_afFogDistances[0] = 27852.8F;
    m_afFogDistances[3] = 163840.0F;
    m_afFogDistances[1] = 163840.0F;
    m_afFogDistances[5] = 1.0F;
    m_afFogDistances[4] = 1.0F;
    m_auiWeatherColors[7][0] = 0x846C66;
    m_auiWeatherColors[0][0] = 0x846C66;
    m_auiWeatherColors[7][1] = 0x71533E;
    m_auiWeatherColors[0][1] = 0x71533E;
    m_auiWeatherColors[7][4] = 0x71533E;
    m_auiWeatherColors[0][4] = 0x71533E;
    m_auiWeatherColors[7][2] = 0x846D66;
    m_auiWeatherColors[0][2] = 0x846D66;
    m_auiWeatherColors[7][3] = 0x100A05;
    m_auiWeatherColors[0][3] = 0x100A05;
    m_auiWeatherColors[7][5] = 0x100A05;
    m_auiWeatherColors[0][5] = 0x100A05;
    m_auiWeatherColors[8][0] = 0x5F6DB6;
    m_auiWeatherColors[1][0] = 0x5F6DB6;
    m_auiWeatherColors[8][1] = 0xD19A83;
    m_auiWeatherColors[1][1] = 0xD19A83;
    m_auiWeatherColors[8][4] = 0xD19A83;
    m_auiWeatherColors[1][4] = 0xD19A83;
    m_auiWeatherColors[8][2] = 0x5782A8;
    m_auiWeatherColors[1][2] = 0x5782A8;
    m_auiWeatherColors[8][3] = 0x261B0F;
    m_auiWeatherColors[1][3] = 0x261B0F;
    m_auiWeatherColors[8][5] = 0x261B0F;
    m_auiWeatherColors[1][5] = 0x261B0F;
    m_auiWeatherColors[3][0] = 0x252212;
    m_auiWeatherColors[3][1] = 0x857065;
    m_auiWeatherColors[3][4] = 0x857065;
    m_auiWeatherColors[3][2] = 0x35221A;
    m_auiWeatherColors[3][3] = 0x281C15;
    m_auiWeatherColors[3][5] = 0x281C15;
    m_auiWeatherColors[4][0] = 0x79A5FF;
    m_auiWeatherColors[4][1] = 0xCAEDFF;
    m_auiWeatherColors[4][4] = 0xCAEDFF;
    m_auiWeatherColors[4][2] = 0x499AE2;
    m_auiWeatherColors[4][3] = 0x764D34;
    m_auiWeatherColors[4][5] = 0x764D34;
    m_auiWeatherColors[5][0] = 0x779FF2;
    m_auiWeatherColors[5][1] = 0xBED9DE;
    m_auiWeatherColors[5][4] = 0xBED9DE;
    m_auiWeatherColors[5][2] = 0x9DBDFF;
    m_auiWeatherColors[5][3] = 0x000000;
    m_auiWeatherColors[5][5] = 0x000000;
}

// Deletes each TESWeather__WeatherSound in the list, then clears the list with RemoveAll.
// @fnv 0x00581f50
void TESWeather__WeatherSoundList::ClearWeatherSounds()
{
    BSSimpleList<TESWeather__WeatherSound*>* iter = this;
    while (iter && iter->GetItem())
    {
        TESWeather__WeatherSound* sound = iter->GetItem();
        ::operator delete(sound);
        iter = iter->GetNext();
    }
    RemoveAll();
}
// @fnv 0x00580990
bool TESWeather::LoadForm(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x35)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    unsigned int uiChunkID;
    while (uiChunkID = file->GetChunkID())
    {
        switch (uiChunkID)
        {
        case 0x44494445:  // EDID
        {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x44414900: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<WeatherImageSpaceFunctions*>(reinterpret_cast<char*>(this) + sizeof(TESForm))->TESImageSpaceModifiableCountForm_6_SetFormImageSpaceModifying(0, formID);
            break;
        }
        case 0x44414901:
        case 0x4d414e4d:  // MNAM
        {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<WeatherImageSpaceFunctions*>(reinterpret_cast<char*>(this) + sizeof(TESForm))->TESImageSpaceModifiableCountForm_6_SetFormImageSpaceModifying(1, formID);
            break;
        }
        case 0x44414902: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<WeatherImageSpaceFunctions*>(reinterpret_cast<char*>(this) + sizeof(TESForm))->TESImageSpaceModifiableCountForm_6_SetFormImageSpaceModifying(2, formID);
            break;
        }
        case 0x44414903: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<WeatherImageSpaceFunctions*>(reinterpret_cast<char*>(this) + sizeof(TESForm))->TESImageSpaceModifiableCountForm_6_SetFormImageSpaceModifying(3, formID);
            break;
        }
        case 0x44414904: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<WeatherImageSpaceFunctions*>(reinterpret_cast<char*>(this) + sizeof(TESForm))->TESImageSpaceModifiableCountForm_6_SetFormImageSpaceModifying(4, formID);
            break;
        }
        case 0x44414905: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<WeatherImageSpaceFunctions*>(reinterpret_cast<char*>(this) + sizeof(TESForm))->TESImageSpaceModifiableCountForm_6_SetFormImageSpaceModifying(5, formID);
            break;
        }
        case 0x44414906: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<WeatherImageSpaceFunctions*>(reinterpret_cast<char*>(this) + sizeof(TESForm))->TESImageSpaceModifiableCountForm_6_SetFormImageSpaceModifying(6, formID);
            break;
        }
        case 0x4d414e43:  // CNAM
            TESTexture::ReadTextureData(&m_kCloudLayerTextures[1], file);
            break;
        case 0x4d414e44:  // DNAM
            TESTexture::ReadTextureData(&m_kCloudLayerTextures[0], file);
            break;
        case 0x4d414e41:  // ANAM
            TESTexture::ReadTextureData(&m_kCloudLayerTextures[2], file);
            break;
        case 0x4d414e42:  // BNAM
            TESTexture::ReadTextureData(&m_kCloudLayerTextures[3], file);
            break;
        case 0x4d414e45:  // ENAM (legacy fifth texture)
            TESTexture::ReadTextureData(&m_kCloudLayerTextures[4], file);
            break;
            // Retained empty legacy branches present in the original loader.
            break;
            break;
            break;
        case 0x4d414e4f:  // ONAM
            file->GetChunkData(m_aucCloudLayerSpeeds, sizeof(m_aucCloudLayerSpeeds));
            break;
        case 0x4d414e50:  // PNAM
            if (file->GetChunkSize() == sizeof(m_auiCloudLayerColors))
                file->GetChunkData(m_auiCloudLayerColors, sizeof(m_auiCloudLayerColors));
            else if (file->GetChunkSize() == 64)
            {
                unsigned int oldCloudColors[4][4];
                file->GetChunkData(oldCloudColors, sizeof(oldCloudColors));
                for (int layer = 0; layer < 4; ++layer)
                    for (int time = 0; time < 4; ++time)
                        m_auiCloudLayerColors[layer][time] = oldCloudColors[layer][time];
            }
            if (file->IsEndianConversionRequired())
                for (int layer = 0; layer < 4; ++layer)
                    for (int time = 0; time < 6; ++time)
                        BSEndian(&m_auiCloudLayerColors[layer][time], EndianSizeTag<4>());
            break;
        case 0x4c444f4d:  // MODL
            TESModel::LoadModelData(&m_kWeatherModel, file);
            break;
        case 0x304d414e:  // NAM0
            if (file->GetChunkSize() == sizeof(m_auiWeatherColors))
                file->GetChunkData(m_auiWeatherColors, sizeof(m_auiWeatherColors));
            else if (file->GetChunkSize() == 160)
            {
                unsigned int oldColors[10][4];
                file->GetChunkData(oldColors, sizeof(oldColors));
                for (int color = 0; color < 10; ++color)
                    for (int time = 0; time < 4; ++time)
                        m_auiWeatherColors[color][time] = oldColors[color][time];
            }
            if (file->IsEndianConversionRequired())
                for (int color = 0; color < 10; ++color)
                    for (int time = 0; time < 6; ++time)
                        BSEndian(&m_auiWeatherColors[color][time], EndianSizeTag<4>());
            break;
        case 0x41544144:  // DATA
            if (file->GetChunkSize() == sizeof(m_aucWeatherFlags))
                file->GetChunkData(m_aucWeatherFlags, sizeof(m_aucWeatherFlags));
            else if (file->GetChunkSize() == 12)
            {
                file->GetChunkData(m_aucWeatherFlags, 12);
                memset(&m_aucWeatherFlags[12], 255, 3);
            }
            break;
        case 0x4d414e46:  // FNAM
        {
            int count = 6;
            if (file->GetChunkSize() != sizeof(m_afFogDistances))
                count -= 2;
            file->GetChunkData(m_afFogDistances, sizeof(m_afFogDistances));
            if (file->IsEndianConversionRequired())
                for (int i = 0; i < count; ++i)
                    BSEndian(&m_afFogDistances[i], EndianSizeTag<4>());
            break;
        }
        case 0x4d414e48:  // HNAM
            file->GetChunkData(m_afHdrParameters, sizeof(m_afHdrParameters));
            if (file->IsEndianConversionRequired())
                for (int i = 0; i < 14; ++i)
                    BSEndian(&m_afHdrParameters[i], EndianSizeTag<4>());
            break;
        case 0x4d414e49:  // INAM
            file->GetChunkData(m_akImageSpaceModifierParameters, sizeof(m_akImageSpaceModifierParameters));
            if (file->IsEndianConversionRequired())
                for (int i = 0; i < 2; ++i)
                    m_akImageSpaceModifierParameters[i].Endian();
            break;
        case 0x4d414e4c:  // LNAM
            file->GetChunkData(&m_iCloudLayerCount, sizeof(m_iCloudLayerCount));
            if (file->IsEndianConversionRequired())
                BSEndian(&m_iCloudLayerCount, EndianSizeTag<4>());
            break;
        case 0x4d414e53:  // SNAM
        {
            TESWeather__WeatherSound* sound = new TESWeather__WeatherSound;
            file->GetChunkData(sound, sizeof(TESWeather__WeatherSound));
            if (file->IsEndianConversionRequired())
                sound->TwoValues_Endian();
            RemapFormIDForFile(sound->formID, file);
            soundList.AddTail(sound);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x005813b0
TESWeather__WeatherSound::TESWeather__WeatherSound()
{
    memset(this, 0, sizeof(*this));
}

// @fnv 0x005808e0
TESWeather::~TESWeather()
{
    ClearData();
}

void TESForm_AddChunkArray(unsigned int, void*, unsigned int);
void TESForm_AddChunkArray_00485710(unsigned int, unsigned int*, unsigned int);
void TESForm_AddChunk_00485910(unsigned int, int);
void AppendChunk(unsigned int, void*, unsigned int);
bool TESForm_QEndianSwapOnSave();
class WeatherSave : public TESWeather
{
  public:
    void TESWeather_Save();
};
// @fnv 0x005813d0
// src: XBOX_PDB 0x005813d0
void WeatherSave::TESWeather_Save()
{
    TESForm::BeginFormRecord();
    reinterpret_cast<WeatherImageSpaceFunctions*>(reinterpret_cast<char*>(this) + sizeof(TESForm))->ReleaseSoundSlots();
    unsigned int auiChunkIds[8] = {0x4d414e44, 0x4d414e43, 0x4d414e41, 0x4d414e42,
                                   0x4d414e45, 0x4d414e47, 0x4d414e4a, 0x4d414e4b};
    for (int i = 0; i < m_iCloudLayerCount; ++i)
        m_kCloudLayerTextures[i].Save(auiChunkIds[i]);
    m_kWeatherModel.WriteToBuffer(0x4c444f4d, 0x54444f4d);
    TESForm_AddChunk_00485910(0x4d414e4c, m_iCloudLayerCount);
    TESForm_AddChunkArray(0x4d414e4f, m_aucCloudLayerSpeeds, 4);
    TESForm_AddChunkArray_00485710(0x4d414e50, &m_auiCloudLayerColors[0][0], 24);
    TESForm_AddChunkArray_00485710(0x304d414e, &m_auiWeatherColors[0][0], 60);
    TESForm_AddChunkArray_00485710(0x4d414e46, reinterpret_cast<unsigned int*>(m_afFogDistances), 6);
    if (TESForm_QEndianSwapOnSave())
    {
        for (unsigned int j = 0; j < 2; ++j)
            m_akImageSpaceModifierParameters[j].Endian();
    }
    AppendChunk(0x4d414e49, m_akImageSpaceModifierParameters, 304);
    if (TESForm_QEndianSwapOnSave())
    {
        for (unsigned int k = 0; k < 2; ++k)
            m_akImageSpaceModifierParameters[k].Endian();
    }
    TESForm_AddChunkArray(0x41544144, m_aucWeatherFlags, 15);
    for (BSSimpleList<TESWeather__WeatherSound*>* node = &soundList; node && node->GetItem(); node = node->GetNext())
    {
        if (TESForm_QEndianSwapOnSave())
            node->GetItem()->TwoValues_Endian();
        AppendChunk(0x4d414e53, node->GetItem(), 8);
        if (TESForm_QEndianSwapOnSave())
            node->GetItem()->TwoValues_Endian();
    }
    TESForm::FinishFormRecord();
}

extern "C" int memcmp(const void* buf1, const void* buf2, unsigned int count);

class TESRegionData;

#include "../../include/BSSimpleList.h"

class FUN_005e79a0_t
{
  public:
    bool TESForm_CompareAllComponents(TESForm* form);
};

class WeatherEq : public TESWeather
{
  public:
    bool IsDifferentFrom(TESForm* pOther);
};

// @fnv 0x00581880
bool WeatherEq::IsDifferentFrom(TESForm* pOther)
{
    TESWeather* other = dynamic_cast<TESWeather*>(pOther);
    if (!other)
        return 1;
    BSSimpleList<TESRegionData*>* otherList3 = (BSSimpleList<TESRegionData*>*)&other->soundList;
    BSSimpleList<TESRegionData*>* thisList2 = (BSSimpleList<TESRegionData*>*)&this->soundList;
    if (otherList3->ItemsInList() == thisList2->ItemsInList())
    {
        while (otherList3 != 0 && thisList2 != 0 && otherList3->GetItem() != 0 && thisList2->GetItem() != 0)
        {
            if (memcmp(otherList3->GetItem(), thisList2->GetItem(), 8) != 0)
                return 1;
            otherList3 = otherList3->GetNext();
            thisList2 = thisList2->GetNext();
        }
    }
    else
    {
        return 1;
    }
    if (this->m_iCloudLayerCount == other->m_iCloudLayerCount)
    {
        for (int i3 = 0; i3 < this->m_iCloudLayerCount; ++i3)
        {
            if (m_kCloudLayerTextures[i3].CompareWithBase(&other->m_kCloudLayerTextures[i3]))
                return 1;
        }
    }
    else
    {
        return 1;
    }
    return ((FUN_005e79a0_t*)this)->TESForm_CompareAllComponents(other) || m_kWeatherModel.CompareWithBase(static_cast<BaseFormComponent*>(&other->m_kWeatherModel)) ||
           memcmp(this->m_aucWeatherFlags, other->m_aucWeatherFlags, 15) != 0 ||
           memcmp(this->m_auiWeatherColors, other->m_auiWeatherColors, 240) != 0 ||
           memcmp(this->m_afFogDistances, other->m_afFogDistances, 24) != 0 ||
           memcmp(this->m_aucCloudLayerSpeeds, other->m_aucCloudLayerSpeeds, 4) != 0 ||
           memcmp(this->m_auiCloudLayerColors, other->m_auiCloudLayerColors, 96) != 0 ||
           memcmp(this->m_akImageSpaceModifierParameters, other->m_akImageSpaceModifierParameters, 304) != 0;
}

#include <string.h>
struct FUN_004b0680
{
    unsigned int formID;
    unsigned int type;
    FUN_004b0680(unsigned int formID, unsigned int type);
};

class WeatherCopy : public TESWeather
{
  public:
    void TESForm_CopyAllComponents(TESForm* source);
    void TESWeather_Copy(TESForm* source);
};

// Copies weather data from a source TESWeather into this WeatherCopy, including cloud layers, model, flags, colors, fog, image space modifiers, and sound list.
// @fnv 0x00581630
// src: XBOX_PDB 0x00581630
void WeatherCopy::TESWeather_Copy(TESForm* source)
{
    TESWeather* weather = dynamic_cast<TESWeather*>(source);
    if (!weather)
        return;
    TESForm_CopyAllComponents(weather);
    m_iCloudLayerCount = weather->m_iCloudLayerCount;
    for (int i = 0; i < m_iCloudLayerCount; ++i)
        m_kCloudLayerTextures[i].CopyFromBase(&weather->m_kCloudLayerTextures[i]);
    m_kWeatherModel.CopyFromBase(static_cast<BaseFormComponent*>(&weather->m_kWeatherModel));
    memcpy(m_aucCloudLayerSpeeds, weather->m_aucCloudLayerSpeeds, 4);
    memcpy(m_auiCloudLayerColors, weather->m_auiCloudLayerColors, 96);
    memcpy(m_aucWeatherFlags, weather->m_aucWeatherFlags, 15);
    memcpy(m_auiWeatherColors, weather->m_auiWeatherColors, 240);
    memcpy(m_afFogDistances, weather->m_afFogDistances, 24);
    memcpy(m_akImageSpaceModifierParameters, weather->m_akImageSpaceModifierParameters, 304);
    soundList.RemoveAll();
    for (BSSimpleList<TESWeather__WeatherSound*>* node = &weather->soundList; node && node->GetItem();
         node = node->GetNext())
    {
        TESWeather__WeatherSound* sound = reinterpret_cast<TESWeather__WeatherSound*>(
            new FUN_004b0680(node->GetItem()->formID, node->GetItem()->type));
        soundList.AddTail(sound);
    }
}
