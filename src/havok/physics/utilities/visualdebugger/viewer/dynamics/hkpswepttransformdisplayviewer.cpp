#include "../../../../../../../include/hkArray.h"

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkpSweptTransformDisplayViewer.h"

// Calls FindEntryIndex on the viewer at this-0x20 with a; if the returned index is non-negative, calls RemoveWorldData with it.
// @fnv 0x00d64950
// src: GUESS 0x00d64950 (confidence: high)
void hkpSweptTransformDisplayViewer::RemoveWorldDataIfFound(int a)
{
    hkpSweptTransformDisplayViewer* p = (hkpSweptTransformDisplayViewer*)((char*)this - 0x20);
    int r = p->FindEntryIndex(a);
    if (r >= 0)
        p->RemoveWorldData(r);
}

extern "C" void hkpSweptTransformDisplayViewer_addWorld();
// @fnv 0x00d647f0
// src: GUESS 0x00d647f0 (confidence: low)
void __fastcall hkpSweptTransformDisplayViewer_addWorld_Helper_00d647f0(void* self)
{
    ((void(__thiscall*)(void*))hkpSweptTransformDisplayViewer_addWorld)((char*)self - 0x20);
}

extern "C" int g_ptr_0x1268fd0;

// @fnv 0x00d64970
// src: GUESS 0x00d64970 (confidence: low)
int __cdecl hkpSweptTransformDisplayViewer_GetPtr0x1268fd0()
{
    return g_ptr_0x1268fd0;
}

struct D63FF0Entry
{
    void* m_key;
};

// Scans m_entries for an entry whose m_key equals key and returns its index, or -1 if none matches.
// @fnv 0x00d63ff0
int hkpSweptTransformDisplayViewer::FindEntryIndex(void* key) const
{
    for (int i = 0; i < m_iNumberOfEntries; i++)
    {
        if (((D63FF0Entry*)m_entries[i])->m_key == key)
            return i;
    }
    return -1;
}

struct SweptList
{
    int unk00;
    void** m_04;
    int m_08;
};

struct SweptArg
{
    int unk00;
    int unk04;
    int m_08;
    int unk0C;
    unsigned char m_10;
    unsigned char m_11;
    unsigned char m_12;
    unsigned char m_13;
};

struct SweptVObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(void* p, int g, int z);
};

extern "C" int g_ptr_0x1268fd0;

// @fnv 0x00d64120
// This callback receives the entity-listener subobject.
// src: HAVOK_LIB 0x00d64120
void __fastcall hkpSweptTransformDisplayViewer_entityRemovedCallback(hkpEntityListener* self, void*, SweptArg* a1)
{
    if (*(int*)&a1->m_10 == 0)
    {
        return;
    }
    hkpSweptTransformDisplayViewer* viewer = (hkpSweptTransformDisplayViewer*)((char*)self - 0x28);
    int iIndex = viewer->FindEntryIndex(a1->m_08);
    if (iIndex < 0)
    {
        return;
    }
    SweptList* list = (SweptList*)((hkpSweptTransformDisplayViewer::WorldDataList*)((char*)self + 8))->m_data[iIndex];
    void* key = (void*)&a1->m_11;
    SweptVObj* pVObj = *(SweptVObj**)((char*)self - 0x10);
    pVObj->v5(key, g_ptr_0x1268fd0, 0);

    int i = 0;
    int iCount = list->m_08;
    if (iCount > 0)
    {
        void** p = list->m_04;
        do
        {
            if (*p == key)
            {
                if (i >= 0)
                {
                    (*(volatile int*)&list->m_08)--;
                    int last = list->m_08;
                    if (last != i)
                    {
                        list->m_04[i] = list->m_04[last];
                    }
                }
                break;
            }
            ++i;
            ++p;
        } while (i < iCount);
    }

    key = (void*)&a1->m_12;
    int g2 = g_ptr_0x1268fd0;
    pVObj = *(SweptVObj**)((char*)self - 0x10);
    pVObj->v5(key, g2, 0);

    i = 0;
    iCount = list->m_08;
    if (iCount > 0)
    {
        void** p = list->m_04;
        do
        {
            if (*p == key)
            {
                if (i >= 0)
                {
                    (*(volatile int*)&list->m_08)--;
                    int last = list->m_08;
                    if (last != i)
                    {
                        list->m_04[i] = list->m_04[last];
                    }
                }
                break;
            }
            ++i;
            ++p;
        } while (i < iCount);
    }
}

struct FUN_00d647b0_Pool
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
    int* m_items;
    int m_uiItemCount;
};

typedef void(__thiscall* FUN_00d647b0_Handler)(hkpSweptTransformDisplayViewer* self, int item);

// @fnv 0x00d647b0
void hkpSweptTransformDisplayViewer::NotifyItems()
{
    // init receives the hkProcess subobject, eight bytes into the viewer.
    if ((*(FUN_00d647b0_Pool**)((char*)this + 0x1c)) != 0)
    {
        int i = 0;
        if ((*(FUN_00d647b0_Pool**)((char*)this + 0x1c))->m_uiItemCount > i)
        {
            hkpSweptTransformDisplayViewer* listener = (hkpSweptTransformDisplayViewer*)((char*)this - 8);
            do
            {
                ((FUN_00d647b0_Handler)hkpSweptTransformDisplayViewer_addWorld)(listener, (*(FUN_00d647b0_Pool**)((char*)this + 0x1c))->m_items[i]);
                i++;
            } while (i < (*(FUN_00d647b0_Pool**)((char*)this + 0x1c))->m_uiItemCount);
        }
    }
}

struct SweptHeap
{
    virtual ~SweptHeap();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
    virtual void* AllocateBufferWithSize(int& n);
    virtual void ReturnMemory(void* p, int n);
};

struct SweptRouter
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    SweptHeap* m_pStreamAllocator;
    SweptHeap& heap()
    {
        return *m_pStreamAllocator;
    }
};

__declspec(nothrow) SweptRouter& __cdecl hkMemoryRouter_getInstance();

template <int SIZE> __forceinline void SweptMemCpyOne(void* dst, const void* src)
{
    for (int i = 0; i < SIZE / 4; i++)
        ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i];
}



struct SweptEntityListener
{
    virtual void EntityAddedCallback(void* entity);
};
struct SweptPostSimListener
{
    virtual void postSimulationCallback(void* world);
};

struct SweptWorld
{
    void AddEntityListener(SweptEntityListener* listener);
    void AddPostSimulationListener(SweptPostSimListener* listener);
};

template<> __forceinline hkArray<unsigned long>::~hkArray() {
 SweptHeap& alloc=hkMemoryRouter_getInstance().heap();m_iElementCount=0;
 if((m_iCapacityState&0x80000000)==0)alloc.ReturnMemory(m_data,(m_iCapacityState&0x3fffffff)*sizeof(unsigned long));
 m_data=0;m_iCapacityState=0x80000000;
}
struct SweptWorldData
{
    SweptWorld* m_pOwningWorld;
    hkArray<unsigned long> m_kEntityIDs;

    static void operator delete(void* p, unsigned int nbytes)
    {
        hkMemoryRouter_getInstance().heap().ReleaseBlock(p, nbytes);
    }
};

__forceinline void hkpSweptTransformDisplayViewer::WorldDataList::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        SweptMemCpyOne<sizeof(SweptWorldData*)>(m_data + index, m_data + m_iElementCount);
}

// Unregisters this viewer from the world at index, calls ClearSweptEntry, deletes the world data and removes it from the array.
// @fnv 0x00d64800
void hkpSweptTransformDisplayViewer::RemoveWorldData(int index)
{
    m_kWorldDataList[index]->m_pOwningWorld->AddEntityListener((SweptEntityListener*)(hkpEntityListener*)this);
    m_kWorldDataList[index]->m_pOwningWorld->AddPostSimulationListener((SweptPostSimListener*)(hkpWorldPostSimulationListener*)this);
    ClearSweptEntry(index);
    delete m_kWorldDataList[index];
    m_kWorldDataList.removeAt(index);
}

class BSAudio;
namespace fnv_00d648c0 {
BSAudio* __cdecl hkMemoryRouter_getInstance();
extern int DAT_010d1918, DAT_010d18f8, DAT_010d18e8, DAT_010d18cc, DAT_010d18bc, DAT_010ccf7c;
__forceinline void ResetWorldData(hkpSweptTransformDisplayViewer::WorldDataList& data)
{
    data.m_data = 0;
    data.m_iCapacityState = 0x80000000u;
}

// The shared class has no declaration for this explicit destruction body.
// @fnv 0x00d648c0
void __fastcall Destroy(hkpSweptTransformDisplayViewer* self)
{
    int i = self->m_kWorldDataList.m_iElementCount - 1;
    *(int*)(self) = (int)&DAT_010d1918;
    *(int*)((char*)self + 0x08) = (int)&DAT_010d18f8;
    *(int*)((char*)self + 0x20) = (int)&DAT_010d18e8;
    *(int*)((char*)self + 0x28) = (int)&DAT_010d18cc;
    *(int*)((char*)self + 0x2c) = (int)&DAT_010d18bc;
    if (i >= 0)
    {
        do
        {
            self->RemoveWorldData(i);
            --i;
        } while (i >= 0);
    }
    hkMemoryRouter* h = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* a = reinterpret_cast<hkMemoryAllocator*>(h->m_heap);
    self->m_kWorldDataList.m_iElementCount = 0;
    unsigned int uiCapBits = self->m_kWorldDataList.m_iCapacityState;
    // FreeArray is nonvirtual in the shared header; the game dispatches through slot 4.
    if ((uiCapBits & 0x80000000u) == 0)
        ((void(__thiscall*)(hkMemoryAllocator*, void*, unsigned int))(*(void***)a)[4])(
            a, self->m_kWorldDataList.m_data, (uiCapBits & 0x3fffffffu) * 4);
    ResetWorldData(self->m_kWorldDataList);
    *(int*)((char*)self + 0x2c) = (int)&DAT_010ccf7c;
    *(int*)((char*)self + 0x28) = (int)"pFU";
    return self->FUN_00ddcc60();
}
}  // namespace fnv_00d648c0

#include <xmmintrin.h>
struct __declspec(align(16)) D64020Vector4
{
    float m_f[4];
};

// local form of hkRotation: 0x00d64020 needs implicit rotation construction; shared form gives 261 bytes vs exe 252.
struct __declspec(align(16)) D64020Rotation
{
    D64020Vector4 m_kColumn0;
    D64020Vector4 m_kColumn1;
    D64020Vector4 m_kColumn2;

    void set(const D64020Vector4& quat);
};

struct __declspec(align(16)) D64020Transform
{
    D64020Rotation m_rotation;
    D64020Vector4 m_vTranslation;
};

inline __m128 D64020RotateDir(const D64020Rotation& m, const D64020Vector4& v)
{
    const __m128 b = *(const __m128*)v.m_f;
    const __m128 b0 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(0, 0, 0, 0));
    const __m128 r0 = _mm_mul_ps(*(const __m128*)m.m_kColumn0.m_f, b0);
    const __m128 b1 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(1, 1, 1, 1));
    const __m128 r1 = _mm_mul_ps(*(const __m128*)m.m_kColumn1.m_f, b1);
    const __m128 b2 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(2, 2, 2, 2));
    const __m128 r2 = _mm_mul_ps(*(const __m128*)m.m_kColumn2.m_f, b2);
    return _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

extern int g_D64020Color;

struct D64020DisplayHandler
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void displayFrame(const D64020Transform& transform, unsigned long id, int tag);
};

struct D64020Constraint
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
    D64020Vector4 m_kPivotA;
    D64020Vector4 m_kPivotB;
    D64020Vector4 m_kRotationA;
    D64020Vector4 m_kRotationB;
    D64020Vector4 m_localPivot;
};

// Builds two D64020Transforms from the constraint's rotation and pivot pairs and submits them to the display handler for rendering.
// @fnv 0x00d64020
// This callback receives the post-simulation-listener subobject.
void __fastcall DisplayConstraintPivots(hkpWorldPostSimulationListener* self, void*, D64020Constraint* constraint)
{
    hkpSweptTransformDisplayViewer* viewer = (hkpSweptTransformDisplayViewer*)((char*)self - 0x2c);
    D64020Transform frame;

    frame.m_rotation.set(constraint->m_kRotationA);
    *(__m128*)frame.m_vTranslation.m_f = _mm_sub_ps(*(const __m128*)constraint->m_kPivotA.m_f,
                                                    D64020RotateDir(frame.m_rotation, constraint->m_localPivot));
    ((D64020DisplayHandler*)viewer->unk10)->displayFrame(frame, (unsigned long)constraint + 0x11, g_D64020Color);

    frame.m_rotation.set(constraint->m_kRotationB);
    *(__m128*)frame.m_vTranslation.m_f = _mm_sub_ps(*(const __m128*)constraint->m_kPivotB.m_f,
                                                    D64020RotateDir(frame.m_rotation, constraint->m_localPivot));
    ((D64020DisplayHandler*)viewer->unk10)->displayFrame(frame, (unsigned long)constraint + 0x12, g_D64020Color);
}

// The shared header does not declare the deleting-destructor entry points.
// Keep their ABI bridges as functions rather than duplicate viewer classes.
// @fnv 0x00d649c0
void* __fastcall DeleteSweptTransformViewer(hkpSweptTransformDisplayViewer* self, void*, unsigned int flags)
{
    fnv_00d648c0::Destroy(self);
    if (flags & 1)
        hkMemoryRouter_getInstance().heap().ReleaseBlock(self, self->m_usMemSizeAndFlags);
    return self;
}

// @fnv 0x00d64980
// src: GUESS 0x00d64980 (confidence: low)
__declspec(naked) void Object_ProcessState_00d64980()
{
    __asm { sub ecx, 8 }
    __asm { jmp DeleteSweptTransformViewer }
}

// @fnv 0x00d64990
__declspec(naked) void FUN_00d64990()
{
    __asm { sub ecx, 28h }
    __asm { jmp DeleteSweptTransformViewer }
}

// @fnv 0x00d649a0
// src: GUESS 0x00d649a0 (confidence: low)
__declspec(naked) void Object_ProcessState_00d649a0()
{
    __asm { sub ecx, 2ch }
    __asm { jmp DeleteSweptTransformViewer }
}

// @fnv 0x00d649b0
__declspec(naked) void FUN_00d649b0()
{
    __asm { sub ecx, 20h }
    __asm { jmp DeleteSweptTransformViewer }
}
