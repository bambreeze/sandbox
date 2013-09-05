#!/usr/bin/tclsh

puts "hello world!"

# The below commets is wrong
set a "aaa"; # error for aaa
puts $a
set a aaa; # error " 

if {![info exist abc]} {
    error "variable abc is not set" 
}

