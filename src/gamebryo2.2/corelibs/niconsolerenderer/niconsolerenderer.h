// gamebryo2.2/corelibs/niconsolerenderer/niconsolerenderer.h: declares HeightLocals, WidthLocals
#ifndef FNV_NICONSOLERENDERER_H
#define FNV_NICONSOLERENDERER_H

#include "niconsolerenderer_types_NiConsoleRenderer.h"
#include "niconsolerenderer_vtable.h"
#include "niconsolerenderer_packet.h"
// 0x00a29680: an empty function (a bare ret) many units call with a message string
void __cdecl Object_DoNothing(const char*, ...);
#pragma optimize("", off)

// @fnv 0x004dee10
unsigned int GraphicsRenderer::GetRenderTargetWidth()
{
    struct HeightLocals
    {
        NiRenderTargetGroup* group;
        NiConsoleRendererHeightArray* array;
    } local;
    local.group = GetDefaultRT();
    if (local.group == 0)
        return 0;
    local.array = (NiConsoleRendererHeightArray*)local.group->GetBuffer_00ee84f0(0);
    if (local.array == 0)
        return 0;
    return local.array->GetSize();
}

// @fnv 0x004dee70
unsigned int GraphicsRenderer::GetRenderTargetHeight()
{
    struct WidthLocals
    {
        NiRenderTargetGroup* group;
        MagicCaster* caster;
    } local;
    local.group = GetDefaultRT();
    if (local.group == 0)
        return 0;
    local.caster = (MagicCaster*)local.group->GetBuffer_00ee84f0(0);
    if (local.caster == 0)
        return 0;
    return (unsigned int)local.caster->MagicCaster::GetSelectedMagicItem();
}

#pragma optimize("", on)
// @fnv 0x00b6b2a0
bool GraphicsRenderer::BeginUsingRenderTargetGroup(NiRenderTargetGroup* group, unsigned int clear)
{
    if ((m_eFrameState != 1 && m_eFrameState != 2) || m_bRenderTargetGroupActive)
        return false;
    if (!group)
    {
        Object_DoNothing(DAT_010ae590);
        return false;
    }
    fnv_EnterCriticalSection(&m_kRendererLock);
    bool result = ((NiConsoleRendererPacketVTable*)this)->BeginGroup(group, clear);
    if (result)
        m_bRenderTargetGroupActive = true;
    else
        fnv_LeaveCriticalSection(&m_kRendererLock);
    return result;
}
// @fnv 0x00a6fa30
bool GraphicsRenderer::MapScreenCoordinates(unsigned int x, unsigned int y, float& outX, float& outY,
                                            NiRenderTargetGroup* group)
{
    if (!group)
        group = GetDefaultRT();
    unsigned int width = ((NiConsoleRendererPacketGroup*)group)->GetWidth(0);
    unsigned int height = ((NiConsoleRendererPacketGroup*)group)->GetHeight(0);
    if (width && height)
    {
        outX = (float)x / (float)width;
        outY = 1.0f - (float)y / (float)height;
        return true;
    }
    return false;
}
#endif
