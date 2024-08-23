//
//  avl.c
//  estrutura-de-dados-2
//
//  Created by Emanuel on 21/08/24.
//

#include "avl.h"

void avlinsert(struct node** aux, struct node* n, struct node** r) {
    if (*aux == NULL) {
        *aux = n;
    } else {
        n->p = *aux;
        if ((*aux)->v > n->v) {
            avlinsert(&((*aux)->l), n, r);
        } else {
            avlinsert(&((*aux)->r), n, r);
        }
    }
    balance(*aux, r);
}

void balance(struct node* n, struct node** r) {
    while (n != NULL) {
        int balance_factor = height_offset(n);
        update_height(n);

        if (balance_factor > 1) {
            if (n->l != NULL && height_offset(n->l) >= 0) {
                rr(&n);
            } else if (n->l != NULL) {
                lr(&(n->l));
                rr(&n);
            } else if (n->r != NULL && height_offset(n->r) >= 0) {
                lr(&n);
            } else {
                rr(&(n->r));
                lr(&n);
            }
        }

        if (n->p == NULL) {
            *r = n;
        }
        n = n->p;
    }
}

void update_height(struct node* n) {
    if (n == NULL) return;
    int left_height = (n->l != NULL) ? n->l->h : 0;
    int right_height = (n->r != NULL) ? n->r->h : 0;
    n->h = ((left_height > right_height) ? left_height : right_height) + 1;
}

int height_offset(struct node* n) {
    int left_height = (n->l != NULL) ? n->l->h : 0;
    int right_height = (n->r != NULL) ? n->r->h : 0;
    return left_height - right_height;
}

void rr(struct node** n) {
    struct node* y = (*n)->l;
    struct node* x = *n;
    struct node* b = y->r;

    y->r = x;
    x->l = b;

    if (b != NULL) b->p = x;
    y->p = x->p;
    x->p = y;

    update_height(x);
    update_height(y);

    *n = y;
}

void lr(struct node** n) {
    struct node* y = (*n)->r;
    struct node* x = *n;
    struct node* b = y->l;

    y->l = x;
    x->r = b;

    if (b != NULL) b->p = x;
    y->p = x->p;
    x->p = y;

    update_height(x);
    update_height(y);

    *n = y;
}

