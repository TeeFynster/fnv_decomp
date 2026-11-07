#pragma once

#include "BaseFormComponent.h"
#include "TESFullName.h"

class TESForm;
class TESObjectREFR;
class TESFile;
class BSS;
class String;

class TESTexture : public BaseFormComponent
{
public:
    TESTexture();
    ~TESTexture();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void* result);
    virtual char* GetTextureResourcePath();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    bool TESTexture_CompareComponent(TESTexture* component);
    void Save(int chunk);

    static unsigned int GetTextureNameLength(TESForm* form);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm* form, TESObjectREFR* reference);
    char* GetTextureResourceName();
    void AssignTextureName(char* name);
    void AssignTextureName(const char* name);
    void SetTexture(const char* name);

    static void NormalizeTextureFilePath(char* path, char* output);
    static char* NormalizeTextureFilePath(void* result, char* path);
    static const char* NormalizeTextureFilePath(BSStringT<char>& result, const char* path);
    static const char* NormalizeTextureFilePath(BSS& result, const char* path);
    template <class StringType>
    static const char* NormalizeTextureFilePath(StringType& result, const char* path);
    static char* NormalFileToRegularFile(void* result, char* path);
    char* GetRegularTextureFilePath(void* result);
    static void GetRegularTextureFilePath(char* path, char* output);
    static char* GetRegularTextureFilePath(void* result, char* path);
    static void ConvertTexturePath(char* path, char* output);
    static void ConvertTexturePath(const char* path, char* output);
    static bool IsTextureChunk(int chunk);
    static void ReadTextureData(TESTexture* texture, TESFile* file);
    static char* GetMessageIconName(TESForm* form, TESObjectREFR* reference);

    unsigned long Unk_04();
    void GetNormalMap(String* result);
    char* GetPathRoot();

    BSStringT<char> FullNameComponent;
};
