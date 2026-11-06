#pragma once

class NiProperty;
class Property;

class NiPropertyState
{
public:
    NiProperty* m_aspProps[7];

    NiPropertyState() throw();
    NiPropertyState& operator=(const NiPropertyState& other);
    static void* operator new(unsigned int amount);
    void SetSlot(Property* property);
    void ReleaseAllRefs();
};
