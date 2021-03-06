#!/usr/bin/perl

my %table;

open TXT_FILE, "registers.txt" or die $!;
while (<TXT_FILE>) {
    chomp;

    next if /^#/;    # discard comments
    next if /^\s*$/; # discard blank lines
    s/^\s+//;        # strip leading  whitespace
    s/\s+$//;        # strip trailing whitespace

    my ($name, $address) = split /,/;
    if ($address =~ /0[xX]([\dA-Fa-f]+)|([\dA-Fa-f]+)/) {
        $address = sprintf "0x%08X", hex($&);
        $name =~ s/\W+/_/g;
        $table{$address} = uc($name);
    } else {
        print "Something worng! We need an address for this register \
        '$name'\n";
    }
}

foreach (sort keys %table) {
    print "$table{$_} => $_\n";
}
