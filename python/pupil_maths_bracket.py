#!/usr/bin/python
import random
import sys
import string
import os

page    = 5         # pages
q_num   = 60        # questions number per pages
max_num = 20        # range

def get_num (min, max):
    if min>=max:
        return min
    return random.randrange(min, max)

def get_q (i, maxnum):
    a = get_num(1,maxnum)
    b = get_num(1,maxnum)
    sig=random.randrange(1,101) % 4
    
    c=max(a,b)
    b=min(a,b)
    a=c             #if a<b, swap a, b to elimination minus numbers

    if b > 10:
        b = b - 10

    if sig==0:
        fp0.write("(%2d) %d + ___ = %d" %(i,b,a))
    elif sig==1:
        fp0.write("(%2d) ___ + %d = %d" %(i,b,a))
    elif sig==2:
        fp0.write("(%2d) %d - ___ = %d" %(i,a,b))
    elif sig==3:
        if a > 10:
            a = a - 10
        fp0.write("(%2d) ___ - %d = %d" %(i,a,b))

    if i % 2 == 0:
        fp0.write("\n")
    else:
        fp0.write(" ")

def gen_test(maxnum, times):
    for i in range(1, (times+1), 1):  #times is not included, so + 1
            get_q(i, maxnum)   

fp0 = open("test.txt", 'w')
for i in range(1, (page+1), 1):
    fp0.write( "Date:__/__    Time:___:___ - ___:___\n\n")
    gen_test(max_num, q_num)
#    if i != page:
#        fp0.write("\n")
else:
    print "Done"
fp0.close
