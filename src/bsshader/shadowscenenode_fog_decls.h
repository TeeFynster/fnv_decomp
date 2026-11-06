// bsshader/shadowscenenode_fog_decls.h: fog declarations and inline bodies
#ifndef FNV_SHADOWSCENENODE_FOG_DECLS_H
#define FNV_SHADOWSCENENODE_FOG_DECLS_H


#include "layout_support.h"

#include "../../include/BSFogProperty.h"

#include "../../include/NiColor.h"

inline NiColor::NiColor(float red, float green, float blue) : r(red), g(green), b(blue)
{}

// BSFogProperty has the NiObjectNET reference-count layout in the game.
inline void BSFogProperty::IncRefCount()
{
    reinterpret_cast<NiObjectNET*>(this)->IncRefCount();
}

inline void BSFogProperty::DecRefCount()
{
    reinterpret_cast<NiObjectNET*>(this)->DecRefCount();
}

inline void BSFogProperty::SetFog(float start, float end)
{
    nearDepth = start;
    farDepth = end;
}

inline void BSFogProperty::SetPower(float power)
{
    density = power;
}

// The shared declaration exposes the water-fog float slots as opaque integers.
inline void BSFogProperty::SetWaterFog(float start, float end)
{
    reinterpret_cast<float&>(unk34) = start;
    reinterpret_cast<float&>(unk38) = end;
}

inline void BSFogProperty::SetWaterColor(const NiColor& color)
{
    reinterpret_cast<NiColor&>(unk54) = color;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* object)
{
    if (m_pObject != object)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = object;
        if (object)
            object->IncRefCount();
    }
    return *this;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

FNV_STATIC_ASSERT(sizeof(NiColor) == 12);
FNV_STATIC_ASSERT(sizeof(BSFogProperty) == 100);
FNV_STATIC_ASSERT(offsetof(BSFogProperty, nearDepth) == 0x2c);
FNV_STATIC_ASSERT(offsetof(BSFogProperty, unk54) == 0x54);
FNV_STATIC_ASSERT(offsetof(BSFogProperty, density) == 0x60);
FNV_STATIC_ASSERT(offsetof(ShadowSceneNode, spFog) == 0x134);
#endif
