#pragma once

#include "NiTimeController.h"

class BSPlayerDistanceCheckController : public NiTimeController
{
public:
    virtual ~BSPlayerDistanceCheckController();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void Update(NiUpdateData& update);
    virtual void Unk_2C();

    void* __thiscall ScalarDeletingDestructor(unsigned int flags);
    const NiRTTI* const* GetNiRTTI();
    double NiControllerSequence_GetLastTime();
    int GetField38();
    void UpdateDoorSpawn(unsigned int unkArg);
    void TargetIsRequiredType();

    unsigned int unk34;
    void (__cdecl* m_callback)(void*);
};
