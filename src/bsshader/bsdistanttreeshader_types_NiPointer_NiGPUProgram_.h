// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPOINTER_NIGPUPROGRAM_H
#define FNV_NIPOINTER_NIGPUPROGRAM_H

class NiGPUProgram;
#pragma pack(push, 4)
class NiPointer_NiGPUProgram_
{
  public:
    NiGPUProgram* m_pObject;  // +0x0, 4 bytes
    // NiPointer<NiGPUProgram>
    // void __cdecl NiPointer<NiGPUProgram>::*()
    // NiGPUProgram* __cdecl NiPointer<NiGPUProgram>::*()
    // NiGPUProgram& __cdecl NiPointer<NiGPUProgram>::*()
    // NiGPUProgram* __cdecl NiPointer<NiGPUProgram>::*()
    // operator=
    // operator==
    // operator!=
    // void __cdecl NiPointer<NiGPUProgram>::*()
    // void* __cdecl NiPointer<NiGPUProgram>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPointer_NiGPUProgram_) == 4);
FNV_STATIC_ASSERT(offsetof(NiPointer_NiGPUProgram_, m_pObject) == 0);
#endif
