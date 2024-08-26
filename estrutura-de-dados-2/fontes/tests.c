//
//  tests.c
//  estrutura-de-dados-2
//
//  Created by Emanuel on 22/08/24.
//

#include "tests.h"
#include "bt.h"
#include "avl.h"
#include "hash.h"
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
    tfree(r);
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
            for (int dif = 10000; dif <= 100000; dif += INCREMENT) {
                get_best_avl(&r);
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
            }
            break;
        case 1:
            for (int dif = 10000; dif <= 100000; dif += INCREMENT) {
                get_expected_avl(&r);
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
            }
            break;
        default:
            for (int dif = 10000; dif <= 100000; dif += INCREMENT) {
                get_worst_avl(&r);
                printf("%d %d\n", dif, test_bt_avl(r));
                fprintf(f, "%d %d\n", dif, test_bt_avl(r));
            }
            break;
    }
    fclose(f);
    
    printf("%s finished.\n", TESTS_LABELS[type]);
    tfree(r);
}

struct htable * get_best_htable(int n) {
    struct htable *nt = (struct htable *) malloc(sizeof(struct htable));
    nt->l = (struct block **) malloc(sizeof(struct block *) * 4);
    nt->n = 0;
    nt->m = n+1;
    
    for (int i = 0; i < n; i++) {
        hinsert(nt, create_block(i));
    }
    return nt;
}

struct htable * get_expected_htable(int n) {
    printf("a\n");
    struct htable *nt = (struct htable *) malloc(sizeof(struct htable));
    printf("a\n");
    nt->l = (struct block **) malloc(sizeof(struct block *) * 4);
    printf("a\n");
    nt->n = 0;
    printf("a\n");
    nt->m = 4;
    printf("a\n");
    
    for (int i = 0; i < 4; i++) {
        nt->l[i] = NULL;
        printf("!\n");
    }
    
    for (int i = 0; i < n; i++) {
        hinsert(nt, create_block(rand()));
        printf("?\n");
    }
    
    printf("get\n");
    
    return nt;
}

struct htable * get_worst_htable(int n) {
    struct htable *nt = (struct htable *)malloc(sizeof(struct htable));
    nt->l = (struct block **) malloc(sizeof(struct block *) * 4);
    nt->n = 0;
    nt->m = 1;
    
    for (int i = 0; i < 4; i++) {
        nt->l[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        worst_hinsert(nt, create_block(rand()));
    }
    
    return nt;
}

int test_htable(struct htable *t) {
    struct timespec s, e;
    clock_gettime(CLOCK_MONOTONIC, &s);
    for (int c = 0; c < TEST_REPEAT; c++) {
        hash_search(t, rand());
    }
    clock_gettime(CLOCK_MONOTONIC, &e);
    
    return (e.tv_sec * 1e9 + e.tv_nsec) - (s.tv_sec * 1e9 + s.tv_nsec);
}

void tests_htable(unsigned int type) {
    char *file_name = (char *) malloc(sizeof(char) * 29);
    sprintf(file_name, "../graficos/hash-%s.txt", TESTS_LABELS[type]);
    FILE *f = fopen(file_name, "w");
    
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    struct htable *t = NULL;
    switch (type) {
        case 0:
            for (int dif = 10000; dif <= 100000; dif += INCREMENT) {
                t = get_best_htable(dif);
                fprintf(f, "%d %d\n", dif, test_htable(t));
            }
            break;
        case 1:
            for (int dif = 10000; dif <= 100000; dif += INCREMENT) {
                printf("start\n");
                t = get_expected_htable(dif);
                printf("%d %d\n", dif, test_htable(t));
                fprintf(f, "%d %d\n", dif, test_htable(t));
            }
            break;
        default:
            for (int dif = 10000; dif <= 100000; dif += INCREMENT) {
                t = get_worst_htable(dif);
                fprintf(f, "%d %d\n", dif, test_htable(t));
            }
            break;
    }
    fclose(f);
    
    printf("%s finished.\n", TESTS_LABELS[type]);
//    hfree(t);
}
