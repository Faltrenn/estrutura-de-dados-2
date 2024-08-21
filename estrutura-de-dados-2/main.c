//
//  main.c
//  estrutura-de-dados-2
//
//  Created by Emanuel on 20/08/24.
//

#include <stdio.h>
#include <time.h>
#include "bt.h"

int main(int argc, const char * argv[]) {
    struct node* r = NULL;

    struct timespec s, e;
    int t;

    srand(time(NULL));
//  Melhor caso e caso esperado
//    for (int i = 0; i < 100; i++) {
//        btinsert(&r, create_node(rand()));
//    }
    
//  Pior caso
    for (int i = 0; i < 100; i++) {
        btinsert(&r, create_node(i));
    }
    
//  Caso esperado
//    clock_gettime(CLOCK_MONOTONIC, &s);
//    for (int c = 0; c < 1000; c++) {
//        btsearch(&r, rand());
//    }
//    clock_gettime(CLOCK_MONOTONIC, &e);

//  Melhor caso
//    clock_gettime(CLOCK_MONOTONIC, &s);
//    for (int c = 0; c < 1000; c++) {
//        btsearch(&r, r->v);
//    }
//    clock_gettime(CLOCK_MONOTONIC, &e);
    
//  Pior caso
    clock_gettime(CLOCK_MONOTONIC, &s);
    for (int c = 0; c < 1000; c++) {
        btsearch(&r, 100);
    }
    clock_gettime(CLOCK_MONOTONIC, &e);
    
    tfree(r);

    t = (e.tv_sec * 1e9 + e.tv_nsec) - (s.tv_sec * 1e9 + s.tv_nsec);

    printf("%d\n", t);
    return 0;
}
