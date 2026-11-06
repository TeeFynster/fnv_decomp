
// bssystemutilities/console/bssystemutility_console.cpp: BSSystemUtility (1 function)
#include "../../../include/BSSystemUtility.h"

int BSSystemUtility::s_iUpdateEnabled;
BSSystemUtility* BSSystemUtility::ms_pSystemUtility;

// @fnv 0x0078d020
void BSSystemUtility::GetRandomGenerator()
{
    if (s_iUpdateEnabled != 0 && ms_pSystemUtility != 0)
        ms_pSystemUtility->Update();
}
