#!/usr/bin/env python3

favorite_languages = {
    'jen':'python',
    'sarah':'c',
    'edward':'ruby',
    'phil':'python',
    }

# go through key-value
for name, language in favorite_languages.items():
    print(name.title() + "'s favorite language is " + language.title() + ".")
print()

# go through key
friends = ['phil', 'sarah']
for name in favorite_languages.keys():
    print(name.title())

    if name in friends:
        print(" Hi " + name.title() + ", I see your favorite language is " + favorite_languages[name].title() + "!")
print()

# sort the key
for name in sorted(favorite_languages.keys()):
    print(name.title() + ", thank you for taking the poll.")
print()

# go through value
print("The following languages have been mentioned:")
for language in set(favorite_languages.values()):
    print(language.title())
