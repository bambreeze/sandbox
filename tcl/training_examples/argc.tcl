#!/bin/sh
# \
exec /usr/bin/tclsh "$0" ${1+"$@"}

if {$argc != 3} { puts "the number of parameter should be 3"}
puts "argv: $argv"

