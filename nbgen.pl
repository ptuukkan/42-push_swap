#!/usr/bin/perl

use strict;
use warnings;
use 5.010;

my %unique;
++$unique{int(rand $ARGV[1])} while keys %unique < $ARGV[0];

say join ' ', keys %unique;
