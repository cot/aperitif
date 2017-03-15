#ifndef SLURMKORE_SLURM_TO_JSON_H
#define SLURMKORE_SLURM_TO_JSON_H

char *slurm_get_configuration();

char *slurm_get_partitions();

long slurm_get_api_version();

int slurm_exec_submit_batch_job();

char *slurm_get_job_info(int jobid);

#endif //SLURMKORE_SLURM_TO_JSON_H

