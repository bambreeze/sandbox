#!/bin/env python3             
import os
myfile = os.path.join(os.path.dirname(os.path.realpath(__file__)), 'sigleton.py')

if __name__ == '__main__':
    lines = open(myfile, "r").readlines()
    lines = [l.rstrip() for l in lines]
    open(myfile, "w").write('\n'.join(lines))