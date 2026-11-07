// fallout/misc/garbagecollector_packet.h: declares GarbageCollector, ModelLoader, GarbageCollectorDeleteA and more
#ifndef FNV_GARBAGECOLLECTOR_PACKET_H
#define FNV_GARBAGECOLLECTOR_PACKET_H

#include "../../../include/NiAVObject.h"
#include "../../../include/NiTObjectArray.h"
#include "../../../include/NavMesh.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/BSTempEffect.h"
class GarbageCollector
{
  public:
    static void Remove(TESObjectREFR* reference);
    static NiTObjectArray<TESObjectREFR*> ms_kReferencesQueuedForRemoval;
    static NiTObjectArray<TESObjectREFR*> ObjectGarbageB;
    static void QueryCurrentThread(bool);
    static void ClearTempEffects();
    static void Update();
};
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
class ModelLoader
{
  public:
    bool FUN_00868250();
    void ModelLoader_UnlockModelMap();
};
extern NiTObjectArray<NiPointer<BSTempEffect> > g_011de828;
extern ModelLoader* g_modelLoader;
extern BSSimpleArray<NavMesh*> g_011de924, g_011de898;

class GarbageCollectorDeleteA
{
  public:
    ~GarbageCollectorDeleteA();
};
class GarbageCollectorDeleteB
{
  public:
    ~GarbageCollectorDeleteB();
};
extern NiTObjectArray<GarbageCollectorDeleteA*> g_011de808;
extern NiTObjectArray<GarbageCollectorDeleteB*> g_011de910, g_011de838;
extern NiTObjectArray<NiPointer<NiAVObject> > g_011de888, g_011de848;
template <class T>
void ForEachNavMesh(NiTObjectArray<T>* apArray, NiTObjectArray<T>* apObj);
void j_CopyArrays_V_NiTObjectArray_V_NiPointer_VNiAVObject_GarbageCollector_KAXPBV_NiTObjectArray_V_NiPointer_VNiAVObject_PAV1_Z(void*, void*);
void CopyNonNullElements(BSSimpleArray<NavMesh*>* apSource, BSSimpleArray<NavMesh*>* apDest);
class GarbageCollectorUpdateState
{
  public:
    bool MemoryLevelManager_WasLastCheckedMemLevelCloseToLow();
};
GarbageCollectorUpdateState* MemoryLevelManager_GetSingleton();
#endif
