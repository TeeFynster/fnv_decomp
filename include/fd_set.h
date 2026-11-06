#pragma once

class fd_set
{
public:
    unsigned int fd_count;
    unsigned int fd_array[64];
};
