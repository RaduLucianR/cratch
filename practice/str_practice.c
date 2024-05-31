#include <stdio.h>

int str_len_practice(char * string)
{
    char * s;

    for (s = string; (* s) != '\0'; s ++) {}

    return s - string;
}

int main()
{
    char * input = "abcdefg";

    printf("%i\n", str_len_practice(input));

    return 0;
}