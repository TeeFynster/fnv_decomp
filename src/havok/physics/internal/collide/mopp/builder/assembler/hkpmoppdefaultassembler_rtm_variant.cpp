#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/Pair.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/NiPoint3.h"
// src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


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
struct Allocator
{
    virtual void* unk00(void* p);
    virtual void* unk04(void* p);
    virtual void __thiscall ReleaseBlock(void* p, unsigned short size);
};
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
void __stdcall hkpMoppDefaultAssembler_getScaleInfo(const FUN_00e07b90_bounds* bounds, hkVector4* result);
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
struct Alloc;
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
void __cdecl ResizeAudioStream(e083::Alloc* a, void* arr, int elemSize);
static void copyJumpCommandInfo(e083::PairArray* srcp, e083::PairArray* dst, int delta);
void e08320_caller(e083::SrcW sw, e083::PairArray* dst, int delta);
struct BvAllocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(unsigned int);
    virtual void v8();
    virtual void vc();
    virtual void ReleaseBlock(void*, int);
};
void __cdecl ResizeAudioStream(void*, void*, int);
inline BvAllocator& GetHeap()
{
    return *(BvAllocator*)hkMemoryRouter::getInstance().m_heap;
}
template <class T>
static __forceinline void BvArray_clear(hkArrayBase<T>& self)
{
        for (int i = 0; i < self.m_iElementCount; ++i)
            self.m_data[i].~T();
        self.m_iElementCount = 0;
    }

template <class T>
static __forceinline void BvArray_ClearAndRelease(hkArrayBase<T>& self, BvAllocator& alloc)
{
        BvArray_clear(self);
        if ((self.m_iCapacityState & 0x80000000u) == 0)
            alloc.ReleaseBlock(self.m_data, self.getCapacity() * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

template <class T>
static __forceinline void BvArray_AddBack(hkArrayBase<T>& self, hkMemoryRouter& router, const T& t)
{
        if (self.m_iElementCount == self.getCapacity())
            ResizeAudioStream((Allocator*)router.m_heap, (&self), sizeof(T));
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
        FUN_00e065f0* p = static_cast<FUN_00e065f0*>(((BvAllocator*)hkMemoryRouter::getInstance().m_heap)->AllocateMemoryBlock(n));
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
        BvAllocator& heap = GetHeap();
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
struct P154Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void*, unsigned);
};
void __cdecl ResizeAudioStream(P154Allocator*, void*, int);
struct P154Array
{
    int* data;
    int count;
    unsigned capacity;
    P154Array() : data(0), count(0), capacity(0x80000000)
    {}
    void Search(P154Allocator*, int, int*, int);
    void append(const int& v)
    {
        hkMemoryRouter* s = (&hkMemoryRouter::getInstance());
        if (count == int(capacity & 0x3fffffff))
            ResizeAudioStream((P154Allocator*)s->m_heap, this, 4);
        constructCopy(data + count, 1, v);
        ++count;
    }
    void insert(int* src, int pos, int n)
    {
        hkMemoryRouter* r = (&hkMemoryRouter::getInstance());
        P154Allocator* a = (P154Allocator*)r->m_heap;
        Search(a, pos, src, n);
    }
    void clear()
    {
        hkMemoryRouter* r = (&hkMemoryRouter::getInstance());
        P154Allocator* a = (P154Allocator*)r->m_heap;
        count = 0;
        if (!(capacity & 0x80000000))
            a->Free(data, (capacity & 0x3fffffff) * 4);
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
        hkMemoryRouter* s = (&hkMemoryRouter::getInstance());
        if (count == int(capacity & 0x3fffffff))
            ResizeAudioStream((P154Allocator*)s->m_heap, this, 8);
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
struct CodeCopySource : FUN_00e065f0
{
};
static int copyCodeAndEmbedTerminals(BvTree* tree, CodeCopySource* source, hkArrayBase<int>* refs, FUN_00e065f0* destination);
int copy_code_caller(BvTree* tree, CodeCopySource* source, hkArrayBase<int>* refs, FUN_00e065f0* destination);
extern "C" void* __cdecl memset(void*, int, unsigned int);
struct ObjectWriter
{
    int unk00;
    int unk04;
    int m_cap;
    int m_pos;
    char* m_data;
    int unk14;
    int unk18;
    int unk1c;

    void FUN_00e065f0(int size) throw();
    ObjectWriter(int size) throw()
    {
        FUN_00e065f0(size);
    }
    void Destroy() throw();
    ~ObjectWriter() throw()
    {
        Destroy();
    }
    void FUN_00c90510() throw();
};
struct HelperEntry
{
    ObjectWriter* ptr;
    int pos;
};
struct EntryArray
{
    HelperEntry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct AssemblerHelper
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    EntryArray m_entries;
    int unk1C;
};
template <typename T> struct MyArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline MyArray() throw()
    {
        memset(this, 0, 8);
        m_iCapacityState = 0x80000000;
    }
    __forceinline ~MyArray() throw()
    {
        hkMemoryRouter* holder = (hkMemoryRouter*)(&hkMemoryRouter::get());
        hkMemoryAllocator* alloc = holder->m_pAllocator;
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            alloc->FreeArray(m_data, (m_iCapacityState & 0x3fffffff) * 4);
    }
    __forceinline void ClearAndRelease() throw()
    {
        hkMemoryAllocator* alloc = ((hkMemoryRouter*)(&hkMemoryRouter::get()))->m_pAllocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & 0x80000000))
        {
            int bytes = (cap & 0x3fffffff) * 4;
            alloc->FreeArray(m_data, bytes);
        }
        m_data = 0;
        m_iElementCount = 0;
    }
};
struct __declspec(align(8)) MyBounds
{
    int unk00;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
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

    void BuildScaledRanges(S_00e07da0_Node* node, void* p) throw();
    void CopyOffsets(S_00e07da0_Node* node) throw();
    void hkpMoppAssemblerNodeInfo_calcMaxExtentsSignificantBits() throw();
};
struct __declspec(align(8)) MyRegion : public MyBounds
{
    int lo48_0;
    int lo48_1;
    int lo48_2;
    int hi54_0;
    int hi54_1;
    int hi54_2;

    void CopyOffsets(S_00e07da0_Node* node) throw();
    void BuildScaledRanges(S_00e07da0_Node* node, void* p) throw();
    void hkpMoppAssemblerNodeInfo_calcMaxExtentsSignificantBits() throw();
    void UpdateState_00e095d0(MyBounds* src, S_00e07da0_Node* node, void* p) throw();
};
extern "C" void __cdecl copyCodeAndEmbedTerminals(AssemblerHelper*, ObjectWriter*, void*) throw();
struct Tree : public FUN_00e09640_class
{
    virtual void vf04() throw();
    virtual void vf08() throw();
    virtual void vf0c() throw();
    virtual void vf10() throw();
    virtual void hkpMoppDefaultAssembler_assemble(S_00e07da0_Node* node, int arg2, int arg3);
    virtual void vf18(S_00e07da0_Node* node, void* p) throw();

    int unk08;
    int unkC;
    ObjectWriter* m_stream;
    AssemblerHelper* m_pAssemblerHelper;
    int unk18;
    int unk1C;
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

    void Recurse(S_00e07da0_Node* node, MyBounds* b, MyRegion* r) throw();
    void BuildRegion(S_00e07da0_Node* node, MyRegion* r1, MyRegion* r2) throw();
    void OptimizeTree(S_00e07da0_Node* node, MyBounds* b1, MyBounds* b2) throw();
    void hkpMoppDefaultAssembler_calcChunkPoints(S_00e07da0_Node* node, MyBounds* b, MyRegion* r, void* arr) throw();
    void hkpMoppDefaultAssembler_calcTerminalIdsForChunks(S_00e07da0_Node* node, int a, int b) throw();
    void hkpMoppDefaultAssembler_assembleSubNodeIntoChunks(S_00e07da0_Node* node, MyBounds* b1, MyBounds* b2, int a, void* arr) throw();
    void hkpMoppDefaultAssembler_addDataOffset(int a, int b) throw();
};
typedef void(__thiscall* Vf18Fn)(Tree*, S_00e07da0_Node*, void*) throw();

namespace E078Intrinsics {
// Exe 0x00e07880 FUN_00e07880: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_set_ps(float, float, float, float);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    void _mm_store_ss(float*, LocalM128);
    float _mm_cvtss_f32(LocalM128);
    LocalM128 _mm_load_ss(const float*);
}
}

typedef E078Intrinsics::LocalM128 E078Quad;
typedef float hkReal;

struct ScalarLane
{
    E078Quad data;
    __forceinline ScalarLane(float x)
    {
        data = E078Intrinsics::_mm_load_ss(&x);
    }
    __forceinline E078Quad splat() const
    {
        return E078Intrinsics::_mm_shuffle_ps(data, data, 0);
    }
};


__forceinline void hkVector4::set(hkReal x, hkReal y, hkReal z, hkReal w)
{
    reinterpret_cast<E078Quad&>(m_vComponents) = E078Intrinsics::_mm_setr_ps(x, y, z, w);
}

__forceinline void hkVector4::mul4(const ScalarLane& s)
{
    reinterpret_cast<E078Quad&>(m_vComponents) = E078Intrinsics::_mm_mul_ps(s.splat(), reinterpret_cast<const E078Quad&>(m_vComponents));
}

__forceinline void hkVector4::add4(const __m128& v)
{
    reinterpret_cast<E078Quad&>(m_vComponents) = E078Intrinsics::_mm_add_ps(reinterpret_cast<const E078Quad&>(m_vComponents), reinterpret_cast<const E078Quad&>(v));
}

__forceinline hkReal hkVector4::dot3scalar(const hkVector4& v) const
{
    E078Quad x2 = E078Intrinsics::_mm_mul_ps(reinterpret_cast<const E078Quad&>(m_vComponents),
                                         reinterpret_cast<const E078Quad&>(v.m_vComponents));
    E078Quad xy = E078Intrinsics::_mm_add_ss(E078Intrinsics::_mm_shuffle_ps(x2, x2, 0x55), x2);
    E078Quad xyz = E078Intrinsics::_mm_add_ss(E078Intrinsics::_mm_shuffle_ps(x2, x2, 0xaa), xy);
    float out;
    E078Intrinsics::_mm_store_ss(&out, xyz);
    return out;
}

struct hkVector4Unaligned
{
    hkReal x, y, z, w;
};

union hkVector4Copy
{
    hkVector4Unaligned m_v;
    E078Quad m_q;
};

hkReal hkMath_hkFloor(hkReal f);
int hkMath_hkFloatToInt(hkReal f);
int hkMath_hkFloorToInt(hkReal f);
extern "C" const double DAT_010ea5c0;

struct QuantNode
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
    const hkVector4* m_vHitNormal;
    hkReal m_kMinimumCorner;
    hkReal m_kMaximumCorner;
};

struct KdRegion
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
    int m_iIndex;
    int m_offset[3];
};

struct KdQuantizer
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
    hkVector4Unaligned m_vRayOrigins;

    void hkpMoppDefaultAssembler_findPlanes(const QuantNode* node, const KdRegion* region, int* hiOut, int* loOut);
};

static __forceinline int toCell(hkReal scale, double x)
{
    return hkMath_hkFloatToInt(hkMath_hkFloor(x * scale));
}

static __forceinline int clampIndex(int i)
{
    if (i <= 0)
    {
        return 0;
    }
    if (i >= 255)
    {
        return 255;
    }
    return i;
}

// @fnv 0x00e07880
// src: XBOX_PDB 0x00e07880
void KdQuantizer::hkpMoppDefaultAssembler_findPlanes(const QuantNode* node, const KdRegion* region, int* hiOut, int* loOut)
{
    const hkReal* n = &node->m_vHitNormal->m_vComponents.m128_f32[0];
    int numNonZero = 0;
    int numNegative = 0;
    int axis = 0;
    for (int i = 0; i < 3; i++)
    {
        hkReal c = n[i];
        if (c != 0.0f)
        {
            numNonZero++;
            axis = i;
            if (c < 0.0f)
            {
                numNegative++;
            }
        }
    }

    double minDist = node->m_kMinimumCorner;
    double maxDist = node->m_kMaximumCorner;

    if (numNonZero == 1)
    {
        const hkReal* origin = &m_vRayOrigins.x;
        int lo = toCell(m_vRayOrigins.w, minDist - origin[axis]);
        int hi = toCell(m_vRayOrigins.w, maxDist - origin[axis]);
        int offset = region->m_offset[axis];
        lo = (lo - offset) >> region->m_iIndex;
        hi = ((hi - offset) >> region->m_iIndex) + 1;
        lo = clampIndex(lo);
        hi = clampIndex(hi);
        *loOut = lo;
        *hiOut = hi;
        if (*loOut < 0)
        {
            *loOut = 0;
        }
        return;
    }

    hkReal scale = m_vRayOrigins.w;
    hkVector4Copy origin;
    origin.m_v = m_vRayOrigins;

    hkVector4 p;
    p.set((hkReal)region->m_offset[0], (hkReal)region->m_offset[1], (hkReal)region->m_offset[2], 0.0f);
    p.mul4(ScalarLane(1.0f / scale));
    p.add4(reinterpret_cast<const __m128&>(origin.m_q));
    double d = p.dot3scalar(*node->m_vHitNormal);

    hkReal cellSize = (hkReal)(1 << region->m_iIndex);
    double lo = (minDist - d) * m_vRayOrigins.w / cellSize;
    maxDist = (maxDist - d) * m_vRayOrigins.w / cellSize;

    double stretch = 1.0;
    double norm = 1.0;
    if (numNonZero == 2)
    {
        stretch = 1.4142135381698608;
        norm = 0.5;
    }
    else if (numNonZero == 3)
    {
        stretch = DAT_010ea5c0;
        norm = 0.3333333432674408;
    }

    double dlo = lo * stretch;
    maxDist *= stretch;
    if (numNegative)
    {
        dlo += numNegative * 255;
        maxDist += numNegative * 255;
    }

    int ilo = hkMath_hkFloorToInt((hkReal)(dlo * norm));
    int ihi = hkMath_hkFloorToInt((hkReal)(maxDist * norm)) + 1;
    ilo = clampIndex(ilo);
    ihi = clampIndex(ihi);
    *loOut = ilo;
    *hiOut = ihi;
}
