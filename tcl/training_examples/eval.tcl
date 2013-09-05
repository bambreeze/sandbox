#!/usr/bin/tclsh

set cmd {puts "this is for eval"; puts "it is second line"; puts "last line"}
eval $cmd

puts "----"
#set cmd "ls "; error for the blank 
set cmd "ls -l"
eval exec $cmd >@ stdout
set cmd "ls"
exec $cmd "-a" >@ stdout
