#pragma once

#include "NiPointer.h"

class BSTreeModel;
class BSTreeNode;
class BSXFlags;
class LockFreeMap_TESObjectREFR___BSTreeNode___;
class NiAlphaProperty;
class NiMaterialProperty;
class NiTexture;
class TESObjectTREE;
template <class TKEY, class TVAL> class NiTPointerMap;

class BSTreeManager
{
public:
    NiTPointerMap<TESObjectTREE*, NiPointer<BSTreeModel>*>* m_pLoadedModelMap;
    NiPointer<NiTexture> m_pTreeTexture;
    NiPointer<NiMaterialProperty> m_spMaterialProperty;
    NiPointer<NiAlphaProperty> m_pAlphaProperty;
    NiPointer<BSXFlags> m_pBSXFlags;
    float m_fCurrentWeatherBlend;
    bool m_bFirstOfFourFlags;
    bool m_bSecondOfFourFlags;
    bool ReferenceTreeManagerState;
    bool m_bFourthTreeManagerFlag;
    LockFreeMap_TESObjectREFR___BSTreeNode___* m_pTreeInstanceMap;

    BSTreeManager();
    static void Create(bool);
    static void UpdateTreeInstances();
    BSTreeNode* CreateTreeInstance(int, int);
};
