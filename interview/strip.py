#!/bin/env python3             
import os
myfile = os.path.join(os.path.dirname(os.path.realpath(__file__)), 'sigleton.py')

if __name__ == '__main__':
    lines = []
    with open(myfile,'r+') as f:
        for l in f.readlines():
            l = l.rstrip()
            lines.append(l+'\n')
    with open(myfile,'w+') as f:
        f.writelines(lines)