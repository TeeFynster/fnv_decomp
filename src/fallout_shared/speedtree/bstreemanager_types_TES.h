// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TES_H
#define FNV_TES_H

#include "layout_support.h"
#include "TESObjectREFR.h"
#include "layout_support.h"
class LeveledActorEntry;
class GridCellArray;
class GridDistantArray;
class ImageSpaceModifierInstance;
class LoadedAreaBound;
class NavMeshInfoMap;
class NiDirectionalLight;
class NiFogProperty;
class NiSourceTexture;
class QueuedFile;
class Sky;
class TES;
class TES__ParticleObjectCache;
class TESRegion;
class TESWaterSystem;
#pragma pack(push, 4)
class TES
{
  public:
    void** m_ppVirtualMethodTable;                                          // +0x0, 4 bytes
    GridDistantArray* m_pGridDistantArray;                    // +0x4, 4 bytes
    GridCellArray* m_pGridCells;                              // +0x8, 4 bytes
    NiNode* m_pLandRootNode;                                  // +0xC, 4 bytes
    NiNode* m_pWaterRootNode;                                 // +0x10, 4 bytes
    NiNode* m_pDistantLandRootNode;                           // +0x14, 4 bytes
    NiNode* m_pObjectRootNode;                                // +0x18, 4 bytes
    NiDirectionalLight* m_pDirectionalLight;                  // +0x1C, 4 bytes
    NiFogProperty* m_pFogProperty;                            // +0x20, 4 bytes
    int iFirstValue;                                          // +0x24, 4 bytes
    int iSecondValue;                                         // +0x28, 4 bytes
    int m_iGridWidth;                                         // +0x2C, 4 bytes
    int m_iGridHeight;                                        // +0x30, 4 bytes
    TESObjectCELL* m_pReferenceCell;                          // +0x34, 4 bytes
    TESObjectCELL** m_ppCellBufferA;                          // +0x38, 4 bytes
    TESObjectCELL** m_ppCellBufferB;                          // +0x3C, 4 bytes
    unsigned int m_uiGridCellCountX;                          // +0x40, 4 bytes
    unsigned int m_uiGridCellCountY;                          // +0x44, 4 bytes
    int m_iCurrentGridX;                                      // +0x48, 4 bytes
    int m_iCurrentGridY;                                      // +0x4C, 4 bytes
    bool m_bFirstCellGridFlag;                                // +0x50, 1 bytes
    bool m_bSecondCellGridFlag;                               // +0x51, 1 bytes
    bool m_bThirdCellGridFlag;                                // +0x52, 1 bytes
    bool m_bFourthCellGridFlag;                               // +0x53, 1 bytes
    void(__cdecl* m_pfnCellCallback)(TESObjectCELL*, void*);  // +0x54, 4 bytes
    void* m_pCellCallbackContext;                             // +0x58, 4 bytes
    TESRegion* m_pCurrentRegion;                              // +0x5C, 4 bytes
    bool m_bHasCurrentRegion;                                 // +0x60, 1 bytes
    unsigned char layoutPadding61[3];
    TESWaterSystem* m_pCurrentClimate;                                                  // +0x64, 4 bytes
    Sky* pWeatherSky;                                                                     // +0x68, 4 bytes
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> > m_kImageSpaceModifierInstances;  // +0x6C, 8 bytes
    unsigned int m_uiNextImageSpaceModifierId;                                            // +0x74, 4 bytes
    unsigned int m_uiImageSpaceModifierCount;                                             // +0x78, 4 bytes
    bool m_bImageSpaceStateFlag;                                                          // +0x7C, 1 bytes
    bool m_bSkyStateFlag;                                                                 // +0x7D, 1 bytes
    unsigned char layoutPadding7E[2];
    float m_fFirstWorldspaceValue;                            // +0x80, 4 bytes
    float m_fSecondWorldspaceValue;                           // +0x84, 4 bytes
    TESWorldSpace* m_pContainingWorldspace;                   // +0x88, 4 bytes
    BSSimpleList<TESObjectCELL*> m_kWorldspaceCellList;       // +0x8C, 8 bytes
    BSSimpleList<TESObjectREFR*> m_kTemporaryReferences;      // +0x94, 8 bytes
    BSSimpleList<LeveledActorEntry*> m_kLeveledActorEntries;  // +0x9C, 8 bytes
    NiPointer<QueuedFile> m_spWorldspaceQueuedFile;           // +0xA4, 4 bytes
    NiPointer<NiSourceTexture> m_pSourceTexture;              // +0xA8, 4 bytes
    NiPointer<QueuedFile> m_spQueuedFile;                     // +0xAC, 4 bytes
    TES__ParticleObjectCache* m_pParticleObjectCache;         // +0xB0, 4 bytes
    bool m_bFirstTESStateFlag;                                // +0xB4, 1 bytes
    bool m_bSecondTESStateFlag;                               // +0xB5, 1 bytes
    unsigned char layoutPaddingB6[2];
    unsigned int m_uiNavMeshStateValue;              // +0xB8, 4 bytes
    NavMeshInfoMap* m_pNavMeshInfoMap;               // +0xBC, 4 bytes
    NiPointer<LoadedAreaBound> m_spLoadedAreaBound;  // +0xC0, 4 bytes
    bool LoadCanopyShadowTexture(const char*, unsigned int);
    // TES
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // NiNode* __cdecl TES::*()
    // NiNode* __cdecl TES::*()
    // NiNode* __cdecl TES::*()
    // NiNode* __cdecl TES::*()
    // GridCell* __cdecl TES::*(int, int)
    // NiDirectionalLight* __cdecl TES::*()
    // NiFogProperty* __cdecl TES::*()
    // TESObjectCELL* __cdecl TES::*()
    // GridCellArray* __cdecl TES::*()
    // void __cdecl TES::*(NiAVObject*, float)
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // bool __cdecl TES::*(int, int, TESWorldSpace*, unsigned int)
    // bool __cdecl TES::*(TESObjectCELL*)
    // void __cdecl TES::*(const NiPoint3*, bool)
    // int __cdecl TES::*(const NiPoint3*, bool)
    // void __cdecl TES::*(unsigned int)
    // void __cdecl TES::*(bool)
    // void __cdecl TES::*(float)
    // void __cdecl TES::*()
    // void __cdecl TES::*(bool)
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*(bool, bool)
    // bool __cdecl TES::*()
    // bool __cdecl TES::*()
    // void __cdecl TES::*(TESWorldSpace*)
    // bool __cdecl TES::*(const NiPoint3&)
    // bool __cdecl TES::*(TESObjectCELL*, bool)
    // void __cdecl TES::*(tagRECT&, float)
    // TESObjectCELL* __cdecl TES::*(const NiPoint3&, const NiPoint3&, NiPoint3&, float)
    // void __cdecl TES::*(NiNode*)
    // void __cdecl TES::*(NiNode*)
    // TESObjectCELL* __cdecl TES::*()
    // void __cdecl TES::*(TESObjectCELL*)
    // void __cdecl TES::*()
    // TESWorldSpace* __cdecl TES::*()
    // void __cdecl TES::*(TESWorldSpace*)
    // void __cdecl TES::*(tagPOINT&)
    // void __cdecl TES::*(const tagPOINT&)
    // void __cdecl TES::*(TESObjectCELL*, const NiPoint3*)
    // void __cdecl TES::*(NiPoint3*)
    // GridCell* __cdecl TES::*()
    // TESObjectCELL* __cdecl TES::*(int, int)
    // GridCell* __cdecl TES::*(TESObjectCELL*)
    // IO_TASK_PRIORITY __cdecl TES::*(TESObjectCELL*, NiPoint3*)
    // TESObjectCELL* __cdecl TES::*(NiPoint3)
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*(TESObjectCELL*)
    // void __cdecl TES::*(void __cdecl (TESObjectCELL*, void*)*)
    // void __cdecl TES::*(void*)
    // void __cdecl TES::*(TESRegion*)
    // void __cdecl TES::*(int)
    // void __cdecl TES::*()
    // bool __cdecl TES::*()
    // bool __cdecl TES::*()
    // bool __cdecl TES::*()
    // void __cdecl TES::*(bool)
    // void __cdecl TES::*(bool)
    // void __cdecl TES::*(unsigned int)
    // void __cdecl TES::*(TESObjectCELL*, unsigned int, unsigned int)
    // void __cdecl TES::*(NiNode*)
    // int __cdecl TES::*(NiNode*, bool)
    // int __cdecl TES::*(NiNode*)
    // void __cdecl TES::*(const char*, NiPointer<NiSourceTexture>&, bool, bool)
    // bool __cdecl TES::*(const char*, unsigned int)
    // void __cdecl TES::*(NiTexture*, const char*, _D3DXIMAGE_FILEFORMAT)
    // void __cdecl TES::*()
    // BSSimpleList<TESObjectCELL *>* __cdecl TES::*()
    // BSSimpleList<TESObjectREFR *>* __cdecl TES::*()
    // void __cdecl TES::*()
    // BSSimpleList<LeveledActorEntry *>* __cdecl TES::*()
    // void __cdecl TES::*()
    // short __cdecl TES::*(TESActorBase*)
    // void __cdecl TES::*(TESActorBase*, short)
    // void __cdecl TES::*(bool)
    // bool __cdecl TES::*()
    // void __cdecl TES::*(bool, bool)
    // void __cdecl TES::*(NiNode*)
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*(const char*)
    // void __cdecl TES::*(bool)
    // bool __cdecl TES::*()
    // void __cdecl TES::*(bool)
    // void __cdecl TES::*(int, bool, bool)
    // bool __cdecl TES::*(NiPick*, const NiPoint3&, const NiPoint3&)
    // bool __cdecl TES::*(NiPick*, const NiPoint3&, const NiPoint3&, float)
    // bool __cdecl TES::*(NiPick*, const NiPoint3&, const NiPoint3&, float, char)
    // bool __cdecl TES::*(const NiPoint3&, float&)
    // bool __cdecl TES::*(const NiPoint3&, NiPoint3&, NiPoint3&)
    // NiGeometry* __cdecl TES::*(const NiPoint3&)
    // TESLandTexture* __cdecl TES::*(const NiPoint3&)
    // MATERIAL_TYPE __cdecl TES::*(const NiPoint3&)
    // float __cdecl TES::*(const NiPoint3&)
    // float __cdecl TES::*(const NiPoint3&)
    // bool __cdecl TES::*(const NiPoint3&, const NiPoint3&, NiPoint3&, float)
    // bool __cdecl TES::*(TESObjectREFR*)
    // void __cdecl TES::*(TESObjectREFR*)
    // void __cdecl TES::*(TESObjectREFR*, TESObjectCELL*, QueuedReference*, bool)
    // void __cdecl TES::*(TESObjectREFR*)
    // void __cdecl TES::*()
    // float __cdecl TES::*(const NiPoint3&, TESObjectCELL*)
    // TESWaterSystem* __cdecl TES::*()
    // Sky* __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*(NiPoint3)
    // void __cdecl TES::*(MODEL_COUNT_TYPE)
    // bool __cdecl TES::*(bool, TESForm*, bool)
    // void __cdecl TES::*(const char*)
    // GridDistantArray* __cdecl TES::*()
    // void __cdecl TES::*()
    // bool __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*(TESObjectCELL*)
    // void __cdecl TES::*(TESObjectCELL*, bool)
    // void __cdecl TES::*(TESObjectCELL*)
    // void __cdecl TES::*()
    // GridLand* __cdecl TES::*(TESObjectLAND*)
    // void __cdecl TES::*()
    // bool __cdecl TES::*(NiNode*, bool)
    // Pick
    // bool __cdecl TES::*()
    // void __cdecl TES::*(bool)
    // void __cdecl TES::*()
    // unsigned short __cdecl TES::*()
    // SaveGame
    // LoadGame
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*(BGSLoadGameBuffer*)
    // void __cdecl TES::*(BGSLoadGameBuffer*)
    // int __cdecl TES::*()
    // int __cdecl TES::*()
    // void __cdecl TES::*(int)
    // void __cdecl TES::*(int)
    // unsigned int __cdecl TES::*()
    // TESObjectCELL* __cdecl TES::*(unsigned int)
    // unsigned int __cdecl TES::*()
    // TESObjectCELL* __cdecl TES::*(unsigned int)
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*(NiAVObject*)
    // unsigned int __cdecl TES::*(NiAVObject*, NiPointer<NiAVObject>&)
    // void __cdecl TES::*()
    // bool __cdecl TES::*()
    // void __cdecl TES::*(bool)
    // bool __cdecl TES::*()
    // NavMeshInfoMap* __cdecl TES::*()
    // void __cdecl TES::*(NavMeshInfoMap*)
    // BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*(NiCamera*)
    // void __cdecl TES::*(bool, bool)
    // void __cdecl TES::*(NiCamera*)
    // void __cdecl TES::*(NiNode*, bool)
    // unsigned int __cdecl TES::*(NiNode*, bool)
    // ENUM_LOD_MULT __cdecl TES::*(TESObject*)
    // void __cdecl TES::*(float)
    // void __cdecl TES::*(float)
    // void __cdecl TES::*(float)
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // unsigned int __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*(bool, NiPoint3*)
    // void __cdecl TES::*(const NiPoint3*, bool)
    // bool __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // bool __cdecl TES::*(TESObjectCELL*)
    // bool __cdecl TES::*(TESObjectCELL*)
    // void __cdecl TES::*(TESObjectCELL*)
    // void __cdecl TES::*(TESObjectCELL*)
    // unsigned int __cdecl TES::*(bool)
    // bool __cdecl TES::*(TESObjectCELL*)
    // void __cdecl TES::*(TESObjectCELL*)
    // unsigned int __cdecl TES::*(bool, TESWorldSpace*)
    // void __cdecl TES::*()
    // void __cdecl TES::*()
    // void __cdecl TES::*(int, int, bool)
    // void __cdecl TES::*(int, int, bool)
    // TES& __cdecl TES::*(const TES&)
    // void* __cdecl TES::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TES) == 196);
FNV_STATIC_ASSERT(offsetof(TES, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(TES, m_pGridDistantArray) == 4);
FNV_STATIC_ASSERT(offsetof(TES, m_pGridCells) == 8);
FNV_STATIC_ASSERT(offsetof(TES, m_pLandRootNode) == 12);
FNV_STATIC_ASSERT(offsetof(TES, m_pWaterRootNode) == 16);
FNV_STATIC_ASSERT(offsetof(TES, m_pDistantLandRootNode) == 20);
FNV_STATIC_ASSERT(offsetof(TES, m_pObjectRootNode) == 24);
FNV_STATIC_ASSERT(offsetof(TES, m_pDirectionalLight) == 28);
FNV_STATIC_ASSERT(offsetof(TES, m_pFogProperty) == 32);
FNV_STATIC_ASSERT(offsetof(TES, iFirstValue) == 36);
FNV_STATIC_ASSERT(offsetof(TES, iSecondValue) == 40);
FNV_STATIC_ASSERT(offsetof(TES, m_iGridWidth) == 44);
FNV_STATIC_ASSERT(offsetof(TES, m_iGridHeight) == 48);
FNV_STATIC_ASSERT(offsetof(TES, m_pReferenceCell) == 52);
FNV_STATIC_ASSERT(offsetof(TES, m_ppCellBufferA) == 56);
FNV_STATIC_ASSERT(offsetof(TES, m_ppCellBufferB) == 60);
FNV_STATIC_ASSERT(offsetof(TES, m_uiGridCellCountX) == 64);
FNV_STATIC_ASSERT(offsetof(TES, m_uiGridCellCountY) == 68);
FNV_STATIC_ASSERT(offsetof(TES, m_iCurrentGridX) == 72);
FNV_STATIC_ASSERT(offsetof(TES, m_iCurrentGridY) == 76);
FNV_STATIC_ASSERT(offsetof(TES, m_bFirstCellGridFlag) == 80);
FNV_STATIC_ASSERT(offsetof(TES, m_bSecondCellGridFlag) == 81);
FNV_STATIC_ASSERT(offsetof(TES, m_bThirdCellGridFlag) == 82);
FNV_STATIC_ASSERT(offsetof(TES, m_bFourthCellGridFlag) == 83);
FNV_STATIC_ASSERT(offsetof(TES, m_pfnCellCallback) == 84);
FNV_STATIC_ASSERT(offsetof(TES, m_pCellCallbackContext) == 88);
FNV_STATIC_ASSERT(offsetof(TES, m_pCurrentRegion) == 92);
FNV_STATIC_ASSERT(offsetof(TES, m_bHasCurrentRegion) == 96);
FNV_STATIC_ASSERT(offsetof(TES, m_pCurrentClimate) == 100);
FNV_STATIC_ASSERT(offsetof(TES, pWeatherSky) == 104);
FNV_STATIC_ASSERT(offsetof(TES, m_kImageSpaceModifierInstances) == 108);
FNV_STATIC_ASSERT(offsetof(TES, m_uiNextImageSpaceModifierId) == 116);
FNV_STATIC_ASSERT(offsetof(TES, m_uiImageSpaceModifierCount) == 120);
FNV_STATIC_ASSERT(offsetof(TES, m_bImageSpaceStateFlag) == 124);
FNV_STATIC_ASSERT(offsetof(TES, m_bSkyStateFlag) == 125);
FNV_STATIC_ASSERT(offsetof(TES, m_fFirstWorldspaceValue) == 128);
FNV_STATIC_ASSERT(offsetof(TES, m_fSecondWorldspaceValue) == 132);
FNV_STATIC_ASSERT(offsetof(TES, m_pContainingWorldspace) == 136);
FNV_STATIC_ASSERT(offsetof(TES, m_kWorldspaceCellList) == 140);
FNV_STATIC_ASSERT(offsetof(TES, m_kTemporaryReferences) == 148);
FNV_STATIC_ASSERT(offsetof(TES, m_kLeveledActorEntries) == 156);
FNV_STATIC_ASSERT(offsetof(TES, m_spWorldspaceQueuedFile) == 164);
FNV_STATIC_ASSERT(offsetof(TES, m_pSourceTexture) == 168);
FNV_STATIC_ASSERT(offsetof(TES, m_spQueuedFile) == 172);
FNV_STATIC_ASSERT(offsetof(TES, m_pParticleObjectCache) == 176);
FNV_STATIC_ASSERT(offsetof(TES, m_bFirstTESStateFlag) == 180);
FNV_STATIC_ASSERT(offsetof(TES, m_bSecondTESStateFlag) == 181);
FNV_STATIC_ASSERT(offsetof(TES, m_uiNavMeshStateValue) == 184);
FNV_STATIC_ASSERT(offsetof(TES, m_pNavMeshInfoMap) == 188);
FNV_STATIC_ASSERT(offsetof(TES, m_spLoadedAreaBound) == 192);
#endif
