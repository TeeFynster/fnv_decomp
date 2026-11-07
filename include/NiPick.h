#pragma once

#include "NiAVObject.h"
#include "NiPoint2.h"
#include "NiPoint3.h"

class NiNode;
class NiPickResults;
class PickRecord;
class PickNode;
class NiPoint3;

class NiPick
{
public:
    enum PickType { FIND_ALL = 0, FIND_FIRST = 1 };
    enum SortType { SORT = 0, NO_SORT = 1 };
    enum IntersectType { BOUND_INTERSECT = 0, TRIANGLE_INTERSECT = 1 };
    enum CoordinateType { MODEL_COORDINATES = 0, WORLD_COORDINATES = 1 };

    class Record
    {
    public:
        NiPointer<NiAVObject> m_pReferencedObject;
        NiPointer<NiNode> m_pParentNode;
        NiPoint3 m_vPoint;
        float m_fHitDistance;
        unsigned short m_usFlags;
        unsigned short m_ausPadding[3];
        float m_texture[2];
        NiPoint3 m_vHitNormal;
        float m_kDiffuseColor[4];

        NiAVObject* AnimatingText_GetFullText();
        const NiPoint2* FUN_00891170();
    };

    class Results
    {
    public:
        void** m_ppVirtualMethodTable;
        union { Record** m_pBase; Record** data; };
        union { unsigned short m_usMaxSize; unsigned short capacity; };
        union { unsigned short m_usSize; unsigned short size; };
        union { unsigned short m_usESize; unsigned short effective; };
        union { unsigned short m_usGrowBy; unsigned short grow; };
        union { unsigned int m_uiValidCount; unsigned int valid; };

        ~Results();
        Record* GetAt(unsigned int index) const
        {
            return m_pBase[index];
        }
        void SetAt(unsigned int index, Record* record)
        {
            if (index >= m_usSize)
            {
                m_usSize = (unsigned short)(index + 1);
                ++m_usESize;
            }
            else if (!m_pBase[index])
            {
                ++m_usESize;
            }
            m_pBase[index] = record;
        }
        Record* ProcessArray_GetItem(unsigned int);
        void InvokeCallbacks();
        void FindHighestPriorityCallback();
        void Clear() throw();
    };

    unsigned int pickType;
    unsigned int sortType;
    unsigned int intersectType;
    unsigned int coordinateType;
    unsigned char frontOnly;
    unsigned char returnNormals;
    unsigned char returnTextures;
    unsigned char returnColors;
    void* root;
    unsigned int resultVtable;
    unsigned int resultData;
    unsigned int resultCapacity;
    unsigned int resultSize;
    unsigned int resultGrow;
    unsigned int resultCount;
    unsigned char flags30;
    unsigned char flags31;
    unsigned char flags32;
    unsigned char flags33;

    NiPick();
    NiPick(int, int);
    ~NiPick();
    NiAVObject* GetRoot() const
    {
        return static_cast<NiAVObject*>(root);
    }
    void SetTarget_00705fc0(NiAVObject*);
    void SetTarget_00705fc0(void*);
    void SetTarget_00705fc0(PickNode*);
    void SetByteAtOffset17(bool);
    void SetByteAtOffset17(int);
    bool FUN_00e98e20(const NiPoint3&, const NiPoint3&, bool);
    bool FUN_00e98e20(const NiPoint3&, const NiPoint3&, int);
    bool FUN_00e98e20(NiPoint3*, NiPoint3*, int);
    bool FUN_00e98e20(NiPoint3&, NiPoint3&, bool);
    Results* FUN_00500940();
    PickRecord* FUN_00500940(unsigned int);
    void FUN_006ecd40(int);
    void FUN_006ecd40(unsigned int);
    void SetByteAtOffset30(bool);
    void SetByteAtOffset30(int);
    bool PerformPick(const NiPoint3&, const NiPoint3&, bool);
    NiAVObject* AnimatingText_GetFullText();
    const NiPoint2* FUN_00891170();
    Record* ProcessArray_GetItem(unsigned int);
    NiPickResults* GetResults();
    void RadioEntry_Data_SetLastSignalStrength(bool bValue);
    void* ScalarDeletingDestructor(unsigned int flags);
    void InvokeCallbacks();
    void FindHighestPriorityCallback();
    void Clear() throw();
};
