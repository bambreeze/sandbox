#include <stdio.h>

int main()
{
    printf("=== Makefile macro definition test ===\n");
    printf("Options:\n");
    printf("  make\n");
    printf("  make ARCH=XX\n");
    printf("  make ARCH=YY\n");
    printf("  make ARCH=ZZ\n");
    printf("Result:\n");

#ifdef TEST1
    printf("defined TEST1\n");
#endif

#ifdef TEST2
    printf("defined TEST2\n");
#endif

#ifdef TEST_UNKNOWN
    printf("defined TEST_UNKNOWN\n");
#endif

    return 0;
}
