#!/usr/bin/python
import random
import sys
import string
import os
import time

def get_num (min, max):
    min = 10
    if min>=max:
        return min
    return random.randrange(min, max)

def get_test1 (i, maxnum):
    a = get_num(1,maxnum)
    b = get_num(1,maxnum)
    sig=random.randrange(1,101) % 2 # 0:+ 1:-
    
    if sig==0:
        fp0.write("%2d + %2d =" %(a,b))
    elif sig==1:
        c=max(a,b)
        b=min(a,b)
        a=c             #if a<b, swap a, b to elimination minus numbers
        fp0.write("%2d - %2d =" %(a,b))

    if i % 2 == 0:
        fp0.write("\n\n")
    else:
        fp0.write("\t\t")

def get_test2 (i, maxnum):
    a = get_num(1,maxnum)
    b = get_num(1,maxnum)
    c = get_num(1,maxnum)
    sig=random.randrange(1,101) % 4 # 0:++ 1:+- 2:-+ 3:--
    
    if sig==0:
        fp0.write("%2d + %2d + %2d =" %(a,b,c))
    elif sig==1:
        if a + b < c:
            x = b
            b = c
            c = b
        fp0.write("%2d + %2d - %2d =" %(a,b,c))
    elif sig==2:
        if a < b:
            x = a
            a = b
            b = a
        fp0.write("%2d - %2d + %2d =" %(a,b,c))
    else:
        x = max(a, b)
        y = max(x, c) # max
        x = min(a, b)
        z = min(x, c) # min

        a = y
        b = z
        if (a == b):
            if (a == 1):
                a = random.randrange(2, maxnum)
            else:
                b = random.randrange(1, a)
        c = random.randrange(0, a - b)
        fp0.write("%2d - %2d - %2d =" %(a,b,c))

    if i % 2 == 0:
        fp0.write("\n\n")
    else:
        fp0.write("\t\t")

def get_test3 (i, maxnum):
    a = get_num(1,maxnum)
    b = get_num(1,maxnum)
    sig=random.randrange(1,101) % 4
    
    c=max(a,b)
    b=min(a,b)
    a=c             #if a<b, swap a, b to elimination minus numbers

    if b > 10:
        b = b - 10

    if sig==0:
        if a - b > 10:
            a = a - 10
        fp0.write("%2d + (  ) = %2d" %(b,a))
    elif sig==1:
        if a - b > 10:
            a = a - 10
        fp0.write("(  ) + %2d = %2d" %(b,a))
    elif sig==2:
        if a - b > 10:
            a = a - 10
        fp0.write("%2d - (  ) = %2d" %(a,b))
    elif sig==3:
        if a > 10:
            a = a - 10
        fp0.write("(  ) - %2d = %2d" %(a,b))

    if i % 2 == 0:
        fp0.write("\n\n")
    else:
        fp0.write("\t\t")

def showhelp():
    print "\n================================\n"
    print " PUPIL MATHS TEST GENERATION v1.2 \n"
    print "==================================\n"
    print "usage:\n"
    print "./maths.py <Arg1> <Arg2> <Arg3>\n"
    print "  Arg1: max number of test range\n"
    print "  Arg2: pages\n"
    print "  Arg3: type: 1 for +/-, 2 for ++, 3 for (), 4 for random\n"
    print "exmple:\n"
    print "./maths.py 50 5 4\n"
    
if len(sys.argv) < 3:
    showhelp()
    exit()
    
if string.atoi(sys.argv[1]) < 10:
    print "test range too small"
elif string.atoi(sys.argv[2]) < 1:
    print "page number too small"
elif string.atoi(sys.argv[3]) < 1 or string.atoi(sys.argv[3]) > 15:
    print "type invalid %d" % (string.atoi(sys.argv[3]))
else :
    max_num = string.atoi(sys.argv[1])
    page    = string.atoi(sys.argv[2])
    maths_type = string.atoi(sys.argv[3])                            

    fp0 = open("tmp.txt", 'w')
    for i in range(1, (page+1), 1):
        fp0.write( "Date: __ / __    Time: __ : __  -  __ :__\n\n")

        times = 30 # questions numbers/page
        for j in range(1, (times+1), 1):  #times is not included, so + 1
            if maths_type == 1:
                get_test1(j, max_num)   
            elif maths_type == 2:
                get_test2(j, max_num)   
            elif maths_type == 3:
                get_test3(j, max_num)   
            elif maths_type == 4:
                maths_type2 = random.randrange(1,4)
                if maths_type2 == 1:
                    get_test1(j, max_num)   
                elif maths_type2 == 2:
                    get_test2(j, max_num)   
                elif maths_type2 == 3:
                    get_test3(j, max_num)   

    else:
        print "Done"
    fp0.close()

    fp1 = open("tmp.txt") # delete the last line
    lines = fp1.readlines()
    fp2 = open("test.txt",'w')
    fp2.writelines([item for item in lines[:-1]])
    fp1.close()
    fp2.close()
    os.remove("tmp.txt")
