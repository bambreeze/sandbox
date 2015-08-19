#include <stdio.h>

unsigned char created = 0;
unsigned char packet = 0;
unsigned char config[1024];

// generate errors in purpose
unsigned char cerrs = 0;
unsigned char derrs = 0;

int init (void)
{
    int i = 0;

    created = 0;
    packet = 0;
    cerrs = 0;
    derrs = 0;

    for (i = 0; i < 1024; i++) {
        config[i] = 0;
    }

    return 0;
}

int create (int itf, int old_cfg)
{
    if (!created) {
        if (cerrs++ < 3) {
            printf("create config error ... No.%d!\n", cerrs);
        } else {
            printf("create config!\n");
            created = 1;
            cerrs = 0;
        }
    }

    if (!old_cfg)
        packet++;

    return 0;
}

int delete (int itf, int old_cfg)
{
    if (old_cfg)
        packet--;

    if (created && !packet) {
        if (derrs++ < 2) {
            printf("delete config error ... No.%d!\n", derrs);
        } else {
            printf("delete config!\n");
            created = 0;
            derrs = 0;
        }
    }

    return 0;
}

int main (void)
{
    int add = 0;
    int itf = 0;
    int old = 0;

    init();

    while (1) {
        printf("Please input [0/1],[itf]:\n");
        scanf("%d,%d", &add, &itf);

        old = config[itf];
        config[itf] = add;

        if (add) {
            create(itf, old);
        } else {
            delete(itf, old);
        }
    }

    return 0;
}
