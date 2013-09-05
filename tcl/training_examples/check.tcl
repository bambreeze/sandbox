#!/usr/bin/tclsh

set ver_info {
    at-10k-i01#show version 
    Load for five secs: 2%/0%; one minute: 2%. five minutes: 2%
    Cisco IOS Software, 10000 Software (UBR10K5-K9P6U2-M), Experimental Version 12.2(20120910:182701)
    [honsun-cobra_qiantang4_Sep11 103]
    Copyright (c) 1986-2012 by Cisco Systems, Inc.
    Compiled Mon 10-Sep-12 12:44 by honsun
    ROM: System Bootstrap, Version 12.2(20120720:021644) [libzhang-pre5_rommon_0720 215], DEVELOPMENT SOFTWARE
    at-10k-i01 uptime is 1 hour, 7 minutes
    Uptime for this control processor is 53 minutes
    System returned to ROM by reload at 13:28:30 CST Mon Sep 17 2012
    System image file is "disk0:ubr10k5-k9p6u2.image".
    Last reload type: Normal Reload
    Last reload reason: Unknown reason
    Standby is up
    Standby has 3727359K bytes of memory
    Configuration register is 0x2102
} 

set check_image "ubr10k5-k9p6u2.image"
set check_tag [regexp {System image file is "disk0:([\.\-a-z0-9]+)}  $ver_info all reg_info]
if {$check_tag == 0} {
    puts  "error: can not get  image info"
} else {
     if {$reg_info == "$check_image"} {
          puts "pass: get right image: $reg_info"
     } else {
          puts  "failure: image not match."
     }
}



