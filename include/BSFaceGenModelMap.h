#pragma once

#include "NiTMapItem.h"
class Sol;
class SolPtr;

class BSFaceGenModelMap
{
public:
    virtual void vf00();

    char pad[0x20];

    BSFaceGenModelMap();
    bool GetModel(void* key, SolPtr* result);
    void SetArrayValue(int index, char* value);
    void SetModel(void* key, Sol* model);
    bool HasModels();
    void PurgeUnusedModels(bool);
    void FreeStringMapObject(NiTMapItem<const char*, void*>* stringMap);
    bool HasFaceGenData(const char*);
};
