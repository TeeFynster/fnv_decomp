// gamebryo2.2/corelibs/nimain/nidynamiceffect.cpp: NiDynamicEffect (7 functions)

#include "../../../../include/NiDynamicEffect.h"
#include "../../../../include/NiTListItem.h"
#include "../../../../include/BSStreamHeader.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/BSShaderLightingProperty.h"
#include "nidynamiceffect_decls.h"
#include "../../../../include/StrArr.h"

// Exe 0x00a69070 uses NiTPointerList nodes (next, prev, value) and head/tail/count.
static inline NiTPointerList<NiNode*>& EffectNodes(NiTPointerList<NiNode*>& nodes)
{
    return nodes;
}
static inline const NiTPointerList<NiNode*>& EffectNodes(const NiTPointerList<NiNode*>& nodes)
{
    return nodes;
}

static inline void InitializeEffectNodes(NiTPointerList<NiNode*>& nodes)
{
    EffectNodes(nodes).m_kItemCount.m_uiCount = 0;
    EffectNodes(nodes).m_pkHead = 0;
    EffectNodes(nodes).m_pkTail = 0;
}

inline unsigned int NiBinaryStream::Read(void* data, unsigned int size)
{
    unsigned int componentSizes[1] = {size};
    return BinaryRead(data, size, componentSizes, 1);
}

inline unsigned int NiBinaryStream::BinaryRead(void* data, unsigned int size, unsigned int* componentSizes,
                                              unsigned int components)
{
    unsigned int read = m_pfnRead(this, data, size, componentSizes, components);
    m_uiAbsoluteCurrentPos += read;
    return read;
}

// @fnv 0x00a68ea0
void NiDynamicEffect::LoadBinary(NiStream& stream)
{
    NiAVObject::LoadBinary(stream);
    if (stream.m_uiNifFileVersion >= 0x0a010066)
    {
        unsigned char on;
        ReadBinaryValue(stream, on);
        switchState = on != 0;
    }
    if (stream.m_uiNifFileVersion < 0x04010000)
    {
        int count;
        ReadBinaryValue(stream, count);
        for (int i = 0; i < count; ++i)
        {
            unsigned int linkID;
            ReadBinaryValue(stream, linkID);
        }
    }
    if (stream.m_uiNifFileVersion >= 0x0a00010e)
        stream.ReadUnsignedInteger();
}

// @fnv 0x00a69070
void NiDynamicEffect::LinkObject(NiStream& stream)
{
    NiAVObject::LinkObject(stream);
    if (stream.m_uiNifFileVersion >= 0x0a00010e)
    {
        unsigned int count = stream.GetLinkID();
        while (count--)
        {
            NiNode* node = reinterpret_cast<NiNode*>(stream.GetLoadedObject());
            if (node)
            {
                NiTListItem<NiNode*>* item = NiDynamicEffectNewListItem();
                item->m_element = node;
                item->m_pkPrev = 0;
                item->m_pkNext = EffectNodes(unaffectedNodes).m_pkHead;
                if (EffectNodes(unaffectedNodes).m_pkHead)
                    EffectNodes(unaffectedNodes).m_pkHead->m_pkPrev = item;
                else
                    EffectNodes(unaffectedNodes).m_pkTail = item;
                ++EffectNodes(unaffectedNodes).m_kItemCount.m_uiCount;
                EffectNodes(unaffectedNodes).m_pkHead = item;
            }
        }
    }
}

// @fnv 0x00a69320
NiDynamicEffect::NiDynamicEffect()
    : switchState(true), effectType(0xff), pushCount(0), revID(1)
{
    InitializeEffectNodes(shadowGenerator);
    InitializeEffectNodes(unaffectedNodes);
    iIndex = InterlockedIncrement(&DAT_011a9b58);
}

void __fastcall ReleaseStorage_00a5a390(void*);
void __fastcall NiDynamicEffect_DetachAllUnaffectedNodes(void*);
void __cdecl _delete(void*, unsigned int);

extern const void* vftable_NiDynamicEffect;

// The scalar deleting destructor takes its flags on the stack and this in ECX.
// A free fastcall helper preserves that ABI without a stand-in derived class.
// @fnv 0x00a69390
void* __fastcall DestroyNiDynamicEffect(NiDynamicEffect* effect, void*, unsigned int flags)
{
    *reinterpret_cast<void**>(effect) = &vftable_NiDynamicEffect;
    NiDynamicEffect_DetachAllUnaffectedNodes(effect);
    reinterpret_cast<BSShaderLightingProperty*>(&effect->unaffectedNodes)->ClearLights();
    reinterpret_cast<BSShaderLightingProperty*>(&effect->shadowGenerator)->ClearLights();
    ReleaseStorage_00a5a390(effect);
    if (flags & 1)
        _delete(effect, 0xc4);
    return effect;
}

inline unsigned int StrArr::Add(char* const& element)
{
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
inline void StrArr::SetAtInline(unsigned int uiIndex, char* element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element)
            m_usESize++;
    }
    else
    {
        if (element)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != 0)
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}
inline unsigned int StrArr::AddInline(char* element)
{
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAtInline(uiIndex, element);
    return uiIndex;
}

// These NiAVObject entry points retain the signatures used by this unit.
struct NiAVObjectEffectMethods
{
    void AppendEffectProperties(StrArr*);
    bool IsEqual(NiObject*) const;
};
int NiSprintf(char*, unsigned int, const char*, ...);
char* NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString_00a7d5a0(const char*, void*);
extern const char* const g_011f4a28_arg1;
static inline NiNode* GetNext(NiTListItem<NiNode*>*& node)
{
    NiNode*& element = node->m_element;
    node = node->m_pkNext;
    return element;
}
// @fnv 0x00a69140
void NiDynamicEffect::AppendEffectProperties(StrArr* pkStrings)
{
    reinterpret_cast<NiAVObjectEffectMethods*>(this)->AppendEffectProperties(pkStrings);
    (pkStrings->*static_cast<unsigned int (StrArr::*)(char* const&)>(&StrArr::Add))(NiViewerStrings_NiGetViewerString_Title(g_011f4a28_arg1));
    if (EffectNodes(shadowGenerator).m_kItemCount.m_uiCount)
    {
        NiTListItem<NiNode*>* kPos = EffectNodes(shadowGenerator).m_pkHead;
        int i = 0;
        while (kPos)
        {
            NiNode* pkNode = GetNext(kPos);
            char acPrefix[64];
            NiSprintf(acPrefix, 64, "affected node[%d]", i);
            pkStrings->AddInline(NiGetViewerString_00a7d5a0(acPrefix, pkNode));
            i++;
        }
        kPos = EffectNodes(unaffectedNodes).m_pkHead;
        while (kPos)
        {
            NiNode* pkNode = GetNext(kPos);
            char acPrefix[64];
            NiSprintf(acPrefix, 64, "unaffected node[%d]", i);
            pkStrings->AddInline(NiGetViewerString_00a7d5a0(acPrefix, pkNode));
            i++;
        }
    }
}

static __forceinline unsigned int WriteBytes(NiBinaryStream* output, const void* bytes, unsigned int length)
{
    unsigned int componentLength = length;
    unsigned int written = output->m_pfnWrite(output, bytes, length, &componentLength, 1);
    output->m_uiAbsoluteCurrentPos += written;
    return written;
}
static __forceinline void WriteLinkedObject(NiStream* stream, NiNode*& object)
{
    stream->SaveLinkID(reinterpret_cast<const NiObject*>(object));
}
// @fnv 0x00a68f80
void NiDynamicEffect::SaveBinary(NiStream& streamRef)
{
    NiStream* stream = &streamRef;
    NiAVObject::SaveBinary(streamRef);
    unsigned char enabled = switchState;
    NiBinaryStream* output = stream->m_pkOstr;
    WriteBytes(output, &enabled, 1);
    int objectCount = EffectNodes(unaffectedNodes).m_kItemCount.m_uiCount;
    output = stream->m_pkOstr;
    WriteBytes(output, &objectCount, 4);
    if (objectCount > 0)
    {
        NiTListItem<NiNode*>* node = EffectNodes(unaffectedNodes).m_pkTail;
        while (node)
        {
            NiNode*& element = node->m_element;
            node = node->m_pkPrev;
            WriteLinkedObject(stream, element);
        }
    }
}

// Returns false if counts differ or paired entries differ in nullness; otherwise returns true if FUN_00a5a260 succeeds.
// @fnv 0x00a68d80
bool NiDynamicEffect::IsEqual(NiObject* object) const
{
    const NiDynamicEffect* other = static_cast<NiDynamicEffect*>(object);
    if (!reinterpret_cast<const NiAVObjectEffectMethods*>(this)->IsEqual(object))
        return false;
    if (EffectNodes(shadowGenerator).m_kItemCount.m_uiCount != EffectNodes(other->shadowGenerator).m_kItemCount.m_uiCount)
        return false;
    if (EffectNodes(shadowGenerator).m_kItemCount.m_uiCount > 0)
    {
        NiTListItem<NiNode*>* left = EffectNodes(shadowGenerator).m_pkHead;
        NiTListItem<NiNode*>* right = EffectNodes(other->shadowGenerator).m_pkHead;
        while (left)
        {
            NiNode* pLeftNode = GetNext(left);
            NiNode* pRightNode = GetNext(right);
            if (pLeftNode && !pRightNode)
                return false;
            if (!pLeftNode && pRightNode)
                return false;
        }
    }
    if (EffectNodes(unaffectedNodes).m_kItemCount.m_uiCount != EffectNodes(other->unaffectedNodes).m_kItemCount.m_uiCount)
        return false;
    if (EffectNodes(unaffectedNodes).m_kItemCount.m_uiCount > 0)
    {
        NiTListItem<NiNode*>* left = EffectNodes(unaffectedNodes).m_pkHead;
        NiTListItem<NiNode*>* right = EffectNodes(other->unaffectedNodes).m_pkHead;
        while (left)
        {
            NiNode* pLeftNode = GetNext(left);
            NiNode* pRightNode = GetNext(right);
            if (pLeftNode && !pRightNode)
                return false;
            if (!pLeftNode && pRightNode)
                return false;
        }
    }
    return true;
}
