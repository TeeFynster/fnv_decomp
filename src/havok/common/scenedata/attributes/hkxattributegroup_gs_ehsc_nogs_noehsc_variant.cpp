#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/havok/common/scenedata/attributes/hkxattributegroup_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/scenedata/attributes/hkxattributegroup.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/scenedata/attributes/hkxattributegroup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxattributegroup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkxAttributeGroup.h"
#include "../../../../../include/hkArray.h"

class hkQuaternion;
typedef ::__m128 LocalM128;

struct AttributeObj
{
    void* unk00;
    int unk04;
    hkQuaternion* m_quaternion;
};

struct S00e5cb40_Os
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(char* buf, int size);
    S00e5cb40_Os& ProcessAndReturnValue_00cc01c0(const char* s);
    S00e5cb40_Os& WriteName(const hkStringPtr& s);
    void FUN_00cc00e0();
};

struct S00e5cb40_Err
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void report(int level, unsigned int id, char* buf, const char* file, int line);
};

extern "C" S00e5cb40_Err* DAT_01268360;

struct S00e5cb40_Grp : hkxAttributeGroup
{
    AttributeObj* Runtime_ForwardCall_00e5c670(const char* name);
    int ProcessAndReturnValue_00e5cb40(const char* name, bool warnIfNotFound, hkQuaternion* out);
};

// @fnv 0x00e5cb40
// src: GUESS 0x00e5cb40 (confidence: low)
int S00e5cb40_Grp::ProcessAndReturnValue_00e5cb40(const char* name, bool warnIfNotFound, hkQuaternion* out)
{
    AttributeObj* attr = Runtime_ForwardCall_00e5c670(name);
    if (attr)
    {
        *(LocalM128*)out = *(LocalM128*)attr->m_quaternion;
        return 0;
    }
    if (warnIfNotFound)
    {
        char buf[512];
        S00e5cb40_Os os;
        os.FUN_00cb1600(buf, sizeof(buf));
        os.ProcessAndReturnValue_00cc01c0("Quaternion attribute ")
            .ProcessAndReturnValue_00cc01c0(name)
            .ProcessAndReturnValue_00cc01c0(" not found in ")
            .WriteName(m_name)
            .ProcessAndReturnValue_00cc01c0(" attribute group");
        DAT_01268360->report(1, 0xabbaab81, buf, ".\\Attributes\\hkxAttributeGroup.cpp", 0xb3);
        os.FUN_00cc00e0();
    }
    return 1;
}
