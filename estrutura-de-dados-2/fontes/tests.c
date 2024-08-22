//
//  tests.c
//  estrutura-de-dados-2
//
//  Created by Emanuel on 22/08/24.
//

#include "tests.h"
#include "bt.h"
#include <time.h>

#define TEST_REPEAT 1000

struct node * get_better_bt(void) {
    return create_node(rand());
}

void tests_bt(void) {
    FILE *f = fopen("../graficos/bt-best.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    for (int dif = 10000; dif <= 100000; dif += 1000) {
        struct node *r = get_better_bt();
        
        struct timespec s, e;
        clock_gettime(CLOCK_MONOTONIC, &s);
        for (int c = 0; c < TEST_REPEAT; c++) {
            btsearch(&r, rand());
        }
        clock_gettime(CLOCK_MONOTONIC, &e);
        
        int t = (e.tv_sec * 1e9 + e.tv_nsec) - (s.tv_sec * 1e9 + s.tv_nsec);
        fprintf(f, "%d %d\n", dif, t);
    }
    fclose(f);
}
