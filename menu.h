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

/// Le modèle Menu
typedef struct {
    
    char* title;
    int number_of_rows;
    char** rows;
    
} Menu;

/// Permet de créer un nouveau menu
Menu* create_menu(char* title, int number_of_rows, char** rows);

/// Permet d'afficher un menu
void show_menu(Menu* menu);

#endif /* menu_h */
