
// src/havok/common/scenedata/environment/hkxenvironment_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/scenedata/environment/hkxenvironment.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/scenedata/environment/hkxenvironment.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/environment/hkxenvironment.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkxEnvironment.h"
#include "../../../../../include/hkError.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkOstream.h"
#include "../../../../../include/hkMemoryRouter.h"

// 0x00c85750 is also bound to hkMemoryRouter::GetMonitorStream in other units.
hkMemoryRouter* getMemoryRouter();


// 0x00cb10d0 is the free C-string length routine declared by hkstring.cpp; no string object is passed.
int __cdecl hkString_strLen(const char* str);

class InlineStorageString
{
  public:
    InlineStorageString();
    __forceinline ~InlineStorageString()
    {
        hkMemoryAllocator& a = getMemoryRouter()->temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            a.bufFree(m_data, m_iCapacityState & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    InlineStorageString& operator=(const InlineStorageString& other);
    InlineStorageString& operator=(const char* s);
    InlineStorageString& operator+=(const char* s);
    const char* cString() const
    {
        return m_data;
    }

    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char m_kStorage[128];
};



struct hkxEnvironmentTransition
{
    int m_uiContentCount;
    int m_pRayCastInput;
    int m_newState;
    int m_pAction;
};

extern const hkxEnvironmentTransition s_transitionTable[32];

struct hkxEnvironmentParser : public hkxEnvironment
{
    void AddVariable(const char* name, const char* value);
    int hkxEnvironment_interpretString(const char* str);
};

// @fnv 0x00e3f520
// src: XBOX_PDB 0x00e3f520
int hkxEnvironmentParser::hkxEnvironment_interpretString(const char* str)
{
    int state = 0;
    int pos = 0;
    InlineStorageString name;
    InlineStorageString value;
    const int length = hkString_strLen(str);

    do
    {
        int input = 4;
        if (pos >= length)
        {
            input = 5;
        }
        else
        {
            const char c = str[pos];
            if (c <= ' ')
            {
                input = 0;
            }
            if (c == '"')
            {
                input = 1;
            }
            else if (c == '=')
            {
                input = 2;
            }
            else if (c == ';')
            {
                input = 3;
            }
        }

        int action = 6;
        int newState = 9;
        int i = 0;
        do
        {
            if (s_transitionTable[i].m_uiContentCount == state && s_transitionTable[i].m_pRayCastInput == input)
            {
                newState = s_transitionTable[i].m_newState;
                action = s_transitionTable[i].m_pAction;
            }
        } while (++i < 32);
        switch (action)
        {
        case 6: {
            char assertBuf[512];
            hkOstream ostr(static_cast<void*>(assertBuf), sizeof(assertBuf));
            ostr << "Error parsing environment string: '" << str << "'";
            hkError::s_instance->message(1, 0xabba7881, assertBuf, ".\\Environment\\hkxEnvironment.cpp", 308);
            return 1;
        }
        case 0:
            pos++;
            break;
        case 1: {
            char tmp[2] = {str[pos], 0};
            name += tmp;
            pos++;
            break;
        }
        case 2: {
            char tmp[2] = {str[pos], 0};
            value += tmp;
            pos++;
            break;
        }
        case 3:
            AddVariable(name.cString(), value.cString());
            name = value = "";
            pos++;
            break;
        case 4:
            AddVariable(name.cString(), 0);
            name = value = "";
            pos++;
            break;
        case 5:
            break;
        default: {
            char assertBuf[512];
            hkOstream ostr(static_cast<void*>(assertBuf), sizeof(assertBuf));
            ostr << "Internal Error: Unknown action parsing environment string: '" << str << "'";
            hkError::s_instance->message(1, 0xabba0032, assertBuf, ".\\Environment\\hkxEnvironment.cpp", 320);
            return 1;
        }
        }
        state = newState;
    } while (state != 8);
    return 0;
}
