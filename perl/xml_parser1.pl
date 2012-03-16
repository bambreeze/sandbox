#!/usr/bin/perl

use XML::Simple;
use Data::Dumper;

$xml = XMLin('sample1.xml', ForceArray => 1);
print Dumper($xml);

foreach (keys %$xml) {
    if ($_ eq "text") {
        print "$_ => ";
        foreach (@{$xml->{$_}}) {
            printf "$_\n";
        }
    } elsif ($_ eq "user") {
        foreach (@{$xml->{$_}}) {
            my %hash = %{$_};
            foreach (keys %hash) {
                if ($_ eq "session") {
                    print "$_ => ";
                    my @array_s = @{$hash{$_}};
                    foreach (@array_s) {
                        my %hash_pid = %{$_};
                        foreach (keys %hash_pid) {
                            print "$_ => $hash_pid{$_}\n";
                        }
                    }
                } else {
                    print "$_ => $hash{$_}\n";
                }
            }
        }
    }
}

