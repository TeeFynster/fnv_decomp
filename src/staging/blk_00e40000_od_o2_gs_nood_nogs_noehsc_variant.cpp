
// src/staging/blk_00e40000_od_o2_gs_nood_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /Gy (unit src/staging/blk_00e40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkError.h"
#include "../../include/hkOstream.h"
#include "../../include/hkVector4.h"

extern const char str_010ecd48[];
extern const char str_010eccfc[];
extern const char str_010ecd0c[];
extern const char str_010eccc8[];

struct VectorAttribute
{
    const char* m_name;
    int m_type;
    hkVector4* m_uiFilterValue;
};

struct AttributeHolder
{
    VectorAttribute* Runtime_ForwardCall_00e5c650(const char* name);
    int ProcessAndReturnValue_00e5ca80(const char* name, unsigned char warn, hkVector4& out);
};

// @fnv 0x00e5ca80
// src: GUESS 0x00e5ca80 (confidence: low)
int AttributeHolder::ProcessAndReturnValue_00e5ca80(const char* name, unsigned char warn, hkVector4& out)
{
    VectorAttribute* attr = Runtime_ForwardCall_00e5c650(name);
    if (attr)
    {
        out.m_vComponents = attr->m_uiFilterValue->m_vComponents;
        return 0;
    }
    if (warn)
    {
        char assertBuf[512];
        hkOstream ostr(assertBuf, sizeof(assertBuf));
        ostr << str_010ecd48 << name << str_010eccfc << (const void*)this << str_010ecd0c;
        hkError::s_instance->message(1, 0xabbaab81, assertBuf, str_010eccc8, 0xa2);
    }
    return 1;
}
