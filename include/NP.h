#pragma once

class AVObj;
class NiAVObject;

class CleanupRef;
class RefObject;
class RefQ;

class NP
{
public:
    void* p;

    NP(RefObject* p = 0);
    NP(RefQ* p = 0);
    NP(void* p);
    NP(NiAVObject* q);
    NP(int value);
    ~NP();

    void operator=(CleanupRef* const& incoming);
    NP& operator=(const NP& rhs);
    NP& operator=(void* pObject);
    void Reset(void* pObject);
    operator void*() const;
    operator int() const;

    AVObj* Modelloader_GetReferencedThis();
    int Modelloader_GetReferencedThis() const;
    NP& FUN_0066b0d0(void* pObject);

    static void operator delete[](void* data);
};
