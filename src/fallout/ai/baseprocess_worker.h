// fallout/ai/baseprocess_worker.h: local call declarations for process helpers
#ifndef FNV_BASEPROCESS_WORKER_H
#define FNV_BASEPROCESS_WORKER_H

class ActorPackageCall
{
  public:
    void SetPackageAndTarget(TESPackage*, TESObjectREFR*);
    void LoadGame(BGSLoadFormBuffer*);
    void ApplyLoadBuffer(BGSLoadFormBuffer*);
    void FUN_008c6970(BGSLoadFormBuffer*);
    void FUN_008c6c80(BGSLoadFormBuffer*);
};
class CachedValuesCall
{
  public:
    void ClearField44();
};
class GuardActorPackageDataCall
{
  public:
    void SetReferenceTarget(TESObjectREFR*);
};
class ActorPackageDataVirtualCall
{
  public:
    virtual void Slot0() = 0;
    virtual void SetReferenceTarget(TESObjectREFR*) = 0;
};

class MiddleHighProcessCall
{
  public:
    void CopyProcessDataFrom(MiddleHighProcessCall*);
};
class CopyCall00914c60
{
  public:
    void MiddleHighProcess_MiddleHighCopy(CopyCall00914c60*);
};
class CachedValuesCopyCall
{
  public:
    void Copy(CachedValuesCopyCall*);
};
class LowProcessCachedCopyCall
{
  public:
    void HandlePackageChange(LowProcessCachedCopyCall*);
};
extern char DAT_0118a6b8;
extern char DAT_0118a6d4;
extern char DAT_0118c64c;
extern char DAT_011a3668;
extern char DAT_011a364c;
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
#endif
