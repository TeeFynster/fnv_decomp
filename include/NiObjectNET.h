#pragma once

#include "NiObject.h"
#include "NiFixedString.h"

class NiTimeController;
class NiExtraData;

namespace fx
{
    struct NiFixedString;
}

class NiObjectNET : public NiObject
{
  public:
    enum CopyType
    {
        COPY_NONE = 0,
        COPY_EXACT = 1,
        COPY_UNIQUE = 2,
    };

    virtual ~NiObjectNET();
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);

    bool AddExtraData(NiExtraData* extra);
    void DeleteExtraData(unsigned short index);
    bool ResizeExtraData(unsigned short size);
    void RefreshExtraData();
    void IncRefCount();
    void DecRefCount();
    void AddController(NiTimeController* controller);
    NiTimeController* GetControllers() const;
    void ReplaceControllers(NiTimeController* controller);
    void SetName(const NiFixedString& name);
    void SetName(const fx::NiFixedString& name);
    void SetFlags(unsigned short flags);
    unsigned int GetNumChildren();
    void CopyMemberData(NiObjectNET* object, CloningProcess& process);

    void SetField_00439360(unsigned short, unsigned int, unsigned int);
    void NiAlphaProperty_SetSrcBlendMode(unsigned short);
    void NiAlphaProperty_SetDestBlendMode(unsigned short);
    void NiStencilProperty_SetStencilFunction(unsigned short);
    void NiStencilProperty_SetStencilPassZFailAction(unsigned short);
    void NiStencilProperty_SetDrawMode(unsigned short);
    void NiStencilProperty_SetStencilFailAction(unsigned short);
    void RemoveAllControllers();
    bool RemoveExtraDataAt(unsigned short);

    NiFixedString m_kName;
    NiTimeController* m_spControllers;
    NiExtraData** m_ppkExtra;
    unsigned short m_usExtraDataSize;
    unsigned short m_usMaxSize;
};
