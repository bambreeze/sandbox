#!/usr/bin/perl 

$line = 1; 
while (<>) { 
    #print $line, " ", $_; 
    #$line = $line + 1;
    printf "%5d %s", $line++, $_;
} 
