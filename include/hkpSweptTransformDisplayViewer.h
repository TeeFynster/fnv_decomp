#pragma once

#include "hkpWorldViewerBase.h"
#include "hkpEntityListener.h"
#include "hkpWorldPostSimulationListener.h"

struct SweptWorldData;

class hkpSweptTransformDisplayViewer : public hkpWorldViewerBase,
                                       public hkpEntityListener,
                                       public hkpWorldPostSimulationListener
{
public:
    struct WorldDataList
    {
        SweptWorldData** m_data;
        int m_iElementCount;
        int m_iCapacityState;

        SweptWorldData*& operator[](int index)
        {
            return m_data[index];
        }

        void clear()
        {
            m_iElementCount = 0;
        }

        void removeAt(int index);
    };

    virtual ~hkpSweptTransformDisplayViewer() throw();

    int FindEntryIndex(int);
    int FindEntryIndex(void* key) const;
    void ClearSweptEntry(int index);
    void RemoveWorldData(int);
    void NotifyItems();
    void RemoveWorldDataIfFound(int a);

    union
    {
        WorldDataList m_kWorldDataList;
        struct
        {
            SweptWorldData** m_entries;
            int m_iNumberOfEntries;
            int m_iCapacityState;
        };
    };
};
