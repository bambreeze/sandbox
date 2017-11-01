#!/usr/bin/tclsh

set input_file  "input.txt"
set output_file "output.txt"

if {[catch {set file_in [open $input_file r]} err_msg]} {
    puts "Failed to open the file for reading: $err_msg"
    return
}

if {[catch {set file_out [open $output_file w]} err_msg]} {
    puts "Failed to open the file for writing: $err_msg"
    close $file_in
    return
}

while {[gets $file_in line] != -1} {
    puts $file_out $line
}

close $file_in
close $file_out
