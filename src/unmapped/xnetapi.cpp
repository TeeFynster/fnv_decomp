// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" __declspec(dllimport) int __stdcall WSAStartup(unsigned short version, void* data);
// @fnv 0x00ee6d86
// src: COMMUNITY 0x00ee6d86
int __stdcall WSAStartup_0(unsigned short version, void* data)
{
    return WSAStartup(version, data);
}
