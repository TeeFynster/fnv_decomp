
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cc05f0Target
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void Invoke(const char* value, int mode);
};
struct RequestReceiver
{
    int unk00;
    int unk04;
    FUN_00cc05f0Target* unk08;
    RequestReceiver* InvokeFromRequest(void* request);
};
// @fnv 0x00cc05f0
RequestReceiver* RequestReceiver::InvokeFromRequest(void* request)
{
    int* values = (int*)request;
    if (values[0])
        unk08->Invoke((const char*)values[0], values[1] - 1);
    else
        unk08->Invoke("(null)", 6);
    return this;
}

static unsigned char* volatile g_out_slot;
static unsigned int volatile g_val_slot;
// @fnv 0x00da2eb0
// src: HAVOK_LIB 0x00da2eb0
static __declspec(noinline) unsigned char* hkIsDigit(unsigned char* out, unsigned int c)
{
    *out = c >= 0x30u && c <= 0x39u;
    return out;
}
void da2eb0_probe_caller()
{
    hkIsDigit(g_out_slot, g_val_slot);
}
