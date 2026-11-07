// staging/blk_00a60000_od.cpp: free functions (4 functions)

#include "fnv_asm_helpers.h"
#include "../../include/NiPoint3.h"
// src/staging/blk_00a60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern unsigned char DAT_011f4a54;
extern int DAT_011f4a50;

int __cdecl NiTransformVectorsPentium();
int __cdecl NiTransformPointsPentium();
void __cdecl NiProcessorSpecificCode_IdentifyProcessor();
int __cdecl NiProcessorSpecificCode_TransformPointsBasic();
int __cdecl NiProcessorSpecificCode_TransformVectorsBasic();
void __cdecl NiProcessorSpecificCode_SetVectorTransformFunction(int);
void __cdecl NiProcessorSpecificCode_SetPointTransformFunction(int);

// @fnv 0x00a74da0
// src: COMMUNITY 0x00a74da0
void __cdecl NiProcessorSpecificCode_OptimizeMainEngineForProcessor()
{
    if (DAT_011f4a54 == 0)
        NiProcessorSpecificCode_IdentifyProcessor();
    NiProcessorSpecificCode_SetPointTransformFunction((int)NiProcessorSpecificCode_TransformPointsBasic);
    NiProcessorSpecificCode_SetVectorTransformFunction((int)NiProcessorSpecificCode_TransformVectorsBasic);
    int count = DAT_011f4a50;
    if (count > 0)
    {
        if (count > 6)
            goto done;
        NiProcessorSpecificCode_SetPointTransformFunction((int)NiTransformPointsPentium);
        NiProcessorSpecificCode_SetVectorTransformFunction((int)NiTransformVectorsPentium);
    }
done:
    ;
}

struct XfRSLocal {
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    float tx;
    float ty;
    float tz;
    float scale;
};

// Transforms count points from in to out by the 3x3 matrix in xf, then scales and translates each result.
// @fnv 0x00a74bc0
// src: COMMUNITY 0x00a74bc0
void NiProcessorSpecificCode_TransformPointsBasic(unsigned short count, NiPoint3* in, NiPoint3* out, XfRSLocal* xf)
{
    XfRSLocal* pXf = xf;
    for (unsigned int i = 0; i < count; i++, in++, out++) {
        out->x = (pXf->m00 * in->x + in->y * pXf->m01 + in->z * pXf->m02) * xf->scale + xf->tx;
        out->y = (pXf->m10 * in->x + in->y * pXf->m11 + in->z * pXf->m12) * xf->scale + xf->ty;
        out->z = (pXf->m20 * in->x + in->y * pXf->m21 + in->z * pXf->m22) * xf->scale + xf->tz;
    }
}

struct A74CB0Matrix3 {
    float m_afEntries[3][3];
};

// @fnv 0x00a74cb0
// src: COMMUNITY 0x00a74cb0
void NiProcessorSpecificCode_TransformVectorsBasic(unsigned short ausCount, const NiPoint3* pkIn, NiPoint3* pkOut, const A74CB0Matrix3* pkMatrix) {
    const A74CB0Matrix3* pkM = pkMatrix;
    for (unsigned int i = 0; i < ausCount; i++, pkIn++, pkOut++) {
        pkOut->x = pkM->m_afEntries[0][0] * pkIn->x + pkIn->y * pkM->m_afEntries[0][1] + pkIn->z * pkM->m_afEntries[0][2];
        pkOut->y = pkM->m_afEntries[1][0] * pkIn->x + pkIn->y * pkM->m_afEntries[1][1] + pkIn->z * pkM->m_afEntries[1][2];
        pkOut->z = pkM->m_afEntries[2][0] * pkIn->x + pkIn->y * pkM->m_afEntries[2][1] + pkIn->z * pkM->m_afEntries[2][2];
    }
}

extern unsigned char DAT_011f4a54;
extern int DAT_011f4a50;
extern int DAT_011f4a58;

// Detects the CPU feature level by querying CPUID and stores the result in DAT_011f4a50, setting DAT_011f4a54 to 1 on entry.
// @fnv 0x00a74a10
// src: COMMUNITY 0x00a74a10
void NiProcessorSpecificCode_IdentifyProcessor()
{
    DAT_011f4a54 = 1;
    __try {
        fnv_CpuidMaxExtended(DAT_011f4a58);
    } __except (1) {
        DAT_011f4a50 = 0;
        return;
    }
    if (DAT_011f4a58 & 0x80000000) {
        __try {
            fnv_CpuidLegacyExtended(DAT_011f4a58);
        } __except (1) {
            DAT_011f4a58 = 0;
        }
        if (DAT_011f4a58 & 0x80000000) {
            DAT_011f4a50 = 6;
            return;
        }
    }
    __try {
        fnv_CpuidFeatures(DAT_011f4a58);
    } __except (1) {
        DAT_011f4a50 = 0;
        return;
    }
    if ((DAT_011f4a58 & 0x800000) == 0) {
        if ((DAT_011f4a58 & 0x8000) == 0) {
            DAT_011f4a50 = 1;
            return;
        } else {
            DAT_011f4a50 = 3;
            return;
        }
    } else {
        if ((DAT_011f4a58 & 0x8000) == 0) {
            DAT_011f4a50 = 2;
            return;
        } else {
            DAT_011f4a50 = 4;
        }
    }
    if ((DAT_011f4a58 & 0x2000000) == 0) return;
    DAT_011f4a50 = 5;
}
