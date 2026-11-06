#pragma once

#include "bhkSerializable.h"

class ArgB;
class SourceMesh;

class bhkShape : public bhkSerializable
{
public:
    bhkShape();

    virtual void FUN_00c84df0(void* object, ArgB* arg);
    virtual int ApplyToNext(int* data);
    virtual void* FUN_00577190();
    virtual bool FUN_00c84ec0(int arg);
    virtual void FUN_00ca6b60(NiNode* parent, int arg);
    virtual void vf54();
    virtual void BuildTriShape(unsigned int unused, SourceMesh* mesh, unsigned int arg, const char* name);

    void FUN_00c84c50();
    void* FUN_0056e740(unsigned int flags);
    int FUN_006205a0();

    int m_0c;
    int m_10;
};
