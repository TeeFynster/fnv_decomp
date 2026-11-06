// gamebryo2.2/corelibs/nimain/nipropertystate.cpp: free functions (1 function)

#include "../../../../include/NiPropertyState.h"
#include "NiProperty.h"
#include "NiObjectNET_inline.h"

// Copies the seven property pointers from other, releasing the old references and adding references to the new ones.
// @fnv 0x00a89900
NiPropertyState& NiPropertyState::operator=(const NiPropertyState& other)
{
    for (unsigned int i = 0; i < 7; ++i)
    {
        if (m_aspProps[i] != other.m_aspProps[i])
        {
            if (m_aspProps[i])
                m_aspProps[i]->DecRefCount();
            m_aspProps[i] = other.m_aspProps[i];
            if (m_aspProps[i])
                m_aspProps[i]->IncRefCount();
        }
    }
    return *this;
}
