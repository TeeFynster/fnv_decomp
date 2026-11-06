#pragma once

template <class T> class NiPointer;
class NiTexture;

class SkyTextureManager
{
public:
    static void LoadTextureFromPath(NiPointer<NiTexture>*, const char*);
};
