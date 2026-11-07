
// src/havok/physics/internal/collide/mopp/machine/hkpmoppobbvirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppobbvirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/HitArray.h"

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

struct GridSource {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    unsigned char* p20;
};

struct GridBounds {
    float f00;
    float f04;
    float f08;
    float unk0c;
    float f10;
    float f14;
    float f18;
};

struct __declspec(align(16)) GridScratch {
    int f00;
    int f04;
    int f08;
    int unk0c;
    int f10;
    int f14;
    int f18;
    int unk1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
};

struct GridCell {
    int m00;
    int unk04;
    int unk08;
    int unk0c;
    union {
        int m10;
        struct {
            short unk10;
            short m12;
        };
    };
    union {
        int m14;
        struct {
            short unk14;
            short m16;
        };
    };
    int m18;
    int unk1c;
    union {
        int m20;
        struct {
            short unk20;
            short m22;
        };
    };
    union {
        int m24;
        struct {
            short unk24;
            short m26;
        };
    };
    union {
        int m28;
        struct {
            short unk28;
            short m2a;
        };
    };
    int unk2c;
    void* m30;
    int m34;

    void hkpMoppObbVirtualMachine_queryAabb(GridSource* a1, GridBounds* a2, int a3);
    void Execute(GridScratch* s, unsigned char* p, int z);
};

// @fnv 0x00dd1da0
// src: HAVOK_LIB 0x00dd1da0
void GridCell::hkpMoppObbVirtualMachine_queryAabb(GridSource* a1, GridBounds* a2, int a3) {
    m30 = a1;
    m00 = a3;
    float s = a1->f1c;
    float p10 = a1->f10;
    m20 = fnv_FloatToInt((a2->f00 - p10) * s) - 1;
    m10 = fnv_FloatToInt((a2->f10 - p10) * s) + 1;
    float p14 = a1->f14;
    m24 = fnv_FloatToInt((a2->f04 - p14) * s) - 1;
    m14 = fnv_FloatToInt((a2->f14 - p14) * s) + 1;
    float p18 = a1->f18;
    m28 = fnv_FloatToInt((a2->f08 - p18) * s) - 1;
    m18 = fnv_FloatToInt((a2->f18 - p18) * s) + 1;

    GridScratch loc;
    loc.f10 = m22;
    loc.f00 = m12 + 1;
    loc.f14 = m26;
    loc.f04 = m16 + 1;
    loc.f18 = m2a;
    loc.f08 = (m18 >> 16) + 1;
    loc.f20 = 0;
    loc.f24 = 0;
    loc.f28 = 0;
    loc.f2c = 0;
    loc.f30 = 0;
    loc.f34 = 0;

    unsigned char* p = a1->p20;
    m34 = ((*p != 0xd) ? 1 : 0) - 1;
    Execute(&loc, p, 0);
}

extern "C" void _ReadWriteBarrier();
extern "C" void __debugbreak();
struct __declspec(align(16)) QueryState {
 union {int lower[4]; struct {int f00;int f04;int f08;int unk0c;};};
 union {int upper[4]; struct {int f10;int f14;int f18;int unk1c;};};
 union {int origin[3]; struct {int f20;int f24;int f28;};};
 union {unsigned primitiveOffset;unsigned f2c;};
 union {int shift;int f30;};
 union {unsigned properties[1];unsigned f34;};
};
struct CodeData {
 int unk00;int unk04;int unk08;int unk0c;
 float f10;float f14;float f18;float f1c;
 union {unsigned char* code;unsigned char* p20;};
};
struct AllocatorContext { int field00, field04, field08, field0c; void* allocator; };
extern AllocatorContext* __cdecl hkMemoryRouter_getInstance();
extern void __cdecl ResizeAudioStream(void*, void*, int);
extern unsigned char DAT_01269cbc;
extern void __cdecl ValidateHavokKeyCode(unsigned char*);
struct ErrorText { char* data; int length; int capacity; void FUN_00cb1600(char*,int); void ProcessAndReturnValue_00cc01c0(const char*); void FUN_00cc00e0(); };
struct ErrorReporter { virtual void ReportDiagnostic(); virtual void unused1(); virtual void unused2(); virtual int report(int,unsigned,const char*,const char*,int); };
extern ErrorReporter* DAT_01268360;
struct VirtualMachine {
 union {int m00;HitArray* hits;};
 int unk04;int unk08;int unk0c;
 union {int lower[4];struct {
 union {int m10;struct {short unk10;short m12;};};
 union {int m14;struct {short unk14;short m16;};};
 int m18;int unk1c;
 };};
 union {int upper[4];struct {
 union {int m20;struct {short unk20;short m22;};};
 union {int m24;struct {short unk24;short m26;};};
 union {int m28;struct {short unk28;short m2a;};};
 int unk2c;
 };};
 union {CodeData* data;void* m30;};
 union {int primitiveMask;int m34;};
 void Execute(const QueryState*,unsigned char*,int);
 __forceinline void AddHit(int value) {
  HitArray* out=hits;AllocatorContext* context=hkMemoryRouter_getInstance();
  if(out->size==(out->capacity&0x3fffffff)) ResizeAudioStream(context->allocator,out,4);
  int* destination=&reinterpret_cast<int*>(out->data)[out->size]; ++out->size; *destination=value; }
};
// Executes a MOPP BVH tree traversal from a QueryState, recursing on diagonal and axial branches, and emits a hit via AddHit on a leaf.
// @fnv 0x00dd1400
void VirtualMachine::Execute(const QueryState* apQueryState,unsigned char* __restrict pc,int codeOffset) {
    int by;(void)by;
    QueryState localQueryState;
    if (!DAT_01269cbc) {
        ValidateHavokKeyCode(&DAT_01269cbc);
        if (!DAT_01269cbc) return;
    }
    for (;;) {
        unsigned op=*pc;
        int high,low,left,right,length;
        int term;
        switch(op) {
        case 0: return;
        case 0x13: left=pc[1]*2;right=pc[2]*2;high=apQueryState->upper[1]+apQueryState->upper[2];low=apQueryState->lower[1]+apQueryState->lower[2];goto diagonal;
        case 0x14: left=pc[1]*2-255;right=pc[2]*2-255;high=apQueryState->upper[1]-apQueryState->lower[2];low=apQueryState->lower[1]-apQueryState->upper[2];goto diagonal;
        case 0x15: left=pc[1]*2;right=pc[2]*2;high=apQueryState->upper[0]+apQueryState->upper[2];low=apQueryState->lower[0]+apQueryState->lower[2];goto diagonal;
        case 0x16: left=pc[1]*2-255;right=pc[2]*2-255;high=apQueryState->upper[0]-apQueryState->lower[2];low=apQueryState->lower[0]-apQueryState->upper[2];goto diagonal;
        case 0x17: left=pc[1]*2;right=pc[2]*2;high=apQueryState->upper[0]+apQueryState->upper[1];low=apQueryState->lower[0]+apQueryState->lower[1];goto diagonal;
        case 0x18: left=pc[1]*2-255;right=pc[2]*2-255;high=apQueryState->upper[0]-apQueryState->lower[1];low=apQueryState->lower[0]-apQueryState->upper[1];goto diagonal;
        case 0x19: left=pc[1]*3;right=pc[2]*3;high=apQueryState->upper[2]+apQueryState->upper[1]+apQueryState->upper[0];low=apQueryState->lower[2]+apQueryState->lower[1]+apQueryState->lower[0];goto diagonal;
        case 0x1a: left=(pc[1]-85)*3;right=(pc[2]-85)*3;high=apQueryState->upper[1]-apQueryState->lower[2]+apQueryState->upper[0];low=apQueryState->lower[1]-apQueryState->upper[2]+apQueryState->lower[0];goto diagonal;
        case 0x1b: left=(pc[1]-85)*3;right=(pc[2]-85)*3;high=apQueryState->upper[2]-apQueryState->lower[1]+apQueryState->upper[0];low=apQueryState->lower[2]-apQueryState->upper[1]+apQueryState->lower[0];goto diagonal;
        case 0x1c: left=(pc[1]-170)*3;right=(pc[2]-170)*3;high=apQueryState->upper[0]-apQueryState->lower[2]-apQueryState->lower[1];low=apQueryState->lower[0]-apQueryState->upper[2]-apQueryState->upper[1];
        diagonal:
            pc+=4;
            if(low<=right) {if(high<left) break;return;}
            length=pc[-1];
            if(high>=left) {pc+=length;break;}
            Execute(apQueryState,pc,codeOffset);
            pc+=length;break;
        case 0x10:case 0x11:case 0x12:
            left=pc[1];right=pc[2];high=apQueryState->upper[op-0x10];pc+=4;
            if(apQueryState->lower[op-0x10]<=right) {if(high<left) break;return;}
            length=pc[-1]; pc+=length;
            if(high<left) goto recurseAxial;
            break;
        case 0x20:case 0x21:case 0x22:
            right=pc[1];pc+=3;
            if(apQueryState->lower[op-0x20]<=right) break;
            length=pc[-1];pc+=length;
            if(apQueryState->upper[op-0x20]>right) break;
        recurseAxial: Execute(apQueryState,pc-length,codeOffset);
            break;
        case 0x23:case 0x24:case 0x25:
            left=pc[1];right=pc[2];high=apQueryState->upper[op-0x23];length=(pc[3]<<8)+pc[4];pc+=7;
            if(apQueryState->lower[op-0x23]<=right) {if(high>=left)return;pc+=length;break;}
            {int other=(pc[-2]<<8)+pc[-1];pc+=other;
            if(high<left) Execute(apQueryState,pc+length-other,codeOffset);}
            break;
        case 0x26:case 0x27:case 0x28:
            if(apQueryState->lower[op-0x26]<pc[1])return;
            if(apQueryState->upper[op-0x26]>=pc[2])return;
            pc+=3;break;
        case 0x29:case 0x2a:case 0x2b:
            left=(((pc[1]<<8)+pc[2])<<8)+pc[3];
            if(lower[op-0x29]<left)return;
            right=(((pc[4]<<8)+pc[5])<<8)+pc[6];
            if(upper[op-0x29]>right)return;
            pc+=7;break;
        case 5: pc+=2; length=pc[-1];pc+=length; break;
        case 6: {int a=pc[1];int b=pc[2];pc+=3;a<<=8;a+=b;pc+=a;break;}
        case 7: {int a=pc[1];int b=pc[2];int c=pc[3];pc+=4;a<<=8;a+=b;a<<=8;a+=c;pc+=a;break;}
        case 12:
            codeOffset=((pc[1]<<8)|pc[2])<<9;goto changePage;
        case 0x70:
            codeOffset=(((((pc[1]<<8)+pc[2])<<8)+pc[3])<<8)+pc[4];
        changePage: pc=data->code+codeOffset;break;
        case 1: case 2: case 3: case 4:
            {volatile QueryState& q=localQueryState;
            q.origin[0]=(pc[1]+apQueryState->origin[0])<<op;
            q.origin[1]=(pc[2]+apQueryState->origin[1])<<op;
            q.origin[2]=(pc[3]+apQueryState->origin[2])<<op;
            q.shift=apQueryState->shift+op;
            int inverseShift=16-localQueryState.shift;
            q.upper[0]=(upper[0]>>inverseShift)-q.origin[0];
            q.upper[1]=(upper[1]>>inverseShift)-q.origin[1];
            q.upper[2]=(upper[2]>>inverseShift)-q.origin[2];
            q.lower[0]=(lower[0]>>inverseShift)-q.origin[0]+1;
            int iOriginY=q.origin[1];by=((volatile int&)lower[1])>>inverseShift;q.lower[1]=by-iOriginY+1;
            q.lower[2]=(lower[2]>>inverseShift)-q.origin[2]+1;
            q.properties[0]=apQueryState->properties[0];
            q.primitiveOffset=apQueryState->primitiveOffset;
            apQueryState=&localQueryState; pc+=4; break;}
        case 9:
            length=pc[1]; if(apQueryState!=&localQueryState) {localQueryState=*apQueryState;apQueryState=&localQueryState;}
            localQueryState.primitiveOffset+=length;pc+=2;break;
        case 10:
            length=(pc[1]<<8)+pc[2]; if(apQueryState!=&localQueryState) {localQueryState=*apQueryState;apQueryState=&localQueryState;}
            localQueryState.primitiveOffset+=length;pc+=3;break;
        case 11:
            length=((((pc[1]<<8)+pc[2])<<8)+pc[3]<<8)+pc[4];
            if(apQueryState!=&localQueryState) {localQueryState=*apQueryState;apQueryState=&localQueryState;}
            localQueryState.primitiveOffset=length;pc+=5;break;
        case 13: pc+=5;break;
        case 0x60:case 0x61:case 0x62:case 0x63:
            {int propertyValue=pc[1];pc+=2;localQueryState.properties[op-0x60]=propertyValue;}goto property;
        case 0x64:case 0x65:case 0x66:case 0x67:
            {int propertyValue=(pc[1]<<8)+pc[2];localQueryState.properties[op-0x64]=propertyValue;pc+=3;}goto property;
        case 0x68:case 0x69:case 0x6a:case 0x6b:
            {int propertyValue=(((((pc[1]<<8)+pc[2])<<8)+pc[3])<<8)+pc[4];localQueryState.properties[op-0x68]=propertyValue;pc+=5;}
        property:
            {int value=localQueryState.properties[0];if(apQueryState!=&localQueryState){localQueryState=*apQueryState;apQueryState=&localQueryState;}localQueryState.properties[0]=value;}break;
        case 0x50: term=pc[1];goto emit;
        case 0x51: term=(pc[1]<<8)+pc[2];goto emit;
        case 0x52: term=(((pc[1]<<8)+pc[2])<<8)+pc[3];goto emit;
        case 0x53: term=(((((pc[1]<<8)+pc[2])<<8)+pc[3])<<8)+pc[4];goto emit;
        case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:case 0x37:case 0x38:case 0x39:case 0x3a:case 0x3b:case 0x3c:case 0x3d:case 0x3e:case 0x3f:case 0x40:case 0x41:case 0x42:case 0x43:case 0x44:case 0x45:case 0x46:case 0x47:case 0x48:case 0x49:case 0x4a:case 0x4b:case 0x4c:case 0x4d:case 0x4e:case 0x4f:
            term=op-0x30;goto emit;
        default:
        badCommand:
            {unsigned int errorBuffer[128];ErrorText errorText;errorText.FUN_00cb1600(reinterpret_cast<char*>(errorBuffer),512);
            errorText.ProcessAndReturnValue_00cc01c0("Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
            if(DAT_01268360->report(3,0x1298fedd,reinterpret_cast<char*>(errorBuffer),".\\Collide\\Mopp\\Machine\\hkpMoppObbVirtualMachine.cpp",459)) __debugbreak();
            errorText.FUN_00cc00e0();}break;
        emit:
            {unsigned key=apQueryState->primitiveOffset+term; unsigned value=((((unsigned)(codeOffset>>9))<<8)&primitiveMask)|key;
            AddHit(value);return;}
        }
    }
}
