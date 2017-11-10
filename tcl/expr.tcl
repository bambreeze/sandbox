#!/usr/bin/tclsh

puts "Hello, World\r"

for {set i 1} {$i < 10 + 1} {incr i} {
    set need_power_cycle [expr ![expr ($i - 1) % 3]]
    puts $need_power_cycle
    if { $need_power_cycle } {
        puts "need power cycle"
    }
}

