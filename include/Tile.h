#pragma once

#include "NiTPointerList_Tile___.h"
#ifndef FNV_LAYOUT_SUPPORT_H
#include "ShadowSceneLight.h"
#else
__if_exists(LayoutNiPointer)
{
#include "ShadowSceneLight.h"
}
#endif
#include "TESFullName.h"
#include "NiExtraData.h"

class Menu;
class NiNode;
class NiColorAlpha;
class TileShaderProperty;
class Tile__Value;
class NodeObj;

class Tile
{
  public:
    enum VALUE_ACTION
    {
        VA_COPY = 2000,
        VA_ADD = 2001,
        VA_SUB = 2002,
        VA_MULT = 2003,
        VA_DIV = 2004,
        VA_MIN = 2005,
        VA_MAX = 2006,
        VA_MOD = 2007,
        VA_FLOOR = 2008,
        VA_CEIL = 2009,
        VA_ABS = 2010,
        VA_ROUND = 2011,
        VA_GT = 2012,
        VA_GTE = 2013,
        VA_EQ = 2014,
        VA_NEQ = 2015,
        VA_LT = 2016,
        VA_LTE = 2017,
        VA_AND = 2018,
        VA_OR = 2019,
        VA_NOT = 2020,
        VA_ONLYIF = 2021,
        VA_ONLYIFNOT = 2022,
        VA_REF = 2023,
        VA_LEFT_PAREN = 2024,
        VA_RIGHT_PAREN = 2025,
        VA_FIRST_ACTION = 2000,
        VA_LAST_ACTION = 2025,
    };

    class Value
    {
      public:
        int m_iValueId;
        Tile* pTile;
        float fValue;

        __forceinline float GetFloat() { return fValue; }
        void SetBooleanValue(bool value);
        void Tile_Value_AddRefValueAction(int trait, Tile* tile, int sourceTrait);
        void Tile_Value_AddRefValueAction(int trait, void* source, int sourceTrait);
        void Tile_Value_SetFloat(int value);
    };

    class Extra : public NiExtraData
    {
      public:
        Tile* pTile;
        NiNode* pNode;

        Extra(Tile* tile, NiNode* node);
    };

    enum enumType  // values: Xbox PDB Tile::enumType
    {
        eNullType = 0,
        eFirstType = 901,
        eRect = 901,
        eImage = 902,
        eText = 903,
        e3D = 904,
        eMenu = 905,
        eHotRect = 906,
        eWindow = 907,
        eRadial = 908,
        eLastType = 908,
        eTemplate = 999
    };

    enum TILE_FADE_CONTROL_TYPE  // values: Xbox PDB Tile::TILE_FADE_CONTROL_TYPE
    {
        TFCT_STANDARD = 0,
        TFCT_NONLINEAR_LONG_DARK_REPEATING = 1,
        TFCT_BLINK_THRICE = 2,
        TFCT_BLINK_FAST_FADE = 3,
        TFCT_FADE_IN_HOLD_FADE_OUT = 4
    };

    Tile();
    virtual ~Tile();
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetTypeStr();
    virtual bool Unk_05(float arg0, float arg1);
    virtual Tile* SetTraitValue(int valueID, float floatValue, const char* strValue);
    virtual void ClearTextures();
    virtual TileShaderProperty* GetShaderProperty();
    virtual void SetAlphaAndOverlayColor(NiNode* node, float alpha, NiColorAlpha* color);

    static Menu* FindMenuById(unsigned int menuID);
    static Menu* FindMenuById(int menuID);
    static int GetTraitID(const char* name);
    static float GetInterfaceScale();
    static void UpdateAll(bool force);
    static bool IsSpecialTileName(const char* name);

    Menu* GetMenu();
    Menu* GetMenu() const;
    Tile* GetParent();
    Tile* GetParent() const;
    void SetParent(Tile* parent, Tile* replacedChild);
    Tile* GetNamedChild(const char* name);
    Tile* GetNamedChild(const char* name) const;
    Tile* GetChildById(int id);
    Tile* GetChild(int id);
    Tile* ReadFile(const char* path);
    NiNode* GetUnderlyingNode();
    const char* GetTypeName();
    void Release();

    void SetName(const char* name);
    void Set(int trait, int value);
    void Set(int trait, unsigned int value);
    void Set(int trait, float value, bool clearActions);
    void Set(int trait, const char* value, bool clearActions);
    void Set(int trait, const char* value);
    void SetInt(int trait, int value);
    void SetUInt(int trait, unsigned int value);
    void SetFloat(int trait, float value, bool propagate);
    void SetString(int trait, const char* text, bool clearActions);
    void SetTraitFloat(int trait, float value);
    Tile* SetTraitValueAndText(int trait, float value, const char* text);
    void SetTileType(int flags);
    void SetImageFlags(int flags);
    void SetFlag8000(bool value);
    void SetNodeFloat(float value);
    void ResetImage();
    void UpdateTrait(int trait);
    void UpdateEffectChanges(Tile* tile);

    Value* GetValue(int trait);
    Value* GetOrCreateTraitValue(int trait);
    float GetValue(unsigned int trait);
    float GetFloat(int trait);
    float GetFloat(int trait) const;
    void GetFloat(int trait, int value);
    const char* GetString(int trait);
    float GetScreenX();
    float GetScreenY();
    float GetTotalFloat();
    bool ContainsTrait(int trait);
    bool IsVisible();
    bool IsSpecial();
    bool IsPointInside(float x, float y);
    bool IsMenuRendered();
    bool IsAllChildrenFlag0();
    bool IsTraitNonZero(int trait);
    bool GetSpeechChallengeFailure();
    void SetSpeechChallengeFailure(bool value);

    void StartFade(int trait, float start, float end, float duration, int control);
    void SetTraitFade(int trait, float start, float end, float duration, TILE_FADE_CONTROL_TYPE control);
    float Read(int trait);
    bool Done(int trait);
    bool Flag(int trait);
    void Animate(int trait, float start, float end, float duration, int control);
    float AnimValue(int trait);
    void Stop(int trait);
    void Text(int trait, const char* text, bool propagate);
    void Integer(int trait, int value);
    Tile* Parent();
    void Float(int trait, float value, bool propagate);
    void Refresh(bool force);

    const char* GetName_00700300();
    void FUN_00700320(int trait, int value);
    void FUN_00700320(int trait, bool value);
    void FUN_007037c0(int value);
    void SetSpeechChallengeFailure_0071aa60(bool value);
    bool Tile3D_IsPlaying();
    NodeObj* TileImage_GetShaderProp();
    void FUN_0097cd10(unsigned char value);
    bool FindCombatLocation_0099ac20();
    void* TESChallenge_GetFormOne();
    Tile* FUN_0045cd60();
    NiNode* GetModel_0056c7f0();
    char* FUN_00671d10();
    void* Tile_GetValue(int trait);
    float FUN_00a011b0();
    float FUN_00a011b0(int trait);
    float FUN_00a011b0(unsigned int trait);
    const char* Tile_GetString(int trait);
    const char* Tile_GetString(unsigned int trait);
    void Tile_Set(int trait, float value);
    void Tile_Set(int trait, float value, bool propagate);
    void Tile_Set(int trait, float value, int propagate);
    void Tile_Set_00a01350(int trait, const char* text, bool propagate);
    void Tile_Set_00a01350(int trait, int value, bool propagate);
    Tile* Tile_ReadFile();
    Tile* Tile_ReadFile(const char* path);
    Menu* Tile_GetMenu();
    Tile* Tile_GetChildByID(int trait);
    void Tile_UpdateTile(bool enabled);
    void Tile_SetChangeFlag(int trait);
    bool Tile_HasFadeControl(int trait);
    bool Tile_GetFadeFinished(int trait);
    void Tile_PlayTileSound(int trait);
    bool RadialTile_SpecialBoundsCheck(float x, float y);

    NiTPointerList_Tile___ m_kChildTileList;
    BSSimpleArray<Tile__Value*, 8> m_kValues;
    BSStringT<char> StringProvider;
    Tile* pParent;
    NiPointer<NiNode> m_pRenderedNodeEntry;
    unsigned int uiFlags;
    bool m_bFlagAfterUiFlags;
    bool m_bSpeechChallengeFailure;
    unsigned char layoutPadding36[2];
};
