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

#include <stdio.h>

void print_tree(struct node* root, int space, int height) {
    if (root == NULL)
        return;

    // Aumenta a distância entre níveis
    space += height;

    // Processa o filho da direita primeiro
    print_tree(root->r, space, height);

    // Imprime o nó atual após o espaço adequado
    printf("\n");
    for (int i = height; i < space; i++)
        printf(" ");
    printf("%d(h=%d)\n", root->v, root->h);

    // Processa o filho da esquerda
    print_tree(root->l, space, height);
}

// Função principal para exibir a árvore
void show_tree(struct node* r) {
    printf("V = %d\n", r->v);
    if (r->r != NULL) {
        printf("r");
        show_tree(r->r);
    }
    if (r->l != NULL) {
        printf("l");
        show_tree(r->r);
    }
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
    
    return 0;
}
