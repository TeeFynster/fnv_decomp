// fallout/misc/saveload/bgssaveloaddefines.cpp: SaveGameSizeState (15 functions)

#include "../../../../include/TESForm.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/SIZE_TYPE.h"
#include <string.h>

void LogWarning(const char* message, ...);

class TESObjectCELL;
class TESWorldSpace;

class SaveGameSizeState
{
  public:
    virtual void UnknownSlot();
    virtual unsigned int Write(unsigned int size);
    unsigned int iSize;
    unsigned int iPosition;
    unsigned int iDataLength;
    void RecordSizeAndLength(unsigned int size, unsigned int length);
    void RecordRequestedSize(unsigned int requested, unsigned int savedSize);
};

class SaveLoadFile
{
  public:
    unsigned int Read(void* buffer, unsigned int size);
};

// @fnv 0x008453a0
void SaveGameSizeState::RecordRequestedSize(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        RecordSizeAndLength(iSize, savedSize);
        iPosition = savedSize;
    }
}

// @fnv 0x00845e50
unsigned int ReadSizedUnsignedInt(SaveLoadFile* file, unsigned int& value, SIZE_TYPE sizeType)
{
    switch (sizeType)
    {
    case SIZE_TYPE_SIZE_CHAR: {
        unsigned char ucByte = 0;
        file->Read(&ucByte, 1);
        value = ucByte;
        return 1;
    }
    case SIZE_TYPE_SIZE_SHORT: {
        unsigned short usShort = 0;
        file->Read(&usShort, 2);
        value = usShort;
        return 2;
    }
    case SIZE_TYPE_SIZE_INT:
        file->Read(&value, 4);
        return 4;
    default:
        return 0;
    }
}

// @fnv 0x00845f70
unsigned int GetEncodedIntegerSize(unsigned int value)
{
    unsigned int type = 0;
    if (value < 0x40)
    {
        type = 1;
    }
    else if (value < 0x4000)
    {
        type = 2;
    }
    else if (value < 0x40000000)
    {
        type = 4;
    }
    type += 1;
    return type;
}

// Checks the form type: stores the form as world if type 0x41, as cell if type 0x39, and returns whether either matched.
// @fnv 0x00846190
bool GetCellAndWorldspaceForForm(TESForm* form, TESObjectCELL*& cell, TESWorldSpace*& world)
{
    if (!form)
    {
        return false;
    }
    if (static_cast<const TESForm*>(form)->GetFormType() == 0x41)
    {
        world = (TESWorldSpace*)form;
        return true;
    }
    else if (static_cast<const TESForm*>(form)->GetFormType() == 0x39)
    {
        cell = (TESObjectCELL*)form;
        return true;
    }
    return false;
}

#include <string.h>

void LogWarning(const char* message, ...);

class TESObjectCELL;
class TESWorldSpace;

// Encodes value into buffer using 1, 2 or 4 bytes depending on its magnitude, logs an error if too large, then appends '|'.
// @fnv 0x00845fc0
void WriteEncodedInteger(char* buffer, unsigned int value)
{
    unsigned int size = 0;
    if (value < 0x40)
    {
        unsigned char encoded = (unsigned char)(value << 2);
        size = 1;
        memcpy(buffer, &encoded, size);
    }
    else if (value < 0x4000)
    {
        unsigned short encoded = (unsigned short)((value << 2) | 1);
        size = 2;
        memcpy(buffer, &encoded, size);
    }
    else if (value < 0x40000000)
    {
        unsigned int encoded = (value << 2) | 2;
        size = 4;
        memcpy(buffer, &encoded, size);
    }
    else
    {
        LogWarning("SAVELOAD: Variable-sized value %08X is too large to be stored.", value);
    }
    buffer[size] = '|';
}

// @fnv 0x00846080
unsigned int ReadEncodedInteger(char* buffer, unsigned int& value)
{
    unsigned int size;
    unsigned char encodedType;
    unsigned int type;
    type = 0;
    encodedType = buffer[0];
    size = encodedType & 3;
    switch (size)
    {
    case 0: {
        char encoded = 0;
        type = 1;
        memcpy(&encoded, buffer, type);
        encoded = (unsigned char)encoded >> 2;
        value = (unsigned char)encoded;
        break;
    }
    case 1: {
        unsigned short encoded = 0;
        type = 2;
        memcpy(&encoded, buffer, type);
        encoded = (unsigned short)(encoded >> 2);
        value = encoded;
        break;
    }
    case 2: {
        unsigned int encoded = 0;
        type = 4;
        memcpy(&encoded, buffer, type);
        encoded >>= 2;
        value = encoded;
        break;
    }
    }
    if (buffer[type] != '|')
    {
        LogWarning("SAVELOAD: Invalid spacer hit while loading data from the buffer");
    }
    type += 1;
    return type;
}


MemoryManager* __cdecl MemoryManager_Instance(void);

// @fnv 0x00401030
// src: COMMUNITY 0x00401030
void __cdecl FormHeapFreeAndLog_00401030(void* ptr)
{
    MemoryManager_Instance()->Deallocate(ptr);
}

// @fnv 0x00845d20
void ReadFileIntoBuffer(SaveLoadFile* file, unsigned int* apuiBuffer, unsigned int size)
{
    file->Read(apuiBuffer, size);
}

extern unsigned int DAT_011a2040[];

// @fnv 0x00845d70
// src: XBOX_PDB 0x00845d70
unsigned int GetSizeTypeSize(unsigned int index)
{
    return DAT_011a2040[index];
}

void* __cdecl _memcpy(void* dst, const void* src, unsigned int size);

// Copies value into dst as 1, 2 or 4 bytes depending on sizeType (0, 1 or 2).
// @fnv 0x00845de0
void __cdecl WriteTypedValue(void* apDest, unsigned int value, unsigned int sizeType)
{
    switch (sizeType)
    {
    case 0: {
        unsigned char c = (unsigned char)value;
        _memcpy(apDest, &c, 1);
        break;
    }
    case 1: {
        unsigned short s = (unsigned short)value;
        _memcpy(apDest, &s, 2);
        break;
    }
    case 2:
        _memcpy(apDest, (void*)&value, 4);
        break;
    }
}

struct FUN_00846330_shell
{
    void WriteToFile(int a, int b);
};

// @fnv 0x00845d00
void ForwardToShell(FUN_00846330_shell* apShell, int aiArg1, int aiArg2)
{
    apShell->WriteToFile(aiArg1, aiArg2);
}

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
// @fnv 0x00845cc0
// src: XBOX_PDB 0x00845cc0
void __cdecl SaveGameWarning(const char* apMessage, ...)
{
    char* varArgs;
    varArgs = (char*)&apMessage + 4;
    if (g_BGSSaveLoadGame)
        g_BGSSaveLoadGame->SaveGameWarningFunction(apMessage, varArgs);
    varArgs = 0;
}

// @fnv 0x00845d40
// src: COMMUNITY 0x00845d40
unsigned int GetSizeTypeForSize(unsigned int value)
{
    if (value <= 0xff)
        return 0;
    else if (value <= 0xffff)
        return 1;
    return 2;
}

void* __cdecl __memcpy(void* dest, const void* src, unsigned int size);

// Copies 1, 2 or 4 bytes from source into value according to sizeType and returns the number of bytes copied, or 0 for other size types.
// @fnv 0x00845ee0
unsigned int ReadValueBySizeType(const void* source, unsigned int* value, unsigned int sizeType)
{
    switch (sizeType)
    {
    case SIZE_TYPE_SIZE_CHAR: {
        unsigned char c = 0;
        __memcpy(&c, source, 1);
        *value = c;
        return 1;
    }
    case SIZE_TYPE_SIZE_SHORT: {
        unsigned short s = 0;
        __memcpy(&s, source, 2);
        *value = s;
        return 2;
    }
    case SIZE_TYPE_SIZE_INT:
        __memcpy(value, source, 4);
        return 4;
    default:
        return 0;
    }
}

namespace fnv_00845d80 {
struct FUN_00846330_shell
{
    void WriteToFile(int, int);
};

// @fnv 0x00845d80
void WriteValueByType(FUN_00846330_shell* self, unsigned short ausValue, int type)
{
    switch (type)
    {
    case 0: {
        char b = ausValue;
        self->WriteToFile((int)&b, 1);
        break;
    }
    case 1: {
        short s = ausValue;
        self->WriteToFile((int)&s, 2);
        break;
    }
    case 2:
        self->WriteToFile((int)&ausValue, 4);
        break;
    }
}
}  // namespace fnv_00845d80
