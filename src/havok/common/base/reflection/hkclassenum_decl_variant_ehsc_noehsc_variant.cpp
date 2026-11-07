
// src/havok/common/base/reflection/hkclassenum_decl_variant_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/base/reflection/hkclassenum_decl_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/reflection/hkclassenum_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00db7600: the skeleton of src/havok/common/base/reflection/hkclassenum.cpp
// with declarations corrected to what the original code does (hkBase.h: typedef char hkBool; -> class hkBool { public: __forceinline hkBool() {} _; hkClassEnum.h: hkClassEnum += void FUN_00db7600(class hkStreamWriter* writer) const;). Move the function to its real unit once
// that unit declares it this way.
// src/havok/common/base/reflection/hkclassenum.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassenum.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkOArchive.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkClass.h"
// The shared headers supply the base types used by the legacy enum declaration.
#define FNV_HAVOK_HKBASE_H
#include "havok/hkClassEnum_decl_hkclassenum.h"
class hkClassEnumItem
{
  public:
    int value;
    const char* name;
};
int __cdecl hkString_strLen(const char*);
// @fnv 0x00db7600
// src: HAVOK_LIB 0x00db7600
void hkClassEnum::writeSignature(hkStreamWriter* writer) const
{
    hkOArchive archive(writer, false);
    const char* name = m_name;
    archive.WriteRaw(name, hkString_strLen(name));
    int count = m_items.m_iElementCount;
    for (int i = 0; i < count; ++i)
    {
        const hkClassEnumItem& item = m_items.m_data[i];
        const char* itemName = item.name;
        archive.WriteRaw(itemName, hkString_strLen(itemName));
        archive.WriteInt(item.value);
    }
    archive.WriteInt(count);
}
