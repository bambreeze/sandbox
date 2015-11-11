#!/usr/bin/python

def fib(n):
    a, b = 0, 1
    result = ""
    while a < n:
        #print(a, end=' ')
        result = result + str(a) + " "
        a, b = b, a+b
    print(result)

fib(1000)
