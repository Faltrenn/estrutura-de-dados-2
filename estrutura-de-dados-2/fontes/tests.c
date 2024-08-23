//
//  tests.c
//  estrutura-de-dados-2
//
//  Created by Emanuel on 22/08/24.
//

#include "tests.h"
#include "bt.h"
#include "avl.h"
#include <time.h>

const int TEST_REPEAT = 1000;
const int INCREMENT = 500;
const char *TESTS_LABELS[] = {"best", "expected", "worst"};

void get_best_bt(struct node **r) {
    *r = create_node(rand());
}

void get_expected_bt(struct node **r) {
    for (int i = 0; i < INCREMENT; i++) {
        btinsert(r, create_node(rand()));
    }
}

void get_worst_bt(struct node **r) {
    for (int i = 0; i < INCREMENT; i++) {
        btinsert(r, create_node(i));
    }
}

void tests_bt(unsigned int type) {
    char *file_name = (char *) malloc(sizeof(char) * 28);
    sprintf(file_name, "../graficos/bt-%s.txt", TESTS_LABELS[type]);
    FILE *f = fopen(file_name, "w");
    
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    
    struct node *r = NULL;
    switch (type) {
        case 0:
            for (int dif = 10000; dif <= 100000; dif += INCREMENT) {
                get_best_bt(&r);
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
            }
            break;
        case 1:
            for (int dif = 10000; dif <= 100000; dif += INCREMENT) {
                get_expected_bt(&r);
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
            }
            break;
        default:
            for (int dif = 10000; dif <= 100000; dif += INCREMENT) {
                get_worst_bt(&r);
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
            }
            break;
    }
    fclose(f);
    
    printf("%s finished.\n", TESTS_LABELS[type]);
    free(r);
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

void get_best_avl(struct node **r) {
    *r = create_node(rand());
}

void get_expected_avl(struct node **r) {
    for (int i = 0; i < INCREMENT; i++) {
        avlinsert(r, create_node(rand()), r);
    }
}

void get_worst_avl(struct node **r) {
    for (int i = 0; i < INCREMENT; i++) {
        avlinsert(r, create_node(i), r);
    }
}

void tests_avl(unsigned int type) {
    char *file_name = (char *) malloc(sizeof(char) * 29);
    sprintf(file_name, "../graficos/avl-%s.txt", TESTS_LABELS[type]);
    FILE *f = fopen(file_name, "w");
    
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    struct node *r = NULL;
    switch (type) {
        case 0:
            for (int dif = 1000; dif <= 100000; dif += INCREMENT) {
                get_best_avl(&r);
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
            }
            break;
        case 1:
            for (int dif = 1000; dif <= 100000; dif += INCREMENT) {
                get_expected_avl(&r);
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
            }
            break;
        default:
            for (int dif = 1000; dif <= 100000; dif += INCREMENT) {
                get_worst_avl(&r);
                printf("%d %d\n", dif, test_bt_avl(r));
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
            }
            break;
    }
    fclose(f);
    
    printf("%s finished.\n", TESTS_LABELS[type]);
    free(r);
}
