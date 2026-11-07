
// src/fallout_shared/teswater_ob0_noob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob0 /GF (unit src/fallout_shared/teswater.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /Ob1 /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


void* __cdecl operator new(unsigned int uiSize);
void* __cdecl operator new[](unsigned int uiSize);
void __cdecl operator delete(void* pvMem);
void __cdecl operator delete[](void* pvMem);

void* __cdecl C4E7770Malloc(unsigned int uiSize);

struct C4E7770AutoMemHelper
{
    C4E7770AutoMemHelper(int iType, bool bFlag, const char* pcFile, int iLine);
    ~C4E7770AutoMemHelper();

    int m_uiLogicalSize;
};

extern const char g_ac4E7770SourceFile[];
extern const char g_ac4E7770AlphaSetting[];

class C4E7770Point3
{
  public:
    C4E7770Point3();
    C4E7770Point3(float fX, float fY, float fZ);

    float x;
    float y;
    float z;
};

class C4E7770Point2
{
  public:
    C4E7770Point2();
    C4E7770Point2(float fX, float fY);

    float x;
    float y;
};

class C4E7770ColorA
{
  public:
    C4E7770ColorA();
    C4E7770ColorA(float fR, float fG, float fB, float fA);

    float r;
    float g;
    float b;
    float a;
};

class C4E7770Setting
{
  public:
    C4E7770Setting(const char* pcName, float fValue);
    ~C4E7770Setting();

    float* Float();
    C4E7770Setting* SetFloat(float fValue);
    float GetFloat();

    int unk00;
    int unk04;
    int unk08;
};

class C4E7770TriShapeData
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);

    C4E7770TriShapeData(unsigned short usVertices, C4E7770Point3* pkVertex, C4E7770Point3* pkNormal,
                        C4E7770ColorA* pkColor, C4E7770Point2* pkTexture, unsigned short usNumTextureSets,
                        unsigned int eNBTMethod, unsigned short usTriangles, unsigned short* pusTriList);

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
};

class C4E7770QuadFactory
{
  public:
    C4E7770TriShapeData* TESWaterSystem_CreateQuadData_0(float m_fGlyphWidthInPixels, float m_fGlyphExtent, int iUnused, unsigned int uiTiles,
                                      bool bGenerateNormals, bool bColors);
};

// @fnv 0x004e7770
// src: COMMUNITY 0x004e7770
C4E7770TriShapeData* C4E7770QuadFactory::TESWaterSystem_CreateQuadData_0(float m_fGlyphWidthInPixels, float m_fGlyphExtent, int iUnused, unsigned int uiTiles,
                                                      bool bGenerateNormals, bool bColors)
{
    C4E7770Point3* pkNormalsDir;
    C4E7770Point2* pkTexCoordsUV;
    C4E7770TriShapeData* pkShapeData;
    C4E7770Point3* pkVerticesQuad;
    float fTilesTile;
    unsigned short* pusTriangles;
    C4E7770ColorA* pkColors;
    C4E7770AutoMemHelper kMemHelperMem(0x1d, true, g_ac4E7770SourceFile, 0xbac);

    pkVerticesQuad = new C4E7770Point3[4];
    if (!pkVerticesQuad)
        return 0;
    pkVerticesQuad[0] = C4E7770Point3(m_fGlyphWidthInPixels / 2.0, m_fGlyphExtent / 2.0, 0.0f);
    pkVerticesQuad[1] = C4E7770Point3(-m_fGlyphWidthInPixels / 2.0, m_fGlyphExtent / 2.0, 0.0f);
    pkVerticesQuad[2] = C4E7770Point3(-m_fGlyphWidthInPixels / 2.0, -m_fGlyphExtent / 2.0, 0.0f);
    pkVerticesQuad[3] = C4E7770Point3(m_fGlyphWidthInPixels / 2.0, -m_fGlyphExtent / 2.0, 0.0f);

    static C4E7770Point3 s_kNormal(0.0f, 0.0f, 1.0f);

    pkTexCoordsUV = new C4E7770Point2[4];
    if (!pkTexCoordsUV)
    {
        delete[] pkVerticesQuad;
        return 0;
    }

    pusTriangles = (unsigned short*)C4E7770Malloc(6 * sizeof(unsigned short));
    if (!pusTriangles)
    {
        delete[] pkVerticesQuad;
        delete[] pkTexCoordsUV;
        return 0;
    }
    pusTriangles[0] = 0;
    pusTriangles[1] = 1;
    pusTriangles[2] = 2;
    pusTriangles[3] = 0;
    pusTriangles[4] = 2;
    pusTriangles[5] = 3;

    pkNormalsDir = 0;
    if (bGenerateNormals)
    {
        pkNormalsDir = new C4E7770Point3[4];
        if (pkNormalsDir)
        {
            pkNormalsDir[0] = s_kNormal;
            pkNormalsDir[1] = s_kNormal;
            pkNormalsDir[2] = s_kNormal;
            pkNormalsDir[3] = s_kNormal;
        }
    }

    pkColors = 0;
    if (bColors)
    {
        pkColors = new C4E7770ColorA[4];
        if (pkColors)
        {
            static C4E7770Setting s_kAlpha(g_ac4E7770AlphaSetting, 1.0f);
            if (*s_kAlpha.Float() > 1.0)
                s_kAlpha.SetFloat(1.0f);
            else if (*s_kAlpha.Float() < 0.0)
                s_kAlpha.SetFloat(0.0f);
            pkColors[0] = C4E7770ColorA(1.0f, 1.0f, 1.0f, s_kAlpha.GetFloat());
            pkColors[1] = C4E7770ColorA(1.0f, 1.0f, 1.0f, s_kAlpha.GetFloat());
            pkColors[2] = C4E7770ColorA(1.0f, 1.0f, 1.0f, s_kAlpha.GetFloat());
            pkColors[3] = C4E7770ColorA(1.0f, 1.0f, 1.0f, s_kAlpha.GetFloat());
        }
    }

    fTilesTile = 1.0f;
    if (uiTiles != 1)
        fTilesTile = (float)uiTiles;
    pkTexCoordsUV[0] = C4E7770Point2(fTilesTile, 0.0f);
    pkTexCoordsUV[1] = C4E7770Point2(0.0f, 0.0f);
    pkTexCoordsUV[2] = C4E7770Point2(0.0f, fTilesTile);
    pkTexCoordsUV[3] = C4E7770Point2(fTilesTile, fTilesTile);

    pkShapeData =
        new C4E7770TriShapeData(4, pkVerticesQuad, pkNormalsDir, pkColors, pkTexCoordsUV, 1, 0, 2, pusTriangles);
    if (!pkShapeData)
    {
        delete[] pkVerticesQuad;
        delete[] pkNormalsDir;
        delete[] pkTexCoordsUV;
        delete[] pusTriangles;
        delete[] pkColors;
    }
    return pkShapeData;
}
