// fallout_shared/magic/alchemyitem.h: bhkHingeConstraint::GetInstanceSize, BSFile::GetFileSize and a +0x168 getter
#ifndef ALCHEMYITEM_H
#define ALCHEMYITEM_H

#include "../../../include/bhkHingeConstraint.h"
#include "../../../include/BSFile.h"

// 0x00afc0c0 reads +0x168, past the end of BSFile (0x158 bytes): the owner is another class.
class FUN_00afc0c0_Owner
{
  public:
    char* GetName168() const;

  private:
    char unknown_000[0x168];
    char* m_pName168;
};

// @fnv 0x00402b00
unsigned int bhkHingeConstraint::GetInstanceSize()
{
    return 20;
}
// @fnv 0x00afc0c0
char* FUN_00afc0c0_Owner::GetName168() const
{
    return m_pName168;
}
// BSFile vftable slot 7 (0x010a4764 + 0x1c): computes the size through slot 10 (GetSize) on first use.
// @fnv 0x00aff610
unsigned int BSFile::GetFileSize()
{
    if (!m_uiValueId)
        GetSize();
    return m_uiValueId;
}
#endif
