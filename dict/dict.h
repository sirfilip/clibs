#ifndef _DICT_H
#define _DICT_H

#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct {
    size_t capacity;
    size_t size;
    size_t len;
    char **keys;
    char **values;
} Dict;



Dict *dict_new(size_t capacity) {
    Dict *dict = (Dict *)malloc(sizeof(Dict));
    dict->keys = (char **)malloc(sizeof(char *) * capacity);
    if (dict->keys == NULL) {
        perror("malloc keys");
        exit(1);
    }
    dict->values = (char **)malloc(sizeof(char *) * capacity);
    if (dict->values == NULL) {
        perror("malloc values");
        exit(1);
    }
    dict->capacity = capacity;
    dict->size = 0;
    dict->len = 0;
    return dict;
}

// TODO: search for space gaps
// TODO check the mallocs for errors
int dict_insert(Dict *dict, const char *key, const char *value) {
    assert(dict->capacity > dict->size + 1 && "dict overflow");

    for (size_t i=0; i < dict->capacity; i++) {
        if (dict->keys[i] != NULL) {
            continue;
        }
        size_t key_len = strlen(key);
        dict->keys[i] = (char *)malloc(sizeof(char) * key_len + 1);
        memcpy(dict->keys[i], key, key_len);
        dict->keys[i][key_len] = '\0';

        size_t value_len  = strlen(value);
        dict->values[i] = (char *)malloc(sizeof(char) * value_len + 1);
        memcpy(dict->values[i], value, value_len);
        dict->values[i][value_len] = '\0';
        dict->len++;
        return 0;
    }

    size_t key_len = strlen(key);
    dict->keys[dict->size] = (char *)malloc(sizeof(char) * key_len + 1);
    memcpy(dict->keys[dict->size], key, key_len);
    dict->keys[dict->size][key_len] = '\0';

    size_t value_len  = strlen(value);
    dict->values[dict->size] = (char *)malloc(sizeof(char) * value_len + 1);
    memcpy(dict->values[dict->size], value, value_len);
    dict->values[dict->size][value_len] = '\0';
    dict->size++;
    dict->len++;
    return 0;
}

char  *dict_get(Dict *dict, const char *key) {
    for (size_t i=0; i < dict->size; i++) {
        if (dict->keys[i] == NULL) {
            continue;
        }

        if (strcmp(dict->keys[i], key) == 0) {
            return dict->values[i];
        }
    }
    return NULL;
}

int dict_delete(Dict *dict, const char *key) {
    for (size_t i=0; i < dict->size; i++) {
        if (dict->keys[i] == NULL) {
            continue;
        }

        if (strcmp(dict->keys[i], key) == 0) {
            free(dict->keys[i]);
            dict->keys[i] = NULL;
            free(dict->values[i]);
            dict->values[i] = NULL;
            dict->len--;
            return 1;
        }
    }

    return 0;
}


#endif // _DICT_H
