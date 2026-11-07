#pragma once

class bhkFilter
{
public:
    unsigned int value;

    bhkFilter();
    bhkFilter(int);

    int CFilter_GetLayer();
    int __thiscall CFilter_GetGroup();
    int CFilter_GetPart();
    int GetType();
    int __thiscall CFilter_GetBipedPart();
};
