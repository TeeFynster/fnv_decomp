#pragma once

class hkpEntity;

class hkpEntityListener
{
public:
    // Inline in Havok 7.1 (hkpEntityListener.h: `virtual ~hkpEntityListener() {}`): /O2 derived
    // destructors only restore the vfptr to 0x0102f13c (e.g. 0x00e46900); /Od code calls the
    // out-of-line COMDAT copy at 0x00554650.
    virtual ~hkpEntityListener() {}
    virtual void EntityAddedCallback(hkpEntity*);
    virtual void EntityRemovedCallback(hkpEntity*);
    virtual void EntityShapeSetCallback(hkpEntity*);
    virtual void entitySetMotionTypeCallback(hkpEntity*);
    virtual void EntityDeletionCallback(hkpEntity*);

    void NotifyEntityIfFlagged(hkpEntity*);
};
