#include "../../../include/BSAudio.h"
#include "../../../include/BSFadeNode.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/FORenderedTerminal.h"
#define FNV_FOURFLOATVECTOR_NO_SSE
// 0x007feeb0 constructs four-float color/viewport values with four-byte alignment (shared SIMD extent 1897 vs 1940).
struct TerminalColorViewport_007feeb0
{
    float x, y, z, w;
    TerminalColorViewport_007feeb0(float, float, float, float);
};

#undef FNV_FOURFLOATVECTOR_NO_SSE
#include "../../../include/NiAdditionalGeometryData.h"
#include "../../../include/NiRenderer.h"
#include "../../../include/NiUpdateData.h"
// LocalVector3: unit-local copy of the former shared stand-in Vector3. Same layout as NiPoint3 but with the stand-in's inline bodies (constructor, operator-, SquaredLength); with NiPoint3, SetupPowerButtonScreen (0x007feeb0) does not match.
class FloatMatrix3;

class LocalVector3
{
public:
    float x;
    float y;
    float z;

    LocalVector3()
    {
    }
    LocalVector3(float x, float y, float z) : x(x), y(y), z(z)
    {}
    LocalVector3(float x, int y, int z);

    LocalVector3 AddVector(const LocalVector3& other) const;
    LocalVector3 ScaleSwizzled(float scale) const;
    LocalVector3 operator*(double multiplier) const;
    LocalVector3 operator*(float multiplier) const;
    LocalVector3 operator+(const LocalVector3& right) const;
    LocalVector3 operator-(const LocalVector3& right) const
    {
        return LocalVector3(x - right.x, y - right.y, z - right.z);
    }
    LocalVector3& operator-=(const LocalVector3& right);
    LocalVector3& operator+=(const LocalVector3& right);
    float& operator[](int index);
    float Dot(const LocalVector3& right) const;
    float SquaredLength() const
    {
        return x * x + y * y + z * z;
    }
    void Normalize();
    float Length() const;

    LocalVector3 Diff_00b13040(const LocalVector3& other) const;
    LocalVector3 FUN_00b12890(const FloatMatrix3& matrix) const;
    LocalVector3 FUN_00b12810(const LocalVector3& other) const;
    void Normalize_00b12790();
    void __thiscall SubtractIntoVector(LocalVector3* dest, void* context);
    void __thiscall Unitize_004a0c10();
// src: GUESS 0x00439ef0 (confidence: high)
    LocalVector3 SubtractIntoVector(const LocalVector3& other) const
    {
        return LocalVector3(x - other.x, y - other.y, z - other.z);
    }
    float FUN_004a7290() const
    {
        return x * x + y * y + z * z;
    }
};

// src/fallout/interface/forenderedterminal.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/forenderedterminal.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ShadowSceneNode;


// @fnv 0x007ffad0
// src: COMMUNITY 0x007ffad0
NiAVObject* FORenderedTerminal::GetParentNodeToRender()
{
    return NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1);
}

struct GlobalObjectO2_0045cfe0
{
    void ProcessAndReturnValue_0045ce80(int);
};

GlobalObjectO2_0045cfe0 g_011f9148;

// @fnv 0x007ffb60
void ForwardToGlobalObject(int aiValue)
{
    g_011f9148.ProcessAndReturnValue_0045ce80(aiValue);
}

namespace fnv_007ffb80 {
struct GlobalObject2_0040c150
{
    int* Int(void);
};
struct GlobalObjectO2_0045cfe0
{
    int* Int(void);
};
extern GlobalObjectO2_0045cfe0 g_011f9148;

// @fnv 0x007ffb80
// src: XBOX_PDB 0x007ffb80
int BSFadeNode_QMinNearDistance()
{
    return *g_011f9148.Int();
}
}  // namespace fnv_007ffb80

struct FUN_00456630_helper
{
    bool __thiscall NiAVObject_GetBit(unsigned int);
};

struct FUN_007ff8e0_shell
{
    bool NiAVObject_QFadedIn();
};

// @fnv 0x007ff8e0
// src: XBOX_PDB 0x007ff8e0
bool FUN_007ff8e0_shell::NiAVObject_QFadedIn()
{
    return reinterpret_cast<FUN_00456630_helper*>(this)->NiAVObject_GetBit(0x4000);
}

struct FUN_007ff8c0_shell : public FUN_007ff8e0_shell
{
    bool BSFadeNode_IsFadedIn();
};
// @fnv 0x007ff8c0
// src: COMMUNITY 0x007ff8c0
bool FUN_007ff8c0_shell::BSFadeNode_IsFadedIn()
{
    return NiAVObject_QFadedIn();
}

struct FUN_004bc1f0_S
{
    void NiAVObject_SetTranslate_004bc1f0(float, float, float);
};
extern float DAT_01078bb0;
struct FUN_007ff900_This
{
    void UpdateSynchTimeNode();
};
// @fnv 0x007ff900
void FUN_007ff900_This::UpdateSynchTimeNode()
{
    NiAVObject* proot;
    proot = (NiAVObject*)((BSAudio*)this)->GetSynchTime();
    if (proot)
    {
        ((FUN_004bc1f0_S*)proot)->NiAVObject_SetTranslate_004bc1f0(DAT_01078bb0, 0.0f, 0.0f);
        NiUpdateData UpdateData(0.0f, 0, 0);
        ((NiNode*)proot)->Update(UpdateData);
    }
}

struct V3;
struct FUN_00440460_S
{
    void NiAVObject_SetTranslate(V3 const*);
};
struct BSRenderedTexture;
struct FUN_007ff7c0_shell : public BSAudio, public FUN_00440460_S
{
    void FORenderedTerminal_Draw(BSRenderedTexture* apTarget, NiRenderer::ClearFlags aeClearMode, BSRenderedTexture* apSwapTarget);
    void Render_007fba00(BSRenderedTexture*, int, int);
};
// @fnv 0x007ff7c0
// src: COMMUNITY 0x007ff7c0
void FUN_007ff7c0_shell::FORenderedTerminal_Draw(BSRenderedTexture* apTarget, NiRenderer::ClearFlags aeClearMode,
                                      BSRenderedTexture* apSwapTarget)
{
    NiAVObject* proot = (NiAVObject*)GetSynchTime();
    if (proot)
    {
        ((FUN_00440460_S*)proot)->NiAVObject_SetTranslate((V3 const*)((char*)this + 0xd8));
        NiUpdateData UpdateData(0.0f, false, false);
        ((NiNode*)proot)->Update(UpdateData);
    }
    Render_007fba00(apTarget, 1, 0);
}

struct Flt
{
    operator unsigned int();
};
extern Flt g_011db63c;
void ForwardToGlobalObject(int param);
int __cdecl BSFadeNode_QMinNearDistance();
struct FUN_007ffaf0_shell
{
    void FORenderedTerminal_FadeOut();
};

// If g_011db63c is set, saves and restores the value from FUN_007ffb80 around ForwardToGlobalObject(0) and SetRange(0,0); then sets byte 0xec to 1 and float 0xe8 to 1.0.
// @fnv 0x007ffaf0
// src: XBOX_PDB 0x007ffaf0
void FUN_007ffaf0_shell::FORenderedTerminal_FadeOut()
{
    if ((unsigned int)g_011db63c)
    {
        int iSavedValue = BSFadeNode_QMinNearDistance();
        ForwardToGlobalObject(0);
        ((BSFadeNode*)(unsigned int)g_011db63c)->SetRange(0.0f, 0.0f);
        ForwardToGlobalObject(iSavedValue);
    }
    ((char*)this)[0xec] = 1;
    *(float*)((char*)this + 0xe8) = 1.0f;
}

struct FUN_007ff820_shell : public FUN_007ff7c0_shell
{
    bool UpdateAudioFallback();
};

struct AudioClock : public FUN_007ff8c0_shell
{
};
struct AudioFallback
{
};

float __fastcall GetFieldB4Float(AudioClock* clock);
bool __fastcall UpdateScreenEffect(FUN_007ff820_shell* surface);
void __fastcall SetRenderedMenu(AudioFallback* fallback);
AudioFallback* __stdcall InterfaceManager_GetSingleton(int mode);

// @fnv 0x007ff820
bool FUN_007ff820_shell::UpdateAudioFallback()
{
    if (*((unsigned char*)this + 0xec))
    {
        if (!g_011db63c || !((AudioClock*)(unsigned int)g_011db63c)->BSFadeNode_IsFadedIn() ||
            *((float*)((char*)this + 0xe8)) == GetFieldB4Float((AudioClock*)(unsigned int)g_011db63c))
        {
            SetRenderedMenu(InterfaceManager_GetSingleton(0));
            return true;
        }
        else
        {
            *((float*)((char*)this + 0xe8)) = GetFieldB4Float((AudioClock*)(unsigned int)g_011db63c);
        }
    }
    return UpdateScreenEffect(this);
}

struct PickTargetNode;

struct PickNodePtr
{
    operator PickTargetNode*() const;
};

struct PickPoint3
{
    float x;
    float y;
    float z;
    PickPoint3();
};

struct PickCamera
{
    void WindowPixelToRay(int aiX, int aiY, PickPoint3& arOrigin, PickPoint3& arDir, int aiPort);
};

struct PickFaceGenNode
{
    PickCamera* GetCamera();
};
PickFaceGenNode* GetPickFaceGenNode();

struct PickInterfaceMgr
{
    float GetCursorY();
    float GetPickCursorX();
};
PickInterfaceMgr* GetPickInterfaceMgr();

struct PickRecord
{
    PickTargetNode* GetObject();
};

struct PickResultArray
{
    PickRecord* GetAt(unsigned int auiIndex);
};

struct PickQuery
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    PickQuery(int aeSortType, int aeIntersectType);
    ~PickQuery();
    void SetPickType(int aeType);
    void SetTarget(PickTargetNode* apTarget);
    void SetReturnNormal(bool abNormal);
    bool PerformPick(PickPoint3& arOrigin, PickPoint3& arDir, bool abAppend);
    PickResultArray& GetResults();
};

struct RenderedTerminalStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    PickNodePtr spScreenNode;

    PickCamera* GetRenderCamera();
    void OnScreenClicked();
    bool HandleClickBase(bool abDown, int aiX, int aiY);
    bool HandleClick(bool abDown, int aiX, int aiY);
};

// If the screen node is set and the button is down, ray-picks it from the cursor and calls OnScreenClicked on a hit; otherwise falls through to HandleClickBase.
// @fnv 0x007ffba0
bool RenderedTerminalStandIn::HandleClick(bool abDown, int aiX, int aiY)
{
    bool bHandledX = false;
    PickInterfaceMgr* pInterfaceMgr = GetPickInterfaceMgr();
    if (spScreenNode && abDown)
    {
        PickPoint3 kOriginTmp;
        PickPoint3 kDir3;
        PickCamera* pCamera = GetRenderCamera();
        if (!pCamera)
        {
            pCamera = GetPickFaceGenNode()->GetCamera();
        }
        PickQuery kPick(0, 8);
        kPick.SetPickType(0);
        kPick.SetTarget(spScreenNode);
        kPick.SetReturnNormal(true);
        pCamera->WindowPixelToRay((int)pInterfaceMgr->GetPickCursorX(), (int)pInterfaceMgr->GetCursorY(), kOriginTmp,
                                  kDir3, 0);
        if (kPick.PerformPick(kOriginTmp, kDir3, false))
        {
            unsigned int uiIndex3 = 0;
            PickRecord* pRecord5 = kPick.GetResults().GetAt(uiIndex3);
            if (pRecord5 && pRecord5->GetObject() == spScreenNode)
            {
                OnScreenClicked();
                return false;
            }
        }
    }
    bool bResult = HandleClickBase(abDown, aiX, aiY);
    return bResult;
}

struct FloatSetting
{
    float* Setting_Float_00403e20();
};
extern FloatSetting g_011db674, g_011db65c, g_011db62c, g_011db614, g_01203144, g_01203150, g_011db5ec;
extern unsigned DAT_011a0bb0;
extern unsigned char DAT_011f9426;
extern int DAT_011f9434;
extern float DAT_010559cc, DAT_01016264;
extern double DAT_0101de30, DAT_01023128, DAT_01021928;
struct Name
{
    unsigned interned;
    Name(const char*);
    ~Name();
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix();
    void RotateX(float);
    void RotateY(float);
    Matrix operator*(const Matrix&) const;
    void SetColumn(int, float, float, float);
};
struct Frustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
    Frustum(int);
};
struct Resource
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Resource* Child(int);
    virtual void v10();
    virtual void v14();
    virtual Resource* GetNode();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual Resource* Find(const Name&);
    Resource* AsNode();
    void SetRotation(const Matrix&);
    void SetTranslation(float, float, float);
    void SetPosition(const LocalVector3&);
    Resource* GetBound();
    float GetRadius();
    void AddProperty(void*);
    void SetController(void*);
    LocalVector3 const& GetPosition();
    void SetFlag(int);
};
struct NodeHolder
{
    void Assign(Resource*);
};
struct Manager
{
    Resource* Load(unsigned, int, int, int, int, int);
};
extern Manager* DAT_011c3b3c;
void __cdecl MarkLoaded(Resource*);
void* __cdecl operator new(unsigned);
void __cdecl operator delete(void*);
struct Camera : Resource
{
    int f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44, f48, f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
    int f80, f84, f88, f8c, f90, f94, f98, f9c, fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc;
    int fc0, fc4, fc8, fcc, fd0, fd4, fd8, fdc, fe0, fe4, fe8, fec, ff0, ff4, ff8, ffc;
    int f100, f104, f108, f10c, f110;
    static void* operator new(unsigned);
    Camera();
    void SetViewport(const TerminalColorViewport_007feeb0&);
    void SetScale(float);
    void SetNearFar(float);
    void SetFrustum(const Frustum&);
};
struct Controller
{
    int f00, f04, f08, f0c, f10, f14, f18;
    static void* operator new(unsigned);
    Controller();
};
// Exe 0x007feeb0: unit-local ForenderedterminalInterfaceView view used by this matched implementation.
struct ForenderedterminalInterfaceView
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual float GetFar();
};
ForenderedterminalInterfaceView* __cdecl GetInterface();
bool __cdecl Renderer_GetWidescreen();
int __cdecl Renderer_GetScreenHeight();
int __cdecl Renderer_GetScreenWidth();
float __cdecl tan_0057dd70(float);
void* __cdecl MagicSystem_CheckEffectFlares();
struct Backend
{
    void* Create(Resource*, float);
};
Backend* __cdecl GetBackend(int);
struct Colors
{
    bool GetColor(TerminalColorViewport_007feeb0&);
};
Colors* __stdcall GetColors(int);
extern Matrix DAT_011a9448;
struct RenderNode
{
    void SetMode(int, float);
    void SetScreen(Resource*);
    void SetScreen2(Resource*);
    void SetRoot(Resource*);
    void SetCamera(Camera*);
    void Update();
    Resource* GetRenderObject();
    void NoBackend();
    void Enable(int);
    void Toggle(int);
    void SetColor(const TerminalColorViewport_007feeb0&);
    void SetupPowerButtonScreen();
};
// Loads the screen and PowerButton nodes, builds a camera with frustum, sets screen/root/camera, updates, and creates the backend render object.
// @fnv 0x007feeb0
void RenderNode::SetupPowerButtonScreen()
{
    SetMode(1, *g_011db674.Setting_Float_00403e20());
    bool createdCur = false;
    Resource* rootP = 0;
    if (!(unsigned)g_011db63c)
    {
        rootP = DAT_011c3b3c->Load(DAT_011a0bb0, 0, 1, 0, 0, 0);
        ((NodeHolder*)&g_011db63c)->Assign(rootP);
        MarkLoaded(rootP);
        createdCur = true;
    }
    else
        rootP = (Resource*)(unsigned)g_011db63c;
    Resource* screenX = rootP->Find(Name("screen"));
    Resource* screenNode = screenX->GetNode();
    if (!screenNode)
        screenNode = screenX->Child(0)->AsNode()->GetNode();
    Resource* kPower = rootP->Find(Name("PowerButton"));
    if (kPower->GetNode())
        ((NodeHolder*)((char*)this + 0xe4))->Assign(kPower);
    else
        ((NodeHolder*)((char*)this + 0xe4))->Assign(kPower->Child(0)->AsNode());
    Matrix rotAM, rotB;
    rotAM.RotateX(DAT_010559cc);
    rotB.RotateY(DAT_010559cc);
    rootP->SetRotation(rotB * rotAM);
    float rate9 = *g_011db65c.Setting_Float_00403e20();
    if (!Renderer_GetWidescreen() && !DAT_011f9426)
        rate9 = (float)(rate9 * DAT_0101de30);
    rootP->SetTranslation(rate9, *g_011db614.Setting_Float_00403e20(), *g_011db62c.Setting_Float_00403e20());
    LocalVector3 akStart(0.f, 0, 0);
    rootP->SetPosition(akStart);
    Camera* cameraK = new Camera;
    TerminalColorViewport_007feeb0 viewport(0.f, 1.f, 1.f, 0.f);
    cameraK->SetViewport(viewport);
    Matrix frame5;
    frame5.SetColumn(0, 0.f, 0.f, 1.f);
    frame5.SetColumn(1, 1.f, 0.f, 0.f);
    frame5.SetColumn(2, 0.f, 1.f, 0.f);
    cameraK->SetRotation(DAT_011a9448);
    cameraK->SetScale(1.f);
    Frustum frustum(0);
    frustum.farPlane = GetInterface()->GetFar();
    frustum.nearPlane = *g_01203144.Setting_Float_00403e20();
    cameraK->SetNearFar(frustum.farPlane / frustum.nearPlane);
    float aspect6 = (double)(DAT_011f9426 ? DAT_011f9434 : Renderer_GetScreenHeight()) / Renderer_GetScreenWidth();
    float scale4 = DAT_01016264;
    float angle7 = (float)(*g_01203150.Setting_Float_00403e20() * DAT_01023128 * *g_011db5ec.Setting_Float_00403e20());
    frustum.left = -tan_0057dd70(angle7) * scale4;
    frustum.right = tan_0057dd70(angle7) * scale4;
    frustum.bottom = -tan_0057dd70(angle7) * aspect6 * scale4;
    frustum.top = tan_0057dd70(angle7) * aspect6 * scale4;
    frustum.ortho = false;
    cameraK->SetFrustum(frustum);
    LocalVector3 pos2(0.f, 0, 0);
    cameraK->SetPosition(pos2);
    SetScreen(screenNode);
    SetScreen2(screenNode);
    SetRoot(rootP);
    screenNode->AddProperty(MagicSystem_CheckEffectFlares());
    screenNode->SetController(new Controller);
    SetCamera(cameraK);
    Update();
    *(LocalVector3*)((char*)this + 0xd8) = GetRenderObject()->GetPosition();
    GetRenderObject()->SetTranslation(DAT_01078bb0, 0.f, 0.f);
    float radius = (float)(rootP->GetBound()->GetRadius() * DAT_01021928);
    void* aBackend = GetBackend(1)->Create(rootP, radius);
    if (!aBackend)
        NoBackend();
    Enable(0);
    Toggle(0);
    ((Resource*)(unsigned)g_011db63c)->SetFlag(8);
    TerminalColorViewport_007feeb0 colorF(0.f, 0.f, 0.f, 0.f);
    if (GetColors(3)->GetColor(colorF))
        SetColor(colorF);
    *(float*)((char*)this + 0xe8) = 1.f;
}

struct Sound376
{
    unsigned int id;
    unsigned int flags;
    unsigned int state;
    ~Sound376()
    {}
    bool FUN_00ad8830(bool deferred);
};
struct Audio376
{
    Sound376 ResolveAudioHandle(const char* editorID, unsigned int flags);
};
Audio376* BSAudioManager_QInstance_00ad9060();
// @fnv 0x007ffe40
// src: XBOX_PDB 0x007ffe40
void FORenderedTerminal_PlayShutdownSound()
{
    BSAudioManager_QInstance_00ad9060()->ResolveAudioHandle("OBJComputerTerminalPowerDown", 0x121).FUN_00ad8830(false);
}
