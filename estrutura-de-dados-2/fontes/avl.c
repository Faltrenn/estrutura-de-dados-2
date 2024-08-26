//
//  avl.c
//  estrutura-de-dados-2
//
//  Created by Emanuel on 21/08/24.
//

#include "avl.h"

int getHeight(struct node *n) {
    if (n == NULL)
        return 0;
    return n->h;
}

void update_height(struct node* r) {
    int hl = getHeight(r->l);
    int hr = getHeight(r->r);
    r->h = hl > hr ? hl + 1: hr + 1;
}

void rotateRight(struct node** n) {
    struct node* aux = (*n);
    (*n) = (*n)->l;
    (*n)->p = aux->p;
    aux->p = (*n);
    aux->l = (*n)->r;
    (*n)->r = aux;
    update_height(aux);
}

void rotateLeft(struct node** n) {
    struct node* aux = (*n);
    (*n) = (*n)->r;
    (*n)->p = aux->p;
    aux->p = (*n);
    aux->r = (*n)->l;
    (*n)->l = aux;
    update_height(aux);
    update_height(*n);
}

void balance(struct node** r) {
    int hl = getHeight((*r)->l);
    int hr = getHeight((*r)->r);
    if (abs(hl - hr) > 1) {
        if (hl > hr) {
            if (getHeight((*r)->l->l) > getHeight((*r)->l->r)) {
                // CASO 2
                rotateRight(r);
            } else {
                // CASO 4
                rotateLeft(&((*r)->l));
                rotateRight(r);
            }
        } else {
            if (getHeight((*r)->r->r) > getHeight((*r)->r->l)) {
                // CASO 1
                rotateLeft(r);
            } else {
                // CASO 3
                rotateRight(&((*r)->r));
                rotateLeft(r);
            }
        }
    }
}

void avlinsert(struct node** r, struct node* n) {
    if((*r) != NULL) {
        if ((*r)->v > n->v) {
            btinsert(&((*r)->l), n);
            (*r)->l->p = (*r);
        } else {
            btinsert(&((*r)->r), n);
            (*r)->r->p = (*r);
        }
    } else {
        *r = n;
    }
    update_height(*r);
    balance(r);
}
