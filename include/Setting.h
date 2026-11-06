#pragma once

#include "SETTING_VALUE.h"

template <class T> class NiTPrimitiveArray;

// RTTI: .?AVSetting@@ (a class).
class Setting
{
public:
    SETTING_VALUE uValue;
    const char* pKey;

    Setting();
    Setting(const char* key, float value);
    Setting(const char* key, int value);
    Setting(const char* key, char* value);

    virtual ~Setting();
    virtual bool IsPrefSetting();

    bool IsPrefSetting() const;
    const char* Name();
    const char* GetString();
    const char* String();
    float* Float();
    int* Int();
    bool* Bool();
    float* GetFloat();
    const unsigned char* Get();
    unsigned int* GetPtr();
    unsigned int GetUInt();
    unsigned int GetFormatSize();
    bool GetBoolValue();
    bool FUN_00403e60(unsigned int value);

    unsigned int FUN_004f8940();
    Setting& FUN_00c33170(const char* value);
    Setting& FUN_005e0190(const char* value);
    void FUN_00404950();
    void* FUN_004049a0(unsigned int flags);
    void FUN_00c33280(NiTPrimitiveArray<char*>* values);
    float* FUN_00403e20();
    int* FUN_0043d4d0();
    const char* FUN_00403df0();
    bool* FUN_00408d60();
    const char* FUN_004c69f0();
    void FUN_0045ce80(int value);
};
