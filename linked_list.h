//
//  linked_list.h
//  PharmApp
//
//  Created by Salim Braksa on 12/30/15.
//  Copyright © 2015 Braksa Salim. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <stdlib.h>

/// liste chainée générique
typedef struct _linked_list {
    
    void* data;
    struct _linked_list* next;
    
} LinkedList ;

/// Permet de créer un nouveau noeud
LinkedList* linked_list_new();

/// Permet d'ajouter un élément à la liste chainée
void linked_list_append(LinkedList** list, void* element);

#endif /* linked_list_h */
