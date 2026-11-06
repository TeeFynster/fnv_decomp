
// src/bsshader/watershaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/watershaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct B6AB20Map
{
    virtual ~B6AB20Map();
};

struct B6AB20CloningProcess
{
    B6AB20CloningProcess(unsigned int uiHashSize);
    ~B6AB20CloningProcess()
    {
        delete m_pCloneMap;
        delete m_pProcessMap;
    }

    B6AB20Map* m_pCloneMap;
    B6AB20Map* m_pProcessMap;
    int m_eCloneCopyMode;
    int m_bExactType;
};

struct B6AB20Object
{
    void Process(void* pkTarget, B6AB20CloningProcess& kCloning);
    void CloneToTarget(void* pkTarget);
};

// Creates a cloning process with hash size 0x101 and runs Process on pkTarget with it.
// @fnv 0x00b6ab20
void B6AB20Object::CloneToTarget(void* pkTarget)
{
    B6AB20CloningProcess kCloning(0x101);
    Process(pkTarget, kCloning);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

struct CmObject
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount();
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct CmPointer
{
    T* m_pObject;
    CmPointer() : m_pObject(0)
    {}
    ~CmPointer();
    CmPointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (pObject != 0)
                pObject->IncRefCount();
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
        }
        return *this;
    }
};

struct CmPoint3
{
    float x, y, z;
    CmPoint3() : x(0.0f), y(0.0f), z(0.0f)
    {}
};

struct CmList
{
    void* m_pHead;
    void* m_pTail;
    unsigned int m_uiCount;
    CmList()
    {
        m_uiCount = 0;
        m_pHead = 0;
        m_pTail = 0;
    }
    ~CmList();
};

struct CmBase
{
    CmBase();
    virtual ~CmBase();
    char pad04[0x1c - 4];
    int m_i1c;
    char pad20[0x58 - 0x20];
    int m_i58;
    char pad5c[0x60 - 0x5c];
};

struct FUN_00b6abb0 : CmBase
{
    bool m_b60, m_b61, m_b62, m_b63;
    int m_i64;
    int m_i68;
    float m_f6c;
    float m_f70;
    char pad74[0x7c - 0x74];
    bool m_b7c, m_b7d, m_b7e, m_b7f, m_b80, m_b81, m_b82, m_b83;
    int m_i84;
    CmPoint3 m_kPt0;
    CmPoint3 m_kPt1;
    CmPoint3 m_kPt2;
    CmPoint3 m_kPt3;
    CmPoint3 m_kPt4;
    CmPoint3 m_kPt5;
    CmPoint3 m_kPt6;
    CmPoint3 m_kPt7;
    CmPoint3 m_kPt8;
    CmPoint3 m_kPt9;
    CmPoint3 m_kPt10;
    CmPoint3 m_kPt11;
    float m_f118;
    float m_f11c;
    float m_f120;
    float m_f124;
    CmList m_kList;
    CmPointer<CmObject> m_sp134;
    CmPointer<CmObject> m_sp138;
    CmPointer<CmObject> m_sp13c;
    CmPointer<CmObject> m_sp140;
    CmPointer<CmObject> m_sp144;
    CmPointer<CmObject> m_sp148;
    int m_i14c;

    FUN_00b6abb0();
    virtual ~FUN_00b6abb0();
};

// Initialises the object's fields to their default values: flags, floats, counters and the two integer fields set to 0x11 and 0xe.
// @fnv 0x00b6abb0
FUN_00b6abb0::FUN_00b6abb0()
{
    m_sp148 = 0;
    m_f6c = 1.0f;
    m_b7f = true;
    m_b80 = true;
    m_f70 = 0.0f;
    m_b81 = true;
    m_b60 = false;
    m_f124 = 1365.33f;
    m_b61 = false;
    m_b62 = false;
    m_b63 = false;
    m_f11c = 1.0f;
    m_i68 = 0;
    m_f120 = 1.0f;
    m_i64 = 0;
    m_b7d = false;
    m_b7e = false;
    m_b7c = false;
    m_i14c = 0;
    m_b82 = false;
    m_b83 = false;
    m_i84 = 0;
    m_i58 = 0x11;
    m_i1c = 0xe;
}
