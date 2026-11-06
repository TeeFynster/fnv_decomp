#pragma once

#include "bhkCollisionObject.h"

class bhkBlendCollisionObject : public bhkCollisionObject
{
  public:
    bhkBlendCollisionObject();

    static NiObject* __cdecl CreateObject();

    unsigned char unk0C[8];
    unsigned char m_flag14;
    char m_pad15[3];
    float m_f18;
    float m_f1c;
    int m_i20;
    int m_i24;
    int m_i28;
};
