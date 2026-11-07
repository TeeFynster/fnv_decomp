// fallout_shared/region system/tesregionpointlist.cpp: RegionPointList, TESObjectCELL, PointList (14 functions)

#include "../../../include/BSThread.h"
#include "../../../include/NiPoint2.h"


#include "../../../include/BSSimpleList.h"

#include "../../../include/TESFile.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESRegionList.h"
#include "tesregionpointlist_cell.h"

class RegionPoint
{
  public:
    NiPoint2 Point;
    RegionPoint(const NiPoint2& apPoint);
    float GetX();
    float GetY();
};

struct TESRegionPointList__ScaleResult
{
};

int Warning(const char* apFormat, ...);

template <int Value> struct EndianSizeTag
{
};
void BSEndian(float* apData, EndianSizeTag<4> aeType);

enum
{
    CHUNK_ID_RPLD_ID = 1145851986,
};

const char kInvalidRegionPointListLabel[] = "Invalid Region Point List data in file \"%s\".";

// Adjacent chunk-size/point-count pair. The two values share one 8-byte
// stack slot with the count first, which plain sequential locals do not
// reproduce under the recorded flags, so they are kept in one aggregate.
struct TESRegionPointListLoadCounts
{
    unsigned int uiPointCount;
    unsigned int uiChunkSize;
};

class RegionPointList : public BSSimpleList<RegionPoint*>
{
  public:
    TESRegionPointList__ScaleResult* m_pScaleResult;  // +0x8
    bool m_bOwnsPointMemory;                          // +0xC
    unsigned char layoutPaddingD[3];
    NiPoint2 m_kMinimums;                  // +0x10
    NiPoint2 Maximums;                     // +0x18
    unsigned int m_uiDistanceInsideAtMax;  // +0x20
    unsigned int iCount;                   // +0x24
    ~RegionPointList();
    void Clear();
    bool ReadPointsFromFile(TESFile* apFile);
};

// @fnv 0x004f7740
RegionPointList::~RegionPointList()
{
    Clear();
    if (m_pScaleResult)
        delete m_pScaleResult;
}

// Reads an RPLD chunk of NiPoint2 pairs, endian-swaps them, wraps each in a point object, updates bounds and adds it to the list.
// @fnv 0x004f79f0
bool RegionPointList::ReadPointsFromFile(TESFile* apFile)
{
    if (!apFile || apFile->GetChunkID() != CHUNK_ID_RPLD_ID)
        return false;
    TESRegionPointListLoadCounts counts;
    counts.uiChunkSize = apFile->GetChunkSize();
    counts.uiPointCount = counts.uiChunkSize >> 3;
    if (counts.uiChunkSize % 8 != 0)
    {
        Warning(kInvalidRegionPointListLabel, apFile->GetFilename());
        return false;
    }
    if (counts.uiChunkSize != 0 && counts.uiPointCount != 0)
    {
        NiPoint2* pElementBuffer = new NiPoint2[counts.uiPointCount];
        apFile->GetChunkData(pElementBuffer, counts.uiChunkSize);
        iCount = 0;
        for (unsigned int i = 0; i < counts.uiPointCount; i++)
        {
            if (apFile->IsEndianConversionRequired())
            {
                BSEndian(&pElementBuffer[i].x, EndianSizeTag<4>());
                BSEndian(&pElementBuffer[i].y, EndianSizeTag<4>());
            }
            RegionPoint* pPoint = new RegionPoint(pElementBuffer[i]);
            if (m_kMinimums.x > pPoint->GetX())
                m_kMinimums.x = pPoint->GetX();
            if (m_kMinimums.y > pPoint->GetY())
                m_kMinimums.y = pPoint->GetY();
            if (Maximums.x < pPoint->GetX())
                Maximums.x = pPoint->GetX();
            if (Maximums.y < pPoint->GetY())
                Maximums.y = pPoint->GetY();
            AddHead(pPoint);
            iCount++;
        }
        delete[] pElementBuffer;
        return true;
    }
    return false;
}

// Deletes the given region point list object.
// @fnv 0x004f0a10
void TESRegionPointList_Delete(RegionPointList* pointList)
{
    delete pointList;
}

// @fnv 0x00547110
TESRegionList* TESObjectCELL::GetRegionList(bool create)
{
    TESRegionList* result = 0;
    if (IsCellInterior())
        return 0;
    result = reinterpret_cast<TESRegionPointList_CellExtraList*>(formData + 4)->ExtraDataList_GetRegionList();
    if (!result && create)
    {
        result = new TESRegionList(0);
        reinterpret_cast<TESRegionPointList_CellExtraList*>(formData + 4)->SetRegionList(result);
    }
    return result;
}

struct FUN_004f7dd0_shell : public RegionPointList
{
    void TESRegionPointList_Clear();
};

RegionPoint*& __fastcall _ref_006815c0(void* pThis);
void __fastcall _ref_0063f7b0(void* pThis);
extern float const DAT_01015f5c;

// @fnv 0x004f7dd0
// src: COMMUNITY 0x004f7dd0
void FUN_004f7dd0_shell::TESRegionPointList_Clear()
{
    RegionPoint* pdelete = 0;
    while (reinterpret_cast<BSThread*>(this)->GetThreadID() > 0)
    {
        pdelete = _ref_006815c0(this);
        _ref_0063f7b0(this);
        iCount = iCount - 1;
        if (pdelete != 0 && m_bOwnsPointMemory)
        {
            delete pdelete;
        }
    }
    iCount = 0;
    m_kMinimums.y = 3.4028234663852886e+38f;
    m_kMinimums.x = 3.4028234663852886e+38f;
    Maximums.y = DAT_01015f5c;
    Maximums.x = DAT_01015f5c;
}

namespace fnv_004f81e0 {
struct FUN_004f81e0_shell : public RegionPointList
{
    bool TESRegionPointList_Validate(bool);
};

struct FUN_004f8220_stub
{
    bool TESRegionPointList_SelfIntersects(bool);
};
// Returns false if abMinPointsTest is set and GetThreadID() is below 3, or if FUN_004f8220(true) returns true; otherwise returns true.
// @fnv 0x004f81e0
// src: COMMUNITY 0x004f81e0
bool FUN_004f81e0_shell::TESRegionPointList_Validate(bool abMinPointsTest)
{
    if ((abMinPointsTest && ((BSThread*)this)->GetThreadID() < 3) || ((FUN_004f8220_stub*)this)->TESRegionPointList_SelfIntersects(true))
        return false;
    return true;
}
}  // namespace fnv_004f81e0

RegionPoint*& __fastcall _ref_006815c0(void* pThis);
void __fastcall _ref_0063f7b0(void* pThis);

class TESRegionPointDist : public RegionPoint
{
  public:
    float GetDistanceToOtherPoint(RegionPoint* apOther);
};

struct FUN_004f7ca0_shell : public RegionPointList
{
    bool CheckSomething(bool abFlag);
    bool AddPoint(RegionPoint* apPoint, float afMinDistance);
};

// Adds apPoint to the list if it is at least afMinDistance from the region point, updates bounds and count, and returns whether it was added.
// @fnv 0x004f7ca0
bool FUN_004f7ca0_shell::AddPoint(RegionPoint* apPoint, float afMinDistance)
{
    if (!apPoint)
    {
        return false;
    }
    if (_ref_006815c0(this))
    {
        if (((TESRegionPointDist*)_ref_006815c0(this))->GetDistanceToOtherPoint(apPoint) <
            afMinDistance * afMinDistance)
        {
            return false;
        }
    }
    AddHead(apPoint);
    if (CheckSomething(false))
    {
        _ref_0063f7b0(this);
        return false;
    }
    iCount++;
    if (apPoint->GetX() < m_kMinimums.x)
    {
        m_kMinimums.x = apPoint->GetX();
    }
    if (apPoint->GetY() < m_kMinimums.y)
    {
        m_kMinimums.y = apPoint->GetY();
    }
    if (apPoint->GetX() > Maximums.x)
    {
        Maximums.x = apPoint->GetX();
    }
    if (apPoint->GetY() > Maximums.y)
    {
        Maximums.y = apPoint->GetY();
    }
    return true;
}

extern double const DAT_010231b0;
extern float const DAT_01016970;

struct FUN_004f7e80_shell : public RegionPointList
{
    float TESRegionPointList_GetMinX();
};

RegionPoint*& __fastcall _ref_006815c0(void* pThis);
float __fastcall AStarSearch_EvaluateValue_006a7f50(RegionPoint* pPoint);
void* __fastcall FUN_00726070(void* pNode);

// @fnv 0x004f7e80
// src: COMMUNITY 0x004f7e80
float FUN_004f7e80_shell::TESRegionPointList_GetMinX()
{
    float fMinValue = DAT_01016970;
    void* node2 = this;
    if (DAT_010231b0 > m_kMinimums.x)
    {
        return m_kMinimums.x;
    }
    while (node2 != 0 && _ref_006815c0(node2) != 0)
    {
        if (fMinValue > AStarSearch_EvaluateValue_006a7f50(_ref_006815c0(node2)))
        {
            fMinValue = AStarSearch_EvaluateValue_006a7f50(_ref_006815c0(node2));
        }
        node2 = FUN_00726070(node2);
    }
    return fMinValue;
}

namespace fnv_004f7fa0 {
extern float DAT_01016970;
extern const double DAT_010231b0;

struct RegionPointNode : BSSimpleList<RegionPoint*>
{
    RegionPointNode* FUN_00726070();
};

struct FUN_004f7fa0_shell : RegionPointList
{
    float GetMinimumY();
};

// @fnv 0x004f7fa0
float FUN_004f7fa0_shell::GetMinimumY()
{
    float minimumY = DAT_01016970;
    RegionPointNode* current = (RegionPointNode*)this;

    if (m_kMinimums.y < DAT_010231b0)
    {
        return m_kMinimums.y;
    }

    while (current && _ref_006815c0(current))
    {
        if (_ref_006815c0(current)->GetY() < minimumY)
        {
            minimumY = _ref_006815c0(current)->GetY();
        }
        current = current->FUN_00726070();
    }
    return minimumY;
}
}  // namespace fnv_004f7fa0

extern const double DAT_010241b0;
BSSimpleList<RegionPoint*>* __fastcall FUN_00726070(BSSimpleList<RegionPoint*>*);
struct FUN_004f8030_shell : RegionPointList
{
    float GetMaxY();
};
// Returns Maximums.y if it exceeds DAT_010241b0, otherwise scans the list for the largest GetY() value, defaulting to DAT_01015f5c.
// @fnv 0x004f8030
float FUN_004f8030_shell::GetMaxY()
{
    float fMaximum = DAT_01015f5c;
    BSSimpleList<RegionPoint*>* pkPoint = this;
    if (Maximums.y > DAT_010241b0)
        return Maximums.y;
    while (pkPoint && _ref_006815c0(pkPoint))
    {
        if (fMaximum < _ref_006815c0(pkPoint)->GetY())
            fMaximum = _ref_006815c0(pkPoint)->GetY();
        pkPoint = FUN_00726070(pkPoint);
    }
    return fMaximum;
}

struct TESRegionPointList_ref : RegionPointList
{
    TESRegionPointList_ref(bool owns);
    bool AddPoint(RegionPoint* point, float scale);
    TESRegionPointList_ref* FUN_00726070();
};
struct TESRegionPoint_ref : RegionPoint
{
    RegionPoint* TESRegionPoint_Copy(int option);
};
struct FUN_004f80c0_shell : RegionPointList
{
    RegionPointList* CloneRegionPointList(RegionPointList* out);
};
// Builds a TESRegionPointList_ref from the points of the current list, cloning each point when the result owns its points, and returns it.
// @fnv 0x004f80c0
RegionPointList* FUN_004f80c0_shell::CloneRegionPointList(RegionPointList* apOutList)
{
    FUN_004f80c0_shell* current = this;
    RegionPointList* result = apOutList ? apOutList : new TESRegionPointList_ref(m_bOwnsPointMemory);
    RegionPoint* clonedPoint = 0;
    while (current != 0)
    {
        if (result->m_bOwnsPointMemory)
        {
            clonedPoint = reinterpret_cast<TESRegionPoint_ref*>(_ref_006815c0(current))->TESRegionPoint_Copy(0);
            if (!reinterpret_cast<TESRegionPointList_ref*>(result)->AddPoint(clonedPoint, 0.0f))
            {
                delete clonedPoint;
            }
        }
        else
        {
            reinterpret_cast<TESRegionPointList_ref*>(result)->AddPoint(_ref_006815c0(current), 0.0f);
        }
        current =
            reinterpret_cast<FUN_004f80c0_shell*>(reinterpret_cast<TESRegionPointList_ref*>(current)->FUN_00726070());
    }
    return result;
}

struct PointNode
{
    PointNode* FUN_00726070();
    RegionPoint** FUN_006815c0();
};
bool TESRegionPoint_LineSegmentsIntersect(RegionPoint*, RegionPoint*, RegionPoint*, RegionPoint*);
struct PointList : PointNode
{
    unsigned int FUN_0059bb30();
    bool TESRegionPointList_SelfIntersects(bool);
};
// Walks the point list and returns true if any four consecutive points pass the FUN_004f7310 test, wrapping to the head when closed.
// @fnv 0x004f8220
// src: COMMUNITY 0x004f8220
bool PointList::TESRegionPointList_SelfIntersects(bool closed)
{
    bool p = false;
    if (FUN_0059bb30() < 4)
        return false;
    PointNode* c = this;
    PointNode* j = c->FUN_00726070();
    PointNode* e = j->FUN_00726070();
    PointNode* l = e->FUN_00726070();
    while (j->FUN_00726070())
    {
        e = j->FUN_00726070();
        if (e)
            l = e->FUN_00726070();
        else
            l = 0;
        p = false;
        do
        {
            if (!l)
            {
                if (closed && c != this)
                {
                    l = this;
                    p = true;
                }
                else
                    p = true;
            }
            if (c && j && e && l &&
                TESRegionPoint_LineSegmentsIntersect(*c->FUN_006815c0(), *j->FUN_006815c0(), *e->FUN_006815c0(), *l->FUN_006815c0()))
                return true;
            e = l;
            if (l)
                l = l->FUN_00726070();
        } while (!p);
        c = j;
        j = j->FUN_00726070();
    }
    return false;
}

#include <string.h>
void TESForm_AddChunk_00485910(unsigned int chunk, unsigned int value);
void TESForm_AddChunkArray_00485710(unsigned int chunk, void* data, unsigned int points);
struct RegionPointAccess : RegionPoint
{
    NiPoint2& FUN_006815c0();
};
struct RegionNode : PointNode
{
    bool FUN_008256d0();
    RegionNode* FUN_00726070();
};
struct FUN_004f77c0_shell : RegionPointList
{
    void TESRegionPointList_Save();
};
// Calls FUN_00485910 with the distance value, then conditionally calls FUN_00485710 with the collected points.
// @fnv 0x004f77c0
// src: COMMUNITY 0x004f77c0
void FUN_004f77c0_shell::TESRegionPointList_Save()
{
    TESForm_AddChunk_00485910(0x494c5052, m_uiDistanceInsideAtMax);
    RegionNode* node = reinterpret_cast<RegionNode*>(this);
    if (!node->FUN_008256d0())
    {
        unsigned int points = 0;
        unsigned int count = 0;
        unsigned int capacity = 1024;
        NiPoint2* blocks = new NiPoint2[capacity * sizeof(NiPoint2)];
        while (node && !node->FUN_008256d0())
        {
            blocks[points] = static_cast<RegionPointAccess*>(*node->FUN_006815c0())->FUN_006815c0();
            ++points;
            if (points >= capacity)
            {
                ++count;
                capacity = (count + 1) * 1024;
                NiPoint2* oldPoints = blocks;
                blocks = new NiPoint2[capacity * sizeof(NiPoint2)];
                memcpy(blocks, oldPoints, points * sizeof(NiPoint2));
                delete[] oldPoints;
            }
            node = node->FUN_00726070();
        }
        if (points)
            TESForm_AddChunkArray_00485710(0x444c5052, blocks, points * 2);
        delete[] blocks;
    }
}

typedef BSSimpleList<RegionPoint*> RegionPointNode;

RegionPoint*& __fastcall _ref_006815c0(void* pThis);
float __fastcall AStarSearch_EvaluateValue_006a7f50(void* pThis);
extern double const DAT_010241b0;

struct FUN_004f7f10_cls : public RegionPointList
{
    float TESRegionPointList_GetMaxX();
};

// @fnv 0x004f7f10
// src: COMMUNITY 0x004f7f10
float FUN_004f7f10_cls::TESRegionPointList_GetMaxX()
{
    float best3 = DAT_01015f5c;
    RegionPointNode* pNode = (RegionPointNode*)this;
    if ((double)this->Maximums.x > DAT_010241b0)
    {
        return this->Maximums.x;
    }
    while (pNode != 0 && _ref_006815c0(pNode) != 0)
    {
        if (best3 < AStarSearch_EvaluateValue_006a7f50(_ref_006815c0(pNode)))
        {
            best3 = AStarSearch_EvaluateValue_006a7f50(_ref_006815c0(pNode));
        }
        pNode = FUN_00726070(pNode);
    }
    return best3;
}
