#pragma once

#include "NiSourceTexture.h"
#include "StrArr.h"

class CubeMapLoader;
class LoadBuffer;
class Pixels;

bool __stdcall NiSourceCubeMap_RegisterStreamables(NiStream&);

class NiSourceCubeMap : public NiSourceTexture
{
  public:
    NiSourceCubeMap() throw() { m_uiFace = 0; }
    virtual ~NiSourceCubeMap();


    bool NiSourceTexture_IsEqual(NiObject*);
    bool IsEqual_00a60880(NiObject*);
    bool CreateCubeOrRelease();
    void GetFileStrings(StrArr*);
    void AppendGlobalString(StrArr*);
    void LinkObject_00a60ba0(NiStream&);
    void LinkObjectOld(NiStream&);
    void SetFaces(NiObject*, NiObject*, NiObject*, NiObject*, NiObject*, NiObject*);
    void Load(void*, void*, void*, void*, void*, void*, LoadBuffer*);
    void CreateFaces(char*, char*, char*, char*, char*, char*, int);
    void LoadBinary_00a612a0(NiStream&);
    void LoadFromPixelData(NiRefObject*, NiRefObject*, NiRefObject*,
                      NiRefObject*, NiRefObject*, NiRefObject*);
    void LoadResources(char*, char*, char*, char*, char*, char*, CubeMapLoader*);
    void* FUN_00a61250(unsigned int);
    void LoadFromPixelData(Pixels*, Pixels*, Pixels*, Pixels*, Pixels*, Pixels*);

    unsigned int m_uiFace;
};
