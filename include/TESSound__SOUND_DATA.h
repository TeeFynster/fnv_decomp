#pragma once

class TESSound__SOUND_DATA
{
public:
    unsigned char minAttenuation;
    unsigned char maxAttenuation;
    signed char frequencyAdjustment;
    unsigned char unk03;
    unsigned int soundFlags;
    unsigned short staticAttenuation;
    unsigned short stopTime;
    unsigned short attenuationCurve[5];
    unsigned short reverbAttenuation;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    signed char frequencyVariance;

    void Endian();
    void SwapEndian();
};
