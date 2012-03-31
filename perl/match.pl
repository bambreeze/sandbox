#!/usr/bin/perl

open DICT, "words.txt" or die "Can't open words.txt: $!\n";
while (<DICT>) {
    $first = $1 if ?(^neur.*)?;
    $last = $1 if /(^neur.*)/;
}

print $first, "\n";     # print "neurad"
print $last, "\n";      # print "neurypnology"

$_ = "I saw Barney\ndown at the bowling alley\nwith fred\nlast night.\n";
if (/Barney.*fred/s) {
    print "That string mentions fred after Barney!\n";
}
