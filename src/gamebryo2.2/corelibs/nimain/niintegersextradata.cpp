// gamebryo2.2/corelibs/nimain/niintegersextradata.cpp: NiIntegersExtraData, NiExtraDataSaveHelperShell (19 functions)

#include "niintegersextradata_decls.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiFixedString.h"
// Loads the extra data from the stream: reads a count, resizes entries, then reads and appends that many NiIntegerStreamEntry objects.
// @fnv 0x00c540a0
void NiIntegersExtraData::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    unsigned int count;
    ReadBinaryValue(stream, count);
    if (count)
    {
        entries.SetSize(count);
        struct Flags
        {
            unsigned short value;
            unsigned char tag;
        } flags;
        flags.value = 0;
        flags.tag = 255;
        NiIntegerStreamEntry streamEntry;
        for (unsigned int i = 0; i < count; ++i)
        {
            streamEntry.FurnitureMark_LoadBinary(stream);
            entries.Add(streamEntry);
            // Preserve the original frame's 176-byte unused local region.
            struct ReservedStreamLocals
            {
                unsigned int slot0;
                unsigned int slot1;
                unsigned int slot2;
                unsigned int slot3;
                unsigned int slot4;
                unsigned int slot5;
                unsigned int slot6;
                unsigned int slot7;
                unsigned int slot8;
                unsigned int slot9;
                unsigned int slot10;
                unsigned int slot11;
                unsigned int slot12;
                unsigned int slot13;
                unsigned int slot14;
                unsigned int slot15;
                unsigned int slot16;
                unsigned int slot17;
                unsigned int slot18;
                unsigned int slot19;
                unsigned int slot20;
                unsigned int slot21;
                unsigned int slot22;
                unsigned int slot23;
                unsigned int slot24;
                unsigned int slot25;
                unsigned int slot26;
                unsigned int slot27;
                unsigned int slot28;
                unsigned int slot29;
                unsigned int slot30;
                unsigned int slot31;
                unsigned int slot32;
                unsigned int slot33;
                unsigned int slot34;
                unsigned int slot35;
                unsigned int slot36;
                unsigned int slot37;
                unsigned int slot38;
                unsigned int slot39;
                unsigned int slot40;
                unsigned int slot41;
                unsigned int slot42;
                unsigned int slot43;
            } reserved;
        }
    }
}

extern NiFixedString* DAT_012031c0;

struct NiExtraDataNameInitializer : NiExtraData
{
    void BSFurnitureMarker_SetName();
};

// @fnv 0x00c543e0
// src: COMMUNITY 0x00c543e0
void NiExtraDataNameInitializer::BSFurnitureMarker_SetName()
{
    reinterpret_cast<NiAVObject*>(this)->SetName(*DAT_012031c0);
}

extern int g_012031c4;

struct FUN_00c54d60_shell
{
    int* __thiscall BSFurnitureMarker_GetRTTI();
};

// @fnv 0x00c54d60
// src: COMMUNITY 0x00c54d60
int* __thiscall FUN_00c54d60_shell::BSFurnitureMarker_GetRTTI()
{
    return &g_012031c4;
}

struct FUN_00c54030_shell
{
    int __thiscall BSFurnitureMarker_CreateClone(int param_1);
};

// @fnv 0x00c54030
// src: COMMUNITY 0x00c54030
int __thiscall FUN_00c54030_shell::BSFurnitureMarker_CreateClone(int param_1)
{
    return (int)this;
}

struct FUN_00a7b290_shell
{
    void __thiscall FUN_00a7b290(int);
};
struct FUN_00c54150_shell
{
    void __thiscall BSFurnitureMarker_RegisterStreamables(int param_1);
};
// @fnv 0x00c54150
// src: XBOX_PDB 0x00c54150
void __thiscall FUN_00c54150_shell::BSFurnitureMarker_RegisterStreamables(int param_1)
{
    ((FUN_00a7b290_shell*)this)->FUN_00a7b290(param_1);
}

struct C00c541e0
{
    bool FUN_00a7b3d0(int);
    bool BSFurnitureMarker_IsEqual(int);
};
// Calls FUN_00a7b3d0 with the given int and returns its bool result.
// @fnv 0x00c541e0
// src: XBOX_PDB 0x00c541e0
bool C00c541e0::BSFurnitureMarker_IsEqual(int a)
{
    bool b = FUN_00a7b3d0(a);
    return b;
}

void __cdecl NiStreamSaveBinary_unsigned_short(NiStream&, unsigned short*);
void __cdecl Runtime_UpdateState_00a29550(NiStream&, unsigned char*);
struct FUN_00c54660_shell
{
    NiColor color;
    unsigned short fldC;
    unsigned char fldE;
    void __thiscall ProcessState_00c54660(NiStream&);
};
// @fnv 0x00c54660
// src: GUESS 0x00c54660 (confidence: low)
void __thiscall FUN_00c54660_shell::ProcessState_00c54660(NiStream& aStream)
{
    color.SaveBinary(aStream);
    NiStreamSaveBinary_unsigned_short(aStream, &fldC);
    Runtime_UpdateState_00a29550(aStream, &fldE);
    Runtime_UpdateState_00a29550(aStream, &fldE);
}

void _delete(void*, unsigned int);
struct S_FUN_00c53fa0
{
    void __thiscall FUN_00c53fa0();
};
struct S_FUN_00c547e0
{
    void* __thiscall FUN_00c547e0(unsigned int);
};
// Calls FUN_00c53fa0 on this, then frees this with _delete when bit 0 of flags is set, and returns this.
// @fnv 0x00c547e0
void* __thiscall S_FUN_00c547e0::FUN_00c547e0(unsigned int flags)
{
    reinterpret_cast<S_FUN_00c53fa0*>(this)->FUN_00c53fa0();
    if (flags & 1)
        _delete(this, 0x1c);
    return this;
}

struct MM
{
    void __thiscall _DeallocateAlias(void*);
};
extern MM g_memoryManager;
extern int DAT_010c2b2c;
struct S
{
    void* vtbl;
    void* ptr;
    void __thiscall SetVtableAndProcessState_00c54810();
};
// Sets the object's vtable pointer to DAT_010c2b2c and deallocates its ptr through g_memoryManager.
// @fnv 0x00c54810
// src: GUESS 0x00c54810 (confidence: low)
void __thiscall S::SetVtableAndProcessState_00c54810()
{
    *(int*)this = (int)&DAT_010c2b2c;
    void* p1 = ptr;
    void* p2 = p1;
    g_memoryManager._DeallocateAlias(p2);
}

struct NiStream;
void __cdecl NiStreamSaveBinary_unsigned_int(NiStream&, unsigned const&);
struct NiExtraDataSaveHelperShell : NiExtraData
{
    void BSFurnitureMarker_SaveBinary(NiStream&);
};
// @fnv 0x00c54170
// src: XBOX_PDB 0x00c54170
void NiExtraDataSaveHelperShell::BSFurnitureMarker_SaveBinary(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    unsigned int count = *(unsigned short*)((char*)this + 0x18);
    NiStreamSaveBinary_unsigned_int(stream, count);
    for (unsigned int i = 0; i < count; ++i)
        (*(FUN_00c54660_shell**)((char*)this + 0x10))[i].ProcessState_00c54660(stream);
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c53f10 : A51BF0Base
{
    unsigned char padding[28];
    FUN_00c53f10();
};

extern NiFixedString DAT_011f49e0;

// Allocates a FUN_00c53f10 object, sets its name to DAT_011f49e0, and returns it as an NiAVObject pointer.
// @fnv 0x00c54210
// src: EXE 0x00c54210
NiAVObject* BSFurnitureMarker_CreateObject()
{
    NiAVObject* object = reinterpret_cast<NiAVObject*>(new FUN_00c53f10);
    object->SetName(DAT_011f49e0);
    return object;
}

class NiStream;

struct FUN_00c54040_cls
{
    unsigned int baseData[3];
    void CopyMembers_00a7b330(NiStream&, unsigned int);
    unsigned int unk0c;
    char* entries;
    unsigned int unk14;
    unsigned short count;

    void ProcessEntries_00c54040(NiStream& stream, unsigned int flags);
};

// Calls FUN_00a7b330, then loops over count entries and passes each entry to FUN_00c54b70 on the stream's array at offset 0xc.
// @fnv 0x00c54040
// src: GUESS 0x00c54040 (confidence: low)
void FUN_00c54040_cls::ProcessEntries_00c54040(NiStream& stream, unsigned int flags)
{
    unsigned char pad[0x58];
    unsigned int i;
    unsigned int n;
    CopyMembers_00a7b330(stream, flags);
    n = count;
    for (i = 0; i < n; i++)
    {
        ((NiIntegerStreamArray*)((char*)&stream + 0xc))->Add(*(NiIntegerStreamEntry*)(entries + (i << 4)));
    }
}

struct S_00c54130
{
    void FUN_00a7b3b0(int a);
    void BSFurnitureMarker_LinkObject(int a);
};

// @fnv 0x00c54130
// src: XBOX_PDB 0x00c54130
void S_00c54130::BSFurnitureMarker_LinkObject(int a)
{
    FUN_00a7b3b0(a);
}

extern double DAT_01012060;
extern float DAT_012031cc;
extern double DAT_01017b70;

struct S_00c54550_Foo
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0c;

    void __thiscall FurnitureMark_SetHeading(float param_1);
};

// @fnv 0x00c54550
// src: XBOX_PDB 0x00c54550
void __thiscall S_00c54550_Foo::FurnitureMark_SetHeading(float param_1)
{
    while (param_1 < DAT_01012060)
        param_1 += DAT_012031cc;

    while (param_1 >= DAT_012031cc)
        param_1 -= DAT_012031cc;

    unk0c = (unsigned short)(param_1 * DAT_01017b70);
}

class NiStream;

extern double DAT_01017b70;

void __cdecl NiStreamLoadBinary_unsigned_short(NiStream&, void*);
void __cdecl NiStreamLoadBinary_char_00a643b0(NiStream&, void*);

struct FUN_00c545d0_cls
{
    unsigned int baseData[3];
    void __thiscall FUN_00a59be0(NiStream&);
    unsigned short fldC;
    unsigned short fldE;
    void __thiscall FurnitureMark_SetHeading(float);
    void __thiscall FurnitureMark_LoadBinary(NiStream& s);
};

// @fnv 0x00c545d0
// src: COMMUNITY 0x00c545d0
void FUN_00c545d0_cls::FurnitureMark_LoadBinary(NiStream& aStream)
{
    unsigned char flag;
    FUN_00a59be0(aStream);
    NiStreamLoadBinary_unsigned_short(aStream, &fldC);
    NiStreamLoadBinary_char_00a643b0(aStream, &fldE);
    NiStreamLoadBinary_char_00a643b0(aStream, &flag);
    short sValue = (short)fldC;
    if (sValue < 0)
    {
        float fScaled = (float)((double)sValue / DAT_01017b70);
        FurnitureMark_SetHeading(fScaled);
    }
}

struct FUN_00c54b70_cls
{
    unsigned int unk00[2];
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void AllocateStorage_00c54850(unsigned int n);
    void FUN_00c54a30(unsigned int idx, NiIntegerStreamEntry& e);
    unsigned int NiTArray_FurnitureMark_NiTNewInterface_FurnitureMark_Add(NiIntegerStreamEntry& e);
};

// @fnv 0x00c54b70
// src: COMMUNITY 0x00c54b70
unsigned int FUN_00c54b70_cls::NiTArray_FurnitureMark_NiTNewInterface_FurnitureMark_Add(NiIntegerStreamEntry& aEntry)
{
    unsigned int scratch[0x16];
    unsigned int tmp;
    {
        unsigned int index = m_0a;
        if (index >= m_08)
        {
            AllocateStorage_00c54850(m_0e + index);
        }
        FUN_00c54a30(index, aEntry);
        return index;
    }
}

struct FUN_00c54c50_shell
{
    void* vtbl;
    void* ptr;
    unsigned short fld8;
    unsigned short fldA;
    unsigned short fldC;
    unsigned short fldE;

    FUN_00c54c50_shell* __thiscall NiTArray_FurnitureMark_NiTNewInterface_FurnitureMark_NiTArray(unsigned short param_1, unsigned short param_2);
};

extern int DAT_010c2b2c;
void* __cdecl Object_GetIndexedValue_00c54bc0(unsigned int);

// @fnv 0x00c54c50
// src: EXE 0x00c54c50
FUN_00c54c50_shell* __thiscall FUN_00c54c50_shell::NiTArray_FurnitureMark_NiTNewInterface_FurnitureMark_NiTArray(unsigned short param_1, unsigned short param_2)
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    this->vtbl = &DAT_010c2b2c;
    this->fld8 = param_1;
    this->fldE = param_2;
    this->fldA = 0;
    this->fldC = 0;

    if (this->fld8 > 0)
        this->ptr = Object_GetIndexedValue_00c54bc0(this->fld8);
    else
        this->ptr = 0;

    return this;
}

struct FUN_00c54cc0_cls
{
    float m_00;
    float m_04;
    float m_08;
    unsigned short m_0c;
    unsigned char m_0e;
    bool __thiscall HasEqualFields(FUN_00c54cc0_cls* other);
};

// Compares m_00, m_04, m_08, m_0e and m_0c against another instance and returns whether all match.
// @fnv 0x00c54cc0
// src: GUESS 0x00c54cc0 (confidence: medium)
bool FUN_00c54cc0_cls::HasEqualFields(FUN_00c54cc0_cls* other)
{
    return (bool)(((m_00 == other->m_00) && (m_04 == other->m_04) && (m_08 == other->m_08)) ? 1 : 0) &&
           (m_0e == other->m_0e) && (m_0c == other->m_0c);
}

static const char* dummy = "";

struct Entry_00c542a0
{
    NiPoint3 pos;
    unsigned short heading;
    unsigned char number;
    unsigned char pad0f;
};

struct ViewerStringsArray
{
    void AddFirstEmpty(char* const&);
};

struct MarkerText_00c542a0
{
    int scratch0;
    int scratch1;
    int scratch2;
    int scratch3;
    float headingValue;
    int scratch5;
    int scratch6;
    int scratch7;
    int scratch8;
    int scratch9;
    unsigned int numberValue;
    int scratch11;
    int scratch12;
    int scratch13;
};

struct FUN_00c542a0_shell : NiExtraData
{
    unsigned int unk0c;
    Entry_00c542a0* entries;
    unsigned int unk14;
    unsigned short count;

    void FUN_00a7b580(ViewerStringsArray*);
    void BSFurnitureMarker_GetViewerStrings(ViewerStringsArray*);
};

extern int g_012031c4;
extern char* __cdecl NiViewerStrings_NiGetViewerString_Title(int);
extern char* __cdecl NiGetViewerString_00a7d510(char const*, unsigned int);
extern char* __cdecl NiGetViewerString_00a7d550(char const*, float);

// Appends marker count and per-marker number, position, and heading strings to the viewer strings array.
// @fnv 0x00c542a0
// src: XBOX_PDB 0x00c542a0
void FUN_00c542a0_shell::BSFurnitureMarker_GetViewerStrings(ViewerStringsArray* strings)
{
    unsigned long iMarkers;
    unsigned int aIndex;
    Entry_00c542a0* marker;
    char* aRtti;
    char* pMark;
    char* aPMarker;
    char* animationType;
    char* aCurrentPos;
    char* aHeadingY;
    int aNameValue;
    MarkerText_00c542a0 val;

    FUN_00a7b580(strings);

    aNameValue = g_012031c4;
    aRtti = NiViewerStrings_NiGetViewerString_Title(aNameValue);
    strings->AddFirstEmpty(aRtti);

    iMarkers = count;
    pMark = NiGetViewerString_00a7d510("iMarks", iMarkers);
    strings->AddFirstEmpty(pMark);

    for (aIndex = 0; aIndex < iMarkers; ++aIndex)
    {
        aPMarker = NiGetViewerString_00a7d510("Mark", aIndex);
        strings->AddFirstEmpty(aPMarker);

        marker = &entries[aIndex];
        val.numberValue = marker->number;
        animationType = NiGetViewerString_00a7d510(" Number", val.numberValue);
        strings->AddFirstEmpty(animationType);

        aCurrentPos = marker->pos.GetViewerString_00a59af0(" Pos");
        strings->AddFirstEmpty(aCurrentPos);

        val.headingValue = (float)(marker->heading / 1000.0);
        aHeadingY = NiGetViewerString_00a7d550(" Heading", val.headingValue);
        strings->AddFirstEmpty(aHeadingY);
    }
}
