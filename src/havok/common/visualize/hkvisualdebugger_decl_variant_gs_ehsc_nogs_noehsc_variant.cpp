#include "../../../../include/hkArray.h"
#include "../../../../include/hkError.h"
#include "../../../../include/hkOstream.h"
#include "../../../../include/hkSocket.h"
#include "../../../../include/hkVisualDebugger.h"

// src/havok/common/visualize/hkvisualdebugger_decl_variant_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/visualize/hkvisualdebugger_decl_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/visualize/hkvisualdebugger.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkvisualdebugger.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Unused sibling-function skeletons (including the key/item entry pair) were removed from this variant.
#include <math.h>
typedef unsigned __int64 TickCount;
TickCount __cdecl hkStopwatch_getTickCounter();
TickCount __cdecl hkStopwatch_getTicksPerSecond();
double __cdecl DivideInt64ToFloat(TickCount, TickCount);
extern float DAT_0104da4c;
extern const char DAT_010caf8c[];
extern const char DAT_010caf48[];
extern const char DAT_010cae1c[];
extern hkError* DAT_01268360;
struct ClientProcess
{
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual bool alive();
    virtual void unknown14();
    virtual void step(float);
};
struct ClientHandler
{
    unsigned int unk00, unk04, unk08;
    ClientProcess process;
};
// @fnv 0x00cd0ec0
void hkVisualDebugger::step(float timeStep)
{
    float stepTime = 16.0f;
    if (m_amTimingFrame)
    {
        TickCount elapsed = m_frameTimer.m_ticks_total;
        if (m_frameTimer.m_running_flag)
            elapsed += hkStopwatch_getTickCounter() - m_frameTimer.m_ticks_at_start;
        stepTime = (float)(DivideInt64ToFloat(elapsed, hkStopwatch_getTicksPerSecond()) * 1000.0);
        m_frameTimer.m_running_flag = false;
        TickCount now = hkStopwatch_getTickCounter();
        m_frameTimer.m_ticks_total += now - m_frameTimer.m_ticks_at_start;
        m_frameTimer.m_split_total += now - m_frameTimer.m_ticks_at_split;
        ++m_frameTimer.m_num_timings;
    }
    m_amTimingFrame = true;
    float magnitude = (float)fabs(timeStep);
    if (magnitude > 1.1920928955078125e-7f)
        stepTime = timeStep;
    pollForNewClients();
    for (int index = m_clients.m_size - 1; index >= 0; --index)
    {
        hkVisualDebuggerClient* client = &m_clients.m_data[index];
        if (reinterpret_cast<ClientHandler*>(client->m_processHandler)->process.alive())
        {
            reinterpret_cast<ClientHandler*>(client->m_processHandler)->process.step(stepTime);
            writeStep(index, stepTime);
        }
        ClientHandler* handler = reinterpret_cast<ClientHandler*>(client->m_processHandler);
        if (!handler->process.alive())
        {
            DAT_01268360->beginSection(0x76e3a642, DAT_010caf8c);
            {
                char buffer[512];
                hkOstream stream(static_cast<void*>(buffer), 512);
                stream << DAT_010caf48;
                DAT_01268360->message(0, -1, buffer, DAT_010cae1c, 0x120);
            }
            DAT_01268360->endSection();
            deleteClient(index);
        }
    }
    if (m_amTimingFrame)
    {
        m_frameTimer.m_ticks_at_start = 0;
        m_frameTimer.m_ticks_total = 0;
        m_frameTimer.m_ticks_at_split = 0;
        m_frameTimer.m_split_total = 0;
        m_frameTimer.m_num_timings = 0;
        m_frameTimer.m_running_flag = true;
        TickCount now = hkStopwatch_getTickCounter();
        m_frameTimer.m_ticks_at_start = now;
        m_frameTimer.m_ticks_at_split = m_frameTimer.m_ticks_at_start;
    }
}
