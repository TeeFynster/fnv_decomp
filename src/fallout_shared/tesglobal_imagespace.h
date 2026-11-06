// fallout_shared/tesglobal_imagespace.h: declares TESImageSpace
#ifndef TESGLOBAL_IMAGESPACE_H
#define TESGLOBAL_IMAGESPACE_H

#include "layout_support.h"
#include "../../include/TESForm.h"
class TESImageSpace : public TESForm
{
  public:
    TESImageSpace();
    virtual void ResetFormData();
};
#endif
