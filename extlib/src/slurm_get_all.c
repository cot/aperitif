//
// Created by pdossant on 23/04/15.
//

#include "configuration.h"
#include "version.h"

char *json_to_string(json_t * obj)
{
    char *str = json_dumps(obj, 0);
    json_decref(obj);
    return str;
}

json_t *slurm_configuration_to_json(const slurm_ctl_conf_t *conf)
{
    json_t *obj = json_object();

//    if (_slurm_api_major == 26)
//    {
//        json_object_set_new(obj, "acct_gather_energy_type", json_string(conf->acct_gather_energy_type));
//        json_object_set_new(obj, "acct_gather_energy_type", json_string(conf->acct_gather_energy_type));
//        json_object_set_new(obj, "acct_gather_profile_type", json_string(conf->acct_gather_profile_type));
//        json_object_set_new(obj, "acct_gather_infiniband_type", json_string(conf->acct_gather_infiniband_type));
//        json_object_set_new(obj, "acct_gather_filesystem_type", json_string(conf->acct_gather_filesystem_type));
//        json_object_set_new(obj, "acct_gather_node_freq", json_integer(conf->acct_gather_node_freq));
//        json_object_set_new(obj, "dynalloc_port", json_integer(conf->dynalloc_port));
//        json_object_set_new(obj, "ext_sensors_type", json_string(conf->ext_sensors_type));
//        json_object_set_new(obj, "ext_sensors_freq", json_integer(conf->ext_sensors_freq));
//        json_object_set_new(obj, "health_check_node_state", json_integer(conf->health_check_node_state));
//        json_object_set_new(obj, "job_acct_gather_freq", json_string(conf->job_acct_gather_freq));
//        json_object_set_new(obj, "keep_alive_time", json_integer(conf->keep_alive_time));
//        json_object_set_new(obj, "launch_type", json_string(conf->launch_type));
//        json_object_set_new(obj, "licenses_used", json_string(conf->licenses_used));
//        json_object_set_new(obj, "max_array_sz", json_integer(conf->max_array_sz));
//        json_object_set_new(obj, "priority_flags", json_integer(conf->priority_flags));
//        json_object_set_new(obj, "reboot_program", json_string(conf->reboot_program));
//        json_object_set_new(obj, "reconfig_flags", json_integer(conf->reconfig_flags));
//        json_object_set_new(obj, "resv_epilog", json_string(conf->resv_epilog));
//        json_object_set_new(obj, "resv_prolog", json_string(conf->resv_prolog));
//        json_object_set_new(obj, "slurmctld_plugstack", json_string(conf->slurmctld_plugstack));
//    }
//    else if (_slurm_api_major == 23)
//    {
//        json_object_set_new(obj, "job_acct_gather_freq", json_integer(conf->job_acct_gather_freq));
//    }
    json_object_set_new(obj, "last_update", json_integer(conf->last_update));
    json_object_set_new(obj, "accounting_storage_enforce", json_integer(conf->accounting_storage_enforce));
    json_object_set_new(obj, "accounting_storage_backup_host", json_string(conf->accounting_storage_backup_host));
    json_object_set_new(obj, "accounting_storage_host", json_string(conf->accounting_storage_host));
    json_object_set_new(obj, "accounting_storage_loc", json_string(conf->accounting_storage_loc));
    json_object_set_new(obj, "accounting_storage_pass", json_string(conf->accounting_storage_pass));
    json_object_set_new(obj, "accounting_storage_port", json_integer(conf->accounting_storage_port));
    json_object_set_new(obj, "accounting_storage_type", json_string(conf->accounting_storage_type));
    json_object_set_new(obj, "accounting_storage_user", json_string(conf->accounting_storage_user));
    json_object_set_new(obj, "acctng_store_job_comment", json_integer(conf->acctng_store_job_comment));
    json_object_set_new(obj, "authtype", json_string(conf->authtype));
    json_object_set_new(obj, "backup_addr", json_string(conf->backup_addr));
    json_object_set_new(obj, "backup_controller", json_string(conf->backup_controller));
    json_object_set_new(obj, "batch_start_timeout", json_integer(conf->batch_start_timeout));
    json_object_set_new(obj, "boot_time", json_integer(conf->boot_time));
    json_object_set_new(obj, "checkpoint_type", json_string(conf->checkpoint_type));
    json_object_set_new(obj, "cluster_name", json_string(conf->cluster_name));
    json_object_set_new(obj, "complete_wait", json_integer(conf->complete_wait));
    json_object_set_new(obj, "control_addr", json_string(conf->control_addr));
    json_object_set_new(obj, "control_machine", json_string(conf->control_machine));
    json_object_set_new(obj, "crypto_type", json_string(conf->crypto_type));
    json_object_set_new(obj, "debug_flags", json_integer(conf->debug_flags));
    json_object_set_new(obj, "def_mem_per_cpu", json_integer(conf->def_mem_per_cpu));
    json_object_set_new(obj, "disable_root_jobs", json_integer(conf->disable_root_jobs));
    json_object_set_new(obj, "enforce_part_limits", json_integer(conf->enforce_part_limits));
    json_object_set_new(obj, "epilog", json_string(conf->epilog));
    json_object_set_new(obj, "epilog_msg_time", json_integer(conf->epilog_msg_time));
    json_object_set_new(obj, "epilog_slurmctld", json_string(conf->epilog_slurmctld));
    json_object_set_new(obj, "fast_schedule", json_integer(conf->fast_schedule));
    json_object_set_new(obj, "first_job_id", json_integer(conf->first_job_id));
    json_object_set_new(obj, "get_env_timeout", json_integer(conf->get_env_timeout));
    json_object_set_new(obj, " gres_plugins", json_string(conf->gres_plugins));
    json_object_set_new(obj, "group_info", json_integer(conf->group_info));
    json_object_set_new(obj, "hash_val", json_integer(conf->hash_val));
    json_object_set_new(obj, "health_check_interval", json_integer(conf->health_check_interval));
    json_object_set_new(obj, " health_check_program", json_string(conf->health_check_program));
    json_object_set_new(obj, "inactive_limit", json_integer(conf->inactive_limit));
    json_object_set_new(obj, "job_acct_gather_type", json_string(conf->job_acct_gather_type));
    json_object_set_new(obj, "job_ckpt_dir", json_string(conf->job_ckpt_dir));
    json_object_set_new(obj, "job_comp_host", json_string(conf->job_comp_host));
    json_object_set_new(obj, "job_comp_loc", json_string(conf->job_comp_loc));
    json_object_set_new(obj, "job_comp_pass", json_string(conf->job_comp_pass));
    json_object_set_new(obj, "job_comp_port", json_integer(conf->job_comp_port));
    json_object_set_new(obj, "job_comp_type", json_string(conf->job_comp_type));
    json_object_set_new(obj, "job_comp_user", json_string(conf->job_comp_user));
    json_object_set_new(obj, "job_credential_private_key", json_string(conf->job_credential_private_key));
    json_object_set_new(obj, "job_credential_public_certificate", json_string(conf->job_credential_public_certificate));
    json_object_set_new(obj, "job_file_append", json_integer(conf->job_file_append));
    json_object_set_new(obj, "job_requeue", json_integer(conf->job_requeue));
    json_object_set_new(obj, "job_submit_plugins", json_string(conf->job_submit_plugins));
    json_object_set_new(obj, "kill_on_bad_exit", json_integer(conf->kill_on_bad_exit));
    json_object_set_new(obj, "kill_wait", json_integer(conf->kill_wait));
    json_object_set_new(obj, "licenses", json_string(conf->licenses));
    json_object_set_new(obj, "mail_prog", json_string(conf->mail_prog));
    json_object_set_new(obj, "max_job_cnt", json_integer(conf->max_job_cnt));
    json_object_set_new(obj, "max_job_id", json_integer(conf->max_job_id));
    json_object_set_new(obj, "max_mem_per_cpu", json_integer(conf->max_mem_per_cpu));
    json_object_set_new(obj, "max_step_cnt", json_integer(conf->max_step_cnt));
    json_object_set_new(obj, "max_tasks_per_node", json_integer(conf->max_tasks_per_node));
    json_object_set_new(obj, "min_job_age", json_integer(conf->min_job_age));
    json_object_set_new(obj, "mpi_default", json_string(conf->mpi_default));
    json_object_set_new(obj, "mpi_params", json_string(conf->mpi_params));
    json_object_set_new(obj, "msg_timeout", json_integer(conf->msg_timeout));
    json_object_set_new(obj, "next_job_id", json_integer(conf->next_job_id));
    json_object_set_new(obj, "node_prefix", json_string(conf->node_prefix));
    json_object_set_new(obj, "over_time_limit", json_integer(conf->over_time_limit));
    json_object_set_new(obj, "plugindir", json_string(conf->plugindir));
    json_object_set_new(obj, "plugstack", json_string(conf->plugstack));
    json_object_set_new(obj, "preempt_mode", json_integer(conf->preempt_mode));
    json_object_set_new(obj, "preempt_type", json_string(conf->preempt_type));
    json_object_set_new(obj, "priority_decay_hl", json_integer(conf->priority_decay_hl));
    json_object_set_new(obj, "priority_calc_period", json_integer(conf->priority_calc_period));
    json_object_set_new(obj, "priority_favor_small", json_integer(conf->priority_favor_small));
    json_object_set_new(obj, "priority_max_age", json_integer(conf->priority_max_age));
    json_object_set_new(obj, "priority_reset_period", json_integer(conf->priority_reset_period));
    json_object_set_new(obj, "priority_type", json_string(conf->priority_type));
    json_object_set_new(obj, "priority_weight_age", json_integer(conf->priority_weight_age));
    json_object_set_new(obj, "priority_weight_fs", json_integer(conf->priority_weight_fs));
    json_object_set_new(obj, "priority_weight_js", json_integer(conf->priority_weight_js));
    json_object_set_new(obj, "priority_weight_part", json_integer(conf->priority_weight_part));
    json_object_set_new(obj, "priority_weight_qos", json_integer(conf->priority_weight_qos));
    json_object_set_new(obj, "private_data", json_integer(conf->private_data));
    json_object_set_new(obj, "proctrack_type", json_string(conf->proctrack_type));
    json_object_set_new(obj, "prolog", json_string(conf->prolog));
    json_object_set_new(obj, "prolog_slurmctld", json_string(conf->prolog_slurmctld));
    json_object_set_new(obj, "propagate_prio_process", json_integer(conf->propagate_prio_process));
    json_object_set_new(obj, "propagate_rlimits", json_string(conf->propagate_rlimits));
    json_object_set_new(obj, "propagate_rlimits_except", json_string(conf->propagate_rlimits_except));
    json_object_set_new(obj, "resume_program", json_string(conf->resume_program));
    json_object_set_new(obj, "resume_rate", json_integer(conf->resume_rate));
    json_object_set_new(obj, "resume_timeout", json_integer(conf->resume_timeout));
    json_object_set_new(obj, "resv_over_run", json_integer(conf->resv_over_run));
    json_object_set_new(obj, "ret2service", json_integer(conf->ret2service));
    json_object_set_new(obj, "salloc_default_command", json_string(conf->salloc_default_command));
    json_object_set_new(obj, "sched_logfile", json_string(conf->sched_logfile));
    json_object_set_new(obj, "sched_log_level", json_integer(conf->sched_log_level));
    json_object_set_new(obj, "sched_params", json_string(conf->sched_params));
    json_object_set_new(obj, "sched_time_slice", json_integer(conf->sched_time_slice));
    json_object_set_new(obj, "schedtype", json_string(conf->schedtype));
    json_object_set_new(obj, "schedport", json_integer(conf->schedport));
    json_object_set_new(obj, "schedrootfltr", json_integer(conf->schedrootfltr));
    json_object_set_new(obj, "select_type", json_string(conf->select_type));
    json_object_set_new(obj, "select_type_param", json_integer(conf->select_type_param));
    json_object_set_new(obj, "slurm_conf", json_string(conf->slurm_conf));
    json_object_set_new(obj, "slurm_user_id", json_integer(conf->slurm_user_id));
    json_object_set_new(obj, "slurm_user_name", json_string(conf->slurm_user_name));
    json_object_set_new(obj, "slurmd_user_id", json_integer(conf->slurmd_user_id));
    json_object_set_new(obj, "slurmd_user_name", json_string(conf->slurmd_user_name));
    json_object_set_new(obj, "slurmctld_debug", json_integer(conf->slurmctld_debug));
    json_object_set_new(obj, "slurmctld_logfile", json_string(conf->slurmctld_logfile));
    json_object_set_new(obj, "slurmctld_pidfile", json_string(conf->slurmctld_pidfile));
    json_object_set_new(obj, "slurmctld_port", json_integer(conf->slurmctld_port));
    json_object_set_new(obj, "slurmctld_port_count", json_integer(conf->slurmctld_port_count));
    json_object_set_new(obj, "slurmctld_timeout", json_integer(conf->slurmctld_timeout));
    json_object_set_new(obj, "slurmd_debug", json_integer(conf->slurmd_debug));
    json_object_set_new(obj, "slurmd_logfile", json_string(conf->slurmd_logfile));
    json_object_set_new(obj, "slurmd_pidfile", json_string(conf->slurmd_pidfile));
    json_object_set_new(obj, "slurmd_port", json_integer(conf->slurmd_port));
    json_object_set_new(obj, "slurmd_spooldir", json_string(conf->slurmd_spooldir));
    json_object_set_new(obj, "slurmd_timeout", json_integer(conf->slurmd_timeout));
    json_object_set_new(obj, "srun_epilog", json_string(conf->srun_epilog));
    json_object_set_new(obj, "srun_prolog", json_string(conf->srun_prolog));
    json_object_set_new(obj, "state_save_location", json_string(conf->state_save_location));
    json_object_set_new(obj, "suspend_exc_nodes", json_string(conf->suspend_exc_nodes));
    json_object_set_new(obj, "suspend_exc_parts", json_string(conf->suspend_exc_parts));
    json_object_set_new(obj, "suspend_program", json_string(conf->suspend_program));
    json_object_set_new(obj, "suspend_rate", json_integer(conf->suspend_rate));
    json_object_set_new(obj, "suspend_time", json_integer(conf->suspend_time));
    json_object_set_new(obj, "suspend_timeout", json_integer(conf->suspend_timeout));
    json_object_set_new(obj, "switch_type", json_string(conf->switch_type));
    json_object_set_new(obj, "task_epilog", json_string(conf->task_epilog));
    json_object_set_new(obj, "task_plugin", json_string(conf->task_plugin));
    json_object_set_new(obj, "task_plugin_param", json_integer(conf->task_plugin_param));
    json_object_set_new(obj, "task_prolog", json_string(conf->task_prolog));
    json_object_set_new(obj, "tmp_fs", json_string(conf->tmp_fs));
    json_object_set_new(obj, "topology_plugin", json_string(conf->topology_plugin));
    json_object_set_new(obj, "track_wckey", json_integer(conf->track_wckey));
    json_object_set_new(obj, "tree_width", json_integer(conf->tree_width));
    json_object_set_new(obj, "unkillable_program", json_string(conf->unkillable_program));
    json_object_set_new(obj, "unkillable_timeout", json_integer(conf->unkillable_timeout));
    json_object_set_new(obj, "use_pam", json_integer(conf->use_pam));
    json_object_set_new(obj, "version", json_string(conf->version));
    json_object_set_new(obj, "vsize_factor", json_integer(conf->vsize_factor));
    json_object_set_new(obj, "wait_time", json_integer(conf->wait_time));
    json_object_set_new(obj, "z_16", json_integer(conf->z_16));
    json_object_set_new(obj, "z_32", json_integer(conf->z_32));
    json_object_set_new(obj, "z_char", json_string(conf->z_char));

    return obj;
}

json_t *slurm_partitions_to_json(const partition_info_msg_t *partitions)
{
    json_t *obj = json_object();
    json_t *partition;
    int i;
    json_t *partitions_array = json_array();
    json_object_set_new(obj, "last_update", json_integer(partitions->last_update));
    json_object_set_new(obj, "record_count", json_integer(partitions->record_count));
    for (i = 0; i < partitions->record_count; i++)
    {
        partition = slurm_partition_to_json(&partitions->partition_array[i]);
        json_array_append(partitions_array, partition);

    }
    json_object_set_new(obj, "partitions", partitions_array);
    return obj;
}

json_t *slurm_partition_to_json(const partition_info_t *partition)
{
    json_t *obj = json_object();
//    if (_slurm_api_major == 26)
//    {
//        json_object_set_new(obj, "cr_type", json_integer(partition->cr_type));
//        json_object_set_new(obj, "max_cpus_per_node", json_integer(partition->max_cpus_per_node));
//    }
    json_object_set_new(obj, "allow_alloc_nodes", json_string(partition->allow_alloc_nodes));
    json_object_set_new(obj, "allow_groups", json_string(partition->allow_groups));
    json_object_set_new(obj, "alternate", json_string(partition->alternate));
    json_object_set_new(obj, "def_mem_per_cpu", json_integer(partition->def_mem_per_cpu));
    json_object_set_new(obj, "default_time", json_integer(partition->default_time));
    json_object_set_new(obj, "flags", json_integer(partition->flags));
    json_object_set_new(obj, "grace_time", json_integer(partition->grace_time));
    json_object_set_new(obj, "max_mem_per_cpu", json_integer(partition->max_mem_per_cpu));
    json_object_set_new(obj, "max_nodes", json_integer(partition->max_nodes));
    json_object_set_new(obj, "max_share", json_integer(partition->max_share));
    json_object_set_new(obj, "max_time", json_integer(partition->max_time));
    json_object_set_new(obj, "min_nodes", json_integer(partition->min_nodes));
    json_object_set_new(obj, "name", json_string(partition->name));

    int node_inx_length = sizeof(partition->node_inx) / sizeof(int);
    int i;

    json_t *node_inx_array = json_array();
    for (i = 0; i < node_inx_length; i++)
    {
        json_array_append(node_inx_array, json_integer(partition->node_inx[i]));

    }
    json_object_set_new(obj, "node_inx", node_inx_array);
    json_object_set_new(obj, "nodes", json_string(partition->nodes));
    json_object_set_new(obj, "preempt_mode", json_integer(partition->preempt_mode));
    json_object_set_new(obj, "priority", json_integer(partition->priority));
    json_object_set_new(obj, "state_up", json_integer(partition->state_up));
    json_object_set_new(obj, "total_cpus", json_integer(partition->total_cpus));
    json_object_set_new(obj, "total_nodes", json_integer(partition->total_nodes));
    return obj;
}

json_t *slurm_jobid_to_json(const job_info_t *job_ptr)
{
    json_t *obj = json_object();
    json_object_set_new(obj, "user", json_integer(job_ptr->user_id));
    json_object_set_new(obj, "group", json_string(job_ptr->account));
    json_object_set_new(obj, "job name", json_string(job_ptr->name));
    json_object_set_new(obj, "partition", json_string(job_ptr->partition));
    json_object_set_new(obj, "allow_nodes", json_string(job_ptr->nodes));
    json_object_set_new(obj, "command", json_string(job_ptr->command));
    return obj;

}


