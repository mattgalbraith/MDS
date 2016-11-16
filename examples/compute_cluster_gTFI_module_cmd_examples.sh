#PBS -S /bin/bash

#PBS -N gTFIv2
#PBS -m ae
#PBS -M joseph.azofeifa@colorado.edu


#PBS -l walltime=72:00:00
#PBS -l nodes=1:ppn=64
#PBS -l mem=10gb
hostlist=$( cat $PBS_NODEFILE | sort | uniq | tr '\n' ',' | sed -e 's/,$//' )
# -- OpenMP environment variables --
OMP_NUM_THREADS=64
export OMP_NUM_THREADS
module load gcc_4.9.2
module load mpich_3.1.4



cmd="mpirun -np $PBS_NUM_NODES -hosts ${hostlist}"


#===========================================================
install_location=/Users/azofeifa/Lab/gTFIv2/ #whereever you installed gTFI
#change this accordingly
#===========================================================
#input parameters and necessary paths

src=${install_location}/CPP_src/SE #path to src

input_interval_file=${install_location}examples/test_intervals_example.bed
fasta_file=${install_location}examples/test_hg19.fa
PSSM_DB=${install_location}examples/test_motif_db.txt
TSS=${install_location}examples/hg19_TSS.bed


out_file_DB=${install_location}/examples/test_null_database.txt
out_file_stats=${install_location}/examples/test_interval_stats.txt

log_out=${install_location}/examples/
ID=unit_test_run_DB
ID2=unit_test_run_EVAL
NP=3
sim_N=100
pv=0.00001
bsn=150
H=1500
h=150


echo '\n\n-------------------------Running Unit Tests-------------------------\n\n\n'

echo 'Installation Location: ' $install_location ' is this correct?'


echo '\n\n-------------------------Running DB Module-------------------------\n'

mpirun -np $NP $src DB -bed $input_interval_file -TSS $TSS -fasta $fasta_file -DB $PSSM_DB -o $out_file_DB -log_out $log_out -ID $ID -sim_N $sim_N -pv $pv -H $H ;


