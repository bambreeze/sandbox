#!/usr/bin/python

import os, sys, string

def encrypt_xor2(data, key):
    buff = ""
    for i in range(0, len(data)):
        buff += chr(ord(data[i]) ^ ord(key[i % len(key)]))
    return buff

fname = sys.argv[1]
pw = sys.argv[2]
fname2 = sys.argv[1] + '.cpt'

infile  = open(fname, "rb")
outfile = open(fname2, "wb")

while 1:
    line = infile.read(256)
    if len(line) == 0:
        break;

    line2 = encrypt_xor2(line, pw)
    #print line2
    outfile.write(line2)

infile.close()
outfile.close()

#os.remove(fname)
