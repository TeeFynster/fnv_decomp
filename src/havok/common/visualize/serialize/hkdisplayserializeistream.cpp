// src/havok/common/visualize/serialize/hkdisplayserializeistream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkdisplayserializeistream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV_VEC4_SIMD
#include "../../../../../include/Vec4.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/BSAudio.h"
#include "../../../../../include/hkDisplaySerializeIStream.h"
#include "../../../../../include/hkIArchive.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkRotation.h"

struct ArchiveByteFlag
{
    bool b;
    ArchiveByteFlag() : b(false)
    {}
    ArchiveByteFlag(const ArchiveByteFlag& o) : b(o.b)
    {}
};

// The shared headers do not declare these constructors. Keep their ABI here
// without a local archive or display-stream class.
extern "C" void ConstructIArchive();
extern "C" void* DisplaySerializeIStreamVtable[];
typedef void (__thiscall* IArchiveConstructor)(hkIArchive*, int, ArchiveByteFlag);

// @fnv 0x00ddabe0
hkDisplaySerializeIStream* __fastcall ConstructDisplaySerializeIStream(
    hkDisplaySerializeIStream* stream, void*, int a)
{
    reinterpret_cast<IArchiveConstructor>(&ConstructIArchive)(stream, a, ArchiveByteFlag());
    *reinterpret_cast<void***>(stream) = DisplaySerializeIStreamVtable;
    return stream;
}

// @fnv 0x00ddac60
// src: HAVOK_LIB 0x00ddac60
__declspec(noinline) void hkDisplaySerializeIStream::readQuadVector4(hkVector4& obj)
{
    hkIArchive_readArrayGeneric(&obj, 4, 3);
    obj.w = 0.0f;
}

struct ArrayRecord
{
    void* data;
    int size;
    int capacity;
};
struct ArrayPair
{
    ArrayRecord first;
    ArrayRecord second;
};
BSAudio* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
// The triangle reader is absent from the shared stream declaration. The unused
// fastcall register argument leaves its original thiscall entry ABI intact.
__declspec(noinline) void __fastcall ReadDisplayTriangle(hkDisplaySerializeIStream*, void*, void*);
typedef void (__thiscall* DisplayTriangleReader)(hkDisplaySerializeIStream*, void*);

// @fnv 0x00ddacd0
// src: HAVOK_LIB 0x00ddacd0
void hkDisplaySerializeIStream::readGeometry(hkGeometry* geometry)
{
    ArrayPair* arrays = reinterpret_cast<ArrayPair*>(geometry);
    {
        int firstCount;
        hkIArchive_readArrayGeneric(&firstCount, 4, 1);
        if (firstCount > 0)
        {
            for (int remaining = firstCount; remaining != 0; --remaining)
            {
                BSAudio* allocator = hkMemoryRouter_getInstance();
                hkMemoryAllocator* growFunction = reinterpret_cast<hkMemoryAllocator*>(reinterpret_cast<hkMemoryRouter*>(allocator)->m_heap);
                ArrayRecord* array = &arrays->first;
                int size = array->size;
                int needed = size + 1;
                int capacity = array->capacity & 0x3fffffff;
                if (capacity < needed)
                {
                    int grown = capacity * 2;
                    if (needed < grown)
                        needed = grown;
                    hkArrayUtil__reserve(growFunction, array, needed, 16);
                }
                ++array->size;
                void* output = (char*)array->data + size * 16;
                readQuadVector4(*reinterpret_cast<hkVector4*>(output));
            }
        }
    }
    {
        int secondCount;
        hkIArchive_readArrayGeneric(&secondCount, 4, 1);
        if (secondCount > 0)
        {
            ArrayRecord* array = &arrays->second;
            for (int remaining = secondCount; remaining != 0; --remaining)
            {
                BSAudio* allocator = hkMemoryRouter_getInstance();
                hkMemoryAllocator* growFunction = reinterpret_cast<hkMemoryAllocator*>(reinterpret_cast<hkMemoryRouter*>(allocator)->m_heap);
                int size = array->size;
                int needed = size + 1;
                int capacity = array->capacity & 0x3fffffff;
                if (capacity < needed)
                {
                    int grown = capacity * 2;
                    if (needed < grown)
                        needed = grown;
                    hkArrayUtil__reserve(growFunction, array, needed, 16);
                }
                ++array->size;
                void* output = (char*)array->data + size * 16;
                reinterpret_cast<DisplayTriangleReader>(&ReadDisplayTriangle)(this, output);
            }
        }
    }
}

// Calls the archive destructor, optionally frees its allocated size, and returns the archive.
// @fnv 0x00dd9210
hkIArchive* __fastcall DeleteIArchive(hkIArchive* archive, void*, unsigned char acFlags)
{
    archive->ReleaseArchiveReader();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        // Preserve the allocator's virtual free dispatch at vtable slot 2.
        typedef void (__thiscall* FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
        reinterpret_cast<FreeFunction>((*reinterpret_cast<void***>(pAllocator))[2])(pAllocator, archive, archive->m_usMemSizeAndFlags);
    }
    return archive;
}

// Reads the translation (w set to 1.0f), then a quaternion used to set the rotation.
// @fnv 0x00ddac80
// src: GUESS 0x00ddac80 (confidence: medium)
void hkDisplaySerializeIStream::ReadTranslationAndRotation(hkTransform* target)
{
    Vec4 source;
    Vec4 destination;
    hkIArchive_readArrayGeneric(&source, 4, 3);
    source.w = 1.0f;
    hkIArchive_readArrayGeneric(&destination, 4, 4);
    target->m_vTranslation = *(__m128*)&source;
    target->m_rotation.hkRotation_set(reinterpret_cast<const hkQuaternion&>(destination));
}

// Reads three 4-byte integers via FUN_00dd8fe0 and stores them sequentially into the output buffer.
// @fnv 0x00ddac00
__declspec(noinline) void __fastcall ReadDisplayTriangle(hkDisplaySerializeIStream* stream, void*, void* output)
{
    int* dst = (int*)output;
    {
        int val1;
        stream->hkIArchive_readArrayGeneric(&val1, 4, 1);
        dst[0] = val1;
    }
    {
        int val2;
        stream->hkIArchive_readArrayGeneric(&val2, 4, 1);
        dst[1] = val2;
    }
    {
        int val3;
        stream->hkIArchive_readArrayGeneric(&val3, 4, 1);
        dst[2] = val3;
    }
}
