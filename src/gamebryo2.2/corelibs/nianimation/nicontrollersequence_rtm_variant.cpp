#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiControllerSequence.h"
#include "../../../../include/NiMultiTargetTransformController.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiStringPalette.h"

// RTM variant: this function matches the game with VC9 RTM (15.00.21022.08).
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" unsigned int __cdecl strlen(const char*);
extern float DAT_01015f5c;
extern double DAT_010241b0;
void __cdecl FUN_00ec65a6(char*, unsigned int, const char*);
void __cdecl _NiFree_00aa10f0(void*);

struct RefObj
{
    virtual void V00();
    virtual void Release();
    long m_iObjectReferenceCount;
};
void __cdecl ReleaseObjectArray(void*);
extern float DAT_01096548;
extern double DAT_010231b0;
extern unsigned char DAT_01096968;
extern unsigned int DAT_01096688;
void* __cdecl _NiMalloc_00aa1070(unsigned int);
struct LegacyStream
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int version;
};
struct LegacyTag
{
    char* name;
    char* property;
    char* type;
    char* controller;
    char* interpolator;
    void LoadFromPalette(RefObj*, NiStream&);
    void ResetStrings();
};
struct LegacyController : RefObj
{
    unsigned short flags;
    unsigned short unk0a;
    float frequency;
    float phase;
    volatile float begin;
    volatile float end;
};
struct LegacyItem
{
    RefObj* interpolator;
    LegacyController* controller;
    void* blend;
    unsigned char index;
    unsigned char priority;
    unsigned short unk0e;
    void Clear()
    {
        if (interpolator)
        {
            RefObj* saved = interpolator;
            if (!InterlockedDecrement(&saved->m_iObjectReferenceCount))
                saved->Release();
            interpolator = 0;
        }
        if (controller)
        {
            LegacyController* saved = controller;
            if (!InterlockedDecrement(&saved->m_iObjectReferenceCount))
                saved->Release();
            controller = 0;
        }
        blend = 0;
        index = DAT_01096968;
        priority = 255;
    }
};
extern MemoryManager _g_memoryManager;
struct ReferenceAllocation;
struct LegacyRef
{
    LegacyController* pointer;
    ~LegacyRef() throw()
    {}
    static void* operator new[](unsigned int bytes, ReferenceAllocation*& allocation) throw();
};
struct ReferenceAllocation
{
    unsigned int count;
    LegacyRef elements[1];
};
__forceinline void* LegacyRef::operator new[](unsigned int bytes, ReferenceAllocation*& allocation) throw()
{
    allocation = (ReferenceAllocation*)_g_memoryManager.Allocate(bytes);
    return allocation;
}
static __forceinline void MakeRefs(unsigned int n, LegacyRef*& result)
{
    ReferenceAllocation* allocation;
    new (allocation) LegacyRef[n];
    if (allocation)
    {
        LegacyRef* data = allocation->elements;
        LegacyRef* current = data;
        for (int remaining = (int)n - 1; remaining >= 0; --remaining, ++current)
            current->pointer = 0;
        result = data;
    }
    else
        result = 0;
}
struct S00a352f0_Hold
{
    LegacyController* p;
    S00a352f0_Hold(LegacyController* c) : p(c)
    {
        if (p)
            InterlockedIncrement(&p->m_iObjectReferenceCount);
    }
};
struct LegacyArray
{
    unsigned int* vtable;
    LegacyRef* data;
    unsigned short capacity;
    unsigned short length;
    unsigned short populated;
    unsigned short grow;
    void SetEntry(unsigned int, const S00a352f0_Hold&);
};
struct NamesArray
{
    unsigned int* vtable;
    char** data;
    unsigned short capacity, length, populated, grow;
};
// @fnv 0x00a352f0
void NiControllerSequence::LinkObject(NiStream& stream)
{
    ::NiObject::LinkObject(stream);
    if (m_spStringPalette.m_pObject)
    {
        for (unsigned int i = 0; i < m_uiNumControlledBlocks; ++i)
            ((LegacyTag*)m_pkIDTags)[i].LoadFromPalette((RefObj*)m_spStringPalette.m_pObject, stream);
        if (m_spStringPalette.m_pObject)
        {
            RefObj* palette = (RefObj*)m_spStringPalette.m_pObject;
            if (!InterlockedDecrement(&palette->m_iObjectReferenceCount))
                palette->Release();
            m_spStringPalette.m_pObject = 0;
        }
    }
    if (((LegacyStream*)&stream)->version < 0x0a010068)
    {
        m_fFirstKeyTime = DAT_01096548;
        unsigned int n = m_uiNumControlledBlocks;
        m_fLastKeyTime = DAT_01015f5c;
        unsigned int rangeIndex = 0;
        if (rangeIndex < n)
        {
            LegacyController** sourceControllers = &((LegacyItem*)m_pInterpArray)[0].controller;
            do
            {
                LegacyController* controller = *sourceControllers;
                if (controller->begin < m_fFirstKeyTime)
                    m_fFirstKeyTime = controller->begin;
                if (controller->end > m_fLastKeyTime)
                    m_fLastKeyTime = controller->end;
                sourceControllers += sizeof(LegacyItem) / sizeof(*sourceControllers);
                ++rangeIndex;
            } while (rangeIndex < n);
        }
        if (m_fFirstKeyTime == DAT_010231b0 && m_fLastKeyTime == DAT_010241b0)
            m_fFirstKeyTime = m_fLastKeyTime = 0.0f;
        NamesArray names;
        names.capacity = (unsigned short)n;
        names.length = 0;
        if (names.capacity > 0)
            names.data = (char**)_NiMalloc_00aa1070(names.capacity * 4);
        else
            names.data = 0;
        LegacyArray controllers;
        controllers.capacity = (unsigned short)m_uiNumControlledBlocks;
        controllers.grow = 1;
        controllers.length = 0;
        controllers.populated = 0;
        if (controllers.capacity > 0)
            MakeRefs(controllers.capacity, controllers.data);
        else
            controllers.data = 0;
        controllers.vtable = &DAT_01096688;
        for (unsigned int i = 0; i < m_uiNumControlledBlocks; ++i)
        {
            {
                const char* name = ((LegacyTag*)m_pkIDTags)[i].name;
                unsigned int bytes = strlen(name) + 1;
                char* copy = (char*)_NiMalloc_00aa1070(bytes);
                FUN_00ec65a6(copy, bytes, name);
                if (i >= names.length)
                    names.length = (unsigned short)(i + 1);
                names.data[i] = copy;
            }
            ((LegacyTag*)m_pkIDTags)[i].ResetStrings();
            LegacyController* retained = ((LegacyItem*)m_pInterpArray)[i].controller;
            controllers.SetEntry(i, S00a352f0_Hold(retained));
            if (retained && !InterlockedDecrement(&retained->m_iObjectReferenceCount))
                retained->Release();
            ((LegacyItem*)m_pInterpArray)[i].Clear();
        }
        unsigned int controllerCount = controllers.length;
        for (unsigned int i = 0; i < controllerCount; ++i)
        {
            LegacyController* controller = controllers.data[i].pointer;
            if (i == 0)
            {
                m_eAnimationCycleType = (NiTimeController__CycleType)((controller->flags >> 1) & 3);
                if (m_eAnimationCycleType != 2 && m_eAnimationCycleType != 0)
                    m_eAnimationCycleType = NiTimeController__CycleType_LOOP;
                m_fFrequency = controller->frequency;
            }
            AssignControllers(names.data[i], (NiInterpController*)controller);
        }
        for (unsigned int i = 0; i < names.length; ++i)
            _NiFree_00aa10f0(names.data[i]);
        ReleaseObjectArray(controllers.data);
        _NiFree_00aa10f0(names.data);
    }
}
