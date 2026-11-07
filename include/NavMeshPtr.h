#pragma once

class NavMesh;
class NavObject;
class NiPoint3;
class RefObject;
class Ret559;
template <class T> class NiPointer;

struct NavMeshPtr
{
public:
    NavMesh* m_pObject;

    NavMeshPtr();
    NavMeshPtr(NavObject* object);
    NavMeshPtr(RefObject* object);
    NavMeshPtr(const NavMeshPtr& other);
    ~NavMeshPtr();

    NavMeshPtr& operator=(const NavMeshPtr& other);
    NavMeshPtr& operator=(const NiPointer<NavMesh>& other);
    bool operator==(const NavMeshPtr& other);
    bool operator!=(const NavMeshPtr& other);
    NavMesh* operator->();
    NavMesh* operator->() const;
    operator NavMesh*();
    operator NavMesh*() const;
    operator unsigned int();
    operator unsigned int() const;
    NavMesh* GetPtr();
    NavMesh* GetPtr() const;

    NavMeshPtr& AssignRetainedObject_0042fdc0(const NavMeshPtr& other);
    void __thiscall Object_ForwardCall_0042fa40();
    void* __thiscall FUN_0042ffa0(unsigned int flags);
    NavMesh* AnimatingText_GetFullText();
    NavMesh* Modelloader_GetReferencedThis();
    Ret559* Modelloader_GetReferencedThis(unsigned int, NiPoint3*, float*, float, float);
    void* GetTextElementPointer512(int index);
};
