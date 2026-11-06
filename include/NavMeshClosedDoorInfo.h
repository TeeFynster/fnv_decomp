#pragma once

class NavMeshClosedDoorInfo
{
public:
    unsigned int m_uiDoorFormID;
    unsigned short m_usDoorTriangleIndex;
    unsigned char layoutPadding6[2];

    NavMeshClosedDoorInfo();
};
