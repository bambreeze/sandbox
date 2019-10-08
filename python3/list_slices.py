#!/usr/bin/env python3

# slices
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print("\nAll players: ", players)
print("Slice 0...3: ", players[0:3])
print("Slice the first 3 elements: ", players[:3])
print("Slice the last 3 elements: ", players[-3:])

players = ['charles', 'martina', 'michael', 'florence', 'eli']
print("\nHere are the first three players on my team:")
for player in players[:3]:
    print(player.title())

# list copy
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:]      # <===== it's correct

print("\nMy favorite foods are:")
print(my_foods)

print("\nMy friend favorite foods are:")
print(friend_foods)

my_foods.append('cannoli')
friend_foods.append('ice cream')

print("\nNew, My favorite foods are:")
print(my_foods)

print("\nNew, My friend favorite foods are:")
print(friend_foods)

# WARNING: IT'S WRONG!
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods         # <===== it's wrong

my_foods.append('cannoli')
friend_foods.append('ice cream')

print("\nBad example, my favorite foods are:")
print(my_foods)

print("\nBad example, my friend favorite foods are:")
print(friend_foods)

