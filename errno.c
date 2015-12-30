#include <stdio.h>  
#include <string.h>  
#include <errno.h>  

int main()  
{  
    int i;  
    for(i = 0; i < 140; ++i)  
    {  
        errno = i;  
        printf("errno %d :\t\t%s\n",i,strerror(errno));  
    }  
    return 0;  
}  
