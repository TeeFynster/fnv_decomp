#pragma once

#include "NiGeometry.h"

namespace stand { class NiPoint3; }
class NiColorA;

class NiLines : public NiGeometry
{
  public:
    NiLines();
    NiLines(unsigned short count, stand::NiPoint3* vertices, NiColorA* colors,
            void* normals, void* textures, void* data, bool* flags);
    void CopyMemberData(NiLines* source, CloningProcess& process);
    bool FUN_00a80430(NiStream& stream);

};
