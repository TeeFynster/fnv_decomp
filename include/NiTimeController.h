#pragma once

#include "NiObject.h"
#include "NiAVObject.h"

class NiObjectNET;
class NiUpdateData;
class NiStreamR;
class Mesh53;
class NiControllerSequence;
class NiInterpControllerTriple;

class NiTimeController : public NiObject
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
        CLAMP,
        MAX_CYCLE_TYPES
    };

    enum
    {
        ANIMTYPE_MASK = 0x0001,
        CYCLETYPE_MASK = 0x0006,
        ACTIVE_MASK = 0x0008,
        DIRECTION_MASK = 0x0010,
        MANAGERCONTROLLED_MASK = 0x0020,
        COMPUTESCALEDTIME_MASK = 0x0040,
        FORCEUDPATE_MASK = 0x0080
    };

    NiTimeController();
    virtual ~NiTimeController();
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);

    virtual void Start(float time);
    virtual void Stop();
    virtual void Update(NiUpdateData& update);
    virtual void SetTarget(NiObjectNET* target);
    virtual void SetGeometry(Mesh53* geometry);
    virtual void Unk_28();
    virtual float ComputeScaledTime(float time);
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();

    void SetFrequency(float frequency);
    float GetFrequency() const;
    void SetSequenceTime(float phase);
    float GetPhase() const;
    void SetBeginKeyTime(float time);
    float GetBeginKeyTime() const;
    void SetEndKeyTime(float time);
    float GetEndKeyTime() const;
    bool IsTransformController() const;
    bool IsVertexController() const;
    bool IsGeometryController() const;
    bool IsTransformInterpolator() const;
    void ResetControllerState();
    void ResetControllerState() const;
    void ResetModifierData();
    void SetGeometry(void* geometry);
    bool Unk_27();
    bool AdvanceController(float time);
    void SetControllerActive(bool active);
    void SetComputeScaledTime(bool computeScaledTime);
    bool GetManagerControlled() const;
    NiTimeController* GetNext() const;
    void Reset();
    void AddKey(const NiInterpControllerTriple& key);
    void EvaluateAndApplyOutput(float& parameter);
    void Update(float time);
    void Update(const NiUpdateData& update);
    static void __cdecl UpdateControllersForTarget(NiObjectNET* target);
    template <class Target>
    static void __cdecl UpdateControllersForTarget(Target* target);

    int FUN_00441110();
    NiControllerSequence* NiControllerManager_GetSequenceByName(const NiFixedString& name);
    bool __thiscall DontDoUpdate(float value);
    void BSShaderPPLightingProperty_SetLandscapeTextureSet(int value, void* data);
    void BSShaderPPLightingProperty_SetLandscapeSpecularExponents(char, char, char, char, char, char, char, int, int, int);
    void BSShaderProperty_FreeRenderPasses();

    union
    {
        unsigned short m_uiObjectFlags;
        unsigned short flags;
    };
    union
    {
        unsigned char unk0A[2];
        unsigned short unk0a;
    };
    union
    {
        float m_fFrequency;
        float frequency;
    };
    union
    {
        float m_fPhase;
        float phase;
    };
    union
    {
        float m_fLoKeyTime;
        float startTime;
    };
    union
    {
        float m_fHiKeyTime;
        float stopTime;
    };
    float m_fStartTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fControllerTime;
    NiObjectNET* m_pkTarget;
    NiPointer<NiTimeController> m_spNextController;
};
