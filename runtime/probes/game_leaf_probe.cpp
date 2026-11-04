// Original fixture for one reviewed source-built leaf; no game assets or layout claim.
#include <stddef.h>
#include <stdio.h>

struct GameLeafFixture {
    unsigned int fixture_words[12];
    int value;
    int ReadValue(); // Definition supplied by the reviewed, renamed retained object.
};
typedef char FixtureIntIsFourBytes[sizeof(int) == 4 ? 1 : -1];
typedef char FixtureValueAtReviewedOffset[offsetof(GameLeafFixture, value) == 0x30 ? 1 : -1];

int main() {
    GameLeafFixture object;
    for (unsigned int i = 0; i < 12; ++i)
        object.fixture_words[i] = 0x13570000u + i;
    const int cases[] = {(-2147483647 - 1), -12345, -1, 0, 1, 12345, 2147483647};
    unsigned int checked = 0;
    int ok = 1;
    for (unsigned int repeat = 0; repeat < 1024; ++repeat) {
        for (unsigned int n = 0; n < sizeof(cases) / sizeof(cases[0]); ++n) {
            object.value = cases[n];
            if (object.ReadValue() != cases[n])
                ok = 0;
            ++checked;
        }
    }
    printf("{\"schema\":1,\"cases\":7,\"calls\":%u,\"checks_ok\":%d}\n", checked, ok);
    return ok ? 0 : 1;
}
