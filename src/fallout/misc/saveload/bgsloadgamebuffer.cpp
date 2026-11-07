
// src/fallout/misc/saveload/bgsloadgamebuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/saveload/bgsloadgamebuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/IntSeenData.h"
#include "../../../../include/NiQuaternion.h"

struct FUN_00835f80_shell
{
    char _0[0x1c];
    char _1c;
    char _1d;
    char _1e;
    char _1f;
    void DynamicRadio_Load(BGSLoadFormBuffer* apBuffer);
};

// @fnv 0x00835f80
// src: COMMUNITY 0x00835f80
void __thiscall FUN_00835f80_shell::DynamicRadio_Load(BGSLoadFormBuffer* apBuffer)
{
    apBuffer->ReadFormIdentifier(this);
    apBuffer->ReadTypedData(&this->_1c, 1u);
    apBuffer->ReadTypedData(&this->_1d, 1u);
    apBuffer->ReadTypedData(&this->_1e, 1u);
    apBuffer->ReadTypedData(&this->_1f, 1u);
}

BGSSaveLoadGame* g_BGSSaveLoadGame;

// @fnv 0x00864720
unsigned char BGSLoadGameBuffer::GetVersion()
{
    return g_BGSSaveLoadGame->GetLoadState();
}

// Initializes the load buffer with the given buffer pointer, size and position.
// @fnv 0x008647f0
void BGSLoadGameBuffer::SetBuffer(char* apBuffer, unsigned int aiSize, unsigned int aiPosition)
{
    pBuffer = apBuffer;
    iBufferSize = aiSize;
    iBufferPosition = aiPosition;
}

// @fnv 0x00864980
// src: XBOX_PDB 0x00864980
void BGSLoadGameBuffer::LoadData(void* apData, unsigned int aiSize)
{
    ReadTypedData(static_cast<NiQuaternion*>(apData), aiSize);
}

class BGSSaveFormBuffer;
namespace fnv_009f38b0 {
struct blob4
{
    char b[4];
};
struct SandboxProcedureData
{
    TESObjectREFR* GetTarget();
    int GetSandboxProcedure();
    int GetBaseScore();
    int GetFullScore();
    void SetFullScore(int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    TESObjectREFR* pTarget;
    int eProcedure;
    int m_iActivityState;
    int m_iProcedureData;
};
typedef char _sizecheck_SandBoxChoiceListItem[sizeof(SandboxProcedureData) == 16 ? 1 : -1];
struct FUN_009f38b0_shell : public SandboxProcedureData
{
    void SandBoxChoiceListItem_LoadGame(BGSLoadFormBuffer*);
};

// @fnv 0x009f38b0
// src: XBOX_PDB 0x009f38b0
void FUN_009f38b0_shell::SandBoxChoiceListItem_LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&eProcedure), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_iActivityState), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_iProcedureData), 4u);
    apLoadGameBuffer->ReadFormIdentifier(&pTarget);
}
}  // namespace fnv_009f38b0

struct SaveGameLoader
{
    static bool __cdecl LoadFormRange(unsigned int, BGSLoadGameBuffer*, unsigned char);
};

// @fnv 0x0084c2a0
// src: XBOX_PDB 0x0084c2a0
void BGSSaveLoadGlobalData_RevertGlobalDataRange(unsigned int start, unsigned int end, unsigned char flag)
{
    BGSLoadGameBuffer lgb;
    for (unsigned int uiIndex = start; uiIndex < end; uiIndex++)
    {
        SaveGameLoader::LoadFormRange(uiIndex, &lgb, flag);
    }
}

extern "C" void* __cdecl __memcpy(void*, const void*, unsigned int);
void __cdecl _fnv_call_845cc0(const char*);

// Copies aiSize bytes from the load buffer into apData, advances the offset, and checks that the next byte is the '|' spacer.
// @fnv 0x00864820
void BGSLoadGameBuffer::ReadTypedData(NiQuaternion* apData, unsigned int aiSize)
{
    if (iBufferSize == 0)
    {
        return;
    }
    __memcpy(apData, pBuffer + iBufferPosition, aiSize);
    iBufferPosition += aiSize;
    if (pBuffer[iBufferPosition] != '|')
    {
        _fnv_call_845cc0("SAVELOAD: Invalid spacer hit while loading data from the buffer");
    }
    iBufferPosition += 1;
}

struct FUN_00857bd0
{
    void Init(unsigned int);
};
struct FUN_008579e0_shell
{
    char _0[0x14];
    void* _14;
    void TESSaveLoadGame_LoadGameDataOLD(void* dst, unsigned int size);
};
// Copies size bytes from the object's _14 pointer into dst, then calls Init(size) on this.
// @fnv 0x008579e0
// src: XBOX_PDB 0x008579e0
void FUN_008579e0_shell::TESSaveLoadGame_LoadGameDataOLD(void* dst, unsigned int size)
{
    __memcpy(dst, _14, size);
    ((FUN_00857bd0*)this)->Init(size);
}

// Initializes pBuffer, iBufferSize and the third field to zero.
// @fnv 0x008646b0
BGSLoadGameBuffer::BGSLoadGameBuffer()
{
    pBuffer = 0;
    iBufferSize = 0;
    iBufferPosition = 0;
}

// @fnv 0x008646f0
BGSLoadGameBuffer::~BGSLoadGameBuffer()
{
    char* p;
    p = (char*)pBuffer;
    operator delete(p);
}

void ReadFileIntoBuffer(SaveLoadFile*, unsigned int*, unsigned int);
// @fnv 0x00864740
int __thiscall BGSLoadGameBuffer::Load(SaveLoadFile* apFile)
{
    ReadFileIntoBuffer(apFile, &iBufferSize, 4);
    int result = Load(apFile, iBufferSize);
    if (result != iBufferSize)
        return -1;
    return result;
}

struct SaveLoadFile
{
    unsigned int Read(void*, unsigned int);
};
// Allocates a buffer of n bytes, reads n bytes from file into it, and returns the byte count or -1 on a short read.
// @fnv 0x00864790
int BGSLoadGameBuffer::Load(SaveLoadFile* file, unsigned int uiSize)
{
    iBufferSize = uiSize;
    char* buf = (char*)operator new(iBufferSize);
    pBuffer = buf;
    unsigned int read = file->Read(pBuffer, iBufferSize);
    if (read != iBufferSize)
        return -1;
    return (int)read;
}

namespace fnv_008648a0 {
struct PackedFormID
{
    unsigned int GetNumericID();
    void SetFormNumericID(unsigned int);
    bool IsZero();
    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
};
typedef char _sizecheck_BGSNumericIDIndex[sizeof(PackedFormID) == 3 ? 1 : -1];

struct Dummy84eaf0
{
    void ClearNumericIDIndex();
};
unsigned int __fastcall BGSNumericIDIndex_GetNumericID(void*);
}

// @fnv 0x008648a0
unsigned int BGSLoadGameBuffer::ReadFormIdentifier()
{
    using namespace fnv_008648a0;
    unsigned int iformID;
    PackedFormID formIDIndex;
    ((Dummy84eaf0*)&formIDIndex)->ClearNumericIDIndex();
    ReadTypedData(reinterpret_cast<NiQuaternion*>(&formIDIndex), 3);
    iformID = BGSNumericIDIndex_GetNumericID(&formIDIndex);
    return iformID;
}

namespace fnv_008648e0 {
struct PackedFormID
{
    unsigned int GetNumericID();
    void SetFormNumericID(unsigned int);
    bool IsZero();
    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
};
typedef char _sizecheck_BGSNumericIDIndex[sizeof(PackedFormID) == 3 ? 1 : -1];

struct Dummy84eaf0
{
    void ClearNumericIDIndex();
};
unsigned int __fastcall BGSNumericIDIndex_GetNumericID(void*);
bool __fastcall BGSNumericIDIndex_IsZero(void*);
}

// @fnv 0x008648e0
bool BGSLoadGameBuffer::ReadFormIdentifier(unsigned int* aiFormID)
{
    using namespace fnv_008648e0;
    PackedFormID formIDIndex;
    ((Dummy84eaf0*)&formIDIndex)->ClearNumericIDIndex();
    ReadTypedData(reinterpret_cast<NiQuaternion*>(&formIDIndex), 3);
    *aiFormID = BGSNumericIDIndex_GetNumericID(&formIDIndex);
    return !BGSNumericIDIndex_IsZero(&formIDIndex) && *aiFormID == 0;
}

struct FUN_00864940_shell
{
    unsigned char BGSNumericIDIndex_IsZero();
};

// Returns 1 if the first three bytes at this are all zero, otherwise 0.
// @fnv 0x00864940
// src: XBOX_PDB 0x00864940
unsigned char FUN_00864940_shell::BGSNumericIDIndex_IsZero()
{
    return (!(unsigned char)*reinterpret_cast<char*>(this) && !(unsigned char)reinterpret_cast<char*>(this)[1] &&
            !(unsigned char)reinterpret_cast<char*>(this)[2])
               ? 1
               : 0;
}

// @fnv 0x008649a0
char* BGSLoadGameBuffer::LoadString(char* apString)
{
    unsigned short slength = 0;
    ReadTypedData(reinterpret_cast<NiQuaternion*>(&slength), 2);
    if (slength)
    {
        if (!apString)
        {
            char* p = static_cast<char*>(operator new(slength + 1));
            apString = p;
        }
        ReadTypedData(reinterpret_cast<NiQuaternion*>(apString), slength);
        apString[slength] = 0;
    }
    else if (apString)
    {
        apString[0] = 0;
    }
    return apString;
}

namespace fnv_0043aaa0 {
struct FUN_0043aaa0_shell
{
    char pad1[4];
    char pad2[4];
    char pad3[4];
    char pad4[4];
    char pad5[4];
    char pad6[4];
    char pad7[4];
    char pad8[4];
    char pad9[4];
    char pad10[4];
    char pad11[4];
    char pad12[4];
    char pad13[4];
    void LoadGame(BGSLoadFormBuffer* buffer);
};

// @fnv 0x0043aaa0
void FUN_0043aaa0_shell::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData((char*)this + 4, 0xcu);
    buffer->ReadTypedData((char*)this + 0x10, 0xcu);
    buffer->ReadTypedData((char*)this + 0x1c, 1u);
    buffer->ReadFormIdentifier(this);
}
}  // namespace fnv_0043aaa0

// Initializes the object with the given section coordinates and sets the field at offset 0x28 to zero.
// @fnv 0x0087a100
IntSeenData::IntSeenData(char acSectionX, char acSectionY)
{
    field_24 = acSectionX;
    field_25 = acSectionY;
    field_28 = 0;
}

struct PackedFormID
{
    unsigned int GetNumericID();
    void SetFormNumericID(unsigned int);
    bool IsZero();
    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
};
typedef char _sizecheck_BGSNumericIDIndex[sizeof(PackedFormID) == 3 ? 1 : -1];
struct FUN_00853500_shell : public PackedFormID
{
    unsigned int BGSNumericIDIndex_GetNumericID();
};

struct FUN_00846d20_shell
{
    unsigned int BGSSaveLoadFormIDMap_GetFormID(unsigned int);
};
// @fnv 0x00853500
// src: XBOX_PDB 0x00853500
unsigned int FUN_00853500_shell::BGSNumericIDIndex_GetNumericID()
{
    unsigned int uiValue = (unsigned int)((unsigned char)m_ucIDByte0 << 0x10) +
                           (unsigned int)((unsigned char)m_ucIDByte1 << 8) + (unsigned int)(unsigned char)m_ucIDByte2;
    if (uiValue & 0x800000)
    {
        uiValue &= 0xff7fffff;
        uiValue |= 0xff000000;
        return uiValue;
    }
    return ((FUN_00846d20_shell*)g_BGSSaveLoadGame->GetFormIDMap())->BGSSaveLoadFormIDMap_GetFormID(uiValue);
}

void* __cdecl operator new(unsigned int);

int DAT_011d60cc;

struct FUN_0066deb0
{
    char _pad[0x1c];

    FUN_0066deb0();
    void ActorCause_LoadGameBGS(BGSLoadGameBuffer*);
};

// @fnv 0x0066e750
// src: COMMUNITY 0x0066e750
void ActorCause_LoadActorCausesList(BGSLoadGameBuffer* apLoadGameBuffer)
{
    unsigned int iloop;
    unsigned int isaveGameCount;

    apLoadGameBuffer->LoadData(&DAT_011d60cc, 4);
    iloop = apLoadGameBuffer->ReadElementCount();

    for (isaveGameCount = 0; isaveGameCount < iloop; ++isaveGameCount)
    {
        FUN_0066deb0* pactorCause = new FUN_0066deb0();
        pactorCause->ActorCause_LoadGameBGS(apLoadGameBuffer);
    }
}

// @fnv 0x00864a20
void BGSLoadGameBuffer::ReadTypedData(NiMatrix3* matrix, unsigned int unused)
{
    NiQuaternion quatData;
    {
        BGSLoadGameBuffer* pBuffer = this;
        pBuffer->LoadData(&quatData, 0x10);
        quatData.ToRotationMatrix(*matrix);
    }
}

void __cdecl operator delete(void* pointer);

struct FUN_0081db60_shell
{
    void FUN_0081db90();
    FUN_0081db60_shell* FUN_0081db60(unsigned int deletingFlags);
};

// Calls FUN_0081db90, frees this with operator delete when deletingFlags has bit 0 set, and returns this.
// @fnv 0x0081db60
FUN_0081db60_shell* FUN_0081db60_shell::FUN_0081db60(unsigned int deletingFlags)
{
    FUN_0081db90();
    if (deletingFlags & 1)
    {
        ::operator delete(this);
    }
    return this;
}

// Reads a tag byte, dispatches on its low two bits to read a 1, 2 or 4 byte value, and returns that value shifted right by two.
// @fnv 0x00864a60
int BGSLoadGameBuffer::ReadElementCount()
{
    unsigned char tag = (unsigned char)pBuffer[iBufferPosition];
    unsigned int flags9 = tag & 3;
    switch (flags9)
    {
    case 0: {
        unsigned char value = 0;
        ReadTypedData(reinterpret_cast<NiQuaternion*>(&value), 1);
        return (int)value >> 2;
    }
    case 1: {
        unsigned short value = 0;
        ReadTypedData(reinterpret_cast<NiQuaternion*>(&value), 2);
        return (int)value >> 2;
        break;
    }
    case 2: {
        unsigned int value = 0;
        ReadTypedData(reinterpret_cast<NiQuaternion*>(&value), 4);
        return (int)(value >> 2);
    }
    }
    return 0;
}
