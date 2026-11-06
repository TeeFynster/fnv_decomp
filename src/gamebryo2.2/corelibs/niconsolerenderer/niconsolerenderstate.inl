#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiTexture.h"
#include "niconsolerenderstate_decls.h"
extern NiFixedString EmptyFS;
extern char g_NiObjectNETExtraDataLock;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
// @fnv 0x00a5bdd0
NiExtraData* NiAVObject::GetExtraData(const NiFixedString& key) {
 if (key.m_kHandle == EmptyFS.m_kHandle) return 0;
 EnterCriticalSection(&g_NiObjectNETExtraDataLock);
 short low = 0;
 short high = m_usExtraDataSize - 1;
 short mid;
 while (low <= high) {
  mid = (high + low) >> 1;
  int diff = reinterpret_cast<int>(key.m_kHandle);
  diff -= reinterpret_cast<int>(reinterpret_cast<NiTexture*>(m_ppkExtra[mid])->GetFilename().m_kHandle);
  if (diff == 0) {
   LeaveCriticalSection(&g_NiObjectNETExtraDataLock);
   return m_ppkExtra[mid];
  }
  if (diff > 0) low = mid + 1;
  else high = mid - 1;
 }
 LeaveCriticalSection(&g_NiObjectNETExtraDataLock);
 return 0;
}
