#!/usr/bin/env python3

# input the height
height = input("How tall are you, in inches? ")
height = int(height)

if height > 36:
    print("\nYou're tall enough to ride!")
else:
    print("\nYou'll be able to ride when you're a little older.")
print("\n")

# input the number
number = input("Enter a number, and I'll tell you if it's even or odd: ")
number = int(number)

if number % 2 == 0:
    print("\nThe number " + str(number) + " is even.")
else:
    print("\nThe number " + str(number) + " is odd.")

# input or quit
prompt = "\nTell me something, and I will repeat it back to you:"
prompt += "\nEnter 'quit' to end the program."

# methold-1
message = ""
while message != 'quit':
    message = input(prompt)

    if message != 'quit':
        print(message)

# methold-2
active = True
while active:
    message = input(prompt)
    if message == 'quit':
        active = False
    else:
        print(message)
