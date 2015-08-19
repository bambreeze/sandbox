#include <stdio.h>

unsigned char cfg_created = 0;
unsigned char cfg_mgmt = 0;
unsigned char cfg_itf[1024];
unsigned char cfg_vlan[4096];

int init (void)
{
    int i = 0;
    
    cfg_created = 0;
    cfg_mgmt = 0;

    for (i = 0; i < 1024; i++) {
        cfg_itf[i] = 0;
    }

    for (i = 0; i < 4096; i++) {
        cfg_vlan[i] = 0;
    }

    return 0;
}

int create_config (int itf)
{
    cfg_itf[itf] = 1;

    if (!cfg_created) {
        printf("create config!\n");
        cfg_created = 1;
    }

    return 0;
}

int delete_config (int itf)
{
    int i = 0;
    int sum = 0;

    cfg_itf[itf] = 0;

    if (cfg_created) {
        for (i = 0; i < 1024; i++) {
            sum += cfg_itf[i];
        }

        if (!sum) {
            printf("delete config!\n");
            cfg_created = 0;
        }
    }

    return 0;
}

int main (void)
{
    int add = 0;
    int itf = 0;

    init();

    while (1) {
        printf("Please input [0/1],[itf]:\n");
        scanf("%d,%d", &add, &itf);

        if (add) {
            create_config(itf);
        } else {
            delete_config(itf);
        }
    }

    return 0;
}
