
#include "../../../../include/NiMemObject.h"
class Direct3DDeviceInterface
{
  public:
    virtual void slot0() = 0;
    virtual unsigned long __stdcall AddRef() = 0;
};
class VertexDeclarationLayout;
class NiGeometryGroup
{
  public:
    void* vtable;
    unsigned int refs;
    Direct3DDeviceInterface* device;
};
class NiUnsharedGeometryGroup
{
  public:
    static NiGeometryGroup* Create();
};
NiGeometryGroup* NiStaticGeometryGroup_Create();
NiGeometryGroup* GetNiGeometryGroup();
class NiStreamLinkIDSet
{
  public:
    unsigned int* data;
    unsigned int capacity, count;
    void Realloc(unsigned int);
    int Find(unsigned int value)
    {
        for (unsigned int i = 0; i < count; ++i)
            if (data[i] == value)
                return i;
        return -1;
    }
};
class NiGeometryGroupManager
{
  public:
    enum RepackingBehavior
    {
        STATIC,
        UNSHARED,
        DYNAMIC
    };
};
class NiD3DGeometryGroupManager : public NiMemObject
{
  public:
    void FUN_00a7f810();
    void** vtable;
    NiStreamLinkIDSet groups;
    Direct3DDeviceInterface* device;
    VertexDeclarationLayout* buffers;
    bool flag;
    NiGeometryGroup* CreateGroup(NiGeometryGroupManager::RepackingBehavior);
    static NiD3DGeometryGroupManager* Create(Direct3DDeviceInterface*, VertexDeclarationLayout*);
};
extern void* DAT_010ef718[];
