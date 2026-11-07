#include "../../include/NiTArray.h"
// bsshader/bsshaderproperty.cpp: ShaderPassEntry, ShaderPassList, NiShadeProperty, ShaderPropertyRecord (23 functions)

#include "bsshaderproperty_decls.h"
#include "../../include/NiShadeProperty.h"

// Initializes the shader property with geometry, pass, first-pass flag, light count, and copies the given lights into a newly allocated array.
// @fnv 0x00ba8ec0
BSShaderProperty::ShaderPassEntry::ShaderPassEntry(NiGeometry* geometry, unsigned short passEnum, bool firstPass,
                                                   unsigned char numLights, ShadowSceneLight* light0, ...)
{
    m_pShaderGeometry = geometry;
    m_usShaderPassType = passEnum;
    m_ucLightCount = numLights;
    m_ucLightCapacity = 0;
    m_bIsBest = firstPass;
    m_bRendered = false;
    m_ppShadowSceneLights = 0;
    m_ucLightIndex = 0;
    if (numLights > 0)
    {
        m_ppShadowSceneLights = reinterpret_cast<ShadowSceneLight**>(new BSShaderPropertyLightSlot[numLights]);
        m_ucLightCapacity = numLights;
        ShadowSceneLight** lights = &light0;
        for (int i = 0; i < numLights; ++i)
            m_ppShadowSceneLights[i] = lights[i];
    }
    m_ucPassIndex = 0;
}

// @fnv 0x00ba9ee0
void BSShaderProperty::ShaderPassList::Add(NiGeometry* geometry, unsigned short passEnum, bool firstPass,
                                           unsigned char numLights, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                           ShadowSceneLight* light2, ShadowSceneLight* light3)
{
    if (m_uiCount >= m_kRenderPasses.m_usESize)
    {
        reinterpret_cast<NiTObjectArray<ShaderPassEntry*>&>(m_kRenderPasses).Add(
            new ShaderPassEntry(geometry, passEnum, firstPass, numLights, light0, light1, light2, light3));
    }
    else
    {
        ShaderPassEntry* pass = m_kRenderPasses.m_pBase[m_uiCount];
        pass->BSShaderProperty_RenderPass_SetLights(numLights, light0, light1, light2, light3);
        pass->SetFirstPass(firstPass);
        pass->SetGeometry(geometry);
        pass->SetPassEnum(passEnum);
        pass->m_bRendered = false;
        pass->m_ucLightIndex = 0;
        pass->m_ucPassIndex = 0;
    }
    ++m_uiCount;
}

struct FUN_00ba8ab0_shell : public BSShaderProperty
{
    void BSShaderProperty_SetAlpha(float);
};

// Resets the int at offset 0x38 when the stored float at 0x28 crosses the 1.0 threshold, then stores afAlpha at 0x28.
// @fnv 0x00ba8ab0
// src: XBOX_PDB 0x00ba8ab0
void FUN_00ba8ab0_shell::BSShaderProperty_SetAlpha(float afAlpha)
{
    if ((*(float*)((char*)this + 0x28) >= 1.0f && afAlpha < 1.0f) ||
        (*(float*)((char*)this + 0x28) < 1.0f && afAlpha >= 1.0f))
    {
        *(int*)((char*)this + 0x38) = 0;
    }
    *(float*)((char*)this + 0x28) = afAlpha;
}

// Resets the count at offset 4, frees the light pointer at offset 0xC if set, and clears the byte at offset 0xB.
// @fnv 0x00ba8cd0
// src: GUESS 0x00ba8cd0 (confidence: low)
void __fastcall BSShaderProperty_ReleaseStorage_00ba8cd0(char* pThis)
{
    *(unsigned short*)(pThis + 4) = 0;
    void* pLights = *(void**)(pThis + 0xC);
    if (pLights)
    {
        g_memoryManager.Deallocate(pLights);
        *(void**)(pThis + 0xC) = 0;
    }
    *(unsigned char*)(pThis + 0xB) = 0;
}

struct FUN_00baa000_shell : public BSShaderProperty
{
    void BSShaderProperty_FreeRenderPasses();
};

void __fastcall FUN_00ba9520(void* pThis);

// Clears the int at offset 0x38, then for each pointer at offsets 0x3c-0x54 calls FUN_00ba9520, deallocates it via g_memoryManager and nulls it.
// @fnv 0x00baa000
// src: XBOX_PDB 0x00baa000
void FUN_00baa000_shell::BSShaderProperty_FreeRenderPasses()
{
    char* self = reinterpret_cast<char*>(this);
    *reinterpret_cast<int*>(self + 0x38) = 0;

    void* p = *reinterpret_cast<void**>(self + 0x3c);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x3c) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x40);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x40) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x48);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x48) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x4c);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x4c) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x44);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x44) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x50);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x50) = 0;
    }

    p = *reinterpret_cast<void**>(self + 0x54);
    if (p)
    {
        FUN_00ba9520(p);
        g_memoryManager.Deallocate(p);
        *reinterpret_cast<void**>(self + 0x54) = 0;
    }
}

extern const char g_01200464_arg1[];
// @fnv 0x00a81450
// src: COMMUNITY 0x00a81450
const char* __cdecl NiShadeProperty_GetRTTI()
{
    return g_01200464_arg1;
}

struct BSSP_stub4;
struct NiObject_stub
{
    void NiShadeProperty_CopyMembers(BSSP_stub4*, int);
};
struct BSSP_stub4 : NiObject_stub
{
    int a[8];
    unsigned int m_f0, m_f1;
    float m_fAlpha, m_fFade;
    int b[2];
    int m_iLast;
    int c[7];
    int m_iShader;
    float m_fFogDepth;
};
// @fnv 0x00ba8b10
// src: XBOX_PDB 0x00ba8b10
void __fastcall BSShaderProperty_CopyMembers(BSSP_stub4* self, int, BSSP_stub4* dst, int arg)
{
    self->NiShadeProperty_CopyMembers(dst, arg);
    dst->m_f0 = self->m_f0;
    dst->m_f1 = self->m_f1;
    dst->m_fAlpha = self->m_fAlpha;
    dst->m_fFade = self->m_fFade;
    dst->m_iLast = 0;
    dst->m_iShader = self->m_iShader;
    dst->m_fFogDepth = self->m_fFogDepth;
}

extern bool DAT_0120045c;
// @fnv 0x00ba8b60
// src: COMMUNITY 0x00ba8b60
void __cdecl BSShaderProperty_PreviousTransform_SetFreeze(bool v)
{
    DAT_0120045c = v;
}

extern bool DAT_0120045d;
// @fnv 0x00ba8b70
void __cdecl ToggleGlobalFlag()
{
    DAT_0120045d = !DAT_0120045d;
}

struct NiObjectNET_stub
{
    void NiObjectNET_PostLinkObject(int);
};
struct BSSP_stub : NiObjectNET_stub
{
    int a[8];
    unsigned int m_flags;
    int b[14];
    float m_depth;
};
// @fnv 0x00ba8be0
// src: XBOX_PDB 0x00ba8be0
void __fastcall BSShaderProperty_PostLinkObject(BSSP_stub* self, int, int arg)
{
    self->NiObjectNET_PostLinkObject(arg);
    if ((self->m_flags & 0x4000000) > 0)
        self->m_depth = 1.0f;
}

struct AllocElem
{
    int v;
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
};
struct BSSP_stub2
{
    int a[3];
    AllocElem* m_p;
};
// Allocates an array of n AllocElem objects and stores its pointer in self->m_p.
// @fnv 0x00ba8c00
void __fastcall AllocateElemArray(BSSP_stub2* self, int, unsigned char n)
{
    self->m_p = new AllocElem[n];
}

struct FUN_00ba8c30_shell2
{
    int a[3];
    void* m_p;
    void BSShaderProperty_RenderPass_ClearSceneLights();
};
// @fnv 0x00ba8c30
// src: COMMUNITY 0x00ba8c30
void __fastcall BSShaderProperty_RenderPass_ClearSceneLights(FUN_00ba8c30_shell2* self, int)
{
    if (self->m_p)
    {
        g_memoryManager.Deallocate(self->m_p);
        self->m_p = 0;
    }
}

extern const char g_011fa018_arg1[];
// @fnv 0x00ba8eb0
// src: XBOX_PDB 0x00ba8eb0
const char* __cdecl BSShaderProperty_GetRTTI()
{
    return g_011fa018_arg1;
}

void __fastcall DestroyFogProperty(void*);
void __cdecl _delete(void*, unsigned int);
// Calls DestroyFogProperty on this, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00a81460
void* NiShadeProperty::Destroy(unsigned int flags)
{
    DestroyFogProperty(this);
    if (flags & 1)
        _delete(this, 0x20);
    return this;
}

extern __declspec(thread) int g_iB97550AllocTag;

struct BB97550AllocTagScope
{
    int m_iSaved;

    BB97550AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iB97550AllocTag;
        g_iB97550AllocTag = aiAllocationTag;
    }
    ~BB97550AllocTagScope()
    {
        g_iB97550AllocTag = m_iSaved;
    }
};

class BB97550Pass;

class BB97550Shader
{
  public:
    void RenderWithTextures(BB97550Pass* pkPass, int iA, int iB, int iC, int iD, int iE);
    void ImageSpaceManager_RenderEffect(unsigned int uiPass, int iA, int iB, int iC, int iD, int iE);

    int unk00;
    int unk04;
    BB97550Pass** m_ppkPasses;
};

// Sets the thread-local alloc tag to 0x27 for the scope, then forwards the arguments to the pass at index uiPass.
// @fnv 0x00b97550
// src: COMMUNITY 0x00b97550
void BB97550Shader::ImageSpaceManager_RenderEffect(unsigned int uiPassIndex, int iA, int iB, int iC, int iD, int iE)
{
    BB97550AllocTagScope kScope(0x27);
    RenderWithTextures(m_ppkPasses[uiPassIndex], iA, iB, iC, iD, iE);
}

struct S_00ba8c50_Slot
{
    ShadowSceneLight* light;
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

// Grows the light array to numLights if needed, then stores numLights and copies the variadic ShadowSceneLight pointers into it.
// @fnv 0x00ba8c50
// src: COMMUNITY 0x00ba8c50
void __cdecl BSShaderProperty::ShaderPassEntry::BSShaderProperty_RenderPass_SetLights(unsigned char numLights, ShadowSceneLight*, ...)
{
    ShadowSceneLight** args = (ShadowSceneLight**)((unsigned int*)&numLights + 1);

    if (numLights > m_ucLightCapacity)
    {
        if (m_ppShadowSceneLights != 0)
        {
            delete[] reinterpret_cast<S_00ba8c50_Slot*>(m_ppShadowSceneLights);
            m_ppShadowSceneLights = 0;
        }
        m_ppShadowSceneLights = reinterpret_cast<ShadowSceneLight**>(new S_00ba8c50_Slot[numLights]);
        m_ucLightCapacity = numLights;
    }
    m_ucLightCount = numLights;
    if (numLights > 0)
    {
        int count = numLights;
        for (int i = 0; i < count; ++i)
        {
            m_ppShadowSceneLights[i] = args[i];
        }
    }
}

extern int DAT_010b8488;

struct FUN_00ba8e50_base
{
    void InitBase();
};

struct FUN_00ba8e50_cls : FUN_00ba8e50_base
{
    int m_vptr00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    volatile unsigned short m_18;
    volatile int m_1c;
    volatile int m_20;
    volatile int m_24;
    volatile float m_28;
    volatile float m_2c;
    volatile float m_30;
    float m_34;
    volatile int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int unk54;
    int m_58;
    float m_5c;

    FUN_00ba8e50_cls* InitializeFields_00ba8e50();
};

// Initializes the object: calls InitBase, sets the vtable pointer, and zeroes or defaults the member fields, returning this.
// @fnv 0x00ba8e50
// src: GUESS 0x00ba8e50 (confidence: low)
FUN_00ba8e50_cls* FUN_00ba8e50_cls::InitializeFields_00ba8e50()
{
    InitBase();
    m_18 = 1;
    m_1c = -1;
    *(volatile int*)&m_vptr00 = (int)&DAT_010b8488;
    m_20 = 0;
    m_24 = 0;
    m_28 = 1.0f;
    m_2c = 1.0f;
    m_38 = 0;
    m_30 = 1.0f;
    m_3c = 0;
    m_40 = 0;
    m_5c = 0.0f;
    m_48 = 0;
    m_4c = 0;
    m_34 = 0.0f;
    m_44 = 0;
    m_50 = 0;
    m_58 = 0;
    return this;
}

typedef NiTArray<ShadowSceneLight*, NiTMallocInterface<ShadowSceneLight*> > FUN_00ba8b80;


// @fnv 0x00ba8b80
template <> NiTArray<ShadowSceneLight*, NiTMallocInterface<ShadowSceneLight*> >::NiTArray(unsigned int maxSize, unsigned int growBy)
{
    unsigned short n = (unsigned short)maxSize;
    m_usMaxSize = n;
    m_usGrowBy = growBy;
    m_usSize = 0;
    m_usESize = 0;
    if (n > 0)
    {
        m_pBase = (ShadowSceneLight**)new BSShaderPropertyLightSlot[m_usMaxSize];
    }
    else
    {
        m_pBase = 0;
    }
}

// Resizes the array to newSize: clears and shrinks entries above the new size, reallocates the base buffer, copies existing entries and zero-fills the rest.
// @fnv 0x00ba8d30
template <>
void NiTArray<BSShaderProperty::ShaderPassEntry*, NiTNewInterface<BSShaderProperty::ShaderPassEntry*> >::SetSize(
    unsigned int newSize)
{
    if (newSize != m_usMaxSize)
    {
        if (newSize < m_usSize)
        {
            for (unsigned short i = (unsigned short)newSize; i < m_usSize; ++i)
            {
                if (m_pBase[i] != 0)
                {
                    m_pBase[i] = 0;
                    m_usESize += 0xffff;
                }
            }
            m_usSize = (unsigned short)newSize;
        }
        BSShaderProperty::ShaderPassEntry** oldBase = m_pBase;
        m_usMaxSize = (unsigned short)newSize;
        if (newSize > 0)
        {
            m_pBase = (BSShaderProperty::ShaderPassEntry**)new BSShaderPropertyLightSlot[m_usMaxSize];
            for (unsigned short i = 0; i < m_usSize; ++i)
                m_pBase[i] = oldBase[i];
            for (unsigned short i = m_usSize; i < m_usMaxSize; ++i)
                m_pBase[i] = 0;
        }
        else
        {
            m_pBase = 0;
        }
        g_memoryManager.Deallocate(oldBase);
    }
}

struct FUN_00ba8d00_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;

    void BSShaderProperty_SetMotionBlurred(bool enable);
};
// Sets or clears bit 0x10 in unk20, zeroing unk38 when the bit's state changes.
// @fnv 0x00ba8d00
// src: COMMUNITY 0x00ba8d00
void FUN_00ba8d00_cls::BSShaderProperty_SetMotionBlurred(bool enable)
{
    if (enable)
    {
        unsigned int f = 0x10;
        if (!(*reinterpret_cast<const unsigned char*>(&unk20) & f))
            unk38 = 0;
        unk20 |= f;
    }
    else
    {
        if (*reinterpret_cast<const unsigned char*>(&unk20) & 0x10)
            unk38 = 0;
        unk20 &= ~0x10;
    }
}

struct SettingArray
{
    unsigned int metadata;
    int* values;
    unsigned short capacity;
    unsigned short count;
    unsigned short activeCount;
    unsigned short growBy;
    void __thiscall FUN_0096ad30(unsigned int newSize);
    void __thiscall FUN_0096ae90(unsigned int index, int* value);
    void AddTextValue(int* value)
    {
        unsigned int index = count;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        FUN_0096ae90(index, value);
    }
    __forceinline void AddNumericValue(int value)
    {
        unsigned int index = count;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        if (index >= count)
        {
            count = (unsigned short)(index + 1);
            if (value != 0)
                ++activeCount;
        }
        else if (value != 0)
        {
            if (values[index] == 0)
                ++activeCount;
        }
        else if (values[index] != 0)
        {
            --activeCount;
        }
        values[index] = value;
    }
    __forceinline void AddFinal(int value)
    {
        unsigned int index = count;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        if (index >= count)
        {
            count = (unsigned short)(index + 1);
            if (value != 0)
                ++activeCount;
        }
        else if (value != 0)
        {
            if (values[index] == 0)
                ++activeCount;
        }
        else if (values[index] != 0)
        {
            --activeCount;
        }
        values[index] = value;
    }
};
struct ShaderFlagEntry
{
    unsigned int unknown00;
    unsigned short type;
    unsigned char unknown06;
    unsigned char secondary;
};
struct ShaderFlagList
{
    unsigned int unknown00;
    ShaderFlagEntry** entries;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int count;
};
extern void __stdcall WriteToArray(SettingArray* target);
extern int __cdecl NiViewerStrings_NiGetViewerString_Title(const char* text);
extern int __cdecl NiGetViewerString(const char* text, int flag);
extern int __cdecl NiGetViewerString_00a7d550(const char* text, float value);
extern int __cdecl NiGetViewerString_00a7d4d0(const char* text, int value);
extern unsigned int __cdecl NiGetViewerString_00a7d510(const char* text, unsigned int value);
extern int __cdecl NiGetViewerString_00a7d5e0(const char* text, const char* value);
extern const char* __cdecl BSShaderManager_GetPassName(unsigned int value);
extern const char* DAT_01200464;
extern const char UNK_010b8950[];
extern const char UNK_010b8948[];
extern const char UNK_010b893c[];
extern const char UNK_010b892c[];
extern const char UNK_010b8920[];
extern const char UNK_010b8914[];
extern const char UNK_010b890c[];
extern const char UNK_010b88f8[];
extern const char UNK_010b88e8[];
extern const char UNK_010b88dc[];
extern const char UNK_010b88d4[];
extern const char UNK_010b88c8[];
extern const char UNK_010b88b4[];
extern const char UNK_010b889c[];
extern const char UNK_010b8890[];
extern const char UNK_010b8884[];
extern const char UNK_010b8874[];
extern const char UNK_010b885c[];
extern const char UNK_010b8854[];
extern const char UNK_010b8844[];
extern const char UNK_010b882c[];
extern const char UNK_010b8810[];
extern const char UNK_010b8800[];
extern const char UNK_010b87f0[];
extern const char UNK_010b87dc[];
extern const char UNK_010b87c8[];
extern const char UNK_010b87c0[];
extern const char UNK_010b87b0[];
extern const char UNK_010b879c[];
extern const char UNK_010b8788[];
extern const char UNK_010b877c[];
extern const char UNK_010b876c[];
extern const char UNK_010b875c[];
extern const char UNK_010b874c[];
extern const char UNK_010b873c[];
extern const char UNK_010b8734[];
extern const char UNK_010b8724[];
extern const char UNK_010b8714[];
extern const char UNK_010b8708[];
extern const char UNK_010b86ec[];
extern const char UNK_010b86e0[];
extern const char UNK_010b86d4[];
extern const char UNK_010b86c4[];
extern const char UNK_010b86b4[];
extern const char UNK_010b86a8[];
extern const char UNK_010b869c[];
extern const char UNK_010b8688[];
extern const char UNK_010b8674[];
extern const char UNK_010b8668[];
extern const char UNK_010b8658[];
extern const char UNK_010b8644[];
extern const char UNK_010b8634[];
extern const char UNK_010b8620[];
extern const char UNK_010b8614[];
extern const char UNK_010b85f4[];
extern const char UNK_010b85e4[];
extern const char UNK_010b85dc[];
extern const char UNK_010b85d0[];
extern const char UNK_010b85c4[];
extern const char UNK_010b85b4[];
extern const char UNK_010b85a4[];
extern const char UNK_010b858c[];
extern const char UNK_010b855c[];
extern const char UNK_010b8554[];
extern const char UNK_010b854c[];
extern const char UNK_010b8570[];
struct ShaderPropertyRecord
{
    int unknown00, unknown04, unknown08, unknown0c;
    int unknown10, unknown14, unknown18, unknown1c;
    unsigned int flags[2];
    float alpha;
    float fade;
    float specular;
    int unknown34;
    int material;
    ShaderFlagList* flagsList;
    int unknown40, unknown44, unknown48, unknown4c;
    int unknown50, unknown54;
    int shaderType;
    float depth;
    void WriteToSettingArray(SettingArray* output);
};
// Serializes shader flags, alpha, fade, depth, specular, shader type, material, and flag list entries into a SettingArray via text and numeric tokens.
// @fnv 0x00ba9890
void ShaderPropertyRecord::WriteToSettingArray(SettingArray* output)
{
    WriteToArray(output);
    union
    {
        int token;
        volatile float scalar;
    } formatted;
    formatted.token = NiViewerStrings_NiGetViewerString_Title(DAT_01200464);
    output->AddTextValue(&formatted.token);
    const char* flagNames[56] = {
        UNK_010b8950, UNK_010b8948, UNK_010b893c, UNK_010b892c, UNK_010b8920, UNK_010b8914, UNK_010b890c, UNK_010b88f8,
        UNK_010b88e8, UNK_010b88dc, UNK_010b88d4, UNK_010b88c8, UNK_010b88b4, UNK_010b889c, UNK_010b8890, UNK_010b8884,
        UNK_010b8874, UNK_010b885c, UNK_010b8854, UNK_010b8844, UNK_010b882c, UNK_010b8810, UNK_010b8800, UNK_010b87f0,
        UNK_010b87dc, UNK_010b87c8, UNK_010b87c0, UNK_010b87b0, UNK_010b879c, UNK_010b8788, UNK_010b877c, UNK_010b876c,
        UNK_010b875c, UNK_010b874c, UNK_010b873c, UNK_010b8734, UNK_010b8724, UNK_010b8714, UNK_010b8708, UNK_010b86ec,
        UNK_010b86e0, UNK_010b86d4, UNK_010b86c4, UNK_010b86b4, UNK_010b86a8, UNK_010b869c, UNK_010b8688, UNK_010b8674,
        UNK_010b8668, UNK_010b8658, UNK_010b8644, UNK_010b8634, UNK_010b8620, UNK_010b8614, UNK_010b85f4, UNK_010b85e4};
    unsigned int i = 0;
    unsigned int mask = 1;
    for (; i < 56; ++i)
    {
        if ((flags[i >> 5] & mask) > 0 && flagNames[i] != 0)
        {
            formatted.token = NiGetViewerString(flagNames[i], 1);
            output->AddTextValue(&formatted.token);
        }
        mask = (mask << 1) | (mask >> 31);
    }
    if (alpha < 1.0f)
    {
        formatted.token = NiGetViewerString_00a7d550(UNK_010b85dc, alpha);
        output->AddTextValue(&formatted.token);
    }
    if (fade < 1.0f)
    {
        formatted.token = NiGetViewerString_00a7d550(UNK_010b85d0, fade);
        output->AddTextValue(&formatted.token);
    }
    if (depth > 0.0f)
    {
        formatted.token = NiGetViewerString_00a7d550(UNK_010b85c4, depth);
        output->AddTextValue(&formatted.token);
    }
    if ((flags[0] & 0x80u) > 0)
    {
        formatted.scalar = specular;
        formatted.token = NiGetViewerString_00a7d550(UNK_010b85b4, formatted.scalar);
        output->AddTextValue(&formatted.token);
    }
    int numericToken = NiGetViewerString_00a7d4d0(UNK_010b85a4, shaderType);
    output->AddNumericValue(numericToken);
    numericToken = NiGetViewerString_00a7d4d0(UNK_010b858c, material);
    output->AddNumericValue(numericToken);
    if (!flagsList)
    {
        formatted.token = NiViewerStrings_NiGetViewerString_Title(UNK_010b8570);
        output->AddTextValue(&formatted.token);
        return;
    }
    unsigned int count = flagsList->count;
    formatted.token = NiGetViewerString_00a7d510(UNK_010b855c, count);
    output->AddTextValue(&formatted.token);
    for (unsigned int index = 0; index < count; ++index)
    {
        ShaderFlagEntry* entry = flagsList->entries[index];
        unsigned short type = entry->type;
        if (type < 0x2f7)
        {
            const unsigned int code = type;
            if (entry->secondary)
            {
                output->AddFinal(NiGetViewerString_00a7d5e0(UNK_010b8554, BSShaderManager_GetPassName((unsigned int)entry->type)));
            }
            else
            {
                output->AddFinal(NiGetViewerString_00a7d5e0(UNK_010b854c, BSShaderManager_GetPassName((unsigned int)entry->type)));
            }
        }
    }
}

struct FUN_00ba8e20
{
    void* m_p;
    FUN_00ba8e20();
    virtual ~FUN_00ba8e20();
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
// Default constructor for FUN_00ba8e20; performs no initialization.
// @fnv 0x00ba8e20
FUN_00ba8e20::FUN_00ba8e20()
{}
FUN_00ba8e20::~FUN_00ba8e20()
{
    g_memoryManager.Deallocate(m_p);
}

namespace fnv_00bb73f0 {
struct FUN_00ba8ab0_shell : public BSShaderProperty
{
    void BSShaderProperty_SetAlpha(float);
};

struct FUN_00ba9820_shell : public BSShaderProperty
{
    void CreateSpawnedObjectIfMissing(int);
};

struct FUN_00ba95e0_shell : public BSShaderProperty
{
    void FUN_00ba95e0(int);
};

struct FUN_00bb73f0_shell
{
    void* vtable;
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
    float m_fAlpha;
    int unk30;
    int unk34;
    unsigned int m_uiPass;
    BSShaderProperty::ShaderPassList* m_pRenderPassArray3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    BSShaderProperty::ShaderPassList* m_pRenderPassArray54;

    BSShaderProperty::ShaderPassList* BSDistantTreeShaderProperty_GetRenderPasses(int geometry, unsigned int arg2, int arg3, unsigned int arg4,
                                                   int arg5, int arg6);
};

// Computes a pass key from arg2 and arg4, sets alpha and light index, and returns the appropriate render pass list for the given geometry.
// @fnv 0x00bb73f0
// src: XBOX_PDB 0x00bb73f0
BSShaderProperty::ShaderPassList* FUN_00bb73f0_shell::BSDistantTreeShaderProperty_GetRenderPasses(int geometry, unsigned int arg2, int aiUnused,
                                                                   unsigned int arg4, int aiUnused2, int aiUnused3)
{
    int* shaderSlot = (int*)((char*)geometry + 0x9c);
    float alpha;
    unsigned int pass = (arg4 << 8) | arg2;
    if (arg4 == 7)
        return 0;

    if (shaderSlot)
    {
        int shader = shaderSlot[2];
        if (shader)
            alpha = *(float*)((char*)shader + 0x3c) * m_fAlpha;
        else
            alpha = m_fAlpha;
        ((FUN_00ba8ab0_shell*)this)->BSShaderProperty_SetAlpha(alpha);
    }

    if (arg4 == 0xf)
    {
        ((FUN_00ba9820_shell*)this)->CreateSpawnedObjectIfMissing(1);
        if (m_pRenderPassArray54->m_uiCount == 0)
        {
            m_pRenderPassArray54->Add((NiGeometry*)geometry, 0x237, true, 0, 0, 0, 0, 0);
            m_pRenderPassArray54->m_kRenderPasses.m_pBase[0]->m_ucLightIndex = 0;
        }
        return m_pRenderPassArray54;
    }

    if (m_uiPass != pass)
    {
        ((FUN_00ba95e0_shell*)this)->FUN_00ba95e0(1);
        m_pRenderPassArray3c->m_uiCount = 0;
        m_pRenderPassArray3c->Add((NiGeometry*)geometry, 0x236, true, 0, 0, 0, 0, 0);
        m_pRenderPassArray3c->m_kRenderPasses.m_pBase[0]->m_ucLightIndex = 0xa;
        m_uiPass = pass;
    }
    return m_pRenderPassArray3c;
}
}  // namespace fnv_00bb73f0
