// fallout_shared/tesanimation_decls.h: declares ActorValueOwner, TESAnimation
#ifndef TESANIMATION_DECLS_H
#define TESANIMATION_DECLS_H

class ActorValueOwner
{
  public:
    ActorValueOwner();
    virtual float GetActorValue(unsigned int);
};
class TESForm;
template <class T> unsigned int BSStringLength(const T*);
#include "layout_support.h"
#include "BaseFormComponent.h"

class TESAnimation : public BaseFormComponent
{
  public:
    BSSimpleList<const char*> m_kKFFileList;
    void ClearComponent();
    ~TESAnimation();
    bool HasSpecialAnimations();
    void LoadComponent(TESForm*, TESFile*);
    void AddPathToList(const char*);
};

#endif
