# include "stdio.h"
# include "memory.h"

// Pseudo-header of IPv6 header
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |                                                               |
// +                                                               +
// |                                                               |
// +                         Source Address                        +
// |                                                               |
// +                                                               +
// |                                                               |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |                                                               |
// +                                                               +
// |                                                               |
// +                      Destination Address                      +
// |                                                               |
// +                                                               +
// |                                                               |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |                   Upper-Layer Packet Length                   |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |                      zero                     |  Next Header  |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
unsigned char pkt[] = {
    // pseudo header
    // source addr
    0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x86, 0xff, 0xfe, 0x05, 0x80, 0xda,
    // dest addr
    0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x60, 0x97, 0xff, 0xfe, 0x07, 0x69, 0xea,
    // payload len
    0x00, 0x00, 0x00, 0x20,
    // next header
    0x00, 0x00, 0x00, 0x3a,

    // icmp header
    0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x60, 0x97, 0xff, 0xfe, 0x07, 0x69, 0xea,
    0x01, 0x01, 0x00, 0x00, 0x86, 0x05, 0x80, 0xda,
};

unsigned short ipv6csum(unsigned char *buffer, int len)
{
    unsigned long cksum = 0;
    unsigned short *p = (unsigned short *)buffer;
    int size = (len >> 1) + (len & 0x1);

    while (size-- > 0) {
        cksum += *p;
        p++;
    }
    cksum = (cksum >> 16) + (cksum & 0xffff);
    cksum += (cksum >> 16);

    return (unsigned short)(~cksum);
}

int main()
{
    unsigned short csum = 0;

    csum = ipv6csum(pkt, sizeof(pkt));
    printf("pkt size: %d, icmpv6 checksum is: 0x%04x\n", (int)sizeof(pkt), csum);
    printf("icmpv6_hdr[2] = 0x%02x\n", csum & 0xff);
    printf("icmpv6_hdr[3] = 0x%02x\n", (csum & 0xff00) >> 8);

    return 0;
}
