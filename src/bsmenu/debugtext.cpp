
// src/bsmenu/debugtext.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsmenu/debugtext.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/Setting.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/NiColorA.h"
#include "../../include/DebugText.h"
#include "../../include/NiTPointerMap.h"

// The shared header leaves the layout fields and formatted virtual signatures
// opaque; retain their original offsets and call signatures below.

// @fnv 0x00a0e750
int DebugText::GetEntry(int aiIndex)
{
    return *(int*)((char*)this + aiIndex * 4 + 0x2284);
}

// @fnv 0x00a11860
void __thiscall DebugText::SetLine(DEBUGTEXT_LOCATION aeLoc, int aiLine)
{
    *(int*)((char*)this + 0x2284 + (int)aeLoc * 4) = aiLine;
}

struct GlobalObject_00a7b610;

extern GlobalObject_00a7b610 g_011f33d4;

struct FUN_00a11b70_shell {
    GlobalObject_00a7b610* __thiscall GetGlobalObject();
};

// @fnv 0x00a11b70
GlobalObject_00a7b610* __thiscall FUN_00a11b70_shell::GetGlobalObject()
{
    return &g_011f33d4;
}

// Adds the value at this+0x2280 multiplied by b to the int at this+0x2284 indexed by a.
// @fnv 0x00a0e430
void __thiscall DebugText::AddScaledValue(int aiIndex, int aiMultiplier)
{
    *(int*)((char*)this + 0x2284 + aiIndex * 4) += *(int*)((char*)this + 0x2280) * aiMultiplier;
}

// @fnv 0x00a0e470
// src: XBOX_PDB 0x00a0e470
int __cdecl DebugText_PrintX(DebugText* apDebugText, int aiX, const char* apFormatString, ...)
{
    int iret;
    {
        char* args;
        args = (char*)(&apFormatString + 1);
        iret = ((int (__thiscall*)(DebugText*, int, int, int, const char*, char*, int))(*(void***)apDebugText)[4])(apDebugText, aiX, 0, 1, apFormatString, args, 0);
    }
    return iret;
}

// Calls the virtual method f4 on p with a, b, c, d, a pointer to e, and 0, returning its result.
// @fnv 0x00a0e4b0
int __cdecl InvokeVirtualWithArgs(DebugText* apObject, int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    char* args;
    int iret;
    args = (char*)&aiArg5;
    iret = ((int (__thiscall*)(DebugText*, int, int, int, int, char*, int))(*(void***)apObject)[4])(apObject, aiArg1, aiArg2, aiArg3, aiArg4, args, 0);
    return iret;
}

// @fnv 0x00a0e580
// src: XBOX_PDB 0x00a0e580
int __cdecl DebugText_PrintLine(DebugText* pThis, int aeLocation, int aeJustify, const char* apFormatString, ...)
{
    char* args;
    int iret;
    args = (char*)(&apFormatString + 1);
    iret = ((int (__thiscall*)(DebugText*, int, int, const char*, char*, int))(*(void***)pThis)[6])(pThis, aeLocation, aeJustify, apFormatString, args, 0);
    return iret;
}

// Forwards a format string and its varargs to the object's virtual f4 with x, 0, 1 and a color, returning its result.
// @fnv 0x00a0e690
// src: XBOX_PDB 0x00a0e690
int DebugText_PrintXC(DebugText* aObj, int aiX, const NiColorA& arColor, const char* apFormatString, ...)
{
    char* args;
    int iret;
    args = (char*)(&apFormatString + 1);
    iret = ((int (__thiscall*)(DebugText*, int, int, int, const char*, char*, const NiColorA&))(*(void***)aObj)[4])(aObj, aiX, 0, 1, apFormatString, args, arColor);
    return iret;
}

// Forwards p1, p3, p4, p5, the varargs pointer and p2 to the virtual VFunc and returns its result.
// @fnv 0x00a0e6d0
int __cdecl InvokeVFuncWithVarArgs(DebugText* pObject, int aiArg1, void* apArg2, int aiArg3, int aiArg4, const char* p5, ...)
{
    int iret;
    {
        char* args;
        args = (char*)(&p5 + 1);
        iret = ((int (__thiscall*)(DebugText*, int, int, int, const char*, char*, void*))(*(void***)pObject)[4])(pObject, aiArg1, aiArg3, aiArg4, p5, args, apArg2);
    }
    return iret;
}

namespace fnv_00a0e710 {
typedef char* va_list;
// Forwards a format string and its va_list to the virtual vf18 debug-text method and returns its result.
// @fnv 0x00a0e710
// src: XBOX_PDB 0x00a0e710
int DebugText_PrintLineC(DebugText* pThis, const NiColorA* apTextColor, DEBUGTEXT_LOCATION aeLocation, DEBUGTEXT_JUSTIFY aeJustify, const char* apFormatString, ...)
{
    va_list args;
    int iret;
    args = (va_list)&apFormatString + 4;
    iret = ((int (__thiscall*)(DebugText*, DEBUGTEXT_LOCATION, DEBUGTEXT_JUSTIFY, const char*, va_list, const NiColorA*))(*(void***)pThis)[6])(pThis, aeLocation, aeJustify, apFormatString, args, apTextColor);
    return iret;
}
}  // namespace fnv_00a0e710

extern "C" unsigned char __cdecl Interface_IsDebugTextVisible();
extern int DAT_011f33dc;
extern void (__stdcall *DAT_00fdf05c)(int*);

// @fnv 0x00a11820
// src: COMMUNITY 0x00a11820
void __cdecl DebugText_Lock()
{
    if (Interface_IsDebugTextVisible())
        DAT_00fdf05c(&DAT_011f33dc);
}

// 12-byte record of FUN_00a11c00 (first dword copied to +8 of the new one); not a map item: the callee 0x00a11db0
// takes the new record.
struct FUN_00a11c00_Record {
    unsigned int key;
    void* data;
    void* extra;
};
struct P03MM {
    void* __thiscall Allocate(unsigned int size);
};
extern P03MM g_memoryManager;
struct FUN_00a11c00_Owner {
    void NiTList_AddTail(FUN_00a11c00_Record* item);
    void NewItem(FUN_00a11c00_Record* item);
};
// Allocates a 12-byte record, stores item->key in its extra field, and passes it to 0x00a11db0.
// @fnv 0x00a11c00
// src: COMMUNITY 0x00a11c00
void FUN_00a11c00_Owner::NiTList_AddTail(FUN_00a11c00_Record* item)
{
    FUN_00a11c00_Record* created = (FUN_00a11c00_Record*)g_memoryManager.Allocate(0xc);
    FUN_00a11c00_Record* temp = created;
    temp->extra = (void*)item->key;
    NewItem(temp);
}

template <>
unsigned int __thiscall BSSimpleArray<void*>::BSSimpleArray_AddUninitialized_0();

// @fnv 0x00a11d20
template <>
// src: COMMUNITY 0x00a11d20
unsigned int __thiscall BSSimpleArray<void*>::BSSimpleArray_Add(void* &aValue)
{
    unsigned int uiIndex = BSSimpleArray_AddUninitialized_0();
    {
        unsigned int n;
        for (n = 0; n < 1; ++n) {
            void** p = pBuffer + uiIndex + n;
        }
    }
    pBuffer[uiIndex] = aValue;
    return uiIndex;
}

struct PendingObj {
    void FUN_00a0dcc0();
};

struct PendingOwner {
    void MemoryManager_Deallocate(PendingObj* p);
};

extern PendingOwner g_011f6238;
extern PendingObj* g_011f33a8;

// If g_011f33a8 is set, calls FUN_00a0dcc0 on it, passes it to g_011f6238.FUN_00aa4060, then clears g_011f33a8.
// @fnv 0x00a0dae0
void __cdecl ClearPendingObject() {
    if (g_011f33a8 != 0) {
        PendingObj* b = g_011f33a8;
        PendingObj* a = b;
        void* r;
        if (a != 0) {
            if ((a->FUN_00a0dcc0(), 1) & 1) {
                g_011f6238.MemoryManager_Deallocate(a);
            }
            r = a;
        } else {
            r = 0;
        }
        g_011f33a8 = 0;
    }
}

extern Setting DAT_011f33c8,DAT_011debac,DAT_011deec0;
extern int DAT_01202800;
struct Record { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34; float* unk38; };
extern Record** DAT_011f33f8;
bool Interface_GetFullHelp();
// Computes height from a record's unk38, fills positions[3] from a margin setting, and sets left/right/center from the right margin setting.
// @fnv 0x00a0e2a0
void DebugText::UpdateLayoutPositions() {
 int* c = &DAT_011f33c8 ? reinterpret_cast<int*>(&DAT_011f33c8.uValue) : (DAT_01202800=0,&DAT_01202800);
 Record** e = DAT_011f33f8;
 Record* j = e[*c-1];
 (*(int*)((char*)this + 0x2280)) = (int)((j->unk38 ? *j->unk38 : 0.0f)+3.0);
 int l;
 for (l=0;l<3;l++) {
  int* margin = &DAT_011debac ? reinterpret_cast<int*>(&DAT_011debac.uValue) : (DAT_01202800=0,&DAT_01202800);
  ((int*)((char*)this + 0x2284))[l] = *margin + (Interface_GetFullHelp() ? 4 : 1)*(*(int*)((char*)this + 0x2280));
 }
    {
 int* rightMargin = &DAT_011deec0 ? reinterpret_cast<int*>(&DAT_011deec0.uValue) : (DAT_01202800=0,&DAT_01202800);
 (*(int*)((char*)this + 0x2294)) = 0x500 - *rightMargin;
    }
    {
 int* fonts = &DAT_011deec0 ? reinterpret_cast<int*>(&DAT_011deec0.uValue) : (DAT_01202800=0,&DAT_01202800);
 (*(int*)((char*)this + 0x2290)) = *fonts;
    }
 (*(int*)((char*)this + 0x2298)) = (((*(int*)((char*)this + 0x2294))-(*(int*)((char*)this + 0x2290)))>>1)+(*(int*)((char*)this + 0x2290));}

extern "C" int __cdecl FUN_00ecddf1(char* buf, unsigned int n, const char* fmt, char* args);

// Formats pcFormat with pArgs into a 200-byte buffer, then prints it at iX and the selected line's Y.
// @fnv 0x00a0e4f0
int DebugText::PrintFormattedLine(int iX, int iLine, int iFlags, const char* pcFormat, char* pArgs, const NiColorA* pkColor)
{
    char acBuffer2[200];
    FUN_00ecddf1(acBuffer2, 200, pcFormat, pArgs);
    int iResult = Print(acBuffer2, (float)iX, (float)((int*)((char*)this + 0x2284))[iLine], iFlags, -1, -1.0f, 0, pkColor);
    return iResult;
}

int FUN_00ecddf1(char* pcBuffer, unsigned int uiSize, const char* pcFormat, char* pArgs);

// Formats pcFormat with pArgs into a 200-byte buffer, prints it at slot iSlot's X/Y, advances that slot's Y by the line height, and returns the print result.
// @fnv 0x00a0e5c0
int DebugText::PrintFormattedAtSlot(int iSlot, int m_iPayloadInteger, const char* pcFormat, char* pArgs, const NiColorA* pkColor) {
    int iResult;
    char acText[200];
    FUN_00ecddf1(acText, sizeof(acText), pcFormat, pArgs);
    iResult = Print(acText, (float)((int*)((char*)this + 0x2290))[iSlot], (float)((int*)((char*)this + 0x2284))[iSlot], m_iPayloadInteger, -1, -1.0f, 0, pkColor);
    ((int*)((char*)this + 0x2284))[iSlot] += (*(int*)((char*)this + 0x2280));
    return iResult;
}

struct ListNode_b5742 {
    ListNode_b5742* m_00;
    ListNode_b5742* m_04;
    unsigned int m_08;
};

struct FUN_00aa4060_shell {
    void __thiscall MemoryManager_Deallocate(void* p);
};
extern FUN_00aa4060_shell DAT_011f6238;

struct FUN_00a1c080_shell {
    unsigned int __thiscall PopFront();
};
struct FUN_00a11fa0_shell {
    unsigned int __thiscall RemoveNextNode();
};

struct FUN_00a11e10_cls {
    ListNode_b5742* m_00;
    ListNode_b5742* m_04;
    unsigned int m_08;

    unsigned int RemoveNode(ListNode_b5742** pNode);
};

// @fnv 0x00a11e10
unsigned int FUN_00a11e10_cls::RemoveNode(ListNode_b5742** pNode) {
    unsigned int unk00[6];
    ListNode_b5742* node3 = *pNode;
    if (node3 == m_00) {
        *pNode = node3->m_00;
        return reinterpret_cast<FUN_00a1c080_shell*>(this)->PopFront();
    }
    if (node3 == m_04) {
        *pNode = 0;
        return reinterpret_cast<FUN_00a11fa0_shell*>(this)->RemoveNextNode();
    }
    ListNode_b5742* prev = node3->m_04;
    ListNode_b5742* pNext = node3->m_00;
    *pNode = pNext;
    if (prev != 0) {
        prev->m_00 = pNext;
    }
    if (pNext != 0) {
        pNext->m_04 = prev;
    }
    unsigned int uiData = node3->m_08;
    node3->m_08 = 0;
    {
    ListNode_b5742* pDead = node3;
    DAT_011f6238.MemoryManager_Deallocate(pDead);
    }
    m_08 = m_08 - 1;
    return uiData;}

// Ensures capacity by allocating or growing the buffer when full, then increments the count and returns the previous index.
// @fnv 0x00a11ee0
template <>
// src: COMMUNITY 0x00a11ee0
unsigned int BSSimpleArray<void*>::BSSimpleArray_AddUninitialized_0() {
    unsigned int unkC, tmp0, a0;
    unsigned int cap;
    unsigned int newCap;
    bool fullTmp;
    if (iSize == SimpleArrayStorage)
        fullTmp = true;
    else
        fullTmp = false;
    if (fullTmp) {
        if (SimpleArrayStorage == 0) {
            cap = 4;
            // The original allocator is dispatched through virtual slot 1.
            pBuffer = (void**)((void* (__thiscall*)(BSSimpleArray<void*>*, unsigned int))(*(void***)this)[1])(this, cap);
            SimpleArrayStorage = cap;
        } else {
            newCap = (SimpleArrayStorage > 0x400) ? SimpleArrayStorage + 0x400 : SimpleArrayStorage * 2;
            ReallocateStorage(newCap, iSize);
            SimpleArrayStorage = newCap;
        }
    }
    iSize++;
    return iSize - 1;
}

struct Point2DResult {
    float fX;
    float fY;
    int iFlags;
    int iUnk0C;
    int iResult;
};
struct DebugTextItem { Point2DResult* pData; };
struct DebugTextEntry {
    float fX;
    float fY;
    int iFlags;
    int iUnk0C;
    int iResult;
    char pad[0x2c - 0x14];
};

// Searches the item list, then the 200-entry table, for a matching fX/fY/iFlags and returns its iResult, or 0 if none match.
// @fnv 0x00a10630
int DebugText::FindDebugTextResult(float fX, float fY, int iFlags) {
    unsigned int i;
    int j2;
    unsigned int ItemUpdateArray;
    for (i = 0; i < (ItemUpdateArray = (*(unsigned int*)((char*)this + 0x2278))); i++) {
        if ((*(DebugTextItem***)((char*)this + 0x2274))[i]->pData->fX == fX && (*(DebugTextItem***)((char*)this + 0x2274))[i]->pData->fY == fY && (*(DebugTextItem***)((char*)this + 0x2274))[i]->pData->iFlags == iFlags) {
            DebugTextItem*& rEntry = (*(DebugTextItem***)((char*)this + 0x2274))[i];
            int iResult = rEntry->pData->iResult;
            return iResult;
        }
    }
    for (j2 = 0; j2 < 200; j2++) {
        if (((DebugTextEntry*)((char*)this + 4))[j2].fX == fX && ((DebugTextEntry*)((char*)this + 4))[j2].fY == fY && ((DebugTextEntry*)((char*)this + 4))[j2].iFlags == iFlags) {
            int iResult = ((DebugTextEntry*)((char*)this + 4))[j2].iResult;
            return iResult;
        }
    }
    return 0;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

#include <string.h>
extern "C" void __cdecl FUN_00ecc7b0(char* destination, const char* source, unsigned int limit);
struct SearchString {
    const char* data;
    unsigned short length;
    unsigned short capacity;
};
struct SearchEntry {
    float x;
    float y;
    int flags;
    int unk0c;
    SearchString text;
    int unk18, unk1c, unk20, unk24, unk28;
};
struct SearchPointer { SearchEntry* value; };
// @fnv 0x00a103e0
// src: COMMUNITY 0x00a103e0
bool DebugText::GetDebugText_0(char* destination, float x, float y, int flags)
{
    bool found = false;
    *destination = 0;
    unsigned int i;
    int j;
    {
    unsigned int count;
    for (i = 0; !found && (count = (*(unsigned int*)((char*)this + 0x2278)), i < count); ++i) {
        if ((*(SearchPointer***)((char*)this + 0x2274))[i]->value->x == x &&
            (*(SearchPointer***)((char*)this + 0x2274))[i]->value->y == y &&
            (*(SearchPointer***)((char*)this + 0x2274))[i]->value->flags == flags) {
            if (destination) {
                SearchPointer** entry = &(*(SearchPointer***)((char*)this + 0x2274))[i];
                {
                {
                const char* lengthData;
                {
                SearchString* text = &(*entry)->value->text;
                if ((text->length == 65535 ? (lengthData = text->data, strlen(lengthData)) : text->length) != 0) {
                    SearchPointer** copyEntry = &(*(SearchPointer***)((char*)this + 0x2274))[i];
                    {
                    const char* source = (*copyEntry)->value->text.data;
                    FUN_00ecc7b0(destination, source, 2046);
                    }
                }
                }
                }
            }
            }
            found = true;
        }
    }
    }
    for (j = 0; !found && j < 200; ++j) {
        if (((SearchEntry*)((char*)this + 4))[j].x == x && ((SearchEntry*)((char*)this + 4))[j].y == y && ((SearchEntry*)((char*)this + 4))[j].flags == flags) {
            if (destination) {
                {
                const char* lengthData;
                {
                SearchString* text = &((SearchEntry*)((char*)this + 4))[j].text;
                if ((text->length == 65535 ? (lengthData = text->data, strlen(lengthData)) : text->length) != 0) {
                    const char* source = ((SearchEntry*)((char*)this + 4))[j].text.data;
                    FUN_00ecc7b0(destination, source, 2046);
                }
                }
                }
            }
            found = true;
        }
    }
    return found;
}

#include <windows.h>
// Releases the global critical section when the game is running in a mode that
// still owns it.
// @fnv 0x00a11840
void __cdecl ReleaseLock()
{
    if (Interface_IsDebugTextVisible() != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_011f33dc);
    }
}
