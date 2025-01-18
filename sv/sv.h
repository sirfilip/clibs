#ifndef _SV_H
#define _SV_H

#include <stdio.h>

typedef struct {
    const char *data;
    size_t len;
} SV;

SV sv_from_cstring(const char *cstring, size_t len) {
    return (SV) {
        .data = cstring,
        .len = len
    };
}

int sv_has_prefix(SV sv, SV prefix) {
    if (sv.len < prefix.len) {
        return 0;
    }
    for (size_t i=0; i < prefix.len; i++) {
        if (sv.data[i] != prefix.data[i]) {
            return 0;
        }
    }
    return 1;
}

int sv_has_suffix(SV sv, SV suffix) {
    if (sv.len < suffix.len) {
        return 0;
    }
    for (size_t i=0; i < suffix.len; i++) {
        if (sv.data[sv.len - suffix.len + i] != suffix.data[i]) {
            return 0;
        }
    }
    return 1;
}

void sv_trim_prefix(SV *sv, SV prefix) {
    if (sv_has_prefix(*sv, prefix) == 0) {
        return;
    }
    sv->data += prefix.len;
    sv->len -= prefix.len;
}

void sv_trim_suffix(SV *sv, SV suffix) {
    if (sv_has_suffix(*sv, suffix) == 0) {
        return;
    }
    sv->len -= suffix.len;
}

void sv_trim(SV *sv, SV chunk) {
    sv_trim_prefix(sv, chunk);
    sv_trim_suffix(sv, chunk);
}

void sv_strip_prefix(SV *sv, char prefix) {
    size_t count = 0;
    for (size_t i=0; i< sv->len; i++) {
        if (sv->data[i] != prefix) {
            break;
        }
        count++;
    }
    sv->data += count;
    sv->len -= count;
}

void sv_strip_suffix(SV *sv, char suffix) {
    size_t count = 0;
    for (size_t i=sv->len - 1; i >= 0; i++) {
        if (sv->data[i] != suffix) {
            break;
        }
        count++;
    }
    sv->len -= count;
}

int sv_equal(SV sv, SV other) {
    if (sv.len != other.len) {
        return 0;
    }
    for (size_t i=0; i<sv.len; i++) {
        if (sv.data[i] != other.data[i]) {
            return 0;
        }
    }
    return 1;
}

void sv_print(SV sv) {
    printf("%.*s", (int) sv.len, sv.data);    
}

#endif // _SV_H
