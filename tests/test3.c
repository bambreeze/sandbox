
typedef struct BigData_ {
    int a[10];
} big_data_t;

typedef struct descriptor_ {
    big_data_t *ptr;
    char data[0];
} desc_t;

void main()
{
    printf("The length is: %d\n", sizeof(desc_t));
}
