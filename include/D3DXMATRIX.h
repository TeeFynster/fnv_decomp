#pragma once

// Include after the SDK (or its CodeView-compatible local declaration) defines _D3DMATRIX.
// src: DirectX SDK d3dx9math.h; this project uses the trivial 64-byte storage form.
class D3DXMATRIX : public _D3DMATRIX
{
};
