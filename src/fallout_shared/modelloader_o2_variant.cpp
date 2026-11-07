
// src/fallout_shared/modelloader_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/modelloader.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.


extern char* _EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct PlaceHolder
{
    char _pad[0x24];
    char* m_h;
    void NiShaderConstantMapEntry_SetVariableName(char*&);
};
// @fnv 0x00e81c60
// src: COMMUNITY 0x00e81c60
void PlaceHolder::NiShaderConstantMapEntry_SetVariableName(char*& kHandle)
{
    char* pkSrc = kHandle;
    if (m_h != pkSrc)
    {
        if (pkSrc != _EmptyFS)
            InterlockedIncrement((long volatile*)(pkSrc - 8));
        if (m_h != _EmptyFS)
            InterlockedDecrement((long volatile*)(m_h - 8));
        m_h = pkSrc;
    }
}
