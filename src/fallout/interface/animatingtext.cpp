
// src/fallout/interface/animatingtext.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/animatingtext.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Str6a70
{
    Str6a70& operator=(const char*);
};
struct FUN_00759f20_shell
{
    FUN_00759f20_shell* AssignString(const char* s);
    void AnimatingText_ResetBuffer();
};
// Assigns the string s to this object, calls FUN_006ffda0, and returns this.
// @fnv 0x00759f20
FUN_00759f20_shell* FUN_00759f20_shell::AssignString(const char* apString)
{
    *(Str6a70*)this = apString;
    AnimatingText_ResetBuffer();
    return this;
}

struct TwTile
{
    char pad00[8];
    float m_fAlpha;
    void Tile_Value_SetFloat_00a0a270(float fValue, int iPropagate);
    void SetString(const char* pcText, int iPropagate);
};
unsigned int __cdecl Cmd_GetSessionTime_Execute();
int __cdecl BSstrlen(const char* pcStr);
void __cdecl FUN_00401460(char* pcDest, const char* pcSrc, unsigned int uiCountZ);

struct TwTypewriter
{
    char pad00[8];
    TwTile* m_pkText;
    TwTile* m_pkCursor;
    unsigned int m_uiInterval;
    unsigned int m_uiBlinkOn;
    unsigned int m_uiBlinkOff;
    unsigned int m_uiNextTime;
    unsigned int m_uiNextBlink;
    char* m_pString;
    char pad28;
    bool m_bDone;

    bool AnimatingText_GetDisplayMode();
    bool AnimatingText_GetFlashMode();
    const char* Modelloader_GetReferencedThis();
    unsigned int BSStringT_char_Length();
    bool FUN_00700270(const char* pcText);
    void AnimatingText_Update();
};

// Advances the typewriter text and cursor blink when the interval elapses, copying characters into the buffer and marking the effect done at the end.
// @fnv 0x006ffea0
// src: XBOX_PDB 0x006ffea0
void TwTypewriter::AnimatingText_Update()
{
    if (AnimatingText_GetDisplayMode() && Cmd_GetSessionTime_Execute() >= m_uiNextTime && !m_bDone)
    {
        if (m_pkCursor && !AnimatingText_GetFlashMode())
            m_pkCursor->Tile_Value_SetFloat_00a0a270(1.0f, 1);
        if (m_pkCursor && m_pkText && !Modelloader_GetReferencedThis())
            m_pkCursor->Tile_Value_SetFloat_00a0a270(0.0f, 1);
        if (m_pkText && m_pString && FUN_00700270(m_pString))
        {
            int iStartTmp = BSstrlen(m_pString);
            unsigned int uiCountZ = m_uiNextTime ? (Cmd_GetSessionTime_Execute() - m_uiNextTime) / m_uiInterval + 1 : 1;
            if (uiCountZ > BSStringT_char_Length() - iStartTmp)
            {
                uiCountZ = BSStringT_char_Length() - iStartTmp;
                m_bDone = true;
            }
            FUN_00401460(m_pString + iStartTmp, Modelloader_GetReferencedThis() + iStartTmp, uiCountZ);
            m_pkText->SetString(m_pString, 1);
        }
        else
        {
            m_bDone = true;
        }
        m_uiNextTime = Cmd_GetSessionTime_Execute() + m_uiInterval;
    }
    if (AnimatingText_GetFlashMode() && Cmd_GetSessionTime_Execute() >= m_uiNextBlink)
    {
        if (m_pkCursor->m_fAlpha == 1.0)
        {
            m_pkCursor->Tile_Value_SetFloat_00a0a270(0.0f, 1);
            m_uiNextBlink = Cmd_GetSessionTime_Execute() + m_uiBlinkOff;
        }
        else
        {
            m_pkCursor->Tile_Value_SetFloat_00a0a270(1.0f, 1);
            m_uiNextBlink = Cmd_GetSessionTime_Execute() + m_uiBlinkOn;
        }
    }
}

// FUN_00700110: thiscall, /Od /GS, guarded float-state updates on member m_0c.
struct ObjC
{
    void Tile_Value_SetFloat_00a0a270(float v, int flag);
};
struct ObjD
{
    void SetString(int a, int b);
};

extern "C" int __cdecl BSstrlen(int v);
extern "C" int __cdecl FUN_00401460(int a, int b, int c);

struct FUN_00700110_cls
{
    int unk00;
    int unk04;
    ObjD* m_08;
    ObjC* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_24;
    unsigned char unk28;
    unsigned char m_29;

    bool AnimatingText_GetDisplayMode();
    bool AnimatingText_GetFlashMode();
    int Modelloader_GetReferencedThis();
    void AnimatingText_ForceFinish();
};

// @fnv 0x00700110
// src: XBOX_PDB 0x00700110
void FUN_00700110_cls::AnimatingText_ForceFinish()
{
    if (AnimatingText_GetDisplayMode())
    {
        if (m_29 == 0)
        {
            if (m_0c != 0)
            {
                if (!AnimatingText_GetFlashMode())
                {
                    m_0c->Tile_Value_SetFloat_00a0a270(1.0f, 1);
                }
            }
            if (m_0c != 0 && m_08 != 0 && Modelloader_GetReferencedThis() == 0)
            {
                m_0c->Tile_Value_SetFloat_00a0a270(0.0f, 1);
            }
            if (m_08 != 0 && m_24 != 0)
            {
                FUN_00401460(m_24, Modelloader_GetReferencedThis(), BSstrlen(Modelloader_GetReferencedThis()));
                m_08->SetString(m_24, 1);
                m_29 = 1;
            }
        }
    }
}
