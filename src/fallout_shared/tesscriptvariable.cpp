// fallout_shared/tesscriptvariable.cpp: SL_standin, Rec (6 functions)

#include "tesscriptvariable_decls.h"
#include "TESFile.h"
#include "ScriptVariableInfo.h"

// Reads a 24-byte chunk from the file when its chunk ID matches, then converts endianness if required.
// @fnv 0x005e2a20
void ScriptVariableInfo::Load(TESFile* file)
{
    if (file && file->GetChunkID() == 0x44534c53)
    {
        file->GetChunkData(this, 24);
        if (file->IsEndianConversionRequired())
            reinterpret_cast<ScriptVariableEndian*>(this)->ProcessState_005e2870();
    }
}

struct SL_standin
{
    SL_standin* SCRIPT_LOCAL_SCRIPT_LOCAL(SL_standin* apCopy);
};
// Copies the byte at offset 0x10, the uint at offset 0, and the double at offset 8 from apCopy into this, then returns this.
// @fnv 0x005ac150
// src: XBOX_PDB 0x005ac150
SL_standin* SL_standin::SCRIPT_LOCAL_SCRIPT_LOCAL(SL_standin* apCopy)
{
    *((char*)this + 0x10) = *((char*)apCopy + 0x10);
    *(unsigned int*)this = *(unsigned int*)apCopy;
    *(double*)((char*)this + 8) = *(double*)((char*)apCopy + 8);
    return this;
}

// Zeroes the object's first field, sets the double at offset 0x8 to 0.0, clears the bool at 0x10, and returns the object.
// @fnv 0x005e28e0
// src: GUESS 0x005e28e0 (confidence: low)
ScriptLocalVariable* __fastcall Object_ComputeValue_005e28e0(ScriptLocalVariable* apObject)
{
    *(unsigned int*)((char*)apObject + 0x0) = 0;
    *(double*)((char*)apObject + 0x8) = 0.0;
    *(bool*)((char*)apObject + 0x10) = false;
    return apObject;
}

struct Dummy00501c30
{
    bool FUN_00501c30(const char*);
};

struct FUN_005e29a0_shell
{
    void* m_p;
    double m_iFourthElementInteger;
    unsigned char m_kPointB;
    char m_pAuxiliaryObject[3];
    Dummy00501c30 m_dum;
    bool ProcessAndReturnValue_005e29a0(FUN_005e29a0_shell* other);
};

// @fnv 0x005e29a0
// src: GUESS 0x005e29a0 (confidence: low)
bool FUN_005e29a0_shell::ProcessAndReturnValue_005e29a0(FUN_005e29a0_shell* other)
{
    if (!other)
        return true;
    if (m_kPointB != other->m_kPointB)
        return true;
    if (m_p != other->m_p)
        return true;
    if (m_iFourthElementInteger != other->m_iFourthElementInteger)
        return true;
    if (((Dummy00501c30*)((char*)this + 0x18))->FUN_00501c30((const char*)other + 0x18))
        return true;
    return false;
}

template <int N> struct EndianSizeTag
{
    char v;
};

void __cdecl BSEndian(unsigned char*, EndianSizeTag<0>);
void __cdecl BSEndian(unsigned char*, EndianSizeTag<1>);
void __cdecl BSEndian(unsigned char*, EndianSizeTag<10>);

struct FUN_00414220_shell
{
    void SCRIPT_HEADER_Endian();
};

// @fnv 0x00414220
// src: XBOX_PDB 0x00414220
void FUN_00414220_shell::SCRIPT_HEADER_Endian()
{
    BSEndian((unsigned char*)this, EndianSizeTag<0>());
    BSEndian((unsigned char*)this + 4, EndianSizeTag<1>());
    BSEndian((unsigned char*)this + 8, EndianSizeTag<0>());
    BSEndian((unsigned char*)this + 12, EndianSizeTag<0>());
}

namespace fnv_005e2910 {
struct FUN_005e28e0
{
    int v;
    FUN_005e28e0();
};
struct FUN_004037b0
{
    int a, b;
    FUN_004037b0();
    ~FUN_004037b0();
    FUN_004037b0& CallAndReturnSelf(const FUN_004037b0&);
    FUN_004037b0& operator=(const FUN_004037b0& o)
    {
        return CallAndReturnSelf(o);
    }
};
struct Rec
{
    FUN_005e28e0 m0;
    int unk04;
    double d8;
    char c10;
    char pad11;
    char pad12;
    char pad13;
    int unk14;
    FUN_004037b0 m18;
    Rec(const Rec& o);
};
// Copy-constructs Rec by copying m0.v, d8, c10, and m18 from the source Rec.
// @fnv 0x005e2910
Rec::Rec(const Rec& aRec)
{
    m0.v = aRec.m0.v;
    d8 = aRec.d8;
    c10 = aRec.c10;
    m18.CallAndReturnSelf(aRec.m18);
}
}  // namespace fnv_005e2910
