#pragma once

// A union in Bethesda's code (every unit's declaration and the PAT mangling of its users).
union SETTING_VALUE
{
    const char* str;
    int i;
    unsigned int u;
    float f;
    bool b;
    char c;
    unsigned char h;
};
