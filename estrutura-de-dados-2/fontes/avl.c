//
//  avl.c
//  estrutura-de-dados-2
//
//  Created by Emanuel on 21/08/24.
//

#include "avl.h"

int get_height(struct node *n) {
    if (n == NULL)
        return 0;
    return n->h;
}

void update_height(struct node* r) {
    int hl = get_height(r->l);
    int hr = get_height(r->r);
    r->h = hl > hr ? hl + 1: hr + 1;
}

void rr(struct node** n) {
    struct node* aux = (*n);
    (*n) = (*n)->l;
    (*n)->p = aux->p;
    aux->p = (*n);
    aux->l = (*n)->r;
    (*n)->r = aux;
    update_height(aux);
    update_height(*n); // Certifique-se de atualizar também o novo nó
}

void lr(struct node** n) {
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
    int hl = get_height((*r)->l);
    int hr = get_height((*r)->r);
    if (abs(hl - hr) > 1) {
        if (hl > hr) {
            if (get_height((*r)->l->l) > get_height((*r)->l->r)) {
                rr(r);
            } else {
                lr(&((*r)->l));
                rr(r);
            }
        } else {
            if (get_height((*r)->r->r) > get_height((*r)->r->l)) {
                lr(r);
            } else {
                rr(&((*r)->r));
                lr(r);
            }
        }
    }
}

void avlinsert(struct node** r, struct node* n) {
    if((*r) != NULL) {
        if ((*r)->v > n->v) {
            avlinsert(&((*r)->l), n);
            (*r)->l->p = (*r);
        } else {
            avlinsert(&((*r)->r), n);
            (*r)->r->p = (*r);
        }
    } else {
        *r = n;
    }
    update_height(*r);
    balance(r);
}
