#!/usr/bin/python
# generate command simulation

import os, sys

cmd = "pkill -1 cmdq"

for i in range(0, 10):
    os.system(cmd)
