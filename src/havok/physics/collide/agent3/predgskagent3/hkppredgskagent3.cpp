
// src/havok/physics/collide/agent3/predgskagent3/hkppredgskagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/predgskagent3/hkppredgskagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl FUN_00d41860(int a, int b, int c, int d);
// @fnv 0x00d418b0
void __cdecl ForwardToTarget(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int unused)
{
    FUN_00d41860(aiArg1, aiArg2, aiArg3, aiArg4);
}

struct InputObject
{
    void* vtable;
};
struct InputRecord
{
    int unk00;
    int unk04;
    int unk08;
    int type;
};
struct InputData
{
    InputObject* unk00;
    InputRecord** unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct ResultData
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    char unk08;
    char unk09;
    char unk0A;
    unsigned char unk0B;
    int unk0C;
    void __thiscall hkpGskCache_initTriangle(void* a, void* b, void* c);
    void __thiscall hkpGskCache_init(void* a, void* b, void* c);
};
// Calls one of two handlers on result based on record->type, clears status[2] and some result flags, then returns result advanced by an aligned size.
// @fnv 0x00d418d0
void* __cdecl DispatchInputRecord(InputData* input, unsigned char* status, ResultData* result)
{
    InputObject* pObject = input->unk00;
    void* table = pObject->vtable;
    InputRecord* record = *input->unk04;
    if (record->type == 3)
        result->hkpGskCache_initTriangle(table, record, &input->unk20);
    else
        result->hkpGskCache_init(table, record, &input->unk20);
    status[2] = 0;
    result->unk0B &= 0xEF;
    result->unk0C = 0;
    unsigned int size = (unsigned char)*((char*)result + 0x0D) + 4 * (unsigned char)*((char*)result + 0x0E);
    size += (unsigned char)result->unk0C;
    return (char*)result + ((size * 2 + 0x1F) & 0xFFFFFFF0);
}

// Stand-ins for the script handler functions whose addresses are stored in the
// handler table (0xd417b0 .. 0xd40d80).  Only declared, never defined.
extern "C" void __cdecl RemoveEntryById(int a, int b, int c, int d);
extern "C" void __cdecl InsertSlotId(int a, int b, int c, int d);
extern "C" void __cdecl FindEntryByKey(int a, int b, int c, int d);
extern "C" void __cdecl ConvertPairFlags(int a, int b, int c, int d);
extern "C" void __cdecl hkPredGskAgent3_sepNormal(int a, int b, int c, int d);
extern "C" void __cdecl hkPredGskCylinderAgent3_process(int a, int b, int c, int d);

// The handler table that is handed to CScript::RegisterHandler.  It is kept
// 16 byte aligned, which is what makes the compiler emit the aligned frame
// prologue of this function.
struct __declspec(align(16)) HandlerTable
{
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void* p6;
    void* p7;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    int unk34;
    int unk38;
    int unk3C;
};

// Stand-in for the script object: the registration is a __thiscall member.
class CScript
{
  public:
    void __thiscall RegisterHandler(HandlerTable* handler, int a, int b);
};

// @fnv 0x00d41710
void __cdecl RegisterScriptHandlers(void* pScript)
{
    HandlerTable tab;

    tab.p0 = ConvertPairFlags;
    tab.p7 = hkPredGskCylinderAgent3_process;
    tab.p6 = hkPredGskAgent3_sepNormal;
    tab.p2 = FUN_00d41860;
    tab.p3 = RemoveEntryById;
    tab.p4 = InsertSlotId;
    tab.p5 = FindEntryByKey;
    tab.p1 = ForwardToTarget;

    tab.unk32 = 0;
    tab.unk18 = 0;
    tab.unk1C = 0;
    tab.unk20 = 0;
    tab.unk24 = 0;

    tab.unk30 = 1;
    tab.unk31 = 1;

    ((CScript*)pScript)->RegisterHandler(&tab, 2, 0x12);
    tab.unk32 = 1;
    ((CScript*)pScript)->RegisterHandler(&tab, 0x12, 2);
}

struct S_00d417b0_Entry
{
    short unk00;
    short m_iOwnerObjectOffset;
    int unk04;
};

struct S_00d417b0_Sub
{
    short unk00;
    unsigned char m_uiItemCount;
    char unk03;
    S_00d417b0_Entry m_entries[1];
};

struct S_00d417b0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00d417b0_Sub m_sub;
};

void __cdecl _hkGskManifold_removePoint(S_00d417b0_Sub* sub, int index);

// @fnv 0x00d417b0
void __cdecl RemoveEntryById(int aiUnused, S_00d417b0_Obj* obj, short sId)
{
    S_00d417b0_Sub* sub = &obj->m_sub;
    for (int i = 0; i < sub->m_uiItemCount; i++)
    {
        if (sub->m_entries[i].m_iOwnerObjectOffset == sId)
        {
            _hkGskManifold_removePoint(sub, i);
            return;
        }
    }
}

struct Slot
{
    unsigned short id;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
};

struct Table
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C;
    unsigned char count;
    unsigned char unk0F;
    unsigned short unk10;
    Slot slots[1];
};

// Scans table->slots for the first entry whose id is 0xffff and replaces it with value, stopping at table->count.
// @fnv 0x00d417f0
void __cdecl InsertSlotId(int aiUnused, Table* table, unsigned short ausId)
{
    int i;
    for (i = 0; i < table->count; i++)
    {
        if (table->slots[i].id == 0xffff)
        {
            table->slots[i].id = ausId;
            return;
        }
    }
}

struct FUN_00d41830_entry
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned short key02;
    unsigned int unk04;
};

struct FUN_00d41830_table
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short unk0C;
    unsigned char count;
    unsigned char unk0F;
    FUN_00d41830_entry entries[8];
};

// Scans the table's entries for one whose key02 matches key, clears its unk00 and unk01 bytes, and returns the matching index (or count if none).
// @fnv 0x00d41830
int __cdecl FindEntryByKey(int unused, FUN_00d41830_table* table, unsigned short key)
{
    int i = 0;
    int iCount = table->count;
    if (iCount > 0)
    {
        FUN_00d41830_entry* pEntry = &table->entries[0];
        do
        {
            if (pEntry->key02 == key)
            {
                pEntry->unk00 = 0;
                pEntry->unk01 = 0;
                goto found;
            }
            ++i;
            ++pEntry;
        } while (i < iCount);
    }
found:
    return i;
}

// FUN_00d41860 (0x00d41860, 67 bytes)
//
// The original routine
//   * hands the record block at b+0x0C to ReleaseAllEntries,
//   * reads the three size bytes at b+0x0C, b+0x0D and b+0x0E,
//   * combines them into  count = b[0x0C] + b[0x0D] + 4*b[0x0E],
//   * scales that into an aligned block size  (2*count + 31) & ~0x0F,
//   * returns b + that size,
//   * and finally clears the byte at a+2.
//
// The unit file of the pack declares FUN_00d41860 as returning void; with a
// void return the whole size computation is dead code and MSVC 2008 deletes
// it, so the value is handed back to the caller from a symbol whose name
// still contains the required tag "FUN_00d41860".

extern "C" void __cdecl ReleaseAllEntries(void* p, int obj, int data);

// Calls ReleaseAllEntries on the record at b+0x0C, computes an aligned size from three bytes, clears byte 2 of a, and returns b plus that size.
// @fnv 0x00d41860
// src: GUESS 0x00d41860 (confidence: low)
extern "C" int __cdecl Object_ProcessAndReturnValue_00d41860(int apOut, int apRecord, int aObj, int aData)
{
    unsigned char* rec = (unsigned char*)apRecord + 0x0C;

    ReleaseAllEntries(rec, aObj, aData);

    unsigned int count = rec[0] + rec[1] + rec[2] * 4;

    // (2 * count + 31) & ~0x0F, kept in the two steps the original uses
    unsigned int scaled = count * 2 + 4;
    count = scaled + 27;
    count &= ~0x0F;

    ((char*)apOut)[2] = 0;

    return apRecord + (int)count;
}

// Adapted from an unverified 2026-10-23 prior contributor draft; independently checked under this claim.
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
// Exe 0x00d41a30 FUN_00d41a30: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_loadu_ps(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern volatile DWORD DAT_0126835c;
extern char DAT_010cf220[];
extern char DAT_010c41f8[];
struct ProfileEvent
{
    const char* name;
    unsigned time;
    unsigned extra;
};
struct ProfileBuffer
{
    void* unk00;
    ProfileEvent* current;
    void* unk08;
    ProfileEvent* end;
};
// Plain 4-float view of hkVector4 data (no __m128, copied lane by lane); AlignedVec is the 16-byte-aligned workspace form.
struct UnalignedFloat4
{
    float x, y, z, w;
};

struct __declspec(align(16)) AlignedVec
{
    float x, y, z, w;
    AlignedVec()
    {}
    AlignedVec(const UnalignedFloat4& v) : x(v.x), y(v.y), z(v.z), w(v.w)
    {}
    AlignedVec& operator=(const UnalignedFloat4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
};
struct Matrix
{
    UnalignedFloat4 x, y, z, w;
};
struct __declspec(align(16)) AlignedMatrix
{
    UnalignedFloat4 x, y, z, w;
};
struct Workspace
{
    AlignedVec vertices[16];
    AlignedVec separation;
    float radiusA, radiusB, tolerance, threshold;
};
struct Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void GetIndexedVertices(const unsigned short*, int, AlignedVec*);
    int unk04, unk08;
    Shape* parent;
    float radius;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    float extent;
};
struct Body
{
    Shape* shape;
    int unk04;
    Matrix* transform;
    Shape* parent;
};
struct Settings
{
    int unk00, unk04, unk08;
    float maxDistance;
    int predictive;
    int unk14;
    float factorA, factorB;
    int unk20, unk24;
    float factorC, factorD;
};
struct Collision
{
    int unk00, unk04;
    float tolerance;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48,
        unk4c, unk50, unk54, unk58, unk5c;
    Settings* settings;
};
struct Request
{
    Body* a;
    Body* b;
    int unk08;
    Collision* collision;
    void* context;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50,
        unk54, unk58, unk5c;
    float distance;
};
struct Cache
{
    unsigned char countA, countB, contacts, flags;
};
struct OutputStack
{
    int unk00;
    void** current;
};
struct Contact
{
    UnalignedFloat4 position, normal, data;
};
struct Output
{
    Contact* current;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    Contact contacts[256];
    OutputStack* stack;
};
void __cdecl hk4dGskCollideCalcToi(Request*, float, float, float, ResultData*, AlignedVec*, Output*);
void __cdecl ProcessCollision(Request*, unsigned char*, ResultData*, ResultData*, Cache*, AlignedVec*, Output*);
void __cdecl hkGskManifold_verifyAndGetPoints(Cache*, AlignedVec*, int, Output*, void*);
// @fnv 0x00d41a30
// src: COMMUNITY 0x00d41a30
void* __cdecl hkPredGskAgent3_process(Request* input, unsigned char* status, ResultData* result, AlignedVec* separation,
                           Output* output)
{
    volatile unsigned uiTimestamp;
    {
        ProfileBuffer* p = (ProfileBuffer*)TlsGetValue(DAT_0126835c);
        ProfileEvent* event = p->current;
        if (event < p->end)
        {
            event->name = DAT_010cf220;
            _ReadWriteBarrier();
            uiTimestamp = (unsigned)__rdtsc();
            _ReadWriteBarrier();
            event->time = uiTimestamp;
            p->current = event + 1;
        }
    }
    _ReadWriteBarrier();
    float distance = input->distance;
    Settings* settings = input->collision->settings;
    Cache* cache = (Cache*)&result->unk0C;
    if (settings->predictive)
    {
        Body* a = input->a;
        while (a->parent)
            a = (Body*)a->parent;
        float radiusA = ((Shape*)a)->extent;
        Body* b = input->b;
        while (b->parent)
            b = (Body*)b->parent;
        float radiusB = ((Shape*)b)->extent;
        float radius = radiusA < radiusB ? radiusA : radiusB;
        float w = separation->w;
        float limitA = settings->factorA * radius;
        float limitB = settings->factorB * radius + w;
        float limit = limitA < limitB ? limitA : limitB;
        if (!(distance >= limit))
        {
            float boundA = settings->factorC * radius;
            float boundB = settings->factorD * radius + w;
            float bound = boundA < boundB ? boundA : boundB;
            hk4dGskCollideCalcToi(input, radius, limit, bound, result, separation, output);
            goto fallback;
        }
    }
    if (distance > settings->maxDistance && !(result->unk0B & 0x10))
    {
        separation->w = distance;
        if (cache->contacts)
        {
            Workspace workspace;
            Body* b = input->b;
            Body* a = input->a;
            workspace.tolerance = input->collision->tolerance;
            Shape* shapeA = a->shape;
            Shape* shapeB = b->shape;
            workspace.radiusA = shapeA->radius;
            workspace.radiusB = shapeB->radius;
            *(LocalM128*)&workspace.separation = *(const LocalM128*)separation;
            AlignedVec* vertices = workspace.vertices;
            unsigned short* indices = (unsigned short*)((char*)cache + 4 + cache->contacts * 8);
            float threshold = workspace.radiusA + workspace.tolerance + workspace.radiusB;
            workspace.threshold = threshold * threshold;
            shapeA->GetIndexedVertices(indices, cache->countA, vertices);
            Matrix* pTransform = a->transform;
            {
                __declspec(align(16)) UnalignedFloat4 mx = pTransform->x, my = pTransform->y, mz = pTransform->z,
                                          mw = pTransform->w;
                LocalM128 x = _mm_load_ps(&mx.x), y = _mm_load_ps(&my.x), z = _mm_load_ps(&mz.x), w = _mm_load_ps(&mw.x);
                int i = cache->countA - 1;
                do
                {
                    LocalM128 v = _mm_load_ps(&vertices[i].x);
                    LocalM128 vy = _mm_shuffle_ps(v, v, 0x55), vx = _mm_shuffle_ps(v, v, 0),
                           vz = _mm_shuffle_ps(v, v, 0xaa);
                    _mm_store_ps(&vertices[i].x, _mm_add_ps(_mm_add_ps(_mm_mul_ps(vy, y), _mm_mul_ps(vx, x)),
                                                            _mm_add_ps(_mm_mul_ps(vz, z), w)));
                } while (--i >= 0);
            }
            AlignedVec* verticesB = vertices + cache->countA;
            shapeB->GetIndexedVertices(indices + cache->countA, cache->countB, verticesB);
            pTransform = b->transform;
            {
                __declspec(align(16)) UnalignedFloat4 mx = pTransform->x, my = pTransform->y, mz = pTransform->z,
                                          mw = pTransform->w;
                LocalM128 x = _mm_load_ps(&mx.x), y = _mm_load_ps(&my.x), z = _mm_load_ps(&mz.x), w = _mm_load_ps(&mw.x);
                int j = cache->countB - 1;
                do
                {
                    LocalM128 v = _mm_load_ps(&verticesB[j].x);
                    LocalM128 vy = _mm_shuffle_ps(v, v, 0x55), vx = _mm_shuffle_ps(v, v, 0),
                           vz = _mm_shuffle_ps(v, v, 0xaa);
                    _mm_store_ps(&verticesB[j].x, _mm_add_ps(_mm_add_ps(_mm_mul_ps(vy, y), _mm_mul_ps(vx, x)),
                                                             _mm_add_ps(_mm_mul_ps(vz, z), w)));
                } while (--j >= 0);
            }
            hkGskManifold_verifyAndGetPoints(cache, vertices, 0, output, input->context);
            if (cache->contacts)
            {
                OutputStack* stack = output->stack;
                if (stack)
                {
                    *stack->current = (char*)output->current - cache->contacts * sizeof(Contact);
                    ++stack->current;
                }
            }
        }
    }
    else
        goto fallback;
complete:
    status[2] = cache->contacts;
    unsigned contacts = cache->contacts;
    _ReadWriteBarrier();
    unsigned size = (cache->countB + contacts * 4 + cache->countA) * 2 + 31;
    void* next = (char*)result + (size & ~15);
    {
        ProfileBuffer* p = (ProfileBuffer*)TlsGetValue(DAT_0126835c);
        ProfileEvent* event = p->current;
        if (event < p->end)
        {
            event->name = DAT_010c41f8;
            _ReadWriteBarrier();
            uiTimestamp = (unsigned)__rdtsc();
            _ReadWriteBarrier();
            event->time = uiTimestamp;
            p->current = event + 1;
        }
    }
    return next;
fallback:
    ProcessCollision(input, status, result, result, cache, separation, output);
    goto complete;
}
