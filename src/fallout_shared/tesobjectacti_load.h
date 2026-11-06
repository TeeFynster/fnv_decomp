// fallout_shared/tesobjectacti_load.h: declares TESScriptableForm, TESObject, ShortPoint3, TESBoundObject__BOUND_DATA, TESBoundObject and more
#ifndef FNV_TESOBJECTACTI_H
#define FNV_TESOBJECTACTI_H

#include "tesobjectacti_layout.h"
#include "BaseFormComponent.h"
#include "layout_support.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#define FNV_TESSCRIPTABLEFORM_H
class Script;
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;
    bool m_bHasScript;
    char padding[3];
    void InitItem(TESForm*);
};
#include "tesobjectacti_layout.h"
class BGSDestructibleObjectForm;
class BGSOpenCloseForm;
class BGSTalkingActivator;
class BSFileEntry;
class CollisionComponent;
class ShortPoint3;
class TESBoundAnimObject;
class TESBoundObject__BOUND_DATA;
class TESMagicTargetForm;
class TESModel;
class TESModelTextureSwap;
class TESObjectACTI;
class TESFormList;
class FileEntryList;
class TESWaterForm;
class DistantTreeTextureInfo;
#pragma pack(push, 4)
class TESObject : public TESForm
{
  public:
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObject) == 36);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pOwningList) == 24);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pPreviousObject) == 28);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pNextObject) == 32);
#pragma pack(push, 4)
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);
#pragma pack(push, 4)
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);
#pragma pack(push, 4)
class TESBoundObject : public TESObject
{
  public:
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);
#pragma pack(push, 4)
class TESBoundAnimObject : public TESBoundObject
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundAnimObject) == 48);
#pragma pack(push, 4)
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    static void LoadModelData(TESModel*, TESFile*);
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
#pragma pack(push, 4)
class TESModelTextureSwap : public TESModel
{
  public:
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModelTextureSwap) == 32);
FNV_STATIC_ASSERT(offsetof(TESModelTextureSwap, TextureSwapNodeAccessor) == 24);
#pragma pack(push, 4)
class TESMagicTargetForm
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESMagicTargetForm) == 1);
#pragma pack(push, 4)
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
    CollisionComponent* pData;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSDestructibleObjectForm, pData) == 4);
#pragma pack(push, 4)
class BGSOpenCloseForm
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSOpenCloseForm) == 4);
FNV_STATIC_ASSERT(offsetof(BGSOpenCloseForm, m_ppVirtualMethodTable) == 0);
#pragma pack(push, 4)
class TESObjectACTI : public TESBoundAnimObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESScriptableForm,
                      public BGSDestructibleObjectForm,
                      public BGSOpenCloseForm,
                      public TESMagicTargetForm
{
  public:
    TESSound* m_pSoundEffect;                  // +0x74, 4 bytes
    TESSound* m_pLoopSound;                    // +0x78, 4 bytes
    TESSound* pRadioTemplate;                  // +0x7C, 4 bytes
    TESWaterForm* m_pWaterForm;                // +0x80, 4 bytes
    BGSTalkingActivator* m_pTalkingActivator;  // +0x84, 4 bytes
    BSStringT<char> m_kActivationPrompt;       // +0x88, 8 bytes
    void ResetFormData();
    virtual bool Load(TESFile*);
    void SetLoopingSound(TESSound*);
    void SetActivationPrompt(BSStringT<char>);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObjectACTI) == 144);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, m_pSoundEffect) == 116);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, m_pLoopSound) == 120);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, pRadioTemplate) == 124);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, m_pWaterForm) == 128);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, m_pTalkingActivator) == 132);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, m_kActivationPrompt) == 136);
#endif

class TESEffectShader;
class EffectSetting
{
  public:
    void SetEffectShader(TESEffectShader*);
    void SetEnchantEffectShader(TESEffectShader*);
    void SetCastSound(TESSound*);
    void SetBoltSound(TESSound*);
};
class CombatController;
class CombatProcedure
{
  public:
    void Initialize(CombatController*);
};
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
