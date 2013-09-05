#!/usr/bin/tclsh

package require Expect
proc InitTelnetcmts {Ip port pass} {
	global telnet_id  expect_out ID
	set value 0
	set PassLoginTimes 0
	set timeout 10
	spawn telnet 
	set ID $spawn_id
	puts "telnet $Ip $port"
	send -i $ID "open $Ip $port\r"
	expect   {
        -i $ID ">" {
            send  -i $ID "en\r"
            exp_continue
        }
        -i $ID  "Password:" {
            incr PassLoginTimes
            puts "Input Password"
            if {$PassLoginTimes < 5} {
                send  -i $ID "$pass\r" 
                exp_continue
            } else {
                return 0       
            }
        }
        -i $ID -re "--More--"  {
            set buf "$buf$expect_out(buffer)"
            send -i $ID "q  "        
            exp_continue   
        }

        -i $ID "#"   {
            puts "$Ip Telnet --> successful"
            send -i $ID "\r"
            expect #
            send -i $ID "configure terminal\r"
            expect #
            send -i $ID "end\r"
            expect -i $ID #
            send -i $ID "terminal length 0\r"
            expect -i $ID #
            set value 1
            #close -i $ID
            #unset ID
            return $value 
        }
        -i $ID "Connection refused" {
            puts "Connection refused."
            return 0
        }      
        timeout {
            puts "Password Mismatch"
            return 0
        }
    }
    return $value
}

# Call Expect the telnet to my testbed
InitTelnetcmts 10.74.58.251 2066 lab
puts \nsuccess!!!

# Get some information from testbed
send -i $ID "show version\r"
expect -i $ID NS-2#
send -i $ID "show cable modem\r"
expect -i $ID NS-2#

parray expect_out
# put a new line
puts ""

