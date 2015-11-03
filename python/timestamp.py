#!/usr/bin/python
# -*- coding: UTF-8 -*-
import time

print time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))

# sleep one second
time.sleep(1)

print time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))
