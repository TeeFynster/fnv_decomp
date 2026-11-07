#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPoint3.h"
#include <string.h>
#include "../../../../include/Mat3.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiGeometry.h"
#include "../../../../include/NiPSysCylinderEmitter.h"
#include "../../../../include/NiPSysEmitter.h"
#include "../../../../include/NiPSysVolumeEmitter.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiSkinInstance.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/NiPoint3.h"

inline NiTransform::NiTransform() {}
__forceinline void CopyParticlePoint(NiPoint3& output, const NiPoint3& value)
{
    memcpy(&output, &value, sizeof(output));
}
// src/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int g_01202500;

// @fnv 0x00c1f4f0
// src: COMMUNITY 0x00c1f4f0
int* __cdecl NiPSysMeshEmitter_GetRTTI()
{
    return &g_01202500;
}

// @fnv 0x00c1fa30
void NiPSysVolumeEmitter::vf43(NiAVObject* pkEmitterObj)
{
    *(NiAVObject**)((char*)this + 0x54) = pkEmitterObj;
}

extern void* g_01202508;

// @fnv 0x00c1fa40
// src: COMMUNITY 0x00c1fa40
void* __cdecl NiPSysCylinderEmitter_GetRTTI()
{
    return &g_01202508;
}

// @fnv 0x00c1f9e0
// src: XBOX_PDB 0x00c1f9e0
bool __thiscall NiPSysCylinderEmitter::IsEqual_00c1f9e0(NiAVObject* pkObject)
{
    NiPSysCylinderEmitter* pkDest = (NiPSysCylinderEmitter*)pkObject;
    if (FUN_00c31b80(pkObject) && m_fCylinderRadius == pkDest->m_fCylinderRadius &&
        m_fCylinderHeight == pkDest->m_fCylinderHeight)
        return true;
    return false;
}

extern double DAT_01011588;
extern double DAT_01016ff0;
// @fnv 0x00c1ced0
// src: GAMEBRYO_LIB 0x00c1ced0
float NiFastSqrt(float number)
{
    float y = number;
    float fHalfX = number * DAT_01011588;
    int i = *(int*)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float*)&i;
    y = y * (DAT_01016ff0 - (fHalfX * y * y));
    y = number * y;
    return y;
}

void __cdecl ReleaseObjectArray(void*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_010bd698;
extern int DAT_010bd6a0;
struct Holder31750
{
    void __thiscall FUN_00c31750();
};
struct NiPSysMeshEmitter
{
    char _pad0[0x54];
    void* m_54;
    void* m_58;
    char _pad1[0x64 - 0x5C];
    void* m_64;
    void* m_68;
    char _pad2[0x88 - 0x6C];
    void* __thiscall Destroy(unsigned int);
};
// @fnv 0x00c1f500
void* __thiscall NiPSysMeshEmitter::Destroy(unsigned int flags)
{
    void* tmp1 = m_68;
    m_64 = (void*)&DAT_010bd6a0;
    ReleaseObjectArray(tmp1);
    void* tmp2 = m_58;
    m_54 = (void*)&DAT_010bd698;
    ReleaseObjectArray(tmp2);
    ((Holder31750*)this)->FUN_00c31750();
    if (flags & 1)
        _delete(this, 0x88);
    return this;
}

class NiFixedString;
class NiObject;
class NiSearchPath;
class NiTexture;
namespace fnv_00c1f990 {
struct NiObjectGroup;
struct NiThread;
using ::NiMemObject;
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct NiPSysMeshEmitter : NiPSysEmitter
{
    struct GeomEmitterArray
    {
        void FUN_00c1e9a0(unsigned int);
    } m_kGeometryEmitters;
    void SetSkinGeom(NiGeometry*);
    void LinkObject_00c1f990(NiStream&);
};
// @fnv 0x00c1f990
// src: XBOX_PDB 0x00c1f990
void NiPSysMeshEmitter::LinkObject_00c1f990(NiStream& kStream)
{
    NiPSysEmitter::LinkObject(kStream);
    unsigned int uiSize = kStream.GetLinkID();
    unsigned int i;
    NiGeometry* pkChild;
    if (uiSize != 0)
    {
        m_kGeometryEmitters.FUN_00c1e9a0(uiSize);
        for (i = 0; i < uiSize; i++)
        {
            pkChild = (NiGeometry*)kStream.GetLoadedObject();
            SetSkinGeom(pkChild);
        }
    }
}
}  // namespace fnv_00c1f990

struct NiSkinnedEmitterData
{
    char _pad[4];
};

int __cdecl GetRandomNumber(void);
extern double DAT_01029790;

struct FUN_00c1f5f0_shell : NiPSysMeshEmitter
{
    void __thiscall PickRandomVertex(NiGeometry*, NiPoint3&, NiPoint3&);
    void __thiscall PickEmitterParticle(NiGeometry*, NiPoint3&, NiPoint3&);
    void __thiscall GetRandomEmitterParticle(NiSkinInstance*, NiGeometry*, NiPoint3&, NiPoint3&);
    void __thiscall NiPSysMeshEmitter_EmitFromSkinnedEdge(NiSkinInstance*, NiGeometry*, NiPoint3&, NiPoint3&);
    void __thiscall SampleSkinPartitionTriangle(NiSkinInstance*, NiGeometry*, NiPoint3&, NiPoint3&);
    void __thiscall EmitFromMesh(NiGeometry*, NiPoint3&, NiPoint3&);

    void __thiscall NiPSysMeshEmitter_ComputeInitialPositionAndVelocity(NiPoint3& kPosition, NiPoint3& kMotionVelocity);
};

// @fnv 0x00c1f5f0
// src: XBOX_PDB 0x00c1f5f0
void __thiscall FUN_00c1f5f0_shell::NiPSysMeshEmitter_ComputeInitialPositionAndVelocity(NiPoint3& kPosition, NiPoint3& kMotionVelocity)
{
    unsigned int uiEmitterIndex;
    NiGeometry* pkGeomEmitter;
    unsigned int uiGeometryEmitterCount;
    NiSkinInstance* pkSkin;
    NiSkinnedEmitterData* pkEmitData;

    uiGeometryEmitterCount = *(unsigned short*)((char*)this + 0x60);
    if (!uiGeometryEmitterCount)
        return;

    {
        float fRandom = GetRandomNumber() / DAT_01029790;
        uiEmitterIndex = (unsigned int)(fRandom * uiGeometryEmitterCount);
    }

    if (uiEmitterIndex == uiGeometryEmitterCount)
        uiEmitterIndex = uiGeometryEmitterCount - 1;

    if (uiEmitterIndex >= *(unsigned short*)((char*)this + 0x60))
        return;

    pkGeomEmitter = ((NiGeometry**)m_58)[uiEmitterIndex];
    if (!pkGeomEmitter)
        return;

    pkEmitData = reinterpret_cast<NiSkinnedEmitterData*>(pkGeomEmitter->m_spSkinInstance.m_pObject);

    if (uiEmitterIndex < *(unsigned short*)((char*)this + 0x70))
        pkSkin = ((NiSkinInstance**)m_68)[uiEmitterIndex];
    else
        pkSkin = 0;

    if (pkEmitData && pkSkin && !pkSkin->m_pSkinData.m_pObject)
        pkSkin->EnsureSkinPartition(pkGeomEmitter);

    switch (*(int*)((char*)this + 0x78))
    {
    case 1:
    case 3:
        if (pkEmitData)
        {
            NiPSysMeshEmitter_EmitFromSkinnedEdge(pkSkin, pkGeomEmitter, kPosition, kMotionVelocity);
            return;
        }
        EmitFromMesh(pkGeomEmitter, kPosition, kMotionVelocity);
        return;

    case 2:
    case 4:
        if (pkEmitData)
        {
            SampleSkinPartitionTriangle(pkSkin, pkGeomEmitter, kPosition, kMotionVelocity);
            return;
        }
        PickEmitterParticle(pkGeomEmitter, kPosition, kMotionVelocity);
        return;

    default:
        if (pkEmitData)
        {
            GetRandomEmitterParticle(pkSkin, pkGeomEmitter, kPosition, kMotionVelocity);
            return;
        }
        PickRandomVertex(pkGeomEmitter, kPosition, kMotionVelocity);
        return;
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int);

struct SkinData_c1d170
{
    int unk[17];
    unsigned int m_uiBoneCount;
};

struct Partition_c1d170
{
    int unk[4];
    Partition_c1d170() throw();
    bool MakePartitions(void* pkModelData, SkinData_c1d170* pkSkinData, unsigned int uiBonesPerPartition,
                        unsigned int uiBonesPerVertex, unsigned int uiStart, bool bForce, bool barg7, bool barg8);
    static void* __cdecl operator new(unsigned int s) throw()
    {
        return Object_DispatchCommandFour(s);
    }
};

struct Ptr_c1d170
{
    Partition_c1d170* m_pObject;
    Ptr_c1d170& operator=(Partition_c1d170* p);
};

struct Host_c1d170
{
    int unk00;
    int unk04;
    Ptr_c1d170 m_spPartition;
    bool EnsureSkinPartition(NiGeometry* pkGeometry);
};

// Validates the geometry and its skin instance, builds a partition from the skin data if missing, stores it in m_spPartition and returns whether it succeeded.
// @fnv 0x00c1d170
bool Host_c1d170::EnsureSkinPartition(NiGeometry* pkGeometry)
{
    if (!pkGeometry || !static_cast<NiObject*>(pkGeometry)->IsTriBasedGeometry())
        return false;
    NiSkinInstance* pkSkin = pkGeometry->m_spSkinInstance.m_pObject;
    if (pkSkin)
    {
        Partition_c1d170* pkPartition = reinterpret_cast<Partition_c1d170*>(pkSkin->m_pkSkinMeshPartition.m_pObject);
        if (!pkPartition)
        {
            if (!pkSkin->m_pSkinData.m_pObject)
                return false;
            unsigned int uiBonesPerPartition = reinterpret_cast<SkinData_c1d170*>(pkSkin->m_pSkinData.m_pObject)->m_uiBoneCount;
            if (uiBonesPerPartition < 4)
                uiBonesPerPartition = 4;
            pkPartition = new Partition_c1d170();
            if (!pkPartition->MakePartitions(pkGeometry->m_spModelData.m_pObject, reinterpret_cast<SkinData_c1d170*>(pkSkin->m_pSkinData.m_pObject), uiBonesPerPartition, 4, 0,
                                             false, false, false))
                return false;
        }
        m_spPartition = pkPartition;
        return true;
    }
    return false;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* sizes,
                                                 unsigned int count)
{
    unsigned int written = m_pfnWrite(this, p, n, sizes, count);
    m_uiAbsoluteCurrentPos += written;
    return written;
}

class C1E8E0Object;

template <class T>
inline void NiBinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void C1E8E0SaveBinary(NiStream& kStream, const T& value)
{
    NiBinaryStreamSave(*(*reinterpret_cast<NiBinaryStream**>((char*)&kStream + 0x250)), &value);
}

class NiColorSaveHelper
{
  public:
    float r;
    float g;
    float b;

    void SaveBinary(NiStream& kStream);
};

class Stub_00c31b60
{
  public:
    void* m_ppVirtualMethodTable;
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

    void NiPSysEmitter_SaveBinary(void* pkStream);
};

class C1E8E0Controller : public Stub_00c31b60
{
  public:
    C1E8E0Object** m_ppkObjects;
    unsigned short unk5C;
    unsigned short m_usObjectCount;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    float m_fValue0;
    float m_fValue1;
    NiColorSaveHelper m_kFogTint;

    void NiPSysMeshEmitter_SaveBinary(NiStream& kStream);
};

// Writes the object count, each object's link ID, m_fValue0, m_fValue1 and the color helper to the stream.
// @fnv 0x00c1e8e0
// src: XBOX_PDB 0x00c1e8e0
void C1E8E0Controller::NiPSysMeshEmitter_SaveBinary(NiStream& kStream)
{
    NiPSysEmitter_SaveBinary(&kStream);
    unsigned int uiObjectCount = m_usObjectCount;
    C1E8E0SaveBinary(kStream, uiObjectCount);
    for (unsigned int i = 0; i < uiObjectCount; i++)
        kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_ppkObjects[i]));
    C1E8E0SaveBinary(kStream, m_fValue0);
    C1E8E0SaveBinary(kStream, m_fValue1);
    m_kFogTint.SaveBinary(kStream);
}

// Receive the matrix result through its original explicit output argument.
// The shared NiPoint3 return type has a nontrivial copy constructor.
typedef NiPoint3 (NiMatrix3::*SharedRotatePoint)(const NiPoint3&) const;
typedef NiPoint3* (NiMatrix3::*ParticleRotatePoint)(NiPoint3*, const NiPoint3*) const;
inline NiPoint3 NiPoint3::operator*(float scalar) const
{
    NiPoint3 result;
    result.x = x * scalar;
    result.y = y * scalar;
    result.z = z * scalar;
    return result;
}
struct MeshEmitter_c1cf50
{
    int unk00, unk04, unk08, unk0c;
    NiAVObject* object;
    int unk14;
    float speed, speedVariation;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70;
    int velocityMode;
    int unk78;
    NiPoint3 direction;
    void ComputeEmitterParticleTransform(NiAVObject* geometry, NiPoint3& position, NiPoint3& velocity);
};
// Transforms position into the emitter object's space and computes velocity from velocityMode using the geometry's world transform and random values.
// @fnv 0x00c1cf50
void MeshEmitter_c1cf50::ComputeEmitterParticleTransform(NiAVObject* geometry, NiPoint3& arPosition,
                                                         NiPoint3& arVelocity)
{
    if (!geometry)
        return;
    NiTransform geometryWorld; memcpy(&geometryWorld, &geometry->m_kWorld, sizeof(geometryWorld));
    NiTransform transform; memcpy(&transform, &object->m_kWorld, sizeof(transform));
    NiTransform inverseWorld;
    transform.FUN_004b4880(inverseWorld);
    inverseWorld.FUN_0062c250(&transform, geometryWorld);
    struct ParticleScratch { NiPoint3 scaled; NiPoint3 rotated; } scratch;
    { NiPoint3* value = transform.ComputeValue_00524c40(reinterpret_cast<NiPoint3*>(&scratch.rotated), reinterpret_cast<const NiPoint3&>(arPosition)); memcpy(&arPosition, value, sizeof(arPosition)); }
    switch (velocityMode)
    {
    case 0:
        { NiPoint3* value = (transform.m_Rotate.*reinterpret_cast<ParticleRotatePoint>(static_cast<SharedRotatePoint>(&NiMatrix3::operator*)))(&scratch.scaled, &arVelocity); memcpy(&arVelocity, value, sizeof(arVelocity)); }
        break;
    case 1:
        arVelocity.x = (GetRandomNumber() * 2.0 / DAT_01029790) - 1.0;
        arVelocity.y = (GetRandomNumber() * 2.0 / DAT_01029790) - 1.0;
        arVelocity.z = (GetRandomNumber() * 2.0 / DAT_01029790) - 1.0;
        arVelocity.Unitize_004a0c10();
        {
            float random = (float)(GetRandomNumber() / DAT_01029790);
            float magnitude = speed + speedVariation * (random - DAT_01011588);
            arVelocity.x *= magnitude; arVelocity.y *= magnitude; arVelocity.z *= magnitude;
        }
        break;
    case 2: {
        NiPoint3& v = scratch.rotated; (transform.m_Rotate.*reinterpret_cast<ParticleRotatePoint>(static_cast<SharedRotatePoint>(&NiMatrix3::operator*)))(&v, &direction);
        float random = (float)(GetRandomNumber() / DAT_01029790);
        float magnitude = speed + speedVariation * (random - DAT_01011588);
        v.Unitize_004a0c10();
        scratch.scaled.x = v.x * magnitude;
        scratch.scaled.y = v.y * magnitude;
        scratch.scaled.z = v.z * magnitude;
        memcpy(&arVelocity, &scratch.scaled, sizeof(arVelocity));
    }
    break;
    }
}

struct Sub54_c1f880
{
    int unk00;
    void FUN_00c1e9a0(unsigned short arg);
};

struct Emit_c1f880
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
    Sub54_c1f880 unk54;
    int unk58;
    unsigned short unk5C;
    unsigned short unk5E;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    NiPoint3 vec7C;
    Emit_c1f880* FUN_00c1f550();
    void CopyTo(Emit_c1f880* pkEmitter, unsigned int uiArg);
    Emit_c1f880* NiPSysMeshEmitter_CreateClone(unsigned int uiArg);
};

// @fnv 0x00c1f880
// src: XBOX_PDB 0x00c1f880
Emit_c1f880* Emit_c1f880::NiPSysMeshEmitter_CreateClone(unsigned int uiArg)
{
    Emit_c1f880* pkNew = (Emit_c1f880*)Object_DispatchCommandFour(0x88);
    Emit_c1f880* pkResult;
    if (pkNew != 0)
    {
        pkResult = pkNew->FUN_00c1f550();
    }
    else
    {
        pkResult = 0;
    }
    CopyTo(pkResult, uiArg);
    pkResult->unk54.FUN_00c1e9a0(unk5E);
    pkResult->unk74 = unk74;
    pkResult->unk78 = unk78;
    memcpy(&pkResult->vec7C, &vec7C, sizeof(vec7C));
    return pkResult;
}

// Factory: allocates a 0x88-byte NiPSysMeshEmitter and runs its out-of-line constructor (FUN_00c1f550).
struct NiPSysMeshEmitterObject
{
    static void* __cdecl operator new(unsigned int);
    NiPSysMeshEmitterObject() throw();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
};

// @fnv 0x00c1f970
NiPSysMeshEmitterObject* __cdecl CreateNiPSysMeshEmitterObject()
{
    return new NiPSysMeshEmitterObject;
}

extern "C" void __cdecl FUN_00c31750();

// @fnv 0x00c1fa20
// src: GUESS 0x00c1fa20 (confidence: low)
void __cdecl Object_ForwardCall_00c1fa20()
{
    FUN_00c31750();
}

struct Sub4880
{
    void __thiscall FUN_004b4880(void* p);
};
struct Holder68
{
    unsigned int unk00;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    Sub4880 m_68;
};
struct BoneEntry
{
    NiTransform transform;
    NiPoint3 center;
    float radius;
    unsigned short count;
    unsigned short flags;
    void* weights;
};
struct BoneHead
{
    int m_00;
    int m_04;
    int m_08;
    NiTransform m_0c;
    BoneEntry* m_40;
};
struct ArrObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    NiPoint3* m_20;
    NiPoint3* m_24;
};
struct Arg3Obj
{
    unsigned int unk00;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    ArrObj* m_b8;
};
struct SceneBone
{
    unsigned int unk00;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    NiTransform world;
};
struct Arg4Obj
{
    void* m_00;
    void* m_04;
    BoneHead* m_08;
    void* m_0c;
    Holder68* m_10;
    SceneBone** m_14;
};
struct Arg5Obj
{
    int m_00;
    unsigned short* m_04;
    float* m_08;
    unsigned short* m_0c;
    unsigned char* m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    unsigned short m_24;
};
extern NiPoint3 DAT_011f426c;
struct AccObj
{
    NiPoint3 a1;
    NiPoint3 a2;
    __declspec(noalias) void __thiscall Unitize_004a0c10();
};
struct LoopPair
{
    NiPoint3 first;
    NiPoint3 second;
};

NiPoint3 operator*(const NiPoint3& a, float f)
{
    NiPoint3 r;
    r.x = a.x * f;
    r.y = a.y * f;
    r.z = a.z * f;
    return r;
}
NiPoint3& operator+=(NiPoint3& a, const NiPoint3& b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
void scale(NiPoint3& r, const NiPoint3& a, float f)
{
    r.x = a.x * f;
    r.y = a.y * f;
    r.z = a.z * f;
}
// Accumulates weighted transformed positions and normals for the selected vertex, then writes the results to the output vectors.
// @fnv 0x00c1d230
void __stdcall SkinVertex(NiPoint3* outPos, NiPoint3* outVel, Arg3Obj* arg3, Arg4Obj* arg4, Arg5Obj* arg5, int vert)
{
    BoneHead* skin = arg4->m_08;
    NiTransform c;
    arg4->m_10->m_68.FUN_004b4880((void*)&c);
    NiTransform ptr;
    { NiTransform result; memcpy(&ptr, skin->m_0c.FUN_0062c250(&result, c), sizeof(ptr)); }
    BoneEntry* bones = skin->m_40;
    AccObj acc;
    LoopPair scratch;
    memcpy(&acc.a2, &DAT_011f426c, sizeof(acc.a2));
    memcpy(&acc.a1, &DAT_011f426c, sizeof(acc.a1));
    const ArrObj* __restrict pwv = arg3->m_b8;
    const NiPoint3* positions = pwv->m_20;
    const NiPoint3* normals = pwv->m_24;
    unsigned int loopT = arg5->m_0c[vert];
    NiPoint3 pForm;
    CopyParticlePoint(pForm, positions[loopT]);
    NiPoint3 cnt;
    if (normals)
    {
        CopyParticlePoint(cnt, normals[loopT]);
    }
    else
    {
        NiPoint3 fallback;
        fallback.x = 1.0f;
        fallback.y = 0.0f;
        fallback.z = 0.0f;
        memcpy(&cnt, &fallback, sizeof(cnt));
    }
    unsigned long idx;
    idx = arg5->m_24;
    unsigned int r = 0;
    if (0 < idx)
    {
        do
        {
            unsigned short bindDir;
            if (arg5->m_10)
            {
                bindDir = arg5->m_04[arg5->m_10[idx * vert + r]];
            }
            else
            {
                bindDir = arg5->m_04[r];
            }
            NiTransform* res = &arg4->m_14[bindDir]->world;
            NiTransform* wv = &bones[bindDir].transform;
            unsigned int matrixStorage[sizeof(Mat3) / sizeof(unsigned int)];
            Mat3& ls = *reinterpret_cast<Mat3*>(matrixStorage);
            { NiTransform first, result; memcpy(&c, ptr.FUN_0062c250(&first, *res)->FUN_0062c250(&result, *wv), sizeof(c)); }
            NiTransform& a = c;
            Mat3& elemT = ls;
            elemT.m00 = a.m_Rotate.m_pEntry[0][0] * a.m_fScale;
            elemT.m01 = a.m_Rotate.m_pEntry[0][1] * a.m_fScale;
            elemT.m02 = a.m_Rotate.m_pEntry[0][2] * a.m_fScale;
            elemT.m10 = a.m_Rotate.m_pEntry[1][0] * a.m_fScale;
            elemT.m11 = a.m_Rotate.m_pEntry[1][1] * a.m_fScale;
            elemT.m12 = a.m_Rotate.m_pEntry[1][2] * a.m_fScale;
            elemT.m20 = a.m_Rotate.m_pEntry[2][0] * a.m_fScale;
            elemT.m21 = a.m_Rotate.m_pEntry[2][1] * a.m_fScale;
            elemT.m22 = a.m_Rotate.m_pEntry[2][2] * a.m_fScale;
            float val = arg5->m_08[vert * 4 + r];
            NiPoint3 accB;
            accB.x = elemT.m00 * pForm.x + elemT.m01 * pForm.y + elemT.m02 * pForm.z + a.m_Translate.x;
            accB.y = elemT.m10 * pForm.x + elemT.m11 * pForm.y + elemT.m12 * pForm.z + a.m_Translate.y;
            accB.z = elemT.m20 * pForm.x + elemT.m21 * pForm.y + elemT.m22 * pForm.z + a.m_Translate.z;
            scratch.second.x = a.m_Rotate.m_pEntry[0][0] * cnt.x + a.m_Rotate.m_pEntry[0][1] * cnt.y + a.m_Rotate.m_pEntry[0][2] * cnt.z;
            scratch.second.y = cnt.x * a.m_Rotate.m_pEntry[1][0] + a.m_Rotate.m_pEntry[1][1] * cnt.y + a.m_Rotate.m_pEntry[1][2] * cnt.z;
            scratch.second.z = a.m_Rotate.m_pEntry[2][0] * cnt.x + a.m_Rotate.m_pEntry[2][1] * cnt.y + a.m_Rotate.m_pEntry[2][2] * cnt.z;
            scale(scratch.first, accB, val);
            operator+=(acc.a2, scratch.first);
            NiPoint3 kIter;
            CopyParticlePoint(kIter, operator*(scratch.second, val));
            operator+=(acc.a1, kIter);
            ++r;
            idx = arg5->m_24;
        } while (r < idx);
    }
    acc.Unitize_004a0c10();
    memcpy(&*outPos, &acc.a2, sizeof(*outPos));
    memcpy(&*outVel, &acc.a1, sizeof(*outVel));
}

namespace fnv_00c1dec0 {
struct GeometryVirtual
{
    virtual void virt00();
    virtual void virt04();
    virtual void virt08();
    virtual void virt0c();
    virtual void virt10();
    virtual void virt14();
    virtual void virt18();
    virtual int IsReady();
};
struct SkinRecord
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned short vertexCount;
    unsigned short unk1e;
    int unk20, unk24, unk28;
};
struct SkinContainer
{
    int unk00, unk04;
    unsigned short recordCount, unk0a;
    SkinRecord* records;
};
struct GeometryExtra
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int hasData;
};
struct SkinGeometry : GeometryVirtual
{
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4;
    GeometryExtra* extra;
    NiSkinnedEmitterData* emitterData;
};
struct SkinInst
{
    int unk00, unk04;
    SkinContainer* container;
};
extern int __cdecl FUN_00ecadb8();
inline float UnitRandom()
{
    return float(double(FUN_00ecadb8()) / DAT_01029790);
}

extern NiPoint3 DAT_011f426c;
NiPoint3 __cdecl FUN_004a3760(float, const NiPoint3&);
struct SkinEmitter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    void __thiscall SkinVertex(NiPoint3*, NiPoint3*, SkinGeometry*, NiSkinnedEmitterData*, SkinRecord*, int);
    void __thiscall ComputeEmitterParticleTransform(SkinGeometry*, NiPoint3&, NiPoint3&);
    bool GetRandomEmitterParticle(SkinInst* skin, SkinGeometry* geometry, NiPoint3& position, NiPoint3& velocity);
};
// Picks a random skin record and vertex, computes a particle position and velocity, and transforms them into emitter space.
// @fnv 0x00c1dec0
bool SkinEmitter::GetRandomEmitterParticle(SkinInst* skin, SkinGeometry* geometry, NiPoint3& position, NiPoint3& velocity)
{
    if (!geometry || !geometry->IsReady())
        return false;
    SkinContainer* container = skin->container;
    if (!container)
        return false;
    unsigned short count = container->recordCount;
    float randomRecord = UnitRandom();
    int recordIndex = (int)(unsigned int)(randomRecord * count);
    if (recordIndex >= int(count) - 1)
        recordIndex = int(count) - 1;
    SkinRecord* record = &skin->container->records[recordIndex];
    float randomVertex = UnitRandom();
    NiSkinnedEmitterData* data = geometry->emitterData;
    if (!data)
        return false;
    {
        NiPoint3 localVelocity;
        {
            NiPoint3 localPosition = DAT_011f426c;
            memcpy(&localVelocity, &DAT_011f426c, sizeof(localVelocity));
            SkinVertex(&localPosition, &localVelocity, geometry, data, record,
                       (int)(unsigned int)((record->vertexCount - 1) * randomVertex));
            memcpy(&position, &localPosition, sizeof(position));
        }
        if (unk74 == 0 && geometry->extra->hasData != 0)
        {
            float length = velocity.FUN_00457990();
            CopyParticlePoint(velocity, FUN_004a3760(length, localVelocity));
        }
    }
    ComputeEmitterParticleTransform(geometry, position, velocity);
    return true;
}
}  // namespace fnv_00c1dec0

int __cdecl FUN_00ecadb8();
float __cdecl Object_ProcessAndReturnValue_00639780();
void __cdecl NiPoint3_UnitizeVector(NiPoint3*);
NiPoint3 __cdecl FUN_004a3760(float, const NiPoint3&);
extern NiPoint3 NiPoint3_ZERO;

struct Partition
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short* m_pusTriList;
    int unk18;
    unsigned short unk1C;
    unsigned short m_usTriangles;
    unsigned short unk20;
    unsigned short m_usStrips;
    int unk24;
    int unk28;
};

struct MySkinPartition
{
    int unk00;
    int unk04;
    unsigned short m_usPartitions;
    unsigned short unk0A;
    Partition* m_pPartitions;
};

struct MySkinInstance
{
    int unk00;
    int unk04;
    MySkinPartition* m_pkSkinMeshPartition;
};

struct MyGeomVtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void* GetModelData();
};

struct MyPoint3 : NiPoint3
{
    MyPoint3()
    {}
    MyPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    MyPoint3 operator+(const MyPoint3& pt) const
    {
        return MyPoint3(x + pt.x, y + pt.y, z + pt.z);
    }
    MyPoint3 operator-(const MyPoint3& pt) const
    {
        return MyPoint3(x - pt.x, y - pt.y, z - pt.z);
    }
    MyPoint3 operator*(float f) const
    {
        return MyPoint3(x * f, y * f, z * f);
    }
    NiPoint3 __thiscall ProcessAndReturnValue_0053d280(float) const;
    float __thiscall FUN_00457990();
};

struct EmitterAccessor
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
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int m_iEmissionDirection;
    int m_iEmissionType;

    bool __thiscall GetRandomEmitterParticle(NiSkinInstance* pkSkinInstance, NiGeometry* pkGeometry,
                                             NiPoint3& kPosition, NiPoint3& kMotionVelocity);
    __declspec(noalias) bool __thiscall SkinVertex(NiPoint3& kPosition, NiPoint3& kNormal, NiGeometry* pkGeometry,
                                                   NiSkinnedEmitterData* pkData, Partition* pkPartition,
                                                   unsigned int m_usVertexId);
    bool __thiscall ComputeEmitterParticleTransform(NiGeometry* pkGeometry, NiPoint3& kPosition,
                                                    NiPoint3& kMotionVelocity);

    bool __thiscall SampleSkinPartitionTriangle(NiSkinInstance* pkSkinInstance, NiGeometry* pkGeometry, NiPoint3& kPosition,
                                 NiPoint3& kMotionVelocity);
};

// Picks a random skin partition and triangle, samples two vertices and normals, computes a position, and may update motion velocity.
// @fnv 0x00c1e4e0
// src: GUESS 0x00c1e4e0 (confidence: medium)
bool EmitterAccessor::SampleSkinPartitionTriangle(NiSkinInstance* pkSkinInstance, NiGeometry* pkGeometry, NiPoint3& kPosition,
                                   NiPoint3& kMotionVelocity)
{
    if (!pkGeometry || !((MyGeomVtbl*)pkGeometry)->GetModelData())
        return false;

    if (!((MySkinInstance*)pkSkinInstance)->m_pkSkinMeshPartition)
        return false;

    unsigned short usPartitions = ((MySkinInstance*)pkSkinInstance)->m_pkSkinMeshPartition->m_usPartitions;
    float fRand = (float)(FUN_00ecadb8() / DAT_01029790);
    unsigned int uiPartition = (unsigned int)(fRand * (int)usPartitions);
    int iMaxPartition = (int)usPartitions - 1;
    if ((int)uiPartition >= iMaxPartition)
        uiPartition = iMaxPartition;

    Partition* pkPartition = &((MySkinInstance*)pkSkinInstance)->m_pkSkinMeshPartition->m_pPartitions[uiPartition];
    if (!pkPartition->m_usTriangles)
        return this->GetRandomEmitterParticle(pkSkinInstance, pkGeometry, kPosition, kMotionVelocity);

    unsigned int uiTriangle = (unsigned int)(pkPartition->m_usTriangles * Object_ProcessAndReturnValue_00639780());
    int iMaxTriangle = (int)pkPartition->m_usTriangles - 1;
    if ((int)uiTriangle >= iMaxTriangle)
        uiTriangle = iMaxTriangle;

    NiSkinnedEmitterData* pkData = reinterpret_cast<NiSkinnedEmitterData*>(pkGeometry->m_spSkinInstance.m_pObject);
    if (!pkData)
        return false;

    unsigned int usV0, usV1, usV2;
    if (pkPartition->m_usStrips)
    {
        usV0 = pkPartition->m_pusTriList[uiTriangle];
        usV1 = pkPartition->m_pusTriList[uiTriangle + 1];
        usV2 = pkPartition->m_pusTriList[uiTriangle + 2];
    }
    else
    {
        usV0 = pkPartition->m_pusTriList[3 * uiTriangle];
        usV1 = pkPartition->m_pusTriList[3 * uiTriangle + 1];
        usV2 = pkPartition->m_pusTriList[3 * uiTriangle + 2];
    }

    switch (FUN_00ecadb8() % 3)
    {
    case 1:
        usV0 = usV1;
        usV1 = usV2;
        break;
    case 2:
        usV1 = usV2;
        break;
    }

    NiPoint3 kPos0 = NiPoint3_ZERO;
    NiPoint3 kNorm0 = NiPoint3_ZERO;
    NiPoint3 kPos1 = NiPoint3_ZERO;
    NiPoint3 kNorm1 = NiPoint3_ZERO;

    this->SkinVertex(kPos0, kNorm0, pkGeometry, pkData, pkPartition, usV0);
    this->SkinVertex(kPos1, kNorm1, pkGeometry, pkData, pkPartition, usV1);
    {
        NiPoint3 kTmp = ((MyPoint3&)kPos0 + (MyPoint3&)kPos1).ProcessAndReturnValue_0053d280(2.0f);
        memcpy(&kPosition, &kTmp, sizeof(kPosition));
    }

    if (this->m_iEmissionDirection == 0)
    {
        NiPoint3 kNormal = ((MyPoint3&)kNorm0 + (MyPoint3&)kNorm1).ProcessAndReturnValue_0053d280(2.0f);
        NiPoint3_UnitizeVector(&kNormal);
        float fSpeed = ((MyPoint3*)&kMotionVelocity)->FUN_00457990();
        CopyParticlePoint(kMotionVelocity, FUN_004a3760(fSpeed, kNormal));
    }

    if (this->m_iEmissionType == 4)
    {
        CopyParticlePoint(kPosition, ((MyPoint3&)kPos1 - (MyPoint3&)kPos0) * Object_ProcessAndReturnValue_00639780() + (MyPoint3&)kPos0);
    }

    this->ComputeEmitterParticleTransform(pkGeometry, kPosition, kMotionVelocity);
    return true;
}

extern int g_01202500;
struct EmitterObject
{
    int unk00;
    int unk04;
    const char* m_kName;
};

struct MeshViewerStringsArray
{
    void* m_ppVirtualMethodTable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& pcString);

    __forceinline unsigned int Add(char* pcString)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcString);
        return uiIndex;
    }

    __forceinline void AddAxis(char* pcString)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        if (uiIndex >= m_usSize)
        {
            m_usSize = uiIndex + 1;
            if (pcString)
                m_usESize++;
        }
        else
        {
            if (pcString)
            {
                if (!m_pBase[uiIndex])
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex])
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = pcString;
    }
};

char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);
char* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);

struct Standin_VolumeEmitter
{
    void NiPSysEmitter_GetViewerStrings(MeshViewerStringsArray* pkStrings);
};

struct MeshEmitter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    EmitterObject** m_ppkEmitterObjs;
    int unk5c;
    unsigned short m_usNumEmitterObjs;
    unsigned short unk62;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    unsigned int m_eInitVelocityType;
    unsigned int m_eEmissionType;
    NiPoint3 m_kEmissionAxis;

    unsigned int GetEmitterObjCount() const
    {
        return m_usNumEmitterObjs;
    }

    EmitterObject* GetEmitterObj(unsigned int i) const
    {
        if (i < m_usNumEmitterObjs)
            return m_ppkEmitterObjs[i];
        return 0;
    }

    void WriteToViewerStrings(MeshViewerStringsArray* pkStrings);
};

// Appends emitter object names, emission type, initial velocity type, and emission axis values to pkStrings.
// @fnv 0x00c1f050
void MeshEmitter::WriteToViewerStrings(MeshViewerStringsArray* pkStrings)
{
    ((Standin_VolumeEmitter*)this)->NiPSysEmitter_GetViewerStrings(pkStrings);

    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title((char*)g_01202500));

    unsigned int i = 0;
    while (i < GetEmitterObjCount())
    {
        EmitterObject* pkObj = GetEmitterObj(i);
        if (pkObj)
        {
            const char* pcObjName = pkObj->m_kName;
            pkStrings->Add(NiGetViewerString_00a7d5e0("Emitter Object", pcObjName));
        }
        i++;
    }

    switch (m_eEmissionType)
    {
    case 0:
        pkStrings->Add(NiGetViewerString_00a7d5e0("m_eEmissionType", "NI_EMIT_FROM_VERTICES"));
        break;
    case 1:
        pkStrings->Add(NiGetViewerString_00a7d5e0("m_eEmissionType", "NI_EMIT_FROM_FACE_CENTER"));
        break;
    case 2:
        pkStrings->Add(NiGetViewerString_00a7d5e0("m_eEmissionType", "NI_EMIT_FROM_EDGE_CENTER"));
        break;
    case 3:
        pkStrings->Add(NiGetViewerString_00a7d5e0("m_eEmissionType", "NI_EMIT_FROM_FACE_SURFACE"));
        break;
    case 4:
        pkStrings->Add(NiGetViewerString_00a7d5e0("m_eEmissionType", "NI_EMIT_FROM_EDGE_SURFACE"));
        break;
    default:
        pkStrings->Add(NiGetViewerString_00a7d5e0("m_eEmissionType", "UNKNOWN!!!"));
        break;
    }

    switch (m_eInitVelocityType)
    {
    case 0:
        pkStrings->Add(NiGetViewerString_00a7d5e0("m_eInitVelocityType", "NI_VELOCITY_USE_NORMALS"));
        break;
    case 1:
        pkStrings->Add(NiGetViewerString_00a7d5e0("m_eInitVelocityType", "NI_VELOCITY_USE_RANDOM"));
        break;
    case 2:
        pkStrings->Add(NiGetViewerString_00a7d5e0("m_eInitVelocityType", "NI_VELOCITY_USE_DIRECTION"));
        break;
    default:
        pkStrings->Add(NiGetViewerString_00a7d5e0("m_eInitVelocityType", "UNKNOWN!!!"));
        break;
    }

    pkStrings->AddAxis(NiGetViewerString_00a7d550("m_kEmissionAxis.x", m_kEmissionAxis.x));
    pkStrings->AddAxis(NiGetViewerString_00a7d550("m_kEmissionAxis.y", m_kEmissionAxis.y));
    pkStrings->AddAxis(NiGetViewerString_00a7d550("m_kEmissionAxis.z", m_kEmissionAxis.z));
}

struct CmpItem
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual bool vCompare(CmpItem* other);
};

struct CmpSub
{
    bool FUN_00439090(void* other);
};

struct FUN_00c1d6b0_cls
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
    CmpItem** m_58;
    short unk5C;
    unsigned short m_5E;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int m_74;
    int m_78;
    CmpSub m_7C;

    bool Equals(FUN_00c1d6b0_cls* other);
    bool IsEquivalent(FUN_00c1d6b0_cls* other);
};

// Returns false on failed equality, count, item, or integer-field checks; otherwise returns the negation of m_7C.FUN_00439090.
// @fnv 0x00c1d6b0
bool FUN_00c1d6b0_cls::IsEquivalent(FUN_00c1d6b0_cls* other)
{
    if (!Equals(other))
        return false;
    unsigned int otherCount = other->m_5E;
    unsigned int count = m_5E;
    if (count != otherCount)
        return false;
    for (unsigned int i = 0; i < count; i++)
    {
        CmpItem* a = m_58[i];
        CmpItem* b = other->m_58[i];
        if (a != 0 && b == 0)
            return false;
        if (a == 0 && b != 0)
            return false;
        if (a != 0 && !a->vCompare(b))
            return false;
    }
    if (m_74 != other->m_74)
        return false;
    if (m_78 != other->m_78)
        return false;
    return m_7C.FUN_00439090(&other->m_7C) ? false : true;
}

#include <math.h>
extern int __cdecl FUN_00ecadb8(void);
struct C1d9e0_Emitter : MeshEmitter_c1cf50
{
    bool __thiscall PickRandomVertex(NiGeometry* pkGeometry, NiPoint3& kPosition, NiPoint3& kMotionVelocity);
};
// @fnv 0x00c1d9e0
bool __thiscall C1d9e0_Emitter::PickRandomVertex(NiGeometry* pkGeometry, NiPoint3& kPosition, NiPoint3& kMotionVelocity)
{
    int iRandomIndex = FUN_00ecadb8();
    char* data = *(char**)((char*)pkGeometry + 0xb8);
    unsigned short count = *(unsigned short*)(data + 8);
    iRandomIndex %= count;
    NiPoint3* positions = *(NiPoint3**)(data + 0x20);
    NiPoint3* normals = *(NiPoint3**)(data + 0x24);
    if (positions == 0)
        return false;
    CopyParticlePoint(kPosition, positions[iRandomIndex]);
    NiPoint3 normal = normals[iRandomIndex];
    if (velocityMode == 0 && *(NiPoint3**)(*(char**)((char*)pkGeometry + 0xb8) + 0x24) != 0)
    {
        float length = (float)sqrt(kMotionVelocity.x * kMotionVelocity.x + kMotionVelocity.y * kMotionVelocity.y +
                                   kMotionVelocity.z * kMotionVelocity.z);
        NiPoint3 result = operator*(normal, length);
        CopyParticlePoint(kMotionVelocity, *(NiPoint3*)&result);
    }
    ComputeEmitterParticleTransform((NiAVObject*)pkGeometry, (NiPoint3&)kPosition, (NiPoint3&)kMotionVelocity);
    return true;
}

struct MeshPoint
{
    float x, y, z;
    MeshPoint()
    {}
    MeshPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    MeshPoint operator+(const MeshPoint& r) const
    {
        return MeshPoint(x + r.x, y + r.y, z + r.z);
    }
    MeshPoint operator-(const MeshPoint& r) const
    {
        return MeshPoint(x - r.x, y - r.y, z - r.z);
    }
    MeshPoint operator*(float r) const
    {
        return MeshPoint(x * r, y * r, z * r);
    }
};
inline MeshPoint operator*(float l, const MeshPoint& r)
{
    return MeshPoint(l * r.x, l * r.y, l * r.z);
}

struct GeometryDataLayout
{
    void* vtable;
    int unk04;
    unsigned short vertexCount;
    unsigned short unk0a;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    MeshPoint* vertices;
    MeshPoint* normals;
};

struct GeometryLayout
{
    void** vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    GeometryDataLayout* modelData;
};

struct EmitterLayout
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int velocityType;
    int emissionType;
};

struct GeometryRuntimeType
{
    const char* name;
    const GeometryRuntimeType* parent;
};

extern GeometryRuntimeType DAT_011f4a48;
extern "C" void __cdecl NiPoint3_UnitizeVector(MeshPoint* point);

typedef int(__thiscall* GeometryTestFn)(NiGeometry*);
typedef GeometryRuntimeType*(__thiscall* GeometryRTTIFn)(NiGeometry*);
typedef unsigned short(__thiscall* GetTriangleCountFn)(void*);
typedef void(__thiscall* GetTriangleIndicesFn)(void*, unsigned int, unsigned short*, unsigned short*, unsigned short*);

struct MeshEmitterCandidate : FUN_00c1f5f0_shell
{
    bool __thiscall PickEmitterParticle(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity);
    void __thiscall ComputeEmitterParticleTransform(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity);
};

// Selects triangle vertices or a consecutive vertex pair, computes position and velocity, then applies the particle transform.
// @fnv 0x00c1dae0
bool MeshEmitterCandidate::PickEmitterParticle(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity)
{
    if (!geometry)
        goto cleanup_fail;

    unsigned short vertex0, vertex1;

    if ((reinterpret_cast<GeometryTestFn>((reinterpret_cast<GeometryLayout*>(geometry)->vtable)[7]))(geometry))
    {
        unsigned int triangleCount = (reinterpret_cast<GetTriangleCountFn>(
            (reinterpret_cast<void**>(reinterpret_cast<GeometryLayout*>(geometry)->modelData->vtable))[42]))(
            reinterpret_cast<GeometryLayout*>(geometry)->modelData);
        unsigned int triangleIndex = static_cast<unsigned int>(GetRandomNumber()) % triangleCount;
        unsigned short vertex2;
        int triangleAttempts = 0;
        do
        {
            (reinterpret_cast<GetTriangleIndicesFn>(
                (reinterpret_cast<void**>(reinterpret_cast<GeometryLayout*>(geometry)->modelData->vtable))[43]))(
                reinterpret_cast<GeometryLayout*>(geometry)->modelData, triangleIndex, &vertex0, &vertex1, &vertex2);
            if (vertex0 != vertex1 && vertex0 != vertex2 && vertex1 != vertex2)
                break;
            triangleIndex += 1;
            if (triangleIndex >= triangleCount)
                triangleIndex = 0;
            triangleAttempts += 1;
        } while (triangleAttempts < 6);

        switch (GetRandomNumber() % 3)
        {
        case 1:
            vertex0 = vertex1;
            vertex1 = vertex2;
            break;
        case 2:
            vertex1 = vertex2;
            break;
        }
    }
    else
    {
        GeometryRuntimeType* runtimeType =
            reinterpret_cast<GeometryRTTIFn>((reinterpret_cast<GeometryLayout*>(geometry)->vtable)[2])(geometry);
        while (runtimeType)
        {
            if (runtimeType == &DAT_011f4a48)
                goto found_line;
            runtimeType = const_cast<GeometryRuntimeType*>(runtimeType->parent);
        }
    cleanup_fail:
        return false;

    found_line:
        float fRatio = static_cast<float>(GetRandomNumber()) / DAT_01029790;
        unsigned short vertexCount = reinterpret_cast<GeometryLayout*>(geometry)->modelData->vertexCount;
        unsigned int seg = static_cast<unsigned int>(static_cast<float>(vertexCount - 1) * fRatio);
        vertex0 = static_cast<unsigned short>(seg);
        vertex1 = static_cast<unsigned short>(seg + 1);
    }

    const MeshPoint* vertices = reinterpret_cast<GeometryLayout*>(geometry)->modelData->vertices;
    const MeshPoint* __restrict normals = reinterpret_cast<GeometryLayout*>(geometry)->modelData->normals;
    if (!vertices)
        goto cleanup_fail;

    MeshPoint v0 = vertices[vertex0];
    MeshPoint v1 = vertices[vertex1];
    MeshPoint vertexSum = v0 + v1;
    position = vertexSum * 0.5f;

    if (reinterpret_cast<EmitterLayout*>(this)->velocityType == 0 && normals)
    {
        MeshPoint normal0 = normals[vertex0];
        MeshPoint normal1 = normals[vertex1];
        MeshPoint normal = (normal0 + normal1) * 0.5f;
        NiPoint3_UnitizeVector(&normal);
        float magnitude = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y + velocity.z * velocity.z);
        velocity = normal * magnitude;
    }

    if (reinterpret_cast<EmitterLayout*>(this)->emissionType == 4)
    {
        float fRatio = static_cast<float>(GetRandomNumber()) / DAT_01029790;
        position = v0 + (v1 - v0) * fRatio;
    }

    ComputeEmitterParticleTransform(geometry, position, velocity);
    return true;
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesRead;
    return uiBytesRead;
}

template <class T>
inline unsigned int NiBinaryStreamLoad(NiBinaryStream& kBinStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int auiComponentSizes[1] = {sizeof(T)};
    return kBinStream.BinaryRead(pValue, uiNumEls * sizeof(T), auiComponentSizes, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(*(*reinterpret_cast<NiBinaryStream**>((char*)&kStream + 0x24c)), &value, 1);
}
template <class T> inline T NiStreamLoadValue(NiStream& kStream)
{
    T value;
    ReadBinaryValue(kStream, value);
    return value;
}
template <class T> inline T ReadC1E(NiBinaryStream& s)
{
    T v;
    NiBinaryStreamLoad(s, &v, 1);
    return v;
}
struct LoadableC1E
{
    void FUN_00a59be0(NiStream& kStream);
};
class LoadObjectC1E
{
  public:
    virtual ~LoadObjectC1E();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    unsigned int m_uiValue74;
    unsigned int m_uiValue78;
    LoadableC1E m_kMember7C;
    void FUN_00c223b0(NiStream& kStream);
    void Load(NiStream& kStream);
};
// Calls FUN_00c223b0, FUN_00a64670, reads two unsigned ints into m_uiValue74 and m_uiValue78, then calls m_kMember7C.FUN_00a59be0.
// @fnv 0x00c1e850
void LoadObjectC1E::Load(NiStream& kStream)
{
    FUN_00c223b0(kStream);
    kStream.ReadUnsignedInteger();
    m_uiValue74 = ReadC1E<unsigned int>(*(*reinterpret_cast<NiBinaryStream**>((char*)&kStream + 0x24c)));
    m_uiValue78 = ReadC1E<unsigned int>(*(*reinterpret_cast<NiBinaryStream**>((char*)&kStream + 0x24c)));
    m_kMember7C.FUN_00a59be0(kStream);
}

namespace fnv_00c1eb20 {
struct MeshPoint
{
    float x, y, z;
    MeshPoint()
    {}
    MeshPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    MeshPoint operator+(const MeshPoint& r) const
    {
        return MeshPoint(x + r.x, y + r.y, z + r.z);
    }
    MeshPoint operator-(const MeshPoint& r) const
    {
        return MeshPoint(x - r.x, y - r.y, z - r.z);
    }
    MeshPoint operator*(float r) const
    {
        return MeshPoint(x * r, y * r, z * r);
    }
};
inline MeshPoint operator*(float l, const MeshPoint& r)
{
    return MeshPoint(l * r.x, l * r.y, l * r.z);
}
struct GeometryDataLayout
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    MeshPoint* vertices;
    MeshPoint* normals;
};
struct GeometryLayout
{
    void** vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    GeometryDataLayout* modelData;
};
struct EmitterLayout
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int velocityType;
    int emissionType;
};
struct GeometryRuntimeType
{
    const char* name;
    const GeometryRuntimeType* parent;
};
extern GeometryRuntimeType DAT_011f4a48;
extern const double DAT_01099ee0;
extern "C" void __cdecl NiPoint3_UnitizeVector(MeshPoint* point);
typedef int(__thiscall* GeometryTestFn)(NiGeometry*);
typedef GeometryRuntimeType*(__thiscall* GeometryRTTIFn)(NiGeometry*);
typedef unsigned short(__thiscall* GetTriangleCountFn)(void*);
typedef void(__thiscall* GetTriangleIndicesFn)(void*, unsigned int, unsigned short*, unsigned short*, unsigned short*);
struct MeshEmitterCandidate : FUN_00c1f5f0_shell
{
    bool __thiscall EmitFromMesh(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity);
    bool __thiscall PickEmitterParticle(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity);
    void __thiscall ComputeEmitterParticleTransform(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity);
};
// For triangle geometry, selects triangle vertices, averages their positions and normals, applies mode-dependent sampling, then transforms the particle.
// @fnv 0x00c1eb20
bool MeshEmitterCandidate::EmitFromMesh(NiGeometry* geometry, MeshPoint& position, MeshPoint& velocity)
{
    if (geometry)
    {
        if ((reinterpret_cast<GeometryTestFn>((reinterpret_cast<GeometryLayout*>(geometry)->vtable)[7]))(geometry))
        {
            unsigned int triangleCount = (reinterpret_cast<GetTriangleCountFn>(
                (reinterpret_cast<void**>(reinterpret_cast<GeometryLayout*>(geometry)->modelData->vtable))[42]))(
                (reinterpret_cast<GeometryLayout*>(geometry)->modelData));
            unsigned int triangleIndex = static_cast<unsigned int>(GetRandomNumber()) % triangleCount;
            if (triangleIndex == triangleCount)
                triangleIndex = triangleCount - 1;
            unsigned short vertex0, vertex1, vertex2;
            int triangleAttempts = 0;
            do
            {
                (reinterpret_cast<GetTriangleIndicesFn>(
                    (reinterpret_cast<void**>(reinterpret_cast<GeometryLayout*>(geometry)->modelData->vtable))[43]))(
                    (reinterpret_cast<GeometryLayout*>(geometry)->modelData), triangleIndex, &vertex0, &vertex1,
                    &vertex2);
                if (vertex0 != vertex1 && vertex0 != vertex2 && vertex1 != vertex2)
                    break;
                triangleIndex += 1;
                if (triangleIndex >= triangleCount)
                    triangleIndex = 0;
                triangleAttempts += 1;
            } while (triangleAttempts < 6);
            const MeshPoint* vertices = reinterpret_cast<GeometryLayout*>(geometry)->modelData->vertices;
            const MeshPoint* __restrict normals;
            normals = reinterpret_cast<GeometryLayout*>(geometry)->modelData->normals;
            if (!vertices)
                return false;
            MeshPoint v0 = vertices[vertex0];
            MeshPoint v1 = vertices[vertex1];
            MeshPoint v2 = vertices[vertex2];
            const float oneThird = 1.0f / 3.0f;
            MeshPoint vertexSum = v0 + v1 + v2;
            position = vertexSum * oneThird;
            if (reinterpret_cast<EmitterLayout*>(this)->velocityType == 0 && normals)
            {
                MeshPoint normal0 = normals[vertex0];
                MeshPoint normal1 = normals[vertex1];
                MeshPoint normal2 = normals[vertex2];
                MeshPoint normalSum = normal0 + normal1 + normal2;
                MeshPoint normal = normalSum * oneThird;
                NiPoint3_UnitizeVector(&normal);
                float magnitude = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y + velocity.z * velocity.z);
                velocity = normal * magnitude;
            }
            if (reinterpret_cast<EmitterLayout*>(this)->emissionType == 3)
            {
                MeshPoint edgeA = v1 - v0;
                MeshPoint edgeB = v2 - v0;
                float scaleA = NiFastSqrt(static_cast<float>(GetRandomNumber()) / DAT_01029790);
                float scaleB = static_cast<float>(GetRandomNumber()) / DAT_01029790;
                position = edgeA + (scaleA * (edgeB * scaleB - edgeA) + v0);
            }
            ComputeEmitterParticleTransform(geometry, position, velocity);
            return true;
        }
        GeometryRuntimeType* runtimeType =
            reinterpret_cast<GeometryRTTIFn>((reinterpret_cast<GeometryLayout*>(geometry)->vtable)[2])(geometry);
        for (; runtimeType; runtimeType = const_cast<GeometryRuntimeType*>(runtimeType->parent))
        {
            if (runtimeType == &DAT_011f4a48)
                return PickEmitterParticle(geometry, position, velocity);
        }
    }
    return false;
}
}  // namespace fnv_00c1eb20

struct CloneOut
{
    void __thiscall SetSkinGeom(void* item);
};
struct CloneMap
{
    bool __thiscall FUN_00a53c30(void* key, void** out);
};
struct CloneProcess
{
    CloneMap* map;
};
struct CloneEmitter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    void** items;
    unsigned int unk5c;
    unsigned short count;
    void __thiscall FUN_00c317e0(CloneProcess& process);
    void __thiscall CloneItems(CloneProcess& process);
    unsigned int GetCount() const
    {
        return count;
    }
    void* GetItem(unsigned int i) const
    {
        return i < count ? items[i] : 0;
    }
};
// Looks up each non-null item in the process map and appends its mapped value, or the original item when absent, to output.
// @fnv 0x00c1f8f0
void __thiscall CloneEmitter::CloneItems(CloneProcess& process)
{
    FUN_00c317e0(process);
    void* clone = 0;
    process.map->FUN_00a53c30(this, &clone);
    CloneOut* output = (CloneOut*)clone;
    for (unsigned int i = 0; i < GetCount(); ++i)
    {
        void* item = GetItem(i);
        if (item)
        {
            if (process.map->FUN_00a53c30(item, &clone))
                output->SetSkinGeom(clone);
            else
                output->SetSkinGeom(item);
        }
    }
}

#include <windows.h>
extern int DAT_0101dce4;
extern long DAT_011f4400;
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00c1d660_cls
{
    void* m_00;
    int unk04;
    NiRefObject* m_08;

    FUN_00c1d660_cls* Release(unsigned char acFlags);
};

// Releases the referenced NiRefObject, clears m_00, decrements a global counter, and optionally frees memory when acFlags has bit 0 set.
// @fnv 0x00c1d660
FUN_00c1d660_cls* FUN_00c1d660_cls::Release(unsigned char acFlags)
{
    LONG(__stdcall * pDecrement)(LONG volatile*) = &InterlockedDecrement;
    FUN_00c1d660_cls* self = this;
    NiRefObject* obj = self->m_08;
    if (obj != 0)
    {
        if (pDecrement(reinterpret_cast<volatile LONG*>(&obj->m_uiRefCount)) == 0)
        {
            obj->DeleteThis();
        }
    }
    self->m_00 = &DAT_0101dce4;
    pDecrement(&DAT_011f4400);
    if (acFlags & 1)
    {
        FUN_00aa1460(self, 0xc);
    }
    return self;
}

struct NiSkinObj790;

struct NiFlags790
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
    unsigned char m_38;
};

struct NiSkinSub790
{
    unsigned int m_00;
    void __thiscall FUN_0066b0d0(unsigned int v);
};

struct NiSkinObj790
{
    virtual void v0();
    virtual void v1();
    long m_04;
    NiSkinSub790 m_08;
};

struct NiSkinRaw790
{
    NiSkinObj790* __thiscall FUN_00c1cf20();
};

struct NiSkinSlot790
{
    void __thiscall FUN_00c1f360(NiGeometry** pp);
    void __thiscall FUN_00c1f420(NiGeometry** pp);
};

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct FUN_00c1f790_cls : NiPSysMeshEmitter
{
    void __thiscall SetSkinGeom(NiGeometry* pkGeom);
};

// Sets skin geometry on the emitter, updating m_54 and m_64 slots, and sets flags 0x33 on the geometry's flags.
// @fnv 0x00c1f790
void __thiscall FUN_00c1f790_cls::SetSkinGeom(NiGeometry* pkGeom)
{
    NiGeometry* pSkinGeom = pkGeom;
    if (pSkinGeom != 0)
    {
        NiGeometry* temp = pSkinGeom;
        InterlockedIncrement(reinterpret_cast<volatile LONG*>(&pSkinGeom->m_uiRefCount));
        reinterpret_cast<NiSkinSlot790*>(&m_54)->FUN_00c1f360(&temp);
        if (InterlockedDecrement(reinterpret_cast<volatile LONG*>(&pSkinGeom->m_uiRefCount)) == 0)
        {
            pSkinGeom->DeleteThis();
        }
        NiSkinInstance* skin = pSkinGeom->m_spSkinInstance.m_pObject;
        NiSkinObj790* pSkinObj;
        NiSkinRaw790* p;
        if (skin != 0)
        {
            unsigned int edi = reinterpret_cast<unsigned int>(skin->m_pkSkinMeshPartition.m_pObject);
            p = (NiSkinRaw790*)Object_DispatchCommandFour(12);
            if (edi != 0)
            {
                if (p != 0)
                {
                    pSkinObj = p->FUN_00c1cf20();
                    pSkinObj->m_08.FUN_0066b0d0(edi);
                    goto joined;
                }
            null_obj:
                pSkinObj = 0;
                pSkinObj->m_08.FUN_0066b0d0(edi);
                goto joined;
            }
        }
        else
        {
            p = (NiSkinRaw790*)Object_DispatchCommandFour(12);
        }
        if (p != 0)
        {
            pSkinObj = p->FUN_00c1cf20();
        }
        else
        {
            pSkinObj = 0;
        }
    joined:
        temp = (NiGeometry*)pSkinObj;
        if (pSkinObj)
        {
            InterlockedIncrement(&pSkinObj->m_04);
        }
        reinterpret_cast<NiSkinSlot790*>(&m_64)->FUN_00c1f420(&temp);
        if (pSkinObj)
        {
            if (InterlockedDecrement(&pSkinObj->m_04) == 0)
            {
                pSkinObj->v1();
            }
        }
        NiFlags790* flags = reinterpret_cast<NiFlags790*>(pSkinGeom->m_spModelData.m_pObject);
        if (flags != 0)
        {
            flags->m_38 |= 0x33;
        }
    }
}

extern "C" void _ReadWriteBarrier(void);
struct GeometryCapability
{
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0C();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual int HasUsableSkinData();
};
struct MeshParticleSample
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    const unsigned short* particleIndices;
    unsigned int unk18;
    unsigned short unk1c;
    union
    {
        unsigned short particleCount;
        short signedParticleCount;
    };
    unsigned short unk20, separateChannels;
    unsigned int unk24, unk28;
};
struct MeshParticleGroup
{
    unsigned int unk00, unk04;
    unsigned short groupCount, unk0a;
    MeshParticleSample* samples;
};
struct MeshVectorOps
{
    float x, y, z;
    void ProcessAndReturnValue_0053d280(NiPoint3* output, float scalar) const;

    float FUN_00457990() const;
};
__forceinline NiPoint3 ScaleVector(const NiPoint3& value, float scalar)
{
    NiPoint3 result;
    reinterpret_cast<const MeshVectorOps*>(&value)->ProcessAndReturnValue_0053d280(&result, scalar);
    return result;
}
__forceinline void AddVector(NiPoint3& output, const NiPoint3& a, const NiPoint3& b)
{
    output.x = a.x + b.x;
    output.y = a.y + b.y;
    output.z = a.z + b.z;
}
struct SumValue
{
    float x, y, z;
    SumValue()
    {}
    SumValue(float x) : x(x)
    {}
};
__forceinline void AddAccumulator(NiPoint3& output, const SumValue& a, const NiPoint3& b)
{
    output.x = a.x + b.x;
    output.y = a.y + b.y;
    output.z = a.z + b.z;
}
extern "C" float __cdecl func_0x00639780();
extern "C" NiPoint3* __cdecl FUN_004a3760(NiPoint3*, float, NiPoint3*);
extern float DAT_01017718;
extern NiPoint3 NiPoint3_ZERO;
class MeshReconstruction : public FUN_00c1f5f0_shell
{
  public:
    bool NiPSysMeshEmitter_EmitFromSkinnedEdge(NiSkinInstance*, NiGeometry*, NiPoint3&, NiPoint3&);
    bool GetRandomEmitterParticle(NiSkinInstance*, NiGeometry*, NiPoint3&, NiPoint3&);
    void SkinVertex(NiPoint3&, NiPoint3&, NiGeometry*, NiSkinnedEmitterData*, MeshParticleSample*, unsigned int);
    void ComputeEmitterParticleTransform(NiGeometry*, NiPoint3&, NiPoint3&);
    int GetVelocitySpaceMode() const
    {
        return reinterpret_cast<const MeshEmitter_c1cf50*>(this)->velocityMode;
    }
    int GetVelocityMode() const
    {
        return reinterpret_cast<const MeshEmitter_c1cf50*>(this)->unk78;
    }
};
// Picks a random particle from a skin group, computes its position and velocity from three skinned vertices, and applies velocity-space and mode transforms.
// @fnv 0x00c1e080
// src: COMMUNITY 0x00c1e080
bool MeshReconstruction::NiPSysMeshEmitter_EmitFromSkinnedEdge(NiSkinInstance* apSkinInstance, NiGeometry* geometry, NiPoint3& position,
                                      NiPoint3& velocity)
{
    if (!geometry || !reinterpret_cast<GeometryCapability*>(geometry)->HasUsableSkinData())
        return false;
    MeshParticleGroup* group = reinterpret_cast<MeshParticleGroup*>(apSkinInstance->m_pSkinData.m_pObject);
    if (!group)
        return false;
    unsigned short groupCount = group->groupCount;
    int groupIndex = (unsigned int)(float(double(GetRandomNumber()) / DAT_01029790) * (int)groupCount);
    if (groupIndex >= (int)groupCount - 1)
        groupIndex = groupCount - 1;
    MeshParticleSample* sample = &reinterpret_cast<MeshParticleGroup*>(apSkinInstance->m_pSkinData.m_pObject)->samples[groupIndex];
    if (!sample->signedParticleCount)
        return GetRandomEmitterParticle(apSkinInstance, geometry, position, velocity);
    _ReadWriteBarrier();
    int particleCount = sample->particleCount;
    int particleIndex = (unsigned int)(func_0x00639780() * (int)particleCount);
    if (particleIndex >= (int)particleCount - 1)
        particleIndex = particleCount - 1;
    NiSkinnedEmitterData* data = reinterpret_cast<NiSkinnedEmitterData*>(geometry->m_spSkinInstance.m_pObject);
    if (!data)
        return false;
    unsigned int first, second, uiThirdIndex;
    if (sample->separateChannels)
    {
        first = sample->particleIndices[particleIndex];
        second = sample->particleIndices[particleIndex + 1];
        uiThirdIndex = sample->particleIndices[particleIndex + 2];
    }
    else
    {
        const unsigned short* indices = sample->particleIndices + particleIndex * 3;
        first = indices[0];
        second = indices[1];
        uiThirdIndex = indices[2];
    }
    struct TriangleVectors
    {
        NiPoint3 p0, p1, p2, v0, v1, v2, accumulator;
    } triangle;
    memcpy(&triangle.p0, &NiPoint3_ZERO, sizeof(triangle.p0));
    memcpy(&triangle.v0, &NiPoint3_ZERO, sizeof(triangle.v0));
    memcpy(&triangle.p1, &NiPoint3_ZERO, sizeof(triangle.p1));
    memcpy(&triangle.v1, &NiPoint3_ZERO, sizeof(triangle.v1));
    memcpy(&triangle.p2, &NiPoint3_ZERO, sizeof(triangle.p2));
    memcpy(&triangle.v2, &NiPoint3_ZERO, sizeof(triangle.v2));
    SkinVertex(triangle.p0, triangle.v0, geometry, data, sample, first);
    SkinVertex(triangle.p1, triangle.v1, geometry, data, sample, second);
    SkinVertex(triangle.p2, triangle.v2, geometry, data, sample, uiThirdIndex);
    {
        SumValue scratch(triangle.p0.x + triangle.p1.x);
        scratch.y = triangle.p1.y + triangle.p0.y;
        scratch.z = triangle.p1.z + triangle.p0.z;
        AddAccumulator(triangle.accumulator, scratch, triangle.p2);
    }
    CopyParticlePoint(position, ScaleVector(triangle.accumulator, DAT_01017718));
    if (GetVelocitySpaceMode() == 0)
    {
        SumValue scratch(triangle.v0.x + triangle.v1.x);
        scratch.y = triangle.v1.y + triangle.v0.y;
        scratch.z = triangle.v1.z + triangle.v0.z;
        AddAccumulator(triangle.accumulator, scratch, triangle.v2);
        reinterpret_cast<MeshVectorOps*>(&triangle.accumulator)->ProcessAndReturnValue_0053d280(&triangle.v2, DAT_01017718);
        NiPoint3_UnitizeVector(&triangle.v2);
        float magnitude = reinterpret_cast<MeshVectorOps*>(&velocity)->FUN_00457990();
        NiPoint3* result = FUN_004a3760(&triangle.accumulator, magnitude, &triangle.v2);
        CopyParticlePoint(velocity, *result);
    }
    if (GetVelocityMode() == 3)
    {
        NiPoint3 scratch;
        scratch.x = triangle.p1.x - triangle.p0.x;
        scratch.y = triangle.p1.y - triangle.p0.y;
        scratch.z = triangle.p1.z - triangle.p0.z;
        triangle.accumulator.x = triangle.p2.x - triangle.p0.x;
        triangle.accumulator.y = triangle.p2.y - triangle.p0.y;
        triangle.accumulator.z = triangle.p2.z - triangle.p0.z;
        float parameter = NiFastSqrt(func_0x00639780());
        NiPoint3* firstResult = FUN_004a3760(&triangle.v1, func_0x00639780(), &triangle.accumulator);
        triangle.accumulator.x = firstResult->x - scratch.x;
        triangle.accumulator.y = firstResult->y - scratch.y;
        triangle.accumulator.z = firstResult->z - scratch.z;
        NiPoint3* secondResult = FUN_004a3760(&triangle.v0, parameter, &triangle.accumulator);
        triangle.v2.x = secondResult->x + triangle.p0.x;
        triangle.v2.y = secondResult->y + triangle.p0.y;
        triangle.v2.z = secondResult->z + triangle.p0.z;
        AddVector(triangle.v1, triangle.v2, scratch);
        memcpy(&position, &triangle.v1, sizeof(position));
    }
    ComputeEmitterParticleTransform(geometry, position, velocity);
    return true;
}
