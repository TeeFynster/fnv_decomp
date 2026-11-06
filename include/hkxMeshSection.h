#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkxVertexBuffer;
class hkxIndexBuffer;
class hkxMaterial;

class hkxMeshSection : public hkReferencedObject
{
public:
    hkxVertexBuffer* m_pMeshVertexBuffer;
    hkArray<hkxIndexBuffer*> m_kIndexBuffers;
    hkxMaterial* m_iMaterialIndex;
    hkArray<hkReferencedObject*> m_kUserChannels;
};
