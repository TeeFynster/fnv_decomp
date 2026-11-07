#pragma once

#include "BaseFormComponent.h"
#include "MagicTarget.h"
#include "FileEntryListCollection.h"

class TESFile;
enum CHUNK_ID;

class TESModelList : public BaseFormComponent
{
public:
    TESModelList();
    ~TESModelList();
    TESModelList& operator=(const TESModelList&);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void ClearComponent();
    bool HasModels();
    unsigned int BaseFormRecord(unsigned int type);
    void BaseFormRecord(BaseFormComponent* component);
    void CopyModelListToBuffer(void* destination, unsigned int flags);
    void CopyModelListToBuffer(unsigned int modelChunkID, unsigned int dataChunkID);
    void CopyModelListToBuffer(CHUNK_ID modelChunkID, CHUNK_ID dataChunkID);
    void LoadStringChunk(TESModelList* modelList, TESFile* file);
    bool ContainsFile(const char* filename);
    void AddModel_00489fa0(const char* filename);
    void FUN_00489a60();
    BSSimpleList<const char*>* FUN_00717e50();

    BSSimpleList<const char*> m_kModelPaths;
    unsigned char m_kModelData[8];
};
