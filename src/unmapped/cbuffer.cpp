// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
struct ID3DXBuffer;
extern "C" __declspec(dllimport) HRESULT WINAPI D3DXCreateBuffer(DWORD, ID3DXBuffer**);
// @fnv 0x00ee6e3a
// src: COMMUNITY 0x00ee6e3a
HRESULT WINAPI D3DXCreateBuffer_0(DWORD size, ID3DXBuffer** buffer)
{
    return D3DXCreateBuffer(size, buffer);
}
