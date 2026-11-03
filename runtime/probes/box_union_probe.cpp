// Original bounded typed caller. Game method bodies come only from the reviewed
// three-root source-built member. This file defines no replacement Game method.
#include <windows.h>
#include <stdlib.h>
#include "box_union_probe.hpp"

union BoxKey { unsigned int word; unsigned char bytes[4]; };
struct ResetGuard { unsigned before[4]; FUN_00db0920_cls object; unsigned after[4]; };
struct InsertGuard { unsigned before[4]; BoxPointInsertion object; unsigned after[4]; };
struct ResultGuard { unsigned char before; unsigned char value; unsigned char after; };
typedef char BoxKeyLayout[(sizeof(unsigned int)==4 && sizeof(BoxKey)==4) ? 1 : -1];

static void fill_bytes(void* pointer, unsigned count, unsigned char value) {
    unsigned char* bytes = static_cast<unsigned char*>(pointer);
    for (unsigned i=0; i<count; ++i) bytes[i]=value;
}
static bool equal_bytes(const void* a, const void* b, unsigned count) {
    const unsigned char* x=static_cast<const unsigned char*>(a);
    const unsigned char* y=static_cast<const unsigned char*>(b);
    for (unsigned i=0; i<count; ++i) if (x[i]!=y[i]) return false;
    return true;
}
static bool guarded(const unsigned* before, const unsigned* after) {
    for (unsigned i=0; i<4; ++i)
        if (before[i]!=0xa5a5a5a5u || after[i]!=0xa5a5a5a5u) return false;
    return true;
}
bool box_probe_lookup(FUN_00db0920& object, const BoxKey& key, bool expected) {
    ResultGuard result={0x6d,0x7f,0xb2};
    unsigned char* returned=object.ContainsKey(&result.value,key.bytes);
    return returned==&result.value && result.value==(expected?1:0) &&
        result.before==0x6d && result.after==0xb2;
}

int main() {
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);
    _set_error_mode(_OUT_TO_STDERR);
    unsigned resets=0, insertions=0, lookups=0;
    for (unsigned round=0; round<128; ++round) {
        ResetGuard reset; fill_bytes(&reset,sizeof(reset),0xa5);
        if (reset.object.FUN_00db0920()!=&reset.object) return 21;
        ++resets;
        if (!guarded(reset.before,reset.after) || reset.object.count ||
            reset.object.flag20 || reset.object.flag22) return 22;
        for (unsigned i=0; i<8; ++i)
            if (reset.object.entries[i].key0!=0xa5 || reset.object.entries[i].key1!=0xa5 ||
                reset.object.entries[i].value!=0) return 23;

        // Separate declared type; no reinterpretation of reset storage.
        InsertGuard insertion; fill_bytes(&insertion,sizeof(insertion),0xa5);
        insertion.object.count=0;
        insertion.object.flag20=0x3c; insertion.object.flag22=0xc3;
        BoxKey keys[8];
        for (unsigned i=0; i<8; ++i)
            keys[i].word=((0x7100u+round+i)<<16) | ((0x20u+i)<<8) | (0x10u+i);
        BoxKey absent; absent.word=0x7856eeffu;
        if (!box_probe_lookup(insertion.object,absent,false)) return 24;
        ++lookups;
        for (unsigned i=0; i<8; ++i) {
            if (insertion.object.FUN_00db0960(0x13579bdfu,0x2468ace0u,keys[i].bytes)!=(int)i) return 25;
            ++insertions;
            if (insertion.object.count!=i+1 || insertion.object.flag20!=0x3c ||
                insertion.object.flag22!=0xc3 || !guarded(insertion.before,insertion.after)) return 26;
            for (unsigned j=0; j<=i; ++j) {
                if (insertion.object.entries[j].key0!=keys[j].bytes[0] ||
                    insertion.object.entries[j].key1!=keys[j].bytes[1] ||
                    insertion.object.entries[j].value!=(unsigned short)(keys[j].word>>16)) return 27;
            }
            if (!box_probe_lookup(insertion.object,keys[i],true) || !box_probe_lookup(insertion.object,absent,false)) return 28;
            lookups+=2;
            unsigned char snapshot[sizeof(BoxPointInsertion)];
            for (unsigned j=0; j<sizeof(snapshot); ++j)
                snapshot[j]=reinterpret_cast<const unsigned char*>(&insertion.object)[j];
            BoxKey duplicate=keys[i]; duplicate.bytes[2]^=0xff; duplicate.bytes[3]^=0xff;
            if (insertion.object.FUN_00db0960(0,0,duplicate.bytes)!=-1 ||
                !equal_bytes(snapshot,&insertion.object,sizeof(snapshot))) return 29;
            ++insertions;
        }
        // At capacity, the existing eight entries are valid for lookup. The
        // insertion must reject a missing key without touching a ninth entry.
        unsigned char full[sizeof(BoxPointInsertion)];
        for (unsigned j=0; j<sizeof(full); ++j)
            full[j]=reinterpret_cast<const unsigned char*>(&insertion.object)[j];
        if (insertion.object.FUN_00db0960(0,0,absent.bytes)!=-1 ||
            !equal_bytes(full,&insertion.object,sizeof(full)) || !guarded(insertion.before,insertion.after)) return 30;
        ++insertions;
        if (!box_probe_lookup(insertion.object,keys[0],true) || !box_probe_lookup(insertion.object,keys[7],true)) return 31;
        lookups+=2;
    }
    if (resets!=128 || insertions!=2176 || lookups!=2432) return 32;
    static const char event[]="{\"schema\":1,\"rounds\":128,\"reset_calls\":128,\"insertion_calls\":2176,\"lookup_calls\":2432,\"guards_ok\":true,\"capacity\":8}\n";
    DWORD written=0;
    if (!WriteFile(GetStdHandle(STD_OUTPUT_HANDLE),event,sizeof(event)-1,&written,0) || written!=sizeof(event)-1) return 33;
    return 0;
}
