#!/usr/bin/env python3

filename = 'pi_digits.txt'

# method-1
with open(filename) as file_object:
    contents = file_object.read()
    print(contents.rstrip())
print()

# method-2
with open(filename) as file_object:
    lines = file_object.readlines()

for line in lines:
    print(line.rstrip())
print()

# pi string
with open(filename) as file_object:
    lines = file_object.readlines()

pi_string = ''
for line in lines:
    pi_string += line.strip()

print(pi_string[:20] + "...")
print(len(pi_string))

birthday = input("Enter your birthday, in the form mmddyy: ")
if birthday in pi_string:
    print("Your birthday appears in the first million digits of pi!")
else:
    print("Your birthday does not appear in the first million digits of pi.")
