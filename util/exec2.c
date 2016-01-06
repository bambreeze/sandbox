/* call system() async */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main()
{
    int status = 0;

    //status = system("cat non-exist-file");
    //status = system("./forever");
    //status = system("./forever &");
    //status = system("./sleep10s");
    status = system("./sleep10s");
    if (status){
        printf("system error %d\n", status);
    }
}
