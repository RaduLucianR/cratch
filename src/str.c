#include "str.h"

/**
 * BSD implementation of strlen()
 * from here: https://stackoverflow.com/questions/1733281/where-is-the-implementation-of-strlen-in-gcc
*/
unsigned int str_len(char * str)
{
    char * s;
    
    for (s = str; *s; s ++);

    return (s - str);
}
