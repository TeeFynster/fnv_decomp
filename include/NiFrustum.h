#pragma once

class NiFrustum
{
public:
    union { float left; float m_fLeftBound; };
    union { float right; float m_fRightBound; };
    union { float top; float m_fTopBound; };
    union { float bottom; float m_fBottomBound; };
    union { float nearPlane; float m_fNearPlane; };
    union { float farPlane; float m_fFarPlane; };
    union { bool ortho; bool m_bOrthographic; };
    unsigned char pad1;
    unsigned short pad2;

    // Call the ctor entries explicitly so other units retain POD default construction.
    void Init(bool orthographic); // exe 0x00a71b70
    void Init(float left, float right, float top, float bottom, float nearPlane, float farPlane, bool orthographic); // exe 0x00a71b80
    char* GetViewerString_00a71bc0(const char*);
};
