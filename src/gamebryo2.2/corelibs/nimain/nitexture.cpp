// gamebryo2.2/corelibs/nimain/nitexture.cpp: NiObjectNET, NiTexture, Elements (13 functions)

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiProperty.h"

#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiTexture.h"

extern "C" void(__stdcall* fnv_EnterCriticalSection)(void*);
extern "C" void(__stdcall* fnv_LeaveCriticalSection)(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern unsigned char DAT_011f4380;

// Removes the extra-data entry at index under a critical section, releasing its reference and shifting the remaining entries down.
// @fnv 0x00a5b990
void NiObjectNET::DeleteExtraData(unsigned short index)
{
    fnv_EnterCriticalSection(&DAT_011f4380);
    if (index >= m_usExtraDataSize)
    {
        fnv_LeaveCriticalSection(&DAT_011f4380);
        return;
    }

    if (m_ppkExtra[index])
    {
        NiExtraData* extra = m_ppkExtra[index];
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&extra->m_uiRefCount)) == 0)
            extra->DeleteThis();
    }

    for (unsigned short i = index; i < m_usExtraDataSize - 1; ++i)
        m_ppkExtra[i] = m_ppkExtra[i + 1];
    --m_usExtraDataSize;
    m_ppkExtra[m_usExtraDataSize] = 0;
    fnv_LeaveCriticalSection(&DAT_011f4380);
}

// @fnv 0x00a47350
void NiTexture::LoadBinary(NiStream& stream)
{
    NiObjectNET::LoadBinary(stream);
}

extern int DAT_010983bc;

// Allocates a 0x18-byte NiProperty, runs its constructor, installs the vtable at DAT_010983bc, and returns it (or null on allocation failure).
// @fnv 0x00a47380
// src: EXE 0x00a47380
void* __cdecl NiSequenceStreamHelper_CreateObject()
{
    NiProperty* p = (NiProperty*)NiRefObject::operator new(0x18);
    if (p)
    {
        p->NiProperty::NiProperty();
        *(int**)p = &DAT_010983bc;
        return p;
    }
    return 0;
}

extern MemoryManager g_memoryManager;

struct Pool00a91290
{
    int a, b, c, d, e, f;
};

extern Pool00a91290* DAT_011f5e50;

// Allocates a Pool00a91290, zeroes its first four fields, sets the last two to 8, and stores it in DAT_011f5e50 (or null on failure).
// @fnv 0x00a91290
// src: COMMUNITY 0x00a91290
void __cdecl NiScreenGeometryData__SDMInit()
{
    Pool00a91290* p = (Pool00a91290*)g_memoryManager.Allocate(sizeof(Pool00a91290));
    if (p)
    {
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        p->e = 8;
        p->f = 8;
        DAT_011f5e50 = p;
        return;
    }
    DAT_011f5e50 = 0;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3f38;
// Returns a pointer to the global object g_011f3f38, ignoring both arguments.
// @fnv 0x00a47370
// src: COMMUNITY 0x00a47370
GlobalObjectO2_00a7b610* __fastcall NiSequenceStreamHelper_GetRTTI(void*, int)
{
    return &g_011f3f38;
}

void __fastcall DestroyFogProperty(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
// @fnv 0x00a473b0
void* __fastcall FUN_00a473b0(void* self, int, unsigned int flags)
{
    DestroyFogProperty(self);
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x18);
    return self;
}

struct ActorCombatGroup;
template <class T, class A> struct ViewerFieldArray
{
    void* m_vtbl;
    unsigned int m_pad4;
    unsigned short m_usMaxSize;
    unsigned short m_usESize;
    unsigned short m_usPadC;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
typedef ViewerFieldArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> > CGArray;
extern const char* const g_011f444c_arg1;
// NiObjectNET's viewer routine is not yet declared by the shared header.
void __fastcall NiObjectNET_GetViewerStrings(NiObjectNET*, int, CGArray*);
ActorCombatGroup* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
ActorCombatGroup* __cdecl NiGetViewerString_00a7d4d0(const char*, unsigned int);
// @fnv 0x00a62a40
// src: XBOX_PDB 0x00a62a40
void __fastcall NiTexture_GetViewerStrings(NiTexture* self, int unused, CGArray* apArray)
{
    NiObjectNET_GetViewerStrings(self, unused, apArray);
    ActorCombatGroup* pEntry = NiViewerStrings_NiGetViewerString_Title(g_011f444c_arg1);
    unsigned int n = apArray->m_usESize;
    if (n >= apArray->m_usMaxSize)
        apArray->SetSize(n + apArray->m_usGrowBy);
    apArray->SetAt(n, pEntry);
    unsigned char* st = reinterpret_cast<unsigned char*>(self->m_pkRendererData);
    pEntry = NiGetViewerString_00a7d4d0("State", st ? st[0x5b] : 0);
    n = apArray->m_usESize;
    if (n >= apArray->m_usMaxSize)
        apArray->SetSize(n + apArray->m_usGrowBy);
    apArray->SetAt(n, pEntry);
}

struct TexInfo
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    char m_c14;
    char m_c15;
    int m_i18;
};

// @fnv 0x00a62670
// The shared NiTexture header does not yet declare this renderer-data query.
// src: XBOX_PDB 0x00a62670
int __fastcall NiTexture_GetMemorySize(NiTexture* self)
{
    unsigned int result = 0;
    if (self->m_pkRendererData != 0)
    {
        result = (unsigned char)reinterpret_cast<TexInfo*>(self->m_pkRendererData)->m_c15;
        result >>= 3;
        result *= (unsigned int)reinterpret_cast<TexInfo*>(self->m_pkRendererData)->m_i10;
        result *= (unsigned int)reinterpret_cast<TexInfo*>(self->m_pkRendererData)->m_i0C;
    }
    return (int)result;
}

// Lazy-initialised dispatch to the cached handler routine.
// The handler pointer is stored in a global slot on first use.
typedef int(__cdecl* DispatchFn)(int, int);

extern DispatchFn DAT_011a9600;
extern int GetTextureForType(int, int);

// Returns 0 when a2's high bit is clear; otherwise lazily installs GetTextureForType as DAT_011a9600 and calls it with a1 and a2.
// @fnv 0x00a62a10
int __cdecl DispatchIfHighBitSet(int a1, int a2, int aUnused)
{
    if ((a2 & 0x80000000u) == 0)
        return 0;

    if (!DAT_011a9600)
        DAT_011a9600 = GetTextureForType;
    return DAT_011a9600(a1, a2);
}

struct TextureColor
{
    float r, g, b, a;
    TextureColor()
    {}
    TextureColor(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha)
    {}
};
struct TextureCacheEntry
{
    int value;
    void FUN_00a5f860(int);
};
extern TextureCacheEntry DAT_011f4514[10];
extern const char DAT_011f4600[];
int CreateCheckerboardTexture(const TextureColor*, const TextureColor*, const char*, unsigned int);
// Looks up a cached texture for a type index, generating it from per-type color pairs via CreateCheckerboardTexture when not yet cached, and returns the cached value.
// @fnv 0x00a62690
int GetTextureForType(int unused, int type)
{
    unsigned int index = (unsigned int)type & 0x7fffffff;
    if (index >= 10)
        return 0;
    unsigned int mode = 1;
    if (!DAT_011f4514[index].value)
    {
        TextureColor firstColor, secondColor;
        switch (type)
        {
        default:
            firstColor = TextureColor(1.0f, 0.0f, 1.0f, 1.0f);
            secondColor = TextureColor(1.0f, 0.0f, 1.0f, 1.0f);
            break;
        case (int)0x80000001u:
            firstColor = TextureColor(0.0f, 0.0f, 1.0f, 1.0f);
            secondColor = TextureColor(1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case (int)0x80000002u:
            firstColor = TextureColor(0.0f, 1.0f, 0.0f, 1.0f);
            secondColor = TextureColor(1.0f, 0.0f, 0.0f, 1.0f);
            mode = 6;
            break;
        case (int)0x80000003u:
            firstColor = TextureColor(0.0f, 1.0f, 1.0f, 1.0f);
            secondColor = TextureColor(1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case (int)0x80000004u:
            firstColor = TextureColor(1.0f, 0.0f, 0.0f, 1.0f);
            secondColor = TextureColor(1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case (int)0x80000006u:
            firstColor = TextureColor(0.0f, 1.0f, 1.0f, 1.0f);
            secondColor = TextureColor(0.0f, 1.0f, 1.0f, 1.0f);
            break;
        case (int)0x80000007u:
            firstColor = TextureColor(0.0f, 1.0f, 0.0f, 1.0f);
            secondColor = TextureColor(1.0f, 1.0f, 0.0f, 1.0f);
            mode = 6;
            break;
        case (int)0x80000008u:
            firstColor = TextureColor(0.0f, 1.0f, 0.0f, 1.0f);
            secondColor = TextureColor(1.0f, 0.0f, 1.0f, 1.0f);
            mode = 6;
            break;
        case (int)0x80000009u:
            firstColor = TextureColor(0.0f, 1.0f, 0.0f, 1.0f);
            secondColor = TextureColor(0.0f, 1.0f, 1.0f, 1.0f);
            mode = 6;
            break;
        }
        DAT_011f4514[index].FUN_00a5f860(CreateCheckerboardTexture(&firstColor, &secondColor, DAT_011f4600, mode));
    }
    return DAT_011f4514[index].value;
}

extern "C" void __cdecl FUN_00a5c0e0();
// @fnv 0x00a47360
// src: XBOX_PDB 0x00a47360
extern "C" void __cdecl NiSequenceStreamHelper_LinkObject()
{
    FUN_00a5c0e0();
}

// @fnv 0x00a62660
// src: XBOX_PDB 0x00a62660
const ExtraName& NiTexture::GetFilename_00a62660()
{
    return reinterpret_cast<const ExtraName&>(m_kName);
}

namespace sa912d0 {

template <class T> class ViewerArray
{
  public:
    void FUN_0096ad30(unsigned int uiMaxSize);
    void FUN_0096ae90(unsigned int uiIndex, const T& element);

    unsigned int Add(const T& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            FUN_0096ad30(uiIndex + m_usGrowBy);
        FUN_0096ae90(uiIndex, element);
        return uiIndex;
    }

    void* m_pvVtable;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
typedef ViewerArray<char*> ViewerStrings;

extern const char* DAT_011f5e54;
char* NiViewerStrings_NiGetViewerString_Title(const char* pcClassName);
char* NiGetViewerString(const char* pcPrefix, bool bValue);
char* NiGetViewerString_00a7d510(const char* pcPrefix, unsigned int uiValue);

class ElementsBase
{
  public:
    void RegisterFields(ViewerStrings* pkStrings);
};

class Elements : public ElementsBase
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    bool m_bPixelAccurate;
    unsigned char unk059;
    unsigned char unk05a;
    unsigned char unk05b;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    unsigned short m_usNumElements;

    void NiScreenGeometryData_GetViewerStrings(ViewerStrings* pkStrings);
};

// Calls base RegisterFields, then adds class name, m_bPixelAccurate, and m_usNumElements to pkStrings.
// @fnv 0x00a912d0
// src: XBOX_PDB 0x00a912d0
void Elements::NiScreenGeometryData_GetViewerStrings(ViewerStrings* pkStrings)
{
    ElementsBase::RegisterFields(pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(DAT_011f5e54));
    pkStrings->Add(NiGetViewerString("m_bPixelAccurate", m_bPixelAccurate));
    unsigned int n = m_usNumElements;
    pkStrings->Add(NiGetViewerString_00a7d510("Num Elements", n));
}

}
