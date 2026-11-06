#pragma once

typedef unsigned short hkUint16;
typedef unsigned char hkUint8;

class hkpEntitySpuCollisionCallback
{
public:
    void* m_pCallbackData;
    hkUint16 m_pRayCursor;
    hkUint8 m_uiCallbackType;
    hkUint8 m_bCallbackEnabled;
};
