#include <stdio.h>
#include "dict.h"



int main(void) {
    Dict *dict = dict_new(100); 
    dict_insert(dict, "key1", "val1");
    dict_insert(dict, "key2", "val2");
    printf("value: %s\n", dict_get(dict, "key1"));
    printf("value: %s\n", dict_get(dict, "key2"));
    printf("value: %s\n", dict_get(dict, "key3"));

    printf("deleting key1: %d\n", dict_delete(dict, "key1"));
    printf("value: %s\n", dict_get(dict, "key1"));

    dict_insert(dict, "key3", "val3");
    printf("value: %s\n", dict_get(dict, "key3"));
    return 0;
}
