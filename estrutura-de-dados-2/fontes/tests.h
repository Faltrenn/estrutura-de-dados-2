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
#include "hash.h"

int test_bt_avl(struct node *);
void tests_bt(unsigned int);
void get_best_bt(struct node **);
void get_expected_bt(struct node **);
void get_worst_bt(struct node **);
void tests_avl(unsigned int);
void get_best_avl(struct node **);
void get_expected_avl(struct node **);
void get_worst_avl(struct node **);
void tests_htable(unsigned int);
struct htable * get_best_htable(int);
struct htable * get_expected_htable(int);
struct htable * get_worst_htable(int);
int test_htable(struct htable *);
int best_test_htable(struct htable *);

#endif /* tests_h */
