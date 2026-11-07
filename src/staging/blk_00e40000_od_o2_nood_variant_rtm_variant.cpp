// src/staging/blk_00e40000_od_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e40000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


#include "fnv_asm_helpers.h"
// Keep the unit's intrinsic layout: SDK byte-array lanes trigger extra /GS code.
#define _INCLUDED_MM2
// Exe 0x00e4b810 FUN_00e4b810: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
#include "../../include/V4.h"
#include "../../include/hkArray.h"
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
void __cdecl hkAlgorithm_quickSortRecursive_float_class_hkAlgorithm_less_float(float* pArr, int d, int h, FloatLess cmpLess);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" int _mm_movemask_ps(LocalM128);
static inline LocalM128 Dot3v(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
static inline LocalM128 Dot3_e4b570(LocalM128 p)
{
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
int __cdecl Runtime_ProcessEntries_00e4b570(const LocalM128* point, const LocalM128* verts, float* out);
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
int __cdecl _hkMoppEarlyExitObbVirtualMachine_queryObb(void* a1, int a2, int a3, int a4);
struct __declspec(align(16)) Vec4E5 { float x, y, z, w; };
struct TmpE5CF40 { Vec4E5 a, b; void hkpMoppSphereVirtualMachine_querySphere(int a, int b, int c); };
void __cdecl _hkMoppSphereVirtualMachine_querySphere(int a, int b, int c);
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
extern "C" LocalM128 _mm_xor_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_and_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_or_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_move_ss(LocalM128,LocalM128);
extern "C" LocalM128 _mm_movelh_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_movehl_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_set_ps(float,float,float,float);
extern "C" LocalM128 _mm_setr_ps(float,float,float,float);
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" LocalM128 _mm_set_ss(float);
extern "C" void _ReadWriteBarrier();
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
extern "C" void _mm_store_ss(float*,LocalM128);
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" float _mm_cvtss_f32(LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
struct hkQuatStore_e52d90 { LocalM128 m_vec; };
struct Shorts_e52d90 { short a; short b; short c; };
void __cdecl hkQuatStore_e52d90_ComputeValues_00e52d90(const unsigned short* in, hkQuatStore_e52d90* out);
extern "C" void _ReadWriteBarrier();
static __forceinline int readPacked(const unsigned char* q) {int a=q[0]; int b=q[1]; int c=q[2]; return ((a<<8)+b<<8)+c;}
static __forceinline int readUpper(const unsigned char* q) {return ((q[0]<<8)+q[1]<<8)+q[2];}
struct P1 { union { struct { int f0; int f4; int xyz[3]; int f14; }; int fields[6]; }; };
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_min_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_and_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" void _mm_store_ss(float*, LocalM128);
__forceinline V4::V4() {}
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
extern "C" void _ReadWriteBarrier();
__forceinline int rightPacked(const unsigned char* q){return ((q[0]<<8)+q[1]<<8)+q[2];}
extern "C" void _ReadWriteBarrier();
__forceinline int packedLocal(const unsigned char* q){_ReadWriteBarrier(); int a=q[0]; return ((a<<8)+q[1]<<8)+q[2];}
extern "C" void _ReadWriteBarrier();
static __forceinline int read24(const unsigned char* q) {_ReadWriteBarrier(); int a=q[0]; int b=q[1]; int c=q[2]; return ((a<<8)+b<<8)+c;}
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" LocalM128 _mm_setzero_ps();
extern "C" LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
extern "C" int _mm_movemask_ps(LocalM128);
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
struct OutputArray { int* data; int size; int capacity; };
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
    OutputArray* output;
    int unk04; int unk08; int unk0C; float scale; int unk14; int unk18; int unk1C;
    CullMachine cull;
    void ProcessEntries_00e5e430(DecodeState*, const unsigned char*, BoundsPair*);
    __forceinline void emit(int value) {
        OutputArray* a = output;
        AllocatorContext* context = (AllocatorContext*)hkMemoryRouter_getInstance();
        if (a->size == (a->capacity & 0x3fffffff)) ResizeAudioStream(context->allocator,a,4);
        int* destination = &a->data[a->size]; ++a->size; *destination = value;
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
extern "C" LocalM128 _mm_and_ps(LocalM128, LocalM128);
extern const LocalM128 DAT_01017d10;
struct hkQuatStore_e52190 { LocalM128 m_vec; };
void __cdecl hkQuatStore_e52190_ComputeValues_00e52190(const hkQuatStore_e52190* q, unsigned char* out);

extern "C" {
LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
LocalM128 _mm_load_ss(const float*);
void _mm_store_ss(float*, LocalM128);
LocalM128 _mm_and_ps(LocalM128, LocalM128);
LocalM128 _mm_add_ps(LocalM128, LocalM128);
}
extern float DAT_0104da48;
extern float DAT_010c6090;
extern double DAT_010290f8;

class FaceScalar
{
    LocalM128 value;
public:
    FaceScalar() {}
    FaceScalar(const LocalM128& input) : value(input) {}
    operator float() const { float result; _mm_store_ss(&result, value); return result; }
    __forceinline const LocalM128& packed() const { return value; }
};
inline FaceScalar operator*(const FaceScalar& left, const FaceScalar& right)
{ return _mm_mul_ss(left.packed(), right.packed()); }
inline FaceScalar operator-(const FaceScalar& left, const FaceScalar& right)
{ return _mm_sub_ss(left.packed(), right.packed()); }
inline int negativeScalar(const FaceScalar& value)
{ return _mm_movemask_ps(value.packed()) & 1; }

struct FaceBasis;
class FaceVector
{
    LocalM128 value;
public:
    __forceinline FaceVector() {}
    __forceinline FaceVector(const FaceVector& other) : value(other.value) {}
    __forceinline void operator=(const FaceVector& other) { value = other.value; }
    __forceinline float& operator()(int i) { return reinterpret_cast<float*>(&value)[i]; }
    __forceinline const float& operator()(int i) const { return reinterpret_cast<const float*>(&value)[i]; }
    __forceinline void difference(const FaceVector& left, const FaceVector& right)
    { value = _mm_sub_ps(left.value, right.value); }
    __forceinline void product(const FaceVector& left, const FaceVector& right)
    { value = _mm_mul_ps(left.value, right.value); }
    __forceinline void scale(float amount)
    {
        LocalM128 scalar = _mm_load_ss(&amount);
        scalar = _mm_shuffle_ps(scalar, scalar, 0);
        value = _mm_mul_ps(scalar, value);
    }
    __forceinline void absolute(const FaceVector& other)
    { value = _mm_and_ps(other.value, DAT_01017d10); }
    __forceinline void cross(const FaceVector& left, const FaceVector& right)
    {
        LocalM128 cyclic = _mm_mul_ps(_mm_shuffle_ps(left.value,left.value,0xc9),_mm_shuffle_ps(right.value,right.value,0xd2));
        LocalM128 reverse = _mm_mul_ps(_mm_shuffle_ps(left.value,left.value,0xd2),_mm_shuffle_ps(right.value,right.value,0xc9));
        value = _mm_sub_ps(cyclic, reverse);
    }
    __forceinline FaceScalar dot(const FaceVector& other) const
    {
        LocalM128 lanes = _mm_mul_ps(value, other.value);
        LocalM128 pair = _mm_add_ss(_mm_shuffle_ps(lanes,lanes,0x55),lanes);
        return _mm_add_ss(_mm_shuffle_ps(lanes,lanes,0xaa),pair);
    }
    __forceinline FaceScalar squaredLength() const { return dot(*this); }
    __forceinline void inverseRotation(const FaceBasis& basis, const FaceVector& input);
};
struct FaceColumns
{
    FaceVector first, second, third;
    __forceinline FaceVector& column(int i) { return (&first)[i]; }
    __forceinline const FaceVector& column(int i) const { return (&first)[i]; }
};
struct __declspec(align(16)) FaceBasis : FaceColumns {};
__forceinline void FaceVector::inverseRotation(const FaceBasis& basis, const FaceVector& input)
{
    LocalM128 row0 = basis.column(0).value;
    LocalM128 row1 = basis.column(1).value;
    LocalM128 row2 = basis.column(2).value;
    LocalM128 lo = _mm_unpacklo_ps(row0,row1);
    LocalM128 hi = _mm_unpackhi_ps(row0,row1);
    row0 = _mm_movelh_ps(lo,row2);
    row1 = _mm_shuffle_ps(_mm_movehl_ps(row0,lo),row2,0xd4);
    row2 = _mm_shuffle_ps(hi,row2,0xe4);
    LocalM128 x = _mm_shuffle_ps(input.value,input.value,0);
    LocalM128 xTerm = _mm_mul_ps(row0,x);
    LocalM128 y = _mm_shuffle_ps(input.value,input.value,0x55);
    LocalM128 yTerm = _mm_mul_ps(row1,y);
    LocalM128 z = _mm_shuffle_ps(input.value,input.value,0xaa);
    LocalM128 zTerm = _mm_mul_ps(row2,z);
    value = _mm_add_ps(_mm_add_ps(xTerm,yTerm),zTerm);
}
template<class T> inline void exchangeValues(T& left, T& right)
{ T old = left; left = right; right = old; }

static __forceinline int edgeFallback(const FaceVector& query, const FaceVector* vertices, FaceVector& distances, float orientation)
{
    int previous = 1;
    int next = 2;
    for (int current = 0; current < 3; previous = next, next = current, ++current)
    {
        if (distances(current) >= 0.0f && distances(previous) >= 0.0f)
        {
            FaceVector firstEdge; firstEdge.difference(vertices[current], vertices[next]);
            FaceVector secondEdge; secondEdge.difference(vertices[previous], vertices[next]);
            FaceVector queryDelta; queryDelta.difference(query, vertices[next]);
            FaceVector apexDelta; apexDelta.difference(vertices[3], vertices[next]);
            FaceScalar queryFirst = queryDelta.dot(firstEdge);
            FaceScalar querySecond = queryDelta.dot(secondEdge);
            FaceScalar apexFirst = apexDelta.dot(firstEdge);
            FaceScalar apexSecond = apexDelta.dot(secondEdge);
            FaceScalar determinant = queryFirst * apexSecond - querySecond * apexFirst;
            if (negativeScalar(determinant)) distances(previous) = -1.0f;
            else distances(current) = -1.0f;
        }
    }
    if (distances(0) > 0.0f) return 0;
    if (distances(1) > 0.0f) return 1;
    if (distances(2) > 0.0f) return 2;
    return -1;
}

// @fnv 0x00e4b810
// src: GUESS 0x00e4b810 (confidence: low)
int __cdecl Runtime_ProcessEntries_00e4b810(const FaceVector& query, const FaceVector* vertices, float orientation)
{
    FaceVector firstEdge; firstEdge.difference(vertices[2], vertices[1]);
    FaceVector secondEdge; secondEdge.difference(vertices[0], vertices[2]);
    FaceVector thirdEdge; thirdEdge.difference(vertices[1], vertices[0]);
    FaceVector apexFirst; apexFirst.difference(vertices[3], vertices[0]);
    FaceVector apexSecond; apexSecond.difference(vertices[3], vertices[1]);
    FaceVector apexThird; apexThird.difference(vertices[3], vertices[2]);
    FaceBasis basis;
    basis.column(0).cross(firstEdge, apexSecond);
    basis.column(1).cross(secondEdge, apexThird);
    basis.column(2).cross(thirdEdge, apexFirst);
    FaceVector delta; delta.difference(query, vertices[3]); delta.scale(orientation);
    FaceVector projected; projected.inverseRotation(basis, delta);
    FaceVector magnitude; magnitude.absolute(projected);
    FaceVector square; square.product(projected, magnitude);
    float distances[3];
    for (int i = 0; i < 3; ++i)
    {
        float norm = basis.column(i).squaredLength();
        if (norm != 0.0f) distances[i] = square(i) / norm;
        else distances[i] = 3.40282e+38f;
    }
    int best = 1;
    if (distances[0] > distances[1]) { exchangeValues(distances[0], distances[1]); best = 0; }
    if (distances[1] > distances[2])
    {
        exchangeValues(distances[1], distances[2]);
        if (distances[0] > distances[1]) exchangeValues(distances[0], distances[1]);
    }
    else best = 2;
    if (distances[2] < DAT_010c6090) return -1;
    if (distances[1] * DAT_010290f8 < distances[2]) return best;
    struct Four { float x,y,z,w; }; Four active = reinterpret_cast<const Four&>(projected);
    return edgeFallback(query, vertices, reinterpret_cast<FaceVector&>(active), orientation);
}
