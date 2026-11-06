#pragma once

class hkpPhantom;

class hkpPhantomListener
{
public:
    virtual ~hkpPhantomListener();
    virtual void PhantomAddedCallback(hkpPhantom*);
    virtual void PhantomRemovedCallback(hkpPhantom*);
    virtual void phantomShapeSetCallback(hkpPhantom*);
    virtual void phantomDeletedCallback(hkpPhantom*);
};
