// src/fallout/misc/saveload/bgssavegamebuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/saveload/bgssavegamebuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BGSSaveGameBuffer.h"
#include "../../../../include/BGSSaveLoadManager.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/NiMatrix3.h"

// The shared interface does not declare buffer growth; keep only that operation here.
class BGSSaveGameBufferGrowth : public BGSSaveGameBuffer
{
public:
    void GrowBuffer();
};

struct FUN_0043aa40_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void __thiscall SaveFields_0043aa40(BGSSaveFormBuffer* apBuffer);
};

// Writes three ranges of this object (offsets 4, 0x10, 0x1c) and the form at m_00 into the save buffer.
// @fnv 0x0043aa40
// src: GUESS 0x0043aa40 (confidence: medium)
void FUN_0043aa40_shell::SaveFields_0043aa40(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveData((void*)((char*)this + 4), 0xc, 0);
    apBuffer->SaveData((void*)((char*)this + 0x10), 0xc, 0);
    apBuffer->SaveData((void*)((char*)this + 0x1c), 1, 0);
    apBuffer->SerializeFormData((void*)this->m_00, 0);
}

extern BGSSaveLoadManager* DAT_011de134;

struct FUN_00846330_shell
{
    void __thiscall WriteToFile(int a, int b);
};

// @fnv 0x00865c80
void BGSSaveGameBuffer::Save(SaveLoadFile* a1, unsigned int a2)
{
    if (DAT_011de134->InterfaceManager_GetMenuMode())
    {
        if (a2)
        {
            ((FUN_00846330_shell*)a1)->WriteToFile(0, a2);
        }
    }
    else
    {
        if (pBuffer && a2)
        {
            ((FUN_00846330_shell*)a1)->WriteToFile((int)pBuffer, a2);
        }
    }
}

void __cdecl _fnv_call_845cc0(const char* fmt, unsigned int value);

// @fnv 0x00865f60
// src: XBOX_PDB 0x00865f60
void BGSSaveGameBuffer::SaveVariableSizedValue(unsigned int aiVariableValue)
{
    unsigned char cvalue3;
    unsigned short svalue9;
    unsigned int ivalue;

    if (aiVariableValue < 0x40)
    {
        cvalue3 = (unsigned char)(aiVariableValue << 2);
        WriteAtOffset(&cvalue3, 1, 0);
    }
    else if (aiVariableValue < 0x4000)
    {
        svalue9 = (unsigned short)((aiVariableValue << 2) | 1);
        WriteAtOffset(&svalue9, 2, 0);
    }
    else if (aiVariableValue < 0x40000000)
    {
        ivalue = (aiVariableValue << 2) | 2;
        WriteAtOffset(&ivalue, 4, 0);
    }
    else
    {
        _fnv_call_845cc0("SAVELOAD: Variable-sized value %08X is too large to be stored.", aiVariableValue);
    }
}

struct FUN_00835f10_shell
{
    void __thiscall DynamicRadio_Save(BGSSaveFormBuffer* apBuffer);
};

// Writes the object's pointer to the save buffer, then saves four consecutive one-byte fields at offsets 0x1c through 0x1f.
// @fnv 0x00835f10
// src: COMMUNITY 0x00835f10
void __thiscall FUN_00835f10_shell::DynamicRadio_Save(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SerializeFormData(*(void**)this, 0);
    apBuffer->SaveData((char*)this + 0x1c, 1, 0);
    apBuffer->SaveData((char*)this + 0x1d, 1, 0);
    apBuffer->SaveData((char*)this + 0x1e, 1, 0);
    apBuffer->SaveData((char*)this + 0x1f, 1, 0);
}

struct FUN_009f3850_shell
{
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    void __thiscall SandBoxChoiceListItem_SaveGame(BGSSaveFormBuffer* apBuffer);
};

// @fnv 0x009f3850
// src: XBOX_PDB 0x009f3850
void __thiscall FUN_009f3850_shell::SandBoxChoiceListItem_SaveGame(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveData(&m_04, 4, 0);
    apBuffer->SaveData(&m_08, 4, 0);
    apBuffer->SaveData(&m_0c, 4, 0);
    apBuffer->SerializeFormData(m_00, 0);
}

struct FUN_006e2350_shell
{
    void __thiscall SaveState_006e2350(BGSSaveFormBuffer* apBuffer);
};

// @fnv 0x006e2350
// src: GUESS 0x006e2350 (confidence: medium)
void __thiscall FUN_006e2350_shell::SaveState_006e2350(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveData(this, 4, 0);
    apBuffer->SaveData((char*)this + 0x2c, 12, 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x38), 0);
    ((void(__thiscall*)(void*, BGSSaveFormBuffer*))(*(void***)(*(void***)((char*)this + 4))))((char*)this + 4,
                                                                                              apBuffer);
}

struct FUN_006f50b0_shell
{
    int m_00;
    int m_04;
    void __thiscall VirtualPathingNode_Save(BGSSaveFormBuffer* apBuffer);
};

// Saves 4 bytes of this object, saves the pointer at offset 0x2c, then calls the virtual save on the sub-object at offset 4.
// @fnv 0x006f50b0
// src: COMMUNITY 0x006f50b0
void __thiscall FUN_006f50b0_shell::VirtualPathingNode_Save(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveData(this, 4, 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x2c), 0);
    ((void(__thiscall*)(FUN_006f50b0_shell*, BGSSaveFormBuffer*))(*(void**)(*(void**)((char*)this + 4))))(
        (FUN_006f50b0_shell*)((char*)this + 4), apBuffer);
}

struct Flt
{
    operator unsigned int();
};

struct FUN_0083d690_shell
{
    void __thiscall DialogueResponse_SaveGame(BGSSaveFormBuffer* apBuffer);
};

// @fnv 0x0083d690
// src: COMMUNITY 0x0083d690
void __thiscall FUN_0083d690_shell::DialogueResponse_SaveGame(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveGameString((const char*)((Flt*)this)->operator unsigned int(), 0);
    apBuffer->SaveGameString((const char*)((Flt*)((char*)this + 0x10))->operator unsigned int(), 0);
    apBuffer->SaveData((char*)this + 8, 4, 0);
    apBuffer->SaveData((char*)this + 0xc, 4, 0);
    apBuffer->SaveData((char*)this + 0x24, 1, 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x18), 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x1c), 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x20), 0);
}

struct FUN_00857bd0
{
    void __thiscall Init(unsigned int);
};
void* __cdecl __memcpy(void* a1, const void* a2, unsigned int a3);
struct FUN_008579b0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void __thiscall TESSaveLoadGame_SaveGameDataOLD(void* a1, unsigned int a2);
};
// Copies a2 bytes from a1 into the buffer at this+0x14, then calls Init with a2.
// @fnv 0x008579b0
// src: XBOX_PDB 0x008579b0
void __thiscall FUN_008579b0_shell::TESSaveLoadGame_SaveGameDataOLD(void* apSource, unsigned int uiSize)
{
    __memcpy(*(void**)((char*)this + 0x14), apSource, uiSize);
    ((FUN_00857bd0*)this)->Init(uiSize);
}

// Writes size bytes from data into the buffer at the given offset, using the buffer's stored base position.
// @fnv 0x00865570
void BGSSaveGameBuffer::WriteAtOffset(void* data, unsigned int size, unsigned int offset)
{
    SaveData(data, size, iBufferPosition, (unsigned char)offset);
}

void __cdecl _Deallocate(void*);
// Restores the base vtable and deallocates pBuffer.
// @fnv 0x00865c10
BGSSaveGameBuffer::~BGSSaveGameBuffer()
{
    void* p = pBuffer;
    _Deallocate(p);
}

void __cdecl ForwardToShell(FUN_00846330_shell*, void*, int);
// @fnv 0x00865c40
void BGSSaveGameBuffer::Save(SaveLoadFile* apFile)
{
    ForwardToShell((FUN_00846330_shell*)apFile, &iBufferPosition, 4);
    Save(apFile, iBufferPosition);
}

struct Dummy84eaf0
{
    void __thiscall ClearNumericIDIndex();
    void __thiscall WriteFormIDBytes(unsigned int);
    int m_auiShapeKeys;
};
// @fnv 0x00865db0
void BGSSaveGameBuffer::SerializeFormData(unsigned int a, unsigned int uiUnused)
{
    Dummy84eaf0 p;
    p.ClearNumericIDIndex();
    p.WriteFormIDBytes(a);
    WriteAtOffset(&p, 3, 0);
}

namespace fnv_00865df0 {
struct Dummy84eaf0
{
    void __thiscall ClearNumericIDIndex();
};
struct PackedFormID : Dummy84eaf0
{
    unsigned m_iOwnerObjectOffset;
    void __thiscall WriteFormIDBytes(unsigned);
};
}  // namespace fnv_00865df0

// @fnv 0x00865df0
void BGSSaveGameBuffer::SerializeFormData(TESForm* apForm, unsigned aiUnusuedMetaDataArg)
{
    unsigned formID;
    fnv_00865df0::PackedFormID formIDIndex;
    formID = apForm ? apForm->GetHavokWorldObjectCountInSceneGraph_0084e3a0() : 0;
    formIDIndex.ClearNumericIDIndex();
    formIDIndex.WriteFormIDBytes(formID);
    WriteAtOffset(&formIDIndex, 3, 0);
}

// @fnv 0x00865e50
void BGSSaveGameBuffer::SaveData(void* data, unsigned int size, unsigned int offset)
{
    WriteAtOffset(data, size, 0);
}

// Builds a NiQuaternion from aMatrix and writes its 16 bytes into the save buffer.
// @fnv 0x00865ee0
void BGSSaveGameBuffer::SaveData(NiMatrix3* aMatrix, unsigned int aiUnused1, unsigned int aiUnused2)
{
    NiQuaternion quat;
    BGSSaveFormBuffer* pkBuffer;
    quat.FromRotationMatrix(*aMatrix);
    pkBuffer = (BGSSaveFormBuffer*)this;
    pkBuffer->SaveData(&quat, 16, 0);
}

// Appends a single '#' character at iBufferPosition and returns the previous position.
// @fnv 0x00865f20
// src: XBOX_PDB 0x00865f20
unsigned int BGSSaveGameBuffer::StartVariableSizedValue()
{
    char cvalue;
    unsigned int iposition;
    iposition = iBufferPosition;
    cvalue = 0x23;
    SaveData(&cvalue, 1, iBufferPosition, 0);
    return iposition;
}

struct FUN_0083fb10_shell
{
    void __thiscall SaveState_0083fb10(BGSSaveFormBuffer* apBuffer);
};

// @fnv 0x0083fb10
// src: GUESS 0x0083fb10 (confidence: medium)
void __thiscall FUN_0083fb10_shell::SaveState_0083fb10(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveGameString((const char*)(unsigned int)*(Flt*)this, 0);
    apBuffer->SaveData((char*)this + 8, 1, 0);
    apBuffer->SaveData((char*)this + 0x24, 1, 0);
    apBuffer->SaveData((char*)this + 0x25, 1, 0);
    apBuffer->SaveData((char*)this + 9, 1, 0);
    apBuffer->SaveData((char*)this + 0xa, 1, 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x14), 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x28), 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x1c), 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x18), 0);
}

unsigned int __cdecl _strlen(const char*);
// Writes a string to the save buffer: computes its length, writes the 2-byte length, then the string bytes if non-empty.
// @fnv 0x00865e70
void BGSSaveGameBuffer::SaveGameString(const char* apString, int aiUnusedMetaDataArg)
{
    unsigned short usLength = apString ? _strlen(apString) : 0;
    unsigned short usSavedLength = usLength;
    WriteAtOffset(&usLength, 2, 0);
    if (usSavedLength)
        WriteAtOffset((void*)apString, usSavedLength, 0);
}

// @fnv 0x00865ff0
// src: XBOX_PDB 0x00865ff0
void BGSSaveGameBuffer::SaveVariableSizedValue_00865ff0(unsigned int uiValue, unsigned int a2)
{
    if (uiValue < 0x40)
    {
        char value8 = static_cast<char>(uiValue << 2);
        this->SaveData(&value8, 1, a2, 0);
    }
    else if (uiValue < 0x4000)
    {
        this->ShiftBuffer(a2, 1);
        unsigned short value16 = static_cast<unsigned short>((uiValue << 2) | 1);
        this->SaveData(reinterpret_cast<char*>(&value16), 2, a2, 0);
    }
    else if (uiValue < 0x40000000)
    {
        this->ShiftBuffer(a2, 3);
        unsigned int value32 = (uiValue << 2) | 2;
        this->SaveData(reinterpret_cast<char*>(&value32), 4, a2, 0);
    }
    else
    {
        _fnv_call_845cc0("SAVELOAD: Variable-sized value %08X is too large to be stored.", uiValue);
    }
}

// @fnv 0x00847dd0
void BGSSaveGameBuffer::ReleaseBufferContents()
{
    BGSSaveGameBuffer::~BGSSaveGameBuffer();
}

void* __cdecl FUN_00401460(void* a1, const void* a2, unsigned int a3);

// Grows the buffer to fit the data and optional terminator, then updates its position and debug overhead.
// @fnv 0x00865ce0
void BGSSaveGameBuffer::SaveData(void* pSource, unsigned int uiLength, unsigned int a3, unsigned int a4)
{
    int iTerminator = ((unsigned char)a4 == 0);

    while (a3 + uiLength + iTerminator > iBufferSize)
    {
        static_cast<BGSSaveGameBufferGrowth*>(this)->GrowBuffer();
    }

    if (!DAT_011de134->InterfaceManager_GetMenuMode())
    {
        FUN_00401460(pBuffer + a3, pSource, uiLength);
    }

    if ((unsigned char)a4 == 0)
    {
        if (!DAT_011de134->InterfaceManager_GetMenuMode())
        {
            pBuffer[a3 + uiLength] = 0x7c;
        }

        if (a3 == iBufferPosition)
        {
            iDebugOverhead += 1;
        }
    }

    if (a3 + uiLength + iTerminator > iBufferPosition)
    {
        iBufferPosition = a3 + uiLength + iTerminator;
    }
}

// Interface dispatch: when owned by a menu item, refresh it directly; otherwise refresh the item its owner reports.

class F54C0Item;

class F54C0Interface
{
  public:
    virtual void Unk00();
    virtual F54C0Item* GetItem();
    virtual void Unk08();
    virtual bool IsItem();

    void RefreshItem();
};

class F54C0ItemBase
{
  public:
    virtual ~F54C0ItemBase();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
};

class F54C0Item : public F54C0ItemBase, public F54C0Interface
{
  public:
    void Refresh();
};

class F54C0OwnerBase
{
  public:
    virtual ~F54C0OwnerBase();
    int unk04;
    int unk08;
};

class F54C0Owner : public F54C0OwnerBase, public F54C0Interface
{
};

// If this is an item, refreshes it directly; otherwise gets the owner's item and refreshes that.
// @fnv 0x008254c0
void F54C0Interface::RefreshItem()
{
    F54C0Owner* pkOwner;
    F54C0Item* pkItem;

    if (IsItem())
    {
        pkItem = static_cast<F54C0Item*>(this);
        pkItem->Refresh();
    }
    else
    {
        pkOwner = static_cast<F54C0Owner*>(this);
        pkOwner->GetItem()->Refresh();
    }
}
