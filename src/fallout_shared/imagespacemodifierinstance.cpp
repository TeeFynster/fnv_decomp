#include "layout_support.h"
#include "../../include/NiPointer.h"
#include "../../include/ImageSpaceModifierInstanceForm.h"
#include "../../include/TES.h"
#include "../../include/TESSound.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/ImageSpaceModifierInstanceDRB.h"
#include "../../include/ImageSpaceModifierInstanceDOF.h"
#include "../../include/ImageSpaceManager.h"
#include "../../include/BSAudioManager.h"
#include "../../include/BSAudio.h"
#include "../../include/ImageSpaceModifierInstance.h"
#include "../../include/ImageSpaceModifierInstanceRB.h"
#include "../../include/ImageSpaceModifierInstanceTemp.h"
#include "../../include/NiColorInterpolator.h"
#include "../../include/NiFloatInterpolator.h"
#include "../../include/NiInterpolator.h"
#include "../../include/NiKeyBasedInterpolator.h"
#include "../../include/TESImageSpaceModifier.h"
#include "../../include/GO.h"


// NiMemObjectAllocation_imagespacemodifierinstance: local type (was include/NiMemObjectAllocation.h, which had no evidence of one real class); no method of it is bound to a named game function
class NiMemObjectAllocation_imagespacemodifierinstance
{
public:
    static void* operator new(unsigned int size);
    static void operator delete(void* pointer);
    static void operator delete(void* pointer, unsigned int size);
};
#include "../../include/BSSimpleList.h"
extern TES* g_TES;
extern float DAT_0102d270;
extern float DAT_011c96fc;

// These callers use the original sound-handle return ABI and omit Play's flag.
// Cast the shared declarations to the call signatures emitted by this unit.
typedef BSSoundHandle (BSAudio::*SoundHandleByFormID)(unsigned int, unsigned int, bool);
typedef bool (BSSoundHandle::*SoundHandlePlay)();

// Returns whether the referenced image space modifier is expired, or false when no modifier is set.
// @fnv 0x005297b0
bool ImageSpaceModifierInstanceForm::IsExpired()
{
    if (m_pPreviousImageSpaceModifier)
        return m_pPreviousImageSpaceModifier->IsExpired(m_fStartTime);
    else
        return false;
}

// @fnv 0x005297e0
void ImageSpaceModifierInstanceForm::Apply()
{
    if (fWaterLevelItem > 0.0 || m_fBlendWeight > 0.0)
    {
        if (m_pPreviousImageSpaceModifier)
        {
            if (m_fStartTime < -10000.0)
                m_fStartTime = ImageSpaceModifierInstance::GetTime();
            if (m_pImageSpaceModifier)
            {
                float afTime = ImageSpaceModifierInstance::GetTime();
                float afBlendWeight = (afTime - m_fStartTime) / m_fElapsedTime;
                if (afBlendWeight < 1.0)
                {
                    TESImageSpaceModifier::BlendModifiers(afBlendWeight, m_pImageSpaceModifier,
                                                          m_pPreviousImageSpaceModifier, m_fBlendWeight,
                                                          fWaterLevelItem, m_pTargetNode, m_spTargetObject);
                }
                else
                {
                    m_pImageSpaceModifier = NULL;
                    m_fBlendWeight = 0.0f;
                    if (m_bHasBeenApplied)
                        m_pPreviousImageSpaceModifier->EvaluateInterpolators(m_fStartTime, fWaterLevelItem);
                    else
                        m_pPreviousImageSpaceModifier->Apply(m_fStartTime, fWaterLevelItem, m_spTargetObject);
                }
            }
            else
            {
                if (m_bHasBeenApplied)
                    m_pPreviousImageSpaceModifier->EvaluateInterpolators(m_fStartTime, fWaterLevelItem);
                else
                    m_pPreviousImageSpaceModifier->Apply(m_fStartTime, fWaterLevelItem, m_spTargetObject);
            }
        }
    }
}

// @fnv 0x0052a920
bool ImageSpaceModifierInstanceTemp::IsExpired()
{
    bool bExpired = false;
    if (fDuration != 0.0)
        bExpired = ((ImageSpaceModifierInstance::GetTime() - m_fStartTime) > fDuration) ? 1 : 0;
    return bExpired;
}

// Creates an ImageSpaceModifierInstanceForm for the given modifier, appends it to a list, plays its intro sound, and returns the instance.
// @fnv 0x005299a0
ImageSpaceModifierInstanceForm* ImageSpaceModifierInstanceForm::Trigger(TESImageSpaceModifier* modifier, float strength,
                                                                        NiAVObject* target)
{
    ImageSpaceModifierInstanceForm* instance = NULL;
    if (modifier)
    {
        instance = new ImageSpaceModifierInstanceForm(modifier, DAT_0102d270, strength, target);
        reinterpret_cast<BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*>(g_TES->FUN_0043b5d0())->AddTail(instance);
        if (modifier->GetIntroSound())
            ((BSAudio::GetSingleton()->*reinterpret_cast<SoundHandleByFormID>(static_cast<BSSoundHandle (BSAudio::*)(unsigned int, unsigned int, bool)>(&BSAudio::GetSoundHandleByFormID)))(
                modifier->GetIntroSound()->GetFormID(), 0x200000, false).*reinterpret_cast<SoundHandlePlay>(&BSSoundHandle::Play))();
    }
    return instance;
}


FNV_STATIC_ASSERT(sizeof(ImageSpaceModifierInstanceDRB) == 68);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, m_fRampUp) == 32);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, fStart) == 36);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, m_fRampDown) == 40);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, m_fRampDownStart) == 44);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, Center) == 48);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, fDistance) == 56);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, fImpulseRadiusSquared) == 60);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, Mode) == 64);
FNV_STATIC_ASSERT(sizeof(ImageSpaceModifierInstanceDOF) == 48);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDOF, fDistance) == 32);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDOF, fImpulseRadiusSquared) == 36);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDOF, m_fMaskConstant) == 40);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDOF, Mode) == 44);

// @fnv 0x0052a670
void ImageSpaceModifierInstanceDRB::Apply()
{
    if (fWaterLevelItem > 0.0)
    {
        if (m_fStartTime < -10000.0)
            m_fStartTime = ImageSpaceModifierInstance::GetTime();
        ImageSpaceManager* manager = ImageSpaceManager::BSShaderManager_GetImageSpaceManager();
        if (m_spTargetObject)
        {
            ((NiAVObject*)m_spTargetObject)->UpdateWorldBound();
            manager->ApplyDepthOfFieldModifier(fWaterLevelItem, Mode, m_fRampUp, fStart,
                                               ((NiAVObject*)m_spTargetObject)->GetBoundingVolume());
        }
        else
            manager->SetIfHigherPriority(fWaterLevelItem, Mode, fDistance, fImpulseRadiusSquared, m_fRampUp, fStart, Center);
    }
}

// @fnv 0x0052a060
void ImageSpaceModifierInstanceDOF::Apply()
{
    if (fWaterLevelItem > 0.0)
    {
        if (m_fStartTime < -10000.0)
            m_fStartTime = ImageSpaceModifierInstance::GetTime();
        ImageSpaceManager* manager = ImageSpaceManager::BSShaderManager_GetImageSpaceManager();
        if (m_spTargetObject)
        {
            ((NiAVObject*)m_spTargetObject)->UpdateWorldBound();
            manager->SetDistanceEffect(fWaterLevelItem, Mode, m_fMaskConstant,
                                       ((NiAVObject*)m_spTargetObject)->GetBoundingVolume());
        }
        else
            manager->SetDepthOfFieldParameters(fWaterLevelItem, Mode, m_fMaskConstant, fDistance, fImpulseRadiusSquared);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
inline unsigned int NiAtomicIncrement(unsigned int& value)
{
    return InterlockedIncrement(reinterpret_cast<volatile long*>(&value));
}
inline void NiRefObject::IncRefCount()
{
    NiAtomicIncrement(m_uiRefCount);
}
// @fnv 0x00529c90
void ImageSpaceModifierInstanceForm::Stop(TESImageSpaceModifier* modifier)
{
    if (!modifier)
        return;
    bool playedSound = false;
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* node = reinterpret_cast<BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*>(g_TES->FUN_0043b5d0());
    while (node)
    {
        ImageSpaceModifierInstance* instance = node->GetItem();
        if (instance && instance->GetInstanceForm() && instance->GetInstanceForm()->GetImageSpaceMod() == modifier)
        {
            node->Remove(instance);
            if (modifier->GetOutroSound() && !playedSound)
            {
                playedSound = true;
                ((BSAudio::GetSingleton()->*reinterpret_cast<SoundHandleByFormID>(static_cast<BSSoundHandle (BSAudio::*)(unsigned int, unsigned int, bool)>(&BSAudio::GetSoundHandleByFormID)))(
                    modifier->GetOutroSound()->GetFormID(), 0x200000, false).*reinterpret_cast<SoundHandlePlay>(&BSSoundHandle::Play))();
            }
        }
        else
            node = node->GetNext();
    }
}

// Creates a new ImageSpaceModifierInstanceDRB with the given parameters, appends it to the image space modifier list, and returns it.
// @fnv 0x0052a780
ImageSpaceModifierInstanceDRB* ImageSpaceModifierInstanceDRB::Trigger(float distance, float range,
                                                                      DepthOfFieldMode mode, float strength,
                                                                      float rampup, float start, float rampdown,
                                                                      float downstart, const NiPoint2& center,
                                                                      float duration)
{
    ImageSpaceModifierInstanceDRB* instance = new ImageSpaceModifierInstanceDRB(
        strength, DAT_0102d270, NULL, duration, mode, distance, range, rampup, start, rampdown, downstart, center);
    reinterpret_cast<BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*>(g_TES->FUN_0043b5d0())->AddTail(instance);
    return instance;
}

// Allocates an ImageSpaceModifierInstanceDOF with the given parameters, appends it to the modifier list, and returns it.
// @fnv 0x0052a150
ImageSpaceModifierInstanceDOF* ImageSpaceModifierInstanceDOF::CreateAndRegister(float distance, float range,
                                                                                DepthOfFieldMode mode, float strength,
                                                                                float mask, float duration)
{
    ImageSpaceModifierInstanceDOF* instance =
        new ImageSpaceModifierInstanceDOF(strength, DAT_0102d270, mode, distance, range, mask, NULL, duration);
    reinterpret_cast<BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*>(g_TES->FUN_0043b5d0())->AddTail(instance);
    return instance;
}

// Constructs a depth-of-field modifier instance, initializing the base temp instance and storing ramp, center, distance, range and mode values.
// @fnv 0x0052a590
ImageSpaceModifierInstanceDRB::ImageSpaceModifierInstanceDRB(float strength, float startTime, NiAVObject* target,
                                                             float duration, DepthOfFieldMode mode, float distance,
                                                             float range, float rampup, float start, float rampdown,
                                                             float downstart, const NiPoint2& center)
    : ImageSpaceModifierInstanceTemp(startTime, strength, target, duration),
      m_fRampUp(rampup), fStart(start), m_fRampDown(rampdown), m_fRampDownStart(downstart), Center(center)
{
    fDistance = distance;
    fImpulseRadiusSquared = range;
    Mode = mode;
}

// Constructs a DOF modifier instance: forwards startTime, strength, target and duration to the temp base, then stores distance, range, mask and mode.
// @fnv 0x00529fb0
ImageSpaceModifierInstanceDOF::ImageSpaceModifierInstanceDOF(float strength, float startTime, DepthOfFieldMode mode,
                                                             float distance, float range, float mask,
                                                             NiAVObject* target, float duration)
    : ImageSpaceModifierInstanceTemp(startTime, strength, target, duration)
{
    fDistance = distance;
    fImpulseRadiusSquared = range;
    m_fMaskConstant = mask;
    Mode = mode;
}

// Constructs a temporary image space modifier instance, forwarding strength, start time and target to the base and storing the duration.
// @fnv 0x0052a8b0
ImageSpaceModifierInstanceTemp::ImageSpaceModifierInstanceTemp(float startTime, float strength, NiAVObject* target,
                                                               float duration)
    : ImageSpaceModifierInstance(strength, startTime, target)
{
    fDuration = duration;
}

// @fnv 0x0052a650
void ImageSpaceModifierInstanceDOF::DestroyMembers()
{
    this->ImageSpaceModifierInstanceTemp::~ImageSpaceModifierInstanceTemp();
}

// @fnv 0x0052a040
void ImageSpaceModifierInstanceTemp::DestroyMembers()
{
    this->ImageSpaceModifierInstance::~ImageSpaceModifierInstance();
}

// @fnv 0x00529990
float ImageSpaceModifierInstance::GetTime()
{
    return DAT_011c96fc;
}

// Explicit readable equivalent of the compiler's scalar deleting destructor.
// Destructs the ImageSpaceModifierInstanceDOF and, if flags bit 0 is set, frees its memory via operator delete, returning this.
// @fnv 0x0052a010
void* ImageSpaceModifierInstanceDOF::ScalarDeletingDestructor(unsigned int flags)
{
    this->ImageSpaceModifierInstanceDOF::~ImageSpaceModifierInstanceDOF();
    if (flags & 1)
        NiMemObjectAllocation_imagespacemodifierinstance::operator delete(this, sizeof(ImageSpaceModifierInstanceDOF));
    return this;
}

// Walks the image space modifier instance list from g_TES and removes every entry matching apInstance.
// @fnv 0x005293f0
// src: XBOX_PDB 0x005293f0
void __cdecl ImageSpaceModifierInstance_Stop(ImageSpaceModifierInstance* apInstance)
{
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* pkList = reinterpret_cast<BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*>(g_TES->FUN_0043b5d0());
    while (pkList)
    {
        ImageSpaceModifierInstance* pinstance = pkList->GetItem();
        if (pinstance == apInstance)
        {
            pkList->Remove(pinstance);
        }
        else
        {
            pkList = pkList->GetNext();
        }
    }
}


// @fnv 0x00529660
void* ImageSpaceModifierInstanceForm::Destroy(unsigned int flags)
{
    this->ImageSpaceModifierInstanceForm::~ImageSpaceModifierInstanceForm();
    if (flags & 1)
        NiMemObjectAllocation_imagespacemodifierinstance::operator delete(this, 0x30);
    return this;
}


// Destructor that clears the NiPointer member by assigning null to it.
// @fnv 0x00529690
ImageSpaceModifierInstanceForm::~ImageSpaceModifierInstanceForm()
{
    m_pTargetNode = 0;
}

// @fnv 0x00529540
ImageSpaceModifierInstance::ImageSpaceModifierInstance(float afStrength, float afStartTime, NiAVObject* apTarget)
    : fWaterLevelItem(afStrength), m_spTargetObject(apTarget)
{
    m_fStartTime = afStartTime;
}

// Destructor that clears the node pointer reference by assigning null to it.
// The shared NiObject destructor calls a different game entry point.
// Retain this destructor layout until that shared base teardown is available.
class NiNode;
struct NiPtrNode
{
    NiPtrNode& operator=(NiNode*);
    ~NiPtrNode();
    NiNode* m_pObject;
};
struct FUN_00a5d3d0
{
    virtual void vfn_0();
    ~FUN_00a5d3d0();
    unsigned int m_uiRefCount;
};
struct FUN_005295c0 : public FUN_00a5d3d0
{
    bool m_bHasBeenApplied;
    float fWaterLevelItem;
    NiPtrNode m_spTargetObject;
    ~FUN_005295c0();
};
// @fnv 0x005295c0
FUN_005295c0::~FUN_005295c0()
{
    m_spTargetObject = 0;
}

struct InstanceDeleteFlags { unsigned int value; };

extern "C" const char* const g_011f36dc_arg1;

// @fnv 0x00529530
const char* const* __fastcall GetInstanceArg1Ptr(ImageSpaceModifierInstance*)
{
    return &g_011f36dc_arg1;
}

void* _delete(void*, unsigned int);

// Calls Destruct on this instance and, when flags has bit 0 set, frees it with _delete; returns this.
// @fnv 0x00529630
ImageSpaceModifierInstance* __fastcall DeleteImageSpaceModifierInstance(ImageSpaceModifierInstance* self, InstanceDeleteFlags flags)
{
    self->ImageSpaceModifierInstance::~ImageSpaceModifierInstance();
    if (flags.value & 1)
        _delete(self, 0x1c);
    return self;
}

namespace fnv_0052a620 {
extern "C" void _delete(void* p, unsigned int size);

// Destroys the object's members and, when flags has bit 0 set, frees the 0x44-byte object; returns this.
// @fnv 0x0052a620
void* __fastcall DeleteImageSpaceModifierInstanceDRB(ImageSpaceModifierInstanceDRB* self, InstanceDeleteFlags flags)
{
    reinterpret_cast<ImageSpaceModifierInstanceDOF*>(self)->DestroyMembers();
    if (flags.value & 1)
        fnv_0052a620::_delete(self, 0x44);
    return self;
}
}  // namespace fnv_0052a620

namespace fnv_0052a8f0 {
extern "C" void* __cdecl _delete(void* ptr, unsigned int size);


// Calls Destruct on the object, then frees it with _delete when flags has bit 0 set, and returns the object pointer.
// @fnv 0x0052a8f0
void* __fastcall DeleteImageSpaceModifierInstanceTemp(ImageSpaceModifierInstanceTemp* self, InstanceDeleteFlags flags)
{
    self->ImageSpaceModifierInstanceTemp::~ImageSpaceModifierInstanceTemp();
    if (flags.value & 1)
        fnv_0052a8f0::_delete(self, 0x20);
    return self;
}
}  // namespace fnv_0052a8f0

struct DebugStringBuffer { char* value; };

int _sprintf_s(char*, unsigned int, const char*, ...);
// Writes the DOF distance, range and strength values into apBuffer with _sprintf_s.
// @fnv 0x0052a240
void __fastcall FormatDofParams(ImageSpaceModifierInstanceDOF* self, DebugStringBuffer apBuffer)
{
    _sprintf_s(apBuffer.value, 0x800, "  DOF  Distance: %f  Range: %f  Str: %f", self->fDistance, self->fImpulseRadiusSquared, self->fWaterLevelItem);
}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
// @fnv 0x0052a880
void __fastcall WriteDepthRadialBlurLabel(ImageSpaceModifierInstanceDRB* self, DebugStringBuffer apBuffer)
{
    _sprintf_s(apBuffer.value, 0x800, "  Depth Radial Blur");
}

// @fnv 0x00529ea0
bool TESImageSpaceModifier::GetAnimatable()
{
    return Data.m_bOverride;
}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
extern const char str_0102d408[];
// @fnv 0x0052a530
void ImageSpaceModifierInstanceRB::vf38(char* apBuffer)
{
    _sprintf_s(apBuffer, 0x800, str_0102d408, m_fRampUp, fStart, m_fRampDown, m_fRampDownStart, fWaterLevelItem);
}

// @fnv 0x00529490
ImageSpaceModifierInstanceForm::ImageSpaceModifierInstanceForm()
    : ImageSpaceModifierInstance(0.0f, 0.0f, 0), m_pPreviousImageSpaceModifier(0), m_pImageSpaceModifier(0),
      m_fBlendWeight(0.0f), m_pTargetNode(0), m_fElapsedTime(0.0f)
{
    m_bHasBeenApplied = false;
}

// Constructs an ImageSpaceModifierInstance from a modifier, start, strength and target, initializing the modifier pointer and clearing the remaining fields.
// @fnv 0x00529700
ImageSpaceModifierInstanceForm::ImageSpaceModifierInstanceForm(TESImageSpaceModifier* apModifier, float start, float strength, NiAVObject* target)
    : ImageSpaceModifierInstance(strength, start, target), m_pPreviousImageSpaceModifier(apModifier),
      m_pImageSpaceModifier(0), m_fBlendWeight(0.0f), m_pTargetNode(0), m_fElapsedTime(0.0f)
{
    m_bHasBeenApplied = false;
}

// @fnv 0x00529df0
bool ImageSpaceModifierInstanceForm::Blend(TESImageSpaceModifier* pModifier, float m_fElapsedTime, float fWaterLevelItem,
                                      NiAVObject* pTarget)
{
    if ((this->m_pPreviousImageSpaceModifier != 0 &&
         this->m_pPreviousImageSpaceModifier->GetAnimatable()) ||
        (pModifier != 0 && pModifier->GetAnimatable()))
    {
        return false;
    }

    this->m_pImageSpaceModifier = this->m_pPreviousImageSpaceModifier;
    this->m_fBlendWeight = this->fWaterLevelItem;
    this->m_pTargetNode = this->m_spTargetObject;
    this->m_fStartTime = ImageSpaceModifierInstance::GetTime();
    this->m_fElapsedTime = m_fElapsedTime;
    this->m_pPreviousImageSpaceModifier = pModifier;
    this->fWaterLevelItem = fWaterLevelItem;
    this->m_spTargetObject = pTarget;

    return true;
}


ImageSpaceManager* BSShaderManager_GetImageSpaceManager(void);

// @fnv 0x0052a330
void ImageSpaceModifierInstanceRB::vf36()
{
    if (fWaterLevelItem > 0.0)
    {
        if (m_fStartTime < -10000.0)
            m_fStartTime = ImageSpaceModifierInstance::GetTime();

        ImageSpaceManager* pmanager = BSShaderManager_GetImageSpaceManager();

        if (m_spTargetObject.operator NiAVObject*())
        {
            reinterpret_cast<NiAVObject*>(m_spTargetObject.operator NiAVObject*())->UpdateWorldBound();

            pmanager->ApplyRadialBlurParamModifier(
                fWaterLevelItem, m_fRampUp, fStart, m_fRampDown, m_fRampDownStart,
                reinterpret_cast<NiAVObject*>(m_spTargetObject.operator NiAVObject*())->GetBoundingVolume());
        }
        else
        {
            pmanager->SetRadialBlurParameters(
                fWaterLevelItem, m_fRampUp, fStart, m_fRampDown, m_fRampDownStart, Center);
        }
    }
}

// Checks whether an instance for apModifier already exists; if not, creates one, appends it to the list, and plays the modifier's intro sound.
// @fnv 0x00529ae0
ImageSpaceModifierInstanceForm* __cdecl CreateImageSpaceModifierInstance(TESImageSpaceModifier* apModifier,
                                                                         float afStrength, NiAVObject* apTarget)
{
    bool bFound = false;
    ImageSpaceModifierInstanceForm* pInstance = 0;
    if (apModifier)
    {
        BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* pIter = reinterpret_cast<BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*>(g_TES->FUN_0043b5d0());
        while (pIter)
        {
            ImageSpaceModifierInstance* pCurrent = pIter->GetItem();
            if (pCurrent && pCurrent->GetInstanceForm() &&
                pCurrent->GetInstanceForm()->m_pPreviousImageSpaceModifier == apModifier)
            {
                bFound = true;
                break;
            }
            pIter = pIter->GetNext();
        }
        if (!bFound)
        {
            pInstance = new ImageSpaceModifierInstanceForm(apModifier, DAT_0102d270, afStrength, apTarget);
            reinterpret_cast<BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*>(g_TES->FUN_0043b5d0())->AddTail(pInstance);
            if (apModifier->GetIntroSound())
            {
                ((BSAudio::GetSingleton()->*reinterpret_cast<SoundHandleByFormID>(static_cast<BSSoundHandle (BSAudio::*)(unsigned int, unsigned int, bool)>(&BSAudio::GetSoundHandleByFormID)))(
                    apModifier->GetIntroSound()->GetFormID(), 0x200000, false).*reinterpret_cast<SoundHandlePlay>(&BSSoundHandle::Play))();
            }
        }
    }
    return pInstance;
}

extern const char DAT_0102d288[];
extern const char DAT_01020770[];
extern const char str_0102d294[];
extern const char str_0102d28c[];
extern const char str_0102d274[];
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
// @fnv 0x00529ec0
void ImageSpaceModifierInstanceForm::FormatDebugString(char* apBuffer)
{
    if (m_pImageSpaceModifier != 0)
    {
        _sprintf_s(apBuffer, 0x800, "B %s %s", (m_pPreviousImageSpaceModifier != 0) ? m_pPreviousImageSpaceModifier->GetName() : "(NULL)", m_pImageSpaceModifier->GetName());
    }
    else
    {
        _sprintf_s(apBuffer, 0x800, "%s %s Str: %1.3f ", (m_bHasBeenApplied != 0) ? DAT_0102d288 : DAT_01020770,
                   (m_pPreviousImageSpaceModifier != 0) ? m_pPreviousImageSpaceModifier->GetName() : "(NULL)", (double)fWaterLevelItem);
    }
}

// Initializes an ImageSpaceModifierInstanceTemp from the given parameters and stores the ramp-up, ramp-down, down-start and center values.
// @fnv 0x0052a290
ImageSpaceModifierInstanceRB::ImageSpaceModifierInstanceRB(float a, float b, NiAVObject* obj, float c, float afRampup, float fStart, float afRampdown,
                           float afDownStart, const NiPoint2& center)
    : ImageSpaceModifierInstanceTemp(b, a, obj, c),
      m_fRampUp(afRampup), fStart(fStart), m_fRampDown(afRampdown), m_fRampDownStart(afDownStart), Center(center)
{
}

namespace fnv_0052a440 {

// Allocates an ImageSpaceModifierInstanceRB with the given parameters, appends it to the modifier list, and returns it.
// @fnv 0x0052a440
// src: XBOX_PDB 0x0052a440
ImageSpaceModifierInstance* __cdecl ImageSpaceModifierInstanceRB_Trigger(float afStrength, float afRampup, float afStart, float afRampdown,
                                                 float afDownStart, const NiPoint2& akCenter, float afDuration)
{
    ImageSpaceModifierInstanceRB* p = new ImageSpaceModifierInstanceRB(
        afStrength, DAT_0102d270, 0, afDuration, afRampup, afStart, afRampdown, afDownStart, akCenter);
    reinterpret_cast<BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*>(g_TES->FUN_0043b5d0())->AddTail(p);
    return p;
}
}  // namespace fnv_0052a440

extern "C" void _operator_delete_sized(void* apMemory, unsigned int aSize);

// Calls DestroyMembers, then frees this via _operator_delete_sized when aFlags has bit 0 set, and returns this.
// @fnv 0x0052a300
void* __fastcall DeleteImageSpaceModifierInstanceRB(ImageSpaceModifierInstanceRB* self, InstanceDeleteFlags aFlags)
{
    reinterpret_cast<ImageSpaceModifierInstanceDOF*>(self)->DestroyMembers();
    if (aFlags.value & 1)
    {
        _operator_delete_sized(self, 0x38);
    }
    return self;
}



// The game's audio message constructs its by-value target reference inline.
class AudioTargetReference
{
  public:
    NiAVObject* m_pObject;
    __forceinline AudioTargetReference(NiAVObject* object)
    {
        m_pObject = object;
        if (m_pObject)
            reinterpret_cast<NiRefObject*>(m_pObject)->IncRefCount();
    }
    ~AudioTargetReference();
};
// The game's audio position argument is copied as three integer words.
struct AudioPosition
{
    float x, y, z;
    static const AudioPosition ZERO;
};
typedef void (BSAudioManager::*AudioMessageSender)(SOUND_MSG, unsigned int, int, void*, AudioTargetReference, AudioPosition);

// Sends SOUND_MSG_ENTER_DIALOGUE to the audio manager with no target object or position.
// @fnv 0x00ad85a0
// src: XBOX_PDB 0x00ad85a0
void BSAudio::EnterDialogue()
{
    (BSAudioManager::GetRandomGenerator().*reinterpret_cast<AudioMessageSender>(&BSAudioManager::SendSoundMessage))(
        SOUND_MSG_ENTER_DIALOGUE, 1, 0, NULL, (NiAVObject*)NULL, AudioPosition::ZERO);
}

