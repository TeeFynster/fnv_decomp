#pragma once

#include "NiGPUProgram.h"

class NiRTTI;
class NiD3DShaderProgramCreator;
class NiD3DRenderer;
class Direct3DDeviceInterface;
class GraphicsRenderer;
class ShaderPassRenderer;
class NiShaderConstantMapEntry;
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

class NiD3DShaderProgram : public NiGPUProgram
{
public:
    NiD3DShaderProgram(NiD3DRenderer* pkRenderer, int iType) throw();
    NiD3DShaderProgram(void* pkRenderer, int eType) throw();

    virtual ~NiD3DShaderProgram();
    virtual void DeleteThis();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* IsSceneNode();
    virtual BSFadeNode* IsFadeNode();
    virtual BSMultiBoundNode* IsMultiBoundNode();
    virtual NiGeometry* IsGeometry();
    virtual NiTriBasedGeom* IsTriBasedGeom();
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
    virtual unsigned int GetNumberOfVariables();
    virtual char* GetVariableName(unsigned int);
    virtual char* GetName();
    virtual void SetName(char*);
    virtual char* GetProgramProfile();
    virtual void SetShaderProfile(char*);
    virtual unsigned int GetCodeSize();
    virtual void* GetCode();
    virtual void SetProgramCode(unsigned int, void*);
    virtual NiD3DShaderProgramCreator* GetCreator();
    virtual void SetCreator(NiD3DShaderProgramCreator*);
    virtual bool SetShaderConstant(NiShaderConstantMapEntry*, void*, unsigned int);
    virtual bool SetShaderConstantArray(NiShaderConstantMapEntry*, void*, unsigned int,
                                        unsigned int, unsigned short*);

    unsigned int GetCodeSize() const;
    void UpdateFields_00e89840();
    void SetCreator_00eea540(NiD3DShaderProgramCreator* pkCreator);
    void* DestroyIfFlagged(unsigned int flags);
    void SetShaderCode(unsigned int uiSize, void* pvCode);
    void SetD3DDevice(Direct3DDeviceInterface*);
    void SetD3DRenderState(ShaderPassRenderer*);
    void SetShaderObject(GraphicsRenderer*);
    void SetVertexShaderConstant(int, int, float*);
    void SetPixelShaderConstant(int, int, float*);

    char* m_pcProgramName;
    char* m_pcProfile;
    unsigned int m_uiProgramCodeSize;
    void* m_pProgramCode;
    NiD3DShaderProgramCreator* m_pCreator;
    Direct3DDeviceInterface* m_pD3DDevice;
    GraphicsRenderer* m_pShaderObject;
    ShaderPassRenderer* m_pRenderState;
};
