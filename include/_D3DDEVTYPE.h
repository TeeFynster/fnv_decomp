#pragma once

// The D3D9 SDK's device type (d3d9types.h); the guard skips it when d3d9.h is already in.
#ifndef _d3d9TYPES_H_
enum _D3DDEVTYPE
{
    D3DDEVTYPE_HAL = 1,
    D3DDEVTYPE_REF = 2,
    D3DDEVTYPE_SW = 3,
    D3DDEVTYPE_NULLREF = 4,
    D3DDEVTYPE_FORCE_DWORD = 0x7fffffff
};
#endif
