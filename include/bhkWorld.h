#pragma once

#include "bhkSerializable.h"

class NiAVObject;
class TESObjectREFR;
class WorldExt;

class bhkWorld : public bhkSerializable
{
public:
    virtual ~bhkWorld();

    virtual void* v37(); // EAX pointer: bhkSerializable 0x00c87a40, bhkWorld 0x00d47a30
    virtual void vf49();
    virtual bool vf50(TESObjectREFR* refr);
    virtual void vf51();
    virtual void AddObject(NiAVObject* object, bool a, bool b, int c, bool d);
    virtual void vf53();
    virtual void vf54();

    WorldExt* GetHkpWorld() throw();
    void AddObject(NiAVObject* object, bool a, bool b, int c, int d);
    void ProcessConstraints() throw();
    void ReleaseBodies();
    void ClearReferences();
    void ClearEntries();
    void FlushEntries() throw();
    void SetProcessEnabled(int arg) throw();
    void SetWorldActive(bool arg);
    void RefreshWorld();
    bool StepSimulation();
    static bool __cdecl QPickCountOverride();

    void bhkWorld_SaveSnapshot(const char* name);
    void bhkWorld_AddEntities(void* p, unsigned int count) throw();
    void bhkWorld_AddBatchedActions() throw();
    void bhkWorld_UpdateActions(float f) throw();
    void bhkWorld_ScaleSolverInfo() throw();
    void bhkWorld_UpdateListeners(float f) throw();
    void bhkWorld_UpdateDebugger() throw();
    void bhkWorld_StopBatchingAdds(bool);
    void bhkWorld_StartBatchingRemovals();
    void bhkWorld_StartBatchingAdds();

    unsigned int unk0C;
    void* pDebugger;
    bool bStateChanged;
    bool bEnabled;
    bool m_bFlagAt16;
    char _pdbpad_17[1];
    unsigned int m_uiValueAt18;
    unsigned int m_uiReferenceCount;
    void* pTrapListener;
    void* m_pObjectAt24;
    void* m_pObjectAt28;
    void* m_pObjectAt2C;
    unsigned int m_uiValueAt30;
    void* m_pObjectAt34;
    unsigned int m_uiValueAt38;
    void* m_pObjectAt3C;
    unsigned int m_uiValueAt40;
    void* m_pObjectAt44;
    unsigned int m_uiValueAt48;
    void* m_pObjectAt4C;
    unsigned int m_uiValueAt50;
    char _pdbpad_54[12];
    char Origin[16];
    char m_achDataAt70[12];
    char m_achDataAt7C[12];
    float m_fValueAt88;
    float m_fValueAt8C;
    char ActionEntryList[8];
    char _pdbpad_98[8];
};
