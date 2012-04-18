#!/usr/bin/perl

$a       = "alpha";
$b       = "omega";
print "$a, $b\n";
($a, $b) = ($b, $a);        # the first shall be last -- and versa vice
print "$a, $b\n";

($alpha, $beta, $production) = qw(January March August);
print "$alpha, $beta, $production\n";
# move beta       to alpha,
# move production to beta,
# move alpha      to production
($alpha, $beta, $production) = ($beta, $production, $alpha);
print "$alpha, $beta, $production\n";
