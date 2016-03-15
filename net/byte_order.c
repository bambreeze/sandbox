/*
htonl(3) - Linux man page
Name
htonl, htons, ntohl, ntohs - convert values between host and network byte order
Synopsis

#include <arpa/inet.h>
uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);

Description
The htonl() function converts the unsigned integer hostlong from host byte order to network byte order.

The htons() function converts the unsigned short integer hostshort from host byte order to network byte order.

The ntohl() function converts the unsigned integer netlong from network byte order to host byte order.

The ntohs() function converts the unsigned short integer netshort from network byte order to host byte order.

On the i386 the host byte order is Least Significant Byte first, whereas the network byte order, as used on the Internet, is Most Significant Byte first.
Conforming to
POSIX.1-2001.

Some systems require the inclusion of <netinet/in.h> instead of <arpa/inet.h>.
See Also
endian(3), gethostbyname(3), getservent(3)
Referenced By
pmdacachestorekey(3) 
 */
#include <stdio.h>
#include <arpa/inet.h>

main()
{
    int i = 0;
    unsigned int val = 0x12345678;
    unsigned int val2 = 0;
    unsigned char *pval = NULL;

    val2 = htonl(val);
    printf("val: 0x%08x, val2: 0x%08x\n", val, val2);

    printf("host byte order:\n");
    pval = (unsigned char *) &val;
    for (i = 0; i < 4; i++) {
        printf("%02x ", *pval++);
    }
    printf("\n");

    printf("network byte order:\n");
    pval = (unsigned char *) &val2;
    for (i = 0; i < 4; i++) {
        printf("%02x ", *pval++);
    }
    printf("\n");
}
