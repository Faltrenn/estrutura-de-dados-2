//
//  tests.h
//  estrutura-de-dados-2
//
//  Created by Emanuel on 22/08/24.
//

#ifndef tests_h
#define tests_h

#include <stdio.h>
#include "bt.h"

void tests_bt(unsigned int);
void get_best_bt(struct node **);
void get_expected_bt(struct node **);
void get_worst_bt(struct node **);
void tests_avl(unsigned int);
void get_best_avl(struct node **);
void get_expected_avl(struct node **);
void get_worst_avl(struct node **);
void tests_hash(void);
int test_bt_avl(struct node *);

#endif /* tests_h */
