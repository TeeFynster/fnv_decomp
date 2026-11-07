
// src/havok/physics/collide/agent3/predgskcylinderagent3/hkppredgskcylinderagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/predgskcylinderagent3/hkppredgskcylinderagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FNVTypeRecord
{
    int unknown0;
    int unknown4;
    int unknown8;
    int type;
};
struct FNVObject
{
    FNVTypeRecord* record;
};
struct FNVPair
{
    FNVObject* first;
    FNVObject* second;
};
struct FNVFlags
{
    int unknown0;
    int unknown4;
    short unknown8;
    unsigned char unknownA;
    unsigned char flags;
};
extern "C" int __cdecl DispatchInputRecord(FNVPair*, int, FNVFlags*);
// @fnv 0x00d40b90
int __cdecl ConvertPairFlags(FNVPair* pair, int mode, FNVFlags* result)
{
    int converted = DispatchInputRecord(pair, mode, result);
    result->flags &= 0xF0;
    if (pair->first->record->type == 2)
    {
        result->flags |= 5;
    }
    if (pair->second->record->type == 2)
    {
        result->flags |= 10;
    }
    return converted;
}

struct FNVExtendedObject;
struct ExtendedRecord;
struct Node;

struct Allocator
{
    virtual void* unk00();
    virtual Node* allocate(unsigned int size);
};

struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};

extern "C" Manager* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl hkPredGskAgent3_sepNormal(void*, void*, void*, void*);
extern double DAT_010cf218;

struct Node
{
    int unk00;
    short unk04;
    short unk06;
    int unk08;
    int unk0c;
    Node* Init(void* p1, void* p2, float val);
};

struct ExtendedRecord : FNVTypeRecord
{
    float unk10;
    float unk14;
    int unk18;
    int unk1c;
    int unk20;
    float GetVal();
    void RemoveRef();
};

struct FNVExtendedObject : FNVObject
{
    int unk04;
    int unk08;
    FNVObject* unk0c;
};

struct __declspec(align(16)) FNVResult
{
    float x;
    float y;
    float z;
    float val;
};

struct ExtendedFlags : FNVFlags
{
    void Init(void* p1, void* p2, void* p3);
};

struct __declspec(align(16)) LocalSource
{
    FNVObject* first;
    FNVObject* second;
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

    void CopyBase(LocalSource* src);
};

// Copies the source, wraps flagged slots in new nodes, runs the flags init and FUN_00d41930, restores old objects, and returns result.val.
// @fnv 0x00d40be0
float __cdecl ComputeExtendedResult(LocalSource* source, void* apArg, FNVFlags* apFlags)
{
    LocalSource local_source;
    local_source.CopyBase(source);
    local_source.unk60 = source->unk60;
    local_source.unk70 = source->unk70;
    local_source.unk74 = source->unk74;
    local_source.unk78 = source->unk78;
    local_source.unk7c = source->unk7c;

    FNVObject** slots[2];
    FNVObject** pSecondSlot = &local_source.second;
    slots[0] = &local_source.first;
    slots[1] = pSecondSlot;

    int flags = apFlags->flags;
    int aiFlagBits[2];
    int iFlag1 = flags & 1;
    int iFlag2 = flags & 2;
    aiFlagBits[0] = iFlag1;
    aiFlagBits[1] = iFlag2;

    FNVObject* apOldObjects[2];
    apOldObjects[0] = 0;
    apOldObjects[1] = 0;

    FNVExtendedObject p[2];
    FNVExtendedObject* pTempObject = p;

    for (int i = 0; i < 2; ++i)
    {
        if (aiFlagBits[i])
        {
            FNVObject** slot;
            slot = slots[i];
            ExtendedRecord* record = (ExtendedRecord*)(*slot)->record;
            Manager* pManager = hkMemoryRouter_getInstance();
            Node* node = pManager->allocator->allocate(0x40);
            node->unk04 = 0x40;
            float v = record->unk10;
            float val = (v + record->GetVal()) + DAT_010cf218;
            node = node->Init((char*)record + 0x20, (char*)record + 0x30, val);
            if (pTempObject)
            {
                FNVObject* pOldObject = *slot;
                int iOldUnk08 = ((FNVExtendedObject*)pOldObject)->unk08;
                pTempObject->unk0c = pOldObject;
                pTempObject->unk08 = iOldUnk08;
            }
            pTempObject->record = (FNVTypeRecord*)node;
            pTempObject->unk04 = -1;
            apOldObjects[i] = *slot;
            *slot = pTempObject;
        }
        else
        {
            apOldObjects[i] = 0;
        }
        pTempObject++;
    }

    FNVTypeRecord* pSecondRecord = local_source.second->record;
    FNVTypeRecord* pFirstRecord = local_source.first->record;
    ExtendedFlags local_flags;
    local_flags.Init(pFirstRecord, pSecondRecord, (char*)source + 0x20);

    FNVResult result;
    hkPredGskAgent3_sepNormal(&local_source, apArg, &local_flags, &result);

    for (int i = 0; i < 2; ++i)
    {
        if (apOldObjects[i])
        {
            ((ExtendedRecord*)(*slots[i])->record)->RemoveRef();
            *slots[i] = apOldObjects[i];
        }
    }

    return result.val;
}

struct D40AF0State
{
    unsigned short m_iSlotIds[4];
    unsigned char m_uiEdgeIndex;
    unsigned char m_uiItemCount;
};
struct D40AF0Mask
{
    int m_pHeadNode;
    int m_iSecondInteger;
};

// @fnv 0x00d40af0
// src: HAVOK_LIB 0x00d40af0
static void __declspec(noinline) convertCylinderCacheToCapsuleCache(D40AF0State* pState, D40AF0Mask* pMask)
{
    if (pMask->m_pHeadNode)
    {
        pState->m_iSlotIds[0] = (1 - ((pState->m_iSlotIds[0] >> 7) & 1)) << 4;
        unsigned char idx = pState->m_uiEdgeIndex;
        if (idx > 1)
        {
            pState->m_iSlotIds[0] = 0x10;
            pState->m_iSlotIds[1] = 0;
            if (idx == 3)
            {
                pState->m_uiEdgeIndex = 2;
                pState->m_iSlotIds[2] = pState->m_iSlotIds[3];
            }
        }
    }
    if (pMask->m_iSecondInteger)
    {
        unsigned short* v = &pState->m_iSlotIds[pState->m_uiEdgeIndex];
        *v = (1 - ((*v >> 7) & 1)) << 4;
        if (pState->m_uiItemCount > 1)
        {
            pState->m_iSlotIds[pState->m_uiEdgeIndex] = 0x10;
            pState->m_iSlotIds[pState->m_uiEdgeIndex + 1] = 0;
            if (pState->m_uiItemCount == 3)
                pState->m_uiItemCount = 2;
        }
    }
}

void D40AF0Caller(D40AF0State* s, D40AF0Mask* m)
{
    convertCylinderCacheToCapsuleCache(s, m);
}

void __fastcall FUN_00c905b0(void* selfVal);

// For k in 0..1, if vals[k] is non-null, calls FUN_00c905b0 on **slots[k] and then stores vals[k] into *slots[k].
// @fnv 0x00d409d0
// src: HAVOK_LIB 0x00d409d0
static __declspec(noinline) void restoreOriginalShapesInCdBodies(void** apValues, void** slots)
{
    for (int k = 0; k < 2; k++)
    {
        if (apValues[k] != 0)
        {
            void* obj = slots[k];
            FUN_00c905b0(*(void**)*(void**)obj);
            *(void**)slots[k] = apValues[k];
        }
    }
}

void** volatile g_d409d0_vals;
void** volatile g_d409d0_slots;

void d409d0_probe_caller(void)
{
    restoreOriginalShapesInCdBodies(g_d409d0_vals, g_d409d0_slots);
}

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

struct D40A10Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
    Allocator& heap()
    {
        return *allocator;
    }
};

struct D40A10Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float unk10;
    int unk14;
    int unk18;
    int unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float FUN_00d571a0();
};

struct D40A10Node
{
    int unk00;
    short unk04;
    short unk06;
    int unk08;
    int unk0c;
    D40A10Node* FUN_00d22590(float* p1, float* p2, float val);
};

struct D40A10Entry
{
    D40A10Node* m_node;
    int m_uiEdgeIndex;
    int m_data;
    FNVTypeRecord* m_record;

    D40A10Entry(FNVTypeRecord* rec, int data)
    {
        m_record = rec;
        m_data = data;
    }
};

// For i in 0..1: if a[i] is set, builds a node via FUN_00d22590 into out[i], saves the object's old record in b[i] and replaces it with out[i]; else b[i] = 0.
// @fnv 0x00d40a10
// src: HAVOK_LIB 0x00d40a10
static __declspec(noinline) void replaceCylindersWithCapsulesInCdBodies(int* a, FNVTypeRecord** apRecords, FNVObject** apObjects,
                                              D40A10Entry* out)
{
    FNVObject**& list = apObjects;
    D40A10Entry*& dst = out;
    for (int i = 0; i < 2; ++dst, ++i)
    {
        if (a[i] != 0)
        {
            D40A10Shape* shape = (D40A10Shape*)list[i]->record->unknown0;
            D40A10Node* node = (D40A10Node*)((D40A10Holder*)hkMemoryRouter_getInstance())->heap().allocate(0x40);
            node->unk04 = 0x40;
            float t = shape->unk10;
            float val = t + shape->FUN_00d571a0() + DAT_010cf218;
            D40A10Node* pResult = node->FUN_00d22590(&shape->unk20, &shape->unk30, val);
            new (dst) D40A10Entry(list[i]->record, list[i]->record->unknown8);
            dst->m_node = pResult;
            dst->m_uiEdgeIndex = -1;
            apRecords[i] = list[i]->record;
            list[i]->record = (FNVTypeRecord*)dst;
        }
        else
        {
            apRecords[i] = 0;
        }
    }
}

void D40A10Caller(int* a, FNVTypeRecord** b, FNVObject** objs, D40A10Entry* out)
{
    replaceCylindersWithCapsulesInCdBodies(a, b, objs, out);
}
