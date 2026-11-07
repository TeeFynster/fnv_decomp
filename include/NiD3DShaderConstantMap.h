#pragma once
#define FNV64_NITOBJECTARRAY_SHADER_ENTRIES
#include "NiTObjectArray.h"

#include "NiShaderConstantMap.h"
#include "NiAVObject.h"
#include "NiSkinPartition.h"
#include "NiShaderConstantMapEntry.h"

class NiD3DShaderProgram;
class Direct3DDeviceInterface;
class GraphicsRenderer;
class ShaderPassRenderer;
class NiGeometry;
class NiSkinInstance;
class NiGeometryBufferData;
class ConstantEntry;
struct Program;
struct Skin;
struct Properties;
struct Effects;

class NiD3DShaderConstantMap : public NiShaderConstantMap
{
public:
    NiD3DShaderConstantMap(GraphicsRenderer*, unsigned int);
    NiD3DShaderConstantMap(GraphicsRenderer*, NiGPUProgram__ProgramType);
    NiD3DShaderConstantMap(void*, int);
    NiD3DShaderConstantMap(unsigned int, unsigned int);
    virtual ~NiD3DShaderConstantMap();

    virtual unsigned int vfn_28();
    virtual unsigned int vfn_2c();
    virtual unsigned int vfn_30();
    virtual unsigned int vfn_34();
    virtual unsigned int vfn_38();
    virtual unsigned int vfn_3c();
    virtual unsigned int vfn_40();
    virtual unsigned int vfn_44();
    virtual unsigned int vfn_48();
    virtual unsigned int vfn_4c();
    virtual unsigned int vfn_50();
    virtual unsigned int vfn_54();
    virtual unsigned int vfn_58();
    virtual unsigned int vfn_5c();
    virtual unsigned int vfn_60();
    virtual unsigned int vfn_64();
    virtual unsigned int AddConstant8(const char*, unsigned int, unsigned int, const char*,
                                      unsigned int, unsigned int, const void*, bool);
    virtual unsigned int vfn_6c();
    virtual NiShaderConstantMapEntry* GetEntry(const char*);
    virtual ConstantEntry* GetEntry(unsigned int);
    virtual unsigned int ConfigureShaderConstantMap(
        NiD3DShaderProgram*, NiGeometry*, const NiSkinInstance*, const NiSkinPartition::Partition*,
        NiGeometryBufferData*, const NiPropertyState*, const NiDynamicEffectState*,
        const NiTransform&, const NiBound&, unsigned int, bool);
    virtual unsigned int vfn_7c();
    virtual int vfn_80(NiShaderConstantMapEntry*);
    virtual unsigned int vfn_84();
    virtual unsigned int vfn_88();
    virtual unsigned int vfn_8c(
        NiD3DShaderProgram*, NiShaderConstantMapEntry*, NiGeometry*, const NiSkinInstance*,
        const NiSkinPartition::Partition*, NiGeometryBufferData*, const NiPropertyState*,
        const NiDynamicEffectState*, const NiTransform&, const NiBound&, unsigned int);
    virtual unsigned int vfn_90(NiD3DShaderProgram*, NiShaderConstantMapEntry*, unsigned int);
    virtual unsigned int vfn_94(
        NiD3DShaderProgram*, NiShaderConstantMapEntry*, NiGeometry*, const NiSkinInstance*,
        const NiSkinPartition::Partition*, NiGeometryBufferData*, const NiPropertyState*,
        const NiDynamicEffectState*, const NiTransform&, const NiBound&, unsigned int, bool, NiExtraData*);
    virtual unsigned int vfn_98(NiD3DShaderProgram*, NiShaderConstantMapEntry*, unsigned int);
    virtual unsigned int vfn_9c(
        NiD3DShaderProgram*, NiShaderConstantMapEntry*, NiGeometry*, const NiSkinInstance*,
        const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&, unsigned int);
    virtual unsigned int vfn_a0();
    virtual unsigned int vfn_a4(
        NiD3DShaderProgram*, NiShaderConstantMapEntry*, NiGeometry*, const NiSkinInstance*,
        const NiSkinPartition::Partition*, NiGeometryBufferData*, const NiPropertyState*,
        const NiDynamicEffectState*, const NiTransform&, const NiBound&, unsigned int);

    void IncRefCount();
    void DecRefCount();
    void* __thiscall Destroy(unsigned int);
    NiD3DShaderConstantMap& operator=(const NiD3DShaderConstantMap&);

    unsigned int AddConstant(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                             const char*, unsigned int, unsigned int, const void*, bool);
    unsigned int AddConstant10(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                               const char*, unsigned int, unsigned int, const void*, bool);
    unsigned int AddEntry(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                          const char*, unsigned int, unsigned int, const void*, bool);
    unsigned int AddEntry(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                          const char*, unsigned int, unsigned int, void*, bool);
    void Add(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
             const char*, unsigned int, unsigned int, void*, unsigned int);
    unsigned int LookupSequenceByKey(const char*);
    unsigned int ConfigureShaderConstantMap(
        NiD3DShaderProgram*, NiGeometry*, const NiSkinInstance*, const void*, NiGeometryBufferData*,
        const NiPropertyState*, const void*, const NiTransform&, const NiBound&, unsigned int, bool);
    void NiD3DShaderConstantMap_SetD3DRenderer(unsigned int);
    void ResetShaderConstantMap();
    void ClearShaderConstantEntries(NiTObjectArray<NiPointer<NiShaderConstantMapEntry> >*);
    void Update();
    unsigned int NiD3DShaderConstantMap_SetDefinedConstant(
        Program*, NiShaderConstantMapEntry*, NiAVObject*, Skin*, NiSkinPartition::Partition*,
        void*, Properties*, Effects*, const void*, const void*, unsigned int);

    NiTObjectArray<NiPointer<NiShaderConstantMapEntry> > m_kEntries;
    NiTObjectArray<NiPointer<NiShaderConstantMapEntry> > m_kDefinedEntries;
    bool m_bHasChanges;
    unsigned char layoutPadding2D[3];
    NiD3DShaderProgram* m_pShaderProgram;
    unsigned int m_uiErrorCode;
    Direct3DDeviceInterface* m_pD3DDevice;
    GraphicsRenderer* m_pShaderObject;
    ShaderPassRenderer* m_pRenderState;
};
