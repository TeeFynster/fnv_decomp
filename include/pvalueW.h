#pragma once

class pvalueW
{
public:
    wchar_t* pv_valuename;
    int pv_valuelen;
    void* pv_value_context;
    unsigned long pv_type;
};
