#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define uint8 unsigned char
#define uint32 unsigned int

static unsigned char bcd_decimal (unsigned char bcd)
{
    return bcd - (bcd >> 4) * 6;
}

static unsigned char decimal_bcd (unsigned char decimal)
{
    return (unsigned char) (decimal + (decimal / 10) * 6);
}

static uint32 tod_is_equal (uint32 tod1, uint32 tod2)
{
    uint8 dys1 = 0, hrs1 = 0, min1 = 0, sec1 = 0;
    uint8 dys2 = 0, hrs2 = 0, min2 = 0, sec2 = 0;
    uint32 to_sec1 = 0, to_sec2 = 0;

    dys1 = (tod1 >> 24) & 0xff;
    hrs1 = (tod1 >> 16) & 0xff;
    min1 = (tod1 >> 8) & 0xff;
    sec1 = tod1 & 0xff;
    to_sec1 = bcd_decimal(sec1) + bcd_decimal(min1)*60 + bcd_decimal(hrs1)*3600 + bcd_decimal(dys1)*3600*24;
    printf("to_sec1: 0x%x\n", to_sec1);

    dys2 = (tod2 >> 24) & 0xff;
    hrs2 = (tod2 >> 16) & 0xff;
    min2 = (tod2 >> 8) & 0xff;
    sec2 = tod2 & 0xff;
    to_sec2 = bcd_decimal(sec2) + bcd_decimal(min2)*60 + bcd_decimal(hrs2)*3600 + bcd_decimal(dys2)*3600*24;
    printf("to_sec2: 0x%x\n", to_sec2);

    if ((to_sec1 == to_sec2) || (to_sec1 + 1 == to_sec2) || (to_sec1 == to_sec2 + 1)) {
        return 1;
    }

    return 0;
}


int main (void)
{
    uint32 tod1 = 0, tod2 = 0;

    printf("0x52 ---> %d\n", bcd_decimal(0x52));

    tod1 = 0x59;
    tod2 = 0x100;
    printf("tod1:0x%x, tod2:0x%x ---> %d\n",
            tod1, tod2, tod_is_equal(tod1, tod2));

    return 0;
}
