
// src/gamebryo2.2/corelibs/nianimation/nianimationkey.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nianimationkey.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/MemoryManager.h"

// UpdateSlotStates - recursive tree walk over 3-child state nodes with a float test
// and a dispatch-table callback.

extern unsigned char DAT_011f3758[];
typedef void(__cdecl* SlotCallback)(float, void**, int*);
extern SlotCallback DAT_011f3810[];

struct SlotState
{
    float m00;
    unsigned int unk04[4];
    void* m14[3];
    int m20[3];
    unsigned char m2c[3];
    unsigned char unk2F;
    void* m30[3];
    int m3c[3];
};

// For each of three slots, recursively updates the slot's callback state and stores the result, then invokes the slot's callback with a5 and a6.
// @fnv 0x00a3d930
void __cdecl UpdateSlotStates(int aiSlotGroup, int a2, void** apSlotData, int* apiState, float afValueA, float afValueB)
{
    if (a2 == 4)
    {
        SlotState* pSlot = (SlotState*)*apSlotData;
        unsigned int i = 0;
        do
        {
            unsigned char idx = (unsigned char)i;
            void* pSlotData = pSlot->m14[idx];
            int iSlotIndex = pSlot->m20[idx];
            void* volatile savedC = pSlot->m30[idx];
            a2 = (int)pSlotData;
            void* pResult = pSlotData;
            if (pSlotData != 0)
            {
                UpdateSlotStates(0, iSlotIndex, (void**)(void*)&savedC, &a2, afValueA, afValueB);
                pResult = (void*)a2;
            }
            pSlot->m30[idx] = savedC;
            pSlot->m14[idx] = pResult;
            pSlot->m20[idx] = iSlotIndex;
            pSlot->m3c[idx] = 0;
            pSlot->m2c[idx] = DAT_011f3758[iSlotIndex];
            i++;
        } while (i < 3);
        return;
    }

    aiSlotGroup = aiSlotGroup * 3;
    SlotCallback pCallback = DAT_011f3810[a2 + aiSlotGroup * 2];
    if (*apiState == 1)
    {
        float* pfValue = (float*)*apSlotData;
        if (*pfValue == afValueA)
        {
            return;
        }
    }
    pCallback(afValueA, apSlotData, apiState);
    pCallback(afValueB, apSlotData, apiState);
}

extern MemoryManager _g_memoryManager;

struct Inner_00a6db50
{
    void Set(float, float, float, float);
};

struct DerivedSlotState : SlotState
{
    void SetChannelValues(void*, int, int, void*, int, int, void*, int, int);
};

struct RefSlotState
{
    int refCount;
    SlotState state;
};

typedef void* (*AllocCallback)(int count);
typedef void (*CopyCallback)(void* dst, void* src);

extern AllocCallback DAT_011f3930[];
extern CopyCallback DAT_011f39c0[];

// @fnv 0x00a3d630
// src: XBOX_PDB 0x00a3d630
void NiAnimationKey_CopySequence(int a1, int a2, void* apData, int aiCount, float afMin, float afMax, void** apOut, int* apiOutCount)
{
    if (a2 == 4)
    {
        SlotState* state = (SlotState*)apData;
        int local_m20[3];
        int local_counts[3];
        void* local_bufs[3];

        for (unsigned int uiIndex = 0; uiIndex < 3; ++uiIndex)
        {
            unsigned char idx = (unsigned char)uiIndex;
            unsigned int m20 = state->m20[idx];
            local_m20[uiIndex] = m20;
            NiAnimationKey_CopySequence(0, m20, state->m30[idx], (int)state->m14[idx], afMin, afMax, &local_bufs[uiIndex],
                         &local_counts[uiIndex]);
        }

        SlotState* pNewState;
        RefSlotState* ref = (RefSlotState*)_g_memoryManager.Allocate(sizeof(RefSlotState));
        if (ref)
        {
            ref->refCount = 1;
            pNewState = &ref->state;
            ((Inner_00a6db50*)&pNewState->unk04)->Set(0.0f, 0.0f, 0.0f, 0.0f);
            pNewState->m14[0] = 0;
            pNewState->m14[1] = 0;
            pNewState->m14[2] = 0;
            pNewState->m30[0] = 0;
            pNewState->m30[1] = 0;
            pNewState->m30[2] = 0;
            pNewState->m20[0] = 0;
            pNewState->m20[1] = 0;
            pNewState->m20[2] = 0;
            pNewState->m3c[0] = 0;
            pNewState->m3c[1] = 0;
            pNewState->m3c[2] = 0;
            pNewState->m2c[0] = 0;
            pNewState->m2c[1] = 0;
            pNewState->m2c[2] = 0;
        }
        else
        {
            pNewState = 0;
        }

        *apOut = pNewState;
        *apiOutCount = 1;
        ((DerivedSlotState*)*apOut)
            ->SetChannelValues(local_bufs[0], local_counts[0], local_m20[0], local_bufs[1], local_counts[1],
                               local_m20[1], local_bufs[2], local_counts[2], local_m20[2]);
        return;
    }

    unsigned int idx = a1 * 6 + a2;
    *apiOutCount = 0;
    unsigned char stride = DAT_011f3758[idx];
    unsigned int i;
    for (i = 0; i < (unsigned int)aiCount; ++i)
    {
        float* pfValue = (float*)((char*)apData + i * stride);
        if (!(*pfValue < afMin))
        {
            if (*pfValue > afMax)
                break;
            (*apiOutCount)++;
        }
    }

    if (*apiOutCount != 0)
    {
        AllocCallback alloc_func = DAT_011f3930[idx];
        *apOut = alloc_func(*apiOutCount);
        CopyCallback copy_func = DAT_011f39c0[idx];
        for (i = 0, *apiOutCount = 0; i < (unsigned int)aiCount; ++i)
        {
            char* src = (char*)apData + i * stride;
            float* pfValue = (float*)src;
            if (!(*pfValue < afMin))
            {
                if (*pfValue > afMax)
                    break;
                char* dst = (char*)(*apOut) + (*apiOutCount) * stride;
                copy_func(dst, src);
                *(float*)dst = *pfValue - afMin;
                (*apiOutCount)++;
            }
        }
    }
    else
    {
        *apOut = 0;
    }
}
