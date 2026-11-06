#include "../../../../include/NiTSet.h"
// gamebryo2.2/corelibs/niconsolerenderer/nid3dpass_decls.h: declares BeamStage, SNAEntry, NiD3DPassPoolRecord, NiD3DPassAllocation, NiD3DPassPool and more
#ifndef NID3DPASS_DECLS_H
#define NID3DPASS_DECLS_H

extern "C" void* DAT_0126f710;
extern "C" void* DAT_0126f714;
extern "C" unsigned int DAT_0126f680[];
class BeamStage
{
  public:
    unsigned char m_pcBase[0x60];
    unsigned int m_uiRefCount;
    void ReturnToPool();
};
struct SNAEntry
{
    unsigned int m_data[4];
    SNAEntry() throw();
    static void* operator new[](unsigned int bytes) throw();
};
class UnknownPoolReceiver
{
  public:
    unsigned int GetItemByIndex(unsigned int index);
};
struct NiD3DPassPoolRecord
{
    unsigned int unknown0;
    unsigned int poolIndex;
    unsigned int state;
    unsigned int unknownC;
    UnknownPoolReceiver* pool;
};
struct NiD3DPassAllocation
{
    SNAEntry* entries;
    unsigned int count;
    unsigned int reserved;
};
class NiD3DPassPool
{
  public:
    NiD3DPass** entries;
    unsigned int capacity;
    unsigned int size;
    unsigned int reserved;
    unsigned int grow;
    void Grow(unsigned int count);
    NiD3DPass* Get()
    {
        unsigned int& available = size;
        if (!available)
        {
            unsigned int& growth = grow;
            Grow(growth);
            growth *= 2;
        }
        NiD3DPass** base = entries;
        NiD3DPass* result = base[0];
        base[0] = base[--available];
        return result;
    }
};
extern "C" NiD3DPassPool* DAT_0126f72c;
class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    static void ReleaseRenderStateGroup(D3DRenderStateGroup* group);
};
struct NiD3DPassRefObject
{
    virtual void vfn_00();
    virtual void DeleteThis();
    long refs;
};
void NiFree(void* pointer);
template <class T> class NiTMallocInterface;

#endif
