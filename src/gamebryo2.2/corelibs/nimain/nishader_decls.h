// gamebryo2.2/corelibs/nimain/nishader_decls.h: private reference-count helpers
#ifndef FNV_NISHADER_PRIVATE_DECLS_H
#define FNV_NISHADER_PRIVATE_DECLS_H

class WaitableObject
{
  public:
    void NiRefObject_DecRefCount();
    void NiRefObject_IncRefCount();
};
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    NiPointer<NiAVObject>& operator=(NiAVObject* object);
};
#endif
