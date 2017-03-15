#ifndef SLURMKORE_SLURM_TO_JSON_H
#define SLURMKORE_SLURM_TO_JSON_H

char *slurm_get_configuration();

char *slurm_get_partitions();

long slurm_get_api_version();

char *slurm_get_job_info(int jobid);

int slurm_exec_submit_batch_job();

#endif //SLURMKORE_SLURM_TO_JSON_H

