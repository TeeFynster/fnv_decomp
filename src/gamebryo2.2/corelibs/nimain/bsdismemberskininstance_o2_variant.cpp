
// src/gamebryo2.2/corelibs/nimain/bsdismemberskininstance_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/bsdismemberskininstance.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/BSDismemberSkinInstance.h"
#include "../../../../include/NiSkinInstance.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/BSFadeNode.h"

struct A6C900Stream;
struct OutputStream;

// Method-only adapter for declarations absent from the shared header; all object storage comes from BSDismemberSkinInstance.
struct DismemberOperations : BSDismemberSkinInstance
{
    void CopyPartitions(BSDismemberSkinInstance* dest, CloningProcess& cloning);
    BSDismemberSkinInstance* Clone(CloningProcess& cloning);
    void LoadPartitions(A6C900Stream& stream);
    void SavePartitions(OutputStream& stream);
    void AppendViewerStrings(NiTPrimitiveArray<char*>* strings);
};

extern int DAT_01069a84;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// @fnv 0x00a6c8a0
// src: EXE 0x00a6c8a0
BSDismemberSkinInstance* BSDismemberSkinInstance_CreateObject()
{
    BSDismemberSkinInstance* p = (BSDismemberSkinInstance*)BSFadeNode::operator new(sizeof(BSDismemberSkinInstance));
    if (p)
    {
        ::new (p) NiObject;
        p->m_pSkinData.m_pObject = 0;
        p->m_pkSkinMeshPartition.m_pObject = 0;
        p->m_pRootParent = 0;
        p->m_ppBones = 0;
        p->unk1C = 0;
        p->unk20 = 0;
        p->unk24 = 0;
        p->unk28 = 0;
        p->unk30 = 0;
        p->unk34 = 0;
        p->unk38 = 0;
        p->unk18 = -1;
        *(void**)p = (void*)&DAT_01069a84;
        return p;
    }
    return 0;
}

struct P03MM
{
    void* Allocate(unsigned int);
};

extern P03MM _g_memoryManager;

inline void* __cdecl operator new[](unsigned int size)
{
    return _g_memoryManager.Allocate(size);
}

// @fnv 0x00a6c720
void DismemberOperations::CopyPartitions(BSDismemberSkinInstance* pkDest, CloningProcess& kCloning)
{
    NiSkinInstance::CopyMemberData(pkDest, kCloning);

    pkDest->unk34 = unk34;
    if (unk34 > 0)
    {
        pkDest->unk38 = new Partition[unk34];
        for (unsigned int ui = 0; ui < unk34; ++ui)
        {
            pkDest->unk38[ui].enabled = unk38[ui].enabled;
            pkDest->unk38[ui].unk01 = unk38[ui].unk01;
            pkDest->unk38[ui].bodyPart = unk38[ui].bodyPart;
        }
    }
    else
    {
        pkDest->unk38 = 0;
    }
    pkDest->unk3C = unk3C;
}

// Clone lookup uses object-pointer keys; 0x00a53c30 is also bound to NiTMapBase's pointer-key GetAt in nitimecontroller.cpp.
struct CloningProcess
{
    NiTPointerMap<void*, void*>* m_pCloneMap;
};

void* _NiMalloc(unsigned int);

struct SkinData
{
    char _pad[0x44];
    unsigned int m_uiBoneCount;
};

// Inline constructor body until the shared header declares the default constructor.
static inline BSDismemberSkinInstance* InitializeDismember(BSDismemberSkinInstance* p)
{
    ::new (p) NiObject;
    p->m_pSkinData.m_pObject = 0;
    p->m_pkSkinMeshPartition.m_pObject = 0;
    p->m_pRootParent = 0;
    p->m_ppBones = 0;
    p->unk18 = -1;
    p->unk1C = 0;
    p->unk20 = 0;
    p->unk24 = 0;
    p->unk28 = 0;
    p->unk30 = 0;
    *(void**)p = &DAT_01069a84;
    p->unk34 = 0;
    p->unk38 = 0;
    return p;
}

// @fnv 0x00a6c7c0
BSDismemberSkinInstance* DismemberOperations::Clone(CloningProcess& kCloning)
{
    BSDismemberSkinInstance* allocated = (BSDismemberSkinInstance*)BSFadeNode::operator new(sizeof(BSDismemberSkinInstance));
    BSDismemberSkinInstance* pkSkinInstance = allocated ? InitializeDismember(allocated) : 0;
    CopyPartitions(pkSkinInstance, kCloning);

    void* pkClone = 0;
    pkSkinInstance->m_pRootParent = (NiObject*)(kCloning.m_pCloneMap->GetAt(m_pRootParent, pkClone) ? pkClone : m_pRootParent);

    unsigned int uiBoneCount = ((SkinData*)m_pSkinData.m_pObject)->m_uiBoneCount;
    pkSkinInstance->m_ppBones = (NiObject**)_NiMalloc(uiBoneCount * sizeof(void*));

    for (unsigned int i = 0; i < uiBoneCount; ++i)
    {
        pkSkinInstance->m_ppBones[i] = (NiObject*)(kCloning.m_pCloneMap->GetAt(m_ppBones[i], pkClone) ? pkClone : m_ppBones[i]);
    }

    return pkSkinInstance;
}

struct A6C900BinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(A6C900BinaryStream* pkStream, void* pvBuffer, unsigned int uiSize, unsigned int* puiSizes,
                              unsigned int ItemUpdateArray);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};

class A6C900Stream
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
    int unk0D8;
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
    A6C900BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void A6C900BinaryStreamLoad(A6C900BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A6C900LoadBinary(A6C900Stream& kStream, T& value)
{
    A6C900BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

template <class T>
inline void A6C900BinaryStreamLoad(A6C900BinaryStream& kIstr, T* pValue, unsigned int uiNumEls,
                                   unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    kIstr.BinaryRead(pValue, uiNumEls * sizeof(T), puiComponentSizes, uiNumComponents);
}

// @fnv 0x00a6c900
void DismemberOperations::LoadPartitions(A6C900Stream& kStream)
{
    NiSkinInstance::LoadBinary((NiStream&)kStream);
    A6C900LoadBinary(kStream, unk34);
    unk38 = new Partition[unk34];
    unsigned int auiComponentSizes[3] = {1, 1, 2};
    A6C900BinaryStreamLoad(*kStream.m_pUnderlyingStream, unk38, unk34, auiComponentSizes, 3);
    unk3C = 0;
    for (unsigned int i = 0; i < unk34; i++)
        unk3C |= unk38[i].enabled;
}

int sprintf_s(char* buffer, unsigned int size, const char* format, ...);
char* CreateDebugString(const char* pcName);
char* CreateDebugString(const char* pcName, unsigned int uiValue);
char* CreateDebugString(const char* pcName, bool bValue);

#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
// Gamebryo NiTArray.inl bodies this unit's original inlines (the shared NiTArray declares them):
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}

template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::SetAt(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != 0)
            m_usESize++;
    }
    else
    {
        if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != 0)
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}

extern NiRTTI g_kDismemberSkinRTTI;

// @fnv 0x00a6cac0
void DismemberOperations::AppendViewerStrings(NiTPrimitiveArray<char*>* pkStrings)
{
    NiSkinInstance::GetViewerStrings((NiViewerStringsArray*)pkStrings);

    pkStrings->Add(CreateDebugString(g_kDismemberSkinRTTI.m_pcName));
    pkStrings->Add(CreateDebugString("Num Partitions", unk34));
    pkStrings->Add(CreateDebugString("Visible", reinterpret_cast<const bool&>(unk3C)));

    for (unsigned int i = 0; i < unk34; i++)
    {
        BSDismemberSkinInstance::Partition& kData = unk38[i];
        char acTemp[64];
        sprintf_s(acTemp, 64, "%d = BodyPart %d [%s%s]", i, kData.bodyPart, kData.enabled ? "Enabled" : "Disabled",
                  kData.unk01 ? ", State Change" : "");
        pkStrings->Add(CreateDebugString(acTemp));
    }
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short);
extern "C" void _ReadWriteBarrier();

struct OutputBinary
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    void* m_read;
    unsigned int(__cdecl* m_write)(OutputBinary*, void*, unsigned int, unsigned int*, unsigned int);
    typedef unsigned int(__cdecl* Writer)(OutputBinary*, void*, unsigned int, unsigned int*, unsigned int);
    void Write(void* data, unsigned int bytes)
    {

        unsigned int size = 4;
        m_uiStreamFlags += m_write(this, data, bytes, &size, 1);
    }
};
struct OutputStream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char m_bLittleEndian;
    unsigned char unk1E5;
    unsigned short unk1E6;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    OutputBinary* m_pRayCastOutput;
};

static inline void Swap16(unsigned short& value)
{
    value = _byteswap_ushort(value);
}
static inline void Swap32(BSDismemberSkinInstance::Partition& value)
{
    unsigned int* p = reinterpret_cast<unsigned int*>(&value);
    unsigned int in = *p;
    _ReadWriteBarrier();
    *p = _byteswap_ulong(in);
}
// @fnv 0x00a6c9c0
void DismemberOperations::SavePartitions(OutputStream& stream)
{
    NiSkinInstance::SaveBinary((NiStream&)stream);
    {
        stream.m_pRayCastOutput->Write(&unk34, 4);
    }
    if (stream.m_bLittleEndian != 1)
    {
        for (unsigned int i = 0; i < unk34;)
        {
            unsigned int j = i;
            Swap16(unk38[j].bodyPart);
            ++i;
            Swap32(unk38[j]);
        }
    }
    {
        stream.m_pRayCastOutput->Write(unk38, unk34 * 4);
    }
    if (stream.m_bLittleEndian != 1)
    {
        for (unsigned int i = 0; i < unk34; ++i)
        {
            Swap32(unk38[i]);
            Swap16(unk38[i].bodyPart);
        }
    }
}
