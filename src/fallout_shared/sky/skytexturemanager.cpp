// fallout_shared/sky/skytexturemanager.cpp: SkyTextureManager, SkyTask (5 functions)

#include "../../../include/BSShaderManager.h"
#include "../../../include/IOManager.h"
#include "../../../include/IOTask.h"
#include "../../../include/QueuedFile.h"
#include "../../../include/QueuedFileEntry.h"
#include "../../../include/SkyTask.h"
#include "../../../include/SkyTextureManager.h"
#include "AutoMemContext.h"

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* object);
bool __cdecl CleanPath(const char* path, char* output, unsigned int outputSize);
extern IOManager* DAT_01202d98;

// @fnv 0x0063fb70
void SkyTextureManager::LoadTextureFromPath(NiPointer<NiTexture>* texture, const char* fileName)
{
    struct TextureRequest
    {
        SkyTask* task;
        const char* path;
    } request;
    char standardizedPath[260];
    request.path = 0;
    if (fileName)
    {
        CleanPath(fileName, standardizedPath, sizeof(standardizedPath));
        request.path = standardizedPath;
    }
    request.task = new SkyTask(texture, fileName);
    DAT_01202d98->AddTask(reinterpret_cast<QIOTask*>(request.task));
}

// Creates a sky memory context and requests the sky texture via BSShaderManager::GetTexture using GetFileName().
// @fnv 0x0063fac0
void SkyTask::Run()
{
    AutoMemContext context(static_cast<MEM_CONTEXT>(33), true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\sky\\SkyTextureManager.cpp", 50);
    BSShaderManager::GetTexture(GetFileName(), true, *apTextureOutput, true, false);
}

// @fnv 0x0063fa10
SkyTask::SkyTask(NiPointer<NiTexture>* texture, const char* name) : QueuedFileEntry(3)
{
    apTextureOutput = texture;
    SetFileName_00c3cee0(name);
    LookupFileEntryByArchive(1);
}

// @fnv 0x0063fb40
bool SkyTask::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    return QueuedFileEntry::GetDescription(apDescription, aiBufferSize, (char*)"skytask");
}
