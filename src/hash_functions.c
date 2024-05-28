/**
 * 
*/
#include "hash_functions.h"
#include "str.h"
#include <stdlib.h>

/**
 * From here: https://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html
*/
unsigned int crc_hash(char * string)
{
    unsigned int h = 0;
    unsigned int m = 97; // Size of the hash table
    unsigned int highorder = h & 0xf8000000;
    unsigned int str_length;

    str_length = str_len(string);

    for (int i = 0; i < str_length; i ++)
    {
        highorder = h & 0xf8000000;    // extract high-order 5 bits from h
                                   // 0xf8000000 is the hexadecimal representation
                                   //   for the 32-bit number with the first five 
                                   //   bits = 1 and the other bits = 0   
        h = h << 5;                    // shift h left by 5 bits
        h = h ^ (highorder >> 27);     // move the highorder 5 bits to the low-order
                                    //   end and XOR into h
        h = h ^ string[i];                    // XOR h and ki
    }

    return h % m;
}


// Doesn't work
unsigned long pjw_hash(char * string)
{
    unsigned long h;
    unsigned long high;
    unsigned long bits;
    unsigned long bytes;
    unsigned int str_length;

    h = 0;
    bits = sizeof(unsigned long) * 8;
    bytes = sizeof(unsigned long);
    str_length = str_len(string);

    for (int i = 0; i < str_length; i ++)
    {
        h = h << bytes + string[i];
        high = h & 0xf000000000000000;

        if (high != 0)
        {
            h ^= (high >> bits * 3/4);
            h &= ~high;
        }
    }

    return h;
}