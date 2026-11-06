#pragma once

class sockaddr
{
public:
    unsigned short sa_family;
    char sa_data[14];
};
