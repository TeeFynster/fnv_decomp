// nipsysrotationmodifier.cpp: NiPSysRotationModifier, NiPSysMeshUpdateModifier, FnvRotMod (12 functions)

#include "../include/BSFadeNode.h"
#include "../include/StrArr.h"
#include "../include/NiPSysModifier.h"
#include "../include/NiPSysMeshUpdateModifier.h"
#include "../include/NiPSysData.h"
#include "../include/NiPSysPositionModifier.h"
#include "../include/NiStream.h"

class NiPSysRotationModifier : public NiPSysPositionModifier
{
  protected:
    void CopyMemberData(NiPSysRotationModifier* destination, CloningProcess& process);

  public:
    NiPSysRotationModifier();

    float m_fInitialRotationSpeed;
    float m_fInitialRotationSpeedVariation;
    float m_fInitialRotationAngle;
    float m_fInitialRotationAngleVariation;
    NiPoint3 m_kRotationAxis;
    bool m_bUseRandomRotationAxis;
    bool m_bRandomInitialRotationSpeedSign;
    unsigned char layoutPadding36[2];
};

// Calls the base NiPSysModifier copy and copies the rotation modifier's fields from this object into destination.
// @fnv 0x00c205e0
void NiPSysRotationModifier::CopyMemberData(NiPSysRotationModifier* destination, CloningProcess& arProcess)
{
    NiPSysModifier::CopyMemberData(destination, arProcess);
    destination->m_fInitialRotationSpeed = m_fInitialRotationSpeed;
    destination->m_fInitialRotationSpeedVariation = m_fInitialRotationSpeedVariation;
    destination->m_bRandomInitialRotationSpeedSign = m_bRandomInitialRotationSpeedSign;
    destination->m_fInitialRotationAngle = m_fInitialRotationAngle;
    destination->m_fInitialRotationAngleVariation = m_fInitialRotationAngleVariation;
    destination->m_bUseRandomRotationAxis = m_bUseRandomRotationAxis;
    destination->m_kRotationAxis = m_kRotationAxis;
}

// @fnv 0x00c20f00
void NiPSysMeshUpdateModifier::LoadBinary(NiStream& stream)
{
    NiPSysModifier::LoadBinary(stream);
    m_uiUpdateOrder = 0x1964;
    stream.ReadUnsignedInteger();
}

struct FUN_00c206a0_shell : public NiPSysRotationModifier
{
    void* NiPSysRotationModifier_GetRTTI();
};

extern "C" void* g_01202528;

// @fnv 0x00c206a0
// src: COMMUNITY 0x00c206a0
void* FUN_00c206a0_shell::NiPSysRotationModifier_GetRTTI()
{
    return &g_01202528;
}

struct FUN_00c20a00_shell : public NiPSysRotationModifier
{
    void NiPSysRotationModifier_PostLinkObject(NiStream*);
};

// Links the object to the stream and, for older stream versions, fills the particle rotation speeds array with the modifier's rotation speed value.
// @fnv 0x00c20a00
// src: XBOX_PDB 0x00c20a00
void FUN_00c20a00_shell::NiPSysRotationModifier_PostLinkObject(NiStream* kStream)
{
    NiObject::LinkObject(*kStream);
    if (*(unsigned int*)((char*)kStream + 0xD8) < 0x14000002)
    {
        float* pfRotationSpeeds;
        unsigned short us;
        pfRotationSpeeds = *(float**)((char*)(*(void**)((char*)(*(void**)((char*)this + 0x10)) + 0xB8)) + 0x74);
        if (pfRotationSpeeds)
        {
            for (us = 0;
                 us < *(unsigned short*)((char*)(*(void**)((char*)(*(void**)((char*)this + 0x10)) + 0xB8)) + 0x50);
                 us++)
                pfRotationSpeeds[us] = *(float*)((char*)this + 0x18);
        }
    }
}

struct FUN_00c20a60_shell : public NiPSysRotationModifier
{
    bool NiPSysRotationModifier_IsEqual(NiObject*);
};

struct Call_439090_tgt
{
    bool Call_439090(const NiPoint3&);
};

// @fnv 0x00c20a60
// src: GAMEBRYO_LIB 0x00c20a60
bool FUN_00c20a60_shell::NiPSysRotationModifier_IsEqual(NiObject* object)
{
    NiPSysRotationModifier* pkDest = static_cast<NiPSysRotationModifier*>(object);
    if (NiPSysModifier::IsEqual(pkDest) && pkDest->m_fInitialRotationSpeed == m_fInitialRotationSpeed &&
        pkDest->m_fInitialRotationSpeedVariation == m_fInitialRotationSpeedVariation &&
        pkDest->m_bRandomInitialRotationSpeedSign == m_bRandomInitialRotationSpeedSign &&
        pkDest->m_fInitialRotationAngle == m_fInitialRotationAngle &&
        pkDest->m_fInitialRotationAngleVariation == m_fInitialRotationAngleVariation &&
        pkDest->m_bUseRandomRotationAxis == m_bUseRandomRotationAxis &&
        !reinterpret_cast<Call_439090_tgt*>(&pkDest->m_kRotationAxis)->Call_439090(m_kRotationAxis))
        return true;
    return false;
}

extern int DAT_010bdaec;
extern int DAT_011a946c;
extern int DAT_011a9470;
extern int DAT_011a9474;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// Allocates and constructs a NiPSysRotationModifier, sets its vtable, zeroes four floats, copies three globals and initializes two flags.
// @fnv 0x00c20640
// src: EXE 0x00c20640
NiPSysRotationModifier* NiPSysRotationModifier_CreateObject()
{
    NiPSysRotationModifier* pModifier = (NiPSysRotationModifier*)BSFadeNode::operator new(56);
    if (pModifier)
    {
        ::new (static_cast<NiPSysPositionModifier*>(pModifier)) NiPSysPositionModifier();
        *(void**)pModifier = (void*)&DAT_010bdaec;
        pModifier->m_fInitialRotationAngleVariation = pModifier->m_fInitialRotationAngle =
            pModifier->m_fInitialRotationSpeedVariation = pModifier->m_fInitialRotationSpeed = 0.0f;
        *reinterpret_cast<int*>(&pModifier->m_kRotationAxis.x) = DAT_011a946c;
        *reinterpret_cast<int*>(&pModifier->m_kRotationAxis.y) = DAT_011a9470;
        *reinterpret_cast<int*>(&pModifier->m_kRotationAxis.z) = DAT_011a9474;
        pModifier->m_bUseRandomRotationAxis = true;
        pModifier->m_bRandomInitialRotationSpeedSign = false;
        return pModifier;
    }
    return 0;
}

struct FUN_00c20d00_shell : public NiPSysRotationModifier
{
    void AddRotationStrings(void*);
};


struct Base00c319e0
{
    void FUN_00c319e0(StrArr*);
};

char* _FUN_00a7d330(char const*);
char* _FUN_00a7d370(char const*, bool);
char* NiGetViewerString_00a7d550(char const*, float);

struct NiPoint3Proxy
{
    char* GetViewerString_00a59af0(char const*);
};

// Appends the rotation modifier's property names and values to a string array, growing it as needed via SetSize and SetAt.
// @fnv 0x00c20d00
void FUN_00c20d00_shell::AddRotationStrings(void* pkStrings)
{
    StrArr* strings = static_cast<StrArr*>(pkStrings);
    char* value;

    reinterpret_cast<Base00c319e0*>(this)->FUN_00c319e0(strings);

    value = _FUN_00a7d330(static_cast<char const*>(g_01202528));
    unsigned int count = strings->m_usSize;
    if (count >= strings->m_usMaxSize)
    {
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy + count));
    }
    strings->SetAt(count, value);

    value = NiGetViewerString_00a7d550("Initial Rotation Speed", m_fInitialRotationSpeed);
    count = strings->m_usSize;
    if (count >= strings->m_usMaxSize)
    {
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy + count));
    }
    strings->SetAt(count, value);

    value = NiGetViewerString_00a7d550("Initial Rotation Speed Variation", m_fInitialRotationSpeedVariation);
    count = strings->m_usSize;
    if (count >= strings->m_usMaxSize)
    {
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy + count));
    }
    strings->SetAt(count, value);

    value = _FUN_00a7d370("Random Rot Speed Sign", m_bRandomInitialRotationSpeedSign);
    count = strings->m_usSize;
    if (count >= strings->m_usMaxSize)
    {
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy + count));
    }
    strings->SetAt(count, value);

    value = NiGetViewerString_00a7d550("Initial Rotation Angle", m_fInitialRotationAngle);
    count = strings->m_usSize;
    if (count >= strings->m_usMaxSize)
    {
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy + count));
    }
    strings->SetAt(count, value);

    value = NiGetViewerString_00a7d550("Initial Rotation Angle Variation", m_fInitialRotationAngleVariation);
    count = strings->m_usSize;
    if (count >= strings->m_usMaxSize)
    {
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy + count));
    }
    strings->SetAt(count, value);

    value = _FUN_00a7d370("Random Initial Axis", m_bUseRandomRotationAxis);
    count = strings->m_usSize;
    if (count >= strings->m_usMaxSize)
    {
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy + count));
    }
    strings->SetAt(count, value);

    NiPoint3Proxy* initialAxis = reinterpret_cast<NiPoint3Proxy*>(reinterpret_cast<char*>(this) + 0x28);
    value = initialAxis->GetViewerString_00a59af0("Initial Axis");
    count = strings->m_usSize;
    if (count >= strings->m_usMaxSize)
    {
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy + count));
    }
    strings->SetAt(count, value);
}

// ---------------------------------------------------------------------------
// FUN_00c20c00 - the save helper of the rotation particle-system modifier.
//
// The object hands four floats, two byte flags and one point to the output
// stream that the NiStream keeps at +0x250.  That stream object keeps its
// write entry point at +0x0c and counts the bytes it was given at +0x04.
//
// The base class helper (only declared here) takes the stream pointer on the
// stack, so it removes that argument itself.
// ---------------------------------------------------------------------------

typedef unsigned int(__cdecl* FnvWriteFn)(void* buffer, const void* data, unsigned int size, int* written, int flag);

struct FnvOutStream
{
    void* m_pVtbl;
    unsigned int m_uiCount;
    void* m_pData;
    FnvWriteFn m_pWrite;
};

struct FnvModBase
{
    void* m_pVtbl;
    int unk04;
    NiFixedString m_kName;
    unsigned int m_uiUpdateOrder;
    void* m_pkTarget;
    bool m_bModifierActive;
    void FUN_00c31950(void* stream);
};

struct FnvPoint3 : public NiPoint3
{
    void FnvSavePoint(NiStream* stream);
};

struct FnvRotMod : public FnvModBase
{
    float m_fInitialRotationSpeed;
    float m_fInitialRotationSpeedVariation;
    float m_fInitialRotationAngle;
    float m_fInitialRotationAngleVariation;
    FnvPoint3 m_kRotationAxis;
    bool m_bUseRandomRotationAxis;
    bool m_bRandomInitialRotationSpeedSign;
    void NiPSysRotationModifier_SaveBinary(NiStream* stream);
};

// Calls the base save, writes four floats and two bytes to the stream, then saves the point.
// @fnv 0x00c20c00
// src: XBOX_PDB 0x00c20c00
void FnvRotMod::NiPSysRotationModifier_SaveBinary(NiStream* stream)
{
    FnvModBase::FUN_00c31950(stream);

    {
        FnvOutStream* out = *(FnvOutStream**)((char*)stream + 0x250);
        {
            int written = 4;
            out->m_uiCount += out->m_pWrite(out, &m_fInitialRotationSpeed, 4, &written, 1);
        }
    }
    {
        FnvOutStream* out = *(FnvOutStream**)((char*)stream + 0x250);
        {
            int written = 4;
            out->m_uiCount += out->m_pWrite(out, &m_fInitialRotationSpeedVariation, 4, &written, 1);
        }
    }
    {
        FnvOutStream* out = *(FnvOutStream**)((char*)stream + 0x250);
        {
            int written = 4;
            out->m_uiCount += out->m_pWrite(out, &m_fInitialRotationAngle, 4, &written, 1);
        }
    }
    {
        FnvOutStream* out = *(FnvOutStream**)((char*)stream + 0x250);
        {
            int written = 4;
            out->m_uiCount += out->m_pWrite(out, &m_fInitialRotationAngleVariation, 4, &written, 1);
        }
    }
    {
        FnvOutStream* out = *(FnvOutStream**)((char*)stream + 0x250);
        {
            unsigned char value = m_bRandomInitialRotationSpeedSign;
            int written = 1;
            out->m_uiCount += out->m_pWrite(out, &value, 1, &written, 1);
        }
    }
    {
        FnvOutStream* out = *(FnvOutStream**)((char*)stream + 0x250);
        {
            unsigned char value = m_bUseRandomRotationAxis;
            int written = 1;
            out->m_uiCount += out->m_pWrite(out, &value, 1, &written, 1);
        }
    }

    m_kRotationAxis.FnvSavePoint(stream);
}

class CC20AE0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CC20AE0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class CC20AE0Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    unsigned int m_uiFileVersion;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    CC20AE0BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void CC20AE0BinaryStreamLoad(CC20AE0BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void CC20AE0LoadBinary(CC20AE0Stream& kStream, T& value)
{
    CC20AE0BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

class CC20AE0Point3
{
  public:
    void LoadBinary(CC20AE0Stream& kStream);

    float x;
    float y;
    float z;
};

class CC20AE0Modifier
{
  public:
    virtual void LoadBinary(CC20AE0Stream& kStream);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class CC20AE0FieldModifier : public CC20AE0Modifier
{
  public:
    void NiPSysRotationModifier_LoadBinary(CC20AE0Stream& kStream);

    float m_fInfluence;
    float m_fFieldAttenuation;
    float m_fDistanceLimit;
    float m_fMaxDistanceSquared;
    CC20AE0Point3 m_kLightVector;
    bool m_bEnableMaxDistance;
    bool m_bFieldFlag;
};

// Loads the base modifier, then reads float fields, version-gated fields and two bool flags, and a point from the stream.
// @fnv 0x00c20ae0
// src: XBOX_PDB 0x00c20ae0
void CC20AE0FieldModifier::NiPSysRotationModifier_LoadBinary(CC20AE0Stream& kStream)
{
    CC20AE0Modifier::LoadBinary(kStream);

    CC20AE0LoadBinary(kStream, m_fInfluence);
    if (kStream.m_uiFileVersion >= 0x14000002)
    {
        CC20AE0LoadBinary(kStream, m_fFieldAttenuation);
        CC20AE0LoadBinary(kStream, m_fDistanceLimit);
        CC20AE0LoadBinary(kStream, m_fMaxDistanceSquared);
        unsigned char ucWorldAligned;
        CC20AE0LoadBinary(kStream, ucWorldAligned);
        m_bFieldFlag = ucWorldAligned != 0;
    }

    unsigned char ucUseMaxDistance;
    CC20AE0LoadBinary(kStream, ucUseMaxDistance);
    m_bEnableMaxDistance = ucUseMaxDistance != 0;

    m_kLightVector.LoadBinary(kStream);
}

const float g_fPi = 3.1415927f;
const float g_fRadiansPerRevolution = 2.0f * g_fPi;

class Point3ParameterData
{
  public:
    float m_fVelocityX;
    float m_fVelocityY;
    float m_fVelocityZ;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
};


// For each particle, adds (fTime minus m_fZValue) times its rotation speed to its angle, resetting it to 0 if above 10 pi, else reducing it to at most 2 pi.
// @fnv 0x00c206b0
void __stdcall UpdateRotationAngles(float fTime, NiPSysData* pkData)
{
    float* pfRotationAngles = pkData->m_pfRotationAngles;
    if (pfRotationAngles)
    {
        const float* pfRotationSpeeds = pkData->m_pfRotationSpeeds;
        for (unsigned short us = 0; us < pkData->m_usActive; us++)
        {
            float* pfAngle = &pfRotationAngles[us];
            float fMoveElapsedTime = fTime - pkData->m_pkParticleInfo[us].m_fZValue;
            float fAngleDifference = *pfAngle + fMoveElapsedTime * pfRotationSpeeds[us];
            *pfAngle = fAngleDifference;

            static float fMaxAngle = 10.0f * g_fPi;
            if (fAngleDifference > fMaxAngle)
            {
                *pfAngle = 0.0f;
            }
            else
            {
                while (*pfAngle > g_fRadiansPerRevolution)
                    *pfAngle -= g_fRadiansPerRevolution;
            }
        }
    }
}

inline NiPSysRotationModifier::NiPSysRotationModifier()
{
    m_fInitialRotationSpeed = 0.0f;
    m_fInitialRotationSpeedVariation = 0.0f;
    m_fInitialRotationAngle = 0.0f;
    m_fInitialRotationAngleVariation = 0.0f;
    *reinterpret_cast<int*>(&m_kRotationAxis.x) = DAT_011a946c;
    *reinterpret_cast<int*>(&m_kRotationAxis.y) = DAT_011a9470;
    *reinterpret_cast<int*>(&m_kRotationAxis.z) = DAT_011a9474;
    m_bUseRandomRotationAxis = true;
    m_bRandomInitialRotationSpeedSign = false;
}
struct C20980_Owner
{
    void FUN_00c205e0(NiPSysRotationModifier* modifier, int arg);
    NiPSysRotationModifier* CreateModifier(int arg);
};
// Allocates and constructs a NiPSysRotationModifier, passes it and arg to FUN_00c205e0, and returns it.
// @fnv 0x00c20980
NiPSysRotationModifier* C20980_Owner::CreateModifier(int arg)
{
    NiPSysRotationModifier* modifier = new NiPSysRotationModifier;
    FUN_00c205e0(modifier, arg);
    return modifier;
}

#include <stdlib.h>
#include <math.h>
extern double DAT_01029790;
extern float DAT_011aea98;
extern float DAT_011f4ae0[];
extern float DAT_011f52e0[];


static inline float UnitRandom()
{
    return (float)(rand() / DAT_01029790);
}

static inline float SymmetricRandom()
{
    return (float)(rand() * 2.0 / DAT_01029790 - 1.0);
}

static inline float FastCos(float fAngleDifference)
{
    return DAT_011f4ae0[(int)(512.0 / DAT_011aea98 * fAngleDifference) & 0x1ff];
}

static inline void FastSinCos(float fAngleDifference, float& fCos, float& fSin)
{
    int i = (int)(512.0 / DAT_011aea98 * fAngleDifference) & 0x1ff;
    fCos = DAT_011f4ae0[i];
    fSin = DAT_011f52e0[i];
}

struct FUN_00c207a0_shell : public NiPSysRotationModifier
{
    void UpdateParticleRotation(NiPSysData* pkData, unsigned short usNewParticle);
};

// Sets the rotation axis and initial rotation angle/speed for a new particle, using random values or the modifier's configured defaults.
// @fnv 0x00c207a0
void FUN_00c207a0_shell::UpdateParticleRotation(NiPSysData* pkSysData, unsigned short usNewParticle)
{
    NiPSysData* pkData = pkSysData;
    NiPoint3* pkAxes = pkData->m_pkRotationAxes;
    if (pkAxes)
    {
        NiPoint3& kAxis = pkAxes[usNewParticle];
        if (m_bUseRandomRotationAxis)
        {
            float fZAngle = UnitRandom() * 3.1415927f;
            float fCosZ = FastCos(fZAngle);
            float fR = sqrt(1.0f - fCosZ * fCosZ);
            float fAngleDifference = UnitRandom() * DAT_011aea98;
            float fCos, fSin;
            FastSinCos(fAngleDifference, fCos, fSin);
            kAxis.x = fR * fSin;
            kAxis.y = fR * fCos;
            kAxis.z = fCosZ;
        }
        else
        {
            kAxis = m_kRotationAxis;
        }
    }

    if (pkData->m_pfRotationAngles)
    {
        pkData->m_pfRotationAngles[usNewParticle] =
            m_fInitialRotationAngle + m_fInitialRotationAngleVariation * SymmetricRandom();
        float fSpeed = m_fInitialRotationSpeed + m_fInitialRotationSpeedVariation * SymmetricRandom();
        if (m_bRandomInitialRotationSpeedSign && !(UnitRandom() > 0.5f))
            fSpeed = -fSpeed;
        pkData->m_pfRotationSpeeds[usNewParticle] = fSpeed;
    }
}
