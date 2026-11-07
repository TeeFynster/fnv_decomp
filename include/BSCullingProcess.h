#pragma once

#include "NiCullingProcess.h"
#include "NiAccumulator.h"

class MenuTarget;
class NiVisibleArray;
class TaskArg1;

#ifndef FNV64_NIPTR_DEFINED
#define FNV64_NIPTR_DEFINED
template <class T> class NiPtr
{
public:
    T* m_pObject;

    NiPtr(T* object = 0);
    NiPtr(const NiPtr& other);
    ~NiPtr();

    NiPtr& operator=(T* object);
    NiPtr& operator=(const NiPtr& other);

    operator T*() const { return m_pObject; }
    T* operator->() const { return m_pObject; }
};
#endif

class BSCullingProcess : public NiCullingProcess
{
public:
    virtual void* GetRTTI();
    virtual void vfn_40();
    virtual void Process(NiAVObject* object);
    virtual void Slot18();
    virtual void Append(NiGeometry* geometry);

    BSCullingProcess(NiVisibleArray* pkVisibleSet = 0);
    BSCullingProcess(void* visibleSet);
    ~BSCullingProcess();

    void slot0();
    void Destroy();
    void* DeleteThis(unsigned int flags);
    void SetCamera(void* camera);
    void SetAccumulator(NiRefObject* accumulator);
    void SetAccumulator(MenuTarget* accumulator);
    void SetCullMode(unsigned int mode);
    void SetCompoundFrustum(TaskArg1* frustum);
    void FUN_004a0f60();
    void* FUN_004a0ff0(unsigned int flags);
    void AppendVirtual(NiGeometry& kVisible);

    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBc;
    int unkC0;
    NiPtr<NiAccumulator> m_acRendererDataA;
};
