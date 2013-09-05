#!/usr/bin/tclsh

proc test {first args} {
    puts "First: $first; ARGS: $args"
}

#test 
test 1
test 2 3 4
test 5 6 7 8

