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
        void FUN_00a09130(int trait, Tile* tile, int sourceTrait);
        void FUN_00a09130(int trait, void* source, int sourceTrait);
        void FUN_00a09410(int value);
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

    const char* FUN_00700300();
    void FUN_00700320(int trait, int value);
    void FUN_00700320(int trait, bool value);
    void FUN_007037c0(int value);
    void FUN_0071aa60(bool value);
    bool FUN_0078a1f0();
    NodeObj* FUN_007d5280();
    void FUN_0097cd10(unsigned char value);
    bool FUN_0099ac20();
    void* FUN_004fd3a0();
    Tile* FUN_0045cd60();
    NiNode* FUN_0056c7f0();
    char* FUN_00671d10();
    void* FUN_00a00f30(int trait);
    float FUN_00a011b0();
    float FUN_00a011b0(int trait);
    float FUN_00a011b0(unsigned int trait);
    const char* FUN_00a011f0(int trait);
    const char* FUN_00a011f0(unsigned int trait);
    void FUN_00a012d0(int trait, float value);
    void FUN_00a012d0(int trait, float value, bool propagate);
    void FUN_00a012d0(int trait, float value, int propagate);
    void FUN_00a01350(int trait, const char* text, bool propagate);
    void FUN_00a01350(int trait, int value, bool propagate);
    Tile* FUN_00a01b00();
    Tile* FUN_00a01b00(const char* path);
    Menu* FUN_00a03c90();
    Tile* FUN_00a03eb0(int trait);
    void FUN_00a04640(bool enabled);
    void SetChangeFlag(int trait);
    bool FUN_00a07ed0(int trait);
    bool FUN_00a07fc0(int trait);
    void FUN_00a0b110(int trait);
    bool FUN_00a216b0(float x, float y);

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
