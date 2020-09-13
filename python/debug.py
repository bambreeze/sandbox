#!/usr/bin/env python3
import sys

def get_num (min, max):
    print("[debug](%s, %s(), %d)" % (sys._getframe().f_code.co_filename, sys._getframe().f_code.co_name, sys._getframe().f_lineno))
    min = 10
    if min>=max:
        return min
    return random.randrange(min, max)

print("[debug](%s, %s(), %d)" % (sys._getframe().f_code.co_filename, sys._getframe().f_code.co_name, sys._getframe().f_lineno))
a = get_num(1,5)
print(a)
