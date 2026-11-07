// fallout_shared/pathfinding/pathingrequestlos.cpp: PathingRequestLOS (10 functions)

#include <math.h>

#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/BGSSaveGameBuffer.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/PathingRequestLOS.h"
#include "../../../include/BSSimpleArray.h"

extern void* g_PathingRequestLOS_vtable;

// @fnv 0x004b1480
float WrapAngle(float angle)
{
    if (angle < 0.0)
        angle = fmod((float)(angle + 6.2831854820251465), 6.2831854820251465f);
    else if (angle >= 6.2831854820251465)
        angle = fmod(angle, 6.2831854820251465f);
    return angle;
}

struct C006e39d0
{
    void FUN_006e39d0();
};
void __cdecl _delete(void*, unsigned int);
struct S006e3a50
{
    void* FUN_006e3a50(unsigned int);
};
// Calls FUN_006e39d0 on this, deletes this with size 24 when flags has bit 0 set, and returns this.
// @fnv 0x006e3a50
void* S006e3a50::FUN_006e3a50(unsigned int flags)
{
    reinterpret_cast<C006e39d0*>(this)->FUN_006e39d0();
    if (flags & 1)
        _delete(this, 24);
    return this;
}

// @fnv 0x006e5890
void* PathingRequestLOS::DestroyAndFree(unsigned int flags)
{
    this->PathingRequestLOS::~PathingRequestLOS();
    if (flags & 1)
        PathingRequestLOS::operator delete(this, 0xd8);
    return this;
}

// @fnv 0x006e5c00
void PathingRequestLOS::LoadGame(BGSLoadFormBuffer* buffer)
{
    PathingRequest::LoadGame(buffer);
    unsigned int count = buffer->ReadElementCount();
    m_b4.SetSize(count, 1);
    unsigned int i = 0;
    for (; i < count; ++i)
    {
        ParentSpaceNode& node = m_b4.GetAt((int)i);
        buffer->ReadTypedData(&node, 12);
    }
    buffer->ReadTypedData(static_cast<void*>(&m_c4), 4u);
    buffer->ReadTypedData(static_cast<void*>(&m_c8), 12u);
    buffer->ReadTypedData(static_cast<void*>(&m_d4), 4u);
}

// @fnv 0x006e5a40
// src: COMMUNITY 0x006e5a40
void PathingRequestLOS::SetSearchCenter(NiPoint3 v, float w)
{
    m_c8 = v;
    m_d4 = w;
}

// @fnv 0x006e5a80
void PathingRequestLOS::CopyTo(PathingRequest* apDest)
{
    PathingRequest* pdest = apDest;
    PathingRequest::CopyTo(pdest);
    static_cast<PathingRequestLOS*>(pdest)->m_b0 = m_b0;
    m_b4.CopyTo(&static_cast<PathingRequestLOS*>(pdest)->m_b4);
    static_cast<PathingRequestLOS*>(pdest)->m_c4 = m_c4;
    static_cast<PathingRequestLOS*>(pdest)->SetSearchCenter(m_c8, m_d4);
}

// @fnv 0x006e5b20
void PathingRequestLOS::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    PathingRequest::PathingRequest_SaveGame(apSaveGameBuffer);

    unsigned int isaveGameCount =
        (reinterpret_cast<unsigned int>(this) + 0xB4) != 0
            ? m_b4.GetSize()
            : 0;

    reinterpret_cast<BGSSaveGameBuffer*>(apSaveGameBuffer)->SaveVariableSizedValue(isaveGameCount);

    {
        unsigned int i;
        for (i = 0; i < isaveGameCount; ++i)
        {
            ParentSpaceNode& node = m_b4.GetAt((int)i);
            apSaveGameBuffer->SaveData(&node, 0xC, 0);
        }
    }

    apSaveGameBuffer->SaveData(&m_c4, 4, 0);
    apSaveGameBuffer->SaveData(&m_c8, 0xC, 0);
    apSaveGameBuffer->SaveData(&m_d4, 4, 0);
}

extern float g_fFUN006e57e0_c4;

// @fnv 0x006e57e0
PathingRequestLOS::PathingRequestLOS()
    : PathingRequest(),
      m_b0(((*reinterpret_cast<void**>(this) = &g_PathingRequestLOS_vtable), 0)),
      m_b4(), m_c8()
{
    m_c4 = g_fFUN006e57e0_c4;
    m_d4 = 0.0f;
}

// @fnv 0x006e58d0
PathingRequestLOS::~PathingRequestLOS()
{}

// @fnv 0x006e5940
PathingRequestLOS::PathingRequestLOS(const PathingRequestLOS& kOther)
    : PathingRequest(const_cast<PathingRequestLOS*>(&kOther)),
      m_b0(((*reinterpret_cast<void**>(this) = &g_PathingRequestLOS_vtable), kOther.m_b0)),
      m_c4(kOther.m_c4)
{
    kOther.m_b4.CopyTo(&m_b4);
    float kPos[3];
    Place(kOther.GetPosition(*reinterpret_cast<NiPoint3*>(kPos)), kOther.GetRadius());
}
