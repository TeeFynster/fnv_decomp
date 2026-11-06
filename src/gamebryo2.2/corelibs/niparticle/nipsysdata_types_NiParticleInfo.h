// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPARTICLEINFO_H
#define FNV_NIPARTICLEINFO_H

#include <stddef.h>
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiStream.h"
#pragma pack(push, 4)
class Point3ParameterData
{
  public:
    NiPoint3 m_kValue;               // +0x0, 12 bytes
    float m_fXValue;                 // +0xC, 4 bytes
    float m_fYValue;                 // +0x10, 4 bytes
    float m_fZValue;                 // +0x14, 4 bytes
    unsigned short m_usFirstValue;   // +0x18, 2 bytes
    unsigned short m_usSecondValue;  // +0x1A, 2 bytes
    // void __cdecl Point3ParameterData::*()
    // void __cdecl Point3ParameterData::*(NiStream&)
    // void __cdecl Point3ParameterData::*(NiStream&)
    // bool __cdecl Point3ParameterData::*(const Point3ParameterData&)
    Point3ParameterData();
    void LoadBinary(NiStream&);
    void Initialize();
    bool Equals(void*);
};
#pragma pack(pop)
typedef char particle_info_size_check[(sizeof(Point3ParameterData) == 28) ? 1 : -1];
typedef char particle_info_value_offset_check[(offsetof(Point3ParameterData, m_kValue) == 0) ? 1 : -1];
typedef char particle_info_x_offset_check[(offsetof(Point3ParameterData, m_fXValue) == 12) ? 1 : -1];
typedef char particle_info_y_offset_check[(offsetof(Point3ParameterData, m_fYValue) == 16) ? 1 : -1];
typedef char particle_info_z_offset_check[(offsetof(Point3ParameterData, m_fZValue) == 20) ? 1 : -1];
typedef char particle_info_first_offset_check[(offsetof(Point3ParameterData, m_usFirstValue) == 24) ? 1 : -1];
typedef char particle_info_second_offset_check[(offsetof(Point3ParameterData, m_usSecondValue) == 26) ? 1 : -1];
#endif
