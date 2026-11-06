#pragma once

#include "QueuedFileEntry.h"
#include "NiTexture.h"

#pragma pack(push, 4)
class SkyTask : public QueuedFileEntry
{
public:
    SkyTask(NiPointer<NiTexture>* texture, const char* fileName);
    virtual ~SkyTask();
    virtual void Run();
    virtual void Finish();
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual unsigned char GetFileIndex();

    SkyTask& operator=(const SkyTask& other);

    NiPointer<NiTexture>* apTextureOutput;
    unsigned char layoutPadding34[4];
};
#pragma pack(pop)
