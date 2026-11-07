
// src/staging/blk_00c60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <stddef.h>
#include "../../include/MemoryManager.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTArray.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiPointer.h"
#include "../../include/NiColorA.h"
#include "../../include/BSDecalPlacementVectorExtraData.h"
#include "../../include/BSFaceGenMorphData.h"
#include "../../include/BSPSysSimpleColorModifier.h"
#include "../../include/NiBinaryExtraData.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiObject.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiPSysData.h"
#include "../../include/NiPSysCylinderEmitter.h"
#include "../../include/NiPSysModifier.h"
#include "../../include/NiPSysPositionModifier.h"
#include "../../include/NiPSysVolumeEmitter.h"
#include "../../include/NiStream.h"

class BSAttachPointPair;

extern "C" void* g_01204388;

struct FUN_00c600f0_Class
{
    void* __thiscall BSPSysStripUpdateModifier_GetRTTI();
};

// @fnv 0x00c600f0
// src: COMMUNITY 0x00c600f0
void* __thiscall FUN_00c600f0_Class::BSPSysStripUpdateModifier_GetRTTI()
{
    return &g_01204388;
}

// @fnv 0x00c60910
// src: XBOX_PDB 0x00c60910
void BSPSysSimpleColorModifier::LinkObject_00c60910(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
}

struct FUN_00c60930_class
{
    void FUN_00c31670(void*);
    void BSPSysSimpleColorModifier_RegisterStreamables(void* a);
};

// @fnv 0x00c60930
// src: XBOX_PDB 0x00c60930
void FUN_00c60930_class::BSPSysSimpleColorModifier_RegisterStreamables(void* a)
{
    FUN_00c31670(a);
}

extern "C" void* g_01204390;

struct FUN_00c60d40_Class
{
    void* __thiscall BSPSysSimpleColorModifier_GetRTTI();
};

// @fnv 0x00c60d40
// src: COMMUNITY 0x00c60d40
void* __thiscall FUN_00c60d40_Class::BSPSysSimpleColorModifier_GetRTTI()
{
    return &g_01204390;
}

struct FUN_00c61420_Class
{
    void* __thiscall BSWArray_CreateClone(void* p);
};

// @fnv 0x00c61420
// src: COMMUNITY 0x00c61420
void* __thiscall FUN_00c61420_Class::BSWArray_CreateClone(void* apUnused)
{
    return this;
}

struct FUN_00a99870_Class
{
    void __thiscall CopyMembers_00a99870(int, int);
};

// src: XBOX_PDB 0x00a99870
void __thiscall FUN_00a99870_Class::CopyMembers_00a99870(int, int)
{}

struct FUN_00c61430_Class
{
    void __thiscall ForwardCall_00c61430(int, int);
};

// @fnv 0x00c61430
// src: GUESS 0x00c61430 (confidence: low)
void __thiscall FUN_00c61430_Class::ForwardCall_00c61430(int a, int b)
{
    ((FUN_00a99870_Class*)this)->CopyMembers_00a99870(a, b);
}

struct FUN_00c61450_Class
{
    void FUN_00a99a90(int);
    void BSWArray_LoadBinary(int a);
};

// @fnv 0x00c61450
// src: XBOX_PDB 0x00c61450
void FUN_00c61450_Class::BSWArray_LoadBinary(int aiValue)
{
    FUN_00a99a90(aiValue);
}

struct FUN_00a9af00_class
{
    void NiBinaryExtraData_LinkObject(int a);
};

struct FUN_00c61470_class : FUN_00a9af00_class
{
    void CallBaseWithArg(int a);
};

// @fnv 0x00c61470
void FUN_00c61470_class::CallBaseWithArg(int aiValue)
{
    NiBinaryExtraData_LinkObject(aiValue);
}

struct FUN_00c61490_Class
{
    bool RegisterStreamables_00a89ae0(const void* arg);
    bool IsNot(const void* arg);
};

// Returns the logical negation of FUN_00a89ae0(arg).
// @fnv 0x00c61490
bool FUN_00c61490_Class::IsNot(const void* arg)
{
    return !RegisterStreamables_00a89ae0(arg);
}

struct FUN_00c614c0_Class
{
    void __thiscall SaveBinary_00a89210(void*);
    void __thiscall BSWArray_SaveBinary(void* ap);
};

// @fnv 0x00c614c0
// src: XBOX_PDB 0x00c614c0
void __thiscall FUN_00c614c0_Class::BSWArray_SaveBinary(void* ap)
{
    SaveBinary_00a89210(ap);
}

struct FUN_00c614e0_Class
{
    char IsEqual_00a998e0(int arg);
    char BSWArray_IsEqual(int arg);
};
// Calls FUN_00a998e0 with arg and returns its result.
// @fnv 0x00c614e0
// src: XBOX_PDB 0x00c614e0
char FUN_00c614e0_Class::BSWArray_IsEqual(int arg)
{
    char result = IsEqual_00a998e0(arg);
    return result;
}

extern NiFixedString* DAT_012043a0;

// @fnv 0x00c61610
// src: COMMUNITY 0x00c61610
void NiAVObject::BSWArray_SetName()
{
    SetName(*DAT_012043a0);
}

extern "C" void* g_012043a4;

struct FUN_00c61810_class
{
    void* BSWArray_GetRTTI();
};

// @fnv 0x00c61810
// src: COMMUNITY 0x00c61810
void* FUN_00c61810_class::BSWArray_GetRTTI()
{
    return &g_012043a4;
}

struct FUN_00c61820_class
{
    void* PArrayPoint_Copy(int);
};

// @fnv 0x00c61820
// src: COMMUNITY 0x00c61820
void* FUN_00c61820_class::PArrayPoint_Copy(int)
{
    return this;
}

// @fnv 0x00c61ef0
void NiPSysVolumeEmitter::LoadBinaryFromStream(NiStream* stream)
{
    NiPSysVolumeEmitter::LoadBinary(*stream);
}

namespace fnv_00c61f10 {
// This forwarding entry point is absent from the shared class.
struct VolumeEmitterLink : NiPSysVolumeEmitter
{
    void BSPSysArrayEmitter_LinkObject(NiStream& stream);
};

// @fnv 0x00c61f10
// src: XBOX_PDB 0x00c61f10
void VolumeEmitterLink::BSPSysArrayEmitter_LinkObject(NiStream& stream)
{
    NiPSysVolumeEmitter::LinkObject(stream);
}
}  // namespace fnv_00c61f10

// @fnv 0x00c61f30
// src: XBOX_PDB 0x00c61f30
void NiObject::BSPSysArrayEmitter_PostLinkObject(NiStream& stream)
{
    BSPSysArrayEmitter_SetupArray();
    NiObject::LinkObject(stream);
}

struct FUN_00c61f60_class
{
    void __thiscall NiPSysAirFieldModifier_RegisterStreamables(int);
    void __thiscall BSPSysArrayEmitter_RegisterStreamables(int);
};

// @fnv 0x00c61f60
// src: XBOX_PDB 0x00c61f60
void __thiscall FUN_00c61f60_class::BSPSysArrayEmitter_RegisterStreamables(int arg)
{
    NiPSysAirFieldModifier_RegisterStreamables(arg);
}

struct FUN_00c61f80_cls
{
    void FUN_00c31b60(void* apParam);
    void BSPSysArrayEmitter_SaveBinary(void* apParam);
};

// @fnv 0x00c61f80
// src: XBOX_PDB 0x00c61f80
void FUN_00c61f80_cls::BSPSysArrayEmitter_SaveBinary(void* apParam)
{
    FUN_00c31b60(apParam);
}

// The shared emitter does not declare these forwarding entry points.
struct CylinderEmitterEntries : NiPSysCylinderEmitter
{
    bool FUN_00c31b80(NiAVObject*);
    bool BSPSysArrayEmitter_IsEqual(NiAVObject*);
};

// @fnv 0x00c61fa0
// src: XBOX_PDB 0x00c61fa0
bool CylinderEmitterEntries::BSPSysArrayEmitter_IsEqual(NiAVObject* ap)
{
    return FUN_00c31b80(ap);
}

struct FUN_00c627e0_Class
{
    void __thiscall BSPSysArrayEmitter_SetupArray();
    void __thiscall BSPSysArrayEmitter_SetEmitterObj(void* p);
};

// @fnv 0x00c627e0
// src: XBOX_PDB 0x00c627e0
void __thiscall FUN_00c627e0_Class::BSPSysArrayEmitter_SetEmitterObj(void* pValue)
{
    *(void**)((char*)this + 0x54) = pValue;
    BSPSysArrayEmitter_SetupArray();
}

extern "C" void* g_012043b8;

struct FUN_00c632e0_Class
{
    void* __thiscall PArrayPoint_GetRTTI();
};

// @fnv 0x00c632e0
// src: COMMUNITY 0x00c632e0
void* __thiscall FUN_00c632e0_Class::PArrayPoint_GetRTTI()
{
    return &g_012043b8;
}

namespace fnv_00c63930 {
struct FUN_00c63930_Class : public NiPSysModifier
{
    void BSParentVelocityModifier_LinkObject(NiStream&);
};
// @fnv 0x00c63930
// src: XBOX_PDB 0x00c63930
void FUN_00c63930_Class::BSParentVelocityModifier_LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
}
}  // namespace fnv_00c63930

struct FUN_00c31670_class
{
    void __thiscall FUN_00c31670(int a);
};

struct FUN_00c63950_class
{
    void __thiscall ForwardToOther(int a);
};

// @fnv 0x00c63950
void __thiscall FUN_00c63950_class::ForwardToOther(int aiValue)
{
    ((FUN_00c31670_class*)this)->FUN_00c31670(aiValue);
}

struct GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_012043c8;

struct FUN_00c63aa0_class
{
    GlobalObject_00a7b610* BSParentVelocityModifier_GetRTTI();
};

// @fnv 0x00c63aa0
// src: COMMUNITY 0x00c63aa0
GlobalObject_00a7b610* FUN_00c63aa0_class::BSParentVelocityModifier_GetRTTI()
{
    return &g_012043c8;
}

void __cdecl NiFixedString_CopyMemory_00c63c30(int, int);

// @fnv 0x00c63c10
void __cdecl CallWithSameArgumentTwice(int aiValue)
{
    NiFixedString_CopyMemory_00c63c30(aiValue, aiValue);
}

// @fnv 0x00c644b0
void BSDecalPlacementVectorExtraData::LinkToObject(void* apObject)
{
    reinterpret_cast<NiBinaryExtraData*>(this)->NiBinaryExtraData::LinkObject(*reinterpret_cast<NiStream*>(apObject));
}

struct FUN_00c644d0_Class
{
    unsigned char Equals(const char*);
    unsigned char BSDecalPlacementVectorExtraData_IsEqual(const char*);
};
// Calls Equals with arg and returns its result.
// @fnv 0x00c644d0
// src: XBOX_PDB 0x00c644d0
unsigned char FUN_00c644d0_Class::BSDecalPlacementVectorExtraData_IsEqual(const char* arg)
{
    unsigned char result = Equals(arg);
    return result;
}

extern "C" void* g_012043d4;

struct FUN_00c64600_Class
{
    void* __thiscall GetGlobalPointer();
};

// @fnv 0x00c64600
void* __thiscall FUN_00c64600_Class::GetGlobalPointer()
{
    return &g_012043d4;
}

// NiStream has no declaration for this string-registration entry point.
struct StreamStringRegistration : NiStream
{
    void SaveCString(const char*);
};

// Links this object to the stream, then passes the string pointer at offset 8 to the stream's FUN_00a64160.
// @fnv 0x00c64950
// src: XBOX_PDB 0x00c64950
void NiObject::BSReference_SaveBinary(NiStream* stream)
{
    NiObject::LinkObject(*stream);
    static_cast<StreamStringRegistration*>(stream)->SaveCString(*(const char**)((char*)this + 8));
}

// @fnv 0x00c64aa0
// src: XBOX_PDB 0x00c64aa0
void NiObject::BSNodeReferences_LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    stream.ReadUnsignedInteger();
}

struct FUN_00c64b70 : NiObject
{
    bool RegisterStreamables(NiStream& stream);
};
// @fnv 0x00c64b70
bool FUN_00c64b70::RegisterStreamables(NiStream& stream)
{
    return NiObject::RegisterStreamables(stream);
}

struct FUN_00c64fc0_class
{
    int __thiscall GetThisAddress(int);
};

// @fnv 0x00c64fc0
int __thiscall FUN_00c64fc0_class::GetThisAddress(int)
{
    return (int)this;
}

// @fnv 0x00c65160
// src: XBOX_PDB 0x00c65160
void NiExtraData::BSAttachPoints_LinkObject(NiStream& stream)
{
    NiExtraData::LinkObject(stream);
}

struct C00c541e0
{
    bool FUN_00a7b3d0(int);
    bool BSAttachPoints_IsEqual(int a);
};

// Calls FUN_00a7b3d0 with the given int and returns its bool result.
// @fnv 0x00c65290
// src: XBOX_PDB 0x00c65290
bool C00c541e0::BSAttachPoints_IsEqual(int aiValue)
{
    bool result = FUN_00a7b3d0(aiValue);
    return result;
}

extern "C" void* DAT_012043f0;

struct FUN_00c657e0_class
{
    void* GetGlobalDataPtr();
};

// @fnv 0x00c657e0
void* FUN_00c657e0_class::GetGlobalDataPtr()
{
    return &DAT_012043f0;
}

extern "C" void NiFreeAlias(void*);
extern int DAT_010c377c;

// RTTI at vftable 0x010c377c identifies NiTArray<NiPointer<NiAVObject>, NiTMallocInterface<NiPointer<NiAVObject> > >.
// @fnv 0x00c62890
template <>
NiTArray<NiPointer<NiAVObject>, NiTMallocInterface<NiPointer<NiAVObject> > >::~NiTArray()
{
    void* result = m_pBase;
    NiFreeAlias(result);
}

extern "C" void NiFreeAlias(void*);
extern int DAT_010c3a08;
// RTTI at vftable 0x010c3a08 identifies NiTArray<BSAttachPointPair*, NiTMallocInterface<BSAttachPointPair*> >.
// @fnv 0x00c65680
template <>
NiTArray<BSAttachPointPair*, NiTMallocInterface<BSAttachPointPair*> >::~NiTArray()
{
    void* p = m_pBase;
    NiFreeAlias(p);
}

struct FUN_00c600c0_class
{
    void* __thiscall UpdateState_00c5fd50();
    void* __thiscall FUN_00c600c0(unsigned int flags);
    static void __cdecl operator delete(void* p, unsigned int size);
};

// Calls FUN_00c5fd50, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c600c0
void* __thiscall FUN_00c600c0_class::FUN_00c600c0(unsigned int flags)
{
    UpdateState_00c5fd50();
    if (flags & 1)
        operator delete(this, 0x1c);
    return this;
}

struct FUN_00c613a0_Class
{
    void __thiscall FUN_00c613a0();
    void* __thiscall FUN_00c617e0(unsigned int flags);
    void operator delete(void* p, unsigned int size);
};
// @fnv 0x00c617e0
void* __thiscall FUN_00c613a0_Class::FUN_00c617e0(unsigned int flags)
{
    this->FUN_00c613a0();
    if (flags & 1)
        this->operator delete(this, 20);
    return this;
}

extern "C" void NiFree(void*);
extern MemoryManager g_memoryManager;
// As at 0x00c65710, this deleting entry inlines the destructor and uses
// MemoryManager::Deallocate; the generated VC9 /Od entry calls the destructor
// and global operator delete. Keep only an entry point on the shared layout.
struct AVObjectArrayDeleteEntry : NiTArray<NiPointer<NiAVObject>, NiTMallocInterface<NiPointer<NiAVObject> > >
{
    void* Delete(int flag);
};
// @fnv 0x00c63210
void* AVObjectArrayDeleteEntry::Delete(int flag)
{
    *reinterpret_cast<void**>(this) = &DAT_010c377c;
    void* p = m_pBase;
    NiFree(p);
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00c632f0_class
{
    void* __thiscall FUN_00c632f0(unsigned int flags);
};
void __cdecl operator delete(void*, int);
// @fnv 0x00c632f0
void* __thiscall FUN_00c632f0_class::FUN_00c632f0(unsigned int flags)
{
    reinterpret_cast<NiExtraData*>(this)->DestroyFields_00a7b300();
    if (flags & 1)
        operator delete(this, 12);
    return this;
}

struct FUN_00c63840_Class : NiPSysModifier
{
    void __thiscall CopyModifierWithValue(NiPSysModifier* dst, CloningProcess* proc);
};
// @fnv 0x00c63840
void __thiscall FUN_00c63840_Class::CopyModifierWithValue(NiPSysModifier* dst, CloningProcess* proc)
{
    NiPSysModifier::CopyMemberData(dst, *proc);
    float value = *(float*)((char*)this + 0x20);
    *(float*)((char*)dst + 0x20) = value;
}

struct SStream;
struct SObj;
void __cdecl CallAnimCallback(SStream*, SObj*);
struct FUN_00c63970_class : NiPSysModifier
{
    void __thiscall BSParentVelocityModifier_SaveBinary(void* stream);
};
// @fnv 0x00c63970
// src: XBOX_PDB 0x00c63970
void __thiscall FUN_00c63970_class::BSParentVelocityModifier_SaveBinary(void* stream)
{
    NiPSysModifier::SaveBinary(*reinterpret_cast<NiStream*>(stream));
    CallAnimCallback(reinterpret_cast<SStream*>(stream), reinterpret_cast<SObj*>(reinterpret_cast<char*>(this) + 0x20));
}

void __cdecl FUN_00c63b40(void* p);
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c64610_Class
{
    void __thiscall FUN_00c63b40();
    void* __thiscall FUN_00c64610(unsigned int flags);
};
// Calls FUN_00c63b40, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c64610
void* __thiscall FUN_00c64610_Class::FUN_00c64610(unsigned int flags)
{
    FUN_00c63b40();
    if (flags & 1)
        operator delete(this, 0x40);
    return this;
}

namespace fnv_00c64710 {
extern MemoryManager g_memoryManager;
struct FUN_00c64710_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void ReleaseStorage_00c64710();
};
// @fnv 0x00c64710
// src: GUESS 0x00c64710 (confidence: low)
void FUN_00c64710_Class::ReleaseStorage_00c64710()
{
    void* p = m_iWordAt00;
    while (p)
    {
        void* next = p;
        p = *reinterpret_cast<void**>(p);
        *reinterpret_cast<void**>(reinterpret_cast<char*>(next) + 8) = 0;
        void* pFreed = next;
        g_memoryManager.Deallocate(pFreed);
    }
    m_8 = 0;
    m_iWordAt00 = 0;
    m_iWordAt04 = 0;
}
}  // namespace fnv_00c64710

struct FUN_00c64930_Class
{
    void BSReference_LinkObject(int a);
};

// @fnv 0x00c64930
// src: COMMUNITY 0x00c64930
void FUN_00c64930_Class::BSReference_LinkObject(int a)
{}

struct FUN_00c64940_Class
{
    bool BSReference_RegisterStreamables(int a);
};
// @fnv 0x00c64940
// src: COMMUNITY 0x00c64940
bool FUN_00c64940_Class::BSReference_RegisterStreamables(int a)
{
    return true;
}

struct FUN_00c64c30_Class
{
    bool __thiscall BSNodeReferences_IsEqual(int a);
};

// @fnv 0x00c64c30
// src: XBOX_PDB 0x00c64c30
bool __thiscall FUN_00c64c30_Class::BSNodeReferences_IsEqual(int a)
{
    return false;
}

// The shared color modifier has no constructor declaration. This field-free
// adapter supplies the original position-modifier base initialization.
struct SimpleColorModifierConstruction : NiPSysPositionModifier
{
    SimpleColorModifierConstruction();
};
// Constructor: sets the vtable pointer and zeroes the four-float arrays at offsets 0x18, 0x28 and 0x38.
// @fnv 0x00c60240
SimpleColorModifierConstruction::SimpleColorModifierConstruction()
{
    {
        float* p = reinterpret_cast<float*>(&reinterpret_cast<BSPSysSimpleColorModifier*>(this)->color1);
        p[0] = 0.0f;
        p[1] = 0.0f;
        p[2] = 0.0f;
        p[3] = 0.0f;
    }
    {
        float* q = reinterpret_cast<float*>(&reinterpret_cast<BSPSysSimpleColorModifier*>(this)->color2);
        q[0] = 0.0f;
        q[1] = 0.0f;
        q[2] = 0.0f;
        q[3] = 0.0f;
    }
    {
        float* r = reinterpret_cast<float*>(&reinterpret_cast<BSPSysSimpleColorModifier*>(this)->color3);
        r[0] = 0.0f;
        r[1] = 0.0f;
        r[2] = 0.0f;
        r[3] = 0.0f;
    }
}

struct FUN_00c60950_class : BSPSysSimpleColorModifier
{
    void BSPSysSimpleColorModifier_SaveBinary(NiStream* stream);
};
// @fnv 0x00c60950
// src: XBOX_PDB 0x00c60950
void FUN_00c60950_class::BSPSysSimpleColorModifier_SaveBinary(NiStream* stream)
{
    NiPSysModifier::SaveBinary(*reinterpret_cast<NiStream*>(stream));
    CallAnimCallback((SStream*)stream, reinterpret_cast<SObj*>(&fadeIn));
    CallAnimCallback((SStream*)stream, reinterpret_cast<SObj*>(&fadeOut));
    CallAnimCallback((SStream*)stream, reinterpret_cast<SObj*>(&color1End));
    CallAnimCallback((SStream*)stream, reinterpret_cast<SObj*>(&color2Start));
    CallAnimCallback((SStream*)stream, reinterpret_cast<SObj*>(&color2End));
    CallAnimCallback((SStream*)stream, reinterpret_cast<SObj*>(&color3Start));
    color1.SaveBinary(*stream);
    color2.SaveBinary(*stream);
    color3.SaveBinary(*stream);
}

int _sprintf_s(char*, unsigned int, const char*, ...);
size_t _strlen(const char*);
struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
struct FUN_00c62090_Class
{
    char* __thiscall BuildAttachTypeString(const char* name, int type);
};
// Allocates strlen(name)+0x10 bytes and formats name with an AT_* attach-type suffix chosen by type (0 vertices, 1 specific objs, 2 nodes).
// @fnv 0x00c62090
char* __thiscall FUN_00c62090_Class::BuildAttachTypeString(const char* name, int type)
{
    unsigned int size = _strlen(name) + 0x10;
    char* buffer = (char*)((P03MM*)&g_memoryManager)->Allocate(size);
    char* result = buffer;
    switch (type)
    {
    case 0:
        _sprintf_s(result, size, "%s = AT_VERTICES", name);
        break;
    case 1:
        _sprintf_s(result, size, "%s = AT_SPECIFICOBJS", name);
        break;
    case 2:
        _sprintf_s(result, size, "%s = AT_NODES", name);
        break;
    }
    return result;
}

extern GlobalObject_00a7b610 g_012043b0;

struct FUN_00c63320_Class
{
    GlobalObject_00a7b610* __thiscall BSPSysArrayEmitter_GetRTTI();
};

// @fnv 0x00c63320
// src: COMMUNITY 0x00c63320
GlobalObject_00a7b610* FUN_00c63320_Class::BSPSysArrayEmitter_GetRTTI()
{
    return &g_012043b0;
}

struct FUN_00c65210_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    unsigned short m_18;
    void __thiscall BSAttachPoints_SaveBinary(NiStream& stream);
};
void __cdecl NiStreamSaveBinary_unsigned_int(NiStream& stream, const unsigned int& count);
// @fnv 0x00c65210
// src: XBOX_PDB 0x00c65210
void __thiscall FUN_00c65210_class::BSAttachPoints_SaveBinary(NiStream& stream)
{
    reinterpret_cast<NiExtraData*>(this)->NiExtraData::SaveBinary(stream);
    unsigned int count = m_18;
    NiStreamSaveBinary_unsigned_int(stream, count);
    for (unsigned int i = 0; i < count; i++)
    {
        const char* pcString = ((const char**)m_10)[i];
        stream.SerializeString(pcString);
        stream.SerializeString(pcString + 4);
    }
}

extern "C" void* __cdecl NiMalloc(unsigned int size);
// @fnv 0x00c65760
template <>
NiTArray<BSAttachPointPair*, NiTMallocInterface<BSAttachPointPair*> >::NiTArray(unsigned int count, unsigned int growBy)
{
    m_usMaxSize = (unsigned short)count;
    m_usGrowBy = (unsigned short)growBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
    {
        unsigned int n = m_usMaxSize;
        m_pBase = (BSAttachPointPair**)NiMalloc(n * sizeof(BSAttachPointPair*));
    }
    else
        m_pBase = 0;
}

struct FUN_00c61b10
{
    char m_iWordAt00[0x6c];
    FUN_00c61b10();
    ~FUN_00c61b10();
    static void* operator new(unsigned int size);
};
// Allocates and constructs a new FUN_00c61b10 object, returning the pointer.
// @fnv 0x00c61e70
// src: EXE 0x00c61e70
FUN_00c61b10* BSPSysArrayEmitter_CreateObject()
{
    return new FUN_00c61b10;
}

extern "C" void* __cdecl NiMalloc(unsigned int);

// @fnv 0x00c63260
template <>
NiTArray<NiPointer<NiAVObject>, NiTMallocInterface<NiPointer<NiAVObject> > >::NiTArray(unsigned int x, unsigned int y)
{
    m_usMaxSize = (unsigned short)x;
    m_usGrowBy = (unsigned short)y;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
    {
        int i = m_usMaxSize;
        m_pBase = (NiPointer<NiAVObject>*)NiMalloc(i << 2);
    }
    else
        m_pBase = 0;
}

struct NiPoint3_ZERO
{
    int x;
    int y;
    int z;
};
extern NiPoint3_ZERO _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;
struct ParticlePositionModifierConstruction : NiPSysPositionModifier
{
    ParticlePositionModifierConstruction();
};
// Initializes the object's vtable pointer, sets field 3 to 0xbb8, zeroes two NiPoint3 members at offsets 0x24 and 0x30, and clears floats at indices 6 and 8.
// @fnv 0x00c63330
ParticlePositionModifierConstruction::ParticlePositionModifierConstruction()
{
    ((int*)this)[3] = 0xbb8;
    *(NiPoint3_ZERO*)((char*)this + 0x24) = _NiPoint3_ZERO;
    *(NiPoint3_ZERO*)((char*)this + 0x30) = _NiPoint3_ZERO;
    ((float*)this)[8] = 0.0f;
    ((float*)this)[6] = 0.0f;
}

int strcpy_s(char* dst, unsigned int size, const char* src);
size_t strlen(const char*);
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
};
struct FUN_00c64780_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void BSReference_SetName(const char* apName);
};
// Frees the stored string, then allocates a copy of apName (if non-null) and stores it in m_8.
// @fnv 0x00c64780
// src: XBOX_PDB 0x00c64780
void FUN_00c64780_Class::BSReference_SetName(const char* apName)
{
    unsigned int uiSize;
    void* pOld7 = m_8;
    g_memoryManager.Deallocate(pOld7);
    m_8 = 0;
    if (apName)
    {
        uiSize = strlen(apName) + 1;
        void* pNew = ((MemoryManagerAllocHelper*)&g_memoryManager)->Allocate(uiSize);
        m_8 = pNew;
        if (m_8)
        {
            char* pBuffer2 = (char*)m_8;
            strcpy_s(pBuffer2, uiSize, apName);
        }
    }
}

// The 0x00c65710 deleting entry inlines the destructor body. VC9 /Od's
// generated scalar deleting destructor calls 0x00c65680 instead, so retain
// only this entry point on the shared array layout (no local data members).
struct AttachPointArrayDeleteEntry : NiTArray<BSAttachPointPair*, NiTMallocInterface<BSAttachPointPair*> >
{
    void* Delete(unsigned int flags);
};

// @fnv 0x00c65710
void* AttachPointArrayDeleteEntry::Delete(unsigned int flags)
{
    void* p;
    *reinterpret_cast<void**>(this) = &DAT_010c3a08;
    p = m_pBase;
    NiFree(p);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00c60000_Class
{
    bool __thiscall IsEqualWithFloat(void* arg);
};

// Calls IsEqual on arg, then returns whether the float at offset 24 of arg equals the one at offset 24 of this.
// @fnv 0x00c60000
bool __thiscall FUN_00c60000_Class::IsEqualWithFloat(void* apObject)
{
    if (!reinterpret_cast<const NiPSysModifier*>(this)->NiPSysModifier::IsEqual((NiObject*)apObject))
        return false;
    void* p = apObject;
    if (((float*)p)[6] == ((float*)this)[6])
        return true;
    return false;
}

struct FUN_00c60700_Class : BSPSysSimpleColorModifier
{
    void BSPSysSimpleColorModifier_CopyMembers(NiPSysModifier* dst, CloningProcess& proc);
};

// @fnv 0x00c60700
// src: XBOX_PDB 0x00c60700
void FUN_00c60700_Class::BSPSysSimpleColorModifier_CopyMembers(NiPSysModifier* dst, CloningProcess& proc)
{
    this->CopyMemberData(dst, proc);

    ((BSPSysSimpleColorModifier*)dst)->color1 = color1;
    ((BSPSysSimpleColorModifier*)dst)->color2 = color2;
    ((BSPSysSimpleColorModifier*)dst)->color3 = color3;

    ((BSPSysSimpleColorModifier*)dst)->fadeIn = fadeIn;
    ((BSPSysSimpleColorModifier*)dst)->fadeOut = fadeOut;
    ((BSPSysSimpleColorModifier*)dst)->color1End = color1End;
    ((BSPSysSimpleColorModifier*)dst)->color2Start = color2Start;
    ((BSPSysSimpleColorModifier*)dst)->color2End = color2End;
    ((BSPSysSimpleColorModifier*)dst)->color3Start = color3Start;
}

template <class T> void __cdecl ReadBinaryValue(NiStream& stream, T& value);

struct FUN_00c60850_Class : public BSPSysSimpleColorModifier
{
    void BSPSysSimpleColorModifier_LoadBinary(NiStream& stream);
};

// @fnv 0x00c60850
// src: XBOX_PDB 0x00c60850
void FUN_00c60850_Class::BSPSysSimpleColorModifier_LoadBinary(NiStream& stream)
{
    NiPSysModifier::LoadBinary(stream);

    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(&fadeIn));
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(&fadeOut));
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(&color1End));
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(&color2Start));
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(&color2End));
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(&color3Start));

    color1.LoadBinary(stream);
    color2.LoadBinary(stream);
    color3.LoadBinary(stream);
}

struct FUN_004a4cc0_shell
{
    bool __thiscall FUN_004a4cc0(void*);
};

struct FUN_00c60a10_Class : BSPSysSimpleColorModifier
{
    bool __thiscall BSPSysSimpleColorModifier_IsEqual(NiObject*);
};

// @fnv 0x00c60a10
// src: XBOX_PDB 0x00c60a10
bool FUN_00c60a10_Class::BSPSysSimpleColorModifier_IsEqual(NiObject* pObject)
{
    if (!reinterpret_cast<const NiPSysModifier*>(this)->NiPSysModifier::IsEqual(pObject))
        return false;

    FUN_00c60a10_Class* pOther = reinterpret_cast<FUN_00c60a10_Class*>(pObject);

    if (pOther->fadeIn == fadeIn && pOther->fadeOut == fadeOut && pOther->color1End == color1End && pOther->color2Start == color2Start &&
        pOther->color2End == color2End && pOther->color3Start == color3Start &&
        reinterpret_cast<FUN_004a4cc0_shell*>(reinterpret_cast<char*>(pOther) + 0x18)
            ->FUN_004a4cc0(reinterpret_cast<char*>(this) + 0x18) &&
        reinterpret_cast<FUN_004a4cc0_shell*>(reinterpret_cast<char*>(pOther) + 0x28)
            ->FUN_004a4cc0(reinterpret_cast<char*>(this) + 0x28) &&
        reinterpret_cast<FUN_004a4cc0_shell*>(reinterpret_cast<char*>(pOther) + 0x38)
            ->FUN_004a4cc0(reinterpret_cast<char*>(this) + 0x38))
        return true;

    return false;
}

void __cdecl FUN_00c31750(void);
void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00c60d10_Class
{
    void FUN_00c31750();
    void* __thiscall FUN_00c60d10(unsigned int flags);
};

// @fnv 0x00c60d10
void* FUN_00c60d10_Class::FUN_00c60d10(unsigned int flags)
{
    FUN_00c31750();
    if (flags & 1)
        operator delete(this, 0x60);
    return this;
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c612b0_Class : A51BF0Base
{
    unsigned char m_data[20];

    FUN_00c612b0_Class();
};

extern NiFixedString DAT_011f49e0;

// Allocates a FUN_00c612b0_Class object, sets its name to DAT_011f49e0, and returns it as an NiAVObject.
// @fnv 0x00c61510
// src: EXE 0x00c61510
NiAVObject* __cdecl BSWArray_CreateObject()
{
    NiAVObject* object = reinterpret_cast<NiAVObject*>(new FUN_00c612b0_Class);
    object->SetName(DAT_011f49e0);
    return object;
}

struct FUN_00c61830_class
{
    void ForwardCall_00c61830(void* a, void* b);
};
// @fnv 0x00c61830
// src: GUESS 0x00c61830 (confidence: low)
void FUN_00c61830_class::ForwardCall_00c61830(void* a, void* b)
{
    reinterpret_cast<NiExtraData*>(this)->CopyMembers_00a7b330(a, b);
}

struct FUN_00c62390_class
{
    void BSPSysArrayEmitter_GetAPoint(void*, void*);
};
struct FUN_00c61ba0_class : FUN_00c62390_class
{
    void ForwardToBase(void* a, void* b, void* c);
};
// @fnv 0x00c61ba0
void FUN_00c61ba0_class::ForwardToBase(void* apUnused, void* apArg1, void* apArg2)
{
    BSPSysArrayEmitter_GetAPoint(apArg1, apArg2);
}

namespace fnv_00c61bc0 {
extern unsigned int _data_011c16bc;

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c61bc0_class
{
    void __thiscall BSPSysArrayEmitter_CopyMembers(FUN_00c61b10* object, int arg);
    FUN_00c61b10* __thiscall CreateObject(int arg);
};

// Allocates a new FUN_00c61b10, initialises it via FUN_00c61c50 with arg, and returns the object.
// @fnv 0x00c61bc0
FUN_00c61b10* __thiscall FUN_00c61bc0_class::CreateObject(int arg)
{
    FUN_00c61b10* object = new FUN_00c61b10;
    BSPSysArrayEmitter_CopyMembers(object, arg);
    return object;
}
}  // namespace fnv_00c61bc0

template <class T> void ReadBinaryValue(NiStream&, T&);
struct FUN_00c63900_class : NiPSysModifier
{
    void LoadModifierData(NiStream& stream);
};
// @fnv 0x00c63900
void FUN_00c63900_class::LoadModifierData(NiStream& stream)
{
    NiPSysModifier::LoadBinary(stream);
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x20));
}

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00c31750_Class
{
    void __thiscall FUN_00c31750();
};

struct FUN_00c63a70_Class
{
    void* __thiscall FUN_00c63a70(unsigned int flags);
};

// Calls FUN_00c31750 on this, deletes this with size 0x3c when flags has bit 1 set, and returns this.
// @fnv 0x00c63a70
void* __thiscall FUN_00c63a70_Class::FUN_00c63a70(unsigned int flags)
{
    ((FUN_00c31750_Class*)this)->FUN_00c31750();
    if (flags & 1)
        operator delete(this, 0x3c);
    return this;
}

struct DecalPlacementEntries : BSDecalPlacementVectorExtraData
{
    void* BSDecalPlacementVectorExtraData_CopyMembers(void* object, int value);
    void* BSDecalPlacementVectorExtraData_CreateClone(int value);
    BSDecalPlacementVectorExtraData* Construct(int parameter);
};

// @fnv 0x00c64060
// src: XBOX_PDB 0x00c64060
void* DecalPlacementEntries::BSDecalPlacementVectorExtraData_CreateClone(int value)
{
    BSDecalPlacementVectorExtraData* pObject = new BSDecalPlacementVectorExtraData(0);
    this->BSDecalPlacementVectorExtraData_CopyMembers(pObject, value);
    return pObject;
}

struct FUN_00c64500_Class : FUN_00c61490_Class
{
    bool BSDecalPlacementVectorExtraData_RegisterStreamables(const void* arg);
};

// Returns the negation of FUN_00a89ae0(arg).
// @fnv 0x00c64500
// src: XBOX_PDB 0x00c64500
bool FUN_00c64500_Class::BSDecalPlacementVectorExtraData_RegisterStreamables(const void* arg)
{
    return !RegisterStreamables_00a89ae0(arg);
}

namespace fnv_00c64530 {
struct A51BF0Base
{
    char m_ucUnknownByte[0x40];

    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c63ab0 : public A51BF0Base
{
    FUN_00c63ab0(int a);
};

extern NiFixedString DAT_011f49e0;

// Allocates a FUN_00c63ab0 with argument 0, sets its name to DAT_011f49e0, and returns it.
// @fnv 0x00c64530
void* CreateNamedNode()
{
    FUN_00c63ab0* result = new FUN_00c63ab0(0);
    reinterpret_cast<NiAVObject*>(result)->SetName(DAT_011f49e0);
    return result;
}
}  // namespace fnv_00c64530

struct A46BB0Object
{
    bool IsEqual(A46BB0Object*);
};

int __cdecl __stricmp(const char*, const char*);

struct FUN_00c64980_Class : A46BB0Object
{
    bool BSReference_IsEqual(A46BB0Object* arg);
};

// Returns true when IsEqual(arg) holds and both objects' string pointers at offset 8 are non-null and __stricmp-equal.
// @fnv 0x00c64980
// src: XBOX_PDB 0x00c64980
bool FUN_00c64980_Class::BSReference_IsEqual(A46BB0Object* apOther)
{
    if (this->IsEqual(apOther))
    {
        A46BB0Object* p = apOther;
        if (*(void**)((char*)this + 8) != 0)
        {
            void* a = *(void**)((char*)p + 8);
            if (a != 0)
            {
                void* b = *(void**)((char*)p + 8);
                void* c = *(void**)((char*)this + 8);
                return __stricmp((const char*)c, (const char*)b) == 0;
            }
        }
    }
    return false;
}

struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* AssignInternedString(unsigned int);
};
struct FUN_00c64dc0_Class
{
    char m_iWordAt00;
    char m_cByteAtOffset1;
    char m_cByteAtOffset2;
    char m_cByteAtOffset3;
    FUN_0043ba10_shell m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_0043ba10_shell* BSAttachPointPair_SetChild(unsigned int a);
};
// @fnv 0x00c64dc0
// src: COMMUNITY 0x00c64dc0
FUN_0043ba10_shell* FUN_00c64dc0_Class::BSAttachPointPair_SetChild(unsigned int a)
{
    int v0;
    int v1;
    int v2;
    return m_iWordAt04.AssignInternedString(a);
}

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00c64e70_Class
{
    void __thiscall FUN_00c64e70();
    void* __thiscall FUN_00c65650(unsigned int flags);
};

// Calls FUN_00c64e70, then frees this with operator delete when flags has bit 1 set, and returns this.
// @fnv 0x00c65650
void* __thiscall FUN_00c64e70_Class::FUN_00c65650(unsigned int flags)
{
    this->FUN_00c64e70();
    if (flags & 1)
        operator delete(this, 0x1c);
    return this;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct SpawnedObject_b9118
{
    char m00[0x60];
    SpawnedObject_b9118();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};

// Allocates and constructs a SpawnedObject_b9118 via its custom operator new and returns the pointer.
// @fnv 0x00c607d0
// src: EXE 0x00c607d0
SpawnedObject_b9118* BSPSysSimpleColorModifier_CreateObject()
{
    SpawnedObject_b9118* result = new SpawnedObject_b9118();
    return result;
}

class C61330Base
{
  public:
    C61330Base(int iA, int iB);
    virtual ~C61330Base();

    int unk04;
};

class FUN_00c61330 : public C61330Base
{
  public:
    void Initialize();

    FUN_00c61330(int iA, int iB);
    virtual ~FUN_00c61330();
};

// Constructs the object by forwarding iA and iB to the C61330Base constructor, then calls Initialize().
// @fnv 0x00c61330
FUN_00c61330::FUN_00c61330(int iA, int iB) : C61330Base(iA, iB)
{
    Initialize();
}

struct FUN_00c61c50_cls
{
    unsigned int pad0[0x18];
    unsigned int* m_60;
    unsigned short pad1[1];
    unsigned short m_66;
    void NiPSysVolumeEmitter_CopyMembers(unsigned int a, unsigned int b);
    void BSPSysArrayEmitter_CopyMembers(unsigned int x, unsigned int y);
};
// @fnv 0x00c61c50
// src: XBOX_PDB 0x00c61c50
void FUN_00c61c50_cls::BSPSysArrayEmitter_CopyMembers(unsigned int x, unsigned int y)
{
    unsigned int pad[0xf];
    NiPSysVolumeEmitter_CopyMembers(x, y);
    unsigned int n = m_66;
    if (n != 0)
    {
        ((NiTPrimitiveArray<NiPointer<NiAVObject> >*)(x + 0x5c))->SetSize(n);
        while (n-- != 0)
        {
            ((NiTPrimitiveArray<NiPointer<NiAVObject> >*)(x + 0x5c))->SetAt(n, reinterpret_cast<const NiPointer<NiAVObject>&>(m_60[n]));
        }
    }
}

struct FUN_00c62140_Elem;
struct FUN_00c62140_Item;

struct FUN_00c62140_Val
{
    float m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    unsigned char m_08;
};

struct FUN_00c62140_Item
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    void NiAVObject_Update(FUN_00c62140_Val* pVal);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    FUN_00c62140_Elem** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct FUN_00c62140_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual FUN_00c62140_Item* v03();
};

struct FUN_00c62140_Pad
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_00c62140_Pad5
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct FUN_00c62140_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    FUN_00c62140_Obj* color2Start;
    int unk58;
    NiTPrimitiveArray<NiPointer<NiAVObject> > color3Start;

    void BSPSysArrayEmitter_SetupArray();
    void BSPSysArrayEmitter_SetObjectPointers(FUN_00c62140_Elem* pElem);
};

// @fnv 0x00c62140
// src: XBOX_PDB 0x00c62140
void FUN_00c62140_cls::BSPSysArrayEmitter_SetupArray()
{
    color3Start.RemoveAll();
    FUN_00c62140_Obj* pad;
    pad = color2Start;
    FUN_00c62140_Item* pItem = (0 != pad) ? pad->v03() : 0;
    if (!!pItem)
    {
        FUN_00c62140_Val val;
        val.m_00 = 0.0f;
        val.m_04 = 0;
        val.m_05 = 0;
        val.m_06 = 0;
        val.m_07 = 0;
        val.m_08 = 0;
        pItem->NiAVObject_Update(&val);
        unsigned int slot = pItem->m_a6;
        while (slot-- != 0)
        {
            FUN_00c62140_Pad5 objTmp;
            FUN_00c62140_Elem** i;
            i = &pItem->m_a0[slot];
            FUN_00c62140_Elem* e = *i;
            BSPSysArrayEmitter_SetObjectPointers(e);
        }
    }
}

struct S_00c62cc0_Locals
{
    unsigned int value;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
};

// @fnv 0x00c62cc0
template <>
unsigned int NiTArray<NiPointer<NiAVObject>, NiTMallocInterface<NiPointer<NiAVObject> > >::Add(const NiPointer<NiAVObject>& value)
{
    S_00c62cc0_Locals locals;
    locals.value = m_usSize;

    if (locals.value >= m_usMaxSize)
    {
        SetSize(m_usGrowBy + locals.value);
    }

    SetAt(locals.value, value);
    return locals.value;
}

// FUN_00c634b0: thiscall (this in ecx), 2 stack params (a1 pointer, unsigned short index).

class XVec12
{
  public:
    float m_00;
    float m_04;
    float m_08;
};

class XSub30
{
  public:
    unsigned int unk00;
    unsigned int Call0045bb20(XVec12* out);
};

class XItem12
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void Call004578c0(unsigned int r, float f);
};

class XItem28
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    void Call0063c8a0(XSub30* arg);
};

class XObj70
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    XItem12* m_20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58,
        unk5c, unk60, unk64, unk68, unk6c;
    XItem28* m_70;
};

class FUN_00c634b0_cls
{
  public:
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14;
    float m_18;
    unsigned int m_1c;
    unsigned int m_20, m_24, m_28, m_2c;
    XSub30 m_30;
    void BSParentVelocityModifier_Initialize(XObj70* a1, unsigned short idx);
};

// @fnv 0x00c634b0
// src: XBOX_PDB 0x00c634b0
void FUN_00c634b0_cls::BSParentVelocityModifier_Initialize(XObj70* pObj, unsigned short usIndex)
{
    XItem28* p = pObj->m_70;
    p = p + usIndex;
    p->Call0063c8a0(&m_30);
    XVec12 qq;
    XItem12* mm = pObj->m_20;
    XVec12 xx;
    mm[usIndex].Call004578c0(m_30.Call0045bb20(&xx), m_18);
}

struct NiPoint3_c
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
extern NiPoint3_c NiPoint3_ZERO;

struct FUN_00c63780_c
{
    int pad[9];
    NiPoint3_c v;
    void ResetVector();
};

// Sets the vector member v to NiPoint3_ZERO.
// @fnv 0x00c63780
void FUN_00c63780_c::ResetVector()
{
    v = NiPoint3_ZERO;
}

namespace fnv_00c637b0 {
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct ParticlePositionClone : ParticlePositionModifierConstruction
{
    unsigned char data[0x3c - sizeof(ParticlePositionModifierConstruction)];

    static __forceinline void* __cdecl operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
struct FUN_00c637b0_Class : FUN_00c63840_Class
{
    ParticlePositionClone* CreateParticlePositionClone(CloningProcess* process);
};
// Allocates a ParticlePositionClone, initialises it via CopyModifierWithValue with the given process, and returns it.
// @fnv 0x00c637b0
ParticlePositionClone* FUN_00c637b0_Class::CreateParticlePositionClone(CloningProcess* process)
{
    ParticlePositionClone* clone = new ParticlePositionClone();
    CopyModifierWithValue(reinterpret_cast<NiPSysModifier*>(clone), process);
    return clone;
}
}  // namespace fnv_00c637b0

void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct PositionModifierObject_b9439
{
    char m00[0x3c];
    PositionModifierObject_b9439();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
// Allocates and constructs a PositionModifierObject_b9439 via its custom operator new and returns the pointer.
// @fnv 0x00c63880
PositionModifierObject_b9439* CreatePositionModifierObject()
{
    return new PositionModifierObject_b9439();
}

struct Pad32
{
    unsigned int a0, a1, a2, a3, a4, a5, a6, a7;
};

struct ArgObj
{
    void FUN_0096a610(void* p);
};

struct FUN_00c63a00_cls
{
    void FUN_00c319e0(void* a);
    void BSParentVelocityModifier_GetViewerStrings(ArgObj* a1);
};

unsigned int __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int v);
unsigned int __cdecl NiGetViewerString_00a7d550(const char* name, float f);

// @fnv 0x00c63a00
// src: XBOX_PDB 0x00c63a00
void FUN_00c63a00_cls::BSParentVelocityModifier_GetViewerStrings(ArgObj* a1)
{
    unsigned int r1;
    unsigned int r2;
    unsigned int g;
    Pad32 pad;
    FUN_00c319e0(a1);
    g = *(unsigned int*)&g_012043c8;
    r1 = NiViewerStrings_NiGetViewerString_Title(g);
    a1->FUN_0096a610(&r1);
    r2 = NiGetViewerString_00a7d550("Damping", *(float*)((char*)this + 0x20));
    a1->FUN_0096a610(&r2);
}

struct S_00c643d0_Foo
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    unsigned short m_uiItemCount;
    void* m_entries[16];

    void __thiscall FUN_00a9a4e0(int arg);
    void __thiscall BSDecalPlacementVectorExtraData_SaveBinary(int arg);
};

extern "C" void __cdecl NiStreamSaveBinary_unsigned_short(int arg, void* object);
extern "C" void __cdecl NiPoint3_SaveBinary(int arg, void* data, int count);

// @fnv 0x00c643d0
// src: XBOX_PDB 0x00c643d0
void __thiscall S_00c643d0_Foo::BSDecalPlacementVectorExtraData_SaveBinary(int arg)
{
    this->FUN_00a9a4e0(arg);

    NiStreamSaveBinary_unsigned_short(arg, &this->m_uiItemCount);

    for (int i = 0; i < this->m_uiItemCount; ++i)
    {
        NiStreamSaveBinary_unsigned_short(arg, this->m_entries[i]);

        int count2 = *reinterpret_cast<unsigned short*>(this->m_entries[i]);
        void* count = reinterpret_cast<char*>(this->m_entries[i]) + 4;

        NiPoint3_SaveBinary(arg, count, count2 * 3);

        int data = *reinterpret_cast<unsigned short*>(this->m_entries[i]);
        void* pDataB = reinterpret_cast<char*>(this->m_entries[i]) + 0x64;

        NiPoint3_SaveBinary(arg, pDataB, data * 3);
    }
}

class FUN_00c64b90_target;

class FUN_00c64b90_item
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_18;
};

class FUN_00c64b90_target
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30(unsigned int value);
};

class FUN_00c64b90_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FUN_00c64b90_item** m_0c;
    int unk10;
    unsigned short m_14;
    void BSNodeReferences_SaveBinary(FUN_00c64b90_target* a1);
    void nullsub_3(FUN_00c64b90_target* a1);
};

void __cdecl NiStreamSaveBinary_unsigned_int(FUN_00c64b90_target* a1, unsigned int* p);

// @fnv 0x00c64b90
// src: XBOX_PDB 0x00c64b90
void FUN_00c64b90_cls::BSNodeReferences_SaveBinary(FUN_00c64b90_target* apTarget)
{
    unsigned int count;
    unsigned int i;
    FUN_00c64b90_item* item3;
    unsigned int v2;
    unsigned int bytes;
    nullsub_3(apTarget);
    count = m_14;
    bytes = count * 2;
    NiStreamSaveBinary_unsigned_int(apTarget, &bytes);
    for (i = 0; i < count; i++)
    {
        item3 = m_0c[i];
        if (item3 != 0)
        {
            v2 = item3->m_18;
            apTarget->v30(v2);
            apTarget->v30((unsigned int)item3);
        }
    }
}

struct FUN_00c64da0_cls
{
    int unk00;
    void Callee0043ba10(int a);
    void BSAttachPointPair_SetParent(int a);
};

// @fnv 0x00c64da0
// src: COMMUNITY 0x00c64da0
void FUN_00c64da0_cls::BSAttachPointPair_SetParent(int a)
{
    int unkLoc0;
    int unkLoc1;
    int unkLoc2;
    this->Callee0043ba10(a);
}

struct DispatchStub_c64
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void** m10;
    int unk14;
    unsigned short m18;
    void DispatchToItems(int a8, int cc);
};
struct ItemCallee_c64
{
    void BSAttachPoints_AddPair(int a1, int a2);
};

// Calls FUN_00a7b330 with a8 and cc, then for each of m18 entries in m10 calls FUN_00c65490 on the item and item+4.
// @fnv 0x00c64fd0
void DispatchStub_c64::DispatchToItems(int pTarget, int cc)
{
    reinterpret_cast<NiExtraData*>(this)->CopyMembers_00a7b330((void*)pTarget, (void*)cc);
    unsigned int count = m18;
    for (unsigned int i = 0; i < count; i++)
    {
        int item = (int)m10[i];
        reinterpret_cast<ItemCallee_c64*>(pTarget)->BSAttachPoints_AddPair(item, item + 4);
    }
}

struct FUN_00c65180_VTable
{
    virtual void FUN_00c65180_v0();
    virtual void FUN_00c65180_v1();
    virtual void FUN_00c65180_v2();
    virtual void FUN_00c65180_v3();
    virtual void FUN_00c65180_v4();
    virtual void FUN_00c65180_v5();
    virtual void FUN_00c65180_v6();
    virtual void FUN_00c65180_v7();
    virtual void FUN_00c65180_v8(void* p);
};

struct FUN_00c65180_Class
{
    unsigned char __thiscall FUN_00a7b290(FUN_00c65180_VTable* p);

    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void** m_10;
    int m_14;
    unsigned short m_18;

    unsigned char __thiscall VisitEntries(FUN_00c65180_VTable* p);
};

// Calls FUN_00a7b290; if it succeeds, iterates m_10 up to m_18 times, passing each item and item+4 to the vtable's FUN_00c65180_v8, and returns the result.
// @fnv 0x00c65180
unsigned char __thiscall FUN_00c65180_Class::VisitEntries(FUN_00c65180_VTable* p)
{
    unsigned char result = FUN_00a7b290(p);

    if (result)
    {
        unsigned int count = m_18;

        for (unsigned int i = 0; i < count; ++i)
        {
            void* item = m_10[i];

            p->FUN_00c65180_v8(item);
            p->FUN_00c65180_v8(static_cast<char*>(item) + 4);
        }
    }

    return result;
}

struct Point3ParameterData
{
    float unk00;
    float unk04;
    float unk08;
    float m_fXValue;
    float m_fYValue;
    float unk14;
    float unk18;
};

struct SimpleColorModifierEntries : BSPSysSimpleColorModifier
{
    void UpdateParticleColors(float fTime, NiPSysData* pkData);
};

// For each particle, lerps RGB between color1/2/3 by normalized age and sets alpha from the fade-in/out percentages.
// @fnv 0x00c602e0
void SimpleColorModifierEntries::UpdateParticleColors(float fTime, NiPSysData* pkData)
{
    unsigned short usNumParticlesTmp;
    NiColorA* pkColors8;
    float fRangeVal;
    float fRange4;
    unsigned short us4;
    float fNormAge3;
    Point3ParameterData* pkInfo3;
    float kFLerp1;
    float fLerp4;
    float fFadeOutLerpA;
    float fFadeInLerp3;
    Point3ParameterData* pkParticleInfo3;

    pkColors8 = reinterpret_cast<NiColorA*>(pkData->m_pkColor);
    if (!pkColors8)
        return;

    fRange4 = color2Start - color1End;
    fRangeVal = color3Start - color2End;

    usNumParticlesTmp = pkData->m_usActive;
    for (us4 = 0; us4 < usNumParticlesTmp; us4++)
    {
        pkParticleInfo3 = pkData->m_pkParticleInfo;
        pkInfo3 = &pkParticleInfo3[us4];
        fNormAge3 = pkInfo3->m_fXValue / pkInfo3->m_fYValue;

        if (fRange4 != 0.0 && fNormAge3 < color2Start)
        {
            if (fNormAge3 < color1End)
            {
                pkColors8[us4].r = color1.r;
                pkColors8[us4].g = color1.g;
                pkColors8[us4].b = color1.b;
            }
            else
            {
                kFLerp1 = (fNormAge3 - color1End) / fRange4;
                pkColors8[us4].r = color1.r + (color2.r - color1.r) * kFLerp1;
                pkColors8[us4].g = color1.g + (color2.g - color1.g) * kFLerp1;
                pkColors8[us4].b = color1.b + (color2.b - color1.b) * kFLerp1;
            }
        }
        else if (fRangeVal != 0.0 && fNormAge3 > color2End)
        {
            if (fNormAge3 > color3Start)
            {
                pkColors8[us4].r = color3.r;
                pkColors8[us4].g = color3.g;
                pkColors8[us4].b = color3.b;
            }
            else
            {
                fLerp4 = (fNormAge3 - color2End) / fRangeVal;
                pkColors8[us4].r = color2.r + (color3.r - color2.r) * fLerp4;
                pkColors8[us4].g = color2.g + (color3.g - color2.g) * fLerp4;
                pkColors8[us4].b = color2.b + (color3.b - color2.b) * fLerp4;
            }
        }
        else
        {
            pkColors8[us4].r = color2.r;
            pkColors8[us4].g = color2.g;
            pkColors8[us4].b = color2.b;
        }

        if (fadeOut != 0.0 && fNormAge3 > fadeOut)
        {
            fFadeOutLerpA = (fNormAge3 - fadeOut) / (1.0f - fadeOut);
            pkColors8[us4].a = color2.a + (color3.a - color2.a) * fFadeOutLerpA;
        }
        else if (fadeIn != 0.0 && fNormAge3 < fadeIn)
        {
            fFadeInLerp3 = fNormAge3 / (float)(fadeIn);
            pkColors8[us4].a = color1.a + (color2.a - color1.a) * fFadeInLerp3;
        }
        else
        {
            pkColors8[us4].a = color2.a;
        }
    }
}

class SimpleColorModifierClone : public BSPSysSimpleColorModifier
{
public:
    SimpleColorModifierClone();
};

class SimpleColorModifierCloner : public BSPSysSimpleColorModifier
{
  public:
    void CopyMemberData(SimpleColorModifierClone* pkDest, CloningProcess& kCloning);
    SimpleColorModifierClone* CloneObject(CloningProcess& kCloning);
};

// @fnv 0x00c60670
SimpleColorModifierClone* SimpleColorModifierCloner::CloneObject(CloningProcess& kCloning)
{
    SimpleColorModifierClone* pkClone = new SimpleColorModifierClone;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

struct FUN_00c615a0_class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0c;
    void FUN_00a99b20(NiTPrimitiveArray<unsigned int>* values);
    void AppendGlobalAndFormatValues(NiTPrimitiveArray<unsigned int>* values);
};
extern "C" void* g_012043a4;
extern const char str_0109df4c[];
struct GlobalObject_00a7b610;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(GlobalObject_00a7b610* value);
char* __cdecl NiGetViewerString_00a7d510(const char* format, unsigned int value);

struct Unused20
{
    int a, b, c, d, e, f, g, h;
};
// Calls FUN_00a99b20, then appends the result of FUN_00a7d330 on g_012043a4 and of FUN_00a7d510(str_0109df4c, unk0c) to the values array.
// @fnv 0x00c615a0
void FUN_00c615a0_class::AppendGlobalAndFormatValues(NiTPrimitiveArray<unsigned int>* values)
{
    FUN_00a99b20(values);
    void* global_ptr = g_012043a4;
    unsigned int first = (unsigned int)NiViewerStrings_NiGetViewerString_Title((GlobalObject_00a7b610*)global_ptr);
    values->AddFirstEmpty(first);
    unsigned int second = (unsigned int)NiGetViewerString_00a7d510(str_0109df4c, unk0c);
    values->AddFirstEmpty(second);
    Unused20 tmp;
}

struct C639a0Cls : NiPSysModifier
{
    char pad[0x20 - sizeof(NiPSysModifier)];
    float m_20;
    bool __thiscall BSParentVelocityModifier_IsEqual(NiObject* pObject);
};
// Compares this object with pObject: first via FUN_00c31830, then checks that m_20 matches.
// @fnv 0x00c639a0
// src: XBOX_PDB 0x00c639a0
bool C639a0Cls::BSParentVelocityModifier_IsEqual(NiObject* pObject)
{
    bool bEqual = NiPSysModifier::IsEqual(pObject);
    if (bEqual)
    {
        C639a0Cls* pOther = (C639a0Cls*)pObject;
        bEqual = pOther->m_20 == m_20;
    }
    return bEqual;
}

struct FUN_00c61fc0_Item
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_0096a610_Target
{
    void FUN_0096a610(void* a1);
};

struct FUN_00c61fc0_Pad
{
    int a, b, c, d;
};

struct FUN_00c61fc0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    FUN_00c61fc0_Item** m_ppItems;
    unsigned short unk64;
    unsigned short m_iArrayLength;
    void FUN_00c31db0(void* a1);
    char* BuildAttachTypeString(const char* name, int type);
    void Serialize(void* a1);
};

void* __cdecl NiViewerStrings_NiGetViewerString_Title(int value);
int __cdecl NiGetViewerString_00a7d5e0(int* dat, int value);
extern int DAT_01063e84;

// After FUN_00c31db0, passes FUN_00a7d330's value, an "ArrayType" string for unk58, and each item's unk08 (last to first) to a1->FUN_0096a610.
// @fnv 0x00c61fc0
void FUN_00c61fc0_cls::Serialize(void* apTarget)
{
    char* ib;
    FUN_00c61fc0_Item** b;
    int mid;
    int r;
    unsigned long ptr2;
    unsigned int ra;
    int oa;
    int v1;
    long cur;
    FUN_00c61fc0_Item* x;
    long qa;
    int ta;
    void* mb;
    int xa;
    long gb;
    FUN_00c31db0(apTarget);
    v1 = *(int*)&g_012043b0;
    mb = NiViewerStrings_NiGetViewerString_Title(v1);
    ((FUN_0096a610_Target*)apTarget)->FUN_0096a610(&mb);
    xa = unk58;
    ib = BuildAttachTypeString("ArrayType", xa);
    ((FUN_0096a610_Target*)apTarget)->FUN_0096a610(&ib);
    mid = m_iArrayLength;
    while (0 != mid--)
    {
        b = &m_ppItems[mid];
        x = *b;
        if (!!x)
        {
            ra = x->unk08;
            cur = NiGetViewerString_00a7d5e0(&DAT_01063e84, ra);
            ((FUN_0096a610_Target*)apTarget)->FUN_0096a610(&cur);
        }
    }
}

extern "C" void* g_01204388;

class Base00c319e0
{
  public:
    virtual ~Base00c319e0();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();

    void FUN_00c319e0(NiTPrimitiveArray<unsigned int>* pkStrings);
};

class Mod600 : public Base00c319e0
{
  public:
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_fValue;

    void BSPSysStripUpdateModifier_GetViewerStrings(NiTPrimitiveArray<unsigned int>* pkStrings);
    virtual ~Mod600();
};

struct LocalStackSpace
{
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    int field6;
    int field7;
};

// Calls base FUN_00c319e0, then adds a name string and a string formatted from fUpdateDeltaTime and m_fValue to pkStrings.
// @fnv 0x00c60050
// src: XBOX_PDB 0x00c60050
void __thiscall Mod600::BSPSysStripUpdateModifier_GetViewerStrings(NiTPrimitiveArray<unsigned int>* pkStrings)
{
    Base00c319e0::FUN_00c319e0(pkStrings);

    GlobalObject_00a7b610* obj = (GlobalObject_00a7b610*)g_01204388;
    unsigned int uiName = (unsigned int)NiViewerStrings_NiGetViewerString_Title(obj);
    pkStrings->AddFirstEmpty(uiName);

    unsigned int uiValue = NiGetViewerString_00a7d550("fUpdateDeltaTime", m_fValue);
    pkStrings->AddFirstEmpty(uiValue);

    {
        LocalStackSpace localSpace;
        if (localSpace.field0)
        {
        }
    }
}

Base00c319e0::~Base00c319e0()
{}
void Base00c319e0::vf04()
{}
void Base00c319e0::vf08()
{}
void Base00c319e0::vf0C()
{}
void Base00c319e0::vf10()
{}
void Base00c319e0::vf14()
{}
void Base00c319e0::vf18()
{}

Mod600::~Mod600()
{}

struct SpawnHeap_cls
{
    void __thiscall MemoryManager_Deallocate(void* pObject);
};

extern "C" void* DAT_0109b220;
extern "C" char DAT_011f6238;
extern "C" void(__stdcall* DAT_00fdf1c4)(void*);
extern NiFixedString* DAT_012043a0;

// If DAT_012043a0 is set, calls DAT_00fdf1c4 on its header unless it holds DAT_0109b220, frees it via FUN_00aa4060, then sets DAT_012043a0 to 0.
// @fnv 0x00c61760
// src: GUESS 0x00c61760 (confidence: low)
void Object_UpdateFields_00c61760()
{
    NiFixedString* tmp = DAT_012043a0;
    NiFixedString* p = tmp;
    NiFixedString* result;
    unsigned int hdr;

    if (p != 0)
    {
        if (*(void**)p == DAT_0109b220)
        {
        }
        else
        {
            hdr = *(unsigned int*)p - 8;
            DAT_00fdf1c4((void*)hdr);
        }

        if ((1, 1) & 1)
        {
            reinterpret_cast<SpawnHeap_cls*>(&DAT_011f6238)->MemoryManager_Deallocate(p);
        }

        result = p;
    }
    else
    {
        result = 0;
    }

    DAT_012043a0 = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

namespace fnv_00c61990 {
extern "C" void* DAT_012043ac;
extern "C" int DAT_0109b220;

struct S61990Obj
{
    int vt;
};

// Takes the global at DAT_012043ac, decrements the count at vt-8 unless vt equals DAT_0109b220, deallocates the object, and clears the global.
// @fnv 0x00c61990
// src: GUESS 0x00c61990 (confidence: medium)
void __cdecl Runtime_ReleaseReference_00c61990()
{
    S61990Obj* ptr = (S61990Obj*)DAT_012043ac;
    S61990Obj* mgr = ptr;
    S61990Obj* beta;
    volatile long* temp;
    if (mgr != 0)
    {
        if (mgr->vt == DAT_0109b220)
        {
        }
        else
        {
            temp = (volatile long*)(mgr->vt - 8);
            InterlockedDecrement(temp);
        }
        if ((1, 1) & 1)
        {
            g_memoryManager.Deallocate(mgr);
        }
        beta = mgr;
    }
    else
    {
        beta = 0;
    }
    DAT_012043ac = 0;
}
}  // namespace fnv_00c61990

struct Pt3c64640
{
    float x;
    float y;
    float z;
    Pt3c64640()
    {}
};

extern Pt3c64640 DAT_011f426c;

struct Box0c64640
{
    unsigned short unk00;
    Pt3c64640 unk04[8];
    Pt3c64640 unk64[8];
    Box0c64640* InitializePointArrays();
};

// Sets unk00 to 0 and fills the unk04 and unk64 arrays with the global DAT_011f426c value, then returns this.
// @fnv 0x00c64640
// src: GUESS 0x00c64640 (confidence: medium)
Box0c64640* Box0c64640::InitializePointArrays()
{
    int i;
    {
        int n = 8;
        Pt3c64640* p = unk04;
        while (--n >= 0)
            p++;
    }
    {
        int m = 8;
        Pt3c64640* q = unk64;
        while (--m >= 0)
            q++;
    }
    unk00 = 0;
    for (i = 0; i < 8; i++)
    {
        unk04[i] = DAT_011f426c;
        unk64[i] = DAT_011f426c;
    }
    return this;
}

struct S_00c648a0_Map
{
    bool FUN_00853130(unsigned int, void**);
};

struct ObjectLinkStream : NiStream
{
    S_00c648a0_Map* unk5c4;
    void FUN_00a64ce0(void** link);
};

struct S_00c648a0_Base : NiObject
{
    void* unk08;
};

struct S_00c648a0 : S_00c648a0_Base
{
    void BSReference_LoadBinary(ObjectLinkStream* apStream);
};

// Calls ReadGroup, reads unk08 from the stream, looks it up in the stream's map, and passes any found object to apStream->v28.
// @fnv 0x00c648a0
// src: XBOX_PDB 0x00c648a0
void S_00c648a0::BSReference_LoadBinary(ObjectLinkStream* apStream)
{
    NiObject::LoadBinary(*apStream);
    apStream->FUN_00a64ce0(&unk08);

    void* pObject;
    {
        ObjectLinkStream* pStream = apStream;
        unsigned int uiLinkID = (unsigned int)unk08;
        void* pFound = 0;
        if (pStream->unk5c4 && uiLinkID)
            pStream->unk5c4->FUN_00853130(uiLinkID, &pFound);
        pObject = pFound;
    }
    if (pObject)
        apStream->ChangeObject(static_cast<NiObject*>(pObject));
    {
        int ReportDiagnostic;
        int unused1;
    }
}

struct FUN_00c64de0 : BSFaceGenMorphData
{
    unsigned char data[0x1c - sizeof(BSFaceGenMorphData)];
    FUN_00c64de0();
};

// Allocates a FUN_00c64de0 object, sets its name to DAT_011f49e0, and returns the new pointer.
// @fnv 0x00c652c0
// src: COMMUNITY 0x00c652c0
FUN_00c64de0* __cdecl BSAttachPoints_CreateObject()
{
    FUN_00c64de0* object = new FUN_00c64de0;
    reinterpret_cast<NiAVObject*>(object)->SetName(DAT_011f49e0);
    return object;
}

int _sprintf_s(char*, unsigned int, const char*, ...);

char* __cdecl CreateDebugString(const char* pcText);

class AttachPointName
{
  public:
    const char* m_kHandle;
    operator const char*() const
    {
        return m_kHandle;
    }
};

class AttachPoint
{
  public:
    AttachPointName m_kParent;
    AttachPointName m_kNode;
};

// NiExtraData.h does not declare its viewer-string override.
struct ExtraDataViewerEntry : NiExtraData
{
    void GetViewerStrings(NiViewerStringsArray* strings);
};

class BSAttachPoints : public ExtraDataViewerEntry
{
  public:
    int unk0c;
    AttachPoint** m_ppkPoints;
    int unk14;
    unsigned short m_usElementCount;
    void GetViewerStrings_00c65350(NiViewerStringsArray* pkStrings);
};

struct FillPad3
{
    int unk00;
    int unk04;
    int unk08;
};

struct FillPad4
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct FillPad5
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

// Appends the RTTI name and one formatted string per attach point (index, parent, node) to pkStrings.
// @fnv 0x00c65350
// src: XBOX_PDB 0x00c65350
void BSAttachPoints::GetViewerStrings_00c65350(NiViewerStringsArray* pkStrings)
{
    char acBuffer[260];
    unsigned int i;
    unsigned int kUiCount;
    AttachPoint* pkPoint;
    const char* pcParent;
    const char* pcNode2;
    ExtraDataViewerEntry::GetViewerStrings(pkStrings);
    {
        unsigned int unk0;
        const char* pcRTTIName = (const char*)DAT_012043f0;
        char* unk2;
        char* pcViewerStr = CreateDebugString(pcRTTIName);
        pkStrings->AddFirstEmpty(reinterpret_cast<const char* const&>(pcViewerStr));
        kUiCount = m_usElementCount;
        for (i = 0; i < kUiCount; i++)
        {
            {
                FillPad4 nc;
            }
            pkPoint = m_ppkPoints[i];
            const char* nb6 = pkPoint->m_kParent.m_kHandle;
            pcParent = nb6;
            const char* hNode = pkPoint->m_kNode.m_kHandle;
            pcNode2 = hNode;
            _sprintf_s(acBuffer, 260, "%d: %s - %s", i, pcParent, pcNode2);
            unk2 = acBuffer;
            pkStrings->AddFirstEmpty(reinterpret_cast<const char* const&>(unk2));
        }
    }
}

extern "C" void* VTABLE_010a0d24;
extern "C" void* VTABLE_010c38ac;
// The construction entry uses the shared layout and the original base initializer.
// @fnv 0x00c63ab0
BSDecalPlacementVectorExtraData* DecalPlacementEntries::Construct(int parameter)
{
    NiExtraData::FUN_00a7b2e0();
    *reinterpret_cast<void**>(this) = &VTABLE_010a0d24;
    m_iValue = parameter;
    *reinterpret_cast<void**>(this) = &VTABLE_010c38ac;
    int index;
    ExtraList* coordinate = &list;
    coordinate->size = 0;
    coordinate->head = 0;
    coordinate->tail = 0;
    count = 0;
    for (index = 0; index < 8; ++index)
    {
        groups[index] = 0;
    }
    return this;
}
