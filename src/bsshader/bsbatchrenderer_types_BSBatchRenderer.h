#pragma once

#include "layout_support.h"
#include "../../include/BSBatchRenderer.h"

#pragma pack(push, 4)
struct BSBatchRenderer__PassBucketEntry
{
    unsigned int padding;
    void* m_pRenderPass;
    unsigned char tail[12];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSBatchRenderer__PassBucketEntry) == 20);
