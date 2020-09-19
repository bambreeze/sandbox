#!/usr/bin/env python3

# equal
cars = ['bmw', 'audi', 'toyota', 'subaru']
print(cars)

for car in cars:
    if car == 'bmw':
        print(car.upper())
    else:
        print(car.title())


# contained in the list
banned_users = ['andrew', 'carolina', 'david']

user = 'andrew'
if user in banned_users:
    print(user.title() + ", you can not post it!")

user = 'marie'
if user not in banned_users:
    print(user.title() + ", you can post a response if you wish.")
