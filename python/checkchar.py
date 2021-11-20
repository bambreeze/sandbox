#! /usr/bin/python
# -*- coding:utf-8 -*-
import os, sys, re

flist=[]
cur_dir = os.path.abspath(os.path.dirname(__file__))
for d in os.listdir(cur_dir):
    if d != os.path.basename(__file__):
        sub = cur_dir + '/' + d
        #print(sub)
        for name in os.listdir(sub):
            #print(name)
            flist.append(sub + '/' + name)
#print(flist)
#flist = ["./latest/serdes_db/metaluna/metaluna_88x7120_hostside.csv"]
#illegal_chars = "，"
for file in flist:
    with open(file, 'r') as f:
        print(file)
        lines = f.readlines()
        num = 1
        for line in lines:
            #print(line)
            #for ch in illegal_chars:
            #    if ch in line:
            #        print("Please check line %d ... found illegal character '%c'" % (num, ch))
            #        exit()
            for ch in line:
                if ord(ch) > 126:
                    print("Please check line %d ... found full-width character '%c'" % (num, ch))
                    exit()
            if not re.search('^[#"]', line):
                if not re.search('^[-0-9a-zA-Z_,.:() ]{1,}$', line):
                    for ch in line:
                        if not re.search("^[-0-9a-zA-Z_,.:()]{1,}$", ch):
                            print("Please check line %d ... found illegal character '%c'" % (num, ch))
                            exit()
            num += 1