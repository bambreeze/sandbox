#!/bin/env python3             
import os
root_dir = os.path.join(os.path.dirname(os.path.realpath(__file__)), './')

if __name__ == '__main__':
    with open(os.path.join(root_dir, 'sigleton.py'),'r+') as f:
        #lines = [l.rstrip('\s') for l in f.readlines()]
        lines = [l.rstrip() for l in f.readlines()]
    with open(os.path.join(root_dir, 'sigleton.py'),'w+') as f:
        #f.writelines(lines)
        f.write('\n'.join(lines))