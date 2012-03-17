#!/usr/bin/perl

my %table;

open TXT_FILE, "registers.txt" or die $!;
while (<TXT_FILE>) {
    chomp;
    my ($name, $address) = split /,/;

    my @name_a = split /\s+/, $name;
    $name = join "_", @name_a;

    $table{$address} = $name;
}

foreach (sort keys %table) {
    print "$_ => $table{$_}\n";
}
