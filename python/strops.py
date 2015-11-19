#!/usr/bin/python

import os, sys, string, time

mystr1 = 'abc'
mystr2 = 'abc.def'
mystr3 = 'abc.def.ghi'

if mystr1.find('.'):
    print "not find ."
    
idx = mystr2.index('.')
print idx

idx = mystr3.index('.')
print idx

sStr1 = 'abcdefg'
sStr1 = sStr1[::-1]
print sStr1
