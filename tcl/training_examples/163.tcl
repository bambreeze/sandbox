#!/usr/bin/tclsh

set mail_url "pop.163.com 110"
set user "18939862251"
set passwd "1qaz@WSX"

package require Expect

puts "spawn:"
spawn telnet 
set next_step "open"
sleep 1

puts "open: $mail_url"
send "open $mail_url\r"
set next_step "user"

expect {
    "+OK Welcome to coremail Mail" {
        puts "match \"+OK Welcome\""
        puts "Get the sponse from server"
        sleep 2
        puts "Send the user name"
        send  "user $user\r"
        set next_step "pass"
        exp_continue
    } "+OK core mail" {
        puts "match \"+OK core mail\""
        sleep 2
        switch $next_step {
            "pass" {
                puts "Send the password"
                send  "pass $passwd\r"
                set next_step "mail"
                exp_continue
            } "mail" {
            } default {
                puts "invalid parameter for next step: $next_step"
            }
        }
    } { byte(s)} {
        puts "match \"+OK message list\""
        set str_reg {([\d]+) message\(s\) \[([\d]+) byte} 
        regexp $str_reg $expect_out(buffer) str_all str_num str_byte
        puts "There is $str_num mails and $str_byte bytes"

        # Get the first mail
        puts "--------------------------"
        puts "Get the mail list from server"
        send  "uidl\r"
        expect "^.$"
        puts $expect_out(buffer)
        sleep 2
        puts "--------------------------"
        send "quit\r"
    } "ERR" {
        puts "ERROR in server"
    } timeout {
        puts "time out!!!!"
        puts "Buffer: $expect_out(buffer)"
    }
}
