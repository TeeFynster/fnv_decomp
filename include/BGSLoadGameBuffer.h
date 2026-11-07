#pragma once

class Actor;
class NiPoint3;
class NiQuaternion;
class SaveLoadFile;
class TESForm;
class TESObjectREFR;
class NiMatrix3;
class hkVector4;

class BGSLoadGameBuffer
{
public:
    typedef ::TESForm TESForm;
    typedef ::TESObjectREFR TESObjectREFR;
    typedef ::Actor Actor;

    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();

    char* pBuffer;
    unsigned int iBufferSize;
    union
    {
        unsigned int iBufferPosition;
        unsigned int m_uiReadOffset;
    };

    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();

    void BGSSaveLoadFile_SetSaveFileName(SaveLoadFile* file);
    bool BGSSaveLoadFile_Open();
    void LoadData(void* data, unsigned int size);

    int Load();
    int Load(SaveLoadFile* file);
    int Load(SaveLoadFile* file, unsigned int size);
    void ReadAndVerifySize(SaveLoadFile* file);
    void ResetReadPosition();
    void SetBuffer(char* buffer, unsigned int size, unsigned int position);
    char* GetCurrentBufferPointer();
    char* GetCombinedValue();

    bool ReadFormIdentifier(unsigned int* identifier);
    bool ReadFormIdentifier(void* identifier);
    unsigned int ReadFormIdentifier();

    char* __cdecl ReadTypedData(char* value);
    void ReadTypedData(NiQuaternion* value, unsigned int count);
    void ReadTypedData(hkVector4* value, unsigned int count);
    void ReadTypedData(double* value, unsigned int count);
    void ReadTypedData(NiPoint3* value, unsigned int count);
    void ReadTypedData(float* value, unsigned int count);
    void ReadTypedData(unsigned long* value, unsigned int count);
    void ReadTypedData(long* value, unsigned int count);
    void ReadTypedData(unsigned int* value, unsigned int count);
    void ReadTypedData(int* value, unsigned int count);
    void ReadTypedData(unsigned short* value, unsigned int count);
    void ReadTypedData(short* value, unsigned int count);
    void ReadTypedData(NiMatrix3* value, unsigned int count);
    void ReadTypedData(void* value, unsigned int count);

    char* LoadString(char* string);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int bytes);
    void ReadElementData(void* data, unsigned int size, unsigned int flags);
    void ReadDataBlock(void* data, unsigned int size);
};
