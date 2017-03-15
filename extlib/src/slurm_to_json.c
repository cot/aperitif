#include <slurm/slurm.h>
#include <stdlib.h>
#include "slurm_to_json.h"
#include "configuration.h"
#include <jansson.h>

char *slurm_get_configuration()
{
    slurm_ctl_conf_t *conf;

    if (slurm_load_ctl_conf((time_t) NULL, &conf))
    {
        slurm_perror("slurm_load_ctl_conf error");
        exit(1);
    }

    //Transforms the configuration to json and frees it afterwards
    json_t *json = slurm_configuration_to_json(conf);
    slurm_free_ctl_conf(conf);

    //Transforms the json to a string and frees it afterwards
    char *str = json_dumps(json, 0);
    json_decref(json);

    return str;
}

char *slurm_get_partitions()
{
    partition_info_msg_t *part_info_ptr;
    int i;

    slurm_load_partitions((time_t) NULL,
                          &part_info_ptr,
                          SHOW_ALL);

    json_t *json = slurm_partitions_to_json(part_info_ptr);
    slurm_free_partition_info_msg(part_info_ptr);

    //Transforms the json to a string and frees it afterwards
    char *str = json_dumps(json, 0);
    json_decref(json);

    return str;
}

char *slurm_get_job_info(int jobid)
{

    job_info_msg_t *resp;
    slurm_load_job(&resp, jobid, 0);
    job_info_t *job_ptr = &resp->job_array[0];

    json_t *json = slurm_jobid_to_json(job_ptr);
    char *str = json_dumps(json, 0);
    json_decref(json);

    return str;
}


long slurm_get_api_version()
{
    long api_version = slurm_api_version();
    return api_version;
}

int slurm_exec_submit_batch_job(char* batch_info_as_string)
{
//    json_error_t json_error;
//    json_t *root = json_loads(batch_info_as_string, 0, &json_error);
//    if (!root)
//    {
//        //TODO put an error in the root : {"error" : error.line...}
//        fprintf(stderr, "error: on line %d: %s\n", json_error.line, json_error.text);
//        return 1;
//    }
//    if (!json_is_object(root))
//    {
//        //TODO put an error in the root : {"error" : error: root is not an object...}
//        fprintf(stderr, "error: root is not an object\n");
//        json_decref(root);
//        return NULL;
//    }
//
//    json_t *script = json_object_get(root, "script");
//    if (!json_is_string(script))
//    {
//        //TODO see previous todos
//        fprintf(stderr, "error: script is not a string\n");
//        json_decref(root);
//        return NULL;
//    }
//
//    json_t *work_dir = json_object_get(root, "work_dir");
//
//    if (!json_is_string(work_dir))
//    {
//        //TODO see previous todos
//        fprintf(stderr, "error: work_dir is not a string\n");
//        json_decref(root);
//        return NULL;
//    }
//
//    job_desc_msg_t job_desc_msg;
//    submit_response_msg_t *slurm_submit_msg_pptr;
//
//    slurm_init_job_desc_msg(&job_desc_msg);
//    job_desc_msg.user_id = getuid();
//    job_desc_msg.group_id = getgid();
//    job_desc_msg.script = (char *) json_string_value(script);
//    job_desc_msg.work_dir = (char *) json_string_value(work_dir);
//
//    if (slurm_submit_batch_job(&job_desc_msg, &slurm_submit_msg_pptr))
//    {
//        slurm_perror("slurm_submit_batch_job error");
//        exit(1);
//    }
//    json_decref(root);
//    slurm_free_submit_response_response_msg(slurm_submit_msg_pptr);
//    return 1;
}
