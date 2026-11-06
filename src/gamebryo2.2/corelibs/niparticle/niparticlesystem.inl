template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

inline const NiPointer<NiPSysModifier>& NiParticleGetNext(NiTListItem<NiPointer<NiPSysModifier> >*& position)
{
    const NiPointer<NiPSysModifier>* value = &position->m_element;
    position = position->m_pkNext;
    return *value;
}

inline NiPSysModifier* NiParticleFindModifier(NiParticleSystem* owner, const NiFixedString& name)
{
    NiTListItem<NiPointer<NiPSysModifier> >* position = owner->m_kModifiers.m_pkHead;
    while (position) {
        NiPSysModifier* modifier = NiParticleGetNext(position);
        if (modifier && modifier->m_kName.m_kHandle == name.m_kHandle)
            return modifier;
    }
    return 0;
}
// @fnv 0x00C31400
void __fastcall FindParticleModifier(NiPSysModifierCtlr* controller, void*)
{
    controller->m_pkTargetModifier = NiParticleFindModifier(
        static_cast<NiParticleSystem*>(controller->m_pkTarget), controller->m_kTargetModifierName);
}
