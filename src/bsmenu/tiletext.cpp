// bsmenu/tiletext.cpp: TileText, FontManager, TextNode (4 functions)

#include "layout_support.h"
#include "../../include/NiObject.h"
#include "../../include/NiFixedString.h"
#include "../../include/TileText.h"
#include "../../include/Font.h"
#include "../../include/FontManager.h"
#include "../../include/FontData.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}

// @fnv 0x00a0bbd0
int TileText::GetType()
{
    return eText;
}

// @fnv 0x00a21a10
void TileText::Init(Tile* apParent, const char* apName, Tile* apReplacedTile)
{
    Tile::Init(apParent, apName, apReplacedTile);
    Set(0xfc4, "", true);
    Set(0xff5, 255.0f, true);
    Set(0xfb2, 255.0f, true);
    Set(0xfb3, 255.0f, true);
    Set(0xfb4, 255.0f, true);
    Set(0xfa9, 255.0f, true);
    Set(0xfa3, 1.0f, true);
    SetTileType(3);
}

int __cdecl FUN_00ec6da0(const char*, const char*);
// @fnv 0x00a225b0
Tile* TileText::SetTraitValue(int aiTrait, float afValue, const char* axString)
{
    if (aiTrait == 0xfc4)
    {
        const char* strValue = GetString(0xfc4);
        if (!strValue || (strValue && !FUN_00ec6da0(axString, strValue)))
        {
            SetImageFlags(2);
            return (Tile*)(void*)this;
        }
    }
    else if (aiTrait == 0xfb7)
    {
        if (GetFloat(0xfb7) != afValue)
        {
            SetImageFlags(2);
            return (Tile*)(void*)this;
        }
    }
    return 0;
}

unsigned __cdecl FUN_0044a670(const char*);

unsigned __cdecl FUN_00403940(unsigned, unsigned);

void* __cdecl FormHeap_Allocate(unsigned);

void __cdecl FormHeap_Free(void*);

void __cdecl FUN_00401460(void*, const void*, unsigned);

// local form of BSStringT<char>: 0x00a21af0 needs the forced-inline default ctor and local destructor/Set split; shared replacement changes bytes.
struct TextString
{

    char* text;
    unsigned short length, capacity;

    TextString(const char*);
    TextString(const TextString&);

    __forceinline void SetLength(unsigned n)
    {
        length = n <= 65535u ? (unsigned short)n : 65535u;
    }

    __forceinline void SetCapacity(unsigned n)
    {
        capacity = n <= 65535u ? (unsigned short)n : 65535u;
    }

    __forceinline TextString()
    {
        text = 0;
        SetLength(0);
        SetCapacity(0);
    }

    unsigned MaxLength()
    {
        return capacity;
    }

    bool Set(const char*, unsigned);

    ~TextString()
    {
        Set(0, 0);
    }
};

struct Color4
{
    float r, g, b, a;
    Color4()
    {
        r = 0.0f;
        g = 0.0f;
        b = 0.0f;
        a = 0.0f;
    }
    Color4(float alpha)
    {
        r = 1.0f;
        g = 1.0f;
        b = 1.0f;
        a = alpha;
    }
    Color4(const float& red, const float& green, const float& blue, float alpha)
    {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }
};

extern float DAT_01095268, DAT_01095264, DAT_01095260;

struct TextParams
{

    int font, alignment;
    Color4 color;
    unsigned char flags;

    int width, height, lines, maxLines, lineCount, unknown;

    bool multibyte;

    TextString text;

    __forceinline TextParams(Color4 initialColor = Color4(DAT_01095268, DAT_01095264, DAT_01095260, 1.0f))
        : color(), text()
    {

        font = 0;
        alignment = 1;
        (void)Color4(initialColor);
        flags = 10;
        width = 0x7fffffff;
        height = 0x7fffffff;
        lines = 0;
        lineCount = 0;
        unknown = 0;
        multibyte = false;
    }
};

struct TileExtra;

inline float Font::GetHeight() const
{
    return pFontData ? pFontData->fBaseLine : 0.0f;
}

inline void Font::SetHeight(float value)
{
    if (pFontData)
        pFontData->fBaseLine = value;
}

inline Font* FontManager::GetFont(int index)
{
    return pFont[index];
}

extern FontManager* DAT_011f33f8;

inline FontManager* FontManager::Get()
{
    return DAT_011f33f8;
}

int __cdecl FUN_004019a0(void*);
int __cdecl FUN_0040b460(void*);

struct TextNode
{

    virtual void unkV00();

    virtual void unkV01();

    virtual void unkV02();

    virtual void unkV03();

    virtual void unkV04();

    virtual void unkV05();

    virtual void unkV06();

    virtual void unkV07();

    virtual void unkV08();

    virtual void unkV09();

    virtual void unkV0A();

    virtual void unkV0B();

    virtual void unkV0C();

    virtual void unkV0D();

    virtual void unkV0E();

    virtual void unkV0F();

    virtual void unkV10();

    virtual void unkV11();

    virtual void unkV12();

    virtual void unkV13();

    virtual void unkV14();

    virtual void unkV15();

    virtual void unkV16();

    virtual void unkV17();

    virtual void unkV18();

    virtual void unkV19();

    virtual void unkV1A();

    virtual void unkV1B();

    virtual void unkV1C();

    virtual void unkV1D();

    virtual void unkV1E();

    virtual void unkV1F();

    virtual void unkV20();

    virtual void unkV21();

    virtual void unkV22();

    virtual void unkV23();

    virtual void unkV24();

    virtual void unkV25();

    virtual void unkV26();

    virtual void unkV27();

    virtual void unkV28();

    virtual void unkV29();

    virtual void unkV2A();

    virtual void unkV2B();

    virtual void unkV2C();

    virtual void unkV2D();

    virtual void unkV2E();

    virtual void unkV2F();

    virtual void unkV30();

    virtual void unkV31();

    virtual void unkV32();

    virtual void unkV33();

    virtual void unkV34();

    virtual void unkV35();

    virtual void unkV36();

    virtual void AddObject(TextNode*, bool);

    int unk04;

    int unk08;

    int unk0C;

    int unk10;

    unsigned short extraCount, extraCapacity;

    int unk18;

    int unk1C;

    int unk20;

    int unk24;

    int unk28;

    int unk2C;

    int unk30;

    int unk34;

    int unk38;

    int unk3C;

    int unk40;

    int unk44;

    int unk48;

    int unk4C;

    int unk50;

    int unk54;

    NiPoint3 position;

    const NiPoint3& GetPosition() const
    {
        return position;
    }

    void SetPosition(const NiPoint3& p)
    {
        position = p;
    }

    void DecRefCount()
    {
        if (!FUN_004019a0(&unk04))
            unkV01();
    }
    int IncRefCount()
    {
        return FUN_0040b460(&unk04);
    }

    void FUN_00a5a040();
    bool SetExtraDataName(TileExtra*);
    bool FUN_00a5ba40(TileExtra*);

    void SetFlag(unsigned mask, bool enabled)
    {
        if (enabled)
            unk30 |= mask;
        else
            unk30 &= ~mask;
    }

    void SetCulled(bool hide)
    {
        SetFlag(1, hide);
    }
};

struct NewTextNode
{

    int unk00;

    int unk04;

    int unk08;

    int unk0C;

    int unk10;

    int unk14;

    int unk18;

    int unk1C;

    int unk20;

    int unk24;

    int unk28;

    int unk2C;

    int unk30;

    int unk34;

    int unk38;

    int unk3C;

    int unk40;

    int unk44;

    int unk48;

    int unk4C;

    int unk50;

    int unk54;

    int unk58;

    int unk5C;

    int unk60;

    int unk64;

    int unk68;

    int unk6C;

    int unk70;

    int unk74;

    int unk78;

    int unk7C;

    int unk80;

    int unk84;

    int unk88;

    int unk8C;

    int unk90;

    int unk94;

    int unk98;

    int unk9C;

    int unkA0;

    int unkA4;

    int unkA8;

    NewTextNode(unsigned);
    static void* operator new(unsigned);
    static void operator delete(void*);
};

struct NodePtr
{

    TextNode* value;

    NodePtr& operator=(TextNode* object)
    {
        if (value != object)
        {
            if (value)
                value->DecRefCount();
            value = object;
            if (value)
                value->IncRefCount();
        }
        return *this;
    }

    operator TextNode*() const
    {
        return value;
    }

    TextNode* operator->() const
    {
        return value;
    }
};

struct NameHeader
{
    long references;
    unsigned length;
};
extern char* DAT_0109b220;
extern void* DAT_01094cfc[];
char* __cdecl FUN_00a5b690(const char*);
struct NameString
{
    char* value;
    NameString(const char* text)
    {
        value = text ? FUN_00a5b690(text) : DAT_0109b220;
    }
    ~NameString()
    {
        if (value != DAT_0109b220)
        {
            NameHeader* header = (NameHeader*)value - 1;
            InterlockedDecrement(&header->references);
        }
    }
};
struct TypeInfo
{
    const char* name;
};
struct TileExtra
{
    void* vtable;
    int references;
    char* name;
    Tile* tile;
    TextNode* node;
    const NameString& FUN_00a62660() const;
    const TypeInfo* GetTypeInfo() const;
    void FUN_00a7b2e0();
    void AssignFixedString(const NameString&);
    TileExtra(Tile* owner, TextNode* object)
    {
        FUN_00a7b2e0();
        vtable = DAT_01094cfc;
        tile = owner;
        node = object;
        NameString extraName("Tileptr");
        AssignFixedString(extraName);
    }
    static void* operator new(unsigned);
    static void operator delete(void*);
};

int __cdecl FUN_00a305b0(char*, unsigned, const char*, ...);
const char* __cdecl FUN_00ec7750(const char*, const char*);
void* __cdecl FUN_00aa1070(unsigned);
void __cdecl FUN_00aa10f0(void*);
char* __cdecl CopyFilePath(char*, unsigned, const char*, unsigned);
int __cdecl FUN_00ec6bd2(char*, unsigned, const char*);
inline bool TextNode::SetExtraDataName(TileExtra* extra)
{
    if (!extra)
        return false;
    if (!extra->FUN_00a62660().value)
    {
        const char* typeName = extra->GetTypeInfo()->name;
        if (typeName && FUN_0044a670(typeName))
        {
            char suffix[6];
            FUN_00a305b0(suffix, 6, "ED%03d", extraCount);
            const char* marker = FUN_00ec7750(typeName, "ExtraData");
            char* newName = (char*)FUN_00aa1070(
                ((marker > typeName ? (unsigned)(marker - typeName) : 0) + FUN_0044a670(suffix) + 1));
            CopyFilePath(newName, ((marker > typeName ? (unsigned)(marker - typeName) : 0) + FUN_0044a670(suffix) + 1),
                         typeName, marker > typeName ? (unsigned)(marker - typeName) : 0);
            FUN_00ec6bd2(newName, ((marker > typeName ? (unsigned)(marker - typeName) : 0) + FUN_0044a670(suffix) + 1),
                         suffix);
            {
                NameString assignedName(newName);
                extra->AssignFixedString(assignedName);
            }
            FUN_00aa10f0(newName);
        }
    }
    return FUN_00a5ba40(extra);
}

float __cdecl FUN_00706e00();

TextNode* __cdecl FUN_00706d30();

void __cdecl FUN_00707930(int);

inline int ClampFont(int number)
{
    return number > 1 ? number : 1;
}

inline float ParseFloatValue(const int& value)
{

    const int number = value;

    return (float)number;
}

// Creates a TextNode using tile text and settings, adds it to a node, and attaches a TileExtra.
// @fnv 0x00a21af0
NiNode* TileText::CalculateNode()
{

    // Locals retain the MSVC stack ordering.

    // kFirst: parent node; countVal: pixel height; maximumX: pixel width.

    // entry: font index; index: line count; kPos: depth; scale: alpha.

    // maximumTmp: maximum lines; oldStateVal: saved font height.

    TextNode* kFirst = GetNiNode();

    float unknown;

    float x = FUN_00a011b0(0xfa1);

    float kPos = -FUN_00a011b0(0xfa2);

    int maximumX = (int)FUN_00a011b0(0xfba);

    int countVal = (int)FUN_00a011b0(0xfbb);

    int maximumTmp = (int)FUN_00a011b0(0xfbc);

    int offsetTmp = (int)FUN_00a011b0(0xff7);

    int kIndex = (int)FUN_00a011b0(0xfb7);

    int entry = ClampFont((int)FUN_00a011b0(0xfb9)) - 1;

    FontManager* data = DAT_011f33f8;

    Font* fontA = data ? data->GetFont(entry) : 0;

    int index = (int)FUN_00a011b0(0xfbd);

    bool allowedX = FUN_00a011b0(0xfbe) > 0.0;

    float scale = FUN_00a011b0(0xfa9);

    unknown = FUN_00a011b0(0xff5);

    Color4 colorX(scale != 0.0 ? scale / 255.0 : 0.0);

    if (!fontA || !fontA->pFontData)
        return 0;

    TextString current(" ");

    const char* text;

    text = FUN_00a011f0(0xfc4);

    if (text && *text)
        current.Set(text, 0);

    if (maximumX < 1)
        maximumX = (int)FUN_00706e00();

    if (maximumTmp < 1)
        maximumTmp = 0x7fffffff;

    int oldStateVal = (int)fontA->GetHeight();

    fontA->SetHeight((float)(oldStateVal + offsetTmp));

    if (allowedX || DAT_011f33f8->bUseNewFonts)
    {

        reinterpret_cast<NodePtr&>(m_pRenderedNodeEntry) = (TextNode*)new NewTextNode(0);

        TextParams params;

        params.font = entry;

        params.width = maximumX ? maximumX : 0x7fffffff;

        params.alignment = kIndex;
        params.color = colorX;

        params.height = countVal ? countVal : 0x7fffffff;

        params.lines = index;
        params.maxLines = maximumTmp;
        params.multibyte = allowedX;

        if (!FontManager::Get()->CreateTextRun(current, &params, reinterpret_cast<NodePtr&>(m_pRenderedNodeEntry)))
            return 0;

        maximumX = params.width;
        countVal = params.height;

        FUN_00a012d0(0xfd5, ParseFloatValue(params.lineCount), true);

        multibyte = params.multibyte;
    }
    else
    {

        TextNode* first = 0;
        TextNode* second = 0;

        reinterpret_cast<NodePtr&>(m_pRenderedNodeEntry) = (TextNode*)new NewTextNode(0);

        fontA->FUN_00a12880(current, &maximumX, &countVal, 0, maximumTmp, kIndex, 10, &colorX, &first, &second);

        SetPosition(first->GetPosition());

        first->SetPosition(NiPoint3(x, (float)(FUN_00a011b0(0xfad) * -0.00800000037997961), kPos));

        ((TextNode*)reinterpret_cast<NodePtr&>(m_pRenderedNodeEntry))->AddObject(first, true);

        if (second)
        {

            second->SetPosition(NiPoint3(x, (float)(FUN_00a011b0(0xfad) * -0.00800000037997961), kPos));

            ((TextNode*)reinterpret_cast<NodePtr&>(m_pRenderedNodeEntry))->AddObject(second, true);
        }
    }

    fontA->SetHeight((float)oldStateVal);

    FUN_00a012d0(0xfb1, ParseFloatValue(maximumX), true);

    FUN_00a012d0(0xfb0, ParseFloatValue(countVal), true);

    SetChangeFlag(9);

    if (IsTraitNonZero(0xfae))
        SetChangeFlag(0x100);

    if (!kFirst)
        kFirst = FUN_00706d30();

    kFirst->AddObject(reinterpret_cast<NodePtr&>(m_pRenderedNodeEntry), true);

    reinterpret_cast<NodePtr&>(m_pRenderedNodeEntry)->SetCulled(!IsTraitNonZero(0xfa3));

    reinterpret_cast<NodePtr&>(m_pRenderedNodeEntry)->FUN_00a5a040();

    FUN_00707930(1);

    reinterpret_cast<NodePtr&>(m_pRenderedNodeEntry)->SetExtraDataName(new TileExtra((Tile*)this, reinterpret_cast<NodePtr&>(m_pRenderedNodeEntry)));

    return (NiNode*)(TextNode*)reinterpret_cast<NodePtr&>(m_pRenderedNodeEntry);
}
