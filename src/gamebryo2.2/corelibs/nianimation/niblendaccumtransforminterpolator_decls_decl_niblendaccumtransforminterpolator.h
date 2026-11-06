#pragma once

struct AccumRotationMatrix
{
    float m[9];
};

struct AccumItem
{
    float time;
    NiQuatTransform value, accum;
    AccumRotationMatrix rotation;
};

class NiBlendInterpolator__InterpArrayItem
{
  public:
    NiInterpolator* interpolator;
    float weight;
    float normalizedWeight;
    char priority;
    char pad0d[3];
    float easeSpinner;
    float updateTime;
};
