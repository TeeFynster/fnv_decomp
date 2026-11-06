// gamebryo2.2/corelibs/nianimation/nitextkey_decls.h: declares NiFixedString and TimedTextEntry

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"

#include "../../../../include/NiFixedString.h"
class TimedTextEntry
{
  public:
    float m_fTime;
    NiFixedString m_kText;
    void LoadBinary(NiStream&);
};
