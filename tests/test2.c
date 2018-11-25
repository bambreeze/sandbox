
static int a = 1;

int f()
{
    static int a = 1;
    return (a++);
}

int main()
{
    printf("%d %d %d %d\n", f(), a, f(), a);

    return (0);
}
