
// src/havok/common/visualize/hkprocessregisterutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkprocessregisterutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl hkDebugDisplayProcess_registerProcess();
void __cdecl CreateStatisticsProcess();
void __cdecl RegisterObjectInspectionProcess();
// @fnv 0x00d61420
// src: COMMUNITY 0x00d61420
void __cdecl hkProcessRegisterUtil_registerAllCommonProcesses()
{
    hkDebugDisplayProcess_registerProcess();
    CreateStatisticsProcess();
    RegisterObjectInspectionProcess();
}
