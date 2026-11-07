#pragma once

#include "FaceGenMatrix.h"
#include "IO_TASK_PRIORITY.h"
#include "NiPointer.h"

class BSFaceGenModelMap;
class FaceGenAlphaProperty;
class NiTexture;
class QueuedFile;
class TESNPC;
template <class T> class BSStringT;

struct FaceGenCoordinates
{
    char data[0x60];
};

struct OpaqueDataBlock;

struct FaceGenCoordArr
{
    void resize(unsigned int uiSym, unsigned int uiAsym);
    char data[0x20];
};

struct FaceGenSam
{
    FaceGenSam();
    ~FaceGenSam();
    unsigned int uiGeo;
    unsigned int uiTex;
    FaceGenCoordArr coords[2][2];
    char rest[0x30];
};

struct FaceGenCtlVec
{
    unsigned int std_vector_FanLinCtlS_std_allocator_FanLinCtlS_size() const;
    OpaqueDataBlock* GetElementPointerChecked(unsigned int uiIndex);
    char data[0x18];
};

struct FaceGenCtls
{
    FaceGenCtls();
    ~FaceGenCtls();
    FaceGenCtlVec ctl[2][2];
};

struct FaceGenModels
{
    FaceGenModels();
    ~FaceGenModels();
    char data[0x106c];
};

class BSFaceGenManager
{
public:
    union
    {
        struct
        {
            char pad[8];
            FaceGenCoordinates coords;
            char rest[0x1194 - 8 - 0x60];
        };
        struct
        {
            FaceGenSam m_kSam;
            FaceGenCtls m_kCtls;
            FaceGenModels m_kModels;
            unsigned int m_auiInfo[4];
        };
    };
    union
    {
        BSFaceGenModelMap* cache;
        BSFaceGenModelMap* m_pModelCache;
    };
    NiPointer<FaceGenAlphaProperty> m_spAlpha;
    NiPointer<NiTexture> m_spBaseTexture;
    NiPointer<NiTexture> m_spDetailTexture;

    BSFaceGenManager();
    ~BSFaceGenManager();

    static BSFaceGenManager* GetFaceGenManager();
    static void* __stdcall GetFaceGenManager(float, int, int);
    static FaceGenCoordinates* GetFaceGenCoordinates();
    static BSFaceGenModelMap* GetModelMap();
    static void __cdecl ApplyFaceGenValues(float*, unsigned int, bool);
    static void NormalizeFaceGenValues(float* quantities, unsigned int count);
    static void InitializeFaceGenCoordinates(FaceGenCoordinates*);
    static void InitializeFaceGenCoordinates(FaceGenMatrix<float> (*)[2]);
    static char* BuildFaceGenPartPath(char*, int);
    static const char* BuildFaceGenModelPath(BSStringT<char>&, const char*);
    static void CopyFaceGenCoordinates(FaceGenMatrix<float> (*)[2], FaceGenMatrix<float> (*)[2], bool, bool);
    static void BlendFaceGenCoordinates(FaceGenMatrix<float> (*)[2], FaceGenMatrix<float> (*)[2],
                                        FaceGenMatrix<float> (*)[2], bool, float);
    static void QueueHeadModelLoad(TESNPC*, IO_TASK_PRIORITY, QueuedFile*);
};
