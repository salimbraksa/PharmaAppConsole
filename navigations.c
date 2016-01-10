//
//  navigations.c
//  PharmApp
//
//  Created by Salim Braksa on 1/7/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#include "navigations.h"

/**
 *** MENU PRINCIPAL
 **/

void show_main_menu(void) {
    
    // Create the menu
    Menu* menu = create_menu("Menu principal", 6, NULL, NULL);
    
    // Set rows
    set_rows_for_menu(menu, menu -> number_of_rows,
                      "Gérer les clients",
                      "Gérer les fournisseurs",
                      "Gérer les médicaments",
                      "Gérer les commandes",
                      "Consulter le rapport journalier",
                      "Quitter");
    
    // Set selectors
    set_selectors_for_menu(menu, menu -> number_of_rows,
                           show_clients_manager_menu,
                           show_fournisseurs_manager_menu,
                           show_medicaments_manager_menu,
                           show_commandes_manager_menu,
                           show_rapport_journalier_menu,
                           exit_app);
    
    // Ajouter le menu
    push(menu, stack_menus);
    
    // Afficher le menu
    print_menu(1);
    
}

/**
 *** MENU DE GESTION DE CLIENTS
 **/

void show_clients_manager_menu(void) {
    
    // Create the menu
    Menu* menu = create_menu("Clients", 5, NULL, NULL);
    
    // Set rows
    set_rows_for_menu(menu, menu -> number_of_rows,
                      "Afficher tous les clients",
                      "Afficher un client dont le nom à été saisi",
                      "Ajouter un nouveau client",
                      "Modifier un client",
                      "Retour");
    
    // Set selectors
    set_selectors_for_menu(menu, menu -> number_of_rows,
                           show_all_clients,
                           back);
    
    // Ajouter le menu
    push(menu, stack_menus);
    
    // Afficher le menu
    print_menu(1);
    
}

/**
 *** MENU DE FOURNISSEURS
 **/

void show_fournisseurs_manager_menu(void) {
    
    // Create the menu
    Menu* menu = create_menu("Fournisseurs", 6, NULL, NULL);
    
    // Set rows
    set_rows_for_menu(menu, menu -> number_of_rows,
                      "Ajouter un nouveau fournisseur",
                      "Modifier un fournisseur",
                      "Supprimer un fournisseur",
                      "Afficher la liste de tous les fournisseurs",
                      "Afficher les fournisseurs d'un médicament",
                      "Retour");
    
    // Set selectors
    set_selectors_for_menu(menu, menu -> number_of_rows,
                           back);
    
    // Ajouter le menu
    push(menu, stack_menus);
    
    // Afficher le menu
    print_menu(1);
    
}

/**
 *** MENU DE MEDICAMENTS
 **/

void show_medicaments_manager_menu(void) {
    
    // Create the menu
    Menu* menu = create_menu("Médicaments", 4, NULL, NULL);
    
    // Set rows
    set_rows_for_menu(menu, menu -> number_of_rows,
                      "Ajouter un médicament dans une commande",
                      "Chercher un médicament",
                      "Changer le fournisseur",
                      "Retour");
    
    // Set selectors
    set_selectors_for_menu(menu, menu -> number_of_rows,
                           back);
    
    // Ajouter le menu
    push(menu, stack_menus);
    
    // Afficher le menu
    print_menu(1);
    
}

/**
 *** MENU DE COMMANDES
 **/

void show_commandes_manager_menu(void) {
    
    // Create the menu
    Menu* menu = create_menu("Commandes", 2, NULL, NULL);
    
    // Set rows
    set_rows_for_menu(menu, menu -> number_of_rows,
                      "Lister une commande d'une date",
                      "Retour");
    
    // Set selectors
    set_selectors_for_menu(menu, menu -> number_of_rows,
                           back);
    
    // Ajouter le menu
    push(menu, stack_menus);
    
    // Afficher le menu
    print_menu(1);
    
}

/**
 *** MENU RAPPORT JOURNALIER
 **/

void show_rapport_journalier_menu(void) {
    
    // Create the menu
    Menu* menu = create_menu("Rapport Journalier", 3, NULL, NULL);
    
    // Set rows
    set_rows_for_menu(menu, menu -> number_of_rows,
                      "D'une journée",
                      "D'une année",
                      "Retour");
    
    // Set selectors
    set_selectors_for_menu(menu, menu -> number_of_rows,
                           back);
    
    // Ajouter le menu
    push(menu, stack_menus);
    
    // Afficher le menu
    print_menu(1);
    
}