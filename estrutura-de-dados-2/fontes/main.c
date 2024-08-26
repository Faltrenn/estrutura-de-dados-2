//
//  main.c
//  estrutura-de-dados-2
//
//  Created by Emanuel on 20/08/24.
//

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "bt.h"
#include "avl.h"
#include "hash.h"
#include "tests.h"

int len(struct node *root) {
    if (root == NULL) {
        return 0;  // Base: Se o nó é nulo, retorna 0
    }
    // Recursão: soma 1 (o nó atual) mais o número de nós à esquerda e à direita
    return 1 + len(root->l) + len(root->r);
}


int main(int argc, const char * argv[]) {
//    int type = 2;
//    if (strcmp(argv[1], "b") == 0) {
//        type = 0;
//    } else if (strcmp(argv[1], "e") == 0) {
//        type = 1;
//    }
    
    for (long long unsigned int i = 0; i < UINT32_MAX << 2; i++) {
        continue;
    }
    
    srand((unsigned int) time(NULL));

    tests_bt(0);
    tests_bt(1);
    tests_bt(2);
    
    tests_avl(0);
    tests_avl(1);
    tests_avl(2);
    
    tests_htable(0);
    tests_htable(1);
    tests_htable(2);
    
//    struct node *avl = NULL;
//    struct node *bt = NULL;
//    
//    for (int i = 0; i < 100000; i += 500) {
//        avlinsert(&avl, create_node(i));
//        btinsert(&bt, create_node(i));
//    }
//    printf("%d\n", test_bt_avl(avl));
//    printf("%d\n", test_bt_avl(bt));
    
    return 0;
}
