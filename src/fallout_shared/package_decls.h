#include "../../include/PackageTargetRecord.h"
// fallout_shared/package_decls.h: package target, duration and time declarations


class DurationData
{
  public:
    unsigned int time, duration;
    DurationData();
    ~DurationData();
    void Copy(DurationData*);
};
#include "../../include/PTYPE.h"
extern float gPackageLocationRadius;
class TimeGlobal
{
  public:
    float FUN_0084d030();
};
