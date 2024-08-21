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
        balance(*aux, r);
    } else {
        n->p = *aux;
        if ((*aux)->v > n->v)
            avlinsert(&((*aux)->l), n, r);
        else
            avlinsert(&((*aux)->r), n, r);
    }
}

void balance(struct node* n, struct node** r) {
    n = n->p;
    while (n != NULL) {
        update_height(n);
       
        if (height_offset(n) > 1) {
            int c = get_case(n);

            if (c == 1) {
                rr(&n);
            } else if (c == 2) {
                lr(&n);
            } else if (c == 3) {
                lr(&(n->l));
                rr(&n);
            } else {
                rr(&(n->r));
                lr(&n);
            }
            if (n->p == NULL) {
                *r = n;
            }
        }
        n = n->p;
    }
}

void update_height(struct node* n) {
    if (n == NULL) {
        return;
    }
    
    if ((n->r != NULL) && (n->l != NULL)) {
        n->h = ((n->r->h) > (n->l->h)) ? (n->r->h) + 1 : (n->l->h) + 1;
    }
    else if ((n->l == NULL) && ((n->r != NULL))) {
        n->h = n->r->h + 1;
    }
    else if ((n->l != NULL) && ((n->r == NULL))) {
        n->h = n->l->h + 1;
    }
    n->h = 1;
}

int height_offset(struct node* n) {
    if ((n->l != NULL) && (n->r != NULL)) {
        return abs(n->l->h - n->r->h);
    } else if ((n->l == NULL) && (n->r != NULL)) {
        return n->r->h;
    } else if ((n->l != NULL) && (n->r == NULL)) {
        return n->l->h;
    }
    return 0;
}

int get_case(struct node* n) {
    if (n != NULL) {
        if ((n->l != NULL) && (n->r != NULL)) {
            if ((n->l->h) > (n->r->h)) {
                if ((n->l->l != NULL) && (n->l->r != NULL)) {
                    return ((n->l->l->h) > (n->l->r->h)) ?  1 : 3;
                }
            } else if ((n->r->r != NULL) && (n->r->l != NULL)) {
                return ((n->r->r->h) > (n->r->l->h)) ? 2 : 4;
            }
        } else if ((n->l != NULL) && (n->r == NULL)) {
            return ((n->l->l != NULL) && (n->l->r == NULL)) ? 1 : 3;
        } else {
            if ((n->r->l == NULL) && (n->r->r != NULL)) {
                return 2;
            }
        }
    }
    return 4;
}

void rr(struct node** n) {
    struct node* p = (*n)->p;
    struct node* y = (*n)->l;
    struct node* x = *n;
    struct node* b = y->r;

    y->r = x;
    y->p = p;
    x->l = b;
    x->p = y;
    
    if (b != NULL) {
        b->p = x;
    }

    update_height(x);
    update_height(y);

    if (y->p != NULL) {
        if (y->p->v > y->v) {
            y->p->l = y;
        } else {
            y->p->r = y;
        }
    }
    *n = y;
}

void lr(struct node** n) {
    struct node* p = (*n)->p;
    struct node* y = (*n)->r;
    struct node* x = *n;
    struct node* b = y->l;

    y->l = x;
    y->p = p;
    x->r = b;
    x->p = y;

    if (b != NULL) {
        b->p = x;
    }

    update_height(x);
    update_height(y);

    if (y->p != NULL) {
        if (y->p->v > y->v) {
            y->p->l = y;
        } else {
            y->p->r = y;
        }
    }
    *n = y;
}
