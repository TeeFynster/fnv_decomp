
#include "niavobject_types.h"

// @fnv 0x004eff50
void NiAVObject::UpdateTimeControllers(NiUpdateData& data, bool updateProperties)
{
    NiTimeController* controller;
    if (updateProperties && GetHasPropertyController()) {
        void* position = m_kPropertyList.GetHeadPos();
        while (position) {
            NiProperty* property = m_kPropertyList.GetNext(position);
            if (property && property->GetControllers())
                property->Update(data);
        }
    }
    for (controller = GetControllers(); controller; controller = controller->GetNext())
        controller->Update(data);
}

// @fnv 0x005467e0
void NiAVObject::EnsureWorldBound()
{
    if (!m_kWorldBound) {
        SetObjectBound(new FourComponentFloatVector(0x100, 0));
        m_kWorldBound->SetCenterAndRadius(NiPoint3::ZERO, 0.0f);
    }
}
