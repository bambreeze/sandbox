#!/usr/bin/python
# generate rquest simulation

import os, sys

v4add = "pkill -3 reqq"
v4del = "pkill -4 reqq"
v6add = "pkill -5 reqq"
v6del = "pkill -6 reqq"

for i in range(0, 5):
    os.system(v4add)
    os.system(v4del)
    os.system(v6add)
    os.system(v6del)
