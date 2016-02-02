//
//  helpers.h
//  PharmApp
//
//  Created by Salim Braksa on 1/7/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#ifndef helpers_h
#define helpers_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>

/// Permet de copier un string
void sb_strcpy(char** destination, char* source);

/// Permet de lire un entier
int get_integer(const char* prompt, int *i);

/// Permet de lire un long entier
int get_long_integer(const char* prompt, long int*i);

#endif /* helpers_h */
