#pragma once

#include "BaseFormComponent.h"
#include "FileEntryList.h"
#include "TESFullName.h"

class TESFile;
class TESObject;
class TESModelTextureSwap;

class TESModel : public BaseFormComponent
{
public:
    TESModel();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual ~TESModel();
    virtual const char* GetModelFilePath();
    virtual void SetModelFilePath(const char* path);
    virtual TESModelTextureSwap* GetAsModelMaterialSwap() const;

    const char* GetModelFilePath() const;
    char* GetFullName();
    const char* GetModelName();
    char* GetModelPath();
    void SetModelPath(char* path);
    void SetModelPath(const char* path);
    void* Destroy(bool noDealloc);
    const char* GetPath();
    TESModelTextureSwap* GetAsModelTextureSwap();
    unsigned int GetModelLength();
    unsigned int GetModelLength() const;
    void InitializeComponent();
    void BaseFormRecord(BaseFormComponent* component);
    void WriteToBuffer(unsigned int chunk, unsigned int texChunk);
    void WriteToStream();
    void LoadTextureSwapList(void* buffer, unsigned int size, unsigned int version);
    unsigned int TESModel_GetSkinFlags();
    bool TESModel_QHasFacegenData();
    void* FUN_00489010(unsigned int flags);
    void SetFlags_004893c0(unsigned char flags);

    static void LoadModelData(TESModel* model, TESFile* file);
    static void LoadTextureSwapData(TESModel* model, TESFile* file);
    static unsigned int GetModelLength(TESObject* object);
    static const char* GetModelFilePath(TESObject* object);

    BSStringT<char> m_kModelFilePath;
    FileEntryList m_pTextureSwapData;
    unsigned char cFlags;
    unsigned char unk15[3];
};
