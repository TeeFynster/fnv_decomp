// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TASKQUEUEINTERFACE_H
#define FNV_TASKQUEUEINTERFACE_H

#include <stddef.h>
class PackedTaskQueueProcessor;
class TaskQueueInterface;
#pragma pack(push, 4)
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char* buffer, unsigned int size, const char* source);
    PackedTaskQueueProcessor* m_pPrimaryTaskProcessor;    // +0x0, 4 bytes
    PackedTaskQueueProcessor* m_pSecondaryTaskProcessor;  // +0x4, 4 bytes
    PackedTaskQueueProcessor* m_pTaskQueueProcessor;      // +0x8, 4 bytes
    unsigned long m_uiTaskFlags;                          // +0xC, 4 bytes
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*()
    // unsigned long __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*(float)
    // void __cdecl TaskQueueInterface::*(int)
    // void __cdecl TaskQueueInterface::*(NiNode*, NiColor*)
    // void __cdecl TaskQueueInterface::*(unsigned int, TESObjectREFR*, ...)
    // void __cdecl TaskQueueInterface::*(TESObjectWEAP*, TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*(NiNode*)
    // void __cdecl TaskQueueInterface::*(NiNode*)
    // void __cdecl TaskQueueInterface::*(Actor*, NiAVObject*)
    // void __cdecl TaskQueueInterface::*(NiNode*)
    // void __cdecl TaskQueueInterface::*(NiNode*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*, NiNode*, bool, bool)
    // void __cdecl TaskQueueInterface::*(NiAVObject*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*, int)
    // void __cdecl TaskQueueInterface::*(NiAVObject*)
    // void __cdecl TaskQueueInterface::*(MobileObject*)
    // void __cdecl TaskQueueInterface::*(ActiveEffect*)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*, float, bool)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*, bool)
    // void __cdecl TaskQueueInterface::*(Actor*, bool, bool)
    // void __cdecl TaskQueueInterface::*(Actor*, float, float, float, float)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*, int)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*, bool, bool, bool)
    // void __cdecl TaskQueueInterface::*(Actor*, TESObjectWEAP*)
    // void __cdecl TaskQueueInterface::*(Actor*, TESBoundObject*)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(Actor*, int, int, bool, bool)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*, TESObjectREFR*, float)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*, TESObjectREFR*, float)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(Character*)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*, bool, bool)
    // void __cdecl TaskQueueInterface::*(Actor*, const NiPoint3&)
    // void __cdecl TaskQueueInterface::*(Actor*, bool)
    // void __cdecl TaskQueueInterface::*(float, const NiPoint3&)
    // void __cdecl TaskQueueInterface::*(float, const NiPoint3&)
    // void __cdecl TaskQueueInterface::*(Actor*, bool, bool)
    // void __cdecl TaskQueueInterface::*(Actor*)
    // void __cdecl TaskQueueInterface::*(Actor*)
    // void __cdecl TaskQueueInterface::*(Actor*)
    // void __cdecl TaskQueueInterface::*(ActiveEffect*)
    // void __cdecl TaskQueueInterface::*(PackedTaskQueueProcessor&, PackedTaskQueueProcessor&)
    // void __cdecl TaskQueueInterface::*()
    // TaskQueueInterface* __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*(const BSPackedTask&)
    // void __cdecl TaskQueueInterface::*()
    // bool __cdecl TaskQueueInterface::*()
    // bool __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*(bool)
    // TaskQueueInterface
    // PackedTaskQueueProcessor* __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*(const BSPackedTask&)
    // void* __cdecl TaskQueueInterface::*(unsigned int)
};
#pragma pack(pop)
typedef char TaskQueueInterfaceSizeCheck[sizeof(TaskQueueInterface) == 16 ? 1 : -1];
typedef char TaskQueueInterfacePrimaryTaskProcessorOffsetCheck[offsetof(TaskQueueInterface, m_pPrimaryTaskProcessor) == 0 ? 1 : -1];
typedef char TaskQueueInterfaceSecondaryTaskProcessorOffsetCheck[offsetof(TaskQueueInterface, m_pSecondaryTaskProcessor) == 4 ? 1 : -1];
typedef char TaskQueueInterfaceTaskQueueProcessorOffsetCheck[offsetof(TaskQueueInterface, m_pTaskQueueProcessor) == 8 ? 1 : -1];
typedef char TaskQueueInterfaceTaskFlagsOffsetCheck[offsetof(TaskQueueInterface, m_uiTaskFlags) == 12 ? 1 : -1];
#endif
