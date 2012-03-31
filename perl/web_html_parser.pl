#!/usr/bin/perl

use HTML::TokeParser;

my %table;

$FILENAME = "registers.html";
my $parser = HTML::TokeParser->new($FILENAME)
    or die "Can't open $FILENAME: $!\n";
while (my $token = $parser->get_token( )) {
    my $type = $token->[0];
    if ($type eq 'S') { # start tag
        if ($token->[1] eq 'a') {
            print "$token->[4]\n";
        }
    } elsif ($type eq 'E') { # end tag
        #print "$token->[1]\n";
    } elsif ($type eq 'T') { # text
        #print "$token->[1]\n";
    }
    elsif ($type eq 'C')  {  }   # comment
    elsif ($type eq 'D')  {  }   # declaration
    elsif ($type eq 'PI') {  }   # processing instruction
    else { die "$type isn't a valid HTML token type" }
}
