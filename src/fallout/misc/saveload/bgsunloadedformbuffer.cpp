
// src/fallout/misc/saveload/bgsunloadedformbuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/saveload/bgsunloadedformbuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BGSLoadFormBuffer.h"

extern int DAT_0107f494;

struct FUN_0084b4e0_shell
{
    void FUN_0084b750(void* arg);
    int NiTMap_int64_int_NiTMap(void* arg);
};

// Calls FUN_0084b750 with arg, stores the address of DAT_0107f494 into this, and returns this.
// @fnv 0x0084b4e0
// src: EXE 0x0084b4e0
int FUN_0084b4e0_shell::NiTMap_int64_int_NiTMap(void* arg)
{
    FUN_0084b750(arg);
    *(int*)this = (int)&DAT_0107f494;
    return (int)this;
}

struct BGSSaveLoadFormInfo
{
    int dummy;
};

struct FormInfoRecord
{
    BGSSaveLoadFormInfo FormInfo;
};

struct FormBufferContext
{
    char* pBuffer;
    char* BGSUnloadedFormBuffer_GetAdvancedBuffer();
};

unsigned int __cdecl GetSizeTypeSize(unsigned int);
unsigned int __fastcall BGSSaveLoadFormInfo_GetSizeType(void*);

// If pBuffer is set, computes a size from the header via FUN_00864520 and FUN_00845d70 and returns pBuffer plus that size plus 2; otherwise returns 0.
// @fnv 0x00866390
// src: XBOX_PDB 0x00866390
char* FormBufferContext::BGSUnloadedFormBuffer_GetAdvancedBuffer()
{
    FormInfoRecord* punloadedHeader;
    unsigned int isizeTypeSize;
    if (pBuffer)
    {
        punloadedHeader = (FormInfoRecord*)pBuffer;
        isizeTypeSize = GetSizeTypeSize(BGSSaveLoadFormInfo_GetSizeType(punloadedHeader));
        return (char*)(pBuffer + isizeTypeSize + 2);
    }
    return 0;
}

typedef unsigned int SIZE_TYPE;

SIZE_TYPE __fastcall BGSSaveLoadFormInfo_GetSizeType(void*);

// @fnv 0x00866430
// src: COMMUNITY 0x00866430
SIZE_TYPE __fastcall BGSUnloadedFormBuffer_GetSizeType(void* a)
{
    return BGSSaveLoadFormInfo_GetSizeType(*(void**)a);
}

struct FUN_00866450_shell
{
    unsigned int __thiscall BGSUnloadedFormBuffer_GetSizeType();
    unsigned int __thiscall GetAdjustedValue();
};

unsigned int __cdecl GetSizeTypeSize(unsigned int);

// Calls FUN_00845d70 on the result of FUN_00866430 and returns that value plus 9.
// @fnv 0x00866450
unsigned int __thiscall FUN_00866450_shell::GetAdjustedValue()
{
    unsigned int result = GetSizeTypeSize(BGSUnloadedFormBuffer_GetSizeType());
    return result + 9;
}

void __cdecl ReadValueBySizeType(void* a1, unsigned int* a2, unsigned int a3);
struct FUN_008663e0_shell
{
    char* pBuffer;
    unsigned int BGSUnloadedFormBuffer_GetSize();
};
// @fnv 0x008663e0
// src: COMMUNITY 0x008663e0
unsigned int FUN_008663e0_shell::BGSUnloadedFormBuffer_GetSize()
{
    unsigned int uiOut;
    if (pBuffer == 0)
        return 0;
    {
        unsigned int uiSize = BGSUnloadedFormBuffer_GetSizeType(this);
        char* pData = pBuffer + 2;
        uiOut = 0;
        ReadValueBySizeType(pData, &uiOut, uiSize);
    }
    return uiOut;
}

void* __cdecl operator new(unsigned int);
unsigned int _data_011c16bc;


struct FUN_0084b450_Class
{
    unsigned char BGSUnloadedFormBuffer_GetVersion();
};

struct FUN_00866480_shell : FormBufferContext
{
    unsigned int BGSUnloadedFormBuffer_GetSizeType();
    BGSLoadFormBuffer* BGSUnloadedFormBuffer_FillLoadFormBuffer();
};

// @fnv 0x00866480
// src: COMMUNITY 0x00866480
BGSLoadFormBuffer* FUN_00866480_shell::BGSUnloadedFormBuffer_FillLoadFormBuffer()
{
    SIZE_TYPE esizeType;
    char* padvancedBuffer;
    unsigned int isize;
    unsigned int iposition;
    BGSLoadFormBuffer* ploadFormBuffer;

    ploadFormBuffer = new BGSLoadFormBuffer;
    ploadFormBuffer->ExtraDismemberedLimbs_SetEaten(reinterpret_cast<FUN_0084b450_Class*>(this)->BGSUnloadedFormBuffer_GetVersion());
    esizeType = this->BGSUnloadedFormBuffer_GetSizeType();
    iposition = 2;
    padvancedBuffer = this->pBuffer + 2;
    isize = 0;
    iposition += (*reinterpret_cast<unsigned int(__cdecl*)(void const*, unsigned int*, unsigned int)>(
        &ReadValueBySizeType))(padvancedBuffer, &isize, esizeType);
    ploadFormBuffer->SetBuffer(this->pBuffer, isize + iposition, iposition);
    return ploadFormBuffer;
}

struct FUN_0044ddc0_shell
{
    void FUN_0044ddc0();
};

struct FUN_00866da0_shell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    FUN_0044ddc0_shell** unk50;

    void CallSlotMethod(int index);
};

// @fnv 0x00866da0
void FUN_00866da0_shell::CallSlotMethod(int index)
{
    unk50[index]->FUN_0044ddc0();
}

class Version866
{
  public:
    int GetFormat();

    unsigned char m_ucMajor;
    unsigned char m_ucMinor;
};

class Header866
{
  public:
    Header866();

    unsigned char m_ucMagic0;
    unsigned char m_ucMagic1;
    unsigned char m_ucMagic2;
    unsigned char m_ucMagic3;
    unsigned char m_ucMagic4;
    unsigned char m_ucMagic5;
    unsigned char m_ucMagic6;
    Version866 m_kVersion;
};

class SaveFile866
{
  public:
    unsigned int Read(void* pvBuffer, unsigned int uiSize);
};

int __cdecl ReadLength866(SaveFile866* pkFile, unsigned int* puiLength, int iFormat);
void __cdecl PrepareBuffer866(void* pvBuffer, unsigned int uiLength, int iFormat);

class Buffer866
{
  public:
    char* m_pcData;

    void ReadBuffer(SaveFile866* pkFile);
};

// @fnv 0x008662c0
void Buffer866::ReadBuffer(SaveFile866* pkFile)
{
    unsigned int uiLength_;
    int iExtra;
    Version866* pkVersion2;
    unsigned int uiSize;
    int iFormat2;
    char* pcCur6;
    Header866 kHeader5;

    pkFile->Read(&kHeader5, 9);
    iFormat2 = kHeader5.m_kVersion.GetFormat();
    uiLength_ = 0;
    iExtra = ReadLength866(pkFile, &uiLength_, iFormat2);
    uiSize = uiLength_ + iExtra + 2;
    m_pcData = new char[uiSize];
    pcCur6 = m_pcData;
    pkVersion2 = (Version866*)pcCur6;
    pkVersion2->m_ucMinor = kHeader5.m_kVersion.m_ucMinor;
    pkVersion2->m_ucMajor = kHeader5.m_kVersion.m_ucMajor;
    pcCur6 += 2;
    PrepareBuffer866(pcCur6, uiLength_, iFormat2);
    pcCur6 += iExtra;
    if (uiLength_)
        pkFile->Read(pcCur6, uiLength_);
}
