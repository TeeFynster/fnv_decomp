#pragma once

class NiUpdateData
{
public:
    union
    {
        float fTime;
        struct
        {
            unsigned char unk00;
            bool m_bUpdateEnabled;
            bool m_bVisible;
            char pad0;
        };
    };
    char pad1;
    char pad2;
    char pad3;
    char pad4;
    char pad5;
    char pad6;
    char pad7;
    char pad8;

    NiUpdateData();
    NiUpdateData(float time);
    NiUpdateData(float time, bool updateControllers, bool isMultiThreaded);
    NiUpdateData(float time, int updateControllers, int updateGeometry);
    NiUpdateData(float time, bool updateControllers, int flags);

    void FUN_0043d410(float time, bool updateControllers, bool isMultiThreaded);

    const float& GetTime() const { return fTime; }
};
