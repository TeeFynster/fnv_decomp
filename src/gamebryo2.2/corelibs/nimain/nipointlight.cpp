
// src/gamebryo2.2/corelibs/nimain/nipointlight.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nipointlight.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiObject.h"
#include "../../../../include/NiPointLight.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiUpdateData.h"

// @fnv 0x00a7d730
// src: XBOX_PDB 0x00a7d730
bool NiPointLight::IsEqual_00a7d730(NiObject* pObject)
{
    NiPointLight* pOtherLight = static_cast<NiPointLight*>(pObject);
    if (IsEqual(pOtherLight))
    {
        if (reinterpret_cast<float*>(this)[0x3C] == reinterpret_cast<float*>(pOtherLight)[0x3C] &&
            reinterpret_cast<float*>(this)[0x3D] == reinterpret_cast<float*>(pOtherLight)[0x3D] &&
            reinterpret_cast<float*>(this)[0x3E] == reinterpret_cast<float*>(pOtherLight)[0x3E])
            return true;
    }
    return false;
}

extern const char* const g_011f5ec4_arg1;

// @fnv 0x00a7d790
// src: COMMUNITY 0x00a7d790
const char* const* __cdecl NiPointLight_GetRTTI()
{
    return &g_011f5ec4_arg1;
}

// @fnv 0x00a7d7a0
// src: XBOX_PDB 0x00a7d7a0
void NiPointLight::UpdateWorldData_00a7d7a0(NiUpdateData& update)
{
    NiAVObject::UpdateWorldData(update);
    ++revID;
}

extern const void* g_011f5f6c;

// @fnv 0x00a9b390
// src: COMMUNITY 0x00a9b390
const void* __cdecl NiAmbientLight_GetRTTI()
{
    return &g_011f5f6c;
}

#include "../../../../include/NiMemObject.h"
extern void __fastcall FUN_00a71f60(void* object);
struct FUN_00a71ec0_helper
{
    void FUN_00a71ec0(void* clone, void* process);
};
extern const unsigned int DAT_0109dd0c;
// @fnv 0x00a7d7c0
NiObject* NiPointLight::MakeClone(CloningProcess& process)
{
    NiPointLight* clone;
    void* allocation = NiMemObject::operator new(0xfc);
    if (allocation)
    {
        clone = (NiPointLight*)allocation;
        FUN_00a71f60(clone);
        float zero = 0.0f;
        reinterpret_cast<float*>(clone->storage)[0] = zero;
        *(unsigned int*)clone = (unsigned int)&DAT_0109dd0c;
        clone->effectType = 2;
        float one = 1.0f;
        reinterpret_cast<float*>(clone->storage)[1] = one;
        reinterpret_cast<float*>(clone->storage)[2] = zero;
    }
    else
    {
        clone = 0;
    }
    ((FUN_00a71ec0_helper*)this)->FUN_00a71ec0(clone, &process);
    reinterpret_cast<float*>(clone->storage)[0] = reinterpret_cast<float*>(storage)[0];
    reinterpret_cast<float*>(clone->storage)[1] = reinterpret_cast<float*>(storage)[1];
    reinterpret_cast<float*>(clone->storage)[2] = reinterpret_cast<float*>(storage)[2];
    return clone;
}

// NiPointLight::SaveToStream (NiPointLight vtable slot 20)
//
// The base class stores the light first; afterwards the three light radii
// (unkF0 / unkF4 / unkF8) are handed to the stream buffer that the stream
// keeps at offset 0x24c.  The buffer counts the values it receives, so the
// result of every call is added to the buffer's counter at offset 4.
//
// The callback is called with the buffer itself as its first argument, then
// the radius, the radius size (4), a pointer to an int that is preset to 4
// and a flag of 1.

// The stream buffer: a vtable pointer, a counter and the callback that the
// buffer passes to itself as its first argument.
typedef int (*NiBufferReadFn)(void* buffer, float* data, int size, int* out, int flag);

struct NiStreamBuf
{
    void* unk00;
    int unk04;
    NiBufferReadFn unk08;
};

typedef int (*NiRenderSaveFn)(void* target, float* data, int size, int* out, int flag);

struct NiRenderTarget
{
    void* unk00;
    int unk04;
    void* unk08;
    NiRenderSaveFn unk0C;
};

// NiLight's shared header does not yet declare these two base operations.
// These declarations provide direct base calls without a local light layout.
struct NiLightBaseOperations
{
    void SaveBinary(NiStream& stream);
    void GetViewerStrings(NiViewerStringsArray* strings);
};

// @fnv 0x00a7d840
void NiPointLight::LoadBinary(NiStream& stream)
{
    NiLight::LoadBinary(stream);

    // One block per light radius.  The out value of the callback lives in an
    // inner scope: that is what makes the compiler keep the callback in EDX
    // and hoist its load to the top of the block, exactly like the original.
    {
        NiStreamBuf* buffer = reinterpret_cast<NiStreamBuf*&>(stream.m_pkIstr);
        {
            int count = 4;
            buffer->unk04 += buffer->unk08(buffer, &reinterpret_cast<float*>(storage)[0], 4, &count, 1);
        }
    }

    {
        NiStreamBuf* buffer = reinterpret_cast<NiStreamBuf*&>(stream.m_pkIstr);
        {
            int count = 4;
            buffer->unk04 += buffer->unk08(buffer, &reinterpret_cast<float*>(storage)[1], 4, &count, 1);
        }
    }

    {
        NiStreamBuf* buffer = reinterpret_cast<NiStreamBuf*&>(stream.m_pkIstr);
        {
            int count = 4;
            buffer->unk04 += buffer->unk08(buffer, &reinterpret_cast<float*>(storage)[2], 4, &count, 1);
        }
    }
}

// Calls FUN_00a720f0 then writes the three 4-byte values at unkF0, unkF4 and unkF8 to the output stream at offset 0x250, accumulating the byte counts into its unk04.
// @fnv 0x00a7d8d0
void NiPointLight::SaveBinary(NiStream& stream)
{
    reinterpret_cast<NiLightBaseOperations*>(this)->SaveBinary(stream);

    // One block per light radius.  The out value of the callback lives in an
    // inner scope: that is what makes the compiler keep the callback in EDX
    // and hoist its load to the top of the block, exactly like the original.
    {
        NiRenderTarget* target = reinterpret_cast<NiRenderTarget*&>(stream.m_pkOstr);
        {
            int count = 4;
            target->unk04 += target->unk0C(target, &reinterpret_cast<float*>(storage)[0], 4, &count, 1);
        }
    }

    {
        NiRenderTarget* target = reinterpret_cast<NiRenderTarget*&>(stream.m_pkOstr);
        {
            int count = 4;
            target->unk04 += target->unk0C(target, &reinterpret_cast<float*>(storage)[1], 4, &count, 1);
        }
    }

    {
        NiRenderTarget* target = reinterpret_cast<NiRenderTarget*&>(stream.m_pkOstr);
        {
            int count = 4;
            target->unk04 += target->unk0C(target, &reinterpret_cast<float*>(storage)[2], 4, &count, 1);
        }
    }
}

struct S_00a7d960_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void FUN_0096ad30(unsigned int n);
    void FUN_0096ae90(unsigned int idx, char* const& v);
};

extern unsigned int DAT_011f4a98;
extern const char str_0109de00[];
extern const char str_0109ddf4[];
extern const char str_0109dde8[];
char* __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int v);
char* __cdecl NiGetViewerString_00a7d550(const char* fmt, float v);

inline void S_Push(S_00a7d960_arg* p, char* s)
{
    unsigned int n = p->m_0a;
    if (n >= p->m_08)
    {
        p->FUN_0096ad30(n + p->m_0e);
    }
    p->FUN_0096ae90(n, s);
}

// @fnv 0x00a7d960
void NiPointLight::GetViewerStrings(NiViewerStringsArray* strings)
{
    S_00a7d960_arg* pBuffer = reinterpret_cast<S_00a7d960_arg*>(strings);
    reinterpret_cast<NiLightBaseOperations*>(this)->GetViewerStrings(strings);
    S_Push(pBuffer, NiViewerStrings_NiGetViewerString_Title(DAT_011f4a98));
    S_Push(pBuffer, NiGetViewerString_00a7d550(str_0109de00, reinterpret_cast<float*>(storage)[0]));
    S_Push(pBuffer, NiGetViewerString_00a7d550(str_0109ddf4, reinterpret_cast<float*>(storage)[1]));
    S_Push(pBuffer, NiGetViewerString_00a7d550(str_0109dde8, reinterpret_cast<float*>(storage)[2]));
}

void __cdecl FUN_00a71f50();

// @fnv 0x00a9b360
// src: XBOX_PDB 0x00a9b360
void __cdecl NiAmbientLight_LinkObject()
{
    FUN_00a71f50();
}

void __cdecl FUN_00a720f0(int param1, int param2);

// @fnv 0x00a9b370
// src: XBOX_PDB 0x00a9b370
void __cdecl NiAmbientLight_SaveBinary(int param1, int param2)
{
    FUN_00a720f0(param1, param2);
}

extern void __cdecl FUN_00a72160();

// @fnv 0x00a9b380
// src: XBOX_PDB 0x00a9b380
void __cdecl NiAmbientLight_IsEqual()
{
    FUN_00a72160();
}
