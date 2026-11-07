#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/staging/blk_00d20000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/FinishingFlag.h"
#include "../../include/hkpCdPointCollector.h"
#include "../../include/hkpCollisionDispatcher.h"

__forceinline hkpCdPointCollector::hkpCdPointCollector()
{
    m_fEarlyOutDistance = 3.40282e+38f;
}

__forceinline hkpCdPointCollector::~hkpCdPointCollector() throw()
{}

typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    float _mm_cvtss_f32(LocalM128);
    void _mm_store_ss(float*, LocalM128);
}

// This unit supplies its SSE intrinsic type and declarations above.
#define _INCLUDED_MM2
#include "../../include/hkVector4.h"
#include "../../include/hkVector4.h"
#include <string.h>


__forceinline hkVector4::hkVector4(const hkVector4& vector)
{
    memcpy(this, &vector, sizeof(*this));
}


__forceinline void hkVector4::setBroadcast3(const hkVector4& vector)
{
    m_vComponents = _mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 0xff);
}

__forceinline void hkVector4::addMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
}

__forceinline float hkVector4::dot3scalar(const hkVector4& vector) const
{
    LocalM128 sq = _mm_mul_ps(m_vComponents, vector.m_vComponents);
    LocalM128 y = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    LocalM128 z = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), y);
    float r;
    _mm_store_ss(&r, z);
    return r;
}


struct ContactBody
{
    char unk00[0xa];
    unsigned char m_qualityA;
    unsigned char unk0b;
    unsigned char m_qualityC;
    char unk0d[0xb0 - 0xd];
    float m_uiCommandId;
    char unkb4[0xd0 - 0xb4];
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    char unkf0[0xfc - 0xf0];
    float m_limitA;
    char unk100[0x10c - 0x100];
    float m_limitC;
};

// @fnv 0x00d28560
// src: GUESS 0x00d28560 (confidence: low)
bool Object_ProcessEntries_00d28560(void* unused, char** items, int count, int offset)
{
    for (int i = count - 1; i >= 0; i--)
    {
        ContactBody* body = (ContactBody*)(*items + offset);
        float t0 = body->m_uiCommandId;
        float t = (1.0f < t0) ? 1.0f : t0;
        float lin = body->m_kTranslationalVelocity.dot3scalar(body->m_kTranslationalVelocity);
        float ang = body->m_kAngularVelocity.dot3scalar(body->m_kAngularVelocity);
        float r = t * t * ang + lin;
        r = r * 0.25 - 0.010000000298023226;
        if ((body->m_qualityA & 0x7f) > (body->m_qualityC & 0x7f))
        {
            if (r > body->m_limitA)
            {
                return false;
            }
        }
        else if (r > body->m_limitC)
        {
            return false;
        }
        items++;
    }
    return true;
}

namespace fnv_00d31610 {

extern LocalM128 DAT_010c4c00;


struct LinearCastVertex
{
    hkVector4 m_vContactPosition;
    hkVector4 m_direction;
    hkVector4 m_unk20;
};

struct GskVertexIds
{
    unsigned char m_numA : 4;
    unsigned char m_numB : 4;
};

struct GskCache
{
    unsigned short m_ausVertexIds[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    GskVertexIds m_counts;
    unsigned char m_unk304b;

    __forceinline void flip()
    {
        unsigned char lo = m_counts.m_numA;
        m_counts.m_numA = m_counts.m_numB;
        m_counts.m_numB = lo;

        unsigned char dimA = m_ucDimensionA;
        m_ucDimensionA = m_ucDimensionB;
        m_ucDimensionB = dimA;

        int last = m_ucDimensionA + m_ucDimensionB - 1;
        unsigned short t = m_ausVertexIds[0];
        m_ausVertexIds[0] = m_ausVertexIds[last];
        m_ausVertexIds[last] = t;

        if ((m_ucDimensionB & m_ucDimensionA) == 2)
        {
            unsigned short t1 = m_ausVertexIds[1];
            m_ausVertexIds[1] = m_ausVertexIds[2];
            m_ausVertexIds[2] = t1;
        }
    }
};

struct LinearCastState
{
    LinearCastVertex* m_kRayEnd;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    LinearCastVertex m_v000;
    LinearCastVertex m_v001;
    LinearCastVertex m_v002;
    LinearCastVertex m_v003;
    LinearCastVertex m_v004;
    LinearCastVertex m_v005;
    LinearCastVertex m_v006;
    LinearCastVertex m_v007;
    LinearCastVertex m_v008;
    LinearCastVertex m_v009;
    LinearCastVertex m_v010;
    LinearCastVertex m_v011;
    LinearCastVertex m_v012;
    LinearCastVertex m_v013;
    LinearCastVertex m_v014;
    LinearCastVertex m_v015;
    LinearCastVertex m_v016;
    LinearCastVertex m_v017;
    LinearCastVertex m_v018;
    LinearCastVertex m_v019;
    LinearCastVertex m_v020;
    LinearCastVertex m_v021;
    LinearCastVertex m_v022;
    LinearCastVertex m_v023;
    LinearCastVertex m_v024;
    LinearCastVertex m_v025;
    LinearCastVertex m_v026;
    LinearCastVertex m_v027;
    LinearCastVertex m_v028;
    LinearCastVertex m_v029;
    LinearCastVertex m_v030;
    LinearCastVertex m_v031;
    LinearCastVertex m_v032;
    LinearCastVertex m_v033;
    LinearCastVertex m_v034;
    LinearCastVertex m_v035;
    LinearCastVertex m_v036;
    LinearCastVertex m_v037;
    LinearCastVertex m_v038;
    LinearCastVertex m_v039;
    LinearCastVertex m_v040;
    LinearCastVertex m_v041;
    LinearCastVertex m_v042;
    LinearCastVertex m_v043;
    LinearCastVertex m_v044;
    LinearCastVertex m_v045;
    LinearCastVertex m_v046;
    LinearCastVertex m_v047;
    LinearCastVertex m_v048;
    LinearCastVertex m_v049;
    LinearCastVertex m_v050;
    LinearCastVertex m_v051;
    LinearCastVertex m_v052;
    LinearCastVertex m_v053;
    LinearCastVertex m_v054;
    LinearCastVertex m_v055;
    LinearCastVertex m_v056;
    LinearCastVertex m_v057;
    LinearCastVertex m_v058;
    LinearCastVertex m_v059;
    LinearCastVertex m_v060;
    LinearCastVertex m_v061;
    LinearCastVertex m_v062;
    LinearCastVertex m_v063;
    LinearCastVertex m_v064;
    LinearCastVertex m_v065;
    LinearCastVertex m_v066;
    LinearCastVertex m_v067;
    LinearCastVertex m_v068;
    LinearCastVertex m_v069;
    LinearCastVertex m_v070;
    LinearCastVertex m_v071;
    LinearCastVertex m_v072;
    LinearCastVertex m_v073;
    LinearCastVertex m_v074;
    LinearCastVertex m_v075;
    LinearCastVertex m_v076;
    LinearCastVertex m_v077;
    LinearCastVertex m_v078;
    LinearCastVertex m_v079;
    LinearCastVertex m_v080;
    LinearCastVertex m_v081;
    LinearCastVertex m_v082;
    LinearCastVertex m_v083;
    LinearCastVertex m_v084;
    LinearCastVertex m_v085;
    LinearCastVertex m_v086;
    LinearCastVertex m_v087;
    LinearCastVertex m_v088;
    LinearCastVertex m_v089;
    LinearCastVertex m_v090;
    LinearCastVertex m_v091;
    LinearCastVertex m_v092;
    LinearCastVertex m_v093;
    LinearCastVertex m_v094;
    LinearCastVertex m_v095;
    LinearCastVertex m_v096;
    LinearCastVertex m_v097;
    LinearCastVertex m_v098;
    LinearCastVertex m_v099;
    LinearCastVertex m_v100;
    LinearCastVertex m_v101;
    LinearCastVertex m_v102;
    LinearCastVertex m_v103;
    LinearCastVertex m_v104;
    LinearCastVertex m_v105;
    LinearCastVertex m_v106;
    LinearCastVertex m_v107;
    LinearCastVertex m_v108;
    LinearCastVertex m_v109;
    LinearCastVertex m_v110;
    LinearCastVertex m_v111;
    LinearCastVertex m_v112;
    LinearCastVertex m_v113;
    LinearCastVertex m_v114;
    LinearCastVertex m_v115;
    LinearCastVertex m_v116;
    LinearCastVertex m_v117;
    LinearCastVertex m_v118;
    LinearCastVertex m_v119;
    LinearCastVertex m_v120;
    LinearCastVertex m_v121;
    LinearCastVertex m_v122;
    LinearCastVertex m_v123;
    LinearCastVertex m_v124;
    LinearCastVertex m_v125;
    LinearCastVertex m_v126;
    LinearCastVertex m_v127;
    LinearCastVertex m_v128;
    LinearCastVertex m_v129;
    LinearCastVertex m_v130;
    LinearCastVertex m_v131;
    LinearCastVertex m_v132;
    LinearCastVertex m_v133;
    LinearCastVertex m_v134;
    LinearCastVertex m_v135;
    LinearCastVertex m_v136;
    LinearCastVertex m_v137;
    LinearCastVertex m_v138;
    LinearCastVertex m_v139;
    LinearCastVertex m_v140;
    LinearCastVertex m_v141;
    LinearCastVertex m_v142;
    LinearCastVertex m_v143;
    LinearCastVertex m_v144;
    LinearCastVertex m_v145;
    LinearCastVertex m_v146;
    LinearCastVertex m_v147;
    LinearCastVertex m_v148;
    LinearCastVertex m_v149;
    LinearCastVertex m_v150;
    LinearCastVertex m_v151;
    LinearCastVertex m_v152;
    LinearCastVertex m_v153;
    LinearCastVertex m_v154;
    LinearCastVertex m_v155;
    LinearCastVertex m_v156;
    LinearCastVertex m_v157;
    LinearCastVertex m_v158;
    LinearCastVertex m_v159;
    LinearCastVertex m_v160;
    LinearCastVertex m_v161;
    LinearCastVertex m_v162;
    LinearCastVertex m_v163;
    LinearCastVertex m_v164;
    LinearCastVertex m_v165;
    LinearCastVertex m_v166;
    LinearCastVertex m_v167;
    LinearCastVertex m_v168;
    LinearCastVertex m_v169;
    LinearCastVertex m_v170;
    LinearCastVertex m_v171;
    LinearCastVertex m_v172;
    LinearCastVertex m_v173;
    LinearCastVertex m_v174;
    LinearCastVertex m_v175;
    LinearCastVertex m_v176;
    LinearCastVertex m_v177;
    LinearCastVertex m_v178;
    LinearCastVertex m_v179;
    LinearCastVertex m_v180;
    LinearCastVertex m_v181;
    LinearCastVertex m_v182;
    LinearCastVertex m_v183;
    LinearCastVertex m_v184;
    LinearCastVertex m_v185;
    LinearCastVertex m_v186;
    LinearCastVertex m_v187;
    LinearCastVertex m_v188;
    LinearCastVertex m_v189;
    LinearCastVertex m_v190;
    LinearCastVertex m_v191;
    LinearCastVertex m_v192;
    LinearCastVertex m_v193;
    LinearCastVertex m_v194;
    LinearCastVertex m_v195;
    LinearCastVertex m_v196;
    LinearCastVertex m_v197;
    LinearCastVertex m_v198;
    LinearCastVertex m_v199;
    LinearCastVertex m_v200;
    LinearCastVertex m_v201;
    LinearCastVertex m_v202;
    LinearCastVertex m_v203;
    LinearCastVertex m_v204;
    LinearCastVertex m_v205;
    LinearCastVertex m_v206;
    LinearCastVertex m_v207;
    LinearCastVertex m_v208;
    LinearCastVertex m_v209;
    LinearCastVertex m_v210;
    LinearCastVertex m_v211;
    LinearCastVertex m_v212;
    LinearCastVertex m_v213;
    LinearCastVertex m_v214;
    LinearCastVertex m_v215;
    LinearCastVertex m_v216;
    LinearCastVertex m_v217;
    LinearCastVertex m_v218;
    LinearCastVertex m_v219;
    LinearCastVertex m_v220;
    LinearCastVertex m_v221;
    LinearCastVertex m_v222;
    LinearCastVertex m_v223;
    LinearCastVertex m_v224;
    LinearCastVertex m_v225;
    LinearCastVertex m_v226;
    LinearCastVertex m_v227;
    LinearCastVertex m_v228;
    LinearCastVertex m_v229;
    LinearCastVertex m_v230;
    LinearCastVertex m_v231;
    LinearCastVertex m_v232;
    LinearCastVertex m_v233;
    LinearCastVertex m_v234;
    LinearCastVertex m_v235;
    LinearCastVertex m_v236;
    LinearCastVertex m_v237;
    LinearCastVertex m_v238;
    LinearCastVertex m_v239;
    LinearCastVertex m_v240;
    LinearCastVertex m_v241;
    LinearCastVertex m_v242;
    LinearCastVertex m_v243;
    LinearCastVertex m_v244;
    LinearCastVertex m_v245;
    LinearCastVertex m_v246;
    LinearCastVertex m_v247;
    LinearCastVertex m_v248;
    LinearCastVertex m_v249;
    LinearCastVertex m_v250;
    LinearCastVertex m_v251;
    LinearCastVertex m_v252;
    LinearCastVertex m_v253;
    LinearCastVertex m_v254;
    LinearCastVertex m_v255;
    int m_unk3010;
    int m_unk3014;
    int m_unk3018;
    int m_unk301c;
    hkVector4 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int m_unk3034;
    int m_unk3038;
    int m_unk303c;
    GskCache m_pAccessManager;
};

struct CastObj
{
    void __thiscall hkpBvTreeAgent_processCollision(int a, int b, int c, LinearCastState& s);
    void __thiscall ProcessEntries_00d31610(int a1, int a2, int a3, LinearCastState& st);
};

// @fnv 0x00d31610
// src: GUESS 0x00d31610 (confidence: low)
void __thiscall CastObj::ProcessEntries_00d31610(int a1, int a2, int a3, LinearCastState& st)
{
    LinearCastState* s = &st;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    LinearCastVertex* v = s->m_kRayEnd;
    hkpBvTreeAgent_processCollision(a2, a1, a3, st);
    for (; v < s->m_kRayEnd; v++)
    {
        hkVector4 w;
        w.setBroadcast3(v->m_direction);
        v->m_vContactPosition.addMul4(w, v->m_direction);
        v->m_direction.m_vComponents = _mm_xor_ps(v->m_direction.m_vComponents, DAT_010c4c00);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        s->m_vHitNormal.m_vComponents = _mm_xor_ps(DAT_010c4c00, s->m_vHitNormal.m_vComponents);

        s->m_pAccessManager.flip();
    }
}
}  // namespace fnv_00d31610

namespace fnv_00d36d60 {
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
}

extern LocalM128 DAT_010c4c00;

struct SimplexVertex
{
    LocalM128 m_kPointA;
    LocalM128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    LocalM128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

class SimplexProcessor
{
  public:
    void FUN_00d369a0(int a, int b, int c, Simplex* s);
    void ProcessEntries_00d36d60(int a, int b, int c, Simplex* s);
};

// @fnv 0x00d36d60
// src: GUESS 0x00d36d60 (confidence: low)
void SimplexProcessor::ProcessEntries_00d36d60(int a, int b, int c, Simplex* s)
{
    SimplexVertex* v = s->m_kRayEnd;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    FUN_00d369a0(b, a, c, s);
    for (; v < s->m_kRayEnd; v++)
    {
        const LocalM128* pb = &v->m_kPointB;
        LocalM128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        LocalM128* n = &s->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = s->m_dims.m_ucLowNibble;
            s->m_dims.m_ucLowNibble = s->m_dims.m_ucHighNibble;
            s->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = s->m_ucDimensionA;
            s->m_ucDimensionA = s->m_ucDimensionB;
            s->m_ucDimensionB = t;
        }
        int last = s->m_ucDimensionA + s->m_ucDimensionB - 1;
        unsigned short t0 = s->m_ids[0];
        s->m_ids[0] = s->m_ids[last];
        s->m_ids[last] = t0;
        if ((s->m_ucDimensionA & s->m_ucDimensionB) == 2)
        {
            unsigned short t1 = s->m_ids[1];
            s->m_ids[1] = s->m_ids[2];
            s->m_ids[2] = t1;
        }
    }
}
}  // namespace fnv_00d36d60

namespace fnv_00d23380 {


struct SortObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    hkVector4 m_vContactPosition;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    int m_priority;
};

struct SortEntry
{
    unsigned int m_data;
    SortObject* m_object;
    unsigned int m_extra;
};

struct SortList
{
    SortEntry m_entries[4];
    int m_iNumberOfEntries;
};

// @fnv 0x00d23380
// src: GUESS 0x00d23380 (confidence: low)
void Object_ProcessEntries_00d23380(SortList* list)
{
    for (int i = 0; i < list->m_iNumberOfEntries - 1; i++)
    {
        for (int j = i + 1; j < list->m_iNumberOfEntries; j++)
        {
            SortEntry& a = list->m_entries[i];
            SortEntry& b = list->m_entries[j];
            if (a.m_object->m_priority < b.m_object->m_priority)
                continue;
            if (a.m_object->m_priority == b.m_object->m_priority &&
                a.m_object->m_vContactPosition.dot3scalar(a.m_object->m_vContactPosition) < b.m_object->m_vContactPosition.dot3scalar(b.m_object->m_vContactPosition))
                continue;
            SortEntry t = a;
            a = b;
            b = t;
        }
    }
}
}  // namespace fnv_00d23380

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}
inline void operator delete(void*, void*) throw()
{}

static inline FinishingFlag NotFinishing()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    return flag;
}

class S00d2c8a0_Base
{
  public:
    S00d2c8a0_Base(FinishingFlag flag);  // FUN_00d2c7e0
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class S00d2c8a0_Derived : public S00d2c8a0_Base
{
  public:
    S00d2c8a0_Derived(FinishingFlag flag) : S00d2c8a0_Base(flag)
    {}
    virtual void vf04();
    LocalM128 m_kScaleFactors;
};

// Havok getVtable helper: placement-construct into a local buffer with the finish-loading flag.
// @fnv 0x00d2c8a0
// src: GUESS 0x00d2c8a0 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable()
{
    __declspec(align(16)) char buffer[sizeof(S00d2c8a0_Derived)];
    S00d2c8a0_Derived* pObject = new (buffer) S00d2c8a0_Derived(NotFinishing());
    return *reinterpret_cast<const void**>(pObject);
}

namespace fnv_00d32850 {
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
}

extern LocalM128 DAT_010c4c00;

struct SimplexVertex
{
    LocalM128 m_kPointA;
    LocalM128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    LocalM128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
    void hkpHeightFieldAgent_processCollision(int a, int b, int c, Simplex* s);
};

struct Agent : AgentBase
{
    void ProcessEntries_00d32850(int a, int b, int c, Simplex* s);
};

// @fnv 0x00d32850
// src: GUESS 0x00d32850 (confidence: low)
void Agent::ProcessEntries_00d32850(int a, int b, int c, Simplex* s)
{
    SimplexVertex* v = s->m_kRayEnd;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    AgentBase::hkpHeightFieldAgent_processCollision(b, a, c, s);
    for (; v < s->m_kRayEnd; v++)
    {
        const LocalM128* pb = &v->m_kPointB;
        LocalM128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        LocalM128* n = &s->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = s->m_dims.m_ucLowNibble;
            s->m_dims.m_ucLowNibble = s->m_dims.m_ucHighNibble;
            s->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = s->m_ucDimensionA;
            s->m_ucDimensionA = s->m_ucDimensionB;
            s->m_ucDimensionB = t;
        }
        int last = s->m_ucDimensionA + s->m_ucDimensionB - 1;
        unsigned short t0 = s->m_ids[0];
        s->m_ids[0] = s->m_ids[last];
        s->m_ids[last] = t0;
        if ((s->m_ucDimensionA & s->m_ucDimensionB) == 2)
        {
            unsigned short t1 = s->m_ids[1];
            s->m_ids[1] = s->m_ids[2];
            s->m_ids[2] = t1;
        }
    }
}
}  // namespace fnv_00d32850

struct SortPair
{
    unsigned int key;
    unsigned int val;
};

// @fnv 0x00d36520
// src: GUESS 0x00d36520 (confidence: low)
extern "C" void Object_ProcessEntries_00d36520(SortPair* arr, int lo, int hi, unsigned int extra)
{
    int i;
    int j;
    __declspec(align(16)) SortPair pivot;
    __declspec(align(16)) SortPair tmp;

    for (;;)
    {
        i = lo;
        j = hi;
        pivot = arr[(lo + hi) >> 1];
        do
        {
            while (arr[i].key < pivot.key || (arr[i].key == pivot.key && arr[i].val < pivot.val))
            {
                ++i;
            }
            while (pivot.key < arr[j].key || (pivot.key == arr[j].key && pivot.val < arr[j].val))
            {
                --j;
            }
            if (j < i)
            {
                break;
            }
            if (j != i)
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
            --j;
            ++i;
        } while (i <= j);
        if (lo < j)
        {
            Object_ProcessEntries_00d36520(arr, lo, j, extra);
        }
        if (i >= hi)
        {
            break;
        }
        lo = i;
    }
}

// The original registration helpers inline the shared table's default initialization.
inline hkpCollisionDispatcher::Agent3FunctionTable::Agent3FunctionTable()
{
    m_bIsPredictive = false;
    m_bAgentFlag1 = false;
    m_bAgentFlag2 = false;
    m_pUpdateFilterFunc = 0;
    m_pCalcStats = 0;
    m_pAgentFunction10 = 0;
    m_pAgentFunction11 = 0;
    m_pAgentFunction7 = 0;
}

void __cdecl hkpCollectionAgent3_initAgentFunc(hkpCollisionDispatcher::Agent3FunctionTable& kFuncs);

// @fnv 0x00d367d0
// src: HAVOK_LIB 0x00d367d0
void __cdecl hkpCollectionAgent3_registerAgent3(hkpCollisionDispatcher* pkDispatcher)
{
    __declspec(align(16)) hkpCollisionDispatcher::Agent3FunctionTable kFuncs;
    hkpCollectionAgent3_initAgentFunc(kFuncs);
    pkDispatcher->AddEntry(&kFuncs, 0x12, 7);
}

class hkpCdBody;
namespace fnv_00d36e80 {

extern LocalM128 DAT_010c44d0;



struct ShapeSweepParameters
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    hkVector4 m_path;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};

class hkpSymmetricAgentFlipCastCollector : public hkpCdPointCollector
{
  public:
    hkpSymmetricAgentFlipCastCollector(const hkVector4& path, hkpCdPointCollector& collector)
        : m_path(path), m_kCollector(collector)
    {}
    virtual void AddCdPoint(const ContactPointPair& point);
    hkVector4 m_path;
    hkpCdPointCollector& m_kCollector;
};

struct AgentBase
{
    void hkpListAgent_linearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ShapeSweepParameters& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector) throw();
};

struct Agent : AgentBase
{
    void CopyData_00d36e80(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ShapeSweepParameters& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

// @fnv 0x00d36e80
// src: GUESS 0x00d36e80 (confidence: low)
void Agent::CopyData_00d36e80(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ShapeSweepParameters& input,
                         hkpCdPointCollector& collector, hkpCdPointCollector* startCollector)
{
    ShapeSweepParameters flippedInput;
    memcpy(&flippedInput, &input, sizeof(flippedInput));
    flippedInput.m_path.m_vComponents = _mm_xor_ps(input.m_path.m_vComponents, DAT_010c44d0);
    hkpSymmetricAgentFlipCastCollector flippedCollector(input.m_path, collector);
    if (startCollector)
    {
        hkpSymmetricAgentFlipCastCollector flippedStartCollector(input.m_path, *startCollector);
        AgentBase::hkpListAgent_linearCast(bodyB, bodyA, flippedInput, flippedCollector, &flippedStartCollector);
    }
    else
    {
        AgentBase::hkpListAgent_linearCast(bodyB, bodyA, flippedInput, flippedCollector, 0);
    }
}
}  // namespace fnv_00d36e80

namespace fnv_00d37c10 {
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
}

extern LocalM128 DAT_010c4c00;

struct SimplexVertex
{
    LocalM128 m_kPointA;
    LocalM128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    LocalM128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
    void hkpMultiRayConvexAgent_processCollision(int a, int b, int c, Simplex* s);
};

struct Agent : AgentBase
{
    void hkpSymmetricAgentLinearCast_hkpMultiRayConvexAgent_processCollision(int a, int b, int c, Simplex* s);
};

// @fnv 0x00d37c10
// src: XBOX_PDB 0x00d37c10
void Agent::hkpSymmetricAgentLinearCast_hkpMultiRayConvexAgent_processCollision(int a, int b, int c, Simplex* s)
{
    SimplexVertex* v = s->m_kRayEnd;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    AgentBase::hkpMultiRayConvexAgent_processCollision(b, a, c, s);
    for (; v < s->m_kRayEnd; v++)
    {
        const LocalM128* pb = &v->m_kPointB;
        LocalM128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        LocalM128* n = &s->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = s->m_dims.m_ucLowNibble;
            s->m_dims.m_ucLowNibble = s->m_dims.m_ucHighNibble;
            s->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = s->m_ucDimensionA;
            s->m_ucDimensionA = s->m_ucDimensionB;
            s->m_ucDimensionB = t;
        }
        int last = s->m_ucDimensionA + s->m_ucDimensionB - 1;
        unsigned short t0 = s->m_ids[0];
        s->m_ids[0] = s->m_ids[last];
        s->m_ids[last] = t0;
        if ((s->m_ucDimensionA & s->m_ucDimensionB) == 2)
        {
            unsigned short t1 = s->m_ids[1];
            s->m_ids[1] = s->m_ids[2];
            s->m_ids[2] = t1;
        }
    }
}
}  // namespace fnv_00d37c10

hkpAgentData* __cdecl InitOutputDefaults(const AgentProcessingInput&, FourByteState*, hkpAgentData*);
void __cdecl Runtime_ReleaseHandles_Thunk(FourByteState*, hkpAgentData*, hkpContactMgr*, hkpConstraintOwner&,
                         hkpCollisionDispatcher*);
hkpAgentData* __cdecl ReleaseHandles(FourByteState*, hkpAgentData*, hkpContactMgr*, hkpConstraintOwner&);
void __cdecl RemoveKeyFromTable(FourByteState*, hkpAgentData*, hkContactPointId);
void __cdecl InsertIntoSlotArray(FourByteState*, hkpAgentData*, hkContactPointId);
void __cdecl nullsub_15(FourByteState*, hkpAgentData*, hkContactPointId);
void __cdecl hkCollideCapsuleUtilCapsVsTri_ProcessEntries_00d39150(const AgentProcessingInput&, FourByteState*, hkpAgentData*, hkVector4&);
hkpAgentData* __cdecl hkCapsuleTriangleAgent3_process(const AgentSubtypeMarker&, FourByteState*, hkpAgentData*, hkVector4*,
                                 WorldOperationEntry&);

// @fnv 0x00d39840
// src: HAVOK_LIB 0x00d39840
void __cdecl hkCapsuleTriangleAgent3_registerAgent3(hkpCollisionDispatcher* pkDispatcher)
{
    __declspec(align(16)) hkpCollisionDispatcher::Agent3FunctionTable kFuncs;
    // This registration helper applies the defaults in its original store order.
    kFuncs.m_bAgentFlag1 = false;
    kFuncs.m_bAgentFlag2 = false;
    kFuncs.m_pCalcStats = 0;
    kFuncs.m_pAgentFunction10 = 0;
    kFuncs.m_pAgentFunction11 = 0;
    kFuncs.m_pAgentFunction7 = 0;
    kFuncs.m_pUpdateFilterFunc = 0;
    kFuncs.m_bIsPredictive = false;
    kFuncs.m_pCreateFunc = InitOutputDefaults;
    kFuncs.m_pAgentFunction8 = hkCapsuleTriangleAgent3_process;
    kFuncs.m_pAgentFunction7 = hkCollideCapsuleUtilCapsVsTri_ProcessEntries_00d39150;
    kFuncs.m_pAgentFunction3 = ReleaseHandles;
    kFuncs.m_pAgentFunction4 = RemoveKeyFromTable;
    kFuncs.m_pAgentFunction5 = InsertIntoSlotArray;
    kFuncs.m_pCreateZombieFunc = nullsub_15;
    kFuncs.m_pAgent3DestroyFuncs = Runtime_ReleaseHandles_Thunk;
    pkDispatcher->AddEntry(&kFuncs, 5, 3);
}

namespace fnv_00d3f500 {
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
}

extern LocalM128 DAT_010c4c00;

struct SimplexVertex
{
    LocalM128 m_kPointA;
    LocalM128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    LocalM128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
    void FUN_00d3f080(int a, int b, int c, Simplex* s);
};

struct Agent : AgentBase
{
    void hkpSymmetricAgentLinearCast_hkpSphereCapsuleAgent_processCollision(int a, int b, int c, Simplex* s);
};

// @fnv 0x00d3f500
// src: XBOX_PDB 0x00d3f500
void Agent::hkpSymmetricAgentLinearCast_hkpSphereCapsuleAgent_processCollision(int a, int b, int c, Simplex* s)
{
    SimplexVertex* v = s->m_kRayEnd;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    AgentBase::FUN_00d3f080(b, a, c, s);
    for (; v < s->m_kRayEnd; v++)
    {
        const LocalM128* pb = &v->m_kPointB;
        LocalM128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        LocalM128* n = &s->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = s->m_dims.m_ucLowNibble;
            s->m_dims.m_ucLowNibble = s->m_dims.m_ucHighNibble;
            s->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = s->m_ucDimensionA;
            s->m_ucDimensionA = s->m_ucDimensionB;
            s->m_ucDimensionB = t;
        }
        int last = s->m_ucDimensionA + s->m_ucDimensionB - 1;
        unsigned short t0 = s->m_ids[0];
        s->m_ids[0] = s->m_ids[last];
        s->m_ids[last] = t0;
        if ((s->m_ucDimensionA & s->m_ucDimensionB) == 2)
        {
            unsigned short t1 = s->m_ids[1];
            s->m_ids[1] = s->m_ids[2];
            s->m_ids[2] = t1;
        }
    }
}
}  // namespace fnv_00d3f500

namespace fnv_00d3fe90 {
extern "C"
{
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_load_ss(const float*);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
    unsigned __int64 __rdtsc();
    void _ReadWriteBarrier();
}
extern unsigned int DAT_0126835c;
struct ProfileSample
{
    const char* name;
    unsigned int time, unk08;
};
struct ProfileBuffer
{
    unsigned int unk00;
    ProfileSample* current;
    unsigned int unk08;
    ProfileSample* end;
};
struct Matrix
{
    hkVector4 c0, c1, c2, c3;
};
struct ShapeBase
{
    unsigned int unk00, unk04, unk08, unk0c;
    float radius;
};
struct Shape : ShapeBase
{
    unsigned int unk14, unk18, unk1c;
    LocalM128 halfExtents;
};
struct Body
{
    ShapeBase* shape;
    unsigned int unk04;
    Matrix* transform;
};
struct CollisionInput
{
    unsigned int unk00, unk04;
    float tolerance;
};
struct Params
{
    Body* a;
    Body* b;
    unsigned int unk08;
    CollisionInput* input;
    unsigned int unk10, unk14, unk18, unk1c;
    Matrix relative;
};
struct Processor
{
    const Body* a;
    const Body* b;
    CollisionInput* input;
    unsigned int manager;
    int output;
    const Matrix* worldA;
    const Matrix* worldB;
    unsigned int unk1c;
    Matrix relative;
    hkVector4 halfA, halfB, tolerance, expandedA, expandedB;
    float scalarTolerance, constant;
    unsigned int unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    unsigned int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    unsigned int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c;
    __forceinline Processor(const Body& aa, const Body& bb, CollisionInput* ii, unsigned int mm, int oo,
                            const Matrix& rr, const Matrix& wa, const hkVector4& ha, const Matrix& wb, const hkVector4& hb,
                            float tol)
    {
        a = &aa;
        b = &bb;
        input = ii;
        manager = mm;
        output = oo;
        worldA = &wa;
        worldB = &wb;
        hkVector4 c0;
        memcpy(&c0, &rr.c0, sizeof(c0));
        hkVector4 c1;
        memcpy(&c1, &rr.c1, sizeof(c1));
        hkVector4 c2;
        memcpy(&c2, &rr.c2, sizeof(c2));
        hkVector4 c3;
        memcpy(&c3, &rr.c3, sizeof(c3));
        relative.c0.m_vComponents = c0.m_vComponents;
        relative.c1.m_vComponents = c1.m_vComponents;
        relative.c2.m_vComponents = c2.m_vComponents;
        relative.c3.m_vComponents = c3.m_vComponents;
        memcpy(&halfA, &ha, sizeof(halfA));
        memcpy(&halfB, &hb, sizeof(halfB));
        LocalM128 t = _mm_set_ps1(tol);
        tolerance.m_vComponents = t;
        expandedA.m_vComponents = _mm_add_ps(tolerance.m_vComponents, ha.m_vComponents);
        expandedB.m_vComponents = _mm_add_ps(tolerance.m_vComponents, hb.m_vComponents);
        scalarTolerance = tol;
        constant = 0.01f;
    }
    void hkpBoxBoxCollisionDetection_calcManifold(unsigned char*);
};
// @fnv 0x00d3fe90
// src: COMMUNITY 0x00d3fe90
void* __cdecl hkBoxBoxAgent3_process(Params* p, unsigned char* out, unsigned char* obj, int unused, int z)
{
    ProfileBuffer* buf = (ProfileBuffer*)TlsGetValue(DAT_0126835c);
    if (buf->current < buf->end)
    {
        ProfileSample* rec = buf->current;
        rec->name = "TtBoxBox3";
        _ReadWriteBarrier();
        volatile unsigned int tick = (unsigned int)__rdtsc();
        rec->time = tick;
        buf->current = rec + 1;
    }
    Body* a = p->a;
    Shape* shapeA = static_cast<Shape*>(a->shape);
    float radiusA = *(volatile float*)&shapeA->radius;
    Shape* shapeB = static_cast<Shape*>(p->b->shape);
    LocalM128 ba = _mm_set_ps1(radiusA);
    hkVector4 halfA;
    halfA.m_vComponents = _mm_add_ps(ba, shapeA->halfExtents);
    float radiusB = shapeB->radius;
    LocalM128 bb = _mm_set_ps1(radiusB);
    hkVector4 halfB;
    halfB.m_vComponents = _mm_add_ps(bb, shapeB->halfExtents);
    CollisionInput* input = p->input;
    float tol = input->tolerance;
    Processor state(*a, *p->b, input, p->unk10, z, p->relative, *a->transform, halfA, *p->b->transform, halfB, tol);
    state.hkpBoxBoxCollisionDetection_calcManifold(obj);
    out[2] = obj[0x21];
    buf = (ProfileBuffer*)TlsGetValue(DAT_0126835c);
    if (buf->current < buf->end)
    {
        ProfileSample* rec = buf->current;
        rec->name = "Et";
        _ReadWriteBarrier();
        volatile unsigned int tick = (unsigned int)__rdtsc();
        rec->time = tick;
        buf->current = rec + 1;
    }
    return obj + 0x40;
}
}  // namespace fnv_00d3fe90

extern "C"
{
    LocalM128 _mm_set_ps1(float a);
    LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
    void _mm_store_ps(float* p, LocalM128 a);
}

extern "C" double fabs(double);

struct ClosestPointResult
{
    float distSq;
    float s;
    float t;
    float unk0C;
    LocalM128 p1;
    LocalM128 p2;
};

static __forceinline void Dot3(float& result, LocalM128 u, LocalM128 v)
{
    LocalM128 m = _mm_mul_ps(u, v);
    LocalM128 y = _mm_shuffle_ps(m, m, 0x55);
    LocalM128 z = _mm_shuffle_ps(m, m, 0xaa);
    _mm_store_ss(&result, _mm_add_ss(z, _mm_add_ss(y, m)));
}

// @fnv 0x00d231b0
// src: XBOX_PDB 0x00d231b0
int hkLineSegmentUtil_closestPointInfLineInfLine(const LocalM128* pa, const LocalM128* pb, const LocalM128* pc, const LocalM128* pd, ClosestPointResult* out)
{
    const LocalM128& d = *pd;
    const LocalM128& b = *pb;
    LocalM128 a = *pa;
    LocalM128 c = *pc;

    LocalM128 ca = _mm_sub_ps(c, a);
    float p;
    Dot3(p, d, b);
    float q;
    Dot3(q, b, ca);
    float r;
    Dot3(r, d, ca);
    float bb;
    Dot3(bb, b, b);
    float dd;
    Dot3(dd, d, d);

    float denom = dd * bb - p * p;
    int result;
    float s;
    if ((float)fabs(denom) > (float)((p * p + (float)fabs((float)(dd * bb))) * 9.5367431640625e-07))
    {
        s = (dd * q - r * p) / denom;
        result = 0;
    }
    else
    {
        s = 0.0f;
        result = 1;
    }
    float t = (p * s - r) / dd;

    LocalM128 p1 = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(s), b), a);
    LocalM128 p2 = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(t), d), c);
    LocalM128 diff = _mm_sub_ps(p1, p2);
    float distSq;
    Dot3(distSq, diff, diff);

    out->distSq = distSq;
    _mm_store_ps(out->p1.m128_f32, p1);
    _mm_store_ps(out->p2.m128_f32, p2);
    out->s = s;
    out->t = t;
    return result;
}

extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 _mm_xor_ps(LocalM128, LocalM128);

extern float DAT_0104da48;
extern LocalM128 DAT_010c44d0;
extern char DAT_010ce80c;


struct __declspec(align(16)) D2fInput
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    hkVector4 m_vec;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

struct D2fRayHitCollector
{
    virtual void CollectRayHit(const void* a, const void* b) = 0;
    float m_fHitDistance;
    D2fRayHitCollector() throw() : m_fHitDistance(DAT_0104da48)
    {}
};

struct __declspec(align(16)) D2fCollector : D2fRayHitCollector
{
    hkVector4 m_vec;
    void* m_user;

    D2fCollector(const hkVector4& v, void* user) throw() : m_vec(v), m_user(user)
    {}
    virtual void CollectRayHit(const void* a, const void* b);
};

struct D2fWorld
{
    void hkpBvTreeAgent_linearCast(int a, int b, D2fInput* in, D2fCollector* c1, D2fCollector* c2);
    void CopyData_00d2f460(int a1, int a2, const D2fInput* a3, int a4, void* a5);
};

// @fnv 0x00d2f460
// src: GUESS 0x00d2f460 (confidence: medium)
void D2fWorld::CopyData_00d2f460(int a1, int a2, const D2fInput* a3, int a4, void* a5)
{
    D2fInput tmp;
    memcpy(&tmp, a3, sizeof(tmp));
    _mm_store_ps(tmp.m_vec.m_f, _mm_xor_ps(a3->m_vec.m_vComponents, DAT_010c44d0));
    D2fCollector c1(a3->m_vec, (void*)a4);
    if (a5)
    {
        D2fCollector c2(a3->m_vec, a5);
        hkpBvTreeAgent_linearCast(a2, a1, &tmp, &c1, &c2);
    }
    else
    {
        hkpBvTreeAgent_linearCast(a2, a1, &tmp, &c1, 0);
    }
}

namespace N {
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_setr_ps(float, float, float, float);
}
}

class S00d2c910_Base
{
  public:
    S00d2c910_Base(void* a, int b);  // FUN_00d2b260
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class FUN_00d2c910 : public S00d2c910_Base
{
  public:
    FUN_00d2c910(void* a, int b);
    virtual void vf00();
    N::LocalM128 m_kScaleFactors;
};

// @fnv 0x00d2c910
FUN_00d2c910::FUN_00d2c910(void* a, int b) : S00d2c910_Base(a, b)
{
    m_kScaleFactors = N::_mm_setr_ps(0.0f, 0.0f, 0.0f, 0.0f);
}
