#!/bin/bash
#PBS -q hotel
#PBS -N Paired_DNA_${mode}_${s}
#PBS -l nodes=1:ppn=8
#PBS -l walltime=36:00:00

### you need to pass s, genome, mode into this script!
### s: sample name (e.g., YX001_R1.fq.gz. YX001 is the sample name)
### genome: genome used (e.g., mm10)
### mode: what kind of barcodes strageties you used? (e.g., PT48, indicating 48*384*384 barcodes)
### pass variable during qsub:
### qsub -v s=YX001,genome=mm10,mode=PT48 02.proc_DNA_PT_v3.sh

### you need to change [current] to your working directory
current="/home/y2xie/scratch/34.Biomek_PT_test"
###
fastq_dir="${current}/01.rawdata"
old_fastq_dir="${current}"
trim_dir="${current}/02.trimmed"
map_dir="${current}/03.mapping"
mtx_dir="${current}/04.matrices"
log_dir="${current}/log"

### you need to have at least 01.rawdata (contain sample_R?.fq.gz) and scripts directory ready.
mkdir ${trim_dir} ${map_dir} ${mtx_dir} ${log_dir}

PT2="/home/y2xie/Paired-Tag-master/refereces/cell_id"
PT3="/home/y2xie/Paired-Tag-master/refereces/cell_id_407"
PT48="/projects/ps-renlab/zhw063/software/Paired-Tag-master/references/PairedTag48_384"
mm10_bowtie2="/projects/ps-renlab/share/bowtie2_indexes/mm10"
hg19_bowtie2="/projects/ps-renlab/share/bowtie2_indexes/hg19"
hg38_bowtie2="/projects/ps-renlab/share/bowtie2_indexes/hg38"
mix_bowtie2="/projects/ps-renlab/y2xie/projects/genome_ref/GRCh38_and_mm10/fasta/GRCh38_mm10"
mm10_5k="/projects/ps-renlab/y2xie/projects/genome_ref/Paired-Tag/mm10/mm10.bin5k.txt"
hg38_5k="/projects/ps-renlab/y2xie/projects/genome_ref/Paired-Tag/hg38/hg38.bin5k.txt"
mix_5k="/projects/ps-renlab/y2xie/projects/genome_ref/Paired-Tag/mix/mix.bin5k.txt"

if [ -z ${genome+x} ]; then echo "genome is not specified. Default to mm10"; genome="mm10"; fi
if [ $genome == "mm10" ]; then ref=${mm10_bowtie2}; bin=${mm10_5k}; fi
if [ $genome == "hg38" ]; then ref=${hg38_bowtie2}; bin=${hg38_5k}; fi
if [ $genome == "mix" ]; then ref=${mix_bowtie2}; bin=${mix_5k}; fi

echo "barcoding mode: "${mode}
if [ $mode == "PT2" ]; then PT=${PT2}; combine="combine2"; fi
if [ $mode == "PT3" ]; then PT=${PT3}; combine="combine3"; fi
if [ $mode == "PT48" ]; then PT=${PT48}; combine="combine48"; fi
 
(/home/y2xie/Paired-Tag-master/reachtools/reachtools ${combine} ${fastq_dir}/${s}) 2>&1> ${log_dir}/${s}_qc.log 
ln -sf ${fastq_dir}/${s}_DNA_combined.fq.gz ${fastq_dir}/${s}_combined.fq.gz
zcat ${fastq_dir}/${s}_combined.fq.gz | bowtie ${PT} - --norc -m 1 -v 1 -S ${fastq_dir}/${s}_BC.sam
(/home/y2xie/Paired-Tag-master/reachtools/reachtools convert2 ${fastq_dir}/${s}_BC.sam) 2>&1>> ${log_dir}/${s}_qc.log

if [[ -f "${fastq_dir}/${s}_BC_cov.fq.gz" ]]
then 
	echo ${s}" has been processed."
	rm ${fastq_dir}/${s}_BC.sam
fi

# whether do merge or not? if files with identical name in ${old_fastq_dir} can be found, then merge
if [[ -f "${old_fastq_dir}/${s}_BC_cov.fq.gz" ]]
then
    echo "previous sequencing file in "${old_fastq_dir}" has been found. Merge files for processing..."
    cat ${fastq_dir}/${s}_BC_cov.fq.gz ${old_fastq_dir}/${s}_BC_cov.fq.gz > ${fastq_dir}/${s}_merge_BC_cov.fq.gz
    sall=${s}_merge
else
    sall=${s}
fi

# whether do subsample or not? default is no subsampling
if [ -z ${sample+x} ]
then
    echo "no fastq sub sample is done"
    salll=${sall}
else
    seqtk sample -s 123 ${fastq_dir}/${sall}_BC_cov.fq.gz ${sample} | gzip > ${fastq_dir}/${sall}_sample_BC_cov.fq.gz
    salll=${sall}_sample
fi

trim_galore ${fastq_dir}/${salll}_BC_cov.fq.gz -o ${trim_dir}
(bowtie2 -x ${ref} -U ${trim_dir}/${salll}_BC_cov_trimmed.fq.gz --no-unal -p 16 -S ${map_dir}/${salll}_${genome}.sam) 2>${map_dir}/${salll}.log
samtools sort -@ 16 -T ${map_dir} -o ${map_dir}/${salll}_${genome}_sorted.bam ${map_dir}/${salll}_${genome}.sam

if [[ -f "${map_dir}/${salll}_${genome}_sorted.bam" ]]
then 
	rm ${map_dir}/${salll}_${genome}.sam
fi

### bam2mtx
/home/y2xie/Paired-Tag-master/reachtools/reachtools rmdup2 ${map_dir}/${salll}_${genome}_sorted.bam
/home/y2xie/Paired-Tag-master/reachtools/reachtools bam2Mtx2 ${map_dir}/${salll}_${genome}_sorted_rmdup.bam ${bin}
mv ${map_dir}/${salll}_${genome}_sorted_rmdup_mtx2 ${mtx_dir}


