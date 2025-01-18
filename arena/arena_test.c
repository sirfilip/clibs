#include <stdio.h>
#include "arena.h"


int main(void) {
  Arena *arena = arena_new(1024);
  char *str = (char *)arena_alloc(arena, 6);
  str[0] = 'h';
  str[1] = 'e';
  str[2] = 'l';
  str[3] = 'l';
  str[4] = 'o';
  str[5] = '\0';
  printf("arena says: %s\n", str);
  arena_free(arena);
  return 1;
}
