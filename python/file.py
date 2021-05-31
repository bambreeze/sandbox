#! /usr/bin/python
try:
  fsock = open("./input_data.txt")
except IOError:
  print "The file dose not exits..."
else:
  print "open the file."
print "this line will always print"
