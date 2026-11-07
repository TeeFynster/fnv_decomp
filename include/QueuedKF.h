#pragma once

#include "QueuedFileEntry.h"

class KFModel;

class QueuedKF : public QueuedFileEntry
{
public:
    QueuedKF(const char* apFileName, int aePriority);
    QueuedKF(KFModel* apKF, int aePriority);
    virtual ~QueuedKF();
    virtual void Run() override;
    virtual void Finish() override;
    virtual bool GetDescription(char* description, unsigned int bufferSize) override;
    virtual void DispatchToManager() override;

    void QueuedKF_Run();
    void QueuedKF_Finish();
    void QueuedKF_SetAlreadyInKFMap(bool abValue);
};
