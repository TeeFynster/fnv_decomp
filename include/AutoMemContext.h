#pragma once

enum MEM_CONTEXT;

class AutoMemContext
{
  public:
    MEM_CONTEXT m_eMemoryContext;

    AutoMemContext();
    AutoMemContext(int context);
    AutoMemContext(MEM_CONTEXT context, bool track, const char* file, int line);
    AutoMemContext(MEM_CONTEXT context, bool track, const char* file, unsigned int line);
    AutoMemContext(int context, bool track, const char* file, int line);
    ~AutoMemContext();

    void Enter(int context, bool track, char* file, int line);
    void Leave();
    // The compiler generates __vecDelDtor(unsigned int) from the destructor.
};
