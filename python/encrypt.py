#!/usr/bin/python

import os, sys, string, time

def encrypt_xor2(data, key):
    buff = ""
    for i in range(0, len(data)):
        buff += chr(ord(data[i]) ^ ord(key[i % len(key)]))
    return buff

fname = sys.argv[1]
pw = sys.argv[2]

if fname.find('.') == -1:
    fname2 = fname
else:
    fname2 = fname[:fname.find('.')]
fname2 = fname2[::-1]

print time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))
infile  = open(fname, "rb")
outfile = open(fname2, "wb")

while 1:
    line = infile.read(256)
    if len(line) == 0:
        break;

    line2 = encrypt_xor2(line, pw)
    outfile.write(line2)

infile.close()
outfile.close()

#os.remove(fname)
print time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))
