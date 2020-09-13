#!/usr/bin/python
import time
import datetime

print("Now:")
print(datetime.datetime.now())

print("Today:")
print(datetime.date.today())

d = datetime.date.today()
print(d.isoformat())

today = datetime.date.fromtimestamp(time.time())
print(today)

someday = datetime.date(2018,1,1)
print(someday.strftime('%Y-%m-%d'))
print(someday.strftime('%Y/%m/%d'))
print(someday.isoformat())

print("datetime -> str")
now = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
print(now)

print("str -> datetime")
new = datetime.datetime.strptime("2015-07-17 16:58:46", "%Y-%m-%d %H:%M:%S")
print(new)

print("datetime compare")
strftime = datetime.datetime.strptime("2017-11-02", "%Y-%m-%d")
strftime2 = datetime.datetime.strptime("2017-01-04", "%Y-%m-%d")
if (strftime > strftime2):
    print("2017-11-02 bigger than 2017-01-04")

print("datetime compare2")
someday1 = datetime.date(2018,1,1)
someday2 = datetime.date(2019,1,1)
if (someday2 > someday1):
    print("someday2 bigger than someday1")

print("datetime +")
print(datetime.date.today())
print(datetime.date.today() + datetime.timedelta(days=100))
