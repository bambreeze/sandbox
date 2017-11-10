#!/usr/bin/tclsh

set skip_timing_sys {test1 test2 test3}

proc skip_tests {type} {
    global diag_prompt
    global skip_timing_sys

    if {$type == "sys"} {
      foreach test $skip_timing_sys {
          puts "skip $test"
          after 1
      }
    } elseif {$type == "fp"} {
    } else {
        puts "$type not support!"
        exit
    }
}

skip_tests "sys"
