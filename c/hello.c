#include <linux/module.h>
#include <linux/init.h>

#define my_container_of(ptr, type, member) ({ \
(type *)( (char *)ptr - offsetof(type,member) );})

#define container_of(ptr, type, member) ({          \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offsetof(type,member) );})

struct city {
    int size;
    int history;
};

struct school {
    int index;
    int addr;
};

struct student {
    int id;
    char *name;
    struct school sc;
};

struct city mycity;
struct school myschool;
struct student mystudent;
struct student *stu;

static int __init hello_init(void)
{
    printk(KERN_ALERT "hello, Git on Ubuntu Maverick ;-)\n");
   
    mycity.size = 100;
    mycity.history = 200;

    myschool.index = 565;
    myschool.addr  = 888;

    mystudent.id   = 6;
    mystudent.name = "Jack";
    mystudent.sc.index = 12;
    mystudent.sc.addr  = 16;

    //stu = my_container_of(&mycity, struct student, sc);
    //stu = my_container_of(&(mystudent.sc), struct student, sc);

    //stu = container_of(&mycity, struct student, sc);
    stu = container_of(&(mystudent.sc), struct student, sc);
    printk(KERN_ALERT "  mystudent: 0x%x\n", (uint32_t)&mystudent);
    printk(KERN_ALERT "  stu: 0x%x\n", (uint32_t)stu);

    printk(KERN_ALERT "  mystudent.name: %s\n", mystudent.name);
    printk(KERN_ALERT "  stu->name: %s\n", stu->name);

    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_ALERT "Bye, Git!\n");
}

module_init(hello_init)
module_exit(hello_exit)

MODULE_LICENSE("Dual BSD/GPL");
