//
// Created by pdossant on 23/04/15.
//

#ifndef SLURMKORE_CONFIGURATION_H
#define SLURMKORE_CONFIGURATION_H

#include <slurm/slurm.h>
#include <jansson.h>

char *json_to_string(json_t * obj);

json_t *slurm_configuration_to_json(const slurm_ctl_conf_t *conf);

json_t *slurm_partitions_to_json(const partition_info_msg_t *partitions);

json_t *slurm_partition_to_json(const partition_info_t *partition);

json_t *slurm_jobid_to_json(const job_info_t *job_ptr);

#endif //SLURMKORE_CONFIGURATION_H
