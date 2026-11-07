#include "../../../../include/NiTStringPointerMap.h"
// gamebryo2.2/corelibs/nimain/nigeometry.cpp: NiGeometry, NiAVObject and dependencies (23 functions)

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiCullingProcess.h"
#include "../../../../include/NiGeometry.h"
#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiCollisionObject.h"
#include "../../../../include/NiD3DShaderInterface.h"
#include "../../../../include/NiD3DShaderProgram.h"
#include "../../../../include/NiPropertyState.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/NonActorMagicCaster.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/NiScreenLODData.h"
#include "../../../../include/NiTexture.h"

#include <new>


inline const char* NiRTTI::GetName() const { return m_pcName; }
inline bool NiRTTI::IsExactly(const NiRTTI* type) const { return this == type; }
inline NiBound::NiBound() {}
inline NiBound::NiBound(const NiBound& b) : m_kCenter(b.m_kCenter), radiusBits(b.radiusBits) {}
inline void NiBound::SetCenterAndRadius(const NiPoint3& point, float value)
{
    m_kCenter = point;
    m_fRadius = value;
}
inline bool NiD3DShaderInterface::IsExactKindOf(const NiRTTI* type)
{
    return GetRTTI()->IsExactly(type);
}
inline bool NiGeometry::GetFlag19() const { return (m_uFlags >> 19) & 1; }
inline bool NiGeometry::GetFlag13() const { return (m_uFlags >> 13) & 1; }


// The remaining declarations describe dependencies specific to this unit.

class CloningProcess;
template <class T> void ReadBinaryValue(NiStream& stream, T& value);
template <> void ReadBinaryValue<unsigned int>(NiStream& stream, unsigned int& value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (pkNew)
        InterlockedIncrement((long volatile*)&pkNew->m_uiRefCount);
}
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    T* old = m_pObject;
    if (old != pkNew)
    {
        if (old && InterlockedDecrement((long volatile*)&old->m_uiRefCount) == 0)
            old->DeleteThis();
        m_pObject = pkNew;
        if (pkNew)
            InterlockedIncrement((long volatile*)&pkNew->m_uiRefCount);
    }
    return *this;
}
class NiPropertyNode
{
  public:
    NiPropertyNode* m_pkNext;
    unsigned int m_uiPad;
    NiPointer<NiProperty> m_pkProperty;
    static NiPointer<NiProperty>& GetNext(NiPropertyNode*& pos)
    {
        NiPointer<NiProperty>& value = pos->m_pkProperty;
        pos = pos->m_pkNext;
        return value;
    }
};
extern unsigned int DAT_011f42a4;
extern unsigned int DAT_011f42a0;
#include "../../../../include/RecursiveSpinLock.h"
#include "../../../../include/NiTStringPointerMap.h"
class ShaderBufferRecord;
class CloningProcess
{
  public:
    NiTStringPointerMap<ShaderBufferRecord*>* m_pCloneMap;
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)
extern NiBound DAT_011f4288;
inline const NiBound& NiGeometry::GetBoundingVolume() const
{
    if (m_kWorldBound) return *(NiBound*)m_kWorldBound;
    return DAT_011f4288;
}
inline const NiBound& __fastcall PreviousBound(NiBound* b)
{
    return b ? *b : DAT_011f4288;
}
inline bool BoundFlag(unsigned int bits, unsigned int shift)
{
    return (bits >> shift) & 1;
}
inline NiBound CopyWorldBound(NiBound* b)
{
    return b ? *b : DAT_011f4288;
}
extern MemoryManager g_memoryManager;
class NiLODNode;
template <> NiPointer<NiAVObject>& NiPointer<NiAVObject>::operator=(NiAVObject*);
inline NiD3DShaderInterface* CreateGeometryShader()
{
    NiD3DShaderInterface* shader = 0;
    void* memory = NiMemObject::operator new(sizeof(NiShader));
    if (memory)
        shader = ::new (memory) NiD3DShaderInterface;
    return shader;
}
inline bool& TestGeometryShaderType(NiD3DShaderInterface* object, const NiRTTI* type, bool& result)
{
    result = (unsigned char)(object->GetRTTI() == type) & 255;
    return result;
}
inline bool NiIsExactKindOf(const NiRTTI* type, NiD3DShaderInterface* object)
{
    return object ? object->IsExactKindOf(type) : false;
}
extern NiRTTI DAT_011f5d08;
class MagicItem;
class NiController
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void Update();
    char pad[0x2c];
    NiController* next;
};
struct NiGeometryProperties
{
    char pad[12];
    NiPropertyState* state;
};

// @fnv 0x00a89ab0
NiGeometry* NiGeometry::CopyMemberData()
{
    unsigned int* fields = (unsigned int*)this;
    fields[0] = 0;
    fields[1] = 0;
    fields[2] = 0;
    fields[3] = 0;
    fields[4] = 0;
    fields[5] = 0;
    fields[6] = 0;
    NiAVObject::CopyMemberData();
    return this;
}

// @fnv 0x00a7fd90
void NiGeometry::OnVisible(NiCullingProcess& process)
{
    process.Append(this);
}

// @fnv 0x00a80b50
void NiGeometry::LinkObject(NiStream& stream)
{
    NiAVObject::LinkObject(stream);
    m_spModelData = (NiGeometryData*)stream.GetLoadedObject();
    *(NiPointer<NiObject>*)&m_spSkinInstance = stream.GetLoadedObject();
}

// @fnv 0x00a80680
void NiGeometry::ReplaceModelData(NiGeometryData* data)
{
    if (data)
    {
        if (m_spCollisionObject)
        {
            struct State
            {
                float value;
                unsigned char flag0;
                unsigned char flag1;
                unsigned char flag2;
                unsigned char flag3;
                unsigned char flag4;
            } state;
            m_spCollisionObject->Unk25();
            state.value = 0.0f;
            state.flag0 = 0;
            state.flag1 = 0;
            state.flag2 = 0;
            state.flag3 = 0;
            state.flag4 = 0;
            m_spCollisionObject->Unk_24(*(NiUpdateData*)&state);
        }
        m_spModelData = data;
    }
}

// @fnv 0x00a80820
void NiGeometry::UpdatePropertiesDownwardPass(NiPropertyState* state)
{
    NiAVObject::UpdatePropertiesDownwardPass(state);
    ((RecursiveSpinLock*)0x011f42a0)->Lock(0);
    NiPropertyState* propertyState = (NiPropertyState*)((char*)this + 0x9c);
    *propertyState = *state;
    NiPropertyNode* node = *(NiPropertyNode**)((char*)this + 0x24);
    while (node)
    {
        NiProperty* property = NiPropertyNode::GetNext(node);
        if (property && property->GetType() <= 7)
            (*(NiPointer<NiProperty>*)&((NiPropertyState*)((char*)this + 0x9c))->m_aspProps[property->GetType()]) = property;
    }
    if (--DAT_011f42a4 == 0)
        DAT_011f42a0 = 0;
    SetMaterialNeedsUpdate(true);
}

// @fnv 0x00a5ac90
// src: XBOX_PDB 0x00a5ac90
void NiAVObject::CopyMembers_00a5ac90(NiAVObject* dest, CloningProcess& process)
{
    ((NiObjectNET*)this)->CopyMemberData((NiObjectNET*)dest, process);
    dest->m_uFlags = m_uFlags | 0x80000;
    dest->m_kLocal = m_kLocal;
    if (m_kPropertyList.m_kItemCount.m_uiCount)
        NiAVObject_CloneProperties(dest, &m_kPropertyList, process);
    if (m_spCollisionObject)
        dest->AssignCollisionObject((NiCollisionObject*)m_spCollisionObject->MakeClone(process));
}

// Copies the previous world bound, and if flags 19/13 conditions or a zero radius apply, allocates or updates m_kWorldBound and refreshes the flag bit 22.
// @fnv 0x00a80710
void NiGeometry::UpdateWorldBound()
{
    NiBound* world = (NiBound*)m_kWorldBound;
    const NiBound& current = PreviousBound(world);
    NiBound previous;
    unsigned int* dst = (unsigned int*)&previous;
    const unsigned int* __restrict src = (const unsigned int*)&current;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    unsigned int& flags = m_uFlags;
    if (!(GetFlag19() && !GetFlag13()) && previous.m_fRadius != 0.0f)
        return;
    {
        if (!world)
        {
            NiBound* allocated = (NiBound*)g_memoryManager.Allocate(16);
            SetObjectBound(allocated);
            ((NiBound*)m_kWorldBound)->SetCenterAndRadius(NiPoint3::ZERO, 0.0f);
        }
        if (m_spSkinInstance)
        {
            ((NiScreenLODData*)m_spSkinInstance.m_pObject)->UpdateScreenBound((NiLODNode*)m_kWorldBound);
            ((NiBound*)m_kWorldBound)->TransformPoint(m_kWorld);
        }
        else
        {
            ((NiBound*)m_kWorldBound)->Update(m_spModelData.m_pObject->m_kBound,
                                 m_kWorld);
        }
        unsigned int savedFlags = flags;
        if ((unsigned char)(savedFlags >> 22) & 1)
        {
            if (((NiBound*)m_kWorldBound)->Object_HasEqualFloatComponents(previous))
                savedFlags |= 0x400000;
            else
                savedFlags &= ~0x400000;
            flags = savedFlags;
        }
    }
}

// @fnv 0x00a80a10
void NiGeometry::ProcessClone(CloningProcess& process)
{
    NiAVObject::ProcessClone(process);

    ShaderBufferRecord* clone = 0;
    process.m_pCloneMap->GetAt((const char*)this, clone);
    NiGeometry* geometryClone = (NiGeometry*)clone;
    if (m_spSkinInstance)
    {
        if (process.m_pCloneMap->GetAt((const char*)m_spSkinInstance.m_pObject, clone))
            *(NiPointer<NiAVObject>*)&geometryClone->m_spSkinInstance = (NiAVObject*)clone;
        else
        {
            *(NiPointer<NiAVObject>*)&geometryClone->m_spSkinInstance =
                (NiAVObject*)((NiObject*)m_spSkinInstance.m_pObject)->MakeClone(process);
            ((NiObject*)m_spSkinInstance.m_pObject)->ProcessClone(process);
        }
    }
    NiD3DShaderInterface* shader = 0;
    if ((unsigned int)m_spShader != (unsigned int)shader)
    {
        unsigned char exactType = NiIsExactKindOf(&DAT_011f5d08, (NiD3DShaderInterface*)m_spShader);
        if (exactType != (unsigned char)(unsigned int)shader)
        {
            // The original allocation is the size of NiShader (0x14).
            void* memory = NiMemObject::operator new(sizeof(NiShader));
            if ((unsigned int)memory != (unsigned int)shader)
                shader = ::new (memory) NiD3DShaderInterface;
            ((NiAVObject*)shader)->SetName(((NiTexture*)m_spShader)->GetFilename());
            // The call uses the MagicCaster subobject address. Compensate for
            // the shared class's secondary-base adjustment before the direct call.
            ((NonActorMagicCaster*)((char*)shader - sizeof(BSExtraData)))
                ->NonActorMagicCaster::SetSelectedMagicItem((MagicItem*)((NiD3DShaderProgram*)m_spShader)->NiD3DShaderProgram::GetName());
            geometryClone->m_spShader = shader;
        }
        else
        {
            geometryClone->m_spShader = m_spShader;
            m_spShader->SetupGeometry(geometryClone);
            ((RecursiveSpinLock*)0x011f42a0)->Lock((const char*)shader);
            geometryClone->UpdatePropertiesDownwardPass((NiPropertyState*)((char*)this + 0x9c));
            if (--DAT_011f42a4 == 0)
                DAT_011f42a0 = (unsigned int)shader;
        }
    }
}

struct NiAccumulator;
struct NiD3DShaderDeclaration;
struct NiDynamicEffectState;
struct NiShader;
struct NiTriShape;
struct NiTriStrips;

struct DummyController
{
    void OnPreDisplayIterate()
    {
        for (DummyController* pkCtrl = this; pkCtrl != 0; pkCtrl = *(DummyController**)((char*)pkCtrl + 0x30))
        {
            (*(void(__thiscall**)(DummyController*))(*(int*)pkCtrl + 0xa8))(pkCtrl);
        }
    }
};

// Stores a pointer to this object's offset 0x9c into the renderer and, if the controller at this+0xc exists, runs its pre-display iterate.
// @fnv 0x00a80610
void NiGeometry::RenderImmediate(NiRenderer* pkRenderer)
{
    pkRenderer->m_pkCurrProp = (NiPropertyState*)((char*)this + 0x9c);
    DummyController* pkController = *(DummyController**)((char*)this + 0xc);
    if (pkController)
        pkController->OnPreDisplayIterate();
}

struct BSStripParticleSystem;
struct NiAccumulator;
struct NiColorA;
struct NiD3DShaderDeclaration;
struct NiDynamicEffectState;
struct NiPSysModifier;
struct NiParticleSystem;
struct NiParticles;
struct NiQuaternion;
struct NiShader;
struct NiTriShape;
struct NiTriStrips;
struct NiUpdateData;

// Stores a pointer to this+0x9C in the renderer and calls the virtual at offset 0xA8 on each node in the linked list at this+0x0C.
// @fnv 0x00a80650
void NiGeometry::RenderWithRenderer(NiRenderer* pkRenderer)
{
    pkRenderer->m_pkCurrProp = (NiPropertyState*)((char*)this + 0x9C);
    void* pNode = *(void**)((char*)this + 0x0C);
    while (pNode)
    {
        (*(void(__thiscall**)(void*))(*(int*)pNode + 0xA8))(pNode);
        pNode = *(void**)((char*)pNode + 0x30);
    }
}

struct BSResizableTriShape;
struct NiTriBasedGeom;
struct NiTriShape;
struct blob16
{
    char b[16];
};


// Calls FUN_00a5a450, then if the field at offset 0xbc is nonzero sets flags 4 and 2 at 0x30, sets *bSelectiveUpdate true and *bRigid false.
// @fnv 0x00a808f0
void NiGeometry::SetSelectiveUpdateFlags(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms,
                                                    bool& bRigid)
{
    NiAVObject::SetSelectiveUpdateFlags(bSelectiveUpdate, bSelectiveUpdateTransforms, bRigid);
    if (*(int*)((char*)this + 0xbc) != 0)
    {
        *(unsigned int*)((char*)this + 0x30) |= 4;
        bSelectiveUpdate = true;
        *(unsigned int*)((char*)this + 0x30) |= 2;
        bRigid = false;
    }
}

class BSPackedAdditionalGeometryData;
class BSResizableTriShape;
class Ni2DBuffer;
class NiAccumulator;
class NiColorA;
class NiD3DGeometryGroupManager;
class NiD3DPixelShader;
class NiD3DShaderDeclaration;
class NiD3DVertexShader;
class NiDepthStencilBuffer;
class NiDynamicEffect;
class NiDynamicGeometryGroup;
class NiGeometryBufferData;
class NiLines;
class NiMaterialProperty;
class NiPalette;
class NiParticles;
class NiParticlesData;
class NiPixelData;
class NiPixelFormat;
class NiPoint2;
class NiRenderTargetGroup;
class NiRenderedCubeMap;
class NiRenderedTexture;
class NiScreenTexture;
class NiShader;
class NiSkinData;
class NiSkinInstance;
class NiSkinPartition;
class NiSourceCubeMap;
class NiSourceTexture;
class NiTimeController;
class NiTriBasedGeom;
class NiTriShape;
class NiTriStrips;
class NiUnsharedGeometryGroup;
class NiUpdateData;
namespace fnv_00a80930 {
struct FourComponentFloatVector;
struct GeometryDeviceType;
struct Direct3DDeviceInterface;
struct COMBaseInterface;
struct GeometryRelatedType;
struct NiDX9BufferManager;
struct Direct3DRenderState;
struct Direct3D9RenderSystem;
struct COMUnknownInterface;
struct RenderableGeometry;
struct Direct3D;
struct NiDynamicEffectState;
struct GeometryObject;
struct NiFragmentMaterial;
struct GeometryVertexData;
struct GeometryContainer;
struct GeometryBufferView;
struct LevelOfDetailNode;
struct RendererSupportType;
struct NiVBChip;
struct VertexBufferRelatedType;
struct IndexBufferManager;
struct ShaderPassRenderer;
struct ShaderPassRenderContext;
struct GraphicsRenderer;
struct RendererShaderPassContext;
struct NiD3DVertexDeclaration;
struct Direct3DPresentationState;
struct Direct3DRendererState;
struct VertexDeclarationLayout;
struct _D3DPRESENT_PARAMETERS_;
struct Direct3DResourceRecord;
struct _D3DVERTEXELEMENT9;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};

struct TimeCtrlView
{
    virtual void v00();
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
    virtual bool IsTargetCtrl();
    char pad[0x2c];
    TimeCtrlView* next;
};
struct SkinView
{
    char pad[0xc];
    void* partition;
};
// Scans the controller list and skin partition, then passes a consistency flag (0x4000 or 0) to the object at offset 0xb8.
// @fnv 0x00a80930
} // namespace fnv_00a80930

void NiGeometry::CalculateConsistency(bool bTool)
{
    int eConsistency = 0x4000;
    fnv_00a80930::TimeCtrlView* pkController = *(fnv_00a80930::TimeCtrlView**)((char*)this + 0xc);
    while (pkController)
    {
        if (pkController->IsTargetCtrl())
        {
            eConsistency = 0;
            break;
        }
        pkController = pkController->next;
    }
    fnv_00a80930::SkinView* pkSkin = *(fnv_00a80930::SkinView**)((char*)this + 0xbc);
    if (pkSkin)
    {
        if (bTool)
        {
            if (!pkSkin->partition)
                eConsistency = 0;
        }
        else if (!pkSkin->partition)
        {
            eConsistency = 0;
        }
        else
        {
            NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
            if (pkRenderer && !((*(unsigned int(__thiscall**)(NiRenderer*))(*(char**)pkRenderer + 0xa0))(pkRenderer) & 2))
                eConsistency = 0;
        }
    }
    m_spModelData.m_pObject->SetDataConsistency(eConsistency);
}


// Registers the model data and skin instance after registering the geometry.
// @fnv 0x00a80430
bool NiGeometry::RegisterStreamables(NiStream& kStream)
{
    if (!FUN_00a59f00(kStream))
        return false;
    m_spModelData.m_pObject->RegisterStreamables(kStream);
    NiObject* pSecondRegObj = (NiObject*)m_spSkinInstance.m_pObject;
    if (pSecondRegObj)
        pSecondRegObj->RegisterStreamables(kStream);
    return true;
}


extern const char* const g_011f4a48_arg1;

// @fnv 0x00a80530
const NiRTTI* NiGeometry::GetRTTI() const
{
    return (const NiRTTI*)&g_011f4a48_arg1;
}

// @fnv 0x00a809b0
void NiGeometry::PurgeRendererData(NiRenderer* pkRenderer)
{
    NiAVObject::PurgeRendererData(pkRenderer);
    (*(void(__thiscall**)(NiRenderer*, void*))(*(char**)pkRenderer + 0xf0))(
        pkRenderer, *(void**)((char*)this + 0xb8));
    void* p = *(void**)((char*)this + 0xbc);
    if (p)
    {
        (*(void(__thiscall**)(NiRenderer*, void*))(*(char**)pkRenderer + 0x104))(pkRenderer, p);
        (*(void(__thiscall**)(NiRenderer*, void*))(*(char**)pkRenderer + 0x100))(
            pkRenderer, *(void**)((char*)*(void**)((char*)this + 0xbc) + 0xc));
    }
}

// @fnv 0x00a7ff60

void NiGeometry::CalculateNormals()
{
    m_spModelData.m_pObject->vf40();
}


// @fnv 0x00a80470
bool NiGeometry::IsEqual(NiObject* object) const
{
    NiGeometry* apData = (NiGeometry*)object;
    if (!const_cast<NiGeometry*>(this)->FUN_00a5a260(apData))  // NiAVObject::IsEqual
        return false;

    const NiObject* thisBC = (const NiObject*)m_spSkinInstance.m_pObject;
    const NiObject* argBC = (const NiObject*)apData->m_spSkinInstance.m_pObject;

    bool argIsNull = (argBC == 0);
    bool bThisBCNull = (thisBC == 0);
    if (bThisBCNull != argIsNull)
        return false;

    if (thisBC != 0)
    {
        if (!thisBC->IsEqual((NiObject*)argBC))
            return false;
    }

    const NiObject* pThisB8 = (const NiObject*)m_spModelData.m_pObject;
    const NiObject* other = (const NiObject*)apData->m_spModelData.m_pObject;
    bool bResult = pThisB8->IsEqual((NiObject*)other);
    return bResult;
}

extern const char* DAT_011f4acc;
char* NiViewerStrings_NiGetViewerString_Title(const char*);
char* NiGetViewerString_00a7d5a0(const char*, const void*);
char* NiGetViewerString_00a7d5e0(const char*, const char*);
char* NiGetViewerString_00a7d510(const char*, unsigned int);
struct ViewerStrings
{
    void* vtable;
    char** entries;
    unsigned short capacity, count, effectiveSize, growBy;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
    void Add(char* text)
    {
        unsigned int index = count;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        FUN_0096ae90(index, text);
    }
};
struct SkinPartition
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int count;
    unsigned int GetCount() const
    {
        return count;
    }
};
struct SkinInstanceInfo : NiObject
{
    unsigned int unk08;
    SkinPartition* partition;
};
// @fnv 0x00a80e70
void NiGeometry::GetViewerStrings(NiViewerStringsArray* array)
{
    ViewerStrings* strings = (ViewerStrings*)array;
    FUN_00a5ad00(strings);
    strings->Add(NiViewerStrings_NiGetViewerString_Title(DAT_011f4acc));
    strings->Add(NiGetViewerString_00a7d5a0("GeomData", static_cast<NiGeometryData*>(m_spModelData)));
    NiD3DShaderInterface* shader = (NiD3DShaderInterface*)m_spShader;
    if (shader)
        strings->Add(NiGetViewerString_00a7d5e0("shader", shader->GetRTTI()->GetName()));
    SkinInstanceInfo* skin = reinterpret_cast<SkinInstanceInfo*>(m_spSkinInstance.m_pObject);
    if (skin && skin->partition)
        strings->Add(NiGetViewerString_00a7d510("skin partitions", skin->partition->GetCount()));
}

extern char* g_pcEmptyFixedString;

struct GeomFixedString
{
    char* m_handle;
    GeomFixedString() throw()
    {
        m_handle = g_pcEmptyFixedString;
    }
    ~GeomFixedString() throw()
    {
        if (m_handle != g_pcEmptyFixedString)
            InterlockedDecrement((long volatile*)(m_handle - 8));
    }
};

struct GeomBinaryStream
{
    typedef unsigned int(__cdecl* ReadFn)(GeomBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    ReadFn m_pfnRead;
    unsigned int Read(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                      unsigned int uiNumComponents) throw()
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void BinaryStreamLoad(GeomBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls) throw()
{
    unsigned int uiSize = sizeof(T);
    pkIstr->Read(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}

struct GeomStream;
void LoadUIntBinary(GeomStream& stream, unsigned int& value) throw();

struct GeomStream
{
    void ResetStreamState() throw();
    void ReadStringTableEntry(GeomFixedString& value) throw();
    void ReadFixedString(GeomFixedString& value) throw();
    unsigned int GetFileVersion() const
    {
        return m_uiNifVersion;
    }
    template <class T> void LoadRaw(T& value) throw()
    {
        BinaryStreamLoad(m_pUnderlyingStream, &value, 1);
    }
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int m_uiNifVersion;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    GeomBinaryStream* m_pUnderlyingStream;
};


// @fnv 0x00a80bf0
void NiGeometry::LoadBinary(NiStream& stream)
{
    GeomStream& kStream = (GeomStream&)stream;
    NiAVObject::LoadBinary((NiStream&)kStream);

    kStream.ResetStreamState();
    kStream.ResetStreamState();

    if (kStream.GetFileVersion() >= 0x14020005)
    {
        unsigned int uiNumMaterials = 0;
        kStream.LoadRaw(uiNumMaterials);
        for (unsigned int i = 0; i < uiNumMaterials; i++)
        {
            GeomFixedString kMaterialName;
            kStream.ReadStringTableEntry(kMaterialName);
            unsigned int uiMaterialExtraData;
            kStream.LoadRaw(uiMaterialExtraData);
        }
        unsigned int uiActiveMaterial;
        kStream.LoadRaw(uiActiveMaterial);
    }
    else if (kStream.GetFileVersion() >= 0x05000015)
    {
        bool bHasShader = false;
        kStream.LoadRaw(bHasShader);
        if (bHasShader)
        {
            GeomFixedString kShaderName;
            if (kStream.GetFileVersion() < 0x14010001)
                kStream.ReadFixedString(kShaderName);
            else
                kStream.ReadStringTableEntry(kShaderName);
            unsigned int uiImplementation;
            LoadUIntBinary(kStream, uiImplementation);
        }
    }

    if (kStream.GetFileVersion() >= 0x14020007)
    {
        bool m_bDataDirty = false;
        kStream.LoadRaw(m_bDataDirty);
    }
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes,
                                               unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesWritten = m_pfnWrite(this, buffer, bytes, componentSizes, componentCount);
    m_uiAbsoluteCurrentPos += bytesWritten;
    return bytesWritten;
}

template <class T> inline void SaveBinaryValue(NiBinaryStream* stream, T& value)
{
    unsigned int componentSize = sizeof(T);
    stream->BinaryWrite(&value, sizeof(T), &componentSize, 1);
}

// @fnv 0x00a80db0
void NiGeometry::SaveBinary(NiStream& stream)
{
    NiAVObject::SaveBinary(stream);
    stream.SaveLinkID(m_spModelData.m_pObject);
    stream.SaveLinkID((NiObject*)m_spSkinInstance.m_pObject);
    unsigned int uiData0 = 0;
    SaveBinaryValue(stream.m_pkOstr, uiData0);
    {
        unsigned int uiData1 = 0;
        SaveBinaryValue(stream.m_pkOstr, uiData1);
    }
    unsigned char ucData2 = 0;
    SaveBinaryValue(stream.m_pkOstr, ucData2);
}

class NiObjectNET_stub
{
  public:
    void NiObjectNET_PostLinkObject(int);
    void NiGeometry_PostLinkObject(int);
};

// @fnv 0x00a7fdc0
// src: XBOX_PDB 0x00a7fdc0
void NiObjectNET_stub::NiGeometry_PostLinkObject(int a1)
{
    NiObjectNET_PostLinkObject(a1);
}

// @fnv 0x00a804e0
NiGeometry::NiGeometry(NiGeometryData* apModelData) : m_spModelData(apModelData)
{
    m_spShader = 0;
}

struct WideProduct
{
    const float& a;
    const float& b;
    WideProduct(const float& x, const float& y) : a(x), b(y)
    {}
    operator double() const
    {
        return a * b;
    }
};
struct S00a7ff70_P3
{
    float x, y, z;
    S00a7ff70_P3()
    {}
    S00a7ff70_P3(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth)
    {}
    S00a7ff70_P3 operator+(const S00a7ff70_P3& p) const
    {
        return S00a7ff70_P3(x + p.x, y + p.y, z + p.z);
    }
    S00a7ff70_P3 operator-(const S00a7ff70_P3& p) const
    {
        return S00a7ff70_P3(x - p.x, y - p.y, z - p.z);
    }
    S00a7ff70_P3 operator/(float s) const
    {
        float inv = 1.0f / s;
        return S00a7ff70_P3(inv * x, inv * y, inv * z);
    }
};
struct GeometryMatrix
{
    float m_afEntries[3][3];
    GeometryMatrix FUN_0043f8d0(const GeometryMatrix& o) const;
    GeometryMatrix FUN_00a588a0(const GeometryMatrix& o) const;
    bool FUN_004b46a0(GeometryMatrix& inv) const;
    S00a7ff70_P3 operator*(const S00a7ff70_P3& p) const
    {
        return S00a7ff70_P3(m_afEntries[0][0] * p.x + m_afEntries[0][1] * p.y + m_afEntries[0][2] * p.z,
                            m_afEntries[1][0] * p.x + m_afEntries[1][1] * p.y + m_afEntries[1][2] * p.z,
                            m_afEntries[2][0] * p.x + m_afEntries[2][1] * p.y + m_afEntries[2][2] * p.z);
    }
    S00a7ff70_P3 FirstProduct(const S00a7ff70_P3& p) const
    {
        return S00a7ff70_P3(m_afEntries[0][0] * p.x + m_afEntries[0][1] * p.y + WideProduct(m_afEntries[0][2], p.z),
                            WideProduct(m_afEntries[1][0], p.x) + m_afEntries[1][1] * p.y + m_afEntries[1][2] * p.z,
                            WideProduct(m_afEntries[2][0], p.x) + m_afEntries[2][1] * p.y + m_afEntries[2][2] * p.z);
    }
};
inline S00a7ff70_P3 operator*(const S00a7ff70_P3& p, const GeometryMatrix& m)
{
    return S00a7ff70_P3(m.m_afEntries[0][0] * p.x + m.m_afEntries[1][0] * p.y + m.m_afEntries[2][0] * p.z,
                        m.m_afEntries[0][1] * p.x + m.m_afEntries[1][1] * p.y + m.m_afEntries[2][1] * p.z,
                        m.m_afEntries[0][2] * p.x + m.m_afEntries[1][2] * p.y + m.m_afEntries[2][2] * p.z);
}
// Updates the vertices, normals, and model bound using the supplied transform.
// @fnv 0x00a7ff70
void NiGeometry::ApplyTransform(const NiMatrix3& rotation, const NiPoint3& position, bool bOnLeft)
{
    unsigned short usVertices = m_spModelData.m_pObject->GetVertexCount();
    S00a7ff70_P3* pkVertex = (S00a7ff70_P3*)m_spModelData.m_pObject->m_pkVertex;
    S00a7ff70_P3* pkNormal = (S00a7ff70_P3*)m_spModelData.m_pObject->m_pkNormal;
    unsigned short i;
    if (bOnLeft)
    {
        const GeometryMatrix& kRot = ((const GeometryMatrix&)m_kLocal.m_Rotate).FUN_00a588a0((*(const GeometryMatrix*)&rotation).FUN_0043f8d0((const GeometryMatrix&)m_kLocal.m_Rotate));
        S00a7ff70_P3 kTrans =
            (((*(const S00a7ff70_P3*)&position) + (*(const GeometryMatrix*)&rotation) * (*(const S00a7ff70_P3*)&m_kLocal.m_Translate) - (*(const S00a7ff70_P3*)&m_kLocal.m_Translate)) * (const GeometryMatrix&)m_kLocal.m_Rotate) /
            m_kLocal.m_fScale;
        if (pkVertex)
        {
            for (i = 0; i < usVertices; i++)
                pkVertex[i] = kRot.FirstProduct(pkVertex[i]) + kTrans;
        }
        if (pkNormal)
        {
            GeometryMatrix kInv;
            kRot.FUN_004b46a0(kInv);
            for (i = 0; i < usVertices; i++)
                pkNormal[i] = pkNormal[i] * kInv;
        }
    }
    else
    {
        if (pkVertex)
        {
            for (i = 0; i < usVertices; i++)
                pkVertex[i] = (*(const GeometryMatrix*)&rotation) * pkVertex[i] + (*(const S00a7ff70_P3*)&position);
        }
        if (pkNormal)
        {
            GeometryMatrix kInv;
            (*(const GeometryMatrix*)&rotation).FUN_004b46a0(kInv);
            for (i = 0; i < usVertices; i++)
                pkNormal[i] = pkNormal[i] * kInv;
        }
    }
    m_spModelData.m_pObject->m_kBound.ComputeBoundingSphere(usVertices, (const NiPoint3*)pkVertex);
}
