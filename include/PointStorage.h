#pragma once
// Twelve bytes of point storage with no constructor. NiPoint3 declares a default constructor, so a NiPoint3 local calls
// it in /Od code, and a NiPoint3 temporary, return value or array changes /O2 code. Where the original builds no point
// (a point filled through a hidden return pointer, copied in, written field by field, or a plain-data helper result),
// the storage is a PointStorage and is handed on as the NiPoint3 it holds.
struct PointStorage
{
    float x, y, z;
};
