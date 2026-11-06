#pragma once

// Gamebryo 2.2 NiTStringMap.h: string-keyed map over TPARENT (NiTMap<const char*,V> or NiTPointerMap<const char*,V>).
// RTTI: NiTStringTemplateMap<NiTMap<char const *,char *>,char *> : NiTMap<...>, 7 vftable slots (overrides the hash,
// key compare, SetValue and ClearValue for strings). One member, bool m_bCopy at 0x10 (NiTStringPointerMap<int>'s
// static ctor at 0x00fb3250 constructs the 0x101-bucket parent and then stores 1 at 0x011f32f4 + 0x10): 0x14 bytes.
template <class TPARENT, class TVAL> class NiTStringTemplateMap : public TPARENT
{
  public:
    NiTStringTemplateMap(unsigned int uiHashSize = 37, bool bCopy = true);
    virtual ~NiTStringTemplateMap();

    virtual unsigned int KeyToHashIndex(const char* pKey) const;
    virtual bool IsKeysEqual(const char* pcKey1, const char* pcKey2) const;
    virtual void SetValue(NiTMapItem<const char*, TVAL>* pkItem, const char* pcKey, TVAL val);
    virtual void ClearValue(NiTMapItem<const char*, TVAL>* pkItem);

    bool m_bCopy;
};
