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

int main(int argc, const char * argv[]) {
//    int type = 2;
//    if (strcmp(argv[1], "b") == 0) {
//        type = 0;
//    } else if (strcmp(argv[1], "e") == 0) {
//        type = 1;
//    }
    
    for (long long unsigned int i = 0; i < UINT32_MAX << 4; i++) {
        continue;
    }

//    tests_bt(1);
//    tests_bt(0);
//    tests_bt(1);
//    tests_bt(2);
    
//    printf("start1\n");
//    struct node *r = NULL;
//    for (int i = 0; i < 30; i++) {
//        get_worst_avl(&r);
//    }
//    printf("start2\n");
//
    tests_avl(0);
    tests_avl(1);
    tests_avl(2);
    
//    tests_htable(0);
//    tests_htable(1);
//    tests_htable(2);
    return 0;
}
