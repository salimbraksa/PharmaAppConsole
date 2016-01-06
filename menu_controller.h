//
//  menu_controller.h
//  PharmApp
//
//  Created by Salim Braksa on 1/5/16.
//  Copyright © 2016 Braksa Salim. All rights reserved.
//

#ifndef menu_controller_h
#define menu_controller_h

#include <stdio.h>
#include "stack.h"
#include "menu.h"

/// Stack of menus
extern Stack* stack_menus;

/// Print path
void print_path(Stack* menus);

#endif /* menu_controller_h */
