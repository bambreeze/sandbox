
int main ()
{
    int x = 1;
    if (x = ((x + 1) << 2))
        printf("hello\n");
    else
        printf("world\n");

    unsigned char a = 0xff;
    a++;
    printf("0x%d\n", a);

    return 0;
}
