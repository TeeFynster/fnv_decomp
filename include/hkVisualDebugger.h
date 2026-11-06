#pragma once

#include "hkReferencedObject.h"
#include "hkBool.h"
#include "hkStringPtr.h"

class hkClass;
class hkSocket;
class hkStreamReader;
class hkStreamWriter;
class hkProcessContext;
class hkServerProcessHandler;
class hkVtableClassRegistry;

struct hkVisualDebuggerClient
{
    hkSocket* m_socket;
    hkServerProcessHandler* m_processHandler;
};

struct hkVisualDebuggerTrackedObject
{
    void* m_ptr;
    const hkClass* m_class;
    unsigned long m_tag;
};

typedef void(__cdecl* hkVisualDebuggerTrackedObjectCallback)(void* ptr, const hkClass* klass, hkBool wasAdded,
                                                              unsigned long tagId, void* userCallbackHandle);

class hkStopwatch
{
public:
    hkStopwatch(const char* name = 0) : m_name(name)
    {
        reset();
    }
    void reset()
    {
        m_ticks_at_start = 0;
        m_ticks_total = 0;
        m_ticks_at_split = 0;
        m_split_total = 0;
        m_running_flag = false;
        m_num_timings = 0;
    }
    void start()
    {
        m_running_flag = true;
        m_ticks_at_start = getTickCounter();
        m_ticks_at_split = m_ticks_at_start;
    }
    void stop()
    {
        if (m_running_flag)
        {
            m_running_flag = false;
            unsigned __int64 ticks_now = getTickCounter();
            m_ticks_total += ticks_now - m_ticks_at_start;
            m_split_total += ticks_now - m_ticks_at_split;
            ++m_num_timings;
        }
    }
    static unsigned __int64 __cdecl getTickCounter();

    unsigned __int64 m_ticks_at_start;
    unsigned __int64 m_ticks_total;
    unsigned __int64 m_ticks_at_split;
    unsigned __int64 m_split_total;
    bool m_running_flag;
    int m_num_timings;
    const char* m_name;
};

class hkVisualDebugger : public hkReferencedObject
{
public:
    template <typename T> class Array
    {
    public:
        Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000)
        {}
        ~Array() throw();
        Array& operator=(const Array& kFirst) throw();
        int getSize() const
        {
            return m_size;
        }
        int getCapacity() const
        {
            return m_capacityAndFlags & 0x3fffffff;
        }
        T& operator[](int i)
        {
            return m_data[i];
        }
        const T& operator[](int i) const
        {
            return m_data[i];
        }

        T* m_data;
        int m_size;
        int m_capacityAndFlags;
    };

    hkVisualDebugger(const Array<hkProcessContext*>& kContexts, const hkVtableClassRegistry* pClassReg = 0) throw();
    virtual ~hkVisualDebugger() throw();
    virtual void step(float fFrameTimeInMs = 0);
    virtual void pollForNewClients();

    void FUN_00cd1970();
    hkVisualDebugger* FUN_00cd1e40(unsigned int uFlags);
    void serve(int iListenPort);
    void capture(const char* sCaptureFilename) throw();
    void endCapture();
    void shutdown() throw();
    void addDefaultProcess(const char* sProcessName) throw();
    void removeDefaultProcess(const char* sProcessName);
    void addTrackedObject(void* pObj, const hkClass* pKlass, const char* sGroup, unsigned long uTagId);
    void removeTrackedObject(void* pObj);
    void addTrackedObjectCallback(hkVisualDebuggerTrackedObjectCallback kCallback, void* pUserHandle);
    void removeTrackedObjectCallback(hkVisualDebuggerTrackedObjectCallback kCallback);

protected:
    void createClient(hkSocket* pSocket, hkStreamReader* pReader, hkStreamWriter* pWriter) throw();
    void deleteClient(int iIndex);
    void writeStep(int iIndex, float fTime);

    // member names follow the Havok headers (offsets from the exe's constructor)
    hkSocket* m_server;  // src: HAVOK_SRC (members below)
    bool m_suppressPollForNewClients;
    Array<hkVisualDebuggerClient> m_clients;
    Array<hkProcessContext*> m_contexts;
    Array<hkVisualDebuggerTrackedObject> m_trackedObjects;
    Array<hkVisualDebuggerTrackedObjectCallback> m_trackCallbacks;
    Array<void*> m_trackCallbackHandles;
    const hkVtableClassRegistry* m_classReg;
    Array<hkStringPtr> m_defaultProcesses;
    hkBool m_amTimingFrame;
    hkStopwatch m_frameTimer;
};
