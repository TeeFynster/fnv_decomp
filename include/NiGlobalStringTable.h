#pragma once

typedef char* GlobalStringHandle;

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

class NiGlobalStringTable
{
  public:
    void AddString(); // exe: 0x004f31b0, increments +0x68
    char* NiGlobalStringTable_FindString(const char*, unsigned); // exe: 0x00a5b300
    void NiGlobalStringTable_InsertString(char**, unsigned); // exe: 0x00a5b5a0
    static GlobalStringHandle AddString(const char* pcString);
    static void IncRefCount(GlobalStringHandle& kHandle);
    static void DecRefCount(GlobalStringHandle& kHandle);
    static const char* GetString(const GlobalStringHandle& kHandle);
    static char* GetRealBufferStart(const GlobalStringHandle& kHandle);

    static GlobalStringHandle ms_pcEmptyString;
};

inline const char* NiGlobalStringTable::GetString(const GlobalStringHandle& kHandle)
{
    return kHandle;
}

inline char* NiGlobalStringTable::GetRealBufferStart(const GlobalStringHandle& kHandle)
{
    return kHandle - 2 * sizeof(unsigned int);
}

inline void NiGlobalStringTable::IncRefCount(GlobalStringHandle& kHandle)
{
    if (kHandle == ms_pcEmptyString)
        return;
    unsigned int* pkMem = (unsigned int*)GetRealBufferStart(kHandle);
    InterlockedIncrement((long volatile*)&pkMem[0]);
}

inline void NiGlobalStringTable::DecRefCount(GlobalStringHandle& kHandle)
{
    if (kHandle == ms_pcEmptyString)
        return;
    unsigned int* pkMem = (unsigned int*)GetRealBufferStart(kHandle);
    InterlockedDecrement((long volatile*)&pkMem[0]);
}
