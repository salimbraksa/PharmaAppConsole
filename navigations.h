//
//  navigations.h
//  PharmApp
//
//  Created by Salim Braksa on 1/7/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#ifndef navigations_h
#define navigations_h

#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

/**
 *** MENU PRINCIPAL
 **/

/// Permet d'afficher le menu principal
void show_main_menu(void);

/**
 *** MENU DE GESTION DE CLIENTS
 **/

/// Afficher le menu de gestion de clients
void show_clients_manager_menu(void);

/**
 *** MENU DE FOURNISSEURS
 **/

void show_fournisseurs_manager_menu(void);

/**
 *** MENU DE MEDICAMENTS
 **/

void show_medicaments_manager_menu(void);

/**
 *** MENU DE COMMANDES
 **/

void show_commandes_manager_menu(void);

/**
 *** MENU DE RAPPORT JOURNALIER
 **/

void show_rapport_journalier_menu(void);

#endif /* navigations_h */
