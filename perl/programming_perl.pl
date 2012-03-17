#!/usr/bin/perl

$cwd = `pwd`;
print $cwd;

%longday = (
        "Sun" => "Sunday",
        "Mon" => "Monday",
        "Tue" => "Tuesday",
        "Wed" => "Wednesday",
        "Thu" => "Thursday",
        "Fri" => "Friday",
        "Sat" => "Saturday",
        );
print $longday{"Wed"}, "\n";

$a = 12;
$b = 3;
print $a x $b, "\n";
