#!/usr/bin/tclsh
# Read a line from the file and analyse it.

proc load_config_file {fname} {
    set fid [open $fname r]
        while { ![eof $fid] } {
            gets $fid line
    
            if { [regexp {^X *, *(0[xX][a-fA-F0-9]+) *, *(0[xX][a-fA-F0-9]+).*$} $line dummy addr val] } {
                set addr [string tolower $addr]
                set val [string tolower $val]
                puts "write addr: $addr, val: $val"
            } elseif { [regexp {^W , +([0-9]+)} $line dummy dtime] } {
                puts "delay $dtime"
            } elseif { [regexp {^ *$} $line] } {
                #puts "Ignore blank lines"
            } elseif { [regexp {^;.*$} $line] } {
                #puts "Ignore comments lines"
            } else {
                puts "error: please check input file"
            }
        }
    close $fid
}

load_config_file "input.txt"
