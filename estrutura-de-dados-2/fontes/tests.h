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
struct node * get_better_bt(void);
struct node * get_expected_bt(int);
struct node * get_worst_bt(int);
void tests_avl(void);
void tests_hash(void);
int test_bt_avl(struct node *);

#endif /* tests_h */
