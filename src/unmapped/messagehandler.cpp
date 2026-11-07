// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" int __tls_index;

__declspec(thread) int DAT_tls_0046e8a0;

// @fnv 0x0046e8a0
// src: XBOX_PDB 0x0046e8a0
int __cdecl MessageHandler_QWarningCount()
{
    return DAT_tls_0046e8a0;
}

extern __declspec(thread) int DAT_tls_0046e8a0;
// @fnv 0x004fffe0
// src: XBOX_PDB 0x004fffe0
void __cdecl MessageHandler_SetWarningCount(int value)
{
    DAT_tls_0046e8a0 = value;
}
