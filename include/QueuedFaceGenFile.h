#pragma once

#include "QueuedFileLoad.h"

class QueuedFaceGenFile : public QueuedFileLoad
{
public:
    virtual ~QueuedFaceGenFile();

    char m_kObject[4];
    char m_pMesh[4];
};
