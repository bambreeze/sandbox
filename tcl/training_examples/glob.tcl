#!/usr/bin/tclsh

set command version
#Execute the specified command  
switch -regexp $command {
    {aaa} {
        puts "This is an echo command" 
    }
    {bbb} -
    {v.*} { 
        puts version=[info tclversion]
    }
    default {
        puts "Invalid command: $command" 
    }
}
switch -glob $command {
    {aaa} {
        puts "This is an echo command" 
    }
    {v*} { 
        puts version=[info tclversion]
    }
    default {
        puts "Invalid command: $command" 
    }
}
