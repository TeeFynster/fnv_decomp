#pragma once
#include <stddef.h>

class NiStream;
class TPoint3;

class NiPoint3
{
  public:
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        float components[3];
    };

    __forceinline NiPoint3()
    {}
    NiPoint3(float x, float y, float z);

    NiPoint3 operator+(const NiPoint3& point) const;
    NiPoint3 operator-(const NiPoint3& point) const;
    NiPoint3 operator-(const TPoint3& point) const;
    NiPoint3 operator-(float scalar) const;
    NiPoint3 operator-() const;
    NiPoint3 operator*(float scalar) const;
    NiPoint3 operator*(double scalar) const;
    float operator*(const NiPoint3& point) const;
    NiPoint3 operator/(float scalar) const;
    NiPoint3& operator+=(const NiPoint3& point)
    {
        x += point.x;
        y += point.y;
        z += point.z;
        return *this;
    }
    NiPoint3& operator-=(const NiPoint3& point);
    NiPoint3& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }
    bool operator==(const NiPoint3& point);
    bool operator==(const NiPoint3& point) const;
    bool operator!=(const NiPoint3& point);
    bool operator!=(const NiPoint3& point) const;
    float& operator[](int index);
    float& operator[](unsigned int index);
    const float& operator[](int index) const;
    friend NiPoint3 operator*(float scalar, const NiPoint3& point);

    float X() const;
    float Y() const;
    float Z() const;
    float Xvalue() const;
    const float& Xref() const;
    const float& Zref() const;
    float Get(unsigned int index) const;
    float GetY() const;
    const NiPoint3& Value() const;
    float Readx() const;
    float Ready() const;
    void Set(float x, float y, float z);

    float Dot(const NiPoint3& point) const
    {
        return x * point.x + y * point.y + z * point.z;
    }
    float Dot(void* point);
    float DotProduct(const NiPoint3& point);
    float DotProduct(const NiPoint3& point) const;
    float DotProduct(NiPoint3* point);
    NiPoint3 Cross(const NiPoint3& point) const;
    NiPoint3 Cross(void* point);
    NiPoint3 CrossProduct(const NiPoint3& point) const;
    NiPoint3 CrossProduct(void* point);
    NiPoint3 Perpendicular();
    float Length();
    float Length() const;
    float SqrLength();
    float SqrLength() const;
    float XYLength();
    float SqrXYLength();
    float GetLengthSquared();
    float GetSquaredXYLength() const;
    float GetLen() const;
    float Magnitude() const;
    void ComputeMagnitude();
    float ComputeMagnitude() const;
    void Unitize();
    __declspec(noalias) void Unitize_004a0c10();
    float NiPoint3_XYLength() const;
    bool HasEqualComponents(const NiPoint3& point);
    NiPoint3& ScaleComponents(float scalar);
    NiPoint3 FUN_00439e90(const NiPoint3& point);
    NiPoint3 FUN_00439e90(const NiPoint3& point) const;
    NiPoint3 SubtractIntoVector(const NiPoint3& point);
    NiPoint3 SubtractIntoVector(const NiPoint3& point) const;
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    NiPoint3 GetNegatedVector();
    NiPoint3 GetNegatedVector() const;
    NiPoint3* GetNegatedVector(NiPoint3* out);
    void FUN_004a0c90(float scalar);
    float FUN_004a7290() const;
    NiPoint3 FUN_004b3800(const NiPoint3& point) const;
    NiPoint3* FUN_004b4500(void* context, NiPoint3* a, NiPoint3* b);
    NiPoint3 FUN_0053d1a0(const NiPoint3& point);
    NiPoint3 FUN_0053d1a0(const NiPoint3& point) const;
    NiPoint3 ProcessAndReturnValue_0053d280(float scalar) const;
    void FUN_005df510(unsigned int value, NiPoint3* point);
    NiPoint3* ComputeValue_0063c8a0(const NiPoint3& point);
    void FUN_006815c0();
    void SubtractIntoVector();
    float FUN_00435e00();
    void SetQuaternionComponentsFromVector(const float* values);
    // Call targets of the former Vec3 stand-in.
    NiPoint3& AddTo(const NiPoint3& other);
    NiPoint3 AddVector(const NiPoint3& other);
    NiPoint3 AddVector(const NiPoint3& other) const;
    float DotProduct(const NiPoint3* other) const;
    bool FUN_00439090(const NiPoint3* other);
    bool HasEqualComponents(const NiPoint3* other);
    bool HasEqualComponents(const NiPoint3* other) const;
    bool HasEqualComponents(const char* other);
    NiPoint3 SubtractIntoVector(NiPoint3* other);
    void SubtractIntoVector(NiPoint3* output, const NiPoint3* other);
    NiPoint3 SubtractIntoVector(const NiPoint3* other);
    NiPoint3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    void ComputeValue_0063c8a0(const NiPoint3* other);
    void ComputeValue_0063c8a0(void* other);
    float LengthSquared() const;
    NiPoint3 Neg() const;
    void Normalize();
    NiPoint3 Scale(float scale) const;
    NiPoint3 ScaleSwizzled(float scale);
    NiPoint3 ScaleSwizzled(float scale) const;
    NiPoint3* Self();
    NiPoint3& operator/=(float scale);
    float AStarSearch_EvaluateValue_006a7f50();
    float GetX();
    NiPoint3* SubtractIntoVector(NiPoint3* out, NiPoint3* other);
    bool FUN_00439090(NiPoint3* other);
    bool FUN_00439090(const NiPoint3& point) const;
    NiPoint3* SubtractIntoVector(NiPoint3* output, const NiPoint3& point) const;
    float DotAccumulated(const NiPoint3& other) const;
    float DotPlane(const NiPoint3& other) const;
    float Len() const;
    float Length2() const;
    void SubtractIntoVector(NiPoint3* dest, void* context);
    float DotPart(float value, const NiPoint3& point) const;
    NiPoint3* SetComponents(float x, float y, float z);
    NiPoint3* FUN_00439e90(NiPoint3* output, const NiPoint3* other) const;
    void FUN_0043d410(float x, int y, int z);
    char* GetViewerString_00a59af0(const char* prefix);
    NiPoint3& AddComponents(const NiPoint3& point);

    NiPoint3 Add(const NiPoint3& point) const;
    NiPoint3 Added(const NiPoint3& point) const;
    NiPoint3 Sum(const NiPoint3& point) const;
    NiPoint3 Sub(const NiPoint3& point) const;
    void Sub(const NiPoint3& a, const NiPoint3& b);
    NiPoint3& Subtract(const NiPoint3& point);
    NiPoint3 ApplyScaled(float scalar) const;
    NiPoint3 Divide(float scalar) const;
    void DivideBy(float scalar);
    void ScaleByInverse(float scalar);
    NiPoint3* ScaleTo(NiPoint3* output, float scalar);
    NiPoint3 InlineCross(const NiPoint3& point) const;
    void Accumulate(NiPoint3 point);
    void AddByValue(NiPoint3 point);
    void AddBinormal(const NiPoint3& point);
    void AddZTo(float& output) const;
    void AssignOutput(const NiPoint3& point);
    float UpdateCombatStyle();

    void LoadBinary(NiStream* stream);
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream* stream);
    char* FormatToBuffer(char* buffer);
    char* FormatToBuffer(const char* prefix) const;

    static const NiPoint3 ZERO;
    static const NiPoint3 UNIT_X;
    static const NiPoint3 UNIT_Y;
    static const NiPoint3 UNIT_Z;
    static NiPoint3 ComponentProduct(void* a, void* b);
    static void LoadBinary(NiStream* stream, NiPoint3* points, unsigned int count);
    static void SaveBinary(NiStream* stream, NiPoint3* points, unsigned int count);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3* points, unsigned int count, unsigned int stride);
    static void NormalizePoints(NiPoint3* points, unsigned int count, unsigned int stride);
    static void ComputeMagnitude(NiPoint3* point);
    static float VectorLength(void* point);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3* points, float scalar, void* other, unsigned int count);
    static void WeightedPointsPlusWeightedPoints(NiPoint3* points, float scalar, void* other, unsigned int count);
    static unsigned int* InitSqrtTable();
    static void __cdecl NiPoint3_UnitizeVector(NiPoint3& point);
};

typedef char NiPoint3_size_check[(sizeof(NiPoint3) == 12) ? 1 : -1];
typedef char NiPoint3_x_offset_check[(offsetof(NiPoint3, x) == 0) ? 1 : -1];
typedef char NiPoint3_y_offset_check[(offsetof(NiPoint3, y) == 4) ? 1 : -1];
typedef char NiPoint3_z_offset_check[(offsetof(NiPoint3, z) == 8) ? 1 : -1];
