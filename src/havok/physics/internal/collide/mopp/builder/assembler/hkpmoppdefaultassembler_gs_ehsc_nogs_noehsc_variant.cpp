#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/CodeInfo.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../include/hkpMoppCode.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/FinishingFlag.h"
#include "../../../../../../../../include/NiPoint3.h"
#include "../../../../../../../../include/Pair.h"
// src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl GrowBuffer();
struct FUN_00e06780_class
{
    void __thiscall AppendChar(char b);
};
struct S_00e066f0_Src
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
    int m_pRayStart;
    int m_kRayEnd;
    int m_uiItemCount;
    int m_offsets[8];
};
struct S_00e066f0
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
    int unk34;
    int m_iElementCount;
    int m_uiItemCount;
    int m_entries[8];

    void CopyOffsets(const S_00e066f0_Src* src);
};
struct AlignRange
{
    volatile int m_iMinControlPoint;
    volatile int m_iMaxControlPoint;
};
struct FUN_00e06730_cls
{
    int unk00;
    int unk04;
    int unk08;
    AlignRange m_akRange[3];
    volatile int m_iShift;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    volatile int m_aiAlignedMin[3];
    volatile int m_aiAlignedMax[3];
    void AlignRanges();
};
struct ByteSink
{
    int unk00;
    int unk04;
    int m_uiLogicalSize;
    int m_iUsed;
    char* m_pBuffer;

    void GrowBuffer();

    void PutByte(char acValue)
    {
        m_pBuffer[m_uiLogicalSize - m_iUsed - 1] = acValue;
        m_iUsed++;
        if (m_iUsed >= m_uiLogicalSize)
            GrowBuffer();
    }

    void PutBytePair(char acFirst, char acSecond);
};
typedef void(__thiscall* FlushFunction)(void*);
struct BufferWriter
{
    int unknown00;
    int unknown04;
    int capacity;
    int position;
    unsigned char* data;
    void WriteInt24(int value);
};
struct S_00e06aa0_Pool
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void Free(void* p);
};
struct S_00e06aa0_Item
{
    int unk00;
    bool m_flag;
    char unk05;
    char unk06;
    char unk07;
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
    void* m_p70;
    void* m_p74;
};
struct S_00e06aa0
{
    int unk00;
    int unk04;
    int unk08;
    S_00e06aa0_Pool* m_kNodePool;
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
    bool m_enabled;
    void hkpMoppDefaultAssembler_releaseNode(S_00e06aa0_Item* item);
};
struct Node
{
    Node* next;
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
    int unk34;
    char unk38;
    char unk39;
};
void __stdcall hkpMoppDefaultAssembler_fixScale(Node* node);
struct Limits
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
    unsigned int unk34;
    unsigned int unk38;
};
void __stdcall AdjustLimits(Limits* first, Limits* second, Limits* third);
struct E06C20Writer
{
    void hkpMoppCodeGenerator_addCommand32(int size, void* data);
};
struct E06C20Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E06C20Writer* m_pStreamWriter;

    int hkpMoppDefaultAssembler_addJumpChunk(void* data);
};
struct S_00e07040_A
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
};
struct S_00e07040_B
{
    int unk00;
    int unk04;
    int unk08;
};
template <class T> inline T S_00e07040_Max(T a, T b)
{
    return a > b ? a : b;
}
// src: HAVOK_LIB 0x00e07040
int __stdcall hkpMoppDefaultAssembler_calcRescaleBits(S_00e07040_A* a, S_00e07040_B* b)
{
    int n = b->unk08 - 8;
    if (n <= 0)
        n = 0;
    int r = a->unk24 - n;
    if (r > a->unk24)
        r = a->unk24;
    return r;
}
struct E07510Input
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
    unsigned char unk38;
    unsigned char unk39;
    unsigned char m_type;
};
struct E07510Solver
{
    void hkpMoppDefaultAssembler_recalcRescale(void* b, void* c, void* d);
    void AdjustLimits(E07510Input* a, void* b, void* c);
    void hkpMoppDefaultAssembler_initTopDown(E07510Input* a, void* b, void* c, void* d);
};
struct S_e07c50_Buf
{
    int unk0;
    int unk4;
    int unk8;
    int m_iElementCount;
};
struct S_e07c50_Item;
struct S_e07c50
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_e07c50_Buf* m_buf;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_uiItemCount;
    void hkpMoppDefaultAssembler_fixScale(S_e07c50_Item* item);
    void hkpMoppDefaultAssembler_addTerminals(S_e07c50_Item* item, int b, int c);
    void hkpMoppDefaultAssembler_addCut(S_e07c50_Item* item, int c);
    int hkpMoppDefaultAssembler_assembleCutAndTerminalCommand(S_e07c50_Item* item, int b, int c);
};
struct S_e07c50_Item
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    char m_flag38;
    char m_flag39;
    char unk3A;
    char unk3B;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int m_kRayEnd;
};
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FUN_00e09640_class
{
    virtual void unknownVirtual();
    unsigned short unk04;
    void __thiscall DestroyAudioBuffer();
    FUN_00e09640_class* __thiscall FUN_00e09640(int flags);
};
struct FUN_00e06800_cls
{
    int unk00;
    int unk04;
    int m_cap;
    int m_uiItemCount;
    char* m_buf;

    void __thiscall Flush();
    void __thiscall hkpMoppCodeGenerator_addCommand16(char a, int v);
};
struct FUN_00e06880_cls
{
    int unk00;
    int unk04;
    int m_cap;
    int m_uiItemCount;
    char* m_buf;

    void __thiscall Flush();
    void __thiscall hkpMoppCodeGenerator_addCommand24(char a, int v);
};
struct FUN_00e069a0_cls
{
    int unk00;
    int unk04;
    int m_cap;
    int m_uiItemCount;
    char* m_buf;

    void __thiscall Flush();
    void __thiscall hkpMoppCodeGenerator_addCommand32(char a, unsigned int v);
};
struct FUN_00e06490_cls
{
    void __thiscall GrowBuffer();
};
struct FUN_00e06a60_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    void __thiscall FillWithPattern(int count);
};
// FUN_00e06af0 - a small __thiscall member that fills in a result flag.
//
// The original code is exactly:
//     00e06af0  8b 44 24 08        mov eax, dword ptr [esp + 8]
//     00e06af4  83 78 08 16        cmp dword ptr [eax + 8], 16h
//     00e06af8  7d 0a              jge 0x00e06b04
//     00e06afa  8b 44 24 04        mov eax, dword ptr [esp + 4]
//     00e06afe  c6 00 01           mov byte ptr [eax], 1
//     00e06b01  c2 0c 00           ret 0ch
//     00e06b04  8b 54 24 0c        mov edx, dword ptr [esp + 0ch]
//     00e06b08  8b 02              mov eax, dword ptr [edx]
//     00e06b0a  3b 41 18           cmp eax, dword ptr [ecx + 18h]
//     00e06b0d  8b 44 24 04        mov eax, dword ptr [esp + 4]
//     00e06b11  7f eb              jg 0x00e06afe
//     00e06b13  c6 00 00           mov byte ptr [eax], 0
//     00e06b16  c2 0c 00           ret 0ch
//
// so the member is
//     char* FUN_00e06af0(char* out, Actor* actor, int* value)
// and it returns the flag pointer it was given:
//
//   * if actor->unk08 is below 0x16 the flag is set to 1 unconditionally;
//   * otherwise the flag is 1 when *value is greater than the member
//     field at +0x18 and 0 when it is not.
//
// The "return out;" in every branch matters for the code generation: the
// returned pointer is already in EAX, and because the branches are not
// plain assignments MSVC 2008 keeps the two stores as real branches
// instead of folding them into a single conditional store.
// The "actor" the first flag argument points at.
struct FUN_00e06780_actor
{
    int unk00;
    int unk04;
    int unk08;
};
// The class the member belongs to.  The unit's FUN_00e06780_class carries
// no data members, so the flag field lives in the derived stand-in.
struct FUN_00e06780_owner : public FUN_00e06780_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;  // +0x18
    char* __thiscall hkpMoppDefaultAssembler_shouldAssemble(char* out, FUN_00e06780_actor* actor, int* value);
};
struct Stream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char* unk10;

    void GrowBuffer();

    void AppendChar(char b)
    {
        unk10[unk08 - unk0c - 1] = b;
        unk0c++;
        if (unk0c >= unk08)
        {
            GrowBuffer();
        }
    }

    void hkpMoppCodeGenerator_addCommand16(int a, int b);
};
struct FUN_00e06c40_class
{
    char pad[0x10];
    Stream* m_stream;

    int __thiscall hkpMoppDefaultAssembler_addDataOffset(int a1, int a2);
};
extern "C" void __cdecl GrowBuffer();
struct Sink
{
    int unk00;
    int unk04;
    int m_iCap;
    int m_iArrayLength;
    int m_iEnd;
    void __thiscall Flush();
};
struct Pkt
{
    int unk00;
    char m_b04;
    char unk05;
    char unk06;
    char unk07;
    char m_b08;
    char unk09;
    char unk0a;
    char unk0b;
    char m_b0c;
    char unk0d;
    char unk0e;
    char unk0f;
    char m_b10;
};
class FUN_00e06cb0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Sink* m_pSink;

    void __thiscall WritePacket(const Pkt* p);
};
extern char DAT_01000000;
struct S_00e06e00_Item
{
    int unk0;
};
struct S_00e06e00_Buf
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    void PutBytePair(int tag, unsigned int v);
    void hkpMoppCodeGenerator_addCommand16(int tag, unsigned int v);
    void hkpMoppCodeGenerator_addCommand24(int tag, unsigned int v);
    void hkpMoppCodeGenerator_addCommand32(int tag, unsigned int v);
};
struct S_00e06e00_A0
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S_00e06e00_Item* unk30[12];
    unsigned int* unk60;
};
struct S_00e06e00_A1
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    int unk44[16];
};
struct S_00e06e00_A2
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    unsigned int unk34;
};
struct S_00e06e00_Cls
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00e06e00_Buf* unk10;
    int hkpMoppDefaultAssembler_addTerminals(S_00e06e00_A0* a, S_00e06e00_A1* b, S_00e06e00_A2* c);
    void WriteOp(int idx, S_00e06e00_Item* item);
};
extern const double g_thresholdA;
extern const double g_thresholdB;
int __stdcall ClassifyVec3Region(const NiPoint3* pVec);
struct S_00e07070_Pair
{
    int unk00;
    int unk04;
};
struct S_00e07070_Object
{
    int unk00;
    int unk04;
    int unk08;
    S_00e07070_Pair r[3];
    int m_24;
    int v[3];
};
struct S_00e07070_Result
{
    char ok;
    int count;
    int q[3];
};
extern "C" int __stdcall hkpMoppDefaultAssembler_calcRescaleBits(S_00e07070_Object* a, S_00e07070_Object* b);
void __stdcall hkpMoppDefaultAssembler_recalcRescale(S_00e07070_Object* a, S_00e07070_Object* b, S_00e07070_Result* out);
struct S_00e07680_Writer
{
    int unk0;
    int unk4;
    int m_cap;
    int m_pos;
    unsigned char* m_buf;
    void AppendChar(int b);
    void GrowBuffer();
    __forceinline void put(unsigned char b)
    {
        m_buf[m_cap - m_pos - 1] = b;
        m_pos++;
        if (m_pos >= m_cap)
            GrowBuffer();
    }
};
struct S_00e07680
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00e07680_Writer* w;
    void WriteOffsetDelta(int);
    void hkpMoppDefaultAssembler_addSplit(int a1, int a2, int a3, int a4, int a5);
};
struct Entry
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
    int unk34;
    unsigned char unk38;
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
    Entry* unk70;
    Entry* unk74;
};
struct Handler
{
    int unk00, unk04, unk08, unk0c;
    Entry* unk10;
    void __thiscall hkpMoppDefaultAssembler_fixScale(Entry*);
    int __thiscall ClassifyVec3Region(int);
    void __thiscall hkpMoppDefaultAssembler_findPlanes(Entry*, Entry*, Entry**, Entry**);
    void __thiscall hkpMoppDefaultAssembler_addSplit(Entry*, Entry*, int, int, int);
    void __thiscall WriteSize(int);
    void __thiscall hkpMoppDefaultAssembler_checkAndAddProperties(Entry*, Entry*, Entry*);
    void __thiscall hkpMoppDefaultAssembler_addCut(Entry*, Entry*);
    void __thiscall WritePacket(char*);
    int __thiscall hkpMoppDefaultAssembler_assembleNonTerminalCommand(Entry*, Entry*, Entry*, char*);
};
extern int __cdecl hkMath_hkFloatToInt(float f);
struct S_00e07da0_Bounds
{
    int unk0;
    char b4;
    int unk8;
    struct Range
    {
        int lo;
        int hi;
    } ranges[3];  // 0x0C
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40[1];
    int unk44[1];

    void AlignRanges();
};
struct S_00e07da0_Region : S_00e07da0_Bounds
{
    int lo48[3];
    int hi54[3];

    void BuildScaledRanges(struct S_00e07da0_Node* node, void* p);
    void hkpMoppAssemblerNodeInfo_calcMaxExtentsSignificantBits();
};
struct S_00e07da0_Result
{
    bool valid;
    int value;
    int unk8;
    int unkC;
    int unk10;
};
struct S_00e07da0_Info
{
    char b0;
    char b1;
    char b2;
    char state[3];
    char pad6[2];
    int unk8;
    int mins[3];  // 0x0C
    int maxs[3];  // 0x18
};
struct S_00e07da0_Node
{
    int unk0;
    char b4;
    char pad5[3];
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int count2C;
    int offsets[2];        // 0x30
    S_00e07da0_Info info;  // 0x38
    void* unk5C;
    void* unk60;
    int unk64;
    int unk68;
    int unk6C;
    S_00e07da0_Node* child70;
    S_00e07da0_Node* child74;
};
struct S_00e07da0_Tree
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    float unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    float unk54;

    void BuildRegion(S_00e07da0_Node* node, S_00e07da0_Region* parent, S_00e07da0_Region* region);
    void ComputeNodeBounds(S_00e07da0_Node* node, S_00e07da0_Region* region);
    void hkpMoppDefaultAssembler_recalcRescale(S_00e07da0_Region* parent, S_00e07da0_Region* region, S_00e07da0_Result* out);
    int ClassifyVec3Region(void* p);
    void hkpMoppDefaultAssembler_findPlanes(S_00e07da0_Node* node, S_00e07da0_Region* region, int* lo, int* hi);
};
struct BSAudio;
extern int DAT_010ea5dc;
extern int DAT_0102e388;
struct FUN_00e09450_cls
{
    int m_vptr00;
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
    int unk34;
    int unk38;
    int unk3c;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void DestroyAudioBuffer();
};
int __cdecl hkMath_hkFloorToInt(float v);
struct FUN_00e094a0_floatpair
{
    float lo;
    float hi;
};
struct FUN_00e094a0_intpair
{
    int lo;
    int hi;
};
struct FUN_00e094a0_floatset
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00e094a0_floatpair pairs[3];
};
struct FUN_00e094a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00e094a0_intpair m_0c[3];

    void BuildScaledRanges(FUN_00e094a0_floatset* a1, float* a2);
};
// FUN_00e09540 - compute the level of an object from its bounding box.
//
// this : the object
//   +0x08 : the resulting level (a byte-sized value in the original)
//   +0x0c/+0x10, +0x14/+0x18, +0x1c/+0x20 : the three axis bounds
//
// The largest of the three axis extents is taken, the number of bits it
// needs is counted and the level is derived from that; the result is
// clamped to 0x18.
struct FUN_00e09540_Self
{
    void* unk00;
    int unk04;
    int unk08;  // the level
    int unk0c;  // x min
    int unk10;  // x max
    int unk14;  // y min
    int unk18;  // y max
    int unk1c;  // z min
    int unk20;  // z max
    void hkpMoppAssemblerNodeInfo_calcMaxExtentsSignificantBits();
};
class FUN_00e095d0_cls
{
  public:
    unsigned int m_00;
    unsigned char m_04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
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
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;

    FUN_00e095d0_cls* __thiscall UpdateState_00e095d0(FUN_00e095d0_cls* src, unsigned int a2, unsigned int a3);
    void __thiscall CopyOffsets(unsigned int a);
    void __thiscall BuildScaledRanges(unsigned int a, unsigned int b);
    void __thiscall hkpMoppAssemblerNodeInfo_calcMaxExtentsSignificantBits();
};
// Emit an opcode with an immediate, choosing the byte, short or int form (and its opcode offset) by value range.
class E6BC0Writer
{
  public:
    void WriteByteOp(int iOpcode, int iValue);
    void WriteShortOp(int iOpcode, int iValue);
    void WriteIntOp(int iOpcode, int iValue);
};
class E6BC0Encoder
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E6BC0Writer* m_pkWriter;

    void WriteOp(int iOpcode, int iValue);
};
struct FUN_00e06ed0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00e06e00_Buf* m_pStreamWriter;
    void WriteOffsetDelta(int iTarget);
};
extern int __cdecl hkMath_hkFloatToInt(float f);
struct Node07400
{
    int unk00;
    char b04;
    int unk08;
    struct Range
    {
        float fLo;
        float fHi;
    } ranges[3];
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int mins[3];
    int maxs[3];
};
struct Region07400
{
    int unk00;
    char b04;
    int unk08;
    struct Range
    {
        int lo;
        int hi;
    } ranges[3];
    int m_iShift;
};
template <class T> inline T Min07400(T a, T b)
{
    return a < b ? a : b;
}
template <class T> inline T Max07400(T a, T b)
{
    return a > b ? a : b;
}
struct Tree07400
{
    int unk00[15];
    float m_fScale;
    int unk40[6];
    float m_fMinCount;
    int unk5C;
    float m_afMaxCount[3];

    void ComputeNodeBounds(Node07400* node, Region07400* region);
};
struct Arg1Flags
{
    unsigned char unk00[0x3b];
    unsigned char m_3b[3];
};
struct Arg2Layout
{
    int unk00;
    int unk04;
    int unk08;
    Pair m_0c[3];
    int m_24;
    int m_28[3];
};
struct BufWriter
{
    int unk00;
    int unk04;
    int m_08;
    int m_0c;
    int m_10;
    void __thiscall Flush();
    void __thiscall WriteInt24(int v);
};
inline void EmitByte(BufWriter* w, unsigned char v)
{
    ((char*)(w->m_10 - w->m_0c))[w->m_08 - 1] = v;
    w->m_0c++;
    if (w->m_0c >= w->m_08)
    {
        w->Flush();
    }
}
struct FUN_00e07550_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BufWriter* m_10;
    void __thiscall hkpMoppDefaultAssembler_addCut(Arg1Flags* a1, Arg2Layout* a2);
};
extern "C" unsigned int __cdecl _rotl(unsigned int, int);
struct KdNode;
struct KdCtx;
struct KdCtx
{
    int level;
    char flag;
    char unk05;
    char unk06;
    char unk07;
    int shift;
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

    void __thiscall CopyOffsets(KdNode* k);
    void __thiscall BuildScaledRanges(KdNode* k, float* p);
    void __thiscall hkpMoppAssemblerNodeInfo_calcMaxExtentsSignificantBits();
};
struct KdNode
{
    int unk00;
    char leaf;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
    float b[6];
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    char unk38;
    char a;
    char bb;
    char cc[3];
    char unk3e;
    char unk3f;
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
    KdNode* ch[2];
};
struct MyTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int lim;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    float f3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    float f58;
    int unk5c;
    float f60[3];

    int __thiscall hkpMoppDefaultAssembler_calcRescaleBits(KdCtx* a, KdCtx* c);
    void __thiscall hkpMoppDefaultAssembler_recalcRescale(KdCtx* a, KdCtx* c, S_00e07070_Result* o);
    int __thiscall Recurse(KdNode* n, KdCtx* a, KdCtx* c);
};
#include <xmmintrin.h>
extern double _gModifierZero;
struct FUN_00e07b90_bounds
{
    float unk00, unk04, unk08, minimumX, maximumX, minimumY, maximumY, minimumZ, maximumZ;
};
struct FUN_00e07b90_vector
{
    float x, y, z, w;
};
void __stdcall hkpMoppDefaultAssembler_getScaleInfo(const FUN_00e07b90_bounds* bounds, FUN_00e07b90_vector* result);
struct S_00e07d60_Info
{
    float x;
    float y;
    float z;
    __m128 v;
    int i;
    char b;
};
struct S_00e07d60
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
    float x;
    float y;
    float z;
    __m128 v;
    int i;
    char b;
    void UpdateFields_00e07d60(const S_00e07d60_Info& info);
};
namespace e083 {
struct PairArray
{
    Pair* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct SrcW
{
    PairArray* p;
};
}
void __cdecl ResizeAudioStream(hkMemoryAllocator* a, void* arr, int elemSize);
static void copyJumpCommandInfo(e083::PairArray* srcp, e083::PairArray* dst, int delta);
void e08320_caller(e083::SrcW sw, e083::PairArray* dst, int delta);
void __cdecl ResizeAudioStream(void*, void*, int);
inline hkMemoryAllocator& GetHeap()
{
    return *(hkMemoryAllocator*)hkMemoryRouter_getInstance()->m_heap;
}
inline hkMemoryRouter* GetBvRouter()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}
template <class T>
static __forceinline void BvArray_clear(hkArrayBase<T>& self)
{
        for (int i = 0; i < self.m_iElementCount; ++i)
            self.m_data[i].~T();
        self.m_iElementCount = 0;
    }

template <class T>
static __forceinline void BvArray_ClearAndRelease(hkArrayBase<T>& self, hkMemoryAllocator& alloc)
{
        BvArray_clear(self);
        if ((self.m_iCapacityState & 0x80000000u) == 0)
            alloc.ReturnMemory(self.m_data, self.getCapacity() * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

template <class T>
static __forceinline void BvArray_AddBack(hkArrayBase<T>& self, hkMemoryRouter& router, const T& t)
{
        if (self.m_iElementCount == self.getCapacity())
            ResizeAudioStream(router.m_heap, (&self), sizeof(T));
        T* p = self.m_data + self.m_iElementCount;
        for (int i = 0; i < 1; i++)
            p[i] = t;
        self.m_iElementCount++;
    }
struct BvFixup
{
    int offset;
    int value;
};
struct FUN_00e065f0
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_pRayCursor;
    int m_offset;
    unsigned char* m_data;
    hkArrayBase<BvFixup> m_buffer;

    void FillWithPattern(int);
    void nullsub_26();
    FUN_00e065f0(unsigned int id) throw();
    void Destroy();
    void* operator new(unsigned int n)
    {
        FUN_00e065f0* p = static_cast<FUN_00e065f0*>(reinterpret_cast<hkMemoryAllocator*>(GetBvRouter()->m_heap)->blockAlloc(n));
        p->m_usMemSizeAndFlags = (unsigned short)n;
        return p;
    }
};
struct WriterEntry
{
    FUN_00e065f0* m_pStreamWriter;
    unsigned int m_iOwnerObjectOffset;
};
struct BvReferenceConverter
{
    virtual void v0();
    virtual int ConvertReferences(int*, int);
    virtual void writeBuffer(int*, int, unsigned char*);
};
struct BvTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    WriterEntry* m_entries;
    int unk14;
    int unk18;
    BvReferenceConverter* m_converter;
};
struct BvNode;
struct BvInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_uiEdgeIndex;
};
struct BvNode
{
    int unk00;
    bool m_isLeaf;
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
    int m_depth;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    BvInfo* m_info;
    int unk64;
    int unk68;
    int unk6c;
    BvNode* m_fMinimumU;
    BvNode* m_fMaximumU;
};
struct BvRange
{
    bool m_valid;
    int m_uiEdgeIndex;
    int unk08;
    int unk0c;
    int unk10;
};
void __stdcall hkpMoppDefaultAssembler_assembleCutAndTerminalCommand(struct BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack);
void* __cdecl hkString_memCpy(void*, const void*, int);
// src: HAVOK_LIB 0x00e08320
static void copyJumpCommandInfo(hkArrayBase<BvFixup>* destination, hkArrayBase<BvFixup>* source, int adjustment)
{
    for (int i = 0; i < source->m_iElementCount; ++i)
    {
        hkMemoryAllocator& heap = GetHeap();
        if (destination->m_iElementCount == destination->getCapacity())
            ResizeAudioStream(&heap, destination, sizeof(BvFixup));
        BvFixup* out = destination->m_data + destination->m_iElementCount;
        ++destination->m_iElementCount;
        out->value = source->m_data[i].value;
        out->offset = source->m_data[i].offset + adjustment;
    }
}
static int copyCodeAndEmbedTerminals(BvTree* tree, FUN_00e065f0* source, hkArrayBase<int>* refs, FUN_00e065f0* destination);
struct BvBuilder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00e065f0* m_pStreamWriter;
    BvTree* m_iValueAt40;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_info30;

    void hkpMoppDefaultAssembler_addDataOffset(int offset, int count);
    void hkpMoppDefaultAssembler_assembleJumpChunkCommand(BvNode* node);
    void hkpMoppDefaultAssembler_initTopDown(BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack, BvRange* range);
    void hkpMoppDefaultAssembler_assembleNonTerminalCommand(BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack, BvRange* range);
    void hkpMoppDefaultAssembler_assembleSubNodeIntoChunks(BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack, int depth, hkArrayBase<int>* refs);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
template <class T> __forceinline void constructCopy(T* p, int n, const T& value)
{
    for (int i = 0; i < n; ++i)
        p[i] = value;
}
void __cdecl ResizeAudioStream(hkMemoryAllocator*, void*, int);
struct P154Array
{
    int* data;
    int count;
    unsigned capacity;
    P154Array() : data(0), count(0), capacity(0x80000000)
    {}
    void Search(hkMemoryAllocator*, int, int*, int);
    void append(const int& v)
    {
        hkMemoryRouter* s = hkMemoryRouter_getInstance();
        if (count == int(capacity & 0x3fffffff))
            ResizeAudioStream(reinterpret_cast<hkMemoryAllocator*>(s->m_heap), this, 4);
        constructCopy(data + count, 1, v);
        ++count;
    }
    void insert(int* src, int pos, int n)
    {
        hkMemoryRouter* r = hkMemoryRouter_getInstance();
        hkMemoryAllocator* a = reinterpret_cast<hkMemoryAllocator*>(r->m_heap);
        Search(a, pos, src, n);
    }
    void clear()
    {
        hkMemoryRouter* r = hkMemoryRouter_getInstance();
        hkMemoryAllocator* a = reinterpret_cast<hkMemoryAllocator*>(r->m_heap);
        count = 0;
        if (!(capacity & 0x80000000))
            a->bufFree(data, (capacity & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }
};
struct P154Pair
{
    int first, second;
};
struct P154PairArray
{
    P154Pair* data;
    int count;
    unsigned capacity;
    P154Pair& grow()
    {
        hkMemoryRouter* s = hkMemoryRouter_getInstance();
        if (count == int(capacity & 0x3fffffff))
            ResizeAudioStream(reinterpret_cast<hkMemoryAllocator*>(s->m_heap), this, 8);
        for (int i = 0; i < 1; ++i)
            new (data + count + i) P154Pair;
        return data[count++];
    }
};
struct P154Cost
{
    virtual void v00();
    virtual int cost(int*, int);
};
struct P154Settings
{
    int limit, unk04, unk08, unk0c;
    P154PairArray pairs;
    P154Cost* metric;
    int base;
};
struct P154Writer
{
    int unk00, unk04, unk08, count;
};
struct P154Region
{
    int depth;
    char leaf;
    int unk08;
    int unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, context, unk38, unk3c, unk40, unk44;
    void CopyOffsets(struct P154Node*);
    void BuildScaledRanges(struct P154Node*, float*);
    void hkpMoppAssemblerNodeInfo_calcMaxExtentsSignificantBits();
};
struct P154Node
{
    int unk00;
    char leaf;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, index, unk44,
        unk48, unk4c, unk50, unk54, unk58, offset;
    int* values;
    int unk64, unk68, unk6c;
    P154Node* high;
    P154Node* low;
    __forceinline void shift(int amount, bool change)
    {
        if (change)
            offset += amount;
    }
};
__forceinline void adjustOffset(P154Node* node, int amount, bool change)
{
    if (change)
        node->offset += amount;
}
struct P154Result
{
    bool valid;
    int value;
    int unk08, unk0c, unk10;
};
struct P154Tree
{
    int unk00, unk04, unk08, unk0c;
    P154Writer* writer;
    P154Settings* settings;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    int scale30, scale34, scale38;
    void hkpMoppDefaultAssembler_assembleCutAndTerminalCommand(P154Node*, P154Region*, P154Region*);
    void hkpMoppDefaultAssembler_initTopDown(P154Node*, P154Region*, P154Region*, P154Result*);
    void hkpMoppDefaultAssembler_assembleNonTerminalCommand(P154Node*, P154Region*, P154Region*, P154Result*);
    __forceinline int getCost(P154Array& a, int size)
    {
        int result = size;
        if (settings->metric && a.count)
            result += settings->metric->cost(a.data, a.count);
        return result;
    }
    int hkpMoppDefaultAssembler_calcChunkPoints(P154Node*, P154Region*, P154Region*, P154Array*);
};

// Inline implementations used by the original assembler constructor.
inline hkSimdReal::hkSimdReal(const __m128& value) : m_vValue(value) {}
inline const __m128& hkSimdReal::getQuad() const { return m_vValue; }
inline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
template <typename TYPE> inline TYPE* hkMemoryAllocator::_bufAlloc(int& reqNumInOut)
{
    const int SIZE_ELEM = sizeof(TYPE);
    int n = reqNumInOut * SIZE_ELEM;
    void* p = bufAlloc(n);
    reqNumInOut = n / SIZE_ELEM;
    return static_cast<TYPE*>(p);
}

typedef signed char hkInt8;
typedef signed short hkInt16;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned __w64 hk_size_t;
class hkClass;
template <typename T> struct TypeSizeConstant
{
    enum
    {
        val = sizeof(T)
    };
};

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}
template <typename T, typename Allocator> __forceinline hkArray<T, Allocator>::hkArray(int n) : hkArrayBase<T>()
{
    hkMemoryAllocator& a = Allocator().get(this);
    T* p = n ? a._bufAlloc<T>(n) : 0;
    int cap = n ? n : hkArrayBase<T>::DONT_DEALLOCATE_FLAG;
    hkArrayBase<T>::setOwnedData(p, n, cap);
}
typedef float hkReal;
extern "C"
{
    extern __m128 _mm_add_ss(__m128 _A, __m128 _B);
    extern __m128 _mm_sub_ss(__m128 _A, __m128 _B);
    extern __m128 _mm_mul_ss(__m128 _A, __m128 _B);
    extern __m128 _mm_mul_ps(__m128 _A, __m128 _B);
    extern __m128 _mm_rsqrt_ss(__m128 _A);
    extern __m128 _mm_andnot_ps(__m128 _A, __m128 _B);
    extern __m128 _mm_cmpeq_ss(__m128 _A, __m128 _B);
    extern __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
    extern __m128 _mm_set_ss(float _A);
    extern __m128 _mm_setr_ps(float _A, float _B, float _C, float _D);
};
typedef __m128 hkQuadReal;
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    m_vComponents = _mm_setr_ps(a, b, c, d);
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))), xySum);
}
static inline hkSimdReal MoppLengthInverse3(const hkVector4& vector)
{
    const hkQuadReal half = _mm_set_ss(0.5f);
    const hkQuadReal three = _mm_set_ss(3.0f);
    const hkQuadReal zero = _mm_set_ss(0.0f);
    const hkQuadReal len2 = vector.dot3(vector).getQuad();
    const hkQuadReal len2EqualsZero = _mm_cmpeq_ss(len2, zero);
    const hkQuadReal approx = _mm_rsqrt_ss(len2);
    const hkQuadReal refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    return _mm_andnot_ps(len2EqualsZero, refined);
}
inline void hkVector4::normalize3()
{
    hkQuadReal lenInv = MoppLengthInverse3(*this).broadcast();
    m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
}
class hkpMoppMediator;
class hkpMoppNodeMgr;
class hkpMoppCodeGenerator;
class MoppBuildComponent;
struct MoppSplitPlane
{
    hkVector4 m_direction;
    hkReal m_fSplitOffset;
    int m_uiEdgeIndex;
};
class hkpMoppAssembler : public hkReferencedObject
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        hkReferencedObject* b = static_cast<hkReferencedObject*>(
            hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        ;
        return b;
    }
    struct MoppAssemblerSettings
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                hkMemoryRouter::getInstance().heap().blockFree(
                    p, sizeof(hkpMoppAssembler::MoppAssemblerSettings));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        MoppAssemblerSettings()
            : m_fFirstParameter(0.5f), m_fSecondaryScalar(0.2f), m_fTertiaryScalar(1.0f), m_iIntegerParameter(5)
        {
            m_kParameterVector.set(0.2f, 0.2f, 0.05f, 0.0f);
            m_bOptionEnabled = true;
        }
        hkReal m_fFirstParameter;
        hkReal m_fSecondaryScalar;
        hkReal m_fTertiaryScalar;
        hkVector4 m_kParameterVector;
        int m_iIntegerParameter;
        hkBool m_bOptionEnabled;
    };
};
class FUN_00e090c0 : public hkpMoppAssembler
{
  public:
    FUN_00e090c0(const MoppAssemblerSettings& ap, hkpMoppCodeGenerator* code, hkpMoppMediator* mediator);
    ~FUN_00e090c0();
    void updateParams(const MoppAssemblerSettings& ap);
    hkpMoppMediator* m_pMoppMediator;
    hkpMoppNodeMgr* m_pNodeManager;
    hkpMoppCodeGenerator* m_pMoppCode;
    MoppBuildComponent* m_pAdditionalAssemblerData;
    int m_iFirstValue;
    int m_iSecondValue;
    int m_iThirdValue;
    CodeInfo m_kMoppInfo;
    hkArray<MoppSplitPlane> kMoppArray;
    MoppAssemblerSettings m_params;
};
// @fnv 0x00e090c0
FUN_00e090c0::FUN_00e090c0(const MoppAssemblerSettings& ap, hkpMoppCodeGenerator* code, hkpMoppMediator* mediator)
    : kMoppArray(13)
{
    kMoppArray[0].m_direction.set(1.0f, 0.0f, 0.0f, 0.0f);
    kMoppArray[1].m_direction.set(0.0f, 1.0f, 0.0f, 0.0f);
    kMoppArray[2].m_direction.set(0.0f, 0.0f, 1.0f, 0.0f);
    kMoppArray[0].m_fSplitOffset = 0.0f;
    kMoppArray[1].m_fSplitOffset = 0.0f;
    kMoppArray[2].m_fSplitOffset = 0.0f;
    kMoppArray[3].m_direction.set(0.0f, 1.0f, 1.0f, 0.0f);
    kMoppArray[4].m_direction.set(1.0f, 0.0f, 1.0f, 0.0f);
    kMoppArray[5].m_direction.set(1.0f, 1.0f, 0.0f, 0.0f);
    kMoppArray[3].m_fSplitOffset = 0.2f;
    kMoppArray[4].m_fSplitOffset = 0.2f;
    kMoppArray[5].m_fSplitOffset = 0.2f;
    kMoppArray[6].m_direction.set(0.0f, 1.0f, -1.0f, 0.0f);
    kMoppArray[7].m_direction.set(1.0f, 0.0f, -1.0f, 0.0f);
    kMoppArray[8].m_direction.set(1.0f, -1.0f, 0.0f, 0.0f);
    kMoppArray[6].m_fSplitOffset = 0.25f;
    kMoppArray[7].m_fSplitOffset = 0.25f;
    kMoppArray[8].m_fSplitOffset = 0.25f;
    kMoppArray[9].m_direction.set(1.0f, 1.0f, 1.0f, 0.0f);
    kMoppArray[10].m_direction.set(1.0f, 1.0f, -1.0f, 0.0f);
    kMoppArray[11].m_direction.set(1.0f, -1.0f, 1.0f, 0.0f);
    kMoppArray[12].m_direction.set(1.0f, -1.0f, -1.0f, 0.0f);
    kMoppArray[9].m_fSplitOffset = 0.3f;
    kMoppArray[10].m_fSplitOffset = 0.32f;
    kMoppArray[11].m_fSplitOffset = 0.32f;
    kMoppArray[12].m_fSplitOffset = 0.34f;
    for (int i = 0; i < 13; i++)
    {
        kMoppArray[i].m_direction.normalize3();
        kMoppArray[i].m_uiEdgeIndex = i;
    }
    updateParams(ap);
    m_pMoppCode = code;
    m_pMoppMediator = mediator;
    m_pNodeManager = 0;
}
