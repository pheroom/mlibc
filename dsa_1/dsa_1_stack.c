#include <stdlib.h>
#include <stdio.h>
#include "dsa_1_stack.h"

Stack *ST_create(int size){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    int *list = (int *)calloc(size, sizeof(int));
    if(stack == NULL || list == NULL){
        printf("Memory not allocated.\n");
        exit(1);
    }
    stack->size = size;
    stack->list = list;
    stack->top = -1;
    return stack;
}

int isFull(Stack *stack){
    return stack->top + 1 == stack->size;
}

int isEmpty(Stack *stack){
    return stack->top + 1 == 0;
}

void ST_push(Stack *stack, int value){
    if(isFull(stack)){
        printf("Stack is full.\n");
        exit(1);
    }
    stack->list[++stack->top] = value;
}

int ST_peek(Stack *stack){
    return stack->list[stack->top];
}

int ST_pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty.\n");
        exit(1);
    }
    return stack->list[stack->top--];
}

void ST_free(Stack *stack){
    free(stack->list);
    free(stack);
}