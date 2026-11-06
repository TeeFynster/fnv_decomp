
// bscore/console/bscriticalsection_console_decls.h: declares BSCriticalSectionEntry
struct BSCriticalSectionEntry
{
    BSCriticalSectionEntry* next;
    unsigned int key;
    unsigned int value;
};
// BSCriticalSectionMap: unit-local; not RecursiveLock but a hash map of BSCriticalSectionEntry (vftable +0 with the
// hash-index virtual at slot 1, bucket count +4, buckets +8): 0x00a0c850 steps an iterator through it (NiTMapBase::GetNext shape)
class BSCriticalSectionMap
{
  public:
    virtual void vfn_0();
    virtual unsigned int vfn_4(unsigned int key);
    unsigned int bucketCount;
    BSCriticalSectionEntry** buckets;
    void Unlock(BSCriticalSectionEntry** entry, unsigned int* key, unsigned int* value);
};
