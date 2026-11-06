#pragma once

#include <stddef.h>
#include "NiPoint3.h"

class NiStream;
struct _XMMATRIX;

// Gamebryo NiMatrix3 (NiMain). Methods as the Xbox debug PDB (Fallout_Release_Beta.pdb) lists them; the PC game stores
// the entries as float[3][3] (36 bytes: NiTransform::m_Rotate at +0x00, m_Translate at +0x24), where the Xbox build
// keeps three NiPoint4 rows (0x30). Out-of-line bodies the PC game has: NiMatrix3.cpp at 0x00a58550-0x00a59af0
// (src/gamebryo2.2/corelibs/nimain/console/nimatrix3.cpp); inline bodies are defined by the units whose originals
// inline or emit them (e.g. GetCol 0x00439f50, operator* 0x0043f8d0 and 0x004b4500, Inverse 0x004b46a0).
class NiMatrix3
{
public:
    __forceinline NiMatrix3() {}
    NiMatrix3(const NiPoint3& col0, const NiPoint3& col1, const NiPoint3& col2);

    void GetRow(unsigned int uiRow, float* pRow) const;
    void GetRow(unsigned int uiRow, float& f0, float& f1, float& f2) const;
    void GetRow(unsigned int uiRow, NiPoint3& row) const;
    void SetRow(unsigned int uiRow, const float* pRow);
    void SetRow(unsigned int uiRow, float f0, float f1, float f2);
    void SetRow(unsigned int uiRow, const NiPoint3& row);

    void GetCol(unsigned int uiCol, float* pCol) const;
    void GetCol(unsigned int uiCol, float& f0, float& f1, float& f2) const;
    void GetCol(unsigned int uiCol, NiPoint3& col) const;
    void SetCol(unsigned int uiCol, const float* pCol);
    void SetCol(unsigned int uiCol, float f0, float f1, float f2);
    void SetCol(unsigned int uiCol, const NiPoint3& col);

    float GetEntry(unsigned int uiRow, unsigned int uiCol) const;
    void SetEntry(unsigned int uiRow, unsigned int uiCol, float fEntry);

    void MakeZero();
    void MakeIdentity();
    void MakeDiagonal(float fDiag0, float fDiag1, float fDiag2);
    void MakeXRotation(float fAngle);
    void MakeYRotation(float fAngle);
    void MakeZRotation(float fAngle);
    void MakeZRotationQ(float fAngle);
    void MakeRotation(float fAngle, const NiPoint3& axis);
    void MakeRotation(float fAngle, float x, float y, float z);

    // products (the free function is the row-vector form pt * M)
    NiMatrix3 operator*(const NiMatrix3& kRhs) const;
    NiMatrix3 operator*(float fFactor) const;
    NiPoint3 operator*(const NiPoint3& kVec) const;
    friend NiPoint3 operator*(const NiPoint3& kVec, const NiMatrix3& kMat);
    NiMatrix3 TransposeTimes(const NiMatrix3& kRhs) const;
    NiMatrix3 Congruence(const NiMatrix3& kRhs) const;
    NiMatrix3 operator+(const NiMatrix3& kRhs) const;
    NiMatrix3 operator-(const NiMatrix3& kRhs) const;
    bool operator!=(const NiMatrix3& kRhs) const;
    bool operator==(const NiMatrix3& kRhs) const;

    NiMatrix3 Transpose() const;
    NiMatrix3 Inverse() const;
    bool Inverse(NiMatrix3& kResult) const;
    bool Reorthogonalize();

    // batch transforms over vertex/normal arrays (static helpers)
    static void TransformNormals(const NiMatrix3& kRot, unsigned int uiCount, const NiPoint3* pkSrc, NiPoint3* pkDst);
    static void TransformVertices(const NiMatrix3& kRot, const NiPoint3& kOffset, unsigned int uiCount,
        const NiPoint3* pkSrc, NiPoint3* pkDst);
    static void TransformVerticesAndNormals(const NiMatrix3& kRot, const NiPoint3& kOffset, unsigned int uiCount,
        const NiPoint3* pkSrcVerts, NiPoint3* pkDstVerts, const NiPoint3* pkSrcNorms, NiPoint3* pkDstNorms);

    // Euler angle conversions, one pair per axis order (the To* forms report whether the decomposition is unique)
    void FromEulerAnglesXYZ(float fA, float fB, float fC);
    bool ToEulerAnglesXYZ(float& fA, float& fB, float& fC) const;
    void FromEulerAnglesXZY(float fA, float fB, float fC);
    bool ToEulerAnglesXZY(float& fA, float& fB, float& fC) const;
    void FromEulerAnglesYXZ(float fA, float fB, float fC);
    bool ToEulerAnglesYXZ(float& fA, float& fB, float& fC) const;
    void FromEulerAnglesYZX(float fA, float fB, float fC);
    bool ToEulerAnglesYZX(float& fA, float& fB, float& fC) const;
    void FromEulerAnglesZXY(float fA, float fB, float fC);
    bool ToEulerAnglesZXY(float& fA, float& fB, float& fC) const;
    void FromEulerAnglesZYX(float fA, float fB, float fC);
    bool ToEulerAnglesZYX(float& fA, float& fB, float& fC) const;
    void ExtractAngleAndAxis(float& fRadians, float& fAxisX, float& fAxisY, float& fAxisZ) const;

    void EigenSolveSymmetric(float* pfValues, NiPoint3* pkVectors);
    static const NiMatrix3 ZERO;
    static const NiMatrix3 IDENTITY;

    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream);
    char* GetViewerString(const char* pPrefix) const;

    void Scale(float fX, float fY, float fZ);
    static _XMMATRIX XMLoadFloat3x4(const float* pSource);
    static void XMStoreFloat3x4(float* pDest, _XMMATRIX matrix);

    float m_pEntry[3][3];

    bool Tridiagonal(float* afDiag, float* afSubDiag);
    bool QLAlgorithm(float* afDiag, float* afSubDiag);
    float Determinant();
};

typedef char NiMatrix3_size_check[(sizeof(NiMatrix3) == 36) ? 1 : -1];
typedef char NiMatrix3_m_pEntry_offset_check[(offsetof(NiMatrix3, m_pEntry) == 0) ? 1 : -1];
