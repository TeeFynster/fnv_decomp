#pragma once

#include "Tile.h"

class NiAVObject;
template <class T> class BSStringT;
class NiNodeV;

class Tile3D : public Tile
{
  public:
    static void* operator new(unsigned int bytes);
    static void operator delete(void* memory);

    Tile3D();
    __forceinline bool TestFlag(unsigned int mask) const; // inlined in exe destructor 0x00a20650
    virtual ~Tile3D();
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetTypeStr();
    virtual Tile* SetTraitValue(int valueID, float floatValue, const char* strValue);
    virtual void SetAlphaAndOverlayColor(NiNode* node, float alpha, NiColorAlpha* color);

    void SetParent(Tile3D* parent, Tile3D* replacedChild);
    bool AttachController(NiAVObject* object);
    void LoadTile();
    void RemovePropertyRecursive(char* target);
    void RemovePropertyRecursive(NiAVObject* object);
    void ConvertShadersToTileShader(NiNode* node);
    void ConvertShadersToTileShader(NiAVObject* object);
    bool UpdateAnimation(float value, bool force);
    void UpdateAnimation(float value, int force);
    const char* __thiscall GetTypeName_00a0bdd0();
    NiNodeV* GetModel_0056c7f0();
    bool Tile3D_PlaySequence(const char* sequenceName);

    void* m_pParent;
    void* m_pChildTile;            // +0x3c, zeroed by the constructor 0x00a0bc80
    BSStringT<char> m_kName;       // +0x40, cleared by SetTraitValue 0x00a20c50 (trait 0xfc4)
    BSStringT<char> strFilename;   // +0x48; the destructor 0x00a20650 frees +0x48 then +0x40
};
