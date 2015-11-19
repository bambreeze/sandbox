#!/usr/bin/python

import os, sys, string

fname = sys.argv[1]
fname2 = sys.argv[1] + '.hex'

infile = file(fname, "rb")
outfile = file(fname2, "wb")

counter = 0;
while 1:
    c = infile.read(1)
    if not c:
        break
    #outfile.write("%02s" % hex(ord(c)))
    if ord(c) <= 15:
        outfile.write(("0x0"+hex(ord(c))[2:])[2:])
    else:
        outfile.write((hex(ord(c)))[2:])

    counter += 1
    if counter % 16 == 0:
        outfile.write("\n")
    else:
        outfile.write(" ")

outfile.close()
infile.close()
