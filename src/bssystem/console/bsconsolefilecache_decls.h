#include "../../../include/BSSimpleList.h"
#include "../../../include/NiPointer.h"
#include "../../../include/FaceGenMatrix.h"
// bssystem/console/bsconsolefilecache_decls.h: declares FaceGenData
#ifndef FNV_BSCONSOLEFILECACHE_DECLS_H
#define FNV_BSCONSOLEFILECACHE_DECLS_H

#include "../../../include/NiTPrimitiveArray_unsigned_int_.h"
#include "../../../include/BSWin32FileCache.h"


class TESHair;
class TESEyes;
class TESModel;
class TESTexture;
class NiTexture;
class BGSHeadPart;
#include "../../../include/SEX.h"
enum BS_FACEGEN_LOD
{
    BS_FACEGEN_LOD_NONE = -1
};

namespace oldstd {
template <class T> struct vector
{
    unsigned int unk00;
    void* unk04;
    unsigned int unk08;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
};
}



#include "../../../include/NiTPrimitiveArray.h"
#include "../../../include/NiTObjectArray.h"






class FaceGenData
{
  public:
    FaceGenData();
    ~FaceGenData();
    FaceGenMatrix<float> m_kFaceGenCoordinates[2][2];
    TESHair* m_pHair;
    int iHairColor;
    float m_fHairLength;
    TESEyes* pEyes;
    SEX m_eSex;
    NiTPrimitiveArray<TESModel*> m_kModelObjectsItem;
    NiTPrimitiveArray<TESTexture*> pTexture;
    NiTPrimitiveArray<const char*> m_kTexturePaths;
    NiTObjectArray<NiPointer<NiTexture> > m_kFaceGenTextures;
    bool bFaceGenTexturing;
    bool m_bFaceGenDataValid;
    TESModel* m_pHeadModel;
    TESModel* m_pFaceGenModel;
    BS_FACEGEN_LOD m_eFaceGenLOD;
    BSSimpleList<BGSHeadPart*> Accessories;
};

#endif
