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
                           clients_from_name,
                           add_client,
                           edit_client,
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
    Menu* menu = create_menu("Fournisseurs", 5, NULL, NULL);
    
    // Set rows
    set_rows_for_menu(menu, menu -> number_of_rows,
                      "Ajouter un nouveau fournisseur",
                      "Modifier un fournisseur",
                      "Supprimer un fournisseur",
                      "Afficher la liste de tous les fournisseurs",
                      "Retour");
    
    // Set selectors
    set_selectors_for_menu(menu, menu -> number_of_rows,
                           add_fournisseur,
                           modify_fournisseur,
                           delete_fournisseur,
                           show_all_fournisseurs,
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
    Menu* menu = create_menu("Médicaments", 7, NULL, NULL);
    
    // Set rows
    set_rows_for_menu(menu, menu -> number_of_rows,
                      "Ajouter un médicament",
                      "Ajouter un médicament dans une commande",
                      "Afficher les fournisseurs d'un médicament",
                      "Vendre des médicaments",
                      "Chercher un médicament",
                      "Changer le fournisseur",
                      "Retour");
    
    // Set selectors
    set_selectors_for_menu(menu, menu -> number_of_rows,
                           add_medicament,
                           add_medicament_to_commande,
                           show_fournisseur_medicaments,
                           sell_medicaments,
                           medicament_from_id,
                           change_default_fournisseur,
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
    Menu* menu = create_menu("Commandes", 3, NULL, NULL);
    
    // Set rows
    set_rows_for_menu(menu, menu -> number_of_rows,
                      "Lister une commande d'une journée",
                      "Lister les commandes d'une année",
                      "Retour");
    
    // Set selectors
    set_selectors_for_menu(menu, menu -> number_of_rows,
                           commande_from_day,
                           commandes_from_year,
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
                      "Lister une vente d'une journée",
                      "Lister les ventes d'une année",
                      "Retour");
    
    // Set selectors
    set_selectors_for_menu(menu, menu -> number_of_rows,
                           vente_from_day,
                           ventes_from_year,
                           back);
    
    // Ajouter le menu
    push(menu, stack_menus);
    
    // Afficher le menu
    print_menu(1);
    
}