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
