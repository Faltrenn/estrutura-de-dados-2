//
//  bt.h
//  estrutura-de-dados-2
//
//  Created by Emanuel on 20/08/24.
//

#ifndef bt_h
#define bt_h

#include <stdio.h>

#include <stdlib.h>

struct node {
    int v;
    int h;
    struct node *p;
    struct node *r;
    struct node *l;
};

struct node * create_node(int);
void btinsert(struct node **, struct node *);
struct node** btsearch(struct node**, int);
void tfree(struct node *);
void tprint(struct node*);

#endif /* bt_h */
