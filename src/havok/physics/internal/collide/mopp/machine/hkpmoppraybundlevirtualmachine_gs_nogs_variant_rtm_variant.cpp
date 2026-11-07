// src/havok/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
#include "fnv_asm_helpers.h"
// src/havok/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
__declspec(align(16)) struct FUN_00dd4a50_cls
{
    __m128 m_v00;
    unsigned int m_i10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    __m128 m_v20;
    unsigned int m_i30;
    unsigned int m_i34;

    FUN_00dd4a50_cls* InitializeFields_00dd4a50(const FUN_00dd4a50_cls* src);
};

extern const char str_010d7b64[];
class ScalarValue {
 __m128 data;
 public:
 inline ScalarValue(float f) {data=_mm_load_ss(&f);}
 inline ScalarValue(const __m128& q) {data=q;}
 inline ScalarValue() {}
 __forceinline __m128 broadcast() const {return _mm_shuffle_ps(data,data,0);}
 __forceinline const __m128& getQuad() const {return data;}
};
class CompareValue;
class PackedVector {
 __m128 value;
 public:
 __forceinline float& operator()(int i) {return value.m128_f32[i];}
 __forceinline void operator=(const PackedVector& v) { value=v.value; }
 __forceinline void operator=(const __m128& v) { value=v; }
 __forceinline __m128 read() const {return value;}
 __forceinline operator __m128() const {return value;}
 __forceinline __m128& getQuad() { return value; }
 __forceinline const __m128& getQuad() const { return value; }
 __forceinline void set(float x,float y,float z,float w) { value=_mm_setr_ps(x,y,z,w); }
 __forceinline __m128 scaleAndGet(const PackedVector& f) {value=_mm_mul_ps(f.value,value);return value;}
 __forceinline void setZero4() { value=_mm_setzero_ps(); }
 __forceinline void setAdd4(const PackedVector& a,const PackedVector& b) { value=_mm_add_ps(a.value,b.value); }
 __forceinline void add4(const PackedVector& a) { value=_mm_add_ps(value,a.value); }
 __forceinline void setSub4(const PackedVector& a,const PackedVector& b) { value=_mm_sub_ps(a.value,b.value); }
 __forceinline void sub4(const PackedVector& b) { value=_mm_sub_ps(value,b.value); }
 __forceinline void setMul4(const ScalarValue& a,const PackedVector& b) {value=_mm_mul_ps(a.broadcast(),b.value);}
 __forceinline void setMul4(const PackedVector& a,const PackedVector& b) { value=_mm_mul_ps(a.value,b.value); }
 __forceinline void mul4(const PackedVector& b) { value=_mm_mul_ps(value,b.value); }
 __forceinline void addMul4(const PackedVector& a,const PackedVector& b) { __m128 product=_mm_mul_ps(a.value,b.value);value=_mm_add_ps(value,product); }
 __forceinline void setReciprocal4(const PackedVector& a);
 __forceinline void setNeg4(const PackedVector& a);
 __forceinline void setBroadcast(const PackedVector& a,int lane) {
  if(lane==0)value=_mm_shuffle_ps(a.value,a.value,0);
  else if(lane==1)value=_mm_shuffle_ps(a.value,a.value,0x55);
  else if(lane==2)value=_mm_shuffle_ps(a.value,a.value,0xaa);
  else if(lane==3)value=_mm_shuffle_ps(a.value,a.value,0xff);
 }
 __forceinline CompareValue compareLessThan4(const PackedVector& a) const;
 __forceinline CompareValue compareGreaterThan4(const PackedVector& a) const;
 __forceinline CompareValue compareLessThanZero4() const;
 __forceinline void select32(const PackedVector& a,const PackedVector& b,const CompareValue& c);
};
typedef PackedVector FourFloats;
typedef __m128 PackedQuad;
extern const FourFloats DAT_010c44d0;
extern const FourFloats DAT_010ce1c0;
static __forceinline __m128 ReciprocalNative(__m128 x) {
 __m128 approximation=_mm_rcp_ps(x);
 return _mm_sub_ps(_mm_add_ps(approximation,approximation),_mm_mul_ps(_mm_mul_ps(approximation,x),approximation));
}
__forceinline void PackedVector::setReciprocal4(const PackedVector& a) { value=ReciprocalNative(a.value); }
__forceinline void PackedVector::setNeg4(const PackedVector& a) { value=_mm_xor_ps(a.value,DAT_010c44d0.getQuad()); }
class CompareValue {
 __m128 bits;
 friend class PackedVector;
 public:
 __forceinline void setSelect(const CompareValue& a,const CompareValue& b,const CompareValue& c) {bits=_mm_or_ps(_mm_and_ps(c.bits,b.bits),_mm_andnot_ps(c.bits,a.bits));}
 __forceinline void setAnd(const CompareValue& a,const CompareValue& b) { bits=_mm_and_ps(a.bits,b.bits); }
 __forceinline void setOr(const CompareValue& a,const CompareValue& b) { bits=_mm_or_ps(a.bits,b.bits); }
 __forceinline void setNot(const CompareValue& a) { bits=_mm_andnot_ps(a.bits,DAT_010ce1c0.getQuad()); }
 __forceinline int allAreSet() const { return _mm_movemask_ps(bits)==15; }
 __forceinline int anyIsSet() const { return _mm_movemask_ps(bits); }
};
__forceinline CompareValue PackedVector::compareLessThan4(const PackedVector& a) const { CompareValue c;c.bits=_mm_cmplt_ps(value,a.value);return c; }
__forceinline CompareValue PackedVector::compareGreaterThan4(const PackedVector& a) const { CompareValue c;c.bits=_mm_cmplt_ps(a.value,value);return c; }
__forceinline CompareValue PackedVector::compareLessThanZero4() const { CompareValue c;c.bits=_mm_cmplt_ps(value,_mm_setzero_ps());return c; }
__forceinline void PackedVector::select32(const PackedVector& a,const PackedVector& b,const CompareValue& c) {
 value=_mm_or_ps(_mm_and_ps(c.bits,b.value),_mm_andnot_ps(c.bits,a.value));
}


static __forceinline FourFloats MakePacked(float v) {
 FourFloats r;
 r.getQuad().m128_f32[0]=v;r.getQuad().m128_f32[1]=v;
 r.getQuad().m128_f32[2]=v;r.getQuad().m128_f32[3]=v;return r;
}
struct VectorValue {

    __m128 data;

    __forceinline VectorValue() {}

    __forceinline VectorValue(const __m128& value) {data=value;}

    __forceinline operator const __m128&() const {return data;}

    __forceinline VectorValue& operator=(const __m128& value) {data=value; return *this;}

};



struct PlaneDistance { __m128 simd; __forceinline PlaneDistance() {}

 __forceinline PlaneDistance(const FourFloats& v) {simd.m128_f32[0]=v.getQuad().m128_f32[0];simd.m128_f32[1]=v.getQuad().m128_f32[1];simd.m128_f32[2]=v.getQuad().m128_f32[2];simd.m128_f32[3]=v.getQuad().m128_f32[3];}

};

struct QueryState {

    FourFloats offset;

    int shift;

    FourFloats scale;

    unsigned int primitiveBase;

    unsigned int properties[1];

    QueryState& __thiscall InitializeFields_00dd4a50(const QueryState*);

};

struct VectorTriple { FourFloats axis[3]; };

struct RayQuerySet {

    VectorTriple ends[2];

    FourFloats active;

    void __thiscall CopyRotationsAndExtraVector(const RayQuerySet*) throw();

};

struct TreeData {

    int unk00, unk04, unk08, unk0c;

    FourFloats offset;

    const unsigned char* code;

};

struct OutputLane {

    int unk00, unk04, unk08, unk0c;

    float fraction;

    int unk14, unk18, unk1c;

    unsigned int keys[8];

    int count;

    int unk44, unk48, unk4c;

    __forceinline void PushDepth() { ++count; }
 __forceinline void changeLevel(int n) {count+=n;}
 __forceinline void setKey(unsigned int k) {keys[count]=k;}

    __forceinline void PopDepth() { --count; }



};

struct FilterData {FourFloats from,to; void* data; int zero;};



struct ShapeBuffer {

    FourFloats storage[32];

};

struct Shape;

struct QueryContext;

struct BoolValue {

    char value;

    __forceinline BoolValue(bool b):value(b) {}

    __forceinline operator bool() const {return value!=0;}

};

struct ShapeFilter {

    virtual __declspec(nothrow) BoolValue __thiscall Test(const void*, Shape*, Shape*, unsigned int) throw()=0;

};

struct QueryContext {

    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;

    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;

    int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;

    void* filterData;

    ShapeFilter* filter;

};

struct Shape {

    virtual __declspec(nothrow) void slot00() throw()=0;

    virtual __declspec(nothrow) void slot04() throw()=0;

    virtual __declspec(nothrow) void slot08() throw()=0;

    virtual __declspec(nothrow) void slot0c() throw()=0;

    virtual __declspec(nothrow) void slot10() throw()=0;

    virtual __declspec(nothrow) Shape* __thiscall GetChild(unsigned int, void*) throw()=0;

    virtual __declspec(nothrow) void slot18() throw()=0;

    virtual __declspec(nothrow) void slot1c() throw()=0;

    virtual __declspec(nothrow) void slot20() throw()=0;

    virtual __declspec(nothrow) void slot24() throw()=0;

    virtual __declspec(nothrow) FourFloats __thiscall CastBundle(QueryContext*, OutputLane*, FourFloats*) throw()=0;

};

struct ErrorStream {
 int unk00,unk04,unk08;
 __declspec(nothrow) void FUN_00cb1600(void*,int) throw();
 __declspec(nothrow) void FUN_00cc00e0() throw();
 __declspec(nothrow) void ProcessAndReturnValue_00cc01c0(const char*) throw();
};
struct ErrorHandler {

    virtual __declspec(nothrow) void slot00() throw()=0;

    virtual __declspec(nothrow) void slot04() throw()=0;

    virtual __declspec(nothrow) void slot08() throw()=0;

    virtual __declspec(nothrow) int __thiscall Report(int, unsigned int, const char*, const char*, int) throw()=0;

};

extern ErrorHandler* DAT_01268360;

extern unsigned char DAT_01269cbe;

extern __declspec(nothrow) void __cdecl FUN_00df22f0(unsigned char*) throw();

extern const float DAT_01011d78;

extern const FourFloats DAT_010c7170;

extern const FourFloats DAT_010ce1c0;

extern const FourFloats DAT_010c44d0;

extern const unsigned int DAT_010c92e0[4];



static __forceinline __m128 SelectVector(__m128 mask, __m128 yes, const __m128& no) {

    return _mm_or_ps(_mm_and_ps(yes,mask),_mm_andnot_ps(mask,no));

}

static __forceinline FourFloats RefineReciprocal(__m128 difference) {

    __m128 estimate=_mm_rcp_ps(difference);

    FourFloats result;result=_mm_sub_ps(_mm_add_ps(estimate,estimate),_mm_mul_ps(_mm_mul_ps(estimate,difference),estimate));return result;

}

// src: XBOX_PDB 0x00dd3120
static __declspec(noinline) int hkpProcessFlyingColors(const FourFloats* mask, const FourFloats* start, const FourFloats* end) {

    __m128 less=_mm_and_ps(_mm_cmpgt_ps(end->getQuad(),start->getQuad()),mask->getQuad());

    __m128 total=SelectVector(mask->getQuad(),DAT_010c7170.getQuad(),_mm_setzero_ps());

    total=_mm_mul_ps(total,DAT_010c7170.getQuad());

    total=_mm_add_ps(_mm_shuffle_ps(total,total,0x4e),total);

    __m128 count=SelectVector(less,DAT_010c7170.getQuad(),_mm_setzero_ps());

    count=_mm_mul_ps(count,DAT_010c7170.getQuad());

    total=_mm_add_ps(_mm_shuffle_ps(total,total,0xb1),total);

    count=_mm_add_ps(_mm_shuffle_ps(count,count,0x4e),count);

    count=_mm_add_ps(_mm_shuffle_ps(count,count,0xb1),count);

    count=_mm_shuffle_ps(count,count,0);

    total=_mm_shuffle_ps(total,total,0);

    return _mm_movemask_ps(_mm_cmple_ps(total,_mm_add_ps(count,count)));

}

// src: GUESS 0x00dd2fd0 (confidence: low)
static __declspec(noinline) void hkSimdReal_ComputeValues_00dd2fd0(const FourFloats* endDistance,

    const FourFloats* startDistance, FourFloats* startWeight, FourFloats* endWeight) {

    __m128 reciprocal=RefineReciprocal(_mm_sub_ps(startDistance->getQuad(),endDistance->getQuad())).getQuad();

    startWeight->getQuad()=_mm_mul_ps(startDistance->getQuad(),reciprocal);

    endWeight->getQuad()=_mm_mul_ps(endDistance->getQuad(),reciprocal);

    endWeight->getQuad()=_mm_xor_ps(endWeight->getQuad(),DAT_010c44d0.getQuad());

}

static __forceinline void ClipPlane(RayQuerySet* result,const RayQuerySet* original,

    const FourFloats& startDistanceValue,const FourFloats& endDistanceValue, const __m128& zeroValue,bool keepBelow) {

    __m128 startDistance=startDistanceValue.getQuad(),endDistance=endDistanceValue.getQuad();

    __m128 fromX=original->ends[0].axis[0].getQuad();

    __m128 fromY=original->ends[0].axis[1].getQuad();

    __m128 fromZ=original->ends[0].axis[2].getQuad();

    __m128 toX=original->ends[1].axis[0].getQuad();

    __m128 toY=original->ends[1].axis[1].getQuad();

    __m128 toZ=original->ends[1].axis[2].getQuad();

    __m128 crossing=_mm_cmpgt_ps(zeroValue,_mm_mul_ps(endDistance,startDistance));

    __m128 reciprocal=RefineReciprocal(_mm_sub_ps(startDistance,endDistance)).getQuad();

    __m128 startWeight=_mm_xor_ps(_mm_mul_ps(reciprocal,endDistance),DAT_010c44d0.getQuad());

    __m128 endWeight=_mm_mul_ps(reciprocal,startDistance);

    __m128 direction=keepBelow?_mm_cmpgt_ps(endDistance,startDistance):_mm_cmpgt_ps(startDistance,endDistance);

    __m128 startMask=_mm_and_ps(_mm_andnot_ps(direction,DAT_010ce1c0.getQuad()),crossing);

    __m128 endMask=_mm_and_ps(direction,crossing);

    __m128 point0=_mm_add_ps(_mm_mul_ps(fromX,startWeight),_mm_mul_ps(toX,endWeight));

    result->ends[0].axis[0]=SelectVector(startMask,point0,fromX);

    result->ends[1].axis[0]=SelectVector(endMask,point0,toX);

    __m128 point1=_mm_add_ps(_mm_mul_ps(fromY,startWeight),_mm_mul_ps(toY,endWeight));

    result->ends[0].axis[1]=SelectVector(startMask,point1,fromY);

    result->ends[1].axis[1]=SelectVector(endMask,point1,toY);

    __m128 point2=_mm_add_ps(_mm_mul_ps(fromZ,startWeight),_mm_mul_ps(toZ,endWeight));

    result->ends[0].axis[2]=SelectVector(startMask,point2,fromZ);

    result->ends[1].axis[2]=SelectVector(endMask,point2,toZ);

}

static __forceinline const CompareValue& MaskOf(const FourFloats& v) {
 return reinterpret_cast<const CompareValue&>(v);
}
static __forceinline void StoreMask(FourFloats& v,const CompareValue& m) {
 v=reinterpret_cast<const __m128&>(m);
}
static __forceinline CompareValue Crossing(const FourFloats& a,const FourFloats& b) {
 FourFloats zero,product;zero.setZero4();product.setMul4(a,b);return product.compareLessThan4(zero);
}
static __forceinline void Weights(const FourFloats& a,const FourFloats& b,FourFloats& t,FourFloats& omt) {
 FourFloats delta,inv;delta.setSub4(a,b);inv.setReciprocal4(delta);
 t.setMul4(a,inv);omt.setMul4(b,inv);omt.setNeg4(omt);
}
static __forceinline void Interpolate(const VectorTriple& start,const VectorTriple& end,
 VectorTriple& outStart,VectorTriple& outEnd,const FourFloats& t,const FourFloats& omt,
 const CompareValue& m0,const CompareValue& m1) {
 FourFloats point;
 point.setMul4(omt,start.axis[0]);point.addMul4(t,end.axis[0]);
 outStart.axis[0].select32(outStart.axis[0],point,m0);outEnd.axis[0].select32(outEnd.axis[0],point,m1);
 point.setMul4(omt,start.axis[1]);point.addMul4(t,end.axis[1]);
 outStart.axis[1].select32(outStart.axis[1],point,m0);outEnd.axis[1].select32(outEnd.axis[1],point,m1);
 point.setMul4(omt,start.axis[2]);point.addMul4(t,end.axis[2]);
 outStart.axis[2].select32(outStart.axis[2],point,m0);outEnd.axis[2].select32(outEnd.axis[2],point,m1);
}

struct ProductPair {FourFloats to,from;__forceinline ProductPair(const FourFloats& a,const FourFloats& b,const FourFloats& c,const FourFloats& d) {to=_mm_mul_ps(b.read(),d.read());from=_mm_mul_ps(a.read(),c.read());}__forceinline __m128 total() const {return _mm_add_ps(from.read(),to.read());} };
static __forceinline ProductPair MakeProducts(const FourFloats& a,const FourFloats& b,const FourFloats& c,const FourFloats& d) {return ProductPair(a,b,c,d);}
static __forceinline void InterpolateRight(const VectorTriple& start,const VectorTriple& end,
 VectorTriple& outStart,VectorTriple& outEnd,const FourFloats& t,const FourFloats& omt,
 const CompareValue& m0,const CompareValue& m1) {
 FourFloats point;
 ProductPair pair(omt,t,start.axis[0],end.axis[0]);point=pair.total();
 outStart.axis[0].select32(outStart.axis[0],point,m0);outEnd.axis[0].select32(outEnd.axis[0],point,m1);
 point.setMul4(omt,start.axis[1]);point.addMul4(t,end.axis[1]);
 outStart.axis[1].select32(outStart.axis[1],point,m0);outEnd.axis[1].select32(outEnd.axis[1],point,m1);
 point.setMul4(omt,start.axis[2]);point.addMul4(t,end.axis[2]);
 outStart.axis[2].select32(outStart.axis[2],point,m0);outEnd.axis[2].select32(outEnd.axis[2],point,m1);
}

struct CodeView {const unsigned char* p;};static __forceinline int ReadWide(CodeView v) {const unsigned char*p=v.p;return (((p[0]<<8)+p[1])<<8)+p[2];}
static __forceinline __m128 PlaneDiff(__m128 a,__m128 b) {return _mm_sub_ps(a,b);}
static __forceinline __m128 DecodeScalar(int x) {float f=float(x);return _mm_load_ss(&f);}
static __forceinline void ScaleEndpoint(FourFloats& out,const FourFloats& factor) {out=_mm_mul_ps(factor.getQuad(),out.getQuad());}
static __forceinline void OrderChild(bool chooseRight,RayQuerySet*& first,RayQuerySet*& next,int& offset,int& nextOffset,RayQuerySet* left,RayQuerySet* right,int leftOffset,int rightOffset) {
 first=left;next=right;offset=leftOffset;nextOffset=rightOffset;
 if(chooseRight){next=left;first=right;offset=rightOffset;nextOffset=leftOffset;}
}
static __forceinline __m128 IsBelow(__m128 a,__m128 b) {return _mm_cmplt_ps(a,b);}
static __forceinline __m128 IsAbove(__m128 a,__m128 b) {return _mm_cmplt_ps(b,a);}
struct AlignedView {const __m128& q;__forceinline AlignedView(const __m128& v):q(v){} __forceinline operator const __m128&()const{return q;}};
struct RayBundleTraversalMachine {

    int unk00,unk04,unk08,unk0c;

    TreeData* tree;

    int unk14,unk18,unk1c;

    FourFloats byteScale;

    QueryContext* context;

    int unk34,unk38,unk3c;

    FourFloats originalStartX, originalStartY, originalStartZ;

    FourFloats originalEndX, originalEndY, originalEndZ;

    FourFloats hitMask;

    FourFloats hitFractions;

    OutputLane* output;

    int unkC4,unkC8;

    Shape* shape;

    unsigned int chunkMask;

__forceinline void UpdateNext(const QueryState* state,RayQuerySet* next);
    void __thiscall hkpMoppRayBundleVirtualMachine_queryRayOnTree(const QueryState* state, const unsigned char* code,

                                RayQuerySet* rays, unsigned int chunk);

};



__forceinline void RayBundleTraversalMachine::UpdateNext(const QueryState* state,RayQuerySet* next) {
__m128 beyond=_mm_sub_ps(DAT_010c7170.getQuad(),hitFractions.getQuad());

            __m128 hit;

            hit = _mm_cmplt_ps(hitFractions.getQuad(),DAT_010c7170.getQuad());

            __m128 endpointX=_mm_add_ps(_mm_mul_ps(originalEndX.getQuad(),beyond),_mm_mul_ps(originalStartX.getQuad(),hitFractions.getQuad()));

            endpointX=_mm_sub_ps(endpointX,_mm_shuffle_ps(tree->offset.getQuad(),tree->offset.getQuad(),0));

            endpointX=_mm_mul_ps(endpointX,_mm_shuffle_ps(state->scale.getQuad(),state->scale.getQuad(),0));

            endpointX=_mm_sub_ps(endpointX,_mm_shuffle_ps(state->offset.getQuad(),state->offset.getQuad(),0));

            next->ends[1].axis[0]=SelectVector(hit,endpointX,next->ends[1].axis[0].getQuad());

            __m128 endpointY=_mm_add_ps(_mm_mul_ps(originalEndY.getQuad(),beyond),_mm_mul_ps(originalStartY.getQuad(),hitFractions.getQuad()));

            endpointY=_mm_sub_ps(endpointY,_mm_shuffle_ps(tree->offset.getQuad(),tree->offset.getQuad(),85));

            endpointY=_mm_mul_ps(endpointY,_mm_shuffle_ps(state->scale.getQuad(),state->scale.getQuad(),85));

            endpointY=_mm_sub_ps(endpointY,_mm_shuffle_ps(state->offset.getQuad(),state->offset.getQuad(),85));

            next->ends[1].axis[1]=SelectVector(hit,endpointY,next->ends[1].axis[1].getQuad());

            __m128 r=_mm_add_ps(_mm_mul_ps(originalEndZ.getQuad(),beyond),_mm_mul_ps(originalStartZ.getQuad(),hitFractions.getQuad()));

            r=_mm_sub_ps(r,_mm_shuffle_ps(tree->offset.getQuad(),tree->offset.getQuad(),170));

            r=_mm_mul_ps(r,_mm_shuffle_ps(state->scale.getQuad(),state->scale.getQuad(),170));

            r=_mm_sub_ps(r,_mm_shuffle_ps(state->offset.getQuad(),state->offset.getQuad(),170));

            next->ends[1].axis[2]=SelectVector(hit,r,next->ends[1].axis[2].getQuad());

}

// @fnv 0x00dd3210
// src: XBOX_PDB 0x00dd3210
void RayBundleTraversalMachine::hkpMoppRayBundleVirtualMachine_queryRayOnTree(const QueryState* state, const unsigned char* code,

                               RayQuerySet* rays, unsigned int chunk) {

    if (DAT_01269cbe == 0) {

        FUN_00df22f0(&DAT_01269cbe);

        if (DAT_01269cbe == 0) return;

    }

    QueryState propertyCopy; // Local copy-on-write traversal state.

    for (;;) {

        int command=code[0];

        const int splitNode=code[2];

        FourFloats bytes;

        float decoded0=(float)(int)command; bytes.getQuad().m128_f32[0]=decoded0;

        float decoded1=(float)(int)code[1]; bytes.getQuad().m128_f32[1]=decoded1;

        const unsigned int byte1=code[1];

        float decoded2=(float)(int)splitNode; bytes.getQuad().m128_f32[2]=decoded2;

        const unsigned int byte3=code[3];

        float decoded3=(float)(int)byte3; bytes.getQuad().m128_f32[3]=decoded3;



        unsigned int primitive;

        int axis=999;

        int leftJump,rightJump;

        FourFloats projectStart,boundLow,projectEnd,boundHigh;


        switch (command) {

case 0x13: {

            VectorValue packed=_mm_sub_ps(_mm_add_ps(bytes.getQuad(),bytes.getQuad()),MakePacked(0.0f).getQuad());
boundHigh=_mm_shuffle_ps(packed,packed,0x55);
boundLow=_mm_shuffle_ps(packed,packed,0xaa);

            projectStart=_mm_add_ps(rays->ends[0].axis[2].getQuad(),rays->ends[0].axis[1].getQuad());

            projectEnd=_mm_add_ps(rays->ends[1].axis[2].getQuad(),rays->ends[1].axis[1].getQuad());

            goto afterDiagonal;

        }
case 0x14: {

            VectorValue packed=_mm_sub_ps(_mm_add_ps(bytes.getQuad(),bytes.getQuad()),MakePacked(255.0f).getQuad());
boundHigh=_mm_shuffle_ps(packed,packed,0x55);
boundLow=_mm_shuffle_ps(packed,packed,0xaa);

            projectStart=_mm_sub_ps(rays->ends[0].axis[1].getQuad(),rays->ends[0].axis[2].getQuad());

            projectEnd=_mm_sub_ps(rays->ends[1].axis[1].getQuad(),rays->ends[1].axis[2].getQuad());

            goto afterDiagonal;

        }
case 0x15: {

            VectorValue packed=_mm_sub_ps(_mm_add_ps(bytes.getQuad(),bytes.getQuad()),MakePacked(0.0f).getQuad());
boundHigh=_mm_shuffle_ps(packed,packed,0x55);
boundLow=_mm_shuffle_ps(packed,packed,0xaa);

            projectStart=_mm_add_ps(rays->ends[0].axis[2].getQuad(),rays->ends[0].axis[0].getQuad());

            projectEnd=_mm_add_ps(rays->ends[1].axis[2].getQuad(),rays->ends[1].axis[0].getQuad());

            goto afterDiagonal;

        }
case 0x16: {

            VectorValue packed=_mm_sub_ps(_mm_add_ps(bytes.getQuad(),bytes.getQuad()),MakePacked(255.0f).getQuad());
boundHigh=_mm_shuffle_ps(packed,packed,0x55);
boundLow=_mm_shuffle_ps(packed,packed,0xaa);

            projectStart=_mm_sub_ps(rays->ends[0].axis[0].getQuad(),rays->ends[0].axis[2].getQuad());

            projectEnd=_mm_sub_ps(rays->ends[1].axis[0].getQuad(),rays->ends[1].axis[2].getQuad());

            goto afterDiagonal;

        }
case 0x17: {

            VectorValue packed=_mm_sub_ps(_mm_add_ps(bytes.getQuad(),bytes.getQuad()),MakePacked(0.0f).getQuad());
boundHigh=_mm_shuffle_ps(packed,packed,0x55);
boundLow=_mm_shuffle_ps(packed,packed,0xaa);

            projectStart=_mm_add_ps(rays->ends[0].axis[1].getQuad(),rays->ends[0].axis[0].getQuad());

            projectEnd=_mm_add_ps(rays->ends[1].axis[1].getQuad(),rays->ends[1].axis[0].getQuad());

            goto afterDiagonal;

        }
case 0x18: {

            VectorValue packed=_mm_sub_ps(_mm_add_ps(bytes.getQuad(),bytes.getQuad()),MakePacked(255.0f).getQuad());
boundHigh=_mm_shuffle_ps(packed,packed,0x55);
boundLow=_mm_shuffle_ps(packed,packed,0xaa);

            projectStart=_mm_sub_ps(rays->ends[0].axis[0].getQuad(),rays->ends[0].axis[1].getQuad());

            projectEnd=_mm_sub_ps(rays->ends[1].axis[0].getQuad(),rays->ends[1].axis[1].getQuad());

            goto afterDiagonal;

        }
case 0x19: {

            VectorValue packed=_mm_sub_ps(_mm_add_ps(_mm_add_ps(bytes.getQuad(),bytes.getQuad()),bytes.getQuad()),MakePacked(0.0f).getQuad());
boundHigh=_mm_shuffle_ps(packed,packed,0x55);
boundLow=_mm_shuffle_ps(packed,packed,0xaa);

            projectStart=_mm_add_ps(_mm_add_ps(rays->ends[0].axis[1].getQuad(),rays->ends[0].axis[0].getQuad()),rays->ends[0].axis[2].getQuad());

            projectEnd=_mm_add_ps(_mm_add_ps(rays->ends[1].axis[1].getQuad(),rays->ends[1].axis[0].getQuad()),rays->ends[1].axis[2].getQuad());

            goto afterDiagonal;

        }
case 0x1a: {

            VectorValue packed=_mm_sub_ps(_mm_add_ps(_mm_add_ps(bytes.getQuad(),bytes.getQuad()),bytes.getQuad()),MakePacked(255.0f).getQuad());
boundHigh=_mm_shuffle_ps(packed,packed,0x55);
boundLow=_mm_shuffle_ps(packed,packed,0xaa);

            projectStart=_mm_sub_ps(_mm_add_ps(rays->ends[0].axis[1].getQuad(),rays->ends[0].axis[0].getQuad()),rays->ends[0].axis[2].getQuad());

            projectEnd=_mm_sub_ps(_mm_add_ps(rays->ends[1].axis[1].getQuad(),rays->ends[1].axis[0].getQuad()),rays->ends[1].axis[2].getQuad());

            goto afterDiagonal;

        }
case 0x1b: {

            VectorValue packed=_mm_sub_ps(_mm_add_ps(_mm_add_ps(bytes.getQuad(),bytes.getQuad()),bytes.getQuad()),MakePacked(255.0f).getQuad());
boundHigh=_mm_shuffle_ps(packed,packed,0x55);
boundLow=_mm_shuffle_ps(packed,packed,0xaa);

            projectStart=_mm_add_ps(_mm_sub_ps(rays->ends[0].axis[0].getQuad(),rays->ends[0].axis[1].getQuad()),rays->ends[0].axis[2].getQuad());

            projectEnd=_mm_add_ps(_mm_sub_ps(rays->ends[1].axis[0].getQuad(),rays->ends[1].axis[1].getQuad()),rays->ends[1].axis[2].getQuad());

            goto afterDiagonal;

        }
case 0x1c: {

            VectorValue packed=_mm_sub_ps(_mm_add_ps(_mm_add_ps(bytes.getQuad(),bytes.getQuad()),bytes.getQuad()),MakePacked(510.0f).getQuad());
boundHigh=_mm_shuffle_ps(packed,packed,0x55);
boundLow=_mm_shuffle_ps(packed,packed,0xaa);

            projectStart=_mm_sub_ps(_mm_sub_ps(rays->ends[0].axis[0].getQuad(),rays->ends[0].axis[1].getQuad()),rays->ends[0].axis[2].getQuad());

            projectEnd=_mm_sub_ps(_mm_sub_ps(rays->ends[1].axis[0].getQuad(),rays->ends[1].axis[1].getQuad()),rays->ends[1].axis[2].getQuad());

            goto afterDiagonal;

}
        case 0x20:case 0x21:case 0x22:

            axis=command-0x20;

            projectStart=rays->ends[0].axis[axis].getQuad();

            projectEnd=rays->ends[1].axis[axis].getQuad();

            boundHigh=_mm_shuffle_ps(bytes.getQuad(),bytes.getQuad(),0x55);

            boundLow=boundHigh.getQuad();

            boundHigh=_mm_add_ps(boundHigh.getQuad(),DAT_010c7170.getQuad());

            code+=3;leftJump=0;rightJump=code[-1];

            goto byte2;

        case 0x23:case 0x24:case 0x25:
 axis=command-0x23;
boundHigh=_mm_shuffle_ps(bytes.getQuad(),bytes.getQuad(),0x55);
boundLow=_mm_shuffle_ps(bytes.getQuad(),bytes.getQuad(),0xaa);
projectStart=rays->ends[0].axis[axis].getQuad();
projectEnd=rays->ends[1].axis[axis].getQuad();
leftJump=(byte3<<8)+code[4];code+=7;rightJump=(code[-2]<<8)+code[-1];
 goto byte2;
        case 0x10:case 0x11:case 0x12:

            axis=command-0x10;

            projectStart=rays->ends[0].axis[axis].getQuad();

            projectEnd=rays->ends[1].axis[axis].getQuad();

            boundLow=bytes.getQuad();

clipNode: // Common ordinary split setup.

        decodePlane:
boundHigh=_mm_shuffle_ps(boundLow.getQuad(),boundLow.getQuad(),0x55);
boundLow=_mm_shuffle_ps(boundLow.getQuad(),boundLow.getQuad(),0xaa);

afterDiagonal:
        code+=4;leftJump=0;rightJump=code[-1];

byte2: {
 CompareValue belowMask,aboveMask;
 {
  CompareValue a=projectEnd.compareLessThan4(boundLow);
  CompareValue b=projectStart.compareLessThan4(boundLow);
  belowMask.setAnd(a,b);belowMask.setAnd(MaskOf(rays->active),belowMask);
 }
 {
  CompareValue a=projectStart.compareGreaterThan4(boundHigh);
  CompareValue b=projectEnd.compareGreaterThan4(boundHigh);
  aboveMask.setAnd(a,b);aboveMask.setAnd(MaskOf(rays->active),aboveMask);
 }
{CompareValue inactiveMask,temp;
 inactiveMask.setNot(MaskOf(rays->active));temp.setOr(belowMask,inactiveMask);
 if(temp.allAreSet()) {code+=leftJump;continue;}}
 {CompareValue inactiveMask,temp;
 inactiveMask.setNot(MaskOf(rays->active));temp.setOr(aboveMask,inactiveMask);
 if(temp.allAreSet()) {code+=rightJump;continue;}}
 FourFloats startDistance,endDistance,lowStartDistance,lowEndDistance;
 startDistance=PlaneDiff(projectStart.read(),boundHigh.read());
endDistance=PlaneDiff(projectEnd.read(),boundHigh.read());
lowStartDistance=PlaneDiff(projectStart.read(),boundLow.read());
lowEndDistance=PlaneDiff(projectEnd.read(),boundLow.read());
 RayQuerySet left,right;
 left.ends[0].axis[0]=rays->ends[0].axis[0];
left.ends[0].axis[1]=rays->ends[0].axis[1];

left.ends[0].axis[2]=rays->ends[0].axis[2];
left.ends[1].axis[0]=rays->ends[1].axis[0];
left.ends[1].axis[1]=rays->ends[1].axis[1];
left.ends[1].axis[2]=rays->ends[1].axis[2];
right.ends[0].axis[0]=rays->ends[0].axis[0];
__m128 savedZ=rays->ends[0].axis[2].getQuad();
right.ends[0].axis[2]=savedZ;
right.ends[0].axis[1]=rays->ends[0].axis[1];

right.ends[1].axis[0]=rays->ends[1].axis[0];
right.ends[1].axis[1]=rays->ends[1].axis[1];
right.ends[1].axis[2]=rays->ends[1].axis[2];
 {CompareValue dont;dont.setNot(aboveMask);dont.setAnd(MaskOf(rays->active),dont);StoreMask(left.active,dont);}
 {CompareValue dont;dont.setNot(belowMask);dont.setAnd(MaskOf(rays->active),dont);StoreMask(right.active,dont);}


 CompareValue crossingLeft=Crossing(startDistance,endDistance);
 {
  FourFloats t,omt;Weights(startDistance,endDistance,t,omt);
  CompareValue side=startDistance.compareLessThan4(endDistance),other,m0,m1;
  other.setNot(side);m0.setAnd(other,crossingLeft);m1.setAnd(side,crossingLeft);
  Interpolate(left.ends[0],left.ends[1],left.ends[0],left.ends[1],t,omt,m0,m1);
 }

 CompareValue crossingRight=Crossing(lowStartDistance,lowEndDistance);
 {
  FourFloats t,omt;Weights(lowStartDistance,lowEndDistance,t,omt);
  CompareValue side=startDistance.compareGreaterThan4(endDistance),other,m0,m1;
  other.setNot(side);m0.setAnd(other,crossingRight);m1.setAnd(side,crossingRight);
  InterpolateRight(right.ends[0],right.ends[1],right.ends[0],right.ends[1],t,omt,m0,m1);
 }
 RayQuerySet* first;
RayQuerySet* next;
int offset;
int nextJump;
 int rightFirst=!hkpProcessFlyingColors(&rays->active,&startDistance,&endDistance);
OrderChild(rightFirst!=0,first,next,offset,nextJump,&left,&right,leftJump,rightJump);
 hkpMoppRayBundleVirtualMachine_queryRayOnTree(state,code+offset,first,chunk);

UpdateNext(state,next);
            if(3 > axis) {
startDistance.setSub4(projectStart,boundHigh);endDistance.setSub4(projectEnd,boundHigh);


CompareValue direction=startDistance.compareLessThan4(endDistance);
 CompareValue low=next->ends[1].axis[axis].compareLessThan4(boundLow),high=next->ends[1].axis[axis].compareGreaterThan4(boundHigh),prune;
 prune.setSelect(high,low,direction);
 CompareValue both;
 {CompareValue notLeft,notRight;notLeft.setNot(belowMask);notRight.setNot(aboveMask);both.setAnd(notLeft,notRight);}
 prune.setAnd(both,prune);CompareValue hitTest=hitFractions.compareLessThan4(DAT_010c7170);prune.setAnd(prune,hitTest);prune.setNot(prune);prune.setAnd(MaskOf(next->active),prune);StoreMask(next->active,prune);
 }

            if(!_mm_movemask_ps(next->active.getQuad())) return;

            code+=nextJump;

            rays->CopyRotationsAndExtraVector(next);

            continue;

        }

        case 0x29:case 0x2a:case 0x2b: {

axis=command-0x29;CodeView lowView={code+1},highView={code+4};
boundLow.setMul4(float(ReadWide(lowView)),byteScale);boundHigh.setMul4(float((((code[4]<<8)+code[5])<<8)+code[6]),byteScale);boundLow.mul4(state->scale);boundHigh.mul4(state->scale);
                __m128 firstJump;

                if (axis == 0) firstJump = _mm_shuffle_ps(state->offset.getQuad(), state->offset.getQuad(), 0);

                else if (axis == 1) firstJump = _mm_shuffle_ps(state->offset.getQuad(), state->offset.getQuad(), 0x55);

                else if (axis == 2) firstJump = _mm_shuffle_ps(state->offset.getQuad(), state->offset.getQuad(), 0xaa);

                else if (axis == 3) firstJump = _mm_shuffle_ps(state->offset.getQuad(), state->offset.getQuad(), 0xff);

                boundLow=_mm_sub_ps(boundLow.getQuad(),firstJump);

                boundHigh=_mm_sub_ps(boundHigh.getQuad(),firstJump);

                code+=7;

            goto ordinarySplit;

        }

        case 0x26:case 0x27:case 0x28:

            axis=command-0x26;

            boundLow=_mm_shuffle_ps(bytes.getQuad(),bytes.getQuad(),0x55);

            boundHigh=_mm_shuffle_ps(bytes.getQuad(),bytes.getQuad(),0xaa);

            code+=3;

            goto ordinarySplit;

ordinarySplit: { // Clip the current rays to an axis-aligned interval.

            projectStart=rays->ends[0].axis[axis];
            projectEnd=rays->ends[1].axis[axis];

            VectorValue decreasing=_mm_cmple_ps(projectEnd.getQuad(),projectStart.getQuad());

            VectorValue increasing=_mm_cmpgt_ps(projectEnd.getQuad(),projectStart.getQuad());

            VectorValue rejectDown=_mm_or_ps(IsAbove(projectEnd.getQuad(),boundHigh.getQuad()),IsBelow(projectStart.getQuad(),boundLow.getQuad()));

            VectorValue value=_mm_or_ps(IsBelow(projectEnd.getQuad(),boundLow.getQuad()),IsAbove(projectStart.getQuad(),boundHigh.getQuad()));

            VectorValue reject=_mm_or_ps(_mm_andnot_ps(increasing,rejectDown),_mm_and_ps(value,increasing));

            rays->active=_mm_and_ps(_mm_andnot_ps(reject,DAT_010ce1c0.getQuad()),rays->active.getQuad());

            if(!_mm_movemask_ps(rays->active.getQuad())) return;

            VectorTriple oldStart=rays->ends[0];

            VectorTriple oldEnd=rays->ends[1];

            FourFloats endDistance,startDistance,toWeight,fromWeight;

            startDistance=PlaneDiff(projectStart.getQuad(),boundHigh.getQuad());
endDistance=PlaneDiff(projectEnd.getQuad(),boundHigh.getQuad());

            VectorValue ty=_mm_cmplt_ps(_mm_mul_ps(endDistance.getQuad(),startDistance.getQuad()),_mm_setzero_ps());

            hkSimdReal_ComputeValues_00dd2fd0(&endDistance,&startDistance,&toWeight,&fromWeight);

            VectorValue fraction=_mm_and_ps(ty,decreasing);

            VectorValue b=_mm_and_ps(ty,increasing);

            VectorValue upperPoint0=_mm_add_ps(_mm_mul_ps(toWeight.getQuad(),oldEnd.axis[0].getQuad()),_mm_mul_ps(fromWeight.getQuad(),oldStart.axis[0].getQuad()));

            _mm_store_ps(rays->ends[0].axis[0].getQuad().m128_f32,SelectVector(fraction,upperPoint0,rays->ends[0].axis[0].getQuad()));

            _mm_store_ps(rays->ends[1].axis[0].getQuad().m128_f32,SelectVector(b,upperPoint0,rays->ends[1].axis[0].getQuad()));

            VectorValue crossing=_mm_add_ps(_mm_mul_ps(toWeight.getQuad(),_mm_load_ps(oldEnd.axis[1].getQuad().m128_f32)),_mm_mul_ps(fromWeight.getQuad(),oldStart.axis[1].getQuad()));

            _mm_store_ps(rays->ends[0].axis[1].getQuad().m128_f32,SelectVector(fraction,crossing,rays->ends[0].axis[1].getQuad()));

            _mm_store_ps(rays->ends[1].axis[1].getQuad().m128_f32,SelectVector(b,crossing,rays->ends[1].axis[1].getQuad()));

            VectorValue upperPoint2=_mm_add_ps(_mm_mul_ps(toWeight.getQuad(),oldEnd.axis[2].getQuad()),_mm_mul_ps(fromWeight.getQuad(),oldStart.axis[2].getQuad()));

            _mm_store_ps(rays->ends[0].axis[2].getQuad().m128_f32,SelectVector(fraction,upperPoint2,rays->ends[0].axis[2].getQuad()));

            _mm_store_ps(rays->ends[1].axis[2].getQuad().m128_f32,SelectVector(b,upperPoint2,rays->ends[1].axis[2].getQuad()));

            FourFloats lowerEndDistance,lowerStartDistance,lowerToWeight,lowerFromWeight;

            lowerStartDistance=PlaneDiff(projectStart.getQuad(),boundLow.getQuad());
lowerEndDistance=PlaneDiff(projectEnd.getQuad(),boundLow.getQuad());

            ty=_mm_cmplt_ps(_mm_mul_ps(lowerEndDistance.getQuad(),lowerStartDistance.getQuad()),_mm_setzero_ps());

            hkSimdReal_ComputeValues_00dd2fd0(&lowerEndDistance,&lowerStartDistance,&lowerToWeight,&lowerFromWeight);

            fraction=_mm_and_ps(ty,increasing);

            b=_mm_and_ps(ty,decreasing);

            VectorValue lowerPoint0=_mm_add_ps(_mm_mul_ps(lowerToWeight.getQuad(),oldEnd.axis[0].getQuad()),_mm_mul_ps(lowerFromWeight.getQuad(),oldStart.axis[0].getQuad()));

            _mm_store_ps(rays->ends[0].axis[0].getQuad().m128_f32,SelectVector(fraction,lowerPoint0,rays->ends[0].axis[0].getQuad()));

            _mm_store_ps(rays->ends[1].axis[0].getQuad().m128_f32,SelectVector(b,lowerPoint0,rays->ends[1].axis[0].getQuad()));

            VectorValue j=_mm_add_ps(_mm_mul_ps(lowerToWeight.getQuad(),_mm_load_ps(oldEnd.axis[1].getQuad().m128_f32)),_mm_mul_ps(lowerFromWeight.getQuad(),oldStart.axis[1].getQuad()));

            _mm_store_ps(rays->ends[0].axis[1].getQuad().m128_f32,SelectVector(fraction,j,rays->ends[0].axis[1].getQuad()));

            _mm_store_ps(rays->ends[1].axis[1].getQuad().m128_f32,SelectVector(b,j,rays->ends[1].axis[1].getQuad()));

            VectorValue lowerPoint2=_mm_add_ps(_mm_mul_ps(lowerToWeight.getQuad(),oldEnd.axis[2].getQuad()),_mm_mul_ps(lowerFromWeight.getQuad(),oldStart.axis[2].getQuad()));

            _mm_store_ps(rays->ends[0].axis[2].getQuad().m128_f32,SelectVector(fraction,lowerPoint2,rays->ends[0].axis[2].getQuad()));

            _mm_store_ps(rays->ends[1].axis[2].getQuad().m128_f32,SelectVector(b,lowerPoint2,rays->ends[1].axis[2].getQuad()));

            continue;

        }

        case 5: code+=byte1+2; continue;

        case 6: code+=((byte1<<8)+splitNode)+3; continue;

        case 7: code+=(((byte1<<8)+splitNode)<<8)+byte3+4; continue;

        case 12:

            chunk=(byte1<<8)|splitNode;

            code=tree->code+(chunk<<9);

            continue;

        case 13: code+=5;continue;

case 1:case 2:case 3:case 4:{
float txByte=decoded1,tyByte=decoded2,tzByte=decoded3;
FourFloats translation;translation=_mm_setr_ps(txByte,tyByte,tzByte,DAT_01011d78);
 PackedQuad factors[4]={{2.f,2.f,2.f,2.f},{4.f,4.f,4.f,4.f},{8.f,8.f,8.f,8.f},{16.f,16.f,16.f,16.f}};
 FourFloats factor;factor.getQuad()=factors[command-1];
 FourFloats broadcast;
 broadcast.setBroadcast(translation,0);rays->ends[0].axis[0].sub4(broadcast);rays->ends[0].axis[0].setMul4(factor,rays->ends[0].axis[0]);
broadcast.setBroadcast(translation,1);rays->ends[0].axis[1].sub4(broadcast);rays->ends[0].axis[1].setMul4(factor,rays->ends[0].axis[1]);
broadcast.setBroadcast(translation,2);rays->ends[0].axis[2].sub4(broadcast);rays->ends[0].axis[2].setMul4(factor,rays->ends[0].axis[2]);
broadcast.setBroadcast(translation,0);rays->ends[1].axis[0].sub4(broadcast);rays->ends[1].axis[0].scaleAndGet(factor);
broadcast.setBroadcast(translation,1);rays->ends[1].axis[1].sub4(broadcast);rays->ends[1].axis[1].setMul4(factor,rays->ends[1].axis[1]);
broadcast.setBroadcast(translation,2);rays->ends[1].axis[2].sub4(broadcast);rays->ends[1].axis[2].setMul4(factor,rays->ends[1].axis[2]);
propertyCopy.offset.setAdd4(state->offset,translation);propertyCopy.offset.mul4(factor);
 propertyCopy.shift=state->shift+command;propertyCopy.scale.setMul4(factor,state->scale);
 for(int i=0;i<1;++i)propertyCopy.properties[i]=state->properties[i];propertyCopy.primitiveBase=state->primitiveBase;
 state=&propertyCopy;code+=4;continue;}
        case 9:

            if (state!=&propertyCopy) {propertyCopy.InitializeFields_00dd4a50(state);state=&propertyCopy;}

            propertyCopy.primitiveBase+=byte1;

            code+=2;continue;

        case 10: {

            int rejectUp=(byte1<<8)+splitNode;

            if (state!=&propertyCopy) {propertyCopy.InitializeFields_00dd4a50(state);state=&propertyCopy;}

            propertyCopy.primitiveBase+=rejectUp;

            code+=3;continue;

        }

        case 11: {

            int rejectUp=((((byte1<<8)+splitNode)<<8)+byte3)*256+code[4];

            if (state!=&propertyCopy) {propertyCopy.InitializeFields_00dd4a50(state);state=&propertyCopy;}

            propertyCopy.primitiveBase=rejectUp;

            code+=5;continue;

        }

        case 0x60:case 0x61:case 0x62:case 0x63:

            code+=2;

            propertyCopy.properties[command-0x60]=byte1;

            goto localState;

        case 0x64:case 0x65:case 0x66:case 0x67:

            propertyCopy.properties[command-0x64]=(byte1<<8)+splitNode;
            code+=3;

            goto localState;

        case 0x68:case 0x69:case 0x6a:case 0x6b:

            propertyCopy.properties[command-0x68]=((((byte1<<8)+splitNode)<<8)+byte3)*256+code[4];

            code+=5;

localState: { // Preserve the changed property while copying shared state.

            unsigned int property=propertyCopy.properties[0];

            if(state!=&propertyCopy) {propertyCopy.InitializeFields_00dd4a50(state);state=&propertyCopy;}

            propertyCopy.properties[0]=property;

            continue;

        }

        default: {

            ShapeBuffer messageStorageBuf; void* messageStorage = messageStorageBuf.storage;

            {

                ErrorStream stream;stream.FUN_00cb1600(messageStorage,512);

                stream.ProcessAndReturnValue_00cc01c0("Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");

int r=DAT_01268360->Report(3,0x1298fedd,(const char*)messageStorage,

                    str_010d7b64,0x346);if(r){if(r&1){__debugbreak();stream.FUN_00cc00e0();}else{__debugbreak();stream.FUN_00cc00e0();}}else{stream.FUN_00cc00e0();}

                

            }

            continue;

        }

        case 0x50: primitive=code[1];goto leafNode;

        case 0x51: primitive=(code[1]<<8)+code[2];goto leafNode;

        case 0x52: primitive=(((code[1]<<8)+code[2])<<8)+code[3];goto leafNode;

        case 0x53: primitive=(((((code[1]<<8)+code[2])<<8)+code[3])<<8)+code[4];goto leafNode;        case 0x30:

        case 0x31:

        case 0x32:

        case 0x33:

        case 0x34:

        case 0x35:

        case 0x36:

        case 0x37:

        case 0x38:

        case 0x39:

        case 0x3a:

        case 0x3b:

        case 0x3c:

        case 0x3d:

        case 0x3e:

        case 0x3f:

        case 0x40:

        case 0x41:

        case 0x42:

        case 0x43:

        case 0x44:

        case 0x45:

        case 0x46:

        case 0x47:

        case 0x48:

        case 0x49:

        case 0x4a:

        case 0x4b:

        case 0x4c:

        case 0x4d:

        case 0x4e:

        case 0x4f:

            primitive=command-0x30;



leafNode: {

        unsigned int key=(chunkMask&(chunk<<8))|(state->primitiveBase+primitive);

        ShapeBuffer shapeStorageBuf; void* shapeStorage = shapeStorageBuf.storage;

        Shape* child=shape->GetChild(key,shapeStorage);

        if(context->filter) {

            FilterData filterData;

            filterData.data=0;filterData.zero=0;

            filterData.data=context->filterData;

            if(!context->filter->Test(&filterData,child,shape,key)) return;

        }

        output[0].PushDepth();

        output[1].PushDepth();

        output[2].PushDepth();

        output[3].PushDepth();

        FourFloats hits=child->CastBundle(context,output,&rays->active);



        int laneOffset=0;for(int lane=0;4 > lane;++lane,laneOffset+=sizeof(OutputLane)) {

            (*reinterpret_cast<OutputLane*>(reinterpret_cast<unsigned char*>(output)+laneOffset)).PopDepth();

            if(DAT_010c92e0[lane]&_mm_movemask_ps(AlignedView(_mm_load_ps(hits.getQuad().m128_f32)))) {

                hitFractions(lane)=(*reinterpret_cast<OutputLane*>(reinterpret_cast<unsigned char*>(output)+laneOffset)).fraction;

                OutputLane* result=&(*reinterpret_cast<OutputLane*>(reinterpret_cast<unsigned char*>(output)+laneOffset)); result->keys[result->count]=key;

            }



        }

        hitMask=_mm_or_ps(hits.getQuad(),hitMask.getQuad());

        return;

        }

        case 0:return;

        }

    }

}
