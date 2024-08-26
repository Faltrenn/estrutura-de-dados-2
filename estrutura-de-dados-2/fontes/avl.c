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
    r->h = (hl > hr ? hl : hr) + 1;
}

void rotateRight(struct node** n) {
    struct node* aux = (*n)->l;
    (*n)->l = aux->r;
    if (aux->r != NULL) aux->r->p = (*n);
    aux->p = (*n)->p;
    aux->r = (*n);
    (*n)->p = aux;
    (*n) = aux;
    update_height((*n)->r);
    update_height(*n);
}

void rotateLeft(struct node** n) {
    struct node* aux = (*n)->r;
    (*n)->r = aux->l;
    if (aux->l != NULL) aux->l->p = (*n);
    aux->p = (*n)->p;
    aux->l = (*n);
    (*n)->p = aux;
    (*n) = aux;
    update_height((*n)->l);
    update_height(*n);
}

void balance(struct node** r) {
    update_height(*r);
    int hl = getHeight((*r)->l);
    int hr = getHeight((*r)->r);
    if (abs(hl - hr) > 1) {
        if (hl > hr) {
            if (getHeight((*r)->l->l) >= getHeight((*r)->l->r)) {
                rotateRight(r); // CASO 2
            } else {
                rotateLeft(&((*r)->l)); // CASO 4
                rotateRight(r);
            }
        } else {
            if (getHeight((*r)->r->r) >= getHeight((*r)->r->l)) {
                rotateLeft(r); // CASO 1
            } else {
                rotateRight(&((*r)->r)); // CASO 3
                rotateLeft(r);
            }
        }
    }
}

void avlinsert(struct node** r, struct node* n) {
    if (*r == NULL) {
        *r = n;
    } else if (n->v < (*r)->v) {
        avlinsert(&((*r)->l), n);
        (*r)->l->p = *r;
    } else if (n->v > (*r)->v) {
        avlinsert(&((*r)->r), n);
        (*r)->r->p = *r;
    }

    balance(r);
}
