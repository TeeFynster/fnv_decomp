#pragma once

class hkClass;
class hkReferencedObject;

class hkRefVariant
{
public:
    hkReferencedObject* m_pRetainedObject;

    hkRefVariant() : m_pRetainedObject(0) {}
    hkRefVariant(const hkRefVariant& kOther) throw();
    ~hkRefVariant() throw();

    void FUN_00d47770(const void* object, const hkClass* pClassInfo);
    const hkClass* FUN_00d477a0() const;
};
