//
//  hash.h
//  estrutura-de-dados-2
//
//  Created by Emanuel on 22/08/24.
//

#ifndef hash_h
#define hash_h

#include <stdio.h>

struct block {
    int v;
    struct block *next;
};

struct htable {
    int n; // n
    int m; // m
    struct block **l;
};

struct block* create_block(int);
void hinsert(struct htable *, struct block*);
void best_hrefresh(struct htable *, struct block *);
void best_hinsert(struct htable *, struct block *);
void worst_hinsert(struct htable *, struct block *);
void hfree(struct htable *);
void free_block(struct block *);
void hprint(struct htable *);
void hlprint(struct block *);
int hash_search(struct htable *, int);
int best_hash_search(struct htable *, int);
void hrefresh(struct htable *, struct block*);


#endif /* hash_h */
