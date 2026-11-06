#pragma once

class ActivateString334
{
public:
    char* value;
    unsigned short length;
    unsigned short capacity;

    unsigned int GetLength();
    operator const char*() const;
};
