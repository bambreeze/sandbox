#!/usr/bin/tclsh

set x 0

proc print2 {} {
    set x 100
    print3 x
    puts "x in print2: $x"
}
proc print3 {var} {
    # #? for the absoluted path function
    # 0/1/2/3/4/5/6/7 for the uplevel function
    upvar 2 x v
    incr v 
    puts "var: $var, v:$v"
}

print2 
puts "x in global: $x"
