
// src/havok/common/base/memory/allocator/hkmemoryallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/hkmemoryallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct TargetClass
{
    virtual void f0();
    virtual void f1();
    virtual void __fastcall f2(void* a2);

    void __fastcall hkMemoryAllocator_bufFree(void* a2);
};

// @fnv 0x00cbf1d0
// src: HAVOK_SRC 0x00cbf1d0
void __fastcall TargetClass::hkMemoryAllocator_bufFree(void* a2)
{
    f2(a2);
}

/*
 * worker/candidate.cpp — DRAFT ONLY.
 * Not compiled, not compared, no MATCH claimed. Parent owns verification.
 *
 * Unit: pack/pack.json symbol FUN_00cbf280, 67 bytes, __thiscall member of a
 * five-slot class, three stack parameters, returns a pointer, cleans 0xC.
 *
 * Every identifier below is a placeholder chosen for readability. The binary
 * carries no type, field or method names. The prose describes what the unit
 * provably does (which values reach which callee) and what that most likely
 * means; the two are kept separate and the guesses are marked as guesses.
 */

/*
 * Free helper reached by the unit's only non-virtual call.
 * Canonical mangled symbol: ?FUN_00d2caa0@@YAXPAX0I@Z
 *   @@YAX      -> __cdecl, returns void
 *   PAX, 0     -> void *, void *   (0 back-references the first void *)
 *   I          -> unsigned int
 * so the declaration must be exactly this: a plain C++ free function, not an
 * extern "C" block and not a CRT intrinsic. Its own body is out of scope here;
 * the call site hands it a destination, a source and a byte count, which is
 * consistent with a bounded copy (inference, not verified).
 */
void hkMemUtil_memCpy_00d2caa0(void* dest, void* src, unsigned int count);

/*
 * Block passed as the unit's third parameter.
 * The unit forwards the pointer unchanged to the slot +0x0C method and, after
 * that call returns, reads the dword at +0x00 of the same block as a signed
 * bound. Whether the block is a plain struct or has its own vptr at +0x00 is
 * not decidable from this unit; a named field is the narrower assumption, so
 * it is used here.
 */
struct SFun00cbf280Args
{
    int limit; /* +0x00: caller-supplied byte bound, read signed */
};

/*
 * Owner class of the unit. The five declarations place the two methods the
 * unit actually calls at byte offsets +0x0C and +0x10; slots +0x00, +0x04 and
 * +0x08 are declared only to hold that layout and are never invoked here.
 * Slot +0x00 is modelled as the destructor, which is the usual MSVC arrangement
 * (inference: this unit gives no evidence about it).
 */
class CFun00cbf280Owner
{
  public:
    virtual ~CFun00cbf280Owner();

    /* +0x04, +0x08: unknown, unreferenced by this unit. */
    virtual void* VtblSlot04();
    virtual void VtblSlot08();

    /* +0x0C: takes the argument block, returns a writable destination. */
    virtual void* Reserve(SFun00cbf280Args* args);

    /* +0x10: takes the source and the originally requested size; the unit
     * discards whatever it returns. */
    virtual void Commit(void* src, int size);

    /* The unit itself. Non-virtual: it is entered directly, not through a slot. */
    void* hkMemoryAllocator_bufRealloc(void* src, int size, SFun00cbf280Args* args);
};

/*
 * Body, in the order the effects are observable:
 *
 *   1. Reserve(args) is called first and its pointer result is kept alive for
 *      the whole function; it is what gets returned.
 *   2. args->limit is re-read *after* that call, so the unit deliberately
 *      honours a limit the callee may have adjusted. It is then clamped
 *      against the caller's `size` with a signed comparison, i.e. the smaller
 *      of the two wins.
 *   3. FUN_00d2caa0 receives (destination from step 1, src, clamped count) in
 *      that positional order.
 *   4. Commit(src, size) is called with the *unclamped* size, and its result is
 *      dropped.
 *   5. The destination from step 1 is returned.
 *
 * Read as a whole this looks like: ask the owner for somewhere to put data,
 * copy at most min(size, args->limit) bytes of `src` into it, tell the owner
 * how much was asked for, and hand the buffer back. The "looks like" is
 * deliberate — the semantics of Reserve, Commit and the helper are not
 * established by this unit.
 */
// @fnv 0x00cbf280
// src: HAVOK_LIB 0x00cbf280
void* CFun00cbf280Owner::hkMemoryAllocator_bufRealloc(void* src, int size, SFun00cbf280Args* args)
{
    void* dest = this->Reserve(args);

    int count = args->limit;
    if (size < count)
        count = size;

    hkMemUtil_memCpy_00d2caa0(dest, src, (unsigned int)count);

    this->Commit(src, size);

    return dest;
}

extern int DAT_010c3b30;

struct FUN_00cbf1a0_cls
{
    int m_vptr00;

    void UpdateFields_00cbf1a0();
};

// @fnv 0x00cbf1a0
// src: GUESS 0x00cbf1a0 (confidence: low)
void FUN_00cbf1a0_cls::UpdateFields_00cbf1a0()
{
    m_vptr00 = (int)&DAT_010c3b30;
}

struct BhkTarget
{
    virtual void* v0();
    virtual void* v1(void*);
    virtual void* v2();
    virtual void* v3();
    void* CallVirtual1WithDereferencedArg(void** p);
};

// @fnv 0x00cbf1b0
void* BhkTarget::CallVirtual1WithDereferencedArg(void** p)
{
    return this->v1(*p);
}

class FUN_00cbf1e0_cls
{
  public:
    virtual void f0();
    virtual void* f1(void* a);

    void hkMemoryAllocator_blockAllocBatch(void** dest, int count, void* arg);
};

// Calls f1(arg) count times and stores each returned pointer into dest[i].
// @fnv 0x00cbf1e0
// src: HAVOK_LIB 0x00cbf1e0
void FUN_00cbf1e0_cls::hkMemoryAllocator_blockAllocBatch(void** dest, int count, void* arg)
{
    for (int i = 0; i < count; ++i)
    {
        dest[i] = this->f1(arg);
    }
}

struct Visitor
{
    virtual void slot00();
    virtual void slot04();
    virtual void Visit(void* item, int arg);
    void VisitAll(void** items, int count, int arg);
};

// Iterates over the first count entries of items and calls Visit on each non-null item, passing arg through.
// @fnv 0x00cbf220
void Visitor::VisitAll(void** items, int count, int arg)
{
    int i = 0;
    if (0 < count)
    {
        do
        {
            void* item = items[i];
            if (item != 0)
            {
                Visit(item, arg);
            }
            i = i + 1;
        } while (i < count);
    }
}

struct CBF260
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void __fastcall f9(void* arg);
    void __fastcall hkMemoryAllocator_canAllocSingleBlock(void* arg);
};
// @fnv 0x00cbf260
// src: HAVOK_SRC 0x00cbf260
void __fastcall CBF260::hkMemoryAllocator_canAllocSingleBlock(void* arg)
{
    f9(arg);
}

// @fnv 0x00cbf270
// src: COMMUNITY 0x00cbf270
bool __stdcall hkMemoryAllocator_canAllocTotal(int arg0)
{
    return true;
}
