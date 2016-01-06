//
//  handlers.c
//  PharmApp
//
//  Created by Salim Braksa on 1/6/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#include "handlers.h"

// Prototype Helpers

void resize_handlers();

Handlers* new_handlers() {
    
    Handlers* handlers = (Handlers*)malloc(sizeof(Handlers));
    
    handlers -> number_of_handlers = 0;
    handlers -> handlers_array = malloc( handlers -> number_of_handlers * sizeof(void (*)(void)));
    
    return handlers;
    
}

void append_handler(Handlers* handlers, void (*f)(void)) {
    
    handlers -> number_of_handlers++;
    resize_handlers(handlers);
    handlers -> handlers_array[handlers -> number_of_handlers-1] = f;

}

void execute_handler(Handlers* handlers, int index) {
    if (index >= handlers -> number_of_handlers) return;
    handlers -> handlers_array[index]();
}

void free_handlers(Handlers* handlers) {
    free(handlers -> handlers_array);
    free(handlers);
}

// Helpers Implementation

void resize_handlers(Handlers* handlers) {
    handlers = realloc(handlers -> handlers_array, sizeof(handlers -> handlers_array) * handlers -> number_of_handlers);
}