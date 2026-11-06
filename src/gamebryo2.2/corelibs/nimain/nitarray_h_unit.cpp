
// Header unit for gamebryo2.2/corelibs/nimain/nitarray.inl.
// No @fnv markers here; the covered template members are defined and
// marked in the header. This translation unit only forces the covered
// COMDATs to be emitted so their bytes can be compared.
#include "../../../../include/StrArr.h"
#include "nitarray.inl"

void NiTArray_UnitReference()
{
    NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> >* pGroups = 0;
    ActorCombatGroup* pGroup = 0;
    pGroups->SetAt(0, pGroup);
    pGroups->SetSize(0);
    pGroups->SetAtGrow(0, pGroup);
}

// Keep this extension local until the shared StrArr declares ResizeAndClear.
struct ResizableStrArr : StrArr
{
    void ResizeAndClear(int b);
};
// @fnv 0x0096aca0
void ResizableStrArr::ResizeAndClear(int aiCount)
{
    unsigned int uiOldSize = GetSize();
    SetSize(uiOldSize + aiCount);
    for (unsigned int uiIndex = uiOldSize; uiIndex < GetSize(); ++uiIndex)
    {
        char* pElement = 0;
        SetAt(uiIndex, pElement);
    }
}
