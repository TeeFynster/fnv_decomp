#pragma once

#include <stddef.h>
#include "hkBool.h"
#include "hkVector4.h"

class hkQuaternion;

class __declspec(align(16)) hkRotation
{
public:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;

    hkRotation();
    hkRotation(const hkRotation& other);
    void operator=(const hkRotation& other);
    __forceinline const hkVector4& getColumn(int i) const;
    void setIdentity();
    void Orthonormalize() throw();
    void set(const hkQuaternion& q);
    void set(const hkVector4* axis, float angle);
    hkBool IsOrthonormal(float epsilon) const;
    char* IsOrthonormal(char* result, float tolerance); // exe: 0x00cb2e70, explicit result form
    hkBool isOk() const;
    hkBool IsEqualWithinTolerance(const hkRotation& other, float epsilon) const;

    void hkRotation_set(const hkQuaternion& q);
    void FUN_00cb2e30(const hkVector4* axis, float angle);

    static void* __cdecl operator new(size_t nbytes);
};

typedef char hkRotation_size_check[(sizeof(hkRotation) == 48) ? 1 : -1];
typedef char hkRotation_column0_offset_check[(offsetof(hkRotation, m_kColumn0) == 0) ? 1 : -1];
typedef char hkRotation_column1_offset_check[(offsetof(hkRotation, m_kColumn1) == 16) ? 1 : -1];
typedef char hkRotation_column2_offset_check[(offsetof(hkRotation, m_kColumn2) == 32) ? 1 : -1];
