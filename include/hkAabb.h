#pragma once

#include <stddef.h>
#include "hkBool.h"
#include "hkVector4.h"
class NiPoint3;

typedef size_t hk_size_t;

class hkAabb
{
public:
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;

    hkAabb();
    hkAabb(const hkAabb& a) throw();
    hkBool contains(const hkAabb& other) const;
    hkBool ValidateBounds() const throw();
    void includePoint(const hkVector4& p);

    static void* __cdecl operator new(hk_size_t nbytes);
    // Exe aabb helpers formerly declared on Bounds; min/max are still at +0/+0x10.
    void assign(const hkAabb&) throw();
    void copy(const hkAabb&) throw();
    void center(NiPoint3&) const;
    void empty();
    void include(const NiPoint3&);
    float MapX(float) const;
    float MapY(float) const;
    void Init(unsigned int, unsigned int);
};

typedef char hkAabb_size_check[(sizeof(hkAabb) == 32) ? 1 : -1];
typedef char hkAabb_minimum_corner_offset_check[(offsetof(hkAabb, m_kMinimumCorner) == 0) ? 1 : -1];
typedef char hkAabb_maximum_corner_offset_check[(offsetof(hkAabb, m_kMaximumCorner) == 16) ? 1 : -1];
