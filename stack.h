//
//  stack.h
//  PharmApp
//
//  Created by Salim Braksa on 1/5/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

typedef struct _stack{
    int counter;
    void** container;
} Stack;

/***
 * newStack - allocates space and sets up stack
 * @size: the desired default container size (5 minimum)
 *
 **/
Stack* new_stack();

/***
 * freeStack - frees container and stack memory
 * @stack: target stack
 *
 **/
void free_stack(Stack* stack);

/***
 * getSize - returns current stack counter position
 * @stack: target stack
 *
 **/
int get_size(Stack* stack);

/***
 * getMax - returns the current max stack size
 * @stack: target stack
 *
 **/
int get_max(Stack* stack);

/***
 * isEmpty - returns 1 if stack is empty, 0 if not
 * @stack: target stack
 *
 **/
int is_empty(Stack* stack);

/***
 * resizeContainer - expands container to 2*max
 * @stack: target stack
 *
 **/
void resize_container(Stack* stack);

/***
 * search - searches for value in stack and returns index of the found value
 *          or returns -1 if not found.
 * @value: target value
 * @stack: target stack
 *
 **/
int search(void* value, Stack* stack);

/***
 * peek - returns top of the stack without removing it
 * @stack: target stack
 *
 **/
void* peek(Stack* stack);

/***
 * push - pushes an item onto a stack
 * @item: target item
 * @stack: target stack
 *
 **/
void push(void* item, Stack* stack);

/***
 * pop - pops an item off the top of the target stack
 * @stack: target stack
 *
 **/
void* pop(Stack* stack);

#endif /* stack_h */
