#include <stdio.h>
#include <stdlib.h>
#include <array_map.h>
#include "hash_functions.h"

int main()
{
  struct ArrayMap * arraymap = arraymap_create(5);
  arraymap_put(arraymap, "s", "abc");
  char * res = arraymap_get(arraymap, "s");
  printf("%s", res);

  printf("\n");
  return 0;
}
