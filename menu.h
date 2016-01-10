//
//  menu.h
//  PharmApp
//
//  Created by Salim Braksa on 1/4/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#ifndef menu_h
#define menu_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "handlers.h"
#include "helpers.h"

/// Le modèle Menu
typedef struct {
    
    char* title;
    int number_of_rows;
    char** rows;
    Handlers* selectors;
    
} Menu;

/// Permet de créer un nouveau menu
Menu* create_menu(char* title,
                  int number_of_rows,
                  char** rows,
                  Handlers* selectors);

/// Permet d'afficher un menu
void show_menu(Menu* menu);

/// Permet de libérer un menu
void free_menu(Menu* menu);

void set_rows_for_menu(Menu* menu, int num_args, ...);
void set_selectors_for_menu(Menu* menu, int num_args, ...);

#endif /* menu_h */
