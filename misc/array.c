#include <stdio.h>

typedef struct _building {
    int room[3];
} building_t;

int build_room()
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

typedef struct _port_info {
    int num;
    int map[8];
} port_info;

port_info myport[] = 
{
    {1, {2}},
    {1, {3}},
    {1, {1}},
    {1, {0}},
    {4, {3, 2, 0, 1}},
    {4, {2, 3, 1, 0}},
    {2, {2, 3}},
    {2, {1, 0}},
};
#define MY_PORT_NUM (sizeof(myport)/sizeof(port_info))

int port_mapping()
{
    int i = 0;
    int j = 0;

    printf("port num: %d\n", (int)MY_PORT_NUM);
    for (i = 0; i < MY_PORT_NUM; i++) {
        printf("port%d, serdes num: %d\n", i, myport[i].num);
        for (j = 0; j < myport[i].num; j++) {
            printf("  lane %d\n", myport[i].map[j]);
        }
    }

    return 0;
}

int main()
{
    //build_room();
    port_mapping();

    return 0;
}
