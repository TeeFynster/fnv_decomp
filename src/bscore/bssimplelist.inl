
#include "bssimplelist_decls.h"

// Reusable definitions from bscore/bssimplelist.inl. Explicit pointer-list
// instantiations below select the original linker-folded bodies.

// @fnv 0x0096a2d0
template<class T> BSSimpleList<T>::BSSimpleList()
    : m_item(0), m_pkNext(0)
{
}

// @fnv 0x00470440
template<class T> BSSimpleList<T>::BSSimpleList(T& item)
    : m_item(item), m_pkNext(0)
{
}

// @fnv 0x00905820
template<class T> void BSSimpleList<T>::AddTail(T& item)
{
    if (!item)
        return;
    BSSimpleList<T>* tail = this;
    while (tail->m_pkNext)
        tail = tail->m_pkNext;
    if (tail->m_item)
        tail->m_pkNext = new BSSimpleList<T>(item);
    else
        tail->m_item = item;
}

// @fnv 0x006815c0
template<class T> T& BSSimpleList<T>::GetItem()
{
    return m_item;
}

// @fnv 0x00726070
template<class T> BSSimpleList<T>* BSSimpleList<T>::GetNext()
{
    return m_pkNext;
}

// @fnv 0x008256d0
template<class T> bool BSSimpleList<T>::IsEmpty()
{
    return !m_pkNext && !m_item;
}

// @fnv 0x00470470
template<class T> void BSSimpleList<T>::RemoveAll()
{
    while (m_pkNext)
    {
        BSSimpleList<T>* next = m_pkNext->m_pkNext;
        m_pkNext->m_pkNext = 0;
        delete m_pkNext;
        m_pkNext = next;
    }
    m_item = 0;
}

// @fnv 0x0046ffb0
template<class T> BSSimpleList<T>::~BSSimpleList()
{
    RemoveAll();
}

// @fnv 0x005ae3d0
template<class T> void BSSimpleList<T>::AddHead(T& item)
{
    if (!item)
        return;
    if (m_item)
    {
        BSSimpleList<T>* node = new BSSimpleList<T>(m_item);
        node->m_pkNext = m_pkNext;
        m_pkNext = node;
        m_item = item;
    }
    else
        m_item = item;
}

// @fnv 0x0063f7b0
template<class T> void BSSimpleList<T>::RemoveHead()
{
    if (m_pkNext)
    {
        BSSimpleList<T>* node = m_pkNext;
        m_pkNext = node->m_pkNext;
        m_item = node->m_item;
        node->m_pkNext = 0;
        delete node;
    }
    else
        m_item = 0;
}

template class BSSimpleList<InventoryStackRecord*>;

#include "bssimplelist_packet.h"
// @fnv 0x00413f40
BSSimpleList<TESTopic*>* TESTopicInfoData::GetLinkToList() { return &m_kLinkToList; }
// @fnv 0x00500940
PerkEntryConditionSet* BGSCameraPath::GetConditions() { return &Conditions; }
// @fnv 0x00891170
BSSimpleList<BGSCameraShot*>* BGSCameraPath::GetShotList() { return &m_kCameraShotList; }
// @fnv 0x005a7be0
QuantityData::QuantityData() { SetQuantity(0); }
// @fnv 0x00519550
void TESObjectDOOR::ClearRandomTeleportList() { reinterpret_cast<BSSimpleList<ActorCause*>*>(&m_kRandomTeleportTargets)->RemoveAll(); }
// @fnv 0x00944460
unsigned int GetRandomNumberInRange(int min, int max) { return MersenneTwister::GetRandomGenerator()->IntInRange(min,max); }
// @fnv 0x005e7790
void BGSHeadPart::AddExtraPart(BGSHeadPart* part) { reinterpret_cast<BSSimpleList<SpellItem*>*>(&m_kExtraParts)->AddHead(reinterpret_cast<SpellItem*&>(part)); }
// @fnv 0x004b0680
template <> BSSimpleList<TESWeather::WeatherSound*>::BSSimpleList(TESWeather::WeatherSound* item, BSSimpleList* next) : m_item(item),m_pkNext(next) {}
// @fnv 0x00501170
void BGSTerminal::AddMenuItem(TerminalMenuItem* item) { if(item) reinterpret_cast<BSSimpleList<ScriptVariableInfo*>*>(&m_kMenuItems)->AddTail(reinterpret_cast<ScriptVariableInfo* const&>(item)); }

// @fnv 0x006130e0
BSSimpleList<TESClass*>* TESDataHandler::GetTESClassList() { return reinterpret_cast<BSSimpleList<TESClass*>*>(listClasses); }

// @fnv 0x00500a20
// src: COMMUNITY 0x00500a20
void InterfaceManager::BGSTerminal_SetPassword(Tile* tile) { *reinterpret_cast<Tile**>(reinterpret_cast<char*>(this)+160) = tile; }
