
// src/gamebryo2.2/corelibs/nicollision/niboundingvolume.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/niboundingvolume.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00e9cb10_BinStream;
typedef unsigned int (*S_00e9cb10_WriteFn)(S_00e9cb10_BinStream*, const void*, unsigned int, unsigned int*,
                                           unsigned int);
struct S_00e9cb10_BinStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    int unk8;
    S_00e9cb10_WriteFn m_pfnWrite;
    inline unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int w = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += w;
        return w;
    }
};
template <class T> inline void S_00e9cb10_SaveBinary(S_00e9cb10_BinStream& s, T& v)
{
    unsigned int comp = sizeof(T);
    s.BinaryWrite(&v, sizeof(T), &comp, 1);
}
struct S_00e9cb10_Stream
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    S_00e9cb10_BinStream* m_pBackingStream;
};
struct S_00e9cb10_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    void SaveValueToStream(S_00e9cb10_Stream* s);
};
// @fnv 0x00e9cb10
void S_00e9cb10_Obj::SaveValueToStream(S_00e9cb10_Stream* apStream)
{
    int v = v3();
    S_00e9cb10_SaveBinary(*apStream->m_pBackingStream, v);
}

extern void(__cdecl* DAT_0126fa7c)(void);

struct e9Sink
{
    int m_00;
    int m_04;
    int(__cdecl* m_pfnRead)(e9Sink*, void*, int, int*, int);
    void Read(void* pBuf, int iBytes)
    {
        int iCount = iBytes;
        m_04 += m_pfnRead(this, pBuf, iBytes, &iCount, 1);
    }
};

struct e9Obj
{
    char m_auiShapeKeys[0x24c];
    e9Sink* m_pSink;
};

typedef unsigned int(__cdecl* e9Dispatch)(e9Obj*);

// Reads a 4-byte type from the object's sink and dispatches to the handler at DAT_0126fa7c[type] when the type is in 0..5, otherwise returns 0.
// @fnv 0x00e9cab0
// src: XBOX_PDB 0x00e9cab0
unsigned int __cdecl NiBoundingVolume_CreateFromStream(e9Obj* pObj)
{
    int iType;
    pObj->m_pSink->Read(&iType, 4);
    if (iType < 0)
        return 0;
    if (iType < 6)
        return ((e9Dispatch*)&DAT_0126fa7c)[iType](pObj);
    return 0;
}
