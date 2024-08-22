//
//  tests.c
//  estrutura-de-dados-2
//
//  Created by Emanuel on 22/08/24.
//

#include "tests.h"
#include "bt.h"
#include <time.h>

const int TEST_REPEAT = 1000;
const char *TESTS_LABELS[] = {"best", "expected", "worst"};

struct node * get_better_bt(void) {
    return create_node(rand());
}

struct node * get_expected_bt(int n) {
    struct node *r = NULL;
    for (int i = 0; i < n; i++) {
        btinsert(&r, create_node(rand()));
    }
    return r;
}

struct node * get_worst_bt(int n) {
    struct node *r = NULL;
    for (int i = 0; i < n; i++) {
        btinsert(&r, create_node(i));
    }
    return r;
}

void tests_bt(unsigned int type) {
    char *file_name = (char *) malloc(sizeof(char) * 28);
    sprintf(file_name, "../graficos/bt-%s.txt", TESTS_LABELS[type]);
    FILE *f = fopen(file_name, "w");
    
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    
    switch (type) {
        case 0:
            for (int dif = 10000; dif <= 100000; dif += 1000) {
                struct node *r = get_better_bt();
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
                free(r);
            }
            break;
        case 1:
            for (int dif = 10000; dif <= 100000; dif += 1000) {
                struct node *r = get_expected_bt(dif);
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
                free(r);
            }
            break;
        default:
            for (int dif = 1000; dif <= 10000; dif += 100) {
                struct node *r = get_worst_bt(dif);
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
                free(r);
            }
            break;
    }
    fclose(f);
}

int test_bt_avl(struct node *btavl) {
    struct timespec s, e;
    clock_gettime(CLOCK_MONOTONIC, &s);
    for (int c = 0; c < TEST_REPEAT; c++) {
        btsearch(&btavl, rand());
    }
    clock_gettime(CLOCK_MONOTONIC, &e);
    
    return (e.tv_sec * 1e9 + e.tv_nsec) - (s.tv_sec * 1e9 + s.tv_nsec);
}
