#define numDesc 100

typedef struct {
    int flags;
    int state;
    int status;
} myDesc_t;

void main (void)
{
    myDesc_t descArray[numDesc], *desc;
    int ii;

    for (ii = 0; ii < numDesc; ii++) {
        descArray[ii].flags = 0x80000000 + ii;
        descArray[ii].state = 0;
        descArray[ii].status = 0;
    }

    desc = descArray;
    for (ii = 0; ii < 4; ii++) {
        printf("0x%04x ", desc->flags & 0xffff);
        desc += ii;
    }
}
