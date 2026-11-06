#pragma once

class hkpConstraintInstance;

class hkpConstraintListener
{
public:
    virtual ~hkpConstraintListener();
    virtual void ConstraintAddedCallback(hkpConstraintInstance* constraint);
    virtual void ConstraintRemovedCallback(hkpConstraintInstance* constraint);
    virtual void c0c();
    virtual void c10();
    virtual void c14();
    virtual void c18();
};
