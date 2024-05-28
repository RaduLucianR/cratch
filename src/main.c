#include <stdio.h>
#include <stdlib.h>
#include "hash_functions.h"

int main()
{
  printf("%u", crc_hash("6"));

  printf("\n");
  return 0;
}
