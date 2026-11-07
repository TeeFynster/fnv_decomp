
// src/gamebryo2.2/corelibs/nimain/nibinaryextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nibinaryextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryExtraData.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"

extern int DAT_0102e394;

// @fnv 0x00a7f8e0
// src: EXE 0x00a7f8e0
void* __cdecl NiBinaryExtraData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x14);
    if (p)
    {
        ((NiExtraData*)p)->FUN_00a7b2e0();
        *reinterpret_cast<void**>(p) = &DAT_0102e394;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x10) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0xc) = 0;
        return p;
    }
    return 0;
}

inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int totalBytes,
                                               unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesRead = (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 8))(
        this, buffer, totalBytes, componentSizes, componentCount);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += bytesRead;
    return bytesRead;
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

template <class T> inline void NiBinaryStream::Read(T& value)
{
    unsigned int size = sizeof(T);
    BinaryRead(&value, sizeof(T), &size, 1);
}

template <class T> inline unsigned int NiBinaryStream::BinaryRead(T* array, unsigned int count)
{
    unsigned int size = sizeof(T);
    return BinaryRead(array, sizeof(T) * count, &size, 1);
}

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.GetBinaryStream()->Read(value);
}

template <class T> inline void ReadBinaryValue(NiStream& stream, T* array, unsigned int count)
{
    stream.GetBinaryStream()->BinaryRead(array, count);
}

void* NiMalloc(unsigned int size);

// Calls FUN_00a7b4a0, reads m_uiSize from the stream, and if nonzero allocates m_pData and reads m_uiSize bytes into it.
// @fnv 0x00a7f9a0
// src: XBOX_PDB 0x00a7f9a0
void NiBinaryExtraData::LoadBinary_00a7f9a0(NiStream& stream)
{
    FUN_00a7b4a0(stream);
    ReadBinaryValue(stream, m_uiSize);
    if (m_uiSize <= 0)
        return;
    m_pData = (char*)NiMalloc(m_uiSize);
    ReadBinaryValue(stream, m_pData, m_uiSize);
}

namespace fnv_00a7fa20 {
// FUN_00a7fa20 - NiBinaryExtraData::SaveBinary (vtable slot 22 of
// NiBinaryExtraData, overriding NiExtraData::SaveBinary).
//
//   this  : the extra-data object
//          +0x0c : the payload pointer
//          +0x10 : the payload size
//   param : the stream; the node list pointer lives at +0x250 of it
//
// The node exposes a callback at +0x0c.  It is called twice: once to
// register the object (4 bytes) and once - when the size at +0x10 of the
// extra-data object is non-zero - to write the payload.  Both calls take
// a pointer to an out-flag that is set to 4 and to 1 respectively; the
// flag lives in the (dead) incoming argument slot of this frame.

struct FadeNode
{
    int unk00;
    int unk04;  // accumulated callback result
    int unk08;
    int (*unk0c)(FadeNode* node, void* arg2, unsigned int arg3, int* arg4, int arg5);
};

}  // namespace fnv_00a7fa20

// @fnv 0x00a7fa20
// src: XBOX_PDB 0x00a7fa20
void NiBinaryExtraData::SaveBinary_00a7fa20(NiStream* apStream)
{
    this->FUN_00a7b2c0(apStream);
    fnv_00a7fa20::FadeNode* node = *reinterpret_cast<fnv_00a7fa20::FadeNode**>(reinterpret_cast<char*>(apStream) + 0x250);
    {
        int flag = 4;
        node->unk04 += node->unk0c(node, &this->m_uiSize, 4, &flag, 1);
    }
    unsigned int count = this->m_uiSize;
    if (count > 0)
    {
        fnv_00a7fa20::FadeNode* node = *reinterpret_cast<fnv_00a7fa20::FadeNode**>(reinterpret_cast<char*>(apStream) + 0x250);
        void* data = this->m_pData;
        {
            int flag = 1;
            node->unk04 += node->unk0c(node, data, count, &flag, 1);
        }
    }
}

extern unsigned int DAT_011f4ab8;
extern char str_0109df4c[];
void* __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int v);
void* __cdecl NiGetViewerString_00a7d510(const char* fmt, void* v);

// @fnv 0x00a7fa90
// src: XBOX_PDB 0x00a7fa90
void NiBinaryExtraData::GetViewerStrings_00a7fa90(NiStream* pObj)
{
    FUN_00a7b580(pObj);
    void* r = NiViewerStrings_NiGetViewerString_Title(DAT_011f4ab8);
    unsigned int a = *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pObj) + 0x0a);
    if (a >= *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pObj) + 0x08))
    {
        pObj->FUN_0096ad30(a + *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pObj) + 0x0e));
    }
    pObj->FUN_0096ae90(a, reinterpret_cast<const unsigned int*>(&r));
    r = NiGetViewerString_00a7d510(str_0109df4c, data);
    a = *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pObj) + 0x0a);
    if (a >= *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pObj) + 0x08))
    {
        pObj->FUN_0096ad30(a + *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pObj) + 0x0e));
    }
    pObj->FUN_0096ae90(a, reinterpret_cast<const unsigned int*>(&r));
}

struct FUN_00cb9c70_cls
{
    bool Check(int);
};
// @fnv 0x00a89ae0
// src: XBOX_PDB 0x00a89ae0
bool NiBinaryExtraData::RegisterStreamables_00a89ae0(void* a)
{
    return ((FUN_00cb9c70_cls*)this)->Check(reinterpret_cast<int>(a));
}

extern void __cdecl FUN_00a7b3b0();
// @fnv 0x00a9af00
// src: XBOX_PDB 0x00a9af00
void __cdecl NiBinaryExtraData_LinkObject()
{
    FUN_00a7b3b0();
}

#include <string.h>
// Returns true when pkOther is non-null, has the same m_uiSize, and its m_pByteBuffer matches this one via memcmp.
// @fnv 0x00a7f870
bool NiBinaryExtraData::IsEqual(NiObject* object) const
{
    const NiBinaryExtraData* pkOther = static_cast<NiBinaryExtraData*>(object);
    if (!pkOther)
        return false;
    if (m_uiSize != pkOther->m_uiSize)
        return false;
    if (memcmp(m_pByteBuffer, pkOther->m_pByteBuffer, m_uiSize) != 0)
        return false;
    return true;
}

extern void* __cdecl NiMalloc(unsigned int stSize);

// Creates a new NiBinaryExtraData, copies member data, and duplicates the byte buffer when m_uiSize is non-zero.
// @fnv 0x00a7f920
// src: XBOX_PDB 0x00a7f920
NiExtraData* NiBinaryExtraData::CreateClone_00a7f920(CloningProcess& kCloning)
{
    NiBinaryExtraData* pkClone = (NiBinaryExtraData*)NiBinaryExtraData_CreateObject();
    CopyMembers_00a7b330(pkClone, &kCloning);
    if (m_uiSize > 0)
    {
        pkClone->m_pByteBuffer = (char*)NiMalloc(m_uiSize);
        memmove(pkClone->m_pByteBuffer, m_pByteBuffer, m_uiSize);
        pkClone->m_uiSize = m_uiSize;
    }
    else
    {
        pkClone->m_uiSize = 0;
        pkClone->m_pByteBuffer = 0;
    }
    return pkClone;
}
