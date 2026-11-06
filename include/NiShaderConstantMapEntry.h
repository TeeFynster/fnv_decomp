#pragma once

#include "NiRefObject.h"
#include "NiFixedString.h"

struct ScriptAttributeTypes
{
    enum AttributeType
    {
        ATTRIB_TYPE_BOOL = 1,
        ATTRIB_TYPE_INT = 3
    };
};

class NiShaderConstantMapEntry : public NiRefObject
{
public:
    NiShaderConstantMapEntry() throw();
    virtual ~NiShaderConstantMapEntry();
    __declspec(noalias) __declspec(nothrow) virtual void DeleteThis() throw();

    void IncRefCount();
    void DecRefCount();
    ScriptAttributeTypes::AttributeType GetAttributeType() const;

    unsigned int unk08;
    NiFixedString m_kControlPoint;
    unsigned int unk10;
    unsigned int m_uiValue1;
    unsigned int m_uiValue2;
    unsigned int m_uiValue3;
    unsigned int m_uiValue4;
    NiFixedString m_kSecondaryString;
    unsigned int m_uiValue5;
    unsigned int m_uiValue6;
    void* m_pConstantData;
    bool m_bFlag0;
};
