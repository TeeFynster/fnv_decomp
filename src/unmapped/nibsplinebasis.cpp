
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4034;
// @fnv 0x00a52500
// src: COMMUNITY 0x00a52500
GlobalObjectO2_00a7b610* NiBSplineData_GetRTTI()
{
    return &g_011f4034;
}

struct CubicSplineBasis
{
    int count;
    float weight0, weight1, weight2, weight3;
    float lastTime;
    int first, last;
    void ComputeBasisWeights(float time, int& start, int& end);
};
// Caches the span for a time value and computes the four cubic spline basis weights, handling counts from 4 to 7 and above.
// @fnv 0x00a51e80
void CubicSplineBasis::ComputeBasisWeights(float time, int& start, int& end)
{
    if (*reinterpret_cast<unsigned int*>(&time) == *reinterpret_cast<unsigned int*>(&lastTime))
    {
        start = first;
        end = last;
        return;
    }
    *reinterpret_cast<unsigned int*>(&lastTime) = *reinterpret_cast<unsigned int*>(&time);
    int iSpanCount = count - 3;
    int span = time < 1.0f ? int(time * iSpanCount) + 3 : count - 1;
    first = start = span - 3;
    last = end = span;
    time *= iSpanCount;
    const float third = 1.0f / 3.0f;
    if (count >= 7)
    {
        int n1 = iSpanCount + 1;
        int n2 = n1 + 1;
        float a = span > 5 ? float(span - 5) : 0.0f;
        float b = span > 4 ? float(span - 4) : 0.0f;
        float c = float(span - 3);
        float d = float(span - 2);
        float e = span < n1 ? float(span - 1) : float(iSpanCount);
        float f = span < iSpanCount ? float(span) : float(iSpanCount);
        float invDB = span == 3 ? 1.0f : 0.5f;
        float invEC = span == n2 ? 1.0f : 0.5f;
        float invDA = span == 3 ? 1.0f : span == 4 ? 0.5f : third;
        float invEB = span == 3 || span == n2 ? 0.5f : third;
        float invFC = span == n2 ? 1.0f : span == n1 ? 0.5f : third;
        float tb = time - b;
        float tc = time - c;
        float dt = d - time;
        float et = e - time;
        float lower = dt * invDB;
        float upper = tc * invEC;
        float left = dt * invDA * lower;
        float middle = (lower * tb + upper * et) * invEB;
        float right = upper * (tc * invFC);
        weight0 = dt * left;
        float ta = time - a;
        weight1 = et * middle + left * ta;
        float ft = f - time;
        weight2 = middle * tb + ft * right;
        weight3 = tc * right;
    }
    else if (count == 6)
    {
        if (span == 3)
        {
            float dt = 1.0f - time;
            float et = 2.0f - time;
            float upper = time * 0.5f;
            float left = dt * dt;
            float middle = 0.5f * (upper * et + dt * time);
            float right = upper * (time * third);
            weight0 = dt * left;
            weight1 = left * time + et * middle;
            float ft = 3.0f - time;
            weight2 = middle * time + ft * right;
            weight3 = time * right;
        }
        else if (span == 4)
        {
            float tc = time - 1.0f;
            float et = 3.0f - time;
            float halfTime = time * 0.5f;
            float lower = 1.0f - halfTime;
            float upper = 0.5f * tc;
            float left = lower * lower;
            float middle = (lower * time + upper * et) * third;
            float right = upper * upper;
            float dt = 2.0f - time;
            weight0 = dt * left;
            weight1 = left * time + middle * et;
            weight2 = time * middle + et * right;
            weight3 = right * tc;
        }
        else
        {
            float tb = time - 1.0f;
            float tc = time - 2.0f;
            float dt = 3.0f - time;
            float lower = dt * 0.5f;
            float right = tc * tc;
            float left = (dt * third) * lower;
            float middle = 0.5f * (lower * tb + dt * tc);
            weight0 = left * dt;
            weight1 = time * left + middle * dt;
            weight2 = tb * middle + dt * right;
            weight3 = right * tc;
        }
    }
    else if (count == 5)
    {
        if (span == 3)
        {
            float dt = 1.0f - time;
            float et = 2.0f - time;
            float upper = time * 0.5f;
            float left = dt * dt;
            float middle = 0.5f * (upper * et + dt * time);
            float right = upper * upper;
            weight0 = dt * left;
            weight1 = left * time + middle * et;
            weight2 = middle * time + et * right;
            weight3 = time * right;
        }
        else
        {
            float tc = time - 1.0f;
            float dt = 2.0f - time;
            float halfTime = time * 0.5f;
            float right = tc * tc;
            float lower = 1.0f - halfTime;
            float left = lower * lower;
            float middle = (halfTime + tc) * lower;
            weight0 = left * dt;
            weight1 = left * time + middle * dt;
            weight2 = time * middle + dt * right;
            weight3 = right * tc;
        }
    }
    else if (count == 4)
    {
        float lower = 1.0f - time;
        float right = time * time;
        float left = lower * lower;
        weight0 = left * lower;
        weight1 = left * (time * 3.0f);
        weight2 = lower * (3.0f * right);
        weight3 = time * right;
    }
}
