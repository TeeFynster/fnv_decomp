// fallout/ai/procedure.cpp: free functions (1 function)
#include "procedure_decls.h"

// Returns DAT_011a3fbc[procedureType] when procedureType is in [0,49), otherwise -1.
// @fnv 0x0096a820
// src: XBOX_PDB 0x0096a820
int Procedure_GetProcedureCount(int procedureType)
{
    return procedureType >= 0 && procedureType < 49 ? DAT_011a3fbc[procedureType] : -1;
}
