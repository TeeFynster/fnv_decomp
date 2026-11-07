
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/BSMultiBound.h"
#include "../../../../include/GO.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiStream.h"

// The shared header lacks declarations for these entry points. Keep their
// thiscall implementations here, inheriting all layout from the checked class.
class BSMultiBoundStreamOperations : public BSMultiBound
{
public:
    void LoadBinary(NiStream* stream);
    void LinkObject(NiStream& stream);
    void RegisterShape(NiStream& stream);
    bool IsSameBound(BSMultiBound* other);
    void* Delete(unsigned int flags);
    const NiRTTI* GetRTTI() const;
    BSMultiBound* CloneBound(int context);
    void CopyBound(BSMultiBound* target, int context);
    void* GetViewerEntries(int argument);
    void* AppendCameraPathEntries(int argument);
};

// @fnv 0x00c36040
void BSMultiBoundStreamOperations::LoadBinary(NiStream* stream)
{
    NiObject::LoadBinary(*stream);
    stream->ResetStreamState();
}

// @fnv 0x00c36070
void BSMultiBoundStreamOperations::LinkObject(NiStream& stream)
{
    int _u1;
    int _u2;
    NiObject::LinkObject(stream);
    reinterpret_cast<GO&>(pShape) = stream.GetLoadedObject();
}

// @fnv 0x00c36220
void* BSMultiBoundStreamOperations::GetViewerEntries(int arg)
{
    return AppendCameraPathEntries(arg);
}

void _delete(void*, unsigned int);
// @fnv 0x00c36290
void* BSMultiBoundStreamOperations::Delete(unsigned int flags)
{
    BSMultiBound::~BSMultiBound();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct S_00c362c0
{
    NiObject* ptr;
    void UpdateFields_00c362c0();
};
// @fnv 0x00c362c0
// src: GUESS 0x00c362c0 (confidence: low)
void S_00c362c0::UpdateFields_00c362c0()
{
    NiObject* p;
    if (ptr)
    {
        p = ptr;
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount)) == 0)
            p->DeleteThis();
    }
}

extern "C" void* g_01202810;

// @fnv 0x00c36300
const NiRTTI* BSMultiBoundStreamOperations::GetRTTI() const
{
    return reinterpret_cast<const NiRTTI*>(&g_01202810);
}

// @fnv 0x00c35f50
BSMultiBound* BSMultiBoundStreamOperations::CloneBound(int a)
{
    BSMultiBound* t = new BSMultiBound;
    CopyBound(t, a);
    return t;
}

extern int _data_011c16bc;

// @fnv 0x00c361a0
// src: EXE 0x00c361a0
BSMultiBound* BSMultiBound_CreateObject()
{
    return new BSMultiBound;
}

// @fnv 0x00c36130
bool BSMultiBoundStreamOperations::IsSameBound(BSMultiBound* arg)
{
    bool result = IsSameAs(arg);
    BSMultiBound* other = arg;
    {
        int a;
        int b;
        if ((bool)(int)(pShape.m_pObject == other->pShape.m_pObject) &&
            ((a = m_uiBoundFlags) == (b = other->m_uiBoundFlags)))
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    return result;
}

// @fnv 0x00c360f0
void BSMultiBoundStreamOperations::RegisterShape(NiStream& s)
{
    NiObject::LinkObject(s);
    const void* object = pShape.m_pObject;
    s.SaveLinkID(reinterpret_cast<const NiObject*>(object));
}
