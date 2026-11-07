// gamebryo2.2/corelibs/nimain/nidirectionallight.cpp: NiDirectionalLight (8 functions)

#include "../../../../include/NiDirectionalLight.h"
#include "../../../../include/NiLight.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/NiTPrimitiveArray.h"
#include "../../../../include/NiPoint3.h"
#include <string.h>

// @fnv 0x00a71ec0
void NiDirectionalLight::CopyMemberData(NiDirectionalLight* pDest, CloningProcess& process)
{
    NiLight::CopyMemberData(pDest, process);
    pDest->m_fDimmer = m_fDimmer;
    pDest->m_kAmb = m_kAmb;
    pDest->m_kDiff = m_kDiff;
    pDest->m_kSpec = m_kSpec;
}

void __fastcall FUN_00a71f60(void*);
extern int DAT_0109d7b4;

inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
{}

// Calls FUN_00a71f60, sets the vtable to &DAT_0109d7b4, stores NiPoint3(1,0,0) at pThis+0xf0 and byte 3 at pThis+0x9d, then returns pThis.
// @fnv 0x00a75c20
// src: EXE 0x00a75c20
void* __fastcall NiDirectionalLight_NiDirectionalLight(char* pObject)
{
    FUN_00a71f60(pObject);
    *(int**)pObject = &DAT_0109d7b4;
    NiPoint3 v(1.0f, 0.0f, 0.0f);
    memcpy(pObject + 0xf0, &v, sizeof(v));
    *(unsigned char*)(pObject + 0x9d) = 3;
    return pObject;
}

struct GlobalObjectO2_00a7b610
{
    int dummy;
};

GlobalObjectO2_00a7b610 g_011f4a68;

// @fnv 0x00a75c70
// src: COMMUNITY 0x00a75c70
void* __fastcall NiDirectionalLight_GetRTTI(NiDirectionalLight*)
{
    return &g_011f4a68;
}

extern "C" void __cdecl FUN_00a72010(void);
extern "C" void __cdecl __Dummy_00b6fef0(void* p, int n);

// Calls FUN_00a72010, then if bit 0 of n is set calls __Dummy_00b6fef0 on this with 0xfc, and returns this.
// @fnv 0x00a75c80
NiDirectionalLight* __fastcall FUN_00a75c80(NiDirectionalLight* light, void*, int aiFlags)
{
    FUN_00a72010();
    if (aiFlags & 1)
        __Dummy_00b6fef0(light, 0xfc);
    return light;
}

// Calls NiAVObject::UpdateWorldData, copies three floats from offsets 0x68/0x74/0x80 to 0xf0/0xf4/0xf8, and increments the int at 0xa8.
// @fnv 0x00a75cb0
// src: XBOX_PDB 0x00a75cb0
void __fastcall NiDirectionalLight_UpdateWorldData(NiDirectionalLight* light, void*, NiUpdateData* UpdateData)
{
    light->NiAVObject::UpdateWorldData(*UpdateData);
    char* p = reinterpret_cast<char*>(light);
    *reinterpret_cast<float*>(p + 0xf0) = *reinterpret_cast<float*>(p + 0x68);
    *reinterpret_cast<float*>(p + 0xf4) = *reinterpret_cast<float*>(p + 0x74);
    *reinterpret_cast<float*>(p + 0xf8) = *reinterpret_cast<float*>(p + 0x80);
    int* q = reinterpret_cast<int*>(p + 0xa8);
    ++*q;
}

namespace fnv_00a75d70 {
// Direct base operation missing from the shared NiLight declarations.
struct NiLightViewerOperations
{
    void AppendEffectProperties(NiTPrimitiveArray<char*>*);
};
struct GlobalObjectO2_00a7b610
{
    const char* p;
};
extern GlobalObjectO2_00a7b610 g_011f4a68;
char* _FUN_00a7d330(const char*);
// @fnv 0x00a75d70
// src: XBOX_PDB 0x00a75d70
void __fastcall NiDirectionalLight_GetViewerStrings(NiDirectionalLight* light, void*, NiTPrimitiveArray<char*>* apArray)
{
    reinterpret_cast<NiLightViewerOperations*>(light)->AppendEffectProperties(apArray);
    char* s = _FUN_00a7d330(g_011f4a68.p);
    unsigned int sz = apArray->m_usSize;
    if (sz >= apArray->m_usMaxSize)
        apArray->SetSize(sz + apArray->m_usGrowBy);
    apArray->SetAt(sz, s);
}
}  // namespace fnv_00a75d70

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);
inline void* operator new(unsigned int, void* memory) throw()
{
    return memory;
}
// @fnv 0x00a75d50
NiDirectionalLight* __cdecl CreateNiDirectionalLight()
{
    return ::new (Object_DispatchCommandFour(sizeof(NiDirectionalLight))) NiDirectionalLight;
}

// Allocates a NiDirectionalLight, initializes it via FUN_00a75c20, copies member data and m_kWorldDir from the source, and returns the new object.
// @fnv 0x00a75cf0
// src: XBOX_PDB 0x00a75cf0
NiObject* __fastcall NiDirectionalLight_CreateClone(NiDirectionalLight* light, void*, CloningProcess* kCloning)
{
    NiDirectionalLight* pkObject = (NiDirectionalLight*)Object_DispatchCommandFour(sizeof(NiDirectionalLight));

    if (pkObject)
        pkObject = (NiDirectionalLight*)NiDirectionalLight_NiDirectionalLight((char*)pkObject);
    else
        pkObject = 0;

    light->CopyMemberData(pkObject, *kCloning);
    *reinterpret_cast<NiPoint3*>(pkObject->unkF0) = *reinterpret_cast<NiPoint3*>(light->unkF0);
    return (NiObject*)pkObject;
}
