// gamebryo2.2/corelibs/niconsolerenderer/niconsolerenderstate_decls.h: declares ShaderPassRenderer

struct DepthDevice;
extern DepthDevice* DAT_0126f0d8;
extern bool DAT_0126f0d0;
typedef int(__stdcall* CreateExFunction)(unsigned int, DepthDevice**);
typedef DepthDevice*(__stdcall* CreateFunction)(unsigned int);
extern CreateExFunction DAT_0126f0e0;
extern CreateFunction DAT_0126f0dc;
bool InitD3D9CreateFunctions();
class ShaderPassRenderer
{
  public:
    static unsigned int Create(unsigned int);
};
