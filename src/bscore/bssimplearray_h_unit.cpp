// bscore/bssimplearray_h_unit.cpp: PathOwner (1 function)

#include "bssimplearray.h"
#include "../../include/TESForm.h"

typedef unsigned int size_t;

inline void* operator new(size_t, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}

class PathNodeA
{
  public:
    char data[0x30];
    PathNodeA(void* a, TESForm* b);
};

class PathPool
{
  public:
    void* AdvanceCounter();
    void* GetElementAddress30_006e8f40(void* id);
};

class FormIDArray
{
  public:
    unsigned int Add(const unsigned int& value);
};

class PathOwner
{
  public:
    void* vtable;
    int pad4;
    PathPool pool;
    char pad9[0x27];
    FormIDArray forms;

    void* CreatePathNode(void* a, TESForm* b);
};

// Allocates a path node from the pool, constructs it with a and b, and if b is non-null adds b's form ID to the forms array.
// @fnv 0x006ce7e0
void* PathOwner::CreatePathNode(void* a, TESForm* apForm)
{
    void* id = pool.AdvanceCounter();
    void* pNodePlace = pool.GetElementAddress30_006e8f40(id);
    new (pNodePlace) PathNodeA(a, apForm);
    if (apForm)
    {
        forms.Add(apForm->GetFormID());
    }
    return id;
}
