// fallout/ai/camerashake_decls.h: declares ModelLoader and FileFinder
// This unit calls the game's out-of-line fixed-string constructor and destructor.
#define FNV64_NIFIXEDSTRING_OWN_BODIES
#include "../../../include/NiNode.h"
#undef FNV64_NIFIXEDSTRING_OWN_BODIES

class ModelLoader
{
  public:
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
};
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        NONE = 0
    };
    static FILE_LOCATION Exist(const char*, char*, unsigned int, unsigned int);
};
extern ModelLoader* g_modelLoader;
extern NiNode* DAT_011dfecc;
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
