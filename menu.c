//
//  menu.c
//  PharmApp
//
//  Created by Salim Braksa on 1/4/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#include "menu.h"

Menu* create_menu(char* title, int number_of_rows, char** rows) {
    
    // Alloc Menu
    Menu* menu = malloc(sizeof(Menu));
    
    // Malloc
    menu -> title = (char*)malloc(sizeof(char) * strlen(title));
    
    // Set properties
    strcpy(menu -> title, title);
    menu -> number_of_rows = number_of_rows;
    menu -> rows = rows;
    
    // Return
    return menu;
    
}

void show_menu(Menu* menu) {
    
    for (int i = 0; i < menu -> number_of_rows; i++) {
        printf("%d. %s\n", i+1, menu -> rows[i]);
    }
    
}