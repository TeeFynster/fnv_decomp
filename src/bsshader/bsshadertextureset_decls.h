// bsshader/bsshadertextureset_decls.h: defines the NiTexture pointer inline specializations and declares NiFree
#ifndef BSSHADERTEXTURESET_DECLS_H
#define BSSHADERTEXTURESET_DECLS_H

template <> FNV_FORCEINLINE NiPointer<NiTexture>::NiPointer() : m_pObject(0)
{}

template <> FNV_FORCEINLINE NiPointer<NiTexture>::~NiPointer()
{
    if (m_pObject)
    {
        NiTexture* object = m_pObject;
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
            object->DeleteThis();
    }
}

void __cdecl NiFree(void* memory);

#endif
