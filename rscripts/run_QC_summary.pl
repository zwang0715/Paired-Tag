#!/usr/bin/perl
use strict;
use warnings;

### usage:
### perl /home/y2xie/Paired-Tag-master/rscripts/run_QC_summary.pl [parental path] [sub_directory]
### subdirectory can be omitted.

my $path = $ARGV[0]; ### where is the working folder?
my $subdir = "."; ### if not set then set as "."
$subdir = $ARGV[1]; ### is there subdir in the working folder?

my $command = join '', "mkdir ", $path, "/05.R/", $subdir, "/Paired-Tag_QC_reports"; 
my $input = join '/', $path, "05.R", $subdir, "QC_library_list.xls"; 

system($command);
open IN, $input or die $!;
my $first;
my $last;
my $i = 0;
while(<IN>){
	chomp;
	$i++;
	my @tmp = split/\s+/, $_;
	my $dna = $tmp[0];
	my $rna = $tmp[1]; 
	$first=$dna if $i==1;
	$last=$rna;
	my $gen = $tmp[2];
	my $info = $tmp[3]; 
	my $output = join '', $path, "/05.R/", $subdir, "/Per_lib_QC_", $dna, "_", $rna, ".html"; 
	my $command = "/projects/ps-renlab/y2xie/anaconda3/envs/seurat/bin/Rscript -e \"rmarkdown::render(\'/home/y2xie/Paired-Tag-master/rscripts/per_library_QC.Rmd\', params=list(dna.id=\'$dna\', rna.id=\'$rna\', genome=\'$gen\', path=\'$path\', subdir=\'$subdir\', info=\'$info \'), output_file=\'$output\')\"";
	system($command);
}
close IN;

my $output = join '/', $path, "05.R", $subdir, "Paired-Tag_project_summary.html"; 
$command = "/projects/ps-renlab/y2xie/anaconda3/envs/seurat/bin/Rscript -e \"rmarkdown::render(\'/home/y2xie/Paired-Tag-master/rscripts/summary_QC.Rmd\', params=list(metaf=\'$input\', path=\'$path\', subdir=\'$subdir\'), output_file=\'$output\')\"";
system($command);

$command = join '', "mv ", $path, "/05.R/", $subdir, "/*.html ", $path, "/05.R/", $subdir, "/Paired-Tag_QC_reports/"; 
system($command);

$command = join '', "rm -rf ", $path, "/05.R/", $subdir, "/*fastqc"; 
system($command);

