#pragma once

#include <cstddef>
#ifndef FNV_HAVOK_HKBASE_H   // include/havok/hkBase.h already typedefs hkBool as char
#include "hkBool.h"
#endif
#include "hkPadSpu.h"

// Havok 7.1 Common/Base/Monitor/hkMonitorStream.h: the per-thread timer/monitor command stream (m_start, m_end,
// m_capacity, m_capacityMinus16, m_isBufferAllocatedOnTheHeap) and its command records. Declarations only: a unit
// whose original inlines a body (Havok makes the accessors HK_FORCE_INLINE) defines it out of class.
// src: HAVOK_SRC (class name, nested command structs, member names, layout and method list)
class hkMonitorStream
{
public:
    // HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR
    static void* __cdecl operator new(std::size_t nbytes);
    static void __cdecl operator delete(void* p);
    static void* __cdecl operator new(std::size_t n, void* p);
    static void* __cdecl operator new[](std::size_t n, void* p);
    static void __cdecl operator delete(void* p, void* place);
    static void __cdecl operator delete[](void* p, void* place);

    static hkMonitorStream* getInstancePtr();
    static hkMonitorStream& getInstance();

    void __cdecl reset();
    void __cdecl resize(int newSize);

    char* __cdecl getStart();
    char* __cdecl getEnd();
    char* __cdecl getCapacityMinus16();
    char* __cdecl getCapacity();
    hkBool __cdecl memoryAvailable();
    int __cdecl getCurrentMonitorDataSize();
    void* __cdecl expandby(int size);
    void __cdecl setEnd(char* ptr);
    hkBool __cdecl isBufferAllocatedOnTheHeap();
    void __cdecl setStaticBuffer(char* buffer, int bufferSize);

    static void __cdecl init();
    void __cdecl quit();

    hkPadSpu<char*> m_start;              // +0x00
    hkPadSpu<char*> m_end;                // +0x04
    hkPadSpu<char*> m_capacity;           // +0x08
    hkPadSpu<char*> m_capacityMinus16;    // +0x0c
    hkBool m_isBufferAllocatedOnTheHeap;  // +0x10

    struct Command
    {
        // HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        const char* m_commandAndMonitor;
    };

    struct AddValueCommand : public Command
    {
        // HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        float m_value;
    };

    struct TimerCommand : public Command
    {
        // HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        unsigned int m_time0;
        unsigned int m_time1;

        void setTime();
    };

    struct TimerBeginListCommand : public TimerCommand
    {
        // HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        const char* m_nameOfFirstSplit;
    };

    struct TimerBeginObjectNameCommand : public TimerCommand
    {
        // HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        const char* m_objectName;
    };

    struct MemoryCommand : public Command
    {
        void* m_ptr;
        int m_sizeAndFlags;   // 1<<31 means deallocate
    };
};
