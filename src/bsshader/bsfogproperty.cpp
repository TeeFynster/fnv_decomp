// bsshader/bsfogproperty.cpp: FogPropertyWithBase (8 functions)

#include "bsfogproperty_decls.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTArray.h"
#include "../../include/NiTNewInterface.h"

inline NiColor::NiColor() : r(0), g(0), b(0)
{}

inline NiFogProperty::NiFogProperty()
{
    m_uiObjectFlags = 0;
    m_fFogDepth = 1.0f;
    m_kFogTint = DAT_011f4998;
}

// @fnv 0x00bb8180
FogPropertyWithBase::FogPropertyWithBase()
{
    m_fFogStartDistance = (1.0 - m_fFogDepth * DAT_010b9e30) * DAT_0103a480;
    m_fFogEndDistance = 163840.0f;
    m_kFogPlane.x = 0.0f;
    m_kFogPlane.y = 0.0f;
    m_kFogPlane.z = 0.0f;
    m_kFogPlane.c = 0.0f;
    m_fAlpha = 1.0f;
}

// Stores a scaled depth value at offset 0x2c and the constant 163840.0f at offset 0x30.
// @fnv 0x00bb8140
void __fastcall SetDepthParams(FogPropertyWithBase* property, void*, float afDepth)
{
    property->m_fFogStartDistance = (1.0 - afDepth * DAT_010b9e30) * DAT_0103a480;
    property->m_fFogEndDistance = 163840.0f;
}

#include "../../include/NiMemObject.h"
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

extern unsigned char* DAT_0109b244;
extern int EmptyFS;

inline void NiRefObject::DecRefCount()
{
    if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
        DeleteThis();
}

// The original destructor body is kept here because the shared declaration
// does not provide its inlined base-class teardown.
// @fnv 0x00a5c240
void __fastcall DestroyProperty(NiProperty* property)
{
    *(void**)property = (void*)&DAT_0109b244;
    ((NiAVObject*)property)->UpdateModelBound();

    NiRefObject* pExtra = (NiRefObject*)property->m_spControllers;
    if (pExtra)
        pExtra->DecRefCount();

    char* pString = property->m_kName.m_kHandle;
    if (pString != (char*)EmptyFS)
    {
        InterlockedDecrement((volatile long*)(pString - 8));
    }

    property->NiRefObject::~NiRefObject();
}

extern int g_012007e0;

// @fnv 0x00bb8170
// src: XBOX_PDB 0x00bb8170
int* __cdecl BSFogProperty_GetRTTI()
{
    return &g_012007e0;
}

extern char const* const g_012007e0_arg1;

// @fnv 0x00a99f20
// src: COMMUNITY 0x00a99f20
char const* const* __cdecl NiFogProperty_GetRTTI()
{
    return &g_012007e0_arg1;
}

void __cdecl _delete(void*, unsigned int);
// @fnv 0x00a99f40
void* __fastcall DestroyFogProperty(NiFogProperty* property, void*, unsigned int auiFlags)
{
    DestroyProperty(property);
    if (auiFlags & 1)
        _delete(property, sizeof(NiFogProperty));
    return property;
}

void __cdecl ReleaseObjectArray(void*);
extern int DAT_010a1458;
extern MemoryManager g_memoryManager;
// The original vftable's RTTI identifies this array specialization.
class NiMetricsOutputModule;
// @fnv 0x00a9bbc0
void* __fastcall DestroyObjectArray(
    NiTArray<NiPointer<NiMetricsOutputModule>, NiTNewInterface<NiPointer<NiMetricsOutputModule> > >* array,
    void*, unsigned int auiFlags)
{
    void* p = array->m_pBase;
    *(void**)array = (void*)&DAT_010a1458;
    ReleaseObjectArray(p);
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(array);
    return array;
}


void DestroyFogProperty();
// @fnv 0x00a99f30
// src: GUESS 0x00a99f30 (confidence: medium)
void BSFogProperty_DestroyFogProperty_Thunk()
{
    DestroyFogProperty();
}
