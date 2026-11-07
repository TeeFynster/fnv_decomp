#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBoolData.h"
#include "../../../../include/NiBoolInterpolator.h"
#include "../../../../include/NiStream.h"

// src/gamebryo2.2/corelibs/nianimation/niboolinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niboolinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00a53070
// src: GUESS 0x00a53070 (confidence: high)
int __stdcall NiBoolInterpolator_ReturnConstant_5(unsigned short usChannel)
{
    return 5;
}

// @fnv 0x00a53080
unsigned int NiBoolInterpolator::GetColorKeyCount(unsigned short usChannel) const
{
    NiBoolData* p = m_spBoolData.m_pObject;
    if (!p)
        return 0;
    return p->m_uiNumKeys;
}

// @fnv 0x00a53090
NiAnimationKey* NiBoolInterpolator::GetChannelKeys(unsigned short usChannel) const
{
    NiBoolData* p = m_spBoolData.m_pObject;
    if (!p)
        return 0;
    return reinterpret_cast<NiAnimationKey*>(p->m_pKeyArray);
}

// These base overrides are not declared by the shared NiKeyBasedInterpolator yet.
void __cdecl BSPackedAdditionalGeometryData_RegisterStreamables();
void __cdecl bhkCharacterProxy_IsEqual();
void __cdecl NiKeyBasedInterpolator_LinkObject();
void __cdecl FUN_00a3cbf0();

// @fnv 0x00a3c5b0
// src: XBOX_PDB 0x00a3c5b0
bool __thiscall NiBoolInterpolator::RegisterStreamables_00a3c5b0(NiStream* kStream)
{
    if (!reinterpret_cast<bool (__thiscall*)(NiKeyBasedInterpolator*, NiStream*)>(&BSPackedAdditionalGeometryData_RegisterStreamables)(this, kStream))
        return false;
    NiBoolData* pkBoolData = m_spBoolData.m_pObject;
    if (pkBoolData)
        pkBoolData->RegisterStreamables(*kStream);
    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

inline void NiBoolData::DecrementRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline NiPointer<NiBoolData>::operator NiBoolData*() const
{
    return m_pObject;
}

inline NiBoolData* NiPointer<NiBoolData>::operator->() const
{
    return m_pObject;
}

inline NiPointer<NiBoolData>::NiPointer() : m_pObject(0)
{}

inline NiPointer<NiBoolData>& NiPointer<NiBoolData>::operator=(NiBoolData* p)
{
    if (m_pObject != p)
    {
        if (m_pObject)
            m_pObject->DecrementRefCount();
        m_pObject = p;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

// @fnv 0x00a531a0
void NiBoolInterpolator::SetBoolValue(bool abValue)
{
    m_spBoolData = 0;
    m_bBoolValue = abValue;
}

void __cdecl FUN_00a537a0(float m_fStartTime, float m_fMaximumDistance);

// @fnv 0x00a531f0
void NiBoolInterpolator::SetActiveTimeRange(float afArg1, float afArg2)
{
    if (m_spBoolData.m_pObject)
    {
        // The shared class does not yet declare the range-key operation.
        typedef void (__thiscall* AddBooleanKeyFunction)(NiBoolData*, float, float);
        reinterpret_cast<AddBooleanKeyFunction>(&FUN_00a537a0)(m_spBoolData.m_pObject, afArg1, afArg2);
    }
}

extern unsigned char DAT_0109a914;

// The shared class inherits IsPoseValue without declaring this override.
// @fnv 0x00a530a0
unsigned char __fastcall IsBoolPoseValue(const NiBoolInterpolator* self, int, int unused)
{
    if (self->m_spBoolData.m_pObject != 0)
        return 0;

    return reinterpret_cast<const volatile unsigned char&>(self->m_bBoolValue) != DAT_0109a914;
}

struct S_00a53680_Stream;
struct S_00a53680_Obj
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(int v);
};
struct S_00a53680_Stream : S_00a53680_Obj
{
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
    int unkD8;
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
    int unk24C;
    NiBinaryStream* unk250;
};
__forceinline void S_00a53680_Save(NiBinaryStream* o, void* v, unsigned n, unsigned elem)
{
    unsigned sz = elem;
    // NiBinaryStream currently exposes its callbacks only through declarations.
    unsigned int& position = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(o) + sizeof(void*));
    position += (*reinterpret_cast<NiBinaryStream::WriteFunction*>(reinterpret_cast<char*>(o) + 3 * sizeof(void*)))(
        o, v, n, &sz, 1);
}
// @fnv 0x00a53680
void NiBoolInterpolator::SaveBinary(NiStream& stream)
{
    reinterpret_cast<void (__thiscall*)(NiKeyBasedInterpolator*, NiStream*)>(&NiKeyBasedInterpolator_LinkObject)(this, &stream);
    S_00a53680_Stream* kStream = reinterpret_cast<S_00a53680_Stream*>(&stream);
    S_00a53680_Save(kStream->unk250, &m_bBoolValue, 1, 1);
    kStream->vf12(reinterpret_cast<int>(m_spBoolData.m_pObject));
}

struct FUN_00a536d0_arr
{
    int unk00;
    int unk04;
    unsigned short m_usCapacity;
    unsigned short m_usElementCount;
    unsigned short boolValue;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int newSize);
    void FUN_0096ae90(unsigned int index, void* item);
};

void* NiViewerStrings_NiGetViewerString_Title(int value);
void* NiGetViewerString_00a7d410(const char* fmt, unsigned int value);
void* NiGetViewerString_00a7d5a0(const char* fmt, void* value);
extern int DAT_011f404c;

// @fnv 0x00a536d0
void NiBoolInterpolator::GetViewerStrings(NiViewerStringsArray* strings)
{
    FUN_00a536d0_arr* pArr = reinterpret_cast<FUN_00a536d0_arr*>(strings);
    void* v;
    unsigned int idx;

    reinterpret_cast<void (__thiscall*)(NiKeyBasedInterpolator*, NiViewerStringsArray*)>(&FUN_00a3cbf0)(this, strings);
    v = NiViewerStrings_NiGetViewerString_Title(DAT_011f404c);
    idx = pArr->m_usElementCount;
    if (idx >= pArr->m_usCapacity)
    {
        pArr->FUN_0096ad30(idx + pArr->m_usGrowBy);
    }
    pArr->FUN_0096ae90(idx, &v);

    v = NiGetViewerString_00a7d410("m_bBoolValue", m_bBoolValue);
    idx = pArr->m_usElementCount;
    if (idx >= pArr->m_usCapacity)
    {
        pArr->FUN_0096ad30(idx + pArr->m_usGrowBy);
    }
    pArr->FUN_0096ae90(idx, &v);

    void* pBoolData = m_spBoolData.m_pObject;
    v = NiGetViewerString_00a7d5a0("m_spBoolData", pBoolData);
    idx = pArr->m_usElementCount;
    if (idx >= pArr->m_usCapacity)
    {
        pArr->FUN_0096ad30(idx + pArr->m_usGrowBy);
    }
    pArr->FUN_0096ae90(idx, &v);
}

// @fnv 0x00a53220
bool NiBoolInterpolator::IsEqual(NiObject* object) const
{
    NiBoolInterpolator* other = static_cast<NiBoolInterpolator*>(object);
    if (!reinterpret_cast<bool (__thiscall*)(const NiKeyBasedInterpolator*, NiObject*)>(&bhkCharacterProxy_IsEqual)(this, object))
        return false;
    if (m_bBoolValue != other->m_bBoolValue)
        return false;
    NiBoolData* data = m_spBoolData.m_pObject;
    if ((m_spBoolData.m_pObject && !other->m_spBoolData.m_pObject) || (!m_spBoolData.m_pObject && other->m_spBoolData.m_pObject))
        return false;
    if (m_spBoolData.m_pObject)
    {
        NiBoolData* otherData = other->m_spBoolData.m_pObject;
        if (!static_cast<const NiObject*>(data)->IsEqual(otherData))
            return false;
    }
    return true;
}

// @fnv 0x00a532d0
NiBoolInterpolator::NiBoolInterpolator(bool bFlag) throw() : m_bBoolValue(bFlag)
{
    m_uiLastKeyIndex = 0;
}

extern unsigned char DAT_0109a914;
int __cdecl InterpolateBooleanKey(float fValue, BooleanKey* pkKeys, unsigned int uiArg2, unsigned int uiArg3,
                                  void* pArg4, unsigned char ucArg5);
// @fnv 0x00a533c0
bool NiBoolInterpolator::UpdateBool(float fValue, NiObjectNET* target, bool& out)
{
    unsigned char* pucOut = reinterpret_cast<unsigned char*>(&out);
    unsigned char& boolValue = reinterpret_cast<unsigned char&>(m_bBoolValue);
    if (m_fLastTime == fValue)
    {
        if (boolValue == DAT_0109a914)
        {
            *pucOut = 0;
            return false;
        }
        *pucOut = (boolValue != 0);
        return true;
    }

    NiBoolData* pData = m_spBoolData.m_pObject;
    if (pData != 0)
    {
        unsigned int uiOther = pData->m_eRequestType;
        unsigned int ItemUpdateArray = pData->m_uiNumKeys;
        unsigned char ucFlag = pData->m_ucKeyDataSize;
        BooleanKey* pkKeys = pData->m_pKeyArray;
        if (ItemUpdateArray > 0)
        {
            boolValue = ((unsigned char)InterpolateBooleanKey(fValue, pkKeys, uiOther, ItemUpdateArray, &m_uiLastKeyIndex, ucFlag) != 0);
        }
    }

    if (boolValue == DAT_0109a914)
    {
        *pucOut = 0;
        return false;
    }
    *pucOut = (boolValue != 0);
    m_fLastTime = fValue;
    return true;
}

void __cdecl NiCollisionObject_CopyMembers();

// @fnv 0x00aa0ab0
// src: XBOX_PDB 0x00aa0ab0
void __cdecl NiKeyBasedInterpolator_CopyMembers()
{
    NiCollisionObject_CopyMembers();
}

namespace ni535 {
extern bool DAT_0109a914;
}

inline NiBoolInterpolator::NiBoolInterpolator() throw() : m_bBoolValue(ni535::DAT_0109a914)
{
    m_uiLastKeyIndex = 0;
}

// @fnv 0x00a53590
NiObject* NiBoolInterpolator::MakeClone(CloningProcess& cloning)
{
    NiBoolInterpolator* p = new NiBoolInterpolator;
    CopyMemberData(p, cloning);
    return p;
}

// Supply the existing Read template locally while the shared header is declaration-only.
template <class T> inline void NiBinaryStream::Read(T& value)
{
    unsigned int uiSize = sizeof(T);
    unsigned int& position = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + sizeof(void*));
    position += (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 2 * sizeof(void*)))(
        this, &value, sizeof(T), &uiSize, 1);
}

// @fnv 0x00a53600
void NiBoolInterpolator::LoadBinary(NiStream& kStream)
{
    NiKeyBasedInterpolator::LoadBinary(kStream);
    (*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x24C))->Read(m_bBoolValue);
    m_spBoolData = static_cast<NiBoolData*>(kStream.DeserializeObject());
}

extern unsigned char DAT_0109a914;

struct BKey
{
    float m_fTime;
    unsigned char m_bValue;
    static BKey* GetKeyPointerByIndex(BKey* p, unsigned i, unsigned char s)
    {
        return (BKey*)((char*)p + i * s);
    }
};

// Resolves the boolean data into m_bBoolValue, clearing m_spBoolData when keys are absent or all values are constant.
// @fnv 0x00a530c0
void NiBoolInterpolator::Collapse()
{
    if (m_spBoolData)
    {
        unsigned int uiNumKeys;
        int eRequestType;
        unsigned char ucKeyDataSize;
        eRequestType = m_spBoolData->m_eRequestType;
        ucKeyDataSize = m_spBoolData->m_ucKeyDataSize;
        uiNumKeys = m_spBoolData->m_uiNumKeys;
        BKey* pkKeys = reinterpret_cast<BKey*>(m_spBoolData->m_pKeyArray);
        if (uiNumKeys == 0)
        {
            m_spBoolData = 0;
            reinterpret_cast<unsigned char&>(m_bBoolValue) = DAT_0109a914;
        }
        else
        {
            unsigned char ucFirstValue = BKey::GetKeyPointerByIndex(pkKeys, 0, ucKeyDataSize)->m_bValue;
            bool bConstant;
            if (uiNumKeys == 1)
                bConstant = true;
            else if (eRequestType == 1 || eRequestType == 5)
            {
                bConstant = true;
                for (unsigned int i = 1; bConstant && i < uiNumKeys; i++)
                    if (BKey::GetKeyPointerByIndex(pkKeys, i, ucKeyDataSize)->m_bValue != ucFirstValue)
                        bConstant = false;
            }
            else
                bConstant = false;
            if (bConstant)
            {
                m_spBoolData = 0;
                reinterpret_cast<unsigned char&>(m_bBoolValue) = ucFirstValue;
            }
        }
    }
}
