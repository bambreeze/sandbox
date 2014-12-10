/* C header file to Binary file converter */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    FILE *in, *out;
    unsigned int data;

    if (argc < 3) {
        printf("bin2hex <h file> <bin file>\n");
        return (1);
    }

    if ((in = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s\n", argv[1]);
        return (1);
    }

    if ((out = fopen(argv[2], "wb")) == NULL) {
        printf("Unable to open %s\n", argv[2]);
        fclose(in);
        return (1);
    }

    while (fscanf(in, "%x", &data) != EOF) {
        fwrite(&data, 1, 1, out);
    }

    fclose(in);
    fclose(out);
    return 0;
}
