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

    void* NiAdditionalGeometryData_LockDataBlock(unsigned int, unsigned int*);
    void* NiAdditionalGeometryData_UnlockDataBlock(unsigned int);
    bool __thiscall NiAdditionalGeometryData_IsEqual(const NiAdditionalGeometryData*);
    bool NiAdditionalGeometryData_GetDataStream(unsigned int uiIndex, char** ppcData, void** ppvStream, unsigned short* pusVertexCount,
                      int* piFormat, int* piStride, int* piUsage);
    void* FUN_00537cb0(unsigned int flags);

    unsigned char unk08[0x24];
    unsigned int m_uiShaderDeclarationIndex;
    unsigned int m_uiUnknownValue;
};
