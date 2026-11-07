
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct LocalInt
{
    int value;
    LocalInt()
    {}
    LocalInt(int v) : value(v)
    {}
    __forceinline operator int() const
    {
        return value;
    }
};

struct __declspec(align(16)) Point4
{
    float x, y, z, w;
    float& at(int index)
    {
        return (&x)[index];
    }
    const float& at(int index) const
    {
        return (&x)[index];
    }
};
extern "C" void _ReadWriteBarrier(void);
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern int DAT_010eb4d4[];
extern int DAT_010eb73c[];
extern double DAT_0101e568;
extern double DAT_010217d0;

typedef void(__cdecl* S00e33a30_Fn)(float, int, float*, float*, int);
extern S00e33a30_Fn DAT_011be4d0[];

static __forceinline float readScalar(const u8*& stream)
{
    const float*& p = reinterpret_cast<const float*&>(stream);
    return *p++;
}
static __forceinline u8 readByte(const u8*& p)
{
    return *p++;
}
static __forceinline u16 readWord(const u8*& p)
{
    return *reinterpret_cast<const u16*&>(p)++;
}
static __forceinline float expandByte(float low, float high, u8 b)
{
    return (float)b / 255.0f * (high - low) + low;
}
static __forceinline float expandWord(float low, float high, u16 b)
{
    return (float)b / 65535.0f * (high - low) + low;
}

int FindKeyInterval(int, int, u8, const u8*);
// src: HAVOK_LIB 0x00e32f10
__declspec(noinline) int hkaSplineCompressedAnimation_readKnots(const u8*& cur, int* total, int* order, int tick, float scaleTime, float* times)
{
    int count = *reinterpret_cast<const u16*>(cur);
    cur += 2;
    int degree = *cur++;
    const u8* knots = cur;
    int span = FindKeyInterval(count, degree, (u8)tick, knots);
    for (int i = 0; i < 2 * degree; ++i)
        times[i] = (float)knots[span - degree + i + 1] * scaleTime;
    cur = knots + count + degree + 2;
    *total = count;
    *order = degree;
    return span;
}
int hkaSplineCompressedAnimation_readKnots(const u8*& cur, int* p28, int* p24, int a1, float f1, float* buf);
void BlendVector4(u8 flags, float* v, Point4* outp, int aux);

static __forceinline void fillPoint(u8 bits, const Point4& fixedValues, const Point4& defaultValues, Point4& result)
{
    int fixedBits = bits & 15;
    int defaultBits = ~bits & (~bits >> 4) & 15;
    int selectedBit = 1;
    for (int component = 0; component != 4; ++component)
    {
        if (fixedBits & selectedBit)
            result.at(component) = fixedValues.at(component);
        else if (defaultBits & selectedBit)
            result.at(component) = defaultValues.at(component);
        selectedBit *= 2;
    }
}

// @fnv 0x00e33a30
// src: HAVOK_LIB 0x00e33a30
void __cdecl hkaSplineCompressedAnimation_readNURBSCurve(const u8*& cur, int aiTick, float afScaleTime, float f2, u32 flags, int idx, Point4* outp,
                          int aux)
{
    int stride;
    LocalInt scale;
    (void)stride;
    (void)scale;
    Point4 hi;
    Point4 lo;
    Point4 val;
    float buf[6];
    Point4 ob[4];
    int iDegree = 0;
    int iCount = 0;
    int iSpan;

    u8 fb = (u8)flags;
    if ((u8)(fb & 0xf0) != 0)
    {
        iSpan = hkaSplineCompressedAnimation_readKnots(cur, &iCount, &iDegree, aiTick, afScaleTime, buf);
    }
    else
    {
        iDegree = 0;
        iCount = 0;
        iSpan = 0;
    }
    cur = (const u8*)(((u32)cur + 3) & ~3u);

    for (int lane = 0; lane < 3; ++lane)
    {
        if (fb & (1 << lane))
            val.at(lane) = readScalar(cur);
        else if (fb & (0x10 << lane))
        {
            lo.at(lane) = readScalar(cur);
            hi.at(lane) = readScalar(cur);
        }
    }

    if ((u8)(fb & 0xf0) == 0)
    {
        BlendVector4(fb, &val.x, outp, aux);
        return;
    }

    stride = DAT_010eb4d4[idx];
    cur = (const u8*)(((u32)cur + 1) & ~1u);
    scale = DAT_010eb73c[((u32)fb >> 4) & 7];
    const u8* pSample = (const u8*)(cur + (iSpan - iDegree) * stride * scale);

    if (iDegree >= 0)
    {
        for (int j = 0; j <= iDegree; ++j)
        {

            for (int lane = 0; lane < 3; ++lane)
            {
                if (fb & (0x10 << lane))
                {
                    if (idx == 0)
                        ob[j].at(lane) = expandByte(lo.at(lane), hi.at(lane), readByte(pSample));
                    else
                        ob[j].at(lane) = expandWord(lo.at(lane), hi.at(lane), readWord(pSample));
                }
            }
            fillPoint(fb, val, *outp, ob[j]);
        }
    }
    DAT_011be4d0[iDegree](f2, iDegree, buf, &ob[0].x, aux);
    cur += (iCount + 1) * stride * scale;
}
