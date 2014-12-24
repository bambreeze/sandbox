/* utility for dump physical memory */

#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int i = 0;
    int fd = 0;
    unsigned int phy_base = 0;
    unsigned int phy_off = 0;
    unsigned char *map_base = NULL;
    unsigned int addr = 0;
    unsigned int len = 0;

    printf("Please input the physical address: ");
    scanf("%u", &addr);

    printf("Please input the length: ");
    scanf("%u", &len);

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd == -1) {
        printf("Can't open /dev/mem\n");
        return -1;
    }

    // physical address need align to 4K page
    phy_base = addr & ~0xfff;
    phy_off  = addr & 0xfff;

    map_base = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, phy_base);
    if (!map_base) {
        printf("Can't mmap physical address - 0x%08x\n", phy_base);
        return -1;
    }

    for (i = 0; i < len; i++) {
        if (i % 16 == 0) {
            printf("\n%08x ", addr + i);
        }

        printf("%02x ", *(map_base + phy_off + i));
    }
    printf("\n");

    close(fd);
    munmap(map_base, len);

    return 0;
}
