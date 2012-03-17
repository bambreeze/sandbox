#!/usr/bin/perl
use strict;
use warnings;

use Email::Valid;

#my $email_address = 'a.n@example.com';
my $email_address = 'bambreeze123232@gmailabc.com';

unless( Email::Valid->address($email_address) ) {
    print "Sorry, that email address is not valid!";
}
