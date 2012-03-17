#!/usr/bin/perl

my %table;

open CITIES, "cities.txt" or die $!;
while (<CITIES>) {
    chomp;
    my ($city, $country) = split /, /;
    $table{$country} = [] unless exists $table{$country};
    push @{$table{$country}}, $city;
}

foreach $country (sort keys %table) {
    print "$country: ";
    my @cities = @{$table{$country}};
    print join ', ', sort @cities;
    print ".\n";
}
