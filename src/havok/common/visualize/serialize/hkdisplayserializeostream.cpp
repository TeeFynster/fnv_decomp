#include "../../../../../include/hkArray.h"

// src/havok/common/visualize/serialize/hkdisplayserializeostream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkdisplayserializeostream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkOArchive.h"

__declspec(nothrow) hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

// @fnv 0x00dda830
// src: HAVOK_LIB 0x00dda830
unsigned int hkDisplaySerializeOStream_computeBytesRequired(const unsigned int* puiValues)
{
    return 4 * (3 * (puiValues[4] + puiValues[1])) + 8;
}

void __stdcall WriteFloatArray(unsigned int, unsigned int);
// @fnv 0x00dda730
// src: HAVOK_LIB 0x00dda730
void __stdcall hkDisplaySerializeOStream_writeQuadVector4(unsigned int p)
{
    WriteFloatArray(p, 3);
}

struct RefObj
{
    void* m_vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    __declspec(nothrow) void FUN_00c905b0();
};

struct FUN_00d27460 : RefObj
{
    int pad[(0x1c - 8) / 4];
    __declspec(nothrow) FUN_00d27460(int a, int b);
};

inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)hkMemoryRouter_getInstance()->heap().blockAlloc(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct FUN_00d60830 : RefObj
{
    RefObj* m_8;
    __declspec(nothrow) FUN_00d60830(RefObj* o, hkBool b);
};

extern "C" char DAT_010d7db8[];

struct FUN_00dda6e0 : FUN_00d60830
{
    FUN_00dda6e0(int a);
};

// Constructs a FUN_00d60830 base with a newly allocated FUN_00d27460(a, 0x2000), sets the vtable, and calls FUN_00c905b0 on m_8.
// @fnv 0x00dda6e0
FUN_00dda6e0::FUN_00dda6e0(int a) : FUN_00d60830(new(hkAlloc(sizeof(FUN_00d27460))) FUN_00d27460(a, 0x2000), false)
{
    m_vtbl = DAT_010d7db8;
    m_8->FUN_00c905b0();
}

struct DDA7C0Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct DDA7C0Triangle
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
};



struct DDA7C0Geometry
{
    hkArrayBase<DDA7C0Vector4> m_kVertices;
    hkArrayBase<DDA7C0Triangle> m_uiTriangleCount;
};

struct DDA7C0OStream
{
    void writeInt32(unsigned int value);
    void writeVector(const DDA7C0Vector4& v);
    void writeTriangle(const DDA7C0Triangle& t);

    void WriteGeometry(const DDA7C0Geometry& geometry);
};

// Writes the vertex count and vertices, then the triangle count and triangles, of a geometry to the stream.
// @fnv 0x00dda7c0
void DDA7C0OStream::WriteGeometry(const DDA7C0Geometry& geometry)
{
    int numVertices = geometry.m_kVertices.m_iElementCount;
    writeInt32(numVertices);
    for (int i = 0; i < numVertices; i++)
        writeVector(geometry.m_kVertices.m_data[i]);
    int numTriangles = geometry.m_uiTriangleCount.m_iElementCount;
    writeInt32(numTriangles);
    for (int i = 0; i < numTriangles; i++)
        writeTriangle(geometry.m_uiTriangleCount.m_data[i]);
}

namespace fnv_00ddabb0 {
struct FUN_00ddabb0_shell
{
    void* unk00;
    unsigned short size;
    void ReleaseReference_00d60590();
    FUN_00ddabb0_shell* FUN_00ddabb0(unsigned int flags);
};
// Calls FUN_00d60590, then if bit 0 of flags is set frees this through the hkMemoryRouter heap allocator, and returns this.
// @fnv 0x00ddabb0
FUN_00ddabb0_shell* FUN_00ddabb0_shell::FUN_00ddabb0(unsigned int flags)
{
    ReleaseReference_00d60590();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        holder->heap().blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00ddabb0

// 0x00d60600 is hkOArchive::WriteSwapped in hkoarchive.cpp's bindings.
// The shared header lacks this unsigned-16 writer; the unused EDX argument
// lets this local helper retain the original thiscall ABI without a class copy.
// @fnv 0x00d60920
void __fastcall WriteUInt16(hkOArchive* archive, void*, unsigned short value)
{
    archive->WriteSwapped(&value, 2, 1);
}

#include <xmmintrin.h>
struct S_00dda740_Vector4
{
    float x, y, z, w;
    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
};

#include "../../../../../include/hkMatrix3.h"


struct S_00dda740_Transform
{
    hkMatrix3 m_rotation;
    S_00dda740_Vector4 m_vTranslation;
};

struct S_00dda740_Quaternion
{
    S_00dda740_Vector4 m_vec;
    void FUN_00cb26e0(const hkMatrix3& r);
};

struct S_00dda740
{
    void WriteFloatArray(const float* data, int n);
    void WriteTransform(const S_00dda740_Transform& t);
};

// Converts the rotation matrix to a quaternion and writes the translation and quaternion components to the stream.
// @fnv 0x00dda740
void S_00dda740::WriteTransform(const S_00dda740_Transform& t)
{
    S_00dda740_Vector4 trans = t.m_vTranslation;
    __declspec(align(16)) hkMatrix3 rot = t.m_rotation;
    __declspec(align(16)) S_00dda740_Quaternion q;
    q.FUN_00cb26e0(rot);
    WriteFloatArray(&trans.x, 3);
    WriteFloatArray(&q.m_vec.x, 4);
}

int hkDisplaySerializeOStream_computeBytesRequired(int value);

// Returns a constant chosen by the int at param+0x50 (0x1d plus FUN_00dda830(param+8) for 6), or 1 for other values.
// @fnv 0x00dda850
// src: HAVOK_LIB 0x00dda850
int hkDisplaySerializeOStream_computeBytesRequired_00dda850(int param)
{
    int result = 1;
    switch (*(int*)(param + 0x50))
    {
    case 6:
        result = hkDisplaySerializeOStream_computeBytesRequired(*(int*)(param + 8));
        return result + 0x1d;
    case 1:
    case 5:
        return 0x35;
    case 8:
    case 9:
        return 0x41;
    case 3:
        return 0x19;
    case 4:
        return 0x25;
    case 2:
    case 7:
        result = 0x29;
        break;
    }
    return result;
}

struct __declspec(align(16)) Vec4A
{
    union
    {
        __m128 quad;
        float f[4];
    };
    Vec4A& operator=(const Vec4A& o)
    {
        _mm_store_ps(f, _mm_load_ps(o.f));
        return *this;
    }
};
struct Shape
{
    int unk00, unk04;
    DDA7C0Geometry* geom;
    int unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int tag;
    int unk54, unk58, unk5c;
    Vec4A vec60;
    int i70, i74, i78, i7c;
    float f80;
    int i84, i88;
    const void* EvaluateValue_00de1150();
    const void* ComputeValue_00de1160();
    void* GetValue(void* out);
    void* GetVec4At70(void* out);
    float GetField84();
    float GetValue_00de5340();
    int GetFieldAtOffset80_00de5360();
    void* CopyVec4ToBuffer(void* out);
    void* GetQuad16(void* out);
    void* CopyStatsTo(void* out);
    float GetValue_00de4900();
    float GetField90_00de48e0();
    float GetField94();
    int GetField9c();
    const void* Object_EvaluateValue_00de4df0();
    const void* ComputeValue_00de4de0();
    const void* ComputeValue_00de4e00();
    const float* GetFieldAtOffset90();
};
struct DDA8C0Writer
{
    void FUN_00d605b0(int v);
    void WriteTransform(const void* p);
    void hkDisplaySerializeOStream_writeQuadVector4(const void* p);
    void HashUInt(float f);
    void WriteInt(int v);
    void WriteGeometry(const DDA7C0Geometry& geometry);
    void WriteShape(Shape* p);
};
// Writes a Shape to the stream by dispatching on its tag and serializing the tag-specific fields via the writer's hash and write helpers.
// @fnv 0x00dda8c0
void DDA8C0Writer::WriteShape(Shape* p)
{
    Vec4A t[6];
    int tag = p->tag;
    FUN_00d605b0(tag);
    switch (tag)
    {
    case 6: {
        WriteTransform(&p->unk10);
        WriteGeometry(*p->geom);
        break;
    }
    case 1: {
        WriteTransform(&p->unk10);
        t[0] = p->vec60;
        HashUInt(t[0].f[3]);
        hkDisplaySerializeOStream_writeQuadVector4(&t[0]);
        WriteInt(p->i70);
        WriteInt(p->i74);
        break;
    }
    case 8: {
        WriteTransform(&p->unk10);
        HashUInt(p->f80);
        hkDisplaySerializeOStream_writeQuadVector4(&p->vec60);
        hkDisplaySerializeOStream_writeQuadVector4(&p->i70);
        WriteInt(p->i84);
        WriteInt(p->i88);
        break;
    }
    case 9: {
        WriteTransform(&p->unk10);
        HashUInt(p->f80);
        hkDisplaySerializeOStream_writeQuadVector4(&p->vec60);
        hkDisplaySerializeOStream_writeQuadVector4(&p->i70);
        WriteInt(p->i84);
        WriteInt(p->i88);
        break;
    }
    case 2: {
        WriteTransform(&p->unk10);
        hkDisplaySerializeOStream_writeQuadVector4(&p->vec60);
        break;
    }
    case 3: {
        hkDisplaySerializeOStream_writeQuadVector4(p->EvaluateValue_00de1150());
        hkDisplaySerializeOStream_writeQuadVector4(p->ComputeValue_00de1160());
        break;
    }
    case 4: {
        hkDisplaySerializeOStream_writeQuadVector4(p->GetValue(&t[1]));
        hkDisplaySerializeOStream_writeQuadVector4(p->GetVec4At70(&t[2]));
        HashUInt(p->GetField84());
        HashUInt(p->GetValue_00de5340());
        WriteInt(p->GetFieldAtOffset80_00de5360());
        break;
    }
    case 5: {
        hkDisplaySerializeOStream_writeQuadVector4(p->CopyVec4ToBuffer(&t[3]));
        hkDisplaySerializeOStream_writeQuadVector4(p->GetQuad16(&t[4]));
        hkDisplaySerializeOStream_writeQuadVector4(p->CopyStatsTo(&t[5]));
        HashUInt(p->GetValue_00de4900());
        HashUInt(p->GetField90_00de48e0());
        HashUInt(p->GetField94());
        WriteInt(p->GetField9c());
        break;
    }
    case 7: {
        hkDisplaySerializeOStream_writeQuadVector4(p->Object_EvaluateValue_00de4df0());
        hkDisplaySerializeOStream_writeQuadVector4(p->ComputeValue_00de4de0());
        hkDisplaySerializeOStream_writeQuadVector4(p->ComputeValue_00de4e00());
        HashUInt(*p->GetFieldAtOffset90());
        break;
    }
    }
}
