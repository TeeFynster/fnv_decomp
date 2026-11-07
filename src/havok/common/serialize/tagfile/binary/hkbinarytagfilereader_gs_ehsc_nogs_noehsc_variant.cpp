#include "../../../../../../include/hkBinaryTagfileReader.h"
#include "../../../../../../include/hkError.h"
#include "../../../../../../include/hkOstream.h"

// src/havok/common/serialize/tagfile/binary/hkbinarytagfilereader_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/serialize/tagfile/binary/hkbinarytagfilereader.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/tagfile/binary/hkbinarytagfilereader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/tagfile/binary/hkbinarytagfilereader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct hkDataObjectImpl;

struct DataObjectImplReference
{
    hkDataObjectImpl* m_pClassImpl;
    DataObjectImplReference(hkDataObjectImpl* impl);
};

// @fnv 0x00dc6e50
// src: GUESS 0x00dc6e50 (confidence: low)
DataObjectImplReference hkBinaryTagfileReader::ProcessEntries_00dc6e50()
{
    char buf[512];
    int magic0;
    ReadByteArray(&magic0, 4, 1);
    int magic1;
    ReadByteArray(&magic1, 4, 1);
    if (magic0 == 0xcab00d1e && magic1 == 0xd011face)
    {
        for (int tag = ReadTag(); tag != -1; tag = ReadTag())
        {
            switch (tag)
            {
            case 1: {
                if (ReadTag() != 0)
                {
                    {
                        hkOstream ostr(static_cast<void*>(buf), sizeof(buf));
                        ostr << "Unrecognised tagfile version.";
                        hkError::s_instance->message(1, 0x2ab6036f, buf, ".\\Tagfile\\Binary\\hkBinaryTagfileReader.cpp",
                                              0x1d9);
                    }
                    return DataObjectImplReference(0);
                }
                break;
            }
            case 2: {
                if (readMetadata() == 1)
                {
                    return DataObjectImplReference(0);
                }
                break;
            }
            case 3:
            case 4:
            case 6: {
                return readObjectTopLevel(tag);
            }
            default: {
                return DataObjectImplReference(0);
            }
            }
        }
    }
    else
    {
        hkOstream ostr(static_cast<void*>(buf), sizeof(buf));
        ostr << "This does not look like a binary tagfile (magic number mismatch)";
        hkError::s_instance->message(1, 0x2ab6036f, buf, ".\\Tagfile\\Binary\\hkBinaryTagfileReader.cpp", 0x1c5);
    }
    return DataObjectImplReference(0);
}
