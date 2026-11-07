#include "../../../include/Pathing.h"
#include "../../../include/RecursiveSpinLock.h"
// fallout_shared/pathfinding/pathmanager_decls.h: unit-specific path manager declarations


class WaitableObject;
class PathingRequest;

enum PATHING_MESSAGE_TYPE
{
    PATHING_MESSAGE_TYPE_PMT_UNDEF = -1,
    PATHING_MESSAGE_TYPE_PMT_OK = 0,
    PATHING_MESSAGE_TYPE_PMT_ERROR = 1
};

class ActorPathingMessage
{
  public:
    int m_eMessageType;
    NiPointer<WaitableObject> m_pPathingSolution;
    ActorPathingMessage(PATHING_MESSAGE_TYPE type, const NiPointer<PathingSolution>& solution);
    ~ActorPathingMessage();
    ActorPathingMessage& operator=(const ActorPathingMessage&);
};


#include "../../../include/NiMemObject.h"





class ParentSpaceNode;
#include "../../../include/BSSimpleArray.h"


template <class T> class NiTNewInterface;

#include "../../../include/NiTArray.h"

struct Struct_004b0680
{
    int m_val;
    void* m_ptr;
    Struct_004b0680(int val, void* ptr);
    ~Struct_004b0680();
};


class PerformanceMeasurement;
class PerformanceTimerManager
{
  public:
    PerformanceMeasurement* Register(char*, char*, bool, bool);
};

#include "../../../include/MEM_CONTEXT.h"


class PathManagerImpl
{
  public:
    char pad[0x14c0];
    PathManagerImpl();
    bool Initialize();
    bool BuildPath(NiPointer<PathingRequest> m_pPathingRequest, NiPointer<ActorPathingMessageQueue> spQueue);

    bool PathManagerImpl_TaskTryLock();
    void PathManagerImpl_TaskUnlock();
    bool GetByteAtOffsetC34();
    void DispatchPathingMessage(const Struct_004b0680& item);
};

class INISettingCollection;

extern SettingT<INISettingCollection> g_011d77cc;

struct DummyTimer
{
    void FUN_00483710();
};

class PathManager
{
  public:
    PathManagerImpl* m_pPathManagerImpl;
    PerformanceTimerManager m_kPerformanceTimerManager;
    PathManager();
    bool Initialize();
    bool BuildPath(NiPointer<PathingRequest> m_pPathingRequest, NiPointer<ActorPathingMessageQueue> spQueue,
                   bool bAsync);

    static PathManager* GetRandomGenerator();
    PathManagerImpl* Modelloader_GetReferencedThis();
    DummyTimer* FUN_00717e50();
};

extern "C" char DAT_0103a1bc[];
extern "C" char DAT_0106d624[];
extern "C" char DAT_0106d560[];
