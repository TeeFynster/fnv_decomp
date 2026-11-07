// src/bsmenu/shader_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsmenu/shader.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <stdio.h>
#include <stdarg.h>
extern void* DAT_011f6044;

struct LogSink
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int(__cdecl* pfnOutput)(char*, int, int);
};

// @fnv 0x00aa0020
// src: XBOX_PDB 0x00aa0020
int __cdecl NiShaderFactory_ReportError(int a1, int a2, const char* fmt, ...)
{
    char buf[0x800];
    va_list args;

    va_start(args, fmt);
    if (DAT_011f6044 != 0)
    {
        vsprintf_s(buf, 0x800, fmt, args);
        if (((LogSink*)DAT_011f6044)->pfnOutput != 0)
        {
            return ((LogSink*)DAT_011f6044)->pfnOutput(buf, a1, a2);
        }
    }
    return 0;
}
