@infilelist = qw (main.cpp Game.h Game.cpp Bag.h Bag.cpp Ball.h Ball.cpp);
$outfile = "listing";
$i = 0;

foreach $infile (@infilelist)
{
    $i += 1;
    open(OUT, ">>$outfile") || die "cannot create $outfile for appending: $!";

    print OUT "\n";
    print OUT "---------------- $i:$infile ----------------\n";
    print OUT "\n\n";

    open(IN, $infile) || die "cannot open $infile for reading: $!";

    $line = 1;
    while (<IN>)
    {
        printf( OUT "%03d: %s", $line, $_ );
        $line += 1;
#        print OUT $_;
    }

    close(IN) || die "cannot close $infile: $!";

    print OUT "\n\n";
#    print OUT "\f";

    close(OUT) || die "cannot close $outfile: $!";
}