#! /usr/bin/python
import re

with open('rmch.txt', 'r') as f:
    messages = f.readlines()

i = 0
for msg in messages:
    i = i+1
    print(i, msg)
    for char in msg:
        ascii_value = ord(char)
        print(char, ascii_value)
    print('--------')

    pattern3 = re.compile('\b')
    if pattern3.findall(msg):
        print('line', i)
        print('yes' + msg)
        print('before')
        for char in msg:
            ascii_value = ord(char)
            print(char, ascii_value)
        #msg = re.sub(r'\b', 'aaa', msg)
        msg = re.sub(r'\x08', '', msg)
        #msg.replace('^H', 'aaa')
        print('after')
        for char in msg:
            ascii_value = ord(char)
            print(char, ascii_value)
        print('yes' + msg)

#s = "This is a string with\b some\b\b special characters\b."
#s = re.sub(r'\b', '', s)
#print(s)
