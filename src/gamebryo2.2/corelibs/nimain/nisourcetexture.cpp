// gamebryo2.2/corelibs/nimain/nisourcetexture.cpp: NiSourceTexture (2 functions)

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPixelData.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/NiTexture.h"

#include "nisourcetexture_decls.h"
#include "nisourcetexture_types_NiSourceTexture.h"

// Releases the app pixel data object: decrements its ref count, deletes it when the count reaches zero, and clears the pointer.
// @fnv 0x00a60910
void NiSourceTexture::DestroyAppPixelData()
{
    NiPixelData* pAppPixelData = m_spSrcPixelData.m_pObject;
    if (pAppPixelData)
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&pAppPixelData->m_uiRefCount)) == 0)
            pAppPixelData->DeleteThis();
        m_spSrcPixelData.m_pObject = 0;
    }
}

// @fnv 0x00a5fd70
NiSourceTexture* NiSourceTexture::Create(const NiFixedString& name, NiTexture::TextureFormatPreferences& prefs,
                                         bool loadDirectToRendererHint, bool srcRendererDataIsPersistent)
{
    NiSourceTexture* texture = new NiSourceTexture;
    texture->m_kFormatPrefs.m_ePreferredPixelLayout = prefs.m_ePreferredPixelLayout;
    texture->m_kFormatPrefs.m_eAlphaFormat = prefs.m_eAlphaFormat;
    texture->m_kFormatPrefs.m_eMipFlag = prefs.m_eMipFlag;
    texture->m_bLoadDirectToRendererHint = loadDirectToRendererHint;
    texture->m_bSrcRendererDataIsPersistent = srcRendererDataIsPersistent;

    char* newHandle = name.m_kHandle;
    NiFixedString* filename = &texture->m_kFilename;
    if (filename->m_kHandle != newHandle)
    {
        if (newHandle != EmptyFS.m_kHandle)
            InterlockedIncrement(reinterpret_cast<volatile long*>(newHandle - 8));
        if (filename->m_kHandle != EmptyFS.m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(filename->m_kHandle - 8));
        filename->m_kHandle = newHandle;
    }
    NiStandardizeFilePath(filename);
    NiImageConverter_ConvertFilenameToPlatformSpecific_(filename, &texture->m_kPlatformFilename);

    if (DAT_011a9594 && !reinterpret_cast<NiSourceTextureVCall*>(texture)->vfn_0ac())
    {
        reinterpret_cast<NiSourceTextureDeleteVCall*>(texture)->Delete(1);
        return 0;
    }
    return texture;
}
