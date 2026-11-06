// Private map storage declarations and reaction-form layout checks.
#ifndef FNV_TESREACTIONFORM_PRIVATE_DECLS_H
#define FNV_TESREACTIONFORM_PRIVATE_DECLS_H

#include <stddef.h>

typedef char TESReactionForm_size_check[(sizeof(TESReactionForm) == 0x10) ? 1 : -1];
typedef char TESReactionForm_list_offset_check[(offsetof(TESReactionForm, m_kReactionList) == 0x4) ? 1 : -1];
typedef char TESReactionForm_flags_offset_check[(offsetof(TESReactionForm, m_ucReactionFlags) == 0xC) ? 1 : -1];

class DistantTreeTextureInfo;
// Storage constructor at 0x0048b3e0; its original class identity is unresolved.
class TESReactionMapStorage
{
  public:
    TESReactionMapStorage(unsigned int);
    virtual void mapSlot();
};
template <class K, class V> class BSMapBase : public TESReactionMapStorage
{
  public:
    BSMapBase(unsigned int);
    virtual void mapSlot();
};

int Warning(const char*, ...);

#endif
