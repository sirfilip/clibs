#include <string.h>
#include <stdio.h>

#include "sv.h"


int main(void) {
    SV sv = sv_from_cstring("testing", strlen("testing"));
    SV other = sv_from_cstring("test", strlen("test"));

    printf("has prefix: %d\n", sv_has_prefix(sv, other));
    printf("has suffix: %d\n", sv_has_suffix(sv, other));
    sv_trim_prefix(&sv, other);
    sv_print(sv);
    // check why strip preffix is not working
    // as expected
    sv_strip_prefix(&sv, 'i');
    sv_print(sv);
    return 1;
}
