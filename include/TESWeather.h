#pragma once

#include "TESForm.h"
#include "BaseFormComponent.h"
#include "TESTexture1024.h"
#include "TESModel.h"
#include "TESWeather__WeatherSoundList.h"
#include "ImageSpaceModifierParameterData.h"

class TESImageSpaceModifier;

template <unsigned int Count>
class TESImageSpaceModifiableCountForm : public BaseFormComponent
{
public:
    TESImageSpaceModifiableCountForm();
    void InitItem(TESForm* form);

    TESImageSpaceModifier* m_pImageSpaceModifier[Count];
};

struct TESWeather : public TESForm, public TESImageSpaceModifiableCountForm<6>
{
public:
    class WeatherSound;

    TESWeather();
    virtual ~TESWeather();

    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual void InitItem();

    void ResetFormData();
    void MakeDefault();
    bool Load(TESFile* file);
    TESTexture1024* GetCloudTexture(int);
    float GetCloudLayerSpeed(int, float, float);
    bool IsRainy();
    float GetWeatherData(int data, float maximum, float minimum);
    unsigned char GetWeatherDataRaw(int);

    TESTexture1024 m_kCloudLayerTextures[4];
    unsigned char m_aucCloudLayerSpeeds[4];
    unsigned int m_auiCloudLayerColors[4][6];
    TESModel m_kWeatherModel;
    unsigned char m_aucWeatherFlags[15];
    unsigned char layoutPaddingEF[1];
    float m_afFogDistances[6];
    unsigned int m_auiWeatherColors[10][6];
    TESWeather__WeatherSoundList soundList;
    float m_afHdrParameters[14];
    ImageSpaceModifierParameterData m_akImageSpaceModifierParameters[2];
    int m_iCloudLayerCount;
};
