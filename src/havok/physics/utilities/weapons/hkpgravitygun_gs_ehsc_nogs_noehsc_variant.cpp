
// src/havok/physics/utilities/weapons/hkpgravitygun_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/weapons/hkpgravitygun.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/weapons/hkpgravitygun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpgravitygun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkArray.h"
#include "../../../../../include/FinishingFlag.h"

#include <xmmintrin.h>
extern double DAT_01016408;

struct Body_e45e
{
    int unk[0x1a0 / 4];
    __m128 m_kInertiaAndMassInv;
    void hkpRigidBody_setMassInv(float mass);
    void FUN_00c905b0();
    float getMassInv() const
    {
        float w;
        _mm_store_ss(&w, _mm_shuffle_ps(m_kInertiaAndMassInv, m_kInertiaAndMassInv, 0xff));
        return w;
    }
};

struct World_e45e
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    Body_e45e** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    Body_e45e* hkpGravityGun_dropObject(int index);
};
// @fnv 0x00e45e60
// src: XBOX_PDB 0x00e45e60
Body_e45e* World_e45e::hkpGravityGun_dropObject(int index)
{
    Body_e45e** volatile* pdata = (Body_e45e * * volatile*)&m_data;
    Body_e45e* body = (*pdata)[index];
    m_iElementCount--;
    int n = (m_iElementCount - index) * 4;
    Body_e45e** data = *pdata;
    char* dst = (char*)&data[index];
    const char* src = (const char*)&data[index + 1];
    for (int i = 0; i < n; i += 4)
        *(unsigned int*)(dst + i) = *(const unsigned int*)(src + i);
    body->hkpRigidBody_setMassInv((float)(body->getMassInv() * DAT_01016408));
    body->FUN_00c905b0();
    return body;
}
