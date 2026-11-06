// Stars.h lacks the loader, update, destructor, and instance fields used by this unit.
#ifndef FNV_STARS_DECLS_H
#define FNV_STARS_DECLS_H
#include "../../../include/SkyObject.h"
class Stars : public SkyObject
{
  public:
    void Initialize(NiNode*) override;
};
#endif
