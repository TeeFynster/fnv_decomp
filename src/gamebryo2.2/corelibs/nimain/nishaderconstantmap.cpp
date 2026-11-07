// gamebryo2.2/corelibs/nimain/nishaderconstantmap.cpp: NiShaderConstantMap (10 functions)

#define FNV64_NIFIXEDSTRING_OWN_BODIES
#include "../../../../include/NiShaderConstantMap.h"
#undef FNV64_NIFIXEDSTRING_OWN_BODIES
#include "MemoryManager.h"
extern MemoryManager g_memoryManager;

// Keep the unit-local atomic helper calls: their inline expansion preserves
// the original compiler's constructor and assignment inlining decisions.
inline unsigned int NiAtomicIncrement(unsigned int& value)
{
    return InterlockedIncrement((long*)&value);
}
inline unsigned int NiAtomicSubtract(unsigned int& value)
{
    return InterlockedDecrement((long*)&value);
}
inline void NiShaderConstantMapIncRefCount(char*& handle)
{
    if (handle != NiGlobalStringTable::ms_pcEmptyString)
    {
        char* buffer = NiGlobalStringTable::GetRealBufferStart(handle);
        unsigned int* count = (unsigned int*)buffer;
        NiAtomicIncrement(*count);
    }
}
inline void NiShaderConstantMapDecRefCount(char*& handle)
{
    if (handle != NiGlobalStringTable::ms_pcEmptyString)
    {
        char* buffer = NiGlobalStringTable::GetRealBufferStart(handle);
        unsigned int* count = (unsigned int*)buffer;
        NiAtomicSubtract(*count);
    }
}

inline NiFixedString::NiFixedString()
{
    m_kHandle = NiGlobalStringTable::ms_pcEmptyString;
}

inline NiFixedString::NiFixedString(const char* text)
{
    if (text == 0)
        m_kHandle = NiGlobalStringTable::ms_pcEmptyString;
    else
        m_kHandle = NiGlobalStringTable::AddString(text);
}

inline NiFixedString::~NiFixedString()
{
    NiShaderConstantMapDecRefCount(m_kHandle);
}

inline NiFixedString& NiFixedString::operator=(const NiFixedString& text)
{
    char* handle = text.m_kHandle;
    if (m_kHandle != handle)
    {
        NiShaderConstantMapIncRefCount(handle);
        NiShaderConstantMapDecRefCount(m_kHandle);
        m_kHandle = handle;
    }
    return *this;
}

inline NiFixedString& NiFixedString::operator=(const char* text)
{
    if (m_kHandle != text)
    {
        char* old = m_kHandle;
        m_kHandle = NiGlobalStringTable::AddString(text);
        NiShaderConstantMapDecRefCount(old);
    }
    return *this;
}

inline NiFixedString::operator const char*() const
{
    return m_kHandle;
}

inline NiShaderConstantMap::ShaderConstantMapEntry::ShaderConstantMapEntry()
{
    m_uiConstantID = 0;
    m_kConstantName = (const char*)0;
}

inline NiShaderConstantMap::ShaderConstantMapEntry::ShaderConstantMapEntry(unsigned int id, const NiFixedString& name)
{
    m_uiConstantID = id;
    m_kConstantName = name;
}

inline NiShaderConstantMap::ShaderConstantMapEntry::~ShaderConstantMapEntry()
{}

inline NiShaderConstantMap::ShaderConstantMapEntry&
NiShaderConstantMap::ShaderConstantMapEntry::operator=(const ShaderConstantMapEntry& other)
{
    m_uiConstantID = other.m_uiConstantID;
    m_kConstantName = other.m_kConstantName;
    return *this;
}

inline void* NiShaderConstantMap::ShaderConstantMapEntry::operator new[](unsigned int size) throw()
{
    return g_memoryManager.Allocate(size);
}

extern "C" int strcpy_s(char*, unsigned int, const char*);
// The mutable-source C++ overload is distinct from the CRT entry point.
int strcpy_s(char*, unsigned int, char*);
extern "C" char* strchr(char*, int);
extern "C" int isdigit(int);
extern "C" char* strtok_s(char*, const char*, char**);
long FUN_00eca6d3(const char*);
int NiStricmp(const char*, const char*);

// @fnv 0x00a9c2a0
void NiShaderConstantMap::InitializePoint3()
{
    ms_uiShaderConstantMapEntryCount = 136;
    ms_pkShaderConstantMap = new ShaderConstantMapEntry[ms_uiShaderConstantMapEntryCount];
    unsigned int index = 0;
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(0, NiFixedString("Invalid"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(1, NiFixedString("Proj"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(1, NiFixedString("Projection"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(2, NiFixedString("InvProj"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(2, NiFixedString("InvProjection"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(3, NiFixedString("View"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(4, NiFixedString("InvView"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(5, NiFixedString("World"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(6, NiFixedString("InvWorld"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(7, NiFixedString("WorldView"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(8, NiFixedString("InvWorldView"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(9, NiFixedString("ViewProj"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(9, NiFixedString("ViewProjection"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(10, NiFixedString("InvViewProj"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(10, NiFixedString("InvViewProjection"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(11, NiFixedString("WorldViewProj"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(11, NiFixedString("WorldViewProjection"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(12, NiFixedString("InvWorldViewProj"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(12, NiFixedString("InvWorldViewProjection"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(13, NiFixedString("ProjTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(13, NiFixedString("ProjectionTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(14, NiFixedString("InvProjTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(14, NiFixedString("InvProjectionTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(15, NiFixedString("ViewTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(16, NiFixedString("InvViewTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(17, NiFixedString("WorldTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(18, NiFixedString("InvWorldTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(19, NiFixedString("WorldViewTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(20, NiFixedString("InvWorldViewTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(21, NiFixedString("ViewProjTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(21, NiFixedString("ViewProjectionTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(22, NiFixedString("InvViewProjTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(22, NiFixedString("InvViewProjectionTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(23, NiFixedString("WorldViewProjTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(23, NiFixedString("WorldViewProjectionTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(24, NiFixedString("InvWorldViewProjTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(24, NiFixedString("InvWorldViewProjectionTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(25, NiFixedString("SkinWorldView"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(26, NiFixedString("InvSkinWorldView"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(27, NiFixedString("SkinWorldViewTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(28, NiFixedString("InvSkinWorldViewTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(29, NiFixedString("SkinWorldViewProj"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(29, NiFixedString("SkinWorldViewProjection"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(30, NiFixedString("InvSkinWorldViewProj"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(30, NiFixedString("InvSkinWorldViewProjection"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(31, NiFixedString("SkinWorldViewProjTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(31, NiFixedString("SkinWorldViewProjectionTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(32, NiFixedString("InvSkinWorldViewProjTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(32, NiFixedString("InvSkinWorldViewProjectionTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(33, NiFixedString("BoneMatrix3"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(34, NiFixedString("BoneMatrix4"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(35, NiFixedString("SkinBoneMatrix3"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(36, NiFixedString("SkinBoneMatrix4"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(37, NiFixedString("TexTransformBase"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(38, NiFixedString("InvTexTransformBase"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(39, NiFixedString("TexTransformBaseTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(40, NiFixedString("InvTexTransformBaseTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(41, NiFixedString("TexTransformDark"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(42, NiFixedString("InvTexTransformDark"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(43, NiFixedString("TexTransformDarkTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(44, NiFixedString("InvTexTransformDarkTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(45, NiFixedString("TexTransformDetail"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(46, NiFixedString("InvTexTransformDetail"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(47, NiFixedString("TexTransformDetailTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(48, NiFixedString("InvTexTransformDetailTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(49, NiFixedString("TexTransformGloss"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(50, NiFixedString("InvTexTransformGloss"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(51, NiFixedString("TexTransformGlossTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(52, NiFixedString("InvTexTransformGlossTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(53, NiFixedString("TexTransformGlow"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(54, NiFixedString("InvTexTransformGlow"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(55, NiFixedString("TexTransformGlowTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(56, NiFixedString("InvTexTransformGlowTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(57, NiFixedString("TexTransformBump"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(58, NiFixedString("InvTexTransformBump"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(59, NiFixedString("TexTransformBumpTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(60, NiFixedString("InvTexTransformBumpTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(61, NiFixedString("TexTransformDecal"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(62, NiFixedString("InvTexTransformDecal"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(63, NiFixedString("TexTransformDecalTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(64, NiFixedString("InvTexTransformDecalTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(65, NiFixedString("TexTransformShader"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(66, NiFixedString("InvTexTransformShader"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(67, NiFixedString("TexTransformShaderTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(68, NiFixedString("InvTexTransformShaderTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(69, NiFixedString("LightPosWS"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(70, NiFixedString("LightDirWS"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(71, NiFixedString("LightPosOS"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(72, NiFixedString("LightDirOS"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(73, NiFixedString("MaterialDiffuse"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(73, NiFixedString("Diffuse"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(74, NiFixedString("MaterialAmbient"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(74, NiFixedString("Ambient"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(75, NiFixedString("MaterialSpecular"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(75, NiFixedString("Specular"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(76, NiFixedString("MaterialEmissive"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(77, NiFixedString("MaterialPower"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(77, NiFixedString("SpecularPower"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(78, NiFixedString("EyePos"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(79, NiFixedString("EyeDir"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(80, NiFixedString("TaylorSin"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(81, NiFixedString("TaylorCos"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(82, NiFixedString("time"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(83, NiFixedString("sin_time"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(84, NiFixedString("cos_time"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(85, NiFixedString("tan_time"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(86, NiFixedString("time_sin_cos_tan"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(87, NiFixedString("AmbientLight"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(92, NiFixedString("TexTransformParallax"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(93, NiFixedString("InvTexTransformParallax"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(94, NiFixedString("TexTransformParallaxTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(95, NiFixedString("InvTexTransformParallaxTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(88, NiFixedString("TexTransformNormal"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(89, NiFixedString("InvTexTransformNormal"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(90, NiFixedString("TexTransformNormalTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(91, NiFixedString("InvTexTransformNormalTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(96, NiFixedString("SkinWorld"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(97, NiFixedString("InvSkinWorld"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(98, NiFixedString("SkinWorldTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(99, NiFixedString("InvSkinWorldTranspose"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(100, NiFixedString("FogDensity"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(101, NiFixedString("FogNearFar"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(102, NiFixedString("FogColor"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(103, NiFixedString("BumpMatrix"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(104, NiFixedString("BumpLumaAndScale"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(105, NiFixedString("ParallaxOffset"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(106, NiFixedString("TexSizeBase"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(107, NiFixedString("TexSizeDark"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(108, NiFixedString("TexSizeDetail"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(109, NiFixedString("TexSizeGloss"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(110, NiFixedString("TexSizeGlow"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(111, NiFixedString("TexSizeBump"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(111, NiFixedString("TexSizeNormal"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(111, NiFixedString("TexSizeParallax"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(114, NiFixedString("TexSizeDecal"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[index++];
        entry = ShaderConstantMapEntry(115, NiFixedString("TexSizeShader"));
    }

    ms_uiConstantMapEntryCount = 25;
    ms_pkConstantMap = new ShaderConstantMapEntry[ms_uiConstantMapEntryCount];
    index = 0;
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(0, NiFixedString("Invalid"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(1, NiFixedString("Dimmer"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(2, NiFixedString("UndimmedAmbient"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(3, NiFixedString("UndimmedDiffuse"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(4, NiFixedString("UndimmedSpecular"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(5, NiFixedString("Ambient"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(6, NiFixedString("Diffuse"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(7, NiFixedString("Specular"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(8, NiFixedString("WorldPosition"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(9, NiFixedString("ModelPosition"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(10, NiFixedString("WorldDirection"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(11, NiFixedString("ModelDirection"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(12, NiFixedString("WorldTransform"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(13, NiFixedString("ModelTransform"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(14, NiFixedString("SpotAttenuation"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(15, NiFixedString("Attenuation"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(16, NiFixedString("WorldProjectionMatrix"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(17, NiFixedString("ModelProjectionMatrix"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(18, NiFixedString("WorldProjectionTranslation"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(19, NiFixedString("ModelProjectionTranslation"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(20, NiFixedString("WorldClippingPlane"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(21, NiFixedString("ModelClippingPlane"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(22, NiFixedString("TexCoordGen"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(23, NiFixedString("WorldProjectionTransform"));
    }
    {
        ShaderConstantMapEntry& entry = ms_pkConstantMap[index++];
        entry = ShaderConstantMapEntry(24, NiFixedString("ModelProjectionTransform"));
    }
}

// Copies key into name, and if key ends with _<digit>, strips that suffix and stores the parsed digit in extra.
// @fnv 0x00a9bee0
bool NiShaderConstantMap::ParseConstantName(const char* key, char* name, unsigned int size, unsigned int& extra)
{
    char buffer[260];
    if (sizeof(buffer) > size + 1)
        return false;
    strcpy_s(buffer, sizeof(buffer), key);
    strcpy_s(name, sizeof(buffer), key);
    char* suffix = strchr(buffer, '_');
    if (suffix && isdigit(suffix[1]) && suffix[2] == 0)
    {
        char* context;
        char* prefix = strtok_s(buffer, "_", &context);
        char* number = strtok_s(0, "_", &context);
        if (number)
        {
            extra = FUN_00eca6d3(number);
            strcpy_s(name, size, prefix);
        }
    }
    return true;
}

// @fnv 0x00a9bfd0
bool NiShaderConstantMap::FindConstantMapping(const char* key, unsigned int& mapping, unsigned int& extra)
{
    char name[260];
    if (!ParseConstantName(key, name, sizeof(name), extra))
        return false;
    for (unsigned int i = 0; i < ms_uiShaderConstantMapEntryCount; ++i)
    {
        ShaderConstantMapEntry& entry = ms_pkShaderConstantMap[i];
        if (!NiStricmp(entry.m_kConstantName, name))
        {
            mapping = entry.m_uiConstantID;
            return true;
        }
    }
    return false;
}

enum NiShaderAttributeDesc_AttributeType
{
    NiShaderAttributeDesc_AttributeType_0 = 0,
    NiShaderAttributeDesc_AttributeType_1 = 1,
    NiShaderAttributeDesc_AttributeType_2 = 2,
    NiShaderAttributeDesc_AttributeType_3 = 3,
    NiShaderAttributeDesc_AttributeType_4 = 4,
    NiShaderAttributeDesc_AttributeType_5 = 5,
    NiShaderAttributeDesc_AttributeType_6 = 6,
    NiShaderAttributeDesc_AttributeType_7 = 7,
    NiShaderAttributeDesc_AttributeType_8 = 8,
    NiShaderAttributeDesc_AttributeType_9 = 9,
    NiShaderAttributeDesc_AttributeType_10 = 10,
    NiShaderAttributeDesc_AttributeType_11 = 11,
    NiShaderAttributeDesc_AttributeType_12 = 12,
    NiShaderAttributeDesc_AttributeType_13 = 13,
    NiShaderAttributeDesc_AttributeType_14 = 14,
    NiShaderAttributeDesc_AttributeType_15 = 15,
    NiShaderAttributeDesc_AttributeType_16 = 16,
    NiShaderAttributeDesc_AttributeType_17 = 17,
    NiShaderAttributeDesc_AttributeType_18 = 18,
    NiShaderAttributeDesc_AttributeType_19 = 19,
    NiShaderAttributeDesc_AttributeType_20 = 20,
    NiShaderAttributeDesc_AttributeType_21 = 21,
    NiShaderAttributeDesc_AttributeType_22 = 22,
    NiShaderAttributeDesc_AttributeType_23 = 23,
    NiShaderAttributeDesc_AttributeType_24 = 24
};

// Maps a 1-based mapping ID to an attribute type, setting the register and float counts, returning type 0 for unknown IDs.
// @fnv 0x00a9bcd0
NiShaderAttributeDesc_AttributeType __cdecl GetAttributeTypeForMapping(unsigned int uiMappingID,
                                                                       unsigned int& uiRegCount,
                                                                       unsigned int& uiFloatCount)
{
    uiMappingID--;
    uiRegCount = 1;
    uiFloatCount = 4;
    if (uiMappingID > 0x17)
        return NiShaderAttributeDesc_AttributeType_0;
    switch (uiMappingID)
    {
    case 0:
    case 21:
        uiFloatCount = 1;
        return NiShaderAttributeDesc_AttributeType_4;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 13:
    case 14:
    case 17:
    case 18:
    case 19:
    case 20:
        return NiShaderAttributeDesc_AttributeType_7;
    case 11:
    case 12:
    case 22:
    case 23:
        uiRegCount = 4;
        uiFloatCount = 0x10;
        return NiShaderAttributeDesc_AttributeType_9;
    case 15:
    case 16:
        uiRegCount = 3;
        uiFloatCount = 0xc;
        return NiShaderAttributeDesc_AttributeType_8;
    default:
        return NiShaderAttributeDesc_AttributeType_0;
    }
}

// @fnv 0x00a9bd60
// src: COMMUNITY 0x00a9bd60
unsigned int __stdcall NiShaderConstantMap_AddEntryAlt(const char*, unsigned int, unsigned int, const char*)
{
    return 0x30;
}

// @fnv 0x00a9bd70
// src: COMMUNITY 0x00a9bd70
int __stdcall NiShaderConstantMap_AddEntry(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
    return 0x30;
}

// @fnv 0x00a9bd80
// src: COMMUNITY 0x00a9bd80
int __stdcall NiShaderConstantMap_AddOperatorEntry(int a, int b, int c, int d, int e, int f)
{
    return 0x30;
}

// @fnv 0x00a9bd90
// src: COMMUNITY 0x00a9bd90
unsigned int __stdcall NiShaderConstantMap_AddObjectEntry(const char* pszKey, unsigned int uiShaderRegister, const char* pszVariableName,
                                    unsigned int uiObjectIndex, int eObjectType)
{
    return 0x30;
}

extern int __cdecl _NiStricmp(const char*, const char*);

// Searches the shader constant map table for a case-insensitive name match and writes the matching entry's ID to uiMappingID, returning true if found.
// @fnv 0x00a9c0e0
bool __cdecl LookupShaderConstantMapping(const char* pcName, unsigned int* uiMappingID)
{
    unsigned int uiIndex;
    const NiShaderConstantMap::ShaderConstantMapEntry* pkMapping;

    for (uiIndex = 0; uiIndex < NiShaderConstantMap::ms_uiConstantMapEntryCount; ++uiIndex)
    {
        pkMapping = &NiShaderConstantMap::ms_pkConstantMap[uiIndex];
        if (_NiStricmp(pkMapping->m_kConstantName, pcName) == 0)
        {
            *uiMappingID = pkMapping->m_uiConstantID;
            return true;
        }
    }
    return false;
}

struct ShaderLight
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
    int unk30;
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
    unsigned char enabled;
    unsigned char type;
};

struct ShaderLightNode
{
    ShaderLightNode* next;
    ShaderLight* data;

    static inline ShaderLight* GetNext(ShaderLightNode*& node)
    {
        if (!node)
            return 0;
        ShaderLight* light = node->data;
        node = node->next;
        return light;
    }
};

struct ShaderLights
{
    int unk00;
    int unk04;
    int unk08;
    ShaderLightNode* classified;
    ShaderLightNode* special;
    ShaderLightNode* ambient;
    ShaderLight* primary;
    ShaderLight* secondary;
};

// Returns the enabled light of the requested type at index wanted from the classified, ambient or special list, or the primary/secondary light.
// @fnv 0x00a9c130
ShaderLight* GetLightByType(ShaderLights* lights, unsigned int type, unsigned int wanted)
{
    ShaderLight* result = 0;
    if (lights)
    {
        switch (type)
        {
        case 1:
        case 2:
        case 3:
        case 4: {
            ShaderLightNode* pNode = lights->classified;
            unsigned int count = 0;
            while (pNode)
            {
                ShaderLight* light = ShaderLightNode::GetNext(pNode);
                unsigned char enabled = light->enabled;
                unsigned int special = (light->type > type && type == 1) ? type : 0;
                unsigned char match = (light->type == type) ^ (unsigned char)special;
                if (match && enabled)
                {
                    if (count++ == wanted)
                    {
                        result = light;
                        break;
                    }
                }
            }
            break;
        }
        case 5:
            result = lights->primary;
            if (result && !result->enabled)
                result = 0;
            break;
        case 6: {
            ShaderLightNode* pNode = lights->ambient;
            unsigned int found = 0;
            while (pNode)
            {
                ShaderLight* light = pNode->data;
                pNode = pNode->next;
                if (light && light->enabled && found++ == wanted)
                {
                    result = light;
                    break;
                }
            }
            break;
        }
        case 7: {
            ShaderLightNode* pNode = lights->special;
            unsigned int found = 0;
            while (pNode)
            {
                ShaderLight* light = pNode->data;
                pNode = pNode->next;
                if (light && light->enabled && found++ == wanted)
                {
                    result = light;
                    break;
                }
            }
            break;
        }
        case 8:
            result = lights->secondary;
            if (result && !result->enabled)
                result = 0;
            break;
        }
    }

    return result;
}
