
#include "nitmap_decls.h"
template<>
// @fnv 0x00844a70
NiTMapItem<unsigned int, BGSReconstructCellSubBlocksMap*>*
NiTMap<unsigned int, BGSReconstructCellSubBlocksMap*>::NewItem() {
    return static_cast<NiTMapItem<unsigned int, BGSReconstructCellSubBlocksMap*>*>(m_kItemCount.Allocate());
}
// @fnv 0x00975cf0
// src: COMMUNITY 0x00975cf0
void BSTempEffect_RemoveAllDecals() {
    g_011d6a30.BSSimpleList_NiPointer_bhkAction_RemoveAll();
    DAT_011d6a20 = 0;
}
// @fnv 0x0048eff0
// src: XBOX_PDB 0x0048eff0
void ModelLoader::ReleaseKFFile_0048eff0(unsigned int key) {
    ModelLoader_ReleaseKF(key, true);
}
