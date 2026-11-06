
#include "nifixedstring_decls.h"

// @fnv 0x00a2e750
NiFixedString& NiFixedString::operator=(const char* pcString)
{
    char* oldHandle = m_kHandle;
    if (oldHandle != pcString)
    {
        m_kHandle = NiGlobalStringTable::AddString(pcString);
        if (oldHandle != EmptyFS.m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(oldHandle - 8));
    }
    return *this;
}

// These trace entries are unoptimized FaceGen consumers of this inline unit.
// Keep one /O2 unit policy and preserve their original source optimization scope.
#pragma optimize("", off)
#pragma auto_inline(off)
#pragma inline_depth(0)
#include "nifixedstring_facegen.h"

// @fnv 0x0065b410
bool BSFaceGenModel::ApplyTextureCoordinate(FaceGenCoordinates* coord, NiPointer<NiTexture>& texture, unsigned int uiLimit)
{
    // MSVC9 local allocation depends on these names and declaration scopes.
    unsigned int uiWidth; // EGT basis group selected for accumulation
    FaceGenColor kView; // zero fill color
    NiPointer<NiTexture> spTexture(0);
    FaceGenImageView pkImage; // output pixel view
    texture = GetFaceGenManagerValue();
    if (!m_kTextureSlots)
        return false;
    if (!coord)
        coord = BSFaceGenManager::GetFaceGenCoordinates();
    if (!coord)
        return false;
    FUN_00652140();
    if (!FUN_00652040(this)) {
        if (!m_kTextureSlots->m_pTextureData) {
            if (!m_kTextureSlots->GetCharacterSex()) {
                FUN_00652190();
                return false;
            }
            m_kTextureSlots->m_pTextureData = FUN_00659780(m_kTextureSlots->m_kEGTFileName.String());
        }
        if (!m_kTextureSlots->m_pTextureData) {
            FUN_00652190();
            return false;
        }
    }
    if (!m_kTextureSlots->m_pTextureData) {
        FUN_00652190();
        return false;
    }
    unsigned int kColor = 0; // texture width
    unsigned int uiHeight = 0;
    if (m_kTextureSlots->m_pTextureData->basis[0].FUN_0065cea0()) {
        kColor = m_kTextureSlots->m_pTextureData->basis[0].FUN_0065cec0(0)->width;
        uiHeight = m_kTextureSlots->m_pTextureData->basis[0].FUN_0065cec0(0)->height;
    }
    if (!kColor || !uiHeight) {
        FUN_00652190();
        return false;
    }
    unsigned int uiBasis;
    for (uiBasis = 0; uiBasis < 2; ++uiBasis) {
        if (reinterpret_cast<unsigned int>(reinterpret_cast<NiAVObject*>(&reinterpret_cast<FaceGenCoordinateBasis*>(coord->data + 64)[uiBasis])->GetParent()) < m_kTextureSlots->m_pTextureData->basis[uiBasis].FUN_0065cea0()) {
            Warning("MODELS: FaceGen - Tried to apply a coordinate that did not match the EGT basis.");
            FUN_00652190();
            return false;
        }
    }
    kView.a = 0.0f;
    kView.b = kView.a;
    kView.g = kView.b;
    kView.r = kView.g;
    spTexture = reinterpret_cast<NiTexture*>(new FaceGenImage(0));
    reinterpret_cast<TESRecipe*>(static_cast<NiTexture*>(spTexture))->SetSkill(kColor);
    reinterpret_cast<TESRecipe*>(static_cast<NiTexture*>(spTexture))->SetSkillLevel(uiHeight);
    // These scalar accessors were linker-folded with the canonical TESRecipe
    // setters. Their established decorated bindings must be retained.
    FaceGenImage* uiOutHeight = reinterpret_cast<FaceGenImage*>(static_cast<NiTexture*>(spTexture))->GetOrConvertImage();
    uiOutHeight->FUN_0064db50(kColor * uiHeight, &kView);
    unsigned int uiRenderPassIndex = kColor; // output width
    unsigned int piAccum = uiHeight; // output height
    int* uiOutWidth = new int[kColor * uiHeight * 3]; // RGB accumulation buffer
    memset(uiOutWidth, 0, sizeof(int) * kColor * uiHeight * 3);
    uiWidth = 0;
    unsigned int ItemUpdateArray;
    if (uiLimit) {
        ItemUpdateArray = uiLimit;
        if (ItemUpdateArray > m_kTextureSlots->m_pTextureData->basis[uiWidth].FUN_0065cea0())
            ItemUpdateArray = m_kTextureSlots->m_pTextureData->basis[uiWidth].FUN_0065cea0();
    } else {
        ItemUpdateArray = m_kTextureSlots->m_pTextureData->basis[uiWidth].FUN_0065cea0();
    }
    for (unsigned int mode = 0; mode < ItemUpdateArray; ++mode) {
        if (m_kTextureSlots->m_pTextureData->basis[uiWidth].FUN_0065cec0(mode)->width == uiRenderPassIndex) {}
        else ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenModel.cpp", 1162);
        if (m_kTextureSlots->m_pTextureData->basis[uiWidth].FUN_0065cec0(mode)->height == piAccum) {}
        else ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenModel.cpp", 1163);
        FaceGenModeParameters modeData;
        modeData.weight = static_cast<int>(*reinterpret_cast<FaceGenCoordinateBasis*>(coord->data + 64)[uiWidth].FUN_0060b370(mode, 0).FUN_00629ab0() * DAT_010231d8);
        if (!modeData.weight)
            continue;
        modeData.stride = m_kTextureSlots->m_pTextureData->basis[uiWidth].FUN_0065cec0(mode)->width + m_kTextureSlots->m_pTextureData->basis[uiWidth].FUN_0065cec0(mode)->rowPadding;
        for (unsigned int channel = 0; channel < 3; ++channel) {
            FaceGenChannelData channelData;
            channelData.scale = static_cast<int>(m_kTextureSlots->m_pTextureData->basis[uiWidth].FUN_0065cec0(mode)->scale * DAT_010231d8) * modeData.weight;
            channelData.row = m_kTextureSlots->m_pTextureData->basis[uiWidth].FUN_0065cec0(mode)->rows[channel].FUN_0065cc70(0);
            for (unsigned int y = 0; y < piAccum; ++y) {
                for (unsigned int x = 0; x < uiRenderPassIndex; ++x)
                    uiOutWidth[(y * uiRenderPassIndex + x) * 3 + channel] += channelData.row[x] * channelData.scale;
                channelData.row += modeData.stride;
            }
        }
    }
    for (unsigned int channel = 0; channel < 3; ++channel) {
        FaceGenOutputData outputData;
        outputData.multiplier = DAT_01065b9c;
        pkImage = uiOutHeight->_Doraise();
        outputData.output = pkImage.FUN_0064dbd0();
        for (unsigned int y = 0; y < piAccum; ++y) {
            for (unsigned int x = 0; x < uiRenderPassIndex; ++x)
                outputData.output[(y * uiRenderPassIndex + x) * 4 + channel] = uiOutWidth[(y * uiRenderPassIndex + x) * 3 + channel] * outputData.multiplier;
        }
    }
    delete[] uiOutWidth;
    texture = static_cast<NiTexture*>(spTexture)->FUN_0064ceb0(DAT_01065b98, 255.0f, 0.5f, &gNiPoint3StartupSrc);
    FUN_00652190();
    return true;
}

// @fnv 0x0065c3a0
void BSFaceGenModel::ClearTextureData()
{
    if (m_kTextureSlots && m_kTextureSlots->m_pTextureData) {
        delete m_kTextureSlots->m_pTextureData;
        m_kTextureSlots->m_pTextureData = 0;
    }
}

#pragma inline_depth(255)
#pragma auto_inline(on)
#pragma optimize("", on)
