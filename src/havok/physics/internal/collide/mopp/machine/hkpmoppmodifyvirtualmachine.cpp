// src/havok/physics/internal/collide/mopp/machine/hkpmoppmodifyvirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppmodifyvirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

extern "C" void _ReadWriteBarrier();

typedef unsigned char Byte;

struct BoolResult {

    Byte value; BoolResult() {}

    BoolResult(bool v) : value(v) {}

    operator bool() const { return value != 0; }

};

struct BranchWork { BoolResult c4,c1,c2,c3; int leftJump,rightJump; };

struct __declspec(align(16)) VMState {

    int upper[4];

    int lower[4];

    int origin[3];

    int primitive;

    int shift;

    int properties[3];

};

struct CodeStore {

    int unk00; int unk04; int unk08; int unk0c;

    int unk10; int unk14; int unk18; int unk1c;

    const Byte* data;

};

struct Visitor {

    virtual void unused();

    virtual BoolResult terminal(int id, const int* properties);

    virtual void branch(int offset);

};

struct Diagnostic {

    virtual void ReportDiagnostic(); virtual void unused1(); virtual void unused2();

    virtual int report(int type, int id, const char* message, const char* file, int line);

};

extern Diagnostic* DAT_01268360;
extern const char str_010d5100[];
extern const char str_010ed0ac[];

struct MessageStream {

    int unk00; int unk04; int unk08;

    void FUN_00cb1600(char*, int);

    void ProcessAndReturnValue_00cc01c0(const char*);

    void FUN_00cc00e0();

};

struct Interpreter {

    int upper[4];

    int lower[4];

    int origin[4];

    CodeStore* store;

    int unk34; int unk38; int unk3c;

    BoolResult active; Byte unk41; Byte unk42; Byte unk43;

    Visitor* visitor;

    int mask;
    __forceinline void evaluate(int id, const int* props) { active = visitor->terminal(id, props); }

    __declspec(noalias) BoolResult* hkpMoppModifyVirtualMachine_queryModicationPointsRecursive(BoolResult* result, const VMState* state, const Byte* code, int codeOffset);

};

__forceinline int read16(const Byte* p) { return int(p[0])*256+p[1]; }

__forceinline int read24(const Byte* p) { return (int(p[0])*256+p[1])*256+p[2]; }

__forceinline int read32(const Byte* p) { return ((int(p[0])*256+p[1])*256+p[2])*256+p[3]; }

// @fnv 0x00e66950
// src: HAVOK_LIB 0x00e66950
BoolResult* Interpreter::hkpMoppModifyVirtualMachine_queryModicationPointsRecursive(BoolResult* result, const VMState* state, const Byte* code, int codeOffset)

{

    VMState local;
BranchWork work;


    int splitHigh, rightJump;

    int splitLow;
    int boundLow, boundHigh;
    int terminalId;

    for (;;) {

        unsigned op = code[0];

        switch (op) {

        case 0x26: case 0x27: case 0x28:

            if (state->upper[op-0x26] < code[1] || state->lower[op-0x26] >= code[2]) goto reject;

            code += 3; break;

        case 0x29: case 0x2a: case 0x2b:

            if (lower[op-0x29] < ((int(code[1])*256+code[2])*256+code[3])) goto reject;
            { int high = code[4]; _ReadWriteBarrier(); int low = code[5];
              if (origin[op-0x29] > ((low+high*256)*256+code[6])) goto reject; }

            code += 7; break;

        case 5: code += code[1] + 2; break;

        case 6: code += (int(code[1])*256+code[2]) + 3; break;

        case 7: code += ((int(code[1])*256+code[2])*256+code[3]) + 4; break;

        case 0xc:

            codeOffset = ((int(code[1]) << 8) | code[2]) << 9;

            code = store->data + codeOffset; break;

        case 0x70:

            codeOffset = (((int(code[1])*256+code[2])*256+code[3])*256+code[4]); code = store->data + codeOffset; break;

        case 1: case 2: case 3: case 4:

            local.origin[0] = (code[1] + state->origin[0]) << op;

            local.origin[1] = (code[2] + state->origin[1]) << op;

            local.origin[2] = (code[3] + state->origin[2]) << op;

            local.shift = state->shift + op;

            local.lower[0] = (origin[0] >> (16-local.shift)) - local.origin[0];

            local.lower[1] = (origin[1] >> (16-local.shift)) - local.origin[1];

            local.lower[2] = (origin[2] >> (16-local.shift)) - local.origin[2];

            local.upper[0] = (lower[0] >> (16-local.shift)) - local.origin[0] + 1;

            local.upper[1] = (lower[1] >> (16-local.shift)) - local.origin[1] + 1;

            local.upper[2] = (lower[2] >> (16-local.shift)) - local.origin[2] + 1;

            local.properties[0] = state->properties[0];

            local.primitive = state->primitive;

            state = &local; code += 4; break;

        case 9:

            { int value = code[1]; if (state != &local) { local = *state; state = &local; } local.primitive += value; }

            code += 2; break;

        case 0xa:

            { int value = (int(code[1])*256+code[2]); if (state != &local) { local = *state; state = &local; } local.primitive += value; }

            code += 3; break;

        case 0xb:

            { int value = (((int(code[1])*256+code[2])*256+code[3])*256+code[4]); if (state != &local) { local = *state; state = &local; } local.primitive = value; }

            code += 5; break;

        case 0xd: code += 5; break;

        case 0x60: case 0x61: case 0x62: case 0x63:

            { int v = code[1]; code += 2; local.properties[op-0x60] = v; } goto NextOpcode;

        case 0x64: case 0x65: case 0x66: case 0x67:

            { int v = (int(code[1])*256+code[2]); local.properties[op-0x64] = v;  code += 3; } goto NextOpcode;

        case 0x68: case 0x69: case 0x6a: case 0x6b:

            { int v = (((int(code[1])*256+code[2])*256+code[3])*256+code[4]); local.properties[op-0x68] = v;  code += 5; }

        NextOpcode:

            { int value = local.properties[0]; if (state != &local) { local = *state; state = &local; } local.properties[0] = value; }

            break;

        default:

            {

                int buffer[128]; MessageStream message;

                message.FUN_00cb1600((char*)buffer, 512);

                message.ProcessAndReturnValue_00cc01c0("Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");

                if (DAT_01268360->report(3, 0x1298fedd, (char*)buffer, ".\\Collide\\Mopp\\Machine\\hkpMoppModifyVirtualMachine.cpp", 0x125)) __debugbreak();

                message.FUN_00cc00e0();

            }

            break;

        case 0x13:
            splitLow = code[1]*2; splitHigh = code[2]*2; boundHigh = state->lower[2]+state->lower[1]; boundLow = state->upper[2]+state->upper[1]; goto four;
        case 0x14:
            splitLow = code[1]*2-255; splitHigh = code[2]*2-255; boundHigh = state->lower[1]-state->upper[2]; boundLow = state->upper[1]-state->lower[2]; goto four;
        case 0x15:
            splitLow = code[1]*2; splitHigh = code[2]*2; boundHigh = state->lower[2]+state->lower[0]; boundLow = state->upper[2]+state->upper[0]; goto four;
        case 0x16:
            splitLow = code[1]*2-255; splitHigh = code[2]*2-255; boundHigh = state->lower[0]-state->upper[2]; boundLow = state->upper[0]-state->lower[2]; goto four;
        case 0x17:
            splitLow = code[1]*2; splitHigh = code[2]*2; boundHigh = state->lower[1]+state->lower[0]; boundLow = state->upper[1]+state->upper[0]; goto four;
        case 0x18:
            splitLow = code[1]*2-255; splitHigh = code[2]*2-255; boundHigh = state->lower[0]-state->upper[1]; boundLow = state->upper[0]-state->lower[1]; goto four;
        case 0x19:
            splitLow = code[1]*3; splitHigh = code[2]*3; boundHigh = state->lower[2]+state->lower[1]+state->lower[0]; boundLow = state->upper[2]+state->upper[1]+state->upper[0]; goto four;
        case 0x1a:
            splitLow = (code[1]-85)*3; splitHigh = (code[2]-85)*3; boundHigh = state->lower[1]-state->upper[2]+state->lower[0]; boundLow = state->upper[1]-state->lower[2]+state->upper[0]; goto four;
        case 0x1b:
            splitLow = (code[1]-85)*3; splitHigh = (code[2]-85)*3; boundHigh = state->lower[2]-state->upper[1]+state->lower[0]; boundLow = state->upper[2]-state->lower[1]+state->upper[0]; goto four;
        case 0x1c:
            splitLow = (code[1]-170)*3; splitHigh = (code[2]-170)*3; boundHigh = state->lower[0]-state->upper[2]-state->upper[1]; boundLow = state->upper[0]-state->lower[2]-state->lower[1]; goto four;
        case 0x10: case 0x11: case 0x12:
            splitLow = code[1]; splitHigh = code[2]; boundHigh = state->lower[op-0x10]; boundLow = state->upper[op-0x10]; goto four;
        four: work.leftJump=0; code+=4; rightJump=code[-1]; goto split;
        case 0x20: case 0x21: case 0x22:
            splitHigh = code[1]; splitLow = splitHigh+1;
            boundHigh = state->lower[op-0x20]; boundLow = state->upper[op-0x20];
            --code;
            goto four;
        case 0x23: case 0x24: case 0x25:
            splitLow = code[1]; splitHigh = code[2];
            boundHigh = state->lower[op-0x23]; boundLow = state->upper[op-0x23];
            work.leftJump = (int(code[3])*256+code[4]); rightJump = (int(code[5])*256+code[6]); code += 7;
        split:
 static_cast<volatile int&>(work.rightJump)=rightJump;
            {
                
                BoolResult a(false), b(false); int notifiedLeft;
                if (boundLow <= splitHigh) {
                    if (boundHigh < splitLow) {
                        {BoolResult* __restrict out1=&work.c1;notifiedLeft=work.leftJump; a = *hkpMoppModifyVirtualMachine_queryModicationPointsRecursive(out1, state, code+notifiedLeft, codeOffset);}
                    } else { reject: result->value = 0; return result; }
                } else if (boundHigh >= splitLow) {
                    {BoolResult* __restrict out2=&work.c2; b=*hkpMoppModifyVirtualMachine_queryModicationPointsRecursive(out2,state,code+work.rightJump,codeOffset);} notifiedLeft=work.leftJump;
                } else {
                    {BoolResult* __restrict out3=&work.c3;a = *hkpMoppModifyVirtualMachine_queryModicationPointsRecursive(out3, state, code+work.leftJump, codeOffset);}
                    b = *hkpMoppModifyVirtualMachine_queryModicationPointsRecursive(&work.c4, state, code+work.rightJump, codeOffset); notifiedLeft=work.leftJump;
                }
                if ((int)(a.value != 0) & (int)(b.value == 0)) visitor->branch(int(code + notifiedLeft - store->data));
                if ((int)(a.value == 0) & (int)(b.value != 0)) visitor->branch(int(code+work.rightJump-store->data));
                result->value = (b.value != 0) & (a.value != 0); return result;
            }
        case 0x50: terminalId = code[1]; goto terminal;

        case 0x51: terminalId = (int(code[1])*256+code[2]); goto terminal;

        case 0x52: terminalId = ((int(code[1])*256+code[2])*256+code[3]); goto terminal;

        case 0x53: terminalId = (((int(code[1])*256+code[2])*256+code[3])*256+code[4]); goto terminal;

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

            terminalId = op - 0x30;

        terminal: {

            int id = (((codeOffset >> 9)*256) & mask) | (state->primitive + terminalId);

            evaluate(id,state->properties); }

        case 0:

            *result = active; return result;

        }

    }

}

struct S00e67230_Code {
    int unk00; int unk04; int unk08; int unk0c;
    float offsetX; float offsetY; float offsetZ; float scale;
    const Byte* data;
};
struct S00e67230_Aabb {
    float minX; float minY; float minZ; float minW;
    float maxX; float maxY; float maxZ; float maxW;
};
extern BoolResult DAT_0126efbc;
extern "C" void __cdecl FUN_00df22f0(BoolResult* flag);

__forceinline int S00e67230_toIntMin(float r) { return fnv_FloatToInt(r) - 1; }
__forceinline int S00e67230_toIntMax(float r) { return fnv_FloatToInt(r) + 1; }

struct S00e67230_Machine {
    int primitives; int unk04; int unk08; int unk0c;
    int xHi; int yHi; int zHi; int unk1c;
    int xLo; int yLo; int zLo; int unk2c;
    const S00e67230_Code* code; int unk34; int unk38; int unk3c;
    BoolResult active; Byte unk41; Byte unk42; Byte unk43;
    Visitor* modifier;
    int mask;

    BoolResult hkpMoppModifyVirtualMachine_queryModicationPointsRecursive(const VMState* state, const Byte* base, int offset);

    __forceinline void generateQueryFromAabb(const S00e67230_Aabb& aabb, VMState& query)
    {
        const S00e67230_Code* info = code;
        const float scale = info->scale;
        const float x = info->offsetX;
        xLo = S00e67230_toIntMin((aabb.minX - x) * scale);
        xHi = S00e67230_toIntMax((aabb.maxX - x) * scale);
        const float y = info->offsetY;
        yLo = S00e67230_toIntMin((aabb.minY - y) * scale);
        yHi = S00e67230_toIntMax((aabb.maxY - y) * scale);
        const float z = info->offsetZ;
        zLo = S00e67230_toIntMin((aabb.minZ - z) * scale);
        zHi = S00e67230_toIntMax((aabb.maxZ - z) * scale);
        query.lower[0] = xLo >> 16;
        query.upper[0] = (xHi >> 16) + 1;
        query.lower[1] = yLo >> 16;
        query.upper[1] = (yHi >> 16) + 1;
        query.lower[2] = zLo >> 16;
        query.upper[2] = (zHi >> 16) + 1;
        query.origin[0] = 0;
        query.origin[1] = 0;
        query.origin[2] = 0;
        query.primitive = 0;
        query.shift = 0;
        query.properties[0] = 0;
    }

    void hkpMoppModifyVirtualMachine_queryAabb(const S00e67230_Code* codeIn, const S00e67230_Aabb& aabb, Visitor* modifierOut);
};

// @fnv 0x00e67230
// src: HAVOK_LIB 0x00e67230
void S00e67230_Machine::hkpMoppModifyVirtualMachine_queryAabb(const S00e67230_Code* codeIn, const S00e67230_Aabb& aabb, Visitor* modifierOut)
{
    if (!DAT_0126efbc) {
        FUN_00df22f0(&DAT_0126efbc);
        if (!DAT_0126efbc) {
            return;
        }
    }
    code = codeIn;
    modifier = modifierOut;
    primitives = 0;

    VMState query;
    generateQueryFromAabb(aabb, query);

    const Byte* base = &code->data[0];
    mask = (*base != 13) - 1;


    BoolResult hit = hkpMoppModifyVirtualMachine_queryModicationPointsRecursive(&query, base, 0);
    if (hit) {
        modifierOut->branch(code->data[0] == 13 ? 5 : 0);
    }
}
