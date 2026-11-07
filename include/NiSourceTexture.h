#pragma once

#include "NiTexture.h"
#include "NiFixedString.h"
#include "NiAVObject.h"

class NiFile;
class NiPersistentSrcTextureRendererData;
class NiPixelData;
class NiTexture__FormatPrefs;

class NiSourceTexture : public NiTexture
{
  public:
    NiSourceTexture() throw();
    virtual ~NiSourceTexture();

    virtual void LoadBinary(NiStream&);
    virtual void LoadPixelDataFromFile();
    virtual void DestroyAppPixelData();
    virtual bool CreateRendererData();

    static NiSourceTexture* Create(const NiFixedString&, NiTexture::TextureFormatPreferences&, bool, bool);
    static NiSourceTexture* Create(const NiFixedString&, NiTexture__FormatPrefs&, bool, bool);
    void IncRefCount();
    void DecRefCount();
    const NiFixedString& GetFilename();
    bool NiSourceTexture_GetLookNormal();  // 0x004af860: tests the byte at +0x43 against mask 0 (always false)
    void NiSourceTexture_SetLookNormal();  // 0x004af880: rewrites the byte at +0x43 with itself

    NiFixedString m_kFilename;
    NiFixedString m_kPlatformFilename;
    NiPointer<NiPersistentSrcTextureRendererData> m_spPersistentSrcRendererData;
    NiPointer<NiPixelData> m_spSrcPixelData;
    bool m_bStatic;
    bool m_bLoadDirectToRendererHint;
    bool m_bSrcRendererDataIsPersistent;
    char cLooked;
    NiFile* m_pFile;
};
