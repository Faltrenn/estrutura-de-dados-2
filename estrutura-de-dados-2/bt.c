//
//  bt.c
//  estrutura-de-dados-2
//
//  Created by Emanuel on 20/08/24.
//

#include "bt.h"

struct node * create_node(int v) {
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->h = 1;
    n->v = v;
    n->p = NULL;
    n->l = NULL;
    n->r = NULL;
    return n;
}

void btinsert(struct node **r, struct node *n) {
    if (*r != NULL) {
        if ((*r)->v > n->v) {
            btinsert(&(*r)->l, n);
            (*r)->l->p = *r;
        } else {
            btinsert(&(*r)->r, n);
            (*r)->r->p = *r;
        }
    } else {
        (*r) = n;
    }
}

struct node** btsearch(struct node** r, int v) {
    if ((*r) != NULL) {
        if ((*r)->v == v) {
            return r;
        } else if ((*r)->v > v) {
            return btsearch(&((*r)->l), v);
        }
        return btsearch(&((*r)->r), v);
    }
    return NULL;
}

void btfree(struct node *r) {
    if (r != NULL) {
        btfree(r->l);
        btfree(r->r);
        free(r);
    }
}

void btprint(struct node* r) {
    if (r != NULL) {
        btprint(r->l);
        printf("%d \n", r->v);
        btprint(r->r);
    }
}
