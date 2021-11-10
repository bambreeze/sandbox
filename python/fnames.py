#! /usr/bin/python
import os

cur_dir = os.path.abspath(os.path.dirname(__file__))
flist = os.listdir(cur_dir)
n=0
for name in flist:
    new = name.replace("xxx", "")
    #oldname="./"+ os.sep + flist[n]
    #newname=path + os.sep +'a'+str(n+1)+'.JPG'
    os.rename(name, new)
    #print(oldname,'======>',newname)
    #n+=1
