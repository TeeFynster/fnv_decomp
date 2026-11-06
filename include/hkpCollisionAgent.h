#pragma once

#include <cstddef>
#include "hkReferencedObject.h"

class hkpContactMgr;

class hkpCollisionAgent : public hkReferencedObject
{
public:
    class CommandArgument;

    static void* __cdecl operator new(std::size_t nbytes);
    static void __cdecl operator delete(void* p);
    static void* __cdecl operator new(std::size_t nbytes, void* p);
    static void* __cdecl operator new[](std::size_t nbytes, void* p);
    static void __cdecl operator delete(void* p, void* placement);
    static void __cdecl operator delete[](void* p, void* placement);

    hkpContactMgr* m_pContactManager;

    hkpContactMgr* getContactMgr();

protected:
    hkpCollisionAgent(hkpContactMgr* contactMgr);
    ~hkpCollisionAgent() throw();
};
