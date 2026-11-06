#pragma once

#include "QueuedFileEntry.h"

class QueuedTexture : public QueuedFileEntry
{
public:
    virtual unsigned char GetFileIndex() override;
};
