
#include "../../../include/AILinearTaskThread.h"
#include "../../../include/BSLinearTaskThread.h"
#include "../../../include/BSThread.h"
#include "../../../include/CountingSemaphore.h"
#include "../../../include/hkMemoryRouter.h"

// @fnv 0x008c7630
AILinearTaskThread::AILinearTaskThread(void(__cdecl* taskFunction)())
{
    m_pTaskFunction = taskFunction;
}
