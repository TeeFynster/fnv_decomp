
// src/havok/animation/animation/animation/util/hkaanimationpreviewcolorclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/util/hkaanimationpreviewcolorclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Allocator
{
    virtual void slot0();
    virtual void slot1();
    virtual void Free(void* object, unsigned short size);
};
struct Holder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    Allocator* allocator;
};
Holder* hkMemoryRouter_getInstance();
struct hkaAnimationPreviewColorContainer
{
    unsigned int unk00;
    unsigned short allocationSize;
    hkaAnimationPreviewColorContainer* Destroy(unsigned int flags);
    void ReleaseOwnedArray();
};
// Calls FUN_00e41e20, and if flags has bit 0 set, frees this through the allocator from FUN_00c85750 using allocationSize; returns this.
// @fnv 0x00dfe6b0
hkaAnimationPreviewColorContainer* hkaAnimationPreviewColorContainer::Destroy(unsigned int flags)
{
    ReleaseOwnedArray();
    if (flags & 1)
    {
        Holder* holder = hkMemoryRouter_getInstance();
        Allocator* allocator = holder->allocator;
        unsigned short size = allocationSize;
        allocator->Free(this, size);
    }
    return this;
}
