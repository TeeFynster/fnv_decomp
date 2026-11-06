
#include "bscriticalsection_console_decls.h"
// @fnv 0x00a0c850
void BSCriticalSectionMap::Unlock(BSCriticalSectionEntry** entry, unsigned int* key, unsigned int* value)
{
    unsigned int uiIndex;
    BSCriticalSectionEntry* pEntry = *entry;
    *key = pEntry->key;
    *value = pEntry->value;
    if (pEntry->next) {
        *entry = pEntry->next;
    } else {
        uiIndex = vfn_4(pEntry->key);
        ++uiIndex;
        for (; uiIndex < bucketCount; ++uiIndex) {
            pEntry = buckets[uiIndex];
            if (pEntry) {
                *entry = pEntry;
                return;
            }
        }
        *entry = 0;
    }
}
