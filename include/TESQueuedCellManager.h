#pragma once

class TESObjectCELL;

class TESQueuedCellManager
{
public:
    void ExteriorCellLoader_CancelAllCellLoads();
    void SubmitQueuedItems();
    void ExteriorCellLoader_QueueCellLoad(TESObjectCELL*);
    int CallVirtual17();
    void ProcessQueries();
    int ExteriorCellLoader_TryCancelTasks();
    void ExteriorCellLoader_WaitForTasks();
};
