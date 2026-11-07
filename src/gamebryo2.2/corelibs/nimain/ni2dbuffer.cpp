// gamebryo2.2/corelibs/nimain/ni2dbuffer.cpp: Ni2DBuffer (6 functions)

#include "ni2dbuffer_decls.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/Ni2DBuffer.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiRenderer.h"

inline bool Ni2DBuffer::IsKindOfType(const NiRTTI* target) const
{
    const NiRTTI* type = GetRTTI();
    while (type)
    {
        if (type == target)
            return true;
        type = type->m_pBaseRTTI;
    }
    return false;
}

// Creates the renderer data if missing, then asks the renderer to create a depth-stencil surface for this buffer; returns false on failure.
// @fnv 0x00a8f200
bool Ni2DBuffer::CreateRendererData(const NiPixelFormat& format, MultiSamplePreference preference)
{
    if (!m_pRendererData)
    {
        if (!IsKindOfType(&DAT_011f603c))
            return false;
        NiRenderer* renderer = NiRenderer::ms_pRenderer;
        // CreateDepthStencil is slot 85; the shared renderer does not yet declare it.
        typedef bool (__thiscall *CreateDepthStencilFunction)(NiRenderer*, Ni2DBuffer*,
            const NiPixelFormat&, MultiSamplePreference);
        if (renderer && !reinterpret_cast<CreateDepthStencilFunction>(
                (*reinterpret_cast<void***>(renderer))[85])(renderer, this, format, preference))
            return false;
    }
    return true;
}

bool __stdcall IsSameAs(NiObject* pkObject);

bool __stdcall Ni2DBuffer_IsEqual(NiObject* pkObject);
// @fnv 0x00a88a50
// src: XBOX_PDB 0x00a88a50
bool __stdcall Ni2DBuffer_IsEqual(NiObject* pkObject)
{
    if (IsSameAs(pkObject))
        return true;
    return false;
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
inline void Ni2DBuffer::RendererData::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

// Releases the renderer-data reference stored in the shared void* member.
struct RendererDataPtr
{
    Ni2DBuffer::RendererData* p;
    ~RendererDataPtr()
    {
        if (p)
            p->DecRefCount();
    }
};
extern int DAT_0109f4dc;
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
// @fnv 0x00a8f330
Ni2DBuffer* __fastcall DestroyNi2DBuffer(Ni2DBuffer* self, int unused, unsigned char flags)
{
    *reinterpret_cast<void**>(self) = &DAT_0109f4dc;
    reinterpret_cast<RendererDataPtr*>(&self->m_pRendererData)->~RendererDataPtr();
    self->NiRefObject::~NiRefObject();
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x14);
    return self;
}

// @fnv 0x00a8f0a0
bool Ni2DBuffer::CopyRectTo(Ni2DBuffer* pkDest, void* pkSrcRect, unsigned int uiDestX, unsigned int uiDestY)
{
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    if (m_pRendererData == 0 || pkRenderer == 0 || pkDest->m_pRendererData == 0)
        return false;
    return pkRenderer->FastCopy(this, pkDest, static_cast<const NiRect<unsigned int>*>(pkSrcRect), uiDestX, uiDestY);
}

// If this, the renderer and pkDest all have a renderer pointer, forwards to the renderer's copy call with the rects and preference; otherwise returns false.
// @fnv 0x00a8f0f0
bool Ni2DBuffer::CopySurface(Ni2DBuffer* pkDest, void* pkSrcRect, void* pkDestRect, int ePref)
{
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    if (m_pRendererData != 0 && pkRenderer != 0 && pkDest->m_pRendererData != 0)
        return pkRenderer->Copy(this, pkDest, static_cast<NiRect<unsigned int>*>(pkSrcRect),
                                static_cast<NiRect<unsigned int>*>(pkDestRect), static_cast<unsigned int>(ePref));
    return false;
}

// Keep the viewer-string entry point as a helper: Ni2DBuffer declares no override.
void __fastcall AppendCameraPathEntries(NiObject*, int, StrArr*);
extern char const* const g_011f603c_arg1;
char* _FUN_00a7d330(char const*);
// Calls the base handler, obtains a string from g_011f603c_arg1, grows pkStrings if full, then stores the string at index m_usSize.
// @fnv 0x00a8f380
void __fastcall AppendBufferString(Ni2DBuffer* self, int unused, StrArr* pkStrings)
{
    AppendCameraPathEntries(self, unused, pkStrings);
    char* pcStr = _FUN_00a7d330(g_011f603c_arg1);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMax = pkStrings->m_usMaxSize;
    if (uiSize >= uiMax)
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiSize);
    pkStrings->SetAt(uiSize, pcStr);
}
