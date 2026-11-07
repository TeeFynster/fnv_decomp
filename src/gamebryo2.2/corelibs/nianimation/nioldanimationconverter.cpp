
// src/gamebryo2.2/corelibs/nianimation/nioldanimationconverter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nioldanimationconverter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
extern char DAT_0109717c[];

struct FUN_00a5d3a0_cls
{
    void FUN_00a5d3a0();
};

struct FUN_00a5f860_cls
{
    void FUN_00a5f860(void* obj);
};

struct FUN_00a48fe0_cls
{
    void FUN_00a48fe0(unsigned int a1, unsigned int a2, unsigned int a3);
};

struct SpawnedObject
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned char m_14;
};

struct FUN_00a42460_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    void* m_18;
    unsigned int m_1c;
    void NiPoint3Interpolator_SetKeys(unsigned int a1, unsigned int a2, unsigned int a3);
};

// @fnv 0x00a42460
// src: COMMUNITY 0x00a42460
void FUN_00a42460_cls::NiPoint3Interpolator_SetKeys(unsigned int auiArg1, unsigned int auiArg2, unsigned int auiArg3)
{
    if (auiArg2 > 0)
    {
        if (m_18 == 0)
        {
            SpawnedObject* o = (SpawnedObject*)Object_DispatchCommandFour(0x18);
            if (o != 0)
            {
                ((FUN_00a5d3a0_cls*)o)->FUN_00a5d3a0();
                o->m_vtbl = (void*)&DAT_0109717c;
                o->m_08 = 0;
                o->m_0c = 0;
                o->m_10 = 0;
                o->m_14 = 0;
            }
            else
            {
                o = 0;
            }
            ((FUN_00a5f860_cls*)&m_18)->FUN_00a5f860(o);
        }
        ((FUN_00a48fe0_cls*)m_18)->FUN_00a48fe0(auiArg1, auiArg2, auiArg3);
        m_1c = 0;
    }
    else
    {
        if (m_18 != 0)
        {
            ((FUN_00a48fe0_cls*)m_18)->FUN_00a48fe0(0, 0, 0);
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

void* __cdecl Object_DispatchCommandFour(unsigned int uiSize);

struct LcRTTI
{
    const char* m_pcName;
    const LcRTTI* m_pBaseRTTI;
};

extern LcRTTI DAT_011f36ec;
extern LcRTTI DAT_011f3e50;

struct LcString
{
    const char* m_kHandle;
};
extern LcString DAT_011f49e0;

struct LcObject
{
    virtual void v00();
    virtual void DeleteThis();
    virtual const LcRTTI* GetRTTI() const;
    long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    bool IsKindOfType(const LcRTTI* pkRTTI) const
    {
        const LcRTTI* pkTmp = GetRTTI();
        while (pkTmp)
        {
            if (pkTmp == pkRTTI)
                return true;
            pkTmp = pkTmp->m_pBaseRTTI;
        }
        return false;
    }
};

inline void* operator new(unsigned int, void* pv, int)
{
    return pv;
}

struct LcKeyData
{
    char pad00[0xa];
    unsigned short m_usNumA;
    unsigned short m_usNumB;
    unsigned int GetNumA() const
    {
        return m_usNumA;
    }
    unsigned int GetNumB() const
    {
        return m_usNumB;
    }
    void FUN_00a4e0b0(void* pkKeys, unsigned int uiElementCount, int eType);
    void InitFromParams(void* pkKeys, unsigned int uiElementCount, int eType);
};

struct LcTarget;

struct LcSourceInterp : LcObject
{
    char pad08[0x2c - 8];
    LcKeyData* m_pUserData;
    unsigned int GetNumA() const
    {
        if (m_pUserData)
            return m_pUserData->GetNumA();
        return 0;
    }
    unsigned int GetNumB() const
    {
        if (m_pUserData)
            return m_pUserData->GetNumB();
        return 0;
    }
    void* FUN_00a3f990(unsigned int& uiElementCount, int& eType, unsigned char& ucSize);
    void* NiTransformInterpolator_GetScaleData(unsigned int& uiElementCount, int& eType, unsigned char& ucSize);
};

struct LcCtlr : LcObject
{
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void SetTarget(LcTarget* pkTarget);
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void Update();
    virtual void v48();
    virtual LcSourceInterp* GetInterpolator(unsigned short usIndex) const;
    virtual void SetInterpolator(void* pkInterp, unsigned short usIndex);
    void NiTransformController_NiTransformController();
};

struct LcCtlrNew : LcCtlr
{
    char pad08[0x38 - 8];
    LcCtlrNew();
};

struct LcKeys
{
    char pad[0x20];
    LcKeys(int i);
    void NiPoint3Interpolator_SetKeys(void* pkKeys, unsigned int uiElementCount, int eType);
};

struct LcKeys2
{
    char pad[0x18];
    LcKeys2(int i);
    void NiFloatInterpolator_SetKeys(void* pkKeys, unsigned int uiElementCount, int eType);
};

struct LcInterp : LcCtlr
{
    char pad08[0xc - 8];
    unsigned short m_uiObjectFlags;
    char pad0e[2];
    int m_i10;
    char pad14[0x44 - 0x14];
    LcInterp(int a, int b, int c);
    void SetLookAtName(const LcString& kName);
    void NiLookAtInterpolator_SetTranslateInterpolator(LcKeys* pkKeys);
    void NiLookAtInterpolator_SetScaleInterpolator(LcKeys2* pkKeys);
};

struct LcTarget
{
    LcCtlr* NiObjectNET_GetController(const LcRTTI* pkRTTI) const;
    void NiObjectNET_RemoveController(void* pkCtlr);
};

struct LcOld
{
    char pad00[0x2c];
    LcTarget* m_pkTarget;
    char pad30[4];
    unsigned short m_uiObjectFlags;
    char pad36[2];
    int m_i38;
};

void CopyControllerSettings(LcOld* pkOld, LcCtlr* pkCtlr);

// @fnv 0x00a42570
extern "C" void __cdecl CreateInterpolator(LcOld* pkOld)
{
    LcTarget* pkTarget = pkOld->m_pkTarget;
    bool bControllerCreated = false;
    LcCtlr* pkCtlr = pkTarget->NiObjectNET_GetController(&DAT_011f36ec);
    LcSourceInterp* pkSrc;
    if (!pkCtlr || !(pkSrc = pkCtlr->GetInterpolator(0)) || !pkSrc->IsKindOfType(&DAT_011f3e50))
    {
        bControllerCreated = true;
        pkCtlr = new (Object_DispatchCommandFour(0x38), 0) LcCtlrNew;
        CopyControllerSettings(pkOld, pkCtlr);
    }

    LcInterp* pkInterp = new (Object_DispatchCommandFour(0x44), 0) LcInterp(0, 0, 0);
    pkInterp->m_i10 = pkOld->m_i38;
    pkInterp->SetLookAtName(DAT_011f49e0);
    if (pkOld->m_uiObjectFlags & 1)
        pkInterp->m_uiObjectFlags |= 1;
    else
        pkInterp->m_uiObjectFlags &= 0xfffe;
    pkInterp->m_uiObjectFlags = (pkInterp->m_uiObjectFlags & ~6) | (pkOld->m_uiObjectFlags & 6);

    LcSourceInterp* pkData = pkCtlr->GetInterpolator(0);
    if (pkData)
    {
        pkData->IncRefCount();
        if (pkData->IsKindOfType(&DAT_011f3e50))
        {
            if (pkData->GetNumA())
            {
                LcKeys* pkKeys = new (Object_DispatchCommandFour(0x20), 0) LcKeys(0);
                unsigned int uiElementCount;
                int eType;
                unsigned char ucSize;
                void* pvKeyBuffer = pkData->FUN_00a3f990(uiElementCount, eType, ucSize);
                pkKeys->NiPoint3Interpolator_SetKeys(pvKeyBuffer, uiElementCount, eType);
                pkData->m_pUserData->FUN_00a4e0b0(0, 0, 0);
                pkInterp->NiLookAtInterpolator_SetTranslateInterpolator(pkKeys);
            }
            if (pkData->GetNumB())
            {
                LcKeys2* pkKeys = new (Object_DispatchCommandFour(0x18), 0) LcKeys2(0);
                unsigned int uiElementCount;
                int eType;
                unsigned char ucSize;
                void* pvKeyBuffer = pkData->NiTransformInterpolator_GetScaleData(uiElementCount, eType, ucSize);
                pkKeys->NiFloatInterpolator_SetKeys(pvKeyBuffer, uiElementCount, eType);
                pkData->m_pUserData->InitFromParams(0, 0, 0);
                pkInterp->NiLookAtInterpolator_SetScaleInterpolator(pkKeys);
            }
        }
    }

    pkCtlr->SetInterpolator(pkInterp, 0);
    pkInterp->Update();
    if (bControllerCreated)
        pkCtlr->SetTarget(pkTarget);
    if (pkTarget)
        pkTarget->NiObjectNET_RemoveController(pkOld);
    if (pkData)
        pkData->DecRefCount();
}

class Ctl424
{
  public:
    enum AnimType
    {
        APP_TIME,
        APP_INIT
    };
    enum CycleType
    {
        LOOP,
        REVERSE,
        CLAMP
    };

    void SetField(unsigned short uVal, unsigned short uMask, unsigned short uPos)
    {
        m_uiObjectFlags = (m_uiObjectFlags & ~uMask) | (uVal << uPos);
    }
    unsigned short GetField(unsigned short uMask, unsigned short uPos) const
    {
        return (m_uiObjectFlags & uMask) >> uPos;
    }
    void SetBit(bool bVal, unsigned short uMask)
    {
        if (bVal)
            m_uiObjectFlags |= uMask;
        else
            m_uiObjectFlags &= ~uMask;
    }
    bool GetBit(unsigned short uMask) const
    {
        return (m_uiObjectFlags & uMask) != 0;
    }

    AnimType GetAnimType() const
    {
        return (AnimType)GetField(1, 0);
    }
    void SetAnimType(AnimType eType)
    {
        SetField((unsigned short)eType, 1, 0);
        SetActive(eType == APP_TIME);
    }
    CycleType GetCycleType() const
    {
        return (CycleType)GetField(6, 1);
    }
    void SetCycleType(CycleType eType)
    {
        SetField((unsigned short)eType, 6, 1);
    }
    bool GetActive() const
    {
        return GetBit(8);
    }
    void SetActive(bool b)
    {
        SetBit(b, 8);
    }
    bool GetPlayBackwards() const
    {
        return GetBit(0x10);
    }
    void SetPlayBackwards(bool b)
    {
        SetBit(b, 0x10);
    }

    char _pad_00[8];
    unsigned short m_uiObjectFlags;
    char _pad_0a[2];
    float m_fFrequency;
    float m_fPhase;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
};

// Copies animation type, cycle type, playback direction, frequency, key times and active flag from pkSrc to pkDest.
// @fnv 0x00a424e0
void __cdecl CopyControllerSettings(Ctl424* pkSrc, Ctl424* pkDest)
{
    pkDest->SetAnimType(pkSrc->GetAnimType());
    pkDest->SetCycleType(pkSrc->GetCycleType());
    pkDest->SetPlayBackwards(pkSrc->GetPlayBackwards());
    pkDest->m_fFrequency = pkSrc->m_fFrequency;
    pkDest->m_fLoKeyTime = pkSrc->m_fLoKeyTime;
    pkDest->m_fHiKeyTime = pkSrc->m_fHiKeyTime;
    pkDest->SetActive(pkSrc->GetActive());
}
