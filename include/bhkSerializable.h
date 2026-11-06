#pragma once

#include "bhkRefObject.h"

class WorldHolder;
class MoppCodeHeader;

class bhkSerializable : public bhkRefObject
{
public:
    bhkSerializable();
    virtual ~bhkSerializable();

    virtual void* v37(); // EAX pointer: bhkSerializable 0x00c87a40, bhkWorld 0x00d47a30
    virtual WorldHolder* GetWorld();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual unsigned int slotA8();
    virtual void vf43();
    virtual void vf44();
    virtual MoppCodeHeader* slotB4(char* pAllocated);
    virtual void vf46();
    virtual void vf47(int);
    virtual void vf48();

    void Destroy();
    void* FUN_004b5160(unsigned int flags);
};
