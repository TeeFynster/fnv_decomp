// fallout_shared/renderer_decls.h: declares NiDX9Renderer, Renderer
#ifndef FNV_RENDERER_DECLS_H
#define FNV_RENDERER_DECLS_H


#include "../../include/NiColor.h"
#include "../../include/NiColorA.h"
#include "../../include/NiDX9Renderer.h"


class Renderer
{
  public:
    static bool SetBackgroundColor(NiColor&);
    static bool CanRender();
};

NiDX9Renderer* Renderer_GetNIRenderer();
bool Cmd_Default_Execute();
extern NiColor DAT_011c74b8;
extern bool DAT_011c70e9;

#endif
