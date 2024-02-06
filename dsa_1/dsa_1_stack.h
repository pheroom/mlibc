#ifndef DSA_1_STACK_H
#define DSA_1_STACK_H

typedef struct {
    int size;
    int top;
    int *list;
} Stack;

Stack *ST_create(int size);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void ST_push(Stack *stack, int value);
int ST_peek(Stack *stack);
int ST_pop(Stack *stack);
void ST_free(Stack *stack);

#endif //DSA_1_STACK_H
