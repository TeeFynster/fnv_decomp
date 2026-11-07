#pragma once

class Actor;
class NiPoint3;
class NiQuaternion;
class SaveLoadFile;
class TESForm;
class TESObjectREFR;
class NiMatrix3;
class hkVector4;

class BGSSaveGameBuffer
{
public:
    typedef ::TESForm TESForm;
    typedef ::TESObjectREFR TESObjectREFR;
    typedef ::Actor Actor;

    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();

    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int iBufferPosition;
    unsigned int iDebugOverhead;

    BGSSaveGameBuffer();
    ~BGSSaveGameBuffer();

    void Save(SaveLoadFile*, unsigned int);
    void Save(SaveLoadFile*);
    unsigned int GetBufferPosition();
    char* GetBuffer();
    void ClearPosition();
    unsigned int GetDataSize();
    unsigned int GetDebugOverhead();
    void SaveData(NiQuaternion*, unsigned int, unsigned int);
    void SaveData(hkVector4*, unsigned int, unsigned int);
    void SaveData(double*, unsigned int, unsigned int);
    void SaveData(NiPoint3*, unsigned int, unsigned int);
    void SaveData(float*, unsigned int, unsigned int);
    void SaveData(unsigned long*, unsigned int, unsigned int);
    void SaveData(long*, unsigned int, unsigned int);
    void SaveData(unsigned int*, unsigned int, unsigned int);
    void SaveData(int*, unsigned int, unsigned int);
    void SaveData(unsigned short*, unsigned int, unsigned int);
    void SaveData(short*, unsigned int, unsigned int);
    void SaveData(NiMatrix3*, unsigned int, unsigned int);
    void SaveData(void*, unsigned int, unsigned int);
    void SaveData(void*, unsigned int, unsigned int, unsigned int);
    void SaveData(void*, int, int);
    void SerializeFormData(TESForm*, unsigned int);
    void SerializeFormData(unsigned int, unsigned int);
    void SerializeFormData(void*, int);
    void SaveGameString(char*, unsigned int);
    void SaveGameString(const char*, int);
    unsigned int GetBufferLength();
    void SetBufferPosition(unsigned int, unsigned int);
    void SetBufferPosition(unsigned int);
    void CopyBufferData(void*, unsigned int, unsigned int, unsigned int, unsigned int);
    void CopyBufferData(void*, unsigned int, unsigned int, unsigned int);
    void WriteBufferData(void*, unsigned int, bool);
    void WriteBufferData(void*, unsigned int, unsigned int, bool);
    void ReleaseBufferContents();
    void ShiftBuffer(unsigned int, int);
    void WriteAtOffset(void*, unsigned int, unsigned int);
    void FUN_00865c40(void*);
    unsigned int StartVariableSizedValue();
    void SaveVariableSizedValue_00865ff0(unsigned int, unsigned int);
    void SaveVariableSizedValue(unsigned int);
};
