#pragma once

#include "NiRefObject.h"
#include "NiFixedString.h"
#include "NiSkinPartition.h"
#include "NiAlphaProperty.h"

class NiRTTI;
class NiAVObject;
class NiNode;
class BSFadeNode;
class BSMultiBoundNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class BSResizableTriShape;
class NiParticles;
class NiLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;
class NiSkinInstance;
class NiGeometryBufferData;
class NiPropertyState;
class NiDynamicEffectState;
class NiTransform;
class NiBound;
class NiShaderDeclaration;
class NiD3DShaderDeclaration;
class NiShaderConstantMap;
class NiGPUProgram;

class NiShader : public NiRefObject
{
  public:
    class NiShaderInstanceDescriptor
    {
      public:
        virtual void* vf00();
        virtual void vf01();
        virtual void vf02();
        virtual void vf03();
        virtual void vf04();
        virtual void vf05();
        virtual void vf06();
        virtual void vf07();
        virtual void vf08();
        virtual void vf09();
        virtual void vf10();
        virtual void vf11();
        virtual void vf12();
        virtual void vf13();
        virtual void vf14();
        virtual void vf15();
        virtual void* __thiscall vf16(unsigned int mode);
    };

    NiShader();
    virtual ~NiShader();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* IsNiNode();
    virtual BSFadeNode* IsFadeNode();
    virtual BSMultiBoundNode* IsMultiBoundNode();
    virtual NiGeometry* IsGeometry();
    virtual NiTriBasedGeom* IsTriBasedGeometry();
    virtual NiTriStrips* IsTriStrips();
    virtual NiTriShape* IsTriShape();
    virtual BSSegmentedTriShape* IsSegmentedTriShape();
    virtual BSResizableTriShape* IsResizableTriShape();
    virtual NiParticles* IsParticlesGeom();
    virtual NiLines* IsLineGeometry();
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject();
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject();
    virtual bhkRigidBody* IsBhkRigidBody();
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint();
    virtual bool IsFormInitialized();
    virtual bool Initialize();
    virtual bool SetupGeometry(NiGeometry* apGeometry);
    virtual unsigned int GetGeometryRenderCount(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                          NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                          const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                          const NiBound& arWorldBound);
    virtual void SetupGeometryShader(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                     NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                     const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                     const NiBound& arWorldBound);
    virtual void UpdateGeometryEffects(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                       NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                       const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                       const NiBound& arWorldBound);
    virtual unsigned int RenderPartitionedSkinGeometry(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                                 const NiSkinPartition::Partition* apPartition,
                                                 NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                                 const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                                 const NiBound& arWorldBound);
    virtual unsigned int SetupTransformationsAlt(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                           const NiSkinPartition::Partition* apPartition,
                                           NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                           const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                           const NiBound& arWorldBound);
    virtual unsigned int RenderPartitionedGeometry(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                             const NiSkinPartition::Partition* apPartition,
                                             NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                             const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                             const NiBound& arWorldBound);
    virtual NiGeometryBufferData* vPrepareGeometryForRendering(NiGeometry* apGeometry,
                                                               const NiSkinPartition::Partition* apPartition,
                                                               NiGeometryBufferData* apRendererData,
                                                               const NiPropertyState* apState);
    virtual unsigned int GetGeometryPassCount(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                        const NiSkinPartition::Partition* apPartition,
                                        NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                        const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                        const NiBound& arWorldBound);
    virtual unsigned int RenderUnpartitionedGeometry(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                               NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                               const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                               const NiBound& arWorldBound);
    virtual void SetupTextures(NiPropertyState* apState);
    virtual void UpdateConstants(NiPropertyState* apState);
    virtual void SetBlendAlpha(NiPropertyState* apState);
    virtual void SetTestAlpha(NiPropertyState* apState);
    virtual void PreRenderSetup(NiPropertyState* apState, bool abFirstPass);
    virtual void PostRenderSetup(NiPropertyState* apState);
    virtual int HasPasses();
    virtual int GetMaxPasses();
    virtual void StreamCanSkip();
    virtual NiShaderDeclaration* BuildShaderDeclaration(unsigned int auiMaxStreamEntryCount, unsigned int auiStreamCount = 1);
    virtual bool GetNextPass(unsigned int& auiPassId);
    virtual bool SetAlphaBlend(unsigned int auiPassId, bool abAlphaBlend, bool abUsePreviousSrcBlendMode,
                               NiAlphaProperty::AlphaFunction aeSrcBlendMode, bool abUsePreviousDestBlendMode,
                               NiAlphaProperty::AlphaFunction aeDestBlendMode);
    virtual void SetUsesVertexShader(bool abUses);
    virtual bool BindGPUProgram(unsigned int auiPassId, NiGPUProgram* apProgram, unsigned int& auiProgramId);
    virtual NiShaderConstantMap* CreateShaderConstantMap(unsigned int auiPassId, unsigned int auiProgramId);
    virtual bool ResolveSamplerId(unsigned int auiPassId, unsigned int& auiSamplerId, const NiFixedString& arSemantic,
                                  const NiFixedString& arVariableName, unsigned int auiInstance = 0);
    virtual void* GetShaderInstanceDesc();
    NiShader& operator=(const NiShader& shader);
    void UseShaderDeclaration(NiD3DShaderDeclaration* declaration);
    static NiAVObject* __cdecl DynamicCast(NiAVObject* object);
    NiShader* DynamicCast(const NiRTTI* type);
    bool IsKindOfType(const NiRTTI* type) const;
    const NiFixedString& GetFilename() const;
    void __thiscall SetRandomColorRenderStates(unsigned int, unsigned int, unsigned int,
                                               unsigned int, unsigned int, unsigned int,
                                               unsigned int);

    NiFixedString m_kName;
    unsigned int m_uiImplementation;
    bool m_bInitialized;
    unsigned char _pad11[3];
};
