#include "../../../../include/NiTArray.h"

// src/gamebryo2.2/corelibs/nimain/nifloatsextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nifloatsextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiFloatsExtraData.h"

extern "C" void* g_011f5b60;

// @fnv 0x00a89120
// src: COMMUNITY 0x00a89120
void* __cdecl NiFloatsExtraData_GetRTTI()
{
    return &g_011f5b60;
}

// @fnv 0x00a89190
// src: EXE 0x00a89190
void* __cdecl NiFloatsExtraData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x14);
    if (p != 0)
    {
        NiExtraData* pExtraData = static_cast<NiExtraData*>(p);
        pExtraData->FUN_00a7b2e0();
        *static_cast<void**>(p) = (void*)0x0109ec0c;
        *(int*)(static_cast<char*>(p) + 0x10) = 0;
        *(int*)(static_cast<char*>(p) + 0x0c) = 0;
        return p;
    }
    return 0;
}

// @fnv 0x00a89000
bool __thiscall NiFloatsExtraData::SetValue(const unsigned int uiIndex, float fValue)
{
    if (uiIndex < m_uiSize)
    {
        m_pfValue[uiIndex] = fValue;
        return true;
    }
    return false;
}

void* __cdecl _NiMalloc(unsigned int);
struct CloningProcess
{
    char m_ucUnknownByte[12];
    char m_bExactType;
};
// Copies the base extra data, then allocates and copies the float array from this object into pDest, or clears pDest's array when empty.
// @fnv 0x00a89040
void __thiscall NiFloatsExtraData::CopyFloatsExtraData(NiFloatsExtraData* pDest, CloningProcess* pCloning)
{
    CopyMembers_00a7b330(pDest, pCloning);
    if (!m_pfValue || m_uiSize <= 0)
    {
        pDest->m_pfValue = 0;
        pDest->m_uiSize = 0;
    }
    else
    {
        pDest->m_uiSize = m_uiSize;
        pDest->m_pfValue = (float*)_NiMalloc(m_uiSize * 4);
        for (unsigned int i = 0; i < m_uiSize; ++i)
            pDest->m_pfValue[i] = m_pfValue[i];
    }
}

void __cdecl _NiFreeAlias(void*);
extern int DAT_0109ec0c;
void __cdecl operator delete(void*, unsigned int);
// Releases the float array, resets the vtable, runs base cleanup, and optionally frees the object when flags has bit 0 set.
// @fnv 0x00a891d0
void* __thiscall NiFloatsExtraData::DestroyNiFloatsExtraData(unsigned int flags)
{
    NiFloatsExtraData* p = (NiFloatsExtraData*)this;
    float* v = p->m_pfValue;
    *(void**)this = (void*)&DAT_0109ec0c;
    _NiFreeAlias(v);
    p->m_pfValue = 0;
    NiExtraData::DestroyFields_00a7b300();
    if (flags & 1)
        ::operator delete(this, 0x14);
    return this;
}

// NiFloatsExtraData float accessor: bounds-checked read of the value array.
// @fnv 0x00a89020
float __thiscall NiFloatsExtraData::GetValueAt(unsigned int uiIndex)
{
    if (uiIndex < m_uiSize)
        return m_pfValue[uiIndex];
    return 0.0f;
}

// Compares this NiFloatsExtraData with pOther: checks size, null-ness of the value array, and element-wise equality of the floats.
// @fnv 0x00a890b0
// src: XBOX_PDB 0x00a890b0
bool __thiscall NiFloatsExtraData::IsEqual_00a890b0(const NiFloatsExtraData* pOther)
{
    if (!pOther)
        return false;
    if (m_uiSize != pOther->m_uiSize)
        return false;

    if ((m_pfValue != 0 && pOther->m_pfValue == 0) || (m_pfValue == 0 && pOther->m_pfValue != 0))
        return false;

    if (m_pfValue)
    {
        for (unsigned int i = 0; i < m_uiSize; ++i)
        {
            if (m_pfValue[i] != pOther->m_pfValue[i])
                return false;
        }
    }
    return true;
}

class A89210BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A89210BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A89210BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A89210Object;

class A89210Stream
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(A89210Object* pkObject);

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
    int unk24C;
    A89210BinaryStream* m_pBackingStream;
};

template <class T>
inline void A89210BinaryStreamSave(A89210BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A89210SaveBinary(A89210Stream& kStream, const T& value)
{
    A89210BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

// SaveBinary
// Saves the base extra data, then writes the float array size and values to the stream.
// @fnv 0x00a89210
// src: XBOX_PDB 0x00a89210
void NiFloatsExtraData::SaveBinary_00a89210(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    A89210Stream& kStream = reinterpret_cast<A89210Stream&>(stream);
    A89210SaveBinary(kStream, m_uiSize);
    A89210BinaryStreamSave(*kStream.m_pBackingStream, m_pfValue, m_uiSize);
}

extern "C" void* g_011f5b60;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcText);
char* __cdecl NiGetViewerString_00a7d510(const char* pcPrefix, unsigned int uiValue);
char* __cdecl NiGetViewerString_00a7d550(const char* pcPrefix, float fValue);

template <class T> struct NiFloatsMallocInterface
{
};

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
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
        return SetAtGrow(m_usSize, element);
    }

typedef NiTArray<char*, NiTMallocInterface<char*> > NiFloatsViewerStringsArray;

// NiExtraData does not declare this viewer-array overload in the shared header.
void __cdecl GetExtraDataViewerStrings();

// Appends the base viewer strings, the m_uiSize entry and one entry per element of m_pfValue to pkStrings.
// @fnv 0x00a89280
// src: XBOX_PDB 0x00a89280
void NiFloatsExtraData::GetViewerStrings_00a89280(NiFloatsViewerStringsArray* pkStrings)
{
    typedef void (__thiscall* GetViewerStringsFunction)(NiExtraData*, NiFloatsViewerStringsArray*);
    reinterpret_cast<GetViewerStringsFunction>(&GetExtraDataViewerStrings)(this, pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title((const char*)g_011f5b60));
    pkStrings->Add(NiGetViewerString_00a7d510("m_uiSize", m_uiSize));
    for (unsigned int i = 0; i < m_uiSize; i++)
        pkStrings->Add(NiGetViewerString_00a7d550("m_pfValue[i]", m_pfValue[i]));
}

class BA99A90BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BA99A90BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BA99A90Stream
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
    BA99A90BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void BA99A90BinaryStreamLoad(BA99A90BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BA99A90LoadBinary(BA99A90Stream& kStream, T& value)
{
    BA99A90BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

void* __cdecl NiMalloc(unsigned int uiSize);

// Loads the base extra data, then allocates and reads the float array (or clears it when empty).
// @fnv 0x00a99a90
void NiFloatsExtraData::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    BA99A90Stream& kStream = reinterpret_cast<BA99A90Stream&>(stream);

    BA99A90LoadBinary(kStream, m_uiSize);
    if (m_uiSize > 0)
    {
        m_pfValue = static_cast<float*>(NiMalloc(sizeof(float) * m_uiSize));
        BA99A90BinaryStreamLoad(*kStream.m_pUnderlyingStream, m_pfValue, m_uiSize);
    }
    else
    {
        m_pfValue = 0;
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int uiSize);
// @fnv 0x00a89130
NiFloatsExtraData* NiFloatsExtraData::CreateNiFloatsExtraData(CloningProcess* pCloning)
{
    NiFloatsExtraData* pExtraData = (NiFloatsExtraData*)Object_DispatchCommandFour(0x14);
    NiFloatsExtraData* ret =
        pExtraData
            ? (((NiExtraData*)pExtraData)->FUN_00a7b2e0(), *(void**)pExtraData = (void*)&DAT_0109ec0c,
               pExtraData->m_pfValue = 0, pExtraData->m_uiSize = 0, pExtraData)
            : 0;
    CopyFloatsExtraData(ret, pCloning);
    return ret;
}
