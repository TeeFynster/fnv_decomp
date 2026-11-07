// Initial-data packet records and save/load entry points.
#ifndef FNV_SRC_BGSSAVELOADINITIALDATA_H
#define FNV_SRC_BGSSAVELOADINITIALDATA_H

#include <stddef.h>
#define INITIAL_DATA_JOIN_IMPL(a, b) a##b
#define INITIAL_DATA_JOIN(a, b) INITIAL_DATA_JOIN_IMPL(a, b)
#define INITIAL_DATA_ASSERT(condition) typedef char INITIAL_DATA_JOIN(InitialDataAssert, __LINE__)[(condition) ? 1 : -1]
#include "../../../../include/ENUM_FORM_ID.h"

#ifndef FNV_INITIAL_DATA_TYPE_H
#define FNV_INITIAL_DATA_TYPE_H

enum INITIAL_DATA_TYPE
{
    INITIAL_DATA_TYPE_INITIAL_DATA_NONE = 0,
    INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_CHAR = 1,
    INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_SHORT = 2,
    INITIAL_DATA_TYPE_INITIAL_DATA_INTERIOR_CELL = 3,
    INITIAL_DATA_TYPE_INITIAL_DATA_REFERENCE_LOCATION = 4,
    INITIAL_DATA_TYPE_INITIAL_DATA_CREATED_REFERENCE = 5,
    INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE = 6,
    INITIAL_DATA_TYPE_INITIAL_DATA_TYPE_COUNT = 7
};
#endif

#ifndef FNV_BGSCHANGEFLAGS_H
#define FNV_BGSCHANGEFLAGS_H

#pragma pack(push, 4)
// This packet passes its change mask as a trivial four-byte value.
class InitialDataChangeMask
{
  public:
    bool ContainsAnyFlags(int);
    int iFlags;  // +0x0, 4 bytes
};
#pragma pack(pop)
INITIAL_DATA_ASSERT(sizeof(InitialDataChangeMask) == 4);
INITIAL_DATA_ASSERT(offsetof(InitialDataChangeMask, iFlags) == 0);
#endif

#ifndef FNV_REFERENCEINITIALDATA_H
#define FNV_REFERENCEINITIALDATA_H

#include "../../../../include/NiPoint3.h"
#pragma pack(push, 1)
class ReferencePlacementData
{
  public:
    ReferencePlacementData();
    unsigned int m_uiLocationFormID;      // +0x0, 4 bytes
    unsigned int m_uiBaseFormID;          // +0x4, 4 bytes
    unsigned int m_uiOriginalBaseFormID;  // +0x8, 4 bytes
    int m_iCellX;                         // +0xC, 4 bytes
    int m_iCellY;                         // +0x10, 4 bytes
    NiPoint3 Location;                    // +0x14, 12 bytes
    NiPoint3 Angle;                       // +0x20, 12 bytes
    unsigned char m_ucFlags;              // +0x2C, 1 bytes
    bool GetCellAndWorld(TESObjectCELL*& apCell, TESWorldSpace*& apWorld);
};
#pragma pack(pop)
// Packet records are byte packed on disk.
INITIAL_DATA_ASSERT(sizeof(ReferencePlacementData) == 45);
INITIAL_DATA_ASSERT(offsetof(ReferencePlacementData, m_uiLocationFormID) == 0);
INITIAL_DATA_ASSERT(offsetof(ReferencePlacementData, m_uiBaseFormID) == 4);
INITIAL_DATA_ASSERT(offsetof(ReferencePlacementData, m_uiOriginalBaseFormID) == 8);
INITIAL_DATA_ASSERT(offsetof(ReferencePlacementData, m_iCellX) == 12);
INITIAL_DATA_ASSERT(offsetof(ReferencePlacementData, m_iCellY) == 16);
INITIAL_DATA_ASSERT(offsetof(ReferencePlacementData, Location) == 20);
INITIAL_DATA_ASSERT(offsetof(ReferencePlacementData, Angle) == 32);
INITIAL_DATA_ASSERT(offsetof(ReferencePlacementData, m_ucFlags) == 44);
#endif

#undef INITIAL_DATA_ASSERT
#undef INITIAL_DATA_JOIN
#undef INITIAL_DATA_JOIN_IMPL

class BGSSaveLoadInitialData
{
  public:
    static INITIAL_DATA_TYPE LoadInitialDataForForm(BGSLoadFormBuffer*, TESForm*, InitialDataChangeMask);
    static INITIAL_DATA_TYPE DetermineInitialDataType(TESForm* apForm, InitialDataChangeMask eChangeFlags);
    static INITIAL_DATA_TYPE DetermineInitialDataType(unsigned int auiFormId, ENUM_FORM_ID m_eReferenceTypeInfo,
                                                      InitialDataChangeMask eChangeFlags);
};

bool GetCellAndWorldspaceForForm(TESForm* apForm, TESObjectCELL*& apCell, TESWorldSpace*& apWorld);
int TruncateFloatToInt(float afValue);

extern TESDataHandler* g_dataHandler;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TES* g_TES;
extern PlayerCharacter* g_thePlayer;
extern const char DAT_01015890[];
extern const char DAT_0107f86c[];
extern const char DAT_0107f894[];
extern const char DAT_0107f8d0[];
extern const char DAT_0107f938[];
void LogWarning(const char*, ...);
bool BGSSaveLoadInitialData_IsInitialDataCellType(INITIAL_DATA_TYPE);
bool BGSSaveLoadInitialData_IsInitialDataRefType(INITIAL_DATA_TYPE);
unsigned int LoadFormData(BGSLoadFormBuffer*, INITIAL_DATA_TYPE, void*);
struct CellDetachTimeData
{
    unsigned int a, b, c, m_uiDetachTime;
};

#endif
