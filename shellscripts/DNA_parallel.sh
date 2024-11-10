#!/bin/bash
#PBS -q hotel
#PBS -N Paired_DNA
#PBS -t 32
#PBS -l nodes=4:ppn=4
#PBS -l walltime=8:00:00

fastq_dir="/home/y2xie/renlab_y2xie/y2xie/projects/Paired-Tag/210429_H3K4me1_H3K9me3/01.rawdata"
mm10="/home/y2xie/mm10_index/chromFa/mm10_bowtie2_index"
mm10_5k="/home/y2xie/Paired-Tag-master/refereces/mm10.bin5k.txt.zip"
trim_dir="/home/y2xie/renlab_y2xie/y2xie/projects/Paired-Tag/210429_H3K4me1_H3K9me3_YX/02.trimmed"
map_dir="/home/y2xie/renlab_y2xie/y2xie/projects/Paired-Tag/210429_H3K4me1_H3K9me3_YX/03.mm10_mapping"
trim_galore ${fastq_dir}/${s}_BC_cov.fq.gz -o ${trim_dir}
(bowtie2 -x ${mm10} -U ${trim_dir}/${s}_BC_cov_trimmed.fq.gz --no-unal -p 8 -S ${map_dir}/${s}_mm10.sam) 2>${map_dir}/${s}.log
samtools sort -o ${map_dir}/${s}_mm10_sorted.bam ${map_dir}/${s}_mm10.sam 
/home/y2xie/Paired-Tag-master/reachtools/reachtools rmdup2 ${map_dir}/${s}_mm10_sorted.bam
/home/y2xie/Paired-Tag-master/reachtools/reachtools bam2Mtx2 ${map_dir}/${s}_mm10_sorted_rmdup.bam ${mm10_5k}