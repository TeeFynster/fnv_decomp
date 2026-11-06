// Unit-local support declarations for fallout_shared/bgstextureset.cpp.
#ifndef FNV_BGSTEXTURESET_UNIT_H
#define FNV_BGSTEXTURESET_UNIT_H

#include "layout_support.h"
#include "../../include/ARCHIVE_TYPE_INDEX.h"
#include "BaseFormComponent.h"
#include "../../include/TESForm.h"
#include "../../include/TESTexture.h"

#include "../../include/BGSTextureSet.h"
#include "../../include/BSTextureSet.h"
#include "../../include/NiObject.h"
#include "../../include/NiPoint2.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"
#include "../../include/TESObject.h"

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
#endif
