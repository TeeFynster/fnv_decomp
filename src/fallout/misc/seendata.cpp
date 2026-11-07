// fallout/misc/seendata.cpp: SeenData and IntSeenData (25 functions)
#include "../../../include/NiColorA.h"

#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/SeenData.h"
#include "../../../include/IntSeenData.h"
#include "seendata_decls.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/TESSaveLoadGame.h"

// @fnv 0x0087a0e0
void SeenData::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(static_cast<void*>(m_uiSeenData), 0x20u);
}

// @fnv 0x00879940
SeenData::SeenData()
{
    memset(m_uiSeenData, 0, 0x20);
}

// Sets position from the index's row/column scaled by DAT_011a31e8 when index < DAT_011a31ec, otherwise to FLT_MAX.
// @fnv 0x00879bd0
void SeenData::GetPositionForIndex(unsigned int index, NiPoint3& position)
{
    float remainder;
    float quotient;

    if (index < DAT_011a31ec)
    {
        remainder = static_cast<float>(index % 16);
        quotient = static_cast<float>(index >> 4);
        position = NiPoint3(DAT_011a31e8 * remainder, DAT_011a31e8 * quotient, 0.0f);
    }
    else
    {
        position = NiPoint3(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F);
    }
}

// @fnv 0x0087a570
void IntSeenData::LoadGame(BGSLoadFormBuffer* pLoadBuffer)
{
    struct LoadCursor
    {
        unsigned int count;
        IntSeenData* section;
    } cursor;
    cursor.count = pLoadBuffer->ReadElementCount();
    cursor.section = this;
    for (unsigned int index = 0; index < cursor.count; ++index)
    {
        pLoadBuffer->ReadTypedData(&cursor.section->field_24, 1u);
        pLoadBuffer->ReadTypedData(&cursor.section->field_25, 1u);
        cursor.section->SeenData::LoadGame(pLoadBuffer);
        if (index < cursor.count - 1)
            cursor.section->field_28 = new IntSeenData(char(0), char(0));
        cursor.section = cursor.section->field_28;
    }
}

// Tests whether the bit at index aiBit is set in the bit array stored at offset 4 of this object.
// @fnv 0x008799f0
bool SeenData::IsBitSet(unsigned int aiBit)
{
    unsigned int iIndex = aiBit >> 5;
    unsigned int iWhichBit = aiBit - (iIndex << 5);
    if ((1 << iWhichBit) & m_uiSeenData[iIndex])
        return true;
    else
        return false;
}

// Reads the bit at idx from the bit array, sets or clears it depending on set, and returns the previous bit value.
// @fnv 0x00879a40
// src: COMMUNITY 0x00879a40
bool SeenData::SetSeenBit(unsigned int auiIndex, bool set)
{
    unsigned int aWord;
    unsigned int bBit;
    aWord = auiIndex >> 5;
    bBit = auiIndex - (aWord << 5);
    {
        bool old = (1 << bBit) & m_uiSeenData[aWord] ? true : false;
        if (set)
            m_uiSeenData[aWord] |= 1 << bBit;
        else
            m_uiSeenData[aWord] &= ~(1 << bBit);
        return old;
    }
}

struct SettingT_GCol
{
    float* Float();
};
extern SettingT_GCol originalRuntimeFloatSetting37;
// @fnv 0x00879bb0
float GetRuntimeFloatSetting37()
{
    return *originalRuntimeFloatSetting37.Float();
}

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011df198;
float __cdecl GetRuntimeFloatSetting37();

// @fnv 0x00879ad0
bool SeenData::HasEnoughSeenPoints(const NiPoint3& aPoint, const NiPoint3& aOffset)
{
    int iSeenCount = 0;
    for (unsigned int uiIndex = 0; uiIndex < DAT_011a31ec; uiIndex++)
    {
        if (!IsBitSet(uiIndex))
        {
            // The original uses the out-of-line point initializer without a default constructor call.
            float diffStorage[3];
            reinterpret_cast<NiPoint3*>(diffStorage)->FUN_006815c0();
            SeenData::GetPositionForIndex(uiIndex, *reinterpret_cast<NiPoint3*>(diffStorage));
            reinterpret_cast<NiPoint3*>(diffStorage)->ComputeValue_0063c8a0(aOffset);
            {
                NiPoint3 delta = *reinterpret_cast<const NiPoint3*>(diffStorage) - aPoint;
                if (static_cast<const NiPoint3&>(delta).Length() < GetRuntimeFloatSetting37())
                {
                    SetSeenBit(uiIndex, true);
                    iSeenCount++;
                }
            }
        }
        else
        {
            iSeenCount++;
        }
    }
    return iSeenCount >= *g_011df198.Int();
}

int __cdecl TruncateFloatToInt(float);

// Quantizes pos.x and pos.y to multiples of DAT_011a31e8 within their 4096-unit cells and sets pos.z to 0.
// @fnv 0x00879ca0
void SnapToGridCell(NiPoint3& pos)
{
    int cellY;
    int subX;
    int cellX;
    int iSubCellY;
    subX = TruncateFloatToInt(pos.x) >> 12;
    cellX = TruncateFloatToInt(pos.y) >> 12;
    cellY = (int)(TruncateFloatToInt(pos.x - (subX << 12)) / DAT_011a31e8);
    iSubCellY = (int)(TruncateFloatToInt(pos.y - (cellX << 12)) / DAT_011a31e8);
    pos.x = (subX << 12) + cellY * DAT_011a31e8;
    pos.y = (cellX << 12) + iSubCellY * DAT_011a31e8;
    pos.z = 0.0f;
}

// @fnv 0x00879d90
// src: XBOX_PDB 0x00879d90
float SeenData_GetSeenPosSize()
{
    return DAT_011a31e8;
}

// Returns the save size for this object: a fixed 0x20 bytes, ignoring the recursion flag.
// @fnv 0x0087a030
unsigned short SeenData::GetSaveSize(bool abRecursing)
{
    unsigned short isize = 0;
    isize += 0x20;
    return isize;
}


TESSaveLoadGame* g_TESSaveLoadGame;

// @fnv 0x0087a090
// src: XBOX_PDB 0x0087a090
void __thiscall SeenData::LoadGame_0087a090(unsigned short)
{
    g_TESSaveLoadGame->ReadTypedData(m_uiSeenData, 0x20);
}

// Calls SaveData on the buffer with this+4 and a size of 0x20.
// @fnv 0x0087a0c0
void __thiscall SeenData::SaveFormData(void* buf)
{
    ((BGSSaveFormBuffer*)buf)->SaveData(m_uiSeenData, 0x20, 0);
}

void __cdecl _Deallocate(void*);
// @fnv 0x00879970
void* SeenData::FUN_00879970(unsigned int flags)
{
    SetVtable();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0087a060 {
extern TESSaveLoadGame* g_TESSaveLoadGame;
}  // namespace fnv_0087a060

// Passes the seen-data array and size 0x20 to TESSaveLoadGame::FUN_008579b0.
// @fnv 0x0087a060
// src: XBOX_PDB 0x0087a060
void SeenData::SaveGame_0087a060(bool abRecursing)
{
    fnv_0087a060::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&field_04, 0x20);
}

void _Deallocate(void*);
// Calls FUN_0087a170, then if the low bit of flags is set deallocates this, and returns this.
// @fnv 0x0087a140
void* IntSeenData::FUN_0087a140(unsigned int flags)
{
    IntSeenData::~IntSeenData();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Saves each node's bytes at offsets 0x24 and 0x25 and its linked data to the buffer, then writes the node count at the recorded position.
// @fnv 0x0087a4e0
void IntSeenData::SaveToBuffer(BGSSaveFormBuffer* buffer)
{
    unsigned int icount = 0;
    unsigned int icountPosition = buffer->StartVariableSizedValue();
    IntSeenData* pNode = this;
    while (pNode)
    {
        buffer->SaveData(&pNode->field_24, 1, 0);
        buffer->SaveData(&pNode->field_25, 1, 0);
        pNode->SaveFormData(buffer);
        pNode = pNode->field_28;
        ++icount;
    }
    buffer->SaveVariableSizedValue_00865ff0(icount, icountPosition);
}

// @fnv 0x008799a0
void SeenData::SetVtable()
{
    *(void**)this = &DAT_01083fc4;
}

namespace fnv_0087a3e0 {
extern int _data_011c16bc;

class SaveManager
{
};

extern SaveManager* DAT_011de45c;


}  // namespace fnv_0087a3e0

// @fnv 0x0087a3e0
// src: XBOX_PDB 0x0087a090
void IntSeenData::LoadGame_0087a090(unsigned short aiCount)
{
    SeenData::LoadGame_0087a090(0xffff);

    if (aiCount == 0xffff)
        reinterpret_cast<TESSaveLoadGame*>(fnv_0087a3e0::DAT_011de45c)->ReadTypedData(&aiCount, 2);

    reinterpret_cast<TESSaveLoadGame*>(fnv_0087a3e0::DAT_011de45c)->ReadTypedData(&field_24, 1);
    reinterpret_cast<TESSaveLoadGame*>(fnv_0087a3e0::DAT_011de45c)->ReadTypedData(&field_25, 1);

    aiCount--;

    if (aiCount > 0)
    {
        field_28 = new IntSeenData(char(0), char(0));

        field_28->LoadGame_0087a090(aiCount);
    }
}

struct Marker
{
    void NiAVObject_SetTranslate_004bc1f0(float, float, float);
};
Marker* __cdecl CreateSquareLines(float, NiColorA*, int);
struct Parent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void Attach(Marker*, int);
};
// @fnv 0x00879f20
void SeenData::AttachMarkersForSeenData(NiNode* parent, const NiPoint3& offset, int unused)
{
    if (parent)
    {
        NiColorA effectColor(1.0f, 0.0f, 0.0f, 0.0f);
        float half = DAT_011a31e8 / 2.0;
        for (unsigned int i3 = 0; i3 < DAT_011a31ec; i3++)
        {
            if (IsBitSet(i3))
            {
                // The original uses the out-of-line point initializer without a default constructor call.
                float positionStorage[3];
                reinterpret_cast<NiPoint3*>(positionStorage)->FUN_006815c0();
                SeenData::GetPositionForIndex(i3, *reinterpret_cast<NiPoint3*>(positionStorage));
                reinterpret_cast<NiPoint3*>(positionStorage)->ComputeValue_0063c8a0(offset);
                Marker* marker3 = CreateSquareLines(DAT_011a31e8, &effectColor, 1);
                reinterpret_cast<Parent*>(parent)->Attach(marker3, 1);
                marker3->NiAVObject_SetTranslate_004bc1f0(reinterpret_cast<NiPoint3*>(positionStorage)->x + half, reinterpret_cast<NiPoint3*>(positionStorage)->y + half, reinterpret_cast<NiPoint3*>(positionStorage)->z);
            }
        }
    }
}

// Computes the section centre, attaches its markers, then forwards the position and flag to the next section.
// @fnv 0x0087a200
void IntSeenData::AddToNode(NiNode* pvContext, NiPoint3& kPosition, bool bFlag)
{
    int iX = field_24;
    int iY = field_25;
    NiPoint3 kTargetCenter((float)((iX << 12) + 2048), (float)((iY << 12) + 2048), kPosition.z);
    AttachMarkersForSeenData(pvContext, kTargetCenter, bFlag);
    if (field_28)
        field_28->AddToNode(pvContext, kPosition, bFlag);
}

// Computes the save size, including the section count and any following sections.
// @fnv 0x0087a2a0
unsigned short IntSeenData::GetSaveSize(bool bFull)
{
    unsigned short usSize = 0;
    usSize += SeenData::GetSaveSize(false);
    if (!bFull)
        usSize += 2;
    usSize += 1;
    usSize += 1;
    if (field_28)
        usSize += field_28->GetSaveSize(true);
    return usSize;
}

struct SaveDataWriter
{
    void TESSaveLoadGame_SaveGameDataOLD(void* data, unsigned int size);
};
extern SaveDataWriter* DAT_011de45c;

// Writes the section's two bytes and, when not recursing, the section count, then recurses into the next section.
// @fnv 0x0087a330
// src: XBOX_PDB 0x0087a060
void IntSeenData::SaveGame_0087a060(bool abRecursing)
{
    IntSeenData* pSection;
    SeenData::SaveGame_0087a060(false);
    if (!abRecursing)
    {
        unsigned short usSectionCount;
        usSectionCount = 1;
        pSection = this;
        while ((pSection = pSection->field_28) != 0)
        {
            ++usSectionCount;
        }
        DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&usSectionCount, 2);
    }
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&field_24, 1);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&field_25, 1);
    if (field_28)
    {
        field_28->SaveGame_0087a060(true);
    }
}

extern float DAT_011a31e8;
// Converts a world position into cell-local x/y offsets, dividing by DAT_011a31e8, using centered or grid-aligned cell origins.
// @fnv 0x00879da0
void WorldToCellOffset(const NiPoint3& position, bool centered, int& x, int& y)
{
    if (centered)
    {
        int cellX = (TruncateFloatToInt(position.x) - 2048) >> 12;
        int cellY = (TruncateFloatToInt(position.y) - 2048) >> 12;
        x = TruncateFloatToInt(position.x) - ((cellX << 12) + 2048);
        x /= (int)DAT_011a31e8;
        y = TruncateFloatToInt(position.y) - ((cellY << 12) + 2048);
        y /= (int)DAT_011a31e8;
    }
    else
    {
        int gridX = TruncateFloatToInt(position.x) >> 12;
        int gridY = TruncateFloatToInt(position.y) >> 12;
        x = TruncateFloatToInt(position.x) - (gridX << 12);
        x /= (int)DAT_011a31e8;
        y = TruncateFloatToInt(position.y) - (gridY << 12);
        y /= (int)DAT_011a31e8;
    }
}

// Deletes the following sections; SeenData's destructor destroys the base part.
// @fnv 0x0087a170
IntSeenData::~IntSeenData()
{
    delete field_28;
}
