// bsshader/imagespaceeffectnoise_decls.h: effect classes without approved shared headers

#include "../../include/MemoryManager.h"

extern MemoryManager g_memoryManager;
class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
    // Setup at 0x00C05180 allocates 0x88 bytes for the shader parameter.
    char storage[136];

  public:
    ImageSpaceShaderParam();
    void AllocateShaderConstants(int, int);
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTArray.h"
class ImageSpaceTexture;
class ImageSpaceEffect
{
  public:
    char prefix[24];
    NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> > params;
    NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> > textures;
    void SetTextureArrayCount(int);
    void SetEffectParamAt(int, int, int);
    void SetEffectAt(int, ImageSpaceEffect*, ImageSpaceEffectParam*, int);
};
class NoiseImageSpaceEffect : public ImageSpaceEffect
{
  public:
    void Setup(ImageSpaceManager*, ImageSpaceEffectParam*);
};
