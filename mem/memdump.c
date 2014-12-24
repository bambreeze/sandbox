#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

unsigned int phy_base = 0x0;
unsigned int len = 256;

int main()
{
    int i = 0, fd = 0;
    unsigned char *map_base = NULL;

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd == -1) {
        printf("Can't open /dev/mem\n");
        return -1;
    }

    map_base = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, phy_base);
    if (!map_base) {
        printf("Can't mmap physical address - 0x%08x\n", phy_base);
        return -1;
    }

    for (i = 0; i < len; i++) {
        if (i % 16 == 0) {
            printf("\n%08x ", phy_base + i);
        }

        printf("%02x ", *(map_base + i));
    }
    printf("\n");

    close(fd);
    munmap(map_base, len);

    return 0;
}

