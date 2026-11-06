#pragma once

class TESObjectCELL;

class TESQueuedCellManager
{
public:
    void FUN_00528540();
    void SubmitQueuedItems();
    void FUN_005283c0(TESObjectCELL*);
    int CallVirtual17();
    void ProcessQueries();
    int FUN_005281f0();
    void FUN_005282d0();
};
