#!/usr/bin/python
import random
import sys
import string
import os

def get_num (min, max):
    if min>=max:
        return min
    return random.randrange(min, max)

def get_sig ():
    sig=random.randrange(1,101) % 4
    return sig
 
def get_q (i, sig, maxnum):
    a=get_num(1,maxnum)
    #print a
    b=get_num(1,maxnum)
    #print b
    
    if sig==0:
        print "%d)   %d + %d = ____" %(i,a,b)
        fp0.write("(%d) %d + %d = ____\t\t" %(i,a,b))
        print "     %d + %d = %d" %(a,b, a+b)
        fp1.write( "(%d) %d + %d = %d\t\t" %(i,a,b, a+b))
    elif sig==1:
        c=max(a,b)
        b=min(a,b)
        a=c             #if a<b, swap a, b to elimination minus numbers
        print "%d)   %d - %d = ____" %(i,a,b)
        fp0.write("(%d) %d - %d = ____\t\t" %(i,a,b))
        print "     %d - %d = %d" %(a,b, a-b)
        fp1.write( "(%d) %d - %d = %d\t\t" %(i,a,b, a-b))
    elif sig==2:
        print "%d)   %d x %d = ____" %(i,a,b)
        fp0.write("(%d) %d x %d = ____\t\t" %(i,a,b))
        print "     %d x %d = %d" %(a,b, a*b)
        fp1.write( "(%d) %d x %d = %d\t\t" %(i,a,b, a*b))
    elif sig==3:
        while (a<b or b==0):
            b=get_num(1,a)
        print "%d)   %d / %d = ____  %% ____" %(i,a,b)
        fp0.write("(%d) %d / %d = ____ %% ____\t\t" %(i,a,b))
        print "     %d / %d = %d %%%d" %(a,b, a/b, a%b)
        fp1.write( "(%d) %d / %d = %d  %%%d\t\t" %(i,a,b, a/b, a%b))  
    else:
        print "sign is wrong!"
    if i%2==0:
        fp0.write("\n")
        fp1.write("\n")

def gen_test(maxnum, times):
        
    for i in range(1, (times+1), 1):  #times is not included, so + 1
        print "*************"
        #print i
        sig = get_sig()
        while ((1 << sig) & sign_mask) == 0:
            sig= get_sig()
        else:
            #print sig
            get_q(i, sig,maxnum)   
    else:
        print "Test Generation is Over"

def showhelp():
    print "\n================================\n"
    print " PUPIL MATHS TEST GENERATION v1.0 \n"
    print "==================================\n"
    print "usage:\n"
    print "python.exe pupil_maths.py <Arg1> <Arg2> <Arg3>\n"
    print "Arg1: max number of test range\n"
    print "Arg2: question number\n"
    print "Arg3: Sign mask: 1 for +, 2 for -, 4 for * and 8 for /\n"
    
if len(sys.argv) < 3:
    showhelp()
    exit()
    
if string.atoi(sys.argv[1]) < 10:
    print "test range too small"
elif string.atoi(sys.argv[2]) < 1:
    print "question number too small"
elif string.atoi(sys.argv[3]) < 1 or string.atoi(sys.argv[3]) > 15:
    print "sig mask invalid %d" % (string.atoi(sys.argv[3]))

else :
    max_num = string.atoi(sys.argv[1])
    q_num   = string.atoi(sys.argv[2])
    sign_mask = string.atoi(sys.argv[3])                            
    print "Test range %d %d" % (1, max_num)
    print "Question number %d " % q_num
    plus    = string.atoi(sys.argv[3]) & 0x1
    minus   = string.atoi(sys.argv[3]) & 0x2
    multiply= string.atoi(sys.argv[3]) & 0x4
    divide  = string.atoi(sys.argv[3]) & 0x8
    print "Sig mask =0x%x %x %x %x %x" %(sign_mask, plus!=0, minus!=0, multiply!=0, divide!=0)
    fp0 = open("test.txt", 'w')
    fp0.write( "Name: __________ Score:_____ Date:__/__\n\n")
    fp0.write( "Time:___:___ - ___:___ \n --------------------------------\n\n")
    fp1 = open("ans.txt", 'w')
    fp1.write( " ANSWER PAGE: \n\n")
    gen_test(max_num, q_num)
    fp0.close
    fp1.close