//
//  hash.c
//  estrutura-de-dados-2
//
//  Created by Emanuel on 22/08/24.
//

#include "hash.h"
#include <stdlib.h>
#include <time.h>

struct block * create_block(int valor) {
    struct block* b = (struct block *) malloc(sizeof(struct block));
    b->v = valor;
    b->next = NULL;

    return b;
}

void hinsert(struct htable *t, struct block *b) {
    if(t->n >= t->m) {
        hrefresh(t, b);
    } else {
        int i = b->v % t->m;
        b->next = t->l[i];
        t->l[i] = b;
        t->n = t->n + 1;
    }
}

void worst_hinsert(struct htable *t, struct block *b) {
    b->next = t->l[0];
    t->l[0] = b;
    t->n += 1;
}

void hfree(struct htable * t) {
    for(int i = 0; i < t->m; i++){
        free_block(t->l[i]);
        t->l[i] = NULL;
    }
    t->n = 0;
}

void free_block(struct block *b) {
    struct block *aux;

    while (b != NULL){
        aux = b->next;
        free(b);
        b = aux;
    }
}

void hprint(struct htable *t) {
    for (int i = 0; i < t->m; i++) {
        printf("Chave: %d", i);
        printf(" --> ");
        hlprint(t->l[i]);
        printf("\n");
    }
}

void hlprint(struct block *b) {
    while (b != NULL) {
        printf("%d", b->v);
        printf(" --> ");
        b = b->next;
    }
}

int hash_search(struct htable *t, int v) {
    int i = 0;
    struct block *b;

    for (b = t->l[i]; b != NULL; b = b->next){
        if(b->v == v) {
            return 1;
        }
    }
    return 0;
}

void hrefresh(struct htable *t, struct block *b) {
    struct htable nt;
    nt.m = (t->m * 2);
    nt.l = malloc(sizeof(struct block *) * nt.m);
    nt.n = 1;

    for (int i = 0; i < nt.m; i++){
        nt.l[i] = NULL;
    }

    int i = 0;
    nt.l[i] = b;

    for (int i = 0; i < t->m; i++){
        struct block *nb;
        nb = t->l[i];

        while (nb != NULL) {
            struct block *tab = create_block(nb->v);

            tab->next = nt.l[i];
            nt.l[tab->v % nt.m] = tab;

            nb = nb->next;

            nt.n = nt.n + 1;
        }
    }
    (*t) = nt;
}
