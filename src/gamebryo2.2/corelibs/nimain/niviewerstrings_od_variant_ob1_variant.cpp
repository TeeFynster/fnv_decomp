
// src/gamebryo2.2/corelibs/nimain/niviewerstrings_od_variant_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/gamebryo2.2/corelibs/nimain/niviewerstrings_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nimain/niviewerstrings_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niviewerstrings.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/gamebryo2.2/corelibs/nimain/niviewerstrings.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niviewerstrings.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiFixedString.h"

void* __cdecl NiMalloc(unsigned int);
void __cdecl NiFree(void*);

struct ViewerStrings
{
    virtual ~ViewerStrings();
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize)
    {
        if (uiMaxSize == m_usMaxSize)
            return;
        unsigned short i;
        if (uiMaxSize < m_usSize)
        {
            for (i = uiMaxSize; i < m_usSize; i++)
            {
                if (m_pBase[i] != 0)
                {
                    m_pBase[i] = 0;
                    m_usESize--;
                }
            }
            m_usSize = (unsigned short)uiMaxSize;
        }
        char** pSaveBase = m_pBase;
        m_usMaxSize = (unsigned short)uiMaxSize;
        if (uiMaxSize > 0)
        {
            m_pBase = Alloc(m_usMaxSize);
            for (i = 0; i < m_usSize; i++)
                m_pBase[i] = pSaveBase[i];
            for (i = m_usSize; i < m_usMaxSize; i++)
                m_pBase[i] = 0;
        }
        else
        {
            m_pBase = 0;
        }
        Free(pSaveBase);
    }
    static char** Alloc(unsigned int n)
    {
        return (char**)NiMalloc(n * sizeof(char*));
    }
    static void Free(char** p)
    {
        NiFree(p);
    }
    void SetAt(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else
        {
            if (element != 0)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(char* const& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

struct RTTI_Stub
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};
extern RTTI_Stub g_0120436c;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* name);
char* __cdecl NiGetViewerString_00a7d510(const char* label, unsigned int value);
char* __cdecl NiGetViewerString_00a7d490(const char* label, unsigned short value);
char* __cdecl NiGetViewerString_00a7d5a0(const char* label, void* value);

inline NiFixedString::operator const char*() const
{
    return m_kHandle;
}

struct NamedObject
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    NiFixedString m_kName;
    const char* GetName() const
    {
        return m_kName;
    }
};

struct ListItem
{
    ListItem* m_pkNext;
    ListItem* m_pkPrev;
    NamedObject* m_element;
};

struct ObjList
{
    ListItem* m_pkHead;
    ListItem* m_pkTail;
    ListItem* GetHeadPos() const
    {
        return m_pkHead;
    }
    NamedObject* GetNext(ListItem*& kPos) const
    {
        NamedObject* const& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
};

struct EmitterBase
{
    void GetViewerStrings(ViewerStrings* pkStrings);
};

struct MeshEmitter : EmitterBase
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
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    ObjList m_kThirdFollowingStreamField;
    int unkb4;
    unsigned short unkb8;
    unsigned short m_usIndex;
    int unkbc;
    int unkc0;
    unsigned int m_uiMax;

    void BSMasterParticleSystem_GetViewerStrings(ViewerStrings* pkStrings);
};

// @fnv 0x00c5e9f0
// src: XBOX_PDB 0x00c5e9f0
void MeshEmitter::BSMasterParticleSystem_GetViewerStrings(ViewerStrings* pkStrings)
{
    EmitterBase::GetViewerStrings(pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(g_0120436c.GetName()));
    pkStrings->Add(NiGetViewerString_00a7d510("Index", m_uiMax));
    pkStrings->Add(NiGetViewerString_00a7d490("Max Emitter Objs", m_usIndex));
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title("Emitter Objs"));
    ListItem* kPos = m_kThirdFollowingStreamField.GetHeadPos();
    while (kPos)
    {
        NamedObject* pkObj = m_kThirdFollowingStreamField.GetNext(kPos);
        pkStrings->Add(NiGetViewerString_00a7d5a0(pkObj->GetName() ? pkObj->GetName() : "No Name", pkObj));
    }
}
