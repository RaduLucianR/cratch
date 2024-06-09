#include <stdlib.h>
#include <stdio.h>
#include "array_map.h"
#include "hash_functions.h"

struct ArrayMap * arraymap_create(unsigned size) {
    struct ArrayMap * arraymap = (struct ArrayMap *) malloc(sizeof(struct ArrayMap *));
    arraymap->size = size;
    arraymap->count = 0;
    arraymap->key = (char *) malloc(sizeof(char) * arraymap->size);  // this is a pointer to a char/an array of chars
                                                                     // but you want a array of arrays of chars
    arraymap->value = (char *) malloc(sizeof(char) * arraymap->size);

    return arraymap;
}

void arraymap_put(struct ArrayMap * arraymap, char * key, char * value) {
    arraymap->count += 1;
    unsigned int hash = crc_hash(key, arraymap->size);
    printf("%u", hash);
    arraymap->key[hash] = key;
    arraymap->value[hash] = value;
}

char * arraymap_get(struct ArrayMap * arraymap, char * key) {
    unsigned int hash = crc_hash(key, arraymap->size);

    return arraymap->value[hash];
}