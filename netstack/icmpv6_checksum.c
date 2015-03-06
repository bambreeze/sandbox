# include "stdio.h"

// 
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

unsigned char packet_buffer[] = {
    //icmp header
    0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x75, 0xc5, 0xf1, 0x20, 0x80, 0x97, 0x0e, 0x39,

    // pseudo header
    // source addr
    0x20, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    // dest addr
    0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0xff, 0x97, 0x0e, 0x39,
    // payload len
    0x00, 0x00, 0x00, 0x18,
    // next header
    0x00, 0x00, 0x00, 0x3a
};

unsigned char bf[] = {
    //icmp header
    0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x75, 0xc5, 0xf1, 0x20, 0x80, 0x97, 0x0e, 0x39,
    // pseudo header
    // src addr
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // dst addr
    0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0xff, 0x97, 0x0e, 0x39,
    // payload length
    0x00, 0x00, 0x00, 0x18,
    0x00, 0x00, 0x00, 0x3a
};

unsigned short checksum(int len, unsigned char *buffer)
{
    unsigned long cksum = 0;
    unsigned short *p = (unsigned short*)buffer;
    int size = (len >> 1) + (len & 0x1);

    while (size > 0) {
        cksum += *p;
        p++;
        size--;
    }
    cksum = (cksum >> 16) + (cksum & 0xffff);
    cksum += (cksum >> 16);

    return (unsigned short) (~cksum);
}

int main()
{
    unsigned char data[2048];
    unsigned short csum = 0;
    int len = 0;

    len = sizeof(packet_buffer);
    printf("pkt len: %d\n", len);

    memset(data, 2048, 0);
    memcpy(data, packet_buffer, len);

    csum = checksum(len,data);
    printf("icmpv6 checksum is: 0x%04x\n", csum);

    return 0;
}
