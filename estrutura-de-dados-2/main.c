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
    struct node* raiz = NULL;

    struct timespec s, e;
    int t;

    srand(time(NULL));
    
    for (int i = 0; i < 100; i++) {
        btinsert(&raiz, create_node(rand()));
    }

    clock_gettime(CLOCK_MONOTONIC, &s);
    for (int c = 0; c < 1000; c++) {
        btsearch(&raiz, rand());
    }
    clock_gettime(CLOCK_MONOTONIC, &e);

    t = (e.tv_sec * 1e9 + e.tv_nsec) - (s.tv_sec * 1e9 + s.tv_nsec);

    printf("%d\n", t);
    return 0;
}
