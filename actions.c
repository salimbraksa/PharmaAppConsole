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
void show_medicaments_helper(LinkedList* list);
void show_commandes_helper(LinkedList* commandes);
void show_ventes_helper(LinkedList* ventes);

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
    scanf("%[^\n]%*c", name);
    
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
    printf("Donner le nom du client: "); scanf("%[^\n]%*c", nom);
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
    scanf("%[^\n]%*c", name);
    
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
        printf("\nDonner le nouveau nom du client: "); scanf("%[^\n]%*c", nom);
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
    printf("Donner le nom du fournisseur: "); scanf("%[^\n]%*c", nom);
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
        printf("\nDonner le nom du fournisseur: "); scanf("%[^\n]%*c", nom);
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
 *** MENU DE GESTION DE MEDICAMENTS
 **/

void add_medicament(void) {
    
    // Clear
    system("clear");
    
    // User Inputs
    char nom[80], description[201];
    int quantite, seuil, nombre_fournisseurs, default_fournisseur_id;
    double prix;
    int fournisseurs_ids[MAXIMUM_FOURNISSEURS] = { 0 };
    
    printf("Donner le nom du médicament: "); scanf("%[^\n]%*c", nom);
    printf("Donner la description du médicament: "); scanf("%[^\n]%*c", description);
    get_integer("Donner la quantite du médicament: ", &quantite);
    printf("Donner le prix du médicament: "); scanf("%lf", &prix);
    printf("Donner le seuil du médicament: "); scanf("%d", &seuil);
    printf("\n");
    printf("Donner l'id des fournisseurs du médicament ( -1 pour arrêter )\n");
    
    // Les fournisseurs du médicament
    int fournisseur_id;
    nombre_fournisseurs = 0;
    for (int i = 0; i < MAXIMUM_FOURNISSEURS; i++) {
        printf("Donner l'id du %d ème fournisseur: ", i+1);
        get_integer("", &fournisseur_id);
        if (fournisseur_id == -1) break;
        fournisseurs_ids[i] = fournisseur_id;
        nombre_fournisseurs++;
    }
    
    // Le fournisseur par default et le premier fournisseur entrer
    default_fournisseur_id = fournisseurs_ids[0];
    
    // Creer un fournisseur
    Medicament* medicament = create_medicament(nom, description, prix, quantite, seuil, nombre_fournisseurs, default_fournisseur_id, fournisseurs_ids);
    
    // Sauvegarder le medicament
    save_medicament(MEDICAMENTS_FILENAME, medicament);
    
    // Revenir au menu
    show_back_menu();
    
}

void add_medicament_to_commande(void) {
    
    // Clear
    system("clear");
    
    // Prepare Vente fields
    int number_medics;
    long int medicaments[VENTE_MAX_MEDICAMENTS_IDS][2];
    get_integer("Donner le nombre de médicaments à vendre par espèce: ", &number_medics);
    for (int i = 0; i < number_medics; i++) {
        
        int medic_id;
        long int medic_quantity;
        
        printf("\n== Médicament %d ==\n", i+1);
        get_integer("Id: ", &medic_id);
        get_long_integer("Quantité: ", &medic_quantity);
        
        medicaments[i][0] = medic_id;
        medicaments[i][1] = medic_quantity;
        
    }
    
    // Create vente
    Commande* commande = create_commande(time(NULL), number_medics, medicaments);
    
    // Save it
    save_commande(COMMANDES_FILENAME, commande);
    
    // Revenir
    show_back_menu();
    
}

void medicament_from_id() {
    
    // Clear
    system("clear");
    
    // User Input
    long int medic_id;
    printf("Donner l'id du médicament: ");
    scanf("%ld", &medic_id);
    
    // Consume any pending input
    getchar();
    
    // Trouver le médicament
    Medicament* medic = get_medicament_from_id(MEDICAMENTS_FILENAME, medic_id);
    
    // Afficher le médicament
    LinkedList* medics = NULL;
    linked_list_append(&medics, medic);
    show_medicaments_helper(medics);
    free(medics);
    
    // Revenir au menu
    printf("\n");
    show_back_menu();
    
}

void change_default_fournisseur(void) {
    
    // Clear
    system("clear");
    
    // User Input
    long int medic_id;
    printf("Donner l'id du médicament: ");
    scanf("%ld", &medic_id);
    
    // Consume any pending input
    getchar();
    
    // Trouver le médicament
    Medicament* medic = get_medicament_from_id(MEDICAMENTS_FILENAME, medic_id);
    
    if (medic) {
        
        // Afficher les fournisseurs du medic
        printf("Les ids des fournisseurs du médicament sont: ");
        for (int i = 0; i < medic -> nombre_fournisseurs; i++) {
            printf( (i != medic -> nombre_fournisseurs - 1) ? "%d, " : "%d\n", medic -> fournisseurs_ids[i]);
        }
        
        // Afficher l'id du fournisseur par défault
        printf("L'id du fournisseur par défault est: %ld", medic -> default_fournisseur_id);
        
        // Demander au utilisateur de changer l'id du fournisseur
        int new_id;
        get_integer("\nChanger l'id du fournisseur par défault: ", &new_id);
        medic -> default_fournisseur_id = new_id;
        
        // Sauvegarder
        save_medicament(MEDICAMENTS_FILENAME, medic);
        
    }
    
    // Revenir
    show_back_menu();
    
}

void sell_medicaments(void) {
    
    // Clear
    system("clear");
    
    // Prepare Vente fields
    int number_medics;
    int medicaments[VENTE_MAX_MEDICAMENTS_IDS][2];
    get_integer("Donner le nombre de médicaments à vendre par espèce: ", &number_medics);
    for (int i = 0; i < number_medics; i++) {
        
        int medic_id;
        int medic_quantity;
        
        printf("\n== Médicament %d ==\n", i+1);
        get_integer("Id: ", &medic_id);
        get_integer("Quantité: ", &medic_quantity);
        
        medicaments[i][0] = medic_id;
        medicaments[i][1] = medic_quantity;
        
    }
    
    // Create vente
    Vente* vente = create_vente(time(NULL), number_medics, medicaments);
    
    // Save it
    save_vente(VENTES_FILENAME, vente);
    
    // Return
    show_back_menu();
    
}

/**
 *** MENU DE COMMANDES
 **/

void commande_from_day(void) {
    
    // Clear
    system("clear");
    
    // Demander au utilisateur de donner la date du jour
    char day[10];
    printf("Donner la date du jour: ");
    scanf("%s", day);
    
    // Consume any pending input
    getchar();
    
    // Get commande
    LinkedList* commandes = get_commandes_from_date(COMMANDES_FILENAME, day, None);
    
    // Afficher la commande
    show_commandes_helper(commandes);
    
    // Revenir
    show_back_menu();
    
}

void commandes_from_year(void) {
    
    // Clear
    system("clear");
    
    // Demander au utilisateur de donner la date du jour
    char year[4];
    printf("Donner l'année: ");
    scanf("%[^\n]%*c", year);
    
    // Get commande
    LinkedList* commandes = get_commandes_from_date(COMMANDES_FILENAME, year, Month | Day);
    
    // Afficher la commande
    show_commandes_helper(commandes);
    
    // Revenir
    show_back_menu();
    
}

/**
 *** MENU DE VENTES
 **/

void vente_from_day(void) {
    
    // Clear
    system("clear");
    
    // Demander au utilisateur de donner la date du jour
    char day[10];
    printf("Donner la date du jour: ");
    scanf("%s", day);
    
    // Consume any pending input
    getchar();
    
    // Get commande
    LinkedList* ventes = get_ventes_from_date(VENTES_FILENAME, day, None);
    
    // Afficher la commande
    show_ventes_helper(ventes);
    
    // Revenir
    show_back_menu();
    
}

void ventes_from_year(void) {
    
    // Clear
    system("clear");
    
    // Demander au utilisateur de donner la date du jour
    char year[4];
    printf("Donner l'année: ");
    scanf("%[^\n]%*c", year);
    printf("\n");
    
    // Get commande
    LinkedList* ventes = get_ventes_from_date(VENTES_FILENAME, year, Month | Day);
    
    // Afficher la commande
    show_ventes_helper(ventes);
    
    // Revenir
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

void show_medicaments_helper(LinkedList* medicaments) {
    
    // S'il n'existe pas de clients
    if (!medicaments) { printf("Il n'existe aucun medicaments\n"); }
    
    // Itérer
    LinkedList* current_medicament_list = medicaments;
    while (current_medicament_list) {
        Medicament* medicament = current_medicament_list -> data;
        printf("%ld\t%s\t%d\t%lf Dhs", medicament -> medicament_id, medicament -> nom, medicament -> quantite, medicament -> prix);
        current_medicament_list = current_medicament_list -> next;
    }
    
}

void show_commandes_helper(LinkedList* commandes) {
    
    // S'il n'existe pas de clients
    if (!commandes) { printf("Il n'existe aucune commande\n"); }
    
    // Itérer
    LinkedList* current_commande_list = commandes;
    while (current_commande_list) {
        
        Commande* commande = current_commande_list -> data;
        
        // Ne pas afficher les commandes don't le nombre de médics est 0
        if (commande -> nombre_medicaments == 0) {
            current_commande_list = current_commande_list -> next;
            continue;
        }
        
        printf("%ld\t", commande -> commande_id);
        
        // Afficher chaque médicament
        for (int i = 0; i < commande -> nombre_medicaments; i++) {
            
            long int medic_id = commande -> medicaments[i][0];
            long int quantity = commande -> medicaments[i][1];
            Medicament* medicament = get_medicament_from_id(MEDICAMENTS_FILENAME, medic_id);
            printf( (i != commande -> nombre_medicaments - 1) ? "%s x %ld\n\t" : "%s x %ld\n" , medicament -> nom, quantity);
            free(medicament);
            
        }
        
        current_commande_list = current_commande_list -> next;
    }
    
}

void show_ventes_helper(LinkedList* ventes) {
    
    // S'il n'existe pas de clients
    if (!ventes) { printf("Il n'existe aucune vente\n"); }
    
    // Itérer
    LinkedList* current_vente_list = ventes;
    while (current_vente_list) {
        
        Vente* vente = current_vente_list -> data;
        printf("%ld\t", vente -> vente_id);
        
        // Afficher chaque médicament
        for (int i = 0; i < vente -> nombre_medicaments; i++) {
            
            long int medic_id = vente -> medicaments[i][0];
            long int quantity = vente -> medicaments[i][1];
            Medicament* medicament = get_medicament_from_id(MEDICAMENTS_FILENAME, medic_id);
            printf( (i != vente -> nombre_medicaments - 1) ? "%s x %ld\n\t" : "%s x %ld\n" , medicament -> nom, quantity);
            free(medicament);
            
        }
        
        current_vente_list = current_vente_list -> next;
    }
    
}