#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include "list.h"

typedef List Stack;

static inline Stack *stack_create() {
    return list_create();
}

static inline void stack_push(Stack *stack, void *data) {
    list_pushBack(stack, data);
}

static inline void *stack_pop(Stack *stack) {
    return list_popBack(stack);
}

static inline void *stack_top(Stack *stack) {
    if (list_size(stack) == 0) return NULL;
    void *elem = list_first(stack);
    for (int i = 1; i < list_size(stack); ++i)
        elem = list_next(stack);
    return elem;
}

static inline int stack_size(Stack *stack) {
    return list_size(stack);
}

static inline void stack_clean(Stack *stack) {
    list_clean(stack);
}

#endif
