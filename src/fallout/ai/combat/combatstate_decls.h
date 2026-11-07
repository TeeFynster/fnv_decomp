#include "../../../../include/InventoryChanges.h"
#include "../../../../include/CombatState.h"
// fallout/ai/combat/combatstate_decls.h: declares CombatLocations, CombatLOS and combat globals
class CombatLocations
{
  public:
    virtual void Clear();
};
class CombatLOS
{
  public:
    bool BaseProcess_HasCachedValues();
    void BaseProcess_GetCachedRadius(CombatLocations*);
};
class GlobalObject_0044f440
{
  public:
    float FUN_00450410();
};
float RandomFloat(float, float);
bool RandomBoolean(float);
extern GlobalObject_0044f440 DAT_011d57d0;
extern GlobalObject_0044f440 DAT_011d5944;
extern GlobalObject_0044f440 DAT_011d5750;
extern GlobalObject_0044f440 DAT_011d5968;
extern GlobalObject_0044f440 DAT_011d5874;
extern GlobalObject_0044f440 DAT_011d58e8;
extern GlobalObject_0044f440 DAT_011d5988;
extern GlobalObject_0044f440 DAT_011d5794;
extern GlobalObject_0044f440 DAT_011d57b8;
extern GlobalObject_0044f440 DAT_011d581c;
extern GlobalObject_0044f440 DAT_011d5894;
extern GlobalObject_0044f440 DAT_011d5930;
extern GlobalObject_0044f440 DAT_011d58d8;
extern GlobalObject_0044f440 DAT_011d5868;
extern GlobalObject_0044f440 DAT_011d5834;
extern GlobalObject_0044f440 DAT_011d58c4;
extern GlobalObject_0044f440 DAT_011d5908;
extern GlobalObject_0044f440 DAT_011d585c;
extern const float DAT_01017870;
extern const float DAT_01017718;
extern const float DAT_010162c0;
extern const float DAT_01016088;
extern const float DAT_01016248;
extern const float DAT_0101e570;
