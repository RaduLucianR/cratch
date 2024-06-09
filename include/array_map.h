/**
 * 
*/

struct ArrayMap {
    char * key;
    char * value;
    unsigned count;
    unsigned size;
};

struct ArrayMap * arraymap_create(unsigned size);
void arraymap_put(struct ArrayMap * arraymap, char * key, char * value);
char * arraymap_get(struct ArrayMap * arraymap, char * key);
void arraymap_print(struct ArrayMap * arraymap);
