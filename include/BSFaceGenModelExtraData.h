#pragma once
#include "NiPointer.h"

#include "NiExtraData.h"

class BSFaceGenModel;

class __declspec(novtable) BSFaceGenModelExtraData : public NiExtraData
{
public:
    BSFaceGenModelExtraData(int model);
    virtual ~BSFaceGenModelExtraData();

    virtual void vf37();
    virtual void vf38();

    void IncRefCount();
    unsigned int DecRefCount();
    BSFaceGenModel* GetModelFilePath();
    void FUN_0065bf20();
    void* FUN_0065bef0(unsigned int flags);


    union
    {
        struct
        {
            NiPointer<BSFaceGenModel> m_spModel;
        };
        int unk0C;
    };
};

