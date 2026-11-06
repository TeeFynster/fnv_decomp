#pragma once

#include "hkReferencedObject.h"
#include "hkSingleton.h"

class hkBool;

class hkError : public hkReferencedObject, public hkSingleton<hkError>
{
public:
    enum Message
    {
        MESSAGE_REPORT,
        MESSAGE_WARNING,
        MESSAGE_ASSERT,
        MESSAGE_ERROR
    };

    virtual ~hkError() throw();
    virtual int message(int iType, int iId, const char* sDescription, const char* sFile, int iLine);
    virtual void setEnabled(int iId, hkBool bEnabled);   // Havok 7.1 hkError.h order: slot 0x10
    virtual hkBool isEnabled(int iId);                  // slot 0x14
    virtual void enableAll();                          // slot 0x18
    virtual void beginSection(int iId, const char* sName);
    virtual void endSection();


    static hkError* s_instance;
};
