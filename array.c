#include <stdio.h>

typedef struct _building {
    int room[3];
} building_t;

int main()
{
    building_t mybu;
    building_t *pb;

    pb = &mybu;
    pb->room[0] = 100;
    pb->room[1] = 200;
    pb->room[2] = 300;

    printf("%d\n", mybu.room[0]);
    printf("%d\n", mybu.room[1]);
    printf("%d\n", mybu.room[2]);

    return 0;
}
