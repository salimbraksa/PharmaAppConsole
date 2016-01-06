//
//  main.c
//  PharmApp
//
//  Created by Salim Braksa on 1/4/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#include <stdio.h>
#include "menu_controller.h"
#include "handlers.h"

typedef void (*HandlersArray)(void);

void f1(void);

int main(int argc, const char * argv[]) {
    
//    char** rows = malloc(sizeof(char*) * 4);
//    rows[0] = "Hello, world";
//    rows[1] = "Sello, world";
//    rows[2] = "Xello, world";
//    rows[3] = "Tello, world";
//    Menu* main_menu = create_menu("Main menu", 4, rows);
//    
//    char** rows2 = malloc(sizeof(char*) * 0);
//    Menu* second_menu = create_menu("Second menu", 0, rows2);
//    
//    Stack* stack = new_stack();
//    push(main_menu, stack);
//    push(second_menu, stack);
//    
//    print_path(stack);
    
    Handlers* handlers = new_handlers();
    append_handler(handlers, f1);
    execute_handler(handlers, 0);
    free(handlers);
    
    return 0;
}

void f1(void) {
    printf("Voidability\n");
}
