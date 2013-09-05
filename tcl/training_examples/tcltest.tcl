#!/usr/bin/tclsh

package require tcltest 2
namespace import tcltest::*

# Same output for "HELLO WORLD"
test example-1.1 {an example test} -body {
  string toupper "hello world"
} -result "HELLO WORLD"

# Failed case
test example-1.2 {an example test} -body {
  string toupper "hello world"
  puts "HELLO"
} -result "HELLO WORLD"

# Complex Example
test example-1.3 {a more complex example} -constraints {
  unix
} -setup {
  set f [open /tmp/testdata w]
  puts $f "hello, world"
  close $f
} -body {
  set f [open /tmp/testdata r]
  set data [read $f 5]
  close $f
  set data
} -cleanup {
  file delete -force /tmp/testdata
} -result "hello"


cleanupTests
