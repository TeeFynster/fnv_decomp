
// src/speedtree/windinfo_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/windinfo.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/windinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/windinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S00b408b0_Vec
{
    float x;
    float y;
    float z;
};

struct S00b408b0_Reader
{
    int GetNextElement();
    S00b408b0_Vec* GetVector3(S00b408b0_Vec* out);
    float CTreeFileAccess_ParseFloat();
    void ProcessAndTransformResult_00b06180();
};

struct S00b408b0_Str
{
    S00b408b0_Str(const char* s);
    void fopen_0044a730(int a, int b);
    ~S00b408b0_Str()
    {
        fopen_0044a730(1, 0);
    }
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
};

struct S00b408b0_Exc
{
    S00b408b0_Exc(S00b408b0_Str& s, int n);
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
};

extern int DAT_01170384;
void __stdcall FUN_00ec7894(void* obj, void* info);

struct S00b408b0_Big
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    int fc8;
    int fcc;
    int fd0;
    int fd4;
    int fd8;
    int fdc;
    int fe0;
    int fe4;
    int fe8;
    int fec;
    int ff0;
    int ff4;
    int ff8;
    int ffc;
    int f100;
};

inline void S00b408b0_Prep()
{
    S00b408b0_Big big;
    big.f38 = 0;
}

struct S00b408b0_Obj
{
    S00b408b0_Vec pos;
    S00b408b0_Vec rot;
    float scale;
    void SIdvWindInfo_Parse(S00b408b0_Reader* r);
};

// @fnv 0x00b408b0
// src: COMMUNITY 0x00b408b0
void S00b408b0_Obj::SIdvWindInfo_Parse(S00b408b0_Reader* r)
{
    S00b408b0_Vec spare;
    S00b408b0_Vec a;
    S00b408b0_Vec b;
    S00b408b0_Vec d;
    S00b408b0_Vec c;
    S00b408b0_Vec e;
    S00b408b0_Prep();
    int tok = r->GetNextElement();
    do
    {
        switch (tok)
        {
        case 5000:
            r->GetVector3(&a);
            break;
        case 5001:
            r->GetVector3(&b);
            break;
        case 5002:
            rot = *r->GetVector3(&c);
            break;
        case 5003:
            r->GetVector3(&d);
            break;
        case 5004:
            pos = *r->GetVector3(&e);
            break;
        case 5005:
            scale = r->CTreeFileAccess_ParseFloat();
            break;
        case 5006:
            r->ProcessAndTransformResult_00b06180();
            break;
        default: {
            S00b408b0_Str msg("malformed general wind information");
            S00b408b0_Exc ex(msg, 0);
            FUN_00ec7894(&ex, &DAT_01170384);
            break;
        }
        }
        tok = r->GetNextElement();
    } while (tok != 1012);
}
