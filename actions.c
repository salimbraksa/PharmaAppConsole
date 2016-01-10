//
//  actions.c
//  PharmApp
//
//  Created by Salim Braksa on 1/7/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#include "actions.h"

void show_all_clients(void) {
    
    // Clear
    system("clear");
    
    // Get clients
    LinkedList* clients = get_clients(CLIENTS_FILENAME);
    
    if (!clients) {
        printf("Il n'existe aucun client\n");
    }
    
    // Afficher menu
    // Create the menu
    Menu* menu = create_menu("Affichage des clients", 1, NULL, NULL);
    
    // Set rows
    set_rows_for_menu(menu, menu -> number_of_rows,
                      "Retour");
    
    // Set selectors
    set_selectors_for_menu(menu, menu -> number_of_rows,
                           back);
    
    // Ajouter le menu
    push(menu, stack_menus);
    
    // Afficher le menu
    print_menu(0);
    
}

/**
 *** RETOUR & EXIT
 **/

void exit_app(void) {
    exit(0);
}

void back(void) {
    
    // Pop top menu
    Menu* menu = pop(stack_menus);
    
    // Free menu
    free_menu(menu);
    
    // Show top menu
    print_menu(1);
    
}