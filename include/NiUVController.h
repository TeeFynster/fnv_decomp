#pragma once

#include "NiTimeController.h"
#include "NiUVData.h"

class StrArr;
struct UVKey;
struct MyStreamWriter;

class NiUVController : public NiTimeController
{
public:
    virtual ~NiUVController();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void Update(NiUpdateData& update);
    virtual void SetTarget(NiObjectNET* target);
    virtual void Unk_2A();

    void LinkUVData(NiStream& stream);
    void LinkUVData(void* stream);
    bool __thiscall RegisterStreamables_00a45970(void* stream);
    void Update_00a45cf0(NiUpdateData& update);
    void GetViewerStrings_00a46150(StrArr* strings);
    void vf24(StrArr* strings);

    int __thiscall GetDataFromMember(int* count, int* type, char* size);
    int __thiscall GetSomeData(int* count, int* type, char* size);
    int __thiscall GetSomeValues(int* count, int* type, char* size);
    int __thiscall GetSomePtrValues(int* count, int* type, char* size);
    UVKey* __thiscall GetDataFromMember(unsigned int& count, int& type, unsigned char& size);
    UVKey* __thiscall GetSomeData(unsigned int& count, int& type, unsigned char& size);
    UVKey* __thiscall GetSomeValues(unsigned int& count, int& type, unsigned char& size);
    UVKey* __thiscall GetSomePtrValues(unsigned int& count, int& type, unsigned char& size);
    void UpdateUVTransform();
    void ResetRefObject();
    void __thiscall AssignRefObj(NiUVData* data);
    void __thiscall ResetKeyTimeExtrema();
    int __thiscall ProcessAndReturnValue_00a45b60();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
    unsigned int* __thiscall CloneUVData(unsigned int flags);
    void WriteToStream(MyStreamWriter* stream);

    unsigned int m_uiLastIdx0;
    unsigned int m_uiLastIdx1;
    unsigned int m_uiLastIdx2;
    unsigned int m_uiLastIdx3;
    unsigned short m_usValue;
    unsigned short unk46;
    NiPointer<NiUVData> m_pData;
    union
    {
        bool m_bUpdateEnabled;
        bool m_bChanged;
    };
};
