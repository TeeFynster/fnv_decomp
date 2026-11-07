#include "../../../../../../../include/hkArrayBase.h"
#include "../../../../../../../include/hkArray.h"

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/BSAudio.h"
#include "../../../../../../../include/hkpSweptTransformDisplayViewer.h"
#include <xmmintrin.h>

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
	SweptHeap& heap() { return *m_pStreamAllocator; }
};
__declspec(nothrow) SweptRouter& __cdecl hkMemoryRouter_getInstance();
template <int SIZE> __forceinline void SweptMemCpyOne(void* dst, const void* src) { for (int i = 0; i < SIZE / 4; i++) ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i]; }
template <class T>
static __forceinline void SweptArray_destroy(hkArrayBase<T>& self) throw()
{ SweptArray__clearAndDeallocate(self, hkMemoryRouter_getInstance().heap()); }

template <class T>
static __forceinline void SweptArray_clear(hkArrayBase<T>& self) throw()
{ self.m_iElementCount = 0; }

template <class T>
static __forceinline void SweptArray__clearAndDeallocate(hkArrayBase<T>& self, SweptHeap& alloc) throw()
{
		SweptArray_clear(self);
		if ((self.m_iCapacityState & 0x80000000) == 0)
			alloc.ReturnMemory(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
		self.m_data = 0;
		self.m_iCapacityState = 0x80000000;
	}

template <class T>
static __forceinline void SweptArray_removeAt(hkArrayBase<T>& self, int index)
{
		self.m_iElementCount--;
		if (self.m_iElementCount != index)
			SweptMemCpyOne<sizeof(T)>(self.m_data + index, self.m_data + self.m_iElementCount);
	}

struct SweptArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { SweptArray_destroy(self); }
};
void __cdecl ResizeAudioStream(void *,void *,int);
struct FUN_008cd6a0_Class { void hkRotation_set(void *); };
struct ErrBuf { void FUN_00cb1600(char* b, int n); void ProcessAndReturnValue_00cc01c0(const char* s); void FUN_00cc00e0(); int unk00; int unk04; int unk08; };
struct TmpA { void hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment(); int unk00; int unk04; };
struct TmpB { void hkpShapeDisplayBuilder_hkpShapeDisplayBuilder(TmpA* a); void UpdateState_00de0f90(int a, void* b); int unk00; int unk04; int unk08; int unk0c; int unk10; };
struct Reporter { virtual void v0(); virtual void v1(); virtual void v2(); virtual void report(int a, int b, const char* msg, const char* file, int line); };
extern Reporter* DAT_01268360;
extern int DAT_01268fd0; extern int DAT_01268fd4; extern int DAT_01268fd8;
struct Shape { virtual void release(int f); int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; };
struct Disp { virtual void v0(); virtual void add(void* a, void* b, void* c, int d, int e); virtual void v2(); virtual void tag(int a, void* b, int c); };
__declspec(align(16)) struct Mat { float a0,a1,a2,a3,b0,b1,b2,b3,c0,c1,c2,c3,d0,d1,d2,d3; };


struct Entry { int unk00; hkArrayBase<int> unk04; };
struct Arg {
    int unk00; int unk04; int unk08; int unk0c;
    union { int unk10; struct { unsigned char byte10, unk11, unk12, unk13; }; };
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char motionType, unkE9, unkEA, unkEB;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    __m128 position0, position1, rotation0, rotation1, center;
};

// The shared viewer does not yet declare these callbacks or its world-data array.
// Keep their original listener entry-point adjustments in free helpers.
// The unused EDX parameter preserves the ECX receiver and stack argument.
// @fnv 0x00d642c0
// src: XBOX_PDB 0x00d642c0
void __fastcall hkpSweptTransformDisplayViewer_entityAddedCallback(hkpEntityListener* listener, void*, Arg* a)
{
     
    if (a->unk10 == 0) return;
     int idx = ((hkpSweptTransformDisplayViewer*)((char*)listener - 0x28))->FindEntryIndex(a->unk08);
    if (idx < 0) return;
    hkArray<Shape*, SweptArrayPolicy> list(FinishingFlag(0));
    Entry* e; e = (*(Entry***)((char*)listener + 8))[idx];
    list.m_data = 0; list.m_iElementCount = 0; list.m_iCapacityState = 0x80000000; TmpA ta; ta.hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment();
    TmpB tb; tb.hkpShapeDisplayBuilder_hkpShapeDisplayBuilder(&ta);
    tb.UpdateState_00de0f90(a->unk10, &list);
    for (int j = list.m_iElementCount - 1; j >= 0; j--) { Shape* s = (Shape*)list.m_data[j];
        if (s->unk50 == 6 && 0 == s->unk08) {
            char buf[512];
            ErrBuf eb;
            
            eb.FUN_00cb1600(buf, 0x200);
            eb.ProcessAndReturnValue_00cc01c0("Unable to build display geometry from hkpShape geometry data");
            DAT_01268360->report(0, -1, (const char*)&buf, ".\\VisualDebugger\\Viewer\\Dynamics\\hkpSweptTransformDisplayViewer.cpp", 0xa8);
            eb.FUN_00cc00e0();
            SweptArray_removeAt(list, j);
        } }
    if (0 < list.m_iElementCount && 5 != a->motionType) {
        unsigned char* id1 = (unsigned char*)&a->unk11;
        hkArrayBase<int>* ids = &e->unk04;
        SweptRouter* b = &hkMemoryRouter_getInstance();
        if (ids->m_iElementCount == (ids->m_iCapacityState & 0x3fffffff)) ResizeAudioStream(b->m_pStreamAllocator, ids, 4);
        int* slot1 = ids->m_data + ids->m_iElementCount;
        for (int k = 0; k < 1; ++k) slot1[k] = (int)id1; ++ids->m_iElementCount;
        Mat m1; Mat m2;
        ((FUN_008cd6a0_Class*)&m1)->hkRotation_set(&a->rotation0);
        __m128 v = a->center;
        
        __m128 p1 = _mm_sub_ps(a->position0,
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_load_ps(&m1.b0), _mm_shuffle_ps(v, v, 0x55)), _mm_mul_ps(_mm_load_ps(&m1.a0), _mm_shuffle_ps(v, v, 0))), _mm_mul_ps(_mm_load_ps(&m1.c0), _mm_shuffle_ps(v, v, 0xaa))));
        _mm_store_ps(&m1.d0, p1);
        ((FUN_008cd6a0_Class*)&m2)->hkRotation_set(&a->rotation1);
        __m128 w = a->center;
        __m128 p2r = _mm_sub_ps(a->position1,
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(w, w, 0xaa), _mm_load_ps(&m2.c0)), _mm_add_ps(_mm_mul_ps(_mm_load_ps(&m2.b0), _mm_shuffle_ps(w, w, 0x55)), _mm_mul_ps(_mm_load_ps(&m2.a0), _mm_shuffle_ps(w, w, 0)))));
                _mm_store_ps(&m2.d0, p2r);
        Disp* d = ((Disp*)((hkpSweptTransformDisplayViewer*)((char*)listener - 0x28))->hkProcess::unk10); d->add(&list, &m1, id1, DAT_01268fd0, 0);
        d = ((Disp*)((hkpSweptTransformDisplayViewer*)((char*)listener - 0x28))->hkProcess::unk10);
        d->tag(DAT_01268fd8, id1, DAT_01268fd0);
        unsigned char* id2 = &a->unk12;
        b = &hkMemoryRouter_getInstance();
        if (ids->m_iElementCount == (ids->m_iCapacityState & 0x3fffffff)) ResizeAudioStream(b->m_pStreamAllocator, ids, 4);
        int* slot2 = ids->m_data + ids->m_iElementCount;
        for (int k = 0; k < 1; ++k) slot2[k] = (int)id2; ++ids->m_iElementCount;
        d = ((Disp*)((hkpSweptTransformDisplayViewer*)((char*)listener - 0x28))->hkProcess::unk10);
        d->add(&list, &m2, id2, DAT_01268fd0, 0);
        d = ((Disp*)((hkpSweptTransformDisplayViewer*)((char*)listener - 0x28))->hkProcess::unk10);
        d->tag(DAT_01268fd4, id2, DAT_01268fd0);
    }
    for (int i = 0; i < list.m_iElementCount; i++) { Shape* s = (Shape*)list.m_data[i];
        if (0 != s) s->release(1); }
}

#include <windows.h>
extern DWORD DAT_0126835c;
extern int DAT_01268fd0;

struct S_00d63e40_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d63e40_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00d63e40_Timer(const char* name)
{
    S_00d63e40_MonitorStream* s = (S_00d63e40_MonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00d63e40_TimerCommand* h = (S_00d63e40_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct __declspec(align(16)) S_00d63e40_V4 {
    float x, y, z, w;
    __m128& q() { return *(__m128*)this; }
    const __m128& q() const { return *(const __m128*)this; }
};

struct S_00d63e40_Mat3 {
    S_00d63e40_V4 c0;
    S_00d63e40_V4 c1;
    S_00d63e40_V4 c2;
    S_00d63e40_V4 t;
    void hkRotation_set(const S_00d63e40_V4* q);
};

struct S_00d63e40_Handler {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void display(const S_00d63e40_Mat3* xf, const char* id, int tag);
};

struct __declspec(align(16)) S_00d63e40_Entity {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    char unk10;
    char id0;
    char id1;
    char unk13;
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
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    S_00d63e40_V4 pos0;
    S_00d63e40_V4 pos1;
    S_00d63e40_V4 rot0;
    S_00d63e40_V4 rot1;
    S_00d63e40_V4 com;

};

struct S_00d63e40_Array {
    S_00d63e40_Entity** m_data;
    int m_iElementCount;
};

struct S_00d63e40_Island {
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
    S_00d63e40_Array entities;

};
struct S_00d63e40_World {
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
    S_00d63e40_Island** islands;
    int numIslands;

};

struct S_00d63e40_WorldPad {
    S_00d63e40_World* w;
    S_00d63e40_World* val() const { return w; }
};

// @fnv 0x00d63e40
// src: XBOX_PDB 0x00d63e40
void __fastcall hkpSweptTransformDisplayViewer_postSimulationCallback(hkpWorldPostSimulationListener* listener, void*, S_00d63e40_WorldPad world)
{
    hkpSweptTransformDisplayViewer* viewer = (hkpSweptTransformDisplayViewer*)((char*)listener - 0x20);
    S_00d63e40_Timer("TthkpSweptTransformDisplayViewer");
    for (int i = 0; i < world.val()->numIslands; i++)
    {
        S_00d63e40_Array& arr = world.val()->islands[i]->entities;
        for (int j = 0; j < arr.m_iElementCount; j++)
        {
            S_00d63e40_Entity* e = arr.m_data[j];
            S_00d63e40_Mat3 m;
            m.hkRotation_set(&e->rot0);
            __m128 c = e->com.q();
            __m128 r = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(c, c, 0x55), m.c1.q()), _mm_mul_ps(_mm_shuffle_ps(c, c, 0), m.c0.q())), _mm_mul_ps(_mm_shuffle_ps(c, c, 0xaa), m.c2.q()));
            m.t.q() = _mm_sub_ps(e->pos0.q(), r);
            ((S_00d63e40_Handler*)viewer->hkProcess::unk04)->display(&m, &e->id0, DAT_01268fd0);
            m.hkRotation_set(&e->rot1);
            c = e->com.q();
            r = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(c, c, 0x55), m.c1.q()), _mm_mul_ps(_mm_shuffle_ps(c, c, 0), m.c0.q())), _mm_mul_ps(_mm_shuffle_ps(c, c, 0xaa), m.c2.q()));
            m.t.q() = _mm_sub_ps(e->pos1.q(), r);
            ((S_00d63e40_Handler*)viewer->hkProcess::unk04)->display(&m, &e->id1, DAT_01268fd0);
        }
    }
    S_00d63e40_Timer("Et");
}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    A::destroy(*this);
}
