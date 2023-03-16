s="/home/y2xie/renlab_y2xie/y2xie/projects/Paired-Tag/fastq/fastq/CZ401" # with ${s}_R1.fq.gz and ${s}_R2.fq.gz in the working directory
p="/home/y2xie/Paired-Tag-master/refereces/cell_id" # build a bowtie index on cell_id_full.fa
reachtools combine2 ${s}
zcat ${s}_combined.fq.gz | bowtie ${p} - --norc -m 1 -v 1 -S ${s}_BC.sam

#### This step convert to Celluar Barcode mapped reads to fastq files.
#### Use this line if for standard fastq files
reachtools convert2 ${s}_BC.sam  
#### Ues this line if for fastq file downloaded from GEO. The fastq file from GEO trimmed read name as the format is different. See https://github.com/cxzhu/Paired-seq/issues/1 for details.
# ./perlscripts/sam2convFastq.pl ${s}_BC.sam
