#pragma once

#include "NiSourceTexture.h"
#include "StrArr.h"

class CubeMapLoader;
class LoadBuffer;
class Pixels;

bool __stdcall FUN_00a60850(NiStream&);

class NiSourceCubeMap : public NiSourceTexture
{
  public:
    NiSourceCubeMap() throw() { m_uiFace = 0; }
    virtual ~NiSourceCubeMap();


    bool FUN_00a5fae0(NiObject*);
    bool FUN_00a60880(NiObject*);
    bool CreateCubeOrRelease();
    void GetFileStrings(StrArr*);
    void AppendGlobalString(StrArr*);
    void FUN_00a60ba0(NiStream&);
    void LinkObjectOld(NiStream&);
    void SetFaces(NiObject*, NiObject*, NiObject*, NiObject*, NiObject*, NiObject*);
    void Load(void*, void*, void*, void*, void*, void*, LoadBuffer*);
    void CreateFaces(char*, char*, char*, char*, char*, char*, int);
    void FUN_00a612a0(NiStream&);
    void FUN_00a60940(NiRefObject*, NiRefObject*, NiRefObject*,
                      NiRefObject*, NiRefObject*, NiRefObject*);
    void LoadResources(char*, char*, char*, char*, char*, char*, CubeMapLoader*);
    void* FUN_00a61250(unsigned int);
    void FUN_00a60940(Pixels*, Pixels*, Pixels*, Pixels*, Pixels*, Pixels*);

    unsigned int m_uiFace;
};
