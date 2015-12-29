#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main()
{
    int status = 0;

    status = system("cat non-exist-file");
    //status = system("./forever");
    if (status){
        printf("system error %d\n", status);
    }
}
