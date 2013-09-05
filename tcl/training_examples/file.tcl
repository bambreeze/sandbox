#!/usr/bin/tclsh

# Open a file for reading 
if {[catch {set fd [open demo.txt r]} errmsg]} {
    puts " Unable to open file  $errmsg" 
    return
} 

# Display the contents of the file 
while {[gets $fd string] != -1} {
    append string_all $string\n
    puts $string 
} 

# Process any errors that occurred during the read 
if {![eof $fd]} {
    error "Error occurred while reading demo" 
} 
close $fd 

