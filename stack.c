//
//  stack.c
//  PharmApp
//
//  Created by Salim Braksa on 1/5/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#include "stack.h"

Stack* new_stack(){
    
    Stack* stack = malloc(sizeof(Stack));
    stack->container = malloc(sizeof(void**));
    stack->counter = 0;
    
    return stack;
}

void free_Stack(Stack* stack){
    free(stack->container);
    free(stack);
}

int is_empty(Stack* stack){
    if(stack->counter == 0)
        return 1;
    return 0;
}

void resize_container(Stack* stack){
    stack -> container = realloc(stack -> container, sizeof(stack -> container) * stack -> counter);
}

void push(void* item, Stack* stack){
    
    // Increment counter
    stack -> counter++;
    resize_container(stack);
    stack->container[stack->counter-1] = item;
    
}

void* pop(Stack* stack){
    if (stack->counter > 0){
        stack->counter--;
        void* item = stack->container[stack->counter];
        resize_container(stack);
        return item;
    }
    fprintf(stderr, "stack counter is 0... can't pop an empty stack.");
    return NULL;
}