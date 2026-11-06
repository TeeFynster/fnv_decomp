#pragma once

class ConstraintData;

class hkSerializableCinfo
{
public:
    ConstraintData* data;
    int references;
    int unkc;
    int unk10;

    __forceinline hkSerializableCinfo()
        : data(0), references(1), unkc(0), unk10(0)
    {}
};
