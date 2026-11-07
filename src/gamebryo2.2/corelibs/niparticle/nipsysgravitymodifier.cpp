
// src/gamebryo2.2/corelibs/niparticle/nipsysgravitymodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysgravitymodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysBombModifier.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/NiMatrix3.h"

#include "../../../../include/NiMemObject.h"
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

extern NiMemObject g_01202548;

// @fnv 0x00c22af0
// src: COMMUNITY 0x00c22af0
NiMemObject* __cdecl NiPSysGravityModifier_GetRTTI()
{
    return &g_01202548;
}

extern "C" void* g_01202790;

// @fnv 0x00c2e540
// src: COMMUNITY 0x00c2e540
void* __cdecl NiPSysBombModifier_GetRTTI()
{
    return &g_01202790;
}

namespace fnv_00c22b00 {
using ::NiMemObject;
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct NiPSysGravityModifier : NiPSysModifier
{
    NiObject* m_pkGravityObject;
    NiPoint3 m_kGravityDirection;
    float m_fDistanceDecay;
    float m_fValue;
    int m_eRequestType;
    float m_fTurbulenceAmount;
    float m_fScale;
    bool m_bFieldFlag;
    void* operator new(unsigned int);
    NiPSysGravityModifier* InitDefaults();
    NiPSysGravityModifier* CreateClone_00c22b00(CloningProcess&);
};
// Allocates and constructs a copy of this gravity modifier, copies its fields, runs the base clone step with process, and returns the clone.
// @fnv 0x00c22b00
// src: XBOX_PDB 0x00c22b00
NiPSysGravityModifier* NiPSysGravityModifier::CreateClone_00c22b00(CloningProcess& process)
{
    NiPSysGravityModifier* clone = static_cast<NiPSysGravityModifier*>(operator new(0x40));
    if (clone)
        clone = clone->InitDefaults();
    else
        clone = 0;
    CopyMemberData(clone, process);
    clone->m_kGravityDirection = m_kGravityDirection;
    clone->m_fDistanceDecay = m_fDistanceDecay;
    clone->m_fValue = m_fValue;
    clone->m_eRequestType = m_eRequestType;
    clone->m_fTurbulenceAmount = m_fTurbulenceAmount;
    clone->m_fScale = m_fScale;
    clone->m_bFieldFlag = m_bFieldFlag;
    return clone;
}
}  // namespace fnv_00c22b00

// @fnv 0x00c2e520
void NiPSysBombModifier::LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
    m_pkBombObject = stream.GetLoadedObject();
}

struct S_00c236b0_BinaryStream;
typedef unsigned int(__cdecl* S_00c236b0_ReadFn)(S_00c236b0_BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                 unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct S_00c236b0_BinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    S_00c236b0_ReadFn m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T>
inline void S_00c236b0_BinaryStreamLoad(S_00c236b0_BinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

struct S_00c236b0_Stream
{
    int unk0;
    unsigned int m_uiUserVersion;  // +04
    int unk8;
    int unkC;
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned int m_uiNifVersion;  // +D8
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    S_00c236b0_BinaryStream* m_pUnderlyingStream;  // +24C

    void ReadLinkID();
};

template <class T> inline void S_00c236b0_StreamLoadBinary(S_00c236b0_Stream& kStream, T& value)
{
    S_00c236b0_BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value, 1);
}

struct S_00c236b0_Obj : NiPSysModifier
{
    NiObject* m_pkGravityObject;
    NiPoint3 m_1C;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    bool m_3C;

    void LoadFromStream(S_00c236b0_Stream& kStream);
};

// Loads the object's base data, member m_1C, m_28, m_2C, m_30, and conditionally m_34, m_38 and m_3C from kStream based on version checks.
// @fnv 0x00c236b0
void S_00c236b0_Obj::LoadFromStream(S_00c236b0_Stream& kStream)
{
    NiPSysModifier::LoadBinary(reinterpret_cast<NiStream&>(kStream));
    kStream.ReadLinkID();
    m_1C.LoadBinary(reinterpret_cast<NiStream&>(kStream));
    S_00c236b0_StreamLoadBinary(kStream, m_28);
    S_00c236b0_StreamLoadBinary(kStream, m_2C);
    int iValue;
    S_00c236b0_StreamLoadBinary(kStream, iValue);
    m_30 = iValue;
    if (kStream.m_uiNifVersion >= 0x0a00010e)
    {
        S_00c236b0_StreamLoadBinary(kStream, m_34);
        S_00c236b0_StreamLoadBinary(kStream, m_38);
    }
    if (kStream.m_uiUserVersion > 20)
    {
        S_00c236b0_StreamLoadBinary(kStream, m_3C);
    }
}

struct FNVStreamWriter
{
    void* owner;
    unsigned int writtenBytes;
    void* streamState;
    int(__cdecl* write)(FNVStreamWriter*, const void*, unsigned int, unsigned int*, int);
};
struct FNVStreamArchive
{
};
struct FNVSubproperty
{
    void FUN_00a69780(FNVStreamArchive*);
};
struct FNVSerializer
{
    void FUN_00c31950(FNVStreamArchive*);
    void WriteToStream(FNVStreamArchive*);
};
// Writes a header, a subproperty, and five 4-byte values plus one 1-byte value from this object to the stream writer.
// @fnv 0x00c237c0
void FNVSerializer::WriteToStream(FNVStreamArchive* stream)
{
    FUN_00c31950(stream);
    typedef void(__thiscall * HeaderWriter)(FNVStreamArchive*, unsigned int);
    HeaderWriter pHeaderWriter = reinterpret_cast<HeaderWriter>((*reinterpret_cast<void***>(stream))[12]);
    pHeaderWriter(stream, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x18));
    reinterpret_cast<FNVSubproperty*>(reinterpret_cast<char*>(this) + 0x1c)->FUN_00a69780(stream);
    FNVStreamWriter* __restrict writer;
    unsigned int length;
    length = 4;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x28, 4, reinterpret_cast<unsigned int*>(&length), 1);
    length = 4;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x2c, 4, reinterpret_cast<unsigned int*>(&length), 1);
    length = 4;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x30, 4, reinterpret_cast<unsigned int*>(&length), 1);
    length = 4;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x34, 4, reinterpret_cast<unsigned int*>(&length), 1);
    length = 4;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x38, 4, reinterpret_cast<unsigned int*>(&length), 1);
    length = 1;
    writer = *reinterpret_cast<FNVStreamWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    writer->writtenBytes +=
        writer->write(writer, reinterpret_cast<char*>(this) + 0x3c, 1, reinterpret_cast<unsigned int*>(&length), 1);
}

struct GravityViewerStringsArray
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_0096ad30(unsigned int uiMaxSize);
    void FUN_0096ae90(unsigned int uiIndex, char* const& element);
    unsigned int Add(char* const& element)
    {
        unsigned int usIndex = m_usSize;
        if (usIndex >= m_usMaxSize)
            FUN_0096ad30(usIndex + m_usGrowBy);
        FUN_0096ae90(usIndex, element);
        return usIndex;
    }
};

extern NiRTTI g_kGravityModifierRTTI_01202548;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcName);
char* __cdecl NiGetViewerString_00a7d5e0(const char* pcPrefix, const char* pcValue);
char* __cdecl NiGetViewerString_00a7d550(const char* pcPrefix, float fValue);
char* __cdecl NiGetViewerString(const char* pcPrefix, bool bValue);

struct NiPSysGravityModifierImpl
{
    char pad00[0x18];
    NiAVObject* m_pkGravityObject;
    NiPoint3 m_kGravityDirection;
    float m_fDistanceDecay;
    float m_fValue;
    int m_eForceType;
    float m_fTurbulenceAmount;
    float m_fTurbulenceScale;
    bool m_bFieldFlag;

    void FUN_00c319e0(GravityViewerStringsArray* pkStrings);
    void AddViewerStrings(GravityViewerStringsArray* pkStrings);
};

// Appends the gravity modifier's RTTI name, gravity object, axis, decay, strength, turbulence, force type and world-aligned flag to the viewer strings array.
// @fnv 0x00c238c0
void NiPSysGravityModifierImpl::AddViewerStrings(GravityViewerStringsArray* pkStrings)
{
    FUN_00c319e0(pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(g_kGravityModifierRTTI_01202548.m_pcName));
    const char* pcGravityObjName;
    if (m_pkGravityObject)
        pcGravityObjName = m_pkGravityObject->m_kName.m_kHandle;
    else
        pcGravityObjName = "None";
    pkStrings->Add(NiGetViewerString_00a7d5e0("Gravity Object", pcGravityObjName));
    pkStrings->Add(m_kGravityDirection.GetViewerString_00a59af0("Gravity Axis"));
    pkStrings->Add(NiGetViewerString_00a7d550("Decay", m_fDistanceDecay));
    pkStrings->Add(NiGetViewerString_00a7d550("Strength", m_fValue));
    pkStrings->Add(NiGetViewerString_00a7d550("Turbulence", m_fTurbulenceAmount));
    pkStrings->Add(NiGetViewerString_00a7d550("TurbulenceScale", m_fTurbulenceScale));
    const char* pcForceTypeName;
    if (m_eForceType == 0)
        pcForceTypeName = "FORCE_PLANAR";
    else if (m_eForceType == 1)
        pcForceTypeName = "FORCE_SPHERICAL";
    else
        pcForceTypeName = "Unknown";
    pkStrings->Add(NiGetViewerString_00a7d5e0("Force Type", pcForceTypeName));
    pkStrings->Add(NiGetViewerString("WorldAligned", m_bFieldFlag));
}

struct Node18
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual bool v5c(void* p);
};

struct FUN_00c235f0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    Node18* m_18;
    NiPoint3 m_1c;
    float m_28;
    float m_2c;
    int m_30;
    float m_34;
    float m_38;
    char m_3c;

    bool FUN_00c31830(FUN_00c235f0_cls* o);
    bool IsEqual(FUN_00c235f0_cls* o);
};

// Compares two FUN_00c235f0_cls objects for equality, checking m_18, m_1c, and the float/int/char fields m_28 through m_3c.
// @fnv 0x00c235f0
bool FUN_00c235f0_cls::IsEqual(FUN_00c235f0_cls* apOther)
{
    if (FUN_00c31830(apOther))
    {
        if ((m_18 && !apOther->m_18) || (!m_18 && apOther->m_18))
            return false;
        if (m_18 && apOther->m_18 && !m_18->v5c(apOther->m_18))
            return false;
        if (apOther->m_1c != m_1c)
            return false;
        if (apOther->m_28 != m_28)
            return false;
        if (apOther->m_2c != m_2c)
            return false;
        if (apOther->m_30 != m_30)
            return false;
        if (apOther->m_34 != m_34)
            return false;
        if (apOther->m_38 != m_38)
            return false;
        if (apOther->m_3c != m_3c)
            return false;
        return true;
    }
    return false;
}

#include <string.h>
#include <math.h>
extern const double DAT_0106efa0 = 1.600000023841858;
inline float DecayExp(float value)
{
    return (float)exp(value);
}

inline float& GravityX(NiPoint3& p) { return p.x; }
inline float& GravityY(NiPoint3& p) { return p.y; }
inline float& GravityZ(NiPoint3& p) { return p.z; }
inline const float& GravityX(const NiPoint3& p) { return p.x; }
inline const float& GravityY(const NiPoint3& p) { return p.y; }
inline const float& GravityZ(const NiPoint3& p) { return p.z; }
inline float& GravityComponent(NiPoint3& p, unsigned i) { return p.components[i]; }

inline NiPoint3& AddGravityVector(NiPoint3& target, const NiPoint3& p)
{
    GravityX(target) += GravityX(p);
    GravityY(target) += GravityY(p);
    GravityZ(target) += GravityZ(p);
    return target;
}

// Keep the particle update's vector arithmetic inline, as in the original unit.
inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
{}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& p) const
{
    NiPoint3 result(x - p.x, y - p.y, z - p.z);
    return result;
}

inline NiPoint3 NiPoint3::operator*(float k) const
{
    NiPoint3 result(x * k, y * k, z * k);
    return result;
}

inline NiPoint3 NiPoint3::operator+(const NiPoint3& p) const
{
    NiPoint3 result(x + p.x, y + p.y, z + p.z);
    return result;
}

inline float NiPoint3::Length() const
{
    return (float)sqrt((double)(float)(x * x + y * y + z * z));
}

inline NiPoint3 operator*(float scale, const NiPoint3& point)
{
    return NiPoint3(point.x * scale, point.y * scale, point.z * scale);
}

// src: XBOX_PDB 0x004a0c10
__declspec(noinline) void __fastcall NiPoint3_Unitize(NiPoint3* point)
{
    float length = static_cast<const NiPoint3*>(point)->Length();
    if (length > 9.999999974752427e-07)
    {
        float inverse = 1.0f / length;
        point->x *= inverse;
        point->y *= inverse;
        point->z *= inverse;
    }
    else
    {
        point->x = point->y = point->z = 0.0f;
    }
}

__declspec(noinline) float __fastcall FUN_00457910(NiPoint3* point)
{
    float length = static_cast<const NiPoint3*>(point)->Length();
    if (length > 9.999999974752427e-07)
    {
        float inverse = 1.0f / length;
        point->x *= inverse;
        point->y *= inverse;
        point->z *= inverse;
    }
    else
    {
        point->x = point->y = point->z = 0.0f;
        length = 0.0f;
    }
    return length;
}

// NiTransform uses the original inverse/product targets 0x004b4880/0x0062c250.
inline NiTransform::NiTransform()
{}

struct ParticleC22
{

    NiPoint3 position;

    float unk0c, unk10, activeTime, unk18;
    float GetActiveTime() const
    {
        return activeTime;
    }
    NiPoint3& GetPosition()
    {
        return position;
    }

    __forceinline void ApplyMotion(NiPoint3 motion, float elapsed)
    {

        float step = elapsed - activeTime;

        NiPoint3 displacement = motion * step;

        position.x += displacement.x;

        position.y += displacement.y;

        position.z += displacement.z;
    }
};

struct EmitterC22
{

    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;

    NiPoint3* sourcePositions;

    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;

    unsigned short activeCount;

    unsigned short unk52;

    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;

    ParticleC22* particles;
    ParticleC22* GetParticles() const
    {
        return particles;
    }
    NiPoint3* GetSourcePositions() const
    {
        return sourcePositions;
    }
    unsigned short GetActiveCount() const
    {
        return activeCount;
    }
};

extern float __cdecl NiSymmetricRandom_006397c0();

struct EffectC22
{

    int unk00, unk04, unk08, unk0c;

    NiAVObject* sourceTransform;

    int unk14;

    NiAVObject* directionSource;

    NiPoint3 location;

    float radialStrength;

    float speed;

    int movementType;

    float dispersion;

    float spread;

    unsigned char useSource;
    float GetDecay() const
    {
        return radialStrength;
    }
    float GetAttributeStrength() const
    {
        return speed;
    }
    float GetTurbulence() const
    {
        return dispersion;
    }
    float GetTurbulenceScale() const
    {
        return spread;
    }

    __forceinline NiPoint3 Axis(const NiTransform& local)
    {
        NiPoint3 result;
        if (useSource)
            result = directionSource->m_kLocal.m_Rotate.operator*(location);
        else
            result = local.m_Rotate.operator*(location);
        return result;
    }

    void NiPSysGravityModifier_Update(float elapsed, EmitterC22* emitter);
};

// Moves each active particle in the emitter by applying force, decay, and turbulence based on the effect's movement type and elapsed time.
// @fnv 0x00c22b70
// src: XBOX_PDB 0x00c22b70
void EffectC22::NiPSysGravityModifier_Update(float elapsed, EmitterC22* emitter)
{

    if (!emitter->GetActiveCount() || !directionSource)
        return;

    NiTransform x;
    memcpy(&x, &directionSource->m_kWorld, sizeof(x));

    NiTransform pForm;

    memcpy(&pForm, &sourceTransform->m_kWorld, sizeof(pForm));

    NiTransform ptr;

    pForm.FUN_004b4880(&ptr);

    ptr.FUN_0062c250(&pForm, x);

    NiPoint3 vForceDirection;
    if (useSource)
    {
        const NiMatrix3& m = directionSource->m_kLocal.m_Rotate;
        vForceDirection = m.operator*(location);
    }
    else
        vForceDirection = pForm.m_Rotate.operator*(location);

    NiPoint3_Unitize(&vForceDirection);

    unsigned short j;
    j = emitter->GetActiveCount();

    float fSourceStrength;

    fSourceStrength = (float)(GetAttributeStrength() * DAT_0106efa0);

    switch (movementType)
    {

    case 0:

        if (GetDecay() == 0.0f && GetTurbulence() == 0.0f)
        {

            unsigned short i;
            float s;
            NiPoint3* p;
            (void)i;
            (void)s;
            (void)p;
            ParticleC22* pParticle;
            pParticle = emitter->GetParticles();

            for (i = 0; i < j; ++i, ++pParticle)
            {

                s = (elapsed - pParticle->GetActiveTime()) * fSourceStrength;

                NiPoint3 vDisplacement = vForceDirection * s;
                p = &pParticle->position;
                float& deltaz = vDisplacement.z;
                p->x += vDisplacement.x;
                p->y += vDisplacement.y;
                p->z += deltaz;
            }
        }
        else if (GetDecay() == 0.0f && GetTurbulence() != 0.0f)
        {

            ParticleC22* pParticle;
            pParticle = emitter->GetParticles();

            float randomScale = (float)(GetTurbulence() * GetTurbulenceScale() * 500.0);

            for (unsigned short i = 0; i < j; ++i, ++pParticle)
            {

                NiPoint3 kIter;
                kIter = fSourceStrength * vForceDirection;

                NiPoint3 vOffset;

                vOffset.x = NiSymmetricRandom_006397c0() * randomScale;

                vOffset.y = NiSymmetricRandom_006397c0() * randomScale;

                vOffset.z = NiSymmetricRandom_006397c0() * randomScale;

                AddGravityVector(pParticle->position, (kIter + vOffset) * (elapsed - pParticle->activeTime));
            }
        }
        else if (radialStrength != 0.0f && GetTurbulence() == 0.0f)
        {

            ParticleC22* pParticle;
            pParticle = emitter->GetParticles();

            NiPoint3* y;
            y = emitter->GetSourcePositions();

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                NiPoint3 z;

                z = pForm.m_Translate - *y;

                float fDot;

                fDot = z.Dot(vForceDirection);

                float fDecay;
                if (fDot < 0.0f)
                    fDecay = DecayExp(fDot * GetDecay());
                else
                    fDecay = DecayExp(fDot * -GetDecay());

                AddGravityVector(pParticle->GetPosition(),
                    vForceDirection * ((elapsed - pParticle->GetActiveTime()) * (fSourceStrength * fDecay)));
            }
        }
        else if (GetDecay() != 0.0f && GetTurbulence() != 0.0f)
        {

            ParticleC22* pParticle;

            pParticle = emitter->GetParticles();

            NiPoint3* y;
            y = emitter->GetSourcePositions();

            float randomScale;

            randomScale = (float)(GetTurbulence() * GetTurbulenceScale() * 500.0);

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                NiPoint3 vOffset;

                NiPoint3 kIter = fSourceStrength * vForceDirection;

                vOffset.x = NiSymmetricRandom_006397c0() * randomScale;

                vOffset.y = NiSymmetricRandom_006397c0() * randomScale;

                vOffset.z = NiSymmetricRandom_006397c0() * randomScale;

                NiPoint3 z = pForm.m_Translate - *y;

                float v;

                float fDot;

                fDot = z.Dot(vForceDirection);

                if (fDot < 0.0f)
                    v = DecayExp(fDot * GetDecay());

                else
                    v = DecayExp(fDot * -GetDecay());

                pParticle->ApplyMotion(v * kIter + vOffset, elapsed);
            }
        }

        break;

    case 1:

        if (GetDecay() == 0.0f && GetTurbulence() == 0.0f)
        {

            ParticleC22* pParticle;
            pParticle = emitter->GetParticles();

            NiPoint3* y;
            y = emitter->GetSourcePositions();

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                GravityX(vForceDirection) = GravityX(pForm.m_Translate) - GravityX(*y);

                GravityY(vForceDirection) = GravityY(pForm.m_Translate) - GravityY(*y);

                GravityZ(vForceDirection) = GravityZ(pForm.m_Translate) - GravityZ(*y);

                NiPoint3_Unitize(&vForceDirection);

                float s = (elapsed - pParticle->activeTime) * fSourceStrength;
                AddGravityVector(pParticle->GetPosition(), vForceDirection * s);
            }
        }
        else if (GetDecay() == 0.0f && dispersion != 0.0f)
        {

            float randomScale = (float)(GetTurbulenceScale() * GetTurbulence() * 500.0);

            ParticleC22* pParticle = emitter->GetParticles();

            NiPoint3* y = emitter->GetSourcePositions();

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                GravityX(vForceDirection) = GravityX(pForm.m_Translate) - y->x;

                GravityY(vForceDirection) = GravityComponent(pForm.m_Translate, 1) - GravityY(*y);

                GravityZ(vForceDirection) = GravityZ(pForm.m_Translate) - GravityZ(*y);

                NiPoint3_Unitize(&vForceDirection);

                NiPoint3 vOffset;

                vOffset.x = NiSymmetricRandom_006397c0() * randomScale;

                vOffset.y = NiSymmetricRandom_006397c0() * randomScale;

                vOffset.z = NiSymmetricRandom_006397c0() * randomScale;

                AddGravityVector(pParticle->GetPosition(),
                    (fSourceStrength * vForceDirection + vOffset) * (elapsed - pParticle->GetActiveTime()));
            }
        }
        else if (GetDecay() != 0.0f && GetTurbulence() == 0.0f)
        {

            NiPoint3* y;

            ParticleC22* pParticle;

            pParticle = emitter->GetParticles();

            y = emitter->GetSourcePositions();

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                GravityX(vForceDirection) = GravityX(pForm.m_Translate) - y->x;

                GravityY(vForceDirection) = GravityY(pForm.m_Translate) - GravityY(*y);

                GravityZ(vForceDirection) = GravityZ(pForm.m_Translate) - y->z;

                float fDecay = DecayExp((float)(-GetDecay() * FUN_00457910(&vForceDirection)));

                float s = fDecay * fSourceStrength * (elapsed - pParticle->GetActiveTime());
                AddGravityVector(pParticle->GetPosition(), vForceDirection * s);
            }
        }
        else if (GetDecay() != 0.0f && dispersion != 0.0f)
        {

            ParticleC22* pParticle = emitter->GetParticles();

            NiPoint3* y;

            y = emitter->GetSourcePositions();

            float randomScale;
            randomScale = (float)(GetTurbulence() * GetTurbulenceScale() * 500.0);

            for (unsigned short i = 0; i < j; ++i, ++pParticle, ++y)
            {

                NiPoint3 vOffset;

                NiPoint3 kIter = vForceDirection * fSourceStrength;

                vOffset.x = NiSymmetricRandom_006397c0() * randomScale;

                vOffset.y = NiSymmetricRandom_006397c0() * randomScale;

                vOffset.z = NiSymmetricRandom_006397c0() * randomScale;

                NiPoint3 z = pForm.m_Translate - *y;

                float fDecay;
                fDecay = DecayExp((float)(-GetDecay() * FUN_00457910(&z)));

                pParticle->ApplyMotion(kIter * fDecay + vOffset, elapsed);
            }
        }

        break;
    }
}
