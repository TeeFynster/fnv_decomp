#pragma once

class BSTaskletData
{
public:
    BSTaskletData();
    virtual ~BSTaskletData();
    virtual bool StartTaskThread();
    virtual void Process();
    virtual void OnComplete();

    bool m_bTaskYielded;

    void TaskYield();
    void* DestroyIfFlagged(unsigned int flags);
};
