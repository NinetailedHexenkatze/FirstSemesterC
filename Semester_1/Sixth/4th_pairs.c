#include "4th_pairs.h"
#include <stdlib.h>

void remove_duplicate_pairs(KeyValuePairPtr **pairs, size_t *pairs_count)
{
    if (pairs == NULL || *pairs == NULL || *pairs_count <= 1) {
        return;
    }

    size_t count = *pairs_count;
    KeyValuePairPtr *arr = *pairs;

    for (size_t i = 0; i < count; i++) {
        if (arr[i].key_ptr == NULL) continue;

        for (size_t j = i + 1; j < count; j++) {
            if (arr[j].key_ptr == NULL) continue;

            if (*(arr[i].key_ptr) == *(arr[j].key_ptr)) {
                if (*(arr[i].val_ptr) >= *(arr[j].val_ptr)) {
                    arr[j].key_ptr = NULL;
                    arr[j].val_ptr = NULL;
                } else {
                    arr[i] = arr[j];
                    arr[j].key_ptr = NULL;
                    arr[j].val_ptr = NULL;
                }
            }
        }
    }

    size_t new_count = 0;
    for (size_t i = 0; i < count; i++) {
        if (arr[i].key_ptr != NULL) {
            arr[new_count] = arr[i];
            new_count++;
        }
    }

    if (new_count != count) {
        if (new_count == 0) {
            free(*pairs);
            *pairs = NULL;
        } else {
            KeyValuePairPtr *temp = realloc(*pairs, new_count * sizeof(KeyValuePairPtr));
            if (temp != NULL) {
                *pairs = temp;
            }
        }
        *pairs_count = new_count;
    }
}