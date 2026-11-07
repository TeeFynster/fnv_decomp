// fallout_shared/region system/tesregiondatalandscape.cpp: TESRegionDataLandscape, ThisT (15 functions)

void* __cdecl operator new(unsigned int) throw();
void __cdecl operator delete(void*);
#include "../../../include/GO.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiTexturingProperty.h"
#include "../../../include/NiPixelData.h"

#include "../../../include/BSStringT.h"

#include "../../../include/TESFile.h"
#include "../../../include/TESTexture.h"
#include "../../../include/TESRegionData.h"
#include "../../../include/TESRegionDataLandscape.h"
// @fnv 0x004f2a20
bool TESRegionDataLandscape::ReadLandscapeData(TESFile* file)
{
    if (!file)
        return false;
    unsigned int chunk = file->GetChunkID();
    switch (chunk)
    {
    case 0x4e4f4349:
        TESTexture::ReadTextureData(m_pLandscapeTexture, file);
        break;
    }
    return true;
}

// @fnv 0x004f2790
TESRegionDataLandscape::TESRegionDataLandscape()
{
    m_pLandscapeTexture = new TESTexture;
    m_pLandscapeTexture->AssignTextureName("Trees\\CanopyShadow.dds");
}

// Writes 6, 3 and 2 into the first three int slots of pThis and returns pThis.
// @fnv 0x004f31d0
int* __fastcall InitIntArray(int* pIntArray)
{
    pIntArray[0] = 6;
    pIntArray[1] = 3;
    pIntArray[2] = 2;
    return pIntArray;
}

struct FUN_004f32b0_This
{
    void SetMaskedBits(unsigned short, unsigned short, unsigned short);
};

struct FUN_004f32b0_Arg
{
    unsigned short val;
};

// Calls SetMaskedBits with the argument's val, 0x3000 and 0xc.
// @fnv 0x004f32b0
// src: XBOX_PDB 0x004f32b0
void __fastcall NiTexturingProperty_Map_SetClampMode(FUN_004f32b0_This* this_ptr, FUN_004f32b0_Arg aValue)
{
    this_ptr->SetMaskedBits(aValue.val, 0x3000, 0xc);
}

struct LandscapeDeleter : TESRegionDataLandscape
{
    void* __thiscall DestroyLandscape(unsigned int flags);
};

// Destroys the landscape, deletes it when flags has bit 0 set, and returns this.
// @fnv 0x004f2840
void* LandscapeDeleter::DestroyLandscape(unsigned int flags)
{
    TESRegionDataLandscape::~TESRegionDataLandscape();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct TextureDeleter : TESTexture
{
    void* __thiscall DestroyTexture(unsigned int flags);
};

// Destroys the TESTexture base and, when flags has bit 0 set, frees the object, returning this.
// @fnv 0x004f29c0
void* __thiscall TextureDeleter::DestroyTexture(unsigned int flags)
{
    TESTexture::~TESTexture();
    if (flags & 1)
        operator delete(this);
    return this;
}

class LandscapeCopy;

// The shared landscape header does not yet declare these entry points.
// This helper uses its layout without adding data or virtual slots.
struct LandscapeOperations : TESRegionDataLandscape
{
    bool HasModel();
    void SetFullName(BSStringT<char>& aDest);
    void SaveLandscapeData();
    bool SetTextureName(const Flt& aName);
    LandscapeCopy* CloneLandscapeData();
};

// Returns true if the landscape texture has a non-empty path.
// @fnv 0x004f2eb0
bool __thiscall LandscapeOperations::HasModel()
{
    if (!this->m_pLandscapeTexture || !this->m_pLandscapeTexture->GetTextureNameLength())
        return false;
    return true;
}

// @fnv 0x004f2a70
void LandscapeOperations::SetFullName(BSStringT<char>& aDest)
{
    if (!m_pLandscapeTexture)
        aDest.Set("", 0);
    else
        aDest.Set(m_pLandscapeTexture->GetTextureResourceName(), 0);
}

// @fnv 0x004f29f0
void __thiscall LandscapeOperations::SaveLandscapeData()
{
    TESRegionData::Save();
    m_pLandscapeTexture->Save(0x4E4F4349);
}

struct Flt
{
    operator unsigned int() const;
};
int __cdecl CompareTexturePaths(const char*, const char*);
// @fnv 0x004f2ab0
bool __thiscall LandscapeOperations::SetTextureName(const Flt& aName)
{
    if (m_pLandscapeTexture)
    {
        if (!m_pLandscapeTexture->GetTextureNameLength() ||
            CompareTexturePaths(m_pLandscapeTexture->GetTextureResourceName(), (const char*)aName.operator unsigned int()) != 0)
        {
            m_pLandscapeTexture->AssignTextureName((const char*)aName.operator unsigned int());
            return true;
        }
    }
    return false;
}

extern const NiPixelFormat gNiPoint3StartupSrc;
struct TextureFormatPreferences
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};
extern GO g_011c7f0c;
float RandomFloat(float, float);
// Creates a 64x64 random RGBA NiPixelData, wraps it in a texturing property named DefaultFullMaskTextureProp, caches it in g_011c7f0c and returns it.
// @fnv 0x004f2ee0
NiTexturingProperty* GetDefaultFullMaskTextureProperty()
{
    NiPixelData* ppixeldata;
    unsigned char* ppixels;
    unsigned int iy;
    TextureFormatPreferences myPrefs;
    unsigned int ix;
    if ((NiTexturingProperty*)g_011c7f0c)
        return g_011c7f0c;
    ppixeldata = new NiPixelData(64, 64, &gNiPoint3StartupSrc, 1, 1);
    ppixels = ppixeldata->NiPixelData_GetPixels(0, 0);
    for (iy = 0; iy < 64; iy++)
    {
        for (ix = 0; ix < 64; ix++)
        {
            ppixels[(iy * 64 + ix) * 4 + 0] = (unsigned char)RandomFloat(0, 255.0f);
            ppixels[(iy * 64 + ix) * 4 + 1] = (unsigned char)RandomFloat(0, 255.0f);
            ppixels[(iy * 64 + ix) * 4 + 2] = (unsigned char)RandomFloat(0, 255.0f);
            ppixels[(iy * 64 + ix) * 4 + 3] = (unsigned char)RandomFloat(0, 255.0f);
        }
    }
    ppixeldata->AddString();
    InitIntArray((int*)&myPrefs);
    g_011c7f0c = new NiTexturingProperty(ppixeldata, NiFixedString("DefaultFullMaskTextureProp"), myPrefs);
    ((NiTexturingProperty*)g_011c7f0c)->SetBaseMapClampMode(0);
    return g_011c7f0c;
}

// The shared landscape header has no explicit copy constructor. Retain this
// copy-construction layout until it can call the shared base copy constructor.
class LandscapeCopy : public TESRegionData
{
  public:
    LandscapeCopy(const LandscapeCopy& kOther);
    virtual ~LandscapeCopy();

    TESTexture* m_pkTexture;
};

// Allocates a copy of this landscape region and its texture.
// @fnv 0x004f2b10
LandscapeCopy* LandscapeOperations::CloneLandscapeData()
{
    LandscapeCopy* pdata = new LandscapeCopy(*(const LandscapeCopy*)this);
    return pdata;
}

// @fnv 0x004f2930
TESRegionDataLandscape::~TESRegionDataLandscape()
{
    TextureDeleter* copy;
    TextureDeleter* tmp;
    if (m_pLandscapeTexture != 0)
    {
        copy = (TextureDeleter*)m_pLandscapeTexture;
        tmp = copy;
        tmp != 0 ? tmp->DestroyTexture(1) : 0;
    }
}

extern double DAT_01023b88;
float __cdecl floor(float);

// The shared landscape virtual string accessors have no parameters, and its
// base lacks the override/priority accessors used by this merge entry point.
struct ThisT
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual int Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10(BSStringT<char>* s);
    virtual void Slot11(BSStringT<char>* s);
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char TESRegionData_GetOverride();
    void FUN_004f15a0(int v);
    bool FUN_004f15c0(unsigned char v);
    unsigned char TESRegionData_GetPriority();
    void __thiscall UpdateFromSource(ThisT* a1, int a2);
};

// @fnv 0x004f2b90
void __thiscall ThisT::UpdateFromSource(ThisT* a1, int a2)
{
    ThisT* a1p = a1;
    BSStringT<char> str3;
    float f;
    if (!a1 || a1->Slot04() != 5 || !a2)
        return;
    if (m_05)
    {
        FUN_004f15a0(a1p->TESRegionData_GetOverride());
        FUN_004f15c0(a1p->TESRegionData_GetPriority());
        a1p->Slot10(&str3);
        Slot11(&str3);
    }
    else
    {
        if (a1p->m_05)
        {
            return;
        }
        else
        {
            if (m_04)
            {
                if (a1p->TESRegionData_GetOverride())
                {
                    if (a1p->TESRegionData_GetPriority() > TESRegionData_GetPriority())
                    {
                        FUN_004f15a0(a1p->TESRegionData_GetOverride());
                        FUN_004f15c0(a1p->TESRegionData_GetPriority());
                        a1p->Slot10(&str3);
                        Slot11(&str3);
                    }
                }
                return;
            }
            else
            {
                if (a1p->TESRegionData_GetOverride())
                {
                    FUN_004f15a0(a1p->TESRegionData_GetOverride());
                    FUN_004f15c0(a1p->TESRegionData_GetPriority());
                    a1p->Slot10(&str3);
                    Slot11(&str3);
                }
                else
                {
                    if (a1p->TESRegionData_GetPriority() > TESRegionData_GetPriority())
                    {
                        a1p->Slot10(&str3);
                        Slot11(&str3);
                    }
                    f = (float)(TESRegionData_GetPriority() * TESRegionData_GetPriority() + (100 - TESRegionData_GetPriority()) * a1p->TESRegionData_GetPriority());
                    f += (float)((100 - a1p->TESRegionData_GetPriority()) * TESRegionData_GetPriority() +
                                 a1p->TESRegionData_GetPriority() * a1p->TESRegionData_GetPriority());
                    f *= DAT_01023b88;
                    FUN_004f15c0((unsigned char)floor(f));
                }
            }
        }
    }
}

// Copy-constructs a landscape region, allocating a new texture and copying the source texture's path into it.
// @fnv 0x004f2870
LandscapeCopy::LandscapeCopy(const LandscapeCopy& kOther) : TESRegionData(kOther)
{
    m_pkTexture = new TESTexture;
    m_pkTexture->AssignTextureName(kOther.m_pkTexture->GetTextureResourceName());
}
