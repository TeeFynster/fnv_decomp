
// src/havok/physics/vehicle/manager/linearcastbatchingmanager/hkpvehiclelinearcastbatchingmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/manager/linearcastbatchingmanager/hkpvehiclelinearcastbatchingmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleLinearCastBatchingManager.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"

struct FUN_00e42fe0
{
    int __thiscall GetCount();
};

struct FUN_00e43060
{
    void __thiscall DoWork(int a, int b, int* out);
};

// Computes four aligned offsets from GetCount() and the 16-bit count at this+0x14, writes them to out, and advances a by each padding.
// @fnv 0x00e43060
void __thiscall FUN_00e43060::DoWork(int iBaseOffset, int iUnused, int* paiOffsets)
{
    int iCount = ((FUN_00e42fe0*)this)->GetCount();
    unsigned int n = *(unsigned short*)((char*)this + 0x14);
    unsigned int pad = ((unsigned int)(n * 5) << 4) + 0xf;
    pad &= 0xfffffff0u;
    paiOffsets[0] = iBaseOffset;
    iBaseOffset += pad;
    unsigned int pad2 = ((unsigned int)iCount * 0x70) + 0xf;
    pad2 &= 0xfffffff0u;
    unsigned int pad3 = ((unsigned int)iCount << 6) + 0xf;
    pad3 &= 0xfffffff0u;
    paiOffsets[1] = iBaseOffset;
    iBaseOffset += pad3;
    paiOffsets[2] = iBaseOffset;
    iBaseOffset += pad2;
    paiOffsets[3] = iBaseOffset;
}

struct FUN_00e43010
{
    int __thiscall ConvertReferences(int numVehicles);
};
// Computes a 16-byte-aligned total from the object's count, a 16-bit field at offset 0x14, the count again, and numVehicles.
// @fnv 0x00e43010
int __thiscall FUN_00e43010::ConvertReferences(int numVehicles)
{
    int count = ((FUN_00e42fe0*)this)->GetCount();
    unsigned int a = (unsigned int)(unsigned short)*(unsigned short*)((char*)this + 0x14);
    int iTotal = ((a * 5) << 4) + 0xf;
    iTotal &= 0xfffffff0;
    int iCountSize = count * 0x70 + 0xf;
    iCountSize &= 0xfffffff0;
    iTotal += iCountSize;
    int iCountSize2 = (count << 6) + 0xf;
    iCountSize2 &= 0xfffffff0;
    iTotal += iCountSize2;
    int iVehicleSize = (numVehicles << 4) + 0xf;
    iVehicleSize &= 0xfffffff0;
    iTotal += iVehicleSize;
    return iTotal;
}

struct FUN_00e42fe0_counted
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual int GetCount() = 0;
};

struct FUN_00e42fe0_vehicle
{
    unsigned char pad[0x3c];
    FUN_00e42fe0_counted* counted;
};

struct FUN_00e42fe0_impl
{
    virtual void f00() = 0;
    void* field04;
    FUN_00e42fe0_vehicle** vehicles;
    int count;

    int __thiscall GetTotalVehicleCount();
};

// Sums GetCount() over all vehicles in the array and returns the total.
// @fnv 0x00e42fe0
// src: GUESS 0x00e42fe0 (confidence: medium)
int FUN_00e42fe0_impl::GetTotalVehicleCount()
{
    int total = 0;
    for (int i = 0; i < count; ++i)
        total += vehicles[i]->counted->GetCount();
    return total;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern DWORD DAT_0126835c;

struct AllocV;
struct CharacterBufferState
{
    char* m_pCur;
    DWORD unk04, unk08, unk0c;
    AllocV* m_pSharedOwner;
    AllocV& heap()
    {
        return *m_pSharedOwner;
    }
};

CharacterBufferState* __cdecl hkMemoryRouter_getInstance();

struct AllocV
{
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void Free(void* p, unsigned int size);
};

struct HkArr
{
    char* m_data;
    int m_iElementCount;
    int m_cap;
    int getCapacity() const
    {
        return m_cap & 0x3fffffff;
    }
    void reserve(AllocV& a, int n);
    void SetSizeAndGrow(AllocV& a, int n)
    {
        reserve(a, n);
        m_iElementCount = n;
    }
};

extern "C" int __cdecl hkArrayUtil__reserve(AllocV& owner, void* arr, int newCap, int stride);

inline void HkArr::reserve(AllocV& a, int n)
{
    if (getCapacity() < n)
    {
        int cap2 = 2 * getCapacity();
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(a, this, newSize, 0x60);
    }
}

struct Counted433
{
    virtual void u00();
    virtual void u01();
    virtual void u02();
    virtual void u03();
    virtual void u04();
    virtual void u05();
    virtual void u06();
    virtual void u07();
    virtual void u08();
    virtual void u09();
    virtual void u10();
    virtual void M11(void* veh, unsigned char j, char* elem);
    virtual void u12();
    virtual int M13(unsigned char j);
    virtual void u14();
    virtual int M15(unsigned char j, void* ptr);
    virtual void u16();
    virtual void M17(void* veh, unsigned char j, int res, char* elem);
    virtual void M18(void* veh, unsigned char j, char* elem);
};

struct VehData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned char m_iWheelCount;
};

struct Vehicle433
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    VehData* m_data1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    Counted433* m_counted;
    void hkpVehicleInstance_stepVehicleUsingWheelCollideOutput(void*, void*);
};

static __forceinline void S00e43320_timerB(const char* name, volatile DWORD& tick)
{
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
    if (reinterpret_cast<char*>(pRec) < pBuf->m_capacityMinus16.m_storage)
    {
        pRec->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
}

static __forceinline void S00e43320_timer(const char* name)
{
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
    if (reinterpret_cast<char*>(pRec) < pBuf->m_capacityMinus16.m_storage)
    {
        pRec->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
}

struct Slot433
{
    HkArr m_aiIndexedValues;
    char* m_saved;
};

struct Out433
{
    int m_00;
    char* m_04;
    int m_08;
    int m_0c;
};

struct S00e43320_Mgr
{
    void* vtbl;
    int unk04;
    Vehicle433** m_ppVehicles;
    int m_uiItemCount;
    void FUN_00e43060(void* a, void* b, Out433* out);
    void hkpVehicleLinearCastBatchingManager_stepVehiclesUsingCastResults(void* param1, void* param2, void* param3);
};

// Iterates over m_ppVehicles, gathers per-wheel data via Counted433, and calls FUN_00e39030 on each vehicle with the collected array.
// @fnv 0x00e43320
// src: HAVOK_LIB 0x00e43320
void S00e43320_Mgr::hkpVehicleLinearCastBatchingManager_stepVehiclesUsingCastResults(void* param1, void* param2, void* param3)
{
    int i;
    {
        hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        if (reinterpret_cast<char*>(pRec) < pBuf->m_capacityMinus16.m_storage)
        {
            pRec->m_commandAndMonitor = "TtDoVehicles";
            _ReadWriteBarrier();
            *(volatile unsigned*)&i = (unsigned)__rdtsc();
            pRec->m_time0 = *(volatile unsigned*)&i;
            pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
        }
    }
    Out433 out;
    S00e43320_Mgr* self = this;
    int count = self->m_uiItemCount;
    FUN_00e43060(param3, param2, &out);
    char* savedVal = out.m_04;
    Slot433 slot;
    HkArr& arr = slot.m_aiIndexedValues;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_cap = (int)0x80000000;
    CharacterBufferState* ar = hkMemoryRouter_getInstance();
    char* scratch = ar->m_pCur;
    ar->m_pCur = (char*)scratch + 0x600;
    arr.m_data = scratch;
    arr.m_cap = (int)0x80000010;
    slot.m_saved = scratch;
    {
        for (i = 0; i < count; i++)
        {
            Vehicle433* veh = self->m_ppVehicles[i];
            int numWheels = veh->m_data1c->m_iWheelCount;
            arr.SetSizeAndGrow(hkMemoryRouter_getInstance()->heap(), numWheels);
            Counted433* counted = veh->m_counted;
            unsigned char j = 0;
            if (numWheels > 0)
            {
                for (; j < numWheels; j++)
                {
                    int res = counted->M15(j, savedVal);
                    if (res)
                        counted->M17(veh, j, res, arr.m_data + j * 96);
                    else
                        counted->M18(veh, j, arr.m_data + j * 96);
                    counted->M11(veh, j, arr.m_data + j * 96);
                    savedVal += counted->M13(j) * 64;
                }
            }
            self->m_ppVehicles[i]->hkpVehicleInstance_stepVehicleUsingWheelCollideOutput(param1, arr.m_data);
        }
    }
    S00e43320_timer("Et");
    char* saved = slot.m_saved;
    if (saved == arr.m_data)
        arr.m_iElementCount = 0;
    hkMemoryRouter_getInstance()->m_pCur = saved;
    {
        CharacterBufferState* ar5 = hkMemoryRouter_getInstance();
        AllocV* alloc = ar5->m_pSharedOwner;
        int cap = arr.m_cap;
        arr.m_iElementCount = 0;
        if (!(cap & (int)0x80000000))
            alloc->Free(arr.m_data, (cap & 0x3fffffff) * 96);
    }
}
