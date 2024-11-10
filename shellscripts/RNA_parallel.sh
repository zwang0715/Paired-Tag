#!/bin/bash
#PBS -q hotel
#PBS -N Paired_RNA
#PBS -t 32
#PBS -l nodes=4:ppn=4
#PBS -l walltime=8:00:00

fastq_dir="/home/y2xie/renlab_y2xie/y2xie/projects/Paired-Tag/210429_H3K4me1_H3K9me3/01.rawdata"
mm10_rna="/home/y2xie/mm10_index/STAR/mm10.ensGene.gtf"
trim_dir="/home/y2xie/renlab_y2xie/y2xie/projects/Paired-Tag/210429_H3K4me1_H3K9me3_YX/02.trimmed"
map_dir="/home/y2xie/renlab_y2xie/y2xie/projects/Paired-Tag/210429_H3K4me1_H3K9me3_YX/03.mm10_mapping"
trim_galore ${fastq_dir}/${s}_BC_cov.fq.gz -o ${trim_dir}
trim_galore -a AAAAAAAAAAAAAAAACCTGCAGGNNNNACGAATGCTCTGGCCTNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN ${trim_dir}/${s}_BC_cov_trimmed.fq.gz -o ${trim_dir} ### trim oligo-dT primer
trim_galore -a CCTGCAGGNNNNACGAATGCTCTGGCCTNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN ${trim_dir}/${s}_BC_cov_trimmed_trimmed.fq.gz -o ${trim_dir} ## trim N6 primer
STAR --runThreadN 6 --genomeDir ${mm10} --readFilesIn ${trim_dir}/${s}_BC_cov_trimmed_trimmed_trimmed.fq.gz --readFilesCommand zcat --outFileNamePrefix ${map_dir}/${s}_mm10_ --outSAMtype BAM Unsorted
samtools view -h -F 256 ${map_dir}/${s}_mm10_Aligned.out.bam -b > ${map_dir}/${s}_clean.bam
samtools sort -o ${map_dir}/${s}_mm10_sorted.bam ${map_dir}/${s}_clean.bam 
/home/y2xie/Paired-Tag-master/reachtools/reachtools rmdup2 ${map_dir}/${s}_sorted.bam
/home/y2xie/Paired-Tag-master/reachtools/reachtools bam2Mtx2 ${map_dir}/${s}_sorted_rmdup.bam ${mm10_rna}
