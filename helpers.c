//
//  helpers.c
//  PharmApp
//
//  Created by Salim Braksa on 1/7/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#include "helpers.h"

void sb_strcpy(char** destination, char* source) {
    
    // Alloc destination
    *destination = malloc(strlen(source)+1);
    
    // Copy
    strcpy(*destination, source);
    
}

int get_integer(const char* prompt, int *i) {
    
    int invalid = 0;
    int end_index;
    char buffer[100];
    
    do {
        
        invalid = 1;
        fputs(prompt, stdout);
        if (NULL == fgets(buffer, sizeof(buffer), stdin)) return 1;
        errno = 0;
        
    } while ((1 != sscanf(buffer, "%d %n", i, &end_index)) || buffer[end_index] || errno);
    return 0;
    
}

int get_long_integer(const char* prompt, long int *i) {
    
    int invalid = 0;
    int end_index;
    char buffer[100];
    
    do {
        
        invalid = 1;
        fputs(prompt, stdout);
        if (NULL == fgets(buffer, sizeof(buffer), stdin)) return 1;
        errno = 0;
        
    } while ((1 != sscanf(buffer, "%ld %n", i, &end_index)) || buffer[end_index] || errno);
    return 0;
    
}