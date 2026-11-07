
// modelloader_ctx_variant.cpp: context variant of src/fallout_shared/modelloader.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "../../include/AutoMemContext.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiNode.h"
#include "../../include/NiPointer.h"
#include "../../include/NiRenderer.h"
NiRenderer* NiXenonRenderer_GetRenderer();
const NiFixedString& BSXFlags_Tag();

NiRenderer* NiXenonRenderer_GetRenderer();
const NiFixedString& BSXFlags_Tag();

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
    void QueuedKF_SetAlreadyInKFMap(bool);
};

class FUN_0043c3d0_shell
{
  public:
    bool QueuedTexture_GetLoadDegraded();
};

class TextureNode
{
  public:
    int NiTexture_GetTextureQualityLevel();
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
int NiTexture_GetLoadMethod();
void NiTexture_SetLoadMethod(unsigned int);
extern "C" char* strstr(const char*, const char*);
NiNode* NiSourceCubeMap_Create(const NiFixedString&, MyFileEntry*, NiRenderer*, void*);
NiNode* NiSourceTexture_CreateTexture(MyFileEntry*, const char*, void*, int);
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

    void QueuedTexture_Run();
};

// @fnv 0x0043c150
// src: XBOX_PDB 0x0043c150
void CQueuedTexture::QueuedTexture_Run()
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
        ((FUN_0043e480_shell*)(void*)this)->QueuedKF_SetAlreadyInKFMap(true);
        if (((TextureNode*)(void*)(NiNode*)this->unk30)->NiTexture_GetTextureQualityLevel() == 3 &&
            !((FUN_0043c3d0_shell*)(void*)this)->QueuedTexture_GetLoadDegraded())
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
        tlsVal = NiTexture_GetLoadMethod();
        if (((FUN_0043c3d0_shell*)(void*)this)->QueuedTexture_GetLoadDegraded())
        {
            NiTexture_SetLoadMethod(1);
        }
        if (strstr(path, "_e.dd"))
        {
            this->unk30 = NiSourceCubeMap_Create(NiFixedString(path), fileEntry, NiXenonRenderer_GetRenderer(), &DAT_011a9598);
        }
        else
        {
            this->unk30 = NiSourceTexture_CreateTexture(fileEntry, path, &DAT_011a9598, 1);
        }
        NiTexture_SetLoadMethod(tlsVal);
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
