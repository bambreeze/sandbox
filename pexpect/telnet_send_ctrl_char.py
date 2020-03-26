#!/usr/bin/env python

import sys
import time
import pexpect

console_ip = "192.168.1.111"
console_port = "2011"

process = pexpect.spawn("telnet " + console_ip + " " + console_port, logfile=sys.stdout)
process.expect("Escape character is")
process.sendline("\r")
process.expect(">")
process.sendline("?")
process.expect(">")

# quit the telnet gracefully
process.sendcontrol(']')
process.expect(">")
process.sendline("q")
process.expect("Connection closed")

time.sleep(100)

