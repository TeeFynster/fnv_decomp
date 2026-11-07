#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
// staging/blk_00a60000_o2.cpp: NiShader, PivotGeometry, NiDirectionalLight, NiTMapBase and more (116 functions)

#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/NiTStringTemplateMap.h"
#include "../../include/NiTFixedStringMap.h"
class ImageSpaceTexture;
#include <windows.h>
// src/staging/blk_00a60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/NiRefObject.h"
#include "../../include/NiObject.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTexture.h"
#include "../../include/BSFaceGenModel.h"
#include "../../include/NiTexturingProperty.h"
#include "../../include/BSFadeNode.h"
#include "../../include/NiCullingProperty.h"
#include "../../include/RecursiveSpinLock.h"
#include "../../include/Transform.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiDirectionalLight.h"
#include "../../include/NiFile.h"
#include "../../include/NiPixelData.h"
#include "../../include/NiPixelFormat.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiStream.h"
#include "../../include/NiSourceTexture.h"
#include "../../include/NiShader.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTMap.h"
#include "../../include/NiTriStrips.h"
#include "../../include/StrArr.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit defines inline bodies for both NiPoint3 and the stand-in in different forms (constructor/temporary, operand order), so one NiPoint3 cannot carry both.
#include "../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* other);
    float CVec3_Distance(const LocalVec3& other) const;
    LocalVec3 TransformPointByMatrix4(const Mat& matrix);
    LocalVec3 TransformPointByMatrix4(const Matrix4* matrix);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};
#include "../../include/hkVector4.h"


inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c) {}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& p) const
{
    NiPoint3 result;
    result.x = x + p.x;
    result.y = y + p.y;
    result.z = z + p.z;
    return result;
}
inline NiPoint3 NiPoint3::operator*(float scale) const
{
    NiPoint3 result;
    result.x = x * scale;
    result.y = y * scale;
    result.z = z * scale;
    return result;
}
inline NiPoint3 NiPoint3::operator-() const
{
    NiPoint3 result;
    result.x = -x;
    result.y = -y;
    result.z = -z;
    return result;
}
inline NiPoint3 operator*(float scale, const NiPoint3& p)
{
    return NiPoint3(scale * p.x, scale * p.y, scale * p.z);
}
static inline void AssignPoint(NiPoint3& destination, const NiPoint3& source)
{
    memcpy(&destination, &source, sizeof(destination));
}

inline LocalVec3::LocalVec3() {}
inline LocalVec3 LocalVec3::operator*(float scale) const
{
    LocalVec3 r;
    r.x = x * scale;
    r.y = y * scale;
    r.z = z * scale;
    return r;
}
inline LocalVec3& LocalVec3::operator+=(const LocalVec3& p)
{
    x += p.x;
    y += p.y;
    z += p.z;
    return *this;
}
inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
                                              unsigned int* sizes, unsigned int count)
{
    unsigned int result = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))
        (this, buffer, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += result;
    return result;
}
inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes,
                                               unsigned int* sizes, unsigned int count)
{
    unsigned int result = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))
        (this, buffer, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += result;
    return result;
}
static inline NiBinaryStream*& StreamInput(NiStream& stream)
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x24c);
}
static inline NiBinaryStream*& StreamOutput(NiStream& stream)
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x250);
}

void* __cdecl _fnv_zlib_memset(void* p, int c, unsigned int n);

struct FUN_00a61590_class
{
    void* __thiscall ClearAndReset();
};

// Zeroes the first 0xb24 bytes of this object, sets the int at offset 0xb24 to 0, and returns this.
// @fnv 0x00a61590
void* __thiscall FUN_00a61590_class::ClearAndReset()
{
    _fnv_zlib_memset(this, 0, 0xb24);
    *(int*)((char*)this + 0xb24) = 0;
    return this;
}

extern NiTStringTemplateMap<NiTPointerMap<char const*, NiShader*>, NiShader*>* DAT_011f4784;
class NiUnionBV;
extern NiUnionBV* DAT_011f4788;

// Deletes the shader pointer map and the union BV object if each is non-null.
// @fnv 0x00a632b0
// src: GAMEBRYO_LIB 0x00a632b0
void NiStream__SDMShutdown()
{
    if (DAT_011f4784)
        delete DAT_011f4784;
    if (DAT_011f4788)
        reinterpret_cast<void (__thiscall*)(NiUnionBV*, int)>(*reinterpret_cast<void***>(DAT_011f4788)[0])(DAT_011f4788, 1);
}

extern "C" void NiFreeAlias(void*);
extern void* DAT_011f4aa8;

// @fnv 0x00a7e940
void FreeGlobalAlias()
{
    NiFreeAlias(DAT_011f4aa8);
    DAT_011f4aa8 = 0;
}

extern int DAT_0109df2c;
extern int DAT_011f4ab4;

struct FUN_00a7f820_Class
{
    void __thiscall UpdateFields_00a7f820();
};

// @fnv 0x00a7f820
// src: GUESS 0x00a7f820 (confidence: low)
void __thiscall FUN_00a7f820_Class::UpdateFields_00a7f820()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_0109df2c;
    DAT_011f4ab4 = 0;
}

// Clamps each of the first three floats in the array to a maximum of 1.0.
// @fnv 0x00a69690
// src: XBOX_PDB 0x00a69690
void __fastcall NiColor_Clamp(float* afValues)
{
    if (afValues[0] > 1.0f)
        afValues[0] = 1.0f;
    if (afValues[1] > 1.0f)
        afValues[1] = 1.0f;
    if (afValues[2] > 1.0f)
        afValues[2] = 1.0f;
}

extern MemoryManager g_memoryManager;

struct FUN_00a615c0_Class
{
    void __thiscall ClearAllBuckets();
};

// Walks each of 0x3e9 bucket lists, freeing every node via g_memoryManager.Deallocate, then clears the buckets and the pointer at offset 0xfa4.
// @fnv 0x00a615c0
void __thiscall FUN_00a615c0_Class::ClearAllBuckets()
{
    void** p = (void**)(this + 0);
    for (unsigned int i = 0; i < 0x3e9; ++i)
    {
        void* current = p[i];
        while (current != 0)
        {
            void* node = current;
            current = ((void**)node)[1];
            ((void**)((void**)node)[0])[1] = 0;
            g_memoryManager.Deallocate(node);
        }
        p[i] = 0;
    }
    *(void**)((char*)this + 0xfa4) = 0;
}


extern RecursiveSpinLock g_011c5f80;
extern unsigned int DAT_011c5f84;
extern void* DAT_011c5f58;
// @fnv 0x00a638c0
template <>
void NiTPointerMap<const char*, unsigned short>::DeleteItem(NiTMapItem<const char*, unsigned short>* pNode)
{
    pNode->m_val = 0;
    g_011c5f80.Lock(0);
    pNode->m_key = 0;
    pNode->m_pkNext = static_cast<EntryType*>(DAT_011c5f58);
    --DAT_011c5f84;
    DAT_011c5f58 = pNode;
    if (!DAT_011c5f84)
        *(unsigned int*)&g_011c5f80 = 0;
}

namespace fnv_00a63b30 {
extern "C" void NiFree(void*);
extern int DAT_0109bc3c;
extern void* g_memoryManager;


struct FUN_00a63b30_Class
{
    void* __thiscall FUN_00a63b30(bool);
};

// @fnv 0x00a63b30
void* __thiscall FUN_00a63b30_Class::FUN_00a63b30(bool abFree)
{
    void* p = *(void**)((char*)this + 4);
    *(int**)((char*)this) = &DAT_0109bc3c;
    NiFree(p);
    if (abFree & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00a63b30

namespace fnv_00a652d0 {
extern MemoryManager _g_memoryManager;
extern int DAT_0109bd98;
void __cdecl ReleaseObjectArray(void*);
struct FUN_00a652d0_class
{
    int m0;
    void* m4;
    void* __thiscall FUN_00a652d0(bool);
};
// Sets m0 to &DAT_0109bd98, calls ReleaseObjectArray on m4, and if b is set deallocates this via _g_memoryManager, returning this.
// @fnv 0x00a652d0
void* __thiscall FUN_00a652d0_class::FUN_00a652d0(bool abFree)
{
    m0 = (int)&DAT_0109bd98;
    ReleaseObjectArray(m4);
    if (abFree & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a652d0

struct NiTriBasedGeomData;
NiTriBasedGeomData* __fastcall InitializeTriBasedGeomData(NiTriBasedGeomData*);
extern int DAT_0109dac4;
// @fnv 0x00a7b790
// src: EXE 0x00a7b790
void* __cdecl NiTriShapeData_CreateObject()
{
    char* p = (char*)BSFadeNode::operator new(0x58);
    if (p)
    {
        InitializeTriBasedGeomData((NiTriBasedGeomData*)p);
        *(int*)(p + 0x44) = 0;
        *(int*)(p + 0x48) = 0;
        *(int*)(p + 0x4c) = 0;
        *(int*)(p + 0x54) = 0;
        *(short*)(p + 0x50) = 0;
        *(int*)p = (int)&DAT_0109dac4;
        return p;
    }
    return 0;
}

void __fastcall FUN_00a71f60(void*);
extern int DAT_0109dd0c;
// @fnv 0x00a7d670
NiDirectionalLight* __fastcall InitializeAttenuatedLight(NiDirectionalLight* light)
{
    FUN_00a71f60(light);
    *(float*)((char*)light + 0xf0) = 0.0f;
    *(int*)light = (int)&DAT_0109dd0c;
    *(float*)((char*)light + 0xf4) = 1.0f;
    *(unsigned char*)((char*)light + 0x9d) = 2;
    *(float*)((char*)light + 0xf8) = 0.0f;
    return light;
}

// Extra copy operation absent from the shared class; the unused register
// parameter preserves the original thiscall entry convention.
// @fnv 0x00a7d6a0
void __fastcall CopyLightAttenuation(NiDirectionalLight* light, void*, NiDirectionalLight* dst, CloningProcess& proc)
{
    light->CopyMemberData(dst, proc);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(dst) + 0xf0) =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(light) + 0xf0);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(dst) + 0xf4) =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(light) + 0xf4);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(dst) + 0xf8) =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(light) + 0xf8);
}

extern "C" int __cdecl tolower(int);

// Hashes the lowercased characters of str (stopping before a trailing 3-character extension after a dot) and returns the hash modulo 713.
// @fnv 0x00a61530
// src: COMMUNITY 0x00a61530
unsigned int BSTexturePalette_GetContainerNumber(const char* str)
{
    unsigned int hash = 0;
    while (*str)
    {
        int c = tolower(*str);
        ++str;
        if (c == '.' && !str[3])
            break;
        hash = hash * 33u + c;
    }
    return hash % 713u;
}


struct FUN_00a755f0_Class : NiCullingProperty
{
    void __thiscall CopyCullingData(void* dst, CloningProcess& proc);
};
// @fnv 0x00a755f0
void __thiscall FUN_00a755f0_Class::CopyCullingData(void* dst, CloningProcess& proc)
{
    NiProperty_CopyMembers(dst, proc);
    char* a = (char*)this;
    char* b = (char*)dst;
    *(int*)(b + 0x1c) = *(int*)(a + 0x1c);
    *(int*)(b + 0x20) = *(int*)(a + 0x20);
    *(int*)(b + 0x24) = *(int*)(a + 0x24);
    *(int*)(b + 0x28) = *(int*)(a + 0x28);
    *(int*)(b + 0x2c) = *(int*)(a + 0x2c);
    *(int*)(b + 0x30) = *(int*)(a + 0x30);
    *(int*)(b + 0x34) = *(int*)(a + 0x34);
    *(float*)(b + 0x38) = *(float*)(a + 0x38);
    *(float*)(b + 0x3c) = *(float*)(a + 0x3c);
    *(float*)(b + 0x40) = *(float*)(a + 0x40);
}

struct FUN_00a72590_Class
{
    int NiAdditionalGeometryData_LockDataBlock(unsigned int index, int* out);
};

// @fnv 0x00a72590
// src: COMMUNITY 0x00a72590
int FUN_00a72590_Class::NiAdditionalGeometryData_LockDataBlock(unsigned int index, int* out)
{
    *out = 0;
    unsigned short count = *(unsigned short*)((char*)this + 0x26);
    if (index >= count)
        return 0;
    int* array = *(int**)((char*)this + 0x20);
    int obj = array[index];
    if (!obj)
        return 0;
    *out = *(int*)(obj + 4);
    int* vtable = *(int**)obj;
    void(__thiscall * fn)(void*, int, int) = *(void(__thiscall**)(void*, int, int))(vtable + 2);
    fn((void*)obj, 0, 0);
    return *(int*)(obj + 8);
}

// @fnv 0x00a7d6e0
// src: EXE 0x00a7d6e0
void* NiPointLight_CreateObject()
{
    NiDirectionalLight* obj = (NiDirectionalLight*)NiMemObject::operator new(0xfc);
    if (obj)
    {
        FUN_00a71f60(obj);
        *(float*)((char*)obj + 0xf0) = 0.0f;
        *(void**)obj = (void*)&DAT_0109dd0c;
        *(float*)((char*)obj + 0xf4) = 1.0f;
        *(unsigned char*)((char*)obj + 0x9d) = 2;
        *(float*)((char*)obj + 0xf8) = 0.0f;
        return obj;
    }
    return 0;
}


__declspec(nothrow) void _NiFree(void*);

// The map vftables at 0x0109bc64..0x0109bd54 identify these exact RTTI instantiations.
typedef NiObject* (__cdecl* NiObjectFactory)();

template <> __declspec(nothrow) void
NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiObjectFactory>::RemoveAll();
template <> __declspec(nothrow) void
NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, unsigned short>::RemoveAll();
template <> __declspec(nothrow) void
NiTMapBase<NiTPointerAllocator<unsigned int>, const NiObject*, unsigned int>::RemoveAll();

__forceinline void __cdecl operator delete(void* memory)
{
    g_memoryManager.Deallocate(memory);
}

template <class TAlloc, class TKEY, class TVAL>
__forceinline NiTMapBase<TAlloc, TKEY, TVAL>::~NiTMapBase()
{
    RemoveAll();
    _NiFree(m_ppkHashTable);
}

template <class TKEY, class TVAL>
__forceinline NiTPointerMap<TKEY, TVAL>::~NiTPointerMap()
{
    RemoveAll();
}

// @fnv 0x00a63850
template <>
NiTStringTemplateMap<NiTPointerMap<const char*, NiObjectFactory>, NiObjectFactory>::~NiTStringTemplateMap()
{
    if (m_bCopy)
    {
        unsigned int i = 0;
        if (m_uiHashSize > 0)
        {
            do
            {
                EntryType* node = m_ppkHashTable[i];
                while (node)
                {
                    EntryType* cur = node;
                    node = cur->m_pkNext;
                    _NiFree(const_cast<char*>(cur->m_key));
                }
                ++i;
            } while (i < m_uiHashSize);
        }
    }
}

// Scalar deleting destructors: 0x00a639e0, 0x00a63a20, 0x00a63a60,
// 0x00a63aa0, 0x00a63b60 and 0x00a63ba0.
template NiTPointerMap<const char*, NiObjectFactory>::~NiTPointerMap();
template NiTPointerMap<const char*, unsigned short>::~NiTPointerMap();
template NiTPointerMap<const NiObject*, unsigned int>::~NiTPointerMap();


struct FUN_00a699d0_Class
{
    NiPoint3 normal;
    float distance;

    FUN_00a699d0_Class* __thiscall SetPlaneFromThreePoints(NiPoint3 const* point0, NiPoint3 const* point1, NiPoint3 const* point2);
};

// Computes the normal as the cross product of the two edge vectors and sets distance to the dot product of the normal with point0.
// @fnv 0x00a699d0
// src: GUESS 0x00a699d0 (confidence: medium)
FUN_00a699d0_Class* __thiscall FUN_00a699d0_Class::SetPlaneFromThreePoints(NiPoint3 const* point0, NiPoint3 const* point1,
                                                                NiPoint3 const* point2)
{
    NiPoint3 edge1;
    edge1.x = point1->x - point0->x;
    edge1.y = point1->y - point0->y;
    edge1.z = point1->z - point0->z;

    NiPoint3 edge2;
    edge2.x = point2->x - point1->x;
    edge2.y = point2->y - point1->y;
    edge2.z = point2->z - point1->z;

    AssignPoint(normal, edge1.CrossProduct(edge2));

    distance = normal.x * point0->x + normal.y * point0->y + normal.z * point0->z;

    return this;
}


extern int DAT_0109ca08;
extern MemoryManager _g_memoryManager;
void _NiFree(void* p);

// The vftable at 0x0109ca08 identifies the const-char-pointer fixed-string map base.
// Keep this deleting-destructor entry outside the class so its flag argument stays explicit.
// @fnv 0x00a6ea00
void* __fastcall DestroyFixedStringCStringMap(
    NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, const char*> >, const char*>* map,
    void*, unsigned char flag)
{
    *reinterpret_cast<int**>(map) = &DAT_0109ca08;
    map->RemoveAll();
    _NiFree(map->m_ppkHashTable);
    if (flag & 1)
        _g_memoryManager.Deallocate(map);
    return map;
}


extern int DAT_0109cd44;

// Allocates 0xc4 bytes, constructs a NiTriStrips in place, sets its vtable to DAT_0109cd44, and returns the pointer or 0 on failure.
// @fnv 0x00a71ce0
void* CreateNiTriStrips()
{
    NiTriStrips* p = (NiTriStrips*)NiMemObject::operator new(0xc4);
    if (p)
    {
        p->NiTriStrips::NiTriStrips();
        *(int*)p = (int)&DAT_0109cd44;
        return p;
    }
    return 0;
}

struct FUN_00a72ca0_Class
{
    void SetSize_Thunk(unsigned int size);
};
// @fnv 0x00a72ca0
// src: GUESS 0x00a72ca0 (confidence: medium)
void FUN_00a72ca0_Class::SetSize_Thunk(unsigned int size)
{
    ((NiTPrimitiveArray<ImageSpaceTexture*>*)((char*)this + 0x1c))->SetSize(size);
}

struct FUN_00a7f810
{
    int m_p;
    FUN_00a7f810();
};

// @fnv 0x00a7f810
FUN_00a7f810::FUN_00a7f810()
{
    m_p = (int)&DAT_0109df2c;
    DAT_011f4ab4 = (int)this;
}

struct HashValue_00a61670
{
    unsigned int unk00;
    unsigned int key;
};
struct HashNode_00a61670
{
    HashValue_00a61670* value;
    HashNode_00a61670* next;
};
struct FUN_00a61670_Map
{
    HashNode_00a61670* buckets[1001];
    unsigned int count;
    HashValue_00a61670* RemoveByKey(unsigned int key);
};
extern struct MemoryManager g_memoryManager;
// Looks up a key in the hash map, unlinks and deallocates its node, clears the value's key, and returns the removed value or null.
// @fnv 0x00a61670
HashValue_00a61670* FUN_00a61670_Map::RemoveByKey(unsigned int key)
{
    unsigned int index = (key >> 4) % 1001;
    HashValue_00a61670* result = 0;
    HashNode_00a61670* current = buckets[index];
    HashNode_00a61670* previous = 0;
    if (current != 0)
    {
        do
        {
            if (current->value->key == key)
            {
                if (previous != 0)
                    previous->next = current->next;
                else
                    buckets[index] = current->next;
                HashValue_00a61670* value = current->value;
                --count;
                g_memoryManager.Deallocate(current);
                value->key = 0;
                result = value;
                break;
            }
            previous = current;
            current = current->next;
        } while (current != 0);
    }
    return result;
}

struct A616E0Entry
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C;
};

struct A616E0Iter
{
    A616E0Entry* m_entry;
    unsigned int m_uiEdgeIndex;
    unsigned int m_uiFilterValue;
};

struct A616E0Bucket
{
    A616E0Entry* m_entries[0x2c9];
    int m_uiItemCount;

    bool GetFirst(A616E0Iter* it)
    {
        it->m_uiEdgeIndex = 0;
        it->m_entry = 0;
        if (m_uiItemCount)
        {
            for (unsigned int i = 0; i < 0x2c9; ++i)
            {
                if (m_entries[i])
                {
                    it->m_uiEdgeIndex = i;
                    it->m_entry = m_entries[i];
                    it->m_uiFilterValue = it->m_entry->unk0C;
                    break;
                }
            }
        }
        return it->m_entry != 0;
    }
};

struct A616E0Pool
{
    A616E0Bucket m_buckets[7];
};

extern A616E0Pool* DAT_011f4464;

// Scans the seven buckets of DAT_011f4464 from the last to the first and returns whether GetFirst found an entry, filling it.
// @fnv 0x00a616e0
// src: COMMUNITY 0x00a616e0
bool __cdecl BSTexturePalette_GetFirstPos(A616E0Iter* it)
{
    int i = 7;
    bool found;
    do
    {
        --i;
        found = DAT_011f4464->m_buckets[i].GetFirst(it);
    } while (!found && i);
    return found;
}

class A61750Texture
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
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual unsigned int GetHeight();
    virtual unsigned int GetWidth();
};

// Returns a level 0-4 based on the larger of the texture's width and height, using thresholds 0x80, 0x100, 0x200 and 0x400.
// @fnv 0x00a61750
unsigned int GetTextureSizeLevel(A61750Texture* pkTexture)
{
    unsigned int uiTreeBlockIndex = 0;
    unsigned int uiWidth = pkTexture->GetWidth();
    unsigned int uiHeight = pkTexture->GetHeight();
    unsigned int uiSize = uiHeight > uiWidth ? uiHeight : uiWidth;
    if (uiSize >= 0x400)
        uiTreeBlockIndex = 4;
    else if (uiSize >= 0x200)
        uiTreeBlockIndex = 3;
    else if (uiSize >= 0x100)
        uiTreeBlockIndex = 2;
    else if (uiSize >= 0x80)
        uiTreeBlockIndex = 1;
    return uiTreeBlockIndex;
}

extern bool __cdecl BSTexturePalette_ArePathsEqual(int, int);

// The shared header does not name the hash callback used by this table.
static inline int* ShaderHash(NiShader* shader)
{
    typedef int* (__thiscall* HashCallback)(NiShader*);
    return reinterpret_cast<HashCallback>((*reinterpret_cast<void***>(shader))[39])(shader);
}

struct FUN_00a61920_Node
{
    NiShader* m_pObject;
    int unk04;
    FUN_00a61920_Node* m_pkNext;
    short unk0c;
    short unk0e;
};

class FUN_00a61920_Class
{
  public:
    FUN_00a61920_Node* m_pBuckets[1];

    bool __thiscall FindShaderByHash(int, int, NiShader**);
};

// @fnv 0x00a61920
bool __thiscall FUN_00a61920_Class::FindShaderByHash(int iBucketIndex, int iHashKey, NiShader** ppOutShader)
{
    FUN_00a61920_Node* node = m_pBuckets[iBucketIndex];
    bool found = false;

    if (node != 0)
    {
        do
        {
            int* hash = ShaderHash(node->m_pObject);
            int value = static_cast<int>(node->unk0e) + *hash;

            if (BSTexturePalette_ArePathsEqual(iHashKey, value))
            {
                NiShader* pOldShader = *ppOutShader;

                if (pOldShader != node->m_pObject)
                {
                    if (pOldShader != 0)
                    {
                        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&pOldShader->m_uiRefCount)) == 0)
                        {
                            pOldShader->DeleteThis();
                        }
                    }

                    *ppOutShader = node->m_pObject;

                    if (*ppOutShader != 0)
                    {
                        InterlockedIncrement(reinterpret_cast<volatile long*>(&(*ppOutShader)->m_uiRefCount));
                    }
                }

                found = true;
                break;
            }

            node = node->m_pkNext;
        } while (node != 0);
    }

    return found;
}

namespace fnv_00a61ad0 {
// FUN_00a61ad0 candidate (b9725)
struct TLSCtx_b9725
{
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
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

struct TLSHeap_b9725
{
    void* __thiscall Alloc(unsigned int size);
};

extern __declspec(thread) TLSCtx_b9725 g_tlsCtx_b9725;
extern TLSHeap_b9725 DAT_011f6238;
extern void* DAT_011f4468;
extern void* DAT_011f4464;
extern unsigned char DAT_011f4461;
void* __cdecl ClearAndReset();
void* __cdecl _fnv_zlib_memset(void* p, int c, unsigned int n);
void __stdcall Init_b9725(void* p, unsigned int size, int count, void* cb);

// Allocates two blocks via the TLS heap, zeroes the first and initializes the second with Init_b9725, storing both in globals and restoring the TLS field.
// @fnv 0x00a61ad0
// src: COMMUNITY 0x00a61ad0
void BSTexturePalette_Init()
{
    int iSavedTlsValue = g_tlsCtx_b9725.m_2b4;
    g_tlsCtx_b9725.m_2b4 = 0xf;
    char* obj = (char*)DAT_011f6238.Alloc(0xfa8);
    if (obj != 0)
    {
        _fnv_zlib_memset(obj, 0, 0xfa4);
        *(int*)(obj + 0xfa4) = 0;
        DAT_011f4468 = obj;
    }
    else
    {
        DAT_011f4468 = 0;
    }
    char* p = (char*)DAT_011f6238.Alloc(0x4e1c);
    if (p != 0)
    {
        *(int*)p = 7;
        Init_b9725(p + 4, 0xb28, 7, (void*)ClearAndReset);
        DAT_011f4464 = p + 4;
        g_tlsCtx_b9725.m_2b4 = iSavedTlsValue;
        DAT_011f4461 = 0;
        return;
    }
    g_tlsCtx_b9725.m_2b4 = iSavedTlsValue;
    DAT_011f4464 = 0;
    DAT_011f4461 = 0;
}
}  // namespace fnv_00a61ad0

class FUN_00a61ec0_cls;



struct PoolNode
{
    NiRefObject* m_obj;
    unsigned int m_unk04;
    PoolNode* m_next;
};

class NodePool
{
  public:
    void Free(PoolNode* node);
};

extern NodePool DAT_011f6238;

class FUN_00a61ec0_cls
{
  public:
    PoolNode* m_slots[0x2c9];
    unsigned int m_unkB24;

    void ClearAllSlots();
};

// Walks each of the 0x2c9 slot lists, releases each node's refcounted object and frees the node, then clears the slots and m_unkB24.
// @fnv 0x00a61ec0
void FUN_00a61ec0_cls::ClearAllSlots()
{
    for (unsigned int i = 0; i < 0x2c9; ++i)
    {
        PoolNode* node = m_slots[i];
        while (node != 0)
        {
            PoolNode* cur = node;
            node = cur->m_next;
            NiRefObject* obj = cur->m_obj;
            if (obj != 0)
            {
                if (InterlockedDecrement(reinterpret_cast<volatile long*>(&obj->m_uiRefCount)) == 0)
                {
                    obj->DeleteThis();
                }
            }
            DAT_011f6238.Free(cur);
        }
        m_slots[i] = 0;
    }
    m_unkB24 = 0;
}

namespace fnv_00a62090 {
extern MemoryManager g_memoryManager;

struct ShaderState
{
    void __thiscall ClearAllBuckets();
    ~ShaderState()
    {
        ClearAllBuckets();
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct ShaderEntry
{
    void __thiscall ClearAllSlots();
};
extern ShaderState* DAT_011f4468;
extern unsigned char* DAT_011f4464;
void __cdecl BSTexturePalette_RemoveAll();

// Calls FUN_00a62030, deletes DAT_011f4468, destroys each ShaderEntry in the DAT_011f4464 array, frees it, and nulls both globals.
// @fnv 0x00a62090
// src: COMMUNITY 0x00a62090
void __cdecl BSTexturePalette_Kill()
{
    BSTexturePalette_RemoveAll();

    delete DAT_011f4468;

    unsigned char* entries = DAT_011f4464;
    DAT_011f4468 = 0;
    if (entries != 0)
    {
        int count = *reinterpret_cast<int*>(entries - 4);
        unsigned char* current = entries + count * 2856;
        int* allocation = reinterpret_cast<int*>(entries - 4);
        if (--count >= 0)
        {
            do
            {
                current -= 2856;
                reinterpret_cast<ShaderEntry*>(current)->ClearAllSlots();
            } while (--count >= 0);
        }
        g_memoryManager.Deallocate(allocation);
    }
    DAT_011f4464 = 0;
}
}  // namespace fnv_00a62090

// Exe 0x00a62150: unit-local Vector4f view; declarations and layout are preserved.
struct BlkVector4fView
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};
// For each of count 4-byte elements, swaps the first and last bytes and swaps the two middle bytes in place.
// @fnv 0x00a62150
void __cdecl SwapByteQuadWords(BlkVector4fView* pQuads, unsigned int count)
{
    unsigned char* p = (unsigned char*)pQuads;
    if (count <= 0)
        return;
    do
    {
        unsigned int t = pQuads->b3;
        unsigned char c = pQuads->b0;
        pQuads->b0 = (unsigned char)t;
        p[3] = c;
        t = pQuads->b2;
        c = pQuads->b1;
        pQuads->b1 = (unsigned char)t;
        pQuads->b2 = c;
        pQuads++;
        p += 4;
    } while (--count);
}


// NiPixelFormat::GetMask


// @fnv 0x00a62190
unsigned int NiPixelFormat::GetMask(int eComponent) const
{
    unsigned int uiShift = 0;
    for (unsigned int i = 0; i < 4; i++)
    {
        if (reinterpret_cast<const int*>(this)[5 + i * 3] == eComponent)
        {
            unsigned char ucBPC = reinterpret_cast<const unsigned char*>(this)[0x1c + i * 12];
            unsigned int uiMask = 0;
            unsigned char ucBit = ucBPC - 1;
            if (!ucBPC)
                return 0;
            while (ucBit)
            {
                uiMask += 1 << ucBit;
                ucBit--;
            }
            uiMask = (uiMask + 1) << uiShift;
            if (*reinterpret_cast<const unsigned char*>(&unk00) & 1)
                return uiMask;
            unsigned char* pucBytes = (unsigned char*)&uiMask;
            for (int iByte = 0; iByte < 2; iByte++)
            {
                unsigned char ucTemp = pucBytes[iByte];
                pucBytes[iByte] = pucBytes[3 - iByte];
                pucBytes[3 - iByte] = ucTemp;
            }
            return uiMask >> (32 - reinterpret_cast<const unsigned char*>(&unk00)[1]);
        }
        uiShift += reinterpret_cast<const unsigned char*>(this)[0x1c + i * 12];
    }
    return 0;
}

// ReleasePendingTable - release the pending objects held in the engine slot table.
//
// The table lives at DAT_011f4514 and holds ten four byte slots.  Every slot
// points at a reference counted object:
//
//   +0x00  vtable pointer
//   +0x04  reference count
//
// A slot is released by dropping the reference count of the object it holds;
// when that count reaches zero the release hook of the object (vtable slot 1)
// runs, and afterwards the slot itself is cleared.



extern NiRefObject* g_pendingTable[10];

typedef long(__stdcall* FNV_INTERLOCKED_DECREMENT)(volatile long*);

// Iterates g_pendingTable, decrements each object's reference count and calls its virtual slot 1 when the count reaches zero, then clears the entry.
// @fnv 0x00a62280
void ReleasePendingTable()
{
    FNV_INTERLOCKED_DECREMENT pDecrement = &InterlockedDecrement;
    for (unsigned int offset = 0; offset < 40; offset += 4)
    {
        NiRefObject* pObject = *(NiRefObject**)((char*)g_pendingTable + offset);
        if (pObject)
        {
            if (pDecrement((volatile long*)&pObject->m_uiRefCount) == 0)
                pObject->DeleteThis();
            *(NiRefObject**)((char*)g_pendingTable + offset) = 0;
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);



template <class T> struct NiPtr_a62
{
    T* m_pObject;
    NiPtr_a62& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct Settings_a62
{
    int m_ai[17];
};

extern Settings_a62 g_kSettings_11f4600;
extern NiPtr_a62<NiRefObject> g_aspObjects_11f4514[10];

// Copies kSettings into g_kSettings_11f4600 and clears all 10 entries of g_aspObjects_11f4514.
// @fnv 0x00a622d0
void __cdecl ApplySettings(const Settings_a62& kSettings)
{
    g_kSettings_11f4600 = kSettings;
    for (unsigned int i = 0; i < 10; i++)
        g_aspObjects_11f4514[i] = 0;
}

struct FUN_00a66960_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int NiGeometryData_GetTextureSet(int a1);
};

// @fnv 0x00a66960
// src: COMMUNITY 0x00a66960
int FUN_00a66960_cls::NiGeometryData_GetTextureSet(int a1)
{
    return m_2C;
}

// File-static comparison with a compiler-chosen register convention.
// @fnv 0x00a66970
static __declspec(noinline) int CompareFloatArrays(const float* pfA, const float* pfB, unsigned int auiCount)
{
    for (unsigned int i = 0; i < auiCount; i++)
    {
        if (pfA[i] < pfB[i])
            return -1;
        if (pfA[i] > pfB[i])
            return 1;
    }
    return 0;
}

struct A66970Keys
{
    unsigned int m_uiCount;
    const float* m_pfA;
    const float* m_pfB;
};

int A66970Compare(const A66970Keys* pkKeys)
{
    return CompareFloatArrays(pkKeys->m_pfA, pkKeys->m_pfB, pkKeys->m_uiCount);
}

struct OutRec674
{
    int a;
    int b;
    unsigned char c;
};

struct Obj_a674
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool v35();
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
    unsigned char m_2c;
    void __thiscall NiAdditionalGeometryData_GetDataStream(int flag, int* a, int* f, int* c, int* e, int* d, int* b);
};

struct FUN_00a674b0_cls
{
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
    Obj_a674* m_30;
    unsigned int unk34;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char m_3a;
    void __thiscall GetOutRec(OutRec674* out);
};

// If m_3a is set, optionally queries m_30 via FUN_00a72720 and writes the resulting a, b and 0 into out.
// @fnv 0x00a674b0
void FUN_00a674b0_cls::GetOutRec(OutRec674* out)
{
    if (m_3a != 0)
    {
        int b = 0;
        int c = 0;
        int a = 0;
        int e;
        int f;
        Obj_a674* obj = m_30;
        if (obj != 0 && obj->v35() && (obj->m_2c & 1) != 0)
        {
            int d = 0;
            obj->NiAdditionalGeometryData_GetDataStream(1, &a, &f, &c, &e, &d, &b);
        }
        out->a = a;
        out->b = b;
        out->c = 0;
    }
}

extern int DAT_0109c28c;

struct FUN_00a693e0_cls
{
    int m_vptr00;

    void UpdateFields_00a693e0();
};

// @fnv 0x00a693e0
// src: GUESS 0x00a693e0 (confidence: low)
void FUN_00a693e0_cls::UpdateFields_00a693e0()
{
    m_vptr00 = (int)&DAT_0109c28c;
}

extern unsigned int DAT_011f4980;
extern unsigned int DAT_011f4984;
struct FUN_00a69b00
{
    unsigned int originXBits, originYBits;
    float originZ, extentX, extentY, scaleX, scaleY;
    volatile unsigned char enabled;
    unsigned char unk1D, unk1E, unk1F;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    volatile int mode;
    FUN_00a69b00();
};
// Constructor initializing origin bits from globals, unit extents, 0.5 scales, enabled=1 and mode=2.
// @fnv 0x00a69b00
FUN_00a69b00::FUN_00a69b00()
    : originXBits(DAT_011f4980), originYBits(DAT_011f4984), originZ(0.f), extentX(1.f), extentY(1.f), scaleX(0.5f),
      scaleY(0.5f), enabled(1), mode(2)
{}

struct FUN_00a69b40_Class
{
    void __thiscall NiTexturingProperty_SetMultiTexture(int param_2);
};

// Sets or clears bit 0 of the flags at offset 0x18 depending on whether param_2 is nonzero or any entry after the first in the array at 0x20 is nonzero.
// @fnv 0x00a69b40
// src: GAMEBRYO_LIB 0x00a69b40
void FUN_00a69b40_Class::NiTexturingProperty_SetMultiTexture(int param_2)
{
    bool found = param_2 != 0;
    if (!found)
    {
        unsigned int count = *(unsigned short*)((char*)this + 0x26);
        unsigned int index = 1;
        if (index < count)
        {
            int* value = *(int**)((char*)this + 0x20) + 1;
            do
            {
                if (*value != 0)
                {
                    found = true;
                    break;
                }
                ++value;
                ++index;
            } while (index < count);
        }
    }

    if (found)
    {
        *(unsigned short*)((char*)this + 0x18) |= 1;
    }
    else
    {
        *(unsigned short*)((char*)this + 0x18) &= 0xfffe;
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);


inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

inline void NiFixedString::Clear()
{
    char* old = m_kHandle;
    if (old)
    {
        m_kHandle = NiGlobalStringTable::AddString(0);
        NiGlobalStringTable::DecRefCount(old);
    }
}
extern NiRefObject* DAT_011f49ac;
extern NiFixedString DAT_011f49b0;
extern NiFixedString DAT_011f49b4;
extern NiFixedString DAT_011f49b8;
extern NiFixedString DAT_011f49bc;
extern NiFixedString DAT_011f49c0;
extern NiFixedString DAT_011f49c4;
extern NiFixedString DAT_011f49c8;
extern NiFixedString DAT_011f49cc;
extern NiFixedString DAT_011f49d0;
extern NiFixedString DAT_011f49d4;

// Releases the global ref-counted object and clears ten global fixed strings.
// @fnv 0x00a6a6f0
void ReleaseGlobalStrings()
{
    if (DAT_011f49ac)
    {
        DAT_011f49ac->DecRefCount();
        DAT_011f49ac = 0;
    }
    DAT_011f49b0.Clear();
    DAT_011f49b4.Clear();
    DAT_011f49b8.Clear();
    DAT_011f49bc.Clear();
    DAT_011f49c0.Clear();
    DAT_011f49c4.Clear();
    DAT_011f49c8.Clear();
    DAT_011f49cc.Clear();
    DAT_011f49d0.Clear();
    DAT_011f49d4.Clear();
}

struct FUN_00a6db50_V
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00a6db50_V* __thiscall Set(float a, float b, float c, float d);
};

// Stores the four float arguments into m_00, m_04, m_08 and m_0c and returns this.
// @fnv 0x00a6db50
FUN_00a6db50_V* __thiscall FUN_00a6db50_V::Set(float a, float b, float c, float d)
{
    m_00 = a;
    m_04 = b;
    m_08 = c;
    m_0c = d;
    return this;
}

class A6DB70ColorA
{
  public:
    A6DB70ColorA()
    {}
    A6DB70ColorA(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
    {}

    A6DB70ColorA NiQuaternion_Sum(const A6DB70ColorA& kColor) const;

    float r;
    float g;
    float b;
    float a;
};

// operator+
// Returns a new color whose components are this color's components plus the corresponding components of the given color.
// @fnv 0x00a6db70
// src: COMMUNITY 0x00a6db70
A6DB70ColorA A6DB70ColorA::NiQuaternion_Sum(const A6DB70ColorA& kColor) const
{
    return A6DB70ColorA(r + kColor.r, g + kColor.g, b + kColor.b, a + kColor.a);
}

struct FUN_00a6dbd0_cls
{
    float m_f0;
    float m_f1;
    float m_f2;
    float m_f3;

    void Negate(float* __restrict out);
};
// Writes the negation of each of the four float members into the output array.
// @fnv 0x00a6dbd0
void FUN_00a6dbd0_cls::Negate(float* __restrict out)
{
    out[0] = -m_f0;
    out[1] = -m_f1;
    out[2] = -m_f2;
    out[3] = -m_f3;
}

class FUN_00a71b80_cls
{
  public:
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    unsigned char m_18;

    FUN_00a71b80_cls* Init(float a1, float a2, float a3, float a4, float a5, float a6, unsigned char flag);
};

// Stores six float arguments and a flag byte into the object's fields and returns the object.
// @fnv 0x00a71b80
FUN_00a71b80_cls* FUN_00a71b80_cls::Init(float a1, float a2, float a3, float a4, float a5, float a6, unsigned char flag)
{
    FUN_00a71b80_cls* p = this;
    p->m_00 = a1;
    p->m_18 = flag;
    p->m_04 = a2;
    p->m_08 = a3;
    p->m_0c = a4;
    p->m_10 = a5;
    p->m_14 = a6;
    return p;
}

struct FUN_00a75dc0_cls
{
    void* FUN_00a75dc0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5,
                       unsigned int a6, unsigned int a7, unsigned int a8, unsigned int a9, unsigned int a10,
                       unsigned int a11);
};

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct FUN_00a71c40_cls
{
    int* m_vt;
    void FUN_00a89720(void* p);
    FUN_00a71c40_cls* ConstructWithAlloc(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4,
                                         unsigned int a5, unsigned int a6, unsigned int a7, unsigned int a8,
                                         unsigned int a9, unsigned int a10, unsigned int a11);
};

// @fnv 0x00a71c40
FUN_00a71c40_cls* FUN_00a71c40_cls::ConstructWithAlloc(unsigned int a1, unsigned int a2, unsigned int a3,
                                                       unsigned int a4, unsigned int a5, unsigned int a6,
                                                       unsigned int a7, unsigned int a8, unsigned int a9,
                                                       unsigned int a10, unsigned int a11)
{
    void* obj;
    void* mem = Object_DispatchCommandFour(0x50);
    if (mem != 0)
    {
        obj = ((FUN_00a75dc0_cls*)mem)->FUN_00a75dc0(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    else
    {
        obj = 0;
    }
    this->FUN_00a89720(obj);
    this->m_vt = &DAT_0109cd44;
    return this;
}

// FUN_00a71cc0 : constructor-like helper that calls a base routine with the
// argument and then installs the class vtable pointer, returning itself.

extern int DAT_0109cd44;

struct FUN_00a71cc0_cls
{
    void* m_pVTable;
    void FUN_00a89720(int arg);
    FUN_00a71cc0_cls* NiTriStrips_NiTriStrips(int arg);
};

// @fnv 0x00a71cc0
// src: EXE 0x00a71cc0
FUN_00a71cc0_cls* FUN_00a71cc0_cls::NiTriStrips_NiTriStrips(int arg)
{
    FUN_00a89720(arg);
    m_pVTable = (void*)&DAT_0109cd44;
    return this;
}

struct FUN_00a72550_Class
{
    struct Item
    {
        int unk00;
        int unk04;
        int unk08;
    };
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Item** unk20;
    unsigned short unk24;
    unsigned short unk26;

    int GetItemData(unsigned int index, int* out);
};

// Clears out, bounds-checks index against unk26, and if unk20[index] exists writes its unk04 to out and returns its unk08.
// @fnv 0x00a72550
int FUN_00a72550_Class::GetItemData(unsigned int index, int* out)
{
    *out = 0;
    if (index >= unk26)
        return 0;

    Item* item = unk20[index];
    if (!item)
        return 0;

    *out = item->unk04;
    return item->unk08;
}

struct SceneEntry
{
    virtual void Detach(unsigned int reason);
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0C();
    virtual void Prepare(unsigned int reason);
};

struct IndexedObjects
{
    void* vtable;
    SceneEntry** entries;
    unsigned short capacity;
    unsigned short count;
    unsigned short elementSize;
    unsigned short growth;
    void __thiscall FUN_00ba3aa0(unsigned int index, unsigned int* removed);
};

struct LinkedRecord
{
    void* owner;
    void* object;
    void* metadata;
    void* parent;
    void* child;
    unsigned int objectIndex;
    void* cachedValue;
};

struct ObjectRegistry
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    unsigned int recordCount;
    LinkedRecord* records;
    void* unk18;
    IndexedObjects indexedObjects;

    bool __thiscall RemoveObject(unsigned int index, bool clearReferences);
};

// @fnv 0x00a72600
bool __thiscall ObjectRegistry::RemoveObject(unsigned int index, bool clearReferences)
{
    SceneEntry* object = index < indexedObjects.count ? indexedObjects.entries[index] : 0;
    if (!object)
        return false;

    object->Prepare(0);
    object->Detach(1);

    unsigned int removed = 0;
    indexedObjects.FUN_00ba3aa0(index, &removed);

    if (clearReferences)
    {
        for (unsigned int i = 0; i < recordCount; ++i)
        {
            LinkedRecord* record = &records[i];
            if (index == record->objectIndex && i < recordCount && records)
            {
                record->object = 0;
                record->parent = 0;
                record->metadata = 0;
                record->child = 0;
                record->objectIndex = 0;
                record->cachedValue = 0;
            }
        }
    }
    return true;
}

struct BA726A0Entry
{
    unsigned int m_uiValue1;
    void* m_pResource;
    unsigned int m_uiStride;
    unsigned int m_uiSize;
    unsigned int m_uiValueBeforeCount;
    unsigned int m_uiCount;
    unsigned int m_uiElapsedTime;
};

class FUN_00a726a0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFormat;
    unsigned int m_uiStreamIndex;
    BA726A0Entry* m_pkEntryArray;
    int unk18;
    int unk1C;
    int unk20;
    unsigned short unk24;
    unsigned short m_usMaxCount;

    bool NiAdditionalGeometryData_SetDataStream(unsigned int uiIndex, unsigned int ItemUpdateArray, unsigned int uiStart, void* pvData,
                      unsigned short usFormat, unsigned int uiStride, unsigned int uiElapsedMilliseconds);
};

// Validates format, index, count and entry pointer, then fills the entry at uiIndex with the data pointer, count, start, stride and size.
// @fnv 0x00a726a0
// src: COMMUNITY 0x00a726a0
bool FUN_00a726a0_cls::NiAdditionalGeometryData_SetDataStream(unsigned int uiIndex, unsigned int ItemUpdateArray, unsigned int uiStart, void* pvData,
                                    unsigned short usFormat, unsigned int uiStride, unsigned int uiElapsedMilliseconds)
{
    if (usFormat != m_usFormat)
        return false;
    if (uiIndex >= m_uiStreamIndex || !m_pkEntryArray)
        return false;
    if (ItemUpdateArray > m_usMaxCount)
        return false;

    BA726A0Entry& kEntry = m_pkEntryArray[uiIndex];
    kEntry.m_pResource = pvData;
    kEntry.m_uiCount = ItemUpdateArray;
    kEntry.m_uiValueBeforeCount = uiElapsedMilliseconds;
    kEntry.m_uiElapsedTime = uiStart;
    kEntry.m_uiStride = uiStride;
    kEntry.m_uiSize = usFormat * uiStride;
    return true;
}

struct ObjectWriter
{
    void* vtable;
    unsigned int bytesWritten;
    unsigned int(__cdecl* write)(ObjectWriter*, const void*, unsigned int, const unsigned int*, int);
};

struct BinaryStream
{
    ObjectWriter* Writer()
    {
        return *reinterpret_cast<ObjectWriter**>(reinterpret_cast<char*>(this) + 0x24c);
    }
};

struct ColorState
{
    unsigned char format;
    unsigned char flags;
    unsigned short reserved;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int alpha;
    unsigned int threshold;
    unsigned int blendMode;

    void NiAdditionalGeometryData_NiAGDDataStream_LoadBinary(BinaryStream* stream);
};

// Writes red, green, blue, alpha, threshold and blendMode as 4-byte values, then format as 1 byte, to the stream's writer.
// @fnv 0x00a72cb0
// src: COMMUNITY 0x00a72cb0
void ColorState::NiAdditionalGeometryData_NiAGDDataStream_LoadBinary(BinaryStream* stream)
{
    ObjectWriter* __restrict writer = stream->Writer();
    {
        unsigned int elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &red, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &green, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &blue, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &alpha, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &threshold, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 4;
        writer->bytesWritten += writer->write(writer, &blendMode, 4, &elementWidth, 1);

        writer = stream->Writer();
        elementWidth = 1;
        writer->bytesWritten += writer->write(writer, this, 1, &elementWidth, 1);
    }
}


template <class T>
inline void BA72DB0BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BA72DB0SaveBinary(NiStream& kStream, const T& value)
{
    BA72DB0BinaryStreamSave(*StreamOutput(kStream), &value);
}

class BA72DB0Data
{
  public:
    void NiAdditionalGeometryData_NiAGDDataStream_SaveBinary(NiStream& kStream);

    bool m_bFlag;
    int m_iValue0;
    int m_iValue1;
    int m_iValue2;
    int m_iValue3;
    int m_iValue4;
    int m_iValue5;
};

// Writes m_iValue0 through m_iValue5 and m_bFlag to kStream via BA72DB0SaveBinary.
// @fnv 0x00a72db0
// src: XBOX_PDB 0x00a72db0
void BA72DB0Data::NiAdditionalGeometryData_NiAGDDataStream_SaveBinary(NiStream& kStream)
{
    BA72DB0SaveBinary(kStream, m_iValue0);
    BA72DB0SaveBinary(kStream, m_iValue1);
    BA72DB0SaveBinary(kStream, m_iValue2);
    BA72DB0SaveBinary(kStream, m_iValue3);
    BA72DB0SaveBinary(kStream, m_iValue4);
    BA72DB0SaveBinary(kStream, m_iValue5);
    BA72DB0SaveBinary(kStream, m_bFlag);
}

extern int DAT_0109d55c;

struct SceneFactoryObject
{
    void* m_vtbl;
    void Initialize();
};

// Allocates a 196-byte SceneFactoryObject, initializes it, sets its vtable to DAT_0109d55c, and returns it (or null on allocation failure).
// @fnv 0x00a74750
SceneFactoryObject* CreateSceneFactoryObject()
{
    SceneFactoryObject* object = static_cast<SceneFactoryObject*>(BSFadeNode::operator new(196));
    if (object)
    {
        object->Initialize();
        object->m_vtbl = &DAT_0109d55c;
        return object;
    }
    return 0;
}

extern int DAT_011aa04c;

// @fnv 0x00a74d80
// src: COMMUNITY 0x00a74d80
void __cdecl NiProcessorSpecificCode_SetVectorTransformFunction(int param_1)
{
    DAT_011aa04c = param_1;
}

// FUN_00a74d90 - installs a callback pointer into the global slot at 0x011aa050.
//
// Original bytes:
//   8b 44 24 04          mov eax, dword ptr [esp+4]
//   a3 50 a0 1a 01       mov dword ptr [0x011aa050], eax
//   c3                   ret
//
// The global is referenced by a plain DIR32 relocation with addend 0 and is
// declared (never defined) here, so the checker binds it to the original's
// own address.  The name is spelled with a void* type so that it does not
// collide with the canonical "?DAT_011aa050@@3HA" entry in the symbol DB.
extern void* DAT_011aa050;

// @fnv 0x00a74d90
// src: COMMUNITY 0x00a74d90
void __cdecl NiProcessorSpecificCode_SetPointTransformFunction(void* callback)
{
    DAT_011aa050 = callback;
}

struct CallTarget_00a74e10
{
    int SetFromFrustum(int, int);
};
struct SearchObject
{
    int NiFrustumPlanes_Set_(unsigned int arg0);
};
// @fnv 0x00a755d0
// src: COMMUNITY 0x00a755d0
int SearchObject::NiFrustumPlanes_Set_(unsigned int arg0)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00a74e10*)this)->SetFromFrustum((int)(arg0 + 220u), (int)(104u + arg0));
    return (int)callResult0;
}

extern int DAT_00ff0000;

struct FUN_00a77110_info
{
    unsigned int m_eVertexFormat;
    unsigned int m_flags;
};

// @fnv 0x00a77110
// src: GAMEBRYO_LIB 0x00a77110
void __cdecl NiDevImageConverter_ConvertRGBA32To24(unsigned int width, unsigned int rows, unsigned int unk0c, unsigned char* dst,
                          unsigned int unk14, FUN_00a77110_info* info, const unsigned char* src)
{
    if (info->m_flags != 0xff00)
        return;
    unsigned int key = info->m_eVertexFormat;
    if (key == (unsigned int)&DAT_00ff0000)
    {
        if (rows <= 0)
            return;
        unsigned int r = rows;
        do
        {
            if (width > 0)
            {
                unsigned int w = width;
                do
                {
                    dst[0] = src[2];
                    dst++;
                    dst[0] = src[1];
                    dst++;
                    dst[0] = src[0];
                    dst++;
                    src += 4;
                    w--;
                } while (w != 0);
            }
            r--;
        } while (r != 0);
    }
    else if (key == 0xff)
    {
        if (rows <= 0)
            return;
        unsigned int r = rows;
        do
        {
            if (width > 0)
            {
                unsigned int w = width;
                do
                {
                    *dst = src[0];
                    dst++;
                    src++;
                    *dst = src[0];
                    dst++;
                    src++;
                    *dst = src[0];
                    dst++;
                    src += 2;
                    w--;
                } while (w != 0);
            }
            r--;
        } while (r != 0);
    }
}

struct BitPackLayout
{
    unsigned int mask0;
    unsigned int mask1;
    unsigned int mask2;
    unsigned int unk0C;
    unsigned char rshift0;
    unsigned char rshift1;
    unsigned char rshift2;
    unsigned char unk13;
    unsigned char lshift0;
    unsigned char lshift1;
    unsigned char lshift2;
};

// For each of countB rows and countA pixels, reads a 16-bit source value and writes three bytes extracted with the layout's masks and shifts.
// @fnv 0x00a772b0
void UnpackPixels(unsigned int countA, unsigned int uiRowCount, unsigned int uiUnused0C, unsigned char* dst,
                  unsigned int uiUnused14, unsigned int uiUnused18, unsigned int srcAddr, const BitPackLayout* layout)
{
    const unsigned short* src = (const unsigned short*)srcAddr;
    for (srcAddr = 0; srcAddr < uiRowCount; srcAddr++)
    {
        for (unsigned int x = 0; x < countA; x++)
        {
            *dst++ = (unsigned char)(((*src & layout->mask0) >> layout->rshift0) << layout->lshift0);
            *dst++ = (unsigned char)(((*src & layout->mask1) >> layout->rshift1) << layout->lshift1);
            *dst++ = (unsigned char)(((*src++ & layout->mask2) >> layout->rshift2) << layout->lshift2);
        }
    }
}

// Convert a 16-bit-per-pixel surface into 32-bit RGBA.
//
// The pixel layout is described by FnvPixelFormat: four channel masks
// (dwords) followed by the per-channel right and left shift amounts
// (bytes).  Each source pixel is a 16-bit word; every channel is
// extracted, scaled and written as one byte of the destination pixel.
//
// arg0 = pixels per pass, arg1 = number of passes,
// arg3 = destination bytes, arg6 = source words, arg7 = pixel layout.

struct FnvPixelFormat
{
    unsigned int mask[4];
    unsigned char shiftRight[4];
    unsigned char shiftLeft[4];
};

// Converts count pixels per row from src into 4 bytes each in dest using fmt masks and shifts, for rows rows.
// @fnv 0x00a77330
void ConvertPixelsToBytes(unsigned int count, unsigned int rows, unsigned int auiUnused, char* dest,
                          unsigned int auiUnused2, void* apUnused, unsigned short* src, FnvPixelFormat* fmt)
{
    unsigned short* s = src;
    if (rows <= 0)
        return;
    for (unsigned char* p = (unsigned char*)rows; p != 0; --p)
    {
        if (count > 0)
        {
            for (unsigned int col = count; col > 0; --col)
            {
                *dest++ = (unsigned char)((*s & fmt->mask[0]) >> fmt->shiftRight[0]) << fmt->shiftLeft[0];
                *dest++ = (unsigned char)((*s & fmt->mask[1]) >> fmt->shiftRight[1]) << fmt->shiftLeft[1];
                *dest++ = (unsigned char)((*s & fmt->mask[2]) >> fmt->shiftRight[2]) << fmt->shiftLeft[2];
                *dest++ = (unsigned char)((*s & fmt->mask[3]) >> fmt->shiftRight[3]) << fmt->shiftLeft[3];
                s++;
            }
        }
    }
}

namespace fnv_00a77460 {
extern "C" unsigned char DAT_00ff0000;
// Converts a width-by-height RGB source image to RGBA in dst, writing 0xFF alpha and swapping channels when mask[0] matches DAT_00ff0000.
// @fnv 0x00a77460
void __cdecl ConvertRgbToRgba(unsigned int width, unsigned int height, int, unsigned char* dst, int, int,
                              const unsigned char* src, const unsigned int* mask)
{
    if (mask[1] == 0xFF00)
    {
        if (mask[0] == (unsigned int)&DAT_00ff0000)
        {
            if (height > 0)
            {
                unsigned int rows = height;
                do
                {
                    if (width > 0)
                    {
                        unsigned int cols = width;
                        do
                        {
                            *dst++ = src[2];
                            *dst++ = src[1];
                            *dst++ = src[0];
                            *dst++ = 0xFF;
                            src += 3;
                        } while (--cols != 0);
                    }
                } while (--rows != 0);
            }
        }
        else
        {
            if (height > 0)
            {
                unsigned int rows = height;
                do
                {
                    if (width > 0)
                    {
                        unsigned int cols = width;
                        do
                        {
                            *dst++ = *src++;
                            *dst++ = *src++;
                            *dst++ = *src++;
                            *dst++ = 0xFF;
                        } while (--cols != 0);
                    }
                } while (--rows != 0);
            }
        }
    }
}
}  // namespace fnv_00a77460

struct A77740Format
{
    unsigned int m_uiMask0;
    unsigned int m_uiMask1;
    unsigned int m_uiMask2;
    unsigned int m_uiMask3;
    unsigned char m_ucLeftShift0;
    unsigned char m_ucLeftShift1;
    unsigned char m_ucLeftShift2;
    unsigned char m_ucLeftShift3;
    unsigned char m_ucRightShift0;
    unsigned char m_ucRightShift1;
    unsigned char m_ucRightShift2;
    unsigned char m_ucRightShift3;
};

// @fnv 0x00a77740
void ConvertRgbToPacked16(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiUnused, unsigned char* pucDest,
                          unsigned int uiUnused2, const A77740Format* pkFmt, const unsigned char* pucSrc)
{
    unsigned short* pusDest = (unsigned short*)pucDest;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            unsigned char r = *pucSrc;
            unsigned char g = *++pucSrc;
            unsigned char b = *++pucSrc;
            pucSrc += 2;
            *pusDest++ = ((unsigned short)(r >> pkFmt->m_ucRightShift0) << pkFmt->m_ucLeftShift0 & pkFmt->m_uiMask0) |
                         ((unsigned short)(g >> pkFmt->m_ucRightShift1) << pkFmt->m_ucLeftShift1 & pkFmt->m_uiMask1) |
                         ((unsigned short)(b >> pkFmt->m_ucRightShift3) << pkFmt->m_ucLeftShift3 & pkFmt->m_uiMask3);
        }
    }
}

struct S_00a77800_Layout
{
    unsigned int mask0;
    unsigned int mask1;
    unsigned int unk08;
    unsigned int mask2;
    unsigned char shl0;
    unsigned char shl1;
    unsigned char unk12;
    unsigned char shl2;
    unsigned char shr0;
    unsigned char shr1;
    unsigned char unk16;
    unsigned char shr2;
};

// For each pixel, reads two bytes from src and combines shifted/masked channel bits from layout into one packed value written to dst.
// @fnv 0x00a77800
// src: GAMEBRYO_LIB 0x00a77800
void __cdecl NiDevImageConverter_ConvertBUMP16To32(unsigned int count, unsigned int rows, unsigned int auiUnused3, unsigned int* dst,
                          unsigned int auiUnused5, const S_00a77800_Layout* layout, const unsigned char* src)
{
    unsigned int* d = dst;
    for (unsigned int y = 0; y < rows; y++)
    {
        for (unsigned int x = 0; x < count; x++)
        {
            unsigned char b0 = *src++;
            unsigned char b1 = *src++;
            unsigned int r = ((b0 >> layout->shr0) << layout->shl0) & layout->mask0;
            r |= ((b1 >> layout->shr1) << layout->shl1) & layout->mask1;
            r |= ((0xffffffffu >> layout->shr2) << layout->shl2) & layout->mask2;
            *d++ = r;
        }
    }
}

// Returns true when the argument is a power of two (zero is not).
// @fnv 0x00a77920
// src: GAMEBRYO_LIB 0x00a77920
bool NiIsPowerOf2(int aiValue)
{
    if (aiValue == 0)
        return false;
    return (aiValue & (aiValue - 1)) == 0;
}


typedef unsigned int (*NiBinaryStreamWriteFn)(NiBinaryStream* pThis, const void* pvBuffer, unsigned int uiBytes,
                                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);


template <class T> inline void SerializeValue(NiBinaryStream& binstream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    binstream.BinaryWrite(&value, uiSize, &uiSize, 1);
}

template <class T> inline void SerializeValue(NiStream& stream, const T& value)
{
    SerializeValue(*StreamOutput(stream), value);
}

struct Entry
{
    int a;
    int b;
    char c;
    char d;
};

struct FUN_00a7d1a0_Class
{
    char m_c0;
    char m_c1;
    int m_i4;
    int m_i8;
    int m_iC;
    int m_i10;
    Entry m_entries[4];

    void NiPixelFormat_SaveBinary(NiStream& stream);
};

// Writes the object's fields and its four Entry records to the given NiStream in a fixed order.
// @fnv 0x00a7d1a0
// src: XBOX_PDB 0x00a7d1a0
void FUN_00a7d1a0_Class::NiPixelFormat_SaveBinary(NiStream& stream)
{
    SerializeValue(stream, m_i4);
    SerializeValue(stream, m_c1);
    SerializeValue(stream, m_iC);
    SerializeValue(stream, m_i10);
    SerializeValue(stream, m_c0);
    SerializeValue(stream, m_i8);
    for (unsigned int i = 0; i < 4; i++)
    {
        SerializeValue(stream, m_entries[i].a);
        SerializeValue(stream, m_entries[i].b);
        SerializeValue(stream, m_entries[i].c);
        char d = m_entries[i].d;
        SerializeValue(stream, d);
    }
}

void* __cdecl BuildSqrtLut();

// @fnv 0x00a7e930
// src: COMMUNITY 0x00a7e930
void NiPoint3__SDMInit()
{
    DAT_011f4aa8 = BuildSqrtLut();
}






static inline NiPoint3 operator*(const Transform::Mat& rotation, const NiPoint3& v)
{
    const float (*m)[3] = rotation.entries;
    return NiPoint3(m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z,
                    m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z,
                    m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z);
}

static inline NiPoint3 operator+(const NiPoint3& v, const Transform::PlainVec& translation)
{
    NiPoint3 result;
    result.x = translation.x + v.x;
    result.y = v.y + translation.y;
    result.z = v.z + translation.z;
    return result;
}

struct S_00a7fea0_Class
{
    NiPoint3 p;
    float scale;
    void TransformPoint(const Transform& a);
};

// Applies the transform's rotation, scale and translation to p, and multiplies scale by the transform's scale.
// @fnv 0x00a7fea0
void S_00a7fea0_Class::TransformPoint(const Transform& aXf)
{
    AssignPoint(p, aXf.scale * (aXf.rotation * p) + aXf.position);
    scale = aXf.scale * scale;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

inline void NiTexture::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

struct NodeA61
{
    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }

    NiPointer<NiTexture> m_pReferencedObject;
    int m_iData;
    NodeA61* m_pkNext;
};

unsigned int __cdecl GetPrefixLengthA61(const char* pcName, int iFlags);
unsigned int __cdecl HashNameA61(const char* pcName);

class NameTableA61
{
  public:
    void RemoveNode(NodeA61* pkNode);

    NodeA61* m_apkBuckets[713];
    unsigned int m_uiCount;
};

// @fnv 0x00a61890
void NameTableA61::RemoveNode(NodeA61* pkNode)
{
    const char* pcName = pkNode->m_pReferencedObject->GetPath().m_kHandle;
    unsigned int uiBucket = HashNameA61(pcName + GetPrefixLengthA61(pcName, 1));
    NodeA61* pkCurrent = m_apkBuckets[uiBucket];
    if (!pkCurrent)
        return;

    NodeA61* pkPrev = 0;
    do
    {
        if (pkCurrent == pkNode)
        {
            if (pkPrev)
                pkPrev->m_pkNext = pkCurrent->m_pkNext;
            else
                m_apkBuckets[uiBucket] = pkCurrent->m_pkNext;
            delete pkCurrent;
            m_uiCount--;
            return;
        }
        pkPrev = pkCurrent;
        pkCurrent = pkCurrent->m_pkNext;
    } while (pkCurrent);
}

// Fixed-size (713 bucket) pointer map: return the current entry's object and advance the iterator.

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plValue);



template <class T> class A619B0Pointer
{
  public:
    T* m_pObject;

    A619B0Pointer& operator=(const A619B0Pointer& kOther) throw()
    {
        if (m_pObject != kOther.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = kOther.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct A619B0Item
{
    A619B0Pointer<NiRefObject> m_spValue;
    int m_iKey;
    A619B0Item* m_pkNext;
};

struct A619B0Iterator
{
    A619B0Item* m_pkItem;
    unsigned int m_uiBucket;
};

class A619B0Map
{
  public:
    A619B0Item* m_apkBuckets[713];

    bool GetNext(A619B0Iterator& kIter, A619B0Pointer<NiRefObject>& rspValue);
};

// Advances the iterator to the next item, skipping empty buckets, and copies the current item's value into rspValue; returns whether an item remains.
// @fnv 0x00a619b0
bool A619B0Map::GetNext(A619B0Iterator& kIter, A619B0Pointer<NiRefObject>& rspValue)
{
    if (kIter.m_pkItem)
    {
        rspValue = kIter.m_pkItem->m_spValue;
        kIter.m_pkItem = kIter.m_pkItem->m_pkNext;
        if (!kIter.m_pkItem)
        {
            while (++kIter.m_uiBucket < 713)
            {
                if (m_apkBuckets[kIter.m_uiBucket])
                {
                    kIter.m_pkItem = m_apkBuckets[kIter.m_uiBucket];
                    break;
                }
            }
        }
    }
    return kIter.m_pkItem != 0;
}

struct MyPool
{
    FUN_00a61ec0_cls m_buckets[7];
};

extern FUN_00a615c0_Class* DAT_011f4468;
extern RecursiveSpinLock DAT_011f4480;
extern int DAT_011f4484;

// @fnv 0x00a62030
// src: COMMUNITY 0x00a62030
void __cdecl BSTexturePalette_RemoveAll()
{
    if (DAT_011f4468 != 0)
    {
        DAT_011f4480.BSSpinLock_Lock(0);
        DAT_011f4468->ClearAllBuckets();
        for (unsigned int i = 0; i < 7; i++)
            ((MyPool*)DAT_011f4464)->m_buckets[i].ClearAllSlots();
        if (--DAT_011f4484 == 0)
            *(int*)&DAT_011f4480 = 0;
    }
}


template <class T> inline void BA643B0BinaryStreamLoad(NiBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BA643B0LoadBinary(NiStream& kStream, T& value)
{
    BA643B0BinaryStreamLoad(*StreamInput(kStream), &value);
}

// Reads one char from the stream's binary stream into pcValue via BA643B0BinaryStreamLoad.
// @fnv 0x00a643b0
// src: XBOX_PDB 0x00a643b0
void __cdecl NiStreamLoadBinary_char_00a643b0(NiStream& kStream, char* pcValue)
{
    BA643B0BinaryStreamLoad(*StreamInput(kStream), pcValue);
}

struct Q67530Data
{
    int a;
    int b;
    int d;
    int c;
    int e;
    int f;
};


struct Q67530Cls : FUN_00a674b0_cls
{
    void FillOutRec674(OutRec674* out);
};

// @fnv 0x00a67530
void Q67530Cls::FillOutRec674(OutRec674* out)
{
    if (m_3a)
    {
        Obj_a674* p = m_30;
        Q67530Data q;
        q.b = 0;
        q.c = 0;
        q.a = 0;
        if (p && p->v35() && (p->m_2c & 1))
        {
            q.d = 0;
            ((BSFaceGenModel*)p)->NiAdditionalGeometryData_GetDataStream(2, &q.a, &q.f, &q.c, &q.e, &q.d, &q.b);
        }
        out->a = q.a;
        out->b = q.b;
        out->c = 0;
    }
}

void* __cdecl NiMallocA6F(unsigned int uiSize) throw();
extern "C" void* __cdecl MemSetA6F(void* pvDest, int iValue, unsigned int uiSize);

template <class TAlloc, class TVAL>
__forceinline NiTFixedStringMapBase<TAlloc, TVAL>::NiTFixedStringMapBase(unsigned int uiHashSize)
{
    m_uiHashSize = uiHashSize;
    m_kItemCount.m_uiCount = 0;
    unsigned int uiSize = sizeof(EntryType*) * m_uiHashSize;
    m_ppkHashTable = (EntryType**)NiMallocA6F(uiSize);
    MemSetA6F(m_ppkHashTable, 0, m_uiHashSize * sizeof(EntryType*));
}

template <class TVAL>
__forceinline NiTFixedStringMap<TVAL>::NiTFixedStringMap(unsigned int uiHashSize)
    : NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, TVAL> >, TVAL>(uiHashSize)
{
}

class NiExtraDataMapA6F : public NiObject
{
  public:
    __forceinline NiExtraDataMapA6F() throw() : m_pkLast(0)
    {}
    virtual ~NiExtraDataMapA6F() throw();

    static NiObject* NiDefaultAVObjectPalette_CreateObject();

    NiTFixedStringMap<NiAVObject*> m_kFormatEntries;
    void* m_pkLast;
};

// Allocates and constructs a new NiExtraDataMapA6F and returns it as a NiObject pointer.
// @fnv 0x00a6f000
// src: EXE 0x00a6f000
NiObject* NiExtraDataMapA6F::NiDefaultAVObjectPalette_CreateObject()
{
    return new NiExtraDataMapA6F;
}

struct NiPixelChannelsA773
{
    unsigned int m_uiRedMask;
    unsigned int m_uiGreenMask;
    unsigned int m_uiBlueMask;
    unsigned int m_uiAlphaMask;
    unsigned char m_ucRedShift;
    unsigned char m_ucGreenShift;
    unsigned char m_ucBlueShift;
    unsigned char m_ucAlphaShift;
    unsigned char m_ucRedBits;
    unsigned char m_ucGreenBits;
    unsigned char m_ucBlueBits;
    unsigned char m_ucAlphaBits;
};

// Converts a 16-bit source image to 32-bit RGBA output, extracting each channel via the supplied masks and shifts and writing an opaque alpha byte.
// @fnv 0x00a773d0
// src: GAMEBRYO_LIB 0x00a773d0
void __cdecl NiDevImageConverter_Convert16NoAlphaToRGBA32(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride,
                          unsigned char* pucDest, unsigned int uiDestSize, unsigned int uiSrcStride,
                          const unsigned short* pusSrc, const NiPixelChannelsA773* pkChannels)
{
    const unsigned short* pusPixel = pusSrc;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            *pucDest++ = (unsigned char)((*pusPixel & pkChannels->m_uiRedMask) >> pkChannels->m_ucRedShift)
                         << pkChannels->m_ucRedBits;
            *pucDest++ = (unsigned char)((*pusPixel & pkChannels->m_uiGreenMask) >> pkChannels->m_ucGreenShift)
                         << pkChannels->m_ucGreenBits;
            *pucDest++ = (unsigned char)((*pusPixel & pkChannels->m_uiBlueMask) >> pkChannels->m_ucBlueShift)
                         << pkChannels->m_ucBlueBits;
            *pucDest++ = 0xff;
            pusPixel++;
        }
    }
}

struct NiPixelChannelsA77
{
    unsigned int m_uiRedMask;
    unsigned int m_uiGreenMask;
    unsigned int m_uiBlueMask;
    unsigned int m_uiAlphaMask;
    unsigned char m_ucRedShift;
    unsigned char m_ucGreenShift;
    unsigned char m_ucBlueShift;
    unsigned char m_ucAlphaShift;
    unsigned char m_ucRedBits;
    unsigned char m_ucGreenBits;
    unsigned char m_ucBlueBits;
    unsigned char m_ucAlphaBits;
};

// Converts each source pixel to three destination bytes by masking and shifting the red, green and blue channels using the given channel masks and shifts.
// @fnv 0x00a77510
void __cdecl ConvertPixelsToRgb(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride,
                                unsigned char* pucDest, unsigned int uiDestSize, unsigned int uiSrcStride,
                                const unsigned int* puiSrc, const NiPixelChannelsA77* pkChannels)
{
    const unsigned int* puiPixel = puiSrc;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            *pucDest++ = (unsigned char)((*puiPixel & pkChannels->m_uiRedMask) >> pkChannels->m_ucRedShift)
                         << pkChannels->m_ucRedBits;
            *pucDest++ = (unsigned char)((*puiPixel & pkChannels->m_uiGreenMask) >> pkChannels->m_ucGreenShift)
                         << pkChannels->m_ucGreenBits;
            *pucDest++ = (unsigned char)((*puiPixel++ & pkChannels->m_uiBlueMask) >> pkChannels->m_ucBlueShift)
                         << pkChannels->m_ucBlueBits;
        }
    }
}

struct NiPixelChannelsA776
{
    unsigned int m_uiRedMask;
    unsigned int m_uiGreenMask;
    unsigned int m_uiBlueMask;
    unsigned int m_uiAlphaMask;
    unsigned char m_ucRedShift;
    unsigned char m_ucGreenShift;
    unsigned char m_ucBlueShift;
    unsigned char m_ucAlphaShift;
    unsigned char m_ucRedBits;
    unsigned char m_ucGreenBits;
    unsigned char m_ucBlueBits;
    unsigned char m_ucAlphaBits;
};

// @fnv 0x00a776b0
// src: GAMEBRYO_LIB 0x00a776b0
void __cdecl NiDevImageConverter_ConvertBUMPLUMA32To32(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride, unsigned int* puiDest,
                          unsigned int uiDestSize, const NiPixelChannelsA776* pkDestChannels,
                          const unsigned char* pucSrc, const NiPixelChannelsA776* pkSrcChannels)
{
    unsigned int* puiPixel = puiDest;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            unsigned char ucRed = *pucSrc++;
            unsigned char ucGreen = *pucSrc++;
            unsigned char ucAlpha = *pucSrc;
            pucSrc += 2;
            *puiPixel++ = (((ucRed >> pkDestChannels->m_ucRedBits) << pkDestChannels->m_ucRedShift) &
                           pkDestChannels->m_uiRedMask) |
                          (((ucAlpha >> pkDestChannels->m_ucAlphaBits) << pkDestChannels->m_ucAlphaShift) &
                           pkDestChannels->m_uiAlphaMask) |
                          (((ucGreen >> pkDestChannels->m_ucGreenBits) << pkDestChannels->m_ucGreenShift) &
                           pkDestChannels->m_uiGreenMask);
        }
    }
}

extern "C" int __cdecl tolower(int);

// @fnv 0x00a614d0
// src: COMMUNITY 0x00a614d0
bool __cdecl BSTexturePalette_ArePathsEqual(const char* a, const char* b)
{
    while (*a != 0)
    {
        int c1 = tolower(*a++);
        int c2 = tolower(*b++);
        if (c1 == '.')
        {
            if (c2 != c1)
            {
                return false;
            }
            if (a[3] == 0)
            {
                break;
            }
        }
        else if (c1 != c2)
        {
            return false;
        }
    }
    return true;
}

struct A5FC10Stub
{
    A5FC10Stub* __thiscall NiSourceTexture_NiSourceTexture();
};

void* __cdecl Object_DispatchCommandFour(unsigned int size);

// @fnv 0x00a60070
A5FC10Stub* __cdecl CreateA5FC10Stub()
{
    A5FC10Stub* object = (A5FC10Stub*)Object_DispatchCommandFour(0x48);

    if (object)
    {
        return object->NiSourceTexture_NiSourceTexture();
    }

    return 0;
}

struct This;

struct T
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    char pad[0x5b - 4];
    unsigned char m5b;
    virtual void v36(This*);
};

struct This
{
    char pad[0x24];
    T* m24;
    void DispatchIfStateFour();
};

// @fnv 0x00a60100
void This::DispatchIfStateFour()
{
    T* p = m24;
    if (p)
    {
        unsigned int iState = p ? p->m5b : 0;
        if (iState == 4)
            p->v36(this);
    }
}

struct FUN_00a5fca0_cls
{
    void UpdateFields_00a5fca0();
};
struct FUN_00a60160_cls : FUN_00a5fca0_cls
{
    void* DestroyIfFlagged(unsigned int flags);
};
extern "C" void __cdecl _delete(void* p, unsigned int size);
// Calls FUN_00a5fca0, then if bit 0 of flags is set frees this with size 0x48, and returns this.
// @fnv 0x00a60160
void* FUN_00a60160_cls::DestroyIfFlagged(unsigned int flags)
{
    UpdateFields_00a5fca0();
    if (flags & 1)
        _delete(this, 0x48);
    return this;
}

struct ControllerA606
{
    char m_acUnk00[0x18];
    unsigned int m_uiUnk18;
    unsigned int m_uiUnk1c;
    unsigned int m_uiUnk20;
    char m_acUnk24[0xc];
    void* m_kName;
    int m_iUnk34;
    void* m_pkTarget1;
    void* m_pkTarget2;
    bool m_bUnk40;
    bool m_bUnk41;
    bool m_bUseFirst;
    void NiSequenceStreamHelper_SaveBinary(NiStream& kStream);
    void NiSourceTexture_SaveBinary(NiStream& kStream);
};

// @fnv 0x00a60600
// src: XBOX_PDB 0x00a60600
void ControllerA606::NiSourceTexture_SaveBinary(NiStream& kStream)
{
    NiSequenceStreamHelper_SaveBinary(kStream);
    bool bNoTargets = !m_pkTarget1 && !m_pkTarget2;
    SerializeValue(kStream, bNoTargets);
    kStream.SerializeString(reinterpret_cast<const char*>(&m_kName));
    if (m_bUseFirst)
        kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_pkTarget1));
    else
        kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_pkTarget2));
    SerializeValue(kStream, m_uiUnk18);
    SerializeValue(kStream, m_uiUnk20);
    SerializeValue(kStream, m_uiUnk1c);
    bool bUnk40 = m_bUnk40;
    SerializeValue(kStream, bUnk40);
    bool bUnk41 = m_bUnk41;
    SerializeValue(kStream, bUnk41);
    bool bUseFirst = m_bUseFirst;
    SerializeValue(kStream, bUseFirst);
}

class FUN_00a5e3a0_Helper
{
  public:
    void* Game_DoHeapAlloc(unsigned int uiSize);
};

struct EntryA616
{
    int unk00;
    unsigned int m_key;
};

struct NodeA616
{
    EntryA616* m_entry;
    NodeA616* m_next;

    NodeA616(EntryA616* entry, NodeA616* next) : m_entry(entry), m_next(next)
    {}

    static void* operator new(unsigned int uiSize)
    {
        return ((FUN_00a5e3a0_Helper*)&_g_memoryManager)->Game_DoHeapAlloc(uiSize);
    }
    static void operator delete(void* p);
};

class HashA616
{
  public:
    NodeA616* m_buckets[1001];
    unsigned int m_uiItemCount;

    void BSEntryMap_SetAt(unsigned int key, EntryA616* entry);
};

// @fnv 0x00a61610
// src: COMMUNITY 0x00a61610
void HashA616::BSEntryMap_SetAt(unsigned int key, EntryA616* entry)
{
    unsigned int uiBucket = (key >> 4) % 1001;
    entry->m_key = key;
    m_buckets[uiBucket] = new NodeA616(entry, m_buckets[uiBucket]);
    m_uiItemCount++;
}

class A61E60Obj
{

  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();

    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();

    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();

    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();

    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();

    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();

    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();

    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();

    virtual char** GetNameRef();
};

struct A61E60Node
{

    A61E60Obj* m_key;

    unsigned int m_unk04;

    A61E60Node* m_pNext;
};

unsigned int __cdecl FUN_00af4170(const char* s, int n);

unsigned int BSTexturePalette_GetContainerNumber(const char* str);

struct NodeList
{
    A61E60Node* m_pHead;
    A61E60Node* Find(A61E60Obj* obj)
    {
        A61E60Node* n = m_pHead;
        while (n)
        {
            if (obj == n->m_key)
                break;
            n = n->m_pNext;
        }
        return n;
    }
};
// @fnv 0x00a61e60
void* __cdecl FindNodeByObject(A61E60Obj* obj)
{
    const char* pcName = *obj->GetNameRef();
    unsigned int idx = BSTexturePalette_GetContainerNumber(pcName + FUN_00af4170(pcName, 1));
    A61E60Node* n;
    for (unsigned int i = 0; i < 7; ++i)
    {
        n = ((NodeList*)&DAT_011f4464->m_buckets[i].m_entries[idx])->Find(obj);
        if (n)
            break;
    }
    return n;
}

bool __fastcall NiObjectNET_RegisterStreamables(void*, int, NiStream*);
// @fnv 0x00a62130
// src: XBOX_PDB 0x00a62130
bool __fastcall NiSequenceStreamHelper_RegisterStreamables(void* a, int b, NiStream* s)
{
    return NiObjectNET_RegisterStreamables(a, b, s);
}

class EqBase
{
  public:
    bool __thiscall NiObjectNET_IsEqual(void* other);
    bool __thiscall NiSequenceStreamHelper_IsEqual(void* other);
};

// @fnv 0x00a62140
// src: XBOX_PDB 0x00a62140
bool __thiscall EqBase::NiSequenceStreamHelper_IsEqual(void* other)
{
    return NiObjectNET_IsEqual(other);
}

class ColorAStandIn
{
  public:
    float r, g, b, a;
    ColorAStandIn()
    {}
    ColorAStandIn(float fR, float fG, float fB, float fA)
    {
        r = fR;
        g = fG;
        b = fB;
        a = fA;
    }
    ColorAStandIn Subtract(const ColorAStandIn& c) const;
};

// Returns a ColorAStandIn whose components are this color's r, g, b and a minus the corresponding components of c.
// @fnv 0x00a6dba0
ColorAStandIn ColorAStandIn::Subtract(const ColorAStandIn& c) const
{
    return ColorAStandIn(r - c.r, g - c.g, b - c.b, a - c.a);
}

struct FUN_00a727b0_Class
{
    unsigned int NiAdditionalGeometryData_GetDataBlockCount();
};

// @fnv 0x00a727b0
// src: XBOX_PDB 0x00a727b0
unsigned int FUN_00a727b0_Class::NiAdditionalGeometryData_GetDataBlockCount()
{
    return *(unsigned short*)((char*)this + 0x26);
}

extern void __cdecl FUN_00a8a9b0();

// @fnv 0x00a75f00
// src: XBOX_PDB 0x00a75f00
void __cdecl NiPSysData_RegisterStreamables()
{
    FUN_00a8a9b0();
}

// @fnv 0x00a75f20
// src: XBOX_PDB 0x00a75f20
unsigned short __fastcall NiTriBasedGeomData_GetActiveTriangleCount(char* p, int)
{
    return *reinterpret_cast<unsigned short*>(p + 0x40);
}

NiFile* __cdecl FUN_00aa1a20(const char* pcName, NiFile::OpenMode eMode, unsigned int uiBufferSize);

class ObjA609;

struct NamedA609
{
    const char* m_pcName;
};

class OwnerA609
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void Load(ObjA609* pkObj);

    char unk004[0x57];
    unsigned char m_eRequestType;
};

class ObjA609
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual NamedA609* GetNamed();

    char unk004[0x20];
    OwnerA609* m_pkOwnerManager;
    char unk028[0x1c];
    NiFile* m_pFile;

    void LoadFile();
};

// If the owner manager's request type is 2 or 3, opens the named file read-only, calls Load on the owner, then deletes the file handle.
// @fnv 0x00a60090
void ObjA609::LoadFile()
{
    if (m_pkOwnerManager)
    {
        int eType = m_pkOwnerManager->m_eRequestType;
        if (eType == 2 || eType == 3)
        {
            const char* pcName = GetNamed()->m_pcName;
            m_pFile = FUN_00aa1a20(pcName, NiFile::READ_ONLY, 0x8000);
            if (m_pFile)
            {
                m_pkOwnerManager->Load(this);
                delete m_pFile;
                m_pFile = 0;
            }
        }
    }
}


inline void NiFixedString::Assign(const char* value)
{
    char* old = m_kHandle;
    if (old != value)
    {
        m_kHandle = NiGlobalStringTable::AddString(value);
        NiGlobalStringTable::DecRefCount(old);
    }
}


template <class T> inline void TextureBinaryStreamLoad(NiBinaryStream& input, T* value, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    input.BinaryRead(value, count * size, &size, 1);
}
template <class T> inline void ReadTextureValue(NiStream& stream, T& value)
{
    TextureBinaryStreamLoad(*StreamInput(stream), &value);
}
inline void ReadTextureValue(NiStream& stream, bool& value)
{
    unsigned char byte;
    ReadTextureValue(stream, byte);
    value = byte != 0;
}
inline unsigned int NiStream::version()
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}
static inline void ReleaseTextureObject(NiRefObject* object)
{
    if (InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
        object->DeleteThis();
}

enum SourcePixelLayout
{
    PixelLayout4 = 4,
    PixelLayout5 = 5,
    PixelLayout6 = 6
};
enum SourceMipmapFormat
{
    MipmapDefault = 0,
    MipmapDisabled = 1,
    MipmapEnabled = 2
};
enum SourceAlphaFormat
{
    AlphaDefault = 0,
    AlphaNone = 1,
    AlphaBinary = 2,
    AlphaSmooth = 3
};


extern bool DAT_011f4780;
void __cdecl NiImageConverter_ConvertFilenameToPlatformSpecific_(void*, void*);
bool __cdecl NiFile_Access(const char*, int);

// Reads texture metadata and file references from a TextureLoadStream, resolving the texture name and registering the texture object.
// @fnv 0x00a60180
void NiSourceTexture::LoadBinary(NiStream& stream)
{
    NiTexture::LoadBinary(stream);
    InterlockedIncrement((volatile long*)&m_uiRefCount);
    unsigned char bOldVersion = 0;
    unsigned char ucExternal;
    if (stream.version() < 0x0a000104)
    {
        ReadTextureValue(stream, ucExternal);
        if (ucExternal)
        {
            stream.ReadFixedString(m_kFilename);
            if (m_spSrcPixelData.m_pObject)
            {
                ReleaseTextureObject(reinterpret_cast<NiRefObject*>(m_spSrcPixelData.m_pObject));
                m_spSrcPixelData.m_pObject = 0;
            }
            bOldVersion = true;
            stream.SetLinkIDCount(0);
        }
        else
        {
            m_kFilename.Clear();
            unsigned char ucHasPixels;
            ReadTextureValue(stream, ucHasPixels);
            if (ucHasPixels)
            {
                stream.SetLinkIDCount(1);
                stream.ReadLinkIDStub();
            }
            else
            {
                stream.SetLinkIDCount(0);
            }
        }
        if (m_spPersistentSrcRendererData.m_pObject)
        {
            ReleaseTextureObject(reinterpret_cast<NiRefObject*>(m_spPersistentSrcRendererData.m_pObject));
            m_spPersistentSrcRendererData.m_pObject = 0;
        }
    }
    else
    {
        ReadTextureValue(stream, bOldVersion);
        if (stream.version() < 0x14010001)
            stream.ReadFixedString(m_kFilename);
        else
            stream.ReadStringTableEntry(m_kFilename);
        stream.SetLinkIDCount(1);
        stream.ReadLinkIDStub();
    }
    if (m_kFilename.m_kHandle)
        NiImageConverter_ConvertFilenameToPlatformSpecific_(&m_kFilename, &m_kPlatformFilename);
    if (bOldVersion)
    {
        stream.SetStreamPath(m_kPlatformFilename.m_kHandle);
        DAT_011f4780 = true;
        NiTexture* pkTexture = 0;
        char acFileName[260];
        do
        {
            if (!stream.GetLastLoadedFilePath(acFileName, 260))
                break;
            stream.GetTexture(acFileName, reinterpret_cast<NiPointer<NiTexture>&>(pkTexture));
        } while (!pkTexture);
        if (pkTexture)
        {
            m_kPlatformFilename.Assign(acFileName);
            stream.ChangeObject(pkTexture);
        }
        else
        {
            DAT_011f4780 = true;
            while (stream.GetLastLoadedFilePath(acFileName, 260))
            {
                if (NiFile_Access(acFileName, 0))
                {
                    m_kPlatformFilename = static_cast<const char*>(acFileName);
                    stream.SetTexture(this);
                    break;
                }
            }
        }
        if (pkTexture)
            ReleaseTextureObject(pkTexture);
    }
    else if (m_kPlatformFilename.m_kHandle != NiGlobalStringTable::ms_pcEmptyString)
    {
        NiTexture* pkTexture = 0;
        stream.GetTexture(m_kPlatformFilename.m_kHandle, reinterpret_cast<NiPointer<NiTexture>&>(pkTexture));
        if (!pkTexture)
            stream.SetTexture(this);
        else
            stream.ChangeObject(pkTexture);
        if (pkTexture)
            ReleaseTextureObject(pkTexture);
    }
    {
        SourcePixelLayout value;
        ReadTextureValue(stream, value);
        m_kFormatPrefs.m_ePreferredPixelLayout = static_cast<NiTexture::TextureFormatPreferences::PixelLayout>(value);
    }
    {
        SourceMipmapFormat value;
        ReadTextureValue(stream, value);
        m_kFormatPrefs.m_eMipFlag = static_cast<NiTexture::TextureFormatPreferences::MipFlag>(value);
    }
    {
        SourceAlphaFormat value;
        ReadTextureValue(stream, value);
        m_kFormatPrefs.m_eAlphaFormat = static_cast<NiTexture::TextureFormatPreferences::AlphaFormat>(value);
    }
    if (stream.version() < 0x0303000c)
    {
        if (m_kFormatPrefs.m_ePreferredPixelLayout == 4)
            m_kFormatPrefs.m_ePreferredPixelLayout = NiTexture::TextureFormatPreferences::PIX_DEFAULT;
    }
    else if (stream.version() < 0x05000001)
    {
        if (m_kFormatPrefs.m_ePreferredPixelLayout == 5)
            m_kFormatPrefs.m_ePreferredPixelLayout = NiTexture::TextureFormatPreferences::PIX_DEFAULT;
    }
    unsigned char ucStatic;
    ReadTextureValue(stream, ucStatic);
    m_bStatic = ucStatic != 0;
    if (stream.version() >= 0x0a010067)
    {
        ReadTextureValue(stream, m_bLoadDirectToRendererHint);
    }
    if (stream.version() >= 0x14020004)
    {
        ReadTextureValue(stream, m_bSrcRendererDataIsPersistent);
    }
    ReleaseTextureObject(this);
}

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f444c;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char* pcText);
char* __cdecl NiGetViewerString_00a7d5e0(const char* pcPrefix, const char* pcText);

inline void StrArr::AppendReference(char*& element)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, element);
}

struct FUN_00a62a40_this
{
    void NiTexture_GetViewerStrings(StrArr* pkStrings);
};
struct FUN_00a60770_shell : FUN_00a62a40_this
{
    int unk00;
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
    const char* m_pcFileName;
    void GetFileStrings(StrArr* pkStrings);
};
// Calls FUN_00a62a40(pkStrings), then adds FUN_00a7d330 of the string at g_011f444c and a 'File:' string built from m_pcFileName to pkStrings.
// @fnv 0x00a60770
void FUN_00a60770_shell::GetFileStrings(StrArr* pkStrings)
{
    NiTexture_GetViewerStrings(pkStrings);
    char* pcString = NiViewerStrings_NiGetViewerString_Title(*(char**)&g_011f444c);
    pkStrings->AppendReference(pcString);
    const char* pcFile = m_pcFileName;
    pcString = NiGetViewerString_00a7d5e0("File:", pcFile);
    pkStrings->AppendReference(pcString);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

namespace A61F {



// Unit-local view of NiPointer for the code in namespace A61F: built on the shared NiPointer, that code does not compile or does not match.
class NiPointer_A61F
{
  public:
    NiRefObject* m_pObject;
    NiPointer_A61F() throw() : m_pObject(0)
    {}
};



}



extern "C" bool __cdecl fnv_NiStreamGetTexture(const char* pcName, A61F::NiPointer_A61F* apTextureOutput) throw();
bool __cdecl BSTexturePalette_RemoveTexture(const void* pvTexture) throw();

// If DAT_011f4468 is set, locks DAT_011f4480, looks up pcName via fnv_NiStreamGetTexture, and returns FUN_00a61f30 of the result if found, else false.
// @fnv 0x00a61fb0
// src: COMMUNITY 0x00a61fb0
bool __cdecl BSTexturePalette_RemoveTexture_0(const char* pcName)
{
    bool bResult = false;
    if (DAT_011f4468)
    {
        A61F::NiPointer_A61F spTexture;
        DAT_011f4480.Lock(0);
        bool bFound = fnv_NiStreamGetTexture(pcName, &spTexture);
        NiRefObject* pkTexture = spTexture.m_pObject;
        if (bFound)
            bResult = BSTexturePalette_RemoveTexture(pkTexture);
        DAT_011f4480.Unlock();
        if (pkTexture)
            pkTexture->DecRefCount();
    }
    return bResult;
}

// @fnv 0x00a63840
template <class TAlloc, class TKEY, class TVAL>
unsigned int NiTMapBase<TAlloc, TKEY, TVAL>::KeyToHashIndex(TKEY key) const
{
    return reinterpret_cast<unsigned int>(key) % m_uiHashSize;
}

// Conversion helpers use a 24-byte mask/shift/loss descriptor; NiPixelFormat stores 68 bytes of component specifications.
struct PackedPixelChannelLayout
{
    unsigned int m_auiMask[4];
    unsigned char m_aucShift[4];
    unsigned char m_aucBitsLoss[4];
};

// Converts each pixel from a packed source format to four 8-bit channels using the source PackedPixelChannelLayout masks, shifts and bits-loss values.
// @fnv 0x00a77590
void __cdecl ConvertPixelFormat(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride,
                                unsigned char* pucDest, unsigned int uiSrcStride, unsigned int uiSrcSize,
                                const unsigned char* pucSrc, const PackedPixelChannelLayout* pkSrcFmt)
{
    const unsigned int* puiSrc = (const unsigned int*)pucSrc;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            *pucDest++ = (unsigned char)((*puiSrc & pkSrcFmt->m_auiMask[0]) >> pkSrcFmt->m_aucShift[0])
                         << pkSrcFmt->m_aucBitsLoss[0];
            *pucDest++ = (unsigned char)((*puiSrc & pkSrcFmt->m_auiMask[1]) >> pkSrcFmt->m_aucShift[1])
                         << pkSrcFmt->m_aucBitsLoss[1];
            *pucDest++ = (unsigned char)((*puiSrc & pkSrcFmt->m_auiMask[2]) >> pkSrcFmt->m_aucShift[2])
                         << pkSrcFmt->m_aucBitsLoss[2];
            *pucDest++ = (unsigned char)((*puiSrc & pkSrcFmt->m_auiMask[3]) >> pkSrcFmt->m_aucShift[3])
                         << pkSrcFmt->m_aucBitsLoss[3];
            puiSrc++;
        }
    }
}

void __cdecl FUN_00a8a9a0();
// @fnv 0x00a7b7d0
// src: XBOX_PDB 0x00a7b7d0
void __cdecl NiPSysData_LinkObject()
{
    FUN_00a8a9a0();
}


// Adds src[i] * scale to dest[i] for each of the count NiPoint3 elements.
// @fnv 0x00a7ec90
void __cdecl AddScaledPoints(NiPoint3* dest, float scale, const NiPoint3* src, unsigned int count)
{
    LocalVec3* d = reinterpret_cast<LocalVec3*>(dest);
    const LocalVec3* s = reinterpret_cast<const LocalVec3*>(src);
    for (unsigned int i = 0; i < count; ++i)
    {
        d[i] += s[i] * scale;
    }
}

extern int DAT_0109b944;
extern int DAT_0109df8c;
struct FUN_00a7fb80_Class
{
    void* m_ppVirtualMethodTable;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    volatile int m_24;
    int m_28;
    int m_2C;
    int m_30;
    void* __thiscall FUN_00a5c200();
    void* __thiscall NiRenderedTexture_NiRenderedTexture();
};
struct Z2Setup
{
    void* __thiscall NiTexture_AddTextureToList();
};
// @fnv 0x00a7fb80
// src: GAMEBRYO_LIB 0x00a7fb80
void* FUN_00a7fb80_Class::NiRenderedTexture_NiRenderedTexture()
{
    FUN_00a5c200();
    m_ppVirtualMethodTable = &DAT_0109b944;
    m_18 = 6;
    m_1C = 3;
    m_20 = 2;
    m_24 = 0;
    ((Z2Setup*)this)->NiTexture_AddTextureToList();
    m_ppVirtualMethodTable = &DAT_0109df8c;
    m_30 = 0;
    return this;
}

struct Writer
{
    void* unk0;
    int m_offset;
    void* unk8;
    int(__cdecl* m_pfnWrite)(Writer* self, void* buf, int size, int* written, int flag);
    void WriteInt(int value)
    {
        int written = 4;
        m_offset += m_pfnWrite(this, &value, 4, &written, 1);
    }
};

struct Thing
{
    int unk00;
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
    int** m_ppData;
    short m_gap;
    unsigned short m_uiItemCount;
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
    Writer* m_pStreamWriter;
    void WriteData();
};

// @fnv 0x00a64010
void Thing::WriteData()
{
    m_pStreamWriter->WriteInt(m_uiItemCount - 1);
    for (unsigned int i = 1; i < m_uiItemCount; ++i)
    {
        m_pStreamWriter->WriteInt(*m_ppData[i]);
    }
}

#include <math.h>
namespace FrustumPlanes {


inline NiPoint3 multiplyVector(const NiPoint3& v, float scalar)
{
    return v * scalar;
}


struct Frustum
{
    float left, right, top, bottom, nearDistance, farDistance;
    bool orthographic;
};

struct Plane
{
    float x, y, z, d;
    Plane(const NiPoint3&, const NiPoint3&);
};

struct Planes
{
    Plane data[6];
    void SetFromFrustum(const Frustum*, const Transform*);
};

// Computes six frustum planes from a Frustum and Transform, using orthographic or perspective projection formulas.
// @fnv 0x00a74e10
void Planes::SetFromFrustum(const Frustum* apFrustum, const Transform* transform)
{

    NiPoint3 position;
    AssignPoint(position, reinterpret_cast<const NiPoint3&>(transform->position));

    NiPoint3 direction(transform->rotation.entries[0][0], transform->rotation.entries[1][0], transform->rotation.entries[2][0]);

    NiPoint3 up(transform->rotation.entries[0][1], transform->rotation.entries[1][1], transform->rotation.entries[2][1]);

    NiPoint3 right(transform->rotation.entries[0][2], transform->rotation.entries[1][2], transform->rotation.entries[2][2]);

    NiPoint3 point = position + multiplyVector(direction, apFrustum->nearDistance);

    data[0] = Plane(direction, point);

    AssignPoint(point, position + direction * apFrustum->farDistance);

    data[1] = Plane(-direction, point);

    if (apFrustum->orthographic)
    {

        float leftValue = apFrustum->left;
        AssignPoint(point, position + right * leftValue);
        data[2] = Plane(right, point);

        AssignPoint(point, position + right * apFrustum->right);
        data[3] = Plane(-right, point);

        AssignPoint(point, position + up * apFrustum->top);
        data[4] = Plane(-up, point);

        float bottomValue = apFrustum->bottom;
        AssignPoint(point, position + up * bottomValue);
        data[5] = Plane(up, point);
    }
    else
    {

        float inverse = 1.0f / (float)sqrt((float)(1.0 + (float)(apFrustum->left * apFrustum->left)));

        float coefficient = -apFrustum->left * inverse;
        NiPoint3 normal = direction * coefficient + right * inverse;
        data[2] = Plane(normal, position);

        inverse = 1.0f / (float)sqrt((float)(1.0 + (float)(apFrustum->right * apFrustum->right)));

        coefficient = apFrustum->right * inverse;
        float opposite = -inverse;
        AssignPoint(normal, direction * coefficient + right * opposite);
        data[3] = Plane(normal, position);

        inverse = 1.0f / (float)sqrt((float)(1.0 + (float)(apFrustum->top * apFrustum->top)));

        coefficient = inverse * apFrustum->top;
        opposite = -inverse;
        AssignPoint(normal, direction * coefficient + up * opposite);
        data[4] = Plane(normal, position);

        inverse = 1.0f / (float)sqrt((float)(1.0 + (float)(apFrustum->bottom * apFrustum->bottom)));

        coefficient = -apFrustum->bottom * inverse;
        AssignPoint(normal, direction * coefficient + up * inverse);
        data[5] = Plane(normal, position);
    }
}

}

// Converts a 32-bit RGBA pixel buffer to a packed format defined by layout, writing results to dest.
// @fnv 0x00a77040
void __cdecl ConvertRGBAToPacked(unsigned int width, unsigned int height, unsigned int unusedA, unsigned char* dest,
                                 const void* unusedB, const PackedPixelChannelLayout& layout, const unsigned char* src,
                                 const PackedPixelChannelLayout& unusedLayout)
{
    unsigned short* out = reinterpret_cast<unsigned short*>(dest);
    for (unsigned row = 0; row < height; ++row)
    {
        for (unsigned col = 0; col < width; ++col)
        {
            unsigned char red = *src++;
            unsigned char green = *src++;
            unsigned char blue = *src++;
            unsigned char alpha = *src++;
            *out = (unsigned short)((((unsigned long)red >> layout.m_aucBitsLoss[0]) << layout.m_aucShift[0] &
                                     layout.m_auiMask[0]) |
                                    (((unsigned long)green >> layout.m_aucBitsLoss[1]) << layout.m_aucShift[1] &
                                     layout.m_auiMask[1]) |
                                    (((unsigned long)blue >> layout.m_aucBitsLoss[2]) << layout.m_aucShift[2] &
                                     layout.m_auiMask[2]) |
                                    (((unsigned long)alpha >> layout.m_aucBitsLoss[3]) << layout.m_aucShift[3] &
                                     layout.m_auiMask[3]));
            ++out;
        }
    }
}

// Packs 4-byte RGBA source pixels into 32-bit values using format's bit loss, shift and mask per channel; sourceFormat is unused.
// @fnv 0x00a771d0
// src: GUESS 0x00a771d0 (confidence: high)
void __cdecl Runtime_PackRgbaPixelsByFormat(unsigned int width, unsigned int height, unsigned int destStride, unsigned int* dest,
                          unsigned int srcStride, const PackedPixelChannelLayout* format, const unsigned char* src,
                          const PackedPixelChannelLayout& sourceFormat)
{
    unsigned int* out = dest;
    for (unsigned int row = 0; row < height; ++row)
    {
        for (unsigned int col = 0; col < width; ++col)
        {
            unsigned char red = *src++;
            unsigned char green = *src++;
            unsigned char blue = *src++;
            unsigned char alpha = *src++;
            *out++ =
                (((unsigned long)red >> format->m_aucBitsLoss[0]) << format->m_aucShift[0] & format->m_auiMask[0]) |
                (((unsigned long)green >> format->m_aucBitsLoss[1]) << format->m_aucShift[1] & format->m_auiMask[1]) |
                (((unsigned long)blue >> format->m_aucBitsLoss[2]) << format->m_aucShift[2] & format->m_auiMask[2]) |
                (((unsigned long)alpha >> format->m_aucBitsLoss[3]) << format->m_aucShift[3] & format->m_auiMask[3]);
        }
    }
}

struct BitPackDesc
{
    unsigned short m_mask00;
    unsigned short unk02;
    unsigned short m_mask04;
    unsigned short unk06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned short m_mask0C;
    unsigned short unk0E;
    unsigned char m_shift10;
    unsigned char m_shift11;
    unsigned char unk12;
    unsigned char m_shift13;
    unsigned char m_shift14;
    unsigned char m_shift15;
    unsigned char unk16;
    unsigned char m_shift17;
};

// Packs rows x count pixels of 2 source bytes into 16-bit values via desc's shifts and masks, adding a constant third component.
// @fnv 0x00a77880
// src: GAMEBRYO_LIB 0x00a77880
void __cdecl NiDevImageConverter_ConvertBUMP16To16(unsigned int count, unsigned int rows, void* unusedA, unsigned short* dst, void* unusedB,
                          BitPackDesc* desc, const unsigned char* src, void* unusedC)
{
    unsigned short* d = dst;
    for (unsigned int y = 0; y < rows; y++)
    {
        for (unsigned int x = 0; x < count; x++)
        {
            unsigned char b0 = *src++;
            unsigned char b1 = *src++;
            unsigned short comp1 =
                (unsigned short)(((unsigned char)(b0 >> desc->m_shift14) << desc->m_shift10) & desc->m_mask00);
            unsigned short comp2 =
                (unsigned short)(((unsigned char)(b1 >> desc->m_shift15) << desc->m_shift11) & desc->m_mask04);
            unsigned short comp3 =
                (unsigned short)(((0xffffffffu >> desc->m_shift17) << desc->m_shift13) & desc->m_mask0C);
            *d++ = (unsigned short)(comp1 | comp2 | comp3);
        }
    }
}

struct MapEntry
{
    NiRefObject* m_pObject;
    unsigned int m_uiKey;
};

struct WeightedMapNode
{
    MapEntry* m_afEntries;
    WeightedMapNode* m_pNext;
};

class FUN_00a61a60_cls
{
  public:
    bool GetByKey(unsigned int index, unsigned int key, NiRefObject*& out);
};

// Walks the WeightedMapNode chain at the given index, finds the MapEntry whose m_uiKey matches, and swaps the out reference to it with refcount updates.
// @fnv 0x00a61a60
bool FUN_00a61a60_cls::GetByKey(unsigned int index, unsigned int key, NiRefObject*& out)
{
    WeightedMapNode* node = reinterpret_cast<WeightedMapNode**>(this)[index];
    bool result = false;
    if (node != 0)
    {
        do
        {
            if (key == node->m_afEntries->m_uiKey)
            {
                MapEntry* hit = node->m_afEntries;
                NiRefObject* old = out;
                if (old != hit->m_pObject)
                {
                    if (old != 0 && InterlockedDecrement((LONG*)&old->m_uiRefCount) == 0)
                        old->DeleteThis();
                    out = hit->m_pObject;
                    if (out != 0)
                        InterlockedIncrement((LONG*)&out->m_uiRefCount);
                }
                result = true;
                break;
            }
            node = node->m_pNext;
        } while (node != 0);
    }
    return result;
}



void* __cdecl _NiMalloc_00aa1070(unsigned int size);
void __cdecl FUN_00ec65a6(char* dst, unsigned int count, const char* src);

// @fnv 0x00a63980
template <>
void NiTStringTemplateMap<NiTPointerMap<const char*, unsigned short>, unsigned short>::SetValue(
    NiTMapItem<const char*, unsigned short>* dst, const char* src, unsigned short value)
{
    if (m_bCopy)
    {
        unsigned int size = strlen(src) + 1;
        dst->m_key = (char*)_NiMalloc_00aa1070(size);
        FUN_00ec65a6(const_cast<char*>(dst->m_key), size, src);
    }
    else
    {
        dst->m_key = src;
    }
    dst->m_val = value;
}

// Scalar deleting destructor: free the owned buffer, then release the object through the
// global memory manager when the delete flag is set (class-specific operator delete).
struct FUN_00a64470
{
    virtual ~FUN_00a64470();
    void* m_pData;
    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }
};

// @fnv 0x00a64470
FUN_00a64470::~FUN_00a64470()
{
    _NiFree(m_pData);
}

extern "C" void _ReadWriteBarrier(void);
struct S_00a6d290_Obj
{
    virtual void v00() throw();
    virtual void v04() throw();
    long refs;
};

struct S_00a6d290_Base
{
    long refs;
    virtual ~S_00a6d290_Base() throw();
};

struct FUN_00a6d290 : S_00a6d290_Base
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S_00a6d290_Obj* unk30;
    virtual ~FUN_00a6d290() throw();
};

// Destructor that releases the referenced object in unk30 by decrementing its refs and calling v04 when it reaches zero.
// @fnv 0x00a6d290
FUN_00a6d290::~FUN_00a6d290() throw()
{
    _ReadWriteBarrier();
    S_00a6d290_Obj* o = unk30;
    if (o)
    {
        if (!InterlockedDecrement(&o->refs))
            o->v04();
    }
}

struct PixelConvertFormat
{
    unsigned short m_mask0;
    unsigned short unk02;
    unsigned short m_mask1;
    unsigned short unk06;
    unsigned short m_mask2;
    unsigned short unk0a;
    unsigned short m_mask3;
    unsigned short unk0e;
    unsigned char m_shift0;
    unsigned char m_shift1;
    unsigned char m_shift2;
    unsigned char m_shift3;
    unsigned char m_shift4;
    unsigned char m_shift5;
    unsigned char m_shift6;
    unsigned char m_shift7;
};

// Converts a pixel buffer from a source format to 16-bit using per-channel shift and mask values from fmt, writing results to dst.
// @fnv 0x00a76ea0
void __cdecl ConvertPixelsTo16Bit(unsigned int width, unsigned int height, unsigned int unused03, unsigned short* dst,
                                  unsigned int unused05, const PixelConvertFormat* apFormat, const unsigned char* src,
                                  const PixelConvertFormat* unused8)
{
    unsigned short* destination = dst;
    if (height <= 0)
        return;

    unsigned int one = 1;

    for (unsigned int outer = height; outer != 0; --outer)
    {
        if (width <= 0)
            continue;

        for (height = width; height != 0; --height)
        {
            unsigned char b0 = *src++;
            unsigned char b1 = *src++;
            unsigned char b2 = *src++;

            unsigned short px =
                (unsigned short)(((0xffu >> apFormat->m_shift7) << apFormat->m_shift3) & apFormat->m_mask3);
            px |= (unsigned short)((((unsigned short)(b0 >> apFormat->m_shift4)) << apFormat->m_shift0) &
                                   apFormat->m_mask0);
            px |= (unsigned short)((((unsigned short)(b2 >> apFormat->m_shift6)) << apFormat->m_shift2) &
                                   apFormat->m_mask2);
            px |= (unsigned short)((((unsigned short)(b1 >> apFormat->m_shift5)) << apFormat->m_shift1) &
                                   apFormat->m_mask1);

            *destination++ = px;
        }
    }
}

// Converts a packed RGB source buffer to a destination pixel format using per-channel shift, loss and mask values from pkSrcFmt.
// @fnv 0x00a76f80
void __cdecl ConvertRGBToFormat(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestStride,
                                unsigned int* puiDest, unsigned int uiSrcStride, const PackedPixelChannelLayout* pkSrcFmt,
                                const unsigned char* pucSrc, unsigned int uiUnused8)
{
    unsigned int* pDest = puiDest;
    if (uiHeight <= 0)
        return;

    unsigned int h = uiHeight;
    do
    {
        if (uiWidth > 0)
        {
            unsigned int w = uiWidth;
            do
            {
                unsigned char b0 = *pucSrc++;
                unsigned char b1 = *pucSrc++;
                unsigned char b2 = *pucSrc++;

                unsigned int c0 = ((unsigned int)b0 >> pkSrcFmt->m_aucBitsLoss[0]) << pkSrcFmt->m_aucShift[0];
                c0 &= pkSrcFmt->m_auiMask[0];

                unsigned int c1 = ((unsigned int)b1 >> pkSrcFmt->m_aucBitsLoss[1]) << pkSrcFmt->m_aucShift[1];
                c1 &= pkSrcFmt->m_auiMask[1];

                unsigned int c2 = ((unsigned int)b2 >> pkSrcFmt->m_aucBitsLoss[2]) << pkSrcFmt->m_aucShift[2];
                c2 &= pkSrcFmt->m_auiMask[2];

                unsigned int c3 = ((unsigned int)0xff >> pkSrcFmt->m_aucBitsLoss[3]) << pkSrcFmt->m_aucShift[3];
                c3 &= pkSrcFmt->m_auiMask[3];

                *pDest++ = c0 | c1 | c2 | c3;
                --w;
            } while (w != 0);
        }
        --h;
    } while (h != 0);
}

struct PixelChannels
{
    unsigned int redMask;
    unsigned int greenMask;
    unsigned int blueMask;
    unsigned int alphaMask;
    unsigned char redRightShift;
    unsigned char greenRightShift;
    unsigned char blueRightShift;
    unsigned char alphaRightShift;
    unsigned char redLeftShift;
    unsigned char greenLeftShift;
    unsigned char blueLeftShift;
    unsigned char alphaLeftShift;
};

// Converts a packed pixel buffer to RGBA bytes using the channel masks and shifts from channels, writing 0xFF for alpha.
// @fnv 0x00a77630
void __cdecl ConvertPackedPixelsToRGBA(unsigned int width, unsigned int height, unsigned int sourcePitch, char* output,
                                       unsigned int outputPitch, unsigned int unused, const unsigned int* source,
                                       const PixelChannels* channels)
{
    const unsigned int* pixel = source;
    if (height > 0)
    {
        unsigned int rowsRemaining = height;
        do
        {
            if (width > 0)
            {
                unsigned int pixelsRemaining = width;
                do
                {
                    *output++ = (char)((pixel[0] & channels->redMask) >> channels->redRightShift)
                                << channels->redLeftShift;
                    *output++ = (char)((pixel[0] & channels->greenMask) >> channels->greenRightShift)
                                << channels->greenLeftShift;
                    *output++ = (char)((pixel[0] & channels->blueMask) >> channels->blueRightShift)
                                << channels->blueLeftShift;
                    *output++ = -1;
                    ++pixel;
                } while (--pixelsRemaining != 0);
            }
        } while (--rowsRemaining != 0);
    }
}

static __declspec(noinline) int CompareValues(const float* a, const float* b, unsigned count)
{
    for (unsigned i = 0; i < count; ++i)
    {
        if (a[i] < b[i])
            return -1;
        if (a[i] > b[i])
            return 1;
    }
    return 0;
}
struct PivotGeometry
{
    struct LastIndex
    {
        int value;
    };
    int unk00, unk04;
    unsigned short vertexCount, unk0a, format, unk0e;
    int unk10, unk14, unk18, unk1c;
    float* positions;
    float* normals;
    float* colors;
    float* texcoords;
    __declspec(noinline) int CompareVertices(unsigned short a, unsigned short b, unsigned char ctx);
    int MedianOfThree(unsigned short* arr, unsigned char ctx, int lo, int hi);
};
__declspec(noinline) int PivotGeometry::CompareVertices(unsigned short a, unsigned short b, unsigned char ctx)
{
    int result;
    if (ctx & 1)
    {
        result = CompareValues(positions + 3 * a, positions + 3 * b, 3);
        if (result)
            return result;
    }
    if (normals && (ctx & 2))
    {
        result = CompareValues(normals + 3 * a, normals + 3 * b, 3);
        if (result)
            return result;
    }
    if (colors && (ctx & 4))
    {
        result = CompareValues(colors + 4 * a, colors + 4 * b, 4);
        if (result)
            return result;
    }
    if (texcoords && (ctx & 8))
    {
        for (unsigned short set = 0; set < (format & 1); ++set)
        {
            result = CompareValues(texcoords + 2 * (a + set * vertexCount), texcoords + 2 * (b + set * vertexCount), 2);
            if (result)
                return result;
        }
    }
    return 0;
}

// Returns the median vertex index of arr[lo], arr[mid], arr[hi] by comparing them with CompareVertices under the given ctx flags.
// @fnv 0x00a672b0
int PivotGeometry::MedianOfThree(unsigned short* apIndices, unsigned char ctx, int lo, int hi)
{
    int mid = (lo + hi) >> 1;
    if (CompareVertices(apIndices[lo], apIndices[mid], ctx) < 0)
    {
        if (CompareVertices(apIndices[mid], apIndices[hi], ctx) < 0)
            return apIndices[mid];
        if (CompareVertices(apIndices[lo], apIndices[hi], ctx) < 0)
            return apIndices[hi];
        return apIndices[lo];
    }
    if (CompareVertices(apIndices[lo], apIndices[hi], ctx) < 0)
        return apIndices[lo];
    if (CompareVertices(apIndices[mid], apIndices[hi], ctx) < 0)
        return apIndices[hi];
    return apIndices[mid];
}
