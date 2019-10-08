#!/usr/bin/env python3

motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

motorcycles[0] = 'ducati'
print(motorcycles)

motorcycles.append('ducati')
print(motorcycles)

new_motor = []
new_motor.append('honda')
new_motor.append('yamaha')
new_motor.append('suzuki')
print(new_motor)

new_motor.insert(0, 'ducati')
print(new_motor)

del new_motor[0]
print(new_motor)

del new_motor[1]
print(new_motor)

popped_motorcycle = new_motor.pop()
print(new_motor)
print(popped_motorcycle)

motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)
last_owned = motorcycles.pop()
print("The last motorcycle I owned was a " + last_owned.title() + ".")
print(motorcycles)
print()

motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)
first_owned = motorcycles.pop(0)
print("The first motorcycle I owned was a " + first_owned.title() + ".")
print(motorcycles)
print()

motorcycles = ['honda', 'yamaha', 'suzuki', 'ducati']
print(motorcycles)
motorcycles.remove('ducati')
print(motorcycles)
print()

