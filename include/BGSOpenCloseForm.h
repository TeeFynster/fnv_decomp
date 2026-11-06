#pragma once

class TESForm;
class TESObjectREFR;
class NiNode;
class NiControllerSequence;

class BGSOpenCloseForm
{
public:
    enum OPEN_STATE
    {
        CLOSED_UNKNOWN,
        OPEN,
        OPENING,
        CLOSED,
        CLOSING,
        OPEN_STATE_CLOSED = 0,
        OPEN_STATE_OPENING = 1,
        OPEN_STATE_OPEN = 2,
        OPEN_STATE_CLOSING = 3,
        OPEN_STATE_OPEN_LOCKED = 4,
        OPEN_STATE_CLOSED_LOCKED = 5
    };

    BGSOpenCloseForm();

    virtual void HandleOpenAnimationFinish(TESObjectREFR* itemActivated, TESObjectREFR* actionRef);
    virtual void HandleCloseFinish(TESObjectREFR* itemActivated, TESObjectREFR* actionRef);
    virtual bool GetBlockActivatesWhileOpening() const;

    static BGSOpenCloseForm* GetOpenCloseComponent(TESForm* form);
    static bool HasOpenCloseComponent(TESForm* form);
    static bool HasOpenCloseAnims(NiNode* node);
    static void HandleOpenCloseActivation(TESObjectREFR* ref, TESObjectREFR* actor, BGSOpenCloseForm* form);
    static void HandleAnimStartHavok(TESObjectREFR* ref, NiControllerSequence* sequence);
    static bool HandleAnimEndHavok(TESObjectREFR* ref, NiControllerSequence* sequence);
    static bool SetOpenState(TESObjectREFR* ref, bool open, bool immediate);
    static bool SetOpenState(void* ref, bool open, bool immediate);
    static int GetOpenState(TESObjectREFR* ref);
    static void SnapHavokTo3D(TESObjectREFR* ref);
};
