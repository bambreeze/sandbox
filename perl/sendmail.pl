#!/usr/bin/perl
use strict;
use warnings;

# first, create your message
use Email::MIME;
my $message = Email::MIME->create(
  header_str => [
    From    => 'bambreeze@hotmail.com',
    To      => 'bambreeze@gmail.com',
    Subject => 'Hello World!',
  ],
  attributes => {
    encoding => 'quoted-printable',
    charset  => 'ISO-8859-1',
  },
  body_str => "Hello World! This is sending using perl!\n",
);

# send the message
use Email::Sender::Simple qw(sendmail);
sendmail($message);
