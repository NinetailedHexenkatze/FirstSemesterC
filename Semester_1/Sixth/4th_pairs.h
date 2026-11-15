#ifndef UNTITLED_4TH_PAIRS_H
#define UNTITLED_4TH_PAIRS_H

#include <stddef.h>

typedef struct
{
    int *key_ptr;
    int *val_ptr;
} KeyValuePairPtr;

void remove_duplicate_pairs(KeyValuePairPtr **pairs, size_t *pairs_count);

#endif

