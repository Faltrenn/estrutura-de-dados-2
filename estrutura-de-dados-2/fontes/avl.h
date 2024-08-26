//
//  avl.h
//  estrutura-de-dados-2
//
//  Created by Emanuel on 21/08/24.
//

#ifndef avl_h
#define avl_h

#include <stdio.h>
#include "bt.h"

void avlinsert(struct node **, struct node *);
void balance(struct node **);
void update_height(struct node *);
int height_offset(struct node *);
int get_case(struct node * n);
void rr(struct node **);
void lr(struct node **);

#endif /* avl_h */
