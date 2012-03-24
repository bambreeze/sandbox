#!/usr/bin/perl

use strict;
 
use LWP::Simple;
use HTML::TreeBuilder::XPath;
use Data::Dumper;
 
#my $url = "http://www.alexa.com/siteinfo/www.php-oa.com";
#my $html = get( $url );
my $html = "registers.html";
my $tree = new HTML::TreeBuilder::XPath;
$tree->parse($html);
$tree->eof;
$tree->dump;

#my $srt;
#my $items = $tree->findnodes( '/html/body/descendant::div[@class[.=~/data down/]]' );
#for my $item ( $items->get_nodelist() ){
#        eval{
#            $srt  = $item->content->[1];
#        };
#        print "You're on the top ".$srt."\n";
#    }
