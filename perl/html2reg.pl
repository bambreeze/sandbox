#!/usr/bin/perl

use HTML::TokeParser;

my %table;

#$FILENAME = "registers.html";
my $parser = HTML::TokeParser->new(shift || "registers.html")
    or die "Can't open: $!\n";
while (my $token = $parser->get_tag("a")) {
    my $name = $token->[1]{name};
    my $caption = $parser->get_trimmed_text("/caption");

    if ($caption =~ /0[xX]([\dA-Fa-f]+)/) {
        $address = sprintf "0x%08X", hex($&);
        $table{$address} = uc($name);
    }
}

foreach (sort keys %table) {
    print "$table{$_} => $_\n";
}
