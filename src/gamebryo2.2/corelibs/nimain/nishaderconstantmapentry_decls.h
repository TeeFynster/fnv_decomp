#ifndef NISHADERCONSTANTMAPENTRY_DECLS_H
#define NISHADERCONSTANTMAPENTRY_DECLS_H

extern volatile long DAT_011f4400;
extern NiFixedString EmptyFS;

inline NiRefObject::NiRefObject()
{
    m_uiRefCount = 0;
    InterlockedIncrement(&DAT_011f4400);
}

#endif
