#!/usr/bin/tclsh

    for {set var 40} {$var < 70} {incr var 10} {
              puts [format "Decimal: %3d, Zero Pad: %03d, Left,\
                                   Just: %-3d, Hex: %3x Char: %c"\
                                   $var $var $var $var $var] 
    }

