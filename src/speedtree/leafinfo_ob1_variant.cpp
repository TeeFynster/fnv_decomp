// src/speedtree/leafinfo_ob1_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/leafinfo.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/speedtree/leafinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/leafinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../include/NiPoint3.h"
class Sub14_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;

    void AssignSubstring(const Sub14_cls* src, int zero, int value);
};
class Scratch_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
};
extern int DAT_010173f0;
class FUN_00b2e680_cls
{
  public:
    FUN_00b2e680_cls(const FUN_00b2e680_cls& src);

    unsigned char m_b00;
    NiPoint3 m_p04;
    float m_f10;
    Sub14_cls m_s14;
    NiPoint3 m_p30;
    NiPoint3 m_p3c;
    NiPoint3 m_p48;
};
struct S_00b3cf40_Random
{
    S_00b3cf40_Random();
    ~S_00b3cf40_Random();
    float FUN_00b3f130(float lo, float hi);
};
static const float DAT_01022958 = 10000.0f;
struct S_00b3cf40
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
    int m_uiItemCount;  // 40
    int m_rows;         // 44
    int m_iElementCount;         // 48
    float** m_tables;   // 4C
    float* m_verts;     // 50
    float* m_iSlotIds;  // 54
    void Init(int size);
};

#include <string>
#include <vector>
extern const float DAT_01030ff0, DAT_0101df44, DAT_01016248, DAT_010a587c, DAT_01017b78;
struct LeafPoint
{
    float x, y, z;
    LeafPoint()
    {}
    LeafPoint(float value) : x(value), y(value), z(value)
    {}
    LeafPoint(float xx, float yy);
    LeafPoint(float xx, float yy, float zz);
};
extern int DAT_01170384;

struct S00b3d1b0_Str : std::string
{
    S00b3d1b0_Str()
    {}
    S00b3d1b0_Str(const S00b3d1b0_Str& s) : std::string(s)
    {}
};

extern "C" int* __cdecl _errno();
extern "C" char* __cdecl strerror(int);

struct S00b3d1b0_ErrBase
{
    void** vtable;
    int unk04;
    int unk08;
    std::string m_str;

    S00b3d1b0_ErrBase(const std::string& str);
};

inline const std::string* ErrorMessage(const std::string& s)
{
    const std::string* p = &s;
    return p;
}
inline std::string SystemError(int code)
{
    return code ? std::string(strerror(*_errno())) : std::string("");
}
struct S00b3d1b0_Err : S00b3d1b0_ErrBase
{
    S00b3d1b0_Err(const std::string& msg, bool code = false)
        : S00b3d1b0_ErrBase(msg + " [" + (code ? std::string(strerror(*_errno())) : std::string("")) + "]")
    {}
    S00b3d1b0_Err(const std::string& msg, int code)
        : S00b3d1b0_ErrBase(std::string(ErrorMessage(msg)->begin(), msg.end()) + " [" +
                            (code ? std::string(strerror(*_errno())) : std::string()) + "]")
    {}
    S00b3d1b0_Err(const S00b3d1b0_Err&);
    ~S00b3d1b0_Err();
};

struct S00b3d1b0_Name : S00b3d1b0_Str
{
    S00b3d1b0_Name()
    {}
    S00b3d1b0_Name(S00b3d1b0_Str s) : S00b3d1b0_Str(s)
    {}
    S00b3d1b0_Name ProcessEntries_00b09f90();
};

struct S00b3d1b0_Src
{
    int GetNextElement();
    int ReadToken()
    {
        return GetNextElement();
    }
    float CTreeFileAccess_ParseFloat();
    char ProcessAndTransformResult_00b06180();
    LeafPoint GetVector3();
    S00b3d1b0_Str CTreeFileAccess_ParseString();
};

struct S00b3d1b0_Leaf
{
    char m_iWordAt00;
    LeafPoint m_iWordAt04;
    float m_10;
    S00b3d1b0_Name m_14;
    LeafPoint m_30;
    LeafPoint m_3c;
    LeafPoint m_48;

    S00b3d1b0_Leaf()
        : m_iWordAt00(false), m_iWordAt04(DAT_01030ff0), m_10(DAT_0101df44), m_30(DAT_01016248, 1.0f, 0.0f),
          m_3c(DAT_010a587c, DAT_010a587c, 0.0f), m_48(DAT_01017b78, DAT_01017b78, 0.0f)
    {}
};

template <>
__forceinline std::vector<S00b3d1b0_Leaf>::iterator std::vector<S00b3d1b0_Leaf>::erase(const_iterator first_arg,
                                                                                       const_iterator last_arg)
{
    _Destroy(stdext::unchecked_copy(last_arg._Myptr, _Mylast, first_arg._Myptr), _Mylast);
    _Mylast -= last_arg._Myptr - first_arg._Myptr;
    return _Make_iter(first_arg);
}
struct S00b3d1b0_Obj
{
    char m_iWordAt00;
    float m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    std::vector<S00b3d1b0_Leaf> m_10;
    float m_28;
    float m_2c;
    float m_30;
    int m_34;

    void SIdvLeafInfo_Parse(S00b3d1b0_Src* src);
};

// @fnv 0x00b3d1b0
// src: XBOX_PDB 0x00b3d1b0
void S00b3d1b0_Obj::SIdvLeafInfo_Parse(S00b3d1b0_Src* src)
{
    int aTag = src->ReadToken();
    int count;
    int i;
    do
    {
        switch (aTag)
        {
        case 3000:
            m_2c = src->CTreeFileAccess_ParseFloat();
            break;
        case 3001:
            m_34 = src->GetNextElement();
            break;
        case 3002:
            m_30 = src->CTreeFileAccess_ParseFloat();
            break;
        case 3003:
            src->ProcessAndTransformResult_00b06180();
            break;
        case 3004:
            src->CTreeFileAccess_ParseFloat();
            break;
        case 3009:
            m_iWordAt00 = src->ProcessAndTransformResult_00b06180();
            break;
        case 3010:
            m_iWordAt04 = src->CTreeFileAccess_ParseFloat();
            break;
        case 3005:
            src->CTreeFileAccess_ParseFloat();
            break;
        case 3006:
            src->ProcessAndTransformResult_00b06180();
            break;
        case 3007:
            m_28 = src->CTreeFileAccess_ParseFloat();
            break;
        case 3008:
            m_iThirdValue = src->GetNextElement();
            break;
        case 1009: {
            aTag = src->ReadToken();
            count = src->GetNextElement();
            m_10.clear();
            m_10.resize(count);
            for (i = 0; i < count; ++i)
            {
                S00b3d1b0_Leaf leaf;
                aTag = src->ReadToken();
                aTag = src->ReadToken();
                do
                {
                    switch (aTag)
                    {
                    case 4000:
                        leaf.m_iWordAt00 = src->ProcessAndTransformResult_00b06180();
                        break;
                    case 4001:
                        leaf.m_iWordAt04 = src->GetVector3();
                        break;
                    case 4002:
                        leaf.m_10 = src->CTreeFileAccess_ParseFloat();
                        break;
                    case 4003:
                        leaf.m_14 = src->CTreeFileAccess_ParseString();
                        leaf.m_14 = leaf.m_14.ProcessEntries_00b09f90();
                        break;
                    case 4004:
                        leaf.m_30 = src->GetVector3();
                        break;
                    case 4005:
                        leaf.m_3c = src->GetVector3();
                        break;
                    case 4006:
                        leaf.m_48 = src->GetVector3();
                        break;
                    case 4007:
                        src->CTreeFileAccess_ParseFloat();
                        break;
                    default:
                        throw S00b3d1b0_Err("malformed single leaf information", false);
                    }
                    aTag = src->ReadToken();
                } while (aTag != 1008);
                m_10[i] = leaf;
            }
            aTag = src->ReadToken();
            break;
        }
        default:
            throw S00b3d1b0_Err("malformed general leaf information", (int)0);
        }
        aTag = src->ReadToken();
    } while (aTag != 1005);
}
