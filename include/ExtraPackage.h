#pragma once

#include "BSExtraData.h"

class TESPackage;

namespace extra_save
{
class SForm;
}

namespace loader
{
class PackageRef;
}

class ExtraPackage : public BSExtraData
{
public:
    struct RefList
    {
        void* head;
        void* next;
        void FUN_005ae3d0(loader::PackageRef* const&);
    };

    ExtraPackage();
    ExtraPackage(TESPackage* package, unsigned int packageArgument, unsigned int packageOptions,
                 unsigned char flag1, unsigned char flag2, unsigned char flag3);

    union
    {
        struct
        {
            union
            {
                extra_save::SForm* package;
                int unk0C;
            };
            union
            {
                int unk10;
                int iElementIndex;
            };
        };
        RefList list;
    };
    union
    {
        extra_save::SForm* form14;
        struct
        {
            unsigned char flags;
            unsigned char unk15;
            unsigned short unk16;
        };
    };
    char unk18;
    char unk19;
    unsigned short unk1A;
};
