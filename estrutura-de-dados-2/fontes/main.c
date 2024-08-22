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
#include "tests.h"

int main(int argc, const char * argv[]) {
//    int type = 2;
//    if (strcmp(argv[1], "b") == 0) {
//        type = 0;
//    } else if (strcmp(argv[1], "e") == 0) {
//        type = 1;
//    }

    tests_bt(0);
    tests_bt(1);
    tests_bt(2);
    return 0;
}
