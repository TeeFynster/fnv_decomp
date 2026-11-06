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

    void FUN_00439360(unsigned short, unsigned int, unsigned int);
    void FUN_00439340(unsigned short);
    void FUN_00439390(unsigned short);
    void FUN_0049edb0(unsigned short);
    void FUN_0049ee10(unsigned short);
    void FUN_0049ee30(unsigned short);
    void FUN_00533fb0(unsigned short);
    void FUN_00a5c050();
    bool FUN_00a5bf50(unsigned short);

    NiFixedString m_kName;
    NiTimeController* m_spControllers;
    NiExtraData** m_ppkExtra;
    unsigned short m_usExtraDataSize;
    unsigned short m_usMaxSize;
};
