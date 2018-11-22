#! /usr/bin/env perl
use warnings;
use strict;

my $string;

if ($ARGV[0]) {
    $string = do {local(@ARGV, $/) = $ARGV[0]; <>}
        or die;
} else {
    $string = do {local $/; <STDIN>};
}

chomp $string;

my $len = length($string);

if ($len > 1) {
    my ($half, $tmp);

    if ($len % 2 == 0) {
        $half = $len / 2;
    } else {
        $half = ($len - 1) / 2;
    }

    for (1 .. $half) {
        $tmp = substr($string, $_-1, 1);
        substr($string, $_-1, 1, substr($string, -$_, 1));
        substr($string, -$_, 1, $tmp);
    }
}

print($string . "\n");
