#pragma once

// The D3D9 SDK's primitive type (d3d9types.h); the guard skips it when d3d9.h is already in.
#ifndef _d3d9TYPES_H_
enum _D3DPRIMITIVETYPE
{
    D3DPT_POINTLIST = 1,
    D3DPT_LINELIST = 2,
    D3DPT_LINESTRIP = 3,
    D3DPT_TRIANGLELIST = 4,
    D3DPT_TRIANGLESTRIP = 5,
    D3DPT_TRIANGLEFAN = 6,
    D3DPT_FORCE_DWORD = 0x7fffffff
};
#endif
