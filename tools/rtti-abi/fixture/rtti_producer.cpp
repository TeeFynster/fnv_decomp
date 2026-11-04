// Synthetic RTTI ABI fixture: producer translation unit.
//
// Defines every constructor, destructor and virtual function declared in
// rtti_abi_fixture.h, and creates and destroys the fixture objects. It
// performs no dynamic_cast. Base-class views are filled by implicit
// derived-to-base conversion, which C++ resolves statically.
//
// Invented code only. Not compiled or run in this delivery (NOT_RUN).

#include "rtti_abi_fixture.h"

#include <new>

namespace rtti_abi {

// --------------------------------------------------------------- single

SiRoot::SiRoot() : root_value(1) {}
SiRoot::~SiRoot() {}
int SiRoot::depth() const { return 1; }

SiMid::SiMid() : mid_value(2) {}
SiMid::~SiMid() {}
int SiMid::depth() const { return 2; }

SiLeaf::SiLeaf() : leaf_value(3) {}
SiLeaf::~SiLeaf() {}
int SiLeaf::depth() const { return 3; }

// --------------------------------------------------------------- multiple

MiLeft::MiLeft() : left_data(11) {}
MiLeft::~MiLeft() {}
int MiLeft::left_value() const { return left_data; }

MiRight::MiRight() : right_data(12) {}
MiRight::~MiRight() {}
int MiRight::right_value() const { return right_data; }

MiJoin::MiJoin() : join_data(13) {}
MiJoin::~MiJoin() {}
int MiJoin::left_value() const { return left_data + join_data; }
int MiJoin::right_value() const { return right_data + join_data; }

MiSealed::MiSealed() : sealed_data(14) {}
MiSealed::~MiSealed() {}

// --------------------------------------------------------------- virtual

ViBase::ViBase() : base_data(21) {}
ViBase::~ViBase() {}
int ViBase::base_value() const { return base_data; }

ViLeft::ViLeft() : left_data(22) {}
ViLeft::~ViLeft() {}

ViRight::ViRight() : right_data(23) {}
ViRight::~ViRight() {}

ViJoin::ViJoin() : join_data(24) {}
ViJoin::~ViJoin() {}

// --------------------------------------------------------------- ambiguity

AmBase::AmBase() : base_data(31) {}
AmBase::~AmBase() {}

AmLeft::AmLeft() : left_data(32) {}
AmLeft::~AmLeft() {}

AmRight::AmRight() : right_data(33) {}
AmRight::~AmRight() {}

AmTag::AmTag() : tag_data(34) {}
AmTag::~AmTag() {}

AmJoin::AmJoin() : join_data(35) {}
AmJoin::~AmJoin() {}

// --------------------------------------------------------------- lifetime

namespace {

void clear_views(FixtureObjects& o)
{
    o.si_leaf.complete = 0;
    o.si_leaf.as_mid = 0;
    o.si_leaf.as_root = 0;

    o.si_mid.complete = 0;
    o.si_mid.as_root = 0;

    o.mi_join.complete = 0;
    o.mi_join.as_left = 0;
    o.mi_join.as_right = 0;

    o.mi_left.complete = 0;

    o.mi_sealed.complete = 0;
    o.mi_sealed.as_left = 0;

    o.vi_join.complete = 0;
    o.vi_join.as_left = 0;
    o.vi_join.as_right = 0;
    o.vi_join.as_base_via_left = 0;
    o.vi_join.as_base_via_right = 0;

    o.vi_left.complete = 0;
    o.vi_left.as_base = 0;

    o.am_join.complete = 0;
    o.am_join.as_left = 0;
    o.am_join.as_right = 0;
    o.am_join.as_tag = 0;
    o.am_join.as_left_base = 0;
    o.am_join.as_right_base = 0;
}

}  // namespace

bool create_fixture_objects(FixtureObjects& out)
{
    clear_views(out);
    try {
        // Each complete pointer is stored before its views, so a later
        // std::bad_alloc leaves every created object reachable for cleanup.
        out.si_leaf.complete = new SiLeaf();
        out.si_leaf.as_mid = out.si_leaf.complete;
        out.si_leaf.as_root = out.si_leaf.complete;

        out.si_mid.complete = new SiMid();
        out.si_mid.as_root = out.si_mid.complete;

        out.mi_join.complete = new MiJoin();
        out.mi_join.as_left = out.mi_join.complete;
        out.mi_join.as_right = out.mi_join.complete;

        out.mi_left.complete = new MiLeft();

        out.mi_sealed.complete = new MiSealed();
        out.mi_sealed.as_left = out.mi_sealed.complete;

        out.vi_join.complete = new ViJoin();
        out.vi_join.as_left = out.vi_join.complete;
        out.vi_join.as_right = out.vi_join.complete;
        out.vi_join.as_base_via_left = static_cast<ViLeft*>(out.vi_join.complete);
        out.vi_join.as_base_via_right = static_cast<ViRight*>(out.vi_join.complete);

        out.vi_left.complete = new ViLeft();
        out.vi_left.as_base = out.vi_left.complete;

        out.am_join.complete = new AmJoin();
        out.am_join.as_left = out.am_join.complete;
        out.am_join.as_right = out.am_join.complete;
        out.am_join.as_tag = out.am_join.complete;
        // AmBase is ambiguous in AmJoin, so each AmBase view names its path.
        out.am_join.as_left_base = static_cast<AmLeft*>(out.am_join.complete);
        out.am_join.as_right_base = static_cast<AmRight*>(out.am_join.complete);
    } catch (const std::bad_alloc&) {
        destroy_fixture_objects(out);
        return false;
    }
    return true;
}

void destroy_fixture_objects(FixtureObjects& objects)
{
    // Delete through complete-object pointers only; delete of a null pointer
    // does nothing. Reverse creation order.
    delete objects.am_join.complete;
    delete objects.vi_left.complete;
    delete objects.vi_join.complete;
    delete objects.mi_sealed.complete;
    delete objects.mi_left.complete;
    delete objects.mi_join.complete;
    delete objects.si_mid.complete;
    delete objects.si_leaf.complete;
    clear_views(objects);
}

}  // namespace rtti_abi
