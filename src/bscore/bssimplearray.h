#include "../../include/BSSimpleArray.h"
// bscore/bssimplearray.h: declares SearchBounds
#ifndef BSSIMPLEARRAY_H
#define BSSIMPLEARRAY_H

#include "bssimplearray_private_decls.h"

namespace Tile {
class Value;
}

template <>
// @fnv 0x00A0CB90
unsigned int BSSimpleArray<Tile::Value*, 8>::BinarySearch(Tile::Value*& value, BSSimpleArrayCompare compare)
{
    void* found = bsearch(&value, pBuffer, iSize, sizeof(Tile::Value*), compare);
    if (found == 0)
        return 0xFFFFFFFF;
    unsigned int index = (static_cast<char*>(found) - reinterpret_cast<char*>(pBuffer)) / sizeof(Tile::Value*);
    return index;
}

template <>
// @fnv 0x00A0CF00
unsigned int BSSimpleArray<Tile::Value*, 8>::Add(Tile::Value*& value)
{
    unsigned int index = ReserveIndex();
    for (unsigned int i = 0; i < 1; i = i + 1)
    {
        Tile::Value** destination = pBuffer + index + i;
    }
    pBuffer[index] = value;
    return index;
}

// @fnv 0x006E6DA0
// src: GUESS 0x006e6da0 (confidence: high)
void* __cdecl Memory_ReturnPlacementAddress(unsigned int size, void* place)
{
    return place;
}

class NavMeshInfo;
class TESObjectREFR;
template <class A, class B> class AStarNode;


// @fnv 0x006B9760
template <> BSSimpleArray<AStarNode<const NavMeshInfo*, TESObjectREFR*>*, 1024>::BSSimpleArray()
{

    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(this)->BSSimpleArray_float_1024_InitialSetup(0, false);
}

class GlobalObject_00719b80
{
    void* vtable;

  public:
    GlobalObject_00719b80();
};
// @fnv 0x00719B80
GlobalObject_00719b80::GlobalObject_00719b80()
{
    vtable = &DAT_0106f798;
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(this)->BSSimpleArray_float_1024_InitialSetup(0, false);
}

class GlobalObject_00788300
{
    void* vtable;

  public:
    GlobalObject_00788300();
};
// @fnv 0x00788300
GlobalObject_00788300::GlobalObject_00788300()
{
    vtable = &DAT_01073e50;
    reinterpret_cast<BSSimpleArrayPacketEffect*>(this)->FUN_007883b0(0, false);
}

namespace DebugText {
class DebugTextLine;
}

// @fnv 0x00A11CD0
template <> BSSimpleArray<DebugText::DebugTextLine*, 1024>::BSSimpleArray()
{
    unsigned int unused1;
    unsigned int unused2;

    reinterpret_cast<BSSimpleArrayPacketDebug*>(this)->InitArray(0, false);
}

// @fnv 0x0043B4A0
NiAVObject* NiNode::GetAt(unsigned int index)
{
    return m_kChildren.GetAt(index).operator->();
}

template <>
// @fnv 0x006CFE30
void BSSimpleArray<PacketNodeRecord, 1024>::ReleaseElements(PacketNodeRecord* items, unsigned int count)
{
    for (unsigned int i = 0; i < count; i = i + 1)
        reinterpret_cast<BSSimpleArrayPacketNode*>(items + i)->FUN_006d0510(0);
}

template <>
// @fnv 0x006CFF20
void BSSimpleArray<PathingGraphNode, 1024>::ReleaseElements(PathingGraphNode* items, unsigned int count)
{
    for (unsigned int i = 0; i < count; i = i + 1)
        reinterpret_cast<BSSimpleArrayPacketNode*>(items + i)->FUN_006d0510(0);
}

template <>
// @fnv 0x00726BF0
void BSSimpleArray<NavMeshInfo*, 1024>::InitializeItems(NavMeshInfo** items, unsigned int count)
{
    for (unsigned int i = 0; i < count; i = i + 1)
    {
        void* destination = Memory_ReturnPlacementAddress(sizeof(NavMeshInfo*), items + i);
    }
}

template <>
// @fnv 0x007CB2E0
unsigned int BSSimpleArray<NavMeshInfo*, 1024>::Add(NavMeshInfo*& value)
{
    unsigned int index = reinterpret_cast<BSSimpleArrayPacketReserve*>(this)->FUN_00761540();
    InitializeItems(pBuffer + index, 1);
    pBuffer[index] = value;
    return index;
}

// Candidate address 00a0caf0, 155 bytes.
template <>
// @fnv 0x00A0CAF0
void BSSimpleArray<Tile::Value*, 8>::InsertInSortedOrder(Tile::Value*& value, BSSimpleArrayCompare compare)
{
    struct SearchBounds
    {
        int lower;
        int middle;
        int upper;
    } bounds;
    bounds.lower = 0;
    bounds.upper = iSize - 1;
    while (bounds.lower <= bounds.upper)
    {
        bounds.middle = bounds.lower + ((bounds.upper - bounds.lower) >> 1);
        switch (compare(&value, pBuffer + bounds.middle))
        {
        case 1:
            bounds.lower = bounds.middle + 1;
            break;
        case -1:
            bounds.upper = bounds.middle - 1;
            break;
        case 0:
            bounds.lower = bounds.middle;
            bounds.upper = -1;
            break;
        }
    }
    Insert(bounds.lower, value);
}
// Candidate address 00719b20, 92 bytes.
// Actual member-template declaration and callback ABI come from the supplied signature.
template <>
template <>
// @fnv 0x00719B20
unsigned int BSSimpleArray<BGSBodyPart*, 1024>::Find<BGSBodyPart*>(BGSBodyPart*& value, unsigned int start,
                                                                   bool(__cdecl* compare)(BGSBodyPart*&, BGSBodyPart*&))
{
    for (unsigned int index = start; index < iSize; index = index + 1)
    {
        if (pBuffer && compare(pBuffer[index], value))
            return index;
    }
    return 0xFFFFFFFF;
}
// Candidate address 006cf4a0, 28 bytes.
// This is the real protected virtual override, not a new public fake allocator.
template <>
// @fnv 0x006CF4A0
void BSScrapArray<OffsetData, 1024>::_Deallocate(OffsetData* items)
{
    m_pAllocator->Deallocate(items);
}
// Candidate address 00a1bfa0, 123 bytes.
// Natural trivial lifetime expression may need source-shape investigation under MSVC9.
// Do not add a ButtonIcon destructor definition to force the loop.
template <>
// @fnv 0x00A1BFA0
void BSSimpleArray<ButtonIcon, 1024>::Clear(bool freeBuffer)
{
    if (pBuffer)
    {
        for (unsigned int index = 0; index < iSize; index = index + 1)
            pBuffer[index].~ButtonIcon();
        if (freeBuffer)
        {
            _Deallocate(pBuffer);
            pBuffer = 0;
            pBuffer = 0;
            SimpleArrayStorage = 0;
        }
        iSize = 0;
    }
}
// Candidate address 009f6500, 53 bytes.
// Constructor ownership is inferred as documented; no separate PC annotation claimed.
// @fnv 0x009F6500
SandboxProcedureData::SandboxProcedureData()
{
    pTarget = 0;
    eProcedure = SANDBOX_PROCEDURE_NONE;
    m_iActivityState = 0;
    m_iProcedureData = 0;
}
// Candidate address 006e3de0, 129 bytes; inferred owner/operation requires review.
// Do not define the covered construction helper until its own callees are admissible.
// @fnv 0x006E3DE0
void BSSimpleArray<PathingAvoidNode, 1024>::_InitialSetup(unsigned int capacity, unsigned int initialSize)
{
    pBuffer = 0;
    iSize = 0;
    SimpleArrayStorage = 0;
    if (initialSize > capacity)
        capacity = initialSize;
    if (capacity > 0)
    {
        pBuffer = _Allocate(capacity);
        SimpleArrayStorage = capacity;
    }
    if (initialSize > 0)
    {
        InitializeItems(pBuffer, initialSize);
        iSize = initialSize;
    }
}
// Candidate address 00a0cf60, 160 bytes. Full brief names CRT target _memmove.
template <>
// @fnv 0x00A0CF60
void BSSimpleArray<Tile::Value*, 8>::UpdateEntryValue(Tile::Value** destination, Tile::Value** source,
                                                      unsigned int count)
{
    if (count <= 0)
        return;
    if (destination < source)
    {
        for (unsigned int index = 0; index < count; index = index + 1)
            FUN_00ec7230(destination + index, source + index, sizeof(Tile::Value*));
    }
    else if (destination > source)
    {
        for (int index = count - 1; index >= 0; index = index - 1)
            FUN_00ec7230(destination + index, source + index, sizeof(Tile::Value*));
    }
}
// Candidate address 006e5330, 91 bytes; both external operations have complete-span evidence.
template <>
template <>
// @fnv 0x006E5330
void BSSimpleArray<unsigned int, 1024>::CopyTo<1024>(BSSimpleArray<unsigned int, 1024>* destination)
{
    destination->SetSize(iSize, true);
    for (unsigned int index = 0; index < iSize; index = index + 1)
        destination->GetAt(index) = pBuffer[index];
}

// Retained admissible closest WIP; intentionally unmarked.
// Candidate address 00a0cd50, 422 bytes.
template <> void BSSimpleArray<Tile::Value*, 8>::Insert(unsigned int index, Tile::Value*& value)
{
    if (index == iSize)
        Add(value);
    else
    {
        bool shouldGrow;
        if (iSize == SimpleArrayStorage)
            shouldGrow = true;
        else
            shouldGrow = false;
        if (shouldGrow)
        {
            unsigned int newCapacity = SimpleArrayStorage > 8 ? SimpleArrayStorage + 8 : SimpleArrayStorage * 2;
            Tile::Value** newBuffer = _Allocate(newCapacity);
            UpdateEntryValue(newBuffer, pBuffer, index);
            for (unsigned int i = 0; i < 1; i = i + 1)
            {
                Tile::Value** destination = newBuffer + index + i;
            }
            UpdateEntryValue(newBuffer + index + 1, pBuffer + index, iSize - index);
            _Deallocate(pBuffer);
            pBuffer = 0;
            pBuffer = newBuffer;
            SimpleArrayStorage = newCapacity;
        }
        else
        {
            UpdateEntryValue(pBuffer + index + 1, pBuffer + index, iSize - index);
            for (unsigned int i = 0; i < 1; i = i + 1)
            {
                Tile::Value** destination = pBuffer + index + i;
            }
        }
        iSize = iSize + 1;
        pBuffer[index] = value;
    }
}

// Retained admissible closest WIP; intentionally unmarked.
// Candidate address 00a0d000, 187 bytes, inferred folded Tile callee binding.
template <> unsigned int BSSimpleArray<Tile::Value*, 8>::ReserveIndex()
{
    bool shouldGrow;
    if (iSize == SimpleArrayStorage)
        shouldGrow = true;
    else
        shouldGrow = false;
    if (shouldGrow)
    {
        if (SimpleArrayStorage == 0)
        {
            unsigned int initialCapacity = 4;
            pBuffer = _Allocate(initialCapacity);
            SimpleArrayStorage = initialCapacity;
        }
        else
        {
            unsigned int newCapacity = SimpleArrayStorage > 8 ? SimpleArrayStorage + 8 : SimpleArrayStorage * 2;
            ReallocateStorage(newCapacity, iSize);
            SimpleArrayStorage = newCapacity;
        }
    }
    iSize = iSize + 1;
    return iSize - 1;
}

// Retained admissible closest WIP; intentionally unmarked.
// Candidate address 00a0d0c0, 183 bytes.
// Entire pointer-element operation supports the folded Tile specialization.
// Natural initial form only: prior work found a frame-size/source-shape difference.
template <> void BSSimpleArray<Tile::Value*, 8>::ReallocateStorage(unsigned int newCapacity, unsigned int preserveCount)
{
    if (pBuffer)
    {
        if (preserveCount == SimpleArrayStorage)
            pBuffer = _Reallocate(pBuffer, newCapacity);
        else
        {
            Tile::Value** newBuffer = _Allocate(newCapacity);
            UpdateEntryValue(newBuffer, pBuffer, preserveCount);
            _Deallocate(pBuffer);
            pBuffer = 0;
            pBuffer = newBuffer;
        }
    }
    else
    {
        pBuffer = _Allocate(newCapacity);
        SimpleArrayStorage = newCapacity;
    }
}

#endif
