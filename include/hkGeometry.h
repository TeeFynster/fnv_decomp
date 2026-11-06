#pragma once

#include <stddef.h>
#include "hkaAnimation.h"
#include "hkVector4.h"

class hkGeometry
{
public:
    struct Triangle
    {
        int m_kPointA;
        int m_kPointB;
        int m_iThirdValue;
        int m_iMaterialIndex;

        void set(int a, int b, int c, int material = -1);
    };

    hkArray<hkVector4> m_kVertices;
    hkArray<Triangle> m_uiTriangleCount;

    hkGeometry();
    ~hkGeometry();

    static void* operator new(size_t size) throw();
};
