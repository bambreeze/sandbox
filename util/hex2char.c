#include "stdio.h"

static char to_hex_char (int val)
{
    return ("0123456789abcdef"[val & 0xf]);
}

int main (void)
{
    printf("18 is: %c\n", to_hex_char(18));
}
