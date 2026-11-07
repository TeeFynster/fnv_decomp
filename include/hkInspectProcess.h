#pragma once

#include "hkReferencedObject.h"
#include "hkProcess.h"

class hkClass;
class ProcessContext;
struct hkSourceListDDB6;
struct hkWrittenObjectQ;
template <typename T> struct hkArrQLocalForm;

class hkInspectProcess : public hkReferencedObject, public hkProcess
{
public:
    hkInspectProcess(const hkSourceListDDB6& sources) throw();
    virtual ~hkInspectProcess() throw();

    virtual void init();

    int unk20;
    int unk24;
    int unk28;
    ProcessContext* context;

    int WriteObjectHeader(void* object, const hkClass* pClassInfo, unsigned int flags);
    void WriteObjectHeader(void* object, int type, int flags);
    int RemovePair(void* object);
    int RemovePair(int key);
    void WriteTrackedObjects();
    int sendRecursiveQ(const void* object, const hkClass* pClassInfo,
                       hkArrQLocalForm<hkWrittenObjectQ>* written) throw();
    int writeObject(const void* object, const hkClass* pClassInfo, hkBool recurse,
                     hkArrQLocalForm<hkWrittenObjectQ>* written) throw();
};
