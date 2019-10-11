#!/usr/bin/env python3

def greet_user(username):
    print("Hello, " + username.title() + "!")
greet_user('Jean')

def describe_pet(pet_name, animal_type='dog'):
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")
describe_pet(pet_name='harry', animal_type='hamster')
describe_pet(animal_type='hamster', pet_name='harry')
describe_pet('harry', 'hamster')

describe_pet('willie')
describe_pet(pet_name='willie')

def build_person(first_name, last_name):
    person = {'first':first_name, 'last':last_name}
    return person

musician = build_person('jimi', 'hendrix')
print(musician)
