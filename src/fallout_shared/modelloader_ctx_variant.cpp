
// modelloader_ctx_variant.cpp: context variant of src/fallout_shared/modelloader.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "../../include/AutoMemContext.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiNode.h"
#include "../../include/NiPointer.h"
#include "../../include/NiRenderer.h"
NiRenderer* FUN_0043c4b0();
const NiFixedString& FUN_00448a80();

NiRenderer* FUN_0043c4b0();
const NiFixedString& FUN_00448a80();

class H_A100
{
  public:
    void* GetSizeMasked();
};

class FUN_0043c3b0_This
{
  public:
    int FUN_0043c3b0();
};

class FUN_0043e480_shell
{
  public:
    void FUN_0043e480(bool);
};

class FUN_0043c3d0_shell
{
  public:
    bool FUN_0043c3d0();
};

class TextureNode
{
  public:
    int FUN_0043c430();
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
};

class MyFileEntry
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual const char* vfn_18();
};

extern int DAT_011a9598;
void GetNodePointer(NiNode*, NiPointer<NiNode>&);
bool fnv_NiStreamGetTexture(const char*, NiPointer<NiNode>&);
int FUN_0043c410();
void FUN_0043c3f0(unsigned int);
extern "C" char* strstr(const char*, const char*);
NiNode* FUN_00a61040(const NiFixedString&, MyFileEntry*, NiRenderer*, void*);
NiNode* FUN_00a5fe30(MyFileEntry*, const char*, void*, int);
void FNV_Warning(const char*, ...);

class CQueuedTexture
{
  public:
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
    const char* unk28;
    void* unk2c;
    NiPointer<NiNode> unk30;
    int unk34;

    void* GetArchiveFileEntry();
    const char* GetFilePath();
    MyFileEntry* FUN_00c3cff0(int, int);

    void FUN_0043c150();
};

// @fnv 0x0043c150
void CQueuedTexture::FUN_0043c150()
{
    AutoMemContext memContext(this->unk18, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 695);

    if (this->GetArchiveFileEntry())
    {
        GetNodePointer((NiNode*)this->GetArchiveFileEntry(), this->unk30);
    }
    else if (this->GetFilePath())
    {
        fnv_NiStreamGetTexture(this->GetFilePath(), this->unk30);
    }

    if (this->unk30)
    {
        ((FUN_0043e480_shell*)(void*)this)->FUN_0043e480(true);
        if (((TextureNode*)(void*)(NiNode*)this->unk30)->FUN_0043c430() == 3 &&
            !((FUN_0043c3d0_shell*)(void*)this)->FUN_0043c3d0())
        {
            ((TextureNode*)(void*)(NiNode*)this->unk30)->vfn_8c();
        }
        return;
    }

    MyFileEntry* fileEntry = this->FUN_00c3cff0(1, 2);
    if (fileEntry)
    {
        int tlsVal;
        const char* path = fileEntry->vfn_18();
        tlsVal = FUN_0043c410();
        if (((FUN_0043c3d0_shell*)(void*)this)->FUN_0043c3d0())
        {
            FUN_0043c3f0(1);
        }
        if (strstr(path, "_e.dd"))
        {
            this->unk30 = FUN_00a61040(NiFixedString(path), fileEntry, FUN_0043c4b0(), &DAT_011a9598);
        }
        else
        {
            this->unk30 = FUN_00a5fe30(fileEntry, path, &DAT_011a9598, 1);
        }
        FUN_0043c3f0(tlsVal);
    }
    else if (this->GetArchiveFileEntry())
    {
        FNV_Warning("MODELS: Could not get file for texture with file entry offset %i and size %i.",
                    ((FUN_0043c3b0_This*)(void*)this->GetArchiveFileEntry())->FUN_0043c3b0(),
                    ((H_A100*)(void*)this->GetArchiveFileEntry())->GetSizeMasked());
    }
    else if (this->GetFilePath())
    {
        FNV_Warning("MODELS: Could not get file for texture %s.", this->GetFilePath());
    }
}
