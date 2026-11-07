#ifndef PATHSMOOTHERPOV_DECLS_H
#define PATHSMOOTHERPOV_DECLS_H

#include "../../../include/NiPoint3.h"
#include "../../../include/NavMeshPOVSearch.h"

class SineCosine
{
  public:
    float fCos, fSin;
    SineCosine(float);
    SineCosine& operator=(const SineCosine&);
    SineCosine operator-(const SineCosine&) const;
    NiPoint3 MakePointOnCircle(float) const;
    float AngleSinCos_GetAngle() const;
};

class CircularArc
{
  public:
    SineCosine Start, End;
    ANGLE_DIRECTION Direction;
    CircularArc(const SineCosine&, const SineCosine&, ANGLE_DIRECTION);
    CircularArc(const CircularArc&);
    float FUN_006a07a0(float) const;
    bool AngleSinCosArc_WithinRange(const SineCosine&) const;
};

class Sphere
{
  public:
    NiPoint3 Center;
    float Radius;
    Sphere(const NiPoint3&, float);
};

#endif
