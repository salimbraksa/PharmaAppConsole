//
//  menu_controller.c
//  PharmApp
//
//  Created by Salim Braksa on 1/5/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#include "menu_controller.h"

void print_path(Stack* menus) {
    
    for (int i = 0; i < menus -> counter; i++) {
        Menu* menu = (Menu*)menus -> container[i];
        printf( ( i != menus -> counter - 1 ) ? "%s > " : "%s", menu -> title);
    }
    printf("\n");
    
}