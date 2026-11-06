#pragma once

class BaseFormComponent
{
public:
    BaseFormComponent();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};
