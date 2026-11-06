#pragma once

class NiRTTI
{
public:
    NiRTTI(const char* pcName, const NiRTTI* pkBaseRTTI);

    const char* GetName() const;
    const NiRTTI* GetBaseRTTI() const;
    char* GetName();
    void* GetBaseRTTI();
    bool IsExactly(const NiRTTI* type) const;

    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};
