#pragma once

#include "BSSaveDataSystemUtility__SaveDataEntry.h"

class BSSaveDataOperationEntry;

class BSSaveDataSystemUtility
{
public:
    enum OPERATION
    {
        OPERATION_NONE = 0,
        OPERATION_SAVE = 1,
        OPERATION_LOAD = 2,
        OPERATION_DELETE = 3,
        OPERATION_AUTOSAVE = 4,
        OPERATION_AUTOLOAD = 5,
    };

    enum RESULT
    {
        RESULT_SUCCESS = 0,
        RESULT_CANCEL = 1,
        RESULT_FAILED = 2,
    };

    enum RESULT_FAILED_REASON
    {
        RESULT_FAILED_REASON_NO_DATA = 0,
        RESULT_FAILED_REASON_INSUFFICIENT_SPACE = 1,
        RESULT_FAILED_REASON_DATA_CORRUPT = 2,
        RESULT_FAILED_REASON_UNKNOWN = 3,
    };

    virtual void* vf00(unsigned int flags);
    virtual void vf04();
    virtual void Destroy();
    virtual unsigned int vf0C(const char*, int, int);  // 0x00aaa650: returns 0
    virtual bool vf10(const char*, void*);
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C(int);
    virtual void vf20();
    virtual void vf24();

    bool bIsActive;
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSSaveDataOperationEntry* m_pOperationContext;
    BSSaveDataSystemUtility__SaveDataEntry m_kSaveDataEntry;
    OPERATION m_eOperation;
    RESULT m_eResult;
    RESULT m_eSecondResult;
    RESULT m_eThirdResult;
    RESULT_FAILED_REASON m_eFailedReason;
    unsigned int m_uiResultCount;
    void (__cdecl* m_pResultCallback)(RESULT);

    void SetResultCallback(void (__cdecl* apCallback)(RESULT));  // 0x008d8040 (folded +0x44 setter)
};
