#!/usr/bin/perl

my %table;

open TXT_FILE, "registers.txt" or die $!;
while (<TXT_FILE>) {
    chomp;

    next if /^#/;   # discard comments
    s/^\s+//;       # strip leading  whitespace
    s/\s+$//;       # strip trailing whitespace
    next unless $_;

    my ($name, $address) = split /,/;
    my $name_org = $name;

    my @name_a = split /\s+/, $name;
    unless ($name_a[0]) {
        shift @name_a;
    }
    foreach (@name_a) {
        $_ = uc($_);
    }
    $name = join "_", @name_a;

    if ($address =~ /0[xX]([\dA-Fa-f]+)/) {
        #print "got it 1...", $1, "\n";
        #$address = "0x" . uc($1);
        #printf "0x%08X\n", hex($address);
        $address = sprintf "0x%08X", hex($1);
        $table{$address} = $name;
    } elsif ($address =~ /([\dA-Fa-f]+)/) {
        #print "got it 2...", $1, "\n";
        #$address = "0x" . uc($1);
        $address = sprintf "0x%08X", hex($1);
        $table{$address} = $name;
    } else {
        print "Something worng! We need an address for this register \
        '$name_org'\n";
    }
}

foreach (sort keys %table) {
    print "$table{$_} => $_\n";
}
