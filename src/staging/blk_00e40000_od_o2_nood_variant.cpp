// staging/blk_00e40000_od_o2_nood_variant.cpp: Cls, TreeDecoder (9 functions)

#include "fnv_asm_helpers.h"
// Retain the original SSE representation: extra union members change alias analysis.
#define _INCLUDED_MM2
// Exe 0x00e4b570 FUN_00e4b570: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
extern "C" {
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    int _mm_movemask_ps(LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_or_ps(LocalM128, LocalM128);
    LocalM128 _mm_move_ss(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_set_ps(float, float, float, float);
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    float _mm_cvtss_f32(LocalM128);
    void _mm_store_ss(float*, LocalM128);
}
#include "../../include/V4.h"
#include "../../include/hkArray.h"

__forceinline V4::V4() {}
// src/staging/blk_00e40000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00e40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

struct FloatLess
{
	bool operator()(const float& a, const float& b) const { return a < b; }
};

// @fnv 0x00e50f10
// src: HAVOK_LIB 0x00e50f10
void __cdecl hkAlgorithm_quickSortRecursive_float_class_hkAlgorithm_less_float(float* pArr, int d, int h, FloatLess cmpLess)
{
	int i, j;
	__declspec(align(16)) float str;

loop:
	i = h;
	j = d;
	str = pArr[(d + h) >> 1];
	do
	{
		while (cmpLess(pArr[j], str)) j++;
		while (cmpLess(str, pArr[i])) i--;

		if (j <= i)
		{
			if (i != j)
			{
				float t = pArr[i];
				pArr[i] = pArr[j];
				pArr[j] = t;
			}
			i--;
			j++;
		}
	} while (j <= i);

	if (d < i)
	{
		hkAlgorithm_quickSortRecursive_float_class_hkAlgorithm_less_float(pArr, d, i, cmpLess);
	}
	if (j < h)
	{
		d = j;
		goto loop;
	}
}


static inline LocalM128 Dot3v(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}

static inline LocalM128 Dot3_e4b570(LocalM128 p)
{
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}

// @fnv 0x00e4b570
// src: GUESS 0x00e4b570 (confidence: low)
int __cdecl Runtime_ProcessEntries_00e4b570(const LocalM128* point, const LocalM128* verts, float* out)
{
    float zero = 0.0f;
    float one = -1.0f;
    int b = 2;
    int a = 1;
    for (int i = 0; i < 3; i++)
    {
        if (out[i] >= zero && out[a] >= zero)
        {
            LocalM128 o = verts[b];
            LocalM128 A = _mm_sub_ps(verts[i], o);
            LocalM128 B = _mm_sub_ps(verts[a], verts[b]);
            LocalM128 P = _mm_sub_ps(point[0], o);
            LocalM128 C = _mm_sub_ps(verts[3], o);
            LocalM128 dPA = Dot3v(P, A);
            LocalM128 dPB = Dot3v(P, B);
            LocalM128 dCA = Dot3v(C, A);
            LocalM128 dCB = Dot3v(C, B);
            LocalM128 r = _mm_sub_ss(_mm_mul_ss(dPA, dCB), _mm_mul_ss(dPB, dCA));
            if (_mm_movemask_ps(r) & 1)
                out[a] = one;
            else
                out[i] = one;
        }
        a = b;
        b = i;
    }
    if (out[0] > zero) return 0;
    if (out[1] > zero) return 1;
    if (out[2] > zero) return 2;
    return -1;
}

// stand-in for the local object whose method is called
struct LocalObj {
    int m_unk00;
    int m_unk01;
    int m_unk02;
    int m_unk03;
    int m_unk04;
    int m_unk05;
    int m_unk06;
    int m_unk07;
    int m_unk08;
    int m_unk09;
    int m_unk10;
    int m_unk11;
    int m_unk12;
    int m_unk13;
    int m_unk14;
    int m_unk15;
    int m_unk16;
    int m_unk17;
    int m_unk18;
    int m_unk19;
    char* SetupAndProcessShape(char* buf, void* a1, int a2, int a3, int a4);
};

// @fnv 0x00e5cf00
// src: HAVOK_LIB 0x00e5cf00
int __cdecl _hkMoppEarlyExitObbVirtualMachine_queryObb(void* a1, int a2, int a3, int a4)
{
    __declspec(align(16)) LocalObj obj;
    char buf;
    return obj.SetupAndProcessShape(&buf, a1, a2, a3, a4)[0] != 0;
}

struct TmpE5CF40 { V4 a, b; void hkpMoppSphereVirtualMachine_querySphere(int a, int b, int c); };
// @fnv 0x00e5cf40
// src: HAVOK_LIB 0x00e5cf40
void __cdecl _hkMoppSphereVirtualMachine_querySphere(int a, int b, int c)
{
    TmpE5CF40 tmp;
    tmp.hkpMoppSphereVirtualMachine_querySphere(a, b, c);
}

struct __declspec(align(16)) FUN_00e5d010_Block {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    void __thiscall hkpMoppObbVirtualMachine_queryAabb(int first,int second,int third);
};
// @fnv 0x00e5d010
// src: HAVOK_LIB 0x00e5d010
extern "C" void __cdecl _hkMoppObbVirtualMachine_queryAabb(int first,int second,int third)
{
    FUN_00e5d010_Block instance;
    instance.hkpMoppObbVirtualMachine_queryAabb(first,second,third);
}

#include <math.h>
extern "C" void _ReadWriteBarrier();
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();





struct hkQuatStore_e52d90 { LocalM128 m_vec; };

struct Shorts_e52d90 { short a; short b; short c; };

// @fnv 0x00e52d90
// src: GUESS 0x00e52d90 (confidence: low)
void __cdecl hkQuatStore_e52d90_ComputeValues_00e52d90(const unsigned short* in, hkQuatStore_e52d90* out)
{
    static const float s_scale = (float)(1.0 / ((float)sqrt(2.0) * 16383.0));
    Shorts_e52d90 v;
    v.a = in[0] & 0x7fff;
    v.b = in[1] & 0x7fff;
    v.c = in[2] & 0x7fff;
    int missing = ((in[1] & 0x8000) | (in[0] >> 1)) >> 14;
    LocalM128 zero = _mm_setzero_ps();
    out->m_vec = zero;
    float* f = (float*)&out->m_vec;
    int i = (missing == 0);
    f[i] = (v.a - 0x3fff) * s_scale;
    i++;
    i += (i == missing);
    f[i] = (v.b - 0x3fff) * s_scale;
    i++;
    f[i + (i == missing)] = (v.c - 0x3fff) * s_scale;
    LocalM128 sq = _mm_mul_ps(out->m_vec, out->m_vec);
    sq = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0x4e), sq);
    sq = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0xb1), sq);
    float sum; _mm_store_ss(&sum,sq);
    f[missing] = sqrtf(1.0f-sum);
    if (in[2] & 0x8000)
        f[missing] = -f[missing];
}

extern "C" void _ReadWriteBarrier();
static __forceinline int readPacked(const unsigned char* q) {int a=q[0]; int b=q[1]; int c=q[2]; return ((a<<8)+b<<8)+c;}
static __forceinline int readUpper(const unsigned char* q) {return ((q[0]<<8)+q[1]<<8)+q[2];}
struct P1 { union { struct { int f0; int f4; int xyz[3]; int f14; }; int fields[6]; }; };


__forceinline void V4::setAdd(const V4& a,const V4& b){m=_mm_add_ps(a.m,b.m);}
__forceinline void V4::setSub(const V4& a,const V4& b){m=_mm_sub_ps(a.m,b.m);}
__forceinline void V4::setMin(const V4& a,const V4& b){m=_mm_min_ps(a.m,b.m);}
__forceinline void V4::sub(const V4& a){m=_mm_sub_ps(m,a.m);}
__forceinline void V4::add(const V4& a){m=_mm_add_ps(m,a.m);}
__forceinline void V4::abs(const LocalM128& mask){m=_mm_and_ps(m,mask);}
__forceinline float V4::lengthSquared3() const {
  LocalM128 square=_mm_mul_ps(m,m); float r;
  _mm_store_ss(&r,_mm_add_ss(_mm_shuffle_ps(square,square,0xaa),_mm_add_ss(_mm_shuffle_ps(square,square,0x55),square)));
  return r;
}
struct F8 { V4 lower, upper; };
struct BoundsRef { F8* p; F8* operator->() const { return p; } operator F8*() const { return p; } }; 
struct Resource { int unk00, unk04, unk08, unk0c; void* allocator; };
extern void* hkMemoryRouter_getInstance();
extern void ResizeAudioStream(void* a, void* b, int c);
static const __declspec(align(16)) unsigned int AbsMask[4] = { 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff };


struct Diagnostic {
  int unk00, unk04, unk08;
  void FUN_00cb1600(char*, int);
  void ProcessAndReturnValue_00cc01c0(const char*);
  void FUN_00cc00e0();
};
struct ErrorReporter {
  virtual void ReportDiagnostic(); virtual void unused1(); virtual void unused2();
  virtual int report(int, unsigned int, const char*, const char*, int);
};
extern int DAT_01268360;
struct Query {
  void queryOnTree(P1*, unsigned char*);
  __forceinline int classify(P1* state, unsigned char* stream, int offset, F8* bounds) {
    float r2 = center[3] * center[3];
    V4 sum, extent, outside;
    sum.setAdd(bounds->upper,bounds->lower);
    extent.setSub(bounds->upper,bounds->lower);
    sum.sub(*(const V4*)center);
    sum.abs(*(const LocalM128*)AbsMask);
    outside.setMin(sum,extent);
    outside.sub(sum);
    float near2=outside.lengthSquared3();
    if(near2>r2) return 0;
    extent.add(sum);
    float far2=extent.lengthSquared3();
    if(far2<r2){queryOnTree(state,stream+offset);return 1;}
    return 2;
  }
  __forceinline int classifyLocal(P1* state, unsigned char* stream, int offset, F8* bounds) {
    float r2 = center[3] * center[3];
    V4 sum, extent, outside;
    sum.setAdd(bounds->upper,bounds->lower);
    extent.setSub(bounds->upper,bounds->lower);
    sum.sub(*(const V4*)center);
    sum.abs(*(const LocalM128*)AbsMask);
    outside.setMin(sum,extent);
    outside.sub(sum);
    float near2=outside.lengthSquared3();
    if(near2>r2) return 0;
    extent.add(sum);
    float far2=extent.lengthSquared3();
    if(far2<r2){queryOnTree(state,stream+offset);return 1;}
    return 2;
  }
  hkArray<int>* results; int unk24; int unk28; int unk2c;
  float center[4];
};
struct Cls {
  hkArray<int>* vec;
  int unk04; int unk08; int unk0c;
  float scale;
  int unk14; int unk18; int unk1c;
  Query query;
  __forceinline void scan(P1* cur, unsigned char* p, int& offset, F8* const bounds) {
    int code;
      code = p[offset];
      while (code >= 38 && 43 >= code) {
        if (code >= 41) {
          bounds->lower.f[code - 41] = (float)readPacked(p+offset+1) * scale;
          bounds->upper.f[code - 41] = (float)((((p[offset+4] << 8) + p[offset+5]) << 8) + p[offset+6]) * scale;
          offset += 7;
        } else {
          bounds->lower.f[code - 38] = (float)((p[offset+1] << cur->f14) + cur->fields[code - 36]) * scale;
          bounds->upper.f[code - 38] = (float)((p[offset+2] << cur->f14) + cur->fields[code - 36]) * scale;
          offset += 3;
        }
        code = p[offset];
      }

  }
  __forceinline void scanRight(P1* cur, unsigned char* p, int& offset, F8* const bounds) {
    int code;
      code = p[offset];
      while (code >= 38 && 43 >= code) {
        if (code >= 41) {
          bounds->lower.f[code - 41] = (float)readPacked(p+offset+1) * scale;
          bounds->upper.f[code - 41] = (float)readUpper(p+offset+4)*scale;
          offset += 7;
        } else {
          bounds->lower.f[code - 38] = (float)((p[offset+1] << cur->f14) + cur->fields[code - 36]) * scale;
          bounds->upper.f[code - 38] = (float)((p[offset+2] << cur->f14) + cur->fields[code - 36]) * scale;
          offset += 3;
        }
        code = p[offset];
      }

  }
  void Interpret_Thunk(P1* a1, unsigned char* p, F8* a3);
  __forceinline void interpret(P1* a1, unsigned char* p, F8* const& a3);
};
__forceinline void Cls::interpret(P1* a1, unsigned char* p, F8* const& a3) {
  P1 local;
  F8 val;
  P1* cur = a1;
  int left, right, code;
  for (;;) {
    int op = *p;
    switch (op) {
    case 0: return;
    case 19: case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28: {
      right = p[3];
      val.lower.m = a3->lower.m;
      val.upper.m = a3->upper.m;
      p += 4;
      F8* child=&val;
      Interpret_Thunk(cur, p, child);
      p += right;
      break;
    }
    case 16: case 17: case 18: {
      val.lower.m = a3->lower.m;
      val.upper.m = a3->upper.m;
      int r;
      r = p[2];
      a3->upper.f[op - 16] = (float)((p[1] << cur->f14) + cur->fields[op - 14]) * scale;
      val.lower.f[op - 16] = (float)((r << cur->f14) + cur->fields[op - 14]) * scale;
      left = 0; p += 4; right = p[-1];
      goto branch_common;
    }
    case 32: case 33: case 34: {
      val.lower.m = a3->lower.m;
      val.upper.m = a3->upper.m;
      int r = p[1] + 1;
      val.lower.f[op - 32] = (float)((p[1] << cur->f14) + cur->fields[op - 30]) * scale;
      a3->upper.f[op - 32] = (float)((r << cur->f14) + cur->fields[op - 30]) * scale;
      left = 0; p += 3; right = p[-1];
      goto branch_common;
    }
    case 35: case 36: case 37: {
      val.lower.m = a3->lower.m;
      val.upper.m = a3->upper.m;
      long r;
      r = p[2];
      a3->upper.f[op - 35] = (float)((p[1] << cur->f14) + cur->fields[op - 33]) * scale;
      val.lower.f[op - 35] = (float)((r << cur->f14) + cur->fields[op - 33]) * scale;
      left = ((unsigned int)p[3] << 8) + p[4];
      right = ((unsigned int)p[5] << 8) + p[6];
      p += 7;
    }
    branch_common: {
      scan(cur, p, left, a3);
      F8* scanned=&val; scanRight(cur, p, right, scanned);
      int second = query.classifyLocal(cur, p, right, &val);
      int loc = query.classify(cur, p, left, a3);
      if (second != 2) {
        if (loc != 2) return;
        p += left;
      } else if (loc != 2) {
        F8* destination = a3;
        destination->lower.m = val.lower.m;
        destination->upper.m = val.upper.m;
        p += right;
      } else {
        F8* child=&val;
        Interpret_Thunk(cur, p + right, child);
        p += left;
      }
      break;
    }
    case 41: case 42: case 43:
      a3->lower.f[op - 41] = (float)readPacked(p+1) * scale;
      a3->upper.f[op - 41] = (float)((((p[4] << 8) + p[5]) << 8) + p[6]) * scale;
      p += 7;
      goto preserve_metadata;
    case 38: case 39: case 40:
      a3->lower.f[op - 38] = (float)((p[1] << cur->f14) + cur->fields[op - 36]) * scale;
      a3->upper.f[op - 38] = (float)((p[2] << cur->f14) + cur->fields[op - 36]) * scale;
      p += 3;
    preserve_metadata:
      if (*p >= 38 && *p <= 43) break;
      {
        int result = query.classify(cur, p, 0, a3);
        if (!result) return;
        if (1 == result) return;
      }
      break;
    case 5: p += (unsigned int)p[1] + 2; break;
    case 6: p += ((unsigned int)p[1] << 8) + p[2] + 3; break;
    case 7: p += ((((unsigned int)p[1] << 8) + p[2]) << 8) + p[3] + 4; break;
    case 1: case 2: case 3: case 4: {
      local.xyz[0] = (int)((unsigned int)p[1] << cur->f14) + cur->xyz[0];
      local.xyz[1] = (int)((unsigned int)p[2] << cur->f14) + cur->xyz[1];
      local.xyz[2] = (int)((unsigned int)p[3] << cur->f14) + cur->xyz[2];
      local.f14 = cur->f14 - (int)op;
      local.f4 = cur->f4;
      local.f0 = cur->f0;
      cur = &local;
      p += 4;
      break;
    }
    case 9: {
      int keep = p[1];
      if (cur != &local) { local = *cur; cur = &local; }
      local.f0 += keep;
      p += 2;
      break;
    }
    case 10: {
      int keep = (p[1] << 8) + p[2];
      if (cur != &local) { local = *cur; cur = &local; }
      local.f0 += keep;
      p += 3;
      break;
    }
    case 11: {
      int keep = (readPacked(p+1) << 8) + p[4];
      if (cur != &local) { local = *cur; cur = &local; }
      local.f0 = keep;
      p += 5;
      break;
    }
    case 96: case 97: case 98: case 99: {
      int keep = p[1];
      p += 2;
      local.fields[op - 95] = keep;
      goto slot;
    }
    case 100: case 101: case 102: case 103: {
      int keep = (int)(((unsigned int)p[1] << 8) + p[2]);
      local.fields[op - 99] = keep;
      p += 3;
      goto slot;
    }
    case 104: case 105: case 106: case 107: {
      int keep = (int)(((((((unsigned int)p[1] << 8) + p[2]) << 8) + p[3]) << 8) + p[4]);
      local.fields[op - 103] = keep;
      p += 5;
      goto slot;
    }
    slot: {
      int pForm;
      pForm = local.f4;
      if (cur != &local) { local = *cur; cur = &local; }
      local.f4 = pForm;
      break;
    }
    default: {
      Diagnostic high;
      int buffer[128];
      high.FUN_00cb1600((char*)buffer, 512);
      high.ProcessAndReturnValue_00cc01c0("Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
      if (((ErrorReporter*)DAT_01268360)->report(3, 0x1298fedd, (char*)buffer, "d:\\build\\20091222_000100_AiAnBeClDePh\\Source\\Physics/Internal/Collide/Mopp/Machine/hkpMoppUsingFloatAabbVirtualMachine.inl", 301)) __debugbreak();
      high.FUN_00cc00e0();
      break;
    }
    case 80: right = p[1]; goto append;
    case 81: right = ((p[1] << 8) + p[2]); goto append;
    case 82: right = (((p[1] << 8) + p[2]) << 8) + p[3]; goto append;
    case 83: right = (readPacked(p+1) << 8) + p[4]; goto append;
    case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55:
    case 56: case 57: case 58: case 59: case 60: case 61: case 62: case 63:
    case 64: case 65: case 66: case 67: case 68: case 69: case 70: case 71:
    case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 79:
      right = op - 48;
    append: {
      hkArray<int>* item=vec; unsigned int bounds_test=right; _ReadWriteBarrier(); *(volatile int*)&right=right; bounds_test+=cur->f0;
      Resource* first = (Resource*)hkMemoryRouter_getInstance();
      if (item->m_iElementCount == (item->m_iCapacityState & 0x3fffffff)) ResizeAudioStream(first->allocator, item, 4);
      int* message = &item->m_data[item->m_iElementCount++];
      *message = bounds_test;
      return;
    }
    }
  }
}

// @fnv 0x00e5f070
// src: GUESS 0x00e5f070 (confidence: medium)
void Cls::Interpret_Thunk(P1* a1, unsigned char* p, F8* a3) { interpret(a1, p, a3); }

extern "C" void _ReadWriteBarrier();
__forceinline int rightPacked(const unsigned char* q){return ((q[0]<<8)+q[1]<<8)+q[2];}
extern "C" void _ReadWriteBarrier();
__forceinline int packedLocal(const unsigned char* q){_ReadWriteBarrier(); int a=q[0]; return ((a<<8)+q[1]<<8)+q[2];}
extern "C" void _ReadWriteBarrier();
static __forceinline int read24(const unsigned char* q) {_ReadWriteBarrier(); int a=q[0]; int b=q[1]; int c=q[2]; return ((a<<8)+b<<8)+c;}
extern "C" void __debugbreak();
struct IntegerOrigin { int x,y,z; int& operator[](int i) { return (&x)[i]; }
    int volatileAt(int i) const { return reinterpret_cast<const volatile int*>(&x)[i]; } };
struct DecodeState {
    int baseID; int property; IntegerOrigin origin; int shift;
    int& propertyAt(int i) { return (&property)[i]; }
};
struct __declspec(align(16)) BoundsPair { LocalM128 minimum; LocalM128 maximum;
    BoundsPair& operator=(const BoundsPair& b) { minimum=b.minimum; maximum=b.maximum; return *this; }
};
struct AllocatorContext { int unk00; int unk04; int unk08; int unk0C; void* allocator; };
void ResizeAudioStream(void*, void*, int);
struct DiagnosticStream {
    void* vtable; int flags; void* writer;
    void FUN_00cb1600(void*, int);
    void ProcessAndReturnValue_00cc01c0(const char*);
    void FUN_00cc00e0();
};
extern const char str_010d5100[];
extern const char str_010ecd88[];
struct __declspec(align(16)) PlanePacket { LocalM128 x,y,z,w; };
struct CullMachine {
    int unk00; int unk04; int unk08; int unk0C; int count; int unk14; int unk18; int unk1C;
    PlanePacket planes[8];
    PlanePacket absolutePlanes[8];
    void hkpMoppFindAllVirtualMachine_queryOnTreeLeft(DecodeState*, const unsigned char*);
    void hkpMoppFindAllVirtualMachine_queryOnTreeRight(DecodeState*, const unsigned char*);
    __forceinline int classify(DecodeState* state, const unsigned char* code, const BoundsPair& bounds) {
        int allInside = 15;
        const PlanePacket* p=planes;
        const PlanePacket* q=absolutePlanes;
        LocalM128 center = _mm_add_ps(bounds.maximum, bounds.minimum);
        LocalM128 extent = _mm_sub_ps(bounds.maximum, bounds.minimum);
        for (int n=count; --n >= 0; ++p, ++q) {
            LocalM128 radius = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(q->x.m128_f32),_mm_shuffle_ps(extent,extent,0)),
                           _mm_mul_ps(_mm_load_ps(q->y.m128_f32),_mm_shuffle_ps(extent,extent,0x55))),
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(q->z.m128_f32),_mm_shuffle_ps(extent,extent,0xaa)),_mm_load_ps(q->w.m128_f32)));
            LocalM128 distance = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(p->x.m128_f32),_mm_shuffle_ps(center,center,0)),
                           _mm_mul_ps(_mm_load_ps(p->y.m128_f32),_mm_shuffle_ps(center,center,0x55))),
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(p->z.m128_f32),_mm_shuffle_ps(center,center,0xaa)),_mm_load_ps(p->w.m128_f32)));
            if (_mm_movemask_ps(_mm_cmplt_ps(_mm_sub_ps(distance,radius),_mm_setzero_ps())) != 15) return 0;
            allInside &= _mm_movemask_ps(_mm_cmplt_ps(_mm_add_ps(distance,radius),_mm_setzero_ps()));
        }
        if (allInside == 15) {
            hkpMoppFindAllVirtualMachine_queryOnTreeLeft(state,code);
            hkpMoppFindAllVirtualMachine_queryOnTreeRight(state,code);
            return 1;
        }
        return 2;
    }
    __forceinline int classifyB(DecodeState* state, const unsigned char* code, const BoundsPair& bounds) {
        const LocalM128& lower=bounds.minimum;
        int allInside = 15;
        int n=count;
        const PlanePacket* p=planes;
        const PlanePacket* q=absolutePlanes;
        LocalM128 center = _mm_add_ps(bounds.maximum, lower);
        LocalM128 extent = _mm_sub_ps(bounds.maximum, lower);
        for (; --n >= 0; ++p, ++q) {
            LocalM128 px=p->x;
            LocalM128 radius = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(q->x,_mm_shuffle_ps(extent,extent,0)),
                           _mm_mul_ps(q->y,_mm_shuffle_ps(extent,extent,0x55))),
                _mm_add_ps(_mm_mul_ps(q->z,_mm_shuffle_ps(extent,extent,0xaa)),q->w));
            LocalM128 distance = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(center,center,0),px),
                           _mm_mul_ps(_mm_load_ps(p->y.m128_f32),_mm_shuffle_ps(center,center,0x55))),
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(p->z.m128_f32),_mm_shuffle_ps(center,center,0xaa)),_mm_load_ps(p->w.m128_f32)));
            if (_mm_movemask_ps(_mm_cmplt_ps(_mm_sub_ps(distance,radius),_mm_setzero_ps())) != 15) return 0;
            allInside &= _mm_movemask_ps(_mm_cmplt_ps(_mm_add_ps(distance,radius),_mm_setzero_ps()));
        }
        if (allInside == 15) {
            hkpMoppFindAllVirtualMachine_queryOnTreeLeft(state,code);
            hkpMoppFindAllVirtualMachine_queryOnTreeRight(state,code);
            return 1;
        }
        return 2;
    }
};
struct TreeDecoder {
    hkArray<int>* output;
    int unk04; int unk08; int unk0C; float scale; int unk14; int unk18; int unk1C;
    CullMachine cull;
    void ProcessEntries_00e5e430(DecodeState*, const unsigned char*, BoundsPair*);
    __forceinline void emit(int value) {
        hkArray<int>* a = output;
        AllocatorContext* context = (AllocatorContext*)hkMemoryRouter_getInstance();
        if (a->m_iElementCount == (a->m_iCapacityState & 0x3fffffff)) ResizeAudioStream(context->allocator,a,4);
        int* destination = &a->m_data[a->m_iElementCount]; ++a->m_iElementCount; *destination = value;
    }
    __forceinline void readBounds(DecodeState* state, const unsigned char* code, int& offset, BoundsPair& bounds, const float& scalar) {
        int op = code[offset];
        while (op >= 0x26 && op <= 0x2b) {
            if (op >= 0x29) {
                bounds.minimum.m128_f32[op-0x29] = read24(code+offset+1)*scalar;
                bounds.maximum.m128_f32[op-0x29] = int(((code[offset+4]<<8)+code[offset+5]<<8)+code[offset+6])*scalar;
                offset += 7;
            } else {
                bounds.minimum.m128_f32[op-0x26] = (state->origin[op-0x26] + (code[offset+1]<<state->shift))*scalar;
                bounds.maximum.m128_f32[op-0x26] = (state->origin[op-0x26] + (code[offset+2]<<state->shift))*scalar;
                offset += 3;
            }
            op = code[offset];
        }
    }    __forceinline void readBoundsRight(DecodeState* state, const unsigned char* code, int& offset, BoundsPair& bounds) {
        int op = code[offset];
        while (op >= 0x26 && op <= 0x2b) {
            if (op >= 0x29) {
                bounds.minimum.m128_f32[op-0x29] = read24(code+offset+1)*scale;
                bounds.maximum.m128_f32[op-0x29] = (int)rightPacked(code+offset+4)*scale;
                offset += 7;
            } else {
                bounds.minimum.m128_f32[op-0x26] = (state->origin[op-0x26] + (code[offset+1]<<state->shift))*scale;
                bounds.maximum.m128_f32[op-0x26] = (state->origin[op-0x26] + (code[offset+2]<<state->shift))*scale;
                offset += 3;
            }
            op = code[offset];
        }
    }

};
// @fnv 0x00e5e430
// src: GUESS 0x00e5e430 (confidence: low)
void TreeDecoder::ProcessEntries_00e5e430(DecodeState* state, const unsigned char* code, BoundsPair* bounds)
{
    DecodeState localState;
    BoundsPair localBounds;
    void* buffer[128]; DiagnosticStream stream;
    int diagnosticResult;
    int left, right, value;
    for (;;) {
        int op = *code;
        if ((unsigned)op > 0x6b) {
            stream.FUN_00cb1600(buffer,512);
            stream.ProcessAndReturnValue_00cc01c0(str_010d5100);
            diagnosticResult=((ErrorReporter*)DAT_01268360)->report(3,0x1298fedd,(const char*)buffer,str_010ecd88,301);
            goto DiagnosticTail;
        }
        switch (op) {
        case 0: return;
        case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1c: {
            int skip=code[3]; localBounds=*bounds; code+=4;
            ProcessEntries_00e5e430(state,code,&localBounds); code+=skip; break;
        }
        case 0x10: case 0x11: case 0x12: {
            localBounds=*bounds;
            int v1=code[1], v2=code[2];
            bounds->maximum.m128_f32[op-0x10]=(state->origin[op-0x10]+(v1<<state->shift))*scale;
            localBounds.minimum.m128_f32[op-0x10]=(state->origin[op-0x10]+(v2<<state->shift))*scale;
            left=0; right=code[3]; code+=4; goto split; }
        case 0x20: case 0x21: case 0x22: {
localBounds=*bounds; int r=code[1]+1; localBounds.minimum.m128_f32[op-0x20]=(state->origin[op-0x20]+(code[1]<<state->shift))*scale; bounds->maximum.m128_f32[op-0x20]=(state->origin[op-0x20]+(r<<state->shift))*scale;
            left=0; right=code[2]; code+=3; goto split;
        }
        case 0x23: case 0x24: case 0x25: {
            localBounds=*bounds;
            int v1=code[1],v2=code[2];
            bounds->maximum.m128_f32[op-0x23]=(state->origin[op-0x23]+(v1<<state->shift))*scale;
            localBounds.minimum.m128_f32[op-0x23]=(state->origin[op-0x23]+(v2<<state->shift))*scale;
            int lh=code[3],rh=code[5],ll=code[4],rl=code[6];
            left=(lh<<8)+ll; right=(rh<<8)+rl; code+=7; }
        split: {
            readBounds(state,code,left,*bounds,scale);
            readBoundsRight(state,code,right,localBounds);
            const unsigned char* rightCode=code+right;
            int rightResult=cull.classify(state,rightCode,localBounds);
            const unsigned char* leftCode=code+left;
            int leftResult=cull.classify(state,leftCode,*bounds);
            if (rightResult != 2) { if (leftResult != 2) return; code=leftCode; }
            else if (leftResult != 2) { *bounds=localBounds; code=rightCode; }
            else { ProcessEntries_00e5e430(state,rightCode,&localBounds); code=leftCode; }
            break;
        }
        case 0x29: case 0x2a: case 0x2b:
            bounds->minimum.m128_f32[op-0x29]=packedLocal(code+1)*scale;
            bounds->maximum.m128_f32[op-0x29]=read24(code+4)*scale;
            code+=7; goto cullBounds;
        case 0x26: case 0x27: case 0x28:
            bounds->minimum.m128_f32[op-0x26]=(state->origin[op-0x26]+(code[1]<<state->shift))*scale;
            bounds->maximum.m128_f32[op-0x26]=(state->origin[op-0x26]+(code[2]<<state->shift))*scale;
            code+=3;
        cullBounds:
            if (*code >=0x26 && *code<=0x2b) break;
            { int result=cull.classifyB(state,code,*bounds); if(result!=2) return; }
            break;
        case 5: code+=code[1]+2; break;
        case 6: code+=(code[1]<<8)+code[2]+3; break;
        case 7: code+=(((code[1]<<8)+code[2])<<8)+code[3]+4; break;
        case 1: case 2: case 3: case 4:
            localState.origin[0]=state->origin[0]+(code[1]<<state->shift);
            localState.origin[1]=state->origin[1]+(code[2]<<state->shift);
            localState.origin[2]=state->origin[2]+(code[3]<<state->shift);
            localState.shift=state->shift-op;
            localState.property=state->property; localState.baseID=state->baseID;
            state=&localState; code+=4; break;
        case 9: {
            int value=code[1];
            if(state!=&localState) {localState=*state;state=&localState;}
            localState.baseID+=value; code+=2; break;
        }
        case 10: {
            int value=(code[1]<<8)+code[2];
            if(state!=&localState) {localState=*state;state=&localState;}
            localState.baseID+=value; code+=3; break;
        }
        case 11: {
            int value=((((code[1]<<8)+code[2])<<8)+code[3])<<8; value+=code[4];
            if(state!=&localState) {localState=*state;state=&localState;}
            localState.baseID=value; code+=5; break;
        }
        case 0x60: case 0x61: case 0x62: case 0x63:
            { int propertyValue=code[1]; code+=2; localState.propertyAt(op-0x60)=propertyValue; goto property; }
        case 0x64: case 0x65: case 0x66: case 0x67:
            localState.propertyAt(op-0x64)=(code[1]<<8)+code[2]; code+=3; goto property;
        case 0x68: case 0x69: case 0x6a: case 0x6b:
            localState.propertyAt(op-0x68)=((((((code[1]<<8)+code[2])<<8)+code[3])<<8)+code[4]); code+=5;
        property: {
            int value=localState.property;
            if(state!=&localState) {localState=*state;state=&localState;}
            localState.property=value; break;
        }
        default: {

            stream.FUN_00cb1600(buffer,512);
            stream.ProcessAndReturnValue_00cc01c0(str_010d5100);
            diagnosticResult=((ErrorReporter*)DAT_01268360)->report(3,0x1298fedd,(const char*)buffer,str_010ecd88,301);
        DiagnosticTail:
            if(diagnosticResult) __debugbreak();
            stream.FUN_00cc00e0(); break;
        }
        case 0x50: value=code[1]; goto terminal;
        case 0x51: value=(code[1]<<8)+code[2]; goto terminal;
        case 0x52: value=(((code[1]<<8)+code[2])<<8)+code[3]; goto terminal;
        case 0x53: value=(((((code[1]<<8)+code[2])<<8)+code[3])<<8)+code[4]; goto terminal;
        case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37:
        case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f:
        case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47:
        case 0x48: case 0x49: case 0x4a: case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f:
            value=op-0x30;
        terminal: value += state->baseID; emit(value); return;
        }
    }
}


extern const LocalM128 DAT_01017d10;

struct hkQuatStore_e52190 { LocalM128 m_vec; };

// @fnv 0x00e52190
// src: GUESS 0x00e52190 (confidence: low)
void __cdecl hkQuatStore_e52190_ComputeValues_00e52190(const hkQuatStore_e52190* q, unsigned char* out)
{
    static const float s_scale = (float)((float)sqrt(2.0) * 63.0);
    LocalM128 a = _mm_and_ps(q->m_vec, DAT_01017d10);
    const float* f = (const float*)&q->m_vec;
    int idx = 0;
    if (a.m128_f32[1] > a.m128_f32[0]) idx = 1;
    if (a.m128_f32[2] > a.m128_f32[idx]) idx = 2;
    if (a.m128_f32[3] > a.m128_f32[idx]) idx = 3;
    int i = (idx == 0);
    float sc = s_scale;
    unsigned char c[3];
    c[0] = (unsigned char)((int)(f[i++] * sc) + 0x3f);
    i += (i == idx);
    c[1] = (unsigned char)((int)(f[i++] * sc) + 0x3f);
    c[2] = (unsigned char)((int)(f[i + (i == idx)] * sc) + 0x3f);
    out[0] = (unsigned char)((idx << 7) | c[0]);
    out[1] = (unsigned char)(((idx & ~1) << 6) | c[1]);
    out[2] = c[2];
    out[2] = (unsigned char)(((f[idx] < 0.0f) << 7) | c[2]);
}
