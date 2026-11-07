
// src/havok/common/scenedata/scene/hkxsceneclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/scene/hkxsceneclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Allocator
{
    virtual void Allocate();
    virtual void Reallocate();
    virtual void Free(void* object, unsigned int size);
};
struct AudioManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};
AudioManager* hkMemoryRouter_getInstance();
struct AudioObject
{
    void* vtable;
    unsigned short allocationSize;
    void ClearScene();
    AudioObject* Release(unsigned int flags);
};
// Calls ClearScene, then if flags has bit 0 set frees this through the AudioManager allocator using allocationSize, and returns this.
// @fnv 0x00e01ca0
AudioObject* AudioObject::Release(unsigned int flags)
{
    ClearScene();
    if (flags & 1)
    {
        AudioManager* manager = hkMemoryRouter_getInstance();
        manager->allocator->Free(this, allocationSize);
    }
    return this;
}
