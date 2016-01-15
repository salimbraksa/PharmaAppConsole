//
//  actions.h
//  PharmApp
//
//  Created by Salim Braksa on 1/7/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#ifndef actions_h
#define actions_h

#include <stdio.h>

#include "menu_controller.h"

#include "client_controller.h"
#include "fournisseur_controller.h"
#include "medicament_controller.h"
#include "constants.h"

/**
 *** MENU DE GESTION DE CLIENTS
 **/

void show_all_clients(void);
void clients_from_name(void);
void add_client(void);
void edit_client(void);

/**
 *** MENU DE GESTION DE FOURNISSEURS
 **/

void show_all_fournisseurs(void);
void add_fournisseur(void);
void modify_fournisseur(void);
void delete_fournisseur(void);

/**
 *** MENU DE GESTION DE MEDICAMENTS
 **/

void add_medicament(void);
void add_medicament_to_commande(void);
void medicament_from_id();
void change_default_fournisseur(void);
void fournisseurs_of_medicament(void);

/**
 *** RETOUR & EXIT
 **/

void exit_app(void);
void back(void);

#endif /* actions_h */
