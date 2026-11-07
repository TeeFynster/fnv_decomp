#include "../../../../../../include/Vec4.h"
#include <string.h>

// src/havok/physics/dynamics/entity/util/hkpentityaabbutil_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/entity/util/hkpentityaabbutil_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/entity/util/hkpentityaabbutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/entity/util/hkpentityaabbutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/dynamics/entity/util/hkpentityaabbutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/util/hkpentityaabbutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00d1b1d0_Item {
    unsigned int m_key;
    int m_uiFilterValue;
};
struct S_00d1b1d0_Less {
    bool operator()(const S_00d1b1d0_Item& a, const S_00d1b1d0_Item& b) const { return a.m_key < b.m_key; }
};
template <typename T>
__forceinline void S_00d1b1d0_swap(T& x, T& y)
{
    __declspec(align(16)) T t(x);
    x = y;
    y = t;
}
void Hkpentityaabbutil_ProcessEntries_00d1b1d0(S_00d1b1d0_Item* pItems, int iLow, int iHigh, S_00d1b1d0_Less cmpLess);
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

// Computes quantized and expanded bounds for compound or single collision objects, sorts and scatters compound records.

#include <xmmintrin.h>

extern "C" double DAT_01011588;

extern "C" float DAT_01016248;

extern "C" float DAT_010ec7f0[4];

extern "C" __m128 DAT_011b6d70;

extern "C" float DAT_01267e30[4];


class ScalarLane {
    __m128 data;
public:
    __forceinline ScalarLane(const __m128& input) : data(input) {}
    __forceinline ScalarLane(float input) { data=_mm_load_ss(&input); }
    __forceinline __m128 quad() const { return data; }
    __forceinline __m128 spread() const { return _mm_shuffle_ps(data,data,0); }
};
__forceinline Vec4::Vec4(const Vec4& input) { memcpy(this,&input,sizeof(*this)); }
// An aliased SIMD source preserves scratch storage until the bounds writer fills it.
__forceinline Vec4::Vec4(const __m128& input) {
    if (static_cast<const void*>(this)!=static_cast<const void*>(&input))
        getQuad()=input;
}
__forceinline void Vec4::operator=(const __m128& input) { reinterpret_cast<__m128&>(*this)=input; }
__forceinline Vec4::operator __m128() const { return reinterpret_cast<const __m128&>(*this); }
__forceinline __m128& Vec4::getQuad() { return *reinterpret_cast<__m128*>(this); }
__forceinline const __m128& Vec4::getQuad() const { return *reinterpret_cast<const __m128*>(this); }
__forceinline float Vec4::getSimdAt(int index) const { return reinterpret_cast<const float*>(this)[index]; }
__forceinline ScalarLane Vec4::lane(int index) const { return _mm_shuffle_ps(reinterpret_cast<const __m128&>(*this),reinterpret_cast<const __m128&>(*this),0xff); }
__forceinline void Vec4::difference(const Vec4& left,const Vec4& right) { reinterpret_cast<__m128&>(*this)=_mm_sub_ps(reinterpret_cast<const __m128&>(left),reinterpret_cast<const __m128&>(right)); }
__forceinline void Vec4::sum(const Vec4& left,const Vec4& right) { reinterpret_cast<__m128&>(*this)=_mm_add_ps(reinterpret_cast<const __m128&>(left),reinterpret_cast<const __m128&>(right)); }
__forceinline void Vec4::add(const Vec4& input) { reinterpret_cast<__m128&>(*this)=_mm_add_ps(reinterpret_cast<__m128&>(*this),reinterpret_cast<const __m128&>(input)); }
__forceinline void Vec4::multiply(const ScalarLane& input) { reinterpret_cast<__m128&>(*this)=_mm_mul_ps(input.spread(),reinterpret_cast<__m128&>(*this)); }
__forceinline void Vec4::multiply(const Vec4& input) { reinterpret_cast<__m128&>(*this)=_mm_mul_ps(reinterpret_cast<__m128&>(*this),reinterpret_cast<const __m128&>(input)); }
__forceinline void Vec4::lower(const Vec4& left,const Vec4& right) { reinterpret_cast<__m128&>(*this)=_mm_min_ps(reinterpret_cast<const __m128&>(left),reinterpret_cast<const __m128&>(right)); }
__forceinline void Vec4::upper(const Vec4& left,const Vec4& right) { reinterpret_cast<__m128&>(*this)=_mm_max_ps(reinterpret_cast<const __m128&>(left),reinterpret_cast<const __m128&>(right)); }
__forceinline void Vec4::blend(const Vec4& left,const Vec4& right,const ScalarLane& ratio) {
    __m128 amount=ratio.spread();
    __m128 complement=_mm_sub_ps(_mm_load_ps(DAT_010ec7f0),amount);
    reinterpret_cast<__m128&>(*this)=_mm_add_ps(_mm_mul_ps(complement,reinterpret_cast<const __m128&>(left)),_mm_mul_ps(amount,reinterpret_cast<const __m128&>(right)));
}
__forceinline ScalarLane Vec4::radius() const {
    __m128 squares=_mm_mul_ps(reinterpret_cast<const __m128&>(*this),reinterpret_cast<const __m128&>(*this));
    __m128 sumxy=_mm_add_ss(_mm_shuffle_ps(squares,squares,0x55),squares);
    return _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(squares,squares,0xaa),sumxy));
}
__forceinline void Vec4::fill(const ScalarLane& input) { reinterpret_cast<__m128&>(*this)=input.spread(); }
__forceinline void Vec4::addScaled(const ScalarLane& scale,const Vec4& input) { reinterpret_cast<__m128&>(*this)=_mm_add_ps(reinterpret_cast<__m128&>(*this),_mm_mul_ps(scale.spread(),reinterpret_cast<const __m128&>(input))); }


struct IVec4 { int x, y, z; union { int w; struct { unsigned char b0,b1,b2,b3; } packed; }; };
struct __declspec(align(16)) BoundsRecord {
    unsigned int minimum[3];
    union { unsigned int word; struct { unsigned char expansion[3]; unsigned char shift; } bytes; } minExtra;
    unsigned int maximum[3];
    union { unsigned int word; struct { unsigned char expansion[3]; unsigned char key; } bytes; } maxExtra;
};

struct __declspec(align(16)) Mat4Like { Vec4 r0,r1,r2,r3; };
struct FloatBounds;
struct __declspec(align(16)) ShapeStorage { unsigned char bytes[512]; };
struct Shape;
struct ShapeParts {
virtual void slot0();
virtual int GetNumChildShapes() const;
virtual unsigned int GetFirstKey() const;
virtual unsigned int GetNextShapeKey(unsigned int) const;
virtual void slot10();
virtual const Shape* GetShapeForKey(unsigned int,ShapeStorage&) const;
};
struct Shape {
virtual void slot0(); virtual void slot4(); virtual void slot8(); virtual void slotc();
virtual const ShapeParts* GetShapeContainer() const;
virtual void slot14(); virtual void slot18();
virtual void getAabb(const Mat4Like&,float,FloatBounds&) const;
};
struct __declspec(align(16)) SweptData { Vec4 center0,center1,rotation0,rotation1,localCenter; };
struct MotionData {
Mat4Like matrix;
SweptData sweep;
Vec4 deltaAngle;
float objectRadius;
__forceinline const SweptData& getSweptTransform() const {return sweep;}
};
struct MotionBox {
unsigned int unk00,unk04,unk08,unk0c;
MotionData state;
__forceinline MotionData* GetMotionState() {return &state;}
__forceinline const MotionData* GetMotionState() const {return &state;}
__forceinline const Mat4Like& getTransform() const {return state.matrix;}
};
struct EntityNode {
unsigned int unk00,unk04,unk08,unk0c;
const Shape* shape;
unsigned int unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
BoundsRecord bounds;
unsigned short numBounds,capacityBounds;
BoundsRecord* childBounds;
unsigned int* childKeys;
unsigned int unk5c;
unsigned int unk60;
unsigned int unk64;
unsigned int unk68;
unsigned int unk6c;
unsigned int unk70;
unsigned int unk74;
unsigned int unk78;
unsigned int unk7c;
unsigned int unk80;
unsigned int unk84;
unsigned int unk88;
unsigned int unk8c;
unsigned int unk90;
unsigned int unk94;
unsigned int unk98;
unsigned int unk9c;
unsigned int unka0;
unsigned int unka4;
unsigned int unka8;
unsigned int unkac;
unsigned int unkb0;
unsigned int unkb4;
unsigned int unkb8;
unsigned int unkbc;
unsigned int unkc0;
unsigned int unkc4;
unsigned int unkc8;
unsigned int unkcc;
unsigned int unkd0;
unsigned int unkd4;
unsigned int unkd8;
unsigned int unkdc;
MotionBox m_pMotionState;
__forceinline const Shape* getShape() const {return shape;}
__forceinline const EntityNode* getCollidable() const {return this;}
};
struct __declspec(align(16)) QuantizationInfo { Vec4 low,high,scale; };
struct CollisionContext {
unsigned int unk00,unk04;
float tolerance;
unsigned int unk0c,unk10,unk14,unk18,unk1c;
QuantizationInfo quantization;
__forceinline float getTolerance() const {return tolerance;}
};
template<class T> class InputField {
T value;
public:
__forceinline operator T() const {return value;}
__forceinline T operator->() const {return value;}
};
struct OffsetInput {
InputField<const MotionData*> source;
Mat4Like transforms[4];
InputField<int> count;
Mat4Like start,inverseEnd;
};
extern "C" void* hkMemoryRouter_getInstance();
extern "C" void hkMotionStateq_SampleSweptMotionTransforms(void*,void*);
__forceinline void Vec4::transform(const Mat4Like& matrix,const Vec4& input) {
    __m128 x=_mm_shuffle_ps(reinterpret_cast<const __m128&>(input),reinterpret_cast<const __m128&>(input),0);
    __m128 rowx=_mm_mul_ps(matrix.r0.getQuad(),x);
    __m128 y=_mm_shuffle_ps(reinterpret_cast<const __m128&>(input),reinterpret_cast<const __m128&>(input),0x55);
    __m128 rowy=_mm_mul_ps(matrix.r1.getQuad(),y);
    __m128 z=_mm_shuffle_ps(reinterpret_cast<const __m128&>(input),reinterpret_cast<const __m128&>(input),0xaa);
    __m128 rowz=_mm_mul_ps(matrix.r2.getQuad(),z);
    reinterpret_cast<__m128&>(*this)=_mm_add_ps(_mm_add_ps(rowx,rowy),_mm_add_ps(rowz,matrix.r3.getQuad()));
}

static __forceinline const Vec4& ZeroVector() { return *reinterpret_cast<const Vec4*>(DAT_01267e30); }

// Preserve the original no-initialization bounds and whole-record copy behavior.
struct UpperVector : Vec4 {
    using Vec4::operator=;
    __forceinline UpperVector() : Vec4(*reinterpret_cast<const __m128*>(this)) {}
};
struct __declspec(align(16)) FloatBounds {
    Vec4 minimum;
    UpperVector maximum;
    __forceinline FloatBounds() :
        minimum(*reinterpret_cast<const __m128*>(&minimum)) {}
    __forceinline FloatBounds(const FloatBounds& input) { memcpy(this,&input,sizeof(*this)); }
};

static __forceinline __m128 TransformPosition(__m128 point, const Vec4* rows) {
    __m128 p0 = _mm_mul_ps(_mm_shuffle_ps(point,point,0),rows[0].getQuad());
    __m128 p1 = _mm_mul_ps(_mm_shuffle_ps(point,point,0x55),rows[1].getQuad());
    __m128 p2 = _mm_mul_ps(_mm_shuffle_ps(point,point,0xaa),rows[2].getQuad());
    return _mm_add_ps(_mm_add_ps(p1,p0),_mm_add_ps(p2,rows[3].getQuad()));
}

static __forceinline void ConvertToUint32(const Vec4& maximum,const __m128& minimum,const Vec4& in,const Vec4& offset,const Vec4& scale,unsigned int* out) {
    Vec4 x;
    x.getQuad() = _mm_add_ps(in.getQuad(),offset.getQuad());
    x.getQuad() = _mm_mul_ps(x.getQuad(),scale.getQuad());
    x.getQuad() = _mm_min_ps(x.getQuad(),maximum.getQuad());
    x.getQuad() = _mm_max_ps(x.getQuad(),minimum);
    out[0] = fnv_FloatToInt(x.getSimdAt(0));
    out[1] = fnv_FloatToInt(x.getSimdAt(1));
    out[2] = fnv_FloatToInt(x.getSimdAt(2));
    out[3] = fnv_FloatToInt(x.getSimdAt(3));
}

static __forceinline void ConvertAabb(const FloatBounds& aabb, const Vec4& offsetLow,const Vec4& offsetHigh,const Vec4& scale,BoundsRecord& out) {
    Vec4 maxVal;
    maxVal.getQuad() = DAT_011b6d70;
    ConvertToUint32(maxVal,ZeroVector().getQuad(),aabb.minimum,offsetLow,scale,out.minimum);
    ConvertToUint32(maxVal,ZeroVector().getQuad(),aabb.maximum,offsetHigh,scale,out.maximum);
}

static __forceinline void CompressExpanded(const BoundsRecord& expanded, BoundsRecord& out) {
    int mix = out.minimum[0] - expanded.minimum[0];
    int miy = out.minimum[1] - expanded.minimum[1];
    int miz = out.minimum[2] - expanded.minimum[2];
    int maxx = expanded.maximum[0] - out.maximum[0];
    int may = expanded.maximum[1] - out.maximum[1];
    int maz = expanded.maximum[2] - out.maximum[2];
    int all = maz | may | maxx | miz | miy | mix;
    int shift = 0;
    while (all >= 0x800) { all = (unsigned int)all >> 4; shift += 4; }
    while (all >= 0x100) { all = (unsigned int)all >> 1; ++shift; }
    out.minExtra.bytes.shift = (unsigned char)shift;
    out.minExtra.bytes.expansion[0] = (unsigned char)(mix >> shift);
    out.minExtra.bytes.expansion[1] = (unsigned char)(miy >> shift);
    out.minExtra.bytes.expansion[2] = (unsigned char)(miz >> shift);
    out.maxExtra.bytes.expansion[0] = (unsigned char)(maxx >> shift);
    out.maxExtra.bytes.expansion[1] = (unsigned char)(may >> shift);
    out.maxExtra.bytes.expansion[2] = (unsigned char)(maz >> shift);
}

static __forceinline void SweepOffset(const OffsetInput& input, const FloatBounds& aabb, FloatBounds& swept) {

    ScalarLane fraction(DAT_01016248);
    Vec4 halfSize; halfSize.difference(aabb.maximum,aabb.minimum); halfSize.multiply(fraction);
    Vec4 middle; middle.blend(aabb.maximum,aabb.minimum,fraction);
    Vec4 localArm; localArm.transform(input.inverseEnd,middle);
    Vec4 lower=middle;
    Vec4 upper=middle;
    {
        Vec4 endpoint; endpoint.transform(input.start,localArm);
        lower.lower(lower,endpoint);
        upper.upper(upper,endpoint);
    }
    union { IVec4 integers; __m128 quad; } originCopy; originCopy.integers=*reinterpret_cast<const IVec4*>(&input.source->getSweptTransform().localCenter);
    const Vec4& origin=*reinterpret_cast<const Vec4*>(&originCopy);
    for(int i=0;i<input.count;++i) {
        Vec4 reach;
        reach.difference(localArm,origin);
        reach.multiply(input.transforms[i].r3.lane(3));
        reach.add(origin);
        Vec4 point; point.transform(input.transforms[i],reach);
        lower.lower(lower,point);
        upper.upper(upper,point);
    }
    {
        ScalarLane distance=halfSize.radius();
        Vec4 radius; radius.fill(distance);
        halfSize.addScaled(input.source->deltaAngle.lane(3),radius);
        halfSize.lower(radius,halfSize);
    }
    swept.minimum.difference(lower,halfSize);
    swept.maximum.sum(upper,halfSize);
    swept.minimum.lower(aabb.minimum,swept.minimum);
    swept.maximum.upper(aabb.maximum,swept.maximum);
}

static __forceinline void SweepSingle(const MotionData* motion, float tolerance, const FloatBounds& aabb, FloatBounds& swept) {
    __m128 zero;
    float angularRadius=motion->deltaAngle.getSimdAt(3)*motion->objectRadius;
    __m128 angular=_mm_set1_ps(angularRadius);
    swept.minimum.getQuad()=_mm_sub_ps(aabb.minimum.getQuad(),angular);
    swept.maximum=_mm_add_ps(aabb.maximum,angular);
    {
        float boundRadius=motion->objectRadius+tolerance;
        Vec4 radius; radius.fill(ScalarLane(boundRadius));
        __m128 upper=_mm_add_ps(motion->getSweptTransform().center1.getQuad(),radius.getQuad());
        __m128 lower=_mm_sub_ps(motion->getSweptTransform().center1.getQuad(),radius.getQuad());
        swept.minimum.getQuad()=_mm_max_ps(swept.minimum.getQuad(),lower);
        swept.minimum.getQuad()=_mm_min_ps(swept.minimum.getQuad(),aabb.minimum.getQuad());
        swept.maximum=_mm_min_ps(swept.maximum,upper);
        swept.maximum=_mm_max_ps(swept.maximum,aabb.maximum);
        zero=_mm_setzero_ps();
    }
    __m128 delta=_mm_sub_ps(motion->getSweptTransform().center0.getQuad(),motion->getSweptTransform().center1.getQuad());
    __m128 lowerDelta=_mm_min_ps(zero,delta);
    __m128 upperDelta=_mm_max_ps(zero,delta);
    swept.minimum.getQuad()=_mm_add_ps(swept.minimum.getQuad(),lowerDelta);
    swept.maximum=_mm_add_ps(swept.maximum,upperDelta);
}

static __forceinline void CopyQuads(void* destination, const void* source, int count) {
    unsigned int* dst = (unsigned int*)destination;
    const unsigned int* src = (const unsigned int*)source;
    do {
        dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];
        dst += 4; src += 4;
    } while (--count > 0);
}

// @fnv 0x00d1a330
// src: XBOX_PDB 0x00d1a330
extern "C" void hkpEntityAabbUtil_entityBatchRecalcAabb(const CollisionContext* context,EntityNode*const* objects,int count) {
    const float slack=(float)((double)context->getTolerance()*DAT_01011588);
    for(int at=0;at<count;++at) {
        EntityNode* object=objects[at];
        const EntityNode* collider=object->getCollidable();
        const Shape* geometry=collider->getShape();
        int allocated=collider->capacityBounds;
        if(allocated) {
            const ShapeParts* parts=geometry->GetShapeContainer();
            int n=parts->GetNumChildShapes();
            int* stack=(int*)hkMemoryRouter_getInstance();
            BoundsRecord* bounds=(BoundsRecord*)*stack;
            *stack+=((unsigned)n*32+127)&~127;
            stack=(int*)hkMemoryRouter_getInstance();
            unsigned int* keys=(unsigned int*)*stack;
            *stack+=(n*4+127)&~127;
            __declspec(align(16)) unsigned char sweepStorage[sizeof(OffsetInput)];
            OffsetInput& sweepInput=*reinterpret_cast<OffsetInput*>(sweepStorage);
            hkMotionStateq_SampleSweptMotionTransforms(object->m_pMotionState.GetMotionState(),&sweepInput);
            FloatBounds total;
            const Vec4& position=object->m_pMotionState.GetMotionState()->getSweptTransform().center1;
            total.minimum.getQuad()=position.getQuad();
            total.maximum.getQuad()=position.getQuad();
            FloatBounds totalSweep=total;
            BoundsRecord* cursor=bounds;
            unsigned int* keyCursor=keys;
            ShapeStorage shapeStorage;
            for(unsigned int key=parts->GetFirstKey();key!=0xffffffffu;key=parts->GetNextShapeKey(key)) {
                const Shape* child=parts->GetShapeForKey(key,shapeStorage);
                FloatBounds box;
                child->getAabb(object->m_pMotionState.getTransform(),slack,box);
                FloatBounds expandedBox;
                SweepOffset(sweepInput,box,expandedBox);
                total.minimum.lower(total.minimum,box.minimum);
                total.maximum.upper(total.maximum,box.maximum);
                totalSweep.minimum.lower(totalSweep.minimum,expandedBox.minimum);
                totalSweep.maximum.upper(totalSweep.maximum,expandedBox.maximum);
                ConvertAabb(box,context->quantization.low,context->quantization.high,context->quantization.scale,*cursor);
                BoundsRecord expanded;
                ConvertAabb(expandedBox,context->quantization.low,context->quantization.high,context->quantization.scale,expanded);
                CompressExpanded(expanded,*cursor);
                cursor->maxExtra.bytes.key=(unsigned char)key;
                *keyCursor=key;
                ++cursor;
                ++keyCursor;
            }
            const_cast<EntityNode*>(collider)->numBounds=(unsigned short)(keyCursor-keys);
            BoundsRecord* output=reinterpret_cast<BoundsRecord*>(&const_cast<EntityNode*>(collider)->bounds);
            ConvertAabb(total,context->quantization.low,context->quantization.high,context->quantization.scale,*output);
            BoundsRecord expanded;
            ConvertAabb(totalSweep,context->quantization.low,context->quantization.high,context->quantization.scale,expanded);
            CompressExpanded(expanded,*output);
            if (n) {
                stack = (int*)hkMemoryRouter_getInstance();
                S_00d1b1d0_Item* pairs = (S_00d1b1d0_Item*)*stack;
                *stack += (n * 8 + 127) & -128;
                if (n > 1) {
                    int* fillValues=reinterpret_cast<int*>(pairs);
                    BoundsRecord* sourceCursor=bounds;
                    for (int i=0;i<n;++i,++sourceCursor,fillValues+=2) {
                        fillValues[1]=i;
                        reinterpret_cast<unsigned int*>(fillValues)[0]=sourceCursor->minimum[0];
                    }
                    S_00d1b1d0_Less less;
                    *reinterpret_cast<unsigned char*>(&less) = 0;
                    Hkpentityaabbutil_ProcessEntries_00d1b1d0(pairs,0,n-1,less);
                } else if (n == 1) pairs[0].m_uiFilterValue = 0;
                BoundsRecord* destination = (BoundsRecord*)collider->childBounds;
                int* destinationKeys = reinterpret_cast<int*>(collider->childKeys);
                if(n>0) {
                const int* valueCursor=&pairs->m_uiFilterValue;
                int remaining=n;
                do {
                    BoundsRecord* source=bounds+*valueCursor;
                    BoundsRecord* output=destination++;
                    CopyQuads(output,source,2);
                    *destinationKeys++=keys[*valueCursor];
                    valueCursor+=2;
                } while(--remaining);
                }
                *(int*)hkMemoryRouter_getInstance() = (int)pairs;
            }
            *(int*)hkMemoryRouter_getInstance()=(int)keys;
            *(int*)hkMemoryRouter_getInstance()=(int)bounds;
        } else {
            FloatBounds box;
            geometry->getAabb(object->m_pMotionState.getTransform(),slack,reinterpret_cast<FloatBounds&>(box));
            FloatBounds expandedBox;
            SweepSingle(object->m_pMotionState.GetMotionState(),slack,box,expandedBox);
            BoundsRecord* output=reinterpret_cast<BoundsRecord*>(&const_cast<EntityNode*>(collider)->bounds);
            ConvertAabb(box,context->quantization.low,context->quantization.high,context->quantization.scale,*output);
            BoundsRecord expanded;
            ConvertAabb(expandedBox,context->quantization.low,context->quantization.high,context->quantization.scale,expanded);
            CompressExpanded(expanded,*output);
        }
    }
}
