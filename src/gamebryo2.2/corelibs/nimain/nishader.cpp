// gamebryo2.2/corelibs/nimain/nishader.cpp: NiShader (10 functions)

#include "../../../../include/NiShader.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiAVObject.h"
// @fnv 0x00a8f3d0
bool NiShader::Initialize()
{
    return m_bInitialized = true;
}

#pragma optimize("", off)
// @fnv 0x0066b0d0
template <>
NiPointer<NiAVObject>& NiPointer<NiAVObject>::operator=(NiAVObject* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            m_pObject->DecRefCount();
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    return *this;
}
#pragma optimize("", on)

extern int DAT_0109f584;
extern int DAT_0101dce4;
extern char* DAT_0109b220;
extern volatile long DAT_011f4400;
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
void __cdecl FUN_00aa1460(void*, unsigned int);

// Preserve the scalar deleting destructor's register ABI using the shared layout.
// @fnv 0x00a8f4d0
NiShader* __fastcall DestroyShader(NiShader* shader, void*, unsigned char flags)
{
    *reinterpret_cast<int* volatile*>(shader) = &DAT_0109f584;
    char* stringData = static_cast<volatile NiShader*>(shader)->m_kName.m_kHandle;
    if (stringData != DAT_0109b220)
        InterlockedDecrement(reinterpret_cast<volatile long*>(stringData - 8));
    *reinterpret_cast<int* volatile*>(shader) = &DAT_0101dce4;
    InterlockedDecrement(&DAT_011f4400);
    if (flags & 1)
        FUN_00aa1460(shader, sizeof(NiShader));
    return shader;
}

// @fnv 0x00a8f3e0
// src: COMMUNITY 0x00a8f3e0
int __stdcall NiD3DShader_UpdatePipeline(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
    return 0;
}

// @fnv 0x00a8f3f0
// src: COMMUNITY 0x00a8f3f0
int __stdcall ThisCall_Ret0_8Args(int a, int b, int c, int d, int e, int f, int g, int h)
{
    return 0;
}

// @fnv 0x00a8f400
// src: GUESS 0x00a8f400 (confidence: high)
int __stdcall Object_ReturnZero(int arg0, int arg1, int arg2, int arg3)
{
    return 0;
}

// @fnv 0x00a8f410
// src: COMMUNITY 0x00a8f410
int __stdcall ThisCall_Ret0_2Args(int arg0, int arg1)
{
    return 0;
}

// @fnv 0x00a8f420
// src: XBOX_PDB 0x00a8f420
bool __stdcall NiShader_SetAlphaOverride(int a, int b, int c, int d, int e, int f)
{
    return false;
}

// @fnv 0x00a8f430
// src: COMMUNITY 0x00a8f430
char __stdcall NiD3DShaderProgram_SetShaderConstantArray(int a, int b, int c, int d, int e)
{
    return 0;
}

// @fnv 0x00c9a420
// src: XBOX_PDB 0x00c9a420
bool __stdcall BSShaderTextureSet_IsEqual(void* unk00)
{
    return false;
}
