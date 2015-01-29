#!/usr/bin/python

import sys, os, string

if len(sys.argv) == 1:
    filenames = os.listdir(os.curdir)
else:
    filenames = sys.argv[1:]

for filename in filenames:
    print filename
