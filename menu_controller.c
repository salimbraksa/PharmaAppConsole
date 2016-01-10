//
//  menu_controller.c
//  PharmApp
//
//  Created by Salim Braksa on 1/5/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#include "menu_controller.h"

Stack* stack_menus;

void print_path(Stack* menus) {
    
    printf("- ");
    for (int i = 0; i < menus -> counter; i++) {
        Menu* menu = (Menu*)menus -> container[i];
        printf( ( i != menus -> counter - 1 ) ? "%s > " : "%s", menu -> title);
    }
    printf("\n\n");
    
}

void print_menu(int clear) {
    
    // Clear old menu
    if (clear == 1) system("clear");
    
    // Afficher seul le menu qui existe au sommet de la pile
    Menu* head_menu = (Menu*)stack_menus -> container[stack_menus -> counter - 1];
    
    // Afficher path
    print_path(stack_menus);
    
    // Afficher le menu
    show_menu(head_menu);
    
    // Scan
    menu_scan(head_menu);
    
}

void menu_scan(Menu* menu) {
    
    int choice;
    printf("Choisir un nombre entre 1 et %d\n\n", menu -> number_of_rows);
    
    do {
        get_integer("\tVotre choix: ", &choice);
    } while (!(choice > 0 && choice <= menu -> number_of_rows));
    
    execute_handler(menu -> selectors, choice - 1);
    
}