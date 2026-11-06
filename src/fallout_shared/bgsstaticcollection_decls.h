// fallout_shared/bgsstaticcollection_decls.h: declares TESObject, ShortPoint3, TESBoundObject__BOUND_DATA, TESBoundObject, FileEntryList and more
#ifndef FNV_BGSSTATICCOLLECTION_DECLS_H
#define FNV_BGSSTATICCOLLECTION_DECLS_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "../../include/TESForm.h"
#include "layout_support.h"
class BGSStaticCollection;
class BSFileEntry;
class ShortPoint3;
class TESBoundObject__BOUND_DATA;
class TESModel;
class TESModelTextureSwap;
class TESFormList;
class FileEntryList;
class DistantTreeTextureInfo;
#include "../../include/TESObject.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"
#include "../../include/TESBoundObject.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/BGSStaticCollection.h"
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
#endif
