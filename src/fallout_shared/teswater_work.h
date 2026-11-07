// fallout_shared/teswater_work.h: the shared classes and globals teswater.cpp's world/water functions use, plus
// WaterSurface (TESWaterSystem's water zone; no shared header yet).
#ifndef FNV_TESWATER_WORK_H
#define FNV_TESWATER_WORK_H

#include "../../include/NiPoint2.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPlane.h"
#include "../../include/NiNode.h"
#include "../../include/NiTPointerList.h"
#include "../../include/BSSimpleList.h"
#include "../../include/LoadedAreaBound.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/Setting.h"
#include "../../include/TESDataHandler.h"
#include "../../include/bhkWorld.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/BGSTerrainManager.h"
#include "../../include/TESWorldSpace.h"
#include "../../include/GridCellArray.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/TES.h"
#include "../../include/TESQueuedCellManager.h"
#include "../../include/Menu.h"
#include "../../include/NiMatrix3.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESWaterSystem.h"

class TESWaterForm;

// TESWaterSystem's water zone (48 bytes; layout table WaterSurface.json): the owning water form,
// the water and secondary planes and the placed water references sharing them.
class WaterSurface
{
  public:
    TESWaterForm* m_pOwningWater;
    NiPlane m_kWaterPlane;
    NiPlane m_kSecondaryPlane;
    NiTPointerList<TESObjectREFR*> m_kWaterReferences;
};

int TruncateFloatToInt(float);
int FUN_00ec7d40(int);
void BSTaskThread_SetUpdateSleepEnabled(bool);
float BSShaderManager_GetTimer(bool);
extern bool DAT_011c3c0c, DAT_011f94aa;
extern float DAT_011f94ac;
extern NiPoint2 DAT_011f962c, DAT_011f9634, DAT_011f4980;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TESDataHandler* g_dataHandler;
extern PlayerCharacter* g_thePlayer;
// two SettingT<INISettingCollection> bools and a game-setting int (the grid size: Int() 0x0043d4d0)
extern Setting DAT_011c9670, DAT_011c3d40;
extern Setting DAT_011c63cc;
extern TESQueuedCellManager* DAT_011c9618;

bool AreVectorsEqual(const NiPoint3&, const NiPoint3&, float);
bool IsApproximatelyEqual(float, float, float);
#endif
