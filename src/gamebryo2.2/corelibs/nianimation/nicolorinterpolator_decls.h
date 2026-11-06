// gamebryo2.2/corelibs/nianimation/nicolorinterpolator_decls.h: declares NiAnimationKey, NiMemObject, NiColorData, NiColorInterpolator
#ifndef FNV_NICOLORINTERPOLATOR_DECLS_H
#define FNV_NICOLORINTERPOLATOR_DECLS_H

#include "../../../../include/NiAnimationKey.h"
class ColorAnimationKey;
#include "../../../../include/NiMemObject.h"
class NiColorData : public NiMemObject
{
    char storage[24];

  public:
    NiColorData();
    void SetColorKeys(ColorAnimationKey*, unsigned int, NiAnimationKey::KeyType);
};
template <class T> class NiPointer
{
    T* m_pObject;

  public:
    T* operator->() const;
    NiPointer& operator=(T*);
};
class NiColorInterpolator
{
    char prefix[28];
    NiPointer<NiColorData> m_spColorData;
    unsigned int m_uiLastKeyIndex;

  public:
    void SetAnimationKeys(ColorAnimationKey*, unsigned int, NiAnimationKey::KeyType);
};
#endif
