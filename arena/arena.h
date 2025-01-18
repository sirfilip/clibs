#ifndef _ARENA_H
#define _ARENA_H

#include <stdlib.h>
#include <assert.h>

typedef struct {
    size_t size;
    size_t capacity;
    void *data;
} Arena;

Arena *arena_new(size_t capacity) {
    Arena *arena = malloc(sizeof(Arena));
    arena->capacity = capacity;
    arena->size = 0;
    arena->data = malloc(sizeof(char) * capacity);
    return arena;
}

void arena_free(Arena *arena) {
    free(arena->data);
    free(arena);
}

void arena_reset(Arena *arena) {
    arena->size = 0;
}

void *arena_alloc(Arena *arena, size_t size) {
    assert(arena->capacity > arena->size + size && "Arena overflow"); 
    void *ptr = &arena->data[arena->size];
    arena->size += size;
    return ptr;
}

#endif // _ARENA_H
