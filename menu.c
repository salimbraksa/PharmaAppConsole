//
//  menu.c
//  PharmApp
//
//  Created by Salim Braksa on 1/4/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#include "menu.h"

Menu* create_menu(char* title, int number_of_rows, char** rows, Handlers* selectors) {
    
    // Alloc Menu
    Menu* menu = malloc(sizeof(Menu));
    
    // Malloc
    menu -> title = (char*)malloc(sizeof(char) * strlen(title));
    
    // Set properties
    strcpy(menu -> title, title);
    menu -> number_of_rows = number_of_rows;
    menu -> rows = rows;
    menu -> selectors = selectors;
    
    // Return
    return menu;
    
}

void show_menu(Menu* menu) {
    
    for (int i = 0; i < menu -> number_of_rows; i++) {
        printf("%d. %s\n", i+1, menu -> rows[i]);
    }
    printf("\n");
    
}

void set_rows_for_menu(Menu* menu, int num_args, ...) {
    
    va_list valist;
    
    /* initialize valist for num number of arguments */
    va_start(valist, num_args);
    
    // Set rows
    char** rows = malloc(sizeof(char*) * num_args);
    for (int i = 0; i < num_args; i++) {
        sb_strcpy(&rows[i], va_arg(valist, char*));
    }
    
    // Set rows
    menu -> rows = rows;
    
    /* clean memory reserved for valist */
    va_end(valist);
    
}

void set_selectors_for_menu(Menu* menu, int num_args, ...) {
    
    va_list valist;
    
    /* initialize valist for num number of arguments */
    va_start(valist, num_args);
    
    // Set rows
    Handlers* selectors = new_handlers();
    for (int i = 0; i < num_args; i++) {
        append_handler(selectors, va_arg(valist, void (*)(void)));
    }
    
    // Set rows
    menu -> selectors = selectors;
    
    /* clean memory reserved for valist */
    va_end(valist);
    
}

void free_menu(Menu* menu) {
    
    // Free title
    free(menu -> title);
    
    // Free rows & selectors
    for (int i = 0; i < menu -> number_of_rows; i++) {
        free(menu -> rows[i]);
    }
    free(menu -> rows);
    
    // Free selectors
    free_handlers(menu -> selectors);
    
    // Free the entire menu
    free(menu);
    
}