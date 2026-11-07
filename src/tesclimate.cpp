// tesclimate.cpp: TESClimate (12 functions)

#include <windows.h>
#include "layout_support.h"
#include "../include/FileEntryList.h"
#include "../include/TESForm.h"
#include "../include/TESFile.h"
#include "../include/TESModel.h"
#include "../include/TESTexture.h"
#include "../include/TESWeather.h"
#include "tesclimate_types.h"
#include <string.h>
#include <new>

// @fnv 0x0052aaa0
TESClimate::TESClimate()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x36));
    ResetFormData();
}

// @fnv 0x0052ac20
void TESClimate::ResetFormData()
{
    memset(m_ucTimeSettings, 0, sizeof(m_ucTimeSettings));
    SetMoonPhaseDays(3);
}

// @fnv 0x0052b0f0
void TESClimate::MakeDefault()
{
    m_kSunTextures[0].AssignTextureName("Sky\\Sun.dds");
    m_kSunTextures[1].AssignTextureName("Sky\\SunGlare.dds");
    m_kStarsModel.SetModelFilePath("Sky\\Stars.nif");
    m_ucTimeSettings[0] = 36;
    m_ucTimeSettings[1] = 42;
    m_ucTimeSettings[2] = 108;
    m_ucTimeSettings[3] = 114;
    m_ucTimeSettings[4] = 0;
    SetUsesMasser(true);
    SetUsesSecunda(true);
    SetMoonPhaseDays(3);
    weatherList.RemoveAll();
    WeatherEntry* weather = new WeatherEntry;
    weather->m_pWeatherObject = dynamic_cast<TESWeather*>(TESForm::GetFormByID(0x15e));
    weather->m_uiWeatherChance = 100;
    if (weather->m_pWeatherObject)
        weatherList.AddHead(weather);
    else
    {
        delete weather;
        Warning("DEFAULT: Unable to add default weather to default climate.  ( TESClimate::MakeDefault() )");
    }
}

#include <malloc.h>
// @fnv 0x0052ac90
bool TESClimate::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x36)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x54534c57: {
            int warnings = Warning();
            SetWarningState(true);
            TESWeatherList::LoadWeatherEntries(&weatherList, file, this);
            SetWarningState(false);
            if (Warning() > warnings)
                Warning("MASTERFILE: Warnings were encountered while loading weather list chunk from climate %s",
                        GetName());
        }
        break;
        case 0x4d414e46:
        case 0x4d414e47:
        case 0x4d414e48:
        case 0x4d414e49:
        case 0x4d414e4a:
        case 0x4d414e4b:
        case 0x4d414e4c:
        case 0x4d414e4d:
        case 0x4d414e4e:
        case 0x4d414e4f:
        case 0x4d414e50:
            if (chunk - 0x4d414e46 < 2)
                TESTexture::ReadTextureData(&m_kSunTextures[chunk - 0x4d414e46], file);
            break;
        case 0x4c444f4d:
            TESModel::LoadModelData(&m_kStarsModel, file);
            break;
        case 0x4d414e54:
            file->GetChunkData(m_ucTimeSettings, 6);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0052b260
void TESClimate::SetUsesMasser(bool abUses)
{
    abUses ? m_ucTimeSettings[5] |= 0x80 : m_ucTimeSettings[5] &= ~0x80;
}

// @fnv 0x0052b2c0
void TESClimate::SetUsesSecunda(bool abUses)
{
    abUses ? m_ucTimeSettings[5] |= 0x40 : m_ucTimeSettings[5] &= ~0x40;
}

int __cdecl MinInt(int, int);

// @fnv 0x0052ac50
void TESClimate::SetMoonPhaseDays(unsigned int auiDays)
{
    m_ucTimeSettings[5] = (m_ucTimeSettings[5] & 0xC0) | MinInt(auiDays, 0xFFFFFF3F);
}

void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);

// @fnv 0x0052ae80
void TESClimate::SaveForm()
{
    TESForm::BeginFormRecord();
    weatherList.WriteWeatherList(0x54534c57);
    int i = 0;
    for (; i < 2; ++i)
        m_kSunTextures[i].Save(0x4d414e46 + i);
    m_kStarsModel.WriteToBuffer(0x4c444f4d, 0x54444f4d);
    TESForm_AddChunkArray(0x4d414e54, m_ucTimeSettings, 6);
    TESForm::FinishFormRecord();
}

// @fnv 0x0052afe0
bool TESClimate::Compare(TESForm* apCompare)
{
    int iIndex;
    TESClimate* i = dynamic_cast<TESClimate*>(apCompare);

    if (!i)
        return true;

    if (TESForm::Compare(i))
        return true;

    for (iIndex = 0; iIndex < 2; ++iIndex)
    {
        if (m_kSunTextures[iIndex].CompareWithBase(static_cast<BaseFormComponent*>(&i->m_kSunTextures[iIndex])))
            return true;
    }

    if (m_kStarsModel.CompareWithBase(static_cast<BaseFormComponent*>(&i->m_kStarsModel)))
        return true;

    if (weatherList.IsDifferentFrom(&i->weatherList))
        return true;

    if (memcmp(m_ucTimeSettings, i->m_ucTimeSettings, 6) != 0)
        return true;

    return false;
}

// @fnv 0x0052ab80
TESClimate::~TESClimate()
{
    TESForm::ClearData();
}

// @fnv 0x0052af10
void TESClimate::CopyFrom(const TESForm* source)
{
    TESClimate* climate;
    climate = dynamic_cast<TESClimate*>(const_cast<TESForm*>(source));
    if (!climate)
        return;

    TESForm::CopyFrom(climate);
    weatherList.CopyWeatherList(&climate->weatherList, false);

    {
        int i;
        for (i = 0; i < 2; ++i)
            m_kSunTextures[i].CopyFromBase(static_cast<BaseFormComponent*>(&climate->m_kSunTextures[i]));
    }

    m_kStarsModel.CopyFromBase(static_cast<BaseFormComponent*>(&climate->m_kStarsModel));
    memcpy(m_ucTimeSettings, climate->m_ucTimeSettings, 6);
}
