#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiCollisionData.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/NiBoundingVolume.h"
#include "../../../../include/NiCollisionObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiPoint3.h"

// Read the serialized file version at its fixed stream offset.
inline unsigned int GetFileVersion(const NiStream& stream)
{
    return *reinterpret_cast<const unsigned int*>((const char*)&stream + 0xD8);
}

inline unsigned int StrArr::AddInline(char* pcElement)
{
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, pcElement);
    return uiIndex;
}

// src/gamebryo2.2/corelibs/nicollision/nicollisiondata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nicollisiondata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void* g_0126fab4;

// @fnv 0x00eacd20
// src: COMMUNITY 0x00eacd20
void* __cdecl NiCollisionData_GetRTTI()
{
    return &g_0126fab4;
}

extern "C" void* __cdecl _NiMalloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
int __cdecl NiSprintf(char*, unsigned int, const char*, ...);

// Allocates a string sized from pcPrefix and formats it as "<pcPrefix> = <mode name>" based on eMode, returning the buffer.
// @fnv 0x00eacef0
// src: XBOX_PDB 0x00eacef0
char* __stdcall NiCollisionData_GetViewerString(const char* pcPrefix, unsigned int eMode)
{
    char* pString;
    unsigned int uiBufferSize;

    uiBufferSize = strlen(pcPrefix) + 0x11;
    pString = (char*)_NiMalloc(uiBufferSize);
    switch (eMode)
    {
    case 0:
        NiSprintf(pString, uiBufferSize, "%s = USE_OBB", pcPrefix);
        break;
    case 1:
        NiSprintf(pString, uiBufferSize, "%s = USE_TRI", pcPrefix);
        break;
    case 2:
        NiSprintf(pString, uiBufferSize, "%s = USE_ABV", pcPrefix);
        break;
    case 3:
        NiSprintf(pString, uiBufferSize, "%s = NOTEST", pcPrefix);
        break;
    case 4:
        NiSprintf(pString, uiBufferSize, "%s = USE_NIBOUND", pcPrefix);
        break;
    default:
        NiSprintf(pString, uiBufferSize, "%s = UNKNOWN!!!", pcPrefix);
        break;
    }
    return pString;
}

extern "C" void* _NiPoint3_ZERO;
extern unsigned char DAT_011f4270;
extern unsigned char DAT_011f4274;

// @fnv 0x00eacd30
// src: XBOX_PDB 0x00eacd30
NiPoint3 NiCollisionData::GetVelocity()
{
    NiPoint3 p;
    *(unsigned int*)&p.x = *(unsigned int*)&_NiPoint3_ZERO;
    *(unsigned int*)&p.y = *(unsigned int*)&DAT_011f4270;
    *(unsigned int*)&p.z = *(unsigned int*)&DAT_011f4274;
    return p;
}

// @fnv 0x00eace50
void NiCollisionData::SetBoundingVolume(NiBoundingVolume* pkBV)
{
    if (m_pkModelABV)
        delete m_pkModelABV;
    if (unk30)
        delete unk30;
    m_pkModelABV = pkBV;
    if (pkBV)
    {
        unk30 = pkBV->v6();
        if (m_pkSceneObject)
            unk30->v5(m_pkModelABV, &m_pkSceneObject->m_kWorld);
    }
    else
    {
        unk30 = 0;
    }
}

extern void* __cdecl NiBoundingVolume_CreateFromStream(void*);

// @fnv 0x00eaceb0
void __fastcall AssignFromSource(NiCollisionData* self, void*, void* pSource)
{
    self->SetSceneObject(*(NiAVObject**)pSource);
    self->m_ePropagationMode = *(int*)((char*)pSource + 4);
    if (*(int*)((char*)pSource + 8))
    {
        void* bv = NiBoundingVolume_CreateFromStream(*(void**)((char*)pSource + 12));
        self->SetBoundingVolume((NiBoundingVolume*)bv);
    }
}

void __cdecl _delete(void*, unsigned int);
// Calls FUN_00eacde0, then deletes this with size 0x50 when bit 0 of uFlags is set, and returns this.
// @fnv 0x00ead0b0
void* NiCollisionData::DestroyIfFlagged(unsigned int auiFlags)
{
    UpdateFields_00eacde0();
    if (auiFlags & 1)
        _delete(this, 0x50);
    return this;
}

// @fnv 0x00ead610
void NiCollisionData::CloneCollisionData(NiCollisionData* pkDest, CloningProcess& kCloning)
{
    NiCollisionObject_CopyMembers(pkDest, kCloning);
    pkDest->m_ePropagationMode = m_ePropagationMode;
    pkDest->m_eCollisionMode = m_eCollisionMode;
    if (m_pkModelABV)
        pkDest->SetBoundingVolume(m_pkModelABV->Clone());
    if (m_pCollisionObject)
    {
        if (!pkDest->m_pWorldVertices)
        {
            pkDest->CreateWorldVertices();
            pkDest->UpdateWorldVertices();
        }
        pkDest->CreateTriData(1);
    }
}

struct Helper38
{
    char _pad[0x38];
    unsigned char m_uiObjectFlags;
};

// @fnv 0x00ead330
// src: XBOX_PDB 0x00ead330
void NiCollisionData::SetSceneGraphObject(NiAVObject* pkSceneObject)
{
    NiCollisionObject::SetSceneObject(pkSceneObject);
    int iMode = m_eCollisionMode;
    NiAVObject* pkObj = m_pkSceneObject;
    if (!pkObj)
        return;
    if (!pkObj->IsGeometry())
        return;
    Helper38* pkHelper = *reinterpret_cast<Helper38**>((char*)pkObj + 0xB8);
    if (!pkHelper)
        return;
    if (iMode == 0 || iMode == 1)
        pkHelper->m_uiObjectFlags |= 0x33;
}

struct TargetObj
{
    unsigned char _pad[0x38];
    unsigned char m_ucFlag;
};

// Stream boundary declarations use opaque arguments until NiStream has one
// approved tag kind; the bodies use the shared stream and collision layouts.
void __cdecl LinkCollisionObject();

// @fnv 0x00ead760
void __fastcall LinkCollisionData(NiCollisionData* self, void*, void* stream)
{
    NiStream& kStream = *(NiStream*)stream;
    ((void (__thiscall*)(NiCollisionData*, void*))LinkCollisionObject)(self, stream);
    if (GetFileVersion(kStream) < 0x0A000110)
    {
        int iMode = self->m_eCollisionMode;
        NiAVObject* pkScene = self->m_pkSceneObject;
        if (pkScene)
        {
            if (pkScene->IsGeometry())
            {
                TargetObj* pkTarget = *reinterpret_cast<TargetObj**>((char*)pkScene + 0xB8);
                if (pkTarget)
                {
                    if (iMode == 0 || iMode == 1)
                        pkTarget->m_ucFlag |= 0x33;
                }
            }
        }
    }
}

char* __cdecl _FUN_00a7d330(const char*);

// @fnv 0x00ead870
// src: XBOX_PDB 0x00ead870
void NiCollisionData::GetViewerStrings_00ead870(StrArr* pkStrings)
{
    FUN_00a81100(pkStrings);
    char* pszDup = _FUN_00a7d330((const char*)g_0126fab4);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMax = pkStrings->m_usMaxSize;
    if (uiSize >= uiMax)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pszDup);
    AddViewerStrings((NiViewerStringsArray*)pkStrings);
}

// FUN_00eacd00 - forwards its single argument to the collection's stream
// writer and reports the writer's byte sized result as a bool.
//
// Original body (18 bytes):
//   mov eax, dword ptr [esp + 4]
//   push eax
//   call  <stream writer>
//   test al, al
//   setne al
//   ret 4
//
// The writer is the collection's "write to stream" helper; it is declared
// here with a byte sized result because the original only looks at AL.

extern "C" unsigned char __stdcall MyColl_WriteToStream(void* pStream);

// @fnv 0x00eacd00
// src: XBOX_PDB 0x00eacd00
bool __stdcall NiCollisionData_RegisterStreamables(void* pStream)
{
    return MyColl_WriteToStream(pStream);
}

extern unsigned char DAT_010f18bc;
extern unsigned int DAT_011f426c;

inline void* __cdecl operator new(unsigned int, void* memory) { return memory; }

// Initialize the base, zero collision buffers and copy the default velocities.
// @fnv 0x00eacd60
NiCollisionData::NiCollisionData() : NiCollisionObject((void*)0)
{
    m_pWorldVertices = 0;
    unk44 = 0;
    unk48 = 0;
    unk49 = 0;
    *(unsigned int*)&m_kLocalVelocity.x = DAT_011f426c;
    *(unsigned int*)&m_kLocalVelocity.y = *(unsigned int*)&DAT_011f4270;
    *(unsigned int*)&m_kLocalVelocity.z = *(unsigned int*)&DAT_011f4274;
    *(unsigned int*)&m_kWorldVelocity.x = DAT_011f426c;
    *(unsigned int*)&m_kWorldVelocity.y = *(unsigned int*)&DAT_011f4270;
    *(unsigned int*)&m_kWorldVelocity.z = *(unsigned int*)&DAT_011f4274;
    unk4C = 0;
    m_pkModelABV = 0;
    unk30 = 0;
    m_pCollisionObject = 0;
    unk38 = 0;
    unk3C = 0;
    unk4E = 0;
    m_ePropagationMode = 2;
    m_eCollisionMode = 3;

}

extern unsigned char DAT_010f18bc;
extern unsigned char DAT_011f6238;

struct FUN_00aa4060_shell
{
    void __thiscall MemoryManager_Deallocate(unsigned int);
};

void __fastcall DestroyCollisionObject(NiCollisionObject*);

struct SpawnedObj
{
    virtual void v00(int);
    virtual void v04(int);
    virtual void v08(int);
};

// @fnv 0x00eacde0
// src: GUESS 0x00eacde0 (confidence: low)
void NiCollisionData::UpdateFields_00eacde0()
{
    unsigned int a = (unsigned int)m_pWorldVertices;
    *(void**)this = &DAT_010f18bc;
    ((FUN_00aa4060_shell*)&DAT_011f6238)->MemoryManager_Deallocate(a);
    ((FUN_00aa4060_shell*)&DAT_011f6238)->MemoryManager_Deallocate((unsigned int)unk44);
    if (m_pkModelABV != 0)
    {
        delete m_pkModelABV;
    }
    if (unk30 != 0)
    {
        delete unk30;
    }
    if (m_pCollisionObject != 0)
    {
        ((SpawnedObj*)m_pCollisionObject)->v00(1);
    }
    m_pCollisionObject = 0;
    DestroyCollisionObject((NiCollisionObject*)this);
}

extern void(__cdecl* g_011aa050)(unsigned short, unsigned int, void*, void*);

struct S_00ead250_Second
{
    virtual void m00()
    {}
    virtual void m04()
    {}
    virtual void m08()
    {}
    virtual void m0c()
    {}
    virtual void m10()
    {}
    virtual void m14()
    {}
    virtual void m18()
    {}
    virtual void m1c()
    {}
    virtual void m20()
    {}
    virtual void m24()
    {}
    virtual void m28()
    {}
    virtual void m2c()
    {}
    virtual void m30()
    {}
    virtual void m34()
    {}
    virtual void m38()
    {}
    virtual void m3c()
    {}
    virtual void m40()
    {}
    virtual void m44()
    {}
    virtual void m48()
    {}
    virtual void m4c()
    {}
    virtual void m50()
    {}
    virtual void m54()
    {}
    virtual void m58()
    {}
    virtual void m5c()
    {}
    virtual void m60()
    {}
    virtual void m64()
    {}
    virtual void m68()
    {}
    virtual void m6c()
    {}
    virtual void m70()
    {}
    virtual void m74()
    {}
    virtual void m78()
    {}
    virtual void m7c()
    {}
    virtual void m80()
    {}
    virtual void m84()
    {}
    virtual void m88()
    {}
    virtual void m8c()
    {}
    virtual unsigned short m90()
    {
        return 0;
    }

    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    unsigned int unk20;
};

// If unk08's m18() result is non-null and m_pWorldVertices and unk48 are set, calls g_011aa050 with the second object's unk20 and m90() and clears unk48.
// @fnv 0x00ead250
// src: XBOX_PDB 0x00ead250
void NiCollisionData::UpdateWorldVertices()
{
    NiAVObject* first = m_pkSceneObject;

    if (first != 0)
    {
        NiAVObject* object = (NiAVObject*)first->IsGeometry();

        if (object != 0 && m_pWorldVertices != 0 && unk48 != 0)
        {
            S_00ead250_Second* second = *reinterpret_cast<S_00ead250_Second**>((char*)object + 0xB8);
            unsigned int value20 = second->unk20;
            unsigned short value90 = second->m90();

            g_011aa050(value90, value20, m_pWorldVertices, (void*)((char*)object + 0x68));

            unk48 = 0;
        }
    }
}

struct FUN_00ead2b0_node
{
    void* vft;
    FUN_00ead2b0_node* m_04;
};

// These base implementations are absent from the shared NiCollisionObject
// declaration. Call them with their original thiscall ABI without a proxy class.
bool __cdecl CollisionObjectIsEqual();

// Checks Probe(other), a node list for g_0126fab4, equal m_28/m_24, and equal m_2c unk0c values; returns true on match, false otherwise.
// @fnv 0x00ead2b0
bool NiCollisionData::IsEqual(NiObject* pkOther) const
{
    NiCollisionData* other = (NiCollisionData*)pkOther;
    FUN_00ead2b0_node* node;
    NiBoundingVolume* a;
    NiBoundingVolume* b;
    if (!((bool (__thiscall*)(const NiCollisionData*, NiObject*))CollisionObjectIsEqual)(this, other))
    {
        goto fail;
    }
    if (other == 0)
    {
        goto fail;
    }
    node = (FUN_00ead2b0_node*)other->GetRTTI();
    if (node == 0)
    {
        goto fail;
    }
    do
    {
        if (node == (FUN_00ead2b0_node*)&g_0126fab4)
        {
            goto found;
        }
        node = node->m_04;
    } while (node != 0);
    goto fail;
found:
    if (other->m_eCollisionMode != m_eCollisionMode)
    {
        goto fail;
    }
    if (other->m_ePropagationMode != m_ePropagationMode)
    {
        goto fail;
    }
    a = other->m_pkModelABV;
    if (a == 0)
    {
        goto tail;
    }
    b = m_pkModelABV;
    if (b != 0)
    {
        int ra = a->F3();
        int rb = b->F3();
        if (ra == rb)
        {
            goto ok;
        }
        goto fail;
    }
tail:
    if (a != m_pkModelABV)
    {
        goto fail;
    }
ok:
    return true;
fail:
    return false;
}

extern NiRTTI g_NiTriShapeRTTI;
extern NiRTTI g_NiTriStripsRTTI;

extern MemoryManager _g_memoryManager;

void* __cdecl NiMalloc(unsigned int size);

inline void NiFreeHelper(void* p)
{
    _g_memoryManager.Deallocate(p);
}

struct GeomData
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void GetTriangleVertexIndices(unsigned int i, unsigned short& i0, unsigned short& i1,
                                          unsigned short& i2) const;

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void* m_pkVertex;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    unsigned short m_usTriangles;

    unsigned short* GetTriListImpl();
    unsigned short* GetTriangleList()
    {
        return GetTriListImpl();
    }
    void* GetVertices() const
    {
        return m_pkVertex;
    }
    unsigned short GetTriangleCount() const
    {
        return m_usTriangles;
    }
};

struct GeomObj : NiObject
{
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
    int m_pWorldVertices;
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
    GeomData* m_spGeometryData;
    GeomData* GetModelData() const
    {
        return m_spGeometryData;
    }
    void* GetVertices() const
    {
        return m_spGeometryData->GetVertices();
    }
};

struct TriData
{
    TriData(unsigned short usTriangles, unsigned short* pusTriList, void* pkVertex, void* pkWorldVertex, int iParam);
    static void* operator new(unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    static void operator delete(void* p, const char* pcFile);
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
    int m_pWorldVertices;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
};

inline bool IsKindOfHelper(const NiRTTI& rtti, NiObject* obj)
{
    if (obj)
    {
        for (const NiRTTI* r = obj->GetRTTI(); r; r = r->m_pBaseRTTI)
        {
            if (r == &rtti)
                return true;
        }
    }
    return false;
}

// Builds m_pCollisionObject from the scene object's triangle or triangle-strip geometry, creating world normals first if needed.
// @fnv 0x00ead380
void NiCollisionData::CreateTriData(int iParam)
{
    if (m_pkSceneObject && IsKindOfHelper(g_NiTriShapeRTTI, (NiObject*)m_pkSceneObject))
    {
        if (m_pCollisionObject)
            return;
        if (!m_pWorldVertices)
        {
            CreateWorldVertices();
            UpdateWorldVertices();
        }
        GeomObj* pkShape = (GeomObj*)m_pkSceneObject;
        m_pCollisionObject =
            new TriData(pkShape->m_spGeometryData->GetTriangleCount(), pkShape->m_spGeometryData->GetTriangleList(),
                        pkShape->m_spGeometryData->GetVertices(), m_pWorldVertices, iParam);
    }
    else if (m_pkSceneObject && IsKindOfHelper(g_NiTriStripsRTTI, (NiObject*)m_pkSceneObject))
    {
        if (m_pCollisionObject)
            return;
        if (!m_pWorldVertices)
        {
            CreateWorldVertices();
            UpdateWorldVertices();
        }
        GeomObj* pkStrips = (GeomObj*)m_pkSceneObject;
        unsigned int uiTriangleCount = 0;
        unsigned int uiTriangles = pkStrips->m_spGeometryData->m_usTriangles;
        unsigned short* pusTriList = (unsigned short*)NiMalloc(uiTriangles * 3 * sizeof(unsigned short));
        unsigned short* p = pusTriList;
        for (unsigned int i = 0; i < uiTriangles; i++)
        {
            pkStrips->m_spGeometryData->GetTriangleVertexIndices(i, p[0], p[1], p[2]);
            if (p[0] != p[1] && p[0] != p[2] && p[1] != p[2])
            {
                p += 3;
                uiTriangleCount++;
            }
        }
        m_pCollisionObject = new TriData(uiTriangleCount, pusTriList, pkStrips->m_spGeometryData->GetVertices(),
                                  m_pWorldVertices, iParam);
        NiFreeHelper(pusTriList);
    }
}

struct FNV_CollideFlags
{
    int unk00;
    int unk04;
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
    int unk30;
    int unk34;
    unsigned char m_38;
};

__forceinline void CollisionModeThen(NiCollisionData* self)
{
    NiAVObject* obj = self->m_pkSceneObject;
    if (obj)
        obj->IsGeometry();
}

__forceinline void CollisionModeElse(NiCollisionData* self)
{
    NiAVObject* obj = self->m_pkSceneObject;
    self->m_eCollisionMode = 0;
    if (obj)
    {
        if (obj->IsGeometry())
        {
            FNV_CollideFlags* flags = *reinterpret_cast<FNV_CollideFlags**>((char*)obj + 0xB8);
            if (flags)
                flags->m_38 |= 0x33;
        }
    }
}

// @fnv 0x00ead550
void __fastcall UpdateCollideState(NiCollisionData* self, void*, unsigned int arg, unsigned int arg2)
{
    (void)arg2;
    if (arg >= 0x0a000106u)
        return;
    switch (self->m_ePropagationMode)
    {
    case 0:
        self->m_ePropagationMode = 3;
        if (self->m_pkModelABV != 0)
        {
            self->m_eCollisionMode = 2;
            CollisionModeThen(self);
        }
        else
        {
            CollisionModeElse(self);
        }
        break;
    case 1:
        self->m_ePropagationMode = 3;
        break;
    case 2:
        self->m_ePropagationMode = 0;
        if (self->m_pkModelABV != 0)
        {
            self->m_eCollisionMode = 2;
            CollisionModeThen(self);
        }
        else
        {
            CollisionModeElse(self);
        }
        break;
    case 3:
        self->m_ePropagationMode = 2;
        if (self->m_pkModelABV != 0)
        {
            self->m_eCollisionMode = 2;
            CollisionModeThen(self);
        }
        else
        {
            CollisionModeElse(self);
        }
        break;
    case 4:
        self->m_ePropagationMode = 2;
        break;
    }
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesRead;
    return uiBytesRead;
}

template <class T> inline void NiBinaryStream::Read(T& value)
{
    unsigned int uiSize = sizeof(T);
    BinaryRead(&value, sizeof(T), &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.m_pkIstr->Read(value);
}

template <class T> inline T ReadBinaryScalar(NiBinaryStream& stream)
{
    T v;
    unsigned int uiSize = sizeof(T);
    unsigned int n = stream.m_pfnRead(&stream, &v, sizeof(T), &uiSize, 1);
    T r = v;
    stream.m_uiAbsoluteCurrentPos += n;
    return r;
}

template <class T> inline T LoadValue(NiStream& stream)
{
    return ReadBinaryScalar<T>(*stream.m_pkIstr);
}

NiBoundingVolume* __cdecl LoadBoundingVolume(void* stream);
void __cdecl LoadCollisionObject();

// Reads two ints (or one for older file versions), a bool, and if set loads an object and stores its v06() result.
// @fnv 0x00ead670
void __fastcall LoadCollisionData(NiCollisionData* self, void*, void* source)
{
    NiStream& stream = *(NiStream*)source;
    ((void (__thiscall*)(NiCollisionData*, void*))LoadCollisionObject)(self, source);
    if (GetFileVersion(stream) >= 0x0A000106)
    {
        self->m_ePropagationMode = LoadValue<int>(stream);
        self->m_eCollisionMode = LoadValue<int>(stream);
    }
    else
    {
        self->m_ePropagationMode = LoadValue<int>(stream);
    }
    bool bHasObject;
    ReadBinaryValue(stream, bHasObject);
    if (bHasObject)
    {
        self->m_pkModelABV = LoadBoundingVolume(source);
        self->unk30 = self->m_pkModelABV->v6();
    }
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* sizes,
                                                unsigned int count)
{
    unsigned int written = m_pfnWrite(this, p, n, sizes, count);
    m_uiAbsoluteCurrentPos += written;
    return written;
}

template <class T>
inline void SaveBinaryValue(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void SaveBinaryValue(NiStream& kStream, const T& value)
{
    SaveBinaryValue(*kStream.m_pkOstr, &value);
}

void __cdecl SaveCollisionObject();

// Saves the base fields, m_ePropagationMode and m_eCollisionMode, then a presence flag and the child's SaveBinary if m_pkModelABV is set.
// @fnv 0x00ead7b0
void __fastcall SaveCollisionData(NiCollisionData* self, void*, void* target)
{
    NiStream& kStream = *(NiStream*)target;
    ((void (__thiscall*)(NiCollisionData*, void*))SaveCollisionObject)(self, target);
    SaveBinaryValue(kStream, self->m_ePropagationMode);
    SaveBinaryValue(kStream, self->m_eCollisionMode);
    if (self->m_pkModelABV)
    {
        SaveBinaryValue(kStream, true);
        self->m_pkModelABV->SaveBinary(kStream);
    }
    else
    {
        SaveBinaryValue(kStream, false);
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int);

// @fnv 0x00eada20
NiObject* NiCollisionData::MakeClone(CloningProcess& arg)
{
    NiCollisionData* result;
    void* mem = Object_DispatchCommandFour(0x50);
    if (mem != 0)
    {
        result = ::new (mem) NiCollisionData();
    }
    else
    {
        result = 0;
    }
    CloneCollisionData(result, arg);
    return result;
}

extern unsigned char DAT_0126fab0;

__forceinline NiPoint3 AddVelocity(const NiPoint3& kA, const NiPoint3& kB)
{
    NiPoint3 kResult;
    kResult.x = kA.x + kB.x;
    kResult.y = kA.y + kB.y;
    kResult.z = kA.z + kB.z;
    return kResult;
}

__declspec(noinline) NiAVObject* __stdcall FindCollisionParent(NiAVObject* pkNode)
{
    if (pkNode == 0)
        return 0;
    do
    {
        pkNode = (NiAVObject*)pkNode->m_pkParent;
        if (pkNode == 0)
            return 0;
    } while (pkNode->m_spCollisionObject.m_pObject == 0);
    return pkNode;
}

// @fnv 0x00ead0f0
void NiCollisionData::Unk_24(NiUpdateData& arData)
{
    if (m_pkModelABV)
    {
        unk30->v5(m_pkModelABV, &m_pkSceneObject->m_kWorld);
    }
    if (DAT_0126fab0)
    {
        NiAVObject* pkParent = (NiAVObject*)m_pkSceneObject->m_pkParent;
        if (pkParent)
        {
            NiCollisionData* pkData = 0;
            if (m_pkSceneObject)
            {
                NiAVObject* pkNode = (NiAVObject*)m_pkSceneObject->m_pkParent;
                if (pkNode)
                {
                    if (pkNode->m_spCollisionObject.m_pObject == 0)
                        pkNode = ((NiAVObject* (__thiscall*)(NiCollisionData*, NiAVObject*))FindCollisionParent)(this, pkNode);
                    if (pkNode)
                        pkData = (NiCollisionData*)pkNode->m_spCollisionObject.m_pObject;
                }
            }
            if (pkData)
            {
                m_kWorldVelocity =
                    AddVelocity(pkData->m_kWorldVelocity, pkParent->m_kWorld.FUN_004b4500(&m_kLocalVelocity));
            }
            else
            {
                m_kWorldVelocity = pkParent->m_kWorld.FUN_004b4500(&m_kLocalVelocity);
            }
        }
        else
        {
            m_kWorldVelocity = m_kLocalVelocity;
        }
    }
    unk49 = unk48 = true;
}

char* NiViewerStrings_NiGetViewerString_Title(char* pcText);
char* __stdcall FormatName(const char* name, int mode);

void __cdecl AddCollisionObjectViewerStrings();

// Appends viewer strings for propagation/collision modes, the ABV model and local/world velocities to pkStrings.
// @fnv 0x00ead8d0
void NiCollisionData::AddViewerStrings(NiViewerStringsArray* strings)
{
    StrArr* pkStrings = (StrArr*)strings;
    ((void (__thiscall*)(NiCollisionData*, StrArr*))AddCollisionObjectViewerStrings)(this, pkStrings);
    pkStrings->AddInline(NiViewerStrings_NiGetViewerString_Title((char*)g_0126fab4));
    // The original callers also supply the collision owner in ECX to these
    // stateless formatters; preserve that calling convention.
    unsigned int propagationMode = m_ePropagationMode;
    pkStrings->AddInline(((char* (__thiscall*)(NiCollisionData*, const char*, unsigned int))FormatName)(this, "m_ePropagationMode", propagationMode));
    unsigned int collisionMode = m_eCollisionMode;
    pkStrings->AddInline(((char* (__thiscall*)(NiCollisionData*, const char*, unsigned int))NiCollisionData_GetViewerString)(this, "m_eCollisionMode", collisionMode));
    if (m_pkModelABV)
        m_pkModelABV->AddViewerStrings("m_pkModelABV->Type", (NiTPrimitiveArray<char*>*)pkStrings);
    pkStrings->AddInline(m_kLocalVelocity.GetViewerString_00a59af0("m_kLocalVelocity"));
    pkStrings->AddInline(m_kWorldVelocity.GetViewerString_00a59af0("m_kWorldVelocity"));
}

extern const char str_010f19fc[];
extern const char str_010f19e0[];
extern const char str_010f19c8[];
extern const char str_010f19b0[];
extern const char str_0109b2ec[];

extern "C" unsigned int __cdecl strlen(const char*);
void* __cdecl _NiMalloc_00aa1070(unsigned int size);
void FUN_00a305b0(char* buf, unsigned int size, const char* fmt, const char* name);

// Obtains a buffer sized from name length and formats name into it using the mode-selected format string.
// @fnv 0x00eacfd0
char* __stdcall FormatName(const char* name, int mode)
{
    unsigned int len = strlen(name);
    char* buf = (char*)_NiMalloc_00aa1070(len + 0x20);
    switch (mode)
    {
    case 0:
        FUN_00a305b0(buf, len + 0x20, str_010f19fc, name);
        break;
    case 1:
        FUN_00a305b0(buf, len + 0x20, str_010f19e0, name);
        break;
    case 2:
        FUN_00a305b0(buf, len + 0x20, str_010f19c8, name);
        break;
    case 3:
        FUN_00a305b0(buf, len + 0x20, str_010f19b0, name);
        break;
    default:
        FUN_00a305b0(buf, len + 0x20, str_0109b2ec, name);
        break;
    }
    return buf;
}

struct Allocator
{
    void* __thiscall Game_DoHeapAlloc(unsigned int bytes);
};
void* __cdecl operator new[](unsigned int n)
{
    return reinterpret_cast<Allocator&>(DAT_011f6238).Game_DoHeapAlloc(n);
}
struct GeometryData
{
    void* m_00;
    void* m_04;
    unsigned short vertexCount;
    unsigned short m_0a;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    unsigned short geomFlags;
};
struct Geometry
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void* m_6c;
    void* m_70;
    void* m_74;
    void* m_78;
    void* m_7c;
    void* m_80;
    void* m_84;
    void* m_88;
    void* m_8c;
    void* m_90;
    void* m_94;
    void* m_98;
    void* m_9c;
    void* m_a0;
    void* m_a4;
    void* m_a8;
    void* m_ac;
    void* m_b0;
    void* m_b4;
    GeometryData* geometryData;
};

// @fnv 0x00ead1e0
// src: XBOX_PDB 0x00ead1e0
void NiCollisionData::CreateWorldVertices()
{
    if (m_pkSceneObject)
    {
        Geometry* geometry = (Geometry*)m_pkSceneObject->IsTriBasedGeometry();
        if (geometry && !m_pWorldVertices)
        {
            unsigned short count = geometry->geometryData->vertexCount;
            if (count != 0)
            {
                unk4A = count;
                m_pWorldVertices = new NiPoint3[count];
                unk48 = 1;
                unk4C = geometry->geometryData->geomFlags;
            }
        }
    }
}
