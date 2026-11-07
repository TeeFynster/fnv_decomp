// src/fallout_shared/bgstextureset_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/bgstextureset.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy /GF (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.


// Fallout: New Vegas decompilation: fallout_shared/bgstextureset.cpp.
#include "layout_support.h"
#include "../../include/NiPointer.h"
#include "../../include/ARCHIVE_TYPE_INDEX.h"
#include "../../include/NiPoint2.h"
#include "../../include/BSShaderManager.h"
#include "../../include/NiTexture.h"
#include "../../include/BGSTextureSet.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESObject.h"

#include "../../include/BSTextureSet.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"

class BSFileEntry;
class BSTextureSet;
class DecalData;
class ShortPoint3;
class TESBoundObject__BOUND_DATA;
class TESFormList;
class QueuedFile;

#pragma pack(push, 4)
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);

#pragma pack(push, 4)
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);

#pragma pack(push, 4)
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTextureSet) == 8);
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);

FNV_STATIC_ASSERT(sizeof(BGSTextureSet) == 0xA0);
FNV_STATIC_ASSERT(offsetof(BGSTextureSet, pTextures) == 56);
FNV_STATIC_ASSERT(offsetof(BGSTextureSet, m_pDecalData) == 128);
FNV_STATIC_ASSERT(offsetof(BGSTextureSet, iFlags) == 132);
FNV_STATIC_ASSERT(offsetof(BGSTextureSet, m_ppTextureFileEntries) == 136);

// DecalData::`scalar deleting destructor' (0x007b3fa0); layout copied
#pragma pack(push, 4)
#include "../../include/DecalData.h"
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DecalData::DataRecordView) == 36);
FNV_STATIC_ASSERT(offsetof(DecalData::DataRecordView, m_fDecalMinWidth) == 0);
FNV_STATIC_ASSERT(offsetof(DecalData::DataRecordView, m_fDecalMaxWidth) == 4);
FNV_STATIC_ASSERT(offsetof(DecalData::DataRecordView, m_fDecalMinHeight) == 8);
FNV_STATIC_ASSERT(offsetof(DecalData::DataRecordView, m_fDecalMaxHeight) == 12);
FNV_STATIC_ASSERT(offsetof(DecalData::DataRecordView, m_fProjectionDepth) == 16);
FNV_STATIC_ASSERT(offsetof(DecalData::DataRecordView, m_fShininess) == 20);
FNV_STATIC_ASSERT(offsetof(DecalData::DataRecordView, m_fParallaxScale) == 24);
FNV_STATIC_ASSERT(offsetof(DecalData::DataRecordView, m_ucParallaxPasses) == 28);
FNV_STATIC_ASSERT(offsetof(DecalData::DataRecordView, cFlags) == 29);
FNV_STATIC_ASSERT(offsetof(DecalData::DataRecordView, iColor) == 32);
#pragma pack(push, 4)
#include "../../include/DecalData.h"
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DecalData) == 36);
FNV_STATIC_ASSERT(offsetof(DecalData, Data) == 0);
struct DecalDataDeleter : public DecalData
{
    void* DeleteThis(int aiFlag);
};

// ModelLoader queue call (0x00443af0) on the global at 0x011c3b3c.
struct ModelLoader
{
    void QueueTextureFile(BSFileEntry* apEntry, int aePriority, QueuedFile* apQueuedFile);
};
extern ModelLoader* g_pModelLoader;

// Bethesda memset (0x00403d30).
void* FillBytes(void* apDst, int aiValue, unsigned int auSize);

struct TESDataHandlerForms
{
    void AddFormToDataHandler(TESForm*);
};
class TESDataHandler;
extern TESDataHandler* g_dataHandler;

void* operator new(unsigned int);
void operator delete(void*);
struct TESFileChunkData16
{
    bool GetChunkData(unsigned short*);
};
struct TESTextureLoader
{
    static void ReadTextureData(TESTexture*, TESFile*);
};
struct TaskQueueInterface
{
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
int strcat_s(char*, unsigned int, const char*);
bool CleanPath(const char*, char*, unsigned int);
class FileNameHash;
class FileNameHash
{
  public:
    static void CreateDirectoryAndFileHashes(const char*, FileNameHash&, FileNameHash&);
};
struct ArchiveManager
{
    static BSFileEntry* FindFileEntry(ARCHIVE_TYPE_INDEX, FileNameHash&, FileNameHash&, const char*);
};

void BGSTextureSet_ClearNullTextureSet();
BGSTextureSet* __cdecl BGSTextureSet_GetNullTextureSet();
void __cdecl _Deallocate(void*);
struct S591140
{
    void FUN_00591170();
    void* FUN_00591140(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
struct FullNameEx
{
    int _m0;
    int _m1;
    int _m2;
    void SetFullName(char const*);
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct FUN_0048e370_obj
{
    void TESTexture_Save(unsigned int);
};
void __cdecl TESForm_AddChunk_00485950(unsigned int, unsigned int);
extern unsigned int DAT_0118c574[6];
struct FUN_005e79a0_t : public TESForm
{
    bool TESForm_CompareAllComponents(TESForm*);
};
struct FUN_005932e0_shell
{
    bool Compare(void*);
};
struct FUN_005926f0_entry
{
    virtual void FUN_0() = 0;
    virtual void FUN_1() = 0;
    virtual void FUN_2() = 0;
    virtual bool Compare(void*) = 0;
};
struct DecalDataOwned : public DecalData
{
    ~DecalDataOwned();
};
struct DecalDataCopier
{
    void Copy(DecalData* apSrc);
};
int FUN_00406d30(char*, unsigned int, const char*);
namespace s593030 {

struct ValueList
{
    int unk00;
    int unk04;
    int unk08;

    void FUN_00489100(int iValue);
};

struct Owner
{
    int unk00;
    int unk04;
    ValueList m_kList0;
    ValueList m_kList1;
    ValueList m_kList5;
    ValueList m_kList2;
    ValueList m_kList3;
    ValueList m_kList4;

    void BGSTextureSet_SetTexturePath(unsigned int uiType, int iValue);
};

// @fnv 0x00593030
// src: COMMUNITY 0x00593030
void Owner::BGSTextureSet_SetTexturePath(unsigned int uiType, int iValue)
{
    switch (uiType)
    {
    case 0:
        m_kList0.FUN_00489100(iValue);
        break;
    case 1:
        m_kList1.FUN_00489100(iValue);
        break;
    case 2:
        m_kList2.FUN_00489100(iValue);
        break;
    case 3:
        m_kList3.FUN_00489100(iValue);
        break;
    case 4:
        m_kList4.FUN_00489100(iValue);
        break;
    case 5:
        m_kList5.FUN_00489100(iValue);
        break;
    }
}

}

// @fnv 0x005923c0
BGSTextureSet::~BGSTextureSet()
{
    ClearData();
}
