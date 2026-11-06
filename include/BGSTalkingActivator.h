#pragma once

#include "TESObjectACTI.h"

class BGSVoiceType;
class RadioStationRef;
class RefStub;
class TESObjectREFR;
template <class T> class BSSimpleList;

class BGSTalkingActivator : public TESObjectACTI
{
public:
    BGSTalkingActivator();

    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void InitItem(void);

    virtual bool IsRadioStationObject() const;
    virtual bool GetReflectedByAutoWater() const;

    void ResetFormData();
    bool Load(TESFile* file);
    void SetRadioTemplate(TESSound* apSound);
    void SetVoiceType(BGSVoiceType* apVoice);
    bool IsRadioStation();
    bool IsRadioStation() const;
    TESObjectREFR* GetTempRef() const;
    RefStub* GetTempRef();

    static bool IsRadioStation(TESForm* form, unsigned int flags);
    static void AddRadioStation(TESObjectREFR* reference);
    static void FindRadioStations(TESObjectREFR* reference,
                                  BSSimpleList<TESObjectREFR*>* stations,
                                  BSSimpleList<float>* distances);
    static void FindRadioStations(TESObjectREFR* reference,
                                  BSSimpleList<RadioStationRef*>* stations,
                                  BSSimpleList<float>* distances);
    static BSSimpleList<TESObjectREFR*> ms_kRadioStations;

    TESObjectREFR* m_pTempRef;    // 0x90
    BGSVoiceType* m_kFactionList; // 0x94
};
