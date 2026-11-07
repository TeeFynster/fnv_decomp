#pragma once

class Nav;
class NavMeshInfo;

class PathBuilderDetailedPathInfos
{
public:
    PathBuilderDetailedPathInfos();
    ~PathBuilderDetailedPathInfos();

    void Clear(bool abFree);
    Nav*& FUN_00877a30(unsigned);
    NavMeshInfo*& GetFirstForm();
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
