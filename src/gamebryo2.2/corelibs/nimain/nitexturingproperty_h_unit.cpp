// gamebryo2.2/corelibs/nimain/nitexturingproperty_h_unit.cpp: NiTexturingProperty, AudioLoadTask (1 function)

#include "../../../../include/AudioLoadTask.h"
#include "../../../../include/NiTexturingProperty.h"

void NiTexturingProperty::SetBaseMapFilterMode(FilterMode mode)
{
    Map* baseMap;
    baseMap = m_kStringArray.GetAt(0);

    if (baseMap == 0)
    {
        baseMap = new Map;
        m_kStringArray.SetAt(0, baseMap);
    }

    baseMap->SetFilterMode(mode);
}

void NiTexturingProperty::SetBaseMapClampMode(ClampMode mode)
{
    Map* baseMap;
    baseMap = m_kStringArray.GetAt(0);

    if (baseMap == 0)
    {
        baseMap = new Map;
        m_kStringArray.SetAt(0, baseMap);
    }

    baseMap->SetClampMode(mode);
}

// @fnv 0x00ae8b80
unsigned char AudioLoadTask::GetFileIndex()
{
    return 2;
}
