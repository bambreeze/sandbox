#!/usr/bin/python
import random
import sys
import string
import os

page    = 5         # pages
q_num   = 100       # questions number per pages
max_num = 20        # range

def get_num (min, max):
    if min>=max:
        return min
    return random.randrange(min, max)

def get_q (i, maxnum):
    a = get_num(1,maxnum)
    b = get_num(1,maxnum)
    sig=random.randrange(1,101) % 2
    
    if sig==0:
        fp0.write("(%2d) %2d + %2d = ____" %(i,a,b))
    elif sig==1:
        c=max(a,b)
        b=min(a,b)
        a=c             #if a<b, swap a, b to elimination minus numbers
        fp0.write("(%2d) %2d - %2d = ____" %(i,a,b))

    if i % 2 == 0:
        fp0.write("\n")
    else:
        fp0.write("       ")

def get_q2 (i, maxnum):
    a = get_num(1,maxnum)
    b = get_num(1,maxnum)
    c = get_num(1,maxnum)
    sig=random.randrange(1,101) % 4 # 0:++ 1:+- 2:-+ 3:--
    
    if sig==0:
        fp0.write("(%2d) %2d + %2d + %2d = ____" %(i,a,b,c))
    elif sig==1:
        if a + b < c:
            x = b
            b = c
            c = b
        fp0.write("(%2d) %2d + %2d - %2d = ____" %(i,a,b,c))
    elif sig==2:
        if a < b:
            x = a
            a = b
            b = a
        fp0.write("(%2d) %2d - %2d + %2d = ____" %(i,a,b,c))
    else:
        x = max(a, b)
        y = max(x, c) # max
        x = min(a, b)
        z = min(x, c) # min

        a = y
        b = z
        c = random.randrange(0, a - b)
        fp0.write("(%2d) %2d - %2d - %2d = ____" %(i,a,b,c))

    if (i % 2 == 0) and (i != q_num):
        fp0.write("\n")
    else:
        fp0.write("  ")
#elif not ((a >=10 and b >=10) or (a >=10 and c >=10) or (b >=10 and c >=10)):
#        fp0.write("\t")

def gen_test(maxnum, times):
    for i in range(1, (times+1), 1):  #times is not included, so + 1
        if i <= times/2:
            get_q(i, maxnum)   
        else:
            get_q2(i, maxnum)   

fp0 = open("test.txt", 'w')
#fp0.write( "Date:__/__    Time:___:___ - ___:___\n\n")
for i in range(1, (page+1), 1):
    gen_test(max_num, q_num)
    if i != page:
        fp0.write("\n")
else:
    print "Done"
fp0.close
