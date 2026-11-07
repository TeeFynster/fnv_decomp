
//
// Compile form of the FNV 2.2 vertex-buffer-manager translation unit for the
// MSVC 2008 (Windows, x86) matcher. This unit defines
// NiD3DHLSLVertexShader::GetEntryPoint (0x00E8BF90, 4 bytes:
// "mov eax,[ecx+0x3c]; ret"). The getter returns the HLSL entry-point string
// held in m_pcShaderEntryPoint, which sits at offset 0x3C (60) inside
// NiD3DHLSLVertexShader, i.e. immediately after the 60-byte NiD3DVertexShader
// base object.

#include "../../../../include/NiD3DHLSLVertexShader.h"
#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiPoint2.h"

// @fnv 0x00E8BF90
const char* NiD3DHLSLVertexShader::GetEntryPoint()
{
    return m_pcShaderEntryPoint;
}

struct Outer;

struct Inner
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int func18(Outer* a, unsigned int b);
    virtual void func1c(Outer* a, unsigned int b);
};

struct Outer
{
    int _00;
    int _04;
    Inner* m08;
    char _0C[20];
    unsigned int m20;
    int _24;
    int* m28;
};

// Calls func1c then func18 on a->m08; if func18 returns nonzero, stores it in a->m28[b] when b < a->m20 and returns true, else false.
// @fnv 0x00e8bfa0
// src: COMMUNITY 0x00e8bfa0
bool __stdcall NiDX9VertexBufferManager_AllocateBufferSpace(Outer* apOuter, unsigned int uiIndex)
{
    Inner* p = apOuter->m08;
    p->func1c(apOuter, uiIndex);
    int v = p->func18(apOuter, uiIndex);
    if (v != 0) {
        if (uiIndex < apOuter->m20)
            apOuter->m28[uiIndex] = v;
        return true;
    }
    return false;
}

void* _memmove(void*, const void*, unsigned int);
// Copies count blocks of size bytes from src to dst, advancing dst by stride and src by size each time.
// @fnv 0x00e8c090
void __stdcall CopyStridedElements(char* apDest, char* src, unsigned int stride, unsigned int size, unsigned int count)
{
    if (count <= 0)
        return;
    unsigned int cnt = count;
    do {
        _memmove(apDest, src, size);
        apDest += stride;
        src += size;
    } while (--cnt);
}

void* __cdecl _memmove(void*, const void*, unsigned int);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct VTBL_00e8c0d0 { char _pad[0x30]; int (__stdcall *fn)(void*); };
struct OBJ_00e8c0d0 { VTBL_00e8c0d0* v; };
struct S_00e8c0d0
{
    char _pad0[0x40];
    void* m_src;
    int _pad1;
    void* m_dst;
    unsigned int m_iElementCount;
    char _pad2[0x30];
    char m_cs[24];
    bool CopyAndRelease(void* p);
};
// @fnv 0x00e8c0d0
bool S_00e8c0d0::CopyAndRelease(void* apObj)
{
    _memmove(m_dst, m_src, m_iElementCount);
    m_dst = 0;
    m_iElementCount = 0;
    LeaveCriticalSection(m_cs);
    OBJ_00e8c0d0* o = (OBJ_00e8c0d0*)apObj;
    return o->v->fn(apObj) >= 0;
}

extern unsigned int DAT_011bf558;

// @fnv 0x00e8c120
// src: COMMUNITY 0x00e8c120
void __stdcall NiDX9VertexBufferManager_GenerateVertexParameters(NiGeometryData* p1, Outer* p2, unsigned int* flags, unsigned int* auiOffset, int* p5,
                            unsigned int* p6, unsigned int* p7, unsigned int* p8, unsigned int* p9)
{
    unsigned int cnt;
    *flags = 0;
    *auiOffset = 0;
    cnt = 0;
    if (p2 != 0) {
        cnt = (unsigned short)p2->m20;
    }
    *p5 = 0;
    *auiOffset += 0xc;
    *p6 = *auiOffset;
    if ((unsigned short)cnt == 0) {
        *flags |= 2;
    } else {
        *flags = 0xa;
        *auiOffset += 0xc;
    }
    if (p1->m_pkNormal != 0) {
        *flags |= 0x10;
        *p7 = *auiOffset;
        *auiOffset += 0xc;
    }
    if (p1->m_pkColor != 0) {
        *flags |= 0x40;
        *p8 = *auiOffset;
        *auiOffset += 4;
    }
    unsigned int n = p1->m_usDataFlags & 1;
    if (n == 0) {
        n = 1;
    } else if (n > DAT_011bf558) {
        n = DAT_011bf558;
    }
    if (n != 0) {
        *flags |= n << 8;
        *p9 = *auiOffset;
        *auiOffset += n * 8;
    }
}

struct Holder_e8bff0 {
    virtual void __stdcall slot00() = 0;
    virtual void __stdcall slot04() = 0;
    virtual void __stdcall slot08() = 0;
    virtual void __stdcall slot0c() = 0;
    virtual void __stdcall slot10() = 0;
    virtual void __stdcall slot14() = 0;
    virtual void __stdcall slot18() = 0;
    virtual void __stdcall slot1c() = 0;
    virtual void __stdcall slot20() = 0;
    virtual void __stdcall slot24() = 0;
    virtual void __stdcall slot28() = 0;
    virtual int __stdcall read(unsigned int type, unsigned int length, unsigned int* out, unsigned int flags) = 0;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
void __cdecl _NiFree_00aa10f0(void* p);
void* __cdecl _NiMalloc_00aa1070(unsigned int n);
void __cdecl FUN_00ec44d0(void* p, unsigned int out, unsigned int n);
struct Owner_e8bff0 {
    void*& Data() { return *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x40); }
    unsigned int& Capacity() { return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x44); }
    unsigned int& Offset() { return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48); }
    unsigned int& Size() { return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x4c); }
    void* CriticalSection() { return reinterpret_cast<char*>(this) + 0x80; }
    void* NiDX9VertexBufferManager_LockVB(Holder_e8bff0* source, unsigned int type, unsigned int length, unsigned int flags);
};
// @fnv 0x00e8bff0
// src: COMMUNITY 0x00e8bff0
void* Owner_e8bff0::NiDX9VertexBufferManager_LockVB(Holder_e8bff0* source, unsigned int type, unsigned int length, unsigned int flags) {
    unsigned int out = 0;
    if (source->read(type, length, &out, flags) < 0)
        return 0;
    EnterCriticalSection(CriticalSection());
    Offset() = out;
    Size() = length;
    if (Capacity() < length) {
        _NiFree_00aa10f0(Data());
        Data() = _NiMalloc_00aa1070(length);
        Capacity() = length;
    }
    if ((flags & 0x3000) == 0)
        FUN_00ec44d0(Data(), out, length);
    return Data();
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

struct BufferDesc { unsigned int type, usage, pool, format, size, fvf; };
struct VertexBuffer {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual int __stdcall Lock(unsigned int, unsigned int, void**, unsigned int);
    virtual int __stdcall Unlock();
    virtual int __stdcall GetDesc(BufferDesc*);
};
struct VertexRecord {
    unsigned int unk00, unk04;
    VertexBuffer* buffer;
    unsigned int offset, flags, size;
};
struct C_00e8f010 {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int count;
    unsigned int* strides;
    VertexRecord** records;
    void FUN_00e8f010(int);
};
struct Class87d40 { void ForwardActorBaseData(void*, int, int, int, int, int); };
struct CriticalSection { unsigned int debug, lock, recursion, owner, semaphore, spin; };
struct Renderer {
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
    char* staging;
    unsigned int capacity;
    char* locked;
    unsigned int lockedSize;
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
    CriticalSection criticalSection;
    void NiDX9VertexBufferManager_GenerateVertexParameters(NiGeometryData*, void*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*);
    bool NiDX9VertexBufferManager_AllocateBufferSpace(C_00e8f010*, unsigned int);
    char* NiDX9VertexBufferManager_LockVB(VertexBuffer*, unsigned int, unsigned int, unsigned int);
    void CopyStridedElements(char*, char*, unsigned int, unsigned int, unsigned int);
    VertexRecord* NiDX9VertexBufferManager_PackUntransformedVB(NiGeometryData*, Class87d40*, unsigned int, VertexRecord*, char*);
};
// src: COMMUNITY 0x00e8c120
__declspec(noinline) void Renderer::NiDX9VertexBufferManager_GenerateVertexParameters(NiGeometryData* d, void* p, unsigned int* a, unsigned int* b, unsigned int* c, unsigned int* e, unsigned int* f, unsigned int* g, unsigned int* h)
{
    *a = unk00; *b = unk04; *c = unk08; *e = unk0c; *f = unk10; *g = unk14; *h = unk18;
}
// @fnv 0x00e8c1e0
// src: COMMUNITY 0x00e8c1e0
VertexRecord* Renderer::NiDX9VertexBufferManager_PackUntransformedVB(NiGeometryData* data, Class87d40* transform, unsigned int dirty, VertexRecord* existing, char* destination)
{
    VertexRecord* record;
    unsigned short count = data->GetVertexCount();
    if (!count) return existing;
    NiPoint3* positions = data->m_pkVertex;
    NiPoint3* normals = data->m_pkNormal;
    NiColorA* colors = data->m_pkColor;
    unsigned int maxTextures = DAT_011bf558;
    unsigned int textureCount = data->m_usDataFlags & 1;
    if (textureCount > maxTextures) textureCount = maxTextures;
    unsigned int fvf = 0, stride = 0;
    unsigned int positionOffset, normalOffset, colorOffset, textureOffset, unusedOffset;
    NiDX9VertexBufferManager_GenerateVertexParameters(data, 0, &fvf, &stride, &positionOffset, &unusedOffset, &normalOffset, &colorOffset, &textureOffset);
    C_00e8f010* bufferData = static_cast<C_00e8f010*>(data->m_pkBuffData);
    bufferData->FUN_00e8f010(fvf);
    if (bufferData->count > 0) bufferData->strides[0] = stride;
    bool unlock = true;
    if (destination) {
        record = existing;
        unlock = false;
    } else {
        BufferDesc desc;
        VertexBuffer* buf;
        if (existing && (buf = existing->buffer) != 0 &&
            (buf->GetDesc(&desc), desc.type == 100 && desc.fvf == fvf && desc.size >= (unsigned short)count * stride)) {
            record = existing;
        } else {
            if (!NiDX9VertexBufferManager_AllocateBufferSpace(bufferData, 0)) return 0;
            record = bufferData->count > 0 ? bufferData->records[0] : 0;
            dirty = 0xfff;
        }
        unsigned int flags = record->flags;
        unsigned int size = record->size;
        unsigned int offset = record->offset;
        VertexBuffer* buffer = record->buffer;
        destination = NiDX9VertexBufferManager_LockVB(buffer, offset, size, flags);
    }
    if (transform) {
        if (positions && (dirty & 1)) {
            char* positionDest = destination + positionOffset;
            char* normalDest = normals ? destination + normalOffset : 0;
            transform->ForwardActorBaseData(data, (int)positionDest, (int)normalDest, 0, 0, stride);
        }
    } else {
        if (positions && (dirty & 1)) CopyStridedElements(destination + positionOffset, (char*)positions, stride, 12, (unsigned short)count);
        if (normals && (dirty & 2)) CopyStridedElements(destination + normalOffset, (char*)normals, stride, 12, (unsigned short)count);
    }
    if (colors && (dirty & 4)) {
        char* output = destination + colorOffset;
        for (unsigned int i = 0; i < (unsigned short)count; ++i) {
            *(unsigned int*)output = (((((fnv_FloatToInt(colors->a * 255.0) << 8) | fnv_FloatToInt(colors->r * 255.0)) << 8) | fnv_FloatToInt(colors->g * 255.0)) << 8) | fnv_FloatToInt(colors->b * 255.0);
            ++colors;
            output += stride;
        }
    }
    if (dirty & 8) {
        for (unsigned int i = 0; i < textureCount; ++i) {
            char* output = destination + textureOffset + i * 8;
            NiPoint2* input = data->NiGeometryData_GetTextureSet((unsigned short)i);
            char* vertex = output;
            for (unsigned int j = 0; j < (unsigned short)count; ++j) {
                *(NiPoint2*)vertex = *input++;
                vertex += stride;
            }

        }
    }
    if (unlock) {
        VertexBuffer* buffer = record->buffer;
        _memmove(locked, staging, lockedSize);
        locked = 0;
        lockedSize = 0;
        LeaveCriticalSection(&criticalSection);
        if (buffer->Unlock() < 0) return 0;
    }
    return record;
}
