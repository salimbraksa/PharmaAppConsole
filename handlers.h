//
//  handlers.h
//  PharmApp
//
//  Created by Salim Braksa on 1/6/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#ifndef handlers_h
#define handlers_h

#include <stdio.h>
#include <stdlib.h>

typedef void (*handlers_t)(void);
typedef struct _handlers {
    
    int number_of_handlers;
    handlers_t* handlers_array;
    
} Handlers;

/// Permet de créer un tableau de handlers
Handlers* new_handlers();

/// Ajouter un nouveau handler
void append_handler(Handlers* handlers, void (*f)(void));

/// Executer un handler
void execute_handler(Handlers* handlers, int index);

/// Free handlers array
void free_handlers(Handlers* handlers);

#endif /* handlers_h */
