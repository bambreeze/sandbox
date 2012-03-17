#!/usr/bin/perl

use XML::Simple;
use Data::Dumper;

$xml = XMLin('sample1.xml', ForceArray => 1);
print Dumper($xml);

foreach (keys %$xml) {
    print "$_\n";
    my %xml_h = %{$xml};
    if ($_ eq "text") {
        #print "  ", $$xml{$_}[0], "\n";
        print "  ", $xml_h{$_}[0], "\n";
    } elsif ($_ = "user") {
    } else {
    }

}
