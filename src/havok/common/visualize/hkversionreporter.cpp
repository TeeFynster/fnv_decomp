
// src/havok/common/visualize/hkversionreporter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkversionreporter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n);
};
struct S_Router
{
    int unk0;
    int unk4;
    int unk8;
    S_Alloc* m0c;
    S_Alloc* m10;
    S_Alloc& temp()
    {
        return *m0c;
    }
    S_Alloc& heap()
    {
        return *m10;
    }
};
S_Router* hkMemoryRouter_getInstance();
int hkString_strLen(const char* s);

struct S_Arr
{
    char* data;
    int size;
    int cap;
    void clear(S_Alloc& a)
    {
        size = 0;
        if ((cap & 0x80000000) == 0)
            a.ReturnMemory(data, cap & 0x3fffffff);
        data = 0;
        cap = 0x80000000;
    }
};

struct S_Writer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
struct S_Out
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_Out* FUN_00dda690(S_Arr* a);
    S_Out* FUN_00dda6e0(const char* name);
    void hkOArchive_write8u(unsigned v);
    void WriteInt(unsigned v);
    void WriteUInt16(unsigned v);
    void hkOArchive_writeRaw(const void* p, int n);
    void ReleaseReference_00d60590();
};
struct S_Str : S_Arr
{
    S_Str* InitBuffer();
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
    int unk80;
    int unk84;
    int unk88;
};
int hkStringBuf_printf(S_Str* s, const char* fmt, ...);
extern int DAT_011b5dc0;
extern int DAT_011b5dbc;

// Builds a string with the PC_32 value and "MSVC:1500", writes both into a stream, then writes the accumulated buffer to the named output and clears the buffers.
// @fnv 0x00d61290
int WriteCompilerInfo(const char* name)
{
    S_Arr buffer;
    buffer.data = 0;
    buffer.size = 0;
    buffer.cap = 0x80000000;
    S_Out outStream;
    outStream.FUN_00dda690(&buffer);
    outStream.hkOArchive_write8u(0x90);
    outStream.WriteInt(DAT_011b5dc0);
    outStream.WriteInt(DAT_011b5dbc);
    int n = hkString_strLen("PC_32");
    if (n > 0xffff)
        n = 0xffff;
    outStream.WriteUInt16(n);
    outStream.hkOArchive_writeRaw("PC_32", n);
    S_Str versionStr;
    versionStr.InitBuffer();
    hkStringBuf_printf(&versionStr, "%s:%i", "MSVC", 1500);
    int iVersionLen = versionStr.size - 1;
    if (iVersionLen > 0xffff)
        iVersionLen = 0xffff;
    outStream.WriteUInt16(iVersionLen);
    outStream.hkOArchive_writeRaw(versionStr.data, iVersionLen);
    S_Out f;
    f.FUN_00dda6e0(name);
    f.WriteInt(buffer.size);
    f.hkOArchive_writeRaw(buffer.data, buffer.size);
    f.ReleaseReference_00d60590();
    versionStr.clear(hkMemoryRouter_getInstance()->temp());
    outStream.ReleaseReference_00d60590();
    buffer.clear(hkMemoryRouter_getInstance()->heap());
    return 0;
}
