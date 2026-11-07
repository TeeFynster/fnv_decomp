
// src/havok/physics/internal/collide/mopp/machine/hkpmoppkdopgeometriesvirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppkdopgeometriesvirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkVector4.h"


static inline hkBool& AssignMoppFlag(hkBool& flag, bool value)
{
    static_cast<volatile char&>(flag.m_cBooleanValue) = static_cast<char>(value);
    return flag;
}

struct __declspec(align(16)) E5CF70Solver
{
    E5CF70Solver();
    ~E5CF70Solver();

    __declspec(nothrow) void solve(void* a, void* b, void* c);

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
    int unkCC;
};

// Constructs an E5CF70Solver on the stack and forwards the three arguments to its solve method.
// @fnv 0x00e5cf70
void __cdecl SolveWithSolver(void* a, void* b, void* c)
{
    E5CF70Solver solver;
    solver.solve(a, b, c);
}

// Exe 0x00e65040: unit-local Vector4f view; declarations and layout are preserved.
struct HkpmoppkdopgeometriesvirtualmachineVector4fView
{
    int a;
    int b;
    int c;
    int d;
};
struct Block
{
    HkpmoppkdopgeometriesvirtualmachineVector4fView q0;
    HkpmoppkdopgeometriesvirtualmachineVector4fView q1;
    HkpmoppkdopgeometriesvirtualmachineVector4fView q2;
    HkpmoppkdopgeometriesvirtualmachineVector4fView RunFourthVirtual;
    HkpmoppkdopgeometriesvirtualmachineVector4fView InvokeFifthVirtualFunction;
    HkpmoppkdopgeometriesvirtualmachineVector4fView q5;
    int e0;
    int e1;
};
struct Entry
{
    Block data;
    int unk68;
    char unk6c;
    char unk6d;
};
struct Flag
{
    char v;
};
struct Cls
{
    HkpmoppkdopgeometriesvirtualmachineVector4fView h0;
    HkpmoppkdopgeometriesvirtualmachineVector4fView h1;
    HkpmoppkdopgeometriesvirtualmachineVector4fView h2;
    HkpmoppkdopgeometriesvirtualmachineVector4fView h3;
    Entry* cursor;
    Block current;
    char flag;
    void hkpMoppKDopGeometriesVirtualMachine_pushKDop(Flag a, int b);
};
// Writes the flag, optional value, current block and flag byte into the entry at cursor, then advances cursor.
// @fnv 0x00e65040
// src: HAVOK_LIB 0x00e65040
void Cls::hkpMoppKDopGeometriesVirtualMachine_pushKDop(Flag aFlag, int b)
{
    Entry* e = cursor;
    e->unk6d = aFlag.v;
    if (aFlag.v)
    {
        e->unk68 = b;
    }
    e->unk6c = flag;
    e->data = current;
    cursor = cursor + 1;
}

struct S_00e65e70
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
    char unkB0;
    char unkB1;
    char unkB2;
    char unkB3;
    int unkB4;
    char unkB8;
    char unkB9;
    char unkBA;
    char unkBB;
    int unkBC;

    S_00e65e70* Reset();
};

// @fnv 0x00e65e70
S_00e65e70* S_00e65e70::Reset()
{
    unk34 = 0;
    unk38 = 0;
    unk3C = 0x80000000;
    unkB0 = 0;
    unkB4 = -1;
    unkB8 = 0;
    unkBC = 0;
    return this;
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00e65ea0_cls
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
    void* m_pData;
    unsigned int m_uCount;
    unsigned int m_uiObjectFlags;

    void ClearArray();
};

// Frees the data array through the audio allocator when the high flag bit is clear, then resets the pointer, count and flag.
// @fnv 0x00e65ea0
void FUN_00e65ea0_cls::ClearArray()
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uFlags = m_uiObjectFlags;
    m_uCount = 0;
    if ((uFlags & 0x80000000u) == 0)
    {
        unsigned int uCount = uFlags & 0x3fffffffu;
        pAllocator->bufFree(m_pData, uCount * 4u);
    }
    m_pData = 0;
    m_uiObjectFlags = 0x80000000u;
}

void __cdecl ResizeAudioStream(void* allocator, void* list, unsigned int stride);

template <class T> inline void CopyConstruct(T* dst, int count, const T& value)
{
    for (int i = 0; i < count; ++i)
        dst[i] = value;
}
struct ItemList
{
    void** data;
    int count;
    unsigned int capacity;
    int indexOf(void* item) const
    {
        for (int i = 0; i < count; ++i)
            if (data[i] == item)
                return i;
        return -1;
    }
    void AddBack(void* const& value)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        if (count == (int)(capacity & 0x3fffffff))
            ResizeAudioStream(holder->m_heap, this, 4);
        CopyConstruct(data + count, 1, value);
        ++count;
    }
};

struct FlagArg
{
    bool b;
    FlagArg(bool x) : b(x)
    {}
    FlagArg(const FlagArg& o) : b(o.b)
    {}
};
struct FUN_00e65080_cls
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
    unsigned int unk30;
    ItemList m_34;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    bool m_b0;
    unsigned char unkB1;
    unsigned char unkB2;
    unsigned char unkB3;
    unsigned int unkB4;
    unsigned char m_b8;
    unsigned char unkB9;
    unsigned char unkBA;
    unsigned char unkBB;
    void* m_bc;
    unsigned char m_c0;

    void hkpMoppKDopGeometriesVirtualMachine_pushKDop(FlagArg flag, void* item);
    void hkpMoppKDopGeometriesVirtualMachine_addHit(void* item, unsigned int unused);
};

// Adds item to m_34 if absent, calls FUN_00e65040 when m_b8 is clear or item matches m_bc, and sets m_c0 when m_b0 is true.
// @fnv 0x00e65080
// src: HAVOK_LIB 0x00e65080
void FUN_00e65080_cls::hkpMoppKDopGeometriesVirtualMachine_addHit(void* item, unsigned int unused)
{
    if (m_34.indexOf(item) == -1)
    {
        unsigned char flagB8 = m_b8;
        bool selected = flagB8 != 0 && item == m_bc;
        if (flagB8 == 0 || selected)
        {
            hkpMoppKDopGeometriesVirtualMachine_pushKDop(FlagArg(true), item);
            bool result = m_b0 || selected;
            m_b0 = result;
        }
        m_34.AddBack(item);
    }
    if (m_b0)
        m_c0 = 1;
}

extern double const DAT_01091c00;
extern double const DAT_01011590;
struct E65Range
{
    float m_kMinimumCorner;
    float m_kMaximumCorner;
};
struct E65Input
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_vec;
    int unk20;
};
struct E65Key
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct E65Out
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct E65Solver
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_invMass;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_vec;
    int m_uiEdgeIndex;
    int unk34;
    int unk38;
    int unk3C;
    int m_kIntegerDataBlock;
    E65Range m_ranges[13];
    int unkAC;
    E65Key m_key;
    hkBool m_flag;
    void hkpMoppKDopGeometriesVirtualMachine_queryMoppKDopGeometriesRecurse(E65Out* out, int v);
    void ProcessEntries_00e65d90(E65Input* in, E65Key* key, int param);
};
// @fnv 0x00e65d90
// src: GUESS 0x00e65d90 (confidence: low)
void E65Solver::ProcessEntries_00e65d90(E65Input* apInput, E65Key* __restrict key, int aiDataBlock)
{
    m_kIntegerDataBlock = aiDataBlock;
    E65Out out;
    out.unk00 = 0;
    out.unk04 = 0;
    out.unk08 = 0;
    out.unk0C = 0;
    out.unk10 = 0;
    m_invMass = 1.0f / apInput->m_vec.m_vComponents.m128_f32[3];
    m_vec.m_vComponents = apInput->m_vec.m_vComponents;
    AssignMoppFlag(m_flag, false);
    float t = (float)(m_invMass * DAT_01091c00);
    E65Key* __restrict pKey = &m_key;
    pKey->unk00 = *(volatile int*)&key->unk00;
    pKey->unk04 = key->unk04;
    *(volatile int*)&pKey->unk08 = key->unk08;
    float lo = (float)(-t * DAT_01011590);
    float hi = (float)(t * DAT_01011590);
    pKey->unk0C = *(volatile int*)&key->unk0C;
    m_uiEdgeIndex = -1;
    unkAC = 0;
    for (int i = 0; i < 13; i++)
    {
        m_ranges[i].m_kMinimumCorner = lo;
        m_ranges[i].m_kMaximumCorner = hi;
    }
    int v = *(volatile int*)&apInput->unk20;
    out.unk14 = 0;
    hkpMoppKDopGeometriesVirtualMachine_queryMoppKDopGeometriesRecurse(&out, v);
}

struct DecodedParts
{
    unsigned high, last, mid;
    DecodedParts(const unsigned char* p) : high((p[1] << 8) + p[2]), mid(p[3]), last(p[4])
    {
        high <<= 16;
        mid <<= 8;
    }
    unsigned get()
    {
        last += high;
        return last + mid;
    }
};
struct MoppState
{

    unsigned int primitiveOffset;

    unsigned int properties[1];
};

struct MoppResults
{

    unsigned int* data;

    int size;

    int capacityAndFlags;
};

struct HavokMemory
{

    void* router;

    void* temporary;

    void* heap;

    void* debug;

    void* allocator;
};

struct MoppErrorStream
{

    void* vtable;

    unsigned short memorySizeAndFlags;

    unsigned short referenceCount;

    void* writer;

    void FUN_00cb1600(char*, int);

    void ProcessAndReturnValue_00cc01c0(const char*);

    void FUN_00cc00e0();
};

struct MoppError
{

    virtual void destroy();

    virtual void SetErrorCodeEnabled(int, bool);

    virtual bool isEnabled(int);

    virtual int message(int, int, const char*, const char*, int);
};

extern int DAT_01268360;

struct hkpMoppFindAllVirtualMachine
{

    MoppResults* results;

    void queryOnTree(const MoppState* state, const unsigned char* code);
};

// Interprets a MOPP bytecode stream, updating primitiveOffset and properties, and appends decoded primitive indices to results.
// @fnv 0x00e65ee0
// src: HAVOK_LIB 0x00e65ee0
void hkpMoppFindAllVirtualMachine::queryOnTree(const MoppState* state, const unsigned char* code)

{

    MoppState localState;

    unsigned int primitiveIndex;

    for (;;)
    {

        unsigned int command = *code;

        switch (command)
        {

        case 0:
            return;

        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:

        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:

        case 0x1a:
        case 0x1b:
        case 0x1c:

        {

            unsigned int secondOffset = code[3];

            code += 4;

            queryOnTree(state, code);

            code += secondOffset;
            continue;
        }

        case 0x20:
        case 0x21:
        case 0x22:

        {

            unsigned int secondOffset = code[2];

            code += 3;

            queryOnTree(state, code);

            code += secondOffset;
            continue;
        }

        case 0x23:
        case 0x24:
        case 0x25:

        {

            unsigned int firstOffset = (code[3] << 8) + code[4];

            unsigned int secondOffset = (code[5] << 8) + code[6];

            code += 7;

            queryOnTree(state, code + firstOffset);

            code += secondOffset;
            continue;
        }

        case 0x29:
        case 0x2a:
        case 0x2b:

            code += 7;
            continue;

        case 5:

            code += code[1] + 2;
            continue;

        case 6:

            code += (code[1] << 8) + code[2] + 3;
            continue;

        case 7:

            code += ((code[1] << 8) + code[2] << 8) + code[3] + 4;
            continue;

        case 1:
        case 2:
        case 3:
        case 4:

            code += 4;
            continue;

        case 0x26:
        case 0x27:
        case 0x28:

            code += 3;
            continue;

        case 9:

        {

            unsigned int offset = code[1];

            if (state != &localState)
            {
                localState = *state;
                state = &localState;
            }

            localState.primitiveOffset += offset;

            code += 2;
            continue;
        }

        case 10:

        {

            unsigned int offset = (code[1] << 8) + code[2];

            if (state != &localState)
            {
                localState = *state;
                state = &localState;
            }

            localState.primitiveOffset += offset;

            code += 3;
            continue;
        }

        case 11:

        {

            unsigned int offset = ((((code[1] << 8) + code[2]) << 8) + code[3] << 8) + code[4];

            if (state != &localState)
            {
                localState = *state;
                state = &localState;
            }

            localState.primitiveOffset = offset;

            code += 5;
            continue;
        }

        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:

        {
            unsigned int value = code[1];
            code += 2;
            localState.properties[command - 0x60] = value;
        }

            goto property;

        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:

            localState.properties[command - 0x64] = (code[1] << 8) + code[2];

            code += 3;
            goto property;

        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b:

            localState.properties[command - 0x68] = ((((code[1] << 8) + code[2]) << 8) + code[3] << 8) + code[4];

            code += 5;

        property:

        {

            unsigned int propertyValue = localState.properties[0];

            if (state != &localState)
            {
                localState = *state;
                state = &localState;
            }

            localState.properties[0] = propertyValue;

            continue;
        }

        default:

        {

            int errorBuffer[128];

            MoppErrorStream errorStream;

            errorStream.FUN_00cb1600(reinterpret_cast<char*>(errorBuffer), sizeof(errorBuffer));

            errorStream.ProcessAndReturnValue_00cc01c0(
                "Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");

            if (reinterpret_cast<MoppError*>(DAT_01268360)
                    ->message(3, 0x1298fedd, reinterpret_cast<char*>(errorBuffer),
                              ".\\Collide\\Mopp\\Machine\\hkpMoppFindAllVirtualMachine.cpp", 113))

                __debugbreak();

            errorStream.FUN_00cc00e0();

            continue;
        }

        case 0x50:

            primitiveIndex = code[1];
            goto append;

        case 0x51:

            primitiveIndex = (code[1] << 8) + code[2];
            goto append;

        case 0x52:

            primitiveIndex = ((code[1] << 8) + code[2] << 8) + code[3];
            goto append;

        case 0x53:

        {
            DecodedParts d(code);
            primitiveIndex = d.get();
            goto append;
        }

        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:

        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:

        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:

        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:

        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:

        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:

        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:

        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:

            primitiveIndex = command - 0x30;
            goto append;
        }
    }

append:

    primitiveIndex += state->primitiveOffset;

    MoppResults* output = results;

    hkMemoryRouter* memory = hkMemoryRouter_getInstance();

    if (output->size == (output->capacityAndFlags & 0x3fffffff))

        ResizeAudioStream(memory->m_heap, output, sizeof(unsigned int));

    unsigned int* dst = output->data + output->size;
    output->size++;
    *dst = primitiveIndex;
}

extern "C" void __cdecl __debugbreak(void);

struct S_00e65140_Query
{
    int m_offset[3];                // 00
    int m_iIndex;                   // 0c
    int m_uiPropertyCount;          // 10
    unsigned int m_kProperties[1];  // 14
};

struct S_00e65140_KDop
{
    float m_kMinimumCorner;
    float m_kMaximumCorner;
};

struct S_00e65140_Out
{
    S_00e65140_KDop m_kKDopNodes[13];  // 00
    int m_key;                         // 68
    char m_depth;                      // 6c
    char m_isLeaf;                     // 6d
};

struct S00e65140_Dop
{
    enum DOP_AXIS
    {
        AXIS_X = 0
    };
    float m_fFirstValue, m_fSecondFloatOfFirstPair;
    float m_fLowProjection1, m_fSecondFloatOfSecondPair;
    float m_fLowProjection2, m_fThirdValue;
    float m_fLowProjection3, m_fHighProjection3;
    float m_fLowProjection4, m_fHighProjection4;
    float m_fLowProjection5, m_fHighProjection5;
    float m_fLowProjection6, m_fHighProjection6;
    float m_fLowProjection7, m_fHighProjection7;
    float m_fLowProjection8, m_fHighProjection8;
    float m_fLowProjection9, m_fHighProjection9;
    float m_fLowProjection10, m_fHighProjection10;
    float m_fLowProjection11, m_fHighProjection11;
    float m_fLowProjection12, m_fHighProjection12;

    float getLow(int i) const
    {
        return (&m_fFirstValue)[i * 2];
    }
    float getHigh(int i) const
    {
        return (&m_fSecondFloatOfFirstPair)[i * 2];
    }
    void setLow(int i, float l)
    {
        (&m_fFirstValue)[i << 1] = l;
    }
    void setHigh(int i, float h)
    {
        (&m_fSecondFloatOfFirstPair)[i << 1] = h;
    }
};

static inline float S00e65140_shiftDopLow(S00e65140_Dop& dop, S00e65140_Dop::DOP_AXIS axis, float v)
{
    float old = dop.getLow(axis);
    dop.setLow(axis, v);
    return old;
}

static inline float S00e65140_shiftDopHigh(S00e65140_Dop& dop, S00e65140_Dop::DOP_AXIS axis, float v)
{
    float old = dop.getHigh(axis);
    dop.setHigh(axis, v);
    return old;
}

static inline void S00e65140_doubleCut(S00e65140_Dop& dop, S00e65140_Dop::DOP_AXIS axis, float lo, float hi,
                                       float& oldLo, float& oldHi)
{
    oldLo = dop.getLow(axis);
    oldHi = dop.getHigh(axis);
    dop.setLow(axis, lo);
    dop.setHigh(axis, hi);
}

static inline int S00e65140_read24(const unsigned char* PC)
{
    int v = (PC[0] << 16) + (PC[1] << 8) + PC[2];
    return v;
}

struct S_00e65140_VM
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_vScale;  // 10
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_primitiveId;  // 30
    int unk34;
    int unk38;
    int unk3c;
    S_00e65140_Out* m_out;  // 40
    union
    {
        S_00e65140_KDop m_kKDopNodes[13];
        S00e65140_Dop m_kDop;
    };                // 44
    int m_depth;      // ac
    char m_b0;        // b0
    int m_iNumNodes;  // b4
    char m_b8;        // b8
    int unkbc;        // bc
    char m_abort;     // c0

    void hkpMoppKDopGeometriesVirtualMachine_pushKDop(FlagArg isLeaf, int key);
    void hkpMoppKDopGeometriesVirtualMachine_addHit(int key, const unsigned int* properties);
    void hkpMoppKDopGeometriesVirtualMachine_queryMoppKDopGeometriesRecurse(const S_00e65140_Query* query, const unsigned char* PC);
};

// Executes a Mopp byte-code stream, updating the DOP bounds and recording primitive hits via FUN_00e65080.
// @fnv 0x00e65140
// src: HAVOK_LIB 0x00e65140
void S_00e65140_VM::hkpMoppKDopGeometriesVirtualMachine_queryMoppKDopGeometriesRecurse(const S_00e65140_Query* query, const unsigned char* PC)
{
    S_00e65140_Query scaledQuery;
    int axis;
    int queryAxis;
    int offset;
    unsigned int rightOffset;
    float splitMin;
    float splitMax;

    for (unsigned int command = *PC; !m_abort; command = *PC)
    {
        switch (command)
        {
        case 5:
            offset = PC[1];
            PC += 2;
            PC += offset;
            continue;
        case 6:
            rightOffset = PC[1];
            offset = PC[2];
            PC += 3;
            PC += (rightOffset << 8) + offset;
            continue;
        case 7: {
            rightOffset = PC[1];
            const int mid = PC[2];
            offset = PC[3];
            PC += 4;
            PC += (rightOffset << 16) + (mid << 8) + offset;
            continue;
        }
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            scaledQuery.m_offset[0] = (PC[1] << (16 - query->m_iIndex)) + query->m_offset[0];
            scaledQuery.m_offset[1] = (PC[2] << (16 - query->m_iIndex)) + query->m_offset[1];
            scaledQuery.m_offset[2] = (PC[3] << (16 - query->m_iIndex)) + query->m_offset[2];
            scaledQuery.m_iIndex = query->m_iIndex + command;
            scaledQuery.m_kProperties[0] = query->m_kProperties[0];
            scaledQuery.m_uiPropertyCount = query->m_uiPropertyCount;
            query = &scaledQuery;
            PC += 4;
            continue;
        case 9: {
            const int add = PC[1];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount += add;
            PC += 2;
            continue;
        }
        case 0xa: {
            const int add = (PC[1] << 8) + PC[2];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount += add;
            PC += 3;
            continue;
        }
        case 0xb: {
            const int value = ((((((PC[1] << 8) + PC[2]) << 8) + PC[3]) << 8) + PC[4]);
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount = value;
            PC += 5;
            continue;
        }
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63: {
            const unsigned int propValue = PC[1];
            PC += 2;
            scaledQuery.m_kProperties[command - 0x60] = propValue;
        }
            goto propertyCopy;
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
            scaledQuery.m_kProperties[command - 0x64] = (PC[1] << 8) + PC[2];
            PC += 3;
            goto propertyCopy;
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b:
            scaledQuery.m_kProperties[command - 0x68] = ((((PC[1] << 8) + PC[2]) << 8) + PC[3] << 8) + PC[4];
            PC += 5;
        propertyCopy: {
            const unsigned int property = scaledQuery.m_kProperties[0];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_kProperties[0] = property;
        }
            continue;

        case 0x13: {
            const int shift = 16 - query->m_iIndex;
            const float off = float(query->m_offset[1] + query->m_offset[2]);
            float v = float((PC[1] * 2) << shift) + off;
            splitMax = v * m_vScale;
            v = off + ((PC[2] * 2) << shift);
            splitMin = v * m_vScale;
            rightOffset = PC[3];
            PC += 4;
            axis = 3;
            offset = 0;
            goto doSplit;
        }
        case 0x14: {
            const int shift = 16 - query->m_iIndex;
            const float off = float(query->m_offset[1] - query->m_offset[2]);
            float v = float((PC[1] * 2 - 0xff) << shift) + off;
            splitMax = v * m_vScale;
            v = off + ((PC[2] * 2 - 0xff) << shift);
            splitMin = v * m_vScale;
            rightOffset = PC[3];
            PC += 4;
            axis = 4;
            offset = 0;
            goto doSplit;
        }
        case 0x15: {
            const int shift = 16 - query->m_iIndex;
            const float off = float(query->m_offset[0] + query->m_offset[2]);
            float v = float((PC[1] * 2) << shift) + off;
            splitMax = v * m_vScale;
            v = off + ((PC[2] * 2) << shift);
            splitMin = v * m_vScale;
            rightOffset = PC[3];
            PC += 4;
            axis = 5;
            offset = 0;
            goto doSplit;
        }
        case 0x16: {
            const int shift = 16 - query->m_iIndex;
            const float off = float(query->m_offset[0] - query->m_offset[2]);
            float v = float((PC[1] * 2 - 0xff) << shift) + off;
            splitMax = v * m_vScale;
            v = off + ((PC[2] * 2 - 0xff) << shift);
            splitMin = v * m_vScale;
            rightOffset = PC[3];
            PC += 4;
            axis = 6;
            offset = 0;
            goto doSplit;
        }
        case 0x17: {
            const int shift = 16 - query->m_iIndex;
            const float off = float(query->m_offset[0] + query->m_offset[1]);
            float v = float((PC[1] * 2) << shift) + off;
            splitMax = v * m_vScale;
            v = off + ((PC[2] * 2) << shift);
            splitMin = v * m_vScale;
            rightOffset = PC[3];
            PC += 4;
            axis = 7;
            offset = 0;
            goto doSplit;
        }
        case 0x18: {
            const int shift = 16 - query->m_iIndex;
            const float off = float(query->m_offset[0] - query->m_offset[1]);
            float v = float((PC[1] * 2 - 0xff) << shift) + off;
            splitMax = v * m_vScale;
            v = off + ((PC[2] * 2 - 0xff) << shift);
            splitMin = v * m_vScale;
            rightOffset = PC[3];
            PC += 4;
            axis = 8;
            offset = 0;
            goto doSplit;
        }
        case 0x19: {
            const int shift = 16 - query->m_iIndex;
            const float off = float(query->m_offset[0] + query->m_offset[1] + query->m_offset[2]);
            float v = float((PC[1] * 3) << shift) + off;
            splitMax = v * m_vScale;
            v = off + ((PC[2] * 3) << shift);
            splitMin = v * m_vScale;
            rightOffset = PC[3];
            PC += 4;
            axis = 9;
            offset = 0;
            goto doSplit;
        }
        case 0x1a: {
            const int shift = 16 - query->m_iIndex;
            const float off = float(query->m_offset[0] + query->m_offset[1] - query->m_offset[2]);
            float v = float(((PC[1] - 0x55) * 3) << shift) + off;
            splitMax = v * m_vScale;
            v = off + (((PC[2] - 0x55) * 3) << shift);
            splitMin = v * m_vScale;
            rightOffset = PC[3];
            PC += 4;
            axis = 10;
            offset = 0;
            goto doSplit;
        }
        case 0x1b: {
            const int shift = 16 - query->m_iIndex;
            const float off = float(query->m_offset[0] - query->m_offset[1] + query->m_offset[2]);
            float v = float(((PC[1] - 0x55) * 3) << shift) + off;
            splitMax = v * m_vScale;
            v = off + (((PC[2] - 0x55) * 3) << shift);
            splitMin = v * m_vScale;
            rightOffset = PC[3];
            PC += 4;
            axis = 11;
            offset = 0;
            goto doSplit;
        }
        case 0x1c: {
            const int shift = 16 - query->m_iIndex;
            const float off = float(query->m_offset[0] - query->m_offset[1] - query->m_offset[2]);
            float v = float(((PC[1] - 0xaa) * 3) << shift) + off;
            splitMax = v * m_vScale;
            v = off + (((PC[2] - 0xaa) * 3) << shift);
            splitMin = v * m_vScale;
            rightOffset = PC[3];
            PC += 4;
            axis = 12;
            offset = 0;
            goto doSplit;
        }
        case 0x10:
        case 0x11:
        case 0x12: {
            queryAxis = command - 0x10;
            splitMax = float((PC[1] << (16 - query->m_iIndex)) + query->m_offset[queryAxis]) * m_vScale;
            splitMin = float((PC[2] << (16 - query->m_iIndex)) + query->m_offset[queryAxis]) * m_vScale;
            axis = queryAxis;
            PC += 4;
            offset = 0;
            rightOffset = PC[-1];
            goto doSplit;
        }
        case 0x20:
        case 0x21:
        case 0x22: {
            const int shift = 16 - query->m_iIndex;
            splitMin = float((PC[1] << shift) + query->m_offset[command - 0x20]);
            splitMax = splitMin + float(1 << shift);
            axis = command - 0x20;
            rightOffset = PC[2];
            PC += 3;
            offset = 0;
            splitMin *= m_vScale;
            splitMax = static_cast<const volatile float&>(m_vScale) * splitMax;
            goto doSplit;
        }
        case 0x23:
        case 0x24:
        case 0x25: {
            const int off = query->m_offset[command - 0x23];
            const int shift = 16 - query->m_iIndex;
            splitMax = float((PC[1] << shift) + off) * m_vScale;
            splitMin = float((PC[2] << shift) + off) * m_vScale;
            axis = command - 0x23;
            offset = (PC[3] << 8) + PC[4];
            PC += 7;
            rightOffset = (PC[-2] << 8) + PC[-1];
        doSplit: {
            float old = S00e65140_shiftDopHigh(m_kDop, (S00e65140_Dop::DOP_AXIS)axis, splitMax);
            PC += offset;
            hkpMoppKDopGeometriesVirtualMachine_queryMoppKDopGeometriesRecurse(query, PC);
            S00e65140_shiftDopHigh(m_kDop, (S00e65140_Dop::DOP_AXIS)axis, old);
            old = S00e65140_shiftDopLow(m_kDop, (S00e65140_Dop::DOP_AXIS)axis, splitMin);
            PC -= offset - rightOffset;
            hkpMoppKDopGeometriesVirtualMachine_queryMoppKDopGeometriesRecurse(query, PC);
            S00e65140_shiftDopLow(m_kDop, (S00e65140_Dop::DOP_AXIS)axis, old);
            return;
        }
        }
        case 0x26:
        case 0x27:
        case 0x28: {
            queryAxis = command - 0x26;
            splitMin = float((PC[1] << (16 - query->m_iIndex)) + query->m_offset[queryAxis]) * m_vScale;
            splitMax = float((PC[2] << (16 - query->m_iIndex)) + query->m_offset[queryAxis]) * m_vScale;
            bool added;
            if (m_iNumNodes == 0 || m_depth < m_iNumNodes)
            {
                added = true;
                hkpMoppKDopGeometriesVirtualMachine_pushKDop(FlagArg(false), -1);
            }
            else
            {
                added = false;
            }
            const S00e65140_Dop::DOP_AXIS axis = (S00e65140_Dop::DOP_AXIS)queryAxis;
            float oldLo, oldHi;
            S00e65140_doubleCut(m_kDop, axis, splitMin, splitMax, oldLo, oldHi);
            PC += 3;
            m_depth++;
            hkpMoppKDopGeometriesVirtualMachine_queryMoppKDopGeometriesRecurse(query, PC);
            m_depth--;
            if (added && m_b8 && !m_abort)
            {
                m_out--;
            }
            S00e65140_doubleCut(m_kDop, axis, oldLo, oldHi, splitMin, splitMax);
            return;
        }
        case 0x29:
        case 0x2a:
        case 0x2b: {
            queryAxis = command - 0x29;
            splitMin = float(S00e65140_read24(PC + 1)) * m_vScale;
            splitMax = float(S00e65140_read24(PC + 4)) * m_vScale;
            bool added;
            if (m_iNumNodes == 0 || m_depth < m_iNumNodes)
            {
                added = true;
                hkpMoppKDopGeometriesVirtualMachine_pushKDop(FlagArg(false), -1);
            }
            else
            {
                added = false;
            }
            const S00e65140_Dop::DOP_AXIS axis = (S00e65140_Dop::DOP_AXIS)queryAxis;
            float oldLo, oldHi;
            S00e65140_doubleCut(m_kDop, axis, splitMin, splitMax, oldLo, oldHi);
            PC += 7;
            m_depth++;
            hkpMoppKDopGeometriesVirtualMachine_queryMoppKDopGeometriesRecurse(query, PC);
            m_depth--;
            if (added && m_b8)
            {
                m_out--;
            }
            S00e65140_doubleCut(m_kDop, axis, oldLo, oldHi, splitMin, splitMax);
            return;
        }
        case 0x50:
            m_primitiveId = PC[1];
            goto AddHit;
        case 0x51: {
            queryAxis = PC[1];
            queryAxis <<= 8;
            m_primitiveId = PC[2];
            m_primitiveId += queryAxis;
        }
            goto AddHit;
        case 0x52: {
            queryAxis = PC[1];
            queryAxis <<= 16;
            m_primitiveId = PC[2];
            m_primitiveId <<= 8;
            m_primitiveId = PC[3] + m_primitiveId;
            m_primitiveId += queryAxis;
        }
            goto AddHit;
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:
            m_primitiveId = command - 0x30;
        AddHit:
            m_primitiveId += query->m_uiPropertyCount;
            hkpMoppKDopGeometriesVirtualMachine_addHit(m_primitiveId, query->m_kProperties);
            m_primitiveId = -1;
            return;
        default: {
            unsigned int assertBuf[128];
            MoppErrorStream ostr;
            ostr.FUN_00cb1600((char*)assertBuf, 0x200);
            ostr.ProcessAndReturnValue_00cc01c0(
                "Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
            if (reinterpret_cast<MoppError*>(DAT_01268360)
                    ->message(3, 0x1298fedd, (const char*)assertBuf,
                              ".\\Collide\\Mopp\\Machine\\hkpMoppKDopGeometriesVirtualMachine.cpp", 0x251))
            {
                __debugbreak();
            }
            ostr.FUN_00cc00e0();
            break;
        }
        }
    }
}
