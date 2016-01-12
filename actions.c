//
//  actions.c
//  PharmApp
//
//  Created by Salim Braksa on 1/7/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#include "actions.h"

// Helpers Prototype

void show_back_menu();

void show_clients_helper(LinkedList* clients);
void show_fournisseurs_helper(LinkedList* fournisseurs);

/**
 *** MENU DE GESTION DE CLIENTS
 **/

void show_all_clients(void) {
    
    // Clear
    system("clear");
    
    // Get clients
    LinkedList* clients = get_clients(CLIENTS_FILENAME);
    
    // Afficher les clients
    show_clients_helper(clients);
    
    // Revenir au menu
    show_back_menu();
    
}

void clients_from_name(void) {
    
    // Clear
    system("clear");
    
    // User input
    char name[100];
    printf("Donner le nom du client: ");
    scanf("%s", name);
    
    // Consume any pending input
    getchar();
    
    // Get client from user input
    LinkedList* clients = get_client_from_name(CLIENTS_FILENAME, name);
    
    // Afficher les clients
    show_clients_helper(clients);
    
    // Revenir au menu
    show_back_menu();
    
}

void add_client(void) {
    
    // Clear
    system("clear");
    
    // User Inputs
    char nom[80], telephone[11], cin[9];
    printf("Donner le nom du client: "); scanf("%s", nom);
    printf("Donner le telephone du client: "); scanf("%s", telephone);
    printf("Donner le cin du client: "); scanf("%s", cin);
    
    // Consume any pending input
    getchar();
    
    // Creer un client
    Client* client = creer_client(nom, telephone, cin);
    
    // Sauvegarder le client
    save_client(CLIENTS_FILENAME, client);
    
    // Revenir au menu
    show_back_menu();
    
}

void edit_client(void) {
    
    // Clear
    system("clear");
    
    // Chercher le nom du client
    char name[100];
    printf("Donner le nom du client: ");
    scanf("%s", name);
    
    // Consume any pending input
    getchar();
    
    // Get clients from user input
    LinkedList* clients = get_client_from_name(CLIENTS_FILENAME, name);
    Client* client = NULL;
    int clients_len = list_len(clients);
    
    // Afficher les clients
    show_clients_helper(clients);
    
    // User input
    int user_id = -1;
    
    // S'il existe plusieurs clients dont le nom est 'name'
    if (clients_len > 1) {
        
        // Demander au utilisateur de préciser le client à modifier
        printf("\nPréciser l'id du client que vous voulez modifier\n");
        get_integer("\tVotre choix: ", &user_id);
        
    } else if (clients_len == 1) {
        client = (Client*)clients -> data;
    }
    
    // Chercher le client à partir de son id
    LinkedList* iterator = clients;
    for (int i = 0; i < clients_len; i++) {
        if ( ((Client*)iterator -> data) -> client_id == user_id ) {
            printf("Im Up\n");
            client = (Client*)iterator -> data;
            break;
        }
        iterator = iterator -> next;
    }
    
    // Finalement on commande la modification du client
    // Si la variable client n'est pas NULLE
    if (client) {
        
        // User Inputs
        char nom[80], telephone[11], cin[9];
        printf("\nDonner le nouveau nom du client: "); scanf("%s", nom);
        printf("Donner le nouveau telephone du client: "); scanf("%s", telephone);
        printf("Donner le nouveau cin du client: "); scanf("%s", cin);
        
        // Consume any pending input
        getchar();
        
        // Modifier et sauvegarder le client
        modifier_client(client, nom, telephone, cin);
        save_client(CLIENTS_FILENAME, client);
        
    }
    
    // Revenir au menu
    show_back_menu();
    
}

/**
 *** MENU DE GESTION DE FOURNISSEURS
 **/

void show_all_fournisseurs(void) {
    
    // Clear
    system("clear");
    
    // Get clients
    LinkedList* fournisseurs = get_fournisseurs(FOURNISSEURS_FILENAME);
    
    // Afficher les clients
    show_fournisseurs_helper(fournisseurs);
    
    // Revenir au menu
    show_back_menu();
    
}

void add_fournisseur(void) {
    
    // Clear
    system("clear");
    
    // User Inputs
    char nom[80], email[100], telephone[11];
    printf("Donner le nom du fournisseur: "); scanf("%s", nom);
    printf("Donner l'email du fournisseur: "); scanf("%s", email);
    printf("Donner le telephone du fournisseur: "); scanf("%s", telephone);
    
    // Consume any pending input
    getchar();
    
    // Creer un fournisseur
    Fournisseur* fournisseur =  create_fournisseur(nom, email, telephone);
    
    // Sauvegarder le fournisseur
    save_fournisseur(FOURNISSEURS_FILENAME, fournisseur);
    
    // Revenir au menu
    show_back_menu();
    
}

void modify_fournisseur(void) {
    
    // Clear
    system("clear");
    
    // Chercher du fournisseur
    int fournisseur_id;
    printf("Donner l'id du fournisseur: ");
    scanf("%d", &fournisseur_id);
    
    // Get fournisseur from user input
    Fournisseur* fournisseur = get_fournisseur_from_id(FOURNISSEURS_FILENAME, fournisseur_id);
    
    // Afficher les informations du fournisseur
    LinkedList* list = NULL;
    linked_list_append(&list, fournisseur);
    show_fournisseurs_helper(list);
    free(list);
    
    if (fournisseur) {
        
        // User Inputs
        char nom[80], email[100], telephone[11];
        printf("\nDonner le nom du fournisseur: "); scanf("%s", nom);
        printf("Donner l'email du fournisseur: "); scanf("%s", email);
        printf("Donner le telephone du fournisseur: "); scanf("%s", telephone);
        
        // Consume any pending input
        getchar();
        
        // Modifier et sauvegarder le client
        edit_fournisseur(fournisseur, nom, email, telephone);
        save_fournisseur(FOURNISSEURS_FILENAME, fournisseur);
        
    }
    
    // Revenir au menu
    show_back_menu();
    
}

void delete_fournisseur(void) {
    
    // Clear
    system("clear");
    
    // Chercher du fournisseur à supprimer
    int fournisseur_id;
    printf("Donner l'id du fournisseur: ");
    scanf("%d", &fournisseur_id);
    
    // Consume any pending input
    getchar();
    
    // Get fournisseur from user input
    Fournisseur* fournisseur = get_fournisseur_from_id(FOURNISSEURS_FILENAME, fournisseur_id);
    
    // Afficher les informations du fournisseur
    LinkedList* list = NULL;
    linked_list_append(&list, fournisseur);
    show_fournisseurs_helper(list);
    free(list);
    
    // Supprimer le fournisseur
    if (fournisseur) {
        remove_fournisseur(FOURNISSEURS_FILENAME, fournisseur -> fournisseur_id);
    }
    
    // Revenir au menu
    show_back_menu();
    
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

// Helpers

void show_back_menu() {
    
    printf("\nCliquez sur [ENTRER] pour revenir au menu");
    char enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    
    print_menu(1);
    
}

void show_clients_helper(LinkedList* clients) {
    
    // S'il n'existe pas de clients
    if (!clients) { printf("Il n'existe aucun client\n"); }
    
    // Itérer
    LinkedList* current_client_list = clients;
    while (current_client_list) {
        Client* client = current_client_list -> data;
        printf("%ld\t%s\t%s\t%s\n", client -> client_id, client -> nom, client -> telephone, client -> cin);
        current_client_list = current_client_list -> next;
    }
    
}

void show_fournisseurs_helper(LinkedList* fournisseurs) {
    
    // S'il n'existe pas de clients
    if (!fournisseurs) { printf("Il n'existe aucun fournisseur\n"); }
    
    // Itérer
    LinkedList* current_fournisseur_list = fournisseurs;
    while (current_fournisseur_list) {
        Fournisseur* fournisseur = current_fournisseur_list -> data;
        printf("%ld\t%s\t%s\t%s\n", fournisseur -> fournisseur_id, fournisseur -> nom, fournisseur -> email, fournisseur -> telephone);
        current_fournisseur_list = current_fournisseur_list -> next;
    }
    
}