#pragma once

#include <stddef.h>

class Color;
class Geometry;
class Matrix;
class NiPoint3;
class NiPoint3;
class RenderPoint3;
class NiPoint3;

class Bound
{
public:
    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float radius;
        };
        float coordinates[4];
    };

    Bound();
    __forceinline float Radius()
    {
        return radius;
    }
    float Radius() const;
    float TESBoundObject_GetBoundSize();
    float FUN_0084d030();
    NiPoint3& FUN_006815c0();
    void BSMultiBound_SetHalfExtents(const NiPoint3&);
    void BSMultiBoundAABB_SetAxis(const Matrix&);
    void BSMultiBoundAABB_GetVertices(NiPoint3* out);
    void BSMultiBoundAABB_MakeDebugGeom(Geometry*, Geometry*, Color);
    void Recalculate(unsigned short, RenderPoint3*);
    void ComputeBoundingSphere(unsigned short, NiPoint3*);
    void Calculate(unsigned short, void*);
};

typedef char Bound_size_check[(sizeof(Bound) == 16) ? 1 : -1];
typedef char Bound_x_offset_check[(offsetof(Bound, x) == 0x00) ? 1 : -1];
typedef char Bound_y_offset_check[(offsetof(Bound, y) == 0x04) ? 1 : -1];
typedef char Bound_z_offset_check[(offsetof(Bound, z) == 0x08) ? 1 : -1];
typedef char Bound_radius_offset_check[(offsetof(Bound, radius) == 0x0C) ? 1 : -1];
typedef char Bound_coordinates_offset_check[(offsetof(Bound, coordinates) == 0x00) ? 1 : -1];
