// fallout_shared/facegen/bsfacegenmodel_decls.h: local FaceGen declarations and shared game types
#ifndef BSFACEGENMODEL_DECLS_H
#define BSFACEGENMODEL_DECLS_H

#include "../../../include/AutoMemContext.h"
#include "../../../include/BGSQuestObjective.h"
#include "../../../include/BSFaceGenBaseMorphExtraData.h"
#include "../../../include/BSFaceGenMorphData.h"
#include "../../../include/BSFaceGenMorphDataHair.h"
#include "../../../include/BSFaceGenMorphDataHead.h"
#include "../../../include/NiGeometryData.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiTriBasedGeom.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/TES.h"
#include "../../../include/BSFaceGenModel.h"
#include "../../../include/BSFaceGenManager.h"

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete[](void*);
#include "../../../include/MEM_CONTEXT.h"
#include "../../../include/HAIR_PART.h"
template <class T> class FaceGenIterator
{
  public:
    T* current;
    void* container;
    T& operator*() const;
    FaceGenIterator operator++(int);
};
template <class T> class FaceGenVector
{
  public:
    void* proxy;
    T* first;
    T* last;
    T* end;
    unsigned int allocator;
    unsigned int state;
    unsigned int size() const;
    T& operator[](unsigned int);
    FaceGenIterator<T> begin();
};
template <class T> class ThreeComponentVector
{
  public:
    T x, y, z;
};
class FaceGenMorphTarget
{
  public:
    float scale;
    FaceGenVector<ThreeComponentVector<short> > kVertexPositionLocal;
};
class FaceGenMorphData
{
  public:
    unsigned int state;
    FaceGenVector<FaceGenMorphTarget> modes[2];
    FaceGenMorphData(const char*);
};
class FaceGenCoordinate
{
  public:
    unsigned int data[8];
    FaceGenIterator<float> operator()(unsigned int, int);
};
class GeometryBufferView
{
  public:
    void* data;
    unsigned int stride;
    unsigned int count;
    GeometryBufferView();
    unsigned int* FUN_00717e50();
    void* Modelloader_GetReferencedThis();
    void NiGeometryDataIteratorNiPoint3_Get(unsigned int, NiPoint3&);
    void FUN_0065b390(unsigned int, const NiPoint3&);
};
class TESQuest;
class NiSkinInstance;
class FaceGenTriData
{
  public:
    unsigned int data[60];
    FaceGenTriData();
    ~FaceGenTriData();
    unsigned int ProcessEntries_0065a5a0();
    unsigned int std_vector_FR2Vect3TC_float_std_allocator_FR2Vect3TC_float_size();
    NiPoint3& GetCheckedElement(unsigned int);
};
class FaceGenGeometryModel
{
  public:
    BSStringT<char> m_kEGMFileName;
    FaceGenMorphData* m_pModelData;
    NiPointer<NiNode> m_spModelRoot;
    NiPointer<NiTriBasedGeom> m_pRenderedNodeEntry;
    NiPoint3* pAdditionalVertices;
    unsigned int m_uiAdditionalVertexCount;
    NiPointer<BSFaceGenMorphData> m_spFaceMorphData;
    int BackgroundTask;
    FaceGenGeometryModel();
};
struct FaceGenTextureFile;
class BSFaceGenTexture
{
  public:
    BSStringT<char> EGTFileName;
    FaceGenTextureFile* m_pTextureData;
    BSFaceGenTexture();
};
void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();
bool BSFaceGenManager_LoadEGMData(BSFaceGenModel*);
BSFaceGenBaseMorphExtraData* GetExtraDataIfPresent(NiTriBasedGeom*);
class CloningProcess
{
  public:
    unsigned int state[7];
    CloningProcess(float);
    ~CloningProcess();
};
class ModelLoader
{
  public:
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
};
class NarrowString
{
  public:
    unsigned int text[7];
    NarrowString(const char*);
    ~NarrowString();
};
extern ModelLoader* g_modelLoader;
extern TES* g_TES;
extern const char* DAT_0119b734[];
int __cdecl BSstricmp(const char*, const char*);
int Warning(const char*, ...);
int NiTexturingProperty_GetType();
bool fffReadTriFile(const NarrowString&, FaceGenTriData*);
FaceGenTextureFile* BSFaceGenModel_EGTData_Create(const char*);
NiAVObject* GetGeomExtraData(NiAVObject*);
#endif
