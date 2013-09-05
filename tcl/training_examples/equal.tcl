#!/usr/bin/tclsh

set str {"123" == " 123"}
puts "The result of $str is: [expr $str]"

set str {"123" == " 123.0"}
puts "The result of $str is: [expr $str]"

set str {"123.a" == " 123.a"}
puts "The result of $str is: [expr $str]"

set str {"123" eq " 123"}
puts "The result of $str is: [expr $str]"
