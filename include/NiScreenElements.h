#pragma once

#include "NiTriShape.h"
#include "NiScreenElementsData.h"

class ScreenSink;

class NiScreenElements : public NiTriShape
{
  public:
    NiScreenElements(NiScreenElementsData* data);
    virtual ~NiScreenElements();

    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);


    void AssignFixedString(NiFixedString* name);
    void Update(const void* data);
    void SetName(const void* name);
    NiScreenElementsData* GetData();
    void* DestroyIfRequested(bool requested);

    void FUN_00a5a040();
    void FUN_00a59c60(NiUpdateData* data);
    void FUN_00a87790(ScreenSink* sink);
    void __fastcall FUN_00a89760();
    NiScreenElements* __thiscall FUN_00a87830(unsigned int flags);

};
