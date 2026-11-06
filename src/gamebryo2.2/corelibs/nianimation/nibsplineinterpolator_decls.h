// Inline assignment used while loading the two spline objects.
#pragma once

template <class T>
__forceinline void AssignSplineObject(NiPointer<T>& slot, NiObject* object)
{
    if (slot.m_pObject != object)
    {
        if (slot.m_pObject)
            slot.m_pObject->DecRefCount();
        slot.m_pObject = static_cast<T*>(object);
        if (object)
            object->IncRefCount();
    }
}
