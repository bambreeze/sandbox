#!/usr/bin/env python3

cars = ['bmw', 'audi', 'toyota', 'subaru']
cars.sort()
print(cars)
print()

cars = ['bmw', 'audi', 'toyota', 'subaru']
cars.sort(reverse=True)
print(cars)
print()

cars = ['bmw', 'audi', 'toyota', 'subaru']
print("Here is the original list:")
print(cars)

print("\nHere is the sorted list:")
print(sorted(cars))

print("\nHere is the original list:")
print(cars)

print("\nHere is the new sorted list:")
new_cars = sorted(cars)
print(new_cars)
print()

# reverse
cars = ['bmw', 'audi', 'toyota', 'subaru']
print("Original: ", cars)
cars.reverse()
print("Reversed: ", cars)

#length
cars = ['bmw', 'audi', 'toyota', 'subaru']
lens = len(cars)
print("Length: ", lens)
