#pragma once
#include "hkBool.h"   // CompileTimeTrueType / CompileTimeFalseType

// Common/Base/Types/hkTypeTraits.h. hkTraitBool is spelled BooleanTypeConstant here (the name the units and
// hkVector4.h use); hkIsPodType is IsPodType.
// compile-time flag type: hkArray picks its copy/construct overloads with it
template <bool bFlag> struct BooleanTypeConstant  // src: HAVOK_SRC (shape)
{
    enum { result = bFlag };
    typedef BooleanTypeConstant<bFlag> type;
};
typedef BooleanTypeConstant<false> hkTypeIsClass;
typedef BooleanTypeConstant<true> hkTypeIsPod;

// A type counts as POD when it declares an `operator==(const T&, const hkTypeIsPod&)` returning the true type (the
// Havok POD declaration macro does); the catch-all template below returns the false type. Pointers are always POD.
template <typename T> hkBool::CompileTimeFalseType operator==(const T&, const hkTypeIsPod&);
template <typename T> struct PodDeclaredProbe
{
    static T& Self();
    static const hkTypeIsPod& Tag();
    enum { value = sizeof(Self() == Tag()) == sizeof(hkBool::CompileTimeTrueType) };
};
template <typename T> struct IsPodType : public BooleanTypeConstant<PodDeclaredProbe<T>::value> {};
template <typename T> struct IsPodType<T*> : public hkTypeIsPod {};
