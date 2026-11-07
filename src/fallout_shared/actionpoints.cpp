
// fallout_shared/actionpoints.cpp
// ActionPoints::GetActionPoints (0x0066dda0).
//
#include "../../include/SettingT_GameSettingCollection_.h"
#include "../../include/StartMenu.h"

extern SettingT_GameSettingCollection_ fActionPointsRestoreRate;

class ActionPoints
{
  public:
    static float GetActionPoints();
};

// @fnv 0x0066dda0
float ActionPoints::GetActionPoints()
{
    return fActionPointsRestoreRate.Float()->f;
}

// Returns true for action codes 0-8, 16, 17, 19, 20 and 21, and false for any other code.
// @fnv 0x0066dde0
// src: XBOX_PDB 0x0066dde0
bool ActionPoints_IsAttackAction(int aeAction)
{
    switch (aeAction)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 16:
    case 17:
    case 19:
    case 20:
    case 21:
        return true;
    default:
        return false;
    }
}

// @fnv 0x0066dba0
// src: COMMUNITY 0x0066dba0
int ActionPoints_GetAttackAction(int aeWeaponType)
{
    int result = 22;
    if (aeWeaponType >= 0 && aeWeaponType < 14)
    {
        switch (aeWeaponType)
        {
        case 0:
            result = 0;
            break;
        case 1:
            result = 1;
            break;
        case 2:
            result = 2;
            break;
        case 3:
        case 4:
            result = 3;
            break;
        case 5:
        case 6:
        case 7:
            result = 4;
            break;
        case 8:
            result = 5;
            break;
        case 9:
            result = 6;
            break;
        case 10:
            result = 7;
            break;
        case 11:
            result = 8;
            break;
        case 13:
            result = 19;
            break;
        }
    }
    return result;
}

extern StartMenu* DAT_0119bb50[];

// @fnv 0x0066ddc0
// src: COMMUNITY 0x0066ddc0
char const* ActionPoints_GetActionPointsString(int index)
{
    return reinterpret_cast<char const*>(DAT_0119bb50[index]->GetMenuTitle());
}
