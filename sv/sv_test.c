#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "sv.h"


int main(void) {
    SV sv = sv_from_cstring("testing");
    SV other = sv_from_cstring("test");

    assert(sv_has_prefix(sv, other) && "has prefix");
    assert(!sv_has_suffix(sv, other) && "does not have suffix");
    sv_trim_prefix(&sv, other);
    assert(sv_equal(sv, sv_from_cstring("ing")) && "equals to ing");
    sv_strip_prefix(&sv, 'i');
    assert(sv_equal(sv, sv_from_cstring("ng")) && "removed i from ing");

    return 0;
}
