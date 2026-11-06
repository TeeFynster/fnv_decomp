#pragma once

#include "NiObject.h"
#include "ShadowSceneNode.h"

class NiAGDDataBlock;
class ShadowSceneNode;

class NiAdditionalGeometryData : public NiObject
{
  public:
    virtual bool IsPacked() const;
    virtual NiAGDDataBlock* CreateNiAGDDataBlock();

    unsigned short GetVertexCount() const;
    void SetVertexCount(unsigned short usVertices);
    bool HasGeometryProperty() const;
    void CopyDataMembers(const NiAdditionalGeometryData* pkSrc);
    void ReserveDataStreams(unsigned int ItemUpdateArray);
    unsigned int GetDataStreamCount() const;
    void* GetDataStream(unsigned int uiIndex);
    bool IsDataStreamValid(unsigned int uiIndex) const;

    static ShadowSceneNode* __cdecl GetShadowSceneNodeForIndex(int index);
    static ShadowSceneNode* __cdecl GetShadowSceneNodeForIndex(unsigned int index);

    void* FUN_00a72590(unsigned int, unsigned int*);
    void* FUN_00a725d0(unsigned int);
    bool __thiscall FUN_00a727f0(const NiAdditionalGeometryData*);
    bool FUN_00a72720(unsigned int uiIndex, char** ppcData, void** ppvStream, unsigned short* pusVertexCount,
                      int* piFormat, int* piStride, int* piUsage);
    void* FUN_00537cb0(unsigned int flags);

    unsigned char unk08[0x24];
    unsigned int m_uiShaderDeclarationIndex;
    unsigned int m_uiUnknownValue;
};
