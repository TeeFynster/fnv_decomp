#pragma once

#include "bhkSerializable.h"

class ArgB;
class SourceMesh;

class bhkShape : public bhkSerializable
{
public:
    bhkShape();

    virtual void bhkShape_CopyMembers(void* object, ArgB* arg);
    virtual int ApplyToNext(int* data);
    virtual void* bhkBvTreeShape_GetShapeCollection();
    virtual bool bhkShape_CanShare(int arg);
    virtual void BuildDisplayGeometry_00ca6b60(NiNode* parent, int arg);
    virtual void vf54();
    virtual void BuildTriShape(unsigned int unused, SourceMesh* mesh, unsigned int arg, const char* name);

    void FUN_00c84c50();
    void* FUN_0056e740(unsigned int flags);
    int bhkShape_QMaterial();

    int m_0c;
    int m_10;
};
