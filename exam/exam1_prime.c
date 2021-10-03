#include <stdio.h>
#include <math.h>

int is_prime(int num)
{
    int i = 0;

    for (i = 2; i < sqrt(num); i++) {
        if (num % i == 0) {
           return 0; 
        }
    }

    return 1;
}

int main (void)
{
    int num = 2;
    int counter = 0;

    while (counter < 10) {
        if (is_prime(num)) {
            printf("%d ", num);
            counter++;
        }
        num++;
    }

    return 0;
}