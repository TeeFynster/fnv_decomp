// bsmenu/tile3d.cpp: Tile3D, Tile3DCalc, AnimTile, Interface and more (12 functions)

#include "tile3d_decls.h"

class NiNode;
class RgbaColor;

template <> class BSStringT<char>
{
  public:
    char opaque[8];
    bool Set(const char* value, unsigned int length);
};

class Tile
{
  public:
    virtual Tile* Destroy(bool doFree);
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual NiNode* CalcNode();
    virtual unsigned int GetType();
    virtual const char* GetTypeStr();
    virtual bool Unk05(float first, float second);
    virtual Tile* UpdateField(unsigned int valueID, float floatValue, const char* strValue);
    virtual void ClearTextures();
    virtual void* GetShaderProperty();
    virtual void SetAlphaAndOverlayColor(NiNode* node, float alpha, const RgbaColor& color);

    char layoutPadding[0x34];
};

class Tile3D : public Tile
{
  public:
    virtual Tile* SetTraitValue(int value, float number, const char* text);

    void* m_pParent;
    void* m_pChildTile;
    BSStringT<char> m_kName;
    BSStringT<char> strFilename;
};

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

struct GameTimerRecord
{
    void Update(unsigned int);
    void Enable();
};
extern GameTimerRecord DAT_011f3560;
__declspec(dllimport) unsigned long __stdcall GetTickCount();
struct TileNU
{
    void SetTileType(int);
    void Set(int, float, bool);
};
struct FUN_00a20720_shell : public Tile3D
{
    void InitTile(Tile* apParent, const char* apName, Tile* apReplacedTile);
};
// @fnv 0x00a20720
void FUN_00a20720_shell::InitTile(Tile* apParent, const char* apName, Tile* apReplacedTile)
{
    Tile::Init(apParent, apName, apReplacedTile);
    ((TileNU*)this)->Set(0xff5, 255.0f, true);
    ((TileNU*)this)->Set(0xfb2, 255.0f, true);
    ((TileNU*)this)->Set(0xfb3, 255.0f, true);
    ((TileNU*)this)->Set(0xfb4, 255.0f, true);
    ((TileNU*)this)->Set(0xfa9, 255.0f, true);
    ((TileNU*)this)->Set(0xfa3, 1.0f, true);
    ((TileNU*)this)->SetTileType(3);
    DAT_011f3560.Enable();
    DAT_011f3560.Update(GetTickCount());
}

struct NiTimeController;
struct NiRTTI;
extern NiRTTI DAT_011f36ac;
struct NiAVObject
{
    NiTimeController* GetController(NiRTTI const*);
};
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
struct Col16
{
    float r, g, b, a;
};
struct AVObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual NiNode* IsSceneNode();
    virtual void v04();
    virtual void v05();
    virtual PropHelper* IsGeometry();
};
struct FUN_00a21570_shell : public Tile3D
{
    void ApplyAlphaToChildren(NiNode* apNode, float afAlpha, const RgbaColor* apTextColor);
};

// @fnv 0x00a21570
void FUN_00a21570_shell::ApplyAlphaToChildren(NiNode* apNode, float afAlpha, const RgbaColor* apColor)
{
    if (!apNode)
        return;
    for (unsigned int ui = 0; ui < *(unsigned short*)((char*)apNode + 0xa6); ui++)
    {
        AVObj* pchild;
        {
            PropHelper* pgeom;
            {
                void* pprop;
                {
                    char* ptsp;
                    {
                        AVObj** pp = &(*(AVObj***)((char*)apNode + 0xa0))[ui];
                        {
                            AVObj* p = *pp;
                            pchild = p;
                        }
                    }
                    if (pchild)
                    {
                        SetAlphaAndOverlayColor(pchild->IsSceneNode(), afAlpha, *apColor);
                        pgeom = pchild->IsGeometry();
                        if (pgeom)
                        {
                            pprop = pgeom->GetProperty(3);
                            ptsp = (char*)pprop;
                            *(float*)(ptsp + 0x78) = afAlpha;
                            *(Col16*)(ptsp + 0x68) = *(const Col16*)apColor;
                        }
                    }
                }
            }
        }
    }
}

void __fastcall FUN_004afc80(void*);
void __fastcall TrimTrailingNullPointers(void*);
struct NiAVObjectRP
{
    void RemoveProperty(unsigned int);
};
struct NiObjVtX
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* v3();
};
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
    ((NiAVObjectRP*)pTarget)->RemoveProperty(2);
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
            ((NiAVObjectRP*)pobj)->RemoveProperty(2);
            val = (char*)((NiObjVtX*)pobj)->v3();
            if (val)
                RemovePropertyRecursive(val);
        }
    }
}

extern char* EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct NiGlobalStringTable
{
    static char* __cdecl AddString(const char*);
    static long* GetRealBufferStart(char* const& h)
    {
        return ((long*)h) - 2;
    }
    static void DecRefCount(char*& h)
    {
        if (h == EmptyFS)
            return;
        NiAtomicSubtract(GetRealBufferStart(h)[0]);
    }
    static const char* GetString(char* const& h)
    {
        return h;
    }
    static long NiAtomicSubtract(long& v)
    {
        return InterlockedDecrement(&v);
    }
};
class NiFixedString
{
  public:
    NiFixedString(const char* pc)
    {
        if (pc == 0)
            m_kHandle = EmptyFS;
        else
            m_kHandle = NiGlobalStringTable::AddString(pc);
    }
    ~NiFixedString()
    {
        NiGlobalStringTable::DecRefCount(m_kHandle);
    }
    operator const char*() const
    {
        return NiGlobalStringTable::GetString(m_kHandle);
    }
    char* m_kHandle;
};
struct DummyPointerMapItem
{
    DummyPointerMapItem* m_pkNext;
    unsigned int m_key;
    unsigned int m_val;
};
struct DummyPointerMap
{
    virtual void V0();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int a, unsigned int b);
    unsigned int m_uiHashSize;
    DummyPointerMapItem** m_ppkHashTable;
    unsigned int m_uiCount;
    bool GetAt(unsigned int key, unsigned int& val)
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        DummyPointerMapItem* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(pkItem->m_key, key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
};
struct Dummy_00a20ed0
{
    void UpdateAnimation(float, int);
};
class NiControllerSequence
{
  public:
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual bool Deactivate(float fEaseOutTime, bool bTransition);
    bool Activate(char, bool, float, float, NiControllerSequence*, bool);
    int GetState()
    {
        return m_eAnimationState;
    }
    char pad[0x40];
    int m_eAnimationState;
};
struct NiControllerManager
{
    void* vt;
    long rc;
    unsigned short m_uiObjectFlags;
    char pad[0x46];
    DummyPointerMap m_kPointerMap;
    void SetBit(bool bVal, unsigned short uMask)
    {
        if (bVal)
            m_uiObjectFlags |= uMask;
        else
            m_uiObjectFlags &= ~uMask;
    }
    NiControllerSequence* FindSequenceByName(const NiFixedString& kName)
    {
        NiControllerSequence* pkSequence;
        if (m_kPointerMap.GetAt((unsigned int)(const char*)kName, (unsigned int&)pkSequence))
            return pkSequence;
        return 0;
    }
    bool StopSequence(NiControllerSequence* pkSequence, float fEaseOutTime = 0.0f)
    {
        return pkSequence->Deactivate(fEaseOutTime, false);
    }
    bool ActivateControllerSequence(NiControllerSequence* pkSequence, int iPriority = 0, bool bStartOver = false,
                                    float fWeight = 1.0f, float fEaseInTime = 0.0f,
                                    NiControllerSequence* pkTimeSyncSeq = 0)
    {
        return pkSequence->Activate((char)iPriority, bStartOver, fWeight, fEaseInTime, pkTimeSyncSeq, false);
    }
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

struct Tile3DStrField : BSStringT<char>
{
    ~Tile3DStrField()
    {
        Set(0, 0);
    }
};

struct Tile3DBaseDtor : Tile
{
    virtual ~Tile3DBaseDtor();
};

struct FUN_00a20650_cls : Tile3DBaseDtor
{
    void* m_pParent;
    void* m_pChildTile;
    Tile3DStrField m_kName;
    Tile3DStrField strFilename;
    __forceinline bool TestFlag(unsigned int mask) const
    {
        return (*(const unsigned int*)((const char*)this + 0x30) & mask) != 0;
    }
    virtual ~FUN_00a20650_cls();
};

void __cdecl FUN_00707640(unsigned int value);
void __fastcall FUN_009ff690(void* pThis);

struct FUN_00a20650_pad
{
    unsigned int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38;
};

// @fnv 0x00a20650
FUN_00a20650_cls::~FUN_00a20650_cls()
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

class NiExtraData
{
  public:
    NiExtraData();
    virtual ~NiExtraData();
    void SetName(const NiFixedString& name);
    int unk04;
    int unk08;
};

class NiObjectNET
{
  public:
    virtual ~NiObjectNET();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void AttachChildInAvailableSlot(NiNode* child, bool firstAvail);
    bool AddExtraData(NiExtraData* extra);
    void DecRefCount();
    void IncRefCount();
};

struct NiNodeChildArray
{
    NiNodeChildArray(int maxSize, int growBy);
    ~NiNodeChildArray();
    void RemoveAll();
    void* vtbl;
    int m_pBase;
    int m_usMaxSize;
    int m_usGrowBy;
};

class NiNode : public NiObjectNET
{
  public:
    NiNode(unsigned short arraySize);
    void UpdateModel();
    static void* operator new(unsigned int size);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiNode* m_pParentNode;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    NiNodeChildArray m_kChildList;
};

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

struct TileX
{
    NiNode* GetNiNode();
};
NiNode* FUN_00706d30();

extern "C" char* __cdecl strstr(const char*, const char*);
struct ModelPath
{
    char* buffer;
    unsigned int length;
};
int __cdecl FormatModelPath(ModelPath*, const char*, ...);
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
    TileX* parent;
    NiPtrX<NiNode> node;

    TileX* GetParent()
    {
        return parent;
    }
    unsigned int flags;
    int unk34, unk38, unk3c, unk40, unk44;
    ModelPath filename;
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
            FormatModelPath(&filename, "%s", name);
        else
            FormatModelPath(&filename, "%s\\%s", ModelRoot(), name);
        bool loaded = false;
        NiNode* model = LoadTileModel(filename.buffer, &loaded);
        if (!model)
        {
            node = 0;
            return;
        }
        if (loaded)
            flags |= 0x20000;
        else
            flags &= ~0x20000;
        if (model->m_pParentNode)
            model = CopyTileModel(model);
        InitControllers(model);
        node.m_pObject->m_kChildList.RemoveAll();
        CreateMenuBackgroundGeometry(model);
        InitProperties(model);
        node.m_pObject->AttachChildInAvailableSlot(model, true);
        SetValue(0xfa8, 1.0f, true);
        if (!GetBool(0xfa3))
            node.m_pObject->unk30 |= 1;
        else
            node.m_pObject->unk30 &= ~1;
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
        node->m_pParentNode = 0;
        node = 0;
    }
    node = new NiNode(0);
    LoadTile();
    if (node)
    {
        NiNode* parentNode = GetParent()->GetNiNode();
        if (!parentNode)
            parentNode = FUN_00706d30();
        parentNode->AttachChildInAvailableSlot(node, true);
        node->AddExtraData(new Tile__Extra(reinterpret_cast<Tile*>(this), node));
    }
    return node;
}

extern "C" unsigned int __cdecl strlen(const char*);
struct AnimString
{
    char* text;
    unsigned short length, capacity;
    int StrCmp(const char*, bool) const;
    bool Set(const char*, unsigned int);
    const char* Get() const
    {
        return text;
    }
    bool operator==(const char* rhs) const
    {
        return !StrCmp(rhs, true);
    }
    AnimString& operator=(const char* rhs)
    {
        Set(rhs, 0);
        return *this;
    }
    bool operator!=(const char* rhs) const
    {
        return !(*this == rhs);
    }
    unsigned int Length() const
    {
        return length == 65535 ? strlen(Get()) : length;
    }
};
struct UpdateData
{
    float time;
    bool controllers, geom, transforms, selective, rigid;
    UpdateData(float t) : time(t), controllers(true), geom(false), transforms(false), selective(false), rigid(false)
    {}
};
struct AnimNode
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
    int unk2c;
    unsigned int flags;
    void SetFlag(bool b, unsigned int mask)
    {
        if (b)
            flags |= mask;
        else
            flags &= ~mask;
    }
    void Update(UpdateData&);
};
struct AnimSequence
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool Deactivate(float, bool);
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
    int unk2c;
    float duration, time;
    float GetTime() const
    {
        return time;
    }
    float GetDuration() const
    {
        return duration;
    }
};
struct AnimManager
{
    int unk00, unk04;
    unsigned short flags;
    void SetBit(bool b, unsigned short mask)
    {
        if (b)
            flags |= mask;
        else
            flags &= ~mask;
    }
    bool StopSequence(AnimSequence* seq, float ease = 0.0f)
    {
        return seq->Deactivate(ease, false);
    }
};

extern float DAT_011f356c;
inline float DeltaTime()
{
    float delta = DAT_011f356c;
    return delta;
}
extern float DAT_01095728;
__declspec(dllimport) unsigned long __stdcall GetTickCount();
struct Interface
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
    AnimNode* node;
    int unk30, unk34;
    AnimManager* manager;
    AnimSequence* sequence;
    AnimString name;
    const char* GetString(int);
    bool HasValue(int);
    bool LoadSequence(const char*);
    AnimNode* GetNode()
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
    if ((name.Get() || r) && name != r)
    {
        name = r;
        if (name.Length() && !LoadSequence(name.Get()))
            name = 0;
    }
    if (!GetNode() || !manager || !HasValue(0xfa3))
        return false;
    if (!HasValue(0xfa3))
        GetNode()->SetFlag(true, 1);
    if (!sequence)
        return false;
    if (sequence->GetTime() == -DAT_01095728)
    {
        UpdateData update(0.0f);
        GetNode()->Update(update);
    }
    else if (value == -1.0)
    {
        float time3;
        time3 = sequence->GetTime() + DeltaTime();
        float ptr;
        ptr = sequence->GetDuration();
        while (time3 > ptr)
            time3 -= ptr;
        DAT_011f3560.Update(GetTickCount());
        UpdateData loopUpdate7(time3);
        GetNode()->Update(loopUpdate7);
        if (Interface::PlayNifSounds((NiControllerSequence*)sequence))
        {
            manager->StopSequence(sequence);
            sequence = 0;
            manager->SetBit(false, 8);
        }
    }
    else if (force || value > 1.0)
    {
        float kSeekTime;
        kSeekTime = sequence->GetDuration();
        float c = MinTime(MaxTime(kSeekTime * value, 0.0f), kSeekTime);
        UpdateData seekUpdate9(c);
        GetNode()->Update(seekUpdate9);
    }
    else
    {
        UpdateData update(value);
        GetNode()->Update(update);
    }
    return true;
}

namespace fnv_00a21340 {
struct NiMemObject
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct NiTexture;
struct TileShaderProperty : NiMemObject
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
    TileShaderProperty(bool);
    void FUN_00bb7a10(NiTexture*);
};

struct AVObj;
struct Geometry;
struct NiNode;

struct AVObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NiNode* IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual Geometry* IsGeometry();
};

struct NodePointer
{
    AVObj* ptr;
    operator AVObj*() const
    {
        return ptr;
    }
    AVObj* operator->() const
    {
        AVObj* result = ptr;
        return result;
    }
};
struct NodeArray
{
    void* vf;
    NodePointer* data;
    unsigned short capacity, allocated, size;
    NodePointer& operator[](unsigned int i)
    {
        return data[i];
    }
};

struct NiNode : AVObj
{
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
    NodeArray children;
};

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
        for (unsigned int i8 = 0; i8 < node->children.size; ++i8)
        {
            if (node->children[i8])
            {
                Geometry* child_ = (Geometry*)node->children[i8]->IsGeometry();
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
                NiNode* geometry9 = node->children[i8]->IsSceneNode();
                if (geometry9)
                    ConvertShadersToTileShader(geometry9);
            }
        }
    }
}
}  // namespace fnv_00a21340

namespace fnv_00a20980 {
long FinishScriptRunLock(void* p);
long InitScriptRunLock(void* p);

class NiAVObject
{
  public:
    void IncRefCount()
    {
        InitScriptRunLock(&unk04);
    }
    void DecRefCount()
    {
        if (!FinishScriptRunLock(&unk04))
            DeleteThis();
    }
    virtual void vf00();
    virtual void DeleteThis();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void AttachChildInAvailableSlot(NiAVObject* child, bool firstAvail);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiAVObject* m_parent;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned int m_flags;

    NiAVObject* GetParent()
    {
        return m_parent;
    }
    void SetBit(bool val, unsigned int mask)
    {
        if (val)
            m_flags |= mask;
        else
            m_flags &= ~mask;
    }
    void SetAppCulled(bool val)
    {
        SetBit(val, 1);
    }
};

template <class T> class NiPtr;

template <class T> class NiTArray
{
  public:
    virtual void vf00();

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void RemoveAll()
    {
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = T(0);
        m_usSize = 0;
        m_usESize = 0;
    }
};

class NiNode : public NiAVObject
{
  public:
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    NiTArray<NiPtr<NiAVObject> > m_children;
    void FUN_00a5a040();
};

template <class T> class NiPtr
{
  public:
    T* m_object;
    NiPtr(T* p)
    {
        m_object = p;
        if (m_object)
            m_object->IncRefCount();
    }
    ~NiPtr();
    NiPtr& operator=(const NiPtr& p);
    NiPtr& operator=(T* p)
    {
        if (m_object != p)
        {
            if (m_object)
                m_object->DecRefCount();
            m_object = p;
            if (m_object)
                m_object->IncRefCount();
        }
        return *this;
    }
    T* operator->() const
    {
        return m_object;
    }
    operator T*() const
    {
        return m_object;
    }
};

class BSString
{
  public:
    char* m_data;
    int m_len;
    const char* CStr()
    {
        return m_data;
    }
    int Sprintf(const char* fmt, ...);
};

const char* FUN_00707860();
NiAVObject* FUN_00707660(const char* path, bool* flag);
NiAVObject* FUN_00707870(NiAVObject* obj);
void FUN_00707930(int a);
void FUN_00707820();

class Tile3DX
{
  public:
    virtual void vf00();

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
    NiPtr<NiNode> node;
    unsigned int flags;
    int unk34;
    void* m_pParent;
    void* m_pChildTile;
    BSString m_kName;
    BSString strFilename;

    const char* GetString(int id);
    bool GetBool(int id);
    void Set(int id, float value, bool b);
    void SetChangeFlag(int a);
    bool AttachController(NiAVObject* obj);
    void RemovePropertyRecursive(NiAVObject* obj);
    void ConvertShadersToTileShader(NiAVObject* obj);
    void SetFlag20000(bool b)
    {
        b ? (flags |= 0x20000) : (flags &= ~0x20000);
    }
    void LoadTile();
};

// Loads an object from a constructed path, attaches it beneath the node, converts its shaders, and updates culling and flags.
// @fnv 0x00a20980
void Tile3DX::LoadTile()
{
    const char* pszName = GetString(0xfcc);
    if (!pszName)
        return;
    if (strstr(pszName, "\\Data"))
        strFilename.Sprintf("%s", pszName);
    else
        strFilename.Sprintf("%s\\%s", FUN_00707860(), pszName);
    bool flag = false;
    NiAVObject* m_kModelObjectsItem = FUN_00707660(strFilename.CStr(), &flag);
    if (!m_kModelObjectsItem)
    {
        node = 0;
        return;
    }
    SetFlag20000(flag);
    if (m_kModelObjectsItem->GetParent())
        m_kModelObjectsItem = FUN_00707870(m_kModelObjectsItem);
    AttachController(m_kModelObjectsItem);
    node->m_children.RemoveAll();
    RemovePropertyRecursive(m_kModelObjectsItem);
    ConvertShadersToTileShader(m_kModelObjectsItem);
    node->AttachChildInAvailableSlot(m_kModelObjectsItem, true);
    Set(0xfa8, 1.0f, true);
    node->SetAppCulled(!GetBool(0xfa3));
    node->FUN_00a5a040();
    if (flags & 0x40)
        flags ^= 0x40;
    SetChangeFlag(9);
    FUN_00707930(1);
    FUN_00707820();
}
}  // namespace fnv_00a20980
