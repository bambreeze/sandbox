#!/usr/bin/tclsh

puts "Example1"
foreach var " a1 b2 c3 " { 
    puts var=$var 
}
puts "Example2"
foreach {v1 v2 v3} {1 2 3 4 5} {
   puts v1=$v1
   puts v2=$v2
   puts v3=$v3
} 
puts "Example3"
foreach v3 "d1 d2 " v4 "e3 e4"  {
   puts v3=$v3
   puts v4=$v4
}

