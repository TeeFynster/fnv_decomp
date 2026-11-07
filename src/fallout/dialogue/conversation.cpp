// fallout/dialogue/conversation.cpp: Conversation and DialogueItem (11 functions)

#include "layout_support.h"

#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/DialogueItem.h"
#include "../../../include/Setting.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESSaveLoadGame.h"

// No shared Conversation header exists yet. Its list prefix and current node are
// shared by the methods bound at 0x0083b850, 0x0083ba50 and 0x0083c8a0.
class Conversation
{
  public:
    BSSimpleList<DialogueItem*> m_kDialogueItems;
    BSSimpleList<DialogueItem*>* m_pCurrentDialogueNode;

    Conversation(Character*, PlayerCharacter*, TESTopic*);
    short GetDialogueItemIndex(DialogueItem* item);
    DialogueItem* GetDialogueItemByIndex(unsigned short);
    unsigned short GetSaveSize_0083bb30();
    void SaveConversation();
    void LoadFromSave();
    void InitLoadGameTES_0083c220();
    void SaveGameBGS_0083c270(BGSSaveFormBuffer*);
    void LoadGameBGS_0083c330(BGSLoadFormBuffer*);
    void InitLoadGame_0083c420(BGSLoadFormBuffer*);
    void FUN_0083c8a0(DialogueItem*);
};

// @fnv 0x0083c7b0
bool DialogueItem::SelectDefaultResponseList()
{
    m_pCurrentResponseList = &m_kResponseList;
    return m_pCurrentResponseList->GetItem() != 0;
}

// Methods missing from the shared header use local declarations with the original call ABI.
void __fastcall ResolveDialogueItemSpeaker(DialogueItem*);
// Resolves each dialogue item speaker until the list is empty or ends.
// @fnv 0x0083c220
// src: COMMUNITY 0x0083c220
void Conversation::InitLoadGameTES_0083c220()
{
    BSSimpleList<DialogueItem*>* current = &m_kDialogueItems;
    while (current && !current->IsEmpty())
    {
        DialogueItem* item = current->GetItem();
        ResolveDialogueItemSpeaker(item);
        current = current->GetNext();
    }
}

// Iterates the dialogue item list and calls each item's load function with the buffer.
// @fnv 0x0083c420
// src: XBOX_PDB 0x0083c420
void Conversation::InitLoadGame_0083c420(BGSLoadFormBuffer* pBuffer)
{
    BSSimpleList<DialogueItem*>* pCurrentElementNext = &m_kDialogueItems;
    while (pCurrentElementNext)
    {
        DialogueItem* pdialogueItem = pCurrentElementNext->GetItem();
        if (pdialogueItem)
        {
            pdialogueItem->RefreshObjectRef(pBuffer);
        }
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
}

void __cdecl _FNV_Warning(const char*);

// Walks the dialogue item list looking for item and returns its index, warning and returning 0 if not found.
// @fnv 0x0083ba50
// src: XBOX_PDB 0x0083ba50
short Conversation::GetDialogueItemIndex(DialogueItem* item)
{
    short index = 0;
    BSSimpleList<DialogueItem*>* node = &m_kDialogueItems;
    while (node && !node->IsEmpty())
    {
        if (item == node->GetItem())
            return index;
        ++index;
        node = node->GetNext();
    }
    _FNV_Warning(
        "DIALOGUE: When trying to get a dialogue item index, the dialogue item was not found in the dialogue items list.");
    return 0;
}

struct FormRecordMetadata
{
    unsigned int iFormID;
    char cUnk4;
    unsigned char iFlags[4];
    unsigned char cVersion;
};
void __fastcall LoadDialogueItemFromSave(DialogueItem*);
extern TESSaveLoadGame* g_TESSaveLoadGame;
TESForm* TESForm_GetFormByNumericID(unsigned int);
void FNV_Warning(const char*, ...);

// Reads a save block header and dialogue item count, creates and appends DialogueItem objects, sets the current item, and warns on buffer overrun or underrun.
// @fnv 0x0083bec0
void Conversation::LoadFromSave()
{
    unsigned short usBlockSize = 0;
    unsigned int uiStartBufferPosition = 0;
    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiBlockHeader;
        g_TESSaveLoadGame->ReadTypedData(&uiBlockHeader, 4);
        if (uiBlockHeader != 0x424c4f4b)
        {
            FormRecordMetadata* pheader =
            reinterpret_cast<FormRecordMetadata*>(g_TESSaveLoadGame->BGSProjectile_GetExplosion());
            if (pheader)
            {
                TESForm* pform = TESForm_GetFormByNumericID(pheader->iFormID);
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xe7,
                    pheader->iFormID, pform->GetName(), pheader->cVersion,
                    *(unsigned int*)pheader->iFlags);
            }
            else
            {
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xe7,
                    g_TESSaveLoadGame->FUN_008df040());
            }
        }
        uiStartBufferPosition = g_TESSaveLoadGame->GetTimeStamp();
        g_TESSaveLoadGame->ReadTypedData(&usBlockSize, 2);
    }
    unsigned short icount;
    g_TESSaveLoadGame->ReadTypedData(&icount, 2);
    for (unsigned int i = 0; i < icount; i++)
    {
        DialogueItem* pdialogueItem = new DialogueItem;
        LoadDialogueItemFromSave(pdialogueItem);
        m_kDialogueItems.AddTail(pdialogueItem);
    }
    short sCurrentItemIndex;
    g_TESSaveLoadGame->ReadTypedData(&sCurrentItemIndex, 2);
    if (sCurrentItemIndex != -1)
        FUN_0083c8a0(GetDialogueItemByIndex(sCurrentItemIndex));
    else
        m_pCurrentDialogueNode = 0;
    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiCurrentBufferPosition = g_TESSaveLoadGame->GetTimeStamp();
        FormRecordMetadata* pheader =
            reinterpret_cast<FormRecordMetadata*>(g_TESSaveLoadGame->BGSProjectile_GetExplosion());
        if (pheader)
        {
            TESForm* pform = TESForm_GetFormByNumericID(pheader->iFormID);
            if (uiCurrentBufferPosition > usBlockSize + uiStartBufferPosition)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    uiCurrentBufferPosition - (usBlockSize + uiStartBufferPosition),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xfd,
                    pheader->iFormID, pform->GetName(), pheader->cVersion,
                    *(unsigned int*)pheader->iFlags);
            else if (uiCurrentBufferPosition < usBlockSize + uiStartBufferPosition)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    usBlockSize + uiStartBufferPosition - uiCurrentBufferPosition,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xfd,
                    pheader->iFormID, pform->GetName(), pheader->cVersion,
                    *(unsigned int*)pheader->iFlags);
        }
        else
        {
            if (uiCurrentBufferPosition > usBlockSize + uiStartBufferPosition)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    uiCurrentBufferPosition - (usBlockSize + uiStartBufferPosition),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xfd,
                    g_TESSaveLoadGame->FUN_008df040());
            else if (uiCurrentBufferPosition < usBlockSize + uiStartBufferPosition)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    usBlockSize + uiStartBufferPosition - uiCurrentBufferPosition,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp", 0xfd,
                    g_TESSaveLoadGame->FUN_008df040());
        }
    }
}

// Walks the dialogue item list until the entry at aiIndex is found and returns its item, warning and returning 0 if the index is out of range.
// @fnv 0x0083bac0
// src: XBOX_PDB 0x0083bac0
DialogueItem* Conversation::GetDialogueItemByIndex(unsigned short aiIndex)
{
    short iElementIndex = 0;
    BSSimpleList<DialogueItem*>* pCurrentElementNext = &m_kDialogueItems;
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        if (iElementIndex == (short)aiIndex)
            return pCurrentElementNext->GetItem();
        iElementIndex++;
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    FNV_Warning(
        "DIALOGUE: When trying to get a dialogue item by its index, the index was larger than the size of the dialogue items list.");
    return 0;
}

// @fnv 0x0083c330
// src: COMMUNITY 0x0083c330
void Conversation::LoadGameBGS_0083c330(BGSLoadFormBuffer* buffer)
{
    short count;
    unsigned int currentItem = buffer->ReadElementCount();
    unsigned int index = 0;

    for (; index < currentItem; ++index)
    {
        DialogueItem* item = new DialogueItem;
        item->LoadDialogueItem(buffer);
        m_kDialogueItems.AddTail(item);
    }

    count = -1;
    buffer->ReadTypedData(static_cast<void*>(&count), 2u);

    if (count != -1)
    {
        FUN_0083c8a0(
            GetDialogueItemByIndex(static_cast<unsigned short>(count)));
    }
}

void __cdecl GenerateConversation(Character*, PlayerCharacter*, Conversation*, TESTopic*);

// @fnv 0x0083b850
Conversation::Conversation(Character* pvA, PlayerCharacter* pvB, TESTopic* pvC)
{
    m_pCurrentDialogueNode = 0;
    GenerateConversation(pvA, pvB, this, pvC);
}

struct FormIDEntry
{
    unsigned int iFormID;
    char cUnk4;
    unsigned char iFlags;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char cVersion;
};
unsigned short __fastcall GetDialogueItemSaveSize(DialogueItem*);
extern Setting g_011de4e8;
TESForm* LookupFormByID(unsigned int);
void SaveWarning(const char*, ...);
static const char kConversationFile[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp";
static const char kSaveSizeFormFormat[] =
    "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s";
static const char kSaveSizeFormat[] = "GetSaveSize(): %-5i ending at line %i in file %s";

// @fnv 0x0083bb30
// src: XBOX_PDB 0x0083bb30
unsigned short Conversation::GetSaveSize_0083bb30()
{
    unsigned short size3 = 0;
    unsigned short start = size3;
    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        size3 += 4;
        size3 += 2;
    }
    size3 += 2;
    BSSimpleList<DialogueItem*>* node5 = &m_kDialogueItems;
    while (node5 && !node5->IsEmpty())
    {
        DialogueItem* item8 = node5->GetItem();
        size3 += GetDialogueItemSaveSize(item8);
        node5 = node5->GetNext();
    }
    size3 += 2;
    if (*g_011de4e8.Bool())
    {
        FormIDEntry* header3 = static_cast<FormIDEntry*>(g_TESSaveLoadGame->GetHitSound());
        if (header3)
        {
            TESForm* form = LookupFormByID(header3->iFormID);
            SaveWarning(kSaveSizeFormFormat, size3 - start, header3->iFormID, form->GetName(),
                        *(unsigned int*)&header3->iFlags, 192, kConversationFile);
        }
        else
        {
            SaveWarning(kSaveSizeFormat, size3 - start, 192, kConversationFile);
        }
    }
    return size3;
}

// The shared DialogueItem header does not yet declare its buffer-save method.
// Fastcall passes this pointer in ECX and a value-type buffer argument on the stack,
// preserving the original member call without declaring another DialogueItem class.
struct DialogueSaveBufferArgument
{
    BGSSaveFormBuffer* buffer;
};
void __fastcall SaveDialogueItemToBuffer(DialogueItem*, DialogueSaveBufferArgument);

// Begins a chunk, saves each non-null item in the node list, ends the chunk, then saves the current node's item index (or -1).
// @fnv 0x0083c270
// src: COMMUNITY 0x0083c270
void Conversation::SaveGameBGS_0083c270(BGSSaveFormBuffer* pkBuffer)
{
    int iCount7 = 0;
    unsigned int uiChunk = pkBuffer->StartVariableSizedValue();
    BSSimpleList<DialogueItem*>* pkNode4 = &m_kDialogueItems;
    while (pkNode4)
    {
        DialogueItem* pkItem = pkNode4->GetItem();
        if (pkItem)
        {
            SaveDialogueItemToBuffer(pkItem, *reinterpret_cast<DialogueSaveBufferArgument*>(&pkBuffer));
            iCount7++;
        }
        pkNode4 = pkNode4->GetNext();
    }
    pkBuffer->SaveVariableSizedValue_00865ff0(iCount7, uiChunk);
    short sIndex3 = m_pCurrentDialogueNode ? GetDialogueItemIndex(m_pCurrentDialogueNode->GetItem()) : -1;
    pkBuffer->SaveData(&sIndex3, 2, 0);
}

void __fastcall SaveDialogueItemToSave(DialogueItem*);

extern "C" char DAT_01015318;
extern "C" char DAT_0101536c;
extern "C" char DAT_010153a0;
extern "C" char DAT_0107db20;
void __cdecl ProgramFlow(const char* fmt, ...);
void __cdecl Warning_005b5e40(const char* fmt, const char* file, int line);

// @fnv 0x0083bc80
void Conversation::SaveConversation()
{
    short sCount_ = 0;                                  // slot -0x10
    short* pSizeTmp = 0;                                // slot -0x04
    unsigned int pCount7 = g_TESSaveLoadGame->GetTimeStamp();  // slot -0x14
    if (*g_011de4e8.Bool())
        pCount7 = g_TESSaveLoadGame->GetTimeStamp();
    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiBlok9 = 0x424c4f4b;  // slot -0x20
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&uiBlok9, 4);
        pSizeTmp = (short*)g_TESSaveLoadGame->GetTimeStamp();
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&sCount_, 2);
    }
    short sIndex5 = 0;                                  // slot -0x1c
    short* sVer7 = (short*)g_TESSaveLoadGame->GetTimeStamp();  // slot -0x0c
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&sIndex5, 2);
    BSSimpleList<DialogueItem*>* uiStartTime4 = &m_kDialogueItems;  // slot -0x18
    while (uiStartTime4 && !uiStartTime4->IsEmpty())
    {
        DialogueItem* pItem = uiStartTime4->GetItem();  // slot -0x24
        SaveDialogueItemToSave(pItem);
        sIndex5++;
        uiStartTime4 = uiStartTime4->GetNext();
    }
    *sVer7 = sIndex5;
    short pNode2 = -1;  // slot -0x08
    if (m_pCurrentDialogueNode)
        pNode2 = GetDialogueItemIndex(m_pCurrentDialogueNode->GetItem());
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&pNode2, 2);
    if (*g_011de4e8.Bool())
    {
        unsigned int uiEndTime4 = g_TESSaveLoadGame->GetTimeStamp();  // slot -0x2c
        void* _pWorld = g_TESSaveLoadGame->GetHitSound();             // slot -0x28
        if (_pWorld)
        {
            TESForm* pForm = TESForm_GetFormByNumericID(*(unsigned int*)_pWorld);  // -0x30
            ProgramFlow(&DAT_010153a0, uiEndTime4 - pCount7, *(unsigned int*)_pWorld, pForm->GetName(),
                         *(unsigned int*)((char*)_pWorld + 5), 0xe1, &DAT_0107db20);
        }
        else
        {
            ProgramFlow(&DAT_0101536c, uiEndTime4 - pCount7, 0xe1, &DAT_0107db20);
        }
    }
    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiEnd7 = g_TESSaveLoadGame->GetTimeStamp();  // slot -0x34
        unsigned int uiStart2 = (unsigned int)pSizeTmp;    // slot -0x38
        if (uiEnd7 > uiStart2 + 0xffff)
            Warning_005b5e40(&DAT_01015318, &DAT_0107db20, 0xe1);
        *pSizeTmp = (short)(uiEnd7 - uiStart2);
    }
}
