#pragma once

struct __declspec(align(16)) Vec289
{
    float x, y, z, w;
};

struct RootContact289
{
    Vec289 position, normal;
    void* rootA;
    unsigned shapeKeyA;
    unsigned pathA[8];
    void* rootB;
    unsigned shapeKeyB;
    unsigned pathB[8];
};

class ContactArray289
{
public:
    RootContact289* data;
    int count;
    unsigned capacity;
    RootContact289 local[8];

    __declspec(nothrow) ContactArray289();
    __declspec(nothrow) ~ContactArray289();
};
