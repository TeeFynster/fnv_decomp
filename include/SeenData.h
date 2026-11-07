#pragma once

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class NiNode;
class NiPoint3;

class SeenData
{
public:
    SeenData();

    virtual ~SeenData();
    virtual void AddToNode(NiNode* pNode, NiPoint3& kPos, bool bFlag);
    virtual unsigned short GetSaveSize(bool abRecursing);
    virtual void Save(BGSSaveFormBuffer* buffer);
    virtual void SaveGame_0087a060(bool abRecursing);
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual void LoadGame_0087a090(unsigned short count);

    bool IsBitSet(unsigned int index);
    bool SetSeenBit(unsigned int index, bool set);
    bool HasEnoughSeenPoints(const NiPoint3& point, const NiPoint3& offset);
    void AttachMarkersForSeenData(NiNode* parent, const NiPoint3& offset, int unused);
    void SaveFormData(void* buffer);
    void SetVtable();
    void* FUN_00879970(unsigned int flags);

    static void GetPositionForIndex(unsigned int index, NiPoint3& position);

    union
    {
        struct
        {
            unsigned int field_04;
            unsigned int field_08;
            unsigned int field_0c;
            unsigned int field_10;
            unsigned int field_14;
            unsigned int field_18;
            unsigned int field_1c;
            unsigned int field_20;
        };
        unsigned int m_uiSeenData[8];
    };
};
