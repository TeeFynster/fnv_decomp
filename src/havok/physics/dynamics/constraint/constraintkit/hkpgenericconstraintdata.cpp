typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
#define _INCLUDED_MM2
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/dynamics/constraint/constraintkit/hkpgenericconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/constraintkit/hkpgenericconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// The reflected headers use packed POD math types.
// Preserve the scalar copy form of the former reflection-only POD view.
struct ReflectionScalarCopy { float a, b, c, d; };
__forceinline void CopyReflectionQuad(void* destination, const void* source)
{
    *static_cast<ReflectionScalarCopy*>(destination) = *static_cast<const ReflectionScalarCopy*>(source);
}

#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkHalf.h"
#include "../../../../../../include/hkStringPtr.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkQsTransform.h"
#include "../../../../../../include/hkMatrix4.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkVariant.h"
#include "../../../../../../include/hkHomogeneousArray.h"
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkClass.h"
#include "../../../../../../include/hkpBridgeAtoms.h"
#include "../../../../../../include/hkpConstraintData.h"
#include "havok/hkBase.h"
#include "../../../../../../include/hkpConstraintMotor.h"
namespace reflection {
using ::hkpConstraintMotor;
#include "havok/hkpGenericConstraintData.h"
}
using ::hkReal;
using ::hkpConstraintData;
using ::hkpBridgeAtoms;
using reflection::hkpGenericConstraintDataScheme;
using reflection::hkpGenericConstraintDataSchemeConstraintInfo;
using ::hkpConstraintMotor;

// Exe 0x00d503c0 FUN_00d503c0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
#define _INCLUDED_MM2
#include "../../../../../../include/Pair.h"
#include "../../../../../../include/hkVector4q.h"


struct FUN_00d503a0_class
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_g;
    int m_h;
    int m_i;
    int m_iUnknownValue;
    int m_k;
    int m_l;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
    int m_p;
    void hkpGenericConstraintData_getRuntimeInfo(int, int* out);
};

// @fnv 0x00d503a0
// src: HAVOK_LIB 0x00d503a0
void FUN_00d503a0_class::hkpGenericConstraintData_getRuntimeInfo(int, int* paiOut)
{
    int v = *(int*)((char*)this + 0x20);
    paiOut[1] = v;
    paiOut[0] = v * 8;
}

struct FUN_00d50520_s
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
    int ai;
    int aj;
    int ak;
    int al;
    int am;
    int an;
    int ao;
    int ap;
    int aq;
    int ar;
    int as;
    int at;
    int au;
    int av;
    int aw;
    int ax;
    int ay;
    int az;
    int ba;
    int bb;
    int bc;
    int bd;
    int be;
    int bf;
    int bg;
    int bh;
    int bi;
    int bj;
    int bk;
    int bl;
    int bm;
    int bn;
    int bo;
    int bp;
    int bq;
    int br;
    int bs;
    int bt;
    int bu;
    int bv;
    int bw;
    int bx;
    int by;
    int bz;
    int ca;
    int cb;
    int cc;
    int cd;
    int ce;
    int cf;
    int cg;
    int ch;
    int ci;
    int cj;
    int ck;
    int cl;
    int cm;
    int cn;
    int co;
    int cp;
    int cq;
    int cr;
    int cs;
    int ct;
    int cu;
    int cv;
    int cw;
    int cx;
    int cy;
    int cz;
    int da;
    int db;
    int dc;
    int dd;
    int de;
    int df;
    int dg;
    int dh;
    int di;
    int dj;
    int dk;
    int dl;
    int dm;
    int dn;
    int do2;
    int dp;
    int dq;
    int dr;
    int ds;
    int dt;
    int du;
    int dv;
    int dw;
    int dx;
    int dy;
    int dz;
    int ea;
    int eb;
    int ec;
    int ed;
    int ee;
    int ef;
    int eg;
    int eh;
    int ei;
    int ej;
    int ek;
    int el;
    int em;
    int en;
    int eo;
    int ep;
    int eq;
    int er;
    int es;
    int et;
    int eu;
    int ev;
    int ew;
    int ex;
    int ey;
    int ez;
    int fa;
    int fb;
    int fc;
    int fd;
    int fe;
    int ff;
    int fg;
    int pInventoryChangeNode;
    int fi;
    int fj;
    int fk;
    int fl;
    int fm;
    int fn;
    int fo;
    int fp;
    int fq;
    int fr;
    int fs;
    int ft;
    int fu;
    int fv;
    int fw;
    int fx;
    int fy;
    int afDepth;
    int ga;
    int gb;
    int gc;
    int gd;
    int ge;
    int gf;
    int gg;
    int gh;
    int gi;
    int gj;
    int gk;
    int gl;
    int gm;
    int gn;
    int go;
    int gp;
    int gq;
    int gr;
    int gs;
    int gt;
    int gu;
    int gv;
    int gw;
    int gx;
    int gy;
    int gz;
    int ha;
    int hb;
    int hc;
    int hd;
    int he;
    int hf;
    int hg;
    int hh;
    int hi;
    int hj;
    int hk;
    int hl;
    int hm;
    int hn;
    int ho;
    int hp;
    int hq;
    int hr;
    int hs;
    int ht;
    int hu;
    int hv;
    int hw;
    int hx;
    int hy;
    int hz;
    int ia;
    int ib;
    int ic;
    int id;
    int ie;
    int if2;
    int ig;
    int ih;
    int ii;
    int ij;
    int ik;
    int il;
    int im;
    int in2;
    int io;
    int ip;
    int iq;
    int ir;
    int is;
    int it;
    int iu;
    int iv;
    int iw;
    int ix;
    int iy;
    int iz;
    int ja;
    int jb;
    int jc;
    int jd;
    int je;
    int m_iFadeNodeState;
    int jg;
    int jh;
    int ji;
    int jj;
    int jk;
    int jl;
    int jm;
    int jn;
    int jo;
    int jp;
    int jq;
    int jr;
    int js;
    int jt;
    int ju;
    int jv;
    int jw;
    int jx;
    int jy;
    int jz;
    int ka;
    int kb;
    int kc;
    int kd;
    int ke;
    int kf;
    int kg;
    int kh;
    int ki;
    int kj;
    int kk;
    int kl;
    int km;
    int kn;
    int ko;
    int kp;
    int kq;
    int kr;
    int ks;
    int kt;
    int ku;
    int kv;
    int kw;
    int kx;
    int ky;
    int kz;
    int la;
    int lb;
    int lc;
    int ld;
    int le;
    int lf;
    int lg;
    int lh;
    int li;
    int lj;
    int lk;
    int ll;
    int lm;
    int ln;
    int lo;
    int lp;
    int lq;
    int lr;
    int ls;
    int lt;
    int lu;
    int lv;
    int lw;
    int lx;
    int ly;
    int lz;
    int ma;
    int mb;
    int mc;
    int md;
    int me;
    int mf;
    int mg;
    int mh;
    int mi;
    int mj;
    int mk;
    int ml;
    int mm;
    int mn;
    int mo;
    int mp;
    int mq;
    int mr;
    int ms;
    int mt;
    int mu;
    int mv;
    int mw;
    int mx;
    int my;
    int mz;
    int na;
    int nb;
    int nc;
    int nd;
    int ne;
    int nf;
    int ng;
    int nh;
    int ni;
    int nj;
    int nk;
    int nl;
    int nm;
    int nn;
    int no;
    int np;
    int nq;
    int nr;
    int ns;
    int nt;
    int nu;
    int nv;
    int nw;
    int nx;
    int ny;
    int nz;
    int oa;
    int ob;
    int oc;
    int od;
    int oe;
    int of2;
    int og;
    int oh;
    int oi;
    int oj;
    int ok;
    int ol;
    int om;
    int on;
    int oo;
    int op;
    int oq;
    int or2;
    int os;
    int ot;
    int ou;
    int ov;
    int ow;
    int ox;
    int oy;
    int oz;
    int pa;
    int pb;
    int pc;
    int pd;
    int pe;
    int pf;
    int pg;
    int ph;
    int pi;
    int pj;
    int pk;
    int pl;
    int pm;
    int pn;
    int po;
    int pp;
    int pq;
    int pr;
    int ps;
    int pt;
    int pu;
    int pv;
    int pw;
    int px;
    int py;
    int pz;
    int qa;
    int qb;
    int qc;
    int qd;
    int qe;
    int qf;
    int qg;
    int qh;
    int qi;
    int qj;
    int qk;
    int ql;
    int qm;
    int qn;
    int qo;
    int qp;
    int qq;
    int qr;
    int qs;
    int qt;
    int qu;
    int qv;
    int qw;
    int qx;
    int qy;
    int qz;
    int ra;
    int rb;
    int rc;
    int rd;
    int re;
    int rf;
    int rg;
    int rh;
    int ri;
    int rj;
    int rk;
    int rl;
    int rm;
    int rn;
    int ro;
    int rp;
    int rq;
    int rr;
    int rs;
    int rt;
    int ru;
    int rv;
    int rw;
    int rx;
    int ry;
    int rz;
    int sa;
    int sb;
    int sc;
    int sd;
    int se;
    int sf;
    int sg;
    int sh;
    int si;
    int sj;
    int sk;
    int sl;
    int sm;
    int sn;
    int so;
    int sp;
    int sq;
    int sr;
    int ss;
    int st;
    int su;
    int sv;
    int sw;
    int sx;
    int sy;
    int sz;
    int ta;
    int tb;
    int tc;
    int td;
    int te;
    int tf;
    int tg;
    int th;
    int ti;
    int tj;
    int tk;
    int tl;
    int tm;
    int tn;
    int to;
    int tp;
    int tq;
    int tr;
    int ts;
    int tt;
    int tu;
    int tv;
    int tw;
    int tx;
    int ty;
    int tz;
    int ua;
    int ub;
    int uc;
    int ud;
    int ue;
    int uf;
    int ug;
    int uh;
    int ui;
    int uj;
    int uk;
    int ul;
    int um;
    int un;
    int uo;
    int up;
    int uq;
    int ur;
    int us;
    int ut;
    int uu;
    int uv;
    int uw;
    int ux;
    int uy;
    int uz;
    int va;
    int vb;
    int vc;
    int vd;
    int ve;
    int vf;
    int vg;
    int vh;
    int vi;
    int vj;
    int vk;
    int vl;
    int vm;
    int vn;
    int vo;
    int vp;
    int vq;
    int vr;
    int vs;
    int vt;
    int vu;
    int vv;
    int vw;
    int vx;
    int vy;
    int vz;
    int wa;
    int wb;
    int wc;
    int wd;
    int we;
    int wf;
    int wg;
    int wh;
    int wi;
    int wj;
    int wk;
    int wl;
    int wm;
    int wn;
    int wo;
    int wp;
    int wq;
    int wr;
    int ws;
    int wt;
    int wu;
    int wv;
    int ww;
    int wx;
    int wy;
    int wz;
    int xa;
    int xb;
    int xc;
    int xd;
    int xe;
    int xf;
    int xg;
    int xh;
    int xi;
    int xj;
    int xk;
    int xl;
    int m_iFourthIntegerSlot;
    int xn;
    int xo;
    int xp;
    int xq;
    int xr;
    int xs;
    int xt;
    int xu;
    int xv;
    int xw;
    int xx;
    int xy;
    int xz;
    int ya;
    int yb;
    int yc;
    int yd;
    int ye;
    int yf;
    int yg;
    int yh;
    int yi;
    int yj;
    int yk;
    int yl;
    int ym;
    int yn;
    int yo;
    int yp;
    int yq;
    int m_iFourthIntegerInLaterGroup;
    int ys;
    int yt;
    int yu;
    int yv;
    int yw;
    int yx;
    int yy;
    int yz;
    int za;
    int zb;
    int zc;
    int zd;
    int ze;
    int zf;
    int zg;
    int zh;
    int zi;
    int zj;
    int zk;
    int zl;
    int zm;
    int zn;
    int zo;
    int zp;
    int zq;
    int zr;
    int zs;
    int zt;
    int zu;
    int zv;
    int zw;
    int zx;
    int zy;
    int zz;
    void hkpGenericConstraintData_getConstraintInfo(int* o);
};
// @fnv 0x00d50520
// src: HAVOK_LIB 0x00d50520
void FUN_00d50520_s::hkpGenericConstraintData_getConstraintInfo(int* aiOut)
{
    aiOut[4] = (int)((char*)this + 0xc);
    aiOut[0] = 0;
    aiOut[1] = 0;
    aiOut[2] = 0;
    aiOut[3] = 0;
    aiOut[5] = 0xc;
    aiOut[0] = *(int*)((char*)this + 0x18);
    aiOut[1] = *(int*)((char*)this + 0x1c);
    aiOut[2] = *(int*)((char*)this + 0x20);
    aiOut[3] = *(int*)((char*)this + 0x24);
}

struct FUN_00d50560_class
{
    char pad[0x28];
    int* m_items;
    int* hkpGenericConstraintData_getParameters(unsigned int index);
};

// @fnv 0x00d50560
// src: HAVOK_LIB 0x00d50560
int* FUN_00d50560_class::hkpGenericConstraintData_getParameters(unsigned int index)
{
    return m_items + index * 4;
}

// @fnv 0x00d50500
// src: XBOX_PDB 0x00d50500
void __stdcall hkpGenericConstraintData_isValid(unsigned char* out)
{
    *out = 1;
}

// @fnv 0x00d50510
// src: GUESS 0x00d50510 (confidence: high)
int hkpGenericConstraintData_ReturnConstant_10()
{
    return 10;
}

class CFoo
{
  public:
    void* hkpGenericConstraintData_getScheme();
};

// @fnv 0x00d504f0
// src: XBOX_PDB 0x00d504f0
void* CFoo::hkpGenericConstraintData_getScheme()
{
    return (void*)((char*)this + 0x18);
}


struct FUN_00d50570_class
{
    char pad[0x28];
    LocalM128* m_items;
    void CopyItems(int start, int count, const LocalM128* src);
};
// Copies count __m128 values from src into m_items starting at index start.
// @fnv 0x00d50570
void FUN_00d50570_class::CopyItems(int start, int count, const LocalM128* src)
{
    int end = start + count;
    if (start < end)
    {
        int off = start * 16;
        int n = end - start;
        do
        {
            *(LocalM128*)((char*)m_items + off) = *src;
            off += 16;
            ++src;
            --n;
        } while (n != 0);
    }
}

struct SolverItem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64;
};

void __cdecl AppendEventRecord(SolverItem* item, int index, int count, int stride);

struct FUN_00d50bd0_owner
{
    hkpConstraintData m_base;
    hkpBridgeAtoms m_kBridgeAtoms;
    hkpGenericConstraintDataScheme m_kConstraintDataScheme;

    void hkpGenericConstraintData_hatchScheme(hkpGenericConstraintDataScheme* scheme, SolverItem* item, int index);
    void hkpGenericConstraintData_buildJacobian(SolverItem* item, int index);
};

// @fnv 0x00d50bd0
// src: XBOX_PDB 0x00d50bd0
void FUN_00d50bd0_owner::hkpGenericConstraintData_buildJacobian(SolverItem* item, int index)
{
    AppendEventRecord(item, index, item->unk64, 8);
    hkpGenericConstraintData_hatchScheme(&m_kConstraintDataScheme, item, index);
}

struct FUN_00d51620_Alloc
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void* p, unsigned int n);
};

struct FUN_00d51620_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d51620_Alloc* m_pThreadAllocator;
};

FUN_00d51620_Router* hkMemoryRouter_getInstance();

struct FUN_00d51620_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_a10;
    int m_a14;
    int m_a18;
    void* m_1c;
    int m_20;
    int m_24;
    void* m_28;
    int m_2c;
    int m_30;
    void* m_34;
    int m_38;
    int m_3c;

    void FreeArrays();
};

// @fnv 0x00d51620
void FUN_00d51620_class::FreeArrays()
{
    FUN_00d51620_Router* m = hkMemoryRouter_getInstance();
    FUN_00d51620_Alloc* alloc = m->m_pThreadAllocator;
    int c = m_3c;
    m_38 = 0;
    if (!(c & 0x80000000))
        alloc->free(m_34, (c & 0x3fffffff) * 4);
    m_34 = 0;
    m_3c = 0x80000000;
    m = hkMemoryRouter_getInstance();
    alloc = m->m_pThreadAllocator;
    c = m_30;
    m_2c = 0;
    if (!(c & 0x80000000))
        alloc->free(m_28, (c & 0x3fffffff) * 4);
    m_28 = 0;
    m_30 = 0x80000000;
    m = hkMemoryRouter_getInstance();
    alloc = m->m_pThreadAllocator;
    c = m_24;
    m_20 = 0;
    if (!(c & 0x80000000))
        alloc->free(m_1c, (c & 0x3fffffff) * 4);
    m_1c = 0;
    m_24 = 0x80000000;
    m = hkMemoryRouter_getInstance();
    alloc = m->m_pThreadAllocator;
    c = m_a18;
    m_a14 = 0;
    if (!(c & 0x80000000))
        alloc->free(m_a10, (c & 0x3fffffff) * 16);
    m_a10 = 0;
    m_a18 = 0x80000000;
}

namespace fnv_00d516f0 {
struct FnvCpu_FUN_00d516f0_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d516f0_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d516f0_CpuAllocator* allocator;
};
FnvCpu_FUN_00d516f0_CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00d516f0_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00d50c50();
    FnvCpu_FUN_00d516f0_CpuObject* FUN_00d516f0(unsigned int flags);
};
// @fnv 0x00d516f0
FnvCpu_FUN_00d516f0_CpuObject* FnvCpu_FUN_00d516f0_CpuObject::FUN_00d516f0(unsigned int flags)
{
    FUN_00d50c50();
    if (flags & 1)
    {
        FnvCpu_FUN_00d516f0_CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00d516f0

struct FUN_00d503c0_m
{
    hkVector4q r0, r1, r2;
};
struct FUN_00d503c0_src
{
    hkVector4q r0;
    hkVector4q r1;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unkA0, unkA4, unkA8, unkAc, unkB0, unkB4, unkB8;
};

extern "C" LocalM128 __cdecl _mm_setzero_ps(void);
void __cdecl hk1dLinearBilateralConstraintBuildJacobian(FUN_00d503c0_m* m, void* obj, void* out);

// Copies two vectors from src, sets a third to each unit axis in turn calling FUN_00dcf280 each time, then adds 3 to src->unkB8.
// @fnv 0x00d503c0
// src: XBOX_PDB 0x00d503c0
void __stdcall hkpGenericConstraintData_constrainAllLinearW(int a, int b, int c, FUN_00d503c0_src* src, void* obj, void* out)
{
    FUN_00d503c0_m m;
    m.r0.m_vComponents = src->r0.m_vComponents;
    m.r1.m_vComponents = src->r1.m_vComponents;
    m.r2.m_vComponents = _mm_setzero_ps();
    m.r2.m_vec.x = 1.0f;
    hk1dLinearBilateralConstraintBuildJacobian(&m, obj, out);
    m.r2.m_vec.x = 0.0f;
    m.r2.m_vec.y = 1.0f;
    hk1dLinearBilateralConstraintBuildJacobian(&m, obj, out);
    m.r2.m_vec.y = 0.0f;
    m.r2.m_vec.z = 1.0f;
    hk1dLinearBilateralConstraintBuildJacobian(&m, obj, out);
    src->unkB8 += 3;
}

struct FUN_00d50c90;
struct ReferenceFields
{
    virtual void Release() = 0;
    unsigned short memSizeAndFlags;
    short referenceCount;
    unsigned int userData;
    ReferenceFields() : referenceCount(1), userData(0)
    {}
};
struct BridgeAtom
{
    unsigned short type;
    unsigned short flags;
    void* jacobian;
    void* constraintData;
    BridgeAtom() : type(1)
    {}
    void hkpBridgeConstraintAtom_init(FUN_00d50c90* parent);
};
template <class T> struct ConstraintArray
{
    T* data;
    int size;
    int capacityAndFlags;
    ConstraintArray() : data(0), size(0), capacityAndFlags(0x80000000)
    {}
};
struct ConstraintScheme
{
    hkpGenericConstraintDataSchemeConstraintInfo info;
    ConstraintArray<::hkVector4> data;
    ConstraintArray<int> commands;
    ConstraintArray<void*> modifiers;
    ConstraintArray<hkpConstraintMotor*> motors;
    ConstraintScheme()
    {
        info.m_iMaxSchemaSize = 0;
        info.m_iSchemaByteSize = 0;
        info.m_iSolverResultCount = 0;
        info.m_iSolverElementTemporaryCount = 0;
    }
};
struct FUN_00d50c90 : ReferenceFields
{
    BridgeAtom atom;
    ConstraintScheme scheme;
    FUN_00d50c90();
};
// @fnv 0x00d50c90
FUN_00d50c90::FUN_00d50c90()
{
    *(volatile int*)&scheme.info.m_iSchemaByteSize += 16;
    atom.hkpBridgeConstraintAtom_init(this);
}

struct S00d50e10_Rows
{
    LocalM128 v0;
    LocalM128 v1;
    LocalM128 v2;
};

void __cdecl hk1dAngularBilateralConstraintBuildJacobian(S00d50e10_Rows* out, int d, int e);

// Builds three S00d50e10_Rows from vectors in p, calls FUN_00dcee80 on each with d and e, and adds 3 to the int at p+0xB8.
// @fnv 0x00d50e10
// src: GUESS 0x00d50e10 (confidence: low)
void __stdcall hkpGenericConstraintData_UpdateState_00d50e10(int a0, int a1, int a2, void* p, int d, int e)
{
    float* base = reinterpret_cast<float*>(p);
    S00d50e10_Rows out1;
    S00d50e10_Rows out;

    out1.v0 = (*reinterpret_cast<const LocalM128*>(base + 0x14));
    out1.v2 = (*reinterpret_cast<const LocalM128*>(base + 0x24));
    out1.v1 = (*reinterpret_cast<const LocalM128*>(base + 0x1C));
    hk1dAngularBilateralConstraintBuildJacobian(&out1, d, e);

    out.v0 = (*reinterpret_cast<const LocalM128*>(base + 0x18));
    out.v2 = (*reinterpret_cast<const LocalM128*>(base + 0x28));
    out.v1 = out1.v0;
    hk1dAngularBilateralConstraintBuildJacobian(&out, d, e);

    out.v2 = (*reinterpret_cast<const LocalM128*>(base + 0x20));
    out.v1 = out.v0;
    out.v0 = out1.v1;
    hk1dAngularBilateralConstraintBuildJacobian(&out, d, e);

    *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0xB8) += 3;
}


struct SolverInfoD510
{
    hkVector4q m_jacobian;
    float m_f0;
    float m_f1;
    float m_out;
    float m_vScale;
};

struct SolverStateD510
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
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int m_numJacobians;
};

void __cdecl Object_UpdateFields_00dcfec0(const hkVector4q* pkLinA, const hkVector4q* pkAngA, const hkVector4q* pkLinB,
                          const hkVector4q* pkAngB, hkVector4q* pkJac, float* pfOut);
void __cdecl HkpbuildjacobianfromatomsGsNogs_UpdateState_00d6cb30(const SolverInfoD510* pkInfo, void* pvA, void* pvB);

// Reads two indices from ppSchema, computes a Jacobian via FUN_00dcfec0, stores it with two floats from ppData, and calls FUN_00d6cb30.
// @fnv 0x00d51060
// src: HAVOK_LIB 0x00d51060
void __stdcall hkpGenericConstraintData_setTwistLimitW(const char** ppSchema, const float** ppData, void* pvUnused, SolverStateD510* pkState,
                            void* pvA, void* pvB)
{
    SolverInfoD510 kInfo;
    *ppSchema += 4;
    int iIndexA = *(const int*)*ppSchema;
    *ppSchema += 4;
    int iIndexB = *(const int*)*ppSchema;
    kInfo.m_vScale = 0.5f;
    const hkVector4q* pkVecs = (const hkVector4q*)pkState;
    Object_UpdateFields_00dcfec0(&pkVecs[iIndexA + 5], &pkVecs[iIndexA + 8], &pkVecs[iIndexB + 5], &pkVecs[iIndexB + 8],
                 &kInfo.m_jacobian, &kInfo.m_out);
    const float* pVector4 = *ppData;
    kInfo.m_f0 = pVector4[0];
    *ppData = pVector4 + 4;
    kInfo.m_f1 = pVector4[1];
    HkpbuildjacobianfromatomsGsNogs_UpdateState_00d6cb30(&kInfo, pvA, pvB);
    pkState->m_numJacobians++;
}


struct d51390_pool
{
    hkVector4q recs[11];
    int unkB0;
    int unkB4;
    int unkB8;
};

struct d51390_ctx
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
};

struct d51390_item
{
    hkVector4q* rec;
    int dest;
    float val;
    int flag;
};

extern "C" void __cdecl DAT_00dcefb0(d51390_item* item, d51390_ctx* ctx, void* a6);

// Advances the stream, builds an item from a pool record and the cursor value with a destination offset by pool->unkB8, calls DAT_00dcefb0, and increments unkB8.
// @fnv 0x00d51390
// src: GUESS 0x00d51390 (confidence: low)
void __stdcall hkpGenericConstraintData_UpdateState_00d51390(int** stream, float** cursor, int a3, d51390_pool* pool, d51390_ctx* ctx, void* a6)
{
    int destBase = ctx->unk64;
    (*stream) += 1;
    d51390_item item;
    item.rec = &pool->recs[**stream + 5];
    float* cur = *cursor;
    float v = cur[0];
    *cursor = cur + 4;
    item.val = v;
    item.flag = 1;
    item.dest = destBase + pool->unkB8 * 8;
    DAT_00dcefb0(&item, ctx, a6);
    pool->unkB8 += 1;
}

extern "C"
{
    LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
    void _mm_store_ss(float* p, LocalM128 a);
}

__forceinline float hkVector4q::dot3(const hkVector4q& a) const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    const LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    const LocalM128 z = _mm_shuffle_ps(x2, x2, 0xaa);
    float result;
    _mm_store_ss(&result, _mm_add_ss(z, xySum));
    return result;
}

// local form of hkRotation: 0x00d50450 needs inline column access/reduction; shared form gives 181 bytes vs exe 147.
struct hkRotationq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    __forceinline const hkVector4q& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
};

struct AngularFrames
{
    hkVector4q m_v00;
    hkVector4q m_v10;
    hkVector4q m_v20;
    hkVector4q m_v30;
    hkVector4q m_v40;
    hkRotationq m_rotA;
    hkRotationq m_rotB;
};

extern int DAT_011b5a90[];
extern int DAT_011b5a94[];

float __cdecl Atan2(float y, float x);

// Dots columns of m_rotB with a column of m_rotA, chosen by axis through two lookup tables, and passes the results to Atan2 as sine and cosine.
// @fnv 0x00d50450
// src: XBOX_PDB 0x00d50450
static __declspec(noinline) float calcDeltaAngleAroundAxis(const AngularFrames* frames, int axis)
{
    const hkVector4q& dirA = frames->m_rotA.getColumn(DAT_011b5a90[axis]);
    const float sinAngle = frames->m_rotB.getColumn(DAT_011b5a94[axis]).dot3(dirA);
    const float cosAngle = frames->m_rotB.getColumn(DAT_011b5a90[axis]).dot3(dirA);
    return Atan2(sinAngle, cosAngle);
}

float calcAngleForAxis(const AngularFrames* frames, int axis)
{
    return calcDeltaAngleAroundAxis(frames, axis);
}

extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);

struct S00d505c0_Blk
{
    LocalM128 diff;
    LocalM128 v;
    float fb;
    int idx;
};

void __cdecl hk1dLinearFrictionBuildJacobian(S00d505c0_Blk* in, int* cfg, int index);

// Builds an S00d505c0_Blk from vectors in c, a float read via b and a destination offset, calls FUN_00dcf100 with basePtr and index, and increments c[0xb8/4].
// @fnv 0x00d505c0
// src: XBOX_PDB 0x00d505c0
void __stdcall hkpGenericConstraintData_setLinearFrictionW(int** a, int* b, void* unused, int* c, int* basePtr, int index)
{
    int idxBase = basePtr[0x64 / 4];

    (*a)++;
    int val = **a;

    LocalM128 lo = *(LocalM128*)c;
    S00d505c0_Blk blk;
    blk.v = *(LocalM128*)((char*)c + ((val + 2) << 4));

    blk.diff = _mm_sub_ps(lo, *((LocalM128*)c + 1));
    float* bv = *(float**)b;
    *(float**)b = bv + 4;
    blk.fb = *bv;

    blk.idx = idxBase + c[0xb8 / 4] * 8;

    hk1dLinearFrictionBuildJacobian(&blk, basePtr, index);

    c[0xb8 / 4]++;
}

namespace fnv_00d50d60 {
extern "C" LocalM128 __cdecl _mm_load_ps(const float*);
extern "C" void __cdecl _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 __cdecl _mm_xor_ps(LocalM128, LocalM128);


struct D50D60_Stream
{
    hkVector4q vecs[11];  // vector data the code indexes
    int unkB0;
    int unkB4;
    int numDecoded;  // +0xB8
};


struct D50D60_Out
{
    hkVector4q a;
    hkVector4q b;
    hkVector4q c;
};

extern unsigned int DAT_011b5a90;
extern unsigned int DAT_011b5a94;
extern unsigned int DAT_010c44d0;

void __cdecl hk1dAngularBilateralConstraintBuildJacobian(void* pair, int a2, int a3);

// Loads three vectors into out, calls FUN_00dcee80, sets a to old b XORed with a constant and b to old a, calls it again, and adds 2 to data->numDecoded.
// @fnv 0x00d50d60
// src: GUESS 0x00d50d60 (confidence: low)
void __stdcall Object_UpdateFields_00d50d60(unsigned int** a0, int aiUnused1, int aiUnused2, D50D60_Stream* apStream, int a4, int a5)
{
    D50D60_Out out;
    ++*a0;
    unsigned int idx = **a0;
    _mm_store_ps(&out.b.m_vec.x, apStream->vecs[(&DAT_011b5a90)[idx] + 5].m_vComponents);
    _mm_store_ps(&out.a.m_vec.x, apStream->vecs[(&DAT_011b5a94)[idx] + 5].m_vComponents);
    _mm_store_ps(&out.c.m_vec.x, apStream->vecs[idx + 8].m_vComponents);
    hk1dAngularBilateralConstraintBuildJacobian(&out, a4, a5);
    LocalM128 cur = _mm_load_ps(&out.b.m_vec.x);
    LocalM128 t = _mm_xor_ps(_mm_load_ps((const float*)&DAT_010c44d0), cur);
    _mm_store_ps(&out.b.m_vec.x, _mm_load_ps(&out.a.m_vec.x));
    _mm_store_ps(&out.a.m_vec.x, t);
    hk1dAngularBilateralConstraintBuildJacobian(&out, a4, a5);
    apStream->numDecoded += 2;
}
}  // namespace fnv_00d50d60

extern "C"
{
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, LocalM128);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_set_ss(float);
}

struct __declspec(align(16)) hkVec4A
{
    float x, y, z, w;
};

struct hkSchemeVecs
{
    ::hkVector4 m_v0;
    ::hkVector4 m_v1;
    ::hkVector4 m_v2;
    ::hkVector4 m_v3;
    ::hkVector4 m_v4;
    hkVec4A m_colsA[3];
    hkVec4A m_colsB[3];
    int unkb0;
    int unkb4;
    int m_uiItemCount;
};

struct hkAngInfo
{
    hkVec4A m_kAxisEndPoints;
    float m_kPointA;
    float m_kPointB;
    float m_dot;
    float m_fTau;
};

static inline float hkToReal(LocalM128 v)
{
    float s;
    _mm_store_ss(&s, v);
    return s;
}

extern "C" void HkpbuildjacobianfromatomsGsNogs_UpdateState_00d6cb30(hkAngInfo* info, int p1, int p2);

static inline LocalM128 hkLenSq3(LocalM128 v)
{
    LocalM128 len = _mm_mul_ps(v, v);
    LocalM128 r = _mm_add_ss(_mm_shuffle_ps(len, len, 0x55), len);
    return _mm_add_ss(_mm_shuffle_ps(len, len, 0xaa), r);
}

// Builds a normalized cross product and dot of m_colsA[idx] and m_colsB[idx] with two floats from data and calls FUN_00d6cb30, unless the cross is near zero.
// @fnv 0x00d50ec0
// src: GUESS 0x00d50ec0 (confidence: low)
void __stdcall hkVector4_ProcessAndReturnValue_00d50ec0(int** cmds, ::hkVector4** data, int unused, hkSchemeVecs* apSchemeVecs, int p5, int p6)
{
    float lenSq;
    int idx = *++*cmds;
    hkVec4A a = apSchemeVecs->m_colsA[idx];
    hkVec4A b = apSchemeVecs->m_colsB[idx];
    hkAngInfo info;
    info.m_fTau = 0.5f;
    LocalM128 vb = _mm_load_ps(&b.x);
    LocalM128 va = _mm_load_ps(&a.x);
    LocalM128 c0 = _mm_mul_ps(_mm_shuffle_ps(va, va, 0xc9), _mm_shuffle_ps(vb, vb, 0xd2));
    LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(va, va, 0xd2), _mm_shuffle_ps(vb, vb, 0xc9));
    LocalM128 cross = _mm_sub_ps(c0, c1);
    lenSq = hkToReal(hkLenSq3(cross));
    if (lenSq < 1.192092896e-07f)
        return;
    info.m_dot = b.x * a.x + b.y * a.y + b.z * a.z;
    LocalM128 r = hkLenSq3(cross);
    LocalM128 e = _mm_rsqrt_ss(r);
    LocalM128 isZero = _mm_cmpeq_ss(r, _mm_set_ss(0.0f));
    LocalM128 ree = _mm_mul_ss(_mm_mul_ss(r, e), e);
    LocalM128 threeMinus = _mm_sub_ss(_mm_set_ss(3.0f), ree);
    LocalM128 res = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), threeMinus);
    LocalM128 inv = _mm_andnot_ps(isZero, res);
    _mm_store_ps(&info.m_kAxisEndPoints.x, _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), cross));
    ::hkVector4* v = (*data)++;
    info.m_kPointA = v->x;
    info.m_kPointB = v->y;
    HkpbuildjacobianfromatomsGsNogs_UpdateState_00d6cb30(&info, p5, p6);
    apSchemeVecs->m_uiItemCount++;
}

struct S00d51100_Blk
{
    LocalM128 a;
    LocalM128 b;
    LocalM128 v;
    float f0;
    float f1;
};

void __cdecl hk1dLinearLimitBuildJacobian(S00d51100_Blk* in, int* cfg, int index);

// @fnv 0x00d51100
// src: GUESS 0x00d51100 (confidence: low)
void __stdcall Object_UpdateFields_00d51100(int** a, int* b, void* unused, int* c, int* basePtr, int index)
{
    (*a)++;
    int val = **a;

    S00d51100_Blk blk;
    blk.v = *(LocalM128*)((char*)c + ((val + 2) << 4));
    blk.a = *(LocalM128*)c;
    blk.b = *((LocalM128*)c + 1);
    float* bv = *(float**)b;
    *(float**)b = bv + 4;
    blk.f0 = bv[0];
    blk.f1 = bv[1];

    hk1dLinearLimitBuildJacobian(&blk, basePtr, index);

    c[0xb8 / 4]++;
}

namespace fnv_00d51170 {
extern float DAT_01016248;

struct AnglePool
{
    LocalM128 vectors[11];
    int unkB0, unkB4, unkB8;
};
extern "C" LocalM128 __cdecl _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 __cdecl _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 __cdecl _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" void __cdecl _mm_store_ss(float*, LocalM128);
extern int DAT_011b5a90[];
extern float Atan2(float, float);
extern float dotAngle(LocalM128, LocalM128);
// src: XBOX_PDB 0x00d50450
static __declspec(noinline) float calcDeltaAngleAroundAxis(AnglePool* pool, int index)
{
    LocalM128 first = pool->vectors[DAT_011b5a90[index] + 5];
    LocalM128 basis[3] = {pool->vectors[8], pool->vectors[9], pool->vectors[10]};
    float x = dotAngle(first, basis[DAT_011b5a90[index]]);
    float y = dotAngle(first, basis[DAT_011b5a90[index + 1]]);
    return Atan2(y, x);
}
struct AngleRecord
{
    float x, y, angle, w;
};

// Reads an index from stream, computes an angle via pool and FUN_00d50450, adjusts it to stay within ±π of the previous angle, stores it, and calls FUN_00d6cb30.
// @fnv 0x00d51170
// src: GUESS 0x00d51170 (confidence: medium)
void __stdcall hkpGenericConstraintData_UnwrapAxisAngleAndProcessConstraint(int** __restrict stream, AngleRecord** cursor, int unused, AnglePool* pool, void* a,
                            void* b)
{
    SolverInfoD510 info;
    ++*stream;
    int index = **stream;
    info.m_vScale = DAT_01016248;
    (LocalM128&)info.m_jacobian = pool->vectors[index + 5];
    info.m_out = calcDeltaAngleAroundAxis(pool, index);
    AngleRecord* pRecord = *cursor;
    info.m_f0 = pRecord->x;
    *cursor = pRecord + 1;
    info.m_f1 = pRecord->y;
    if (info.m_out < 0.0f && pRecord->angle > 0.0f)
    {
        double adjusted = info.m_out + 6.2831854820251465;
        if (pRecord->angle - info.m_out > 3.1415927410125732)
            info.m_out = adjusted;
    }
    if (info.m_out > 0.0f && pRecord->angle < 0.0f)
    {
        double adjusted = info.m_out - 6.2831854820251465;
        if (info.m_out - pRecord->angle > 3.1415927410125732)
            info.m_out = adjusted;
    }
    pRecord->angle = info.m_out;
    HkpbuildjacobianfromatomsGsNogs_UpdateState_00d6cb30(&info, a, b);
    ++pool->unkB8;
}
}  // namespace fnv_00d51170

extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
    LocalM128 _mm_load_ps(float const* p);
    void _mm_store_ss(float* p, LocalM128 a);
}

struct ContactImpulseInfo
{
    hkReal m_fContactImpulse;
    hkReal m_data;
};

struct SixteenWordFloatRecord
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    ContactImpulseInfo* m_pSolverResults;
};

struct GenericConstraintRuntime
{
    ::hkVector4 m_kShapeVectorData[11];
    int unkB0;
    int unkB4;
    int m_solverResultIndex;
};

struct SolverElementTemp
{
    hkReal m_invMass;
    SixteenWordFloatRecord* m_pStepInfo;
    ContactImpulseInfo m_lastImpulse;
    hkReal m_rhs;
    hkReal m_deltaPosition;

    SolverElementTemp()
    {
        m_lastImpulse.m_fContactImpulse = 0;
        m_lastImpulse.m_data = 0;
    }
};

struct SixIntegerData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

void __cdecl ComputeJacobian(const ::hkVector4* axis, const ::hkVector4* posB, SixteenWordFloatRecord* in,
                             void* currentSchema, SolverElementTemp* input);
void __cdecl _hkCalcMotorData(const hkpConstraintMotor* motor, const SolverElementTemp* input, SixIntegerData* output);
void __cdecl _hk1dLinearVelocityMotorCommitJacobian(SixIntegerData* output, SixteenWordFloatRecord* in, void* currentSchema, void** schemaPtr);

// Advances the command and data pointers, computes a dot product for a motor constraint, and updates the solver state if a motor is present.
// @fnv 0x00d51270
// src: GUESS 0x00d51270 (confidence: medium)
void __stdcall hkVector4_AdvanceStreamsAndProcessMotor(const int** commands, const ::hkVector4** data, hkpGenericConstraintDataScheme* scheme,
                            GenericConstraintRuntime* runtime, SixteenWordFloatRecord* apStepInfo, void** schema)
{
    *commands += 1;
    int axisIdx = **commands;

    const ::hkVector4* currentData = *data;
    ContactImpulseInfo* p = apStepInfo->m_pSolverResults;
    *data = currentData + 1;
    int motorIdx = (int)currentData->x;

    hkpConstraintMotor* motor = scheme->m_ppMotors.m_data[motorIdx];

    int axisIndex = axisIdx + 2;
    LocalM128 v1 = (LocalM128&)runtime->m_kShapeVectorData[1];
    LocalM128 v0 = (LocalM128&)runtime->m_kShapeVectorData[0];

    ::hkVector4 axis;
    CopyReflectionQuad(&axis, &runtime->m_kShapeVectorData[axisIndex]);
    LocalM128 diff = _mm_sub_ps(v0, v1);
    LocalM128 ax = _mm_load_ps((const float*)&axis);

    LocalM128 mul = _mm_mul_ps(diff, ax);
    LocalM128 shuf1 = _mm_shuffle_ps(mul, mul, 0x55);
    LocalM128 add1 = _mm_add_ss(shuf1, mul);
    LocalM128 shuf2 = _mm_shuffle_ps(mul, mul, 0xaa);
    LocalM128 add2 = _mm_add_ss(shuf2, add1);

    float dot;
    _mm_store_ss(&dot, add2);

    if (motor)
    {
        void* currentSchema = *schema;
        SolverElementTemp input;
        SixIntegerData output;

        ComputeJacobian(&axis, &runtime->m_kShapeVectorData[1], apStepInfo, currentSchema, &input);

        input.m_lastImpulse = p[runtime->m_solverResultIndex];
        input.m_rhs = 0.0f;
        input.m_deltaPosition = -dot;
        input.m_pStepInfo = apStepInfo;

        _hkCalcMotorData(motor, &input, &output);
        _hk1dLinearVelocityMotorCommitJacobian(&output, apStepInfo, currentSchema, schema);
    }

    runtime->m_solverResultIndex += 1;
}

extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern "C" LocalM128 _mm_load_ss(float const*);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);

struct Motor;

union Vec
{
    LocalM128 m;
    struct
    {
        float x, y, z, w;
    };
};


struct QueryIn
{
    float m_fTau;
    float m_fMotorDamping;
    float m_fThirdQueryValue;
    float m_fFourthQueryValue;
    float m_fFifthQueryValue;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void* m_pFirstQueryData;
    void* m_pSecondQueryData;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    Pair* m_pSolverResults;
};

struct Scheme
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    Vec* m_data;
    int m_iDataSize;
    int m_dataCap;
    int* m_commands;
    int m_cmdSize;
    int m_cmdCap;
    void** m_ppModifiers;
    int m_modSize;
    int m_modCap;
    Motor** m_ppMotors;
};

struct Runtime
{
    Vec v[11];
    int unkB0;
    int unkB4;
    int m_iFirstInteger;
};

struct __declspec(align(16)) MotorStuff
{
    float effMass;
    QueryIn* query;
    union
    {
        float last0f;
        int last0;
    };
    union
    {
        float last1f;
        int last1;
    };
    float zero;
    float negTarget;
    float out0;
    float out1;
    float out2;
    float out3;
    float out4;
};

extern int DAT_011b5a90[];
extern double DAT_0101ff58;

extern "C" void _ReadWriteBarrier(void);
extern "C" void __cdecl Hkpbuildjacobianfromatoms_ComputeJacobianInverseEffectiveMass(Vec* axis, QueryIn* in, void* schema, MotorStuff* packet);
void __cdecl _hkCalcMotorData(Motor* motor, MotorStuff* input, float* output);
extern "C" void __cdecl Hkpbuildjacobianfromatoms_UpdateState_00d6ce70(float* negAndOut, QueryIn* in, void* schema, void** out);

static __forceinline LocalM128 dot3(LocalM128 p, LocalM128 q)
{
    LocalM128 m = _mm_mul_ps(p, q);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xAA), s);
}

struct StepScratch
{
    float z;
    float y;
    union
    {
        int axis;
        float d2;
        float ang;
    };
    Motor* motor;
    float d1;
    union
    {
        Pair* sr;
        float sum;
    };
};
// Computes and unwraps an angle from runtime vectors, stores it back, and if a motor exists calls FUN_00dcfff0 and FUN_00d6ce70; then increments m_iFirstInteger.
// @fnv 0x00d51410
// src: GUESS 0x00d51410 (confidence: medium)
void __stdcall hkpGenericConstraintData_UnwrapAngleAndProcessMotor(int** cmdPtr, Vec** dataPtr, Scheme* scheme, Runtime* runtime, QueryIn* apQuery, void** out)
{
    StepScratch v;
    ++*cmdPtr;
    v.axis = **cmdPtr;

    Vec* data = *dataPtr;
    v.sr = apQuery->m_pSolverResults;
    *dataPtr = data + 1;
    v.y = data->y;
    v.z = data->z;
    int motorIndex = (int)data->x;
    v.motor = scheme->m_ppMotors[motorIndex];
    Vec* axisVec = &runtime->v[v.axis + 5];

    double pi = 3.1415927410125732;
    int t0 = DAT_011b5a90[v.axis];
    const Vec& aV = runtime->v[t0 + 5];
    const Vec& bV = runtime->v[DAT_011b5a90[v.axis + 1] + 8];
    const Vec& cV = runtime->v[t0 + 8];

    _mm_store_ss(&v.d1, dot3(bV.m, aV.m));

    _mm_store_ss(&v.d2, dot3(cV.m, aV.m));

    v.ang = (float)(Atan2(-v.d1, -v.d2) + pi);
    if (v.ang - v.y < DAT_0101ff58)
    {
        v.z = (float)(v.z + 1.0);
    }
    else if (v.ang - v.y > pi)
    {
        v.z = (float)(v.z - 1.0);
    }
    v.y = v.ang;

    data->m = _mm_setr_ps(data->x, v.y, v.z, 0.0f);

    if (v.motor)
    {
        void* schema = *out;
        MotorStuff packet;
        packet.last0f = 0.0f;
        packet.last1f = 0.0f;
        Hkpbuildjacobianfromatoms_ComputeJacobianInverseEffectiveMass(axisVec, apQuery, schema, &packet);
        packet.query = apQuery;
        int index = runtime->m_iFirstInteger;
        Pair* pSolverResults = *static_cast<Pair* volatile*>(&v.sr);
        *reinterpret_cast<Pair*>(&packet.last0) = pSolverResults[index];
        packet.zero = 0.0f;
        v.sum = (float)(v.z * 6.2831854820251465 + v.ang);
        packet.negTarget = -v.sum;
        _hkCalcMotorData(v.motor, &packet, &packet.out0);
        Hkpbuildjacobianfromatoms_UpdateState_00d6ce70(&packet.out0, apQuery, schema, out);
    }
    runtime->m_iFirstInteger++;
}

extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);

struct FUN_00cdf250_class
{
    LocalM128 c0, c1, c2;
    __forceinline void operator=(const FUN_00cdf250_class& m)
    {
        c0 = m.c0;
        c1 = m.c1;
        c2 = m.c2;
    }
    void hkMatrix3_setMul(int*, int);
};
struct __declspec(align(16)) InputD506
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    union
    {
        float real;
        int bits;
    } factor;
    int unk28, unk2c, unk30, unk34;
    FUN_00cdf250_class* transformA;
    FUN_00cdf250_class* transformB;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};
struct StateD506
{
    hkVector4q pivotA, pivotB;
    hkVector4q axes[3];
    FUN_00cdf250_class basisA, basisB;
    FUN_00cdf250_class* transformA;
    FUN_00cdf250_class* transformB;
    int count;
};
// Command 24 calls vtable slot +4 with constraint state; actor-value Modifier instead stores a key at +0 and value at +4.
struct ConstraintCommandCallback;
typedef void(__thiscall* ApplyConstraintCommand)(ConstraintCommandCallback*, StateD506*, int);
struct ConstraintCommandCallbackVTable
{
    void* unknown;
    ApplyConstraintCommand apply;
};
struct ConstraintCommandCallback
{
    ConstraintCommandCallbackVTable* vtable;
};
extern "C" void setTransformedPos_00c7f640();
typedef void(__thiscall* PivotD506)(hkVector4q*, const void*, const hkVector4q*);
struct InterpreterD506
{
    void hkpGenericConstraintData_hatchScheme(hkpGenericConstraintDataScheme*, const InputD506*, void*);
    void hkpGenericConstraintData_constrainLinearW(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void hkpGenericConstraintData_constrainAllLinearW(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void Object_UpdateFields_00d50d60(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void hkpGenericConstraintData_UpdateState_00d50e10(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void Object_UpdateFields_00d51100(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void hkpGenericConstraintData_UnwrapAxisAngleAndProcessConstraint(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void hkVector4_ProcessAndReturnValue_00d50ec0(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void hkpGenericConstraintData_setTwistLimitW(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void hkpGenericConstraintData_UnwrapAngleAndProcessMotor(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void hkVector4_AdvanceStreamsAndProcessMotor(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void hkpGenericConstraintData_UpdateState_00d51390(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
    void hkpGenericConstraintData_setLinearFrictionW(int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*, InputD506*, void*);
};
typedef void(__thiscall* HandlerD506)(InterpreterD506*, int**, hkVector4q**, hkpGenericConstraintDataScheme*, StateD506*,
                                      InputD506*, void*);

static __forceinline void rotateD506(hkVector4q& out, const FUN_00cdf250_class* m, const hkVector4q& vec)
{
    const LocalM128& v = vec.m_vComponents;
    LocalM128 y = _mm_shuffle_ps(v, v, 0x55);
    LocalM128 x = _mm_shuffle_ps(v, v, 0);
    LocalM128 z = _mm_shuffle_ps(v, v, 0xaa);
    y = _mm_mul_ps(y, m->c1);
    x = _mm_mul_ps(x, m->c0);
    y = _mm_add_ps(y, x);
    z = _mm_mul_ps(z, m->c2);
    out.m_vComponents = _mm_add_ps(y, z);
}

// Executes a byte-code program from a constraint scheme, dispatching on command codes to update state and call handler functions.
// @fnv 0x00d50640
// src: XBOX_PDB 0x00d50640
void InterpreterD506::hkpGenericConstraintData_hatchScheme(hkpGenericConstraintDataScheme* scheme, const InputD506* input, void* output)
{
    InputD506 localInput = *input;
    StateD506 state;
    state.transformA = localInput.transformA;
    state.transformB = localInput.transformB;
    state.count = 0;
    hkVector4q* data = (hkVector4q*)scheme->m_data.m_data;
    int* command = scheme->m_commands.m_data;
    ConstraintCommandCallback** modifiers = (ConstraintCommandCallback**)scheme->m_ppModifiers.m_data;
    for (;;)
    {
        int* __restrict op = command;
        switch (*op)
        {
        case 0:
            return;
        case 3: {
            LocalM128 v = data->m_vComponents;
            const FUN_00cdf250_class* __restrict m = state.transformA;
            LocalM128 y = _mm_shuffle_ps(v, v, 0x55);
            LocalM128 x = _mm_shuffle_ps(v, v, 0);
            y = _mm_mul_ps(y, m->c1);
            x = _mm_mul_ps(x, m->c0);
            y = _mm_add_ps(y, x);
            hkVector4q& out = state.axes[*++command];
            LocalM128 z = _mm_shuffle_ps(v, v, 0xaa);
            z = _mm_mul_ps(z, m->c2);
            out.m_vComponents = _mm_add_ps(y, z);
            ++data;
            break;
        }
        case 4: {
            LocalM128 v = data->m_vComponents;
            const FUN_00cdf250_class* __restrict m = state.transformB;
            LocalM128 y = _mm_shuffle_ps(v, v, 0x55);
            LocalM128 x = _mm_shuffle_ps(v, v, 0);
            y = _mm_mul_ps(y, m->c1);
            x = _mm_mul_ps(x, m->c0);
            y = _mm_add_ps(y, x);
            ++command;
            int* __restrict axisCommand = command;
            hkVector4q& out = state.axes[*axisCommand];
            LocalM128 z = _mm_shuffle_ps(v, v, 0xaa);
            z = _mm_mul_ps(z, m->c2);
            out.m_vComponents = _mm_add_ps(y, z);
            ++data;
            break;
        }
        case 5: {
            hkVector4q v;
            v.m_vComponents = data->m_vComponents;
            state.axes[*++command] = v;
            ++data;
            break;
        }
        case 6:
            hkpGenericConstraintData_constrainLinearW(&command, &data, scheme, &state, &localInput, output);
            break;
        case 7:
            hkpGenericConstraintData_constrainAllLinearW(&command, &data, scheme, &state, &localInput, output);
            break;
        case 8: {
            FUN_00cdf250_class* m = (FUN_00cdf250_class*)data;
            data += 3;
            state.basisA.hkMatrix3_setMul((int*)state.transformA, (int)m);
            break;
        }
        case 9: {
            FUN_00cdf250_class* m = (FUN_00cdf250_class*)data;
            data += 3;
            state.basisB.hkMatrix3_setMul((int*)state.transformB, (int)m);
            break;
        }
        case 10:
            state.basisA = *state.transformA;
            break;
        case 11:
            state.basisB = *state.transformB;
            break;
        case 12:
            Object_UpdateFields_00d50d60(&command, &data, scheme, &state, &localInput, output);
            break;
        case 13:
            hkpGenericConstraintData_UpdateState_00d50e10(&command, &data, scheme, &state, &localInput, output);
            break;
        case 16:
            Object_UpdateFields_00d51100(&command, &data, scheme, &state, &localInput, output);
            break;
        case 17:
            hkpGenericConstraintData_UnwrapAxisAngleAndProcessConstraint(&command, &data, scheme, &state, &localInput, output);
            break;
        case 18:
            hkVector4_ProcessAndReturnValue_00d50ec0(&command, &data, scheme, &state, &localInput, output);
            break;
        case 19:
            hkpGenericConstraintData_setTwistLimitW(&command, &data, scheme, &state, &localInput, output);
            break;
        case 14:
            hkpGenericConstraintData_UnwrapAngleAndProcessMotor(&command, &data, scheme, &state, &localInput, output);
            break;
        case 15:
            hkVector4_AdvanceStreamsAndProcessMotor(&command, &data, scheme, &state, &localInput, output);
            break;
        case 20:
            hkpGenericConstraintData_UpdateState_00d51390(&command, &data, scheme, &state, &localInput, output);
            break;
        case 21:
            hkpGenericConstraintData_setLinearFrictionW(&command, &data, scheme, &state, &localInput, output);
            break;
        case 1:
            state.pivotA.setTransformedPos_00c7f640(*(const hkTransform*)state.transformA, *data);
            ++data;
            break;
        case 2:
            state.pivotB.setTransformedPos_00c7f640(*(const hkTransform*)state.transformB, *data);
            ++data;
            break;
        case 22: {
            float scale = ((::hkVector4*)data)->x;
            ++data;
            localInput.factor.real *= scale;
            break;
        }
        case 23:
            localInput.factor.bits = input->factor.bits;
            break;
        case 24: {
            ConstraintCommandCallback* pModifier = *modifiers;
            ApplyConstraintCommand apply = pModifier->vtable->apply;
            apply(pModifier, &state, *++command);
            ++modifiers;
            break;
        }
        }
        ++command;
    }
}

// @fnv 0x00d50d00
// src: XBOX_PDB 0x00d50d00
void __stdcall hkpGenericConstraintData_constrainLinearW(int** commands, int unusedData, int unusedScheme, Runtime* runtime, void* input,
                            void* output)
{
    ++*commands;
    FUN_00d503c0_m packet;
    packet.r2.m_vComponents = runtime->v[**commands + 2].m;
    packet.r0.m_vComponents = runtime->v[0].m;
    packet.r1.m_vComponents = runtime->v[1].m;
    hk1dLinearBilateralConstraintBuildJacobian(&packet, input, output);
    ++runtime->m_iFirstInteger;
}
