#include "../../include/NiFormArray.h"
#include "../../include/TESIdleForm.h"

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

// @fnv 0x005fe770
NiFormArray* TESIdleForm::AssignParentPath()
{
    return m_pParentPath ? m_pParentPath : (m_pParentPath = new NiFormArray);
}
