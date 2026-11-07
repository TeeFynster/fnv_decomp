#pragma once

#include "NiTask.h"

class NiParticleSystem;

class NiPSysUpdateTask : public NiTask
{
public:
    NiPSysUpdateTask();
    virtual ~NiPSysUpdateTask();
    virtual const NiRTTI* GetRTTI() const;
    virtual void vf35();
    virtual bool vf37();

    void AssignRefAndValue(NiParticleSystem* pkObject, float fNew);
    void ReleaseSysAndDispatch();
    void Destroy();
    bool Clear_00c25be0();
    void Release();
    void Destruct();
    void* DestroyElements(unsigned int uiFlags);

    static void* operator new[](unsigned int size, unsigned int count);
    static void operator delete[](void* p);

    union
    {
        NiParticleSystem* m_pkParticleSystem;
        NiParticleSystem* m_ptr;
        NiParticleSystem* sys;
    };
    union
    {
        float m_fUpdateTime;
        float m_f;
        float tm;
    };
};
