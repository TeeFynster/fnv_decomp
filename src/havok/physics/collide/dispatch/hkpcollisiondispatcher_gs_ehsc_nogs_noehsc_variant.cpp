#include "../../../../../include/BSAudio.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkError.h"
#include "../../../../../include/hkOstream.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkpCollisionDispatcher.h"


// src/havok/physics/collide/dispatch/hkpcollisiondispatcher_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/dispatch/hkpcollisiondispatcher.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/dispatch/hkpcollisiondispatcher.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/dispatch/hkpcollisiondispatcher.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern int DAT_01268360;
const char* GetHavokShapeTypeName(int type);
int Vsnprintf(char* buf, int size, const char* fmt, ...);

struct InlineStorageString
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char m_buffer[128];
    InlineStorageString(const char*, const char* = 0, const char* = 0, const char* = 0, const char* = 0, const char* = 0);
    ~InlineStorageString();
};
// @fnv 0x00cfc1d0
// src: HAVOK_LIB 0x00cfc1d0
void hkpCollisionDispatcher::debugPrintTable()
{
    ((hkError*)DAT_01268360)->beginSection(0x5e4345e4, "hkpCollisionDispatcher::debugPrintTable");
    if (!m_tableDiscrete || !m_tableContinuous)
    {
        return;
    }
    char buf[512];
    for (int i = 0; i < 32; ++i)
    {
        InlineStorageString str("\nEntries for (continuous)", GetHavokShapeTypeName(i));
        {
            hkOstream stream(static_cast<void*>(buf), 512);
            stream.InvokeFromRequest(str);
            ((hkError*)DAT_01268360)->message(0, -1, buf, ".\\Dispatch\\hkpCollisionDispatcher.cpp", 547);
        }
        for (int j = 1; j < 32; ++j)
        {
            AgentTypePairPriority& entry = reinterpret_cast<AgentTypePairPriority*>(m_tableContinuous)[i * 32 + j];
            if (entry.m_priority < 100)
            {
                char lineBuf[255];
                const char* other = GetHavokShapeTypeName(j);
                const char* a = GetHavokShapeTypeName(entry.m_iAgentTypeA);
                const char* b = GetHavokShapeTypeName(entry.m_iAgentTypeB);
                Vsnprintf(lineBuf, 255, "vs %30s <%i:%s-%s>", other, entry.m_priority, a, b);
                hkOstream stream(static_cast<void*>(buf), 512);
                stream << lineBuf;
                ((hkError*)DAT_01268360)->message(0, -1, buf, ".\\Dispatch\\hkpCollisionDispatcher.cpp", 562);
            }
        }
    }
    for (int i = 0; i < 32; ++i)
    {
        InlineStorageString str("\nEntries for (discrete)", GetHavokShapeTypeName(i));
        {
            hkOstream stream(static_cast<void*>(buf), 512);
            stream.InvokeFromRequest(str);
            ((hkError*)DAT_01268360)->message(0, -1, buf, ".\\Dispatch\\hkpCollisionDispatcher.cpp", 570);
        }
        for (int j = 1; j < 32; ++j)
        {
            AgentTypePairPriority& entry = reinterpret_cast<AgentTypePairPriority*>(m_tableDiscrete)[i * 32 + j];
            if (entry.m_priority < 100)
            {
                char lineBuf[255];
                const char* other = GetHavokShapeTypeName(j);
                const char* a = GetHavokShapeTypeName(entry.m_iAgentTypeA);
                const char* b = GetHavokShapeTypeName(entry.m_iAgentTypeB);
                Vsnprintf(lineBuf, 255, "vs %30s <%i:%s-%s>", other, entry.m_priority, a, b);
                hkOstream stream(static_cast<void*>(buf), 512);
                stream << lineBuf;
                ((hkError*)DAT_01268360)->message(0, -1, buf, ".\\Dispatch\\hkpCollisionDispatcher.cpp", 585);
            }
        }
    }
    ((hkError*)DAT_01268360)->endSection();
}

InlineStorageString::~InlineStorageString()
{
    hkMemoryAllocator& allocator = hkMemoryRouter::getInstance().temp();
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        allocator.bufFree(m_data, m_iCapacityState & 0x3fffffff);
}
