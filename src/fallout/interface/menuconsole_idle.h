#include "../../../include/NiTListBase.h"
// Authored layout header for fallout/interface/menuconsole.cpp.
//
// The NiTList<BSStringT<char>> machinery and the ConsoleManager body layout below
// assert. The member-function declarations (ConsoleManager/Init/Instance,
// pInstance) are the only additions needed to compile this unit; they do not
// change the layout.
#ifndef FNV_MENUCONSOLE_IDLE_H
#define FNV_MENUCONSOLE_IDLE_H

#include "menuconsole_support.h"

class DFALL_NiTListItem_BSStringT_char_____;
class ConsoleManager;
class NiTList_BSStringT_char___;
typedef NiTListBase<DFALL_NiTListItem_BSStringT_char_____, BSStringT<char> > NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___;
class NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char_____AntiBloatAllocator;
class NiTListItem_BSStringT_char___;
class NiTPointerListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___;

#pragma pack(push, 4)
class DFALL_NiTListItem_BSStringT_char_____
{
  public:
    // void* __cdecl DFALL<NiTListItem<BSStringT<char> > >::*()
    // void __cdecl DFALL<NiTListItem<BSStringT<char> > >::*(void*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DFALL_NiTListItem_BSStringT_char_____) == 1);
#pragma pack(push, 4)
class NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char_____AntiBloatAllocator
    : public DFALL_NiTListItem_BSStringT_char_____
{
  public:
    // base DFALL<NiTListItem<BSStringT<char> > > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char_____AntiBloatAllocator,
                           m_uiCount) == 0);
#pragma pack(push, 4)

#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___, m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___
    : public NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___
{
  public:
    // base NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> > at +0x0, size 12
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(const BSStringT<char>&)
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(const BSStringT<char>&)
    // void* __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*, const BSStringT<char>&)
    // void* __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*, const BSStringT<char>&)
    // const BSStringT<char>& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // const BSStringT<char>& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // const BSStringT<char>& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*)
    // const BSStringT<char>& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*&)
    // const BSStringT<char>& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*&)
    // BSStringT<char> __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // BSStringT<char> __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // BSStringT<char> __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(const BSStringT<char>&)
    // BSStringT<char> __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*&)
    // void* __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(const BSStringT<char>&, void*)
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(int __cdecl (void*, void*)*)
    // NiTListItem<BSStringT<char> >* __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(NiTListItem<BSStringT<char> >*)
    // NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >
    // NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(const NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >&)
    // void* __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___) == 12);
#pragma pack(push, 4)
class NiTList_BSStringT_char___ : public NiTPointerListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___
{
  public:
    // base NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> > at +0x0, size 12
    // NiTList<BSStringT<char> >
    // void __cdecl NiTList<BSStringT<char> >::*()
    // NiTList<BSStringT<char> >& __cdecl NiTList<BSStringT<char> >::*(const NiTList<BSStringT<char> >&)
    // void* __cdecl NiTList<BSStringT<char> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTList_BSStringT_char___) == 12);
#pragma pack(push, 4)
class ConsoleManager
{
  public:
    ScriptCompiler* m_pScriptCompiler;            // +0x0, 4 bytes
    NiTList_BSStringT_char___ m_kOutputLines;     // +0x4, 12 bytes
    NiTList_BSStringT_char___ m_kCommandHistory;  // +0x10, 12 bytes
    int m_iCommandHistoryPosition;                // +0x1C, 4 bytes
    int m_iScrollPosition;                        // +0x20, 4 bytes
    int m_iOutputLineCount;                       // +0x24, 4 bytes
    bool m_bVisible;                              // +0x28, 1 bytes
    unsigned char layoutPadding29[3];
    int iConsoleLineSpacing;  // +0x2C, 4 bytes
    int m_iConsoleX;          // +0x30, 4 bytes
    int m_iConsoleY;          // +0x34, 4 bytes
    char cVisible;            // +0x38, 1 bytes
    bool bIsActive;           // +0x39, 1 bytes
    bool m_bRecordingBatch;   // +0x3A, 1 bytes
    unsigned char layoutPadding3B[1];
    int m_iBatchCommandCount;           // +0x3C, 4 bytes
    char m_aacCommandHistory[20][100];  // +0x40, 2000 bytes
    char m_acOutputFilename[260];       // +0x810, 260 bytes

    bool Idle(int);
    void Print(const char*, const char*);
    void ResetOutputState();
    void DumpTextureList();
    static ConsoleManager* Instance(bool bCreate);

  private:
    // Singleton storage; the constructor is private like the rest of the
    ConsoleManager();
    void Init();
    static ConsoleManager* pInstance;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ConsoleManager) == 2324);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_pScriptCompiler) == 0);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_kOutputLines) == 4);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_kCommandHistory) == 16);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_iCommandHistoryPosition) == 28);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_iScrollPosition) == 32);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_iOutputLineCount) == 36);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_bVisible) == 40);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, iConsoleLineSpacing) == 44);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_iConsoleX) == 48);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_iConsoleY) == 52);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, cVisible) == 56);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, bIsActive) == 57);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_bRecordingBatch) == 58);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_iBatchCommandCount) == 60);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_aacCommandHistory) == 64);
FNV_STATIC_ASSERT(offsetof(ConsoleManager, m_acOutputFilename) == 2064);
#endif
