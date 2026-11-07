#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPalette.h"
#include "../../../../include/NiPersistentSrcTextureRendererData.h"
#include "../../../../include/NiPixelFormat.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiTMap.h"

// src/gamebryo2.2/corelibs/nimain/nipersistentsrctexturerendererdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nipersistentsrctexturerendererdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern char const* const g_0126f9f8_arg1;

// @fnv 0x00e91780
// src: COMMUNITY 0x00e91780
char const* const* __cdecl NiPersistentSrcTextureRendererData_GetRTTI()
{
    return &g_0126f9f8_arg1;
}


extern char const* const DAT_0109f0a0;
NiObject* __cdecl NiPersistentSrcTextureRendererData_CreateObject();

// @fnv 0x00a98460
void __cdecl RegisterNiStreamFactory()
{
    NiStream::UnregisterObjectLoader((char const*)&DAT_0109f0a0);
    NiStream::RegisterObjectLoader((char const*)&DAT_0109f0a0, NiPersistentSrcTextureRendererData_CreateObject);
}

extern "C" void __cdecl _NiFreeAlias(void*);


// Frees m_pucPixels and clears the pixel pointer, width, height and offset fields.
// @fnv 0x00a980e0
void NiPersistentSrcTextureRendererData::FreePixelData()
{
    if (m_pucPixels)
    {
        _NiFreeAlias(m_pucPixels);
        m_puiOffsetInBytes = 0;
        m_puiHeight = 0;
        m_puiWidth = 0;
        m_pucPixels = 0;
    }
}


extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

// Links the object to the stream, then swaps m_spPalette to the stream's palette, releasing the old one and incrementing the new one's refcount.
// @fnv 0x00a98110
void NiPersistentSrcTextureRendererData::LinkPalette(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    NiPalette* pkPalette = (NiPalette*)kStream.GetLoadedObject();
    NiPalette* pkOld = m_spPalette;
    if (pkOld != pkPalette)
    {
        if (pkOld && InterlockedDecrement((long volatile*)&pkOld->m_uiRefCount) == 0)
            pkOld->DeleteThis();
        m_spPalette = pkPalette;
        if (pkPalette)
            InterlockedIncrement((long volatile*)&pkPalette->m_uiRefCount);
    }
}


// Registers the object's streamables with kStream, then registers m_spPalette's streamables if it is set; returns false on failure.
// @fnv 0x00a98170
// src: XBOX_PDB 0x00a98170
bool NiPersistentSrcTextureRendererData::RegisterStreamables_00a98170(NiStream& kStream)
{
    if (!NiObject::RegisterStreamables(kStream))
        return false;
    NiPalette* pkPalette = m_spPalette;
    if (pkPalette)
        pkPalette->RegisterStreamables(kStream);
    return true;
}


void __cdecl UpdateFields_00a98240();
void __cdecl _delete(void*, unsigned int);

// Calls FUN_00a98240, then deletes this with size 0x94 when f has bit 0 set, and returns this.
// @fnv 0x00a98480
void* __fastcall DestroyIfFlagged(NiPersistentSrcTextureRendererData* self, void*, unsigned int auiFlags)
{
    UpdateFields_00a98240();
    if (auiFlags & 1)
        _delete(self, 0x94);
    return self;
}

extern bool DAT_011f5f00;
struct NiBinaryStream_s
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream_s*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream_s*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    unsigned int Write(const void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiSize = 1;
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiBytes, &uiSize, 1);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
template <class T>
inline unsigned int NiBinaryStreamSave_s(NiBinaryStream_s& binstream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return binstream.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
inline NiBinaryStream_s* Ostr_s(NiStream& kStream)
{
    return *(NiBinaryStream_s**)((char*)&kStream + 0x250);
}
template <class T> inline void NiStreamSaveBinary_s(NiStream& kStream, const T& tValue)
{
    NiBinaryStreamSave_s(*Ostr_s(kStream), &tValue, 1);
}
template <class T> inline void NiStreamSaveBinary_s(NiStream& kStream, const T* pValue, unsigned int uiNumEls)
{
    NiBinaryStreamSave_s(*Ostr_s(kStream), pValue, uiNumEls);
}


// Writes the renderer data to the stream: pixel format, palette link ID, mipmap levels, per-level dimensions and offsets, faces, and pixel data.
// @fnv 0x00a984b0
void NiPersistentSrcTextureRendererData::SaveBinary(NiStream& kStream)
{
    // The original calls the empty base hook at 0x00a89af0.
    NiObject::LinkObject(kStream);

    bool bToolModeStreamingValid = DAT_011f5f00 && m_uiPaletteSize && m_uiPaletteEntryCount && m_pucPaletteData;

    m_kPixelFormat.SaveBinary(&kStream);
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_spPalette));
    NiStreamSaveBinary_s(kStream, m_uiMipmapLevels);
    NiStreamSaveBinary_s(kStream, m_uiPixelStride);

    for (unsigned int i = 0; i < m_uiMipmapLevels; i++)
    {
        NiStreamSaveBinary_s(kStream, m_puiWidth[i]);
        NiStreamSaveBinary_s(kStream, m_puiHeight[i]);
        NiStreamSaveBinary_s(kStream, m_puiOffsetInBytes[i]);
    }

    if (bToolModeStreamingValid)
    {
        NiStreamSaveBinary_s(kStream, m_uiPaletteSize);
        NiStreamSaveBinary_s(kStream, m_uiPaletteEntryCount);
    }
    else
    {
        NiStreamSaveBinary_s(kStream, m_puiOffsetInBytes[m_uiMipmapLevels]);
        NiStreamSaveBinary_s(kStream, m_uiPixelDataSize);
    }

    NiStreamSaveBinary_s(kStream, m_uiFaces);
    NiStreamSaveBinary_s(kStream, m_iPaletteFormat);

    if (bToolModeStreamingValid)
        NiStreamSaveBinary_s(kStream, m_pucPaletteData, m_uiPaletteSize * m_uiFaces);
    else
        NiStreamSaveBinary_s(kStream, m_pucPixels, m_puiOffsetInBytes[m_uiMipmapLevels] * m_uiFaces);
}


inline bool IsKindOf_s(const NiRTTI* pkRTTI, NiObject* pkObject)
{
    if (!pkObject)
        return false;
    const NiRTTI* p = pkObject->GetRTTI();
    while (p)
    {
        if (p == pkRTTI)
            return true;
        p = p->m_pBaseRTTI;
    }
    return false;
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

inline NiObject* PaletteObject(NiPalette* const& palette)
{
    return palette;
}

// @fnv 0x00a982f0
// src: XBOX_PDB 0x00a982f0
bool NiPersistentSrcTextureRendererData::IsEqual_00a982f0(NiObject* pkObject)
{
    if (!IsKindOf_s(&ms_kRTTI, pkObject))
        return false;

    if (!NiObject::IsEqual(pkObject))
        return false;

    NiPersistentSrcTextureRendererData* pkData = (NiPersistentSrcTextureRendererData*)pkObject;

    if (m_kPixelFormat != pkData->m_kPixelFormat)
        return false;

    const NiObject* pkPalette = m_spPalette;
    if (pkPalette)
    {
        if (!pkPalette->IsEqual(PaletteObject(pkData->m_spPalette)))
            return false;
    }

    if (m_uiMipmapLevels != pkData->m_uiMipmapLevels || m_uiPixelStride != pkData->m_uiPixelStride)
        return false;

    for (unsigned int i = 0; i < m_uiMipmapLevels; i++)
    {
        if (m_puiWidth[i] != pkData->m_puiWidth[i] || m_puiHeight[i] != pkData->m_puiHeight[i] ||
            m_puiOffsetInBytes[i] != pkData->m_puiOffsetInBytes[i])
            return false;
    }

    if (m_puiOffsetInBytes[m_uiMipmapLevels] != pkData->m_puiOffsetInBytes[m_uiMipmapLevels])
        return false;
    if (m_uiPixelDataSize != pkData->m_uiPixelDataSize)
        return false;
    if (m_uiFaces != pkData->m_uiFaces)
        return false;
    if (m_iPaletteFormat != pkData->m_iPaletteFormat)
        return false;

    if (memcmp(m_pucPixels, pkData->m_pucPixels, m_puiOffsetInBytes[m_uiMipmapLevels]) != 0)
        return false;

    return true;
}

struct ViewerArray
{
    void* vtable;
    char** data;
    unsigned short capacity;
    unsigned short size;
    unsigned short used;
    unsigned short grow;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char* const*);
    void FUN_0096a610(char* const*);
    void SetAtGrow(unsigned int index, char* const& value)
    {
        if (index >= capacity)
            FUN_0096ad30(index + grow);
        FUN_0096ae90(index, &value);
    }
    unsigned int Add(char* const& value)
    {
        unsigned int index = size;
        SetAtGrow(index, value);
        return index;
    }
};

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString_00a7d510(const char*, unsigned int);
char* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);
extern const char* DAT_011f5f04;

inline unsigned int NiPersistentSrcTextureRendererData::GetWidth(unsigned int level) const
{
    return m_puiWidth[level];
}
inline unsigned int NiPersistentSrcTextureRendererData::GetHeight(unsigned int level) const
{
    return m_puiHeight[level];
}
inline const unsigned int& NiPersistentSrcTextureRendererData::GetMipmapLevels() const
{
    return m_uiMipmapLevels;
}
inline const unsigned int& NiPersistentSrcTextureRendererData::GetFaces() const
{
    return m_uiFaces;
}
inline unsigned int NiPersistentSrcTextureRendererData::GetTotalSizeInBytes() const
{
    return m_puiOffsetInBytes[m_uiMipmapLevels] * m_uiFaces;
}
inline unsigned int NiPersistentSrcTextureRendererData::GetFaceSizeInBytes() const
{
    return m_puiOffsetInBytes[m_uiMipmapLevels];
}

// Appends the texture's width, height, mipmap levels, faces, sizes and a target-platform string to the given string array.
// @fnv 0x00a98740
void NiPersistentSrcTextureRendererData::AppendToStrings(ViewerArray* strings)
{
    NiObject::AddViewerStrings((NiViewerStringsArray*)strings);
    char* value = NiViewerStrings_NiGetViewerString_Title(DAT_011f5f04);
    strings->Add(value);
    value = NiGetViewerString_00a7d510("Width", GetWidth());
    strings->Add(value);
    value = NiGetViewerString_00a7d510("Height", GetHeight());
    strings->Add(value);
    value = NiGetViewerString_00a7d510("MipmapLevels", GetMipmapLevels());
    strings->Add(value);
    value = NiGetViewerString_00a7d510("Faces", GetFaces());
    strings->Add(value);
    value = NiGetViewerString_00a7d510("TotalSizeInBytes", GetTotalSizeInBytes());
    strings->Add(value);
    value = NiGetViewerString_00a7d510("FaceSizeInBytes", GetFaceSizeInBytes());
    strings->Add(value);
    switch (m_iPaletteFormat)
    {
    case 0: {
        value = NiGetViewerString_00a7d5e0("TargetPlatform", "NI_ANY - Generic (default)");
        strings->FUN_0096a610(&value);
        break;
    }
    case 3: {
        value = NiGetViewerString_00a7d5e0("TargetPlatform", "NI_DX9");
        strings->FUN_0096a610(&value);
        break;
    }
    case 1: {
        value = NiGetViewerString_00a7d5e0("TargetPlatform", "NI_XENON");
        strings->FUN_0096a610(&value);
        break;
    }
    case 2: {
        value = NiGetViewerString_00a7d5e0("TargetPlatform", "NI_PS3");
        strings->FUN_0096a610(&value);
        break;
    }
    default:
        value = NiGetViewerString_00a7d5e0("TargetPlatform", "UNKNOWN!");
        strings->Add(value);
        break;
    }
}

struct Input
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(Input*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int ReadBytes(void* data, unsigned int bytes)
    {
        unsigned int size = 1;
        unsigned int result = read(this, data, bytes, &size, 1);
        position += result;
        return result;
    }
    unsigned int Read(void* data, unsigned int bytes, unsigned int* sizes, unsigned int count)
    {
        unsigned int result = read(this, data, bytes, sizes, count);
        position += result;
        return result;
    }
};
struct LoadStream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    Input* input;
    void Resolve();
};
template <class T> inline unsigned int BinaryLoad(Input& input, T* value, unsigned int count)
{
    unsigned int size = sizeof(T);
    return input.Read(value, count * size, &size, 1);
}
template <class T> inline void Load(LoadStream& stream, T& value)
{
    BinaryLoad(*stream.input, &value, 1);
}


extern bool DAT_011f5f00;
void* __cdecl NiMalloc(unsigned int);
void* __cdecl memcpy(void*, const void*, unsigned int);
// @fnv 0x00e917e0
void NiPersistentSrcTextureRendererData::LoadBinary(NiStream& kStream)
{
    LoadStream& stream = (LoadStream&)kStream;
    NiObject::LoadBinary(kStream);
    m_kPixelFormat.LoadBinary(&kStream);
    stream.Resolve();
    Load(stream, m_uiMipmapLevels);
    Load(stream, m_uiPixelStride);
    unsigned int widths[16], heights[16], mipOffsets[16];
    for (unsigned int level = 0; level < m_uiMipmapLevels; ++level)
    {
        Load(stream, widths[level]);
        Load(stream, heights[level]);
        Load(stream, mipOffsets[level]);
    }
    Load(stream, mipOffsets[m_uiMipmapLevels]);
    if (stream.unk0d8 >= 0x14020006)
    {
        m_uiPixelDataSize = 0;
        Load(stream, m_uiPixelDataSize);
    }
    else
        m_uiPixelDataSize = mipOffsets[m_uiMipmapLevels];
    Load(stream, m_uiFaces);
    {
        int platform;
        Load(stream, platform);
        m_iPaletteFormat = platform;
    }
    AllocateMipMap(m_uiMipmapLevels, m_uiFaces, mipOffsets[m_uiMipmapLevels]);
    unsigned int bytesPerLevel = m_uiMipmapLevels * 4;
    memcpy(m_puiWidth, widths, bytesPerLevel);
    memcpy(m_puiHeight, heights, bytesPerLevel);
    memcpy(m_puiOffsetInBytes, mipOffsets, (m_uiMipmapLevels + 1) * 4);
    stream.input->ReadBytes(m_pucPixels, m_puiOffsetInBytes[m_uiMipmapLevels] * m_uiFaces);
    if (DAT_011f5f00)
    {
        m_uiPaletteSize = m_puiOffsetInBytes[m_uiMipmapLevels];
        m_uiPaletteEntryCount = m_uiPixelDataSize;
        unsigned int bytes = m_uiPaletteSize * m_uiFaces;
        m_pucPaletteData = (unsigned char*)NiMalloc(bytes);
        memcpy(m_pucPaletteData, m_pucPixels, bytes);
    }
}

namespace fnv_00e75a70 {
extern "C" long __declspec(dllimport) __stdcall InterlockedDecrement(volatile long*) throw();
extern "C" void __cdecl _NiFreeAlias(void*) throw();
inline void NiFree(void* p) throw()
{
    _NiFreeAlias(p);
}

extern "C" void __cdecl FUN_00aa1460(void*, unsigned int) throw();
extern "C" void __cdecl RunRegistryHandlers() throw();
extern "C" int __cdecl NiD3DShaderInterface_ShutdownShaderSystem() throw();
extern "C" void __cdecl NiDX9AdditionalDepthStencilBufferData_ShutdownAll() throw();
extern "C" void __cdecl ReleaseShaderNodes(void*) throw();
extern "C" void __cdecl NiStream_UnregisterLoader(const char*) throw();
void __cdecl RegisterNiStreamFactory() throw();

extern int DAT_011bf558;
extern int DAT_0126f0ec;
extern void* DAT_0126f108[256];

extern MemoryManager DAT_011f6238;


template <class T> struct NiPointerArray4
{
    T* m_iWordAt00;
    T* m_cByteAtOffset1;
    T* m_cByteAtOffset2;
    T* m_cByteAtOffset3;
    __forceinline ~NiPointerArray4() throw()
    {
        T** p = &m_cByteAtOffset3 + 1;
        for (int i = 3; i >= 0; --i)
        {
            T* obj = *--p;
            if (obj)
            {
                if (InterlockedDecrement((volatile long*)&obj->m_uiRefCount) == 0)
                    obj->DeleteThis();
            }
        }
    }
    operator T**() throw()
    {
        return &m_iWordAt00;
    }
};

struct CachedGeometrySub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiRefObject* m_pReferencedObject;
};

struct GeometryCacheEntry : public NiRefObject
{
    virtual void cg_0() throw();
    virtual void cg_1() throw();
    virtual void cg_2() throw();
    virtual void cg_3() throw();
    virtual void cg_4() throw();
    virtual void cg_5() throw();
    virtual void cg_6() throw();
    virtual void cg_7() throw();
    virtual void cg_8() throw();
    virtual void cg_9() throw();
    virtual void cg_10() throw();
    virtual void cg_11() throw();
    virtual void cg_12() throw();
    virtual void cg_13() throw();
    virtual void cg_14() throw();
    virtual void cg_15() throw();
    virtual void cg_16() throw();
    virtual void cg_17() throw();
    virtual void cg_18() throw();
    virtual void cg_19() throw();
    virtual void cg_20() throw();
    virtual void cg_21() throw();
    virtual void cg_22() throw();
    virtual void cg_23() throw();
    virtual void cg_24() throw();
    virtual void cg_25() throw();
    virtual void cg_26() throw();
    virtual void cg_27() throw();
    virtual void cg_28() throw();
    virtual void cg_29() throw();
    virtual void cg_30() throw();
    virtual void cg_31() throw();
    virtual void cg_32() throw();
    virtual void cg_33() throw();
    virtual void cg_34() throw();
    virtual void cg_35() throw();
    virtual void cg_36() throw();
    virtual void cg_37() throw();
    virtual void cg_38() throw();
    virtual unsigned int GetCount() throw();
    virtual void cg2_0() throw();
    virtual void cg2_1() throw();
    virtual CachedGeometrySub* GetSub(unsigned int) throw();
    virtual CachedGeometrySub* GetExtra() throw();
};

}  // namespace fnv_00e75a70

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{}
template <class T> inline NiPointer<T>::~NiPointer()
{
    T* pkNew = m_pObject;
    if (pkNew)
    {
        if (InterlockedDecrement((volatile long*)&pkNew->m_uiRefCount) == 0)
            pkNew->DeleteThis();
    }
}
template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}
template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

template <class Alloc, class Key, class Val> inline NiTMapBase<Alloc, Key, Val>::~NiTMapBase()
{
    RemoveAll();
    fnv_00e75a70::NiFree(m_ppkHashTable);
}
template <class Alloc, class Key, class Val> inline void* NiTMapBase<Alloc, Key, Val>::GetFirstPos() const
{
    for (unsigned int i = 0; i < m_uiHashSize; i++)
    {
        if (m_ppkHashTable[i])
            return m_ppkHashTable[i];
    }
    return 0;
}
template <class Alloc, class Key, class Val>
inline void NiTMapBase<Alloc, Key, Val>::GetNext(void*& pos, Key& key, Val& val) const
{
    NiTMapItem<Key, Val>* pItem = (NiTMapItem<Key, Val>*)pos;
    void* next = pItem->m_pkNext;
    key = pItem->m_key;
    val = pItem->m_val;
    if (next)
    {
        pos = next;
        return;
    }
    unsigned int i = KeyToHashIndex(pItem->m_key);
    for (i++; i < m_uiHashSize; i++)
    {
        NiTMapItem<Key, Val>* found = m_ppkHashTable[i];
        if (found)
        {
            pos = found;
            return;
        }
    }
    pos = 0;
}

// Renderer cache map: vftable 0x010edb1c; GetNext 0x00e6e630 copies a NiPointer value (also used by TallGrassShaderProperty).
template <>
__declspec(noalias) void NiTMapBase<NiTPointerAllocator<unsigned int>, const char*,
    NiPointer<fnv_00e75a70::GeometryCacheEntry> >::GetNext(void*& pos, const char*& key,
    NiPointer<fnv_00e75a70::GeometryCacheEntry>& val) const;

template <class Key, class Val> inline NiTPointerMap<Key, Val>::~NiTPointerMap()
{
    this->RemoveAll();
}
template <class Key, class Val> inline NiTMap<Key, Val>::~NiTMap()
{
    this->RemoveAll();
}

#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
// Gamebryo NiTArray.inl / NiTCollection.h bodies the original inlines into Member_900's destructor
template <class T> inline void NiTMallocInterface<T>::Deallocate(T* pArray)
{
    fnv_00e75a70::NiFree(pArray);
}
template <class T, class TAlloc> inline NiTArray<T, TAlloc>::~NiTArray()
{
    TAlloc::Deallocate(m_pBase);
}
namespace fnv_00e75a70 {

struct Member_900
{
    int unk00;
    int unk04;
    int unk08;
    ~Member_900() throw();
};

struct Member_90c
{
    int unk00;
    int unk04;
    int unk08;
    ~Member_90c() throw();
};

struct IDirect3DDevice9_Custom
{
    virtual long __stdcall QueryInterface(void*, void**) throw();
    virtual long __stdcall AddRef() throw();
    virtual long __stdcall Release() throw();
    virtual void d3d_0() throw();
    virtual void d3d_1() throw();
    virtual void d3d_2() throw();
    virtual void d3d_3() throw();
    virtual void d3d_4() throw();
    virtual void d3d_5() throw();
    virtual void d3d_6() throw();
    virtual void d3d_7() throw();
    virtual void d3d_8() throw();
    virtual void d3d_9() throw();
    virtual void d3d_10() throw();
    virtual void d3d_11() throw();
    virtual void d3d_12() throw();
    virtual void d3d_13() throw();
    virtual void d3d_14() throw();
    virtual void d3d_15() throw();
    virtual void d3d_16() throw();
    virtual void d3d_17() throw();
    virtual void d3d_18() throw();
    virtual void d3d_19() throw();
    virtual void d3d_20() throw();
    virtual void d3d_21() throw();
    virtual void d3d_22() throw();
    virtual void d3d_23() throw();
    virtual void d3d_24() throw();
    virtual void d3d_25() throw();
    virtual void d3d_26() throw();
    virtual void d3d_27() throw();
    virtual void d3d_28() throw();
    virtual void d3d_29() throw();
    virtual void d3d_30() throw();
    virtual void d3d_31() throw();
    virtual void d3d_32() throw();
    virtual void d3d_33() throw();
    virtual void d3d_34() throw();
    virtual void d3d_35() throw();
    virtual void d3d_36() throw();
    virtual void d3d_37() throw();
    virtual void d3d_38() throw();
    virtual void d3d_39() throw();
    virtual void d3d_40() throw();
    virtual void d3d_41() throw();
    virtual void d3d_42() throw();
    virtual void d3d_43() throw();
    virtual void d3d_44() throw();
    virtual void d3d_45() throw();
    virtual void d3d_46() throw();
    virtual void d3d_47() throw();
    virtual void d3d_48() throw();
    virtual void d3d_49() throw();
    virtual void d3d_50() throw();
    virtual void d3d_51() throw();
    virtual void d3d_52() throw();
    virtual void d3d_53() throw();
    virtual void d3d_54() throw();
    virtual void d3d_55() throw();
    virtual void d3d_56() throw();
    virtual void d3d_57() throw();
    virtual void d3d_58() throw();
    virtual void d3d_59() throw();
    virtual void d3d_60() throw();
    virtual void d3d_61() throw();
    virtual void d3d_62() throw();
    virtual void d3d_63() throw();
    virtual void d3d_64() throw();
    virtual void d3d_65() throw();
    virtual void d3d_66() throw();
    virtual void d3d_67() throw();
    virtual void d3d_68() throw();
    virtual void d3d_69() throw();
    virtual void d3d_70() throw();
    virtual void d3d_71() throw();
    virtual void d3d_72() throw();
    virtual void d3d_73() throw();
    virtual void d3d_74() throw();
    virtual void d3d_75() throw();
    virtual void d3d_76() throw();
    virtual void d3d_77() throw();
    virtual void d3d_78() throw();
    virtual void d3d_79() throw();
    virtual void d3d_80() throw();
    virtual void d3d_81() throw();
    virtual void d3d_82() throw();
    virtual void d3d_83() throw();
    virtual void d3d_84() throw();
    virtual void d3d_85() throw();
    virtual void d3d_86() throw();
    virtual void d3d_87() throw();
    virtual void d3d_88() throw();
    virtual void d3d_89() throw();
    virtual void d3d_90() throw();
    virtual void d3d_91() throw();
    virtual void d3d_92() throw();
    virtual void d3d_93() throw();
    virtual void d3d_94() throw();
    virtual void d3d_95() throw();
    virtual void d3d_96() throw();
    virtual long __stdcall Method100(unsigned int, unsigned int, unsigned int, unsigned int) throw();
    virtual void d3d2_0() throw();
    virtual void d3d2_1() throw();
    virtual void d3d2_2() throw();
    virtual long __stdcall Method104(unsigned int) throw();
};

struct Obj8B8
{
    virtual void o8b8_0() throw();
    virtual void o8b8_1() throw();
    virtual void o8b8_2() throw();
    virtual void o8b8_3() throw();
    virtual void o8b8_4() throw();
    virtual void o8b8_5() throw();
    virtual void o8b8_6() throw();
    virtual void o8b8_7() throw();
    virtual void o8b8_8() throw();
    virtual void o8b8_9() throw();
    virtual void o8b8_10() throw();
    virtual void o8b8_11() throw();
    virtual void o8b8_12() throw();
    virtual void o8b8_13() throw();
    virtual void o8b8_14() throw();
    virtual void o8b8_15() throw();
    virtual void o8b8_16() throw();
    virtual void o8b8_17() throw();
    virtual void o8b8_18() throw();
    virtual void o8b8_19() throw();
    virtual void o8b8_20() throw();
    virtual void o8b8_21() throw();
    virtual void o8b8_22() throw();
    virtual void o8b8_23() throw();
    virtual void o8b8_24() throw();
    virtual void o8b8_25() throw();
    virtual void o8b8_26() throw();
    virtual void o8b8_27() throw();
    virtual void o8b8_28() throw();
    virtual void o8b8_29() throw();
    virtual void o8b8_30() throw();
    virtual void o8b8_31() throw();
    virtual void o8b8_32() throw();
    virtual void o8b8_33() throw();
    virtual void o8b8_34() throw();
    virtual void o8b8_35() throw();
    virtual void o8b8_36() throw();
    virtual void o8b8_37() throw();
    virtual void o8b8_38() throw();
    virtual void o8b8_39() throw();
    virtual void o8b8_40() throw();
    virtual void o8b8_41() throw();
    virtual void o8b8_42() throw();
    virtual void o8b8_43() throw();
    virtual void o8b8_44() throw();
    virtual void o8b8_45() throw();
    virtual void o8b8_46() throw();
    virtual void o8b8_47() throw();
    virtual void o8b8_48() throw();
    virtual void o8b8_49() throw();
    virtual void o8b8_50() throw();
    virtual void o8b8_51() throw();
    virtual void o8b8_52() throw();
    virtual void o8b8_53() throw();
    virtual void o8b8_54() throw();
    virtual void Method55(unsigned int, unsigned int) throw();
};

struct IDirect3DInterface_Custom
{
    virtual void Delete(unsigned int) throw();
    virtual void Unknown() throw();
    virtual void Detach(void*) throw();
};

struct E8B630_Obj
{
    void ProcessEntries_00e8b630() throw();
};

struct PrePackObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    PrePackObject* m_pkNext;
};

struct FreeListNode
{
    int unk00;
    int unk04;
    int unk08;
    FreeListNode* next;
};

class Base_00a62b60
{
  public:
    virtual ~Base_00a62b60() throw();
};

class FUN_00e75a70 : public Base_00a62b60
{
  public:
    virtual ~FUN_00e75a70() throw();

    void NiDX9Renderer_PurgeAllD3DShaders() throw();
    void ClearArrays() throw();
    void ResetPools() throw();

    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    IDirect3DDevice9_Custom* m_pDirect3DDevice;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059c;
    int unk05a0;
    int unk05a4;
    int unk05a8;
    int unk05ac;
    int unk05b0;
    int unk05b4;
    int unk05b8;
    int unk05bc;
    int unk05c0;
    int unk05c4;
    int unk05c8;
    int unk05cc;
    int unk05d0;
    int unk05d4;
    int unk05d8;
    int unk05dc;
    int unk05e0;
    int unk05e4;
    int unk05e8;
    int unk05ec;
    int unk05f0;
    int unk05f4;
    int unk05f8;
    int unk05fc;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060c;
    NiTPointerMap<unsigned int, PrePackObject*> m_kMap610;
    FreeListNode* m_pkFreeList;
    unsigned int m_uiFreeListCount;
    int unk0628;
    int unk062c;
    NiPointer<NiRefObject> m_sp630;
    int unk0634;
    int unk0638;
    int unk063c;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064c;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065c;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066c;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067c;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068c;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069c;
    int unk06a0;
    int unk06a4;
    int unk06a8;
    int unk06ac;
    int unk06b0;
    int unk06b4;
    int unk06b8;
    int unk06bc;
    int unk06c0;
    int unk06c4;
    int unk06c8;
    int unk06cc;
    int unk06d0;
    int unk06d4;
    int unk06d8;
    int unk06dc;
    int unk06e0;
    int unk06e4;
    unsigned int m_uiAnimationCount;
    int unk06ec;
    int unk06f0;
    int unk06f4;
    int unk06f8;
    int unk06fc;
    void* m_p700[4][22];
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086c;
    NiPointerArray4<NiRefObject> m_sp870;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088c;
    NiTPointerMap<const char*, NiPointer<GeometryCacheEntry> > m_kMap890;
    int unk08a0;
    int unk08a4;
    void* m_p8a8;
    IDirect3DInterface_Custom* m_p8ac;
    void* m_p8b0;
    void* m_p8b4;
    Obj8B8* m_p8b8;
    IDirect3DInterface_Custom* m_p8bc;
    IDirect3DInterface_Custom* m_p8c0;
    IDirect3DInterface_Custom* m_p8c4;
    E8B630_Obj* m_p8c8;
    NiTPointerMap<void*, NiRefObject*> m_kMap8cc;
    NiTPointerMap<unsigned int, NiRefObject*> m_kMap8dc;
    NiTPointerMap<void*, void*> m_kMap8ec;
    NiPointer<NiRefObject> m_sp8fc;
    Member_900 m_k900;
    Member_90c m_k90c;
    int unk0918;
    int unk091c;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092c;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093c;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094c;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095c;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096c;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097c;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098c;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099c;
    int unk09a0;
    int unk09a4;
    int unk09a8;
    int unk09ac;
    int unk09b0;
    int unk09b4;
    int unk09b8;
    int unk09bc;
    int unk09c0;
    int unk09c4;
    int unk09c8;
    int unk09cc;
    int unk09d0;
    int unk09d4;
    int unk09d8;
    int unk09dc;
    int unk09e0;
    int unk09e4;
    int unk09e8;
    int unk09ec;
    int unk09f0;
    int unk09f4;
    int unk09f8;
    int unk09fc;
    int unk0a00;
    int unk0a04;
    int unk0a08;
    int unk0a0c;
    int unk0a10;
    int unk0a14;
    int unk0a18;
    int unk0a1c;
    int unk0a20;
    int unk0a24;
    int unk0a28;
    int unk0a2c;
    int unk0a30;
    int unk0a34;
    int unk0a38;
    int unk0a3c;
    int unk0a40;
    int unk0a44;
    int unk0a48;
    int unk0a4c;
    int unk0a50;
    int unk0a54;
    int unk0a58;
    int unk0a5c;
    int unk0a60;
    int unk0a64;
    int unk0a68;
    int unk0a6c;
    int unk0a70;
    int unk0a74;
    int unk0a78;
    int unk0a7c;
    void* m_pa80;
    void* m_pa84;
    void* m_pa88;
    int unk0a8c;
    void* m_pa90;
    int unk0a94;
    int unk0a98;
    int unk0a9c;
    int unk0aa0;
    int unk0aa4;
    int unk0aa8;
    int unk0aac;
    int unk0ab0;
    int unk0ab4;
    int unk0ab8;
    int unk0abc;
    int unk0ac0;
    int unk0ac4;
    int unk0ac8;
    int unk0acc;
    int unk0ad0;
    // element types from the RTTI of the vftables ~Member_900 stores (0x010edaec, 0x010edae4, 0x010edaf4)
    NiTPrimitiveArray<bool(__cdecl*)(bool, void*)> m_kArrayAd4;
    NiTPrimitiveArray<void*> m_kArrayAe4;
    NiTPrimitiveArray<bool(__cdecl*)(void*)> m_kArrayAf4;
    NiTPrimitiveArray<void*> m_kArrayB04;
    NiTMap<unsigned int, void*> m_kMapB14;
    int unk0b24;
    int unk0b28;
    int unk0b2c;
    int unk0b30;
    int unk0b34;
    int unk0b38;
    int unk0b3c;
    int unk0b40;
    int unk0b44;
    int unk0b48;
    int unk0b4c;
    int unk0b50;
    int unk0b54;
    int unk0b58;
    int unk0b5c;
    int unk0b60;
    int unk0b64;
    int unk0b68;
    int unk0b6c;
    int unk0b70;
    int unk0b74;
    int unk0b78;
    int unk0b7c;
};

// @fnv 0x00e75a70
FUN_00e75a70::~FUN_00e75a70() throw()
{
    if (m_pDirect3DDevice)
    {
        if (m_p8b8)
        {
            for (unsigned int i = 0; i < (unsigned int)DAT_011bf558; i++)
            {
                m_p8b8->Method55(i, 0);
            }
        }
        for (unsigned int i = 0; i < m_uiAnimationCount; i++)
        {
            m_pDirect3DDevice->Method100(i, 0, 0, 0);
        }
        m_pDirect3DDevice->Method104(0);
    }

    NiRefObject** p870 = m_sp870;
    void** p700 = &m_p700[0][0];
    unsigned int loc0 = 4;
    do
    {
        unsigned int count = 22;
        do
        {
            DAT_011f6238.Deallocate(*p700);
            ++p700;
        } while (--count);
        NiRefObject* obj = *p870;
        if (obj)
        {
            if (InterlockedDecrement((volatile long*)&obj->m_uiRefCount) == 0)
                obj->DeleteThis();
            *p870 = 0;
        }
        p870++;
    } while (--loc0);

    FreeListNode* item = m_pkFreeList;
    if (item)
    {
        do
        {
            FreeListNode* next = item->next;
            FreeListNode* old = (FreeListNode*)DAT_0126f0ec;
            DAT_0126f0ec = (int)item;
            item->next = old;
            item = next;
        } while (item);
    }
    m_pkFreeList = 0;
    m_uiFreeListCount = 0;

    for (FreeListNode* p = (FreeListNode*)DAT_0126f0ec; p;)
    {
        FreeListNode* next = p->next;
        FUN_00aa1460(p, 0x10);
        p = next;
    }
    DAT_0126f0ec = 0;

    // Map 610
    void* pos610 = m_kMap610.GetFirstPos();
    if (pos610)
    {
        do
        {
            unsigned int key;
            PrePackObject* val;
            m_kMap610.GetNext(pos610, key, val);
            while (val)
            {
                PrePackObject* nextVal = val->m_pkNext;
                if (nextVal)
                {
                    m_kMap610.SetAt(key, nextVal);
                }
                else
                {
                    m_kMap610.RemoveAt(key);
                }
                FUN_00aa1460(val, 0x24);
                val = nextVal;
            }
        } while (pos610);
    }

    RunRegistryHandlers();
    NiDX9Renderer_PurgeAllD3DShaders();
    NiD3DShaderInterface_ShutdownShaderSystem();
    NiDX9AdditionalDepthStencilBufferData_ShutdownAll();
    m_kMap8cc.RemoveAll();
    m_kMap8dc.RemoveAll();
    m_kMap8ec.RemoveAll();
    ReleaseShaderNodes(this);

    // Map 890
    void* pos890 = m_kMap890.GetFirstPos();
    if (pos890)
    {
        do
        {
            const char* key890;
            NiPointer<GeometryCacheEntry> output;
            m_kMap890.GetNext(pos890, key890, output);
            GeometryCacheEntry* geom = output;
            if (geom)
            {
                for (unsigned int j = 0; j < geom->GetCount(); j++)
                {
                    CachedGeometrySub* sub = geom->GetSub(j);
                    if (sub)
                    {
                        NiRefObject* obj = sub->m_pReferencedObject;
                        if (obj)
                        {
                            if (InterlockedDecrement((volatile long*)&obj->m_uiRefCount) == 0)
                                obj->DeleteThis();
                            sub->m_pReferencedObject = 0;
                        }
                    }
                }
                CachedGeometrySub* extra = geom->GetExtra();
                if (extra)
                {
                    NiRefObject* obj = extra->m_pReferencedObject;
                    if (obj)
                    {
                        if (InterlockedDecrement((volatile long*)&obj->m_uiRefCount) == 0)
                            obj->DeleteThis();
                        extra->m_pReferencedObject = 0;
                    }
                }
            }
        } while (pos890);
    }
    m_kMap890.RemoveAll();

    // Map B14
    NiTMap<unsigned int, void*>* pMapB14 = &m_kMapB14;
    void* posB14 = pMapB14->GetFirstPos();
    while (posB14)
    {
        unsigned int keyB14;
        void* valB14;
        pMapB14->GetNext(posB14, keyB14, valB14);
        DAT_011f6238.Deallocate(valB14);
    }

    m_p8a8 = 0;
    if (m_p8bc)
    {
        m_p8bc->Delete(1);
    }
    m_p8bc = 0;
    if (m_p8c0)
    {
        m_p8c0->Delete(1);
        m_p8c0 = 0;
    }
    if (m_p8ac)
    {
        m_p8ac->Detach(m_p8b0);
        m_p8ac->Detach(m_p8b4);
        if (m_p8ac)
            m_p8ac->Delete(1);
        m_p8ac = 0;
    }
    if (m_p8b8)
    {
        IDirect3DInterface_Custom* iface = (IDirect3DInterface_Custom*)m_p8b8;
        iface->Delete(1);
    }
    m_p8b8 = 0;
    if (m_p8c4)
    {
        m_p8c4->Delete(1);
    }
    m_p8c4 = 0;
    E8B630_Obj* object8c8 = m_p8c8;
    if (object8c8)
    {
        object8c8->ProcessEntries_00e8b630();
        FUN_00aa1460(object8c8, 0x23c);
    }
    m_p8c8 = 0;

    for (unsigned int i = 0; i < 256; i++)
    {
        NiRefObject* obj = (NiRefObject*)DAT_0126f108[i];
        if (obj)
        {
            if (InterlockedDecrement((volatile long*)&obj->m_uiRefCount) == 0)
                obj->DeleteThis();
            DAT_0126f108[i] = 0;
        }
    }

    if (m_pDirect3DDevice)
    {
        m_pDirect3DDevice->Release();
        m_pDirect3DDevice = 0;
    }

    DAT_011f6238.Deallocate(m_pa80);
    DAT_011f6238.Deallocate(m_pa84);
    DAT_011f6238.Deallocate(m_pa88);
    NiFree(m_pa90);

    ClearArrays();
    ResetPools();
    NiStream_UnregisterLoader("NiPersistentSrcTextureRendererData");
    RegisterNiStreamFactory();
}
}  // namespace fnv_00e75a70

void* __cdecl _NiMalloc_00aa1070(unsigned int size);


// Allocates a pixel buffer and sets m_puiWidth, m_puiHeight, and m_puiOffsetInBytes for a mip map with uiLevels and uiFaces.
// @fnv 0x00a98090
void NiPersistentSrcTextureRendererData::AllocateMipMap(unsigned int uiLevels, unsigned int uiFaces, unsigned int uiBytes)
{
    unsigned int uiStride = (uiBytes + 3) & ~3;
    unsigned int uiTotal = *(volatile unsigned int*)&uiFaces * uiStride;
    m_pucPixels = (unsigned char*)_NiMalloc_00aa1070(uiTotal + uiLevels * 12 + 4);
    m_puiWidth = (unsigned int*)(m_pucPixels + uiTotal);
    m_puiHeight = m_puiWidth + uiLevels;
    m_puiOffsetInBytes = m_puiHeight + uiLevels;
}
