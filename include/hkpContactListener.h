#pragma once

// Havok 7.1 hkpContactListener: the destructor is the fourth virtual slot (RTTI vftable 0x0104dd7c,
// slot 3 = 0x00623510, its deleting destructor; 0x006234f0 is the destructor).
class hkpContactListener
{
public:
    virtual void contact0();
    virtual void contact1();
    virtual void contact2();
    virtual ~hkpContactListener();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
};
