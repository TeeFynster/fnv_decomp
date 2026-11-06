#pragma once

#include <stddef.h>

enum BS_TASK_STATE
{
    BS_TASK_STATE_PENDING = 0,
    BS_TASK_STATE_QUEUED = 1,
    BS_TASK_STATE_MOVING = 2,
    BS_TASK_STATE_RUNNING = 3,
    BS_TASK_STATE_FINISHED = 4,
    BS_TASK_STATE_COMPLETED = 5,
    BS_TASK_STATE_CANCELED = 6
};

#pragma pack(push, 4)
template <class T>
class BSTask
{
public:
    union
    {
        unsigned char taskStorage[0x14];
        struct
        {
            unsigned int unk04;
            volatile int BackgroundTask;
            BS_TASK_STATE eState;
            T Key;
        };
    };

    BSTask();
    virtual ~BSTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    void Cancel();
};
#pragma pack(pop)

typedef char BSTask_size[(sizeof(BSTask<__int64>) == 24) ? 1 : -1];
typedef char BSTask_storage_offset[(offsetof(BSTask<__int64>, taskStorage) == 4) ? 1 : -1];
typedef char BSTask_refcount_offset[(offsetof(BSTask<__int64>, BackgroundTask) == 8) ? 1 : -1];
typedef char BSTask_state_offset[(offsetof(BSTask<__int64>, eState) == 12) ? 1 : -1];
typedef char BSTask_key_offset[(offsetof(BSTask<__int64>, Key) == 16) ? 1 : -1];
