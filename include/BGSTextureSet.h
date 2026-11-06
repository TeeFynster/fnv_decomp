#pragma once

#include "TESBoundObject.h"
#include "BSTextureSet.h"
#include "TESTexture.h"

class BSFileEntry;
class BSShaderTextureSet;
class DecalData;
class QueuedFile;



class BGSTextureSet : public TESBoundObject, public BSTextureSet
{
public:
    BGSTextureSet();
    virtual ~BGSTextureSet();

    virtual bool LoadForm(TESFile* modInfo);
    virtual void ClearData();
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual const char* GetTexture(BSShaderProperty::TextureTypeEnum textureType);

    void ResetFormData();
    void LoadTextures(int aePriority, QueuedFile* apQueuedFile, bool abLoad);
    void LoadTextures(int aePriority, void* apQueuedFile, bool abLoad);
    void SetHasSpecular(bool hasSpecular);
    BSShaderTextureSet* BuildShaderTextureSet();

    static void operator delete(void*, unsigned int);
    static BGSTextureSet* GetEmptyTextureSet();
    static void InitializeNullTextureSet();
    static BGSTextureSet* s_pNullTextureSet;

    // Exe ctor/dtor 0x0048e270/0x0048e2e0: six ordinary 12-byte TESTexture slots.
    TESTexture pTextures[6];
    DecalData* m_pDecalData;
    unsigned short iFlags;
    unsigned char layoutPadding86[2];
    BSFileEntry* m_ppTextureFileEntries[6];
};
