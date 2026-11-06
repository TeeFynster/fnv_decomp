#pragma once

#include "NiInterpController.h"
#include "NiMorphData.h"
#include "NiPointer.h"

class NiGeomMorpherController : public NiInterpController
{
public:
    struct InterpItem
    {
        NiPointer<NiInterpolator> m_spControllerInterpolator;
        float m_fWeight;

        __declspec(nothrow) InterpItem();
        __declspec(nothrow) ~InterpItem();
        static void* operator new[](unsigned int size) throw();
        static void operator delete[](void* p) throw();
    };

    NiGeomMorpherController(NiMorphData* pkData = 0) throw()
        : m_spMorphTargetData(pkData), m_pInterpolatorItems(0)
    {
        m_uiObjectFlags = 0;
        m_bUpdateEnabled = false;
        m_bUpdateNormals = false;
        m_bNeedsUpdate = false;
        m_bUpdateBounds = false;
    }
    virtual ~NiGeomMorpherController() throw();
    virtual NiObject* MakeClone(CloningProcess& kCloning);

    virtual unsigned short GetTargetCount() const;
    virtual unsigned short GetTargetIndex(const char* pcID) const;
    virtual unsigned short GetTargetIndex(const NiFixedString& kID) const;

    virtual void vf58();
    virtual void vf59();

    unsigned int GetNumTargets() const;
    void CopyMemberData(NiGeomMorpherController* pkClone, CloningProcess& kCloning);
    void SetMorphData(NiMorphData* pkMorphData, bool bCanUpdate);
    void ClearInterpolatorArray();

    unsigned short m_uiObjectFlags;
    unsigned char m_aucPad[2];
    NiPointer<NiMorphData> m_spMorphTargetData;
    InterpItem* m_pInterpolatorItems;
    bool m_bUpdateEnabled;
    bool m_bUpdateNormals;
    bool m_bNeedsUpdate;
    bool m_bUpdateBounds;
};

