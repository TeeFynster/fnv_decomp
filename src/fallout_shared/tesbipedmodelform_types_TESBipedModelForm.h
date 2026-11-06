// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESBIPEDMODELFORM_H
#define FNV_TESBIPEDMODELFORM_H
#include "layout_support.h"
#include "tesbipedmodelform_types_BIPED_OBJECT.h"
#include "tesbipedmodelform_types_SEX.h"
#include "BaseFormComponent.h"
#include "layout_support.h"
class BGSMessageIcon;
class BipedModelForm;
class BSFileEntry;
class BSFaceGenModel;
class TESBipedModelForm;
class TESModel;
class TESModelRDT;
class TESModelTextureSwap;
class FileEntryList;
class DistantTreeTextureInfo;
class TESForm;
#include "../../include/TESIcon.h"
class BGSBipedModelList;
class BipedAnim;
#pragma pack(push, 4)
class BipedModelForm
{
  public:
    unsigned int m_uiBipedModelFlags;  // +0x0, 4 bytes
    union
    {
        unsigned int sFlagsAndPadding;  // +0x4, 4 bytes
        struct
        {
            unsigned char m_ucBipedModelData;
            unsigned char layoutPadding5[3];
        };
    };
    // void __cdecl BipedModelForm::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BipedModelForm) == 8);
FNV_STATIC_ASSERT(offsetof(BipedModelForm, m_uiBipedModelFlags) == 0);
FNV_STATIC_ASSERT(offsetof(BipedModelForm, m_ucBipedModelData) == 4);
#include "../../include/FileEntryList.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/TESModelRDT.h"
#pragma pack(push, 4)
class TESBipedModelFormBase
{
  public:
    TESBipedModelFormBase();
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent*);
    virtual bool CompareWithBase(BaseFormComponent*);
};
#pragma pack(pop)
#include "../../include/TESBipedModelForm.h"
#endif
