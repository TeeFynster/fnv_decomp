#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/MobileObject.h"
#include "../../../include/PathingAvoidNode.h"
#include "../../../include/PathingAvoidNodeArray.h"
#include "../../../include/PathingRequestClosePoint.h"
#include "../../../include/PathingRequestCoveredMove.h"
#include "../../../include/PathingRequestHide.h"
#include "../../../include/PathingRequestFlee.h"
#include "../../../include/PathingRequestLOS.h"
#include "../../../include/PathingRequestOptimalLocation.h"
#ifndef PATHINGREQUEST_DECLS_H
#define PATHINGREQUEST_DECLS_H

class Actor;
class BGSLoadFormBuffer;
class TESForm;
class TESObjectREFR;
class TESPackage;
class PlayerCharacter;
class BGSLoadFormBufferView
{
  public:
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
};
class Calendar
{
  public:
    unsigned int GetDaysPassed();
};
extern PlayerCharacter* g_thePlayer;
class PathingLocationLoadView
{
  public:
    virtual void vfn_0();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
template <class T, unsigned int N> class BSSimpleArray;
extern unsigned char DAT_0106d1d8;
extern unsigned char DAT_0106d1e4;
// PathingAvoidNodeArray as this unit's constructor (0x006e3850), destructor (0x006e38b0) and deleting destructor
// (0x006e3880) build it: 24 raw bytes whose two vtable pointers the constructor stores by hand after FUN_006e3960;
// the shared PathingAvoidNodeArray (a BSSimpleArrayRefCounted with virtuals) would install them itself.
class PathingAvoidNodeArrayStorage
{
  public:
    char data[24];
    PathingAvoidNodeArrayStorage();
    ~PathingAvoidNodeArrayStorage();
    PathingAvoidNodeArrayStorage* Destroy(unsigned int);
    void FUN_006e3960();
    void FUN_006e39d0();

    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void SetSize(unsigned int, bool);
    PathingAvoidNode* BSSimpleArray_PathingAvoidNode_1024_GetAt(unsigned int);
};

class PathingAvoidNodeArrayDestructionView
{
  public:
    void Destruct();
};
class PathingAvoidPointerView
{
  public:
    PathingAvoidPointerView& Assign(PathingAvoidNodeArray*);
    PathingAvoidNodeArray* Get();
};

int Warning(const char*, ...);
class FUN_006e4080 : public PathingRequest
{
  public:
    char extra[60];
    FUN_006e4080();
};
class FUN_006e4a50 : public PathingRequest
{
  public:
    char extra[92];
    FUN_006e4a50();
};
extern const float runtimeFloatSettingDefault65;
extern const NiPoint3 pathingrequestZero;
#endif
