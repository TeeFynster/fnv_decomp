#include "../../include/NiTMapItem.h"
// bsmenu/tile3d.cpp: Tile3D, Tile3DCalc, AnimTile, Tile3dInterfaceView and more (12 functions)

#include "../../include/BSStringT.h"
#include "../../include/NiMemObject.h"
#include <string.h>
#include "../../include/GameTimerRecord.h"

#include "../../include/NiColorA.h"
#include "../../include/TileShaderProperty.h"

#include "../../include/DummyPointerMap.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiControllerSequence.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiNode.h"
#include "../../include/NiObjectNET.h"
#include "../../include/Tile.h"

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}
template <class T> inline T* NiPointer<T>::operator->() const
{
    T* result = m_pObject;
    return result;
}

template <class T> inline NiPointer<T>::NiPointer(T* p)
{
    m_pObject = p;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* p)
{
    if (m_pObject != p)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = p;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

// Keep array operations local: the approved NiNode.h declares them on NiTArray,
// while the working header declares them on NiTObjectArray.
template <class T> struct Tile3DArrayAccess : NiTObjectArray<T>
{
    T& GetAt(unsigned int i)
    {
        return this->m_pBase[i];
    }
    void RemoveAll()
    {
        for (unsigned short i = 0; i < this->m_usSize; i++)
            this->m_pBase[i] = T(0);
        this->m_usSize = 0;
        this->m_usESize = 0;
    }
};

#include "../../include/Tile3D.h"

// Handles field value 0xFC4 by clearing the string, then returns null.
// @fnv 0x00a20c50
Tile* Tile3D::SetTraitValue(int uiValueID, float fFloatValue, const char* pcStrValue)
{
    char localFrame[0x1c];
    if (uiValueID == 0xFC4)
        m_kName.Set("", 0);
    return 0;
}

int* __fastcall _ref_006815c0(void* p);
void* __fastcall _ref_00726070(void* p);
void(__thiscall* const pFUN_0078bb60)(void*, int) = 0;
struct DummyClass_0078a9f0;
void __fastcall FUN_0078bb60(DummyClass_0078a9f0* pThis);

typedef void(__thiscall* FUN_0078bb60_t)(void*, int);

// @fnv 0x0078a9f0
void __fastcall FUN_0078a9f0(char* pThis)
{
    *(int*)(pThis + 0x1dc) = *_ref_006815c0(*(void**)(pThis + 0x1d8));
    *(void**)(pThis + 0x1d8) = _ref_00726070(*(void**)(pThis + 0x1d8));
    if (*(void**)(pThis + 0x1d8) == 0)
    {
        *(void**)(pThis + 0x1d8) = pThis + 0x1d0;
    }
    if (*(void**)(pThis + 0x1d8) != 0)
    {
        int item = *_ref_006815c0(*(void**)(pThis + 0x1d8));
        if (item != 0)
        {
            ((void(__thiscall*)(void*, int))FUN_0078bb60)(pThis, *(int*)(pThis + 0x1dc));
        }
    }
}

extern GameTimerRecord DAT_011f3560;
__declspec(dllimport) unsigned long __stdcall GetTickCount();

struct FUN_00a20720_shell : public Tile3D
{
    void InitTile(Tile* apParent, const char* apName, Tile* apReplacedTile);
};
// @fnv 0x00a20720
void FUN_00a20720_shell::InitTile(Tile* apParent, const char* apName, Tile* apReplacedTile)
{
    Tile::Init(apParent, apName, apReplacedTile);
    this->Set(0xff5, 255.0f, true);
    this->Set(0xfb2, 255.0f, true);
    this->Set(0xfb3, 255.0f, true);
    this->Set(0xfb4, 255.0f, true);
    this->Set(0xfa9, 255.0f, true);
    this->Set(0xfa3, 1.0f, true);
    this->SetTileType(3);
    DAT_011f3560.Enable();
    DAT_011f3560.Update(GetTickCount());
}

struct NiTimeController;
struct NiRTTI;
extern NiRTTI DAT_011f36ac;

struct FUN_00a20c80_shell : public Tile3D
{
    bool AttachController(NiAVObject* obj);
};
// Looks up a NiTimeController of type DAT_011f36ac on obj; if found, stores it at this+0x38 and returns true, otherwise returns false.
// @fnv 0x00a20c80
bool FUN_00a20c80_shell::AttachController(NiAVObject* apObject)
{
    NiTimeController* ctrl = apObject->GetController(&DAT_011f36ac);
    if (ctrl)
    {
        *(NiTimeController**)((char*)this + 0x38) = ctrl;
        return true;
    }
    return false;
}

struct PropHelper
{
    void* GetProperty(unsigned int);
};

struct FUN_00a21570_shell : public Tile3D
{
    void ApplyAlphaToChildren(NiNode* apNode, float afAlpha, const NiColorA* apTextColor);
};

// @fnv 0x00a21570
void FUN_00a21570_shell::ApplyAlphaToChildren(NiNode* apNode, float afAlpha, const NiColorA* apColor)
{
    if (!apNode)
        return;
    for (unsigned int ui = 0; ui < *(unsigned short*)((char*)apNode + 0xa6); ui++)
    {
        NiAVObject* pchild;
        {
            PropHelper* pgeom;
            {
                void* pprop;
                {
                    char* ptsp;
                    {
                        NiAVObject** pp = &(*(NiAVObject***)((char*)apNode + 0xa0))[ui];
                        {
                            NiAVObject* p = *pp;
                            pchild = p;
                        }
                    }
                    if (pchild)
                    {
                        SetAlphaAndOverlayColor(pchild->IsSceneNode(), afAlpha, (NiColorAlpha*)apColor);
                        pgeom = (PropHelper*)pchild->IsGeometry();
                        if (pgeom)
                        {
                            pprop = pgeom->GetProperty(3);
                            ptsp = (char*)pprop;
                            *(float*)(ptsp + 0x78) = afAlpha;
                            *(NiColorA*)(ptsp + 0x68) = *apColor;
                        }
                    }
                }
            }
        }
    }
}

void __fastcall FUN_004afc80(void*);
void __fastcall TrimTrailingNullPointers(void*);

struct FUN_00a20ba0_X
{
    void RemovePropertyRecursive(char* pTarget);
};
// @fnv 0x00a20ba0
void FUN_00a20ba0_X::RemovePropertyRecursive(char* pTarget)
{
    unsigned int a;
    void* pobj;
    char* val;
    int unused[5];
    ((NiAVObject*)pTarget)->RemoveProperty(2);
    FUN_004afc80(pTarget + 0x9c);
    TrimTrailingNullPointers(pTarget + 0x9c);
    for (a = 0; a < *(unsigned short*)(pTarget + 0xa8); a++)
    {
        {
            void** tB = &(*(void***)(pTarget + 0xa0))[a];
            void* tA = *tB;
            pobj = tA;
        }
        if (pobj)
        {
            ((NiAVObject*)pobj)->RemoveProperty(2);
            val = (char*)((NiAVObject*)pobj)->IsSceneNode();
            if (val)
                RemovePropertyRecursive(val);
        }
    }
}

extern char* EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

inline NiFixedString::operator const char*() const
{
    return NiGlobalStringTable::GetString(m_kHandle);
}
inline int NiControllerSequence::GetState()
{
    return m_eAnimationState;
}
inline void NiControllerManager::SetBit(bool bVal, unsigned short uMask)
{
    if (bVal)
        m_uiObjectFlags |= uMask;
    else
        m_uiObjectFlags &= ~uMask;
}
inline NiControllerSequence* NiControllerManager::FindSequenceByName(const NiFixedString& kName)
{
    NiControllerSequence* pkSequence;
    if (((DummyPointerMap*)&m_kObjectMap)->GetAt((unsigned int)(const char*)kName, (unsigned int&)pkSequence))
        return pkSequence;
    return 0;
}
inline bool NiControllerManager::StopSequence(NiControllerSequence* pkSequence, float fEaseOutTime)
{
    return pkSequence->Deactivate(fEaseOutTime, false);
}
inline bool NiControllerManager::ActivateControllerSequence(NiControllerSequence* pkSequence, int iPriority, bool bStartOver,
                                                          float fWeight, float fEaseInTime, NiControllerSequence* pkTimeSyncSeq)
{
    return pkSequence->Activate((char)iPriority, bStartOver, fWeight, fEaseInTime, pkTimeSyncSeq, false);
}


inline bool DummyPointerMap::GetAt(unsigned int key, unsigned int& val)
{
    unsigned int uiIndex = ((unsigned int (__thiscall*)(DummyPointerMap*, unsigned int))(*(void***)this)[1])(this, key);
    NiTMapItem<unsigned int, unsigned int>* pkItem = ((NiTMapItem<unsigned int, unsigned int>**)c)[uiIndex];
    while (pkItem)
    {
        if (((bool (__thiscall*)(DummyPointerMap*, unsigned int, unsigned int))(*(void***)this)[2])(this, pkItem->m_key, key))
        {
            val = pkItem->m_val;
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }
    return false;
}

struct Dummy_00a20ed0
{
    void UpdateAnimation(float, int);
};

struct FUN_00a20cc0_t : public Tile3D
{
    NiNode* GetNode()
    {
        return *(NiNode**)((char*)this + 0x2c);
    }
    NiControllerManager* Mgr()
    {
        return (NiControllerManager*)m_pParent;
    }
    bool FUN_00a20cc0(const char* apSequenceName);
};
// Looks up a controller sequence by name and activates it, deactivating the current sequence first, then sets a manager flag and stores the new sequence.
// @fnv 0x00a20cc0
bool FUN_00a20cc0_t::FUN_00a20cc0(const char* apSequenceName)
{
    if (!GetNode() || !m_pParent || !apSequenceName)
        return false;
    NiControllerSequence* pseq = ((NiControllerManager*)m_pParent)->FindSequenceByName(NiFixedString(apSequenceName));
    if (pseq)
    {
        bool bActivated = false;
        if (m_pChildTile)
        {
            if (((NiControllerSequence*)m_pChildTile)->GetState() == 1)
                ((Dummy_00a20ed0*)this)->UpdateAnimation(1.0f, 1);
            ((NiControllerManager*)m_pParent)->StopSequence((NiControllerSequence*)m_pChildTile);
        }
        if (!bActivated)
        {
            if (pseq->GetState() != 0)
                ((NiControllerManager*)m_pParent)->StopSequence(pseq);
            bActivated = ((NiControllerManager*)m_pParent)->ActivateControllerSequence(pseq);
        }
        if (bActivated)
        {
            ((NiControllerManager*)m_pParent)->SetBit(true, 8);
            m_pChildTile = pseq;
            return true;
        }
    }
    return false;
}

template <class T> inline BSStringT<T>::~BSStringT()
{
    Set(0, 0);
}



void __cdecl FUN_00707640(unsigned int value);
void __fastcall FUN_009ff690(void* pThis);

struct FUN_00a20650_pad
{
    unsigned int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38;
};

__forceinline bool Tile3D::TestFlag(unsigned int mask) const
{
    return (*(const unsigned int*)((const char*)this + 0x30) & mask) != 0;
}

// @fnv 0x00a20650
Tile3D::~Tile3D()
{
    FUN_00a20650_pad unkPad;
    unsigned int unkX;
    unsigned int uiName;
    if (TestFlag(0x20000))
    {
        uiName = *(unsigned int*)((char*)this + 0x48);
        FUN_00707640(uiName);
    }
    if (!TestFlag(0x2000))
    {
        FUN_009ff690(this);
    }
}

template <class T> struct NiPtrX
{
    T* m_pObject;
    NiPtrX& operator=(T* p);
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct Tile__Extra : NiExtraData
{
    Tile* pTile;
    NiNode* pNode;
    Tile__Extra(Tile* tile, NiNode* node)
    {
        pTile = tile;
        pNode = node;
        SetName("Tileptr");
    }
    static void* operator new(unsigned int size);
};

NiNode* __fastcall GetTileNiNode(Tile* tile);
NiNode* FUN_00706d30();

const char* __cdecl ModelRoot();
NiNode* __cdecl LoadTileModel(const char*, bool*);
NiNode* __cdecl CopyTileModel(NiNode*);
void __cdecl FinishTileModel(int);
void __cdecl FlushTileModel();

struct Tile3DCalc
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Tile* parent;
    NiPtrX<NiNode> node;

    Tile* GetParent()
    {
        return parent;
    }
    unsigned int flags;
    int unk34, unk38, unk3c, unk40, unk44;
    BSStringT<char> filename;
    const char* GetString(int);
    bool InitControllers(NiNode*);
    void CreateMenuBackgroundGeometry(NiNode*);
    void InitProperties(NiNode*);
    void SetValue(int, float, bool);
    bool GetBool(int);
    void UpdateValue(int);
    void LoadTile()
    {
        const char* name = GetString(0xfcc);
        if (!name)
            return;
        if (strstr(name, "\\Data"))
            filename.PrintfString("%s", name);
        else
            filename.PrintfString("%s\\%s", ModelRoot(), name);
        bool loaded = false;
        NiNode* model = LoadTileModel(filename.pString, &loaded);
        if (!model)
        {
            node = 0;
            return;
        }
        if (loaded)
            flags |= 0x20000;
        else
            flags &= ~0x20000;
        if (model->m_pkParent)
            model = CopyTileModel(model);
        InitControllers(model);
        ((Tile3DArrayAccess<NiPointer<NiAVObject> >*)&node.m_pObject->m_kChildren)->RemoveAll();
        CreateMenuBackgroundGeometry(model);
        InitProperties(model);
        node.m_pObject->AttachChildInAvailableSlot(model, true);
        SetValue(0xfa8, 1.0f, true);
        if (!GetBool(0xfa3))
            node.m_pObject->m_uFlags |= 1;
        else
            node.m_pObject->m_uFlags &= ~1;
        node->UpdateModel();
        if (flags & 0x40)
            flags ^= 0x40;
        UpdateValue(9);
        FinishTileModel(1);
        FlushTileModel();
    }
    NiNode* CreateTileNode();
};

// @fnv 0x00a20800
NiNode* Tile3DCalc::CreateTileNode()
{
    if (node)
    {
        node->m_pkParent = 0;
        node = 0;
    }
    node = new NiNode(0);
    LoadTile();
    if (node)
    {
        NiNode* parentNode = GetTileNiNode(GetParent());
        if (!parentNode)
            parentNode = FUN_00706d30();
        parentNode->AttachChildInAvailableSlot((NiAVObject*)(NiNode*)node, true);
        node->AddExtraData(new Tile__Extra(reinterpret_cast<Tile*>(this), node));
    }
    return node;
}

extern "C" unsigned int __cdecl strlen(const char*);
template <class T> inline const T* BSStringT<T>::String() const
{
    return pString;
}
template <class T> inline BSStringT<T>& BSStringT<T>::operator=(const T* rhs)
{
    Set(rhs, 0);
    return *this;
}
template <class T> inline unsigned int BSStringT<T>::Length() const
{
    return sLen == 65535 ? strlen(String()) : sLen;
}
// Comparison operators are absent from the shared interface.
inline bool operator==(const BSStringT<char>& lhs, const char* rhs)
{
    return !lhs.StrCmp(rhs, true);
}
inline bool operator!=(const BSStringT<char>& lhs, const char* rhs)
{
    return !(lhs == rhs);
}
inline void NiAVObject::SetBit(bool val, unsigned int mask)
{
    if (val)
        m_uFlags |= mask;
    else
        m_uFlags &= ~mask;
}
struct UpdateData
{
    float time;
    bool controllers, geom, transforms, selective, rigid;
    UpdateData(float t) : time(t), controllers(true), geom(false), transforms(false), selective(false), rigid(false)
    {}
};

inline float GetSequenceTime(const NiControllerSequence* sequence)
{
    return sequence->m_fLastTime;
}
inline float GetSequenceDuration(const NiControllerSequence* sequence)
{
    return sequence->m_fLastKeyTime;
}

extern float DAT_011f356c;
inline float DeltaTime()
{
    float delta = DAT_011f356c;
    return delta;
}
extern float DAT_01095728;
__declspec(dllimport) unsigned long __stdcall GetTickCount();
// Exe 0x00a20ed0: unit-local Tile3dInterfaceView view used by this matched implementation.
struct Tile3dInterfaceView
{
    static bool PlayNifSounds(NiControllerSequence*);
};
struct AnimTile
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    NiNode* node;
    int unk30, unk34;
    NiControllerManager* manager;
    NiControllerSequence* sequence;
    BSStringT<char> name;
    const char* GetString(int);
    bool HasValue(int);
    bool LoadSequence(const char*);
    NiNode* GetNode()
    {
        return node;
    }
    bool UpdateAnimation(float value, bool force);
};
inline float MaxTime(float value, float low)
{
    if (low > value)
        return low;
    return value;
}
inline float MinTime(float value, float high)
{
    return high < value ? high : value;
}
// @fnv 0x00a20ed0
bool AnimTile::UpdateAnimation(float value, bool force)
{
    const char* r = GetString(0xfd2);
    if ((name.String() || r) && name != r)
    {
        name = r;
        if (name.Length() && !LoadSequence(name.String()))
            name = 0;
    }
    if (!GetNode() || !manager || !HasValue(0xfa3))
        return false;
    if (!HasValue(0xfa3))
        GetNode()->SetBit(true, 1);
    if (!sequence)
        return false;
    if (GetSequenceTime(sequence) == -DAT_01095728)
    {
        UpdateData update(0.0f);
        GetNode()->Update((NiUpdateData&)update);
    }
    else if (value == -1.0)
    {
        float time3;
        time3 = GetSequenceTime(sequence) + DeltaTime();
        float ptr;
        ptr = GetSequenceDuration(sequence);
        while (time3 > ptr)
            time3 -= ptr;
        DAT_011f3560.Update(GetTickCount());
        UpdateData loopUpdate7(time3);
        GetNode()->Update((NiUpdateData&)loopUpdate7);
        if (Tile3dInterfaceView::PlayNifSounds((NiControllerSequence*)sequence))
        {
            manager->StopSequence(sequence);
            sequence = 0;
            manager->SetBit(false, 8);
        }
    }
    else if (force || value > 1.0)
    {
        float kSeekTime;
        kSeekTime = GetSequenceDuration(sequence);
        float c = MinTime(MaxTime(kSeekTime * value, 0.0f), kSeekTime);
        UpdateData seekUpdate9(c);
        GetNode()->Update((NiUpdateData&)seekUpdate9);
    }
    else
    {
        UpdateData update(value);
        GetNode()->Update((NiUpdateData&)update);
    }
    return true;
}

class NiTexture;
namespace fnv_00a21340 {
using ::NiMemObject;

struct Geometry;

struct Prop
{
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int type;
    unsigned int GetType()
    {
        return type;
    }
    unsigned int IsType(unsigned int t)
    {
        return GetType() == t;
    }
};

struct TexPointer
{
    unsigned int f00, f04;
    NiTexture* ptr;
    NiTexture* Get()
    {
        return ptr;
    }
};
struct TexturingProp : Prop
{
    TexPointer** maps;
    NiTexture* GetTexture(unsigned int index)
    {
        TexPointer* map = maps[index];
        if (map)
        {
            NiTexture* texture = map->Get();
            return texture;
        }
        else
            return 0;
    }
};

struct PropHelper
{
    void* GetProperty(unsigned int);
};

struct Geometry : PropHelper
{
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    unsigned int f34;
    unsigned int f38;
    unsigned int f3c;
    unsigned int f40;
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    unsigned int f54;
    unsigned int f58;
    unsigned int f5c;
    unsigned int f60;
    unsigned int f64;
    unsigned int f68;
    unsigned int f6c;
    unsigned int f70;
    unsigned int f74;
    unsigned int f78;
    unsigned int f7c;
    unsigned int f80;
    unsigned int f84;
    unsigned int f88;
    unsigned int f8c;
    unsigned int f90;
    unsigned int f94;
    unsigned int f98;
    unsigned int f9c;
    unsigned int fa0;
    unsigned int fa4;
    unsigned int fa8;
    unsigned int fac;
    unsigned int fb0;
    unsigned int fb4;
    unsigned int fb8;
    unsigned int fbc;
    void* shader;
    void FUN_00a5b230(unsigned int);
    void RemoveProperty(unsigned int type)
    {
        int a, b, c, d, e;
        FUN_00a5b230(type);
    }
    void FUN_00439410(TileShaderProperty*);
};

void* __cdecl FUN_00b55560(unsigned int);
inline void* AllocateShader()
{
    void* result = FUN_00b55560(32);
    return result;
}

struct FUN_00a21340_shell : Tile3D
{
    void ConvertShadersToTileShader(NiNode* node);
};

// @fnv 0x00a21340
void FUN_00a21340_shell::ConvertShadersToTileShader(NiNode* node)
{
    if (node)
    {
        for (unsigned int i8 = 0; i8 < node->m_kChildren.m_usESize; ++i8)
        {
            if (((Tile3DArrayAccess<NiPointer<NiAVObject> >*)&node->m_kChildren)->GetAt(i8))
            {
                Geometry* child_ = (Geometry*)((Tile3DArrayAccess<NiPointer<NiAVObject> >*)&node->m_kChildren)->GetAt(i8)->IsGeometry();
                if (child_)
                {
                    Prop* shader = (Prop*)child_->GetProperty(3);
                    if (shader && !(!shader ? 0 : shader->IsType(19)))
                    {
                        TileShaderProperty* property = new TileShaderProperty(false);
                        child_->RemoveProperty(3);
                        child_->FUN_00439410(property);
                        TexturingProp* data7 = (TexturingProp*)child_->GetProperty(5);
                        if (data7)
                            property->FUN_00bb7a10(data7->GetTexture(0));
                        void* allocated = FUN_00b55560(32);
                        void* texturing2 = allocated;
                        child_->shader = texturing2;
                    }
                }
                NiNode* geometry9 = ((Tile3DArrayAccess<NiPointer<NiAVObject> >*)&node->m_kChildren)->GetAt(i8)->IsSceneNode();
                if (geometry9)
                    ConvertShadersToTileShader(geometry9);
            }
        }
    }
}
}  // namespace fnv_00a21340

inline NiNode* NiAVObject::GetParent()
{
    return m_pkParent;
}
inline void NiAVObject::SetAppCulled(bool val)
{
    SetBit(val, 1);
}

inline void NiNode::SetAppCulled(bool val)
{
    SetBit(val, 1);
}

namespace fnv_00a20980 {
long FinishScriptRunLock(void* p);
long InitScriptRunLock(void* p);
}
inline void NiAVObject::IncRefCount()
{
    fnv_00a20980::InitScriptRunLock(&m_uiRefCount);
}
inline void NiAVObject::DecRefCount()
{
    if (!fnv_00a20980::FinishScriptRunLock(&m_uiRefCount))
        DeleteThis();
}
inline void NiNode::IncRefCount()
{
    fnv_00a20980::InitScriptRunLock(&m_uiRefCount);
}
inline void NiNode::DecRefCount()
{
    if (!fnv_00a20980::FinishScriptRunLock(&m_uiRefCount))
        DeleteThis();
}

namespace fnv_00a20980 {
long FinishScriptRunLock(void* p);
long InitScriptRunLock(void* p);

const char* FUN_00707860();
NiAVObject* FUN_00707660(const char* path, bool* flag);
NiAVObject* FUN_00707870(NiAVObject* obj);
void FUN_00707930(int a);
void FUN_00707820();

}  // namespace fnv_00a20980

// The approved Tile interface has no helper for the model ownership flag.
inline void SetModelLoaded(Tile* tile, bool loaded)
{
    loaded ? (tile->uiFlags |= 0x20000) : (tile->uiFlags &= ~0x20000);
}

template <> inline NiNode* NiPointer<NiNode>::operator->() const
{
    return m_pObject;
}

// Loads an object from a constructed path, attaches it beneath the node, converts its shaders, and updates culling and flags.
// @fnv 0x00a20980
void Tile3D::LoadTile()
{
    using namespace fnv_00a20980;
    const char* pszName = GetString(0xfcc);
    if (!pszName)
        return;
    if (strstr(pszName, "\\Data"))
        strFilename.PrintfString("%s", pszName);
    else
        strFilename.PrintfString("%s\\%s", FUN_00707860(), pszName);
    bool flag = false;
    NiAVObject* m_kModelObjectsItem = FUN_00707660(strFilename.String(), &flag);
    if (!m_kModelObjectsItem)
    {
        m_pRenderedNodeEntry = 0;
        return;
    }
    SetModelLoaded(this, flag);
    if (m_kModelObjectsItem->GetParent())
        m_kModelObjectsItem = FUN_00707870(m_kModelObjectsItem);
    AttachController(m_kModelObjectsItem);
    ((Tile3DArrayAccess<NiPointer<NiAVObject> >*)&m_pRenderedNodeEntry->m_kChildren)->RemoveAll();
    RemovePropertyRecursive(m_kModelObjectsItem);
    ConvertShadersToTileShader(m_kModelObjectsItem);
    m_pRenderedNodeEntry->AttachChildInAvailableSlot(m_kModelObjectsItem, true);
    Set(0xfa8, 1.0f, true);
    m_pRenderedNodeEntry->SetAppCulled(!IsTraitNonZero(0xfa3));
    m_pRenderedNodeEntry->FUN_00a5a040();
    if (uiFlags & 0x40)
        uiFlags ^= 0x40;
    SetChangeFlag(9);
    FUN_00707930(1);
    FUN_00707820();
}

