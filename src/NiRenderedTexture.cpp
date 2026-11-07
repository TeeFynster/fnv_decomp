// NiRenderedTexture.cpp: NiRenderedTexture (6 functions)

#include "../include/Ni2DBuffer.h"
#include "../include/NiObject.h"
#include "../include/NiObjectNET.h"
#include "../include/NiRefObject.h"
#include "../include/NiRenderedTexture.h"
#include "../include/NiRenderer.h"
#include "NiRenderedTexture.h"

// @fnv 0x00a7fc00
NiRenderedTexture* NiRenderedTexture::Create(const NiFixedString& name, unsigned int width, unsigned int height,
                                             NiRenderer* renderer, NiTexture::TextureFormatPreferences& preferences,
                                             Ni2DBuffer::MultiSamplePreference msaa, NiRenderedTexture* reuseTexture,
                                             unsigned int aliasOffset)
{
    if (!renderer)
        return 0;
    NiDX9Renderer* dxRenderer = static_cast<NiDX9Renderer*>(renderer);
    bool dimensionsPowerOfTwo = false;
    if (width)
    {
        dimensionsPowerOfTwo = (width & (width - 1)) == 0;
        if (dimensionsPowerOfTwo)
        {
            if (height)
                dimensionsPowerOfTwo = (height & (height - 1)) == 0;
            else
                dimensionsPowerOfTwo = false;
        }
    }
    if (!dimensionsPowerOfTwo)
    {
        if (!(dxRenderer->GetFlags() & 8) && !(dxRenderer->GetFlags() & 4))
            return 0;
    }
    NiRenderedTexture* texture = new NiRenderedTexture;
    texture->m_kFormatPrefs = preferences;
    texture->m_pReuseTexture = reuseTexture;
    texture->m_uiAliasOffset = aliasOffset;
    Ni2DBuffer* buffer = Ni2DBuffer::Create(width, height);
    Ni2DBuffer* oldBuffer = texture->m_spRenderTargetBuffer.m_pObject;
    if (oldBuffer != buffer)
    {
        if (oldBuffer && InterlockedDecrement(reinterpret_cast<volatile long*>(&oldBuffer->m_uiRefCount)) == 0)
            oldBuffer->DeleteThis();
        texture->m_spRenderTargetBuffer.m_pObject = buffer;
        if (buffer)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&buffer->m_uiRefCount));
    }
    texture->m_bUseDepthBuffer = ms_bUseDepthBuffer;
    texture->m_ePixelFormat = ms_eDepthStencilFormat;
    texture->m_bUseMipMaps = ms_bUseMipMaps;
    if (!dxRenderer->CreateRenderedTexture(texture, msaa))
    {
        delete texture;
        return 0;
    }
    texture->m_eMultiSamplePreference = msaa;
    texture->m_pReuseTexture = 0;
    return texture;
}

// Declarations needed
// InterlockedDecrement might be needed if not in headers, but let's assume it is or use a helper if needed.
// The error log didn't complain about InterlockedDecrement, only LONG.

void __fastcall DestroyFogProperty(void*);
void __fastcall NiTexture_RemoveTextureFromList(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
extern int DAT_0109b944;

// Need to declare InterlockedDecrement if it's not found.
// extern "C" long __cdecl InterlockedDecrement(long*);

// @fnv 0x00a7fd30
void* __fastcall DestroyRenderedTexture(NiRenderedTexture* self, int, unsigned char flags)
{
    void* p30 = *(void**)((char*)self + 0x30);
    if (p30)
    {
        // InterlockedDecrement((long*)((char*)p30 + 4))
        // The assembly uses a call to an address.
        // If I use InterlockedDecrement, it matches the semantics.
        if (InterlockedDecrement((long*)((char*)p30 + 4)) == 0)
        {
            void** vtbl = *(void***)p30;
            ((void(__thiscall*)(void*))vtbl[1])(p30);
        }
    }

    void* p24 = *(void**)((char*)self + 0x24);
    *(void**)self = &DAT_0109b944;
    if (p24)
    {
        void** vtbl24 = *(void***)p24;
        ((void(__thiscall*)(void*, int))vtbl24[0])(p24, 1);
    }

    NiTexture_RemoveTextureFromList(self);
    DestroyFogProperty(self);

    if (flags & 1)
    {
        __Dummy_00b6fef0(self, 0x48);
    }

    return self;
}

extern char const* const g_012708e4_arg1[];

// @fnv 0x00a7fbd0
NiRTTI* NiRenderedTexture::GetType()
{
    return reinterpret_cast<NiRTTI*>(const_cast<char const**>(g_012708e4_arg1));
}

// @fnv 0x00a7fbe0
unsigned int NiTexture::GetRenderedWidth()
{
    Ni2DBuffer* buffer = static_cast<NiRenderedTexture*>(this)->m_spRenderTargetBuffer.m_pObject;
    if (buffer)
        return buffer->m_uiImageWidth;
    return 0;
}

// @fnv 0x00a7fbf0
unsigned int NiTexture::GetRenderedHeight()
{
    Ni2DBuffer* buffer = static_cast<NiRenderedTexture*>(this)->m_spRenderTargetBuffer.m_pObject;
    if (buffer)
        return buffer->m_uiImageHeight;
    return 0;
}

// @fnv 0x00be0b90
int NiRenderedTexture::vf41()
{
    return reinterpret_cast<int>(m_spRenderTargetBuffer.m_pObject);
}
