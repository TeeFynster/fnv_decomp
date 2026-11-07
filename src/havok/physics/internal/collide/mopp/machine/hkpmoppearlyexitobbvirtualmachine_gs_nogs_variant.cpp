// src/havok/physics/internal/collide/mopp/machine/hkpmoppearlyexitobbvirtualmachine_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/internal/collide/mopp/machine/hkpmoppearlyexitobbvirtualmachine.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/internal/collide/mopp/machine/hkpmoppearlyexitobbvirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppearlyexitobbvirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkErrStream.h"
#include "../../../../../../../include/hkError.h"
#include "../../../../../../../include/hkOstream.h"

extern char DAT_0126efba;
void ValidateHavokKeyCode(char* pKey);
struct S_00e647e0_Shape;
struct S_00e647e0_Input { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; S_00e647e0_Shape* m_pCollisionShape; };
struct S_00e647e0_Local { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; };
struct S_00e647e0 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    hkBool m_bHasHit; char unk41; char unk42; char unk43;
    S_00e647e0_Input* m_pRayCastInput;
    void ComputeValues_00e645b0(const void* a, const void* b, const void* c, S_00e647e0_Local* out);
    void queryOBBOnTree(S_00e647e0_Local* l, S_00e647e0_Shape* shape);
    hkBool SetupAndProcessShape(S_00e647e0_Input* input, const void* b, const void* c, const void* d);
};
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

namespace S00e63f10 {

struct CollisionShapeRecord
{
    int m_aiFirstCoordinates[3];
    int m_unk0c;
    int m_aiSecondCoordinates[3];
    int m_unk1c;
    int m_uiX[3];
    int m_fSphereRadius;
    int m_iFirstPostRadiusValue;
    int m_iSecondPostRadiusValue;
    int m_iThirdPostRadiusValue;
    int m_uiPropertyCount;
    int m_iIndex;
    unsigned int m_kProperties[1];
};

}

extern hkError* DAT_01268360;
extern char DAT_010d5100[];
extern char DAT_010ecfbc[];

namespace S00e63f10 {

static inline int S63_Read24(const unsigned char* p)
{
    return (((p[0] << 8) + p[1]) << 8) + p[2];
}

class hkpMoppEarlyExitObbVirtualMachine
{
public:
    void* m_pPrimitiveInfoArray;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_aiFirstCoordinates[3];
    int m_unk1c;
    int m_aiSecondCoordinates[3];
    int m_unk2c;
    int m_uiX[3];
    int m_fSphereRadius;
    hkBool m_bFlag;

    static inline int read24(const unsigned char* PC) { return (((PC[0] << 8) + PC[1]) << 8) + PC[2]; }

    void queryOBBOnTree(const CollisionShapeRecord* query, const unsigned char* PC);
};

}

// @fnv 0x00e63f10
// src: HAVOK_LIB 0x00e63f10
void S00e63f10::hkpMoppEarlyExitObbVirtualMachine::queryOBBOnTree(const CollisionShapeRecord* query, const unsigned char* PC)
{
    CollisionShapeRecord newQuery;
    int command;
    int low;
    int high;
    int x;
    int radius;

    while (1)
    {
        command = *PC;
        if (m_bFlag.m_cBooleanValue)
            return;

        switch (command)
        {
        case 0x13:
            low = PC[1] * 2;
            high = PC[2] * 2;
            x = query->m_uiX[1] + query->m_uiX[2];
            radius = (query->m_fSphereRadius >> 1) + query->m_fSphereRadius + 1;
            goto do_compare;
        case 0x14:
            try {
            low = PC[1] * 2;
            high = PC[2] * 2;
            x = 0xff - query->m_uiX[2] + query->m_uiX[1];
            radius = (query->m_fSphereRadius >> 1) + query->m_fSphereRadius + 1;
            } catch (...) { throw; }
            goto do_compare;
        case 0x15:
            low = PC[1] * 2;
            high = PC[2] * 2;
            x = query->m_uiX[0] + query->m_uiX[2];
            radius = (query->m_fSphereRadius >> 1) + query->m_fSphereRadius + 1;
            goto do_compare;
        case 0x16:
            low = PC[1] * 2;
            high = PC[2] * 2;
            x = 0xff - query->m_uiX[2] + query->m_uiX[0];
            radius = (query->m_fSphereRadius >> 1) + query->m_fSphereRadius + 1;
            goto do_compare;
        case 0x17:
            low = PC[1] * 2;
            high = PC[2] * 2;
            x = query->m_uiX[0] + query->m_uiX[1];
            radius = (query->m_fSphereRadius >> 1) + query->m_fSphereRadius + 1;
            goto do_compare;
        case 0x18:
            low = PC[1] * 2;
            high = PC[2] * 2;
            x = 0xff - query->m_uiX[1] + query->m_uiX[0];
            radius = (query->m_fSphereRadius >> 1) + query->m_fSphereRadius + 1;
            goto do_compare;
        case 0x19:
            low = PC[1] * 2 + PC[1];
            high = PC[2] * 2 + PC[2];
            x = query->m_uiX[0] + query->m_uiX[1] + query->m_uiX[2];
            radius = query->m_fSphereRadius * 4;
            goto do_compare;
        case 0x1a:
            low = PC[1] * 2 + PC[1];
            high = PC[2] * 2 + PC[2];
            x = query->m_uiX[0] + query->m_uiX[1] + (0xff - query->m_uiX[2]);
            radius = query->m_fSphereRadius * 4;
            goto do_compare;
        case 0x1b:
            low = PC[1] * 2 + PC[1];
            high = PC[2] * 2 + PC[2];
            x = query->m_uiX[0] + (0xff - query->m_uiX[1]) + query->m_uiX[2];
            radius = query->m_fSphereRadius * 4;
            goto do_compare;
        case 0x1c:
            low = PC[1] * 2 + PC[1];
            high = PC[2] * 2 + PC[2];
            x = query->m_uiX[0] + (0xff - query->m_uiX[1]) + (0xff - query->m_uiX[2]);
            radius = query->m_fSphereRadius * 4;
        do_compare:
            PC += 4;
            if (x + radius <= high)
                continue;
            {
                int offset = PC[-1];
                PC += offset;
                if (x >= low + radius)
                    continue;
                queryOBBOnTree(query, PC - offset);
            }
            continue;

        case 0x10:
        case 0x11:
        case 0x12:
            low = PC[1];
            high = PC[2];
                                    PC += 4;
            if (query->m_aiFirstCoordinates[command - 0x10] <= high)
                continue;
            {
                int offset = PC[-1];
                PC += offset;
                if (query->m_aiSecondCoordinates[command - 0x10] >= low)
                    continue;
                queryOBBOnTree(query, PC - offset);
            }
            continue;

        case 0x20:
        case 0x21:
        case 0x22:
            high = PC[1];
                                    PC += 3;
            if (query->m_aiFirstCoordinates[command - 0x20] <= high)
                continue;
            {
                int offset = PC[-1];
                PC += offset;
                if (query->m_aiSecondCoordinates[command - 0x20] > high)
                    continue;
                queryOBBOnTree(query, PC - offset);
            }
            continue;

        case 0x23:
        case 0x24:
        case 0x25:
            {
                low = PC[1];
                high = PC[2];
                                                int offsetRight = (PC[3] << 8) + PC[4];
                PC += 7;
                if (query->m_aiFirstCoordinates[command - 0x23] <= high)
                {
                    PC += offsetRight;
                    continue;
                }
                int offsetLeft = (PC[-2] << 8) + PC[-1];
                PC += offsetLeft;
                if (query->m_aiSecondCoordinates[command - 0x23] >= low)
                    continue;
                queryOBBOnTree(query, PC - offsetLeft + offsetRight);
            }
            continue;

        case 0x26:
        case 0x27:
        case 0x28:
            if (query->m_aiFirstCoordinates[command - 0x26] < PC[1] || query->m_aiSecondCoordinates[command - 0x26] >= PC[2])
                return;
            PC += 3;
            continue;

        case 0x29:
        case 0x2a:
        case 0x2b:
            if (m_aiFirstCoordinates[command - 0x29] < S63_Read24(PC + 1) || m_aiSecondCoordinates[command - 0x29] > S63_Read24(PC + 4))
                return;
            PC += 7;
            continue;

        case 0x05:
            high = PC[1];
            PC += 2;
            PC += high;
            continue;
        case 0x06:
            low = PC[1];
            high = PC[2];
            PC += 3;
            PC += (low << 8) + high;
            continue;
        case 0x07:
            {
                low = PC[1];
                int mid = PC[2];
                high = PC[3];
                PC += 4;
                PC += (low << 16) + (mid << 8) + high;
            }
            continue;

        case 0x01:
        case 0x02:
        case 0x03:
        case 0x04:
            {
                int scaleUp = command;
                newQuery.m_iFirstPostRadiusValue = (PC[1] + query->m_iFirstPostRadiusValue) << scaleUp;
                newQuery.m_iSecondPostRadiusValue = (PC[2] + query->m_iSecondPostRadiusValue) << scaleUp;
                newQuery.m_iThirdPostRadiusValue = (PC[3] + query->m_iThirdPostRadiusValue) << scaleUp;
                newQuery.m_iIndex = query->m_iIndex + scaleUp;
                int shift = 16 - newQuery.m_iIndex;
                newQuery.m_aiSecondCoordinates[0] = m_aiSecondCoordinates[0] >> shift;
                newQuery.m_aiSecondCoordinates[0] -= newQuery.m_iFirstPostRadiusValue;
                newQuery.m_aiSecondCoordinates[1] = m_aiSecondCoordinates[1] >> shift;
                newQuery.m_aiSecondCoordinates[1] -= newQuery.m_iSecondPostRadiusValue;
                newQuery.m_aiSecondCoordinates[2] = m_aiSecondCoordinates[2] >> shift;
                newQuery.m_aiSecondCoordinates[2] -= newQuery.m_iThirdPostRadiusValue;
                newQuery.m_aiFirstCoordinates[0] = m_aiFirstCoordinates[0] >> shift;
                newQuery.m_aiFirstCoordinates[0] += 1;
                newQuery.m_aiFirstCoordinates[0] -= newQuery.m_iFirstPostRadiusValue;
                newQuery.m_aiFirstCoordinates[1] = m_aiFirstCoordinates[1] >> shift;
                newQuery.m_aiFirstCoordinates[1] += 1;
                newQuery.m_aiFirstCoordinates[1] -= newQuery.m_iSecondPostRadiusValue;
                newQuery.m_aiFirstCoordinates[2] = m_aiFirstCoordinates[2] >> shift;
                newQuery.m_aiFirstCoordinates[2] += 1;
                newQuery.m_aiFirstCoordinates[2] -= newQuery.m_iThirdPostRadiusValue;
                newQuery.m_uiX[0] = m_uiX[0] >> shift;
                newQuery.m_uiX[0] -= newQuery.m_iFirstPostRadiusValue;
                newQuery.m_uiX[1] = m_uiX[1] >> shift;
                newQuery.m_uiX[1] -= newQuery.m_iSecondPostRadiusValue;
                newQuery.m_uiX[2] = m_uiX[2] >> shift;
                newQuery.m_uiX[2] -= newQuery.m_iThirdPostRadiusValue;
                newQuery.m_fSphereRadius = (m_fSphereRadius >> shift) + 1;
                for (int i = 0; i < 1; i++)
                {
                    newQuery.m_kProperties[i] = query->m_kProperties[i];
                }
                newQuery.m_uiPropertyCount = query->m_uiPropertyCount;
                query = &newQuery;
                PC += 4;
            }
            continue;

        case 0x09:
            {
                int offset = PC[1];
                if (query != &newQuery)
                {
                    newQuery = *query;
                    query = &newQuery;
                }
                newQuery.m_uiPropertyCount += offset;
                PC += 2;
            }
            continue;
        case 0x0a:
            {
                int offset = (PC[1] << 8) + PC[2];
                if (query != &newQuery)
                {
                    newQuery = *query;
                    query = &newQuery;
                }
                newQuery.m_uiPropertyCount += offset;
                PC += 3;
            }
            continue;
        case 0x0b:
            {
                int offset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
                if (query != &newQuery)
                {
                    newQuery = *query;
                    query = &newQuery;
                }
                newQuery.m_uiPropertyCount = offset;
                PC += 5;
            }
            continue;

        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
            {
                int property = *PC - 0x60;
                unsigned int value = PC[1];
                PC += 2;
                newQuery.m_kProperties[property] = value;
            }
            goto propertyCopy;
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
            {
                int property = *PC - 0x64;
                unsigned int value = (PC[1] << 8) + PC[2];
                newQuery.m_kProperties[property] = value;
                PC += 3;
            }
            goto propertyCopy;
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b:
            {
                int property = *PC - 0x68;
                unsigned int value = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
                newQuery.m_kProperties[property] = value;
                PC += 5;
            }
        propertyCopy:
            {
                unsigned int prop0 = newQuery.m_kProperties[0];
                if (query != &newQuery)
                {
                    newQuery = *query;
                    query = &newQuery;
                }
                newQuery.m_kProperties[0] = prop0;
            }
            continue;

        case 0x00:
            return;

        case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37:
        case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f:
        case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47:
        case 0x48: case 0x49: case 0x4a: case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f:
        case 0x50: case 0x51: case 0x52: case 0x53:
            m_bFlag.m_cBooleanValue = true;
            return;

        default:
            {
                char buf[512];
                // Keep the original explicit stream lifetime without automatic unwinding.
                union { char bytes[sizeof(hkErrStream)]; void* alignment; } streamStorage;
                hkErrStream& ostr = *reinterpret_cast<hkErrStream*>(streamStorage.bytes);
                ostr.FUN_00cb1600(buf, sizeof(buf));
                ostr.ProcessAndReturnValue_00cc01c0(DAT_010d5100);
                if (DAT_01268360->message(3, 0x1298fedd, buf, DAT_010ecfbc, 0x156))
                    __debugbreak();
                ostr.FUN_00cc00e0();
            }
            continue;
        }
    }
}
