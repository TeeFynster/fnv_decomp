#pragma once


class BSSysInfoSystemUtility
{
public:
    enum LANGUAGE
    {
        LANGUAGE_JAPANESE = 0,
        LANGUAGE_ENGLISH = 1,
        LANGUAGE_FRENCH = 2,
        LANGUAGE_SPANISH = 3,
        LANGUAGE_GERMAN = 4,
        LANGUAGE_ITALIAN = 5,
        LANGUAGE_DUTCH = 6,
        LANGUAGE_PORTUGUESE = 7,
        LANGUAGE_RUSSIAN = 8,
        LANGUAGE_KOREAN = 9,
        LANGUAGE_CHINESE_TRADITIONAL = 10,
        LANGUAGE_CHINESE_SIMPLIFIED = 11,
        LANGUAGE_FINNISH = 12,
        LANGUAGE_SWEDISH = 13,
        LANGUAGE_DANISH = 14,
        LANGUAGE_NORWEGIAN = 15,
        LANGUAGE_UNKNOWN = 16,
        MAX_LANGUAGES = 17,
    };

    virtual void* vf00(unsigned int flags);
    virtual void Initialize();
    virtual void Destroy();

    LANGUAGE m_eLanguage;
    unsigned int SystemUtilityData[16];

    static unsigned int GetRandomGenerator();
};
