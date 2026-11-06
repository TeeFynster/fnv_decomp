#pragma once

enum BSDiscBootSystemUtility__NOTIFICATION_TYPE;

class BSDiscBootSystemUtility
{
public:
    virtual void* vf00(unsigned int flags);
    virtual void Initialize(const char* titleID, unsigned int parentalLevel);
    virtual void Destroy();

    char m_acTitleID[64];
    unsigned int m_uiParentalLevel;
    bool m_bNotificationActive;
    unsigned char layoutPadding49[3];
    void (__cdecl* m_pNotificationCallback)(BSDiscBootSystemUtility__NOTIFICATION_TYPE);
};
