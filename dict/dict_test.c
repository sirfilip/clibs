#include <assert.h>
#include "dict.h"



int main(void) {
    Dict *dict = dict_new(100); 
    dict_insert(dict, "key1", "val1");
    dict_insert(dict, "key2", "val2");

    assert(dict_delete(dict, "key1") == 1 && "deletion is successful");
    assert(dict_get(dict, "key1") == NULL && "key1 value is NULL");

    dict_insert(dict, "key3", "val3");
    assert(strcmp(dict_get(dict, "key3"), "val3") == 0 && "key3 value is val3");

    dict_free(dict);
    return 0;
}
